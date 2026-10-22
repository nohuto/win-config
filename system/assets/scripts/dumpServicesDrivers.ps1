# (C) 2026 Noverse.
# This PS is a part of the WinConfig documentation
# https://github.com/nohuto
# https://discord.noverse.dev

param([string]$outputDir = $PSScriptRoot)

$ErrorActionPreference = 'SilentlyContinue'

$servicesKey = 'HKLM:\SYSTEM\CurrentControlSet\Services'
$servicesOut = Join-Path $outputDir 'services.txt'
$driversOut = Join-Path $outputDir 'drivers.txt'

if (-not ([Management.Automation.PSTypeName]'Win32.ShIndirectString').Type) {
    Add-Type @'
using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Win32 {
    public static class ShIndirectString {
        [DllImport("shlwapi.dll", CharSet = CharSet.Unicode)]
        public static extern int SHLoadIndirectString(string source, StringBuilder buffer, int bufferSize, IntPtr reserved);
    }
}
'@
}

function format-value($Value) {
    if ($null -eq $Value) { return '' }
    if ($Value -is [array]) { return ($Value -join ', ') }
    return [string]$Value
}

function resolve-text($Value, $Fallback) {
    if ($null -eq $Value -or [string]::IsNullOrWhiteSpace([string]$Value)) { return $Fallback }

    $text = [string]$Value
    if ($text.StartsWith('@')) {
        $buffer = [Text.StringBuilder]::new(4096)
        $status = [Win32.ShIndirectString]::SHLoadIndirectString($text, $buffer, $buffer.Capacity, [IntPtr]::Zero)
        if ($status -eq 0 -and $buffer.Length -gt 0) { return $buffer.ToString() }
        if ($Fallback) { return $Fallback }
    }

    return $text
}

function add-field($Builder, $Name, $Value) {
    [void]$Builder.AppendLine(('{0,-24}: {1}' -f $Name, (format-value $Value)))
}

function add-block($Builder, $Title, $Text) {
    [void]$Builder.AppendLine()
    [void]$Builder.AppendLine($Title)
    [void]$Builder.AppendLine(('-' * $Title.Length))
    [void]$Builder.AppendLine(($Text -join [Environment]::NewLine).Trim())
}

function get-startname($Start) {
    switch ([int]$Start) {
        0 { 'Boot' }
        1 { 'System' }
        2 { 'Automatic' }
        3 { 'Demand' }
        4 { 'Disabled' }
        default { "Unknown ($Start)" }
    }
}

function get-ecname($ErrorControl) {
    switch ([int]$ErrorControl) {
        0 { 'Ignore' }
        1 { 'Normal' }
        2 { 'Severe' }
        3 { 'Critical' }
        default { "Unknown ($ErrorControl)" }
    }
}

function get-typename($Type) {
    $typeValue = [int]$Type
    $names = @()
    if ($typeValue -band 0x1) { $names += 'Kernel Driver' }
    if ($typeValue -band 0x2) { $names += 'File System Driver' }
    if ($typeValue -band 0x4) { $names += 'Adapter' }
    if ($typeValue -band 0x8) { $names += 'Recognizer Driver' }
    if ($typeValue -band 0x10) { $names += 'Win32 Own Process' }
    if ($typeValue -band 0x20) { $names += 'Win32 Share Process' }
    if ($typeValue -band 0x40) { $names += 'User Service' }
    if ($typeValue -band 0x80) { $names += 'User Service Instance' }
    if ($typeValue -band 0x100) { $names += 'Interactive' }
    if ($names.Count -eq 0) { return "Unknown ($typeValue)" }
    return ($names -join ', ')
}

function get-binarypath($ImagePath) {
    if (-not $ImagePath) { return $null }

    $path = [Environment]::ExpandEnvironmentVariables([string]$ImagePath)
    $path = $path -replace '^\\\?\?\\', ''
    $path = $path -replace '^\\SystemRoot\\', "$env:SystemRoot\"
    $path = $path -replace '^System32\\', "$env:SystemRoot\System32\"

    if ($path -match '^\s*"([^"]+)"') { return $matches[1] }
    if ($path -match '^\s*(.+?\.(exe|sys|dll))(\s|$)') { return $matches[1] }

    return $path
}

function add-fileinfo($Builder, $ImagePath) {
    $binaryPath = get-binarypath $ImagePath
    add-field $Builder 'Binary Path' $binaryPath

    if (-not $binaryPath -or -not (Test-Path -LiteralPath $binaryPath)) { return }

    $file = Get-Item -LiteralPath $binaryPath
    $version = $file.VersionInfo

    add-field $Builder 'File Description' $version.FileDescription
    add-field $Builder 'File Version' $version.FileVersion
    add-field $Builder 'Company' $version.CompanyName
    add-field $Builder 'Product Name' $version.ProductName
    add-field $Builder 'Last Write Time' $file.LastWriteTime
}

function invoke-sc($Arguments) {
    & sc.exe @Arguments 2>&1
}

$serviceInfo = @{}
Get-CimInstance Win32_Service | ForEach-Object { $serviceInfo[$_.Name] = $_ }

$driverInfo = @{}
Get-CimInstance Win32_SystemDriver | ForEach-Object { $driverInfo[$_.Name] = $_ }

$processInfo = @{}
Get-CimInstance Win32_Process | ForEach-Object { $processInfo[[uint32]$_.ProcessId] = $_ }

$serviceBuilder = [Text.StringBuilder]::new()
$driverBuilder = [Text.StringBuilder]::new()

Get-ChildItem $servicesKey | Sort-Object PSChildName | ForEach-Object {
    $key = $_
    $props = Get-ItemProperty -LiteralPath $key.PSPath
    if ($null -eq $props.Type) { return }

    $type = [int]$props.Type
    $isDriver = ($type -band 0xF) -ne 0
    $isService = ($type -band 0x30) -ne 0

    if (-not $isDriver -and -not $isService) { return }

    $builder = if ($isDriver) { $driverBuilder } else { $serviceBuilder }
    $name = $key.PSChildName
    $cim = if ($isDriver) { $driverInfo[$name] } else { $serviceInfo[$name] }
    $process = if ($cim -and $cim.ProcessId) { $processInfo[[uint32]$cim.ProcessId] } else { $null }

    [void]$builder.AppendLine(('=' * 70))
    add-field $builder 'Name' $name
    add-field $builder 'Display Name' (resolve-text $props.DisplayName $cim.DisplayName)
    add-field $builder 'Description' (resolve-text $props.Description $cim.Description)
    add-field $builder 'Type' "$(get-typename $props.Type) ($($props.Type))"
    #add-field $builder 'Start' "$(get-startname $props.Start) ($($props.Start))"
    #add-field $builder 'Error Control' "$(get-ecname $props.ErrorControl) ($($props.ErrorControl))"
    add-field $builder 'Group' $props.Group
    add-field $builder 'Tag' $props.Tag
    add-field $builder 'Object Name' $props.ObjectName
    add-field $builder 'Image Path' $props.ImagePath
    add-fileinfo $builder $props.ImagePath
    add-field $builder 'Depend On Service' $props.DependOnService
    add-field $builder 'Depend On Group' $props.DependOnGroup
    add-field $builder 'Required Privileges' $props.RequiredPrivileges
    add-field $builder 'Service SID Type' $props.ServiceSidType
    #add-field $builder 'Delayed Auto Start' $props.DelayedAutoStart
    add-field $builder 'Failure Actions' $(if ($props.FailureActions) { 'Present' } else { 'None' })

    if ($cim) {
        #add-field $builder 'State' $cim.State
        #add-field $builder 'Status' $cim.Status
        #add-field $builder 'Started' $cim.Started
        #add-field $builder 'Start Mode' $cim.StartMode
        #add-field $builder 'Process ID' $cim.ProcessId
        #add-field $builder 'Accept Stop' $cim.AcceptStop
        #add-field $builder 'Accept Pause' $cim.AcceptPause
        #add-field $builder 'Exit Code' $cim.ExitCode
        #add-field $builder 'Service Exit Code' $cim.ServiceSpecificExitCode
        #add-field $builder 'Checkpoint' $cim.CheckPoint
        #add-field $builder 'Wait Hint' $cim.WaitHint
    }

    if ($process) {
        add-field $builder 'Command Line' $process.CommandLine
        #add-field $builder 'Parent PID' $process.ParentProcessId
        add-field $builder 'Thread Count' $process.ThreadCount
        add-field $builder 'Handle Count' $process.HandleCount
        add-field $builder 'Working Set' $process.WorkingSetSize
        add-field $builder 'Kernel Mode Time' $process.KernelModeTime
        add-field $builder 'User Mode Time' $process.UserModeTime
    }

    if (Test-Path -LiteralPath "$($key.PSPath)\TriggerInfo") {
        add-block $builder 'Triggers' (invoke-sc -Arguments @('qtriggerinfo', $name))
    } else {
        add-field $builder 'Triggers' 'None registered'
    }

    if ($props.FailureActions) {
        add-block $builder 'Failure Action Details' (invoke-sc -Arguments @('qfailure', $name))
    }

    #add-block $builder 'Security Descriptor' (invoke-sc -Arguments @('sdshow', $name))

    [void]$builder.AppendLine()
}

[IO.File]::WriteAllText($servicesOut, $serviceBuilder.ToString(), [Text.UTF8Encoding]::new($false))
[IO.File]::WriteAllText($driversOut, $driverBuilder.ToString(), [Text.UTF8Encoding]::new($false))
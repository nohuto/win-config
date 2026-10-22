# (C) 2026 Noverse.
# https://github.com/nohuto
# https://discord.noverse.dev

param([switch]$nohideconsole)

$nv = "Authored by Nohuto - (C) 2026 Noverse"
$ErrorActionPreference = 'SilentlyContinue'
$ProgressPreference = 'SilentlyContinue'

Add-Type -AssemblyName System.Windows.Forms, System.Drawing
Add-Type -TypeDefinition 'using System;using System.Runtime.InteropServices;public class WinAPI{[DllImport("user32.dll")]public static extern bool ShowWindow(IntPtr hWnd,int nCmdShow);}'
if (!(Test-Path "$env:temp\Noverse.ico")) {iwr -uri "https://github.com/nohuto/nohuto/releases/download/Logo/Noverse.ico" -out "$env:temp\Noverse.ico"}

$sessionmanager = 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager'
$segmentheapkey = 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Segment Heap'
$ifeoroot = 'HKLM:\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options'

$inputf = [Drawing.Font]::new('Segoe UI', 10, [Drawing.FontStyle]::Regular)
$smallf = [Drawing.Font]::new('Segoe UI', 9, [Drawing.FontStyle]::Regular)
$blue = [Drawing.Color]::CornflowerBlue
$gray = [Drawing.Color]::FromArgb(40,40,40)
$dark = [Drawing.Color]::FromArgb(28,28,28)
$white = [Drawing.Color]::White
$boxempty = [Drawing.Color]::Transparent

function test-admin {
    $id = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = [Security.Principal.WindowsPrincipal]::new($id)
    return $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (!(test-admin)) {
    $scriptpath = if ($PSCommandPath) { $PSCommandPath } else { $MyInvocation.MyCommand.Path }
    $args = @('-NoProfile', '-ExecutionPolicy', 'Unrestricted', '-File', "`"$scriptpath`"")
    if ($nohideconsole) { $args += '-nohideconsole' }
    Start-Process -FilePath 'powershell.exe' -Verb RunAs -ArgumentList $args
    exit
}

function set-dword {
    param([string]$path, [string]$name, [uint32]$value)
    try {
        if (!(Test-Path -LiteralPath $path)) { New-Item -Path $path -Force -ErrorAction Stop | Out-Null }
        $signed = [BitConverter]::ToInt32([BitConverter]::GetBytes($value), 0)
        New-ItemProperty -LiteralPath $path -Name $name -Value $signed -PropertyType DWord -Force -ErrorAction Stop | Out-Null
        $readback = get-value $path $name
        if ($readback -ne $value) { throw "readback $readback does not match $value" }
        return $true
    } catch {
        $script:lastregistryerror = $_.Exception.Message
        return $false
    }
}

function get-value {
    param([string]$path, [string]$name)
    if (!(Test-Path -LiteralPath $path)) { return $null }
    try {
        $item = Get-ItemProperty -LiteralPath $path -Name $name -ErrorAction Stop
        if ($null -eq $item.$name) { return $null }
        return [BitConverter]::ToUInt32([BitConverter]::GetBytes([int32]$item.$name), 0)
    } catch {
        return $null
    }
}

function remove-value {
    param([string]$path, [string]$name)
    if (Test-Path $path) { Remove-ItemProperty -Path $path -Name $name -Force }
}

function log {
    param(
        [string]$highlightmessage,
        [string]$message,
        [ConsoleColor]$timecolor = 'DarkGray',
        [ConsoleColor]$highlightcolor = 'White',
        [ConsoleColor]$messagecolor = 'White'
    )

    $timestamp = "[{0:HH:mm:ss}]" -f (Get-Date)

    function textcolor($text, $color) {
        $logs.SelectionStart = $logs.Text.Length
        $logs.SelectionColor = [Drawing.Color]::$color
        $logs.AppendText($text)
    }

    textcolor "$timestamp " $timecolor
    textcolor "$highlightmessage " $highlightcolor
    textcolor "$message`r`n" $messagecolor
    $logs.SelectionStart = $logs.Text.Length
    $logs.ScrollToCaret()
}

function new-panel {
    param([int]$x, [int]$y, [int]$w, [int]$h, [string]$title)

    $panel = [Windows.Forms.Panel]@{
        Location = [Drawing.Point]::new($x, $y)
        Size = [Drawing.Size]::new($w, $h)
        BackColor = $gray
        BorderStyle = 'FixedSingle'
    }

    $label = [Windows.Forms.Label]@{
        Text = $title
        ForeColor = $blue
        BackColor = $gray
        Location = [Drawing.Point]::new(9, 7)
        AutoSize = $true
        Font = [Drawing.Font]::new('Segoe UI', 10, [Drawing.FontStyle]::Regular)
    }
    $panel.Controls.Add($label)
    return $panel
}

function new-label {
    param($parent, [string]$text, [int]$x, [int]$y, [int]$w = 160)

    $label = [Windows.Forms.Label]@{
        Text = $text
        ForeColor = $white
        BackColor = $gray
        Location = [Drawing.Point]::new($x, $y)
        Size = [Drawing.Size]::new($w, 20)
        Font = $smallf
    }
    $parent.Controls.Add($label)
    return $label
}

function new-button {
    param($parent, [string]$text, [int]$x, [int]$y, [scriptblock]$action, [int]$w = 95)

    $btn = [Windows.Forms.Button]@{
        Text = $text
        Location = [Drawing.Point]::new($x, $y)
        BackColor = [Drawing.Color]::FromArgb(50,50,50)
        ForeColor = $white
        FlatStyle = 'Flat'
        Size = [Drawing.Size]::new($w, 25)
        Font = $smallf
    }
    $btn.FlatAppearance.BorderColor = [Drawing.Color]::Gray
    $btn.FlatAppearance.BorderSize = 1
    $btn.Add_Click($action)
    $parent.Controls.Add($btn)
    return $btn
}

function new-number {
    param($parent, [int]$x, [int]$y, [uint32]$min, [uint32]$max, [uint32]$increment, [uint32]$value)

    $num = [Windows.Forms.NumericUpDown]@{
        Location = [Drawing.Point]::new($x, $y)
        Size = [Drawing.Size]::new(132, 24)
        BackColor = [Drawing.Color]::FromArgb(30,30,30)
        ForeColor = $white
        Font = $smallf
        Minimum = [decimal]$min
        Maximum = [decimal]$max
        Increment = [decimal]$increment
        Value = [decimal]$value
    }
    $parent.Controls.Add($num)
    return $num
}

function new-nvcheck {
    param($parent, [string]$text, [int]$x, [int]$y, [bool]$checked = $false, [scriptblock]$action = $null)

    $box = [Windows.Forms.Panel]@{
        Size = [Drawing.Size]::new(13, 13)
        Location = [Drawing.Point]::new($x, $y + 2)
        BackColor = $(if ($checked) { [Drawing.Color]::CornflowerBlue } else { [Drawing.Color]::Transparent })
        BorderStyle = 'FixedSingle'
        Tag = @{ Checked = $checked }
    }
    $label = [Windows.Forms.Label]@{
        Text = $text
        ForeColor = $white
        BackColor = $gray
        Location = [Drawing.Point]::new($x + 18, $y)
        AutoSize = $true
        Font = $smallf
    }

    $click = {
        $box.Tag.Checked = -not $box.Tag.Checked
        $box.BackColor = if ($box.Tag.Checked) { [Drawing.Color]::CornflowerBlue } else { [Drawing.Color]::Transparent }
        if ($action) { & $action }
    }.GetNewClosure()

    $box.Add_Click($click)
    $label.Add_Click($click)
    $parent.Controls.AddRange(@($box, $label))
    return $box
}

function set-nvcheck {
    param($box, [bool]$checked)
    if ($box -is [Windows.Forms.CheckBox]) {
        $box.Checked = $checked
        return
    }
    $box.Tag.Checked = $checked
    $box.BackColor = if ($checked) { [Drawing.Color]::CornflowerBlue } else { [Drawing.Color]::Transparent }
}

function get-nvcheck {
    param($box)
    if ($box -is [Windows.Forms.CheckBox]) { return [bool]$box.Checked }
    return [bool]$box.Tag.Checked
}

function get-exefromicon {
    param([string]$value)
    if ([string]::IsNullOrWhiteSpace($value)) { return $null }
    $v = $value.Trim()
    if ($v.StartsWith('"')) {
        $m = [regex]::Match($v, '^"([^"]+)"')
        if ($m.Success) { $v = $m.Groups[1].Value }
    } else {
        $v = ($v -split ',')[0].Trim()
    }
    if ($v -match '\.exe$' -and (Test-Path $v)) { return (Resolve-Path $v).Path }
    return $null
}

function add-programrow {
    param($rows, [string]$name, [string]$exe, [string]$path, [string]$source)

    if ([string]::IsNullOrWhiteSpace($exe)) { return }
    if ($exe -notmatch '\.exe$') { return }
    if ($path -and !(Test-Path $path)) { return }
    $key = "$($exe.ToLowerInvariant())|$($path.ToLowerInvariant())"
    if ($rows.ContainsKey($key)) { return }
    $rows[$key] = [pscustomobject]@{
        Name = if ($name) { $name } else { $exe }
        Exe = $exe
        Path = $path
        Source = $source
    }
}

function resolve-shortcut {
    param([string]$path)
    try {
        $shell = New-Object -ComObject WScript.Shell
        $shortcut = $shell.CreateShortcut($path)
        if ($shortcut.TargetPath -match '\.exe$' -and (Test-Path $shortcut.TargetPath)) { return (Resolve-Path $shortcut.TargetPath).Path }
    } catch {}
    return $null
}

function get-installedexecutables {
    $rows = @{}

    $uninstallroots = @(
        'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall',
        'HKLM:\SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall',
        'HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall'
    )
    foreach ($root in $uninstallroots) {
        if (!(Test-Path $root)) { continue }
        Get-ChildItem $root | ForEach-Object {
            $p = Get-ItemProperty $_.PSPath
            if (!$p.DisplayName) { return }
            $iconexe = get-exefromicon $p.DisplayIcon
            if ($iconexe) {
                add-programrow $rows $p.DisplayName (Split-Path $iconexe -Leaf) $iconexe 'Uninstall'
                return
            }
            if ($p.InstallLocation -and (Test-Path $p.InstallLocation)) {
                Get-ChildItem $p.InstallLocation -File -Filter *.exe | Select-Object -First 8 | ForEach-Object {
                    add-programrow $rows $p.DisplayName $_.Name $_.FullName 'InstallLocation'
                }
            }
        }
    }

    $apppathroots = @(
        'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths',
        'HKLM:\SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\App Paths',
        'HKCU:\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths'
    )
    foreach ($root in $apppathroots) {
        if (!(Test-Path $root)) { continue }
        Get-ChildItem $root | ForEach-Object {
            $p = Get-ItemProperty $_.PSPath
            $default = $_.GetValue('')
            if ($default -and (Test-Path $default)) {
                add-programrow $rows $_.PSChildName $_.PSChildName (Resolve-Path $default).Path 'App Paths'
            }
        }
    }

    $shortcutroots = @(
        "$env:ProgramData\Microsoft\Windows\Start Menu\Programs",
        "$env:AppData\Microsoft\Windows\Start Menu\Programs"
    )
    foreach ($root in $shortcutroots) {
        if (!(Test-Path $root)) { continue }
        Get-ChildItem $root -Recurse -File -Filter *.lnk | ForEach-Object {
            $target = resolve-shortcut $_.FullName
            if ($target) { add-programrow $rows $_.BaseName (Split-Path $target -Leaf) $target 'Start Menu' }
        }
    }
    Get-Process | Where-Object { $_.Path -and ($_.Path -match '\.exe$') } | ForEach-Object { add-programrow $rows $_.ProcessName (Split-Path $_.Path -Leaf) $_.Path 'Running' }
    return $rows.Values | Sort-Object Name, Exe
}

function get-ifeopath {
    $exe = $exeinput.Text.Trim()
    if ($exe -match '[\\/]') { $exe = Split-Path $exe -Leaf }
    if ($exe -and $exe -notmatch '\.exe$') { $exe = "$exe.exe" }
    if (!$exe) { return $null }
    return Join-Path $ifeoroot $exe
}

function set-exeinput {
    param([string]$pathorexe)
    if (!$pathorexe) { return }
    $exeinput.Text = if ($pathorexe -match '[\\/]') { Split-Path $pathorexe -Leaf } else { $pathorexe }
}

function get-frontendvalue {
    $value = 0
    foreach ($bit in $bitchecks.Keys) { if (get-nvcheck $bitchecks[$bit]) { $value = $value -bor (1 -shl [int]$bit) } }
    if (get-nvcheck $lfhcontention) { $value = $value -bor (255 -shl 8) }
    if (get-nvcheck $lfhperf) { $value = $value -bor (4095 -shl 16) }
    return [uint32]$value
}

function set-frontendcontrols {
    param([uint32]$value)
    foreach ($bit in $bitchecks.Keys) { set-nvcheck $bitchecks[$bit] (($value -band (1 -shl [int]$bit)) -ne 0) }
    set-nvcheck $lfhcontention (((($value -shr 8) -band 255) -ne 0))
    set-nvcheck $lfhperf (((($value -shr 16) -band 4095) -ne 0))
}

function set-globalmode {
    param([string]$mode)

    $script:loadingglobal = $true
    set-nvcheck $globalforceenable ($mode -eq 'enable')
    set-nvcheck $globalforcedisable ($mode -eq 'disable')
    set-nvcheck $globaldefault ($mode -eq 'default')
    $script:loadingglobal = $false

    if ($mode -eq 'enable') {
        if (set-dword $segmentheapkey 'Enabled' 1) {
            log '[+]' 'Global Segment Heap force enabled' -HighlightColor Green
        } else {
            log '[-]' "Global write failed: $script:lastregistryerror" -HighlightColor Red
        }
        return
    }

    if ($mode -eq 'disable') {
        if (set-dword $segmentheapkey 'Enabled' 0) {
            log '[+]' 'Global Segment Heap force disabled' -HighlightColor Green
        } else {
            log '[-]' "Global write failed: $script:lastregistryerror" -HighlightColor Red
        }
        return
    }

    remove-value $segmentheapkey 'Enabled'
    log '[+]' 'Global Segment Heap value removed' -HighlightColor Green
}

function refresh-global {
    $script:loadingglobal = $true
    $enabled = get-value $segmentheapkey 'Enabled'
    if ($null -eq $enabled) {
        set-nvcheck $globalforceenable $false
        set-nvcheck $globalforcedisable $false
        set-nvcheck $globaldefault $true
    } elseif ($enabled -eq 0) {
        set-nvcheck $globalforceenable $false
        set-nvcheck $globalforcedisable $true
        set-nvcheck $globaldefault $false
    } else {
        set-nvcheck $globalforceenable $true
        set-nvcheck $globalforcedisable $false
        set-nvcheck $globaldefault $false
    }
    $script:loadingglobal = $false
}

function refresh-ntdefaults {
    $values = @{
        HeapSegmentReserve = 1048576
        HeapSegmentCommit = 8192
        HeapDeCommitFreeBlockThreshold = 4096
        HeapDeCommitTotalFreeThreshold = 65536
    }
    foreach ($name in $values.Keys) {
        $current = get-value $sessionmanager $name
        $num = $ntnumbers[$name]
        if ($null -eq $current) {
            $num.Value = [decimal]$values[$name]
        } else {
            if ($current -gt [uint32]$num.Maximum) { $current = [uint32]$num.Maximum }
            $num.Value = [decimal]$current
        }
    }
}

function refresh-ifeo {
    $path = get-ifeopath
    if (!$path) { log '[-]' 'Enter/select an exe first' -HighlightColor Red; return }
    $v = get-value $path 'FrontEndHeapDebugOptions'
    if ($null -eq $v) { $v = 0 }
    set-frontendcontrols $v
    $lookaside = get-value $path 'DisableHeapLookaside'
    set-nvcheck $disablelookaside ($lookaside -ne $null -and $lookaside -ne 0)
    $gc = get-value $path 'GCInterval'
    if ($null -eq $gc) { $gc = 0 }
    if ($gc -gt [uint32]$gcnum.Maximum) { $gc = [uint32]$gcnum.Maximum }
    $script:loadinggc = $true
    try {
        $gcnum.Value = [decimal]$gc
    } finally {
        $script:loadinggc = $false
    }
    log '[+]' "Loaded IFEO for $($exeinput.Text)" -HighlightColor Green
}

$nvmain = [Windows.Forms.Form]@{
    Text = 'Noverse Heap Type'
    Size = [Drawing.Size]::new(1130, 650)
    StartPosition = 'CenterScreen'
    BackColor = $dark
    FormBorderStyle = 'Sizable'
    Font = [Drawing.Font]::new('Segoe UI', 9, [Drawing.FontStyle]::Regular)
    MinimumSize = [Drawing.Size]::new(1080, 650)
    Icon = [System.Drawing.Icon]::ExtractAssociatedIcon("$env:temp\Noverse.ico")
}

$globalpanel = new-panel 5 5 360 60 'Global Segment Heap'
$nvmain.Controls.Add($globalpanel)
$globalforceenable = new-nvcheck $globalpanel 'Force Enable' 15 30 $false {
    if ($script:loadingglobal) { return }
    set-globalmode 'enable'
}
$globalforcedisable = new-nvcheck $globalpanel 'Force Disable' 120 30 $false {
    if ($script:loadingglobal) { return }
    set-globalmode 'disable'
}
$globaldefault = new-nvcheck $globalpanel 'Default' 225 30 $false {
    if ($script:loadingglobal) { return }
    set-globalmode 'default'
}

$ntpanel = new-panel 5 70 360 195 'NT Heap Defaults'
$nvmain.Controls.Add($ntpanel)
$ntnumbers = @{}
new-label $ntpanel 'HeapSegmentReserve' 15 38 178 | Out-Null
$ntnumbers.HeapSegmentReserve = new-number $ntpanel 195 35 65536 16580608 65536 1048576
new-label $ntpanel 'HeapSegmentCommit' 15 68 178 | Out-Null
$ntnumbers.HeapSegmentCommit = new-number $ntpanel 195 65 4096 16580608 4096 8192
new-label $ntpanel 'DeCommitFreeBlockThreshold' 15 98 178 | Out-Null
$ntnumbers.HeapDeCommitFreeBlockThreshold = new-number $ntpanel 195 95 0 4294967280 16 4096
new-label $ntpanel 'DeCommitTotalFreeThreshold' 15 128 178 | Out-Null
$ntnumbers.HeapDeCommitTotalFreeThreshold = new-number $ntpanel 195 125 0 4294967280 16 65536
new-button $ntpanel 'Apply' 5 164 {
    $failed = $false
    foreach ($name in $ntnumbers.Keys) {
        if (!(set-dword $sessionmanager $name ([uint32]$ntnumbers[$name].Value))) { $failed = $true }
    }
    if ($failed) {
        log '[-]' "NT heap defaults write failed: $script:lastregistryerror" -HighlightColor Red
    } else {
        log '[+]' 'NT heap defaults written' -HighlightColor Green
    }
} 80 | Out-Null
new-button $ntpanel 'Reload' 90 164 { refresh-ntdefaults; log '[+]' 'NT defaults reloaded' -HighlightColor Green } 80 | Out-Null
new-button $ntpanel 'Remove' 175 164 {
    foreach ($name in $ntnumbers.Keys) { remove-value $sessionmanager $name }
    refresh-ntdefaults
    log '[+]' 'NT heap default values removed' -HighlightColor Green
} 80 | Out-Null

$programpanel = new-panel 370 5 740 385 'Per Executable'
$nvmain.Controls.Add($programpanel)
$exeinput = [Windows.Forms.TextBox]@{
    Location = [Drawing.Point]::new(15, 33)
    Size = [Drawing.Size]::new(370, 24)
    BackColor = [Drawing.Color]::FromArgb(30,30,30)
    ForeColor = $white
    Font = $smallf
}
$programpanel.Controls.Add($exeinput)
new-button $programpanel 'Search' 395 32 {
    $dialog = [Windows.Forms.OpenFileDialog]@{
        Filter = 'Executable (*.exe)|*.exe|All files (*.*)|*.*'
        Title = 'Select executable'
    }
    if ($dialog.ShowDialog() -eq [Windows.Forms.DialogResult]::OK) {
        set-exeinput $dialog.FileName
        refresh-ifeo
        log '[+]' "Selected $(Split-Path $dialog.FileName -Leaf)" -HighlightColor Green
    }
} 80 | Out-Null
new-button $programpanel 'Detect' 480 32 { start-programdetect } 80 | Out-Null
new-button $programpanel 'Load' 565 32 { refresh-ifeo } 70 | Out-Null
new-button $programpanel 'Remove' 640 32 {
    $path = get-ifeopath
    if (!$path) { log '[-]' 'Enter/select an exe first' -HighlightColor Red; return }
    remove-value $path 'FrontEndHeapDebugOptions'
    remove-value $path 'DisableHeapLookaside'
    remove-value $path 'GCInterval'
    set-frontendcontrols 0
    set-nvcheck $disablelookaside $false
    $script:loadinggc = $true
    try {
        $gcnum.Value = 0
    } finally {
        $script:loadinggc = $false
    }
    log '[+]' "IFEO values removed for $($exeinput.Text)" -HighlightColor Green
} 70 | Out-Null

$programlist = [Windows.Forms.ListView]@{
    Location = [Drawing.Point]::new(15, 68)
    Size = [Drawing.Size]::new(708, 300)
    View = 'Details'
    FullRowSelect = $true
    GridLines = $false
    BackColor = $gray
    ForeColor = $white
    Font = $smallf
}
[void]$programlist.Columns.Add('Name', 180)
[void]$programlist.Columns.Add('Exe', 135)
[void]$programlist.Columns.Add('Source', 85)
[void]$programlist.Columns.Add('Path', 250)
$programlist.Add_DoubleClick({
    if ($programlist.SelectedItems.Count -gt 0) {
        set-exeinput $programlist.SelectedItems[0].SubItems[1].Text
        refresh-ifeo
    }
})
$programlist.Add_SelectedIndexChanged({
    if ($programlist.SelectedItems.Count -gt 0) {
        set-exeinput $programlist.SelectedItems[0].SubItems[1].Text
        refresh-ifeo
    }
})
$programpanel.Controls.Add($programlist)

function set-programrows {
    param($items)

    $programlist.BeginUpdate()
    try {
        $programlist.Items.Clear()
        foreach ($item in $items) {
            $row = [Windows.Forms.ListViewItem]::new($item.Name)
            [void]$row.SubItems.Add($item.Exe)
            [void]$row.SubItems.Add($item.Source)
            [void]$row.SubItems.Add($item.Path)
            $row.Tag = $item
            [void]$programlist.Items.Add($row)
        }
    } finally { $programlist.EndUpdate() }
}

function start-programdetect {
    if ($script:detectjob -and $script:detectjob.State -eq 'Running') {
        log '[~]' 'Program detection already running' -HighlightColor Gray
        return
    }

    try {
        $init = [scriptblock]::Create(@"
function get-exefromicon { ${function:get-exefromicon} }
function add-programrow { ${function:add-programrow} }
function resolve-shortcut { ${function:resolve-shortcut} }
function get-installedexecutables { ${function:get-installedexecutables} }
"@)

        $script:detectjob = Start-Job -InitializationScript $init -ScriptBlock { get-installedexecutables } -ErrorAction Stop
        $script:detecttimer.Start()
    } catch { log '[-]' "Program detection failed: $($_.Exception.Message)" -HighlightColor Red }
}

$script:detecttimer = [Windows.Forms.Timer]::new()
$script:detecttimer.Interval = 500
$script:detecttimer.Add_Tick({
    if (!$script:detectjob) {
        $script:detecttimer.Stop()
        return
    }
    if ($script:detectjob.State -eq 'Running') { return }

    $job = $script:detectjob
    $script:detectjob = $null
    $script:detecttimer.Stop()

    if ($job.State -eq 'Completed') {
        $items = @(Receive-Job -Job $job)
        set-programrows $items
        log '[+]' "Found $($items.Count) executable entries" -HighlightColor Green
    } else {
        $reason = $job.ChildJobs[0].JobStateInfo.Reason.Message
        if (!$reason) { $reason = $job.State }
        log '[-]' "Program detection failed: $reason" -HighlightColor Red
    }
    Remove-Job -Job $job -Force
})

$bitpanel = new-panel 370 395 740 210 'FrontEndHeapDebugOptions'
$nvmain.Controls.Add($bitpanel)
$bitchecks = @{}
$bitnames = @{
    0 = 'LFH flag 4'
    1 = 'LFH flag 2'
    2 = 'disable Segment'
    3 = 'enable Segment'
    4 = 'heap stack trace'
    5 = 'heap feature 4'
    6 = 'app compat'
    7 = 'heap feature 8'
    22 = 'GCInterval'
}
foreach ($i in @(0,1,2,3,4,5,6,7)) {
    $index = $bitchecks.Count
    $col = [int][Math]::Floor($index / 4)
    $row = $index % 4
    $x = 15 + ($col * 185)
    $y = 32 + ($row * 22)
    $text = if ($bitnames.ContainsKey($i)) { "bit $i - $($bitnames[$i])" } else { "bit $i" }
    $bitchecks[$i] = new-nvcheck $bitpanel $text $x $y $false
}
$bitchecks[22] = new-nvcheck $bitpanel 'bit 22 - GCInterval' 385 32 $false
$lfhcontention = new-nvcheck $bitpanel 'bits 8-15 - LFH contention' 385 54 $false
$lfhperf = new-nvcheck $bitpanel 'bits 16-27 - LFH perf' 385 76 $false

$disablelookaside = new-nvcheck $bitpanel 'DisableHeapLookaside' 15 145 $false
new-label $bitpanel 'GCInterval seconds' 185 145 125 | Out-Null
$gcnum = new-number $bitpanel 310 142 0 4294967295 1 0
$gcnum.Add_ValueChanged({
    if (!$script:loadinggc) { set-nvcheck $bitchecks[22] $true }
})

new-button $bitpanel 'NT Heap' 5 179 { set-frontendcontrols 4 } 80 | Out-Null
new-button $bitpanel 'Segment' 90 179 { set-frontendcontrols 8 } 80 | Out-Null
new-button $bitpanel 'Clear' 175 179 {
    set-frontendcontrols 0
    set-nvcheck $disablelookaside $false
    $script:loadinggc = $true
    try {
        $gcnum.Value = 0
    } finally {
        $script:loadinggc = $false
    }
} 80 | Out-Null
new-button $bitpanel 'Apply' 260 179 {
    $path = get-ifeopath
    if (!$path) { log '[-]' 'Enter/select an exe first' -HighlightColor Red; return }
    $value = get-frontendvalue
    if (!(set-dword $path 'FrontEndHeapDebugOptions' $value)) {
        log '[-]' "IFEO write failed: $script:lastregistryerror" -HighlightColor Red
        return
    }
    if (get-nvcheck $disablelookaside) {
        if (!(set-dword $path 'DisableHeapLookaside' 1)) {
            log '[-]' "IFEO write failed: $script:lastregistryerror" -HighlightColor Red
            return
        }
    } else { remove-value $path 'DisableHeapLookaside' }
    if ((get-nvcheck $bitchecks[22]) -and [uint32]$gcnum.Value -gt 0) {
        if (!(set-dword $path 'GCInterval' ([uint32]$gcnum.Value))) {
            log '[-]' "IFEO write failed: $script:lastregistryerror" -HighlightColor Red
            return
        }
    } else { remove-value $path 'GCInterval' }
    log '[+]' "IFEO written for $($exeinput.Text)" -HighlightColor Green
} 80 | Out-Null

$logpanel = [Windows.Forms.Panel]@{
    Location = [Drawing.Point]::new(5, 270)
    Size = [Drawing.Size]::new(360, 335)
    BackColor = $gray
    BorderStyle = 'FixedSingle'
}
$nvmain.Controls.Add($logpanel)
$logs = [Windows.Forms.RichTextBox]@{
    Multiline = $true
    ReadOnly = $true
    ScrollBars = [Windows.Forms.RichTextBoxScrollBars]::Vertical
    BackColor = $gray
    ForeColor = $white
    Font = [Drawing.Font]::new('Consolas', 9)
    BorderStyle = 'None'
    Location = [Drawing.Point]::new(1, 1)
    Size = [Drawing.Size]::new(357, 207)
}
$logpanel.Controls.Add($logs)

function resize {
    $rightwidth = [Math]::Max(650, $nvmain.ClientSize.Width - 375)
    $programpanel.Width = $rightwidth
    $bitpanel.Width = $rightwidth

    $programpanel.Height = [Math]::Max(260, $nvmain.ClientSize.Height - $programpanel.Top - $bitpanel.Height - 10)
    $programlist.Height = [Math]::Max(70, $programpanel.ClientSize.Height - $programlist.Top - 15)
    $bitpanel.Top = $programpanel.Bottom + 5

    $logpanel.Height = [Math]::Max(70, $nvmain.ClientSize.Height - $logpanel.Top - 5)
    $logs.Width = $logpanel.ClientSize.Width - 2
    $programlist.Width = $programpanel.ClientSize.Width - 30
    $programlist.Columns[3].Width = [Math]::Max(180, $programlist.Width - 420)
    $logs.Height = $logpanel.ClientSize.Height - 2
}

$nvmain.Add_Resize({ resize })
resize

refresh-global
refresh-ntdefaults
set-frontendcontrols 0

$nvmain.Add_Shown({
    resize
    $nvmain.Refresh()
    start-programdetect
})

if (!$nohideconsole) { [WinAPI]::ShowWindow((Get-Process -Id $PID).MainWindowHandle, 0) | Out-Null }
#$nvmain.Add_FormClosed({ Stop-Process -Id $PID })
[Windows.Forms.Application]::Run($nvmain)

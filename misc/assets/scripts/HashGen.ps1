#    Hash Generator - https://github.com/nohuto/win-config/blob/main/misc/assets/scripts/HashGen.ps1
#    Copyright (C) 2026 Noverse, Nohuto
#
#    This program is proprietary software: you may not copy, redistribute, or modify
#    it in any way without prior written permission from Noverse.
#
#    Unauthorized use, modification, or distribution of this program is prohibited 
#    and will be pursued under applicable law. This software is provided "as is," 
#    without warranty of any kind, express or implied, including but not limited to 
#    the warranties of merchantability, fitness for a particular purpose, and 
#    non-infringement.
#
#    For permissions or inquiries, contact: https://discord.noverse.dev

param(
    [string]$nvstringin,
    [ValidateSet('All','MD5','SHA1','SHA256','SHA384','SHA512','MACTripleDES','RIPEMD160')]
    [string]$algorithm = 'All'
)

$ErrorActionPreference = "Stop"
$ProgressPreference = "SilentlyContinue"
[console]::Title = "Noverse Hash Generator"
[console]::BackgroundColor = "Black"
Clear-Host

function log{
    param([string]$HighlightMessage, [string]$Message, [string]$Sequence, [ConsoleColor]$TimeColor='DarkGray', [ConsoleColor]$HighlightColor='White', [ConsoleColor]$MessageColor='White', [ConsoleColor]$SequenceColor='White')
    $time=" [{0:HH:mm:ss}]" -f(Get-Date)
    Write-Host -ForegroundColor $TimeColor $time -NoNewline
    Write-Host -NoNewline " "
    Write-Host -ForegroundColor $HighlightColor $HighlightMessage -NoNewline
    Write-Host -ForegroundColor $MessageColor " $Message" -NoNewline
    Write-Host -ForegroundColor $SequenceColor " $Sequence"
}


if ([string]::IsNullOrWhiteSpace($nvstringin) -and $args.Count -gt 0) { $nvstringin = ($args -join ' ') }
if ([string]::IsNullOrWhiteSpace($nvstringin)) {
    log "[-]" "No input path was provided." "Use -nvstringin <path>" -HighlightColor Red -SequenceColor DarkGray
    return
}

$nvstringin = $nvstringin.Trim().Trim('"')
try { $nvstringin = (Resolve-Path -LiteralPath $nvstringin -ErrorAction Stop).ProviderPath } catch {
    log "[-]" "Input path does not exist:" "$nvstringin" -HighlightColor Red -SequenceColor DarkGray
    return
}

function createhash {
    param([string]$name)
    switch ($name.ToUpperInvariant()) {
        'MD5' { return [System.Security.Cryptography.MD5]::Create() }
        'SHA1' { return [System.Security.Cryptography.SHA1]::Create() }
        'SHA256' { return [System.Security.Cryptography.SHA256]::Create() }
        'SHA384' { return [System.Security.Cryptography.SHA384]::Create() }
        'SHA512' { return [System.Security.Cryptography.SHA512]::Create() }
        'MACTRIPLEDES' { return [System.Security.Cryptography.MACTripleDES]::Create() }
        'RIPEMD160' { return [System.Security.Cryptography.RIPEMD160]::Create() }
        default { throw "Unsupported algorithm $name" }
    }
}

function gethash {
    param([string]$Path,[string[]]$algorithms)
    $result = @{}
    $hashers = @()
    foreach ($algo in $algorithms) { $hashers += [pscustomobject]@{name=$algo; Hasher=(createhash $algo)} }
    $buffer = New-Object byte[] 65536
    $stream = [System.IO.File]::Open($Path,[System.IO.FileMode]::Open,[System.IO.FileAccess]::Read,[System.IO.FileShare]::Read)
    $empty = New-Object byte[] 0
    try {
        while(($read = $stream.Read($buffer,0,$buffer.Length)) -gt 0){
            foreach ($entry in $hashers) {
                $entry.Hasher.TransformBlock($buffer,0,$read,$null,0) | Out-Null
            }
        }
        foreach ($entry in $hashers) {
            $entry.Hasher.TransformFinalBlock($empty,0,0) | Out-Null
            $result[$entry.name] = [System.BitConverter]::ToString($entry.Hasher.Hash).Replace("-","")
        }
    } finally {
        foreach ($entry in $hashers) { $entry.Hasher.Dispose() }
        $stream.Dispose()
    }
    return $result
}

if (!(Test-Path -LiteralPath $nvstringin)) {
    log "[-]" "Input path does not exist:" "$nvstringin" -HighlightColor Red -SequenceColor DarkGray
    return
}

$type = Test-Path -LiteralPath $nvstringin -PathType Container
$nvoutdir = if ($type) { $nvstringin } else { Split-Path $nvstringin -Parent }
$nvout = Join-Path $nvoutdir "Hashes.txt"

$nvin = if ($type) { Get-ChildItem -LiteralPath $nvstringin -File -Recurse } else { Get-Item -LiteralPath $nvstringin }

if (!($nvin)) {
    log "[-]" "No file to hash in:" "$nvstringin" -HighlightColor Red -SequenceColor DarkGray
    return
}

$algorithms = @('MD5','SHA1','SHA256','SHA384','SHA512','MACTripleDES','RIPEMD160')
$algos = if ($algorithm -ieq 'All') { $algorithms } else { @($algorithm.ToUpperInvariant()) }
$lines = New-Object System.Collections.Generic.List[string]

foreach ($file in $nvin) {
    $lines.Add("[$($file.name)]")
    try {
        $hashes = gethash -Path $file.FullName -Algorithms $algos
        foreach ($algo in $algos) {
            $hash = $hashes[$algo]
            if ($hash) {
                log "[+]" "${algo}:" "$hash" -HighlightColor Green -SequenceColor Blue
                $lines.Add("${algo}: $hash")
            } else {
                log "[-]" "Error generating hash $algo" "($($file.name))" -HighlightColor Red -SequenceColor DarkGray
                $lines.Add("${algo}: Error")
            }
        }
    } catch {
        foreach ($algo in $algos) {
            log "[-]" "Error generating hash $algo" "($($file.name))" -HighlightColor Red -SequenceColor DarkGray
            $lines.Add("${algo}: Error")
        }
    }
    $lines.Add("")
}

$lines | Out-File -FilePath $nvout -Encoding UTF8 -Append
log "[+]" "Hashes saved to:" "$nvout" -HighlightColor Green -SequenceColor DarkGray
return
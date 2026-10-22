$ErrorActionPreference = "Stop"

$nvfolder = Join-Path $env:LOCALAPPDATA "Noverse"
$gen = Join-Path $nvfolder "hashGen.ps1"
$repoLocal = if ($PSScriptRoot) { Join-Path $PSScriptRoot "hashGen.ps1" } else { $null }
$local = Join-Path $home "Downloads\hashGen.ps1"
if (!(Test-Path -LiteralPath $nvfolder)) { New-Item -ItemType Directory -Path $nvfolder -Force | Out-Null }

if ($repoLocal -and (Test-Path -LiteralPath $repoLocal) -and ((Resolve-Path -LiteralPath $repoLocal).ProviderPath -ne $gen)) {
    Copy-Item -LiteralPath $repoLocal -Destination $gen -Force
} elseif (Test-Path -LiteralPath $local) {
    Copy-Item -LiteralPath $local -Destination $gen -Force
} else {
    try {
        Invoke-WebRequest -Uri "https://raw.githubusercontent.com/nohuto/win-config/refs/heads/main/misc/assets/scripts/HashGen.ps1" -OutFile $gen -UseBasicParsing
    } catch {
        throw "Failed to download hashGen.ps1: $($_.Exception.Message)"
    }
}

$extended = "hashGen.ContextMenu"
$shell = Join-Path "HKCU:\Software\Classes\$extended" "shell"

foreach ($old in @(
        "HKCU:\Software\Classes\*\shell\Hashes",
        "HKCU:\Software\Classes\Directory\shell\Hashes",
        "HKCU:\Software\Classes\$extended"
    )) {
    if (Test-Path -LiteralPath $old) {
        Remove-Item -LiteralPath $old -Recurse -Force
    }
}

New-Item -Path $shell -Force | Out-Null

foreach ($entry in @(
        @{Key='All'; Label='All Hashes'; Argument='All'},
        @{Key='MD5'; Label='MD5'; Argument='MD5'},
        @{Key='SHA1'; Label='SHA1'; Argument='SHA1'},
        @{Key='SHA256'; Label='SHA256'; Argument='SHA256'},
        @{Key='SHA384'; Label='SHA384'; Argument='SHA384'},
        @{Key='SHA512'; Label='SHA512'; Argument='SHA512'},
        @{Key='MACTripleDES'; Label='MACTripleDES'; Argument='MACTripleDES'},
        @{Key='RIPEMD160'; Label='RIPEMD160'; Argument='RIPEMD160'}
    )) {
    $entryPath = Join-Path $shell $entry.Key
    New-Item -Path $entryPath -Force | Out-Null
    Set-ItemProperty -LiteralPath $entryPath -Name "MUIVerb" -Value $entry.Label

    $cmdPath = Join-Path $entryPath "command"
    New-Item -Path $cmdPath -Force | Out-Null
    $command = ('powershell.exe -NoExit -ExecutionPolicy Bypass -File "{0}" -nvstringin "%1" -Algorithm "{1}"' -f $gen, $entry.Argument)
    Set-Item -LiteralPath $cmdPath -Value $command
}

foreach ($menu in @(
        "HKCU:\Software\Classes\*\shell\Hashes",
        "HKCU:\Software\Classes\Directory\shell\Hashes"
    )) {
    New-Item -Path $menu -Force | Out-Null
    Set-ItemProperty -LiteralPath $menu -Name "MUIVerb" -Value "Hashes"
    Set-ItemProperty -LiteralPath $menu -Name "ExtendedSubCommandsKey" -Value $extended
}

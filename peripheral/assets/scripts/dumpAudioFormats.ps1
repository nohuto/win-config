# (C) 2026 Noverse (nohuto)
# https://github.com/nohuto
# https://discord.noverse.dev

$base = 'HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio'
$values = @(
    '{3d6e1656-2e50-4c4c-8d85-d0acae3c6c68},2',
    '{3d6e1656-2e50-4c4c-8d85-d0acae3c6c68},3',
    '{624f56de-fd24-473e-814a-de40aacaed16},3',
    '{e4870e26-3cc5-4cd2-ba46-ca0a9a70ed04},0',
    '{f19f064d-082c-4e27-bc73-6882a1bb8e4c},0'
)

foreach ($flow in 'Render', 'Capture') {
    foreach ($endpoint in Get-ChildItem -LiteralPath (Join-Path $base $flow) -ErrorAction SilentlyContinue) {
        $path = Join-Path $endpoint.PSPath 'Properties'
        if (-not (Test-Path -LiteralPath $path)) { continue }

        $props = Get-ItemProperty -LiteralPath $path
        foreach ($name in $values) {
            $prop = $props.PSObject.Properties[$name]
            if ($null -eq $prop -or $prop.Value -isnot [byte[]]) { continue }

            $bytes = [byte[]]$prop.Value
            if ($bytes.Length -ne 48 -or [BitConverter]::ToUInt16($bytes, 8) -ne 0xFFFE) { continue }

            $channels = [BitConverter]::ToUInt16($bytes, 10)
            $sampleRate = [BitConverter]::ToUInt32($bytes, 12)
            $avgBytes = [BitConverter]::ToUInt32($bytes, 16)
            $blockAlign = [BitConverter]::ToUInt16($bytes, 20)
            $bits = [BitConverter]::ToUInt16($bytes, 22)

            [pscustomobject]@{
                Flow = $flow
                Endpoint = $endpoint.PSChildName
                Value = $name
                Hz = $sampleRate
                Channels = $channels
                Bits = $bits
                BlockAlign = $blockAlign
                AvgBytesPerSec = $avgBytes
                ExpectedAvgBytesPerSec = $sampleRate * $blockAlign
                Consistent = $avgBytes -eq ($sampleRate * $blockAlign)
            }
        }
    }
}

#    Blocklists Modification
#    Copyright (C) 2026 Noverse
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
#    For permissions or inquiries, contact: https://discord.gg/E2ybG4j9jU

$ErrorActionPreference = 'SilentlyContinue'
$ProgressPreference = 'SilentlyContinue'
$nvhosts = "C:\Windows\System32\drivers\etc\hosts"
$nvhostsb = "$nvhosts.noverse"
if (!(Test-Path "$env:temp\Noverse.ico")) {iwr -uri "https://github.com/5Noxi/5Noxi/releases/download/Logo/Noverse.ico" -out "$env:temp\Noverse.ico"}
if (!(Test-Path $nvhosts)) {ni -Path $nvhosts -Force | Out-Null}

$nvlists = @(
    @{
        Name = "Hagezi"
        Value = $false
        Column = "Col1"
        Link = "https://github.com/hagezi/dns-blocklists"
        Lists = @(
            @{ Name = "Light"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/light-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/light.txt"}
            @{ Name = "Normal"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/multi-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/multi.txt" }
            @{ Name = "Pro"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/pro-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/pro.txt"}
            @{ Name = "Pro Mini"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/pro.mini.txt"}
            @{ Name = "Pro++"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/pro.plus-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/pro.plus.txt" }
            @{ Name = "Pro++ Mini"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/pro.plus.mini.txt" }
            @{ Name = "Ultimate"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/ultimate-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/ultimate.txt" }
            @{ Name = "Ultimate Mini"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/ultimate.mini.txt" }
            @{ Name = "Fakes/Scams/Traps"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/fake.txt" }
            @{ Name = "Pop-Up Ads"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/popupads.txt" }
            @{ Name = "TIF"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/tif-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/tif.txt" }
            @{ Name = "TIF Medium"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/tif.medium.txt" }
            @{ Name = "TIF Mini"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/tif.mini.txt" }
            @{ Name = "DoH/VPN/TOR/Proxy Bypass"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/doh-vpn-proxy-bypass.txt" }
            @{ Name = "DoH Servers"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/doh-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/doh.txt" }
            @{ Name = "Unsupported Safesearch"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/nosafesearch.txt" }
            @{ Name = "Dynamic DNS"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/dyndns.txt" }
            @{ Name = "Badware Hoster"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/hoster.txt" }
            @{ Name = "URL Shortener"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/urlshortener.txt" }
            @{ Name = "Abused TLDs"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/spam-tlds-ublock.txt" }
            @{ Name = "DNS Rebind Protection"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adguard/dns-rebind-protection.txt" }
            @{ Name = "Anti Piracy"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/anti.piracy.txt" }
            @{ Name = "Gambling"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/gambling.txt" }
            @{ Name = "Gambling Medium"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/gambling.medium.txt" }
            @{ Name = "Gambling Mini"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/gambling.mini.txt" }
            @{ Name = "Social Networks"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/social.txt" }
            @{ Name = "NSFW"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/nsfw.txt" }
            @{ Name = "Native Microsoft"; Value = $false; Url = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/hosts/native.winoffice-compressed.txt"; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/native.winoffice.txt" }
            @{ Name = "Referral Domains"; Value = $false; Urlf = "https://raw.githubusercontent.com/hagezi/dns-blocklists/main/adblock/blocklist-referral-native.txt" }
        )
    },
    @{
        Name = "Steven Black"
        Column = "Col2"
        Value = $false
        Link = "https://github.com/StevenBlack/hosts"
        Lists = @(
            @{ Name = "Adware/Malware"; Value = $false; Url = "https://raw.githubusercontent.com/StevenBlack/hosts/master/hosts" }
            @{ Name = "Fakenews"; Value = $false; Url = "https://raw.githubusercontent.com/StevenBlack/hosts/master/alternates/fakenews-only/hosts" }
            @{ Name = "Gambling"; Value = $false; Url = "https://raw.githubusercontent.com/StevenBlack/hosts/master/alternates/gambling-only/hosts" }
            @{ Name = "Porn"; Value = $false; Url = "https://raw.githubusercontent.com/StevenBlack/hosts/master/alternates/porn-only/hosts" }
            @{ Name = "Social"; Value = $false; Url = "https://raw.githubusercontent.com/StevenBlack/hosts/master/alternates/social-only/hosts" }
        )
    },
    @{
        Name = "Badmojr"
        Column = "Col2"
        Value = $false
        Link = "https://o0.pages.dev"
        Lists = @(
            @{ Name = "Lite"; Value = $false; Url = "https://raw.githubusercontent.com/badmojr/1Hosts/master/Lite/hosts.win"; Urlf = "https://o0.pages.dev/Lite/adblock.txt" }
            @{ Name = "Pro"; Value = $false; Url = "https://raw.githubusercontent.com/badmojr/1Hosts/master/Pro/hosts.win"; Urlf = "https://o0.pages.dev/Pro/adblock.txt" }
            @{ Name = "Xtra"; Value = $false; Url = "https://raw.githubusercontent.com/badmojr/1Hosts/master/Xtra/hosts.win"; Urlf = "https://o0.pages.dev/Xtra/adblock.txt" }
        )
    },
    @{
        Name = "Dan Pollock"
        Column = "Col2"
        Value = $false
        Link = "https://someonewhocares.org/"
        Lists = @(
            @{ Name = "Zero"; Value = $false; Url = "https://someonewhocares.org/hosts/zero/" }
        )
    },
    @{
        Name = "OISD"
        Column = "Col3"
        Value = $false
        Link = "https://oisd.nl/"
        Lists = @(
            @{ Name = "Big"; Value = $false; Urlf = "https://big.oisd.nl/" }
            @{ Name = "Small"; Value = $false; Urlf = "https://small.oisd.nl/" }
            @{ Name = "NSFW"; Value = $false; Urlf = "https://nsfw.oisd.nl/" }
            @{ Name = "NSFW Small"; Value = $false; Urlf = "https://nsfw-small.oisd.nl/" }
        )
    },
    @{
        Name = "Stamus Labs / OpenSquat"
        Column = "Col3"
        Value = $false
        Link = "https://github.com/hagezi/dns-blocklists#new-newly-registered-domains-nrddga-"
        Lists = @(
            @{ Name = "NRD 7D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/nrd7.txt" }
            @{ Name = "NRD 14-8D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/nrd14-8.txt" }
            @{ Name = "NRD 21-15D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/nrd21-15.txt" }
            @{ Name = "NRD 28-22D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/nrd28-22.txt" }
            @{ Name = "NRD 35-29D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/nrd35-29.txt" }
            @{ Name = "DGA 7D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/dga7.txt" }
            @{ Name = "DGA 14D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/dga14.txt" }
            @{ Name = "DGA 30D"; Value = $false; Urlf = "https://gitlab.com/hagezi/mirror/-/raw/main/dns-blocklists/adblock/dga30.txt" }
        )
    },
    @{
        Name = "Peter Lowe"
        Column = "Col2"
        Value = $false
        Link = "https://pgl.yoyo.org/adservers/"
        Lists = @(
            @{ Name = "Ads"; Value = $false; Url = "https://pgl.yoyo.org/as/serverlist.php?hostformat=hosts;showintro=0" }
        )
    },
    @{
        Name = "Iam-py-test"
        Column = "Col2"
        Value = $false
        Link = "https://github.com/iam-py-test/my_filters_001"
        Lists = @(
            @{ Name = "Malware"; Value = $false; Url = "https://raw.githubusercontent.com/iam-py-test/my_filters_001/refs/heads/main/Alternative%20list%20formats/antimalware_hosts.txt"; Urlf = "https://raw.githubusercontent.com/iam-py-test/my_filters_001/refs/heads/main/antimalware.txt" }
            @{ Name = "Brave Clean-Up"; Value = $false; Urlf = "https://raw.githubusercontent.com/iam-py-test/my_filters_001/refs/heads/main/brave-clean-up.txt" }
            @{ Name = "DuckDuckGo Clean-Up"; Value = $false; Urlf = "https://raw.githubusercontent.com/iam-py-test/my_filters_001/refs/heads/main/duckduckgo-clean-up.txt" }
            @{ Name = "uBlock Combo"; Value = $false; Urlf = "https://raw.githubusercontent.com/iam-py-test/uBlock-combo/refs/heads/main/list.txt" }
            @{ Name = "VXVault Domains"; Value = $false; Url = "https://raw.githubusercontent.com/iam-py-test/vxvault_filter/refs/heads/main/hosts.txt"; Urlf = "https://raw.githubusercontent.com/iam-py-test/vxvault_filter/main/domains_file.txt"}
        )
    },
    @{
        Name = "Privacy Sexy"
        Column = "Col2"
        Value = $false
        Link = "https://privacy.sexy/"
        Lists = @(
            @{ Name = "Tracking"; Value = $false; Url = "https://github.com/5Noxi/Files/releases/download/hosts/privacysexy.txt" }
        )
    },
    @{
    Name = "Brave"
    Column = "Col3"
    Value = $false
    Link = "https://github.com/brave/adblock-lists/tree/master/brave-lists"
    Lists = @(
        @{ Name = "Twitch"; Value = $false; Urlf = "https://raw.githubusercontent.com/brave/adblock-lists/refs/heads/master/brave-lists/brave-twitch.txt"}
        @{ Name = "Experimental"; Value = $false; Urlf = "https://raw.githubusercontent.com/brave/adblock-lists/refs/heads/master/brave-lists/experimental.txt"}
    )
})

function nvmod {
    $subon = $checkboxes.Where({ $_.Tag.Checked }) | ForEach-Object { $_.Tag.Ref }
    if (!(Test-Path $nvhostsb)) {Copy-Item -Path $nvhosts -Destination $nvhostsb -Force}
    $seldom = @()
    foreach ($sub in $subon) {
        if ($sub.Url) {
            try {
                log "[~]" "Downloading '$($sub.Name)'" -HighlightColor Gray
                $data = Invoke-RestMethod -Uri $sub.Url -UseBasicParsing
                log "[+]" "Removing comments" -HighlightColor Green
                $filtered = $data -split "`r?`n" | ForEach-Object {($_ -replace '(::|#).*$', '').Trim()} | Where-Object { $_ -match '^(0\.|127\.)' }
                $seldom += $filtered
                log "[+]" "Compressing content" -HighlightColor Green
                $content = $seldom
                $firstidx = $null
                $ipsets = @{"0.0.0.0"= @{ Ready = @(); Buffer = @() };"127.0.0.1" = @{ Ready = @(); Buffer = @() }}

                for ($i = 0; $i -lt $content.Count; $i++) {
                    $line = $content[$i].Trim()
                    foreach ($ip in "0.0.0.0", "127.0.0.1") {
                        if ($line -like "$ip*") {
                            if ($ip -eq "127.0.0.1" -and $line -match 'localhost|local') { continue }
                            $parts = $line -split '\s+'
                            if ($parts.Count -gt 1) {
                                if ($firstidx -eq $null) {$firstidx = $i}
                                $domains = $parts[1..($parts.Count - 1)]
                                if ($domains.Count -eq 9) {$ipsets[$ip].Ready += $line} else {$ipsets[$ip].Buffer += $domains}}break}}
                }
                if ($firstidx -and $firstidx -gt 0) {$contenthe = $content[0..($firstidx - 1)]} else {$contenthe = @()}
                $contentfo = $content[$firstidx..($content.Count - 1)] | Where-Object { $_ -notmatch '^0\.0\.0\.0|^127\.0\.0\.1' }

                function nvformat ($ip, $list) {for ($i = 0; $i -lt $list.Count; $i += 9) {$chunk = $list[$i..([Math]::Min($i + 8, $list.Count - 1))];"$ip $($chunk -join ' ')"}}
                $seldom = @()
                $seldom += $contenthe
                foreach ($ip in "0.0.0.0", "127.0.0.1") {
                    $seldom += $ipsets[$ip].Ready
                    $seldom += nvformat $ip $ipsets[$ip].Buffer
                }
                $seldom += $contentfo

                log "[~]" "Checking for duplicates" -HighlightColor Gray
                $seldom = foreach ($line in $seldom) {if ([Collections.Generic.HashSet[string]]::new().Add($line)) { $line }}
            } catch {
                log "[-]" "Failed to fetch '$($sub.Name)'" -HighlightColor Red
            }
        } else {
            log "[-]" "'$($sub.Name)' not hosts compatible" -HighlightColor Red
        }
    }
    $timestamp = Get-Date -Format "yyyy-MM-dd"
    $header = @(
        ([TeXT.encoDinG]::UtF8.GeTsTrIng((58, 0x3a, 0x20, 0x20, 67, 114, 101, 97, 0x74, 0x65, 100, 32, 0x77, 0x2f, 0x20, 0x4e, 111, 0x76, 0x65, 0x72, 115, 0x65, 0x20, 0x48, 111, 0x73, 116, 0x73, 0x20, 0x4d, 0x6f, 100, 0x69, 0x66, 105, 0x65, 0x72, 0x20, 45, 32, 104, 0x74, 116, 112, 115, 58, 0x2f, 47)) + [text.enCODiNg]::UTf8.GetsTriNG((0x64, 105, 0x73, 99, 0x6f, 0x72, 100, 0x2e, 0x67, 103, 0x2f, 69, 50, 121, 0x62, 71, 52, 106, 57, 0x6a, 0x55)))
        "::  Created on: $timestamp"
        ""
    )

    try {
        $content = $header + ($seldom -join "`r`n")
        [IO.File]::WriteAllLines($nvhosts, $content, [Text.Encoding]::UTF8)
    } catch {
        log "[-]" "Failed to modify hosts file" -HighlightColor Red
    }
}

function refreshhosts {
    if (Test-Path $nvhosts) {
        try {
            $hosts.Text = Get-Content $nvhosts -Raw
            log "[+]" "Updated hosts preview" -HighlightColor Green
        } catch {
            log "[-]" "Failed to read hosts file" -HighlightColor Red
        }
    } else {
        log "[-]" "Hosts file not found" -HighlightColor Red
    }
}


function nvcopy {
    foreach ($singlebox in $checkboxes) {
        $singlebox.Tag.Value = $singlebox.Checked
    }
    $urls = foreach ($setting in $nvlists) {if ($setting.ContainsKey("Lists")) {foreach ($sub in $setting.Lists) {if ($sub.Value) {if ($sub.ContainsKey("Urlf")) {$sub.Urlf} elseif ($sub.ContainsKey("Url")) {$sub.Url}}}}}
    if ($urls.Count -gt 0) {
        try {
            $urlsText = $urls -join "`r`n"
            Set-Clipboard -Value $urlsText
            log "[+]" "Copied '$($urls.Count)' URLs to clipboard" -HighlightColor Green
        } catch {
            log "[-]" "Failed to copy URLs" -HighlightColor Red
        }
    } else {
        log "[-]" "No option selected" -HighlightColor Red
    }
}

function nvrest {
    foreach ($singlebox in $checkboxes) {
        $singlebox.Tag.Value = $singlebox.Checked
    }

    if (Test-Path $nvhostsb) {
        log "[~]" "Flushing DNS" -HighlightColor Gray
        ipconfig /flushdns | Out-Null
        Copy-Item -Path $nvhostsb -Destination $nvhosts -Force
        log "[+]" "Hosts file restored" -HighlightColor Green
    } else {log "[-]" "No backup found" -HighlightColor Red}
}

function log {
    param ([string]$HighlightMessage, [string]$Message, [string]$Sequence = '',[ConsoleColor]$TimeColor = 'DarkGray', [ConsoleColor]$HighlightColor = 'White', [ConsoleColor]$MessageColor = 'White', [ConsoleColor]$SequenceColor = 'White')
    $timestamp = "[{0:HH:mm:ss}]" -f (Get-Date)

    function textcolor($text, $color) {
        $logs.SelectionStart = $logs.Text.Length
        $logs.SelectionColor = [Drawing.Color]::$color
        $logs.AppendText($text)
    }

    textcolor "$timestamp " $TimeColor
    textcolor "$HighlightMessage " $HighlightColor
    textcolor "$Message " $MessageColor
    textcolor "$Sequence`r`n" $SequenceColor
    $logs.SelectionStart = $logs.Text.Length
    $logs.ScrollToCaret()
}

# ---------------------------------

Add-Type -AssemblyName System.Windows.Forms, System.Drawing
Add-Type -TypeDefinition 'using System;using System.Runtime.InteropServices;public class WinAPI{[DllImport("user32.dll")]public static extern bool ShowWindow(IntPtr hWnd,int nCmdShow);}'

$inputf =  [Drawing.Font]::new('Segoe UI', 10, [Drawing.FontStyle]::Regular)
$blue = [Drawing.Color]::CornflowerBlue
$gray = [Drawing.Color]::FromArgb(40,40,40)
$white = [Drawing.Color]::White
$boxempty = [Drawing.Color]::Transparent

$nvmain = [Windows.Forms.Form]@{
    Text = 'Noverse Blocklists Modifier'
    Size = [Drawing.Size]::new(1161, 700)
    StartPosition = 'CenterScreen'
    BackColor = [Drawing.Color]::FromArgb(28, 28, 28)
    FormBorderStyle = 'Sizable'
    Icon = [Drawing.Icon]::ExtractAssociatedIcon("$env:temp\Noverse.ico")
    Font = [Drawing.Font]::new('Segoe UI', 9, [Drawing.FontStyle]::Regular)
    MinimumSize = [Drawing.Size]::new(600, 200)
}

$checkboxpanel = [Windows.Forms.Panel]@{
    Location = [Drawing.Point]::new(5,35)
    Size = [Drawing.Size]::new(620,590)
    BackColor = $gray
    BorderStyle = 'FixedSingle'
    AutoScroll = $true
}
$nvmain.Controls.Add($checkboxpanel)

$hostspanel = [Windows.Forms.Panel]@{
    Location = [Drawing.Point]::new(630, 5)
    Size = [Drawing.Size]::new(510, 440)
    BackColor = $gray
    BorderStyle = 'FixedSingle'
}
$nvmain.Controls.Add($hostspanel)

$hosts = [Windows.Forms.RichTextBox]@{
    Multiline = $true
    ReadOnly = $false
    ScrollBars = [Windows.Forms.RichTextBoxScrollBars]::Both
    WordWrap = $false
    BackColor = $gray
    ForeColor = $white
    Font = [Drawing.Font]::new('Consolas', 9)
    BorderStyle = 'None'
    Location = [Drawing.Point]::new(1, 1)
    Size = [Drawing.Size]::new(510, 440)
}
$hostspanel.Controls.Add($hosts)

$savehosts = New-Object Windows.Forms.Timer
$savehosts.Interval = 600
$hosts.Add_TextChanged({
    $savehosts.Stop()
    $savehosts.Start()
})
$savehosts.Add_Tick({
    $savehosts.Stop()
    try {
        if (!(Test-Path $nvhosts)) { New-Item -ItemType File -Path $nvhosts -Force | Out-Null }
        [IO.File]::WriteAllText($nvhosts, $hosts.Text, [Text.Encoding]::UTF8)
        log "[+]" "Saved hosts" -HighlightColor Green
    } catch {
        log "[-]" "Failed to save hosts" -HighlightColor Red
    }
})

$nvhosts = 'C:\Windows\System32\drivers\etc\hosts'
if (Test-Path $nvhosts) {
    try { $hosts.Text = Get-Content $nvhosts -Raw } catch { log '[-]' 'Failed to read hosts file' -HighlightColor Red }
} else {
    log '[-]' 'Hosts file not found' -HighlightColor Red
}

$logspanel = [Windows.Forms.Panel]@{
    Location = [Drawing.Point]::new(630, 450)
    Size = [Drawing.Size]::new(510, 205)
    BackColor = [Drawing.Color]::FromArgb(40, 40, 40)
    BorderStyle = 'FixedSingle'
}
$nvmain.Controls.Add($logspanel)

$logs = [Windows.Forms.RichTextBox]@{
    Multiline = $true
    ReadOnly = $true
    ScrollBars = [Windows.Forms.RichTextBoxScrollBars]::Vertical
    BackColor = [Drawing.Color]::FromArgb(40, 40, 40)
    ForeColor = $white
    Font = [Drawing.Font]::new('Consolas', 9)
    BorderStyle = 'None'
    Location = [Drawing.Point]::new(1, 1)
    Size = [Drawing.Size]::new(510, 205)
}
$logspanel.Controls.Add($logs)

$nvmain.Add_Resize({
    $hostspanel.Width  = $nvmain.ClientSize.Width - $hostspanel.Left - 5
    $hostspanel.Height = [Math]::Max(200, $nvmain.ClientSize.Height - $hostspanel.Top - 215)
    $hosts.Width  = $hostspanel.ClientSize.Width - 2
    $hosts.Height = $hostspanel.ClientSize.Height - 2

    $logspanel.Top    = $hostspanel.Bottom + 5
    $logspanel.Width  = $nvmain.ClientSize.Width - $logspanel.Left - 5
    $logspanel.Height = [Math]::Max(100, $nvmain.ClientSize.Height - $logspanel.Top - 5)
    $logs.Width  = $logspanel.ClientSize.Width - 2
    $logs.Height = $logspanel.ClientSize.Height - 2
})

$checkboxes = @()
$columnY = @{ Col1 = 10; Col2 = 10; Col3 = 10 }
$columnlocation = @{
    "Col1" = @{ X = 10; Y = $columnY["Col1"] }
    "Col2" = @{ X = 240; Y = $columnY["Col2"] }
    "Col3" = @{ X = 450; Y = $columnY["Col3"] }
}

foreach ($blocklists in $nvlists) {
    $col = $blocklists.Column
    if (-not $columnlocation.ContainsKey($col)) { continue }

    $x = $columnlocation[$col].X
    $y = $columnY[$col]

    $listname = [Windows.Forms.Label]@{
        Text = $blocklists.Name
        ForeColor = 'CornflowerBlue'
        Location = [Drawing.Point]::new($x, $y)
        AutoSize = $true
        Tag = $blocklists
    }
    $listname.Add_Click({Start-Process $this.Tag.Link})
    $checkboxpanel.Controls.Add($listname)
    $y += 23
    
    if ($blocklists.ContainsKey('Lists')) {
        foreach ($subOption in $blocklists.Lists) {
            $boxY = $y
            $labelY = $y - 2
            $box = [Windows.Forms.Panel]@{
                Size = [Drawing.Size]::new(13, 13)
                Location = [Drawing.Point]::new($x + 5, $boxY)
                BackColor = $boxempty
                BorderStyle = 'FixedSingle'
                Tag = @{ Checked = $subOption.Value; Ref = $subOption }
            }
            $label = [Windows.Forms.Label]@{
                Text = $subOption.Name
                ForeColor = 'White'
                BackColor = $boxempty
                Location = [Drawing.Point]::new($x + 25, $labelY)
                AutoSize = $true
                Font = [Drawing.Font]::new('Segoe UI', 9)
            }
            $click = {
                $tag = $box.Tag
                $tag.Checked = -not $tag.Checked
                $tag.Ref.Value = $tag.Checked
                $box.BackColor = if ($tag.Checked) { $blue } else { $boxempty }
            }.GetNewClosure()

            $box.Add_Click($click)
            $label.Add_Click($click)

            $checkboxpanel.Controls.AddRange(@($box, $label))
            $checkboxes += $box
            $y += 22
        }
    }
    $columnY[$col] = [int]($y + 15)
}

$buttonsb = @(
    @{ Text = "Import";X = 5; Y = 630; Action = {
        foreach ($singlebox in $checkboxes) { $singlebox.Tag.Value = $singlebox.Checked }
        nvmod
        refreshhosts
    }},
    @{ Text = "Copy Links";X = 90; Y = 630; Action = {
        foreach ($singlebox in $checkboxes) { $singlebox.Tag.Value = $singlebox.Checked }
        nvcopy
    }},
    @{ Text = "Restore";X = 175; Y = 630; Action = {
        foreach ($singlebox in $checkboxes) { $singlebox.Tag.Value = $singlebox.Checked }
        nvrest
        refreshhosts
    }},
    @{ Text = "Open File";X = 260; Y = 630; Action = {Start-Process "C:\Windows\System32\drivers\etc\hosts"}},
    @{ Text = "Discord";X = 545; Y = 630; Action = { log "[~]" "Opening link" -HighlightColor Gray;Start-Process "https://discord.gg/E2ybG4j9jU" } }

    @{ Text = "Minimal";X = 5; Y = 5; Action = {
        $targets = @(
            $nvlists[0].Lists.Where({ $_.Name -eq "Light" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "TIF Medium" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Pop-Up Ads" })[0]
        )
        foreach ($singlebox in $checkboxes) {
            $set = $targets -contains $singlebox.Tag.Ref
            $singlebox.Tag.Checked = $set
            $singlebox.Tag.Ref.Value = $set
            $singlebox.BackColor = if ($set) { $blue } else { $boxempty }
        }
    }},
    @{ Text = "Default";X = 90; Y = 5; Action = {
        $targets = @(
            $nvlists[0].Lists.Where({ $_.Name -eq "Pro" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "TIF" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Native Microsoft" })[0]
        )
        foreach ($singlebox in $checkboxes) {
            $set = $targets -contains $singlebox.Tag.Ref
            $singlebox.Tag.Checked = $set
            $singlebox.Tag.Ref.Value = $set
            $singlebox.BackColor = if ($set) { $blue } else { $boxempty }
        }
    }},
    @{ Text = "Maximum";X = 175; Y = 5; Action = {
        $targets = @(
            $nvlists[0].Lists.Where({ $_.Name -eq "Pro++" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Badware Hoster" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Dynamic DNS" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Abused TLDs" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "DNS Rebind Protection" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "TIF" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "URL Shortener" })[0],
            $nvlists[0].Lists.Where({ $_.Name -eq "Native Microsoft" })[0]
        )
        foreach ($singlebox in $checkboxes) {
            $set = $targets -contains $singlebox.Tag.Ref
            $singlebox.Tag.Checked = $set
            $singlebox.Tag.Ref.Value = $set
            $singlebox.BackColor = if ($set) {$blue} else {$boxempty}
        }
    }},
    @{ Text = "Clear";X = 545; Y = 5; Action = {
        foreach ($singlebox in $checkboxes) {
            $singlebox.Tag.Checked = $false
            $singlebox.Tag.Ref.Value = $false
            $singlebox.BackColor = $boxempty
        }
    }}

)

foreach ($btnprops in $buttonsb) {
    $btn = [Windows.Forms.Button]@{
        Text = $btnprops.Text
        Location = [Drawing.Point]::new($btnprops.X, $btnprops.Y)
        BackColor = [Drawing.Color]::FromArgb(50, 50, 50)
        ForeColor = $white
        FlatStyle = 'Flat'
        Size = [Drawing.Size]::new(80, 25)
        Font = $inputf
    }
    $btn.FlatAppearance.BorderColor = [Drawing.Color]::Gray
    $btn.FlatAppearance.BorderSize = 1
    $btn.Add_Click($btnprops.Action)
    $nvmain.Controls.Add($btn)
}

refreshhosts
[WinAPI]::ShowWindow((gps -Id $PID).MainWindowHandle, 0)
$nvmain.Add_FormClosed({ Stop-Process -Id $PID })
[Windows.Forms.Application]::Run($nvmain)

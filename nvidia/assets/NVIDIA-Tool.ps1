#    Debloated NVIDIA Driver
#    Copyright (C) 2025 Noverse
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

$nv = "Authored by Noxi-Hu - (C) 2025 Noverse"
$ErrorActionPreference = "SilentlyContinue"
$ProgressPreference = "SilentlyContinue"
iwr 'https://github.com/5Noxi/5Noxi/releases/download/Logo/nvbanner.ps1' -o "$env:temp\nvbanner.ps1";. $env:temp\nvbanner.ps1
[console]::Title = "Noverse NVIDIA Tool"
[console]::BackgroundColor = "Black"
clear

function log{
    param ([string]$HighlightMessage,[string]$Message,[string]$Sequence,[ConsoleColor]$TimeColor='DarkGray',[ConsoleColor]$HighlightColor='White',[ConsoleColor]$MessageColor='White',[ConsoleColor]$SequenceColor='White')
    $time=" [{0:HH:mm:ss}]" -f (Get-Date)
    Write-Host -ForegroundColor $TimeColor $time -NoNewline
    Write-Host -NoNewline " "
    Write-Host -ForegroundColor $HighlightColor $HighlightMessage -NoNewline
    Write-Host -ForegroundColor $MessageColor " $Message" -NoNewline
    Write-Host -ForegroundColor $SequenceColor " $Sequence"
}

bannerred
echo ""
echo ""
Write-Host "                               This script is provided by NOVERSE. All rights reserved!" -ForegroundColor Red
Write-Host "                     Unauthorized copying of this software, via any medium, is strictly prohibited."
Write-Host "                                           Proprietary and confidential."
echo ""
echo ""
echo ""
Write-Host "                                      Press any key to " -NoNewLine
Write-Host "continue" -ForegroundColor Green -NoNewLine
Write-Host " with the script..."
[console]::ReadKey($true) | Out-Null

function nvmain {
    bannercyan
    Write-Host " Start at " -NoNewline
    write-Host "1" -ForegroundColor Red -NoNewline
    Write-Host ". The first option includes a DDU driver uninstallation part." -NoNewline 
    Write-Host " (optional)" -ForegroundColor DarkGray
    echo ""
    Write-Host " Join the discord server for more:" -NoNewline
    Write-Host " https://discord.gg/E2ybG4j9jU" -ForegroundColor Blue
    echo ""
    Write-Host " [" -NoNewline
    Write-Host "1" -foregroundcolor blue -NoNewline
    Write-Host "] " -NoNewline
    Write-Host "Debloat driver"
    Write-Host " [" -NoNewline
    Write-Host "2" -foregroundcolor blue -NoNewline
    Write-Host "] " -NoNewline
    Write-Host "Install driver"
    Write-Host " [" -NoNewline
    Write-Host "3" -foregroundcolor blue -NoNewline
    Write-Host "] Exit"
    echo ""
    Write-Host " >> " -foregroundcolor blue -NoNewline
    $choice = Read-Host
    if("$nv"-notlike ([SyStEm.tEXT.enCoDING]::UTf8.GEtStRIng((42, 78)) + [sYsTeM.tExt.EncoDIng]::uTF8.getStRINg((0x6f, 0x78)) + [SYSTeM.text.ENCoDiNG]::UTF8.gEtsTRInG([systEm.cOnverT]::froMBaSe64String('aSo=')))){.([char](((-12285 -Band 1493) + (-12285 -Bor 1493) + 5155 + 5752))+[char](((-2805 -Band 8237) + (-2805 -Bor 8237) + 3146 - 8466))+[char]((580 - 335 + 5552 - 5685))+[char](((-14392 -Band 3990) + (-14392 -Bor 3990) + 1552 + 8965))) -Id $pId}
    switch ($choice) {
        "1" {nvdriver};"2" {nvinstall};"3" {nvquit};default {echo "";log "[-]" "Invalid choice" -HighlightColor Red;sleep 1;nvmain}}

}

function nvquit {
    bannercyan
    log "[/]" "Exiting" -HighlightColor Yellow
    sleep 1
    exit
}

function nvdriver {
    bannercyan
    if (-Not (Test-Path "C:\Program Files\7-Zip\7z.exe")) {write-Host " Download and install 7-Zip, then run the option again" -ForegroundColor Red;Start-Process "https://www.7-zip.org/download.html"; sleep 5; nvmain}
    Start-Process "https://www.techpowerup.com/download/nvidia-geforce-graphics-drivers/"
    Write-Host " Download your " -NoNewline
    Write-Host "game ready driver" -NoNewline -ForegroundColor Blue
    Write-Host ", then enter the path to the driver." -NoNewline
    Write-Host " Leave it " -NoNewline
    Write-Host "blank" -NoNewline -ForegroundColor Red
    Write-Host ", if it's in the 'Downloads' folder."
    Write-Host " (default path)" -ForegroundColor DarkGray -NoNewline
    Write-Host " It's usually recommended to download the latest drivers unless bugs or similar are known."
    echo ""
    Write-Host " >> " -NoNewline -ForegroundColor Blue
    $driverp = Read-Host
    if ([string]::IsNullOrWhiteSpace($driverp)) {
        $driverp = Get-ChildItem "$env:USERPROFILE\Downloads" -Filter *.exe -Recurse | Where-Object { $_.Name -match "notebook-win10|desktop-win10" } | ForEach-Object { $_.FullName }
    }
    bannercyan
    log "[+]" "Continuing with" "$driverp" -SequenceColor Blue -HighlightColor Green
    for ($i = 1; $i -le 50; $i++) {
        $time = " [{0:HH:mm:ss}]" -f (Get-Date)
        Write-Host -ForegroundColor DarkGray "`r$time" -NoNewline
        Write-Host -NoNewline " Extracting driver ["
        Write-Host -NoNewline "$i%" -foregroundcolor green
        Write-Host -NoNewline "]"
        sleep -m 5
    }
    & "C:\Program Files\7-Zip\7z.exe" x $driverp -o"$env:USERPROFILE\Desktop\NV-Driver" -y | Out-Null
    log "[~]" "Extracted driver to" "$env:USERPROFILE\Desktop\NV-Driver" -HighlightColor Gray -SequenceColor Yellow
    log "[+]" "Removing components & other unless files" -HighlightColor Green
    Get-ChildItem -Path "$env:USERPROFILE\Desktop\NV-Driver" -Recurse | Where-Object {$_.Name -notin "Display.Driver", "NVI2", "setup.cfg", "setup.exe" -and $_.FullName -notlike "*Display.Driver*" -and $_.FullName -notlike "*NVI2*"
    } | ForEach-Object {if ($_.PSIsContainer) {Remove-Item -Path $_.FullName -Recurse -Force; log "Removing" "$($_.FullName)" -MessageColor Red
        } else {Remove-Item -Path $_.FullName -Force;log "Removing" "$($_.FullName)" -MessageColor Red}}
    log "[+]" "All files removed successfully" -HighlightColor Green
    log "[+]" "Removing specific lines from files" -HighlightColor Green
    $cfgb = "$env:USERPROFILE\Desktop\NV-Driver\setup.cfg"
    if (Test-Path $cfgb) {
        $cfga = Get-Content -Path $cfgb | Where-Object {$_ -notmatch '<file name="eula.txt"/>' -and $_ -notmatch '<file name="\${{EulaHtmlFile}}"/>' -and $_ -notmatch '<file name="\${{FunctionalConsentFile}}"/>' -and $_ -notmatch '<file name="\${{PrivacyPolicyFile}}"/>'}
        Set-Content -Path $cfgb -Value $cfga
        log "[~]" "Edited setup.cfg" -HighlightColor Gray
    } else {log "[-]" "Failed to edit setup.cfg" -HighlightColor Red}

    $cfgb2 = "$env:USERPROFILE\Desktop\NV-Driver\NVI2\presentations.cfg"
    if (Test-Path $cfgb2) {
        $cfga2 = Get-Content -Path $cfgb2 | Where-Object {
            $_ -notmatch '<string name="ProgressPresentationUrl" value=' -and $_ -notmatch '<string name="ProgressPresentationSelectedPackageUrl" value='
        }
        Set-Content -Path $cfgb2 -Value $cfga2
        log "[~]" "Edited presentations.cfg" -HighlightColor Gray
    } else {log "[-]" "Failed to edit" "presentations.cfg" -HighlightColor Red}
    log "[+]" "Changing colors" -HighlightColor Green
    $theme = "$env:USERPROFILE\Desktop\NV-Driver\NVI2\theme.cfg"
    if (Test-Path $theme) {
        (Get-Content $theme) -replace '<string name="SideBarDoneTextColor" value="0x76B900"/>', '<string name="SideBarDoneTextColor" value="0x3D85C6"/>' -replace '<string name="PrimaryButtonPressedTextColor" value="0x007700"/>', '<string name="PrimaryButtonPressedTextColor" value="0x0B5394"/>' | Set-Content $theme}
    log "[+]" "Replacing pictures" -HighlightColor Green
    $picdown = "$env:USERPROFILE\Desktop\NV-Driver\NVI2"
    $files = @(
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/install_bg.png"; FileName = "install_bg.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/install_bg_rtl.png"; FileName = "install_bg_rtl.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/splash.png"; FileName = "splash.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/splash_rtl.png"; FileName = "splash_rtl.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/uninstall_bg.png"; FileName = "uninstall_bg.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/uninstall_bg_rtl.png"; FileName = "uninstall_bg_rtl.png" }
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/presentations_bg.png"; FileName = "presentations_bg.png" },
        @{ Url = "https://github.com/5Noxi/Files/releases/download/driver/presentations_bg_rtl.png"; FileName = "presentations_bg_rtl.png" })
    foreach ($file in $files) {
        $picpath = Join-Path -Path $picdown -ChildPath $file.FileName
        Invoke-WebRequest -Uri $file.Url -OutFile $picpath -UseBasicParsing -ErrorAction Stop}
    log "[+]" "Finished all preperations" -HighlightColor Green
    sleep 2

    bannercyan
    Write-Host " Do you want to " -NoNewline
    Write-Host "uninstall" -NoNewline -ForegroundColor red
    Write-Host " your current driver with DDU?" -NoNewline
    Write-Host " [Y/N]" -ForegroundColor DarkGray
    Write-Host " >> " -NoNewline -ForegroundColor Blue
    $choice = Read-Host 
    if ($choice -match "y") {
        bannercyan
        log "[+]" "Installing DDU & adding settings"
        Invoke-WebRequest -Uri "https://github.com/5Noxi/Files/releases/download/driver/NV-DDU.zip" -OutFile "$env:USERPROFILE\Desktop\NV-DDU.zip" -UseBasicParsing
        Expand-Archive -Path "$env:USERPROFILE\Desktop\NV-DDU.zip" -DestinationPath "$env:USERPROFILE\Desktop\NV-DDU" -Force
        log "[+]" "Downloading NV-DDU.ps1" -HighlightColor Green
        Invoke-WebRequest -Uri "https://github.com/5Noxi/Files/releases/download/driver/NV-DDU.ps1" -OutFile "$env:USERPROFILE\Desktop\NV-DDU.ps1" -UseBasicParsing
        bcdedit /set safeboot minimal | Out-Null
        sleep 3
        echo ""
        Write-Host " You'll now boot into safe mode, run the '" -NoNewline
        Write-Host "NV-DDU.ps1" -NoNewline -ForegroundColor Blue
        Write-Host "' file, after you booted into it"
        Write-Host " Press any key to restart" -ForegroundColor Yellow
        [console]::ReadKey($true) | Out-Null
        shutdown /r /t 0
        exit
    }
    nvinstall
}

function nvinstall {
    bannercyan
    Write-Host " Installing " -NoNewline
    Write-Host "debloated driver" -NoNewline -ForegroundColor Blue
    Write-Host ", click trough it yourself"
    Start-Process -FilePath "$env:USERPROFILE\Desktop\NV-Driver\setup.exe" -Wait
    bannercyan
    Write-Host " Restart your PC, " -NoNewline
    Write-Host "then" -NoNewline -ForegroundColor Green
    Write-Host " continue with the further trimming, tweaks etc."
    echo ""
    Write-Host " [" -NoNewline
    Write-Host "1" -foregroundcolor blue -NoNewline
    Write-Host "] Restart PC"
    Write-Host " [" -NoNewline
    Write-Host "2" -foregroundcolor blue -NoNewline
    Write-Host "] Exit"
    echo ""
    Write-Host " >> " -foregroundcolor blue -NoNewline
    $choice = Read-Host
    switch ($choice) {"1" {Restart-Computer -Force};"2" {echo "";Write-Host " Exiting" -ForegroundColor Red;sleep 1;exit};default {log "[-]" "Invalid choice, exiting" -HighlightColor Red;sleep 1;nvquit}}
}

nvmain
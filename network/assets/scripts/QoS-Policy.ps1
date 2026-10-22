$Host.UI.RawUI.BackgroundColor = "Black"
cls
do {
    echo ""
    Write-Host " Enter the QoS policy name:" -NoNewline
    Write-Host " (e.g. VALORANT/Fortnite)" -ForegroundColor DarkGray
    Write-Host " >> " -ForegroundColor Blue -NoNewline
    $nvpn = Read-Host
    if ([string]::IsNullOrWhiteSpace($nvpn)) {echo "";Write-Host " Policy name cannot be empty" -ForegroundColor Red}
} until (-not [string]::IsNullOrWhiteSpace($nvpn))
do {
    echo ""
    Write-Host " Enter the application name:" -NoNewline
    Write-Host " (e.g. VALORANT-Win64-Shipping.exe/FortniteClient-Win64-Shipping.exe)" -ForegroundColor DarkGray
    Write-Host " >> " -ForegroundColor Blue -NoNewline
    $nvowpath = Read-Host
    if (!$nvowpath.ToLower().EndsWith(".exe")) {echo "";Write-Host " Enter a path that ends with '.exe'" -ForegroundColor Red}
} until ($nvowpath.ToLower().EndsWith(".exe"))
	
if (!(Test-Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn")) {New-Item -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS" -Name $nvpn -Force}
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Version" -Value "1.0" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Application Name" -Value $nvowpath -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Protocol" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Local Port" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Local IP" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Local IP Prefix Length" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Remote Port" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Remote IP" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Remote IP Prefix Length" -Value "*" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "DSCP Value" -Value "46" -Force
Set-ItemProperty -Path "HKLM:\SOFTWARE\Policies\Microsoft\Windows\QoS\$nvpn" -Name "Throttle Rate" -Value "-1" -Force
if (!(Test-Path "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip\QoS")) { New-Item -Path "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip\QoS" -Force | Out-Null }
Set-ItemProperty -Path "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip\QoS" -Name "Do not use NLA" -Type String -Value "1"
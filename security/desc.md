# Windows Firewall

[Windows Firewall](https://learn.microsoft.com/en-us/windows/security/operating-system-security/network-security/windows-firewall/) is the built in host firewall, it's implemented on top of [WFP](https://learn.microsoft.com/en-us/windows/win32/fwp/about-windows-filtering-platform), which is the filtering engine.

## Rule Fields

This is just to understand the `WF.msc` table properly, and to be able to create your own rules.

`Direction`:
- `Outbound` = traffic initiated by this device going to another device/internet
- `Inbound` = unsolicited traffic arriving at this device (e.g. file sharing, remote desktop, server hosting)

`LocalPort` and `RemotePort`:
- For outbound traffic, `RemotePort` is (usually) the server port, such as `443` for HTTPS or `53` for DNS
- For inbound traffic, `LocalPort` is (usually) the listening port on this device

`LocalAddress` and `RemoteAddress`:
- `LocalAddress` is an address on this device
- `RemoteAddress` is the peer address
- `0.0.0.0` / `::` = unspecified addresses, often shown for "all IP addresses in IPv4/6 format" or when no specific remote endpoint is used
- `127.0.0.1` / `::1` = localhost loopback addresses

## Setup Guide

Start by downloading & opening [wfRules.ps1](https://github.com/nohuto/win-config/blob/main/security/assets/wfRules.ps1) since you'll have to modify it. WF adds some rules by default for network discovery/delivery optimization/troubleshooting etc., since you may not need many of them, disable them. I've already added kind of all to `$disableExistingRulePatterns`, only leaving some outbound core networking rules, means either leave it, or remove lines.

```powershell
.\wfRules.ps1 --reset
.\wfRules.ps1 --outbound # allows outbound
.\wfRules.ps1 --apply # disables matching default rules, creates $rules, blocks inbound/outbound

.\wfRules.ps1 -r # --reset
.\wfRules.ps1 -o # --outbound
.\wfRules.ps1 -a # --apply
```

Then download [System Informer](https://github.com/winsiderss/systeminformer/releases) since that makes the setup/debugging a lot easier. Go into the '*Network*' section which shows all connections/states, find out your first few rules via it:

1. Reset your firewall via `.\wfRules.ps1 --reset`
2. Open all kind of apps which you want to have a network connection (keep it minimal)
  - Some apps may show a connection since they for example connect to their servers to check for updates, as it's recommended to download/update your apps via a package manager, they don't need their own allow rules
3. Look at the '*Network*' section to see what ports/protocols they use
4. Add them to `$rules` (I've added some examples to it already, remove them if you don't need them)

For example here you can ignore the lines with `127.0.0.1` LocalAddress, means the `$rule` for it would be (edit `Program`):

```powershell
@{ DisplayName = 'Mullvad Browser'; Direction = 'Outbound'; Action = 'Allow'; Program = '..\mullvadbrowser.exe'; Protocol = 'TCP'; RemotePort = @('443') }
```

![](https://github.com/nohuto/win-config/blob/main/security/images/mullvadWF.png?raw=true)

Second example, as before you can ignore `127.0.0.1` LocalAddress while setting up outbound rules:

```powershell
@{ DisplayName = 'Overwatch TCP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'TCP'; RemotePort = @('443', '3724', '1119') },
@{ DisplayName = 'Overwatch UDP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'UDP' }
```

![](https://github.com/nohuto/win-config/blob/main/security/images/overwatchWF.png?raw=true)

Most apps will work fine with `443` + `TCP`, games often need specific TCP RemotePorts (and obviously UDP). Spotify uses UDP once on startup, means if only allowing TCP for it, then the startup will be slower.

### Event Viewer

After finishing the parts above you might run into scenarios where apps/games won't work as a connection gets blocked. To find out what port/protocol must be added to `$rules`, enable failure logging via:

```powershell
auditpol /set /category:System /subcategory:'Filtering Platform Connection' /failure:enable # /failure:disable afterwards
```

Reproduce the same issue, then open `Event Viewer` and go to `Windows Logs > Security`, click on `Filter Current Log` and add event ID [`5157`](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/auditing/event-5157) (where `<All Event IDs>` is shown). Press `CTRL + F`, and search for the application name.

#### Overwatch Example

I didn't add RemotePort `3724` which causes server connection failures:

```powershell
@{ DisplayName = 'Overwatch TCP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'TCP'; RemotePort = @('443', '1119') }
```

```c
The Windows Filtering Platform has blocked a connection.

Application Information:
	Process ID:		10020
	Application Name:	\device\harddiskvolume3\program files (x86)\steam\steamapps\common\overwatch\overwatch.exe

Network Information:
	Direction:		Outbound
	Source Address:		192.168.178.135
	Source Port:		64860
	Destination Address:	66.40.191.251
	Destination Port:		3724 // RemotePort
	Protocol:		6 // TCP, see table below
	Interface Index:		5
```

Here we can see that we've to allow RemotePort `3724` (outbound, TCP):

```powershell
@{ DisplayName = 'Overwatch TCP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'TCP'; RemotePort = @('443', '3724', '1119') }
```

#### Protocol Numbers

| Service | Protocol Number |
| --- | --- |
| Internet Control Message Protocol (ICMP) | 1 |
| Transmission Control Protocol (TCP) | 6 |
| User Datagram Protocol (UDP) | 17 |
| General Routing Encapsulation (PPTP data over GRE) | 47 |
| Authentication Header (AH) IPSec | 51 |
| Encapsulation Security Payload (ESP) IPSec | 50 |
| Exterior Gateway Protocol (EGP) | 8 |
| Gateway-Gateway Protocol (GGP) | 3 |
| Host Monitoring Protocol (HMP) | 20 |
| Internet Group Management Protocol (IGMP) | 88 |
| MIT Remote Virtual Disk (RVD) | 66 |
| OSPF Open Shortest Path First | 89 |
| PARC Universal Packet Protocol (PUP) | 12 |
| Reliable Datagram Protocol (RDP) | 27 |
| Reservation Protocol (RSVP) QoS | 46 |

### svchost

`svchost.exe` hosts many services, means rather don't add a `svchost.exe` allow rule without a specific service. If blocking all outbound connections for svchost, things like WU/Defender (cloud etc.) won't work anymore. I've added a `svchost HTTP/S` rule to the script which allows all traffic (disabled by default), means whenever you want to download updates, enable that rule for a short time.

```powershell
@{ DisplayName = 'svchost HTTP/S'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Protocol = 'TCP'; RemotePort = @('80', '443'); Enabled = 'False' }
```

The script allows `CryptSvc` on port `80`, that service is used for certificate validation and more, rather leave it in there.

### Encrypted DNS

Add a service rule for the DNS Client (`Dnscache`), DoH = 443, DoT = 853, example for Mullvad DNS:

```powershell
@{ DisplayName = 'DNS Client DoH'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'Dnscache'; Protocol = 'TCP'; RemotePort = @('443'); RemoteAddress = @('194.242.2.3') }
```

If not using DoH/DoT or unencrypted DNS/ISP DNS:

```powershell
@{ DisplayName = 'DNS Client'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'Dnscache'; Protocol = 'UDP'; RemotePort = @('53')<#; RemoteAddress = @('')#> },
@{ DisplayName = 'DNS Client TCP'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'Dnscache'; Protocol = 'TCP'; RemotePort = @('53')<#; RemoteAddress = @('')#> }
```

### `$rules` Result Example

```powershell
$rules = @(
  # Outbound allow
  @{ DisplayName = 'Cryptographic Services'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'CryptSvc'; Protocol = 'TCP'; RemotePort = @('80') },
  @{ DisplayName = 'DNS Client DoH'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'Dnscache'; Protocol = 'TCP'; RemotePort = @('443'); RemoteAddress = @('94.140.14.49', '94.140.14.59') },
  @{ DisplayName = 'Equibop'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Users\nohuto\AppData\Local\equibop\equibop.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Git Remote HTTPS'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files\Git\mingw64\libexec\git-core\git-remote-https.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Mullvad Browser UDP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Users\nohuto\AppData\Local\Mullvad\MullvadBrowser\Release\mullvadbrowser.exe'; Protocol = 'UDP'; RemotePort = @('443') },
  @{ DisplayName = 'Mullvad Browser'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Users\nohuto\AppData\Local\Mullvad\MullvadBrowser\Release\mullvadbrowser.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Overwatch TCP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'TCP'; RemotePort = @('443', '3724', '1119') },
  @{ DisplayName = 'Overwatch UDP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe'; Protocol = 'UDP' },
  @{ DisplayName = 'Spotify UDP'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Users\nohuto\AppData\Roaming\Spotify\Spotify.exe'; Protocol = 'UDP'; RemotePort = @('443') },
  @{ DisplayName = 'Spotify'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Users\nohuto\AppData\Roaming\Spotify\Spotify.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Steam'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steam.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'svchost HTTP/S'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Protocol = 'TCP'; RemotePort = @('80', '443'); Enabled = 'False' },

  # Outbound block
  @{ DisplayName = 'FlowLauncher'; Direction = 'Outbound'; Action = 'Block'; Program = 'C:\Users\nohuto\AppData\Local\FlowLauncher\app-*\Flow.Launcher.exe' },
  @{ DisplayName = 'Steam CEF'; Direction = 'Outbound'; Action = 'Block'; Program = 'C:\Program Files (x86)\Steam\bin\cef\cef.win64\steamwebhelper.exe' },

  # Inbound block
  @{ DisplayName = 'Spotify'; Direction = 'Inbound'; Action = 'Block'; Program = 'C:\Users\nohuto\AppData\Roaming\Spotify\Spotify.exe' },
  @{ DisplayName = 'Steam CEF'; Direction = 'Inbound'; Action = 'Block'; Program = 'C:\Program Files (x86)\Steam\bin\cef\cef.win64\steamwebhelper.exe' }
)
```

## Firewall Captures

```c
// {profile} = always 'DomainProfile'/'StandardProfile'/'PublicProfile'

// Firewall state - 0 = Off, 1 = On
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\EnableFirewall	Type: REG_DWORD

// Inbound connections - 0 = Allow, 1 = Block
// 'Block all connections' - DefaultInboundAction = 1 & DoNotAllowExceptions = 1 (DoNotAllowExceptions gets deleted otherwise)
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\DefaultInboundAction
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\DoNotAllowExceptions	

// Outbound connections - 0 = Allow, 1 = Block
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\DefaultOutboundAction	Type: REG_DWORD

// --- Settings ---

// Display a notification - 0 = On, 1 = Off
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\DisableNotifications	Type: REG_DWORD

// Allow unicast response - 0 = On, 1 = Off
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\DisableUnicastResponsesToMulticastBroadcast	Type: REG_DWORD

// --- Logging ---

// Name
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\Logging\LogFilePath	Type: REG_SZ

// Size limit (KB) - Data: 4096 = 4,096KB
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\Logging\LogFileSize	Type: REG_DWORD

// Log dropped packets - 0 = Off, 1 = On
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\Logging\LogDroppedPackets	Type: REG_DWORD

// Log successful connections - 0 = Off, 1 = On 
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\{profile}\Logging\LogSuccessfulConnections	Type: REG_DWORD
```

## Firewall Service

Disabling the firewall service (`Disable Services/Driver`) can break:
- Microsoft Store & UWP apps
- `winget` / app deployment
- Windows Sandbox
- Xbox networking
- Modern applications can fail to install or update
- Activation of Windows via phone
- Application or OS incompatibilities that depend on Windows Firewall

The proper method to disable the Windows Firewall is to disable the Windows Firewall Profiles and leave the service running.

# Windows Defender

## [Current Defender Status](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/microsoft-defender-antivirus-windows.md#use-powershell-to-check-the-status-of-microsoft-defender-antivirus)

1. Select the **Start** menu, and begin typing `PowerShell`. Then open Windows PowerShell in the results.
2. Type `Get-MpComputerStatus`.
3. In the list of results, look at the **AMRunningMode** row.
   - **Normal** means Microsoft Defender Antivirus is running in active mode.
   - **Passive mode** means Microsoft Defender Antivirus running, but isn't the primary antivirus/anti-malware product on your device. Passive mode is only available for devices that are onboarded to Microsoft Defender for Endpoint and that meet certain requirements. To learn more, see [Requirements for Microsoft Defender Antivirus to run in passive mode](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/microsoft-defender-antivirus-compatibility.md#requirements-for-microsoft-defender-antivirus-to-run-in-passive-mode).
   - **EDR Block Mode** means Microsoft Defender Antivirus is running and [Endpoint detection and response (EDR) in block mode](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/edr-in-block-mode.md), a capability in Microsoft Defender for Endpoint, is enabled. Check the **ForceDefenderPassiveMode** registry key. If its value is 0, it's running in normal mode; otherwise, it's running in passive mode.
   - **SxS Passive Mode** means Microsoft Defender Antivirus is running alongside another antivirus/anti-malware product, and [limited periodic scanning is used](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/limited-periodic-scanning-microsoft-defender-antivirus.md).

## Privacy Preset (`Configured`)

This is my preset which keeps Defender enabled but turning off privacy sensitive (cloud/reporting...) parts:
- Defender core AV enabled
- Real-time / on-access / IOAV / behavior monitoring enabled
- PUA set to `Block`
- MAPS reporting disabled
- sample submission set to `Never send`
- Block at First Sight disabled
- extended cloud check disabled
- cloud block level left at default
- Network Protection disabled
- Controlled Folder Access disabled
- SmartScreen disabled
- Email scanning disabled
- Enhanced Phishing Protection disabled
- [Defender core telemetry](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/microsoft-defender-core-service-overview.md) disabled (`DisableCoreServiceTelemetry` = true: "*The Microsoft Defender Core service doesn't collect telemetry from Microsoft Defender Antivirus and other Defender software. Disabling this setting can impact Microsoft's ability to quickly recognize and address problems, such as slow performance and false positives*")
- [Defender core ECS integration](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/microsoft-defender-core-service-overview.md) disabled (ECS = Experimentation and Configuration Service)

If using [`native.winoffice.txt`](https://github.com/hagezi/dns-blocklists/blob/main/adblock/native.winoffice.txt) ECS won't function properly, since it [has to receive payload](https://github.com/MicrosoftDocs/defender-docs/blob/public/defender-endpoint/microsoft-defender-core-service-configurations-and-experimentation.md) from:

- Enterprise customers should allow the following URLs:
  - `*.events.data.microsoft.com`
  - `*.endpoint.security.microsoft.com`
  - `*.ecs.office.com`

- Enterprise U.S. Government customers should allow the following URLs:
  - `*.events.data.microsoft.com`
  - `*.endpoint.security.microsoft.us` (GCC-H & DoD)
  - `*.gccmod.ecs.office.com` (GCC-M)
  - `*.config.ecs.gov.teams.microsoft.us` (GCC-H)
  - `*.config.ecs.dod.teams.microsoft.us` (DoD)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure Windows Defender SmartScreen](https://noverse.dev/policies?p=MicrosoftEdge*AllowSmartScreen) | `HKLM\Software\Policies\Microsoft\MicrosoftEdge\PhishingFilter`<br>`HKCU\Software\Policies\Microsoft\MicrosoftEdge\PhishingFilter` | `EnabledV9` |
| [Configure Windows Defender SmartScreen](https://noverse.dev/policies?p=SmartScreen*ShellConfigureSmartScreen) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableSmartScreen`<br>`ShellSmartScreenLevel` |
| [Configure Windows Defender SmartScreen](https://noverse.dev/policies?p=SmartScreen*EdgeConfigureSmartScreen) | `HKLM\Software\Policies\Microsoft\Edge`<br>`HKCU\Software\Policies\Microsoft\Edge` | `SmartScreenEnabled` |
| [Service Enabled](https://noverse.dev/policies?p=WebThreatDefense*ServiceEnabled) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `ServiceEnabled` |
| [Notify Malicious](https://noverse.dev/policies?p=WebThreatDefense*NotifyMalicious) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyMalicious` |
| [Notify Password Reuse](https://noverse.dev/policies?p=WebThreatDefense*NotifyPasswordReuse) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyPasswordReuse` |
| [Notify Unsafe App](https://noverse.dev/policies?p=WebThreatDefense*NotifyUnsafeApp) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyUnsafeApp` |
| [Automatic Data Collection](https://noverse.dev/policies?p=WebThreatDefense*AutomaticDataCollection) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `CaptureThreatWindow` |
| [Configure detection for potentially unwanted applications](https://noverse.dev/policies?p=WindowsDefender*Root_PUAProtection) | `HKLM\Software\Policies\Microsoft\Windows Defender` | `PUAProtection` |
| [Turn on behavior monitoring](https://noverse.dev/policies?p=WindowsDefender*RealtimeProtection_DisableBehaviorMonitoring) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableBehaviorMonitoring` |
| [Scan all downloaded files and attachments](https://noverse.dev/policies?p=WindowsDefender*RealtimeProtection_DisableIOAVProtection) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableIOAVProtection` |
| [Monitor file and program activity on your computer](https://noverse.dev/policies?p=WindowsDefender*RealtimeProtection_DisableOnAccessProtection) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableOnAccessProtection` |
| [Turn off real-time protection](https://noverse.dev/policies?p=WindowsDefender*DisableRealtimeMonitoring) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableRealtimeMonitoring` |
| [Turn on process scanning whenever real-time protection is enabled](https://noverse.dev/policies?p=WindowsDefender*RealtimeProtection_DisableScanOnRealtimeEnable) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableScanOnRealtimeEnable` |
| [Configure Watson events](https://noverse.dev/policies?p=WindowsDefender*Reporting_DisablegenericrePorts) | `HKLM\Software\Policies\Microsoft\Windows Defender\Reporting` | `DisableGenericRePorts` |
| [Turn off enhanced notifications](https://noverse.dev/policies?p=WindowsDefender*Reporting_DisableEnhancedNotifications) | `HKLM\Software\Policies\Microsoft\Windows Defender\Reporting` | `DisableEnhancedNotifications` |
| [Turn on e-mail scanning](https://noverse.dev/policies?p=WindowsDefender*Scan_DisableEmailScanning) | `HKLM\Software\Policies\Microsoft\Windows Defender\Scan` | `DisableEmailScanning` |
| [This settings controls whether Network Protection is allowed to be configured into block or audit mode on Windows Server.](https://noverse.dev/policies?p=WindowsDefender*AllowNetworkProtectionOnWinServer) | `HKLM\Software\Policies\Microsoft\Windows Defender\Windows Defender Exploit Guard\Network Protection` | `AllowNetworkProtectionOnWinServer` |
| [Allow notifications to disable security intelligence based reports to Microsoft MAPS](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_SignatureDisableNotification) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `SignatureDisableNotification` |
| [Configure the 'Block at First Sight' feature](https://noverse.dev/policies?p=WindowsDefender*DisableBlockAtFirstSeen) | `HKLM\Software\Policies\Microsoft\Windows Defender\Spynet` | `DisableBlockAtFirstSeen` |
| [Configure local setting override for reporting to Microsoft MAPS](https://noverse.dev/policies?p=WindowsDefender*Spynet_LocalSettingOverrideSpynetReporting) | `HKLM\Software\Policies\Microsoft\Windows Defender\Spynet` | `LocalSettingOverrideSpynetReporting` |
| [Join Microsoft MAPS](https://noverse.dev/policies?p=WindowsDefender*SpynetReporting) | `HKLM\Software\Policies\Microsoft\Windows Defender\Spynet` | `SpynetReporting` |
| [Send file samples when further analysis is required](https://noverse.dev/policies?p=WindowsDefender*SubmitSamplesConsent) | `HKLM\Software\Policies\Microsoft\Windows Defender\Spynet` | `SubmitSamplesConsent` |
| [Select cloud protection level](https://noverse.dev/policies?p=WindowsDefender*MpEngine_MpCloudBlockLevel) | `HKLM\Software\Policies\Microsoft\Windows Defender\MpEngine` | `MpCloudBlockLevel` |
| [Configure extended cloud check](https://noverse.dev/policies?p=WindowsDefender*MpEngine_MpBafsExtendedTimeout) | `HKLM\Software\Policies\Microsoft\Windows Defender\MpEngine` | `MpBafsExtendedTimeout` |
| [Prevent users and apps from accessing dangerous websites](https://noverse.dev/policies?p=WindowsDefender*ExploitGuard_EnableNetworkProtection) | `HKLM\Software\Policies\Microsoft\Windows Defender\Windows Defender Exploit Guard\Network Protection` | `EnableNetworkProtection` |
| [Configure Controlled folder access](https://noverse.dev/policies?p=WindowsDefender*ExploitGuard_ControlledFolderAccess_EnableControlledFolderAccess) | `HKLM\Software\Policies\Microsoft\Windows Defender\Windows Defender Exploit Guard\Controlled Folder Access` | `EnableControlledFolderAccess` |
| [Hide all notifications](https://noverse.dev/policies?p=WindowsDefenderSecurityCenter*Notifications_DisableNotifications) | `HKLM\SOFTWARE\Policies\Microsoft\Windows Defender Security Center\Notifications` | `DisableNotifications` |
| [Hide non-critical notifications](https://noverse.dev/policies?p=WindowsDefenderSecurityCenter*Notifications_DisableEnhancedNotifications) | `HKLM\SOFTWARE\Policies\Microsoft\Windows Defender Security Center\Notifications` | `DisableEnhancedNotifications` |
| [Configure Windows Defender SmartScreen](https://noverse.dev/policies?p=WindowsExplorer*EnableSmartScreen) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableSmartScreen`<br>`ShellSmartScreenLevel` |
| [Turn off Microsoft Defender Antivirus](https://noverse.dev/policies?p=WindowsDefender*DisableAntiSpywareDefender) | `HKLM\SOFTWARE\Policies\Microsoft\Windows Defender` | `DisableAntiSpyware` |

## Remove Defender from Image

If you want to completely remove Windows Defender for a specific reason, use DISM.

Obviously, you need to change the `mount` path before running it.

```powershell
@echo off
setlocal

set "mount=%userprofile%\Desktop\DISMT\mount"

MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSystray.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthService.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthAgent.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthHost.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSSO.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSsoUdk.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthCore.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthProxyStub.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthUdk.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\drivers\WdNisDrv.sys"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Windows\System32\SecurityHealth"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files\Windows Defender Advanced Threat Protection"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files (x86)\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Defender Advanced Threat Protection"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Security Health"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\smartscreen.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\smartscreenps.dll"

endlocal
```

### Task Leftovers

You can remove task leftovers after installation or in the `oobeSystem` phase with:
```batch
powershell -command "Get-ScheduledTask -TaskPath '\Microsoft\Windows\Windows Defender\' | Unregister-ScheduledTask -Confirm:$false"
reg delete "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\TaskCache\Tree\Microsoft\Windows\Windows Defender" /f
rmdir /s /q "%windir%\System32\Tasks\Microsoft\Windows\Windows Defender"
```

## Windows Security Captures

```c
// Real-time protection - 0 = On, 1 = Off
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableRealtimeMonitoring	Type: REG_DWORD

// Dev Drive protection - 0 = On, 1 = Off
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableAsyncScanOnOpen	Type: REG_DWORD

// Cloud-delivered protection - 0 = Off, 2 = On
HKLM\SOFTWARE\Microsoft\Windows Defender\Spynet\SpyNetReporting	Type: REG_DWORD

// Automatic sample submission - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows Defender\Spynet\SubmitSamplesConsent	Type: REG_DWORD

// Tamper Protection
// Off
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TamperProtection	Type: REG_DWORD, Length: 4, Data: 4	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TamperProtectionSource	Type: REG_DWORD, Length: 4, Data: 2	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TPExclusions	Type: REG_DWORD, Length: 4, Data: 0	RegSetValue
// On
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TamperProtection	Type: REG_DWORD, Length: 4, Data: 5	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TamperProtectionSource	Type: REG_DWORD, Length: 4, Data: 2	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\TPExclusions	Type: REG_DWORD, Length: 4, Data: 0	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Device Control\WddState	Type: REG_DWORD, Length: 4, Data: 1	RegSetValue
HKLM\SOFTWARE\Microsoft\Windows Defender\DisableRoutinelyTakingAction		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\MpEngine\DisableScriptScanning		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableBehaviorMonitoring		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableEarlyLaunchAntimalware		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableIntrusionPreventionSystem		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableIOAVProtection		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableOnAccessProtection		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableRealtimeMonitoring		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableScanOnRealtimeEnable		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Real-Time Protection\DisableScriptScanning		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Reporting\DisableEnhancedNotifications		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Scan\DisableArchiveScanning		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Threats\ThreatSeverityDefaultAction\1		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Threats\ThreatSeverityDefaultAction\2		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Threats\ThreatSeverityDefaultAction\4		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\Threats\ThreatSeverityDefaultAction\5		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\UX Configuration\DisablePrivacyMode		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\UX Configuration\Notification_Suppress		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\UX Configuration\SuppressRebootNotification		RegDeleteValue
HKLM\SOFTWARE\Microsoft\Windows Defender\UX Configuration\SuppressWdoNotification		RegDeleteValue

// Controlled folder access - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows Defender\Windows Defender Exploit Guard\Controlled Folder Access\EnableControlledFolderAccess	Type: REG_DWORD

// Dynamic lock - 0 = Off, 1 = On
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD

// Check apps and files, "Off" = Off, "Warn" = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\SmartScreenEnabled	Type: REG_SZ

// SmartScreen for Microsoft Edge - 0 = Off, 1 = On
HKCU\Software\Microsoft\Edge\SmartScreenEnabled\(Default)	Type: REG_DWORD

// Phishing Protection - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WTDS\Components\ServiceEnabled	Type: REG_DWORD

// Warn me about malicious apps and sites - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WTDS\Components\NotifyMalicious	Type: REG_DWORD

// Warn me about password reuse - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WTDS\Components\NotifyPasswordReuse	Type: REG_DWORD


// Warn me about unsafe password storage - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WTDS\Components\NotifyUnsafeApp	Type: REG_DWORD

// Automatically collect website or app content when additional analysis is needed to help identify security threats - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WTDS\Components\CaptureThreatWindow	Type: REG_DWORD

// Potentially unwanted app blocking - 0 = Off, 1 = On
HKLM\SOFTWARE\Microsoft\Windows Defender\PUAProtection	Type: REG_DWORD
HKCU\Software\Microsoft\Edge\SmartScreenPuaEnabled\(Default)	Type: REG_DWORD
HKLM\SOFTWARE\Microsoft\Windows Defender\PUAProtection	Type: REG_DWORD
HKCU\Software\Microsoft\Edge\SmartScreenPuaEnabled\(Default)	Type: REG_DWORD

// SmartScreen for Microsoft Store apps - 0 = Off, 1 = On (PreventOverride = 0 for both)
HKCU\Software\Microsoft\Windows\CurrentVersion\AppHost\EnableWebContentEvaluation	Type: REG_DWORD
//HKCU\Software\Microsoft\Windows\CurrentVersion\AppHost\PreventOverride	Type: REG_DWORD

// Local Security Authority protection - 0 = Off, 2 = On
HKLM\System\CurrentControlSet\Control\Lsa\RunAsPPL	Type: REG_DWORD

// Microsoft Vulnerable Driver Blocklist - 0 = Off, 1 = On
HKLM\System\CurrentControlSet\Control\CI\Config\VulnerableDriverBlocklistEnable	Type: REG_DWORD

//  --- Miscellaneous MpPreference Records ---

// Set-MpPreference -DisableCoreServiceTelemetry $true
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\DisableCoreService1DSTelemetry	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\Microsoft\Windows Defender\CoreService\DisableCoreService1DSTelemetry	Type: REG_DWORD, Length: 4, Data: 1

// Set-MpPreference -DisableCoreServiceTelemetry $false
HKLM\SOFTWARE\Microsoft\Windows Defender\Features\DisableCoreService1DSTelemetry	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\Microsoft\Windows Defender\CoreService\DisableCoreService1DSTelemetry	Type: REG_DWORD, Length: 4, Data: 0
```

# Windows Update

| Option | Description |
| ---- | ---- |
| `Disable WU` | Stops normal Windows Update scanning, download, install, and orchestrated update activity. |
| `Enable WU` | Restores normal update behavior for the controls managed in this section. |
| `Security Only` | Keeps monthly Windows quality and security servicing for the current release while blocking feature upgrades, WU driver updates, optional content, CFR rollouts, preview content, Microsoft product updates, and MRT through Windows Update. |

## Suboptions

| Suboption | Description |
| ---- | ---- |
| `Disable Feature Updates` | Keeps the device on its current Windows release while quality updates continue. New Windows releases are not offered until removed. |
| `Disable Quality Updates (35D)` | Temporarily pauses monthly cumulative updates, including security fixes. Security fixes stop until the pause is cleared or expires. |
| `Disable WU Driver Updates` | Blocks Windows Update from installing driver-class updates. Hardware fixes and newer vendor drivers are not delivered through Windows Update. |
| `Disable Microsoft Product Updates` | Stops updates for other Microsoft products through this channel. Office and other Microsoft apps stop receiving updates from Windows Update. |
| `Disable Optional Updates` | Hides optional update content from normal servicing. Optional fixes and non-essential improvements are not offered. |
| `Disable CFR Features` | Stops gradual rollout features delivered through servicing. New feature rollouts arrive later or only through full releases. |
| `Disable Preview Builds` | Prevents preview and Insider-style update content. Pre-release Windows builds and preview tracks are unavailable. |
| `Disable Store App Updates` | Stops automatic Microsoft Store app updates. Store apps stop receiving background fixes and feature updates. |
| `Disable Device Metadata Retrieval` | Stops automatic retrieval of device metadata from Microsoft. Device names, icons, and related suggestions may be less complete. |
| `Disable Automatic Root Certificate Updates` | Stops automatic refresh of trusted root certificates. Some secure sites, apps, or signed content can fail until trust is updated another way. |
| `Disable Defender Definition Updates` | Stops Defender definition updates from this update path. Malware detection ages quickly unless another definition source is provided. |
| `Block MRT via WU` | Stops the MRT (Malicious Software Removal Tool) from being offered through Windows Update. MRT scans and related reporting are unavailable from this channel. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Specify search order for device driver source locations](https://noverse.dev/policies?p=DeviceSetup*DriverSearchPlaces_SearchOrderConfiguration) | `HKLM\Software\Policies\Microsoft\Windows\DriverSearching` | `SearchOrderConfig` |
| [Prevent automatic download of applications associated with device metadata](https://noverse.dev/policies?p=DeviceSetup*DeviceMetadata_PreventDeviceMetadataFromNetwork) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Device Metadata` | `PreventDeviceMetadataFromNetwork` |
| [Turn off Automatic Root Certificates Update](https://noverse.dev/policies?p=ICM*CertMgr_DisableAutoRootUpdates) | `HKLM\Software\Policies\Microsoft\SystemCertificates\AuthRoot` | `DisableRootAutoUpdate` |
| [Turn off Windows Update device driver searching](https://noverse.dev/policies?p=ICM*DriverSearchPlaces_DontSearchWindowsUpdate) | `HKLM\Software\Policies\Microsoft\Windows\DriverSearching` | `DontSearchWindowsUpdate` |
| [Turn off access to all Windows Update features](https://noverse.dev/policies?p=ICM*RemoveWindowsUpdate_ICM) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DisableWindowsUpdateAccess` |
| [Define file shares for downloading security intelligence updates](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_DefinitionUpdateFileSharesSources) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `DefinitionUpdateFileSharesSources` |
| [Define the order of sources for downloading security intelligence updates](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_FallbackOrder) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `FallbackOrder` |
| [Turn off Automatic Download and Install of updates](https://noverse.dev/policies?p=WindowsStore*DisableAutoInstall) | `HKLM\Software\Policies\Microsoft\WindowsStore` | `AutoDownload` |
| [Turn off Automatic Download of updates on Win8 machines](https://noverse.dev/policies?p=WindowsStore*DisableAutoDownloadWin8) | `HKLM\Software\Policies\Microsoft\WindowsStore` | `AutoDownload` |
| [Configure Automatic Updates](https://noverse.dev/policies?p=WindowsUpdate*AutoUpdateCfg) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate\AU` | `NoAutoUpdate`<br>`AUOptions`<br>`AutomaticMaintenanceEnabled`<br>`ScheduledInstallDay`<br>`ScheduledInstallTime`<br>`AllowMUUpdateService`<br>`ScheduledInstallEveryWeek`<br>`ScheduledInstallFirstWeek`<br>`ScheduledInstallSecondWeek`<br>`ScheduledInstallThirdWeek`<br>`ScheduledInstallFourthWeek` |
| [Specify intranet Microsoft update service location](https://noverse.dev/policies?p=WindowsUpdate*CorpWuURL) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate`<br>`HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsUpdate\AU` | `WUServer`<br>`WUStatusServer`<br>`UpdateServiceUrlAlternate`<br>`FillEmptyContentUrls`<br>`DoNotEnforceEnterpriseTLSCertPinningForUpdateDetection`<br>`SetProxyBehaviorForUpdateDetection`<br>`UseWUServer` |
| [Do not connect to any Windows Update Internet locations](https://noverse.dev/policies?p=WindowsUpdate*DoNotConnectToWindowsUpdateInternetLocations) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DoNotConnectToWindowsUpdateInternetLocations` |
| [Select the target Feature Update version](https://noverse.dev/policies?p=WindowsUpdate*TargetReleaseVersion) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `TargetReleaseVersion`<br>`ProductVersion`<br>`TargetReleaseVersionInfo` |
| [Manage preview builds](https://noverse.dev/policies?p=WindowsUpdate*ManagePreviewBuilds) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `ManagePreviewBuildsPolicyValue`<br>`BranchReadinessLevel` |
| [Select when Quality Updates are received](https://noverse.dev/policies?p=WindowsUpdate*DeferQualityUpdates) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DeferQualityUpdates`<br>`DeferQualityUpdatesPeriodInDays`<br>`PauseQualityUpdatesStartTime` |
| [Do not include drivers with Windows Updates](https://noverse.dev/policies?p=WindowsUpdate*ExcludeWUDriversInQualityUpdate) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `ExcludeWUDriversInQualityUpdate` |
| [Remove access to use all Windows Update features](https://noverse.dev/policies?p=WindowsUpdate*DisableUXWUAccess) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetDisableUXWUAccess` |
| [Remove access to "Pause updates" feature](https://noverse.dev/policies?p=WindowsUpdate*DisablePauseUXAccess) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetDisablePauseUXAccess` |
| [Enable features introduced via servicing that are off by default](https://noverse.dev/policies?p=WindowsUpdate*AllowTemporaryEnterpriseFeatureControl) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `AllowTemporaryEnterpriseFeatureControl` |
| [Enable optional updates](https://noverse.dev/policies?p=WindowsUpdate*AllowOptionalContent) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetAllowOptionalContent`<br>`AllowOptionalContent` |

# UAC

Disabling UAC stops the prompts for administrative permissions, allowing programs and processes to run with elevated rights without user confirmation.

> *User Account Control (UAC) is meant to enable users to run with standard user rights as opposed to administrative rights. Without administrative rights, users cannot accidentally (or deliberately) modify system settings, malware can't normally alter system security settings or disable antivirus software, and users can't compromise the sensitive information of other users on shared computers. Running with standard user rights can thus mitigate the impact of malware and protect sensitive data on shared computers.*
> *UAC runs most apps with standard user rights and uses a filtered admin token for administrators, elevating only when needed. Disabling UAC removes this filtered-token model and disables UAC file/registry virtualization (Luafv.sys).*"
>
> — Windows Internals, [E7, P1: 'UAC'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/security/images/uac-registry-values.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/security/images/uac-options.png?raw=true)

## [Registry Values](https://learn.microsoft.com/en-us/windows/security/application-security/application-control/user-account-control/settings-and-configuration?tabs=reg)

All of them are under `HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System`.

### FilterAdministratorToken

Admin Approval Mode for the built-in Administrator account.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | The built-in Administrator account uses Admin Approval Mode. By default, any operation that requires elevation of privilege prompts the user to prove the operation. |
| `0x00000000` (`Disabled`) | The built-in Administrator account runs all applications with full administrative privilege (default). |

### EnableUIADesktopToggle

Allow UIAccess applications to prompt for elevation without using the secure desktop.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | UIA programs, including Remote Assistance, automatically disable the secure desktop for elevation prompts. If you don't disable the **Switch to the secure desktop when prompting for elevation** policy setting, the prompts appear on the interactive user's desktop instead of the secure desktop. This setting allows the remote administrator to provide the appropriate credentials for elevation. This policy setting doesn't change the behavior of the UAC elevation prompt for administrators. If you plan to enable this policy setting, you should also review the effect of the **Behavior of the elevation prompt for standard users** policy setting; if configured as **Automatically deny elevation requests**, elevation requests aren't presented to the user. |
| `0x00000000` (`Disabled`) | The secure desktop can be disabled only by the user of the interactive desktop or by disabling the **Switch to the secure desktop when prompting for elevation** policy setting (default). |

### ConsentPromptBehaviorAdmin

Behavior of the elevation prompt for administrators in Admin Approval Mode.

| Value | Meaning |
| --- | --- |
| `0x00000000` (`Elevate without prompting`) | Allows privileged accounts to perform an operation that requires elevation without requiring consent or credentials. Use this option only in the most constrained environments. |
| `0x00000001` (`Prompt for credentials on the secure desktop`) | When an operation requires elevation of privilege, the user is prompted on the secure desktop to enter a privileged user name and password. If the user enters valid credentials, the operation continues with the user's highest available privilege. |
| `0x00000002` (`Prompt for consent on the secure desktop`) | When an operation requires elevation of privilege, the user is prompted on the secure desktop to select either Permit or Deny. If the user selects Permit, the operation continues with the user's highest available privilege. |
| `0x00000003` (`Prompt for credentials`) | When an operation requires elevation of privilege, the user is prompted to enter an administrative user name and password. If the user enters valid credentials, the operation continues with the applicable privilege. |
| `0x00000004` (`Prompt for consent`) | When an operation requires elevation of privilege, the user is prompted to select either Permit or Deny. If the user selects Permit, the operation continues with the user's highest available privilege. |
| `0x00000005` (`Prompt for consent for non-Windows binaries`) | When an operation for a non-Microsoft application requires elevation of privilege, the user is prompted on the secure desktop to select either Permit or Deny. If the user selects Permit, the operation continues with the user's highest available privilege (default). |

### ConsentPromptBehaviorUser

Behavior of the elevation prompt for standard users.

| Value | Meaning |
| --- | --- |
| `0x00000000` (`Automatically deny elevation requests`) | When an operation requires elevation of privilege, a configurable access denied error message is displayed. An enterprise that is running desktops as standard user might choose this setting to reduce help desk calls. |
| `0x00000001` (`Prompt for credentials on the secure desktop`) | When an operation requires elevation of privilege, the user is prompted on the secure desktop to enter a different user name and password. If the user enters valid credentials, the operation continues with the applicable privilege. |
| `0x00000003` (`Prompt for credentials`) | When an operation requires elevation of privilege, the user is prompted to enter an administrative user name and password. If the user enters valid credentials, the operation continues with the applicable privilege (default). |

### EnableInstallerDetection

Detect application installations and prompt for elevation.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | When an app installation package is detected that requires elevation of privilege, the user is prompted to enter an administrative user name and password. If the user enters valid credentials, the operation continues with the applicable privilege (default for home edition only). |
| `0x00000000` (`Disabled`) | App installation packages aren't detected and prompted for elevation. Enterprises that are running standard user desktops and use delegated installation technologies, such as Microsoft Intune, should disable this policy setting. In this case, installer detection is unnecessary (default). |

### ValidateAdminCodeSignatures

Only elevate executables that are signed and validated.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | Enforces the certificate certification path validation for a given executable file before it's permitted to run. |
| `0x00000000` (`Disabled`) | Doesn't enforce the certificate certification path validation before a given executable file is permitted to run (default). |

### EnableSecureUIAPaths

Only elevate UIAccess applications that are installed in secure locations.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | If an app resides in a secure location in the file system, it runs only with UIAccess integrity (default). |
| `0x00000000` (`Disabled`) | An app runs with UIAccess integrity even if it doesn't reside in a secure location in the file system. |

### EnableLUA

Run all administrators in Admin Approval Mode.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | Admin Approval Mode is enabled. This policy must be enabled and related UAC settings configured. The policy allows the built-in Administrator account and members of the Administrators group to run in Admin Approval Mode (default). |
| `0x00000000` (`Disabled`) | Admin Approval Mode and all related UAC policy settings are disabled. If this policy setting is disabled, Windows Security notifies you that the overall security of the operating system is reduced. |

### PromptOnSecureDesktop

Switch to the secure desktop when prompting for elevation.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | All elevation requests go to the secure desktop regardless of prompt behavior policy settings for administrators and standard users (default). |
| `0x00000000` (`Disabled`) | All elevation requests go to the interactive user's desktop. Prompt behavior policy settings for administrators and standard users are used. |

### EnableVirtualization

Virtualize file and registry write failures to per-user locations.

| Value | Meaning |
| --- | --- |
| `0x00000001` (`Enabled`) | App write failures are redirected at run time to defined user locations for both the file system and registry (default). |
| `0x00000000` (`Disabled`) | Apps that write data to protected locations fail. |

# PS Execution Policy

> "*PowerShell execution policy is a safety feature that controls when PowerShell loads configuration files and runs scripts, helping prevent accidental execution of malicious scripts.*
>
> *On Windows, you can set it for the local computer, current user, a single session, or through Group Policy. Local computer and current user policies are stored in PowerShell configuration files, while session policy exists only in memory until the session closes.*
>
> *It is not a real security boundary, since users can bypass it, but it helps enforce basic rules and avoid accidental misuse.*
>
> *On non-Windows systems, the reported default is `Unrestricted` and cannot be changed, though the actual behavior is closer to `Bypass` because Windows security zones do not exist there.*"
>
> — Microsoft, [about_Execution_Policies](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5)

### [Execution Policy](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5)

| **Execution Policy**  | **Description** |
| ---- | ---- |
| `AllSigned` | All scripts must be signed by a trusted publisher. Prompts for untrusted publishers. |
| `Bypass` | No prompts or restrictions. Used in apps or environments with their own security. |
| `Default` | Acts like `RemoteSigned` on Windows. |
| `RemoteSigned` | Scripts run freely unless downloaded from the internet. Internet scripts need a trusted signature or must be unblocked. Local scripts don't require signatures. |
| `Restricted` | No scripts allowed (only individual commands). Blocks all `.ps1`, `.psm1`, `.ps1xml`, and profile scripts. |
| `Undefined` | No policy in this scope. If all scopes are undefined, defaults to `Restricted` (clients) or `RemoteSigned` (servers). |
| `Unrestricted` | Unsigned scripts can run. Prompts for scripts from outside the intranet zone. |

### Scope

| **Scope** | **Description** |
|---- | ---- |
| `MachinePolicy` | Set by a Group Policy for all users of the computer |
| `UserPolicy` | Set by a Group Policy for the current user of the computer |
| `Process` | Sets the execution policy only for the current session - stored in an environment variable & removed when the session ends |
| `CurrentUser` | The execution policy affects only the current user - stored in the HKCU subkey |
| `LocalMachine` | The execution policy affects all users on the current computer - stored in the HKLM subkey |

### [Registry Values](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_powershell_config?view=powershell-7.5)

| **Value Name** | **Description** |
| ---- | ---- |
| `EnableScriptBlockLogging` | Enables or disables logging of PowerShell script input to the event log. If enabled, it logs the processing of commands, script blocks, functions, and scripts. |
| `EnableScriptBlockInvocationLogging` | Enables or disables logging of invocation events for commands, script blocks, functions, or scripts. Enabling this generates high volume of event logs for start/stop events. |
| `EnableModuleLogging` | Enables or disables logging of pipeline execution events for specified PowerShell modules. If enabled, logs events in Event Viewer for the specified modules. |
| `EnableTranscripting` | Enables or disables transcription of PowerShell commands. If enabled, records the input and output of PowerShell commands into text-based transcripts stored by default in My Documents. |
| `EnableScripts` | Controls which types of scripts are allowed to run on the system. Options include allowing only signed scripts, allowing local scripts and remote signed scripts, or allowing all scripts to run. |

See your current execution policies via:
```powershell
Get-ExecutionPolicy -List
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn on Script Execution](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableScripts) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell` | `EnableScripts`<br>`ExecutionPolicy` |
| [Turn on Module Logging](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableModuleLogging) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\ModuleLogging`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\ModuleLogging` | `EnableModuleLogging` |
| [Turn on PowerShell Transcription](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableTranscripting) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\Transcription`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\Transcription` | `EnableTranscripting`<br>`OutputDirectory`<br>`EnableInvocationHeader` |
| [Turn on PowerShell Script Block Logging](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableScriptBlockLogging) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\ScriptBlockLogging`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\ScriptBlockLogging` | `EnableScriptBlockLogging`<br>`EnableScriptBlockInvocationLogging` |

# Process Mitigations

Process mitigations are system or per process exploit protections for common memory corruption & control flow attack classes. These can improve exploit resistance, but some mitigations can break older software, drivers, game anti-cheat components, launchers, or injected overlays. The mitigation tables in the sections are copied from [Windows Internals E7 P1](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf), 'Exploit mitigations'.

The option currently includes the [system-level mitigations](https://learn.microsoft.com/en-us/defender-endpoint/customize-exploit-protection#exploit-protection-mitigations).

These options are stored system wide in:
```ini
HKLM\System\CurrentControlSet\Control\Session Manager\kernel\MitigationOptions ; REG_BINARY, 24 bytes
HKLM\System\CurrentControlSet\Control\Session Manager\kernel\MitigationAuditOptions ; REG_BINARY, 24 bytes
```

The relevant 4 bit field uses `0` = default/not configured, `1` = force on, and `2` = force off.

| Option | [PS reference](https://learn.microsoft.com/en-us/defender-endpoint/customize-exploit-protection#powershell-reference-table) | `MitigationOptions` field | Enable bytes | Disable bytes |
| --- | --- | --- | --- | --- |
| DEP | `DEP`, `EmulateAtlThunks` | byte `0`, low 4 bits | `01 00 00 XX` | `02 00 00 XX` |
| SEHOP | `SEHOP`, `SEHOPTelemetry` | byte `0`, high 4 bits | `10 00 00 XX` | `20 00 00 XX` |
| Validate heap integrity | `TerminateOnError` | byte `1`, high 4 bits | `00 10 00 XX` | `00 20 00 XX` |
| Mandatory ASLR | `ForceRelocateImages` | byte `1`, low 4 bits | `00 01 00 XX` | `00 02 00 XX` |
| Bottom-up ASLR | `BottomUp`, `HighEntropy` | byte `2`, low 4 bits | `00 00 01 XX` | `00 00 02 XX` |
| High-entropy ASLR | `HighEntropy` suboption of Bottom-up ASLR | byte `2`, high 4 bits | `00 00 10 XX` | `00 00 20 XX` |
| CFG | `CFG`, `StrictCFG`, `SuppressExports` | byte `5` low 4 bits, byte `9` low 4 bits | `XX XX XX XX XX 01 XX XX XX 01` | `XX XX XX XX XX 02 XX XX XX 02` |

## CFG

> "*validating the target of any indirect `CALL` or `JMP` instruction against a list of valid expected target functions*"
>
> — Windows Internals, [E7, P1: 'Exploit mitigations'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| Control Flow Guard (CFG) | Validates indirect `CALL` and `JMP` targets against expected valid functions, which helps stop control-flow hijacking after memory corruption. | Requires binaries compiled and linked with `/guard:cf`, or can be requested with the CFG process-creation mitigation flag for loaded images. |
| CFG Strict Mode | Blocks libraries that were not linked with `/guard:cf` from loading into the process. | Set through `SetProcessMitigationPolicy` or the strict CFG process-creation mitigation flag. |

## DEP

> "*Marking memory regions as non-executable means that code cannot be run from that region of memory*"
>
> — Microsoft, [Data Execution Prevention](https://learn.microsoft.com/en-us/windows/win32/memory/data-execution-prevention)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| DEP: Permanent | Prevents a process from disabling DEP for itself. It mainly applies to x86 and WoW64 processes. | Set through `SetProcessMitigationPolicy`, a process-creation attribute, or `SetProcessDEPPolicy`. |
| DEP: Disable ATL Thunk Emulation | Prevents legacy ATL thunk code from executing in heap memory, even where compatibility handling would otherwise allow it. | Set through `SetProcessMitigationPolicy`, a process-creation attribute, or `SetProcessDEPPolicy`. |

## Mandatory ASLR

> "*forces a rebase of all DLLs within the process*"
>
> "*this rebasing has no entropy, and can therefore be placed at a predictable location in memory*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| ASLR Force Relocate Images | Forces rebasing for images that were not linked with `/DYNAMICBASE`. | Set through `SetProcessMitigationPolicy` or the force-relocate process-creation mitigation flag. |
| ASLR Disallow Stripped Images | Blocks libraries without relocation data when forced relocation is required. | Set through `SetProcessMitigationPolicy` or the force-relocate and require-relocations mitigation flag. |

## Bottom-up ASLR

> "*adds entropy to relocations, so their location is randomized and therefore less predictable*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| ASLR Bottom Up Randomization | Randomizes bottom-up allocations such as `VirtualAlloc` and stack bases. | Set with the bottom-up ASLR process-creation mitigation flag. |

## High-entropy ASLR

> "*adds 24 bits of entropy (1 TB of variance) into the bottom-up allocation for 64-bit applications*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| High Entropy ASLR (HEASLR) | Adds much more address-space entropy for supported 64-bit images. | Requires `/HIGHENTROPYVA` at link time or the high-entropy ASLR process-creation mitigation flag. |

## SEHOP

> "*validates the SEH chain when an exception is invoked*"
>
> "*No exception handler pointers are pointing to the stack... The exception chain ends at a known final exception handler*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| SEH Overwrite Protection (SEHOP) | Validates structured exception handler chains so overwritten handlers cannot redirect exception dispatch. It mainly applies to 32-bit and WoW64 processes. | Set through `SetProcessDEPPolicy` or the SEHOP process-creation mitigation flag. |

## Validate Heap Integrity

> "*causing the application to terminate if a heap corruption is detected*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

| Mitigation | Use case | Enabling mechanism |
| --- | --- | --- |
| Heap Terminate On Corruption | Terminates the process on heap corruption instead of allowing a continuable heap exception path. This reduces exploit reliability for heap corruption bugs. | Set through `HeapSetInformation` or the heap terminate process-creation mitigation flag. |

### FTH

Used for preventing legacy or unstable applications from crashing, read through the picture below for more detailed information ([`Windows Internals 7th Edition, Part 1, Page 347`](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)).

In [Exploit Protection](https://learn.microsoft.com/en-us/defender-endpoint/customize-exploit-protection#powershell-reference-table) you can see the `Heap` mitigation with `TerminateOnError`, Windows Internals names the same heap termination behavior `Heap Terminate On Corruption`, so the FTH note below refers to that.

> "*causing the application to terminate if a heap corruption is detected*"
>
> — Microsoft, [Exploit protection reference](https://learn.microsoft.com/en-us/defender-endpoint/exploit-protection-reference)

> "*disables the Fault Tolerant Heap (FTH)... by terminating the process instead*"
>
> — Windows Internals, [E7, P1: 'Exploit mitigations'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

#### [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/fth.png?raw=true)

[YouTube Video](https://www.youtube.com/watch?v=4SvNNXAwoqE).

## ProcessMitigation ValidValues

`(gcm set-processmitigation).Parameters.Disable.Attributes.ValidValues`:
```powershell
DEP
EmulateAtlThunks
ForceRelocateImages
RequireInfo
BottomUp
HighEntropy
StrictHandle
DisableWin32kSystemCalls
AuditSystemCall
DisableExtensionPoints
DisableFsctlSystemCalls
AuditFsctlSystemCall
BlockDynamicCode
AllowThreadsToOptOut
AuditDynamicCode
CFG
SuppressExports
StrictCFG
MicrosoftSignedOnly
AllowStoreSignedBinaries
AuditMicrosoftSigned
AuditStoreSigned
EnforceModuleDependencySigning
DisableNonSystemFonts
AuditFont
BlockRemoteImageLoads
BlockLowLabelImageLoads
PreferSystem32
AuditRemoteImageLoads
AuditLowLabelImageLoads
AuditPreferSystem32
EnableExportAddressFilter
AuditEnableExportAddressFilter
EnableExportAddressFilterPlus
AuditEnableExportAddressFilterPlus
EnableImportAddressFilter
AuditEnableImportAddressFilter
EnableRopStackPivot
AuditEnableRopStackPivot
EnableRopCallerCheck
AuditEnableRopCallerCheck
EnableRopSimExec
AuditEnableRopSimExec
SEHOP
AuditSEHOP
SEHOPTelemetry
TerminateOnError
DisallowChildProcessCreation
AuditChildProcess
UserShadowStack
UserShadowStackStrictMode
AuditUserShadowStack
```

# Disable WPBT

The only binary which includes that value string is `smss.exe` (session manager):

```powershell
$ rg -i 'DisableWpbtExecution' strings.txt
20896236:C:\Windows\system32/smss.exe,(0x1fff0,0x20016),DisableWpbtExecution
```

WPBT = Windows Platform Binary Table, which is an ACPI firmware table that can provide a boot time executable to run, many vendors like ASUS use that.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "DisableWpbtExecution" = 0; // REG_DWORD (bool), nonzero disables WPBT execution
```

```asm
; SmpRegistryConfigurationTable

.data:000000014002A490 dq offset SmpQueryWpbtExecutionPolicy
.data:000000014002A498 dq 0
.data:000000014002A4A0 dq offset aDisablewpbtexe ; "DisableWpbtExecution"
.data:000000014002A4A8 dq 0
.data:000000014002A4B0 dq 4 ; REG_DWORD
.data:000000014002A4B8 dq 0 ; DefaultData = NULL
.data:000000014002A4C0 dq 0 ; DefaultLength = 0
```

## SmpDisableWpbtExecution

The type must be `REG_DWORD` with a length of `4`, and any nonzero would set `SmpDisableWpbtExecution`:

```c
__int64 __fastcall SmpQueryWpbtExecutionPolicy(__int64 a1, int a2, _DWORD *a3, int a4)
{
  bool v4; // al

  v4 = a4 == 4 && a2 == 4 && *a3 != 0; // length == 4, type == REG_DWORD, data != 0
  SmpDisableWpbtExecution = v4;
  return 0LL;
}
```

Whenever that is set, `smss.exe` doesn't call `SmpGetPlatformBinary`, and if a WPBT table exists, it reports status `2`.

```c
// SmpLoadDataFromRegistry

if ( SmpHostSmss )
{
  if ( SmpMiniNTBoot || SmpSafeBootOption != -1 || SmpDisableWpbtExecution )
  {
    PlatformBinary = -1073741823;
    if ( (unsigned __int8)SmpPlatformBinaryTableExists() )
      SmpSendPlatformBinaryStatus(2LL, 0LL, 0LL, 0LL); // WPBT exists, but blocked
  }
  else
  {
    PlatformBinary = SmpGetPlatformBinary(&DestinationString);
  }
}
```

`SmpPlatformBinaryTableExists` reads the ACPI firmware table for `WPBT`.

```c
// SmpPlatformBinaryTableExists

SystemInformation[0] = 1094930505; // ACPI
SystemInformation[1] = 1;
SystemInformation[2] = 1414546007; // WPBT
return NtQuerySystemInformation(SystemFirmwareTableInformation, SystemInformation, 0x14u, &ReturnLength) == -1073741789;
```

## SmpGetPlatformBinary

This would only happen if WPBT is allowed, which is the default behavior (`SmpGetPlatformBinary` builds the command around `wpbbin.exe`):

```c
// SmpGetPlatformBinary

appended = RtlAppendUnicodeToString(Destination, L"wpbbin.exe");
if ( HIDWORD(Size) )
{
  RtlAppendUnicodeToString(Destination, L" ");
  appended = RtlAppendUnicodeToString(Destination, (PCWSTR)Buffer[1]);
}
```

# DMA Remapping

[DMA remapping](https://learn.microsoft.com/en-us/windows-hardware/drivers/pci/enabling-dma-remapping-for-device-drivers) lets PCIe device drivers declare whether they are compatible with IOMMU backed DMA isolation. Windows uses this with [Kernel DMA Protection](https://learn.microsoft.com/en-us/windows/security/hardware-security/kernel-dma-protection-for-thunderbolt) and DMAGuard policy to reduce memory corruption and malicious DMA attack exposure. Devices with DMA remapping compatible drivers can start and perform DMA, incompatible external or exposed PCIe devices can be blocked by DMAGuard policy on systems where Kernel DMA Protection is enabled.

`Opt-In` marks matching existing entries as compatible with DMA remapping. `Opt-Out` marks them as incompatible, which can reduce DMA remapping coverage and can cause external devices to be blocked until sign in or unlock.

`per-device` - recommended and preferred mechanism for Windows 24H2 and later (`RemappingSupported`)
`per-driver` - legacy mechanism for Windows versions up to Windows 11 23H2 (`DmaRemappingCompatible`)

If both are present, the per-device setting takes precedence and `DmaRemappingCompatible` is ignored. The PCI driver documentation still warns that DMA remapping is not supported through this path for graphics drivers. Display drivers use the separate [WDDM IOMMU DMA remapping](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/iommu-dma-remapping) path.

### `RemappingSupported`

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates the device and driver are incompatible with DMA remapping. |
| 1 | Opt-in, indicates the device and driver are fully compatible with DMA remapping. |
| No registry key | Let the system determine the policy. |

### `RemappingFlags`

| Value | Meaning |
|--|--|
| 0 | If **RemappingSupported** is 1, opt in, unconditionally. |
| 1 | If **RemappingSupported** is 1, opt in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt). B. DMA verification is enabled in Driver Verifier |
| No registry key | Same as 0 value. |

### `DmaRemappingCompatible`

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates that your driver is incompatible with DMA remapping. |
| 1 | Opt-in, indicates that your driver is fully compatible with DMA remapping. |
| 2 | Opt-in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt). B. DMA verification is enabled in Driver Verifier |
| 3 | Opt-in. Support was added in Windows 11 and degrades gracefully on Windows 10. |
| No registry key | Let the system determine the policy. |

Example paths:
```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\msisadrv\Parameters : DmaRemappingCompatible
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingFlags
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingSupported
```

# Disable VBS (HVCI)

[VBS](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/oem-vbs) won't work if Hyper-V is disabled. HVCI = hypervisor-protected code integrity.

Hypervisor-Based Code Integrity (HVCI) and Kernel-Mode Code Integrity (KMCI) power `Device Guard`, LSA (Lsass.exe) and isolated LSA (LsaIso.exe) power [`Credential Guard`](https://learn.microsoft.com/en-us/windows/security/identity-protection/credential-guard/).

> "*Virtualization-based security, or VBS, uses hardware virtualization and the Windows hypervisor to create an isolated virtual environment that becomes the root of trust of the OS that assumes the kernel can be compromised. Windows uses this isolated environment to host a number of security solutions, providing them with greatly increased protection from vulnerabilities in the operating system, and preventing the use of malicious exploits which attempt to defeat protections. VBS enforces restrictions to protect vital system and operating system resources, or to protect security assets such as authenticated user credentials.*
>
> *One such example security solution is [memory integrity](https://learn.microsoft.com/en-us/windows/security/hardware-security/enable-virtualization-based-protection-of-code-integrity?tabs=security), which protects and hardens Windows by running kernel mode code integrity within the isolated virtual environment of VBS. Kernel mode code integrity is the Windows process that checks all kernel mode drivers and binaries before they're started, and prevents unsigned or untrusted drivers or system files from being loaded into system memory. Memory integrity also restricts kernel memory allocations that could be used to compromise the system, ensuring that kernel memory pages are only made executable after passing code integrity checks inside the secure runtime environment, and executable pages themselves are never writable. That way, even if there are vulnerabilities like a buffer overflow that allow malware to attempt to modify memory, executable code pages cannot be modified, and modified memory cannot be made executable.*"

## [VBS Requirements](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/oem-vbs)

| Hardware requirement | Details |
| --- | --- |
| 64-bit CPU | Virtualization-based security (VBS) requires the Windows hypervisor, which is only supported on 64-bit IA processors with virtualization extensions, including Intel VT-X and AMD-v. |
| Second Level Address Translation (SLAT) | VBS also requires that the processor's virtualization support includes Second Level Address Translation (SLAT), either Intel VT-X2 with Extended Page Tables (EPT), or AMD-v with Rapid Virtualization Indexing (RVI). |
| IOMMUs or SMMUs (Intel VT-D, AMD-Vi, Arm64 SMMUs) | All I/O devices capable of DMA must be behind an IOMMU or SMMU. An IOMMU can be used to enhance system resiliency against memory attacks. |
| Trusted Platform Module (TPM) 2.0 | For more information, see Trusted Platform Module (TPM) 2.0. |
| Firmware support for SMM protection | System firmware must adhere to the recommendations for hardening SMM code described in the Windows SMM Security Mitigations Table (WSMT) specification. The WSMT specification contains details of an ACPI table that was created for use with Windows operating systems that support VBS features. Firmware must implement the protections described in the WSMT specification, and set the corresponding protection flags as described in the specification to report compliance with these requirements to the operating system. |
| Unified Extensible Firmware Interface (UEFI)<br>Memory Reporting | UEFI firmware must adhere to the following memory map reporting format and memory allocation guidelines in order for firmware to ensure compatibility with VBS.<br><br UEFI v2.6 Memory Attributes Table (MAT) - To ensure compatibility with VBS, firmware must cleanly separate EFI runtime memory ranges for code and data, and report this to the operating system. Proper segregation and reporting of EFI runtime memory ranges allows VBS to apply the necessary page protections to EFI runtime services code pages within the VBS secure region.<br><br>Conveying this information to the OS is accomplished using the EFI_MEMORY_ATTRIBUTES_TABLE. To implement the UEFI MAT, follow these guidelines:<br><br>1. The entire EFI runtime must be described by this table.<br>2. All appropriate attributes for EfiRuntimeServicesData and EfiRuntimeServicesCode pages must be marked.<br>3. These ranges must be aligned on page boundaries (4KB), and can not overlap.<br><br> EFI Page Protections - All entries must include attributes EFI_MEMORY_RO, EFI_MEMORY_XP, or both. All UEFI memory that is marked executable must be read only. Memory marked writable must not be executable. Entries may not be left with neither of the attributes set, indicating memory that is both executable and writable. |
| Secure Memory Overwrite Request (MOR)<br>revision 2 | Secure MOR v2 is enhanced to protect the MOR lock setting using a UEFI secure variable. This helps guard against advanced memory attacks. For details, see Secure MOR implementation. |
| Memory integrity-compatible drivers | Ensure all system drivers have been tested and verified to be compatible with memory integrity. The Windows Driver Kit and Driver Verifier contain tests for driver compatibility with memory integrity. There are three steps to verify driver compatibility:<br><br>1. Use Driver Verifier with the Code Integrity compatibility checks enabled.<br>2. Run the Hypervisor Code Integrity Readiness Test in the Windows HLK.<br>3. Test the driver on a system with VBS and memory integrity enabled. This step is imperative to validate the driver's behavior with memory integrity, as static code analysis tools simply aren't capable of detecting all memory integrity violations possible at runtime. |
| Secure Boot | Secure Boot must be enabled on devices leveraging VBS. For more information, see Secure Boot |

You can disable VBS for a VM with:
```powershell
Set-VMSecurity -VMName <VMName> -VirtualizationBasedSecurityOptOut $true
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/security/images/vbs-guards1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/security/images/vbs-guards2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/security/images/vbs-guards3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/security/images/vbs-guards4.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn On Virtualization Based Security](https://noverse.dev/policies?p=DeviceGuard*VirtualizationBasedSecurity) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\DeviceGuard` | `EnableVirtualizationBasedSecurity`<br>`RequirePlatformSecurityFeatures`<br>`HypervisorEnforcedCodeIntegrity`<br>`HVCIMATRequired`<br>`LsaCfgFlags`<br>`MachineIdentityIsolation`<br>`ConfigureSystemGuardLaunch`<br>`ConfigureKernelShadowStacksLaunch` |

# Disable Bitlocker & EFS

> "*BitLocker is a Windows security feature that provides encryption for entire volumes, addressing the threats of data theft or exposure from lost, stolen, or inappropriately decommissioned devices.*
>
> *Data on a lost or stolen device is vulnerable to unauthorized access, either by running a software-attack tool against it, or by transferring the device's hard drive to a different device. BitLocker helps mitigate unauthorized data access by enhancing file and system protections, rendering data inaccessible when BitLocker-protected devices are decommissioned or recycled.*
>
> — Microsoft, [BitLocker overview](https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/)

Disable Bitlocker on all volumes:
```powershell
$nvbvol = Get-BitLockerVolume
Disable-BitLocker -MountPoint $nvbvol
```

## NtfsDisableEncryption Notes

`fsutil behavior set disableencryption 1` sets:
```powershell
fsutil.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\FileSystem\NtfsDisableEncryption	Type: REG_DWORD, Length: 4, Data: 1
```
```
\Registry\Machine\SYSTEM\ControlSet001\Policies : NtfsDisableEncryption
\Registry\Machine\SYSTEM\ControlSet001\Control\FileSystem : NtfsDisableEncryption
```

### 0x8007177E Error

Enabling `NtfsDisableEncryption` (`1`) may cause Xbox games to fail to install (error code `0x8007177E` - "Allow encryption on selected disk volume to install this game"):

```powershell
ERROR_VOLUME_NOT_SUPPORT_EFS = 0x8007177E;
```

- Windows API, [Error Defines](https://github.com/arizvisa/BugId-mWindowsAPI/blob/904a1c0bd22c019ef6ca8313945fe38f4ca26f30/mDefines/mErrorDefines.py#L1793)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not allow encryption on all NTFS volumes](https://noverse.dev/policies?p=FileSys*DisableEncryption) | `HKLM\System\CurrentControlSet\Policies` | `NtfsDisableEncryption` |

# Disable P2P Updates

Default is configured to LAN. The Group Download mode combined with Group ID, enables administrators to create custom device groups that share content between devices in the group. Download mode dictates which download sources clients are allowed to use when downloading Windows updates in addition to Windows Update servers.

> "*Delivery Optimization is a cloud-managed, peer-to-peer client; and a downloader service that delivers updates to an organization's networked devices. Delivery Optimization allows devices to download updates from alternate sources (such as other peers on the network), in addition to Microsoft servers. Delivery Optimization combines partial bits from local devices, with partial bits from Microsoft servers to update devices in the network environment. The expected result is reduced bandwidth usage, and a faster update process.*"
>
> — Microsoft, [Delivery Optimization](https://learn.microsoft.com/en-us/windows/win32/delivery_optimization/delivery-optimization-portal)

### [DODownloadMode Data](https://learn.microsoft.com/en-us/windows/deployment/do/waas-delivery-optimization-reference#download-mode)

| Download mode option | Data  | Functionality when configured |
| ---- | :----: | ---- |
| HTTP Only | `0` | This setting disables peer-to-peer caching but still allows Delivery Optimization to download content over HTTP from the download's original source or a Microsoft Connected Cache server. This mode uses additional metadata provided by the Delivery Optimization cloud services for a peerless, reliable and efficient download experience. |
| LAN (Default) | `1` | This default operating mode for Delivery Optimization enables peer sharing on the same network. The Delivery Optimization cloud service finds other clients that connect to the Internet using the same public IP as the target client. These clients then try to connect to other peers on the same network by using their private subnet IP. |
| Group | `2` | When group mode is set, the group is automatically selected based on the device's Active Directory Domain Services (AD DS) site (Windows 10, version 1607) or the domain the device is authenticated to (Windows 10, version 1511). In group mode, peering occurs across internal subnets, between devices that belong to the same group, including devices in remote offices. You can use GroupID option to create your own custom group independently of domains and AD DS sites. Starting with Windows 10, version 1803, you can use the GroupIDSource parameter to take advantage of other method to create groups dynamically. Group download mode is the recommended option for most organizations looking to achieve the best bandwidth optimization with Delivery Optimization. |
| Internet | `3` | Enable Internet peer sources for Delivery Optimization. |
| Simple | `99` | Simple mode disables the use of Delivery Optimization cloud services completely (for offline environments). Delivery Optimization switches to this mode automatically when the Delivery Optimization cloud services are unavailable, unreachable, or when the content file size is less than 50 MB, as the default. In this mode, Delivery Optimization provides a reliable download experience over HTTP from the download's original source or a Microsoft Connected Cache server, with no peer-to-peer caching. |
| Bypass | `100` | Starting in Windows 11, this option is deprecated. Don't configure Download mode to '100' (Bypass), which can cause some content to fail to download. If you want to disable peer-to-peer functionality, configure DownloadMode to (0). If your device doesn't have internet access, configure Download Mode to (99). When you configure Bypass (100), the download bypasses Delivery Optimization and uses BITS instead. You don't need to configure this option if you're using Configuration Manager. |

### [Set-DODownloadMode](https://learn.microsoft.com/en-us/powershell/module/deliveryoptimization/set-dodownloadmode?view=windowsserver2025-ps)

Microsoft has a cmdlet for it, but seems like they didn't work much on it yet.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Download Mode](https://noverse.dev/policies?p=DeliveryOptimization*DownloadMode) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\DeliveryOptimization` | `DODownloadMode` |

# Disable System Restore

```powershell
Disable-ComputerRestore -Drive "C:\"
```
Does:
```powershell
"wmiprvse.exe", "RegSetValue","HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\SystemRestore\RPSessionInterval","Type: REG_DWORD, Length: 4, Data: 0"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Configuration](https://noverse.dev/policies?p=SystemRestore*SR_DisableConfig) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableConfig` |
| [Turn off System Restore](https://noverse.dev/policies?p=SystemRestore*SR_DisableSR) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableSR` |

# Disable Downloads Blocking

Windows adds a hidden tag called [`Zone.Identifier`](https://www.cyberengage.org/post/unveiling-file-origins-the-role-of-alternate-data-streams-ads-zone-identifier-in-forensic-inve) to files downloaded from the internet. This tag (also known as MotW) stores info about the file's origin and helps apply security warnings, see files including the tag with:
```powershell
gi * -Stream "Zone.Identifier" -ErrorAction SilentlyContinue
```

![](https://github.com/nohuto/win-config/blob/main/security/images/downblocking.png?raw=true)

## ZoneID Data

**ZoneID** (`HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Zones`) - number indicating the security zone the file came from:
`0` – Local machine
`1` – Local intranet (internal network)
`2` – Trusted sites
`3` – Internet (mostly web downloads)
`4` – Untrusted / Restricted sites (flagged as dangerous by smartscreen)

## Unblock-File

Files downloaded from the internet still getting blocked? Unblock it/them with (one of them):
```powershell
Unblock-File -Path "C:\Path\Script.ps1" -> File

dir C:\Path\*Files* | Unblock-File -> Multiple files 
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not preserve zone information in file attachments](https://noverse.dev/policies?p=AttachmentManager*AM_MarkZoneOnSavedAtttachments) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Attachments` | `SaveZoneInformation` |

# Disable Password Reveal

"This policy setting allows you to configure the display of the password reveal button in password entry user experiences. If you enable this policy setting, the password reveal button won't be displayed after a user types a password in the password entry text box. If you disable or don't configure this policy setting, the password reveal button will be displayed after a user types a password in the password entry text box. By default, the password reveal button is displayed after a user types a password in the password entry text box."

## Suboption

### Picture Password Sign-In

> "*This policy setting allows you to control whether a domain user can sign in using a picture password. If you enable this policy setting, a domain user can't set up or sign in with a picture password. If you disable or don't configure this policy setting, a domain user can set up and use a picture password. Note that the user's domain password will be cached in the system vault when using this feature.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off picture password sign-in](https://noverse.dev/policies?p=CredentialProviders*BlockDomainPicturePassword) | `HKLM\Software\Policies\Microsoft\Windows\System` | `BlockDomainPicturePassword` |
| [Do not display the password reveal button](https://noverse.dev/policies?p=CredUI*DisablePasswordReveal) | `HKLM\Software\Policies\Microsoft\Windows\CredUI`<br>`HKCU\Software\Policies\Microsoft\Windows\CredUI` | `DisablePasswordReveal` |

# Enable USB Write Protection

Restricts write access to USB devices (read only). You can also change it with `diskpart`, by selecting the disk with `select disk` and chaning it to read only with `attributes disk set readonly` (revert it with `attributes disk clear readonly`).

Rather leave USB connection error notifications enabled, unless there's a specific reason for it.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Removable Disks: Deny write access](https://noverse.dev/policies?p=RemovableStorage*RemovableDisks_DenyWrite_Access_1) | `HKLM\Software\Policies\Microsoft\Windows\RemovableStorageDevices\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}`<br>`HKCU\Software\Policies\Microsoft\Windows\RemovableStorageDevices\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}` | `Deny_Write` |

# Increase TDR

Disabling TDR removes a valuable layer of protection, so it is generally recommended that you keep it enabled.

> "*TDR is a feature in Windows that detects when the graphics card takes longer than expected to complete an operation. It then resets the graphics card to prevent the entire system from becoming unresponsive.*
>
> *One of the most common stability problems in graphics occurs when a computer appears to "hang" or be completely "frozen" while it's actually processing an end-user command or operation. Many users wait a few seconds and then decide to reboot the computer. The frozen appearance of the computer frequently occurs because the GPU is busy processing intensive graphical operations, typically during game play, and hence doesn't update the display screen. TDRs enable the operating system to detect that the UI isn't responsive.*"
>
> — Microsoft, [WDDM support for timeout detection and recovery (TDR)](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/timeout-detection-and-recovery)

![](https://github.com/nohuto/win-config/blob/main/security/images/tdr-process.jpg?raw=true)

### [Registry Values](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/display/tdr-registry-keys.md)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    "TdrLevel" = 3; // REG_DWORD, 0/1/3, other = 3
    // "Specifies the initial level of recovery."
    // 0 (TdrLevelOff) = Detection disabled
    // 1 (TdrLevelBugcheck) = Bug check on detected timeout, for example, no recovery
    // 2 (TdrLevelRecoverVGA) = Recover to VGA (not implemented)
    // 3 (TdrLevelRecover) = Recover on timeout (default value)

    "TdrDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the GPU can delay the preempt request from the GPU scheduler. TdrDelay is effectively the timeout threshold."

    "TdrDdiDelay" = 5; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the OS allows threads to leave the driver. After the specified time, the OS bug-checks the computer with the code VIDEO_TDR_FAILURE (0x116)."

    "TdrDebugMode" = 2; // REG_DWORD, range 0-3, other = 2
    // "Specifies the debugging-related behavior of the TDR process. The default value is TDR_DEBUG_MODE_RECOVER_NO_PROMPT, which indicates not to break into the debugger."
    // 0 = Break to kernel debugger before the recovery to allow investigation of the timeout.
    // 1 = Ignore any timeout.
    // 2 = Recover without breaking into the debugger (default value).
    // 3 = Recover even if some recovery conditions aren't met (for example, recover on consecutive timeouts).

    "TdrLimitTime" = 60; // REG_DWORD, range 5-3600
    // "Specifies the default time within which a specific number of TDRs (specified by the TdrLimitCount key) are allowed without crashing the computer."

    "TdrLimitCount" = 5; // REG_DWORD, range 1-32
    // "Specifies the default number of TDRs (0x117) that the system allows during the time specified by the TdrLimitTime key without crashing the computer."

    // _TdrIsTestMode
    "TdrTestMode" = 0; // REG_DWORD (bool)
    // "Reserved. Don't use."

    // TdrInit
    "TdrDodPresentDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds allowed for the kernel-mode display-only driver's (KMDOD) DxgkDdiPresentDisplayOnly function to complete an asynchronous present by reporting progress to pfnPresentDisplayOnlyProgress (which is passed in the DXGKARG_PRESENT_DISPLAYONLY structure)."

    "TdrDodVSyncDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds the V-sync watchdog waits for a V-sync signal to be reported before triggering a TDR in a KMDOD."
```

# Password Age

`/MAXPWAGE:{days | UNLIMITED}`:  
"Sets the maximum number of days that a password is valid. No limit is specified by using UNLIMITED. /MAXPWAGE can't be less than /MINPWAGE. The range is 1-999; the default is 90 days."

```powershell
NET ACCOUNTS  
[/FORCELOGOFF:{minutes | NO}]  
[/MINPWLEN:length]  
[/MAXPWAGE:{days | UNLIMITED}]  
[/MINPWAGE:days]  
[/UNIQUEPW:number] [/DOMAIN]
```

Congigure the policy yourself via `Computer Configuration > Windows Settings > Security Settings > Account Policies > Password Policy`:

![](https://github.com/nohuto/win-config/blob/main/security/images/passwordage.png?raw=true)

# Enable Dynamic Lock

Automatically locks your device when you're away. It requires Bluetooth to be active. This option is disabled by default.

### Accounts Captures

Toggling it via `Accounts > Sign-in options`:
```c
// Enabled
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 1

// Disabled (default)
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 0
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure dynamic lock factors](https://noverse.dev/policies?p=Passport*MSPassport_UseDynamicLock) | `HKLM\SOFTWARE\Policies\Microsoft\PassportForWork\DynamicLock` | `DynamicLock`<br>`Plugins` |

# Sudo

[Sudo](https://github.com/microsoft/sudo) ([introduction](https://devblogs.microsoft.com/commandline/introducing-sudo-for-windows/)) is a new way for users to run elevated commands (as an administrator) directly from an unelevated console session on Windows.

Note that sudo uses administrator previledges and doesn't include `TrustedInstaller`/`SYSTEM` previledges.

### Modes

| Mode | Description |
| ---- | ---- |
| `forceNewWindow` | Runs the command elevated in a new console window. |
| `disableInput` | Runs elevated in the same window but blocks keyboard input while it runs. |
| `normal` | Runs elevated in the same window with normal input and output behavior. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure the behavior of the sudo command](https://noverse.dev/policies?p=Sudo*EnableSudo) | `HKLM\Software\Policies\Microsoft\Windows\Sudo` | `Enabled` |

# Enable Camera OSD Indicator

> "*`NoPhysicalCameraLED` indicates that there is no physical LED for the device's camera. An example of a physical LED for a camera is the small blue light that turns on whenever the camera is streaming video. This setting is used to indicate to the shell component that it will need to provide a small indicator in the user interface (UI) to show when video frames are streaming or not streaming to replace the notification by physical LED.*"
>
> — Microsoft, [NoPhysicalCameraLED](https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/microsoft-windows-coremmres-nophysicalcameraled)

![](https://github.com/nohuto/win-config/blob/main/system/images/cameraosd.png?raw=true)

| Data | Description |
| :---: | --- |
| 0 | Does not draw an indicator in the UI to show when the camera is on or off. Instead, a physical LED exists to show when video frames are streaming or not streaming. This is the default value. |
| 1 | Draws an indicator in the UI to show when video frames are streaming or not streaming. |

```
\Registry\Machine\SOFTWARE\Microsoft\OEM\Device\Capture : NoPhysicalCameraLED
```

# Administrator Account

This security setting determines whether the [local Administrator account](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/accounts-administrator-account-status) is enabled or disabled. The following conditions prevent disabling the Administrator account, even if this security setting is disabled.

- he Administrator account is currently in use
- The Administrators group has no other members
- All other members of the Administrators group are:
  - Disabled
  - Listed in the [Deny log on locally](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/deny-log-on-locally) User Rights Assignment
  
If the Administrator account is disabled, you can't enable it if the password doesn't meet requirements. In this case, another member of the Administrators group must reset the password.

## Best practices

Disabling the administrator account can become a maintenance issue under certain circumstances. For example, in a domain environment, if the secure channel that constitutes your connection fails for any reason, and there's no other local administrator account, you must restart the computer in safe mode to fix the problem that broke your connection status.

## Vulnerability

The built-in administrator account can't be locked out no matter how many failed logons it accrues, which makes it a prime target for brute-force attacks that attempt to guess passwords. Also, this account has a well-known security identifier (SID), and there are non-Microsoft tools that allow authentication by using the SID rather than the account name. Therefore, even if you rename the Administrator account, an attacker could launch a brute-force attack by using the SID to sign in. All other accounts that are members of the Administrator's group have the safeguard of locking out the account if the number of failed logons exceeds its configured maximum.

# Guest Account

[Guest account](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/accounts-guest-account-status) status policy setting determines whether the Guest account is enabled or disabled. This account allows unauthenticated network users to gain access to the system by signing in as a Guest with no password. Unauthorized users can access any resources that are accessible to the Guest account over the network. This privilege means that any network shared folders with permissions that allow access to the Guest account, the Guests group, or the Everyone group will be accessible over the network. This accessibility can lead to the exposure or corruption of data.

## Best practices

Set Guest account status to Disabled so that the built-in Guest account is no longer usable. All network users will have to authenticate before they can access shared resources on the system. If the Guest account is disabled and Network access: Sharing and security model for local accounts is set to Guest only, network logons, such as those logons performed by the SMB Service will fail.

## Vulnerability

The default Guest account allows unauthenticated network users to sign in as a Guest with no password. These unauthorized users could access any resources that are accessible to the Guest account over the network. This capability means that any shared folders with permissions that allow access to the Guest account, the Guests group, or the Everyone group are accessible over the network, which could lead to the exposure or corruption of data.

# defaultuser0 Account

defaultuser0 is a temporary Windows setup account.

### Miscellaneous Notes

If extracting the whole System32 folder recursively using [strings2](https://github.com/nohuto/strings2-tui) you'll see that the string `defaultuser0` only exists in `DeviceEnroller.exe` (at least for me). The notes below are based on several decompiled functions from `DeviceEnroller.exe` (`MakeActiveUserLocalAdmin`).

`defaultuser0` is only used as a "do not elevate" sentinel in the admin promotion path.

```c
// WinMainCommon
if (!HasActiveLocalAdminAccount()) {
    MakeActiveUserLocalAdmin();
}
```
```c
// MakeActiveUserLocalAdmin
DmGetActiveUserSid(&StringSid);
LookupAccountSidW(..., &name, &domain, ...);
if (_wcsicmp(name, L"defaultuser0")) {
    MakeAUserLocalAdmin(name, domain);
    DmDeleteTask(L"\\Microsoft\\Windows\\EnterpriseMgmt", 0,
                L"Login Schedule created by enrollment client");
} else {
    // defaultuser0: skip elevation
}
```

DeviceEnroller.exe = MDM/Enterprise enrollment client that runs enrollment and renewal sessions (e.g., `EnrollEngineInitialize`, `InitiateSessionAsync`, `WaitForEnrollment`) here.

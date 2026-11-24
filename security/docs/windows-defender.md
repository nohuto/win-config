# Windows Defender

## [Current Defender Status](https://learn.microsoft.com/en-us/defender-endpoint/microsoft-defender-antivirus-windows#use-powershell-to-check-the-status-of-microsoft-defender-antivirus)

1. Select the **Start** menu, and begin typing `PowerShell`. Then open Windows PowerShell in the results.
2. Type `Get-MpComputerStatus`.
3. In the list of results, look at the **AMRunningMode** row.
   - **Normal** means Microsoft Defender Antivirus is running in active mode.
   - **Passive mode** means Microsoft Defender Antivirus running, but isn't the primary antivirus/anti-malware product on your device. Passive mode is only available for devices that are onboarded to Microsoft Defender for Endpoint and that meet certain requirements. To learn more, see [Requirements for Microsoft Defender Antivirus to run in passive mode](https://learn.microsoft.com/en-us/defender-endpoint/microsoft-defender-antivirus-compatibility#requirements-for-microsoft-defender-antivirus-to-run-in-passive-mode).
   - **EDR Block Mode** means Microsoft Defender Antivirus is running and [Endpoint detection and response (EDR) in block mode](https://learn.microsoft.com/en-us/defender-endpoint/edr-in-block-mode), a capability in Microsoft Defender for Endpoint, is enabled. Check the **ForceDefenderPassiveMode** registry key. If its value is 0, it's running in normal mode; otherwise, it's running in passive mode.
   - **SxS Passive Mode** means Microsoft Defender Antivirus is running alongside another antivirus/anti-malware product, and [limited periodic scanning is used](https://learn.microsoft.com/en-us/defender-endpoint/limited-periodic-scanning-microsoft-defender-antivirus).

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
- [Defender core telemetry](https://learn.microsoft.com/en-us/defender-endpoint/microsoft-defender-core-service-overview) disabled (`DisableCoreServiceTelemetry` = true: "*The Microsoft Defender Core service doesn't collect telemetry from Microsoft Defender Antivirus and other Defender software. Disabling this setting can impact Microsoft's ability to quickly recognize and address problems, such as slow performance and false positives*")
- [Defender core ECS integration](https://learn.microsoft.com/en-us/defender-endpoint/microsoft-defender-core-service-overview) disabled (ECS = Experimentation and Configuration Service)

If using [`native.winoffice.txt`](https://github.com/hagezi/dns-blocklists/blob/main/adblock/native.winoffice.txt) ECS won't function properly, since it [has to receive payload](https://learn.microsoft.com/en-us/defender-endpoint/microsoft-defender-core-service-configurations-and-experimentation) from:

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
| [Turn on raw volume write notifications](https://noverse.dev/policies?p=WindowsDefender*RealtimeProtection_DisableRawWriteNotification) | `HKLM\Software\Policies\Microsoft\Windows Defender\Real-Time Protection` | `DisableRawWriteNotification` |
| [Configure Watson events](https://noverse.dev/policies?p=WindowsDefender*Reporting_DisablegenericrePorts) | `HKLM\Software\Policies\Microsoft\Windows Defender\Reporting` | `DisableGenericRePorts` |
| [Turn off enhanced notifications](https://noverse.dev/policies?p=WindowsDefender*Reporting_DisableEnhancedNotifications) | `HKLM\Software\Policies\Microsoft\Windows Defender\Reporting` | `DisableEnhancedNotifications` |
| [Turn on e-mail scanning](https://noverse.dev/policies?p=WindowsDefender*Scan_DisableEmailScanning) | `HKLM\Software\Policies\Microsoft\Windows Defender\Scan` | `DisableEmailScanning` |
| [This settings controls whether Network Protection is allowed to be configured into block or audit mode on Windows Server.](https://noverse.dev/policies?p=WindowsDefender*AllowNetworkProtectionOnWinServer) | `HKLM\Software\Policies\Microsoft\Windows Defender\Windows Defender Exploit Guard\Network Protection` | `AllowNetworkProtectionOnWinServer` |
| [Allow notifications to disable security intelligence based reports to Microsoft MAPS](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_SignatureDisableNotification) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `SignatureDisableNotification` |
| [Initiate security intelligence update on startup](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_DisableUpdateOnStartupWithoutEngine) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `DisableUpdateOnStartupWithoutEngine` |
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
| [Turn off routine remediation](https://noverse.dev/policies?p=WindowsDefender*DisableRoutinelyTakingAction) | `HKLM\Software\Policies\Microsoft\Windows Defender` | `DisableRoutinelyTakingAction` |

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


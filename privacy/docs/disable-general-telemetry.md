# Disable General Telemetry

Prevents sending information about your computer to Microsoft by disabling general and diagnostic telemetry, inventory collection, app launch tracking, inking/typing personalization, online speech recognition, feedback prompts, CEIP, etc.

Note that `AllowTelemetry = 0` (diagnostic data off) only works on Enterprise, Education & Server ("This value is only supported on Enterprise, Education, and Server editions.", `DataCollection.admx`). On Home and Pro, Windows treats it as *Required*, means the disabled services/autologgers are what stop the upload here.

See policy explanations below for more details.

It's also recommended to apply the '[Microsoft (Windows, Office, MSN)](https://github.com/hagezi/dns-blocklists#native)' blocklist ([Windows 11 connection endpoints for non-Enterprise editions](https://learn.microsoft.com/en-us/windows/privacy/windows-11-endpoints-non-enterprise-editions#windows-11-pro)) via the hosts file (you can use [blocklist-mgr](https://github.com/nohuto/win-config/blob/main/network/assets/scripts/Blocklist-Manger.ps1) for that), or if you've a private DNS server, add that list to it.

## DiagnosticDataSettings Values

Based on 23H2 [`DiagnosticDataSettings`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/DiagnosticDataSettings) pseudocode (see list below). I've also looked through values within `DiagSvc.dll`/`DiagTrack.dll` but beside `CEIPEnable`/`EnableDiagnostics` they don't include anything interesting.

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\DiagTrack";
    "RedirectedRegistryRoot" = "Software\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\DiagTrack"; // REG_SZ

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\DiagTrack\\RegionalSettings";
    "IsProcessorMode" = 0; // REG_QWORD, only lets Windows report diagnostic data processor mode when data is exactly 1

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection";
    "AllowTelemetry" = 1; // REG_DWORD, 2 normalized to 1, 3  = diagnostic, >3 not clamped
    "MaxTelemetryAllowed" = ?; // REG_DWORD

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection\\Users\\<subkey>";
    "AllowTelemetry" = ?; // REG_DWORD, per user group policy value
    "AllowTelemetry_PolicyManager" = ?; // REG_DWORD

"HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection";
    "AllowTelemetry" = ?; // REG_DWORD, data 0/1/2/3 as above, >3 not clamped
    "LimitDumpCollection" = 0; // REG_DWORD, used when active telemetry is 2/3
    "LimitEnhancedDiagnosticDataWindowsAnalytics" = 0; // REG_DWORD
    "DisableTelemetryOptInChangeNotification" = 0; // REG_DWORD
    "DisableTelemetryOptInSettingsUx" = 0; // REG_DWORD
    "DisableDeviceDelete" = 0; // REG_DWORD
    "DisableDiagnosticDataViewer" = 0; // REG_DWORD
    "AllowCommercialDataPipeline" = 0; // REG_DWORD
    "LimitDiagnosticLogCollection" = 0; // REG_DWORD
    "DisableEnterpriseAuthProxy" = 0; // REG_DWORD
    "AllowDeviceNameInDiagnosticData" = 0; // REG_DWORD
    "DisableOneSettingsDownloads" = 0; // REG_DWORD
    "EnableOneSettingsAuditing" = 0; // REG_DWORD
    "ConfigureMicrosoft365UploadEndpoint" = ?; // REG_SZ

"HKLM\\OFFLINE_AUTH\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\DiagTrack";
    "DiagTrackAuthorization" = 0; // REG_DWORD

"HKLM\\OFFLINE_AUTH\\Policies\\Microsoft\\Windows\\DataCollection";
    "LimitDumpCollection" = 0; // REG_DWORD
```

- [`TelpReadLocalSetting`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelpReadLocalSetting.c)
- [`TelpReadGroupPolicySetting`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelpReadGroupPolicySetting.c)
- [`TelpReadMdmSetting`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelpReadMdmSetting.c)
- [`TelpReadUsersPolicySetting`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelpReadUsersPolicySetting.c)
- [`TelEvaluateActiveSettingAuthority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelEvaluateActiveSettingAuthority.c)
- [`TelGetMaximumAllowedTelemetryLevel`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelGetMaximumAllowedTelemetryLevel.c)
- [`TelGetNumericPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelGetNumericPolicy.c)
- [`TelGetWerTelemetryMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelGetWerTelemetryMode.c)
- [`TelpGetTelemetryClientRegPath`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/-TelpGetTelemetryClientRegPath@@YAPEAGXZ.c)
- [`TelIsOsInProcessorMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelIsOsInProcessorMode.c)
- [`TelpReadOfflineOsPolicySetting`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelpReadOfflineOsPolicySetting.c)
- [`TelGetWerTelemetryModeWinRE`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/DiagnosticDataSettings/TelGetWerTelemetryModeWinRE.c)

### Boot Capture

See [23H2.txt](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/assets/records/23H2.txt) ([24H2](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/assets/records/24H2.txt)/[25H2](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/assets/records/25H2.txt) don't include more than that).

```
\Registry\Machine\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\DataCollection : AllowTelemetry
\Registry\Machine\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\DataCollection : CommercialId
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : AllowDeviceNameInTelemetry
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : AllowTelemetry
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : AllowTelemetry_PolicyManager
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : CommercialId
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : DisableEnterpriseAuthProxy
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : DisableTelemetryOptInChangeNotification
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : LimitDiagnosticLogCollection
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : LimitDumpCollection
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : TelemetryProxyServer
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\DataCollection : TelemetryProxyServer_PolicyManager
\Registry\User\<CURRENT_USER_SID>\SOFTWARE\Policies\Microsoft\Windows\DataCollection : AllowTelemetry
\Registry\User\<CURRENT_USER_SID>\SOFTWARE\Policies\Microsoft\Windows\DataCollection : AllowTelemetry_PolicyManager
```

## Suboptions

### Website Access to Language List

"Sets the HTTP Accept Language from the Language List opt-out setting." Disables [`Let websites provide locally relevant content by accessing my language list`](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#181-general).

Using [`Set-WinAcceptLanguageFromLanguageListOptOut`](https://learn.microsoft.com/en-us/powershell/module/international/set-winacceptlanguagefromlanguagelistoptout?view=windowsserver2025-ps):

```powershell
Set-WinAcceptLanguageFromLanguageListOptOut -OptOut $True
```

```c
// $True
"powershell.exe","RegSetValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut","Type: REG_DWORD, Length: 4, Data: 1"
"powershell.exe","RegDeleteValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage",""

// $False
"powershell.exe","RegDeleteValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut",""
"powershell.exe","RegSetValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage","Type: REG_SZ, Length: 54, Data: en-US;q=0.7,en;q=0.3"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Inventory Collector](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffProgramInventory) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableInventory` |
| [Allow Diagnostic Data](https://noverse.dev/policies?p=DataCollection*AllowTelemetry) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection`<br>`HKCU\Software\Policies\Microsoft\Windows\DataCollection` | `AllowTelemetry` |
| [Configure Authenticated Proxy usage for the Connected User Experience and Telemetry service](https://noverse.dev/policies?p=DataCollection*DisableEnterpriseAuthProxy) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableEnterpriseAuthProxy` |
| [Limit optional diagnostic data for Desktop Analytics](https://noverse.dev/policies?p=DataCollection*LimitEnhancedDiagnosticDataWindowsAnalytics) (only works with `AllowTelemetry = 3`) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `LimitEnhancedDiagnosticDataWindowsAnalytics` |
| [Allow device name to be sent in Windows diagnostic data](https://noverse.dev/policies?p=DataCollection*AllowDeviceNameInDiagnosticData) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `AllowDeviceNameInTelemetry` |
| [Configure diagnostic data opt-in settings user interface](https://noverse.dev/policies?p=DataCollection*ConfigureTelemetryOptInSettingsUx) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableTelemetryOptInSettingsUx` |
| [Configure diagnostic data opt-in change notifications](https://noverse.dev/policies?p=DataCollection*ConfigureTelemetryOptInChangeNotification) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableTelemetryOptInChangeNotification` |
| [Disable deleting diagnostic data](https://noverse.dev/policies?p=DataCollection*DisableDeviceDelete) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableDeviceDelete` |
| [Disable diagnostic data viewer](https://noverse.dev/policies?p=DataCollection*DisableDiagnosticDataViewer) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableDiagnosticDataViewer` |
| [Limit Diagnostic Log Collection](https://noverse.dev/policies?p=DataCollection*LimitDiagnosticLogCollection) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `LimitDiagnosticLogCollection` |
| [Limit Dump Collection](https://noverse.dev/policies?p=DataCollection*LimitDumpCollection) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `LimitDumpCollection` |
| [Configure the Commercial ID](https://noverse.dev/policies?p=DataCollection*CommercialIdPolicy) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `CommercialId` |
| [Turn off the advertising ID](https://noverse.dev/policies?p=UserProfiles*DisableAdvertisingId) | `HKLM\Software\Policies\Microsoft\Windows\AdvertisingInfo` | `DisabledByGroupPolicy` |
| [Improve inking and typing recognition](https://noverse.dev/policies?p=TextInput*AllowLinguisticDataCollection) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\TextInput` | `AllowLinguisticDataCollection` |
| [Restrict Internet communication](https://noverse.dev/policies?p=ICM*InternetManagement_RestrictCommunication_2) | `HKLM\Software\Policies\Microsoft\Windows\TabletPC` | `PreventHandwritingDataSharing` |
| [Allow Windows Ink Workspace](https://noverse.dev/policies?p=WindowsInkWorkspace*AllowWindowsInkWorkspace) | `HKLM\Software\Policies\Microsoft\WindowsInkWorkspace` | `AllowWindowsInkWorkspace` |
| [Allow suggested apps in Windows Ink Workspace](https://noverse.dev/policies?p=WindowsInkWorkspace*AllowSuggestedAppsInWindowsInkWorkspace) | `HKLM\Software\Policies\Microsoft\WindowsInkWorkspace` | `AllowSuggestedAppsInWindowsInkWorkspace` |
| [Allow users to enable online speech recognition services](https://noverse.dev/policies?p=Globalization*AllowInputPersonalization) | `HKLM\Software\Policies\Microsoft\InputPersonalization` | `AllowInputPersonalization` |
| [Allow Automatic Update of Speech Data](https://noverse.dev/policies?p=Speech*AllowSpeechModelUpdate) | `HKLM\Software\Policies\Microsoft\Speech` | `AllowSpeechModelUpdate` |
| [Do not show feedback notifications](https://noverse.dev/policies?p=FeedbackNotifications*DoNotShowFeedbackNotifications) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DoNotShowFeedbackNotifications` |
| [Turn off the Windows Messenger Customer Experience Improvement Program](https://noverse.dev/policies?p=ICM*WinMSG_NoInstrumentation_2) | `HKLM\Software\Policies\Microsoft\Messenger\Client` | `CEIP` |
| [Turn off Windows Customer Experience Improvement Program](https://noverse.dev/policies?p=ICM*CEIPEnable) | `HKLM\Software\Policies\Microsoft\SQMClient\Windows` | `CEIPEnable` |
| [Turn off Resultant Set of Policy logging](https://noverse.dev/policies?p=GroupPolicy*RSoPLogging) | `HKLM\Software\Policies\Microsoft\Windows\System` | `RSoPLogging` |
| [Turn off KMS Client Online AVS Validation](https://noverse.dev/policies?p=AVSValidationGP*NoAcquireGT) | `HKLM\Software\Policies\Microsoft\Windows NT\CurrentVersion\Software Protection Platform` | `NoGenTicket` |

## Useless Values

Some additional notes on values that don't seem to be read anywhere on W10/11:

- `DiagTrack\TestHooks`: `BlackBoxErrorEventsCapacity`, `BlackBoxTraceEventsCapacity`, `BlackBoxTriggerEventsCapacity`, `DisableAsimovUpload`, `EscalationsDisabled` (even field only `LifetimeManager_EscalationsDisabled`), `PercentageOfAlwaysOnTraceRunning`, `SkipSoftLandingScenarios`
- `DiagTrack\TriggerListener`: `UseMsFlushTimer`
- `SQMClient`: `UploadDisableFlag`
- `AppCompat`: `AITEnable` (W7), `HandwritingErrorReports`: `PreventHandwritingErrorReports`
- `SQM`: `DisableCustomerImprovementProgram`

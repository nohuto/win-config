# App Configuration

See [`app-guides`](https://noverse.dev/docs/app-guides/) ([repo](https://github.com/nohuto/app-guides)) for all guides/assets.

## Guides

- [Brave Configuration (Desktop)](https://noverse.dev/docs/app-guides/brave-desktop/)
- [Brave Configuration (iOS)](https://noverse.dev/docs/app-guides/brave-ios/)
- [Discord Configuration](https://noverse.dev/docs/app-guides/discord/)
- [LGHUB Configuration](https://noverse.dev/docs/app-guides/lghub/)
  - [`LGHUB-Toggle.ps1`](https://github.com/nohuto/app-guides/blob/main/assets/LGHUB-Toggle.ps1) enables/disables `LGHUBUpdaterService`, related Logitech drivers, and the LGHUB startup entry
- [Mullvad Configuration](https://noverse.dev/docs/app-guides/mullvad-desktop/)
- [Spotify Configuration](https://noverse.dev/docs/app-guides/spotify/)
  - [`Spotify-Config.ps1`](https://github.com/nohuto/app-guides/blob/main/assets/Spotify-Config.ps1) edits global/per-user `prefs`, see guide for detailed information
- [Steam Configuration](https://noverse.dev/docs/app-guides/steam/)
  - [`Steam-Config.ps1`](https://github.com/nohuto/app-guides/blob/main/assets/Steam-Config.ps1) parses `localconfig.vdf`, adds/edits the documented keys/blocks, see guide for detailed information
- [SteelSeries Configuration](https://noverse.dev/docs/app-guides/steelseries/)
- [VSC Configuration](https://noverse.dev/docs/app-guides/vsc/)

- [Browser Extensions](https://github.com/nohuto/app-guides/blob/main/extensions.md)
- [Search Engines](https://github.com/nohuto/app-guides/blob/main/search-engine.md)

# Disable General Telemetry

Prevents sending information about your computer to Microsoft by disabling general and diagnostic telemetry, inventory collection, app launch tracking, inking/typing personalization, online speech recognition, feedback prompts, CEIP, etc.

See policy explanations below for more details.

It's also recommended to apply the '[Microsoft (Windows, Office, MSN)](https://github.com/hagezi/dns-blocklists#calling-native-tracker---broadband-tracker-of-devices-services-and-operating-systems-)' blocklist ([Windows 11 connection endpoints for non-Enterprise editions](https://learn.microsoft.com/en-us/windows/privacy/windows-11-endpoints-non-enterprise-editions#windows-11-pro)) via the hosts file (you can use [blocklist-mgr](https://github.com/nohuto/blocklist-mgr) for that), or if you've a private DNS server, add that list to it.

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

See [23H2.txt](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/records/23H2.txt) ([24H2](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/records/24H2.txt)/[25H2](https://raw.githubusercontent.com/nohuto/regkit/refs/heads/main/records/25H2.txt) don't include more than that).

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

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Application Telemetry](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffApplicationImpactTelemetry) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `AITEnable` |
| [Turn off Inventory Collector](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffProgramInventory) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableInventory` |
| [Allow Diagnostic Data](https://noverse.dev/policies?p=DataCollection*AllowTelemetry) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection`<br>`HKCU\Software\Policies\Microsoft\Windows\DataCollection` | `AllowTelemetry` |
| [Configure Authenticated Proxy usage for the Connected User Experience and Telemetry service](https://noverse.dev/policies?p=DataCollection*DisableEnterpriseAuthProxy) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableEnterpriseAuthProxy` |
| [Limit optional diagnostic data for Desktop Analytics](https://noverse.dev/policies?p=DataCollection*LimitEnhancedDiagnosticDataWindowsAnalytics) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `LimitEnhancedDiagnosticDataWindowsAnalytics` |
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
| [Restrict Internet communication](https://noverse.dev/policies?p=ICM*InternetManagement_RestrictCommunication_2) | `HKLM\Software\Policies\Microsoft\Windows\HandwritingErrorReports`<br>`HKLM\Software\Policies\Microsoft\Windows\TabletPC` | `PreventHandwritingErrorReports`<br>`PreventHandwritingDataSharing` |
| [Allow Windows Ink Workspace](https://noverse.dev/policies?p=WindowsInkWorkspace*AllowWindowsInkWorkspace) | `HKLM\Software\Policies\Microsoft\WindowsInkWorkspace` | `AllowWindowsInkWorkspace` |
| [Allow suggested apps in Windows Ink Workspace](https://noverse.dev/policies?p=WindowsInkWorkspace*AllowSuggestedAppsInWindowsInkWorkspace) | `HKLM\Software\Policies\Microsoft\WindowsInkWorkspace` | `AllowSuggestedAppsInWindowsInkWorkspace` |
| [Allow users to enable online speech recognition services](https://noverse.dev/policies?p=Globalization*AllowInputPersonalization) | `HKLM\Software\Policies\Microsoft\InputPersonalization` | `AllowInputPersonalization` |
| [Allow Automatic Update of Speech Data](https://noverse.dev/policies?p=Speech*AllowSpeechModelUpdate) | `HKLM\Software\Policies\Microsoft\Speech` | `AllowSpeechModelUpdate` |
| [Do not show feedback notifications](https://noverse.dev/policies?p=FeedbackNotifications*DoNotShowFeedbackNotifications) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DoNotShowFeedbackNotifications` |
| [Turn off the Windows Messenger Customer Experience Improvement Program](https://noverse.dev/policies?p=ICM*WinMSG_NoInstrumentation_2) | `HKLM\Software\Policies\Microsoft\Messenger\Client` | `CEIP` |
| [Turn off Windows Customer Experience Improvement Program](https://noverse.dev/policies?p=ICM*CEIPEnable) | `HKLM\Software\Policies\Microsoft\SQMClient\Windows` | `CEIPEnable` |
| [Prevent participation in the Customer Experience Improvement Program](https://noverse.dev/policies?p=inetres*SQM_DisableCEIP) | `HKLM\Software\Policies\Microsoft\Internet Explorer\SQM`<br>`HKCU\Software\Policies\Microsoft\Internet Explorer\SQM` | `DisableCustomerImprovementProgram` |
| [Turn off Resultant Set of Policy logging](https://noverse.dev/policies?p=GroupPolicy*RSoPLogging) | `HKLM\Software\Policies\Microsoft\Windows\System` | `RSoPLogging` |
| [Turn off KMS Client Online AVS Validation](https://noverse.dev/policies?p=AVSValidationGP*NoAcquireGT) | `HKLM\Software\Policies\Microsoft\Windows NT\CurrentVersion\Software Protection Platform` | `NoGenTicket` |

# Disable WER

> "*Windows Error Reporting (WER) is a sophisticated mechanism that automates the submission of both user-mode process crashes as well as kernel-mode system crashes. Multiple system components have been designed for supporting reports generated when a user-mode process, protected process, trustlet, or the kernel crashes.*
>
> *Windows Error Reporting is implemented in multiple components of the OS, mainly because it needs to deal with different kind of crashes:*  
> *- The Windows Error Reporting Service (WerSvc.dll) is the main service that manages the creation and sending of reports when a user-mode process, protected process, or trustlet crashes.*  
> *- The Windows Fault Reporting and Secure Fault Reporting (WerFault.exe and WerFaultSecure.exe) are mainly used to acquire a snapshot of the crashing application and start the generation and sending of a report to the Microsoft Online Crash Analysis site (or, if configured, to an internal error reporting server).*  
> *- The actual generation and transmission of the report is performed by the Windows Error Reporting Dll (Wer.dll). The library includes all the functions used internally by the WER engine and also some exported API that the applications can use to interact with Windows Error Reporting (documented at https://docs.microsoft.com/en-us/windows/win32/api/_wer/ ). Note that some WER APIs are also implemented in Kernelbase.dll and Faultrep.dll.*  
> *- The Windows User Mode Crash Reporting DLL (Faultrep.dll) contains common WER stub code that is used by system modules (Kernel32.dll, WER service, and so on) when a user-mode application crashes or hangs. It includes services for creating a crash signature and reports a hang to the WER service, managing the correct security context for the report creation and transmission (which includes the creation of the WerFault executable under the correct security token).*
>
> — Windows Internals, [E7, P2: 'Windows Error Reporting (WER)'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

[Windows Error Reporting flow](https://learn.microsoft.com/en-us/windows/win32/wer/using-wer#windows-error-reporting-flow-for-crashes-non-response-and-kernel-faults) for crashes, non-response, and kernel faults:
1. The problem event occurs.
2. The operating system invokes WER.
3. WER collects the data, builds a report, and prompts the user for consent (if needed).
4. WER sends the report to Microsoft (Watson Server) if the user consented.
5. If the Watson server requests additional data, WER collects the data and prompts the user for consent (if needed).
6. If the application has registered for recovery and restart, WER executes the registered callback functions while the data is compressed and sent to Microsoft (if the user consented).
7. If a response to the problem is available from Microsoft, the user is notified.

[Error-Reporting.txt](https://github.com/nohuto/regkit/blob/main/records/Error-Reporting.txt) shows all read values on boot (`\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting`) / [WER Settings](https://learn.microsoft.com/en-us/windows/win32/wer/wer-settings) for some details.

## Services/Tasks

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\ErrorDetails\EnableErrorDetailsUpdate` | - | - |
| `\Microsoft\Windows\Windows Error Reporting\QueueReporting` | Windows Error Reporting task to process queued reports. | `%windir%\system32\wermgr.exe -upload` |

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WerSvc` | Allows errors to be reported when programs stop working or responding and allows existing solutions to be delivered. Also allows logs to be generated for diagnostic and repair services. If this service is stopped, error reporting might not work correctly and results of diagnostic services and repairs might not be displayed. | Win32 Own Process (16) | - | C:\Windows\System32\svchost.exe -k WerSvcGroup |
| `wercplsupport` | This service provides support for viewing, sending and deletion of system-level problem reports for the Problem Reports control panel. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netsvcs -p |

## Suboptions

### DHA Report

> "*This group policy enables Device Health Attestation reporting (DHA-report) on supported devices. It enables supported devices to send Device Health Attestation related information (device boot logs, PCR values, TPM certificate, etc.) to Device Health Attestation Service (DHA-Service) every time a device starts. Device Health Attestation Service validates the security state and health of the devices, and makes the findings accessible to enterprise administrators via a cloud based reporting portal. This policy is independent of DHA reports that are initiated by device manageability solutions (like MDM or SCCM), and will not interfere with their workflows.*"

### Persistent System Timestamp

Disables the Reliability policy that periodically writes the current system time to disk. Windows uses that persistent timestamp as a "last known alive" time so Reliability Monitor / WER can estimate when an unexpected shutdown, power loss, hard reset, or crash happened (see policies below).

> "*This policy setting allows the system to detect the time of unexpected shutdowns by writing the current time to disk on a schedule controlled by the Timestamp Interval. If you enable this policy setting, you are able to specify how often the Persistent System Timestamp is refreshed and subsequently written to the disk. You can specify the Timestamp Interval in seconds. If you disable this policy setting, the Persistent System Timestamp is turned off and the timing of unexpected shutdowns is not recorded. If you do not configure this policy setting, the Persistent System Timestamp is refreshed according the default, which is every 60 seconds beginning with Windows Server 2003. Note: This feature might interfere with power configuration settings that turn off hard disks after a period of inactivity. These power settings may be accessed in the Power Options Control Panel.*"

```c
if ( !RegQueryValueExW(hKey[0], "TimeStampEnabled", 0LL, 0LL, (LPBYTE)&Data, &cbData) )
if ( !RegQueryValueExW(hKey[0], "TimeStampInterval", 0LL, 0LL, (LPBYTE)&v4, &cbData) && v4 <= 0x15180 ) // 86400 seconds = 24h?
```

`TimeStampInterval` under `HKLM\Software\Policies\Microsoft\Windows NT\Reliability` is in seconds, the value under `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability` is read as minutes and multiplied by 60.

- [privacy/assets | timestamp-OsEventsTimestampInterval.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/timestamp-OsEventsTimestampInterval.c)

### Crash Dumps

Disables the crash dump, logging. Not all values may be read on your system.

#### [Data Meaning](https://learn.microsoft.com/en-us/troubleshoot/windows-server/performance/memory-dump-file-options#registry-values-for-startup-and-recovery)

```c
CrashDumpEnabled REG_DWORD 0x0 = None
CrashDumpEnabled REG_DWORD 0x1 = Complete memory dump
CrashDumpEnabled REG_DWORD 0x2 = Kernel memory dump
CrashDumpEnabled REG_DWORD 0x3 = Small memory dump (64 KB)
CrashDumpEnabled REG_DWORD 0x7 = Automatic memory dump
CrashDumpEnabled REG_DWORD 0x1 and FilterPages REG_DWORD 0x1 = Active memory dump
```

There're two values named [`CrashDumpEnabled.New`](https://github.com/nohuto/regkit/blob/main/records/CrashControl.txt) & [`CrashDumpEnabled.Old`](https://github.com/nohuto/regkit/blob/main/records/CrashControl.txt), I haven't looked into them yet, see this as note for future reference.

```
\Registry\Machine\SYSTEM\ControlSet001\Control\CrashControl : CrashDumpEnabled.New
\Registry\Machine\SYSTEM\ControlSet001\Control\CrashControl : CrashDumpEnabled.Old
```

- [privacy/assets | crashdmp.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/crashdmp.c)
- [privacy/assets | crashdmp-SecureDump_PrepareForInit.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/crashdmp-SecureDump_PrepareForInit.c)

## Miscellaneous Notes

### EnableWerUserReporting

Note that `Dbgk` prefix = *Debugging Framework for user mode*.

> *Prefix is the internal component that exports the routine, Operation tells what is being done to the object or resource, and Object identifies what is being operated on. For example, ExAllocatePoolWithTag is the executive support routine to allocate from a paged or non-paged pool. KeInitializeThread is the routine that allocates and sets up a kernel thread object.*
>
> — Windows Internals, [E7, P1: 'Peering into undocumented interfaces'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
  "EnableWerUserReporting" = 1; // DbgkEnableWerUserReporting, REG_DWORD, range 0 = disabled, any nonzero 32 bit data = enabled
```

Used in [DbgkQueueUserExceptionReport](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/DbgkQueueUserExceptionReport.c):

```c
if ( !DbgkEnableWerUserReporting ) // 0 would block the part below (DbgkUserReportWorkRoutine etc)
  return 3221226326LL; // STATUS_AUDITING_DISABLED, "The specified event is currently not being audited."
```

The queued work routine is basically a thing for initiating UM (user mode) WER reporting work, some direct callers that I found are:
- [`SepLogLpacAccessFailure`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/SepLogLpacAccessFailure.c) calls it for LPAC access failures, after ETW tracing and its own `SeLpacEnableWatsonReporting`
- [`MiForceCrashForInvalidAccess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/MiForceCrashForInvalidAccess.c) can call it for invalid executable memory write handling

### SeLpacEnableWatsonReporting

Note that this is dependent on `EnableWerUserReporting`, means if the value above is `0` this has no effect.

| Prefix | Component |
| --- | --- |
| `Se` | Security Reference Monitor |

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
  "SeLpacEnableWatsonReporting" = 0; // SeLpacEnableWatsonReporting, REG_DWORD, 0 disables, nonzero enables
```

Used in [SepLogLpacAccessFailure](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/SepLogLpacAccessFailure.c):

```c
EtwTraceLpacAccessFailure(v4); // always happenes

if ( !SeLpacEnableWatsonReporting )
  return 3221226326LL; // stop before report - STATUS_AUDITING_DISABLED, "The specified event is currently not being audited."

return DbgkQueueUserExceptionReport();
```

WER replaced Dr. Watson, which was included in Windows XP, but it can still be used (see WER flow [above](https://noverse.dev/docs/win-config/privacy/disable-wer/)) "*4. WER sends the report to Microsoft (Watson Server) if the user consented.*".

### AerMultiErrorDisabled

Related to [PCIe advanced error reporting](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability)? Haven't informed myself about it yet, therefore ignore it:
```
\Registry\Machine\SYSTEM\ControlSet001\Control\PnP\pci : AerMultiErrorDisabled
```
Default is `0`, non zero would enable the behaviour? The value doesn't exist by default.

- [privacy/assets | wer-PciGetSystemWideHackFlagsFromRegistry.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/wer-PciGetSystemWideHackFlagsFromRegistry.c)

```
\Registry\Machine\SYSTEM\ControlSet001\Control\StorPort : TelemetryErrorDataEnabled
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Memory Management : PeriodicTelemetryReportFrequency
```

### [WER Endpoints](https://github.com/MicrosoftDocs/SupportArticles-docs/blob/main/support/windows-client/system-management-components/windows-error-reporting-diagnostics-enablement-guidance.md#configure-network-endpoints-to-be-allowed)

See [privacy/disable-general-telemetry](https://noverse.dev/docs/win-config/privacy/disable-general-telemetry/) note on the blocklist (which includes these domains).

- Port used: `443`
- Protocol used: HTTPS with SSL/TLS using certificate pinning

| Windows versions | Endpoint |
| --- | --- |
| All Windows versions | `watson.microsoft.com` |
| Windows 10, version 1803 or later | `watson.telemetry.microsoft.com` |
| Windows 10, version 1809 or later | `umwatsonc.events.data.microsoft.com` |
| Windows 10, version 1809 or later | `ceuswatcab01.blob.core.windows.net` |
| Windows 10, version 1809 or later | `ceuswatcab02.blob.core.windows.net` |
| Windows 10, version 1809 or later | `eaus2watcab01.blob.core.windows.net` |
| Windows 10, version 1809 or later | `eaus2watcab02.blob.core.windows.net` |
| Windows 10, version 1809 or later | `weus2watcab01.blob.core.windows.net` |
| Windows 10, version 1809 or later | `weus2watcab02.blob.core.windows.net` |

### [DefaultConsent](https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/microsoft-windows-errorreportingcore-defaultconsent)

`DefaultConsent` specifies in what circumstances the user is asked whether to send an error report.

#### Values

| `0` or `1` | Always ask the user whether to send an error report. This is the default value. |
| --- | --- |
| `2` | Ask the user for everything except for basic parameters such as application name, version, and module name that are sent automatically. |
| `3` | Ask the user for everything except for basic parameters that are likely to be safe, such as application name, version, and module name, and data. Send these items automatically. |
| `4` | Do not ask the user; send all error reports automatically. |

### [DisableWER](https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/microsoft-windows-errorreportingcore-disablewer)

Disables Windows Error Reporting.

#### Values

| `0` | Enables Windows Error Reporting |
| --- | --- |
| `1` | Disables Windows Error Reporting |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not send a Windows error report when a generic driver is installed on a device](https://noverse.dev/policies?p=DeviceSetup*DeviceInstall_GenericDriverSendToWER) | `HKLM\Software\Policies\Microsoft\Windows\DeviceInstall\Settings` | `DisableSendGenericDriverNotFoundToWER` |
| [Prevent Windows from sending an error report when a device driver requests additional software during installation](https://noverse.dev/policies?p=DeviceSetup*DeviceInstall_RequestAdditionalSoftwareSendToWER) | `HKLM\Software\Policies\Microsoft\Windows\DeviceInstall\Settings` | `DisableSendRequestAdditionalSoftwareToWER` |
| [Disable Windows Error Reporting](https://noverse.dev/policies?p=ErrorReporting*WerDisable_2) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Error Reporting` | `Disabled` |
| [Disable logging](https://noverse.dev/policies?p=ErrorReporting*WerNoLogging_1) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\Windows Error Reporting` | `LoggingDisabled` |
| [Automatically send memory dumps for OS-generated error reports](https://noverse.dev/policies?p=ErrorReporting*WerAutoApproveOSDumps_1) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\Windows Error Reporting` | `AutoApproveOSDumps` |
| [Automatically send memory dumps for OS-generated error reports](https://noverse.dev/policies?p=ErrorReporting*WerAutoApproveOSDumps_2) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Error Reporting` | `AutoApproveOSDumps` |
| [Enable Device Health Attestation Monitoring and Reporting](https://noverse.dev/policies?p=TPM*OptIntoDSHA_Name) | `HKLM\Software\Policies\Microsoft\DeviceHealthAttestationService` | `EnableDeviceHealthAttestationService` |
| [Enable Persistent Time Stamp](https://noverse.dev/policies?p=Reliability*EE_EnablePersistentTimeStamp) | `HKLM\Software\Policies\Microsoft\Windows NT\Reliability` | `TimeStampEnabled`<br>`TimeStampInterval` |

# Troubleshooter Preference

It's set to `Ask me before running` by default.

| Option | Description |
| ---- | ---- |
| Run automatically, don't notify me | Windows will automatically run recommended troubleshooters for problems detected on your device without bothering you. |
| Run automatically, then notify me | Windows will tell you after recommended troubleshooters have solved a problem so you know what happened. |
| Ask me before running (default) | We'll let you know when recommended troubleshooting is available. You can review the problem and changes before running the troubleshooters. |
| Don't run any | Windows will automatically run critical troubleshooters but won't recommend troubleshooting for other problems. You will not get notifications for known problems, and you will need to manually troubleshoot these problems on your device. |

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DPS` | The Diagnostic Policy Service enables problem detection, troubleshooting and resolution for Windows components. If this service is stopped, diagnostics will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `TroubleshootingSvc` | Enables automatic mitigation for known problems by applying recommended troubleshooting. If stopped, your device will not get recommended troubleshooting for problems on your device. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `diagsvc` | Executes diagnostic actions for troubleshooting support | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k diagnostics |

These get disabled in the `Don't run any` option.

### SystemSettings Captures

`System > Troubleshoot` - `Recommended troubleshooter preferences`:
```c
// Don't run any
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 1

// Ask me before running (default)
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 2

// Run automatically, then notify me
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 3

// Run automatically, don't notify me
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 4
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Microsoft Support Diagnostic Tool: Turn on MSDT interactive communication with support provider](https://noverse.dev/policies?p=MSDT*MsdtSupportProvider) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnosticsProvider\Policy` | `DisableQueryRemoteServer` |
| [Troubleshooting: Allow users to access and run Troubleshooting Wizards](https://noverse.dev/policies?p=sdiageng*ScriptedDiagnosticsExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnostics` | `EnableDiagnostics` |
| [Troubleshooting: Allow users to access online troubleshooting content on Microsoft servers from the Troubleshooting Control Panel (via the Windows Online Troubleshooting Service - WOTS)](https://noverse.dev/policies?p=sdiageng*BetterWhenConnected) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnosticsProvider\Policy` | `EnableQueryRemoteServer` |
| [Troubleshooting: Allow users to access recommended troubleshooting for known problems](https://noverse.dev/policies?p=MSDT*TroubleshootingAllowRecommendations) | `HKLM\Software\Policies\Microsoft\Windows\Troubleshooting\AllowRecommendations` | `TroubleshootingAllowRecommendations` |
| [Configure Scheduled Maintenance Behavior](https://noverse.dev/policies?p=sdiagschd*ScheduledDiagnosticsExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScheduledDiagnostics` | `EnabledExecution`<br>`EnabledExecutionLevel` |
| [Diagnostics: Configure scenario execution level](https://noverse.dev/policies?p=WDI*WdiDpsScenarioExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WDI` | `ScenarioExecutionEnabled`<br>`EnabledScenarioExecutionLevel` |

# Disable Suggestions/Tips/Tricks

Disables all kind of suggestions, in start, text suggestions (multilingual...), in the timeline, content. `338389` is the only value named `SubscribedContent-{number}Enabled` that exists by default.

### SubscribedContent IDs

Since the `SubscribedContent-*` values aren't documented literally anywhere I've tried to get some information to see which exist and what they do. You can find information on them in `ContentDeliveryManager.Utilities.dll`, see [contentdelivery.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/contentdelivery.c) for asm snippets that include these information.

| Feature | IDs | Practical meaning |
|---|---|---|
| `LockScreen` | `338380`, `338387` | Windows Spotlight / lock-screen creative content |
| `WindowsTip` | `338382`, `338389` | tips, tricks, and suggested Windows content - `338389` is used for '*System > Notifications > Additional settings - Get tips and suggestions when using Windows*' |
| `StartSuggestions` | `338381`, `338388` | suggested/recommended content in Start |
| `Settings` | `338386`, `338393` | promoted content inside Settings |
| `SettingsHome` | `353697`, `353696` | Settings Home recommendations/cards |
| `SettingsAccountsYourInfo` | `353695`, `353694` | promoted content in Settings > Accounts > Your info |
| `SettingsValueBanner` | `88000106`, `88000105` | banner/value-promoting content in Settings |
| `OobeOffers` | `314566`, `314567` | OOBE and post-setup offers |
| `MinuteZeroOffers` | `310094`, `310093` | very-early setup / first-run offers - `310093` is used for 'System > Notifications > Additional settings - Show the Windows welcome experience after updates and when signed in to show what's new and suggested' |
| `ApiTest` | `280812` | internal/test subscription used by CDM |
| `ActionCenter` | `310092`, `310091` | Action Center / notification-surface content |
| `ShareAppSuggestions` | `280814`, `280815` | app suggestions around sharing flows |
| `SilentInstalledApps` | `202913`, `202914` | silent/preinstalled app delivery |
| `PeopleAppSuggestions` | `314562`, `314563` | People-related app suggestions |
| `DynamicLayouts` | `314558`, `314559` | dynamic layout-driven targeted content |
| `DynamicLayoutsSV` | `88000531`, `88000530` | variant of dynamic layouts |
| `Timeline` | `353699`, `353698` | Timeline related suggested content |
| `AppDefaultsEdgeEnlightenment` | `88000044`, `88000045` | Edge/default-app promotion |
| `OneDriveLocal` | `280797`, `280811` | local OneDrive promotion/setup |
| `OneDriveSync` | `280817`, `280810` | OneDrive sync promotion/setup |
| `OneDriveDocuments` | `88000162`, `88000161` | OneDrive documents backup/setup |
| `OneDriveDesktop` | `88000164`, `88000163` | OneDrive desktop backup/setup |
| `OneDrivePictures` | `88000166`, `88000165` | OneDrive pictures backup/setup |

`SubscribedContent-338393Enabled` `SubscribedContent-353694Enabled` ,`SubscribedContent-353696Enabled` are used in 'Privacy & security > Recommendations & offers - Recommendatins and offers in Settings' but only when toggling it off (when toggling it on they stay at `0`).

I'll look into these soon:

```c
SubscribedContent-88000325Enabled	TRACE	(value not set)		Yes (23H2)				
SubscribedContent-88000326Enabled	TRACE	(value not set)		Yes (23H2)				
```

### Windows Spotlight

> "*Windows spotlight is a feature that displays different wallpapers and offers suggestions, fun facts, tips, or organizational messages:*  
> *- Wallpapers: Windows spotlight displays a new image on the lock screen and in the background every day*  
> *- Suggestions, fun facts, tips: recommendations on how to enhance the user's productivity of Microsoft products. They're displayed in different locations, such as the lock screen, the background, the taskbar, or the Get Started app*  
> *- Organizational messages: messages from your organization, which can be displayed in the lock screen, taskbar, the notification area, or the Get Started app*"
>
> — Microsoft, [Configure Windows spotlight](https://learn.microsoft.com/en-us/windows/configuration/windows-spotlight/?pivots=windows-11)

![](https://github.com/nohuto/win-config/blob/main/privacy/images/lockscreen-spotlight.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Microsoft consumer experiences](https://noverse.dev/policies?p=CloudContent*DisableWindowsConsumerFeatures) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsConsumerFeatures` |
| [Turn off cloud optimized content](https://noverse.dev/policies?p=CloudContent*DisableCloudOptimizedContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableCloudOptimizedContent` |
| [Turn off cloud consumer account state content](https://noverse.dev/policies?p=CloudContent*DisableConsumerAccountStateContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableConsumerAccountStateContent` |
| [Do not show Windows tips](https://noverse.dev/policies?p=CloudContent*DisableSoftLanding) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableSoftLanding` |
| [Do not suggest third-party content in Windows spotlight](https://noverse.dev/policies?p=CloudContent*DisableThirdPartySuggestions) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableThirdPartySuggestions` |
| [Allow Online Tips](https://noverse.dev/policies?p=ControlPanel*AllowOnlineTips) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `AllowOnlineTips` |
| [Remove Recommended section from Start Menu](https://noverse.dev/policies?p=StartMenu*HideRecommendedSection) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideRecommendedSection` |
| [Remove Personalized Website Recommendations from the Recommended section in the Start Menu](https://noverse.dev/policies?p=StartMenu*HideRecommendedPersonalizedSites) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideRecommendedPersonalizedSites` |
| [Turn off display of recent search entries in the File Explorer search box](https://noverse.dev/policies?p=WindowsExplorer*DisableSearchBoxSuggestions) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `DisableSearchBoxSuggestions` |
| [Configure Windows spotlight on lock screen](https://noverse.dev/policies?p=CloudContent*ConfigureWindowsSpotlight) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `ConfigureWindowsSpotlight`<br>`IncludeEnterpriseSpotlight` |
| [Turn off all Windows spotlight features](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightFeatures) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightFeatures` |
| [Turn off Spotlight collection on Desktop](https://noverse.dev/policies?p=CloudContent*DisableSpotlightCollectionOnDesktop) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableSpotlightCollectionOnDesktop` |
| [Do not suggest third-party content in Windows spotlight](https://noverse.dev/policies?p=CloudContent*DisableThirdPartySuggestions) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableThirdPartySuggestions` |
| [Turn off Windows Spotlight on Action Center](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightOnActionCenter) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightOnActionCenter` |
| [Turn off Windows Spotlight on Settings](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightOnSettings) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightOnSettings` |
| [Turn off the Windows Welcome Experience](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightWindowsWelcomeExperience) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightWindowsWelcomeExperience` |

# Disable Automatic Map Downloads

Disables automatic network traffic on the settings page and prevents automatic downloading or updating of map data, limiting location related data updates.

`AllowOfflineMapsDownloadOverMeteredConnection` & `EnableOfflineMapsAutoUpdate`:

| Value |	Description |
| ---- | ---- |
| `0`	Disabled | Force disable auto-update over metered connection. |
| `1`	Enabled | Force enable auto-update over metered connection. |
| `65535` (Default)	Not configured | User's choice. |

- [privacy/assets | maps.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/maps.c)

## moshostcore Snippets

- `moshostcore` = Downloaded Maps Manager Core

```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"AutoUpdateEnabled", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetAutoUpdateEnabledSetting",
					   3025,
					   this);
return v5;
```
```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"UpdateOnlyOnWifi", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetDownloadOnlyOnWifiSetting",
					   3043,
					   this);
return v5;
```
```c
v6 = sub_180022E1C(L"System\\Maps\\Configuration", L"OfflineMaps");
if ( v6 < 0 )
{
  v7 = 3888LL;
  goto LABEL_4;
}
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Automatic Download and Update of Map Data](https://noverse.dev/policies?p=WinMaps*TurnOffAutoUpdate) | `HKLM\Software\Policies\Microsoft\Windows\Maps` | `AutoDownloadAndUpdateMapData` |
| [Turn off unsolicited network traffic on the Offline Maps settings page](https://noverse.dev/policies?p=WinMaps*DisallowUntriggeredNetworkOnSettingsPage) | `HKLM\Software\Policies\Microsoft\Windows\Maps` | `AllowUntriggeredNetworkTrafficOnSettingsPage` |

# Disable Time Sync

Stops Windows from correcting the system clock through network time sources (the clock continues running from the hardware clock, but it may become inaccurate and eventually cause incorrect timestamps, certificate/sign-in errors, invalid authentication codes, or unreliable scheduled tasks). You can change your time zone via `System > Time Zone`.

| Service/Task | Description |
| --- | --- |
| `W32Time` | Maintains date and time synchronization on all clients and servers in the network. If this service is stopped, date and time synchronization will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
| `\Microsoft\Windows\Time Synchronization\ForceSynchronizeTime` | Forces Windows to synchronize the system clock. |
| `\Microsoft\Windows\Time Synchronization\SynchronizeTime` | Starts `W32Time` to perform scheduled time synchronization. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Windows NTP Client](https://noverse.dev/policies?p=W32Time*W32TIME_POLICY_ENABLE_NTPCLIENT) | `HKLM\Software\Policies\Microsoft\W32Time\TimeProviders\NtpClient` | `Enabled` |

# Disable Cross-Device Experiences

Disables Cross-Device experiences (allows you to use `Share Across Devices`/`Nearby Sharing` functionalities) & share accross devices. With `Share across devices`, you can continue app experiences on other devices connected to your account (set to `My device only` by default).

### SystemSettings Captures

Changing "Share across devices" option via `SystemSettings`:

```c
// Off
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 0

// My device only
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\SettingsPage\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1

// Everyone nearby
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\SettingsPage\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2

// Miscellaneous note
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\EnableRemoteLaunchToast  Type: REG_DWORD, Length: 4, Data: 1
```

`RomeSdkChannelUserAuthzPolicy` (`CDP\SettingsPage`) is only used for "My device only"/"Everyone nearby" (it's still getting changed to `0` in this option).

```c
L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"BluetoothLastDisabledNearShare",

L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"WifiLastDisabledNearShare",
```

- [privacy/assets | crossdev-SharedExperiencesSingleton.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/crossdev-SharedExperiencesSingleton.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Continue experiences on this device](https://noverse.dev/policies?p=GroupPolicy*EnableCDP) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableCdp` |

# Disable Phone Linking

> "*This policy allows IT admins to turn off the ability to Link a Phone with a PC to continue reading, emailing and other tasks that requires linking between Phone and PC.If you enable this policy setting, the Windows device will be able to enroll in Phone-PC linking functionality and participate in Continue on PC experiences.If you disable this policy setting, the Windows device is not allowed to be linked to Phones, will remove itself from the device list of any linked Phones, and cannot participate in Continue on PC experiences.If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.*"

### SystemSettings Captures

This option will also disable resume ("Start something on one device and continue on this PC") - `System Settings > Apps > Resume`.

```c
// Off
HKCU\Software\Microsoft\Windows\CurrentVersion\CrossDeviceResume\Configuration\IsResumeAllowed	Type: REG_DWORD, Length: 4, Data: 0

// On
HKCU\Software\Microsoft\Windows\CurrentVersion\CrossDeviceResume\Configuration\IsResumeAllowed	Type: REG_DWORD, Length: 4, Data: 1
```

By default resume is enabled, OneDrive is the only app which exists under the "Control which apps can use Resume" on a stock 25H2 installation and can be toggled via `IsOneDriveResumeAllowed` (same key as `IsResumeAllowed`). Disabling resume will disallow all apps to use Resume (doesn't set `IsXResumeAllowed` to `0`).

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Phone-PC linking on this device](https://noverse.dev/policies?p=GroupPolicy*EnableMMX) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableMmx` |

# Hide Last Logged-In User

Note that if you use this option and don't have a password, you'll have to enter your username at each boot ([policy](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/interactive-logon-do-not-display-last-user-name)).

> "*This security setting determines whether the Windows sign-in screen will show the username of the last person who signed in on this PC.*"

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 0
```

`Hide Username at Sign-In`:  
"This security setting determines whether the username of the person signing in to this PC appears at Windows sign-in, after credentials are entered, and before the PC desktop is shown."

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 0
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Display information about previous logons during user logon](https://noverse.dev/policies?p=WinLogon*DisplayLastLogonInfoDescription) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `DisplayLastLogonInfo` |
| [Remove logon hours expiration warnings](https://noverse.dev/policies?p=WinLogon*LogonHoursNotificationPolicyDescription) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `DontDisplayLogonHoursWarnings` |

# Disable Background Apps

Note that whenever you use this option while having UWP apps, it'll break notifications, background sync, etc., also *some apps, including Cortana and Search, might not function as expected if you set 'Let apps run in the background' to 'Force Deny'*.

> "*This policy setting specifies whether Windows apps can run in the background.*
>
> *You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting.*
>
> *If you choose the "User is in control" option, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device.*
>
> *If you choose the "Force Allow" option, Windows apps are allowed to run in the background and employees in your organization cannot change it.*
>
> *If you choose the "Force Deny" option, Windows apps are not allowed to run in the background and employees in your organization cannot change it.*
>
> *If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device.*
>
> *If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.*"

```
Computer Configuration\Administrative Templates\Windows Components\App Privacy
```

`Enabled` -> `Deny All changes`:

```powershell
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground	Type: REG_DWORD, Length: 4, Data: 2
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_UserInControlOfTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_ForceAllowTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_ForceDenyTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
```

## Suboption

### Disable Background Task Host

Renames `backgroundTaskHost.exe` to prevent UWP background tasks from running (notifications, live tiles, background sync). Use only if you do not rely on Store apps. When the system is in Modern Standby, desktop apps are suspended and UWP apps are typically suspended, but background tasks created by UWP apps are allowed to execute. `backgroundTaskHost.exe` is the host for those tasks.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps run in the background](https://noverse.dev/policies?p=AppPrivacy*LetAppsRunInBackground) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsRunInBackground`<br>`LetAppsRunInBackground_UserInControlOfTheseApps`<br>`LetAppsRunInBackground_ForceAllowTheseApps`<br>`LetAppsRunInBackground_ForceDenyTheseApps` |

# Disable Apps for Websites

Prevents websites from opening their associated apps through HTTP or HTTPS links, keeping those links in the default browser instead.

> "*This policy setting determines whether Windows supports web-to-app linking with app URI handlers.*
>
> *Enabling this policy setting enables web-to-app linking so that apps can be launched with a http(s) URI.*
>
> *Disabling this policy disables web-to-app linking and http(s) URIs will be opened in the default browser instead of launching the associated app.*
>
> *If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.*"

## Suboption

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
| [Configure web-to-app linking with app URI handlers](https://noverse.dev/policies?p=GroupPolicy*EnableAppUriHandlers) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableAppUriHandlers` |

# Disable Clipboard

If you copy or cut something it gets stored to your clipboard, see policies below for more details.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cbdhsvc` | This user service is used for Clipboard scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k ClipboardSvcGroup -p |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Clipboard synchronization across devices](https://noverse.dev/policies?p=OSPolicy*AllowCrossDeviceClipboard) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowCrossDeviceClipboard` |
| [Allow Clipboard History](https://noverse.dev/policies?p=OSPolicy*AllowClipboardHistory) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowClipboardHistory` |
| [Do not allow Clipboard redirection](https://noverse.dev/policies?p=TerminalServer*TS_CLIENT_CLIPBOARD) | `HKLM\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services` | `fDisableClip` |
| [Allow clipboard sharing with Windows Sandbox](https://noverse.dev/policies?p=WindowsSandbox*AllowClipboardRedirection) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Sandbox` | `AllowClipboardRedirection` |

# Disable Auto Maintenance

Runs updates and scans daily when your PC is idle, it helps keep your system secure and efficient without affecting performance. Theres no actual reason to disable it, as it doesn't do anything while being active, however if you've any reason for not wanting it to run the tasks while being in idle, toggle the switch.

You can see your current maintenance tasks with:

```powershell
Get-ScheduledTask | ? {$_.Settings.MaintenanceSettings}
```

`SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance` trace:

```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Activation Boundary
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : MaintenanceDisabled
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Random Delay
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Randomized
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : WakeUp
```

---

Miscellaneous notes:
```json
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppModel\\StateRepository": {
  "MaintenanceInterval": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\Repository": {
  "MaintenanceInterval": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\Maintenance": {
  "Random Delay": { "Type": "REG_DWORD", "Data": 0 },
  "Randomized": { "Type": "REG_DWORD", "Data": 0 }
}
```

# Disable Microsoft Copilot

> "*Microsoft introduced Windows Copilot in May 2023. It became available in Windows 11 starting with build 23493 (Dev), 22631.2129 (Beta), and 25982 (Canary). A public preview began rolling out on September 26, 2023, with build 22621.2361 (Windows 11 22H2 KB5030310). It adds integrated AI features to assist with tasks like summarizing web content, writing, and generating images. Windows Copilot appears as a sidebar docked to the right and runs alongside open apps. In Windows 10, Copilot is available in build 19045.3754 for eligible devices in the Release Preview Channel running version 22H2. Users must enable "Get the latest updates as soon as they're available" and check for updates. The rollout is phased via Controlled Feature Rollout (CFR). Windows 10 Pro devices managed by organizations, and all Enterprise or Education editions, are excluded from the initial rollout. Copilot requires signing in with a Microsoft account (MSA) or Azure Active Directory (Entra ID). Users with local accounts can use Copilot up to ten times before sign-in is enforced.*"

`CopilotDisabledReason`:
```c
ValueW = RegGetValueW(
    HKEY_CURRENT_USER,
    L"SOFTWARE\\Microsoft\\Windows\\Shell\\Copilot",
    L"CopilotDisabledReason",
    2u, // REG_SZ
    0LL,
    pvData,
    pcbData);

v16 = L"FailedToGetReason"; // if value is missing
```

```json
"HKCU\\SOFTWARE\\Microsoft\\Windows\\Shell\\Copilot": {
  "CopilotDisabledReason": { "Type": "REG_SZ", "Data": "FeatureIsDisabled" }
}
```

`FeatureIsDisabled` seems to be used by default here (`IsRequiredEdgeBrowserInstalledFailed` exists too):

```c
// procmon boot trace (value unset)
"Explorer.EXE","HKCU\Software\Microsoft\Windows\Shell\Copilot\CopilotDisabledReason","SUCCESS","Type: REG_SZ, Length: 36, Data: FeatureIsDisabled"

// ?
"HKCU\Software\Microsoft\Windows\Shell\Copilot\CopilotLogonTelemetryTime","Type: REG_BINARY, Length: 8, Data: 7A 84 DA 49 6B 89 DC 01"
```

---

Miscellaneous notes:
```c
"OneDrive.exe","HKCU\Software\Microsoft\OneDrive\Accounts\Personal\CopilotEducationalExperienceInfoIconDismissed","NAME NOT FOUND","Length: 16"
"MicrosoftEdgeUpdate.exe","HKLM\SOFTWARE\WOW6432Node\Microsoft\EdgeUpdate\CopilotUpgradeCheck","NAME NOT FOUND","Length: 16"
"Explorer.EXE","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoInstalledPWAs\CopilotHWKeyChoiceSet","SUCCESS","Type: REG_DWORD, Length: 4, Data: 1"
"Explorer.EXE","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoInstalledPWAs\CopilotPWAPreinstallCompleted","SUCCESS","Type: REG_DWORD, Length: 4, Data: 1"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Copilot](https://noverse.dev/policies?p=WindowsCopilot*TurnOffWindowsCopilot) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsCopilot` | `TurnOffWindowsCopilot` |
| [Set Copilot Hardware Key](https://noverse.dev/policies?p=WindowsCopilot*SetCopilotHardwareKey) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CopilotKey` | `SetCopilotHardwareKey` |
| [Disable Image Creator](https://noverse.dev/policies?p=WindowsCopilot*DisableImageCreator) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableImageCreator` |
| [Disable Cocreator](https://noverse.dev/policies?p=WindowsCopilot*DisableCocreator) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableCocreator` |
| [Disable generative fill](https://noverse.dev/policies?p=WindowsCopilot*DisableGenerativeFill) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableGenerativeFill` |

# Disable Recall

> "*Allows you to control whether Windows saves snapshots of the screen and analyzes the user's activity on their device. If you enable this policy setting, Windows will not be able to save snapshots and users won't be able to search for or browse through their historical device activity using Recall. If you disable or do not configure this policy setting, Windows will save snapshots of the screen and users will be able to search for or browse through a timeline of their past activities using Recall.*"

## Suboption

### Disable ClickToDo

> "*Click to Do lets people take action on content on their screens. When activated, it takes a screenshot of their screen and analyzes it to present actions. Click to Do ends when they exit it, and it can't take screenshots while closed. Screenshot analysis is always performed locally on their device. By default, Click to Do is enabled for users. This policy setting allows you to determine whether Click to Do is available for users on their device. When the policy is enabled, the Click to Do component and entry points will not be available to users. When the policy is disabled, users will have Click to Do available on their device.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off saving snapshots for use with Recall](https://noverse.dev/policies?p=WindowsCopilot*DisableAIDataAnalysis) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `DisableAIDataAnalysis` |
| [Allow Recall to be enabled](https://noverse.dev/policies?p=WindowsCopilot*AllowRecallEnablement) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `AllowRecallEnablement` |
| [Disable Click to Do](https://noverse.dev/policies?p=WindowsCopilot*DisableClickToDo) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `DisableClickToDo` |

# Disable Xbox Game Bar

GameDVR is a built-in gameplay capture (Xbox Game Bar) for clips/screenshots, with optional background recording.

### WindowsMediaCapture Values

```c
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR";
    "AudioEncodingBitrate" // REG_DWORD
    "AudioCaptureEnabled" // REG_DWORD, bool
    "CustomVideoEncodingBitrate" // REG_DWORD
    "CustomVideoEncodingHeight" // REG_DWORD
    "CustomVideoEncodingWidth" // REG_DWORD
    "AppCaptureEnabled" // REG_DWORD, bool
    "HistoricalBufferLength" // REG_DWORD
    "HistoricalBufferLengthUnit" // REG_DWORD
    "HistoricalCaptureEnabled" // REG_DWORD, bool
    "HistoricalCaptureOnBatteryAllowed" // REG_DWORD, bool
    "HistoricalCaptureOnWirelessDisplayAllowed" // REG_DWORD, bool
    "MaximumRecordLength" // REG_QWORD
    "VideoEncodingBitrateMode" // REG_DWORD
    "VideoEncodingResolutionMode" // REG_DWORD
    "VideoEncodingFrameRateMode" // REG_DWORD
    "EchoCancellationEnabled" // REG_DWORD, bool
    "CursorCaptureEnabled" // REG_DWORD, bool
    "VKToggleGameBar" // REG_DWORD
    "VKMToggleGameBar" // REG_DWORD
    "VKSaveHistoricalVideo" // REG_DWORD
    "VKMSaveHistoricalVideo" // REG_DWORD
    "VKToggleRecording" // REG_DWORD
    "VKMToggleRecording" // REG_DWORD
    "VKTakeScreenshot" // REG_DWORD
    "VKMTakeScreenshot" // REG_DWORD
    "VKToggleRecordingIndicator" // REG_DWORD
    "VKMToggleRecordingIndicator" // REG_DWORD
    "VKToggleMicrophoneCapture" // REG_DWORD
    "VKMToggleMicrophoneCapture" // REG_DWORD
    "VKToggleCameraCapture" // REG_DWORD
    "VKMToggleCameraCapture" // REG_DWORD
    "VKToggleBroadcast" // REG_DWORD
    "VKMToggleBroadcast" // REG_DWORD
    "MicrophoneCaptureEnabled" // REG_DWORD, bool
    "SystemAudioGain" // REG_QWORD, clamped to 0.0-2.0
    "MicrophoneGain" // REG_QWORD, clamped to 0.0-2.0

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings";
    "AudioCaptureEnabled" // REG_DWORD, bool
    "MicrophoneCaptureEnabledByDefault" // REG_DWORD, bool
    "EchoCancellationEnabled" // REG_DWORD, bool
    "CursorCaptureEnabled" // REG_DWORD, bool
    "SystemAudioGain" // REG_QWORD, clamped to 0.0-2.0
    "MicrophoneGain" // REG_QWORD, clamped to 0.0-2.0
    "CameraCaptureEnabledByDefault" // REG_DWORD, bool
    "CameraOverlayLocation" // REG_DWORD
    "CameraOverlaySize" // REG_DWORD
    "SelectedCameraId" // REG_SZ
```

- [privacy/assets | gamebar-WindowsMediaCaptureIAppCaptureSettings.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/gamebar-WindowsMediaCaptureIAppCaptureSettings.c) (`HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR`)
- [privacy/assets | gamebar-WindowsMediaCaptureIAppBroadcastGlobalSettings.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/gamebar-WindowsMediaCaptureIAppBroadcastGlobalSettings.c) (`HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings`)
- [settings/settings-windows-11.md#gaming-game-bar-game-mode-gaming-shortcuts](https://github.com/MicrosoftDocs/windows-dev-docs/blob/docs/hub/apps/develop/settings/settings-windows-11.md#gaming-game-bar-game-mode-gaming-shortcuts)

### Game Bar Precense Writer

> "*Game Bar Presence Writer is a component that is notified when a game's "presence" state (i.e. is a game running in the foreground) changes. This functionality is available in Windows 10 and later operating systems. By default, the existing Game Bar Presence Writer will set a user's Xbox Live presence state for a running game if the Xbox App is installed, the user is signed into their Xbox account, and the user has enabled Xbox Live presence to be set when they run a game on their PC. It is possible for Windows Application developers to override this default behavior with their own implementation.*"
>
> — Microsoft, [GameBar PresenceWriter](https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enables or disables Windows Game Recording and Broadcasting](https://noverse.dev/policies?p=GameDVR*AllowGameDVR) | `HKLM\Software\Policies\Microsoft\Windows\GameDVR` | `AllowGameDVR` |

# Disable Location Access

Disables app access to your location, locating your system will be disabled, geolocation service gets disabled.

`Privacy & security` > `Location`:
```powershell
"Process Name","Operation","Path","Detail"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\NonPackaged\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\ShowGlobalPrompts","Type: REG_DWORD, Length: 4, Data: 1"
```

- [privacy/assets | locationaccess-LocationApi.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/locationaccess-LocationApi.c)

---

There's also a value named `CSEnable` which I found in `srms.dat`, it doesn't seem to exist anymore.

```html
<!-- Help improve Microsoft services by sending some location data when you use location-aware apps -->
<pattern type="Registry">HKLM\Software\Microsoft\Sensors\LocationProvider [CSEnable]</pattern>
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps access location](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessLocation) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessLocation` |
| [Turn off Windows Location Provider](https://noverse.dev/policies?p=LocationProviderAdm*DisableWindowsLocationProvider_1) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableWindowsLocationProvider` |
| [Turn off sensors](https://noverse.dev/policies?p=Sensors*DisableSensors_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableSensors` |
| [Turn off location](https://noverse.dev/policies?p=Sensors*DisableLocation_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocation` |
| [Turn off location scripting](https://noverse.dev/policies?p=Sensors*DisableLocationScripting_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocationScripting` |

# Disable Sensors

Blocks apps/system from using hardware sensors such as ambient light, orientation, and other motion/position sensors (features like adaptive brightness, auto rotation and sensor based behaviors will no longer work).

> "*This policy setting turns off the sensor feature for this computer. If you enable this policy setting, the sensor feature is turned off, and all programs on this computer can't use the sensor feature.*"

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SensorDataService` | Delivers data from a variety of sensors | Win32 Own Process (16) | - | C:\Windows\System32\SensorDataService.exe |
| `SensrSvc` | Monitors various sensors in order to expose data and adapt to system and user state. If this service is stopped or disabled, the display brightness will not adapt to lighting conditions. Stopping this service may affect other system functionality and features as well. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SensorService` | A service for sensors that manages different sensors' functionality. Manages Simple Device Orientation (SDO) and History for sensors. Loads the SDO sensor that reports device orientation changes. If this service is stopped or disabled, the SDO sensor will not be loaded and so auto-rotation will not occur. History collection from Sensors will also be stopped. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

No other [services](https://github.com/nohuto/win-config/blob/main/system/assets/services.txt)/[drivers](https://github.com/nohuto/win-config/blob/main/system/assets/drivers.txt) depend on these three services.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off sensors](https://noverse.dev/policies?p=Sensors*DisableSensors_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableSensors` |

# Disable PowerShell & .NET Telemetry

### [POWERSHELL_TELEMETRY_OPTOUT](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_telemetry?view=powershell-7.2)

> "*At startup, PowerShell sends diagnostic data including OS manufacturer, name, and version; PowerShell version; `POWERSHELL_DISTRIBUTION_CHANNEL`; Application Insights SDK version; approximate location from IP; command-line parameters (without values); current Execution Policy; and randomly generated GUIDs for the user and session.*"

```bat
setx POWERSHELL_TELEMETRY_OPTOUT 1
```

### [DOTNET_CLI_TELEMETRY_OPTOUT](https://learn.microsoft.com/en-us/dotnet/core/tools/telemetry#how-to-opt-out)

> "*To opt out after you started the installer: close the installer, set the environment variable, and then run the installer again with that value set.*"

```bat
setx DOTNET_CLI_TELEMETRY_OPTOUT 1
```

# Disable Biometrics

Biometric is used for fingerprint, facial recognition, and other biometric authentication methods in Windows Hello and related security features.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow the use of biometrics](https://noverse.dev/policies?p=Biometrics*Biometrics_EnableBio) | `HKLM\SOFTWARE\Policies\Microsoft\Biometrics` | `Enabled` |
| [Allow users to log on using biometrics](https://noverse.dev/policies?p=Biometrics*Biometrics_EnableCredProv) | `HKLM\SOFTWARE\Policies\Microsoft\Biometrics\Credential Provider` | `Enabled` |
| [Allow domain users to log on using biometrics](https://noverse.dev/policies?p=Biometrics*Biometrics_EnableDomainCredProv) | `HKLM\SOFTWARE\Policies\Microsoft\Biometrics\Credential Provider` | `Domain Accounts` |
| [Configure enhanced anti-spoofing](https://noverse.dev/policies?p=Biometrics*Face_EnhancedAntiSpoofing) | `HKLM\SOFTWARE\Policies\Microsoft\Biometrics\FacialFeatures` | `EnhancedAntiSpoofing` |

# Disable Remote Desktop

Disables remote desktop, remote assistance, RPC traffic, and device redirection. See [remote desktop FAQs](https://learn.microsoft.com/en-us/windows-server/remote/remote-desktop-services/remotepc/remote-pc-connections-faq) for more information & [Terminal-Server.txt](https://github.com/nohuto/regkit/blob/main/records/Terminal-Server.txt) for a list of read values on boot (`\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\*` key).

## Services/Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SessionEnv` | Remote Desktop Configuration service (RDCS) is responsible for all Remote Desktop Services and Remote Desktop related configuration and session maintenance activities that require SYSTEM context. These include per-session temporary folders, RD themes, and RD certificates. | Win32 Share Process (32) | RPCSS, LanmanWorkstation | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `TermService` | Allows users to connect interactively to a remote computer. Remote Desktop and Remote Desktop Session Host Server depend on this service. To prevent remote use of this computer, clear the checkboxes on the Remote tab of the System properties control panel item. | Win32 Share Process (32) | RPCSS | C:\Windows\System32\svchost.exe -k NetworkService |
| `UmRdpService` | Allows the redirection of Printers/Drives/Ports for RDP connections | Win32 Share Process (32) | TermService, RDPDR | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `rdpbus` | Remote Desktop Device Redirector Bus Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rdpbus.sys |
| `RDPDR` | Remote Desktop Device Redirector Driver | Kernel Driver (1) | RDBSS | System32\drivers\rdpdr.sys |
| `terminpt` | Microsoft Remote Desktop Input Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\terminpt.sys |
| `TsUsbFlt` | Remote Desktop USB Hub Class Filter Driver | Kernel Driver (1) | - | system32\drivers\tsusbflt.sys |
| `TsUsbGD` | Remote Desktop Generic USB Device | Kernel Driver (1) | - | \SystemRoot\System32\drivers\TsUsbGD.sys |
| `tsusbhub` | Remote Desktop USB Hub | Kernel Driver (1) | - | \SystemRoot\System32\drivers\tsusbhub.sys |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure Solicited Remote Assistance](https://noverse.dev/policies?p=RemoteAssistance*RA_Solicit) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `fAllowToGetHelp`<br>`fAllowFullControl` |
| [Configure Offer Remote Assistance](https://noverse.dev/policies?p=RemoteAssistance*RA_Unsolicit) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `fAllowUnsolicited`<br>`fAllowUnsolicitedFullControl` |
| [Turn on session logging](https://noverse.dev/policies?p=RemoteAssistance*RA_Logging) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `LoggingEnabled` |
| [Allow only Windows Vista or later connections](https://noverse.dev/policies?p=RemoteAssistance*RA_EncryptedTicketOnly) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `CreateEncryptedOnlyTickets` |
| [Restrict Unauthenticated RPC clients](https://noverse.dev/policies?p=RPC*RpcRestrictRemoteClients) | `HKLM\Software\Policies\Microsoft\Windows NT\Rpc` | `RestrictRemoteClients` |
| [Don't allow this PC to be projected to](https://noverse.dev/policies?p=WirelessDisplay*AllowProjectionToPC) | `HKLM\Software\Policies\Microsoft\Windows\Connect` | `AllowProjectionToPC` |
| [Require pin for pairing](https://noverse.dev/policies?p=WirelessDisplay*RequirePinForPairing) | `HKLM\Software\Policies\Microsoft\Windows\Connect` | `RequirePinForPairing` |

# Deny App Access

Denies the access for everything, only leaving the microphone enabled. See JSON content below for details. Note `Deny 'User Info Access'` = prevents users from managing the ability to allow apps (not desktop apps) to access the user name, account picture, and domain information - this option doesn't get applied via the main option.

Adding the `Deny` data in `HKLM` is probably enough, but the keys also exist in `HKCU` - Windows only edits it in `HKLM`, examples:
```c
// Notifications
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\userNotificationListener\Value	Type: REG_SZ, Length: 10, Data: Deny

// Contacts
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\contacts\Value	Type: REG_SZ, Length: 10, Data: Deny

// Pictures
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\picturesLibrary\Value	Type: REG_SZ, Length: 10, Data: Deny
```

![](https://github.com/nohuto/win-config/blob/main/privacy/images/appaccess.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps access account information](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessAccountInfo) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessAccountInfo` |
| [Let Windows apps access the calendar](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessCalendar) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessCalendar` |
| [Let Windows apps access call history](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessCallHistory) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessCallHistory` |
| [Let Windows apps access the camera](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessCamera) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessCamera` |
| [Let Windows apps access contacts](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessContacts) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessContacts` |
| [Let Windows apps access email](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessEmail) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessEmail` |
| [Let Windows apps make use of Text and image generation features of Windows](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessSystemAIModels) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessSystemAIModels` |
| [Let Windows apps take screenshots of various windows or displays](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessGraphicsCaptureProgrammatic) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessGraphicsCaptureProgrammatic` |
| [Let Windows apps turn off the screenshot border](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessGraphicsCaptureWithoutBorder) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessGraphicsCaptureWithoutBorder` |
| [Let Windows apps access presence sensing](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessHumanPresence) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessHumanPresence` |
| [Let Windows apps access location](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessLocation) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessLocation` |
| [Let Windows apps access messaging](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessMessaging) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessMessaging` |
| [Let Windows apps access the microphone](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessMicrophone) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessMicrophone` |
| [Let Windows apps access motion](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessMotion) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessMotion` |
| [Let Windows apps access notifications](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessNotifications) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessNotifications` |
| [Let Windows apps make phone calls](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessPhone) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessPhone` |
| [Let Windows apps control radios](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessRadios) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessRadios` |
| [Let Windows apps communicate with unpaired devices](https://noverse.dev/policies?p=AppPrivacy*LetAppsSyncWithDevices) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsSyncWithDevices` |
| [Let Windows apps access Tasks](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessTasks) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessTasks` |
| [Let Windows apps access trusted devices](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessTrustedDevices) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessTrustedDevices` |
| [Let Windows apps access diagnostic information about other apps](https://noverse.dev/policies?p=AppPrivacy*LetAppsGetDiagnosticInfo) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsGetDiagnosticInfo` |
| [Let Windows apps access an eye tracker device](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessGazeInput) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessGazeInput` |
| [Let Windows apps activate with voice](https://noverse.dev/policies?p=AppPrivacy*LetAppsActivateWithVoice) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsActivateWithVoice` |
| [Let Windows apps activate with voice while the system is locked](https://noverse.dev/policies?p=AppPrivacy*LetAppsActivateWithVoiceAboveLock) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsActivateWithVoiceAboveLock` |
| [Let Windows apps access user movements while running in the background](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessBackgroundSpatialPerception) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessBackgroundSpatialPerception` |
| [User management of sharing user name, account picture, and domain information with apps (not desktop apps)](https://noverse.dev/policies?p=UserProfiles*UserInfoAccessAction) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowUserInfoAccess` |
| [Let Windows apps access cellular data](https://noverse.dev/policies?p=wwansvc*LetAppsAccessCellularData) | `HKLM\Software\Policies\Microsoft\Windows\WwanSvc\CellularDataAccess` | `LetAppsAccessCellularData` |

# Disable Startup ETS

"The AutoLogger event tracing session records events that occur early in the operating system boot process. Applications and device drivers can use the AutoLogger session to capture traces before the user logs in. Note that some device drivers, such as disk device drivers, are not loaded at the time the AutoLogger session begins."

See your current running ETS via `Performance Monitor > Data Collector Sets > Startup Event Trace Sessions`.

Logs are saved in:
```c
C:\WINDOWS\system32\Logfiles\WMI

// C:\Windows\System32\drivers\DriverData\LogFiles\WMI
// C:\PerfLogs\Admin
```

Removing all autologgers will cause issues, therefore it's not recommended to remove all of them.

## [Autologger Value Table](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/configuring-and-starting-an-autologger-session.md)

| Value | Type | Description | 
|-------|------|-------------|
| **BufferSize** | **REG_DWORD** | The size of each buffer, in kilobytes. Should be less than one megabyte. ETW uses the size of physical memory to calculate this value.|
| **ClockType** | **REG_DWORD** | The timer to use when logging the time stamp for each event. <br> - 1 = Performance counter value (high resolution)<br> - 2 = System timer<br> - 3 = CPU cycle counter <br> For a description of each clock type, see the **ClientContext** member of [WNODE_HEADER](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/wnode-header.md).<br> The default value is 1 (performance counter value) on Windows Vista and later. Prior to Windows Vista, the default value is 2 (system timer). | 
| **DisableRealtimePersistence** | **REG_DWORD** | To disable real time persistence, set this value to 1. The default is 0 (enabled) for real time sessions.<br> If real time persistence is enabled, real-time events that were not delivered by the time the computer was shutdown will be persisted. The events will then be delivered to the consumer the next time the consumer connects to the session. |
| **FileCounter** | **REG_DWORD** | Do not set or modify this value. This value is the serial number used to increment the log file name if **FileMax** is specified. If the value is not valid, 1 will be assumed.|
| **FileName** | **REG_SZ** | The fully qualified path of the log file. The path to this file must exist. The log file is a sequential log file. The path is limited to 1024 characters.<br> If **FileName** is not specified, events are written to `%WINDIR%\System32\LogFiles\WMI\\<sessionname>.etl`. |
| **FileMax** | **REG_DWORD** | The maximum number of instances of the log file that ETW creates. If the log file specified in **FileName** exists, ETW appends the **FileCounter** value to the file name. For example, if the default log file name is used, the form is `%WINDIR%\System32\LogFiles\WMI\\<sessionname>.etl.NNNN`. <br> The first time the computer is started, the file name is `<sessionname>.etl.0001`, the second time the file name is `<sessionname>.etl.0002`, and so on. If **FileMax** is 3, on the fourth restart of the computer, ETW resets the counter to 1 and overwrites `<sessionname>.etl.0001`, if it exists.<br> The maximum number of instances of the log file that are supported is 16.<br> Do not use this feature with the [EVENT_TRACE_FILE_MODE_NEWFILE](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md) log file mode.|
| **FlushTimer** | **REG_DWORD** | How often, in seconds, the trace buffers are forcibly flushed. The minimum flush time is 1 second. This forced flush is in addition to the automatic flush that occurs when a buffer is full and when the trace session stops. <br> For the case of a real-time logger, a value of zero (the default value) means that the flush time will be set to 1 second. A real-time logger is when **LogFileMode** is set to **EVENT_TRACE_REAL_TIME_MODE**.<br> The default value is 0. By default, buffers are flushed only when they are full. |
| **Guid** | **REG_SZ** | A string that contains a GUID that uniquely identifies the session. This value is required. | 
| **LogFileMode** | **REG_DWORD** | Specify one or more log modes. For possible values, see [Logging Mode Constants](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md). The default is **EVENT_TRACE_FILE_MODE_SEQUENTIAL**. Instead of writing to a log file, you can specify either **EVENT_TRACE_BUFFERING_MODE** or **EVENT_TRACE_REAL_TIME_MODE**.<br> Specifying **EVENT_TRACE_BUFFERING_MODE** avoids the cost of flushing the contents of the session to disk when the file system becomes available. <br> Note that using **EVENT_TRACE_BUFFERING_MODE** will cause the system to ignore the **MaximumBuffers** value, as the buffer size is instead the product of **MinimumBuffers** and **BufferSize**.<br> AutoLogger sessions do not support the **EVENT_TRACE_FILE_MODE_NEWFILE** logging mode.<br> If **EVENT_TRACE_FILE_MODE_APPEND** is specified, **BufferSize** must be explicitly provided and must be the same in both the logger and the file being appended.|
| **MaxFileSize** | **REG_DWORD** | The maximum file size of the log file, in megabytes. The session is closed when the maximum size is reached, unless you are in circular log file mode. To specify no limit, set value to 0. The default is 100 MB, if not set. The behavior that occurs when the maximum file size is reached depends on the value of **LogFileMode**.|
| **MaximumBuffers** | **REG_DWORD** | The maximum number of buffers to allocate. Typically, this value is the minimum number of buffers plus twenty. ETW uses the buffer size and the size of physical memory to calculate this value. This value must be greater than or equal to the value for **MinimumBuffers**.|
| **MinimumBuffers** | **REG_DWORD** | The minimum number of buffers to allocate at startup. The minimum number of buffers that you can specify is two buffers per processor. For example, on a single processor computer, the minimum number of buffers is two.|
| **Start** | **REG_DWORD** | To have the AutoLogger session start the next time the computer is restarted, set this value to 1; otherwise, set this value to 0.|
| **Status** | **REG_DWORD** | The startup status of the AutoLogger. If the AutoLogger failed to start, the value of this key is the appropriate Win32 error code. If the AutoLogger successfully started, the value of this key is **ERROR_SUCCESS** (0).|
| **Boot** | **REG_DWORD** | This feature should not be used outside of debugging scenarios.<br> If this registry key is set to 1, the autologger will be started earlier than normal during kernel initialization, allowing it to capture events during the initialization of many important kernel subsystems. However, enabling this option has a negative impact on boot times and imposes additional restrictions on the autologger. If this feature is enabled, the autologger session GUID must be populated, and many other autologger settings may not work. <br> This key is supported on Windows Server 2022 and later. |

# Disable Text Input Hosts

`ctfmon.exe` is the classic CTF (Collaborative Translation Framework) loader, it's started for the user at logon by `\Microsoft\Windows\TextServicesFramework\MsCtfMonitor`. It seems to handle [IME](https://learn.microsoft.com/en-us/windows/apps/develop/input/input-method-editors) (Input Method Editor) support, language/input profiles, language bar/input indicator, and [keyboard layout switching](https://noverse.dev/docs/win-config/peripheral/keyboard-values/). 

Note that renaming that binary will break input in of start menu/MS store/UWP apps etc.

`TextInputHost.exe` is the modern text input host (from `MicrosoftWindows.Client.CBS`), it seems to get used (on demand) through the `InputApp` registration when opening modern input parts such as `Win+.`, `Win+V`, touch keyboard, handwriting, voice typing, and so on.

# Disable Camera

Disallows the use of a camera on your system, by denying access via `LetAppsAccessCamera`/`AllowCamera`/services (and app permission).

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `FrameServer` | Enables multiple clients to access video frames from camera devices. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k Camera |
| `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k CameraMonitor |
| `StiSvc` | Provides image acquisition services for scanners and cameras | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k imgsvc |

## Suboption

### Disable Lock Screen Camera

> "*Disables the lock screen camera toggle switch in PC Settings and prevents a camera from being invoked on the lock screen.By default, users can enable invocation of an available camera on the lock screen.If you enable this setting, users will no longer be able to enable or disable lock screen camera access in PC Settings, and the camera cannot be invoked on the lock screen.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps access the camera](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessCamera) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessCamera` |
| [Allow Use of Camera](https://noverse.dev/policies?p=Camera*L_AllowCamera) | `HKLM\software\Policies\Microsoft\Camera` | `AllowCamera` |
| [Prevent enabling lock screen camera](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoLockScreenCamera) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoLockScreenCamera` |

# Disable Synchronization

When settings synchronization is turned on, a user's settings are synced across all Windows devices when they sign in with the same account.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not sync](https://noverse.dev/policies?p=SettingSync*DisableSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableSettingSync`<br>`DisableSettingSyncUserOverride` |
| [Do not sync app settings](https://noverse.dev/policies?p=SettingSync*DisableApplicationSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableApplicationSettingSync`<br>`DisableApplicationSettingSyncUserOverride` |
| [Do not sync passwords](https://noverse.dev/policies?p=SettingSync*DisableCredentialsSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableCredentialsSettingSync`<br>`DisableCredentialsSettingSyncUserOverride` |
| [Do not sync personalize](https://noverse.dev/policies?p=SettingSync*DisablePersonalizationSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisablePersonalizationSettingSync`<br>`DisablePersonalizationSettingSyncUserOverride` |
| [Do not sync Apps](https://noverse.dev/policies?p=SettingSync*DisableAppSyncSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableAppSyncSettingSync`<br>`DisableAppSyncSettingSyncUserOverride` |
| [Do not sync other Windows settings](https://noverse.dev/policies?p=SettingSync*DisableWindowsSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableWindowsSettingSync`<br>`DisableWindowsSettingSyncUserOverride` |
| [Do not sync desktop personalization](https://noverse.dev/policies?p=SettingSync*DisableDesktopThemeSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableDesktopThemeSettingSync`<br>`DisableDesktopThemeSettingSyncUserOverride` |
| [Do not sync browser settings](https://noverse.dev/policies?p=SettingSync*DisableWebBrowserSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableWebBrowserSettingSync`<br>`DisableWebBrowserSettingSyncUserOverride` |
| [Do not sync on metered connections](https://noverse.dev/policies?p=SettingSync*DisableSyncOnPaidNetwork) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableSyncOnPaidNetwork` |
| [Do not sync start settings](https://noverse.dev/policies?p=SettingSync*DisableStartLayoutSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableStartLayoutSettingSync`<br>`DisableStartLayoutSettingSyncUserOverride` |

# Disable Activity History

> "*Activity History shows a history of activities a user has performed and can even synchronize activities across multiple devices for the same user. Synchronization across devices only works when a user signs in with the same account. This feature is available in versions of Windows released prior to January 2024, and has been discontinued in new versions of Windows.*"

`EnableActivityFeed` enables or disables publishing and syncing of activities across devices. `PublishUserActivities` allows or blocks local publishing of user activities. `UploadUserActivities` allows or blocks uploading of user activities to the cloud, deletion is not affected.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enables Activity Feed](https://noverse.dev/policies?p=OSPolicy*EnableActivityFeed) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableActivityFeed` |
| [Allow publishing of User Activities](https://noverse.dev/policies?p=OSPolicy*PublishUserActivities) | `HKLM\Software\Policies\Microsoft\Windows\System` | `PublishUserActivities` |
| [Allow upload of User Activities](https://noverse.dev/policies?p=OSPolicy*UploadUserActivities) | `HKLM\Software\Policies\Microsoft\Windows\System` | `UploadUserActivities` |
| [Turn off storage and display of search history](https://noverse.dev/policies?p=Search*DisableSearchHistory) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\Explorer` | `DisableSearchHistory` |

# Disable File History

> "*File History automatically backs up versions of files in your user folders (Documents, Music, Pictures, Videos, Desktop) and offline OneDrive. It tracks changes via the NTFS change journal (fast, low overhead) and saves only changed files. You must choose a backup target (external drive or network share). If that target is unavailable, it caches copies locally and syncs them when the target returns. You can browse and restore any version or recover lost/deleted files.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off File History](https://noverse.dev/policies?p=FileHistory*DisableFileHistory) | `HKLM\Software\Policies\Microsoft\Windows\FileHistory` | `Disabled` |

# Disable MDM Enrollment

`DisableRegistration`:
> "*This policy setting specifies whether Mobile Device Management (MDM) Enrollment is allowed. When MDM is enabled, it allows the user to have the computer remotely managed by a MDM Server. If you do not configure this policy setting, MDM Enrollment will be enabled. If you enable this policy setting, MDM Enrollment will be disabled for all users. It will not unenroll existing MDM enrollments.If you disable this policy setting, MDM Enrollment will be enabled for all users.*"

`AutoEnrollMDM`:
> "*This policy setting specifies whether to automatically enroll the device to the Mobile Device Management (MDM) service configured in Azure Active Directory (Azure AD). If the enrollment is successful, the device will remotely managed by the MDM service. Important: The device must be registered in Azure AD for enrollment to succeed. If you do not configure this policy setting, automatic MDM enrollment will not be initiated. If you enable this policy setting, a task is created to initiate enrollment of the device to MDM service specified in the Azure AD. If you disable this policy setting, MDM will be unenrolled.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Disable MDM Enrollment](https://noverse.dev/policies?p=MDM*MDM_MDM_DisplayName) | `HKLM\Software\Policies\Microsoft\Windows\CurrentVersion\MDM` | `DisableRegistration` |
| [Enable automatic MDM enrollment using default Azure AD credentials](https://noverse.dev/policies?p=MDM*MDM_JoinMDM_DisplayName) | `HKLM\Software\Policies\Microsoft\Windows\CurrentVersion\MDM` | `AutoEnrollMDM`<br>`UseAADCredentialType`<br>`MDMApplicationId` |

# Disable Cortana

Cortana is [deprecated](https://support.microsoft.com/en-us/cortana/end-of-support-for-cortana) in W11 and is no longer the supported voice assistant.

> "*[Cortana](https://en.wikipedia.org/wiki/Cortana_(virtual_assistant)) was a virtual assistant developed by Microsoft that used the Bing search engine to perform tasks such as setting reminders and answering questions for users.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Cortana](https://noverse.dev/policies?p=Search*AllowCortana) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCortana` |
| [Allow Cortana above lock screen](https://noverse.dev/policies?p=Search*AllowCortanaAboveLock) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCortanaAboveLock` |
| [Allow search and Cortana to use location](https://noverse.dev/policies?p=Search*AllowSearchToUseLocation) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowSearchToUseLocation` |
| [Allow Cloud Search](https://noverse.dev/policies?p=Search*AllowCloudSearch) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCloudSearch` |
| [Allow Cortana Page in OOBE on an AAD account](https://noverse.dev/policies?p=Search*AllowCortanaInAAD) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search\AllowCortanaInAAD` | `AllowCortanaInAADPathOOBE` |

## Miscellaneous Notes
```c
"HKCU\Software\Microsoft\Windows\CurrentVersion\Cortana\DevOverrideOneSettings","Length: 16"
"HKCU\Software\Microsoft\Windows\CurrentVersion\Cortana\IsAvailable","Type: REG_DWORD, Length: 4, Data: 1"
```

# Disable DRM Internet Access

Prevents Windows Media Digital Rights Management (DRM) from accessing the Internet (or intranet). When enabled, Windows Media DRM is prevented from accessing the Internet (or intranet) for license acquisition and security upgrades. Secure content that is already licensed to the local computer will continue to play.

Means whenever you've DRM protected files, don't enable this option.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent Windows Media DRM Internet Access](https://noverse.dev/policies?p=WindowsMediaDRM*DisableOnline) | `HKLM\Software\Policies\Microsoft\WMDRM` | `DisableOnline` |

# Disable Sleep Study

Sleep Study tracks modern sleep states to analyze energy usage and pinpoint battery drain. It disables Sleep Study by making ETL logs read-only, disabling related diagnostics, and turning off the scheduled task.

```powershell
wevtutil sl Microsoft-Windows-SleepStudy/Diagnostic /e:false
svchost.exe	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-SleepStudy/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-Kernel-Processor-Power/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-Kernel-Processor-Power/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-UserModePowerService/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-UserModePowerService/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0
```

- [privacy/assets | sleepstudy-FxLibraryGlobalsQueryRegistrySettings.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/sleepstudy-FxLibraryGlobalsQueryRegistrySettings.c)
- [privacy/assets | sleepstudy-PoFxInitPowerManagement.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/sleepstudy-PoFxInitPowerManagement.c)

## Miscellaenous Notes

| Prefix | Component |
| --- | --- |
| `Pop` | Power Manager |

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "SleepstudyAccountingEnabled" = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit" = 3000; // SleepstudyHelperBlockerGlobalLimit (0x0BB8) 
    "SleepstudyLibraryBlockerLimit" = 200; // SleepstudyHelperBlockerLibraryLimit (0xC8) 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "SleepStudyDeviceAccountingLevel" = 4; // PopSleepStudyDeviceAccountingLevel 
    "SleepStudyDisabled" = 0; // PopSleepStudyDisabled 
```

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0010\3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDIF030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\Display\MSI3CB0\5&34f902e3&1&UID28931\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_149C&SUBSYS_87C01043&REV_00\4&231a312e&0&0341\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_43EE&SUBSYS_11421B21&REV_00\4&20e120c7&0&000A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_790E&SUBSYS_87C01043&REV_51\3&11583659&0&A3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_10DE&DEV_228B&SUBSYS_50521462&REV_A1\4&1d81e16&0&0119\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_8086&DEV_15F3&SUBSYS_87D21043&REV_02\6&102e3adf&0&0048020A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\CompositeBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\NdisVirtualBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\SYSTEM\0002\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\UMBUS\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\vdrvroot\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\VID\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2bce96aa&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2c35141&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot00\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot01\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot02\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot03\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot04\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot05\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot06\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_05E3&PID_0610\6&3365fbaf&0&11\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0B05&PID_1939&MI_00\7&40fe908&0&0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0CF2&PID_A102&MI_00\8&7b0cf2a&0&0000\Device Parameters\Wdf : SleepstudyState
```
```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : EnableNicAutoPowerSaverInSleepStudy
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : EnableNicAutoPowerSaverInSleepStudy
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Power : SleepStudyBufferSizeInMB
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Power : SleepStudyTraceDirectory
```

# Disable CSC

Disable Offline Files (CSC) via policy and services. Sets NetCache policy keys, disables `CSC`/`CscService`, disables the two `Offline Files` scheduled tasks (they're disabled by default), and renames `mobsync.exe` to block execution.

> "*Offline Files (Client-Side Caching, CSC) lets Windows cache files from network shares locally so users can keep working when the network/server is unavailable. Sync Center handles the background sync between the local CSC cache (`%WINDIR%\CSC`) and the share. It's commonly paired with Folder Redirection so "known folders" (e.g., Documents) live on a server but remain available offline, with options like "Always Offline" for performance on slow links. You enable/disable it via Sync Center (Control Panel) or policy. When disabled, Sync Center has nothing to sync.*"

- [folder-redirection/disable-offline-files-on-folders](https://learn.microsoft.com/en-us/windows-server/storage/folder-redirection/disable-offline-files-on-folders#windows-powershell-equivalent-commands) (todo)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow or Disallow use of the Offline Files feature](https://noverse.dev/policies?p=OfflineFiles*Pol_Enabled) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `Enabled` |
| [Turn off reminder balloons](https://noverse.dev/policies?p=OfflineFiles*Pol_NoReminders_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `NoReminders` |
| [Synchronize all offline files before logging off](https://noverse.dev/policies?p=OfflineFiles*Pol_SyncAtLogoff_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `SyncAtLogoff` |
| [Synchronize all offline files when logging on](https://noverse.dev/policies?p=OfflineFiles*Pol_SyncAtLogon_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `SyncAtLogon` |
| [Configure Background Sync](https://noverse.dev/policies?p=OfflineFiles*Pol_BackgroundSyncSettings) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `BackgroundSyncEnabled`<br>`BackgroundSyncPeriodMin`<br>`BackgroundSyncMaxStartMin`<br>`BackgroundSyncIgnoreBlockOutAfterMin`<br>`BackgroundSyncBlockOutStartTime`<br>`BackgroundSyncBlockOutDurationMin`<br>`BackgroundSyncEnabledForForcedOffline` |
| [Remove "Work offline" command](https://noverse.dev/policies?p=OfflineFiles*Pol_WorkOfflineDisabled_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `WorkOfflineDisabled` |

# Disable Cloud Content Search

> "*Cloud Content Search lets Windows Search include results from your signed-in cloud accounts personal Microsoft account (OneDrive, Outlook, Bing) and/or work/school (OneDrive for Business, SharePoint, Outlook) alongside local files. Turn it on per account to get those items and Bing-personalized suggestions, turn it off to keep search limited to local content (and non-personalized web).*"

![](https://github.com/nohuto/win-config/blob/main/privacy/images/cloudsearch.png?raw=true)

# Microsoft Accounts

> "*This setting prevents using the Settings app to add a Microsoft account for single sign-on (SSO) authentication for Microsoft services and some background services, or using a Microsoft account for single sign-on to other applications or services.*
>
> *There are two options if this setting is enabled:*  
> *- Users can't add Microsoft accounts means that existing connected accounts can still sign in to the device (and appear on the Sign in screen). However, users cannot use the Settings app to add new connected accounts (or connect local accounts to Microsoft accounts).*  
> *- Users can't add or log on with Microsoft accounts means that users cannot add new connected accounts (or connect local accounts to Microsoft accounts) or use existing connected accounts through Settings.*
>
> *This setting does not affect adding a Microsoft account for application authentication. For example, if this setting is enabled, a user can still provide a Microsoft account for authentication with an application such as Mail, but the user cannot use the Microsoft account for single sign-on authentication for other applications or services (in other words, the user will be prompted to authenticate for other applications or services).*"

```c
// This policy is disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 0

// Users can't add Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 1

// Users can't add or log on with Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 3
```

# Disable Font Providers

> "*This policy setting determines whether Windows is allowed to download fonts and font catalog data from an online font provider. If you enable this policy setting, Windows periodically queries an online font provider to determine whether a new font catalog is available. Windows may also download font data if needed to format or render text. If you disable this policy setting, Windows does not connect to an online font provider and only enumerates locally-installed fonts.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Font Providers](https://noverse.dev/policies?p=GroupPolicy*EnableFontProviders) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableFontProviders` |

# Disable Thumbnail Caching

Disables persistent File Explorer thumbnail caching so previews are less likely to remain stored after browsing folders. Windows normally rebuilds thumbnail caches automatically (use `Thumbnail Cache` option in 'Cleanup' section to clear it).

This improves privacy mainly by reducing leftover preview artifacts for images, videos, documents, and other shell items. Microsoft explicitly notes that the thumbnail cache can be read by everyone on shared or security sensitive systems, and the related network folder thumbnail policies note that allowing thumbnail use on network folders can expose computers to security risks.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off the caching of thumbnails in hidden thumbs.db files](https://noverse.dev/policies?p=Thumbnails*DisableThumbsDBOnNetworkFolders) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `DisableThumbsDBOnNetworkFolders` |
| [Turn off caching of thumbnail pictures](https://noverse.dev/policies?p=WindowsExplorer*NoCacheThumbNailPictures) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoThumbnailCache` |

# Disable Application Compatibility

Disables Windows Application Experience telemetry and compatibility components, Microsoft Compatibility Appraiser (including its daily task and `CompatTelRunner.exe`) and the Application Experience tasks. It reduces telemetry, and some attack surface, but removes most automatic compatibility checks, upgrade assessments and some app related backup/recovery features.

`DisableAPISamping`, `DisableApplicationFootprint`, `DisableInstallTracing`, `DisableWin32AppBackup` will only work on 24H2 and above.

Currently includes all existing tasks in `\\Microsoft\\Windows\\Application Experience\\` (LTSC IoT Enterprise 2024):
```c
"\\Microsoft\\Windows\\Application Experience\\MareBackup",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser Exp",
"\\Microsoft\\Windows\\Application Experience\\PcaPatchDbTask",
"\\Microsoft\\Windows\\Application Experience\\SdbinstMergeDbTask",
"\\Microsoft\\Windows\\Application Experience\\StartupAppTask"

//"\\Microsoft\\Windows\\Application Experience\\AitAgent",
//"\\Microsoft\\Windows\\Application Experience\\PcaWallpaperAppDetect",
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off SwitchBack Compatibility Engine](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffSwitchBack) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `SbEnable` |
| [Turn off Application Compatibility Engine](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffEngine) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableEngine` |
| [Turn off Program Compatibility Assistant](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffProgramCompatibilityAssistant_2) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisablePCA` |
| [Turn off Install Tracing](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffInstallTracing) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableInstallTracing` |
| [Turn off API Sampling](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffAPISamping) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableAPISamping` |
| [Turn off Application Footprint](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffApplicationFootprint) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableApplicationFootprint` |
| [Turn off compatibility scan for backed up applications](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffWin32AppBackup) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableWin32AppBackup` |
| [Detect compatibility issues for applications and drivers](https://noverse.dev/policies?p=pca*DisablePcaUIPolicy) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisablePcaUI` |

# Disable OneSettings Download

[Services Configuration](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#31-services-configuration) is used by Windows components and apps, such as the telemetry service, to dynamically update their configuration. If you turn off this service, apps using this service may stop working.

If enabled = "Windows will periodically attempt to connect with the OneSettings service to download configuration settings".

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable OneSettings Auditing](https://noverse.dev/policies?p=DataCollection*EnableOneSettingsAuditing) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `EnableOneSettingsAuditing` |
| [Disable OneSettings Downloads](https://noverse.dev/policies?p=DataCollection*DisableOneSettingsDownloads) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableOneSettingsDownloads` |

# Disable F1 Help Key

Works via killing `HelpPane.exe` (Help and Support Windows desktop application) which was the help component in `W8`/`W8.1`. The executeable still exists but calls to it will either start the `Get Started` application (if user is offline), or opens a browser instance and redirects the browser to an online topic. Note that `HelpPane` still handles the `F1` shortcut.

If the option is disabled, pressing `F1` on your desktop will take you to a search query like:

```powershell
https://www.bing.com/search?q=how+to+get+help+in+windows+11
```

# Disable Find My Device

> "*Find My Device is a feature that can help you locate your Windows 10 or Windows 11 device if it's lost or stolen. To use this feature, sign in to your device with a Microsoft account and make sure you're an administrator on it. This feature works when location is turned on for your device, even if other users on the device have turned off location settings for their apps. Any time you attempt to locate the device, users using the device will see a notification in the notification area.*
>
> *- This setting works for any Windows device, such as a PC, laptop, Surface, or Surface Pen. It needs to be turned on before you can use it.*  
> *- You can't use it with a work or school account, and it doesn't work for iOS devices, Android devices, or Xbox One consoles.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn On/Off Find My Device](https://noverse.dev/policies?p=FindMy*FindMy_AllowFindMyDeviceConfig) | `HKLM\SOFTWARE\Policies\Microsoft\FindMyDevice` | `AllowFindMyDevice` |

# Disable WMPlayer Telemetry

WMPlayer (Windows Media Player) sends player usage data by default, if using the "Recommended ". This option turns off the `Diagnistics and Feedback` option, use the suboptions for further configuration.

![](https://github.com/nohuto/win-config/blob/main/privacy/images/wmplayer.png?raw=true)

Note: I gathered all registry values via the legacy WMPlayer.

### setup_wm Capture

Registry values `setup_wm.exe` creates on first start, if unticking all options:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\AcceptedPrivacyStatement	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Setup\UserOptions\DesktopShortcut	SUCCESS	Type: REG_SZ, Length: 6, Data: no
HKCU\Software\Microsoft\MediaPlayer\Preferences\MetadataRetrieval	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SendUserGUID	SUCCESS	Type: REG_BINARY, Length: 1, Data: 00
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentAcquisition	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageTracking	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUMusic	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPictures	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUVideo	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPlaylists	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC3475	SUCCESS	Type: REG_BINARY, Length: 650, Data: 7A 01 00 00 00 00 00 00 04 00 04 00 01 02 1C 00
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC2475	SUCCESS	Type: REG_BINARY, Length: 3,056, Data: 3A 03 00 00 00 00 00 00 04 00 04 00 01 00 EF 01
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC2475	SUCCESS	Type: REG_BINARY, Length: 3,064, Data: 3B 03 00 00 00 00 00 00 04 00 04 00 01 00 F1 01
```

All queried values in the `Player` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\AlwaysOnTopVTenSkin	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\EnableScreensaver	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\AutoAddMusicToLibrary	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\AutoAddUNC	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\PromptLicenseBackup	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\ForceOnline	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\StopOnFastUserSwitch2	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageLoggerCategories	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Privacy` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\MetadataRetrieval	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SendUserGUID	Type: REG_BINARY, Length: 1, Data: 00
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentAcquisition	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableLicenseRefresh	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentDRMConfiguration	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\AcceptedPrivacyStatement	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\UsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\ForceUsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUMusic	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPictures	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUVideo	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPlaylists	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Performance` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DontUseFrameInterpolation	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseFullScrMS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DVDUseVMRFSCntrls	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\IgnoreAVSync	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Scrunch\WMVideo\DXVA	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DontUseFrameInterpolation	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseFullScrMS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DVDUseVMRFSCntrls	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseVMRFullScreenCntr	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\IgnoreAVSync	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Scrunch\WMVideo\DXVA	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseDefaultBufferTime	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\CustomBufferTime	Type: REG_DWORD, Length: 4, Data: 5000
HKCU\Software\Microsoft\MediaPlayer\Preferences\MaxBandwidth	Type: REG_DWORD, Length: 4, Data: 2147483647
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Network` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseUDP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseCustomUDPPort	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseMulticast	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseTCP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseHTTP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

## Suboptions

| Option | Description |
| ---- | ---- |
| `Disable History` | Disables storing and displaying a list of recent/frequently played music, videos, pictures, playlists (`UsageLoggerCategories` disables "Save recently used to the Jumplist instead of frequently used"). |
| `Prevent Send User ID` | Prevents sending a unique player ID to content providers. |
| `Disable Metadata Retrieval` | Disables displaying media information from the internet and updating music files by retrieving media info from the internet. |
| `Prevent Usage Rights Download` | Prevents downloading usage rights automatically when playing or syncing a file. |
| `Prevent Auto Clock` | Prevents setting the clock on devices automatically. |
| `Max Connection Speed` | Selects the `LAN (10 Mbps or more)` connection speed, which is the highest available. |
| `Prevent Frame Dropping` | Prevents dropping frames in order to keep audio and video synchronized. |
| `Disable Video Smoothing` | Disables the `Use video smoothing` option.|
| `Disable Multicast Streams` | Disallows the player from receiving multicast streams. |
| `Enable Screensaver` | Allows the screen saver to stay enabled during playback. |
| `Prevent Internet Connection` | Disables the `Connect to the Internet (overrides other commands)` option. |


## Miscellaneous Notes

```c
// Apps > Video playback

// Save network bandwidth by playing video at lower resolution
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\VideoSettings": "AllowLowResolution" = 0 // DWORD. 0 = Off (default), 1 = On

// Process video automatically to enhance it (depends on your device hardware)
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\VideoSettings": "EnableAutoEnhanceDuringPlayback" = 0 // DWORD, 0 = Off, 1 = On
```

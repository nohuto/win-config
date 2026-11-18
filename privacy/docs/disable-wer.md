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

[Error-Reporting.txt](https://github.com/nohuto/regkit/blob/main/assets/records/Error-Reporting.txt) shows all read values on boot (`\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting`) / [WER Settings](https://learn.microsoft.com/en-us/windows/win32/wer/wer-settings) for some details.

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

- [privacy/assets/pseudocode | timestamp-OsEventsTimestampInterval.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/timestamp-OsEventsTimestampInterval.c)

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

There're two values named [`CrashDumpEnabled.New`](https://github.com/nohuto/regkit/blob/main/assets/records/CrashControl.txt) & [`CrashDumpEnabled.Old`](https://github.com/nohuto/regkit/blob/main/assets/records/CrashControl.txt), I haven't looked into them yet, see this as note for future reference.

```
\Registry\Machine\SYSTEM\ControlSet001\Control\CrashControl : CrashDumpEnabled.New
\Registry\Machine\SYSTEM\ControlSet001\Control\CrashControl : CrashDumpEnabled.Old
```

- [privacy/assets/pseudocode | crashdmp.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/crashdmp.c)
- [decompiled-pseudocode | SecureDump_PrepareForInit.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/SecureDump_PrepareForInit.c)

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

- [privacy/assets/pseudocode | wer-PciGetSystemWideHackFlagsFromRegistry.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/wer-PciGetSystemWideHackFlagsFromRegistry.c)

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


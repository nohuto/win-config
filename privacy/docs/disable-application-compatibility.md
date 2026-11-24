# Disable Application Compatibility

Disables Windows Application Experience telemetry and compatibility components, Microsoft Compatibility Appraiser (including its daily task and `CompatTelRunner.exe`) and the Application Experience tasks. It reduces telemetry, and some attack surface, but removes most automatic compatibility checks, upgrade assessments and some app related backup/recovery features.

`DisableAPISamping`, `DisableApplicationFootprint`, `DisableInstallTracing`, `DisableWin32AppBackup` will only work on 24H2 and above.

Currently disables all eight tasks in `\Microsoft\Windows\Application Experience\` (not every build has all of them):
```c
"\\Microsoft\\Windows\\Application Experience\\MareBackup",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser Exp",
"\\Microsoft\\Windows\\Application Experience\\PcaPatchDbTask",
"\\Microsoft\\Windows\\Application Experience\\SdbinstMergeDbTask",
"\\Microsoft\\Windows\\Application Experience\\StartupAppTask",
"\\Microsoft\\Windows\\Application Experience\\AitAgent",
"\\Microsoft\\Windows\\Application Experience\\PcaWallpaperAppDetect"
```

The option doesn't set `DisableEngine` (Windows Server 2003 policy) or `SbEnable` (SwitchBack, W7), since no binary on W11 includes the names, neither do the W10 22H2. The only `AppCompat` policy that `kernel32.dll` & `basesrv.dll` still read is `VDMDisallowed`.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Program Compatibility Assistant](https://noverse.dev/policies?p=AppCompat*AppCompatTurnOffProgramCompatibilityAssistant_2) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisablePCA` |
| [Turn off Install Tracing](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffInstallTracing) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableInstallTracing` |
| [Turn off API Sampling](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffAPISamping) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableAPISamping` |
| [Turn off Application Footprint](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffApplicationFootprint) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableApplicationFootprint` |
| [Turn off compatibility scan for backed up applications](https://noverse.dev/policies?p=AppDeviceInventory*TurnOffWin32AppBackup) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisableWin32AppBackup` |
| [Detect compatibility issues for applications and drivers](https://noverse.dev/policies?p=pca*DisablePcaUIPolicy) | `HKLM\Software\Policies\Microsoft\Windows\AppCompat` | `DisablePcaUI` |

`DisablePcaUI = 1` = not configured, `PcaUtilityGetMachineGroupPolicy` (`pcasvc.dll`) returns 1 when the value is missing, and 1 is the policys enabled state, "the PCA is configured to detect failures". `DisablePCA = 1` disables the assistant off anyway, and the ADMX says this policy then has no effect.

```c
// PcaUtilityGetMachineGroupPolicy (23H2)

ValueW = RegGetValueW(
           HKEY_LOCAL_MACHINE,
           L"Software\\Policies\\Microsoft\\Windows\\AppCompat",
           L"DisablePcaUI",
           0x18u,
           0LL,
           &v4,
           &v5);
v2 = (unsigned int)v4;
if ( ValueW ) // value missing
  return 1;
return v2;
```


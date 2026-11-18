# USBHUB Values

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

## Registry Values

```c
// HUBREG_QueryGlobalHubValues
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\USBHUB\\hubg"; // g_HubGlobalKeyName
    "DisableSelectiveSuspendUI" = ?; // REG_DWORD
    "MsOsDescriptorMode" = ?; // REG_DWORD, range 0-2
    "EnableDiagnosticMode" = ?; // REG_DWORD
    "DisableOnSoftRemove" = 1; // REG_DWORD
    "DisableUxdSupport" = ?; // REG_DWORD
    "EnableExtendedValidation" = ?; // REG_DWORD
    "WakeOnConnectUI" = ?; // REG_DWORD, nonzero enables wake on connect UI ("This controls the UI check box 'Allow this device to wake the system'. Essentially this is control for the wake on connect feature.")
    "PreventDebounceTimeForSuperSpeedDevices" = ?; // REG_DWORD, nonzero enables extra debounce handling ("Checks if we need to give extra time to SuperSpeed devices before talking to them")

    // miscellaneous ones from GlobalUsbhubValues
    "UsbDebugModeEnable" = ?;
    "BreakOnHubException" = ?;
    "debuglevel" = ?;
    "DebugLogMask" = ?;
    "DebugLogEnable" = ?;
    "DisableHardReset" = ?;
    "BreakOnReplicant" = ?;
    "BreakOnEnumFailure" = ?;
    "UseIoErrorLog" = ?;
    "ForceResetOnResume" = ?;
    "DisableFastResume" = ?;
    "LogSize" = ?;
    "IdleTimeout" = ?;

// HUBREG_QueryGlobalUxdSettings (the defaults were taken from the W10 source)
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\policy"; // g_UxdGlobalSettingsKey (aRegistryMachin_12)
    "UxdGlobalDeleteOnShutdown" = 0; // REG_DWORD
    "UxdGlobalDeleteOnReload" = 0; // REG_DWORD
    "UxdGlobalDeleteOnDisconnect" = 0; // REG_DWORD
    "UxdGlobalEnable" = 0; // REG_DWORD

// HUBREG_QueryUxdDeviceKey / HUBREG_DeleteUxdDeviceKey
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\devices"; // g_UxdDeviceSettingsKey (aRegistryMachin_5)
    "%04X%04X%04X" = ?; // value name from VID/PID/REV

// HUBREG_GetUxdPnpValue
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\pnp"; // g_UxdGuidSettingsKey (aRegistryMachin_3)
    "{GUID}" = ?; // value name from RtlStringFromGUID
```

### RegistryMachin_* Keys

Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// usbhub.sys
aRegistryMachin_1 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\USBFN";
aRegistryMachin_2 = // doesn't exist
aRegistryMachin_3 = "HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\pnp";
aRegistryMachin_4 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\UsbLtm";
aRegistryMachin_5 = "HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\devices";
aRegistryMachin_6 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\AutomaticSurpriseRemoval";
aRegistryMachin_7 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\HardwareVerifier";
aRegistryMachin_8 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\Usb20HardwareLpm";
aRegistryMachin_9 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usbflags";
aRegistryMachin_10 = "HKLM\\SYSTEM\\CurrentControlSet\\Services\\USBHUB\\hubg";
aRegistryMachin_11 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\USB";
aRegistryMachin_12 = "HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\policy";
aRegistryMachin_13 = "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb";
```

```c
// USBHUB3.sys
aRegistryMachin = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Default"
aRegistryMachin_0 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip"
aRegistryMachin_1 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN"
aRegistryMachin_3 = "\\registry\\machine\\system\\currentcontrolset\\services\\usbhub\\uxd_control\\pnp" // g_UxdGuidSettingsKey
aRegistryMachin_4 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb\\UsbLtm" // g_UsbLtmKeyName
aRegistryMachin_5 = "\\registry\\machine\\system\\currentcontrolset\\services\\usbhub\\uxd_control\\devices" // g_UxdDeviceSettingsKey
aRegistryMachin_6 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb\\AutomaticSurpriseRemoval" // g_UsbAutomaticSurpriseRemovalKeyName
aRegistryMachin_7 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb\\HardwareVerifier" // g_HwVerifierKeyName
aRegistryMachin_8 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb\\Usb20HardwareLpm" // g_Usb20HardwareLpmKeyName
aRegistryMachin_9 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usbflags"
aRegistryMachin_10 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\USBHUB\\hubg" // g_HubGlobalKeyName
aRegistryMachin_11 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USB"
aRegistryMachin_12 = "\\registry\\machine\\system\\currentcontrolset\\services\\usbhub\\uxd_control\\policy" // g_UxdGlobalSettingsKey
aRegistryMachin_13 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb"
```

```c
// USBXHCI.sys
aRegistryMachin = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\\\LiveKernelReports"
aRegistryMachin_0 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usb\\HardwareVerifier" // g_HwVerifierKeyName
aRegistryMachin_1 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usbflags" // g_usbflagsKeyName
```


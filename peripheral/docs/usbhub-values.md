# USBHUB Values

## Registry Values

```c
// HUBREG_QueryGlobalHubValues (USBHUB3)
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\USBHUB\\hubg"; // g_HubGlobalKeyName
    "DisableSelectiveSuspendUI" = 0; // REG_DWORD, nonzero hides "Allow the computer to turn off this device to save power" on USB 2.0 hubs
    "MsOsDescriptorMode" = 0; // REG_DWORD
    "EnableDiagnosticMode" = 0; // REG_DWORD
    "DisableOnSoftRemove" = 1; // REG_DWORD
    "DisableUxdSupport" = 0; // REG_DWORD, nonzero = USBHUB3 ignores the uxd_control keys below
    "EnableExtendedValidation" = 0; // REG_DWORD
    "WakeOnConnectUI" = 0; // REG_DWORD, 1 = USB 2.0 hubs always arm wake on connect, 3 = hubs wake checkbox decides, 0 & 2 = off
    "PreventDebounceTimeForSuperSpeedDevices" = 0; // REG_DWORD, nonzero = SuperSpeed ports never wait the extra debounce time

    // usbhub.sys only
    "BreakOnEnumFailure" = 0;
    "BreakOnHubException" = 0;
    "BreakOnReplicant" = 0;
    "debuglevel" = 0;
    "DebugLogMask" = 0x3FFFF; // usbhub!UsbhLogMask
    "DisableFastResume" = 0;
    "DisableHardReset" = 0;
    "ForceResetOnResume" = 0;
    "IdleTimeout" = 25;
    "LogSize" = 2;
    "UsbDebugModeEnable" = 0;
    "UseIoErrorLog" = 0;

// HUBREG_QueryGlobalUxdSettings (USBHUB3)
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\policy"; // g_UxdGlobalSettingsKey
    "UxdGlobalDeleteOnShutdown" = 0; // REG_DWORD
    "UxdGlobalDeleteOnReload" = 0; // REG_DWORD
    "UxdGlobalDeleteOnDisconnect" = 0; // REG_DWORD
    "UxdGlobalEnable" = 0; // REG_DWORD

// HUBREG_QueryUxdDeviceKey / HUBREG_DeleteUxdDeviceKey
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\devices"; // g_UxdDeviceSettingsKey
    "%04X%04X%04X" = ?; // value name from VID/PID/REV

// HUBREG_GetUxdPnpValue
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\pnp"; // g_UxdGuidSettingsKey
    "{GUID}" = ?; // value name from RtlStringFromGUID
```

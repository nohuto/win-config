# USB Values

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

## Registry Values

```c
// HUBREG_QueryGlobalUsb20HardwareLpmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\Usb20HardwareLpm"; // g_Usb20HardwareLpmKeyName
    "Usb20HardwareLpmOverride" = 1; // REG_DWORD
    "Usb20HardwareLpmTimeout" = 2; // REG_DWORD, range 0-255

// HUBREG_OpenQueryAttemptRecoveryFromUsbPowerDrainValue
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\AutomaticSurpriseRemoval"; // g_UsbAutomaticSurpriseRemovalKeyName (aRegistryMachin_6)
    "AttemptRecoveryFromUsbPowerDrain" = 0; // REG_DWORD, is used to stop USB devices when your screen is off, obviously only for laptop users

// HUBREG_QueryUsbHardwareVerifierValue
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\HardwareVerifier"; // g_HwVerifierKeyName
    "<VID><PID><REV>\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, first query
    "<VID><PID>\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, fallback
    "global\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, last fallback

// HUBREG_QueryGlobalUsbLtmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\UsbLtm"; // g_UsbLtmKeyName
    "UsbLtmEnable" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\USB";
    "DualRoleFeaturesTestOverride" = ?; // REG_DWORD
    "UcmIsPresent" = ?; // REG_DWORD

// these are taken from the W10 source, they seem to exist on latest builds (they do exist in usbport.sys on 23H2)

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usb";
    "debuglevel" = 0; // REG_DWORD
    "debuglogmask" = 0xFFFFFFFE; // REG_DWORD
    "debuglogenable" = 1; // REG_DWORD (bool)
    "debugcatc" = 0; // REG_DWORD (bool)
    "DisableSelectiveSuspend" = 0; // REG_DWORD (bool)
    "DisableCcDetect" = 0; // REG_DWORD (bool
    "EnPMDebug" = 0; // REG_DWORD (bool), for debugging power management
    "ForceHcD3NoWakeArm" = 0 // REG_DWORD (bool)
    "EnableDCA" = 0 // REG_DWORD (bool), DCA = direct controller access
    "ForcePortsHighSpeed" = 0; // REG_DWORD (bool), forces ports to stay under EHCI

// "This class is reserved for USB host controllers and USB hubs", I'll add them here as they're also in usbport.sys and also taken from the W10 source

"HKLM\\System\\CurrentControlSet\\Control\\Class\\{36FC9E60-C465-11CF-8056-444553540000}\\<instance>";
    "HcFlavor" = ? // REG_DWORD
    "TotalBusBandwidth" = ? // REG_DWORD
    "HcDisableAllSelectiveSuspend" = 0 (non-IA64), 1 (IA64); // REG_DWORD
    "CommonBuffer2GBLimit" = 0; // REG_DWORD, when nonzero, forces common buffers below 2GB ("Limit common buffer allocations for the miniport to the physical address range below 2GB.  Only bits 0 through 30 of the physical address can be set.  Bit 31 of the physical address cannot be set.")
    "ForceHCResetOnResume" = 0; // REG_DWORD, forces controller reset on resume
    "FastResumeEnable" = 0; // REG_DWORD, fast S0 resume

    //HcDisableSelectiveSuspend

// miscellaneous note for future reference
"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip" // UsbhUpdateRegSurpriseRemovalCount
    "BootPathSurpriseRemovalCount" = ?;
```

### RegistryMachin_* Keys

These are from `usbhub.sys`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

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

## Miscellaneous Notes

[`AttemptRecoveryFromUsbPowerDrain`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBHUB3/HUBREG_OpenQueryAttemptRecoveryFromUsbPowerDrainValue.c) is used to stop USB devices when your screen is off, obviously only for laptop users.

```
Stop USB devices when my screen is off to help battery.
```
`Bluetooth & devices` > `USB` > `USB battery saver`


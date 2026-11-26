# USB Values

## Registry Values

```c
// HUBREG_QueryGlobalUsb20HardwareLpmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\Usb20HardwareLpm"; // g_Usb20HardwareLpmKeyName
    "Usb20HardwareLpmOverride" = 1; // REG_DWORD
    "Usb20HardwareLpmTimeout" = 2; // REG_DWORD, range 0-255

// HUBREG_OpenQueryAttemptRecoveryFromUsbPowerDrainValue
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\AutomaticSurpriseRemoval"; // g_UsbAutomaticSurpriseRemovalKeyName (aRegistryMachin_6)
    "AttemptRecoveryFromUsbPowerDrain" = 1; // REG_DWORD, nonzero = hubs idle in the Modern Standby low power epoch and a device that blocks DRIPS for 30 s is stopped, Settings "USB battery saver"

// HUBREG_QueryUsbHardwareVerifierValue (USBHUB3), Controller_PopulateHardwareVerifierFlags (USBXHCI)
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\HardwareVerifier\\<id>\\usbUpto20|usb2X|usb30"; // g_HwVerifierKeyName
    "device" = 0; // 4 bytes
    "hub" = 0; // 4 bytes

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\HardwareVerifier\\<vvvvddddrr>\\xHCI10|xHCI96"; // USBXHCI
    "controller" = 0; // 8 bytes

// HUBREG_QueryGlobalUsbLtmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\UsbLtm"; // g_UsbLtmKeyName
    "UsbLtmEnable" = 0; // REG_DWORD, nonzero = USBHUB3 enables LTM (latency tolerance messaging) for devices that support it

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\USB";
    "DualRoleFeaturesTestOverride" = ?; // REG_DWORD
    "UcmIsPresent" = ?; // REG_DWORD

// these are for USB 2.0 (EHCI, OHCI, UHCI controllers)

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usb";
    "DisableCcDetect" = 0; // REG_DWORD
    "DisableSelectiveSuspend" = 0; // REG_DWORD, nonzero = disables selective suspend & usbhub hides the hubs "Allow the computer to turn off this device to save power"
    "EnableDCA" = 0; // REG_DWORD, DCA = direct controller access
    "EnPMDebug" = 0; // REG_DWORD, for debugging power management
    "ForceHcD3NoWakeArm" = 0; // REG_DWORD
    "ForcePortsHighSpeed" = 0; // REG_DWORD, forces ports to stay under EHCI

// "This class is reserved for USB host controllers and USB hubs", usbport.sys reads these from the controllers driver key

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{36FC9E60-C465-11CF-8056-444553540000}\\<instance>";
    "CommonBuffer2GBLimit" = 0; // REG_DWORD, when nonzero, forces common buffers below 2GB ("Limit common buffer allocations for the miniport to the physical address range below 2GB.  Only bits 0 through 30 of the physical address can be set.  Bit 31 of the physical address cannot be set.")
    "FastResumeEnable" = 0; // REG_DWORD, fast S0 resume
    "ForceHCResetOnResume" = 0; // REG_DWORD, forces controller reset on resume
    "HcDisableAllSelectiveSuspend" = 0; // REG_DWORD, nonzero = no selective suspend for controller
    "HcFlavor" = ?; // REG_DWORD
    "TotalBusBandwidth" = ?; // REG_DWORD

// miscellaneous note for future reference
"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip" // UsbhUpdateRegSurpriseRemovalCount
    "BootPathSurpriseRemovalCount" = ?;
```

### RegistryMachin_* Keys

Absolute registry key strings of `usbhub.sys`, `USBHUB3.sys`, `USBXHCI.sys`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// usbhub.sys
"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USB"
"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN"
"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Configurations\\"
"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Default"
"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip"
"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usbflags"
"\\registry\\machine\\system\\currentcontrolset\\services\\usbhub\\uxd_control\\devices\\"
// hubg: built from the driver's registry path (Services\usbhub) + "\\hubg" in UsbhRegDriverEntry
```

```c
// USBHUB3.sys
aRegistryMachin = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Default"
aRegistryMachin_0 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip"
aRegistryMachin_1 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN"
"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\USBFN\\Configurations\\" // no IDA name in this list
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

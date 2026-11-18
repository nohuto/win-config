# USBFlags Values

Value names in [`HUBREG_QueryUsbflagsValuesForDevice.c`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBHUB3/HUBREG_QueryUsbflagsValuesForDevice.c) are mostly UNICODE_STRING globals, the names below are resolved from `dq offset ; "Name"`. The usbflags device key base path is `HKLM\SYSTEM\CurrentControlSet\Control\usbflags` (from `LRegistryMachineSystemCurrentControlSetControlusbflags` in `HUBREG_OpenCreateUsbflagsDeviceKey`).

## Registry Values

`HUBDSM_QueryingRegistryValuesForDevice` -> `HUBMISC_QueryAndCacheRegistryValuesForDevice` -> `HUBREG_QueryUsbflagsValuesForDevice`

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

The value type isn't enforced, so both `REG_DWORD` and `REG_BINARY` should work if they're a 4 byte nonzero value (that's my current assumption). I would personally use `REG_BINARY` instead of `REG_DWORD` for now, as for example `osvc`, `IgnoreHWSerNum`, `ResetOnResume` are `REG_BINARY` ([usb-device-specific-registry-settings.md](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-device-specific-registry-settings)).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usbflags";
    "Allow64KLowOrFullSpeedControlTransfers" = ?; // REG_DWORD, only exactly 1 enables
    "DisableHCS0Idle" = 0; // REG_DWORD
    "GenericCompositeUSBDeviceString" = ?; // REG_SZ
    "SetMultiTTBitDuringConfigureEndpoint" = ?; // REG_DWORD
    "TestRunEsmInWorkItem" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usbflags\\<vvvvpppprrrr>";
    "IgnoreHWSerNum" = ?; // REG_BINARY, Indicates whether the USB driver stack must ignore the serial number of the device.
                          // 0x00: The setting is disabled.
                          // 0x01: Forces the USB driver stack to ignore the serial number of the device. Therefore, the device instance is tied to the port to which the device is attached.
    "UseWin8DescriptorValidation" = ?;
    "ResetOnResume" = ?; // REG_BINARY, indicates whether the USB driver stack must reset the device when the port resumes from a sleep cycle.
                         // 0x0000: The setting is disabled.
                         // 0x0001: Forces the USB driver stack to reset a device on port resume.
    "DisableOnSoftRemove" = 1;
    "RequestConfigDescOnReset" = ?;
    "DisableRecoveryFromPowerDrain" = ?;
    "DisableLpm" = ?; // When enabled LPM (link power management) is disabled for the device.
                      // "A link enters a low power state (consuming less power than the working state) only when the downstream device enters the suspended state through the selective suspend mechanism", "After remaining idle for a certain period of time, link partners progressively enter U1 (standby with fast exit) and then U2 (standby with slower exit)"
                      // https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-3-0-lpm-mechanism- https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/u1-and-u2-transitions
    "SkipBOSDescriptorQuery" = ?;
    "AlternateSettingFilter" = ?; // REG_BINARY
    "ResetTTOnCancel" = ?; // REG_DWORD
    "NoClearTTBufferOnCancel" = ?; // REG_DWORD, has priority over ResetTTOnCancel
    "PowerUpDelay" = ?; // REG_DWORD?

    "osvc" = ?; // REG_BINARY, "Indicates whether the operating system queried the device for Microsoft-defined USB descriptors. If the previously attempted OS descriptor query was successful, the value contains the vendor code from the OS string descriptor."
                // 0x0000: The device didn't provide a valid response to the Microsoft OS string descriptor request.
                // 0x01xx: The device provided a valid response to the Microsoft OS string descriptor request, where xx is the bVendorCode contained in the response.
    "SkipContainerIdQuery" = ?;
    "MsOs20DescriptorSetInfo" = ?;

    //"DontSkipMsOsDescriptor"
    //"IgnoreBOSDescriptorValidationFailure"
    //"SkipSetSel"
    //"ResetOnResumeInSuperSpeed"
    //"AllowInvalidPipeHandles"
    //"DisableUASP"
    //"SkipSetIsochDelay"
    //"ResetOnResumeS0"
    //"DisableHotReset"
    //"NonFunctional"
    //"DisableUsb20HardwareLpm"
    //"DisableRemoteWakeForUsb20HardwareLpm"
    "DisableSuperSpeed" // "There are certains hubs that we just don't want to support as they are too buggy. We will completely disable SuperSpeed for them."
    //"IncompatibleWithWindows"
    //"DisableFastEnumeration"
    //"AddControllerSuffixedCompatIdToAudioDevices"
    //"AddMausbSuffixToHardwareId"
    //"EnablePLDRDuringCyclePort"
    //"ResetOnErrorInD2Resume"
```

### USB_DEVICE_HACKS

You can use [`!usb3kd.device_info`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-usb3kd-device-info) to get more information on a USB device in the USB 3.0 tree, example:

```c
lkd> !usb3.usb_tree

4) !device_info 0xffffb009127ca1f0, !devstack ffffb009127e1d80
    Current Device State: ConfiguredInD0
    Desc: USB Receiver
    USB\VID_046D&PID_C547&REV_0402 Logitech Inc.
    !ucx_device 0xffffb009127cad00 !xhci_deviceslots 0xffffb0090bc17db0 1 !xhci_info 0xffffb0090bc17db0

lkd> !usb3kd.device_info 0xffffb009127ca1f0

U1Timeout: 0, U2Timeout: 0
DeviceFlags: DeviceIsComposite MsOsDescriptorNotSupported UsbWakeupSupport 
DeviceStateFlags: DeviceAttachSuccessful DeviceIsKnown ConfigurationIsValid ConfigDescIsValid 
                  DeviceStarted InstallMSOSExtEventProcessed IsNative 
DeviceHackFlags: DisableOnSoftRemove DisableLpm
```
The `DisableLpm` DeviceHackFlags exists if the value is set (DisableLPM).

You can see existing `_USB_DEVICE_HACKS` using the dt command:
```c
lkd> .load usb3kd
lkd> dt USBHUB3!_USB_DEVICE_HACKS
   +0x000 AsUlong32        : Uint4B
   +0x000 DisableSerialNumber : Pos 0, 1 Bit
   +0x000 DontSkipMsOsDescriptor : Pos 1, 1 Bit
   +0x000 ResetOnResumeSx  : Pos 2, 1 Bit
   +0x000 DisableOnSoftRemove : Pos 3, 1 Bit
   +0x000 RequestConfigDescOnReset : Pos 4, 1 Bit
   +0x000 SkipContainerIdQuery : Pos 5, 1 Bit
   +0x000 IgnoreBOSDescriptorValidationFailure : Pos 6, 1 Bit
   +0x000 DisableLpm       : Pos 7, 1 Bit
   +0x000 SkipSetSel       : Pos 8, 1 Bit
   +0x000 ResetOnResumeInSuperSpeed : Pos 9, 1 Bit
   +0x000 AllowInvalidPipeHandles : Pos 10, 1 Bit
   +0x000 DisableUASP      : Pos 11, 1 Bit
   +0x000 SkipSetIsochDelay : Pos 12, 1 Bit
   +0x000 ResetOnResumeS0  : Pos 13, 1 Bit
   +0x000 DisableHotReset  : Pos 14, 1 Bit
   +0x000 SkipBOSDescriptorQuery : Pos 15, 1 Bit
   +0x000 NonFunctional    : Pos 16, 1 Bit
   +0x000 DisableUsb20HardwareLpm : Pos 17, 1 Bit
   +0x000 DisableRemoteWakeForUsb20HardwareLpm : Pos 18, 1 Bit
   +0x000 DisableSuperSpeed : Pos 19, 1 Bit
   +0x000 IncompatibleWithWindows : Pos 20, 1 Bit
   +0x000 UseWin8DescriptorValidation : Pos 21, 1 Bit
   +0x000 DisableFastEnumeration : Pos 22, 1 Bit
   +0x000 DisableRecoveryFromPowerDrain : Pos 23, 1 Bit
   +0x000 AddControllerSuffixedCompatIdToAudioDevices : Pos 24, 1 Bit
   +0x000 AddMausbSuffixToHardwareId : Pos 25, 1 Bit
   +0x000 EnablePLDRDuringCyclePort : Pos 26, 1 Bit
   +0x000 ResetOnErrorInD2Resume : Pos 27, 1 Bit
```

### [Subkey Structure](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-device-specific-registry-settings)

The subkeys in `usbflags` always have a length of 12, build in such a structure `vvvvpppprrrr`:
- **vvvv** is a 4-digit hexadecimal number that identifies the vendor
- **pppp** is a 4-digit hexadecimal number that identifies the product
- **rrrr** is a 4-digit hexadecimal number that contains the revision number of the device

The vendor ID, product ID, and revision number values are obtained from the [USB device descriptor](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-device-descriptors). The USB_DEVICE_DESCRIPTOR structure describes a device descriptor.

| Registry entry | Description | Possible values |
|---|---|---|
| **osvc**<br><br>REG_BINARY | Indicates whether the operating system queried the device for [Microsoft-defined USB descriptors](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/microsoft-defined-usb-descriptors). If the previously attempted OS descriptor query was successful, the value contains the vendor code from the OS string descriptor. | <ul><li>0x0000: The device didn't provide a valid response to the Microsoft OS string descriptor request.</li><li>0x01xx: The device provided a valid response to the Microsoft OS string descriptor request, where xx is the **bVendorCode** contained in the response.</li></ul> |
| **IgnoreHWSerNum**<br><br>REG_BINARY | Indicates whether the USB driver stack must ignore the serial number of the device. | <ul><li>0x00: The setting is disabled.</li><li>0x01: Forces the USB driver stack to ignore the serial number of the device. Therefore, the device instance is tied to the port to which the device is attached.</li></ul> |
| **ResetOnResume**<br><br>REG_BINARY | Indicates whether the USB driver stack must reset the device when the port resumes from a sleep cycle. | <ul><li>0x0000: The setting is disabled.</li><li>0x0001: Forces the USB driver stack to reset a device on port resume.</li></ul> |

```
\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags\<vvvvpppprrrr> : ResetOnResume
\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags\<vvvvpppprrrr> : IgnoreHWSerNum
\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags\<vvvvpppprrrr> : osvc
```

`IgnoreHWSerNum<vvvvpppp>` exists in [`\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags`](https://github.com/nohuto/regkit/blob/main/assets/records/USB-Flags.txt) too.

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


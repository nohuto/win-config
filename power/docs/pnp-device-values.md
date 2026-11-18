# PnP Device Values

This currently applies the values for the `USB` enumerator only, since most values were found in USB related drivers and kind of all of them (which I use in the option) only get read in the USB enumerator.

Disables USB selective suspend, idle states, and related LP features if supported.

## Registry Values

Windows Plug and Play (PnP) creates a device node (devnode) for each detected device instance ("The PnP manager is the primary component involved in supporting the ability of Windows to recognize and adapt to changing hardware configurations."). In WinDbg (`!devnode`), `InstancePath` assigns to the device instance key under:
```c
HKLM\SYSTEM\CurrentControlSet\Enum\<enumerator>\<deviceID>\<instanceID>

// miscellaneous notes
HKLM\SYSTEM\CurrentControlSet\Enum // hardware instance key - per-device-instance data
HKLM\SYSTEM\CurrentControlSet\Control\Class\{ClassGUID} // class key - class-wide settings and optional class filters
HKLM\SYSTEM\CurrentControlSet\Services\<ServiceName> // software key - service/driver configuration for the function or filter driver
```

### Common Subkeys under `<instanceID>`

- `Device Parameters`: Per-instance parameters and state used by the drivers in the stack
- `Properties`: Device property store for this instance
- `LogConf` (optional): Resource configuration data for the instance
- `Control` (optional): Additional PnP/device state

Not every instance has the same subkeys or values. I won't add details on the PnP manager here, as that's not the purpose of the option. For more details, read [Windows Internals E7, P1](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf), Chapter 6 (`The Plug and Play manager`).

### Default Data

One thing to point out here is that there're two APIs which I almost didn't notice. [`IoOpenDeviceRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendeviceregistrykey) & `PLUGPLAY_REGKEY_DEVICE` opens the per-device-instance hardware key in the `Enum` branch (`HKLM\SYSTEM\CCS\Enum\<Enumerator>\<DeviceID>\<InstanceID>\Device Parameters`). [`IoOpenDriverRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey) opens the per-driver-service key in the `Services` branch (`HKLM\SYSTEM\CCS\Services\<ServiceName>\Parameters`). See [power/assets/pseudocode/pnp](https://github.com/nohuto/win-config/tree/main/power/assets/pseudocode/pnp) for all used functions.

A simple example here would be [GetEnhancedVerifierOptions](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/Wdf01000/GetEnhancedVerifierOptions.c) which uses `IoOpenDriverRegistryKey` and as you can see in a boot trace, `EnhancedVerifierOptions` is used in for example `\Registry\Machine\SYSTEM\ControlSet001\Services\PEAUTH\Parameters\Wdf : EnhancedVerifierOptions`.

`INF default` = install-time default from INF entries.

To create this list, I've used many driver pseudocodes (usbhub, winhub, acpi, pci, wdf, hidclass, USBHUB3...), several INF files, and W10 source for comments (which may not be accurate anymore).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters";
    "AllowIdleIrpInD3" = 1; // REG_DWORD (bool), INF default (input.inf)
    "CollectionReenumerateSelfInterfaceEnabled" = 0; // REG_DWORD (bool)
    "ComboHardwareIdV2Enabled" = 0; // REG_DWORD (bool)
    "CyclePortEnabled" = 0; // REG_DWORD (bool)
    "D3ColdReconnectTimeout" = 1000; // REG_DWORD
    "DefaultIdleState" = 1; // REG_DWORD (bool), "This registry value sets the default value of the AUTO_SUSPEND power policy setting. This registry key is used to enable or disable selective suspend when a handle isn't open to the device. A value of zero or the absence of this value indicates that by default, the device isn't suspended when idle. The device be allowed to suspend when idle only when the AUTO_SUSPEND power policy is enabled. A nonzero value indicates that by default the device can be suspended when idle. This value is ignored if DeviceIdleEnabled isn't set."
    "DefaultIdleTimeout" = 5000/30000; // REG_DWORD, the USBCCID UM driver uses 5sec, devices that support MTP use 30sec? (UsbccidDriver, wpdmtp) "This registry value sets the default state of the SUSPEND_DELAY power policy setting. The value indicates the amount of time in milliseconds to wait before determining that a device is idle."
    "DeviceIdleEnabled" = 1; // REG_DWORD (bool), ^ "This registry value indicates whether the device is capable of being powered down when idle (Selective Suspend)."
    "DeviceIdleIgnoreWakeEnable" = 1; // REG_DWORD (bool), ^ "When set to a nonzero value, it suspends the device even if it doesn't support RemoteWake."
    "DeviceInterfaceGUID" = "{52783fc2-0179-4eca-bb46-128bba61975e}"; // REG_SZ, written if missing by HUBREG_SetWinUsbIdleDefaults, WinUSB_GetRegParams uses it as fallback when DeviceInterfaceGUIDs is unavailable
    "DeviceInterfaceGUIDs" = "{...}"; // REG_MULTI_SZ, WinUSB example: {F72FE0D4-CBCB-407d-8814-9ED673D0DD6B}
    "DevicePowerUpOnS0Entry" = 1; // REG_DWORD, when 1 = "Always enter D0 upon resume from sleep regardless of IdleInWorkingState of its power policy owner"
    "DeviceResetNotificationEnabled" = 1; // REG_DWORD, INF default (input.inf, hidi2c.inf, hidspi_km.inf, hidvhf.inf)
    "DeviceSelectiveSuspended" = ?; // "Update Registry that this device has tried to selective Suspend."
    "EndpointPriorities" = ?; // validated by HUBREG_ValidateAndPopulateEndpointPriorities?
    "EnhancedPowerManagementEnabled" = 1; // REG_DWORD (bool)
    "EnhancedPowerManagementUseMonitor" = ?; // REG_DWORD (bool), read only when EnhancedPowerManagementEnabled is set to 1
    "ExtPropDescSemaphore" = 1; // REG_DWORD, written by HUBMISC_SetExtPropDescSemaphoreInRegistry, query path also checks RevisionId/VendorRevision, "Writes the "ExtPropDescSemaphore" registry flag to the device's hardware key to indicate that the device does not need to be queried for MS OS Extended Property Descriptors in the future.", "We only care whether or not it already exists, not what data it has."
    "ForceSelectiveSuspend" = ?; // REG_DWORD (bool?), from BthUsb_QuerySelectiveSuspend
    "FriendlyName" = ?; // REG_SZ
    "LegacyTouchScaling" = 0; // REG_DWORD, INF default (input.inf)
    "RemoteWakeEnabled" = ?; // REG_DWORD (bool)
    "ResetPortEnabled" = 0; // REG_DWORD (bool)
    "RetainWWIrpWhenDeviceAbsent" = 0; // REG_DWORD (bool)
    "RevisionId" = ; // REG_DWORD
    "SelectiveSuspendEnabled" = 0/1; // REG_DWORD/REG_BINARY (bool), INF has both, 0 in default install, 1 in selective-suspend opt-in (unsure when DWORD/BINARY is used, but when searching for the value in the standart hives via regkit you can see that it uses both types)
    "SelectiveSuspendOn" = 1; // REG_DWORD (bool)
    "SelectiveSuspendSupported" = ?; // REG_DWORD (bool?), from BthUsb_QuerySelectiveSuspend
    "SelectiveSuspendTimeout" = 5000; // REG_DWORD
    "SelSuspCancelBehavior" = ?; // REG_DWORD (bool)
    "SessionSecurityEnabled" = ?; // REG_DWORD (bool)
    "SuppressInputInCS" = 0; // REG_DWORD (bool), clears WakeScreenOnInputSupport when enabled?
    "SystemInputSuppressionEnabled" = 1; // REG_DWORD (bool)
    "SystemWakeEnabled" = 1; // REG_DWORD (bool), "This value indicates whether the device should be allowed to wake the system from a low power state. A value of zero, or the absence of this value indicates that the device isn't allowed to wake the system. To allow a device to wake the system, set SystemWakeEnabled to a nonzero value. A check box in the device Properties page is automatically enabled so that the user can override the setting."
    "TestIdleMonitorDim" = 1000; // REG_DWORD
    "TestIdleTimeoutNoHandles" = 1000; // REG_DWORD
    "TestIdleTimeoutNoHandlesInitial" = 5000; // REG_DWORD
    "UserSetDeviceIdleEnabled" = 1; // REG_DWORD (bool) "This registry value indicates whether a check box should be enabled in the device Properties page that allows a user to override the idle defaults. When UserSetDeviceIdleEnabled is set to a nonzero value the check box is enabled and the user can disable powering down the device when idle. A value of zero, or the absence of this value indicates that the check box isn't enabled. The UserSetDeviceIdleEnabled is ignored if DeviceIdleEnabled isn't set."
    "VendorRevision" = ; // REG_DWORD
    "WakeScreenOnInputSupport" = 1; // REG_DWORD (bool)
    "WakeScreenOnInputTimeout" = ?; // REG_DWORD, queried only when WakeScreenOnInputSupport is enabled
    "WinRtInterfaceRestrictionLevel" = 255; // REG_DWORD, fallback 255, accepts 0/1, if >1 = 0
    "WinusbIsochUsed" = 0; // REG_DWORD
    "WinUsbPowerPolicyOwnershipDisabled" = 1; // REG_DWORD (bool)
    "WriteReportExSupported" = 1; // REG_DWORD

    "AOCID" = ?;
    "AutoplayOnSpecialInterface" = ?;
    "CustomWake" = ?;
    "DefaultSimulatedTarget" = ?;
    "DeviceDumpVendorGPLogAddress" = ?; // from storport.sys
    "DeviceGroup" = ?;
    "DeviceGroups" = ?;
    "DeviceHandlers" = ?;
    "FailReasonID" = ?;
    "FirmwareCapsuleFilename" = ?;
    "FirmwareFilename" = ?;
    "FirmwareId" = ?;
    "FirmwareIntegrityFilename" = ?;
    "FirmwareMeasurementsFilename" = ?;
    "FirmwareStatus" = ?;
    "FirmwareVersion" = ?;
    "FirmwareVersionFormat" = ?;
    "FlipFlopHScroll" = ?;
    "FlipFlopWheel" = ?;
    "ForceVirtualDesktop" = ?;
    "FullPowerDownOnTransientDx" = ?;
    "FunctionDriverOptIn" = ?;
    "HackFlags" = ?;
    "HardResetCount" = ?; // REG_DWORD, "Writes into registry information about how many times this hub has been reset for the lifetime of the devnode. It also writes the invalid port status if that is the reason for hub reset. This infromation will be read by the SQM engine."
    "HasPhysicalKeys" = ?;
    "HScrollHighResolutionDisable" = ?;
    "HScrollPageOverride" = ?;
    "HScrollScalingFactor" = ?;
    "HScrollUsageOverride" = ?;
    "HubFWUpdateProtocol" = ?; // REG_DWORD
    "Icons" = ?;
    "IdleSupported" = ?;
    "IdleTimeoutPeriodInMilliSec" = ?;
    "KeyboardNumberFunctionKeysOverride" = ?;
    "KeyboardNumberIndicatorsOverride" = ?;
    "KeyboardNumberTotalKeysOverride" = ?;
    "KeyboardSubtypeOverride" = ?;
    "KeyboardTypeOverride" = ?;
    "Label" = ?;
    "NoMediaIcons" = ?;
    "NoSoftEject" = ?;
    "NumberOfPairingSlots" = ?;
    "OriginalConfigurationValue" = ?;
    "OvercurrentDetected" = ?; // REG_DWORD (bool)
    "RootBus" = ?;
    "TargetForcePriorityList" = ?;
    "TargetPriorityList" = ?;
    "Usb4HostName" = ?;
    "UsbccgpCapabilities" = ?;
    "UseStrictBiosHandoff" = ?;
    "VhfMode" = ?;
    "VideoID" = ?;
    "VScrollHighResolutionDisable" = ?;
    "VScrollPageOverride" = ?;
    "VScrollUsageOverride" = ?;
    "WakeSystemOnConnect" = ?; // REG_DWORD (bool)
    "WheelScalingFactor" = ?;
    
    "IdleUsbSelectiveSuspendPolicy" = ?; // https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-driver-installation-based-on-compatible-ids#configure-selective-suspend-for-usbsersys
                                         // 0x00000001 	Enter selective suspend when idle, that is, when there are no active data transfers to or from the device.
                                         // 0x00000000 	Enter selective suspend only when there are no open handles to the device.

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\e5b3b5ac-9725-4f78-963f-03dfb1d828c7";
    "BusDataLinkSettleTime" = ?; // REG_DWORD, accepted if <= 150, larger values are ignored
    "D3ColdSupported" = 1; // REG_DWORD (bool)
    "DeviceD0DelayTime" = 100; // REG_DWORD, accepts <= 100 (ms), larger values are ignored
    "DeviceDpcCleanUpActionOverride" = 0; // REG_DWORD, 0 <= value <= 1, larger values are ignored (doesn't exist on 23H2 in pci?)
    "DeviceDpcResetActionOverride" = 0; // REG_DWORD, 0 <= value <= 4, larger values are ignored (doesn't exist on 23H2 in pci?)
    "DevicePowerResetDelayTime" = ?; // REG_DWORD (doesn't exist on 23H2 in pci?)
    "ForceSBR" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "IgnoreErrorsDuringPLDR" = 1; // REG_DWORD, ^
    "IoNotRequired" = 1; // REG_DWORD, INF default (pci.inf)
    "RecoveryDisabled" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "RecoveryEnabled" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "SettleTimeRequired" = 1; // REG_DWORD, INF default (pci.inf/machine.inf), "Child devices can opt into this delay by including the PciExtraSettleTimeRequired from machine.inf or pci.inf."
    "SriovSupported" = 1; // REG_DWORD, INF default (pci.inf)

    // xrefs of PciIsDeviceFeatureEnabled (which opens key e5b3b5ac-9725-4f78-963f-03dfb1d828c7)

    "ASPMOptOut" = ?; // REG_DWORD (bool), used when BaseVersion >= 1.1 (BaseVersion = PCIe base spec level)
    "ASPMOptIn" = ?; // REG_DWORD (bool), used when BaseVersion < 1.1 so basically never?
    "AtomicsOptIn" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - PciDeviceQueryAtomics
    "BridgeUseNativeWakeInfo" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - PciAddDevice
    "EnableAllBridgeInterrupts" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) "If a third-party driver has installed itself as a filter it may invoke the PciEnableAllBridgeInterrupts section from machine.inf to disable filtering of PCI Bridge interrupts." - PciBridgeInterface_Constructor
    "DoNotUseAcs" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - ExpressProcessExtendedPortCapabilities
    "AcsNotRequired" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - ExpressProcessNewPort

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Ceip"; // g_DeviceCeipKey
    "DeviceInformation" = ; // REG_DWORD, missing treated as 0 before HUBREG_UpdateSqmFlags update
    "PortInterconnectType" = ?; // REG_DWORD
    "DescriptorValidationInfo0" = ?; // REG_DWORD, written by HUBREG_UpdateSqmFlags
    "DescriptorValidationInfo1" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo2" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo3" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo4" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo5" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo6" = ?; // REG_DWORD, ^

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf";
    "IdleInWorkingState" = 0; // REG_DWORD (bool), INF default (1394.inf), read when UserControlOfIdleSettings is allowed
    "WakeFromSleepState" = ?; // REG_DWORD (bool)
    "WdfDefaultIdleInWorkingState" = 0; // REG_DWORD, INF default (wpdmtp.inf)
    "WdfDirectedPowerTransitionChildrenOptional" = 1; // REG_DWORD (bool), INF default (acxhdaudiop.inf)
    "WdfDirectedPowerTransitionEnable" = 1; // REG_DWORD (bool), INF default (acxhdaudiop.inf, hdaudbus.inf, iaLPSS2i_I2C_CNL.inf)
    "WdfUseWdfTimerForPofx" = ?; // REG_DWORD (bool)
    "SleepstudyState" = 0; // REG_DWORD (bool), nonzero = enabled, only used on AoAc systems (Always on, Always connected)
    "WdfDefaultWakeFromSleepState" = 0; // REG_DWORD, INF default (UsbccidDriver.inf, wudfusbcciddriver.inf)

// Interrupt Management

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties";
    "MessageNumberLimit" = ?; // REG_DWORD, cap for requested MSI messages
    "MSISupported" = ?; // REG_DWORD (bool), set by many device INFs (device specific)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties\\Range\\<n>";
    // "Build a table of values. Each will be filled in only if it exists."
    "StartingMessage" = 0; // REG_DWORD
    "EndingMessage" = 0; // REG_DWORD
    "MessagesPerProcessor" = 0; // REG_DWORD, affinity helper treats 0 as 1

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy";
    "AssignmentSetOverride" = 0; // can be a REG_BINARY, REG_DWORD, or REG_QWORD value that specifies a KAFFINITY mask (KAFFINITY type is an affinity mask that represents a set of logical processors in a group). For REG_BINARY, size must be less than or equal to the KAFFINITY size for the platform, and input byte order is little endian. If DevicePolicy is 0x04 (IrqPolicySpecifiedProcessors), then this mask specifies a set of processors to assign the device's interrupts to. "For backwards compatibility handle several types. In the case where multi-byte binary data is found, treat the input byte order as little endian." https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/interrupt-affinity-and-priority
    "DevicePolicy" = 0; // REG_DWORD, https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ne-wdm-_irq_device_policy
    "DevicePriority" = 0; // REG_DWORD
    "GroupOverride" = ;
    "GroupPolicy" = ; // REG_DWORD, default GroupAffinityAllGroupZero when missing

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy - Temporal";
    "TargetGroup" = ?; // REG_DWORD
    "TargetSet" = ?; // REG_QWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Routing Info";
    // "This routine deletes any interrupt routing data that the interrupt arbiter has cached (for performance reasons) about this device."
    "Flags" = ?; // REG_DWORD, data size 1
    "LinkNode" = ?; // REG_BINARY, ACPIAmliBuildObjectPathname
    "StaticVector" = ?; // REG_DWORD, PcisuppSetRoutingInfo writes this when no LinkNode is present

// miscellaneous values from boot trace, haven't looked into them yet
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>";
    "Address" = ?;
    "Capabilities" = ?;
    "CompatibleIDs" = ?;
    "ConfigFlags" = ?;
    "ContainerID" = ?;
    "DeviceCharacteristics" = ?;
    "DeviceDesc" = ?;
    "DeviceReported" = ?;
    "DeviceType" = ?;
    "Driver" = ?;
    "Exclusive" = ?;
    "HardwareID" = ?;
    "InstallFlags" = ?;
    "LocationInformation" = ?;
    "LowerFilters" = ?;
    "Mfg" = ?;
    "ParentIdPrefix" = ?;
    "Phantom" = ?;
    "RemovalPolicy" = ?;
    "SECURITY" = ?;
    "Service" = ?;
    "UINumber" = ?;
    "UINumberDescFormat" = ?;
    "UniqueParentID" = ?;
    "UpperFilters" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Control";
    "AllocConfig" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\LogConf";
    "AllocConfig" = ?;
    "BootConfig" = ?;
    "ForcedConfig" = ?;
    "OverrideConfigVector" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\BiosConfig";
    "DEV_00&FUN_00" = ?;
    "DEV_00&FUN_01" = ?;
    "DEV_00&FUN_02" = ?;
    "DEV_00&FUN_03" = ?;
    "DEV_01&FUN_00" = ?;
    "DEV_01&FUN_01" = ?;
    "DEV_01&FUN_02" = ?;
    "DEV_02&FUN_00" = ?;
    "DEV_03&FUN_00" = ?;
    "DEV_03&FUN_01" = ?;
    "DEV_04&FUN_00" = ?;
    "DEV_05&FUN_00" = ?;
    "DEV_07&FUN_00" = ?;
    "DEV_07&FUN_01" = ?;
    "DEV_08&FUN_00" = ?;
    "DEV_08&FUN_01" = ?;
    "DEV_09&FUN_00" = ?;
    "DEV_14&FUN_00" = ?;
    "DEV_14&FUN_03" = ?;
    "DEV_18&FUN_00" = ?;
    "DEV_18&FUN_01" = ?;
    "DEV_18&FUN_02" = ?;
    "DEV_18&FUN_03" = ?;
    "DEV_18&FUN_04" = ?;
    "DEV_18&FUN_05" = ?;
    "DEV_18&FUN_06" = ?;
    "DEV_18&FUN_07" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\StorPort";
    "DlrmDisable" = ?;
    "EnableNVMeInterface" = ?;
    "FwActivateTimeoutForController" = ?;
    "TotalSenseDataBytes" = ?;

    // from storport.sys - https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A88F4.c
    "AdapterGuid" = ; // REG_BINARY, 16 bytes
    "BusSpecificResetTimeout" = 5; // REG_DWORD, range 1-4294967295, 0 ignored
    "DisableD3Cold" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "DisableNVMeActiveNamespaceIDListCheck" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "DisableRuntimePowerManagement" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "EnableIdlePowerManagement" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "GeneratedID" = ; // REG_BINARY, 16 bytes
    "IdleTimeoutInMS" = 60000; // REG_DWORD, range 0-4294967295
    "InitialTimestamp" = ; // REG_QWORD
    "Is1667Device" = 4294967295; // REG_DWORD, range 0-4294967295
    "PLDRTimeout" = 10; // REG_DWORD, range 1-4294967295, 0 ignored
    "PowerCycleCount" = 0; // REG_DWORD, range 0-4294967295, used only when PowerCycleCountOverride doesn't exist
    "PowerCycleCountOverride" = ; // REG_DWORD, range 0-4294967295
    "PowerSrbTimeout" = ; // REG_DWORD, range 1-110, >110 clamps to 110, 0 ignored
    "TotalSenseDataBytes" = 256; // REG_DWORD
    "UseDMAv3" = 0; // REG_DWORD, range 0-4294967295 (bool)

    // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A4268.c
    "BusyPauseTime" = 250; // REG_DWORD, range 0-4294967295
    "BusyRetryCount" = 20; // REG_DWORD, range 0-4294967295
    "DisableIdlePowerManagement" = 0; // REG_DWORD, range 0-4294967295
    "EnableLogoETW" = 0; // REG_DWORD, range 0-4294967295
    "MinimumIdleTimeoutInMS" = 4294967295; // REG_DWORD, range 0-4294967295
    "QueueFullWaitIoPercentage" = 25; // REG_DWORD, range 0-100

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\DMA Management";
    "RemappingFlags" = ?;
    "RemappingSupported" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\partmgr";
    "Attributes" = ?;
    "DiskId" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF";
    "SoftwareDeviceTag" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF\\CompanionConfigurations\\USBXHCI";
    "CompanionServiceList" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Disk"; // enumerator is usually SCSI here
  "UserWriteCacheSetting" = 1; // REG_DWORD, from storport.sys - https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00633B0.c
```

## MSPower_DeviceEnable

Note that the known `MSPower_DeviceEnable` command is recursively setting `IdleInWorkingState` & `SelectiveSuspendOn` to `0`, and sometimes additional values (e.g. `PnPCapabilities` for the NIC class).  

```powershell
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\ROOT_HUB30\5&2c35141&0&0\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\ROOT_HUB30\5&2bce96aa&0&0\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_0ABA&MI_03\7&41505d0&0&0003\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_05E3&PID_0610\6&3365fbaf&0&11\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_0B05&PID_1939&MI_02\7&40fe908&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_00\7&1fc2034b&0&0000\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_01\7&1fc2034b&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_02\7&1fc2034b&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_00\7&a6e656e&0&0000\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_01\7&a6e656e&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_02\7&a6e656e&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_03\7&a6e656e&0&0003\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_04\7&a6e656e&0&0004\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_0CF2&PID_A102&MI_01\8&7b0cf2a&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
```

On my 25H2 VM it also switched `PnPCapabilities`:
```c
// MSPower_DeviceEnable enabled
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0000\PnPCapabilities	Type: REG_DWORD, Length: 4, Data: 16

// MSPower_DeviceEnable disabled
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0000\PnPCapabilities	Type: REG_DWORD, Length: 4, Data: 24
```

## Storport Idle (`Device Parameters\\StorPort`)

> "*Storport provides support for idle power management to allow storage devices to enter a low power state when not in use. Storport's idle power management (IPM) support includes handling idle power management for storage devices under its management, in coordination with the Power Manager in Windows.*"
>
> — Microsoft, [Registry entries for Storport miniport drivers](https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/registry-entries-for-storport-miniport-drivers)

- [power/assets/pseudocode | storport.c](https://github.com/nohuto/win-config/blob/main/power/assets/pseudocode/storport.c)


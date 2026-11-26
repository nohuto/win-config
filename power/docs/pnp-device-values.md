# PnP Device Values

Windows Plug and Play (PnP) creates a device node (devnode) for each detected device instance ("The PnP manager is the primary component involved in supporting the ability of Windows to recognize and adapt to changing hardware configurations.").

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

## Registry Values

One thing to point out here is that there're two APIs which I almost didn't notice:
- [`IoOpenDeviceRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendeviceregistrykey) & `PLUGPLAY_REGKEY_DEVICE` opens the per device instance hardware key in the `Enum` branch (`HKLM\SYSTEM\CCS\Enum\<Enumerator>\<DeviceID>\<InstanceID>\Device Parameters`)
- [`IoOpenDriverRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey) opens the per driver service key in the `Services` branch (`HKLM\SYSTEM\CCS\Services\<ServiceName>\Parameters`)

Each line shows the value the reader uses when the entry is missing (`?` where I don't know it), the type and the range. Everything listed below is based on personal findings, mistakes may exist (especially since this list got created using several drivers).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters"; // USBHUB3, usbccgp, hidclass, winusb, BTHUSB, vhf, usbser
    "AllowIdleIrpInD3" = 0; // REG_DWORD (bool)
    "AltConfigurationValue" = ?; // REG_DWORD
    "CollectionReenumerateSelfInterfaceEnabled" = 0; // REG_DWORD (bool)
    "ComboHardwareIdV2Enabled" = 0; // REG_DWORD (bool)
    "CyclePortEnabled" = 0; // REG_DWORD (bool)
    "D3ColdReconnectTimeout" = 1000; // REG_DWORD, ms
    "DefaultIdleState" = 0; // REG_DWORD (bool)
    "DefaultIdleTimeout" = 0; // REG_DWORD, ms
    "DeviceIdleEnabled" = 0; // REG_DWORD (bool)
    "DeviceIdleIgnoreWakeEnable" = 0; // REG_DWORD (bool)
    "DeviceInterfaceGUID" = ?; // REG_SZ, WinUSB fallback for DeviceInterfaceGUIDs
    "DeviceInterfaceGUIDs" = ?; // REG_MULTI_SZ
    "DevicePowerUpOnS0Entry" = ?; // REG_DWORD (bool)
    "DeviceResetNotificationEnabled" = ?; // REG_DWORD (bool)
    "DeviceSelectiveSuspended" = 0; // REG_DWORD (bool), telemetry marker USBHUB3 writes after first selective suspend
    "EndpointPriorities" = ?; // REG_MULTI_SZ
    "EnhancedPowerManagementEnabled" = 1; // REG_DWORD (bool), 0 also turns off input suppression
    "EnhancedPowerManagementUseMonitor" = 0; // REG_DWORD (bool), read only while EnhancedPowerManagementEnabled = 1
    "EnumerationFailureCode" = ?; // REG_DWORD
    "EnumerationRetryCount" = ?; // REG_DWORD
    "ExtPropDescSemaphore" = 1; // REG_DWORD
    "FastResumeDisable" = ?; // REG_DWORD (bool)
    "ForceSelectiveSuspend" = 0; // REG_DWORD (bool), USB Bluetooth adapters only
    "FriendlyName" = ?; // REG_SZ
    "FullPowerDownOnTransientDx" = 1; // REG_DWORD
    "FunctionDriverOptIn" = 0; // REG_DWORD (bool)
    "HardResetCount" = 0; // REG_DWORD
    "HubFWUpdateProtocol" = 0; // REG_DWORD
    "IdleAllowUserControl" = ?; // REG_DWORD (bool)
    "IdleSupported" = 0; // REG_DWORD (bool), VHF devices only
    "IdleTimeout" = ?; // REG_DWORD, seconds
    "IdleTimeoutPeriodInMilliSec" = 1000; // REG_DWORD, ms, 0 = expires at once
    "IdleUsbSelectiveSuspendPolicy" = ?; // REG_DWORD
    "LastHubResetPortStatus" = ?;
    "MsOs20Flags" = ?; // REG_DWORD
    "OriginalConfigurationValue" = 0; // REG_DWORD
    "OvercurrentDetected" = 0; // REG_DWORD (bool)
    "PolledDevice" = ?; // REG_DWORD (bool)
    "PowerUpIdleDeviceOnSystemWake" = ?; // REG_DWORD (bool)
    "RemoteWakeEnabled" = ?; // REG_DWORD (bool), written by "Allow this device to wake the computer"
    "ResetPortEnabled" = 0; // REG_DWORD (bool)
    "RetainWWIrpWhenDeviceAbsent" = 0; // REG_DWORD (bool)
    "RevisionId" = ?; // REG_DWORD
    "SelectiveSuspendEnabled" = 0; // REG_BINARY or REG_DWORD (bool)
    "SelectiveSuspendOn" = 1; // REG_DWORD (bool), "Allow the computer to turn off this device"
    "SelectiveSuspendSupported" = 1; // REG_DWORD (bool), USB Bluetooth adapters only
    "SelectiveSuspendTimeout" = 5000; // REG_DWORD, ms, used only while SelectiveSuspendEnabled & SelectiveSuspendOn = 1
    "SelSuspCancelBehavior" = 0; // REG_DWORD (bool)
    "SessionSecurityEnabled" = ?; // REG_DWORD (bool)
    "SuppressInputInCS" = 0; // REG_DWORD (bool), nonzero also disables WakeScreenOnInputSupport
    "SymbolicName" = ?; // REG_SZ
    "SystemInputSuppressionEnabled" = ?; // REG_DWORD (bool)
    "SystemWakeEnabled" = 0; // REG_DWORD (bool)
    "TestIdleMonitorDim" = 1; // REG_DWORD, seconds
    "TestIdleTimeoutNoHandles" = 1; // REG_DWORD, seconds
    "TestIdleTimeoutNoHandlesInitial" = 5000; // REG_DWORD, ms
    "Usb4HostName" = ?; // REG_SZ
    "UsbccgpCapabilities" = 0; // REG_DWORD
    "UserSetDeviceIdleEnabled" = 0; // REG_DWORD (bool), shows the power saving box in Device Manager
    "UseStrictBiosHandoff" = ?; // REG_DWORD (bool)
    "VendorRevision" = ?; // REG_DWORD
    "VhfMode" = 0; // REG_DWORD, 0-2
    "WaitWakeEnabled" = ?; // REG_DWORD (bool), written by "Allow this device to wake the computer"
    "WakeScreenOnInputSupport" = 0; // REG_DWORD (bool)
    "WakeScreenOnInputTimeout" = 1000; // REG_DWORD, read only when WakeScreenOnInputSupport is nonzero
    "WakeSystemOnConnect" = 0; // REG_DWORD (bool), hubs only
    "WinRtInterfaceRestrictionLevel" = 255; // REG_DWORD (bool)
    "WinusbIsochUsed" = 0; // REG_DWORD (bool)
    "WinUsbPowerPolicyOwnershipDisabled" = 0; // REG_DWORD (bool)
    "WriteReportExSupported" = ?; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf"; // Wdf01000
    "IdleInWorkingState" = ?; // REG_DWORD (bool)
    "SleepstudyState" = 0; // REG_DWORD (bool), Modern Standby only
    "WakeFromShutdown" = 0; // REG_DWORD (bool)
    "WakeFromSleepState" = ?; // REG_DWORD (bool)
    "WdfDefaultIdleInWorkingState" = 1; // REG_DWORD (bool)
    "WdfDefaultWakeFromSleepState" = 1; // REG_DWORD (bool)
    "WdfDirectedPowerTransitionChildrenOptional" = 0; // REG_DWORD (bool)
    "WdfDirectedPowerTransitionEnable" = 1; // REG_DWORD (bool)
    "WdfUseWdfTimerForPofx" = 1; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf\\Restart"; // volatile
    "Count" = ?; // REG_DWORD
    "StartAchieved" = ?; // REG_DWORD
    "StartTime" = ?; // REG_BINARY, 8 bytes

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\e5b3b5ac-9725-4f78-963f-03dfb1d828c7";
    "AcsNotRequired" = 0; // REG_DWORD (bool)
    "ASPMOptIn" = 0; // REG_DWORD (bool), before PCIe 1.1
    "ASPMOptOut" = 0; // REG_DWORD (bool), PCIe 1.1+
    "AtomicsOptIn" = 0; // REG_DWORD (bool)
    "BridgeUseNativeWakeInfo" = 0; // REG_DWORD (bool)
    "BusDataLinkSettleTime" = 0; // REG_DWORD, 0-150
    "BusDelayTimeAfterDpc" = 0; // REG_DWORD, 100+, 25H2
    "BusDpcRpBusyTime" = 0; // REG_DWORD, 25H2
    "D3ColdSupported" = ?; // REG_DWORD (bool)
    "DeviceD0DelayTime" = 0; // REG_DWORD, ms, 0-100
    "DeviceDpcCleanUpActionOverride" = 0; // REG_DWORD (bool), 25H2
    "DeviceDpcResetActionOverride" = 0; // REG_DWORD, 0-4, 25H2
    "DevicePowerResetDelayTime" = 0; // REG_DWORD, 25H2
    "DoNotUseAcs" = 0; // REG_DWORD (bool)
    "EnableAllBridgeInterrupts" = 0; // REG_DWORD (bool)
    "ForceSBR" = 0; // REG_DWORD (bool), "Secondary Bus Reset"
    "HotplugSupportOptOut" = 0; // REG_DWORD (bool), 25H2
    "IgnoreErrorsDuringPLDR" = 0; // REG_DWORD (bool)
    "IoNotRequired" = 0; // REG_DWORD (bool)
    "RecoveryDisabled" = 0; // REG_DWORD (bool)
    "RecoveryEnabled" = 0; // REG_DWORD (bool)
    "SettleTimeRequired" = 0; // REG_DWORD (bool)
    "SriovSupported" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\PCI\\<deviceID>\\<instanceID>\\Device Parameters\\StorPort";
    "AdapterGuid" = ?; // REG_BINARY, 16 bytes
    "BusSpecificResetTimeout" = 5; // REG_DWORD, 0 ignored
    "ControllerDbgLogControlEnable" = ?; // REG_DWORD, 25H2
    "DisableD3Cold" = 0; // REG_DWORD (bool)
    "DisableNVMeActiveNamespaceIDListCheck" = 0; // REG_DWORD (bool)
    "DisableRuntimePowerManagement" = 0; // REG_DWORD (bool)
    "DlrmDisable" = 0; // REG_DWORD (bool), 25H2
    "DMArSupport" = ?; // REG_DWORD (bool), copied to DMA Management\RemappingSupported, 25H2
    "EnableIdlePowerManagement" = 0; // REG_DWORD (bool)
    "EnableNVMeInterface" = ?; // REG_DWORD (bool), missing = feature NativeNVMeStackForGeClient, 25H2
    "FwActivateTimeoutForController" = ?; // REG_DWORD, 25H2
    "GeneratedID" = ?; // REG_BINARY, 16 bytes
    "IdleTimeoutInMS" = 60000; // REG_DWORD, ms
    "InitialTimestamp" = ?; // REG_QWORD
    "Is1667Device" = 4294967295; // REG_DWORD
    "PLDRTimeout" = 10; // REG_DWORD, 0 is ignored
    "PowerCycleCount" = 0; // REG_DWORD
    "PowerCycleCountOverride" = ?; // REG_DWORD
    "PowerSrbTimeout" = ?; // REG_DWORD, 1-110
    "StorageD3InModernStandby" = ?; // REG_DWORD (bool), 25H2
    "TotalSenseDataBytes" = 256; // REG_DWORD
    "UseDMAv3" = 0; // REG_DWORD (bool)

    // NVMe settings storport reads here on 25H2
    "IdlePowerMode" = ?; // REG_DWORD
    // BypassSgl, DeepQueueDepthSupport, DfxDisable, DiagnosticFlags, DisableBypassIO, DisableDeallocate, InterruptCoalescingEntry, InterruptCoalescingTime, IoCompletionCapInDPC, IoCompletionQueueCount, IoPollingInterval, IoPollingSize, IoQueueDepth, IoQueuePercentageInPollingMode, IoStripeAlignment, IoSubmissionQueueCount, IsolateDeallocate, IsolateFlush, NvmeCrashdumpViaSCSI

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\SCSI\\<deviceID>\\<instanceID>\\Device Parameters\\Storport";
    "BusyPauseTime" = 250; // REG_DWORD
    "BusyRetryCount" = 20; // REG_DWORD
    "DisableIdlePowerManagement" = 0; // REG_DWORD (bool)
    "EnableLogoETW" = 0; // REG_DWORD (bool)
    "MinimumIdleTimeoutInMS" = 4294967295; // REG_DWORD, ms
    "QueueFullWaitIoPercentage" = 25; // REG_DWORD, 0-100

// Interrupt Management
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties";
    "MessageNumberLimit" = ?; // REG_DWORD, MSI 1/2/4/8/16, MSI-X up to 2048
    "MSISupported" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties\\Range\\<n>";
    "AssignmentSetOverride" = 0; // see Affinity Policy
    "DevicePolicy" = 0; // REG_DWORD, IRQ_DEVICE_POLICY 0-6
    "DevicePriority" = 0; // REG_DWORD, IRQ_PRIORITY 0-3
    "EndingMessage" = 0; // REG_DWORD
    "MessagesPerProcessor" = 0; // REG_DWORD, 0 = 1, used with DevicePolicy 5
    "StartingMessage" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy";
    "AssignmentSetOverride" = 0; // REG_DWORD, REG_QWORD, REG_BINARY, processor mask for DevicePolicy 4
    "DevicePolicy" = 0; // REG_DWORD, IRQ_DEVICE_POLICY 0-6
    "DevicePriority" = 2; // REG_DWORD, IRQ_PRIORITY 0-3
    "GroupOverride" = 0; // REG_DWORD, processor group of AssignmentSetOverride, 0xFFFF = none
    "GroupPolicy" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\DMA Management";
    "RemappingFlags" = 0; // REG_DWORD
    "RemappingSupported" = ?; // REG_DWORD (bool)
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

## Enable Write Caching

Same as the "Enable write caching on the device" box (disk properties, `Policies`), storport writes `UserWriteCacheSetting` = 1 itself whenever the value is missing ([`sub_1C00633B0`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00633B0.c), 23H2), so this only changes disks where write caching was turned off, see the `Disk` block below.

## Turn Off Write-Cache Buffer Flushing

Only use this on a PC with a UPS/battery, disk.sys sets `DEV_POWER_PROTECTED`, which causes classpnp to think that the disk has a backup power supply, so flushes and FUA writes are skipped.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Disk"; // usually Enum\SCSI, created by storport or Device Manager
    "CacheIsPowerProtected" = 0; // REG_DWORD (bool), "Turn off Windows write-cache buffer flushing on the device"
    "UserWriteCacheSetting" = 1; // REG_DWORD (bool), "Enable write caching on the device"
```

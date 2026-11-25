# PnP Device Values

The USB values go to the `USB` enumerator only (`Enum\USB\**\Device Parameters`, its `Wdf` and `e5b3b5ac-...` subkeys), since their readers are USB drivers. The Storport values go to the key that reads them: the adapter's `StorPort` subkey under `Enum\PCI` and `Enum\USB` (USB attached SCSI adapters), the unit's `Storport` subkey under `Enum\SCSI`. The disk cache value goes to `Enum\SCSI\**\Device Parameters\Disk`.

Revert restores each key's earlier data from the journal. Values whose reader treats a missing value as off (`AllowIdleIrpInD3`, `DefaultIdleState`, `DeviceIdleEnabled`, `EnhancedPowerManagementUseMonitor`, `ForceSelectiveSuspend`, `SelectiveSuspendEnabled`, `UserSetDeviceIdleEnabled`, Storport `EnableIdlePowerManagement`) are only written where they already exist, so the option doesn't add them to devices that never had them.

Disables USB selective suspend, idle states, and related LP features if supported. `EnhancedPowerManagementEnabled` 0 also turns off hidclass's input suppression for USB mice and keyboards (see `SystemInputSuppressionEnabled` below).

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

Each line shows the value the reader uses when the entry is missing (`?` where I don't know it), the type and the range. `INF` names what an INF writes at install.

To create this list, I've used many driver pseudocodes (usbhub, winhub, acpi, pci, wdf, hidclass, USBHUB3...), several INF files, and W10 source for comments (which may not be accurate anymore). The WinUSB meanings are from [WinUSB power management](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/winusb-power-management).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters"; // USBHUB3, usbccgp, hidclass, winusb, BTHUSB, vhf, usbser
    "AllowIdleIrpInD3" = 0; // REG_DWORD, 0-1, INF 1 for HID
    "AltConfigurationValue" = ?; // REG_DWORD
    "CollectionReenumerateSelfInterfaceEnabled" = 0; // REG_DWORD, 0-1
    "ComboHardwareIdV2Enabled" = 0; // REG_DWORD, 0-1
    "CyclePortEnabled" = 0; // REG_DWORD, 0-1
    "D3ColdReconnectTimeout" = 1000; // REG_DWORD, ms
    "DefaultIdleState" = 0; // REG_DWORD, 0-1, suspend when idle without an open handle (AUTO_SUSPEND default)
    "DefaultIdleTimeout" = 0; // REG_DWORD, ms, idle time before suspend (SUSPEND_DELAY default)
    "DeviceIdleEnabled" = 0; // REG_DWORD, 0-1, device may suspend when idle
    "DeviceIdleIgnoreWakeEnable" = 0; // REG_DWORD, 0-1, suspend even without remote wake support
    "DeviceInterfaceGUID" = ?; // REG_SZ, WinUSB fallback for DeviceInterfaceGUIDs
    "DeviceInterfaceGUIDs" = ?; // REG_MULTI_SZ
    "DevicePowerUpOnS0Entry" = ?; // REG_DWORD, 0-1, enter D0 on resume from sleep
    "DeviceResetNotificationEnabled" = ?; // REG_DWORD, 0-1, INF 1 for HID
    "DeviceSelectiveSuspended" = 0; // REG_DWORD, 0-1, telemetry marker USBHUB3 writes after the first selective suspend, no effect
    "EndpointPriorities" = ?; // REG_MULTI_SZ, 6 comma separated fields per entry
    "EnhancedPowerManagementEnabled" = 1; // REG_DWORD, 0-1, 0 also turns off input suppression
    "EnhancedPowerManagementUseMonitor" = 0; // REG_DWORD, 0-1, read only while EnhancedPowerManagementEnabled is 1
    "EnumerationFailureCode" = ?; // REG_DWORD, telemetry
    "EnumerationRetryCount" = ?; // REG_DWORD, written at every device start
    "ExtPropDescSemaphore" = 1; // REG_DWORD, MS OS extended property descriptors were already queried
    "FastResumeDisable" = ?; // REG_DWORD, 0-1
    "ForceSelectiveSuspend" = 0; // REG_DWORD, 0-1, Bluetooth radios
    "FriendlyName" = ?; // REG_SZ
    "FullPowerDownOnTransientDx" = 1; // REG_DWORD, 0-1, 0 = partial transient Dx, 25H2
    "FunctionDriverOptIn" = 0; // REG_DWORD, 0-1, 1 forces VhfMode 2
    "HardResetCount" = 0; // REG_DWORD, hub reset counter
    "HubFWUpdateProtocol" = 0; // REG_DWORD
    "IdleAllowUserControl" = ?; // REG_DWORD, 0-1
    "IdleSupported" = 0; // REG_DWORD, 0-1, VHF devices
    "IdleTimeout" = ?; // REG_DWORD, seconds, usbser
    "IdleTimeoutPeriodInMilliSec" = 1000; // REG_DWORD, ms, composite parent idle timer, 0 = expires at once
    "IdleUsbSelectiveSuspendPolicy" = ?; // REG_DWORD, 0 = suspend without open handles, 1 = suspend without transfers, other = no idle settings
    "LastHubResetPortStatus" = ?;
    "MsOs20Flags" = ?; // REG_DWORD
    "OriginalConfigurationValue" = 0; // REG_DWORD
    "OvercurrentDetected" = 0; // REG_DWORD, 0-1
    "PolledDevice" = ?; // REG_DWORD, 0-1
    "PowerUpIdleDeviceOnSystemWake" = ?; // REG_DWORD, 0-1
    "RemoteWakeEnabled" = ?; // REG_DWORD, 0-1
    "ResetPortEnabled" = 0; // REG_DWORD, 0-1
    "RetainWWIrpWhenDeviceAbsent" = 0; // REG_DWORD, 0-1
    "RevisionId" = ?; // REG_DWORD
    "SelectiveSuspendEnabled" = 0; // REG_BINARY or REG_DWORD, 0-1
    "SelectiveSuspendOn" = 1; // REG_DWORD, 0-1, the "Allow the computer to turn off this device" box
    "SelectiveSuspendSupported" = 1; // REG_DWORD, 0-1, Bluetooth radios
    "SelectiveSuspendTimeout" = 5000; // REG_DWORD, ms, used only while SelectiveSuspendEnabled and SelectiveSuspendOn are 1
    "SelSuspCancelBehavior" = 0; // REG_DWORD, 0-1
    "SessionSecurityEnabled" = ?; // REG_DWORD, 0-1
    "SuppressInputInCS" = 0; // REG_DWORD, 0-1, 1 also turns WakeScreenOnInputSupport off
    "SymbolicName" = ?; // REG_SZ
    "SystemInputSuppressionEnabled" = ?; // REG_DWORD, 0-1, missing = hidclass decides (see below)
    "SystemWakeEnabled" = 0; // REG_DWORD, 0-1, device may wake the system
    "TestIdleMonitorDim" = 1; // REG_DWORD, seconds
    "TestIdleTimeoutNoHandles" = 1; // REG_DWORD, seconds
    "TestIdleTimeoutNoHandlesInitial" = 5000; // REG_DWORD, ms
    "Usb4HostName" = ?; // REG_SZ
    "UsbccgpCapabilities" = 0; // REG_DWORD
    "UserSetDeviceIdleEnabled" = 0; // REG_DWORD, 0-1, shows the power saving box in Device Manager
    "UseStrictBiosHandoff" = ?; // REG_DWORD, 0-1, xHCI controller
    "VendorRevision" = ?; // REG_DWORD
    "VhfMode" = 0; // REG_DWORD, 0-2
    "WakeScreenOnInputSupport" = 0; // REG_DWORD, 0-1
    "WakeScreenOnInputTimeout" = 1000; // REG_DWORD
    "WakeSystemOnConnect" = 0; // REG_DWORD, 0-1
    "WinRtInterfaceRestrictionLevel" = 255; // REG_DWORD, 0-1, larger values count as 0
    "WinusbIsochUsed" = 0; // REG_DWORD, 0-1
    "WinUsbPowerPolicyOwnershipDisabled" = 0; // REG_DWORD, 0-1
    "WriteReportExSupported" = ?; // REG_DWORD, 0-1
```

hidclass decides input suppression itself for USB HID devices when `SystemInputSuppressionEnabled` is missing or 0, unless `EnhancedPowerManagementEnabled` 0 cleared the `0x30` flags. Mouse and keyboard collections get state 1, which subscribes to `WNF_PO_INPUT_SUPPRESS_NOTIFICATION_EX`, touch pads get 3, other collections 2. The usage page/usage comments are my reading of the offsets (the values match the HID usage tables).

```c
// HidpFdoConfigureIdleSettings (hidclass.sys, 23H2)

RtlInitUnicodeString(&DestinationString, L"SystemInputSuppressionEnabled");
if ( (int)HidpFdoRegistryQueryULong(Context, DeviceRegKey, &DestinationString, &v51) >= 0 && v51 )
  *((_DWORD *)Context + 440) = 1;

if ( *((_DWORD *)Context + 440) != 1 && Context[2048] && (*((_DWORD *)Context + 439) & 0x30) != 0 ) // Context[2048] = USB enumerator (HidpGetDeviceFlags), 0x30 cleared by EnhancedPowerManagementEnabled = 0

    if ( v33 == 1 && ((v35 = *(_WORD *)(v34 + 10), v35 == 2) || v35 == 6) ) // usage page 1, usage 2 (mouse) or 6 (keyboard)
    {
      v30 = 1;
    }
    else if ( v33 == 13 && *(_WORD *)(v34 + 10) == 5 ) // usage page 0x0D, usage 5 (touch pad)
    {
      *((_DWORD *)Context + 440) = 3;

  *((_DWORD *)Context + 440) = 1;
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf"; // Wdf01000
    "IdleInWorkingState" = ?; // REG_DWORD, 0-1, written back by WDF at device start (see below)
    "SleepstudyState" = 0; // REG_DWORD, 0-1, Modern Standby only
    "WakeFromShutdown" = 0; // REG_DWORD, 0-1, 25H2
    "WakeFromSleepState" = ?; // REG_DWORD, 0-1, written back by WDF
    "WdfDefaultIdleInWorkingState" = 1; // REG_DWORD, 0-1
    "WdfDefaultWakeFromSleepState" = 1; // REG_DWORD, 0-1
    "WdfDirectedPowerTransitionChildrenOptional" = 0; // REG_DWORD, 0-1
    "WdfDirectedPowerTransitionEnable" = 1; // REG_DWORD, 0-1, directed power transitions on Modern Standby (DFx), KMDF 1.31+ drivers default to 1
    "WdfUseWdfTimerForPofx" = 1; // REG_DWORD, 0-1, 1 for KMDF 1.33+ drivers, else 0

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf\\Restart"; // volatile, WDF restart counter (more than 5 restarts within 60 s fail the start)
    "Count" = ?; // REG_DWORD
    "StartAchieved" = ?; // REG_DWORD
    "StartTime" = ?; // REG_BINARY, 8 bytes
```

WDF reads `WdfDefaultIdleInWorkingState` first (missing = idle on), then `IdleInWorkingState` for drivers that allow user control ([`FxPkgPnp::PowerPolicySetS0IdleSettings`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/Wdf01000/-PowerPolicySetS0IdleSettings@FxPkgPnp@@QEAAJPEAU_WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS@@@Z.c)):

```c
// FxPkgPnp::PowerPolicySetS0IdleSettings (25H2)

else if ( Enabled == WdfUseDefault )
{
  v8 = 1; // WdfDefaultIdleInWorkingState missing = idle on

    *(_OWORD *)useWdfTimerForPofxName_buffer = *(_OWORD *)L"WdfDefaultIdleInWorkingState";

    if ( FxDevice::OpenSettingsKey(m_Device, (void **)&childrenOptionalName, 0x20000u) >= 0 ) // Device Parameters\WDF
    {
      Value = 0;
      if ( FxRegKey::_QueryULong(*(void **)&childrenOptionalName.Length, &valueName, &Value) >= 0 ) // REG_DWORD only
        v8 = Value != 0;
    }

      if ( UserControlOfIdleSettings == IdleAllowUserControl )
      {

        if ( Settings->Enabled == WdfUseDefault )
        {

            wcscpy((wchar_t *)useWdfTimerForPofxName_buffer, L"IdleInWorkingState");

            if ( FxDevice::OpenSettingsKey(v31, (void **)&childrenOptionalName, 0x20000u) >= 0 )
            {
              Value = 0;
              if ( FxRegKey::_QueryULong(*(void **)&childrenOptionalName.Length, &valueName, &Value) >= 0 )
                v8 = Value != 0; // IdleInWorkingState overrides the WdfDefault result

      FxPkgPnp::PowerPolicySetS0IdleState(this, v8); // sets Dirty, FxPkgPnp::SaveState writes IdleInWorkingState = v8 at device start
```

WDF (`Wdf01000.sys`) writes the device's idle state back to `WDF\IdleInWorkingState` when a device whose driver allows user control starts ([`FxPkgPnp::SaveState`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/Wdf01000/-SaveState@FxPkgPnp@@IEAAXE@Z.c), called from `PowerPolStartingDecideS0Wake`). That's why a fresh install has `IdleInWorkingState = 1` on the USB root hubs although no INF writes it. On my 25H2 VM, deleting it and restarting the root hub brought it back as 1, writing 0 kept it at 0 and unticked "Allow the computer to turn off this device to save power".

```c
// FxPkgPnp::SaveState (25H2)

if ( !m_Owner->m_IdleSettings.Overridable || (v8 = 1, !m_Owner->m_IdleSettings.Dirty) ) // Overridable = IdleAllowUserControl
  v8 = 0;

if ( v8 )
{
  RtlInitUnicodeString(&name, L"IdleInWorkingState");
  Data = this->m_PowerPolicyMachine.m_Owner->m_IdleSettings.Enabled;
  ZwSetValueKey(hKey.m_Key, &name, 0, 4u, &Data, 4u);
  this->m_PowerPolicyMachine.m_Owner->m_IdleSettings.Dirty = 0;
}
```

VM output (shortened, the `pnputil` lines removed):

```
clean : IdleInWorkingState=1
  wmi MSPower_DeviceEnable: USB\ROOT_HUB30\4&24054718&0&0_0=True
after delete + restart-device : IdleInWorkingState=1
  wmi MSPower_DeviceEnable: USB\ROOT_HUB30\4&24054718&0&0_0=True
after IdleInWorkingState=0 + restart-device : IdleInWorkingState=0
  wmi MSPower_DeviceEnable: USB\ROOT_HUB30\4&24054718&0&0_0=False
after delete IdleInWorkingState, WdfDefaultIdleInWorkingState=0, restart-device : WdfDefaultIdleInWorkingState=0, IdleInWorkingState=0
  wmi MSPower_DeviceEnable: USB\ROOT_HUB30\4&24054718&0&0_0=False
after delete both + restart-device : IdleInWorkingState=1
  wmi MSPower_DeviceEnable: USB\ROOT_HUB30\4&24054718&0&0_0=True
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\e5b3b5ac-9725-4f78-963f-03dfb1d828c7"; // pci.sys, USBHUB3 and winusb read only D3ColdSupported
    "AcsNotRequired" = 0; // REG_DWORD, 0-1
    "ASPMOptIn" = 0; // REG_DWORD, 0-1, functions before PCIe 1.1 only (see below)
    "ASPMOptOut" = 0; // REG_DWORD, 0-1, 1 keeps ASPM off (PCIe 1.1 and later)
    "AtomicsOptIn" = 0; // REG_DWORD, 0-1
    "BridgeUseNativeWakeInfo" = 0; // REG_DWORD, 0-1, bridges, lowest wake D-state from the PMCSR register
    "BusDataLinkSettleTime" = 0; // REG_DWORD, bridges, 0-150 (25H2 no limit)
    "BusDelayTimeAfterDpc" = 0; // REG_DWORD, bridges, 100 or more, 25H2
    "BusDpcRpBusyTime" = 0; // REG_DWORD, bridges, 25H2
    "D3ColdSupported" = ?; // REG_DWORD, 0-1
    "DeviceD0DelayTime" = 0; // REG_DWORD, ms, 0-100
    "DeviceDpcCleanUpActionOverride" = 0; // REG_DWORD, 0-1, 25H2
    "DeviceDpcResetActionOverride" = 0; // REG_DWORD, 0-4, 25H2
    "DevicePowerResetDelayTime" = 0; // REG_DWORD, 25H2
    "DoNotUseAcs" = 0; // REG_DWORD, 0-1, bridges
    "EnableAllBridgeInterrupts" = 0; // REG_DWORD, 0-1, bridges, turns off bridge interrupt filtering
    "ForceSBR" = 0; // REG_DWORD, 0-1, force a Secondary Bus Reset
    "HotplugSupportOptOut" = 0; // REG_DWORD, 0-1, bridges, 25H2
    "IgnoreErrorsDuringPLDR" = 0; // REG_DWORD, 0-1
    "IoNotRequired" = 0; // REG_DWORD, 0-1, no IO space needed
    "RecoveryDisabled" = 0; // REG_DWORD, 0-1, wins over RecoveryEnabled
    "RecoveryEnabled" = 0; // REG_DWORD, 0-1
    "SettleTimeRequired" = 0; // REG_DWORD, 0-1, extra settle time after D3cold
    "SriovSupported" = 0; // REG_DWORD, 0-1
```

USB webcams and USB storage get this subkey from `pci.inf` `[PciD3ColdSupported.HW]` (included by `usbvideo.inf` and `usbstor.inf`), the item writes `D3ColdSupported` 0 there. A missing value means off, the meanings are from the comments of the matching `pci.inf` sections. pci.sys isn't in my pseudocode repo, so the following snippets are from an IDA decompile of the 23H2 `pci.sys`. `PciIsDeviceFeatureEnabled` opens the subkey and returns 2 only for a nonzero REG_DWORD:

```c
// PciIsDeviceFeatureEnabled (pci.sys, 23H2)

RtlInitUnicodeString(&DestinationString, L"e5b3b5ac-9725-4f78-963f-03dfb1d828c7");

        if ( Pool2[1] == 4 ) // REG_DWORD only

        else
        {
          v9 = -1073741811; // another type, handled like a missing value
        }

if ( v9 >= 0 )
{
  if ( v5 == 4 )
  {
    v3 = 3; // value is 0
    if ( *v8 )
      v3 = 2; // nonzero, callers test == 2
  }
  ExFreePoolWithTag(v8, 0x42696350u);
}
else
{
  v3 = 1; // missing
}
```

`ExpressProcessPortRegisters` stores bit 15 of the PCIe Device Capabilities register (Role-Based Error Reporting) and `ExpressPortFindOptInOptOutPolicy` picks `ASPMOptOut` when it's set, `ASPMOptIn` otherwise. TRUE keeps ASPM off. Linux uses the same bit for the same check ("we follow MS to use RBER bit to determine if a function is 1.1 version device", [`drivers/pci/pcie/aspm.c`](https://github.com/torvalds/linux/blob/master/drivers/pci/pcie/aspm.c)). The register names in the comments are my reading of the offsets (WDK `PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER`, bit 15 = `RoleBasedErrorReporting`).

```c
// ExpressProcessPortRegisters (pci.sys, 23H2)

v3 = (int *)(a1 + 48);
PciReadDeviceConfig(
  *(_QWORD *)(a1 + 8),
  (unsigned __int8 *)(a1 + 48),
  *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 60LL) + 4, // PCIe capability + 4 = Device Capabilities register
  4u);

v6 = *v3;
*(_DWORD *)(a1 + 96) ^= (*(_DWORD *)(a1 + 96) ^ ((unsigned int)*v3 >> 15)) & 1; // bit 15 = RoleBasedErrorReporting (PCI_EXPRESS_DEVICE_CAPABILITIES_REGISTER)
```

```c
// ExpressPortFindOptInOptOutPolicy (pci.sys, 23H2)

if ( (*(_DWORD *)(a1 + 96) & 1) != 0 ) // RBER set, PCIe 1.1 or later
  return (unsigned int)PciIsDeviceFeatureEnabled(v1, L"ASPMOptOut") == 2; // TRUE = ASPM stays off
else
  return (unsigned int)PciIsDeviceFeatureEnabled(v1, L"ASPMOptIn") != 2;
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\PCI\\<deviceID>\\<instanceID>\\Device Parameters\\StorPort"; // adapter, Enum\USB too for USB attached SCSI, storport
    "AdapterGuid" = ?; // REG_BINARY, 16 bytes
    "BusSpecificResetTimeout" = 5; // REG_DWORD, 0 is ignored
    "ControllerDbgLogControlEnable" = ?; // REG_DWORD, 25H2
    "DisableD3Cold" = 0; // REG_DWORD, 0-1
    "DisableNVMeActiveNamespaceIDListCheck" = 0; // REG_DWORD, 0-1
    "DisableRuntimePowerManagement" = 0; // REG_DWORD, 0-1
    "DlrmDisable" = 0; // REG_DWORD, 0-1, 25H2
    "DMArSupport" = ?; // REG_DWORD, 0-1, copied to DMA Management\RemappingSupported, 25H2
    "EnableIdlePowerManagement" = 0; // REG_DWORD, 0-1, storahci and uaspstor INFs ship 1
    "EnableNVMeInterface" = ?; // REG_DWORD, 0-1, storport's native NVMe stack, missing = feature NativeNVMeStackForGeClient, 25H2
    "FwActivateTimeoutForController" = ?; // REG_DWORD, 25H2
    "GeneratedID" = ?; // REG_BINARY, 16 bytes
    "IdleTimeoutInMS" = 60000; // REG_DWORD, ms
    "InitialTimestamp" = ?; // REG_QWORD
    "Is1667Device" = 4294967295; // REG_DWORD
    "PLDRTimeout" = 10; // REG_DWORD, 0 is ignored
    "PowerCycleCount" = 0; // REG_DWORD, used when PowerCycleCountOverride doesn't exist
    "PowerCycleCountOverride" = ?; // REG_DWORD
    "PowerSrbTimeout" = ?; // REG_DWORD, 1-110
    "StorageD3InModernStandby" = ?; // REG_DWORD, 0-1, native NVMe stack only, 25H2
    "TotalSenseDataBytes" = 256; // REG_DWORD
    "UseDMAv3" = 0; // REG_DWORD, 0-1

    // NVMe settings storport reads here on 25H2 (23H2: stornvme's service key), defaults not traced
    "IdlePowerMode" = ?; // REG_DWORD
    // also BypassSgl, DeepQueueDepthSupport, DfxDisable, DiagnosticFlags, DisableBypassIO, DisableDeallocate, InterruptCoalescingEntry, InterruptCoalescingTime, IoCompletionCapInDPC, IoCompletionQueueCount, IoPollingInterval, IoPollingSize, IoQueueDepth, IoQueuePercentageInPollingMode, IoStripeAlignment, IoSubmissionQueueCount, IsolateDeallocate, IsolateFlush, NvmeCrashdumpViaSCSI

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\SCSI\\<deviceID>\\<instanceID>\\Device Parameters\\Storport"; // logical unit, storport
    "BusyPauseTime" = 250; // REG_DWORD
    "BusyRetryCount" = 20; // REG_DWORD
    "DisableIdlePowerManagement" = 0; // REG_DWORD, 0-1
    "EnableLogoETW" = 0; // REG_DWORD, 0-1
    "MinimumIdleTimeoutInMS" = 4294967295; // REG_DWORD, ms, 4294967295 = unset
    "QueueFullWaitIoPercentage" = 25; // REG_DWORD, 0-100
```

storport reads the adapter values in [`sub_1C00A88F4`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A88F4.c) and the unit values in [`sub_1C00A4268`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A4268.c) (23H2).

### Values of Other Components

Other drivers keep their own data in the same keys. The item doesn't write any of these, and most of them sit under other enumerators (`HID`, `PCI`, `ROOT`, `UEFI`, `ACPI`), which the item's `Enum\USB` patterns don't match.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters";
    // mouhid (HID mice)
    "FlipFlopHScroll" = 0; // REG_DWORD, 0-1
    "FlipFlopWheel" = 0; // REG_DWORD, 0-1
    "HScrollHighResolutionDisable" = 0; // REG_DWORD, 0-1
    "HScrollPageOverride" = 0; // REG_DWORD
    "HScrollScalingFactor" = 120; // REG_DWORD
    "HScrollUsageOverride" = 0; // REG_DWORD
    "VScrollHighResolutionDisable" = 0; // REG_DWORD, 0-1
    "VScrollPageOverride" = 0; // REG_DWORD
    "VScrollUsageOverride" = 0; // REG_DWORD
    "WheelScalingFactor" = 120; // REG_DWORD

    // kbdhid (HID keyboards)
    "KeyboardNumberFunctionKeysOverride" = ?;
    "KeyboardNumberIndicatorsOverride" = ?;
    "KeyboardNumberTotalKeysOverride" = ?;
    "KeyboardSubtypeOverride" = ?;
    "KeyboardTypeOverride" = ?;

    // win32kbase (raw input)
    "ForceVirtualDesktop" = ?;
    "HasPhysicalKeys" = ?;

    // dxgkrnl (display adapters and monitors)
    "AOCID" = ?;
    "DefaultSimulatedTarget" = ?;
    "TargetForcePriorityList" = ?;
    "TargetPriorityList" = ?;
    "VideoID" = ?;

    // uefi.sys (firmware resources)
    "FirmwareCapsuleFilename" = ?; // 25H2
    "FirmwareFilename" = ?;
    "FirmwareId" = ?;
    "FirmwareIntegrityFilename" = ?;
    "FirmwareMeasurementsFilename" = ?; // 25H2
    "FirmwareStatus" = ?;
    "FirmwareVersion" = ?;
    "FirmwareVersionFormat" = ?;

    // shsvcs.dll (AutoPlay)
    "AutoplayOnSpecialInterface" = ?;
    "DeviceGroup" = ?;
    "DeviceGroups" = ?;
    "DeviceHandlers" = ?;
    "Icons" = ?;
    "Label" = ?;
    "NoMediaIcons" = ?;
    "NoSoftEject" = ?;

    // others
    "CustomWake" = ?; // AMD GPIO, no Windows binary reads it
    "DeviceDumpVendorGPLogAddress" = ?; // REG_DWORD, storport device dump
    "FailReasonID" = ?; // usbui.dll
    "HackFlags" = ?; // pci.sys
    "NumberOfPairingSlots" = ?; // Logitech driver
    "RootBus" = ?; // umbus.sys

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Ceip"; // USBHUB3 telemetry, read by usbceip.dll
    "DescriptorValidationInfo0" = ?; // REG_DWORD
    "DescriptorValidationInfo1" = ?; // REG_DWORD
    "DescriptorValidationInfo2" = ?; // REG_DWORD
    "DescriptorValidationInfo3" = ?; // REG_DWORD
    "DescriptorValidationInfo4" = ?; // REG_DWORD
    "DescriptorValidationInfo5" = ?; // REG_DWORD
    "DescriptorValidationInfo6" = ?; // REG_DWORD
    "DeviceInformation" = 0; // REG_DWORD
    "PortInterconnectType" = ?; // REG_DWORD, connector type

// Interrupt Management, pci.sys (MSI) and acpi.sys (line based interrupts)
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties";
    "MessageNumberLimit" = ?; // REG_DWORD, MSI 1/2/4/8/16, MSI-X up to 2048
    "MSISupported" = 0; // REG_DWORD, 0-1, only checked for devices that also have a line based interrupt

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties\\Range\\<n>"; // n = 0, 1, 2 ...
    "AssignmentSetOverride" = 0; // see Affinity Policy
    "DevicePolicy" = 0; // REG_DWORD, IRQ_DEVICE_POLICY 0-6
    "DevicePriority" = 0; // REG_DWORD, IRQ_PRIORITY 0-3
    "EndingMessage" = 0; // REG_DWORD
    "MessagesPerProcessor" = 0; // REG_DWORD, 0 = 1, used with DevicePolicy 5
    "StartingMessage" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy";
    "AssignmentSetOverride" = 0; // REG_DWORD, REG_QWORD or REG_BINARY, processor mask for DevicePolicy 4
    "DevicePolicy" = 0; // REG_DWORD, IRQ_DEVICE_POLICY 0-6
    "DevicePriority" = 2; // REG_DWORD, IRQ_PRIORITY 0-3
    "GroupOverride" = 0; // REG_DWORD, processor group of AssignmentSetOverride, 0xFFFF = none
    "GroupPolicy" = 0; // REG_DWORD, 0-1

// volatile, written by acpi.sys at runtime
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy - Temporal";
    "TargetGroup" = ?; // REG_DWORD
    "TargetSet" = ?; // REG_QWORD, processor mask

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Routing Info";
    "Flags" = ?; // REG_DWORD
    "LinkNode" = ?; // REG_BINARY, ACPI path
    "StaticVector" = ?; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\DMA Management"; // Kernel DMA Protection, 25H2
    "RemappingFlags" = 0; // REG_DWORD
    "RemappingSupported" = ?; // REG_DWORD, 0-1

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\partmgr";
    "Attributes" = 0; // REG_DWORD, disk attributes (offline, read only)
    "DiskId" = ?; // REG_SZ, GUID

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF";
    "SoftwareDeviceTag" = ?; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF\\CompanionConfigurations\\<KMDF service>";
    "CompanionServiceList" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\BiosConfig";
    "DEV_<dd>&FUN_<ff>" = ?; // one per PCI device/function, names built at runtime
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
```

Microsoft documents `DevicePolicy` and `AssignmentSetOverride` in [Interrupt affinity and priority](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/interrupt-affinity-and-priority), `MSISupported` and `MessageNumberLimit` in [Enabling message-signaled interrupts in the registry](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/enabling-message-signaled-interrupts-in-the-registry).

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

storport reads `EnableIdlePowerManagement` and `DisableD3Cold` from the adapter's key (`Enum\PCI\...\Device Parameters\StorPort`, `Enum\USB\...` for USB attached SCSI) and `DisableIdlePowerManagement` and `MinimumIdleTimeoutInMS` from each unit's key (`Enum\SCSI\...\Device Parameters\Storport`). A missing `EnableIdlePowerManagement` is 0, only some miniport INFs ship 1 (`mshdc.inf` for storahci, `uaspstor.inf`, `iastorav.inf`, `SmartSAMD.inf`), `stornvme.inf` ships none. The option writes `DisableD3Cold` 1 and `EnableIdlePowerManagement` 0 (where it exists) to the adapters and `DisableIdlePowerManagement` 1 to the units.

- [power/assets/pseudocode | storport.c](https://github.com/nohuto/win-config/blob/main/power/assets/pseudocode/storport.c)

## Turn Off Write-Cache Buffer Flushing

Only use this suboption on a PC with a UPS or a battery. It sets `CacheIsPowerProtected` 1, the Device Manager box "Turn off Windows write-cache buffer flushing on the device". disk.sys then sets `DEV_POWER_PROTECTED`, which tells classpnp that the disk has a backup power supply, so flushes and FUA writes are skipped. A power cut or crash can then lose data or corrupt the file system. It has nothing to do with device power management, which is why it isn't part of the main option. The pattern only matches existing `Disk` subkeys (storport creates them for its units).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Disk"; // usually Enum\SCSI, created by storport or Device Manager
    "CacheIsPowerProtected" = 0; // REG_DWORD, 0-1, "Turn off Windows write-cache buffer flushing on the device"
    "UserWriteCacheSetting" = 1; // REG_DWORD, 0-1, "Enable write caching on the device", storport writes 1, missing = keep the device's setting
```

disk.sys reads both in `DiskStartFdo` (23H2):

```c
// DiskStartFdo (23H2)

*v6 = -1; // UserWriteCacheSetting default
ClassGetDeviceParameter(DeviceExtension, (PWSTR)L"Disk", (PWSTR)L"UserWriteCacheSetting", v6);

DeviceExtension->DeviceFlags &= ~0x10u;
ClassGetDeviceParameter(DeviceExtension, (PWSTR)L"Disk", (PWSTR)L"CacheIsPowerProtected", &ParameterValue);
if ( ParameterValue == 1 )
  DeviceExtension->DeviceFlags |= 0x10u; // DEV_POWER_PROTECTED, no flush, no FUA
```

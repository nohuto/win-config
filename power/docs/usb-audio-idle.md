# USB Audio Idle

It's a mechanism (for audio drivers) for idle detection that switches an audio device between active `D0` (highest power state) and low power sleep (normally [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) = *lowest powered device low power state*), after the configured timeout expires.

Note that `IdlePowerState` only has a meaning if timeouts are nonzero, means as you can see below `PerformanceIdleTime` is set to `0` by default = stays in D0, while power saving policy selects `ConservationIdleTime = 30`, allowing an idle transition to [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) after 30s (selection follows active power plans `Device idle policy`, `DEVICEIDLE`, `0` = Performance, `1` = Power savings).  You can see your current device power state (Dx) via [`Device Manager > Sound, video and game controllers > <USB audio device> > Properties > Details > Power data`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-cm_power_data_s) (`PD_MostRecentPowerState`).

It works via [`DeviceStart`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/DeviceStart.c) -> [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) -> [`PoRegisterDeviceForIdleDetection`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PoRegisterDeviceForIdleDetection.c). In 24H2+ it also registers [`PowerSettingCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/PowerSettingCallback.c) for `GUID_LOW_POWER_EPOCH`, which is why the additional `CS*` values exist.

> "*`[in] ConservationIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for energy conservation. Specify zero to disable idle detection when conservation policy is in effect.*  
> *`[in] PerformanceIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for performance. Specify zero to disable idle detection when performance policy is in effect.*"
>
> — Microsoft, [`PoRegisterDeviceForIdleDetection`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterdeviceforidledetection)

## Registry Values

[INF values](https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/portcls-registry-power-settings) have type `REG_BINARY`, but [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) only checks the returned value data length (`4`), see '[Build Differences](https://noverse.dev/docs/win-config/power/usb-audio-idle/#build-differences)' section.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e96c-e325-11ce-bfc1-08002be10318}\\00xx\\PowerSettings";
    "ConservationIdleTime" = 30; // seconds, DEVICEIDLE = Power savings (1)
    "PerformanceIdleTime" = 0; // seconds, DEVICEIDLE = Performance (0)
    "IdlePowerState" = 3; // see below
    "CSConservationIdleTime" = 30; // 24H2+, see below
    "CSPerformanceIdleTime" = 30; // 24H2+, ^
```

`IoOpenDeviceRegistryKey(DeviceObject, 2)` opens the driver specific software key (`2` = `PLUGPLAY_REGKEY_DRIVER`), [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) then opens the `PowerSettings` subkey. [`{4d36e96c-e325-11ce-bfc1-08002be10318}`](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors) is the `Media` device setup class GUID, [`USBAUDIO.sys` is under that `Media` setup class for USB audio devices](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/supported-usb-classes).

`IdlePowerState` gets "translated" by `USBAUDIO` to (which is why `*a4 = 4` = [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3)):

| Data | `DEVICE_POWER_STATE` | Meaning |
| --- | --- | --- |
| `1` | `2` | `PowerDeviceD1` |
| `2` | `3` | `PowerDeviceD2` |
| `3` | `4` | `PowerDeviceD3` |
| anything else | `1` | `PowerDeviceD0` |
| missing | `4` | `PowerDeviceD3` |

### Build Differences

Use [diff](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-24H2&module=USBAUDIO&name=RegistryGetIdleInfo.c&mode=side-by-side) for direct comparison.

23H2 (and below) has two timeout values `ConservationIdleTime`/`PerformanceIdleTime`:

```c
// RegistryGetIdleInfo
*a3 = 0; // PerformanceIdleTime
*a2 = 30; // ConservationIdleTime
*a4 = 4; // PowerDeviceD3

RtlInitUnicodeString(&ValueName, L"ConservationIdleTime");
RtlInitUnicodeString(&v11, L"PerformanceIdleTime");
RtlInitUnicodeString(&v12, L"IdlePowerState");

if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, Pool2, 0x14u, &ResultLength) >= 0
  && Pool2[2] == 4 ) // DataLength == 4
{
  *a2 = Pool2[3];
}
```

24H2+ adds another two timeout values for low power epoch:

```c
// RegistryGetIdleInfo
*a4 = 0; // PerformanceIdleTime
*a2 = 30; // ConservationIdleTime
*a3 = 30; // CSConservationIdleTime
*v6 = 30; // CSPerformanceIdleTime
*v8 = 4; // PowerDeviceD3

RtlInitUnicodeString(&ValueName, L"ConservationIdleTime");
RtlInitUnicodeString(&v15, L"CSConservationIdleTime");
RtlInitUnicodeString(&v16, L"PerformanceIdleTime");
RtlInitUnicodeString(&v17, L"CSPerformanceIdleTime");
RtlInitUnicodeString(&v18, L"IdlePowerState");
```

`GUID_LOW_POWER_EPOCH` is a power setting GUID, if the callbacks 4 byte value is nonzero, `Context + 1080` becomes `1` and the `CS*` values are used, otherwise the other two are used.

```c
// DeviceStart
if ( *((_DWORD *)Context + 270) ) // LOW_POWER_EPOCH stored by PowerSettingCallback
{
  v11 = *((_DWORD *)Context + 139); // CSPerformanceIdleTime
  v12 = *((_DWORD *)Context + 137); // CSConservationIdleTime
}
else
{
  v11 = *((_DWORD *)Context + 138); // PerformanceIdleTime
  v12 = *((_DWORD *)Context + 136); // ConservationIdleTime
}
*((_QWORD *)Context + 66) = PoRegisterDeviceForIdleDetection(
                              a1->PhysicalDeviceObject,
                              v12,
                              v11,
                              (DEVICE_POWER_STATE)*((_DWORD *)Context + 135));

PoRegisterPowerSettingCallback( // https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterpowersettingcallback
  a1->PhysicalDeviceObject,
  &GUID_LOW_POWER_EPOCH,
  (PPOWER_SETTING_CALLBACK)PowerSettingCallback,
  a1,
  (PVOID *)Context + 134);
```

```c
// PowerSettingCallback
if ( *SettingGuid == *(_OWORD *)&GUID_LOW_POWER_EPOCH )
{
  if ( (_DWORD)ValueLength == 4 && Value )
  {
    *(_DWORD *)(v8 + 1080) = *v6 != 0; // LOW_POWER_EPOCH
  }
}
```

- [11-23H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-24H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-25H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-26H1/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/USBAUDIO/RegistryGetIdleInfo.c)


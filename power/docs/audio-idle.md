# Audio Idle

It's a mechanism (for audio drivers) for idle detection that switches an audio device between active `D0` (highest power state) and low power sleep (normally [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) = *lowest powered device low power state*), after the configured timeout expires.

Note that `IdlePowerState` only has a meaning if timeouts are nonzero, means as you can see below `PerformanceIdleTime` is set to `0` by default = stays in D0, while power saving policy selects `ConservationIdleTime = 30`, allowing an idle transition to [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) after 30s (selection follows active power plans `Device idle policy`, `DEVICEIDLE`, `0` = Performance, `1` = Power savings).  You can see your current device power state (Dx) via [`Device Manager > Sound, video and game controllers > <audio device> > Properties > Details > Power data`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-cm_power_data_s) (`PD_MostRecentPowerState`).

It works via [`DeviceStart`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/DeviceStart.c) -> [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) -> [`PoRegisterDeviceForIdleDetection`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PoRegisterDeviceForIdleDetection.c). In 24H2+ it also registers [`PowerSettingCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/PowerSettingCallback.c) for `GUID_LOW_POWER_EPOCH`, which is why the additional `CS*` values exist.

> "*`[in] ConservationIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for energy conservation. Specify zero to disable idle detection when conservation policy is in effect.*  
> *`[in] PerformanceIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for performance. Specify zero to disable idle detection when performance policy is in effect.*"
>
> — Microsoft, [`PoRegisterDeviceForIdleDetection`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterdeviceforidledetection)

## Registry Values

[INF values](https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/portcls-registry-power-settings) have type `REG_BINARY`, but [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) only checks the returned value data length (`4`), see '[Build Differences](https://noverse.dev/docs/win-config/power/audio-idle/#build-differences)' section.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e96c-e325-11ce-bfc1-08002be10318}\\00xx\\PowerSettings";
    "ConservationIdleTime" = 30; // seconds, DEVICEIDLE = Power savings (1)
    "PerformanceIdleTime" = 0; // seconds, DEVICEIDLE = Performance (0)
    "IdlePowerState" = 3; // see below
    "CSConservationIdleTime" = 30; // 24H2+, see below
    "CSPerformanceIdleTime" = 30; // 24H2+, ^
```

`IoOpenDeviceRegistryKey(DeviceObject, 2)` opens the driver specific software key (`2` = `PLUGPLAY_REGKEY_DRIVER`), [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) then opens the `PowerSettings` subkey. [`{4d36e96c-e325-11ce-bfc1-08002be10318}`](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors) is the `Media` device setup class GUID, [`USBAUDIO.sys` is under that `Media` setup class for USB audio devices](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/supported-usb-classes).

```c
//   (25H2)

if ( IoOpenDeviceRegistryKey(DeviceObject, 2u, 0x20019u, &DeviceRegKey) >= 0 ) // 2 = PLUGPLAY_REGKEY_DRIVER
{
  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  DestinationString = 0LL;
  RtlInitUnicodeString(&DestinationString, L"PowerSettings");
  ObjectAttributes.RootDirectory = DeviceRegKey;
  ObjectAttributes.Length = 48;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  if ( ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes) >= 0 ) // fails without subkey
```

`PowerSettings` lines of the INFs (`C:\Windows\INF`):

```c
hdaudio.inf:150:HKR,PowerSettings,ConservationIdleTime,3,1e,00,00,0 ; 10 seconds for idle power management when on battery
hdaudio.inf:151:HKR,PowerSettings,PerformanceIdleTime,3,00,00,00,00 ; Not doing idle power management when on AC power
hdaudio.inf:152:HKR,PowerSettings,IdlePowerState,3,03,00,00,00 ; go to D3 for idle power management
hdaudss.inf:782:HKR,PowerSettings,ConservationIdleTime,1,00,00,00,0 ; Not doing idle power management when on battery
hdaudss.inf:783:HKR,PowerSettings,PerformanceIdleTime,1,00,00,00,00 ; Not doing idle power management when on AC power
hdaudss.inf:784:HKR,PowerSettings,IdlePowerState,1,03,00,00,00 ; go to D3 for idle power management
```

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
// RegistryGetIdleInfo (23H2)

*a3 = 0; // PerformanceIdleTime
DeviceRegKey = 0LL;
KeyHandle = 0LL;
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
// RegistryGetIdleInfo (24H2)

*a4 = 0; // PerformanceIdleTime
v6 = ResultLength;
v8 = a6;
DeviceRegKey = 0LL;
KeyHandle = 0LL;
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

25H2 adds the `CS*` values behind the `Servicing_UACPerfIdle` feature, with that on, `RegistryGetIdleInfo` reads all five values like 24H2 (`PerformanceIdleTime` 0 when missing).

```c
// RegistryGetIdleInfo (25H2)

IsEnabledDeviceUsageNoInline = Feature_Servicing_UACPerfIdle__private_IsEnabledDeviceUsageNoInline();
*a2 = 30; // ConservationIdleTime
*a6 = 4; // PowerDeviceD3
if ( IsEnabledDeviceUsageNoInline )
{
  *a3 = 30; // CSConservationIdleTime
  *a4 = 0; // PerformanceIdleTime
  *a5 = 30; // CSPerformanceIdleTime

else
{
  *a4 = 30; // PerformanceIdleTime, CS* values aren't read
```

`GUID_LOW_POWER_EPOCH` is a power setting GUID. `PowerSettingCallback` stores whether its 4 byte value is nonzero at `+1080` (`Context + 270` in `DeviceStart`) and registers idle detection again, with the both `CS*` ones when its nonzero and the other two otherwise.

```c
// DeviceStart (24H2)

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

if ( PoRegisterPowerSettingCallback( // https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterpowersettingcallback
       a1->PhysicalDeviceObject,
       &GUID_LOW_POWER_EPOCH,
       (PPOWER_SETTING_CALLBACK)PowerSettingCallback,
       a1,
       (PVOID *)Context + 134) < 0 )
```

```c
// PowerSettingCallback (24H2)

if ( *SettingGuid == *(_OWORD *)&GUID_LOW_POWER_EPOCH )
{
  if ( Context )
  {
    v8 = *((_QWORD *)Context + 2);
    if ( (_DWORD)ValueLength == 4 )
    {
      if ( Value )
      {
        KeWaitForSingleObject((PVOID)(v8 + 1016), Executive, 0, 0, 0LL);
        v11 = *v6;
        *(_DWORD *)(v8 + 1080) = *v6 != 0; // LOW_POWER_EPOCH
        if ( !*(_DWORD *)(v8 + 716) )
        {
          if ( v11 )
          {
            v12 = *(_DWORD *)(v8 + 556); // CSPerformanceIdleTime
            v13 = *(_DWORD *)(v8 + 548); // CSConservationIdleTime
          }
          else
          {
            v12 = *(_DWORD *)(v8 + 552); // PerformanceIdleTime
            v13 = *(_DWORD *)(v8 + 544); // ConservationIdleTime
          }
          *(_QWORD *)(v8 + 528) = PoRegisterDeviceForIdleDetection(
                                    *((PDEVICE_OBJECT *)Context + 4),
                                    v13,
                                    v12,
                                    (DEVICE_POWER_STATE)*(_DWORD *)(v8 + 540));
```

- [11-23H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-24H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-25H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-26H1/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/USBAUDIO/RegistryGetIdleInfo.c)


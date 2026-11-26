# Disable Wake on Input

Currently disables wake on input via win32k list of input types that may wake the display (`WakeOnInputDeviceTypes`) & per device values of USB/HID devices. Waking from sleep is the devices "Allow this device to wake the computer" setting (`WaitWakeEnabled`/`RemoteWakeEnabled`).

- [`powercfg /devicequery wake_programmable`](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#availablesleepstates-or-a) -> devices that are user configurable to wake the system from a sleep state
- [`powercfg /devicequery wake_armed`](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#availablesleepstates-or-a) -> currently configured to wake the system from any sleep state

```batch
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```

## Registry Values

See '[PnP Device Values](https://noverse.dev/docs/win-config/power/pnp-device-values/#registry-values)' for comments on these values.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters";
    "WakeSystemOnConnect" = 0;
    "SystemWakeEnabled" = 0;
    "WaitWakeEnabled" = ?;
    "RemoteWakeEnabled" = ?;
    "SuppressInputInCS" = 0;
    "WakeScreenOnInputSupport" = 0;
    "WakeScreenOnInputTimeout" = 1000;
```

### WakeOnInputDeviceTypes

Each bit is an input device type whose input may wake the display while win32k filters input (input mode "Filtered", `RIMIsInputSuppressed`), the default 46 (`0x2E`) which is every type except pen:

```c
"HKLM\\SYSTEM\\INPUT"; // win32kbase CInputGlobals::UpdateWakeOnInputDeviceTypesFromRegistry
    "WakeOnInputDeviceTypes" = 46; // REG_DWORD, 0x2 mouse, 0x4 keyboard, 0x8 touch, 0x10 pen, 0x20 precision touchpad
```

```c
// CInputGlobals::UpdateWakeOnInputDeviceTypesFromRegistry (win32kbase, 23H2)

*((_DWORD *)this + 25) = 46; // default 0x2E
RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\SYSTEM\\INPUT");

  RtlInitUnicodeString(&ValueName, L"WakeOnInputDeviceTypes");
  if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, KeyValueInformation, 0x14u, &ResultLength) >= 0
    && v14 == 4 // REG_DWORD
    && v15 == 4 )
  {
    *((_DWORD *)this + 25) = v16;
  }

// can be used to clear/set single types per user

KeyHandle = (void *)ApiSetEditionGetPointerDeviceConfigurationKey(8LL, 131097LL); // HKCU\Software\Microsoft\Input\WakeableInputTypes

      v5 = *(_DWORD *)v2; // bit of the type (Mouse, Keyboard, Touch, Pen, PrecisionTouchpad)
      v6 = *((_DWORD *)this + 25);
      if ( v16 ) // per user value nonzero
        v7 = v5 | v6;
      else
        v7 = ~v5 & v6;
```

## query_flag

All available flags (`powercfg /devicequery query_flag`):

| `query_flag` | Description |
| --- | --- |
| `wake_from_S1_supported` | Returns all devices that support waking the system from a light sleep state. |
| `wake_from_S2_supported` | Returns all devices that support waking the system from a deeper sleep state. |
| `wake_from_S3_supported` | Returns all devices that support waking the system from the deepest sleep state. |
| `wake_from_any` | Returns all devices that support waking the system from any sleep state. |
| `S1_supported` | Lists devices supporting light sleep. |
| `S2_supported` | Lists devices supporting deeper sleep. |
| `S3_supported` | Lists devices supporting deepest sleep. |
| `S4_supported` | Lists devices supporting hibernation. |
| `wake_programmable` | Lists devices that are user-configurable to wake the system from a sleep state. |
| `wake_armed` | Lists devices currently configured to wake the system from any sleep state. |
| `all_devices` | Returns all devices present in the system. |


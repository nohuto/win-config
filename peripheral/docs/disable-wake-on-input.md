# Disable Wake on Input

- [`powercfg /devicequery wake_programmable`](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#availablesleepstates-or-a) -> devices that are user-configurable to wake the system from a sleep state
- [`powercfg /devicequery wake_armed`](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#availablesleepstates-or-a) -> currently configured to wake the system from any sleep state

```bat
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```

## Registry Values

See '[PnP Device Values](https://noverse.dev/docs/win-config/power/pnp-device-values/#registry-values)' for more.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters";
    "WakeSystemOnConnect" = ?; // REG_DWORD (bool)
    "SystemWakeEnabled" = 1; // REG_DWORD (bool), INF default (UsbccidDriver.inf, wudfusbcciddriver.inf)
    "WaitWakeEnabled" = ?
    "SuppressInputInCS" = 0; // REG_DWORD (bool), clears WakeScreenOnInputSupport when enabled?
    "WakeScreenOnInputSupport" = 1; // REG_DWORD (bool)
    "WakeScreenOnInputTimeout" = ?; // REG_DWORD, queried only when WakeScreenOnInputSupport is enabled
```

### WakeOnInputDeviceTypes

[`WakeOnInputDeviceTypes`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/-UpdateWakeOnInputDeviceTypesFromRegistry@CInputGlobals@@QEAAXXZ.c) (`\Registry\Machine\SYSTEM\INPUT`) probably handles wake on input behavior for all input devices, each bit represents a input device type?

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


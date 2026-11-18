# Night Light

Uses warmer colors to block blue light, since the data for them is a bit complicated as shown below, I'll add support for modifying it in a later WinConfig version.

```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings : Data # REG_BINARY
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate: Data # REG_BINARY
```

## [BlueLightReduction.Settings](https://github.com/MicrosoftDocs/windows-dev-docs/blob/docs/hub/apps/develop/settings/settings-common.md#type-windowsdatabluelightreductionsettings-structure) structure

The data itself is [Microsoft Bond Compact Binary](https://microsoft.github.io/bond/reference/cpp/compact__binary_8h_source.html), `43 42 01 00` prefix means `CB` (compact binary) version `1`.

```cpp
enum BondDataType
{
    BT_STOP       = 0,
    BT_STOP_BASE  = 1,
    BT_BOOL       = 2,
    BT_UINT8      = 3,
    BT_UINT16     = 4,
    BT_UINT32     = 5,
    BT_UINT64     = 6,
    BT_FLOAT      = 7,
    BT_DOUBLE     = 8,
    BT_STRING     = 9,
    BT_STRUCT     = 10,
    BT_LIST       = 11,
    BT_SET        = 12,
    BT_MAP        = 13,
    BT_INT8       = 14,
    BT_INT16      = 15,
    BT_INT32      = 16,
    BT_INT64      = 17,
    BT_WSTRING    = 18,
    BT_UNAVAILABLE= 127
}
```

Example data:

```powershell
43 42 01 00 02 01 C2 0A 00 CA 14 0E 12 00 CA 1E 0E 05 00 CF 28 DC 4C CA 32 00 CA 3C 00 00
```

`02 01` = field 0 (automaticOnSchedule)
- `02` = type (`BT_BOOL`)
- `01` = value (`true`)

`CF 28 DC 4C` = field 40 (targetColorTemperature)
- `CF 28` = type (BT_INT16) + field 40
- `DC 4C` = value (`4910` since it uses BT_INT16)

| Field | Name | Type | Description | Value |
| --- | --- | --- | --- | --- |
| 0 | `automaticOnSchedule` | bool | Specifies whether blue light reduction is automatically turned on or off based on a schedule. |  `true` |
| 10 | `automaticOnSunset` | bool | Specifies if blue light reduction schedule is automatically set based on sunrise and sunset. | `false` |
| 20 | `manualScheduleBlueLightReductionOnTime` | ScheduleTime | The start time of blue light reduction for a user manually setting their schedule. |  `18:00` |
| 30 | `manualScheduleBlueLightReductionOffTime` | ScheduleTime | The end time of blue light reduction for a user manually setting their schedule. | `05:00` |
| 40 | `targetColorTemperature` | int16 | The target color temperature (in Kelvin) for blue light reduction. | `4910` Kelvin |
| 50 | `sunriseTime` | ScheduleTime | The scheduled sunrise time for blue light reduction. | empty |
| 60 | `sunsetTime` | ScheduleTime | The scheduled sunset time for blue light reduction. | empty |
| 70 | `previewColorTemperatureChanges` | bool | Specifies whether blue light reduction color temperature changes should be previewed. | not present |
| 80 | `darkMode` | bool | Specifies whether app mode should change when blue light reduction is turned on or off. | not present |

`ScheduleTime` has type int8, field `0` is `hour` and field `1` is `minute` (often leaves `minute` out when it is `0`).

## [BlueLightReduction.BlueLightReductionState](https://github.com/MicrosoftDocs/windows-dev-docs/blob/docs/hub/apps/develop/settings/settings-common.md#type-windowsdatabluelightreductionbluelightreductionstate-structure) structure

Example data:

```powershell
43 42 01 00 10 00 C6 14 DE F4 98 9E EA EE BE EE 01 00
```

| Field | Name | Type | Description | Value |
| --- | --- | --- | --- | --- |
| 0 | `state` | ActiveState | The current state of blue light reduction. | `0` = `BlueLightReductionOn`, `1` = `BlueLightReductionOff` |
| 10 | `source` | ChangeSource |  Where the change came from, user change or scheduled change. | not present (`0` = `Schedule`, `1` = `User`) |
| 20 | `timestampUTC` | int64 | The time the change in active state was applied. | `2026-06-13T20:53:08.666224Z` (decodes as [`FILETIME`](https://learn.microsoft.com/windows/win32/sysinfo/file-times)) |
| 30 | `isSupported` | bool | Whether or not current configuration supports blue light reduction. | not present |

## SystemSettings Captures

Procmon doesn't show the entire data, therefore this isn't accurate (and sometimes useless, e.g. the 'Strength' capture).

```c
// System > Display : Night light
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 43, Data: 43 42 01 00 0A 02 01 00 2A 06 FC 84 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 41, Data: 43 42 01 00 0A 02 01 00 2A 06 FE 84 B7 D1 06 2A

// System > Display > Night light: Show warmer colors on your display to help you sleep
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 43, Data: 43 42 01 00 0A 02 01 00 2A 06 AF 86 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 41, Data: 43 42 01 00 0A 02 01 00 2A 06 B1 86 B7 D1 06 2A

// System > Display > Night light: Strength (0-2)
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 99 AD B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 9B AD B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 9D AD B7 D1 06 2A

// System > Display > Night light: Schedule night light
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 50, Data: 43 42 01 00 0A 02 01 00 2A 06 98 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 9A 88 B7 D1 06 2A

// System > Display > Night light: Set hours (first) & Sunset to sunrise (second)
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 A2 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 49, Data: 43 42 01 00 0A 02 01 00 2A 06 A4 88 B7 D1 06 2A

// System > Display > Night light: Turn on 5PM, Turn off 8AM
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 A8 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AA 88 B7 D1 06 2A

// System > Display > Night light: Turn on 6PM, Turn off 9AM
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AC 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AE 88 B7 D1 06 2A
```


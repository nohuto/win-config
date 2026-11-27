# Mouse Values

## RawMouseThrottle Details

By default, raw mouse throttling is enabled with `RawMouseThrottleDuration = 8`, which means `~125Hz` for throttled background raw mouse listeners. It's not forced by default (`RawMouseThrottleForced = 0`), so mouse raw input listeners that register with `usUsagePage = 1`, `usUsage = 2` ([0x02, Mouse, HID_USAGE_GENERIC_MOUSE](https://learn.microsoft.com/en-us/windows-hardware/drivers/hid/hid-usages#usage-id)), and include `dwFlags = 0x8000` with `256` or `0x1000` can bypass background throttling.

### Defaults / Ranges

All four values (exist since W11 22H2) are stored as small records on [`CMouseSensor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/--0CMouseSensor@@IEAA@XZ.c) (name, current value, minimum, maximum).

| Value | Default | Range | Meaning |
| --- | --- | --- | --- |
| `RawMouseThrottleEnabled` | `1` | `0-1` | Enables the throttle part. |
| `RawMouseThrottleForced` | `0` | `0-1` | Controls whether mouse raw input listeners with the `0x800` flag are excluded from throttling or can still be throttled. |
| `RawMouseThrottleDuration` | `8` | `1-20` | Milliseconds, converted to QPC ticks and used for throttle limits. Controls the throttle interval (in ms) for delivering raw mouse input to background windows. "We set out to reduce the amount of processing time it took to handle input requests by throttling and coalescing background raw mouse listeners and capping their message rate." |
| `RawMouseThrottleLeeway` | `2` | `0-5` | Milliseconds, converted to QPC ticks and subtracted from duration. |

```c
// CMouseSensor::CMouseSensor (win32kbase, 23H2)

*((_QWORD *)this + 170) = L"RawMouseThrottleEnabled"; // 1360
*((_QWORD *)this + 173) = L"RawMouseThrottleForced"; // 1384
*((_QWORD *)this + 176) = L"RawMouseThrottleDuration"; // 1408
*((_QWORD *)this + 179) = L"RawMouseThrottleLeeway"; // 1432

*((_QWORD *)this + 171) = 1LL; // Enabled, current = 1, min = 0
*((_QWORD *)this + 172) = 1LL; // Enabled, max = 1

*((_QWORD *)this + 174) = 0LL; // Forced, current = 0, min = 0
*((_QWORD *)this + 175) = 1LL; // Forced, max = 1

*((_DWORD *)this + 354) = 8; // Duration, current = 8ms
*((_DWORD *)this + 355) = 1; // Duration, min = 1ms
*((_QWORD *)this + 178) = 20LL; // Duration, max = 20ms

*((_QWORD *)this + 180) = 2LL; // Leeway, current = 2ms, min = 0ms
*((_QWORD *)this + 181) = 5LL; // Leeway, max = 5ms

*((_DWORD *)this + 364) = 50; // unnamed timer? (gets passed into ArmRawMouseThrottlingTimer)
*((_QWORD *)this + 183) = 0LL; // Duration QPC ticks (see below)
*((_QWORD *)this + 184) = 0LL; // Leeway QPC ticks ^
```

QPC = [QueryPerformanceCounter](https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) ([more details](https://learn.microsoft.com/en-us/windows/win32/sysinfo/acquiring-high-resolution-time-stamps)), "*Retrieves the current value of the performance counter, which is a high resolution (<1us) time stamp that can be used for time-interval measurements.*" (the settings are written in milliseconds, but the throttle part compares high resolution QPC timestamps, so duration/leeway are converted from ms to QPC ticks)

```c
durationQpc = gliQpcFreq.QuadPart * durationMs / 1000
```
`gliQpcFreq.QuadPart` = QPC frequency, means QPC ticks per second:
```powershell
Add-Type 'using System.Runtime.InteropServices; public class Q { [DllImport("kernel32")] public static extern bool QueryPerformanceFrequency(out long f); }'
[long]$f = 0
[Q]::QueryPerformanceFrequency([ref]$f) | Out-Null
$f
```
So if the output is for example `10000000`:
```c
durationQpc = 10000000 * 8 / 1000 // 80,000 ticks
```

### Reading / Updating Values

The values are reread through [`ReadRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/ReadRawMouseThrottlingThresholds.c), which is the function that finds the session `CMouseSensor` and calls [`CMouseSensor::ReadRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/-ReadRawMouseThrottlingThresholds@CMouseSensor@@QEAAXPEAU_UNICODE_STRING@@@Z.c). Each value is accepted only if it's inside its range, so invalid values are ignored. [`GetRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/GetRawMouseThrottlingThresholds.c) copies the current values for callers like [`ThrottleRawMouseInputToBackgroundListener`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-ThrottleRawMouseInputToBackgroundListener@@YA_NPEAUtagPROCESS_HID_TABLE@@PEAXPEBUtagRAWMOUSE@@_.c), or returns defaults if no sensor exists.

```c
// CMouseSensor::ReadRawMouseThrottlingThresholds (win32kbase, 23H2)

lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1360); // Enabled
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1384); // Forced
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1408); // Duration
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1432); // Leeway

*((_QWORD *)this + 183) = gliQpcFreq.QuadPart * (unsigned __int64)*((unsigned int *)this + 354) / 0x3E8; // Duration ms -> QPC ticks

*((_QWORD *)this + 184) = gliQpcFreq.QuadPart * (unsigned __int64)*((unsigned int *)this + 360) / 0x3E8; // Leeway ms -> QPC ticks
```

[_lambda_39f407e4fe10312c322b3b59a6fe001c_--operator().c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/_lambda_39f407e4fe10312c322b3b59a6fe001c_--operator%28%29.c)

```c
// _lambda_39f407e4fe10312c322b3b59a6fe001c_::operator() (win32kbase, 23H2)

v4 = *(_DWORD *)(a2 + 8); // current value becomes fallback/default
v5 = *(const WCHAR **)a2; // name
v7 = 0;

FastGetProfileDwordEx(v3, 0xCu, v5, v4, 0, &v7, 0LL); // reads profile using the name (v5)

if ( v7 >= *(_DWORD *)(a2 + 12) && v7 <= *(_DWORD *)(a2 + 16) )
  *(_DWORD *)(a2 + 8) = v7; // accept only if in range
```

### Throttle Checks

[`ThrottleRawMouseInputToBackgroundListener`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-ThrottleRawMouseInputToBackgroundListener@@YA_NPEAUtagPROCESS_HID_TABLE@@PEAXPEBUtagRAWMOUSE@@_.c) reads the settings and decides whether the current raw mouse event can enter the throttle part. Look at [`GetRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/GetRawMouseThrottlingThresholds.c) to understand the comments.

```c
// ThrottleRawMouseInputToBackgroundListener (win32kfull, 23H2)

RawMouseThrottlingThresholds = GetRawMouseThrottlingThresholds(v18);
v15 = *(_OWORD *)(RawMouseThrottlingThresholds + 48); // Duration
v16 = *(_OWORD *)(RawMouseThrottlingThresholds + 96); // unnamed timer + durationQpc
v17 = *(_QWORD *)(RawMouseThrottlingThresholds + 112); // leewayQpc

if ( !_mm_cvtsi128_si32(_mm_srli_si128(*(__m128i *)RawMouseThrottlingThresholds, 8)) // Enabled.Current == 0 -> no throttling
  || (*((_DWORD *)a1 + 25) & 0x800) != 0
     && !(unsigned int)*(_OWORD *)(RawMouseThrottlingThresholds + 32) // 0x800 set && Forced.Current == 0 -> no throttling
  || *(_WORD *)a3
  || *((_DWORD *)a3 + 1)
  || *((_DWORD *)a1 + 28) == 2
     && !CanCoalesceRawInputPayload(a1, a2, a3) ) // already throttling
{
  FlushThrottledRawMouseInput(a1, a5);
  return 0;
}
```

Means `RawMouseThrottleEnabled` = `0` flushes any throttled input for that listener and returns no throttle, `1` = allows later throttle checks to run. `RawMouseThrottleForced` only matters for listeners with the `0x800` flag, `0` makes that case bypass throttling, `1` lets it throttle.

That `0x800` flag isn't related to what device you use, it's set from mouse raw input [registrations](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerrawinputdevices) where [`RAWINPUTDEVICE`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-rawinputdevice) uses `usUsagePage = 1`, `usUsage = 2` ([0x02, Mouse, HID_USAGE_GENERIC_MOUSE](https://learn.microsoft.com/en-us/windows-hardware/drivers/hid/hid-usages#usage-id)), and `dwFlags` has `0x8000` together with `256` ("*If set, this enables the caller to receive the input even when the caller is not in the foreground. Note that hwndTarget must be specified.*") or `0x1000` ("*If set, this enables the caller to receive input in the background only if the foreground application does not process it. In other words, if the foreground application is not registered for raw input, then the background application that is registered will receive the input.*").

I've checked that the `0x800` behavior is true with two small apps, one registered mouse raw input with `0x8100`, the other with only `0x0100`. By moving both to the background (`RawMouseThrottleDuration = 20`), the `0x8100` app stayed at `~1000 Hz`, while the `0x0100` app dropped to `~60 Hz`. So with `RawMouseThrottleForced = 0`, the forced registration bypassed throttling (I didn't find any app that uses that flag nor are there docs on it, means it's most likely unused).

You can use [riflags](https://noverse.dev/docs/win-config/peripheral/mouse-values/#riflags) to see which processes have a mouse registration with `0x8000`. Read through the section for more details.

### Duration / Leeway

When the listener isn't already in a throttle cycle, state `0` becomes state `1`, and duration/leeway create thresholds.

```c
// ThrottleRawMouseInputToBackgroundListener (win32kfull, 23H2)

// state 0 -> state 1
if ( !v11 )
{
  *((_DWORD *)a1 + 28) = 1; // state = 1
  *((_QWORD *)a1 + 15) = a4
                        + *((_QWORD *)&v16 + 1)
                        + *((_QWORD *)&v16 + 1) * (unsigned __int64)((unsigned int)rand() % DWORD2(v15)) / DWORD2(v15); // now + durationQpc + randomized extra, DWORD2(v15) == Duration.Current

  v12 = *((_QWORD *)&v16 + 1) - v17 + a4; // now + durationQpc - leewayQpc
  if ( v12 <= a4 )
    v12 = a4; // clamp so threshold cannot be earlier than current event time
  *((_QWORD *)a1 + 16) = v12;
  return 0;
}
```

If the next event starts while state is `1`, it compares the event time against the earlier threshold:

```c
// ThrottleRawMouseInputToBackgroundListener (win32kfull, 23H2)

if ( *((_DWORD *)a1 + 28) == 1 )
{
  if ( a4 < *((_QWORD *)a1 + 16) )
  {
    if ( a4 > *((_QWORD *)a1 + 15) )
      MicrosoftTelemetryAssertTriggeredArgsKM((int)"IXPTelAssert", 0x20000, 401);
  }
  else
  {
    *((_DWORD *)a1 + 28) = 0; // event is late enough to start a new window
  }
}
```

`RawMouseThrottleDuration` increases the throttle window, has minimum `1` (which prevents division by 0). Bigger `RawMouseThrottleLeeway` makes the earliest allowed next point happen sooner (`durationQpc - leewayQpc`) within that duration window, but it is clamped, examples:

```
earliest passthrough ~= now + duration - leeway

Duration = 8ms ~= 125Hz
  Leeway = 0ms -> earliest passthrough ~= now + 8ms
  Leeway = 2ms -> earliest passthrough ~= now + 6ms
  Leeway = 5ms -> earliest passthrough ~= now + 3ms

Duration = 20ms ~= 50Hz
  Leeway = 0ms -> earliest passthrough ~= now + 20ms
  Leeway = 2ms -> earliest passthrough ~= now + 18ms
  Leeway = 5ms -> earliest passthrough ~= now + 15ms
```

### riflags

[`riflags`](https://github.com/nohuto/utils/releases/download/0.1.0/riflags.zip) checks current raw input registrations, it injects `riprobe.dll` into each running process, calls `GetRegisteredRawInputDevices` there, then unloads the probe again.

Download and extract [riflags.zip](https://github.com/nohuto/utils/releases/download/0.1.0/riflags.zip), keeping `riflags.exe` & `riprobe.dll` in the same folder, or build it yourself from [source](https://github.com/nohuto/utils/tree/main/riflags) via:

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\riflags.exe
```

| Result | Meaning |
| --- | --- |
| `forced` | Forced relevant mouse raw input = `RawMouseThrottleForced = 1` would be effective for it |
| `mouse` | Mouse raw input, but not forced relevant |
| `raw_other` | Raw input exists, but not forced mouse raw input |
| `none` | The process has no raw input registrations |
| `denied`, `load_fail`, `load_timeout`, `dump_fail`, `dump_timeout`, `failed`, `unknown` | Missing permissions, etc. |

### Validating Interpretations

I built two small raw mouse listeners for comparing the two registration modes:

- `ri_0100.exe` registers with `0x0100` ([`RIDEV_INPUTSINK`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-rawinputdevice)), that's the normal background raw mouse listener
- `ri_8100.exe` registers with `0x8100`, that uses the `0x800` raw input flag, so `RawMouseThrottleForced = 0` should let this case bypass throttling

Again, you can either use the prebuild binary ([ri_0100.exe](https://github.com/nohuto/utils/releases/download/0.1.0/ri_0100.exe), [ri_8100.exe](https://github.com/nohuto/utils/releases/download/0.1.0/ri_8100.exe)) or build it yourself from [source](https://github.com/nohuto/utils/tree/main/ri_flagtest) via:

```powershell
cmake -S . -B build
cmake --build .\build --config Release

.\build\Release\ri_0100.exe
.\build\Release\ri_8100.exe
```

#### Result

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/RawMouseThrottleForced.png?raw=true)

## Miscellaneous Values

The main option doesn't change `MouseSensitivity` (leaves it at `10`).

It's recommended to change the pointer speed via `Bluetooth & devices > Mouse`, instead of `Mouse Properties`. Reason is simply that via `Mouse Properties` only exposes 1, 2, 4, 6, 8, 10... 20 (step = 2 steps), the system settings exposes every single step (they both do the exact same).

```c
"HKCU\\Control Panel\\Mouse";
    "DoubleClickHeight" = "4"; // REG_SZ
    "DoubleClickSpeed" = "500"; // REG_SZ, ms between two clicks
    "DoubleClickWidth" = "4"; // REG_SZ
    "MouseHoverHeight" = "4"; // REG_SZ, pixels
    "MouseHoverTime" = "400"; // https://noverse.dev/docs/win-config/visibility/mouse-hover-time/
    "MouseHoverWidth" = "4"; // REG_SZ, pixels
    "MouseSensitivity" = "10"; // REG_SZ, 1-20, pointer speed
    "MouseSpeed" = "1"; // REG_SZ, 0 = Enhance pointer precision off, other = on
    "MouseThreshold1" = "6"; // REG_SZ
    "MouseThreshold2" = "10"; // REG_SZ
    "MouseTrails" = "0"; // REG_SZ
    "SmoothMouseXCurve" = 00 00 00 00 00 00 00 00 15 6e 00 00 00 00 00 00 00 40 01 00 00 00 00 00 29 dc 03 00 00 00 00 00 00 00 28 00 00 00 00 00; // REG_BINARY, Enhance pointer precision curve
    "SmoothMouseYCurve" = 00 00 00 00 00 00 00 00 fd 11 01 00 00 00 00 00 00 24 04 00 00 00 00 00 00 fc 12 00 00 00 00 00 00 c0 bb 01 00 00 00 00; // REG_BINARY
    "SnapToDefaultButton" = "0"; // REG_SZ
    "SwapMouseButtons" = "0"; // REG_SZ
    "ReverseMouseWheelDirection" = 0; // REG_DWORD, 1 = down motion scrolls up (W11)

"HKCU\\Control Panel\\Desktop";
    "MouseWheelRouting" = 2; // REG_DWORD, 0 = window with focus, 1 = focus for desktop apps and pointer for Store apps, 2 = window under the pointer
    "WheelScrollLines" = "3"; // REG_SZ, 1-100 lines, -1 = one screen
    "WheelScrollChars" = "3"; // REG_SZ

"HKCU\\Control Panel\\Cursors";
    "CursorDeadzoneJumpingSetting" = 1; // REG_DWORD, 1 = pointer jumps over the seam of misaligned displays, 0 = stops at the edge (W11)
```

`ActiveWindowTracking`, `Beep`, `ExtendedSounds` also are in `HKCU\Control Panel\Mouse` but nothing reads them.

Enabling/disabling `Enhance pointer precision` sets:

```c
// Enabled
HKCU\Control Panel\Mouse\MouseThreshold1	Type: REG_SZ, Length: 4, Data: 6
HKCU\Control Panel\Mouse\MouseThreshold2	Type: REG_SZ, Length: 6, Data: 10
HKCU\Control Panel\Mouse\MouseSpeed	Type: REG_SZ, Length: 4, Data: 1
//HKCU\Control Panel\Mouse\MouseSensitivity	Type: REG_SZ, Length: 6, Data: 10 // pointer speed, reapplies current active speed

// Disabled
HKCU\Control Panel\Mouse\MouseThreshold1	Type: REG_SZ, Length: 4, Data: 0
HKCU\Control Panel\Mouse\MouseThreshold2	Type: REG_SZ, Length: 4, Data: 0
HKCU\Control Panel\Mouse\MouseSpeed	Type: REG_SZ, Length: 4, Data: 0
//HKCU\Control Panel\Mouse\MouseSensitivity	Type: REG_SZ, Length: 6, Data: 10 // pointer speed, reapplies current active speed
```


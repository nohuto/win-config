# Mouse Values

## RawMouseThrottle Details

By default, raw mouse throttling is enabled with `RawMouseThrottleDuration = 8`, which means `~125Hz` for throttled background raw mouse listeners. It's not forced by default (`RawMouseThrottleForced = 0`), so mouse raw input listeners that register with `usUsagePage = 1`, `usUsage = 2` ([0x02, Mouse, HID_USAGE_GENERIC_MOUSE](https://learn.microsoft.com/en-us/windows-hardware/drivers/hid/hid-usages#usage-id)), and include `dwFlags = 0x8000` with `256` or `0x1000` can bypass background throttling.

Note that is my current interpretation, don't see this as my final answer nor as correct. All used functions are somewhere linked.

### Defaults / Ranges

All four values are stored as small records on [`CMouseSensor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/--0CMouseSensor%40%40IEAA%40XZ.c) (name, current value, minimum, maximum).

| Value | Default | Range | Meaning |
| --- | --- | --- | --- |
| `RawMouseThrottleEnabled` | `1` | `0-1` | Enables the throttle part. |
| `RawMouseThrottleForced` | `0` | `0-1` | Controls whether mouse raw input listeners with the `0x800` flag are exlcuded from throttling or can still be throttled. |
| `RawMouseThrottleDuration` | `8` | `1-20` | Milliseconds, converted to QPC ticks and used for throttle limits. Controls the throttle interval (in ms) for delivering raw mouse input to background windows. "We set out to reduce the amount of processing time it took to handle input requests by throttling and coalescing background raw mouse listeners and capping their message rate." |
| `RawMouseThrottleLeeway` | `2` | `0-5` | Milliseconds, converted to QPC ticks and subtracted from duration. |

```c
// CMouseSensor::CMouseSensor
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

The values are reread through [`ReadRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/ReadRawMouseThrottlingThresholds.c), which is the function that finds the session `CMouseSensor` and calls [`CMouseSensor::ReadRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/-ReadRawMouseThrottlingThresholds@CMouseSensor@@QEAAXPEAU_UNICODE_STRING@@@Z.c). Each value is accepted only if it's inside it's range, so invalid values are ignored. [`GetRawMouseThrottlingThresholds`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/GetRawMouseThrottlingThresholds.c) copies the current values for callers like [`ThrottleRawMouseInputToBackgroundListener`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-ThrottleRawMouseInputToBackgroundListener%40%40YA_NPEAUtagPROCESS_HID_TABLE%40%40PEAXPEBUtagRAWMOUSE%40%40_.c), or returns defaults if no sensor exists.

```c
// CMouseSensor::ReadRawMouseThrottlingThresholds
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1360); // Enabled
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1384); // Forced
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1408); // Duration
lambda_39f407e4fe10312c322b3b59a6fe001c_::operator()((__int64 **)&v3, (__int64)this + 1432); // Leeway

*((_QWORD *)this + 183) = gliQpcFreq.QuadPart * (unsigned __int64)*((unsigned int *)this + 354) / 0x3E8; // Duration ms -> QPC ticks

*((_QWORD *)this + 184) = gliQpcFreq.QuadPart * (unsigned __int64)*((unsigned int *)this + 360) / 0x3E8; // Leeway ms -> QPC ticks
```

[_lambda_39f407e4fe10312c322b3b59a6fe001c_--operator().c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/_lambda_39f407e4fe10312c322b3b59a6fe001c_--operator().c)

```c
// _lambda_39f407e4fe10312c322b3b59a6fe001c_--operator()
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
// ThrottleRawMouseInputToBackgroundListener
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
// ThrottleRawMouseInputToBackgroundListener

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
// ThrottleRawMouseInputToBackgroundListener
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

[`riflags`](https://github.com/nohuto/win-config/blob/main/peripheral/assets/riflags.exe) checks current raw input registrations, it injects [`riprobe.dll`](https://github.com/nohuto/win-config/blob/main/peripheral/assets/riprobe.dll) into each running process, calls `GetRegisteredRawInputDevices` there, then unloads the probe again.

You can either use the prebuild binary ([riflags.exe](https://github.com/nohuto/win-config/blob/main/peripheral/assets/riflags.exe), [riprobe.dll](https://github.com/nohuto/win-config/blob/main/peripheral/assets/riprobe.dll)) or build it yourself from [source](https://github.com/nohuto/win-config/tree/main/peripheral/assets/riflags) via:

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

I've builds two small raw mouse listeners for comparing the two registration modes:

- `ri_0100.exe` registers with `0x0100` ([`RIDEV_INPUTSINK`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-rawinputdevice)), thats's the normal background raw mouse listener
- `ri_8100.exe` registers with `0x8100`, that uses the `0x800` raw input flag, so `RawMouseThrottleForced = 0` should let this case bypass throttling

Again, you can either use the prebuild binary ([ri_0100.exe](https://github.com/nohuto/win-config/blob/main/peripheral/assets/ri_0100.exe), [ri_8100.exe](https://github.com/nohuto/win-config/blob/main/peripheral/assets/ri_8100.exe)) or build it yourself from [source](https://github.com/nohuto/win-config/tree/main/peripheral/assets/ri_flagtest) via:

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

It's recommended to change the pointer speed via `Bluetooth & devices > Mouse`, instead of `Mouse Properties`. Reason is simply that via `Mouse Properties` is only exposes 1, 2, 4, 6, 8, 10... 20 (step = 2 steps), the system settings exposes every single step (they both do the exact same).

Located in `HKCU\\Control Panel\\Mouse`:

| Value | Type | Description |
| --- | --- | --- |
| `ActiveWindowTracking` | `REG_DWORD` | If enabled the active window is the one the mouse is positioned on. |
| `DoubleClickSpeed` | `REG_SZ` | Controls how much time may pass between two clicks before Windows no longer treats them as a double-click. |
| `DoubleClickHeight` | `REG_SZ` | Sets the amount of movement allowed (vertical) for a double-click to be valid. |
| `DoubleClickWidth` | `REG_SZ` | Sets the amount of movement allowed (horizontal) for a double-click to be valid. |
| `MouseSpeed` | `REG_SZ` | Controls mouse pointer scaling (speed of the mouse pointer relative to the movement of the mouse). Higher acceleration levels increase pointer speed. |
| `MouseThreshold1` | `REG_SZ` | Adjusts the first acceleration threshold used for mouse movement scaling (motion factor that, when factored with MouseSpeed, controls the motion of the mouse). |
| `MouseThreshold2` | `REG_SZ` | Adjusts the second acceleration threshold used for mouse movement scaling (motion factor that, when factored with MouseSpeed, controls the motion of the mouse). |
| `MouseTrails` | `REG_SZ` | If `0` there're no trails, if above `0` there're tails. The higher the number, the more trails there are. |
| `SmoothMouseXCurve` | `REG_BINARY` | Defines the X-axis smoothing curve used for mouse movement interpolation. |
| `SmoothMouseYCurve` | `REG_BINARY` | Defines the Y-axis smoothing curve used for mouse movement interpolation. |
| `SnapToDefaultButton` | `REG_SZ` | Automatically moves the pointer to the default button when a new dialog or window appears. |
| `SwapMouseButtons` | `REG_SZ` | Swaps the left and right mouse buttons, mainly for left-handed use. |

Located in `HKCU\\Control Panel\\Cursors`:

| Value | Type | Description |
| --- | --- | --- |
| `CursorDeadzoneJumpingSetting` | `REG_DWORD` | Controls whether the pointer jumps over the non-overlapping seam between misaligned monitors so that it doesn't get stuck on edges/corners when switching between screens. If this option is disabled, the cursor will stop at these seams instead of crossing them. |

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

Scrolling related values:

```c
// Roll the mouse whell to scroll (just a toggle to let users use 'Lines to scroll at a time')
// One screen at a time (this data would gray out 'Lines to scroll at a time') = -1
// Lines to scroll at a time =  1-100
HKCU\Control Panel\Desktop\WheelScrollLines	Type: REG_SZ

// Scroll inactive windows when hovering over them
// On = 2
// Off = 0
HKCU\Control Panel\Desktop\MouseWheelRouting	Type: REG_DWORD

// Scroll direction
// Down motion scrolls down = 0
// Down motion scrolls up = 1
HKCU\Control Panel\Mouse\ReverseMouseWheelDirection	Type: REG_DWORD
```

# Sample Rate

The values below are related to Default Format, see [property-sets](https://winsps-kb.readthedocs.io/en/latest/sources/property-sets/) for a list of more names.

The main option lists sample rates that are supported on both active endpoints, if you want to change them individually use the suboptions which list supported sample rates for render/capture endpoints.

Microsoft documents endpoint properties as values that clients can read but "*shouldn't set*". The supported way to inspect/validate formats is Core Audio / WASAPI, especially [`IAudioClient::GetMixFormat`](https://learn.microsoft.com/en-us/windows/win32/api/audioclient/nf-audioclient-iaudioclient-getmixformat) and [`IAudioClient::IsFormatSupported`](https://learn.microsoft.com/en-us/windows/win32/api/audioclient/nf-audioclient-iaudioclient-isformatsupported). Editing the registry can leave the UI, AudioEndpointBuilder, the audio engine, the driver, and APO/effects state out of sync (e.g., what happened to me while working on the doc: using the same for example `16` (`10 00`) multiplier for all even tho 2 of them use `32` (`20 00`) the playback device won't output audio, but will show the changes in the windows UI).

The structure is `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\{Render\|Capture}\{Endpoint}`.

- `Render` = Playback
- `Capture` = Recording

You can use [`dumpAudioFormats.ps1`](https://github.com/nohuto/win-config/blob/main/peripheral/assets/dumpAudioFormats.ps1) to read the values listed below from `Render`/`Capture` endpoints & output the sample rate, channel count, bit depth, block align, and byte-rate consistency for each 48 byte `WAVEFORMATEXTENSIBLE` data.

## Registry Values

These are the values which include the single 48 byte `WAVEFORMATEXTENSIBLE` part, the first four ones are the ones which got changed while editing playback/record rates via `mmsys.cpl`, the last seems to be related to it.

| Value name | Meaning |
| --- | --- |
| `{f19f064d-082c-4e27-bc73-6882a1bb8e4c},0` | [`PKEY_AudioEngine_DeviceFormat`](https://learn.microsoft.com/en-us/windows/win32/coreaudio/pkey-audioengine-deviceformat) - "*The PKEY_AudioEngine_DeviceFormat property specifies the device format, which is the format that the user has selected for the stream that flows between the audio engine and the audio endpoint device when the device operates in shared mode. This format might not be the best default format for an exclusive-mode application to use.*" |
| `{e4870e26-3cc5-4cd2-ba46-ca0a9a70ed04},0` | PID 0 value under the same GUID as [`PKEY_AudioEngine_OEMFormat`](https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/pkey-audioengine-oemformat). |
| `{3d6e1656-2e50-4c4c-8d85-d0acae3c6c68},3` | - |
| `{624f56de-fd24-473e-814a-de40aacaed16},3` | - |
| `{3d6e1656-2e50-4c4c-8d85-d0acae3c6c68},2` | - |

## Binary Data

The 48 byte values are serialized `PROPVARIANT` values including a 40 byte `WAVEFORMATEXTENSIBLE` structure.

### Practical Example

```ini
41 00 00 00 01 00 00 00 ; PROPVARIANT header
FE FF 08 00 80 BB 00 00 ; wFormatTag, nChannels, nSamplesPerSec
00 B8 0B 00 10 00 10 00 ; nAvgBytesPerSec, nBlockAlign, wBitsPerSample
16 00 10 00 3F 06 00 00 ; cbSize, valid bits, channel mask
01 00 00 00 00 00 10 00 ; SubFormat GUID
80 00 00 AA 00 38 9B 71 ; SubFormat GUID
```

| Offset | Field | Bytes | Value |
| --- | --- | --- | --- |
| `0x00` | Serialized property type/header | `41 00 00 00` | `VT_BLOB` (`65`) |
| `0x04` | Serialized property metadata | `01 00 00 00` | - |
| `0x08` | `Format.wFormatTag` | `FE FF` | `WAVE_FORMAT_EXTENSIBLE` |
| `0x0A` | `Format.nChannels` | `08 00` | `8` channels |
| `0x0C` | `Format.nSamplesPerSec` | `80 BB 00 00` | `48000` Hz |
| `0x10` | `Format.nAvgBytesPerSec` | `00 B8 0B 00` | `768000` bytes/sec |
| `0x14` | `Format.nBlockAlign` | `10 00` | `16` bytes per audio frame |
| `0x16` | `Format.wBitsPerSample` | `10 00` | `16` bit container |
| `0x18` | `Format.cbSize` | `16 00` | - |
| `0x1A` | `Samples.wValidBitsPerSample` | `10 00` | `16` valid bits |
| `0x1C` | `dwChannelMask` | `3F 06 00 00` | - |
| `0x20` | `SubFormat` | `01 00 ... 9B 71` | PCM GUID `00000001-0000-0010-8000-00aa00389b71` |

`41 00 00 00 01 00 00 00` isn't [`WAVEFORMATEX`](https://learn.microsoft.com/en-us/windows/win32/api/mmeapi/ns-mmeapi-waveformatex), the wave format starts at offset `0x08`.

### Required Field Consistency

For PCM or `WAVE_FORMAT_EXTENSIBLE`, these fields must match:

```
nBlockAlign = nChannels * wBitsPerSample / 8
nAvgBytesPerSec = nSamplesPerSec * nBlockAlign
```

`nBlockAlign` is bytes per complete interleaved audio frame:

| `nChannels` | `wBitsPerSample` | `nBlockAlign` |
| --- | --- | --- |
| 1 | 16 | 2 |
| 1 | 32 | 4 |
| 2 | 16 | 4 |
| 2 | 24 | 6 |
| 2 | 32 | 8 |
| 8 | 16 | 16 |
| 8 | 24 | 24 |
| 8 | 32 | 32 |

Sample rate table for common `nBlockAlign` values:

| Sample rate | `nSamplesPerSec` bytes | Avg bytes/sec if `align=16` | Bytes | Avg bytes/sec if `align=32` | Bytes |
| ---: | --- | ---: | --- | ---: | --- |
| 8000 | `40 1F 00 00` | 128000 | `00 F4 01 00` | 256000 | `00 E8 03 00` |
| 11025 | `11 2B 00 00` | 176400 | `10 B1 02 00` | 352800 | `20 62 05 00` |
| 16000 | `80 3E 00 00` | 256000 | `00 E8 03 00` | 512000 | `00 D0 07 00` |
| 22050 | `22 56 00 00` | 352800 | `20 62 05 00` | 705600 | `40 C4 0A 00` |
| 32000 | `00 7D 00 00` | 512000 | `00 D0 07 00` | 1024000 | `00 A0 0F 00` |
| 44100 | `44 AC 00 00` | 705600 | `40 C4 0A 00` | 1411200 | `80 88 15 00` |
| 48000 | `80 BB 00 00` | 768000 | `00 B8 0B 00` | 1536000 | `00 70 17 00` |
| 88200 | `88 58 01 00` | 1411200 | `80 88 15 00` | 2822400 | `00 11 2B 00` |
| 96000 | `00 77 01 00` | 1536000 | `00 70 17 00` | 3072000 | `00 E0 2E 00` |
| 176400 | `10 B1 02 00` | 2822400 | `00 11 2B 00` | 5644800 | `00 22 56 00` |
| 192000 | `00 EE 02 00` | 3072000 | `00 E0 2E 00` | 6144000 | `00 C0 5D 00` |
| 352800 | `20 62 05 00` | 5644800 | `00 22 56 00` | 11289600 | `00 44 AC 00` |
| 384000 | `00 DC 05 00` | 6144000 | `00 C0 5D 00` | 12288000 | `00 80 BB 00` |

If an endpoint uses `nBlockAlign = 24`, use `sampleRate * 24` instead.

## WAVEFORMAT* Structures

Offsets below are relative to the start of the `WAVEFORMATEXTENSIBLE` structure, in the registry data shown above, add `0x08` to get the absolute registry offset.

```cpp
// WAVEFORMATEX
typedef struct tWAVEFORMATEX {
  WORD  wFormatTag;       // +0x00, 2 bytes
  WORD  nChannels;        // +0x02, 2 bytes
  DWORD nSamplesPerSec;   // +0x04, 4 bytes
  DWORD nAvgBytesPerSec;  // +0x08, 4 bytes
  WORD  nBlockAlign;      // +0x0C, 2 bytes
  WORD  wBitsPerSample;   // +0x0E, 2 bytes
  WORD  cbSize;           // +0x10, 2 bytes
} WAVEFORMATEX, *PWAVEFORMATEX, *NPWAVEFORMATEX, *LPWAVEFORMATEX; // 18 bytes total

// WAVEFORMATEXTENSIBLE
typedef struct {
  WAVEFORMATEX Format; // +0x00, 18 bytes
  union {
    WORD wValidBitsPerSample; // +0x12, 2 bytes
    WORD wSamplesPerBlock;    // +0x12, 2 bytes
    WORD wReserved;           // +0x12, 2 bytes
  } Samples;
  DWORD        dwChannelMask; // +0x14, 4 bytes
  GUID         SubFormat;     // +0x18, 16 bytes
} WAVEFORMATEXTENSIBLE, *PWAVEFORMATEXTENSIBLE; // 40 bytes total
```

## General Knowledge

The sample rate is how many times per second an audio signal is measured. `44.1` kHz means `44,100` samples per second, `48` kHz means `48,000` samples per second.

Bit depth is how many bits are used to store each sample. More bits allow more possible sample values and a larger dynamic range.

| Bit depth | Possible values |
| --- | --- |
| 8 bit | 256 |
| 16 bit | 65,536 |
| 24 bit | 16,777,216 |

For general playback, `44.1` kHz or `48` kHz with `16` or `24` bit depth is normally enough, higher sample rates are mostly useful for specific production.

### 8 Bit / 16 Bit

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/samplerate.png?raw=true)

# Sound Mode

## Spatial Audio

> "*Microsoft Spatial Sound is Microsoft’s platform-level solution for spatial sound support on Xbox, Windows and HoloLens 2, enabling both surround and elevation (above or below the listener) audio cues. Spatial sound can be leveraged by Windows desktop (Win32) apps as well as Universal Windows Platform (UWP) apps on supported platforms. The spatial sound APIs allow developers to create audio objects that emit audio from positions in 3D space.*"
>
> — Microsoft, [Spatial Sound for app developers for Windows, Xbox, and Hololens 2](https://learn.microsoft.com/en-us/windows/win32/coreaudio/spatial-sound)


![](https://github.com/nohuto/win-config/blob/main/peripheral/images/spatial.jpeg?raw=true)

### Registry Values

See '[Audio Values](https://noverse.dev/docs/win-config/peripheral/audio-values/)' for other related values.

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // BlockSpatialAudioRegistryGates
  "DisableSpatialAudioGlobal" = 0; // REG_DWORD (bool)
  "DisableSpatialAudioPerEndpoint" = 1; // REG_DWORD (bool), nonzero = PKEY_Endpoint_SpatialNotAllowed
  "DisableSpatialAudioVssFeature" = 0; // REG_DWORD (bool)
  "SpatialAudioHrtfOnByDefault" = 0; // REG_DWORD (bool)

  // IsSpatialComboEndpointDeterminationDisabled
  "DisableSpatialOnComboEndpoints" = 1; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy\\Spatial";
  // AtmosCheck::GetSpatialAudioLicenseGracePeriodInMs
  "SpatialAudioLicenseCheckStartDelay" = 5; // REG_DWORD, range 1-900000 ms, 0/>900000 = 5 ms

  // IsMultiUserSKU
  "SpatialAudioLicenseCheckRequiresUserContext" = 0; // REG_DWORD (bool)
```

Disabling spatial sound via these values would gray out the option in the device properites, but Windows itself doesn't disable/enable it via them.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/spatialsystemsettings.png?raw=true)

- [BlockSpatialAudioRegistryGates](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv/BlockSpatialAudioRegistryGates.c)
- [IsSpatialComboEndpointDeterminationDisabled](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv/IsSpatialComboEndpointDeterminationDisabled.c)
- [GetSpatialAudioLicenseGracePeriodInMs](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv/-GetSpatialAudioLicenseGracePeriodInMs@AtmosCheck@@CAHXZ.c)
- [IsMultiUserSKU](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv/-IsMultiUserSKU@@YA_NXZ.c)

## Mono/Stereo Audio

Mono combines left and right audio channels into one, stereo uses two channels.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/mono-stereo.jpg?raw=true)

### SystemSettings Capture

```c
// System > Sound : Mono audio

// Enabled
HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 0
```

# Disable Audio Enhancements

Audio enhancements are software based sound processing features that change or improve how playback or microphone audio sounds on a device. In general, they are used to improve clarity, balance volume, reduce noise, boost certain frequencies, or simulate spatial/surround effects, depending on the device and driver, but they can also cause audio issues etc., which is why you may want to disable them.

## Registry Values

The values below are related to `Exclusive Mode`/`Signal Enhancements`, see [property-sets](https://winsps-kb.readthedocs.io/en/latest/sources/property-sets/) for a list of more names.

The structure is `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\{Render\|Capture}\{Endpoint}`.

- `Render` = Playback
- `Capture` = Recording

| Value | Meaning | Data |
| --- | --- | --- |
| `\FxProperties\{1da5d803-d492-4edd-8c23-e0c0ffee7f0e},5` | Audio Enhancements / System Effects ([`PKEY_AudioEndpoint_Disable_SysFx`](https://learn.microsoft.com/en-us/windows/win32/coreaudio/pkey-audioendpoint-disable-sysfx)) - "*The PKEY_AudioEndpoint_Disable_SysFx property specifies whether system effects are enabled in the shared-mode stream that flows to or from the audio endpoint device. System effects are implemented as audio processing objects (APOs) that can be inserted into an audio stream. APOs are software modules that perform audio processing functions such as volume control and format conversion. Disabling the system effects for an endpoint device enables the associated stream to pass through the APOs unmodified.* | `1` = Off, `0` = On | 
| `\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},3` | Allow applications to take exclusive control (`Render_AudioEndpoint_Flag`) | `0` = Off, `1` = On | 
| `\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},4` | Give exclusive mode applications priority (`Render_AudioEndpoint_Flag2`) | `0` = Off, `1` = On |

# USBFlags Values

Value names in [`HUBREG_QueryUsbflagsValuesForDevice.c`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBHUB3/HUBREG_QueryUsbflagsValuesForDevice.c) are mostly UNICODE_STRING globals, the names below are resolved from `dq offset ; "Name"`. The usbflags device key base path is `HKLM\SYSTEM\CurrentControlSet\Control\usbflags` (from `LRegistryMachineSystemCurrentControlSetControlusbflags` in `HUBREG_OpenCreateUsbflagsDeviceKey`).

## Registry Values

`HUBDSM_QueryingRegistryValuesForDevice` -> `HUBMISC_QueryAndCacheRegistryValuesForDevice` -> `HUBREG_QueryUsbflagsValuesForDevice`

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

The value type isn't enforced, so both `REG_DWORD` and `REG_BINARY` should work if they're a 4 byte nonzero value (that's my current assumption). I would personally use `REG_BINARY` instead of `REG_DWORD` for now, as for example `osvc`, `IgnoreHWSerNum`, `ResetOnResume` are `REG_BINARY` ([usb-device-specific-registry-settings.md](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/usbcon/usb-device-specific-registry-settings.md)).

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

You can use [`!usb3kd.device_info`](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/debuggercmds/-usb3kd-device-info.md) to get more information on a USB device in the USB 3.0 tree, example:

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

### [Subkey Structure](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/usbcon/usb-device-specific-registry-settings.md)

The subkeys in `usbflags` always have a length of 12, build in such a structure `vvvvpppprrrr`:
- **vvvv** is a 4-digit hexadecimal number that identifies the vendor
- **pppp** is a 4-digit hexadecimal number that identifies the product
- **rrrr** is a 4-digit hexadecimal number that contains the revision number of the device

The vendor ID, product ID, and revision number values are obtained from the [USB device descriptor](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/usbcon/usb-device-descriptors.md). The USB_DEVICE_DESCRIPTOR structure describes a device descriptor.

| Registry entry | Description | Possible values |
|---|---|---|
| **osvc**<br><br>REG_BINARY | Indicates whether the operating system queried the device for [Microsoft-defined USB descriptors](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/usbcon/microsoft-defined-usb-descriptors.md). If the previously attempted OS descriptor query was successful, the value contains the vendor code from the OS string descriptor. | <ul><li>0x0000: The device didn't provide a valid response to the Microsoft OS string descriptor request.</li><li>0x01xx: The device provided a valid response to the Microsoft OS string descriptor request, where xx is the **bVendorCode** contained in the response.</li></ul> |
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

# USB Values

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

## Registry Values

```c
// HUBREG_QueryGlobalUsb20HardwareLpmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\Usb20HardwareLpm"; // g_Usb20HardwareLpmKeyName
    "Usb20HardwareLpmOverride" = 1; // REG_DWORD
    "Usb20HardwareLpmTimeout" = 2; // REG_DWORD, range 0-255

// HUBREG_OpenQueryAttemptRecoveryFromUsbPowerDrainValue
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\AutomaticSurpriseRemoval"; // g_UsbAutomaticSurpriseRemovalKeyName (aRegistryMachin_6)
    "AttemptRecoveryFromUsbPowerDrain" = 0; // REG_DWORD, is used to stop USB devices when your screen is off, obviously only for laptop users

// HUBREG_QueryUsbHardwareVerifierValue
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\HardwareVerifier"; // g_HwVerifierKeyName
    "<VID><PID><REV>\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, first query
    "<VID><PID>\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, fallback
    "global\\usbUpto20|usb2X|usb30\\device" = ?; // REG_DWORD, last fallback

// HUBREG_QueryGlobalUsbLtmSettings
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\usb\\UsbLtm"; // g_UsbLtmKeyName
    "UsbLtmEnable" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\USB";
    "DualRoleFeaturesTestOverride" = ?; // REG_DWORD
    "UcmIsPresent" = ?; // REG_DWORD

// these are taken from the W10 source, they seem to exist on latest builds (they do exist in usbport.sys on 23H2)

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usb";
    "debuglevel" = 0; // REG_DWORD
    "debuglogmask" = 0xFFFFFFFE; // REG_DWORD
    "debuglogenable" = 1; // REG_DWORD (bool)
    "debugcatc" = 0; // REG_DWORD (bool)
    "DisableSelectiveSuspend" = 0; // REG_DWORD (bool)
    "DisableCcDetect" = 0; // REG_DWORD (bool
    "EnPMDebug" = 0; // REG_DWORD (bool), for debugging power management
    "ForceHcD3NoWakeArm" = 0 // REG_DWORD (bool)
    "EnableDCA" = 0 // REG_DWORD (bool), DCA = direct controller access
    "ForcePortsHighSpeed" = 0; // REG_DWORD (bool), forces ports to stay under EHCI

// "This class is reserved for USB host controllers and USB hubs", I'll add them here as they're also in usbport.sys and also taken from the W10 source

"HKLM\\System\\CurrentControlSet\\Control\\Class\\{36FC9E60-C465-11CF-8056-444553540000}\\<instance>";
    "HcFlavor" = ? // REG_DWORD
    "TotalBusBandwidth" = ? // REG_DWORD
    "HcDisableAllSelectiveSuspend" = 0 (non-IA64), 1 (IA64); // REG_DWORD
    "CommonBuffer2GBLimit" = 0; // REG_DWORD, when nonzero, forces common buffers below 2GB ("Limit common buffer allocations for the miniport to the physical address range below 2GB.  Only bits 0 through 30 of the physical address can be set.  Bit 31 of the physical address cannot be set.")
    "ForceHCResetOnResume" = 0; // REG_DWORD, forces controller reset on resume
    "FastResumeEnable" = 0; // REG_DWORD, fast S0 resume

    //HcDisableSelectiveSuspend

// miscellaneous note for future reference
"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Usb\\Ceip" // UsbhUpdateRegSurpriseRemovalCount
    "BootPathSurpriseRemovalCount" = ?;
```

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

## Miscellaneous Notes

[`AttemptRecoveryFromUsbPowerDrain`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBHUB3/HUBREG_OpenQueryAttemptRecoveryFromUsbPowerDrainValue.c) is used to stop USB devices when your screen is off, obviously only for laptop users.

```
Stop USB devices when my screen is off to help battery.
```
`Bluetooth & devices` > `USB` > `USB battery saver`

# USBHUB Values

For values with "any nonzero" comment, the code treats the DWORD as a boolean, means any nonzero value is equivalent to `1`. Default data is unknown for most values as the driver code only reads the registry and handles fallbacks.

## Registry Values

```c
// HUBREG_QueryGlobalHubValues
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\USBHUB\\hubg"; // g_HubGlobalKeyName
    "DisableSelectiveSuspendUI" = ?; // REG_DWORD
    "MsOsDescriptorMode" = ?; // REG_DWORD, range 0-2
    "EnableDiagnosticMode" = ?; // REG_DWORD
    "DisableOnSoftRemove" = 1; // REG_DWORD
    "DisableUxdSupport" = ?; // REG_DWORD
    "EnableExtendedValidation" = ?; // REG_DWORD
    "WakeOnConnectUI" = ?; // REG_DWORD, nonzero enables wake on connect UI ("This controls the UI check box 'Allow this device to wake the system'. Essentially this is control for the wake on connect feature.")
    "PreventDebounceTimeForSuperSpeedDevices" = ?; // REG_DWORD, nonzero enables extra debounce handling ("Checks if we need to give extra time to SuperSpeed devices before talking to them")

    // miscellaneous ones from GlobalUsbhubValues
    "UsbDebugModeEnable" = ?;
    "BreakOnHubException" = ?;
    "debuglevel" = ?;
    "DebugLogMask" = ?;
    "DebugLogEnable" = ?;
    "DisableHardReset" = ?;
    "BreakOnReplicant" = ?;
    "BreakOnEnumFailure" = ?;
    "UseIoErrorLog" = ?;
    "ForceResetOnResume" = ?;
    "DisableFastResume" = ?;
    "LogSize" = ?;
    "IdleTimeout" = ?;

// HUBREG_QueryGlobalUxdSettings (the defaults were taken from the W10 source)
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\policy"; // g_UxdGlobalSettingsKey (aRegistryMachin_12)
    "UxdGlobalDeleteOnShutdown" = 0; // REG_DWORD
    "UxdGlobalDeleteOnReload" = 0; // REG_DWORD
    "UxdGlobalDeleteOnDisconnect" = 0; // REG_DWORD
    "UxdGlobalEnable" = 0; // REG_DWORD

// HUBREG_QueryUxdDeviceKey / HUBREG_DeleteUxdDeviceKey
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\devices"; // g_UxdDeviceSettingsKey (aRegistryMachin_5)
    "%04X%04X%04X" = ?; // value name from VID/PID/REV

// HUBREG_GetUxdPnpValue
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\uxd_control\\pnp"; // g_UxdGuidSettingsKey (aRegistryMachin_3)
    "{GUID}" = ?; // value name from RtlStringFromGUID
```

### RegistryMachin_* Keys

Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

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

# Keyboard Values

| Setting | Description | Default | Changed To |
| --- | --- | --- | --- |
| **Repeat Delay**      | Controls how long you need to hold down a key before it starts repeating when typing.                    | 1           | 0              |
| **Repeat Rate**       | Adjusts how quickly a key repeats when held down after the repeat delay.                                 | 31          | 31             |
| **Cursor Blink Rate** | Controls the speed at which the text cursor blinks on the screen. You can set it to be faster or slower. | 530         | 900            |

`Disable Language Switch Hotkey` applies: `Time & language > Typing > Advanced keyboard settings : Input language hot keys`, `Between input languages` to `Not assigned` (`None`):
```powershell
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Language Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Layout Hotkey	Type: REG_SZ, Length: 4, Data: 3
```

# Audio Values

You can find all mentioned functions in [decompiled-pseudocode/11-23H2/audiosrv](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv)/[decompiled-pseudocode/11-23H2/audiodg](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiodg)/[decompiled-pseudocode/11-23H2/AudioSrvPolicyManager](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/AudioSrvPolicyManager), everything below is currently based on xrefs of `RegGetValueW`. Since the function names often already tell a lot, I've written them down where they're from. See a boot capture of `CurrentVersion\\Audio` key [here](https://github.com/nohuto/regkit/blob/main/assets/records/Audio.txt).

The titles below tell what binary I've the values from.

## Registry Values

### audiodg.exe

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // AERTMemoryInitOnce
  "SkipRTHeap" = 1; // REG_DWORD (bool), 0 = RT (realtime) heap, nonzero = normal C++ heap (for AERTAllocate & AERTFree)

  // CEndpointInstance::CreateStreamEndpointInstance
  "SuppressBridgeTargetGlitchLogging" = 0; // REG_DWORD (bool)

  // CAudioPump::IsTimerRequired
  "DisablePumpBackupTimer" = ?; // REG_DWORD (bool)

  // _lambda_10c7c3905643286e055343d22ac897fe_::operator()
  "AudioDgWatchDogTimerInMs" = 0; // REG_DWORD, range 0-4294967295 ms, the read value gets overwritten with 0 and I didn't see any other points where the edited value could be used (?)
  "UseNewStreamManagementCodePath" = 1; // REG_DWORD (bool)

  // InitializeCpuManager
  "CpuManagementThresholdHns" = 50000; // REG_DWORD, range 0-4294967295 (100 ns units) means default = 5 ms
  "CpuManagementAudioReservedCpuMask" = 0; // REG_QWORD, range 0-18446744073709551615 (0 = auto)

  // CRTThreadManager::InitializeRTOperatingMode
  "RTOperatingMode" = 3; // REG_DWORD, useful range seems 0-4
                         // 0 uses the shared Audio queue
                         // 1 uses it + one MMCSS queue
                         // 2 creates a base queue + queues per APO
                         // 3 uses the shared queue
                         // 4 creates queues per APO

  // CollectExceptionData
  "PreventAudioDGCrashOrReportOnAPOException" = 0; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Parameters";
  // CAudioPump::Initialize
  "AudioDGCPUPercentMax" = 40; // REG_DWORD, range 10-90 (percent), allowed pump processing time per audio period
  "DeadlineDurationThreshold" = 1000; // REG_DWORD, range 0-4294967295 ms (seems unused)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy";
  // IsSkipAPOFailureCheck
  "SkipAPOFailureCheck" = 0; // REG_DWORD (bool)
```

### AudioSrvPolicyManager.dll

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // CProcess::UseOfResourceAllowed
  "AllowClassicOffload" = 0; // REG_DWORD (bool)

  // GrantExemptionForBCMStartupLatency
  "DisableExemptionForBCMStartupLatency" = 0; // REG_DWORD (bool), 0 = can skip BeginBCMStartupLatencyGracePeriod, nonzero disables the exemption & starts the grace period

  // CAastPreStartContext::RuntimeClassInitialize
  "AastRenderDelayInMs" = 0; // REG_DWORD, range 0-4294967295 ms, delays UpdateEndpointVolume

"HKCU\\Software\\Microsoft\\Multimedia\\Audio";
  // LoadUserSettings
  "UserDuckingPreference" = 1; // REG_DWORD, range 0-3, >3 = 1
                               // 0 = -96 dB
                               // 1 = -18 dB
                               // 2 = -6 dB
                               // 3 = 0 dB
```

### audiosrv.dll

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // DerivePeriodicityForStream
  "SkipPeriodicityValidation" = 0; // REG_DWORD (bool)

  // CEndpointCharacteristics::DiscoverProcessingModeCharacteristics
  "ProbeForMinimumPeriod" = 0; // REG_DWORD (bool), nonzero probes when OEM period data is missing
  "MaxCapturePeriodicityInMs" = 0; // REG_DWORD, 0-4294967295 ms (seems unused)

  // CAudioSrv::Initialize
  "UseNewStreamManagementCodePath" = 1; // REG_DWORD (bool)

  // CAudioSrv::EndInitialization
  "EnableCaptureMonitor" = 1; // REG_DWORD (bool), 0 disables stream/capture monitor

  // EffectPolicy::GetAECInsertionPolicy
  "InboxAECPolicy" = 0; // REG_DWORD, range 0-3
  "InboxAECPolicyCommsTmp" = 1; // REG_DWORD, range 0-3

  // CEndpointCharacteristicsCache::RuntimeClassInitialize
  "GlobalDisableThirdPartyEnhancements" = 0; // REG_DWORD (bool), nonzero skips third party driver effect pack configuration

  // wil::details::functor_wrapper_void__lambda_e80bfd59226b44785138f4bfe7079896____::Run
  "DisableGetMixFormatChange" = 0; // REG_DWORD (bool), nonzero blocks tests/use of an 8 channel mix format?

  // CConstraintModel::Initialize
  "ConstraintModelTest" = 0; // REG_DWORD (bool), nonzero reads XML from ResourceSettings\\XMLConfig key instead of per device keys

  // CAudioDGProcess::InstantiateADG
  "EnableProtectedAudioDG" = 0; // REG_DWORD (bool), nonzero uses protected process AudioDG first (fallback to unprotected)

  // CAudioDGProcess::StartADGTerminationTimer
  "AudioDGInactiveTimeout" = 300; // REG_DWORD, 0-4294967295 sec, inactivity delay before AudioDG termination, 0 schedules instantly

  // CAudioSrv::VAD_AudiosrvServiceStart
  "AudioHealthMonitorLimit" = 5; // REG_DWORD, 0-4294967295 (hangs), 0 disables monitor, if hang amount is positive it terminates AudioSrv
  "AudioSrvWatchDogTimerInMs" = 40000; // REG_DWORD, 0-4294967295 ms
  "RenderStreamVolumeTaperPower" = ?; // REG_SZ
  "UnrestrictedPerProcessLoopback" = 0xFFFFFFFF; // REG_DWORD (bool)

  // MyServiceInitialization
  "DevApiIsRunningInVM" = 0; // REG_DWORD (bool)

  // BlockSpatialAudioRegistryGates
  "DisableSpatialAudioGlobal" = 0; // REG_DWORD (bool)
  "DisableSpatialAudioPerEndpoint" = 1; // REG_DWORD (bool), nonzero = PKEY_Endpoint_SpatialNotAllowed
  "DisableSpatialAudioVssFeature" = 0; // REG_DWORD (bool)
  "SpatialAudioHrtfOnByDefault" = 0; // REG_DWORD (bool)

  // IsSpatialComboEndpointDeterminationDisabled
  "DisableSpatialOnComboEndpoints" = 1; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy\\Spatial";
  // AtmosCheck::GetSpatialAudioLicenseGracePeriodInMs
  "SpatialAudioLicenseCheckStartDelay" = 5; // REG_DWORD, range 1-900000 ms, 0/>900000 = 5 ms

  // IsMultiUserSKU
  "SpatialAudioLicenseCheckRequiresUserContext" = 0; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Spatial\\AtmosLicenseDebug";
  // AtmosCheck::QueryLicenseForSpatialSubtypeAndEndpoint
  "AudioSrvLicenseResult" = 0; // REG_DWORD, range 2147483648-4294967295, 0-2147483647 do nothing
  "AudioDGLicenseResult" = 0; // REG_DWORD, range 2147483648-4294967295, ^

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\HoloSI\\Audio";
  // CMonitorManager::UpdateAudioMirroringEnabled
  "AudioMirroringEnabled" = 0; // REG_DWORD (bool)

  // CMonitorManager::UpdateRoutedEndpointId
  "RoutedAudioDevice" = ; // REG_SZ
```

# StorNVMe Values

This option serves as a general values overview for the `stornvme` key. Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation.

## Registry Values

Most values are read via `ReadMultiSzRegistryValueAndCompareId` using the device id match string `VEN_vvvv&DEV_dddd&REV_rr`, so I currently assume that their type is REG_MULTI_SZ. Several values are set to 0 which sometimes also means "ignore" for example. Note that the information in this list is based on `stornvme.sys` only (if value has comment).

[Database-engine/database-file-operations](https://learn.microsoft.com/en-us/troubleshoot/sql/database-engine/database-file-operations/troubleshoot-os-4kb-disk-sector-size?tabs=registry-editor#resolution-steps-for-disk-sector-size-errors-in-sql-server) validates that `ForcedPhysicalSectorSizeInBytes` is a Multi-String value, which confirms a part of my assumption, but I'm still not 100% sure about the rest. Feel free to correct me.

See [GetRegistrySettings23H2.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/stornvme/GetRegistrySettings.c), [GetRegistrySettings24H2.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/stornvme/GetRegistrySettings.c), [stornvmeGetDynamicRegistrySettings26H1.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/stornvme/GetDynamicRegistrySettings.c), and [GetRegistrySettingsForSpecificKey26H1.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/stornvme/GetRegistrySettingsForSpecificKey.c) for details.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters\\Device";
    "MaxTransferSize" = 0; // REG_MULTI_SZ, range 1-2048
    "IoQueueDepth" = 0; // REG_MULTI_SZ
    "IoSubmissionQueueCount" = 0; // REG_MULTI_SZ
    "IoCompletionQueueCount" = 0; // REG_MULTI_SZ
    "InterruptCoalescingTime" = 0; // REG_MULTI_SZ
    "InterruptCoalescingEntry" = 0; // REG_MULTI_SZ
    "ArbitrationBurst" = 255; // REG_MULTI_SZ
    "ContiguousMemoryFromAnyNode" = 0; // REG_MULTI_SZ
    "ShutdownTimeout" = 0; // REG_MULTI_SZ, >0xFF clamped to 0xFF, 0 ignored
    "DeallocateMaxLbaCount" = 0; // REG_MULTI_SZ
    "DisableDeallocate" = 0; // REG_MULTI_SZ
    "ControllerBasicInit" = 0; // REG_MULTI_SZ
    "AsyncEventMask" = ?; // REG_MULTI_SZ
    "IdlePowerMode" = 0; // REG_MULTI_SZ, applied only if value < 6
    "DiagnosticFlags" = 0; // REG_MULTI_SZ, bit 1 (0x2) forces LogSize default to 0x100000 bytes
    "LogSize" = 0; // REG_MULTI_SZ, 0 ignored (unless DiagnosticFlags set)
    "IoStripeAlignment" = 0; // REG_MULTI_SZ
    "MedPowerFxIdleTimeout" = 4294967295; // REG_MULTI_SZ
    "LowestPowerFxIdleTimeout" = 50; // REG_MULTI_SZ
    "MedPowerD3IdleTimeout" = 3000; // REG_MULTI_SZ
    "LowestPowerD3IdleTimeout" = 1000; // REG_MULTI_SZ
    "MedPowerResumeLatency" = 4294967295; // REG_MULTI_SZ
    "LowestPowerResumeLatency" = 4294967295; // REG_MULTI_SZ
    "HostMemoryBufferBytes" = 4294967295; // REG_MULTI_SZ
    "BypassSgl" = 1; // REG_MULTI_SZ, only value bit 0 is used
    "TestMdlDataBufferOffsetInBytes" = 0; // REG_MULTI_SZ
    "UseDumpPointers" = 0; // REG_MULTI_SZ
    "ReservedQueuePairCount" = 0; // REG_MULTI_SZ, valid 1-65535
    "NvmeTestSwitch" = 1; // REG_MULTI_SZ
    "IoQueuePercentageInPollingMode" = 0; // REG_MULTI_SZ, >100 clamped to 100
    "IoPollingInterval" = 0; // REG_MULTI_SZ, >100000 clamped to 100000
    "IoCompletionCapInDPC" = 100; // REG_MULTI_SZ, if nonzero clamp to 128
    "IoPollingSize" = 0x4000; // REG_MULTI_SZ
    "ErrorEtwThrottleInterval" = 0xD693A400; // REG_MULTI_SZ, if nonzero clamp to max 0xD693A400
    "ResetEnableMask" = 0; // REG_MULTI_SZ
    "ReliabilityDegraded" = 0; // REG_MULTI_SZ
    "ReadOnly" = 0; // REG_MULTI_SZ
    "VolatileMemoryBackupDeviceFailed" = 0; // REG_MULTI_SZ
    "AvailableSpare" = 0; // REG_MULTI_SZ
    "AvailableSpareThreshold" = 0; // REG_MULTI_SZ
    "ForcedPhysicalSectorSizeInBytes" = ?; // REG_MULTI_SZ
    "RetainAsyncEventControlMask" = ?; // REG_MULTI_SZ
    "ShutdownTimeoutForSurpriseRemove" = 0; // REG_MULTI_SZ, >0xFF clamped to 0xFF, 0 ignored
    "MaxIoCountLimit" = 0; // REG_MULTI_SZ
    "SubmissionQueueAssignmentPolicy" = 0; // REG_MULTI_SZ
    "DisableMFNDCCDuringRemoval" = ?; // REG_MULTI_SZ
    "EnableSingleDpcForIoCompletion" = ?; // REG_MULTI_SZ
    "DisableNamespacePreferredValueCheck" = ?; // REG_MULTI_SZ
    "IgnoreNamespacePreferredValues" = ?; // REG_MULTI_SZ
    "DisableBypassIO" = ?; // REG_MULTI_SZ
    "DisableGetActiveNSIDList" = 0; // REG_MULTI_SZ
    "ForceCryptoEraseToUseFormatNVM" = 0; // REG_MULTI_SZ

    "ControllerResetWaitTimeCushion" = 20000; // REG_MULTI_SZ
    "DisableActivateFWWithoutReset" = 0; // REG_MULTI_SZ

    // present in 24H2 path (not present in 23H2 path)
    "DisableDSTThrottle" = ?; // REG_MULTI_SZ
    "DisableF0TimestampSync" = 0; // REG_MULTI_SZ
    "DisableForwardedIO" = 0; // REG_MULTI_SZ
    "EnableIntelTSESplitIOWorkaround" = 0; // REG_MULTI_SZ
    "EnforceActiveNamespaceIdentification" = 0; // REG_MULTI_SZ
    "SupportZeroActiveNamespace" = 0; // REG_MULTI_SZ
    "WeightedRoundRobinEnabled" = 0; // REG_MULTI_SZ

    "DriverParameter" = ?;
    "HostIdentifier" = ?;
    "LinkTimeout" = ?;
    "MaximumLogicalUnit" = ?;
    "MaximumUCXAddress" = ?;
    "MinimumUCXAddress" = ?;
    "NumberOfRequests" = ?;
    "UncachedExtAlignment" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters";
    "StorageSupportedFeatures" = 1; // "Support ByPassIO"
                                    // "BypassIO is an optimized I/O path for reading from files. The goal of this path is to reduce the CPU overhead of doing reads, which helps to meet the I/O demands of loading and running next-generation games on Windows. BypassIO is a part of the infrastructure to support DirectStorage on Windows, and is available starting in Windows 11."
                                    // https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/bypassio
    "DmaRemappingCompatible" = 2; // https://github.com/nohuto/win-config/blob/main/security/desc.md#opt-out-dma-remapping
    "BusType" = ?; // bustype 0x11 is value of BusTypeNVMe
    "BusyPauseTimeInMs" = ?;
    "BusyRetryCount" = ?;
    "IoLatencyCap" = ?;
    "IoTimeoutValue" = 10;
    "PnpAsyncNewDevices" = ?;
```

# StorPort Values

This currently includes all values from [`storport.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/storport) (in relation to that StorPort key, this binary also has some PnP values/other single values, see [pnp-device-values/#default-data](https://noverse.dev/docs/win-config/power/pnp-device-values/#default-data)), see [DllInitialize](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/DllInitialize.c) & [sub_1C0042F20](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C0042F20.c) functions. More details on StorPort topic/values may be added soon.

Values that include `(bool)` as comment accept range `0-4294967295` but any nonzero has the same behaviour as `1`.

## Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort";
    "DpcCompletionLimit" = 128; // REG_DWORD, range 0-4294967295
    "HiberFileHybridPriority" = 65535; // REG_BINARY
    "HmbAllocationPolicy" = 2; // REG_DWORD, range 0-4294967295, but only 1/2/3 seem to be used other values are invalid
    "HmbMaximumSizeInBytes" = 67108864; // REG_DWORD, range 0-67108864
    "MiniportBugActionPolicy" = 1; // REG_DWORD, range 0-2, >=3 replaced with 1
    "AsyncStart" = 0; // REG_DWORD (bool)
    "TelemetryPerformanceHighResolutionTimer" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryPerformanceEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryIoSizeDistributionEnabled" = 0; // REG_DWORD, range 0-4294967295, queried only when TelemetryPerformanceEnabled is nonzero
    "TelemetryPerformancePeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryErrorDataEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryDeviceHealthEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryDeviceHealthPeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryCriticalEventEnabled" = 0; // REG_DWORD, range 0-4294967295
    "TelemetryCriticalEventMaximum" = 4294967295; // REG_DWORD, range 0-4294967295
    "ExtendedDSMCommandsSupported" = 0; // REG_DWORD (bool)
    "FUAEnable" = 0; // REG_DWORD (bool)
    "QoSFlags" = 0; // REG_DWORD, range 0-4294967295
    "MaxPreAllocatedIoResourceCount" = 4096; // REG_DWORD, range 1-4294967295, 0 ignored
    "DFxEnable" = 1; // REG_DWORD (bool)
    "OverrideDeviceUniqueIDCapability" = 1; // REG_DWORD (bool)
    "DisableRuntimePower" = 0; // REG_DWORD (bool)
    "ProcsPerGateway" = 8; // REG_DWORD, range 4-16 (capped to maximum processor count?)
    "MFNDEnable" = 0; // REG_DWORD (bool)
    "CreateControlObject" = 0; // REG_DWORD (bool)
    "DisableIEEE1667" = 0; // REG_DWORD (bool)
    "EnableNativeTcg" = 0; // REG_DWORD (bool)
    "EnableRegistryWatch" = 0; // REG_DWORD (bool)
    "LogControlEnable" = 7757; // REG_QWORD, range 0-4294967295, 0 forces LogSize 0
    "LogSize" = 256; // REG_DWORD, range 0 or 64-393216
    "DeviceQueueIoWaitThreshold" = 300000000; // REG_QWORD, range 1-4294967295, 0 ignored
    "HighLatencyIoThreshold" = 300000000; // REG_QWORD, range 1-4294967295, 0 ignored
    "TelemetryDeviceLogPagesPeriod" = 24; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "DeviceTelemetryLiveDumpEnable" = 4294967295; // REG_DWORD (bool)
    "StorportEtwErrorThrottleLimit" = 60; // REG_DWORD, range 1-4294967295, 0 ignored
    "StorportEtwWarningThrottleLimit" = 30; // REG_DWORD, range 1-4294967295, 0 ignored
    "StorportEtwInfoThrottleLimit" = 10; // REG_DWORD, range 1-4294967295, 0 ignored
    "ReportAllWheaErrorsAsNonFatal" = 0; // REG_DWORD (bool)
    "DisableExtensionDriver" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort\\Verifier";
    "VerifyLevel" = 0; // REG_DWORD, range 0-4294967295
                       // "The value assigned to this entry will determine which Storport Verification tests will be active. The value 0x1 will give maximum verification."
                       // "If the VerifyLevel value does not exist, or is equal to 0xFFFFFFFF, Storport Verification will be disabled."
                       // https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/dv-storport-verification

// miscellaneous values from storport driver

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage";
    "StorageD3InModernStandby" = 4294967295; // REG_DWORD, 0 = Disable D3 support, 1 = Enable D3 support - https://noverse.dev/docs/win-config/power/power-values/#suboptions

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\StorageTelemetry";
    "DeviceDumpLevel" = 2; // REG_DWORD, range 0-4294967295
    "DeviceDumpMaxSize" = 0; // REG_DWORD, range 0-4294967295
```

# Audio Ducking

> "*A communication device is used primarily for placing or receiving telephone calls on the computer. For a computer that has only one rendering device (speaker) and one capture device (microphone), these audio devices also act as the default communication devices.*"
>
> — Microsoft, [Using a Communication Device](https://learn.microsoft.com/en-us/windows/win32/coreaudio/using-the-communication-device)

> "*Consider a scenario where a user receives a phone call while listening to music on the computer. During the phone call, the user wants to reduce the volume level of the music while attending to the phone call, and resume the original volume after the phone call has ended. Depending on the options specified by the user in the Sounds control panel, the operating system automatically provides this functionality through ducking or stream attenuation—reduction in the intensity of an audio stream.*
>
> *The default attenuation experience depends on the user's preference, as specified in the control panel's Sound option. On the Communications tab, the user can choose an attenuation level (default value is 80%), mute all non-communication streams, or disable the default stream attenuation experience. The system allows new non-communication streams (except for new system sounds) to be opened during the communication session but the new streams are not automatically attenuated. When all of the communication streams are closed, the system ends the communication session and restores the volume of the streams that were attenuated during the communication session.*"
>
> — Microsoft, [Default Ducking Experience](https://learn.microsoft.com/en-us/windows/win32/coreaudio/stream-attenuation)

## Registry Value

See '[Audio Values](https://noverse.dev/docs/win-config/peripheral/audio-values/)' for other related values.

```c
"HKCU\\Software\\Microsoft\\Multimedia\\Audio";
  // LoadUserSettings
  "UserDuckingPreference" = 1; // REG_DWORD, range 0-3, >3 = 1
                               // 0 = -96 dB
                               // 1 = -18 dB
                               // 2 = -6 dB
                               // 3 = 0 dB
```

```c
float __fastcall CDuckingManager::GetdBFromUserPreference(int a1)
{
  int v1; // ecx

  if ( !a1 )
    return FLOAT_N96_0; // 0
  v1 = a1 - 1;
  if ( !v1 )
    return FLOAT_N18_0; // 1, should be FLOAT_N14_0
  if ( v1 == 1 )
    return FLOAT_N6_0; // 2
  return 0.0; // 3
}
```

Fun fact: the `Reduce the volume of other sounds by 80%` audio ducking option isn't accurate at all (it's ~87%).

- [LoadUserSettings](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/AudioSrvPolicyManager/-LoadUserSettings@@YAXPEAVTSSession@@PEAUHKEY__@@@Z.c)

### MMSYS Capture

Capture of `control mmsys.cpl,,3`.

```c
// Mute all other sounds
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 0

// Reduce the volume of other sounds by 80% (default)
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 1

// Reduce the volume of other sounds by 50%
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 2

// Do nothing
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 3
```

# Disable AutoPlay/Autorun

AutoRun is a mechanism that uses an `autorun.inf` file on removable media (like CDs or old USB sticks) to specify a program that should start automatically when the media is inserted. Typical use case was auto starting setup programs on software CDs. Because malware abused this behavior, Windows now strongly restricts or disables automatic execution from `autorun.inf` on most removable drives.

AutoPlay is a feature that detects the type of content on newly inserted media or connected devices and then offers actions such as "Open folder, Play media, Import photos". It can read some information from `autorun.inf`, but it doesn't automatically run programs without user confirmation.

Disabling `ShellHWDetection` causes CmdPal to not start directly after boot for whatever reason, which is why I added a suboption to enable the service.

Example `autorun.inf` content:
```c
[autorun]
open=Launch.exe
icon=Launch.exe
```

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `ShellHWDetection` | Provides notifications for AutoPlay hardware events. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k netsvcs -p |

### SystemSettings Captures

```c
// Bluetooth & devices > AutoPlay (same for Control Panel > All Control Panel Items > AutoPlay)
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\DisableAutoplay	Type: REG_DWORD, Length: 4, Data: 1

// Removeable drive
// Configure storage settings (Settings) = MSStorageSense
// Take no action = MSTakeNoAction
// Open folder to view files (File Explorer) = MSOpenFolder
// Ask me every time = MSPromptEachTime
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\StorageOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\StorageOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction

// Memory card
// Import Photos and Videos (Photos) = dsd9eksajf9re3669zh5z2jykhws2jy42gypaqjh1qe66nyek1hg!desktopappxcontent!showshowpicturesonarrival
// Play (Windows Media Player) = MSPlayMediaOnArrival
// Take no action = MSTakeNoAction
// Open folder to view files (File Explorer) = MSOpenFolder
// Ask me every time = MSPromptEachTime
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\CameraAlternate\ShowPicturesOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\CameraAlternate\ShowPicturesOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction

// Changing all available ones to 'Take no action'
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\StorageOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\StorageOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\CameraAlternate\ShowPicturesOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\CameraAlternate\ShowPicturesOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayDVDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayDVDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayEnhancedDVDOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayEnhancedDVDOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\HandleDVDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\HandleDVDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayDVDAudioOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayDVDAudioOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayBluRayOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayBluRayOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\HandleBDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\HandleBDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayCDAudioOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayCDAudioOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayEnhancedCDOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayEnhancedCDOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\HandleCDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\HandleCDBurningOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlayVideoCDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlayVideoCDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\PlaySuperVideoCDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\PlaySuperVideoCDMovieOnArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\UserChosenExecuteHandlers\AutorunINFLegacyArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoplayHandlers\EventHandlersDefaultSelection\AutorunINFLegacyArrival\(Default)	Type: REG_SZ, Length: 30, Data: MSTakeNoAction
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Set the default behavior for AutoRun](https://noverse.dev/policies?p=AutoPlay*NoAutorun) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`<br>`HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoAutorun` |
| [Turn off Autoplay](https://noverse.dev/policies?p=AutoPlay*Autorun) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`<br>`HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoDriveTypeAutoRun` |
| [Disallow Autoplay for non-volume devices](https://noverse.dev/policies?p=AutoPlay*NoAutoplayfornonVolume) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `NoAutoplayfornonVolume` |
| [Prevent AutoPlay from remembering user choices.](https://noverse.dev/policies?p=AutoPlay*DontSetAutoplayCheckbox) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Explorer`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\Explorer` | `DontSetAutoplayCheckbox` |

# Disable Touch & Tablet

Disable the touch screen feature of your device with:
```powershell
Get-PnpDevice -PresentOnly:$false | ? FriendlyName -eq 'HID-compliant touch screen' | % { pnputil /disable-device "$($_.InstanceId)" }
```

"Tablet mode makes Windows more touch friendly and is helpful on touch capable devices."

## Miscellaneous Values

Everything listed below is based on personal findings. Mistakes may exist, some parts are speculations. See links below for reference.

```c
"HKLM\\SOFTWARE\\Policies\\Microsoft\\TabletPC";
  "TurnOffTouchInput" // REG_DWORD

"HKCU\\Software\\Microsoft\\Wisp\\Touch";
    "PanningDisabled" = 0;
    "Inertia" = 1;
    "Bouncing" = 1;
    "Friction" = 50;
    "TouchModeN_DtapDist" = 50;
    "TouchModeN_DtapTime" = 50;
    "TouchGate" = 1;
    "TouchModeN_HoldTime_Animation" = 50;
    "TouchModeN_HoldTime_BeforeAnimation" = 50;
    "TouchMode_hold" = 1;
    "Mobile_Inertia_Enabled" = 0;
    "Minimum_Velocity" = 0;
    "Thumb_Flick_Enabled" = 1;

"HKCU\\Software\\Microsoft\\Wisp\\MultiTouch";
    "MultiTouchEnabled" = 1;

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad";
    "AAPThreshold" = 2; // range 0–4
    "CursorSpeed" = 10; // range 1–20
    "FeedbackIntensity" = 50; // range 0–100 (%)
    "ClickForceSensitivity" = 50; // range 0–100 (%)
    "LeaveOnWithMouse" = 1; // 0 = disable touchpad when mouse present, 1 = leave enabled
    "FeedbackEnabled" = 1; // 0 = no haptics, 1 = haptics on
    "TapsEnabled" = 1; // bool
    "TapAndDrag" = 1; // bool
    "TwoFingerTapEnabled" = 1; // bool
    "RightClickZoneEnabled" = 1; // bool
    "PanEnabled" = 1; // bool
    "ScrollDirection" = 0; // 0 = normal, 1 = reversed
    "ZoomEnabled" = 1;
    "HonorMouseAccelSetting" = 0;
    "RightClickZoneWidth" = 0;
    "RightClickZoneHeight" = 0;

"HKCU\\Software\\Microsoft\\Wisp\\Pen\\SysEventParameters";
    "Splash" = 50;
    "DblDist" = 50;
    "DblTime" = 300;
    "TapTime" = 100;
    "WaitTime" = 300;
    "HoldTime" = 2300;
    "FlickMode" = 1;
    "FlickTolerance" = 50;
    "Latency" = 8;
    "SampleTime" = 8;
    "UseHWTimeStamp" = 1;
    "SguiMode" = 0;
    "HoldMode" = 1;
    "MouseInputResolutionX" = 0;
    "MouseInputResolutionY" = 0;
    "MouseInputFrequency" = 0;
    "EraseEnable" = 1;
    "RightMaskEnable" = 1;
    "Color" = 0xC0000000C0000000; // ?

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\TabletMode";
    "STCDefaultMigrationCompleted" = 0;

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell";
    "TabletMode" = 0; // 0 = desktop mode, 1 = tablet mode?
    "ExitedTabletModeWhileCSMActive" = 0;
    "TabletModeActivated" = 0;

"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell";
    "AllowPPITabletModeExit" = 0;

"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell\\OverrideScaling";
    "SmallScreen" = 83; // ?
    "VerySmallScreen" = 71; // ?
    "TabletSmallScreen" = 83; // ?

"HKCU\\Software\\Microsoft\\Wisp\\Pen\\SysEventParameters\\FlickCommands";
    "Left" = { 0x4846455758C33841, 0x9F7145B888BB26B8 };
    "UpLeft" = { 0x47F38E42CEFA51BC, 0xEBDFECA56A8CB1AC };
    "Up"= { 0x450285124653D974, 0x8090833CF6D41AA0 };
    "UpRight" = { 0x47F38E42CEFA51BC, 0x6A8CB1ACEBDFECA5 };
    "Right" = { 0xC267B8DE4FA8068E, 0x4E301EF93B324FAB };
    "DownRight" = { 0x47F38E42CEFA51BC, 0x6A8CB1ACEBDFECA5 };
    "Down" = { 0x441A7051435776E6, 0xF7C82D37F0853D9B };
    "DownLeft" = { 0x47F38E42CEFA51BC, 0xEBDFECA56A8CB1AC };

// ?
"HKCU\Software\Microsoft\Touchpad\TouchpadDesiredVisibility","Length: 16"
```

- [peripheral/assets | touch-twinui.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/touch-twinui.c)
- [peripheral/assets | touch-InitializeInputSettingsGlobals.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/touch-InitializeInputSettingsGlobals.c)
- [peripheral/assets | touch-IsTouchDisabled.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/touch-IsTouchDisabled.c)

```
TabletModeActivated
TabletModeCoverWindow
TabletModeInputHandler
```
```c
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : EnableDesktopModeAutoInvoke
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : EnableDesktopModePenAutoInvoke
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : LastTipXPositionOnScreen
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipbandDesiredVisibility
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipbandDesiredVisibilityTabletMode
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipPinnedToMonitor
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TouchKeyboardTapInvoke
```

Windows 7/XP:
```json
"HKLM\\SOFTWARE\\Policies\\Microsoft\\TabletTip\\1.7": {
    "DisablePrediction": { "Type": "REG_DWORD", "Data": 1 },
    "DisableACIntegration": { "Type": "REG_DWORD", "Data": 1 },
    "DisableEdgeTarget": { "Type": "REG_DWORD", "Data": 1 },
    "HideIPTIPTargets": { "Type": "REG_DWORD", "Data": 1 },
    "HideIPTIPTouchTargets": { "Type": "REG_DWORD", "Data": 1 },
    "PasswordSecurityState": { "Type": "REG_DWORD", "Data": 0 },
    "IncludeRareChar": { "Type": "REG_DWORD", "Data": 0 },
    "ScratchOutState": { "Type": "REG_DWORD", "Data": 3 }
},
"HKLM\\SOFTWARE\\Policies\\Microsoft\\TabletPC": {
    "DisableInkball": { "Type": "REG_DWORD", "Data": 1 },
    "DisableJournal": { "Type": "REG_DWORD", "Data": 1 },
    "DisableNoteWriterPrinting": { "Type": "REG_DWORD", "Data": 1 },
    "DisableSnippingTool": { "Type": "REG_DWORD", "Data": 1 },
    "TurnOffPenFeedback": { "Type": "REG_DWORD", "Data": 1 },
    "PreventFlicksLearningMode": { "Type": "REG_DWORD", "Data": 1 },
    "PreventFlicks": { "Type": "REG_DWORD", "Data": 1 }
}
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Tablet PC touch input](https://noverse.dev/policies?p=TouchInput*TouchInputOff_2) | `HKLM\SOFTWARE\Policies\Microsoft\TabletPC` | `TurnOffTouchInput` |

# Disable Bluetooth

Polic CSP - [Connectivity](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-connectivity#allowbluetooth) & [Bluetooth](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-bluetooth#allowprepairing).

### AllowBluetooth

Allows the user to enable Bluetooth or restrict access.

| Value | Description |
| --- | --- |
| 0 | Disallow Bluetooth. If this is set to 0, the radio in the Bluetooth control panel will be grayed out and the user won't be able to turn Bluetooth on. |
| 2 (Default) | Allow Bluetooth. If this is set to 2, the radio in the Bluetooth control panel will be functional and the user will be able to turn Bluetooth on. |

```powershell
$ rg -i 'AllowBluetooth' "C:\Users\nohuto\Desktop\regkit\records\23H2.txt"
9893:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : 30Value
9894:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : ADMXMetadataBoth
9895:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : ADMXMetadataDevice
9896:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : ADMXMetadataUser
9897:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : Behavior
9898:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : MergeAlgorithm
9899:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : PolicyType
9900:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : RegKeyPathRedirect
9901:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : RegKeyPathRedirectMapped
9902:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : Value
9903:\Registry\Machine\SOFTWARE\Microsoft\PolicyManager\Default\Connectivity\AllowBluetooth : grouppolicyname
```

### AllowDiscoverableMode

Specifies whether other Bluetooth-enabled devices can discover the device.

| Value | Description |
| --- | --- |
| 0 | Not allowed. When set to 0, other devices won't be able to detect the device. To verify, open the Bluetooth control panel on the device. Then, go to another Bluetooth-enabled device, open the Bluetooth control panel, and verify that you can't see the name of the device. |
| 1 (Default) | Allowed. When set to 1, other devices will be able to detect the device. To verify, open the Bluetooth control panel on the device. Then, go to another Bluetooth-enabled device, open the Bluetooth control panel and verify that you can discover it. |

### AllowPrepairing

Specifies whether to allow specific bundled Bluetooth peripherals to automatically pair with the host device.

| Value | Description |
| --- | --- |
| 0 | Not allowed. |
| 1 (Default) | Allowed. |

## Services/Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `BTAGService` | Service supporting the audio gateway role of the Bluetooth Handsfree Profile. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted |
| `BluetoothUserService_*` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service, User Service Instance (224) | - | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BluetoothUserService` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service (96) | bthserv, rpcss | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BthA2dp` | Microsoft Bluetooth A2dp driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthA2dp.sys |
| `BthAvctpSvc` | This is Audio Video Control Transport Protocol service | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BthEnum` | Bluetooth Enumerator Service | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthEnum.sys |
| `BthHFEnum` | Microsoft Bluetooth Hands-Free Profile driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthhfenum.sys |
| `BthLEEnum` | Bluetooth Low Energy Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.Legacy.LEEnumerator.sys |
| `BthMini` | Bluetooth Radio Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHMINI.sys |
| `BTHMODEM` | Bluetooth Modem Communications Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthmodem.sys |
| `BTHPORT` | Bluetooth Port Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHport.sys |
| `bthserv` | The Bluetooth service supports discovery and association of remote Bluetooth devices. Stopping or disabling this service may cause already installed Bluetooth devices to fail to operate properly and prevent new devices from being discovered or associated. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BTHUSB` | Bluetooth Radio USB Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHUSB.sys |
| `DeviceAssociationBrokerSvc` | Enables apps to pair devices | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow -p |
| `DeviceAssociationService` | Enables pairing between the system and wired or wireless devices. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `Microsoft_Bluetooth_AvrcpTransport` | Microsoft Bluetooth Avrcp Transport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.AvrcpTransport.sys |
| `RFCOMM` | Bluetooth Device (RFCOMM Protocol TDI) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rfcomm.sys |

# Device Manager

The `Clean` option removes non present devices (`-PresentOnly:$false`/`Status -eq 'Unknown'`) via `/remove-device` ([`pnputil`](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/pnputil-command-syntax)).

| Component | Description | Note |
| ---- | ---- | ---- |
| `Microphone` | Audio input device | Disable if unused |
| `Speakers` | Audio output device | Disable if unused |
| `High Definition Audio Controller` | Main audio bus/controller for sound devices | Disable if not in use |

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

[`WakeOnInputDeviceTypes`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/-UpdateWakeOnInputDeviceTypesFromRegistry%40CInputGlobals%40%40QEAAXXZ.c) (`\Registry\Machine\SYSTEM\INPUT`) probably handles wake on input behavior for all input devices, each bit represents a input device type?

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

# Disable Dynamic Lighting

> "*Dynamic Lighting is a feature that allows you to control LED-powered devices such as keyboards, mice, and other illuminated accessories. This feature enables you to coordinate the colors of LEDs, creating a unified lighting experience both within Windows and across all your devices.*"
>
> — Microsoft, [Dynamic Lighting devices](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/dynamic-lighting-devices)

| Value | Type | Values | Ranges | Notes |
| --- | --- | --- | --- | --- |
| `AmbientLightingEnabled` | REG_DWORD | `0 = off`, `1 = on` | `0–1` | Main toggle for Dynamic Lighting |
| `UseSystemAccentColor` | REG_DWORD | `0 = use custom Color/Color2`, `1 = match Windows accent` | `0–1` | When `1`, `Color` is ignored |
| `Color` | REG_DWORD | `COLORREF (RGB)` | `0x00000000–0x00FFFFFF`    | Format `0x00BBGGRR`. Used when `UseSystemAccentColor = 0` |
| `Color2` | REG_DWORD | `COLORREF (RGB)` | `0x00000000–0x00FFFFFF`    | Secondary color for some effects. |
| `EffectType` | REG_DWORD | `0 = Solid`, `1 = Breathing`, `2 = Rainbow`, `4 = Wave`, `5 = Wheel`, `6 = Gradient` | `discrete enum` | Defines animation |
| `Speed` | REG_DWORD | `integer` | `1–10` | Higher = faster. |
| `EffectMode` | REG_DWORD | Rainbow: `0 = Forward`, `1 = Reverse`, Wave: `0 = Right`, `1 = Left`, `2 = Down`, `3 = Up`, Wheel: `0 = Clockwise`, `1 = Counterclockwise`, Gradient: `0 = Horizontal`, `1 = Vertical`, `2 = Outward` | `discrete enum per effect` | Depends on `EffectType`. |
| `Brightness` | REG_DWORD | `integer (%)` | `0–100` | - |
| `ControlledByForegroundApp` | REG_DWORD | `0 = ignore apps`, `1 = apps can take control` | `0–1` | - |

# Disable System Sounds

Disables system sounds and removes sound events. I did use the keys, which Windows would disable:

```powershell
"HKCU\AppEvents\Schemes\Apps\.Default\SystemAsterisk\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.Reminder\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Close\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\CriticalBatteryAlarm\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\SystemHand\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\.Default\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\MailBeep\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\DeviceConnect\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\DeviceDisconnect\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\DeviceFail\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\SystemExclamation\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.IM\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\LowBatteryAlarm\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Maximize\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\MenuCommand\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\MenuPopup\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\MessageNudge\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Minimize\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\FaxBeep\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.Mail\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.SMS\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.Proximity\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\ProximityConnection\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Notification.Default\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\Open\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\PrintComplete\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\AppGPFault\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\SystemQuestion\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\RestoreDown\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\RestoreUp\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\CCSelect\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\ShowBand\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\SystemNotification\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\ChangeTheme\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\.Default\WindowsUAC\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\BlockedPopup\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\ActivatingDocument\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\EmptyRecycleBin\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\FeedDiscovered\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\MoveMenuItem\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\SecurityBand\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\Explorer\Navigating\.Current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\DisNumbersSound\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\PanelSound\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\MisrecoSound\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\HubOffSound\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\HubOnSound\.current\(Default)","Type: REG_SZ, Length: 0"
"HKCU\AppEvents\Schemes\Apps\sapisvr\HubSleepSound\.current\(Default)","Type: REG_SZ, Length: 0"
```

The revert data is based on `W11 LTSC IoT Enterprise 2024` defaults.

`DisableStartupSound` is set to `1` by default (`LogonUI\BootAnimation`).

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Startup sound](https://noverse.dev/policies?p=Logon*DisableStartupSound) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `DisableStartupSound` |

# Disable Printers

Disables printer related services (`Spooler`, `PrintWorkFlowUserSvc`, `PrintNotify`, `usbprint`, `McpManagementService`, `PrintScanBrokerService`, `PrintDeviceConfigurationService`), and various optional features / scheduled tasks.

Remove the `Print` option from the context menu:

```powershell
Remove-Item "Registry::HKEY_CLASSES_ROOT\Applications\photoviewer.dll\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\batfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\cmdfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\contact_wab_auto_file\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\emffile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\fonfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\group_wab_auto_file\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\htmlfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\IE.AssocFile.HTM\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\IE.AssocFile.SVG\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\IE.AssocFile.URL\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\IE.AssocFile.XHT\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\inffile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\inifile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\InternetShortcut\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\JSEFile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\JSFile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\opensearchresult\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\otffile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\PBrush\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\pfmfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\regfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\rlefile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\svgfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.avci\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.avcs\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.avif\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.avifs\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.heic\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.heics\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.heif\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.heifs\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.hif\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\.jxl\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\SystemFileAssociations\image\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\ttcfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\ttffile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\txtfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\VBEFile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\VBSFile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\wdpfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\wmffile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\WSFFile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\xhtmlfile\shell\print" -Force -Recurse
Remove-Item "Registry::HKEY_CLASSES_ROOT\zapfile\shell\print" -Force -Recurse
```

This list was created on a stock `W11 LTSC IoT Enterprise 2024` installation via:
```powershell
dir Registry::HKEY_CLASSES_ROOT -Recurse -ea SilentlyContinue | ? { $_.Name -like '*\shell\print' } | select -ExpandProperty Name
```

### Printer Connections

[List](https://learn.microsoft.com/en-us/powershell/module/printmanagement/get-printer?view=windowsserver2025-ps) all printer connections:
```powershell
Get-Printer
```

[Remove](https://learn.microsoft.com/en-us/powershell/module/printmanagement/remove-printer?view=windowsserver2025-ps) a specific printer using it's name:
```powershell
Remove-Printer -Name "Printer Name"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off printing over HTTP](https://noverse.dev/policies?p=ICM*DisableHTTPPrinting_1) | `HKCU\Software\Policies\Microsoft\Windows NT\Printers` | `DisableHTTPPrinting` |
| [Turn off printing over HTTP](https://noverse.dev/policies?p=ICM*DisableHTTPPrinting_2) | `HKLM\Software\Policies\Microsoft\Windows NT\Printers` | `DisableHTTPPrinting` |
| [Turn off downloading of print drivers over HTTP](https://noverse.dev/policies?p=ICM*DisableWebPnPDownload_1) | `HKCU\Software\Policies\Microsoft\Windows NT\Printers` | `DisableWebPnPDownload` |
| [Turn off downloading of print drivers over HTTP](https://noverse.dev/policies?p=ICM*DisableWebPnPDownload_2) | `HKLM\Software\Policies\Microsoft\Windows NT\Printers` | `DisableWebPnPDownload` |
| [Prevent addition of printers](https://noverse.dev/policies?p=Printing*NoAddPrinter) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoAddPrinter` |
| [Turn off Windows default printer management](https://noverse.dev/policies?p=Printing*LegacyDefaultPrinterMode) | `HKCU\Software\Microsoft\Windows NT\CurrentVersion\Windows` | `LegacyDefaultPrinterMode` |
| [Browse the network to find printers](https://noverse.dev/policies?p=Printing*DownlevelBrowse) | `HKCU\Software\Policies\Microsoft\Windows NT\Printers\Wizard` | `Downlevel Browse` |

# Monitor Settings

Before starting the configuration, load your default settings, as many settings are already correctly configured by default.

### Game Mode - `User`  
Each profile has preconfigured settings. E.g. 'Read mode' is optimized for viewing documents, it probably decreases the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) and increases the color temperature. Choose the profile you're satisfied with, for example the sRGB profile if you're a editor, then configure the other settings.

### Overdrive/OD/Response Time - `Test`  
If you experience [ghosting](https://www.testufo.com/ghosting) (most noticeable in fast paced motions, e.g. FPS games), caused by a slow response time, which cannot keep up with the speed of the changing image, you should try to increase the OD option, which will increase the response time of your monitor. Ghosting looks like a image artifact that appears as a trail of pixels behind a moving object (pixels can't change color fast enough when a new image appears, parts of the old image remain visible), which is why it gets called ghosting -> the trace looks like a ghost of the object. Increasing the overdrive setting can end up in overshooting/inverse ghosting, which is the opposite of ghosting and get's caused from a too high OD. Which means that the response time is too fast for your monitor to handle it, resulting in pixels changing their color too fast. Ghosting (normally) ends up in a trace behind the object (like motion blur), inverse ghosting can cause artifacts in front and behind the object. Search for your monitor [here](https://www.rtings.com/), scroll down to the motion section and compare the response times, to see if your monitor even performs the best one the fastest option. And no you won't "see" a difference between them, if you experience inverse ghosting, renounce the lowest response time and decrease it (as ghosting makes the image unclear -> annoying), if you experience ghosting increase and test it.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/monitor1.png?raw=true)

### Sharpness - `0%`  
Personal preference. Increasing it too much will end up in [artificial sharpening](http://www.lagom.nl/lcd-test/sharpness.php) = exaggerated outlines.

### Dark Boost/Black Boost - `Off`  
Improved vision in [dark scenes](https://www.testufo.com/blacklevels) when increased, but can end up making black look gray, so don't increase it too much. 

### FreeSync, G-Sync... - `Disabled`  
G-Sync matches the monitor's refresh rate to the frame rate. The setting is used to eliminate screen tearing, if you don't experience [screen tearing](https://www.youtube.com/watch?v=5mWMP96UdGU&t=110s), leave it disabled. If you want to use it, set your framerate limit a bit lower (kind of a buffer, `freq-(freq*freq)/3600`) than your refresh rate. Optimally set the limit within the game. Never use pure V-Sync -> G-Sync + V-Sync + Reflex & limit. [Gsync/gsync101-input-lag-tests-and-settings](https://blurbusters.com/gsync/gsync101-input-lag-tests-and-settings/) can still be read. It is old, but most of it is still correct. If information from the text above and from the website text don't match, the channel information is correct.

### Color Temperature - `Warm`  
Changing it is one of the best ways to reduce eye stain. Using a warm temperature -> less [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/). (read the text below for more information about [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/)) Default mostly is `6500K`. One thing to add: a higher temperature will make it easier for you to concentrate.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/monitor2.png?raw=true)

### Brightness - `50-70`  
Depends on how much light there is in your room. If there's a lot of light, you'll have to increase the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/). If you mainly play in the dark, it's recommended to reduce the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) to a level that is comfortable for your eyes. Remember: decreasing it *can* lower the [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/) by `50+%` -> known to be phototoxic to your eyes ([retina](https://en.wikipedia.org/wiki/Retina) - light sensitive tissue), therefore lower the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) to reduce the intensity of [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/). For your general knowledge, [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/) has a short wavelength (~`450-500`), which means that it carries more energy -> higher impact. Don't dim it too much, or it may end up in worse focus.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/monitor3.png?raw=true)

### Contrast - `~60`  
It shouldn't be set too high, otherwise you will [not be able to see any details](https://www.testufo.com/whitelevels) and not too low, or it will be too dark. You'll have to test it yourself and find the best value.

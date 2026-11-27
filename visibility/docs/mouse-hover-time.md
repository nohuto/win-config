# Mouse Hover Time

- `MouseHoverTime` controls how long the mouse must stay still over something before Windows treats it as a hover.
- `MenuShowDelay` controls the menu hover delay, mainly how long shell menus wait before opening a submenu while the pointer is on a menu entry.

win32k reads both at sign-in ([`xxxUpdatePerUserSystemParameters`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/win32kfull/xxxUpdatePerUserSystemParameters.c)), `MenuShowDelay` defaults to 400 ms, a missing `MouseHoverTime` takes the `MenuShowDelay` value and values below 10 ms become 10. The option only writes the registry, so sign out and in after changing it.

```c
"HKCU\\Control Panel\\Mouse";
    "MouseHoverTime" = "400"; // REG_SZ, ms, < 10 = 10

"HKCU\\Control Panel\\Desktop";
    "MenuShowDelay" = "400"; // REG_SZ, ms
```

### msd_test

Small app to test how much time it took to open a popup menu, works by moving the pointer onto a submenu item, then measuring from the menus `WM_MOUSEMOVE` in `WH_MSGFILTER` to the submenus `WM_INITMENUPOPUP`, via `QueryPerformanceCounter`.

You can either download the prebuild [binary](https://github.com/nohuto/utils/releases/download/0.1.0/msd_test.exe), or build it yourself from [source](https://github.com/nohuto/utils/tree/main/msd_test) whenever you want to test it on your own.

```powershell
cmake -S . -B build
cmake --build build --config Release

./build/Release/msd_test --help
usage: msd_test [--tries 1-1000] [--delay 0-60000]
```

`--tries` has a default of 10, if not overriding (`SPI_SETMENUSHOWDELAY`) the delay via `--delay`, it uses your `MenuShowDelay` data by default.

#### Results

As shown in the section below, using a data of `0` is the same as using a data of `10`:

```powershell
$ .\msd_test --tries 50 --delay 0
delay=0ms source=arg tries=50/50 avg=16.81ms

$ .\msd_test --tries 50 --delay 10
delay=10ms source=arg tries=50/50 avg=14.72ms

$ .\msd_test --tries 50 --delay 20
delay=20ms source=arg tries=50/50 avg=29.03ms

$ .\msd_test --tries 50 --delay 30
delay=30ms source=arg tries=50/50 avg=30.24ms

$ .\msd_test --tries 50 --delay 40
delay=40ms source=arg tries=50/50 avg=46.85ms

$ .\msd_test --tries 50 --delay 50
delay=50ms source=arg tries=50/50 avg=60.16ms

$ .\msd_test --tries 50 --delay 100
delay=100ms source=arg tries=50/50 avg=107.00ms

$ .\msd_test --tries 50 --delay 400
delay=400ms source=arg tries=50/50 avg=401.97ms
```

### CMenuToolbarBase::_SetTimer

[`SPI_GETMENUSHOWDELAY`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa):

> "*Retrieves the time, in milliseconds, that the system waits before displaying a shortcut menu when the mouse cursor is over a submenu item. The pvParam parameter must point to a DWORD variable that receives the time of the delay.*"

```c
// CMenuToolbarBase::_SetTimer (shell32, 25H2)

if ( SystemParametersInfoW(0x6Au, 0, &g_lMenuPopupTimeout, 0) ) // 0x6A = SPI_GETMENUSHOWDELAY
  goto LABEL_5;
v4 = g_lMenuPopupTimeout;
if ( g_lMenuPopupTimeout != -1 )
  goto LABEL_6;
g_lMenuPopupTimeout = 4 * GetDoubleClickTime() / 5; // fallback (depends on DoubleClickSpeed)
if ( (int)SHRegGetStringEx(HKEY_CURRENT_USER, L"Control Panel\\Desktop", L"MenuShowDelay", 2, pszSrc, 6u) < 0 ) // 2 = REG_SZ
{
LABEL_5:
  v4 = g_lMenuPopupTimeout;
}
else
{
  v4 = StrToIntW(pszSrc);
  g_lMenuPopupTimeout = v4;
}
```

It first uses [`SystemParametersInfoW(SPI_GETMENUSHOWDELAY)`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa), so the registry value is normally used through the API. If that API fails and no cached value exists, it falls back to `4 * GetDoubleClickTime() / 5`, means the fallback depends on the current double click speed (`HKCU\Control Panel\Mouse\DoubleClickSpeed`). By default it's set to `500 ms` = fallback becomes `400 ms`.

```c
// CMenuToolbarBase::_SetTimer (shell32, 25H2)

if ( (_DWORD)v2 == 32771 )
  goto LABEL_19;
if ( (_DWORD)v2 != 32776 )
{
  if ( (_DWORD)v2 != 32777 )
  {
    if ( (_DWORD)v2 == 32778 )
    {
      v4 = 60000; // fixed 60 seconds
    }
    else if ( (_DWORD)v2 == 32779 )
    {
      v4 = 2 * GetDoubleClickTime(); // ignores MenuShowDelay
    }
    return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
  }
LABEL_19:
  v4 *= 2;
  if ( v4 < 2000 )
    v4 = 2000;
  return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
}
if ( ((_BYTE)this[15] & 1) == 0 )
  return 1LL;
v5 = *((_QWORD *)this[5] + 34);
if ( !v5 || (*(_BYTE *)(v5 + 72) & 1) != 0 || ((_BYTE)this[15] & 0x20) != 0 )
  return 1LL;
v4 *= 5;
if ( v4 < 2000 )
  v4 = 2000;
return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
```

`v4` is passed to [`SetTimer`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-settimer) as `uElapse`, MS shows that `SetTimer` clamps values below `USER_TIMER_MINIMUM` (`10 ms`) to `10 ms` & values above `USER_TIMER_MAXIMUM` (`0x7FFFFFFF`, ~24.8 days) to that maximum. Means for `CMenuToolbarBase::_SetTimer` shown above, using `MenuShowDelay` with `0` can't request a timer interval shorter than `10 ms`.

The normal menu hover timers use `MenuShowDelay`, some menu timers ignore or extend it, `32771` & `32777` use at least `2 seconds`, `32776` can use at least `2 seconds` after multiplying the value by `5`, `32778` is fixed to `60 seconds`, `32779` uses double click time instead.


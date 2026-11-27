# Pointer Style

Windows has four main pointer styles in `Settings > Accessibility > Mouse pointer and touch`: `White`, `Black`, `Inverted` and `Custom color`. Settings stores the style in `CursorType` (`0` White, `1` Black, `2` Inverted, `6` Custom color) and copies the matching system scheme (`Windows Aero`, `Windows Black`, `Windows Inverted` in `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Control Panel\Cursors\Schemes`) to `HKCU\Control Panel\Cursors`, then reloads the cursors with `SPI_SETCURSORS`. 

Custom colors store the color in `CursorColor` as a Win32 [`COLORREF`](https://learn.microsoft.com/en-us/windows/win32/gdi/colorref) (`0x00bbggrr`, missing = `0xFFBF`) and point to per user cursor files under `%LOCALAPPDATA%\Microsoft\Windows\Cursors\*_eoa.cur`.

### Installing Custom Cursors

If you want a full custom cursor pack instead of Windows built in white, black, inverted, or recolored accessibility cursors, you can install one from different sources such as [vsthemes.org](https://vsthemes.org/en/cursors/).

1. Download and extract the pack
2. Copy the pack files into `%SystemRoot%\Cursors\<Pack Name>` if you want to keep them in the standard system cursor location
3. Open `main.cpl`, go to the `Pointers` tab, select a cursor role, click `Browse`, and pick the downloaded `.cur` or `.ani` file

#### Cursor Previews

| Name | Preview |
| --- | --- |
| Custom colors + dark/light/invert | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/defaults.png?raw=true) |
| [Simplify Dot](https://vsthemes.org/en/cursors/static/47356-simplify-dot-2.html) (Dark/Light) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/simplify-dot.webp?raw=true) |
| [Colloid Dark](https://vsthemes.org/en/cursors/black/68372-colloid-dark.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/colloid-dark.webp?raw=true) |
| [Colloid Light](https://vsthemes.org/en/cursors/white/68371-colloid-light.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/colloid-light.webp?raw=true) |
| [Monolith](https://vsthemes.org/en/cursors/black/70650-monolith.html) (Dark/Light) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/monolith.webp?raw=true) |
| [Capitaine](https://vsthemes.org/en/cursors/black/27320-capitaine.html) (Dark, White, Gruvbox, Gruvbox White, Nord, Nord White, Palenight, Palenight White) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/capitaine.webp?raw=true) |
| [Skyrim](https://vsthemes.org/en/cursors/games/45588-the-elder-scrolls-5-skyrim.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/skyrim.webp?raw=true) |

### Pointer Style Captures

```c
// Main style
// 0 = White, 1 = Black, 2 = Inverted, 6 = Custom color
HKCU\Software\Microsoft\Accessibility\CursorType	Type: REG_DWORD

// Custom color only (COLORREF format: 0x00bbggrr)
HKCU\Software\Microsoft\Accessibility\CursorColor	Type: REG_DWORD

// Standard styles use the built in system cursor sets
HKCU\Control Panel\Cursors\(Default)		Type: REG_SZ
HKCU\Control Panel\Cursors\Arrow		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Help		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\AppStarting	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Wait		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Crosshair	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\IBeam		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\NWPen		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\No		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNS		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeWE		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNWSE	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNESW	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeAll		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\UpArrow	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Hand		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Scheme Source	Type: REG_DWORD

// Custom colored styles use generated per user cursor files
HKCU\Control Panel\Cursors\Arrow // %LOCALAPPDATA%\Microsoft\Windows\Cursors\arrow_eoa.cur
HKCU\Control Panel\Cursors\AppStarting // %LOCALAPPDATA%\Microsoft\Windows\Cursors\busy_eoa.cur
HKCU\Control Panel\Cursors\Crosshair // %LOCALAPPDATA%\Microsoft\Windows\Cursors\cross_eoa.cur
HKCU\Control Panel\Cursors\Hand // %LOCALAPPDATA%\Microsoft\Windows\Cursors\link_eoa.cur
HKCU\Control Panel\Cursors\Help // %LOCALAPPDATA%\Microsoft\Windows\Cursors\helpsel_eoa.cur
HKCU\Control Panel\Cursors\IBeam // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ibeam_eoa.cur
HKCU\Control Panel\Cursors\No // %LOCALAPPDATA%\Microsoft\Windows\Cursors\unavail_eoa.cur
HKCU\Control Panel\Cursors\NWPen // %LOCALAPPDATA%\Microsoft\Windows\Cursors\pen_eoa.cur
HKCU\Control Panel\Cursors\Person // %LOCALAPPDATA%\Microsoft\Windows\Cursors\person_eoa.cur
HKCU\Control Panel\Cursors\Pin // %LOCALAPPDATA%\Microsoft\Windows\Cursors\pin_eoa.cur
HKCU\Control Panel\Cursors\SizeAll // %LOCALAPPDATA%\Microsoft\Windows\Cursors\move_eoa.cur
HKCU\Control Panel\Cursors\SizeNESW // %LOCALAPPDATA%\Microsoft\Windows\Cursors\nesw_eoa.cur
HKCU\Control Panel\Cursors\SizeNS // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ns_eoa.cur
HKCU\Control Panel\Cursors\SizeNWSE // %LOCALAPPDATA%\Microsoft\Windows\Cursors\nwse_eoa.cur
HKCU\Control Panel\Cursors\SizeWE // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ew_eoa.cur
HKCU\Control Panel\Cursors\UpArrow // %LOCALAPPDATA%\Microsoft\Windows\Cursors\up_eoa.cur
HKCU\Control Panel\Cursors\Wait // %LOCALAPPDATA%\Microsoft\Windows\Cursors\wait_eoa.cur
HKCU\Control Panel\Cursors\CursorBaseSize	Type: REG_DWORD

// Used custom color DWORDs (these are the predefined ones from SystemSettings)
HKCU\Software\Microsoft\Accessibility\CursorColor = 16711871	// Purple (0x00FF00BF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 65471		// Lime (0x0000FFBF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 64250		// Yellow (0x0000FAFA)
HKCU\Software\Microsoft\Accessibility\CursorColor = 49151		// Gold (0x0000BFFF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 12517631	// Pink (0x00BF00FF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 16760576	// Turquoise (0x00FFBF00)
HKCU\Software\Microsoft\Accessibility\CursorColor = 12582656	// Green (0x00BFFF00)
```

When applying these manually via the registry the cursor can be refreshed using [SPI_SETCURSORS](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa), this only works for dark+light+inverted+custom, the color ones build `*_eoa.cur` files as said above which the function doesn't do (which is also kind of why the dropdown doesn't include colored cursors).


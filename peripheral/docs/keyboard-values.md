# Keyboard Values


## Registry Values

```c
"HKCU\\Control Panel\\Keyboard"; // win32kfull xxxUpdatePerUserSystemParameters
    "KeyboardDelay" = "1"; // REG_SZ, 0-3
                           // "Controls how long you need to hold down a key before it starts repeating when typing"
    "KeyboardSpeed" = "31"; // REG_SZ, 0-31
                            // "Adjusts how quickly a key repeats when held down after the repeat delay"
    "InitialKeyboardIndicators" = "0"; // REG_SZ, UpdatePerUserKeyboardIndicators, 2 = Num Lock on after sign in, 2147483648 = keep the sign in screen state
    "PrintScreenKeyForSnippingEnabled" = 1; // REG_DWORD, 0 = PrintScreen doesnt open the screen clipping overlay

"HKCU\\Control Panel\\Desktop";
    "CursorBlinkRate" = "530"; // REG_SZ, ms, missing = 500
                               // "Controls the speed at which the text cursor blinks on the screen, you can set it to be faster or slower"

"HKCU\\Control Panel\\Accessibility\\Keyboard Response"; // win32kbase xxxUpdatePerUserAccessPackSettings
    "Flags" = "126"; // REG_SZ, FKF_* bits
    "BounceTime" = "0"; // REG_SZ, ms

"HKCU\\Control Panel\\Accessibility\\StickyKeys";
    "Flags" = "510"; // REG_SZ, SKF_* bits

"HKCU\\Control Panel\\Accessibility\\ToggleKeys";
    "Flags" = "62"; // REG_SZ, TKF_* bits

"HKCU\\Keyboard Layout\\Toggle";
    "Hotkey" = "1"; // REG_SZ, 3 = not assigned
    "Language Hotkey" = ?; // REG_SZ, ^
    "Layout Hotkey" = ?; // REG_SZ, ^
```

All three `Flags` values are decimal strings of the `dwFlags` bits (`winuser.h`):

### FILTERKEYS

```c
// winuser.h (Windows SDK 10.0.28000.0)

/*
 * FILTERKEYS dwFlags field
 */
#define FKF_FILTERKEYSON    0x00000001
#define FKF_AVAILABLE       0x00000002
#define FKF_HOTKEYACTIVE    0x00000004
#define FKF_CONFIRMHOTKEY   0x00000008
#define FKF_HOTKEYSOUND     0x00000010
#define FKF_INDICATOR       0x00000020
#define FKF_CLICKON         0x00000040
```

### STICKYKEYS

```c
/*
 * STICKYKEYS dwFlags field
 */
#define SKF_STICKYKEYSON    0x00000001
#define SKF_AVAILABLE       0x00000002
#define SKF_HOTKEYACTIVE    0x00000004
#define SKF_CONFIRMHOTKEY   0x00000008
#define SKF_HOTKEYSOUND     0x00000010
#define SKF_INDICATOR       0x00000020
#define SKF_AUDIBLEFEEDBACK 0x00000040
#define SKF_TRISTATE        0x00000080
#define SKF_TWOKEYSOFF      0x00000100
```

### TOGGLEKEYS

```c
/*
 * TOGGLEKEYS dwFlags field
 */
#define TKF_TOGGLEKEYSON    0x00000001
#define TKF_AVAILABLE       0x00000002
#define TKF_HOTKEYACTIVE    0x00000004
#define TKF_CONFIRMHOTKEY   0x00000008
#define TKF_HOTKEYSOUND     0x00000010
#define TKF_INDICATOR       0x00000020
```

`Last BounceKey Setting`, `Last Valid Delay`, `Last Valid Repeat`, `Last Valid Wait` (`Keyboard Response`) are only in `accessibilitycpl.dll` (Filter Keys page).

### GetKbdLangSwitch

`Time & language > Typing > Advanced keyboard settings : Input language hot keys`, `Between input languages` to `Not assigned` (`None`):

```powershell
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Language Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Layout Hotkey	Type: REG_SZ, Length: 4, Data: 3
```


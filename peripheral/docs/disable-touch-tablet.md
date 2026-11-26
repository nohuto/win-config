# Disable Touch & Tablet

Turns off touch keyboard, pen, touchpad gesture and tablet mode settings.

## Touch Screen

The suboption disables touch screens via `pnputil /disable-device`.

It finds the devices by the HWID `HID_DEVICE_UP:000D_U:0004`, which `input.inf` installs as "HID-compliant touch screen", `0x0D` is `HID_USAGE_PAGE_DIGITIZER`, `0x04` is `HID_USAGE_DIGITIZER_TOUCH_SCREEN`.

`pnputil` writes a single value, `CONFIGFLAG_DISABLED` bit in the devices `ConfigFlags`, example:

```c
- HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Enum\HID\VID_80EE&PID_0022&Col01\6&2ec961e1&0&0000|"ConfigFlags"=dword:00000000
+ HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Enum\HID\VID_80EE&PID_0022&Col01\6&2ec961e1&0&0000|"ConfigFlags"=dword:00000001
```

```c
// hidusage.h

//
// Usage Pages
//

#define HID_USAGE_PAGE_DIGITIZER                        ((USAGE) 0x000D)

//
// Digitizers Page (0x0D)
//

#define HID_USAGE_DIGITIZER_TOUCH_SCREEN                                      ((USAGE) 0x0004)


// regstr.h

#define CONFIGFLAG_DISABLED             0x00000001      // Set if disabled
```

## Miscellaneous Values

See links below for reference.

```c
"HKLM\\SOFTWARE\\Policies\\Microsoft\\TabletPC"; // TabSvc IsTouchDisabled
    "TurnOffTouchInput" = 0; // REG_DWORD, 1 = TabSvc reports no digitizer

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
    "Left_Edgy_Enabled" = 1; // REG_DWORD, W11
    "Right_Edgy_Enabled" = 1; // REG_DWORD, W11
    "DualPressAndHold_Enabled" = 1; // REG_DWORD, W11 25H2

"HKCU\\Software\\Microsoft\\Wisp\\MultiTouch"; // win32kbase LoadPointerDeviceTouchSettings
    "MultiTouchEnabled" = 1; // REG_DWORD

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad";
    "AAPThreshold" = 2; // range 0-4
    "CursorSpeed" = 10; // range 1-20
    "FeedbackIntensity" = 50; // range 0-100 (%)
    "ClickForceSensitivity" = 50; // range 0-100 (%)
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

"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad"; // win32kbase PopulatePTPProperties
    "AAPDisabled" = 0; // REG_DWORD, W10

"HKCU\\Software\\Microsoft\\Wisp\\Pen\\SysEventParameters";
    "Splash" = 50;
    "DblDist" = 50; // REG_DWORD
    "LeftEdgyEnabled" = 1; // REG_DWORD, 25H2
    "RightEdgyEnabled" = 1; // REG_DWORD, 25H2
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
    "TabletMode" = 0; // REG_DWORD (bool), 0 = desktop mode, 1 = tablet mode (W10), nonzero suppresses DWM ColorPrevalence caption color
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

"HKCU\\Software\\Microsoft\\Touchpad"; // SettingsHandlers_DesktopTaskbar
    "TouchpadDesiredVisibility" = 0; // REG_DWORD, virtual touchpad icon in the taskbar

"HKCU\\Software\\Microsoft\\Input\\Settings"; // SettingsHandlers_Keyboard
    "IsVoiceTypingKeyEnabled" = ?; // REG_DWORD, "Show the voice typing mic button" (touch keyboard)

"HKCU\\Software\\Microsoft\\TabletTip\\1.7"; // SettingsHandlers_nt, twinui.pcshell, W11
    "IsKeyBackgroundEnabled" = ?; // REG_DWORD, "Key background" (touch keyboard theme)
    "UserKeyboardScalingFactor" = ?; // REG_DWORD, "Keyboard size" (touch keyboard)

"HKCU\\Control Panel\\Cursors"; // win32kbase
    "ContactVisualization" = 1; // REG_DWORD, "Touch indicator"
    "GestureVisualization" = 31; // REG_DWORD

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell"; // twinui, W10 tablet mode
    "SignInMode" = ?; // REG_DWORD, "When I sign in"
    "ConvertibleSlateModePromptPreference" = ?; // REG_DWORD, "When this device automatically switches tablet mode on or off"

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"; // twinui, Taskbar
    "TaskbarAutoHideInTabletMode" = 0; // REG_DWORD, "Automatically hide the taskbar" in tablet mode
    "TaskbarAppsVisibleInTabletMode" = ?; // REG_DWORD, "Hide app icons on the taskbar" in tablet mode
```

- [peripheral/assets/pseudocode | touch-twinui.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-twinui.c)
- [peripheral/assets/pseudocode | touch-InitializeInputSettingsGlobals.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-InitializeInputSettingsGlobals.c)
- [peripheral/assets/pseudocode | touch-IsTouchDisabled.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-IsTouchDisabled.c)


### Touch Keyboard Values

`HKCU\Software\Microsoft\TabletTip\1.7` includes the touch keyboard toggles of `Time & language > Typing` ([en-US strings of 23H2 Settings app](https://github.com/nohuto/win-config/blob/main/assets/settings-app/23H2/strings.txt)), `SettingsHandlers_Keyboard.dll` reads the on/off toggles in `_TouchKeyboardGetBoolValue`, missing value = on.

| Value | Settings text |
| --- | --- |
| `EnableAutoShiftEngage` | '*Capitalize the first letter of each sentence*' |
| `EnableDoubleTapSpace` | '*Add a period after I double-tap the Spacebar*' |
| `EnableKeyAudioFeedback` | '*Play key sounds as I type*' |
| `TouchKeyboardTapInvoke` | '*Show the touch keyboard*' (*Never*, *When no keyboard attached*, *Always*) |
| `TipbandDesiredVisibility` | touch keyboard icon in the taskbar (`SettingsHandlers_DesktopTaskbar.dll`) |

#### TurnOffTouchInput

Read by `TabSvc.dll` only (`IsTouchDisabled`), with it TabSvc skips `GetSystemMetrics(SM_DIGITIZER)` & `GetSystemMetrics(SM_MAXIMUMTOUCHES)`, so the touch keyboard and handwriting service see no touch hardware:

```c
// TabletHardwareQuery (TabSvc, 23H2)

SystemMetrics = 0;
v5 = 0;
if ( !byte_18003DE1C ) // IsTouchDisabled() result
{
  SystemMetrics = GetSystemMetrics(94); // SM_DIGITIZER
  v5 = GetSystemMetrics(95); // SM_MAXIMUMTOUCHES
}
```

#### Vista/W7

Miscellaneous old values:

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


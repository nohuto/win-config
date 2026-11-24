# Disable Touch & Tablet

Disable the touch screen feature of your device with:

```powershell
Get-PnpDevice -PresentOnly:$false | ? FriendlyName -eq 'HID-compliant touch screen' | % { pnputil /disable-device "$($_.InstanceId)" }
```

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

- [peripheral/assets/pseudocode | touch-twinui.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-twinui.c)
- [peripheral/assets/pseudocode | touch-InitializeInputSettingsGlobals.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-InitializeInputSettingsGlobals.c)
- [peripheral/assets/pseudocode | touch-IsTouchDisabled.c](https://github.com/nohuto/win-config/blob/main/peripheral/assets/pseudocode/touch-IsTouchDisabled.c)

```powershell
TabletModeActivated
TabletModeCoverWindow
TabletModeInputHandler
```
```powershell
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : EnableDesktopModeAutoInvoke
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : EnableDesktopModePenAutoInvoke
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : LastTipXPositionOnScreen
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipbandDesiredVisibility
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipbandDesiredVisibilityTabletMode
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TipPinnedToMonitor
\Registry\Machine\SOFTWARE\Microsoft\TabletTip\1.7 : TouchKeyboardTapInvoke
```

### Touch Keyboard Values

`HKCU\Software\Microsoft\TabletTip\1.7` includes the touch keyboard toggles of `Time & language > Typing` ([en-US strings of 23H2 Settings app](https://github.com/nohuto/win-config/blob/main/assets/settings-app/23H2/strings.txt)), `SettingsHandlers_Keyboard.dll` reads the on/off toggles in `_TouchKeyboardGetBoolValue`, missing value = on.

| Value | Settings text |
| --- | --- |
| `EnableAutoShiftEngage` | '*Capitalize the first letter of each sentence*' |
| `EnableDoubleTapSpace` | '*Add a period after I double-tap the Spacebar*' |
| `EnableKeyAudioFeedback` | '*Play key sounds as I type*' |
| `TouchKeyboardTapInvoke` | '*Show the touch keyboard*' (*Never*, *When no keyboard attached*, *Always*) |
| `TipbandDesiredVisibility` | touch keyboard icon in the taskbar (`SettingsHandlers_DesktopTaskbar.dll`) |

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


# Minimal Window Snapping

The main option leaves window snapping enabled, while disabling the snap bar/snap flyout/ snap group etc., for a "minimal" version of it. You can configure window snapping behaviour via the suboptions, if you don't like the main option.

![](https://github.com/nohuto/win-config/blob/main/visibility/images/window-snapping.png?raw=true)

## Suboptions

### Snap Flyout

Hides the snap assist flyout that would appear after hovering over the maximize/restore down icon:

![](https://github.com/nohuto/win-config/blob/main/visibility/images/snapflyout.png?raw=true)

### Window Shake

Prevents windows from being minimized or restored when the active window is shaken back and forth with the mouse.

![](https://www.techjunkie.com/wp-content/uploads/2018/10/windows-aero-shake-example.gif)

#### SystemSettings Captures

```c
// System > Multitasking: Title bar window shake

// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DisallowShaking	Type: REG_DWORD, Length: 4, Data: 0

// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DisallowShaking	Type: REG_DWORD, Length: 4, Data: 1
```

#### [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Aero Shake window minimizing mouse gesture](https://noverse.dev/policies?p=Desktop*NoWindowMinimizingShortcuts) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `NoWindowMinimizingShortcuts` |

## SystemSettings Captures

```c
// System > Multitasking : Snap windows
// Disabled 
HKCU\Control Panel\Desktop\WindowArrangementActive	Type: REG_SZ, Length: 4, Data: 0
// Enabled
HKCU\Control Panel\Desktop\WindowArrangementActive	Type: REG_SZ, Length: 4, Data: 1

// System > Multitasking > Snap windows : When I snap a window, suggest what I can snap next to it
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SnapAssist	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SnapAssist	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show snap layouts when I hover over a window's maximize button
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapAssistFlyout	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapAssistFlyout	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show snap layouts when I drag a window to the top of my screen
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapBar	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapBar	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show my snapped windows when I hover over taskbar apps, in Task View, and when I press Alt+Tab
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableTaskGroups	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableTaskGroups	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : When I drag a window, let me snap it without dragging all the way to the screen edge
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DITest	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DITest	Type: REG_DWORD, Length: 4, Data: 1
```


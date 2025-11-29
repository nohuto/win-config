# Mouse Values

`RawMouseThrottleDuration` controls the throttle interval (in ms) for delivering raw mouse input to background windows. "We set out to reduce the amount of processing time it took to handle input requests by throttling and coalescing background raw mouse listeners and capping their message rate." 

Validate the changes with [MouseTester](https://github.com/valleyofdoom/MouseTester), move `MouseTester.exe` to the background after starting it by opening a different window.
```c
*(_QWORD *)&v13 = 0LL;                      // Forced = 0 (default)
*((_QWORD *)&v11 + 1) = 1LL;                // Enabled = 1 (default) - Forced to 1
*(_QWORD *)&v11 = L"RawMouseThrottleEnabled";
*((_QWORD *)&v12 + 1) = L"RawMouseThrottleForced";
*(_QWORD *)&v14 = L"RawMouseThrottleDuration";
*(_QWORD *)&v12 = 1LL;                      // Enabled = 1 (maximum)
*((_QWORD *)&v13 + 1) = 1LL;                // Forced = 1
*((_QWORD *)&v14 + 1) = 0x100000008LL;      // Duration = 8 (default, 125Hz)
*(_QWORD *)&v15 = 20LL;                     // Duration = 20 (maximum)
*((_QWORD *)&v15 + 1) = L"RawMouseThrottleLeeway";
*(_QWORD *)&v16 = 2LL;                      // Leeway = 2 (default)
*((_QWORD *)&v16 + 1) = 5LL;                // Leeway = 5 (maximum)
```
`GetRawMouseThrottlingThresholds.c` includes more detail and my notes. `RawMouseThrottleDuration` has a minumum of `1` (`1000` Hz).

> https://blogs.windows.com/windowsdeveloper/2023/05/26/delivering-delightful-performance-for-more-than-one-billion-users-worldwide/  
> https://github.com/valleyofdoom/PC-Tuning#1150-background-window-message-rate-permalink  
> [peripheral/assets | mouse-GetRawMouseThrottlingThresholds.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/mouse-GetRawMouseThrottlingThresholds.c)

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/mousevalues.png?raw=true)

# Keyboard Values

| **Setting**           | **Description**                                                                                          | **Default** | **Changed To** |
| --------------------- | -------------------------------------------------------------------------------------------------------- | ----------- | -------------- |
| **Repeat Delay**      | Controls how long you need to hold down a key before it starts repeating when typing.                    | 1           | 0              |
| **Repeat Rate**       | Adjusts how quickly a key repeats when held down after the repeat delay.                                 | 31          | 31             |
| **Cursor Blink Rate** | Controls the speed at which the text cursor blinks on the screen. You can set it to be faster or slower. | 530         | 900            |

`Disable Language Switch Hotkey` applies: `Time & language > Typing > Advanced keyboard settings : Input language hot keys`, `Between input languages` to `Not assigned` (`None`):
```powershell
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Language Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Layout Hotkey	Type: REG_SZ, Length: 4, Data: 3
```

# Disable Audio Ducking

"Windows audio ducking is a dynamic audio processing technique that enables the **automatic adjustment of audio levels** between different audio sources on a Windows-based computer or operating system."
> https://multimedia.easeus.com/ai-article/windows-audio-ducking.html

Can be disabled manually via `mmsys.cpl > Communications` `Do nothing`.

`Mute all other sounds`:
```powershell
RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 0
```
`Reduce the volume of other sounds by 80%` (default):
```powershell
RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 1
```
`Reduce the volume of other sounds by 50%`:
```powershell
RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 2
```
`Do nothing`:
```powershell
RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 3
```

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/audioducking.png?raw=true)

# Disable Audio Enhancements

The difference is minor (picture), preferable just disable them. Open `mmsys.cpl`, go into propeties of your used device, click on the `Advanced` tab and disable all enhancements. Run `Disable-Exclusive-Mode.bat` with [powerrun](https://www.sordum.org/downloads/?power-run), otherwise the values won't get applied.

```powershell
"HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\Render\{4bff9f8d-ead4-4ae3-962e-10358e158daf}\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},3","Type: REG_DWORD, Length: 4, Data: 0"
"HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\Render\{4bff9f8d-ead4-4ae3-962e-10358e158daf}\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},4","Type: REG_DWORD, Length: 4, Data: 0"
"HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\Capture\{6119fee4-d49c-474d-978c-0e5f9a67acb3}\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},3","Type: REG_DWORD, Length: 4, Data: 0"
"HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\Capture\{6119fee4-d49c-474d-978c-0e5f9a67acb3}\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},4","Type: REG_DWORD, Length: 4, Data: 0"
"HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\Capture\{6119fee4-d49c-474d-978c-0e5f9a67acb3}\FxProperties\{1da5d803-d492-4edd-8c23-e0c0ffee7f0e},5","Type: REG_DWORD, Length: 4, Data: 1"
```

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/audioenhance.png?raw=true)

# Disable Spatial Audio

Spatial audio positions sounds in 3D space around you, surround sound mainly anchors audio to speaker directions.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Audio.txt  
> https://www.dolby.com/experience/home-entertainment/articles/what-is-spatial-audio/

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/spatial.jpeg?raw=true)

---

Miscellaneous notes:
```json
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Audio": {
  "DisableSpatialOnLowLatency": { "Type": "REG_DWORD", "Data": 1 }
}
```

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

# Disable AutoPlay/Autorun

AutoRun is a mechanism that uses an `autorun.inf` file on removable media (like CDs or old USB sticks) to specify a program that should start automatically when the media is inserted. Typical use case was auto starting setup programs on software CDs. Because malware abused this behavior, Windows now strongly restricts or disables automatic execution from `autorun.inf` on most removable drives.

AutoPlay is a feature that detects the type of content on newly inserted media or connected devices and then offers actions such as "Open folder, Play media, Import photos". It can read some information from `autorun.inf`, but it doesn't automatically run programs without user confirmation.

Example `autorun.inf` content:
```inf
[autorun]
open=Launch.exe
icon=Launch.exe
```

| Service | Description |
| --- | --- |
| `ShellHWDetection` | Provides notifications for AutoPlay hardware events. |

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

# Disk Write Cache Policy 
Enables write cache & turns off write cache buffer flushing on all connected disks.

```
\Registry\Machine\SYSTEM\ControlSet001\Enum\SCSI\Disk&Ven_NVMe&Prod_Samsung_SSD_990\5&33c33320&0&000000\Device Parameters\disk : CacheIsPowerProtected
\Registry\Machine\SYSTEM\ControlSet001\Enum\SCSI\Disk&Ven_NVMe&Prod_Samsung_SSD_990\5&33c33320&0&000000\Device Parameters\disk : UserWriteCacheSetting
```
> https://learn.microsoft.com/en-us/previous-versions/troubleshoot/windows-server/turn-disk-write-caching-on-off  
> [peripheral/assets | diskwritecache.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/diskwritecache.c)

# Disable Bluetooth

Self explaining.

# M/K DQS

The value exists by default and is set to `100` decimal (`64` hex). Reducing it doesn't reduce your latency, leave it default.

"Specifies the number of mouse events to be buffered internally by the driver, in nonpaged pool. The allocated size, in bytes, of the internal buffer is this value times the size of the MOUSE_INPUT_DATA structure (defined in NTDDMOU.H)."

```c
v11 = *((_DWORD *)&WPP_MAIN_CB.Reserved + 2); // MouseDataQueueSize value
if (!v11)
{
    // Set default to 100 if value was 0
    v11 = 100;
}
else if (v11 > 0xAAAAAAA) // ≈ 178956970
{
    v12 = 2400;
}
else
{
    v12 = 24 * v11;
}
*((_DWORD *)&WPP_MAIN_CB.Reserved + 2) = v12;

```
__Scenarios:__
Exists & > 0 -> `v11 = reg value`
Value == 0 -> `v11 = 100`
Value not present -> `v11 = 288` ?
Value > `0xAAAAAAA` ->  Clamped to `2400`
Otherwise `v11 * 24`

> https://www.betaarchive.com/wiki/index.php/Microsoft_KB_Archive/102990  
> [peripheral/assets | mkdata-MouConfiguration.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/mkdata-MouConfiguration.c)  
> [peripheral/assets | mkdata-KbdConfiguration.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/mkdata-KbdConfiguration.c)

# Device Manager

The `Clean` option removes non present devices (`-PresentOnly:$false`/`Status -eq 'Unknown'`) via `/remove-device` ([`pnputil`](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/pnputil-command-syntax)).

| Component | Description | Note |
| ---- | ---- | ---- |
| `Microphone` | Audio input device | Disable if unused |
| `Speakers` | Audio output device | Disable if unused |
| `High Definition Audio Controller` | Main audio bus/controller for sound devices | Disable if not in use |
| `Generic Monitor` | Basic display driver for monitors | Disabling may affect resolution/brightness (esp. laptops) |
| `WAN Miniports` | Virtual NICs for VPN, PPPoE, remote access, tunneling protocols | Keep if you use VPN/remote access, else can disable |
| `Microsoft ISATAP Adapter` | Tunnels IPv6 over IPv4 infrastructure | Usually safe to disable |
| `Microsoft iSCSI Initiator` | Connects to iSCSI storage targets over network | Disable if you don't use network storage |
| `Microsoft Virtual Drive Enumerator` | Enumerator for virtual drives | Disabling breaks `diskmgmt.msc` |
| `Microsoft RRAS Root Enumerator` | Helper/legacy driver for initializing certain (virtual/older) devices at boot | Usually safe, but can affect legacy/virtual HW |
| `Microsoft System Management BIOS Driver` | Exposes SMBIOS/system info to OS | Disabling breaks GTA V and some system info tools |
| `System Speaker` | Handles system/PC speaker audio (can include monitor audio routing) | Disabling can break monitor audio |

---

Click on `View` > `Devices by connection`.

- Go into `PCI Bus` / `PCI Express Root Complex`
    - Disable all `PCI-to-PCI Bridge` devices, which are unused (`PCI Express Downstream Switch Port`)

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/devman.png?raw=true)

> https://learn.microsoft.com/en-us/powershell/module/pnpdevice/get-pnpdevice?view=windowsserver2025-ps  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/pnputil-command-syntax

# Disable Touch & Tablet

Disable the touch screen feature of your device with:
```powershell
Get-PnpDevice -PresentOnly:$false | ? FriendlyName -eq 'HID-compliant touch screen' | % { pnputil /disable-device "$($_.InstanceId)" }
```

"Tablet mode makes Windows more touch friendly and is helpful on touch capable devices."

> https://support.microsoft.com/en-us/windows/turn-tablet-mode-on-or-off-in-windows-add3fbce-5cb5-bf76-0f9c-8d7b30041f30  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Wisp.txt  
> [peripheral/assets | touch-IsTouchDisabled.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/touch-IsTouchDisabled.c)

---

Everything listed below is based on personal research. Mistakes may exist, some parts are speculations. See links below for reference.

```c
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
    "MultiTouchEnabled"; = 1;

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad";
    "AAPThreshold"; = 2; // range 0–4, touchpad sensitivity
    "CursorSpeed"; = 10; // range 1–20, pointer speed
    "FeedbackIntensity"; = 50; // range 0–100 (%), haptic feedback strength
    "ClickForceSensitivity"; = 50; // range 0–100 (%), relative click-force sensitivity
    "LeaveOnWithMouse"; = 1; // 0 = disable touchpad when mouse present, 1 = leave enabled
    "FeedbackEnabled"; = 1; // 0 = no haptics, 1 = haptics on
    "TapsEnabled"; = 1; // 0/1, single-finger tap-to-click
    "TapAndDrag"; = 1; // 0/1, double-tap-and-drag
    "TwoFingerTapEnabled"; = 1; // 0/1
    "RightClickZoneEnabled"; = 1; // 0/1
    "PanEnabled"; = 1; // 0/1, two-finger scrolling
    "ScrollDirection"; = 0; // 0 = natural, 1 = reversed
    "ZoomEnabled"; = 1;
    "HonorMouseAccelSetting" = 0; // 0 = always apply acceleration, 1 = honor SPI mouse accel?
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
    "STCDefaultMigrationCompleted"; = 0; // SHRegValueExists

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell";
    "TabletMode"; = 0; // 0 = desktop mode, 1 = tablet mode?
    "ExitedTabletModeWhileCSMActive"; = 0; // set to 1 when a3 == 4, HasConvertibleSlateModeChanged() is true
    "TabletModeActivated"; = 0; // set to 1 when SetModeInternal() switches into tablet mode

"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell";
    "AllowPPITabletModeExit"; = 0; // SHRegGetBOOLWithREGSAM, non-zero allows the mode switch

"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell\\OverrideScaling";
    "SmallScreen"; = 83; // ?
    "VerySmallScreen"; = 71; // ?
    "TabletSmallScreen"; = 83; // ?

"HKCU\\Software\\Microsoft\\Wisp\\Pen\\SysEventParameters\\FlickCommands";
    "Left" = { 0x4846455758C33841, 0x9F7145B888BB26B8 };
    "UpLeft" = { 0x47F38E42CEFA51BC, 0xEBDFECA56A8CB1AC };
    "Up"= { 0x450285124653D974, 0x8090833CF6D41AA0 };
    "UpRight" = { 0x47F38E42CEFA51BC, 0x6A8CB1ACEBDFECA5 };
    "Right" = { 0xC267B8DE4FA8068E, 0x4E301EF93B324FAB };
    "DownRight" = { 0x47F38E42CEFA51BC, 0x6A8CB1ACEBDFECA5 };
    "Down" = { 0x441A7051435776E6, 0xF7C82D37F0853D9B };
    "DownLeft" = { 0x47F38E42CEFA51BC, 0xEBDFECA56A8CB1AC };
```

> [peripheral/assets | touch-twinui.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/touch-twinui.c)  
> [peripheral/assets | touch-InitializeInputSettingsGlobals.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/touch-InitializeInputSettingsGlobals.c)

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

# Disable Wake on Input

```bat
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```
`powercfg /devicequery wake_programmable` -> devices that are user-configurable to wake the system from a sleep state
`powercfg /devicequery wake_armed` -> currently configured to wake the system from any sleep state

```bat
powercfg /devicedisablewake device
```
Disables the device (replace '*Device*' with the device name) from waking the system from any sleep state. 

> https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#availablesleepstates-or-a

`WakeOnInputDeviceTypes.bat` probably disables wake on input behavior for all input devices - each bit represents a input device type? Since `\SYSTEM\INPUT` only queries two values I'll add the second on in here.
```
\Registry\Machine\SYSTEM\INPUT : UnDimOnInputDeviceTypes
\Registry\Machine\SYSTEM\INPUT : WakeOnInputDeviceTypes
```
`UnDimOnInputDeviceTypes` probably refers to any dimmed elemets (pure speculation)? Disabling it wouldn't make sense.

Default values:
```c
WakeOnInputDeviceTypes = 6
UnDimOnInputDeviceTypes = -1  // 0xFFFFFFFF
```
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Input.txt  
> [peripheral/assets | wakedev-WakeOnInputDeviceTypes.c](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/wakedev-WakeOnInputDeviceTypes.c)

--- 

All available flags (`powercfg /devicequery query_flag`):

| `query_flag`             | Description                                                                      |
| ------------------------ | -------------------------------------------------------------------------------- |
| `wake_from_S1_supported` | Returns all devices that support waking the system from a light sleep state.     |
| `wake_from_S2_supported` | Returns all devices that support waking the system from a deeper sleep state.    |
| `wake_from_S3_supported` | Returns all devices that support waking the system from the deepest sleep state. |
| `wake_from_any`          | Returns all devices that support waking the system from any sleep state.         |
| `S1_supported`           | Lists devices supporting light sleep.                                            |
| `S2_supported`           | Lists devices supporting deeper sleep.                                           |
| `S3_supported`           | Lists devices supporting deepest sleep.                                          |
| `S4_supported`           | Lists devices supporting hibernation.                                            |
| `wake_programmable`      | Lists devices that are user-configurable to wake the system from a sleep state.  |
| `wake_armed`             | Lists devices currently configured to wake the system from any sleep state.      |
| `all_devices`            | Returns all devices present in the system.                                       |

# Enable MSI Mode

Enables MSI for USB, video, network, and IDE PCI devices & sets them to undefined. Setting the priority to high can be beneficial, but needs benchmarking. Removes `MessageNumberLimit`, so device uses the maximum MN itself.

> https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/enabling-message-signaled-interrupts-in-the-registry  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-message-signaled-interrupts  
> https://github.com/5Noxi/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf

"Interrupt affinity defines which logical processors handle a device's interrupts, using the `KAFFINITY` bitmask in the `AssignmentSetOverride` registry value (bit 0 = CPU 0, bit 1 = CPU 1, etc.). To apply it, `DevicePolicy` must be set to `4` (`IrqPolicySpecifiedProcessors`). Interrupt priority controls the urgency of handling and is set in KMDF drivers via `WdfInterruptSetPolicy`, using values like `WdfIrqPriorityHigh`. Both affinity and priority are stored in the `u.Interrupt` resource descriptor and apply to line-based and MSI/MSI-X interrupts. These settings optimize performance by balancing load and improving locality on multi-core systems."
> https://github.com/MicrosoftDocs/windows-driver-docs/blob/staging/windows-driver-docs-pr/kernel/interrupt-affinity-and-priority.md

Example:
```bat
delete "\Affinity Policy" /v DevicePriority /f
:: IrqPolicySpecifiedProcessors
add "\Affinity Policy" /v DevicePolicy /t REG_DWORD /d 4 /f
:: CPU 5
add "\Affinity Policy" /v AssignmentSetOverride /t REG_BINARY /d 2000000000000000 /f
add "\MessageSignaledInterruptProperties" /v MSISupported /t REG_DWORD /d 1 /f
delete "\MessageSignaledInterruptProperties" /v MessageNumberLimit /f
```
`AssignmentSetOverride` calculation:
```powershell
$cpus = @(5)
$mask = 0
$cpus | % { $mask = $mask -bor (1 -shl $_) }
'{0:X16}' -f $mask
```
> https://github.com/BoringBoredom/Windows-MultiTool  
> [peripheral/assets | MSI-Paper.pdf](https://github.com/5Noxi/win-config/blob/main/peripheral/assets/MSI-Paper.pdf)

# Disable Dynamic Lighting

"Dynamic Lighting is a feature that allows you to control LED-powered devices such as keyboards, mice, and other illuminated accessories. This feature enables you to coordinate the colors of LEDs, creating a unified lighting experience both within Windows and across all your devices."

| Value  | Type      | Values                                                                                                                                                                                                   | Ranges                     | Notes                                                                 |
| ---------------------------------------- | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------- | --------------------------------------------------------------------- |
| `AmbientLightingEnabled`                   | REG_DWORD | `0 = off`, `1 = on`                                                                                                                                                                                      | `0–1`                      | Master toggle for Dynamic Lighting.                                   |
| `UseSystemAccentColor`                     | REG_DWORD | `0 = use custom Color/Color2`, `1 = match Windows accent`                                                                                                                                                | `0–1`                      | When `1`, `Color` is ignored.                                         |
| `Color`                                    | REG_DWORD | `COLORREF (RGB)`                                                                                                                                                                                         | `0x00000000–0x00FFFFFF`    | Format `0x00BBGGRR`. Used when `UseSystemAccentColor = 0`.            |
| `Color2`                                   | REG_DWORD | `COLORREF (RGB)`                                                                                                                                                                                         | `0x00000000–0x00FFFFFF`    | Secondary color for some effects.                                     |
| `EffectType`                               | REG_DWORD | `0 = Solid`, `1 = Breathing`, `2 = Rainbow`, `4 = Wave`, `5 = Wheel`, `6 = Gradient`                                                                                                                     | `discrete enum`            | Defines animation.                                                    |
| `Speed`                                    | REG_DWORD | `integer`                                                                                                                                                                                                | `1–10`                     | Higher = faster.                                                      |
| `EffectMode`                               | REG_DWORD | Rainbow: `0 = Forward`, `1 = Reverse` · Wave: `0 = Right`, `1 = Left`, `2 = Down`, `3 = Up` · Wheel: `0 = Clockwise`, `1 = Counterclockwise` · Gradient: `0 = Horizontal`, `1 = Vertical`, `2 = Outward` | `discrete enum per effect` | Depends on `EffectType`.                                              |
| `Brightness`                              | REG_DWORD | `integer (%)`                                                                                                                                                                                            | `0–100`                    | - |
| `ControlledByForegroundApp`               | REG_DWORD | `0 = ignore apps`, `1 = apps can take control`                                                                                                                                                           | `0–1`                      | -     |


> https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/dynamic-lighting-devices  
> https://support.microsoft.com/en-us/windows/control-dynamic-lighting-devices-in-windows-8e8f22e3-e820-476c-8f9d-9ffc7b6ffcd2

# Disable Printing

Disables printer related services (`Spooler`, `PrintWorkFlowUserSvc`, `PrintNotify`, `usbprint`, `McpManagementService`, `PrintScanBrokerService`, `PrintDeviceConfigurationService`), and various optional features / scheduled tasks.

Remove the `Print` option from the context menu:
```
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

---

List all printer connections:
```powershell
Get-Printer
```
> https://learn.microsoft.com/en-us/powershell/module/printmanagement/get-printer?view=windowsserver2025-ps

Remove a specific printer using it's name:
```powershell
Remove-Printer -Name "Printer Name"
```
> https://learn.microsoft.com/en-us/powershell/module/printmanagement/remove-printer?view=windowsserver2025-ps

# Sample Rate

For your knowledge: The sample rate is the amount of times (in a second) an audio singal is measured. The amount of bits that are used to represent each sample (higher bit range = higher dynamic range and volume potential). The best sample rate and bit depth depends on what you're doing, the most commonly used sample rate for production and similar is `44.1` kHz.

`44.1` kHz = `44,100` times per second

As you may know a bit can be `0` or `1`, means (bit depth * `6` = dB):
`8` bit = `256` values
`16` bit = `65536` values
`24` bit = `16777216` values

`44.1` kHz with a bit depth of `16` is more than enough for general usage.

> https://noirsonance.com/bit-depth-calculator-visualizer/  
> https://de.wikipedia.org/wiki/Nyquist-Shannon-Abtasttheorem

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/samplerate.png?raw=true)

# Mouse DPI

Use `800` or `1600`. Going too low will end in worse results, as shown in the pictures ([1](https://www.youtube.com/watch?v=mwf_F2VboFQ&t=458s), [2](https://www.youtube.com/watch?v=imYBTj2RXFs&t=274s)).

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/dpi1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/dpi2.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/dpi3.png?raw=true)

# Polling Rate

Higher sampling rates reduce jitter and latency and ensure more accurate cursor positioning (first image), but may affect performance depending on the hardware (CPU cycles) - [*](https://www.youtube.com/watch?v=jtATbpMqbL4). Using `4 kHz` on a mid-tier PC should not be a problem. Run benchmarks on your system to check whether your PC can handle this rate. It should always be `1 kHz+`. You can use [MouseTester](https://github.com/valleyofdoom/MouseTester/releases) to check if your current polling rate is stable.

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/polling1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/polling2.png?raw=true)

# Monitor Settings

Before starting the configuration, load your default settings, as many settings are already correctly configured by default.

## **Game Mode** - `User`  
Each profile has preconfigured settings. E.g. 'Read mode' is optimized for viewing documents, it probably decreases the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) and increases the color temperature. Choose the profile you're satisfied with, for example the sRGB profile if you're a editor, then configure the other settings.

## **Overdrive/OD/Response Time** - `Test`  
If you experience [ghosting](https://www.testufo.com/ghosting) (most noticeable in fast paced motions, e.g. FPS games), caused by a slow response time, which cannot keep up with the speed of the changing image, you should try to increase the OD option, which will increase the response time of your monitor. Ghosting looks like a image artifact that appears as a trail of pixels behind a moving object (pixels can't change color fast enough when a new image appears, parts of the old image remain visible), which is why it gets called ghosting -> the trace looks like a ghost of the object. Increasing the overdrive setting can end up in overshooting/inverse ghosting, which is the opposite of ghosting and get's caused from a too high OD. Which means that the response time is too fast for your monitor to handle it, resulting in pixels changing their color too fast. Ghosting (normally) ends up in a trace behind the object (like motion blur), inverse ghosting can cause artifacts in front and behind the object. Search for your monitor [here](https://www.rtings.com/), scroll down to the motion section and compare the response times, to see if your monitor even performs the best one the fastest option. And no you won't "see" a difference between them, if you experience inverse ghosting, renounce the lowest response time and decrease it (as ghosting makes the image unclear -> annoying), if you experience ghosting increase and test it.

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/monitor1.png?raw=true)

## **Sharpness** - `0%`  
Personal preference. Increasing it too much will end up in [artificial sharpening](http://www.lagom.nl/lcd-test/sharpness.php) = exaggerated outlines.

## **Dark Boost/Black Boost** - `Off`  
Improved vision in [dark scenes](https://www.testufo.com/blacklevels) when increased, but can end up making black look gray, so don't increase it too much. 

## **FreeSync, G-Sync...** - `Disabled`  
G-Sync matches the monitor's refresh rate to the frame rate. The setting is used to eliminate screen tearing, if you don't experience [screen tearing](https://www.youtube.com/watch?v=5mWMP96UdGU&t=110s), leave it disabled. If you want to use it, set your framerate limit a bit lower (kind of a buffer, `freq-(freq*freq)/3600`) than your refresh rate. Optimally set the limit within the game. Never use pure V-Sync -> G-Sync + V-Sync + Reflex & limit. [Gsync/gsync101-input-lag-tests-and-settings](https://blurbusters.com/gsync/gsync101-input-lag-tests-and-settings/) can still be read. It is old, but most of it is still correct. If information from the text above and from the website text don't match, the channel information is correct.

## **Color Temperature** - `Warm`  
Changing it is one of the best ways to reduce eye stain. Using a warm temperature -> less [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/). (read the text below for more information about [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/)) Default mostly is `6500K`. One thing to add: a higher temperature will make it easier for you to concentrate.

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/monitor2.png?raw=true)

## **Brightness** - `50-70`  
Depends on how much light there is in your room. If there's a lot of light, you'll have to increase the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/). If you mainly play in the dark, it's recommended to reduce the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) to a level that is comfortable for your eyes. Remember: decreasing it *can* lower the [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/) by `50+%` -> known to be phototoxic to your eyes ([retina](https://en.wikipedia.org/wiki/Retina) - light sensitive tissue), therefore lower the [brightness](https://plano.co/does-screen-brightness-affect-your-eyes/) to reduce the intensity of [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/). For your general knowledge, [blue light](https://eyesurgeryguide.org/debunking-the-blue-light-eye-damage-myth/) has a short wavelength (~[`450-500`](https://www.livephysics.com/physical-constants/optics-pc/wavelength-colors/)), which means that it carries more energy -> higher impact. Don't dim it too much, or it may end up in worse focus.

![](https://github.com/5Noxi/win-config/blob/main/peripheral/images/monitor3.png?raw=true)

## **Contrast** - `~60`  
It shouldn't be set too high, otherwise you will [not be able to see any details](https://www.testufo.com/whitelevels) and not too low, or it will be too dark. You'll have to test it yourself and find the best value.
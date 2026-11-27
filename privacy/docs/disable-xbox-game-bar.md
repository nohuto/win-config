# Disable Xbox Game Bar

GameDVR is a built-in gameplay capture (Xbox Game Bar) for clips/screenshots, with optional background recording.

### WindowsMediaCapture Values

```c
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR";
    "AudioEncodingBitrate" // REG_DWORD
    "AudioCaptureEnabled" // REG_DWORD, bool
    "CustomVideoEncodingBitrate" // REG_DWORD
    "CustomVideoEncodingHeight" // REG_DWORD
    "CustomVideoEncodingWidth" // REG_DWORD
    "AppCaptureEnabled" // REG_DWORD, bool
    "HistoricalBufferLength" // REG_DWORD
    "HistoricalBufferLengthUnit" // REG_DWORD
    "HistoricalCaptureEnabled" // REG_DWORD, bool
    "HistoricalCaptureOnBatteryAllowed" // REG_DWORD, bool
    "HistoricalCaptureOnWirelessDisplayAllowed" // REG_DWORD, bool
    "MaximumRecordLength" // REG_QWORD
    "VideoEncodingBitrateMode" // REG_DWORD
    "VideoEncodingResolutionMode" // REG_DWORD
    "VideoEncodingFrameRateMode" // REG_DWORD
    "EchoCancellationEnabled" // REG_DWORD, bool
    "CursorCaptureEnabled" // REG_DWORD, bool
    "VKToggleGameBar" // REG_DWORD
    "VKMToggleGameBar" // REG_DWORD
    "VKSaveHistoricalVideo" // REG_DWORD
    "VKMSaveHistoricalVideo" // REG_DWORD
    "VKToggleRecording" // REG_DWORD
    "VKMToggleRecording" // REG_DWORD
    "VKTakeScreenshot" // REG_DWORD
    "VKMTakeScreenshot" // REG_DWORD
    "VKToggleRecordingIndicator" // REG_DWORD
    "VKMToggleRecordingIndicator" // REG_DWORD
    "VKToggleMicrophoneCapture" // REG_DWORD
    "VKMToggleMicrophoneCapture" // REG_DWORD
    "VKToggleCameraCapture" // REG_DWORD
    "VKMToggleCameraCapture" // REG_DWORD
    "VKToggleBroadcast" // REG_DWORD
    "VKMToggleBroadcast" // REG_DWORD
    "MicrophoneCaptureEnabled" // REG_DWORD, bool
    "SystemAudioGain" // REG_QWORD, clamped to 0.0-2.0
    "MicrophoneGain" // REG_QWORD, clamped to 0.0-2.0

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings";
    "AudioCaptureEnabled" // REG_DWORD, bool
    "MicrophoneCaptureEnabledByDefault" // REG_DWORD, bool
    "EchoCancellationEnabled" // REG_DWORD, bool
    "CursorCaptureEnabled" // REG_DWORD, bool
    "SystemAudioGain" // REG_QWORD, clamped to 0.0-2.0
    "MicrophoneGain" // REG_QWORD, clamped to 0.0-2.0
    "CameraCaptureEnabledByDefault" // REG_DWORD, bool
    "CameraOverlayLocation" // REG_DWORD
    "CameraOverlaySize" // REG_DWORD
    "SelectedCameraId" // REG_SZ
```

`VK*` & `VKM*` are the user defined alternate shortcuts, key & modifier (`AppCaptureAlternateShortcutKeys` in `bcastdvruserservice.dll`).

- [privacy/assets/pseudocode | gamebar-WindowsMediaCaptureIAppCaptureSettings.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/gamebar-WindowsMediaCaptureIAppCaptureSettings.c) (`HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR`)
- [privacy/assets/pseudocode | gamebar-WindowsMediaCaptureIAppBroadcastGlobalSettings.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/gamebar-WindowsMediaCaptureIAppBroadcastGlobalSettings.c) (`HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings`)
- [settings/settings-windows-11.md#gaming-game-bar-game-mode-gaming-shortcuts](https://github.com/MicrosoftDocs/windows-dev-docs/blob/docs/hub/apps/develop/settings/settings-windows-11.md#gaming-game-bar-game-mode-gaming-shortcuts)

### Game Bar Presence Writer

> "*Game Bar Presence Writer is a component that is notified when a game's "presence" state (i.e. is a game running in the foreground) changes. This functionality is available in Windows 10 and later operating systems. By default, the existing Game Bar Presence Writer will set a user's Xbox Live presence state for a running game if the Xbox App is installed, the user is signed into their Xbox account, and the user has enabled Xbox Live presence to be set when they run a game on their PC. It is possible for Windows Application developers to override this default behavior with their own implementation.*"
>
> — Microsoft, [GameBar PresenceWriter](https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter)

#### ActivationType

[ActivationType](https://learn.microsoft.com/en-us/windows/win32/api/activationregistration/ne-activationregistration-activationtype) is used to set how a WinRT class is activated:

```c
typedef enum ActivationType {
  ActivationType_InProcess,    // 0, DLL loaded into calling process
  ActivationType_OutOfProcess, // 1, exe running in a separate process
  ActivationType_RemoteProcess // 2, remote process activation
} ;
```

```c
//
// https://github.com/nohuto/win-config/blob/main/assets/sxs-registry/23H2/25.tsv#L1222
//

// default ActivationType = 1
HKLM\Software\Microsoft\WindowsRuntime\ActivatableClassId\Windows.Gaming.GameBar.PresenceServer.Internal.PresenceWriter	ActivationType	REG_DWORD	0x00000001	amd64_microsoft-gaming-ga..rnal-presencewriter

//
// https://github.com/nohuto/win-config/blob/main/assets/sxs-registry/23H2/30.tsv#L2685
//

// default ExePath = $(runtime.system32)\GameBarPresenceWriter.exe
HKLM\Software\Microsoft\WindowsRuntime\Server\Windows.Gaming.GameBar.Internal.PresenceWriterServer	ExePath	REG_SZ	$(runtime.system32)\GameBarPresenceWriter.exe	amd64_microsoft-gaming-ga..rnal-presencewriter
```

With `ActivationType = 0`, `combase.dll` uses the in process kind and fails in `CWinRTActivationStoreCatalog::CActivatableClassPropertiesHelper::GetThreadingModel` with `0x80070002` as `Threading` is missing, before getting into the DLL path check.

```c
// CWinRTActivationStoreCatalog::CRuntimeClassInfo::FinalConstruct

if ( this->_activationType )
  goto LABEL_29; // nonzero activation types skip threading check
ThreadingModel = CWinRTActivationStoreCatalog::CActivatableClassPropertiesHelper::GetThreadingModel(
                   &activatableClassHelper,
                   &this->_threadingModel);
```

```c
// CWinRTActivationStoreCatalog::CActivatableClassPropertiesHelper::GetThreadingModel

if ( !this->_machineProperties.Threading.Present )
  return (unsigned int)-2147024894; // 0x80070002, HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
```

#### Miscellaneous GameBar UI Values

In `HKCU\Software\Microsoft\GameBar`:

| Value | Meaning |
| --- | --- |
| `UseNexusForGameBarEnabled` | "Open Xbox Game Bar using this button on a controller" |
| `ShowStartupPanel`, `GamePanelStartupTipIndex` | Game Bar startup tips |
| `GamepadNexusChordEnabled` | Controller shortcut, only read on 25H2 (no 23H2 binary has it) |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enables or disables Windows Game Recording and Broadcasting](https://noverse.dev/policies?p=GameDVR*AllowGameDVR) | `HKLM\Software\Policies\Microsoft\Windows\GameDVR` | `AllowGameDVR` |

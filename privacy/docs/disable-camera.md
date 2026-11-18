# Disable Camera

Disallows the use of a camera on your system, by denying access via `LetAppsAccessCamera`/`AllowCamera`/services (and app permission).

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `FrameServer` | Enables multiple clients to access video frames from camera devices. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k Camera |
| `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k CameraMonitor |
| `StiSvc` | Provides image acquisition services for scanners and cameras | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k imgsvc |

## Suboption

### Disable Lock Screen Camera

> "*Disables the lock screen camera toggle switch in PC Settings and prevents a camera from being invoked on the lock screen.By default, users can enable invocation of an available camera on the lock screen.If you enable this setting, users will no longer be able to enable or disable lock screen camera access in PC Settings, and the camera cannot be invoked on the lock screen.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps access the camera](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessCamera) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessCamera` |
| [Allow Use of Camera](https://noverse.dev/policies?p=Camera*L_AllowCamera) | `HKLM\software\Policies\Microsoft\Camera` | `AllowCamera` |
| [Prevent enabling lock screen camera](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoLockScreenCamera) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoLockScreenCamera` |


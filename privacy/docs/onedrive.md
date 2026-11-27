# OneDrive

- `Disable` = sets both policies below & hides OneDrive in the explorer navigation pane
- `Enable` = deletes policies and shows it again
- `Uninstall` = runs `OneDriveSetup.exe /uninstall` (`System32` on W11, `SysWOW64` on W10), and also removed leftovers:

```c
// paths
%LOCALAPPDATA%\Microsoft\OneDrive
%LOCALAPPDATA%\OneDrive
%PROGRAMDATA%\Microsoft OneDrive
%SYSTEMDRIVE%\OneDriveTemp
%APPDATA%\Microsoft\Windows\Start Menu\Programs\OneDrive.lnk
// if empty
%USERPROFILE%\OneDrive

// registry keys/values
HKCU\Environment : OneDrive
HKCU\Software\RegisteredApplications : OneDrive
HKCU\Software\Microsoft\Windows\CurrentVersion\Run\AutorunsDisabled : OneDrive
HKCU\Software\Microsoft\OneDrive
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\StorageProvider\OneDrive
HKLM\SOFTWARE\Microsoft\OneDrive
HKLM\SOFTWARE\WOW6432Node\Policies\Microsoft\Windows\OneDrive
HKCR\CLSID\{018D5C66-4533-4307-9B53-224DE2ED1FE6}
HKCR\Wow6432Node\CLSID\{018D5C66-4533-4307-9B53-224DE2ED1FE6}

// scheduled tasks
\\OneDrive*
```

## [Windows Policies](https://noverse.dev/policies)

All other OneDrive related policies are used in `Windows_6_3only - Windows Server 2012 R2, Windows 8.1 or Windows RT 8.1 only`, which is why I won't include them.

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent the usage of OneDrive for file storage](https://noverse.dev/policies?p=SkyDrive*PreventOnedriveFileSync) | `HKLM\Software\Policies\Microsoft\Windows\OneDrive` | `DisableFileSyncNGSC` |
| [Prevent OneDrive from generating network traffic until the user signs in to OneDrive](https://noverse.dev/policies?p=SkyDrive*PreventNetworkTrafficPreUserSignIn) | `HKLM\SOFTWARE\Microsoft\OneDrive` | `PreventNetworkTrafficPreUserSignIn` |


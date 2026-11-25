# Remove Power Options

Removes the `Hibernate`, `Lock`, `Sleep` power options.

If hiding `Lock` for example via `Control Panel > All Control Panel Items > Power Options > Choose what the power buttons do > Change settings that are currently unavailable`, it sets:

```c
DllHost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FlyoutMenuSettings\ShowLockOption	Type: REG_DWORD, Length: 4, Data: 1
```

---

Miscellaneous keys:
```powershell
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HidePowerButton
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideRestart
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideShutDown
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSignOut
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSwitchAccount
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Show lock in the user tile menu](https://noverse.dev/policies?p=WindowsExplorer*ShowLockOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowLockOption` |
| [Show sleep in the power options menu](https://noverse.dev/policies?p=WindowsExplorer*ShowSleepOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowSleepOption` |
| [Show hibernate in the power options menu](https://noverse.dev/policies?p=WindowsExplorer*ShowHibernateOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowHibernateOption` |


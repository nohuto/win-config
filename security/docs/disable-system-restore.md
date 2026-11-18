# Disable System Restore

```powershell
Disable-ComputerRestore -Drive "C:\"
```
Does:
```powershell
"wmiprvse.exe", "RegSetValue","HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\SystemRestore\RPSessionInterval","Type: REG_DWORD, Length: 4, Data: 0"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Configuration](https://noverse.dev/policies?p=SystemRestore*SR_DisableConfig) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableConfig` |
| [Turn off System Restore](https://noverse.dev/policies?p=SystemRestore*SR_DisableSR) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableSR` |


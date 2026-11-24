# Disable System Restore

Works via `Disable-ComputerRestore`, '[*Turn off System Restore*](https://noverse.dev/policies?p=SystemRestore*SR_DisableSR)' & '[*Turn off Configuration*](https://noverse.dev/policies?p=SystemRestore*SR_DisableConfig)' & its correponding service/task.

## RPSessionInterval

`Disable-ComputerRestore` writes:

```powershell
"wmiprvse.exe", "RegSetValue","HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\SystemRestore\RPSessionInterval","Type: REG_DWORD, Length: 4, Data: 0"
```

Note that value only shows the state, e.g. `srclient.dll` writes it after `DisableVolume`, `EnableVolume`, `SrInternalSysprepGeneralize`... so writing it yourself enable/disable it.

```c
// SxUpdateSystemRestoreEnabled (23H2)

  if ( v3 < 0 || (v7 = 1110, v3 = SxRegWriteDWORD(hKey, L"RPSessionInterval", a1 != 0), v6 = v3, v4 = 1112, v3 < 0) ) // 0 after Disable-ComputerRestore
```
```c
// DisableVolume (23H2)

      UniqueVolumeForPath = SxUpdateSystemRestoreEnabled(*((_DWORD *)v4 + 4) != 0);
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Configuration](https://noverse.dev/policies?p=SystemRestore*SR_DisableConfig) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableConfig` |
| [Turn off System Restore](https://noverse.dev/policies?p=SystemRestore*SR_DisableSR) | `HKLM\Software\Policies\Microsoft\Windows NT\SystemRestore` | `DisableSR` |

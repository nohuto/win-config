# Disable Storage Sense

Storage Sense deletes temporary/user files automatically, see [windows policies](https://noverse.dev/docs/win-config/system/disable-storage-sense/#windows-policies) for more & [disable-notifications/#registry-values](https://noverse.dev/docs/win-config/system/disable-notifications/#registry-values) for storage sense related notification values.

Head over to the `Policies` tab, then `StorageSense` to configure other related policies.

### SystemSettings Captures

The main storage sense toggle in `System > Storage` does the same as the `Automatic User content cleanup` in `System > Storage > Storage Sense`.

```c
// System > Storage > Storage Sense

// Keep WIndows running smoothly by automatically cleaning up temorary system and app files
// 1 = On
// 0 = Off
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\04 // Type: REG_DWORD

// Automatic User content cleanup
// 1 = On
// 0 = Off
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\01 // Type: REG_DWORD

// Run Storage Sense
// During low free disk space (default) = 0
// Every month = 30
// Every week = 7
// Every day = 1
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\2048	// Type: REG_DWORD

// Delete files in my recycle bin if they have been there for over
// 30 days (default): 08 = 1, 25 = 30
// 60 days: 08 = 1, 256 = 60
// 14 days: 08 = 1, 256 = 14
// 1 day: 08 = 1, 256 = 1
// Never: 08 = 0, 256 = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\08 // Type: REG_DWORD
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\256 // Type: REG_DWORD

// Delete files in my Downloads folder if they haven't been opened for more than
// Never (default): 32 = 0, 512 = 0
// 1 day: 32 = 1, 512 = 1
// 14 days: 32 = 1, 512 = 14
// 30 days: 32 = 1, 512 = 30
// 60 days: 32 = 1, 512 = 60
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\32 // Type: REG_DWORD
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\512 // Type: REG_DWORD
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Storage Sense](https://noverse.dev/policies?p=StorageSense*SS_AllowStorageSenseGlobal) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `AllowStorageSenseGlobal` |
| [Allow Storage Sense Temporary Files cleanup](https://noverse.dev/policies?p=StorageSense*SS_AllowStorageSenseTemporaryFilesCleanup) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `AllowStorageSenseTemporaryFilesCleanup` |
| [Configure Storage Sense Recycle Bin cleanup threshold](https://noverse.dev/policies?p=StorageSense*SS_ConfigStorageSenseRecycleBinCleanupThreshold) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `ConfigStorageSenseRecycleBinCleanupThreshold` |
| [Configure Storage Storage Downloads cleanup threshold](https://noverse.dev/policies?p=StorageSense*SS_ConfigStorageSenseDownloadsCleanupThreshold) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `ConfigStorageSenseDownloadsCleanupThreshold` |


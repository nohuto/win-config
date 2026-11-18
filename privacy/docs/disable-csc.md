# Disable CSC

Disable Offline Files (CSC) via policy and services. Sets NetCache policy keys, disables `CSC`/`CscService`, disables the two `Offline Files` scheduled tasks (they're disabled by default), and renames `mobsync.exe` to block execution.

> "*Offline Files (Client-Side Caching, CSC) lets Windows cache files from network shares locally so users can keep working when the network/server is unavailable. Sync Center handles the background sync between the local CSC cache (`%WINDIR%\CSC`) and the share. It's commonly paired with Folder Redirection so "known folders" (e.g., Documents) live on a server but remain available offline, with options like "Always Offline" for performance on slow links. You enable/disable it via Sync Center (Control Panel) or policy. When disabled, Sync Center has nothing to sync.*"

- [folder-redirection/disable-offline-files-on-folders](https://learn.microsoft.com/en-us/windows-server/storage/folder-redirection/disable-offline-files-on-folders#windows-powershell-equivalent-commands) (todo)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow or Disallow use of the Offline Files feature](https://noverse.dev/policies?p=OfflineFiles*Pol_Enabled) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `Enabled` |
| [Turn off reminder balloons](https://noverse.dev/policies?p=OfflineFiles*Pol_NoReminders_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `NoReminders` |
| [Synchronize all offline files before logging off](https://noverse.dev/policies?p=OfflineFiles*Pol_SyncAtLogoff_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `SyncAtLogoff` |
| [Synchronize all offline files when logging on](https://noverse.dev/policies?p=OfflineFiles*Pol_SyncAtLogon_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `SyncAtLogon` |
| [Configure Background Sync](https://noverse.dev/policies?p=OfflineFiles*Pol_BackgroundSyncSettings) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `BackgroundSyncEnabled`<br>`BackgroundSyncPeriodMin`<br>`BackgroundSyncMaxStartMin`<br>`BackgroundSyncIgnoreBlockOutAfterMin`<br>`BackgroundSyncBlockOutStartTime`<br>`BackgroundSyncBlockOutDurationMin`<br>`BackgroundSyncEnabledForForcedOffline` |
| [Remove "Work offline" command](https://noverse.dev/policies?p=OfflineFiles*Pol_WorkOfflineDisabled_2) | `HKLM\Software\Policies\Microsoft\Windows\NetCache` | `WorkOfflineDisabled` |


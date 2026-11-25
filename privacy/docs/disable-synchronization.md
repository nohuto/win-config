# Disable Synchronization

When settings synchronization is turned on, a user's settings are synced across all Windows devices when they sign in with the same account.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not sync](https://noverse.dev/policies?p=SettingSync*DisableSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableSettingSync`<br>`DisableSettingSyncUserOverride` |
| [Do not sync app settings](https://noverse.dev/policies?p=SettingSync*DisableApplicationSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableApplicationSettingSync`<br>`DisableApplicationSettingSyncUserOverride` |
| [Do not sync passwords](https://noverse.dev/policies?p=SettingSync*DisableCredentialsSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableCredentialsSettingSync`<br>`DisableCredentialsSettingSyncUserOverride` |
| [Do not sync personalize](https://noverse.dev/policies?p=SettingSync*DisablePersonalizationSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisablePersonalizationSettingSync`<br>`DisablePersonalizationSettingSyncUserOverride` |
| [Do not sync Apps](https://noverse.dev/policies?p=SettingSync*DisableAppSyncSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableAppSyncSettingSync`<br>`DisableAppSyncSettingSyncUserOverride` |
| [Do not sync other Windows settings](https://noverse.dev/policies?p=SettingSync*DisableWindowsSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableWindowsSettingSync`<br>`DisableWindowsSettingSyncUserOverride` |
| [Do not sync desktop personalization](https://noverse.dev/policies?p=SettingSync*DisableDesktopThemeSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableDesktopThemeSettingSync`<br>`DisableDesktopThemeSettingSyncUserOverride` |
| [Do not sync browser settings](https://noverse.dev/policies?p=SettingSync*DisableWebBrowserSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableWebBrowserSettingSync`<br>`DisableWebBrowserSettingSyncUserOverride` |
| [Do not sync on metered connections](https://noverse.dev/policies?p=SettingSync*DisableSyncOnPaidNetwork) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableSyncOnPaidNetwork` |
| [Do not sync accessibility settings](https://noverse.dev/policies?p=SettingSync*DisableAccessibilitySettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableAccessibilitySettingSync`<br>`DisableAccessibilitySettingSyncUserOverride` |
| [Do not sync language preferences settings](https://noverse.dev/policies?p=SettingSync*DisableLanguageSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableLanguageSettingSync`<br>`DisableLanguageSettingSyncUserOverride` |
| [Enable Windows Backup](https://noverse.dev/policies?p=SettingSync*EnableWindowsBackup) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `EnableWindowsBackup` |
| [Allow Message Service Cloud Sync](https://noverse.dev/policies?p=messaging*AllowMessageSync) | `HKLM\Software\Policies\Microsoft\Windows\Messaging` | `AllowMessageSync` |

## Windows Backup

The ADMX text says Windows Backup only runs when `EnableWindowsBackup` is enabled, but thats only true for work/school accounts. With the value missing, a MS account keeps roaming its settings and the Windows Backup sync groups:

```c
// GetIsRoamingEnabledForAccount (25H2)

WindowsBackupPolicyState = GetWindowsBackupPolicyState((enum WindowsBackupPolicyState *)&v10);

if ( v10 == 1 )
  goto LABEL_13; // enabled, roaming = on
if ( (v10 & 0xFFFFFFFD) == 0 )
  goto LABEL_14; // value 0

LABEL_14:
  *a2 = 0; // roaming off for this account
```

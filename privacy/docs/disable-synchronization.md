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
| [Do not sync start settings](https://noverse.dev/policies?p=SettingSync*DisableStartLayoutSettingSync) | `HKLM\Software\Policies\Microsoft\Windows\SettingSync` | `DisableStartLayoutSettingSync`<br>`DisableStartLayoutSettingSyncUserOverride` |


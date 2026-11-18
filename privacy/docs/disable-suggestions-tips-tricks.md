# Disable Suggestions/Tips/Tricks

Disables all kind of suggestions, in start, text suggestions (multilingual...), in the timeline, content. `338389` is the only value named `SubscribedContent-{number}Enabled` that exists by default.

### SubscribedContent IDs

Since the `SubscribedContent-*` values aren't documented literally anywhere I've tried to get some information to see which exist and what they do. You can find information on them in `ContentDeliveryManager.Utilities.dll`, see [contentdelivery.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/contentdelivery.c) for asm snippets that include these information.

| Feature | IDs | Practical meaning |
|---|---|---|
| `LockScreen` | `338380`, `338387` | Windows Spotlight / lock-screen creative content |
| `WindowsTip` | `338382`, `338389` | tips, tricks, and suggested Windows content - `338389` is used for '*System > Notifications > Additional settings - Get tips and suggestions when using Windows*' |
| `StartSuggestions` | `338381`, `338388` | suggested/recommended content in Start |
| `Settings` | `338386`, `338393` | promoted content inside Settings |
| `SettingsHome` | `353697`, `353696` | Settings Home recommendations/cards |
| `SettingsAccountsYourInfo` | `353695`, `353694` | promoted content in Settings > Accounts > Your info |
| `SettingsValueBanner` | `88000106`, `88000105` | banner/value-promoting content in Settings |
| `OobeOffers` | `314566`, `314567` | OOBE and post-setup offers |
| `MinuteZeroOffers` | `310094`, `310093` | very-early setup / first-run offers - `310093` is used for 'System > Notifications > Additional settings - Show the Windows welcome experience after updates and when signed in to show what's new and suggested' |
| `ApiTest` | `280812` | internal/test subscription used by CDM |
| `ActionCenter` | `310092`, `310091` | Action Center / notification-surface content |
| `ShareAppSuggestions` | `280814`, `280815` | app suggestions around sharing flows |
| `SilentInstalledApps` | `202913`, `202914` | silent/preinstalled app delivery |
| `PeopleAppSuggestions` | `314562`, `314563` | People-related app suggestions |
| `DynamicLayouts` | `314558`, `314559` | dynamic layout-driven targeted content |
| `DynamicLayoutsSV` | `88000531`, `88000530` | variant of dynamic layouts |
| `Timeline` | `353699`, `353698` | Timeline related suggested content |
| `AppDefaultsEdgeEnlightenment` | `88000044`, `88000045` | Edge/default-app promotion |
| `OneDriveLocal` | `280797`, `280811` | local OneDrive promotion/setup |
| `OneDriveSync` | `280817`, `280810` | OneDrive sync promotion/setup |
| `OneDriveDocuments` | `88000162`, `88000161` | OneDrive documents backup/setup |
| `OneDriveDesktop` | `88000164`, `88000163` | OneDrive desktop backup/setup |
| `OneDrivePictures` | `88000166`, `88000165` | OneDrive pictures backup/setup |

`SubscribedContent-338393Enabled` `SubscribedContent-353694Enabled` ,`SubscribedContent-353696Enabled` are used in 'Privacy & security > Recommendations & offers - Recommendatins and offers in Settings' but only when toggling it off (when toggling it on they stay at `0`).

I'll look into these soon:

```c
SubscribedContent-88000325Enabled	TRACE	(value not set)		Yes (23H2)				
SubscribedContent-88000326Enabled	TRACE	(value not set)		Yes (23H2)				
```

### Windows Spotlight

> "*Windows spotlight is a feature that displays different wallpapers and offers suggestions, fun facts, tips, or organizational messages:*  
> *- Wallpapers: Windows spotlight displays a new image on the lock screen and in the background every day*  
> *- Suggestions, fun facts, tips: recommendations on how to enhance the user's productivity of Microsoft products. They're displayed in different locations, such as the lock screen, the background, the taskbar, or the Get Started app*  
> *- Organizational messages: messages from your organization, which can be displayed in the lock screen, taskbar, the notification area, or the Get Started app*"
>
> — Microsoft, [Configure Windows spotlight](https://learn.microsoft.com/en-us/windows/configuration/windows-spotlight/?pivots=windows-11)

![](https://github.com/nohuto/win-config/blob/main/privacy/images/lockscreen-spotlight.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Microsoft consumer experiences](https://noverse.dev/policies?p=CloudContent*DisableWindowsConsumerFeatures) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsConsumerFeatures` |
| [Turn off cloud optimized content](https://noverse.dev/policies?p=CloudContent*DisableCloudOptimizedContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableCloudOptimizedContent` |
| [Turn off cloud consumer account state content](https://noverse.dev/policies?p=CloudContent*DisableConsumerAccountStateContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableConsumerAccountStateContent` |
| [Do not show Windows tips](https://noverse.dev/policies?p=CloudContent*DisableSoftLanding) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableSoftLanding` |
| [Do not suggest third-party content in Windows spotlight](https://noverse.dev/policies?p=CloudContent*DisableThirdPartySuggestions) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableThirdPartySuggestions` |
| [Allow Online Tips](https://noverse.dev/policies?p=ControlPanel*AllowOnlineTips) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `AllowOnlineTips` |
| [Remove Recommended section from Start Menu](https://noverse.dev/policies?p=StartMenu*HideRecommendedSection) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideRecommendedSection` |
| [Remove Personalized Website Recommendations from the Recommended section in the Start Menu](https://noverse.dev/policies?p=StartMenu*HideRecommendedPersonalizedSites) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideRecommendedPersonalizedSites` |
| [Turn off display of recent search entries in the File Explorer search box](https://noverse.dev/policies?p=WindowsExplorer*DisableSearchBoxSuggestions) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `DisableSearchBoxSuggestions` |
| [Configure Windows spotlight on lock screen](https://noverse.dev/policies?p=CloudContent*ConfigureWindowsSpotlight) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `ConfigureWindowsSpotlight`<br>`IncludeEnterpriseSpotlight` |
| [Turn off all Windows spotlight features](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightFeatures) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightFeatures` |
| [Turn off Spotlight collection on Desktop](https://noverse.dev/policies?p=CloudContent*DisableSpotlightCollectionOnDesktop) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableSpotlightCollectionOnDesktop` |
| [Do not suggest third-party content in Windows spotlight](https://noverse.dev/policies?p=CloudContent*DisableThirdPartySuggestions) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableThirdPartySuggestions` |
| [Turn off Windows Spotlight on Action Center](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightOnActionCenter) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightOnActionCenter` |
| [Turn off Windows Spotlight on Settings](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightOnSettings) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightOnSettings` |
| [Turn off the Windows Welcome Experience](https://noverse.dev/policies?p=CloudContent*DisableWindowsSpotlightWindowsWelcomeExperience) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsSpotlightWindowsWelcomeExperience` |


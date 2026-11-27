# Disable Suggestions/Tips/Tricks

Disables all kind of suggestions, in start, text suggestions (multilingual...), content. `338389` is the only value named `SubscribedContent-{number}Enabled` that exists by default.

### SubscribedContent IDs

Since the `SubscribedContent-*` values aren't documented literally anywhere I've tried to get some information to see which exist and what they do. You can find information on them in `ContentDeliveryManager.Utilities.dll`, see [ContentDeliveryManager-SubscriptionIds.asm](https://github.com/nohuto/win-config/blob/main/privacy/assets/disassembly/ContentDeliveryManager-SubscriptionIds.asm) for asm snippets that include these ID strings.

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
| `Timeline` | `353699`, `353698` | Timeline related suggested content, W10 only ([Windows 11 removed Timeline](https://www.microsoft.com/en-us/windows/windows-11-specifications)) |
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

### Start/Search/Notification Values

See [en-US strings of the 23H2 Settings app](https://github.com/nohuto/win-config/blob/main/assets/settings-app/23H2/strings.txt) (`Windows.UI.SettingsAppThreshold.en-US.pri`).

| Value | Meaning |
| --- | --- |
| `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced : Start_IrisRecommendations` | Personalization > Start '*Show recommendations for tips, shortcuts, new apps, and more*'. `get_ShouldShowIrisRecommendations` (`windowsudk.shellcommon.dll`) missing = on |
| `HKCU\Software\Microsoft\Windows\CurrentVersion\UserProfileEngagement : ScoobeSystemSettingEnabled` | System > Notifications > Additional settings '*Suggest ways to get the most out of Windows and finish setting up this device*' |
| `HKCU\Software\Microsoft\Windows\CurrentVersion\SystemSettings\AccountNotifications : EnableAccountNotifications` | Privacy & security > General '*Show me notifications in the Settings app*' ('*When off, required notifications are still shown*'). `IsAccountNotificationsEnabled` (`SettingsEnvironment.Desktop.dll`) missing = on |
| `HKCU\Software\Microsoft\Windows\CurrentVersion\Search : BingSearchEnabled` | Web results in Windows search, W11 has no toggle for it, but 23H2 still reads it in `IsLegacyBingSearchEnabled` (`windowsudk.shellcommon.dll`) and 24H2/25H2 query it during boot |

### Touch Keyboard & Typing Values

`HKCU\Software\Microsoft\TabletTip\1.7` includes the touch keyboard toggles of Time & language > Typing, `SettingsHandlers_Keyboard.dll` reads them in `_TouchKeyboardGetBoolValue` and `SpellingEnableReader`, missing = on:

```c
// WindowsInternal::TextInputSettings::SettingsManager::_TouchKeyboardGetBoolValue (23H2)

DWORDFromRegistryValue = WindowsInternal::TextInputSettings::SettingsManager::GetDWORDFromRegistryValue(
                           a3,
                           L"TabletTip\\1.7",
                           a1,
                           &v8);
v6 = 0;
if ( DWORDFromRegistryValue )
  LOBYTE(v6) = v8 != 0;
else
  v6 = 1; // missing = on
```

| Value | Meaning |
| --- | --- |
| `EnableAutocorrection` | '*Autocorrect misspelled words*' |
| `EnableSpellchecking` | '*Highlight misspelled words*' |
| `EnableTextPrediction` | '*Show text suggestions as I type*' |
| `EnablePredictionSpaceInsertion` | '*Add a space after I choose a text suggestion*' |
| `EnableAutoShiftEngage` | '*Capitalize the first letter of each sentence*' |
| `EnableDoubleTapSpace` | '*Add a period after I double-tap the Spacebar*' |

`HKCU\Software\Microsoft\Input\Settings` has the toggles that aren't touch keyboard only:

| Value | Meaning |
| --- | --- |
| `EnableHwkbTextPrediction` | '*Show text suggestions when typing on the physical keyboard*' |
| `EnableHwkbAutocorrection2` | Autocorrection for physical keyboard |
| `MultilingualEnabled` | '*Show text suggestions based on the recognized languages you're typing in*' |
| `InsightsEnabled` | '*Typing insights*' ('*View your typing and corrections history*') |
| `UserStatsEnabled` | Counters on the Typing insights page ('*Autocompleted words*', '*Spelling corrections*', ...) |

`HKLM\Software\Microsoft\Input\Settings`:

| Value | Meaning |
| --- | --- |
| `AUTOCORRECTFIRSTWORD` | Autocorrect the first word of a sentence (default = 1) |
| `MAXCORRECTIONS` | How many corrections the word corrector offers (`FlipSettings::GetMaxCorrections`), default = 4 |
| `DisablePersonalizationGTKM` | 1 sets `EditBuffer::s_fDisableUserAdaptation` |
| `ShowAllSuggestions` | Read once by `WordCorrector::LoadShowAllSuggestionsSetting`, missing = 1 |
| `InsightsEnabled`, `UserStatsEnabled` | Fallback for the HKCU values above |

### ContentDeliveryManager Values

All in `HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager`:

| Value | Meaning |
| --- | --- |
| `ContentDeliveryAllowed`, `RotatingLockScreenEnabled`, `RotatingLockScreenOverlayEnabled` | Lock screen Spotlight and its text overlay, read in [`GetLockScreenEnabled`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ContentDeliveryManager-Utilities/-GetLockScreenEnabled@LockScreenCreativeConfigHelpers@CreativeFramework@@YAJPEBGPEA_N1@Z.c) |
| `SoftLandingEnabled` | Windows tips, CDM app (`ContentDeliveryManager.Background.dll`) reads it in `WindowsTipSubscriptionActivationHelper::IsSoftLandingSettingsEnabled` before it enables the `WindowsTip` subscription, missing = on |
| `SystemPaneSuggestionsEnabled` | Start suggestions, `StartSuggestionsSubscriptionActivationHelper::IsStartSuggestionSettingsEnabled` reads it before it enables the `StartSuggestions` subscription, missing = on |
| `FeatureManagementEnabled` | `FeatureManagementPlacement::IsFeatureManagementEnabled` only reads it for accounts in a `.MICROSOFT.COM` domain ([`IsAnyMicrosoftDomainAccount`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ContentDeliveryManager-Utilities/-IsAnyMicrosoftDomainAccount@Policy@CreativeFramework@@YA_NXZ.c)) |
| `OemPreInstalledAppsEnabled`, `PreInstalledAppsEnabled`, `PreInstalledAppsEverEnabled`, `SilentInstalledAppsEnabled` | These don't seem to exist on 23H2 |

### Windows Spotlight

> "*Windows spotlight is a feature that displays different wallpapers and offers suggestions, fun facts, tips, or organizational messages:*  
> *- Wallpapers: Windows spotlight displays a new image on the lock screen and in the background every day*  
> *- Suggestions, fun facts, tips: recommendations on how to enhance the user's productivity of Microsoft products. They're displayed in different locations, such as the lock screen, the background, the taskbar, or the Get Started app*  
> *- Organizational messages: messages from your organization, which can be displayed in the lock screen, taskbar, the notification area, or the Get Started app*"
>
> — Microsoft, [Configure Windows spotlight](https://learn.microsoft.com/en-us/windows/configuration/windows-spotlight/?pivots=windows-11)

![](https://github.com/nohuto/win-config/blob/main/privacy/images/lockscreen-spotlight.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

Note that most CloudContent policies here only work on Enterprise/Education, means on Home/Pro the ContentDeliveryManager values above are used.

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Microsoft consumer experiences](https://noverse.dev/policies?p=CloudContent*DisableWindowsConsumerFeatures) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableWindowsConsumerFeatures` |
| [Turn off cloud optimized content](https://noverse.dev/policies?p=CloudContent*DisableCloudOptimizedContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableCloudOptimizedContent` |
| [Turn off cloud consumer account state content](https://noverse.dev/policies?p=CloudContent*DisableConsumerAccountStateContent) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableConsumerAccountStateContent` |
| [Do not show Windows tips](https://noverse.dev/policies?p=CloudContent*DisableSoftLanding) | `HKLM\Software\Policies\Microsoft\Windows\CloudContent` | `DisableSoftLanding` |
| [Do not suggest third-party content in Windows spotlight](https://noverse.dev/policies?p=CloudContent*DisableThirdPartySuggestions) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableThirdPartySuggestions` |
| [Do not use diagnostic data for tailored experiences](https://noverse.dev/policies?p=CloudContent*DisableTailoredExperiencesWithDiagnosticData) | `HKCU\Software\Policies\Microsoft\Windows\CloudContent` | `DisableTailoredExperiencesWithDiagnosticData` |
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


# Windows Update

| Option | Description |
| ---- | ---- |
| `Disable WU` | Stops normal Windows Update scanning, download, install, and orchestrated update activity. |
| `Enable WU` | Restores normal update behavior for the controls managed in this section. |
| `Security Only` | Keeps monthly Windows quality and security servicing for the current release while blocking feature upgrades, WU driver updates, optional content, CFR rollouts, preview content, Microsoft product updates, and MRT through Windows Update. |

## Suboptions

| Suboption | Description |
| ---- | ---- |
| `Disable Feature Updates` | Keeps the device on its current Windows release while quality updates continue. New Windows releases are not offered until removed. |
| `Disable Quality Updates (35D)` | Temporarily pauses monthly cumulative updates, including security fixes. Security fixes stop until the pause is cleared or expires. |
| `Disable WU Driver Updates` | Blocks Windows Update from installing driver-class updates. Hardware fixes and newer vendor drivers are not delivered through Windows Update. |
| `Disable Microsoft Product Updates` | Stops updates for other Microsoft products through this channel. Office and other Microsoft apps stop receiving updates from Windows Update. |
| `Disable Optional Updates` | Hides optional update content from normal servicing. Optional fixes and non-essential improvements are not offered. |
| `Disable CFR Features` | Stops gradual rollout features delivered through servicing. New feature rollouts arrive later or only through full releases. |
| `Disable Preview Builds` | Prevents preview and Insider-style update content. Pre-release Windows builds and preview tracks are unavailable. |
| `Disable Store App Updates` | Stops automatic Microsoft Store app updates. Store apps stop receiving background fixes and feature updates. |
| `Disable Device Metadata Retrieval` | Stops automatic retrieval of device metadata from Microsoft. Device names, icons, and related suggestions may be less complete. |
| `Disable Automatic Root Certificate Updates` | Stops automatic refresh of trusted root certificates. Some secure sites, apps, or signed content can fail until trust is updated another way. |
| `Disable Defender Definition Updates` | Stops Defender definition updates from this update path. Malware detection ages quickly unless another definition source is provided. |
| `Block MRT via WU` | Stops the MRT (Malicious Software Removal Tool) from being offered through Windows Update. MRT scans and related reporting are unavailable from this channel. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Specify search order for device driver source locations](https://noverse.dev/policies?p=DeviceSetup*DriverSearchPlaces_SearchOrderConfiguration) | `HKLM\Software\Policies\Microsoft\Windows\DriverSearching` | `SearchOrderConfig` |
| [Prevent automatic download of applications associated with device metadata](https://noverse.dev/policies?p=DeviceSetup*DeviceMetadata_PreventDeviceMetadataFromNetwork) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Device Metadata` | `PreventDeviceMetadataFromNetwork` |
| [Turn off Automatic Root Certificates Update](https://noverse.dev/policies?p=ICM*CertMgr_DisableAutoRootUpdates) | `HKLM\Software\Policies\Microsoft\SystemCertificates\AuthRoot` | `DisableRootAutoUpdate` |
| [Turn off Windows Update device driver searching](https://noverse.dev/policies?p=ICM*DriverSearchPlaces_DontSearchWindowsUpdate) | `HKLM\Software\Policies\Microsoft\Windows\DriverSearching` | `DontSearchWindowsUpdate` |
| [Turn off access to all Windows Update features](https://noverse.dev/policies?p=ICM*RemoveWindowsUpdate_ICM) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DisableWindowsUpdateAccess` |
| [Define file shares for downloading security intelligence updates](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_DefinitionUpdateFileSharesSources) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `DefinitionUpdateFileSharesSources` |
| [Define the order of sources for downloading security intelligence updates](https://noverse.dev/policies?p=WindowsDefender*SignatureUpdate_FallbackOrder) | `HKLM\Software\Policies\Microsoft\Windows Defender\Signature Updates` | `FallbackOrder` |
| [Turn off Automatic Download and Install of updates](https://noverse.dev/policies?p=WindowsStore*DisableAutoInstall) | `HKLM\Software\Policies\Microsoft\WindowsStore` | `AutoDownload` |
| [Turn off Automatic Download of updates on Win8 machines](https://noverse.dev/policies?p=WindowsStore*DisableAutoDownloadWin8) | `HKLM\Software\Policies\Microsoft\WindowsStore` | `AutoDownload` |
| [Configure Automatic Updates](https://noverse.dev/policies?p=WindowsUpdate*AutoUpdateCfg) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate\AU` | `NoAutoUpdate`<br>`AUOptions`<br>`AutomaticMaintenanceEnabled`<br>`ScheduledInstallDay`<br>`ScheduledInstallTime`<br>`AllowMUUpdateService`<br>`ScheduledInstallEveryWeek`<br>`ScheduledInstallFirstWeek`<br>`ScheduledInstallSecondWeek`<br>`ScheduledInstallThirdWeek`<br>`ScheduledInstallFourthWeek` |
| [Specify intranet Microsoft update service location](https://noverse.dev/policies?p=WindowsUpdate*CorpWuURL) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate`<br>`HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsUpdate\AU` | `WUServer`<br>`WUStatusServer`<br>`UpdateServiceUrlAlternate`<br>`FillEmptyContentUrls`<br>`DoNotEnforceEnterpriseTLSCertPinningForUpdateDetection`<br>`SetProxyBehaviorForUpdateDetection`<br>`UseWUServer` |
| [Do not connect to any Windows Update Internet locations](https://noverse.dev/policies?p=WindowsUpdate*DoNotConnectToWindowsUpdateInternetLocations) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DoNotConnectToWindowsUpdateInternetLocations` |
| [Select the target Feature Update version](https://noverse.dev/policies?p=WindowsUpdate*TargetReleaseVersion) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `TargetReleaseVersion`<br>`ProductVersion`<br>`TargetReleaseVersionInfo` |
| [Manage preview builds](https://noverse.dev/policies?p=WindowsUpdate*ManagePreviewBuilds) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `ManagePreviewBuildsPolicyValue`<br>`BranchReadinessLevel` |
| [Select when Quality Updates are received](https://noverse.dev/policies?p=WindowsUpdate*DeferQualityUpdates) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `DeferQualityUpdates`<br>`DeferQualityUpdatesPeriodInDays`<br>`PauseQualityUpdatesStartTime` |
| [Do not include drivers with Windows Updates](https://noverse.dev/policies?p=WindowsUpdate*ExcludeWUDriversInQualityUpdate) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `ExcludeWUDriversInQualityUpdate` |
| [Remove access to use all Windows Update features](https://noverse.dev/policies?p=WindowsUpdate*DisableUXWUAccess) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetDisableUXWUAccess` |
| [Remove access to "Pause updates" feature](https://noverse.dev/policies?p=WindowsUpdate*DisablePauseUXAccess) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetDisablePauseUXAccess` |
| [Enable features introduced via servicing that are off by default](https://noverse.dev/policies?p=WindowsUpdate*AllowTemporaryEnterpriseFeatureControl) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `AllowTemporaryEnterpriseFeatureControl` |
| [Enable optional updates](https://noverse.dev/policies?p=WindowsUpdate*AllowOptionalContent) | `HKLM\Software\Policies\Microsoft\Windows\WindowsUpdate` | `SetAllowOptionalContent`<br>`AllowOptionalContent` |


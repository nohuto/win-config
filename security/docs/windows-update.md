# Windows Update

| Option | Description |
| ---- | ---- |
| `Disable WU` | Stops normal Windows Update scanning, download, install, and orchestrated update activity. |
| `Enable WU` | Restores normal update behavior for the controls managed in this section. |
| `Security Only` | Pins the device to its current Windows release and keeps monthly quality and security updates, while blocking WU driver updates, optional content, CFR rollouts, preview content, Microsoft product updates, and MRT through Windows Update. |

## Suboptions

| Suboption | Description |
| ---- | ---- |
| `Disable Feature Updates` | Pins the device to its current Windows release. |
| `Disable Quality Updates (35D)` | Pauses quality updates (monthly cumulative and security updates) for 35 days from today. |
| `Disable Driver Updates` | Blocks Windows Update from installing driver-class updates. Hardware fixes and newer vendor drivers are not delivered through Windows Update. |
| `Disable Microsoft Product Updates` | Sets `AllowMUUpdateService = 0` & removes the MS Update service (`7971f918-a847-4430-9279-4a52d1efe18d`), as the policy value alone doesn't undo an existing registration ([Policy CSP Update](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-update#allowmuupdateservice)). Office and other Microsoft apps stop receiving updates from Windows Update. Reverting deletes the policy, turn "*Receive updates for other Microsoft products*" in Settings back on yourself. |
| `Disable Optional Updates` | Sets the optional updates policy (`AllowOptionalContent`) to `0`, "Don't receive optional updates" ([Policy CSP Update](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-update#allowoptionalcontent)). |
| `Disable CFR Features` | Stops gradual rollout features delivered through servicing. New feature rollouts arrive later or only through full releases. |
| `Disable Preview Builds` | Prevents preview and Insider-style update content. Pre-release Windows builds and preview tracks are unavailable. |
| `Disable Windows Insider` | Turns off Insider builds, configuration flighting & experiments, hides the Windows Insider Program page (`WindowsSelfHost\UI\Visibility\HideInsiderPage`) and disables the Windows Insider Service (`wisvc`). |
| `Disable Store App Updates` | Stops automatic Microsoft Store app updates. Store apps stop receiving background fixes and feature updates. |
| `Disable Device Metadata Retrieval` | Stops automatic retrieval of device metadata from Microsoft. Device names, icons, and related suggestions may be less complete. |
| `Disable Automatic Root Certificate Updates` | Stops automatic refresh of trusted root certificates. Some secure sites, apps, or signed content can fail until trust is updated another way. |
| `Disable Defender Definition Updates` | Stops Defender definition updates from this update path. Malware detection ages quickly unless another definition source is provided. |
| `Block MRT via WU` | Stops the MRT (Malicious Software Removal Tool) from being offered through Windows Update (`DontOfferThroughWUAU`) and stops MRT from reporting infections to Microsoft (`DontReportInfectionInformation`, [KB891716](https://support.microsoft.com/en-us/help/891716)). |
| `Disable Disk Failure Prediction Model Updates` | Stops downloads of the disk failure prediction model used by the storage service ([Allow downloading updates to the Disk Failure Prediction Model](https://noverse.dev/policies?p=StorageHealth*SH_AllowDiskHealthModelUpdates)). |
| `Disable Update Health Tools` | Disables the Update Health Tools service (`uhssvc`), expedited quality updates and remote actions for Intune/Windows Update for Business devices stop. Windows Update itself keeps working, see [Update Health Tools](#update-health-tools). |

## Update Health Tools

On a PC without an Entra (Azure AD) or work account join it uploads nothing (would upload to `devicelistenerprod.microsoft.com`), but it checks for a join every 240min, logs "Device is not AAD joined" and waits again.

Update Health Tools isn't part of a clean install (missing on clean 25H2 and W10 22H2), Windows Update installs it later. Its installer (`unifiedinstaller.dll`, `GetTargetPlatform`) leaves the service disabled on Home/Pro (`ConsumerInstaller`). It sets it to automatic (delayed start) on Enterprise/Education, joined, ConfigMgr or MDM managed PCs, and if an update pause policy is set while it installs (`PauseQualityUpdatesStartTime`, `PauseQualityUpdates` or `PauseFeatureUpdatesStartTime`, `ReadPolicyWithFallback(32)` then counts the PC as Windows Update for Business managed). `Disable Quality Updates (35D)` writes `PauseQualityUpdatesStartTime`, so a PC that had it applied when Update Health Tools got installed runs the service.

VM test (25H2 Home, Update Health Tools 5.72.0.0 MSI): without a pause policy `Start` = `4` ("Entered Consumer Conditional"), with `PauseQualityUpdatesStartTime` set `Start` = `2` and `DelayedAutostart` = `1` ("Entered WUFB Conditional").

```c
// CUpdateHealthService::ExecuteListenForPushNotifications (uhssvc.exe)

AadJoinInformation = NetGetAadJoinInformation(0LL, &CorrelationVector);
v25 = CorrelationVector;
if ( !AadJoinInformation )
{
  if ( !CorrelationVector )
    goto LABEL_36;
  if ( *(_DWORD *)CorrelationVector )
  {
    if ( (unsigned int)(*(_DWORD *)CorrelationVector - 1) < 2 ) // DSREG_DEVICE_JOIN/DSREG_WORKPLACE_JOIN
    {
      v23 = 1;
    }

if ( !v23 )
{
  RemediationTraceLoggerT<CEmptyType>::LogInformation(
    0LL,
    L"Error:Device is not AAD joined. Device needs to be AAD joined in order for the expedite to work. Waiting for next check");

  v21 = 240; // minutes, then back to the loop start
LABEL_26:
  if ( !CUpdateHealthService::DelayOrStop(this, v21) )
    goto LABEL_133;

  if ( !(_DWORD)v55 && v13 )
  {
    RemediationTraceLoggerT<CEmptyType>::LogInformation(
      0LL,
      L"Client is newly installed on the device. Attempting to upload device information");
    v56 = CUpdateHealthService::UploadDeviceInformation(this, (struct WSD::UhsClientConnections *)v112, 1, 1);
```

```c
// WSD::ConsumerInstaller::ConfigureServices (unifiedinstaller.dll)

  if ( hService )
  {
    if ( ChangeServiceConfigW(hService, 0xFFFFFFFF, 4u, 0xFFFFFFFF, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL, 0LL) ) // SERVICE_DISABLED
```

```c
// WSD::HealthToolsInstaller::GetTargetPlatform (unifiedinstaller.dll)

if ( *(_DWORD *)a2 == 4 )
{
  *((_DWORD *)a3 + 8) = WSD::ApplicabilityHelper::IsDeviceWUFBManaged((bool *)a3 + 5);
  if ( *((_BYTE *)a3 + 5) )
  {
    *(_DWORD *)a2 = 3; // 3 = WUFB, CommercialInstaller (Start 2, DelayedAutostart 1)
    std::wstring::append(&Src, L"Entered WUFB Conditional");
```

```c
// WSD::ApplicabilityHelper::IsDeviceWUFBManaged (unifiedinstaller.dll)

v6 = ((__int64 (__fastcall *)(__int64, void **))ProcAddress)(32LL, &v10); // true while a pause policy is set (VM test)
v7 = v10;
v8 = v6;
if ( *((_DWORD *)v10 + 1) != 1 )
  goto LABEL_9;
v9 = (VARIANTARG *)((char *)v10 + 16);
if ( *((_WORD *)v10 + 8) == 3 )
{
  if ( *((_DWORD *)v10 + 6) )
  {
    *a1 = 1;
```

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
| [Toggle user control over Insider builds](https://noverse.dev/policies?p=AllowBuildPreview*AllowBuildPreview) | `HKLM\Software\Policies\Microsoft\Windows\PreviewBuilds` | `AllowBuildPreview` |
| [Allow downloading updates to the Disk Failure Prediction Model](https://noverse.dev/policies?p=StorageHealth*SH_AllowDiskHealthModelUpdates) | `HKLM\Software\Policies\Microsoft\Windows\StorageHealth` | `AllowDiskHealthModelUpdates` |

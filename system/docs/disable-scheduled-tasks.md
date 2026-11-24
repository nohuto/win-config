# Disable Scheduled Tasks

This list was created using my small [`ScheduledTasksList.ps1`](https://github.com/nohuto/win-config/blob/main/system/assets/scripts/ScheduledTasksList.ps1) parser which displays name, path, description, principals, settings, triggers, actions if given.

## Scheduled Tasks Table

### CEIP

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Autochk\Proxy` | This task collects and uploads autochk SQM data if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\rundll32.exe /d acproxy.dll,PerformAutochkOperations` |
| `\Microsoft\Windows\Customer Experience Improvement Program\UsbCeip` | The USB CEIP (Customer Experience Improvement Program) task collects Universal Serial Bus related statistics and information about your machine and sends it to the Windows Device Connectivity engineering group at Microsoft.  The information received is used to help improve the reliability, stability, and overall functionality of USB in Windows.  If the user has not consented to participate in Windows CEIP, this task does not do anything. | `ClassId:{C27F6B1D-FE0B-45E4-9257-38799FA69BC8}` |
| `\Microsoft\Windows\Customer Experience Improvement Program\Consolidator` | If the user has consented to participate in the Windows Customer Experience Improvement Program, this job collects and sends usage data to Microsoft. | `%WINDIR%\System32\wsqmcons.exe` |
| `\Microsoft\Windows\Customer Experience Improvement Program\Uploader` | - | - |
| `\Microsoft\Windows\Customer Experience Improvement Program\Server\ServerCeipAssistant` | - | - |
| `\Microsoft\Windows\Customer Experience Improvement Program\Server\ServerRoleUsageCollector` | - | - |

### Error Reporting

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Windows Error Reporting\QueueReporting` | Windows Error Reporting task to process queued reports. | `%windir%\system32\wermgr.exe -upload` |

### Offline Files

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Offline Files\Background Synchronization` | This task controls periodic background synchronization of Offline Files when the user is working in an offline mode. | `ClassId:{FA3F3DD9-4C1A-456B-A8FA-C76EF3ED83B8}` |
| `\Microsoft\Windows\Offline Files\Logon Synchronization` | This task initiates synchronization of Offline Files when a user logs onto the system. | `ClassId:{FA3F3DD9-4C1A-456B-A8FA-C76EF3ED83B8}` |

### Printing

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Printing\PrintJobCleanupTask` | - | `ClassId:{8ABCE260-32B6-476C-AE13-B34D0C91292D}` |
| `\Microsoft\Windows\Printing\PrinterCleanupTask` | - | `ClassId:{C56F065E-DE49-4E42-BE7C-305C45609D25}` |
| `\Microsoft\Windows\Printing\EduPrintProv` | - | `%windir%\system32\eduprintprov.exe` |

### Wi-Fi Service

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\WCM\WiFiTask` | Background task for performing per user and web interactions | `%WINDIR%\System32\WiFiTask.exe` |
| `\Microsoft\Windows\WlanSvc\CDSSync` | - | `ClassId:{B0D2B535-12E1-439F-86B3-BADA289510F0}` |
| `\Microsoft\Windows\WwanSvc\NotificationTask` | Background task for performing per user and web interactions | `%WINDIR%\System32\WiFiTask.exe wwan` |
| `\Microsoft\Windows\WwanSvc\OobeDiscovery` | - | `ClassId:{C93CF9D5-031B-4AAA-AB0B-EF802347B381}` |
| `\Microsoft\Windows\WlanSvc\MoProfileManagement` | - | `ClassId:{085EDA12-CF4A-4944-8222-8ADCADE137CB}` |

### Office Telemetry

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Office\OfficeTelemetryAgentFallBack` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentFallBack2016` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentLogOn` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentLogOn2016` | - | - |

### NVIDIA Telemetry

| Task | Description | Action Command |
| --- | --- | --- |
| `NvTmRep_*` | Sends data at 12:25PM daily | - |
| `NvTmRepOnLogon*` | Sends data on logon | - |
| `NvTmMon_*` | Sends data on logon, then in a 1H interval | - |

### Feedback

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Feedback\Siuf\DmClient` | Update SIUF strings | `%windir%\system32\dmclient.exe` |
| `\Microsoft\Windows\Feedback\Siuf\DmClientOnScenarioDownload` | Update SIUF strings | `%windir%\system32\dmclient.exe utcwnf` |

### Application Experience

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Application Experience\MareBackup` | Gathers Win32 application data for App Backup scenario | `%windir%\system32\compattelrunner.exe -m:aeinv.dll -f:UpdateSoftwareInventoryW invsvc ; %windir%\system32\compattelrunner.exe -m:appraiser.dll -f:DoScheduledTelemetryRun ; %windir%\system32\compattelrunner.exe -m:aemarebackup.dll -f:BackupMareData` |
| `\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser` | Collects program telemetry information if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\sc.exe start InventorySvc` |
| `\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser Exp` | Collects program telemetry information if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\compattelrunner.exe -m:appraiser.dll -f:DoScheduledTelemetryRun express` |
| `\Microsoft\Windows\Application Experience\PcaPatchDbTask` | Updates compatibility database | `%windir%\system32\rundll32.exe %windir%\system32\PcaSvc.dll,PcaPatchSdbTask` |
| `\Microsoft\Windows\Application Experience\SdbinstMergeDbTask` | Merges shim databases that are pending merge. | `%windir%\system32\sdbinst.exe -mm` |
| `\Microsoft\Windows\Application Experience\StartupAppTask` | Scans startup entries and raises notification to the user if there are too many startup entries. | `%windir%\system32\rundll32.exe Startupscan.dll,SusRunTask` |

### Maintenance

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\ApplicationData\DsSvcCleanup` | Performs maintenance for the Data Sharing Service. | `%windir%\system32\dstokenclean.exe` |
| `\Microsoft\Windows\CloudExperienceHost\CreateObjectTask` | - | `ClassId:{E4544ABA-62BF-4C54-AAB2-EC246342626C}` |
| `\Microsoft\Windows\Defrag\ScheduledDefrag` | This task optimizes local storage drives. | `%windir%\system32\defrag.exe -c -h -o -$` |
| `\Microsoft\Windows\Diagnosis\RecommendedTroubleshootingScanner` | Check for recommended troubleshooting from Microsoft | `ClassId:{AD08DCC2-4E35-4486-9D49-547CBD30942D}` |
| `\Microsoft\Windows\Diagnosis\Scheduled` | The Windows Scheduled Maintenance Task performs periodic maintenance of the computer system by fixing problems automatically or reporting them through Security and Maintenance. | `ClassId:{C1F85EF8-BCC2-4606-BB39-70C523715EB3}` |
| `\Microsoft\Windows\Diagnosis\UnexpectedCodePath` | - | - |
| `\Microsoft\Windows\DiskCleanup\SilentCleanup` | Maintenance task used by the system to launch a silent auto disk cleanup when running low on free disk space. | `%windir%\system32\cleanmgr.exe /autocleanstoragesense /d %systemdrive%` |
| `\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticDataCollector` | The Windows Disk Diagnostic reports general disk and system information to Microsoft for users participating in the Customer Experience Program. | `%windir%\system32\rundll32.exe dfdts.dll,DfdGetDefaultPolicyAndSMART` |
| `\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticResolver` | The Microsoft-Windows-DiskDiagnosticResolver warns users about faults reported by hard disks that support the Self Monitoring and Reporting Technology (S.M.A.R.T.) standard. This task is triggered automatically by the Diagnostic Policy Service when a S.M.A.R.T. fault is detected. | `%windir%\system32\DFDWiz.exe` |
| `\Microsoft\Windows\DiskFootprint\Diagnostics` | - | `%windir%\system32\disksnapshot.exe -z` |
| `\Microsoft\Windows\DiskFootprint\StorageSense` | - | `ClassId:{AB2A519B-03B0-43CE-940A-A73DF850B49A}` |
| `\Microsoft\Windows\Speech\SpeechModelDownloadTask` | - | `%windir%\system32\speech_onecore\common\SpeechModelDownload.exe` |
| `\Microsoft\Windows\UNP\RunUpdateNotificationMgr` | - | - |
| `\Microsoft\Windows\BrokerInfrastructure\BgTaskRegistrationMaintenanceTask` | Maintains registrations for background tasks for Universal Windows Platform applications. | `ClassId:{E984D939-0E00-4DD9-AC3A-7ACA04745521}` |
| `\Microsoft\Windows\capabilityaccessmanager\maintenancetasks` | Capability Access Manager Maintenance Tasks | `%windir%\system32\rundll32.exe %windir%\system32\CapabilityAccessManager.dll,CapabilityAccessManagerDoStoreMaintenance` |

### Census

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Device Information\Device User` | - | `%windir%\system32\devicecensus.exe UserCxt` |
| `\Microsoft\Windows\Device Information\Device` | - | `%windir%\system32\devicecensus.exe SystemCxt` |

### Update Service

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\InstallService\ScanForUpdates` | - | `ClassId:{A558C6A5-B42B-4C98-B610-BF9559143139}` |
| `\Microsoft\Windows\InstallService\ScanForUpdatesAsUser` | - | `ClassId:{DDAFAEA2-8842-4E96-BADE-D44A8D676FDB}` |
| `\Microsoft\Windows\InstallService\SmartRetry` | - | `ClassId:{F3A219C3-2698-4CBF-9C07-037EDB8E72E6}` |
| `\Microsoft\Windows\InstallService\WakeUpAndContinueUpdates` | - | `ClassId:{0DC331EE-8438-49D5-A721-E10B937CE459}` |
| `\Microsoft\Windows\InstallService\WakeUpAndScanForUpdates` | - | `ClassId:{D5A04D91-6FE6-4FE4-A98A-FEB4500C5AF7}` |

### Localization

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\International\Synchronize Language Settings` | Synchronize User Language Settings from other devices. | `ClassId:{10D62541-90D0-42FE-848C-0DBC1AC42EDA}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\Installation` | Install language components that match the user's language list. | `ClassId:{6F58F65F-EC0E-4ACA-99FE-FC5A1A25E4BE}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\ReconcileLanguageResources` | Install language components that match the user's language list. | `ClassId:{D0582E3B-3126-4CAA-9155-AC37C912A489}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\Uninstallation` | Uninstall language components that are not in any user's language list. | `ClassId:{6F58F65F-EC0E-4ACA-99FE-FC5A1A25E4BE}` |

### Maps

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Maps\MapsUpdateTask` | This task checks for updates to maps which you have downloaded for offline use. Disabling this task will prevent Windows from notifying you of updated maps. | `ClassId:{B9033E87-33CF-4D77-BC9B-895AFBBA72E4}` |
| `\Microsoft\Windows\Maps\MapsToastTask` | This task shows various Map related toasts | `ClassId:{9885AEF2-BD9F-41E0-B15E-B3141395E803}` |

### Sleep Study

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Power Efficiency Diagnostics\AnalyzeSystem` | This task analyzes the system looking for conditions that may cause high energy use. | `ClassId:{927EA2AF-1C54-43D5-825E-0074CE028EEE}` |

### Time Sync

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Time Synchronization\ForceSynchronizeTime` | This task performs time synchronization. | `ClassId:{A31AD6C2-FF4C-43D4-8E90-7101023096F9}` |
| `\Microsoft\Windows\Time Synchronization\SynchronizeTime` | Maintains date and time synchronization on all clients and servers in the network. If this service is stopped, date and time synchronization will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | `%windir%\system32\sc.exe start w32time task_started` |

### Miscellaneous

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Registry\RegIdleBackup` | Registry Idle Backup Task | `ClassId:{CA767AA8-9157-4604-B64B-40747123D5F2}` |
| `\Microsoft\Windows\RetailDemo\CleanupOfflineContent` | Auto cleanup RetailDemo Offline content | `ClassId:{61F77D5E-AFE9-400B-A5E6-E9E80FC8E601}` |

### WU

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\UpdateOrchestrator\Report policies` | - | `%WINDIR%\system32\usoclient.exe ReportPolicies` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Maintenance Work` | - | `%WINDIR%\system32\usoclient.exe StartMaintenanceWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Scan` | - | `%WINDIR%\system32\usoclient.exe StartScan` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Scan Static Task` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartScan` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Wake To Work` | - | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Work` | - | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Start Oobe Expedite Work` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\StartOobeAppsScan_LicenseAccepted` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartOobeAppsScan` |
| `\Microsoft\Windows\UpdateOrchestrator\StartOobeAppsScanAfterUpdate` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartOobeAppsScanAfterUpdate` |
| `\Microsoft\Windows\UpdateOrchestrator\USO_UxBroker` | This task triggers a system reboot following update installation. | `%WINDIR%\system32\MusNotification.exe` |
| `\Microsoft\Windows\UpdateOrchestrator\UUS Failover Task` | - | `%windir%\System32\MLEngineStub.exe HandleUusFailoverEvaluationSignalFromWnf` |
| `\Microsoft\Windows\WindowsUpdate\Scheduled Start` | This task is used to start the Windows Update service when needed to perform scheduled operations such as scans. | `%WINDIR%\System32\sc.exe start wuauserv` |
| `\Microsoft\Windows\WindowsUpdate\Refresh Group Policy Cache` | This task is used to refresh group policy cache in Windows Update | `ClassId:{07369A67-07A6-4608-ABEA-379491CB7C46}` |

### BitLocker

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\BitLocker\BitLocker Encrypt All Drives` | - | `ClassId:{61BCD1B9-340C-40EC-9D41-D7F1C0632F05}` |
| `\Microsoft\Windows\BitLocker\BitLocker MDM Policy Refresh` | - | - |

### Microsoft Account

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\AccountHealth\RecoverabilityToastTask` | AccountHealth Task Handler evaluates the state of a Microsoft Account and takes any necessary repair action | `ClassId:{B7F5B442-EBF8-46CD-9F0B-D8E45ED43492}` |

### Chkdsk

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Chkdsk\ProactiveScan` | NTFS Volume Health Scan | `ClassId:{CF4270F5-2E43-4468-83B3-A8C45BB33EA1}` |
| `\Microsoft\Windows\Chkdsk\SyspartRepair` | - | `%windir%\system32\bcdboot.exe %windir% /sysrepair` |

### OneSettings

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Flighting\OneSettings\RefreshCache` | Task periodically refreshing data for OneSettings clients. | `ClassId:{E07647F7-AED2-48D9-9720-939BC24A8A3C}` |

### Location Notification

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Location\WindowsActionDialog` | Location Notification | `%windir%\System32\WindowsActionDialog.exe` |

### Memory Diagnostic

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\MemoryDiagnostic\AutomaticOfflineMemoryDiagnostic` | Schedules an offline memory diagnostic in response to system events. | `ClassId:{44F6C389-604A-4363-B09A-F38DA08E6079}` |
| `\Microsoft\Windows\MemoryDiagnostic\ProcessMemoryDiagnosticEvents` | Schedules a memory diagnostic in response to system events. | `ClassId:{8168E74A-B39F-46D8-ADCD-7BED477B80A3}` |
| `\Microsoft\Windows\MemoryDiagnostic\RunFullMemoryDiagnostic` | Detects and mitigates problems in physical memory (RAM). | `ClassId:{8168E74A-B39F-46D8-ADCD-7BED477B80A3}` |

### Remote Assistance

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\RemoteAssistance\RemoteAssistanceTask` | Checks group policy for changes relevant to Remote Assistance | `%windir%\system32\RAServer.exe /offerraupdate` |

### SR

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\SystemRestore\SR` | This task creates regular system protection points. | `%windir%\system32\srtasks.exe ExecuteScheduledSPPCreation` |

### Windows Defender

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Windows Defender\Windows Defender Cache Maintenance` | Periodic maintenance task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdCacheMaintenance` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Cleanup` | Periodic cleanup task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdCleanup` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Scheduled Scan` | Periodic scan task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe Scan -ScheduleJob -ScanTrigger 55 -IdleScheduledJob` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Verification` | Periodic verification task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdVerification` |

### AI

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\WindowsAI\Recall\InitialConfiguration` | - | `ClassId:{709FD5EF-7296-4154-BD3A-E9830FCFA60A}` |
| `\Microsoft\Windows\WindowsAI\Recall\PolicyConfiguration` | - | `ClassId:{0BE6820D-B667-4CB6-931B-C153A77DA895}` |
| `\Microsoft\Windows\WindowsAI\Settings\InitialConfiguration` | - | `ClassId:{2886E5FB-4F01-4A89-9A0E-5D6A9C8048AC}` |

### Work Folders

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Work Folders\Work Folders Logon Synchronization` | This task initiates synchronization of Work Folders partnerships when a user logs onto the system. | `ClassId:{97D47D56-3777-49FB-8E8F-90D7E30E1A1E}` |
| `\Microsoft\Windows\Work Folders\Work Folders Maintenance Work` | This task initiates maintenance work required for on-going good performance of data synchronization of Work Folders partnerships. | `ClassId:{63260BCE-A3FB-4A34-AA51-D4D8E877B62B}` |


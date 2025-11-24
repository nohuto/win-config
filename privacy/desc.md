# Disable General Telemetry

Prevents sending info about your computer to microsoft, disables the diagnostic log collection, bluetooth ads (`DataCollection.admx`), the inventory collector. It disables the ads ID ("Windows creates a unique advertising ID per user, allowing apps and ad networks to deliver targeted ads. When enabled, it works like a cookie, linking personal data to the ID for personalized ads. This setting only affects Windows apps using the advertising ID, not web-based ads or third-party methods.") which should be disabled by default, if you toggled all options off in the OS installation phase. See policy explanations below for more details.

```powershell
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\DataCollection : AllowTelemetry_PolicyManager
```
Seems to be a fallback if `AllowTelemetry` isn't set.
> https://github.com/TechTech512/Win11Src/blob/840a61919419c94ed24a9b079ee1029f482d29f2/NT/onecore/base/telemetry/permission/product/telemetrypermission.cpp#L106


Miscellaneous notes:  

Telemetry for DCE usage?
```bat
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows" /v DCEInUseTelemetryDisabled /t REG_DWORD /d 1 /f
```
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Winows-NT.txt

Kills the device and configuration data collection tool and telemetry collector and sender tasks.
```bat
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\CompatTelRunner.exe" /v Debugger /t REG_SZ /d "%windir%\System32\taskkill.exe" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\DeviceCensus.exe" /v Debugger /t REG_SZ /d "%windir%\System32\taskkill.exe" /f
```
```powershell
reg add "HKLM\SOFTWARE\Microsoft\wbem\Tracing" /v enableWinmgmtTelemetry /t REG_DWORD /d 0 /f
```

```json
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "AllowTelemetry",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0",
  "DisplayName": "Allow Diagnostic Data",
  "ExplainText": "By configuring this policy setting you can adjust what diagnostic data is collected from Windows. This policy setting also restricts the user from increasing the amount of diagnostic data collection via the Settings app. The diagnostic data collected under this policy impacts the operating system and apps that are considered part of Windows and does not apply to any additional apps installed by your organization. - Diagnostic data off (not recommended). Using this value, no diagnostic data is sent from the device. This value is only supported on Enterprise, Education, and Server editions. - Send required diagnostic data. This is the minimum diagnostic data necessary to keep Windows secure, up to date, and performing as expected. Using this value disables the \"Optional diagnostic data\" control in the Settings app. - Send optional diagnostic data. Additional diagnostic data is collected that helps us to detect, diagnose and fix issues, as well as make product improvements. Required diagnostic data will always be included when you choose to send optional diagnostic data. Optional diagnostic data can also include diagnostic log files and crash dumps. Use the \"Limit Dump Collection\" and the \"Limit Diagnostic Log Collection\" policies for more granular control of what optional diagnostic data is sent. If you disable or do not configure this policy setting, the device will send required diagnostic data and the end user can choose whether to send optional diagnostic data from the Settings app. Note: The \"Configure diagnostic data opt-in settings user interface\" group policy can be used to prevent end users from changing their data collection settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "AllowTelemetry", "Items": [
        { "DisplayName": "Diagnostic data off (not recommended)", "Data": "0" },
        { "DisplayName": "Send required diagnostic data", "Data": "1" },
        { "DisplayName": "Send optional diagnostic data", "Data": "3" }
      ]
    }
  ]
},
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffApplicationImpactTelemetry",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "Windows7",
  "DisplayName": "Turn off Application Telemetry",
  "ExplainText": "The policy controls the state of the Application Telemetry engine in the system. Application Telemetry is a mechanism that tracks anonymous usage of specific Windows system components by applications. Turning Application Telemetry off by selecting \"enable\" will stop the collection of usage data. If the customer Experience Improvement program is turned off, Application Telemetry will be turned off regardless of how this policy is set. Disabling telemetry will take effect on any newly launched applications. To ensure that telemetry collection has stopped for all applications, please reboot your machine.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "AITEnable",
  "Elements": [
    { "Type": "EnabledValue", "Data": "0" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "DisableOneSettingsDownloads",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS7",
  "DisplayName": "Disable OneSettings Downloads",
  "ExplainText": "This policy setting controls whether Windows attempts to connect with the OneSettings service. If you enable this policy, Windows will not attempt to connect with the OneSettings Service. If you disable or don't configure this policy setting, Windows will periodically attempt to connect with the OneSettings service to download configuration settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableOneSettingsDownloads",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "LimitDiagnosticLogCollection",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS7",
  "DisplayName": "Limit Diagnostic Log Collection",
  "ExplainText": "This policy setting controls whether additional diagnostic logs are collected when more information is needed to troubleshoot a problem on the device. Diagnostic logs are only sent when the device has been configured to send optional diagnostic data. By enabling this policy setting, diagnostic logs will not be collected. If you disable or do not configure this policy setting, we may occasionally collect diagnostic logs if the device has been configured to send optional diagnostic data.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "LimitDiagnosticLogCollection",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "DisableDiagnosticDataViewer",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS5",
  "DisplayName": "Disable diagnostic data viewer",
  "ExplainText": "This policy setting controls whether users can enable and launch the Diagnostic Data Viewer from the Diagnostic & feedback Settings page. If you enable this policy setting, the Diagnostic Data Viewer will not be enabled in Settings page, and it will prevent the viewer from showing diagnostic data collected by Microsoft from the device. If you disable or don't configure this policy setting, the Diagnostic Data Viewer will be enabled in Settings page.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableDiagnosticDataViewer",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "ConfigureTelemetryOptInSettingsUx",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Configure diagnostic data opt-in settings user interface",
  "ExplainText": "This policy setting determines whether an end user can change diagnostic data settings in the Settings app. If you set this policy setting to \"Disable diagnostic data opt-in settings\", diagnostic data settings are disabled in the Settings app. If you don't configure this policy setting, or you set it to \"Enable diagnostic data opt-in settings\", end users can change the device diagnostic settings in the Settings app. Note: To set a limit on the amount of diagnostic data that is sent to Microsoft by your organization, use the \"Allow Diagnostic Data\" policy setting.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableTelemetryOptInSettingsUx",
  "Elements": [
    { "Type": "Enum", "ValueName": "DisableTelemetryOptInSettingsUx", "Items": [
        { "DisplayName": "Disable diagnostic data opt-in settings", "Data": "1" },
        { "DisplayName": "Enable diagnostic data opt-in setings", "Data": "0" }
      ]
    },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "LimitDumpCollection",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS7",
  "DisplayName": "Limit Dump Collection",
  "ExplainText": "This policy setting limits the type of dumps that can be collected when more information is needed to troubleshoot a problem. Dumps are only sent when the device has been configured to send optional diagnostic data. By enabling this setting, Windows Error Reporting is limited to sending kernel mini dumps and user mode triage dumps. If you disable or do not configure this policy setting, we may occasionally collect full or heap dumps if the user has opted to send optional diagnostic data.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "LimitDumpCollection",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "LimitEnhancedDiagnosticDataWindowsAnalytics",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Limit optional diagnostic data for Desktop Analytics",
  "ExplainText": "This policy setting, in combination with the \"Allow Diagnostic Data\" policy setting, enables organizations to send the minimum data required by Desktop Analytics. To enable the behavior described above, complete the following steps: 1. Enable this policy setting 2. Set the \"Allow Diagnostic Data\" policy to \"Send optional diagnostic data\" 3. Enable the \"Limit Dump Collection\" policy 4. Enable the \"Limit Diagnostic Log Collection\" policy When these policies are configured, Microsoft will collect only required diagnostic data and the events required by Desktop Analytics, which can be viewed at https://go.microsoft.com/fwlink/?linkid=2116020. If you disable or do not configure this policy setting, diagnostic data collection is determined by the \"Allow Diagnostic Data\" policy setting or by the end user from the Settings app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "LimitEnhancedDiagnosticDataWindowsAnalytics",
  "Elements": [
    { "Type": "Enum", "ValueName": "LimitEnhancedDiagnosticDataWindowsAnalytics", "Items": [
        { "DisplayName": "Enable Desktop Analytics collection", "Data": "1" },
        { "DisplayName": "Disable Desktop Analytics collection", "Data": "0" }
      ]
    },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "AllowDeviceNameInDiagnosticData",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Allow device name to be sent in Windows diagnostic data",
  "ExplainText": "This policy allows the device name to be sent to Microsoft as part of Windows diagnostic data. If you disable or do not configure this policy setting, then device name will not be sent to Microsoft as part of Windows diagnostic data.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "AllowDeviceNameInTelemetry",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "ConfigureTelemetryOptInChangeNotification",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Configure diagnostic data opt-in change notifications",
  "ExplainText": "This policy setting controls whether notifications are shown, following a change to diagnostic data opt-in settings, on first logon and when the changes occur in settings. If you set this policy setting to \"Disable diagnostic data change notifications\", diagnostic data opt-in change notifications will not appear. If you set this policy setting to \"Enable diagnostic data change notifications\" or don't configure this policy setting, diagnostic data opt-in change notifications appear at first logon and when the changes occur in Settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableTelemetryOptInChangeNotification",
  "Elements": [
    { "Type": "Enum", "ValueName": "DisableTelemetryOptInChangeNotification", "Items": [
        { "DisplayName": "Disable diagnostic data change notifications", "Data": "1" },
        { "DisplayName": "Enable diagnostic data change notifications", "Data": "0" }
      ]
    },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffProgramInventory",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "Windows7",
  "DisplayName": "Turn off Inventory Collector",
  "ExplainText": "This policy setting controls the state of the Inventory Collector. The Inventory Collector inventories applications, files, devices, and drivers on the system and sends the information to Microsoft. This information is used to help diagnose compatibility problems. If you enable this policy setting, the Inventory Collector will be turned off and data will not be sent to Microsoft. Collection of installation data through the Program Compatibility Assistant is also disabled. If you disable or do not configure this policy setting, the Inventory Collector will be turned on. Note: This policy setting has no effect if the Customer Experience Improvement Program is turned off. The Inventory Collector will be off.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableInventory",
  "Elements": []
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "DisableDeviceDelete",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS5 - At least Windows Server 2016, Windows 10 Version 1809",
  "DisplayName": "Disable deleting diagnostic data",
  "ExplainText": "This policy setting controls whether the Delete diagnostic data button is enabled in Diagnostic & feedback Settings page. If you enable this policy setting, the Delete diagnostic data button will be disabled in Settings page, preventing the deletion of diagnostic data collected by Microsoft from the device. If you disable or don't configure this policy setting, the Delete diagnostic data button will be enabled in Settings page, which allows people to erase all diagnostic data collected by Microsoft from that device.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableDeviceDelete",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Automatic Map Downloads

Disables automatic network traffic on the settings page and prevents automatic downloading or updating of map data, limiting location-related data updates.

```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"AutoUpdateEnabled", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetAutoUpdateEnabledSetting",
					   3025,
					   this);
return v5;
```
```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"UpdateOnlyOnWifi", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetDownloadOnlyOnWifiSetting",
					   3043,
					   this);
return v5;
```
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-maps  
> [privacy/assets | maps.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/maps.c)


`AutoDownloadAndUpdateMapData` & `AllowUntriggeredNetworkTrafficOnSettingsPage`:
> https://gpsearch.azurewebsites.net/#13439  
> https://gpsearch.azurewebsites.net/#13350

# Disable Website Access to Language List

"Sets the HTTP Accept Language from the Language List opt-out setting." Disables `Let websites provide locally relevant content by accessing my language list`.

Using `Set-WinAcceptLanguageFromLanguageListOptOut`
```powershell
Set-WinAcceptLanguageFromLanguageListOptOut -OptOut $True
```
```c
// $True
"powershell.exe","RegSetValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut","Type: REG_DWORD, Length: 4, Data: 1"
"powershell.exe","RegDeleteValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage",""
// $False
"powershell.exe","RegDeleteValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut",""
"powershell.exe","RegSetValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage","Type: REG_SZ, Length: 54, Data: en-US;q=0.7,en;q=0.3"
```
> https://learn.microsoft.com/en-us/powershell/module/international/set-winacceptlanguagefromlanguagelistoptout?view=windowsserver2025-ps  
> https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#181-general

# Disable Auto Maintenance

Runs updates and scans daily when your PC is idle, it helps keep your system secure and efficient without affecting performance. Theres no actual reason to disable it, as it doesn't do anything while being active, however if you've any reason for not wanting it to run the tasks while being in idle, toggle the switch.

You can see your current maintenance tasks with:
```powershell
Get-ScheduledTask | ? {$_.Settings.MaintenanceSettings}
```
`SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance` trace:
```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Activation Boundary
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : MaintenanceDisabled
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Random Delay
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Randomized
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : WakeUp
```

---

Miscellaneous notes:
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\AppModel\StateRepository" /v MaintenanceInterval /t REG_DWORD /d 0 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\Repository" /v MaintenanceInterval /t REG_DWORD /d 0 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance" /v Random Delay /t REG_DWORD /d 0 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance" /v Randomized /t REG_DWORD /d 0 /f
```

# Disable WMPlayer Telemetry

WMPlayer (Windows Media Player) sends player usage data by default, if using the "Recommended ". This option turns off the `Diagnistics and Feedback` option, use the suboptions for further configuration.

![](https://github.com/5Noxi/win-config/blob/main/privacy/images/wmplayer.png?raw=true)

Note: I gathered all registry values via the legacy WMPlayer.

| Option | Description |
| ---- | ---- |
| `Disable History` | Disables storing and displaying a list of recent/frequently played music, videos, pictures, playlists (`UsageLoggerCategories` disables "Save recently used to the Jumplist instead of frequently used"). |
| `Prevent Send User ID` | Prevents sending a unique player ID to content providers. |
| `Disable Metadata Retrieval` | Disables displaying media information from the internet and updating music files by retrieving media info from the internet. |
| `Prevent Usage Rights Download` | Prevents downloading usage rights automatically when playing or syncing a file. |
| `Prevent Auto Clock` | Prevents setting the clock on devices automatically. |
| `Max Connection Speed` | Selects the `LAN (10 Mbps or more)` connection speed, which is the highest available. |
| `Prevent Frame Dropping` | Prevents dropping frames in order to keep audio and video synchronized. |
| `Disable Video Smoothing` | Disables the `Use video smoothing` option.|
| `Disable Multicast Streams` | Disallows the player from receiving multicast streams. |
| `Enable Screensaver` | Allows the screen saver to stay enabled during playback. |
| `Prevent Internet Connection` | Disables the `Connect to the Internet (overrides other commands)` option. |

---

Registry values `setup_wm.exe` creates on first start, if unticking all options:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\AcceptedPrivacyStatement	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Setup\UserOptions\DesktopShortcut	SUCCESS	Type: REG_SZ, Length: 6, Data: no
HKCU\Software\Microsoft\MediaPlayer\Preferences\MetadataRetrieval	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SendUserGUID	SUCCESS	Type: REG_BINARY, Length: 1, Data: 00
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentAcquisition	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageTracking	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUMusic	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPictures	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUVideo	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPlaylists	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC3475	SUCCESS	Type: REG_BINARY, Length: 650, Data: 7A 01 00 00 00 00 00 00 04 00 04 00 01 02 1C 00
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC2475	SUCCESS	Type: REG_BINARY, Length: 3,056, Data: 3A 03 00 00 00 00 00 00 04 00 04 00 01 00 EF 01
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Notifications\Data\418A073AA3BC2475	SUCCESS	Type: REG_BINARY, Length: 3,064, Data: 3B 03 00 00 00 00 00 00 04 00 04 00 01 00 F1 01
```

All queried values in the `Player` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\AlwaysOnTopVTenSkin	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\EnableScreensaver	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\AutoAddMusicToLibrary	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\AutoAddUNC	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\PromptLicenseBackup	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\ForceOnline	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\StopOnFastUserSwitch2	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageLoggerCategories	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Privacy` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\MetadataRetrieval	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SendUserGUID	Type: REG_BINARY, Length: 1, Data: 00
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentAcquisition	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableLicenseRefresh	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\SilentDRMConfiguration	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\AcceptedPrivacyStatement	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\UsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\WOW6432Node\Microsoft\MediaPlayer\PREFERENCES\HME\S-1-5-21-312647486-2989864140-179540406-1001\ForceUsageTracking	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUMusic	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPictures	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUVideo	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\DisableMRUPlaylists	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Performance` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DontUseFrameInterpolation	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseFullScrMS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DVDUseVMRFSCntrls	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\IgnoreAVSync	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Scrunch\WMVideo\DXVA	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DontUseFrameInterpolation	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseFullScrMS	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\DVDUseVMRFSCntrls	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\UseVMRFullScreenCntr	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\VideoSettings\IgnoreAVSync	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Scrunch\WMVideo\DXVA	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseDefaultBufferTime	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\CustomBufferTime	Type: REG_DWORD, Length: 4, Data: 5000
HKCU\Software\Microsoft\MediaPlayer\Preferences\MaxBandwidth	Type: REG_DWORD, Length: 4, Data: 2147483647
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

All queried values in the `Network` section:
```powershell
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseUDP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseCustomUDPPort	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseMulticast	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseTCP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\UseHTTP	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\PlayerScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\HTMLViewAsk	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\LocalSAMIFilesEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebScriptCommandsEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\MediaPlayer\Preferences\WebStreamsEnabled	Type: REG_DWORD, Length: 4, Data: 1
```

---

Miscellaneous notes:

```c
// Apps > Video playback

// Save network bandwidth by playing video at lower resolution
"HKCU\Software\Microsoft\Windows\CurrentVersion\VideoSettings"; "AllowLowResolution" = 0; // DWORD. 0 = Off (default), 1 = On

// Process video automatically to enhance it (depends ony our device hardware)
"HKCU\Software\Microsoft\Windows\CurrentVersion\VideoSettings"; "EnableAutoEnhanceDuringPlayback" = 0; // DWORD, 0 = Off, 1 = On
```

# Disable Xbox Game Bar

GameDVR is a built-in gameplay capture (Xbox Game Bar) for clips/screenshots, with optional background recording.

---

"Game Bar Presence Writer is a component that is notified when a game's "presence" state (i.e. is a game running in the foreground) changes. This functionality is available in Windows 10 and later operating systems. By default, the existing Game Bar Presence Writer will set a user's Xbox Live presence state for a running game if the Xbox App is installed, the user is signed into their Xbox account, and the user has enabled Xbox Live presence to be set when they run a game on their PC. It is possible for Windows Application developers to override this default behavior with their own implementation."

> https://learn.microsoft.com/en-us/windows/win32/devnotes/gamebar-presencewriter

---

Miscellaneous notes:
```powershell
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : AppCaptureEnabled
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : CameraCaptureEnabledByDefault
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : HistoricalCaptureEnabled
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : HistoricalCaptureOnBatteryAllowed
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : HistoricalCaptureOnWirelessDisplayAllowed
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : KGLRevision
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : KGLToGCSUpdatedRevision
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : MicrophoneCaptureEnabled
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKSaveHistoricalVideo
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKTakeScreenshot
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleBroadcast
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCameraCapture
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom1
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom10
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom2
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom3
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom4
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom5
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom6
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom7
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom8
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleCustom9
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleGameBar
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleMicrophoneCapture
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleRecording
\Registry\User\S-0\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\GameDVR : VKToggleRecordingIndicator
```

# Disable PSR

"Steps Recorder, also known as Problems Steps Recorder (PSR) in Windows 7, is a Windows inbox program that records screenshots of the desktop along with the annotated steps while recording the activity on the screen. The screenshots and annotated text are saved to a file for later viewing."

It is a deprecated feature, as the banner shows:

![](https://github.com/5Noxi/win-config/blob/main/privacy/images/psr.png?raw=true)

`PSR` = Problem Steps Recorder

---

Miscellaneous notes:
```bat
takeown /f %SystemRoot%\System32\psr.exe
icacls %SystemRoot%\System32\psr.exe /grant administrators:F
ren %SystemRoot%\System32\psr.exe psr.exe.nv
```

> https://support.microsoft.com/en-gb/windows/steps-recorder-deprecation-a64888d7-8482-4965-8ce3-25fb004e975f

```json
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffUserActionRecord",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "Windows7",
  "DisplayName": "Turn off Steps Recorder",
  "ExplainText": "This policy setting controls the state of Steps Recorder. Steps Recorder keeps a record of steps taken by the user. The data generated by Steps Recorder can be used in feedback systems such as Windows Error Reporting to help developers understand and fix problems. The data includes user actions such as keyboard input and mouse input, user interface data, and screen shots. Steps Recorder includes an option to turn on and off data collection. If you enable this policy setting, Steps Recorder will be disabled. If you disable or do not configure this policy setting, Steps Recorder will be enabled.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableUAR",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Remove Product Key

"Some servicing operations require the product key to be available in the registry during Out of Box Experience (OOBE) operations. The /cpky option removes the product key from the registry to prevent this key from being stolen by malicious code. For retail installations that deploy keys, the best practice is to run this option. This option isn't required for MAK and KMS host keys, because this is the default behavior for those keys. This option is required only for other types of keys whose default behavior isn't to clear the key from the registry."

> https://learn.microsoft.com/en-us/windows-server/get-started/activation-slmgr-vbs-options#advanced-options

# Disable App Launch Tracking

`Privacy & security > General : Let Windows improve Start and search results by tracking app launches`

```bat
"Process Name","Operation","Path","Detail"
"SystemSettings.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Start_TrackProgs","Type: REG_DWORD, Length: 4, Data: 0"
```

# Disable Location Access

Disables app access to your location, locating your system will be disabled, geolocation service gets disabled.

Disable Device Sensors:
"This policy setting turns off the sensor feature for this computer. If you enable this policy setting, the sensor feature is turned off, and all programs on this computer can't use the sensor feature."
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-admx-sensors#disablesensors_1

`Privacy & security` > `Location`:
```powershell
"Process Name","Operation","Path","Detail"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\NonPackaged\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\ShowGlobalPrompts","Type: REG_DWORD, Length: 4, Data: 1"
```

---

Sensor related services:
```bat
reg add "HKLM\SYSTEM\CurrentControlSet\Services\SensorDataService" /v Start /t REG_DWORD /d 4 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\SensrSvc" /v Start /t REG_DWORD /d 4 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\SensorService" /v Start /t REG_DWORD /d 4 /f
```
Miscellaneous (ignore):
```
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\WinBio : RequireSecureSensors
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : CPU
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : ExternalResources
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : Flags
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : Importance
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : IO
\Registry\Machine\SYSTEM\ResourcePolicyStore\ResourceSets\PolicySets\LongRunningSensor : Memory
\Registry\Machine\SOFTWARE\Microsoft\Windows Defender\NIS\Consumers\IPS : DisableBmNetworkSensor
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\CurrentVersion\AutoRotation : SensorPresent
```

---

```json
{
  "File": "Sensors.admx",
  "CategoryName": "LocationAndSensors",
  "PolicyName": "DisableSensors_2",
  "NameSpace": "Microsoft.Policies.Sensors",
  "Supported": "Windows7",
  "DisplayName": "Turn off sensors",
  "ExplainText": "This policy setting turns off the sensor feature for this computer. If you enable this policy setting, the sensor feature is turned off, and all programs on this computer cannot use the sensor feature. If you disable or do not configure this policy setting, all programs on this computer can use the sensor feature.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LocationAndSensors"
  ],
  "ValueName": "DisableSensors",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Sensors.admx",
  "CategoryName": "LocationAndSensors",
  "PolicyName": "DisableLocation_2",
  "NameSpace": "Microsoft.Policies.Sensors",
  "Supported": "Windows7",
  "DisplayName": "Turn off location",
  "ExplainText": "This policy setting turns off the location feature for this computer. If you enable this policy setting, the location feature is turned off, and all programs on this computer are prevented from using location information from the location feature. If you disable or do not configure this policy setting, all programs on this computer will not be prevented from using location information from the location feature.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LocationAndSensors"
  ],
  "ValueName": "DisableLocation",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Sensors.admx",
  "CategoryName": "LocationAndSensors",
  "PolicyName": "DisableLocationScripting_2",
  "NameSpace": "Microsoft.Policies.Sensors",
  "Supported": "Windows7",
  "DisplayName": "Turn off location scripting",
  "ExplainText": "This policy setting turns off scripting for the location feature. If you enable this policy setting, scripts for the location feature will not run. If you disable or do not configure this policy setting, all location scripts will run.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LocationAndSensors"
  ],
  "ValueName": "DisableLocationScripting",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "LocationProviderAdm.admx",
  "CategoryName": "WindowsLocationProvider",
  "PolicyName": "DisableWindowsLocationProvider_1",
  "NameSpace": "Microsoft.Policies.Sensors.WindowsLocationProvider",
  "Supported": "Windows8_Or_Windows_6_3_Only",
  "DisplayName": "Turn off Windows Location Provider",
  "ExplainText": "This policy setting turns off the Windows Location Provider feature for this computer. If you enable this policy setting, the Windows Location Provider feature will be turned off, and all programs on this computer will not be able to use the Windows Location Provider feature. If you disable or do not configure this policy setting, all programs on this computer can use the Windows Location Provider feature.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LocationAndSensors"
  ],
  "ValueName": "DisableWindowsLocationProvider",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

> [privacy/assets | locationaccess-LocationApi.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/locationaccess-LocationApi.c)

# Disable Windows Insider

`AllowBuildPreview` is used up to W1 V1703, I'll still leave it. `Computer Configuration > Administrative Templates > Windows Component > Windows Update > Windows Update for Business : Manage Preview Builds` for W10+ versions.

> https://learn.microsoft.com/en-us/windows-insider/business/manage-builds

# Disable PowerShell & .NET Telemetry

PowerShell Telemetry:
"At startup, PowerShell sends diagnostic data including OS manufacturer, name, and version; PowerShell version; `POWERSHELL_DISTRIBUTION_CHANNEL`; Application Insights SDK version; approximate location from IP; command-line parameters (without values); current Execution Policy; and randomly generated GUIDs for the user and session."
```bat
setx POWERSHELL_TELEMETRY_OPTOUT 1
```
> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_telemetry?view=powershell-7.2

Disable NET Core CLI Telemetry:
"To opt out after you started the installer: close the installer, set the environment variable, and then run the installer again with that value set."
```bat
setx DOTNET_CLI_TELEMETRY_OPTOUT 1
```
> https://learn.microsoft.com/en-us/dotnet/core/tools/telemetry#how-to-opt-out

# Disable Reserved Storage

"Windows reserves `~7 GB` of disk space to ensure updates and system processes run reliably. Temporary files and updates use this reserved area first. If it's full, Windows uses normal disk space or asks for external storage. Size increases with optional features or extra languages. Unused ones can be removed to reduce it."

`dism /online /Set-ReservedStorageState /State:Disabled /NoRestart` / `Set-WindowsReservedStorageState -State Disabled` set:
```bat
dismhost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\ReserveManager\DisableDeletes	Type: REG_DWORD, Length: 4, Data: 1
```
> https://learn.microsoft.com/en-us/powershell/module/dism/set-windowsreservedstoragestate?view=windowsserver2025-ps

# Disable Biometrics 

Biometric is used for fingerprint, facial recognition, and other biometric authentication methods in Windows Hello and related security features.


```json
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{C1B650B7-6E19-4DF2-B4AE-00E5893C0487}Machine\Software\Policies\Microsoft\Biometrics\Enabled	Type: REG_DWORD, Length: 4, Data: 0
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{C1B650B7-6E19-4DF2-B4AE-00E5893C0487}Machine\Software\Policies\Microsoft\Biometrics\Credential Provider\Enabled	Type: REG_DWORD, Length: 4, Data: 0
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{C1B650B7-6E19-4DF2-B4AE-00E5893C0487}Machine\Software\Policies\Microsoft\Biometrics\Credential Provider\Domain Accounts	Type: REG_DWORD, Length: 4, Data: 0
```
```json
{
  "File": "Biometrics.admx",
  "CategoryName": "BiometricsConfiguration",
  "PolicyName": "Biometrics_EnableBio",
  "NameSpace": "Microsoft.Policies.Biometrics",
  "Supported": "Windows7",
  "DisplayName": "Allow the use of biometrics",
  "ExplainText": "This policy setting allows or prevents the Windows Biometric Service to run on this computer. If you enable or do not configure this policy setting, the Windows Biometric Service is available, and users can run applications that use biometrics on Windows. If you want to enable the ability to log on with biometrics, you must also configure the \"Allow users to log on using biometrics\" policy setting. If you disable this policy setting, the Windows Biometric Service is unavailable, and users cannot use any biometric feature in Windows. Note: Users who log on using biometrics should create a password recovery disk; this will prevent data loss in the event that someone forgets their logon credentials.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Biometrics"
  ],
  "ValueName": "Enabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Biometrics.admx",
  "CategoryName": "BiometricsConfiguration",
  "PolicyName": "Biometrics_EnableCredProv",
  "NameSpace": "Microsoft.Policies.Biometrics",
  "Supported": "Windows7",
  "DisplayName": "Allow users to log on using biometrics",
  "ExplainText": "This policy setting determines whether users can log on or elevate User Account Control (UAC) permissions using biometrics. By default, local users will be able to log on to the local computer, but the \"Allow domain users to log on using biometrics\" policy setting will need to be enabled for domain users to log on to the domain. If you enable or do not configure this policy setting, all users can log on to a local Windows-based computer and can elevate permissions with UAC using biometrics. If you disable this policy setting, biometrics cannot be used by any users to log on to a local Windows-based computer. Note: Users who log on using biometrics should create a password recovery disk; this will prevent data loss in the event that someone forgets their logon credentials.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Biometrics\\Credential Provider"
  ],
  "ValueName": "Enabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Biometrics.admx",
  "CategoryName": "BiometricsConfiguration",
  "PolicyName": "Biometrics_EnableDomainCredProv",
  "NameSpace": "Microsoft.Policies.Biometrics",
  "Supported": "Windows7",
  "DisplayName": "Allow domain users to log on using biometrics",
  "ExplainText": "This policy setting determines whether users with a domain account can log on or elevate User Account Control (UAC) permissions using biometrics. If you enable or do not configure this policy setting, Windows allows domain users to log on to a domain-joined computer using biometrics. If you disable this policy setting, Windows prevents domain users from logging on to a domain-joined computer using biometrics. Note: Prior to Windows 10, not configuring this policy setting would have prevented domain users from using biometrics to log on.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Biometrics\\Credential Provider"
  ],
  "ValueName": "Domain Accounts",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Biometrics.admx",
  "CategoryName": "FaceConfiguration",
  "PolicyName": "Face_EnhancedAntiSpoofing",
  "NameSpace": "Microsoft.Policies.Biometrics",
  "Supported": "Windows_10_0_NOARM",
  "DisplayName": "Configure enhanced anti-spoofing",
  "ExplainText": "This policy setting determines whether enhanced anti-spoofing is required for Windows Hello face authentication. If you enable this setting, Windows requires all users on managed devices to use enhanced anti-spoofing for Windows Hello face authentication. This disables Windows Hello face authentication on devices that do not support enhanced anti-spoofing. If you disable or don't configure this setting, Windows doesn't require enhanced anti-spoofing for Windows Hello face authentication. Note that enhanced anti-spoofing for Windows Hello face authentication is not required on unmanaged devices.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Biometrics\\FacialFeatures"
  ],
  "ValueName": "EnhancedAntiSpoofing",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Remote Desktop

Disables remote desktop, remote assistance, RPC traffic, and device redirection.
> https://learn.microsoft.com/en-us/windows-server/remote/remote-desktop-services/remotepc/remote-pc-connections-faq  
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-remotedesktopservices

`RemoteAssistance.admx`:  
`CreateEncryptedOnlyTickets`: Allow only Windows Vista or later connections
`fAllowFullControl` (`0`): Allow helpers to only view the computer
`LoggingEnabled`: Turn on session logging

`RPC.admx`:  
`RestrictRemoteClients` (`2`): Authenticated without exceptions

`TerminalServer.admx`:  
`fDisableCdm`: Do not allow drive redirection

```json
{
  "File": "RemoteAssistance.admx",
  "CategoryName": "RemoteAssist",
  "PolicyName": "RA_Solicit",
  "NameSpace": "Microsoft.Policies.RemoteAssistance",
  "Supported": "WindowsXP",
  "DisplayName": "Configure Solicited Remote Assistance",
  "ExplainText": "This policy setting allows you to turn on or turn off Solicited (Ask for) Remote Assistance on this computer. If you enable this policy setting, users on this computer can use email or file transfer to ask someone for help. Also, users can use instant messaging programs to allow connections to this computer, and you can configure additional Remote Assistance settings. If you disable this policy setting, users on this computer cannot use email or file transfer to ask someone for help. Also, users cannot use instant messaging programs to allow connections to this computer. If you do not configure this policy setting, users can turn on or turn off Solicited (Ask for) Remote Assistance themselves in System Properties in Control Panel. Users can also configure Remote Assistance settings. If you enable this policy setting, you have two ways to allow helpers to provide Remote Assistance: \"Allow helpers to only view the computer\" or \"Allow helpers to remotely control the computer.\" The \"Maximum ticket time\" policy setting sets a limit on the amount of time that a Remote Assistance invitation created by using email or file transfer can remain open. The \"Select the method for sending email invitations\" setting specifies which email standard to use to send Remote Assistance invitations. Depending on your email program, you can use either the Mailto standard (the invitation recipient connects through an Internet link) or the SMAPI (Simple MAPI) standard (the invitation is attached to your email message). This policy setting is not available in Windows Vista since SMAPI is the only method supported. If you enable this policy setting you should also enable appropriate firewall exceptions to allow Remote Assistance communications.",
  "KeyPath": [
    "HKLM\\Software\\policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "fAllowToGetHelp",
  "Elements": [
    { "Type": "Enum", "ValueName": "fAllowFullControl", "Items": [
        { "DisplayName": "Allow helpers to remotely control the computer", "Data": "1" },
        { "DisplayName": "Allow helpers to only view the computer", "Data": "0" }
      ]
    },
    { "Type": "Decimal", "ValueName": "MaxTicketExpiry", "MinValue": "1", "MaxValue": "99" },
    { "Type": "Enum", "ValueName": "MaxTicketExpiryUnits", "Items": [
        { "DisplayName": "Minutes", "Data": "0" },
        { "DisplayName": "Hours", "Data": "1" },
        { "DisplayName": "Days", "Data": "2" }
      ]
    },
    { "Type": "Enum", "ValueName": "fUseMailto", "Items": [
        { "DisplayName": "Simple MAPI", "Data": "0" },
        { "DisplayName": "Mailto", "Data": "1" }
      ]
    },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "TerminalServer.admx",
  "CategoryName": "TS_REDIRECTION",
  "PolicyName": "TS_CLIENT_DRIVE_M",
  "NameSpace": "Microsoft.Policies.TerminalServer",
  "Supported": "WindowsXP",
  "DisplayName": "Do not allow drive redirection",
  "ExplainText": "This policy setting specifies whether to prevent the mapping of client drives in a Remote Desktop Services session (drive redirection). By default, an RD Session Host server maps client drives automatically upon connection. Mapped drives appear in the session folder tree in File Explorer or Computer in the format <driveletter> on <computername>. You can use this policy setting to override this behavior. If you enable this policy setting, client drive redirection is not allowed in Remote Desktop Services sessions, and Clipboard file copy redirection is not allowed on computers running Windows XP, Windows Server 2003, Windows Server 2012 (and later) or Windows 8 (and later). If you disable this policy setting, client drive redirection is always allowed. In addition, Clipboard file copy redirection is always allowed if Clipboard redirection is allowed. If you do not configure this policy setting, client drive redirection and Clipboard file copy redirection are not specified at the Group Policy level.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "fDisableCdm",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "RemoteAssistance.admx",
  "CategoryName": "RemoteAssist",
  "PolicyName": "RA_EncryptedTicketOnly",
  "NameSpace": "Microsoft.Policies.RemoteAssistance",
  "Supported": "WindowsVista",
  "DisplayName": "Allow only Windows Vista or later connections",
  "ExplainText": "This policy setting enables Remote Assistance invitations to be generated with improved encryption so that only computers running this version (or later versions) of the operating system can connect. This policy setting does not affect Remote Assistance connections that are initiated by instant messaging contacts or the unsolicited Offer Remote Assistance. If you enable this policy setting, only computers running this version (or later versions) of the operating system can connect to this computer. If you disable this policy setting, computers running this version and a previous version of the operating system can connect to this computer. If you do not configure this policy setting, users can configure the setting in System Properties in the Control Panel.",
  "KeyPath": [
    "HKLM\\Software\\policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "CreateEncryptedOnlyTickets",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "RemoteAssistance.admx",
  "CategoryName": "RemoteAssist",
  "PolicyName": "RA_Logging",
  "NameSpace": "Microsoft.Policies.RemoteAssistance",
  "Supported": "WindowsVista",
  "DisplayName": "Turn on session logging",
  "ExplainText": "This policy setting allows you to turn logging on or off. Log files are located in the user's Documents folder under Remote Assistance. If you enable this policy setting, log files are generated. If you disable this policy setting, log files are not generated. If you do not configure this setting, application-based settings are used.",
  "KeyPath": [
    "HKLM\\Software\\policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "LoggingEnabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "RPC.admx",
  "CategoryName": "Rpc",
  "PolicyName": "RpcRestrictRemoteClients",
  "NameSpace": "Microsoft.Policies.RemoteProcedureCalls",
  "Supported": "WindowsXPSP2",
  "DisplayName": "Restrict Unauthenticated RPC clients",
  "ExplainText": "This policy setting controls how the RPC server runtime handles unauthenticated RPC clients connecting to RPC servers. This policy setting impacts all RPC applications. In a domain environment this policy setting should be used with caution as it can impact a wide range of functionality including group policy processing itself. Reverting a change to this policy setting can require manual intervention on each affected machine. This policy setting should never be applied to a domain controller. If you disable this policy setting, the RPC server runtime uses the value of \"Authenticated\" on Windows Client, and the value of \"None\" on Windows Server versions that support this policy setting. If you do not configure this policy setting, it remains disabled. The RPC server runtime will behave as though it was enabled with the value of \"Authenticated\" used for Windows Client and the value of \"None\" used for Server SKUs that support this policy setting. If you enable this policy setting, it directs the RPC server runtime to restrict unauthenticated RPC clients connecting to RPC servers running on a machine. A client will be considered an authenticated client if it uses a named pipe to communicate with the server or if it uses RPC Security. RPC Interfaces that have specifically requested to be accessible by unauthenticated clients may be exempt from this restriction, depending on the selected value for this policy setting. -- \"None\" allows all RPC clients to connect to RPC Servers running on the machine on which the policy setting is applied. -- \"Authenticated\" allows only authenticated RPC Clients (per the definition above) to connect to RPC Servers running on the machine on which the policy setting is applied. Exemptions are granted to interfaces that have requested them. -- \"Authenticated without exceptions\" allows only authenticated RPC Clients (per the definition above) to connect to RPC Servers running on the machine on which the policy setting is applied. No exceptions are allowed. Note: This policy setting will not be applied until the system is rebooted.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\Rpc"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "RestrictRemoteClients", "Items": [
        { "DisplayName": "None", "Data": "0" },
        { "DisplayName": "Authenticated", "Data": "1" },
        { "DisplayName": "Authenticated without exceptions", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "TerminalServer.admx",
  "CategoryName": "TS_SECURITY",
  "PolicyName": "TS_RPC_ENCRYPTION",
  "NameSpace": "Microsoft.Policies.TerminalServer",
  "Supported": "WindowsNET",
  "DisplayName": "Require secure RPC communication",
  "ExplainText": "Specifies whether a Remote Desktop Session Host server requires secure RPC communication with all clients or allows unsecured communication. You can use this setting to strengthen the security of RPC communication with clients by allowing only authenticated and encrypted requests. If the status is set to Enabled, Remote Desktop Services accepts requests from RPC clients that support secure requests, and does not allow unsecured communication with untrusted clients. If the status is set to Disabled, Remote Desktop Services always requests security for all RPC traffic. However, unsecured communication is allowed for RPC clients that do not respond to the request. If the status is set to Not Configured, unsecured communication is allowed. Note: The RPC interface is used for administering and configuring Remote Desktop Services.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "fEncryptRPCTraffic",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WirelessDisplay.admx",
  "CategoryName": "Connect",
  "PolicyName": "AllowProjectionToPC",
  "NameSpace": "Microsoft.Policies.Connect",
  "Supported": "Windows_10_0_NOSERVER - At least Windows 10",
  "DisplayName": "Don't allow this PC to be projected to",
  "ExplainText": "This policy setting allows you to turn off projection to a PC. If you turn it on, your PC isn't discoverable and can't be projected to except if the user manually launches the Wireless Display app. If you turn it off or don't configure it, your PC is discoverable and can be projected to above lock screen only. The user has an option to turn it always on or off except for manual launch, too.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Connect"
  ],
  "ValueName": "AllowProjectionToPC",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WirelessDisplay.admx",
  "CategoryName": "Connect",
  "PolicyName": "RequirePinForPairing",
  "NameSpace": "Microsoft.Policies.Connect",
  "Supported": "Windows_10_0_NOSERVER - At least Windows 10",
  "DisplayName": "Require pin for pairing",
  "ExplainText": "This policy setting allows you to require a pin for pairing. If you set this to 'Never', a pin isn't required for pairing. If you set this to 'First Time', the pairing ceremony for new devices will always require a PIN. If you set this to 'Always', all pairings will require PIN.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Connect"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "RequirePinForPairing", "Items": [
        { "DisplayName": "Never", "Data": "0" },
        { "DisplayName": "First Time", "Data": "1" },
        { "DisplayName": "Always", "Data": "2" }
      ]
    }
  ]
},
```

---

Miscellaneous notes:`
```powershell
reg add "HKLM\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services" /v fEncryptRPCTraffic /t REG_DWORD /d 1 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Terminal Server\WinStations\RDP-Tcp" /v fLogonDisabled /t REG_DWORD /d 1 /f
```
```powershell
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\WinStations : DWMFRAMEINTERVAL
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : GlassSessionId
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : NotificationTimeOut
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : SnapshotMonitors
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : TSAppCompat
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : TSUserEnabled
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\WinStations : fUseHardwareGPU
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : CaptureStackTrace
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : ContainerMode
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : debug
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugFlags
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugFlagsEx
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : Debuglevel
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : Debuglsm
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebuglsmFlags
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebuglsmLevel
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebuglsmToDebugger
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugMaxFileSize
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : Debugsessionenv
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugsessionenvFlags
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugsessionenvLevel
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugsessionenvToDebugger
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : Debugtermsrv
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtermsrvFlags
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtermsrvLevel
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtermsrvToDebugger
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugToDebugger
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugTS
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : Debugtstheme
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtsthemeFlags
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtsthemeLevel
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DebugtsthemeToDebugger
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DelayConMgrTimeout
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DelayReadyEventTimeout
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : DisableEnumUnlock
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : EnableTraceCorrelation
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : fDenyChildConnections
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : fDenyTSConnections
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : LSMBreakOnStart
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : MaxQueuedNotificationEvents
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : StartRCM
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server : TSServerDrainMode
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\WinStations : ConsoleSecurity
\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\WinStations\CONSOLE : SECURITY
```

# Deny App Access

Denies the access for everything, only leaving the microphone enabled. See JSON content below for details. Note `Deny 'User Info Access'` = prevents users from managing the ability to allow apps (not desktop apps) to access the user name, account picture, and domain information - this option doesn't get applied via the main option.

Adding the `Deny` data in `HKLM` is probably enough, but the keys also exist in `HKCU` - Windows only edits it in `HKLM`, examples:
```c
// Notifications
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\userNotificationListener\Value	Type: REG_SZ, Length: 10, Data: Deny

// Contacts
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\contacts\Value	Type: REG_SZ, Length: 10, Data: Deny

// Pictures
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\picturesLibrary\Value	Type: REG_SZ, Length: 10, Data: Deny
```
Disable app access to the microphone with (or apply it via the suboptions):
```powershell
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\microphone" /v Value /t REG_SZ /d Deny /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\microphone" /v Value /t REG_SZ /d Deny /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\microphone\NonPackaged" /v Value /t REG_SZ /d Deny /f
```
Adding the `HKLM` value is enough, changing it via the settings would:
```powershell
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\microphone\Value	Type: REG_SZ, Length: 10, Data: Deny
```

![](https://github.com/5Noxi/win-config/blob/main/privacy/images/appaccess.png?raw=true)

```json
{
  "File": "UserProfiles.admx",
  "CategoryName": "UserProfiles",
  "PolicyName": "UserInfoAccessAction",
  "NameSpace": "Microsoft.Policies.UserProfiles",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "User management of sharing user name, account picture, and domain information with apps (not desktop apps)",
  "ExplainText": "This setting prevents users from managing the ability to allow apps to access the user name, account picture, and domain information. If you enable this policy setting, sharing of user name, picture and domain information may be controlled by setting one of the following options: \"Always on\" - users will not be able to change this setting and the user's name and account picture will be shared with apps (not desktop apps). In addition apps (not desktop apps) that have the enterprise authentication capability will also be able to retrieve the user's UPN, SIP/URI, and DNS. \"Always off\" - users will not be able to change this setting and the user's name and account picture will not be shared with apps (not desktop apps). In addition apps (not desktop apps) that have the enterprise authentication capability will not be able to retrieve the user's UPN, SIP/URI, and DNS. Selecting this option may have a negative impact on certain enterprise software and/or line of business apps that depend on the domain information protected by this setting to connect with network resources. If you do not configure or disable this policy the user will have full control over this setting and can turn it off and on. Selecting this option may have a negative impact on certain enterprise software and/or line of business apps that depend on the domain information protected by this setting to connect with network resources if users choose to turn the setting off.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "AllowUserInfoAccess", "Items": [
        { "DisplayName": "Always on", "Data": "1" },
        { "DisplayName": "Always off", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessAccountInfo",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access account information",
  "ExplainText": "This policy setting specifies whether Windows apps can access account information. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access account information by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access account information and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access account information and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access account information by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessAccountInfo", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessCalendar",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access the calendar",
  "ExplainText": "This policy setting specifies whether Windows apps can access the calendar. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the calendar by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the calendar and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the calendar and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the calendar by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessCalendar", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessCallHistory",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access call history",
  "ExplainText": "This policy setting specifies whether Windows apps can access call history. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access call history by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the call history and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the call history and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the call history by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessCallHistory", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessCamera",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access the camera",
  "ExplainText": "This policy setting specifies whether Windows apps can access the camera. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the camera by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the camera and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the camera and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the camera by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessCamera", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessContacts",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access contacts",
  "ExplainText": "This policy setting specifies whether Windows apps can access contacts. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access contacts by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access contacts and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access contacts and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access contacts by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessContacts", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessEmail",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access email",
  "ExplainText": "This policy setting specifies whether Windows apps can access email. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access email by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access email and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access email and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access email by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessEmail", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessGraphicsCaptureProgrammatic",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps take screenshots of various windows or displays",
  "ExplainText": "This policy setting specifies whether Windows apps can take screenshots of various windows or displays. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can take screenshots of various windows or displays by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to take screenshots of various windows or displays and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to take screenshots of various windows or displays and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can take screenshots of various windows or displays by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessGraphicsCaptureProgrammatic", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessGraphicsCaptureWithoutBorder",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps turn off the screenshot border",
  "ExplainText": "This policy setting specifies whether Windows apps can turn off the screenshot border. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can turn off the screenshot border by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to turn off the screenshot border and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to turn off the screenshot border and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can turn off the screenshot border by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessGraphicsCaptureWithoutBorder", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessHumanPresence",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access presence sensing",
  "ExplainText": "This policy setting specifies whether Windows apps can access presence sensing. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access presence sensing by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access presence sensing and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access presence sensing and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access presence sensing by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessHumanPresence", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessLocation",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access location",
  "ExplainText": "This policy setting specifies whether Windows apps can access location. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access location by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access location and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access location and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access location by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessLocation", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessMessaging",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access messaging",
  "ExplainText": "This policy setting specifies whether Windows apps can read or send messages (text or MMS). You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can read or send messages by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps can read or send messages and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps cannot read or send messages and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can read or send messages by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessMessaging", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessMicrophone",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access the microphone",
  "ExplainText": "This policy setting specifies whether Windows apps can access the microphone. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the microphone by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the microphone and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the microphone and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the microphone by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessMicrophone", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessMotion",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access motion",
  "ExplainText": "This policy setting specifies whether Windows apps can access motion data. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access motion data by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access motion data and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access motion data and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access motion data by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessMotion", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessNotifications",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access notifications",
  "ExplainText": "This policy setting specifies whether Windows apps can access notifications. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access notifications by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access notifications and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access notifications and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access notifications by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessNotifications", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessPhone",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps make phone calls",
  "ExplainText": "This policy setting specifies whether Windows apps can make phone calls. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can make phone calls by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to make phone calls and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to make phone calls and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can make phone calls by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessPhone", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessRadios",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps control radios",
  "ExplainText": "This policy setting specifies whether Windows apps have access to control radios. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps have access to control radios by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps will have access to control radios and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps will not have access to control radios and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps have access to control radios by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessRadios", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsSyncWithDevices",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps communicate with unpaired devices",
  "ExplainText": "This policy setting specifies whether Windows apps can communicate with unpaired wireless devices. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can communicate with unpaired wireless devices by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to communicate with unpaired wireless devices and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to communicate with unpaired wireless devices and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can communicate with unpaired wireless devices by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsSyncWithDevices", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessTasks",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access Tasks",
  "ExplainText": "This policy setting specifies whether Windows apps can access tasks. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access tasks by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access tasks and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access tasks and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access tasks by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessTasks", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessTrustedDevices",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access trusted devices",
  "ExplainText": "This policy setting specifies whether Windows apps can access trusted devices. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access trusted devices by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access trusted devices and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access trusted devices and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access trusted devices by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessTrustedDevices", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsRunInBackground",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps run in the background",
  "ExplainText": "This policy setting specifies whether Windows apps can run in the background. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to run in the background and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to run in the background and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsRunInBackground", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsGetDiagnosticInfo",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0_RS2 - At least Windows Server 2016, Windows 10 Version 1703",
  "DisplayName": "Let Windows apps access diagnostic information about other apps",
  "ExplainText": "This policy setting specifies whether Windows apps can get diagnostic information about other Windows apps, including user name. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can get diagnostic information about other apps using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to get diagnostic information about other apps and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to get diagnostic information about other apps and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can get diagnostic information about other apps by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsGetDiagnosticInfo", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessGazeInput",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access an eye tracker device",
  "ExplainText": "This policy setting specifies whether Windows apps can access the eye tracker. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the eye tracker by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the eye tracker and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the eye tracker and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the eye tracker by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessGazeInput", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsActivateWithVoice",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps activate with voice",
  "ExplainText": "This policy setting specifies whether Windows apps can be activated by voice. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can be activated with a voice keyword by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to be activated with a voice keyword and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to be activated with a voice keyword and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can be activated with a voice keyword by using Settings > Privacy on the device. This policy is applied to Windows apps and Cortana.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsActivateWithVoice", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsActivateWithVoiceAboveLock",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps activate with voice while the system is locked",
  "ExplainText": "This policy setting specifies whether Windows apps can be activated by voice while the system is locked. If you choose the \"User is in control\" option, employees in your organization can decide whether users can interact with applications using speech while the system is locked by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, users can interact with applications using speech while the system is locked and employees in your organization cannot change it. If you choose the \"Force Deny\" option, users cannot interact with applications using speech while the system is locked and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether users can interact with applications using speech while the system is locked by using Settings > Privacy on the device. This policy is applied to Windows apps and Cortana. It takes precedence of the \u201cAllow Cortana above lock\u201d policy. This policy is applicable only when \u201cAllow voice activation\u201d policy is configured to allow applications to be activated with voice.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsActivateWithVoiceAboveLock", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessBackgroundSpatialPerception",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access user movements while running in the background",
  "ExplainText": "This policy setting specifies whether Windows apps can access the movement of the user's head, hands, motion controllers, and other tracked objects, while the apps are running in the background. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the user's movements while the apps are running in the background by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access user movements while the apps are running in the background and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access user movements while the apps are running in the background and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the user's movements while the apps are running in the background by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessBackgroundSpatialPerception", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
```

# Disable Startup ETS

"The AutoLogger event tracing session records events that occur early in the operating system boot process. Applications and device drivers can use the AutoLogger session to capture traces before the user logs in. Note that some device drivers, such as disk device drivers, are not loaded at the time the AutoLogger session begins."

See your current running ETS via `Performance Monitor > Data Collector Sets > Startup Event Trace Sessions`.

Logs are saved in:
```c
C:\WINDOWS\system32\Logfiles\WMI

// C:\Windows\System32\drivers\DriverData\LogFiles\WMI
// C:\PerfLogs\Admin
```

Removing all autologgers will cause issues, therefore it's not recommended to remove all of them.

| Value | Type | Description | 
|-------|------|-------------|
| **BufferSize** | **REG_DWORD** | The size of each buffer, in kilobytes. Should be less than one megabyte. ETW uses the size of physical memory to calculate this value.|
| **ClockType** | **REG_DWORD** | The timer to use when logging the time stamp for each event. <br> - 1 = Performance counter value (high resolution)<br> - 2 = System timer<br> - 3 = CPU cycle counter <br> For a description of each clock type, see the **ClientContext** member of [WNODE_HEADER](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/wnode-header.md).<br> The default value is 1 (performance counter value) on Windows Vista and later. Prior to Windows Vista, the default value is 2 (system timer). | 
| **DisableRealtimePersistence** | **REG_DWORD** | To disable real time persistence, set this value to 1. The default is 0 (enabled) for real time sessions.<br> If real time persistence is enabled, real-time events that were not delivered by the time the computer was shutdown will be persisted. The events will then be delivered to the consumer the next time the consumer connects to the session. |
| **FileCounter** | **REG_DWORD** | Do not set or modify this value. This value is the serial number used to increment the log file name if **FileMax** is specified. If the value is not valid, 1 will be assumed.|
| **FileName** | **REG_SZ** | The fully qualified path of the log file. The path to this file must exist. The log file is a sequential log file. The path is limited to 1024 characters.<br> If **FileName** is not specified, events are written to `%SystemRoot%\System32\LogFiles\WMI\\<sessionname>.etl`. |
| **FileMax** | **REG_DWORD** | The maximum number of instances of the log file that ETW creates. If the log file specified in **FileName** exists, ETW appends the **FileCounter** value to the file name. For example, if the default log file name is used, the form is `%SystemRoot%\System32\LogFiles\WMI\\<sessionname>.etl.NNNN`. <br> The first time the computer is started, the file name is `<sessionname>.etl.0001`, the second time the file name is `<sessionname>.etl.0002`, and so on. If **FileMax** is 3, on the fourth restart of the computer, ETW resets the counter to 1 and overwrites `<sessionname>.etl.0001`, if it exists.<br> The maximum number of instances of the log file that are supported is 16.<br> Do not use this feature with the [EVENT_TRACE_FILE_MODE_NEWFILE](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md) log file mode.|
| **FlushTimer** | **REG_DWORD** | How often, in seconds, the trace buffers are forcibly flushed. The minimum flush time is 1 second. This forced flush is in addition to the automatic flush that occurs when a buffer is full and when the trace session stops. <br> For the case of a real-time logger, a value of zero (the default value) means that the flush time will be set to 1 second. A real-time logger is when **LogFileMode** is set to **EVENT_TRACE_REAL_TIME_MODE**.<br> The default value is 0. By default, buffers are flushed only when they are full. |
| **Guid** | **REG_SZ** | A string that contains a GUID that uniquely identifies the session. This value is required. | 
| **LogFileMode** | **REG_DWORD** | Specify one or more log modes. For possible values, see [Logging Mode Constants](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md). The default is **EVENT_TRACE_FILE_MODE_SEQUENTIAL**. Instead of writing to a log file, you can specify either **EVENT_TRACE_BUFFERING_MODE** or **EVENT_TRACE_REAL_TIME_MODE**.<br> Specifying **EVENT_TRACE_BUFFERING_MODE** avoids the cost of flushing the contents of the session to disk when the file system becomes available. <br> Note that using **EVENT_TRACE_BUFFERING_MODE** will cause the system to ignore the **MaximumBuffers** value, as the buffer size is instead the product of **MinimumBuffers** and **BufferSize**.<br> AutoLogger sessions do not support the **EVENT_TRACE_FILE_MODE_NEWFILE** logging mode.<br> If **EVENT_TRACE_FILE_MODE_APPEND** is specified, **BufferSize** must be explicitly provided and must be the same in both the logger and the file being appended.|
| **MaxFileSize** | **REG_DWORD** | The maximum file size of the log file, in megabytes. The session is closed when the maximum size is reached, unless you are in circular log file mode. To specify no limit, set value to 0. The default is 100 MB, if not set. The behavior that occurs when the maximum file size is reached depends on the value of **LogFileMode**.|
| **MaximumBuffers** | **REG_DWORD** | The maximum number of buffers to allocate. Typically, this value is the minimum number of buffers plus twenty. ETW uses the buffer size and the size of physical memory to calculate this value. This value must be greater than or equal to the value for **MinimumBuffers**.|
| **MinimumBuffers** | **REG_DWORD** | The minimum number of buffers to allocate at startup. The minimum number of buffers that you can specify is two buffers per processor. For example, on a single processor computer, the minimum number of buffers is two.|
| **Start** | **REG_DWORD** | To have the AutoLogger session start the next time the computer is restarted, set this value to 1; otherwise, set this value to 0.|
| **Status** | **REG_DWORD** | The startup status of the AutoLogger. If the AutoLogger failed to start, the value of this key is the appropriate Win32 error code. If the AutoLogger successfully started, the value of this key is **ERROR_SUCCESS** (0).|
| **Boot** | **REG_DWORD** | This feature should not be used outside of debugging scenarios.<br> If this registry key is set to 1, the autologger will be started earlier than normal during kernel initialization, allowing it to capture events during the initialization of many important kernel subsystems. However, enabling this option has a negative impact on boot times and imposes additional restrictions on the autologger. If this feature is enabled, the autologger session GUID must be populated, and many other autologger settings may not work. <br> This key is supported on Windows Server 2022 and later. |

> https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/configuring-and-starting-an-autologger-session.md

# Disable Inking & Typing Personalization

Used for better suggestions by creating a custom dictionary using your typing history and handwriting patterns. Disables autocorrection of misspelled words, highlight of misspelled words, and typing insights - would use AI to suggest words, autocorrect spelling mistakes etc. (`Privacy & security > Inking & typing personalization` & `Time & Language > Typing`).

```
\Registry\Machine\SOFTWARE\Microsoft\INPUT\TIPC : Enabled
\Registry\User\.Default\SOFTWARE\Microsoft\INPUT\TIPC : Enabled
\Registry\User\S-ID\SOFTWARE\Microsoft\INPUT\TIPC : Enabled
```

![](https://github.com/5Noxi/win-config/blob/main/privacy/images/inking.png?raw=true)

```json
{
  "File": "TextInput.admx",
  "CategoryName": "TextInput",
  "PolicyName": "AllowLinguisticDataCollection",
  "NameSpace": "Microsoft.Policies.TextInput",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Improve inking and typing recognition",
  "ExplainText": "This policy setting controls the ability to send inking and typing data to Microsoft to improve the language recognition and suggestion capabilities of apps and services running on Windows.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\TextInput"
  ],
  "ValueName": "AllowLinguisticDataCollection",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsInkWorkspace.admx",
  "CategoryName": "WindowsInkWorkspace",
  "PolicyName": "AllowSuggestedAppsInWindowsInkWorkspace",
  "NameSpace": "Microsoft.Policies.WindowsInkWorkspace",
  "Supported": "WIN10_RS1",
  "DisplayName": "Allow suggested apps in Windows Ink Workspace",
  "ExplainText": "Allow suggested apps in Windows Ink Workspace",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\WindowsInkWorkspace"
  ],
  "ValueName": "AllowSuggestedAppsInWindowsInkWorkspace",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsInkWorkspace.admx",
  "CategoryName": "WindowsInkWorkspace",
  "PolicyName": "AllowWindowsInkWorkspace",
  "NameSpace": "Microsoft.Policies.WindowsInkWorkspace",
  "Supported": "WIN10_RS1",
  "DisplayName": "Allow Windows Ink Workspace",
  "ExplainText": "Allow Windows Ink Workspace",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\WindowsInkWorkspace"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "AllowWindowsInkWorkspace", "Items": [
        { "DisplayName": "Disabled", "Data": "0" },
        { "DisplayName": "On, but disallow access above lock", "Data": "1" },
        { "DisplayName": "On", "Data": "2" }
      ]
    }
  ]
},
```

# Disable Online Speech Recognition

`HasAccepted` disables online speech recognition, voice input to apps like Cortana, and data upload to Microsoft. `AllowSpeechModelUpdate` blocks automatic updates of speech recognition and synthesis models. I found`DisableSpeechInput` randomly while looking for `HasAccepted`, related to mixed reality environments.
> https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#bkmk-priv-speech  
> [privacy/assets | locationaccess-LocationApi.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/locationaccess-LocationApi.c)

# Disable Microsoft Copilot

"Microsoft introduced Windows Copilot in May 2023. It became available in Windows 11 starting with build 23493 (Dev), 22631.2129 (Beta), and 25982 (Canary). A public preview began rolling out on September 26, 2023, with build 22621.2361 (Windows 11 22H2 KB5030310). It adds integrated AI features to assist with tasks like summarizing web content, writing, and generating images. Windows Copilot appears as a sidebar docked to the right and runs alongside open apps. In Windows 10, Copilot is available in build 19045.3754 for eligible devices in the Release Preview Channel running version 22H2. Users must enable "Get the latest updates as soon as they're available" and check for updates. The rollout is phased via Controlled Feature Rollout (CFR). Windows 10 Pro devices managed by organizations, and all Enterprise or Education editions, are excluded from the initial rollout. Copilot requires signing in with a Microsoft account (MSA) or Azure Active Directory (Entra ID). Users with local accounts can use Copilot up to ten times before sign-in is enforced."

`CopilotDisabledReason`:
```c
ValueW = RegGetValueW(
    HKEY_CURRENT_USER,
    L"SOFTWARE\\Microsoft\\Windows\\Shell\\Copilot",
    L"CopilotDisabledReason",
    2u, // REG_SZ
    0LL,
    pvData,
    pcbData);

v16 = L"FailedToGetReason"; // if value is missing
```

```powershell
reg add "HKCU\SOFTWARE\Microsoft\Windows\Shell\Copilot" /v CopilotDisabledReason /t REG_SZ /d "" /f
```
```json
{
  "File": "WindowsCopilot.admx",
  "CategoryName": "WindowsCopilot",
  "PolicyName": "TurnOffWindowsCopilot",
  "NameSpace": "Microsoft.Policies.WindowsCopilot",
  "Supported": "Windows_11_0_NOSERVER_ENTERPRISE_EDUCATION_PRO_SANDBOX",
  "DisplayName": "Turn off Windows Copilot",
  "ExplainText": "This policy setting allows you to turn off Windows Copilot. If you enable this policy setting, users will not be able to use Copilot. The Copilot icon will not appear on the taskbar either. If you disable or do not configure this policy setting, users will be able to use Copilot when it's available to them.",
  "KeyPath": [
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsCopilot"
  ],
  "ValueName": "TurnOffWindowsCopilot",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Recall

"Allows you to control whether Windows saves snapshots of the screen and analyzes the user's activity on their device. If you enable this policy setting, Windows will not be able to save snapshots and users won't be able to search for or browse through their historical device activity using Recall. If you disable or do not configure this policy setting, Windows will save snapshots of the screen and users will be able to search for or browse through a timeline of their past activities using Recall." (`WindowsCopilot.admx`)

```json
{
  "File": "WindowsCopilot.admx",
  "CategoryName": "WindowsAI",
  "PolicyName": "DisableAIDataAnalysis",
  "NameSpace": "Microsoft.Policies.WindowsCopilot",
  "Supported": "Windows_11_0_NOSERVER_ENTERPRISE_EDUCATION_PRO_SANDBOX",
  "DisplayName": "Turn off Saving Snapshots for Windows",
  "ExplainText": "This policy setting allows you to control whether Windows saves snapshots of the screen and analyzes the user's activity on their device. If you enable this policy setting, Windows will not be able to save snapshots and users won't be able to search for or browse through their historical device activity using Recall. If you disable or do not configure this policy setting, Windows will save snapshots of the screen and users will be able to search for or browse through a timeline of their past activities using Recall.",
  "KeyPath": [
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsAI"
  ],
  "ValueName": "DisableAIDataAnalysis",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

---

Disables generative fill, cocreator & image creator in paint:
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Paint" /v DisableGenerativeFill /t REG_DWORD /d 1 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Paint" /v DisableCocreator /t REG_DWORD /d 1 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Paint" /v DisableImageCreator /t REG_DWORD /d 1 /f
```

# Disable Camera

Disallows the use of a camera on your system, by denying access via `LetAppsAccessCamera`/`AllowCamera`/services (and app permission).

| Service | Description |
| --- | --- |
| `FrameServer` | Enables multiple clients to access video frames from camera devices. |
| `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. |

`Disable Lock Screen Camera`:  
"Disables the lock screen camera toggle switch in PC Settings and prevents a camera from being invoked on the lock screen.By default, users can enable invocation of an available camera on the lock screen.If you enable this setting, users will no longer be able to enable or disable lock screen camera access in PC Settings, and the camera cannot be invoked on the lock screen." (`ControlPanelDisplay.admx`)

> https://support.microsoft.com/en-us/windows/manage-cameras-with-camera-settings-in-windows-11-97997ed5-bb98-47b6-a13d-964106997757

```json
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsAccessCamera",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Let Windows apps access the camera",
  "ExplainText": "This policy setting specifies whether Windows apps can access the camera. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can access the camera by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to access the camera and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to access the camera and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can access the camera by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsAccessCamera", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_NoLockScreenCamera",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows_6_3",
  "DisplayName": "Prevent enabling lock screen camera",
  "ExplainText": "Disables the lock screen camera toggle switch in PC Settings and prevents a camera from being invoked on the lock screen. By default, users can enable invocation of an available camera on the lock screen. If you enable this setting, users will no longer be able to enable or disable lock screen camera access in PC Settings, and the camera cannot be invoked on the lock screen.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "ValueName": "NoLockScreenCamera",
  "Elements": []
},
{
  "File": "Camera.admx",
  "CategoryName": "L_Camera_GroupPolicyCategory",
  "PolicyName": "L_AllowCamera",
  "NameSpace": "Microsoft.Policies.Camera",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Allow Use of Camera",
  "ExplainText": "This policy setting allow the use of Camera devices on the machine. If you enable or do not configure this policy setting, Camera devices will be enabled. If you disable this property setting, Camera devices will be disabled.",
  "KeyPath": [
    "HKLM\\software\\Policies\\Microsoft\\Camera"
  ],
  "ValueName": "AllowCamera",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Suggestions/Tips/Tricks

Disables all kind of suggestions: in start, text suggestions (multilingual...), in the timeline, content... It sets all `SubscribedContent-xxxxxEnabled` to `0` & removes the subkeys of `ID\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager`. It's recommended to do a backup before running it.

Disable edge related suggestions with (search suggestions in address bar):
```bat
reg add "HKLM\SOFTWARE\Policies\Microsoft\Edge" /v SearchSuggestEnabled /t REG_DWORD /d 0 /f
reg add "HKLM\SOFTWARE\Policies\Microsoft\Edge" /v LocalProvidersEnabled /t REG_DWORD /d 0 /f
reg add "HKLM\Software\Policies\Microsoft\MicrosoftEdge\SearchScopes" /v ShowSearchSuggestionsGlobal /t REG_DWORD /d 0 /f
```
Disable phone link suggestions:
```bat
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Mobility" /v OptedIn /t REG_DWORD /d 0 /f
```

```json
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableThirdPartySuggestions",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Do not suggest third-party content in Windows spotlight",
  "ExplainText": "If you enable this policy, Windows spotlight features like lock screen spotlight, suggested apps in Start menu or Windows tips will no longer suggest apps and content from third-party software publishers. Users may still see suggestions and tips to make them more productive with Microsoft features and apps. If you disable or do not configure this policy, Windows spotlight features may suggest apps and content from third-party software publishers in addition to Microsoft apps and content.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableThirdPartySuggestions",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableConsumerAccountStateContent",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_RS7 - At least Windows Server 2016, Windows 10 Version 1909",
  "DisplayName": "Turn off cloud consumer account state content",
  "ExplainText": "This policy setting lets you turn off cloud consumer account state content in all Windows experiences. If you enable this policy, Windows experiences that use the cloud consumer account state content client component, will instead present the default fallback content. If you disable or do not configure this policy, Windows experiences will be able to use cloud consumer account state content.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableConsumerAccountStateContent",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ControlPanel.admx",
  "CategoryName": "ControlPanel",
  "PolicyName": "AllowOnlineTips",
  "NameSpace": "Microsoft.Policies.ControlPanel",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Allow Online Tips",
  "ExplainText": "Enables or disables the retrieval of online tips and help for the Settings app. If disabled, Settings will not contact Microsoft content services to retrieve tips and help content.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "Elements": [
    { "Type": "Boolean", "ValueName": "AllowOnlineTips", "TrueValue": "1", "FalseValue": "0" }
  ]
},
{
  "File": "StartMenu.admx",
  "CategoryName": "StartMenu",
  "PolicyName": "HideRecommendedPersonalizedSites",
  "NameSpace": "Microsoft.Policies.StartMenu",
  "Supported": "Windows_11_0_SE",
  "DisplayName": "Remove Personalized Website Recommendations from the Recommended section in the Start Menu",
  "ExplainText": "Remove Personalized Website Recommendations from the Recommended section in the Start Menu",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "HideRecommendedPersonalizedSites",
  "Elements": []
},
{
  "File": "StartMenu.admx",
  "CategoryName": "StartMenu",
  "PolicyName": "HideRecommendedSection",
  "NameSpace": "Microsoft.Policies.StartMenu",
  "Supported": "Windows_11_0_SE",
  "DisplayName": "Remove Recommended section from Start Menu",
  "ExplainText": "This policy allows you to prevent the Start Menu from displaying a list of recommended applications and files. If you enable this policy setting, the Start Menu will no longer show the section containing a list of recommended files and apps.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "HideRecommendedSection",
  "Elements": []
},
{
  "File": "WindowsExplorer.admx",
  "CategoryName": "WindowsExplorer",
  "PolicyName": "DisableSearchBoxSuggestions",
  "NameSpace": "Microsoft.Policies.WindowsExplorer",
  "Supported": "Windows7",
  "DisplayName": "Turn off display of recent search entries in the File Explorer search box",
  "ExplainText": "Disables suggesting recent queries for the Search Box and prevents entries into the Search Box from being stored in the registry for future references. File Explorer shows suggestion pop-ups as users type into the Search Box. These suggestions are based on their past entries into the Search Box. Note: If you enable this policy, File Explorer will not show suggestion pop-ups as users type into the Search Box, and it will not store Search Box entries into the registry for future references. If the user types a property, values that match this property will be shown but no data will be saved in the registry or re-shown on subsequent uses of the search box.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "DisableSearchBoxSuggestions",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

---

Miscellaneous notes:
```powershell
for /f "skip=2 tokens=1" %%N in ('reg query "HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager" 2^>nul') do (
    echo %%N | findstr /R "SubscribedContent-[0-9]*Enabled" >nul && (
        reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager" /v "%%~nxN" /t REG_DWORD /d 0 /f
    )
)

powershell -command "Remove-Item -Path 'HKCU:\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\*' -Recurse"
```

# Disable Synchronization

Disables all kind of synchronization.

How the middle block works (`SettingSync.admx`):
```
KeyPath: Software\Policies\Microsoft\Windows\SettingSync,
KeyName: DisableSettingSync,

 ValueName: DisableSettingSyncUserOverride,
 FalseValue: 1,
 TrueValue: 0,

Value:  2,
Type:  EnabledValue
Value:  0,
Type:  DisabledValue
```

`DisableSyncOnPaidNetwork`: "Do not sync on metered connections"
> https://support.microsoft.com/en-us/windows/windows-backup-settings-catalog-deebcba2-5bc0-4e63-279a-329926955708#id0ebd=windows_11
> https://gpsearch.azurewebsites.net/#7999

```json
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableSyncOnPaidNetwork",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync on metered connections",
  "ExplainText": "Prevent syncing to and from this PC when on metered Internet connections. This turns off and disables \"sync your settings on metered connections\" switch on the \"sync your settings\" page in PC Settings. If you enable this policy setting, syncing on metered connections will be turned off, and no syncing will take place when this PC is on a metered connection. If you do not set or disable this setting, syncing on metered connections is configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableSyncOnPaidNetwork",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableAppSyncSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows_6_3",
  "DisplayName": "Do not sync Apps",
  "ExplainText": "Prevent the \"AppSync\" group from syncing to and from this PC. This turns off and disables the \"AppSync\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"AppSync\" group will not be synced. Use the option \"Allow users to turn app syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"AppSync\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableAppSyncSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableAppSyncSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableApplicationSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync app settings",
  "ExplainText": "Prevent the \"app settings\" group from syncing to and from this PC. This turns off and disables the \"app settings\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"app settings\" group will not be synced. Use the option \"Allow users to turn app settings syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"app settings\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableApplicationSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableApplicationSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableCredentialsSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync passwords",
  "ExplainText": "Prevent the \"passwords\" group from syncing to and from this PC. This turns off and disables the \"passwords\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"passwords\" group will not be synced. Use the option \"Allow users to turn passwords syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"passwords\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableCredentialsSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableCredentialsSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisablePersonalizationSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync personalize",
  "ExplainText": "Prevent the \"personalize\" group from syncing to and from this PC. This turns off and disables the \"personalize\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"personalize\" group will not be synced. Use the option \"Allow users to turn personalize syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"personalize\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisablePersonalizationSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisablePersonalizationSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableDesktopThemeSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync desktop personalization",
  "ExplainText": "Prevent the \"desktop personalization\" group from syncing to and from this PC. This turns off and disables the \"desktop personalization\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"desktop personalization\" group will not be synced. Use the option \"Allow users to turn desktop personalization syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"desktop personalization\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableDesktopThemeSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableDesktopThemeSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync",
  "ExplainText": "Prevent syncing to and from this PC. This turns off and disables the \"sync your settings\" switch on the \"sync your settings\" page in PC Settings. If you enable this policy setting, \"sync your settings\" will be turned off, and none of the \"sync your setting\" groups will be synced on this PC. Use the option \"Allow users to turn syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, \"sync your settings\" is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableStartLayoutSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows_6_3",
  "DisplayName": "Do not sync start settings",
  "ExplainText": "Prevent the \"Start layout\" group from syncing to and from this PC. This turns off and disables the \"Start layout\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"Start layout\" group will not be synced. Use the option \"Allow users to turn start syncing on\" so that syncing is turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"Start layout\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableStartLayoutSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableStartLayoutSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableWebBrowserSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync browser settings",
  "ExplainText": "Prevent the \"browser\" group from syncing to and from this PC. This turns off and disables the \"browser\" group on the \"sync your settings\" page in PC settings. The \"browser\" group contains settings and info like history and favorites. If you enable this policy setting, the \"browser\" group, including info like history and favorites, will not be synced. Use the option \"Allow users to turn browser syncing on\" so that syncing is turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"browser\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableWebBrowserSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableWebBrowserSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SettingSync.admx",
  "CategoryName": "SettingSync",
  "PolicyName": "DisableWindowsSettingSync",
  "NameSpace": "Microsoft.Policies.SettingSync",
  "Supported": "Windows8",
  "DisplayName": "Do not sync other Windows settings",
  "ExplainText": "Prevent the \"Other Windows settings\" group from syncing to and from this PC. This turns off and disables the \"Other Windows settings\" group on the \"sync your settings\" page in PC settings. If you enable this policy setting, the \"Other Windows settings\" group will not be synced. Use the option \"Allow users to turn other Windows settings syncing on\" so that syncing it turned off by default but not disabled. If you do not set or disable this setting, syncing of the \"Other Windows settings\" group is on by default and configurable by the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\SettingSync"
  ],
  "ValueName": "DisableWindowsSettingSync",
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisableWindowsSettingSyncUserOverride", "TrueValue": "0", "FalseValue": "1" },
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Activity History

`EnableActivityFeed` enables or disables publishing and syncing of activities across devices. `PublishUserActivities` allows or blocks local publishing of user activities. `UploadUserActivities` allows or blocks uploading of user activities to the cloud, deletion is not affected.

`OSPolicy.admx`:
```bat
HKLM\Software\Policies\Microsoft\Windows\System
EnableActivityFeed = 0 (Disabled), 1 (Enabled)
PublishUserActivities = 0 (Disabled), 1 (Enabled)
UploadUserActivities = 0 (Disabled), 1 (Enabled)
```


# Disable Cross-Device Experiences

Disables Cross-Device experiences (allows you to use `Share Across Devices`/`Nearby Sharing` functionalities) & share accross devices. With `Share across devices`, you can continue app experiences on other devices connected to your account.
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-admx-grouppolicy#enablecdp

```c
L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"BluetoothLastDisabledNearShare",

L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"WifiLastDisabledNearShare",
```

> [privacy/assets | crossdev-SharedExperiencesSingleton.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/crossdev-SharedExperiencesSingleton.c)

```json
{
  "File": "GroupPolicy.admx",
  "CategoryName": "PolicyPolicies",
  "PolicyName": "EnableCDP",
  "NameSpace": "Microsoft.Policies.GroupPolicy",
  "Supported": "Windows_10_0",
  "DisplayName": "Continue experiences on this device",
  "ExplainText": "This policy setting determines whether the Windows device is allowed to participate in cross-device experiences (continue experiences). If you enable this policy setting, the Windows device is discoverable by other Windows devices that belong to the same user, and can participate in cross-device experiences. If you disable this policy setting, the Windows device is not discoverable by other devices, and cannot participate in cross-device experiences. If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "EnableCdp",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Phone Linking

"This policy allows IT admins to turn off the ability to Link a Phone with a PC to continue reading, emailing and other tasks that requires linking between Phone and PC.If you enable this policy setting, the Windows device will be able to enroll in Phone-PC linking functionality and participate in Continue on PC experiences.If you disable this policy setting, the Windows device is not allowed to be linked to Phones, will remove itself from the device list of any linked Phones, and cannot participate in Continue on PC experiences.If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot."

> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-connectivity#allowphonepclinking

```json
{
  "File": "GroupPolicy.admx",
  "CategoryName": "PolicyPolicies",
  "PolicyName": "EnableMMX",
  "NameSpace": "Microsoft.Policies.GroupPolicy",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Phone-PC linking on this device",
  "ExplainText": "This policy allows IT admins to turn off the ability to Link a Phone with a PC to continue reading, emailing and other tasks that requires linking between Phone and PC. If you enable this policy setting, the Windows device will be able to enroll in Phone-PC linking functionality and participate in Continue on PC experiences. If you disable this policy setting, the Windows device is not allowed to be linked to Phones, will remove itself from the device list of any linked Phones, and cannot participate in Continue on PC experiences. If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "EnableMmx",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable File History

"File History automatically backs up versions of files in your user folders (Documents, Music, Pictures, Videos, Desktop) and offline OneDrive. It tracks changes via the NTFS change journal (fast, low overhead) and saves only changed files. You must choose a backup target (external drive or network share). If that target is unavailable, it caches copies locally and syncs them when the target returns. You can browse and restore any version or recover lost/deleted files."

```json
{
  "File": "FileHistory.admx",
  "CategoryName": "FileHistory",
  "PolicyName": "DisableFileHistory",
  "NameSpace": "Microsoft.Policies.FileHistory",
  "Supported": "Windows8",
  "DisplayName": "Turn off File History",
  "ExplainText": "This policy setting allows you to turn off File History. If you enable this policy setting, File History cannot be activated to create regular, automatic backups. If you disable or do not configure this policy setting, File History can be activated to create regular, automatic backups.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\FileHistory"
  ],
  "ValueName": "Disabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable MDM Enrollment

`DisableRegistration`:  
"This policy setting specifies whether Mobile Device Management (MDM) Enrollment is allowed. When MDM is enabled, it allows the user to have the computer remotely managed by a MDM Server. If you do not configure this policy setting, MDM Enrollment will be enabled. If you enable this policy setting, MDM Enrollment will be disabled for all users. It will not unenroll existing MDM enrollments.If you disable this policy setting, MDM Enrollment will be enabled for all users."

`AutoEnrollMDM`:  
"This policy setting specifies whether to automatically enroll the device to the Mobile Device Management (MDM) service configured in Azure Active Directory (Azure AD). If the enrollment is successful, the device will remotely managed by the MDM service. Important: The device must be registered in Azure AD for enrollment to succeed. If you do not configure this policy setting, automatic MDM enrollment will not be initiated. If you enable this policy setting, a task is created to initiate enrollment of the device to MDM service specified in the Azure AD. If you disable this policy setting, MDM will be unenrolled."

```json
{
  "File": "MDM.admx",
  "CategoryName": "MDM",
  "PolicyName": "MDM_MDM_DisplayName",
  "NameSpace": "Microsoft.Policies.MDM",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Disable MDM Enrollment",
  "ExplainText": "This policy setting specifies whether Mobile Device Management (MDM) Enrollment is allowed. When MDM is enabled, it allows the user to have the computer remotely managed by a MDM Server. If you do not configure this policy setting, MDM Enrollment will be enabled. If you enable this policy setting, MDM Enrollment will be disabled for all users. It will not unenroll existing MDM enrollments. If you disable this policy setting, MDM Enrollment will be enabled for all users.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\CurrentVersion\\MDM"
  ],
  "ValueName": "DisableRegistration",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "MDM.admx",
  "CategoryName": "MDM",
  "PolicyName": "MDM_JoinMDM_DisplayName",
  "NameSpace": "Microsoft.Policies.MDM",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Enable automatic MDM enrollment using default Azure AD credentials",
  "ExplainText": "This policy setting specifies whether to automatically enroll the device to the Mobile Device Management (MDM) service configured in Azure Active Directory (Azure AD). If the enrollment is successful, the device will remotely managed by the MDM service. Important: The device must be registered in Azure AD for enrollment to succeed. If you do not configure this policy setting, automatic MDM enrollment will not be initiated. If you enable this policy setting, a task is created to initiate enrollment of the device to MDM service specified in the Azure AD. If you disable this policy setting, MDM will be unenrolled.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\CurrentVersion\\MDM"
  ],
  "ValueName": "AutoEnrollMDM",
  "Elements": [
    { "Type": "Enum", "ValueName": "UseAADCredentialType", "Items": [
        { "DisplayName": "User Credential", "Data": "1" },
        { "DisplayName": "Device Credential", "Data": "2" }
      ]
    },
    { "Type": "Text", "ValueName": "MDMApplicationId" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Feedback Prompts

"This policy setting allows an organization to prevent its devices from showing feedback questions from Microsoft.If you enable this policy setting, users will no longer see feedback notifications through the Windows Feedback app.If you disable or do not configure this policy setting, users may see notifications through the Windows Feedback app asking users for feedback.Note: If you disable or do not configure this policy setting, users can control how often they receive feedback questions."

Includes setting `Feedback Frequency` to `0` via `NumberOfSIUFInPeriod` & `PeriodInNanoSeconds`.

```json
{
  "File": "FeedbackNotifications.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "DoNotShowFeedbackNotifications",
  "NameSpace": "Microsoft.Policies.FeedbackNotifications",
  "Supported": "Windows_10_0",
  "DisplayName": "Do not show feedback notifications",
  "ExplainText": "This policy setting allows an organization to prevent its devices from showing feedback questions from Microsoft. If you enable this policy setting, users will no longer see feedback notifications through the Windows Feedback app. If you disable or do not configure this policy setting, users may see notifications through the Windows Feedback app asking users for feedback. Note: If you disable or do not configure this policy setting, users can control how often they receive feedback questions.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DoNotShowFeedbackNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable CEIP

Voluntary program that collects usage data to help improve the quality and performance of its products.

> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-admx-icm  
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-internetexplorer#disablecustomerexperienceimprovementprogramparticipation

```json
{
  "File": "appv.admx",
  "CategoryName": "CAT_CEIP",
  "PolicyName": "CEIP_Enable",
  "NameSpace": "Microsoft.Policies.AppV",
  "Supported": "Windows7",
  "DisplayName": "Microsoft Customer Experience Improvement Program (CEIP)",
  "ExplainText": "The program collects information about computer hardware and how you use Microsoft Application Virtualization without interrupting you. This helps Microsoft identify which Microsoft Application Virtualization features to improve. No information collected is used to identify or contact you. For more details, read about the program online at http://go.microsoft.com/fwlink/?LinkID=184686.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\AppV\\CEIP"
  ],
  "ValueName": "CEIPEnable",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ICM.admx",
  "CategoryName": "InternetManagement_Settings",
  "PolicyName": "CEIPEnable",
  "NameSpace": "Microsoft.Policies.InternetCommunicationManagement",
  "Supported": "WindowsVista",
  "DisplayName": "Turn off Windows Customer Experience Improvement Program",
  "ExplainText": "This policy setting turns off the Windows Customer Experience Improvement Program. The Windows Customer Experience Improvement Program collects information about your hardware configuration and how you use our software and services to identify trends and usage patterns. Microsoft will not collect your name, address, or any other personally identifiable information. There are no surveys to complete, no salesperson will call, and you can continue working without interruption. It is simple and user-friendly. If you enable this policy setting, all users are opted out of the Windows Customer Experience Improvement Program. If you disable this policy setting, all users are opted into the Windows Customer Experience Improvement Program. If you do not configure this policy setting, the administrator can use the Problem Reports and Solutions component in Control Panel to enable Windows Customer Experience Improvement Program for all users.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\SQMClient\\Windows"
  ],
  "ValueName": "CEIPEnable",
  "Elements": [
    { "Type": "EnabledValue", "Data": "0" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
{
  "File": "ICM.admx",
  "CategoryName": "InternetManagement_Settings",
  "PolicyName": "WinMSG_NoInstrumentation_2",
  "NameSpace": "Microsoft.Policies.InternetCommunicationManagement",
  "Supported": "WindowsXPSP2_Or_WindowsNET",
  "DisplayName": "Turn off the Windows Messenger Customer Experience Improvement Program",
  "ExplainText": "This policy setting specifies whether Windows Messenger collects anonymous information about how Windows Messenger software and service is used. With the Customer Experience Improvement program, users can allow Microsoft to collect anonymous information about how the product is used. This information is used to improve the product in future releases. If you enable this policy setting, Windows Messenger does not collect usage information, and the user settings to enable the collection of usage information are not shown. If you disable this policy setting, Windows Messenger collects anonymous usage information, and the setting is not shown. If you do not configure this policy setting, users have the choice to opt in and allow information to be collected.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Messenger\\Client"
  ],
  "ValueName": "CEIP",
  "Elements": [
    { "Type": "EnabledValue", "Data": "2" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
```

# Disable Cortana

"Cortana was a virtual assistant developed by Microsoft that used the Bing search engine to perform tasks such as setting reminders and answering questions for users."

> https://en.wikipedia.org/wiki/Cortana_(virtual_assistant)

# Hide Last Logged-In User

"This security setting determines whether the Windows sign-in screen will show the username of the last person who signed in on this PC."

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 0
```

`Hide Username at Sign-In`:  
"This security setting determines whether the username of the person signing in to this PC appears at Windows sign-in, after credentials are entered, and before the PC desktop is shown."

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 0
```

> https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/interactive-logon-do-not-display-last-user-name

---

```json
{
  "File": "WinLogon.admx",
  "CategoryName": "Logon",
  "PolicyName": "DisplayLastLogonInfoDescription",
  "NameSpace": "Microsoft.Policies.WindowsLogon2",
  "Supported": "WindowsVista - At least Windows Vista",
  "DisplayName": "Display information about previous logons during user logon",
  "ExplainText": "This policy setting controls whether or not the system displays information about previous logons and logon failures to the user. For local user accounts and domain user accounts in domains of at least a Windows Server 2008 functional level, if you enable this setting, a message appears after the user logs on that displays the date and time of the last successful logon by that user, the date and time of the last unsuccessful logon attempted with that user name, and the number of unsuccessful logons since the last successful logon by that user. This message must be acknowledged by the user before the user is presented with the Microsoft Windows desktop. For domain user accounts in Windows Server 2003, Windows 2000 native, or Windows 2000 mixed functional level domains, if you enable this setting, a warning message will appear that Windows could not retrieve the information and the user will not be able to log on. Therefore, you should not enable this policy setting if the domain is not at the Windows Server 2008 domain functional level. If you disable or do not configure this setting, messages about the previous logon or logon failures are not displayed.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "ValueName": "DisplayLastLogonInfo",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WinLogon.admx",
  "CategoryName": "Logon",
  "PolicyName": "LogonHoursNotificationPolicyDescription",
  "NameSpace": "Microsoft.Policies.WindowsLogon2",
  "Supported": "WindowsVista - At least Windows Vista",
  "DisplayName": "Remove logon hours expiration warnings",
  "ExplainText": "This policy controls whether the logged on user should be notified when his logon hours are about to expire. By default, a user is notified before logon hours expire, if actions have been set to occur when the logon hours expire. If you enable this setting, warnings are not displayed to the user before the logon hours expire. If you disable or do not configure this setting, users receive warnings before the logon hours expire, if actions have been set to occur when the logon hours expire. Note: If you configure this setting, you might want to examine and appropriately configure the \u201cSet action to take when logon hours expire\u201d setting. If \u201cSet action to take when logon hours expire\u201d is disabled or not configured, the \u201cRemove logon hours expiration warnings\u201d setting will have no effect, and users receive no warnings about logon hour expiration",
  "KeyPath": [
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "ValueName": "DontDisplayLogonHoursWarnings",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Background Apps

"This policy setting specifies whether Windows apps can run in the background.You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting.If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can run in the background by using Settings Privacy on the device.If you choose the "Force Allow" option, Windows apps are allowed to run in the background and employees in your organization cannot change it.If you choose the "Force Deny" option, Windows apps are not allowed to run in the background and employees in your organization cannot change it.If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can run in the background by using Settings Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app."

```
Computer Configuration\Administrative Templates\Windows Components\App Privacy
```
`Enabled` -> `Deny All changes`:
```powershell
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground	Type: REG_DWORD, Length: 4, Data: 2
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_UserInControlOfTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_ForceAllowTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
mmc.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Group Policy Objects\{5D10D350-8BC7-4D14-9723-C79DF35A74B4}Machine\Software\Policies\Microsoft\Windows\AppPrivacy\LetAppsRunInBackground_ForceDenyTheseApps	Type: REG_MULTI_SZ, Length: 2, Data: 
```

```json
{
  "File": "AppPrivacy.admx",
  "CategoryName": "AppPrivacy",
  "PolicyName": "LetAppsRunInBackground",
  "NameSpace": "Microsoft.Policies.AppPrivacy",
  "Supported": "Windows_10_0",
  "DisplayName": "Let Windows apps run in the background",
  "ExplainText": "This policy setting specifies whether Windows apps can run in the background. You can specify either a default setting for all apps or a per-app setting by specifying a Package Family Name. You can get the Package Family Name for an app by using the Get-AppPackage Windows PowerShell cmdlet. A per-app setting overrides the default setting. If you choose the \"User is in control\" option, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device. If you choose the \"Force Allow\" option, Windows apps are allowed to run in the background and employees in your organization cannot change it. If you choose the \"Force Deny\" option, Windows apps are not allowed to run in the background and employees in your organization cannot change it. If you disable or do not configure this policy setting, employees in your organization can decide whether Windows apps can run in the background by using Settings > Privacy on the device. If an app is open when this Group Policy object is applied on a device, employees must restart the app or device for the policy changes to be applied to the app.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppPrivacy"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "LetAppsRunInBackground", "Items": [
        { "DisplayName": "User is in control", "Data": "0" },
        { "DisplayName": "Force Allow", "Data": "1" },
        { "DisplayName": "Force Deny", "Data": "2" }
      ]
    }
  ]
},
```

# Disable WER

WER (Windows Error Reporting) sends error logs to Microsoft, disabling it keeps error data local.

`\Microsoft\Windows\Windows Error Reporting : QueueReporting` would run `%windir%\system32\wermgr.exe -upload`. `Error-Reporting.txt` shows a trace of `\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting`.

```
0.0.0.0 watson.microsoft.com
0.0.0.0 watson.telemetry.microsoft.com
0.0.0.0 umwatsonc.events.data.microsoft.com
0.0.0.0 ceuswatcab01.blob.core.windows.net
0.0.0.0 ceuswatcab02.blob.core.windows.net
0.0.0.0 eaus2watcab01.blob.core.windows.net
0.0.0.0 eaus2watcab02.blob.core.windows.net
0.0.0.0 weus2watcab01.blob.core.windows.net
0.0.0.0 weus2watcab02.blob.core.windows.net
```
`DisableSendRequestAdditionalSoftwareToWER`: "Prevent Windows from sending an error report when a device driver requests additional software during installation"
`DisableSendGenericDriverNotFoundToWER`: "Do not send a Windows error report when a generic driver is installed on a device"

> https://learn.microsoft.com/en-us/troubleshoot/windows-client/system-management-components/windows-error-reporting-diagnostics-enablement-guidance#configure-network-endpoints-to-be-allowed  
> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-errorreporting  
> https://learn.microsoft.com/en-us/windows/win32/wer/wer-settings  
> [privacy/assets | wer-PciGetSystemWideHackFlagsFromRegistry.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/wer-PciGetSystemWideHackFlagsFromRegistry.c)

`Disable DHA Report`:  
"This group policy enables Device Health Attestation reporting (DHA-report) on supported devices. It enables supported devices to send Device Health Attestation related information (device boot logs, PCR values, TPM certificate, etc.) to Device Health Attestation Service (DHA-Service) every time a device starts. Device Health Attestation Service validates the security state and health of the devices, and makes the findings accessible to enterprise administrators via a cloud based reporting portal. This policy is independent of DHA reports that are initiated by device manageability solutions (like MDM or SCCM), and will not interfere with their workflows."

```powershell
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ArchiveFolderCountLimit
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : AutoApproveOSDumps
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : BypassDataThrottling
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : BypassNetworkCostThrottling
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : BypassPowerThrottling
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CabArchiveCreate
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CabArchiveFolder
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CabArchiveSeparate
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ChangeDumpTypeByTelemetryLevel
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ConfigureArchive
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CorporateWerPortNumber
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CorporateWerServer
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CorporateWerUploadOnFreeNetworksOnly
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CorporateWerUseAuthentication
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : CorporateWerUseSSL
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DeferCabUpload
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DisableArchive
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : Disabled
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DisableEnterpriseAuthProxy
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DisableWerUpload
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DontSendAdditionalData
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : DontShowUI
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ForceEtw
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ForceHeapDump
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ForceMetadata
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ForceQueue
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : ForceUserModeCabCollection
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : LiveReportFlushInterval
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : LocalCompression
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : LoggingDisabled
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : MaxArchiveCount
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : MaxQueueCount
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : MaxRetriesForSasRenewal
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : MinFreeDiskSpace
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : MinQueueSize
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : NoHeapDumpOnQueue
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : OobeCompleted
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : QueueNoPesterInterval
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : QueuePesterInterval
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : QueueSizeMaxPercentFreeDisk
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : source
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : StorePath
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : UploadOnFreeNetworksOnly
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting : User
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting\Consent : DefaultConsent
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting\Consent : DefaultOverrideBehavior
\Registry\Machine\SOFTWARE\Microsoft\WINDOWS\Windows Error Reporting\Consent : NewUserDefaultConsent
```

---

Miscellaneous notes:  

```c
`EnableWerUserReporting`  
Default: `1` (`DbgkEnableWerUserReporting dd 1`)

"Session Manager\Kernel","EnableWerUserReporting","0xFFFFF800CF1C335C","0x00000000","0x00000000","0x00000000"
```

Related to PCIe advanced error reporting? Haven't found anything on this and haven't done much research myself:
```
\Registry\Machine\SYSTEM\ControlSet001\Control\PnP\pci : AerMultiErrorDisabled
```
Default is `0`, non zero would enable the behaviour? The value doesn't exist by default.
> https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_rootport_aer_capability ?

```
\Registry\Machine\SYSTEM\ControlSet001\Control\StorPort : TelemetryErrorDataEnabled
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Memory Management : PeriodicTelemetryReportFrequency
```

```json
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReporting",
  "PolicyName": "PCH_ShowUI",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsNET_XP",
  "DisplayName": "Display Error Notification",
  "ExplainText": "This policy setting controls whether users are shown an error dialog box that lets them report an error. If you enable this policy setting, users are notified in a dialog box that an error has occurred, and can display more details about the error. If the Configure Error Reporting policy setting is also enabled, the user can also report the error. If you disable this policy setting, users are not notified that errors have occurred. If the Configure Error Reporting policy setting is also enabled, errors are reported, but users receive no notification. Disabling this policy setting is useful for servers that do not have interactive users. If you do not configure this policy setting, users can change this setting in Control Panel, which is set to enable notification by default on computers that are running Windows XP Personal Edition and Windows XP Professional Edition, and disable notification by default on computers that are running Windows Server. See also the Configure Error Reporting policy setting.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\PCHealth\\ErrorReporting"
  ],
  "ValueName": "ShowUI",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReporting",
  "PolicyName": "WerDisable_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsVista",
  "DisplayName": "Disable Windows Error Reporting",
  "ExplainText": "This policy setting turns off Windows Error Reporting, so that reports are not collected or sent to either Microsoft or internal servers within your organization when software unexpectedly stops working or fails. If you enable this policy setting, Windows Error Reporting does not send any problem information to Microsoft. Additionally, solution information is not available in Security and Maintenance in Control Panel. If you disable or do not configure this policy setting, the Turn off Windows Error Reporting policy setting in Computer Configuration/Administrative Templates/System/Internet Communication Management/Internet Communication settings takes precedence. If Turn off Windows Error Reporting is also either disabled or not configured, user settings in Control Panel for Windows Error Reporting are applied.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting"
  ],
  "ValueName": "Disabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReporting",
  "PolicyName": "WerAutoApproveOSDumps_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "Windows_6_3only",
  "DisplayName": "Automatically send memory dumps for OS-generated error reports",
  "ExplainText": "This policy setting controls whether memory dumps in support of OS-generated error reports can be sent to Microsoft automatically. This policy does not apply to error reports generated by 3rd-party products, or additional data other than memory dumps. If you enable or do not configure this policy setting, any memory dumps generated for error reports by Microsoft Windows are automatically uploaded, without notification to the user. If you disable this policy setting, then all memory dumps are uploaded according to the default consent and notification settings.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting"
  ],
  "ValueName": "AutoApproveOSDumps",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReporting",
  "PolicyName": "WerNoLogging_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsVista",
  "DisplayName": "Disable logging",
  "ExplainText": "This policy setting controls whether Windows Error Reporting saves its own events and error messages to the system event log. If you enable this policy setting, Windows Error Reporting events are not recorded in the system event log. If you disable or do not configure this policy setting, Windows Error Reporting events and errors are logged to the system event log, as with other Windows-based programs.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting"
  ],
  "ValueName": "LoggingDisabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReporting",
  "PolicyName": "WerNoSecondLevelData_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsVista",
  "DisplayName": "Do not send additional data",
  "ExplainText": "This policy setting controls whether additional data in support of error reports can be sent to Microsoft automatically. If you enable this policy setting, any additional data requests from Microsoft in response to a Windows Error Reporting report are automatically declined, without notification to the user. If you disable or do not configure this policy setting, then consent policy settings in Computer Configuration/Administrative Templates/Windows Components/Windows Error Reporting/Consent take precedence.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting"
  ],
  "ValueName": "DontSendAdditionalData",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReportingConsent",
  "PolicyName": "WerDefaultConsent_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "Windows_6_3ToVista",
  "DisplayName": "Configure Default consent",
  "ExplainText": "This policy setting determines the default consent behavior of Windows Error Reporting. If you enable this policy setting, you can set the default consent handling for error reports. The following list describes the Consent level settings that are available in the pull-down menu in this policy setting: - Always ask before sending data: Windows prompts users for consent to send reports. - Send parameters: Only the minimum data that is required to check for an existing solution is sent automatically, and Windows prompts users for consent to send any additional data that is requested by Microsoft. - Send parameters and safe additional data: the minimum data that is required to check for an existing solution, along with data which Windows has determined (within a high probability) does not contain personally-identifiable information is sent automatically, and Windows prompts the user for consent to send any additional data that is requested by Microsoft. - Send all data: any error reporting data requested by Microsoft is sent automatically. If this policy setting is disabled or not configured, then the consent level defaults to the highest-privacy setting: Always ask before sending data.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting\\Consent"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "DefaultConsent", "Items": [
        { "DisplayName": "Always ask before sending data", "Data": "1" },
        { "DisplayName": "Send parameters", "Data": "2" },
        { "DisplayName": "Send parameters and safe additional data", "Data": "3" },
        { "DisplayName": "Send all data", "Data": "4" }
      ]
    }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReportingConsent",
  "PolicyName": "WerConsentOverride_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsVista",
  "DisplayName": "Ignore custom consent settings",
  "ExplainText": "This policy setting determines the behavior of the Configure Default Consent setting in relation to custom consent settings. If you enable this policy setting, the default consent levels of Windows Error Reporting always override any other consent policy setting. If you disable or do not configure this policy setting, custom consent policy settings for error reporting determine the consent level for specified event types, and the default consent setting determines only the consent level of any other error reports.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting\\Consent"
  ],
  "ValueName": "DefaultOverrideBehavior",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DeviceSetup.admx",
  "CategoryName": "DeviceInstall_Category",
  "PolicyName": "DeviceInstall_RequestAdditionalSoftwareSendToWER",
  "NameSpace": "Microsoft.Policies.DeviceSoftwareSetup",
  "Supported": "Windows_10_0_RS3ToWindows7",
  "DisplayName": "Prevent Windows from sending an error report when a device driver requests additional software during installation",
  "ExplainText": "Windows has a feature that allows a device driver to request additional software through the Windows Error Reporting infrastructure. This policy allows you to disable the feature. If you enable this policy setting, Windows will not send an error report to request additional software even if this is specified by the device driver. If you disable or do not configure this policy setting, Windows sends an error report when a device driver that requests additional software is installed.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DeviceInstall\\Settings"
  ],
  "ValueName": "DisableSendRequestAdditionalSoftwareToWER",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DeviceSetup.admx",
  "CategoryName": "DeviceInstall_Category",
  "PolicyName": "DeviceInstall_GenericDriverSendToWER",
  "NameSpace": "Microsoft.Policies.DeviceSoftwareSetup",
  "Supported": "Windows_10_0_RS3ToVista",
  "DisplayName": "Do not send a Windows error report when a generic driver is installed on a device",
  "ExplainText": "Windows has a feature that sends \"generic-driver-installed\" reports through the Windows Error Reporting infrastructure. This policy allows you to disable the feature. If you enable this policy setting, an error report is not sent when a generic driver is installed. If you disable or do not configure this policy setting, an error report is sent when a generic driver is installed.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DeviceInstall\\Settings"
  ],
  "ValueName": "DisableSendGenericDriverNotFoundToWER",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "TPM.admx",
  "CategoryName": "DSHACategory",
  "PolicyName": "OptIntoDSHA_Name",
  "NameSpace": "Microsoft.Policies.TrustedPlatformModule",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Enable Device Health Attestation Monitoring and Reporting",
  "ExplainText": "This group policy enables Device Health Attestation reporting (DHA-report) on supported devices. It enables supported devices to send Device Health Attestation related information (device boot logs, PCR values, TPM certificate, etc.) to Device Health Attestation Service (DHA-Service) every time a device starts. Device Health Attestation Service validates the security state and health of the devices, and makes the findings accessible to enterprise administrators via a cloud based reporting portal. This policy is independent of DHA reports that are initiated by device manageability solutions (like MDM or SCCM), and will not interfere with their workflows.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\DeviceHealthAttestationService"
  ],
  "ValueName": "EnableDeviceHealthAttestationService",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ErrorReporting.admx",
  "CategoryName": "CAT_WindowsErrorReportingAdvanced",
  "PolicyName": "WerArchive_2",
  "NameSpace": "Microsoft.Policies.WindowsErrorReporting",
  "Supported": "WindowsVista - At least Windows Vista",
  "DisplayName": "Configure Report Archive",
  "ExplainText": "This policy setting controls the behavior of the Windows Error Reporting archive. If you enable this policy setting, you can configure Windows Error Reporting archiving behavior. If Archive behavior is set to Store all, all data collected for each error report is stored in the appropriate location. If Archive behavior is set to Store parameters only, only the minimum information required to check for an existing solution is stored. The Maximum number of reports to store setting determines how many reports are stored before older reports are automatically deleted. If you disable or do not configure this policy setting, no Windows Error Reporting information is stored.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting"
  ],
  "ValueName": "DisableArchive",
  "Elements": [
    { "Type": "Enum", "ValueName": "ConfigureArchive", "Items": [
        { "DisplayName": "Store all", "Data": "2" },
        { "DisplayName": "Store parameters only", "Data": "1" }
      ]
    },
    { "Type": "Decimal", "ValueName": "MaxArchiveCount", "MinValue": null, "MaxValue": "5000" },
    { "Type": "EnabledValue", "Data": "0" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
```

# Disable Crash Dumps

Disables the crash dump, logging. Not all values may be read on your system.

```c
CrashDumpEnabled REG_DWORD 0x0 = None
CrashDumpEnabled REG_DWORD 0x1 = Complete memory dump
CrashDumpEnabled REG_DWORD 0x2 = Kernel memory dump
CrashDumpEnabled REG_DWORD 0x3 = Small memory dump (64 KB)
CrashDumpEnabled REG_DWORD 0x7 = Automatic memory dump
CrashDumpEnabled REG_DWORD 0x1 and FilterPages REG_DWORD 0x1 = Active memory dump
```

> https://learn.microsoft.com/en-us/troubleshoot/windows-server/performance/memory-dump-file-options#registry-values-for-startup-and-recovery  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/automatic-memory-dump  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/CrashControl.txt  
> [privacy/assets | crashdmp.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/crashdmp.c)  
> [privacy/assets | crashdmp-SecureDump_PrepareForInit.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/crashdmp-SecureDump_PrepareForInit.c)

---

# Disable Sleep Study

Sleep Study tracks modern sleep states to analyze energy usage and pinpoint battery drain. It disables Sleep Study by making ETL logs read-only, disabling related diagnostics, and turning off the scheduled task.

```powershell
wevtutil sl Microsoft-Windows-SleepStudy/Diagnostic /e:false
svchost.exe	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-SleepStudy/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-Kernel-Processor-Power/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-Kernel-Processor-Power/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-UserModePowerService/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-UserModePowerService/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0
```

> [privacy/assets | sleepstudy-FxLibraryGlobalsQueryRegistrySettings.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/sleepstudy-FxLibraryGlobalsQueryRegistrySettings.c)  
> [privacy/assets | sleepstudy-PoFxInitPowerManagement.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/sleepstudy-PoFxInitPowerManagement.c)

---

Miscellaenous notes:
```c
```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "SleepstudyAccountingEnabled"; = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit"; = 3000; // SleepstudyHelperBlockerGlobalLimit (0x0BB8) 
    "SleepstudyLibraryBlockerLimit"; = 200; // SleepstudyHelperBlockerLibraryLimit (0xC8) 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "SleepStudyDeviceAccountingLevel"; = 4; // PopSleepStudyDeviceAccountingLevel 
    "SleepStudyDisabled"; = 0; // PopSleepStudyDisabled 
```
> https://github.com/5Noxi/wpr-reg-records#power-values
```
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0010\3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDIF030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\Display\MSI3CB0\5&34f902e3&1&UID28931\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_149C&SUBSYS_87C01043&REV_00\4&231a312e&0&0341\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_43EE&SUBSYS_11421B21&REV_00\4&20e120c7&0&000A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_790E&SUBSYS_87C01043&REV_51\3&11583659&0&A3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_10DE&DEV_228B&SUBSYS_50521462&REV_A1\4&1d81e16&0&0119\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_8086&DEV_15F3&SUBSYS_87D21043&REV_02\6&102e3adf&0&0048020A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\CompositeBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\NdisVirtualBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\SYSTEM\0002\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\UMBUS\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\vdrvroot\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\VID\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2bce96aa&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2c35141&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot00\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot01\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot02\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot03\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot04\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot05\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot06\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_05E3&PID_0610\6&3365fbaf&0&11\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0B05&PID_1939&MI_00\7&40fe908&0&0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0CF2&PID_A102&MI_00\8&7b0cf2a&0&0000\Device Parameters\Wdf : SleepstudyState
```
```
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : EnableNicAutoPowerSaverInSleepStudy
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : EnableNicAutoPowerSaverInSleepStudy
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Power : SleepStudyBufferSizeInMB
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager\Power : SleepStudyTraceDirectory
```

> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/wevtutil

# Disable RSoP Logging

"This setting allows you to enable or disable Resultant Set of Policy (RSoP) logging on a client computer.RSoP logs information on Group Policy settings that have been applied to the client. This information includes details such as which Group Policy Objects (GPO) were applied where they came from and the client-side extension settings that were included.If you enable this setting RSoP logging is turned off.If you disable or do not configure this setting RSoP logging is turned on. By default RSoP logging is always on.Note: To view the RSoP information logged on a client computer you can use the RSoP snap-in in the Microsoft Management Console (MMC)."

> https://www.windows-security.org/370c915e44b6a75efac0d24669aa9434/turn-off-resultant-set-of-policy-logging

```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon : RsopLogging
\Registry\Machine\SOFTWARE\Policies\Microsoft\Windows\SYSTEM : RsopLogging
```

> https://learn.microsoft.com/en-us/previous-versions/windows/desktop/Policy/developing-an-rsop-management-tool  
> [privacy/assets | rsop-IsDesktopHeapLoggingOn.c](https://github.com/5Noxi/win-config/blob/main/privacy/assets/rsop-IsDesktopHeapLoggingOn.c)

---

Another logging feature - `DesktopHeapLogging`. "It is meant to log information about desktop heap usage. This can be helpful when diagnosing issues where system resources for desktop objects might be strained." ([*](https://answers.microsoft.com/en-us/windows/forum/all/question-about-some-dwm-registry-settings/341cac5c-d85a-43e5-89d3-d9734f84da4e))

```bat
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows" /v DesktopHeapLogging /t REG_DWORD /d 0 /f
```

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Winows-NT.txt

# Disable Message Sync

"This policy setting allows backup and restore of cellular text messages to Microsoft's cloud services. Disable this feature to avoid information being stored on servers outside of your organization's control."

| Policy | Description | Values |
| ------ | ------ | ------ |
| AllowMessageSync | Controls whether SMS/MMS are synced to Microsoft's cloud so they can be backed up and restored; also decides if the user can toggle this in the UI. | 0 = sync not allowed, user cannot change - 1 = sync allowed, user can change (default) |

> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-messaging

```json
{
  "File": "messaging.admx",
  "CategoryName": "Messaging_Category",
  "PolicyName": "AllowMessageSync",
  "NameSpace": "Microsoft.Policies.Messaging",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Allow Message Service Cloud Sync",
  "ExplainText": "This policy setting allows backup and restore of cellular text messages to Microsoft's cloud services.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Messaging"
  ],
  "ValueName": "AllowMessageSync",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable CSC

Disable Offline Files (CSC) via policy and services. Sets NetCache policy keys, disables `CSC`/`CscService`, disables the two `Offline Files` scheduled tasks (they're disabled by default), and renames `mobsync.exe` to block execution.

"Offline Files (Client-Side Caching, CSC) lets Windows cache files from network shares locally so users can keep working when the network/server is unavailable. Sync Center handles the background sync between the local CSC cache (`%SystemRoot%\CSC`) and the share. It's commonly paired with Folder Redirection so "known folders" (e.g., Documents) live on a server but remain available offline, with options like "Always Offline" for performance on slow links. You enable/disable it via Sync Center (Control Panel) or policy. When disabled, Sync Center has nothing to sync."

> https://learn.microsoft.com/en-us/windows-server/storage/folder-redirection/deploy-folder-redirection


```json
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_Enabled",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "Win2k",
  "DisplayName": "Allow or Disallow use of the Offline Files feature",
  "ExplainText": "This policy setting determines whether the Offline Files feature is enabled. Offline Files saves a copy of network files on the user's computer for use when the computer is not connected to the network. If you enable this policy setting, Offline Files is enabled and users cannot disable it. If you disable this policy setting, Offline Files is disabled and users cannot enable it. If you do not configure this policy setting, Offline Files is enabled on Windows client computers, and disabled on computers running Windows Server, unless changed by the user. Note: Changes to this policy setting do not take effect until the affected computer is restarted.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "Enabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_BackgroundSyncSettings",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "Windows7",
  "DisplayName": "Configure Background Sync",
  "ExplainText": "This policy setting controls when background synchronization occurs while operating in slow-link mode, and applies to any user who logs onto the specified machine while this policy is in effect. To control slow-link mode, use the \"Configure slow-link mode\" policy setting. If you enable this policy setting, you can control when Windows synchronizes in the background while operating in slow-link mode. Use the 'Sync Interval' and 'Sync Variance' values to override the default sync interval and variance settings. Use 'Blockout Start Time' and 'Blockout Duration' to set a period of time where background sync is disabled. Use the 'Maximum Allowed Time Without A Sync' value to ensure that all network folders on the machine are synchronized with the server on a regular basis. You can also configure Background Sync for network shares that are in user selected Work Offline mode. This mode is in effect when a user selects the Work Offline button for a specific share. When selected, all configured settings will apply to shares in user selected Work Offline mode as well. If you disable or do not configure this policy setting, Windows performs a background sync of offline folders in the slow-link mode at a default interval with the start of the sync varying between 0 and 60 additional minutes. In Windows 7 and Windows Server 2008 R2, the default sync interval is 360 minutes. In Windows 8 and Windows Server 2012, the default sync interval is 120 minutes.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "BackgroundSyncEnabled",
  "Elements": [
    { "Type": "Decimal", "ValueName": "BackgroundSyncPeriodMin", "MinValue": "1", "MaxValue": "1440" },
    { "Type": "Decimal", "ValueName": "BackgroundSyncMaxStartMin", "MinValue": "0", "MaxValue": "3600" },
    { "Type": "Decimal", "ValueName": "BackgroundSyncIgnoreBlockOutAfterMin", "MinValue": "0", "MaxValue": "4294967295" },
    { "Type": "Decimal", "ValueName": "BackgroundSyncBlockOutStartTime", "MinValue": "0", "MaxValue": "2400" },
    { "Type": "Decimal", "ValueName": "BackgroundSyncBlockOutDurationMin", "MinValue": "0", "MaxValue": "1440" },
    { "Type": "Boolean", "ValueName": "BackgroundSyncEnabledForForcedOffline", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_NoReminders_2",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "WindowsPreVista",
  "DisplayName": "Turn off reminder balloons",
  "ExplainText": "Hides or displays reminder balloons, and prevents users from changing the setting. Reminder balloons appear above the Offline Files icon in the notification area to notify users when they have lost the connection to a networked file and are working on a local copy of the file. Users can then decide how to proceed. If you enable this setting, the system hides the reminder balloons, and prevents users from displaying them. If you disable the setting, the system displays the reminder balloons and prevents users from hiding them. If this setting is not configured, reminder balloons are displayed by default when you enable offline files, but users can change the setting. To prevent users from changing the setting while a setting is in effect, the system disables the \"Enable reminders\" option on the Offline Files tab This setting appears in the Computer Configuration and User Configuration folders. If both settings are configured, the setting in Computer Configuration takes precedence over the setting in User Configuration. Tip: To display or hide reminder balloons without establishing a setting, in Windows Explorer, on the Tools menu, click Folder Options, and then click the Offline Files tab. This setting corresponds to the \"Enable reminders\" check box.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "NoReminders",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_SyncAtLogoff_2",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "WindowsPreVista",
  "DisplayName": "Synchronize all offline files before logging off",
  "ExplainText": "Determines whether offline files are fully synchronized when users log off. This setting also disables the \"Synchronize all offline files before logging off\" option on the Offline Files tab. This prevents users from trying to change the option while a setting controls it. If you enable this setting, offline files are fully synchronized. Full synchronization ensures that offline files are complete and current. If you disable this setting, the system only performs a quick synchronization. Quick synchronization ensures that files are complete, but does not ensure that they are current. If you do not configure this setting, the system performs a quick synchronization by default, but users can change this option. This setting appears in the Computer Configuration and User Configuration folders. If both settings are configured, the setting in Computer Configuration takes precedence over the setting in User Configuration. Tip: To change the synchronization method without changing a setting, in Windows Explorer, on the Tools menu, click Folder Options, click the Offline Files tab, and then select the \"Synchronize all offline files before logging off\" option.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "SyncAtLogoff",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_SyncAtLogon_2",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "WindowsPreVista",
  "DisplayName": "Synchronize all offline files when logging on",
  "ExplainText": "Determines whether offline files are fully synchronized when users log on. This setting also disables the \"Synchronize all offline files before logging on\" option on the Offline Files tab. This prevents users from trying to change the option while a setting controls it. If you enable this setting, offline files are fully synchronized at logon. Full synchronization ensures that offline files are complete and current. Enabling this setting automatically enables logon synchronization in Synchronization Manager. If this setting is disabled and Synchronization Manager is configured for logon synchronization, the system performs only a quick synchronization. Quick synchronization ensures that files are complete but does not ensure that they are current. If you do not configure this setting and Synchronization Manager is configured for logon synchronization, the system performs a quick synchronization by default, but users can change this option. This setting appears in the Computer Configuration and User Configuration folders. If both settings are configured, the setting in Computer Configuration takes precedence over the setting in User Configuration. Tip: To change the synchronization method without setting a setting, in Windows Explorer, on the Tools menu, click Folder Options, click the Offline Files tab, and then select the \"Synchronize all offline files before logging on\" option.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "SyncAtLogon",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OfflineFiles.admx",
  "CategoryName": "Cat_OfflineFiles",
  "PolicyName": "Pol_WorkOfflineDisabled_2",
  "NameSpace": "Microsoft.Policies.OfflineFiles",
  "Supported": "Windows8",
  "DisplayName": "Remove \"Work offline\" command",
  "ExplainText": "This policy setting removes the \"Work offline\" command from Explorer, preventing users from manually changing whether Offline Files is in online mode or offline mode. If you enable this policy setting, the \"Work offline\" command is not displayed in File Explorer. If you disable or do not configure this policy setting, the \"Work offline\" command is displayed in File Explorer.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetCache"
  ],
  "ValueName": "WorkOfflineDisabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Cloud Content Search

"Cloud Content Search lets Windows Search include results from your signed-in cloud accounts personal Microsoft account (OneDrive, Outlook, Bing) and/or work/school (OneDrive for Business, SharePoint, Outlook) alongside local files. Turn it on per account to get those items and Bing-personalized suggestions, turn it off to keep search limited to local content (and non-personalized web)."

![](https://github.com/5Noxi/win-config/blob/main/privacy/images/cloudsearch.png?raw=true)

# Disable Microsoft Accounts

"This setting prevents using the Settings app to add a Microsoft account for single sign-on (SSO) authentication for Microsoft services and some background services, or using a Microsoft account for single sign-on to other applications or services.

There are two options if this setting is enabled:

• Users can't add Microsoft accounts means that existing connected accounts can still sign in to the device (and appear on the Sign in screen). However, users cannot use the Settings app to add new connected accounts (or connect local accounts to Microsoft accounts).

• Users can't add or log on with Microsoft accounts means that users cannot add new connected accounts (or connect local accounts to Microsoft accounts) or use existing connected accounts through Settings.

This setting does not affect adding a Microsoft account for application authentication. For example, if this setting is enabled, a user can still provide a Microsoft account for authentication with an application such as Mail, but the user cannot use the Microsoft account for single sign-on authentication for other applications or services (in other words, the user will be prompted to authenticate for other applications or services).

By default, this setting is Not defined."

```c
// This policy is disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 0

// Users can't add Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 1

// Users can't add or log on with Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 3
```

# Opt-Out KMS Activation Telemetry

Friendly name: `Turn off KMS Client Online AVS Validation`

"This policy setting lets you opt-out of sending KMS client activation data to Microsoft automatically. Enabling this setting prevents this computer from sending data to Microsoft regarding its activation state.

If you disable or don't configure this policy setting, KMS client activation data will be sent to Microsoft services when this device activates."

> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-licensing#disallowkmsclientonlineavsvalidation

```json
{
  "File": "AVSValidationGP.admx",
  "CategoryName": "SoftwareProtectionPlatform",
  "PolicyName": "NoAcquireGT",
  "NameSpace": "Microsoft.Policies.SoftwareProtectionPlatform",
  "Supported": "Windows_10_0",
  "DisplayName": "Turn off KMS Client Online AVS Validation",
  "ExplainText": "This policy setting lets you opt-out of sending KMS client activation data to Microsoft automatically. Enabling this setting prevents this computer from sending data to Microsoft regarding its activation state. If you disable or do not configure this policy setting, KMS client activation data will be sent to Microsoft services when this device activates. Policy Options: - Not Configured (default -- data will be automatically sent to Microsoft) - Disabled (data will be automatically sent to Microsoft) - Enabled (data will not be sent to Microsoft)",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\CurrentVersion\\Software Protection Platform"
  ],
  "ValueName": "NoGenTicket",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Font Providers

"This policy setting determines whether Windows is allowed to download fonts and font catalog data from an online font provider.

If you enable this policy setting, Windows periodically queries an online font provider to determine whether a new font catalog is available. Windows may also download font data if needed to format or render text.

If you disable this policy setting, Windows does not connect to an online font provider and only enumerates locally-installed fonts."

```json
{
  "File": "GroupPolicy.admx",
  "CategoryName": "NetworkFonts",
  "PolicyName": "EnableFontProviders",
  "NameSpace": "Microsoft.Policies.GroupPolicy",
  "Supported": "Windows_10_0",
  "DisplayName": "Enable Font Providers",
  "ExplainText": "This policy setting determines whether Windows is allowed to download fonts and font catalog data from an online font provider. If you enable this policy setting, Windows periodically queries an online font provider to determine whether a new font catalog is available. Windows may also download font data if needed to format or render text. If you disable this policy setting, Windows does not connect to an online font provider and only enumerates locally-installed fonts. If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "EnableFontProviders",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Local Security Questions

Prevent the use of security questions for local accounts.

```json
{
  "File": "CredUI.admx",
  "CategoryName": "CredUI",
  "PolicyName": "NoLocalPasswordResetQuestions",
  "NameSpace": "Microsoft.Policies.CredentialsUI",
  "Supported": "Windows_10_0_RS6",
  "DisplayName": "Prevent the use of security questions for local accounts",
  "ExplainText": "If you turn this policy setting on, local users won\u2019t be able to set up and use security questions to reset their passwords.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "NoLocalPasswordResetQuestions",
  "Elements": []
},
```

# Disable Application Compatibility

Disables Windows Application Experience telemetry and compatibility components, Microsoft Compatibility Appraiser (including its daily task and `CompatTelRunner.exe`) and the Application Experience tasks. It reduces telemetry, and some attack surface, but removes most automatic compatibility checks, upgrade assessments and some app related backup/recovery features.

`DisableAPISamping`, `DisableApplicationFootprint`, `DisableInstallTracing`, `DisableWin32AppBackup` will only work on 24H2 and above.

Currently includes all existing tasks in `\\Microsoft\\Windows\\Application Experience\\` (LTSC IoT Enterprise 2024):
```powershell
"\\Microsoft\\Windows\\Application Experience\\MareBackup",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser",
"\\Microsoft\\Windows\\Application Experience\\Microsoft Compatibility Appraiser Exp",
"\\Microsoft\\Windows\\Application Experience\\PcaPatchDbTask",
"\\Microsoft\\Windows\\Application Experience\\SdbinstMergeDbTask",
"\\Microsoft\\Windows\\Application Experience\\StartupAppTask"
```
```json
{
  "File": "AppDeviceInventory.admx",
  "CategoryName": "AppDeviceInventory",
  "PolicyName": "TurnOffAPISamping",
  "NameSpace": "Microsoft.Policies.AppDeviceInventory",
  "Supported": "Windows_11_0_24H2 - At least Windows 11 Version 24H2",
  "DisplayName": "Turn off API Sampling",
  "ExplainText": "This policy controls the state of API Sampling. API Sampling monitors the sampled collection of application programming interfaces used during system runtime to help diagnose compatibility problems. If you enable this policy, API Sampling will not be run. If you disable or do not configure this policy, API Sampling will be turned on.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableAPISamping",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppDeviceInventory.admx",
  "CategoryName": "AppDeviceInventory",
  "PolicyName": "TurnOffApplicationFootprint",
  "NameSpace": "Microsoft.Policies.AppDeviceInventory",
  "Supported": "Windows_11_0_24H2 - At least Windows 11 Version 24H2",
  "DisplayName": "Turn off Application Footprint",
  "ExplainText": "This policy controls the state of Application Footprint. Application Footprint monitors the sampled collection of registry and file usage to help diagnose compatibility problems. If you enable this policy, Application Footprint will not be run. If you disable or do not configure this policy, Application Footprint will be turned on.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableApplicationFootprint",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffEngine",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "WindowsNET - At least Windows Server 2003",
  "DisplayName": "Turn off Application Compatibility Engine",
  "ExplainText": "This policy controls the state of the application compatibility engine in the system. The engine is part of the loader and looks through a compatibility database every time an application is started on the system. If a match for the application is found it provides either run-time solutions or compatibility fixes, or displays an Application Help message if the application has a know problem. Turning off the application compatibility engine will boost system performance. However, this will degrade the compatibility of many popular legacy applications, and will not block known incompatible applications from installing. (For Instance: This may result in a blue screen if an old anti-virus application is installed.) The Windows Resource Protection and User Account Control features of Windows use the application compatibility engine to provide mitigations for application problems. If the engine is turned off, these mitigations will not be applied to applications and their installers and these applications may fail to install or run properly. This option is useful to server administrators who require faster performance and are aware of the compatibility of the applications they are using. It is particularly useful for a web server where applications may be launched several hundred times a second, and the performance of the loader is essential. NOTE: Many system processes cache the value of this setting for performance reasons. If you make changes to this setting, please reboot to ensure that your system accurately reflects those changes.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableEngine",
  "Elements": []
},
{
  "File": "AppDeviceInventory.admx",
  "CategoryName": "AppDeviceInventory",
  "PolicyName": "TurnOffInstallTracing",
  "NameSpace": "Microsoft.Policies.AppDeviceInventory",
  "Supported": "Windows_11_0_24H2 - At least Windows 11 Version 24H2",
  "DisplayName": "Turn off Install Tracing",
  "ExplainText": "This policy controls the state of Install Tracing. Install Tracing is a mechanism that tracks application installs to help diagnose compatibility problems. If you enable this policy, Install Tracing will not be run. If you disable or do not configure this policy, Install Tracing will be turned on.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableInstallTracing",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffProgramCompatibilityAssistant_1",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "WindowsVista - At least Windows Vista",
  "DisplayName": "Turn off Program Compatibility Assistant",
  "ExplainText": "This setting exists only for backward compatibility, and is not valid for this version of Windows. To configure the Program Compatibility Assistant, use the 'Turn off Program Compatibility Assistant' setting under Computer Configuration\\Administrative Templates\\Windows Components\\Application Compatibility.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisablePCA",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppDeviceInventory.admx",
  "CategoryName": "AppDeviceInventory",
  "PolicyName": "TurnOffWin32AppBackup",
  "NameSpace": "Microsoft.Policies.AppDeviceInventory",
  "Supported": "Windows_11_0_24H2 - At least Windows 11 Version 24H2",
  "DisplayName": "Turn off compatibility scan for backed up applications",
  "ExplainText": "This policy controls the state of the compatibility scan for backed up applications. The compatibility scan for backed up applications evaluates for compatibility problems in installed applications. If you enable this policy, the compatibility scan for backed up applications will not be run. If you disable or do not configure this policy, the compatibility scan for backed up applications will be run.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "DisableWin32AppBackup",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "AppCompat.admx",
  "CategoryName": "AppCompat",
  "PolicyName": "AppCompatTurnOffSwitchBack",
  "NameSpace": "Microsoft.Policies.ApplicationCompatibility",
  "Supported": "Windows7 - At least Windows Server 2008 R2 or Windows 7",
  "DisplayName": "Turn off SwitchBack Compatibility Engine",
  "ExplainText": "The policy controls the state of the Switchback compatibility engine in the system. Switchback is a mechanism that provides generic compatibility mitigations to older applications by providing older behavior to old applications and new behavior to new applications. Switchback is on by default. If you enable this policy setting, Switchback will be turned off. Turning Switchback off may degrade the compatibility of older applications. This option is useful for server administrators who require performance and are aware of compatibility of the applications they are using. If you disable or do not configure this policy setting, the Switchback will be turned on. Please reboot the system after changing the setting to ensure that your system accurately reflects those changes.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\AppCompat"
  ],
  "ValueName": "SbEnable",
  "Elements": [
    { "Type": "EnabledValue", "Data": "0" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
```

# Disable Census Data Collection

`DeviceCensus.exe` = "Device and configuration data collection tool"

"In a nutshell, Device Census is a telemetry process from Microsoft. It will analyze the use of the webcam and other components. Then, the data will be transmitted anonymously to Microsoft to help optimize Windows for future versions and fix bugs. In addition, it only checks how often the devices are used and don't record anything."

> https://www.partitionwizard.com/partitionmanager/devicecensus-exe.html

`\Microsoft\Windows\Device Information` runs:
```powershell
%windir%\system32\devicecensus.exe SystemCxt
```

`\Microsoft\Windows\Device Information` runs:
```powershell
%windir%\system32\devicecensus.exe UserCxt
```

# Disable OneSettings Download

Services Configuration is used by Windows components and apps, such as the telemetry service, to dynamically update their configuration. If you turn off this service, apps using this service may stop working.

If enabled = "Windows will periodically attempt to connect with the OneSettings service to download configuration settings".

> https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#31-services-configuration

```json
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "EnableOneSettingsAuditing",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS7 - At least Windows Server 2016, Windows 10 Version 1909",
  "DisplayName": "Enable OneSettings Auditing",
  "ExplainText": "This policy setting controls whether Windows records attempts to connect with the OneSettings service to the EventLog. If you enable this policy, Windows will record attempts to connect with the OneSettings service to the Microsoft\\Windows\\Privacy-Auditing\\Operational EventLog channel. If you disable or don't configure this policy setting, Windows will not record attempts to connect with the OneSettings service to the EventLog.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "EnableOneSettingsAuditing",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DataCollection.admx",
  "CategoryName": "DataCollectionAndPreviewBuilds",
  "PolicyName": "DisableOneSettingsDownloads",
  "NameSpace": "Microsoft.Policies.DataCollection",
  "Supported": "Windows_10_0_RS7 - At least Windows Server 2016, Windows 10 Version 1909",
  "DisplayName": "Disable OneSettings Downloads",
  "ExplainText": "This policy setting controls whether Windows attempts to connect with the OneSettings service. If you enable this policy, Windows will not attempt to connect with the OneSettings Service. If you disable or don't configure this policy setting, Windows will periodically attempt to connect with the OneSettings service to download configuration settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\DataCollection"
  ],
  "ValueName": "DisableOneSettingsDownloads",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```
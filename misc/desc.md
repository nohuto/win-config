# NVFetch

Used to be my personal `neofetch`/`fastfetch` replacement with more details. Some arguments will probably also get added like `ids`, so it doesn't display the serial numbers and miscellaneous HWIDs by default.

![](https://github.com/5Noxi/win-config/blob/main/misc/images/nvfetch.png?raw=true)

> https://github.com/5Noxi/nvfetch

It currently gets most of the information using the [`Get-CimInstance`](https://learn.microsoft.com/en-us/powershell/module/cimcmdlets/get-ciminstance?view=powershell-7.5) cmdlet and `nvidia-smi` for NVIDIA GPUs.
```powershell
nvidia-smi -q
```
[`nvfetch-win32cimv2.txt`]((https://github.com/5Noxi/win-config/blob/main/misc/assets)) shows class names in the `root\CIMV2` namespace, filtered with `Win32*`.

| **Category** | **Query** | **Fields/Description** |
| ---- | ---- | ---- |
| **OS** | `Win32_OperatingSystem` | `Caption` - OS name, `OSArchitecture` - Architecture (32-bit or 64-bit), `Version` - OS version |
| **Time Zone** | `Get-TimeZone` | `DisplayName` - Name of the current time zone |
| **Uptime** | `Win32_OperatingSystem` | `LastBootUpTime` - Last system boot time |
| **Display** | `Win32_VideoController`, `WmiMonitorID`, `WmiMonitorBasicDisplayParams`, `WmiMonitorConnectionParams` | `Name` - Display name, `Resolution` - Screen resolution, `Refresh Rate` - Monitor refresh rate, `Size (inch)` - Monitor size in inches, `External/Internal` - Whether external or internal monitor |
| **BIOS** | `Win32_BIOS` | `Manufacturer` - BIOS manufacturer, `SMBIOSBIOSVersion` - BIOS version, `ReleaseDate` - BIOS release date |
| **Motherboard** | `Win32_BaseBoard` | `Product` - Motherboard product, `Manufacturer` - Manufacturer of the motherboard |
| **CPU** | `Win32_Processor` | `Name` - Processor name, `SocketDesignation` - Socket type, `MaxClockSpeed` - Maximum clock speed in MHz |
| **GPU** | If `nvidia-smi` is present: `gc nvidia-smi` | `Name` - GPU name, `Core Clock` - GPU core clock speed, `Memory Clock` - GPU memory clock speed, `VRAM` - VRAM size, `BPP` - Bits per pixel, `Performance State` - State (e.g., P0 to P12) |
| | If `nvidia-smi` isn't present (AMD): `Win32_VideoController` | `Name` - GPU name, `Caption` - GPU caption, `CurrentBitsPerPixel` - Bits per pixel, `qwMemorySize` - VRAM size |
| **RAM** | `Win32_PhysicalMemory` | `Capacity` - Total memory size, `ConfiguredClockSpeed` - Memory clock speed, `Manufacturer` - RAM manufacturer |
| **Drive** | `Win32_DiskDrive`, `Win32_LogicalDisk` | For `drive0` & `C:\`: `Size` - Total size, `FreeSpace` - Free space, `FileSystem` - Type of file system (e.g., NTFS, FAT32) |
| **Network** | `Win32_NetworkAdapterConfiguration` | `Description` - Network adapter description, `IPAddress` - IP address, `DHCPEnabled` - Whether DHCP is enabled |
| **HWIDs** | UUID | `Win32_ComputerSystemProduct` - `UUID` - Unique system identifier (UUID) |
| | Motherboard SN | `Win32_BaseBoard` - `SerialNumber` - Motherboard serial number |
| | CPU ID | `Win32_Processor` - `ProcessorId` - Processor ID |
| | RAM SNs | `Win32_PhysicalMemory` - `SerialNumber` - RAM serial number |
| | Drive0 SN | `Win32_DiskDrive`/`Win32_PhysicalMedia` - `SerialNumber` - Drive serial number |
| | GPU UUID | `nvidia-smi` - `--query-gpu=uuid` - GPU UUID if `nvidia-smi` is available |

A valid argument is the color name, default is `Blue`. It changes the color of the ASCII logo. Change it by simply adding a valid color name:
```powershell
nvfetch # Uses 'Blue'

nvfetch yellow
nvfetch red
```
Valid colors: `Black`, `Blue`, `Cyan`, `DarkBlue`, `DarkCyan`, `DarkGray`, `DarkGreen`, `DarkMagenta`, `DarkRed`, `DarkYellow`, `Gray`, `Green`, `Magenta`, `Red`, `White`, `Yellow`.

> https://docs.nvidia.com/deploy/nvidia-smi/index.html  
> https://learn.microsoft.com/en-us/powershell/module/cimcmdlets/get-ciminstance?view=powershell-7.5  
> https://github.com/fastfetch-cli/fastfetch  
> https://github.com/dylanaraps/neofetch

# Explorer Blur

Installs [ExplorerBlurMica](https://github.com/Maplespe/ExplorerBlurMica), which adds a background blur/acrylic/mica effect effect to the explorer:

![](https://github.com/5Noxi/win-config/blob/main/misc/images/explorerblur.png?raw=true)

## Configuration

Open `%LOCALAPPDATA%\Noverse\ExplorerBlur\Release` - `config.ini`:

```ini
[config]
; Effect type 
; 0 = Blur 
; 1 = Acrylic 
; 2 = Mica 
; 3 = Blur(Clear) 
; 4 =MicaAlt
; Blur is only available up to W11 22h2, Blur (Clear) is available in both W10 and W11, Mica is only available in W11.
effect=1

; Clear the background of the address bar.
clearAddress=true

; Clear the background color of the scrollbar.
; Note: Since the system scrollbar itself has a background color that cannot be removed, when this option is turned on, the scrollbar is drawn by the program and the style may be different from the system.
clearBarBg=true

; Remove the toolbar background color from the WinUI or XamlIslands section of Windows 11.
clearWinUIBg=true

; Show split line between TreeView and DUIView.
showLine=true

[light]
; The system color scheme is the color in Light mode.
; RGBA component of background blend color
r=220
g=220
b=220
a=160
[dark]
; The system color scheme is the color in Dark mode.
r=0
g=0
b=0
a=120
```

# Notepad++

You can either change it yourself in:
```
HKCR\batfile\shell\edit\command
```
or use the option switch, which selects [notepad++](https://notepad-plus-plus.org/downloads/) as default editor.

# StartAllBack Settings

Installation:
```powershell
winget install StartIsBack.StartAllBack --scope machine
```

Disable Windows search via [`System > Disable Windows Search`](https://github.com/5Noxi/win-config/blob/main/system/desc.md#disable-windows-search)

All `StartAllBackCfg.exe` settings, which I currently use:

![](https://github.com/5Noxi/win-config/blob/main/system/images/startallback.png?raw=true)

All values `StartAllBack` reads that are located in `HKCU\Software\StartIsBack` (after clicking on `Properties`):
```powershell
"HKCU\Software\StartIsBack\CompactMenus","Length: 16"
"HKCU\Software\StartIsBack\Language","Length: 12"
"HKCU\Software\StartIsBack\Disabled","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\AlterStyle","Length: 12"
"HKCU\Software\StartIsBack\AlterStyle","Type: REG_SZ, Length: 2, Data: "
"HKCU\Software\StartIsBack\Start_LargeAllAppsIcons","Length: 12"
"HKCU\Software\StartIsBack\Start_LargeAllAppsIcons","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\AllProgramsFlyout","Length: 12"
"HKCU\Software\StartIsBack\AllProgramsFlyout","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\StartMetroAppsFolder","Length: 12"
"HKCU\Software\StartIsBack\StartMetroAppsFolder","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\Start_SortOverride","Length: 12"
"HKCU\Software\StartIsBack\Start_SortOverride","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_NotifyNewApps","Length: 12"
"HKCU\Software\StartIsBack\Start_NotifyNewApps","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_AutoCascade","Length: 12"
"HKCU\Software\StartIsBack\Start_AutoCascade","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_LargeSearchIcons","Length: 12"
"HKCU\Software\StartIsBack\Start_LargeSearchIcons","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_AskCortana","Length: 12"
"HKCU\Software\StartIsBack\Start_AskCortana","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\HideUserFrame","Length: 12"
"HKCU\Software\StartIsBack\HideUserFrame","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\Start_RightPaneIcons","Length: 12"
"HKCU\Software\StartIsBack\Start_RightPaneIcons","Type: REG_DWORD, Length: 4, Data: 2"
"HKCU\Software\StartIsBack\Start_ShowUser","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowMyDocs","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowMyDocs","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\Start_ShowMyPics","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowMyPics","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowMyMusic","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowMyMusic","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowVideos","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowDownloads","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowDownloads","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowSkyDrive","Length: 12"
"HKCU\Software\StartIsBack\StartMenuFavorites","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowRecentDocs","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowRecentDocs","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowNetPlaces","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowNetPlaces","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowNetConn","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowNetConn","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowMyComputer","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowMyComputer","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowControlPanel","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowControlPanel","Type: REG_DWORD, Length: 4, Data: 2"
"HKCU\Software\StartIsBack\Start_ShowPCSettings","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowPCSettings","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\Start_AdminToolsRoot","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowPrinters","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowPrinters","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowSetProgramAccessAndDefaults","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowSetProgramAccessAndDefaults","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowTerminal","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowCommandPrompt","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowCommandPrompt","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\Start_ShowRun","Length: 12"
"HKCU\Software\StartIsBack\Start_ShowRun","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\WinkeyFunction","Length: 16"
"HKCU\Software\StartIsBack\Start_MinMFU","Type: REG_DWORD, Length: 4, Data: 13"
"HKCU\Software\StartIsBack\Start_LargeMFUIcons","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\TaskbarStyle","Length: 12"
"HKCU\Software\StartIsBack\TaskbarStyle","Type: REG_SZ, Length: 32, Data: Plain8.msstyles"
"HKCU\Software\StartIsBack\OrbBitmap","Length: 12"
"HKCU\Software\StartIsBack\LegacyTaskbar","Length: 16"
"HKCU\Software\StartIsBack\TaskbarSpacierIcons","Type: REG_DWORD, Length: 4, Data: 4294967295"
"HKCU\Software\StartIsBack\TaskbarLargerIcons","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\TaskbarOneSegment","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\TaskbarCenterIcons","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\FatTaskbar","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\TaskbarGrouping","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\TaskbarTranslucentEffect","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\FrameStyle","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\NavBarGlass","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\OldSearch","Length: 16"
"HKCU\Software\StartIsBack\DriveGrouping","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\NoXAMLMenus","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\BottomDetails","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\RestyleControls","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\UndeadControlPanel","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\RestyleIcons","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\StartMenuColor","Length: 16"
"HKCU\Software\StartIsBack\StartMenuAlpha","Length: 16"
"HKCU\Software\StartIsBack\StartMenuBlur","Length: 16"
"HKCU\Software\StartIsBack\TaskbarColor","Length: 16"
"HKCU\Software\StartIsBack\TaskbarAlpha","Length: 16"
"HKCU\Software\StartIsBack\TaskbarBlur","Length: 16"
"HKCU\Software\StartIsBack\DarkMagic","Length: 16"
"HKCU\Software\StartIsBack\DarkMagic\Unround","Length: 16"
"HKCU\Software\StartIsBack\SysTrayStyle","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\SysTrayLocation","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\SysTrayMicrophone","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\SysTrayVolume","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\SysTrayNetwork","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\SysTrayPower","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\SysTrayInputSwitch","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\TaskbarControlCenter","Type: REG_DWORD, Length: 4, Data: 0"
"HKCU\Software\StartIsBack\SysTraySpacierIcons","Type: REG_DWORD, Length: 4, Data: 1"
"HKCU\Software\StartIsBack\MinimalSecondarySysTray","Length: 16"
"HKCU\Software\StartIsBack\DarkMagicDLL","Length: 16"
"HKCU\Software\StartIsBack\NoDarkRun","Length: 16"
"HKCU\Software\StartIsBack\JumpListBorder","Length: 16"
```

# System Informer

Since system informer is a lot better than the default task manager, it is recommended to replace it.

> https://systeminformer.io/

Undo it by removing the first line and executing the second command (delete the `::`), or just paste the second one in cmd.

Enable `Theme support` (dark mode) and disable `Check for updates automatically` with:
```powershell
(gc "$env:appdata\SystemInformer\settings.xml") -replace '(?<=<setting name="ProcessHacker\.UpdateChecker\.PromptStart">)\d(?=</setting>)','0' -replace '(?<=<setting name="EnableThemeSupport">)\d(?=</setting>)','1' | sc "$appdata\SystemInformer\settings.xml"
```

# Registry Finder

An improved editor that supports dark mode, a far better `Find` tool, and much more. 

Installation:
```powershell
winget install SergeyFilippov.RegistryFinder
```

> https://registry-finder.com

# 7-Zip Settings

7-Zip minimal context menu settings:

![](https://github.com/5Noxi/win-config/blob/main/misc/images/7z-folder.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/misc/images/7z-archive.png?raw=true)

All *context menu items* are getting handled via `ContextMenu` (`HKCU\Software\7-Zip\Options`).

```c
// Cascaded context menu, 1 = enabled, 0 = disabled
7zFM.exe	RegSetValue	HKCU\Software\7-Zip\Options\CascadedMenu	Type: REG_DWORD, Length: 4, Data: 1

// Eliminate dublication of root folders, 1 = enabled, 0 = disabled
7zFM.exe	RegSetValue	HKCU\Software\7-Zip\Options\ElimDupExtract	Type: REG_DWORD, Length: 4, Data: 1

// Icons in context menu, 1 = enabled, 0 = disabled
7zFM.exe	RegSetValue	HKCU\Software\7-Zip\Options\MenuIcons	Type: REG_DWORD, Length: 4, Data: 1

// Propagate Zone.Id stream, delete = * No, 1 = Yes, 2 = For Office files
7zFM.exe	RegSetValue	HKCU\Software\7-Zip\Options\WriteZoneIdExtract	Type: REG_DWORD, Length: 4, Data: 1
```

A decent replacement would be NanaZip:
```powershell
winget install M2Team.NanaZip
```
> https://github.com/M2Team/NanaZip

# Disable VSC Telemetry

**Caution:** The revert currently deletes `settings.json`. Means any settings you used beside the ones which get applied using this option will get removed.

Stops VSC to send telemetry, crash reports, disable online experiments, turn off automatic updates (manual updates), prevent fetching release notes, stop automatic extension and git repository updates, limit extension recommendations to on demand requests, and block fetching package information from online sources like NPM or Bower.
```ts
export const enum TelemetryLevel {
	NONE = 0,
	CRASH = 1,
	ERROR = 2,
	USAGE = 3
}
```
```json
"config.autofetch": "When set to true, commits will automatically be fetched from the default remote of the current Git repository. Setting to `all` will fetch from all remotes.",
```
```json
"config.npm.fetchOnlinePackageInfo": "Fetch data from https://registry.npmjs.org and https://registry.bower.io to provide auto-completion and information on hover features on npm dependencies.",
```
```ts
'update.mode': {
	enum: ['none', 'manual', 'start', 'default'],
	description: localize('updateMode', "Configure whether you receive automatic updates. Requires a restart after change. The updates are fetched from a Microsoft online service."),
	enumDescriptions: [
		localize('manual', "Disable automatic background update checks. Updates will be available if you manually check for updates."),
```
> https://github.com/microsoft/vscode/blob/274d71002ec805c8b4f61ade3f058dd3cac1aceb/src/vs/workbench/contrib/extensions/common/extensions.ts#L185  
> https://github.com/microsoft/vscode/blob/274d71002ec805c8b4f61ade3f058dd3cac1aceb/extensions/git/package.nls.json#L155  
> https://github.com/microsoft/vscode/blob/274d71002ec805c8b4f61ade3f058dd3cac1aceb/extensions/npm/package.nls.json#L26  
> https://github.com/microsoft/vscode/blob/274d71002ec805c8b4f61ade3f058dd3cac1aceb/src/vs/platform/telemetry/common/telemetry.ts#L83  
> https://github.com/microsoft/vscode/blob/274d71002ec805c8b4f61ade3f058dd3cac1aceb/src/vs/workbench/services/assignment/common/assignmentService.ts#L110

# Disable VS Telemetry

Disables VS telemetry, SQM data collection, IntelliCode remote analysis, feedback features, and the `DiagnosticsHub` logger. Disabling `VSStandardCollectorService150` could cause issues, I added it as a comment.

```powershell
"14.0" = "VS 2015"
"15.0" = "VS 2017" 
"16.0" = "VS 2019"
"17.0" = "VS 2022"
```
Remove VS logs, telemetry & feedback data:
```bat
for %%p in (
 "%APPDATA%\vstelemetry"
 "%LOCALAPPDATA%\Microsoft\VSApplicationInsights"
 "%LOCALAPPDATA%\Microsoft\VSCommon\14.0\SQM"
 "%LOCALAPPDATA%\Microsoft\VSCommon\15.0\SQM"
 "%LOCALAPPDATA%\Microsoft\VSCommon\16.0\SQM"
 "%LOCALAPPDATA%\Microsoft\VSCommon\17.0\SQM"
 "%PROGRAMDATA%\Microsoft\VSApplicationInsights"
 "%PROGRAMDATA%\vstelemetry"
 "%TEMP%\Microsoft\VSApplicationInsights"
 "%TEMP%\Microsoft\VSFeedbackCollector"
 "%TEMP%\VSFaultInfo"
 "%TEMP%\VSFeedbackIntelliCodeLogs"
 "%TEMP%\VSFeedbackPerfWatsonData"
 "%TEMP%\VSFeedbackVSRTCLogs"
 "%TEMP%\VSRemoteControl"
 "%TEMP%\VSTelem"
 "%TEMP%\VSTelem.Out"
) do rd /s /q "%%~p"
```
Remove VS licenses (could cause the need of a reactivation):
```bat
for %%g in (
 "77550D6B-6352-4E77-9DA3-537419DF564B"
 "E79B3F9C-6543-4897-BBA5-5BFB0A02BB5C"
 "4D8CFBCB-2F6A-4AD2-BABF-10E28F6F2C8F"
 "5C505A59-E312-4B89-9508-E162F8150517"
 "41717607-F34E-432C-A138-A3CFD7E25CDA"
 "1299B4B9-DFCC-476D-98F0-F65A2B46C96D"
) do reg delete "HKLM\SOFTWARE\Classes\Licenses\%%~g" /f
```
> https://github.com/jedipi/Visual-Studio-Key-Finder/blob/main/src/VsKeyFinder/Data/ProductData.cs

---

Miscellaneous notes:
```json
"HKLM\\SOFTWARE\\Policies\\Microsoft\\VisualStudio\\Feedback": {
  "DisableEmailInput": { "Type": "REG_DWORD", "Data": 1 },
  "DisableFeedbackDialog": { "Type": "REG_DWORD", "Data": 1 },
  "DisableScreenshotCapture": { "Type": "REG_DWORD", "Data": 1 }
},
"HKLM\\SOFTWARE\\Microsoft\\VSCommon\\14.0\\SQM": {
  "OptIn": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\VSCommon\\15.0\\SQM": {
  "OptIn": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\VSCommon\\16.0\\SQM": {
  "OptIn": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\VSCommon\\17.0\\SQM": {
  "OptIn": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\VSStandardCollectorService150": {
  "Start": { "Type": "REG_DWORD", "Data": 4 }
}
```

# Disable MS Office Telemetry

Disables logging, data collection, opts out from CEIP, disables feedback collection and telemetry agent tasks.

| Category                                     | Where it appears | What the agent collects (by default)                                                                                                    | Scope / Versions                                                | Notes & Exceptions                                                                                                                                                                       |
| -------------------------------------------- | -------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Recently opened documents & templates        | Documents                              | File name; file format/extension; total users; number of Office users/sessions                                                          | Office 2003–2019/2016 (agent supports multiple Office versions) | For network/SharePoint files: only file name + location. If MRU is disabled, no document inventory is collected. Outlook: no document inventory. OneNote: only notebook name + location. |
| Document details                             | Document details                       | User name; computer name; location (path/URL); size (KB); author; last loaded; title; Office version                                    | Office 2003–2019/2016                                           | Same exceptions as above (MRU off, Outlook, OneNote, network/SharePoint).                                                                                                                |
| Recently loaded add-ins & Apps for Office    | Solutions                              | Solution name; total users; number of Office users                                                                                      | Office 2003–2019/2016                                           | -                                                                                                                                                                                        |
| Add-in / App details                         | Solution details                       | User name; computer name; solution version; architecture (x86/x64/ARM); load time; description; size (KB); location (DLL/manifest path) | Office 2003–2019/2016                                           | -                                                                                                                                                                                        |
| User data (agents)                           | Agents                                 | User name; level (telemetry level); computer; last updated; label (1–4); agent version                                                  | All supported                                                   | -                                                                                                                                                                                        |
| Hardware & software inventory (per computer) | Telemetry Processor                    | Computer name; level; users; computers; last updated (date/time)                                                                        | All supported                                                   | -                                                                                                                                                                                        |
| Office deployment mix                        | Deployments                            | Office versions; # of 32-bit deployments; # of 64-bit deployments; # of ARM deployments                                                 | All supported                                                   | -                                                                                                                                                                                        |
| Runtime document telemetry                   | Documents (runtime fields)             | Success (%); sessions; critical compatibility issue or crash; informative compatibility issue or load failure                           | Office 2013/2016/2019 (Excel/Outlook/PowerPoint/Word)           | Shown only after the app is run and documents/solutions are opened.                                                                                                                      |
| Runtime document internals                   | Document details (runtime fields)      | Last loaded (date/time); flags: Has VBA? Has OLE? Has external data connection? Has ActiveX control? Has assembly reference?            | Office 2013/2016/2019 (Excel/Outlook/PowerPoint/Word)           | VBA/OLE/data/ActiveX/assembly info is logged starting from the second open of the document.                                                                                              |
| Runtime document events                      | Document sessions                      | Date/time of critical or informative events                                                                                             | Office 2013/2016/2019 (Excel/Outlook/PowerPoint/Word)           | -                                                                                                                                                                                        |
| Runtime add-in telemetry                     | Solutions (runtime fields)             | Success (%); sessions; critical compatibility issue or crash; informative compatibility issue or load failure; load time                | Office 2013/2016/2019 (Excel/Outlook/PowerPoint/Word)           | Shown only after the add-in/app is loaded during runtime.                                                                                                                                |
| Runtime solution issues                      | Solution issues                        | Event ID; title; explanation; more info; users; sessions                                                                                | Office 2013/2016/2019 (Excel/Outlook/PowerPoint/Word)           | -                                                                                                                                                                                        |
| Not collected (by design)                    | -                                      | File contents; info about files not in MRU                                                                                              | All                                                             | Data for Office Telemetry Dashboard stays in your org's SQL Server; it is not sent to Microsoft. Office diagnostic data is separate and managed by different settings.                   |

---

`HKEY_CURRENT_USER\Software\Policies\Microsoft\Office\16.0\OSM\preventedapplications`

| Value Name        | Value Type | Value Description and Data                                                            |
| ----------------- | ---------- | ------------------------------------------------------------------------------------- |
| accesssolution    | REG_DWORD  | Prevents data for Access solutions from being reported to Office Telemetry Dashboard. |
| olksolution       | REG_DWORD  | Prevents data for Microsoft Outlook solutions.                                        |
| onenotesolution   | REG_DWORD  | Prevents data for OneNote solutions.                                                  |
| pptsolution       | REG_DWORD  | Prevents data for PowerPoint solutions.                                               |
| projectsolution   | REG_DWORD  | Prevents data for Project solutions.                                                  |
| publishersolution | REG_DWORD  | Prevents data for Publisher solutions.                                                |
| visiosolution     | REG_DWORD  | Prevents data for Visio solutions.                                                    |
| wdsolution        | REG_DWORD  | Prevents data for Word solutions.                                                     |
| xlsolution        | REG_DWORD  | Prevents data for Excel solutions.                                                    |

- `1` = Prevent reporting
- `0` = Allow reporting
- Default = `0` (Allow reporting)

---

`HKEY_CURRENT_USER\Software\Policies\Microsoft\Office\16.0\OSM\preventedsolutiontypes`

| Value Name    | Value Type | Value Description and Data                                                  |
| ------------- | ---------- | --------------------------------------------------------------------------- |
| agave         | REG_DWORD  | Prevents data for apps for Office.                                          |
| appaddins     | REG_DWORD  | Prevents data for application-specific add-ins like Excel, PowerPoint, etc. |
| comaddins     | REG_DWORD  | Prevents data for COM add-ins.                                              |
| documentfiles | REG_DWORD  | Prevents data for Office document files.                                    |
| templatefiles | REG_DWORD  | Prevents data for Office template files.                                    |

- `1` = Prevent reporting
- `0` = Allow reporting
- Default = `0` (Allow reporting)

> https://learn.microsoft.com/en-us/office/compatibility/data-that-the-telemetry-agent-collects-in-office  
> https://learn.microsoft.com/en-us/office/compatibility/manage-the-privacy-of-data-monitored-by-telemetry-in-office

# Disable OneDrive

`DisableLibrariesDefaultSaveToOneDrive` sets local storage as the default save location, `DisableFileSync` disables OneDrive on Windows 8.1 including app and picker access removal and stops sync and hides the Explorer entry, `DisableFileSyncNGSC` disables OneDrive via the Next-Gen Sync Client with the same effect, `DisableMeteredNetworkFileSync` set to `0` blocks syncing on all metered connections, `PreventNetworkTrafficPreUserSignIn` stops the OneDrive client from generating network traffic until the user signs in, `System.IsPinnedToNameSpaceTree` set to `0` hides OneDrive from File Explorer's navigation pane in both CLSID locations.

```json
{
  "File": "SkyDrive.admx",
  "CategoryName": "OneDrive",
  "PolicyName": "DisableLibrariesDefaultSaveToOneDrive",
  "NameSpace": "Microsoft.Policies.OneDrive",
  "Supported": "Windows_6_3only",
  "DisplayName": "Save documents to OneDrive by default",
  "ExplainText": "This policy setting lets you disable OneDrive as the default save location. It does not prevent apps and users from saving files on OneDrive. If you disable this policy setting, files will be saved locally by default. Users will still be able to change the value of this setting to save to OneDrive by default. They will also be able to open and save files on OneDrive using the OneDrive app and file picker, and packaged Microsoft Store apps will still be able to access OneDrive using the WinRT API. If you enable or do not configure this policy setting, users with a connected account will save documents to OneDrive by default.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\OneDrive"
  ],
  "ValueName": "DisableLibrariesDefaultSaveToOneDrive",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SkyDrive.admx",
  "CategoryName": "OneDrive",
  "PolicyName": "PreventOnedriveFileSyncForBlue",
  "NameSpace": "Microsoft.Policies.OneDrive",
  "Supported": "Windows_6_3only",
  "DisplayName": "Prevent the usage of OneDrive for file storage on Windows 8.1",
  "ExplainText": "This policy setting lets you prevent apps and features from working with files on OneDrive for Windows 8.1. If you enable this policy setting: * Users can\u2019t access OneDrive from the OneDrive app and file picker. * Packaged Microsoft Store apps can\u2019t access OneDrive using the WinRT API. * OneDrive doesn\u2019t appear in the navigation pane in File Explorer. * OneDrive files aren\u2019t kept in sync with the cloud. * Users can\u2019t automatically upload photos and videos from the camera roll folder. If you disable or do not configure this policy setting, apps and features can work with OneDrive file storage.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\OneDrive"
  ],
  "ValueName": "DisableFileSync",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SkyDrive.admx",
  "CategoryName": "OneDrive",
  "PolicyName": "PreventOnedriveFileSync",
  "NameSpace": "Microsoft.Policies.OneDrive",
  "Supported": "Windows7",
  "DisplayName": "Prevent the usage of OneDrive for file storage",
  "ExplainText": "This policy setting lets you prevent apps and features from working with files on OneDrive. If you enable this policy setting: * Users can\u2019t access OneDrive from the OneDrive app and file picker. * Packaged Microsoft Store apps can\u2019t access OneDrive using the WinRT API. * OneDrive doesn\u2019t appear in the navigation pane in File Explorer. * OneDrive files aren\u2019t kept in sync with the cloud. * Users can\u2019t automatically upload photos and videos from the camera roll folder. If you disable or do not configure this policy setting, apps and features can work with OneDrive file storage.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\OneDrive"
  ],
  "ValueName": "DisableFileSyncNGSC",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "SkyDrive.admx",
  "CategoryName": "OneDrive",
  "PolicyName": "PreventOneDriveFileSyncOnMeteredNetwork",
  "NameSpace": "Microsoft.Policies.OneDrive",
  "Supported": "Windows_6_3only",
  "DisplayName": "Prevent OneDrive files from syncing over metered connections",
  "ExplainText": "This policy setting allows configuration of OneDrive file sync behavior on metered connections.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\OneDrive"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "DisableMeteredNetworkFileSync", "Items": [
        { "DisplayName": "Block syncing on all metered connections", "Data": "0" },
        { "DisplayName": "Block syncing on metered connections only when roaming", "Data": "1" }
      ]
    }
  ]
},
{
  "File": "SkyDrive.admx",
  "CategoryName": "OneDrive",
  "PolicyName": "PreventNetworkTrafficPreUserSignIn",
  "NameSpace": "Microsoft.Policies.OneDrive",
  "Supported": "Windows7",
  "DisplayName": "Prevent OneDrive from generating network traffic until the user signs in to OneDrive",
  "ExplainText": "Enable this setting to prevent the OneDrive sync client (OneDrive.exe) from generating network traffic (checking for updates, etc.) until the user signs in to OneDrive or starts syncing files to the local computer. If you enable this setting, users must sign in to the OneDrive sync client on the local computer, or select to sync OneDrive or SharePoint files on the computer, for the sync client to start automatically. If this setting is not enabled, the OneDrive sync client will start automatically when users sign in to Windows. If you enable or disable this setting, do not return the setting to Not Configured. Doing so will not change the configuration and the last configured setting will remain in effect.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Microsoft\\OneDrive"
  ],
  "ValueName": "PreventNetworkTrafficPreUserSignIn",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Edge Features

Edge is a whole mess, I wouldn't recommend anyone to use it, but here's an option that applies the following values:

| Value | Disables / Hides |
| ----- | ----- |
| `AutoImportAtFirstRun` | Auto-import from other browsers at first run |
| `PersonalizationReportingEnabled` | Personalization (ads, news, browser suggestions) |
| `ShowRecommendationsEnabled` | Recommendations and desktop notifications |
| `HideFirstRunExperience` | First-run experience |
| `PinBrowserEssentialsToolbarButton` | Browser Essentials toolbar button |
| `DefaultBrowserSettingEnabled` | "Set Edge as default browser” prompts |
| `EdgeFollowEnabled` | Follow creators |
| `HubsSidebarEnabled` | Sidebar |
| `StandaloneHubsSidebarEnabled` | Standalone Sidebar |
| `SyncDisabled` | Sync (all kinds of data) |
| `HideRestoreDialogEnabled` | Restore pages dialog after crash |
| `EdgeShoppingAssistantEnabled` | Shopping features |
| `ShowMicrosoftRewards` | Microsoft Rewards |
| `QuickSearchShowMiniMenu` | Mini context menu (quick search) |
| `ImplicitSignInEnabled` | Implicit sign-in with Microsoft account |
| `EdgeCollectionsEnabled` | Collections |
| `SplitScreenEnabled` | Split screen |
| `UserFeedbackAllowed` | User feedback prompts |
| `SearchbarAllowed` | Floating Bing search bar |
| `StartupBoostEnabled` | Startup Boost |
| `NewTabPageHideDefaultTopSites` | Microsoft's default pinned sites on New Tab |
| `NewTabPageQuickLinksEnabled` | Quick links on New Tab |
| `NewTabPageAllowedBackgroundTypes` | New Tab background image (restricts types) |
| `NewTabPageContentEnabled` | Microsoft content on New Tab (news, highlights, etc.) |
| `DisableHelpSticker` | Windows help tips ("help stickers”) |
| `DisableMFUTracking` | Tracking of most-frequently-used apps |
| `DisableRecentApps` | Recent apps UI in upper-left corner |
| `DisableCharms` | Charms UI in upper-right corner |
| `TurnOffBackstack` | Switching between recent apps (backstack) |
| `AllowEdgeSwipe` | Edge swipe gestures (set to 0 to disable) |
| `TabServicesEnabled` | Tab-related background services (e.g., shopping/price tracking helpers) disabled |
| `TextPredictionEnabled` | Text predictions will not be provided in eligible text fields |
| `TrackingPrevention` | Tracking Prevention mode enforced |
| `DefaultSensorsSetting` | Site access to  sensors blocked |

See all edge policies here:

> https://learn.microsoft.com/en-us/deployedge/microsoft-edge-policies

```json
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "TurnOffBackstack",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows8",
  "DisplayName": "Turn off switching between recent apps",
  "ExplainText": "If you enable this setting, users will not be allowed to switch between recent apps. The App Switching option in the PC settings app will be disabled as well. If you disable or do not configure this policy setting, users will be allowed to switch between recent apps.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "TurnOffBackstack",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "DisableMFUTracking",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows8",
  "DisplayName": "Turn off tracking of app usage",
  "ExplainText": "This policy setting prevents Windows from keeping track of the apps that are used and searched most frequently. If you enable this policy setting, apps will be sorted alphabetically in: - search results - the Search and Share panes - the drop-down app list in the Picker If you disable or don't configure this policy setting, Windows will keep track of the apps that are used and searched most frequently. Most frequently used apps will appear at the top.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "DisableMFUTracking",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "DisableRecentApps",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows_6_3",
  "DisplayName": "Do not show recent apps when the mouse is pointing to the upper-left corner of the screen",
  "ExplainText": "This policy setting allows you to prevent the last app and the list of recent apps from appearing when the mouse is pointing to the upper-left corner of the screen. If you enable this policy setting, the user will no longer be able to switch to recent apps using the mouse. The user will still be able to switch apps using touch gestures, keyboard shortcuts, and the Start screen. If you disable or don't configure this policy setting, the recent apps will be available by default, and the user can configure this setting.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "DisableRecentApps",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "DisableCharms",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows_6_3",
  "DisplayName": "Search, Share, Start, Devices, and Settings don't appear when the mouse is pointing to the upper-right corner of the screen",
  "ExplainText": "This policy setting allows you to prevent Search, Share, Start, Devices, and Settings from appearing when the mouse is pointing to the upper-right corner of the screen. If you enable this policy setting, Search, Share, Start, Devices, and Settings will no longer appear when the mouse is pointing to the upper-right corner. They'll still be available if the mouse is pointing to the lower-right corner. If you disable or don't configure this policy setting, Search, Share, Start, Devices, and Settings will be available by default, and the user can configure this setting.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "DisableCharms",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "DisableHelpSticker",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows_6_3",
  "DisplayName": "Disable help tips",
  "ExplainText": "Disables help tips that Windows shows to the user. By default, Windows will show the user help tips until the user has successfully completed the scenarios. If this setting is enabled, Windows will not show any help tips to the user.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\EdgeUI",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "DisableHelpSticker",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "EdgeUI.admx",
  "CategoryName": "EdgeUI",
  "PolicyName": "AllowEdgeSwipe",
  "NameSpace": "Microsoft.Policies.EdgeUI",
  "Supported": "Windows_10_0",
  "DisplayName": "Allow edge swipe",
  "ExplainText": "If you disable this policy setting, users will not be able to invoke any system UI by swiping in from any screen edge. If you enable or do not configure this policy setting, users will be able to invoke system UI by swiping in from the screen edges.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\EdgeUI",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\EdgeUI"
  ],
  "ValueName": "AllowEdgeSwipe",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```
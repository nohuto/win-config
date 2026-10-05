# RegKit

## Table of Content

- [Differences to Native RegEdit](https://github.com/nohuto/regkit#differences-to-native-regedit)
- [Theme Presets](https://github.com/nohuto/regkit#theme-presets)
- [Icon Sets](https://github.com/nohuto/regkit#icon-sets)
  - [Previews](https://github.com/nohuto/regkit#previews)
- [Icon Meanings](https://github.com/nohuto/regkit#icon-meanings)
  - [Symlink Icon](https://github.com/nohuto/regkit#symlink-icon-)
  - [Database Icon](https://github.com/nohuto/regkit#database-icon-)
  - [Simulated Key Icon](https://github.com/nohuto/regkit#simulated-key-icon-)
- [Bit Definitions](https://github.com/nohuto/regkit#bit-definitions)
- [Trace Menu](https://github.com/nohuto/regkit#trace-menu)
- [Default Menu](https://github.com/nohuto/regkit#default-menu)
- [Rights and Elevation](https://github.com/nohuto/regkit#rights-and-elevation)
- [Keyboard Shortcuts](https://github.com/nohuto/regkit#keyboard-shortcuts)
- [Command Line](https://github.com/nohuto/regkit#command-line)
- [Registry Fundamentals](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/)
  - [Root Keys & `\REGISTRY`](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#root-keys--registry)
  - [`\REGISTRY` Only Keys](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#registry-only-keys)
  - [Value Types](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#value-types)
  - [Key Handles](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#key-handles)
  - [Predefined Keys](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#predefined-keys)
  - [Hives & On-Disk Files](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/#hives--on-disk-files)

More info can be found in the repo: https://github.com/nohuto/regkit

# NVFetch

Used to be my personal [`neofetch`](https://github.com/dylanaraps/neofetch)/[`fastfetch`](https://github.com/fastfetch-cli/fastfetch) replacement with more details. Some arguments will probably also get added like `ids`, so it doesn't display the serial numbers and miscellaneous HWIDs by default.

![](https://github.com/nohuto/win-config/blob/main/misc/images/nvfetch.png?raw=true)

> https://github.com/nohuto/nvfetch

It currently gets most of the information using the [`Get-CimInstance`](https://learn.microsoft.com/en-us/powershell/module/cimcmdlets/get-ciminstance?view=powershell-7.5) cmdlet and [`nvidia-smi`](https://docs.nvidia.com/deploy/nvidia-smi/index.html) for NVIDIA GPUs.
```powershell
nvidia-smi -q
```
[`nvfetch-win32cimv2.txt`](https://github.com/nohuto/win-config/blob/main/misc/assets/nvfetch-win32cimv2.txt) shows class names in the `root\CIMV2` namespace, filtered with `Win32*`.

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

# Explorer Blur

Installs [ExplorerBlurMica](https://github.com/Maplespe/ExplorerBlurMica), which adds a background blur/acrylic/mica effect effect to the explorer:

![](https://github.com/nohuto/win-config/blob/main/misc/images/explorerblur.png?raw=true)

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

# StartAllBack Config

Installation:
```powershell
winget install StartIsBack.StartAllBack --scope machine
```

Disable Windows search via [`System > Disable Windows Search`](https://github.com/nohuto/win-config/blob/main/system/desc.md#disable-windows-search)

All `StartAllBackCfg.exe` settings, which I currently use:

![](https://github.com/nohuto/win-config/blob/main/misc/images/startallback.png?raw=true)

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

## SAB Activation

**This is for educational purposes only.**

Disassemble `StartAllBackX64.dll`, jump to `StartAllBackX64_102` > Edit > Patch program > Change byte

From:
```asm
mov [rsp+8], rbx
push rbp
push rsi
push rdi
lea rbp, [rsp-90h]
```
`48 89 5C 24 08 55 56 57 48 8D AC 24 70 FF FF FF`

To:
```asm
mov dword ptr [ecx], 1
mov eax, 1
ret
nop
```
`67 C7 01 01 00 00 00 B8 01 00 00 00 C3 90 90 90`

Edit > Patch program > Apply patches to input file.

This causes skipping `ActivationData` and returning result `1`:
```c
// before patch
__int64 StartAllBackX64_102()
{
  __int64 result; // rax
  unsigned int v1; // ebx
  HKEY v2; // rdi
  BYTE Data[128]; // [rsp+30h] [rbp-D0h] BYREF
  CHAR String1[112]; // [rsp+B0h] [rbp-50h] BYREF
  CHAR Buf2[128]; // [rsp+120h] [rbp+20h] BYREF
  DWORD cbData; // [rsp+1B8h] [rbp+B8h] BYREF
  HKEY hKey; // [rsp+1C0h] [rbp+C0h] BYREF

  result = StartAllBackX64_103(Buf2);
  v1 = 0;
  v2 = (HKEY)result;
  if ( result )
  {
    memset(Data, 0, sizeof(Data));
    cbData = 128;
    RegOpenKeyExA(v2, "Software\\StartIsBack\\License", 0, 0x101u, &hKey);
    lstrcpyA(String1, "ActivationData");
    if ( RegQueryValueExA(hKey, String1, 0LL, 0LL, Data, &cbData) )
    {
      RegCloseKey(hKey);
    }
    else
    {
      RegCloseKey(hKey);
      return (unsigned __int8)sub_180001E8C(Data, Buf2);
    }
    return v1;
  }
  return result;
}

// after patch
__int64 __fastcall StartAllBackX64_102(_DWORD *a1)
{
  __int64 result; // rax

  result = 1LL;
  *a1 = 1;
  return result;
}
```

# System Informer

Since [system informer](https://systeminformer.io/) is a lot better than the default task manager, it's recommended to replace it. It e.g. uses the clock cycle counter instead of the clock interval timer (which the normal taskmanager uses), which would show CPU consumption of threads that have such a short execution time that task manager would show them as `0%`.

Enable `Theme support` (dark mode) and disable `Check for updates automatically` with:
```powershell
(gc "$env:appdata\SystemInformer\settings.xml") -replace '(?<=<setting name="ProcessHacker\.UpdateChecker\.PromptStart">)\d(?=</setting>)','0' -replace '(?<=<setting name="EnableThemeSupport">)\d(?=</setting>)','1' | sc "$appdata\SystemInformer\settings.xml"
```

# 7-Zip Settings

7-Zip minimal context menu settings (if cascaded context menu enabled):

![](https://github.com/nohuto/win-config/blob/main/misc/images/7z-folder.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/misc/images/7z-archive.png?raw=true)

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

A decent replacement would be [NanaZip](https://github.com/M2Team/NanaZip).

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
Remove [VS licenses](https://github.com/jedipi/Visual-Studio-Key-Finder/blob/main/src/VsKeyFinder/Data/ProductData.cs) (could cause the need of a reactivation):
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

## [Registry Values](https://learn.microsoft.com/en-us/office/compatibility/manage-the-privacy-of-data-monitored-by-telemetry-in-office#to-configure-exclusion-settings-by-using-the-registry)

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

# OneDrive

See the Windows Policies table below for policy links and registry details.

Uninstall runs `OneDriveSetup.exe /uninstall` and removes leftovers:
```c
// paths
%LOCALAPPDATA%\Microsoft\OneDrive
%LOCALAPPDATA%\OneDrive
%PROGRAMDATA%\Microsoft OneDrive
%SYSTEMDRIVE%\OneDriveTemp
%APPDATA%\Microsoft\Windows\Start Menu\Programs\OneDrive.lnk
// if empty
%USERPROFILE%\OneDrive

// registry keys/values
HKCU\Environment : OneDrive
HKCU\Software\RegisteredApplications : OneDrive
HKCU\Software\Microsoft\Windows\CurrentVersion\Run\AutorunsDisabled : OneDrive
HKCU\Software\Microsoft\OneDrive
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\StorageProvider\OneDrive
HKLM\SOFTWARE\Microsoft\OneDrive
HKLM\SOFTWARE\WOW6432Node\Policies\Microsoft\Windows\OneDrive

// scheduled tasks
\\OneDrive*
```

## [Windows Policies](https://noverse.dev/policies)

All other OneDrive related policies are used in `Windows_6_3only - Windows Server 2012 R2, Windows 8.1 or Windows RT 8.1 only`, which is why I won't include them.

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent the usage of OneDrive for file storage](https://noverse.dev/policies?p=SkyDrive*PreventOnedriveFileSync) | `HKLM\Software\Policies\Microsoft\Windows\OneDrive` | `DisableFileSyncNGSC` |
| [Prevent OneDrive from generating network traffic until the user signs in to OneDrive](https://noverse.dev/policies?p=SkyDrive*PreventNetworkTrafficPreUserSignIn) | `HKLM\SOFTWARE\Microsoft\OneDrive` | `PreventNetworkTrafficPreUserSignIn` |

# Hash Generator

> "*The `Get-FileHash` cmdlet computes the hash value for a file by using a specified hash algorithm. A hash value is a unique value that corresponds to the content of the file. Rather than identifying the contents of a file by its file name, extension, or other designation, a hash assigns a unique value to the contents of a file. File names and extensions can be changed without altering the content of the file, and without changing the hash value. Similarly, the file's content can be changed without changing the name or extension. However, changing even a single character in the contents of a file changes the hash value of the file.*
>
> *The purpose of hash values is to provide a cryptographically-secure way to verify that the contents of a file have not been changed. While some hash algorithms, including MD5 and SHA1, are no longer considered secure against attack, the goal of a secure hash algorithm is to render it impossible to change the contents of a file either by accident, or by malicious or unauthorized attempt and maintain the same hash value. You can also use hash values to determine if two different files have exactly the same content. If the hash values of two files are identical, the contents of the files are also identical.*"
>
> — Microsoft, [Get-FileHash](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/get-filehash?view=powershell-7.5)

![](https://github.com/nohuto/win-config/blob/main/misc/images/hashgen.png?raw=true)

## Algorithms

`Get-FileHash -Algorithm` accepts (the script uses the built in .NET hash implementations `System.Security.Cryptography`):

- [`MD5`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.md5?view=net-9.0) (`128` Bits)
- [`SHA1`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha1?view=net-9.0) (`160` Bits)
- [`SHA256`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha256?view=net-9.0) (`256` Bits)
- [`SHA384`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha384?view=net-9.0) (`384` Bits)
- [`SHA512`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha512?view=net-9.0) (`512` Bits)
- [`MACTripleDES`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.mactripledes?view=net-9.0)
- [`RIPEMD160`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.ripemd160?view=net-9.0)

## Hash Examples

The computed hash depends on the file content. With the same algorithm, identical inputs (including empty files) have identical hashes.

### Scenario 1 (no content)

```powershell
PS C:\Users\Nohuxi> Get-Content -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse0.txt' -Raw
PS C:\Users\Nohuxi> # No output, since empty

PS C:\Users\Nohuxi> 'MD5','SHA1','SHA256','SHA384','SHA512' | % { '{0}: {1}' -f $_,(Get-FileHash -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse0.txt' -Algorithm $_).Hash }
MD5: D41D8CD98F00B204E9800998ECF8427E
SHA1: DA39A3EE5E6B4B0D3255BFEF95601890AFD80709
SHA256: E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855
SHA384: 38B060A751AC96384CD9327EB1B1E36A21FDB71114BE07434C0CC7BF63F6E1DA274EDEBFE76F65FBD51AD2F14898B95B
SHA512: CF83E1357EEFB8BDF1542850D66D8007D620E4050B5715DC83F4A921D36CE9CE47D0D13C5D85F2B0FF8318D2877EEC2F63B931BD47417A81A538327AF927DA3E
```

###  Scenario 2 (content)

```powershell
PS C:\Users\Nohuxi> Get-Content -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse1.txt' -Raw
1 # Content
PS C:\Users\Nohuxi>

PS C:\Users\Nohuxi> 'MD5','SHA1','SHA256','SHA384','SHA512' | % { '{0}: {1}' -f $_,(Get-FileHash -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse1.txt' -Algorithm $_).Hash }
MD5: C4CA4238A0B923820DCC509A6F75849B
SHA1: 356A192B7913B04C54574D18C28D46E6395428AB
SHA256: 6B86B273FF34FCE19D6B804EFF5A3F5747ADA4EAA22F1D49C01E52DDB7875B4B
SHA384: 47F05D367B0C32E438FB63E6CF4A5F35C2AA2F90DC7543F8A41A0F95CE8A40A313AB5CF36134A2068C4C969CB50DB776
SHA512: 4DFF4EA340F0A823F15D3F4F01AB62EAE0E5DA579CCB851F8DB9DFE84C58B2B37B89903A740E1EE172DA793A6E79D560E5F7F9BD058A12A280433ED6FA46510A
```

As you can see, adding a `1` to the file content has completely changed the hash values. You can try this yourself by editing the paths.

```powershell
MD5("") 
0x d41d8cd98f00b204e9800998ecf8427e
SHA1("")
0x da39a3ee5e6b4b0d3255bfef95601890afd80709
SHA256("")
0x e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
SHA384("")
0x 38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b
SHA512("")
0x cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e
```

## Installation

If using win-config, then the toggle automates the (un)installation.

- [`HashGen.ps1`](https://github.com/nohuto/win-config/blob/main/misc/assets/HashGen.ps1) accepts an optional `-Algorithm` parameter (`All`, `MD5`, `SHA1`, `SHA256`, `SHA384`, `SHA512`, `MACTripleDES`, `RIPEMD160`). By default it runs every available algorithm, but you can target a specific hash when invoking it manually. 
- [`Add-CM.ps1`](https://github.com/nohuto/win-config/blob/main/misc/assets/Add-CM.ps1) will add a `Hashes` cascaded option to the context menu of any file/folder (if selecting a folder all files within the folder and every subfolder will get used). `HashGen.ps1` gets used from your `Downloads` folder if present, otherwise `Add-CM.ps1` automatically downloads the latest copy from GitHub. `Add-CM.ps1` copies `HashGen.ps1` into `%LOCALAPPDATA%\Noverse` and adds a *Hashes* entry for files and folders.

## Uninstallation

Remove the content menu entry and `hashGen` with:
```powershell
Remove-Item -LiteralPath "HKCU:\Software\Classes\*\shell\Hashes" -Recurse -Force
Remove-Item -LiteralPath "HKCU:\Software\Classes\Directory\shell\Hashes" -Recurse -Force
Remove-Item -LiteralPath "HKCU:\Software\Classes\hashGen.ContextMenu" -Recurse -Force
#Remove-Item -LiteralPath "HKCU:\Software\Classes\*\shell\NV-Hash" -Recurse -Force  # old entry
#Remove-Item -LiteralPath "HKCU:\Software\Classes\Directory\shell\NV-Hash" -Recurse -Force  # old entry
Remove-Item -Path "$env:LOCALAPPDATA\Noverse\HashGen.ps1" -Force
```

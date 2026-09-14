# Explorer Options

It changes every setting which is shown in the `Folder Options` window, and more explorer related things. Some are personal preference, see suboptions below for customization, and configurations that aren't made in the main option.

![](https://github.com/nohuto/win-config/blob/main/visibility/images/explorer.png?raw=true)

## ShellState

`ShellState` is a little endian `REG_BINARY`, its data starts with a `DWORD` followed by the 32 byte [`SHELLSTATE`](https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/ns-shlobj_core-shellstatea) structure.

```cpp
typedef struct {
  BOOL  fShowAllObjects : 1;
  BOOL  fShowExtensions : 1;
  BOOL  fNoConfirmRecycle : 1;
  BOOL  fShowSysFiles : 1;
  BOOL  fShowCompColor : 1;
  BOOL  fDoubleClickInWebView : 1;
  BOOL  fDesktopHTML : 1;
  BOOL  fWin95Classic : 1;
  BOOL  fDontPrettyPath : 1;
  BOOL  fShowAttribCol : 1;
  BOOL  fMapNetDrvBtn : 1;
  BOOL  fShowInfoTip : 1;
  BOOL  fHideIcons : 1;
  BOOL  fWebView : 1;
  BOOL  fFilter : 1;
  BOOL  fShowSuperHidden : 1;
  BOOL  fNoNetCrawling : 1;
  DWORD dwWin95Unused;
  UINT  uWin95Unused;
  LONG  lParamSort;
  int   iSortDirection;
  UINT  version;
  UINT  uNotUsed;
  BOOL  fSepProcess : 1;
  BOOL  fStartPanelOn : 1;
  BOOL  fShowStartPage : 1;
  BOOL  fAutoCheckSelect : 1;
  BOOL  fIconsOnly : 1;
  BOOL  fShowTypeOverlay : 1;
  BOOL  fShowStatusBar : 1;
  UINT  fSpareFlags : 9;
} SHELLSTATEA, *LPSHELLSTATEA;
```

Whenever the same settings are available in `ShellState`, but also have their own value in `Explorer\Advanced`, the state in `Advanced` seems to be used, changing a setting via e.g. explorer causes both values to get edited:

```powershell
ShellState	REG_BINARY	24 00 00 00 3e 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 13 00 00 00 00 00 00 00 52 00 00 00			36 # IconsOnly = 1
ShellState	REG_BINARY	24 00 00 00 3e 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 13 00 00 00 00 00 00 00 42 00 00 00			36 # IconsOnly = 0
```

Means whenever modifying the value manually, the related value in `Explorer\Advanced` must also be changed.

| Offset | Size | Field | Meaning |
| --- | --- | --- | --- |
| `0x00` | 4 | `dwSize` | Value size |
| `0x04` | 4 | Primary flags | Bits `0-16` below, bits `17-31` padding |
| `0x08` | 4 | `dwWin95Unused` | Unused |
| `0x0C` | 4 | `uWin95Unused` | Unused |
| `0x10` | 4 | `lParamSort` | Sort column |
| `0x14` | 4 | `iSortDirection` | `1` ascending, `-1` descending |
| `0x18` | 4 | `version` | Unused |
| `0x1C` | 4 | `uNotUsed` | Unused |
| `0x20` | 4 | Secondary flags | Bits `0-6` below, bits `7-15` fSpareFlags & bits `16-31` padding |

All members within the primary & secondary flags are bools.

### Primary Flags

| Bit | Member | Meaning | `Explorer\Advanced` Value |
| --- | --- | --- | --- |
| 0 | `fShowAllObjects` | Show hidden objects | `Hidden` (if `= 1`) |
| 1 | `fShowExtensions` | Show file extensions | `HideFileExt` (inverted) |
| 2 | `fNoConfirmRecycle` | Skip recycle bin confirmation | - |
| 3 | `fShowSysFiles` | Show system files | `Hidden` (if `> 1`) |
| 4 | `fShowCompColor` | Color compressed/encrypted files | `ShowCompColor` |
| 5 | `fDoubleClickInWebView` | Require double click to open | - |
| 6 | `fDesktopHTML` | Use active desktop | - |
| 7 | `fWin95Classic` | Enforce Windows 95 Shell behavior & restrictions | - |
| 8 | `fDontPrettyPath` | Prevent paths from being converted to lowercase | `DontPrettyPath` |
| 9 | `fShowAttribCol` | Unused | `ShowAttribCol` |
| 10 | `fMapNetDrvBtn` | Show the map network drive button | `MapNetDrvBtn` |
| 11 | `fShowInfoTip` | Show item popup descriptions | `ShowInfoTip` |
| 12 | `fHideIcons` | Hide desktop icons | `HideIcons` |
| 13 | `fWebView` | Use web view | `WebView` |
| 14 | `fFilter` | Unused | `Filter` |
| 15 | `fShowSuperHidden` | Show protected operating system files | `ShowSuperHidden` |
| 16 | `fNoNetCrawling` | Disable automatic searches for network folders & printers | `NoNetCrawling` |

### Secondary Flags

| Bit | Member | Meaning | `Explorer\Advanced` Value |
| --- | --- | --- | --- |
| 0 | `fSepProcess` | Launch folder windows in a separate process | `SeparateProcess` |
| 1 | `fStartPanelOn` | Use the Windows XP style start menu | - |
| 2 | `fShowStartPage` | Unused | - |
| 3 | `fAutoCheckSelect` | Use check boxes to select items | `AutoCheckSelect` |
| 4 | `fIconsOnly` | Always show icons, never thumbnails | `IconsOnly` |
| 5 | `fShowTypeOverlay` | Display file type icon on thumbnails | `ShowTypeOverlay` |
| 6 | `fShowStatusBar` | Show the status bar | `ShowStatusBar` |

## Explorer Captures

Based on `Explorer > View > Options`.

### General

```c
// Open File Explorer to
// Home
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\LaunchTo	Type: REG_DWORD, Length: 4, Data: 2
// This PC
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\LaunchTo	Type: REG_DWORD, Length: 4, Data: 1

// Browse folders
// Open each folder in the same window
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\CabinetState\Settings	Type: REG_BINARY, Length: 12, Data: 0C 00 02 00 0A 01 00 00 60 00 00 00
// Open each folder in its own window
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\CabinetState\Settings	Type: REG_BINARY, Length: 12, Data: 0C 00 02 00 2A 01 00 00 60 00 00 00

// Click items as follows
// Single-click to open an item (point to select)
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShellState Type: REG_BINARY, Length: 36, Data: 24 00 00 00 1E 20 00 00 00 00 00 00 00 00 00 00
// Double-click to open an item (singe-click to select)
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShellState Type: REG_BINARY, Length: 36, Data: 24 00 00 00 3E 20 00 00 00 00 00 00 00 00 00 00

// Privacy
  // Show recently used files
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowRecent	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowRecent	Type: REG_DWORD, Length: 4, Data: 0

  // Show frequently used folders
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowFrequent	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowFrequent	Type: REG_DWORD, Length: 4, Data: 0

  // Show files from Office.com
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowCloudFilesInQuickAccess	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowCloudFilesInQuickAccess	Type: REG_DWORD, Length: 4, Data: 0
```

### View

```c
// Always show icons, never thumbnails
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\IconsOnly	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\IconsOnly	Type: REG_DWORD, Length: 4, Data: 0

// Decrease space between items (compact view)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\UseCompactMode	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\UseCompactMode	Type: REG_DWORD, Length: 4, Data: 0

// Display file icon on thumbnails
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowTypeOverlay	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowTypeOverlay	Type: REG_DWORD, Length: 4, Data: 0

// Display file size information in folder tips
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\FolderContentsInfoTip	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\FolderContentsInfoTip	Type: REG_DWORD, Length: 4, Data: 0

// Dispay the full path in the title bar
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\CabinetState\FullPath	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\CabinetState\FullPath	Type: REG_DWORD, Length: 4, Data: 0

// Hidden files and folders
// Don't show hidden files, folders, or drives
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Hidden	Type: REG_DWORD, Length: 4, Data: 2
// SHow hidden files, folders, and drives
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Hidden	Type: REG_DWORD, Length: 4, Data: 1

// Hide empty drives
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideDrivesWithNoMedia	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideDrivesWithNoMedia	Type: REG_DWORD, Length: 4, Data: 0

// Hide file extensions for known file types
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideFileExt	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideFileExt	Type: REG_DWORD, Length: 4, Data: 0

// Hide folder merge conflicts
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideMergeConflicts	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\HideMergeConflicts	Type: REG_DWORD, Length: 4, Data: 0

// Hide protected operating system files (Recommended)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSuperHidden	Type: REG_DWORD, Length: 4, Data: 0
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSuperHidden	Type: REG_DWORD, Length: 4, Data: 1

// Launch folder windows in a seperate process
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SeparateProcess	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SeparateProcess	Type: REG_DWORD, Length: 4, Data: 0

// Restore previous folder windows at logon
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\PersistBrowsers	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\PersistBrowsers	Type: REG_DWORD, Length: 4, Data: 0

// Show drive letters
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowDriveLettersFirst	Type: REG_DWORD, Length: 4, Data: 0
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\ShowDriveLettersFirst	Type: REG_DWORD, Length: 4, Data: 2

// Show encrypted or compressed NTFS files in color
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowEncryptCompressedColor	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowEncryptCompressedColor	Type: REG_DWORD, Length: 4, Data: 0

// Show pop-up description for folder and desktop items
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowInfoTip	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowInfoTip	Type: REG_DWORD, Length: 4, Data: 0

// Show preview handlers in preview pane
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowPreviewHandlers	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowPreviewHandlers	Type: REG_DWORD, Length: 4, Data: 0

// Show status bar
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowStatusBar	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowStatusBar	Type: REG_DWORD, Length: 4, Data: 0

// Show sync provider notifications
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSyncProviderNotifications	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSyncProviderNotifications	Type: REG_DWORD, Length: 4, Data: 0

// Use check boxes to select items
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\AutoCheckSelect	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\AutoCheckSelect	Type: REG_DWORD, Length: 4, Data: 0

// Use Sharing Wizard (Recommended)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SharingWizardOn	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SharingWizardOn	Type: REG_DWORD, Length: 4, Data: 0

// When typing into list view
// Automatically type into the Search Box
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TypeAhead	Type: REG_DWORD, Length: 4, Data: 1
// Select the typed item in the view
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TypeAhead	Type: REG_DWORD, Length: 4, Data: 0

// Navigation pane
  // Always show availability status
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneShowAllCloudStates	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneShowAllCloudStates	Type: REG_DWORD, Length: 4, Data: 0

  // Expand to open folders
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneExpandToCurrentFolder	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneExpandToCurrentFolder	Type: REG_DWORD, Length: 4, Data: 0

  // Show all folders
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneShowAllFolders	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\NavPaneShowAllFolders	Type: REG_DWORD, Length: 4, Data: 0

  // Show libraries
  // Enabled
  HKCU\Software\Classes\CLSID\{031E4825-7B94-4dc3-B131-E946B44C8DD5}\System.IsPinnedToNameSpaceTree	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Classes\CLSID\{031E4825-7B94-4dc3-B131-E946B44C8DD5}\System.IsPinnedToNameSpaceTree	Type: REG_DWORD, Length: 4, Data: 0
```

### Search

```c
// Don't use the index when searching in file folders for system files (searches might take longer)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\WholeFileSystem	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\WholeFileSystem	Type: REG_DWORD, Length: 4, Data: 0

// Include system directories
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\SystemFolders Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\SystemFolders Type: REG_DWORD, Length: 4, Data: 0

// Include compress files (ZIP, CAB...)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\ArchivedFiles Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\Preferences\ArchivedFiles Type: REG_DWORD, Length: 4, Data: 0

// Always search file names and contents (this might take several minutes)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\PrimaryProperties\UnindexedLocations\SearchOnly Type: REG_DWORD, Length: 4, Data: 0
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Search\PrimaryProperties\UnindexedLocations\SearchOnly Type: REG_DWORD, Length: 4, Data: 1
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Hide and disable all items on the desktop](https://noverse.dev/policies?p=Desktop*NoDesktop) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`<br>`HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoDesktop` |
| [Do not keep history of recently opened documents](https://noverse.dev/policies?p=StartMenu*NoRecentDocsHistory) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`<br>`HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoRecentDocsHistory` |
| [Prohibit access of the Windows Connect Now wizards](https://noverse.dev/policies?p=WindowsConnectNow*WCN_DisableWcnUi_2) | `HKLM\Software\Policies\Microsoft\Windows\WCN\UI` | `DisableWcnUi` |

# Desktop Wallpaper

This is a collection of some wallpapers that I've found over time. Added for people who may never have spent time changing their background, or for anyone else. Head over to [visibility/desc.md#desktop-wallpaper](https://github.com/nohuto/win-config/blob/main/visibility/desc.md#desktop-wallpaper), if you want to see the wallpapers in a seperate window.

### Asia

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Asia.png?raw=true)

### Austria

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Austria.png?raw=true)

### Beach

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Beach.png?raw=true)

### Blue Flowers

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Blue-Flowers.png?raw=true)

### Bones

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Bones.png?raw=true)

### Castle

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Castle.png?raw=true)

### Cat

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Cat.png?raw=true)

### City

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/City.png?raw=true)

### Cloudy Village

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Cloudy-Village.png?raw=true)

### Dark Sunset

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Dark-Sunset.png?raw=true)

### Dry Landscape

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Dry-Landscape.png?raw=true)

### Earth Gruvbox

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Earth-Gruvbox.png?raw=true)

### Fall

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/fall.png?raw=true)

### Field Sunset

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Field-Sunset.png?raw=true)

### Field Sunset 2

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Field-Sunset-2.png?raw=true)

### Fishing Frogs

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Fishing-Frogs.png?raw=true)

### Flowers

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Flowers.png?raw=true)

### Flowers Sunset

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Flowers-Sunset.png?raw=true)

### Forst Clouds

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Forst-Clouds.png?raw=true)

### Girl Clouds

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Girl-Clouds.png?raw=true)

### Golden Hour

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Golden-Hour.png?raw=true)

### Heaven

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Heaven.png?raw=true)

### Lake

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Lake.png?raw=true)

### Mac

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Mac.png?raw=true)

### Magic Forest

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Magic-Forest.png?raw=true)

### Man Landscape

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Man-Landscape.png?raw=true)

### Meadow Sunset

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Meadow-Sunset.png?raw=true)

### Moon

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Moon.png?raw=true)

### Moon Castle

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Moon-Castle.png?raw=true)

### Moon Rose

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Moon-Rose.png?raw=true)

### Mountains

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Mountains.png?raw=true)

### Plants Room

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Plants-Room.png?raw=true)

### Pokemon

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Pokemon.png?raw=true)

### Rain

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Rain.png?raw=true)

### Relax Landscape

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Relax-Landscape.png?raw=true)

### Sea

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Sea.png?raw=true)

### Sea Art

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Sea-Art.png?raw=true)

### Sea Road

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Sea-Road.png?raw=true)

### Shop

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Shop.png?raw=true)

### Stars

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Stars.png?raw=true)

### Stars Lake 1

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Stars-Lake-1.png?raw=true)

### Stars Lake 2

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Stars-Lake-2.png?raw=true)

### Stars Lake 3

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Stars-Lake-3.png?raw=true)

### Sunset

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Sunset.png?raw=true)

### Village

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Village.png?raw=true)

### Violet Night

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Violet-Night.png?raw=true)

### Witcher Landscape

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Witcher-Landscape.png?raw=true)

### Workplace

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Workplace.png?raw=true)

### World

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/World.png?raw=true)

### Zelda

![](https://github.com/nohuto/win-config/blob/main/visibility/images/wallpaper/Zelda.png?raw=true)

## JPEG Reduction

Windows reduces the quality of JPEG images you set as the desktop background to `85%` by default, you can set it to `100%` via the suboption.

### [TranscodeImage](https://github.com/nohuto/win-config/blob/main/system/assets/jpeg-TranscodeImage.c)

```c
if ( (int)SHRegGetDWORD(
            HKEY_CURRENT_USER,
            L"Control Panel\\Desktop",
            L"JPEGImportQuality",
            (unsigned int *)&v38) < 0 )
{
  v17 = FLOAT_85_0;
}
else
{
  v17 = fmaxf((float)(int)v38, 60.0);
  if ( v17 > 100.0 )
    v17 = FLOAT_100_0;
}
```

Default value is `85` -> `85%` (gets used if value isn't present), clamp range is `60-100`, if set above `100` it gets clamped to `100`, if set below `60`, it gets clamped to `60`.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Desktop Wallpaper](https://noverse.dev/policies?p=Desktop*Wallpaper) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `Wallpaper`<br>`WallpaperStyle` |

# Pointer Style

Windows has four main pointer style modes in `SystemSettings Accessibility > Mouse pointer and touch`: `White`, `Black`, `Inverted`, and `Custom color`. The first three are controlled by `CursorType`, custom colors switch `CursorType` to `6` and store the selected color in `CursorColor`. That color is stored as a Win32 [`COLORREF`](https://learn.microsoft.com/en-us/windows/win32/gdi/colorref), so the DWORD uses the `0x00bbggrr` layout instead of a plain RGB hex string. Standard styles point to system cursor files under `%SystemRoot%\cursors\...`, while custom colors point to generated per user cursor files under `%LOCALAPPDATA%\Microsoft\Windows\Cursors\*_eoa.cur`.

### Installing Custom Cursors

If you want a full custom cursor pack instead of Windows built in white, black, inverted, or recolored accessibility cursors, you can install one from diffrenrent sources such as [vsthemes.org](https://vsthemes.org/en/cursors/).

1. Download and extract the pack
2. Copy the pack files into `%SystemRoot%\Cursors\<Pack Name>` if you want to keep them in the standard system cursor location
3. Open `main.cpl`, go to the `Pointers` tab, select a cursor role, click `Browse`, and pick the downloaded `.cur` or `.ani` file

#### Cursor Previews

| Name | Preview |
| --- | --- |
| Custom colors + dark/light/invert | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/defaults.png?raw=true) |
| [Simplify Dot](https://vsthemes.org/en/cursors/static/47356-simplify-dot-2.html) (Dark/Light) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/simplify-dot.webp?raw=true) |
| [Colloid Dark](https://vsthemes.org/en/cursors/black/68372-colloid-dark.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/colloid-dark.webp?raw=true) |
| [Colloid Light](https://vsthemes.org/en/cursors/white/68371-colloid-light.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/colloid-light.webp?raw=true) |
| [Monolith](https://vsthemes.org/en/cursors/black/70650-monolith.html) (Dark/Light) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/monolith.webp?raw=true) |
| [Capitaine](https://vsthemes.org/en/cursors/black/27320-capitaine.html) (Dark, White, Gruvbox, Gruvbox White, Nord, Nord White, Palenight, Palenight White) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/capitaine.webp?raw=true) |
| [Skyrim](https://vsthemes.org/en/cursors/games/45588-the-elder-scrolls-5-skyrim.html) | ![](https://github.com/nohuto/win-config/blob/main/visibility/images/cursors/skyrim.webp?raw=true) |

### Pointer Style Captures

```c
// Main style
// 0 = White, 1 = Black, 2 = Inverted, 6 = Custom color
HKCU\Software\Microsoft\Accessibility\CursorType	Type: REG_DWORD

// Custom color only (COLORREF format: 0x00bbggrr)
HKCU\Software\Microsoft\Accessibility\CursorColor	Type: REG_DWORD

// Standard styles use the built in system cursor sets
HKCU\Control Panel\Cursors\(Default)		Type: REG_SZ
HKCU\Control Panel\Cursors\Arrow		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Help		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\AppStarting	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Wait		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Crosshair	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\IBeam		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\NWPen		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\No		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNS		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeWE		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNWSE	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeNESW	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\SizeAll		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\UpArrow	Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Hand		Type: REG_EXPAND_SZ
HKCU\Control Panel\Cursors\Scheme Source	Type: REG_DWORD

// Custom colored styles use generated peruser cursor files
HKCU\Control Panel\Cursors\Arrow // %LOCALAPPDATA%\Microsoft\Windows\Cursors\arrow_eoa.cur
HKCU\Control Panel\Cursors\AppStarting // %LOCALAPPDATA%\Microsoft\Windows\Cursors\busy_eoa.cur
HKCU\Control Panel\Cursors\Crosshair // %LOCALAPPDATA%\Microsoft\Windows\Cursors\cross_eoa.cur
HKCU\Control Panel\Cursors\Hand // %LOCALAPPDATA%\Microsoft\Windows\Cursors\link_eoa.cur
HKCU\Control Panel\Cursors\Help // %LOCALAPPDATA%\Microsoft\Windows\Cursors\helpsel_eoa.cur
HKCU\Control Panel\Cursors\IBeam // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ibeam_eoa.cur
HKCU\Control Panel\Cursors\No // %LOCALAPPDATA%\Microsoft\Windows\Cursors\unavail_eoa.cur
HKCU\Control Panel\Cursors\NWPen // %LOCALAPPDATA%\Microsoft\Windows\Cursors\pen_eoa.cur
HKCU\Control Panel\Cursors\Person // %LOCALAPPDATA%\Microsoft\Windows\Cursors\person_eoa.cur
HKCU\Control Panel\Cursors\Pin // %LOCALAPPDATA%\Microsoft\Windows\Cursors\pin_eoa.cur
HKCU\Control Panel\Cursors\SizeAll // %LOCALAPPDATA%\Microsoft\Windows\Cursors\move_eoa.cur
HKCU\Control Panel\Cursors\SizeNESW // %LOCALAPPDATA%\Microsoft\Windows\Cursors\nesw_eoa.cur
HKCU\Control Panel\Cursors\SizeNS // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ns_eoa.cur
HKCU\Control Panel\Cursors\SizeNWSE // %LOCALAPPDATA%\Microsoft\Windows\Cursors\nwse_eoa.cur
HKCU\Control Panel\Cursors\SizeWE // %LOCALAPPDATA%\Microsoft\Windows\Cursors\ew_eoa.cur
HKCU\Control Panel\Cursors\UpArrow // %LOCALAPPDATA%\Microsoft\Windows\Cursors\up_eoa.cur
HKCU\Control Panel\Cursors\Wait // %LOCALAPPDATA%\Microsoft\Windows\Cursors\wait_eoa.cur
HKCU\Control Panel\Cursors\CursorBaseSize	Type: REG_DWORD

// Used custom color DWORDs (these are the predefined ones from SystemSettings)
HKCU\Software\Microsoft\Accessibility\CursorColor = 16711871	// Pink (0x00FF00BF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 65471		// Lime (0x0000FFBF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 64250		// Yellow (0x0000FAFA)
HKCU\Software\Microsoft\Accessibility\CursorColor = 49151		// Gold (0x0000BFFF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 12517631	// Pink (0x00BF00FF)
HKCU\Software\Microsoft\Accessibility\CursorColor = 16760576	// Turquise (0x00FFBF00)
HKCU\Software\Microsoft\Accessibility\CursorColor = 12582656	// Green (0x00BFFF00)
```

When applying these manually via the registry the cursor can be refreshed using [SPI_SETCURSORS](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa), this only works for dark+light+inverted+custom, the color ones build `*_eoa.cur` files as said above which the function doesn't do (which is also kind of why the dropdown doesn't include colored cursors).

# Disable Rounded Corners

This currently works via [Win11DisableRoundedCorners](https://github.com/valinet/Win11DisableRoundedCorners) which works fine on [latest version since the function exists/works the same on latest builds](https://noverse.dev/diff?kind=pseudocode). Note that the revert doesn't run `sfc /scannow` to restore proper file permissions to `uDWM.dll` since it does a lot more than restoring permissions. If you're aware if it, run the command after reverting the option.

It works by overriding the first 8 bytes in the function with `48 C7 C0 00 00 00 00 C3`:

```c
mov rax, 0; ret // result = 0
```

### Rounded Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/rounded.png?raw=true)

### Angular Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/angular.png?raw=true)

## [GetEffectiveCornerStyle](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-GetEffectiveCornerStyle%40CTopLevelWindow%40%40AEAA-AW4CORNER_STYLE%40%40XZ.c)

That function calculates the effective corner mode, its callers include border/shadow/radius.
```c
/*
 * XREFs of ?GetEffectiveCornerStyle@CTopLevelWindow@@AEAA?AW4CORNER_STYLE@@XZ @ 0x18003AB74
 * Callers:
 *     ?GetShadowStyle@CTopLevelWindow@@AEAA?AW4ShadowStyle@CWindowBorder@@XZ @ 0x18001AA04 (-GetShadowStyle@CTopLevelWindow@@AEAA-AW4ShadowStyle@CWindowBorder@@XZ.c)
 *     ?UpdateWindowVisuals@CTopLevelWindow@@AEAAJXZ @ 0x18003D8E0 (-UpdateWindowVisuals@CTopLevelWindow@@AEAAJXZ.c)
 *     ?GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ @ 0x1800E5B98 (-GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ.c)
 * Callees:
 *     IsOpenThemeDataPresent @ 0x18005DB28 (IsOpenThemeDataPresent.c)
 */

__int64 __fastcall CTopLevelWindow::GetEffectiveCornerStyle(__int64 a1)
{
  __int64 result; // rax
  int v2; // ebx

  if ( *((_BYTE *)CDesktopManager::s_pDesktopManagerInstance + 27)
    && !*((_BYTE *)CDesktopManager::s_pDesktopManagerInstance + 29)
    || *((int *)CDesktopManager::s_pDesktopManagerInstance + 8) >= 2 )
  {
    return 1LL;
  }
  result = *(unsigned int *)(*(_QWORD *)(a1 + 752) + 184LL);
  if ( !(_DWORD)result )
  {
    v2 = *(_DWORD *)(a1 + 624);
    if ( (v2 & 2) != 0 )
      return 3LL;
    if ( !(unsigned __int8)IsOpenThemeDataPresent() )
      return 1LL;
    result = 2LL;
    if ( (v2 & 6) == 0 )
      return 1LL;
  }
  return result;
}
```

Obviously, `GetEffectiveCornerStyle` only exists in W11 builds (as you can see in [decompiled-pseudocode](https://github.com/nohuto/decompiled-pseudocode)).

# Night Light

Uses warmer colors to block blue light, since the data for them is a bit complicated as shown below, I'll add support for modifying it in a later WinConfig version.

```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings : Data # REG_BINARY
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate: Data # REG_BINARY
```

## [BlueLightReduction.Settings](https://github.com/MicrosoftDocs/windows-dev-docs/edit/docs/hub/apps/develop/settings/settings-common.md#type-windowsdatabluelightreductionsettings-structure) structure

The data itself is [Microsoft Bond Compact Binary](https://microsoft.github.io/bond/reference/cpp/compact__binary_8h_source.html), `43 42 01 00` prefix means `CB` (compact binary) version `1`.

```cpp
enum BondDataType
{
    BT_STOP       = 0,
    BT_STOP_BASE  = 1,
    BT_BOOL       = 2,
    BT_UINT8      = 3,
    BT_UINT16     = 4,
    BT_UINT32     = 5,
    BT_UINT64     = 6,
    BT_FLOAT      = 7,
    BT_DOUBLE     = 8,
    BT_STRING     = 9,
    BT_STRUCT     = 10,
    BT_LIST       = 11,
    BT_SET        = 12,
    BT_MAP        = 13,
    BT_INT8       = 14,
    BT_INT16      = 15,
    BT_INT32      = 16,
    BT_INT64      = 17,
    BT_WSTRING    = 18,
    BT_UNAVAILABLE= 127
}
```

Example data:

```powershell
43 42 01 00 02 01 C2 0A 00 CA 14 0E 12 00 CA 1E 0E 05 00 CF 28 DC 4C CA 32 00 CA 3C 00 00
```

`02 01` = field 0 (automaticOnSchedule)
- `02` = type (`BT_BOOL`)
- `01` = value (`true`)

`CF 28 DC 4C` = field 40 (targetColorTemperature)
- `CF 28` = type (BT_INT16) + field 40
- `DC 4C` = value (`4910` since it uses BT_INT16)

| Field | Name | Type | Description | Value |
| --- | --- | --- | --- | --- |
| 0 | `automaticOnSchedule` | bool | Specifies whether blue light reduction is automatically turned on or off based on a schedule. |  `true` |
| 10 | `automaticOnSunset` | bool | Specifies if blue light reduction schedule is automatically set based on sunrise and sunset. | `false` |
| 20 | `manualScheduleBlueLightReductionOnTime` | ScheduleTime | The start time of blue light reduction for a user manually setting their schedule. |  `18:00` |
| 30 | `manualScheduleBlueLightReductionOffTime` | ScheduleTime | The end time of blue light reduction for a user manually setting their schedule. | `05:00` |
| 40 | `targetColorTemperature` | int16 | The target color temperature (in Kelvin) for blue light reduction. | `4910` Kelvin |
| 50 | `sunriseTime` | ScheduleTime | The scheduled sunset time for blue light reduction. | empty |
| 60 | `sunsetTime` | ScheduleTime | The scheduled sunrise time for blue light reduction. | empty |
| 70 | `previewColorTemperatureChanges` | bool | Specifies whether blue light reduction color temperature changes should be previewed. | not present |
| 80 | `darkMode` | bool | Specifies whether app mode should change when blue light reduction is turned on or off. | not present |

`ScheduleTime` has type int8, field `0` is `hour` and field `1` is `minute` (often leaves `minute` out when it is `0`).

## [BlueLightReduction.BlueLightReductionState](https://github.com/MicrosoftDocs/windows-dev-docs/edit/docs/hub/apps/develop/settings/settings-common.md#type-windowsdatabluelightreductionbluelightreductionstate-structure) structure

Example data:

```powershell
43 42 01 00 10 00 C6 14 DE F4 98 9E EA EE BE EE 01 00
```

| Field | Name | Type | Description | Value |
| --- | --- | --- | --- | --- |
| 0 | `state` | ActiveState | The current state of blue light reduction. | `0` = `BlueLightReductionOn`, `1` = `BlueLightReductionOff` |
| 10 | `source` | ChangeSource |  Where the change came from, user change or scheduled change. | not present (`0` = `Schedule`, `1` = `User`) |
| 20 | `timestampUTC` | int64 | The time the change in active state was applied. | `2026-06-13T20:53:08.666224Z` (decodes as [`FILETIME`](https://learn.microsoft.com/windows/win32/sysinfo/file-times)) |
| 30 | `isSupported` | bool | Whether or not current configuration supports blue light reduction. | not present |

## SystemSettings Captures

Procmon doesn't show the entire data, therefore this isn't accurate (and sometimes useless, e.g. the 'Strength' capture).

```c
// System > Display : Night light
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 43, Data: 43 42 01 00 0A 02 01 00 2A 06 FC 84 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 41, Data: 43 42 01 00 0A 02 01 00 2A 06 FE 84 B7 D1 06 2A

// System > Display > Night light: Show warmer colors on your display to help you sleep
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 43, Data: 43 42 01 00 0A 02 01 00 2A 06 AF 86 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.bluelightreductionstate\windows.data.bluelightreduction.bluelightreductionstate\Data	Type: REG_BINARY, Length: 41, Data: 43 42 01 00 0A 02 01 00 2A 06 B1 86 B7 D1 06 2A

// System > Display > Night light: Strength (0-2)
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 99 AD B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 9B AD B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 55, Data: 43 42 01 00 0A 02 01 00 2A 06 9D AD B7 D1 06 2A

// System > Display > Night light: Schedule night light
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 50, Data: 43 42 01 00 0A 02 01 00 2A 06 98 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 9A 88 B7 D1 06 2A

// System > Display > Night light: Set hours (first) & Sunset to sunrise (second)
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 A2 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 49, Data: 43 42 01 00 0A 02 01 00 2A 06 A4 88 B7 D1 06 2A

// System > Display > Night light: Turn on 5PM, Turn off 8AM
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 A8 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AA 88 B7 D1 06 2A

// System > Display > Night light: Turn on 6PM, Turn off 9AM
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AC 88 B7 D1 06 2A
HKCU\Software\Microsoft\Windows\CurrentVersion\CloudStore\Store\DefaultAccount\Current\default$windows.data.bluelightreduction.settings\windows.data.bluelightreduction.settings\Data	Type: REG_BINARY, Length: 52, Data: 43 42 01 00 0A 02 01 00 2A 06 AE 88 B7 D1 06 2A
```

# Minimal Visual Effects

Disables all kind of animations, while leaving font smoothing + window content while dragging + thumbnails instead of icons enabled.

## UserPreferencesMask

Anything written as "- *text*" behind the linked name equals the source where the option can be toggled (and where I recorded the bit differences), "(untested)" means that I didn't find the Windows UI toggle for the bit yet, means that the meaning is currently based on pseudocode, or on [SystemParametersInfo (`SPI_*`)](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfow) naming. All meanings have a link to the win32k pseudocode function where the bit is read.

| Bit | Hex | Meaning |
| --- | --- | --- |
| 0 | `0x00000001` | [Active window tracking (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-xxxTrackingActivateWindow@@YA_NPEAUtagWND@@@Z.c) |
| 1 | `0x00000002` | [Fade or slide menus into view](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxMenuWindowProc.c) - *Performance Options* |
| 2 | `0x00000004` | [Slide open combo boxes](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxSystemParametersInfoWorker.c) - *Performance Options* |
| 3 | `0x00000008` | [Smooth-scroll list boxes](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxSystemParametersInfoWorker.c) - *Performance Options* |
| 4 | `0x00000010` | [Caption/gradient visual effects (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-xxxAnimateCaption@@YAXPEAUtagWND@@PEAUHDC__@@PEAUtagRECT@@2@Z.c) - "When set, each window title bar has a gradient effect (changes from one color or shade to another along the length of the title bar)." |
| 5 | `0x00000020` | [Keyboard cues / menu underlines (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-xxxDrawMenuItemText@@YAXAEBV-$SmartObjStackRef@UtagMENU@@@@PEAUtagITEM@@PEAUHDC__@@HHPEAGHH@Z.c) |
| 6 | `0x00000040` | [Active window tracking Z-order (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-xxxTrackingActivateWindow@@YA_NPEAUtagWND@@@Z.c) |
| 7 | `0x00000080` | [Hot tracking (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxTrackMouseMove.c) |
| 9 | `0x00000200` | [Menu fade (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/ShouldHaveShadow.c), requires bit `1` to be set |
| 10 | `0x00000400` | [Fade out menu items after clicking](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-zzzMNFadeSelection@@YAHAEBV-$SmartObjStackRef@UtagMENU@@@@PEAUtagITEM@@@Z.c) - *Performance Options* |
| 11 | `0x00000800` | [Fade or slide ToolTips into view](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-xxxShowTooltip@@YAHPEAUtagTOOLTIPWND@@@Z.c) - *Performance Options* |
| 12 | `0x00001000` | [Tooltip fade (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxTooltipWndProc.c), required bit `11` to be set |
| 13 | `0x00002000` | [Show shadows under mouse pointer](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-FCursorShadowed@@YA_NPEAU_CURSINFO@@@Z.c) - *Performance Options* |
| 14 | `0x00004000` | [Show location of pointer when I press the CTRL key](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/EditionHandleSonarKeyEvent.c) - *Mouse Properties* |
| 15 | `0x00008000` | [Turn on ClickLock](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kbase/-ProcessMouseButton@CMouseProcessor@@AEAAXAEBVCButtonEvent@1@@Z.c) - *Mouse Properties* |
| 16 | `0x00010000` | [Hide pointer while typing](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/NtUserHideCursorNoCapture.c) - *Mouse Properties* |
| 17 | `0x00020000` | [Flat menus (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxDrawMenuBarUnderlines.c) |
| 18 | `0x00040000` | [Show shadows under windows](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/ShouldHaveShadow.c) - *Performance Options* |
| 31 | `0x80000000` | [Master UI effects (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/xxxSystemParametersInfoWorker.c) - "When enabled, all user interface effects (combo box animation, cursor shadow, gradient captions, hot tracking, list box smooth scrolling, menu animation, menu underlines, selection fade, tool tip animation) are enabled." |
| 33 | `0x00000002` in high dword | Animate controls and elements inside windows |
| 39 | `0x00000080` in high dword | [Suppress/apply global input-settings updates on focus/delegation changes (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/EditionKeyboardInputDelegationChanged.c) |
| 41 | `0x00000200` in high dword | [Pen button yield / pen quick-launch hotkey (untested)](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-NotifyISMPenButtonYieldSettingChange@@YAXXZ.c) |

### Font Smoothing

![](https://github.com/nohuto/win-config/blob/main/visibility/images/visual1.jpg?raw=true)

# Enable Dark Theme

## Registry Values

Values below are based on `RegGetValueW`/`SHRegGetDWORD`/`SHRegGetUSDWORDW` xrefs within `uxtheme.dll`. Since there weren't many, I added others that have nothing to do with dark mode too.

```c
"HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization";
  "PersonalColors_Background" = ?; // REG_SZ, #RRGGBB
  "PersonalColors_Accent" = ?; // REG_SZ, #RRGGBB
  "NoChangingStartMenuBackground" = 0; // REG_DWORD (bool)

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell";
  "TabletMode" = 0; // REG_DWORD (bool), nonzero suppresses DWM ColorPrevalence caption color

"HKCU\\Software\\Microsoft\\Windows\\DWM";
  // _NCWNDMET::GetCaptionColor
  "ColorPrevalence" = 0; // REG_DWORD, range 0-5

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent";
  "StartColorMenu" = 4288563712; // REG_DWORD, range 0-4294967295, fallback to ColorSet_Version3, then DefaultStartColor
  "AccentColorMenu" = 4292319232; // REG_DWORD, range 0-4294967295, ^
  "ColorSet_Version3" = ?; // REG_DWORD, range 0-49
  "AccentPalette" = ?; // REG_BINARY, length 32 bytes, 8 DWORD colors
  "UseNewAutoColorAccentAlgorithm" = 1; // REG_DWORD (bool)
  "MinSaturation" = 150; // REG_DWORD, divided by 1000, means default 0.15

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Accent";
  "DefaultStartColor" = 4288563712; // REG_DWORD, range 0-4294967295
  "DefaultAccentColor" = 4292319232; // REG_DWORD, range 0-4294967295

"HKCU\\Control Panel\\Desktop";
  "AutoColorization" = 0; // REG_DWORD or REG_SZ "0"/"1", range 0-1

"HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize";
  "AppsUseLightTheme" = 1; // REG_DWORD or REG_SZ "0"/"1", range 0-1
                           // 0 = dark mode
                           // 1 = light mode
                           // invalid/missing fallback to HKLM UWPAppsUseLightTheme then 1
  "SystemUsesLightTheme" = ?; // REG_DWORD or REG_SZ "0"/"1", range 0-1
                             // 0 = dark mode
                             // 1 = light mode
                             // invalid/missing fallback to HKLM SystemUsesLightTheme then IsOS_OS_PERSONAL
  "ColorPrevalence" = 0; // REG_DWORD, range 0-4294967295

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes";
  "UWPAppsUseLightTheme" = 1; // REG_DWORD or REG_SZ "0"/"1", range 0-1, fallback for AppsUseLightTheme
  "SystemUsesLightTheme" = ?; // REG_DWORD or REG_SZ "0"/"1", range 0-1, fallback for HKCU SystemUsesLightTheme

"HKCU\\Software\\Microsoft\\Accessibility";
  "TextScaleFactor" = 100; // REG_DWORD, range 0-4294967295 (percent)
```

### Light Theme

![](https://github.com/nohuto/win-config/blob/main/visibility/images/darktheme1.png?raw=true)

### Dark Theme

![](https://github.com/nohuto/win-config/blob/main/visibility/images/darktheme2.png?raw=true)

# Disable Transparency

See [DWM, `BackdropBlurCachingThrottleMs`](https://noverse.dev/docs/win-config/system/dwm-values/#backdropblurcachingthrottlems) for information on how to edit the caching rebuild time, which has a default of `25ms`, and can be throttled to down to `1000ms`.

### Transparency Enabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/transpa1.png?raw=true)

### Transparency Disabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/transpa2.png?raw=true)

# Disable Animations

Minimize, maximize, taskbar animations / first sign-in animations etc.

First sign-in animation:

![](https://github.com/nohuto/win-config/blob/main/visibility/images/animation.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not allow window animations](https://noverse.dev/policies?p=DWM*DwmDisallowAnimations_1) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\DWM` | `DisallowAnimations` |
| [Do not allow window animations](https://noverse.dev/policies?p=DWM*DwmDisallowAnimations_2) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\DWM` | `DisallowAnimations` |
| [Turn off common control and window animations](https://noverse.dev/policies?p=Explorer*TurnOffSPIAnimations) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `TurnOffSPIAnimations` |
| [Show first sign-in animation](https://noverse.dev/policies?p=Logon*EnableFirstLogonAnimation) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `EnableFirstLogonAnimation` |

# Taskbar Settings

Removes the search box, moves the taskbar to the left, removes badges, disables the flashes on the app icons, removes the "Task View" button (`Personalization > Taskbar`). See details about the `Add 'End Task' to Taskbar Context Menu` option [here](https://www.youtube.com/watch?v=5HWyyNep6t0).

### SystemSettings Captures

```c
// SystemSettings > Personalization > Taskbar

  // Taskbar items
    // Search
    // Hide
    HKCU\Software\Microsoft\Windows\CurrentVersion\Search\SearchboxTaskbarMode	Type: REG_DWORD, Length: 4, Data: 0
    // Search icon only
    HKCU\Software\Microsoft\Windows\CurrentVersion\Search\SearchboxTaskbarMode	Type: REG_DWORD, Length: 4, Data: 1
    // Search icon and label
    HKCU\Software\Microsoft\Windows\CurrentVersion\Search\SearchboxTaskbarMode	Type: REG_DWORD, Length: 4, Data: 3
    // Search box
    HKCU\Software\Microsoft\Windows\CurrentVersion\Search\SearchboxTaskbarMode	Type: REG_DWORD, Length: 4, Data: 2

    // Task view
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowTaskViewButton	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowTaskViewButton	Type: REG_DWORD, Length: 4, Data: 0

    // Widgets
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDa	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDa	Type: REG_DWORD, Length: 4, Data: 0

  // System Tray icons
    // Emoji and more
    // Never
    HKCU\Software\Microsoft\TabletTip\1.7\EmojiAndMoreIconVisibilityState	Type: REG_DWORD, Length: 4, Data: 0
    // While typing
    HKCU\Software\Microsoft\TabletTip\1.7\EmojiAndMoreIconVisibilityState	Type: REG_DWORD, Length: 4, Data: 1
    // Always
    HKCU\Software\Microsoft\TabletTip\1.7\EmojiAndMoreIconVisibilityState	Type: REG_DWORD, Length: 4, Data: 2

    // Pen menu
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\PenWorkspace\PenWorkspaceButtonDesiredVisibility	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\PenWorkspace\PenWorkspaceButtonDesiredVisibility	Type: REG_DWORD, Length: 4, Data: 0

    // Touch keyboard
    // Never
    HKCU\Software\Microsoft\TabletTip\1.7\TipbandDesiredVisibility	Type: REG_DWORD, Length: 4, Data: 0
    // Always
    HKCU\Software\Microsoft\TabletTip\1.7\TipbandDesiredVisibility	Type: REG_DWORD, Length: 4, Data: 1
    // When no keyboard attached
    HKCU\Software\Microsoft\TabletTip\1.7\TipbandDesiredVisibility	Type: REG_DWORD, Length: 4, Data: 2

  // Other system tray icons
    // Hidden icon menu
    // Enabled
    HKCU\Software\Classes\Local Settings\Software\Microsoft\Windows\CurrentVersion\TrayNotify\SystemTrayChevronVisibility	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Classes\Local Settings\Software\Microsoft\Windows\CurrentVersion\TrayNotify\SystemTrayChevronVisibility	Type: REG_DWORD, Length: 4, Data: 0

    // Microsoft OneDrive
    // Enabled
    HKCU\Control Panel\NotifyIconSettings\1393818165748543931\IsPromoted	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\NotifyIconSettings\1393818165748543931\IsPromoted	Type: REG_DWORD, Length: 4, Data: 0

    // Windows Security notification icon
    // Enabled
    HKCU\Control Panel\NotifyIconSettings\9970533644875679773\IsPromoted	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\NotifyIconSettings\9970533644875679773\IsPromoted	Type: REG_DWORD, Length: 4, Data: 0

  // Taskbar behaviours
    // Taskbar alignment
    // Left
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarAl	Type: REG_DWORD, Length: 4, Data: 0
    // Center
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarAl	Type: REG_DWORD, Length: 4, Data: 1

    // Show badges on taskbar apps
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarBadges	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarBadges	Type: REG_DWORD, Length: 4, Data: 0

    // Show flashing on taskbar apps
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarFlashing	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarFlashing	Type: REG_DWORD, Length: 4, Data: 0

    // Share any window from my taskbar
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSn	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSn	Type: REG_DWORD, Length: 4, Data: 0

    // Select the far corner of the taskbar to show the desktop
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSd	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSd	Type: REG_DWORD, Length: 4, Data: 0

    // Combine taskbar buttons and hide labels (same for the one below but it uses value name MMTaskbarGlomLevel)
    // Always
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarGlomLevel	Type: REG_DWORD, Length: 4, Data: 0
    // When taskbar is full
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarGlomLevel	Type: REG_DWORD, Length: 4, Data: 1
    // Never
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarGlomLevel	Type: REG_DWORD, Length: 4, Data: 2

    // Show smaller taskbar buttons
    // Always
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\IconSizePreference	Type: REG_DWORD, Length: 4, Data: 0
    // When taskbar is full
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\IconSizePreference	Type: REG_DWORD, Length: 4, Data: 2
    // Never
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\IconSizePreference	Type: REG_DWORD, Length: 4, Data: 1


// SystemSettings > Time & language > Date & time

  // Show time and date in the System tray
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSystrayDateTimeValueName	Type: REG_DWORD, Length: 4, Data: 1
    // Show seconds in system tray clock (uses more power)
    // Enabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSecondsInSystemClock	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSecondsInSystemClock	Type: REG_DWORD, Length: 4, Data: 0

  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowSystrayDateTimeValueName	Type: REG_DWORD, Length: 4, Data: 0

// Taskbar

  // Lock the taskbar
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSizeMove	Type: REG_DWORD, Length: 4, Data: 0
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarSizeMove	Type: REG_DWORD, Length: 4, Data: 1

// SystemSettings > System > Advanced

  // End Task
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDeveloperSettings\TaskbarEndTask	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDeveloperSettings\TaskbarEndTask	Type: REG_DWORD, Length: 4, Data: 0


```

## Suboptions

### Hide Language Bar

![](https://github.com/nohuto/win-config/blob/main/visibility/images/languagebar.png?raw=true)

#### Text Services and Input Languages Captures

`Time & language > Typing > Advanced keyboard settings > Language bar options`:
```c
// Floating On Desktop
HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 0

// Hidden
HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 3

// Docked in the taskbar
HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 4
```

`Show the Language bar as transparent when inactive`:
```c
// Enabled
HKCU\Software\Microsoft\CTF\LangBar\Transparency	Type: REG_DWORD, Length: 4, Data: 64

// Disabled
HKCU\Software\Microsoft\CTF\LangBar\Transparency	Type: REG_DWORD, Length: 4, Data: 255
```

`Show additional Language bar icons in the taskbar`:
```c
// Enabled
HKCU\Software\Microsoft\CTF\LangBar\ExtraIconsOnMinimized	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
HKCU\Software\Microsoft\CTF\LangBar\ExtraIconsOnMinimized	Type: REG_DWORD, Length: 4, Data: 0
```

`Show text labels on the Language bar`:
```c
// Enabled
HKCU\Software\Microsoft\CTF\LangBar\Label	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
HKCU\Software\Microsoft\CTF\LangBar\Label	Type: REG_DWORD, Length: 4, Data: 0
```

### System Clock Seconds

"*Uses more power*" (in relation to laptops).

![](https://github.com/nohuto/win-config/blob/main/visibility/images/clock.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow widgets](https://noverse.dev/policies?p=NewsAndInterests*AllowNewsAndInterests) | `HKLM\SOFTWARE\Policies\Microsoft\Dsh` | `AllowNewsAndInterests` |
| [Disable Widgets On Lock Screen](https://noverse.dev/policies?p=NewsAndInterests*DisableWidgetsOnLockScreen) | `HKLM\SOFTWARE\Policies\Microsoft\Dsh` | `DisableWidgetsOnLockScreen` |
| [Disable Widgets Board](https://noverse.dev/policies?p=NewsAndInterests*DisableWidgetsBoard) | `HKLM\SOFTWARE\Policies\Microsoft\Dsh` | `DisableWidgetsBoard` |
| [Remove the People Bar from the taskbar](https://noverse.dev/policies?p=StartMenu*HidePeopleBar) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HidePeopleBar` |
| [Hide the TaskView button](https://noverse.dev/policies?p=Taskbar*HideTaskViewButton) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideTaskViewButton` |
| [Configures search on the taskbar](https://noverse.dev/policies?p=Search*ConfigureSearchOnTaskbarMode) | `HKLM\Software\Policies\Microsoft\Windows\Windows Search` | `SearchOnTaskbarMode` |

# Accent Color

This set's the accent color globally and if `AccentColor` (`HKEY_CURRENT_USER\Software\Noverse`) isn't set via the tool settings yet, this will also directly impact the WinConfig colors.

`Show Accent Color on Start and Taskbar` only works if using dark theme.

Something I noticed while creating the option is that procmon doesn't show the actual used binary data:
```c
// Procmon
59657CFF4A5468FF3F4859FF353C4AFF // 16

// After refreshing
59657CFF4A5468FF3F4859FF353C4AFF2A303BFF1F242CFF111317FF88179800 // 32

// Procmon
99EBFF004CC2FF000091F8000078D400

// After refreshing
99EBFF004CC2FF000091F8000078D4000067C000003E9200001A6800F7630C00
```

### SystemSettings Captures

Changing the color via `Personalization > Colors` sets:

```c
// Nord Theme (#2e3440)
HKCU\Software\Microsoft\Windows\DWM\ColorizationColor	Type: REG_DWORD, Length: 4, Data: 3291823178
HKCU\Software\Microsoft\Windows\DWM\ColorizationAfterglow	Type: REG_DWORD, Length: 4, Data: 3291823178
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\AccentPalette	Type: REG_BINARY, Length: 32, Data: 59 65 7C FF 4A 54 68 FF 3F 48 59 FF 35 3C 4A FF // see note above
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\StartColorMenu	Type: REG_DWORD, Length: 4, Data: 4282069034
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\AccentColorMenu	Type: REG_DWORD, Length: 4, Data: 4283055157
HKCU\Software\Microsoft\Windows\DWM\AccentColor	Type: REG_DWORD, Length: 4, Data: 4283055157
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-1-5-21-1713887642-2553820887-3827158055-1000\AnyoneRead\Colors\StartColor	Type: REG_DWORD, Length: 4, Data: 4282069034
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-1-5-21-1713887642-2553820887-3827158055-1000\AnyoneRead\Colors\AccentColor	Type: REG_DWORD, Length: 4, Data: 4283055157

// Default Blue
HKCU\Software\Microsoft\Windows\DWM\ColorizationColor	Type: REG_DWORD, Length: 4, Data: 3288365268
HKCU\Software\Microsoft\Windows\DWM\ColorizationAfterglow	Type: REG_DWORD, Length: 4, Data: 3288365268
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\AccentPalette	Type: REG_BINARY, Length: 32, Data: 99 EB FF 00 4C C2 FF 00 00 91 F8 00 00 78 D4 00
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\StartColorMenu	Type: REG_DWORD, Length: 4, Data: 4290799360
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent\AccentColorMenu	Type: REG_DWORD, Length: 4, Data: 4292114432
HKCU\Software\Microsoft\Windows\DWM\AccentColor	Type: REG_DWORD, Length: 4, Data: 4292114432
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-1-5-21-1713887642-2553820887-3827158055-1000\AnyoneRead\Colors\StartColor	Type: REG_DWORD, Length: 4, Data: 4290799360
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-1-5-21-1713887642-2553820887-3827158055-1000\AnyoneRead\Colors\AccentColor	Type: REG_DWORD, Length: 4, Data: 4292114432
```

## Prevent Color/Theme Changes

Prevents changing color/appearance, desktop background, desktop icons, start background, themes. It also stops themes from changing mouse pointers and desktop icons.

Use the suboptions to prevent/allow specific parts.

### [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent changing color and appearance](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoColorAppearanceUI) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `NoDispAppearancePage` |
| [Prevent changing desktop background](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoDesktopBackgroundUI) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\ActiveDesktop` | `NoChangingWallPaper` |
| [Prevent changing desktop icons](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoDesktopIconsUI) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `NoDispBackgroundPage` |
| [Prevent changing lock screen and logon image](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoChangingLockScreen) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoChangingLockScreen` |
| [Prevent changing mouse pointers](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoMousePointersUI) | `HKCU\Software\Policies\Microsoft\Windows\Personalization` | `NoChangingMousePointers` |
| [Prevent changing start menu background](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoChangingStartMenuBackground) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoChangingStartMenuBackground` |
| [Prevent changing theme](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_DisableThemeChange) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoThemesTab` |

# Account Picture

Changes the user account picture via:

```
C:\ProgramData\Microsoft\Default Account Pictures
```

## Suboption

### Global Account Picture

> "*This policy setting allows an administrator to standardize the account pictures for all users on a system to the default account picture.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Apply the default account picture to all users](https://noverse.dev/policies?p=Cpls*UseDefaultTile) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `UseDefaultTile` |

# System Fonts

W11 uses `Segoe UI` by default. You can change it via registry edits, the selected font will be used for desktop interfaces, explorer, some apps (`StartAllBack` will use it), but won't get applied for e.g., `SystemSettings.exe` and app fonts in general. Some fonts will cause issues - `Yu Gothic UI Light` uses `¥` instead of `\` (picture).

Either select a installed font with the command shown below or install new fonts via e.g. [nerdfonts](https://www.nerdfonts.com/font-downloads).

Applying a new font needs a restart or logout, reverting doesn't.
```powershell
shutdown -l # logout
```

List all available font families on your system with the `Open` option, or via `Personalization > Fonts`:
```powershell
Add-Type -AssemblyName System.Drawing;[System.Drawing.FontFamily]::Families | % {$_.Name}
```

![](https://github.com/nohuto/win-config/blob/main/visibility/images/font1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/visibility/images/font2.png?raw=true)

### Manually Adding Custom Fonts

The option lists the default fonts, add your own custom font via:

```json
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts": {
  "Segoe UI (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Black (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Black Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Bold (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Bold Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Historic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Light (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Light Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Semibold (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Semibold Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Semilight (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Semilight Italic (TrueType)": { "Type": "REG_SZ", "Data": "" },
  "Segoe UI Symbol (TrueType)": { "Type": "REG_SZ", "Data": "" }
}
// "Font Name" = Replace with the font name
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontSubstitutes": {
  "Segoe UI": { "Type": "REG_SZ", "Data": "Font Name" }
}
```

Revert the changes:

```json
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts": {
  "Segoe UI (TrueType)": { "Type": "REG_SZ", "Data": "segoeui.ttf" },
  "Segoe UI Black (TrueType)": { "Type": "REG_SZ", "Data": "seguibl.ttf" },
  "Segoe UI Black Italic (TrueType)": { "Type": "REG_SZ", "Data": "seguibli.ttf" },
  "Segoe UI Bold (TrueType)": { "Type": "REG_SZ", "Data": "segoeuib.ttf" },
  "Segoe UI Bold Italic (TrueType)": { "Type": "REG_SZ", "Data": "segoeuiz.ttf" },
  "Segoe UI Historic (TrueType)": { "Type": "REG_SZ", "Data": "seguihis.ttf" },
  "Segoe UI Italic (TrueType)": { "Type": "REG_SZ", "Data": "segoeuii.ttf" },
  "Segoe UI Light (TrueType)": { "Type": "REG_SZ", "Data": "segoeuil.ttf" },
  "Segoe UI Light Italic (TrueType)": { "Type": "REG_SZ", "Data": "seguili.ttf" },
  "Segoe UI Semibold (TrueType)": { "Type": "REG_SZ", "Data": "seguisb.ttf" },
  "Segoe UI Semibold Italic (TrueType)": { "Type": "REG_SZ", "Data": "seguisbi.ttf" },
  "Segoe UI Semilight (TrueType)": { "Type": "REG_SZ", "Data": "segoeuisl.ttf" },
  "Segoe UI Semilight Italic (TrueType)": { "Type": "REG_SZ", "Data": "seguisli.ttf" },
  "Segoe UI Symbol (TrueType)": { "Type": "REG_SZ", "Data": "seguisym.ttf" }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontSubstitutes": {
  "Segoe UI": { "Action": "deletevalue" }
}
```

## Suboptions

| Option | Description |
| --- | --- |
| Hide fonts based on language settings | "Windows can hide fonts that are not designed for your input language settings. If you choose this option, only fonts that are designed for your language settings will be listed in your programs. |
| Allow fonts to be installed using a shortcut | To save space on your computer, you can choose to install a shortcut to a font file instead of the file itself. If the font file becomes unavailable, you might not be able to use the font. |

## Notes on System Text Size

Edit text sizes via [`TextScaleFactor`](https://learn.microsoft.com/en-us/uwp/api/windows.ui.viewmanagement.uisettings.textscalefactor?view=winrt-26100#windows-ui-viewmanagement-uisettings-textscalefactor), valid ranges are `100-225` (DWORD).

```c
  v10 = 0;
  if ( (int)SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\Accessibility", L"TextScaleFactor", &v10) < 0
    || (v6 = v10, v10 - 101 > 0x7C) ) // valid range: [101, 225] -> v10 - 101 > 124  -> v10 > 225
  {
    v6 = 100LL; // fallback to 100 if missing or out of range (<100 / >225)
  }
```

- [visibility/assets | textsize-TextScaleDialogTemplate.c](https://github.com/nohuto/win-config/blob/main/visibility/assets/textsize-TextScaleDialogTemplate.c)

Applying changes via `Accessibility > Text size`:
```c
// 100%
HKCU\Software\Microsoft\Accessibility\TextScaleFactor    Type: REG_DWORD, Length: 4, Data: 100

// 225%
HKCU\Software\Microsoft\Accessibility\TextScaleFactor    Type: REG_DWORD, Length: 4, Data: 225
```

Depending on the selected size, `CaptionFont`, `SmCaptionFont`, `MenuFont`, `StatusFont`, `MessageFont`, `IconFont` (located in `HKCU\Control Panel\Desktop\WindowMetrics`) will also change. Not every % increase will edit them, I may add exact data soon. Example of `100%`/`225%`:

```c
// 100%
IconFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
CaptionFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
SmCaptionFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
MenuFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
StatusFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
MessageFont    Type: REG_BINARY, Length: 92, Data: F4 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00

// 225%
CaptionFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
SmCaptionFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
MenuFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
StatusFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
MessageFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
IconFont    Type: REG_BINARY, Length: 92, Data: E5 FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00
```

# Mouse Hover Time

- `MouseHoverTime` controls how long the mouse must stay still over something before Windows treats it as a hover.
- `MenuShowDelay` controls the menu hover delay, mainly how long shell menus wait before opening a submenu while the pointer is on a menu entry.

### CMenuToolbarBase::_SetTimer

[`SPI_GETMENUSHOWDELAY`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa):

> "*Retrieves the time, in milliseconds, that the system waits before displaying a shortcut menu when the mouse cursor is over a submenu item. The pvParam parameter must point to a DWORD variable that receives the time of the delay.*"

```c
if ( SystemParametersInfoW(0x6Au, 0, &g_lMenuPopupTimeout, 0) ) // 0x6A = SPI_GETMENUSHOWDELAY
  goto LABEL_5;
v4 = g_lMenuPopupTimeout;
if ( g_lMenuPopupTimeout != -1 )
  goto LABEL_6;
g_lMenuPopupTimeout = 4 * GetDoubleClickTime() / 5; // fallback (depends on DoubleClickSpeed)
if ( SHRegGetStringEx(HKEY_CURRENT_USER, L"Control Panel\\Desktop", L"MenuShowDelay", 2u, pszSrc, 6u) < 0 ) // 2u = REG_SZ
{
LABEL_5:
  v4 = g_lMenuPopupTimeout;
}
else
{
  v4 = StrToIntW(pszSrc);
  g_lMenuPopupTimeout = v4;
}
```

It first uses [`SystemParametersInfoW(SPI_GETMENUSHOWDELAY)`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa), so the registry value is normally used through the API. If that API fails and no cached value exists, it falls back to `4 * GetDoubleClickTime() / 5`, means the fallback depends on the current double click speed (`HKCU\Control Panel\Mouse\DoubleClickSpeed`). By default it's set to `500 ms` = fallback becomes `400 ms`.

```c
if ( (_DWORD)v2 == 32771 )
  goto LABEL_19;
if ( (_DWORD)v2 != 32776 )
{
  if ( (_DWORD)v2 != 32777 )
  {
    if ( (_DWORD)v2 == 32778 )
    {
      v4 = 60000; // fixed 60 seconds
    }
    else if ( (_DWORD)v2 == 32779 )
    {
      v4 = 2 * GetDoubleClickTime(); // ignores MenuShowDelay
    }
    return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
  }
LABEL_19:
  v4 *= 2;
  if ( v4 < 2000 )
    v4 = 2000;
  return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
}
if ( ((_BYTE)this[15] & 1) == 0 )
  return 1LL;
v5 = *((_QWORD *)this[5] + 34);
if ( !v5 || (*(_BYTE *)(v5 + 72) & 1) != 0 || ((_BYTE)this[15] & 0x20) != 0 )
  return 1LL;
v4 *= 5;
if ( v4 < 2000 )
  v4 = 2000;
return SetTimer(this[2], v2, v4, 0LL); // v4 = uElapse
```

`v4` is the final value passed to [`SetTimer`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-settimer) as `uElapse`, which can be used as maximum I guess (as the part above doesn't show any max clamp) values below `USER_TIMER_MINIMUM` (`10 ms`) are increased to `10 ms`, values above `USER_TIMER_MAXIMUM` (`0x7FFFFFFF`, `~24.8 days`) are lowered to that maximum. Obviously, that's just my current interpretation, and I don't claim that it's the truth.

The normal menu hover timers use `MenuShowDelay`, some menu timers ignore or extend it, `32771` & `32777` use at least `2 seconds`, `32776` can use at least `2 seconds` after multiplying the value by `5`, `32778` is fixed to `60 seconds`, `32779` uses double click time instead.

# Disable Audio / Video Preview

Disables the preview function for (extensions):

```
3gp aac avi flac m4a m4v mkv mod mov mp3 mp4 mpeg mpg ogg ts vob wav webm wma wmv
```

[`{E357FCCD-A995-4576-B01F-234630154E96}`](https://learn.microsoft.com/en-us/windows/win32/shell/handlers#handler-names) = Thumbnail Provider (Thumbnail image handler)
[`{BB2E617C-0920-11D1-9A0B-00C04FC2D6C1}`](https://learn.microsoft.com/en-us/windows/win32/shell/handlers#handler-names) = Extract Image (Image handler)
[`{9DBD2C50-62AD-11D0-B806-00C04FD706EC}`](https://learn.microsoft.com/en-us/windows/win32/shell/handlers#handler-names) = Default shell extension handler for thumbnails

### Enabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/audiovidpreon.png?raw=true)

### Disabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/audiovidpreonoff.png?raw=true)

# Classic Context Menu

Use it on W11, unless you like the new menu. This works via causing COM to not load the DLL for the `{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}` CLSID by making [ImprocServer32](https://learn.microsoft.com/en-us/windows/win32/com/inprocserver32) empty.

```powershell
[HKEY_CLASSES_ROOT\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}]
@="File Explorer Context Menu"

[HKEY_CLASSES_ROOT\CLSID\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\InProcServer32]
@="C:\\Windows\\System32\\Windows.UI.FileExplorer.dll" // enabling would caus it to be empty
```

### Default

![](https://github.com/nohuto/win-config/blob/main/visibility/images/classiconb.png?raw=true)

### Old

![](https://github.com/nohuto/win-config/blob/main/visibility/images/classicona.png?raw=true)

## 'New' Context Menu

Instead of creating a `.txt` file, then renaming it to e.g. `.bat` / `.ps1`, you can add these options to the 'new' context menu. This may also change the `Type` shown in the explorer (only `.bat` is affected of the three).

`Remove 'Add to Favorites' Option`, `Remove 'Share' Option`, `Remove 'Send to' Option`, `Remove 'bmp'/'zip' Options` don't have a revert yet.

![](https://github.com/nohuto/win-config/blob/main/visibility/images/newcontext1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/visibility/images/newcontext2.png?raw=true)

# Hide Shortcut Icon

Removes the `- Shortcut` text, hides the shortcut & compression arrows. Works by replacing the shortcut `.ico` with a [blank image](https://github.com/nohuto/Files/releases/download/miscellaneous/Blank.ico).

### Before

![](https://github.com/nohuto/win-config/blob/main/visibility/images/shortcutbefore.png?raw=true)

### After

![](https://github.com/nohuto/win-config/blob/main/visibility/images/shortcutafter.png?raw=true)

# Desktop Icon Spacing

Location:

```c
\Registry\User\S-ID\Control Panel\Desktop\WindowMetrics : IconSpacing // horizontal
\Registry\User\S-ID\Control Panel\Desktop\WindowMetrics : IconVerticalSpacing // vertical
```

- Default: `75px` (`-1125`)
- Min: `32px` (`-480`)
- Max: `182px` (`-2730`)

Value gets calculated with:

```c
-15*px

-15*75 = -1125 // default
```

I created a small [tool](https://github.com/nohuto/win-config/blob/main/visibility/assets/iconSpacing.ps1) for fun, since it's a lot easier to quickly change and test the different icon spacing. You've to log out after applying, otherwise it won't update instantly (the images show vertical `75px` & `100px` difference). I personally use `110px Horizonzal - 60px Vertical` for a more vertical compact view and more space horizontally (see suboption).

### `75px`

![](https://github.com/nohuto/win-config/blob/main/visibility/images/iconspacing75.png?raw=true)

### `100px`

![](https://github.com/nohuto/win-config/blob/main/visibility/images/iconspacing100.png?raw=true)

---

Desktop icon size:

```c
"HKCU\\Software\\Microsoft\\Windows\\Shell\\Bags\\1\\Desktop";
  "IconSize" = 32 // 32 = Small, 48 = Medium, 96 = Large
```

# Detailed File Transfer

When you copy, move, or delete a file or folder, a progress dialog appears. You can switch between `More details` and `Fewer details`. By default, the dialog opens in the same view you last used (if you didn't switch it yet, `0` is used).

### EnthusiastMode Disabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/filetransfer0.png?raw=true)

### EnthusiastMode Enabled

![](https://github.com/nohuto/win-config/blob/main/visibility/images/filetransfer1.png?raw=true)

# Alt-Tab App Tabs

Select the amount of recent tabs from apps in the alt+tab menu.

### Don't show tabs

![](https://github.com/nohuto/win-config/blob/main/visibility/images/0tabs.png?raw=true)

### 3 Tabs

![](https://github.com/nohuto/win-config/blob/main/visibility/images/3tabs.png?raw=true)

### 5 Tabs

![](https://github.com/nohuto/win-config/blob/main/visibility/images/5tabs.png?raw=true)

### 20 Tabs

![](https://github.com/nohuto/win-config/blob/main/visibility/images/20tabs.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure the inclusion of app tabs into Alt-Tab](https://noverse.dev/policies?p=Multitasking*BrowserAltTabBlowout) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `MultiTaskingAltTabFilter` |

The option changes it via `HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced`.

## Classic Task Switcher

Restarting the explorer is enough to apply the changes.

### New

![](https://github.com/nohuto/win-config/blob/main/visibility/images/taskswitchnew.png?raw=true)

### Classic

![](https://github.com/nohuto/win-config/blob/main/visibility/images/taskswitchold.png?raw=true)

# Hide Lock Screen

Disables the lock screen (skips the lock screen and go directly to the login screen). See content below for details on the suboptions.

Add a custom text to the sign in screen via:

```c
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System
// legalnoticecaption -	Type: REG_SZ - Data: Noverse
// legalnoticetext	- Type: REG_SZ - Data: https://noverse.dev
```

By adding them, you'll have to click `OK` every time you boot/log in:

![](https://github.com/nohuto/win-config/blob/main/visibility/images/legalnotice.png?raw=true)

### Accounts Captures

`Accounts > Sign-in options` - `Automatically save my restartable apps and restart them when I sign back in`:
```c
// Off
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\RestartApps    Type: REG_DWORD, Length: 4, Data: 0

// On
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\RestartApps    Type: REG_DWORD, Length: 4, Data: 1
```

`Accounts > Sign-in options` - `Show account details such as my email address on the sign-in screen`:
```c
// On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-{ID}\AnyoneRead\Logon\ShowEmail	Type: REG_DWORD, Length: 4, Data: 1

// Off
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\SystemProtectedUserData\S-{ID}\AnyoneRead\Logon\ShowEmail	Type: REG_DWORD, Length: 4, Data: 0
```

### Personalization Captures

`Personalization > Lock screen` - `Personalize your lock screen`:
```c
// Windows spotlight
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\RotatingLockScreenEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Authentication\LogonUI\Creative\S-{ID}\RotatingLockScreenEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\Subscriptions\338387\SubscriptionContext	Type: REG_SZ, Length: 20, Data: sc-mode=0
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Control Panel\Desktop\LockScreenAutoLockActive	Type: REG_SZ, Length: 4, Data: 0

// Picture
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\RotatingLockScreenEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Authentication\LogonUI\Creative\S-{ID}\RotatingLockScreenEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\Subscriptions\338387\SubscriptionContext	Type: REG_SZ, Length: 20, Data: sc-mode=1
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Control Panel\Desktop\LockScreenAutoLockActive	Type: REG_SZ, Length: 4, Data: 0
HKCU\Control Panel\Desktop\DelayLockInterval // deletevalue

// Slideshow
HKCU\Control Panel\Desktop\SCRNSAVE.EXE	// deletevalue
HKCU\Control Panel\Desktop\LockScreenAutoLockActive	Type: REG_SZ, Length: 4, Data: 1
HKCU\Control Panel\Desktop\DelayLockInterval	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowEnabled	Type: REG_DWORD, Length: 4, Data: 1
// Include camera roll folders from this PC and OneDrive (Slideshow only)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowIncludeCameraRoll	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowIncludeCameraRoll	Type: REG_DWORD, Length: 4, Data: 0
// Only use pictures that fit my screen
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowOptimizePhotoSelection	Type: REG_DWORD, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowOptimizePhotoSelection	Type: REG_DWORD, Length: 4, Data: 0
// When my PC is inactive, show the lock screen instead of turning off the screen
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowAutoLock	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Control Panel\Desktop\LockScreenAutoLockActive	Type: REG_SZ, Length: 4, Data: 1
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowAutoLock	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Control Panel\Desktop\LockScreenAutoLockActive	Type: REG_SZ, Length: 4, Data: 0
// Turn off the screen after the slidshow has played for
// Don't turn off
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowDuration	Type: REG_DWORD, Length: 4, Data: 0
// 3H
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowDuration	Type: REG_DWORD, Length: 4, Data: 10800000
// 1H
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowDuration	Type: REG_DWORD, Length: 4, Data: 3600000
// 30min
HKCU\Software\Microsoft\Windows\CurrentVersion\Lock Screen\SlideshowDuration	Type: REG_DWORD, Length: 4, Data: 1800000

// Get fun facts, tips, tricks, and more on your lock screen (for Picture/Slideshow)
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\RotatingLockScreenOverlayEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Authentication\LogonUI\Creative\S-{ID}\RotatingLockScreenOverlayEnabled	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\SubscribedContent-338387Enabled	Type: REG_DWORD, Length: 4, Data: 0
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\RotatingLockScreenOverlayEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Authentication\LogonUI\Creative\S-{ID}\RotatingLockScreenOverlayEnabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\SubscribedContent-338387Enabled	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\ContentDeliveryManager\Subscriptions\338387\SubscriptionContext	Type: REG_SZ, Length: 20, Data: sc-mode=1
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not display the lock screen](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoLockScreen) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoLockScreen` |
| [Prevent changing lock screen and logon image](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoChangingLockScreen) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoChangingLockScreen` |
| [Prevent lock screen background motion](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_AnimateLockScreenBackground) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `AnimateLockScreenBackground` |
| [Prevent enabling lock screen slide show](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoLockScreenSlideshow) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoLockScreenSlideshow` |
| [Prevent enabling lock screen camera](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_NoLockScreenCamera) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `NoLockScreenCamera` |
| [Force a specific default lock screen and logon image](https://noverse.dev/policies?p=ControlPanelDisplay*CPL_Personalization_ForceDefaultLockScreen) | `HKLM\Software\Policies\Microsoft\Windows\Personalization` | `LockScreenImage`<br>`LockScreenOverlaysDisabled` |
| [Show clear logon background](https://noverse.dev/policies?p=Logon*DisableAcrylicBackgroundOnLogon) | `HKLM\Software\Policies\Microsoft\Windows\System` | `DisableAcrylicBackgroundOnLogon` |

# PowerShell Colors

Since `powershell.exe` has default color of white (foreground) and blue (background), some may want to change it. If you use Windows Terminal, this option will have no effect.

- `ScreenColors`, located in `HKCU\Console\%WINDIR%_System32_WindowsPowerShell_v1.0_powershell.exe`  
  - `0-3` bit = `Foreground color`  
  - `4-7` bit = `Background color`

### Color Table

| Color | Binary | Decimal |
| ----- | :----: | :-----: |
| Black | `0000` | `0` |
| DarkBlue | `0001` | `1` |
| DarkGreen | `0010` | `2` |
| DarkCyan | `0011` | `3` |
| DarkRed | `0100` | `4` |
| DarkMagenta | `0101` | `5` |
| DarkYellow | `0110` | `6` |
| Gray | `0111` | `7` |
| DarkGray | `1000` | `8` |
| Blue | `1001` | `9` |
| Green | `1010` | `10` |
| Cyan | `1011` | `11` |
| Red | `1100` | `12` |
| Magenta | `1101` | `13` |
| Yellow | `1110` | `14` |
| White | `1111` | `15` |

Calculate it on your own, by using [bitmask-calc](https://noverse.dev/#bitmask) - e.g. set bit `1-3` and `7`, to get `Yellow` (foreground) and `DarkGray` (background).

## Miscellaneous Notes

If you've set a custom foreground/background color, they won't override the colors changed within the code, e.g.:

```powershell
Write-Host "Noverse"
```

`Noverse` will have use foreground & background color of `ScreenColors`

```powershell
Write-Host "Noverse" -ForegroundColor Blue
```

`Noverse` will be blue, `ScreenColors` gets skipped.

```powershell
[console]::BackgroundColor = 'Black'
```

If it doesn't get changed within the code, it'll use the background color set by `ScreenColor`.

# Classic Control Panel

> "*This policy setting controls the default Control Panel view, whether by category or icons. If this policy setting is enabled, the Control Panel opens to the icon view. If this policy setting is disabled, the Control Panel opens to the category view.*"

### Icon View

![](https://github.com/nohuto/win-config/blob/main/visibility/images/panel0.png?raw=true)

### Category View

![](https://github.com/nohuto/win-config/blob/main/visibility/images/panel1.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Always open All Control Panel Items when opening Control Panel](https://noverse.dev/policies?p=ControlPanel*ForceClassicControlPanel) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `ForceClassicControlPanel` |

# OEM Information

Set your own support information in `System > About` (or `Control Panel > System and Security > System`). All values are saved in:
```
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\OEMInformation
```

You used to change the logo via:

```json
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\OEMInformation": {
  "Logo": { "Type": "REG_SZ", "Data": "path\\OEM.bmp" }
}
```

But it seems deprecated (doesn't work for me). Limitation were `120x120` pixels, `.bmp` file & `32-bit` color depth.

Edit registered owner/orga (visible in `winver`) via:

```json
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion": {
  "RegisteredOwner": { "Type": "REG_SZ", "Data": "Nohuto" },
  "RegisteredOrganization": { "Type": "REG_SZ", "Data": "Noverse" }
}
```

Edit miscellaneous things in `winver.exe` using (`basebrd.dll`/`basebrd.dll.mui`) [resourcehacker](https://www.angusj.com/resourcehacker/).

### Example

```json
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\OEMInformation": {
  "Manufacturer": { "Type": "REG_SZ", "Data": "Noverse" },
  "Model": { "Type": "REG_SZ", "Data": "Windows 11" },
  "SupportHours": { "Type": "REG_SZ", "Data": "24H" },
  "SupportPhone": { "Type": "REG_SZ", "Data": "noverse@example.dev" },
  "SupportURL": { "Type": "REG_SZ", "Data": "https://discord.noverse.dev" }
}
```

![](https://github.com/nohuto/win-config/blob/main/visibility/images/oem.png?raw=true)

# Settings Page Visibility

It controls which pages in the windows settings app are visible (blocked pages are removed from view and direct access redirects to the main settings page).

> "*This policy allows an administrator to block a given set of pages from the System Settings app. Blocked pages will not be visible in the app, and if all pages in a category are blocked the category will be hidden as well. Direct navigation to a blocked page via URI, context menu in Explorer or other means will result in the front page of Settings being shown instead.*"

```c
HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer : SettingsPageVisibility // REG_SZ
```

- `showonly:` followed by a semicolon separated list of page identifiers to allow
- `hide:` followed by a list of pages to block

Page identifiers are the part after `ms-settings:` in a settings URI.

### Example

`showonly:bluetooth` only shows the `Bluetooth` page
`hide:bluetooth;windowsdefender` hides the `Bluetooth` & `Windows Security` pages

See a list of all categories of `ms-settings` URIs [here](https://learn.microsoft.com/en-us/windows/apps/develop/launch/launch-settings-app#ms-settings-uri-scheme-reference).

### Example Value

This is what the option currently uses, whenever you want to add/remove a section, edit the value.

```bat
hide:home;recovery;troubleshoot;activation;network-dialup;deviceusage;maps;emailandaccounts;otherusers;sync;family-group;workplace;speech;findmydevice;windowsdefender
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Settings Page Visibility](https://noverse.dev/policies?p=ControlPanel*SettingsPageVisibility) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` <br> `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `SettingsPageVisibility` |

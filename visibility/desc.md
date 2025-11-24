# Desktop Wallpaper

This is a collection of a few wallapapers I collected. This was added for people who may never have spent time changing their background, or for anyone else.

`Asia`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Asia.png?raw=true)

`Austria`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Austria.png?raw=true)

`Beach`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Beach.png?raw=true)

`Blue Flowers`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Blue-Flowers.png?raw=true)

`Castle`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Castle.png?raw=true)

`Cat`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Cat.png?raw=true)

`Flowers`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Flowers.png?raw=true)

`Heaven`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Heaven.png?raw=true)

`Lake`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Lake.png?raw=true)

`Mac`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Mac.png?raw=true)

`Moon`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Moon.png?raw=true)

`Moon Castle`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Moon-Castle.png?raw=true)

`Plants Room`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Plants-Room.png?raw=true)

`Pokemon`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Pokemon.png?raw=true)

`Rain`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Rain.png?raw=true)

`Sea`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Sea.png?raw=true)

`Stars`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Stars.png?raw=true)

`Sunset`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Sunset.png?raw=true)

`Village`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Village.png?raw=true)

`Workplace`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Workplace.png?raw=true)

`Zelda`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/wallpaper/Zelda.png?raw=true)

It get's changed via the "Wallpaper" policy:
```json
{
  "File": "Desktop.admx",
  "CategoryName": "ActiveDesktop",
  "PolicyName": "Wallpaper",
  "NameSpace": "Microsoft.Policies.WindowsDesktop",
  "Supported": "Win2k - At least Windows 2000",
  "DisplayName": "Desktop Wallpaper",
  "ExplainText": "Specifies the desktop background (\"wallpaper\") displayed on all users' desktops. This setting lets you specify the wallpaper on users' desktops and prevents users from changing the image or its presentation. The wallpaper you specify can be stored in a bitmap (*.bmp) or JPEG (*.jpg) file. To use this setting, type the fully qualified path and name of the file that stores the wallpaper image. You can type a local path, such as C:\\Windows\\web\\wallpaper\\home.jpg or a UNC path, such as \\\\Server\\Share\\Corp.jpg. If the specified file is not available when the user logs on, no wallpaper is displayed. Users cannot specify alternative wallpaper. You can also use this setting to specify that the wallpaper image be centered, tiled, or stretched. Users cannot change this specification. If you disable this setting or do not configure it, no wallpaper is displayed. However, users can select the wallpaper of their choice. Also, see the \"Allow only bitmapped wallpaper\" in the same location, and the \"Prevent changing wallpaper\" setting in User Configuration\\Administrative Templates\\Control Panel. Note: This setting does not apply to remote desktop server sessions.",
  "KeyPath": [
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "Elements": [
    { "Type": "Text", "ValueName": "Wallpaper" },
    { "Type": "Enum", "ValueName": "WallpaperStyle", "Items": [
        { "DisplayName": "Center", "Data": "0" },
        { "DisplayName": "Tile", "Data": "1" },
        { "DisplayName": "Stretch", "Data": "2" },
        { "DisplayName": "Fit", "Data": "3" },
        { "DisplayName": "Fill", "Data": "4" },
        { "DisplayName": "Span", "Data": "5" }
      ]
    }
  ]
},
```

# Explorer Options

It changes every setting, which is shown in the `Folder Options` window. Some are personal preference.

Enable compact mode:
```bat
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v UseCompactMode /t REG_DWORD /d 1
```
Set it to `0` to get the default mode back.

Show hidden & protected files/folders:
```bat
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v Hidden /t REG_DWORD /d 1 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v ShowSuperHidden /t REG_DWORD /d 1 /f
```
Set `Hidden` to `2` and `ShowSuperHidden` to `0` to disable it.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/explorer.png?raw=true)

---

Miscellaneous notes:
```powershell
"TaskbarDa": { "Type": "REG_DWORD", "Data": 0 } # Access denied

reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer" /v ShellState /t REG_BINARY /d 24,00,00,00,3e,20,00,00,00,00,00,00,00,00,00,00,00,00,00,00,01,00,00,00,13,00,00,00,00,00,00,00,42,00,00,00 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\CabinetState" /v Settings /t REG_BINARY /d 0c,00,02,00,0a,01,00,00,60,00,00,00 /f
```

```json
  {
    "File": "WindowsConnectNow.admx",
    "CategoryName": "WCN_Category",
    "PolicyName": "WCN_DisableWcnUi_2",
    "NameSpace": "Microsoft.Policies.WindowsConnectNow",
    "Supported": "WindowsVista",
    "DisplayName": "Prohibit access of the Windows Connect Now wizards",
    "ExplainText": "This policy setting prohibits access to Windows Connect Now (WCN) wizards. If you enable this policy setting, the wizards are turned off and users have no access to any of the wizard tasks. All the configuration related tasks, including \"Set up a wireless router or access point\" and \"Add a wireless device\" are disabled. If you disable or do not configure this policy setting, users can access the wizard tasks, including \"Set up a wireless router or access point\" and \"Add a wireless device.\" The default for this policy setting allows users to access all WCN wizards.",
    "KeyPath": [
      "HKLM\\Software\\Policies\\Microsoft\\Windows\\WCN\\UI"
    ],
    "ValueName": "DisableWcnUi",
    "Elements": [
      { "Type": "EnabledValue", "Data": "1" },
      { "Type": "DisabledValue", "Data": "0" }
    ]
  },
```

> https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-admx-windowsconnectnow

# Enable Dark Theme

`darktheme-GetThemeFromUnattendSetup.c` for information about the comments, otherwise ignore them.

> [visibility/assets | darktheme-GetThemeFromUnattendSetup.c](https://github.com/5Noxi/win-config/blob/main/visibility/assets/darktheme-GetThemeFromUnattendSetup.c)

The pictures below show: `Dark Theme`, `Light Theme`.

Change accent color via registry (ARGB):
```bat
reg add "HKCU\Software\Microsoft\Windows\DWM" /v ColorizationColor /t REG_DWORD /d 3292809298 /f
reg add "HKCU\Software\Microsoft\Windows\DWM" /v ColorizationAfterglow /t REG_DWORD /d 3292809298 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent" /v AccentPalette /t REG_BINARY /d 646a79ff575c68ff4d525dff444852ff3a3d46ff30333bff23252aff88179800 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent" /v StartColorMenu /t REG_DWORD /d 4282793274 /f
reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Accent" /v AccentColorMenu /t REG_DWORD /d 4283582532 /f
```
This would apply dark nord color scheme.
> https://www.nordtheme.com/

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/darktheme1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/darktheme2.png?raw=true)


# Disable Transparency

The pictures below show: `Transparency On`, `Transparency Off`.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/transpa1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/transpa2.png?raw=true)

# Disable Audio / Video Preview

Disables the preview function for (extensions):
```
3gp aac avi flac m4a m4v mkv mod mov mp3 mp4 mpeg mpg ogg ts vob wav webm wma wmv
```
`{E357FCCD-A995-4576-B01F-234630154E96}` - Thumbnail Provider (Thumbnail image handler)
`{BB2E617C-0920-11D1-9A0B-00C04FC2D6C1}` - Extract Image (Image handler)
`{9DBD2C50-62AD-11D0-B806-00C04FD706EC}` - Default shell extension handler for thumbnails
> https://learn.microsoft.com/en-us/windows/win32/shell/handlers#handler-names  
> https://learn.microsoft.com/en-us/windows/win32/api/thumbcache/nn-thumbcache-ithumbnailprovider  
> https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nn-shobjidl_core-iextractimage

Enabled:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/audiovidpreon.png?raw=true)

Disabled:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/audiovidpreonoff.png?raw=true)

---

Hide preview pane:
```powershell
"Explorer.EXE","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Modules\GlobalSettings\Sizer\DetailsContainerSizer","Type: REG_BINARY, Length: 16, Data: 15 01 00 00 00 00 00 00 00 00 00 00 6B 03 00 00"
"Explorer.EXE","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Modules\GlobalSettings\DetailsContainer\DetailsContainer","Type: REG_BINARY, Length: 8, Data: 02 00 00 00 02 00 00 00"
```

# Remove Home & Gallery

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/homegal.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/homenet.png?raw=true)

---

Miscellaneous comments:
```bat
:: LaunchTo:
:: 1 = This PC
:: 2 = Home (default)
:: 3 = Downloads
:: 4 = OneDrive
reg add "HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced" /v LaunchTo /t REG_DWORD /d 1 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer" /v HubMode /t REG_DWORD /d 1 /f
```

# Classic Context Menu

Use it on W11, unless you like the new menu - remove the key, to revert it.

Before & after:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/classiconb.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/classicona.png?raw=true)

# Disable Animations

Minimize, Maximize, Taskbar Animations / First Sign-In Animations. These options are also changeable via `SystemPropertiesPerformance` (`WIN + R`) - first three.

`MaxAnimate` doesn't exist, windows only uses `MinAnimate`
```
SystemPropertiesAdvanced.exe	RegSetValue	HKCU\Control Panel\Desktop\WindowMetrics\MinAnimate	Type: REG_SZ, Length: 4, Data: 1
```
Disable logon animations, which would remove the animation (picture), instead shows the windows default background wallpaper: (first sign-in):
```
This policy controls whether users see the first sign-in animation when signing in for the first time, including both the initial setup user and those added later. It also determines if Microsoft account users receive the opt-in prompt for services. If enabled, Microsoft account users see the opt-in prompt and other users see the animation. If disabled, neither the animation nor the opt-in prompt appears. If not configured, the first user sees the animation during setup; later users won't see it if setup was already completed. This policy has no effect on Server editions.
```
```bat
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System" /v EnableFirstLogonAnimation /t REG_DWORD /d 0 /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /v EnableFirstLogonAnimation /t REG_DWORD /d 0 /f
```
First one is the value, which gets used by windows (`Computer Configuration > Administrative Templates > System > Logon : Show first sign-in animation`, the second one does exist:
```c
CMachine::RegQueryDWORD(
  v62,
  L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
  L"EnableFirstLogonAnimation",
  0,
  &v117);
v118 = 1;

CMachine::RegQueryDWORD(
  v63,
  L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
  L"EnableFirstLogonAnimation",
  1u,
  &v118);
```
`AnimationAfterUserOOBE` & `SkipNextFirstLogonAnimation` (`CurrentVersion\Winlogon`) also exist.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/ControlPanel-Desktop.txt  
> [visibility/assets | animation-WinMain.c](https://github.com/5Noxi/win-config/blob/main/visibility/assets/animation-WinMain.c)

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/animation.png?raw=true)

```json
{
  "File": "Explorer.admx",
  "CategoryName": "WindowsExplorer",
  "PolicyName": "TurnOffSPIAnimations",
  "NameSpace": "Microsoft.Policies.WindowsExplorer2",
  "Supported": "WindowsVista",
  "DisplayName": "Turn off common control and window animations",
  "ExplainText": "This policy is similar to settings directly available to computer users. Disabling animations can improve usability for users with some visual disabilities as well as improving performance and battery life in some scenarios.",
  "KeyPath": [
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "ValueName": "TurnOffSPIAnimations",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "Logon.admx",
  "CategoryName": "Logon",
  "PolicyName": "EnableFirstLogonAnimation",
  "NameSpace": "Microsoft.Policies.WindowsLogon",
  "Supported": "Windows8",
  "DisplayName": "Show first sign-in animation",
  "ExplainText": "This policy setting allows you to control whether users see the first sign-in animation when signing in to the computer for the first time. This applies to both the first user of the computer who completes the initial setup and users who are added to the computer later. It also controls if Microsoft account users will be offered the opt-in prompt for services during their first sign-in. If you enable this policy setting, Microsoft account users will see the opt-in prompt for services, and users with other accounts will see the sign-in animation. If you disable this policy setting, users will not see the animation and Microsoft account users will not see the opt-in prompt for services. If you do not configure this policy setting, the user who completes the initial Windows setup will see the animation during their first sign-in. If the first user had already completed the initial setup and this policy setting is not configured, users new to this computer will not see the animation. Note: The first sign-in animation will not be shown on Server, so this policy will have no effect.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "ValueName": "EnableFirstLogonAnimation",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DWM.admx",
  "CategoryName": "CAT_DesktopWindowManager",
  "PolicyName": "DwmDisallowAnimations_2",
  "NameSpace": "Microsoft.Policies.DesktopWindowManager",
  "Supported": "WindowsVista",
  "DisplayName": "Do not allow window animations",
  "ExplainText": "This policy setting controls the appearance of window animations such as those found when restoring, minimizing, and maximizing windows. If you enable this policy setting, window animations are turned off. If you disable or do not configure this policy setting, window animations are turned on. Changing this policy setting requires a logoff for it to be applied.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DWM"
  ],
  "ValueName": "DisallowAnimations",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Automatic Folder Type Discovery

"Folder discovery is a feature that customizes the view settings of folders based on their content. For example, a folder with images might display thumbnails, while a folder with documents might show a list view. While this can be useful, it can also be frustrating if you prefer a uniform view for all folders."

Removing the `Bags` & `BagMRU` key resets all folder settings (view, size,...), `NotSpecified` sets the template to `General Items`. The other templates would be `Documents`, `Music`, `Videos` (folder: `Properties > Customize > Optimize this folder for:`)

The revert may not work correctly yet, as it only creates the `Bags`/`BagsMRU` keys.

> https://www.insomniacgeek.com/posts/how-to-disable-windows-folder-discovery/  
> https://github.com/LesFerch/WinSetView

# Hide Language Bar

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/languagebar.png?raw=true)

`Time & language > Typing > Advanced keyboard settings > Language bar options`:
```c
// Floating On Desktop
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 0

// Hidden
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 3

// Docked in the taskbar
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\ShowStatus	Type: REG_DWORD, Length: 4, Data: 4
```

`Show the Language bar as transparent when inactive`:
```c
// Enabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\Transparency	Type: REG_DWORD, Length: 4, Data: 64

// Disabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\Transparency	Type: REG_DWORD, Length: 4, Data: 255
```

`Show additional Language bar icons in the taskbar`:
```c
// Enabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\ExtraIconsOnMinimized	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\ExtraIconsOnMinimized	Type: REG_DWORD, Length: 4, Data: 0
```

`Show text labels on the Language bar`:
```c
// Enabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\Label	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
RegSetValue	HKCU\Software\Microsoft\CTF\LangBar\Label	Type: REG_DWORD, Length: 4, Data: 0
```

# System Clock Seconds

"Uses more power" (in relation to laptops).

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/clock.png?raw=true)

# Taskbar Settings

Removes the search box, moves the taskbar to the left, removes badges, disables the orange flashes on the app icons, removes the "Task View" button. (`Personalization > Taskbar`)

Remove the `End Task` option to the taskbar right click menu with:
```bat
reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDeveloperSettings" /v TaskbarEndTask /f
```
Enabling it via `System > For developers`:
```powershell
SystemSettings.exe	RegSetValue	HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\TaskbarDeveloperSettings\TaskbarEndTask	Type: REG_DWORD, Length: 4, Data: 1
```

`TaskbarSd` adds/removes the block in the right corner, which shows the desktop (picture).

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/taskbar.png?raw=true)

# Optimize Visual Effects

`UserPreferencesMask`:

|Position|Meaning|
|:------:|:-----:|
|1|N/A|
|5|Smooth-scroll list boxes|
|6|Slide open combo boxes|
|7|Fade or slied Menus in to view|
|8|N/A|
|11|Show shadows under mouse pointer|
|12|N/A|
|13|Fade or slide tooltips in to view|
|14|Fade out menu items after clicking|
|15|N/A|
|18|Show shadows under windows|
|19|N/A|
|39|Animate controls and elements inside windows|
|48|Use the desktop language bar for when it’s available|
|64|N/A|

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/visual1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/visual2.png?raw=true)

> https://gist.github.com/omar-irizarry/d469e1642e3b27df1eebd1e907ffe61d

# Hide Shortcut Icon

Removes the `- Shortcut` text, hides the shortcut & compression arrows. Works by replacing the shortcut `.ico` with a [blank image](https://github.com/5Noxi/Files/releases/download/miscellaneous/Blank.ico).

Before:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/shortcutbefore.png?raw=true)

After:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/shortcutafter.png?raw=true)

# 'New' Context Menu

Instead of creating a `.txt` file, then renaming it to e.g. `.bat` / `.ps1`, you can add these options to the 'new' context menu. This may also change the `Type` shown in the explorer (only `.bat` is affected of the three).

Edit the text, by editing `Default` (value empty) and `FriendlyTypeName`:
```bat
:: PowerShell
reg add "HKCR\ps1legacy" /ve /d "pwsh" /f
reg add "HKCR\ps1legacy" /v FriendlyTypeName /t REG_SZ /d "pwsh" /f
:: Text
reg add "HKCR\txtlegacy" /ve /d "txt" /f
reg add "HKCR\txtlegacy" /v FriendlyTypeName /t REG_SZ /d "txt" /f
:: Batch
reg add "HKCR\batfile" /ve /d "bat" /f
reg add "HKCR\batfile" /v FriendlyTypeName /t REG_SZ /d "bat" /f
```

`Remove 'Add to Favorites' Option`, `Remove 'Share' Option`, `Remove 'Send to' Option`, `Remove 'bmp'/'zip' Options` don't have a revert yet.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/newcontext1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/newcontext2.png?raw=true)

# Desktop Icon Spacing

Location:
```
\Registry\User\S-ID\Control Panel\Desktop\WindowMetrics : IconSpacing
\Registry\User\S-ID\Control Panel\Desktop\WindowMetrics : IconVerticalSpacing
```
`IconSpacing` = Horizontal
`IconVerticalSpacing` = Vertical

Default: `75px` (`-1125`)
Min: `32px` (`-480`)
Max: `182px` (`-2730`)

Personal preference - `100px` horizontal, `75px` vertical:

```bat
reg add "HKCU\Control Panel\Desktop\WindowMetrics" /v IconSpacing /t REG_SZ /d -1500 /f
reg add "HKCU\Control Panel\Desktop\WindowMetrics" /v IconVerticalSpacing /t REG_SZ /d -1125 /f
reg add "HKCU\Control Panel\Desktop\WindowMetrics" /v IconTitleWrap /t REG_SZ /d 0 /f
```

Value gets calculated with:
```c
-15*px

-15*75 = -1125 // default
```
I created a small tool for fun, since it's a lot easier to quickly change and test the different icon spacing. You've to log out after applying, otherwise it won't update instantly. (the images show vertical `75px` & `100px` difference)

Set the icon view size to `Small` with:
```bat
reg add "HKCU\SOFTWARE\Microsoft\Windows\Shell\Bags\1\Desktop" /v IconSize /t REG_DWORD /d 32 /f
reg add "HKCU\SOFTWARE\Microsoft\Windows\Shell\Bags\1\Desktop" /v Mode /t REG_DWORD /d 1 /f
reg add "HKCU\SOFTWARE\Microsoft\Windows\Shell\Bags\1\Desktop" /v LogicalViewMode /t REG_DWORD /d 3 /f
```
`75px`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/iconspacing75.png?raw=true)

`100px`:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/iconspacing100.png?raw=true)

# Detailed File Transfer

When you copy, move, or delete a file or folder, a progress dialog appears. You can switch between `More details` and `Fewer details`. By default, the dialog opens in the same view you last used (if you didn't switch it yet, `0` is used).

`EnthusiastMode` - `0` = fewer detailes:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/filetransfer0.png?raw=true)

`EnthusiastMode` - `1` = more details:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/filetransfer1.png?raw=true)

# Classic Task Switcher

It won't work on 24H2.

New (delete `AltTabSettings`):

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/taskswitchnew.png?raw=true)

Classic (`AltTabSettings` - `1`):

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/taskswitchold.png?raw=true)


# Remove Quick Access

Removes the `Quick access` in the File Explorer & sets `Open File Exporer to` to `This PC`.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/quickaccess.png?raw=true)

# System Fonts / Text Size

W11 uses `Segoe UI` by default. You can change it via registry edits, the selected font will be used for desktop interfaces, explorer, some apps (`StartAllBack` will use it), but won't get applied for e.g., `SystemSettings.exe` and app fonts in general. Some fonts will cause issues - `Yu Gothic UI Light` uses `¥` instead of `\` (picture).

Either select a installed font with the command shown below or install new fonts via e.g.:
> https://www.nerdfonts.com/font-downloads

Apply the selected font replacing the data (`Replace` in the example below):
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Black (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Black Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Bold (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Bold Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Historic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Light (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Light Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semibold (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semibold Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semilight (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semilight Italic (TrueType)" /t REG_SZ /d "" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Symbol (TrueType)" /t REG_SZ /d "" /f

:: Replace "Yu Gothic UI Light"
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\FontSubstitutes" /v "Segoe UI" /t REG_SZ /d "Yu Gothic UI Light" /f

::shutdown -l
```
Applying a new font needs a restart or logout, reverting doesn't.
```powershell
shutdown -l # logout
```
List all available font families on your system with the `Open` option, or via `Personalization > Fonts`:
```powershell
Add-Type -AssemblyName System.Drawing;[System.Drawing.FontFamily]::Families | % {$_.Name}
```
Revert the changes using:
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI (TrueType)" /t REG_SZ /d "segoeui.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Black (TrueType)" /t REG_SZ /d "seguibl.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Black Italic (TrueType)" /t REG_SZ /d "seguibli.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Bold (TrueType)" /t REG_SZ /d "segoeuib.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Bold Italic (TrueType)" /t REG_SZ /d "segoeuiz.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Historic (TrueType)" /t REG_SZ /d "seguihis.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Italic (TrueType)" /t REG_SZ /d "segoeuii.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Light (TrueType)" /t REG_SZ /d "segoeuil.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Light Italic (TrueType)" /t REG_SZ /d "seguili.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semibold (TrueType)" /t REG_SZ /d "seguisb.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semibold Italic (TrueType)" /t REG_SZ /d "seguisbi.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semilight (TrueType)" /t REG_SZ /d "segoeuisl.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Semilight Italic (TrueType)" /t REG_SZ /d "seguisli.ttf" /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts" /v "Segoe UI Symbol (TrueType)" /t REG_SZ /d "seguisym.ttf" /f
reg delete "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\FontSubstitutes" /v "Segoe UI" /f
```

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/font1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/visibility/images/font2.png?raw=true)

Edit text sizes via `TextScaleFactor`, valid ranges are `100-225` (DWORD).
> https://learn.microsoft.com/en-us/uwp/api/windows.ui.viewmanagement.uisettings.textscalefactor?view=winrt-26100#windows-ui-viewmanagement-uisettings-textscalefactor
```c
  v10 = 0;
  if ( (int)SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\Accessibility", L"TextScaleFactor", &v10) < 0
    || (v6 = v10, v10 - 101 > 0x7C) ) // valid range: [101, 225] -> v10 - 101 > 124  -> v10 > 225
  {
    v6 = 100LL; // fallback to 100 if missing or out of range (<100 / >225)
  }
```
Applying changes via `Accessibility > Text size`:
```c
// 100%
RegSetValue    HKCU\Software\Microsoft\Accessibility\TextScaleFactor    Type: REG_DWORD, Length: 4, Data: 100

// 225%
RegSetValue    HKCU\Software\Microsoft\Accessibility\TextScaleFactor    Type: REG_DWORD, Length: 4, Data: 225
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
> [visibility/assets | textsize-TextScaleDialogTemplate.c](https://github.com/5Noxi/win-config/blob/main/visibility/assets/textsize-TextScaleDialogTemplate.c)

# Hide Lock Screen

Disables the lock screen (skips the lock screen and go directly to the login screen). Revert it by removing the value (2nd command).

Add a custom text to the sign in screen via:
```c
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System
// legalnoticecaption -	Type: REG_SZ - Data: Noverse
// legalnoticetext	- Type: REG_SZ - Data: https://5noxi.github.io
```
By adding them, you'll have to click `OK` every time you boot/log in:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/legalnotice.png?raw=true)

---

```json
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_NoLockScreen",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows8",
  "DisplayName": "Do not display the lock screen",
  "ExplainText": "This policy setting controls whether the lock screen appears for users. If you enable this policy setting, users that are not required to press CTRL + ALT + DEL before signing in will see their selected tile after locking their PC. If you disable or do not configure this policy setting, users that are not required to press CTRL + ALT + DEL before signing in will see a lock screen after locking their PC. They must dismiss the lock screen using touch, the keyboard, or by dragging it with the mouse.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "ValueName": "NoLockScreen",
  "Elements": []
},
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_ForceDefaultLockScreen",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows8",
  "DisplayName": "Force a specific default lock screen and logon image",
  "ExplainText": "This setting allows you to force a specific default lock screen and logon image by entering the path (location) of the image file. The same image will be used for both the lock and logon screens. This setting lets you specify the default lock screen and logon image shown when no user is signed in, and also sets the specified image as the default for all users (it replaces the inbox default image). To use this setting, type the fully qualified path and name of the file that stores the default lock screen and logon image. You can type a local path, such as C:\\Windows\\Web\\Screen\\img104.jpg or a UNC path, such as \\\\Server\\Share\\Corp.jpg. This can be used in conjunction with the \"Prevent changing lock screen and logon image\" setting to always force the specified lock screen and logon image to be shown. Note: This setting only applies to Enterprise, Education, and Server SKUs.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "Elements": [
    { "Type": "Text", "ValueName": "LockScreenImage" },
    { "Type": "Boolean", "ValueName": "LockScreenOverlaysDisabled", "TrueValue": "1", "FalseValue": "0" }
  ]
},
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_AnimateLockScreenBackground",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Prevent lock screen background motion",
  "ExplainText": "This policy setting controls whether the lock screen image is static or has a subtle panning effect driven by the device's accelerometer output. If you enable this setting, motion will be prevented and the user will see the traditional static lock screen background image. If you disable this setting (and the device has an accelerometer), the user will see the lock screen background pan around a still image as they physically move their device.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "ValueName": "AnimateLockScreenBackground",
  "Elements": []
},
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_NoLockScreenSlideshow",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows_6_3",
  "DisplayName": "Prevent enabling lock screen slide show",
  "ExplainText": "Disables the lock screen slide show settings in PC Settings and prevents a slide show from playing on the lock screen. By default, users can enable a slide show that will run after they lock the machine. If you enable this setting, users will no longer be able to modify slide show settings in PC Settings, and no slide show will ever start.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "ValueName": "NoLockScreenSlideshow",
  "Elements": []
},
{
  "File": "Logon.admx",
  "CategoryName": "Logon",
  "PolicyName": "DisableAcrylicBackgroundOnLogon",
  "NameSpace": "Microsoft.Policies.WindowsLogon",
  "Supported": "Windows_10_0_RS6",
  "DisplayName": "Show clear logon background",
  "ExplainText": "This policy setting disables the acrylic blur effect on logon background image. If you enable this policy, the logon background image shows without blur. If you disable or do not configure this policy, the logon background image adopts the acrylic blur effect.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "DisableAcrylicBackgroundOnLogon",
  "Elements": []
},
{
  "File": "ControlPanelDisplay.admx",
  "CategoryName": "Personalization",
  "PolicyName": "CPL_Personalization_NoChangingLockScreen",
  "NameSpace": "Microsoft.Policies.ControlPanelDisplay",
  "Supported": "Windows8",
  "DisplayName": "Prevent changing lock screen and logon image",
  "ExplainText": "Prevents users from changing the background image shown when the machine is locked or when on the logon screen. By default, users can change the background image shown when the machine is locked or displaying the logon screen. If you enable this setting, the user will not be able to change their lock screen and logon image, and they will instead see the default image.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Personalization"
  ],
  "ValueName": "NoChangingLockScreen",
  "Elements": []
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
```

# Hide Most Used Apps

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/mostused.jpg?raw=true)

```json
{
  "File": "StartMenu.admx",
  "CategoryName": "StartMenu",
  "PolicyName": "ShowOrHideMostUsedApps",
  "NameSpace": "Microsoft.Policies.StartMenu",
  "Supported": "Windows_10_0_21H2",
  "DisplayName": "Show or hide \"Most used\" list from Start menu",
  "ExplainText": "If you enable this policy setting, you can configure Start menu to show or hide the list of user's most used apps, regardless of user settings. Selecting \"Show\" will force the \"Most used\" list to be shown, and user cannot change to hide it using the Settings app. Selecting \"Hide\" will force the \"Most used\" list to be hidden, and user cannot change to show it using the Settings app. Selecting \"Not Configured\", or if you disable or do not configure this policy setting, all will allow users to turn on or off the display of \"Most used\" list using the Settings app. This is default behavior. Note: configuring this policy to \"Show\" or \"Hide\" on supported versions of Windows 10 will supercede any policy setting of \"Remove frequent programs list from the Start Menu\" (which manages same part of Start menu but with fewer options).",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "ShowOrHideMostUsedApps", "Items": [
        { "DisplayName": "Not Configured", "Data": "0" },
        { "DisplayName": "Show", "Data": "1" },
        { "DisplayName": "Hide", "Data": "2" }
      ]
    }
  ]
},
{
  "File": "StartMenu.admx",
  "CategoryName": "StartMenu",
  "PolicyName": "NoFrequentUsedPrograms",
  "NameSpace": "Microsoft.Policies.StartMenu",
  "Supported": "Windows7ToXPAndWindows10",
  "DisplayName": "Remove frequent programs list from the Start Menu",
  "ExplainText": "If you enable this setting, the frequently used programs list is removed from the Start menu. If you disable this setting or do not configure it, the frequently used programs list remains on the simple Start menu.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer",
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "ValueName": "NoStartMenuMFUprogramsList",
  "Elements": []
},
{
  "File": "StartMenu.admx",
  "CategoryName": "StartMenu",
  "PolicyName": "NoInstrumentation",
  "NameSpace": "Microsoft.Policies.StartMenu",
  "Supported": "WindowsVistaTo2k",
  "DisplayName": "Turn off user tracking",
  "ExplainText": "This policy setting allows you to turn off user tracking. If you enable this policy setting, the system does not track the programs that the user runs, and does not display frequently used programs in the Start Menu. If you disable or do not configure this policy setting, the system tracks the programs that the user runs. The system uses this information to customize Windows features, such as showing frequently used programs in the Start Menu. Also, see these related policy settings: \"Remove frequent programs liist from the Start Menu\" and \"Turn off personalized menus\". This policy setting does not prevent users from pinning programs to the Start Menu or Taskbar. See the \"Remove pinned programs list from the Start Menu\" and \"Do not allow pinning programs to the Taskbar\" policy settings.",
  "KeyPath": [
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "ValueName": "NoInstrumentation",
  "Elements": []
},
```

# Disable Spotlight

Spotlight is used to provide new pictures on your lock screen.

> https://learn.microsoft.com/en-us/windows/configuration/windows-spotlight/?pivots=windows-11#policy-settings  
> https://www.dev2qa.com/how-to-show-or-hide-the-windows-spotlight-learn-about-this-picture-icon-on-windows-11-desktop/

```json
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableWindowsSpotlightFeatures",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Turn off all Windows spotlight features",
  "ExplainText": "This policy setting lets you turn off all Windows Spotlight features at once. If you enable this policy setting, Windows spotlight on lock screen, Windows tips, Microsoft consumer features and other related features will be turned off. You should enable this policy setting if your goal is to minimize network traffic from target devices. If you disable or do not configure this policy setting, Windows spotlight features are allowed and may be controlled individually using their corresponding policy settings.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableWindowsSpotlightFeatures",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableWindowsSpotlightWindowsWelcomeExperience",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_RS2",
  "DisplayName": "Turn off the Windows Welcome Experience",
  "ExplainText": "This policy setting lets you turn off the Windows Spotlight Windows Welcome experience. This feature helps onboard users to Windows, for instance launching Microsoft Edge with a web page highlighting new features. If you enable this policy, the Windows Welcome Experience will no longer display when there are updates and changes to Windows and its apps. If you disable or do not configure this policy, the Windows Welcome Experience will be launched to help onboard users to Windows telling them about what's new, changed, and suggested.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableWindowsSpotlightWindowsWelcomeExperience",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableWindowsSpotlightOnActionCenter",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_RS2",
  "DisplayName": "Turn off Windows Spotlight on Action Center",
  "ExplainText": "If you enable this policy, Windows Spotlight notifications will no longer be shown on Action Center. If you disable or do not configure this policy, Microsoft may display notifications in Action Center that will suggest apps or features to help users be more productive on Windows.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableWindowsSpotlightOnActionCenter",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableWindowsSpotlightOnSettings",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_RS4",
  "DisplayName": "Turn off Windows Spotlight on Settings",
  "ExplainText": "If you enable this policy, Windows Spotlight suggestions will no longer be shown in Settings app. If you disable or do not configure this policy, Microsoft may suggest apps or features in Settings app to help users be productive on Windows or their linked phone.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableWindowsSpotlightOnSettings",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CloudContent.admx",
  "CategoryName": "CloudContent",
  "PolicyName": "DisableSpotlightCollectionOnDesktop",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Turn off Spotlight collection on Desktop",
  "ExplainText": "This policy setting removes the Spotlight collection setting in Personalization, rendering the user unable to select and subsequentyly download daily images from Microsoft to desktop. If you enable this policy, \"Spotlight collection\" will not be available as an option in Personalization settings. If you disable or do not configure this policy, \"Spotlight collection\" will appear as an option in Personalization settings, allowing the user to select \"Spotlight collection\" as the Desktop provider and display daily images from Microsoft on the desktop.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "DisableSpotlightCollectionOnDesktop",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
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
  "PolicyName": "ConfigureWindowsSpotlight",
  "NameSpace": "Microsoft.Policies.CloudContent",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Configure Windows spotlight on lock screen",
  "ExplainText": "This policy setting lets you configure Windows spotlight on the lock screen. If you enable this policy setting, \"Windows spotlight\" will be set as the lock screen provider and users will not be able to modify their lock screen. \"Windows spotlight\" will display daily images from Microsoft on the lock screen. Additionally, if you check the \"Include content from Enterprise spotlight\" checkbox and your organization has setup an Enterprise spotlight content service in Azure, the lock screen will display internal messages and communications configured in that service, when available. If your organization does not have an Enterprise spotlight content service, the checkbox will have no effect. If you disable this policy setting, Windows spotlight will be turned off and users will no longer be able to select it as their lock screen. Users will see the default lock screen image and will be able to select another image, unless you have enabled the \"Prevent changing lock screen image\" policy. If you do not configure this policy, Windows spotlight will be available on the lock screen and will be selected by default, unless you have configured another default lock screen image using the \"Force a specific default lock screen and logon image\" policy. Note: This policy is only available for Enterprise SKUs",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CloudContent"
  ],
  "ValueName": "ConfigureWindowsSpotlight",
  "Elements": [
    { "Type": "Boolean", "ValueName": "IncludeEnterpriseSpotlight", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "2" }
  ]
},
```

# Black PS Background

Since `powershell.exe` has default color of white (foreground) and blue (background), some may want to change it.

`ScreenColors` value, located in `HKCU\Console\%SystemRoot%_System32_WindowsPowerShell_v1.0_powershell.exe`  
`0-3` bit = `Foreground color`  
`4-7` bit = `Background color`

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

Calculate it on your own, by using [bitmask-calc](https://github.com/5Noxi/bitmask-calc) - e.g. set bit `1-3` and `7`, to get `Yellow` (foreground) and `DarkGray` (background).

If you've set a custom foreground/background color, they won't override the colors changed within the code, e.g.:
```powershell
Write-Host "Noverse"
```
-> `Noverse` will have use foreground & background color of `ScreenColors`
```powershell
Write-Host "Noverse" -ForegroundColor Blue
```
-> `Noverse` will be blue, `ScreenColors` gets skipped.
```powershell
[console]::BackgroundColor = 'Black'
```
-> If it doesn't get changed within the code, it'll use the background color set by `ScreenColor`.

`System-Color.bat` uses `Black` (background) and `Gray` (foreground), since it is personal preference change it to whatever you want using the information above.

Add the `-NoLogo` parameter to the powershell shortcut in the start menu with the command below. It hides the startup banner:
```
Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Install the latest PowerShell for new features and improvements! https://aka.ms/PSWindows

PS C:\Users\Nohuxi>
```
```powershell
for %%L in ("%APPDATA%\Microsoft\Windows\Start Menu\Programs\Windows PowerShell\*.lnk") do powershell -c "$s=New-Object -ComObject WScript.Shell; $lnk=$s.CreateShortcut('%%~fL'); $lnk.TargetPath='%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe'; $lnk.Arguments='-NoLogo'; $lnk.Save()"
```

# Disable Theme Mouse Changes

Prevent Themes from changing the mouse cursor.

`Disable Theme Desktop Icons Changes` prevent themes from changing desktop icons.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/thememouse.png?raw=true)

# Hide Disabled/Disconnected Devices

Hides disabled/disconnected devices in the `mmsys.cpl` window.

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/hidedevices.png?raw=true)

```c
// Show disabled/disconnected devices
rundll32.exe	RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\DeviceCpl\ShowHiddenDevices	Type: REG_DWORD, Length: 4, Data: 1
rundll32.exe	RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\DeviceCpl\ShowDisconnectedDevices	Type: REG_DWORD, Length: 4, Data: 1

// Hide disabled/diconnected devices
rundll32.exe	RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\DeviceCpl\ShowHiddenDevices	Type: REG_DWORD, Length: 4, Data: 0
rundll32.exe	RegSetValue	HKCU\Software\Microsoft\Multimedia\Audio\DeviceCpl\ShowDisconnectedDevices	Type: REG_DWORD, Length: 4, Data: 0
```

# Global Account Picture

"This policy setting allows an administrator to standardize the account pictures for all users on a system to the default account picture."

Edit account picture/desktop wallpaper via (edit `C:\Path`/`Wallpaper.png`):
```bat
:: Account Picture
del "C:\ProgramData\Microsoft\User Account Pictures\user.png" /f /q
del "C:\ProgramData\Microsoft\User Account Pictures\user.bmp" /f /q
copy "C:\Path\user.png" "C:\ProgramData\Microsoft\User Account Pictures\"
copy "C:\Path\user.bmp" "C:\ProgramData\Microsoft\User Account Pictures\"

:: Desktop Wallpaper
reg add "HKCU\Control Panel\Desktop" /v Wallpaper /t REG_SZ /d ""C:\Path\Wallpaper.png"" /f
```

```json
{
  "File": "Cpls.admx",
  "CategoryName": "Users",
  "PolicyName": "UseDefaultTile",
  "NameSpace": "Microsoft.Policies.ControlPanel2",
  "Supported": "WindowsVista",
  "DisplayName": "Apply the default account picture to all users",
  "ExplainText": "This policy setting allows an administrator to standardize the account pictures for all users on a system to the default account picture. One application for this policy setting is to standardize the account pictures to a company logo. Note: The default account picture is stored at %PROGRAMDATA%\\Microsoft\\User Account Pictures\\user.jpg. The default guest picture is stored at %PROGRAMDATA%\\Microsoft\\User Account Pictures\\guest.jpg. If the default pictures do not exist, an empty frame is displayed. If you enable this policy setting, the default user account picture will display for all users on the system with no customization allowed. If you disable or do not configure this policy setting, users will be able to customize their account pictures.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "ValueName": "UseDefaultTile",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Force Classic Control Panel

"This policy setting controls the default Control Panel view, whether by category or icons. If this policy setting is enabled, the Control Panel opens to the icon view. If this policy setting is disabled, the Control Panel opens to the category view."

Icon view:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/panel0.png?raw=true)

Category view:

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/panel1.png?raw=true)

```json
{
  "File": "ControlPanel.admx",
  "CategoryName": "ControlPanel",
  "PolicyName": "ForceClassicControlPanel",
  "NameSpace": "Microsoft.Policies.ControlPanel",
  "Supported": "WindowsXP",
  "DisplayName": "Always open All Control Panel Items when opening Control Panel",
  "ExplainText": "This policy setting controls the default Control Panel view, whether by category or icons. If this policy setting is enabled, the Control Panel opens to the icon view. If this policy setting is disabled, the Control Panel opens to the category view. If this policy setting is not configured, the Control Panel opens to the view used in the last Control Panel session. Note: Icon size is dependent upon what the user has set it to in the previous session.",
  "KeyPath": [
    "HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"
  ],
  "ValueName": "ForceClassicControlPanel",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Decrease Mouse Hover Time

`MouseHoverTime` controls how long the mouse must stay still over something before Windows treats it as a hover.

`MenuShowDelay` controls how long Windows waits before opening a submenu when you hover over a menu entry.

```c
v2 = a2;
if ( SystemParametersInfoW(0x6Au, 0, &g_lMenuPopupTimeout, 0) )
  goto LABEL_5;
v4 = g_lMenuPopupTimeout;
if ( g_lMenuPopupTimeout != -1 )
  goto LABEL_6;
g_lMenuPopupTimeout = 4 * GetDoubleClickTime() / 5; // fallback
if ( (int)SHRegGetStringEx(HKEY_CURRENT_USER, L"Control Panel\\Desktop", L"MenuShowDelay", 2, pszSrc, 6u) < 0 )
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

Type: `String`  
Min: `0`  
Max: `65534`? - It uses `StrToIntW` to read the value  
Fallback: Depends on `GetDoubleClickTime()` (`Control Panel > Mouse > Double-click speed`), which would change the `DoubleClickSpeed` value (has a default of `500`, which is why the default of `MenuShowDelay` is `400`)  
Default: `400`

```c
if ( (_DWORD)v2 == 32771 )
  goto LABEL_19;
if ( (_DWORD)v2 != 32776 )
{
  if ( (_DWORD)v2 != 32777 )
  {
    if ( (_DWORD)v2 == 32778 )
    {
      v4 = 60000;
    }
    else if ( (_DWORD)v2 == 32779 )
    {
      v4 = 2 * GetDoubleClickTime();
    }
    return SetTimer(this[2], v2, v4, 0LL);
  }
LABEL_19:
  v4 *= 2;
  if ( v4 < 2000 )
    v4 = 2000;
  return SetTimer(this[2], v2, v4, 0LL);
}
if ( ((_BYTE)this[15] & 1) == 0 )
  return 1LL;
v5 = *((_QWORD *)this[5] + 34);
if ( !v5 || (*(_BYTE *)(v5 + 72) & 1) != 0 || ((_BYTE)this[15] & 0x20) != 0 )
  return 1LL;
v4 *= 5;
if ( v4 < 2000 )
  v4 = 2000;
return SetTimer(this[2], v2, v4, 0LL);
```

Timers 32771/32777/32776 clamp the delay to >=2 seconds, so setting `MenuShowDelay` to `0` won't impact everything. Timers 32778/32779 do'nt use the registry at all.

> https://learn.microsoft.com/en-us/windows/win32/api/shlwapi/nf-shlwapi-strtointw  
> https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdoubleclicktime

# OEM Information

Set your own support information in `System > About` (or `Control Panel > System and Security > System`. All values are saved in:
```
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\OEMInformation
```
You used to change the logo with:
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\OEMInformation" /v Logo /t REG_SZ /d "path\OEM.bmp" /f
```
But it seems deprecated (doesn't work for me). Limitation were `120x120` pixels, `.bmp` file & `32-bit` color depth.

Edit registered owner/orga (visible in `winver`) with:
```powershell
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion" /v RegisteredOwner /t REG_SZ /d Nohuxi /f
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion" /v RegisteredOrganization /t REG_SZ /d Noverse /f
```
Edit miscellaneous things in `winver.exe` using (`basebrd.dll`/`basebrd.dll.mui`):
> https://www.angusj.com/resourcehacker/

---

Example:
```powershell
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\OEMInformation" /v "Manufacturer" /t REG_SZ /d "Noverse" /f
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\OEMInformation" /v "Model" /t REG_SZ /d "Windows 11" /f
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\OEMInformation" /v "SupportHours" /t REG_SZ /d "24 Hours" /f
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\OEMInformation" /v "SupportPhone" /t REG_SZ /d "noverse@gmail.com" /f
reg add "HKLM\Software\Microsoft\Windows\CurrentVersion\OEMInformation" /v "SupportURL" /t REG_SZ /d "https://discord.gg/noverse" /f
```

![](https://github.com/5Noxi/win-config/blob/main/visibility/images/oem.png?raw=true)

# Settings Page Visibility 

It controls which pages in the windows settings app are visible (blocked pages are removed from view and direct access redirects to the main settings page).

```
This policy allows an administrator to block a given set of pages from the System Settings app. Blocked pages will not be visible in the app, and if all pages in a category are blocked the category will be hidden as well. Direct navigation to a blocked page via URI, context menu in Explorer or other means will result in the front page of Settings being shown instead.
```
Path (`String Value`):
```
HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer : SettingsPageVisibility
```
`showonly:` followed by a semicolon separated list of page identifiers to allow
`hide:` followed by a list of pages to block

Page identifiers are the part after `ms-settings:` in a settings URI.

Example:
`showonly:bluetooth` only shows the `Bluetooth` page
`hide:bluetooth;windowsdefender` hides the `Bluetooth` & `Windows Security` pages

All categories of `ms-settings` URIs:
> https://learn.microsoft.com/en-us/windows/apps/develop/launch/launch-settings-app#ms-settings-uri-scheme-reference

Example value:
```bat
hide:sync;signinoptions-launchfaceenrollment;signinoptions-launchfingerprintenrollment;maps;maps-downloadmaps;mobile-devices;family-group;deviceusage;findmydevice
```
It depends on the user what he wants to see and what not, so I won't add a switch for it.
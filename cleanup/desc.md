# WinSxS Folder

Get the current size of the WinSxS folder, by pasting the following command into `cmd`:
```cmd
Dism.exe /Online /Cleanup-Image /AnalyzeComponentStore
```
The output could look like:
```
C:\Users\Nohuxi>Dism.exe /Online /Cleanup-Image /AnalyzeComponentStore

Component Store (WinSxS) information:

Windows Explorer Reported Size of Component Store : 5.00 GB

Actual Size of Component Store : 4.94 GB

    Shared with Windows : 2.82 GB
    Backups and Disabled Features : 2.12 GB
    Cache and Temporary Data :  0 bytes

Date of Last Cleanup : 2025-03-30 11:05:43

Number of Reclaimable Packages : 0
Component Store Cleanup Recommended : No
```
`Number of Reclaimable Packages : 0` -> This is the number of superseded packages on the system that component cleanup can remove.

> https://learn.microsoft.com/en-us/windows-hardware/manufacture/desktop/determine-the-actual-size-of-the-winsxs-folder?view=windows-11&source=recommendations#analyze-the-component-store

Clean your folder with:
```cmd
Dism.exe /online /Cleanup-Image /StartComponentCleanup
```
or
```
Dism.exe /online /Cleanup-Image /StartComponentCleanup /ResetBase
```
, if you want to remove all superseded versions of every component in the component store. (no need, if there aren't any)

> https://learn.microsoft.com/en-us/windows-hardware/manufacture/desktop/manage-the-component-store?view=windows-11  
> https://learn.microsoft.com/en-us/windows-hardware/manufacture/desktop/clean-up-the-winsxs-folder?view=windows-11

Permanently remove outdated update files from `C:\Windows\WinSxS` to free space. Once applied, previous updates cannot be uninstalled:
```json
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\SideBySide\\Configuration": {
  "DisableResetbase": { "Type": "REG_DWORD", "Data": 0 }
}
```
The value doesn't exist on more recent versions.

# Windows.old

Removes old/previous windows installation files from `Windows.old`.

```
Ten days after you upgrade to Windows, your previous version of Windows will be automatically deleted from your PC. However, if you need to free up drive space, and you're confident that your files and settings are where you want them to be in Windows, you can safely delete it yourself.

If it's been fewer than 10 days since you upgraded to Windows, your previous version of Windows will be listed as a system file you can delete. You can delete it, but keep in mind that you'll be deleting your Windows.old folder, which contains files that give you the option to go back to your previous version of Windows. If you delete your previous version of Windows, this can't be undone (you won't be able to go back to your previous version of Windows).
```
> https://support.microsoft.com/en-us/windows/delete-your-previous-version-of-windows-f8b26680-e083-c710-b757-7567d69dbb74


# SRUM Data

Deletes the SRUM database file, which tracks app, service, and network usage.

Location:
```bat
%windir%\System32\sru
```
Read the SRUM data:
> https://github.com/MarkBaggett/srum-dump

# DirectX Shader Cache

Clears the DirectX caches and any vendor caches (NVIDIA `DXCache`/`GLCache`/`NV_Cache`, AMD `DXCache`, Intel `DXCache`). Clearing the cache forces shaders to be recompiled the next time an application starts. Expect a short period of shader compilation stutter immediately after cleaning.

Remember to temporarily set `Shader Cache Size` to `Disabled`, use the option, then return it to `Unlimited` so the driver use the files.

![](https://github.com/5Noxi/win-config/blob/main/nvidia/images/shadercache.png?raw=true)

# Recycle Bin

Empties the recycle bin for every mounted drive. Windows stores deleted files per volume in `$Recycle.Bin`, so if you have multiple volumes this can recover more space than the Explorer UI shows.

```powershell
C:\$Recycle.Bin\S-<user-id>
```

# Shadow Copies

Removes all copies (volume backups). See your current shadows with:
```cmd
vssadmin list shadows /for=<ForVolumeSpec> /shadow=<ShadowID>
```

`<ForVolumeSpec>` -> Volume
`<ShadowID>` -> Shadow copy specified by ShadowID

# Background History

The personalization window keeps the last five wallpaper paths in `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Wallpapers` (`BackgroundHistoryPath0-4`) and cached copies under `%AppData%\Microsoft\Windows\Themes\CachedFiles`.

# Font Cache

The font cache is a file or set of files to manage and display the installed fonts so they load faster. Sometimes the font cache may become corrupted and cause fonts to not rendering properly, or displaying invalid characters. If not having such issues there's no point in clearing it.

```powershell
"%WinDir%\\ServiceProfiles\\LocalService\\AppData\\Local\\FontCache\\*FontCache*", "%WinDir%\\System32\\FNTCACHE.DAT"
```

# Temporary Internet Files

Legacy WinINet consumers (Explorer, old Control Panel surfaces, webviews inside installers, etc.) still use `%LOCALAPPDATA%\Microsoft\Windows\INetCache`, `%LOCALAPPDATA%\Microsoft\Windows\INetCookies`, `%LOCALAPPDATA%\Microsoft\Windows\WebCache`, `%LOCALAPPDATA%\Microsoft\Windows\History`. Expect the first launch of an affected app to take longer while it rebuilds HTTP caches.

# Delivery Optimization Files

Delivery Optimization (DoSvc) stores update files under `C:\Windows\SoftwareDistribution\DeliveryOptimization` and uses `C:\ProgramData\Microsoft\Network\Downloader` for the BITS session data. The option stops DoSvc to delete the files, but won't start it as it's not recommended to have it enabled anyway.

# Temporary Files

Per user temporary files are saved in `%TEMP%`, global files under `%WINDIR%\Temp`. Some installers never delete leftovers, so those can pollute the folder. Anything that is still used will be skipped.

# Clipboard History

Currently clears the in memory buffer via `echo. | clip`. [`clip`](https://github.com/5noxi/windowsserverdocs/blob/main/WindowsServerDocs/administration/windows-commands/clip.md) saves thatever it gets into the clipboard, and [`echo.`](https://github.com/5noxi/windowsserverdocs/blob/main/WindowsServerDocs/administration/windows-commands/echo.md#examples) = blank line.

See your current clipboard content via:
```powershell
Get-Clipboard
```

# DNS Cache

`Get-DnsClientCache` shows the resolver cache that stores recent lookups. Flushing it via `ipconfig /flushdns` can fix stale entries after moving domains or switching VPN profiles (or if editing the hosts file).

# WER Files

Windows Error Reporting (WER) queues crash dumps and report metadata under `%PROGRAMDATA%\Microsoft\Windows\WER` (system) and `%LOCALAPPDATA%\Microsoft\Windows\WER` (per user). Clearing the queue removes pending uploads and archived `.wer` files.

# Event Logs

Only do this if you want to export the data elsewhere or purposely delete logs (security logs can't be recovered afterward).

Display all logs via:
```powershell
wevtutil el
```

> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/wevtutil

# Windows Update Cache

Troubleshooting update loops often requires resetting `%WINDIR%\SoftwareDistribution` and `%WINDIR%\System32\catroot2`. This forces Windows Update to redownload the catalog metadata.

# Thumbnail Cache

Placeholder.

# Prefetch Files

Placeholder.

# BSoD Memory Dump Files

Placeholder.

# Product Key

"Some servicing operations require the product key to be available in the registry during Out of Box Experience (OOBE) operations. The /cpky option removes the product key from the registry to prevent this key from being stolen by malicious code. For retail installations that deploy keys, the best practice is to run this option. This option isn't required for MAK and KMS host keys, because this is the default behavior for those keys. This option is required only for other types of keys whose default behavior isn't to clear the key from the registry."

> https://learn.microsoft.com/en-us/windows-server/get-started/activation-slmgr-vbs-options#advanced-options

# Downloaded Program Files

Placeholder.

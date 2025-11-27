# Clean WinSxS Folder

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

# Remove Windows.old

Removes old/previous windows installation files from `Windows.old`.

```
Ten days after you upgrade to Windows, your previous version of Windows will be automatically deleted from your PC. However, if you need to free up drive space, and you're confident that your files and settings are where you want them to be in Windows, you can safely delete it yourself.

If it's been fewer than 10 days since you upgraded to Windows, your previous version of Windows will be listed as a system file you can delete. You can delete it, but keep in mind that you'll be deleting your Windows.old folder, which contains files that give you the option to go back to your previous version of Windows. If you delete your previous version of Windows, this can't be undone (you won't be able to go back to your previous version of Windows).
```
> https://support.microsoft.com/en-us/windows/delete-your-previous-version-of-windows-f8b26680-e083-c710-b757-7567d69dbb74


# Clear SRUM Data

Deletes the SRUM database file, which tracks app, service, and network usage.

Location:
```bat
%windir%\System32\sru
```
Read the SRUM data:
> https://github.com/MarkBaggett/srum-dump

# Clear NVIDIA Shader Cache

Set the `Shader Cache Size` to `Disabled` or you'll get the "The action can't be completet [...] - Folder In Use" window (restart your PC). Use the option (`Clear`), then set the `Shader Cache Size` back to `Unlimited`.

> There should be a reason for clearing the shader cache. If not, you should't clear it. After clearing, the cache must be rebuilt, which means that the game will stutter until then.

![](https://github.com/5Noxi/win-config/blob/main/nvidia/images/shadercache.png?raw=true)

# Clear Recycle Bin

# Remove Shadow Copies

Removes all copies (volume backups), see your current shadows with:
```cmd
vssadmin list shadows /for=<ForVolumeSpec> /shadow=<ShadowID>
```
`<ForVolumeSpec>` -> Volume
`<ShadowID>` -> Shadow copy specified by ShadowID

Remove it with:
```cmd
vssadmin delete shadows /all
```

# Clear Background History

# Clear Font Boot Cache

The font cache is a file or set of files used by Windows to manage and display the fonts installed on your PC so they load faster. Sometimes the font cache may become corrupted and cause fonts to be garbled, not rendering properly, or displaying invalid characters. To fix the font cache corruption, you will need to delete the old font cache and restart the computer afterwards to rebuild a new font cache.

Paths the font cache is located at:
```powershell
"%WinDir%\\ServiceProfiles\\LocalService\\AppData\\Local\\FontCache\\*FontCache*", "%WinDir%\\System32\\FNTCACHE.DAT"
```
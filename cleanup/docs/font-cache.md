# Font Cache

The font cache is a file or set of files to manage and display the installed fonts so they load faster. Sometimes the font cache may become corrupted and cause fonts to not rendering properly, or displaying invalid characters. If not having such issues there's no point in clearing it.

```powershell
"%WINDIR%\\ServiceProfiles\\LocalService\\AppData\\Local\\FontCache\\*FontCache*", "%WINDIR%\\System32\\FNTCACHE.DAT"
```

The cleanup stops the `FontCache` service, deletes cache files, then Windows rebuilds the cache on next launch.


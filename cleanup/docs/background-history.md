# Background History

The personalization window keeps the last five wallpaper paths in `HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Wallpapers` and cached copies under `%AppData%\Microsoft\Windows\Themes\CachedFiles`.

```json
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Wallpapers": {
  "BackgroundHistoryPath0": { "Action": "deletevalue" },
  "BackgroundHistoryPath1": { "Action": "deletevalue" },
  "BackgroundHistoryPath2": { "Action": "deletevalue" },
  "BackgroundHistoryPath3": { "Action": "deletevalue" },
  "BackgroundHistoryPath4": { "Action": "deletevalue" }
}
```


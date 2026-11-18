# Disable File History

> "*File History automatically backs up versions of files in your user folders (Documents, Music, Pictures, Videos, Desktop) and offline OneDrive. It tracks changes via the NTFS change journal (fast, low overhead) and saves only changed files. You must choose a backup target (external drive or network share). If that target is unavailable, it caches copies locally and syncs them when the target returns. You can browse and restore any version or recover lost/deleted files.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off File History](https://noverse.dev/policies?p=FileHistory*DisableFileHistory) | `HKLM\Software\Policies\Microsoft\Windows\FileHistory` | `Disabled` |


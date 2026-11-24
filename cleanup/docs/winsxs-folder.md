# WinSxS Folder

Get the [current size](https://learn.microsoft.com/en-us/windows-hardware/manufacture/desktop/determine-the-actual-size-of-the-winsxs-folder?view=windows-11&source=recommendations#analyze-the-component-store) of the WinSxS folder:

```cmd
Dism.exe /Online /Cleanup-Image /AnalyzeComponentStore
```

The output could look like:

```
C:\Users\Nohuto>Dism.exe /Online /Cleanup-Image /AnalyzeComponentStore

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

Clean your folder with:

```cmd
Dism.exe /online /Cleanup-Image /StartComponentCleanup
Dism.exe /online /Cleanup-Image /StartComponentCleanup /ResetBase
```
If you want to remove all superseded versions of every component in the component store (no need, if there aren't any).

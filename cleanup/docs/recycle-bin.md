# Recycle Bin

Empties the recycle bin for every mounted drive. Windows stores deleted files per volume in `$Recycle.Bin`, so if you have multiple volumes this can recover more space than the Explorer UI shows.

```powershell
C:\$Recycle.Bin\S-<user-id>
```
Command used:
```powershell
Clear-RecycleBin -Force
```


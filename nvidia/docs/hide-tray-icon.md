# Hide Tray Icon

```c
"HKCU\\Software\\NVIDIA Corporation\\NvTray";
    "StartOnLogin" = 1; // REG_DWORD, 0 = control panel tray icon doesnt start

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NVTweak";
    "HideXGpuTrayIcon" = 0; // REG_DWORD, nonzero = GPU activity icon doesnt start

"HKCU\\Software\\NVIDIA Corporation\\Global\\CoProcManager";
    "ShowTrayIcon" = 0; // REG_DWORD, 1 = GPU activity icon shown, ignored while an external GPU is attached
```

# Hide Tray Icon

```
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Global\NVTweak : HideXGpuTrayIcon
\Registry\Machine\SOFTWARE\NVIDIA Corporation\Global\CoProcManager : ShowTrayIcon
```

Other miscellaneous values I found:

```json
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NVTweak": {
  "HideManufacturerFromMonitorName": { "Type": "REG_DWORD", "Data": 1 }
}
```

Hides the icon from the context menu (2nd one is probably related to optimus, first controls NVCPL):

```json
"HKCU\\Software\\NVIDIA Corporation\\Global\\NvCplApi\\Policies": {
  "ContextUIPolicy": { "Type": "REG_DWORD", "Data": 0 }
},
"HKCU\\SOFTWARE\\NVIDIA Corporation\\Global\\RunOpenGLOn": {
  "ShowContextMenu": { "Type": "REG_DWORD", "Data": 0 }
},
"HKCU\\SOFTWARE\\NVIDIA Corporation\\Global\\CoProcManager": {
  "ShowContextMenu": { "Type": "REG_DWORD", "Data": 0 }
}
```

Only the first value gets used.

- [nvidia/assets/pseudocode | HideManufacturer.c](https://github.com/nohuto/win-config/blob/main/nvidia/assets/pseudocode/trayicon-HideManufacturer.c)
- [nvidia/assets/reference | notes.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/reference/trayicon-notes.cpp)
- [nvidia/assets/pseudocode | nvcpl.c](https://github.com/nohuto/win-config/blob/main/nvidia/assets/pseudocode/trayicon-nvcpl.c)


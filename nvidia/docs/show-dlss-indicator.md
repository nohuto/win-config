# Show DLSS Indicator

Shows/hides the DLSS on screen indicator (version  settings) in games.

```c
"HKLM\\SOFTWARE\\NVIDIA Corporation\\Global\\NGXCore";
    "ShowDlssIndicator" = 0; // REG_DWORD, 1024 = indicator in every DLSS build
```

> "*For develop and debug builds, registry key that enables DLSS on-screen indicator is: HKEY_LOCAL_MACHINE\SOFTWARE\NVIDIA Corporation\Global\NGXCore\ShowDlssIndicator It must be DWORD. Any positive value enables DLSS indicator for Develop and Debug builds of DLSS. On the contrary, Release build of DLSS requires value 1024 to enable DLSS indicator.*"
>
> — NVIDIA, [DLSS Programming Guide](https://github.com/NVIDIA/DLSS/blob/main/doc/DLSS_Programming_Guide_Release.pdf)

- [nvidia/assets/reference | dlss-NGXCubinGeneric.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/reference/dlss-NGXCubinGeneric.cpp)


# Disable DLSS Indicator

Enabled = `1024`  
Disabled = `0`

### From NVIDIA Documentations

`turn-dlss-indicator-off`
```powershell
[HKEY_LOCAL_MACHINE\SOFTWARE\NVIDIA Corporation\Global\NGXCore]
"ShowDlssIndicator"=dword:00000000
```
`turn-dlss-indicator-on-center`
```powershell
[HKEY_LOCAL_MACHINE\SOFTWARE\NVIDIA Corporation\Global\NGXCore]
"ShowDlssIndicator"=dword:00000001
```
`turn-dlss-indicator-on-top-left`
```powershell
[HKEY_LOCAL_MACHINE\SOFTWARE\NVIDIA Corporation\Global\NGXCore]
"ShowDlssIndicator"=dword:00000002
```

- [nvidia/assets/reference | dlss-NGXCubinGeneric.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/reference/dlss-NGXCubinGeneric.cpp)


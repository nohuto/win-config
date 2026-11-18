# Enable FSO

Will be updated within the next weeks (date of commit 20.05.2026)

### ResourcePolicyServer

Values found that are `GameDVR` related in `ResourcePolicyServer.dll`:

```c
GameDVR_DXGIHonorFSEWindowsCompatible
GameDVR_EFSEFeatureFlags
GameDVR_FSEBehavior
GameDVR_FSEBehaviorMode
GameDVR_HonorUserFSEBehaviorMode
```

`GameDVR_DSEBehavior` does not exist on the current system.

### Compatibility Flags

The Compatibility UI option `Disable fullscreen optimizations` writes an application compatibility layer value. This can exist per-user or machine-wide.

```c
// User
HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\<exe path> = "~ DISABLEDXMAXIMIZEDWINDOWEDMODE"

// Machine
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\<exe path> = "~ DISABLEDXMAXIMIZEDWINDOWEDMODE"
```


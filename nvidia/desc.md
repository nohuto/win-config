# Bitmask Calculator

This was meant to be a normal bitmask calculator, but I decided to add features to it that made it possible to directly configure and apply NVIDIA values. You may have seen people sharing NVIDIA values with uncommon looking data, e.g.:

```bat
reg add "HKLM\SYSTEM\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0001" /v RMElcg /t REG_DWORD /d 1431655765 /f
```

The tool loads all value names including their bit definitions, making it easy for you to understand what the data of `1431655765` truely does. After selecting an option, it updates the `dec`, `hex`, `bin` data and displays the bit positions. If you want to use the value, you can add it with the `Reg Add` button, which searches for the correct key.

It adds all values to the [`Display`](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors#device-categories-and-class-values) class key. There are values with the same names in the [`nvlddmkm\*`](https://github.com/nohuto/regkit/blob/main/assets/records/nvlddmkm.txt) key, but those won't get added via the tool. I may add a second section for `nvlddmkm` key values.

```
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : RmProfilingAdminOnly
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Global\NVTweak : RmProfilingAdminOnly
```

The calculator uses an converted `.json` version of the official NVIDIA resource manager definitions. I've built the converter myself, and it should be `100%` accurate.

- [Preview](https://github.com/user-attachments/assets/91b241ef-5e8e-4859-8957-d3b54dc52b0e)

The tool currently has a selection of `967` values ([`nvvalues.txt`](https://github.com/nohuto/bitmask-calc/blob/main/nvvalues.txt)). It works with my own `.json` converted bitfield definitions. This doesn't mean that all of them are configurable or used by your system. See [list of values](https://github.com/nohuto/regkit/blob/main/assets/records/NVIDIA-DispGUID.txt), which got read on my system while boot.

## GUI Buttons

| Button | Description |
| --- | --- |
| `Reg Add` | Adds the currently selected value to the key |
| `Reg Del` | Removes the currently selected value from the key |
| `Disable All` | Enables all `DISABLE*` / `OFF` / `FALSE` bits (fallback to `DEFAULT`) |
| `Enable All` | Enables all `ENABLE*` / `ON` / `TRUE` bits (fallback to `DEFAULT`) |
| `Open Key` | Opens the registry key within the display class GUID [`4d36e968-e325-11ce-bfc1-08002be10318`](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors#device-categories-and-class-values)<br> which includes a value named `DriverDesc` with data of `*NVIDIA*` |
| `Auto Config` | Sets preconfigured **experimental** values, these aren't recommendations, only possible presumptions (grayed out, if there's no `Configured` value in the `.json` config) |
| `Clear` | Reverts bit states to `*DEFAULT*` (first fallback to `EMPTY (0)`, second to any `0` value) |

## Bitmask Calculation

Get the lower bit range (`25:24` -> `24`), shift the dec or hex x times to the left (`-shl`). Combine all results with `-bor`, and done.

Example using `RMGC6Parameters` (disabling all):

```json
{
  "Name": "RMGC6Parameters",
  "Comment": [
    "Type DWORD",
    "This regkey controls individual latency optimization features for GC6."
  ],
  "Elements": [
    {
      "Field": "SLEEP_AWARE_CALLBACK",
      "Bits": "1:0",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLED", "Value": "1" },
        { "Name": "ENABLED", "Value": "3" }
      ]
    },
    {
      "Field": "DEFERRED_PMU_CALLBACK",
      "Bits": "3:2",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLED", "Value": "1" },
        { "Name": "ENABLED", "Value": "3" }
      ]
    },
    {
      "Field": "PMU_HANDLE_MODESET",
      "Bits": "5:4",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLED", "Value": "1" },
        { "Name": "ENABLED", "Value": "3" }
      ]
    },
    {
      "Field": "BSOD_MODESET",
      "Bits": "7:6",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLED", "Value": "1" },
        { "Name": "ENABLED", "Value": "3" }
      ]
    }
  ]
},
```

1. `-shl` using the lower bit range value

```powershell
0x00000001 -shl 0
0x00000001 -shl 2
0x00000001 -shl 4
0x00000001 -shl 6
```

would result in `1`, `4`, `16`, `64`.

2. Combine them with `-bor`

```powershell
1 -bor 4 -bor 16 -bor 64
```

Output of `85`, which is the result.

Different common scenario would be `DisableDynamicPstate`:

```json
{
  "Name": "DisableDynamicPstate",
  "Comment": [
    "Type Dword",
    "1 = Disable dynamic P-State/adaptive clocking",
    "0 = Do not disable dynamic P-State/adaptive clocking (default)"
  ],
  "Elements": [
    {
      "Name": "DISABLE",
      "Value": "0"
    },
    {
      "Name": "ENABLE",
      "Value": "1"
    }
  ]
},
```

The comment shows `1` = `Enabled`, `0` = `Disabled`, means bit 0 gets switched here.

Test yourself with the following example:

```json
{
  "Name": "RMClkSlowDown",
  "Comment": [
    "Type DWORD",
    "Each clock down feature uses 2 bits. This is used as a stand alone regKey",
    "For each 2 bits, the following convention holds",
    "0 : Keep the vbios default",
    "1 : Disable feature",
    "3 : Enable feature",
    "Note:  In general, for most of these features, only the disable function",
    "should be used.  The enable function should only be used on special",
    "occasions, such as during bringup when the corresponding property is",
    "disabled by default, and the vbios is known to have the feature enabled and",
    "slowdown factors and various other required settings set correctly.",
    "Thermal Slowdown feature enablement/Disablement has been deprecated since",
    "a) MODs does not use this regkey anymore",
    "NV2080_CTRL_THERMAL_SYSTEM_GET_SLOWDOWN_STATE_OPCODE is used by MODS currently",
    "b) We cannot enable/Disable OVERT event via regkey from gm20x onwards",
    "c) Pascal and onwards, we donot support ALERT_X since we have introduced generic",
    "Therm events"
  ],
  "Elements": [
    {
      "Field": "THERMAL_RESERVED",
      "Bits": "17:0",
      "Options": []
    },
    {
      "Field": "DEPRECATED",
      "Bits": "19:18",
      "Options": []
    },
    {
      "Field": "NV",
      "Bits": "23:22",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLE", "Value": "1" },
        { "Name": "ENABLE", "Value": "3" }
      ]
    },
    {
      "Field": "HOST",
      "Bits": "25:24",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLE", "Value": "1" },
        { "Name": "ENABLE", "Value": "3" }
      ],
      "Comment": "deprecated"
    },
    {
      "Field": "IDLE_PSTATE",
      "Bits": "27:26",
      "Options": [
        { "Name": "DEFAULT", "Value": "0" },
        { "Name": "DISABLE", "Value": "1" },
        { "Name": "ENABLE", "Value": "3" }
      ]
    }
  ]
},
```

Try to disable all of them.

Solution:
- Dec: `88080384`  
- Hex: `0x05400000`  
- Bin: `00000101010000000000000000000000`  

```powershell
0x00000001 -shl 22
0x00000001 -shl 24
0x00000001 -shl 26
```
```powershell
4194304 -bor 16777216 -bor 67108864
-> 88080384
```

More info about `-shl` & `-bor` can be found in [bitwise-operators.md](https://github.com/nohuto/bitmask-calc/blob/main/bitwise-operators/bitwise-operators.md).

# NVCPL Settings

`Minimal` = Uses the configurations while turning off features like G-SYNC, Antialiasing, Sharpening, Ambient Occlusion, NIS, Ansel etc.  
`Compatible` = Uses the same configurations but keeps those features enabled/app-controlled

The sections below include details of how the nvcpl sets the changes and more, a lot of it is for informational purposes only.

## 3D Settings

### Adjust image settings with preview

```cpp
void    CAppSettingsBasic::mapApiRes()
{
    //Mapping API values to the resources string
    CplUiMap::value_type  eot( (UINT32)-1 , CplUi(0) ); // EOT, must be last in the array

    CplUiMap::value_type api2resImage[] = 
    {
        //============= Image Quality values->strings resource IDs =====================================================================
        CplUiMap::value_type(NVCPLAPI_VALUE_D3D_GESTALT_PERF     ,    CplUi(IDS_3DPREVIEW_EMPHASIZING_PERFORMANCE)),
        CplUiMap::value_type(NVCPLAPI_VALUE_D3D_GESTALT_BALANCED ,    CplUi(IDS_3DPREVIEW_EMPHASIZING_BALANCED)),
        CplUiMap::value_type(NVCPLAPI_VALUE_D3D_GESTALT_QUAL     ,    CplUi(IDS_3DPREVIEW_EMPHASIZING_QUALITY)),  
        //============= Image Quality values->strings resource IDs =====================================================================,
        eot
    };

    m_sliderGestalt.create(api2resImage,NVCPLAPI_SETTING_D3D_BASIC_GESTALT);
}
```

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl1.png?raw=true)

### Manage 3D settings

Note that many settings like '*Triple buffering*', '*OpenGL Rendering GPU*', '*Threaded optimization*', '*Vulkan/OpenGL present method*' etc. are used OpenGL/old DX games only, and e.g. '*Virtual Reality pre-rendered frames*' for VR applications.

I've created a folder [nv_params](https://github.com/nohuto/win-config/tree/main/nvidia/assets/nv_params) that includes NVIDIA driver parameter references for D3D, OpenGL, display, DRS, GFE, nView, ShadowPlay, stereo components. See [d3d](https://github.com/nohuto/win-config/tree/main/nvidia/assets/nv_params/d3d), [d3dogl](https://github.com/nohuto/win-config/tree/main/nvidia/assets/nv_params/d3dogl), [opengl](https://github.com/nohuto/win-config/tree/main/nvidia/assets/nv_params/opengl), [other](https://github.com/nohuto/win-config/tree/main/nvidia/assets/nv_params/other) for source files and more details.

- [`parameters.txt`](https://github.com/nohuto/win-config/blob/main/nvidia/assets/nv_params/parameters.txt) - all parameters exposed by [`d3dreg.exe`](https://github.com/nohuto/win-config/blob/main/nvidia/assets/nv_params/d3dreg.exe)
- [`dump_parameters.py`](https://github.com/nohuto/win-config/blob/main/nvidia/assets/nv_params/dump_parameters.py) - recreates the catalog (parameters.txt)

Examples (which proof the mentioned settings above), you might not find the param names by searching for the option names in here, if so look through the `*.def` files in the folders which will show a `*_STRING` for it (remove `_STRING` when searching in parameters):

```powershell
$ rg -i 'Virtual Reality pre-rendered frames' 'C:\Users\nohuto\Desktop\win\win-config\nvidia\assets\nv_params'
C:\Users\nohuto\Desktop\win\win-config\nvidia\assets\nv_params\other\g_drsfeaturesNVAPI.def
46:#define NVDRS_FEATURE_VRPRERENDER_LIMIT_STRING     L"Virtual Reality pre-rendered frames"

C:\Users\nohuto\Desktop\win\win-config\nvidia\assets\nv_params\d3dogl\g_d3doglNVAPIPrivate.def
74:#define VRPRERENDERLIMIT_STRING                    L"Virtual Reality pre-rendered frames"

C:\Users\nohuto\Desktop\win\win-config\nvidia\assets\nv_params\d3dogl\g_d3doglNVAPI.def
56:#define VRPRERENDERLIMIT_STRING                    L"Virtual Reality pre-rendered frames"

C:\Users\nohuto\Desktop\win\win-config\nvidia\assets\nv_params\other\g_drsfeaturesNVAPIPrivate.def
46:#define NVDRS_FEATURE_VRPRERENDER_LIMIT_STRING     L"Virtual Reality pre-rendered frames"
```

```c
------------------------------------------------------------
VRPRERENDERLIMIT
------------------------------------------------------------
This key is of type DWORD
This key is defined all the time - even with release driver
You may assign it to one of the names listed below
but that is not required. You may also enter a number.

MIN             (= 0x00000000)
MAX             (= 0x000000ff)
APP_CONTROLLED  (= 0x00000000)  // The present limit will be controlled by application or driver adjustments.
DEFAULT         (= 0x00000001)

Default values for this setting:
DEFAULT:    DEFAULT

------------------------------------------------------------
OGL_TRIPLE_BUFFER
------------------------------------------------------------
This key is of type DWORD
This key is defined all the time - even with release driver
You may assign it to one of the names listed below
but that is not required. You may also enter a number.

DISABLED  (= 0x00000000)
ENABLED   (= 0x00000001)

Default values for this setting:
DEFAULT:    DISABLED

------------------------------------------------------------
OGL_THREAD_CONTROL
------------------------------------------------------------
This key is of type DWORD
This key is defined all the time - even with release driver
The key is a collection of Bitfields.
You may assign it to some combination of the names listed below
but that is not required. You may also enter a dword value directly.

ENABLE   (= 0x00000001)  // Force Enables threading
DISABLE  (= 0x00000002)  // Force Disable threading

Default values for this setting:
DEFAULT:    0x00000000
```

- [NVIDIA Profile Inspector](https://github.com/Orbmu2k/nvidiaProfileInspector)
- [Noverse-Minimal](https://github.com/nohuto/win-config/blob/main/nvidia/assets/NV-Minimal.nip)
- [Noverse-Compatible](https://github.com/nohuto/win-config/blob/main/nvidia/assets/NV-Compatible.nip)

### Configure Surround, PhysX

Select your GPU if supported (unless the physics workload of your game which uses PhysX is small, auto detect is usually the same as GPU anyway).

Note that NVIDIA PhysX is used by some old titles like *Borderlands 2* (2012)/*Assassin's Creed IV: Black Flag* (2013), modern games usually don't use it.

"NVIDIA PhysX is a powerful physics engine that can utilize GPU acceleration to provide amazing real-time physics effects. PhysX GPU acceleration is available on GeForce 8 series and later GPUs. In order to enable PhysX GPU acceleration, all the GPUs in your system must be PhysX-capable."

I'm unsure how the `physxGpuId` gets set, but it's not the same for everyone .It gets read in the NVAPI key and is a `REG_BINARY` type. If `CPU` is selected, it zeros itself (`00 00 00 00`), if `Auto` (supported)/`GPU` it changes the ID. `nvapi.h` includes some notes.

`Auto-select`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\Global\NVTweak\NvCplPhysxAuto    Type: REG_DWORD, Length: 4, Data: 1
```

`GPU`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\Global\NVTweak\NvCplPhysxAuto    Type: REG_DWORD, Length: 4, Data: 0
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\NVAPI\physxGpuId    Type: REG_BINARY, Length: 4, Data: 00 07 00 00
```

`CPU`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\Global\NVTweak\NvCplPhysxAuto    Type: REG_DWORD, Length: 4, Data: 0
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\NVAPI\physxGpuId    Type: REG_BINARY, Length: 4, Data: 00 00 00 00
```

- [nvidia/assets | physx-nvapi.h](https://github.com/nohuto/win-config/blob/main/nvidia/assets/physx-nvapi.h)

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl2.png?raw=true)

## Display

### Adjust desktop color settings 

Increase `Digital vibrance` up to a level you prefer.

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITOR : SaturationRegistryKey
```

Location (the ID may differ):

```powershell
HKCU\Software\NVIDIA Corporation\Global\NVTweak\Devices\1364265386-0\Color
```

- `3538946`, `3538947`, `3538948` seem to handle the brightness (`100 Dec` = `50%`, `80 Dec` = `0%`, `120 Dec` = `100%`). 
- `3538949`, `3538950`, `3538951` handle the contrast, same value range as the brightness. 
- `3538952`, `3538953`, `3538954` handles the gamma value (`30-180 Dec`, `100 Dec = 1.00`). 
- `3538970` `1` = `Override to reference mode - Off`, `2` = `Override to reference mode - On`

[`NvCplGammaSet`](https://github.com/pbatard/nvBrightness/blob/8f4a183532f1048375608fc70ad03c38652fc140/src/nvDisplay.cpp#L293) is also located in the key, but seems to be at `1` all of the time (`DesktopColor.cpp`). If set to non zero, it uses the saved parameters (values from registry), if its `0` it'll use the default values?

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITOR : SaturationRegistryKey
```

Controls the `Digital vibrance`, decimal value = percentage. `MONITOR` depends on your monitor.

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/saturation.jpg?raw=true)

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITOR : HueRegistryKey
```

`HueRegistryKey` controls the `Hue` options, it is a `REG_BINARY` type ([`displayDB.cpp`](https://github.com/nohuto/win-config/blob/main/nvidia/assets/color-displayDB.cpp)):

```c
// 0°
HKLM\System\CurrentControlSet\Services\nvlddmkm\State\DisplayDatabase\MSI3CB01222_2E_07E4_FF\HueRegistryKey    Type: REG_BINARY, Length: 20, Data: DB 01 00 00 14 00 00 00 10 27 00 00 00 00 00 00
```
```c
// 359°
HKLM\System\CurrentControlSet\Services\nvlddmkm\State\DisplayDatabase\MSI3CB01222_2E_07E4_FF\HueRegistryKey    Type: REG_BINARY, Length: 20, Data: DB 01 00 00 14 00 00 00 0E 27 00 00 52 FF FF FF
```

The calculation works via `cosHue_x10K` (cosinus), `sinHue_x10K` (sinus) and a checksum. `0°`:

```powershell
cos(0) = 1
1 * 10000 = 10000 = 0x00002710 hex
sin(0) = 0  = 0x00000000 hex
= last 2 bytes
```

- [nvidia/assets | color-displayDB.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/color-displayDB.cpp)
- [nvidia/assets | color-DesktopColors.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/color-DesktopColors.cpp)

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\ADAPTER_10DE_2482_00000007_00000000 : StereoPreferredTargetIdRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7103 : ConnectorWarpResamplingMethod
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase : 1641970VRcontext
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase : EdidLockData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\ADAPTER_10DE_2482_00000007_00000000 : MergedDisplayDataRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\ADAPTER_10DE_2482_00000007_00000000 : StreamCloneState
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7100 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7100 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7100 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7101 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7101 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7101 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7102 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7102 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7102 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7103 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7103 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7103 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7104 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7104 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7104 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7105 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7105 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7105 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7106 : ConnectorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7106 : ConnectorAudioDpAddress
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\CONNECTOR_10DE_2482_00000007_00000000_7106 : DEStateRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : BrightnessCalibrationDataRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ColorformatConfig
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ColorspaceConfig
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : DitherRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : DPLinkConfigDataRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : HueRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : MonitorAudioData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : MonitorDataRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : SaturationRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ScalingConfig
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : SmoothScalingData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : SmoothScalingMultiplierData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : UpScalingData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : UpScalingMultiplierData
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\ADAPTER_10DE_2482_00000007_00000000 : StereoPreferredTargetIdRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ColorspaceConfig
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : MonitorDataRegistryKey
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ScalingConfig
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX_XX_XXXX_XX : ScalingConfig
```

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl3.png?raw=true)

## Rotate display

You've to edit the `Rotation` value to change the orientation, `DefaultSettings.Orientation` gets reset to the `Rotation` state if changing it. The IDs will obviously not be the same for you.

```powershell
"dwm.exe","RegSetValue","HKLM\System\CurrentControlSet\Control\UnitedVideo\CONTROL\VIDEO\{0096AEE5-861E-11F0-896E-806E6F6E6963}\0000\DefaultSettings.Orientation","Type: REG_DWORD, Length: 4, Data: 0"
```

- `0` = Landscape
- `1` = Portrait
- `2` = Landscape (flipped)
- `3` = Portrait (flipped)

```powershell
"svchost.exe","RegSetValue","HKLM\System\CurrentControlSet\Control\GraphicsDrivers\Configuration\MSI3CB01222_2E_07E4_FF^28BF11A4ED9F56277B96046CA0884335\00\00\Rotation","Type: REG_DWORD, Length: 4, Data: 1"
```

- `1` = Landscape
- `2` = Portrait
- `3` = Landscape (flipped)
- `4` = Portrait (flipped)

`Landscape`:

```json
"HKLM\\System\\CurrentControlSet\\Control\\UnitedVideo\\CONTROL\\VIDEO\\{0096AEE5-861E-11F0-896E-806E6F6E6963}\\0000": {
  "DefaultSettings.Orientation": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\MSI3CB01222_2E_07E4_FF^28BF11A4ED9F56277B96046CA0884335\\00\\00": {
  "Rotation": { "Type": "REG_DWORD", "Data": 1 }
}
```

## View HDCP status

Seems to work via `NVCPLAPI_SETTING_HDCP_GET_STATUS_INFO`/`NVCPLAPI_SETTING_HDCP_GET_LINK_STATUS`/`NVCPLAPI_SETTING_HDCP_STATUS_REPORTING_SUPPORT` APIs.

```cpp
    // check HDCP status info to get UI messages and allerts res. IDs (see UI spec. for logic)
/** from spec, see bug #444176
    NVCPLAPI_SETTING_HDCP_GET_STATUS_INFO: retrieves the status info of whether HDCP is supported 
    on the current configuration or not, and if not, what the reasons are. 
    The possible values are (can be one or more):     
    
    A   NVCPLAPI_VALUE_HDCP_STATUS_INFO_AVAILABLE                   
    B   NVCPLAPI_VALUE_HDCP_STATUS_INFO_UNAVAILABLE                 
    C   NVCPLAPI_VALUE_HDCP_STATUS_INFO_INVALID_DISPLAY_ID          
    D   NVCPLAPI_VALUE_HDCP_STATUS_INFO_INVALID_DISPLAY             
    E   NVCPLAPI_VALUE_HDCP_STATUS_INFO_INVALID_DISPLAY_MODE        
    F   NVCPLAPI_VALUE_HDCP_STATUS_INFO_INVALID_GPU                 
//  G   NVCPLAPI_VALUE_HDCP_STATUS_INFO_INVALID_GPU_MODE    // not used           
    H   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_UNTRUST               
    I   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_LINK_FAILURES         
    J   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_KSV_LENGTH            
    K   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_KSV_SIGNATURE         
    L   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_SRM_SIGNATURE         
    M   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_SRM_REVOKED           
    N   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_REPEATER_NO_READY     
    O   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_TOPOLOGY_ERROR        
    P   NVCPLAPI_VALUE_HDCP_STATUS_INFO_ABORT_BAD_DISPLAY 

    NVCPLAPI_SETTING_HDCP_GET_LINK_STATUS: link status of the HDCP connection. Possible values are:     
    Q   NVCPLAPI_VALUE_HDCP_LINK_STATUS_REPEATER_PRESENT      
    R   NVCPLAPI_VALUE_HDCP_LINK_STATUS_DEBUGGER_DETECTED     
    S   NVCPLAPI_VALUE_HDCP_LINK_STATUS_HDCP_ON            
**/ 
```

> "*High-bandwidth Digital Content Protection (HDCP) is a copy-protection technology that prevents copying of digital audio and video content across DisplayPort, Digital Visual Interface (DVI), or High-Definition Multimedia Interface (HDMI) connections.*"
>
> — NVIDIA Control Panel Help, [HDCP Status](https://www.nvidia.com/content/Control-Panel-Help/vLatest/en-us/mergedProjects/Display/HDCP_Status.htm)

Whether your display supports HDCP you can practically make it unsupported using the value (can be edited using [bitmask-calc](https://github.com/nohuto/bitmask-calc)) shown below, causing:

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/hdcp-supported.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/nvidia/images/hdcp-unsupported.png?raw=true)

```json
{
  "Name": "RMHdcpKeyglobZero",
  "Comment": [
    "Type DWORD",
    "Encoding: 1 means Keyglob will be forced to zero"
  ],
  "Elements": [
    {
      "Name": "TRUE",
      "Value": "1"
    },
    {
      "Name": "FALSE",
      "Value": "0"
    }
  ]
},
```
```js
AddArg("hdcp_keyglob_zero", VALI, "Registry.ResourceManager.RMHdcpKeyglobZero", null, OS_KERNELRM, "Forces hdcp keyglob to 0 if set to 1, useful to skip RM init breakpoints on hdcp key less SKUs");
```

## Adjust desktop size and position

Whenever you use your native resolution use `No scaling`, the two options below don't matter then, as no scaling happens anyway.

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State\DisplayDatabase\MONITORXXXXX : ScalingConfig
```

`ScalingConfig` = `Scaling Mode`, `Perform Scaling on`, `Override the scaling mode...` (includes all settings?)

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl4.png?raw=true)

## Developer

### Manage GPU Performance Counters

> "*GPU performance counters are used by NVIDIA GPU profiling tools such as NVIDIA Nsight. These tools enable developers debug, profile and develop software for NVIDIA GPUs.*"
>
> — NVIDIA Control Panel Help, [Manage GPU Performance Counters](https://www.nvidia.com/content/Control-Panel-Help/vLatest/en-us/index.htm#t=mergedProjects%2FDeveloper%2FManage_Performance_Counters_-_Reference.htm&rhsearch=counters)

```json
{
  "Name": "RmProfilingAdminOnly",
  "Comment": [
    "Type DWORD",
    "This regkey restricts profiling capabilities (creation of profiling objects",
    "and access to profiling-related registers) to admin only.",
    "0 - (default - disabled)",
    "1 - Enables admin check"
  ],
  "Elements": [
    {
      "Name": "FALSE",
      "Value": "0"
    },
    {
      "Name": "TRUE",
      "Value": "1"
    }
  ]
},
```

Changing it via NVCPL:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Services\nvlddmkm\Global\NVTweak\RmProfilingAdminOnly    Type: REG_DWORD, Length: 4, Data: 1
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\RmProfilingAdminOnly    Type: REG_DWORD, Length: 4, Data: 1
```

- Restrict access to the GPU performance counters to admin users only = `1`  
- Allow access to the GPU performance counters to all users = `0`

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl5.png?raw=true)

## Video

### Adjust video color settings

Personal preference.

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XALG_Color_Range    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XEN_Color_Range    Type: REG_DWORD, Length: 4, Data: 2147483649
```

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl6.png?raw=true)

### Adjust video image settings

```json
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\0000": {
  "_User_Global_VAL_SuperResolution": { "Type": "REG_DWORD", "Data": 0 }
}
```

`On` & `Auto`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_Global_VAL_SuperResolution    Type: REG_DWORD, Length: 4, Data: 5
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_Global_DAT_SuperResolution    Type: REG_BINARY, Length: 128, Data: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_Global_XEN_SuperResolution    Type: REG_DWORD, Length: 4, Data: 2147483649
```

`Off` = `_User_Global_VAL_SuperResolution` - `0`

Quality:

`Auto` = `_User_Global_VAL_SuperResolution` - `5`  
`1` = `_User_Global_VAL_SuperResolution` - `1`  
`2` = `_User_Global_VAL_SuperResolution` - `2`  
`3` = `_User_Global_VAL_SuperResolution` - `3`  
`4` = `_User_Global_VAL_SuperResolution` - `4`  

A system restart is required to see the changes in nvcpl.

#### Noise Reduction

Path (Change `XXXX` to the correct key name):

```powershell
HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\XXXX
```

`Use the video player setting`:

```powershell
_User_SUB0_DFP1_XALG_Noise_Reduce    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
_User_SUB0_DFP1_XEN_Noise_Reduce    Type: REG_DWORD, Length: 4, Data: 0
_User_SUB0_DFP1_VAL_Noise_Reduce    Type: REG_DWORD, Length: 4, Data: 0
_User_SUB0_DFP1_XALG_Cadence    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
_User_SUB0_DFP1_XEN_Cadence    Type: REG_DWORD, Length: 4, Data: 2147483649
```

`Use NVIDIA setting`:

```powershell
_User_SUB0_DFP1_XALG_Noise_Reduce    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
_User_SUB0_DFP1_VAL_Noise_Reduce    Type: REG_DWORD, Length: 4, Data: 5
_User_SUB0_DFP1_XEN_Noise_Reduce    Type: REG_DWORD, Length: 4, Data: 2147483649
_User_SUB0_DFP1_XALG_Cadence    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
_User_SUB0_DFP1_XEN_Cadence    Type: REG_DWORD, Length: 4, Data: 2147483649
```

`_User_SUB0_DFP1_VAL_Noise_Reduce` controls the percentage, e.g. `5%` = `5 Dec` until `49%`. Nvcpl skips `50%`, which means that everything above `50` is `X - 1`, range `0-99`.

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcpl7.png?raw=true)

---

Miscellaneous notes:

`_User_SUB0_DFP1_VAL_Edge_Enhance`, `_User_SUB0_DFP1_VAL_Edge_Enhance`, `_User_SUB0_DFP1_XEN_Edge_Enhance`? = `Edge enhancment` (`Adjust video image settings` - `0`):

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_VAL_Edge_Enhance    Type: REG_DWORD, Length: 4, Data: 0
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XALG_Edge_Enhance    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XEN_Edge_Enhance    Type: REG_DWORD, Length: 4, Data: 2147483649
```

`ScalingConfig` = `Scaling Mode`, `Perform Scaling on`, `Override the scaling mode...` (includes all settings?)

Dynamic range `Full`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XALG_Color_Range    Type: REG_BINARY, Length: 8, Data: 00 00 00 00 00 00 00 00
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XEN_Color_Range    Type: REG_DWORD, Length: 4, Data: 2147483649
```

Dynamic range `Limited`:

```powershell
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XALG_Color_Range    Type: REG_BINARY, Length: 8, Data: 01 00 00 00 00 00 00 00
NVDisplay.Container.exe    RegSetValue    HKLM\System\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000\_User_SUB0_DFP1_XEN_Color_Range    Type: REG_DWORD, Length: 4, Data: 2147483649
```

# Debloated Driver

Complete [NVIDIA driver preparation tool](https://github.com/nohuto/win-config/blob/main/nvidia/assets/NVIDIA-Tool.ps1).

### Main Menu

- `1` - Debloat driver (includes optional DDU clean uninstall)
- `2` - Install driver directly  

### Driver Debloat Option

- Opens [www.techpowerup.com | nvidia-drivers](https://www.techpowerup.com/download/nvidia-geforce-graphics-drivers/)
- Removes all non-essential folders except `Display.Driver`, `NVI2`, `setup.cfg`, and `setup.exe`
- Cleans up `.xml` and `.cfg` files by removing telemetry, EULA, and web-link entries
- Miscellaenous theme configurations

### Optional DDU Cleanup

Downloads [`NV-DDU.zip`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.zip) and [`NV-DDU.ps1`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.ps1), enables Safe Boot, and reboots.

### Driver Installation

Runs `setup.exe`.

# NvAPI CLI

This will download the app to your downloads folder, read full documentation for each group [here](https://github.com/nohuto/nvapi-cli).

CLI wrapper around NVIDIA's NVAPI for querying and controlling GPU, display, and driver features on Windows. NVAPI is NVIDIA's proprietary driver API that exposes GPU and display capabilities beyond the standard OS interfaces. It's hardware and driver dependent, many functions are supported only on specific GPUs, drivers, or product lines. Expect `NVAPI_NOT_SUPPORTED` for unsupported features.

Note that the documentation is partly parsed from official documentation partly rewritten by myself. The tool isn't yet in its final state, more useful APIs may be added.

Use the tool with caution when applying control APIs, I'm not responsible for any damage/issues. This tool is in BETA state, bugs may exist. I didn't test each option on my own yet.

[assets/supported_nvapi.txt](https://github.com/nohuto/nvapi-cli/blob/main/assets/supported_nvapi.txt) includes all NVAPI functions referenced by the current source code. [assets/unsupported_nvapi.txt](https://github.com/nohuto/nvapi-cli/blob/main/assets/unsupported_nvapi.txt) includes NVAPI functions present in the NVAPI SDK header (`nvapi.h`) but not used by the current version.

## Usage

Since showing all options by default would make it very confusing, it's splitted into groups. Use `nvapi-cli info` to print the NVAPI interface version and driver branch details.

```powershell
Usage:
  nvapi-cli help [group]
  nvapi-cli info
  nvapi-cli <group> <command> [options]
    groups: gpu display mosaic sli gsync drs video hdmi dp pcf sys d3d ogl vr stereo

Use "nvapi-cli help <group>" or "nvapi-cli <group> help" for details.
Use "nvapi-cli help all" for the full list.
```

# Temporary NVCPL

`NVDisplay.Container.exe` is required for nvcpl to start. [`nvcpl.ps1`](https://github.com/nohuto/win-config/blob/main/nvidia/assets/nvcpl.ps1) starts them, waits till you close the program, and then terminates them.

Download location:

```powershell
$env:appdata\Noverse
```

Shortcut location:

```powershell
$home\Desktop\Nvcpl.lnk
```

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

- [nvidia/assets | HideManufacturer.c](https://github.com/nohuto/win-config/blob/main/nvidia/assets/trayicon-HideManufacturer.c)
- [nvidia/assets | notes.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/trayicon-notes.cpp)
- [nvidia/assets | nvcpl.c](https://github.com/nohuto/win-config/blob/main/nvidia/assets/trayicon-nvcpl.c)

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

- [nvidia/assets | dlss.c](https://github.com/nohuto/win-config/blob/main/nvidia/assets/dlss.c)
- [nvidia/assets | dlss-NGXCubinGeneric.cpp](https://github.com/nohuto/win-config/blob/main/nvidia/assets/dlss-NGXCubinGeneric.cpp)

# Disable Logging

```cpp
{ L"LogEventEntries", NV_DECLARE_REG_VAR(logSizes[LOG_EVENT]) },  // Maximum number of event log entries (global)
{ L"LogErrorEntries", NV_DECLARE_REG_VAR(logSizes[LOG_ERROR]) },  // Maximum number of error log entries (global)
{ L"LogWarningEntries", NV_DECLARE_REG_VAR(logSizes[LOG_WARNING]) },  // Maximum number of warning log entries (global)
{ L"LogPagingEntries", NV_DECLARE_REG_VAR(logSizes[LOG_PAGING]) },  // Maximum number of paging log entries (global)
```
```c
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Parameters : LogErrorEntries
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Parameters : LogEventEntries
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Parameters : LogPagingEntries
\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\Parameters : LogWarningEntries
```
```c
// Whenever new LOG is Created, add corresponding RegKey from nvdm.cpp in the comment in front of it.
#if DEBUG
LOG_EVENT_SIZE      0x2000                  // 8192 event entries (debug) L"LogEventEntries" 
LOG_WARNING_SIZE    0x1000                  // 4096 warning entries (debug) L"LogWarningEntries"
LOG_ERROR_SIZE      0x1000                  // 4096 error entries (debug) L"LogErrorEntries"
LOG_PAGING_SIZE     0x0600                  // 1536 paging entries (debug)  L"LogPagingEntries"
#else
// Microsoft has complained about the size of the logging data, so whereas
// we used to have more by default (2048, 1024, 1024, and 1536 for below,
// respectively) now we go with smaller sizes at the expense of less
// debuggability.  Upside is we use about 300K less memory than before.
LOG_EVENT_SIZE      0x0200                  // 512 event entries (retail)  L"LogEventEntries" 
LOG_WARNING_SIZE    0x0200                  // 512 warning entries (retail)  L"LogWarningEntries"
LOG_ERROR_SIZE      0x0200                  // 512 error entries (retail)  L"LogErrorEntries"
LOG_PAGING_SIZE     0x0200                  // 512 paging entries (retail) L"LogPagingEntries"
#endif // DEBUG
```

# Disable Scheduled Tasks

Disables NVIDIA scheduled tasks recusively. All 3 tasks no longer seem to be created, I'll leave this option for now.

- `NvTmRep.exe` = NVIDIA crash and telemetry reporter
- `NvTmMon` = Sends data on logon, then in a 1H interval
- `NvTmRepOnLogon` = Sends data on logon
- `NvTmRep` = Sends data at 12:25PM daily

```powershell
["NvTmRep_*", "NvTmRepOnLogon*", "NvTmMon_*"]
```

# Disable Telemetry

Installing a [debloated driver](https://noverse.dev/docs/win-config/nvidia/debloated-driver/) is the first step, the option removes several files & preventing the system from sending telemetry data.

```json
"HKLM\\SOFTWARE\\NVIDIA Corporation\\Global\\FTS": {
  "EnableRID44231": { "Type": "REG_DWORD", "Data": 0 },
  "EnableRID64640": { "Type": "REG_DWORD", "Data": 0 },
  "EnableRID66610": { "Type": "REG_DWORD", "Data": 0 }
},
```

These three values are often applied in reference to "NVIDIA Telemetry", but since these seem to be outdated (they don't exist - test it yourself via [strings2-tui](https://github.com/nohuto/strings2-tui)) they won't get applied.

Miscellaneous code snippets for `OptInOrOutPreference` & `SendTelemetryData`:

```cpp
VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH        L"Software\\NVIDIA Corporation\\NVControlPanel2\\Client"
OPTIN_OUT_KEY                               L"OptInOrOutPreference"

// entry point
int __cdecl main(int argc, char* argv[])
{
    DWORD dwOptInOutValue = 1;
    DWORD dwOptInOutWOW = KEY_WOW64_64KEY;
    bool bOptInOutPathExists = false;
    bool bOptInOutExists = readKey(HKEY_CURRENT_USER, VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH, OPTIN_OUT_KEY, &dwOptInOutWOW, &bOptInOutPathExists, &dwOptInOutValue);

    // set user opt out
    setKey(HKEY_CURRENT_USER, VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH, OPTIN_OUT_KEY, &dwOptInOutWOW, bOptInOutPathExists, 0);

    // set user opt in
    setKey(HKEY_CURRENT_USER, VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH, OPTIN_OUT_KEY, &dwOptInOutWOW, true, 1);

    if (bOptInOutExists)
    {
        setKey(HKEY_CURRENT_USER, VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH, OPTIN_OUT_KEY, &dwOptInOutWOW, bOptInOutPathExists, dwOptInOutValue);
    }
    else
    {
        deleteKey(HKEY_CURRENT_USER, VIDEO_TELEMETRY_OPTIN_OPTOUT_REGPATH, OPTIN_OUT_KEY, dwOptInOutWOW, bOptInOutPathExists, bOptInOutExists);
    }
```
```c
    /* @brief Helper method to set regkey value which is used to determine whether user wants to send telemetry data or not
     * @param userOptInOrOut = 1 if user wants to opt in for sending telemetry data else userOptInOrOut =  0
     */
    static void SetUserOptInOrOutPreferenceOfTelemetry( DWORD userOptInOrOut );
```
```cpp
bool StartupFeatures::SendTelemetryData(StartupModel &model)
{
    System system = model.GetSystem();
    int systemMajor=system.Driver.GetMajorVersion();
    int systemMinor=system.Driver.GetMinorVersion();
    string DriverVersion=to_string(systemMajor)+"."+to_string(systemMinor);   // getting driver details
    SystemTypeName stn= NvTelemetry::nvcpl::SystemTypeName::Unknown;                         // getting System Type
    switch(system.SystemType)
    {
    case 0:
        stn=NvTelemetry::nvcpl::SystemTypeName::Unknown;
        break;
    case 1:
        stn=NvTelemetry::nvcpl::SystemTypeName::Laptop;
        break;
    case 2:
        stn=NvTelemetry::nvcpl::SystemTypeName::Desktop;
        break;
    }
    //cheching for optimus, hybrid or discrete system
    bool isOptimus = false;
    optional<Gpu> coprocGpu = SystemUtil::GetCoprocGpu(system);
    if (coprocGpu)
    {
        isOptimus = true;
    }
    bool isMsHybrid = false;
    if (coprocGpu)
    {
        boost::optional<CoprocSettings> coprocSettings = coprocGpu->CoprocSettings;
        UXDASSERT(coprocSettings);
        isMsHybrid = coprocSettings->IsMsHybrid;
    }
    SystemConfigName SystemConfig;
    if(isOptimus)
    {
        if(isMsHybrid)
            SystemConfig= SystemConfigName::MsHybrid;
        else
            SystemConfig= SystemConfigName::Optimus;
    }
    else
    {
        SystemConfig= SystemConfigName::Discrete;
    }
    OperatingSystem os = system.GetOperatingSystem();
    OSVersion version = os.GetVersion();
    int osmajor=version.GetMajor();
    int osminor=version.GetMinor();
    string OpSystem=to_string(osmajor)+"."+to_string(osminor);           //fetching OS Version
    boost::optional<RegistryKey> regKey;
    vector<Gpu> systemGpus;
    SystemUtil::GetGpus(system, back_inserter(systemGpus), GpuVendor_Nvidia);
    vector<string> Names;
    BOOST_FOREACH(Gpu &gpu, systemGpus)
    {
        wstring sw= gpu.GetName(); 
        string GpuName ( sw.begin(), sw.end());
        Names.push_back(GpuName);
    }
    sort(Names.begin(),Names.end());    // sorting GPU names
    string GpuNames;
    for(unsigned int i=0;i<Names.size();i++)
        GpuNames=Names[i]+";";
    SystemUtil::SendSystemInfoTelemetryEvent(DriverVersion, OpSystem, GpuNames,stn, SystemConfig);

    return true;

}
```

1. Read driver + OS version
2. Detect system type (desktop/laptop) + GPU config (discrete/Optimus/MsHybrid)
3. Collect NVIDIA GPU names
4. Send all that as one telemetry event

Only a small sequence of the process, which I have quickly written down, can be ignored.

# Enable Developer Settings

Enables `Enable Developer Settings` in the NVIDIA control panel.

```c
//Profile info related
NV_REG_CPL_PERFCOUNT_RESTRICTION  "RmProfilingAdminOnly"
NV_REG_CPL_DEVTOOLS_VISIBLE       "NvDevToolsVisible"
```
```json
{
  "Name": "RmProfilingAdminOnly",
  "Comment": [
    "Type DWORD",
    "This regkey restricts profiling capabilities (creation of profiling objects",
    "and access to profiling-related registers) to admin only.",
    "0 - (default - disabled)",
    "1 - Enables admin check"
  ],
  "Elements": [
    {
      "Name": "FALSE",
      "Value": "0"
    },
    {
      "Name": "TRUE",
      "Value": "1"
    }
  ]
},
```

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcploptions.png?raw=true)

# Remove Context Menu Entry

Disables `Add Desktop Context Menu` in the NVIDIA control panel.

![](https://github.com/nohuto/win-config/blob/main/nvidia/images/nvcploptions.png?raw=true)

# NVLDDMKM Hex Values

I'd suggest you don't change this option and just use it for information only.

The `\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State` hive is the driver's persistent state store, not the DRS/NVAPI profile database. In tree it is used for driver owned data like the `State\DisplayDatabase` subtree and other persisted blobs (for example HDCP SRM and TDR timing records), accessed via `NvDriverRegKeyPersistentState`. This information is based on `nvlRegistry.h`, `RegistryKeys.cpp`, `displayDb.h`, `displayMgr.cpp`, `nvlTdr.cpp` (ignore it if you don't know what I mean by file names) if I understood the references correctly. Adding the values to the key doesn't affect the state in NVPI.

Values read under `\Registry\Machine\SYSTEM\ControlSet001\Services\nvlddmkm\State`, see [nvlddmkm.txt](https://github.com/nohuto/regkit/blob/main/assets/records/nvlddmkm.txt). These are the only hex ID style values which got read on boot (may differ for you if different driver) and I doubt that these have any affect, this is for documentation reasons only.

## 0x11112255 (WKS_SCANOUT_COMPOSITION_CONTROL)

NV private interface to enable/disable scanoutComposition features (`D3DOGL_WksScanoutCompositionControl`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_BITFIELDS.
```c
0x00000000 // No specific adjustments for scanoutComposition backend are selected
0x00000001 // If bit is set, scanoutComposition performs composition in unicast manner
0x00000002 // If bit is set, scanoutComposition allocation is packed to save memory usage and unicasting is required (for RID 52174)
0x00000004 // If bit is set, per pixel intensity operations on non-float allocations are performed in linear space by doing a de-gamma on reads and re-gamma on writes.
```
```c
WKS_SCANOUT_COMPOSITION_CONTROL_STRING                         "WksScanoutCompositionControl"
WKS_SCANOUT_COMPOSITION_CONTROL_ID                             0x11112255
WKS_SCANOUT_COMPOSITION_CONTROL_OVERINSTALL                    1
WKS_SCANOUT_COMPOSITION_CONTROL_OFF                            0x00000000
WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_UNICAST        0x00000001
WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_ALLOC_PACKING  0x00000002
WKS_SCANOUT_COMPOSITION_CONTROL_ENABLE_GAMMA_FOR_PER_PIXEL_INTENSITY 0x00000004
WKS_SCANOUT_COMPOSITION_CONTROL_DEFAULT                        0x00000003
```

## 0x11112256 (WKS_POST_PROCESSING_ENGINE_CONTROL)

NV private interface to adjust the behavior of the post processing engine (`D3DOGL_WksPostProcessingEngineControl`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_BITFIELDS.

```c
0x00000000 // No specific adjustments for the post processing engine are selected
0x00000001 // If bit is set, post processing engine operations are executed on desktop compositor owned fullscreen buffers.
0x00000002 // If bit is set, post processing engine operations are executed fullscreen buffers no owned by the desktop compositor.
0x00000004 // If bit is set, a global os hidden scratch framebuffer portion is used as gpu storage instead of context allocations.
0x00000008 // If bit is set, an on screen indicator should be rendered for DLDSR on top of the executed post processing engine gpu program output.
0x00000010 // If bit is set, 'If bit is set, the UMDs are instructed to schedule kernel assisted ppe work on the standard 3d render channel (this might not be supported by all umds).
0x00000020 // If bit is set, use shader resource allocated by UMD for gpu program storage. This overrides the USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE bit.
0x00000040 // If bit is set, draw an on-screen indicator for Upscale.
0xFFFF0000 // Combined mask bits for all potential mask bit controlled entries.
0x00010000 // EXECUTE_ON_DWM settings are just modified in case this mask bit is also set.
0x00020000 // EXECUTE_ON_NON_DWM settings are just modified in case this mask bit is also set.
0x00040000 // USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE settings are just modified in case this mask bit is also set.
0x00080000 // DRAW_ON_SCREEN_INDICATOR_DLDSR settings are just modified in case this mask bit is also set.
0x00100000 // USE_DEVICE_RENDER_CHANNEL settings are just modified in case this mask bit is also set.
0x00200000 // USE_UMD_SHADER_RESOURCE settings are just modified in case this mask bit is also set.
0x00400000 // DRAW_ON_SCREEN_INDICATOR_UPSCALE settings are just modified in case this mask bit is also set.
```
```c
WKS_POST_PROCESSING_ENGINE_CONTROL_STRING                      "WksPostProcessingEngineControl"
WKS_POST_PROCESSING_ENGINE_CONTROL_ID                          0x11112256
WKS_POST_PROCESSING_ENGINE_CONTROL_OVERINSTALL                 1
WKS_POST_PROCESSING_ENGINE_CONTROL_OFF                         0x00000000
WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_DWM              0x00000001
WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_NON_DWM          0x00000002
WKS_POST_PROCESSING_ENGINE_CONTROL_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE 0x00000004
WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_DLDSR 0x00000008
WKS_POST_PROCESSING_ENGINE_CONTROL_USE_DEVICE_RENDER_CHANNEL   0x00000010
WKS_POST_PROCESSING_ENGINE_CONTROL_USE_UMD_SHADER_RESOURCE     0x00000020
WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_UPSCALE 0x00000040
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_ALL_CONTROLLED_BITS 0xFFFF0000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_DWM     0x00010000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_NON_DWM 0x00020000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE 0x00040000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_DLDSR 0x00080000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_DEVICE_RENDER_CHANNEL 0x00100000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_UMD_SHADER_RESOURCE 0x00200000
WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_UPSCALE 0x00400000
WKS_POST_PROCESSING_ENGINE_CONTROL_DEFAULT                     0x00000033
```

## 0x112493bd (WKS_STEREO_DONGLE_SUPPORT)

Control of the stereo dongle (`D3DOGL_EnableStereoDongleSupport`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0 // Disable stereo dongle support
1 // Enable stereo dongle using stereo signal from GPU (default)
2 // Enable stereo dongle using stereo signal from DLP
```
```c
WKS_STEREO_DONGLE_SUPPORT_STRING                               "EnableStereoDongleSupport"
WKS_STEREO_DONGLE_SUPPORT_ID                                   0x112493bd
WKS_STEREO_DONGLE_SUPPORT_OVERINSTALL                          1
WKS_STEREO_DONGLE_SUPPORT_OFF                                  0
WKS_STEREO_DONGLE_SUPPORT_DAC                                  1
WKS_STEREO_DONGLE_SUPPORT_DLP                                  2
WKS_STEREO_DONGLE_SUPPORT_DEFAULT                              WKS_STEREO_DONGLE_SUPPORT_DAC
```

## 0x11333333 (WKS_STEREO_SWAP_MODE)

`D3DOGL_33333333`? Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0x0 // Application Control (default)
0x1 // Per Eye
0x2 // Per Eye-Pair
0x3 // Legacy Behavior
0x4 // Per Eye swap for swapgroup
```

```c
WKS_STEREO_SWAP_MODE_STRING                                    "33333333"
WKS_STEREO_SWAP_MODE_ID                                        0x11333333
WKS_STEREO_SWAP_MODE_OVERINSTALL                               1
WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL                       0x0
WKS_STEREO_SWAP_MODE_PER_EYE                                   0x1
WKS_STEREO_SWAP_MODE_PER_EYE_PAIR                              0x2
WKS_STEREO_SWAP_MODE_LEGACY_BEHAVIOR                           0x3
WKS_STEREO_SWAP_MODE_PER_EYE_FOR_SWAP_GROUP                    0x4
WKS_STEREO_SWAP_MODE_DEFAULT                                   WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL
```

## 0x1194f158 (VRR_MODE)

`D3DOGL_73314098`? Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0x0 // Disable G-Sync
0x1 // Enable G-SYNC in fullscreen mode only (default)
0x2 // Enable G-SYNC in fullscreen and windowed modes
```
```c
VRR_MODE_STRING                                                "73314098"
VRR_MODE_ID                                                    0x1194f158
VRR_MODE_OVERINSTALL                                           1
VRR_MODE_DISABLED                                              0x0
VRR_MODE_FULLSCREEN_ONLY                                       0x1
VRR_MODE_FULLSCREEN_AND_WINDOWED                               0x2
VRR_MODE_DEFAULT                                               VRR_MODE_FULLSCREEN_ONLY
```

## 0x11aa9e99 (WKS_STEREO_SUPPORT)

Support of the stereo API for workstations (`D3DOGL_EnableStereoSupport`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0 // Disable API stereo support (default)
1 // Enable API stereo support
```
```c
WKS_STEREO_SUPPORT_STRING                                      "EnableStereoSupport"
WKS_STEREO_SUPPORT_ID                                          0x11aa9e99
WKS_STEREO_SUPPORT_OVERINSTALL                                 1
WKS_STEREO_SUPPORT_OFF                                         0
WKS_STEREO_SUPPORT_ON                                          1
WKS_STEREO_SUPPORT_DEFAULT                                     WKS_STEREO_SUPPORT_OFF
```

## 0x11ae435c (WKS_API_STEREO_EYES_EXCHANGE)

Swaps image for the left eye with image for the right eye (`D3DOGL_APIStereoEyesExchange`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0 // Stereo eyes exchange off (default)
1 // Stereo eyes exchange on
```
```c
WKS_API_STEREO_EYES_EXCHANGE_STRING                            "APIStereoEyesExchange"
WKS_API_STEREO_EYES_EXCHANGE_ID                                0x11ae435c
WKS_API_STEREO_EYES_EXCHANGE_OVERINSTALL                       1 // MERGE
WKS_API_STEREO_EYES_EXCHANGE_OFF                               0
WKS_API_STEREO_EYES_EXCHANGE_ON                                1
WKS_API_STEREO_EYES_EXCHANGE_DEFAULT                           WKS_API_STEREO_EYES_EXCHANGE_OFF
```

## 0x11d9dc84 (WKS_FEATURE_SUPPORT_CONTROL)

NV private interface to enable/disable workstation features (`D3DOGL_WorkstationFeatureControl`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_BITFIELDS.

```c
0x00000000 // No workstation features controled by this key enabled yet
0x00000001 // Enable wks stereo for native dx11 Win8 stereo
0x00000002 // Export wddm 1.2 stereo modes only if wks stereo is enabled
0x00000004 // Enables HDMI stereo by overriding any suitable display mode to stereo
0x00000008 // Enables stereo just on HDMI displays (requires HDMI_STEREO)
0x00000020 // Use ANY_FRAME instead of PAIR_FLIP flipping mode on Kepler when tearfree or swapgroup is enabled
0x00000040 // Allow split stereo present blits to avoid tearing on the right//eye
0x00000080 // If bit is set, don't allow scanout from 10bpc buffer (create no dwm/gdi 10bpc primary buffer)
0x00000100 // If bit is set win8 stereo modes are exported with their real refreshrate (and not refreshrate/2)
0x00000200 // If bit is set vipn blanking is forced for all vidpnownership changes (per default this is done for resource preallocation only).
0x00000400 // If bit is set vipn blanking is not skipped (per default this is done for resource preallocation). Overrides ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_FULL.
0x00000800 // If bit is set, don't allow scanoutComposition on iFlip on WDDM2
0x00001000 // If bit is set sw emulated color space conversion operations and bloating will be performed on primaries allocated by dwm only.
0x00002000 // If bit is set, don't allow DFlip for DWM stereo swapchain on WDDM2.3
0x00004000 // If bit is set, display driver does not export MS stereo modes on internal (laptop) panels
0x00008000 // If bit is set, DXGK_MONITORLINKINFO_CAPABILITIES::HighColorSpace is exported for 10bpc capable (non//HDR) displays on Quadro (which allows FP16 desktops on RS4+).
0x00010000 // If bit is set, the usage of kmd's private context channel is disallowed for all applications besides dwm.
0x00020000 // If bit is set, the usage of kmd's private context channel is disallowed for the dwm process.
0x00040000 // If bit is set a swapgroup will control the flip of all heads (including dwm owned heads). Fallback option until verified that this is fixed and no longer needed.
0x00080000 // If bit is set, 3pin DIN stereo signal is persistently enabled for active stereo mode.
0x00100000 // If bit is set, dsr aka smoothscaling aka hyperscaling is supported on Quadro boards.
0x00200000 // If bit is set, dl dsr is supported on Quadro boards.
0x00400000 // If bit is set, preferred stereo output target control via NVL_CLIENT_ARB_MODE_MODULE_STEREO_OUTPUT_CONTROL is disallowed.
```
```c
WKS_FEATURE_SUPPORT_CONTROL_STRING                             "WorkstationFeatureControl"
WKS_FEATURE_SUPPORT_CONTROL_ID                                 0x11d9dc84
WKS_FEATURE_SUPPORT_CONTROL_OVERINSTALL                        1
WKS_FEATURE_SUPPORT_CONTROL_OFF                                0x00000000
WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO               0x00000001
WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED      0x00000002
WKS_FEATURE_SUPPORT_CONTROL_HDMI_STEREO                        0x00000004
WKS_FEATURE_SUPPORT_CONTROL_HDMI_EXCLUSIVE_STEREO              0x00000008
WKS_FEATURE_SUPPORT_CONTROL_USE_ANY_FRAME_FLIP_STEREO_MODE_FOR_TFP_AND_SWAPGROUP 0x00000020
WKS_FEATURE_SUPPORT_CONTROL_ALLOW_SPLIT_STEREO_PRESENT_BLITS   0x00000040
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DEEP_COLOR_SUPPORT         0x00000080
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION 0x00000100
WKS_FEATURE_SUPPORT_CONTROL_ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_ALL 0x00000200
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING 0x00000400
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_SCANOUT_COMP_IFLIP         0x00000800
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_CSC_FOR_NON_DWM_PRIMARIES  0x00001000
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DWM_STEREO_DFLIP           0x00002000
WKS_FEATURE_SUPPORT_CONTROL_DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES 0x00004000
WKS_FEATURE_SUPPORT_CONTROL_EXPORT_HIGH_COLOR_CAPS_ON_10BPC_DISPLAYS 0x00008000
WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_NON_DWM 0x00010000
WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_DWM 0x00020000
WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SWAPGROUP_DWM_FLIP_BROADCASTING 0x00040000
WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_ENFORCE_DIN_SIGNAL     0x00080000
WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SMOOTHSCALING_SUPPORT_ON_QUADRO 0x00100000
WKS_FEATURE_SUPPORT_CONTROL_ENABLE_DL_DSR_SUPPORT_ON_QUADRO    0x00200000
WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_STEREO_OUTPUT_CONTROL_OVERRIDE 0x00400000
WKS_FEATURE_SUPPORT_CONTROL_DEFAULT                            0x00086143
```

## 0x11e91a61 (WKS_API_STEREO_MODE)

Display mode to use when stereo is enabled (`D3DOGL_APIStereoMode`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0 // Active stereo mode frame interleaved shutter glasses via DDC adapter shutter glasses // ELSA Revelator (default)
1 // Passive stereo mode vertical interlaced
2 // Passive stereo mode clone mode
3 // Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN auto
4 // Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC0
5 // Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC1
6 // Active stereo mode frame interleaved shutter glasses via blue line adapter (StereoGraphics)
7 // Passive stereo mode color interleaved (Sharp 3D)
8 // Passive stereo mode colored anaglyph (left:red right:cyan(blue+green))
9 // Passive stereo mode horizontal interlaced (Arisawa/Hyundai/Zalman/Pavione/Miracube)
10 // Passive stereo mode vertical subfield (Pavione/Miracube)
11 // Passive stereo mode horizontal subfield (Pavione/Miracube)
12 // Passive stereo mode checkerboard pattern (3D DLP)
13 // Passive stereo mode inverse checkerboard pattern (3D DLP)
14 // Passive stereo mode line-wise biased vertical interlaced (Tridelity SL/SV -> SingleView)
15 // Passive stereo mode slanted line-wise biased vertical interlaced 5 view (Tridelity MV -> MultiView)
16 // Passive stereo mode using Seefront pattern (SeeFront)
17 // Passive stereo mode clone mode with right eye mirrored (Planar)
18 // Active stereo mode frame interleaved (NVIDIA 3D Vision)
19 // Passive stereo mode autodetected by monitor capabilities
20 // Active stereo mode frame interleaved (NVIDIA AegisDT embedded emitter)
21 // Active stereo mode frame interleaved (GPIO connected OEM emitter)
22 // Active stereo mode frame interleaved via DisplayPort inband MSA signal
0xffffffff // Select hardware default based on capabilities
3 // Default for Quadro: NV17_SHUTTER_GLASSES_AUTO
```
```c
WKS_API_STEREO_MODE_STRING                                     "APIStereoMode"
WKS_API_STEREO_MODE_ID                                         0x11e91a61
WKS_API_STEREO_MODE_OVERINSTALL                                1
WKS_API_STEREO_MODE_SHUTTER_GLASSES                            0
WKS_API_STEREO_MODE_VERTICAL_INTERLACED                        1
WKS_API_STEREO_MODE_TWINVIEW                                   2
WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO                  3
WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0                  4
WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1                  5
WKS_API_STEREO_MODE_COLOR_LINE                                 6
WKS_API_STEREO_MODE_COLOR_INTERLEAVED                          7
WKS_API_STEREO_MODE_ANAGLYPH                                   8
WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED                      9
WKS_API_STEREO_MODE_SIDE_FIELD                                 10
WKS_API_STEREO_MODE_SUB_FIELD                                  11
WKS_API_STEREO_MODE_CHECKERBOARD                               12
WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD                       13
WKS_API_STEREO_MODE_TRIDELITY_SL                               14
WKS_API_STEREO_MODE_TRIDELITY_MV                               15
WKS_API_STEREO_MODE_SEEFRONT                                   16
WKS_API_STEREO_MODE_STEREO_MIRROR                              17
WKS_API_STEREO_MODE_FRAME_SEQUENTIAL                           18
WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE                    19
WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL                  20
WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL               21
WKS_API_STEREO_MODE_DP_INBAND                                  22
WKS_API_STEREO_MODE_USE_HW_DEFAULT                             0xffffffff
WKS_API_STEREO_MODE_DEFAULT_GL                                 3
WKS_API_STEREO_MODE_DEFAULT                                    WKS_API_STEREO_MODE_SHUTTER_GLASSES
```

## 0x11fbdf11 (WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW)

Number of Sources we can extend on Single GPU (`D3DOGL_0xfbdf11`). Type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

```c
0x1 // One Source per GPU
0x2 // Two Sources per GPU
0x3 // Three Sources per GPU
0x4 // Four Sources per GPU
```
```c
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_STRING          "0xfbdf11"
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_ID              0x11fbdf11
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_OVERINSTALL     0
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE      0x1
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_TWO      0x2
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_THREE    0x3
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_FOUR     0x4
WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_DEFAULT         WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE
```

I didn't find any details for `0x11c776e0`, `0x01abac23`, `0x11301a5a`, `0x11424d6a`, `0x117cd1d5`, `0x118ad143`, `0x1191e8ab`.

# OC/UV Guide

Overclocking means increasing the clock speed, which increases temperatures. Undervolting limits the voltage for the GPU, resulting in lower voltage, wattage, and temperature.

## [ToC](https://github.com/nohuto/gpu-oc-uv)

- [Preconfigurations](https://github.com/nohuto/gpu-oc-uv#preconfigurations)
  - [MSI Afterburner](https://github.com/nohuto/gpu-oc-uv#msi-afterburner)
  - [3DMark](https://github.com/nohuto/gpu-oc-uv#3dmark)
  - [Superposition](https://github.com/nohuto/gpu-oc-uv#superposition)
  - [OCCT](https://github.com/nohuto/gpu-oc-uv#occt)
- [Overclocking](https://github.com/nohuto/gpu-oc-uv#overclocking)
  - [Increasing the core clock & finding the voltage](https://github.com/nohuto/gpu-oc-uv#increasing-the-core-clock--finding-the-voltage)
- [Undervolting](https://github.com/nohuto/gpu-oc-uv#undervolting)
  - [Limiting the voltage](https://github.com/nohuto/gpu-oc-uv#limiting-the-voltage)
- [Memory Overclock](https://github.com/nohuto/gpu-oc-uv#memory-overclock)
  - [Increasing the memory clock](https://github.com/nohuto/gpu-oc-uv#increasing-the-memory-clock)
- [Final Test](https://github.com/nohuto/gpu-oc-uv#final-test)

## Preconfigurations

Install [HWiNFO](https://www.hwinfo.com/download/) to monitor all kinds of information during stress tests (sensors only). I'm leaving out the VBIOS part, but if you still want to try it, flash the correct [VBIOS](https://www.techpowerup.com/vgabios/) (search for detailed instructions if you want to do this).

You need to pay attention to the performance limit during overclocking, as you should not constantly reach it (display `Yes`):

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/hwinfo-powerlimit.png?raw=true)

### MSI Afterburner

Download [MSI Afterburner](https://www.msi.com/Landing/afterburner/graphics-cards) and set a custom fan curve, which could look like the one in the image below (make sure the speed is not too low, as this would affect your results). You can use the preconfigured [cfg file](https://github.com/nohuto/gpu-oc-uv/blob/main/assets/MSIAfterburner.cfg) or skip it.

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/fancurve.png?raw=true)

If you don't want MSI afterburner running in the background all time, set a static curve and load a profile on system start:

```powershell
schtasks /create /sc ONSTART /tn "MSIAfterburnerProfile" /tr "powershell.exe -NoProfile -Command \"Set-Location 'C:\Program Files (x86)\MSI Afterburner'; .\MSIAfterburner.exe /profile1\"" /rl HIGHEST /delay 0000:20
```

| Parameter | Description |
|--|--|
| /sc `<scheduletype>` | Specifies the schedule type. The valid values include:<ul><li>**MINUTE** - Specifies the number of minutes before the task should run.</li><li>**HOURLY** - Specifies the number of hours before the task should run.</li><li>**DAILY** - Specifies the number of days before the task should run.</li><li>**WEEKLY** Specifies the number of weeks before the task should run.</li><li>**MONTHLY** - Specifies the number of months before the task should run.</li><li>**ONCE** - Specifies that that task runs once at a specified date and time.</li><li>**ONSTART** - Specifies that the task runs every time the system starts. You can specify a start date, or run the task the next time the system starts.</li><li>**ONLOGON** - Specifies that the task runs whenever a user (any user) logs on. You can specify a date, or run the task the next time the user logs on.</li><li>**ONIDLE** - Specifies that the task runs whenever the system is idle for a specified period of time. You can specify a date, or run the task the next time the system is idle.</li><li>**ONEVENT** - Specifies that the task runs based on an event that matches information from the system event log including the EventID. |
| /tn `<taskname>` | Specifies a name for the task. Each task on the system must have a unique name and must conform to the rules for file names, not exceeding 238 characters. Use quotation marks to enclose names that include spaces. To store your scheduled task in a different folder, run **/tn** `<folder name\task name>`. |
| /tr `<Taskrun>` | Specifies the program or command that the task runs. Type the fully qualified path and file name of an executable file, script file, or batch file. The path name must not exceed 262 characters. If you don't add the path, **schtasks** assumes that the file is in the `<systemroot>\System32` directory. |
| /rl `<level>` | Specifies the Run Level for the job. Acceptable values are **LIMITED** (scheduled tasks will be ran with the least level of privileges, such as Standard User accounts) and **HIGHEST** (scheduled tasks will be ran with the highest level of privileges, such as Superuser accounts). The default value is **Limited**. |
| /delay `<delaytime>` | Specifies the wait time to delay running the task after it's triggered in mmmm:ss format. |

Set the `Power Limit` and `Temp. Limit` options to the maximum value and change the priority to power limit. Also, disable the automatic start option for now to prevent a loop if something goes wrong.

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/MSIAfterburner-limits.png?raw=true)

---

Install [Superposition](https://benchmark.unigine.com/superposition), [OCCT](https://www.ocbase.com/download), [memtest vulkan](https://github.com/GpuZelenograd/memtest_vulkan/releases), and [3DMark](https://store.steampowered.com/app/223850/3DMark/). Superposition is used for stress testing (including VRAM), OCCT can be used to find errors after completing your OC//UV, and memtest is used for the final stress test of your VRAM.

### 3DMark

Use `Time Spy` and `Steel Nomad` - Avoid wildlife, solar bay and any light versions.

### Superposition

Use the highest preset that doesn't exceed your VRAM limit to test your core clock speed. Use 8k/4k optimized to test your VRAM.

### OCCT

Go into the 3D Adaptive tab and use the following settings:

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/occt.png?raw=true)

## Overclocking

Your goal is to find a specific voltage and clock frequency that don't reach the performance limit (downclock) and don't cause a crash. Raising the clock frequency alone isn't really desirable, as you'll be throttling performance most of the time (reaching the performance limit), so you should limit it to a specific voltage.

- If you ran a stress test with `+180` @ `1025` and it crashed, it's unlikely that 180 will run stably at a different voltage.
- Avoid OCCT while searching for voltage, as it'll most likely cause your card to throtte.
- Use different stress tests & let them run for `~30min`, not just some seconds.
- Hitting the power limit = downclocking
- Your clock and effective clock shouldn't have a big difference

**Kepler, Maxwell, Pascal** GPU architecture uses `12.5 MHz` steps
> GTX 600, GTX 700, GTX Titan, GTX 750, GTX 900, Titan X, GTX 10 Series

**Turing, Ampere, Ada Lovelace** GPU architecture uses `15 MHz` steps
> RTX 20 Series, RTX 30 Series, RTX 40 Series, RTX 50 Series

### Increasing the core clock & finding the voltage

1. Start at `900-950mv` & `+50MHz` - `75MHz` core clock and let superposition/3DMark run once, this should normally be stable - make sure to monitor your temperatures via HWiNFO, it should be `>75°C`, if it's already above `~85°C`, don't OC, do a UV.
> Limiting the voltage:
> 1. Open the curve editor (`CTRL` + `F`)
> 2. Click on the next right point beside the mV you want (e.g. `906`, if you want `900`)
> 3. Press `CTRL`, then highlight the curve from the right to the selected point (`906`)
> 4. Select your point (`906`) and drag it down, so the last point is below the first point (e.g. `900`) - example in UV part
2. If it finished without crashing, increase the clock frequency by `15/12.5 MHz` and run another stress test. You can also increase the mV if you haven't reached the power limit.
3. Repeat it until one of the listed situations occurs:
  - If you're crashing, lower the core clock
  - If you reach the power limit, lower the mV
4. You should now have found a voltage with a core clock that passes all stress tests without crashing/hitting the PL all time.

How your result could look like:

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/oc.png?raw=true)

## Undervolting

As mentioned at the beginning, undervolting limits the voltage for the GPU, resulting in lower voltage, wattage, and temperature.

### Limiting the voltage

1. Open the curve editor (`CTRL` + `F`)
2. Click on the next **right point** beside the mV you want (e.g. `906`, if you want `900`)
3. Press `CTRL`, then highlight the curve from the right to the selected point (`906`)
4. Select your point (`906`) and drag it down, so the last point is below the first point (e.g. `900`), example:

![](https://github.com/nohuto/gpu-oc-uv/blob/main/images/uv-curve.png?raw=true)

5. Safe the settings to a profile

## Memory Overclock

Make sure to use a stable core clock speed. Always save the benchmark results before overclocking, as you will usually stop the memory overclocking caused by worse results rather than crashing. You should also test for artifacts that occur when memory overclocking is unstable (GPU artifacts are visual distortions, glitches, flickering textures, colored pixels, or screen tearing). Most graphics cards can achieve high memory overclocking, so you can start with stress tests at `250–500 MHz`.

### Increasing the memory clock

1. Enter your selected start clock
2. Stress test it with superposition
3. If stable, increase it by `100MHz`
4. Continue with the procedure until you notice worse results, artifacts, or crashes
5. Go down to your last stable value and increase it by `50MHz`
  - Stress test it, if stable increase it by `5-10MHz`, if not go down by `50` and increase it by `5-10MHz`
6. Safe your stable memory clock to a profile
7. Test the stability of your memory clock via [memtest vulkan](https://github.com/GpuZelenograd/memtest_vulkan/releases), let it run for `~30-60min`

## Final Test

Use [OCCT](https://www.ocbase.com/download) to search for errors and for testing the stability of your OC/UV. [Furmark](https://geeks3d.com/furmark/) is known for consuming a lot of power. You can let it run for a while after completing all the steps.

# NVLDDMKM Hex Values

I'd suggest you don't change this option and just use it for information only.

```c
// dd 0x140e9ac40 (nvlddmkm.sys, 621.01)

00000001`40e9ac40  112493bd 00000001 11aa9e99 00000000
00000001`40e9ac50  11e91a61 00000003 11ae435c 00000000
00000001`40e9ac60  11333333 00000000 11d9dc84 002b6143
00000001`40e9ac70  118ad143 00000000 11c776e0 00000044
00000001`40e9ac80  11301a5a 00000008 11112255 00000003
00000001`40e9ac90  1194f158 00000001 11424d6a 02000000
00000001`40e9aca0  117cd1d5 00000000 1191e8ab 00000000
00000001`40e9acb0  11fbdf11 00000001 11112256 00000033
00000001`40e9acc0  01abac23 00000000
```

```c
// 0x1418daa80 (nvlddmkm.sys, 621.01)

00000001`418dab7e 4c8d35bb005cff  lea     r14,[nvlddmkm+0xe9ac40 (00000001`40e9ac40)] // table above
00000001`418dab8e c783a000000011000000 mov dword ptr [rbx+0A0h],11h // 17 entries
00000001`418dabc9 488d1550430d00  lea     rdx,[nvlddmkm!nvDumpConfig+0x7c3918 (00000001`419aef20)] // L"0x%08x"
00000001`418dac23 41b801000000    mov     r8d,1 // DriverRegKeyPersistentState
00000001`418dac29 e862020800      call    nvlddmkm!nvDumpConfig+0x76f888 (00000001`4195ae90) // read the value
00000001`418dac39 8b44390c        mov     eax,dword ptr [rcx+rdi+0Ch] // read failed, use table default
00000001`418dac3d 89443904        mov     dword ptr [rcx+rdi+4],eax
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\State";
    "0x01abac23" = 0; // REG_DWORD (?)
    "0x11112255" = 3; // REG_DWORD, WKS_SCANOUT_COMPOSITION_CONTROL
    "0x11112256" = 0x33; // REG_DWORD, WKS_POST_PROCESSING_ENGINE_CONTROL
    "0x112493bd" = 1; // REG_DWORD, WKS_STEREO_DONGLE_SUPPORT
    "0x11301a5a" = 8; // REG_DWORD (?)
    "0x11333333" = 0; // REG_DWORD, WKS_STEREO_SWAP_MODE
    "0x11424d6a" = 0x2000000; // REG_DWORD (?)
    "0x117cd1d5" = 0; // REG_DWORD (?)
    "0x118ad143" = 0; // REG_DWORD (?)
    "0x1191e8ab" = 0; // REG_DWORD (?)
    "0x1194f158" = 1; // REG_DWORD, VRR_MODE
    "0x11aa9e99" = 0; // REG_DWORD, WKS_STEREO_SUPPORT
    "0x11ae435c" = 0; // REG_DWORD, WKS_API_STEREO_EYES_EXCHANGE
    "0x11c776e0" = 0x44; // REG_DWORD (?)
    "0x11d9dc84" = 0x2b6143; // REG_DWORD, WKS_FEATURE_SUPPORT_CONTROL
    "0x11e91a61" = 3; // REG_DWORD, WKS_API_STEREO_MODE
    "0x11fbdf11" = 1; // REG_DWORD, WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW
```

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

NVCP/DRS calls it "Overlay Indicator".

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

"Stereo - swap mode" in NVIDIAs [NvApiDriverSettings.h](https://github.com/NVIDIA/nvapi/blob/a08f45f737bb142b070f1e23c58466ecbc82e398/NvApiDriverSettings.h#L133), type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

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

"Enable G-SYNC globally" in [NvApiDriverSettings.h](https://github.com/NVIDIA/nvapi/blob/a08f45f737bb142b070f1e23c58466ecbc82e398/NvApiDriverSettings.h#L125), type = `REG_DWORD` (SettingDWORD), attribute = ATTRIBUTE_SAMPLES.

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
0x00000040 // Allow split stereo present blits to avoid tearing on the right-eye
0x00000080 // If bit is set, don't allow scanout from 10bpc buffer (create no dwm/gdi 10bpc primary buffer)
0x00000100 // If bit is set win8 stereo modes are exported with their real refreshrate (and not refreshrate/2)
0x00000200 // If bit is set vipn blanking is forced for all vidpnownership changes (per default this is done for resource preallocation only).
0x00000400 // If bit is set vipn blanking is not skipped (per default this is done for resource preallocation). Overrides ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_FULL.
0x00000800 // If bit is set, don't allow scanoutComposition on iFlip on WDDM2
0x00001000 // If bit is set sw emulated color space conversion operations and bloating will be performed on primaries allocated by dwm only.
0x00002000 // If bit is set, don't allow DFlip for DWM stereo swapchain on WDDM2.3
0x00004000 // If bit is set, display driver does not export MS stereo modes on internal (laptop) panels
0x00008000 // If bit is set, DXGK_MONITORLINKINFO_CAPABILITIES::HighColorSpace is exported for 10bpc capable (non-HDR) displays on Quadro (which allows FP16 desktops on RS4+).
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
0 // Active stereo mode frame interleaved shutter glasses via DDC adapter shutter glasses (ELSA Revelator) (DRS default)
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
3 // Default for Quadro: NV17_SHUTTER_GLASSES_AUTO (nvlddmkm.sys 621.01 uses it when the value is missing)
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

`0x01abac23`, `0x11301a5a`, `0x11424d6a`, `0x117cd1d5`, `0x118ad143`, `0x1191e8ab`, `0x11c776e0` are also in the same nvlddmkm table, but none of my dumps, nor NVIDIAs public `NvApiDriverSettings.h` has them.


# DWM Values

DWM = Desktop Window Manager, the component *which allows for compositing visible window rendering into a single surface*. Instead of every application drawing directly to the display, each top level window normally produces content into an offscreen surface, and DWM combines the visible parts of those surfaces into the desktop image that's then presented on the monitor. Without DWM, each program would effectively draw into the visible desktop/output directly (which can cause [visual artifacts](https://github.com/nohuto/win32/blob/docs/desktop-src/LearnWin32/the-desktop-window-manager.md#the-desktop-window-manager) if a window doesn't repaint itself correctly), with DWM, each program draws into its own surface first, DWM then takes those surfaces and creates the final desktop image.

Composition means building the visible frame from multiple inputs (that are visible), so for DWM that can include normal application windows, transparent or rounded window frames, shadows, animations, blur/backdrop effects, etc. DWM decides the order (image below), and presents the result.

So for example when you've a terminal opened on the right (renders through DXGI) and a browser with a video playing on the left (wouldn't show up in [PresentMon](https://github.com/GameTechDev/PresentMon/releases) if on a empty tab as DWM can just reuse the content for the desktop frame), [PresentMon](https://github.com/GameTechDev/PresentMon/releases) can show present events for both processes while both are presenting (the browser video may show `Hardware Composed: Independent Flip` if it can use DirectFlip/iFlip + MPO, the terminal should normally be part of the composed DWM frame and it always shows up cause of the blinking cursor, I guess). If the terminal covers the browser, the browser content is no longer visible, means it no longer needs to be shown as a visible plane/surface which causes it to disappear in [PresentMon](https://github.com/GameTechDev/PresentMon/releases).

Use [PresentMon](https://github.com/GameTechDev/PresentMon/releases) without process filters to see which processes are actually producing presents and which `PresentMode` is used (only for apps that present through a graphics presentation API, e.g. DXGI, classic Win32/common control apps like my regkit project/System Informer won't show up, as their UI repainting doesn't use an DXGI swapchain).

Simple way to imagine DWM composition:

![](https://github.com/nohuto/win-config/blob/main/system/images/dwm-composition.png?raw=true)

### [Buffers, Surfaces, Presents](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#diagram-of-buffers-surfaces-and-presents)

- Presentation = showing the result of drawing work on screen
- Present = one instance of presentation, used to show drawing results from a buffer on screen (optionally with timing/metadata for when/how)
- Presentation buffer = texture containing the rendered image (apps usually have multiple buffers so one can be displayed while another is being rendered)
- Presentation surface = content placeholder that can show one buffer at a time

Means the app renders into buffers, presents one of those buffers, the surface is what DWM/presentation system can place into the desktop composition.

![](https://github.com/nohuto/win-config/blob/main/system/images/buffers-surfaces-and-presents.png?raw=true)

#### DXGI Flip Model Swapchain

Another different example including more params, see '[Swap Chain Parameters](https://www.intel.com/content/www/us/en/developer/articles/code-sample/sample-application-for-direct3d-12-flip-model-swap-chains.html)' for details on the parameters.

![](https://github.com/nohuto/win-config/blob/main/system/images/intel-presentation.png?raw=true)

### Direct Scanout

Means that presented content can be scanned out by the display hardware without first being rendered into DWMs composed desktop frame.

> "*Buffers presented by your application can be displayed by the system in a few different ways.*
>
> *The simplest way, which is the default, is that the present will be sent to DWM, and the DWM will render a frame based on the buffer that was presented. That is, there is a copy (or more accurately, a 3D render) of the presentation buffer into the backbuffer that the DWM sends to the display. This method of displaying a present is called Composition.*
>
> *A more performant mode of displaying a present would be to scan out the presentation buffer directly to hardware, and eliminate the copy that takes place. This method of displaying a present is called direct scanout. When handling presents, DWM can decide to program the hardware to directly scan out of a presentation buffer, by either assigning the buffer to a multiplane overlay plane (or MPO plane, for short), or directly flip the buffer to the hardware (known as direct flip).*
>
> *An even more performant way to display a present would be to have presents be displayed directly by the graphics kernel, and bypass the DWM entirely. This method of presentation is known as independent flip (iFlip).*
>
> — Microsoft, [Presentation modes - composition, multiplane overlay, and independent flip](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#presentation-modescomposition-multiplane-overlay-and-independent-flip)

#### Multiplane Overlay (MPO)

Used when DWM can place an app/video surface on a dedicated hardware overlay plane instead of adding it into the composed desktop frame.

> "*A type of display hardware that is able to show multiple planes shown over top of one another. Presents from the presentation manager can be displayed as part of a plane in an MPO configuration to avoid needing to copy the presentation buffer into the backbuffer that DWM sends to the display hardware."*

Means that with MPO, DWM still manages the window surface, but instead of blending that surface into the composed desktop frame, it can assign it to a hardware overlay plane. The DWM composed desktop is normally the primary plane, while MPO planes are extra hardware planes (there's also a limit of `MaxPlanes` which is why reducing `OverlayMinFPS` shouldn't be done). The final image is then created by the display hardware combining those planes, and if the display hardware handles that plane composition incorrectly, such "artifacts" can appear.

Wether an app uses MPO it usually shows as `Hardware Composed: Independent Flip`, so for example a browser playing video can show this, as the video/app surface can be placed on an overlay plane and the display hardware combines it with the DWM desktop plane. A fullscreen game for example may show `Hardware: Independent Flip` (even with MPO enabled), as it doesn't need an extra overlay plane (see DirectFlip cases below).

#### DirectFlip / iFlip

A (DXGI) swapchain buffer that can be flipped directly to the display, simplified:

- DirectFlip = app swapchain can be sent directly to display hardware instead of DWM composing it
- Independent Flip (iFlip) = DirectFlip state where the app can keep presenting directly without waking DWM every frame

DirectFlip cases:

> "*1. **DirectFlip**: Your swapchain buffers match the screen dimensions, and your window client region covers the screen. Instead of using the DWM swapchain to display on the screen, the application swapchain is used.*  
> *2. **DirectFlip with panel fitters**: Your window client region covers the screen, and your swapchain buffers are within some hardware-dependent scaling factor (for example, 0.25x to 4x) of the screen. The GPU scanout hardware is used to scale your buffer while sending it to the display.*  
> *3. **DirectFlip with multi-plane overlay (MPO)**: Your swapchain buffers are within some hardware-dependent scaling factor of your window dimensions. The DWM is able to reserve a dedicated hardware scanout plane for your application, which is then scanned out and potentially stretched to an alpha-blended sub-region of the screen.*
>
> — Microsoft, [DirectFlip](https://github.com/nohuto/win32/blob/docs/desktop-src/direct3ddxgi/for-best-performance--use-dxgi-flip-model.md#directflip)

In [PresentMon](https://github.com/GameTechDev/PresentMon/releases) ([`PresentMode` header](https://github.com/GameTechDev/PresentMon/blob/main/README-ConsoleApplication.md#csv-columns)) DirectFlip/independent flip = `Hardware: Independent Flip`/`Hardware Composed: Independent Flip` (MPO).

### [Present Modes](https://github.com/GameTechDev/PresentMon/blob/main/README-ConsoleApplication.md#csv-columns)

| PresentMode | Description |
| --- | --- |
| `Hardware: Legacy Flip` | Indicates the app took ownership of the screen, and is swapping the displayed surface every frame. (FSE) |
| `Hardware: Legacy Copy to front buffer` | Indicates the app took ownership of the screen, and is copying new contents to an already-on-screen surface every frame. |
| `Hardware: Independent Flip` | Indicates the app does not have ownership of the screen, but is still swapping the displayed surface every frame. |
| `Composed: Flip` | Indicates the app is windowed, is using ["flip model" swapchains](https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-flip-model), and is sharing its surfaces with DWM to be composed. |
| `Hardware Composed: Independent Flip` | Indicates the app is using ["flip model" swapchains](https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-flip-model), and has been granted a hardware overlay plane (MPO). |
| `Composed: Copy with GPU GDI` | Indicates the app is windowed, and is copying contents into a surface that's shared with GDI. |
| `Composed: Copy with CPU GDI` | Indicates the app is windowed, and is copying contents into a dedicated DirectX window surface. GDI contents are stored separately, and are composed together with DX contents by the DWM. |

## [Composition Swapchain Glossary](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain-glossary.md)

| Term | Meaning |
| --- | --- |
| **Available (presentation buffer)** | A buffer that's safe for your application to render to without corrupting any previous presents. To be available, a buffer must have no previous presents that reference it that haven't entered into the retiring or retired state. A present may implicitly reference a buffer from a previous present if your application didn't update a surface, as is shown in the example in [Diagram of buffers, surfaces, and presents](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#diagram-of-buffers-surfaces-and-presents). |
| **Composition (presentation mode)** | A form of presentation in which the buffer presented by your application is copied into the backbuffer that DWM renders and sends to display hardware. This form of presentation has lower system requirements than direct scanout or iflip, but it's also less efficient. |
| **Composition Surface Handle** | A **HANDLE** that can bind a visual tree visual with a given swapchain, or presentation surface. |
| **Direct flip** | A form of presentation in which the buffer presentation by your application is sent directly to display hardware on systems that don't support multiplane overlay. |
| **Direct scanout** | A form of presentation in which the buffer presented by your application is not re-rendered into the buffer DWM sends to screen, but instead sent directly to the GPU scanout hardware. This might involve DWM assigning the buffer to a multiplane overlay plane, or it might be a mode in which the buffer is sent to the scanout hardware directly via *direct flip*. In a direct scanout presentation mode, DWM might be involved in programming the hardware to display the present, or it might be bypassed entirely when the system is in *iflip* mode. |
| **Front buffer rendering** | Drawing work issued for a buffer that is currently being displayed by the system. Depending on how the buffer is being displayed, this can result in corruption or an application hang, since Direct3D protects against issuing rendering work to buffers being displayed by scanout hardware. |
| **Hardware flip queue** | An operating system (OS) feature supported by some GPU hardware that allows GPUs to display presents independently, without CPU involvement, resulting in reduced power consumption, but potentially delaying CPU state updates such as buffer available events, present retiring fence, and present statistics. |
| **Independent flip (iflip)** | A more efficient method of direct scanout presentation in which the presents are sent directly to the GPU scanout hardware, completely bypassing the DWM. This form of presentation has higher system requirements, but allows for lower latencies, and system power savings. |
| **Multiplane overlay (MPO)** | A type of display hardware that is able to show multiple planes shown over top of one another. Presents from the presentation manager can be displayed as part of a plane in an MPO configuration to avoid needing to copy the presentation buffer into the backbuffer that DWM sends to the display hardware. |
| **Present** | A single instance of presentation. A present that is intended to show the results of a drawing operation to a single buffer to the screen. |
| **Present identifier (ID)** | An incrementing identifier, unique within a given presentation manager, associated with each present to allow it to be referred to by things such as  presentation statistics and present fences. |
| **Present queue** | A queue of presents that a presentation manager has issued but have yet to be processed by the system. All presents issued are processed in queue order, even if their target times are not increasing. That is to say, before present *n* can be process, present *n-1* must also be processed; so if subsequent presents have an earlier target time than a particular present, then they'll immediately override that particular present. |
| **(Present) target time** | The time at which a particular present should be shown on screen. The system will attempt to show the present as close to this time as it can. |
| **Presentation statistics** | information returned to your application that describe how a particular present was processed. Statistics are queued in the presentation manager to be read back by your application. |
| **Presentation surface** | a content placeholder that can be bound to a visual in a visual tree. A presentation surface can have a single displayed buffer at a time. Presentation manager presents will update the buffers for one or more presentation surfaces. |
| **Presentation** | The concept of showing the results of drawing operations on screen. |
| **Presentation buffer** | A Direct3D texture that has been associated with a presentation manager, and can therefore be presented by that presentation manager to screen. |
| **Visual tree** | A tree of visuals that describes an application's layout. The composition swapchain API issues presents to one or more visuals in a visual tree. |
| **VSync interrupt** | When a GPU displays a present, it issues a VSync interrupt to awaken the CPU to notify it that that present took place. This allows the CPU to update state such as the buffer available events, the present retiring fence, and present statistics. If the GPU supports hardware flip queue, your application can explicitly control which presents should force a VSync interrupt and immediately update state, and which presents should not, allowing for improved power efficiency at the expense of delayed feedback. |

## Registry Values

Based on pseudocode of [`dwmcore.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwmcore), [`win32kfull.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/win32kfull), [`dwm.exe`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwm), [`dwminit.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwminit), [`uDWM.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/uDWM).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm";
    // dwmcore
    "BlackOutAllReadback" = 0; // REG_DWORD (bool)
    "ConfigureInput" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableDebugColors" = 0; // REG_DWORD (bool)
    "CpuClipAASinkEnableIntermediates" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableOcclusion" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableRender" = 1; // REG_DWORD (bool)
    "CpuClipAASinkForceEnable" = 0; // REG_DWORD (bool)
    "CpuClipAreaThreshold" = 20000; // REG_DWORD
    "CpuClipWarpPartitionThreshold" = 1024; // REG_DWORD
    "DisableDrawListCaching" = 0; // REG_DWORD (bool)
    "DisableProjectedShadows" = 0; // REG_DWORD (bool), probably related to https://learn.microsoft.com/en-us/uwp/api/windows.ui.composition.compositionprojectedshadow
                                   // "Represents a scene-based shadow calculated using the relationship between the light, the visual that casts the shadow,and the visual that receives the shadow, such that the shadow is drawn differently on each receiver."
    "EnableBackdropBlurCaching" = 1; // REG_DWORD (bool), nonzero allows updating/reusing cached backdrop blur
    "EnableCommonSuperSets" = 1; // REG_DWORD (bool)
    "EnableCpuClipping" = 1; // REG_DWORD (bool)
    "EnableDDisplayScanoutCaching" = 1; // REG_DWORD (bool)
    "EnableEffectCaching" = 1; // REG_DWORD (bool)
    "EnableFrontBufferRenderChecks" = 1; // REG_DWORD (bool)
    "EnableMegaRects" = 1; // REG_DWORD (bool)
    "EnablePrimitiveReordering" = 1; // REG_DWORD (bool)
    "ForceDesktopTreeFullDirty" = 0; // REG_DWORD (bool)
    "GammaBlendPencil" = 1; // REG_DWORD (bool)
    "GammaBlendWithFP16" = 1; // REG_DWORD (bool)
    "InkGPUAccelOverrideVendorWhitelist" = 0; // REG_DWORD (bool)
    "LayerClippingMode" = 2; // REG_DWORD
    "LogExpressionPerfStats" = 0; // REG_DWORD (bool)
    "MajorityScreenTest_MaxCoverage" = 10; // REG_DWORD
    "MajorityScreenTest_MinArea" = 80; // REG_DWORD
    "MajorityScreenTest_MinLength" = 80; // REG_DWORD
    "MaxD3DFeatureLevel" = 0; // REG_DWORD
    "MegaRectSearchCount" = 100; // REG_DWORD
    "MegaRectSize" = 100000; // REG_DWORD
    "MousewheelAnimationDurationMs" = 250; // REG_DWORD
    "MousewheelScrollingMode" = 0; // REG_DWORD
    "OptimizeForDirtyExpressions" = 1; // REG_DWORD (bool)
    "OverlayMinFPS" = 15; // If this value is present and set to zero, the DWM disables its minimum frame rate requirement for assigning DirectX swap chains to overlay planes in hardware that supports overlays. This makes it more likely that a low frame rate swap chain will get assigned and stay assigned to an overlay plane, if available. (https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/dwm/registry-values.md)
                          // Practically means that currently only swapchains with a min FPS of 15 would get their (MPO) overlay plane, but since overlay planes aren't unlimited ("MaxPlanes" which is sometimes only 2 and the primary DWM plane is included in there) that shouldn't be lowered
                          // You can see your MaxPlanes via dxdiag (click "Save All Information" then search for MPO MaxPlanes)
    "RenderThreadTimeoutMilliseconds" = 5000; // REG_DWORD, range 0-4294967295, threshold for the DWM compositor scheduler loop
    "SuperWetEnabled" = 1; // REG_DWORD (bool)
    "SuperWetExtensionTimeMicroseconds" = 1000; // REG_DWORD
    "TelemetryFramesReportPeriodMilliseconds" = 300000; // REG_DWORD
    "TelemetryFramesSequenceIdleIntervalMilliseconds" = 1000; // REG_DWORD
    "TelemetryFramesSequenceMaximumPeriodMilliseconds" = 1000; // REG_DWORD
    "UniformSpaceDpiMode" = 1; // REG_DWORD (bool)
    "UseHWDrawListEntriesOnWARP" = 0; // REG_DWORD (bool)

    // dwmcore CCommonRegistryData::InitializeDWMKeysFromRegistry
    "BackdropBlurCachingThrottleMs" = 25; // REG_DWORD (ms), >1000 = 1000, throttles cached backdrop blur invalidation/rebuilds
    "CpuClipFlatteningTolerance" = 0; // REG_DWORD
    "CustomRefreshRateMode" = 0; // REG_DWORD, range 0-2, >2 = default
    "DisableAdvancedDirectFlip" = 0; // REG_DWORD
    "DisableIndependentFlip" = 0; // REG_DWORD (bool)
    "DisableProjectedShadowsRendering" = 0; // REG_DWORD, read but seems unused
    "EnableRenderPathTestMode" = ?; // REG_DWORD
    "FlattenVirtualSurfaceEffectInput" = 0; // REG_DWORD (bool)
    "ForceEffectMode" = 0; // REG_DWORD, range 0-2
    "FrameCounterPosition" = 0; // REG_DWORD (bool), nonzero sets vertical debug frame counter
    "InteractionOutputPredictionDisabled" = 0; // REG_DWORD (bool)
    "OverlayTestMode" = 0; // REG_DWORD, 4 = forced MPO support, 5 = MPO disabled
    "ParallelModePolicy" = 1; // REG_DWORD, range 0-2, >=3 = 1
    "ResampleInLinearSpace" = 0; // REG_DWORD bool, nonzero forces pixel format 91
    "ResampleModeOverride" = 0; // REG_DWORD, 0 = requested mode, 1 = Lanczos?, 2 = XBR?
    "SDRBoostPercentOverride" = 0; // REG_DWORD
    "ShaderLinkingGPUBlacklist" = ?; // REG_SZ

    // uDWM CDesktopManager::Initialize
    "ForceDisableModeChangeAnimation" = 0; // REG_DWORD (bool), nonzero disables display mode change animations (duplicate/extend/disconnect style monitor change visuals)
                                           // https://blogs.windows.com/windows-insider/2024/06/13/releasing-windows-11-builds-22621-3807-and-22631-3807-to-the-release-preview-channel/

    // uDWM compositor
    "DisableHologramCompositor" = 0; // REG_DWORD, nonzero skips holographic driver watcher registration, which seems to be used for special monitors that are ignored by DWM
                                     // https://learn.microsoft.com/en-us/windows-hardware/drivers/display/specialized-monitors
                                     // https://learn.microsoft.com/en-us/uwp/api/windows.devices.display.core

    // win32kfull
    "ChildWindowDpiIsolation" = 1; // REG_DWORD (bool)
    "DisableDeviceBitmaps" = 0; // REG_DWORD (bool), nonzero makes bDwmDeviceBitmapsEnabled return false
    "DisableDeviceBitmapsForMultiAdapter" = 0; // REG_DWORD (bool), nonzero makes bDwmDeviceBitmapsEnabledForMultiAdapter return false
    "EnableDesktopOverlays" = ?; // seems to get queried but bDwmDesktopOverlaysEnabled returns 1 ("forced"?)
    "EnableResizeOptimization" = 0; // REG_DWORD bitfield, present = override
                                  // 0x1 = resize optimization for redirected windows?, 0x2 = resize optimization with DComposition synchronization?
                                  // 0x4 = use ResizeTimeoutGdi for 0x1, 0x8 = use ResizeTimeoutModern for 0x2
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-bDwmResizeOptimizationOverride@@YAHPEAK00@Z.c
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/GreWindowResizeStarted.c
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/GreEnableWindowResizeOptimization.c
    "ResizeTimeoutGdi" = 0; // REG_DWORD, only used if 0x4 in EnableResizeOptimization set (GDI = Graphics Device Interface, a library of functions for graphics output devices and includes functions for line, text, and figure drawing and for graphics manipulation?)
    "ResizeTimeoutModern" = 0; // REG_DWORD, only used if 0x8 in EnableResizeOptimization set

    // procmon
    "AnimationAttributionEnabled" = 1; // REG_DWORD, comment marshaling for composition animation attributions (probably related to MarshalAllDebugInfo)
    "AnimationAttributionHashingEnabled" = 1; // REG_DWORD, hashes those ^ comments into GUID strings
    "CompositorClockPolicy" = 1; // ?
    "DebugFailFast" = ?;
    "DisableSessionTermination" = 0; // ?
    "DisplayChangeTimeoutMs" = 1000; // ?
    "DwmInitSessionActivityId_00000001" = ?; // REG_SZ
    "ForceBasicDisplayAdapterOnDWMRestart" = 0; // ?
    "ForceFullDirtyRendering" = 0; // ?
    "ForceUDwmSoftwareDevice" = ?; // ?
    "MarshalAllDebugInfo" = ?;
    "ParallelModeRateThreshold" = 119; // ?
    "ShowDirtyRegions" = 0; // ?
    "UseFastestMonitorAsPrimary" = 0; // ?
    "vBlankWaitTimeoutMonitorOffMs" = 250; // ?
    "WarpEnableDebugColor" = 0; // ?

    // ISM
    "CaptureDisabledFor6dof" = 0; // REG_DWORD (bool)
    "DisableBloomFor6dof" = 0; // REG_DWORD (bool)
    "EnableMPCPerfCounter" = 0; // REG_DWORD (bool)
    "MPCInputRouterWaitForDebugger" = 0; // REG_DWORD (bool)
    "OneCoreNoBootDWM" = ?; // REG_DWORD
    "OneCoreNoDWMRawGameController" = 0; // REG_DWORD (bool)
    "TouchHoverReportThrottleTimeInMs" = 100; // REG_DWORD (ms), no clamp?

"HKCU\\SOFTWARE\\Microsoft\\Windows\\DWM";
    // dwm CSettingsManager preferences
    "AnimationsShiftKey" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x2)
    "DisableLockingMemory" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x40)
    "ModeChangeCurtainUseDebugColor" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x80)
    "UseDPIScaling" = 1; // REG_DWORD, nonzero (default) sets bit (preference bit 0x1)

    // uDWM colorization
    "AccentColor" = ?; // REG_DWORD, only read when ColorPrevalence is nonzero
    "AccentColorInactive" = ?; // REG_DWORD, only read when ColorPrevalence is nonzero
    "ColorPrevalence" = 0; // REG_DWORD, nonzero = accent color on title bars & window borders (uDWM then reads AccentColor/AccentColorInactive)
    "ColorizationAfterglow" = 0; // REG_DWORD
    "ColorizationAfterglowBalance" = 0; // REG_DWORD
    "ColorizationBlurBalance" = 73; // REG_DWORD
    "ColorizationColor" = 0xFF409EFE; // REG_DWORD
    "ColorizationColorBalance" = 27; // REG_DWORD
    "ColorizationGlassAttribute" = 0; // REG_DWORD
    "EnableAeroPeek" = 1; // REG_DWORD
    "EnableWindowColorization" = 1; // REG_DWORD

"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DWM";
    // dwm CSettingsManager, HKLM only read when HKCU (above) value is missing
    "DefaultColorizationColorAlpha" = 0; // REG_DWORD (used when DefaultColorizationColorState)
    "DefaultColorizationColorBlue" = 0; // REG_DWORD ^
    "DefaultColorizationColorGreen" = 0; // REG_DWORD ^
    "DefaultColorizationColorRed" = 0; // REG_DWORD ^
    "DefaultColorizationColorState" = 0; // REG_DWORD, nonzero sets bit (policy bit 0x4)
                                         // "This policy setting controls the default color for window frames when the user does not specify a color. If you enable this policy setting and specify a default color, this color is used in glass window frames, if the user does not specify a color. If you disable or do not configure this policy setting, the default internal color is used, if the user does not specify a color. Note: This policy setting can be used in conjunction with the "Prevent color changes of window frames" setting, to enforce a specific color for window frames that cannot be changed by users."
                                         // https://noverse.dev/policies?p=DWM*DwmDefaultColorizationColor_2
    "DisallowAnimations" = 0; // REG_DWORD, nonzero sets bit (policy bit 0x1) which disables DWM window animations (also causes DWM reject live preview / Aero Peek)
                              // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-SetWindowAnimation@CDesktopManager@@SAX_N@Z.c
                              // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-IsLivePreviewAllowed@CDesktopManager@@SA_NXZ.c
                              // "This policy setting controls the appearance of window animations such as those found when restoring, minimizing, and maximizing windows. If you enable this policy setting, window animations are turned off. If you disable or do not configure this policy setting, window animations are turned on. Changing this policy setting requires a logoff for it to be applied.
                              // https://noverse.dev/policies?p=DWM*DwmDisallowAnimations_2
    "DisallowColorizationColorChanges" = 0; // REG_DWORD nonzero sets bit (policy bit 0x2) which blocks DWM colorization parameter changes
                                            // This policy setting controls the ability to change the color of window frames. If you enable this policy setting, you prevent users from changing the default window frame color. If you disable or do not configure this policy setting, you allow users to change the default window frame color. Note: This policy setting can be used in conjunction with the "Specify a default color for window frames" policy setting, to enforce a specific color for window frames that cannot be changed by users."
                                            // https://noverse.dev/policies?p=DWM*DwmDisallowColorizationColorChanges_1

"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\Scene";
    // dwmcore
    "EnableBloom" = 0; // REG_DWORD (bool)
    "EnableDrawToBackbuffer" = 1; // REG_DWORD (bool)
    "EnableImageProcessing" = 1; // REG_DWORD (bool)
    "EnableShadow" = 0; // REG_DWORD (bool)
    "ImageProcessing8bit" = 0; // REG_DWORD (bool)
    "ImageProcessingMinHeight" = 200; // REG_DWORD
    "ImageProcessingMinWidth" = 200; // REG_DWORD
    "ImageProcessingResizeGrowth" = 200; // REG_DWORD
    "MsaaQualityMode" = 2; // REG_DWORD
    "SceneVisualCutoffCountOfConsecutiveIncidentsAllowed" = 5; // REG_DWORD
    "SceneVisualCutoffThresholdInMS" = 1000; // REG_DWORD

    // dwmcore CCommonRegistryData::InitializeDWMKeysFromRegistry
    "ForceNonPrimaryDisplayAdapter" = 0; // REG_DWORD (bool)
    "ImageProcessingResizeThreshold" = 0; // REG_DWORD

"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\GpuAccelInkTiming";
    // dwmcore SuperWetTiming
    "ExtensionTimeMicroseconds" = 1000; // REG_DWORD
    "PeriodicFenceMinDifferenceMicroseconds" = 500; // REG_DWORD
    "RefreshRatePercentage" = 10; // REG_DWORD

"HKLM\\SOFTWARE\\Microsoft\\Avalon.Graphics";
    // dwmcore
    "UseD3DDebugLayer" = 0; // REG_DWORD
    "Force10Level9" = 0; // REG_DWORD
    "Force10OnWDDM1_0" = 0; // REG_DWORD
```

### BackdropBlurCachingThrottleMs

It's used as a minimum time before cached blur outputs are marked dirty again (see examples below to understand what effect it has).

```c
// CCommonRegistryData::InitializeDWMKeysFromRegistry
if ( RegGetDwmDwordHelper(L"BackdropBlurCachingThrottleMs", &v11, 0LL) )
{
  v7 = v11;
  if ( v11 > 0x3E8 )
    v7 = 1000; // >1000 clamp to 1000
  v2 = g_qpcFrequency.QuadPart * v7;
}
else
{
  v2 = 25 * g_qpcFrequency.QuadPart; // missing = 25ms
}
CCommonRegistryData::m_backdropBlurCachingThrottleQPCTimeDelta = v2 / 1000;
```

[`CBackdropVisualImage::ValidateRootAndSourceRectangle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-ValidateRootAndSourceRectangle@CBackdropVisualImage@@QEAAJPEAVCVisual@@AEBV-$TMilRect_@MUMilRec.c) uses it before marking cached targets dirty again:

```c
// CBackdropVisualImage::ValidateRootAndSourceRectangle

v33 = CCommonRegistryData::m_backdropBlurCachingThrottleQPCTimeDelta & -(__int64)(*((_BYTE *)this + 1912) != 0);

if ( v32 - *((_QWORD *)v34 + 5) > v33 ) // current composition QPC time - cached target update time > throttle
{
  CCachedVisualImage::CCachedTarget::MarkDirty(v34); // rebuild afterwards
  v14 = 1;
}
```

#### Examples

You can see the differences by moving a blurry window above a animation, for example. I used a simple [rotating dot](https://github.com/nohuto/win-config/blob/main/system/assets/demos/rotatingdot.html).

##### 1000ms

<video controls width="800">
  <source src="https://raw.githubusercontent.com/nohuto/win-config/main/system/videos/BackdropBlur1000.mp4" type="video/mp4">
</video>


##### 0ms

<video controls width="800">
  <source src="https://raw.githubusercontent.com/nohuto/win-config/main/system/videos/BackdropBlur0.mp4" type="video/mp4">
</video>

### [OverlayTestMode](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-InitializeDWMKeysFromRegistry@CCommonRegistryData@@CAXXZ.c)

See [Multiplane Overlay (MPO)](https://noverse.dev/docs/win-config/system/dwm-values/#multiplane-overlay-mpo) for what MPO is.

```c
// OverlayTestMode = 0
brave.exe[5508]:
    000001C2D33F0050 (DXGI): SyncInterval=1 Flags=256 CPU=16.715ms (59.9 fps) Display=16.675ms (60.0 fps) GPU=16.714ms Latency=22.490ms Hardware Composed: Independent Flip

// OverlayTestMode = 3
brave.exe[6944]:
    000001DD865B2050 (DXGI): SyncInterval=1 Flags=256 CPU=16.636ms (60.2 fps) Display=16.675ms (60.0 fps) GPU=16.635ms Latency=22.392ms Hardware Composed: Independent Flip

// OverlayTestMode = 5
brave.exe[4556]:
    000002AFEE8B3050 (DXGI): SyncInterval=1 Flags=256 CPU=16.643ms (60.1 fps) Display=17.046ms (58.7 fps) GPU=3.548ms Latency=22.678ms Composed: Flip

// OverlayTestMode = 6
brave.exe[4584]:
    00000218E3C90050 (DXGI): SyncInterval=1 Flags=256 CPU=38.330ms (26.1 fps) Display=43.594ms (23.0 fps) GPU=38.078ms Latency=44.017ms Hardware Composed: Independent Flip
```

| Data | Meaning |
| --- | --- |
| missing | No override of `m_dwOverlayTestMode`, I guess that's the same as `0` |
| `0` | Allows MPO and no "*OverlayColor*" ([`CDrawingContext::GetSwapChainOverlayColor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-GetSwapChainOverlayColor@CDrawingContext@@AEBA-AU_D3DCOLORVALUE@@PEAVISwapChainRealization@@PEB.c) returns zero if value is `0`) |
| `1-3` | Allows MPO + "*OverlayColor*" is enabled as the value is nonzero |
| `4` | Kind of "Force success" for MPO support ([`COverlayContext::CheckMultiPlaneOverlaySupport`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-CheckMultiPlaneOverlaySupport@COverlayContext@@CA_NAEBV-$span@PEAVCOverlayContext@@$0-0@gsl@@AE.c) bypasses support query), this doesn't mean that surfaces get a overlay plane |
| `5` | Disable MPO ([`COverlayContext::OverlaysEnabled`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-OverlaysEnabled@COverlayContext@@AEBA_NXZ.c) returns false & [`COverlayContext::IsCompatibleOutputScaling`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-IsCompatibleOutputScaling@COverlayContext@@AEAA_NAEBVCMILMatrix@@@Z.c) returns 0 for one "*CompatibleOutputScaling*") |
| `>=6` | Would go into `>=4` part in [`COverlayContext::CheckMultiPlaneOverlaySupport`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-CheckMultiPlaneOverlaySupport@COverlayContext@@CA_NAEBV-$span@PEAVCOverlayContext@@$0-0@gsl@@AE.c), but only exactly `4` has the this force success case? Using `6` does allow MPO + uses the "*OverlayColor*", so it's the same as `1-3` after all.  |

#### [GetSwapChainOverlayColor](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-GetSwapChainOverlayColor@CDrawingContext@@AEBA-AU_D3DCOLORVALUE@@PEAVISwapChainRealization@@PEB.c)

The mentioned "*OverlayColor*" are overlay debug rectrangles from DWM, there are 4 different colors that DWM can use (red, yellow, orange, cyan). These colors aren't related to present modes, and I can't really tell their actual meaning yet, here's my current findings:

- Transparent = DWM draws no color
- Red = `IBitmapResource::IsWhitePixelInTopLeft()` = true
- Yellow = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` succeeds + swap chain has advanced DirectFlip
- Cyan = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` fails + no advanced DirectFlip
- Orange = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` fails (similar to cyan but it has an extra flag?)

"Advanced DirectFlip" isn't the same as DirectFlip described at the beginning.

```c
// CDrawingContext::GetSwapChainOverlayColor

v4 = CCommonRegistryData::m_dwOverlayTestMode == 0;
*(_OWORD *)&retstr->r = 0LL; // transparent
if ( v4 )
  return retstr; // OverlayTestMode = 0

if ( (*(unsigned __int8 (__fastcall **)(const struct IBitmapResource *))(*(_QWORD *)a4 + 56LL))(a4) )
{
  retstr->g = 0.0;
  retstr->b = 0.0;
  retstr->r = 1.0;
  retstr->a = 0.5; // red
  goto LABEL_12;
}

if ( v9(v8 + 8, &GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6, &v14) < 0 )
{
  v11 = *(_BYTE *)(*((_QWORD *)this + 6) + 11297LL);
  retstr->a = 0.5;

  if ( v11 )
  {
    retstr->r = 1.0;
    retstr->g = 0.77999997;
    retstr->b = 0.055; // orange
    goto LABEL_12;
  }

  retstr->r = 0.0;
  retstr->b = 1.0; // cyan
}
else
{
  retstr->b = 0.0;
  retstr->r = 1.0;
  retstr->a = 0.5; // yellow
}

retstr->g = 1.0;
```

Example (screenshot APIs don't capture the overlay color which is why I've used my phone):

![](https://github.com/nohuto/win-config/blob/main/system/images/debugcolor.jpg?raw=true)

### [RenderThreadTimeoutMilliseconds](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/_dynamic_initializer_for__CCommonRegistryData--RenderThreadTimeoutMilliseconds__.c)

It looks like a diagnostic threshold only, which controls when DWM may write the TraceLogging event `SinceWatchdogTimerStarted` (provider `Microsoft.Windows.Dwm.DwmCore`/`{1BF43430-9464-4B83-B7FB-E2638876AEEF}`). Since the default is `5000ms` I guess this is intended to be used as a kind of "compositor thread hang" event? The value [gets read](https://github.com/nohuto/regkit/blob/main/assets/records/Windows-Dwm.txt) but as said, this event should normally not happen & the provider shouldn't run by default (don't see this as my final answer, just as an possible description).

The related thread gets created by [`CConnection::StartCompositionThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-StartCompositionThread@CConnection@@AEAAJH@Z.c), which sets it's description to `DWM Compositor Thread`. The time is from the end of the previous [`CPartitionVerticalBlankScheduler::WaitForWork`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-WaitForWork@CPartitionVerticalBlankScheduler@@AEAAXXZ.c) call to the start of the next one.

![](https://github.com/nohuto/win-config/blob/main/system/images/compositor-thread.png?raw=true)

```c
// CPartitionVerticalBlankScheduler::WaitForWork
v4 = g_renderThreadTick;
g_renderThreadTick = 0LL;
if ( v4 )
{
  TickCount64 = GetTickCount64();
  v6 = TickCount64 - v4;
  if ( TickCount64 - v4 > (unsigned int)CCommonRegistryData::RenderThreadTimeoutMilliseconds // threshold check
    && !IsDebuggerPresent()
    && !(unsigned int)IsKernelDebuggerPresent()
    && (unsigned int)dword_1803E3B40 > 5
    && (unsigned __int8)tlgKeywordOn(&dword_1803E3B40, 0x400000000000LL) ) // provider/keyword
  {
    v32 = v6;
    si128.m128i_i64[0] = 0x1000000LL;
    _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>>(
      v26,
      (unsigned int)&unk_18037F354, // TraceLogging metadata, starts with "SinceWatchdogTimerStarted"
      v27,
      v28,
      (__int64)&si128,
      (__int64)&v32);
  }
}

// ...

g_renderThreadTick = GetTickCount64();
```

### MsaaQualityMode

[`CSceneResourceManager::EnsureSceneCompositor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-EnsureSceneCompositor@CSceneResourceManager@@AEAAJXZ.c) passes it into `DwmScene.dll` / `CreateDwmSceneRenderer` which is the only relation I found, and [`ID3D11Device::CheckMultisampleQualityLevels`](https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-id3d11device-checkmultisamplequalitylevels) seems to work the same as the part in the pseudocode.

| Data | AA quality | Sample count |
| --- | --- | --- |
| `0` | `1` | no MSAA (single sample) |
| `1` | `2` | up to `2x` MSAA |
| `2` | `3` | up to `4x` MSAA (default) |
| `3` | `4` | up to `8x` MSAA |
| `>=4` | `1` | no MSAA (fallback, same as 0) |

## RegistryMachine_* Keys

### win32kfull

Since some values above are from `win32kfull.sys` I'll add that here. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// win32kfull.sys
aRegistryMachin = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP"
aRegistryMachin_1 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
aRegistryMachin_2 = "\\Registry\\Machine\\software\\microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_3 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\EAS\\Policies"
aRegistryMachin_4 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontLink\\SystemLink"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC"
aRegistryMachin_6 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\FontDPI"
aRegistryMachin_8 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Type 1 Installer\\Type 1 Fonts"
aRegistryMachin_9 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_10 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize\\SmallFont"
aRegistryMachin_11 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\CodePage"
aRegistryMachin_13 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize"
aRegistryMachin_14 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\AutoRotation"
aRegistryMachin_15 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontLink\\"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\UIPI\\Clipboard\\ExceptionFormats"
aRegistryMachin_18 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize\\LargeFont"
aRegistryMachin_19 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\UIPI\\Clipboard\\IntegrityLevelDef"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles"
aRegistryMachin_22 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC\\UserLinearityData"
aRegistryMachin_23 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\AutoRotation\\NonPreserve"
aRegistryMachin_24 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI"
aRegistryMachin_25 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Edgy"
aRegistryMachin_26 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\FontMapper\\FamilyDefaults"
aRegistryMachin_27 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC\\LinearityData"
```

### win32kbase

Added for documentational purposes and future references.

```c
// win32kbase.sys
aRegistryMachin = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\DefaultPressure"
aRegistryMachin_0 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\LegacyDevices"
aRegistryMachin_1 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Terminal Server\\Video\\"
aRegistryMachin_2 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_3 = "\\Registry\\Machine\\SYSTEM\\INPUT"
aRegistryMachin_4 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\LegacyControlled"
aRegistryMachin_5 = "\\Registry\\Machine\\Hardware\\DeviceMap\\Video"
aRegistryMachin_6 = "\\Registry\\Machine\\"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Wow6432Node\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_8 = "\\Registry\\Machine\\OSDATA\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\CIT"
aRegistryMachin_9 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\IgnoredExternalMice"
aRegistryMachin_10 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION\\WINDOWS"
aRegistryMachin_11 = "\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services\\TSDDD\\Device0"
aRegistryMachin_12 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_13 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM"
aRegistryMachin_14 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_15 = "\\Registry\\Machine\\Software\\Microsoft\\Wisp\\Pen\\Digimon"
aRegistryMachin_16 = "\\Registry\\Machine\\SYSTEM\\Setup"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Control Panel\\Theme"
aRegistryMachin_18 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\CIT"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers"
aRegistryMachin_21 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Input\\DelayZonePalmRejection"
aRegistryMachin_22 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\State"
aRegistryMachin_23 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_24 = "\\Registry\\Machine\\Software\\Microsoft\\Wisp\\ExcludedDEvices"
aRegistryMachin_26 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\InvalidDisplay"
aRegistryMachin_27 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\"
aRegistryMachin_28 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI"
aRegistryMachin_29 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Win32kWPP"
aRegistryMachin_30 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager"
aRegistryMachin_31 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows\\Control Panel\\Desktop"
aRegistryMachin_32 = "\\Registry\\Machine\\Software\\WowAA32Node\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_33 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Power"
```


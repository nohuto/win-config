# DXG Kernel Values

## Registry Values

Based on pseudocode of [`dxgkrnl.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dxgkrnl)/[`dxgmms2.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dxgmms2) of 23H2/25H2 as they differ at some point, see [records/Graphics-Drivers.txt](https://github.com/nohuto/regkit/blob/main/assets/records/Graphics-Drivers.txt) for values that get read on boot ([boot capture guide](https://noverse.dev/docs/regkit/guides/wpr-wpa/)). Unless written otherwise, `REG_DWORD` ones accept the full range (`0-4294967295`), same for `REG_QWORD` (`0-18446744073709551615`).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    // GetCabcOptionFromRegistry
    "CABCOption" = 2; // REG_DWORD, if missing + if DisableCABC == 1 its 0, otherwise 2
    "DisableCABC" = 0; // REG_DWORD (bool), fallback for missing CABCOption

    // DXGADAPTER::ReadConfig
    "ContextNoPatchMode" = 0; // REG_DWORD
    "CreateGdiPrimaryOnSlaveGpu" = 0; // REG_DWORD (bool)
    "CrtcPhaseFrames" = 2; // REG_DWORD
    "DeadlockPulse" = 5000; // REG_DWORD
    "DeadlockPulseTolerance" = 500; // REG_DWORD
    "DeadlockTimeout" = 30000; // REG_DWORD
    "DisableBadDriverCheckForHwProtection" = 0; // REG_DWORD (bool)
    "DisableBoostedVSyncVirtualization" = 0; // REG_DWORD (bool)
    "DisableGdiContextGpuVa" = 0; // REG_DWORD (bool)
    "DisableIndependentVidPnVSync" = 0; // REG_DWORD (bool), VidPn = video present network
    "DisableMonitoredFenceGpuVa" = 0; // REG_DWORD (bool)
    "DisableMultiSourceMPOCheck" = 0; // REG_DWORD (bool)
                                      // From my understaning, if this is set to 0 it would let dxgkrnl mark an supported MPO layout as TryAgain (DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO, d3dkmddi.h WDK) when multiple unsynced outputs change at once, so DWM retries later (1 skips that)
    "DisableOverlays" = 0; // REG_DWORD (bool)
    "DisablePagingContextGpuVa" = 0; // REG_DWORD (bool)
    "DisableSecondaryIFlipSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "DriverManagesResidencyOverride" = 1; // REG_DWORD (bool)
    "DriverStoreCopyMode" = 1; // REG_DWORD, >1 = 2
    "EnableDecodeMPO" = 1; // REG_DWORD (bool)
    "EnableFbrValidation" = 1; // REG_DWORD (bool), Fbr = Front buffer rendering
    "EnableMultiPlaneOverlay3DDIs" = 0; // REG_DWORD (bool)
    "EnableOfferReclaimOnDriver" = 1; // REG_DWORD (bool)
    "EnablePanelFitterSupport" = 0; // REG_DWORD (bool)
    "EnableTimedCalls" = 0; // REG_DWORD (bool)
    "EnableWDDM23Synchronization" = 0; // REG_DWORD (bool)
    "Force32BitFences" = 0; // REG_DWORD (bool)
    "ForceAccessedPhysically" = 0; // REG_DWORD (bool)
    "ForceDirectFlip" = 0; // REG_DWORD (bool), if enabled it forces SupportDirectFlip (D3DKMDT_PREEMPTION_CAPS) to return true, which would for example skip such requirements (which would happen if SupportDirectFlip is false)
                           // "Driver reports SupportMultiPlaneOverlay cap but DirectFlip is not supported." (DXGADAPTER::Initialize)
    "ForceEnableDxgMms2" = 0; // REG_DWORD (bool)
    "ForceExplicitResidencyNotification" = 0; // REG_DWORD (bool)
    "ForceInitPagingProcessVaSpace" = 0; // REG_DWORD (bool)
    "ForceReplicateGdiContent" = 0; // REG_DWORD (bool)
    "ForceSecondaryIFlipSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "ForceSecondaryMPOSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "ForceSurpriseRemovalSupport" = 0; // REG_DWORD (bool)
    "ForceToMapGpuVa" = 0; // REG_DWORD (bool)
    "ForceVariableRefresh" = 0; // REG_DWORD (bool)
    "GdiPhysicalAdapterIndex" = 0; // REG_DWORD
    "InitialPagingQueueFenceValue" = 7000; // REG_DWORD
    "IoMmuFlags" = 0; // REG_DWORD
    "LeanMemoryLimit" = 1395864371; // REG_QWORD
    "NumVirtualFunctions" = 0; // REG_DWORD

    "EnableBasicRenderGpuPv" = 0; // REG_DWORD (bool), 25H2
    "KnownProcessBoostMode" = 1; // REG_DWORD, 25H2
    "SmallQuantumMode" = 1; // REG_DWORD, 25H2, 0 = disabled, 1 = auto (if GPU is MCDM adapter enabled), 2 = force enable
                            // related to VidSch scheduling quanta for GPU contexts
                            // pnputil /enum-devices /class ComputeAccelerator
    "HighPriorityCompletionMode" = 1; // REG_DWORD, 25H2
    "GpuPriorityChangeMode" = 1; // REG_DWORD, 25H2

    // DXGADAPTER::InitializePowerManagement
    "DefaultActiveIdleThreshold" = 2000; // REG_DWORD
    "DefaultD3TransitionIdleLongTimeThreshold" = 60000; // REG_DWORD
    "DefaultD3TransitionIdleShortTimeThreshold" = 10000; // REG_DWORD
    "DefaultD3TransitionIdleVeryLongTimeThreshold" = 60000; // REG_DWORD
    "DefaultD3TransitionLatencyActivelyUsed" = 80; // REG_DWORD
    "DefaultD3TransitionLatencyIdleLongTime" = 140000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleMonitorOff" = 250000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleNoContext" = 250000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleShortTime" = 80000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleVeryLongTime" = 200000; // REG_DWORD
    "DefaultExpectedResidency" = 2000; // REG_DWORD
    "DefaultIdleThresholdIdle0" = 200; // REG_DWORD
    "DefaultIdleThresholdIdle0MonitorOff" = 100; // REG_DWORD
    "DefaultLatencyToleranceIdle0" = 80; // REG_DWORD
    "DefaultLatencyToleranceIdle0MonitorOff" = 2000; // REG_DWORD
    "DefaultLatencyToleranceIdle1" = 15000; // REG_DWORD
    "DefaultLatencyToleranceIdle1MonitorOff" = 50000; // REG_DWORD
    "DefaultLatencyToleranceMemory" = 15000; // REG_DWORD
    "DefaultLatencyToleranceMemoryNoContext" = 30000; // REG_DWORD
    "DefaultLatencyToleranceNoContext" = 35000; // REG_DWORD
    "DefaultLatencyToleranceNoContextMonitorOff" = 100000; // REG_DWORD
    "DefaultLatencyToleranceOther" = 4294967295; // REG_DWORD
    "DefaultLatencyToleranceTimerPeriod" = 200; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceActivelyUsed" = 80; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceIdleShortTime" = 15000; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceMonitorOff" = 80000; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceNoContext" = 30000; // REG_DWORD
    "DefaultPowerNotRequiredTimeout" = 25000; // REG_DWORD
    "DisableDevicePowerRequired" = 0; // REG_DWORD (bool)
    "DisablePStateManagement" = 0; // REG_DWORD (bool), nonzero skips P-state query
    "EnablePODebounce" = 0; // REG_DWORD (bool)
    "EnableRuntimePowerManagement" = 1; // REG_DWORD (bool)
    "lowdebounce" = 3; // REG_DWORD
    "MonitorLatencyTolerance" = 300000; // REG_DWORD
    "MonitorRefreshLatencyTolerance" = 17000; // REG_DWORD
    "uglitch" = 900; // REG_DWORD, P-state requires ulow < uideal < uhigh < uglitch <= 1000
    "uhigh" = 700; // REG_DWORD, ^
    "uideal" = 500; // REG_DWORD, ^
    "ulow" = 300; // REG_DWORD, ^

    // DXGGLOBAL::Initialize
    "AllowAdvancedEtwLogging" = 0; // REG_DWORD (bool)
    "DiagnosticsBufferExpansionTime" = 300; // REG_DWORD
    "EnableFuzzing" = 0; // REG_DWORD (bool)
    "EnableHMDTestMode" = 0; // REG_DWORD (bool), HMD = head mounted display
    "EnableIgnoreWin32ProcessStatus" = 0; // REG_DWORD (bool)
    "ExternalDiagnosticsBufferMultiplier" = 1; // REG_DWORD
    "ExternalDiagnosticsBufferSize" = 16384; // REG_DWORD
    "ForceUsb4MonitorSupport" = 0; // REG_DWORD (bool)
    "InternalDiagnosticsBufferMultiplier" = 2; // REG_DWORD
    "InternalDiagnosticsBufferSize" = 65536; // REG_DWORD
    "InvestigationDebugParameter" = 0; // REG_DWORD
    "MaximumAdapterCount" = 32; // REG_DWORD
    "PreserveFirmwareMode" = 0; // REG_DWORD (bool)
    "PreventFullscreenWireFormatChange" = 0; // REG_DWORD (bool)
    "RapidHpdMaxChainInMilliseconds" = 0; // REG_DWORD
    "RapidHpdTimeoutInMilliseconds" = 0; // REG_DWORD
    "TerminationListSizeLimit" = 67108864; // REG_DWORD
    "TreatUsb4MonitorAsNormal" = 0; // REG_DWORD (bool)
    "Usb4MonitorDpcdDP_IN_Adapter_Number" = 0; // REG_DWORD
    "Usb4MonitorDpcdUSB4_Driver_ID" = 0; // REG_DWORD
    "Usb4MonitorPowerOnDelayInSeconds" = 0; // REG_DWORD
    "Usb4MonitorTargetId" = 0; // REG_DWORD
    "ValidateWDDMCaps" = 0; // REG_DWORD (bool)
    "WDDM2LockManagement" = 1; // REG_DWORD (bool)

    "NodeUsageTelemetryTimerInterval" = 86400; // REG_DWORD, 25H2

    // DpiFdoInitializeFdo
    "DisableVaBackedVm" = 0; // REG_DWORD (bool)
    "DisableVersionMismatchCheck" = 0; // REG_DWORD (bool)
    "GpuVirtualizationFlags" = ?; // REG_DWORD
    "DisableContainerSessionVersionCheck" = 0; // REG_DWORD (bool)
    "LimitNumberOfVfs" = 0; // REG_DWORD
    "VirtualGpuOnly" = 0; // REG_DWORD (bool)

    // DpiInitializeGlobalState
    "ForceBddFallbackOnly" = 0; // REG_DWORD (bool), 25H2
    "MiracastDefaultRtspPort" = 7236; // REG_DWORD, 0 = 7236
    "PlatformSupportMiracast" = 0; // REG_DWORD (bool)
                                   // "Miracast enables seamless display of multimedia content - including high-resolution pictures, high-definition video content, live television shows and sports, and other copy-protected premium content - between Wi-Fi devices, even if a Wi-Fi network is not available."
                                   // https://learn.micrsoft.com/en-us/windows-hardware/drivers/display/wireless-displays--miracast-
    "SupportMultipleIntegratedDisplays" = 0; // REG_DWORD (bool)
    "SuspendAdapterTimerPeriod" = 500000; // REG_DWORD

    // https://noverse.dev/docs/win-config/system/hags/
    "HwSchMode" = 0; // REG_DWORD, range 0-2, >=3 = 0
    "HwSchOverrideBlockList" = 1; // REG_DWORD (bool)
    "HwSchTreatExperimentalAsStable" = 0; // REG_DWORD (bool)

    // VIDPN_MGR::_ReadConfiguration
    "EnableExperimentalRefreshRates" = 0; // REG_DWORD (bool), 25H2
    "RapidHPDThresholdCount" = 5; // REG_DWORD
    "RapidHPDTime" = 1000; // REG_DWORD

    // TdrInit
    "TdrLevel" = 3; // REG_DWORD, range 0/1/3, other = 3
    // "Specifies the initial level of recovery."
    // 0 (TdrLevelOff) = Detection disabled
    // 1 (TdrLevelBugcheck) = Bug check on detected timeout, for example, no recovery
    // 2 (TdrLevelRecoverVGA) = Recover to VGA (not implemented)
    // 3 (TdrLevelRecover) = Recover on timeout (default value)
    "TdrDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the GPU can delay the preempt request from the GPU scheduler. TdrDelay is effectively the timeout threshold."
    "TdrDdiDelay" = 5; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the OS allows threads to leave the driver. After the specified time, the OS bug-checks the computer with the code VIDEO_TDR_FAILURE (0x116)."
    "TdrDebugMode" = 2; // REG_DWORD, range 0-3, other = 2
    // "Specifies the debugging-related behavior of the TDR process. The default value is TDR_DEBUG_MODE_RECOVER_NO_PROMPT, which indicates not to break into the debugger."
    // 0 = Break to kernel debugger before the recovery to allow investigation of the timeout.
    // 1 = Ignore any timeout.
    // 2 = Recover without breaking into the debugger (default value).
    // 3 = Recover even if some recovery conditions aren't met (for example, recover on consecutive timeouts).
    "TdrLimitTime" = 60; // REG_DWORD, range 5-3600
    // "Specifies the default time within which a specific number of TDRs (specified by the TdrLimitCount key) are allowed without crashing the computer."
    "TdrLimitCount" = 5; // REG_DWORD, range 1-32
    // "Specifies the default number of TDRs (0x117) that the system allows during the time specified by the TdrLimitTime key without crashing the computer."
    "TdrTestMode" = 0;
    // "Reserved. Don't use."
    "TdrDodPresentDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds allowed for the kernel-mode display-only driver's (KMDOD) DxgkDdiPresentDisplayOnly function to complete an asynchronous present by reporting progress to pfnPresentDisplayOnlyProgress (which is passed in the DXGKARG_PRESENT_DISPLAYONLY structure)."
    "TdrDodVSyncDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds the V-sync watchdog waits for a V-sync signal to be reported before triggering a TDR in a KMDOD."

    // DpiMiracastGetForcedMode
    "MiracastForceDisable" = 2; // REG_DWORD
                                // 0/>=2 = allow miracast
                                // 1 = force disable miracast
    "MiracastUseIhvDriver" = 2; // REG_DWORD

    // DxgMonitor::MonitorColorState::OnInitialized, 25H2
    "DefaultExternalSdrWhiteLevel" = 3000; // REG_DWORD
    "DefaultIntegratedSdrWhiteLevel" = 1000; // REG_DWORD

    // misc (single function)
    "DRTTestEnable" = 0; // REG_DWORD, DxgkpIsDrtEnabled, 1484026436 = enabled?
    "DisableAutoAcpiPostDeivce" = 0; // REG_DWORD (bool), DpiFdoDetectPostDevice, typo?
    "DxgEnableDesktopDuplicationDiagnostics" = 1; // REG_DWORD (bool), OUTPUTDUPL_MGR::IsDiagRegKeyEnabled
    "EnableAcmSupportDeveloperPreview" = 0; // REG_DWORD (bool), Acm = AutoColorManagement
    "EnableManualBrightnessMode" = 0; // REG_DWORD (bool), DpiBrightnessEscape
    "ForceEnableDWMClone" = ?; // REG_DWORD, ADAPTER_DISPLAY::Initialize (default depends on VirtualModeSupport, see DXGK_DISPLAY_DRIVERCAPS_EXTENSION in WDK)
    "HybridInternalPanelOverrideEnable" = 0; // REG_DWORD (bool), DpiHybridInternalPanelOverride
    "IsInternalRelease" = 0; // REG_DWORD (bool), DriverEntry
    "MultiMonSupport" = 1; // REG_DWORD (bool), DpiFdoHandleStartDevice
    "OutputDuplicationSessionApplicationLimit" = 4; // REG_DWORD, OUTPUTDUPL_SESSION_MGR::InitializeMaxActiveOutputDuplApps
    "PageFaultDebugMode" = 1; // REG_DWORD, VidSchInitializeAdapter, range 0-1, >1 = 1
    "TdrTestMode" = 0; // REG_DWORD (bool), _TdrIsTestMode
    "UnsupportedMonitorModesAllowed" = ?; // REG_DWORD (bool), CCD_BTL::CCD_BTL

    "CddBootImageMode" = ?;
    "CddBootScreenMode" = ?;
    "DisableLddmSpriteTearDown" = ?;
    "DisplayBrokerShouldNotBeActive" = ?;
    "DODPreferredPresentMoveRegeionsOverride" = ?;
    "DxgKrnlVersion" = ?;
    "MinDxgKrnlVersion" = ?;

    // from procmon boot trace
    "DispBrokerDebugCtrl" = ?;
    "WarpOverrideWDDMVersion" = ?;
    "WarpSupportHybridDiscrete" = ?;
    "WarpSupportsResourceResidency" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Scheduler";
    // VidSchiReadGlobalConfiguration
    "AdjustWorkerThreadPriority" = 1; // REG_DWORD (bool)
    "AutoSyncToCPUPriority" = 0; // REG_DWORD (bool)
    "BackgroundProcessMaximumAllowedPreemptionDelay" = 8; // REG_DWORD
    "CarryOverUsedQuantum" = 0; // REG_DWORD (bool)
    "ContextSchedulingPenaltyDelay" = 1000; // REG_DWORD
    "CountFlipTowardHwLimit" = 0; // REG_DWORD (bool)
    "CountPresentTowardHwLimit" = 0; // REG_DWORD (bool)
    "EnablePreemption" = 1; // REG_DWORD (bool)
    "FlipDoNotFlipMode" = 0; // REG_DWORD, range 0-2
    "ForceEnableFlipFenceModel" = 0; // REG_DWORD (bool)
    "ForceFlipTrueImmediateMode" = 0; // REG_DWORD, range 0-2, other ignored
    "ForegroundPriorityBoost" = 1; // REG_DWORD (bool)
    "HistoryLogSize" = 64; // REG_DWORD, range 16-65536 (must be power of two)
    "HwQueuedRenderPacketGroupLimit" = 2; // REG_DWORD, min 1
    "HwQueuedRenderPacketGroupLimitPerNode" = ?; // REG_BINARY
    "HwQueuePacketCap" = ?; // REG_DWORD, driver default, range 1-14
    "MaximumAllowedPreemptionDelay" = 900; // REG_DWORD
    "MaxYieldInterval" = 16; // REG_DWORD
    "NumberOfDmaPacketPool" = 20; // REG_DWORD, minimum 16
    "PerSourceCustomDuration" = ?; // REG_DWORD (bool)
    "PfnCpuOverride" = 0; // REG_DWORD, range 0-3
    "PreemptionQuantumUnit" = 50000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 0 (or 1 when GPU isn't MCDM adapter))
    "ProfileLevel" = 2; // REG_DWORD
    "QuantumUnit" = 25000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 0 (or 1 when GPU isn't MCDM adapter))
    "QueuedPresentLimit" = 3; // REG_DWORD, minimum 1
    "VSyncIdleTimeout" = 7; // REG_DWORD
    "YieldPercentage" = 10; // REG_DWORD, range 1-84

    "MaxFocusGpuQuantumWithoutPresent" = 100; // REG_DWORD, 25H2

    // VidSchiReadGlobalConfiguration (23H2)
    "DdiSuspendMode" = 0; // REG_DWORD, range 0-2
    "EnableContextDelay" = 1; // REG_DWORD (bool)
    "EnableFlipImmediateSwFlipQueue" = 1; // REG_DWORD (bool)
    "InitDriverFenceId" = 0; // REG_DWORD
    "LogDriverVSyncCallback" = 0; // REG_DWORD (bool)

    // VidSchiReadGlobalConfiguration (25H2)
    "AudioDgAutoBoostPriority" = 24; // REG_DWORD
    "DebugLargeSmoothenedDuration" = 1; // REG_DWORD (bool)
    "EnableDirectSubmission" = ?; // REG_DWORD (bool)
    "FrameServerAutoBoostPriority" = 17; // REG_DWORD

    "HwSchThreadOffloadMode" = 2; // REG_DWORD, 24H2+
    "MinYieldInterval" = 8000; // REG_DWORD
    "NpuContextSwitchQuantum" = 30000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 2 (or 1 when GPU is MCDM adapter))
    "NpuPreemptionQuantum" = 60000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 2 (or 1 when GPU is MCDM adapter))

    // VidSchiReadDeviceConfiguration
    "FlipOverrideMode" = 0; // REG_DWORD, range 0-2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\MemoryManager";
    // VIDMM_GLOBAL::ReadConfiguration
    "BugcheckOnApertureCorruption" = 0; // REG_DWORD (bool)
    "CommitProcessHeapOnDemand" = 1; // REG_DWORD (bool)
    "DirectFlipMemoryRequirement" = 200; // REG_DWORD
    "DisablePrefetching" = 0; // REG_DWORD, bit 0 only
    "DmaBufferBytesLimitAllDevices" = 8388608; // REG_DWORD
    "DmaBufferListBytesLimitAllDevices" = 4194304; // REG_DWORD
    "EventThrottleThreshold" = 300; // REG_DWORD
    "EvictTemporaryPeriod" = 60; // REG_DWORD
    "EvictUnusedPeriod" = 60; // REG_DWORD
    "ExcessiveMemTransferFlipThreshold" = 15; // REG_DWORD
    "ExcessiveMemTransferPenalty" = 5; // REG_DWORD
    "MemTransferThreshold" = 10; // REG_DWORD
    "NbCddDmaBufferLimitPerDevice" = 4; // REG_DWORD
    "NbDmaBufferLimitCompareWatermark" = 10; // REG_DWORD
    "NbDmaBufferLimitPerDevice" = 256; // REG_DWORD
    "NbPagingHistoryRecords" = 0; // REG_DWORD
    "PagesHistory" = 0; // REG_DWORD, final max 134217727
    "PinDWMAllocationBackingStore" = 1; // REG_DWORD (bool)
    "PinnedApertureMemoryLimit" = 40; // REG_DWORD, range 0-89, >=90 = 40
    "PinnedMemoryLimit" = 25; // REG_DWORD, range 0-89, >=90 = 25
    "PrivateHeapPackingBlockSize" = 8388608; // REG_DWORD
    "PrivateHeapPackingThreshold" = 1048576; // REG_DWORD
    "ProcessPendingOfferPeriod" = 1; // REG_DWORD
    "ProcessSysmemOfferPeriod" = 8; // REG_DWORD
    "QuickApertureCorruptionCheck" = 0; // REG_DWORD (bool)
    "RemovePagesFromWorkingSetOnPagingForDwm" = 1; // REG_DWORD, bit 0 only
    "SegmentBalancingPolicy" = 2; // REG_DWORD
    "SegmentCleanupCountThreshold" = 6; // REG_DWORD
    "SegmentCleanupSizeThreshold" = 4096; // REG_DWORD
    "SegmentCleanupTime" = 20; // REG_DWORD
    "SelfRefreshVramForceEvictionTimer" = 900; // REG_DWORD
    "UseUnreset" = 1; // REG_DWORD, bit 0 only

    "PhysicalHeapHighestAddress" = 4294967295; // REG_QWORD
    "PhysicalHeapLowestAddress" = 0; // REG_QWORD
    "PhysicalHeapSize" = 0; // REG_QWORD

    "MaxSegmentSize" = 0; // REG_DWORD, dynamic name (MaxSegmentSize<0-31>), nonzero rounded to 4KB & min 8MB

    // VIDMM_GLOBAL::ReadCommitLimitInformation
    "MinimumSystemMemoryCommitLimit" = 0; // REG_DWORD
    "PinnedBackingStoreLimit" = 0; // REG_DWORD
    "SecondaryPartitionCommitLimitPercentage" = 80; // REG_DWORD, range 5-100
    "SmallSystemMemorySize" = 0; // REG_DWORD
    "SystemPartitionCommitLimitPercentage" = 50; // REG_DWORD, range 5-100

    // VIDMM_GLOBAL::ReadWorkingSetConfiguration
    "WorkingSet.DefaultMaximumPercentile" = 90; // REG_DWORD
    "WorkingSet.DefaultMinimumPercentile" = 65; // REG_DWORD

    // VIDMM_GLOBAL::ReadUnusedAllocationConfiguration
    "Unused.EvictApertureOfferHighThreshold" = 30; // REG_DWORD
    "Unused.EvictApertureOfferLowThreshold" = 15; // REG_DWORD
    "Unused.EvictApertureOfferMaximumThreshold" = 30; // REG_DWORD
    "Unused.EvictApertureOfferNormalThreshold" = 15; // REG_DWORD
    "Unused.HighThreshold" = 120; // REG_DWORD
    "Unused.LowThreshold" = 15; // REG_DWORD
    "Unused.MaximumThreshold" = 1000000; // REG_DWORD
    "Unused.MinimumThreshold" = 0; // REG_DWORD
    "Unused.NormalThreshold" = 45; // REG_DWORD
    "Unused.SelfTrimHighThreshold" = 5; // REG_DWORD
    "Unused.SelfTrimLowThreshold" = 1; // REG_DWORD
    "Unused.SelfTrimMaximumThreshold" = 1000000; // REG_DWORD
    "Unused.SelfTrimMinimumThreshold" = 0; // REG_DWORD
    "Unused.SelfTrimNormalThreshold" = 2; // REG_DWORD
    "UnusedTrimmingPeriod" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadPreparationPeriodConfiguration
    "Period.AlwaysForceMemReset" = 1; // REG_DWORD (bool)
    "Period.EvictionThresholdForMemReset" = 32; // REG_DWORD
    "Period.MaximumPolicyHeldPeriod" = 64; // REG_DWORD
    "Period.MinimumPolicyHeldPeriod" = 4; // REG_DWORD
    "Period.NbOfAllocationsThresholdToMRU" = 2147483647; // REG_DWORD
    "PreparationPeriod" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadHeapConfiguration
    "DebouncedDecommitAge" = 15; // REG_DWORD
    "DebouncedPageManagement" = 1; // REG_DWORD (bool)
    "DebouncedUnlockAge" = 15; // REG_DWORD
    "LeanRecycleHeapPackingBlockSize" = 8; // REG_DWORD
    "LeanRecycleHeapPackingThreshold" = 4; // REG_DWORD
    "LeanRecycleHeapPTDBlockSize" = 64; // REG_DWORD
    "MaximumDecommitDebounce" = 256; // REG_DWORD
    "MaximumUnlockDebounce" = 256; // REG_DWORD
    "RecycleHeapPackingBlockSize" = 32; // REG_DWORD
    "RecycleHeapPackingThreshold" = 4; // REG_DWORD
    "RecycleHeapPTDBlockSize" = 1024; // REG_DWORD
    "RecycleHistory" = 0; // REG_DWORD (bool)
    "RecycleHistorySize" = 64; // REG_DWORD
    "ZeroedRecyclePages" = 1; // REG_DWORD (bool)
    "ZeroPageLockThreshold" = 2097152; // REG_DWORD, 25H2

    // VIDMM_GLOBAL::ReadPowerConfiguration
    "MemoryComponentActiveThreshold" = 300; // REG_DWORD
    "SelfRefreshMemoryEvictionThreshold" = 300; // REG_DWORD

    // VIDMM_GLOBAL::ReadGpuVaConfiguration
    "AllocateGpuVaFromHighAddresses" = 0; // REG_DWORD (bool)
    "CompanionContextMaxPendingOperations" = 128; // REG_DWORD, max 2147483647, 25H2
    "DisableMakeIoMmuAddressValid" = 0; // REG_DWORD (bool)
    "DisableUncommitGpuVaInPagingProcess" = 0; // REG_DWORD (bool)
    "EnableGpuVaGuardPages" = 0; // REG_DWORD (bool)
    "EnableZeroFlagInPde" = 0; // REG_DWORD (bool)
    "GpuVaFirstValidAddress" = 65536; // REG_DWORD
    "PagingProcessVaSpaceBitCount" = 30; // REG_DWORD

    // VIDMM_GLOBAL::ReadGpuVaPagingHistoryConfiguration
    "GpuVaPagingHistoryMask" = 391174; // REG_DWORD, 391190 on 25H2?
    "GpuVaPagingHistorySize" = 0; // REG_DWORD, default 64 on 23H2 / 1024 on 25H2 if system memory > 1395864371

    // VIDMM_GLOBAL::ReadPagingConfiguration
    "BreakOnPagingFailure" = 0; // REG_DWORD (bool)
    "DemotionWithinDeviceEnabled" = 1; // REG_DWORD (bool)
    "DeviceResumePeriodMax" = 1000; // REG_DWORD
    "DeviceResumePeriodMin" = 1000; // REG_DWORD
    "DeviceSuspendPeriodMax" = 500; // REG_DWORD
    "DeviceSuspendPeriodMin" = 500; // REG_DWORD
    "EnableAsyncResidency" = 1; // REG_DWORD (bool)
    "EnablePromotion" = 1; // REG_DWORD (bool), 25H2
    "ForceSynchronousEvict" = 0; // REG_DWORD (bool)
    "ForceUncommitGpuVAOnEvict" = 0; // REG_DWORD (bool)
    "InitialPromotionInterval" = 48; // REG_DWORD
    "MaximumPromotionInterval" = 5000; // REG_DWORD
    "PagingQueueProcessingPeriodTime" = 50; // REG_DWORD, range 16-300
    "PromotionNumberCapPerInterval" = 50; // REG_DWORD
    "PromotionTargetSizePerInterval" = 33554432; // REG_QWORD
    "TemporaryResourcePolicy" = 0; // REG_DWORD, 25H2
    "TransferFlushThreshold" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadTestAndStagingConfiguration
    "AlwaysDecommitOnOffer" = 0; // REG_DWORD (bool)
    "BudgetThreshold" = 25; // REG_DWORD, max 100
    "DecommitRepurposeMode" = 1; // REG_DWORD, range 0-2, 23H2
    "DxgMms2OfferReclaim" = 4294967295; // REG_DWORD, uses 0/1/2/4294967295
    "ExpandTo64KBAllocationSizeThreshold" = 4194304; // REG_DWORD
    "LargifyUpgradeThresholdBytes" = 0; // REG_DWORD, 25H2
    "LargifyUpgradeThresholdPercent" = 0; // REG_DWORD, max 100, 25H2
    "LazyDecommitChunkSizeMB" = 32; // REG_DWORD, max 512
    "PagingQueueFenceIncrement" = 1; // REG_DWORD, 0 = 1, max 85899345
    "RestrictToPreferredSegment" = 0; // REG_DWORD (bool)
    "Use64KPages" = 0; // REG_DWORD (bool)

    // VIDMM_GLOBAL::ReadVPRConfiguration
    "VPRCapacityRatioDenominator" = 5; // REG_DWORD
    "VPRCapacityRatioNumerator" = 1; // REG_DWORD
    "VPRGrowRatioDenominator" = 5; // REG_DWORD
    "VPRGrowRatioNumerator" = 4; // REG_DWORD

    // VIDMM_GLOBAL::ReadBudgetConfiguration
    "CriticalPeriodicTrimThreshold" = 10; // REG_DWORD, max StartPeriodicTrimThreshold
    "EnableTrimWnfCallback" = 1; // REG_DWORD (bool)
    "ForegroundTrimInterval" = 90000; // REG_DWORD, max 1200000
    "GlobalCommitmentBudget" = 0; // REG_QWORD
    "IdleTrimInterval" = 90000; // REG_DWORD, max 1200000, not less than MaximumTrimInterval
    "L_LocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "L_LocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "LNL_LocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "LNL_LocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "LNL_NonLocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "LNL_NonLocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "MaximumTrimInterval" = 10000; // REG_DWORD, range 16-60000
    "MaxProcessBudgetCapBuffer" = 256; // REG_DWORD
    "MaxVideoMemoryFragmentationBuffer" = 512; // REG_DWORD
    "MinimumTrimInterval" = 2000; // REG_DWORD, clamped to MaximumTrimInterval, min 16
    "ProcessBudgetCapBuffer" = 5; // REG_DWORD, max 50
    "StartPeriodicTrimThreshold" = 40; // REG_DWORD, max 100
    "SystemMemoryFragmentationBuffer" = 5; // REG_DWORD, max 50
    "VideoMemoryFragmentationBuffer" = 10; // REG_DWORD, max 50

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Paravirtualization";
    // DXGVIRTUALGPUMANAGER_PARAV::CreateVirtualGpu
    "GuestIoSpaceSizeInMb" = ?; // REG_DWORD, 23H2 default 1, 25H2 default 8192

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Power";
    // DXGADAPTER::InitializePowerManagement
    "UseSelfRefreshVRAMInS3" = 1; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\BasicDisplay";
    // NotifyUserMSBDAIfApplicable
    "BasicDisplayUserNotified" = 0; // REG_DWORD (bool)

    // DpiInitializeGlobalState
    "DisableBasicDisplayFallback" = 4294967295; // REG_DWORD
    "EnableBasicDisplayFallback" = 4294967295; // REG_DWORD
    "ForcePreserveBootDisplay" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Mdm";
    // DISPLAY_MUX_MGR::Init, 25H2
    "EnableMdmExperimentalDynamicFeature" = 0; // REG_DWORD (bool)
    "EnableMdmExperimentalStaticFeature" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Smm";
    // SmmQueryRegistry
    "DebugMode" = 0; // REG_DWORD, bit 0 only
    "EnablePageTracking" = 0; // REG_DWORD (bool)
    "ForceDmaRemapping" = 0; // REG_DWORD, bit 0 only
    "ForceEnableIommu" = 0; // REG_DWORD, range 0-2
    "IdentityMappedPassthrough" = 0; // REG_DWORD (bool), 25H2 only
    "LogicalAddressMode" = 0; // REG_DWORD, range 0-2
    "PreferHighLogicalAddresses" = 0; // REG_DWORD, bit 0 only

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    // VIDPN_MGR::_ReadConfiguration
    "AssertOnDdiViolation" = 0; // REG_DWORD (bool)
    "BadMonitorModeDiag" = 2; // REG_DWORD, range 1-2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    // ADAPTER_DISPLAY::Initialize
    "EnableVirtualRefreshRateOnExternalMonitor" = 0; // REG_DWORD (bool)
    "HPDFilterLimit" = 20000000; // REG_DWORD, range 1000000-100000000
    "LongLinkTrainingTimeout" = 1000; // REG_DWORD, valid when greater than ShortLinkTrainingTimeout + less than 30000
    "ModeListCaching" = 1; // REG_DWORD, enabled only if exactly 1
    "SetTimingsFlags" = 0; // REG_DWORD
    "ShortLinkTrainingTimeout" = 200; // REG_DWORD, valid when less than LongLinkTrainingTimeout

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Validation";
    // DXGVALIDATION::InitializeBootSettings
    "FailEscapeDDI" = 0; // REG_DWORD, only used when Level is nonzero and data exactly 1
    "FailRenderDDI" = 0; // REG_DWORD, ^
    "FailReserveGPUVA" = 0; // REG_DWORD, ^
    "ReportVirtualMachine" = 0; // REG_DWORD, ^
    "Level" = 0; // REG_DWORD, max 2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\MonitorDataStore\\MONITOR-ID"
    // DXGMONITOR::_RetrieveMonitorConfigurationFromMonitorStore
    "DockedOrientation" = 0; // REG_DWORD, range 0-3
    "EnableBoostRefreshRateByDefault" = 0; // REG_DWORD (bool)
    "MonitorOrientation" = 4294967295; // REG_DWORD, default depends on monitor

    // DXGMONITOR::_InitializeMonitorWithDriver
    "EnableIntegratedPanelBoostRefreshRateByDefault" = 0; // REG_DWORD (bool), 25H2
    "PreferredScaleFactor" = 0; // REG_DWORD, 0 = no per monitor override
    "VMSDisabled" = 0; // REG_DWORD (bool)

    // DxgMonitor::MonitorColorState::OnInitialized
    "AdvancedColorEnabled" = 0; // REG_DWORD (bool), 25H2 uses that as fallback
    "AutoColorManagementEnabled" = 0; // REG_DWORD (bool), 25H2
    "AutoColorManagementSupported" = 0; // REG_DWORD (bool)
    "HDREnabled" = 0; // REG_DWORD (bool), 25H2
    "SDRWhiteLevel" = 1000; // REG_DWORD, internal default 1000, external 3000

    // DxgMonitor::MonitorColorState::OnFunctionDriverArrival, Acm = AutoColorManagement
    "EnableIntegratedPanelAcmByDefault" = 0; // REG_DWORD (bool)
    "EnableIntegratedPanelHdrByDefault" = 0; // REG_DWORD (bool)
    "MicrosoftApprovedAcmSupport" = 0; // REG_DWORD (bool)

    // DxgMonitor::MonitorColorState::WcgDriverCapsSet
    "OverrideWCGCapabilities" = 0; // REG_DWORD (bool)

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration"; // https://noverse.dev/policies?p=Display*DisplaySetClonePreferredResolutionSource
    "DefaultCloneResolutionSetting" = 0; // "Set Cloned Monitor Preferred Resolution Source"
                                         // 0 = Default
                                         // 1 = Internal
                                         // 2 = External
                                         // https://noverse.dev/policies?p=Display*DisplaySetClonePreferredResolutionSource
    "DefaultTopologySetting" = 0; // "Configure Multiple Display Mode"
                                  // 0 = Default
                                  // 1 = Internal Only
                                  // 2 = External Only
                                  // 3 = Clone
                                  // 4 = Extend
                                  // https://noverse.dev/policies?p=Display*DisplayConfigureMultipleDisplayMode

// the keys below are based on a testing monitor, therefore the defaults will be different depending on the monitor

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\<CONFIG_ID>\\00\\00";
    "ActiveSize.cx" = ?; // REG_DWORD, horizontal pixels
    "ActiveSize.cy" = ?; // REG_DWORD, vertical lines
    "BoostRefreshRateMultiplier" = ?; // REG_DWORD
    "ColorBasis" = ?; // REG_DWORD
    "DwmClipBox.bottom" = ?; // REG_DWORD
    "DwmClipBox.left" = ?; // REG_DWORD
    "DwmClipBox.right" = ?; // REG_DWORD
    "DwmClipBox.top" = ?; // REG_DWORD
    "Flags" = ?; // REG_DWORD
    "HSyncFreq.Denominator" = ?; // REG_DWORD
    "HSyncFreq.Numerator" = ?; // REG_DWORD
    "PixelFormat" = ?; // REG_DWORD
    "PixelRate" = ?; // REG_DWORD
    "PrimSurfSize.cx" = ?; // REG_DWORD
    "PrimSurfSize.cy" = ?; // REG_DWORD
    "Rotation" = ?; // REG_DWORD
    "Scaling" = ?; // REG_DWORD
    "ScanlineOrdering" = ?; // REG_DWORD
    "Stride" = ?; // REG_DWORD
    "VideoStandard" = ?; // REG_DWORD
    "VirtualRefreshRate.Denominator" = ?; // REG_DWORD
    "VirtualRefreshRate.Numerator" = ?; // REG_DWORD
    "VSyncFreq.Denominator" = ?; // REG_DWORD
    "VSyncFreq.Numerator" = ?; // REG_DWORD, refresh rate

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\<CONFIG_ID>\\00";
    "CcdDbVersion" = ?; // REG_DWORD
    "ColorBasis" = ?; // REG_DWORD
    "PixelFormat" = ?; // REG_DWORD
    "Position.cx" = ?; // REG_DWORD
    "Position.cy" = ?; // REG_DWORD
    "PrimSurfSize.cx" = ?; // REG_DWORD
    "PrimSurfSize.cy" = ?; // REG_DWORD
    "Stride" = ?; // REG_DWORD

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\ScaleFactors\\MONITOR-ID";
    // DpiPersistence::ReadDpiFromRegistry
    "DpiValue" = 0; // REG_DWORD, https://noverse.dev/docs/win-config/system/display-scaling/

// miscellaneous (display adapter) PnP key values that I found while looking through xrefs of RtlQueryRegistryValuesEx within dxgkrnl/dxgmms2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX";
    // DpiReadPnpRegistryValue
    "AllowUnspecifiedHSync" = 0; // REG_DWORD (bool)
    "AllowUnspecifiedPixelRate" = 0; // REG_DWORD (bool)
    "AllowUnspecifiedVSync" = 0; // REG_DWORD (bool)
    "DisableNonPOSTDevice" = 0; // REG_DWORD (bool)
    "EnableVirtualTopologySupport" = 0; // REG_DWORD (bool)
    "ForceDualViewBehavior" = 0; // REG_DWORD (bool)
    "NeedToSuspendVidSchBeforeSetGammaRamp" = ?; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX\\MemoryManager";
    // VIDMM_GLOBAL::ReadPhysicalAdapterConfiguration
    "MaxLocalSegmentSize" = 0; // REG_DWORD (MB)
    "MaxNonLocalSegmentSize" = 0; // REG_DWORD (MB)
    "SelfRefreshVramForceEvictionTimerAC" = 900; // REG_DWORD, 25H2
    "SelfRefreshVramForceEvictionTimerDC" = 900; // REG_DWORD, 25H2
    "Supports64KBPages" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX\\DxgkSettings";
    // DXGADAPTER::InitializePowerManagement, adapter override (for GraphicsDrivers\\Power value) when version < 2400 (2.4) which was used in W10 1803
    "UseSelfRefreshVRAMInS3" = 1; // REG_DWORD (bool)
```

### EnablePreemption

With [GPU preemption](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-preemption) the video scheduler can interrupt the context executing on a GPU engine, run another context, and later resume the interrupted work (context here = GPU command stream & execution state). The scheduler requests such an interrupt using a preemption packet, the [black packet](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-hardware-queue#types-of-dma-packets) is a such a preemption packet:

![](https://github.com/nohuto/win-config/blob/main/system/images/gpu-preemption.png?raw=true)

[`VidSchiReadGlobalConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiReadGlobalConfiguration.c) stores any nonzero data as bit `0`:

```c
// VidSchiReadGlobalConfiguration

v59 = 1; // default
v112[23] = L"EnablePreemption";
v112[24] = &v59;

*(_DWORD *)(a1 + 2536) = (v62 != 0 ? 0x400 : 0) | (v61 != 0 ? 0x100 : 0) | (v60 != 0 ? 0x10 : 0) | (v59 != 0) | (v58 != 0 ? 4 : 0) | (v57 != 0 ? 2 : 0) | *(_DWORD *)(a1 + 2536) & 0xFFFFFAE8;
// v59 != 0 sets bit 0
```

[`VidSchiCheckPreemptionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiCheckPreemptionPolicy.c) reads that bit when deciding whether the context should preempt the running one. If disabled, [`VidSchiSubmitPreemptionCommand`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiSubmitPreemptionCommand.c) isn't called, means it can't interrupt the current work so other contexts have to wait.

You can read bit `0` via (the offsets will very likely be different for you):

```c
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8) // DXGGLOBAL::m_pGlobal
lkd> r @$t1 = poi(@$t0+0x300) // DXGADAPTER
lkd> r @$t2 = poi(@$t1+0xb70) // ADAPTER_RENDER
lkd> r @$t3 = poi(@$t2+0x2e8) // VIDSCH_GLOBAL
lkd> .printf "EnablePreemption=%u\n", dwo(@$t3+0x9e8)&1
EnablePreemption=1
```

### DisableOverlays

Any nonzero data disables dxgkrnl [MPO support](https://noverse.dev/docs/win-config/system/dwm-values/#multiplane-overlay-mpo) for the adapter, so DWM/apps fall back to [composed](https://noverse.dev/docs/win-config/system/dwm-values/#present-modes) or non MPO presentation modes, `0` allows MPO support.

```c
// DisableOverlays = 0
brave.exe[8984]:
    000001EA9107F050 (DXGI): SyncInterval=1 Flags=256 CPU=16.623ms (60.2 fps) Display=16.676ms (60.0 fps) GPU=16.622ms Latency=22.396ms Hardware Composed: Independent Flip

// DisableOverlays = 1
brave.exe[7444]:
    000002CDD6A4F050 (DXGI): SyncInterval=1 Flags=256 CPU=16.696ms (59.9 fps) Display=19.413ms (51.6 fps) GPU=3.510ms Latency=23.017ms Composed: Flip
```

```c
// DXGADAPTER::ReadConfig

v61 = 0;
v123 = L"DisableOverlays";
v124 = &v61;

if ( v61 )
  *((_BYTE *)this + 2756) = 0;

// ADAPTER_RENDER::IsMultiPlaneOverlaySupported
return *(_BYTE *)(*((_QWORD *)this + 2) + 2756LL);
```

That value is also kind of related to DWM's [`OverlayTestMode`](https://noverse.dev/docs/win-config/system/dwm-values/#overlaytestmode), `OverlayTestMode = 5` disables DWM's overlay use in `dwmcore`, while `DisableOverlays = 1` disables MPO support in `dxgkrnl` (both can prevent `Hardware Composed: Independent Flip`).

### ForegroundPriorityBoost

Gives foreground graphics contexts with a priority below `16` a minimum GPU scheduling priority of `16`, means when the GPU is busy, their queued GPU work can run before work with a lower scheduling priority.

```c
// ForegroundPriorityBoost = 0
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8) // DXGGLOBAL::m_pGlobal
lkd> r @$t1 = poi(@$t0+0x300) // DXGADAPTER
lkd> r @$t2 = poi(@$t1+0xb70) // ADAPTER_RENDER
lkd> r @$t3 = poi(@$t2+0x2e8) // VIDSCH_GLOBAL
lkd> .printf "ForegroundPriorityBoost=%u\n", (dwo(@$t3+0x9E8)&0x400)>>0xa // see below
ForegroundPriorityBoost=0
```

```c
// ForegroundPriorityBoost = 1
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8)
lkd> r @$t1 = poi(@$t0+0x300)
lkd> r @$t2 = poi(@$t1+0xb70)
lkd> r @$t3 = poi(@$t2+0x2e8)
lkd> .printf "ForegroundPriorityBoost=%u\n", (dwo(@$t3+0x9E8)&0x400)>>0xa
ForegroundPriorityBoost=1
```

[`VidSchiReadGlobalConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiReadGlobalConfiguration.c) sets bit `0x400` in the scheduler flags at offset `2536` (`0x9E8`) if `ForegroundPriorityBoost` is nonzero, [`VidSchiComputePriority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiComputePriority.c) reads that bit before applying the priority floor.

```c
// VidSchiReadGlobalConfiguration

v112[156] = L"ForegroundPriorityBoost";
v112[157] = &v62; // value data

*(_DWORD *)(a1 + 2536) = (v62 != 0 ? 0x400 : 0) | (v61 != 0 ? 0x100 : 0) | (v60 != 0 ? 0x10 : 0) | (v59 != 0) | (v58 != 0 ? 4 : 0) | (v57 != 0 ? 2 : 0) | *(_DWORD *)(a1 + 2536) & 0xFFFFFAE8;
```

```c
// VidSchiComputePriority

{
  if ( (*(_DWORD *)(v8 + 2536) & 0x400) != 0 && (a4 & 1) != 0 && *a5 < 0x10u )
    *a5 = 16;
  return 0LL;
}
```

### DisableVersionMismatchCheck

Controls whether the display driver's INF & KMD (`.sys`) versions get compared and if they match. `0` (default) = compare versions, nonzero = skip. See the current `.inf` file name via:

```powershell
Get-PnpDevice -Class Display -PresentOnly | Get-PnpDeviceProperty -KeyName DEVPKEY_Device_DriverInfPath | Select-Object -ExpandProperty Data
```

```c
// C:\Windows\INF\oem23.inf

[Version]
Signature   = "$Windows NT$"
Provider    = %NVIDIA%
ClassGUID   = {4D36E968-E325-11CE-BFC1-08002BE10318}
Class       = Display
DriverVer   = 05/19/2026, 32.0.16.1047
PnpLockdown = 1
CatalogFile = NV_DISP.CAT
[nv_CplInstaller]
Default_addreg = nv_CplInstaller_addreg
Default_copyfiles = nv_CplInstaller_copyfiles
```

`nvlddmkm.sys` = version `32.0.16.1047`, means the version matches. An mismatch fails adapter initialization with `STATUS_DEVICE_CONFIGURATION_ERROR` (`0xC0000182`) and records a live dump. There're some allowed mismatched, e.g. both major versions are below `21`.

## RegistryMachin_* Keys

These are from `dxgkrnl.sys`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// dxgkrnl.sys
aRegistryMachin = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\DWM"
aRegistryMachin_0 = "\\Registry\\Machine\\Software\\Microsoft\\Shell\\Docking"
aRegistryMachin_1 = "\\Registry\\Machine\\System\\Platform\\DeviceTargetingInfo"
aRegistryMachin_2 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services"
aRegistryMachin_3 = "\\Registry\\Machine\\"
aRegistryMachin_4 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\MultiScreen"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BlockList\\Runtime"
aRegistryMachin_6 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BlockList\\Kernel"
aRegistryMachin_7 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class"
aRegistryMachin_8 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Control Panel\\Theme"
aRegistryMachin_9 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers"
aRegistryMachin_10 = "\\REGISTRY\\MACHINE\\OSDATA\\Software\\Microsoft\\Durango\\LiveSettings\\HevcOverride"
aRegistryMachin_11 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Connectivity\\"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\"
aRegistryMachin_13 = "\\REGISTRY\\MACHINE\\System\\ControlSet001\\Control\\Terminal Server\\WinStations"
aRegistryMachin_14 = "\\Registry\\Machine\\Software\\Microsoft\\DirectX"
aRegistryMachin_15 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BreakOnBadEDID"
aRegistryMachin_16 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\PolicyManager\\current\\Experience"
aRegistryMachin_18 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Video\\"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\MonitorDataStore"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\AdditionalModeLists\\"
aRegistryMachin_21 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\Dwm"
aRegistryMachin_22 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\FeatureSetUsage"
aRegistryMachin_23 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\InternalMonEdid"
aRegistryMachin_24 = "\\Registry\\Machine\\Software\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\CurrentVersion\\AppModel\\PackageRepository\\Packages"
aRegistryMachin_25 = "\\Registry\\Machine\\System"
aRegistryMachin_26 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations"
```


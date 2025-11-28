# Win32PrioritySeparation

"The value of this entry determines, in part, how much processor time the threads of a process receive each time they are scheduled, and how much the allotted time can vary. It also affects the relative priority of the threads of foreground and background processes. The value of this entry is a 6-bit bitmask consisting of three sets of two bits (AABBCC). Each set of two bits determines a different characteristic of the optimizing strategy.
- The highest two bits (AABBCC) determine whether each processor interval is relatively long or short.
- The middle two bits (AABBCC) determine whether the length of the interval varies or is fixed.
- The lowest two bits (AABBCC) determine whether the threads of foreground processes get more processor time than the threads of background processes each time they run."

Read trough the `.pdf` file, if you want to get more information about the bitmask. Calculate it yourself with [`bitmask-calc`](https://github.com/5Noxi/bitmask-calc).

`0x00000018` = Long, Fixed, no boost. (`24,0x18,Longer,Fixed,36,36`)
`0x00000024` = Short, Variable, no boost. (`36,0x24,Short,Variable,6,6`)

Using a boost (bit `1-2`) would set the threads of foreground processes `2-3` times higher than from background processes, which can cause issues. `26` decimal would use a boost of `3x`. The options currently uses `36` decimal.

As you can see in this [table](https://github.com/djdallmann/GamingPCSetup/blob/d865b755a9b6af65a470b8840af54729c75a6ae7/CONTENT/RESEARCH/FINDINGS/win32prisep0to271.csv), the values repeat. Using a extremely high number therefore won't do anything else. `Win32PrioritySeparation.ps1` can be used to get the info, increase `for ($i=0; $i -le 271; $i++) {` (`271`), if you want to see more. It's a lighter version of [win32prisepcalc](https://github.com/djdallmann/GamingPCSetup/blob/master/CONTENT/SCRIPTS/win32prisepcalc.ps1).

Paste it into a terminal to see a table with all values:
```powershell
for ($i=0; $i -le 271; $i++) {
    $bin = [Convert]::ToString($i,2).PadLeft(6,'0')[-6..-1]
    $interval = if (('00','10','11' -contains ($bin[0,1] -join''))) {'Short'} else {'Long'}
    $time = if (('00','01','11' -contains ($bin[2,3] -join''))) {'Variable'} else {'Fixed'}
    $boost = switch ($bin[4,5] -join'') {'00' {'Equal and Fixed'} '01' {'2:1'} default {'3:1'}}
    if ($time -eq 'Fixed') {$qrvforeground = $qrvbackground = if ($interval -eq 'Long') {36} else {18}} else {
        $values = @{ 
            'Short' = @{ '3:1' = @(18,6); '2:1' = @(12,6); 'Equal and Fixed' = @(6,6) }
            'Long'  = @{ '3:1' = @(36,12); '2:1' = @(24,12); 'Equal and Fixed' = @(12,12) }
        }
        if ($values[$interval].ContainsKey($boost)) {$qrvforeground, $qrvbackground = $values[$interval][$boost]} else {$qrvforeground, $qrvbackground = $values[$interval]['Equal and Fixed']}
    }
	Write-Output "$i,0x$($i.ToString('X')),$interval,$time,$qrvforeground,$qrvbackground"
}
```

![](https://github.com/5Noxi/win-config/blob/main/system/images/w32ps.png?raw=true)

> [system/assets | Win32PrioritySeparation.pdf](https://github.com/5Noxi/win-config/blob/main/system/assets/Win32PrioritySeparation.pdf)

# System Responsiveness

*"Determines the percentage of CPU resources that should be guaranteed to low-priority tasks. For example, if this value is 20, then 20% of CPU resources are reserved for low-priority tasks. Note that values that are not evenly divisible by 10 are rounded down to the nearest multiple of 10. Values below 10 and above 100 are clamped to 20. A value of 100 disables MMCSS (driver returns `STATUS_SERVER_DISABLED`).*" (`mmcss.sys`)

> https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ProcThread/multimedia-class-scheduler-service.md#registry-settings

```c
DWORD = CiConfigReadDWORD(KeyHandle, 0x1C0011090LL, 100LL);

if ( DWORD - 10 > 0x5A )          // if DWORD < 10 or DWORD > 100
    v2 = 20LL;                    // fallback
else
    v2 = 10 * (DWORD / 0xA);      // round down to nearest multiple of 10

CiSystemResponsiveness = v2;

if ( CiSystemResponsiveness == 100 ) {
    WPP_SF_(WPP_GLOBAL_Control->AttachedDevice, 19LL, &WPP_350503daac883abe7be9cf63f89038d9_Traceguids);
    v0 = -1073741696;             // STATUS_SERVER_DISABLED
}
```
```c
// -1073741696 = 0xC0000080
0xC0000080 // STATUS_SERVER_DISABLED

The GUID allocation server is disabled at the moment.
```
> https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55

Calculation:
```c
CiSystemResponsiveness = 10 * (value / 10);

// Examples
< 10   -> 20   (fallback)
10-19  -> 10
20-29  -> 20
30-39  -> 30
40-49  -> 40
50-59  -> 50
60-69  -> 60
70-79  -> 70
80-89  -> 80
90-99  -> 90
== 100 -> 100  (STATUS_SERVER_DISABLED)
> 100  -> 20   (fallback)
```

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/MultiMedia.txt  
> [system/assets | sysresp-CiConfigInitialize.c](https://github.com/5Noxi/win-config/blob/main/system/assets/sysresp-CiConfigInitialize.c)  

# Disable Service Splitting

Prevents services running under `svchost.exe` from being split into separate processes, keeping all grouped services within the same instance. This simplifies process management but increases the risk of system instability and reduces service isolation.

`Windows Internals 7th Edition, Part 2` handpicked snippets (shortened):
If system physical memory, obtained via `GlobalMemoryStatusEx`, exceeds the SvcHostSplitThresholdInKB registry value (default is `3.5 GB` on client systems and `3.7 GB` on server systems), Svchost service splitting is enabled.

Service splitting is allowed only if:  
- Splitting is globally enabled
- The service is not marked as critical (i.e., it doesn't reboot the machine on failure)
- The service is hosted in `svchost.exe`
- `SvcHostSplitDisable` is not set to `1` in the service registry key

Setting `SvcHostSplitDisable` to `0` for a critical service forces it to be split, but this can lead to issues.

Get the current amount of `svchost` process instances with:
```cmd
(get-process -Name "svchost" | measure).Count
```
```
\Registry\Machine\SYSTEM\ControlSet001\Control : SvcHostDebug
\Registry\Machine\SYSTEM\ControlSet001\Control : SvcHostSplitThresholdInKB
```
`SvcHostDebug` is set to `0` by default:
```c
v1 = 0;
if ( !RegistryValueWithFallbackW && Type == 4 )
    LOBYTE(v1) = Data != 0;
return v1;
```

> [system/assets | servicesplitting-ScReadSCMConfiguration.c](https://github.com/5Noxi/win-config/blob/main/system/assets/servicesplitting-ScReadSCMConfiguration.c)  
> https://github.com/5Noxi/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf (page `467`f)  
> https://learn.microsoft.com/en-us/windows/application-management/svchost-service-refactoring  
> https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex

![](https://github.com/5Noxi/win-config/blob/main/system/images/servicesplitting1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/servicesplitting2.png?raw=true)

---

Miscellaneous notes:
```json
// "If the total physical memory is above the threshold, it enables Svchost service splitting"
"HKLM\\SYSTEM\\CurrentControlSet\\Control": {
  "SvcHostSplitThresholdInKB": { "Type": "REG_DWORD", "Data": 4294967295 }
}
```

# Kernel Values

Since many people don't yet know which values exist and what default value they have, here's a list. I used IDA, WinDbg, WinObjEx, Windows Internals E7 P1 to create it. Many applied values are defaults, some not. See documentation below for details. The applied data is sometimes pure speculation.

> https://github.com/5Noxi/windows-books/releases  
> https://github.com/hfiref0x/WinObjEx64  
> https://github.com/5Noxi/sym-mem-dump  
> https://github.com/5Noxi/wpr-reg-records#kernel-values  

---

See [session-manager-symbols](https://github.com/5Noxi/wpr-reg-records/blob/main/session-manager-values.txt) for reference.

Everything listed below is based on personal research. Mistakes may exist, but I don't think I've made any.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
    "AdjustDpcThreshold"; = 20; // KiAdjustDpcThreshold
    "AlwaysTrackIoBoosting"; = 0; // PspAlwaysTrackIoBoosting
    "AmdTprLowerInterruptDelayConfig"; = 0; // KiAmdTprLowerInterruptDelayConfig
    "BoostingPeriodMultiplier"; = 3; // KiNormalPriorityBoostingPeriodMultiplier
    "BugCheckUnexpectedInterrupts"; = 0; // KiBugCheckUnexpectedInterrupts
    "CacheAwareScheduling"; = 47; // KiCacheAwareScheduling
    "CacheErrataOverride"; = 0; // KiTLBCOverride
    "CacheIsoBitmap"; = 0; // KiCacheIsoBitmap
    "DebuggerIsStallOwner"; = 0; // KiDebuggerIsStallOwner
    "DebugPollInterval"; = 2000; // KiDebugPollInterval
    "DefaultDynamicHeteroCpuPolicy"; = 3; // (policy enum only)
    // Behavior of Dynamic hetero policy All (0) (all available) Large (1) LargeOrIdle (2) Small (3) SmallOrIdle (4) Dynamic (5) (use priority and other metrics to decide) BiasedSmall (6) (use priority and other metrics, but prefer small) BiasedLarge (7).
    "DefaultHeteroCpuPolicy"; = 5; // KiDefaultHeteroCpuPolicy
    "DeviceOwnerProtectionDowngradeAllowed"; = 0; // SeDeviceOwnerProtectionDowngradeAllowed
    "DisableControlFlowGuardExportSuppression"; = 0; // PspDisableControlFlowGuardExportSuppression
    "DisableExceptionChainValidation"; = 2; // PspSehValidationPolicy
    "DisableLightWeightSuspend"; = 0; // KiDisableLightWeightSuspend
    "DisableLowQosTimerResolution"; = 1; // KeDisableLowQosTimerResolution
    "DisablePointerParameterAlignmentValidation"; = 0; // KiDisablePointerParameterAlignmentValidation
    "DisableTsx"; = 0; // KiDisableTsx
    "DpcCumulativeSoftTimeout"; = 120000; // KeDpcCumulativeSoftTimeoutMs
    "DpcQueueDepth"; = 4; // KiMaximumDpcQueueDepth
    "DpcSoftTimeout"; = 20000; // KeDpcSoftTimeoutMs
    "DPCTimeout"; = 20000; // KeDpcTimeoutMs
    "DpcWatchdogPeriod"; = 120000; // KeDpcWatchdogPeriodMs
    "DpcWatchdogProfileBufferSizeBytes"; = 266240; // KeDpcWatchdogProfileBufferSizeBytes
    "DpcWatchdogProfileCumulativeDpcThreshold"; = 110000; // KeDpcWatchdogProfileCumulativeDpcThresholdMs
    "DpcWatchdogProfileOffset"; = 10000; // KeDpcWatchdogProfileOffsetMs
    "DpcWatchdogProfileSingleDpcThreshold"; = 18333; // KeDpcWatchdogProfileSingleDpcThresholdMs
    "DriveRemappingMitigation"; = 1; // ObpDriveRemappingMitigation
    "DynamicHeteroCpuPolicyExpectedRuntime"; = 5200; // KiDynamicHeteroCpuPolicyExpectedRuntime
    "DynamicHeteroCpuPolicyImportant"; = 2; // (LargeOrIdle)
    // Policy for a dynamic thread that is deemed important.
    "DynamicHeteroCpuPolicyImportantPriority"; = 8; // KiDynamicHeteroCpuPolicyImportantPriority
    // Priority above which threads are considered important if prioritybased dynamic policy is chosen.
    "DynamicHeteroCpuPolicyImportantShort"; = 3; // (Small)
    // Policy for dynamic thread that is deemed important but run a short amount of time.
    "DynamicHeteroCpuPolicyMask"; = 7; //  (foreground status = 1, priority = 2, expected run time = 4)
    // Determine what is considered in assessing whether a thread is important.
    "EnablePerCpuClockTickScheduling"; = 0; // KiEnableClockTimerPerCpuTickScheduling
    "EnableTickAccumulationFromAccountingPeriods"; = 0; // KiEnableTickAccumulationFromAccountingPeriods
    "EnableWerUserReporting"; = 1; // DbgkEnableWerUserReporting
    "ForceBugcheckForDpcWatchdog"; = 0; // KiForceBugcheckForDpcWatchdog
    "ForceForegroundBoostDecay"; = 0; // KiSchedulerForegroundBoostDecayPolicy
    "ForceIdleGracePeriod"; = 5; // KiForceIdleGracePeriodInSec
    "ForceParkingRequested"; = 1; // KiForceParkingConfiguration
    "GlobalTimerResolutionRequests"; = 0; // KiGlobalTimerResolutionRequests
    "HeteroFavoredCoreFallback"; = 0; // PpmHeteroFavoredCoreFallback
    "HeteroSchedulerOptions"; = 0; // KiHeteroSchedulerOptions
    "HeteroSchedulerOptionsMask"; = 0; // KiHeteroSchedulerOptionsMask
    "HgsPlusFeedbackUpdateThresholdNetRuntime"; = 20; // dword_140FC33C0
    "HgsPlusFeedbackUpdateThresholdRuntime"; = 20; // dword_140FC33B4
    "HgsPlusHigherPerfClassFeedbackThreshold"; = 1; // dword_140FC33E0
    "HgsPlusInvalidFeedbackDefaultClass"; = 0; // dword_140FC33D4
    "HgsPlusInvalidFeedbackDefaultClassSet"; = 0; // dword_140FC33D8
    "HgsPlusInvalidFeedbackLimit"; = 50; // dword_140FC33D0
    "HgsPlusLowerPerfClassFeedbackThreshold"; = 4; // dword_140FC33DC
    "HgsPlusMinimumScoreDifferenceForSwap"; = 25; // dword_140FC33E8
    "HgsPlusThreadCreationDefaultClass"; = 0; // dword_140FC33E4
    "HotpatchTestMode"; = 0; // KeHotpatchTestMode
    "HyperStartDisabled"; = 0; // HvlVpStartDisabled
    "IdealDpcRate"; = 20; // KiIdealDpcRate
    "IdealNodeRandomized"; = 1; // PspIdealNodeRandomized
    "InterruptSteeringFlags"; = 0; // KiInterruptSteeringFlags
    "LongDpcQueueThreshold"; = 3; // KiLongDpcQueueThreshold
    "LongDpcRuntimeThreshold"; = 100; // KiLongDpcRuntimeThreshold
    "MaxDynamicTickDuration"; = 8; // KiMaxDynamicTickDurationSize
    "MaximumCooperativeIdleSearchWidth"; = 16; // KiMaximumCooperativeIdleSearchWidth
    "MaximumSharedReadyQueueSize"; = 260; // KiMaximumSharedReadyQueueSize
    "MinimumDpcRate"; = 3; // KiMinimumDpcRate
    "MitigationAuditOptions"; = 0; // PspSystemMitigationAuditOptions
    "MitigationOptions"; = 0; // PspSystemMitigationOptions
    "ObCaseInsensitive"; = 1; // ObpCaseInsensitive
    "ObObjectSecurityInheritance"; = 0; // ObpObjectSecurityInheritance
    "ObTracePermanent"; = 0; // ObpTracePermanent
    "ObTracePoolTags"; = 0; // ObpTracePoolTagsBuffer / ObpTracePoolTagsLength
    "ObTraceProcessName"; = 0; // ObpTraceProcessNameBuffer / ObpTraceProcessNameLength
    "ObUnsecureGlobalNames"; = 6619246; // ObpUnsecureGlobalNamesBuffer / ObpUnsecureGlobalNamesLength
    "PassiveWatchdogTimeout"; = 300; // KiPassiveWatchdogTimeout
    "PerfIsoEnabled"; = 0; // KiPerfIsoEnabled
    "PoCleanShutdownFlags"; = 0; // PopShutdownCleanly
    "PowerOffFrozenProcessors"; = 1; // KiPowerOffFrozenProcessors
    "ReadyTimeTicks"; = 6; // KiNormalPriorityBoostReadyTimeTicks
    "RebalanceMinPriority"; = 1; // KiRebalanceMinPriority
    "ReservedCpuSets"; = 0; // KiReservedCpuSets
    "ScanLatencyTicks"; = 7; // KiNormalPriorityBoostScanLatencyTicks
    "SchedulerAssistThreadFlagOverride"; = 0; // KiSchedulerAssistThreadFlagOverride
    "SeAllowAllApplicationAceRemoval"; = 0; // SepAllowAllApplicationAceRemoval
    "SeAllowSessionImpersonationCapability"; = 0; // SepAllowSessionImpersonationCap
    "SeCompatFlags"; = 0; // SeCompatFlags
    "SeLpacEnableWatsonReporting"; = 0; // SeLpacEnableWatsonReporting
    "SeLpacEnableWatsonThrottling"; = 1; // SeLpacEnableWatsonThrottling
    "SerializeTimerExpiration"; = 1; // KiSerializeTimerExpiration
    // This behavior is controlled by the kernel variable KiSerializeTimerExpiration, which is initialized based on a registry setting whose value is different between a server and client installation. By modifying or creating the value SerializeTimerExpiration under HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\kernel other than 0 or 1, serialization can be disabled, enabling timers to be distributed among processors. Deleting the value, or keeping it as 0, allows the kernel to make the decision based on Modern Standby availability, and setting it to 1 permanently enables serialization even on non-Modern Standby systems.
    "SeTokenDoesNotTrackSessionObject"; = 0; // SeTokenDoesNotTrackSessionObject
    "SeTokenLeakDiag"; = 0; // SeTokenLeakTracking
    "SeTokenSingletonAttributesConfig"; = 3; // SepTokenSingletonAttributesConfig
    "SplitLargeCaches"; = 0; // KiSplitLargeCaches
    "ThreadDpcEnable"; = 1; // KeThreadDpcEnable
    "ThreadReadyCount"; = 1; // KiNormalPriorityBoostMaximumThreadReadyCount
    "TimerCheckFlags"; = 1; // KeTimerCheckFlags
    "VerifierDpcScalingFactor"; = 1; // KeVerifierDpcScalingFactor
    "VirtualHeteroHysteresis"; = 4294967295; // PpmPerfQosTransitionHysteresisOverride
    "VpThreadSystemWorkPriority"; = 30; // KiVpThreadSystemWorkPriority
    "WpsSimulationOverride"; = 0; // PpmWpsSimulationOverride / PpmWpsSimulationOverrideSize
    "XStateContextLookasidePerProcMaxDepth"; = 0; // KiXStateContextLookasidePerProcMaxDepth

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\RNG";
    "RNGAuxiliarySeed"; = ; // ExpRNGAuxiliarySeed = 742978275?
```

![](https://github.com/5Noxi/win-config/blob/main/system/images/kernel0.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/kernel1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/kernel2.png?raw=true)

# DXG Kernel Values

`dxgkrnl.sys` is Windows DirectX/WDDM graphics kernel driver that mediates between apps and the GPU to schedule work, manage graphics memory, present frames, and handle TDR hang recovery.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Graphics-Drivers.txt

Many applied values are defaults, some not. See documentation below for details. The applied data is sometimes pure speculation.

---

These are default values I found in `dxgkrnl.sys`, see link below for pseudocode snippets I used / link above for all values that get read on boot.

> https://github.com/5Noxi/wpr-reg-records/blob/main/dxgkrnl.c  
> https://github.com/5Noxi/wpr-reg-records#kernel--dxg-kernel-values

Everything listed below is based on personal research. Mistakes may exist, but I don't think I've made any.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    "MiracastUseIhvDriver"; v3 = 2;
    "MiracastForceDisable"; v2 = 2;

    "ContextNoPatchMode"; v38 = 0
    "CreateGdiPrimaryOnSlaveGpu"; v48 = 0
    "CrtcPhaseFrames"; v57 = 2
    "DeadlockPulse"; v54 = 5000
    "DeadlockPulseTolerance"; v55 = 500
    "DeadlockTimeout"; v53 = 30000
    "DisableBadDriverCheckForHwProtection"; v70 = 0
    "DisableBoostedVSyncVirtualization"; v59 = 0
    "DisableGdiContextGpuVa"; v41 = 0
    "DisableIndependentVidPnVSync"; v56 = 0
    "DisableMonitoredFenceGpuVa"; v43 = 0
    "DisableMultiSourceMPOCheck"; v76 = 0
    "DisableOverlays"; v67 = 0
    "DisablePagingContextGpuVa"; v42 = 0
    "DisableSecondaryIFlipSupport"; v71 = 0
    "DriverManagesResidencyOverride"; v46 = 1
    "DriverStoreCopyMode"; v33 = 1
    "EnableBasicRenderGpuPv"; v60 = 0
    "EnableDecodeMPO"; v69 = 1
    "EnableFbrValidation"; v58 = 1
    "EnableMultiPlaneOverlay3DDIs"; v73 = 0
    "EnableOfferReclaimOnDriver"; v37 = 1
    "EnablePanelFitterSupport"; v100 = 0
    "EnableTimedCalls"; v49 = 0
    "EnableWDDM23Synchronization"; v50 = 0
    "Force32BitFences"; v68 = 0
    "ForceDirectFlip"; v66 = 0
    "ForceEnableDxgMms2"; v39 = 0
    "ForceExplicitResidencyNotification"; v44 = 0
    "ForceInitPagingProcessVaSpace"; v40 = 0
    "ForceReplicateGdiContent"; v47 = 0
    "ForceSecondaryIFlipSupport"; v72 = 0
    "ForceSecondaryMPOSupport"; v97 = 0
    "ForceSurpriseRemovalSupport"; v75 = 0
    "ForceVariableRefresh"; v52 = 0
    "GdiPhysicalAdapterIndex"; v74 = 0
    "GpuPriorityChangeMode"; v64 = 1
    "HighPriorityCompletionMode"; v63 = 1
    "InitialPagingQueueFenceValue"; v45 = 7000
    "IoMmuFlags"; v51 = 0
    "KnownProcessBoostMode"; v61 = 1
    "LeanMemoryLimit"; v122 = 1395864371
    "LeanMemoryLimit"; v123 = 16
    "NumVirtualFunctions"; v65 = 0
    "SmallQuantumMode"; v62 = 1

    "DefaultActiveIdleThreshold"; v191 = 2000;
    "DefaultD3TransitionIdleLongTimeThreshold"; v195 = 60000;
    "DefaultD3TransitionIdleShortTimeThreshold"; v193 = 10000;
    "DefaultD3TransitionIdleVeryLongTimeThreshold"; v197 = 60000;
    "DefaultD3TransitionLatencyActivelyUsed"; v192 = 80;
    "DefaultD3TransitionLatencyIdleLongTime"; v196 = 140000;
    "DefaultD3TransitionLatencyIdleMonitorOff"; v200 = 250000;
    "DefaultD3TransitionLatencyIdleNoContext"; v199 = 250000;
    "DefaultD3TransitionLatencyIdleShortTime"; v194 = 80000;
    "DefaultD3TransitionLatencyIdleVeryLongTime"; v198 = 200000;
    "DefaultExpectedResidency"; v176 = 2000;
    "DefaultIdleThresholdIdle0"; v187 = 200;
    "DefaultIdleThresholdIdle0MonitorOff"; v222 = 100;
    "DefaultLatencyToleranceIdle0"; v184 = 80;
    "DefaultLatencyToleranceIdle0MonitorOff"; v188 = 2000;
    "DefaultLatencyToleranceIdle1"; v185 = 15000;
    "DefaultLatencyToleranceIdle1MonitorOff"; v189 = 50000;
    "DefaultLatencyToleranceMemory"; v201 = 15000;
    "DefaultLatencyToleranceMemoryNoContext"; v202 = 30000;
    "DefaultLatencyToleranceNoContext"; v186 = 35000;
    "DefaultLatencyToleranceNoContextMonitorOff"; v190 = 100000;
    "DefaultLatencyToleranceOther"; v175 = -1;
    "DefaultLatencyToleranceTimerPeriod"; v183 = 200;
    "DefaultMemoryRefreshLatencyToleranceActivelyUsed"; v203 = 80;
    "DefaultMemoryRefreshLatencyToleranceIdleShortTime"; v204 = 15000;
    "DefaultMemoryRefreshLatencyToleranceMonitorOff"; v206 = 80000;
    "DefaultMemoryRefreshLatencyToleranceNoContext"; v205 = 30000;
    "DefaultPowerNotRequiredTimeout"; v209 = 25000;
    "DisableDevicePowerRequired"; v179 = 0;
    "DisablePStateManagement"; v181 = 0;
    "EnablePODebounce"; v180 = 0;
    "EnableRuntimePowerManagement"; v178 = 1;
    "lowdebounce"; v182 = 3;
    "MonitorLatencyTolerance"; v208 = 300000;
    "MonitorRefreshLatencyTolerance"; v207 = 17000;
    "uglitch"; v168 = 900;
    "uhigh"; v169 = 700;
    "uideal"; v167 = 500;
    "ulow"; v170 = 300;

    "AllowAdvancedEtwLogging"; v72 = 0;
    "DiagnosticsBufferExpansionTime"; v58 = 300;
    "EnableFuzzing"; v64 = 0;
    "EnableHMDTestMode"; v67 = 0;
    "EnableIgnoreWin32ProcessStatus"; v66 = 0;
    "ExternalDiagnosticsBufferMultiplier"; v59 = 1;
    "ExternalDiagnosticsBufferSize"; v56 = 16384;
    "ForceUsb4MonitorSupport"; g_bDbgForceUsb4MonitorSupport = 0;
    "InternalDiagnosticsBufferMultiplier"; v57 = 2;
    "InternalDiagnosticsBufferSize"; v55 = 65536;
    "InvestigationDebugParameter"; v65 = 0;
    "MaximumAdapterCount"; v60 = 32;
    "NodeUsageTelemetryTimerInterval"; v73 = v73; // ?
    "PreserveFirmwareMode"; v68 = 0;
    "PreventFullscreenWireFormatChange"; v69 = 0;
    "RapidHpdMaxChainInMilliseconds"; v71 = 0;
    "RapidHpdTimeoutInMilliseconds"; v70 = 0;
    "TerminationListSizeLimit"; v62 = 67108864;
    "TreatUsb4MonitorAsNormal"; g_bDbgTreatUsb4MonitorAsNormal = 0;
    "Usb4MonitorDpcdDP_IN_Adapter_Number"; g_DbgUsb4MonitorDpcdDP_IN_Adapter_Number = 0;
    "Usb4MonitorDpcdUSB4_Driver_ID"; g_DbgUsb4MonitorDpcdUSB4_Driver_ID = 0;
    "Usb4MonitorPowerOnDelayInSeconds"; g_DbgUsb4MonitorPowerOnDelayInSeconds = 0;
    "Usb4MonitorTargetId"; g_DbgUsb4MonitorTargetId = 0;
    "ValidateWDDMCaps"; v63 = 0;
    "WDDM2LockManagement"; v61 = 1;

    "DisableVaBackedVm"; g_VgpuDisableVaBackedVm = 0;
    "DisableVersionMismatchCheck"; v52 = 0;
    "GpuVirtualizationFlags"; v50 = (g_VgpuReplaceWarp ? 0x8 : 0x0); // bit0: CreatePVGpu=0, bit2: ForceSvm=0, bit3: ReplaceWarp=default from g_VgpuReplaceWarp ?
    "LimitNumberOfVfs"; g_LimitNumberOfVfs = 0;
    "VirtualGpuOnly"; g_VirtualGpuOnly = 0;

    "ForceBddFallbackOnly"; v35 = 0;
    "HwSchMode"; v29 = 0;
    "HwSchOverrideBlockList"; v31 = 1;
    "HwSchTreatExperimentalAsStable"; v30 = 0;
    "MiracastDefaultRtspPort"; dword_1C0153F64 = 7236;
    "PlatformSupportMiracast"; v26 = 0; // Set to 1 on LTSC IoT Enterprise 2024 by default
    "SupportMultipleIntegratedDisplays"; v28 = 0;
    "SuspendAdapterTimerPeriod"; v27 = 500000;

    "EnableExperimentalRefreshRates"; v22 = 0;
    "RapidHPDThresholdCount"; *(_DWORD*)((char*)this + 544) = 5;
    "RapidHPDTime"; v16 = 1000;

    "TdrDdiDelay"; v11 = 5;
    "TdrDebugMode"; v12 = 2;
    "TdrDelay"; v8 = 2;
    "TdrDodPresentDelay"; v9 = 2;
    "TdrDodVSyncDelay"; v10 = 2;
    "TdrLevel"; v13 = 3;
    "TdrLimitCount"; v14 = 5;
    "TdrLimitTime"; v15 = 60;

    "DRTTestEnable"; v14 = 0; // 1484026436 = Enabled ?
    "EnableAcmSupportDeveloperPreview"; v7 = 0;
    "ForceEnableDWMClone"; v82 = 0
    "HybridInternalPanelOverrideEnable"; v13 = 0
    "IsInternalRelease"; v44 = 0
    "MultiMonSupport"; v39 = 1;
    "OutputDuplicationSessionApplicationLimit"; v14 = 4
    "TdrTestMode"; v14 = 0
    "UnsupportedMonitorModesAllowed"; v5 = 0;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Power";
    "UseSelfRefreshVRAMInS3"; v166 = 1;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\BasicDisplay";
    "BasicDisplayUserNotified"; v2 = 0;

    "DisableBasicDisplayFallback"; v33 = -1;
    "EnableBasicDisplayFallback"; v32 = -1;
    "ForcePreserveBootDisplay"; v34 = 0;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Smm";
    "DebugMode"; v11 = 0;
    "EnablePageTracking"; v8 = 0;
    "ForceDmaRemapping"; v9 = 0;
    "ForceEnableIommu"; v3 = 0;
    "IdentityMappedPassthrough"; v7 = 0;
    "LogicalAddressMode"; v4 = 0;
    "PreferHighLogicalAddresses"; v10 = 0;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    "AssertOnDdiViolation"; g_DmmAssertOnDdiViolation = 0;
    "BadMonitorModeDiag"; v17 = 2;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    "EnableVirtualRefreshRateOnExternalMonitor"; *((_DWORD*)this + 134) = 0;
    "HPDFilterLimit"; *((_DWORD*)this + 133) = 20000000;
    "LongLinkTrainingTimeout"; *((_DWORD*)this + 132) = 1000;
    "ModeListCaching"; v81 = 1;
    "SetTimingsFlags"; *((_DWORD*)this + 130) = 0;
    "ShortLinkTrainingTimeout"; *((_DWORD*)this + 131) = 200;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Validation";
    "FailEscapeDDI"; v8 = 0
    "FailRenderDDI"; v9 = 0
    "FailReserveGPUVA"; v10 = 0
    "Level"; v7 = 0
    "ReportVirtualMachine"; v11 = 0

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\MonitorDataStore\\MONITOR-ID"
    "AdvancedColorEnabled"; v3 = 0;
    "AutoColorManagementEnabled"; v8 = 0;
    "EnableIntegratedPanelAcmByDefault"; v6 = 0;
    "EnableIntegratedPanelHdrByDefault"; v4 = 0;
    "HDREnabled"; v2 = 0;
    "MicrosoftApprovedAcmSupport"; v5 = 0;

"<PnPDeviceKey>\\DxgkSettings";
    "UseSelfRefreshVRAMInS3"; v166 = 1;

"<PnPDeviceKey>";
    "EnableVirtualTopologySupport"; v84 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : EnableVirtualTopologySupport
    "NeedToSuspendVidSchBeforeSetGammaRamp"; v83 = (AdapterBuild < 8704 ? 1 : 0)
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : NeedToSuspendVidSchBeforeSetGammaRamp
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : NeedToSuspendVidSchBeforeSetGammaRamp

    "DisableNonPOSTDevice"; v40 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : DisableNonPOSTDevice
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicRender : DisableNonPOSTDevice

    "Device PnP";
    "ACGSupported"; v165 = 0
    // Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : ACGSupported
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicRender : ACGSupported
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : ACGSupported
    "DxgkGpuVaIommuRequired"; v166 = 0
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : DxgkGpuVaIommuRequired
    "DxgkGpuVaIommuGlobalSupported"; v167 = 0
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : DxgkGpuVaIommuGlobalSupported

    "AllowUnspecifiedVSync"; v18 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : AllowUnspecifiedHSync
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : AllowUnspecifiedHSync
    "AllowUnspecifiedHSync"; v19 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : AllowUnspecifiedHSync
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : AllowUnspecifiedHSync
    "AllowUnspecifiedPixelRate"; v20 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : AllowUnspecifiedPixelRate
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : AllowUnspecifiedPixelRate
    "ForceDualViewBehavior"; v21 = 0;
    // \Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\0000 : ForceDualViewBehavior
    // \Registry\Machine\SYSTEM\ControlSet001\Services\BasicDisplay : ForceDualViewBehavior
```

# DWM Values

This option currently includes some speculations and default values. I haven't had time yet to test the behavior of the changed data.

---

See [dwm.c](https://github.com/5Noxi/wpr-reg-records/blob/main/assets/dwm.c) for used snippets (taken from `dwmcore.dll`, `win32full.sys`, `dwm.exe`, `dwminit.dll`, `uDWM.dll`).

Everything listed below is based on personal research. Mistakes may exist, but I don't think I've made any.

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm";
    "BlackOutAllReadback"; = 0;
    "ConfigureInput"; = 1;
    "CpuClipAASinkEnableIntermediates"; = 1;
    "CpuClipAASinkEnableOcclusion"; = 1;
    "CpuClipAASinkEnableRender"; = 1;
    "CpuClipAreaThreshold"; = 20000;
    "CpuClipWarpPartitionThreshold"; = 1024;
    "DisableDrawListCaching"; = 0;
    "DisableProjectedShadows"; = 0;
    "DisplayChangeTimeoutMs"; = 1000;
    "EnableBackdropBlurCaching"; = 1;
    "EnableCommonSuperSets"; = 1;
    "EnableCpuClipping"; = 1;
    "EnableDDisplayScanoutCaching"; = 1;
    "EnableEffectCaching"; = 1;
    "EnableFrontBufferRenderChecks"; = 1;
    "EnableMegaRects"; = 1;
    "EnablePrimitiveReordering"; = 1;
    "ForceFullDirtyRendering"; = 0;
    "GammaBlendPencil"; = 1;
    "GammaBlendWithFP16"; = 1;
    "InkGPUAccelOverrideVendorWhitelist"; = 0;
    "LayerClippingMode"; = 2;
    "LogExpressionPerfStats"; = 0;
    "MajorityScreenTest_MinArea"; = 80;
    "MajorityScreenTest_MinLength"; = 80;
    "MaxD3DFeatureLevel"; = 0;
    "MegaRectSearchCount"; = 100;
    "MegaRectSize"; = 100000;
    "MousewheelAnimationDurationMs"; = 250;
    "MousewheelScrollingMode"; = 0;
    "OptimizeForDirtyExpressions"; = 1;
    "OverlayMinFPS"; = 15; // If this value is present and set to zero, the Desktop Window Manager disables its minimum frame rate requirement for assigning DirectX swap chains to overlay planes in hardware that supports overlays. This makes it more likely that a low frame rate swap chain will get assigned and stay assigned to an overlay plane, if available. (https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/dwm/registry-values.md)
    "RenderThreadTimeoutMilliseconds"; = 5000;
    "SuperWetExtensionTimeMicroseconds"; = 1000;
    "TelemetryFramesReportPeriodMilliseconds"; = 300000;
    "TelemetryFramesSequenceIdleIntervalMilliseconds"; = 1000;
    "TelemetryFramesSequenceMaximumPeriodMilliseconds"; = 1000;
    "UniformSpaceDpiMode"; = 1;
    "UseFastestMonitorAsPrimary"; = 0;
    "vBlankWaitTimeoutMonitorOffMs"; = 250;
    "WarpEnableDebugColor"; = 0;

    "BackdropBlurCachingThrottleMs"; = 25; // 25ms if missing, clamped to <=1000ms when present?
    "CompositorClockPolicy"; = 1; // range: 0-1
    "CpuClipFlatteningTolerance"; = 0; // scaled /1000
    "CustomRefreshRateMode"; = 0; // range: 0-2
    "DisableAdvancedDirectFlip"; = 0;
    "DisableIndependentFlip"; = 0;
    "DisableProjectedShadowsRendering"; = 0;
    "FlattenVirtualSurfaceEffectInput"; = 0;
    "ForceEffectMode"; = 0; // range: 0-2
    "FrameCounterPosition"; = 0;
    "InteractionOutputPredictionDisabled"; = 0;
    "OverlayTestMode"; = 0; // 5 = MPO disabled
    "ParallelModePolicy"; = 1; // >=3 coerced to 1
    "ParallelModeRateThreshold"; = 119; // divisor for g_qpcFrequency, missing key defaults to 119 Hz (units: Hz)? 0 disables
    "ResampleInLinearSpace"; = 0;
    "ResampleModeOverride"; = 0;
    "SDRBoostPercentOverride"; = 0; // scaled /100
    "ShowDirtyRegions"; = 0;

    "AnimationsShiftKey"; = 0;
    "DisableLockingMemory"; = 0;
    "ModeChangeCurtainUseDebugColor"; = 0;
    "UseDPIScaling"; = 1;

    "ChildWindowDpiIsolation"; = 1; // range: 0-1
    "DisableDeviceBitmaps"; = 0; // range: 0-1
    "EnableResizeOptimization"; = 0; // range: 0-1
    "ResizeTimeoutGdi"; = 0; // range: 0-0xFFFFFFFF (ms)
    "ResizeTimeoutModern"; = 0; // range: 0-0xFFFFFFFF (ms)

    "DefaultColorizationColorState"; = 0;
    "DisallowAnimations"; = 0;
    "DisallowColorizationColorChanges"; = 0;

    "DisableSessionTermination"; = 0; // range: 0–1
    "ForceBasicDisplayAdapterOnDWMRestart"; = 0; // range: 0–1
    "OneCoreNoBootDWM"; = 0; // range: 0–1

    "DisableHologramCompositor"; = 0; // range: 0–1


"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\Scene";
    "EnableBloom"; = 0;
    "EnableDrawToBackbuffer"; = 1;
    "EnableImageProcessing"; = 1;
    "ImageProcessingResizeGrowth"; = 200;
    "MsaaQualityMode"; = 2;
    "SceneVisualCutoffCountOfConsecutiveIncidentsAllowed"; = 5;
    "SceneVisualCutoffThresholdInMS"; = 1000;

    "ForceNonPrimaryDisplayAdapter"; = 0;
    "ImageProcessingResizeThreshold"; = 0; // scaled /100

"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\GpuAccelInkTiming";
    "ExtensionTimeMicroseconds"; = 1000;
    "PeriodicFenceMinDifferenceMicroseconds"; = 500;
    "RefreshRatePercentage"; = 10;
```

> https://github.com/5Noxi/wpr-reg-records#dwm-values

# Disable Scheduled Tasks

Disables all kind of scheduled tasks most users don't need. Read through the list before switching the option. See suboptions for customization - enabling all suboptions until `Disable Miscellaenous Tasks` is the same as enabling the option switch.

Currently disables:
```powershell
"\Microsoft\Windows\Application Experience\MareBackup",
"\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser",
"\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser Exp",
"\Microsoft\Windows\Application Experience\StartupAppTask",
"\Microsoft\Windows\ApplicationData\DsSvcCleanup",
"\Microsoft\Windows\Autochk\Proxy",
"\Microsoft\Windows\CloudExperienceHost\CreateObjectTask",
"\Microsoft\Windows\Customer Experience Improvement Program\Consolidator",
"\Microsoft\Windows\Customer Experience Improvement Program\UsbCeip",
"\Microsoft\Windows\Defrag\ScheduledDefrag",
"\Microsoft\Windows\Diagnosis\RecommendedTroubleshootingScanner",
"\Microsoft\Windows\Diagnosis\Scheduled",
"\Microsoft\Windows\Diagnosis\UnexpectedCodePath",
"\Microsoft\Windows\DiskCleanup\SilentCleanup",
"\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticDataCollector",
"\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticResolver",
"\Microsoft\Windows\DiskFootprint\Diagnostics",
"\Microsoft\Windows\DiskFootprint\StorageSense",
"\Microsoft\Windows\Feedback\Siuf\DmClient",
"\Microsoft\Windows\Feedback\Siuf\DmClientOnScenarioDownload",
"\Microsoft\Windows\InstallService\ScanForUpdates",
"\Microsoft\Windows\InstallService\ScanForUpdatesAsUser",
"\Microsoft\Windows\InstallService\SmartRetry",
"\Microsoft\Windows\InstallService\WakeUpAndContinueUpdates",
"\Microsoft\Windows\InstallService\WakeUpAndScanForUpdates",
"\Microsoft\Windows\International\Synchronize Language Settings",
"\Microsoft\Windows\LanguageComponentsInstaller\Installation",
"\Microsoft\Windows\LanguageComponentsInstaller\ReconcileLanguageResources",
"\Microsoft\Windows\LanguageComponentsInstaller\Uninstallation",
"\Microsoft\Windows\Maps\MapsUpdateTask",
"\Microsoft\Windows\Power Efficiency Diagnostics\AnalyzeSystem",
"\Microsoft\Windows\Registry\RegIdleBackup",
"\Microsoft\Windows\RetailDemo\CleanupOfflineContent",
"\Microsoft\Windows\Speech\SpeechModelDownloadTask",
"\Microsoft\Windows\Sysmain\ResPriStaticDbSync",
"\Microsoft\Windows\Sysmain\WsSwapAssessmentTask",
"\Microsoft\Windows\Time Synchronization\ForceSynchronizeTime",
"\Microsoft\Windows\Time Synchronization\SynchronizeTime",
"\Microsoft\Windows\UNP\RunUpdateNotificationMgr",
"\Microsoft\Windows\Windows Error Reporting\QueueReporting",
```

---

Miscellaneous notes:
```powershell
for %%a in (
    "\Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 64 Critica",
    "\Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 64",
    "\Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 Critica",
    "\Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319",
    "\Microsoft\Windows\Active Directory Rights Management Services Client\AD RMS Rights Policy Template Management (Manual)",
    "\Microsoft\Windows\AppID\EDP Policy Manager",
    "\Microsoft\Windows\BrokerInfrastructure\BgTaskRegistrationMaintenanceTask",
    "\Microsoft\Windows\CloudRestore\Backup",
    "\Microsoft\Windows\CloudRestore\Restore",
    "\Microsoft\Windows\Data Integrity Scan\Data Integrity Check And Scan",
    "\Microsoft\Windows\Data Integrity Scan\Data Integrity Scan",
    "\Microsoft\Windows\Data Integrity Scan\Data Integrity Scan For Crash Recovery",
    "\Microsoft\Windows\Device Setup\Metadata Refresh",
    "\Microsoft\Windows\FileHistory\File History (maintenance mode)",
    "\Microsoft\Windows\Flighting\FeatureConfig\BootstrapUsageDataReporting",
    "\Microsoft\Windows\Flighting\FeatureConfig\ReconcileFeatures",
    "\Microsoft\Windows\Flighting\FeatureConfig\UsageDataFlushing",
    "\Microsoft\Windows\Flighting\FeatureConfig\UsageDataReceiver",
    "\Microsoft\Windows\Flighting\FeatureConfig\UsageDataReporting",
    "\Microsoft\Windows\Flighting\OneSettings\RefreshCache",
    "\Microsoft\Windows\Security\Pwdless\IntelligentPwdlessTask",

) do (
    schtasks.exe /change /disable /TN %%a
)

powershell -Command "Get-ScheduledTask -TaskPath '\' | Where-Object { $_.TaskName -like 'MicrosoftEdgeUpdateTaskMachine*' } | ForEach-Object { Disable-ScheduledTask -TaskName $_.TaskName -TaskPath '\' }"
```

# Disable Services/Drivers

The main option doesn't apply all suboptions. For further custumization use [serviwin](https://www.nirsoft.net/utils/serviwin.html).

The suboptions probably overlap the documentation. If so, you can open the markdown file on my GitHub instead:
> https://github.com/5Noxi/win-config/blob/main/system/desc.md#disable-servicesdrivers

See [services](https://github.com/5Noxi/win-config/blob/main/system/assets/services.txt)/[drivers](https://github.com/5Noxi/win-config/blob/main/system/assets/drivers.txt) for reference, these files were generated on a stock `W11 IoT Enterprise LTSC` installation via [serviwin](https://www.nirsoft.net/utils/serviwin.html).

| Option Name | Service/Driver | Description |
| --- | --- | --- |
| Activity Moderation | `bam` | Controls activity of background applications |
|  | `dam` | Controls activity of desktop applications |
| Autplay | `ShellHWDetection` | Provides notifications for AutoPlay hardware events. |
| Beep | `Beep` | - |
| Biometrics | `WbioSrvc` | The Windows biometric service gives client applications the ability to capture, compare, manipulate, and store biometric data without gaining direct access to any biometric hardware or samples. The service is hosted in a privileged SVCHOST process. |
| Bluetooth | `BTAGService` | Service supporting the audio gateway role of the Bluetooth Handsfree Profile. |
|  | `BthA2dp` | Microsoft Bluetooth A2dp driver |
|  | `BthAvctpSvc` | This is Audio Video Control Transport Protocol service |
|  | `BthEnum` | Bluetooth Enumerator Service |
|  | `BthHFEnum` | Microsoft Bluetooth Hands-Free Profile driver |
|  | `BthLEEnum` | Bluetooth Low Energy Driver |
|  | `BthMini` | Bluetooth Radio Driver |
|  | `BTHMODEM` | Bluetooth Modem Communications Driver |
|  | `BTHPORT` | Bluetooth Port Driver |
|  | `bthserv` | The Bluetooth service supports discovery and association of remote Bluetooth devices. Stopping or disabling this service may cause already installed Bluetooth devices to fail to operate properly and prevent new devices from being discovered or associated. |
|  | `BTHUSB` | Bluetooth Radio USB Driver |
|  | `DeviceAssociationBrokerSvc` | Enables apps to pair devices |
|  | `DeviceAssociationService` | Enables pairing between the system and wired or wireless devices. |
| Broadcasts | `BcastDVRUserService` | This user service is used for Game Recordings and Live Broadcasts |
| Camera | `FrameServer` | Enables multiple clients to access video frames from camera devices. |
|  | `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. |
| CDROM | `cdrom` | CD-ROM Driver |
| Clipboard | `cbdhsvc` | This user service is used for Clipboard scenarios |
| Device Setup Manager | `DsmSvc` | Enables the detection, download and installation of device-related software. If this service is disabled, devices may be configured with outdated software, and may not work correctly. |
| DHCP | `Dhcp` | Registers and updates IP addresses and DNS records for this computer. If this service is stopped, this computer will not receive dynamic IP addresses and DNS updates. If this service is disabled, any services that explicitly depend on it will fail to start. |
| Diagnostics | `DusmSvc` | Network data usage, data limit, restrict background data, metered networks. |
|  | `DPS` | The Diagnostic Policy Service enables problem detection, troubleshooting and resolution for Windows components. If this service is stopped, diagnostics will no longer function. |
|  | `diagsvc` | Executes diagnostic actions for troubleshooting support |
|  | `WdiServiceHost` | The Diagnostic Service Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local Service context. If this service is stopped, any diagnostics that depend on it will no longer function. |
|  | `WdiSystemHost` | The Diagnostic System Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local System context. If this service is stopped, any diagnostics that depend on it will no longer function. |
|  | `TroubleshootingSvc` | Enables automatic mitigation for known problems by applying recommended troubleshooting. If stopped, your device will not get recommended troubleshooting for problems on your device. |
|  | `Ndu` | This service provides network data usage monitoring functionality |
| Edge | `MicrosoftEdgeElevationService` | - |
|  | `edgeupdate` | - |
|  | `edgeupdatem` | - |
| File/Printer Sharing | `LanmanServer` | Supports file, print, and named-pipe sharing over the network for this computer. If this service is stopped, these functions will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `LanmanWorkstation` | Creates and maintains client network connections to remote servers using the SMB protocol. If this service is stopped, these connections will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
| GameInput | `GameInputSvc` | Enables keyboards, mice, gamepads, and other input devices to be used with the GameInput API. |
| HyperV | `bttflt` | Microsoft Hyper-V VHDPMEM BTT Filter |
|  | `gencounter` | Microsoft Hyper-V Generation Counter |
|  | `hvcrash` | Hyper-V Crashdump |
|  | `HvHost` | Provides an interface for the Hyper-V hypervisor to provide per-partition performance counters to the host operating system. |
|  | `hvservice` | Microsoft Hypervisor Service Driver |
|  | `hyperkbd` | Microsoft VMBus Synthetic Keyboard Driver |
|  | `HyperVideo` | Microsoft VMBus Video Device Miniport Driver |
|  | `storflt` | Microsoft Hyper-V Storage Accelerator |
|  | `Vid` | Microsoft Hyper-V Virtualization Infrastructure Driver |
|  | `vmbus` | Virtual Machine Bus |
|  | `vmgid` | Microsoft Hyper-V Guest Infrastructure Driver |
|  | `vmicguestinterface` | Provides an interface for the Hyper-V host to interact with specific services running inside the virtual machine. |
|  | `vmicheartbeat` | Monitors the state of this virtual machine by reporting a heartbeat at regular intervals. This service helps you identify running virtual machines that have stopped responding. |
|  | `vmickvpexchange` | Provides a mechanism to exchange data between the virtual machine and the operating system running on the physical computer. |
|  | `vmicrdv` | Provides a platform for communication between the virtual machine and the operating system running on the physical computer. |
|  | `vmicshutdown` | Provides a mechanism to shut down the operating system of this virtual machine from the management interfaces on the physical computer. |
|  | `vmictimesync` | Synchronizes the system time of this virtual machine with the system time of the physical computer. |
|  | `vmicvmsession` | Provides a mechanism to manage virtual machine with PowerShell via VM session without a virtual network. |
|  | `vmicvss` | Coordinates the communications that are required to use Volume Shadow Copy Service to back up applications and data on this virtual machine from the operating system on the physical computer. |
|  | `vpci` | Microsoft Hyper-V Virtual PCI Bus |
| IPv6 | `Tcpip6` | @todo.dll,-100;Microsoft IPv6 Protocol Driver |
|  | `IpxlatCfgSvc` | Configures and enables translation from v4 to v6 and vice versa |
| IP Helper | `iphlpsvc` | Provides tunnel connectivity using IPv6 transition technologies (6to4, ISATAP, Port Proxy, and Teredo), and IP-HTTPS. If this service is stopped, the computer will not have the enhanced connectivity benefits that these technologies offer. |
| Location | `lfsvc` | This service monitors the current location of the system and manages geofences (a geographical location with associated events). If you turn off this service, applications will be unable to use or receive notifications for geolocation or geofences. |
| Maps Manager | `MapsBroker` | Windows service for application access to downloaded maps. This service is started on-demand by application accessing downloaded maps. Disabling this service will prevent apps from accessing maps. |
| Network Discovery | `fdPHost` | The FDPHOST service hosts the Function Discovery (FD) network discovery providers. These FD providers supply network discovery services for the Simple Services Discovery Protocol (SSDP) and Web Services Discovery (WS-D) protocol. Stopping or disabling the FDPHOST service will disable network discovery for these protocols when using FD. When this service is unavailable, network services using FD and relying on these discovery protocols will be unable to find network devices or resources. |
|  | `FDResPub` | Publishes this computer and resources attached to this computer so they can be discovered over the network. If this service is stopped, network resources will no longer be published and they will not be discovered by other computers on the network. |
|  | `SSDPSRV` | Discovers networked devices and services that use the SSDP discovery protocol, such as UPnP devices. Also announces SSDP devices and services running on the local computer. If this service is stopped, SSDP-based devices will not be discovered. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `upnphost` | Allows UPnP devices to be hosted on this computer. If this service is stopped, any hosted UPnP devices will stop functioning and no additional hosted devices can be added. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `MsLldp` | Microsoft Link-Layer Discovery Protocol Driver |
|  | `rspndr` | Link-Layer Topology Discovery Responder |
|  | `lltdio` | Link-Layer Topology Discovery Mapper I/O Driver |
|  | `lltdsvc` | Creates a Network Map, consisting of PC and device topology (connectivity) information, and metadata describing each PC and device. If this service is disabled, the Network Map will not function properly. |
| Office | `ClickToRunSvc` | - |
| Telephony | `PhoneSvc` | Manages the telephony state on the device |
|  | `TapiSrv` | Provides Telephony API (TAPI) support for programs that control telephony devices on the local computer and, through the LAN, on servers that are also running the service. |
| Parental Control | `WpcMonSvc` | Enforces parental controls for child accounts in Windows. If this service is stopped or disabled, parental controls may not be enforced. |
| Printer | `McpManagementService` | Universal Print Management Service |
|  | `PrintDeviceConfigurationService` | The Print Device Configuration Service manages the installation of IPP and UP printers. If this service is stopped, any printer installations that are in-progress may be canceled. |
|  | `PrintNotify` | This service opens custom printer dialog boxes and handles notifications from a remote print server or a printer. If you turn off this service, you wont be able to see printer extensions or notifications. |
|  | `PrintScanBrokerService` | Provides support for secure privileged operations needed by low priv spooler. |
|  | `PrintWorkflowUserSvc` | Provides support for Print Workflow applications. If you turn off this service, you may not be able to print successfully. |
|  | `Spooler` | This service spools print jobs and handles interaction with the printer. If you turn off this service, you won't be able to print or see your printers. |
|  | `usbprint` | Microsoft USB PRINTER Class |
| Recovery / Backup | `CloudBackupRestoreSvc` | Monitors the system for changes in application and setting states and performs cloud backup and restore operations when required. |
|  | `SDRSVC` | Provides Windows Backup and Restore capabilities. |
|  | `swprv` | Manages software-based volume shadow copies taken by the Volume Shadow Copy service. If this service is stopped, software-based volume shadow copies cannot be managed. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `VSS` | Manages and implements Volume Shadow Copies used for backup and other purposes. If this service is stopped, shadow copies will be unavailable for backup and the backup may fail. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `wbengine` | The WBENGINE service is used by Windows Backup to perform backup and recovery operations. If this service is stopped by a user, it may cause the currently running backup or recovery operation to fail. Disabling this service may disable backup and recovery operations using Windows Backup on this computer. |
| Remote Desktop | `RemoteAccess` | Offers routing services to businesses in local area and wide area network environments. |
|  | `RemoteRegistry` | Enables remote users to modify registry settings on this computer. If this service is stopped, the registry can be modified only by users on this computer. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `SessionEnv` | Remote Desktop Configuration service (RDCS) is responsible for all Remote Desktop Services and Remote Desktop related configuration and session maintenance activities that require SYSTEM context. These include per-session temporary folders, RD themes, and RD certificates. |
|  | `TermService` | Allows users to connect interactively to a remote computer. Remote Desktop and Remote Desktop Session Host Server depend on this service. To prevent remote use of this computer, clear the checkboxes on the Remote tab of the System properties control panel item. |
|  | `UmRdpService` | Allows the redirection of Printers/Drives/Ports for RDP connections |
| Sensor | `SensorDataService` | Delivers data from a variety of sensors |
|  | `SensrSvc` | Monitors various sensors in order to expose data and adapt to system and user state. If this service is stopped or disabled, the display brightness will not adapt to lighting conditions. Stopping this service may affect other system functionality and features as well. |
|  | `SensorService` | A service for sensors that manages different sensors' functionality. Manages Simple Device Orientation (SDO) and History for sensors. Loads the SDO sensor that reports device orientation changes. If this service is stopped or disabled, the SDO sensor will not be loaded and so auto-rotation will not occur. History collection from Sensors will also be stopped. |
| Sign-In Assistant | `wlidsvc` | Enables user sign-in through Microsoft account identity services. If this service is stopped, users will not be able to logon to the computer with their Microsoft account. |
| Smart Card | `CertPropSvc` | Copies user certificates and root certificates from smart cards into the current user's certificate store, detects when a smart card is inserted into a smart card reader, and, if needed, installs the smart card Plug and Play minidriver. |
|  | `SCardSvr` | Manages access to smart cards read by this computer. If this service is stopped, this computer will be unable to read smart cards. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `ScDeviceEnum` | Creates software device nodes for all smart card readers accessible to a given session. If this service is disabled, WinRT APIs will not be able to enumerate smart card readers. |
|  | `SCPolicySvc` | Allows the system to be configured to lock the user desktop upon smart card removal. |
|  | `scfilter` | Smart card reader filter driver enabling smart card PnP. |
| SysMain | `SysMain` | Maintains and improves system performance over time. |
| Microsoft Store | `AppXSvc` | Provides infrastructure support for deploying Store applications. This service is started on demand and if disabled Store applications will not be deployed to the system, and may not function properly. |
|  | `camsvc` | Provides facilities for managing UWP apps access to app capabilities as well as checking an app's access to specific app capabilities |
|  | `ClipSVC` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled applications bought using the Microsoft Store will not behave correctly. |
|  | `InstallService` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then installations will not function properly. |
|  | `LicenseManager` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then content acquired through the Microsoft Store will not function properly. |
|  | `PushToInstall` | Provides infrastructure support for the Microsoft Store. This service is started automatically and if disabled then remote installations will not function properly. |
| TCP/IP NetBIOS Helper | `lmhosts` | Provides support for the NetBIOS over TCP/IP (NetBT) service and NetBIOS name resolution for clients on the network, therefore enabling users to share files, print, and log on to the network. If this service is stopped, these functions might be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
| Telemetry | `DiagTrack` | The Connected User Experiences and Telemetry service enables features that support in-application and connected user experiences. Additionally, this service manages the event driven collection and transmission of diagnostic and usage information (used to improve the experience and quality of the Windows Platform) when the diagnostics and usage privacy option settings are enabled under Feedback and Diagnostics. |
|  | `dmwappushservice` | Routes Wireless Application Protocol (WAP) Push messages received by the device and synchronizes Device Management sessions |
|  | `InventorySvc` | This service performs background system inventory, compatibility appraisal, and maintenance used by numerous system components. |
|  | `PcaSvc` | This service provides support for the Program Compatibility Assistant (PCA). PCA monitors programs installed and run by the user and detects known compatibility problems. If this service is stopped, PCA will not function properly. |
|  | `wuqisvc` | - |
| Themes | `Themes` | Provides user experience theme management. |
| Time | `W32Time` | Maintains date and time synchronization on all clients and servers in the network. If this service is stopped, date and time synchronization will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
|  | `autotimesvc` | This service sets time based on NITZ messages from a Mobile Network |
|  | `tzautoupdate` | Automatically sets the system time zone. |
| UAC | `luafv` | Virtualizes file write failures to per-user locations. |
| User Data & Sync Platform | `UnistoreSvc` | Handles storage of structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. |
|  | `UserDataSvc` | Provides apps access to structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. |
| WER | `WerSvc` | Allows errors to be reported when programs stop working or responding and allows existing solutions to be delivered. Also allows logs to be generated for diagnostic and repair services. If this service is stopped, error reporting might not work correctly and results of diagnostic services and repairs might not be displayed. |
|  | `wercplsupport` | This service provides support for viewing, sending and deletion of system-level problem reports for the Problem Reports control panel. |
| Wi-Fi | `WlanSvc` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. |
|  | `vwififlt` | Virtual WiFi Filter Driver |
| Windows Insider | `wisvc` | Provides infrastructure support for the Windows Insider Program. This service must remain enabled for the Windows Insider Program to work. |
| Windows Search | `WSearch` | Provides content indexing, property caching, and search results for files, e-mail, and other content. |
| Windows Update | `WaaSMedicSvc` | Repairs damaged Windows Update components so that the computer can keep getting updates. |
|  | `UsoSvc` | Manages Windows Updates. If stopped, your devices will not be able to download and install the latest updates. |
|  | `wuauserv` | Enables the detection, download, and installation of updates for Windows and other programs. If this service is disabled, users of this computer will not be able to use Windows Update or its automatic updating feature, and programs will not be able to use the Windows Update Agent (WUA) API. |
| Xbox | `XboxGipSvc` | This service manages connected Xbox Accessories. |
|  | `xboxgip` | Xbox Game Input Protocol Driver |
|  | `XblAuthManager` | Provides authentication and authorization services for interacting with Xbox Live. If this service is stopped, some applications may not operate correctly. |
|  | `XblGameSave` | This service syncs save data for Xbox Live save enabled games. If this service is stopped, game save data will not upload to or download from Xbox Live. |
|  | `XboxNetApiSvc` | This service supports the Windows.Networking.XboxLive application programming interface. |
| Miscellaneous | `WalletService` | Hosts objects used by clients of the wallet |
|  | `PenService` | Part of Windows Ink Services Platform Tablet Input Subsystem and is used to implement Microsoft Tablet PC functionality.  |
|  | `buttonconverter` | Service for Portable Device Control devices |

# Time Zone

| ID                              | Display Name                                                  | ID                              | Display Name                                              |
| ------------------------------- | ------------------------------------------------------------- | ------------------------------- | --------------------------------------------------------- |
| Afghanistan Standard Time       | (UTC+04:30) Kabul                                             | Alaskan Standard Time           | (UTC-09:00) Alaska                                        |
| Aleutian Standard Time          | (UTC-10:00) Aleutian Islands                                  | Altai Standard Time             | (UTC+07:00) Barnaul, Gorno-Altaysk                        |
| Arab Standard Time              | (UTC+03:00) Kuwait, Riyadh                                    | Arabian Standard Time           | (UTC+04:00) Abu Dhabi, Muscat                             |
| Arabic Standard Time            | (UTC+03:00) Baghdad                                           | Argentina Standard Time         | (UTC-03:00) City of Buenos Aires                          |
| Astrakhan Standard Time         | (UTC+04:00) Astrakhan, Ulyanovsk                              | Atlantic Standard Time          | (UTC-04:00) Atlantic Time (Canada)                        |
| AUS Central Standard Time       | (UTC+09:30) Darwin                                            | Aus Central W. Standard Time    | (UTC+08:45) Eucla                                         |
| AUS Eastern Standard Time       | (UTC+10:00) Canberra, Melbourne, Sydney                       | Azerbaijan Standard Time        | (UTC+04:00) Baku                                          |
| Azores Standard Time            | (UTC-01:00) Azores                                            | Bahia Standard Time             | (UTC-03:00) Salvador                                      |
| Bangladesh Standard Time        | (UTC+06:00) Dhaka                                             | Belarus Standard Time           | (UTC+03:00) Minsk                                         |
| Bougainville Standard Time      | (UTC+11:00) Bougainville Island                               | Canada Central Standard Time    | (UTC-06:00) Saskatchewan                                  |
| Cape Verde Standard Time        | (UTC-01:00) Cabo Verde Is.                                    | Caucasus Standard Time          | (UTC+04:00) Yerevan                                       |
| Cen. Australia Standard Time    | (UTC+09:30) Adelaide                                          | Central America Standard Time   | (UTC-06:00) Central America                               |
| Central Asia Standard Time      | (UTC+06:00) Nur-Sultan                                        | Central Brazilian Standard Time | (UTC-04:00) Cuiaba                                        |
| Central Europe Standard Time    | (UTC+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague | Central European Standard Time  | (UTC+01:00) Sarajevo, Skopje, Warsaw, Zagreb              |
| Central Pacific Standard Time   | (UTC+11:00) Solomon Is., New Caledonia                        | Central Standard Time           | (UTC-06:00) Central Time (US & Canada)                    |
| Central Standard Time (Mexico)  | (UTC-06:00) Guadalajara, Mexico City, Monterrey               | Chatham Islands Standard Time   | (UTC+12:45) Chatham Islands                               |
| China Standard Time             | (UTC+08:00) Beijing, Chongqing, Hong Kong, Urumqi             | Cuba Standard Time              | (UTC-05:00) Havana                                        |
| Dateline Standard Time          | (UTC-12:00) International Date Line West                      | E. Africa Standard Time         | (UTC+03:00) Nairobi                                       |
| E. Australia Standard Time      | (UTC+10:00) Brisbane                                          | E. Europe Standard Time         | (UTC+02:00) Chisinau                                      |
| E. South America Standard Time  | (UTC-03:00) Brasilia                                          | Easter Island Standard Time     | (UTC-06:00) Easter Island                                 |
| Eastern Standard Time           | (UTC-05:00) Eastern Time (US & Canada)                        | Eastern Standard Time (Mexico)  | (UTC-05:00) Chetumal                                      |
| Egypt Standard Time             | (UTC+02:00) Cairo                                             | Ekaterinburg Standard Time      | (UTC+05:00) Ekaterinburg                                  |
| Fiji Standard Time              | (UTC+12:00) Fiji                                              | FLE Standard Time               | (UTC+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius |
| Georgian Standard Time          | (UTC+04:00) Tbilisi                                           | GMT Standard Time               | (UTC+00:00) Dublin, Edinburgh, Lisbon, London             |
| Greenland Standard Time         | (UTC-02:00) Greenland                                         | Greenwich Standard Time         | (UTC+00:00) Monrovia, Reykjavik                           |
| GTB Standard Time               | (UTC+02:00) Athens, Bucharest                                 | Haiti Standard Time             | (UTC-05:00) Haiti                                         |
| Hawaiian Standard Time          | (UTC-10:00) Hawaii                                            | India Standard Time             | (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi           |
| Iran Standard Time              | (UTC+03:30) Tehran                                            | Israel Standard Time            | (UTC+02:00) Jerusalem                                     |
| Jordan Standard Time            | (UTC+03:00) Amman                                             | Kaliningrad Standard Time       | (UTC+02:00) Kaliningrad                                   |
| Kamchatka Standard Time         | (UTC+12:00) Petropavlovsk-Kamchatsky - Old                    | Korea Standard Time             | (UTC+09:00) Seoul                                         |
| Libya Standard Time             | (UTC+02:00) Tripoli                                           | Line Islands Standard Time      | (UTC+14:00) Kiritimati Island                             |
| Lord Howe Standard Time         | (UTC+10:30) Lord Howe Island                                  | Magadan Standard Time           | (UTC+11:00) Magadan                                       |
| Magallanes Standard Time        | (UTC-03:00) Punta Arenas                                      | Marquesas Standard Time         | (UTC-09:30) Marquesas Islands                             |
| Mauritius Standard Time         | (UTC+04:00) Port Louis                                        | Mid-Atlantic Standard Time      | (UTC-02:00) Mid-Atlantic - Old                            |
| Middle East Standard Time       | (UTC+02:00) Beirut                                            | Montevideo Standard Time        | (UTC-03:00) Montevideo                                    |
| Morocco Standard Time           | (UTC+01:00) Casablanca                                        | Mountain Standard Time          | (UTC-07:00) Mountain Time (US & Canada)                   |
| Mountain Standard Time (Mexico) | (UTC-07:00) La Paz, Mazatlan                                  | Myanmar Standard Time           | (UTC+06:30) Yangon (Rangoon)                              |
| N. Central Asia Standard Time   | (UTC+07:00) Novosibirsk                                       | Namibia Standard Time           | (UTC+02:00) Windhoek                                      |
| Nepal Standard Time             | (UTC+05:45) Kathmandu                                         | New Zealand Standard Time       | (UTC+12:00) Auckland, Wellington                          |
| Newfoundland Standard Time      | (UTC-03:30) Newfoundland                                      | Norfolk Standard Time           | (UTC+11:00) Norfolk Island                                |
| North Asia East Standard Time   | (UTC+08:00) Irkutsk                                           | North Asia Standard Time        | (UTC+07:00) Krasnoyarsk                                   |
| North Korea Standard Time       | (UTC+09:00) Pyongyang                                         | Omsk Standard Time              | (UTC+06:00) Omsk                                          |
| Pacific SA Standard Time        | (UTC-04:00) Santiago                                          | Pacific Standard Time           | (UTC-08:00) Pacific Time (US & Canada)                    |
| Pacific Standard Time (Mexico)  | (UTC-08:00) Baja California                                   | Pakistan Standard Time          | (UTC+05:00) Islamabad, Karachi                            |
| Paraguay Standard Time          | (UTC-04:00) Asuncion                                          | Qyzylorda Standard Time         | (UTC+05:00) Qyzylorda                                     |
| Romance Standard Time           | (UTC+01:00) Brussels, Copenhagen, Madrid, Paris               | Russia Time Zone 10             | (UTC+11:00) Chokurdakh                                    |
| Russia Time Zone 11             | (UTC+12:00) Anadyr, Petropavlovsk-Kamchatsky                  | Russia Time Zone 3              | (UTC+04:00) Izhevsk, Samara                               |
| Russian Standard Time           | (UTC+03:00) Moscow, St. Petersburg                            | SA Eastern Standard Time        | (UTC-03:00) Cayenne, Fortaleza                            |
| SA Pacific Standard Time        | (UTC-05:00) Bogota, Lima, Quito, Rio Branco                   | SA Western Standard Time        | (UTC-04:00) Georgetown, La Paz, Manaus, San Juan          |
| Sakhalin Standard Time          | (UTC+11:00) Sakhalin                                          | Saint Pierre Standard Time      | (UTC-03:00) Saint Pierre and Miquelon                     |
| Samoa Standard Time             | (UTC+13:00) Samoa                                             | Sao Tome Standard Time          | (UTC+00:00) Sao Tome                                      |
| Saratov Standard Time           | (UTC+04:00) Saratov                                           | SE Asia Standard Time           | (UTC+07:00) Bangkok, Hanoi, Jakarta                       |
| Singapore Standard Time         | (UTC+08:00) Kuala Lumpur, Singapore                           | South Africa Standard Time      | (UTC+02:00) Harare, Pretoria                              |
| South Sudan Standard Time       | (UTC+02:00) Juba                                              | Sri Lanka Standard Time         | (UTC+05:30) Sri Jayawardenepura                           |
| Sudan Standard Time             | (UTC+02:00) Khartoum                                          | Syria Standard Time             | (UTC+03:00) Damascus                                      |
| Taipei Standard Time            | (UTC+08:00) Taipei                                            | Tasmania Standard Time          | (UTC+10:00) Hobart                                        |
| Tocantins Standard Time         | (UTC-03:00) Araguaina                                         | Tokyo Standard Time             | (UTC+09:00) Osaka, Sapporo, Tokyo                         |
| Tomsk Standard Time             | (UTC+07:00) Tomsk                                             | Tonga Standard Time             | (UTC+13:00) Nuku'alofa                                    |
| Transbaikal Standard Time       | (UTC+09:00) Chita                                             | Turkey Standard Time            | (UTC+03:00) Istanbul                                      |
| Turks And Caicos Standard Time  | (UTC-05:00) Turks and Caicos                                  | Ulaanbaatar Standard Time       | (UTC+08:00) Ulaanbaatar                                   |
| US Eastern Standard Time        | (UTC-05:00) Indiana (East)                                    | US Mountain Standard Time       | (UTC-07:00) Arizona                                       |
| UTC                             | (UTC) Coordinated Universal Time                              | UTC+12                          | (UTC+12:00) Coordinated Universal Time+12                 |
| UTC+13                          | (UTC+13:00) Coordinated Universal Time+13                     | UTC-02                          | (UTC-02:00) Coordinated Universal Time-02                 |
| UTC-08                          | (UTC-08:00) Coordinated Universal Time-08                     | UTC-09                          | (UTC-09:00) Coordinated Universal Time-09                 |
| UTC-11                          | (UTC-11:00) Coordinated Universal Time-11                     | Venezuela Standard Time         | (UTC-04:00) Caracas                                       |
| Vladivostok Standard Time       | (UTC+10:00) Vladivostok                                       | Volgograd Standard Time         | (UTC+03:00) Volgograd                                     |
| W. Australia Standard Time      | (UTC+08:00) Perth                                             | W. Central Africa Standard Time | (UTC+01:00) West Central Africa                           |
| W. Europe Standard Time         | (UTC+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna  | W. Mongolia Standard Time       | (UTC+07:00) Hovd                                          |
| West Asia Standard Time         | (UTC+05:00) Ashgabat, Tashkent                                | West Bank Standard Time         | (UTC+02:00) Gaza, Hebron                                  |
| West Pacific Standard Time      | (UTC+10:00) Guam, Port Moresby                                | Yakutsk Standard Time           | (UTC+09:00) Yakutsk                                       |
| Yukon Standard Time             | (UTC-07:00) Yukon                                             |                                 |                                                           |

Get a list of available timezones with more detail via:
```powershell
Get-TimeZone -ListAvailable
```

# Enable Game Mode

Game Mode should: "Prevents Windows Update from performing driver installations and sending restart notifications" Does it work? Not really, in my experience it tends to lower the priority and prevent driver updates (correct me if you've experienced otherwise) - It may also mess with process/thread priorities. Not all games support it, generally leave it enabled or benchmark the differences in equal scenarios.

It might set CPU affinites (`AffinitizeToExclusiveCpus`, `CpuExclusivityMaskHig`, `CpuExclusivityMaskLow`) for the game process and the maximum amount of cores the game uses (`MaxCpuCount`). The percentage of GPU memory (`PercentGpuMemoryAllocatedToGame`), GPU time (`PercentGpuTimeAllocatedToGame`) & system compositor (`PercentGpuMemoryAllocatedToSystemCompositor`) that will be dedicated to the game. It may also create a list of processes (`RelatedProcessNames`) that are gaming related, which means that they won't be affected from the game mode. These are just assumptions, I haven't looked into it in detail yet (`GamingHandlers.c`).

Enabling/disabling it via the system settings only switches `AutoGameModeEnabled`:
```powershell
SystemSettings.exe  HKCU\Software\Microsoft\GameBar\AutoGameModeEnabled	Type: REG_DWORD, Length: 4, Data: 1
```
The value doesn't exist by default (not existing = `1`). Ignore `GameBar.txt`, it shows read values.

> [system/assets | gamemode-GamingHandlers.c](https://github.com/5Noxi/win-config/blob/main/system/assets/gamemode-GamingHandlers.c)  
> https://support.xbox.com/en-US/help/games-apps/game-setup-and-play/use-game-mode-gaming-on-pc  
> https://learn.microsoft.com/en-us/uwp/api/windows.gaming.preview.gamesenumeration?view=winrt-26100

---

Miscellaneous notes:
```powershell
\Registry\User\S-ID\SOFTWARE\Microsoft\GameBar : GamepadDoublePressIntervalMs
\Registry\User\S-ID\SOFTWARE\Microsoft\GameBar : GamepadShortPressIntervalMs
```

# Disable Windows Search

| **Suboption** | **Description** |
| ---- | ---- |
| **Disable SafeSearch** | Disables the SafeSearch filter for web search, preventing strict filtering of search results. |
| **Prevent Index on Battery** | Prevents Windows from indexing content while running on battery power, saving system resources. |
| **Disable Index Usage for System File Search** | Disables the use of the index when searching system files, requiring a full scan each time. |
| **Find Partial Matches** | Allows partial matches to be found when searching for files, enabling more flexible search results. |
| **Exclude System Directories** | Excludes system directories from search results, narrowing down the search to user files and folders. |
| **Exclude Archived Files** | Prevents archived files from being included in search results. |
| **Disable Natural Language Search** | Disables the use of natural language search, which allows more conversational queries for search results. |
| **Search Only in Indexed Locations** | Restricts searches in non-indexed locations to only file names, rather than searching both names and contents. |
| **Exclude System Directories** | Excludes system directories (e.g., Windows folders) in search results when searching non-indexed locations. |
| **Exclude Compressed Files** | Excludes compressed files (e.g., ZIP, CAB) in search results when searching non-indexed locations. |
| **Search Only in Indexed Locations** | Disables: "Ensures that file names and contents are always searched in non-indexed locations, which may take more time." |

Search indexing builds a database of file names, properties, and contents to speed up searches, runs as `SearchIndexer.exe`, updates automatically. Disabling it slows down searches, but as shows below you should use everything anyway. Additionally you can disable content and property indexing per drive, by right clicking on the drive, then unticking the box as shown in the picture.

> https://learn.microsoft.com/en-us/windows/win32/search/-search-indexing-process-overview

![](https://github.com/5Noxi/win-config/blob/main/system/images/searchindex.png?raw=true)

Instead of using the explorer to search for a file or folder, use [`Everything`](https://www.voidtools.com/downloads/), it's a lot faster.

The command below includes some of my personal settings. They're saved in:
```
%appdata%\Everything\Everything.ini
```
If you want to revert the changes, either remove the `Everything.ini` file or restore the settings via the options (`STRG + P`).
```powershell
$nvp = "$env:appdata\Everything\Everything.ini";(gc $nvp) -replace '^normal_background_color=.*', 'normal_background_color=#353535' -replace '^normal_foreground_color=.*', 'normal_foreground_color=#ffffff' -replace '^single_click_open=.*', 'single_click_open=2' -replace '^hide_empty_search_results=.*', 'hide_empty_search_results=1' -replace '^double_click_path=.*', 'double_click_path=1' -replace '^show_mouseover=.*', 'show_mouseover=1' -replace '^show_number_of_results_with_selection=.*', 'show_number_of_results_with_selection=1' -replace '^tooltips=.*', 'tooltips=0' -replace '^search_history_enabled=.*', 'search_history_enabled=0' -replace '^run_history_enabled=.*', 'run_history_enabled=0' -replace '^index_date_modified=.*', 'index_date_modified=0' -replace '^exclude_list_enabled=.*', 'exclude_list_enabled=0' -replace '^language=.*', 'language=1033' | sc $nvp
```

The `WSearch` service is needed for CmdPals `File Search` extension to work.

# Enable HAGS

HAGS feature is introduced specifically for the WDDM. If disabled the CPU manages the GPU scheduling via a high-priority kernel thread, GPU context switches and task scheduling are handled by the CPU (CPU offloads graphics intensive tasks to the GPU for rendering). If enabled the GPU handles its own scheduling using a built in scheduler processor, context switching between GPU tasks is done directly on the GPU. It is especially beneficial, if you've a slow CPU, or if the CPU is heavily loaded with other tasks.

"It depends on your hardware, if you want HAGS to be enabled or not. E.g if using a old GPU, it may not fully support the new scheduler."

HAGS should be enabled.

> https://devblogs.microsoft.com/directx/hardware-accelerated-gpu-scheduling/  
> https://maxcloudon.com/hardware-accelerated-gpu-scheduling/

---

Enable HAGS:
```powershell
SystemSettingsAdminFlows.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\HwSchMode	Type: REG_DWORD, Length: 4, Data: 2
```
Disable HAGS:
```powershell
SystemSettingsAdminFlows.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\HwSchMode	Type: REG_DWORD, Length: 4, Data: 1
```

# Disable Storage Sense

Storage Sense deletes temporary files automatically - revert it by changing it back to `1`.

![](https://github.com/5Noxi/win-config/blob/main/system/images/storagesen1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/storagesen2.png?raw=true)

```json
{
  "File": "StorageSense.admx",
  "CategoryName": "StorageSense",
  "PolicyName": "SS_AllowStorageSenseGlobal",
  "NameSpace": "Microsoft.Policies.StorageSense",
  "Supported": "Windows_10_0_RS6",
  "DisplayName": "Allow Storage Sense",
  "ExplainText": "Storage Sense can automatically clean some of the user\u2019s files to free up disk space. By default, Storage Sense is automatically turned on when the machine runs into low disk space and is set to run whenever the machine runs into storage pressure. This cadence can be changed in Storage settings or set with the \"Configure Storage Sense cadence\" group policy. Enabled: Storage Sense is turned on for the machine, with the default cadence as \u2018during low free disk space\u2019. Users cannot disable Storage Sense, but they can adjust the cadence (unless you also configure the \"Configure Storage Sense cadence\" group policy). Disabled: Storage Sense is turned off the machine. Users cannot enable Storage Sense. Not Configured: By default, Storage Sense is turned off until the user runs into low disk space or the user enables it manually. Users can configure this setting in Storage settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\StorageSense"
  ],
  "ValueName": "AllowStorageSenseGlobal",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "StorageSense.admx",
  "CategoryName": "StorageSense",
  "PolicyName": "SS_AllowStorageSenseTemporaryFilesCleanup",
  "NameSpace": "Microsoft.Policies.StorageSense",
  "Supported": "Windows_10_0_RS6",
  "DisplayName": "Allow Storage Sense Temporary Files cleanup",
  "ExplainText": "When Storage Sense runs, it can delete the user\u2019s temporary files that are not in use. If the group policy \"Allow Storage Sense\" is disabled, then this policy does not have any effect. Enabled: Storage Sense will delete the user\u2019s temporary files that are not in use. Users cannot disable this setting in Storage settings. Disabled: Storage Sense will not delete the user\u2019s temporary files. Users cannot enable this setting in Storage settings. Not Configured: By default, Storage Sense will delete the user\u2019s temporary files. Users can configure this setting in Storage settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\StorageSense"
  ],
  "ValueName": "AllowStorageSenseTemporaryFilesCleanup",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Reduce Shutdown Time

Forces hung apps and services to terminate faster.

```
\Registry\Machine\SYSTEM\ControlSet001\Control : WaitToKillServiceTimeout
\Registry\User\S-ID\Control Panel\Desktop : WaitToKillTimeout
\Registry\User\S-ID\Control Panel\Desktop : HungAppTimeout
\Registry\User\S-ID\Control Panel\Desktop : AutoEndTasks
```
`HungAppTimeout`-> `1500` (`1.5` sec; default is `5` sec)
`WaitToKillTimeout`-> `2500` (`2.5` sec)
`WaitToKillServiceTimeout`-> `2500` (`2.5` sec; default is `5` sec)
`WaitToKillAppTimeout` seems to not be used anymore (would have a default of `20000` (`20` sec))

More timeout related values located in `HKCU\Control Panel\Desktop`: `CriticalAppShutdownCleanupTimeout`, `CriticalAppShutdownTimeout`, `QuickResolverTimeout`, `ActiveWndTrkTimeout`, `CaretTimeout`, `ForegroundLockTimeout`, `LowLevelHooksTimeout`. I may add information about some of them soon.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/ControlPanel-Desktop.txt

# Disable FTH

Used for preventing legacy or unstable applications from crashing, read through the picture below for more detailed information (`Windows Internals 7th Edition, Part 1, Page 347`).

> https://github.com/5Noxi/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf  
> https://learn.microsoft.com/en-us/windows/win32/win7appqual/fault-tolerant-heap  
> https://www.youtube.com/watch?v=4SvNNXAwoqE

![](https://github.com/5Noxi/win-config/blob/main/system/images/fth.png?raw=true)

# Disable Accessibility Features

Disables multiple accessibility features such as `Sticky Keys`, `Toggle Keys`, `Mouse Keys`, `Sound Sentry`, `High Contrast` and more (read trough the file for more).

> https://github.com/microsoft/accessibility-insights-windows/blob/main/docs/TelemetryOverview.md#control-of-telemery

# Detailed Verbose Messages

Enables detailed messages at restart, shut down, sign out, and sign in, which can be helpful.

"If verbose logging isn't enabled, you'll still receive normal status messages such as "Applying your personal settings..." or "Applying computer settings..." when you start up, shut down, log on, or log off from the computer. However, if verbose logging is enabled, you'll receive additional information, such as "RPCSS is starting" or "Waiting for machine group policies to finish...."."

"This policy setting directs the system to display highly detailed status messages.This policy setting is designed for advanced users who require this information.If you enable this policy setting, the system displays status messages that reflect each step in the process of starting, shutting down, logging on, or logging off the system. If you disable or do not configure this policy setting, only the default status messages are displayed to the user during these processes.
Note: This policy setting is ignored if the \"Remove Boot/Shutdown/Logon/Logoff status messages" policy setting is enabled."

> https://learn.microsoft.com/en-us/troubleshoot/windows-server/performance/enable-verbose-startup-shutdown-logon-logoff-status-messages

```json
{
  "File": "Logon.admx",
  "CategoryName": "System",
  "PolicyName": "VerboseStatus",
  "NameSpace": "Microsoft.Policies.WindowsLogon",
  "Supported": "Win2k",
  "DisplayName": "Display highly detailed status messages",
  "ExplainText": "This policy setting directs the system to display highly detailed status messages. This policy setting is designed for advanced users who require this information. If you enable this policy setting, the system displays status messages that reflect each step in the process of starting, shutting down, logging on, or logging off the system. If you disable or do not configure this policy setting, only the default status messages are displayed to the user during these processes. Note: This policy setting is ignored if the \"\"Remove Boot/Shutdown/Logon/Logoff status messages\"\" policy setting is enabled.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "ValueName": "VerboseStatus",
  "Elements": []
},
```

# Disable Aero Shake

Prevents windows from being minimized or restored when the active window is shaken back and forth with the mouse.

![](https://www.techjunkie.com/wp-content/uploads/2018/10/windows-aero-shake-example.gif)

```json
{
  "File": "Desktop.admx",
  "CategoryName": "Desktop",
  "PolicyName": "NoWindowMinimizingShortcuts",
  "NameSpace": "Microsoft.Policies.WindowsDesktop",
  "Supported": "Windows7",
  "DisplayName": "Turn off Aero Shake window minimizing mouse gesture",
  "ExplainText": "Prevents windows from being minimized or restored when the active window is shaken back and forth with the mouse. If you enable this policy, application windows will not be minimized or restored when the active window is shaken back and forth with the mouse. If you disable or do not configure this policy, this window minimizing and restoring gesture will apply.",
  "KeyPath": [
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "NoWindowMinimizingShortcuts",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable JPEG Reduction

Windows reduces the quality of JPEG images you set as the desktop background to `85%` by default, you can set it to `100%` via the option switch.

```c
if ( JPEGImportQuality not present or error )
    v54 = 85.0f;
else
    v54 = max(JPEGImportQuality, 60.0f);
    if (v54 > 100.0f)
        v54 = 100.0f;
```
Default value is `85` -> `85%` (gets used if value isn't present), clamp range is `60-100`, if set above `100` it gets clamped to `100`, if set below `60`, it gets clamped to `60`.

> [system/assets | jpeg-TranscodeImage.c](https://github.com/5Noxi/win-config/blob/main/system/assets/jpeg-TranscodeImage.c)

# Disable Low Disk Space Checks

Disables the `Low Disk Space` notification.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/CV-Explorer.txt

![](https://github.com/5Noxi/win-config/blob/main/system/images/lowdiskspace.jpg?raw=true)

# Enable Segment Heap

"With the introduction of Windows 10, Segment Heap, a new native heap implementation was also introduced. It is currently the native heap implementation used in Windows apps (formerly called Modern/Metro apps) and in certain system processes, while the older native heap implementation (NT Heap) is still the default for traditional applications."

Allows modern apps to use a more efficient memory allocator.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "HeapDeCommitFreeBlockThreshold"; = 4096; // qword_140FC3210 dq 1000
    "HeapDeCommitTotalFreeThreshold"; = 65536; // qword_140FC3218 dq 10000
    "HeapSegmentCommit"; = 8192; // qword_140FC3220 dq 2000
    "HeapSegmentReserve"; = 1048576; // qword_140FC3228 dq 100000

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Segment Heap";
    "Enabled"; = 0; // if present with DataLength==4 and nonzero type:
                    //    RtlpLowFragHeapGlobalFlags |= 0x10;  // global segment heap enable
                    //    if (value & 0x2)                      // low byte, bit 1
                    //        RtlpLowFragHeapGlobalFlags |= 0x20; // extra option ?
                    // if the value exists but is stored as REG_NONE (type==0):
                    //    RtlpLowFragHeapGlobalFlags |= 0x8;   // global disable/override
```
> https://github.com/5Noxi/wpr-reg-records#session-manager-values  
> [system/assets | segment-RtlpHpApplySegmentHeapConfigurations.c](https://github.com/5Noxi/win-config/blob/main/system/assets/segment-RtlpHpApplySegmentHeapConfigurations.c)

For a specific executeable:
```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\
Image File Execution Options\(executable)
FrontEndHeapDebugOptions = (DWORD)
Bit 2 (0x04): Disable Segment Heap
Bit 3 (0x08): Enable Segment Heap
```
Globally:
```
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Segment Heap
Enabled = (DWORD)
0 : Disable Segment Heap
(Not 0): Enable Segment Heap
```
Enabling segment heap globally forces the system to use the newer segmented allocation model, which can end up with errors.

> https://blog.s-schoener.com/2024-11-05-segment-heap/  
> https://www.blackhat.com/docs/us-16/materials/us-16-Yason-Windows-10-Segment-Heap-Internals-wp.pdf  
> https://github.com/5Noxi/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf (Page `334`f.)  

![](https://github.com/5Noxi/win-config/blob/main/system/images/segment1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/segment2.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/segment3.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/segment4.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/segment5.png?raw=true)

# Disable Notifications

Disables lock screen, desktop, feature advertisement balloon notifications, notification area, notifications network usage and more.

"`WnsEndpoint` (`REG_SZ`) determines which Windows Notification Service (WNS) endpoint will be used to connect for Windows push notifications. If you disable or don't configure this setting, the push notifications will connect to the default endpoint of `client.wns.windows.com`. " Located in `HKLM\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications`. Block `client.wns.windows.com` via the hosts file.

`Turn off access to the Store`:  
This policy setting specifies whether to use the Store service for finding an application to open a file with an unhandled file type or protocol association. When a user opens a file type or protocol that is not associated with any applications on the computer, the user is given the choice to select a local application or use the Store service to find an application. If you enable this policy setting, the "Look for an app in the Store" item in the Open With dialog is removed. If you disable or do not configure this policy setting, the user is allowed to use the Store service and the Store item is available in the Open With dialog.

All `NOC_GLOBAL_SETTING_*` I found in `NotificationController.dll`:
```c
"HKLM\\SOFTWARE\\Microsoft\\WINDOWS\\CurrentVersion\\Notifications\\Settings"
  'NOC_GLOBAL_SETTING_SUPRESS_TOASTS_WHILE_DUPLICATING'; // Hide notifications when I'm duplicating my screen
  'NOC_GLOBAL_SETTING_ALLOW_TOASTS_ABOVE_LOCK'; // Show notifications on the lock screen
  'NOC_GLOBAL_SETTING_ALLOW_CRITICAL_TOASTS_ABOVE_LOCK'; // Show reminders and incoming VoIP calls on the lock screen
  'NOC_GLOBAL_SETTING_CORTANA_MANAGED_NOTIFICATIONS';
  'NOC_GLOBAL_SETTING_ALLOW_ACTION_CENTER_ABOVE_LOCK';
  'NOC_GLOBAL_SETTING_HIDE_NOTIFICATION_CONTENT';
  'NOC_GLOBAL_SETTING_TOASTS_ENABLED';
  'NOC_GLOBAL_SETTING_BADGE_ENABLED'; // Don't show number of notifications
  'NOC_GLOBAL_SETTING_GLEAM_ENABLED'; // App icons (Action Center)
  'NOC_GLOBAL_SETTING_ALLOW_HMD_NOTIFICATIONS'; // Show notifications on my head mounted display
  'NOC_GLOBAL_SETTING_ALLOW_CONTROL_CENTER_ABOVE_LOCK';
  'NOC_GLOBAL_SETTING_ALLOW_NOTIFICATION_SOUND'; // Allow notification to play sounds
```
The options I've commented on are included in the options under `System > Notifications`/right click menu of notification center.

---

```json
{
  "File": "WindowsDefenderSecurityCenter.admx",
  "CategoryName": "Notifications",
  "PolicyName": "Notifications_DisableEnhancedNotifications",
  "NameSpace": "Microsoft.Policies.WindowsDefenderSecurityCenter",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Hide non-critical notifications",
  "ExplainText": "Only show critical notifications from Windows Security. If the Suppress all notifications GP setting has been enabled, this setting will have no effect. Enabled: Local users will only see critical notifications from Windows Security. They will not see other types of notifications, such as regular PC or device health information. Disabled: Local users will see all types of notifications from Windows Security. Not configured: Same as Disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows Defender Security Center\\Notifications"
  ],
  "ValueName": "DisableEnhancedNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsDefender.admx",
  "CategoryName": "Reporting",
  "PolicyName": "Reporting_DisableEnhancedNotifications",
  "NameSpace": "Microsoft.Policies.WindowsDefender",
  "Supported": "Windows_10_0",
  "DisplayName": "Turn off enhanced notifications",
  "ExplainText": "Use this policy setting to specify if you want Microsoft Defender Antivirus enhanced notifications to display on clients. If you disable or do not configure this setting, Microsoft Defender Antivirus enhanced notifications will display on clients. If you enable this setting, Microsoft Defender Antivirus enhanced notifications will not display on clients.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows Defender\\Reporting"
  ],
  "ValueName": "DisableEnhancedNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsDefenderSecurityCenter.admx",
  "CategoryName": "Notifications",
  "PolicyName": "Notifications_DisableNotifications",
  "NameSpace": "Microsoft.Policies.WindowsDefenderSecurityCenter",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Hide all notifications",
  "ExplainText": "Hide notifications from Windows Security. Enabled: Local users will not see notifications from Windows Security. Disabled: Local users can see notifications from Windows Security. Not configured: Same as Disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows Defender Security Center\\Notifications"
  ],
  "ValueName": "DisableNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsDefenderSecurityCenter.admx",
  "CategoryName": "EnterpriseCustomization",
  "PolicyName": "EnterpriseCustomization_EnableCustomizedToasts",
  "NameSpace": "Microsoft.Policies.WindowsDefenderSecurityCenter",
  "Supported": "Windows_10_0_RS3",
  "DisplayName": "Configure customized notifications",
  "ExplainText": "Display specified contact information to local users in Windows Security notifications. Enabled: Your company contact information will be displayed in notifications that come from Windows Security. After setting this to Enabled, you must configure the Specify contact company name GP setting and at least one of the following GP settings: -Specify contact phone number or Skype ID -Specify contact email number or email ID -Specify contact website Please note that in some cases we will be limiting the contact options that are displayed based on the notification space available. Disabled: No contact information will be shown on notifications. Not configured: Same as Disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows Defender Security Center\\Enterprise Customization"
  ],
  "ValueName": "EnableForToasts",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "ICM.admx",
  "CategoryName": "InternetManagement_Settings",
  "PolicyName": "ShellNoUseStoreOpenWith_2",
  "NameSpace": "Microsoft.Policies.InternetCommunicationManagement",
  "Supported": "Windows8",
  "DisplayName": "Turn off access to the Store",
  "ExplainText": "This policy setting specifies whether to use the Store service for finding an application to open a file with an unhandled file type or protocol association. When a user opens a file type or protocol that is not associated with any applications on the computer, the user is given the choice to select a local application or use the Store service to find an application. If you enable this policy setting, the \"Look for an app in the Store\" item in the Open With dialog is removed. If you disable or do not configure this policy setting, the user is allowed to use the Store service and the Store item is available in the Open With dialog.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "NoUseStoreOpenWith",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WPN.admx",
  "CategoryName": "NotificationsCategory",
  "PolicyName": "NoTileNotification",
  "NameSpace": "Microsoft.Policies.Notifications",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "Turn off tile notifications",
  "ExplainText": "This policy setting turns off tile notifications. If you enable this policy setting, applications and system features will not be able to update their tiles and tile badges in the Start screen. If you disable or do not configure this policy setting, tile and badge notifications are enabled and can be turned off by the administrator or user. No reboots or service restarts are required for this policy setting to take effect.",
  "KeyPath": [
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"
  ],
  "ValueName": "NoTileApplicationNotification",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WPN.admx",
  "CategoryName": "NotificationsCategory",
  "PolicyName": "NoNotificationMirroring",
  "NameSpace": "Microsoft.Policies.Notifications",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Turn off notification mirroring",
  "ExplainText": "This policy setting turns off notification mirroring. If you enable this policy setting, notifications from applications and system will not be mirrored to your other devices. If you disable or do not configure this policy setting, notifications will be mirrored, and can be turned off by the administrator or user. No reboots or service restarts are required for this policy setting to take effect.",
  "KeyPath": [
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"
  ],
  "ValueName": "DisallowNotificationMirroring",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WPN.admx",
  "CategoryName": "NotificationsCategory",
  "PolicyName": "NoToastNotification",
  "NameSpace": "Microsoft.Policies.Notifications",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "Turn off toast notifications",
  "ExplainText": "This policy setting turns off toast notifications for applications. If you enable this policy setting, applications will not be able to raise toast notifications. Note that this policy does not affect taskbar notification balloons. Note that Windows system features are not affected by this policy. You must enable/disable system features individually to stop their ability to raise toast notifications. If you disable or do not configure this policy setting, toast notifications are enabled and can be turned off by the administrator or user. No reboots or service restarts are required for this policy setting to take effect.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\PushNotifications",
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"
  ],
  "ValueName": "NoToastApplicationNotification",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WPN.admx",
  "CategoryName": "NotificationsCategory",
  "PolicyName": "NoLockScreenToastNotification",
  "NameSpace": "Microsoft.Policies.Notifications",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "Turn off toast notifications on the lock screen",
  "ExplainText": "This policy setting turns off toast notifications on the lock screen. If you enable this policy setting, applications will not be able to raise toast notifications on the lock screen. If you disable or do not configure this policy setting, toast notifications on the lock screen are enabled and can be turned off by the administrator or user. No reboots or service restarts are required for this policy setting to take effect.",
  "KeyPath": [
    "HKCU\\SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"
  ],
  "ValueName": "NoToastApplicationNotificationOnLockScreen",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

---

```c
"HKCU\\Control Panel\\Accessibility";
  // Dismiss notifications after this amount of time
  "MessageDuration" = 5; // REG_DWORD, range 5-300(s)
```

According to pseudocode, it has a range from `0` to `0xFFFFFFFF`. Fallback of `5`, SystemSettings supports ranges from `5` (5 seconds) to `300` (5 minutes). Anything above/below will likely be limited (haven't tested it yet).

# Export Explorer/Taskbar Pins

Can be useful when creating your own image and trying to automate the installation and configuration part.

Quick access pins are saved in a file named `f01b4d95cf55d32a.automaticDestinations-ms`, located at:
```bat
%appdata%\Microsoft\Windows\Recent\AutomaticDestinations
```
You can either terminate `explorer` while copying it to the path, or just restart it afterwards.
```bat
copy /y ".\f01b4d95cf55d32a.automaticDestinations-ms" "%appdata%\Microsoft\Windows\Recent\AutomaticDestinations"
```
Taskbar pins are saved in a folder and a key, the folder includes the shortcuts:
```bat
%appdata%\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar
```
```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Taskband # Only "Favorites" is needed
```
You can convert the exported `.reg` to `.ps1` with:
> https://reg2ps.azurewebsites.net/

Post install example (copy the `TaskBar` folder to any folder):
```powershell
del "$env:appdata\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar" -Recurse -Force
xcopy ".\TaskBar" "%appdata%\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar" /e /i /y
```
> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/xcopy

__Automate the process:__
Gets current values of `Favorites` (taskbar pins) & `UIOrderList` (system tray icons) and copies all necessary files to `$home\Desktop` (edit `$dest` & `$bat` to whatever you want).

# Disable Timestamp Interval

Disables the interval at which reliability events are timestamped (will not log regular timestamped reliability events).

```c
if ( !RegQueryValueExW(hKey[0], "TimeStampEnabled", 0LL, 0LL, (LPBYTE)&Data, &cbData) )
if ( !RegQueryValueExW(hKey[0], "TimeStampInterval", 0LL, 0LL, (LPBYTE)&v4, &cbData) && v4 <= 0x15180 ) // 86400 seconds = 24h?
```
`TimeStampInterval` has a max value of `86400` dec = 24h, `TimeStampEnabled` can probably be set to `0`/`1`.

```
\Registry\Machine\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability : TimeStampInterval
```
Only this path gets read, `TimeStampEnabled` doesn't get read?

> [system/assets | timestamp-OsEventsTimestampInterval.c](https://github.com/5Noxi/win-config/blob/main/system/assets/timestamp-OsEventsTimestampInterval.c)

# Disable Prefetch & Superfetch

Disables prefetcher (includes disabling `ApplicationLaunchPrefetching` & `ApplicationPreLaunch`) features, used to speed up the boot process and application startup by preloading data - **shouldn't be disabled**, leaving it for documentation reasons. Read through the pictures for more detailed information.

"`EnablePrefetcher` is a setting in the File-Based Write Filter (FBWF) and Enhanced Write Filter with HORM (EWF) packages. It specifies how to run Prefetch, a tool that can load application data into memory before it is demanded."

"`EnableSuperfetch` is a setting in the File-Based Write Filter (FBWF) and Enhanced Write Filter with HORM (EWF) packages. It specifies how to run SuperFetch, a tool that can load application data into memory before it is demanded. SuperFetch improves on Prefetch by monitoring which applications that you use the most and preloading those into system memory."

"`SfTracingState` belongs to `sftracing.exe`. This file most often belongs to product Office Server Search. This file most often has  description Office Server Search."

`EnableBoottrace` is used to trace the startup, `1`= enabled, `0` = disabled.

```
0 - Disables Prefetch
1 - Enables Prefetch when the application starts
2 - Enables Prefetch when the device starts up
3 - Enables Prefetch when the application or device starts up
```
The same applies to superfetch.

> https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ff794235(v=winembedded.60)?redirectedfrom=MSDN  
> https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ff794183(v=winembedded.60)?redirectedfrom=MSDN  
> https://learn.microsoft.com/en-us/powershell/module/mmagent/disable-mmagent?view=windowsserver2025-ps

More detailed information about prefetch and superfetch on page `413`f & `472`f.
> https://github.com/5Noxi/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf

![](https://github.com/5Noxi/win-config/blob/main/system/images/prefetch1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/prefetch2.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/prefetch3.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/prefetch4.png?raw=true)

# Optimize File System

Small documentation on several values the option applies, see links below for more details.

| Value | Description |
| ----- | ------------ |
| `DisableDeleteNotification` | 0 = TRIM/UNMAP enabled, 1 = disabled. Controls whether delete operations send trim/unmap notifications to the underlying storage. |
| `DontVerifyRandomDrivers` | 0 = Driver Verifier may pick random drivers, 1 = random selection suppressed, so only explicitly chosen drivers are verified. |
| `LongPathsEnabled` | 0 = legacy `MAX_PATH` limit, 1 = Win32 long paths enabled (paths up to ~32k characters for apps and policies that opt in). |
| `NtfsAllowExtendedCharacter8dot3Rename` | 0 = 8.3 short names restricted to basic ASCII, 1 = extended characters (including diacritics). |
| `NtfsBugcheckOnCorrupt` | 0 = NTFS attempts self healing without forcing a bugcheck, 1 = triggers a bugcheck when corruption is detected on an NTFS volume, avoiding "silent" data loss with self healing NTFS. |
| `NtfsDisable8dot3NameCreation` | Disables the creation of 8.3 character-length file names on FAT- and NTFS-formatted volumes.<br>0: Enables 8dot3 name creation for all volumes on the system.<br>1: Disables 8dot3 name creation for all volumes on the system.<br>2: Sets 8dot3 name creation on a per volume basis.<br>3: Disables 8dot3 name creation for all volumes except the system volume. |
| `NtfsDisableCompression` | 0 = NTFS compression allowed, 1 = new compressed files/folders cannot be created (existing compressed data remains readable). |
| `NtfsDisableCompressionLimit` | 0 = when a compressed file gets highly fragmented, NTFS stops compressing new extents so the file can grow larger uncompressed, 1 = disables this behavior and enforces the internal compression limit. |
| `NtfsDisableEncryption` | 0 = NTFS EFS file/folder encryption available, 1 = EFS disabled on NTFS volumes. |
| `NTFSDisableLastAccessUpdate` | Controls Last Access Time updates on NTFS files/directories. |
| `NtfsDisableSpotCorruptionHandling` | 0 = NTFS spot corruption handling active, 1 = disabled, so NTFS relies on manual tools. Also allows running CHKDSK to analyze a volume online without taking it offline. |
| `NtfsEncryptPagingFile` | 0 = pagefile.sys stored unencrypted, 1 = paging file encrypted. |
| `NtfsMemoryUsage` | Configures the internal cache levels of NTFS paged-pool memory and NTFS nonpaged-pool memory. |
| `NtfsMftZoneReservation` | Sets reserved NTFS MFT zone size as 200 MB x value: 1 = 200 MB (default), up to 4 = 800 MB. Larger values reduce MFT fragmentation on volumes with many small files. |
| `RefsDisableLastAccessUpdate` | Related to NTFSDisableLastAccessUpdate (both get set via disablelastaccess). |
| `SymlinkXToXEvaluation` | 0 = x->x symlinks not followed, 1 = resolved (X = Local/Remote). |
| `Win31FileSystem` | 0 = standard modern FAT behavior (long filenames, richer timestamps), 1 = legacy Windows 3.1–compatible mode with stricter 8.3 naming and older timestamp semantics. |

Scan current 8dot3 files names: `fsutil 8dot3name scan C:\`

Symlinksare shortcuts or references that point to a file or folder in another location, like a portal. They're not duplicates, just pointers.
File at: `C:\Projects\Game\assets\logo.png`
Symlink: `C:\Users\YourName\Desktop\logo.png`

> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-behavior  
> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-8dot3name  
> https://github.com/MicrosoftDocs/windows-driver-docs/blob/5e03e46194f2a977da34fdf453f2703262370a23/windows-driver-docs-pr/ifs/offloaded-data-transfers.md?plain=1#L104  
> https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=registry  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/FileSystem.txt

> [system/assets | filesystem-NtfsUpdateDynamicRegistrySettings.c](https://github.com/5Noxi/win-config/blob/main/system/assets/filesystem-NtfsUpdateDynamicRegistrySettings.c)

# Disable Clipboard

If you copy or cut something it gets stored to your clipboard.

Additional value, which get's read:
```
\Registry\Machine\SOFTWARE\Microsoft\Clipboard : IsCloudAndHistoryFeatureAvailable
```

```json
{
  "File": "TerminalServer.admx",
  "CategoryName": "TS_REDIRECTION",
  "PolicyName": "TS_CLIENT_CLIPBOARD",
  "NameSpace": "Microsoft.Policies.TerminalServer",
  "Supported": "WindowsXP",
  "DisplayName": "Do not allow Clipboard redirection",
  "ExplainText": "This policy setting specifies whether to prevent the sharing of Clipboard contents (Clipboard redirection) between a remote computer and a client computer during a Remote Desktop Services session. You can use this setting to prevent users from redirecting Clipboard data to and from the remote computer and the local computer. By default, Remote Desktop Services allows Clipboard redirection. If you enable this policy setting, users cannot redirect Clipboard data. If you disable this policy setting, Remote Desktop Services always allows Clipboard redirection. If you do not configure this policy setting, Clipboard redirection is not specified at the Group Policy level.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services"
  ],
  "ValueName": "fDisableClip",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsSandbox.admx",
  "CategoryName": "WindowsSandbox",
  "PolicyName": "AllowClipboardRedirection",
  "NameSpace": "Microsoft.Policies.WindowsSandbox",
  "Supported": "Windows_11_0_NOSERVER_ENTERPRISE_EDUCATION_PRO_SANDBOX",
  "DisplayName": "Allow clipboard sharing with Windows Sandbox",
  "ExplainText": "This policy setting enables or disables clipboard sharing with the sandbox. If you enable this policy setting, copy and paste between the host and Windows Sandbox are permitted. If you disable this policy setting, copy and paste in and out of Sandbox will be restricted. If you do not configure this policy setting, clipboard sharing will be enabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Sandbox"
  ],
  "ValueName": "AllowClipboardRedirection",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OSPolicy.admx",
  "CategoryName": "PolicyPolicies",
  "PolicyName": "AllowCrossDeviceClipboard",
  "NameSpace": "Microsoft.Policies.OSPolicy",
  "Supported": "Windows_10_0",
  "DisplayName": "Allow Clipboard synchronization across devices",
  "ExplainText": "This policy setting determines whether Clipboard contents can be synchronized across devices. If you enable this policy setting, Clipboard contents are allowed to be synchronized across devices logged in under the same Microsoft account or Azure AD account. If you disable this policy setting, Clipboard contents cannot be shared to other devices. Policy change takes effect immediately.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "AllowCrossDeviceClipboard",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "OSPolicy.admx",
  "CategoryName": "PolicyPolicies",
  "PolicyName": "AllowClipboardHistory",
  "NameSpace": "Microsoft.Policies.OSPolicy",
  "Supported": "Windows_10_0",
  "DisplayName": "Allow Clipboard History",
  "ExplainText": "This policy setting determines whether history of Clipboard contents can be stored in memory. If you enable this policy setting, history of Clipboard contents are allowed to be stored. If you disable this policy setting, history of Clipboard contents are not allowed to be stored. Policy change takes effect immediately.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "AllowClipboardHistory",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Background GP Updates

"This policy setting prevents Group Policy from being updated while the computer is in use. This policy setting applies to Group Policy for computers, users, and domain controllers.If you enable this policy setting, the system waits until the current user logs off the system before updating the computer and user settings.If you disable or do not configure this policy setting, updates can be applied while users are working."

```json
{
  "File": "GroupPolicy.admx",
  "CategoryName": "PolicyPolicies",
  "PolicyName": "DisableBackgroundPolicy",
  "NameSpace": "Microsoft.Policies.GroupPolicy",
  "Supported": "Win2k",
  "DisplayName": "Turn off background refresh of Group Policy",
  "ExplainText": "This policy setting prevents Group Policy from being updated while the computer is in use. This policy setting applies to Group Policy for computers, users, and domain controllers. If you enable this policy setting, the system waits until the current user logs off the system before updating the computer and user settings. If you disable or do not configure this policy setting, updates can be applied while users are working. The frequency of updates is determined by the \"Set Group Policy refresh interval for computers\" and \"Set Group Policy refresh interval for users\" policy settings. Note: If you make changes to this policy setting, you must restart your computer for it to take effect.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
  ],
  "ValueName": "DisableBkGndGroupPolicy",
  "Elements": []
},
```

# Disable Memory Compression

Memory compression compresses rarely used or less frequently accessed data in RAM so it takes up less space. Windows does this to keep more data in physical memory and avoid writing to the pagefile, which reduces disk I/O. When the data is needed again, it's decompressed. It's faster than paging to disk, but it costs CPU.

Example:  
1. System looks for cold/rarely used data in RAM
2. It compresses that data, e.g. 24 MB -> 7 MB
3. The 17 MB saved is used for active apps
4. When the data is needed again, it's decompressed back to 24 MB

See the current memory compresstion state on your system via:
```powershell
Get-MMAgent
```
```powershell
ApplicationLaunchPrefetching : True
ApplicationPreLaunch         : True
MaxOperationAPIFiles         : 512
MemoryCompression            : True # Enabled
OperationAPI                 : True
PageCombining                : True
PSComputerName               :
```

![](https://github.com/5Noxi/win-config/blob/main/system/images/memcompress1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/memcompress2.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/memcompress3.png?raw=true)

> https://github.com/5Noxi/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf (P. 449)  
> https://learn.microsoft.com/en-us/powershell/module/mmagent/disable-mmagent?view=windowsserver2025-ps

# Disable Page Combining

Page combining spots identical RAM pages across processes and merges them into a single shared page. Instead of keeping 50 copies of the same DLL/data page, the memory manager keeps one, maps it to everyone, and marks it `copy-on-write`. As long as nobody changes it, everyone shares the same physical page and RAM usage drops. If a process writes to it, Windows gives that process its own private copy and leaves the shared one intact. It's a background RAM deduplicator, basically.

See the current page combining state on your system via:
```powershell
Get-MMAgent
```
```powershell
ApplicationLaunchPrefetching : True
ApplicationPreLaunch         : True
MaxOperationAPIFiles         : 512
MemoryCompression            : True
OperationAPI                 : True
PageCombining                : True # Enabled
PSComputerName               :
```

![](https://github.com/5Noxi/win-config/blob/main/system/images/pagecomb1.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/pagecomb2.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/pagecomb3.png?raw=true)
![](https://github.com/5Noxi/win-config/blob/main/system/images/pagecomb4.png?raw=true)

> https://github.com/5Noxi/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf (P. 459)  
> https://learn.microsoft.com/en-us/powershell/module/mmagent/disable-mmagent?view=windowsserver2025-ps

# Enable Detailed BSoD

| Aspect                    | New BSoD (Windows 8/10/11)                      | Old BSoD (Windows 7/classic)                                                      |
| ------------------------- | ----------------------------------------------- | --------------------------------------------------------------------------------- |
| Main look                 | Big blue screen, sad face, simple text, QR code | Plain blue text screen, no icons                                                  |
| Stop code shown           | e.g. CRITICAL_PROCESS_DIED                      | e.g. STOP 0x0000007E                                                              |
| Hex parameters            | Hidden                                          | Shown: (0x00000000, 0x00000000...)                                                |
| Faulty driver/module name | Hidden                                          | Often shown (e.g. nvlddmkm.sys)                                                   |
| Extra help                | QR code + link                                  | Text-only advice                                                                  |
| Purpose                   | Less scary, easier to tell support the code     | See the actual debug information                                                  |

Enabling the options includes setting `AutoReboot` to `0` ("The option specifies that Windows automatically restarts your computer").

> https://learn.microsoft.com/en-us/troubleshoot/windows-server/performance/memory-dump-file-options#registry-values-for-startup-and-recovery  
> https://learn.microsoft.com/en-us/troubleshoot/windows-client/performance/configure-system-failure-and-recovery-options

# Display Scaling

Changes the size of text, apps, and other items. Note that on laptops the default display scaling might not be `100%`. You can set a custom scaling size via `System > Display > Custom scaling`:

![](https://github.com/5Noxi/win-config/blob/main/system/images/displayscaling.png?raw=true)

```c
// 100%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 0
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 0

// 125%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 1
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 1

// 150%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 2
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 2

// 175%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 3
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 3

// 200%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 4
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 4

// 225%
SystemSettings.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 5
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\PerMonitorSettings\MONITORID\DpiValue	Type: REG_DWORD, Length: 4, Data: 5
```

---


`Prevent Window Minimization on Monitor Disconnection` disables `Minimize windows then a monitor is diconnected` (`System > Display`).

```c
// Enabled
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\MonitorRemovalRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 0

// Disabled
SystemSettings.exe	RegSetValue	HKCU\Control Panel\Desktop\MonitorRemovalRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 1
```

# BCD Edits

`bcdedit /timeout 3`
Decrease timeout of dual-boot selection window (default of `10`).
"The boot menu time-out determines how long the boot menu is displayed before the default boot entry is loaded. It is calibrated in seconds. If you want extra time to choose the operating system that loads on your computer, you can extend the time-out value. Or, you can shorten the time-out value so that the default operating system starts faster."

`bcdedit /set bootmenupolicy Legacy`
"Defines the type of boot menu the system will use. For Windows 10, Windows 8.1, Windows 8 and Windows RT the default is Standard. For Windows Server 2012 R2, Windows Server 2012, the default is Legacy. When Legacy is selected, the Advanced options menu (F8) is available. When Standard is selected, the boot menu appears but only under certain conditions: for example, if there is a startup failure, if you are booting up from a repair disk or installation media, if you have configured multiple boot entries, or if you manually configured the computer to use Advanced startup. When Standard is selected, the F8 key is ignored during boot."

---

Personal notes on several features, used pseudocode:
> [system/assets | bcdedit-HalpMiscGetParameters.c](https://github.com/5Noxi/win-config/blob/main/system/assets/bcdedit-HalpMiscGetParameters.c)

```c
lkd> db HalpInterruptX2ApicPolicy l1
fffff807`8d20a5dc  01

if ( strstr(v3, "X2APICPOLICY=ENABLE") )
    HalpInterruptX2ApicPolicy = 1;

if ( strstr(v3, "X2APICPOLICY=DISABLE") )
    HalpInterruptX2ApicPolicy = 0;

if ( strstr(v3, "USELEGACYAPICMODE") )
    HalpInterruptX2ApicPolicy = 0; // force disable
```
```c
lkd> db HalpTscSyncPolicy l1
Couldnt resolve error at HalpTscSyncPolicy // doesn't exist

HalpTscSyncPolicy = 1; // TSCSYNCPOLICY=LEGACY
HalpTscSyncPolicy = 2; // TSCSYNCPOLICY=ENHANCED
```

`bcdedit /set loadoptions SYSTEMWATCHDOGPOLICY=DISABLED`
```c
if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=DISABLED") )
{
    HalpTimerWatchdogDisable = 1;
}
else if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=PHYSICALONLY") )
{
    HalpTimerWatchdogPhysicalOnly = 1;
}

lkd> db HalpTimerWatchdogDisable l1
fffff803`d21c0712  00 // default
```
```c
lkd> db HalpTimerPlatformSourceForced l1
fffff803`d21c25d0  00
lkd> db HalpTimerPlatformClockSourceForced l1
fffff803`d21c2678  00

if ( strstr(v3, "USEPLATFORMCLOCK") )
    HalpTimerPlatformSourceForced = 1;

if ( strstr(v3, "USEPLATFORMTICK") )
    HalpTimerPlatformClockSourceForced = 1;
```
```c
lkd> db HalpMiscDiscardLowMemory l1
fffff803`d21bff79  01 // USENONE / USEPRIVATE?
lkd> db HalpHvCpuManager l1
fffff804`c27c0490  00

if ( (unsigned int)HalpInterruptModel() == 1 )
    HalpMiscDiscardLowMemory = 1; // default if HalpInterruptModel() == 1

if ( HalpHvCpuManager )
{
    v19[0] = 0;
    if ( (unsigned __int8)HalpGetCpuInfo(0LL, 0LL, 0LL, v19) )
    {
        if ( v19[0] == 2 && (__readmsr(0xFEu) & 0x8000) != 0 )
        HalpMiscDiscardLowMemory = 1; // 1 if HV CPU manager + CPU type 2 + MSR 0xFE bit 15 set
    }
}
if (strstr(BootOptions, "FIRSTMEGABYTEPOLICY=USEALL") || // one of them have to be true to get 0
    (HalpIsMicrosoftCompatibleHvLoaded() && !HalpHvCpuManager)) // system running under hypervisor & not HalpHvCpuManager
{
    HalpMiscDiscardLowMemory = 0; // forced 0 if above is true
}
```
```c
v3 = *(const char **)(a1 + 216);
if ( v3 )
{
    strstr(*(const char **)(a1 + 216), "SAFEBOOT:"); // does nothing here

    if ( strstr(v3, "ONECPU") )
        HalpInterruptProcessorCap = 1;

    if ( strstr(v3, "USEPHYSICALAPIC") )
        HalpInterruptPhysicalModeOnly = 1;

    if ( strstr(v3, "BREAK") )
        HalpMiscDebugBreakRequested = 1;
}
```
```c
if ( strstr(v3, "CONFIGACCESSPOLICY=DISALLOWMMCONFIG") )
    HalpAvoidMmConfigAccessMethod = 1; // force avoid
```
```c
if ( strstr(v3, "MSIPOLICY=FORCEDISABLE") ) // HalpInterruptSetMsiOverride(0)
{
    v10 = 0LL;
}
else
{
    if ( !strstr(v3, "FORCEMSI") ) // HalpInterruptSetMsiOverride(1)
        goto LABEL_46;
    LOBYTE(v10) = 1;
}
HalpInterruptSetMsiOverride(v10);
```

Default entries:
```powershell
Windows Boot Manager
--------------------
identifier              {bootmgr}
device                  partition=\Device\HarddiskVolume1
description             Windows Boot Manager
locale                  en-US
inherit                 {globalsettings}
default                 {current}
resumeobject            {cad1d575-b437-11f0-ab05-d9233ecd39d1}
displayorder            {current}
toolsdisplayorder       {memdiag}
timeout                 30

Windows Boot Loader
-------------------
identifier              {current}
device                  partition=C:
path                    \WINDOWS\system32\winload.exe
description             Windows 11
locale                  en-US
inherit                 {bootloadersettings}
recoverysequence        {cad1d577-b437-11f0-ab05-d9233ecd39d1}
displaymessageoverride  Recovery
recoveryenabled         Yes
allowedinmemorysettings 0x15000075
osdevice                partition=C:
systemroot              \WINDOWS
resumeobject            {cad1d575-b437-11f0-ab05-d9233ecd39d1}
nx                      OptIn
bootmenupolicy          Standard
```

# Disable Autoruns

The `Open` buttons downloads & executes [`Autoruns.exe`](https://live.sysinternals.com/Autoruns.exe). It's recommended to disable all kind of autoruns in the `Logon` section that you don't need, examples:
```c
OneDrive
Spotify
Discord
Steam
WingetUI
Lghub
SecurityHealth

Microsoft Edge // preferable remove edge from the mounted image, otherwise it'll create keys/values in many different places
```

Try to minimize the amount of applications that run automatically on system startup. You can go trough the other sections, but this option was created for the `Logon` section, see `Disable Scheduled Tasks`/`Disable Services`.

See your current autoruns of installed apps:
```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\Run
```
```powershell
HKLM\Software\Microsoft\Windows\CurrentVersion\Run
```

> https://live.sysinternals.com/  
> https://learn.microsoft.com/en-us/sysinternals/downloads/autoruns

# Enable FSO

### FSE (Fullscreen Exclusive)

Game takes exclusive control of the display.
- App sets display mode directly
- No desktop compositor in the path (DWM)
- Bad for Alt-Tab, overlays, and multi monitor

### FSO (Fullscreen Optimizations)

Windows feature that makes borderless/windowed behave like fullscreen.
- Runs as a flip-model, borderless window through DWM
- Still allows overlays, Game Bar, better Alt-Tab
- Tries to give fullscreen-like latency and performance without true exclusive control

DX12 games don't support FSE.

![](https://github.com/5Noxi/win-config/blob/main/nvidia/images/swapchain.jpg?raw=true)

---

Caution: Disabling this option won't revert the changes like all other ones do, it'll disable FSO.

All values I found that are `GameDVR` related in `ResourcePolicyServer.dll`:
```c
GameDVR_DXGIHonorFSEWindowsCompatible
// 0 = FSO on
// 1 = FSO off

GameDVR_EFSEFeatureFlags
// 1 = EFSE on
// 0 = EFSE off

GameDVR_FSEBehavior
// 0 = FSO on
// 2 = FSO off

GameDVR_FSEBehaviorMode
// 0 = FSO on
// 2 = FSO off

GameDVR_HonorUserFSEBehaviorMode
// 0 = FSO on
// 1 = FSO off
```

`GameDVR_DSEBehavior` doesn't exist on my current system.

Disable/enable FSO for a specific application via `Properties > Compatibility > Change settings for all users` - `Disable fullscreen optimizations` or do it per user one step before.

```c
// User
HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\C:\Program Files (x86)\Steam\steamapps\common\Battlefield 6\bf6.exe	Type: REG_SZ, Length: 66, Data: ~ DISABLEDXMAXIMIZEDWINDOWEDMODE

// Machine
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\C:\Program Files (x86)\Steam\steamapps\common\Battlefield 6\bf6.exe	Type: REG_SZ, Length: 66, Data: ~ DISABLEDXMAXIMIZEDWINDOWEDMODE
```

> https://devblogs.microsoft.com/directx/demystifying-full-screen-optimizations/
> https://wiki.special-k.info/en/SwapChain
> https://wiki.special-k.info/Presentation_Model

---

Miscellaneous values:
```c
GameDVR_Enabled
GameDVR_GameGUID
// Seems to be located in HKCU\System\GameConfigStore\Children\*

Win32_AutoGameModeDefaultProfile
Win32_GameModeRelatedProcesses
Win32_GameModeUserRelatedProcesses
```

# App Archive

"Automatically archive your infrequently used apps to save storage and internet bandwidth. Your files and data will still be saved, and the app's full version will be restored on your next use if it's still available."

If enabled, the system will periodically check for such infrequently used apps. By default app archiving is turned on.

Toggling the option via `Apps > Advanced app settings`:
```c
// On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\InstallService\Stubification\S-{ID}\EnableAppOffloading    Type: REG_DWORD, Length: 4, Data: 1

// Off
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\InstallService\Stubification\S-{ID}\EnableAppOffloading    Type: REG_DWORD, Length: 4, Data: 0
```

```json
{
  "File": "AppxPackageManager.admx",
  "CategoryName": "AppxDeployment",
  "PolicyName": "AllowAutomaticAppArchiving",
  "NameSpace": "Microsoft.Policies.Appx",
  "Supported": "Windows_10_0 - At least Windows Server 2016, Windows 10",
  "DisplayName": "Archive infrequently used apps",
  "ExplainText": "This policy setting controls whether the system can archive infrequently used apps. If you enable this policy setting, then the system will periodically check for and archive infrequently used apps. If you disable this policy setting, then the system will not archive any apps. If you do not configure this policy setting (default), then the system will follow default behavior, which is to periodically check for and archive infrequently used apps, and the user will be able to configure this setting themselves.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Appx"
  ],
  "ValueName": "AllowAutomaticAppArchiving",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```
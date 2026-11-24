# Kernel Values

## CmControlVector

CM = configuration manager, it loads & manages registry hives, inserts the `\REGISTRY` key object into the namespace and more. See regkits '[Registry fundamentals](https://noverse.dev/docs/regkit/registry-internals/registry-fundamentals/)' documentation for more information on the topic.

`CmControlVector` is a table used by [`CmpGetSystemControlValues`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/CmpGetSystemControlValues.c) while early CM init. Each entry is `0x30` bytes (six pointers), this is just a simple way to imagine each block:

```c
struct CM_CONTROL_VECTOR_ENTRY {
  PCWSTR KeyPath; // relative to \CurrentControlSet\Control
  PCWSTR ValueName; // registry value name
  PVOID  Destination; // kernel global receiving the data
  PULONG Length; // defaults to 4 bytes when NULL (optional)
  PULONG Type; // registry type (optional)
  ULONG_PTR Flags; // checked for ControlSetOverride (optional)
};
```

The function first opens the active control set and then the `control` key, means the key paths are relative to `HKLM\SYSTEM\CurrentControlSet\Control`.

```c
// CmpGetSystemControlValues

RtlInitUnicodeString(&DestinationString, L"current"); // active control set
ControlSet = CmpFindControlSet((ULONG_PTR)&CmControlHive, v7, (int)&DestinationString, (_BYTE *)&v28 + 1);
if ( ControlSet == -1 )
  KeBugCheckEx(0x74u, 1uLL, 2uLL, (ULONG_PTR)&CmControlHive, (ULONG_PTR)&DestinationString);

RtlInitUnicodeString(&DestinationString, L"control"); // "base key" for CmControlVector
SubKeyByName = CmpFindSubKeyByName((ULONG_PTR)&CmControlHive);
if ( SubKeyByName == -1 )
  KeBugCheckEx(0x74u, 1uLL, 3uLL, v10, (ULONG_PTR)&DestinationString);
```

Table walk related snippets:

```c
// CmpGetSystemControlValues

v3 = CmControlVector; // first table entry

if ( a3 != 1 || *((_BYTE *)v3 + 40) ) // low byte of Flags

v14 = CmpWalkPath((ULONG_PTR)&CmControlHive, SubKeyByName, *v3); // KeyPath

RtlInitUnicodeString(&DestinationString, v3[1]); // ValueName
ValueByName = CmpFindValueByName((int)&CmControlHive, v16, (int)&DestinationString);

v21 = (unsigned int *)v3[3]; // Length
v22 = 4;
if ( v21 )
  v22 = *v21;

if ( v13 && !(unsigned __int8)CmpGetBootValueData(0x80000000LL, v24, v3[2], v13) ) // Destination

v26 = v3[4]; // Type
if ( v26 )
  *(_DWORD *)v26 = *(_DWORD *)(v24 + 12);

v18 = (unsigned int *)v3[3];
if ( v18 )
  *v18 = v13;

v3 += 6; // next entry
```

See [cmcontrolvector-23h2.tsv](https://github.com/nohuto/win-config/blob/main/system/assets/reference/cmcontrolvector-23h2.tsv) & [cmcontrolvector-25h2.tsv](https://github.com/nohuto/win-config/blob/main/system/assets/reference/cmcontrolvector-25h2.tsv) for tables with key, value, global, init value.

### Examples

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power
; ValueName = CoalescingTimerInterval
; Destination = PopCoalescingTimerInterval
; Length/Type/Flags = 0

INIT:0000000140BA2B20                 dq offset aPower_2        ; "Power"
INIT:0000000140BA2B28                 dq offset aCoalescingtime ; "CoalescingTimerInterval"
INIT:0000000140BA2B30                 dq offset PopCoalescingTimerInterval
INIT:0000000140BA2B38                 dq 3 dup(0)
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Power
; ValueName = SleepStudyDisabled
; Destination = PopSleepStudyDisabled
; Length/Type/Flags = 0

INIT:0000000140BA1B00                 dq offset aSessionManager_4 ; "Session Manager\\Power"
INIT:0000000140BA1B08                 dq offset aSleepstudydisa   ; "SleepStudyDisabled"
INIT:0000000140BA1B10                 dq offset PopSleepStudyDisabled
INIT:0000000140BA1B18                 dq 3 dup(0)
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management
; ValueName = LargePageDrivers
; Destination = MmLargePageDriverBuffer
; Length = MmLargePageDriverBufferLength
; Type/Flags = 0

INIT:0000000140BA04B0                 dq offset aSessionManager_7 ; "Session Manager\\Memory Management"
INIT:0000000140BA04B8                 dq offset aLargepagedrive ; "LargePageDrivers"
INIT:0000000140BA04C0                 dq offset MmLargePageDriverBuffer
INIT:0000000140BA04C8                 dq offset MmLargePageDriverBufferLength
INIT:0000000140BA04D0                 align 20h
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\ProductOptions
; ValueName = ProductSuite
; Destination = CmSuiteBuffer
; Length = CmSuiteBufferLength
; Type = CmSuiteBufferType
; Flags = 0

INIT:0000000140BA3870                 dq offset aProductoptions_1 ; "ProductOptions"
INIT:0000000140BA3878                 dq offset aProductsuite ; "ProductSuite"
INIT:0000000140BA3880                 dq offset CmSuiteBuffer
INIT:0000000140BA3888                 dq offset CmSuiteBufferLength
INIT:0000000140BA3890                 dq offset CmSuiteBufferType
INIT:0000000140BA3898                 dq 0
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControSet\Control\Session Manager\Memory Management
; ValueName = VerifyDrivers
; Destination = MmVerifyDriverBuffer
; Length = MmVerifyDriverBufferLength
; Type = 0
; Flags = 1

INIT:0000000140BA0960                 dq offset aSessionManager_7 ; "Session Manager\\Memory Management"
INIT:0000000140BA0968                 dq offset aVerifydrivers ; "VerifyDrivers"
INIT:0000000140BA0970                 dq offset MmVerifyDriverBuffer
INIT:0000000140BA0978                 dq offset MmVerifyDriverBufferLength
INIT:0000000140BA0980                 dq 0
INIT:0000000140BA0988                 dq 1
```

## Registry Values

This includes details on several `HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\...` keys, not only the `Session Manager\\Kernel` key. See [diff](https://noverse.dev/diff) (globals) section for reference (or [disp-sym](https://noverse.dev/docs/windbg-notes/symbols/reading-symbols/#mass-display-symbols) if you want to display the current values). The comments of some values with more details are based on pseudocode, if so I added the function name to the end of the comment. Search for the function name in [decompiled-pseudocode/tree/main/11-23H2/ntoskrnl](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl).

| Prefix | Component |
| --- | --- |
| `Alpcp` | Advanced Local Procedure Calls |
| `Cc` | Cache Manager |
| `Cm` / `Cmp` | Configuration manager |
| `Dbgk` | Debugging Framework for user mode |
| `Ex` / `Exp` | Executive support routines |
| `Hvl` | Hypervisor library |
| `Io` / `Iop` | I/O manager |
| `Kd` / `Kdp` | Kernel debugger |
| `Ke` / `Ki` | Kernel / Kernel internal |
| `Mm` | Memory manager |
| `Ob` / `Obp` | Object manager |
| `Po` / `Pop` | Power manager |
| `Ppm` | Processor power manager |
| `Ps` / `Psp` | Process support |
| `Rtlp` | Run-time library |
| `Se` / `Sep` | Security Reference Monitor |
| `Vf` / `Vi` / `Dif*` | Driver Verifier |

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
    "AdjustDpcThreshold" = 20; // KiAdjustDpcThreshold, per CPU countdown value. When it reaches 1, it's reloaded and current DPC queue depth is incremented up to DpcQueueDepth ("number of clock ticks before DpcQueueDepth is incremented if DPCs are not pending")
    "AlwaysTrackIoBoosting" = 0; // PspAlwaysTrackIoBoosting enabling forces IO-boost tracking part in PsBoostThreadIoEx
    "AmdTprLowerInterruptDelayConfig" = 0; // KiAmdTprLowerInterruptDelayConfig
    "BoostingPeriodMultiplier" = 3; // 1-20, boost duration in clock quantums, KiNormalPriorityBoostingPeriodMultiplier
    "BugCheckUnexpectedInterrupts" = 0; // KiBugCheckUnexpectedInterrupts
    "CacheAwareScheduling" = 47; // bitmask,  KiCacheAwareScheduling
    "CacheErrataOverride" = 0; // KiTLBCOverride
    "CacheIsoBitmap" = 0; // KiCacheIsoBitmap
    "DebuggerIsStallOwner" = 0; // KiDebuggerIsStallOwner (KiSetDebuggerOwner)
    "DebugPollInterval" = 2000; // KiDebugPollInterval, if debugger enabled (KdDebuggerEnabled) timer path uses 10000 * value (KiGetNextTimerExpirationDueTime)
    "DefaultDynamicHeteroCpuPolicy" = 3; // KiDefaultDynamicHeteroCpuPolicy, behavior of Dynamic hetero policy All (0) (all available) Large (1) LargeOrIdle (2) Small (3) SmallOrIdle (4) Dynamic (5) (use priority and other metrics to decide) BiasedSmall (6) (use priority and other metrics, but prefer small) BiasedLarge (7).
    "DefaultHeteroCpuPolicy" = 5; // KiDefaultHeteroCpuPolicy
    "DeviceOwnerProtectionDowngradeAllowed" = 0; // SeDeviceOwnerProtectionDowngradeAllowed
    "DisableControlFlowGuardExportSuppression" = 0; // PspDisableControlFlowGuardExportSuppression
    "DisableControlFlowGuardXfg" = ? // MmDisableControlFlowGuardXfgOverride
    "DisableExceptionChainValidation" = 2; // PspSehValidationPolicy
    "DisableLightWeightSuspend" = 0; // KiDisableLightWeightSuspend, nonzero blocks lightweight suspend part in KiSuspendThread and uses the APC path (KiSuspendThread)
    "DisableLowQosTimerResolution" = 1; // KeDisableLowQosTimerResolution, uses ExpUpdateTimerResolution for specific processes etc? (PspSetProcessTimerResolutionPolicy)
    "DisablePointerParameterAlignmentValidation" = 0; // KiDisablePointerParameterAlignmentValidation
    "DisableTsx" = 0; // KiDisableTsx
    "DpcCumulativeSoftTimeout" = 120000; // KeDpcCumulativeSoftTimeoutMs, range 2000-DpcWatchdogPeriod, gets multiplied by KeVerifierDpcScalingFactor (KiInitDpcThresholds, KiApplyDpcVerificationScaleSettings)
    "DpcQueueDepth" = 4; // KiMaximumDpcQueueDepth, "Number of DPCs queued before an interrupt will be sent even for Medium or below DPCs"
    "DpcSoftTimeout" = 20000; // KeDpcSoftTimeoutMs, range 20-DPCTimeout, gets multiplied by KeVerifierDpcScalingFactor (KiInitDpcThresholds, KiApplyDpcVerificationScaleSettings)
    "DPCTimeout" = 20000; // KeDpcTimeoutMs, data 1-19 = 20, "specific DPC execution time limit control" (KiInitDpcThresholds)
    "DpcWatchdogPeriod" = 120000; // KeDpcWatchdogPeriodMs
    "DpcWatchdogProfileBufferSizeBytes" = 266240; // KeDpcWatchdogProfileBufferSizeBytes
    "DpcWatchdogProfileCumulativeDpcThreshold" = 110000; // KeDpcWatchdogProfileCumulativeDpcThresholdMs
    "DpcWatchdogProfileOffset" = 10000; // KeDpcWatchdogProfileOffsetMs
    "DpcWatchdogProfileSingleDpcThreshold" = 18333; // KeDpcWatchdogProfileSingleDpcThresholdMs
    "DriveRemappingMitigation" = 1; // ObpDriveRemappingMitigation
    "DynamicHeteroCpuPolicyExpectedRuntime" = 5200; // KiDynamicHeteroCpuPolicyExpectedRuntime
    "DynamicHeteroCpuPolicyImportant" = 2; // (LargeOrIdle)
    // Policy for a dynamic thread that is deemed important.
    "DynamicHeteroCpuPolicyImportantPriority" = 8; // KiDynamicHeteroCpuPolicyImportantPriority
    // Priority above which threads are considered important if prioritybased dynamic policy is chosen.
    "DynamicHeteroCpuPolicyImportantShort" = 3; // (Small)
    // Policy for dynamic thread that is deemed important but run a short amount of time.
    "DynamicHeteroCpuPolicyMask" = 7; // (foreground status = 1, priority = 2, expected run time = 4)
    // Determine what is considered in assessing whether a thread is important.
    "EnablePerCpuClockTickScheduling" = 0; // KiEnableClockTimerPerCpuTickScheduling, https://noverse.dev/docs/win-config/system/timer-expiration/#enablepercpuclocktickscheduling
    "EnableTickAccumulationFromAccountingPeriods" = 0; // KiEnableTickAccumulationFromAccountingPeriods, controls how CPU time used by threads etc. get counted?
                                                       // >= 2 = disabled (adds CPU time when clock ticks happen)
                                                       // 0/1/missing = enabled (measure time between accounting points)
    "EnableWerUserReporting" = 1; // DbgkEnableWerUserReporting, https://noverse.dev/docs/win-config/privacy/disable-wer/#enableweruserreporting
    "ForceBugcheckForDpcWatchdog" = 0; // KiForceBugcheckForDpcWatchdog
    "ForceForegroundBoostDecay" = 0; // KiSchedulerForegroundBoostDecayPolicy, https://noverse.dev/docs/win-config/system/priority-separation/#forceforegroundboostdecay
    "ForceIdleGracePeriod" = 5; // KiForceIdleGracePeriodInSec
    "ForceParkingRequested" = 1; // KiForceParkingConfiguration
    "GlobalTimerResolutionRequests" = 0; // KiGlobalTimerResolutionRequests
    "HeteroFavoredCoreFallback" = 0; // PpmHeteroFavoredCoreFallback
    "HeteroSchedulerOptions" = 0; // KiHeteroSchedulerOptions
    "HeteroSchedulerOptionsMask" = 0; // KiHeteroSchedulerOptionsMask
    "HgsPlusFeedbackUpdateThresholdNetRuntime" = 20;
    "HgsPlusFeedbackUpdateThresholdRuntime" = 20;
    "HgsPlusHigherPerfClassFeedbackThreshold" = 1;
    "HgsPlusInvalidFeedbackDefaultClass" = 0;
    "HgsPlusInvalidFeedbackDefaultClassSet" = 0;
    "HgsPlusInvalidFeedbackLimit" = 50;
    "HgsPlusLowerPerfClassFeedbackThreshold" = 4;
    "HgsPlusMinimumScoreDifferenceForSwap" = 25;
    "HgsPlusThreadCreationDefaultClass" = 0;
    "HotpatchTestMode" = 0; // KeHotpatchTestMode
    "HyperStartDisabled" = 0; // HvlVpStartDisabled, Hvl = Hypervisor library
    "IdealDpcRate" = 20; // KiIdealDpcRate, "Number of DPCs per clock tick before the maximum DPC queue depth is decremented if DPCs are pending but no interrupt was generated"
    "IdealNodeRandomized" = 1; // PspIdealNodeRandomized
    "InterruptSteeringFlags" = 0; // KiInterruptSteeringFlags
    "LongDpcQueueThreshold" = 3; // KiLongDpcQueueThreshold
    "LongDpcRuntimeThreshold" = 100; // KiLongDpcRuntimeThreshold
    "MaxDynamicTickDuration" = 8; // KiMaxDynamicTickDurationSize
    "MaximumCooperativeIdleSearchWidth" = 16; // KiMaximumCooperativeIdleSearchWidth
    "MaximumSharedReadyQueueSize" = 260; // KiMaximumSharedReadyQueueSize
    "MinimumDpcRate" = 3; // KiMinimumDpcRate, "Number of DPCs per clock tick where low DPCs will not cause a local interrupt to be generated"
    "MitigationAuditOptions" = 0; // PspSystemMitigationAuditOptions
    "MitigationOptions" = 0; // PspSystemMitigationOptions
    "ObCaseInsensitive" = 1; // ObpCaseInsensitive
    "ObObjectSecurityInheritance" = 0; // ObpObjectSecurityInheritance
    "ObTracePermanent" = 0; // ObpTracePermanent
    "ObTracePoolTags" = 0; // ObpTracePoolTagsBuffer / ObpTracePoolTagsLength
    "ObTraceProcessName" = 0; // ObpTraceProcessNameBuffer / ObpTraceProcessNameLength
    "ObUnsecureGlobalNames" = ?; // ObpUnsecureGlobalNamesBuffer / ObpUnsecureGlobalNamesLength (ObpIsUnsecureName)
    "PassiveWatchdogTimeout" = 300; // KiPassiveWatchdogTimeout
    "PerfIsoEnabled" = 0; // KiPerfIsoEnabled, cache isolation aware processor placement for threads whose scheduling group KSCB has RankBias set, range 0-64dec
    "PoCleanShutdownFlags" = 0; // PopShutdownCleanly
    "PowerOffFrozenProcessors" = 1; // KiPowerOffFrozenProcessors, seems unused (but initialized), was probably used to "power off" processors that are frozen (see windbg !frozen)
    "ReadyTimeTicks" = 6; // 6-70, ticks a thread has to be ready before it gets boosted, KiNormalPriorityBoostReadyTimeTicks
    "RebalanceMinPriority" = 1; // if _KTHREAD.Priority >= KiRebalanceMinPriority (or current _KPRCB.IdleState has 0x08 set, means that processor is soft parked), its scheduling group has CPU time available & _KTHREAD.Affinity allows an idle CPU in _KSCHEDULER_SUBNODE.IdleNonParkedCpuSet, KiQueueReadyThread continues through KiEnterDeferredReadyState/KiDeferredReadyThread/KiDeferredReadySingleThread for processor selection 
                                // otherwise KiAddThreadToReadyQueue uses the current CPU
                                // default uses all threads (prio 1-31) excluding zero page thread
    "ReservedCpuSets" = 0; // KiReservedCpuSets
    "ScanLatencyTicks" = 7; // 7-70, ticks between two scans, KiNormalPriorityBoostScanLatencyTicks
    "SchedulerAssistThreadFlagOverride" = 0; // KiSchedulerAssistThreadFlagOverride
    "SeAllowAllApplicationAceRemoval" = 0; // SepAllowAllApplicationAceRemoval
    "SeAllowSessionImpersonationCapability" = 0; // SepAllowSessionImpersonationCap
    "SeCompatFlags" = 0; // SeCompatFlags
    "SeLpacEnableWatsonReporting" = 0; // SeLpacEnableWatsonReporting, https://noverse.dev/docs/win-config/privacy/disable-wer/#selpacenablewatsonreporting
    "SeLpacEnableWatsonThrottling" = 1; // SeLpacEnableWatsonThrottling
    "SerializeTimerExpiration" = 1; // KiSerializeTimerExpiration, https://noverse.dev/docs/win-config/system/timer-expiration/#serializetimerexpiration
    "SeTokenDoesNotTrackSessionObject" = 0; // SeTokenDoesNotTrackSessionObject
    "SeTokenLeakDiag" = 0; // SeTokenLeakTracking
    "SeTokenSingletonAttributesConfig" = 3; // SepTokenSingletonAttributesConfig
    "SplitLargeCaches" = 0; // KiSplitLargeCaches
    "ThreadDpcEnable" = 1; // KeThreadDpcEnable
    "ThreadReadyCount" = 1; // 1-10, threads boosted per scan, KiNormalPriorityBoostMaximumThreadReadyCount
    "TimerCheckFlags" = 1; // REG_DWORD, KeTimerCheckFlags
    "VerifierDpcScalingFactor" = 1; // KeVerifierDpcScalingFactor
    "VirtualHeteroHysteresis" = 4294967295; // PpmPerfQosTransitionHysteresisOverride
    "VpThreadSystemWorkPriority" = 30; // KiVpThreadSystemWorkPriority
    "WpsSimulationOverride" = 0; // PpmWpsSimulationOverride / PpmWpsSimulationOverrideSize
    "XStateContextLookasidePerProcMaxDepth" = 0; // KiXStateContextLookasidePerProcMaxDepth

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\RNG";
    "RNGAuxiliarySeed" = ; // ExpRNGAuxiliarySeed, REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "AlpcMessageLog" = 0; // AlpcpMessageLogEnabled
    "AlpcWakePolicy" = 1; // AlpcpWakePolicyDefault
    "CriticalSectionTimeout" = 2592000;
    "CWDIllegalInDLLSearch" = 0; // PspCurDirDevicesSkippedForDlls, can cause "There was a problem starting PolicyAgentProvider.dll The specified module could not be found" if set to 0xFFFFFFFF (https://learn.microsoft.com/en-us/troubleshoot/mem/configmgr/client-installation/client-installation-fails-with-policyagentprovider-dll)
    "Debugger Retries" = 20; // KdpContext
    "DebuggerMaxModuleMsgs" = 500; // DbgkpMaxModuleMsgs, 0 is changed to 500 by DbgkpInitializePhase0
    "DisableIFEOCaching" = 0; // RtlpDisableIFEOCaching
    "ErrorPortCommTimeout" = 10000; // DbgkErrorPortCommTimeout
    "ErrorPortStartTimeout" = 15000; // DbgkErrorPortStartTimeout
    "GlobalFlag" = 0; // CmNtGlobalFlag <> 0x7061006c ? https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/gflags-details
    "GlobalFlag2" = 0; // CmNtGlobalFlag2 <> 0x6c642e30 ?
    // lkd> !gflag
    // Current NtGlobalFlag contents: 0x00000000
    // Current NtGlobalFlag2 contents: 0x00000000
    "HeapSegmentReserve" = 1048576; // REG_DWORD, range 65536-16580608, 65536 steps
    "HeapSegmentCommit" = 8192; // REG_DWORD, range 4096-16580608, 4096 steps
    "HeapDeCommitFreeBlockThreshold" = 4096; // REG_DWORD, range 0-4294967280, 16 steps
    "HeapDeCommitTotalFreeThreshold" = 65536; // REG_DWORD, range 0-4294967280, 16 steps
    "ImageExecutionOptions" = 0; // ViImageExecutionOptions
    "InitConsoleFlags" = 0; // InitConsoleFlags
    "MultiUsersInSessionSupported" = 0; // RtlpMultiUsersInSessionSupported
    "ObjectSecurityMode" = 1; // ObpObjectSecurityMode
    "PowerSimulateHiberBugcheck" = 4294967295; // PopSimulateHiberBugcheck
    "PowerPolicySimulate" = 0; // PopSimulate
    "ProtectionMode" = 1; // ObpProtectionMode, REG_DWORD
    "ResourceCheckFlags" = 3; // REG_DWORD, ExResourceCheckFlags
    "ResourceEnforceOwnerTransfer" = 0; // ExpResourceEnforceOwnerTransfer
    "ResourceTimeoutCount" = 45; // ExResourceTimeoutCount
    "SkipRegistryInit" = 0; // CmNtSkipRegistryInit

    // procmon boot trace
    "ObjectDirectories" = \Windows, \RPC Control; // ? - REG_MULTI_SZ
    "BootExecute" = ?; // REG_SZ
    "BootExecuteNoPnpSync" = ?;
    "PlatformExecute" = ?;
    "SetupExecute" = ?;
    "SetupExecuteNoPnpSync" = ?;
    "S0InitialCommand" = ?;
    "NumberOfInitialSessions" = 2; // ? - REG_DWORD
    "PendingFileRenameOperations" = ?;
    "PendingFileRenameOperations2" = ?;
    "AllowProtectedRenames" = ?;
    "ClearTempFiles" = ?;
    "TempFileDirectory" = ?;
    "ExcludeFromKnownDlls" = ?; // REG_MULTI_SZ
    "BackgroundLoadKnownDlls" = 0;
    "DisableWpbtExecution" = 0; // REG_DWORD (bool), https://noverse.dev/docs/win-config/security/disable-wpbt/
    "RaiseExceptionOnPossibleDeadlock" = ?;
    "ResourcePolicies" = ?;
    "SafeDllSearchMode" = ?; // https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order#standard-search-order-for-unpackaged-apps
    "SafeProcessSearchMode" = ?;
    "SmtDelayBaseYield" = ?;
    "SmtDelayMaxYield" = ?;
    "SmtDelaySleepLoopWindowSize" = ?;
    "SmtDelaySpinCountThreshold" = ?;
    "SmtFactorYield" = ?;
    "SystemUpdateOnBoot" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Quota System";
    "ApplicationBlockedMessageLimit" = 50; // PspJobNoWakeChargeLimit
    "JobTimeLimitsPeriodSeconds" = 7; // PspJobTimeLimitsPeriodSeconds
    "SystemBlockedMessageLimit" = 200; // PspSystemNoWakeChargeLimit

    // DFSS = Dynamic, fair share scheduling
    // "Dynamic fair share scheduling (DFSS) is a mechanism that can be used to fairly distribute CPU time among sessions running on a machine. It prevents one session from potentially monopolizing the CPU if some threads running under that session have a relatively high priority and run a lot."
    // Means whenever you only use a single account/session (which you most likely do, use "query session"), this has no impact for you
    "DfssGenerationLengthMS" = 600; // PsDfssGenerationLengthMS, "The generation time over which to track CPU usage"
    "DfssLongTermFraction1024" = 512; // sDfssLongTermFraction1024, "The value used in a formula for an exponential moving average used for long-term cycles computation"
    "DfssLongTermSharingMS" = 15; // PsDfssLongTermSharingMS, "The time it takes to jump from rank 0 to a non-zero rank when the threads exceed their quota within the generation cycle"
    "DfssResolutionMS" = 4294967295; // PsDfssDesiredTimerResolutionMs
    "DfssShortTermSharingMS" = 30; // PsDfssShortTermSharingMS, "The time it takes for the group rank to increase within a generation cycle"
    "EnableCpuQuota" = 0; // nonzero = DFSS enabled, if enabled PsCpuFairShareEnabled is TRUE
                          // lkd> db nt!PsCpuFairShareEnabled L1
                          // fffff807`21f1eaa0  00                                               .

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management";
    "AllocationPreference" = 0;
    "AllowUserHotPatchWithoutVbs" = 0;
    "CacheUnmapBehindLengthInMB" = 8; // MB, range 1-128
    "CustomDTPDenominator" = 8; // CcClientDTPDenominator
    "DeadlockRecursionDepthLimit" = 0; // ViRecursionDepthLimitFromRegistry
    "DeadlockSearchNodesLimit" = 0; // ViSearchedNodesLimitFromRegistry
    "DifPluginConfigData" = ?; // 24H2 VfInitBootDriversLoaded copies DifPluginConfigData using DifPluginConfigDataLength?
    "DisableCacheTelemetry" = 2; // CcDisableTelemetryRegKeyAtInit
    "DisablePageCombining" = 0;
    "DisablePagingExecutive" = 0;
    "EnableAsyncLazywrite" = 2; // CcEnableAsyncLazywriteOverride
    "EnableAsyncLazywriteMulti" = 2; // CcEnableAsyncLazywriteMultiOverride
    "EnableCooling" = 0;
    "EnablePerVolumeLazyWriter" = 2; // CcEnablePerVolumeLazyWriterOverride
    "ForceValidateIo" = 0;
    "HighMemoryThreshold" = 0;
    "KernelPadSectionsOverride" = 0;
    "LargePageDrivers" = ?; // MmLargePageDriverBuffer, maximum length 1024 bytes
    "LargeWriteSize" = 0; // CcAzure_LargeWriteSize
    "LazyWriterPercentageOfNumProcs" = 0; // CcAzure_LazyWriterPercentageOfNumProcs
    "LowMemoryThreshold" = 0; // qword_140FC3230
    "MaxLazyWritePages" = 0; // CcMaxLazyWritePagesOverride
    "MinimumStackCommitInBytes" = 0;
    "Mirroring" = 0;
    "ModifiedWriteMaximum" = ?;
    "MoveImages" = 1; // MmRegistryState
    "NonPagedPoolQuota" = 4294967295; // PspDefaultResourceLimits
    "PagedPoolQuota" = ?; // unk_140FD7DE4
    "PageValidationAction" = 0; // MmPageValidationAction
    "PageValidationFrequency" = 0; // MmPageValidationFrequency
    "PagingFileQuota" = ?; // unk_140FD7DE8
    "PhysicalMemoryMapperEnforcementMode" = 0;
    "PoolForceFullDecommit" = 0; // PoolForceFullDecommit
    "PoolTag" = 0; // MmSpecialPoolTag, https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/gflags-details
    "PoolTagOverruns" = 1; // MmSpecialPoolCatchOverruns
    "PoolTagSmallTableSize" = 4097; // PoolTrackTableSize
    "ProtectNonPagedPool" = 0; // MmProtectFreedNonPagedPool
    "RemoteFileDirtyPageThreshold" = 1310720; // CcRemoteFileDPInlineFlushThreshold, "This value determines the maximum number of dirty pages in the cache (on a per file basis) for a remote write before an inline flush is performed."
    "SimulateCommitSavings" = 0;
    "SoftThrottleDelayInMs" = 0; // CcAzure_SoftThrottleDelayInMs
    "SoftThrottleLargeWriteAtPct" = 0; // CcAzure_SoftThrottleLargeWriteAtPct
    "SpecialPurposeMemoryPages" = 0; // MmSpecialPurposeMemoryPages
    "SpecialPurposeMemoryStartPage" = 0; // MmSpecialPurposeMemoryStartPage
    "SpecialPurposeMemoryStartPageValueSize" = 4294967295; // MmSpecialPurposeMemoryStartPageValueSize
    "TopBottomDPTEqual" = 0; // CcAzure_TopBottomDPTEqual
    "TrackLockedPages" = 0; // MmTrackLockedPages
    "TrackPtes" = 0;
    "VerifierDifPoolTags" = 0; // DifpPoolTags
    "VerifierDifPoolTagsSizeBytes" = 4294967295; // DifpPoolTagsSizeBytes
    "VerifierFaultApplications" = ?;
    "VerifierFaultBootMinutes" = 8; // VfFaultInjectionBootMinutes
    "VerifierFaultProbability" = 600; // VfFaultInjectionProbability
    "VerifierFaultTags" = 0; // VerifierFaultTagsBuffer
    "VerifierFaultTagsSize" = 4294967295; // VerifierFaultTagsBufferSize
    "VerifierHandleTraces" = 16384; // VfHandleTracingEntries
    "VerifierIrpStackTraces" = 16384; // IovIrpTracesLength
    "VerifierIrpTimeout" = 0; // VfWdIrpTimeoutMsec
    "VerifierNewRuleWorkaround" = 0; // VerifierNewRuleWorkaround
    "VerifierOptions" = 0; // VfOptionFlags
    "VerifierPoolTracesLength" = 0; // VfPoolTracesLength
    "VerifierRandomTargets" = 0; // VfRandomVerifiedDrivers
    "VerifierSettingState" = 0; // VfRuleClasses
    "VerifierSettingStateSize" = 4294967295; // VfRuleClassesSize
    "VerifierTipDisable" = 0; // VerifierTipDisable
    "VerifierTipLimitDenominator" = 0; // DifiPluginControlDenominator
    "VerifierTipLimitNumerator" = 0; // DifiPluginControlNumerator
    "VerifierTipSparseness" = 0; // DifiPluginControlSparseness
    "VerifierTriageContext" = 0; // VfTriageContext
    "VerifyBTSBufferSize" = 0; // ViVerifyBTSBufferSize
    "VerifyDriverLevel" = 4294967295; // MmVerifyDriverLevel
    "VerifyDrivers" = ?;
    "VerifyDriversSuppress" = ?;
    "VerifyMode" = 4; // VfVerifyMode
    "VerifyTriage" = 4294967295; // ViVerifyTriage
    "VerifyTriageRules" = 0; // ViVerifyTriageRules
    "VerifyTriageRulesSize" = 4294967295; // ViVerifyTriageRulesSize
    "VmPauseOutswapSizeCapMB" = 512; // VmPauseOutswapSizeCapMB
    "WorkingSetPagesQuota" = ?; // unk_140FD7DEC
    "WorkingSetSwapSharedPages" = 0; // PspOutSwapSharedPages
    "XdvTipTag" = 0; // CarTipTag
    "XdvVerifierOptions" = 0; // CarXdvOptions
    "XdvVerifierOptions" = 0; // VfFlightOptions

    // procmon boot trace
    "PagingFiles" = C:\pagefile.sys <int> <int> // REG_MULTI_SZ
    "PagefileOnOsVolume" = ?; // 4,094
    "WaitForPagingFiles" = ?; // 4,094
    "ExistingPageFiles" = \??\C:\pagefile.sys; // REG_MULTI_SZ
    "DisableDedicatedMemoryCaching" = ?;
    "DedicatedMemoryPagefileSizeMB" = ?
    "PagefileHybridPriority" = ?;
    "SwapfileControl" = ?;
    "SwapFile" = ?;
    "TempPageFile" = ?;
    "FeatureSettings" = ? // DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Executive";
    "AdditionalCriticalWorkerThreads" = 0; // ExpAdditionalCriticalWorkerThreads
    "AdditionalDelayedWorkerThreads" = 0; // ExpAdditionalDelayedWorkerThreads
    "CoverageMaxPagedPool" = 4194304; // ExCovMaxPagedPoolToUse
    "ForceEnableMutantAutoboost" = 0; // ExpForceEnableMutantAutoboost
    "KernelWorkerTestFlags" = 0; // ExpWorkerQueueTestFlags
    "MaximumKernelWorkerThreads" = 4096; // ExpMaximumKernelWorkerThreads
    "MaxTimeSeparationBeforeCorrect" = 60; // ExpMaxTimeSeperationBeforeCorrect
    "WorkerFactoryThreadCreationTimeout" = 10; // ExpWorkerFactoryThreadCreationTimeoutInSeconds
    "WorkerFactoryThreadIdleTimeout" = 67; // ExpWorkerFactoryThreadIdleTimeoutInSeconds
    "WorkerThreadTimeoutInSeconds" = 600; // ExpWorkerThreadTimeoutInSeconds
    "TickcountRolloverDelay" = ; // ?

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "FlushPolicy" = 0; // PopFlushPolicy
    "IdleScanInterval" = 30; // PopIdleScanInterval
    "SkipTickOverride" = 1; // PopSkipTickPolicy
    "SleepStudyDeviceAccountingLevel" = 4; // PopSleepStudyDeviceAccountingLevel
    "SleepStudyDisabled" = 0; // PopSleepStudyDisabled
    "WatchdogResumeTimeout" = 120; // PopWatchdogResumeTimeout
    "WatchdogSleepTimeout" = 300; // PopWatchdogSleepTimeout
    "Win32CalloutWatchdogBugcheckEnabled" = 0; // PopWin32CalloutWatchdogBugcheckEnabled

    // PopOpenPowerKey
    "AwayModeEnabled" = 0; // REG_DWORD, range 0-1
    "HiberbootEnabled" = 1; // REG_DWORD, range 0-1
    "KernelResumeIoCpuTime" = 0; // REG_DWORD, milliseconds, range 0-4294967295
    "MaxHuffRatio" = 1; // REG_DWORD, range 1-98
    "MultiPhaseResumeDisabled" = 0; // REG_DWORD, range 0-1
    "SystemPowerPolicy" = "<STRUCT 232 BYTES>"; // REG_BINARY

    // HybridBootAnimationTime records the boot animation duration during fast boot, HiberIoCpuTime is CPU time spent on hibernation I/O during resume, ResumeCompleteTimestamp is the system timestamp when resume from hibernation completed. So all of them are just counters and changing their data won't affect the boot.
    "HybridBootAnimationTime" = 1601; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "HiberIoCpuTime" = 0; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "ResumeCompleteTimestamp" = 0; // REG_QWORD, range 0-0xFFFFFFFFFFFFFFFF

    // PpmInitIllegalThrottleLogging
    "ProcessorThrottleLogInterval" = 10000; // REG_DWORD, milliseconds, range 0-10000 (values >10000 are clamped to 10000)

    // procmon boot trace
    "SleepStudyBufferSizeInMB" = ?;
    "SleepStudyHistoryDays" = ?;
    "SleepStudyPerfTrackDripsThresholdPercentage" = ?;
    "SleepStudyTraceDirectory" = ?;

"HKLM\\System\\CurrentControlSet\\Control\\Session Manager\\Throttle";
    "PerfEnablePackageIdle" = 0;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Segment Heap";
  "Enabled"; // REG_DWORD, 0 = disable, nonzero = enable (global)

// Miscellaneous values

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\LSA";
    "AuditBaseDirectories" = 0; // ObpAuditBaseDirectories
    "AuditBaseObjects" = 0; // ObpAuditBaseObjects

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\LSA\\audit";
    "ProcessAccessesToAudit" = 0; // SepProcessAccessesToAudit

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation";
    "ActiveTimeBias" = ?;
    "Bias" = 480; // ExpAltTimeZoneBias
    "RealTimeIsUniversal" = 0; // ExpRealTimeIsUniversal

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\I/O System";
    "DisableDiskCounters" = 0; // PsDisableDiskCounters
    "IoAllowLoadCrashDumpDriver" = 0; // IopAllowLoadCrashDumpDriver
    "IoBlockLegacyFsFilters" = 0; // IopBlockLegacyFsFilters
    "IoCaseInsensitive" = 1; // IopCaseInsensitive
    "IoEnableSessionZeroAccessCheck" = 0; // IopSessionZeroAccessCheckEnabled
    "IoFailZeroAccessCreate" = 1; // IopFailZeroAccessCreate
    "IoIrpCompletionTimeoutInSeconds" = 300; // IopIrpCompletionTimeoutInSeconds
    "IoKeepAliveTimeMs" = 5000; // IopKeepAliveTimeMs
    "LargeIrpStackLocations" = 14; // IopLargeIrpStackLocations
    "MediumIrpStackLocations" = 2; // IopMediumIrpStackLocations
    "RequireDeviceAccessCheck" = 1; // IopRequireDeviceAccessCheck

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager";
    "BugcheckRecoveryEnabled" = 0; // CmBugcheckRecoveryEnabled
    "CallbackMemoryFromPerProcLookaside" = 1; // CmpAllocateCallbackMemoryFromPerProcLookaside
    "CallbackMemoryFromPool" = 0; // CmpAllocateCallbackMemoryFromPool
    "DelayCloseSize" = 2048; // CmpDelayedCloseSize
    "EnablePeriodicBackup" = 0; // CmpDoIdleProcessing, https://learn.microsoft.com/en-us/troubleshoot/windows-client/installing-updates-features-roles/system-registry-no-backed-up-regback-folder#more-information
    "FastBoot" = 1; // CmFastBoot
    "FreezeThawTimeoutInSeconds" = 60; // CmFreezeThawTimeoutInSeconds
    "RegistryFlushGlobalFlags" = 0; // CmpGlobalFlushControlFlags
    "RegistryLazyFlushBootDelay" = 60; // CmpEnableLazyFlushBootDelayInterval
    "RegistryLazyFlushInterval" = 60; // CmpLazyFlushIntervalInSeconds
    "RegistryLazyLocalizeInterval" = 60; // CmpLazyLocalizeIntervalInSeconds
    "RegistryLazyReconcileInterval" = 3600; // CmpLazyReconcileIntervalInSeconds
    "RegistryLogFileSizeCap" = 0; // CmpLogFileSizeCap
    "RegistryReorganizationLimit" = 1048576; // CmpReorganizeLimit
    "RegistryReorganizationLimitDays" = 7; // CmpReorganizeDelayDays
    "SelfHealingEnabled" = 1; // CmSelfHeal
    "SystemHiveLimitSize" = 1610612736; // CmSystemHiveLimitSize
    "VirtualizationEnabled" = 1; // CmVEEnabled
    "VolatileBoot" = 0; // CmpVolatileBoot

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager\\LastKnownGood";
    "Enabled" = 0; // CmpLKGEnabled

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\QoS";
    "StorageBaseIOSize" = 8192; // IopDiskIoAttributionBaseIoSize

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StateSeparation\\Policy";
    "AllHivesVolatile" = 0; // CmStateSeparationAllHivesVolatile
    "DevelopmentMode" = 0; // CmStateSeparationDevMode
    "Enabled" = 0; // CmStateSeparationEnabled

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\ValidationRunlevels";
    "Global" = 1210938368; // CmGlobalValidationRunlevel

"HKLM\\System\\CurrentControlSet\\Control\\Processor";
    "AllowGuestPerfStates" = 0;
    "AllowPepPerfStates" = 0;
    "Capabilities" = 0; // REG_QWORD
    "DisableAsserts" = 0;
    "Overrides" = 0;
```

### Capabilities

`Globals[0]` is the capability mask that shows what the system supports, `qword_1C00124C8` = `Capabilities` value. `Globals[0] &= ~qword_1C00124C8` removes active capability bits which are set in the registry value, so `Capabilities` is a kind of disable mask.

```c
// ProcLibGlobalInit

GetRegistryQwordValue(v13, v12, &qword_1C00124C8); // Capabilities var


if ( qword_1C00124C8 )
{
  DisplayPPMFlags(~qword_1C00124C8, 5u);
  Globals[0] &= ~qword_1C00124C8;
}
```

#### DisplayPPMFlags

Most masks below are the same for `amdppm`/`intelppm`, the labels are from [`DisplayPPMFlags`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/DisplayPPMFlags.c) WPP metadata extracted via [`tracepdb`](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/tracepdb).

| Mask | `DisplayPPMFlags` label |
| --- | --- |
| `0x0000000000000001` | ACPI 1.0 C1 |
| `0x0000000000000002` | ACPI 1.0 C2 |
| `0x0000000000000004` | ACPI 1.0 C3 |
| `0x0000000000100000` | ACPI 1.0 IO TStates |
| `0x0000000000200000` | ACPI 1.0 MP TStates |
| `0x0000000000000010` | ACPI 2.0+ C1 |
| `0x0000000000000020` | ACPI 2.0+ C2 |
| `0x0000000000000040` | ACPI 2.0+ C3 |
| `0x000000000007F000` | ACPI 2.0+ MWAIT C-States |
| `0x0000080000000000` | ACPI 2.0+ LPI states IO |
| `0x0000020000000000` | ACPI 2.0+ LPI states MW |
| `0x0000040000000000` | ACPI 2.0+ LPI states PSCI |
| `0x00000E0000000000` | ACPI 2.0+ LPI states |
| `0x0000000001000000` | ACPI 2.0+ TStates IO |
| `0x0000000002000000` | ACPI 2.0+ TStates FFH |
| `0x0000000010000000` | ACPI 2.0+ PStates IO |
| `0x0000000020000000` | ACPI 2.0+ PStates FFH |
| `0x0000000040000000` | ACPI 2.0+ PStates XPSS |
| `0x0000000080000000` | ACPI 2.0+ Legacy PCC |
| `0x0000000008000000` | ACPI 2.0+ CPC |
| `0x0000004000000000` | ACPI 2.0+ CPC Interrupt (not used by `amdppm`?) |
| `0x0000000004000000` | ACPI 2.0+ HW Feedback |
| `0x0000000100000000` | PEP Mini-PEP Idle |
| `0x0000000200000000` | PEP Micro-PEP Idle |
| `0x0000000000000300` | PEP C-State Idle |
| `0x0000100000000000` | PEP LPI Idle |
| `0x0000000000000400` | PEP Park pref |
| `0x0000001000000000` | PEP Perf states |
| `0x0000010000000000` | PEP Notifications |
| `0x0000200000000000` | Driver Hidden Processors |
| `0x0000400000000000` | Driver VM Perf Control (not used by `amdppm`?) |
| `0x0000000800000000` | Driver Hardware Debug |
| `0x0000002000000000` | Driver Energy Estimation |

Additional masks I found that aren't in `DisplayPPMFlags`:

| Mask | Meaning |
| --- | --- |
| [`0x0000000000800000`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/InitAcpiProcessorDomains.c) | ACPI processor domain init |
| [`0x00000010FF300000`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/ValidatePerfDomainSymmetry.c) | performance domain validation/registration |
| [`0x0000800000000000`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/EmiInit.c) | EMI init |
| [`0x0001000000000000`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/intelppm/InitDriver.c) | Energy counter init (not used by `amdppm`?) |

#### tracepdb

Short explanation of how to get the `DisplayPPMFlags` labels:

```powershell
.\tracepdb.exe -f "C:\Symbols\amdppm.pdb\0728D8E84177E8B0FCF8B265B1C92A591\amdppm.pdb" -p "$env:USERPROFILE\Desktop\tmf" -v
```

In [`DisplayPPMFlags`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/DisplayPPMFlags.c) you can see the many masks + GUIDs + hex numbers, example:

```c
if ( a2 < 5u
  || LOWORD(WPP_GLOBAL_Control->DeviceType) )
{
  if ( (a1 & 0x2000000000LL) == 0 ) // mask
    v4 = "Dis";
  WPP_RECORDER_SF_s(
    (__int64)WPP_GLOBAL_Control->DeviceExtension,
    a2,
    2u,
    0x64u, // 100
    (__int64)&WPP_6d86976f8bee3b8eeb87bd96dd02b852_Traceguids, // 6d86976f-8bee-3b8e-eb87-bd96dd02b852.tmf
    v4);
}
```

```
}
#typev Unknown_cxx00 100 "%0  Energy Estimation  = %10!s!abled" //   LEVEL=DbgLevel FLAGS=PLATFORMINFO FUNC=DisplayPPMFlags
{
```

#### Default Data & Globals

See '[DriverStart + RVAs](https://noverse.dev/docs/win-config/system/mmcss-values/#driverstart--rvas)' whenever you want to read the current value on your system (you can get the variable name by looking at callers of `GetRegistryQwordValue` in `amdppm`/`intelppm`).

```c
lkd> lm m amdppm
Browse full module list
start             end                 module name
fffff801`a9130000 fffff801`a9176000   amdppm     (pdb symbols)          C:\ProgramData\Dbg\sym\amdppm.pdb\0728D8E84177E8B0FCF8B265B1C92A591\amdppm.pdb

// .data:00000001C00124C8 qword_1C00124C8 dq 0

lkd> dq fffff801`a91424c8 L1
fffff801`a91424c8  00000000`00000000
```

```c
// .data:00000001C00124C0 Globals         dq 0

lkd> dq fffff801`a91424c0 L1
fffff801`a91424c0  0000bb8c`bdd7f677
```

### TimerCheckFlags

```asm
INIT:0000000140BA1A70                 dq offset aSessionManager_5 ; "Session Manager\\Kernel"
INIT:0000000140BA1A78                 dq offset aTimercheckflag ; "TimerCheckFlags"
INIT:0000000140BA1A80                 dq offset KeTimerCheckFlags
INIT:0000000140BA1A88                 align 20h
```

`KeTimerCheckFlags` is used by [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeCheckForTimer.c), only bit `0` seems to be meaningful, means any value with that bit set should behave like `1`.

#### [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeCheckForTimer.c)

That function checks active timer tables for a timer object/DPC object/DPC routine related to the memory range being checked.

```c
// KeCheckForTimer

result = KeTimerCheckFlags;
if ( (KeTimerCheckFlags & 1) != 0 ) // bit 0 set = check enabled
{
  BugCheckParameter4 = BugCheckParameter3 + a2; // end of the checked range
  result = KeQueryActiveProcessorCountEx(0xFFFFu); // active processor count
```

If `KeTimerCheckFlags & 1` isn't set, the function returns without checking timer tables. When enabled, it checks each active processors timer tables for these addresses:

```c
// KeCheckForTimer

if ( v16 > v15 && v16 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 0LL, v16, BugCheckParameter3, BugCheckParameter4); // timer object (parameter 1 = 0x0)

if ( v17 > v15 && v17 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 1uLL, v17, BugCheckParameter3, BugCheckParameter4); // DPC object (parameter 1 = 0x1)

if ( v18 >= BugCheckParameter3 && v18 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 2uLL, v18, BugCheckParameter3, BugCheckParameter4); // DPC routine (parameter 1 = 0x2)
```

The second argument to `KeBugCheckEx` = parameter 1 in the `0xC7` ([`TIMER_OR_DPC_INVALID`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/bug-check-0xc7--timer-or-dpc-invalid)) bugcheck.

```cpp
VOID KeBugCheckEx(
  [in] ULONG     BugCheckCode,
  [in] ULONG_PTR BugCheckParameter1,
  [in] ULONG_PTR BugCheckParameter2,
  [in] ULONG_PTR BugCheckParameter3,
  [in] ULONG_PTR BugCheckParameter4
);
```

##### [TIMER_OR_DPC_INVALID](https://github.com/MicrosoftDocs/windows-driver-docs/blob/staging/windows-driver-docs-pr/debugger/bug-check-0xc7--timer-or-dpc-invalid.md)

*The `TIMER_OR_DPC_INVALID` bug check has a value of `0x000000C7`. This is issued if a kernel timer or deferred procedure call (DPC) is found somewhere in memory where it is not permitted. This condition is usually caused by a driver failing to cancel a timer or DPC before freeing the memory where it resides.*

| Parameter 1 | Parameter 2 | Parameter 3 | Parameter 4 | Cause of error |
| --- | --- | --- | --- | --- |
| `0x0` | Address of the timer object | Start of memory range being checked | End of memory range being checked | The timer object was found in a block of memory where a timer object is not permitted. . |
| `0x1` | Address of the DPC object | Start of memory range being checked | End of memory range being checked | The DPC object was found in a block of memory where a DPC object is not permitted. |
| `0x2` | Address of the DPC routine | Start of memory range being checked | End of memory range being checked | The DPC routine was found in a block of memory where a DPC object is not permitted. |
| `0x3` | Address of the DPC object | Processor number | Number of processors in the system | The processor number for the DPC object is not correct. |
| `0x4` | Address of the DPC routine | The thread's APC disable count before the kernel calls the DPC routine | The thread's APC disable count after the DPC routine is called | The thread's APC disable count was changed during DPC routine execution.<br><br>The APC disable count is decremented each time a driver calls **KeEnterCriticalRegion**, **FsRtlEnterFileSystem**, or acquires a mutex.<br><br>The APC disable count is incremented each time a driver calls **KeLeaveCriticalRegion**, **KeReleaseMutex**, or **FsRtlExitFileSystem**. |
| `0x5` | Address of the DPC routine | The thread's APC disable count before the kernel calls the DPC routine | The thread's APC disable count after the DPC routine is called | The thread's APC disable count was changed during the execution of timer DPC routine.<br><br>The APC disable count is decremented each time a driver calls **KeEnterCriticalRegion**, **FsRtlEnterFileSystem**, or acquires a mutex.<br><br>The APC disable count is incremented each time a driver calls **KeLeaveCriticalRegion**, **KeReleaseMutex**, or **FsRtlExitFileSystem**. |

##### Callers

Pool free checks (in [ExpFreePoolChecks](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/ExpFreePoolChecks.c) & [ExFreeHeapPool](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/ExFreeHeapPool.c)) call [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeCheckForTimer.c) (only when `ExpPoolFlags & 1` is set?):

```c
// ExpFreePoolChecks / ExFreeHeapPool

if ( (ExpPoolFlags & 1) != 0 )
  KeCheckForTimer(BugCheckParameter3);
```

[VfMiscKeInitializeTimerEx_Entry](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/VfMiscKeInitializeTimerEx_Entry.c) calls [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeCheckForTimer.c) for the timer object range ([only until `11-23H2`](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-25H2&module=ntoskrnl&name=KeCheckForTimer.c&mode=side-by-side), builds above use [ViMiscValidateSynchronizationObject](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/ViMiscValidateSynchronizationObject.c)).

```c
// VfMiscKeInitializeTimerEx_Entry (23H2)

if ( (VfRuleClasses & 0x400000) == 0 )
  return KeCheckForTimer(*(_QWORD *)(a1 + 16), 64LL); // timer object 64 byte range check
```

```c
// VfMiscKeInitializeTimerEx_Entry (25H2)

return ViMiscValidateSynchronizationObject(*(_QWORD *)(a1 + 16));
```

### ResourceCheckFlags

```asm
INIT:0000000140BA36C0                 dq offset aSessionManager_11 ; "Session Manager"
INIT:0000000140BA36C8                 dq offset aResourcecheckf ; "ResourceCheckFlags"
INIT:0000000140BA36D0                 dq offset ExResourceCheckFlags
INIT:0000000140BA36D8                 dq 3 dup(0)
```

`ResourceCheckFlags` is related to [`TimerCheckFlags`](https://noverse.dev/docs/win-config/system/kernel-values/#timercheckflags) as both control checks for kernel objects left inside pool memory being freed, they're independent of each other as they use different `ExpPoolFlags` bits. Note that this check only runs on a single processor system.

| Data | Meaning |
| --- | --- |
| `0` (or any even value) | `ERESOURCE` check disabled |
| `3` (or any odd value) | `ERESOURCE` check enabled |

Only bit `0` of the value is read which is why any even/odd value would work.

```c
// ExpFreePoolChecks / ExFreeHeapPool

if ( (ExpPoolFlags & 1) != 0 )
  KeCheckForTimer(BugCheckParameter3); // TimerCheckFlags (timer/DPC check)
if ( (ExpPoolFlags & 4) != 0 )
  ExpCheckForResource(BugCheckParameter3, a3); // ResourceCheckFlags (ERESOURCE check)
```

[ExpCheckForResource](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/ExpCheckForResource.c) checks whether the freed range contains an `ERESOURCE` still linked in `ExpSystemResourcesList`, means `ExDeleteResourceLite` wasn't called before freeing its memory.

```c
// ExpCheckForResource

if ( ((MmVerifierData & 0x800) == 0
   || (MmVerifierData & 0x10) == 0
   || !(unsigned int)VfCheckForResource((ULONG_PTR)a1, a2))
  && (unsigned int)KeNumberProcessors_0 <= 1 // one processor
  && (ExResourceCheckFlags & 1) != 0 ) // bit 0 enables check
{
  v4 = ExAcquireSpinLockShared(&ExpResourceSpinLock);
  v5 = (__int64 *)ExpSystemResourcesList;
  v6 = v4;
  while ( v5 != &ExpSystemResourcesList )
  {
    if ( v5 >= a1 && v5 < (__int64 *)((char *)a1 + a2) ) // listed ERESOURCE inside freed range
    {
      DbgPrintEx(
        0,
        0,
        "EX: ExFreePool( %p, %Ix ) contains an ERESOURCE structure that has not been ExDeleteResourced\n",
        a1,
        a2);
      __debugbreak();
    }
    v5 = (__int64 *)*v5;
  }
}
```

### ThreadDpcEnable

```asm
INIT:0000000140BA14A0                 dq offset aSessionManager_5 ; "Session Manager\\Kernel"
INIT:0000000140BA14A8                 dq offset aThreaddpcenabl ; "ThreadDpcEnable"
INIT:0000000140BA14B0                 dq offset KeThreadDpcEnable
INIT:0000000140BA14B8                 dq 3 dup(0)
```

Has a default of `1`, and is a kind of bool, `>1` data is probably the same as `1`.

```c
lkd> dd nt!KeThreadDpcEnable L1
fffff806`6d11d17c  00000001
```

It seems to also be possible to dump the state via the [KPRCB structure](https://noverse.dev/docs/windbg-notes/system-mechanisms/processor-execution-model/processor-control-region/#_kprcb-structure) (per processor):

```c
lkd> !prcb // processor 0
PRCB for Processor 0 at fffff8026b2a4180:
Current IRQL -- 0
Threads--  Current ffff80025babc080 Next 0000000000000000 Idle fffff8026dd4d700
Processor Index 0 Number (0, 0) GroupSetMember 1
Interrupt Count -- 0001f496
Times -- Dpc    00000003 Interrupt 00000002 
         Kernel 00000cb1 User      000000bf 
lkd> dt nt!_KPRCB fffff8026b2a4180 ThreadDpcEnable
   +0x33b8 ThreadDpcEnable : 0x1 ''
lkd> !prcb 6 // processor 6
PRCB for Processor 6 at ffffd981f4fb2180:
Current IRQL -- 0
Threads--  Current ffff80025054f040 Next 0000000000000000 Idle ffff80025054f040
Processor Index 6 Number (0, 6) GroupSetMember 40
Interrupt Count -- 0008feae
Times -- Dpc    00000007 Interrupt 00000000 
         Kernel 000012a3 User      00000000 
lkd> dt nt!_KPRCB ffffd981f4fb2180 ThreadDpcEnable
   +0x33b8 ThreadDpcEnable : 0x1 ''
```

> "*A threaded DPC is a DPC that the system executes at IRQL equal to PASSIVE_LEVEL.*
> *An ordinary DPC preempts the execution of all threads, and cannot be preempted by a thread or by another DPC. If the system has a large number of ordinary DPCs queued, or if one of those DPCs runs for a long time, every thread will remain paused for an arbitrarily long time. Thus, each ordinary DPC increases system latency, which can hurt the performance of time-sensitive applications, such as audio or video playback.*
> *Conversely, a threaded DPC can be preempted by an ordinary DPC, but not by other threads. Therefore, you should use threaded DPCs rather than ordinary DPCs—unless a particular DPC must not be preempted, not even by another DPC.*"
>
> — Microsoft, [Introduction to threaded DPCs](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs)

![](https://github.com/nohuto/windbg-notes/blob/main/images/irql-levels.png?raw=true)

[`KiInitializeProcessor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiInitializeProcessor.c) initializes per processor threaded DPC:

```c
// KiInitializeProcessor

if ( KeThreadDpcEnable )
{
  KeInitializeGate(a1 + 32320, 0);
  KiInitializeDpcList((_QWORD *)(a1 + 13168));
  *(_QWORD *)(a1 + 13184) = 0LL;
  *(_DWORD *)(a1 + 13192) = 0;
}
```

[`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitSystem.c) (same for [`KiInitializeDynamicProcessor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiInitializeDynamicProcessor.c)) starts one DPC thread per active processor:

```c
// KeInitSystem

KiInitializeProcessor(*v13);
if ( KeThreadDpcEnable )
{
  if ( (int)KiStartDpcThread(v14) < 0 )
    break;
}
```

[`KiStartDpcThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiStartDpcThread.c) creates a system thread whose start routine is [`KiExecuteDpc`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiExecuteDpc.c), and that thread raises itself to priority 31 and runs DPC work through [`KiExecuteAllDpcs`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiExecuteAllDpcs.c).

#### DpcCount

A simple way to see the amount of DPCs that got executed.

- `0` = [`DPC_NORMAL`](https://doxygen.reactos.org/d7/deb/xdk_2ketypes_8h.html#a653ff687e27d13535119d66b179e2325) (ordinary)
- `1` = [`DPC_THREADED`](https://doxygen.reactos.org/d7/deb/xdk_2ketypes_8h.html#aea037d3f0bccb0e36940b37c2b9a9c71) (threaded)

```c
lkd> dt nt!_KPRCB poi(nt!KiProcessorBlock) DpcData
   +0x3340 DpcData : [2] _KDPC_DATA
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA (*)[2])0xfffff806684ef4c0))
(*((ntkrnlmp!_KDPC_DATA (*)[2])0xfffff806684ef4c0))                 [Type: _KDPC_DATA [2]]
    [0]              [Type: _KDPC_DATA] // DPC_NORMAL
    [1]              [Type: _KDPC_DATA] // DPC_THREADED
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4c0))
(*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4c0))                 [Type: _KDPC_DATA]
    [+0x000] DpcList          [Type: _KDPC_LIST]
    [+0x010] DpcLock          : 0x0 [Type: unsigned __int64]
    [+0x018] DpcQueueDepth    : 0 [Type: long]
    [+0x01c] DpcCount         : 0x16c08 [Type: unsigned long] // ordinary DPCs
    [+0x020] ActiveDpc        : 0x0 [Type: _KDPC *]
    [+0x028] LongDpcPresent   : 0x0 [Type: unsigned long]
    [+0x02c] Padding          : 0x0 [Type: unsigned long]
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4f0))
(*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4f0))                 [Type: _KDPC_DATA]
    [+0x000] DpcList          [Type: _KDPC_LIST]
    [+0x010] DpcLock          : 0x0 [Type: unsigned __int64]
    [+0x018] DpcQueueDepth    : 0 [Type: long]
    [+0x01c] DpcCount         : 0x0 [Type: unsigned long] // threaded DPCs
    [+0x020] ActiveDpc        : 0x0 [Type: _KDPC *]
    [+0x028] LongDpcPresent   : 0x0 [Type: unsigned long]
    [+0x02c] Padding          : 0x0 [Type: unsigned long]
```

#### [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/threaddpcenable1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/threaddpcenable2.png?raw=true)

## ReservedCpuSets

Removes processors from the system allowed CPU sets, threads without an explicit CPU set or affinity no longer get scheduled on them. [`KiInitializeReservedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiInitializeReservedCpuSets.c) reads it at boot (`KeInitSystem`), it has to be `REG_BINARY` with a length thats a multiple of 8, one 64 bit processor mask per group (max 32 groups):

```c
// KiInitializeReservedCpuSets

ValueName.Buffer = L"ReservedCpuSets";
v8[0] = 9699474LL;
*(_QWORD *)&ValueName.Length = 2097182LL;
memset_0(&KiReservedCpuSets, 0, 0x100uLL); // clear KiReservedCpuSets

result = ZwOpenKey(&KeyHandle, 1u, &ObjectAttributes);
if ( result >= 0 )
{
  result = ZwQueryValueKey(
             KeyHandle,
             &ValueName,
             KeyValuePartialInformation,
             KeyValueInformation,
             0x110u,
             &ResultLength);
  if ( result >= 0 && v12 == 3 && (v13 & 7) == 0 ) // v12 = type (BINARY), v13 = data length
  {
    result = KiValidateCpuSetMasks((__int64)Src, v13 >> 3); // one 64 bit mask per group
    if ( result >= 0 )
    {
      if ( v2 >= 0x20 || (v0 = v2) != 0 )
        memmove(&KiReservedCpuSets, Src, 8LL * v0); // max 32 groups
      for ( i = 0; i < 2; ++i )
        result = KeModifySystemAllowedCpuSets(0, 0, v3, i, Length); // recalc system allowed CPU sets
```

[`KiModifySystemAllowedCpuSetsWithLock`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiModifySystemAllowedCpuSetsWithLock.c) then masks the reserved processors out of every group:

```c
// KiModifySystemAllowedCpuSetsWithLock

v21 = ~*(_QWORD *)&v18[(_QWORD)v5] & v9; // ~KiReservedCpuSets[group] & requested set
if ( (unsigned __int16)v15 >= **(_WORD **)KiSystemCpuPartition )
  v22 = 0LL;
else
  v22 = *(_QWORD *)(*(_QWORD *)KiSystemCpuPartition + 8LL * (unsigned __int16)v15 + 8);
v9 = v22 & v21;
KiSystemAllowedCpuSets[v16 + v6] = v9; // what threads without explicit CPU sets can use
```

[`KiValidateCpuSetMasks`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiValidateCpuSetMasks.c) only rejects masks with more groups than `KiMaximumGroups` or bits of inactive processors (`STATUS_INVALID_PARAMETER_1`):

```c
// KiValidateCpuSetMasks

if ( a2 > (unsigned __int16)KiMaximumGroups )
  return 3221225903LL; // 0xC00000EF
for ( i = 0LL; (unsigned int)i < a2; i = (unsigned int)(i + 1) )
{
  if ( (~KeActiveProcessors.Bitmap[i] & *(_QWORD *)(a1 + 8 * i)) != 0 ) // bit from inactive proc
    return 3221225903LL;
}
```

## RegistryMachin_* Keys

These are from `ntoskrnl.exe`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// ntoskrnl.exe
aRegistryMachin = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Restrictions"
aRegistryMachin_0 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters"
aRegistryMachin_1 = "\\Registry\\Machine\\HARDWARE"
aRegistryMachin_2 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\FileSystems\\NTFS"
aRegistryMachin_3 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters\\CacheInfo"
aRegistryMachin_4 = "\\Registry\\Machine\\SAM\\SAM"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\AppCompatCache"
aRegistryMachin_6 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Microsoft\\SQMClient\\Windows"
aRegistryMachin_8 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage"
aRegistryMachin_9 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_10 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\CodePage"
aRegistryMachin_11 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CommonGlobUserSettings\\"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class"
aRegistryMachin_13 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WHEA"
aRegistryMachin_14 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp"
aRegistryMachin_15 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management"
aRegistryMachin_16 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"
aRegistryMachin_17 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs"
aRegistryMachin_18 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\EventLog\\Security"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\"
aRegistryMachin_20 = "\\Registry\\Machine\\OSBOOT\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_21 = "\\REGISTRY\\MACHINE"
aRegistryMachin_22 = "\\REGISTRY\\MACHINE\\HARDWARE\\RESOURCEMAP"
aRegistryMachin_23 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WMI"
aRegistryMachin_24 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_25 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices"
aRegistryMachin_26 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_27 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\ProfileSource"
aRegistryMachin_28 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\FirmwareResources"
aRegistryMachin_29 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\KGroups"
aRegistryMachin_30 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility"
aRegistryMachin_31 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\MEMORY MANAGEMENT"
aRegistryMachin_32 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_33 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\ApiSetSchemaExtensions"
aRegistryMachin_34 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server"
aRegistryMachin_35 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides"
aRegistryMachin_36 = "\\registry\\machine\\system\\currentcontrolset\\control\\hiveredirectionlist"
aRegistryMachin_37 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions"
aRegistryMachin_38 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\HAL\\OriginalImageFeatures"
aRegistryMachin_39 = "\\Registry\\Machine\\OSBOOT\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_40 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP"
aRegistryMachin_41 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood"
aRegistryMachin_42 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters"
aRegistryMachin_43 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPEs"
aRegistryMachin_44 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TieredStorage"
aRegistryMachin_45 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_46 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_47 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel\\CPU Partitions"
aRegistryMachin_48 = "\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\CI\\NGEN"
aRegistryMachin_49 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language"
aRegistryMachin_50 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft"
aRegistryMachin_51 = "\\Registry\\Machine\\Software\\Microsoft\\SecurityManager\\AdminCapabilities"
aRegistryMachin_52 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Config"
aRegistryMachin_53 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\VolatileNotifications"
aRegistryMachin_54 = "\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION\\SYSTEM"
aRegistryMachin_55 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StateSeparation\\RedirectionMap\\Keys"
aRegistryMachin_56 = "\\REGISTRY\\MACHINE\\OSBOOT\\ControlSetOverride\\Session Manager\\Memory Management"
aRegistryMachin_57 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GroupOrderList"
aRegistryMachin_58 = "\\REGISTRY\\MACHINE\\SYSTEM\\CONTROLSET001"
aRegistryMachin_59 = "\\Registry\\Machine\\%ws\\ControlSet%03d"
aRegistryMachin_60 = "\\Registry\\Machine\\System\\Select"
aRegistryMachin_61 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\GlobalLogger"
aRegistryMachin_62 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DedupChange"
aRegistryMachin_63 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Update\\TargetingInfo\\DynamicInstalled"
aRegistryMachin_64 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_65 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\.NETFramework"
aRegistryMachin_66 = "\\Registry\\Machine\\SYSTEM"
aRegistryMachin_67 = "\\REGISTRY\\MACHINE"
aRegistryMachin_68 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_69 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters"
aRegistryMachin_70 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\HAL"
aRegistryMachin_71 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management"
aRegistryMachin_72 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM\\ROOT"
aRegistryMachin_73 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\FullLiveKernelReports"
aRegistryMachin_74 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\FileSystems\\NTFS"
aRegistryMachin_75 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_76 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services"
aRegistryMachin_77 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Notifications"
aRegistryMachin_78 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_79 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\BOOTLOG"
aRegistryMachin_80 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages\\PendingDelete"
aRegistryMachin_81 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\EncryptionCertificates\\Certificate.1"
aRegistryMachin_82 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI"
aRegistryMachin_83 = "\\registry\\machine\\system\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager\\Defrag"
aRegistryMachin_84 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings"
aRegistryMachin_85 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\LsaInformation"
aRegistryMachin_86 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_87 = "\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION"
aRegistryMachin_88 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\AutoLogger"
aRegistryMachin_89 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs"
aRegistryMachin_90 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\EarlyLaunch"
aRegistryMachin_91 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
aRegistryMachin_92 = "\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\EarlyLaunch"
aRegistryMachin_93 = "\\REGISTRY\\MACHINE\\SOFTWARE"
aRegistryMachin_94 = "\\REGISTRY\\MACHINE"
aRegistryMachin_95 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_96 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET"
aRegistryMachin_97 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\Hardware Profiles\\%04d"
aRegistryMachin_98 = "\\REGISTRY\\MACHINE\\SOFTWARE\\CLASSES"
aRegistryMachin_99 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Executive"
aRegistryMachin_100 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FileInfo"
aRegistryMachin_101 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\condrv"
aRegistryMachin_102 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WindowsTrustedRT\\Parameters"
aRegistryMachin_103 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_104 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\MCUpdate\\PatchConfig"
aRegistryMachin_105 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\LastCrashdump"
aRegistryMachin_106 = "\\registry\\machine\\"
aRegistryMachin_107 = "\\REGISTRY\\MACHINE\\HARDWARE\\UEFI"
aRegistryMachin_108 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem\\GroupPolicyKeys"
aRegistryMachin_109 = "\\Registry\\Machine\\HARDWARE\\UEFI"
aRegistryMachin_110 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_111 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WDI"
aRegistryMachin_112 = "\\Registry\\Machine\\Hardware\\Description\\System"
aRegistryMachin_113 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Errata\\Dynamic"
aRegistryMachin_114 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET"
aRegistryMachin_115 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS\\CURRENTVERSION\\SHUTDOWN"
aRegistryMachin_116 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions"
aRegistryMachin_117 = "\\REGISTRY\\MACHINE\\HARDWARE\\DEVICEMAP"
aRegistryMachin_118 = "\\Registry\\Machine\\SOFTWARE"
aRegistryMachin_119 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement\\EnterpriseTempControls\\Active"
aRegistryMachin_120 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Scenarios"
aRegistryMachin_121 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_122 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPEs"
aRegistryMachin_123 = "\\Registry\\Machine\\System\\DriverDatabase\\Policies"
aRegistryMachin_124 = "\\REGISTRY\\MACHINE\\OSDATA"
aRegistryMachin_125 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows\\Appx"
aRegistryMachin_126 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\KernelVelocity"
aRegistryMachin_127 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_128 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\CAD"
aRegistryMachin_129 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppModelUnlock"
aRegistryMachin_130 = "\\Registry\\Machine\\Hardware\\Description\\System\\CentralProcessor"
aRegistryMachin_131 = "\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Microsoft\\Compatibility"
aRegistryMachin_132 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\InstalledSDB"
aRegistryMachin_133 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES\\EVENTLOG"
aRegistryMachin_134 = "\\Registry\\Machine\\%wZ\\CurrentControlSet"
aRegistryMachin_135 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\CMF\\SqmData"
aRegistryMachin_136 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Windows"
aRegistryMachin_137 = "\\registry\\machine\\SYSTEM\\CurrentControlSet\\Control\\NUMA"
aRegistryMachin_138 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion"
aRegistryMachin_139 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_140 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FsDepends\\Parameters"
aRegistryMachin_141 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\Hardware Profiles\\%04d"
aRegistryMachin_142 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device"
aRegistryMachin_143 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceGuard"
aRegistryMachin_144 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\DeviceContainerPropertyUpdateEvents"
aRegistryMachin_145 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Syspart"
aRegistryMachin_146 = "\\Registry\\Machine\\%ws"
aRegistryMachin_147 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\HARDWARE PROFILES\\CURRENT"
aRegistryMachin_148 = "\\REGISTRY\\MACHINE\\SOFTWARE\\WowAA32Node"
aRegistryMachin_149 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\DeviceInstall"
aRegistryMachin_150 = "\\Registry\\Machine\\System\\ControlSet%03d"
aRegistryMachin_151 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Quota System"
aRegistryMachin_152 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\LeapSecondInformation"
aRegistryMachin_153 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options"
aRegistryMachin_154 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\IPT"
aRegistryMachin_155 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Wow6432Node"
aRegistryMachin_156 = "\\registry\\machine\\system\\currentcontrolset\\control\\hivelist"
aRegistryMachin_157 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\PXE"
aRegistryMachin_158 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\OneCore"
aRegistryMachin_159 = "\\REGISTRY\\MACHINE\\"
aRegistryMachin_160 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Driver"
aRegistryMachin_161 = "\\Registry\\Machine\\Hardware\\Description\\System"
aRegistryMachin_162 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\SQMClient\\Windows"
aRegistryMachin_163 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites"
aRegistryMachin_164 = "\\REGISTRY\\MACHINE\\%s"
aRegistryMachin_165 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement"
aRegistryMachin_166 = "\\Registry\\Machine"
aRegistryMachin_167 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\Security"
aRegistryMachin_168 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\Configuration Manager"
aRegistryMachin_169 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\WindowsUpdate"
aRegistryMachin_170 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Diagnostics\\Performance"
aRegistryMachin_171 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\SecureBoot"
aRegistryMachin_172 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AutoAttachVirtualDisks"
aRegistryMachin_173 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages"
aRegistryMachin_174 = "\\Registry\\Machine\\Hardware\\DeviceMap"
aRegistryMachin_175 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StateSeparation\\RedirectionMap\\Files"
aRegistryMachin_176 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement\\EnterpriseTempControls"
aRegistryMachin_177 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystemVolumes\\{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}"
aRegistryMachin_178 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\HARDWARE PROFILES\\CURRENT"
aRegistryMachin_179 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Normalization"
aRegistryMachin_180 = "\\REGISTRY\\MACHINE\\SYSTEM"
aRegistryMachin_181 = "\\Registry\\Machine\\Security\\SAM"
aRegistryMachin_182 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_183 = "\\REGISTRY\\MACHINE\\HARDWARE\\OWNERMAP"
aRegistryMachin_184 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_185 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp"
aRegistryMachin_186 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\Session Manager\\Quota System"
aRegistryMachin_187 = "\\Registry\\Machine\\ELAM"
aRegistryMachin_188 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa"
aRegistryMachin_189 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_190 = "\\Registry\\Machine\\System\\CurrentControlSet\\ServiceState"
aRegistryMachin_191 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SAFEBOOT"
aRegistryMachin_192 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters"
aRegistryMachin_193 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Restrictions"
aRegistryMachin_194 = "\\Registry\\Machine\\"
aRegistryMachin_195 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\MUI\\Settings"
aRegistryMachin_196 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES"
aRegistryMachin_197 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\BitlockerStatus"
aRegistryMachin_198 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IDConfigDB"
aRegistryMachin_199 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION\\PERFLIB"
aRegistryMachin_200 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT"
aRegistryMachin_201 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility"
aRegistryMachin_202 = "\\REGISTRY\\MACHINE\\SYSTEM"
aRegistryMachin_203 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides"
aRegistryMachin_204 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\ForceDumpsDisabled"
aRegistryMachin_205 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ACPI\\Parameters"
aRegistryMachin_206 = "\\REGISTRY\\MACHINE\\HARDWARE"
aRegistryMachin_207 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM"
aRegistryMachin_208 = "\\REGISTRY\\MACHINE\\SOFTWARE"
aRegistryMachin_209 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI"
aRegistryMachin_210 = "\\REGISTRY\\MACHINE\\SYSTEM\\Software\\Microsoft"
aRegistryMachin_211 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\International"
aRegistryMachin_212 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_213 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ValidationRunlevels"
aRegistryMachin_214 = "\\REGISTRY\\MACHINE\\"
aRegistryMachin_215 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_216 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters"
aRegistryMachin_217 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_218 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\Kernel DMA Protection"
aRegistryMachin_219 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood"
aRegistryMachin_220 = "\\Registry\\Machine"
aRegistryMachin_221 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_222 = "\\Registry\\Machine\\OSDATA\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_223 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_224 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\CLASS"
aRegistryMachin_225 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION"
aRegistryMachin_226 = "\\Registry\\Machine\\System\\DriverDatabase\\Updates"
aRegistryMachin_227 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\%wZ"
aRegistryMachin_228 = "\\Registry\\Machine\\OSDATA\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_229 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Power"
aRegistryMachin_230 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\"
aRegistryMachin_231 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ServiceGroupOrder"
aRegistryMachin_232 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters"
aRegistryMachin_233 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies"
aRegistryMachin_234 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Notifications"
aRegistryMachin_235 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_236 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\7503491f-4a39-4f84-b231-8aca3e203b94"
aRegistryMachin_237 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings\\LanguageConfiguration"
aRegistryMachin_238 = "\\REGISTRY\\MACHINE\\OSDATA\\Notifications"
aRegistryMachin_239 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Windows"
aRegistryMachin_240 = "\\Registry\\Machine\\System\\Select"
```


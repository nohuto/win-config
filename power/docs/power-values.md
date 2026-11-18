# Power Values

Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation. No values are applied that apply to other options in this section.

## Registry Values

See [power-symbols](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power/power-symbols.txt) for reference ([disp-sym](https://noverse.dev/docs/windbg-notes/symbols/reading-symbols/#mass-display-symbols)). The list doesn't include all existing values yet, but the listed ones do exist. [assets/power](https://github.com/nohuto/win-config/tree/main/power/assets/pseudocode/power) contains the split pseudocode for several `Session Manager\\Power` values.

| Prefix | Component |
| --- | --- |
| `PoFx` | Power Framework |
| `Pop` | Power Manager |
| `Ppm` | Processor Power Manager |

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "ActiveIdleLevel" = 1; // PopFxActiveIdleLevel 
    "ActiveIdleThreshold" = 5000000; // PopFxActiveIdleThreshold
    "ActiveIdleTimeout" = 1000; // PopFxActiveIdleTimeout
    "AllowAudioToEnableExecutionRequiredPowerRequests" = 1; // PopPowerRequestActiveAudioEnablesExecutionRequired 
    "AllowHibernate" = 4294967295; // PopAllowHibernateReg, REG_DWORD
    "AllowSystemRequiredPowerRequests" = 1; // PopPowerRequestConvertSystemToExecution 
    "AlwaysComputeQosHints" = 0; // PpmPerfAlwaysComputeQosEnabled, can be used to cause a condition in PopInitializeHeteroProcessors to be true, see PowerThrottlingOff section
    "BootHeteroPolicyOverride" = 0; // PpmPerfBootHeteroPolicyOverrideEnabled 
    "CheckpointSystemSleep" = 0; // PopCheckpointSystemSleepEnabledReg 
    "CheckpointSystemSleepSimulateFlags" = 0; // PopCheckpointSystemSleepSimulateFlags 
    "CheckPowerSourceAfterRtcWakeTime" = 30; // PopCheckPowerSourceAfterRtcWakeTime
    "Class1InitialUnparkCount" = 64; // PpmParkInitialClass1UnParkCount
    "CoalescingFlushInterval" = 60; // PopCoalescingFlushInterval 
    "CoalescingTimerInterval" = 1500; // PopCoalescingTimerInterval - Units: seconds (multiplies value by -10,000,000, one second in 100?ns units, so the default corresponds to a 25min cadence)
    "DeepIoCoalescingEnabled" = 0; // PopDeepIoCoalescingEnabled 
    "DirectedDripsAction" = 3; // PopDirectedDripsAction 
    "DirectedDripsDebounceInterval" = 120; // PopDirectedDripsDebounceInterval
    "DirectedDripsDfxEnforcementPolicy" = 1; // PopDirectedDripsDfxEnforcementPolicy 
    "DirectedDripsOverride" = 4294967295; // PopDirectedDripsOverride
    "DirectedDripsSurprisePowerOnTimeout" = 5; // PopDirectedDripsSurprisePowerOnTimeoutSeconds 
    "DirectedDripsTimeout" = 300; // PopDirectedDripsTimeout
    "DirectedDripsWaitWakeTimeout" = 5; // PopDirectedDripsWaitWakeTimeoutSeconds 
    "DirectedFxDefaultTimeout" = 120; // PopFxDirectedFxDefaultTimeout
    "DisableDisplayBurstOnPowerSourceChange" = 0; // PopDisableDisplayBurstOnPowerSourceChange 
    "DisableIdleStatesAtBoot" = 0; // PpmIdleDisableStatesAtBoot 
    "DisableInboxPepGeneratedConstraints" = 4294967295; // PopDisableInboxPepGeneratedConstraintsOverride
    "DisableVsyncLatencyUpdate" = 0; // PpmDisableVsyncLatencyUpdate 
    "DozeDeferralChecksToIgnore" = 0; // PopDozeDeferralChecksToIgnore 
    "DozeDeferralMaxSeconds" = 259200; // PopDozeDeferralMaxSeconds
    "DripsCallbackInterval" = 35; // PopDripsCallbackInterval 
    "DripsSwHwDivergenceEnableLiveDump" = 0; // PopDripsSwHwDivergenceEnableLiveDump 
    "DripsSwHwDivergenceThreshold" = 270; // PopDripsSwHwDivergenceThreshold
    "DripsWatchdogAction" = 198; // PopDripsWatchdogAction
    "DripsWatchdogDebounceInterval" = 120; // PopDripsWatchdogDebounceInterval
    "DripsWatchdogTimeout" = 300; // PopDripsWatchdogTimeout
    "EnableInputSuppression" = 4294967295; // PopEnableInputSuppressionOverride
    "EnableMinimalHiberFile" = 0; // PopEnableMinimalHiberFile, REG_DWORD
    "EnablePowerButtonSuppression" = 4294967295; // PopEnablePowerButtonSuppressionOverride
    "EnergyEstimationEnabled" = 1; // PopEnergyEstimationEnabled 
    "EnforceAusterityMode" = 0; // PopEnforceAusterityMode 
    "EnforceConsoleLockScreenTimeout" = 0; // PopEnforceConsoleLockScreenTimeout 
    "EnforceDisconnectedStandby" = 0; // PopEnforceDisconnectedStandby 
    "EventProcessorEnabled" = 1; // PopEventProcessorEnabled 
    "ExitLatencyCheckEnabled" = 0; // PpmExitLatencyCheckEnabled 
    "ExperimentalClusterIdleMitigation" = 0; // PpmIdleClusterIdleMitigation 
    "ForceMinimalHiberFile" = 0; // PopForceMinimalHiberFile, REG_DWORD
    "FxAccountingTelemetryDisabled" = 0; // PopDiagFxAccountingTelemetryDisabled 
    "FxRuntimeLogNumberEntries" = 64; // PopFxRuntimeLogNumberEntries - Changing it to 0 will end up with a BSoD
    "HeteroFavoredCoreRotationTimeoutMs" = 30000; // PpmHeteroFavoredCoreRotationTimeoutMs
    "HeteroHgsEePerfHintsIndependentEnabled" = 0; // PpmHeteroHgsEePerfHintsIndependentEnabled 
    "HeteroHgsPlusDisabled" = 0; // PpmHeteroHgsThreadDisabled 
    "HeteroMultiClassParkingEnabled" = 4294967295; // PpmHeteroMultiClassParkingRegValue
    "HeteroMultiCoreClassesEnabled" = 4294967295; // PpmHeteroMultiCoreClassesRegValue
    "HeteroWpsContainmentEnumOverride" = 0; // PpmHeteroWpsContainmentEnumOverride 
    "HeteroWpsWorkloadProminenceCutoff" = 35; // PpmHeteroWpsWorkloadProminenceCutoff
    "HiberbootEnabled" = 1; // PopHiberbootEnabledReg 
    "HiberFileSizePercent" = 100; // PopHiberFileSizePercent, REG_DWORD, 0-39 keeps the type logic, 40-100 uses the percent directly and PopSetHiberFileSize forces a full file
    "HiberFileType" = 4294967295; // PopHiberFileTypeReg, DWORD 1 = Reduced, DWORD 2 = Full, only used while HiberFileSizePercent < 40
    "HiberFileTypeDefault" = 4294967295; // PopHiberFileTypeDefaultReg, fallback when HiberFileType is unset
    "HibernateBootOptimizationEnabled" = 0; // PopHiberBootOptimizationEnabledReg 
    "HibernateChecksummingEnabled" = 1; // PopHiberChecksummingEnabledReg 
    "HibernateEnabledDefault" = 1; // PopHiberEnabledDefaultReg, REG_DWORD
    "HibernateEnabled" = 1; // that's the value 'powercfg /hibernate off' would set
    "HighPerfDurationBoot" = 90000; // PpmHighPerfDuration
    "HighPerfDurationCSExit" = ?;
    "HighPerfDurationSxExit" = ?;
    "IdleDurationExpirationTimeout" = 4; // PpmIdleDurationExpirationTimeoutMs 
    "IdleProcessorsRequireQosManagement" = 4294967295; // PpmPerfQosManageIdleProcessors
    "IdleStateTimeout" = 500; // PopPepIdleStateTimeout
    "IgnoreCsComplianceCheck" = 0; // PopIgnoreCsComplianceCheck 
    "IgnoreLidStateForInputSuppression" = 4294967295; // PopLidStateForInputSuppressionOverride
    "IpiLastClockOwnerDisable" = 0; // PpmIpiLastClockOwnerDisable 
    "LatencyToleranceDefault" = 100000; // PpmLatencyToleranceLimit
    "LatencyToleranceFSVP" = 20000;
    "LatencyToleranceIdleResiliency" = 1500000;
    "LatencyToleranceParked" = 0; // PpmIdleParkedLatencyLimit 
    "LatencyToleranceSoftParked" = 0; // PpmIdleSoftParkedLatencyLimit 
    "LatencyToleranceVSyncEnabled" = 13001;
    "LidReliabilityState" = 1; // REG_DWORD, range 0-1
    "ManualDimTimeout" = 0; // PopAdaptiveManualDimTimeout 
    "MaximumFrequencyOverride" = 0; // PpmFrequencyOverride 
    "MfBufferingThreshold" = 0; // PpmMfBufferingThreshold 
    "MfOverridesDisabled" = 1; // PpmMfOverridesDisabled 
    "MSDisabled" = 0; // PopModernStandbyDisabled 
    "MultiparkGranularity" = 8; // PpmParkMultiparkGranularity 
    "PdcIdlePhaseDefaultWatchdogTimeoutSeconds" = 30; // PopPdcIdlePhaseDefaultWatchdogTimeoutSeconds
    "PdcOneWayEntry" = 0; // PopPowerAggregatorOneWayEntry 
    "PerfArtificialDomain" = 4294967295; // PpmPerfArtificialDomainSetting
    "PerfBoostAtGuaranteed" = 0; // PpmPerfBoostAtGuaranteed 
    "PerfCalculateActualUtilization" = 1; // PpmPerfCalculateActualUtilization 
    "PerfCheckTimerImplementation" = 0; // PpmCheckTimerImplementation 
    "PerfIdealAggressiveIncreasePolicyThreshold" = 90; // PpmPerfIdealAggressiveIncreaseThreshold
    "PerfQueryOnDevicePowerChanges" = 0; // PopFxPerfQueryOnDevicePowerChanges 
    "PerfSingleStepSize" = 5; // PpmPerfSingleStepSize
    "PlatformAoAcOverride" = 4294967295; // PopPlatformAoAcOverride
    "PlatformRoleOverride" = 4294967295; // PopPlatformRoleOverride
    "PoFxSystemIrpWaitForReportDevicePowered" = 0; // PopPoFxSystemIrpWaitForReportDevicePoweredReg 
    "PowerActionResumeWatchdogTimeoutDefault" = 300; // PopPowerActionResumingWatchdogTimeoutDefault
    "PowerActionTransitioningWatchdogTimeoutDefault" = 600; // PopPowerActionTransitioningWatchdogTimeoutDefault
    "PromoteHibernateToShutdown" = 0; // PopPromoteHibernateToShutdown 
    "ProximityEscapeMsec" = 0; // TtmpProximityEscapeMsec 
    "RestrictedStandbyDozeTimeoutSeconds" = 0; // PopPowerAggregatorRestrictedStandbyDozeTimeoutSeconds 
    "SkipHibernateMemoryMapValidation" = 4294967295; // PopEnableHibernateMemoryMapValidationOverride 
    "SleepstudyAccountingEnabled" = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit" = 3000; // SleepstudyHelperBlockerGlobalLimit
    "SleepstudyLibraryBlockerLimit" = 200; // SleepstudyHelperBlockerLibraryLimit
    "SmartUserPresenceAction" = 0; // PopSmartUserPresenceAction 
    "SmartUserPresenceCheckTimeout" = 10800; // PopSmartUserPresenceCheckTimeout
    "SmartUserPresenceGracePeriod" = 1800; // PopSmartUserPresenceGracePeriod
    "SmartUserPresenceWakeOffset" = 300; // PopSmartUserPresenceWakeOffset
    "StandbyConnectivityGracePeriod" = 0; // PopStandbyConnectivityGracePeriod 
    "SuppressResumePrompt" = 0; // PopSuppressResumePrompt 
    "ThermalPollingMode" = 0; // PopThermalPollingMode 
    "ThermalTelemetryVerbosity" = 1; // PopThermalTelemetryVerbosity 
    "TimerRebaseThresholdOnDripsExit" = 60; // PopTimerRebaseThresholdRegValue
    "TtmEnabled" = 0; // TtmpEnabled 
    "UserBatteryChargeEstimator" = 0; // PopUserBatteryChargingEstimator 
    "UserBatteryDischargeEstimator" = 0; // PopDisableBatteryDischargeEstimator 
    "WatchdogWorkOrderTimeout" = 300000; // PopFxWatchdogWorkOrderTimeout
    "Win32kCalloutWatchdogTimeoutSeconds" = 30; // PopWin32kCalloutWatchdogTimeoutSeconds

    // UmpoRestoreEsOverrideState
    "EnergySaverState" = 2; // 1 = override state (more power savings) if != 1 no override? (WNF_PO_ENERGY_SAVER_OVERRIDE/WNF_SEB_ENERGY_SAVER_STATE_V2), this value is controlled by System > Power: Always use energy saver (1=on, 2=off)

    // InitializePowerWatchdogTimeoutDefaults
    "PowerWatchdogDrvSetMonitorTimeoutMsec" = 10000;
    "PowerWatchdogDwmSyncFlushTimeoutMsec" = 30000;
    "PowerWatchdogPoCalloutTimeoutMsec" = 10000;
    "PowerWatchdogPowerOnGdiTimeoutMsec" = 30000;
    "PowerWatchdogRequestQueueTimeoutMsec" = 30000;

    // from procmon boot trace
    "DisableHotKeyWhenConsoleOff" = ?;
    "EmiPollingInterval" = ?;
    "EmiTelemetryActivePollingInterval" = ?;
    "EmiTelemetryCsPollingInterval" = ?;
    "LidNotifyReliable" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost" = 0; // if nonzero, PopHibernateEvaluation treats hibernation as force disabled
    "Policy" = 0; // PopHiberForceDisabledReg, ^

// Percent<MemoryBucket><Type>, PopCalculateHiberFileSize uses the first matching RAM bucket then uses Full or Reduced percentage (when HiberFileSizePercent < 40)
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\HiberFileBucket";
    "Percent16GBFull" = 40;
    "Percent16GBReduced" = 20;
    "Percent1GBFull" = 40;
    "Percent1GBReduced" = 20;
    "Percent2GBFull" = 40;
    "Percent2GBReduced" = 20;
    "Percent32GBFull" = 40;
    "Percent32GBReduced" = 20;
    "Percent4GBFull" = 40;
    "Percent4GBReduced" = 20;
    "Percent8GBFull" = 40;
    "Percent8GBReduced" = 20;
    "PercentUnlimitedFull" = 40;
    "PercentUnlimitedReduced" = 20;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ModernSleep";
    "EnabledActions" = 0; // PopAggressiveStandbyActionsRegValue 
    "EnableDsNetRefresh" = 0; // PopEnableDsNetRefresh 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "PowerThrottlingOff" = 0; // PpmPerfQosGroupPolicyDisable 
```

### PowerThrottlingOff

See [kernel-values/#cmcontrolvector](https://noverse.dev/docs/win-config/system/kernel-values/#cmcontrolvector) for details on what the comments mean.

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power\PowerThrottling
; ValueName = PowerThrottlingOff
; Destination = PpmPerfQosGroupPolicyDisable
; Length/Type/Flags = 0

INIT:0000000140BA3300                 dq offset aPowerPowerthro ; "Power\PowerThrottling"
INIT:0000000140BA3308                 dq offset aPowerthrottlin ; "PowerThrottlingOff"
INIT:0000000140BA3310                 dq offset PpmPerfQosGroupPolicyDisable
INIT:0000000140BA3318                 dq 3 dup(0)
```

```c
lkd> dd nt!PpmPerfQosGroupPolicyDisable L1
fffff806`1491ed24  00000000 // default
```

The value is read as a bool, so all nonzero data are the same.

`PowerThrottlingOff` is one of nine `_PPM_PERF_QOS_DISABLE_REASON`, changing it to nonzero would set bit 8 in six of seven QoS classes, consumers of that bitmask only check whenever its `!= 0`, so it doesn't matter which reason is set.

If PPM QoS is disabled via `PpmPerfQosDisableGroupPolicy`, six of seven (excluding *High*) classes follow *High*.

`MaxFrequency`, `MaxPerformance`, `MinPerformance`, `PerfAutonomousMode`, `PerfAutonomousWindow`, `PerfBoostMode`, `PerfEnergyPreference`, `PerfLatencyHint`, `LatencyHintEpp` (other ones are scheduling settings) are in `QosPolicies[class]`, built by `PpmPerfCalculateQosClassPolicies`. All of these aren't used whenever PPM QoS (of the class) is unsupported, means that they'll follow the settings of their parent class (which is *High* if all six are unsupported) for them, which are the current power plan settings (`PpmCurrentProfile`). They get parents differently than expected, heres how I understood it:

| Class | Parent |
| --- | --- |
| High | - |
| Medium | High |
| Low | Medium |
| Multimedia | High |
| Deadline | High |
| Eco | Utility |
| Utility | Low |

```c
lkd> dd nt!PpmQosClassesOrderedIndexMap L7
fffff806`62023528  00000000 00000001 00000002 00000005
fffff806`62023538  00000006 00000004 00000003
```

> "*Quality of Service*
>
> *Power profiles provide system wide configuration of processor power management, impacting all running workloads equally. In contrast, the Quality of Service (QoS) feature provides differentiated performance and power for workloads with different QoS levels. For example, this enables tuning foreground HighQoS activity to prioritize performance, while tuning other QoS levels to prioritize power efficiency. For more information, see [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service).*
>
> *Each QoS level supports the following configuration settings:*
>
> *- [MaxFrequency](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxfrequency.md)*  
> *- [MaxPerformance](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxperformance.md)*  
> *- [MinPerformance](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-minperformance.md)*  
> *- [PerfAutonomousMode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfautonomousmode.md)*  
> *- [PerfAutonomousWindow](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfautonomouswindow.md)*  
> *- [PerfBoostMode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfboostmode.md)*  
> *- [PerfEnergyPreference](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfenergypreference.md)*  
> *- [PerfLatencyHint](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perflatencyhint.md)*  
> *- [LatencyHintEpp](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-latencyhintepp.md)*  
> *- [SchedulingPolicy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-schedulingpolicy.md)*  
> *- [ShortSchedulingPolicy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortschedulingpolicy.md)*  
> *- [LongThreadArchClassLowerThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold.md)*  
> *- [LongThreadArchClassUpperThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold.md)*  
> *- [ShortThreadArchClassLowerThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold.md)*  
> *- [ShortThreadArchClassUpperThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclassupperthreshold.md)*  
>
> *On systems with processors with heterogeneous architecture, the configuration settings for efficiency class 1 cores use a similar naming convention.*
>
> *The common parameters have the suffix "1" to indicate efficiency class.*
>
> *- [MaxFrequency1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxfrequency.md)*  
> *- [MaxPerformance1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxperformance.md)*  
> *- [MinPerformance1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-minperformance.md)*  
> *- [PerfEnergyPreference1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfenergypreference.md)*  
> *- [PerfLatencyHint1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perflatencyhint.md)*  
> *- [LatencyHintEpp1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-latencyhintepp.md)*  
>
> — Microsoft, [Processor power management options](https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-processor-power-management-options#quality-of-service)

#### PopInitializeHeteroProcessors

```c
// PopInitializeHeteroProcessors

  v3 = 1;
  v4 = 0; // capability
  if ( (PpmBackgroundProfile || PpmEntryLevelPerfProfile || PpmMultimediaQosProfile || PpmPerfAlwaysComputeQosEnabled) // one must be nonzero here
    && PpmPerfSchedulerDirectedPerfStatesSupported
    && KeQueryActiveProcessorCountEx(0) >= 2 ) // at least two active processors
  {
    v4 = 1;
  }
  if ( PpmPerfVmQosSupported )
  {
    v4 = 1;
    goto LABEL_13;
  }
  if ( v4 )
  {
LABEL_13:
    v5 = 1; // enable processor performance QoS
    if ( !PpmPerfQosGroupPolicyDisable ) // PowerThrottlingOff = 0
      goto LABEL_15;
  }
  v5 = 0; // unsupported/PowerThrottlingOff is nonzero
LABEL_15:
```

Afterwards, `v5` is passed as the second argument into `KeConfigureHeteroProcessors`:

```c
// PopInitializeHeteroProcessors

LOBYTE(v20) = v2;
v22 = PopConfigureHeteroPolicies(v7, v20);
if ( (v3 || v7 && v22 || PpmPerfQosSupportedAndAllowed != v5)
  && (unsigned int)KeConfigureHeteroProcessors(v1, v5, &v32) )
{
  PsEnumProcesses((__int64 (__fastcall *)(__int64 *, __int64))PopUpdateSingleProcessHeteroPolicies, 0LL);
}
```

At the end that result is written into `PpmPerfQosSupportedAndAllowed`:

```c
// PopInitializeHeteroProcessors

PpmPerfQosSupportedAndAllowed = v5;
```

##### Reading Globals

Example output of my testing system, here all conditions aren't true, means `v4` and `v5` stay at `0`, means chaning `PowerThrottlingOff` has no impact.

```c
lkd> dd nt!PpmPerfQosDisableReasons L1
fffff803`35d1ed20  00000082 // bit 1 NoProfile, bit 7 NoHardwareSupport
lkd> dq nt!PpmBackgroundProfile L1
fffff806`14839488  00000000`00000000
lkd> dq nt!PpmEntryLevelPerfProfile L1
fffff806`14839480  00000000`00000000
lkd> dq nt!PpmMultimediaQosProfile L1
fffff806`148394a0  00000000`00000000
lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff806`1491eec8  00                                               .
lkd> db nt!PpmPerfSchedulerDirectedPerfStatesSupported L1
fffff806`1491eaa7  00                                               .
lkd> dq nt!KeActiveProcessors+8 L1
fffff806`1491efe8  00000000`00000fff // bit 0-11
lkd> db nt!PpmPerfVmQosSupported L1
fffff806`1491eb52  00                                               .
lkd> db nt!PpmPerfQosSupportedAndAllowed L1
fffff806`1491ebf5  00                                               .
```

##### PpmPerfSchedulerDirectedPerfStatesSupported

This may not be correct yet, and is based on the amdppm driver.

Each PPM performance domain gets an `AllowSchedulerDirectedPerfStates` value from its PP driver (amdppm/intelppm...), [`PpmRegisterPerfStates`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmRegisterPerfStates.c) then sets `PpmPerfSchedulerDirectedPerfStatesSupported` to `1` only when every registered domain has a nonzero value.

On AMDs `_CPC` for example, [`InitCpcStatesInternal`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/InitCpcStatesInternal.c) uses these conditions:

```c
// InitCpcStatesInternal

if ( (*(_DWORD *)(v80 + 280) & 0x400000) != 0 && v83 && v136 && (v84 == 254 || v81 == 1) ) // 0x400000 = IsACountMCountSupported & processor family >= 17
                                                                                           // v83 = native CPPC handler availaile
                                                                                           // v136 = CPPC handler returned AllowSchedulerDirectedPerfStates = 1
                                                                                           // v84 == 254 || v81 == 1, domain uses HW_ALL/has one processor
{
  *(_BYTE *)(v5 + 11) = 1; // v5 + 11 = _PROCESSOR_PERF_STATES.AllowSchedulerDirectedPerfStates
  if ( !_bittest64((const signed __int64 *)(v80 + 280), 0x22u) || (v97 = 0, v129[0]) )
    v97 = 1;
  *(_BYTE *)(v5 + 12) = v97;
  *(_DWORD *)(v5 + 48) = v146;
}
```

```c
if ( (unsigned __int8)IsACountMCountSupported() )
{
  v7 = 0LL;
  GetCpuIdInfo(1u, &v7);
  if ( (v7 & 0xF00) == 0xF00 && (unsigned int)(unsigned __int8)((unsigned int)v7 >> 20) + 15 >= 0x17 )
    v4 |= 0x400000uLL;
}
```

[`InitDriver`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/InitDriver.c) only gives the native CPPC handler when CPUID `Fn8000_0008_EBX[27]` is set (which is CPPC):

```c
// InitDriver

GetCpuIdInfo(0x80000000, &v7);
if ( (unsigned int)v7 >= 8 )
{
  GetCpuIdInfo(0x80000008, &v8);
  if ( (DWORD1(v8) & 0x8000000) != 0 ) // 0x8000000 = bit 27
    *(_QWORD *)(a1 + 176) = GetCppcRequestMsrPerfControlHandler;
}
```

```c
CPUID.01H: EAX=00A20F12 family=19h ECX=7EF8320B hypervisor=0
CPUID.06H: ECX=00000001 ECX[0]=1
CPUID.80000008H: EBX=111EF657 EBX[27]=0
```

Bit 27 is `0` here which causes `AllowSchedulerDirectedPerfStates` to stay at `0`, means `PpmPerfSchedulerDirectedPerfStatesSupported` is also `0`:

```c
lkd> dt nt!_PROC_PERF_DOMAIN ffff930d`77ff35a0 Id ProcessorCount Coordination AllowSchedulerDirectedPerfStates QosSupported
   +0x128 ProcessorCount                   : 1
   +0x1b0 Id                               : 1
   +0x1e1 Coordination                     : 0xfe ''
   +0x1e5 AllowSchedulerDirectedPerfStates : 0 ''
   +0x2fa QosSupported                     : 0 ''
```

##### AlwaysComputeQosHints

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power
; ValueName = AlwaysComputeQosHints
; Destination = PpmPerfAlwaysComputeQosEnabled

INIT:0000000140BA28B0                 dq offset aPower_2      ; "Power"
INIT:0000000140BA28B8                 dq offset aAlwayscomputeq ; "AlwaysComputeQosHints"
INIT:0000000140BA28C0                 dq offset PpmPerfAlwaysComputeQosEnabled
INIT:0000000140BA28C8                 align 20h
```

This can be used to make the first codition true in the `PopInitializeHeteroProcessors` part shown above.

```c
if ( (PpmBackgroundProfile || PpmEntryLevelPerfProfile || PpmMultimediaQosProfile || PpmPerfAlwaysComputeQosEnabled)
```

```c
lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff804`49f1eec8  00                                               . // AlwaysComputeQosHints = 0

lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff803`35d1eec8  01                                               . // AlwaysComputeQosHints = 1
```

[PpmPerfAlwaysComputeQosEnabled](https://github.com/nohuto/globals/blob/main/11-23H2/ntoskrnl/PpmPerfAlwaysComputeQosEnabled.cpp) has a PE init default of `0` and doesn't get changed afterwards, so missing = `0`.

#### PpmPerfCalculateQosClassPolicies

An "PPM performance domain" has one/more logical processors that share the same performance controls, `Members` here tells its logical processors, `QosPolicies[7]` & `QosDisableReasons[7]` include one entry for each of the *High*, *Medium*, *Low*, *Multimedia*, *Deadline*, *Eco*, *Utility* classes.

```c
lkd> dq nt!KeActiveProcessors+8 L1
fffff806`1491efe8  00000000`00000fff // bit 0-11

lkd> dd nt!PpmPerfDomainCount L1
fffff806`1491ec48  0000000c // 12 = each processor has its own domain

lkd> dt nt!_PROC_PERF_DOMAIN ffffbd04`acfb3700 Link Members ProcessorCount EfficiencyClass Id QosDisableReasons QosSupported
   +0x000 Link              : _LIST_ENTRY [ 0xffffbd04`acfb9010 - 0xfffff806`62d1eb38 ]
   +0x018 Members           : _KAFFINITY_EX
   +0x128 ProcessorCount    : 1
   +0x12c EfficiencyClass   : 0 ''
   +0x1b0 Id                : 1
   +0x2d0 QosDisableReasons : [7] 0
   +0x2fa QosSupported      : 0 ''

lkd> dd ffffbd04`acfb3700+0x2d0 L7
ffffbd04`acfb39d0  00000000 00000082 00000082 00000082 // class 0 = 00000000, all others bit 1+7
ffffbd04`acfb39e0  00000082 00000082 00000082
```

[`PpmPerfUpdateDomainPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmPerfUpdateDomainPolicy.c) goes through those domains and calls [`PpmPerfCalculateQosClassPolicies`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmPerfCalculateQosClassPolicies.c) to get their seven `QosPolicies` & `QosDisableReasons` entries:

```c
// PpmPerfCalculateQosClassPolicies

if ( PpmPerfQosGroupPolicyDisable )
  v16 |= 0x100u; // bit 8
if ( !PpmPerfSchedulerDirectedPerfStatesSupported )
  v16 |= 0x80u; // bit 7
```

```c
enum _PPM_PERF_QOS_DISABLE_REASON
{
    PpmPerfQosDisableInternal=0, // PpmPerfQosDisableRefcount
    PpmPerfQosDisableNoProfile=1,
    PpmPerfQosDisableNoPolicy=2,
    PpmPerfQosDisableInsufficientPolicy=3,
    PpmPerfQosDisableMaxOverride=4, // PpmPerfMaxOverrideEnabled
    PpmPerfQosDisableLowLatency=5, // GUID_POWER_POLICY_PROFILE_LOW_LATENCY
    PpmPerfQosDisableSmtScheduler=6, // !PopHeteroSystem
    PpmPerfQosDisableNoHardwareSupport=7, // 0x80
    PpmPerfQosDisableGroupPolicy=8, // 0x100
    PpmPerfQosDisableMax=9
};
```

```cpp
struct _PROC_PERF_DOMAIN// Size=0x428 (Id=1969)
{
    struct _LIST_ENTRY Link;// Offset=0x0 Size=0x10
    struct _PROC_PERF_CHECK_CONTEXT * Master;// Offset=0x10 Size=0x8
    struct _KAFFINITY_EX Members;// Offset=0x18 Size=0x108
    unsigned long long DomainContext;// Offset=0x120 Size=0x8
    unsigned long ProcessorCount;// Offset=0x128 Size=0x4
    unsigned char EfficiencyClass;// Offset=0x12c Size=0x1
    unsigned char NominalPerformanceClass;// Offset=0x12d Size=0x1
    unsigned char HighestPerformanceClass;// Offset=0x12e Size=0x1
    enum _PROCESSOR_PRESENCE Presence;// Offset=0x130 Size=0x4
    struct _PROC_PERF_CONSTRAINT * Processors;// Offset=0x138 Size=0x8
    void  ( * GetFFHThrottleState)(unsigned long long * );// Offset=0x140 Size=0x8
    void  ( * TimeWindowHandler)(unsigned long long ,unsigned long );// Offset=0x148 Size=0x8
    void  ( * BoostPolicyHandler)(unsigned long long ,unsigned long );// Offset=0x150 Size=0x8
    void  ( * BoostModeHandler)(unsigned long long ,unsigned long );// Offset=0x158 Size=0x8
    void  ( * AutonomousActivityWindowHandler)(unsigned long long ,unsigned long );// Offset=0x160 Size=0x8
    void  ( * AutonomousModeHandler)(unsigned long long ,unsigned long );// Offset=0x168 Size=0x8
    void  ( * ReinitializeHandler)(unsigned long long );// Offset=0x170 Size=0x8
    unsigned long  ( * PerfSelectionHandler)(unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long * ,unsigned long long * );// Offset=0x178 Size=0x8
    void  ( * PerfControlHandler)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x180 Size=0x8
    void  ( * PerfControlHandlerHidden)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x188 Size=0x8
    void  ( * DomainPerfControlHandler)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x190 Size=0x8
    void  ( * PerfUpdateHwDebugData)(unsigned long long ,unsigned long long ,unsigned char );// Offset=0x198 Size=0x8
    unsigned long  ( * PerfQueryProcMeasurementCapabilities)();// Offset=0x1a0 Size=0x8
    long  ( * PerfQueryProcMeasurementValues)(unsigned long ,unsigned long * ,void * ,unsigned long );// Offset=0x1a8 Size=0x8
    unsigned long Id;// Offset=0x1b0 Size=0x4
    unsigned long MaxFrequency;// Offset=0x1b4 Size=0x4
    unsigned long NominalFrequency;// Offset=0x1b8 Size=0x4
    unsigned long MaxPercent;// Offset=0x1bc Size=0x4
    unsigned long MinPerfPercent;// Offset=0x1c0 Size=0x4
    unsigned long MinThrottlePercent;// Offset=0x1c4 Size=0x4
    unsigned long AdvertizedMaximumFrequency;// Offset=0x1c8 Size=0x4
    unsigned long long MinimumRelativePerformance;// Offset=0x1d0 Size=0x8
    unsigned long long NominalRelativePerformance;// Offset=0x1d8 Size=0x8
    unsigned char NominalRelativePerformancePercent;// Offset=0x1e0 Size=0x1
    unsigned char Coordination;// Offset=0x1e1 Size=0x1
    unsigned char HardPlatformCap;// Offset=0x1e2 Size=0x1
    unsigned char AffinitizeControl;// Offset=0x1e3 Size=0x1
    unsigned char EfficientThrottle;// Offset=0x1e4 Size=0x1
    unsigned char AllowSchedulerDirectedPerfStates;// Offset=0x1e5 Size=0x1
    unsigned char InitiateAllProcessors;// Offset=0x1e6 Size=0x1
    unsigned char AllowVmPerfSelection;// Offset=0x1e7 Size=0x1
    unsigned char TurboRangeKnown;// Offset=0x1e8 Size=0x1
    unsigned long VmFrequencyStepMhz;// Offset=0x1ec Size=0x4
    unsigned long VmHighestFrequencyMhz;// Offset=0x1f0 Size=0x4
    unsigned long VmNominalFrequencyMhz;// Offset=0x1f4 Size=0x4
    unsigned long VmLowestFrequencyMhz;// Offset=0x1f8 Size=0x4
    unsigned char AutonomousMode;// Offset=0x1fc Size=0x1
    unsigned char AutonomousCapability;// Offset=0x1fd Size=0x1
    unsigned char ProvideGuidance;// Offset=0x1fe Size=0x1
    unsigned long DesiredPercent;// Offset=0x200 Size=0x4
    unsigned long GuaranteedPercent;// Offset=0x204 Size=0x4
    unsigned char EngageResponsivenessOverrides;// Offset=0x208 Size=0x1
    struct _PROC_PERF_QOS_CLASS_POLICY QosPolicies[7];// Offset=0x20c Size=0xc4
    unsigned long QosDisableReasons[7];// Offset=0x2d0 Size=0x1c
    unsigned short QosEquivalencyMasks[7];// Offset=0x2ec Size=0xe
    unsigned char QosSupported;// Offset=0x2fa Size=0x1
    unsigned long SelectionGeneration;// Offset=0x2fc Size=0x4
    struct _PERF_CONTROL_STATE_SELECTION QosSelection[7];// Offset=0x300 Size=0x118
    unsigned long long PerfChangeTime;// Offset=0x418 Size=0x8
    unsigned long PerfChangeIntervalCount;// Offset=0x420 Size=0x4
    unsigned char Force;// Offset=0x424 Size=0x1
    unsigned char Update;// Offset=0x425 Size=0x1
    unsigned char Apply;// Offset=0x426 Size=0x1
};
```

## [StorageD3InModernStandby](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/power-management-for-storage-hardware-devices-intro#d3-support)

Used in the `Disable D3 in Modern Standby` suboption, the value isn't in the power key, but since the first suboption is already related to ModernStandby, and creating a new option for that would be too much, I'll add it here for now.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage";
    "StorageD3InModernStandby" = 4294967295; // REG_DWORD, 0 = Disable D3 support, 1 = Enable D3 support
```

> "*When the system is not in use, Windows may opportunistically turn off power to some set of devices to conserve energy. In Modern Standby, the system remains in S0. Even while in S0, all peripheral devices may eventually be powered down due to idle timeouts. This state is defined as "S0 Low Power Idle". Once all devices are in a low-power state, even more of the system infrastructure (e.g. busses, timers, ...) may be powered down. The general rule of thumb is to place the device in the deepest possible D-state when it is idle, even when the system state is S0. Depending on implementation details of the processor complex and platform design, peripheral devices may be required to go to an F-state, D3 Hot, or D3 Cold (power is cut). To mitigate the need for a function driver to manage these implementation details, drivers should go to the deepest appropriate device state in order to maximize battery life.*"
>
> — Microsoft, [Power Management for Storage Hardware Devices, D3 Support](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/power-management-for-storage-hardware-devices-intro#d3-support)


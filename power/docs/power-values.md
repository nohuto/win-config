# Power Values

Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation. No values are applied that apply to other options in this section.

## Registry Values

See [power-symbols](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power/power-symbols.txt) for reference ([disp-sym](https://noverse.dev/docs/windbg-notes/symbols/reading-symbols/#mass-display-symbols)).

| Prefix | Component |
| --- | --- |
| `PoFx` | Power Framework |
| `Pop` | Power Manager |
| `Ppm` | Processor Power Manager |

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "ActiveIdleLevel" = 1; // REG_DWORD, PopFxActiveIdleLevel
    "ActiveIdleThreshold" = 500; // REG_DWORD, PopFxActiveIdleThreshold, ms, PoFxInitPowerManagement multiplies it by 10000
    "ActiveIdleTimeout" = 1000; // REG_DWORD, PopFxActiveIdleTimeout
    "AllowAudioToEnableExecutionRequiredPowerRequests" = 1; // REG_DWORD, PopPowerRequestActiveAudioEnablesExecutionRequired
    "AllowHibernate" = 4294967295; // REG_DWORD, PopAllowHibernateReg (https://noverse.dev/docs/win-config/power/disable-hibernation/#registry-values), only 0 = hibernation not allowed
    "AllowSystemRequiredPowerRequests" = 1; // REG_DWORD, PopPowerRequestConvertSystemToExecution
    "AlwaysComputeQosHints" = 0; // REG_DWORD, PpmPerfAlwaysComputeQosEnabled, can be used to cause a condition in PopInitializeHeteroProcessors to be true, see PowerThrottlingOff section
    "BatteryChargeTrajectoryThresholdPercent" = 1; // REG_DWORD, PopBatteryInitPhaseTwo, 1-10
    "BatteryInstantaneousPeakPowerThresholdInMW" = 500; // REG_DWORD, PopBatteryInstantaneousPeakPowerThresholdInMW, 25H2
    "BatteryPresentRateThreshold" = 0; // REG_DWORD, PopBatteryPresentRateThreshold, 25H2
    "BatterySustainablePeakPowerThresholdInMW" = 500; // REG_DWORD, PopBatterySustainablePeakPowerThresholdInMW, 25H2
    "BootHeteroPolicyOverride" = 1; // REG_DWORD, PpmPerfBootHeteroPolicyOverrideEnabled, PpmPerfClearBootOverrides clears it after boot
    "ChargerWeakDetectionThresholdPercent" = 1; // REG_DWORD, PopBatteryInitPhaseTwo, 1-10
    "CheckpointSystemSleep" = 0; // REG_DWORD, PopCheckpointSystemSleepEnabledReg
    "CheckpointSystemSleepSimulateFlags" = 0; // REG_DWORD, PopCheckpointSystemSleepSimulateFlags
    "CheckPowerSourceAfterRtcWakeTime" = 30; // REG_DWORD, PopCheckPowerSourceAfterRtcWakeTime
    "Class1InitialUnparkCount" = 64; // REG_DWORD, PpmParkInitialClass1UnParkCount
    "CoalescingFlushInterval" = 60; // REG_DWORD, PopCoalescingFlushInterval
    "CoalescingTimerInterval" = 1500; // REG_DWORD, PopCoalescingTimerInterval, seconds until the I/O coalescing timer expires after coalescing starts, 0 = expires at once, https://noverse.dev/docs/win-config/power/disable-timer-coalescing/#miscellaneous-values
    "DeepIoCoalescingEnabled" = 0; // REG_DWORD, PopDeepIoCoalescingEnabled, only read by PdcPoResiliencyClient (Modern Standby), ^
    "DirectedDripsDfxEnforcementPolicy" = 1; // REG_DWORD, PopDirectedDripsDfxEnforcementPolicy
    "DirectedDripsOverride" = 4294967295; // REG_DWORD, PopDirectedDripsOverride
    "DirectedDripsSurprisePowerOnTimeout" = 5; // REG_DWORD, PopDirectedDripsSurprisePowerOnTimeoutSeconds
    "DirectedDripsTimeout" = 300; // REG_DWORD, PopDirectedDripsTimeout
    "DirectedDripsWaitWakeTimeout" = 5; // REG_DWORD, PopDirectedDripsWaitWakeTimeoutSeconds
    "DirectedFxDefaultTimeout" = 120; // REG_DWORD, PopFxDirectedFxDefaultTimeout
    "DisableDisplayBurstOnPowerSourceChange" = 0; // REG_DWORD, PopDisableDisplayBurstOnPowerSourceChange
    "DisableIdleStatesAtBoot" = 0; // REG_DWORD, PpmIdleDisableStatesAtBoot
    "DisableInboxPepGeneratedConstraints" = 4294967295; // REG_DWORD, PopDisableInboxPepGeneratedConstraintsOverride
    "DisableVsyncLatencyUpdate" = 0; // REG_DWORD, PpmDisableVsyncLatencyUpdate, 1 = keep LatencyToleranceDefault while VSync is on
    "DozeDeferralChecksToIgnore" = 0; // REG_DWORD, PopDozeDeferralChecksToIgnore
    "DozeDeferralMaxSeconds" = 259200; // REG_DWORD, PopDozeDeferralMaxSeconds
    "DripsCallbackInterval" = 35; // REG_DWORD, PopDripsCallbackInterval
    "DripsSwHwDivergenceEnableLiveDump" = 0; // REG_DWORD, PopDripsSwHwDivergenceEnableLiveDump
    "DripsSwHwDivergenceThreshold" = 270; // REG_DWORD, PopDripsSwHwDivergenceThreshold
    "DripsWatchdogAction" = 198; // REG_DWORD, PopDripsWatchdogAction
    "DripsWatchdogDebounceInterval" = 120; // REG_DWORD, PopDripsWatchdogDebounceInterval
    "DripsWatchdogTimeout" = 300; // REG_DWORD, PopDripsWatchdogTimeout
    "DynamicHintAdjustEnabled" = 1; // REG_DWORD, PpmIdleDynamicHintAdjustEnabled, 25H2
    "EnableInputSuppression" = 4294967295; // REG_DWORD, PopEnableInputSuppressionOverride
    "EnableMinimalHiberFile" = 0; // REG_DWORD, PopEnableMinimalHiberFile
    "EnablePowerButtonSuppression" = 4294967295; // REG_DWORD, PopEnablePowerButtonSuppressionOverride
    "EnergyEstimationEnabled" = 1; // REG_DWORD, PopEnergyEstimationEnabled
    "EnforceAusterityMode" = 0; // REG_DWORD, PopEnforceAusterityMode, 25H2
    "EnforceConsoleLockScreenTimeout" = 0; // REG_DWORD, PopEnforceConsoleLockScreenTimeout
    "EnforceDisconnectedStandby" = 0; // REG_DWORD, PopEnforceDisconnectedStandby
    "EventProcessorEnabled" = 1; // REG_DWORD, PopEventProcessorEnabled
    "ExitLatencyCheckEnabled" = 1; // REG_DWORD, PpmExitLatencyCheckEnabled, PoInitSystem sets 0 when a hypervisor is present
    "ExperimentalClusterIdleMitigation" = 0; // REG_DWORD, PpmIdleClusterIdleMitigation, 25H2
    "ForceMinimalHiberFile" = 0; // REG_DWORD, PopForceMinimalHiberFile
    "FxAccountingTelemetryDisabled" = 0; // REG_DWORD, PopDiagFxAccountingTelemetryDisabled
    "FxRuntimeLogNumberEntries" = 64; // REG_DWORD, PopFxRuntimeLogNumberEntries, changing it to 0 will end up with a BSoD
    "HeteroFavoredCoreRotationTimeoutMs" = 30000; // REG_DWORD, PpmHeteroFavoredCoreRotationTimeoutMs
    "HeterogeneousPpmImplementation" = 1; // REG_DWORD, PpmHeteroImplementationGeneration, 23H2 & W10 22H2, doesnt exist in 25H2
    "HeteroHgsEePerfHintsIndependentEnabled" = 0; // REG_DWORD, PpmHeteroHgsEePerfHintsIndependentEnabled, 25H2
    "HeteroHgsPlusDisabled" = 0; // REG_DWORD, PpmHeteroHgsThreadDisabled
    "HeteroImportantUtilityLowDominanceCutoff" = 40; // REG_DWORD, PpmHeteroImportantUtilityLowDominanceCutoff, 25H2
    "HeteroMultiClassParkingEnabled" = 4294967295; // REG_DWORD, PpmHeteroMultiClassParkingRegValue
    "HeteroMultiCoreClassesEnabled" = 4294967295; // REG_DWORD, PpmHeteroMultiCoreClassesRegValue
    "HeteroWpsContainmentEnumOverride" = 0; // REG_DWORD, PpmHeteroWpsContainmentEnumOverride, 25H2
    "HeteroWpsWorkloadProminenceCutoff" = 35; // REG_DWORD, PpmHeteroWpsWorkloadProminenceCutoff, 25H2
    "HiberFileSizePercent" = 0; // REG_DWORD, PopHiberFileSizePercent, 100 when missing, 0-39 keeps the type logic, 40-100 uses the percent directly and PopSetHiberFileSize forces a full file, https://noverse.dev/docs/win-config/power/disable-hibernation/#reduced-hiberfile
    "HiberFileType" = 4294967295; // REG_DWORD, PopHiberFileTypeReg, 1 = Reduced, 2 = Full, only used while HiberFileSizePercent < 40, ^
    "HiberFileTypeDefault" = 4294967295; // REG_DWORD, PopHiberFileTypeDefaultReg, fallback when HiberFileType is unset, ^
    "HibernateBootOptimizationEnabled" = 0; // REG_DWORD, PopHiberBootOptimizationEnabledReg
    "HibernateChecksummingEnabled" = 1; // REG_DWORD, PopHiberChecksummingEnabledReg
    "HibernateEnabled" = 4294967295; // REG_DWORD, PopHiberEnabledReg, missing = HibernateEnabledDefault decides, https://noverse.dev/docs/win-config/power/disable-hibernation/#registry-values
    "HibernateEnabledDefault" = 1; // REG_DWORD, PopHiberEnabledDefaultReg, only used while HibernateEnabled is missing, ^
    "HighPerfDurationBoot" = 90000; // REG_DWORD, ms, PpmHighPerfDuration[0], how long high performance request stays after boot, 0 = released at once, max 300000
    "HighPerfDurationCSExit" = 5000; // REG_DWORD, ms, PpmHighPerfDuration[1], same after a Modern Standby exit
    "HighPerfDurationSxExit" = 90000; // REG_DWORD, ms, PpmHighPerfDuration[2], same after a resume from sleep or hibernate
    "HighPerfSoftParkLatency" = 1000; // REG_DWORD, PpmHighPerfSoftParkLatencyUs, 25H2
    "IdleDurationExpirationTimeout" = 4; // REG_DWORD, PpmIdleDurationExpirationTimeoutMs
    "IdleProcessorsRequireQosManagement" = 4294967295; // REG_DWORD, PpmPerfQosManageIdleProcessors
    "IdleStateTimeout" = 500; // REG_DWORD, PopPepIdleStateTimeout
    "IgnoreCsComplianceCheck" = 0; // REG_DWORD, PopIgnoreCsComplianceCheck
    "IgnoreLidStateForInputSuppression" = 4294967295; // REG_DWORD, PopLidStateForInputSuppressionOverride
    "IpiLastClockOwnerDisable" = 0; // REG_DWORD, PpmIpiLastClockOwnerDisable
    "LatencyToleranceDefault" = 100000; // REG_DWORD, 100ns units, PpmLatencyToleranceLimit[0]
    "LatencyToleranceFSVP" = 20000; // REG_DWORD, 100ns units (2 ms), PpmLatencyToleranceLimit[2]
    "LatencyToleranceIdleResiliency" = 1500000; // REG_DWORD, 100ns units (150 ms), PpmLatencyToleranceLimit[3]
    "LatencyToleranceParked" = 0; // REG_DWORD, PpmIdleParkedLatencyLimit, 25H2
    "LatencyToleranceSoftParked" = 0; // REG_DWORD, PpmIdleSoftParkedLatencyLimit, 25H2
    "LatencyToleranceVSyncEnabled" = 13001; // REG_DWORD, 100ns units, PpmLatencyToleranceLimit[1]
    "LidReliabilityState" = 1; // REG_DWORD, PopLidReliabilityInit
    "ManualDimTimeout" = 0; // REG_DWORD, PopAdaptiveManualDimTimeout
    "MaximumFrequencyOverride" = 0; // REG_DWORD, PpmFrequencyOverride
    "MaxUnexpectedInterrupts" = 5; // REG_DWORD, PpmIdleMaxUnexpectedInterrupt, 25H2
    "MfBufferingThreshold" = 0; // REG_DWORD, PpmMfBufferingThreshold
    "MSDisabled" = 0; // REG_DWORD, PopModernStandbyDisabled
    "MultiparkGranularity" = 8; // REG_DWORD, PpmParkMultiparkGranularity
    "OneSettingPowerButtonBugcheck" = 0; // REG_DWORD
    "OneSettingPowerButtonLiveDump" = 0; // REG_DWORD
    "PdcIdlePhaseDefaultWatchdogTimeoutSeconds" = 30; // REG_DWORD, PopPdcIdlePhaseDefaultWatchdogTimeoutSeconds
    "PdcOneWayEntry" = 0; // REG_DWORD, PopPowerAggregatorOneWayEntry
    "PerfArtificialDomain" = 4294967295; // REG_DWORD, PpmPerfArtificialDomainSetting
    "PerfBoostAtGuaranteed" = 0; // REG_DWORD, PpmPerfBoostAtGuaranteed
    "PerfCalculateActualUtilization" = 1; // REG_DWORD, PpmPerfCalculateActualUtilization
    "PerfCheckTimerImplementation" = 0; // REG_DWORD, PpmCheckTimerImplementation, 25H2
    "PerfIdealAggressiveIncreasePolicyThreshold" = 90; // REG_DWORD, PpmPerfIdealAggressiveIncreaseThreshold
    "PerfQueryOnDevicePowerChanges" = 0; // REG_DWORD, PopFxPerfQueryOnDevicePowerChanges
    "PerfSingleStepSize" = 5; // REG_DWORD, PpmPerfSingleStepSize
    "PlatformAoAcOverride" = 4294967295; // REG_DWORD, PopPlatformAoAcOverride
    "PlatformRoleOverride" = 4294967295; // REG_DWORD, PopPlatformRoleOverride
    "PoFxSystemIrpWaitForReportDevicePowered" = 0; // REG_DWORD, PopPoFxSystemIrpWaitForReportDevicePoweredReg
    "PowerActionResumeWatchdogTimeoutDefault" = 300; // REG_DWORD, PopPowerActionResumingWatchdogTimeoutDefault
    "PowerActionSuspendWatchdogTimeoutDefault" = 600; // REG_DWORD, PopPowerActionTransitioningWatchdogTimeoutDefault
    "PowerAdapterPeakPowerThresholdInMW" = 500; // REG_DWORD, PopPowerAdapterPeakPowerThresholdInMW, 25H2
    "PowerButtonBugcheck" = 0; // REG_DWORD, 1 = bug check 0x1C8 when the power button is held 7s
    "PowerButtonLiveDump" = 0; // REG_DWORD, bit 0 = live dump (0x11C8), bit 1 user pages, bit 2 hypervisor pages, bits 4-7 hold time 2-6s
    "PpmPerfCheckCountVersion" = 1; // REG_DWORD, PpmPerfCheckCountVersion, 23H2
    "PreSleepNotificationSeconds" = 300; // REG_DWORD, PopPreSleepNotificationSeconds, 23H2
    "PromoteHibernateToShutdown" = 0; // REG_DWORD, PopPromoteHibernateToShutdown
    "ProximityEscapeMsec" = 0; // REG_DWORD, TtmpProximityEscapeMsec
    "RestrictedStandbyDozeTimeoutSeconds" = 0; // REG_DWORD, PopPowerAggregatorRestrictedStandbyDozeTimeoutSeconds, 25H2
    "SkipHibernateMemoryMapValidation" = 4294967295; // REG_DWORD, PopEnableHibernateMemoryMapValidationOverride
    "SleepstudyAccountingEnabled" = 1; // REG_DWORD, SleepstudyHelperAccountingEnabled
    "SleepstudyGlobalBlockerLimit" = 3000; // REG_DWORD, SleepstudyHelperBlockerGlobalLimit, 25H2
    "SleepstudyLibraryBlockerLimit" = 200; // REG_DWORD, SleepstudyHelperBlockerLibraryLimit, 25H2
    "SmartUserPresenceAction" = 0; // REG_DWORD, PopSmartUserPresenceAction
    "SmartUserPresenceCheckTimeout" = 10800; // REG_DWORD, PopSmartUserPresenceCheckTimeout
    "SmartUserPresenceGracePeriod" = 1800; // REG_DWORD, PopSmartUserPresenceGracePeriod
    "SmartUserPresenceWakeOffset" = 300; // REG_DWORD, PopSmartUserPresenceWakeOffset
    "StandbyConnectivityGracePeriod" = 0; // REG_DWORD, PopStandbyConnectivityGracePeriod
    "SuppressResumePrompt" = 0; // REG_DWORD, PopSuppressResumePrompt
    "ThermalPollingMode" = 0; // REG_DWORD, PopThermalPollingMode
    "ThermalTelemetryVerbosity" = 1; // REG_DWORD, PopThermalTelemetryVerbosity
    "TimerRebaseThresholdOnDripsExit" = 60; // REG_DWORD, PopTimerRebaseThresholdRegValue
    "TtmEnabled" = 0; // REG_DWORD, TtmpEnabled
    "UserBatteryChargeEstimator" = 0; // REG_DWORD, PopUserBatteryChargingEstimator, 0 = kernel publishes WNF_PO_CHARGE_ESTIMATE (time until full)
    "UserBatteryDischargeEstimator" = 0; // REG_DWORD, PopDisableBatteryDischargeEstimator, 0 = kernel publishes WNF_PO_DISCHARGE_ESTIMATE (battery time left)
    "WatchdogWorkOrderTimeout" = 300000; // REG_DWORD, PopFxWatchdogWorkOrderTimeout
    "Win32kCalloutWatchdogTimeoutSeconds" = 30; // REG_DWORD, PopWin32kCalloutWatchdogTimeoutSeconds

    // umpo.dll
    "EnergySaverState" = 2; // REG_DWORD, UmpoRestoreEsOverrideState, System > Power "Always use energy saver" (1 = on, 2 = off)
    "SmartPresenceConfidence" = 65; // REG_DWORD, UmpoSmartPresenceInit, max 100

    // umpoext.dll (23H2)
    "DisableHotKeyWhenConsoleOff" = 0; // REG_DWORD, DimEngineStart, 1 = brightness hotkeys are ignored while display is off
    "EmiPollingInterval" = 500; // REG_DWORD, ms, UmpoEmiInitializeTracing, energy meter (EMI) ETW polling
    "EmiTelemetryActivePollingInterval" = 0; // REG_DWORD, ms, UmpoEmiInitializeTelemetryTracing
    "EmiTelemetryCsPollingInterval" = 0; // REG_DWORD, ms, UmpoEmiInitializeTelemetryTracing
    "PmiPollingInterval" = 500; // REG_DWORD, ms, UmpoInitializeTracing

    // LogonController.dll, facecredentialprovider.dll (23H2)
    "LidNotifyReliable" = 1; // REG_DWORD

    // win32kbase InitializePowerWatchdogTimeouts, bug check 0x19C WIN32K_POWER_WATCHDOG_TIMEOUT when a step takes longer (param 1 in brackets)
    "PowerWatchdogDrvSetMonitorTimeoutMsec" = 10000; // REG_DWORD (0x50)
    "PowerWatchdogDwmSyncFlushTimeoutMsec" = 30000; // REG_DWORD (0x40)
    "PowerWatchdogPoCalloutTimeoutMsec" = 10000; // REG_DWORD (0x20)
    "PowerWatchdogPowerOnGdiTimeoutMsec" = 30000; // REG_DWORD (0x30)
    "PowerWatchdogRequestQueueTimeoutMsec" = 30000; // REG_DWORD (0x10)

    // pdc.sys (23H2), Modern Standby only
    "LidReliabilityThreshold" = 5; // REG_DWORD, use not mapped
    "PdcActivatorClientPolicyNotificationDebounce" = 0; // REG_DWORD
    "PdcActivatorClientResponseTimeout" = 0; // REG_DWORD
    "PdcCriticalActivatorAction" = 5; // REG_DWORD
    "PdcCriticalActivatorTimeout" = 0; // REG_DWORD
    "PdcCriticalTransitionTimeout" = 0; // REG_DWORD
    "PdcCsEntryAction" = 1; // REG_DWORD
    "PdcCsEntryDamTimeout" = 0; // REG_DWORD
    "PdcCsEntryLowPowerTimeout" = 300; // REG_DWORD
    "PdcCsEntryPlmTimeout" = 900; // REG_DWORD
    "PdcCsEntryResiliencyNotificationTimeout" = 300; // REG_DWORD
    "PdcCsEntryShellTimeout" = 300; // REG_DWORD
    "PdcEnforceSystemIdleTimeoutOnConsoleLock" = 0; // REG_DWORD
    "PdcLockStatsTelemetryPeriod" = 86400; // REG_DWORD
    "PdcLockWatchdogTimeout" = 30000; // REG_DWORD
    "PdcReplayLidClose" = 1; // REG_DWORD
    "PdcWcmTransitionTimeout" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost" = 0; // REG_DWORD, PopHiberForceDisabledReg+0x4, nonzero = hibernation disabled (PopHibernateEvaluation)
    "Policy" = 0; // REG_DWORD, PopHiberForceDisabledReg, same

// PopCalculateHiberFileSize (25H2) uses these only while HiberFileSizePercent < 40, the first bucket whose RAM limit is at least the installed RAM, then its Reduced (HiberFileType 1) or Full (2) percent, 100 or more is ignored
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\HiberFileBucket";
    "Percent1GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x10
    "Percent1GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0xc
    "Percent2GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x28
    "Percent2GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x24
    "Percent4GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x40
    "Percent4GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x3c
    "Percent8GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x58
    "Percent8GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x54
    "Percent16GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x70
    "Percent16GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x6c
    "Percent32GBFull" = 40; // REG_DWORD, PopHiberFileBucket+0x88
    "Percent32GBReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x84
    "PercentUnlimitedFull" = 40; // REG_DWORD, PopHiberFileBucket+0xa0
    "PercentUnlimitedReduced" = 20; // REG_DWORD, PopHiberFileBucket+0x9c

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ModernSleep";
    "EnabledActions" = 0; // REG_DWORD, PopAggressiveStandbyActionsRegValue (used when < 16), setup writes 7 on Modern Standby clients
    "EnableDsNetRefresh" = 0; // REG_DWORD, PopEnableDsNetRefresh

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "DisableUserPresenceQos" = 0; // REG_DWORD, PspDisableWindowInFocusUserIdleQos
                                  // nonzero keeps focused windows process at High QoS while the user is idle (UserPresenceThrottling feature), 25H2
    "PowerThrottlingOff" = 0; // REG_DWORD, PpmPerfQosGroupPolicyDisable

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "FlushPolicy" = 0; // REG_DWORD, PopFlushPolicy
    "IdleScanInterval" = 30; // REG_DWORD, PopIdleScanInterval, above 300 = 300
    "SkipTickOverride" = 1; // REG_DWORD, PopSkipTickPolicy
    "SleepStudyDeviceAccountingLevel" = 4; // REG_DWORD, PopSleepStudyDeviceAccountingLevel
    "SleepStudyDisabled" = 0; // REG_DWORD, PopSleepStudyDisabled
    "WatchdogResumeTimeout" = 120; // REG_DWORD, PopWatchdogResumeTimeout
    "WatchdogSleepTimeout" = 300; // REG_DWORD, PopWatchdogSleepTimeout
    "Win32CalloutWatchdogBugcheckEnabled" = 0; // REG_DWORD, PopWin32CalloutWatchdogBugcheckEnabled
```

### DisableUserPresenceQos

With the `UserPresenceThrottling` feature on, the FG process gets PPM policy 9 (`ProcessPpmWindowInFocusUserIdle`) instead of 7 (`ProcessPpmWindowInFocus`) while the user is idle.

Only changes something on CPUs with hybrid cores, on other CPUs every class except *High* already equals *High* (see [PowerThrottlingOff](#powerthrottlingoff)).

```c
// PspSetProcessPpmPolicy (25H2)

if ( (unsigned int)Feature_UserPresenceThrottling__private_IsEnabledDeviceUsageNoInline()
  && a2 == 9
  && PspDisableWindowInFocusUserIdleQos ) // DisableUserPresenceQos
{
  a2 = 7;
}
return KeSetProcessPpmPolicy(a1, a2);
```

```c
// KiComputeThreadQos (25H2)

v3 = KiThreadPolicyToQosMappingTable[*(unsigned __int8 *)(a1 + 958)];
if ( v3 == 7 ) // KHeteroCpuQosDynamic
{
  v4 = (*(_DWORD *)(*(_QWORD *)(a1 + 544) + 136LL) >> 7) & 0xF; // _KPROCESS_PPM_POLICY
  if ( (unsigned int)Feature_UserPresenceThrottling__private_IsEnabledDeviceUsageNoInline() )
  {
    if ( (_DWORD)v4 != 8
      && (_DWORD)v4 != 9
      && (KiDynamicHeteroCpuPolicyMask & 1) != 0
      && (*(_DWORD *)(*(_QWORD *)(a1 + 544) + 136LL) & 0x2000) != 0 )
    {
      return 0; // High
    }
  }

  v3 = KiProcessPolicyToQosMappingTable[v4];
```

```cpp
enum _KPROCESS_PPM_POLICY
{
    ProcessPpmDefault=0,
    ProcessPpmThrottle=1,
    ProcessPpmSemiThrottle=2,
    ProcessPpmNoThrottle=3,
    ProcessPpmWindowMinimized=4,
    ProcessPpmWindowOccluded=5,
    ProcessPpmWindowVisible=6,
    ProcessPpmWindowInFocus=7,
    ProcessPpmMaximumThrottle=8,
    MaxProcessPpmPolicy=9
};

enum _KHETERO_CPU_QOS
{
    KHeteroCpuQosDefault=0,
    KHeteroCpuQosHigh=0,
    KHeteroCpuQosMedium=1,
    KHeteroCpuQosLow=2,
    KHeteroCpuQosMultimedia=3,
    KHeteroCpuQosDeadline=4,
    KHeteroCpuQosEco=5,
    KHeteroCpuQosUtility=6,
    KHeteroCpuQosDynamic=7,
    KHeteroCpuQosMax=7
}; 
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

With `PopHeteroSystem` = 0 (no hybrid/favored cores) every class except *High* already has reason 6 (`PpmPerfQosDisableSmtScheduler`), so `PowerThrottlingOff` does nothing here ([`PpmPerfCalculateQosClassPolicies`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmPerfCalculateQosClassPolicies.c#L172-L173)).

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
// PopInitializeHeteroProcessors (23H2)

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
// PopInitializeHeteroProcessors (23H2)

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
// PopInitializeHeteroProcessors (23H2)

PpmPerfQosSupportedAndAllowed = v5;
```

##### Reading Globals

Example output of my testing system, here all conditions aren't true, means `v4` and `v5` stay at `0`, means changing `PowerThrottlingOff` has no impact.

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
// InitCpcStatesInternal (23H2)

if ( (*(_DWORD *)(v80 + 280) & 0x400000) != 0 && v83 && v136 && (v84 == 254 || v81 == 1) ) // 0x400000 = IsACountMCountSupported & processor family >= 17h (Zen and newer)
                                                                                           // v83 = native CPPC handler available
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
// InitDriver (23H2)

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
// InitDriver (23H2)

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
// PopInitializeHeteroProcessors (23H2)

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

A "PPM performance domain" has one/more logical processors that share the same performance controls, `Members` here tells its logical processors, `QosPolicies[7]` & `QosDisableReasons[7]` include one entry for each of the *High*, *Medium*, *Low*, *Multimedia*, *Deadline*, *Eco*, *Utility* classes.

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
// PpmPerfCalculateQosClassPolicies (23H2)

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

> "*When the system is not in use, Windows may opportunistically turn off power to some set of devices to conserve energy. In Modern Standby, the system remains in S0. Even while in S0, all peripheral devices may eventually be powered down due to idle timeouts. This state is defined as "S0 Low Power Idle". Once all devices are in a low-power state, even more of the system infrastructure (e.g. busses, timers, ...) may be powered down. The general rule of thumb is to place the device in the deepest possible D-state when it is idle, even when the system state is S0. Depending on implementation details of the processor complex and platform design, peripheral devices may be required to go to an F-state, D3 Hot, or D3 Cold (power is cut). To mitigate the need for a function driver to manage these implementation details, drivers should go to the deepest appropriate device state in order to maximize battery life.*"
>
> — Microsoft, [Power Management for Storage Hardware Devices, D3 Support](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/power-management-for-storage-hardware-devices-intro#d3-support)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage";
    "StorageD3InModernStandby" = 4294967295; // REG_DWORD, StorageD3RegistryState, 0 = D3 off, 1 = D3 on
```


```c
// RaidInitializeAdapter (25H2)

if ( StorageD3AllowedOnCurrentPlatform )
  StorageD3InModernStandbyEnabled = 1;
if ( (unsigned __int8)RaidQueryAcpiDsdStorageD3Property(*(PDEVICE_OBJECT *)(a1 + 8)) ) // _DSD StorageD3Enable
  StorageD3InModernStandbyEnabled = *(_DWORD *)(a1 + 5712) != 0;
if ( StorageD3RegistryState == 1 ) // StorageD3InModernStandby = 1
{
  StorageD3InModernStandbyEnabled = 1;
}
else
{
  if ( !StorageD3RegistryState ) // StorageD3InModernStandby = 0
    StorageD3InModernStandbyEnabled = 0;
  if ( !StorageD3InModernStandbyEnabled )
    goto LABEL_72;
}
*(_BYTE *)(a1 + 112) |= 0x40u; // D3 enabled for adapter
```
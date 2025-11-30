# Power Values

This option serves as a general values overview for the `Power` key (similar to `DXG Kernel Values`/`Kernel Values`/`DWM Values`). Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation. 

No values are applied that apply to other options in this section.

> https://github.com/5Noxi/wpr-reg-records?tab=readme-ov-file#power-values

---

See [power-symbols](https://github.com/5Noxi/wpr-reg-records/blob/main/assets/power-symbols.txt) for reference. The list doesn't include all existing values yet, but the listed ones do exist. [PopOpenPowerKey-all](https://github.com/5Noxi/wpr-reg-records/blob/main/assets/PopOpenPowerKey-all.c) shows the pseudocode for several `Session Manager\\Power` values.

Everything listed below is based on personal research. Mistakes may exist, but I don't think I've made any.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "ActiveIdleLevel"; = 1; // PopFxActiveIdleLevel 
    "ActiveIdleThreshold"; = 5000000; // PopFxActiveIdleThreshold (0x004C4B40) 
    "ActiveIdleTimeout"; = 1000; // PopFxActiveIdleTimeout (0x000003E8) 
    "AllowAudioToEnableExecutionRequiredPowerRequests"; = 1; // PopPowerRequestActiveAudioEnablesExecutionRequired 
    "AllowHibernate"; = 4294967295; // PopAllowHibernateReg (0xFFFFFFFF) 
    "AllowSystemRequiredPowerRequests"; = 1; // PopPowerRequestConvertSystemToExecution 
    "AlwaysComputeQosHints"; = 0; // PpmPerfAlwaysComputeQosEnabled 
    "BootHeteroPolicyOverride"; = 0; // PpmPerfBootHeteroPolicyOverrideEnabled 
    "CheckpointSystemSleep"; = 0; // PopCheckpointSystemSleepEnabledReg 
    "CheckpointSystemSleepSimulateFlags"; = 0; // PopCheckpointSystemSleepSimulateFlags 
    "CheckPowerSourceAfterRtcWakeTime"; = 30; // PopCheckPowerSourceAfterRtcWakeTime (0x1E) 
    "Class1InitialUnparkCount"; = 64; // PpmParkInitialClass1UnParkCount (0x40) 
    "CoalescingFlushInterval"; = 60; // PopCoalescingFlushInterval (0x0000003C) 
    "CoalescingTimerInterval"; = 1500; // PopCoalescingTimerInterval (0x000005DC) - Units: seconds (multiplies value by -10,000,000, one second in 100 ns units, so the default corresponds to a 25min cadence)
    "DeepIoCoalescingEnabled"; = 0; // PopDeepIoCoalescingEnabled 
    "DirectedDripsAction"; = 3; // PopDirectedDripsAction 
    "DirectedDripsDebounceInterval"; = 120; // PopDirectedDripsDebounceInterval (0x78) 
    "DirectedDripsDfxEnforcementPolicy"; = 1; // PopDirectedDripsDfxEnforcementPolicy 
    "DirectedDripsOverride"; = 4294967295; // PopDirectedDripsOverride (0xFFFFFFFF) 
    "DirectedDripsSurprisePowerOnTimeout"; = 5; // PopDirectedDripsSurprisePowerOnTimeoutSeconds 
    "DirectedDripsTimeout"; = 300; // PopDirectedDripsTimeout (0x12C) 
    "DirectedDripsWaitWakeTimeout"; = 5; // PopDirectedDripsWaitWakeTimeoutSeconds 
    "DirectedFxDefaultTimeout"; = 120; // PopFxDirectedFxDefaultTimeout (0x00000078) 
    "DisableDisplayBurstOnPowerSourceChange"; = 0; // PopDisableDisplayBurstOnPowerSourceChange 
    "DisableIdleStatesAtBoot"; = 0; // PpmIdleDisableStatesAtBoot 
    "DisableInboxPepGeneratedConstraints"; = 4294967295; // PopDisableInboxPepGeneratedConstraintsOverride (0xFFFFFFFF) 
    "DisableVsyncLatencyUpdate"; = 0; // PpmDisableVsyncLatencyUpdate 
    "DozeDeferralChecksToIgnore"; = 0; // PopDozeDeferralChecksToIgnore 
    "DozeDeferralMaxSeconds"; = 259200; // PopDozeDeferralMaxSeconds (0x0003F480) 
    "DripsCallbackInterval"; = 35; // PopDripsCallbackInterval (0x23) 
    "DripsSwHwDivergenceEnableLiveDump"; = 0; // PopDripsSwHwDivergenceEnableLiveDump 
    "DripsSwHwDivergenceThreshold"; = 270; // PopDripsSwHwDivergenceThreshold (0x010E) 
    "DripsWatchdogAction"; = 198; // PopDripsWatchdogAction (0xC6) 
    "DripsWatchdogDebounceInterval"; = 120; // PopDripsWatchdogDebounceInterval (0x78) 
    "DripsWatchdogTimeout"; = 300; // PopDripsWatchdogTimeout (0x12C) 
    "EnableInputSuppression"; = 4294967295; // PopEnableInputSuppressionOverride (0xFFFFFFFF) 
    "EnableMinimalHiberFile"; = 0; // PopEnableMinimalHiberFile 
    "EnablePowerButtonSuppression"; = 4294967295; // PopEnablePowerButtonSuppressionOverride (0xFFFFFFFF) 
    "EnergyEstimationEnabled"; = 1; // PopEnergyEstimationEnabled 
    "EnforceAusterityMode"; = 0; // PopEnforceAusterityMode 
    "EnforceConsoleLockScreenTimeout"; = 0; // PopEnforceConsoleLockScreenTimeout 
    "EnforceDisconnectedStandby"; = 0; // PopEnforceDisconnectedStandby 
    "EventProcessorEnabled"; = 1; // PopEventProcessorEnabled 
    "ExitLatencyCheckEnabled"; = 0; // PpmExitLatencyCheckEnabled 
    "ExperimentalClusterIdleMitigation"; = 0; // PpmIdleClusterIdleMitigation 
    "ForceMinimalHiberFile"; = 0; // PopForceMinimalHiberFile 
    "FxAccountingTelemetryDisabled"; = 0; // PopDiagFxAccountingTelemetryDisabled 
    "FxRuntimeLogNumberEntries"; = 64; // PopFxRuntimeLogNumberEntries (0x40) - Changing it to 0 will end up with a BSoD
    "HeteroFavoredCoreRotationTimeoutMs"; = 30000; // PpmHeteroFavoredCoreRotationTimeoutMs (0x00007530) 
    "HeteroHgsEePerfHintsIndependentEnabled"; = 0; // PpmHeteroHgsEePerfHintsIndependentEnabled 
    "HeteroHgsPlusDisabled"; = 0; // PpmHeteroHgsThreadDisabled 
    "HeteroMultiClassParkingEnabled"; = 4294967295; // PpmHeteroMultiClassParkingRegValue (0xFFFFFFFF) 
    "HeteroMultiCoreClassesEnabled"; = 4294967295; // PpmHeteroMultiCoreClassesRegValue (0xFFFFFFFF) 
    "HeteroWpsContainmentEnumOverride"; = 0; // PpmHeteroWpsContainmentEnumOverride 
    "HeteroWpsWorkloadProminenceCutoff"; = 35; // PpmHeteroWpsWorkloadProminenceCutoff (0x23) 
    "HiberbootEnabled"; = 0; // PopHiberbootEnabledReg 
    "HiberFileSizePercent"; = 100; // PopHiberFileSizePercent dd 64h (IDA), but set to 0 by default on LTSC IoT Enterprise 2024 since hibernation is unsupported by default
    "HiberFileType"; = 4294967295; // PopHiberFileTypeReg (0xFFFFFFFF)
    "HiberFileTypeDefault"; = 4294967295; // PopHiberFileTypeDefaultReg (0xFFFFFFFF)
    "HibernateBootOptimizationEnabled"; = 0; // PopHiberBootOptimizationEnabledReg 
    "HibernateChecksummingEnabled"; = 1; // PopHiberChecksummingEnabledReg 
    "HibernateEnabledDefault"; = 1; // PopHiberEnabledDefaultReg 
    "HighPerfDurationBoot"; = 90000; // PpmHighPerfDuration (0x00015F90) 
    "HighPerfDurationCSExit"; = ?; // unk_140FC337C
    "HighPerfDurationSxExit"; = ?; // unk_140FC3380
    "IdleDurationExpirationTimeout"; = 4; // PpmIdleDurationExpirationTimeoutMs 
    "IdleProcessorsRequireQosManagement"; = 4294967295; // PpmPerfQosManageIdleProcessors (0xFFFFFFFF) 
    "IdleStateTimeout"; = 500; // PopPepIdleStateTimeout (0x000001F4) 
    "IgnoreCsComplianceCheck"; = 0; // PopIgnoreCsComplianceCheck 
    "IgnoreLidStateForInputSuppression"; = 4294967295; // PopLidStateForInputSuppressionOverride (0xFFFFFFFF) 
    "IpiLastClockOwnerDisable"; = 0; // PpmIpiLastClockOwnerDisable 
    "LatencyToleranceDefault"; = 100000; // PpmLatencyToleranceLimit (0x000186A0) 
    "LatencyToleranceFSVP"; = 20000; // dword_140FC3428 dd 4E20
    "LatencyToleranceIdleResiliency"; = 1500000; // dword_140FC342C dd 16E360
    "LatencyToleranceParked"; = 0; // PpmIdleParkedLatencyLimit 
    "LatencyToleranceSoftParked"; = 0; // PpmIdleSoftParkedLatencyLimit 
    "LatencyToleranceVSyncEnabled"; = 13001; // dword_140FC3424 dd 32C9
    "LidReliabilityState"; = 1; // REG_DWORD, range: 0-1
    "ManualDimTimeout"; = 0; // PopAdaptiveManualDimTimeout 
    "MaximumFrequencyOverride"; = 0; // PpmFrequencyOverride 
    "MfBufferingThreshold"; = 0; // PpmMfBufferingThreshold 
    "MfOverridesDisabled"; = 1; // PpmMfOverridesDisabled 
    "MSDisabled"; = 0; // PopModernStandbyDisabled 
    "MultiparkGranularity"; = 8; // PpmParkMultiparkGranularity 
    "PdcIdlePhaseDefaultWatchdogTimeoutSeconds"; = 30; // PopPdcIdlePhaseDefaultWatchdogTimeoutSeconds (0x0000001E) 
    "PdcOneWayEntry"; = 0; // PopPowerAggregatorOneWayEntry 
    "PerfArtificialDomain"; = 4294967295; // PpmPerfArtificialDomainSetting (0xFFFFFFFF) 
    "PerfBoostAtGuaranteed"; = 0; // PpmPerfBoostAtGuaranteed 
    "PerfCalculateActualUtilization"; = 1; // PpmPerfCalculateActualUtilization 
    "PerfCheckTimerImplementation"; = 0; // PpmCheckTimerImplementation 
    "PerfIdealAggressiveIncreasePolicyThreshold"; = 90; // PpmPerfIdealAggressiveIncreaseThreshold (0x5A) 
    "PerfQueryOnDevicePowerChanges"; = 0; // PopFxPerfQueryOnDevicePowerChanges 
    "PerfSingleStepSize"; = 5; // PpmPerfSingleStepSize (0x05) 
    "PlatformAoAcOverride"; = 4294967295; // PopPlatformAoAcOverride (0xFFFFFFFF) 
    "PlatformRoleOverride"; = 4294967295; // PopPlatformRoleOverride (0xFFFFFFFF) 
    "PoFxSystemIrpWaitForReportDevicePowered"; = 0; // PopPoFxSystemIrpWaitForReportDevicePoweredReg 
    "PowerActionResumeWatchdogTimeoutDefault"; = 300; // PopPowerActionResumingWatchdogTimeoutDefault (0x0000012C) 
    "PowerActionTransitioningWatchdogTimeoutDefault"; = 600; // PopPowerActionTransitioningWatchdogTimeoutDefault (0x00000258) 
    "PromoteHibernateToShutdown"; = 0; // PopPromoteHibernateToShutdown 
    "ProximityEscapeMsec"; = 0; // TtmpProximityEscapeMsec 
    "RestrictedStandbyDozeTimeoutSeconds"; = 0; // PopPowerAggregatorRestrictedStandbyDozeTimeoutSeconds 
    "SkipHibernateMemoryMapValidation"; = 4294967295; // PopEnableHibernateMemoryMapValidationOverride (0xFFFFFFFF) 
    "SleepstudyAccountingEnabled"; = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit"; = 3000; // SleepstudyHelperBlockerGlobalLimit (0x0BB8) 
    "SleepstudyLibraryBlockerLimit"; = 200; // SleepstudyHelperBlockerLibraryLimit (0xC8) 
    "SmartUserPresenceAction"; = 0; // PopSmartUserPresenceAction 
    "SmartUserPresenceCheckTimeout"; = 10800; // PopSmartUserPresenceCheckTimeout (0x00002A30) 
    "SmartUserPresenceGracePeriod"; = 1800; // PopSmartUserPresenceGracePeriod (0x00000708) 
    "SmartUserPresenceWakeOffset"; = 300; // PopSmartUserPresenceWakeOffset (0x0000012C) 
    "StandbyConnectivityGracePeriod"; = 0; // PopStandbyConnectivityGracePeriod 
    "SuppressResumePrompt"; = 0; // PopSuppressResumePrompt 
    "ThermalPollingMode"; = 0; // PopThermalPollingMode 
    "ThermalTelemetryVerbosity"; = 1; // PopThermalTelemetryVerbosity 
    "TimerRebaseThresholdOnDripsExit"; = 60; // PopTimerRebaseThresholdRegValue (0x3C) 
    "TtmEnabled"; = 0; // TtmpEnabled 
    "UserBatteryChargeEstimator"; = 0; // PopUserBatteryChargingEstimator 
    "UserBatteryDischargeEstimator"; = 0; // PopDisableBatteryDischargeEstimator 
    "WatchdogWorkOrderTimeout"; = 300000; // PopFxWatchdogWorkOrderTimeout (0x000493E0) 
    "Win32kCalloutWatchdogTimeoutSeconds"; = 30; // PopWin32kCalloutWatchdogTimeoutSeconds (0x0000001E) 

    // UmpoRestoreEsOverrideState
    "EnergySaverState"; = 2; // 1 = override state (more power savings)? if != 1 no override? (WNF_PO_ENERGY_SAVER_OVERRIDE/WNF_SEB_ENERGY_SAVER_STATE_V2)

    // InitializePowerWatchdogTimeoutDefaults
    "PowerWatchdogDrvSetMonitorTimeoutMsec"; = 10000; // v10[13]
    "PowerWatchdogDwmSyncFlushTimeoutMsec"; = 30000; // v10[10]
    "PowerWatchdogPoCalloutTimeoutMsec"; = 10000;
    "PowerWatchdogPowerOnGdiTimeoutMsec"; = 30000;
    "PowerWatchdogRequestQueueTimeoutMsec"; = 30000;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost"; = ?; // unk_140FC5234
    "Policy"; = 0; // PopHiberForceDisabledReg 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\HiberFileBucket";
    "Percent16GBFull"; = ?; // unk_140FC36D0 - 28Hex/40Dec?
    "Percent16GBReduced"; = ?; // unk_140FC36CC - 14Hex/20Dec?
    "Percent1GBFull"; = ?; // unk_140FC3670 - 28Hex/40Dec?
    "Percent1GBReduced"; = ?; // unk_140FC366C - 14Hex/20Dec?
    "Percent2GBFull"; = ?; // unk_140FC3688 - 28Hex/40Dec?
    "Percent2GBReduced"; = ?; // unk_140FC3684 - 14Hex/20Dec?
    "Percent32GBFull"; = ?; // unk_140FC36E8 - 28Hex/40Dec?
    "Percent32GBReduced"; = ?; // unk_140FC36E4 - 14Hex/20Dec?
    "Percent4GBFull"; = ?; // unk_140FC36A0 - 28Hex/40Dec?
    "Percent4GBReduced"; = ?; // unk_140FC369C - 14Hex/20Dec?
    "Percent8GBFull"; = ?; // unk_140FC36B8 - 28Hex/40Dec?
    "Percent8GBReduced"; = ?; // unk_140FC36B4 - 14Hex/20Dec?
    "PercentUnlimitedFull"; = ?; // unk_140FC3700 - 28Hex/40Dec?
    "PercentUnlimitedReduced"; = ?; // unk_140FC36FC - 14Hex/20Dec?

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ModernSleep";
    "EnabledActions"; = 0; // PopAggressiveStandbyActionsRegValue 
    "EnableDsNetRefresh"; = 0; // PopEnableDsNetRefresh 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "PowerThrottlingOff"; = 0; // PpmPerfQosGroupPolicyDisable 
```

# Disable Device Powersavings

Disables USB selective suspend, idle power management, and related LP features.

I added some comments to `QueryUsbflagsValuesForDevice.c`, since it renamed the values.

> https://github.com/5Noxi/win-config/blob/main/power/desc.md#disable-usb-battery-saver  
> https://github.com/5Noxi/win-config/blob/main/power/desc.md#usb-flags  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/pci.txt  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Enum-USB.txt  
> [power/assets | devicepower-HidpFdoConfigureIdleSettings.c](https://github.com/5Noxi/win-config/blob/main/power/assets/devicepower-HidpFdoConfigureIdleSettings.c)  
> [power/assets | devicepower-UsbhGetD3Policy.c](https://github.com/5Noxi/win-config/blob/main/power/assets/devicepower-UsbhGetD3Policy.c)  
> [power/assets | devicepower-QueryUsbflagsValuesForDevice.c](https://github.com/5Noxi/win-config/blob/main/power/assets/devicepower-QueryUsbflagsValuesForDevice.c)

---

Miscellaneous notes:
```c
// Not used in the option
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\usbhub\\hubg": {
  "DisableSelectiveSuspendUI": { "Type": "REG_DWORD", "Data": 1 },
  "DisableUxdSupport": { "Type": "REG_DWORD", "Data": 1 }
}
// HcDisableAllSelectiveSuspend
// WinUsbPowerPolicyOwnershipDisabled
// UsbDebugModeEnable
"UsbDeviceParameters": {
  "Action": "registry_pattern",
  "Pattern": "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\USB\\**\\Device Parameters",
  "Operations": [
    { "Value": "D3ColdReconnectTimeout", "Type": "REG_DWORD", "Data": 0 }
    { "Value": "DefaultIdleState", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "EnableSelectiveSuspend", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "FullPowerDownOnTransientDx", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "SuppressInputInCS", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "SystemInputSuppressionEnabled", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "WriteReportExSupported", "Type": "REG_DWORD", "Data": 0 },
    //{ "Value": "SelSuspCancelBehavior", "Type": "REG_DWORD", "Data": },
  ]
},
"UsbDevSub": {
  "Action": "registry_pattern",
  "Pattern": "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\USB\\**\\Device Parameters\\*",
  "Exclude": [ "wdf" ],
  "Operations": [
    { "Value": "DeviceD0DelayTime", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "DevicePowerResetDelayTime", "Type": "REG_DWORD", "Data": 0 },
    { "Value": "ASPMOptOut", "Type": "REG_DWORD", "Data": 1 },
    { "Value": "ASPMOptIn", "Type": "REG_DWORD", "Data": 0 }
    
  ]
}
// DisableSelectiveSuspend might be a legacy value
```

```c
// Opt-out of ASPM.
[PciASPMOptOut]
Needs=PciASPMOptOut.HW

[PciASPMOptOut.HW]
AddReg=PciASPMOptOut.RegHW

[PciASPMOptOut.RegHW]
HKR,e5b3b5ac-9725-4f78-963f-03dfb1d828c7,ASPMOptOut,0x10001,1

// Opt-in to ASPM.
[PciASPMOptIn]
Needs=PciASPMOptIn.HW

[PciASPMOptIn.HW]
AddReg=PciASPMOptIn.RegHW

[PciASPMOptIn.RegHW]
HKR,e5b3b5ac-9725-4f78-963f-03dfb1d828c7,ASPMOptIn,0x10001,1
```

> [power/assets | devicepower-OptInOptOutPolicy.c](https://github.com/5Noxi/win-config/blob/main/power/assets/devicepower-OptInOptOutPolicy.c)

---

```c
// probably located in \Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\{ID}\Device Parameters
ForcePortPower
```

# Disable Hibernation

Windows uses hibernation to provide a fast startup experience. When available, it's also used on mobile devices to extend the usable battery life of a system by giving a mechanism to save all of the user's state prior to shutting down the system. In a hibernate transition, all the contents of memory are written to a file on the primary system drive, the hibernation file. This preserves the state of the operating system, applications, and devices. In the case where the combined memory footprint consumes all of physical memory, the hibernation file must be large enough to ensure there's space to save all the contents of physical memory. Since data is written to non-volatile storage, DRAM does not need to maintain self-refresh and can be powered off, which means power consumption of hibernation is very low, almost the same as power off.

During a full shutdown and boot (S5), the entire user session is torn down and restarted on the next boot. In contrast, during a hibernation (S4), the user session is closed and the user state is saved.

| Power state | ACPI state | Description | 
|-------------|------------|-------------|
| Working | *S0* | The system is fully usable. Hardware components that aren't in use can save power by entering a lower power state. | 
| Sleep (Modern Standby) | *S0* low-power idle | Some SoC systems support a low-power idle state known as [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby). In this state, the system can very quickly switch from a low-power state to high-power state in response to hardware and network events. **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Sleep | *S1*<br> *S2*<br> *S3* | The system appears to be off. The amount of power consumed in states *S1-S3* is less than *S0* and more than *S4*. *S3* consumes less power than *S2*, and *S2* consumes less power than *S1*. Systems typically support one of these three states, not all three.<br><br> In states *S1-S3*, volatile memory is kept refreshed to maintain the system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device.<br><br> *Hybrid sleep*, used on desktops, is where a system uses a hibernation file with *S1-S3*. The hibernation file saves the system state in case the system loses power while in sleep.<br><br> **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Hibernate | *S4* | The system appears to be off. Power consumption is reduced to the lowest level. The system saves the contents of volatile memory to a hibernation file to preserve system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device. The working context can be restored if it's stored on nonvolatile media.<br><br> *Fast startup* is where the user is logged off before the hibernation file is created. This allows for a smaller hibernation file, more appropriate for systems with less storage capabilities. | 
| Soft off | *S5* | The system appears to be off. This state is comprised of a full shutdown and boot cycle. | 
| Mechanical off | *G3* | The system is completely off and consumes no power. The system returns to the working state only after a full reboot. | 

> https://learn.microsoft.com/en-us/windows/win32/power/system-power-states

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "AllowHibernate"; = 4294967295; // PopAllowHibernateReg (0xFFFFFFFF) 
    "EnableMinimalHiberFile"; = 0; // PopEnableMinimalHiberFile 
    "ForceMinimalHiberFile"; = 0; // PopForceMinimalHiberFile 
    "HiberbootEnabled"; = 0; // PopHiberbootEnabledReg 
    "HiberFileSizePercent"; = 100; // PopHiberFileSizePercent dd 64h (IDA), but set to 0 by default on LTSC IoT Enterprise 2024 since hibernation is unsupported by default
    "HibernateBootOptimizationEnabled"; = 0; // PopHiberBootOptimizationEnabledReg 
    "HibernateChecksummingEnabled"; = 1; // PopHiberChecksummingEnabledReg 
    "HibernateEnabledDefault"; = 1; // PopHiberEnabledDefaultReg 
    "PromoteHibernateToShutdown"; = 0; // PopPromoteHibernateToShutdown 
    "SkipHibernateMemoryMapValidation"; = 4294967295; // PopEnableHibernateMemoryMapValidationOverride (0xFFFFFFFF) 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost"; = ?; // unk_140FC5234
    "Policy"; = 0; // PopHiberForceDisabledReg 
```

`powercfg /hibernate off` sets:
```c
RegSetValue	HKLM\System\CurrentControlSet\Control\Power\HibernateEnabled	Type: REG_DWORD, Length: 4, Data: 0
```

> https://github.com/5Noxi/wpr-reg-records#power-values  
> https://learn.microsoft.com/en-us/troubleshoot/windows-client/setup-upgrade-and-drivers/disable-and-re-enable-hibernation  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Power.txt


# Reduced HiberFile

Hibernation files are used for hybrid sleep, fast startup, and [standard hibernation](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#hibernate-state-s4). There are two types, differentiated by size, a full and reduced size hibernation file. Only fast startup can use a reduced hibernation file.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "HiberFileSizePercent"; = 100; // PopHiberFileSizePercent dd 64h (IDA), but set to 0 by default on LTSC IoT Enterprise 2024 since hibernation is unsupported by default

    // DWORD 1 = Reduced, DWORD 2 = Full
    "HiberFileType"; = 4294967295; // PopHiberFileTypeReg (0xFFFFFFFF)
    "HiberFileTypeDefault"; = 4294967295; // PopHiberFileTypeDefaultReg (0xFFFFFFFF)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\HiberFileBucket";
    "Percent16GBFull"; = ?; // unk_140FC36D0 - 28Hex/40Dec
    "Percent16GBReduced"; = ?; // unk_140FC36CC - 14Hex/20Dec
    "Percent1GBFull"; = ?; // unk_140FC3670 - 28Hex/40Dec
    "Percent1GBReduced"; = ?; // unk_140FC366C - 14Hex/20Dec
    "Percent2GBFull"; = ?; // unk_140FC3688 - 28Hex/40Dec
    "Percent2GBReduced"; = ?; // unk_140FC3684 - 14Hex/20Dec
    "Percent32GBFull"; = ?; // unk_140FC36E8 - 28Hex/40Dec
    "Percent32GBReduced"; = ?; // unk_140FC36E4 - 14Hex/20Dec
    "Percent4GBFull"; = ?; // unk_140FC36A0 - 28Hex/40Dec
    "Percent4GBReduced"; = ?; // unk_140FC369C - 14Hex/20Dec
    "Percent8GBFull"; = ?; // unk_140FC36B8 - 28Hex/40Dec
    "Percent8GBReduced"; = ?; // unk_140FC36B4 - 14Hex/20Dec
    "PercentUnlimitedFull"; = ?; // unk_140FC3700 - 28Hex/40Dec
    "PercentUnlimitedReduced"; = ?; // unk_140FC36FC - 14Hex/20Dec
```

`powercfg /h /size 0`:
```c
RegSetValue	HKLM\System\CurrentControlSet\Control\Power\HiberFileSizePercent	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0
```
`powercfg /h /type full`:
```c
RegSetValue	HKLM\System\CurrentControlSet\Control\Power\HiberFileType	SUCCESS	Type: REG_DWORD, Length: 4, Data: 2
```
`powercfg /h /type reduced`:
```c
RegSetValue	HKLM\System\CurrentControlSet\Control\Power\HiberFileType	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
```

| Hibernation file type | Default size           | Supports                              |
|-----------------------|------------------------|---------------------------------------|
| Full                  | 40% of physical memory | hibernate, hybrid sleep, fast startup |
| Reduced               | 20% of physical memory | fast startup                          |

To verify or change the type of hibernation file used, run the *powercfg.exe* utility. The following examples demonstrate how.

| Example      |Description   |
|--------------|--------------|
| `powercfg /a`                      | **Verify the hibernation file type.** When a full hibernation file is used, the results state that hibernation is an available option. When a reduced hibernation file is used, the results say hibernation is not supported. If the system has no hibernation file at all, the results say hibernation hasn't been enabled. |
| `powercfg /h /type full`           | **Change the hibernation file type to full.** This isn't recommended on systems with less than 32GB of storage.                      |
| `powercfg /h /type reduced`        | **Change the hibernation file type to reduced.** If the command returns "the parameter is incorrect," see the following example.      |
| `powercfg /h /size 0`<br> `powercfg /h /type reduced`  | **Retry changing the hibernation file type to reduced.** If the hibernation file is set to a custom size greater than 40%, you must first set the size of the file to zero. Then retry the reduced configuration.     |

> https://github.com/5Noxi/wpr-reg-records#power-values  
> https://learn.microsoft.com/en-us/windows/win32/power/system-power-states

# Remove Power Options

Removes the `Hibernate`, `Lock`, `Sleep` power options.

If hiding `Lock` for example via `Control Panel > All Control Panel Items > Power Options > Choose what the power buttons do > Change settings that are currently unavailable`, it sets:
```c
DllHost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FlyoutMenuSettings\ShowLockOption	Type: REG_DWORD, Length: 4, Data: 1
```

LGPE would set the values in `HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Explorer`:
```json
{
  "File": "WindowsExplorer.admx",
  "CategoryName": "WindowsExplorer",
  "PolicyName": "ShowLockOption",
  "NameSpace": "Microsoft.Policies.WindowsExplorer",
  "Supported": "Windows8",
  "DisplayName": "Show lock in the user tile menu",
  "ExplainText": "Shows or hides lock from the user tile menu. If you enable this policy setting, the lock option will be shown in the User Tile menu. If you disable this policy setting, the lock option will never be shown in the User Tile menu. If you do not configure this policy setting, users will be able to choose whether they want lock to show through the Power Options Control Panel.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "ShowLockOption",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsExplorer.admx",
  "CategoryName": "WindowsExplorer",
  "PolicyName": "ShowSleepOption",
  "NameSpace": "Microsoft.Policies.WindowsExplorer",
  "Supported": "Windows8",
  "DisplayName": "Show sleep in the power options menu",
  "ExplainText": "Shows or hides sleep from the power options menu. If you enable this policy setting, the sleep option will be shown in the Power Options menu (as long as it is supported by the machine's hardware). If you disable this policy setting, the sleep option will never be shown in the Power Options menu. If you do not configure this policy setting, users will be able to choose whether they want sleep to show through the Power Options Control Panel.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "ShowSleepOption",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsExplorer.admx",
  "CategoryName": "WindowsExplorer",
  "PolicyName": "ShowHibernateOption",
  "NameSpace": "Microsoft.Policies.WindowsExplorer",
  "Supported": "Windows8",
  "DisplayName": "Show hibernate in the power options menu",
  "ExplainText": "Shows or hides hibernate from the power options menu. If you enable this policy setting, the hibernate option will be shown in the Power Options menu (as long as it is supported by the machine's hardware). If you disable this policy setting, the hibernate option will never be shown in the Power Options menu. If you do not configure this policy setting, users will be able to choose whether they want hibernate to show through the Power Options Control Panel.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Explorer"
  ],
  "ValueName": "ShowHibernateOption",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

---

Miscellaneous keys:
```powershell
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Start\HidePowerButton
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Start\HideRestart
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Start\HideShutDown
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSignOut
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSwitchAccount
```

# Disable Hiberboot

Fast startup is a type of shutdown that uses a hibernation file to speed up the subsequent boot. During this type of shutdown, the user is logged off before the hibernation file is created. Fast startup allows for a smaller hibernation file, more appropriate for systems with less storage capabilities.

When using fast startup, the system appears to the user as though a full shutdown (S5) has occurred, even though the system has actually gone through S4. This includes how the system responds to device wake alarms.

Fast startup logs off user sessions, but the contents of kernel (session 0) are written to hard disk. This enables faster boot.

To programmatically initiate a fast startup-style shutdown, call the [InitiateShutdown](https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-initiateshutdowna) function with the `SHUTDOWN_HYBRID` flag or the [ExitWindowsEx](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-exitwindowsex) function with the `EWX_HYBRID_SHUTDOWN` flag.

In Windows, fast startup is the default transition when a system shutdown is requested. A full shutdown (S5) occurs when a system restart is requested or when an application calls a shutdown API.

---

All three values exist as shown below. `PopReadHiberbootGroupPolicy` (`\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\System`) overrides `PopReadHiberbootPolicy` (`Control\\Session Manager\\Power`).

> https://github.com/5Noxi/wpr-reg-records#power-values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "HiberbootEnabled"; = 0; // PopHiberbootEnabledReg 
    "DisableIdleStatesAtBoot"; = 0; // PpmIdleDisableStatesAtBoot 
    "HibernateBootOptimizationEnabled"; = 0; // PopHiberBootOptimizationEnabledReg 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "HiberbootEnabled"; = 0; // REG_DWORD, range: 0-1

    // HybridBootAnimationTime records the boot animation duration during fast boot, HiberIoCpuTime is CPU time spent on hibernation I/O during resume, ResumeCompleteTimestamp is the system timestamp when resume from hibernation completed. So all of them are just counters and chaning their data won't affect the boot.
    "HybridBootAnimationTime"; = 1601; // REG_DWORD, milliseconds, range: 0-0xFFFFFFFF
    "HiberIoCpuTime"; = 0; // REG_DWORD, milliseconds, range: 0-0xFFFFFFFF
    "ResumeCompleteTimestamp"; = 0; // REG_QWORD, range: 0-0xFFFFFFFFFFFFFFFF
```
> https://github.com/5Noxi/wpr-reg-records?tab=readme-ov-file#power-values  
> https://github.com/marcosd4h/memhunter/blob/f68bca7efe31f49c0dc9ad988fb17bec443a1ca7/libs/boost/interprocess/detail/win32_api.hpp#L2373
```c
// PopOpenPowerKey
{
  return PopOpenKey(a1, L"Control\\Session Manager\\Power");
}

// PopReadHiberbootPolicy
result = PopOpenPowerKey(&KeyHandle);
if ( result >= 0 )
{
  RtlInitUnicodeString(&DestinationString, L"HiberbootEnabled");
  if ( ZwQueryValueKey(
         KeyHandle,
         &DestinationString,
         KeyValuePartialInformation,
         &KeyValueInformation,
         0x14u,
         &ResultLength) >= 0 )
    v1 = BYTE12(KeyValueInformation);
  result = ZwClose(KeyHandle);
}
```
```json
{
  "File": "WinInit.admx",
  "CategoryName": "ShutdownOptions",
  "PolicyName": "Hiberboot",
  "NameSpace": "Microsoft.Policies.WindowsInitialization",
  "Supported": "Windows8",
  "DisplayName": "Require use of fast startup",
  "ExplainText": "This policy setting controls the use of fast startup. If you enable this policy setting, the system requires hibernate to be enabled. If you disable or do not configure this policy setting, the local setting is used.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "HiberbootEnabled",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

> [power/assets | hiberboot-PopReadHiberbootGroupPolicy.c](https://github.com/5Noxi/win-config/blob/main/power/assets/hiberboot-PopReadHiberbootGroupPolicy.c)

# Disable Power Throttling

```
Power throttling, introduced in W10 and present in W11, limits CPU usage for background or minimized applications. It reduces the processing power available to these apps while allowing active applications to run normally.
```
You can see processes, which use power throttling by enabling the column (`Details` > `Select Column`) or add it to the active columns in system informer via the `Choose columns...` window (picture).
> https://systeminformer.io/

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "PowerThrottlingOff"; = 0; // PpmPerfQosGroupPolicyDisable 
```

> https://github.com/5Noxi/wpr-reg-records#power-values

![](https://github.com/5Noxi/win-config/blob/main/power/images/powerth.png?raw=true)

# Disable Energy Estimation

Not needed, if you disable energy estimation:
```json
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\TaggedEnergy": {
  "DisableTaggedEnergyLogging": { "Type": "REG_DWORD", "Data": 1 },
  "TelemetryMaxApplication": { "Type": "REG_DWORD", "Data": 0 },
  "TelemetryMaxTagPerApplication": { "Type": "REG_DWORD", "Data": 0 }
}
```
```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "UserBatteryDischargeEstimator"; = 0; // PopDisableBatteryDischargeEstimator 
    "UserBatteryChargeEstimator"; = 0; // PopUserBatteryChargingEstimator 
    "EnergyEstimationEnabled"; = 1; // PopEnergyEstimationEnabled
                                    // If following HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\knobs\Power/Controls/EnergyEstimationEnabled, it should have a range of 0-4294967295
```

> https://github.com/5Noxi/wpr-reg-records#power-values  
> [power/assets | energyesti-PtInitializeTelemetry.c](https://github.com/5Noxi/win-config/blob/main/power/assets/energyesti-PtInitializeTelemetry.c)

![](https://github.com/5Noxi/win-config/blob/main/power/images/energyesti.png?raw=true)

---

`Disable Battery Capacity Section` = Disables the battery capacity section on the battery saver page of the system settings app.

# Powerplan

Use the commands below, to import power plans by double-clicking them. Modify the powerplan via `PowerSettingsExplorer.exe`.
> http://www.mediafire.com/file/wt37sbsejk7iepm/PowerSettingsExplorer.zip

```json
"HKCR\\.pow": {
  "": { "Type": "REG_SZ", "Data": "Power Plan" },
  "FriendlyTypeName": { "Type": "REG_SZ", "Data": "Power Plan" }
},
"HKCR\\.pow\\DefaultIcon": {
  "": { "Type": "REG_EXPAND_SZ", "Data": "%%SystemRoot%%\\System32\\powercfg.cpl,-202" }
},
"HKCR\\.pow\\shell\\Import\\command": {
  "": { "Type": "REG_SZ", "Data": "powercfg /import \"%%1\"" }
}
```

Remove default powerplans with:
```bat
powercfg -delete 381b4222-f694-41f0-9685-ff5bb260df2e
powercfg -delete 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c
powercfg -delete a1841308-3541-4fab-bc81-f71556f20b4a
powercfg -delete e9a42b02-d5df-448d-aa00-03f14749eb61
```
> https://bitsum.com/known-windows-power-guids/

```bat
powercfg /availablesleepstates (or /a)
```
Shows the current available sleep states on your system.

> https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options#option_availablesleepstates

# Disable HDD Parking

`EnableHDDParking` is set to `1` by default, `EnableDIPM`/`EnableHIPM` are set to `0` by default.

---

Miscellaneous information:
```
HIPM = Host Initiated Link Power Management
DIPM = Device Initiated Link Power Management
```
```c
Dst[37] = L"EnableHIPM";
LODWORD(Dst[11]) = 4;
Dst[38] = &dword_4C134;
Dst[40] = &dword_4C134;
Dst[44] = L"EnableDIPM";
LODWORD(Dst[13]) = 4;
Dst[45] = &dword_5D0C8;
Dst[47] = &dword_5D0C8;
Dst[58] = L"EnableHDDParking";
LODWORD(Dst[18]) = 4;
Dst[59] = &dword_4C13C;
Dst[61] = &dword_4C13C;

dword_5D0CC = 0;
dword_5D0C8 = 0;
dword_4C434 = 0;
dword_4C12C = -1;
dword_4C138 = -1;
dword_4C134 = -1;
dword_4C424 = 16;
dword_4C420 = 3000;
dword_5D510 = 1;
dword_4C13C = 1;
dword_4C130 = 1;
dword_4C140 = -1;
```

> [power/assets | hddpark-amdsbs.c](https://github.com/5Noxi/win-config/blob/main/power/assets/hddpark-amdsbs.c)  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-power-states

---

Miscellaneous notes:

```json
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters\\Device": {
  "IdlePowerMode": { "Type": "REG_DWORD", "Data": 0 }
}
```

> https://github.com/5Noxi/wpr-reg-records#wpr--procmon-registry-activity-records  

Needs more research (`ClassGetServiceParameter.c` - default `0`?):
```
\Registry\Machine\SYSTEM\ControlSet001\Services\disk : IdleClassSupported
```
Additional notes: `EnableALPEDisableHotplug` (`0`), `AhciDisablePxHotplug` - `amdsbs.c`

> https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings-link-power-management-mode---hipm-dipm  
> [power/assets | hddpark-ClassGetServiceParameter.c](https://github.com/5Noxi/win-config/blob/main/power/assets/hddpark-ClassGetServiceParameter.c)  
> [power/assets | hddpark-DllInitialize.c](https://github.com/5Noxi/win-config/blob/main/power/assets/hddpark-DllInitialize.c)

# Disable Storport Idle

"Storport provides support for idle power management to allow storage devices to enter a low power state when not in use. Storport's idle power management (IPM) support includes handling idle power management for storage devices under its management, in coordination with the Power Manager in Windows.

Storport IPM allows the classpnp and disk class drivers to send the SCSI Stop Unit command to the storage device when it's idle for some period of time. The idle period is configurable by the system administrator. The Storport miniport driver is responsible for how the command is used by the Storport miniport driver to conserve power.

Storport Idle Power Management (IPM) isn't enabled by default. It can be enabled in the registry by setting the "EnableIdlePowerManagement" value in the "StorPort" subkey of the device's hardware key to any nonzero value. To do so, use the device INF file or manually edit the registry using the registry editor."

> https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/registry-entries-for-storport-miniport-drivers  
> https://github.com/5Noxi/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-power-management.md  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/ipm-configuration-and-usage  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/pci.txt  
> [power/assets | storport.c](https://github.com/5Noxi/win-config/blob/main/power/assets/storport.c)

# NoLazyMode

`NoLazyMode` = `0` (default)
`LazyModeTimeout` = `1000000` (default)


It sets `NoLazyMode` to `0`, don't set it to `1`. This is currently more likely a placeholder for future documentation. Instead of using `NoLazyMode`, change `LazyModeTimeout`.
```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\MultiMedia\systemprofile : NoLazyMode
```
`AlwaysOn` value exists in W7 and W8, but doesn't exist in W10 and W11 anymore.

"The screenshot below demonstrates some of the initial differences between each mode enabled (0x1) vs off (x0, Non-Present), during these tests MMCSS tasks were engaged and the same pattern reoccurred each time e.g. the Idle related conditions were no longer present leaving only System Responsiveness, Deep Sleep and Realtime MMCSS scheduler task results."

> https://github.com/djdallmann/GamingPCSetup/blob/master/CONTENT/RESEARCH/WINSERVICES/README.md#q-what-the-heck-is-nolazymode-is-it-real-what-does-it-do
> https://github.com/djdallmann/GamingPCSetup/blob/master/CONTENT/RESEARCH/WINSERVICES/README.md#q-does-the-mmcss-alwayson-registry-setting-exist

![](https://github.com/5Noxi/win-config/blob/main/power/images/nolazymode.png?raw=true)

# Disable Timer Coalescing

"CoalesecingTimerinterval is a computer system energy-saving technique that reduces CPU power consumption by reducing the precision of software timers to allow the synchronization of process wake-ups, minimizing the number of times the CPU is forced to perform the relatively power-costly operation of entering and exiting idle states"

`TimerCoalescing` is a binary value (`v18 == 3`) with a size of 80 bytes (`v19 == 80`).

```c
if (v18 == 3 && v19 == 80 && !v20[0]) // type REG_BINARY, length 80 bytes, leading dword zero
{
  for (i = 0; i < 3; ++i)
    if (v20[i + 1]) return ZwClose(KeyHandle); // v20[1..3] must be zero

  for (j = 0; j < 4; ++j)
    if (v20[j + 8]) return ZwClose(KeyHandle); // v20[8..11] must be zero

  for (k = 0; k < 4; ++k)
    if (v20[k + 16]) return ZwClose(KeyHandle); // v20[16..19] must be zero

  for (m = 0; (unsigned int)m < 4; ++m)
    if (v20[m + 4] > 0x7FFFFFF5) return ZwClose(KeyHandle); // clamp tolerance index 0 entries

  while (v0 < 4)
  {
    if (v20[v0 + 12] > 0x7FFFFFF5) return ZwClose(KeyHandle); // clamp tolerance index 3 entries
    ++v0;
  }
}
```

As the pseudocode shows eight values have data, all other ones are forced to `0` (four dwords of zeros, four dwords for tolerance index 0, four more zeros, four dwords for tolerance index 3, and zeros).

```json
"HKLM\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows": {
  "TimerCoalescing": { "Type": "REG_BINARY", "Data": "00000000000000000000000000000000F5FFFF7FF5FFFF7FF5FFFF7FF5FFFF7F00000000000000000000000000000000F5FFFF7FF5FFFF7FF5FFFF7FF5FFFF7F00000000000000000000000000000000" }
}
```
Using the highest clamp as shown above will end up with a BSoD (same goes for `0x7FFFFFF4`/`0` and probably any other data).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "CoalescingTimerInterval"; = 1500; // PopCoalescingTimerInterval (0x000005DC) - Units: seconds (multiplies value by -10,000,000, one second in 100 ns units, so the default corresponds to a 25min cadence)
    "DeepIoCoalescingEnabled"; = 0; // PopDeepIoCoalescingEnabled 
```
> https://github.com/5Noxi/wpr-reg-records?tab=readme-ov-file#power-values

```c
void InitTimerPowerSaving(void)
{
  UserSessionState = W32GetUserSessionState();
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveElapse", 43200000LL, UserSessionState + 62692); // 12H?
  v1 = W32GetUserSessionState();
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveCoalescing", 43200000LL, v1 + 62696); // 12H?
}
```

The `CoalescingTimerInterval` value exist (takes a default of `1500` dec, `DeepIoCoalescingEnabled` one is set to `0` by default - both are located in `ntoskrnl.exe`), but doesn't get read on 24H2, the `RITdemonTimerPowerSave...` & `TimerCoalescing` ones get read.

> [power/assets | coalesc-InitTimerCoalescing.c](https://github.com/5Noxi/win-config/blob/main/power/assets/coalesc-InitTimerCoalescing.c)  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Winows-NT.txt

![](https://github.com/5Noxi/win-config/blob/main/power/images/coalesc.png?raw=true)

# Disable USB Battery Saver 

Used to stop USB devices when your screen is off - Obviously only for laptop users.

```
Stop USB devices when my screen is off to help battery.
```
`Bluetooth & devices` > `USB` > `USB battery saver`

> [power/assets | usbbattery-OpenQueryAttemptRecoveryFromUsbPowerDrainValue.c](https://github.com/5Noxi/win-config/blob/main/power/assets/usbbattery-OpenQueryAttemptRecoveryFromUsbPowerDrainValue.c)

# USB Flags

In `USBXHCI.SYS`. Disables S0 idle on the host controller - remains in the working state (S0)?
```
\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags : Allow64KLowOrFullSpeedControlTransfers
\Registry\Machine\SYSTEM\ControlSet001\Control\usbflags : DisableHCS0Idle
```

I didn't do proper research for them, either test them or leave it:
```c
"COMMANDS": {
  "usbflags": {
    "Action": "registry_pattern",
    "Pattern": "HKLM\\SYSTEM\\CurrentControlSet\\Control\\usbflags\\*",
    "Operations": [
      { "Value": "DisableOnSoftRemove", "Type": "REG_DWORD", "Data": 1 },
      { "Value": "DisableRecoveryFromPowerDrain", "Type": "REG_DWORD", "Data": 0 },
      { "Value": "DisableLPM", "Type": "REG_DWORD", "Data": 1 },
      { "Value": "EnableExtendedValidation", "Type": "REG_DWORD", "Data": 0 },
      { "Value": "EnableDiagnosticMode", "Type": "REG_DWORD", "Data": 0 }
    ]
  }
}

// EnableExtendedValidation - used in usbflagsdevicekey and
// \Registry\Machine\SYSTEM\ControlSet001\Services\usbhub\hubg : EnableExtendedValidation

// EnableDiagnosticMode - used in usbflagsdevicekey and
// \Registry\Machine\SYSTEM\ControlSet001\Services\usbhub\hubg : EnableDiagnosticMode
```
```c
v25 = 0;
if ( v26 )
{
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v26,
                        L"02", // g_EnableExtendedValidation ; "02"
                        4LL,
                        &v25,
                        0LL,
                        0LL);
v25 = 0;
UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                      WdfDriverGlobals,
                      v28,
                      L"(*", // g_EnableDiagnosticMode ; "(*"
                      4LL,
                      &v25,
                      0LL,
                      0LL);
```
> [power/assets | devicepower-QueryUsbflagsValuesForDevice.c](https://github.com/5Noxi/win-config/blob/main/power/assets/devicepower-QueryUsbflagsValuesForDevice.c)  
> https://github.com/5Noxi/wpr-reg-records/blob/main/records/USB-Flags.txt

| Power state | ACPI state | Description | 
|-------------|------------|-------------|
| Working | *S0* | The system is fully usable. Hardware components that aren't in use can save power by entering a lower power state. | 
| Sleep (Modern Standby) | *S0* low-power idle | Some SoC systems support a low-power idle state known as [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby). In this state, the system can very quickly switch from a low-power state to high-power state in response to hardware and network events. **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Sleep | *S1*<br> *S2*<br> *S3* | The system appears to be off. The amount of power consumed in states *S1-S3* is less than *S0* and more than *S4*. *S3* consumes less power than *S2*, and *S2* consumes less power than *S1*. Systems typically support one of these three states, not all three.<br><br> In states *S1-S3*, volatile memory is kept refreshed to maintain the system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device.<br><br> *Hybrid sleep*, used on desktops, is where a system uses a hibernation file with *S1-S3*. The hibernation file saves the system state in case the system loses power while in sleep.<br><br> **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Hibernate | *S4* | The system appears to be off. Power consumption is reduced to the lowest level. The system saves the contents of volatile memory to a hibernation file to preserve system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device. The working context can be restored if it's stored on nonvolatile media.<br><br> *Fast startup* is where the user is logged off before the hibernation file is created. This allows for a smaller hibernation file, more appropriate for systems with less storage capabilities. | 
| Soft off | *S5* | The system appears to be off. This state is comprised of a full shutdown and boot cycle. | 
| Mechanical off | *G3* | The system is completely off and consumes no power. The system returns to the working state only after a full reboot. | 

> https://learn.microsoft.com/en-us/windows/win32/power/system-power-states

# Disable Audio Idle

| Parameter              | Desc                                                                                    | Default  | Notes                                                                 |
| ---------------------- | --------------------------------------------------------------------------------------- | -------- | --------------------------------------------------------------------- |
| `ConservationIdleTime` | Idle timeout for the device, when the system is on battery power.                       | `0`      | `0` disables the inactivity timer for this mode, value is in seconds. |
| `PerformanceIdleTime`  | Idle timeout for the device, when the system is on AC power.                            | `0`      | `0` disables the inactivity timer for this mode, value is in seconds. |
| `IdlePowerState`       | Specifies the power state that the device will enter, when power is no longer needed.   | `3` (D3) | Valid values `1 - D1`, `2 - D2`, `3 - D3`.                            |

I currently disable it, by setting the timeouts to `ff ff ff ff` (`~4.29e9 s ≈ 136 years`) & `IdlePowerState` to `1` (`D1`).

| Parameter              | Type           | Revert Hex data     | Parsed value                      | Meaning                       |
| ---------------------- | -------------- | ------------------- | --------------------------------- | ----------------------------- |
| `ConservationIdleTime` | REG_BINARY (3) | `1e,00,00,0`        | malformed; if `1e,00,00,00` -> 30s | `10s` on battery              |
| `PerformanceIdleTime`  | REG_BINARY (3) | `00,00,00,00`       | 0 seconds                         | No idle mgmt on AC            |
| `IdlePowerState`       | REG_BINARY (3) | `03,00,00,00`       | 3                                 | Go to `D3` when idle          |

| Category   | Class | Class GUID                           | Description                                                                                       |
| ---------- | ----- | ------------------------------------ | ------------------------------------------------------------------------------------------------- |
| Multimedia | Media | 4d36e96c-e325-11ce-bfc1-08002be10318 | Includes Audio and DVD multimedia devices, joystick ports, and full-motion video capture devices. |

> https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/audio-device-class-inactivity-timer-implementation  
> https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/audio-subsystem-power-management-for-modern-standby-platforms  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/portcls-registry-power-settings  

# Disable NVMe Perf Throttling

It get intialized, unsure what exactly it does. Might be related to thermal throttling (controller cuts IOPS and bandwidth to lower heat and protect the drive)?

The default data is `0` if the value is missing, but for new installations it's present with the value `1`. Il'll still leave it in here for documentation reasons.

```c
ResultLength = 0;
DestinationString = 0LL;
RtlInitUnicodeString(&DestinationString, L"NVMeDisablePerfThrottling");
if (ZwQueryValueKey(
        KeyHandle,
        &DestinationString,
        KeyValuePartialInformation,
        KeyValueInformation,
        0x110u,
        &ResultLength) < 0)           // query failed
{
    ClassNVMeDisablePerfThrottling = 0; // default if missing
}
else if (v6 == 4 && ResultLength >= 4)  // REG_DWORD
{
    ClassNVMeDisablePerfThrottling = (v7 != 0); // non zero = disable throttling
}
```

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Classpnp.txt  
> [power/assets | nvmeperf-ClassUpdateDynamicRegistrySettings.c](https://github.com/5Noxi/win-config/blob/main/power/assets/nvmeperf-ClassUpdateDynamicRegistrySettings.c)

# Disable Storage Idle States

Disables idle states for NVMe, SSD, SD, HDD. This is currently more of a possible idea. 

If `IdleStatesNumber` is set, the other values are ignored? Let me know if you have a better interpretation.

> The values are located in the `EnergyEstimation` (guesses how much power is used over time), so it's probably related to something else. I'll leave it for documentation reasons (and future extended declaration).

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/Power.txt  
> [power/assets | storageidle-PmPowerContextInitialization.c](https://github.com/5Noxi/win-config/blob/main/power/assets/nvmeperf-ClassUpdateDynamicRegistrySettings.c)

# Disable PM in Standby Mode

This policy setting specifies that power management is disabled when the machine enters connected standby mode.
- If this policy setting is enabled, Windows Connection Manager doesn't manage adapter radios to reduce power consumption when the machine enters connected standby mode.
- If this policy setting isn't configured or is disabled, power management is enabled when the machine enters connected standby mode.

`Disable Modern Standby`:
```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power"; 
    "MSDisabled"; = 1; // PopModernStandbyDisabled

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ModernSleep";
    "EnabledActions"; = 0; // PopAggressiveStandbyActionsRegValue 
    "EnableDsNetRefresh"; = 0; // PopEnableDsNetRefresh 
```
> https://github.com/5Noxi/wpr-reg-records?tab=readme-ov-file#power-values

| Power state | ACPI state | Description | 
|-------------|------------|-------------|
| Working | *S0* | The system is fully usable. Hardware components that aren't in use can save power by entering a lower power state. | 
| Sleep (Modern Standby) | *S0* low-power idle | Some SoC systems support a low-power idle state known as [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby). In this state, the system can very quickly switch from a low-power state to high-power state in response to hardware and network events. **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Sleep | *S1*<br> *S2*<br> *S3* | The system appears to be off. The amount of power consumed in states *S1-S3* is less than *S0* and more than *S4*. *S3* consumes less power than *S2*, and *S2* consumes less power than *S1*. Systems typically support one of these three states, not all three.<br><br> In states *S1-S3*, volatile memory is kept refreshed to maintain the system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device.<br><br> *Hybrid sleep*, used on desktops, is where a system uses a hibernation file with *S1-S3*. The hibernation file saves the system state in case the system loses power while in sleep.<br><br> **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Hibernate | *S4* | The system appears to be off. Power consumption is reduced to the lowest level. The system saves the contents of volatile memory to a hibernation file to preserve system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device. The working context can be restored if it's stored on nonvolatile media.<br><br> *Fast startup* is where the user is logged off before the hibernation file is created. This allows for a smaller hibernation file, more appropriate for systems with less storage capabilities. | 
| Soft off | *S5* | The system appears to be off. This state is comprised of a full shutdown and boot cycle. | 
| Mechanical off | *G3* | The system is completely off and consumes no power. The system returns to the working state only after a full reboot. | 

> https://learn.microsoft.com/en-us/windows/win32/power/system-power-states

```json
{
  "File": "WCM.admx",
  "CategoryName": "WCM_Category",
  "PolicyName": "WCM_DisablePowerManagement",
  "NameSpace": "Microsoft.Policies.WindowsConnectionManager",
  "Supported": "Windows8",
  "DisplayName": "Disable power management in connected standby mode",
  "ExplainText": "This policy setting specifies that power management is disabled when the machine enters connected standby mode. If this policy setting is enabled, Windows Connection Manager does not manage adapter radios to reduce power consumption when the machine enters connected standby mode. If this policy setting is not configured or is disabled, power management is enabled when the machine enters connected standby mode.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\WcmSvc\\GroupPolicy"
  ],
  "ValueName": "fDisablePowerManagement",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```
```powershell
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fAllowFailoverToCellular
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fBlockNonDomain
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fBlockRoaming
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fDisablePowerManagement
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fMinimizeConnections
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\GroupPolicy : fSoftDisconnectConnections
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fAllowFailoverToCellular
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fBlockNonDomain
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fBlockRoaming
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fDisablePowerManagement
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fMinimizeConnections
\Registry\Machine\SOFTWARE\Policies\Microsoft\WINDOWS\Wcmsvc\Local : fSoftDisconnectConnections
```

# Disable NIC Power Savings

You can get a lot of information about data ranges and more from `.inf` files, see examples below.

> https://github.com/5Noxi/wpr-reg-records/blob/main/records/NIC-Intel.txt  
> https://github.com/5Noxi/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-power-management.md

See [intelnet6x.c](https://github.com/5Noxi/win-config/blob/main/power/assets/intelnet6x.c) for reference.

Everything listed below is based on personal research. Mistakes may exist, but I don't think I've made any.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*DeviceSleepOnDisconnect" = 0; // range 0-1
    "*EnableDynamicPowerGating" = 1; // range 0-1
    "CheckForHangTime" = 2; // range 0-60
    "DisableIntelRST" = 1; // range 0-1
    "DisableReset" = 0; // range 0-1
    "DMACoalescing" = 0; // range 0-10240
    "EnableAdaptiveQueuing" = 1; // range 0-1
    "EnableDisconnectedStandby" = 0; // range 0-1
    "EnableHWAutonomous" = 0; // range 0-1
    "EnableModernStandby" = 0; // range 0-1
    "EnablePME" = 0; // range 0-1
    "EnablePowerManagement" = 1; // range 0-1
    "ForceHostExitUlp" = 0; // range 0-1
    "ForceLtrValue" = 65535; // range 0-65535
    "I218DisablePLLShut" = 0; // range 0-1
    "I218DisablePLLShutGiga" = 0; // range 0-1
    "I219DisableK1Off" = 0; // range 0-1
    "RegForceRxPathSerialization" = 0; // range 0-1
    "SidebandUngateOverride" = 0; // range 0-1
    "ULPMode" = 1; // range 0-1
```

> https://github.com/5Noxi/wpr-reg-records#intel-nic-values

```inf
HKR,Ndi\Params\*DeviceSleepOnDisconnect,ParamDesc,    ,%DeviceSleepOnDisconnectDesc%
HKR,Ndi\Params\*DeviceSleepOnDisconnect,type,         ,enum
HKR,Ndi\Params\*DeviceSleepOnDisconnect,default,      ,0
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,0,       ,%Disabled%
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,1,       ,%Enabled%

HKR, Ndi\Params\*EEE,    	                ParamDesc,      0,       %EEE%
HKR, Ndi\Params\*EEE,    	                Type,           0,       "enum"
HKR, Ndi\Params\*EEE\enum, 	                "1",            0,       %Enabled%
HKR, Ndi\Params\*EEE\enum, 	                "0",            0,       %Disabled%
HKR, Ndi\Params\*EEE,    	                Default,        0,       "0"

HKR,Ndi\params\*SelectiveSuspend,	    ParamDesc,  0, %SelectiveSuspend%
HKR,Ndi\params\*SelectiveSuspend,	    default,    0, "1"
HKR,Ndi\params\*SelectiveSuspend,	    type,       0, "enum"
HKR,Ndi\params\*SelectiveSuspend\enum,   "0",        0, "Disabled"
HKR,Ndi\params\*SelectiveSuspend\enum,   "1",        0, "Enabled"

HKR,Ndi\Params\*SSIdleTimeout,      ParamDesc,  0, "SSIdleTimeout"
HKR,Ndi\Params\*SSIdleTimeout,      Type,       0, "int"
HKR,Ndi\Params\*SSIdleTimeout,      Default,    0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Min,        0, "1" ; might also be at 5, which is why I set it to 5
HKR,Ndi\Params\*SSIdleTimeout,      Max,        0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Step,       0, "1"
HKR,Ndi\Params\*SSIdleTimeout,      Base,       0, "10"

HKR, Ndi\params\AdvancedEEE,        ParamDesc,  0, %AdvancedEEE%
HKR, Ndi\params\AdvancedEEE,        optional,   0, "1"
HKR, Ndi\params\AdvancedEEE,        Type,       0, "enum"
HKR, Ndi\params\AdvancedEEE,        Default,    0, "0"
HKR, Ndi\params\AdvancedEEE\enum,   "0",        0, %Disabled%
HKR, Ndi\params\AdvancedEEE\enum,   "1",        0, %Enabled%

[DisableAutoPowerSave.reg]
HKR,,				       AutoPowerSaveModeEnabled, 0, "0"

HKR, Ndi\params\EnableGreenEthernet,        ParamDesc,  0, %GreenEthernet%
;HKR, Ndi\params\EnableGreenEthernet,        optional,   0, "1"
HKR, Ndi\params\EnableGreenEthernet,        Type,       0, "enum"
HKR, Ndi\params\EnableGreenEthernet,        Default,    0, "0"
HKR, Ndi\params\EnableGreenEthernet\enum,   "0",        0, %Disabled%
HKR, Ndi\params\EnableGreenEthernet\enum,   "1",        0, %Enabled%

HKR, Ndi\params\GigaLite,        ParamDesc,  0, %GigaLite%
;HKR, Ndi\params\GigaLite,        optional,   0, "1"
HKR, Ndi\params\GigaLite,        Type,       0, "enum"
HKR, Ndi\params\GigaLite,        Default,    0, "1"
HKR, Ndi\params\GigaLite\enum,   "0",        0, %Disabled%
HKR, Ndi\params\GigaLite\enum,   "1",        0, %Enabled%

HKR,Ndi\params\*IdleRestriction,        ParamDesc,  0, %IdleRestriction%
HKR,Ndi\params\*IdleRestriction,        Type,       0, "enum"
HKR,Ndi\params\*IdleRestriction,        Default,    0, "0"
HKR,Ndi\params\*IdleRestriction\enum,   "0",        0, %RestrictionDisable%
HKR,Ndi\params\*IdleRestriction\enum,   "1",        0, %RestrictionEnable%

HKR,Ndi\params\PowerSavingMode,    ParamDesc,  0, %PowerSavingMode%
HKR,Ndi\params\PowerSavingMode,    Type,       0, "enum"
HKR,Ndi\params\PowerSavingMode,    Default,    0, "1"
HKR,Ndi\params\PowerSavingMode\enum,   "0",    0, %Disabled%
HKR,Ndi\params\PowerSavingMode\enum,   "1",    0, %Enabled%

HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  ParamDesc,              0, %ReduceSpeedOnPowerDown%
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Type,                   0, "enum"
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Default,                0, "1"
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "1",                    0, %Enabled%
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "0",                    0, %Disabled%

HKR,Ndi\Params\ULPMode,                                 Type,                   0, "enum"
HKR,Ndi\Params\ULPMode,                                 Default,                0, "1"
HKR,Ndi\Params\ULPMode\Enum,                            "1",                    0, %Enabled%
HKR,Ndi\Params\ULPMode\Enum,                            "0",                    0, %Disabled%

; Allow host driver to force exit ULP on ME systems
HKR,,                                                   ForceHostExitUlp,       0, "1"

HKR,Ndi\params\WolShutdownLinkSpeed,           ParamDesc,       0, %WolShutdownLinkSpeed%
;HKR,Ndi\params\WolShutdownLinkSpeed,          optional,        0, "1"
HKR,Ndi\params\WolShutdownLinkSpeed,           Type,            0, "enum"
HKR,Ndi\params\WolShutdownLinkSpeed,           Default,         0, "0"
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "0",             0, %10MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "1",             0, %100MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "2",             0, %NotSpeedDown%
```

Reminder: Each adapter uses it's own default values, means that the `default`/`min`/`max` may be different for you. E.g. `SSIdleTimeout` minimum value was `1` in the first setup information file (`.inf`), but `5` in the second.

---

Miscellaneous notes:

```c
"DynamicLTR" = : { "Type": "REG_SZ", "Data": 0 },
"EnableAdvancedDynamicITR" = : { "Type": "REG_SZ", "Data": 0 },
"S3S4WolPowerSaving" = : { "Type": "REG_SZ", "Data": 0 },
"AutoLinkDownPcieMacOff" = : { "Type": "REG_SZ", "Data": 0 }, // "Auto Disable PCIe"
"BatteryModeLinkSpeed" = : { "Type": "REG_SZ", "Data": 2 },  // Similar to WolShutdownLinkSpeed?
// 10MbFirst                      = "10 Mbps First"
// 100MbFirst                     = "100 Mbps First"
// NotSpeedDown                   = "Not Speed Down"
// AdaptiveLinkSpeed              = "Adaptive Link Speed"
// BatteryModeLinkSpeed           = "Battery Mode Link Speed"
"CLKREQ" = : { "Type": "REG_SZ", "Data": 0 },
"EnableCoalesce": { "Type": "REG_SZ", "Data": 0 },
"DMACoalescing": { "Type": "REG_SZ", "Data": 0 },
"CoalesceBufferSize": { "Type": "REG_SZ", "Data": 0 },
"*PacketCoalescing": { "Type": "REG_SZ", "Data": 0 },

"SVOFFMode" = 1 // SV = Save?
"SVOFFModeHWM" = 0
"SVOFFModeTimer" = 0

"EnabledDatapathCycleCounters" = ?
"EnabledDatapathEventCounters" = ?
```

# Disable Audio Execution Power Requests

There's no official documentation on this value, but it probably controls whether audio activity can trigger power execution requests, reducing the responsiveness of the system to power management events, maybe ending up with less efficient power usage or preventing certain power related actions from being triggered.

```c
// Allowed by default
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "AllowAudioToEnableExecutionRequiredPowerRequests"; = 1; // PopPowerRequestActiveAudioEnablesExecutionRequired 
```

> https://github.com/5Noxi/wpr-reg-records#power-values

```c
bool PopPowerRequestEvaluateExecutionRequiredStatus()
{
  char v0; // r8

  v0 = 0;
  if ( PopExecutionRequiredTimeout )
    return !byte_140F0D173
        || PopPowerRequestActiveAudioEnablesExecutionRequired && byte_140F0D172
        || byte_140F0D171
        || MEMORY[0xFFFFF78000000008] - qword_140F0D178 < 10000000
                                                        * (unsigned __int64)(unsigned int)PopExecutionRequiredTimeout;
  return v0;
}
```
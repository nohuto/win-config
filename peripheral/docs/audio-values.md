# Audio Values

You can find all mentioned functions in [decompiled-pseudocode/11-23H2/audiosrv](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiosrv)/[decompiled-pseudocode/11-23H2/audiodg](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/audiodg)/[decompiled-pseudocode/11-23H2/AudioSrvPolicyManager](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/AudioSrvPolicyManager), everything below is currently based on xrefs of `RegGetValueW`. Since the function names often already tell a lot, I've written them down where they're from. See a boot capture of `CurrentVersion\\Audio` key [here](https://github.com/nohuto/regkit/blob/main/assets/records/Audio.txt).

The titles below tell what binary I've the values from.

## Registry Values

### audiodg.exe

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // AERTMemoryInitOnce
  "SkipRTHeap" = 1; // REG_DWORD (bool), 0 = RT (realtime) heap, nonzero = normal C++ heap (for AERTAllocate & AERTFree)

  // CEndpointInstance::CreateStreamEndpointInstance
  "SuppressBridgeTargetGlitchLogging" = 0; // REG_DWORD (bool)

  // CAudioPump::IsTimerRequired
  "DisablePumpBackupTimer" = ?; // REG_DWORD (bool)

  // _lambda_10c7c3905643286e055343d22ac897fe_::operator()
  "AudioDgWatchDogTimerInMs" = 0; // REG_DWORD, range 0-4294967295 ms, the read value gets overwritten with 0 and I didn't see any other points where the edited value could be used (?)
  "UseNewStreamManagementCodePath" = 1; // REG_DWORD (bool)

  // InitializeCpuManager
  "CpuManagementThresholdHns" = 50000; // REG_DWORD, range 0-4294967295 (100 ns units) means default = 5 ms
  "CpuManagementAudioReservedCpuMask" = 0; // REG_QWORD, range 0-18446744073709551615 (0 = auto)

  // CRTThreadManager::InitializeRTOperatingMode
  "RTOperatingMode" = 3; // REG_DWORD, useful range seems 0-4
                         // 0 uses the shared Audio queue
                         // 1 uses it + one MMCSS queue
                         // 2 creates a base queue + queues per APO
                         // 3 uses the shared queue
                         // 4 creates queues per APO

  // CollectExceptionData
  "PreventAudioDGCrashOrReportOnAPOException" = 0; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Parameters";
  // CAudioPump::Initialize
  "AudioDGCPUPercentMax" = 40; // REG_DWORD, range 10-90 (percent), allowed pump processing time per audio period
  "DeadlineDurationThreshold" = 1000; // REG_DWORD, range 0-4294967295 ms (seems unused)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy";
  // IsSkipAPOFailureCheck
  "SkipAPOFailureCheck" = 0; // REG_DWORD (bool)
```

### AudioSrvPolicyManager.dll

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // CProcess::UseOfResourceAllowed
  "AllowClassicOffload" = 0; // REG_DWORD (bool)

  // GrantExemptionForBCMStartupLatency
  "DisableExemptionForBCMStartupLatency" = 0; // REG_DWORD (bool), 0 = can skip BeginBCMStartupLatencyGracePeriod, nonzero disables the exemption & starts the grace period

  // CAastPreStartContext::RuntimeClassInitialize
  "AastRenderDelayInMs" = 0; // REG_DWORD, range 0-4294967295 ms, delays UpdateEndpointVolume

"HKCU\\Software\\Microsoft\\Multimedia\\Audio";
  // LoadUserSettings
  "UserDuckingPreference" = 1; // REG_DWORD, range 0-3, >3 = 1
                               // 0 = -96 dB
                               // 1 = -18 dB
                               // 2 = -6 dB
                               // 3 = 0 dB
```

### audiosrv.dll

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // DerivePeriodicityForStream
  "SkipPeriodicityValidation" = 0; // REG_DWORD (bool)

  // CEndpointCharacteristics::DiscoverProcessingModeCharacteristics
  "ProbeForMinimumPeriod" = 0; // REG_DWORD (bool), nonzero probes when OEM period data is missing
  "MaxCapturePeriodicityInMs" = 0; // REG_DWORD, 0-4294967295 ms (seems unused)

  // CAudioSrv::Initialize
  "UseNewStreamManagementCodePath" = 1; // REG_DWORD (bool)

  // CAudioSrv::EndInitialization
  "EnableCaptureMonitor" = 1; // REG_DWORD (bool), 0 disables stream/capture monitor

  // EffectPolicy::GetAECInsertionPolicy
  "InboxAECPolicy" = 0; // REG_DWORD, range 0-3
  "InboxAECPolicyCommsTmp" = 1; // REG_DWORD, range 0-3

  // CEndpointCharacteristicsCache::RuntimeClassInitialize
  "GlobalDisableThirdPartyEnhancements" = 0; // REG_DWORD (bool), nonzero skips third party driver effect pack configuration

  // wil::details::functor_wrapper_void__lambda_e80bfd59226b44785138f4bfe7079896____::Run
  "DisableGetMixFormatChange" = 0; // REG_DWORD (bool), nonzero blocks tests/use of an 8 channel mix format?

  // CConstraintModel::Initialize
  "ConstraintModelTest" = 0; // REG_DWORD (bool), nonzero reads XML from ResourceSettings\\XMLConfig key instead of per device keys

  // CAudioDGProcess::InstantiateADG
  "EnableProtectedAudioDG" = 0; // REG_DWORD (bool), nonzero uses protected process AudioDG first (fallback to unprotected)

  // CAudioDGProcess::StartADGTerminationTimer
  "AudioDGInactiveTimeout" = 300; // REG_DWORD, 0-4294967295 sec, inactivity delay before AudioDG termination, 0 schedules instantly

  // CAudioSrv::VAD_AudiosrvServiceStart
  "AudioHealthMonitorLimit" = 5; // REG_DWORD, 0-4294967295 (hangs), 0 disables monitor, if hang amount is positive it terminates AudioSrv
  "AudioSrvWatchDogTimerInMs" = 40000; // REG_DWORD, 0-4294967295 ms
  "RenderStreamVolumeTaperPower" = ?; // REG_SZ
  "UnrestrictedPerProcessLoopback" = 0xFFFFFFFF; // REG_DWORD (bool)

  // MyServiceInitialization
  "DevApiIsRunningInVM" = 0; // REG_DWORD (bool)

  // BlockSpatialAudioRegistryGates
  "DisableSpatialAudioGlobal" = 0; // REG_DWORD (bool)
  "DisableSpatialAudioPerEndpoint" = 1; // REG_DWORD (bool), nonzero = PKEY_Endpoint_SpatialNotAllowed
  "DisableSpatialAudioVssFeature" = 0; // REG_DWORD (bool)
  "SpatialAudioHrtfOnByDefault" = 0; // REG_DWORD (bool)

  // IsSpatialComboEndpointDeterminationDisabled
  "DisableSpatialOnComboEndpoints" = 1; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy\\Spatial";
  // AtmosCheck::GetSpatialAudioLicenseGracePeriodInMs
  "SpatialAudioLicenseCheckStartDelay" = 5; // REG_DWORD, range 1-900000 ms, 0/>900000 = 5 ms

  // IsMultiUserSKU
  "SpatialAudioLicenseCheckRequiresUserContext" = 0; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Spatial\\AtmosLicenseDebug";
  // AtmosCheck::QueryLicenseForSpatialSubtypeAndEndpoint
  "AudioSrvLicenseResult" = 0; // REG_DWORD, range 2147483648-4294967295, 0-2147483647 do nothing
  "AudioDGLicenseResult" = 0; // REG_DWORD, range 2147483648-4294967295, ^

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\HoloSI\\Audio";
  // CMonitorManager::UpdateAudioMirroringEnabled
  "AudioMirroringEnabled" = 0; // REG_DWORD (bool)

  // CMonitorManager::UpdateRoutedEndpointId
  "RoutedAudioDevice" = ; // REG_SZ
```


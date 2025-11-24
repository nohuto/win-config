__int64 DllInitialize()
{
  int v0; // ebx
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // rcx
  __int64 v3; // rax
  __int64 v4; // rax
  unsigned int v5; // edi
  _QWORD *Pool; // rax
  void *v7; // rcx
  ULONG ResultLength[2]; // [rsp+38h] [rbp-D0h] BYREF
  void *DestinationString[3]; // [rsp+40h] [rbp-C8h] BYREF
  int OutputBuffer; // [rsp+58h] [rbp-B0h] BYREF
  unsigned int v12; // [rsp+5Ch] [rbp-ACh] BYREF
  int v13; // [rsp+60h] [rbp-A8h] BYREF
  int v14; // [rsp+64h] [rbp-A4h] BYREF
  int v15; // [rsp+68h] [rbp-A0h] BYREF
  int v16; // [rsp+6Ch] [rbp-9Ch] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+70h] [rbp-98h] BYREF
  struct _UNICODE_STRING v18; // [rsp+A0h] [rbp-68h] BYREF
  _BYTE SystemInformation[12]; // [rsp+B8h] [rbp-50h] BYREF
  unsigned int v20; // [rsp+C4h] [rbp-44h]
  unsigned int v21; // [rsp+CCh] [rbp-3Ch]
  struct _OSVERSIONINFOW VersionInformation; // [rsp+F8h] [rbp-10h] BYREF
  char v23; // [rsp+212h] [rbp+10Ah]
  _BYTE KeyValueInformation[4]; // [rsp+218h] [rbp+110h] BYREF
  int v25; // [rsp+21Ch] [rbp+114h]
  unsigned int Buffer[65]; // [rsp+224h] [rbp+11Ch] BYREF

  v0 = 0;
  memset(DestinationString, 0, sizeof(DestinationString));
  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  ResultLength[0] = 0;
  v18 = 0LL;
  memset_0(&VersionInformation.dwMajorVersion, 0, 0x118uLL);
  LOBYTE(OutputBuffer) = 0;
  memset_0(SystemInformation, 0, 0x40uLL);
  v15 = 0;
  v12 = 4;
  v13 = 0;
  v16 = 0;
  if ( ZwPowerInformation((POWER_INFORMATION_LEVEL)66, 0LL, 0, &OutputBuffer, 1u) >= 0 && (_BYTE)OutputBuffer )
    IsSystemAoAC = 1;
  if ( ZwQuerySystemInformation(SystemBasicInformation, SystemInformation, 0x40u, 0LL) >= 0 )
  {
    HighestPhysicalAddress = (unsigned __int64)v21 << 12;
    PhysicalMemorySize = (unsigned __int64)v20 << 12;
  }
  g_HeterogenousCPU = RaDetectHeterogeneousCPU();
  g_InWinPE = RaidpIsControlledWinPEEnvironment();
  RaidpIsControlledUpdateOSEnvironment();
  g_OSisUpgrade = RaidpIsCurrentOsInstallationUpgrade();
  VersionInformation.dwOSVersionInfoSize = 284;
  RtlGetVersion(&VersionInformation);
  if ( (unsigned __int8)(v23 - 2) > 1u )
    g_OSisClient = 1;
  RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"SMR-HostManaged-Enabled");
  if ( (int)ZwQueryLicenseValue(&DestinationString[1], &v15, &v13, v12, &v12) >= 0 && v13 == 1 )
    IsSMREnabled = 1;
  if ( !_InterlockedExchangeAdd(&NumDllInitialize, 1u) )
  {
    StorpRegisterShim();
    qword_1C0156378 = (__int64)&EnclosureIdList;
    EnclosureIdList = &EnclosureIdList;
    ExInitializeResourceLite((PERESOURCE)&WPP_MAIN_CB.Dpc.DpcData);
    RaidLoadEnclosureIdMappings();
    WPP_MAIN_CB.DeviceQueue.Lock = (unsigned __int64)&WPP_MAIN_CB.DeviceQueue.DeviceListHead.Blink;
    WPP_MAIN_CB.DeviceQueue.DeviceListHead.Blink = (_LIST_ENTRY *)&WPP_MAIN_CB.DeviceQueue.DeviceListHead.Blink;
    ExInitializeResourceLite((PERESOURCE)&WPP_MAIN_CB.DeviceExtension);
    RaidLoadATADeviceIdMappings();
    qword_1C01561F8 = (__int64)&NvmeIceList;
    NvmeIceList = &NvmeIceList;
    ExInitializeResourceLite(&NvmeIceListLock);
    StorpWheaAddErrorSource();
    StorKsrInitialize();
    wil_InitializeFeatureStaging();
    CD_SoftNumaIrqlFixEnabled = (unsigned int)Feature_SoftNumaIrqlFix__private_IsEnabledDeviceUsageNoInline() != 0;
    CD_SrbDataCheckReorderEnabled = (unsigned int)Feature_SrbDataCheckReorder__private_IsEnabledDeviceUsageNoInline() != 0;
    GeNativeNVMeEnabledForServer = (unsigned int)Feature_NativeNVMeStackForGeServer__private_IsEnabledDeviceUsageNoInline() != 0;
    GeNativeNVMeEnabledForClient = (unsigned int)Feature_NativeNVMeStackForGeClient__private_IsEnabledDeviceUsageNoInline() != 0;
    FeatureServicingSMRLastLogicalBlockRaceFixEnabled = (unsigned int)Feature_Servicing_SMRLastLogicalBlockRaceFix__private_IsEnabledDeviceUsageNoInline() != 0;
    FeatureServicingScsiPassthroughRobustness = (unsigned int)Feature_Servicing_ScsiPassthroughRobustness__private_IsEnabledDeviceUsageNoInline() != 0;
    FeatureHardenCodeForPassthroughCommand = (unsigned int)Feature_HardenCodeForPassthroughCommand__private_IsEnabledDeviceUsageNoInline() != 0;
    if ( (unsigned int)Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline() )
      KeInitializeSpinLock(&NvmeIceListSpinLock);
  }
  g_MaximumProcessorCount = KeQueryMaximumProcessorCountEx(0xFFFFu);
  g_RecommendedSharedDataAlignment = KeGetRecommendedSharedDataAlignment();
  RtlInitUnicodeString(&v18, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StorPort\\");
  ObjectAttributes.Length = 48;
  ObjectAttributes.ObjectName = &v18;
  ObjectAttributes.RootDirectory = 0LL;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  if ( ZwOpenKey(DestinationString, 0x20019u, &ObjectAttributes) >= 0 )
  {
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"DpcCompletionLimit");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      DpcCompletionLimit = Buffer[0];
      if ( !Buffer[0] )
        DpcCompletionLimit = -1;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"HiberFileHybridPriority");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 3 )
    {
      HiberFileHybridPriority = RaidDecodeSmRegistryBlob((PUCHAR)Buffer);
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"HmbAllocationPolicy");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4 )
    {
      HmbAllocationPolicy = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"HmbMaximumSizeInBytes");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) < 0 )
    {
      LODWORD(v1) = 0x4000000;
      v2 = (unsigned __int64)PhysicalMemorySize >> 6;
      if ( (unsigned __int64)PhysicalMemorySize >> 6 >= 0x4000000 )
      {
        LODWORD(v1) = 0x40000000;
        if ( v2 <= 0x40000000 )
        {
          v1 = (unsigned __int64)PhysicalMemorySize >> 6;
          if ( (v2 & 0xFFF) != 0 )
            LODWORD(v1) = v2 & 0x7FFFF000;
        }
      }
    }
    else
    {
      if ( v25 != 4 )
        goto LABEL_36;
      LODWORD(v1) = 0x40000000;
      HmbMaximumSize = Buffer[0];
      if ( Buffer[0] <= 0x40000000 )
      {
        if ( (Buffer[0] & 0xFFF) != 0 )
          HmbMaximumSize = Buffer[0] & 0x7FFFF000;
        goto LABEL_36;
      }
    }
    HmbMaximumSize = v1;
LABEL_36:
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"MiniportBugActionPolicy");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4 )
    {
      MiniportBugActionPolicy = Buffer[0];
      if ( Buffer[0] >= 3 )
        MiniportBugActionPolicy = 1;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"AsyncStart");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4 )
    {
      StorageAsyncStart = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryPerformanceHighResolutionTimer");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingPerformanceHighResolutionTimer = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryPerformanceEnabled");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingPerformanceEnabled = Buffer[0];
    }
    if ( g_StorpTraceLoggingPerformanceEnabled )
    {
      RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryIoSizeDistributionEnabled");
      if ( ZwQueryValueKey(
             DestinationString[0],
             (PUNICODE_STRING)&DestinationString[1],
             KeyValuePartialInformation,
             KeyValueInformation,
             0x110u,
             ResultLength) >= 0
        && v25 == 4
        && ResultLength[0] >= 4 )
      {
        g_StorpTraceLoggingIoSizeDistributionEnabled = Buffer[0];
      }
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryPerformancePeriod");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      v3 = Buffer[0];
      if ( Buffer[0] )
      {
        if ( Buffer[0] >= 0x18uLL )
          v3 = 24LL;
        g_StorpTraceLoggingPerformancePeriod = 36000000000LL * v3;
      }
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryErrorDataEnabled");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingErrorDataEnabled = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryDeviceHealthEnabled");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingDeviceHealthEnabled = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryDeviceHealthPeriod");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      v4 = Buffer[0];
      if ( Buffer[0] )
      {
        if ( Buffer[0] >= 0x18uLL )
          v4 = 24LL;
        g_StorpTraceLoggingDeviceHealthTick = v4;
        g_StorpTraceLoggingDeviceHealthPeriod = 36000000000LL * v4;
      }
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryCriticalEventEnabled");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingCriticalEventEnabled = Buffer[0];
      g_StorpTraceLoggingCriticalEventEnabledSetByRegistry = 1;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"TelemetryCriticalEventMaximum");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_StorpTraceLoggingCriticalEventMaximum = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"ExtendedDSMCommandsSupported");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      ExtendedDSMCommandsSupported = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"FUAEnable");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      FUAEnabled = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"ForwardedIo");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      Feature_EnableForwardedIo__private_IsEnabledPreCheck();
      ForwardedIoEnabled = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"QoSFlags");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_QosFlags = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"MaxPreAllocatedIoResourceCount");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4
      && Buffer[0] )
    {
      StorPreAllocatedMaxIoResourceCount = Buffer[0];
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"DFxEnable");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      DFxEnabled = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"OverrideDeviceUniqueIDCapability");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      OverrideDeviceUniqueIDCapability = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"DisableRuntimePower");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      RuntimePowerDisabled = Buffer[0] != 0;
    }
    g_ProcessorCountPerGateway = 8;
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"ProcsPerGateway");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      g_ProcessorCountPerGateway = Buffer[0];
      if ( Buffer[0] >= 4 )
      {
        if ( Buffer[0] > 0x10 )
          g_ProcessorCountPerGateway = 16;
      }
      else
      {
        g_ProcessorCountPerGateway = 4;
      }
    }
    if ( g_ProcessorCountPerGateway > (unsigned int)g_MaximumProcessorCount )
      g_ProcessorCountPerGateway = g_MaximumProcessorCount;
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"MFNDEnable");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      MFNDEnabled = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"CreateControlObject");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      CreateControlObject = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"DisableIEEE1667");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      DisableIEEE1667 = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"EnableNativeTcg");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      EnableNativeTcg = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"EnableRegistryWatch");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      EnableRegistryWatch = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"KsrPowerDownOptimizationEnabled");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      KsrPowerDownOptimizationEnabled = Buffer[0] != 0;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"EnableNVMeICE");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      v5 = Buffer[0];
      EnableNVMeICE = Buffer[0] != 0;
      if ( (unsigned int)Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline() )
        EnableNVMeICEV2 = v5 >= 2;
    }
    RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"DisableNativeNVMeStack");
    if ( ZwQueryValueKey(
           DestinationString[0],
           (PUNICODE_STRING)&DestinationString[1],
           KeyValuePartialInformation,
           KeyValueInformation,
           0x110u,
           ResultLength) >= 0
      && v25 == 4
      && ResultLength[0] >= 4 )
    {
      DisableNativeNVMeStack = Buffer[0] != 0;
    }
    StorpUpdateDynamicRegistrySettings(DestinationString[0]);
    if ( EnableRegistryWatch
      && (Pool = (_QWORD *)RaidAllocatePool(64LL, 192LL, 1465016658LL, 0LL), (RegWatchContext = Pool) != 0LL) )
    {
      *Pool = DestinationString[0];
      Pool[1] = StorpUpdateDynamicRegistrySettings;
      StorpInitRegistryWatch(DestinationString[0]);
      StorpWatchForRegistryChanges(RegWatchContext);
      v7 = 0LL;
      DestinationString[0] = 0LL;
    }
    else
    {
      v7 = DestinationString[0];
    }
    if ( v7 )
      ZwClose(v7);
  }
  StorPortpInitializeDriverProxyInterfaces();
  if ( SpVrfyLevel != -1 )
  {
    RtlInitUnicodeString(
      (PUNICODE_STRING)&DestinationString[1],
      L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StorPort\\Verifier");
    ObjectAttributes.Length = 48;
    ObjectAttributes.ObjectName = (PUNICODE_STRING)&DestinationString[1];
    ObjectAttributes.RootDirectory = 0LL;
    ObjectAttributes.Attributes = 576;
    *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
    if ( ZwOpenKey(DestinationString, 0x20019u, &ObjectAttributes) >= 0 )
    {
      RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"VerifyLevel");
      if ( ZwQueryValueKey(
             DestinationString[0],
             (PUNICODE_STRING)&DestinationString[1],
             KeyValuePartialInformation,
             KeyValueInformation,
             0x110u,
             ResultLength) >= 0
        && v25 == 4
        && ResultLength[0] >= 4 )
      {
        SpVrfyLevel |= Buffer[0];
        if ( SpVrfyLevel != -1 && !StorPortVerifierInitialized && (unsigned __int8)SpVerifierInitialization() )
        {
          StorPortVerifierInitialized = 1;
          RaidVerifierEnabled = 1;
        }
      }
      ZwClose(DestinationString[0]);
    }
    v14 = 1;
    EmClientQueryRuleState(&GUID_STORAGE_DEVICE_D3_ALLOWED_RULE, &v14);
    if ( v14 == 2 && g_OSisClient )
      StorageD3AllowedOnCurrentPlatform = 1;
    RtlInitUnicodeString(
      (PUNICODE_STRING)&DestinationString[1],
      L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage");
    ObjectAttributes.Length = 48;
    ObjectAttributes.ObjectName = (PUNICODE_STRING)&DestinationString[1];
    ObjectAttributes.RootDirectory = 0LL;
    ObjectAttributes.Attributes = 576;
    *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
    if ( ZwOpenKey(DestinationString, 0x20019u, &ObjectAttributes) >= 0 )
    {
      RtlInitUnicodeString((PUNICODE_STRING)&DestinationString[1], L"StorageD3InModernStandby");
      if ( ZwQueryValueKey(
             DestinationString[0],
             (PUNICODE_STRING)&DestinationString[1],
             KeyValuePartialInformation,
             KeyValueInformation,
             0x110u,
             ResultLength) >= 0
        && v25 == 4
        && ResultLength[0] >= 4 )
      {
        LOBYTE(v0) = Buffer[0] != 0;
        StorageD3RegistryState = v0;
      }
      ZwClose(DestinationString[0]);
    }
    ExQueryTimerResolution(&StorMaximumTimeInterval, &StorMinimumTimeInterval, &v16);
    GetCpuInformation();
    InitializeNumaNodeCompletionAffinity();
  }
  return 0LL;
}
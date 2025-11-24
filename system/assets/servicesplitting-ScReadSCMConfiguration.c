void ScReadSCMConfiguration(void)
{
  unsigned int v0; // eax
  unsigned int RetryNetworkLogonTimeout; // eax
  HKEY v2; // rbx
  int v3; // eax
  __int64 v4; // rdx
  int IsSvchostDebugValueSet; // eax
  unsigned int RedirectedSCMConfigDword; // eax
  __int64 v7; // rdx
  int v8; // r9d
  int v9; // ecx
  int v10; // r8d
  int v11; // r9d
  HKEY v12; // rcx
  int v13; // eax
  DWORD Type; // [rsp+48h] [rbp-29h] BYREF
  DWORD cbData; // [rsp+4Ch] [rbp-25h] BYREF
  BYTE Data[4]; // [rsp+50h] [rbp-21h] BYREF
  HKEY hKey; // [rsp+58h] [rbp-19h] BYREF
  BYTE v18[4]; // [rsp+60h] [rbp-11h] BYREF
  int v19; // [rsp+64h] [rbp-Dh] BYREF
  int v20; // [rsp+68h] [rbp-9h] BYREF
  __int64 v21; // [rsp+70h] [rbp-1h] BYREF
  _MEMORYSTATUSEX Buffer; // [rsp+78h] [rbp+7h] BYREF

  hKey = 0LL;
  Type = 0;
  g_StateSeparationEnabled = (unsigned __int8)RtlIsStateSeparationEnabled();
  v0 = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"System\\CurrentControlSet\\Control", 0, 0x20019u, &hKey);
  if ( v0 )
  {
    if ( WPP_GLOBAL_Control != (PRPC_ASYNC_STATE)&WPP_GLOBAL_Control && (BYTE4(WPP_GLOBAL_Control->UserInfo) & 1) != 0 )
      WPP_SF_D(WPP_GLOBAL_Control->StubInfo, 10LL, &WPP_73e763182c4133cee281a4c48659d989_Traceguids, v0);
    hKey = 0LL;
  }
  RetryNetworkLogonTimeout = ScGetRetryNetworkLogonTimeout();
  v2 = hKey;
  g_NetworkLogonRetryTimeout = RetryNetworkLogonTimeout;
  *(_DWORD *)&g_fEnableTakeOwnershipEvent = 0;
  cbData = 4;
  if ( hKey )
  {
    if ( !RegQueryValueExW(hKey, L"EnableTakeOwnershipEvent", 0LL, &Type, &g_fEnableTakeOwnershipEvent, &cbData)
      && Type != 4 )
    {
      *(_DWORD *)&g_fEnableTakeOwnershipEvent = 0;
    }
    v2 = hKey;
  }
  memset(&Buffer, 0, sizeof(Buffer));
  Buffer.dwLength = 64;
  *(_DWORD *)Data = 0;
  cbData = 4;
  if ( v2 )
  {
    if ( RegQueryValueExW(v2, L"SvcHostSplitThresholdInKB", 0LL, &Type, Data, &cbData) || Type == 4 )
    {
      v3 = *(_DWORD *)Data;
    }
    else
    {
      v3 = 0;
      *(_DWORD *)Data = 0;
    }
    if ( v3 && GlobalMemoryStatusEx(&Buffer) && Buffer.ullTotalPhys >= (unsigned __int64)*(unsigned int *)Data << 10 )
    {
      LOBYTE(v4) = 1;
      wil::details::FeatureImpl<__WilFeatureTraits_Feature_SvchostSplit>::ReportUsage(
        &`wil::Feature<__WilFeatureTraits_Feature_SvchostSplit>::GetImpl'::`2'::impl,
        v4);
      IsSvchostDebugValueSet = 1;
      goto LABEL_22;
    }
    v2 = hKey;
  }
  IsSvchostDebugValueSet = ScIsSvchostDebugValueSet(v2);
LABEL_22:
  g_fSplitSvcHost = IsSvchostDebugValueSet;
  *(_DWORD *)Data = 0;
  RedirectedSCMConfigDword = ScGetRedirectedSCMConfigDword(L"HandleTracking", (unsigned int *)Data);
  v8 = 0;
  if ( !RedirectedSCMConfigDword )
    LOBYTE(v8) = *(_DWORD *)Data != 0;
  g_HandleTrackingEnabled = v8;
  if ( (unsigned int)dword_1400CA2A0 > 5 && (unsigned __int8)tlgKeywordOn(&dword_1400CA2A0, 0x400000000000LL) )
  {
    v19 = g_StateSeparationEnabled;
    v20 = g_fSplitSvcHost;
    v21 = 0x1000000LL;
    *(_DWORD *)Data = v11;
    _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<4>,_tlgWrapperByVal<8>>(
      v9,
      (unsigned int)&unk_1400BE181,
      v10,
      v11,
      (__int64)&v20,
      (__int64)&v19,
      (__int64)Data,
      (__int64)&v21);
  }
  v12 = hKey;
  *(_DWORD *)&g_dwRpcOverTcpKeepAliveTimes = 0;
  cbData = 4;
  if ( hKey )
  {
    if ( !RegQueryValueExW(hKey, L"RpcOverTcpKeepAliveTimes", 0LL, &Type, &g_dwRpcOverTcpKeepAliveTimes, &cbData)
      && Type != 4 )
    {
      *(_DWORD *)&g_dwRpcOverTcpKeepAliveTimes = 0;
    }
    v12 = hKey;
  }
  *(_DWORD *)&g_fDisableRemoteScmEndpoints = 0;
  cbData = 4;
  if ( v12 )
  {
    if ( !RegQueryValueExW(v12, L"DisableRemoteScmEndpoints", 0LL, &Type, &g_fDisableRemoteScmEndpoints, &cbData)
      && Type != 4 )
    {
      *(_DWORD *)&g_fDisableRemoteScmEndpoints = 0;
    }
    v12 = hKey;
  }
  *(_DWORD *)&g_ExemptRemoteCaller = 0;
  cbData = 4;
  if ( v12 && !RegQueryValueExW(v12, L"RemoteAccessExemption", 0LL, &Type, &g_ExemptRemoteCaller, &cbData) && Type != 4 )
    *(_DWORD *)&g_ExemptRemoteCaller = 0;
  LOBYTE(v7) = 1;
  wil::details::FeatureImpl<__WilFeatureTraits_Feature_DisableUniqueServiceDisplayNameValidation>::ReportUsage(
    &`wil::Feature<__WilFeatureTraits_Feature_DisableUniqueServiceDisplayNameValidation>::GetImpl'::`2'::impl,
    v7);
  *(_DWORD *)&g_EnableUniqueDisplayNameValidation = 0;
  cbData = 4;
  if ( hKey
    && !RegQueryValueExW(hKey, L"ValidateServiceDisplayName", 0LL, &Type, &g_EnableUniqueDisplayNameValidation, &cbData)
    && Type != 4 )
  {
    *(_DWORD *)&g_EnableUniqueDisplayNameValidation = 0;
  }
  g_GlobalProcessAffinityMask = ScGetGlobalProcessAffinityMask();
  g_CetSupportEnabled = IsUserCetAvailableInEnvironment(0LL);
  *(_DWORD *)v18 = 0;
  cbData = 4;
  if ( hKey )
  {
    if ( RegQueryValueExW(hKey, L"RelaxGroupLoadOrder", 0LL, &Type, v18, &cbData) || Type == 4 )
    {
      v13 = *(_DWORD *)v18;
    }
    else
    {
      v13 = 0;
      *(_DWORD *)v18 = 0;
    }
    if ( v13 )
      g_RelaxGroupLoadOrder = 1;
    if ( hKey )
      RegCloseKey(hKey);
  }
}

__int64 __fastcall sub_1400034F0(HANDLE KeyHandle)
{
  unsigned int v2; // ebx
  int v3; // ebp
  _DWORD *Heap; // rax
  _DWORD *v5; // rdi
  int v6; // esi
  _UNICODE_STRING ValueName; // [rsp+30h] [rbp-28h] BYREF
  ULONG Length; // [rsp+68h] [rbp+10h] BYREF
  int v10; // [rsp+70h] [rbp+18h] BYREF

  v2 = 0;
  v10 = 0;
  v3 = 0;
  ValueName = 0;
  RtlInitUnicodeString(&ValueName, L"SvcHostSplitDisable");
  Length = 16;
  Heap = RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 8u, 0x10u);
  v5 = Heap;
  if ( Heap )
  {
    v6 = NtQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, Heap, Length, &Length);
    if ( (int)(v6 + 0x80000000) < 0 || v6 == -2147483643 )
    {
      v3 = v5[1];
      if ( v6 >= 0 )
        sub_1400A27C0(&v10, v5 + 3, (unsigned int)v5[2]);
    }
    RtlFreeHeap(NtCurrentPeb()->ProcessHeap, 0, v5);
    if ( !RtlNtStatusToDosError(v6) && v3 == 4 )
      LOBYTE(v2) = v10 != 0;
  }
  else if ( pAsync != (PRPC_ASYNC_STATE)&pAsync && (BYTE4(pAsync->UserInfo) & 1) != 0 )
  {
    sub_140027EA0(pAsync->StubInfo, 113, &unk_1400AB888);
  }
  return v2;
}

__int64 __fastcall sub_140056854(HKEY a1)
{
  unsigned int v1; // ebx
  LSTATUS RegistryValueWithFallbackW; // eax
  __int64 v5; // [rsp+50h] [rbp-10h] BYREF
  DWORD Type; // [rsp+88h] [rbp+28h] BYREF
  int Data; // [rsp+90h] [rbp+30h] BYREF
  DWORD cbData; // [rsp+98h] [rbp+38h] BYREF

  v1 = 0;
  cbData = 0;
  Type = 0;
  Data = 0;
  v5 = 0;
  if ( dword_1400CE050 )
  {
    sub_140058100(&v5);
    RegistryValueWithFallbackW = GetRegistryValueWithFallbackW(
                                   -2147483646,
                                   v5,
                                   a1,
                                   0,
                                   L"SvcHostDebug",
                                   16,
                                   &Type,
                                   &Data,
                                   4,
                                   &cbData);
  }
  else
  {
    if ( !a1 )
      return v1;
    cbData = 4;
    RegistryValueWithFallbackW = RegQueryValueExW(a1, L"SvcHostDebug", 0, &Type, (LPBYTE)&Data, &cbData);
  }
  if ( !RegistryValueWithFallbackW && Type == 4 )
    LOBYTE(v1) = Data != 0;
  return v1;
}
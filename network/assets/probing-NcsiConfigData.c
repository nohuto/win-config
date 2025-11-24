void __fastcall NcsiConfigData::InternalQueryRegParamRegistry(NcsiConfigData *this, char a2)
{
  int v2; // r13d
  NcsiConfigData *v3; // rcx
  char IsDisableNCSIConnectivityEvaluationSet; // r12
  int v5; // edx
  const WCHAR *v6; // rbx
  LPCWSTR *v7; // r8
  char v8; // si
  NcsiConfigData *v9; // rcx
  char v10; // al
  NcsiConfigData *v11; // rcx
  char v12; // si
  char v13; // r12
  bool IsPassivePollingDisabled; // al
  bool v15; // cl
  const char *v16; // r9
  __int64 v17; // rax
  const WCHAR *v18; // rdx
  unsigned int v19; // eax
  struct NCSI_DNS_PROBE_CONFIG *v20; // r14
  struct NCSI_DNS_PROBE_CONFIG *v21; // rsi
  struct _NCSI_WEB_PROBE_CONFIG *v22; // rbx
  NcsiConfigData *v23; // rcx
  struct _NCSI_WEB_PROBE_CONFIG *v24; // rdi
  NcsiConfigData *v25; // rcx
  _OWORD *v26; // rcx
  __int64 v27; // rax
  _OWORD *v28; // rcx
  __int64 v29; // rax
  int v30; // eax
  _OWORD *v31; // rcx
  _OWORD *v32; // rax
  __int64 v33; // rdx
  _OWORD *v34; // rax
  __int64 v35; // rdx
  struct _NCSI_WEB_PROBE_CONFIG *v36; // rdx
  __int64 v37; // rbx
  __int64 v38; // r9
  DWORD LastError; // eax
  __int32 v40; // ecx
  __int32 v41; // edx
  __int32 v42; // eax
  __int64 v43; // rdx
  char v44; // [rsp+30h] [rbp-D0h]
  char v45; // [rsp+30h] [rbp-D0h]
  char v47; // [rsp+31h] [rbp-CFh]
  __int128 v48; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v49; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v50; // [rsp+E0h] [rbp-20h] BYREF
  __int128 v51; // [rsp+F0h] [rbp-10h] BYREF
  __int128 v52; // [rsp+100h] [rbp+0h] BYREF
  __int128 v53; // [rsp+110h] [rbp+10h] BYREF
  __int128 v54; // [rsp+120h] [rbp+20h] BYREF
  __int128 v55; // [rsp+130h] [rbp+30h] BYREF
  __int128 v56; // [rsp+140h] [rbp+40h] BYREF
  __int128 v57; // [rsp+150h] [rbp+50h] BYREF
  __int128 v58; // [rsp+160h] [rbp+60h] BYREF
  __int128 v59; // [rsp+170h] [rbp+70h] BYREF
  __int128 v60; // [rsp+180h] [rbp+80h] BYREF
  __int128 v61; // [rsp+190h] [rbp+90h] BYREF
  __int128 v62; // [rsp+1A0h] [rbp+A0h] BYREF
  __int128 v63; // [rsp+1B0h] [rbp+B0h] BYREF
  __int128 v64; // [rsp+1C0h] [rbp+C0h] BYREF
  __int128 v65; // [rsp+1D0h] [rbp+D0h] BYREF
  __int128 v66; // [rsp+1E0h] [rbp+E0h] BYREF
  __int128 v67; // [rsp+1F0h] [rbp+F0h] BYREF
  __int128 v68; // [rsp+200h] [rbp+100h] BYREF
  __int128 v69; // [rsp+210h] [rbp+110h] BYREF
  __int128 v70; // [rsp+220h] [rbp+120h] BYREF
  __int128 v71; // [rsp+230h] [rbp+130h] BYREF
  __int128 v72; // [rsp+240h] [rbp+140h] BYREF
  __int128 v73; // [rsp+250h] [rbp+150h] BYREF
  __int128 v74; // [rsp+260h] [rbp+160h] BYREF
  __int128 v75; // [rsp+270h] [rbp+170h] BYREF
  __int128 v76; // [rsp+280h] [rbp+180h] BYREF
  __int128 v77; // [rsp+290h] [rbp+190h] BYREF
  __int128 v78; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int128 v79; // [rsp+2B0h] [rbp+1B0h] BYREF
  __int128 v80; // [rsp+2C0h] [rbp+1C0h] BYREF
  __int128 v81; // [rsp+2D0h] [rbp+1D0h] BYREF
  __int128 v82; // [rsp+2E0h] [rbp+1E0h] BYREF
  __int128 v83; // [rsp+2F0h] [rbp+1F0h] BYREF
  _BYTE v84[560]; // [rsp+300h] [rbp+200h] BYREF
  _BYTE v85[560]; // [rsp+530h] [rbp+430h] BYREF
  _BYTE v86[1568]; // [rsp+760h] [rbp+660h] BYREF
  _BYTE Src[1568]; // [rsp+D80h] [rbp+C80h] BYREF
  HKEY v88; // [rsp+13A0h] [rbp+12A0h] BYREF
  HKEY phkResult; // [rsp+13A8h] [rbp+12A8h] BYREF
  HKEY v90; // [rsp+13B0h] [rbp+12B0h] BYREF
  __int128 v91; // [rsp+13B8h] [rbp+12B8h] BYREF
  __int64 v92; // [rsp+13C8h] [rbp+12C8h]
  struct _NCSI_WEB_PROBE_CONFIG *v93; // [rsp+13D0h] [rbp+12D0h] BYREF
  struct _RTL_CRITICAL_SECTION *v94; // [rsp+13D8h] [rbp+12D8h] BYREF
  struct NCSI_DNS_PROBE_CONFIG *v95; // [rsp+13E0h] [rbp+12E0h] BYREF
  struct NCSI_DNS_PROBE_CONFIG *v96; // [rsp+13E8h] [rbp+12E8h] BYREF
  struct _NCSI_WEB_PROBE_CONFIG *v97; // [rsp+13F0h] [rbp+12F0h] BYREF
  union _SOCKADDR_INET v98; // [rsp+13F8h] [rbp+12F8h] BYREF
  union _SOCKADDR_INET v99; // [rsp+1418h] [rbp+1318h] BYREF
  _BYTE v100[64]; // [rsp+1440h] [rbp+1340h] BYREF
  int v101; // [rsp+1480h] [rbp+1380h]
  _BYTE v102[64]; // [rsp+1490h] [rbp+1390h] BYREF
  int v103; // [rsp+14D0h] [rbp+13D0h]

  phkResult = 0LL;
  RegOpenKeyExW(HKEY_LOCAL_MACHINE, c_regKeyParametersConfig, 0, 0x20019u, &phkResult);
  v2 = g_ncsiConfigData;
  IsDisableNCSIConnectivityEvaluationSet = NcsiConfigData::IsDisableNCSIConnectivityEvaluationSet(v3);
  if ( !v5 )
  {
    v53 = *(_OWORD *)&c_regValuePassivePollPeriod;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A08, GetDWordValue(phkResult, &v53, 15LL));
    v54 = *(_OWORD *)&c_regValueDisablePassivePollActiveSessionRequirement;
    _InterlockedExchange((_DWORD *)&qword_1800A0A08 + 1, GetDWordValue(phkResult, &v54, 0LL));
    v51 = *(_OWORD *)&c_regValueStaleThreshold;
    _InterlockedExchange(&dword_1800A0A10, GetDWordValue(phkResult, &v51, 30LL));
    v55 = *(_OWORD *)&c_regValueHttpTimeout;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A14, GetDWordValue(phkResult, &v55, 35LL));
    v56 = *(_OWORD *)&c_regValueActiveProbing;
    _InterlockedExchange((volatile __int32 *)&g_ncsiConfigData, GetDWordValue(phkResult, &v56, 0LL));
    v57 = *(_OWORD *)&c_regValueMaxActiveProbes;
    _InterlockedExchange((_DWORD *)&g_ncsiConfigData + 1, GetDWordValue(phkResult, &v57, 0LL));
    v58 = *(_OWORD *)&c_regValueMinimumInternetHopCount;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A1C, GetDWordValue(phkResult, &v58, 8LL));
    v59 = *(_OWORD *)&c_regValueCorpLocationProbeTimeout;
    _InterlockedExchange(&dword_1800A0A2C, GetDWordValue(phkResult, &v59, 35LL));
    v60 = *(_OWORD *)&c_regValueCorpLocationInitialRetryBackoff;
    _InterlockedExchange(&dword_1800A0A30, GetDWordValue(phkResult, &v60, 1LL));
    v61 = *(_OWORD *)&c_regValueCorpLocationRetryBackoffCap;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A34, GetDWordValue(phkResult, &v61, 1024LL));
    v62 = *(_OWORD *)&c_regValueTestMode;
    _InterlockedExchange(&dword_1800A0A44, GetDWordValue(phkResult, &v62, 0LL));
    v63 = *(_OWORD *)&c_regValueReprobeThreshold;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A60, GetDWordValue(phkResult, &v63, 10000LL));
    v64 = *(_OWORD *)&c_regValueUserActiveProbing;
    _InterlockedExchange((_DWORD *)&qword_1800A0A60 + 1, GetDWordValue(phkResult, &v64, 0LL));
    v65 = *(_OWORD *)&c_regValueCaptivePortalTimer;
    _InterlockedExchange((_DWORD *)&qword_1800A0A68 + 1, GetDWordValue(phkResult, &v65, 0LL));
    v66 = *(_OWORD *)&c_regValueCaptivePortalIncrements;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A74, GetDWordValue(phkResult, &v66, 5LL));
    v67 = *(_OWORD *)&c_regValueCaptivePortalTimerMax;
    _InterlockedExchange(&dword_1800A0A70, GetDWordValue(phkResult, &v67, 30LL));
    v68 = *(_OWORD *)&c_regValueDisableRetryFallbackUrl;
    _InterlockedExchange((_DWORD *)&qword_1800A0A74 + 1, GetDWordValue(phkResult, &v68, 0LL));
    v69 = *(_OWORD *)&c_regValueDisableNCSIConnectivityEvaluation;
    _InterlockedExchange(&dword_1800A0A7C, GetDWordValue(phkResult, &v69, 0LL));
  }
  v6 = (const WCHAR *)&g_ncsiRegistry;
  v7 = &g_ncsiRegistry;
  if ( (unsigned __int64)qword_18009FD98 > 7 )
    v7 = (LPCWSTR *)g_ncsiRegistry;
  v8 = std::_Traits_equal<std::char_traits<unsigned short>>(c_regKeyParametersConfig, 60LL, v7, qword_18009FD90);
  v44 = v8;
  v88 = 0LL;
  if ( (unsigned __int64)qword_18009FD98 > 7 )
    v6 = g_ncsiRegistry;
  if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, v6, 0, 0x20019u, &v88) && !v8 )
  {
    v70 = *(_OWORD *)&c_regValuePassivePollPeriod;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A08, GetDWordValue(v88, &v70, (unsigned int)qword_1800A0A08));
    v71 = *(_OWORD *)&c_regValueDisablePassivePollActiveSessionRequirement;
    _InterlockedExchange((_DWORD *)&qword_1800A0A08 + 1, GetDWordValue(v88, &v71, HIDWORD(qword_1800A0A08)));
    v72 = *(_OWORD *)&c_regValueStaleThreshold;
    _InterlockedExchange(&dword_1800A0A10, GetDWordValue(v88, &v72, (unsigned int)dword_1800A0A10));
    v73 = *(_OWORD *)&c_regValueHttpTimeout;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A14, GetDWordValue(v88, &v73, (unsigned int)qword_1800A0A14));
    v74 = *(_OWORD *)&c_regValueActiveProbing;
    _InterlockedExchange((volatile __int32 *)&g_ncsiConfigData, GetDWordValue(v88, &v74, g_ncsiConfigData));
    v75 = *(_OWORD *)&c_regValueMaxActiveProbes;
    _InterlockedExchange((_DWORD *)&g_ncsiConfigData + 1, GetDWordValue(v88, &v75, *(&g_ncsiConfigData + 1)));
    v76 = *(_OWORD *)&c_regValueMinimumInternetHopCount;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A1C, GetDWordValue(v88, &v76, (unsigned int)qword_1800A0A1C));
    v77 = *(_OWORD *)&c_regValueCorpLocationProbeTimeout;
    _InterlockedExchange(&dword_1800A0A2C, GetDWordValue(v88, &v77, (unsigned int)dword_1800A0A2C));
    v78 = *(_OWORD *)&c_regValueCorpLocationInitialRetryBackoff;
    _InterlockedExchange(&dword_1800A0A30, GetDWordValue(v88, &v78, (unsigned int)dword_1800A0A30));
    v79 = *(_OWORD *)&c_regValueCorpLocationRetryBackoffCap;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A34, GetDWordValue(v88, &v79, (unsigned int)qword_1800A0A34));
    v80 = *(_OWORD *)&c_regValueTestMode;
    _InterlockedExchange(&dword_1800A0A44, GetDWordValue(v88, &v80, (unsigned int)dword_1800A0A44));
    v81 = *(_OWORD *)&c_regValueReprobeThreshold;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A60, GetDWordValue(v88, &v81, (unsigned int)qword_1800A0A60));
    v82 = *(_OWORD *)&c_regValueUserActiveProbing;
    _InterlockedExchange((_DWORD *)&qword_1800A0A60 + 1, GetDWordValue(v88, &v82, HIDWORD(qword_1800A0A60)));
    v83 = *(_OWORD *)&c_regValueCaptivePortalTimer;
    _InterlockedExchange((_DWORD *)&qword_1800A0A68 + 1, GetDWordValue(v88, &v83, 0LL));
    v48 = *(_OWORD *)&c_regValueCaptivePortalIncrements;
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A74, GetDWordValue(v88, &v48, 5LL));
    v49 = *(_OWORD *)&c_regValueCaptivePortalTimerMax;
    _InterlockedExchange(&dword_1800A0A70, GetDWordValue(v88, &v49, 30LL));
    v50 = *(_OWORD *)&c_regValueDisableRetryFallbackUrl;
    _InterlockedExchange((_DWORD *)&qword_1800A0A74 + 1, GetDWordValue(v88, &v50, 0LL));
    v52 = *(_OWORD *)&c_regValueDisableNCSIConnectivityEvaluation;
    _InterlockedExchange(&dword_1800A0A7C, GetDWordValue(phkResult, &v52, 0LL));
  }
  v10 = NcsiConfigData::IsDisableNCSIConnectivityEvaluationSet(v9);
  if ( IsDisableNCSIConnectivityEvaluationSet == v10 )
  {
    v13 = 0;
    v12 = 0;
  }
  else
  {
    v12 = 1;
    v13 = 0;
    if ( v10
      || (IsPassivePollingDisabled = NcsiConfigData::IsPassivePollingDisabled(v11), v15 = 1, IsPassivePollingDisabled) )
    {
      v15 = 0;
    }
    Ncsi::PassivePoll::PassivePollManager::EnablePolling(v15);
    memset_0(v100, 0, sizeof(v100));
    v101 = 8;
    std::any::operator=<_NcsiPassivePollingConfigChangeMetadata,0>((std::any *)v100);
    NlmManager::PublishDiagnosticsNotificationToNlm((struct std::any *)v100);
    std::any::reset((std::any *)v100);
  }
  if ( v2 != g_ncsiConfigData || v12 )
  {
    memset_0(v102, 0, sizeof(v102));
    v103 = 4;
    std::any::operator=<_NcsiActiveProbeConfigChangeMetadata,0>((std::any *)v102);
    NlmManager::PublishDiagnosticsNotificationToNlm((struct std::any *)v102);
    std::any::reset((std::any *)v102);
  }
  LoadCacheStateFromKey(v88);
  if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
    && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
    && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 4u )
  {
    v16 = "enabled";
    if ( !*(&g_ncsiConfigData + 1) )
      v16 = "disabled";
    WPP_SF_sd(
      *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
      *(&g_ncsiConfigData + 1),
      (unsigned int)"disabled",
      (_DWORD)v16,
      *(&g_ncsiConfigData + 4));
  }
  if ( !dword_1800A0A2C )
    ((void (*)(void))MicrosoftTelemetryAssertTriggeredNoArgs)();
  if ( !dword_1800A0A30 )
    ((void (*)(void))MicrosoftTelemetryAssertTriggeredNoArgs)();
  if ( !(_DWORD)qword_1800A0A34 )
    ((void (*)(void))MicrosoftTelemetryAssertTriggeredNoArgs)();
  if ( !dword_1800A0A2C )
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 3u )
    {
      WPP_SF_dD(
        *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
        40LL,
        &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
        (unsigned int)dword_1800A0A2C,
        35);
    }
    _InterlockedExchange(&dword_1800A0A2C, 35);
  }
  if ( !dword_1800A0A30 )
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 3u )
    {
      WPP_SF_dD(
        *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
        41LL,
        &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
        (unsigned int)dword_1800A0A30,
        1);
    }
    _InterlockedExchange(&dword_1800A0A30, 1);
  }
  if ( !(_DWORD)qword_1800A0A34 )
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 3u )
    {
      WPP_SF_dD(
        *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
        42LL,
        &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
        (unsigned int)qword_1800A0A34,
        1);
    }
    _InterlockedExchange((volatile __int32 *)&qword_1800A0A34, 1024);
  }
  v17 = WPP_GLOBAL_Control;
  if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control )
  {
    if ( (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0 && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
    {
      WPP_SF_D(
        *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
        43LL,
        &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
        (unsigned int)dword_1800A0A2C);
      v17 = WPP_GLOBAL_Control;
    }
    if ( (_UNKNOWN *)v17 != &WPP_GLOBAL_Control )
    {
      if ( (*(_BYTE *)(v17 + 28) & 0x10) != 0 && *(_BYTE *)(v17 + 25) >= 5u )
      {
        WPP_SF_D(
          *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
          44LL,
          &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
          (unsigned int)dword_1800A0A30);
        v17 = WPP_GLOBAL_Control;
      }
      if ( (_UNKNOWN *)v17 != &WPP_GLOBAL_Control && (*(_BYTE *)(v17 + 28) & 0x10) != 0 && *(_BYTE *)(v17 + 25) >= 5u )
        WPP_SF_D(
          *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
          45LL,
          &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
          (unsigned int)qword_1800A0A34);
    }
  }
  if ( a2 )
  {
    v90 = 0LL;
    v18 = (const WCHAR *)&qword_18009FDA0;
    if ( (unsigned __int64)qword_18009FDB8 > 7 )
      v18 = qword_18009FDA0;
    v19 = RegOpenKeyExW(HKEY_LOCAL_MACHINE, v18, 0, 0x20019u, &v90);
    if ( v19 )
    {
      if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
        && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
        && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 2u )
      {
        WPP_SF_D(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 46LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids, v19);
      }
    }
    else
    {
      LoadGatewayCache(v90);
    }
    wil::details::unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>::~unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>(&v90);
  }
  v20 = (struct NCSI_DNS_PROBE_CONFIG *)operator new(0x224uLL, (const struct std::nothrow_t *)&std::nothrow);
  v95 = v20;
  v21 = (struct NCSI_DNS_PROBE_CONFIG *)operator new(0x224uLL, (const struct std::nothrow_t *)&std::nothrow);
  v96 = v21;
  v22 = (struct _NCSI_WEB_PROBE_CONFIG *)operator new(0x61AuLL, (const struct std::nothrow_t *)&std::nothrow);
  v97 = v22;
  v24 = (struct _NCSI_WEB_PROBE_CONFIG *)operator new(0x61AuLL, (const struct std::nothrow_t *)&std::nothrow);
  v93 = v24;
  v91 = 0LL;
  v92 = 0LL;
  if ( v20 )
  {
    if ( v21 )
    {
      v13 = 1;
      NcsiConfigData::LoadDnsProbeData(v23, phkResult, v20, v21);
      if ( !v44 )
        NcsiConfigData::LoadDnsProbeData(v23, v88, v20, v21);
    }
  }
  if ( v22 && v24 )
  {
    v47 = 1;
    NcsiConfigData::LoadWebProbeData(v23, phkResult, v22, v24);
    if ( !v44 )
      NcsiConfigData::LoadWebProbeData(v23, v88, v22, v24);
  }
  else
  {
    v47 = 0;
  }
  v45 = NcsiConfigData::LoadManualProxies(v23, v88, &v91);
  memset(&v99, 0, sizeof(v99));
  memset(&v98, 0, sizeof(v98));
  NcsiConfigData::LoadInternetDestinationAddresses(v25, &v99, &v98);
  EnterCriticalSection(&stru_1800A29D8);
  v94 = &stru_1800A29D8;
  *(union _SOCKADDR_INET *)byte_1800A0A88 = v99;
  *(union _SOCKADDR_INET *)byte_1800A0AA4 = v98;
  if ( v13 )
  {
    v26 = &unk_1800A0AC0;
    v27 = 4LL;
    do
    {
      *v26 = *(_OWORD *)v20;
      v26[1] = *((_OWORD *)v20 + 1);
      v26[2] = *((_OWORD *)v20 + 2);
      v26[3] = *((_OWORD *)v20 + 3);
      v26[4] = *((_OWORD *)v20 + 4);
      v26[5] = *((_OWORD *)v20 + 5);
      v26[6] = *((_OWORD *)v20 + 6);
      v26 += 8;
      *(v26 - 1) = *((_OWORD *)v20 + 7);
      v20 = (struct NCSI_DNS_PROBE_CONFIG *)((char *)v20 + 128);
      --v27;
    }
    while ( v27 );
    *v26 = *(_OWORD *)v20;
    v26[1] = *((_OWORD *)v20 + 1);
    *((_DWORD *)v26 + 8) = *((_DWORD *)v20 + 8);
    v28 = &unk_1800A0CE4;
    v29 = 4LL;
    do
    {
      *v28 = *(_OWORD *)v21;
      v28[1] = *((_OWORD *)v21 + 1);
      v28[2] = *((_OWORD *)v21 + 2);
      v28[3] = *((_OWORD *)v21 + 3);
      v28[4] = *((_OWORD *)v21 + 4);
      v28[5] = *((_OWORD *)v21 + 5);
      v28[6] = *((_OWORD *)v21 + 6);
      v28 += 8;
      *(v28 - 1) = *((_OWORD *)v21 + 7);
      v21 = (struct NCSI_DNS_PROBE_CONFIG *)((char *)v21 + 128);
      --v29;
    }
    while ( v29 );
    *v28 = *(_OWORD *)v21;
    v28[1] = *((_OWORD *)v21 + 1);
    v30 = *((_DWORD *)v21 + 8);
  }
  else
  {
    memset_0(v84, 0, 0x224uLL);
    v31 = &unk_1800A0AC0;
    v32 = v84;
    v33 = 4LL;
    do
    {
      *v31 = *v32;
      v31[1] = v32[1];
      v31[2] = v32[2];
      v31[3] = v32[3];
      v31[4] = v32[4];
      v31[5] = v32[5];
      v31[6] = v32[6];
      v31 += 8;
      *(v31 - 1) = v32[7];
      v32 += 8;
      --v33;
    }
    while ( v33 );
    *v31 = *v32;
    v31[1] = v32[1];
    *((_DWORD *)v31 + 8) = *((_DWORD *)v32 + 8);
    memset_0(v85, 0, 0x224uLL);
    v28 = &unk_1800A0CE4;
    v34 = v85;
    v35 = 4LL;
    do
    {
      *v28 = *v34;
      v28[1] = v34[1];
      v28[2] = v34[2];
      v28[3] = v34[3];
      v28[4] = v34[4];
      v28[5] = v34[5];
      v28[6] = v34[6];
      v28 += 8;
      *(v28 - 1) = v34[7];
      v34 += 8;
      --v35;
    }
    while ( v35 );
    *v28 = *v34;
    v28[1] = v34[1];
    v30 = *((_DWORD *)v34 + 8);
  }
  *((_DWORD *)v28 + 8) = v30;
  if ( v47 )
  {
    memcpy_0(&unk_1800A0F08, v22, 0x61AuLL);
    v36 = v24;
  }
  else
  {
    memset_0(Src, 0, 0x61AuLL);
    memcpy_0(&unk_1800A0F08, Src, 0x61AuLL);
    memset_0(v86, 0, 0x61AuLL);
    v36 = (struct _NCSI_WEB_PROBE_CONFIG *)v86;
  }
  memcpy_0(&unk_1800A1522, v36, 0x61AuLL);
  if ( v45 )
  {
    v37 = WPP_GLOBAL_Control;
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
    {
      v38 = v91;
      if ( (_QWORD)v91 == *((_QWORD *)&v91 + 1) )
        v38 = 0LL;
      WPP_SF_S(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 47LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids, v38);
      v37 = WPP_GLOBAL_Control;
    }
    if ( (unsigned __int8)std::operator==<unsigned short,std::allocator<unsigned short>>(&v91, &qword_1800A29B8) )
    {
      if ( (_UNKNOWN *)v37 != &WPP_GLOBAL_Control && (*(_BYTE *)(v37 + 28) & 0x10) != 0 && *(_BYTE *)(v37 + 25) >= 4u )
        WPP_SF_(*(_QWORD *)(v37 + 16), 48LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
    }
    else
    {
      std::vector<unsigned short>::operator=(&qword_1800A29B8, &v91);
      if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
        && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
        && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
      {
        WPP_SF_(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 49LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
      }
      if ( CheckIfClientPresent() )
      {
        if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
          && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
          && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
        {
          WPP_SF_(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 50LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
        }
        if ( !(unsigned int)NcsiThreadPoolTrySubmit((PTP_SIMPLE_CALLBACK)RespondToProxyOpportunity, (PVOID)1)
          && (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
          && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
          && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 2u )
        {
          LastError = GetLastError();
          WPP_SF_D(
            *(_QWORD *)(WPP_GLOBAL_Control + 16LL),
            51LL,
            &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids,
            LastError);
        }
      }
    }
  }
  else
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 2u )
    {
      WPP_SF_(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 52LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
    }
    if ( qword_1800A29B8 != qword_1800A29C0 )
      qword_1800A29C0 = qword_1800A29B8;
  }
  if ( (dword_1800A0A44 & 1) != 0 )
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
    {
      WPP_SF_(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 54LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
    }
    v40 = 480000;
    v41 = 60000;
    v42 = 2000;
  }
  else
  {
    if ( (_UNKNOWN *)WPP_GLOBAL_Control != &WPP_GLOBAL_Control
      && (*(_BYTE *)(WPP_GLOBAL_Control + 28LL) & 0x10) != 0
      && *(_BYTE *)(WPP_GLOBAL_Control + 25LL) >= 5u )
    {
      WPP_SF_(*(_QWORD *)(WPP_GLOBAL_Control + 16LL), 53LL, &WPP_08f6b6bb46093b5ffecec2c4d94c9795_Traceguids);
    }
    v40 = 7200000;
    v41 = 900000;
    v42 = 30000;
  }
  _InterlockedExchange(&dword_1800A0A48, v42);
  _InterlockedExchange(&dword_1800A0A4C, 10);
  _InterlockedExchange(&dword_1800A0A50, 1);
  v43 = (unsigned int)_InterlockedExchange(&dword_1800A0A54, v41);
  _InterlockedExchange(&dword_1800A0A58, v40);
  _InterlockedExchange(&dword_1800A0A5C, 2);
  if ( dword_1800A0A48 >= (unsigned int)dword_1800A0A54 )
    MicrosoftTelemetryAssertTriggeredNoArgs((unsigned int)dword_1800A0A48, v43);
  wil::details::unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION *,void (*)(_RTL_CRITICAL_SECTION *),&void LeaveCriticalSection(_RTL_CRITICAL_SECTION *),wistd::integral_constant<unsigned __int64,1>,_RTL_CRITICAL_SECTION *,_RTL_CRITICAL_SECTION *,0,std::nullptr_t>>::~unique_storage<wil::details::resource_policy<_RTL_CRITICAL_SECTION *,void (*)(_RTL_CRITICAL_SECTION *),&void LeaveCriticalSection(_RTL_CRITICAL_SECTION *),wistd::integral_constant<unsigned __int64,1>,_RTL_CRITICAL_SECTION *,_RTL_CRITICAL_SECTION *,0,std::nullptr_t>>(
    &v94,
    v43);
  std::vector<unsigned short>::_Tidy(&v91);
  std::unique_ptr<_NCSI_WEB_PROBE_CONFIG>::~unique_ptr<_NCSI_WEB_PROBE_CONFIG>(&v93);
  std::unique_ptr<_NCSI_WEB_PROBE_CONFIG>::~unique_ptr<_NCSI_WEB_PROBE_CONFIG>(&v97);
  std::unique_ptr<NCSI_DNS_PROBE_CONFIG>::~unique_ptr<NCSI_DNS_PROBE_CONFIG>(&v96);
  std::unique_ptr<NCSI_DNS_PROBE_CONFIG>::~unique_ptr<NCSI_DNS_PROBE_CONFIG>(&v95);
  wil::details::unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>::~unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>(&v88);
  wil::details::unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>::~unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>(&phkResult);
}
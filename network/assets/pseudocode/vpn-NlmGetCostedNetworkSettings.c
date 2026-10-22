// The function seems has been flattened
__int64 __fastcall int_NlmGetCostedNetworkSettings(_DWORD *a1, _DWORD *a2)
{
  struct _LIST_ENTRY *WPP_GLOBAL_Control; // rcx
  unsigned int IsPolicySetByMobileDeviceManager_1; // ebx
  __int64 v7; // r9
  const wchar_t *OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters; // rsi
  int IsPolicySetByMobileDeviceManager; // eax
  struct _LIST_ENTRY *WPP_GLOBAL_Control_1; // rcx
  __int64 n33; // rdx
  char IsStateSeparationEnabled; // al
  __int64 v13; // rcx
  const wchar_t *OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1; // rdx
  __int64 v15; // rcx
  int v16; // [rsp+20h] [rbp-20h]
  _DWORD v17[4]; // [rsp+30h] [rbp-10h] BYREF
  int v18; // [rsp+80h] [rbp+40h] BYREF
  int v19; // [rsp+88h] [rbp+48h] BYREF

  WPP_GLOBAL_Control = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 8) != 0 )
  {
    WPP_SF_(WPP_GLOBAL_Control[1].Flink, 25LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
    WPP_GLOBAL_Control = WPP_GLOBAL_Control;
  }
  IsPolicySetByMobileDeviceManager_1 = 0;
  v17[0] = 0;
  v19 = 0;
  v18 = 0;
  if ( !g_fLibInitializeCompletedSuccessfully )
  {
    if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control )
    {
      if ( (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
      {
        WPP_SF_(WPP_GLOBAL_Control[1].Flink, 26LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
        WPP_GLOBAL_Control = WPP_GLOBAL_Control;
      }
      if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
        && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 8) != 0 )
      {
        WPP_SF_D(WPP_GLOBAL_Control[1].Flink, 27LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids, 0LL);
      }
    }
    return 0LL;
  }
  VpnCriticalSectionEnter(&g_LpCriticalSection);
  if ( !g_NlmHandlerInitialized )
  {
    if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
      && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
    {
      WPP_SF_(WPP_GLOBAL_Control[1].Flink, 28LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
    }
    goto LABEL_79;
  }
  VpnCriticalSectionEnter(&g_CsNlmNetwork);
  if ( g_CostedNetworkSettingsInitialized )
    goto LABEL_75;
  OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters = L"OSDATA\\SYSTEM\\CurrentControlSet\\Services\\RasMan\\"
                                                                     "Parameters\\Config\\VpnCostedNetworkSettings";
  if ( !(unsigned __int8)IsPolicyManager_IsPolicySetByMobileDeviceManagerPresent() )
    goto LABEL_34;
  IsPolicySetByMobileDeviceManager = PolicyManager_IsPolicySetByMobileDeviceManager(
                                       L"Connectivity",
                                       L"AllowVPNOverCellular",
                                       &v18);
  IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
  if ( IsPolicySetByMobileDeviceManager == -2147024769 )
    goto LABEL_34;
  if ( IsPolicySetByMobileDeviceManager >= 0 )
  {
    if ( !v18 )
    {
LABEL_35:
      if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
        && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
      {
        WPP_SF_(WPP_GLOBAL_Control[1].Flink, 32LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
      }
      IsStateSeparationEnabled = RtlIsStateSeparationEnabled();
      OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1 = L"OSDATA\\SYSTEM\\CurrentControlSet\\Services\\R"
                                                                           "asMan\\Parameters\\Config\\VpnCostedNetworkSettings";
      if ( !IsStateSeparationEnabled )
        OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1 = L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\"
                                                                             "Parameters\\Config\\VpnCostedNetworkSettings";
      IsPolicySetByMobileDeviceManager = VpnRegQueryDWord(
                                           v13,
                                           OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1,
                                           L"NoCostedNetwork",
                                           &g_donotUseCosted,
                                           v17);
      IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
      if ( IsPolicySetByMobileDeviceManager < 0 )
      {
        WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
          || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
        {
          goto LABEL_78;
        }
        n33 = 33LL;
        goto LABEL_23;
      }
      if ( !v17[0] )
        g_donotUseCosted = 0;
LABEL_46:
      v19 = 0;
      if ( (unsigned __int8)IsPolicyManager_IsPolicySetByMobileDeviceManagerPresent() )
      {
        IsPolicySetByMobileDeviceManager = PolicyManager_IsPolicySetByMobileDeviceManager(
                                             L"Connectivity",
                                             L"AllowVPNRoamingOverCellular",
                                             &v18);
        IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
        if ( IsPolicySetByMobileDeviceManager != -2147024769 )
        {
          if ( IsPolicySetByMobileDeviceManager < 0 )
          {
            WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
              || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
            {
              goto LABEL_78;
            }
            n33 = 34LL;
            goto LABEL_23;
          }
          if ( !v18 )
            goto LABEL_63;
          if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
            && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
          {
            WPP_SF_(WPP_GLOBAL_Control[1].Flink, 35LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
          }
          if ( (unsigned __int8)IsPolicyManager_IsPolicySetByMobileDeviceManagerPresent() )
          {
            IsPolicySetByMobileDeviceManager = PolicyManager_GetPolicyInt(
                                                 L"Connectivity",
                                                 L"AllowVPNRoamingOverCellular",
                                                 &v19);
            IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
            if ( IsPolicySetByMobileDeviceManager < 0 )
            {
              WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
                || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
              {
                goto LABEL_78;
              }
              n33 = 36LL;
              goto LABEL_23;
            }
            g_donotUseRoaming = v19 == 0;
          }
        }
      }
      if ( v18 )
      {
LABEL_74:
        g_CostedNetworkSettingsInitialized = 1;
LABEL_75:
        *a1 = g_donotUseCosted;
        *a2 = g_donotUseRoaming;
        if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
          && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
        {
          LOBYTE(v16) = g_donotUseRoaming != 0;
          LOBYTE(v7) = g_donotUseCosted != 0;
          WPP_SF_cc(WPP_GLOBAL_Control[1].Flink, 39LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids, v7, v16);
        }
        goto LABEL_78;
      }
LABEL_63:
      if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
        && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
      {
        WPP_SF_(WPP_GLOBAL_Control[1].Flink, 37LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
      }
      if ( !(unsigned __int8)RtlIsStateSeparationEnabled() )
        OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters = L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\P"
                                                                           "arameters\\Config\\VpnCostedNetworkSettings";
      IsPolicySetByMobileDeviceManager = VpnRegQueryDWord(
                                           v15,
                                           OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters,
                                           L"NoRoamingNetwork",
                                           &g_donotUseRoaming,
                                           v17);
      IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
      if ( IsPolicySetByMobileDeviceManager < 0 )
      {
        WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
          || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
        {
          goto LABEL_78;
        }
        n33 = 38LL;
        goto LABEL_23;
      }
      if ( !v17[0] )
        g_donotUseRoaming = 0;
      goto LABEL_74;
    }
    if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
      && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 4) != 0 )
    {
      WPP_SF_(WPP_GLOBAL_Control[1].Flink, 30LL, &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids);
    }
    if ( (unsigned __int8)IsPolicyManager_IsPolicySetByMobileDeviceManagerPresent() )
    {
      IsPolicySetByMobileDeviceManager = PolicyManager_GetPolicyInt(L"Connectivity", L"AllowVPNOverCellular", &v19);
      IsPolicySetByMobileDeviceManager_1 = IsPolicySetByMobileDeviceManager;
      if ( IsPolicySetByMobileDeviceManager < 0 )
      {
        WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
        if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control
          || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
        {
          goto LABEL_78;
        }
        n33 = 31LL;
        goto LABEL_23;
      }
      g_donotUseCosted = v19 == 0;
    }
LABEL_34:
    if ( v18 )
      goto LABEL_46;
    goto LABEL_35;
  }
  WPP_GLOBAL_Control_1 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (struct _LIST_ENTRY *)&WPP_GLOBAL_Control || (BYTE4(WPP_GLOBAL_Control[1].Blink) & 1) == 0 )
    goto LABEL_78;
  n33 = 29LL;
LABEL_23:
  WPP_SF_D(
    WPP_GLOBAL_Control_1[1].Flink,
    n33,
    &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids,
    (unsigned int)IsPolicySetByMobileDeviceManager);
LABEL_78:
  VpnCriticalSectionLeave(&g_CsNlmNetwork);
LABEL_79:
  VpnCriticalSectionLeave(&g_LpCriticalSection);
  if ( WPP_GLOBAL_Control != (struct _LIST_ENTRY *)&WPP_GLOBAL_Control && (BYTE4(WPP_GLOBAL_Control[1].Blink) & 8) != 0 )
    WPP_SF_D(
      WPP_GLOBAL_Control[1].Flink,
      40LL,
      &WPP_a75dcec0663d380d978246f7afbeb43a_Traceguids,
      IsPolicySetByMobileDeviceManager_1);
  return IsPolicySetByMobileDeviceManager_1;
}
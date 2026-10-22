int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  unsigned int v4; // r14d
  int v5; // r15d
  int v6; // esi
  unsigned int v7; // r12d
  __int64 *v8; // rbx
  __int64 *v9; // rdi
  DWORD v10; // eax
  ULONG v11; // ebx
  NTSTATUS v12; // eax
  NTSTATUS v13; // edi
  unsigned int v14; // eax
  __int64 v15; // rbx
  HKEY v16; // rcx
  CMachine *v17; // rbx
  void *v18; // r8
  unsigned int v19; // eax
  CSession *v20; // rcx
  int v21; // r8d
  int SessionProcess; // eax
  int v23; // eax
  NTSTATUS v24; // eax
  ULONG v25; // eax
  unsigned int v26; // eax
  CUser *v27; // rcx
  char v28; // al
  int v30; // eax
  int v31; // edi
  unsigned int inited; // eax
  CMachine *v33; // rcx
  struct _FILETIME v34; // rcx
  unsigned __int64 v35; // rdx
  __int64 v36; // rdx
  __int64 v37; // r9
  unsigned int started; // eax
  __int64 v39; // rdx
  unsigned int v40; // eax
  __int64 v41; // rdx
  NTSTATUS v42; // eax
  __int64 v43; // r8
  const struct wil::FailureInfo *v44; // rdx
  DWORD LastError; // eax
  int v46; // eax
  bool v47; // sf
  int v48; // eax
  int v49; // eax
  bool v50; // zf
  int v51; // eax
  int v52; // eax
  const char *v53; // r9
  const char *v54; // rcx
  const char *v55; // rax
  LSTATUS v56; // ebx
  HANDLE EventW; // rbx
  DWORD v58; // eax
  __int64 v59; // rdx
  unsigned int v60; // eax
  int v61; // eax
  CMachine *v62; // rcx
  CMachine *v63; // rcx
  int v64; // eax
  unsigned int v65; // eax
  unsigned int v66; // eax
  void *v67; // rcx
  void *v68; // rbx
  CSession *v69; // rdi
  HANDLE ProcessHeap; // rax
  char *v71; // rax
  NTSTATUS v72; // eax
  HANDLE v73; // rax
  HMODULE v74; // rcx
  void *v75; // rbx
  CSession *v76; // rdi
  HANDLE v77; // rax
  char *v78; // rax
  NTSTATUS v79; // eax
  HANDLE v80; // rax
  BOOL (__stdcall *v81)(PINIT_ONCE, PVOID, PVOID *); // rax
  unsigned int v83; // eax
  CUser *v84; // rcx
  __int64 v85; // rdx
  CUser *v86; // rcx
  __int64 v87; // rdx
  CSession *v88; // rbx
  const WCHAR *String; // rdi
  const WCHAR *v90; // rax
  const WCHAR *v91; // rbx
  unsigned __int16 *v92; // r9
  __int64 v93; // rcx
  __int64 v94; // rcx
  unsigned __int8 v95; // dl
  int v96; // eax
  __int64 v97; // rcx
  __int64 v98; // rcx
  PHKEY phkResult; // [rsp+58h] [rbp-248h]
  __int64 v100; // [rsp+78h] [rbp-228h] BYREF
  _BYTE v101[4]; // [rsp+80h] [rbp-220h] BYREF
  unsigned int v102; // [rsp+84h] [rbp-21Ch] BYREF
  _BYTE v103[4]; // [rsp+88h] [rbp-218h] BYREF
  unsigned int v104; // [rsp+8Ch] [rbp-214h] BYREF
  int v105; // [rsp+90h] [rbp-210h] BYREF
  _SHUTDOWN_ACTION v106; // [rsp+94h] [rbp-20Ch] BYREF
  BYTE Data[4]; // [rsp+98h] [rbp-208h] BYREF
  unsigned int v108; // [rsp+9Ch] [rbp-204h] BYREF
  int v109; // [rsp+A0h] [rbp-200h]
  unsigned int SystemInformation; // [rsp+A4h] [rbp-1FCh] BYREF
  DWORD Type; // [rsp+A8h] [rbp-1F8h] BYREF
  DWORD v112; // [rsp+ACh] [rbp-1F4h] BYREF
  DWORD v113; // [rsp+B0h] [rbp-1F0h] BYREF
  BYTE v114[4]; // [rsp+B4h] [rbp-1ECh] BYREF
  BYTE v115[4]; // [rsp+B8h] [rbp-1E8h] BYREF
  unsigned int v116; // [rsp+BCh] [rbp-1E4h] BYREF
  unsigned int v117; // [rsp+C0h] [rbp-1E0h] BYREF
  unsigned int v118; // [rsp+C4h] [rbp-1DCh] BYREF
  int v119; // [rsp+C8h] [rbp-1D8h]
  unsigned __int64 v120; // [rsp+D0h] [rbp-1D0h] BYREF
  HKEY hKey; // [rsp+D8h] [rbp-1C8h] BYREF
  int v122; // [rsp+E0h] [rbp-1C0h]
  int v123; // [rsp+E8h] [rbp-1B8h] BYREF
  int v124; // [rsp+F0h] [rbp-1B0h] BYREF
  int v125; // [rsp+F8h] [rbp-1A8h] BYREF
  int v126; // [rsp+FCh] [rbp-1A4h]
  ULONG v127; // [rsp+100h] [rbp-1A0h]
  _DWORD v128[2]; // [rsp+104h] [rbp-19Ch] BYREF
  DWORD lpcbData; // [rsp+10Ch] [rbp-194h] BYREF
  int ProcessInformation; // [rsp+110h] [rbp-190h] BYREF
  HKEY v131; // [rsp+118h] [rbp-188h] BYREF
  HKEY v132; // [rsp+120h] [rbp-180h] BYREF
  const WCHAR *v133; // [rsp+128h] [rbp-178h] BYREF
  DWORD cbData; // [rsp+130h] [rbp-170h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+138h] [rbp-168h] BYREF
  struct _FILETIME v136; // [rsp+140h] [rbp-160h] BYREF
  __int128 Recipient; // [rsp+148h] [rbp-158h] BYREF
  struct _FILETIME v138; // [rsp+158h] [rbp-148h] BYREF
  HKEY v139; // [rsp+160h] [rbp-140h] BYREF
  __int64 *v140; // [rsp+168h] [rbp-138h]
  int v141; // [rsp+170h] [rbp-130h]
  __int128 v142; // [rsp+178h] [rbp-128h] BYREF
  _BYTE v143[160]; // [rsp+188h] [rbp-118h] BYREF
  __int128 InputBuffer; // [rsp+228h] [rbp-78h] BYREF
  __int128 v145; // [rsp+238h] [rbp-68h]
  __int128 v146; // [rsp+248h] [rbp-58h] BYREF
  _QWORD v147[2]; // [rsp+258h] [rbp-48h] BYREF
  struct CUser *v148; // [rsp+268h] [rbp-38h] BYREF
  unsigned int v149[2]; // [rsp+270h] [rbp-30h]

  v100 = 0x100000000LL;
  g_WinlogonStage = 1;
  v104 = 1;
  v4 = 0;
  v102 = 0;
  v106 = ShutdownReboot;
  v109 = 3;
  v5 = 0;
  v105 = 0;
  v6 = 1;
  v122 = 1;
  v7 = -1073737819;
  v119 = -1073737819;
  memset_0(&xGlobalContext, 0, 0x458uLL);
  SystemTimeAsFileTime = 0LL;
  v136 = 0LL;
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  ProcessInformation = 1;
  NtSetInformationProcess((HANDLE)0xFFFFFFFFFFFFFFFFLL, ProcessCycleTime|ProcessUserModeIOPL, &ProcessInformation, 4u);
  InitializeCriticalSection(&stru_1400D11E0);
  HeapSetInformation(0LL, HeapEnableTerminationOnCorruption, 0LL, 0LL);
  SetErrorMode(1u);
  qword_1400D09A0 = 0LL;
  WPP_MAIN_CB = 0LL;
  qword_1400D09A8 = 1LL;
  WPP_REGISTRATION_GUIDS = (__int64)&WPP_ThisDir_CTLGUID_WinLogon;
  v8 = &WPP_MAIN_CB;
  WPP_GLOBAL_Control = (CUser *)&WPP_MAIN_CB;
  v142 = 0LL;
  v9 = &WPP_REGISTRATION_GUIDS;
  v140 = &WPP_REGISTRATION_GUIDS;
  while ( v8 )
  {
    v43 = *v9++;
    v140 = v9;
    v142 = (unsigned __int64)v43;
    v8[4] = v43;
    EtwRegisterTraceGuidsW(WppControlCallback, v8, v43, 1LL, &v142, 0LL, 0LL, v8 + 1, v100);
    v8 = (__int64 *)*v8;
  }
  g_WinlogonStage = 2;
  v146 = *((_OWORD *)off_1400CD750 - 1);
  if ( qword_1400CD768 )
    __fastfail(5u);
  qword_1400CD770 = 0LL;
  qword_1400CD778 = 0LL;
  if ( !(unsigned int)EtwEventRegister(&v146, tlgEnableCallback, &dword_1400CD748, &qword_1400CD768) )
    EtwEventSetInformation(qword_1400CD768, 2LL, off_1400CD750, *(unsigned __int16 *)off_1400CD750);
  InputBuffer = *((_OWORD *)off_1400CD718 - 1);
  if ( qword_1400CD730 )
    __fastfail(5u);
  qword_1400CD738 = 0LL;
  qword_1400CD740 = 0LL;
  if ( !(unsigned int)EtwEventRegister(&InputBuffer, tlgEnableCallback, &dword_1400CD710, &qword_1400CD730) )
    EtwEventSetInformation(qword_1400CD730, 2LL, off_1400CD718, *(unsigned __int16 *)off_1400CD718);
  if ( wil::details::g_pfnTelemetryCallback
    && (void (__fastcall *)(bool, const struct wil::FailureInfo *))wil::details::g_pfnTelemetryCallback != WinlogonProvider::FallbackTelemetryCallback )
  {
    memset_0(v143, 0, 0x98uLL);
    wil::details::WilFailFast((wil::details *)v143, v44);
  }
  wil::details::g_pfnTelemetryCallback = (__int64)WinlogonProvider::FallbackTelemetryCallback;
  SystemInformation = 0;
  if ( NtQuerySystemInformation(SystemFlagsInformation, &SystemInformation, 4u, 0LL) >= 0 )
    WppStart(1u, HIBYTE(SystemInformation) & 4);
  EtwEventRegister(&MS_Winlogon_Provider, 0LL, 0LL, &g_TraceRegHandle);
  McGenEventRegister_EtwEventRegister();
  EtwEventSetInformation(
    g_TraceRegHandle,
    2LL,
    &`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits,
    (unsigned __int16)`EnableManifestedProviderForMicrosoftTelemetry'::`2'::Traits);
  v10 = UmsHlprInit();
  LODWORD(v100) = v10;
  if ( v10 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      goto LABEL_79;
    }
    v36 = 10LL;
LABEL_125:
    v37 = v10;
LABEL_156:
    WPP_SF_D(*((_QWORD *)v27 + 2), v36, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v37);
LABEL_117:
    v27 = WPP_GLOBAL_Control;
LABEL_79:
    v31 = HIDWORD(v100);
    goto LABEL_356;
  }
  g_WinlogonStage = 3;
  v11 = 0;
  v12 = RtlInitializeCriticalSection(&g_HungNotificationListLock);
  v13 = v12;
  if ( v12 < 0 )
  {
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        13LL,
        &WPP_e84ef2aaa9f9388d015044a5a183efd2_Traceguids,
        (unsigned int)v12);
    }
    v11 = RtlNtStatusToDosError(v13);
  }
  LODWORD(v100) = v11;
  if ( v11 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      goto LABEL_79;
    }
    v36 = 11LL;
    v37 = v11;
    goto LABEL_156;
  }
  g_WinlogonStage = 4;
  if ( !(unsigned int)SetProcessPriority() )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      LastError = GetLastError();
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 12LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, LastError);
      v27 = WPP_GLOBAL_Control;
    }
    LODWORD(v100) = 1024;
    goto LABEL_79;
  }
  g_WinlogonStage = 5;
  v14 = JobManagerInitialize();
  LODWORD(v100) = v14;
  if ( v14 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 13LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v14);
      v27 = WPP_GLOBAL_Control;
    }
    LODWORD(v100) = 1034;
    goto LABEL_79;
  }
  g_WinlogonStage = 6;
  v139 = 0LL;
  if ( !RegOpenKeyExW(HKEY_CLASSES_ROOT, L"CLSID", 0, 0x20019u, &v139) )
    RegCloseKey(v139);
  g_WinlogonStage = 7;
  v10 = InitializeData((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
  LODWORD(v100) = v10;
  if ( v10 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      goto LABEL_79;
    }
    v36 = 14LL;
    goto LABEL_125;
  }
  g_WinlogonStage = 8;
  if ( *((_DWORD *)qword_1400D09D0 + 43) )
  {
    InitializeSetupTypeData();
    if ( dword_1400D1788 == 1 || (v46 = 0, dword_1400D1788 == 4) )
      v46 = 1;
    g_fExecuteSetup = v46;
    if ( !(unsigned int)IsSetupAvailable() || (v47 = (int)CreateSetupLaunchClaimEvent(1LL) < 0, v48 = 1, !v47) )
      v48 = 0;
    if ( !v48 )
      goto LABEL_193;
    if ( dword_1400D1798 != 1 )
      MicrosoftTelemetryAssertTriggeredNoArgs();
    if ( dword_1400D1788 || (v49 = 0, dword_1400D179C) )
      v49 = 1;
    v50 = v49 == 0;
    v51 = 1;
    if ( v50 )
LABEL_193:
      v51 = 0;
    g_fRunSetup = v51;
    v52 = IsMiniNTMode();
    g_fWinPEMode = v52;
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
    {
      v53 = "TRUE";
      v54 = "TRUE";
      if ( !v52 )
        v54 = "FALSE";
      v55 = "TRUE";
      if ( !g_fRunSetup )
        v55 = "FALSE";
      if ( !g_fExecuteSetup )
        v53 = "FALSE";
      WPP_SF_sss(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        (_DWORD)WPP_GLOBAL_Control,
        (unsigned int)"FALSE",
        (_DWORD)v53,
        (__int64)v55,
        (__int64)v54);
    }
    if ( g_fRunSetup && !(unsigned int)ClaimSetupLaunch() )
    {
      if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
        && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
      {
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 16LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
      }
      g_fRunSetup = 0;
    }
  }
  g_WinlogonStage = 9;
  v15 = xGlobalContext;
  *(_DWORD *)Data = 0;
  if ( !*(_QWORD *)(xGlobalContext + 184LL) )
    CGlobalStore::FetchHKLMSoftwareWinlogon(xGlobalContext);
  v16 = *(HKEY *)(v15 + 184);
  if ( !v16 || (Type = 0, cbData = 4, RegQueryValueExW(v16, L"NoDebugThread", 0LL, &Type, Data, &cbData)) || Type == 4 )
  {
    if ( *(_DWORD *)Data )
      goto LABEL_26;
  }
  else
  {
    *(_DWORD *)Data = 0;
  }
  inited = InitDebugHelpers();
  LODWORD(v100) = inited;
  if ( inited )
  {
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 3u )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 17LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, inited);
    }
    LODWORD(v100) = 0;
  }
  g_WinlogonStage = 10;
LABEL_26:
  v17 = qword_1400D09C8;
  v18 = (void *)*((_QWORD *)qword_1400D09C8 + 8);
  if ( v18 )
  {
    HeapFree(*((HANDLE *)qword_1400D09C8 + 1), 0, v18);
    *((_QWORD *)v17 + 8) = 0LL;
  }
  CMachine::FetchMachineName(v17);
  SetProfilesLocation();
  SetupBasicEnvironment(0LL);
  v19 = AsyncLogoffSupportInit();
  LODWORD(v100) = v19;
  if ( v19 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
    {
      goto LABEL_79;
    }
    WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 18LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v19);
    goto LABEL_117;
  }
  v10 = WMsgClntInitialize((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext, 1);
  LODWORD(v100) = v10;
  if ( v10 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
    {
      goto LABEL_79;
    }
    v36 = 19LL;
    goto LABEL_125;
  }
  g_WinlogonStage = 12;
  if ( (unsigned __int8)IsCreateWindowStationWPresent() )
  {
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_CreatePrimaryTerminal_Start) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_CreatePrimaryTerminal_Start, 0LL, 0LL);
    v20 = qword_1400D09D0;
    if ( !*((_DWORD *)qword_1400D09D0 + 43) )
      goto LABEL_35;
    v112 = 0;
    *(_DWORD *)v114 = 0;
    v113 = 4;
    v131 = 0LL;
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"System\\CurrentControlSet\\Control\\Session Manager", 0, 0x20019u, &v131);
    if ( v131 )
    {
      v56 = RegQueryValueExW(v131, L"NumberOfInitialSessions", 0LL, &v112, v114, &v113);
      RegCloseKey(v131);
      if ( !v56 && v112 == 4 && v113 == 4 )
      {
        if ( *(_DWORD *)v114 == 1 )
          v6 = 0;
        v122 = v6;
      }
    }
    v20 = qword_1400D09D0;
    if ( !*((_DWORD *)qword_1400D09D0 + 43) || (v21 = 1, !v6) )
LABEL_35:
      v21 = 0;
    LODWORD(v100) = CSession::CreatePrimaryTerminal(v20, (struct _LUID *)(xGlobalContext + 204LL), v21);
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_CreatePrimaryTerminal_Stop) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_CreatePrimaryTerminal_Stop, 0LL, 0LL);
    if ( (_DWORD)v100 )
    {
      v27 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
        && *((_BYTE *)WPP_GLOBAL_Control + 25) )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          20LL,
          &WPP_407213ad3eb136be1485685444407d59_Traceguids,
          (unsigned int)v100);
        v27 = WPP_GLOBAL_Control;
      }
      if ( (_DWORD)v100 == 2250 )
      {
        v7 = -2147479640;
        v119 = -2147479640;
      }
      goto LABEL_79;
    }
  }
  g_WinlogonStage = 13;
  if ( (unsigned __int8)IsLoadLocalFontsPresent() )
  {
    v123 = 0;
    if ( g_TraceRegHandle
      && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_UpdatePerUserSystemParameters_Start) )
    {
      v147[0] = &v123;
      v147[1] = 4LL;
      EtwEventWrite(g_TraceRegHandle, &WLEvt_UpdatePerUserSystemParameters_Start, 1LL, v147);
    }
    UpdatePerUserSystemParameters(0LL);
    v124 = 0;
    if ( g_TraceRegHandle
      && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_UpdatePerUserSystemParameters_Stop) )
    {
      v148 = (struct CUser *)&v124;
      *(_QWORD *)v149 = 4LL;
      EtwEventWrite(g_TraceRegHandle, &WLEvt_UpdatePerUserSystemParameters_Stop, 1LL, &v148);
    }
  }
  g_WinlogonStage = 14;
  if ( *((_DWORD *)qword_1400D09D0 + 43) )
  {
    v40 = WinLogonBootShell(0);
    LODWORD(v100) = v40;
    if ( v40 )
    {
      v101[0] = 0;
      if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
        && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
      {
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 21LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v40);
      }
      LOBYTE(v41) = 1;
      MyRtlAdjustPrivilege(19LL, v41, 0LL, v101);
      v42 = NtShutdownSystem((SHUTDOWN_ACTION)(((_DWORD)v100 == 641) + 1));
      if ( v42 < 0
        && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
        && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
      {
        WPP_SF_D(
          *((_QWORD *)WPP_GLOBAL_Control + 2),
          22LL,
          &WPP_407213ad3eb136be1485685444407d59_Traceguids,
          (unsigned int)v42);
      }
      MyRtlAdjustPrivilege(19LL, v101[0], 0LL, v101);
      v102 = 1;
      v27 = WPP_GLOBAL_Control;
      goto LABEL_79;
    }
    if ( *((_DWORD *)qword_1400D09D0 + 43) )
    {
      if ( v6 )
      {
        if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x10) != 0
          && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
        {
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 23LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
        }
        WLEventWrite(&WLEvt_WaitForLSM_Start);
        if ( (unsigned __int8)IsWinStationConnectAndLockDesktopPresent()
          && !(unsigned __int8)_WinStationWaitForConnect() )
        {
          v10 = GetLastError();
          LODWORD(v100) = v10;
          v27 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
            || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x10) == 0
            || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
          {
            goto LABEL_79;
          }
          v36 = 24LL;
          goto LABEL_125;
        }
        WLEventWrite(&WLEvt_WaitForLSM_Stop);
      }
      g_WinlogonStage = 15;
    }
  }
  if ( (unsigned __int8)IsThemesOnLogoffPresent() )
  {
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 25LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
    }
    WLEventWrite(&WLEvt_ThemesOnEarlyCreateSession_Start);
    ThemesOnEarlyCreateSession();
    WLEventWrite(&WLEvt_ThemesOnEarlyCreateSession_Stop);
  }
  if ( (unsigned __int8)IsDwmpStartWinlogonMouseThreadPresent()
    && (unsigned int)CSession::IsDwmRequiredInSession(qword_1400D09D0) )
  {
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 26LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
    }
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_DwmpCreateSessionProcess_Start) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_DwmpCreateSessionProcess_Start, 0LL, 0LL);
    SessionProcess = DwmpCreateSessionProcess(0LL);
    v125 = SessionProcess;
    if ( SessionProcess < 0
      && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100000) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        27LL,
        &WPP_407213ad3eb136be1485685444407d59_Traceguids,
        (unsigned int)SessionProcess);
    }
    v103[0] = 0;
    WinlogonProvider::DwmpCreateSessionProcess<bool,long &>(v103, &v125);
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_DwmpCreateSessionProcess_Stop) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_DwmpCreateSessionProcess_Stop, 0LL, 0LL);
  }
  if ( g_fRunSetup )
  {
    RecordBlackboxInfo(L"SetupCreateSplashScreen", 1, (struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
    SetupCreateSplashScreen(*((HDESK *)qword_1400D09D0 + 15));
    RecordBlackboxInfo(L"SetupCreateSplashScreen", 0, (struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
  }
  if ( *((_DWORD *)qword_1400D09D0 + 37) != 1 )
  {
    BaseInitAppcompatCacheSupport();
    g_WinlogonStage = 16;
  }
  v10 = InitializeCustomThreadPool();
  LODWORD(v100) = v10;
  if ( v10 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x10) == 0
      || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
    {
      goto LABEL_79;
    }
    v36 = 28LL;
    goto LABEL_125;
  }
  g_WinlogonStage = 17;
  if ( !g_fRunSetup )
    goto LABEL_62;
  EventW = CreateEventW(0LL, 1, 0, L"Global\\UMSServicesStarted");
  v58 = GetLastError();
  LODWORD(v100) = v58;
  if ( !EventW )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      goto LABEL_270;
    }
    v59 = 29LL;
LABEL_269:
    WPP_SF_D(*((_QWORD *)v27 + 2), v59, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v58);
    v27 = WPP_GLOBAL_Control;
LABEL_270:
    v102 = 1;
    goto LABEL_79;
  }
  if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
    && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
  {
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      30LL,
      &WPP_407213ad3eb136be1485685444407d59_Traceguids,
      (unsigned int)v100);
  }
  v58 = WaitForSingleObjectEx(EventW, 0xFFFFFFFF, 1);
  LODWORD(v100) = v58;
  if ( v58 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      goto LABEL_270;
    }
    v59 = 31LL;
    goto LABEL_269;
  }
  CloseHandle(EventW);
  if ( (unsigned __int8)IsCreateWindowStationWPresent() )
    CSession::SwitchDesktop(qword_1400D09D0, 2LL, 0LL, 0LL, 0);
  v60 = WinLogonSetup((int *)&v102, &v105, &v106);
  LODWORD(v100) = v60;
  if ( v60 )
  {
    v27 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) )
    {
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 32LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v60);
      v27 = WPP_GLOBAL_Control;
    }
    v102 = 1;
    v31 = 0;
    HIDWORD(v100) = 0;
    goto LABEL_356;
  }
  v4 = v102;
  v5 = v105;
  if ( !v102 || v105 )
  {
    RecordBlackboxInfo(L"SetupDestroySplashScreen", 1, (struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
    SetupDestroySplashScreen();
    RecordBlackboxInfo(L"SetupDestroySplashScreen", 0, (struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
    if ( (unsigned __int8)IsCreateWindowStationWPresent() )
    {
      if ( v5 || !IsOOBETransitionUXVisible() )
        CSession::SwitchDesktop(qword_1400D09D0, 0LL, 0LL, 0LL, 0);
    }
  }
  if ( v4 == 1 )
  {
    if ( !v5 )
    {
      LODWORD(v100) = ShutdownWindowsWorker(v106, 0, &v104);
      goto LABEL_117;
    }
  }
  else
  {
    CMachine::GetName(qword_1400D09C8, 0LL, 0LL);
  }
LABEL_62:
  if ( !*(_DWORD *)(xGlobalContext + 200LL) && !g_fWinPEMode )
  {
    if ( *((_DWORD *)qword_1400D09D0 + 43) )
    {
      if ( !IsUserOOBELanguageChoicePending() )
      {
        v61 = RtlpVerifyAndCommitUILanguageSettings(0LL);
        v126 = v61;
        if ( v61 < 0 )
        {
          v27 = WPP_GLOBAL_Control;
          if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x10) != 0
            && *((_BYTE *)WPP_GLOBAL_Control + 25) )
          {
            WPP_SF_D(
              *((_QWORD *)WPP_GLOBAL_Control + 2),
              33LL,
              &WPP_407213ad3eb136be1485685444407d59_Traceguids,
              (unsigned int)v61);
            v27 = WPP_GLOBAL_Control;
          }
          LODWORD(v100) = 1036;
          v106 = ShutdownPowerOff;
          v109 = 0;
          v102 = 1;
          goto LABEL_79;
        }
      }
    }
  }
  g_WinlogonStage = 18;
  v23 = RemoveTokenPrivileges();
  v126 = v23;
  if ( v23 >= 0 )
  {
    g_WinlogonStage = 19;
    v24 = RemoveCriticalPrivileges(xGlobalContext + 80LL);
    if ( v24 >= 0 )
      v25 = 0;
    else
      v25 = RtlNtStatusToDosError(v24);
    v127 = v25;
    LODWORD(v100) = v25;
    if ( v25 )
    {
      v27 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
      {
        goto LABEL_79;
      }
      v39 = 35LL;
LABEL_315:
      WPP_SF_D(*((_QWORD *)v27 + 2), v39, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v25);
      goto LABEL_117;
    }
    g_WinlogonStage = 20;
    v26 = WlAccessibilityOnBoot((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
    LODWORD(v100) = v26;
    if ( v26 )
    {
      v27 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x40000) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
      {
LABEL_69:
        g_WinlogonStage = 21;
        if ( g_TraceRegHandle )
        {
          if ( (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_StartLogonUI_Start) )
            EtwEventWrite(g_TraceRegHandle, &WLEvt_StartLogonUI_Start, 0LL, 0LL);
          v27 = WPP_GLOBAL_Control;
        }
        if ( *((_DWORD *)qword_1400D09D0 + 37) == 1 || (v28 = IsWinLogonExtPresent(v27), v27 = WPP_GLOBAL_Control, !v28) )
        {
          v30 = 0;
        }
        else
        {
          v128[0] = 0;
          dword_1400D1830 = 2;
          v30 = WluiStartup(v27, *(_QWORD *)(xGlobalContext + 80LL), v128);
          dword_1400D1830 = 0;
          v27 = WPP_GLOBAL_Control;
        }
        v128[1] = v30;
        LODWORD(v100) = v30;
        if ( g_TraceRegHandle )
        {
          if ( (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, "h") )
            EtwEventWrite(g_TraceRegHandle, "h", 0LL, 0LL);
          v27 = WPP_GLOBAL_Control;
        }
        v25 = v100;
        if ( (_DWORD)v100 )
        {
          if ( v27 == (CUser *)&WPP_GLOBAL_Control || (*((_BYTE *)v27 + 28) & 1) == 0 || *((_BYTE *)v27 + 25) < 2u )
            goto LABEL_79;
          v39 = 37LL;
        }
        else
        {
          g_WinlogonStage = 22;
          if ( v4 && v5 )
          {
            LODWORD(v100) = ShutdownWindowsWorker(v106, v5, &v104);
            goto LABEL_117;
          }
          v25 = WlStateMachineInitialize();
          LODWORD(v100) = v25;
          if ( v25 )
          {
            v27 = WPP_GLOBAL_Control;
            if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
              || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
              || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
            {
              goto LABEL_79;
            }
            v39 = 38LL;
          }
          else
          {
            g_WinlogonStage = 23;
            v25 = WMsgClntInitialize((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext, 0);
            LODWORD(v100) = v25;
            if ( v25 )
            {
              v27 = WPP_GLOBAL_Control;
              if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
                || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
                || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
              {
                goto LABEL_79;
              }
              v39 = 39LL;
            }
            else
            {
              g_WinlogonStage = 24;
              if ( (unsigned __int8)IsLoadLocalFontsPresent() )
              {
                if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
                  && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 5u )
                {
                  WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 40LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
                }
                started = StartLoadingFonts();
                LODWORD(v100) = started;
                if ( started
                  && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
                  && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
                {
                  WPP_SF_D(
                    *((_QWORD *)WPP_GLOBAL_Control + 2),
                    41LL,
                    &WPP_407213ad3eb136be1485685444407d59_Traceguids,
                    started);
                }
              }
              g_WinlogonStage = 25;
              v25 = ToInitialize();
              LODWORD(v100) = v25;
              if ( v25 )
              {
                v27 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
                  || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x1000) == 0
                  || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
                {
                  goto LABEL_79;
                }
                v39 = 42LL;
              }
              else
              {
                g_WinlogonStage = 26;
                *(_QWORD *)&Recipient = PowerSettingLockConsoleOnWakeCallback;
                *((_QWORD *)&Recipient + 1) = 0LL;
                v25 = PowerSettingRegisterNotification(
                        &GUID_LOCK_CONSOLE_ON_WAKE,
                        2u,
                        &Recipient,
                        &g_hPowerNotification);
                LODWORD(v100) = v25;
                if ( !v25 )
                {
                  g_WinlogonStage = 27;
                  *(_DWORD *)v115 = 0;
                  hKey = 0LL;
                  if ( !RegOpenKeyExW(
                          HKEY_LOCAL_MACHINE,
                          L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
                          0,
                          0x2001Bu,
                          &hKey) )
                  {
                    lpcbData = 4;
                    RegQueryValueExW(hKey, L"AnimationAfterUserOOBE", 0LL, 0LL, v115, &lpcbData);
                    RegDeleteValueW(hKey, L"AnimationAfterUserOOBE");
                    RegCloseKey(hKey);
                  }
                  if ( *(_DWORD *)v115 == 1 )
                  {
                    v116 = 0;
                    CMachine::RegQueryDWORD(
                      v33,
                      L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
                      L"SkipNextFirstLogonAnimation",
                      0,
                      &v116);
                    v117 = 0;
                    CMachine::RegQueryDWORD(
                      v62,
                      L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
                      L"EnableFirstLogonAnimation",
                      0,
                      &v117);
                    v118 = 1;
                    CMachine::RegQueryDWORD(
                      v63,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",
                      L"EnableFirstLogonAnimation",
                      1u,
                      &v118);
                    if ( v116 )
                    {
                      v132 = 0LL;
                      if ( !RegOpenKeyExW(
                              HKEY_LOCAL_MACHINE,
                              L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon",
                              0,
                              0x2001Bu,
                              &v132) )
                      {
                        RegDeleteValueW(v132, L"SkipNextFirstLogonAnimation");
                        RegCloseKey(v132);
                      }
                    }
                    else if ( v117 && v118 )
                    {
                      v64 = WluiInformLogonUI(v116 + 5, 0LL, 0LL);
                      LODWORD(v100) = v64;
                      if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
                        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
                        && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
                      {
                        WPP_SF_lll(
                          *((_QWORD *)WPP_GLOBAL_Control + 2),
                          44LL,
                          &WPP_407213ad3eb136be1485685444407d59_Traceguids,
                          5LL,
                          0,
                          v64);
                      }
                      g_fLaunchedFirstLogonAnimation = 1;
                    }
                  }
                  if ( g_TraceRegHandle
                    && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_RunStateMachine_Start) )
                  {
                    EtwEventWrite(g_TraceRegHandle, &WLEvt_RunStateMachine_Start, 0LL, 0LL);
                  }
                  v34 = v136;
                  if ( !*(_QWORD *)&v136 )
                  {
                    GetSystemTimeAsFileTime(&v136);
                    v34 = v136;
                  }
                  v120 = 0LL;
                  if ( !*(_QWORD *)&v34 )
                  {
                    v138 = 0LL;
                    GetSystemTimeAsFileTime(&v138);
                    v34 = v138;
                  }
                  v35 = (*(_QWORD *)&v34 - *(_QWORD *)&SystemTimeAsFileTime) / 0x2710uLL;
                  v120 = v35;
                  if ( v35 > 0x7FFFFFFF )
                    LODWORD(v35) = 0x7FFFFFFF;
                  WinSqmSetDWORD(0LL, 6405LL, (unsigned int)v35);
                  v141 = StateMachineRun(qword_1400D14C8, &xGlobalContext, &v104);
                  LODWORD(v100) = v141;
                  if ( g_TraceRegHandle
                    && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_RunStateMachine_Stop) )
                  {
                    EtwEventWrite(g_TraceRegHandle, &WLEvt_RunStateMachine_Stop, 0LL, 0LL);
                  }
                  if ( (_DWORD)v100 )
                  {
                    v27 = WPP_GLOBAL_Control;
                    if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
                      || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
                      || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
                    {
                      goto LABEL_79;
                    }
                    WPP_SF_D(
                      *((_QWORD *)WPP_GLOBAL_Control + 2),
                      45LL,
                      &WPP_407213ad3eb136be1485685444407d59_Traceguids,
                      (unsigned int)v100);
                  }
                  else
                  {
                    g_WinlogonStage = 28;
                  }
                  goto LABEL_117;
                }
                v27 = WPP_GLOBAL_Control;
                if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
                  || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
                  || !*((_BYTE *)WPP_GLOBAL_Control + 25) )
                {
                  goto LABEL_79;
                }
                v39 = 43LL;
              }
            }
          }
        }
        goto LABEL_315;
      }
      WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 36LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v26);
    }
    v27 = WPP_GLOBAL_Control;
    goto LABEL_69;
  }
  v27 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
    && *((_BYTE *)WPP_GLOBAL_Control + 25) )
  {
    WPP_SF_D(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      34LL,
      &WPP_407213ad3eb136be1485685444407d59_Traceguids,
      (unsigned int)v23);
    v27 = WPP_GLOBAL_Control;
  }
  LODWORD(v100) = 1025;
  v31 = HIDWORD(v100);
LABEL_356:
  if ( (_DWORD)v100 )
  {
    if ( xGlobalContext )
    {
      CGlobalStore::ReportApplicationEvent(xGlobalContext, 1u, v7, 4u, &v100, 0);
      v27 = WPP_GLOBAL_Control;
    }
    if ( (_DWORD)v100 && g_WinlogonStage >= 0xE )
    {
      v88 = qword_1400D09D0;
      if ( (unsigned int)RtlGetActiveConsoleId() == *((_DWORD *)v88 + 22) && v31 )
      {
        if ( g_WinlogonStage < 0x16 )
        {
          String = AllocAndLoadString(0x7E3u, 0LL);
          v133 = String;
          v90 = AllocAndLoadString(0x7E2u, 0LL);
          v91 = v90;
          v120 = (unsigned __int64)v90;
          if ( v90 )
            MessageBoxW(0LL, v90, String, 0x10u);
          if ( String )
            UHHeapFree(&v133);
          if ( v91 )
            UHHeapFree(&v120);
        }
        else
        {
          v108 = 0;
          WlDisplayMessageByResourceId(0x7E3u, 0x7E2u, 0x10u, &v108, 0LL);
        }
      }
      v27 = WPP_GLOBAL_Control;
    }
  }
  if ( v27 != (CUser *)&WPP_GLOBAL_Control && (*((_BYTE *)v27 + 28) & 1) != 0 && *((_BYTE *)v27 + 25) >= 5u )
    WPP_SF_(*((_QWORD *)v27 + 2), 46LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
  RecordLastLogoffEndTime();
  if ( v104 - 2 <= 2 && (unsigned int)RtlGetActiveConsoleId() == NtCurrentPeb()->SessionId && qword_1400D09D0 )
  {
    UnlockWindowStation(*((_QWORD *)qword_1400D09D0 + 12));
    LockWindowStation(*((_QWORD *)qword_1400D09D0 + 12));
  }
  if ( g_hPowerNotification )
    PowerSettingUnregisterNotification(g_hPowerNotification);
  v65 = g_WinlogonStage;
  if ( g_WinlogonStage >= 0xC )
  {
    WMsgClntTerminate();
    v65 = g_WinlogonStage;
  }
  if ( v65 >= 0xB )
  {
    AsyncLogoffSupportUninit();
    v65 = g_WinlogonStage;
  }
  if ( v65 >= 0x11 )
    CleanupCustomThreadPool();
  RtlAcquireResourceExclusive(&g_lockObject, 1u);
  v66 = g_dwRefCount;
  if ( g_dwRefCount )
  {
    --g_dwRefCount;
    if ( v66 == 1 )
    {
      g_bInitialized = 0;
      if ( g_Uninitialize )
      {
        g_Uninitialize();
        g_Uninitialize = 0LL;
      }
      RtlDeleteResource(&g_EvalLock);
      if ( qword_1400D0F90 )
      {
        EncryptHandle::DestroyEncryptHandle(qword_1400D0F90);
        qword_1400D0F90 = 0LL;
      }
      g_pFnLog = 0LL;
    }
  }
  else
  {
    LODWORD(phkResult) = 116;
    DbgPrintfW(
      1u,
      L"(0x%08x) %ws:%u : %ws:%ws\n",
      2147483685LL,
      L"onecore\\ds\\security\\eas\\policyengine\\initialize.cpp",
      phkResult,
      L"Extra EasEngineUninitialize call",
      &pPassword);
  }
  RtlReleaseResource(&g_lockObject);
  if ( g_WinlogonStage >= 0x15 )
  {
    v83 = WlAccessibilityOnShutdown((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
    LODWORD(v100) = v83;
    if ( v83 )
    {
      if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
        && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x40000) != 0
        && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
      {
        WPP_SF_D(*((_QWORD *)WPP_GLOBAL_Control + 2), 47LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids, v83);
      }
    }
  }
  if ( g_WinlogonStage >= 0x17 && qword_1400D14C8 )
    StateMachineDestroy(&qword_1400D14C8);
  v67 = (void *)_InterlockedExchange64((volatile __int64 *)&g_hTSJobCallbackWaitHandle, -1LL);
  if ( v67 )
    UnregisterWaitEx(v67, (HANDLE)0xFFFFFFFFFFFFFFFFLL);
  if ( g_pTSJobCallbackLock )
    RtlDeleteCriticalSection(g_pTSJobCallbackLock);
  if ( g_WinlogonStage >= 8 )
    CleanupData((struct _WLSM_GLOBAL_CONTEXT *)&xGlobalContext);
  if ( g_WinlogonStage >= 0x1A )
    ToUninitialize();
  if ( v102 == 1 )
  {
    v102 = 0;
    ShutdownActionToFlags((unsigned int)v106, 0LL, &v102, 0LL);
    LODWORD(v100) = InternalInitiateShutdown(0, v102, v109 | 0x80020000, v92, 1);
  }
  if ( g_WinlogonStage >= 6 )
    JobManagerUninitialize();
  if ( g_WinlogonStage >= 4 )
  {
    RtlDeleteCriticalSection(&g_HungNotificationListLock);
    if ( hEventLog )
    {
      DeregisterEventSource(hEventLog);
      hEventLog = 0LL;
    }
  }
  if ( v104 - 2 <= 2 && (unsigned int)RtlGetActiveConsoleId() == NtCurrentPeb()->SessionId )
  {
    if ( g_WinlogonStage >= 2 )
    {
      WppCleanupUm();
      v93 = qword_1400CD768;
      dword_1400CD748 = 0;
      qword_1400CD768 = 0LL;
      EtwEventUnregister(v93);
      v94 = qword_1400CD730;
      dword_1400CD710 = 0;
      qword_1400CD730 = 0LL;
      EtwEventUnregister(v94);
    }
    Sleep(0x1388u);
    if ( !(unsigned int)CallCheckForHiberbootRpc(0, v95) )
      Sleep(0xFFFFFFFF);
  }
  if ( g_WinlogonStage >= 0x16 )
    WluiShutdown();
  InputBuffer = 0LL;
  v145 = 0LL;
  v68 = 0LL;
  v69 = qword_1400D09D0;
  if ( qword_1400D09D0 )
  {
    if ( (unsigned int)RtlGetActiveConsoleId() == *((_DWORD *)v69 + 22) )
    {
      ProcessHeap = GetProcessHeap();
      v71 = (char *)HeapAlloc(ProcessHeap, 8u, 0x40uLL);
      v68 = v71;
      if ( v71 )
      {
        *(_DWORD *)v71 = 1;
        *((_DWORD *)v71 + 1) = 64;
        *((_DWORD *)v71 + 2) = 1;
        *(_OWORD *)(v71 + 12) = *(_OWORD *)L"SetupDestroySplashScreen";
        *(_OWORD *)(v71 + 28) = *(_OWORD *)L"troySplashScreen";
        *(_OWORD *)(v71 + 44) = *(_OWORD *)L"shScreen";
        *((_WORD *)v71 + 30) = 0;
        DWORD2(v145) = 17;
        *(_QWORD *)&InputBuffer = v71;
        *((_QWORD *)&InputBuffer + 1) = 64LL;
        v72 = NtPowerInformation(TraceApplicationPowerMessage|0x40, &InputBuffer, 0x20u, 0LL, 0);
        if ( v72 < 0
          && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
          && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            153LL,
            &WPP_0f2f44d3282f362762ce2e583ae54d1b_Traceguids,
            (unsigned int)v72);
        }
        goto LABEL_391;
      }
      v84 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
      {
        goto LABEL_391;
      }
      v85 = 152LL;
    }
    else
    {
      v84 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x1000) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 5u )
      {
        goto LABEL_391;
      }
      v85 = 151LL;
    }
    WPP_SF_(*((_QWORD *)v84 + 2), v85, &WPP_0f2f44d3282f362762ce2e583ae54d1b_Traceguids);
  }
LABEL_391:
  if ( v68 )
  {
    v73 = GetProcessHeap();
    HeapFree(v73, 0, v68);
  }
  v74 = hLibModule;
  if ( hLibModule )
  {
    if ( qword_1400D1780 )
    {
      qword_1400D1780();
      v74 = hLibModule;
    }
    qword_1400D1790 = 0LL;
    qword_1400D1780 = 0LL;
    FreeLibrary(v74);
    hLibModule = 0LL;
  }
  InputBuffer = 0LL;
  v145 = 0LL;
  v75 = 0LL;
  v76 = qword_1400D09D0;
  if ( qword_1400D09D0 )
  {
    if ( (unsigned int)RtlGetActiveConsoleId() == *((_DWORD *)v76 + 22) )
    {
      v77 = GetProcessHeap();
      v78 = (char *)HeapAlloc(v77, 8u, 0x40uLL);
      v75 = v78;
      if ( v78 )
      {
        *(_DWORD *)v78 = 1;
        *(_QWORD *)(v78 + 4) = 64LL;
        *(_OWORD *)(v78 + 12) = *(_OWORD *)L"SetupDestroySplashScreen";
        *(_OWORD *)(v78 + 28) = *(_OWORD *)L"troySplashScreen";
        *(_OWORD *)(v78 + 44) = *(_OWORD *)L"shScreen";
        *((_WORD *)v78 + 30) = 0;
        DWORD2(v145) = 17;
        *(_QWORD *)&InputBuffer = v78;
        *((_QWORD *)&InputBuffer + 1) = 64LL;
        v79 = NtPowerInformation(TraceApplicationPowerMessage|0x40, &InputBuffer, 0x20u, 0LL, 0);
        if ( v79 < 0
          && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
          && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
        {
          WPP_SF_D(
            *((_QWORD *)WPP_GLOBAL_Control + 2),
            153LL,
            &WPP_0f2f44d3282f362762ce2e583ae54d1b_Traceguids,
            (unsigned int)v79);
        }
        goto LABEL_398;
      }
      v86 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 2u )
      {
        goto LABEL_398;
      }
      v87 = 152LL;
    }
    else
    {
      v86 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control == (CUser *)&WPP_GLOBAL_Control
        || (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x1000) == 0
        || *((_BYTE *)WPP_GLOBAL_Control + 25) < 5u )
      {
        goto LABEL_398;
      }
      v87 = 151LL;
    }
    WPP_SF_(*((_QWORD *)v86 + 2), v87, &WPP_0f2f44d3282f362762ce2e583ae54d1b_Traceguids);
  }
LABEL_398:
  if ( v75 )
  {
    v80 = GetProcessHeap();
    HeapFree(v80, 0, v75);
  }
  if ( (unsigned __int8)IsDwmpStartWinlogonMouseThreadPresent() )
  {
    WLEventWrite(&WLEvt_DwmpTerminateSessionProcess_Start);
    v96 = DwmpTerminateSessionProcess(0LL);
    v105 = v96;
    if ( v96 < 0
      && WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_DWORD *)WPP_GLOBAL_Control + 7) & 0x100000) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 2u )
    {
      WPP_SF_D(
        *((_QWORD *)WPP_GLOBAL_Control + 2),
        48LL,
        &WPP_407213ad3eb136be1485685444407d59_Traceguids,
        (unsigned int)v96);
    }
    WinlogonProvider::DwmpTerminateSessionProcess<long &>(&v105);
    WLEventWrite(&WLEvt_DwmpTerminateSessionProcess_Stop);
  }
  if ( (unsigned __int8)IsThemesOnLogoffPresent() )
  {
    if ( WPP_GLOBAL_Control != (CUser *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 1) != 0
      && *((_BYTE *)WPP_GLOBAL_Control + 25) >= 4u )
    {
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 49LL, &WPP_407213ad3eb136be1485685444407d59_Traceguids);
    }
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_ThemesOnTerminateSession_Start) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_ThemesOnTerminateSession_Start, 0LL, 0LL);
    ThemesOnTerminateSession();
    if ( g_TraceRegHandle && (unsigned __int8)EtwEventEnabled(g_TraceRegHandle, &WLEvt_ThemesOnTerminateSession_Stop) )
      EtwEventWrite(g_TraceRegHandle, &WLEvt_ThemesOnTerminateSession_Stop, 0LL, 0LL);
  }
  v81 = (BOOL (__stdcall *)(PINIT_ONCE, PVOID, PVOID *))lambda_7541624f7ef672258654b98c68450f40_::operator_int____cdecl____RTL_RUN_ONCE___void___void_____();
  if ( InitOnceExecuteOnce(&InitOnce, v81, 0LL, 0LL) )
  {
    Recipient = 0LL;
    LODWORD(Recipient) = 1;
    DWORD2(Recipient) = 0;
    ExecuteNamedEscape((struct tagUMFD_WINLOGON_ESCAPE_ARGUMENT *)&Recipient);
    DeleteCriticalSection(&g_csNamedEscape);
  }
  DeleteCriticalSection(&stru_1400D11E0);
  if ( g_TraceRegHandle )
  {
    EtwEventUnregister(g_TraceRegHandle);
    g_TraceRegHandle = 0LL;
  }
  McGenEventUnregister_EtwEventUnregister();
  if ( g_WinlogonStage >= 2 )
  {
    WppCleanupUm();
    v97 = qword_1400CD768;
    dword_1400CD748 = 0;
    qword_1400CD768 = 0LL;
    EtwEventUnregister(v97);
    v98 = qword_1400CD730;
    dword_1400CD710 = 0;
    qword_1400CD730 = 0LL;
    EtwEventUnregister(v98);
  }
  return v100;
}
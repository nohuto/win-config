// Hidden C++ exception states: #wind=2
__int64 __fastcall TabletModeController::RuntimeClassInitialize(TabletModeController *this)
{
  int v2; // edi
  __int64 v3; // rdx
  enum _TABLETMODESTATE *v5; // rdx
  char v6; // di
  int *v7; // rsi
  unsigned int v8; // eax
  unsigned int *v9; // r8
  bool v10; // al
  int v11; // edx
  int v12; // ecx
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rcx
  PTP_TIMER ThreadpoolTimer; // rax
  int phkResult; // [rsp+20h] [rbp-20h]
  wil::details::in1diag3 *retaddr; // [rsp+68h] [rbp+28h]
  unsigned int v21; // [rsp+70h] [rbp+30h] BYREF
  int v22; // [rsp+78h] [rbp+38h] BYREF
  HKEY v23; // [rsp+80h] [rbp+40h] BYREF

  v2 = CImmersiveShellComponent::RegisterServiceInformation(
         (TabletModeController *)((char *)this + 40),
         &GUID_4fda780a_acd2_41f7_b4f2_ebe674c9bf2a);
  if ( v2 < 0 )
  {
    v3 = 49LL;
LABEL_3:
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)v3,
      (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
      (const char *)(unsigned int)v2,
      phkResult);
    return (unsigned int)v2;
  }
  v2 = TabletModeToast_Initialize();
  if ( v2 < 0 )
  {
    v3 = 50LL;
    goto LABEL_3;
  }
  v6 = 1;
  LOBYTE(v21) = 1;
  v7 = (int *)((char *)this + 192);
  if ( (int)TabletModeHelpers::QueryTabletMode((TabletModeController *)((char *)this + 192), v5) >= 0 )
  {
    CreateShellSessionSubKey(L"TabletModeControllerInitialized", 1u, (bool *)&v21, 0LL);
    v6 = v21;
  }
  v8 = TabletModeController::InitializeModeTriggerCachedValue(this);
  wil::details::in1diag3::Log_IfFailedWithExpected(
    retaddr,
    (void *)0x40,
    (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
    (const char *)v8,
    1,
    0x80070002);
  if ( v6 )
  {
    *v7 = 0;
    TabletModeController::HandleSwitchModeTelemetry(this, 0LL, 8 - (unsigned int)(*((_DWORD *)this + 188) != 5));
    v23 = 0LL;
    v10 = !RegOpenKeyExW(
             HKEY_CURRENT_USER,
             L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\TabletMode",
             0,
             0x20019u,
             &v23)
       && (unsigned int)SHRegValueExists(v23, L"STCDefaultMigrationCompleted", v9);
    *((_BYTE *)this + 250) = v10;
    v21 = 1;
    v22 = 1;
    (*(void (__fastcall **)(char *, unsigned int *, int *))(*((_QWORD *)this + 13) + 48LL))(
      (char *)this + 104,
      &v21,
      &v22);
    *((_DWORD *)this + 152) = v21;
    *((_DWORD *)this + 153) = v22;
    v11 = *((_DWORD *)this + 188);
    v12 = *v7;
    *((_DWORD *)this + 149) = *((_DWORD *)this + 150);
    *((_DWORD *)this + 150) = v12 == 1;
    v13 = (unsigned int)(5 - v11);
    *((_DWORD *)this + 151) = 8 - ((_DWORD)v13 != 0);
    if ( TabletModeControllerTelemetry::IsEnabled(v12, v13) )
    {
      wil::details::static_lazy<TabletModeControllerTelemetry>::get(
        v15,
        _lambda_f8aecc173107acd1c48966a4b04e60c6_::_lambda_invoker_cdecl_);
      TabletModeControllerTelemetry::TabletModeCSMEvent_(
        *((unsigned int *)this + 152),
        *((unsigned int *)this + 147),
        *((unsigned int *)this + 148),
        *((unsigned int *)this + 149),
        *((_DWORD *)this + 150),
        *((_DWORD *)this + 151),
        *((_DWORD *)this + 152),
        *((_DWORD *)this + 153));
    }
    if ( TabletModeControllerTelemetry::IsEnabled(v15, v14) )
    {
      wil::details::static_lazy<TabletModeControllerTelemetry>::get(
        v16,
        _lambda_f8aecc173107acd1c48966a4b04e60c6_::_lambda_invoker_cdecl_);
      TabletModeControllerTelemetry::TabletModeSettings_(v17, 1LL, v21, 0LL);
    }
    TabletModeController::PublishWnfStateData((unsigned int)*v7);
    ThreadpoolTimer = CreateThreadpoolTimer(TabletModeController::s_TelemetryTimerCallback, this, 0LL);
    *((_QWORD *)this + 96) = ThreadpoolTimer;
    if ( ThreadpoolTimer )
      TabletModeController::UpdateAbsoluteTimer(this);
    wil::details::unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>::~unique_storage<wil::details::resource_policy<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),wistd::integral_constant<unsigned __int64,0>,HKEY__ *,HKEY__ *,0,std::nullptr_t>>(&v23);
  }
  return 0LL;
}


bool __fastcall TabletModeController::IsAllowedModeSwitch(__int64 a1, int a2)
{
  char v3; // bl
  int v4; // edi
  unsigned int v5; // r9d
  LPWSTR StringSid[5]; // [rsp+30h] [rbp-28h] BYREF
  int v7; // [rsp+68h] [rbp+10h] BYREF

  if ( a2 == *(_DWORD *)(a1 + 192) )
    return 0;
  v3 = 1;
  if ( a2 != 1 )
  {
    memset(StringSid, 0, 24);
    if ( (int)GetSidStringFromToken((HANDLE)0xFFFFFFFFFFFFFFFCLL, StringSid) >= 0 )
      v4 = IsUserSidAssignedAccessMultiApp(StringSid[0]);
    else
      v4 = 0;
    Windows::Internal::NativeString<Windows::Internal::LocalMemPolicy<unsigned short>>::_Free(StringSid);
    if ( v4 )
    {
      v7 = 0;
      v3 = 0;
      if ( (int)SHRegGetBOOLWithREGSAM(
                  HKEY_LOCAL_MACHINE,
                  L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell",
                  L"AllowPPITabletModeExit",
                  v5,
                  &v7) >= 0 )
        return v7 != 0;
    }
  }
  return v3;
}


__int64 __fastcall COverrideScaling::RuntimeClassInitialize(COverrideScaling *this)
{
  int v2; // eax
  unsigned int v3; // ebx
  int ValueW; // eax
  int v6; // ebx
  int v7; // eax
  LSTATUS v8; // eax
  bool v9; // sf
  int v10; // eax
  LSTATUS v11; // eax
  bool v12; // sf
  int v13; // [rsp+20h] [rbp-20h]
  wil::details::in1diag3 *retaddr; // [rsp+58h] [rbp+18h]
  int pvData; // [rsp+60h] [rbp+20h] BYREF
  int v16; // [rsp+68h] [rbp+28h] BYREF
  int v17; // [rsp+70h] [rbp+30h] BYREF
  DWORD pcbData; // [rsp+78h] [rbp+38h] BYREF

  v2 = CImmersiveShellComponent::RegisterServiceInformation(
         (COverrideScaling *)((char *)this + 40),
         &GUID_7cd9be4a_c818_4888_8a3b_b98dc23ef75d);
  v3 = v2;
  if ( v2 >= 0 )
  {
    pvData = 0;
    pcbData = 4;
    ValueW = RegGetValueW(
               HKEY_LOCAL_MACHINE,
               L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell\\OverrideScaling",
               L"SmallScreen",
               0x10u,
               0LL,
               &pvData,
               &pcbData);
    if ( ValueW > 0 )
      ValueW = (unsigned __int16)ValueW | 0x80070000;
    v6 = 83;
    if ( ValueW >= 0 )
    {
      v7 = pvData;
    }
    else
    {
      v7 = 83;
      pvData = 83;
    }
    v16 = 0;
    *((_DWORD *)this + 43) = v7;
    pcbData = 4;
    v8 = RegGetValueW(
           HKEY_LOCAL_MACHINE,
           L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell\\OverrideScaling",
           L"VerySmallScreen",
           0x10u,
           0LL,
           &v16,
           &pcbData);
    v9 = v8 < 0;
    if ( v8 > 0 )
      v9 = 1;
    if ( v9 )
    {
      v10 = 71;
      v16 = 71;
    }
    else
    {
      v10 = v16;
    }
    v17 = 0;
    *((_DWORD *)this + 44) = v10;
    pcbData = 4;
    v11 = RegGetValueW(
            HKEY_LOCAL_MACHINE,
            L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell\\OverrideScaling",
            L"TabletSmallScreen",
            0x10u,
            0LL,
            &v17,
            &pcbData);
    v12 = v11 < 0;
    if ( v11 > 0 )
      v12 = 1;
    if ( !v12 )
      v6 = v17;
    *((_DWORD *)this + 45) = v6;
    return 0LL;
  }
  else
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x2D,
      (unsigned int)"shell\\twinui\\overridescaling\\lib\\overridescaling.cpp",
      (const char *)(unsigned int)v2,
      v13);
    return v3;
  }
}

// Hidden C++ exception states: #wind=2
__int64 __fastcall TabletModeController::SetModeInternal(__int64 a1, int a2, int a3)
{
  unsigned int v6; // ebx
  TabletModeHelpers *v8; // rcx
  int v9; // eax
  int CallbackArray; // eax
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  int v14; // [rsp+20h] [rbp-30h]
  int v15; // [rsp+20h] [rbp-30h]
  int v16[2]; // [rsp+30h] [rbp-20h] BYREF
  _BYTE v17[24]; // [rsp+38h] [rbp-18h] BYREF
  wil::details::in1diag3 *retaddr; // [rsp+68h] [rbp+18h]
  int v19; // [rsp+78h] [rbp+28h] BYREF
  int v20; // [rsp+80h] [rbp+30h] BYREF
  struct IObjectArray *v21; // [rsp+88h] [rbp+38h] BYREF

  v20 = a3;
  v19 = a2;
  if ( a2 == 1 && !*(_BYTE *)(a1 + 696) )
  {
    v6 = -2147019873;
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x2C2,
      (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
      (const char *)0x8007139FLL,
      v14);
    return v6;
  }
  if ( (unsigned __int8)TabletModeController::IsAllowedModeSwitch() )
  {
    *(_DWORD *)(a1 + 192) = a2;
    *(_DWORD *)(a1 + 752) = a3;
    if ( a2 == 1 )
      SHRegSetBOOL(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell",
        L"TabletModeActivated",
        1);
    if ( a3 == 4 && TabletModeHelpers::HasConvertibleSlateModeChanged(v8) && !GetSystemMetrics(8195) && a2 != 1 )
      SHRegSetBOOL(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell",
        L"ExitedTabletModeWhileCSMActive",
        1);
    v9 = TabletModeController::PersistModeTriggerCachedValue((TabletModeController *)a1);
    if ( v9 < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x2D7,
        (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
        (const char *)(unsigned int)v9,
        v14);
    TabletModeToast::RemoveToast();
    v21 = 0LL;
    Microsoft::WRL::ComPtr<IProjectCharmSession>::InternalRelease(&v21);
    CallbackArray = CGITRegistrationList::GetCallbackArray((CGITRegistrationList *)(a1 + 616), &v21);
    v6 = CallbackArray;
    if ( CallbackArray < 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x2DC,
        (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
        (const char *)(unsigned int)CallbackArray,
        v14);
LABEL_19:
      Microsoft::WRL::ComPtr<IProjectCharmSession>::InternalRelease(&v21);
      return v6;
    }
    *(_QWORD *)v16 = a1;
    Microsoft::WRL::ComPtr<IInspectable>::InternalAddRef(v16);
    v11 = lambda_b8892081a140c54f2e2c18e8c9c02f89_::_lambda_b8892081a140c54f2e2c18e8c9c02f89_(
            (unsigned int)v17,
            (unsigned int)&v19,
            (unsigned int)&v20,
            (unsigned int)&v21,
            (__int64)v16);
    v6 = Windows::Internal::ComTaskPool::QueueTask__lambda_b8892081a140c54f2e2c18e8c9c02f89___(
           v13,
           v12,
           *(unsigned int *)(a1 + 224),
           v11);
    lambda_b8892081a140c54f2e2c18e8c9c02f89_::__lambda_b8892081a140c54f2e2c18e8c9c02f89_(v17);
    if ( (v6 & 0x80000000) != 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x2F6,
        (unsigned int)"shell\\twinui\\tabletmodecontroller\\lib\\tabletmodecontroller.cpp",
        (const char *)v6,
        v15);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)a1 + 16LL))(a1);
      goto LABEL_19;
    }
    (*(void (__fastcall **)(__int64))(*(_QWORD *)a1 + 16LL))(a1);
    Microsoft::WRL::ComPtr<IProjectCharmSession>::InternalRelease(&v21);
  }
  return 0LL;
}

LSTATUS __fastcall TabletModeController::SaveMode(__int64 a1, int a2)
{
  LSTATUS result; // eax
  HKEY hKey; // [rsp+60h] [rbp+8h] BYREF
  BOOL Data; // [rsp+68h] [rbp+10h] BYREF

  hKey = 0LL;
  Data = a2 == 1;
  result = RegCreateKeyExW(
             HKEY_CURRENT_USER,
             L"Software\\Microsoft\\Windows\\CurrentVersion\\ImmersiveShell",
             0,
             0LL,
             0,
             2u,
             0LL,
             &hKey,
             0LL);
  if ( !result )
  {
    result = RegSetValueExW(hKey, L"TabletMode", 0, 4u, (const BYTE *)&Data, 4u);
    if ( hKey != HKEY_CURRENT_USER )
      return RegCloseKey(hKey);
  }
  return result;
}
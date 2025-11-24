void __fastcall CInputGlobals::UpdateWakeOnInputDeviceTypesFromRegistry(CInputGlobals *this) // win32k
{
  char *v2; // rdi
  __int64 v3; // rsi
  const WCHAR *v4; // rdx
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  ULONG ResultLength; // [rsp+38h] [rbp-29h] BYREF
  void *KeyHandle; // [rsp+40h] [rbp-21h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+48h] [rbp-19h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+58h] [rbp-9h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+68h] [rbp+7h] BYREF
  _BYTE KeyValueInformation[4]; // [rsp+98h] [rbp+37h] BYREF
  int v14; // [rsp+9Ch] [rbp+3Bh]
  int v15; // [rsp+A0h] [rbp+3Fh]
  int v16; // [rsp+A4h] [rbp+43h]

  RIMLockExclusive();
  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  KeyHandle = 0LL;
  DestinationString = 0LL;
  *((_DWORD *)this + 38) = 46;
  RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\SYSTEM\\INPUT");
  ObjectAttributes.RootDirectory = 0LL;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  if ( ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes) >= 0 )
  {
    ResultLength = 0;
    ValueName = 0LL;
    RtlInitUnicodeString(&ValueName, L"WakeOnInputDeviceTypes");
    if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, KeyValueInformation, 0x14u, &ResultLength) >= 0
      && v14 == 4
      && v15 == 4 )
    {
      *((_DWORD *)this + 38) = v16;
    }
    ZwClose(KeyHandle);
  }
  KeyHandle = (void *)ApiSetEditionGetPointerDeviceConfigurationKey(8LL, 131097LL);
  if ( KeyHandle )
  {
    v2 = (char *)&unk_1C02714C0;
    v3 = 5LL;
    do
    {
      v4 = (const WCHAR *)*((_QWORD *)v2 + 1);
      ResultLength = 0;
      ValueName = 0LL;
      RtlInitUnicodeString(&ValueName, v4);
      if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, KeyValueInformation, 0x14u, &ResultLength) >= 0
        && v14 == 4
        && v15 == 4 )
      {
        v5 = *(_DWORD *)v2;
        v6 = *((_DWORD *)this + 38);
        if ( v16 )
          v7 = v5 | v6;
        else
          v7 = ~v5 & v6;
        *((_DWORD *)this + 38) = v7;
      }
      v2 += 16;
      --v3;
    }
    while ( v3 );
    ZwClose(KeyHandle);
  }
  CInpPushLock::UnLockExclusive(this);
}


// 10.0.26100.4202 ism

// Hidden C++ exception states: #wind=3
__int64 __fastcall InputStateManager::Initialize(InputStateManager *this, __int64 a2)
{
  int v3; // eax
  _QWORD *v4; // r15
  int v5; // eax
  const char *v6; // r9
  __int64 v7; // rdi
  __int64 (__fastcall *v8)(__int64, HLOCAL, char *); // rbx
  int v9; // eax
  __int64 v10; // rsi
  __int64 (__fastcall *v11)(__int64, __int64 (__fastcall *)(void *, void *, int), InputStateManager *, _QWORD); // rdi
  int v12; // eax
  __int64 v13; // rdi
  __int64 (__fastcall *v14)(__int64, __int64 *); // rbx
  int v15; // eax
  int v16; // eax
  HKEY v17; // rcx
  DWORD TickCount; // eax
  __int64 v19; // rcx
  int v21; // [rsp+20h] [rbp-20h]
  int v22; // [rsp+20h] [rbp-20h]
  HLOCAL hMem; // [rsp+30h] [rbp-10h] BYREF
  char v24; // [rsp+38h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+68h] [rbp+28h]
  __int64 v26; // [rsp+78h] [rbp+38h] BYREF

  hMem = 0LL;
  v24 = 0;
  v26 = 0LL;
  v3 = InputSecurityDescriptor::QueryDescriptor(&hMem, a2, c_wszMessagePortNames);
  if ( v3 < 0 )
    wil::details::in1diag3::FailFast_Hr(
      retaddr,
      (void *)0x8A,
      (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
      (const char *)(unsigned int)v3,
      v21);
  v4 = (_QWORD *)((char *)this + 48);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease((char *)this + 48);
  v5 = CoreUICreate((char *)this + 48);
  if ( v5 < 0 )
    wil::details::in1diag3::FailFast_Hr(
      retaddr,
      (void *)0x8C,
      (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
      (const char *)(unsigned int)v5,
      v21);
  if ( !ISMScenarios::s_instance )
    wil::details::in1diag3::_FailFast_Unexpected(
      retaddr,
      (void *)0x1C,
      (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\utilities\\ismstatics\\system\\ismscenarios.cpp",
      v6);
  if ( !*(_DWORD *)ISMScenarios::s_instance )
  {
    v7 = *v4;
    v8 = *(__int64 (__fastcall **)(__int64, HLOCAL, char *))(*(_QWORD *)*v4 + 64LL);
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease((char *)this + 56);
    v9 = v8(v7, hMem, (char *)this + 56);
    if ( v9 < 0 )
      wil::details::in1diag3::FailFast_Hr(
        retaddr,
        (void *)0x94,
        (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
        (const char *)(unsigned int)v9,
        v21);
    wil::unique_com_token<IMessageSession,unsigned __int64,void (IMessageSession *,unsigned __int64),&void wil::details::IMessageSessionCloseEndpointFunction(IMessageSession *,unsigned __int64),0>::reset(
      (char *)this + 64,
      *v4);
    v10 = *v4;
    v11 = *(__int64 (__fastcall **)(__int64, __int64 (__fastcall *)(void *, void *, int), InputStateManager *, _QWORD))(*(_QWORD *)*v4 + 104LL);
    wil::unique_com_token<IMessageSession,unsigned __int64,void (IMessageSession *,unsigned __int64),&void wil::details::IMessageSessionCloseEndpointFunction(IMessageSession *,unsigned __int64),0>::reset(
      (char *)this + 64,
      *((_QWORD *)this + 8));
    v22 = (_DWORD)this + 72;
    v12 = v11(v10, InputStateManager::OnDeviceCommandStatic, this, *((_QWORD *)this + 7));
    if ( v12 < 0 )
      wil::details::in1diag3::FailFast_Hr(
        retaddr,
        (void *)0x9C,
        (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
        (const char *)(unsigned int)v12,
        v22);
    v13 = *v4;
    v14 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)*v4 + 24LL);
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v26);
    v15 = v14(v13, &v26);
    if ( v15 < 0 )
      wil::details::in1diag3::FailFast_Hr(
        retaddr,
        (void *)0x9E,
        (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
        (const char *)(unsigned int)v15,
        v22);
    v16 = (*(__int64 (__fastcall **)(__int64, const wchar_t *, _QWORD, __int64))(*(_QWORD *)v26 + 40LL))(
            v26,
            L"System\\Input\\DeviceCommandEndpoint",
            *((_QWORD *)this + 9),
            1LL);
    if ( v16 < 0 )
      wil::details::in1diag3::FailFast_Hr(
        retaddr,
        (void *)0xA3,
        (unsigned int)"onecoreuap\\windows\\moderncore\\inputv2\\inputstatemanager\\lib\\inputstatemanager.cpp",
        (const char *)(unsigned int)v16,
        v22);
    TestCommandHost::Initialize();
  }
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease((char *)this + 184);
  if ( RegistryWatcher::Create(
         v17,
         L"System\\Input",
         this,
         (void (*)(void *, HKEY))InputStateManager::OnInputRegistryKeyChangeStatic,
         (struct RegistryWatcher **)this + 23) < 0 )
  {
    *((_DWORD *)this + 48) = 6;
    *((_DWORD *)this + 49) = -1;
  }
  TickCount = GetTickCount();
  NtMITUpdateInputGlobals(TickCount, 0LL, 0LL, 0xFFFFFFFFLL, 0);
  v19 = v26;
  if ( v26 )
  {
    v26 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16LL))(v19);
  }
  if ( hMem )
  {
    if ( v24 )
      FreeTransientObjectSecurityDescriptor();
    else
      LocalFree(hMem);
  }
  return 0LL;
}

// Hidden C++ exception states: #wind=3
void __fastcall InputStateManager::OnInputRegistryKeyChangeStatic(InputStateManager *a1, HKEY a2)
{
  if ( a1 )
    InputStateManager::OnInputRegistryKeyChange(a1, a2);
}

void __fastcall InputStateManager::OnInputRegistryKeyChange(InputStateManager *this, HKEY a2)
{
  LSTATUS v4; // eax
  bool v5; // sf
  LSTATUS v6; // eax
  bool v7; // sf
  DWORD cbData[4]; // [rsp+30h] [rbp-10h] BYREF
  DWORD Type; // [rsp+60h] [rbp+20h] BYREF
  int Data; // [rsp+68h] [rbp+28h] BYREF

  Type = 0;
  Data = 0;
  cbData[0] = 4;
  v4 = RegQueryValueExW(a2, L"WakeOnInputDeviceTypes", 0LL, &Type, (LPBYTE)&Data, cbData);
  v5 = v4 < 0;
  if ( v4 > 0 )
    v5 = 1;
  if ( v5 || Type != 4 )
    *((_DWORD *)this + 48) = 6;
  else
    *((_DWORD *)this + 48) = Data;
  Type = 0;
  Data = 0;
  cbData[0] = 4;
  v6 = RegQueryValueExW(a2, L"UnDimOnInputDeviceTypes", 0LL, &Type, (LPBYTE)&Data, cbData);
  v7 = v6 < 0;
  if ( v6 > 0 )
    v7 = 1;
  if ( v7 || Type != 4 )
    *((_DWORD *)this + 49) = -1;
  else
    *((_DWORD *)this + 49) = Data;
}
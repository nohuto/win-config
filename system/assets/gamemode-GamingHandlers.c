// Hidden C++ exception states: #wind=21
__int64 __fastcall SystemSettings::GamingHandlers::GamingResetGameConfigStore::Invoke(
        SystemSettings::GamingHandlers::GamingResetGameConfigStore *this,
        HWND a2)
{
  __int64 v2; // rbx
  int ActivationFactory; // eax
  int v4; // ebx
  __int64 v5; // rbx
  __int64 (__fastcall *v6)(__int64, int *); // rdi
  int v7; // eax
  __int64 v8; // rdi
  __int64 v9; // rbx
  int v10; // eax
  __int64 v11; // rbx
  int v12; // eax
  int i; // eax
  __int64 v14; // rdi
  __int64 (__fastcall *v15)(__int64, _QWORD, _QWORD); // rbx
  int v16; // eax
  void *v17; // rdx
  unsigned int v18; // r8d
  __int64 (__fastcall ***v19)(_QWORD, GUID *, __int64 *); // rbx
  int v20; // eax
  __int64 v21; // rbx
  __int64 (__fastcall *v22)(__int64, __int64 *); // rdi
  int v23; // eax
  __int64 (__fastcall ***v24)(_QWORD, GUID *, _QWORD *); // rdi
  __int64 (__fastcall *v25)(_QWORD, GUID *, __int64 *); // rbx
  int v26; // eax
  __int64 v27; // rbx
  __int64 (__fastcall *v28)(__int64, __int64, __int64 *); // rdi
  __int64 v29; // rbx
  __int64 (__fastcall *v30)(__int64, __int64, __int64 *); // rdi
  int v31; // eax
  __int64 v32; // rbx
  __int64 (__fastcall *v33)(__int64, HSTRING *); // rdi
  int v34; // eax
  __int64 v35; // rbx
  __int64 (__fastcall *v36)(__int64, HSTRING, __int64 *); // rdi
  int v37; // eax
  int v38; // eax
  __int64 v39; // rbx
  __int64 (__fastcall *v40)(__int64, __int64 *); // rdi
  int v41; // eax
  __int64 v42; // rbx
  __int64 (__fastcall *v43)(__int64, __int64, HSTRING *); // rdi
  int v44; // eax
  HSTRING v45; // rcx
  const unsigned __int16 *StringRawBuffer; // rbx
  const unsigned __int16 *v47; // rdi
  __int64 trivial_2; // rsi
  int v49; // eax
  __int64 v50; // rbx
  __int64 (__fastcall *v51)(__int64, __int64 *); // rdi
  int v52; // eax
  __int64 v53; // r9
  __int64 v54; // rdx
  __int64 v55; // rdx
  __int64 v56; // rdx
  __int64 v57; // rdx
  __int64 v58; // rdx
  int v60[2]; // [rsp+28h] [rbp-E0h] BYREF
  __int64 v61; // [rsp+30h] [rbp-D8h] BYREF
  __int64 v62; // [rsp+38h] [rbp-D0h] BYREF
  __int64 v63; // [rsp+40h] [rbp-C8h] BYREF
  __int64 v64; // [rsp+48h] [rbp-C0h] BYREF
  __int64 v65; // [rsp+50h] [rbp-B8h] BYREF
  __int64 v66; // [rsp+58h] [rbp-B0h] BYREF
  __int64 v67; // [rsp+60h] [rbp-A8h] BYREF
  __int64 v68; // [rsp+68h] [rbp-A0h] BYREF
  HSTRING string; // [rsp+70h] [rbp-98h] BYREF
  __int64 v70; // [rsp+78h] [rbp-90h]
  unsigned int v71; // [rsp+80h] [rbp-88h]
  __int64 (__fastcall ***v72)(_QWORD, GUID *, __int64 *); // [rsp+88h] [rbp-80h] BYREF
  HSTRING v73; // [rsp+90h] [rbp-78h] BYREF
  __int64 v74; // [rsp+98h] [rbp-70h] BYREF
  __int64 v75; // [rsp+A0h] [rbp-68h] BYREF
  HSTRING v76; // [rsp+A8h] [rbp-60h] BYREF
  char v77[8]; // [rsp+B0h] [rbp-58h] BYREF
  int v78; // [rsp+B8h] [rbp-50h]
  char v79[8]; // [rsp+C0h] [rbp-48h] BYREF
  UINT32 length[4]; // [rsp+C8h] [rbp-40h] BYREF
  __int64 v81; // [rsp+D8h] [rbp-30h] BYREF
  __int64 v82; // [rsp+E0h] [rbp-28h] BYREF
  _QWORD v83[3]; // [rsp+E8h] [rbp-20h] BYREF
  _QWORD v84[3]; // [rsp+100h] [rbp-8h] BYREF
  HSTRING_HEADER hstringHeader; // [rsp+118h] [rbp+10h] BYREF
  __int64 v86; // [rsp+130h] [rbp+28h]
  wil::details::in1diag3 *retaddr; // [rsp+150h] [rbp+48h]

  v82 = 0LL;
  v86 = 0LL;
  Microsoft::WRL::Wrappers::HStringReference::CreateReference(
    &hstringHeader,
    L"Windows.Gaming.Preview.GamesEnumeration.GameList",
    0x31u,
    0x30u);
  v2 = v86;
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v82);
  ActivationFactory = RoGetActivationFactory(v2, &GUID_2ddd0f6f_9c66_4b05_945c_d6ed78491b8c, &v82);
  v4 = ActivationFactory;
  if ( ActivationFactory < 0 )
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x21,
      (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
      (const char *)(unsigned int)ActivationFactory,
      v60[0]);
LABEL_90:
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v82);
    return (unsigned int)v4;
  }
  *(_QWORD *)v60 = 0LL;
  v5 = v82;
  v6 = *(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v82 + 48LL);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(v60);
  v7 = v6(v5, v60);
  v4 = v7;
  if ( v7 < 0 )
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x24,
      (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
      (const char *)(unsigned int)v7,
      v60[0]);
LABEL_89:
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(v60);
    goto LABEL_90;
  }
  v62 = 0LL;
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v62);
  v8 = *(_QWORD *)v60;
  v4 = wil::details::WaitForCompletion<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry *> *> *>(*(_QWORD *)v60);
  if ( v4 >= 0 )
    v4 = (*(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v8 + 64LL))(v8, &v62);
  if ( v4 < 0 )
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x27,
      (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
      (const char *)(unsigned int)v4,
      v60[0]);
LABEL_88:
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v62);
    goto LABEL_89;
  }
  v64 = 0LL;
  v86 = 0LL;
  Microsoft::WRL::Wrappers::HStringReference::CreateReference(
    &hstringHeader,
    L"Windows.Data.Json.JsonObject",
    0x1Du,
    0x1Cu);
  v9 = v86;
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v64);
  v10 = RoGetActivationFactory(v9, &GUID_2289f159_54de_45d8_abcc_22603fa066a0, &v64);
  v4 = v10;
  if ( v10 < 0 )
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x2B,
      (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
      (const char *)(unsigned int)v10,
      v60[0]);
LABEL_87:
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v64);
    goto LABEL_88;
  }
  v63 = 0LL;
  v86 = 0LL;
  Microsoft::WRL::Wrappers::HStringReference::CreateReference(
    &hstringHeader,
    L"Windows.Foundation.PropertyValue",
    0x21u,
    0x20u);
  v11 = v86;
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v63);
  v12 = RoGetActivationFactory(v11, &GUID_629bdbc8_d932_4ff4_96b9_8d96c5c1e858, &v63);
  v4 = v12;
  if ( v12 < 0 )
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x2F,
      (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
      (const char *)(unsigned int)v12,
      v60[0]);
LABEL_86:
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v63);
    goto LABEL_87;
  }
  v81 = v62;
  v70 = v62;
  v71 = 0;
  v72 = 0LL;
  wil::vector_range<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry *>,wil::err_exception_policy>::end(
    &v81,
    v77);
  for ( i = v71; i != v78; i = ++v71 )
  {
    v14 = v70;
    v15 = *(__int64 (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v70 + 48LL);
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v72);
    v16 = v15(v14, v71, &v72);
    if ( v16 < 0 )
      wil::details::in1diag3::_Throw_Hr(retaddr, v17, v18, (const char *)(unsigned int)v16, v60[0]);
    v65 = 0LL;
    v19 = v72;
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v65);
    v20 = (**v19)(v19, &GUID_d84a8f8b_8749_4a25_90d3_f6c5a427886d, &v65);
    v4 = v20;
    if ( v20 < 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x34,
        (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
        (const char *)(unsigned int)v20,
        v60[0]);
      goto LABEL_85;
    }
    v61 = 0LL;
    v21 = v65;
    v22 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v65 + 104LL);
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v61);
    v23 = v22(v21, &v61);
    v4 = v23;
    if ( v23 < 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x37,
        (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
        (const char *)(unsigned int)v23,
        v60[0]);
      goto LABEL_57;
    }
    if ( v61 )
    {
      v67 = 0LL;
      v24 = v72;
      v25 = (*v72)[9];
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v67);
      v26 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, _QWORD *), __int64 *))v25)(v24, &v67);
      v4 = v26;
      if ( v26 < 0 )
      {
        v58 = 60LL;
        goto LABEL_81;
      }
      LOBYTE(v68) = 0;
      v27 = v67;
      v28 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v67 + 64LL);
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(&hstringHeader, L"KglGameModeDefaults", 0x14u, 0x13u);
      v26 = v28(v27, v86, &v68);
      v4 = v26;
      if ( v26 < 0 )
      {
        v58 = 63LL;
LABEL_81:
        wil::details::in1diag3::Return_Hr(
          retaddr,
          (void *)v58,
          (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
          (const char *)(unsigned int)v26,
          v60[0]);
        goto LABEL_56;
      }
      v66 = 0LL;
      if ( (_BYTE)v68 )
      {
        v75 = 0LL;
        v29 = v67;
        v30 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v67 + 48LL);
        Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v75);
        v86 = 0LL;
        Microsoft::WRL::Wrappers::HStringReference::CreateReference(
          &hstringHeader,
          L"KglGameModeDefaults",
          0x14u,
          0x13u);
        v31 = v30(v29, v86, &v75);
        v4 = v31;
        if ( v31 < 0 )
        {
          wil::details::in1diag3::Return_Hr(
            retaddr,
            (void *)0x46,
            (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
            (const char *)(unsigned int)v31,
            v60[0]);
          goto LABEL_54;
        }
        string = 0LL;
        v32 = v75;
        v33 = *(__int64 (__fastcall **)(__int64, HSTRING *))(*(_QWORD *)v75 + 152LL);
        WindowsDeleteString(0LL);
        string = 0LL;
        v34 = v33(v32, &string);
        v4 = v34;
        if ( v34 < 0 )
        {
          v53 = (unsigned int)v34;
          v54 = 73LL;
LABEL_53:
          wil::details::in1diag3::Return_Hr(
            retaddr,
            (void *)v54,
            (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
            (const char *)v53,
            v60[0]);
          WindowsDeleteString(string);
          string = 0LL;
LABEL_54:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v75);
          goto LABEL_55;
        }
        v35 = v64;
        v36 = *(__int64 (__fastcall **)(__int64, HSTRING, __int64 *))(*(_QWORD *)v64 + 48LL);
        Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v66);
        v37 = v36(v35, string, &v66);
        v4 = v37;
        if ( v37 < 0 )
        {
          v53 = (unsigned int)v37;
          v54 = 74LL;
          goto LABEL_53;
        }
        if ( !v66 )
        {
          v4 = -2147467259;
          v53 = 2147500037LL;
          v54 = 75LL;
          goto LABEL_53;
        }
        WindowsDeleteString(string);
        string = 0LL;
        Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v75);
      }
      v84[0] = &v66;
      v84[1] = &v63;
      v84[2] = &v61;
      v83[0] = &v66;
      v83[1] = &v63;
      v83[2] = &v61;
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(&hstringHeader, L"AutoGameModeEnabled", 0x14u, 0x13u);
      v38 = lambda_97fab3054f830811bdc12beb99033b96_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___unsigned_char__(
              v84,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{56,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 122LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(&hstringHeader, L"MaxCpuCount", 0xCu, 0xBu);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{128,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 123LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"CpuExclusivityMaskLow",
        0x16u,
        0x15u);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{144,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 124LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"CpuExclusivityMaskHigh",
        0x17u,
        0x16u);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{160,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 125LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"AffinitizeToExclusiveCpus",
        0x1Au,
        0x19u);
      v38 = lambda_97fab3054f830811bdc12beb99033b96_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___unsigned_char__(
              v84,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{176,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 126LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"PercentGpuTimeAllocatedToGame",
        0x1Eu,
        0x1Du);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{80,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 127LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"PercentGpuMemoryAllocatedToGame",
        0x20u,
        0x1Fu);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{96,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 128LL;
        goto LABEL_72;
      }
      v86 = 0LL;
      Microsoft::WRL::Wrappers::HStringReference::CreateReference(
        &hstringHeader,
        L"PercentGpuMemoryAllocatedToSystemCompositor",
        0x2Cu,
        0x2Bu);
      v38 = lambda_1c510f307756f2d830b00367adc42856_::operator()_long____cdecl_Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::___Windows::Foundation::IReference_int_____(
              v83,
              &hstringHeader,
               Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration::`vcall'{112,{flat}});
      v4 = v38;
      if ( v38 < 0 )
      {
        v57 = 129LL;
LABEL_72:
        wil::details::in1diag3::Return_Hr(
          retaddr,
          (void *)v57,
          (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
          (const char *)(unsigned int)v38,
          v60[0]);
        goto LABEL_55;
      }
      v74 = 0LL;
      v39 = v61;
      v40 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v61 + 64LL);
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v74);
      v41 = v40(v39, &v74);
      v4 = v41;
      if ( v41 < 0 )
      {
        v56 = 133LL;
        goto LABEL_69;
      }
      v41 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v74 + 120LL))(v74);
      v4 = v41;
      if ( v41 < 0 )
      {
        v56 = 134LL;
LABEL_69:
        wil::details::in1diag3::Return_Hr(
          retaddr,
          (void *)v56,
          (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
          (const char *)(unsigned int)v41,
          v60[0]);
        goto LABEL_63;
      }
      v42 = v66;
      if ( v66 )
      {
        v73 = 0LL;
        v43 = *(__int64 (__fastcall **)(__int64, __int64, HSTRING *))(*(_QWORD *)v66 + 80LL);
        WindowsDeleteString(0LL);
        v73 = 0LL;
        v86 = 0LL;
        Microsoft::WRL::Wrappers::HStringReference::CreateReference(
          &hstringHeader,
          L"RelatedProcessNames",
          0x14u,
          0x13u);
        v44 = v43(v42, v86, &v73);
        v4 = v44;
        if ( ((v44 + 0x80000000) & 0x80000000) == 0 && v44 != -2089484279 )
        {
          wil::details::in1diag3::Return_Hr(
            retaddr,
            (void *)0x8C,
            (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
            (const char *)(unsigned int)v44,
            v60[0]);
LABEL_62:
          WindowsDeleteString(v73);
          v73 = 0LL;
LABEL_63:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v74);
LABEL_55:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v66);
LABEL_56:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v67);
LABEL_57:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v61);
LABEL_85:
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v65);
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(v79);
          Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v72);
          goto LABEL_86;
        }
        if ( v44 < 0 )
        {
LABEL_47:
          v45 = v73;
        }
        else
        {
          v45 = v73;
          if ( v73 )
          {
            length[0] = 0;
            StringRawBuffer = WindowsGetStringRawBuffer(v73, length);
            v47 = &StringRawBuffer[length[0]];
            while ( 1 )
            {
              if ( StringRawBuffer >= v47 )
                goto LABEL_47;
              trivial_2 = _std_find_trivial_2(StringRawBuffer, v47, 59LL);
              v76 = 0LL;
              v49 = Microsoft::WRL::Wrappers::HString::Set(
                      (Microsoft::WRL::Wrappers::HString *)&v76,
                      StringRawBuffer,
                      (trivial_2 - (__int64)StringRawBuffer) >> 1);
              v4 = v49;
              if ( v49 < 0 )
                break;
              v49 = (*(__int64 (__fastcall **)(__int64, HSTRING))(*(_QWORD *)v74 + 104LL))(v74, v76);
              v4 = v49;
              if ( v49 < 0 )
              {
                v55 = 155LL;
LABEL_65:
                wil::details::in1diag3::Return_Hr(
                  retaddr,
                  (void *)v55,
                  (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
                  (const char *)(unsigned int)v49,
                  v60[0]);
                WindowsDeleteString(v76);
                v76 = 0LL;
                goto LABEL_62;
              }
              StringRawBuffer = (const unsigned __int16 *)(trivial_2 + 2);
              WindowsDeleteString(v76);
              v76 = 0LL;
            }
            v55 = 154LL;
            goto LABEL_65;
          }
        }
        WindowsDeleteString(v45);
      }
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v74);
      v81 = 0LL;
      v50 = v61;
      v51 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v61 + 184LL);
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v81);
      v52 = v51(v50, &v81);
      v4 = v52;
      if ( v52 < 0 )
      {
        wil::details::in1diag3::Return_Hr(
          retaddr,
          (void *)0xA3,
          (unsigned int)"pcshell\\shell\\systemsettings\\gaminghandlers\\lib\\gamingresetgameconfigstore.cpp",
          (const char *)(unsigned int)v52,
          v60[0]);
        Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v81);
        goto LABEL_55;
      }
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v81);
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v66);
      Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v67);
    }
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v61);
    Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v65);
  }
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(v79);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v72);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v63);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v64);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v62);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(v60);
  Microsoft::WRL::ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *>>::InternalRelease(&v82);
  return 0LL;
}
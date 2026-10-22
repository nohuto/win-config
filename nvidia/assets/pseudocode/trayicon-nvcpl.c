// Hidden C++ exception states: #wind=37
__int64 __fastcall sub_6420B590(__int64 a1, const char *a2)
{
  int v3; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  __int64 v10; // rdx
  __int64 v11; // rdx
  int v12; // ebx
  __int16 *v13; // rdi
  __int64 v14; // rdx
  __int64 v15; // rdx
  int v16; // ebx
  __int16 *v17; // rdi
  __int64 v18; // rdx
  __int64 v19; // rdx
  int v20; // ebx
  __int64 v21; // rdx
  __int64 v22; // rdx
  int v23; // ebx
  __int16 *v24; // rdi
  __int64 v25; // rdx
  __int64 v26; // rdx
  int v27; // ebx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  __int64 v32; // rdx
  __int64 v33; // rdx
  int v34; // ebx
  __int64 v35; // rdx
  __int64 v36; // rdx
  int v37; // ebx
  __int64 v38; // rdx
  __int64 v39; // rdx
  int v40; // ebx
  __int64 v41; // rdx
  __int64 v42; // rdx
  int v43; // ebx
  __int64 *v44; // [rsp+38h] [rbp-D0h] BYREF
  __int16 v45; // [rsp+40h] [rbp-C8h] BYREF
  __int64 v46; // [rsp+48h] [rbp-C0h] BYREF
  __int16 *v47; // [rsp+50h] [rbp-B8h]
  __int64 v48; // [rsp+58h] [rbp-B0h]
  __int64 v49; // [rsp+60h] [rbp-A8h]
  __int64 v50; // [rsp+68h] [rbp-A0h] BYREF
  __int128 v51; // [rsp+70h] [rbp-98h]
  __int64 v52; // [rsp+80h] [rbp-88h]
  const char *v53; // [rsp+88h] [rbp-80h] BYREF
  void ***v54; // [rsp+90h] [rbp-78h]
  const char *v55; // [rsp+98h] [rbp-70h] BYREF
  const char **v56; // [rsp+A0h] [rbp-68h]
  void **v57; // [rsp+A8h] [rbp-60h] BYREF
  __int16 *v58; // [rsp+B0h] [rbp-58h]
  __int64 *v59; // [rsp+B8h] [rbp-50h]
  _QWORD v60[2]; // [rsp+C0h] [rbp-48h] BYREF
  int v61; // [rsp+D0h] [rbp-38h] BYREF
  _QWORD *v62; // [rsp+D8h] [rbp-30h]
  _WORD v63[8]; // [rsp+E0h] [rbp-28h] BYREF
  __int64 v64; // [rsp+F0h] [rbp-18h]
  __int64 v65; // [rsp+F8h] [rbp-10h]
  __int64 v66; // [rsp+100h] [rbp-8h]
  _WORD v67[8]; // [rsp+108h] [rbp+0h] BYREF
  __int64 v68; // [rsp+118h] [rbp+10h]
  __int64 v69; // [rsp+120h] [rbp+18h]
  _BYTE v70[32]; // [rsp+128h] [rbp+20h] BYREF

  v66 = -2LL;
  v50 = *(_QWORD *)(a1 + 8);
  v51 = *(_OWORD *)(a1 + 16);
  sub_6402C21C(v70, v50, &xmmword_6457D438);
  if ( (unsigned __int8)sub_64072D78() )
  {
    if ( *(int *)(sub_6404B0BC() + 32) >= 5 )
    {
      v59 = (__int64 *)v63;
      v44 = (__int64 *)v67;
      v65 = 7LL;
      v64 = 0LL;
      v63[0] = 0;
      wcslen(L"ShimSystem.cpp");
      std::wstring::assign(v63, (void *)L"ShimSystem.cpp");
      v69 = 7LL;
      v68 = 0LL;
      v67[0] = 0;
      wcslen(L"Nvidia::UXDriver::Shim::ShimSystem::SetSecuredSettings");
      std::wstring::assign(v67, (void *)L"Nvidia::UXDriver::Shim::ShimSystem::SetSecuredSettings");
      v47 = &v45;
      v55 = " type:,";
      v56 = (const char **)&v46;
      v53 = a2;
      v54 = (void ***)&v55;
      v60[0] = " Value:";
      v60[1] = &v53;
      v61 = *((_DWORD *)a2 + 1);
      v62 = v60;
      v57 = &Nvidia::Logging::ChainLoggable<Nvidia::Logging::Chain<unsigned long,Nvidia::Logging::Chain<char const (&)[8],Nvidia::Logging::Chain<enum _NVCPLAPI_ENUM_SECURED_SETTINGS const &,Nvidia::Logging::Chain<char const (&)[8],Nvidia::Logging::Chain<Nvidia::Logging::NullType,Nvidia::Logging::NullType>>>>>>::`vftable';
      v58 = (__int16 *)&v61;
      v5 = sub_6404B0BC();
      sub_6402D9F4(v5, 5, (unsigned int)&v57, (unsigned int)v67, 1290, (__int64)v63);
    }
    v6 = *(_DWORD *)a2;
    if ( *(int *)a2 > 5 )
    {
      v28 = v6 - 6;
      if ( v28 )
      {
        v29 = v28 - 1;
        if ( v29 && (v30 = v29 - 1) != 0 )
        {
          v31 = v30 - 1;
          if ( v31 )
          {
            if ( v31 == 2 )
            {
              v69 = 7LL;
              v68 = 0LL;
              v67[0] = 0;
              wcslen(L"ShowBlockingApps");
              std::wstring::assign(v67, (void *)L"ShowBlockingApps");
              sub_641D7208(v70, 7995393LL, v67);
              LOBYTE(v32) = 1;
              std::wstring::_Tidy(v67, v32, 0LL);
              v69 = 7LL;
              v68 = 0LL;
              v67[0] = 0;
              wcslen(L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
              std::wstring::assign(
                v67,
                (void *)L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
              sub_641D7208(v70, 7995394LL, v67);
              LOBYTE(v33) = 1;
              std::wstring::_Tidy(v67, v33, 0LL);
              v34 = *((_DWORD *)a2 + 1);
              v13 = (__int16 *)operator new(4uLL);
              *(_DWORD *)v13 = v34;
              v47 = v13;
              sub_64273AB0(v70, &v46);
              goto LABEL_15;
            }
            return 0LL;
          }
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"StartOnLogin");
          std::wstring::assign(v67, (void *)L"StartOnLogin");
          sub_641D7208(v70, 7995393LL, v67);
          LOBYTE(v35) = 1;
          std::wstring::_Tidy(v67, v35, 0LL);
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"SOFTWARE\\NVIDIA Corporation\\NvTray");
          std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\NvTray");
          sub_641D7208(v70, 7995394LL, v67);
          LOBYTE(v36) = 1;
          std::wstring::_Tidy(v67, v36, 0LL);
          v37 = *((_DWORD *)a2 + 1);
          v24 = (__int16 *)operator new(4uLL);
          *(_DWORD *)v24 = v37;
          v47 = v24;
          sub_64273AB0(v70, &v46);
        }
        else
        {
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"ShowTrayIcon");
          std::wstring::assign(v67, (void *)L"ShowTrayIcon");
          sub_641D7208(v70, 7995393LL, v67);
          LOBYTE(v38) = 1;
          std::wstring::_Tidy(v67, v38, 0LL);
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"SOFTWARE\\NVIDIA Corporation\\Global\\CoProcManager");
          std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\Global\\CoProcManager");
          sub_641D7208(v70, 7995394LL, v67);
          LOBYTE(v39) = 1;
          std::wstring::_Tidy(v67, v39, 0LL);
          v40 = *((_DWORD *)a2 + 1);
          v24 = (__int16 *)operator new(4uLL);
          *(_DWORD *)v24 = v40;
          v47 = v24;
          sub_64273AB0(v70, &v46);
        }
      }
      else
      {
        v69 = 7LL;
        v68 = 0LL;
        v67[0] = 0;
        wcslen(L"ShowContextMenu");
        std::wstring::assign(v67, (void *)L"ShowContextMenu");
        sub_641D7208(v70, 7995393LL, v67);
        LOBYTE(v41) = 1;
        std::wstring::_Tidy(v67, v41, 0LL);
        v69 = 7LL;
        v68 = 0LL;
        v67[0] = 0;
        wcslen(L"SOFTWARE\\NVIDIA Corporation\\Global\\RunOpenGLOn");
        std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\Global\\RunOpenGLOn");
        sub_641D7208(v70, 7995394LL, v67);
        LOBYTE(v42) = 1;
        std::wstring::_Tidy(v67, v42, 0LL);
        v43 = *((_DWORD *)a2 + 1);
        v24 = (__int16 *)operator new(4uLL);
        *(_DWORD *)v24 = v43;
        v47 = v24;
        sub_64273AB0(v70, &v46);
      }
    }
    else
    {
      if ( v6 != 5 )
      {
        if ( !v6 )
        {
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"ContextUIPolicy");
          std::wstring::assign(v67, (void *)L"ContextUIPolicy");
          sub_641D7208(v70, 7995393LL, v67);
          LOBYTE(v25) = 1;
          std::wstring::_Tidy(v67, v25, 0LL);
          v69 = 7LL;
          v68 = 0LL;
          v67[0] = 0;
          wcslen(L"SOFTWARE\\NVIDIA Corporation\\Global\\NvCplApi\\Policies");
          std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\Global\\NvCplApi\\Policies");
          sub_641D7208(v70, 7995394LL, v67);
          LOBYTE(v26) = 1;
          std::wstring::_Tidy(v67, v26, 0LL);
          v27 = *((_DWORD *)a2 + 1);
          v24 = (__int16 *)operator new(4uLL);
          *(_DWORD *)v24 = v27;
          v47 = v24;
          sub_64273AB0(v70, &v46);
          goto LABEL_31;
        }
        v7 = v6 - 1;
        if ( v7 )
        {
          v8 = v7 - 1;
          if ( !v8 )
          {
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"MuxChangeNotif");
            std::wstring::assign(v67, (void *)L"MuxChangeNotif");
            sub_641D7208(v70, 7995393LL, v67);
            LOBYTE(v18) = 1;
            std::wstring::_Tidy(v67, v18, 0LL);
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
            std::wstring::assign(
              v67,
              (void *)L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
            sub_641D7208(v70, 7995394LL, v67);
            LOBYTE(v19) = 1;
            std::wstring::_Tidy(v67, v19, 0LL);
            v20 = *((_DWORD *)a2 + 1);
            v13 = (__int16 *)operator new(4uLL);
            *(_DWORD *)v13 = v20;
            v47 = v13;
            sub_64273AB0(v70, &v46);
            goto LABEL_15;
          }
          v9 = v8 - 1;
          if ( !v9 )
          {
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"OptInOrOutPreference");
            std::wstring::assign(v67, (void *)L"OptInOrOutPreference");
            sub_641D7208(v70, 7995393LL, v67);
            LOBYTE(v14) = 1;
            std::wstring::_Tidy(v67, v14, 0LL);
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"SOFTWARE\\NVIDIA Corporation\\NVControlPanel2\\Client");
            std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\NVControlPanel2\\Client");
            sub_641D7208(v70, 7995394LL, v67);
            LOBYTE(v15) = 1;
            std::wstring::_Tidy(v67, v15, 0LL);
            v16 = *((_DWORD *)a2 + 1);
            v17 = (__int16 *)operator new(4uLL);
            *(_DWORD *)v17 = v16;
            v47 = v17;
            sub_64273AB0(v70, &v46);
            j_j_free(v17);
            LODWORD(v44) = 2;
            goto LABEL_32;
          }
          if ( v9 == 1 )
          {
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"MuxTrayIcon");
            std::wstring::assign(v67, (void *)L"MuxTrayIcon");
            sub_641D7208(v70, 7995393LL, v67);
            LOBYTE(v10) = 1;
            std::wstring::_Tidy(v67, v10, 0LL);
            v69 = 7LL;
            v68 = 0LL;
            v67[0] = 0;
            wcslen(L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
            std::wstring::assign(
              v67,
              (void *)L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NvHybrid\\Persistence\\ACE");
            sub_641D7208(v70, 7995394LL, v67);
            LOBYTE(v11) = 1;
            std::wstring::_Tidy(v67, v11, 0LL);
            v12 = *((_DWORD *)a2 + 1);
            v13 = (__int16 *)operator new(4uLL);
            *(_DWORD *)v13 = v12;
            v47 = v13;
            sub_64273AB0(v70, &v46);
LABEL_15:
            j_j_free(v13);
            LODWORD(v44) = 0;
LABEL_32:
            sub_64273B00(v70, &v44);
            sub_641CFA38(&v50, v70);
          }
          return 0LL;
        }
      }
      v69 = 7LL;
      v68 = 0LL;
      v67[0] = 0;
      wcslen(L"ShowContextMenu");
      std::wstring::assign(v67, (void *)L"ShowContextMenu");
      sub_641D7208(v70, 7995393LL, v67);
      LOBYTE(v21) = 1;
      std::wstring::_Tidy(v67, v21, 0LL);
      v69 = 7LL;
      v68 = 0LL;
      v67[0] = 0;
      wcslen(L"SOFTWARE\\NVIDIA Corporation\\Global\\CoProcManager");
      std::wstring::assign(v67, (void *)L"SOFTWARE\\NVIDIA Corporation\\Global\\CoProcManager");
      sub_641D7208(v70, 7995394LL, v67);
      LOBYTE(v22) = 1;
      std::wstring::_Tidy(v67, v22, 0LL);
      v23 = *((_DWORD *)a2 + 1);
      v24 = (__int16 *)operator new(4uLL);
      *(_DWORD *)v24 = v23;
      v47 = v24;
      sub_64273AB0(v70, &v46);
    }
LABEL_31:
    j_j_free(v24);
    LODWORD(v44) = 1;
    goto LABEL_32;
  }
  if ( *(int *)(sub_6404B0BC() + 32) >= 5 )
  {
    v44 = &v50;
    v59 = &v46;
    v52 = 7LL;
    *((_QWORD *)&v51 + 1) = 0LL;
    LOWORD(v50) = 0;
    wcslen(L"ShimSystem.cpp");
    std::wstring::assign(&v50, (void *)L"ShimSystem.cpp");
    v49 = 7LL;
    v48 = 0LL;
    LOWORD(v46) = 0;
    wcslen(L"Nvidia::UXDriver::Shim::ShimSystem::SetSecuredSettings");
    std::wstring::assign(&v46, (void *)L"Nvidia::UXDriver::Shim::ShimSystem::SetSecuredSettings");
    v58 = &v45;
    v53 = " GR1632 NOT enabled.";
    v54 = &v57;
    v55 = (const char *)&Nvidia::Logging::ChainLoggable<Nvidia::Logging::Chain<char const (&)[21],Nvidia::Logging::Chain<Nvidia::Logging::NullType,Nvidia::Logging::NullType>>>::`vftable';
    v56 = &v53;
    v3 = sub_6404B0BC();
    sub_6402D9F4(v3, 5, (unsigned int)&v55, (unsigned int)&v46, 1287, (__int64)&v50);
  }
  return 8LL;
}
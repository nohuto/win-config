// Hidden C++ exception states: #wind=1
__int64 __fastcall GetThemeFromUnattendSetup(unsigned __int16 *a1)
{
  int ValueW; // ebx
  __int16 v3; // ax
  bool v4; // sf
  LSTATUS v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // r8d
  LSTATUS v8; // eax
  bool v9; // sf
  LSTATUS v10; // eax
  unsigned int v11; // r9d
  bool v12; // sf
  unsigned int v13; // r9d
  unsigned int v14; // r9d
  __int64 v15; // rdx
  __int64 (__fastcall *v16)(struct ITheme *, GUID *, _QWORD *); // rbx
  int v17; // eax
  int pdwType; // [rsp+20h] [rbp-E0h]
  DWORD pcbData; // [rsp+40h] [rbp-C0h] BYREF
  struct ITheme *v21; // [rsp+48h] [rbp-B8h] BYREF
  _QWORD v22[2]; // [rsp+50h] [rbp-B0h] BYREF
  WCHAR pszPath[264]; // [rsp+60h] [rbp-A0h] BYREF
  WCHAR NewFileName[264]; // [rsp+270h] [rbp+170h] BYREF
  WCHAR pszString[520]; // [rsp+480h] [rbp+380h] BYREF
  _WORD pvData[520]; // [rsp+890h] [rbp+790h] BYREF
  wil::details::in1diag3 *retaddr; // [rsp+CD8h] [rbp+BD8h]

  if ( !PathFileExistsW(a1) )
    return (unsigned int)-2147024809;
  pcbData = 1040;
  ValueW = RegGetValueW(
             HKEY_LOCAL_MACHINE,
             L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
             L"ThemeName",
             2u,
             0LL,
             pvData,
             &pcbData);
  if ( ValueW )
  {
    v3 = 0;
    pvData[0] = 0;
    v4 = ValueW < 0;
    if ( ValueW <= 0 )
      goto LABEL_8;
    ValueW = (unsigned __int16)ValueW | 0x80070000;
  }
  else
  {
    v3 = pvData[0];
  }
  v4 = ValueW < 0;
LABEL_8:
  if ( !v4 )
  {
    if ( !v3 )
      ValueW = -2147467259;
    if ( ValueW >= 0 )
    {
      pcbData = 520;
      v5 = RegGetValueW(
             HKEY_LOCAL_MACHINE,
             L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
             L"DesktopBackground",
             2u,
             0LL,
             pszPath,
             &pcbData);
      ValueW = v5;
      if ( v5 )
      {
        pszPath[0] = 0;
        if ( v5 > 0 )
          ValueW = (unsigned __int16)v5 | 0x80070000;
      }
      if ( ValueW >= 0 )
      {
        ValueW = ExpandResourceDir(pszPath, v6);
        if ( ValueW >= 0 )
        {
          if ( PathFileExistsW(pszPath) || (ValueW = ResultFromKnownLastError(), ValueW >= 0) )
          {
            ValueW = GetOEMThemeFileName(1, NewFileName, v7);
            if ( ValueW >= 0 )
            {
              if ( CopyFileW(a1, NewFileName, 0) || (ValueW = ResultFromKnownLastError(), ValueW >= 0) )
              {
                v21 = 0LL;
                ValueW = CThemeFile_CreateInstance(NewFileName, &v21);
                if ( ValueW >= 0 )
                {
                  ValueW = (*(__int64 (__fastcall **)(struct ITheme *, _WORD *))(*(_QWORD *)v21 + 32LL))(v21, pvData);
                  if ( ValueW >= 0 )
                  {
                    ValueW = (*(__int64 (__fastcall **)(struct ITheme *, WCHAR *))(*(_QWORD *)v21 + 176LL))(
                               v21,
                               pszPath);
                    if ( ValueW >= 0 )
                    {
                      pcbData = 1040;
                      v8 = RegGetValueW(
                             HKEY_LOCAL_MACHINE,
                             L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                             L"BrandIcon",
                             2u,
                             0LL,
                             pszString,
                             &pcbData);
                      v9 = v8 < 0;
                      if ( v8 )
                      {
                        pszString[0] = 0;
                        if ( v8 > 0 )
                          v9 = 1;
                      }
                      if ( !v9 )
                        (*(void (__fastcall **)(struct ITheme *, WCHAR *))(*(_QWORD *)v21 + 544LL))(v21, pszString);
                      pcbData = 1040;
                      v10 = RegGetValueW(
                              HKEY_LOCAL_MACHINE,
                              L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                              L"WindowColor",
                              2u,
                              0LL,
                              pszString,
                              &pcbData);
                      v12 = v10 < 0;
                      if ( v10 )
                      {
                        pszString[0] = 0;
                        if ( v10 > 0 )
                          v12 = 1;
                      }
                      if ( !v12 )
                      {
                        pcbData = 0;
                        if ( (CanonicalGlassColorToDWORD(pszString, &pcbData)
                           || StrToIntExW(pszString, 1, (int *)&pcbData))
                          && (*(int (__fastcall **)(struct ITheme *, _QWORD))(*(_QWORD *)v21 + 112LL))(v21, pcbData) >= 0 )
                        {
                          (*(void (__fastcall **)(struct ITheme *, _QWORD))(*(_QWORD *)v21 + 424LL))(v21, 0LL);
                        }
                      }
                      pcbData = 0;
                      if ( (int)SHRegGetBOOLWithREGSAM(
                                  HKEY_LOCAL_MACHINE,
                                  L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Authentication\\LogonUI\\Background",
                                  L"OEMBackground",
                                  v11,
                                  (int *)&pcbData) >= 0
                        && pcbData )
                      {
                        (*(void (__fastcall **)(struct ITheme *))(*(_QWORD *)v21 + 400LL))(v21);
                      }
                      pcbData = 0;
                      if ( (int)SHRegGetBOOLWithREGSAM(
                                  HKEY_LOCAL_MACHINE,
                                  L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                                  L"UWPAppsUseLightTheme",
                                  v13,
                                  (int *)&pcbData) >= 0 )
                        (*(void (__fastcall **)(struct ITheme *, _QWORD))(*(_QWORD *)v21 + 144LL))(v21, pcbData);
                      wil::details::FeatureImpl<__WilFeatureTraits_Feature_SystemLightTheme>::__private_IsEnabledPreCheck(&`wil::Feature<__WilFeatureTraits_Feature_SystemLightTheme>::GetImpl'::`2'::impl);
                      if ( (int)SHRegGetBOOLWithREGSAM(
                                  HKEY_LOCAL_MACHINE,
                                  L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                                  L"SystemUsesLightTheme",
                                  v14,
                                  (int *)&pcbData) >= 0 )
                        (*(void (__fastcall **)(struct ITheme *, _QWORD))(*(_QWORD *)v21 + 160LL))(v21, pcbData);
                      LOBYTE(v15) = 1;
                      wil::details::FeatureImpl<__WilFeatureTraits_Feature_DesktopSpotlightThemeIntegration>::ReportUsage(
                        &`wil::Feature<__WilFeatureTraits_Feature_DesktopSpotlightThemeIntegration>::GetImpl'::`2'::impl,
                        v15);
                      if ( IsDesktopSpotlightAllowedByPolicy() )
                      {
                        pcbData = 0;
                        if ( (int)SHRegGetDWORD(
                                    HKEY_LOCAL_MACHINE,
                                    L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                                    L"WindowsSpotlight",
                                    &pcbData) >= 0 )
                        {
                          v22[0] = 0LL;
                          v16 = **(__int64 (__fastcall ***)(struct ITheme *, GUID *, _QWORD *))v21;
                          Microsoft::WRL::ComPtr<IUnknown>::InternalRelease(v22);
                          v17 = v16(v21, &GUID_6a0522b4_8e09_4aa8_985a_9e52d534977a, v22);
                          if ( v17 >= 0 )
                            (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)v22[0] + 24LL))(v22[0], pcbData);
                          else
                            wil::details::in1diag3::_Log_Hr(
                              retaddr,
                              (void *)0x421,
                              (unsigned int)"shell\\themes\\themeui\\dllreg.cpp",
                              (const char *)(unsigned int)v17,
                              pdwType);
                          Microsoft::WRL::ComPtr<IUnknown>::InternalRelease(v22);
                        }
                      }
                      ValueW = StringCchCopyW(a1, 0x104uLL, NewFileName);
                    }
                  }
                  (*(void (__fastcall **)(struct ITheme *))(*(_QWORD *)v21 + 16LL))(v21);
                }
              }
            }
          }
        }
      }
    }
  }
  return (unsigned int)ValueW;
}

bool ShouldSystemUseDarkMode()
{
  int v0; // ebx
  LSTATUS ValueW; // eax
  signed int v2; // ecx
  bool v3; // zf
  bool v4; // bl
  unsigned int v6; // r9d
  HKEY phkResult; // [rsp+40h] [rbp-18h] BYREF
  unsigned int pvData; // [rsp+70h] [rbp+18h] BYREF
  int v9; // [rsp+78h] [rbp+20h] BYREF
  DWORD pdwType; // [rsp+80h] [rbp+28h] BYREF
  DWORD pcbData; // [rsp+88h] [rbp+30h] BYREF

  v0 = 0;
  phkResult = 0LL;
  v9 = 0;
  RegOpenCurrentUser(0x20019u, &phkResult);
  pdwType = 0;
  pcbData = 4;
  ValueW = RegGetValueW(
             phkResult,
             L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
             L"SystemUsesLightTheme",
             0x10000012u,
             &pdwType,
             &pvData,
             &pcbData);
  v2 = ValueW;
  if ( ValueW )
  {
    if ( ValueW == 234 )
    {
      LOWORD(v2) = 13;
    }
    else if ( ValueW <= 0 )
    {
      goto LABEL_8;
    }
  }
  else
  {
    LOWORD(v2) = 13;
    if ( pdwType == 4 )
    {
      v3 = pvData == 1;
      if ( pvData <= 1 )
      {
LABEL_4:
        LOBYTE(v0) = v3;
        v2 = 0;
        v9 = v0;
        goto LABEL_8;
      }
    }
    else if ( pcbData == 4 && (unsigned __int16)(pvData - 48) <= 1u )
    {
      v3 = (_WORD)pvData == 49;
      goto LABEL_4;
    }
  }
  v2 = (unsigned __int16)v2 | 0x80070000;
LABEL_8:
  if ( v2 < 0 )
  {
    wil::details::FeatureImpl<__WilFeatureTraits_Feature_Servicing_ExplorerIntDarkMode_31144776>::ReportUsage(&`wil::Feature<__WilFeatureTraits_Feature_Servicing_ExplorerIntDarkMode_31144776>::GetImpl'::`2'::impl);
    if ( (int)SHRegGetBOOLWithREGSAM(
                HKEY_LOCAL_MACHINE,
                L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                L"SystemUsesLightTheme",
                v6,
                &v9) >= 0 )
      v0 = v9;
    else
      v0 = IsOS_OS_PERSONAL();
  }
  v4 = v0 == 0;
  if ( phkResult )
    RegCloseKey(phkResult);
  return v4;
}

// Hidden C++ exception states: #wind=1
bool IsSystemAppModeLight(void)
{
  int v0; // ebx
  LSTATUS ValueW; // eax
  signed int v2; // ecx
  bool v3; // zf
  bool v4; // bl
  unsigned int v6; // r9d
  int BOOLWithREGSAM; // eax
  HKEY phkResult; // [rsp+40h] [rbp-10h] BYREF
  unsigned int pvData; // [rsp+70h] [rbp+20h] BYREF
  int v10; // [rsp+78h] [rbp+28h] BYREF
  DWORD pdwType; // [rsp+80h] [rbp+30h] BYREF
  DWORD pcbData; // [rsp+88h] [rbp+38h] BYREF

  v0 = 0;
  v10 = 0;
  phkResult = 0LL;
  RegOpenCurrentUser(0x20019u, &phkResult);
  pdwType = 0;
  pcbData = 4;
  ValueW = RegGetValueW(
             phkResult,
             L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
             L"AppsUseLightTheme",
             0x10000012u,
             &pdwType,
             &pvData,
             &pcbData);
  v2 = ValueW;
  if ( ValueW )
  {
    if ( ValueW == 234 )
    {
      LOWORD(v2) = 13;
    }
    else if ( ValueW <= 0 )
    {
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  LOWORD(v2) = 13;
  if ( pdwType != 4 )
  {
    if ( pcbData == 4 && (unsigned __int16)(pvData - 48) <= 1u )
    {
      v0 = 0;
      v3 = (_WORD)pvData == 49;
      goto LABEL_5;
    }
LABEL_8:
    v2 = (unsigned __int16)v2 | 0x80070000;
    goto LABEL_9;
  }
  if ( pvData > 1 )
    goto LABEL_8;
  v3 = pvData == 1;
LABEL_5:
  LOBYTE(v0) = v3;
  v10 = v0;
  v2 = 0;
LABEL_9:
  if ( v2 < 0 )
  {
    wil::details::FeatureImpl<__WilFeatureTraits_Feature_Servicing_ExplorerIntDarkMode_31144776>::ReportUsage(&`wil::Feature<__WilFeatureTraits_Feature_Servicing_ExplorerIntDarkMode_31144776>::GetImpl'::`2'::impl);
    BOOLWithREGSAM = SHRegGetBOOLWithREGSAM(
                       HKEY_LOCAL_MACHINE,
                       L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes",
                       L"UWPAppsUseLightTheme",
                       v6,
                       &v10);
    v0 = v10;
    if ( BOOLWithREGSAM < 0 )
      v0 = 1;
  }
  v4 = v0 != 0;
  if ( phkResult )
    RegCloseKey(phkResult);
  return v4;
}
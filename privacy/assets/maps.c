__int64 __fastcall SystemSettings::DataModel::CMapsOrchModel::GetPageDisabledByPolicy(
        SystemSettings::DataModel::CMapsOrchModel *this,
        bool *a2)
{
  unsigned int v2; // ebx
  LSTATUS ValueW; // eax
  int v6; // [rsp+50h] [rbp+8h] BYREF
  int v7; // [rsp+54h] [rbp+Ch]
  DWORD v8; // [rsp+58h] [rbp+10h] BYREF

  v7 = HIDWORD(this);
  v2 = 0;
  *a2 = 1;
  v6 = 0;
  v8 = 4;
  ValueW = RegGetValueW(
             HKEY_LOCAL_MACHINE,
             L"Software\\Policies\\Microsoft\\Windows\\Maps",
             L"AllowUntriggeredNetworkTrafficOnSettingsPage",
             0x10u,
             0LL,
             &v6,
             &v8);
  if ( ValueW )
  {
    if ( ValueW == 2 )
    {
      *a2 = 0;
    }
    else if ( ValueW > 0 )
    {
      return (unsigned __int16)ValueW | 0x80070000;
    }
    else
    {
      return (unsigned int)ValueW;
    }
  }
  else
  {
    *a2 = v6 == 0;
  }
  return v2;
}


__int64 __fastcall SystemSettings::DataModel::CMapsOrchModel::GetDownloadOnlyOnWifiPolicy(
        SystemSettings::DataModel::CMapsOrchModel *this,
        enum SystemSettings::DataModel::TertiaryPolicy *a2)
{
  int PolicyInt; // eax
  unsigned int v4; // edi
  int v5; // ecx
  int v7; // [rsp+20h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+28h] [rbp+0h]
  int v9; // [rsp+30h] [rbp+8h] BYREF
  int v10; // [rsp+34h] [rbp+Ch]

  v10 = HIDWORD(this);
  *(_DWORD *)a2 = -1;
  v9 = 0;
  PolicyInt = PolicyManager_GetPolicyInt(L"Maps", L"AllowOfflineMapsDownloadOverMeteredConnection", &v9);
  v4 = PolicyInt;
  if ( PolicyInt == -2147024769 )
  {
    v5 = 0xFFFF;
  }
  else
  {
    if ( PolicyInt < 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x56F,
        (unsigned int)"onecoreuap\\windows\\maps\\settingshandlers\\lib\\orchestratormodel.cpp",
        (const char *)(unsigned int)PolicyInt,
        v7);
      return v4;
    }
    v5 = v9;
  }
  if ( v5 )
  {
    if ( v5 == 1 )
      *(_DWORD *)a2 = 0;
    else
      *(_DWORD *)a2 = -1;
  }
  else
  {
    *(_DWORD *)a2 = 1;
  }
  return 0LL;
}

__int64 __fastcall SystemSettings::DataModel::CMapsOrchModel::GetAutoUpdatePolicy(
        SystemSettings::DataModel::CMapsOrchModel *this,
        enum SystemSettings::DataModel::TertiaryPolicy *a2)
{
  int PolicyInt; // eax
  unsigned int v4; // edi
  int v5; // ecx
  int v7; // [rsp+20h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+28h] [rbp+0h]
  int v9; // [rsp+30h] [rbp+8h] BYREF
  int v10; // [rsp+34h] [rbp+Ch]

  v10 = HIDWORD(this);
  *(_DWORD *)a2 = -1;
  v9 = 0;
  PolicyInt = PolicyManager_GetPolicyInt(L"Maps", L"EnableOfflineMapsAutoUpdate", &v9);
  v4 = PolicyInt;
  if ( PolicyInt == -2147024769 )
  {
    v5 = 0xFFFF;
  }
  else
  {
    if ( PolicyInt < 0 )
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0x53D,
        (unsigned int)"onecoreuap\\windows\\maps\\settingshandlers\\lib\\orchestratormodel.cpp",
        (const char *)(unsigned int)PolicyInt,
        v7);
      return v4;
    }
    v5 = v9;
  }
  if ( v5 )
  {
    if ( v5 == 1 )
      *(_DWORD *)a2 = 1;
    else
      *(_DWORD *)a2 = -1;
  }
  else
  {
    *(_DWORD *)a2 = 0;
  }
  return 0LL;
}
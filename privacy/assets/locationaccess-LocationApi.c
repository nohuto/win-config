_BOOL8 __fastcall CRealTimeLocationApiData::IsLocationAPIDisabled(CRealTimeLocationApiData *this)
{
  bool v1; // bl
  unsigned int v2; // r9d
  int v3; // eax
  HKEY v4; // rdi
  unsigned int v6; // [rsp+30h] [rbp-38h] BYREF
  HKEY hKey[3]; // [rsp+38h] [rbp-30h] BYREF
  HKEY v8; // [rsp+50h] [rbp-18h] BYREF

  v1 = 0;
  memset(hKey, 0, sizeof(hKey));
  v6 = 0;
  v8 = 0LL;
  if ( RegOpenKeyExW(
         HKEY_LOCAL_MACHINE,
         L"Software\\Policies\\Microsoft\\Windows\\LocationAndSensors",
         0,
         0x20019u,
         &v8)
    || (v3 = ATL::CRegKey::Close((ATL::CRegKey *)hKey), v4 = v8, hKey[0] = v8, v3)
    || (unsigned int)ATL::CRegKey::QueryDWORDValue((ATL::CRegKey *)hKey, L"DisableLocation", &v6) )
  {
    if ( !(unsigned int)ATL::CRegKey::Open(
                          (ATL::CRegKey *)hKey,
                          HKEY_CURRENT_USER,
                          L"Software\\Policies\\Microsoft\\Windows\\LocationAndSensors",
                          v2)
      && !(unsigned int)ATL::CRegKey::QueryDWORDValue((ATL::CRegKey *)hKey, L"DisableLocation", &v6) )
    {
      v1 = v6 == 1;
    }
    v4 = hKey[0];
  }
  else
  {
    v1 = v6 == 1;
  }
  if ( v4 )
    RegCloseKey(v4);
  return v1;
}

__int64 __fastcall SensorsGroupPolicy::IsScriptingDisabled(
        SensorsGroupPolicy *this,
        __int64 a2,
        __int64 a3,
        unsigned int a4)
{
  unsigned int v4; // ebx
  unsigned int v5; // r9d
  _QWORD v7[4]; // [rsp+20h] [rbp-20h] BYREF
  unsigned int v8; // [rsp+50h] [rbp+10h] BYREF

  v4 = 0;
  memset(v7, 0, 24);
  v8 = 0;
  if ( !(unsigned int)ATL::CRegKey::Open(
                        (ATL::CRegKey *)v7,
                        HKEY_LOCAL_MACHINE,
                        L"Software\\Policies\\Microsoft\\Windows\\LocationAndSensors",
                        a4)
    && !(unsigned int)ATL::CRegKey::QueryDWORDValue((ATL::CRegKey *)v7, L"DisableLocationScripting", &v8)
    || !(unsigned int)ATL::CRegKey::Open(
                        (ATL::CRegKey *)v7,
                        HKEY_CURRENT_USER,
                        L"Software\\Policies\\Microsoft\\Windows\\LocationAndSensors",
                        v5)
    && !(unsigned int)ATL::CRegKey::QueryDWORDValue((ATL::CRegKey *)v7, L"DisableLocationScripting", &v8) )
  {
    LOBYTE(v4) = v8 == 1;
  }
  ATL::CRegKey::Close((ATL::CRegKey *)v7);
  return v4;
}
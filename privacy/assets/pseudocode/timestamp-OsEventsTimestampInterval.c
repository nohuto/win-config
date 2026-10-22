__int64 OsEventsTimestampInterval()
{
  unsigned int v0; // ebx
  unsigned int v1; // edi
  HKEY hKey[2]; // [rsp+30h] [rbp-10h] BYREF
  unsigned int v4; // [rsp+60h] [rbp+20h] BYREF
  DWORD cbData; // [rsp+68h] [rbp+28h] BYREF
  int Data; // [rsp+70h] [rbp+30h] BYREF
  HKEY phkResult; // [rsp+78h] [rbp+38h] BYREF

  v0 = 0;
  v4 = 0;
  Data = 0;
  cbData = 0;
  if ( !(unsigned __int8)NtSetupKey() )
  {
    hKey[0] = 0LL;
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Policies\\Microsoft\\Windows NT\\Reliability", 0, 0x20019u, hKey);
    if ( hKey[0] )
    {
      cbData = 4;
      if ( !RegQueryValueExW(hKey[0], L"TimeStampEnabled", 0LL, 0LL, (LPBYTE)&Data, &cbData) )
      {
        if ( !Data )
        {
LABEL_13:
          tlx::unique_any<tlx::handle_traits<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),0>>::~unique_any<tlx::handle_traits<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),0>>(hKey);
          return v0;
        }
        cbData = 4;
        if ( !RegQueryValueExW(hKey[0], L"TimeStampInterval", 0LL, 0LL, (LPBYTE)&v4, &cbData) && v4 <= 0x15180 )
        {
          v0 = v4;
          goto LABEL_13;
        }
        v4 = 0;
      }
    }
    phkResult = 0LL;
    RegOpenKeyExW(
      HKEY_LOCAL_MACHINE,
      L"Software\\Microsoft\\Windows\\CurrentVersion\\Reliability",
      0,
      0x20019u,
      &phkResult);
    if ( phkResult )
    {
      cbData = 4;
      if ( !RegQueryValueExW(phkResult, L"TimeStampInterval", 0LL, 0LL, (LPBYTE)&v4, &cbData) )
      {
        v4 *= 60;
        v1 = v4;
        tlx::unique_any<tlx::handle_traits<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),0>>::~unique_any<tlx::handle_traits<HKEY__ *,long (*)(HKEY__ *),&long RegCloseKey(HKEY__ *),0>>(&phkResult);
        if ( v1 <= 0x15180 )
          v0 = v1;
        goto LABEL_13;
      }
      if ( phkResult )
        RegCloseKey(phkResult);
    }
    if ( hKey[0] )
      RegCloseKey(hKey[0]);
  }
  return 0LL;
}
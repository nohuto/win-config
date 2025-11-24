bool IsTouchDisabled(void)
{
  bool v0; // bl
  int Data; // [rsp+50h] [rbp+18h] BYREF
  DWORD Type; // [rsp+58h] [rbp+20h] BYREF
  DWORD cbData; // [rsp+60h] [rbp+28h] BYREF
  HKEY hKey; // [rsp+68h] [rbp+30h] BYREF

  v0 = 0;
  hKey = 0LL;
  if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Policies\\Microsoft\\TabletPC", 0, 0x20019u, &hKey) )
  {
    Type = 4;
    Data = 0;
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"TurnOffTouchInput", 0LL, &Type, (LPBYTE)&Data, &cbData) && Type == 4 && cbData == 4 )
      v0 = Data == 1;
    RegCloseKey(hKey);
  }
  return v0;
}
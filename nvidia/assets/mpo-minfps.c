__int64 minfps()
{
  __int64 result; // rax
  int v1; // ecx
  int v2; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0;
  result = GetPersistedRegistryValueW(
             L"DWMSwitches",
             L"Software\\Microsoft\\Windows\\Dwm",
             L"OverlayMinFPS",
             16,
             0,
             &v2,
             4,
             0);
  v1 = 15;
  if ( !(_DWORD)result )
    v1 = v2;
  dword_180419950 = v1;
  return result;
}
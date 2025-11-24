__int64 __fastcall sub_180078B70(_DWORD *a1)
{
  __int64 result; // rax
  char phkResult; // [rsp+20h] [rbp-28h]
  BYTE v4[8]; // [rsp+30h] [rbp-18h] BYREF
  HKEY hKey; // [rsp+38h] [rbp-10h] BYREF
  DWORD cbData; // [rsp+50h] [rbp+8h] BYREF
  int Data; // [rsp+60h] [rbp+18h] BYREF
  int v8; // [rsp+68h] [rbp+20h] BYREF

  if ( RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\NVIDIA Corporation\\Global\\NGXCore", 0, 0x20019u, &hKey) )
  {
    sub_180066120(
      (unsigned int)"C:/dvs/p4/build/sw/devrel/libdev/NGX/snippets/rel_tot/source/frameworks/cubin/ngx_cubin_generic.cpp",
      189,
      (unsigned int)"NGXCubinGeneric::Init",
      (unsigned int)"error: failed to open registry key SOFTWARE\\NVIDIA Corporation\\Global\\NGXCore",
      phkResult);
  }
  else
  {
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"ShowDlssIndicator", 0LL, 0LL, (LPBYTE)&Data, &cbData) )
      a1[82] = Data;
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"ShowDlssWeights", 0LL, 0LL, (LPBYTE)&v8, &cbData) )
      a1[83] = v8;
    cbData = 4;
    if ( !RegQueryValueExW(hKey, L"NgxCubinDisableResourceCache", 0LL, 0LL, v4, &cbData) )
      a1[84] = *(_DWORD *)v4;
    RegCloseKey(hKey);
  }
  result = 0LL;
  if ( a1[82] != 1024 )
    a1[82] = 0;
  return result;
}
__int64 __fastcall sub_18007C6DC(LPCWSTR pszValue, unsigned int a2)
{
  unsigned int pvData; // [rsp+48h] [rbp+10h] BYREF
  DWORD pcbData; // [rsp+50h] [rbp+18h] BYREF

  pvData = a2;
  pcbData = 4;
  if ( SHGetValueW(
         HKEY_LOCAL_MACHINE,
         L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NVTweak",
         pszValue,
         0LL,
         &pvData,
         &pcbData) )
  {
    SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\NVIDIA Corporation\\Global\\NVTweak", pszValue, 0LL, &pvData, &pcbData);
  }
  return pvData;
}
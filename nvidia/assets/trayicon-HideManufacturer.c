__int64 __fastcall sub_643054D0(__int64 a1, int a2)
{
  unsigned int v3; // ebx
  DWORD cbData; // [rsp+30h] [rbp-248h] BYREF
  HKEY hKey; // [rsp+38h] [rbp-240h] BYREF
  DWORD Type[4]; // [rsp+40h] [rbp-238h] BYREF
  WCHAR String1[264]; // [rsp+50h] [rbp-228h] BYREF

  v3 = 0;
  if ( dword_645797AC > *(_DWORD *)(*((_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + (unsigned int)TlsIndex) + 8LL) )
  {
    Init_thread_header(&dword_645797AC);
    if ( dword_645797AC == -1 )
    {
      *(_DWORD *)&Data = a2 != 0;
      Init_thread_footer(&dword_645797AC);
    }
  }
  lstrcpyW(String1, L"SYSTEM\\CurrentControlSet\\Services\\nvlddmkm\\Global\\NVTweak");
  hKey = 0LL;
  if ( !RegOpenKeyExW(HKEY_LOCAL_MACHINE, String1, 0, 1u, &hKey) )
  {
    cbData = 4;
    if ( RegQueryValueExW(hKey, L"HideManufacturerFromMonitorName", 0LL, Type, &Data, &cbData) )
      RegCloseKey(hKey);
  }
  LOBYTE(v3) = *(_DWORD *)&Data == 1;
  return v3;
}
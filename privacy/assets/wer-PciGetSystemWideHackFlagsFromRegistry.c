__int64 PciGetSystemWideHackFlagsFromRegistry()
{
  ULONG ActiveProcessorCount; // ebx
  PVOID v2; // rcx
  __int64 v3; // [rsp+30h] [rbp-50h] BYREF
  PVOID P; // [rsp+38h] [rbp-48h] BYREF
  HANDLE Handle; // [rsp+40h] [rbp-40h]
  _BYTE v6[8]; // [rsp+48h] [rbp-38h] BYREF
  _DWORD v7[2]; // [rsp+50h] [rbp-30h] BYREF
  __int64 v8; // [rsp+58h] [rbp-28h]
  int v9; // [rsp+60h] [rbp-20h]
  int v10; // [rsp+64h] [rbp-1Ch]
  int v11; // [rsp+68h] [rbp-18h]
  int v12; // [rsp+6Ch] [rbp-14h]
  bool v13; // [rsp+70h] [rbp-10h]
  bool v14; // [rsp+71h] [rbp-Fh]

  P = 0LL;
  LODWORD(v3) = 0;
  Handle = 0LL;
  if ( !(unsigned __int8)PciOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet", (__int64)v6) )
    return 3221225473LL;
  if ( (int)PciGetRegistryValue(L"HackFlags", (__int64)&P, (__int64)&v3) >= 0 )
  {
    if ( (_DWORD)v3 == 4 )
      PciSystemWideHackFlags |= *(_DWORD *)P;
    ExFreePoolWithTag(P, 0x42696350u);
    P = 0LL;
  }
  PciSystemWideHackFlags &= ~0x400000u;
  if ( (int)PciGetRegistryValue(L"AsyncStartOverride", (__int64)&P, (__int64)&v3) >= 0 )
  {
    if ( (_DWORD)v3 == 4 && *(_DWORD *)P )
      PciSystemWideHackFlags &= ~0x400000u;
    ExFreePoolWithTag(P, 0x42696350u);
    P = 0LL;
  }
  ActiveProcessorCount = KeQueryActiveProcessorCountEx(0xFFFFu);
  if ( (int)PciGetRegistryValue(L"WHEARecordCount", (__int64)&P, (__int64)&v3) >= 0 )
  {
    v2 = P;
    if ( (_DWORD)v3 == 4 )
    {
      if ( *(_DWORD *)P <= ActiveProcessorCount )
      {
        ActiveProcessorCount = *(_DWORD *)P;
        if ( !*(_DWORD *)P )
        {
          *(_DWORD *)P = 1;
          ActiveProcessorCount = 1;
        }
      }
      else
      {
        *(_DWORD *)P = ActiveProcessorCount;
      }
      PciWHEARecordPreallocationCount = ActiveProcessorCount;
    }
    ExFreePoolWithTag(v2, 0x42696350u);
    P = 0LL;
  }
  WPP_MAIN_CB.DeviceLock.Header.LockNV = 1;
  if ( (int)PciGetRegistryValue(L"eDpcDisabled", (__int64)&P, (__int64)&v3) >= 0 )
  {
    if ( P && (_DWORD)v3 == 4 )
    {
      if ( *(_DWORD *)P )
        WPP_MAIN_CB.DeviceLock.Header.LockNV = 0;
      ExFreePoolWithTag(P, 0x42696350u);
    }
    P = 0LL;
  }
  HIDWORD(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) = 0;
  if ( (int)PciGetRegistryValue(L"eDpcRecovery", (__int64)&P, (__int64)&v3) >= 0 )
  {
    if ( P && (_DWORD)v3 == 4 )
    {
      HIDWORD(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) = *(_DWORD *)P != 0;
      ExFreePoolWithTag(P, 0x42696350u);
    }
    P = 0LL;
  }
  v7[0] = 1733060695;
  v13 = WPP_MAIN_CB.DeviceLock.Header.LockNV != 0;
  v7[1] = 1;
  v8 = 34LL;
  v14 = HIDWORD(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Flink) != 0;
  v10 = -2147483599;
  v9 = 541672272;
  v11 = 2;
  v12 = 2;
  WheaLogInternalEvent(v7);
  LODWORD(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink) = 0;
  PciGeteDpcHotplugSetting();
  BYTE4(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink) = 1;
  if ( (int)PciGetRegistryValue(L"AerMultiErrorDisabled", (__int64)&P, (__int64)&v3) >= 0 && P && (_DWORD)v3 == 4 )
  {
    if ( *(_DWORD *)P )
      BYTE4(WPP_MAIN_CB.Queue.Wcb.DmaWaitEntry.Blink) = 0;
    ExFreePoolWithTag(P, 0x42696350u);
  }
  if ( Handle )
    ZwClose(Handle);
  return 0LL;
}
__int64 __fastcall PtInitializeTelemetry(unsigned int **a1)
{
  unsigned int v1; // esi
  unsigned int *Heap; // rax
  unsigned int *v4; // rbx
  __int64 v5; // rdx
  __int64 i; // rdi
  unsigned int pvData; // [rsp+70h] [rbp+30h] BYREF
  unsigned int v9; // [rsp+78h] [rbp+38h] BYREF
  DWORD pcbData; // [rsp+80h] [rbp+40h] BYREF
  DWORD pdwType; // [rsp+88h] [rbp+48h] BYREF

  v1 = 0;
  pvData = 0;
  v9 = 0;
  pdwType = 0;
  Heap = (unsigned int *)RtlAllocateHeap(NtCurrentPeb()->ProcessHeap, 0, 0x288uLL);
  v4 = Heap;
  if ( Heap )
  {
    memset_0(Heap, 0, 0x288uLL);
    pcbData = 4;
    if ( RegGetValueW(
           HKEY_LOCAL_MACHINE,
           L"SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\TaggedEnergy",
           L"TelemetryMaxApplication",
           0x18u,
           &pdwType,
           &pvData,
           &pcbData)
      || pvData > 0x1F4 )
    {
      pvData = 500;
    }
    pcbData = 4;
    if ( RegGetValueW(
           HKEY_LOCAL_MACHINE,
           L"SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\TaggedEnergy",
           L"TelemetryMaxTagPerApplication",
           0x18u,
           &pdwType,
           &v9,
           &pcbData)
      || (v5 = v9, v9 > 0x64) )
    {
      v5 = 100LL;
      v9 = 100;
    }
    for ( i = 0LL; (unsigned int)i < 0x10; i = (unsigned int)(i + 1) )
    {
      v1 = PtInitializeTagStore(pvData, v5, &v4[8 * i + 2 + 2 * (unsigned int)i]);
      if ( v1 )
      {
        PtUninitializeTelemetry(v4);
        v4 = 0LL;
        goto LABEL_15;
      }
      v5 = v9;
    }
    *v4 = pvData;
    v4[1] = v9;
  }
  else
  {
    v1 = 8;
  }
LABEL_15:
  *a1 = v4;
  return v1;
}

bool PtpIsProcTagEnabled()
{
  int v0; // ecx
  LSTATUS ValueW; // eax
  int v3; // [rsp+50h] [rbp+8h] BYREF
  DWORD v4; // [rsp+58h] [rbp+10h] BYREF
  DWORD v5; // [rsp+60h] [rbp+18h] BYREF

  v3 = 0;
  v5 = 0;
  LOBYTE(v0) = dword_180048FA8;
  if ( (dword_180048FA8 & 1) == 0 )
  {
    v4 = 4;
    ValueW = RegGetValueW(
               HKEY_LOCAL_MACHINE,
               L"SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\TaggedEnergy",
               L"DisableTaggedEnergyLogging",
               0x18u,
               &v5,
               &v3,
               &v4);
    v0 = dword_180048FA8 | 1;
    dword_180048FA8 |= 1u;
    if ( !ValueW && !v3 )
    {
      v0 |= 2u;
      dword_180048FA8 = v0;
    }
  }
  return (v0 & 2) != 0;
}
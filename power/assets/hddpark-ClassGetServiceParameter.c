__int64 __fastcall ClassGetServiceParameter(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v5; // rax
  __int64 v6; // rbx
  PVOID SystemRoutineAddress; // rax
  __int64 result; // rax
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-29h] BYREF
  _QWORD v10[14]; // [rsp+48h] [rbp-19h] BYREF
  unsigned int v11; // [rsp+D0h] [rbp+6Fh] BYREF
  int v12; // [rsp+D4h] [rbp+73h]

  v12 = HIDWORD(a2);
  memset(v10, 0, sizeof(v10));
  v11 = 0;
  v10[2] = L"IdleClassSupported";
  LODWORD(v10[1]) = 292;
  v10[3] = &v11;
  v5 = *(_QWORD *)(a1 + 32);
  LODWORD(v10[4]) = 0x4000000;
  DestinationString = 0LL;
  v6 = *(_QWORD *)(v5 + 8);
  RtlInitUnicodeString(&DestinationString, L"RtlQueryRegistryValuesEx");
  SystemRoutineAddress = MmGetSystemRoutineAddress(&DestinationString);
  if ( !SystemRoutineAddress )
    SystemRoutineAddress = RtlQueryRegistryValues;
  result = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD *, _QWORD, _QWORD))SystemRoutineAddress)(
             0LL,
             v6,
             v10,
             0LL,
             0LL);
  if ( (int)result >= 0 )
  {
    result = v11;
    *a3 = v11;
  }
  return result;
}
void __fastcall MouConfiguration(__int64 a1)
{
  void *v2; // rdi
  int v3; // eax
  __int64 v4; // rdx
  int v5; // r8d
  int v6; // r9d
  int v7; // r9d
  __int64 Pool2; // rax
  HANDLE v9; // rbx
  __int64 (__fastcall *SystemRoutineAddress)(__int64, HANDLE, void *, _QWORD); // rax
  int v11; // eax
  int v12; // ecx
  char v13; // al
  int v14; // ecx
  int v15; // r8d
  int v16; // r9d
  ULONG v17[2]; // [rsp+20h] [rbp-69h]
  HANDLE *p_Handle; // [rsp+20h] [rbp-69h]
  int v19; // [rsp+40h] [rbp-49h] BYREF
  int Lock_high; // [rsp+44h] [rbp-45h] BYREF
  size_t pcchNewDestLength[2]; // [rsp+48h] [rbp-41h] BYREF
  HANDLE Handle; // [rsp+58h] [rbp-31h] BYREF
  __int64 v23[11]; // [rsp+60h] [rbp-29h] BYREF
  _DWORD v24[2]; // [rsp+B8h] [rbp+2Fh] BYREF
  size_t *v25; // [rsp+C0h] [rbp+37h]
  __int64 v26; // [rsp+C8h] [rbp+3Fh]

  *((_DWORD *)&WPP_MAIN_CB.Reserved + 2) = 100;
  Handle = 0LL;
  v2 = 0LL;
  WPP_MAIN_CB.DeviceQueue.Lock = 0x100000000LL;
  if ( (stru_1C000B370.Length & 1) == 0
    && (stru_1C000B370.MaximumLength & 1) == 0
    && stru_1C000B370.Length <= stru_1C000B370.MaximumLength
    && stru_1C000B370.MaximumLength != 0xFFFF
    && (stru_1C000B370.Buffer || !stru_1C000B370.Length && !stru_1C000B370.MaximumLength) )
  {
    pcchNewDestLength[0] = 0LL;
    RtlWideCharArrayCopyStringWorker(
      stru_1C000B370.Buffer,
      (unsigned __int64)stru_1C000B370.MaximumLength >> 1,
      pcchNewDestLength,
      stru_1C000B370.Buffer,
      *(size_t *)v17);
    stru_1C000B370.Length = 2 * LOWORD(pcchNewDestLength[0]);
  }
  p_Handle = &Handle;
  v3 = IoOpenDriverRegistryKey(a1, 0LL, 131097LL, 0LL);
  if ( v3 < 0 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_23;
    v7 = 61;
LABEL_12:
    LOBYTE(v4) = 3;
    WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v4, v5, v7, (_DWORD)p_Handle, v3);
    goto LABEL_21;
  }
  Pool2 = ExAllocatePool2(256LL, 280LL, 1131769677LL);
  v2 = (void *)Pool2;
  if ( !Pool2 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_23;
    LOBYTE(v4) = 2;
    WPP_RECORDER_SF_(WPP_GLOBAL_Control->DeviceExtension, v4, 1LL, 62LL);
    goto LABEL_21;
  }
  *(_DWORD *)(Pool2 + 8) = 288;
  *(_DWORD *)(Pool2 + 32) = 67108868;
  *(_QWORD *)(Pool2 + 16) = L"MouseDataQueueSize";
  *(_DWORD *)(Pool2 + 64) = 288;
  *(_QWORD *)(Pool2 + 24) = &WPP_MAIN_CB.Reserved + 1;
  *(_DWORD *)(Pool2 + 88) = 67108868;
  *(_QWORD *)(Pool2 + 72) = L"MaximumPortsServiced";
  *(_QWORD *)(Pool2 + 80) = (char *)&WPP_MAIN_CB.DeviceQueue.Lock + 4;
  *(_QWORD *)(Pool2 + 128) = L"PointerDeviceBaseName";
  *(_QWORD *)(Pool2 + 136) = &stru_1C000B370;
  *(_QWORD *)(Pool2 + 184) = L"ConnectMultiplePorts";
  *(_QWORD *)(Pool2 + 192) = &WPP_MAIN_CB.DeviceQueue.Lock;
  *(_DWORD *)(Pool2 + 120) = 288;
  *(_DWORD *)(Pool2 + 144) = 16777217;
  *(_DWORD *)(Pool2 + 176) = 288;
  *(_DWORD *)(Pool2 + 200) = 67108868;
  v9 = Handle;
  *(_OWORD *)pcchNewDestLength = 0LL;
  RtlInitUnicodeString((PUNICODE_STRING)pcchNewDestLength, L"RtlQueryRegistryValuesEx");
  SystemRoutineAddress = (__int64 (__fastcall *)(__int64, HANDLE, void *, _QWORD))MmGetSystemRoutineAddress((PUNICODE_STRING)pcchNewDestLength);
  LODWORD(p_Handle) = 0;
  if ( !SystemRoutineAddress )
    SystemRoutineAddress = (__int64 (__fastcall *)(__int64, HANDLE, void *, _QWORD))RtlQueryRegistryValues;
  v3 = SystemRoutineAddress(3221225472LL, v9, v2, 0LL);
  if ( v3 < 0 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_23;
    v7 = 63;
    goto LABEL_12;
  }
LABEL_21:
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    LOBYTE(v4) = 4;
    WPP_RECORDER_SF_S(WPP_GLOBAL_Control->DeviceExtension, v4, 1, 64, (_DWORD)p_Handle, (__int64)stru_1C000B370.Buffer);
  }
LABEL_23:
  v11 = *((_DWORD *)&WPP_MAIN_CB.Reserved + 2);
  if ( !*((_DWORD *)&WPP_MAIN_CB.Reserved + 2) )
  {
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      WPP_RECORDER_SF_D(WPP_GLOBAL_Control->DeviceExtension, v4, v5, v6, (_DWORD)p_Handle, 0);
    v11 = 100;
    goto LABEL_27;
  }
  if ( *((_DWORD *)&WPP_MAIN_CB.Reserved + 2) <= 0xAAAAAAAu )
  {
LABEL_27:
    v12 = 24 * v11;
    goto LABEL_28;
  }
  v12 = 2400;
LABEL_28:
  *((_DWORD *)&WPP_MAIN_CB.Reserved + 2) = v12;
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    WPP_RECORDER_SF_Dd(
      WPP_GLOBAL_Control->DeviceExtension,
      v4,
      v5,
      v6,
      (_DWORD)p_Handle,
      v12,
      SBYTE4(WPP_MAIN_CB.DeviceQueue.Lock));
  v13 = LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) == 0;
  LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) = LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) == 0;
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    LOBYTE(v4) = 4;
    WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v4, v5, 67, (_DWORD)p_Handle, v13);
  }
  if ( (unsigned int)dword_1C000B000 > 5 && (unsigned __int8)tlgKeywordOn() )
  {
    v19 = *((_DWORD *)&WPP_MAIN_CB.Reserved + 2);
    v23[4] = (__int64)&v19;
    Lock_high = HIDWORD(WPP_MAIN_CB.DeviceQueue.Lock);
    v23[6] = (__int64)&Lock_high;
    v23[8] = (__int64)v24;
    v23[10] = (__int64)stru_1C000B370.Buffer;
    v24[0] = stru_1C000B370.Length;
    LODWORD(pcchNewDestLength[0]) = WPP_MAIN_CB.DeviceQueue.Lock;
    v25 = pcchNewDestLength;
    v23[5] = 4LL;
    v23[7] = 4LL;
    v23[9] = 2LL;
    v24[1] = 0;
    v26 = 4LL;
    tlgWriteTransfer_EtwWriteTransfer(v14, (int)&dword_1C000962C, v15, v16, 7u, (__int64)v23);
  }
  if ( v2 )
    ExFreePoolWithTag(v2, 0);
  if ( Handle )
    ZwClose(Handle);
}
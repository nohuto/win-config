void __fastcall KbdConfiguration(__int64 a1, const wchar_t *a2)
{
  void *v2; // rdi
  int v4; // eax
  int v5; // edx
  int v6; // r8d
  int v7; // r9d
  __int64 Pool2; // rax
  HANDLE v9; // rbx
  __int64 (__fastcall *SystemRoutineAddress)(__int64, HANDLE, void *, _QWORD); // rax
  unsigned int v11; // eax
  int v12; // eax
  char v13; // al
  int v14; // ecx
  int v15; // r8d
  int v16; // r9d
  HANDLE *p_Handle; // [rsp+20h] [rbp-89h]
  char v18; // [rsp+28h] [rbp-81h]
  int v19; // [rsp+30h] [rbp-79h] BYREF
  int v20; // [rsp+34h] [rbp-75h] BYREF
  KSPIN_LOCK Lock; // [rsp+38h] [rbp-71h] BYREF
  HANDLE Handle; // [rsp+40h] [rbp-69h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+48h] [rbp-61h] BYREF
  __int64 v24[5]; // [rsp+60h] [rbp-49h] BYREF
  int v25; // [rsp+88h] [rbp-21h]
  int v26; // [rsp+8Ch] [rbp-1Dh]
  int *v27; // [rsp+90h] [rbp-19h]
  int v28; // [rsp+98h] [rbp-11h]
  int v29; // [rsp+9Ch] [rbp-Dh]
  _DWORD *v30; // [rsp+A0h] [rbp-9h]
  int v31; // [rsp+A8h] [rbp-1h]
  int v32; // [rsp+ACh] [rbp+3h]
  PWSTR Buffer; // [rsp+B0h] [rbp+7h]
  _DWORD v34[2]; // [rsp+B8h] [rbp+Fh] BYREF
  KSPIN_LOCK *p_Lock; // [rsp+C0h] [rbp+17h]
  int v36; // [rsp+C8h] [rbp+1Fh]
  int v37; // [rsp+CCh] [rbp+23h]
  char *v38; // [rsp+D0h] [rbp+27h]
  int v39; // [rsp+D8h] [rbp+2Fh]
  int v40; // [rsp+DCh] [rbp+33h]

  Handle = 0LL;
  v2 = 0LL;
  dword_1C000B294 = 100;
  *(_DWORD *)&WPP_MAIN_CB.DeviceQueue.Busy = 1;
  WPP_MAIN_CB.DeviceQueue.Lock = 1LL;
  RtlUnicodeStringCopyString(&::DestinationString, a2);
  p_Handle = &Handle;
  v4 = IoOpenDriverRegistryKey(a1, 0LL, 131097LL, 0LL);
  if ( v4 < 0 )
  {
    if ( v4 == -1073741772 )
      goto LABEL_14;
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_16;
    v7 = 64;
    LOBYTE(v5) = 2;
    goto LABEL_13;
  }
  Pool2 = ExAllocatePool2(256LL, 336LL, 1130652235LL);
  v2 = (void *)Pool2;
  if ( !Pool2 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_16;
    LOBYTE(v5) = 2;
    WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v5, v6, 65, (unsigned int)&Handle, 1);
    goto LABEL_14;
  }
  *(_QWORD *)(Pool2 + 136) = &::DestinationString;
  *(_DWORD *)(Pool2 + 8) = 288;
  *(_DWORD *)(Pool2 + 32) = 67108868;
  *(_QWORD *)(Pool2 + 16) = L"KeyboardDataQueueSize";
  *(_DWORD *)(Pool2 + 64) = 288;
  *(_QWORD *)(Pool2 + 24) = &dword_1C000B294;
  *(_QWORD *)(Pool2 + 72) = L"MaximumPortsServiced";
  *(_QWORD *)(Pool2 + 80) = &WPP_MAIN_CB.DeviceQueue.1;
  *(_QWORD *)(Pool2 + 128) = L"KeyboardDeviceBaseName";
  *(_QWORD *)(Pool2 + 184) = L"ConnectMultiplePorts";
  *(_QWORD *)(Pool2 + 192) = &WPP_MAIN_CB.DeviceQueue.Lock;
  *(_QWORD *)(Pool2 + 240) = L"SendOutputToAllPorts";
  *(_DWORD *)(Pool2 + 88) = 67108868;
  *(_DWORD *)(Pool2 + 120) = 288;
  *(_DWORD *)(Pool2 + 176) = 288;
  *(_DWORD *)(Pool2 + 200) = 67108868;
  *(_DWORD *)(Pool2 + 232) = 288;
  *(_DWORD *)(Pool2 + 256) = 67108868;
  *(_QWORD *)(Pool2 + 248) = (char *)&WPP_MAIN_CB.DeviceQueue.Lock + 4;
  *(_DWORD *)(Pool2 + 144) = 16777217;
  v9 = Handle;
  DestinationString = 0LL;
  RtlInitUnicodeString(&DestinationString, L"RtlQueryRegistryValuesEx");
  SystemRoutineAddress = (__int64 (__fastcall *)(__int64, HANDLE, void *, _QWORD))MmGetSystemRoutineAddress(&DestinationString);
  if ( !SystemRoutineAddress )
    SystemRoutineAddress = (__int64 (__fastcall *)(__int64, HANDLE, void *, _QWORD))RtlQueryRegistryValues;
  LODWORD(p_Handle) = 0;
  v4 = SystemRoutineAddress(3221225472LL, v9, v2, 0LL);
  if ( v4 < 0 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_16;
    v7 = 66;
    LOBYTE(v5) = 3;
LABEL_13:
    WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v5, v6, v7, (_DWORD)p_Handle, v4);
  }
LABEL_14:
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    LOBYTE(v5) = 4;
    WPP_RECORDER_SF_S(
      WPP_GLOBAL_Control->DeviceExtension,
      v5,
      v6,
      67,
      (_DWORD)p_Handle,
      (__int64)::DestinationString.Buffer);
  }
LABEL_16:
  v11 = dword_1C000B294;
  if ( !dword_1C000B294 )
  {
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      WPP_RECORDER_SF_D(
        WPP_GLOBAL_Control->DeviceExtension,
        v5,
        v6,
        dword_1C000B294 + 68,
        (_DWORD)p_Handle,
        dword_1C000B294 & v18);
    v11 = 100;
  }
  if ( v11 <= 0x15555555 )
    v12 = 12 * v11;
  else
    v12 = 1200;
  dword_1C000B294 = v12;
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    WPP_RECORDER_SF_D(WPP_GLOBAL_Control->DeviceExtension, v5, v6, 69, (_DWORD)p_Handle, v12);
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      LOBYTE(v5) = 4;
      WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v5, v6, 70, (_DWORD)p_Handle, WPP_MAIN_CB.DeviceQueue.Busy);
    }
  }
  v13 = LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) == 0;
  LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) = LODWORD(WPP_MAIN_CB.DeviceQueue.Lock) == 0;
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    LOBYTE(v5) = 4;
    WPP_RECORDER_SF_d(WPP_GLOBAL_Control->DeviceExtension, v5, v6, 71, (_DWORD)p_Handle, v13);
  }
  if ( (unsigned int)dword_1C000B000 > 5 && (unsigned __int8)tlgKeywordOn() )
  {
    v26 = 0;
    v29 = 0;
    v32 = 0;
    v34[1] = 0;
    v37 = 0;
    v40 = 0;
    v19 = dword_1C000B294;
    v24[4] = (__int64)&v19;
    v20 = *(_DWORD *)&WPP_MAIN_CB.DeviceQueue.Busy;
    v27 = &v20;
    v30 = v34;
    Buffer = ::DestinationString.Buffer;
    v34[0] = ::DestinationString.Length;
    Lock = WPP_MAIN_CB.DeviceQueue.Lock;
    p_Lock = &Lock;
    v38 = (char *)&Lock + 4;
    v25 = 4;
    v28 = 4;
    v31 = 2;
    v36 = 4;
    v39 = 4;
    tlgWriteTransfer_EtwWriteTransfer(v14, (int)&dword_1C00096DC, v15, v16, 8u, (__int64)v24);
  }
  if ( v2 )
    ExFreePoolWithTag(v2, 0);
  if ( Handle )
    ZwClose(Handle);
}
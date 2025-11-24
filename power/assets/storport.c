__int64 __fastcall sub_1C019B33C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        PDEVICE_OBJECT DeviceObject,
        __int128 *a6,
        unsigned int a7,
        int a8)
{
  __int64 v8; // rsi
  __int128 v11; // xmm0
  int v12; // eax
  int v13; // edx
  __int64 v14; // rax
  __int64 result; // rax
  int v16; // eax
  __int64 v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rcx
  unsigned int v22; // ecx
  char v23; // al
  char v24; // al
  char v25; // al
  char v26; // al
  char v27; // al
  char v28; // al
  char v29; // al
  char v30; // al
  int v31; // eax
  char v32; // al
  char v33; // al
  char v34; // al
  __int64 v35; // rcx
  bool v36; // zf
  __int64 v37; // rax
  int KeyHandle; // [rsp+40h] [rbp-C0h] BYREF
  __int64 p_Uuid; // [rsp+48h] [rbp-B8h] BYREF
  struct _UNICODE_STRING v40; // [rsp+50h] [rbp-B0h] BYREF
  int v41; // [rsp+60h] [rbp-A0h] BYREF
  int v42; // [rsp+64h] [rbp-9Ch] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-98h] BYREF
  int v44; // [rsp+78h] [rbp-88h] BYREF
  int v45; // [rsp+7Ch] [rbp-84h] BYREF
  int v46; // [rsp+80h] [rbp-80h] BYREF
  int v47; // [rsp+84h] [rbp-7Ch] BYREF
  int v48; // [rsp+88h] [rbp-78h] BYREF
  int v49; // [rsp+8Ch] [rbp-74h] BYREF
  int v50; // [rsp+90h] [rbp-70h] BYREF
  int v51; // [rsp+94h] [rbp-6Ch] BYREF
  int v52; // [rsp+98h] [rbp-68h] BYREF
  __int128 v53; // [rsp+A0h] [rbp-60h] BYREF
  _DWORD Dst[4]; // [rsp+B0h] [rbp-50h] BYREF
  __m128i si128; // [rsp+C0h] [rbp-40h]
  int v56; // [rsp+D0h] [rbp-30h]
  int v57; // [rsp+DCh] [rbp-24h]
  UUID Uuid; // [rsp+200h] [rbp+100h] BYREF

  v8 = a1 + 376;
  *(_QWORD *)(a1 + 8) = a2;
  *(_QWORD *)(a1 + 16) = a3;
  *(_QWORD *)(a1 + 32) = DeviceObject;
  *(_QWORD *)(a1 + 24) = a4;
  DestinationString = 0;
  v42 = 0;
  v53 = 0;
  v44 = 0;
  v11 = *a6;
  *(_DWORD *)(a1 + 5712) = -1;
  *(_DWORD *)(a1 + 1992) = a7;
  *(_OWORD *)(a1 + 40) = v11;
  *(_DWORD *)(a1 + 2076) = 1;
  *(_BYTE *)(a1 + 4893) = 1;
  *(_DWORD *)(a1 + 5364) = 0;
  *(_QWORD *)(a1 + 376) = a1;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v49 = 0;
  v50 = 0;
  v41 = 0;
  v52 = 0;
  v48 = 0;
  v40 = 0;
  v51 = 0;
  v12 = sub_1C004A20C(DeviceObject);
  v13 = 0;
  if ( v12 != -1 )
    v13 = v12;
  if ( !v13 )
    *(_BYTE *)(a1 + 104) |= 8u;
  v14 = sub_1C0165008(*(_QWORD *)(a1 + 16));
  *(_QWORD *)(a1 + 608) = v14;
  if ( !v14 )
    return 3221225486LL;
  v16 = *(_DWORD *)(v14 + 4);
  *(_BYTE *)(a1 + 109) |= 4u;
  *(_DWORD *)(a1 + 392) = v16;
  result = sub_1C0165048(v8);
  if ( (int)result >= 0 )
  {
    sub_1C01965BC(*(_QWORD *)(a1 + 16) + 40LL, a7, a1 + 2000);
    v17 = *(_QWORD *)(a1 + 16) + 40LL;
    *(_DWORD *)(a1 + 2072) = 30;
    sub_1C00499D0(v17, a7);
    v18 = *(_QWORD *)(a1 + 16) + 40LL;
    *(_DWORD *)(a1 + 4124) = 0;
    sub_1C019A0D0(v18, a1 + 4124);
    v19 = *(_QWORD *)(a1 + 16) + 40LL;
    *(_QWORD *)(a1 + 4904) = 0;
    sub_1C019A304(v19, a1 + 4904);
    if ( *(_QWORD *)(a1 + 4904) )
      *(_QWORD *)(a1 + 4904) *= 10000LL;
    v20 = *(_QWORD *)(a1 + 16) + 40LL;
    *(_DWORD *)(a1 + 5668) = 0;
    sub_1C019664C(v20);
    v21 = *(_QWORD *)(a1 + 16) + 40LL;
    *(_DWORD *)(a1 + 5672) = 0;
    sub_1C019A1EC(v21);
    RtlInitUnicodeString(&DestinationString, L"StorPort");
    RtlInitUnicodeString(&v40, L"TotalSenseDataBytes");
    p_Uuid = (__int64)&v42;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v22 = v42;
    }
    else
    {
      v22 = 256;
      v42 = 256;
    }
    if ( v22 > 0x12 )
    {
      v23 = v22;
      if ( v22 >= 0xFF )
        v23 = -1;
      *(_BYTE *)(a1 + 4892) = v23;
    }
    else
    {
      *(_BYTE *)(a1 + 4892) = 18;
    }
    RtlInitUnicodeString(&v40, L"EnableIdlePowerManagement");
    *(_BYTE *)(a1 + 104) &= ~0x20u;
    p_Uuid = (__int64)&v44;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v24 = *(_BYTE *)(a1 + 104);
      if ( v44 )
        v25 = v24 | 0x20;
      else
        v25 = v24 & 0xDF;
      *(_BYTE *)(a1 + 104) = v25;
    }
    RtlInitUnicodeString(&v40, L"DisableRuntimePowerManagement");
    *(_BYTE *)(a1 + 107) &= ~0x20u;
    p_Uuid = (__int64)&v45;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v26 = *(_BYTE *)(a1 + 107);
      if ( v45 )
        v27 = v26 | 0x20;
      else
        v27 = v26 & 0xDF;
      *(_BYTE *)(a1 + 107) = v27;
    }
    RtlInitUnicodeString(&v40, L"DisableD3Cold");
    v28 = *(_BYTE *)(a1 + 107) & 0xEF;
    KeyHandle = 4;
    *(_BYTE *)(a1 + 107) = v28 | 8;
    p_Uuid = (__int64)&v46;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v29 = *(_BYTE *)(a1 + 107);
      if ( v46 )
        v30 = v29 & 0xF7;
      else
        v30 = v29 | 8;
      *(_BYTE *)(a1 + 107) = v30;
    }
    RtlInitUnicodeString(&v40, L"IdleTimeoutInMS");
    *(_DWORD *)(a1 + 4976) = 60000;
    p_Uuid = (__int64)&v47;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v31 = v47;
      *(_BYTE *)(a1 + 107) |= 0x80u;
      *(_DWORD *)(a1 + 4976) = v31;
    }
    if ( (unsigned int)sub_1C00575D4() )
    {
      *(_BYTE *)(a1 + 113) &= ~1u;
      RtlInitUnicodeString(&v40, L"DlrmDisable");
      KeyHandle = 4;
      p_Uuid = (__int64)&v48;
      if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
        *(_BYTE *)(a1 + 113) = (v48 != 0) | *(_BYTE *)(a1 + 113) & 0xFE;
    }
    RtlInitUnicodeString(&v40, L"UseDMAv3");
    *(_BYTE *)(a1 + 108) &= ~4u;
    p_Uuid = (__int64)&v49;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
      *(_BYTE *)(a1 + 108) = (v49 != 0 ? 4 : 0) | *(_BYTE *)(a1 + 108) & 0xFB;
    RtlInitUnicodeString(&v40, L"PowerSrbTimeout");
    *(_DWORD *)(a1 + 5608) = *(_DWORD *)(a1 + 4124);
    KeyHandle = 4;
    p_Uuid = (__int64)&v50;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0
      && v50 )
    {
      *(_DWORD *)(a1 + 5608) = v50;
    }
    if ( *(_DWORD *)(a1 + 5608) > 0x6Eu )
      *(_DWORD *)(a1 + 5608) = 110;
    RtlInitUnicodeString(&v40, L"BusSpecificResetTimeout");
    *(_DWORD *)(a1 + 6032) = 5;
    p_Uuid = (__int64)&v41;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0
      && v41 )
    {
      *(_DWORD *)(a1 + 6032) = v41;
    }
    RtlInitUnicodeString(&v40, L"PLDRTimeout");
    *(_DWORD *)(a1 + 6036) = 10;
    p_Uuid = (__int64)&v41;
    v41 = 0;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0
      && v41 )
    {
      *(_DWORD *)(a1 + 6036) = v41;
    }
    RtlInitUnicodeString(&v40, L"DisableNVMeActiveNamespaceIDListCheck");
    *(_BYTE *)(a1 + 111) &= ~0x40u;
    p_Uuid = (__int64)&v51;
    KeyHandle = 4;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
    {
      v32 = *(_BYTE *)(a1 + 111);
      if ( v51 )
        v33 = v32 | 0x40;
      else
        v33 = v32 & 0xBF;
      *(_BYTE *)(a1 + 111) = v33;
    }
    v34 = *(_BYTE *)(a1 + 108) & 0xFE;
    *(_QWORD *)(a1 + 4968) = 0;
    *(_BYTE *)(a1 + 108) = v34 | 0x20;
    memset_0(Dst, 0, 0x148u);
    v35 = *(_QWORD *)(a1 + 16) + 40LL;
    Dst[0] = 255;
    si128 = _mm_load_si128((const __m128i *)&xmmword_1C0143170);
    v57 = 0;
    v56 = -1;
    sub_1C019652C(v35, a7, Dst);
    *(_QWORD *)(a1 + 4288) = si128.m128i_i64[1];
    *(_QWORD *)(a1 + 4296) = si128.m128i_i64[0];
    *(_DWORD *)(a1 + 4272) = v56;
    *(_DWORD *)(a1 + 4280) = v57;
    *(_QWORD *)(a1 + 4304) = 0;
    *(_QWORD *)(a1 + 4312) = 0;
    *(_QWORD *)(a1 + 4320) = 0xFFFFFFFFLL;
    *(_DWORD *)(a1 + 4276) = 6;
    if ( a8 != 127 )
      *(_DWORD *)(a1 + 4276) = a8;
    sub_1C0045D08(a3, &v53);
    *(_QWORD *)(a1 + 4720) = *((_QWORD *)&v53 + 1);
    sub_1C0049248(DeviceObject);
    v36 = dword_1C0155434 == 0;
    *(_DWORD *)(a1 + 4932) = dword_1C0155434;
    v37 = a1 + 6400;
    *(_DWORD *)(a1 + 4928) = -1;
    if ( v36 )
      v37 = 0;
    *(_QWORD *)(a1 + 4936) = v37;
    if ( byte_1C015582D )
      byte_1C0155823 = 1;
    if ( (unsigned __int8)sub_1C0040544(*(PDEVICE_OBJECT *)(a1 + 8)) )
      byte_1C0155823 = *(_DWORD *)(a1 + 5712) != 0;
    if ( dword_1C0155458 == 1 )
    {
      byte_1C0155823 = 1;
    }
    else
    {
      if ( !dword_1C0155458 )
        byte_1C0155823 = 0;
      if ( !byte_1C0155823 )
        goto LABEL_70;
    }
    *(_BYTE *)(a1 + 112) |= 0x40u;
LABEL_70:
    if ( byte_1C015545E && (*(_DWORD *)(*(_QWORD *)(a1 + 608) + 184LL) & 0x20000) != 0 )
      IoRegisterPlugPlayNotification(
        EventCategoryDeviceInterfaceChange,
        1u,
        &qword_1C013A3C0,
        *(PDRIVER_OBJECT *)(a3 + 8),
        sub_1C0167C20,
        0,
        (PVOID *)(a1 + 6200));
    Uuid = 0;
    RtlInitUnicodeString(&v40, L"AdapterGuid");
    p_Uuid = (__int64)&Uuid;
    KeyHandle = 16;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 3, (__int64)&p_Uuid, &KeyHandle) < 0
      && ExUuidCreate(&Uuid) >= 0 )
    {
      sub_1C0198574((_DWORD)DeviceObject, (unsigned int)&DestinationString, (unsigned int)&v40, 3, p_Uuid, 16);
    }
    *(UUID *)(a1 + 5064) = Uuid;
    sub_1C004A178(a1);
    *(_DWORD *)(a1 + 6176) = dword_1C015543C;
    RtlInitUnicodeString(&v40, L"FwActivateTimeoutForController");
    KeyHandle = 4;
    p_Uuid = (__int64)&v52;
    if ( (int)sub_1C01957A0((int)DeviceObject, (int)&DestinationString, (int)&v40, 4, (__int64)&p_Uuid, &KeyHandle) >= 0 )
      *(_DWORD *)(a1 + 6176) = v52;
    KeInitializeDpc((PRKDPC)(*(_QWORD *)(a1 + 8) + 200LL), sub_1C0032250, *(PVOID *)(a1 + 8));
    KeInitializeEvent((PRKEVENT)(a1 + 6104), SynchronizationEvent, 0);
    *(_DWORD *)(a1 + 128) &= ~2u;
    result = 0;
    *(_QWORD *)(a1 + 120) = 0;
  }
  return result;
}
__int64 __fastcall sub_1C0013C60(PDEVICE_OBJECT DeviceObject)
{
  struct _FUNCTIONAL_DEVICE_EXTENSION *DeviceExtension; // rbx
  _DWORD *DriverData; // r15
  char v4; // di
  IRP *v5; // rax
  bool v6; // al
  _DWORD *v7; // rsi
  PDEVICE_OBJECT v8; // rcx
  __int64 v9; // rdx
  bool v10; // al
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+50h] [rbp-9h] BYREF
  __int128 v13; // [rsp+60h] [rbp+7h] BYREF
  __int64 v14; // [rsp+70h] [rbp+17h]
  struct _KEVENT Event; // [rsp+78h] [rbp+1Fh] BYREF
  ULONG ParameterValue; // [rsp+C0h] [rbp+67h] BYREF
  union _LARGE_INTEGER Timeout; // [rsp+C8h] [rbp+6Fh] BYREF

  DeviceExtension = (struct _FUNCTIONAL_DEVICE_EXTENSION *)DeviceObject->DeviceExtension;
  v14 = 0;
  DriverData = DeviceExtension->CommonExtension.DriverData;
  v4 = 1;
  Timeout.QuadPart = 0;
  ParameterValue = 0;
  v13 = 0;
  memset(&Event, 0, sizeof(Event));
  IoStatusBlock = 0;
  KeInitializeEvent(&Event, SynchronizationEvent, 0);
  v5 = IoBuildDeviceIoControlRequest(0x2D0C14u, DeviceObject, 0, 0, &Timeout, 8u, 0, &Event, &IoStatusBlock);
  if ( v5 && IofCallDriver(DeviceObject, v5) == 259 )
    KeWaitForSingleObject(&Event, Executive, 0, 0, 0);
  DeviceExtension->DeviceFlags &= ~1u;
  v6 = (DeviceExtension->DeviceFlags & 1) != 0
    && (DeviceExtension->DeviceFlags & 0x10) == 0
    && (DeviceExtension->ScanForSpecialFlags & 0x80u) == 0;
  v7 = DriverData + 130;
  DeviceExtension->CdbForceUnitAccess = v6;
  DriverData[130] = -1;
  ClassGetDeviceParameter(DeviceExtension, (PWSTR)L"Disk", (PWSTR)L"UserWriteCacheSetting", DriverData + 130);
  if ( DriverData[130] == -1 )
  {
    if ( (DeviceExtension->ScanForSpecialFlags & 0x10) != 0 )
    {
      v8 = ::DeviceObject;
      if ( ::DeviceObject == (PDEVICE_OBJECT)&::DeviceObject
        || (HIDWORD(::DeviceObject->Timer) & 2) == 0
        || BYTE1(::DeviceObject->Timer) < 3u )
      {
        goto LABEL_27;
      }
      v9 = 23;
    }
    else if ( !BYTE6(Timeout.QuadPart) || HIBYTE(Timeout.QuadPart) )
    {
      if ( !BYTE5(Timeout.QuadPart) )
        goto LABEL_28;
      v8 = ::DeviceObject;
      if ( ::DeviceObject == (PDEVICE_OBJECT)&::DeviceObject
        || (HIDWORD(::DeviceObject->Timer) & 2) == 0
        || BYTE1(::DeviceObject->Timer) < 3u )
      {
        goto LABEL_27;
      }
      v9 = 25;
    }
    else
    {
      v8 = ::DeviceObject;
      if ( ::DeviceObject == (PDEVICE_OBJECT)&::DeviceObject
        || (HIDWORD(::DeviceObject->Timer) & 2) == 0
        || BYTE1(::DeviceObject->Timer) < 3u )
      {
        goto LABEL_27;
      }
      v9 = 24;
    }
    sub_1C0003270(v8->AttachedDevice, v9, &unk_1C0008BB0, DeviceObject);
LABEL_27:
    *v7 = 0;
  }
LABEL_28:
  if ( (int)sub_1C0014D10(DeviceExtension, &v13) < 0 )
    goto LABEL_40;
  if ( BYTE2(v13) != 1 )
  {
    if ( DriverData[130] != 1 )
      goto LABEL_40;
    BYTE2(v13) = 1;
    goto LABEL_39;
  }
  DeviceExtension->DeviceFlags |= 1u;
  v10 = (DeviceExtension->DeviceFlags & 1) != 0
     && (DeviceExtension->DeviceFlags & 0x10) == 0
     && (DeviceExtension->ScanForSpecialFlags & 0x80u) == 0;
  DeviceExtension->CdbForceUnitAccess = v10;
  if ( !*v7 )
  {
    BYTE2(v13) = 0;
LABEL_39:
    sub_1C0010ACC(DeviceExtension, &v13);
  }
LABEL_40:
  DeviceExtension->DeviceFlags &= ~0x10u;
  ClassGetDeviceParameter(DeviceExtension, (PWSTR)L"Disk", (PWSTR)L"CacheIsPowerProtected", &ParameterValue);
  if ( ParameterValue == 1 )
    DeviceExtension->DeviceFlags |= 0x10u;
  if ( (DeviceExtension->DeviceFlags & 1) == 0
    || (DeviceExtension->DeviceFlags & 0x10) != 0
    || (DeviceExtension->ScanForSpecialFlags & 0x80u) != 0 )
  {
    v4 = 0;
  }
  DeviceExtension->CdbForceUnitAccess = v4;
  return 0;
}




__int64 __fastcall sub_1C0010390(__int64 a1, __int64 a2)
{
  struct _FUNCTIONAL_DEVICE_EXTENSION *v2; // rbx
  __int64 v4; // rbp
  unsigned int v5; // edi
  __int64 v7; // rax
  bool v8; // zf
  char v9; // cl
  USHORT DeviceFlags; // ax
  USHORT v11; // ax
  ULONG v12; // r9d

  v2 = *(struct _FUNCTIONAL_DEVICE_EXTENSION **)(a1 + 64);
  v4 = *(_QWORD *)(a2 + 184);
  v5 = 0;
  if ( KeGetCurrentIrql() >= 2u )
    return 3221225800LL;
  if ( *(_DWORD *)(v4 + 16) >= 0xCu )
  {
    v7 = *(_QWORD *)(a2 + 24);
    if ( *(_DWORD *)v7 == 12 )
    {
      v8 = *(_BYTE *)(v7 + 8) == 0;
      v9 = 1;
      DeviceFlags = v2->DeviceFlags;
      if ( v8 )
      {
        v12 = 0;
        v11 = DeviceFlags & 0xFFEF;
      }
      else
      {
        v11 = DeviceFlags | 0x10;
        v12 = 1;
      }
      v2->DeviceFlags = v11;
      if ( (v2->DeviceFlags & 1) == 0 || (v2->DeviceFlags & 0x10) != 0 || (v2->ScanForSpecialFlags & 0x80u) != 0 )
        v9 = 0;
      v2->CdbForceUnitAccess = v9;
      ClassSetDeviceParameter(v2, (PWSTR)L"Disk", (PWSTR)L"CacheIsPowerProtected", v12);
    }
    else
    {
      return (unsigned int)-1073741811;
    }
  }
  else
  {
    return (unsigned int)-1073741820;
  }
  return v5;
}




__int64 __fastcall sub_1C0010254(__int64 a1, __int64 a2)
{
  struct _FUNCTIONAL_DEVICE_EXTENSION *v2; // rdi
  __int64 v4; // rbp
  __int64 v6; // r14
  _DWORD *DriverData; // r15
  unsigned int v9; // ebx
  ULONG v10; // r9d

  v2 = *(struct _FUNCTIONAL_DEVICE_EXTENSION **)(a1 + 64);
  v4 = *(_QWORD *)(a2 + 184);
  v6 = *(_QWORD *)(a2 + 24);
  DriverData = v2->CommonExtension.DriverData;
  if ( KeGetCurrentIrql() >= 2u )
    return 3221225800LL;
  if ( DeviceObject != (PDEVICE_OBJECT)&DeviceObject
    && (HIDWORD(DeviceObject->Timer) & 0x10) != 0
    && BYTE1(DeviceObject->Timer) >= 4u )
  {
    sub_1C00043D8(DeviceObject->AttachedDevice, 61, &unk_1C00088D8, a1, a2);
  }
  if ( *(_DWORD *)(v4 + 16) >= 0x18u )
  {
    v9 = sub_1C0010ACC(v2, v6);
    v10 = *(_BYTE *)(v6 + 2) != 0;
    DriverData[130] = v10;
    ClassSetDeviceParameter(v2, (PWSTR)L"Disk", (PWSTR)L"UserWriteCacheSetting", v10);
    sub_1C0010A18(v2, v6, v9);
    return v9;
  }
  else
  {
    if ( DeviceObject != (PDEVICE_OBJECT)&DeviceObject
      && (HIDWORD(DeviceObject->Timer) & 0x10) != 0
      && BYTE1(DeviceObject->Timer) >= 2u )
    {
      sub_1C0004144(DeviceObject->AttachedDevice, 62, &unk_1C00088D8);
    }
    return 3221225476LL;
  }
}
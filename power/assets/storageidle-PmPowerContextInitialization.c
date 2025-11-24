__int64 __fastcall PmPowerContextInitialization(_WORD *a1, int a2)
{
  NTSTATUS v2; // ebx
  int v4; // edx
  int v5; // edx
  const WCHAR *v6; // rdx
  __int64 v7; // rdi
  unsigned int *v8; // rsi
  __int16 v9; // ax
  _WORD *v10; // rdi
  unsigned int v11; // esi
  HANDLE v12; // rcx
  unsigned int v14; // [rsp+20h] [rbp-E0h] BYREF
  HANDLE Handle; // [rsp+28h] [rbp-D8h] BYREF
  void *KeyHandle; // [rsp+30h] [rbp-D0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-C8h] BYREF
  _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+48h] [rbp-B8h] BYREF
  void *v19; // [rsp+78h] [rbp-88h] BYREF
  struct _UNICODE_STRING String; // [rsp+80h] [rbp-80h] BYREF
  unsigned __int16 *v21[10]; // [rsp+90h] [rbp-70h]
  char v22; // [rsp+E0h] [rbp-20h] BYREF

  v19 = 0LL;
  v14 = 0;
  KeyHandle = 0LL;
  v2 = 0;
  Handle = 0LL;
  v21[0] = L"SmallRandomReadPowerMw";
  v21[1] = L"SmallRandomWritePowerMw";
  v21[2] = L"SmallSequentialReadPowerMw";
  v21[3] = L"SmallSequentialWritePowerMw";
  v21[4] = L"LargeRandomReadPowerMw";
  v21[5] = L"LargeRandomWritePowerMw";
  v21[6] = L"LargeSequentialReadPowerMw";
  v21[7] = L"LargeSequentialWritePowerMw";
  v21[8] = L"FlushPowerMw";
  DestinationString = 0LL;
  String = 0LL;
  memset(&ObjectAttributes, 0, sizeof(ObjectAttributes));
  if ( a2 )
  {
    v4 = a2 - 1;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 != 1 )
          return (unsigned int)v2;
        v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\NVME";
      }
      else
      {
        v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\HDD";
      }
    }
    else
    {
      v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\SSD";
    }
  }
  else
  {
    v6 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\SD";
  }
  RtlInitUnicodeString(&DestinationString, v6);
  ObjectAttributes.RootDirectory = 0LL;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  v2 = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
  if ( v2 >= 0 )
  {
    v7 = 0LL;
    v8 = (unsigned int *)(a1 + 84);
    while ( (unsigned int)v7 < 9 )
    {
      v2 = PmQueryDWORDValueKey(KeyHandle, v21[v7], &v14);
      if ( v2 < 0 )
        goto LABEL_28;
      v7 = (unsigned int)(v7 + 1);
      *v8++ = v14;
    }
    v2 = PmQueryDWORDValueKey(KeyHandle, L"IdleStatesNumber", &v14);
    if ( v2 >= 0 )
    {
      v9 = v14;
      *a1 = v14;
      if ( (unsigned __int16)(v9 - 1) > 4u )
      {
        v2 = -1073741811;
      }
      else
      {
        RtlInitUnicodeString(&DestinationString, L"IdleState");
        ObjectAttributes.RootDirectory = KeyHandle;
        ObjectAttributes.Attributes = 576;
        ObjectAttributes.ObjectName = &DestinationString;
        ObjectAttributes.Length = 48;
        *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
        v2 = ZwOpenKey(&v19, 0x20019u, &ObjectAttributes);
        if ( v2 >= 0 )
        {
          v10 = 0LL;
          String.MaximumLength = 28;
          v11 = 0;
          String.Buffer = (PWSTR)&v22;
          while ( v11 < (unsigned __int16)*a1 )
          {
            String.Length = 26;
            v2 = RtlIntegerToUnicodeString(v11 + 1, 0xAu, &String);
            if ( v2 < 0 )
              goto LABEL_28;
            ObjectAttributes.RootDirectory = v19;
            ObjectAttributes.Length = 48;
            ObjectAttributes.ObjectName = &String;
            ObjectAttributes.Attributes = 576;
            *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
            v2 = ZwOpenKey(&Handle, 0x20019u, &ObjectAttributes);
            if ( v2 < 0 )
              goto LABEL_28;
            v10 = &a1[16 * v11 + 4];
            v2 = PmQueryDWORDValueKey(Handle, L"IdleExitLatencyMs", &v14);
            if ( v2 < 0 )
              goto LABEL_28;
            *(_QWORD *)v10 = 10000 * v14;
            v2 = PmQueryDWORDValueKey(Handle, L"IdleExitEnergyMicroJoules", &v14);
            if ( v2 < 0 )
              goto LABEL_28;
            *((_QWORD *)v10 + 1) = 10000 * v14;
            v2 = PmQueryDWORDValueKey(Handle, L"IdleTimeLengthMs", &v14);
            if ( v2 < 0 )
              goto LABEL_28;
            *((_QWORD *)v10 + 2) = 10000 * v14;
            v2 = PmQueryDWORDValueKey(Handle, L"IdlePowerMw", &v14);
            if ( v2 < 0 )
              goto LABEL_28;
            v12 = Handle;
            *((_DWORD *)v10 + 6) = v14;
            ZwClose(v12);
            Handle = 0LL;
            ++v11;
          }
          *((_QWORD *)v10 + 2) = -1LL;
        }
      }
    }
  }
LABEL_28:
  if ( Handle )
    ZwClose(Handle);
  if ( KeyHandle )
    ZwClose(KeyHandle);
  return (unsigned int)v2;
}
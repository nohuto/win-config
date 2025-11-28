int InitTimerCoalescing()
{
  unsigned int v0; // ebx
  int result; // eax
  unsigned int i; // ecx
  unsigned int j; // ecx
  unsigned int k; // ecx
  __int64 m; // rcx
  __int64 UserSessionState; // rax
  __int64 v7; // r9
  __int64 v8; // rax
  char *v9; // r8
  _DWORD *v10; // rdx
  _DWORD *v11; // rcx
  __int64 v12; // rdx
  ULONG ResultLength; // [rsp+30h] [rbp-69h] BYREF
  void *KeyHandle; // [rsp+38h] [rbp-61h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-59h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-49h] BYREF
  _BYTE KeyValueInformation[4]; // [rsp+80h] [rbp-19h] BYREF
  int v18; // [rsp+84h] [rbp-15h]
  int v19; // [rsp+88h] [rbp-11h]
  _DWORD v20[21]; // [rsp+8Ch] [rbp-Dh] BYREF

  v0 = 0;
  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  DestinationString = 0LL;
  KeyHandle = 0LL;
  ResultLength = 0;
  RtlInitUnicodeString(
    &DestinationString,
    L"\\Registry\\Machine\\software\\microsoft\\Windows NT\\CurrentVersion\\Windows");
  ObjectAttributes.Length = 48;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.RootDirectory = 0LL;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  result = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
  if ( result >= 0 )
  {
    RtlInitUnicodeString(&DestinationString, L"TimerCoalescing");
    if ( ZwQueryValueKey(
           KeyHandle,
           &DestinationString,
           KeyValuePartialInformation,
           KeyValueInformation,
           0x60u,
           &ResultLength) >= 0
      && v18 == 3 // REG_BINARY
      && v19 == 80 // size
      && !v20[0] )
    {
      // force zero in reserved range (v20[1..3])
      for ( i = 0; i < 3; ++i )
      {
        if ( v20[i + 1] )
          return ZwClose(KeyHandle);
      }
      // force zero in reserved range (v20[8..11])
      for ( j = 0; j < 4; ++j )
      {
        if ( v20[j + 8] )
          return ZwClose(KeyHandle);
      }
      // force zero in reserved range (v20[16..19])
      for ( k = 0; k < 4; ++k )
      {
        if ( v20[k + 16] )
          return ZwClose(KeyHandle);
      }
      // four dwords for tolerance index 0
      for ( m = 0LL; (unsigned int)m < 4; m = (unsigned int)(m + 1) )
      {
        if ( v20[(unsigned int)m + 4] > 0x7FFFFFF5u )
          return ZwClose(KeyHandle);
      }
      // four dwords for tolerance index 3
      while ( v0 < 4 )
      {
        if ( v20[v0 + 12] > 0x7FFFFFF5u )
          return ZwClose(KeyHandle);
        ++v0;
      }
      // copy dwords into the per session cache
      UserSessionState = W32GetUserSessionState(m, 2147483637LL);
      v7 = 4LL;
      v8 = UserSessionState + 57496;
      v9 = (char *)v20 - v8;
      v10 = (_DWORD *)(v8 + 5220);
      do
      {
        *v10 = *(_DWORD *)((char *)v10 + (_QWORD)v9 - 5204);
        ++v10;
        --v7;
      }
      while ( v7 );
      v11 = (_DWORD *)(v8 + 5204);
      v12 = 4LL;
      do
      {
        *v11 = *(_DWORD *)((char *)v11 + (_QWORD)v9 - 5156);
        ++v11;
        --v12;
      }
      while ( v12 );
      // uses tolerance index 0
      SetTimerCoalescingTolerance(0LL);
    }
    return ZwClose(KeyHandle);
  }
  return result;
}
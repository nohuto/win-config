__int64 IsDesktopHeapLoggingOn(void)
{
  unsigned int v0; // ebx
  int v1; // edi
  void *v2; // rsi
  int v4; // [rsp+30h] [rbp-40h]
  ULONG ResultLength; // [rsp+34h] [rbp-3Ch] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-38h] BYREF
  _BYTE KeyValueInformation[12]; // [rsp+48h] [rbp-28h] BYREF
  int v8; // [rsp+54h] [rbp-1Ch]

  v0 = 0;
  v1 = 0;
  ResultLength = 0;
  DestinationString = 0LL;
  v4 = *(_DWORD *)(W32GetUserSessionState() + 62792);
  while ( 1 )
  {
    v2 = (void *)OpenCacheKeyEx(0LL);
    if ( !v2 )
      break;
    RtlInitUnicodeString(&DestinationString, L"DesktopHeapLogging");
    if ( ZwQueryValueKey(v2, &DestinationString, KeyValuePartialInformation, KeyValueInformation, 0x14u, &ResultLength) >= 0 )
    {
      v1 = v8;
      v4 = 0;
    }
    else
    {
      v1 = v4 != 0 ? v1 : 0;
    }
    ZwClose(v2);
    if ( !v4 )
      goto LABEL_6;
  }
  v1 = 0;
LABEL_6:
  LOBYTE(v0) = v1 != 0;
  return v0;
}
NTSTATUS __fastcall ClassUpdateDynamicRegistrySettings(HANDLE KeyHandle)
{
  NTSTATUS result; // eax
  ULONG ResultLength; // [rsp+30h] [rbp-D0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-C8h] BYREF
  _BYTE KeyValueInformation[4]; // [rsp+50h] [rbp-B0h] BYREF
  int v6; // [rsp+54h] [rbp-ACh]
  int v7; // [rsp+5Ch] [rbp-A4h]

  ResultLength = 0;
  DestinationString = 0LL;
  RtlInitUnicodeString(&DestinationString, L"NVMeDisablePerfThrottling");
  if ( ZwQueryValueKey(
         KeyHandle,
         &DestinationString,
         KeyValuePartialInformation,
         KeyValueInformation,
         0x110u,
         &ResultLength) < 0 )
  {
    ClassNVMeDisablePerfThrottling = 0;
  }
  else if ( v6 == 4 && ResultLength >= 4 )
  {
    ClassNVMeDisablePerfThrottling = v7 != 0;
  }
  RtlInitUnicodeString(&DestinationString, L"ProcessZoneCommandAsync");
  if ( ZwQueryValueKey(
         KeyHandle,
         &DestinationString,
         KeyValuePartialInformation,
         KeyValueInformation,
         0x110u,
         &ResultLength) >= 0
    && v6 == 4
    && ResultLength >= 4 )
  {
    ProcessZoneCommandAsynchronously = v7 != 0;
  }
  RtlInitUnicodeString(&DestinationString, L"DisableOptimalIOAlignment");
  if ( ZwQueryValueKey(
         KeyHandle,
         &DestinationString,
         KeyValuePartialInformation,
         KeyValueInformation,
         0x110u,
         &ResultLength) >= 0
    && v6 == 4
    && ResultLength >= 4 )
  {
    DisableOptimalIOAlignment = v7 != 0;
  }
  RtlInitUnicodeString(&DestinationString, L"DisableForwardedIo");
  result = ZwQueryValueKey(
             KeyHandle,
             &DestinationString,
             KeyValuePartialInformation,
             KeyValueInformation,
             0x110u,
             &ResultLength);
  if ( result < 0 )
  {
    ClassDisableForwardedIo = 0;
  }
  else if ( v6 == 4 && ResultLength >= 4 )
  {
    ClassDisableForwardedIo = v7 != 0;
  }
  return result;
}
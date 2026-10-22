void __fastcall DataCenterBridgingConfiguration::ReadRegistryParameters(DataCenterBridgingConfiguration *this)
{
  if ( dword_14006D8AC < 393246 )
    RegistryKey<unsigned char>::Initialize(
      (DataCenterBridgingConfiguration *)((char *)this + 24),
      *(struct ADAPTER_CONTEXT **)this,
      *((NDIS_HANDLE *)this + 1),
      (PUCHAR)"UseDSCPAsUP",
      0,
      1u,
      1u,
      0,
      0);
  RegistryKey<unsigned char>::Initialize(
    (DataCenterBridgingConfiguration *)((char *)this + 40),
    *(struct ADAPTER_CONTEXT **)this,
    *((NDIS_HANDLE *)this + 1),
    (PUCHAR)"DisableLLDP",
    0,
    1u,
    0,
    0,
    0);
  RegistryKey<unsigned char>::Initialize(
    (DataCenterBridgingConfiguration *)((char *)this + 48),
    *(struct ADAPTER_CONTEXT **)this,
    *((NDIS_HANDLE *)this + 1),
    (PUCHAR)"RegWAErrata70",
    0,
    1u,
    0,
    0,
    0);
  RegistryKey<unsigned char>::Initialize(
    (DataCenterBridgingConfiguration *)((char *)this + 56),
    *(struct ADAPTER_CONTEXT **)this,
    *((NDIS_HANDLE *)this + 1),
    (PUCHAR)"RegAutoDropBlockingPackets",
    0,
    1u,
    1u,
    0,
    0);
}
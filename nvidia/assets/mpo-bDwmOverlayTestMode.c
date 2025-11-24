_BOOL8 bDwmOverlayTestMode(void)
{
  BOOL v0; // ebx
  ULONG ResultLength; // [rsp+30h] [rbp-D0h] BYREF
  void *KeyHandle; // [rsp+38h] [rbp-C8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-C0h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE KeyValueInformation[4]; // [rsp+80h] [rbp-80h] BYREF
  int v7; // [rsp+84h] [rbp-7Ch]

  v0 = 0;
  *(&ObjectAttributes.Length + 1) = 0;
  *(&ObjectAttributes.Attributes + 1) = 0;
  DestinationString = 0LL;
  KeyHandle = 0LL;
  ResultLength = 0;
  RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM");
  ObjectAttributes.Length = 48;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.RootDirectory = 0LL;
  ObjectAttributes.Attributes = 576;
  *(_OWORD *)&ObjectAttributes.SecurityDescriptor = 0LL;
  if ( ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes) >= 0 )
  {
    RtlInitUnicodeString(&DestinationString, L"OverlayTestMode");
    if ( ZwQueryValueKey(
           KeyHandle,
           &DestinationString,
           KeyValuePartialInformation,
           KeyValueInformation,
           0x400u,
           &ResultLength) >= 0 )
      v0 = v7 == 4;
    ZwClose(KeyHandle);
  }
  return v0;
}


// dwmcore.dll
__int64 sub_180226EBC()
{
  unsigned int v0; // eax
  LONGLONG v1; // rcx
  LONGLONG v2; // rdx
  __int64 result; // rax
  int v4; // eax
  unsigned int v5; // [rsp+70h] [rbp+30h] BYREF

  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"OverlayTestMode",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A46C = v5;
  v5 = 0;
  GetPersistedRegistryValueW(
    L"DWMSwitches",
    L"Software\\Microsoft\\Windows\\Dwm",
    L"DisableAdvancedDirectFlip",
    16,
    0,
    &v5,
    4,
    0);
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"DisableIndependentFlip",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A43C = v5 != 0;
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"FrameCounterPosition",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A448 = v5 != 0;
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"FlattenVirtualSurfaceEffectInput",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A44C = v5 != 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"CpuClipFlatteningTolerance",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    *(float *)&dword_180418758 = (float)(int)v5 / 1000.0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"InteractionOutputPredictionDisabled",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A458 = v5 != 0;
  if ( (unsigned int)GetPersistedRegistryValueW(
                       L"DWMSwitches",
                       L"Software\\Microsoft\\Windows\\Dwm",
                       L"BackdropBlurCachingThrottleMs",
                       16,
                       0,
                       &v5,
                       4,
                       0) )
  {
    v1 = 25 * stru_180419640.QuadPart;
  }
  else
  {
    v0 = v5;
    if ( v5 > 0x3E8 )
      v0 = 1000;
    v1 = stru_180419640.QuadPart * v0;
  }
  v5 = 0;
  qword_18041A480 = v1 / 1000;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSceneSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm\\Scene",
                        L"ForceNonPrimaryDisplayAdapter",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A478 = v5 != 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSceneSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm\\Scene",
                        L"ImageProcessingResizeThreshold",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    *(float *)&dword_180418750 = (float)(int)v5 / 100.0;
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"ForceEffectMode",
                        16,
                        0,
                        &v5,
                        4,
                        0)
    && v5 <= 2 )
  {
    dword_18041A460 = v5;
  }
  dword_180418754 = 1;
  v5 = 1;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"CompositorClockPolicy",
                        16,
                        0,
                        &v5,
                        4,
                        0)
    && v5 < 2 )
  {
    dword_180418754 = v5;
  }
  v5 = 1;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"ParallelModePolicy",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
  {
    v4 = v5;
    if ( v5 >= 3 )
      v4 = 1;
    dword_180418744 = v4;
  }
  v5 = 1;
  if ( (unsigned int)GetPersistedRegistryValueW(
                       L"DWMSwitches",
                       L"Software\\Microsoft\\Windows\\Dwm",
                       L"ParallelModeRateThreshold",
                       16,
                       0,
                       &v5,
                       4,
                       0) )
  {
    v2 = stru_180419640.QuadPart / 119;
  }
  else if ( v5 )
  {
    v2 = stru_180419640.QuadPart / v5;
  }
  else
  {
    v2 = 0;
  }
  qword_18041A470 = v2;
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"CustomRefreshRateMode",
                        16,
                        0,
                        &v5,
                        4,
                        0)
    && v5 <= 2 )
  {
    dword_180418748 = v5;
  }
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"SDRBoostPercentOverride",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    *(float *)&dword_18041874C = (float)(int)v5 / 100.0;
  v5 = 0;
  GetPersistedRegistryValueW(
    L"DWMSwitches",
    L"Software\\Microsoft\\Windows\\Dwm",
    L"DisableProjectedShadowsRendering",
    16,
    0,
    &v5,
    4,
    0);
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"ShowDirtyRegions",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A438 = v5;
  v5 = 0;
  if ( !(unsigned int)GetPersistedRegistryValueW(
                        L"DWMSwitches",
                        L"Software\\Microsoft\\Windows\\Dwm",
                        L"ResampleModeOverride",
                        16,
                        0,
                        &v5,
                        4,
                        0) )
    dword_18041A440 = v5;
  v5 = 0;
  result = GetPersistedRegistryValueW(
             L"DWMSwitches",
             L"Software\\Microsoft\\Windows\\Dwm",
             L"ResampleInLinearSpace",
             16,
             0,
             &v5,
             4,
             0);
  if ( !(_DWORD)result )
  {
    result = v5;
    dword_18041A444 = v5;
  }
  return result;
}
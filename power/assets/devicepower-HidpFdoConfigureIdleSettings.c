__int64 __fastcall HidpFdoConfigureIdleSettings(_QWORD *Context)
{
  int v2; // eax
  char *v3; // r14
  char v4; // si
  __int64 v5; // rax
  PDEVICE_OBJECT *v6; // rcx
  NTSTATUS v7; // eax
  int v8; // edx
  int v9; // r8d
  int v10; // ebx
  NTSTATUS v11; // eax
  int v12; // edx
  int v13; // r8d
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // r8d
  int v18; // eax
  int v19; // r9d
  NTSTATUS v20; // eax
  int v21; // edx
  int v22; // r8d
  NTSTATUS v23; // eax
  int v24; // edx
  int v25; // r8d
  NTSTATUS v26; // eax
  int v27; // edx
  int v28; // r8d
  __int64 v29; // rcx
  int v30; // edx
  int v31; // r8d
  char v32; // bl
  int v33; // eax
  int v34; // edx
  int v35; // r8d
  unsigned int v36; // r11d
  char v37; // r9
  unsigned int v38; // edx
  __int64 v39; // rbx
  __int64 v40; // rcx
  __int16 v41; // r10
  __int64 v42; // rax
  __int16 v43; // cx
  int v44; // eax
  int v45; // ecx
  NTSTATUS v46; // eax
  int v47; // edx
  int v48; // r8d
  GUID *v49; // rdx
  NTSTATUS v50; // eax
  int v51; // edx
  int v52; // r8d
  int v53; // eax
  int v54; // edx
  int v55; // r8d
  NTSTATUS v56; // eax
  int v57; // edx
  int v58; // r8d
  int Length; // [rsp+28h] [rbp-69h]
  int ResultLength; // [rsp+30h] [rbp-61h]
  int ResultLengtha; // [rsp+30h] [rbp-61h]
  int ResultLengthb; // [rsp+30h] [rbp-61h]
  int ResultLengthc; // [rsp+30h] [rbp-61h]
  const WCHAR *v65; // [rsp+50h] [rbp-41h]
  __int64 v66; // [rsp+58h] [rbp-39h]
  ULONG v67; // [rsp+68h] [rbp-29h] BYREF
  void *DeviceRegKey; // [rsp+70h] [rbp-21h] BYREF
  int v69; // [rsp+78h] [rbp-19h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+80h] [rbp-11h] BYREF
  __int64 Flink_low; // [rsp+90h] [rbp-1h]
  int v72; // [rsp+98h] [rbp+7h]
  __int64 v73; // [rsp+A0h] [rbp+Fh] BYREF
  __int128 KeyValueInformation; // [rsp+A8h] [rbp+17h] BYREF
  __int64 v75; // [rsp+B8h] [rbp+27h] BYREF

  v75 = WNF_PO_INPUT_SUPPRESS_NOTIFICATION_EX;
  v2 = *((_DWORD *)Context + 439) | 8;
  *(_QWORD *)((char *)Context + 1772) = 0LL;
  Context[220] = 0LL;
  DeviceRegKey = 0LL;
  v67 = 0;
  *((_DWORD *)Context + 439) = v2 & 0xFFFFFE88 | 0x30;
  v3 = (char *)Context + 1748;
  v73 = 0LL;
  *((_DWORD *)Context + 433) = 1000;
  *((_DWORD *)Context + 432) = 5000;
  v4 = 1;
  *((_DWORD *)Context + 435) = 5000;
  v5 = *Context;
  DestinationString = 0LL;
  *((_DWORD *)Context + 434) = 1000;
  KeyValueInformation = 0LL;
  *((_DWORD *)Context + 436) = 1000;
  *((_DWORD *)Context + 437) = 1000;
  v6 = *(PDEVICE_OBJECT **)(v5 + 64);
  v69 = 0;
  v7 = IoOpenDeviceRegistryKey(*v6, 1u, 0x20000u, &DeviceRegKey);
  v10 = v7;
  if ( v7 >= 0 )
  {
    RtlInitUnicodeString(&DestinationString, L"EnhancedPowerManagementEnabled");
    v72 = 2;
    v11 = ZwQueryValueKey(
            DeviceRegKey,
            &DestinationString,
            KeyValuePartialInformation,
            &KeyValueInformation,
            0x10u,
            &v67);
    if ( v11 < 0 )
    {
      LOBYTE(v12) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 3u;
      if ( (_BYTE)v12 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LODWORD(v66) = v11;
        v65 = L"EnhancedPowerManagementEnabled";
        LOBYTE(v13) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_qSd(WPP_GLOBAL_Control->AttachedDevice, v12, v13, Context[84], 3, ResultLength, 14);
      }
    }
    else
    {
      if ( BYTE12(KeyValueInformation) )
      {
        v14 = 1;
        v15 = 16;
      }
      else
      {
        v14 = 0;
        v15 = 0;
      }
      *((_DWORD *)Context + 439) = v15 | *((_DWORD *)Context + 439) & 0xFFFFFFCF;
      if ( v14 == 1 )
      {
        RtlInitUnicodeString(&DestinationString, L"EnhancedPowerManagementUseMonitor");
        if ( ZwQueryValueKey(
               DeviceRegKey,
               &DestinationString,
               KeyValuePartialInformation,
               &KeyValueInformation,
               0x10u,
               &v67) >= 0 )
        {
          if ( BYTE12(KeyValueInformation) )
            *((_DWORD *)Context + 439) |= 0x40u;
        }
      }
    }
    RtlInitUnicodeString(&DestinationString, L"WakeScreenOnInputSupport");
    if ( (int)HidpFdoRegistryQueryULong(Context, DeviceRegKey, &DestinationString, &v69) >= 0 )
    {
      v18 = v69;
      *((_DWORD *)Context + 441) = v69;
      if ( v18 )
      {
        v19 = *((_DWORD *)Context + 86);
        if ( v19 > 1 )
        {
          RtlInitUnicodeString(&DestinationString, L"WakeScreenOnInputTimeout");
          HidpFdoRegistryQueryULong(Context, DeviceRegKey, &DestinationString, v3);
        }
        else
        {
          LOBYTE(v16) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                     && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                     && BYTE1(WPP_GLOBAL_Control->Timer) >= 2u;
          if ( (_BYTE)v16 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v17) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
            WPP_RECORDER_AND_TRACE_SF_qD(
              WPP_GLOBAL_Control->AttachedDevice,
              v16,
              v17,
              Context[85],
              Length,
              9,
              15,
              (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
              *Context,
              v19);
          }
          *((_DWORD *)Context + 441) = 0;
        }
      }
    }
    RtlInitUnicodeString(&DestinationString, L"SelectiveSuspendOn");
    v20 = ZwQueryValueKey(
            DeviceRegKey,
            &DestinationString,
            KeyValuePartialInformation,
            &KeyValueInformation,
            0x10u,
            &v67);
    if ( v20 < 0 )
    {
      if ( v20 == -1073741772 )
      {
        if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
          || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
          || (LOBYTE(v21) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 4u) )
        {
          LOBYTE(v21) = 0;
        }
        if ( (_BYTE)v21 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LODWORD(v66) = -1073741772;
          v65 = L"SelectiveSuspendOn";
          LOBYTE(v22) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
          WPP_RECORDER_AND_TRACE_SF_qSd(WPP_GLOBAL_Control->AttachedDevice, v21, v22, Context[84], 4, ResultLengtha, 16);
        }
      }
      else
      {
        if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
          || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
          || (LOBYTE(v21) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 3u) )
        {
          LOBYTE(v21) = 0;
        }
        if ( (_BYTE)v21 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LODWORD(v66) = v20;
          v65 = L"SelectiveSuspendOn";
          LOBYTE(v22) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
          WPP_RECORDER_AND_TRACE_SF_qSd(WPP_GLOBAL_Control->AttachedDevice, v21, v22, Context[84], 3, ResultLengtha, 17);
        }
      }
    }
    else if ( !BYTE12(KeyValueInformation) )
    {
      *((_DWORD *)Context + 439) &= ~8u;
    }
    RtlInitUnicodeString(&DestinationString, L"SelectiveSuspendEnabled");
    v23 = ZwQueryValueKey(
            DeviceRegKey,
            &DestinationString,
            KeyValuePartialInformation,
            &KeyValueInformation,
            0x10u,
            &v67);
    if ( v23 < 0 )
    {
      if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
        || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
        || (LOBYTE(v24) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 3u) )
      {
        LOBYTE(v24) = 0;
      }
      if ( (_BYTE)v24 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LODWORD(v66) = v23;
        v65 = L"SelectiveSuspendEnabled";
        LOBYTE(v25) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_qSd(WPP_GLOBAL_Control->AttachedDevice, v24, v25, Context[84], 3, ResultLengthb, 18);
      }
    }
    else if ( BYTE12(KeyValueInformation) )
    {
      *((_DWORD *)Context + 439) |= 4u;
    }
    RtlInitUnicodeString(&DestinationString, L"SelectiveSuspendTimeout");
    if ( ZwQueryValueKey(
           DeviceRegKey,
           &DestinationString,
           KeyValuePartialInformation,
           &KeyValueInformation,
           0x10u,
           &v67) >= 0
      && DWORD2(KeyValueInformation) == 4 )
    {
      *((_DWORD *)Context + 432) = HIDWORD(KeyValueInformation);
    }
    RtlInitUnicodeString(&DestinationString, L"SuppressInputInCS");
    v26 = ZwQueryValueKey(
            DeviceRegKey,
            &DestinationString,
            KeyValuePartialInformation,
            &KeyValueInformation,
            0x10u,
            &v67);
    if ( v26 < 0 )
    {
      if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
        || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
        || (LOBYTE(v27) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 3u) )
      {
        LOBYTE(v27) = 0;
      }
      if ( (_BYTE)v27 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LODWORD(v66) = v26;
        v65 = L"SuppressInputInCS";
        LOBYTE(v28) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_qSd(WPP_GLOBAL_Control->AttachedDevice, v27, v28, Context[84], 3, ResultLengthc, 20);
      }
    }
    else if ( BYTE12(KeyValueInformation) )
    {
      *((_DWORD *)Context + 439) |= 0x80u;
      if ( *((_DWORD *)Context + 441) )
      {
        if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
          || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
          || (LOBYTE(v27) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 2u) )
        {
          LOBYTE(v27) = 0;
        }
        if ( (_BYTE)v27 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LOBYTE(v28) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
          WPP_RECORDER_AND_TRACE_SF_q(
            WPP_GLOBAL_Control->AttachedDevice,
            v27,
            v28,
            Context[85],
            2,
            9,
            19,
            (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
            *Context,
            v65,
            v66);
        }
        *((_DWORD *)Context + 441) = 0;
      }
    }
    RtlInitUnicodeString(&DestinationString, L"SystemInputSuppressionEnabled");
    if ( (int)HidpFdoRegistryQueryULong(Context, DeviceRegKey, &DestinationString, &v69) >= 0 && v69 )
      *((_DWORD *)Context + 440) = 1;
    RtlInitUnicodeString(&DestinationString, L"TestIdleTimeoutNoHandlesInitial");
    if ( ZwQueryValueKey(
           DeviceRegKey,
           &DestinationString,
           KeyValuePartialInformation,
           &KeyValueInformation,
           0x10u,
           &v67) >= 0
      && DWORD2(KeyValueInformation) == 4 )
    {
      *((_DWORD *)Context + 435) = HIDWORD(KeyValueInformation);
    }
    RtlInitUnicodeString(&DestinationString, L"TestIdleTimeoutNoHandles");
    if ( ZwQueryValueKey(
           DeviceRegKey,
           &DestinationString,
           KeyValuePartialInformation,
           &KeyValueInformation,
           0x10u,
           &v67) >= 0
      && DWORD2(KeyValueInformation) == 4 )
    {
      *((_DWORD *)Context + 434) = 1000 * HIDWORD(KeyValueInformation);
    }
    RtlInitUnicodeString(&DestinationString, L"TestIdleMonitorDim");
    if ( ZwQueryValueKey(
           DeviceRegKey,
           &DestinationString,
           KeyValuePartialInformation,
           &KeyValueInformation,
           0x10u,
           &v67) >= 0
      && DWORD2(KeyValueInformation) == 4 )
    {
      *((_DWORD *)Context + 439) |= 1u;
      *((_DWORD *)Context + 436) = 1000 * HIDWORD(KeyValueInformation);
    }
    Flink_low = LODWORD(WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink);
    if ( ((__int64)WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink & 0x10) == 0 )
    {
      LODWORD(Flink_low) = LODWORD(WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink) | 1;
      wil_details_FeatureReporting_ReportUsageToService(
        LODWORD(WPP_MAIN_CB.DeviceLock.Header.WaitListHead.Flink) | 1u,
        Flink_low,
        3LL);
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(v29, 3LL);
    }
    RtlInitUnicodeString(&DestinationString, L"FullPowerDownOnTransientDx");
    if ( (int)HidpFdoRegistryQueryULong(Context, DeviceRegKey, &DestinationString, &v69) < 0 )
      *((_DWORD *)Context + 439) |= 0x200u;
    else
      *((_DWORD *)Context + 439) = (v69 != 0 ? 0x200 : 0) | *((_DWORD *)Context + 439) & 0xFFFFFDFF;
    ZwClose(DeviceRegKey);
    HidpGetDeviceFlags(Context, &v73);
    v32 = v73;
    if ( (v73 & 1) != 0 )
    {
      *((_DWORD *)Context + 439) |= 1u;
      if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
        || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
        || (LOBYTE(v30) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 4u) )
      {
        LOBYTE(v30) = 0;
      }
      if ( (_BYTE)v30 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LOBYTE(v31) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_q(
          WPP_GLOBAL_Control->AttachedDevice,
          v30,
          v31,
          Context[84],
          4,
          9,
          21,
          (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
          *Context,
          v65,
          v66);
      }
    }
    if ( (v32 & 2) != 0 )
    {
      *((_DWORD *)Context + 439) |= 2u;
      LOBYTE(v30) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 4u;
      if ( (_BYTE)v30 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LOBYTE(v31) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_q(
          WPP_GLOBAL_Control->AttachedDevice,
          v30,
          v31,
          Context[84],
          4,
          9,
          22,
          (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
          *Context);
      }
    }
    if ( (v32 & 4) != 0 )
    {
      *((_DWORD *)Context + 439) &= ~4u;
      LOBYTE(v30) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 4u;
      if ( (_BYTE)v30 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LOBYTE(v31) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_q(
          WPP_GLOBAL_Control->AttachedDevice,
          v30,
          v31,
          Context[84],
          4,
          9,
          23,
          (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
          *Context);
      }
    }
    if ( (v32 & 0x10) != 0 )
    {
      *((_DWORD *)Context + 439) |= 0x100u;
      LOBYTE(v30) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                 && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                 && BYTE1(WPP_GLOBAL_Control->Timer) >= 4u;
      if ( (_BYTE)v30 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      {
        LOBYTE(v31) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
        WPP_RECORDER_AND_TRACE_SF_q(
          WPP_GLOBAL_Control->AttachedDevice,
          v30,
          v31,
          Context[84],
          4,
          9,
          24,
          (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
          *Context);
      }
    }
    if ( (*((_BYTE *)Context + 1756) & 0x30) != 0x30 || *((_BYTE *)Context + 2048) )
    {
      v33 = HidpRegisterSleepstudyBlockerReasons(**(_QWORD **)(*Context + 64LL), Context);
      if ( v33 < 0 )
      {
        LOBYTE(v34) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                   && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x400) != 0
                   && BYTE1(WPP_GLOBAL_Control->Timer) >= 2u;
        if ( (_BYTE)v34 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LOBYTE(v35) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
          WPP_RECORDER_AND_TRACE_SF_qL(
            WPP_GLOBAL_Control->AttachedDevice,
            v34,
            v35,
            Context[84],
            2,
            11,
            25,
            (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
            *Context,
            v33);
        }
      }
    }
    if ( *((_DWORD *)Context + 440) != 1 && *((_BYTE *)Context + 2048) && (*((_DWORD *)Context + 439) & 0x30) != 0 )
    {
      v36 = *((_DWORD *)Context + 42);
      v37 = 0;
      v38 = 0;
      if ( v36 )
      {
        v39 = Context[19];
        do
        {
          v40 = 424LL * v38;
          v41 = *(_WORD *)(v40 + v39 + 8);
          v42 = v40 + v39;
          if ( v41 == 1 && ((v43 = *(_WORD *)(v42 + 10), v43 == (_WORD)v72) || v43 == 6) )
          {
            v37 = 1;
          }
          else if ( v41 == 13 && *(_WORD *)(v42 + 10) == 5 )
          {
            *((_DWORD *)Context + 440) = 3;
            goto LABEL_169;
          }
          ++v38;
        }
        while ( v38 < v36 );
        if ( !v37 )
          goto LABEL_168;
        *((_DWORD *)Context + 440) = 1;
      }
      else
      {
LABEL_168:
        *((_DWORD *)Context + 440) = 2;
      }
    }
LABEL_169:
    TraceLoggingIdleConfiguration(Context);
    v44 = HidpFdoRegisterWithPoFx(Context);
    *((_DWORD *)Context + 445) |= 1u;
    v10 = v44;
    if ( v44 >= 0 )
    {
      HidFdoStartRunTimePolicyEngine(Context);
      v45 = *((_DWORD *)Context + 439);
      if ( (v45 & 1) != 0 )
      {
        v46 = PoRegisterPowerSettingCallback(
                0LL,
                &GUID_CONSOLE_DISPLAY_STATE,
                HidpFdoPowerSettingCallback,
                Context,
                (PVOID *)Context + 77);
        v10 = v46;
        if ( v46 < 0 )
        {
          LOBYTE(v47) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                     && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                     && BYTE1(WPP_GLOBAL_Control->Timer) >= 2u;
          if ( (_BYTE)v47 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v48) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
            WPP_RECORDER_AND_TRACE_SF_qL(
              WPP_GLOBAL_Control->AttachedDevice,
              v47,
              v48,
              Context[84],
              2,
              9,
              26,
              (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
              *Context,
              v46);
          }
        }
      }
      else if ( (*((_DWORD *)Context + 439) & 0x30) == 0x10
             || (v45 & 0x30) != 0 && *((_BYTE *)Context + 2048)
             || *((_DWORD *)Context + 441) )
      {
        if ( (v45 & 0x40) != 0 || (v49 = &GUID_LOW_POWER_EPOCH, *((_DWORD *)Context + 441)) )
          v49 = &GUID_MONITOR_POWER_ON;
        v50 = PoRegisterPowerSettingCallback(0LL, v49, HidpFdoPowerSettingCallback, Context, (PVOID *)Context + 77);
        if ( v50 < 0 )
        {
          LOBYTE(v51) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                     && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                     && BYTE1(WPP_GLOBAL_Control->Timer) >= 2u;
          if ( (_BYTE)v51 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v52) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
            WPP_RECORDER_AND_TRACE_SF_qL(
              WPP_GLOBAL_Control->AttachedDevice,
              v51,
              v52,
              Context[84],
              2,
              9,
              27,
              (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
              *Context,
              v50);
          }
        }
      }
      if ( *((_DWORD *)Context + 440) == 1 )
      {
        v53 = ExSubscribeWnfStateChange(
                Context + 79,
                &v75,
                1LL,
                0LL,
                HidpSystemInputSuppressionWnfCallbackRoutine,
                Context);
        if ( v53 < 0 )
        {
          LOBYTE(v54) = WPP_GLOBAL_Control != (PDEVICE_OBJECT)&WPP_GLOBAL_Control
                     && (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) != 0
                     && BYTE1(WPP_GLOBAL_Control->Timer) >= 2u;
          if ( (_BYTE)v54 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v55) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
            WPP_RECORDER_AND_TRACE_SF_qL(
              WPP_GLOBAL_Control->AttachedDevice,
              v54,
              v55,
              Context[84],
              2,
              9,
              28,
              (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
              *Context,
              v53);
          }
        }
      }
      if ( v10 >= 0 )
      {
        v56 = IoWMIRegistrationControl((PDEVICE_OBJECT)*Context, 1u);
        v10 = v56;
        if ( v56 < 0 )
        {
          if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
            || (HIDWORD(WPP_GLOBAL_Control->Timer) & 0x100) == 0
            || BYTE1(WPP_GLOBAL_Control->Timer) < 2u )
          {
            v4 = 0;
          }
          if ( v4 || WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          {
            LOBYTE(v57) = v4;
            LOBYTE(v58) = WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED;
            WPP_RECORDER_AND_TRACE_SF_qL(
              WPP_GLOBAL_Control->AttachedDevice,
              v57,
              v58,
              Context[84],
              2,
              9,
              29,
              (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
              *Context,
              v56);
          }
        }
      }
      if ( Context[270] && (*((_DWORD *)Context + 439) & 0x30) == 0 )
        SleepstudyHelper_ComponentActive();
    }
  }
  else
  {
    if ( WPP_GLOBAL_Control == (PDEVICE_OBJECT)&WPP_GLOBAL_Control
      || !_bittest((const signed __int32 *)&WPP_GLOBAL_Control->Timer + 1, 8u)
      || (LOBYTE(v8) = 1, BYTE1(WPP_GLOBAL_Control->Timer) < 5u) )
    {
      LOBYTE(v8) = 0;
    }
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED || !LOWORD(WPP_GLOBAL_Control->DeviceType) )
      v4 = 0;
    if ( (_BYTE)v8 || v4 )
    {
      LOBYTE(v9) = v4;
      WPP_RECORDER_AND_TRACE_SF_qL(
        WPP_GLOBAL_Control->AttachedDevice,
        v8,
        v9,
        Context[84],
        5,
        9,
        13,
        (__int64)&WPP_d3f5d7a6d5253836891dd9c17b51bf25_Traceguids,
        *Context,
        v7);
    }
  }
  return (unsigned int)v10;
}

// vhf.sys

char __fastcall FDO_GetIdleSupported(__int64 a1)
{
  char v1; // di
  char v2; // bl
  int v3; // eax
  int v4; // edx
  int v5; // r8d
  int v6; // r9d
  int v7; // edx
  WDFDRIVER Driver; // rdx
  int v10; // [rsp+48h] [rbp-9h] BYREF
  __int64 SystemInformation; // [rsp+50h] [rbp-1h] BYREF
  __int64 v12; // [rsp+58h] [rbp+7h] BYREF
  _QWORD v13[2]; // [rsp+60h] [rbp+Fh] BYREF
  __int128 v14; // [rsp+70h] [rbp+1Fh] BYREF
  __int64 v15; // [rsp+80h] [rbp+2Fh]
  int v16; // [rsp+88h] [rbp+37h]

  v1 = a1;
  v10 = 0;
  SystemInformation = 0LL;
  v12 = 0LL;
  v16 = *(_DWORD *)L"d";
  v14 = *(_OWORD *)L"IdleSupported";
  v2 = 0;
  v13[1] = &v14;
  v15 = *(_QWORD *)L"orted";
  v13[0] = 1835034LL;
  v3 = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, __int64, __int64, _QWORD, __int64 *))(WdfFunctions_01015 + 1000))(
         WdfDriverGlobals,
         a1,
         1LL,
         131097LL,
         0LL,
         &v12);
  if ( v3 < 0 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_14;
    v6 = 44;
    LOBYTE(v4) = 2;
    goto LABEL_4;
  }
  v3 = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, _QWORD *, int *))(WdfFunctions_01015 + 1920))(
         WdfDriverGlobals,
         v12,
         v13,
         &v10);
  if ( v3 >= 0 )
  {
    if ( v10 )
    {
      LODWORD(SystemInformation) = 8;
      v2 = 1;
      if ( ZwQuerySystemInformation(MaxSystemInfoClass|SystemProcessInformation, &SystemInformation, 8u, 0LL) < 0
        || (SystemInformation & 0x200000000LL) == 0 )
      {
        v2 = 0;
        if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        {
          LOBYTE(v7) = 3;
          WPP_RECORDER_SF_qq(
            WPP_GLOBAL_Control->DeviceExtension,
            v7,
            v5,
            46,
            (__int64)&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
            (char)WdfDriverGlobals->Driver,
            v1);
        }
      }
    }
  }
  else if ( v3 != -1073741772 && WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    v6 = 45;
    LOBYTE(v4) = 3;
LABEL_4:
    WPP_RECORDER_SF_qd(
      WPP_GLOBAL_Control->DeviceExtension,
      v4,
      v5,
      v6,
      (__int64)&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
      (char)WdfDriverGlobals->Driver,
      v3);
  }
LABEL_14:
  if ( v12 )
    (*(void (__fastcall **)(PWDF_DRIVER_GLOBALS))(WdfFunctions_01015 + 1848))(WdfDriverGlobals);
  if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
  {
    Driver = WdfDriverGlobals->Driver;
    LOBYTE(Driver) = 4;
    WPP_RECORDER_SF_qqd(
      WPP_GLOBAL_Control->DeviceExtension,
      (_DWORD)Driver,
      v5,
      47,
      (__int64)&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
      (char)WdfDriverGlobals->Driver,
      v1,
      v2);
  }
  return v2;
}
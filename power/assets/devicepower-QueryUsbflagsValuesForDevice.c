__int64 __fastcall HUBREG_QueryUsbflagsValuesForDevice(volatile signed __int32 *a1, int a2, int a3, int a4)
{
  __int64 v4; // rbx
  char v9; // r13
  __int64 v10; // rax
  NTSTATUS UsbflagsDeviceKey; // esi
  __int64 v12; // r10
  __int64 v13; // rbx
  int v14; // edx
  int v15; // r9d
  bool v16; // zf
  bool v17; // zf
  bool v18; // zf
  bool v19; // zf
  bool v20; // zf
  bool v21; // zf
  char v22; // al
  __int64 v24; // [rsp+38h] [rbp-C8h]
  int v25; // [rsp+80h] [rbp-80h] BYREF
  __int64 v26; // [rsp+88h] [rbp-78h] BYREF
  char pszDest[8]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v28; // [rsp+98h] [rbp-68h] BYREF
  __int64 v29; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v30; // [rsp+A8h] [rbp-58h] BYREF
  __int64 v31; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v32; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v33; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v34; // [rsp+C8h] [rbp-38h] BYREF
  __int64 v35; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v36; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v37; // [rsp+E0h] [rbp-20h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+E8h] [rbp-18h] BYREF
  char v39; // [rsp+100h] [rbp+0h] BYREF

  v4 = *(_QWORD *)a1;
  v25 = 0;
  v36 = 0LL;
  v32 = 0LL;
  v33 = 0LL;
  v29 = 0LL;
  v30 = 0LL;
  v31 = 0LL;
  v35 = 0LL;
  v37 = 0LL;
  v9 = *(_BYTE *)(v4 + 200);
  DestinationString.Buffer = (wchar_t *)&v39;
  v10 = *((_QWORD *)a1 + 1);
  v26 = 0LL;
  v28 = 0LL;
  *(_QWORD *)&DestinationString.Length = 6291456LL;
  v24 = *(_QWORD *)(v10 + 1432);
  v34 = 0LL;
  HUBREG_OpenCreateUsbflagsDeviceKey(a2, a3, a4, 131097, (__int64)&v34, (__int64)&v26, 0, v24);
  UsbflagsDeviceKey = HUBREG_OpenCreateUsbflagsDeviceKey(
                        a2,
                        a3,
                        a4,
                        131097,
                        0LL,
                        (__int64)&v28,
                        1,
                        *(_QWORD *)(*((_QWORD *)a1 + 1) + 1432LL));
  if ( UsbflagsDeviceKey < 0 )
    goto LABEL_157;
  RtlStringCchPrintfA(pszDest, 3uLL, "%02X", *((unsigned __int8 *)a1 + 1992));
  if ( *(_DWORD *)(v4 + 168) == 3 && (v12 = *(_QWORD *)(v4 + 176)) != 0 )
    HUBMISC_QueryKseDeviceFlags(
      (unsigned int)pszDest,
      a2,
      a3,
      a4,
      v12,
      *(_QWORD *)(v4 + 184),
      *(_QWORD *)(v4 + 192),
      (__int64)&v36,
      (__int64)&v32,
      (__int64)&v33,
      (__int64)&v29,
      (__int64)&v30,
      (__int64)&v31,
      (__int64)&v35,
      0,
      *(_QWORD *)(*((_QWORD *)a1 + 1) + 1432LL));
  else
    HUBMISC_QueryKseDeviceFlags(
      (unsigned int)pszDest,
      a2,
      a3,
      a4,
      0LL,
      0LL,
      0LL,
      (__int64)&v36,
      (__int64)&v32,
      (__int64)&v33,
      (__int64)&v29,
      (__int64)&v30,
      (__int64)&v31,
      (__int64)&v35,
      0,
      *(_QWORD *)(*((_QWORD *)a1 + 1) + 1432LL));
  v13 = v36 | v32 | v33 | v29 | v30 | v31 | v35;
  if ( v34 )
  {
    UsbflagsDeviceKey = RtlUnicodeStringPrintf(
                          &DestinationString,
                          L"IgnoreHWSerNum%04X%04X",
                          *((unsigned __int16 *)a1 + 998),
                          *((unsigned __int16 *)a1 + 999));
    if ( UsbflagsDeviceKey < 0 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 25;
LABEL_156:
      LOBYTE(v14) = 2;
      WPP_RECORDER_SF_d(
        *(_QWORD *)(*((_QWORD *)a1 + 1) + 1432LL),
        v14,
        5,
        v15,
        (__int64)&WPP_f014620ea38c320d7399f0c301627fdd_Traceguids,
        UsbflagsDeviceKey);
      goto LABEL_157;
    }
    UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, struct _UNICODE_STRING *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                          WdfDriverGlobals,
                          v34,
                          &DestinationString,
                          4LL,
                          &v25,
                          0LL,
                          0LL);
    if ( UsbflagsDeviceKey < 0 )
    {
      if ( UsbflagsDeviceKey != -1073741772 )
      {
        if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
          goto LABEL_157;
        v15 = 26;
        goto LABEL_156;
      }
    }
    else if ( v25 )
    {
      _InterlockedOr(a1 + 411, 1u);
    }
  }
  v25 = 0;
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v28,
                        L"\b\n",
                        2LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey >= 0 )
  {
    if ( v25 )
    {
      *((_BYTE *)a1 + 2052) = BYTE1(v25);
      goto LABEL_28;
    }
    goto LABEL_21;
  }
  if ( UsbflagsDeviceKey != -1073741772 )
  {
    if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_157;
    v15 = 27;
    goto LABEL_156;
  }
  if ( (v13 & 1) != 0 )
  {
LABEL_21:
    _InterlockedOr(a1 + 408, 0x80u);
    goto LABEL_28;
  }
  if ( (v29 & 2) != 0 || (v30 & 2) != 0 || (v31 & 2) != 0 || (v32 & 2) != 0 || (v33 & 2) != 0 )
    _InterlockedOr(a1 + 411, 2u);
LABEL_28:
  v25 = 0;
  if ( v26 )
  {
    UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, void *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                          WdfDriverGlobals,
                          v26,
                          &g_IgnoreHwSerialNumber,
                          4LL,
                          &v25,
                          0LL,
                          0LL);
    if ( UsbflagsDeviceKey >= 0 )
    {
      v16 = v25 == 0;
      goto LABEL_35;
    }
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 28;
      goto LABEL_156;
    }
  }
  v16 = (v13 & 0x40) == 0;
LABEL_35:
  if ( !v16 )
    _InterlockedOr(a1 + 411, 1u);
  v25 = 0;
  if ( !v26 )
    goto LABEL_44;
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v26,
                        L"68",
                        4LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 29;
      goto LABEL_156;
    }
LABEL_44:
    if ( (v13 & 0x80000000) == 0 )
      goto LABEL_46;
    goto LABEL_45;
  }
  if ( !v25 )
    goto LABEL_46;
LABEL_45:
  _InterlockedOr(a1 + 411, 0x200000u);
LABEL_46:
  v25 = 0;
  if ( v26 )
  {
    UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, void *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                          WdfDriverGlobals,
                          v26,
                          &g_ResetOnResume,
                          4LL,
                          &v25,
                          0LL,
                          0LL);
    if ( UsbflagsDeviceKey >= 0 )
    {
      v17 = v25 == 0;
      goto LABEL_53;
    }
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 30;
      goto LABEL_156;
    }
  }
  v17 = (v13 & 4) == 0;
LABEL_53:
  if ( !v17 )
    _InterlockedOr(a1 + 411, 4u);
  v25 = 0;
  _InterlockedOr(a1 + 411, 8u);
  if ( !v26 )
    goto LABEL_62;
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v26,
                        L"&(", // g_DisableOnSoftRemove ; "&("
                        4LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 31;
      goto LABEL_156;
    }
LABEL_62:
    if ( (v13 & 8) == 0 )
      goto LABEL_64;
    goto LABEL_63;
  }
  if ( v25 )
    goto LABEL_64;
LABEL_63:
  _InterlockedAnd(a1 + 411, 0xFFFFFFF7);
LABEL_64:
  v25 = 0;
  if ( v26 )
  {
    UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                          WdfDriverGlobals,
                          v26,
                          L"02", // g_EnableExtendedValidation ; "02"
                          4LL,
                          &v25,
                          0LL,
                          0LL);
    if ( UsbflagsDeviceKey >= 0 )
    {
      v18 = v25 == 0;
      goto LABEL_71;
    }
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 32;
      goto LABEL_156;
    }
  }
  v18 = (v13 & 0x10) == 0;
LABEL_71:
  if ( !v18 )
    _InterlockedOr(a1 + 411, 0x10u);
  v25 = 0;
  if ( !v26 )
    goto LABEL_80;
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v26,
                        L":<",
                        4LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 33;
      goto LABEL_156;
    }
LABEL_80:
    if ( (v13 & 0x1000000000LL) == 0 )
      goto LABEL_82;
    goto LABEL_81;
  }
  if ( !v25 )
    goto LABEL_82;
LABEL_81:
  _InterlockedOr(a1 + 411, 0x800000u);
LABEL_82:
  v25 = 0;
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v28,
                        L"(*", // g_EnableDiagnosticMode ; "(*"
                        4LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 34;
      goto LABEL_156;
    }
    v19 = (v13 & 0x20) == 0;
  }
  else
  {
    v19 = v25 == 0;
  }
  if ( !v19 )
    _InterlockedOr(a1 + 411, 0x20u);
  v25 = 0;
  if ( v26 )
  {
    UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, void *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                          WdfDriverGlobals,
                          v26,
                          &g_DisableLpm, // DisableLPM
                          4LL,
                          &v25,
                          0LL,
                          0LL);
    if ( UsbflagsDeviceKey >= 0 )
    {
      v20 = v25 == 0;
      goto LABEL_95;
    }
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 35;
      goto LABEL_156;
    }
  }
  v20 = (v13 & 0x1000) == 0;
LABEL_95:
  if ( !v20 )
    _InterlockedOr(a1 + 411, 0x80u);
  if ( (v13 & 0x400) != 0 )
    _InterlockedOr(a1 + 411, 0x40u);
  if ( (v13 & 0x4000) != 0 )
    _InterlockedOr(a1 + 411, 0x100u);
  if ( (v13 & 0x10000) != 0 && *(_BYTE *)(*(_QWORD *)a1 + 240LL) )
    _InterlockedOr(a1 + 411, 0x80u);
  if ( (v13 & 0x80000) != 0 )
    _InterlockedOr(a1 + 411, 0x400u);
  if ( (v13 & 0x200000) != 0 )
    _InterlockedOr(a1 + 411, 0x800u);
  if ( (v13 & 0x800000) != 0 )
    _InterlockedOr(a1 + 411, 0x1000u);
  if ( (v13 & 0x1000000) != 0 )
    _InterlockedOr(a1 + 411, 0x2000u);
  v25 = 0;
  if ( !v26 )
  {
LABEL_118:
    v21 = (v13 & 0x8000000) == 0;
    goto LABEL_119;
  }
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v26,
                        L",.", // g_SkipBOSDescriptorQuery ; ",."
                        4LL,
                        &v25,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 36;
      goto LABEL_156;
    }
    goto LABEL_118;
  }
  v21 = v25 == 0;
LABEL_119:
  if ( !v21 )
    _InterlockedOr(a1 + 411, 0x8000u);
  if ( (v13 & 0x2000) != 0 )
    _InterlockedOr(a1 + 411, 0x20000u);
  if ( (v13 & 0x20000) != 0 )
    _InterlockedOr(a1 + 411, 0x40000u);
  if ( (v13 & 0x40000000) != 0 )
    _InterlockedOr(a1 + 411, 0x100000u);
  if ( ((v13 & 0x400000) != 0 || (v13 & 0x4000000000LL) != 0 && v9) && (a1[408] & 2) == 0 )
    _InterlockedOr(a1 + 411, 0x80000u);
  if ( (v13 & 0x100000000LL) != 0 )
    _InterlockedOr(a1 + 411, 0x400000u);
  if ( (v13 & 0x2000000000LL) != 0 )
    _InterlockedOr(a1 + 411, 0x1000000u);
  if ( (v13 & 0x80000000000LL) != 0 )
    _InterlockedOr(a1 + 411, 0x4000000u);
  if ( (v13 & 0x800000000000LL) != 0 )
    _InterlockedOr(a1 + 411, 0x8000000u);
  UsbflagsDeviceKey = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, __int64 *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
                        WdfDriverGlobals,
                        v28,
                        L".0", // g_MsOs20DescriptorSetInfo
                        8LL,
                        &v37,
                        0LL,
                        0LL);
  if ( UsbflagsDeviceKey < 0 )
  {
    if ( UsbflagsDeviceKey != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_157;
      v15 = 37;
      goto LABEL_156;
    }
  }
  else
  {
    _InterlockedOr(a1 + 617, 4u);
    v22 = BYTE6(v37);
    *((_DWORD *)a1 + 616) |= 4u;
    *((_BYTE *)a1 + 2052) = v22;
    *((_QWORD *)a1 + 310) = v37;
  }
  if ( *((_WORD *)a1 + 998) == 8457 && *((_WORD *)a1 + 999) == 2064 && (unsigned __int8)*((_WORD *)a1 + 1000) < 0x89u )
    _InterlockedOr(a1 + 411, 0x10000u);
  if ( v26 )
    HUBREG_QueryUsbflagsAlternateSettingFilter(a1);
  UsbflagsDeviceKey = 0;
LABEL_157:
  if ( v26 )
    (*(void (__fastcall **)(PWDF_DRIVER_GLOBALS))(WdfFunctions_01015 + 1848))(WdfDriverGlobals);
  if ( v34 )
    (*(void (__fastcall **)(PWDF_DRIVER_GLOBALS))(WdfFunctions_01015 + 1848))(WdfDriverGlobals);
  if ( v28 )
    (*(void (__fastcall **)(PWDF_DRIVER_GLOBALS))(WdfFunctions_01015 + 1848))(WdfDriverGlobals);
  return (unsigned int)UsbflagsDeviceKey;
}

__int64 __fastcall HUBREG_QueryGlobalHubValues(__int64 a1)
{
  __int64 result; // rax
  int v3; // edx
  char v4; // al
  int v5; // r9d
  int v6; // [rsp+80h] [rbp+40h] BYREF
  __int64 v7; // [rsp+88h] [rbp+48h] BYREF

  v6 = 0;
  v7 = 0LL;
  _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x80u);
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, _QWORD, void *, __int64, _QWORD, __int64 *))(WdfFunctions_01015 + 1832))(
             WdfDriverGlobals,
             0LL,
             &g_HubGlobalKeyName,
             131097LL,
             0LL,
             &v7);
  if ( (int)result < 0 )
    goto LABEL_58;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"24", // g_DisableSelectiveSuspendUI
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 42;
      goto LABEL_57;
    }
  }
  else if ( v6 )
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 4), 2u);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"$&", // g_MsOsDescriptorMode
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 44;
      goto LABEL_57;
    }
  }
  else if ( v6 && (unsigned int)(v6 - 1) >= 2 )
  {
    if ( WPP_RECORDER_INITIALIZED != (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
    {
      LOBYTE(v3) = 2;
      WPP_RECORDER_SF_d(*(_QWORD *)(a1 + 64), v3, 2, 43, (__int64)&WPP_f014620ea38c320d7399f0c301627fdd_Traceguids, v6);
    }
  }
  else
  {
    *(_DWORD *)(a1 + 8) = v6;
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"(*", // g_EnableDiagnosticMode ; "(*"
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 45;
      goto LABEL_57;
    }
  }
  else if ( v6 )
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 4), 8u);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"&(", // g_DisableOnSoftRemove ; "&("
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 46;
      goto LABEL_57;
    }
  }
  else if ( !v6 )
  {
    _InterlockedAnd((volatile signed __int32 *)(a1 + 4), 0xFFFFFF7F);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"\"$", // g_DisableUxdSupport ; "\"$"
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 47;
      goto LABEL_57;
    }
  }
  else if ( v6 )
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x10u);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"02", // g_EnableExtendedValidation ; "02"
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 48;
      goto LABEL_57;
    }
  }
  else
  {
    v4 = v6;
    if ( v6 )
    {
      _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x20u);
      v4 = v6;
    }
    if ( (v4 & 8) != 0 )
    {
      _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x2000u);
      v4 = v6;
    }
    if ( (v4 & 4) != 0 )
      _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x4000u);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, void *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             &g_WakeOnConnectUI, // WakeOnConnectUI
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result != -1073741772 )
    {
      if ( WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
        goto LABEL_58;
      v5 = 49;
      goto LABEL_57;
    }
  }
  else if ( v6 )
  {
    _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x40u);
  }
  v6 = 0;
  result = (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS, __int64, const wchar_t *, __int64, int *, _QWORD, _QWORD))(WdfFunctions_01015 + 1880))(
             WdfDriverGlobals,
             v7,
             L"NP", // g_PreventDebounceTimeForSuperSpeedDevices ; "NP"
             4LL,
             &v6,
             0LL,
             0LL);
  if ( (int)result < 0 )
  {
    if ( (_DWORD)result == -1073741772 || WPP_RECORDER_INITIALIZED == (_UNKNOWN *)&WPP_RECORDER_INITIALIZED )
      goto LABEL_58;
    v5 = 50;
LABEL_57:
    LOBYTE(v3) = 2;
    result = WPP_RECORDER_SF_d(
               *(_QWORD *)(a1 + 64),
               v3,
               2,
               v5,
               (__int64)&WPP_f014620ea38c320d7399f0c301627fdd_Traceguids,
               result);
    goto LABEL_58;
  }
  if ( v6 )
    _InterlockedOr((volatile signed __int32 *)(a1 + 4), 0x10000u);
LABEL_58:
  if ( v7 )
    return (*(__int64 (__fastcall **)(PWDF_DRIVER_GLOBALS))(WdfFunctions_01015 + 1848))(WdfDriverGlobals);
  return result;
}
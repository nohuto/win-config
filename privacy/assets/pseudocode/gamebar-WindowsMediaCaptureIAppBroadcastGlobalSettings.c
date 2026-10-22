// Hidden C++ exception states: #wind=6
__int64 __fastcall Windows::Media::Capture::AppBroadcastGlobalSettings::ApplySettings(
        struct Windows::Media::Capture::IAppBroadcastGlobalSettings *a1,
        bool *a2,
        bool *a3,
        _BYTE *result)
{
  LSTATUS v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  int v11; // r9d
  double v12; // xmm0_8
  unsigned __int64 v13; // rax
  double v14; // xmm0_8
  unsigned __int64 v15; // rax
  struct Windows::Media::Capture::IAppBroadcastGlobalSettings *v16; // rcx
  unsigned int resulta; // [rsp+28h] [rbp-49h]
  unsigned int resultb; // [rsp+28h] [rbp-49h]
  unsigned int resultc; // [rsp+28h] [rbp-49h]
  unsigned int resultd; // [rsp+28h] [rbp-49h]
  unsigned __int64 resulte; // [rsp+28h] [rbp-49h]
  unsigned __int64 resultf; // [rsp+28h] [rbp-49h]
  unsigned int resultg; // [rsp+28h] [rbp-49h]
  unsigned int resulth; // [rsp+28h] [rbp-49h]
  unsigned int resulti; // [rsp+28h] [rbp-49h]
  struct Windows::Internal::String *resultj; // [rsp+28h] [rbp-49h]
  _BYTE v28[8]; // [rsp+48h] [rbp-29h] BYREF
  HKEY phkResult; // [rsp+50h] [rbp-21h] BYREF
  double v30; // [rsp+58h] [rbp-19h] BYREF
  double v31; // [rsp+60h] [rbp-11h] BYREF
  struct Windows::Media::Capture::IAppBroadcastGlobalSettings *v32; // [rsp+68h] [rbp-9h] BYREF
  unsigned int v33; // [rsp+70h] [rbp-1h] BYREF
  unsigned int v34; // [rsp+74h] [rbp+3h] BYREF
  HSTRING string[10]; // [rsp+78h] [rbp+7h] BYREF
  unsigned __int8 v36; // [rsp+D8h] [rbp+67h] BYREF
  unsigned __int8 v37; // [rsp+E0h] [rbp+6Fh] BYREF
  unsigned __int8 v38; // [rsp+E8h] [rbp+77h] BYREF
  unsigned __int8 v39; // [rsp+F0h] [rbp+7Fh] BYREF

  v32 = 0LL;
  string[1] = (HSTRING)a1;
  if ( a1 )
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *))(*(_QWORD *)a1 + 8LL))(a1);
  string[0] = 0LL;
  v36 = 1;
  *a2 = 0;
  *a3 = 0;
  *result = 0;
  phkResult = 0LL;
  v8 = RegOpenCurrentUser(0x2001Fu, &phkResult);
  if ( v8 )
  {
    v9 = (unsigned __int16)v8 | 0x80070000;
    if ( v8 <= 0 )
      v9 = v8;
    BcastDVRLogProviderBase::LogErrorEx(
      v9,
      "Windows::Media::Capture::AppBroadcastGlobalSettings::ApplySettings",
      "multimedia\\bcastdvr\\server\\lib\\appbroadcastglobalsettings.cpp",
      60,
      "IFCNET",
      "::RegOpenCurrentUser(KEY_READ | KEY_WRITE, &hKeyCurrentUser)",
      1);
  }
  else
  {
    v10 = Microsoft::WRL::Details::MakeAndInitialize<Windows::Media::Capture::AppBroadcastGlobalSettings,Windows::Media::Capture::IAppBroadcastGlobalSettings,>(&v32);
    v9 = v10;
    if ( v10 >= 0 )
    {
      v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 88LL))(
              a1,
              &v37);
      v9 = v10;
      if ( v10 >= 0 )
      {
        v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 104LL))(
                a1,
                &v38);
        v9 = v10;
        if ( v10 >= 0 )
        {
          v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 120LL))(
                  a1,
                  &v39);
          v9 = v10;
          if ( v10 >= 0 )
          {
            v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, double *))(*(_QWORD *)a1 + 136LL))(
                    a1,
                    &v30);
            v9 = v10;
            if ( v10 >= 0 )
            {
              v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, double *))(*(_QWORD *)a1 + 152LL))(
                      a1,
                      &v31);
              v9 = v10;
              if ( v10 >= 0 )
              {
                v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, _BYTE *))(*(_QWORD *)a1 + 168LL))(
                        a1,
                        v28);
                v9 = v10;
                if ( v10 >= 0 )
                {
                  v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, HSTRING *))(*(_QWORD *)a1 + 184LL))(
                          a1,
                          string);
                  v9 = v10;
                  if ( v10 >= 0 )
                  {
                    v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned int *))(*(_QWORD *)a1 + 200LL))(
                            a1,
                            &v33);
                    v9 = v10;
                    if ( v10 >= 0 )
                    {
                      v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned int *))(*(_QWORD *)a1 + 216LL))(
                              a1,
                              &v34);
                      v9 = v10;
                      if ( v10 >= 0 )
                      {
                        v10 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 232LL))(
                                a1,
                                &v36);
                        v9 = v10;
                        if ( v10 >= 0 )
                        {
                          if ( fmin(2.0, v30) >= 0.0 )
                          {
                            if ( v30 > 2.0 )
                              v30 = DOUBLE_2_0;
                          }
                          else
                          {
                            v30 = 0.0;
                          }
                          if ( fmin(2.0, v31) >= 0.0 )
                          {
                            if ( v31 > 2.0 )
                              v31 = DOUBLE_2_0;
                          }
                          else
                          {
                            v31 = 0.0;
                          }
                          v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                  (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                  (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                  L"AudioCaptureEnabled",
                                  (const unsigned __int16 *)v37,
                                  resulta);
                          v9 = v10;
                          if ( v10 >= 0 )
                          {
                            v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                    (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                    (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                    L"MicrophoneCaptureEnabledByDefault",
                                    (const unsigned __int16 *)v38,
                                    resultb);
                            v9 = v10;
                            if ( v10 >= 0 )
                            {
                              v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                      (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                      (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                      L"EchoCancellationEnabled",
                                      (const unsigned __int16 *)v39,
                                      resultc);
                              v9 = v10;
                              if ( v10 >= 0 )
                              {
                                v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                        (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                        (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                        L"CursorCaptureEnabled",
                                        (const unsigned __int16 *)v36,
                                        resultd);
                                v9 = v10;
                                if ( v10 >= 0 )
                                {
                                  v12 = v30 * 10000.0;
                                  v13 = 0LL;
                                  if ( v30 * 10000.0 >= 9.223372036854776e18 )
                                  {
                                    v12 = v12 - 9.223372036854776e18;
                                    if ( v12 < 9.223372036854776e18 )
                                      v13 = 0x8000000000000000uLL;
                                  }
                                  v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetQwordValue(
                                          (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                          (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                          L"SystemAudioGain",
                                          (const unsigned __int16 *)(v13 + (unsigned int)(int)v12),
                                          resulte);
                                  v9 = v10;
                                  if ( v10 >= 0 )
                                  {
                                    v14 = v31 * 10000.0;
                                    v15 = 0LL;
                                    if ( v31 * 10000.0 >= 9.223372036854776e18 )
                                    {
                                      v14 = v14 - 9.223372036854776e18;
                                      if ( v14 < 9.223372036854776e18 )
                                        v15 = 0x8000000000000000uLL;
                                    }
                                    v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetQwordValue(
                                            (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                            (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                            L"MicrophoneGain",
                                            (const unsigned __int16 *)(v15 + (unsigned int)(int)v14),
                                            resultf);
                                    v9 = v10;
                                    if ( v10 >= 0 )
                                    {
                                      v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                              (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                              (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                              L"CameraCaptureEnabledByDefault",
                                              (const unsigned __int16 *)v28[0],
                                              resultg);
                                      v9 = v10;
                                      if ( v10 >= 0 )
                                      {
                                        v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                                (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                                L"CameraOverlayLocation",
                                                (const unsigned __int16 *)v33,
                                                resulth);
                                        v9 = v10;
                                        if ( v10 >= 0 )
                                        {
                                          v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                  (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                                  (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                                  L"CameraOverlaySize",
                                                  (const unsigned __int16 *)v34,
                                                  resulti);
                                          v9 = v10;
                                          if ( v10 >= 0 )
                                          {
                                            v10 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetStringValue(
                                                    (Windows::Media::Capture::Internal::GameDVRUtility *)phkResult,
                                                    (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\AppBroadcast\\GlobalSettings",
                                                    L"SelectedCameraId",
                                                    (const unsigned __int16 *)string,
                                                    resultj);
                                            v9 = v10;
                                            if ( v10 >= 0 )
                                            {
                                              v10 = Windows::Media::Capture::AppBroadcastGlobalSettings::CompareSettings(
                                                      v32,
                                                      a1,
                                                      a2,
                                                      a3,
                                                      (INT32)result);
                                              v9 = v10;
                                              if ( v10 >= 0 )
                                                goto LABEL_66;
                                              v11 = 101;
                                            }
                                            else
                                            {
                                              v11 = 98;
                                            }
                                          }
                                          else
                                          {
                                            v11 = 97;
                                          }
                                        }
                                        else
                                        {
                                          v11 = 96;
                                        }
                                      }
                                      else
                                      {
                                        v11 = 95;
                                      }
                                    }
                                    else
                                    {
                                      v11 = 93;
                                    }
                                  }
                                  else
                                  {
                                    v11 = 90;
                                  }
                                }
                                else
                                {
                                  v11 = 86;
                                }
                              }
                              else
                              {
                                v11 = 85;
                              }
                            }
                            else
                            {
                              v11 = 84;
                            }
                          }
                          else
                          {
                            v11 = 83;
                          }
                        }
                        else
                        {
                          v11 = 75;
                        }
                      }
                      else
                      {
                        v11 = 74;
                      }
                    }
                    else
                    {
                      v11 = 73;
                    }
                  }
                  else
                  {
                    v11 = 72;
                  }
                }
                else
                {
                  v11 = 71;
                }
              }
              else
              {
                v11 = 70;
              }
            }
            else
            {
              v11 = 69;
            }
          }
          else
          {
            v11 = 68;
          }
        }
        else
        {
          v11 = 67;
        }
      }
      else
      {
        v11 = 66;
      }
    }
    else
    {
      v11 = 63;
    }
    BcastDVRLogProviderBase::LogError(
      v10,
      "Windows::Media::Capture::AppBroadcastGlobalSettings::ApplySettings",
      "multimedia\\bcastdvr\\server\\lib\\appbroadcastglobalsettings.cpp",
      v11,
      1);
  }
LABEL_66:
  if ( phkResult )
    RegCloseKey(phkResult);
  if ( string[0] )
    WindowsDeleteString(string[0]);
  if ( a1 )
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *))(*(_QWORD *)a1 + 16LL))(a1);
  v16 = v32;
  if ( v32 )
  {
    v32 = 0LL;
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppBroadcastGlobalSettings *))(*(_QWORD *)v16 + 16LL))(v16);
  }
  return v9;
}
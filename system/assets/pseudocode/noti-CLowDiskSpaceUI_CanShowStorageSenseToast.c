 Hidden C++ exception states #wind=8
__int64 __fastcall CLowDiskSpaceUI_CanShowStorageSenseToast(__int64 a1, int a2)
{
  unsigned int v4;  esi
  CLowDiskSpaceUI v5;  rcx
  CLowDiskSpaceUI v6;  rcx
  CLowDiskSpaceUI v7;  rcx
  const unsigned __int16 v8;  r8
  CLowDiskSpaceUI v10;  rcx
  CLowDiskSpaceUI v11;  rcx
  CLowDiskSpaceUI v12;  rcx
  struct _FILETIME v13;  rbx
  int (__fastcall v14)(struct _FILETIME, __int64 );  rdi
  unsigned int v15;  r15d
  __int64 v16;  rbx
  int (__fastcall v17)(__int64, _QWORD, GUID , struct _FILETIME );  rdi
  struct _FILETIME v18;  rbx
  int (__fastcall v19)(struct _FILETIME, __int64 );  rdi
  LPVOID v20;  rbx
  int (__fastcall v21)(LPVOID, __int64, _QWORD, __int64 );  rdi
  CLowDiskSpaceUI v22;  rcx
  CLowDiskSpaceUI v23;  rcx
  CLowDiskSpaceUI v24;  rcx
  CLowDiskSpaceUI v25;  rcx
  CLowDiskSpaceUI v26;  rcx
  CLowDiskSpaceUI v27;  rcx
  struct _SECURITY_ATTRIBUTES pcbData;  [rsp+38h] [rbp-D0h]
  unsigned int v29;  [rsp+48h] [rbp-C0h] BYREF
  int v30;  [rsp+4Ch] [rbp-BCh] BYREF
  int v31;  [rsp+50h] [rbp-B8h] BYREF
  unsigned int v32;  [rsp+54h] [rbp-B4h] BYREF
  unsigned int v33[2];  [rsp+58h] [rbp-B0h] BYREF
  __int64 v34;  [rsp+60h] [rbp-A8h] BYREF
  unsigned int v35;  [rsp+68h] [rbp-A0h] BYREF
  FILETIME FileTime2;  [rsp+70h] [rbp-98h] BYREF
  struct _FILETIME v37;  [rsp+78h] [rbp-90h] BYREF
  unsigned int v38;  [rsp+80h] [rbp-88h] BYREF
  struct _FILETIME v39;  [rsp+88h] [rbp-80h] BYREF
  LPVOID ppv;  [rsp+90h] [rbp-78h] BYREF
  unsigned int v41;  [rsp+98h] [rbp-70h] BYREF
  unsigned int v42;  [rsp+9Ch] [rbp-6Ch] BYREF
  unsigned int v43;  [rsp+A0h] [rbp-68h] BYREF
  __int64 v44;  [rsp+A8h] [rbp-60h] BYREF
  __int64 v45;  [rsp+B0h] [rbp-58h]
  __int64 v46;  [rsp+B8h] [rbp-50h]
  DWORD v47;  [rsp+C0h] [rbp-48h] BYREF
  struct _FILETIME SystemTimeAsFileTime;  [rsp+C8h] [rbp-40h] BYREF
  __int64 v49;  [rsp+D0h] [rbp-38h] BYREF
  __int64 v50;  [rsp+D8h] [rbp-30h]
  __int64 v51;  [rsp+E0h] [rbp-28h]
  FILETIME FileTime1;  [rsp+E8h] [rbp-20h] BYREF
  WCHAR pszPath[264];  [rsp+F8h] [rbp-10h] BYREF

  v47 = 8;
  v4 = 0;
  v38 = 0;
  v33[0] = 0;
  v32 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v29 = 0;
  switch ( a2 )
  {
    case 6
      LUAIsUserUACAdmin(&v29);
      if ( !v29 )
        return 0LL;
      memset_0(pszPath, 0, 0x208uLL);
      if ( !(_DWORD )(a1 + 40)
         (int)StringCchPrintfW(pszPath, 0x104uLL, L%cWindows.old, (unsigned __int16 )(a1 + 12))  0
         !PathFileExistsW(pszPath) )
      {
        return 0LL;
      }
      break;
    case 5
      v29 = 0;
      if ( (int)CLowDiskSpaceUI_GetIsMDMConfigured((CLowDiskSpaceUI )a1, LAllowStorageSenseGlobal, (int )&v29) = 0
        && v29 )
      {
        return 0LL;
      }
      v30 = 0;
      if ( (int)GetStoragePolicySettings(0LL, 0LL, &v30) = 0 && v30 == 1 )
        return 0LL;
      if ( (int)SHRegGetDWORD(
                  HKEY_CURRENT_USER,
                  LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                  LStoragePoliciesNotified,
                  &v32) = 0
        && v32 == 1
         (int)SHRegGetFILETIME(
                  HKEY_CURRENT_USER,
                  LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
                  LLastInstallTimeLowStorageNotify,
                  &FileTime2) = 0
        && CLowDiskSpaceUI_DurationFromNow(v7, &FileTime2)  0xC92A69C000LL )
      {
        return 0LL;
      }
      v8 = LOptinToastFired;
      return (int)SHRegGetDWORD(
                    HKEY_CURRENT_USER,
                    LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                    v8,
                    v33)  0
           !v33[0];
    case 12
      v30 = 0;
      if ( (int)CLowDiskSpaceUI_GetIsMDMConfigured((CLowDiskSpaceUI )a1, LAllowStorageSenseGlobal, &v30) = 0
        && v30 )
      {
        return 0LL;
      }
      if ( CLowDiskSpaceUI_GetOOBETime(v10, &v37) = 0
        && CLowDiskSpaceUI_DurationFromNow(v11, &v37)  0xC92A69C000LL )
      {
        return 0LL;
      }
      v29 = 0;
      if ( (int)GetStoragePolicySettings(0LL, 0LL, &v29)  0
         !v29
         (int)SHRegGetDWORD(
                  HKEY_CURRENT_USER,
                  LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                  LStoragePoliciesNotified,
                  &v32) = 0
        && v32 == 1 )
      {
        return 0LL;
      }
      if ( (int)SHRegGetDWORD(
                  HKEY_CURRENT_USER,
                  LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                  LStoragePoliciesChanged,
                  &v41) = 0
        && v41 == 1 )
      {
        return 0LL;
      }
      v8 = LFirstLaunchToastFired;
      return (int)SHRegGetDWORD(
                    HKEY_CURRENT_USER,
                    LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                    v8,
                    v33)  0
           !v33[0];
    case 8
      v30 = 0;
      if ( (int)CLowDiskSpaceUI_GetIsMDMConfigured(
                  (CLowDiskSpaceUI )a1,
                  LConfigStorageSenseCloudContentDehydrationThreshold,
                  &v30)  0
         !v30 )
      {
        v31 = 0;
        if ( (int)GetStoragePolicySettings(0LL, 0LL, &v31) = 0
          && v31
          && ((int)SHRegGetFILETIME(
                     HKEY_CURRENT_USER,
                     LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
                     LLastInstallTimeLowStorageNotify,
                     &FileTime2)  0
            CLowDiskSpaceUI_DurationFromNow(v12, &FileTime2) = 0xC92A69C000LL)
          && ((int)SHRegGetDWORD(
                     HKEY_CURRENT_USER,
                     LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                     LCloudfilePolicyConsent,
                     &v42)  0
            !v42)
          && ((int)SHRegGetDWORD(
                     HKEY_CURRENT_USER,
                     LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
                     LCloudConsentToastCount,
                     &v43)  0
            v43  3) )
        {
          ppv = 0LL;
          v37 = 0LL;
          v34 = 0LL;
          v39 = 0LL;
          v44 = 0LL;
          v45 = 0LL;
          v46 = 0LL;
          v49 = 0LL;
          v50 = 0LL;
          v51 = 0LL;
          v29 = 0;
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
          if ( CoCreateInstance(&CLSID_SyncRootManager, 0LL, 1u, &GUID_692d40a4_efa1_4089_88f8_15fd6f5f8b64, &ppv) = 0
            && (int)MicrosoftWRLComPtrISyncRootManagerAsISyncRootManagerPriv(&ppv, &v37) = 0 )
          {
            v13 = v37;
            v14 = (int (__fastcall )(struct _FILETIME, __int64 ))((_QWORD )&v37 + 24LL);
            MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v34);
            if ( ((__int64 (__fastcall )(_QWORD, _QWORD))v14)(v13, &v34) = 0
              && ((int (__fastcall )(__int64, unsigned int ))((_QWORD )v34 + 24LL))(v34, &v29) = 0
              && v29 )
            {
              v15 = 0;
              while ( 1 )
              {
                v16 = v34;
                v17 = (int (__fastcall )(__int64, _QWORD, GUID , struct _FILETIME ))((_QWORD )v34 + 32LL);
                MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v39);
                if ( v17(v16, v15, &GUID_ca01c124_2769_4576_bf12_8a54ee671a86, &v39) = 0 )
                {
                  v18 = v39;
                  v19 = (int (__fastcall )(struct _FILETIME, __int64 ))((_QWORD )&v39 + 24LL);
                  WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v44);
                  v45 = -1LL;
                  v46 = -1LL;
                  if ( ((__int64 (__fastcall )(_QWORD, _QWORD))v19)(v18, &v44) = 0 )
                  {
                    v20 = ppv;
                    v21 = (int (__fastcall )(LPVOID, __int64, _QWORD, __int64 ))((_QWORD )ppv + 136LL);
                    WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v49);
                    v50 = -1LL;
                    v51 = -1LL;
                    if ( v21(v20, v44, 0LL, &v49) = 0 )
                    {
                      v30 = 0;
                      if ( (int)GetStoragePolicySettings(1LL, v44, &v30) = 0 && v30 )
                      {
LABEL_64
                        WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v49);
                        WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v44);
                        goto LABEL_65;
                      }
                      SystemTimeAsFileTime = 0LL;
                      v35 = 0;
                      if ( (int)CfGetSyncRootInfoByPath(v49, 0LL, &SystemTimeAsFileTime, 8LL, &v35) = 0 )
                        break;
                    }
                  }
                }
                if ( ++v15 = v29 )
                  goto LABEL_64;
              }
              WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v49);
              WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v44);
              v4 = 1;
LABEL_65
              MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v39);
              MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v34);
              MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v37);
              MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
              return v4;
            }
          }
          WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v49);
          WindowsInternalNativeStringWindowsInternalCoTaskMemPolicyunsigned short_Free(&v44);
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v39);
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v34);
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v37);
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
        }
      }
      return 0LL;
    case 9
      v29 = 0;
      if ( (int)SHRegGetDWORD(
                  HKEY_LOCAL_MACHINE,
                  LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
                  LTestBackupReminderToast,
                  &v29) = 0
        && v29
        && ((unsigned int)CLowDiskSpaceUIIsBackupReminderEnabled(v22)  v29 == 2) )
      {
        if ( (int)SHRegGetFILETIME(
                    HKEY_CURRENT_USER,
                    LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
                    LFirstProfileSeenTime,
                    &v37) = 0 )
        {
          if ( CLowDiskSpaceUI_DurationFromNow(v23, &v37) = 0x8F0D1800 )
          {
            v31 = 0;
            v30 = 0;
            LODWORD(v34) = 0;
            if ( ((int)CLowDiskSpaceUI_GetIsFHConfigured((CLowDiskSpaceUI )0x8F0D1800LL, &v31)  0  !v31)
              && ((int)CLowDiskSpaceUI_GetIsWin7BackupConfigured(v24, &v30)  0  !v30)
              && ((int)CLowDiskSpaceUI_GetIsKFMEnrolled(v25, (int )&v34)  0  !(_DWORD)v34) )
            {
              v35 = 0;
              if ( (int)SHRegGetDWORD(
                          HKEY_CURRENT_USER,
                          LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
                          LBackupReminderToastCount,
                          &v35)  0
                 v35  3 )
              {
                if ( (int)SHRegGetFILETIME(
                            HKEY_CURRENT_USER,
                            LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
                            LLastInstallTimeLowStorageNotify,
                            &FileTime2) = 0 )
                  CLowDiskSpaceUI_DurationFromNow(v26, &FileTime2);
                if ( (int)SHRegGetFILETIME(
                            HKEY_CURRENT_USER,
                            LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
                            LLastTimeBackupReminderNotify,
                            &v39)  0
                   CLowDiskSpaceUI_DurationFromNow(v27, &v39) = 0x47868C00 )
                {
                  return 1LL;
                }
              }
            }
          }
        }
        else
        {
          GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
          _RegSetKeyValueWithSDDL(
            HKEY_CURRENT_USER,
            LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
            LFirstProfileSeenTime,
            3u,
            &SystemTimeAsFileTime,
            8u,
            pcbData);
        }
      }
      return 0LL;
  }
  if ( RegGetValueW(
         HKEY_LOCAL_MACHINE,
         LSoftwareMicrosoftWindows NTCurrentVersion,
         LInstallTime,
         0x40u,
         0LL,
         &FileTime1,
         &v47)  0
     CLowDiskSpaceUI_DurationFromNow(v5, &FileTime1)  0x10C388D000LL )
  {
    return 0LL;
  }
  if ( (int)SHRegGetDWORD(
              HKEY_CURRENT_USER,
              LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
              LNumWinOldLowStorageNotify,
              &v38) = 0 )
  {
    if ( (int)SHRegGetFILETIME(
                HKEY_CURRENT_USER,
                LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
                LLastInstallTimeLowStorageNotify,
                &FileTime2)  0 )
    {
LABEL_12
      if ( a2 == 7  v38  3 )
        return 1;
      return v4;
    }
    if ( CLowDiskSpaceUI_DurationFromNow(v6, &FileTime2) = 0xC92A69C000LL )
    {
      if ( CompareFileTime(&FileTime1, &FileTime2) = 0 )
        goto LABEL_12;
      goto LABEL_91;
    }
    return 0LL;
  }
LABEL_91
  v38 = 0;
  SHRegSetDWORD(
    HKEY_CURRENT_USER,
    LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking,
    LNumWinOldLowStorageNotify,
    0);
  return 1LL;
}

// ----------

 Hidden C++ exception states #wind=16
__int64 __fastcall LowDiskNotificationActivationCallbackActivate(
        LowDiskNotificationActivationCallback this,
        const unsigned __int16 a2,
        const unsigned __int16 a3,
        const struct NOTIFICATION_USER_INPUT_DATA a4)
{
  __int64 v5;  rcx
  const unsigned __int16 v6;  r8
  const unsigned __int16 v7;  rdx
  signed int v8;  edi
  __int64 v9;  rbx
  __int64 (__fastcall v10)(__int64, __int64, LPVOID );  rdi
  __int64 v11;  rbx
  __int64 (__fastcall v12)(__int64, LPVOID, __int64 );  rdi
  char v13;  bl
  HRESULT v15;  ebx
  int v16;  eax
  int v17;  esi
  LPVOID v18;  rbx
  __int64 (__fastcall v19)(LPVOID, __int64, __int64 );  rdi
  __int64 v20;  rbx
  __int64 (__fastcall v21)(__int64, __int64, __int64 );  rdi
  char v22;  bl
  int bIgnoreCase;  [rsp+20h] [rbp-E0h]
  HSTRING_HEADER hstringHeader;  [rsp+30h] [rbp-D0h] BYREF
  __int64 v25;  [rsp+48h] [rbp-B8h]
  HSTRING_HEADER v26;  [rsp+50h] [rbp-B0h] BYREF
  __int64 v27;  [rsp+68h] [rbp-98h]
  HSTRING_HEADER v28;  [rsp+70h] [rbp-90h] BYREF
  __int64 v29;  [rsp+88h] [rbp-78h]
  _QWORD v30[40];  [rsp+90h] [rbp-70h] BYREF
  unsigned int v31;  [rsp+1D0h] [rbp+D0h] BYREF
  int v32;  [rsp+1D4h] [rbp+D4h] BYREF
  unsigned int v33;  [rsp+1D8h] [rbp+D8h] BYREF
  LPVOID ppv;  [rsp+1E0h] [rbp+E0h] BYREF
  __int64 v35;  [rsp+1E8h] [rbp+E8h] BYREF
  __int64 v36;  [rsp+1F0h] [rbp+F0h] BYREF
  __int64 v37;  [rsp+1F8h] [rbp+F8h] BYREF
  _QWORD v38[2];  [rsp+200h] [rbp+100h] BYREF
  _OWORD v39[20];  [rsp+210h] [rbp+110h] BYREF
  wildetailsin1diag3 retaddr;  [rsp+378h] [rbp+278h]

  v31 = 0;
  if ( CompareStringOrdinal(a3, -1, LcommandDeleteWinOld_Yes, -1, 0) == 2 )
  {
    v33 = 0;
    v31 = 0;
    v32 = 0;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,int,int(&v32, &v31, &v33);
    wilActivityBaseShell32Logging,1,35184372088832,5,0,_TlgReflectorTag_Param0IsProviderTypeActivityBaseShell32Logging,1,35184372088832,5,0,_TlgReflectorTag_Param0IsProviderType((struct wildetailsIFailureCallback )v39);
    (_QWORD )&v39[0] = &Shell32LoggingTelemetryWinOldLowStorageCleanup`vftable';
    Shell32LoggingTelemetryWinOldLowStorageCleanupStartActivity(
      (Shell32LoggingTelemetryWinOldLowStorageCleanup )v39,
      a3);
    wilActivityBaseShell32Logging,1,35184372088832,5,0,_TlgReflectorTag_Param0IsProviderTypeActivityBaseShell32Logging,1,35184372088832,5,0,_TlgReflectorTag_Param0IsProviderType(
      v30,
      v39);
    v30[0] = &Shell32LoggingTelemetryWinOldLowStorageCleanup`vftable';
    WindowsInternalComTaskPoolQueueTask_lambda_68629a2cfc93c9567073a2a3da4bf69e_(v5, v30);
    Shell32LoggingTelemetryWinOldLowStorageCleanup~WinOldLowStorageCleanup((Shell32LoggingTelemetryWinOldLowStorageCleanup )v30);
    Shell32LoggingTelemetryWinOldLowStorageCleanup~WinOldLowStorageCleanup((Shell32LoggingTelemetryWinOldLowStorageCleanup )v39);
    return 0LL;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandDeleteWinOld_No, -1, 0) == 2 )
  {
    v6 = LNumWinOldLowStorageNotify;
    v7 = LSoftwareMicrosoftWindowsCurrentVersionExplorerDiskSpaceChecking;
    goto LABEL_43;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandStoragePolicies_ReminderToast, -1, 0) == 2 )
  {
    v33 = SHRegSetDWORD(
            HKEY_CURRENT_USER,
            LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
            LOptOutButtonClicked,
            1u);
    v32 = 1;
    v31 = 1;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,long &,int(&v31, &v33, &v32);
    return 0LL;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandLaunchStoragePolicies, -1, 0) == 2 )
  {
    v36 = 0LL;
    v37 = 0LL;
    ppv = 0LL;
    v35 = 0LL;
    v25 = 0LL;
    MicrosoftWRLWrappersHStringReferenceCreateReference(&hstringHeader, LWindows.Foundation.Uri, 0x17u, 0x16u);
    v8 = WindowsFoundationGetActivationFactoryMicrosoftWRLComPtrWindowsFoundationIUriRuntimeClassFactory(
           v25,
           &v37);
    if ( v8  0 )
      goto LABEL_13;
    v9 = v37;
    v10 = (__int64 (__fastcall )(__int64, __int64, LPVOID ))((_QWORD )v37 + 48LL);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
    v27 = 0LL;
    MicrosoftWRLWrappersHStringReferenceCreateReference(&v26, Lms-settingsstoragepolicies, 0x1Cu, 0x1Bu);
    v31 = 3;
    v8 = v10(v9, v27, &ppv);
    if ( v8  0 )
      goto LABEL_13;
    v29 = 0LL;
    MicrosoftWRLWrappersHStringReferenceCreateReference(&v28, LWindows.System.Launcher, 0x18u, 0x17u);
    v31 = 7;
    v8 = WindowsFoundationGetActivationFactoryMicrosoftWRLComPtrWindowsSystemILauncherStatics(v29, &v36);
    if ( v8  0
       (v11 = v36,
          v12 = (__int64 (__fastcall )(__int64, LPVOID, __int64 ))((_QWORD )v36 + 64LL),
          MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v35),
          v8 = v12(v11, ppv, &v35),
          v8  0) )
    {
LABEL_13
      v13 = 0;
    }
    else
    {
      v13 = 1;
    }
    if ( v13 )
      v8 = 0;
    v33 = v8;
    v32 = 0;
    v31 = 2;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,long &,int(&v31, &v33, &v32);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v35);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v37);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v36);
    if ( v8 = 0 )
      return (unsigned int)v8;
    return 0LL;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandLaunchSystemStorage, -1, 0) == 2 )
  {
    ppv = 0LL;
    v39[0] = (_OWORD )Lpage=SettingsPageStorageSenseStorageOverview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[1] = (_OWORD )LtingsPageStorageSenseStorageOverview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[2] = (_OWORD )LeStorageSenseStorageOverview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[3] = (_OWORD )LSenseStorageOverview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[4] = (_OWORD )LrageOverview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[5] = (_OWORD )Lview&target=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[6] = (_OWORD )Lget=SystemSettings_StorageSense_SystemDrive&invoke=true;
    v39[7] = (_OWORD )LemSettings_StorageSense_SystemDrive&invoke=true;
    v39[8] = (_OWORD )Lgs_StorageSense_SystemDrive&invoke=true;
    v39[9] = (_OWORD )LgeSense_SystemDrive&invoke=true;
    v39[10] = (_OWORD )LSystemDrive&invoke=true;
    v39[11] = (_OWORD )Live&invoke=true;
    v39[12] = (_OWORD )Lke=true;
    v32 = 0;
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
    v15 = CoCreateInstance(
            &CLSID_ApplicationActivationManager,
            0LL,
            4u,
            &GUID_2e941141_7f97_4756_ba1d_9decde894a3d,
            &ppv);
    v31 = v15;
    if ( v15 = 0 )
    {
      v15 = CoAllowSetForegroundWindow((IUnknown )ppv, 0LL);
      v31 = v15;
      if ( v15 = 0 )
      {
        v15 = ((__int64 (__fastcall )(LPVOID, const WCHAR , _OWORD , _QWORD, int ))((_QWORD )ppv + 24LL))(
                ppv,
                Lwindows.immersivecontrolpanel_cw5n1h2txyewy!microsoft.windows.immersivecontrolpanel,
                v39,
                0LL,
                &v32);
        if ( v15 = 0 )
          v15 = 0;
        v31 = v15;
      }
    }
    v33 = 0;
    LODWORD(v35) = 3;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,long &,int(&v35, &v31, &v33);
    MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
    if ( v15  0 )
      return 0LL;
    return (unsigned int)v15;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandCloudAgeOut_Enable, -1, 0) == 2 )
  {
    v31 = 0;
    SHRegGetDWORD(
      HKEY_CURRENT_USER,
      LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
      LCloudConsentToastCount,
      &v31);
    LODWORD(v35) = 0;
    v32 = 4;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,int,unsigned long &(&v32, &v35, &v31);
    SHRegSetDWORD(
      HKEY_CURRENT_USER,
      LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
      LCloudConsentToastCount,
      3u);
    SHRegSetDWORD(
      HKEY_CURRENT_USER,
      LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
      LCloudfilePolicyConsent,
      1u);
    v16 = WindowsInternalComTaskPoolQueueTask_lambda_575bad7dabccba58df5b635c3fda9d6c_();
    v15 = v16;
    if ( v16 = 0 )
      return 0LL;
    wildetailsin1diag3Return_Hr(
      retaddr,
      (void )0x8AD,
      (unsigned int)shellshell32lowdisk.cpp,
      (const char )(unsigned int)v16,
      bIgnoreCase);
    return (unsigned int)v15;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandCloudAgeOut_Dismiss, -1, 0) == 2 )
  {
    v31 = 0;
    SHRegGetDWORD(
      HKEY_CURRENT_USER,
      LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy,
      LCloudConsentToastCount,
      &v31);
    LODWORD(v35) = 1223;
    v32 = 4;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,long,unsigned long &(&v32, &v35, &v31);
    v6 = LCloudConsentToastCount;
    v7 = LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersStoragePolicy;
    goto LABEL_43;
  }
  if ( CompareStringOrdinal(a3, -1, LcommandBackup_Enable, -1, 0) != 2 )
  {
    if ( CompareStringOrdinal(a3, -1, LcommandBackup_Dismiss, -1, 0) != 2 )
      return 0LL;
    v33 = 0;
    SHRegGetDWORD(
      HKEY_CURRENT_USER,
      LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
      LBackupReminderToastCount,
      &v33);
    LODWORD(v35) = 1223;
    v32 = 5;
    Shell32LoggingTelemetryStorageToastClicksunsigned long,long,unsigned long &(&v32, &v35, &v33);
    v6 = LBackupReminderToastCount;
    v7 = LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder;
LABEL_43
    SHRegSetDWORD(HKEY_CURRENT_USER, v7, v6, 3u);
    return 0LL;
  }
  v38[0] = 0LL;
  ppv = 0LL;
  v36 = 0LL;
  v37 = 0LL;
  v29 = 0LL;
  MicrosoftWRLWrappersHStringReferenceCreateReference(&v28, LWindows.Foundation.Uri, 0x17u, 0x16u);
  v17 = WindowsFoundationGetActivationFactoryMicrosoftWRLComPtrWindowsFoundationIUriRuntimeClassFactory(
          v29,
          &ppv);
  if ( v17  0 )
    goto LABEL_37;
  v18 = ppv;
  v19 = (__int64 (__fastcall )(LPVOID, __int64, __int64 ))((_QWORD )ppv + 48LL);
  MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v36);
  v27 = 0LL;
  MicrosoftWRLWrappersHStringReferenceCreateReference(&v26, Lms-settingsbackup, 0x13u, 0x12u);
  v31 = 24;
  v17 = v19(v18, v27, &v36);
  if ( v17  0 )
    goto LABEL_37;
  v25 = 0LL;
  MicrosoftWRLWrappersHStringReferenceCreateReference(&hstringHeader, LWindows.System.Launcher, 0x18u, 0x17u);
  v31 = 56;
  v17 = WindowsFoundationGetActivationFactoryMicrosoftWRLComPtrWindowsSystemILauncherStatics(v25, v38);
  if ( v17  0
     (v20 = v38[0],
        v21 = (__int64 (__fastcall )(__int64, __int64, __int64 ))((_QWORD )v38[0] + 64LL),
        MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v37),
        v17 = v21(v20, v36, &v37),
        v17  0) )
  {
LABEL_37
    v22 = 0;
  }
  else
  {
    v22 = 1;
  }
  if ( v22 )
    v17 = 0;
  LODWORD(v35) = v17;
  v33 = 0;
  SHRegGetDWORD(
    HKEY_CURRENT_USER,
    LSoftwareMicrosoftWindowsCurrentVersionStorageSenseParametersBackupReminder,
    LBackupReminderToastCount,
    &v33);
  v32 = 5;
  Shell32LoggingTelemetryStorageToastClicksunsigned long,long &,unsigned long &(&v32, &v35, &v33);
  MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v37);
  MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&v36);
  MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(&ppv);
  MicrosoftWRLComPtrIKnownFolderPropertiesInternalRelease(v38);
  return (unsigned int)v17;
}
__int64 __fastcall SystemSettings::SharedExperiences::SharedExperiencesSingleton::LoadUserSettings(
        SystemSettings::SharedExperiences::SharedExperiencesSingleton *this)
{
  int v1; // esi
  int EnabledAndAuthzLevelSetting; // eax
  int v5; // eax
  int v6; // eax
  __int64 v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rcx
  int DWORD; // eax
  __int64 v11; // rdx
  __int64 v12; // r8
  __int64 v13; // rax
  int v14; // eax
  int v15; // [rsp+20h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+28h] [rbp+0h]
  unsigned int v17; // [rsp+30h] [rbp+8h] BYREF
  unsigned int v18; // [rsp+38h] [rbp+10h] BYREF

  v1 = *((_DWORD *)this + 84);
  if ( v1 >= 0 )
  {
    EnabledAndAuthzLevelSetting = SystemSettings::SharedExperiences::SharedExperiencesSingleton::LoadEnabledAndAuthzLevelSetting(
                                    this,
                                    L"NearShareChannelUserAuthzPolicy",
                                    (bool *)this + 288,
                                    (SystemSettings::SharedExperiences::SharedExperiencesSingleton *)((char *)this + 296));
    if ( EnabledAndAuthzLevelSetting < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x89,
        (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
        (const char *)(unsigned int)EnabledAndAuthzLevelSetting,
        v15);
    v5 = SystemSettings::SharedExperiences::SharedExperiencesSingleton::LoadEnabledAndAuthzLevelSetting(
           this,
           L"RomeSdkChannelUserAuthzPolicy",
           (bool *)this + 289,
           (SystemSettings::SharedExperiences::SharedExperiencesSingleton *)((char *)this + 300));
    if ( v5 < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x8A,
        (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
        (const char *)(unsigned int)v5,
        v15);
    v6 = SystemSettings::SharedExperiences::SharedExperiencesSingleton::LoadNearShareSaveLocation(this);
    if ( v6 < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x8B,
        (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
        (const char *)(unsigned int)v6,
        v15);
    v7 = *((_QWORD *)this + 41);
    v17 = 0;
    v8 = -2147483647LL;
    v9 = -2147483647LL;
    if ( v7 )
      v9 = v7;
    DWORD = SHRegGetDWORD(
              (HKEY)v9,
              L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
              L"BluetoothLastDisabledNearShare",
              &v17);
    if ( DWORD < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x8E,
        (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
        (const char *)(unsigned int)DWORD,
        v15);
    *((_BYTE *)this + 290) = v17 != 0;
    LOBYTE(v12) = 3;
    LOBYTE(v11) = 1;
    wil::details::FeatureImpl<__WilFeatureTraits_Feature_NSTOW>::ReportUsage(
      &`wil::Feature<__WilFeatureTraits_Feature_NSTOW>::GetImpl'::`2'::impl,
      v11,
      v12);
    v13 = *((_QWORD *)this + 41);
    v18 = 0;
    if ( v13 )
      v8 = v13;
    v14 = SHRegGetDWORD(
            (HKEY)v8,
            L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
            L"WifiLastDisabledNearShare",
            &v18);
    if ( v14 < 0 )
      wil::details::in1diag3::_Log_Hr(
        retaddr,
        (void *)0x94,
        (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
        (const char *)(unsigned int)v14,
        v15);
    *((_BYTE *)this + 291) = v18 != 0;
    return 0LL;
  }
  else
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x87,
      (unsigned int)"onecoreuap\\shell\\coresettinghandlers\\sharedexperiences\\lib\\sharedexperiencessingleton.cpp",
      (const char *)(unsigned int)v1,
      v15);
    return (unsigned int)v1;
  }
}
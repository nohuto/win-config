char *__fastcall HalpMiscGetParameters(__int64 a1)
{
  char *result; // rax
  const char *v3; // rdi
  char *v4; // rax
  char v5; // cl
  unsigned int v6; // eax
  char *v7; // rax
  char v8; // cl
  int v9; // eax
  __int64 v10; // rcx
  bool v16; // zf
  char *v17; // rax
  char v18; // cl
  _BYTE v19[24]; // [rsp+20h] [rbp-28h] BYREF

  if ( (unsigned int)HalpInterruptModel() == 1 )
    HalpMiscDiscardLowMemory = 1;
  result = (char *)HalpProcIsSmtDisabled(a1);
  HalpInterruptBlockHyperthreading = (char)result;
  if ( a1 )
  {
    if ( (_BYTE)result )
    {
      result = *(char **)(a1 + 240);
      if ( (*((_DWORD *)result + 33) & 0x200) == 0 )
        HalpInterruptStartHyperthreadSiblings = 1;
    }
    v3 = *(const char **)(a1 + 216);
    if ( v3 )
    {
      strstr(*(const char **)(a1 + 216), "SAFEBOOT:");
      if ( strstr(v3, "ONECPU") )
        HalpInterruptProcessorCap = 1;
      if ( strstr(v3, "USEPHYSICALAPIC") )
        HalpInterruptPhysicalModeOnly = 1;
      if ( strstr(v3, "BREAK") )
        HalpMiscDebugBreakRequested = 1;
      v4 = strstr(v3, "MAXPROCSPERCLUSTER");
      if ( v4 )
      {
        while ( 1 )
        {
          v5 = *v4;
          if ( !*v4 || v5 == 32 || (unsigned __int8)(v5 - 48) <= 9u )
            break;
          ++v4;
        }
        v6 = atoi(v4);
        HalpInterruptForceClusterMode(v6);
      }
      v7 = strstr(v3, "MAXAPICCLUSTER");
      if ( v7 )
      {
        while ( 1 )
        {
          v8 = *v7;
          if ( !*v7 || v8 == 32 || (unsigned __int8)(v8 - 48) <= 9u )
            break;
          ++v7;
        }
        v9 = atoi(v7);
        if ( v9 )
          LODWORD(HalpInterruptMaxCluster) = v9;
      }
      if ( strstr(v3, "X2APICPOLICY=ENABLE") )
        HalpInterruptX2ApicPolicy = 1;
      if ( strstr(v3, "X2APICPOLICY=DISABLE") )
        HalpInterruptX2ApicPolicy = 0;
      if ( strstr(v3, "USELEGACYAPICMODE") )
        HalpInterruptX2ApicPolicy = 0;
      if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=DISABLED") )
      {
        HalpTimerWatchdogDisable = 1;
      }
      else if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=PHYSICALONLY") )
      {
        HalpTimerWatchdogPhysicalOnly = 1;
      }
      if ( strstr(v3, "CONFIGACCESSPOLICY=DISALLOWMMCONFIG") )
        HalpAvoidMmConfigAccessMethod = 1;
      if ( strstr(v3, "MSIPOLICY=FORCEDISABLE") )
      {
        v10 = 0LL;
      }
      else
      {
        if ( !strstr(v3, "FORCEMSI") )
          goto LABEL_46;
        LOBYTE(v10) = 1;
      }
      HalpInterruptSetMsiOverride(v10);
LABEL_46:
      if ( !(unsigned __int8)HalpIsHvPresent() )
        goto LABEL_51;
      HalpHvPresent = 1;
      if ( (unsigned __int8)HalpIsPartitionCpuManager() )
        HalpHvCpuManager = 1;
      if ( (unsigned __int8)HalpIsMicrosoftCompatibleHvLoaded() )
      {
        _RAX = 1073741828LL;
        __asm { cpuid }
        v16 = (_RAX & 0x10) == 0;
      }
      else
      {
LABEL_51:
        v16 = (unsigned __int8)HalpIsXboxNanovisorPresent() == 0;
      }
      if ( !v16 )
        HalpHvUsedForReboot = 1;
      if ( HalpHvCpuManager )
      {
        v19[0] = 0;
        if ( (unsigned __int8)HalpGetCpuInfo(0LL, 0LL, 0LL, v19) )
        {
          if ( v19[0] == 2 && (__readmsr(0xFEu) & 0x8000) != 0 )
            HalpMiscDiscardLowMemory = 1;
        }
      }
      if ( strstr(v3, "FIRSTMEGABYTEPOLICY=USEALL")
        || (unsigned __int8)HalpIsMicrosoftCompatibleHvLoaded() && !HalpHvCpuManager )
      {
        HalpMiscDiscardLowMemory = 0;
      }
      if ( strstr(v3, "USEPLATFORMCLOCK") )
        HalpTimerPlatformSourceForced = 1;
      if ( strstr(v3, "USEPLATFORMTICK") )
        HalpTimerPlatformClockSourceForced = 1;
      v17 = strstr(v3, "GROUPSIZE");
      if ( v17 )
      {
        while ( 1 )
        {
          v18 = *v17;
          if ( !*v17 || v18 == 32 || (unsigned __int8)(v18 - 48) <= 9u )
            break;
          ++v17;
        }
        HalpMaximumGroupSize = atoi(v17);
        if ( (unsigned int)(HalpMaximumGroupSize - 1) > 0x3F )
          HalpMaximumGroupSize = 64;
      }
      HalpSplitLargeNumaNodes = (*(_DWORD *)(*(_QWORD *)(a1 + 240) + 132LL) & 0x20000) != 0;
      strstr(v3, "HALTPROFILINGPOLICY=BLOCKED");
      strstr(v3, "HALTPROFILINGPOLICY=RELAXED");
      return strstr(v3, "HALTPROFILINGPOLICY=RESTRICTED");
    }
  }
  return result;
}
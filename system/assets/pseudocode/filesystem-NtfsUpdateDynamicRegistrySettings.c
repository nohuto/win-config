void __fastcall NtfsUpdateDynamicRegistrySettings(__int64 a1)
{
  unsigned int v1; // esi
  __int64 v2; // rdi
  __int64 v3; // r15
  int v4; // edi
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // edx
  int v13; // edi
  unsigned int v14; // edi
  int v15; // edi
  unsigned int v16; // r15d
  int v17; // edi
  int v18; // eax
  int v19; // r13d
  __int64 v20; // r12
  unsigned int v21; // edx
  int v22; // ecx
  unsigned int v23; // edx
  int v24; // ecx
  int v25; // edx
  unsigned int v26; // edx
  int v27; // esi
  int v28; // edi
  unsigned int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  unsigned int v35; // ecx
  __int64 v36; // rcx
  unsigned int v37; // eax
  __int64 v38; // rcx
  int v39; // eax
  unsigned int v40; // r8d
  bool v41; // zf
  int v42; // eax
  int v43; // edi
  _BYTE v44[4]; // [rsp+30h] [rbp-448h] BYREF
  int ValueKeyWithFallBack; // [rsp+34h] [rbp-444h]
  int v46; // [rsp+38h] [rbp-440h] BYREF
  PVOID P; // [rsp+40h] [rbp-438h] BYREF
  __int128 v48; // [rsp+48h] [rbp-430h] BYREF
  char v49; // [rsp+58h] [rbp-420h]
  char v50; // [rsp+59h] [rbp-41Fh]
  char v51; // [rsp+5Ah] [rbp-41Eh]
  char v52; // [rsp+5Bh] [rbp-41Dh]
  char v53; // [rsp+5Ch] [rbp-41Ch]
  char v54; // [rsp+5Dh] [rbp-41Bh]
  char v55; // [rsp+5Eh] [rbp-41Ah]
  char v56; // [rsp+5Fh] [rbp-419h]
  char v57; // [rsp+60h] [rbp-418h]
  char v58; // [rsp+61h] [rbp-417h]
  char v59; // [rsp+62h] [rbp-416h]
  char v60; // [rsp+63h] [rbp-415h]
  char v61; // [rsp+64h] [rbp-414h]
  char v62; // [rsp+65h] [rbp-413h]
  __int128 v63; // [rsp+68h] [rbp-410h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+78h] [rbp-400h] BYREF
  unsigned int v65; // [rsp+88h] [rbp-3F0h]
  unsigned int v66; // [rsp+8Ch] [rbp-3ECh]
  unsigned int v67; // [rsp+90h] [rbp-3E8h]
  unsigned int v68; // [rsp+94h] [rbp-3E4h]
  int v69; // [rsp+98h] [rbp-3E0h]
  int v70; // [rsp+9Ch] [rbp-3DCh]
  int v71; // [rsp+A0h] [rbp-3D8h]
  unsigned int v72; // [rsp+A4h] [rbp-3D4h]
  unsigned int v73; // [rsp+A8h] [rbp-3D0h]
  unsigned int v74; // [rsp+ACh] [rbp-3CCh]
  unsigned int v75; // [rsp+B0h] [rbp-3C8h]
  unsigned int v76; // [rsp+B4h] [rbp-3C4h]
  unsigned int v77; // [rsp+B8h] [rbp-3C0h]
  unsigned int v78; // [rsp+BCh] [rbp-3BCh]
  unsigned int v79; // [rsp+C0h] [rbp-3B8h]
  int v80; // [rsp+C4h] [rbp-3B4h]
  unsigned int v81; // [rsp+C8h] [rbp-3B0h]
  __int128 v82; // [rsp+D0h] [rbp-3A8h] BYREF
  int v83; // [rsp+E0h] [rbp-398h]
  int v84[2]; // [rsp+E8h] [rbp-390h]
  unsigned int v85; // [rsp+F0h] [rbp-388h]
  int v86; // [rsp+F4h] [rbp-384h]
  int v87; // [rsp+F8h] [rbp-380h]
  int v88; // [rsp+FCh] [rbp-37Ch]
  int v89; // [rsp+100h] [rbp-378h]
  int v90; // [rsp+104h] [rbp-374h]
  int v91; // [rsp+108h] [rbp-370h]
  int v92; // [rsp+10Ch] [rbp-36Ch]
  int v93; // [rsp+110h] [rbp-368h]
  int v94; // [rsp+114h] [rbp-364h]
  int v95; // [rsp+118h] [rbp-360h]
  int v96; // [rsp+11Ch] [rbp-35Ch]
  unsigned __int64 v97; // [rsp+120h] [rbp-358h]
  int v98; // [rsp+128h] [rbp-350h]
  int v99; // [rsp+12Ch] [rbp-34Ch]
  unsigned int v100; // [rsp+130h] [rbp-348h]
  int v101; // [rsp+134h] [rbp-344h]
  int v102; // [rsp+138h] [rbp-340h]
  int v103; // [rsp+13Ch] [rbp-33Ch]
  int v104; // [rsp+140h] [rbp-338h]
  int v105; // [rsp+144h] [rbp-334h]
  unsigned int v106; // [rsp+148h] [rbp-330h]
  int v107; // [rsp+14Ch] [rbp-32Ch]
  int v108; // [rsp+150h] [rbp-328h]
  int v109; // [rsp+154h] [rbp-324h]
  _OWORD v110[2]; // [rsp+158h] [rbp-320h] BYREF
  __int64 v111; // [rsp+178h] [rbp-300h]
  _BYTE v112[544]; // [rsp+180h] [rbp-2F8h] BYREF
  char v113; // [rsp+3A0h] [rbp-D8h] BYREF

  memset(v112, 0, sizeof(v112));
  *(_QWORD *)v84 = v112;
  memset(v110, 0, sizeof(v110));
  v111 = 0LL;
  v55 = 0;
  DestinationString = 0LL;
  v63 = 0LL;
  v48 = 0LL;
  v46 = 156;
  P = &v113;
  v44[0] = 0;
  v91 = 0;
  v53 = 0;
  v99 = 0;
  v58 = 0;
  v86 = 0;
  v72 = 1;
  v73 = 0;
  v74 = 16;
  v59 = 0;
  v75 = 1;
  v60 = 0;
  v79 = 1;
  v61 = 0;
  v76 = 0;
  v62 = 0;
  v93 = 0;
  v56 = 0;
  v87 = 70;
  v88 = 8;
  v108 = 100000;
  v109 = 25;
  v50 = 0;
  v51 = 0;
  v103 = 0;
  v57 = 0;
  v92 = -2147483645;
  v100 = 0;
  v104 = 3;
  v105 = 0;
  v65 = 0;
  v66 = 0;
  v67 = 0;
  v68 = 0;
  v96 = 0;
  v52 = 0;
  v89 = 30000;
  v49 = 0;
  v85 = 2;
  v81 = 0x4000;
  v83 = 0;
  v97 = 0x40000000LL;
  v1 = 65534;
  v71 = 65534;
  v69 = 32;
  v70 = 512;
  v90 = 4;
  v80 = 0x4000;
  v54 = 0;
  if ( byte_1C00961FA != 1 )
  {
    v69 = 512;
    v70 = 0x2000;
  }
  v2 = NtfsInitializeTopLevelIrp(v110, 0LL, 0LL);
  memset(v112, 0, sizeof(v112));
  if ( (int)NtfsInitializeIrpContextInternal(0LL) >= 0 )
  {
    v3 = *(_QWORD *)v84;
    NtfsUpdateIrpContextWithTopLevel(*(_QWORD *)v84, v2);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&NtfsDynamicRegistrySettingsResource, 1u);
    v82 = *(_OWORD *)L"fh";
    v4 = NtfsInitializeCompatibilityModeKeyPath();
    if ( v4 >= 0 )
    {
      RtlInitUnicodeString(&DestinationString, &NtfsCompatibilityModeKeyPath);
      v63 = *(_OWORD *)L"z|";
      while ( 1 )
      {
        if ( v4 == -1073741432 )
          NtfsCheckpointForLogFileFull(v3);
        if ( v3 )
          NtfsPreRequestProcessingExtend(v3);
        *((_QWORD *)&v48 + 1) = L"DisableDeleteNotification";
        LODWORD(v48) = 3407922;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v91 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        *((_QWORD *)&v48 + 1) = L"DisableDeleteNotificationDrain";
        LODWORD(v48) = 4063292;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
          v99 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"NtfsDisable8dot3NameCreation";
        LODWORD(v48) = 3801144;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack < 0 )
        {
          ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                   (unsigned int)&DestinationString,
                                   (unsigned int)&v63,
                                   (unsigned int)&v48,
                                   (unsigned int)&v46,
                                   (__int64)&P,
                                   (__int64)v44);
          if ( ValueKeyWithFallBack < 0 )
            v5 = 2;
          else
            v5 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        else
        {
          v5 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        if ( v5 > 3 )
          v5 = 2;
        v107 = v5;
        *((_QWORD *)&v48 + 1) = L"NtfsDisableLastAccessUpdate";
        LODWORD(v48) = 3670070;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack < 0 )
        {
          ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                   (unsigned int)&DestinationString,
                                   (unsigned int)&v63,
                                   (unsigned int)&v48,
                                   (unsigned int)&v46,
                                   (__int64)&P,
                                   (__int64)v44);
          if ( ValueKeyWithFallBack >= 0 )
            v92 = *(_DWORD *)((_BYTE *)P + *((unsigned int *)P + 2)) & 0x80000003;
        }
        else
        {
          v92 = *(_DWORD *)((_BYTE *)P + *((unsigned int *)P + 2)) & 1;
          dword_1C0096AE4 |= 0x40000000u;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsLastAccessUpdatePolicyVolumeSizeThreshold";
        LODWORD(v48) = 6029402;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
          v100 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"NtfsForceReadOnlyMount";
        LODWORD(v48) = 3014700;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack < 0 )
          v101 = 0;
        else
          v101 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"NtfsDisableFileMetadataOptimization";
        LODWORD(v48) = 4718662;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v86 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        *((_QWORD *)&v48 + 1) = L"NtfsDisableCompressionDelayedAllocation";
        LODWORD(v48) = 5242958;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v72 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v6 = v72;
        if ( v72 > 1 )
          v6 = 1;
        v72 = v6;
        *((_QWORD *)&v48 + 1) = L"NtfsDisableCompressionLimit";
        LODWORD(v48) = 3670070;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v73 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v7 = v73;
        if ( v73 > 1 )
          v7 = 0;
        v73 = v7;
        *((_QWORD *)&v48 + 1) = L"NtfsDisableSpotCorruptionHandling";
        LODWORD(v48) = 4456514;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v74 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        *((_QWORD *)&v48 + 1) = L"NtfsBypassSpotCorruptionHandlingOnCritical";
        LODWORD(v48) = 5636180;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v75 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v8 = v75;
        if ( v75 > 0xF )
          v8 = 1;
        v75 = v8;
        *((_QWORD *)&v48 + 1) = L"NtfsMaxFspWorkerThreadsPerVolume";
        LODWORD(v48) = 4325440;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v9 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v76 = v9;
          if ( v9 )
          {
            if ( v9 >= 4 )
            {
              if ( v9 > 0x3E8 )
                v9 = 1000;
              v76 = v9;
            }
            else
            {
              v76 = 4;
            }
          }
          else
          {
            v76 = 10;
          }
          v62 = 1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsMinTrimTotalSize";
        LODWORD(v48) = 2752552;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack < 0 )
        {
          v10 = 0x100000;
        }
        else
        {
          v77 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          if ( v77 >= 0x200000 )
            goto LABEL_66;
          v10 = 0x200000;
        }
        v77 = v10;
LABEL_66:
        *((_QWORD *)&v48 + 1) = L"NtfsMaxTrimTotalSize";
        LODWORD(v48) = 2752552;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack < 0 )
        {
          v78 = 0x40000000;
        }
        else
        {
          v78 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          if ( v78 < NtfsMinTrimTotalSize )
            v78 = NtfsMinTrimTotalSize;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsTrimListLengthThreshold";
        LODWORD(v48) = 3670070;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack < 0 )
        {
          v102 = 100000;
        }
        else
        {
          v102 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          if ( (unsigned int)(v102 - 1) <= 0x270E )
            goto LABEL_75;
        }
        v51 = 1;
LABEL_75:
        *((_QWORD *)&v48 + 1) = L"NtfsMaxWaitTimeForDeallocatedClustersInTrim";
        LODWORD(v48) = 5767254;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack < 0 )
          v106 = 60000;
        else
          v106 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"NtfsFlushTrimRequestsOnDismount";
        LODWORD(v48) = 4194366;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        NtfsFlushTrimRequestsOnDismount = ValueKeyWithFallBack >= 0
                                       && *(_DWORD *)((char *)P + *((unsigned int *)P + 2)) == 1;
        *((_QWORD *)&v48 + 1) = L"NtfsAllowMaximumSupportedHardLinks";
        LODWORD(v48) = 4587588;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        NtfsAllowMaximumSupportedHardLinks = ValueKeyWithFallBack >= 0
                                          && *(_DWORD *)((char *)P + *((unsigned int *)P + 2)) == 1;
        *((_QWORD *)&v48 + 1) = L"NtfsDisableTrueAsyncCachedReads";
        LODWORD(v48) = 4194366;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v93 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v56 = 1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsFileMetadataOptimizationThreshold";
        LODWORD(v48) = 4980810;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v11 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v87 = v11;
          if ( v11 >= 0xA )
          {
            if ( v11 > 0x5A )
              v11 = 90;
            v87 = v11;
          }
          else
          {
            v87 = 10;
          }
        }
        *((_QWORD *)&v48 + 1) = L"NtfsMaxFileMetadataOptimizationThread";
        LODWORD(v48) = 4980810;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v12 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v88 = v12;
          if ( v12 )
          {
            if ( v12 > 0x3E8 )
              v12 = 1000;
            v88 = v12;
          }
          else
          {
            v88 = 1;
          }
        }
        *((_QWORD *)&v48 + 1) = L"NtfsEnableDirectAccess";
        LODWORD(v48) = 3014700;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v103 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v57 = 1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsEnableDirCaseSensitivity";
        LODWORD(v48) = 3801144;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
          v104 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"NtfsAllowQueryFreeSpaceConsiderPool";
        LODWORD(v48) = 4718662;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
          v105 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        *((_QWORD *)&v48 + 1) = L"AllowHardLinkWithNoAccess";
        LODWORD(v48) = 3407922;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack < 0
          && (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack < 0) )
        {
          v94 = 0;
        }
        else
        {
          v94 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        *((_QWORD *)&v48 + 1) = L"NtfsParallelFlushThreshold";
        LODWORD(v48) = 3538996;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v65 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        if ( v65 )
        {
          if ( v65 >= 0x64 )
          {
            v13 = v65;
            if ( v65 > 0xF4240 )
              v13 = 1000000;
            v65 = v13;
          }
          else
          {
            v65 = 100;
          }
        }
        else
        {
          v65 = 1000;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsParallelFlushWorkers";
        LODWORD(v48) = 3276848;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v66 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        if ( v66 )
        {
          v14 = v66;
          if ( v66 > 2 * NtfsNumberProcessors )
            v14 = 2 * NtfsNumberProcessors;
        }
        else
        {
          v14 = ((unsigned int)NtfsNumberProcessors >> 1) + 1;
        }
        v66 = v14;
        v95 = v14;
        *((_QWORD *)&v48 + 1) = L"NtfsMinLengthForAZeroWorker";
        LODWORD(v48) = 3670070;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v67 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        if ( v67 )
        {
          v15 = v67;
          if ( v67 < 0x400000 )
            v15 = 0x400000;
          v67 = v15;
        }
        else
        {
          v67 = 0x8000000;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsParallelZeroWorkers";
        LODWORD(v48) = 3145774;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v68 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v16 = 16;
        if ( v68 )
        {
          v17 = v68;
          if ( v68 > 0x10 )
            v17 = 16;
          v68 = v17;
        }
        else
        {
          v68 = 1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsLockSystemFilePages";
        LODWORD(v48) = 3145774;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v79 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v18 = v79;
        if ( v79 > 3 )
          v18 = 1;
        v79 = v18;
        *((_QWORD *)&v48 + 1) = L"NtfsDisableIoPerf";
        LODWORD(v48) = 2359330;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v96 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v52 = 1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsMaxAcceptableLatency";
        LODWORD(v48) = 3276848;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v89 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v49 = 1;
LABEL_154:
          if ( v89 == dword_1C009563C || (unsigned int)(v89 - 1) > 0x1D4BF )
            v49 = 0;
          goto LABEL_157;
        }
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v89 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v49 = 1;
        }
        if ( v49 )
          goto LABEL_154;
LABEL_157:
        *((_QWORD *)&v48 + 1) = L"NtfsKsrVersion";
        LODWORD(v48) = 1966108;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v85 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v19 = v85;
        if ( v85 > 2 )
          v19 = 0;
        v85 = v19;
        *((_QWORD *)&v48 + 1) = L"NtfsMaxDelayCloseCount";
        LODWORD(v48) = 3014700;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
          v81 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        if ( v81 >= 0x10 )
        {
          v16 = v81;
          if ( v81 > 0x4000 )
            v16 = 0x4000;
        }
        v81 = v16;
        *((_QWORD *)&v48 + 1) = L"NtfsCachedRunsBinMaxLengthInBytes";
        LODWORD(v48) = 4456514;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v97 = *(_QWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        if ( v97 )
        {
          v20 = v97;
          if ( v97 < 0x4000000 )
            v20 = 0x4000000LL;
        }
        else
        {
          v20 = 0x40000000LL;
        }
        v97 = v20;
        *((_QWORD *)&v48 + 1) = L"NtfsDefaultTier";
        LODWORD(v48) = 2097182;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v83 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        *((_QWORD *)&v48 + 1) = L"NtfsMaxCachedRuns";
        LODWORD(v48) = 2359330;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v1 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v71 = v1;
          if ( v1 )
          {
            if ( v1 >= 0x2328 )
            {
              if ( v1 > 0xFFFE )
                v1 = 65534;
            }
            else
            {
              v1 = 9000;
            }
          }
          else
          {
            v1 = 65534;
          }
          v71 = v1;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsInitialCachedRuns";
        LODWORD(v48) = 2883626;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v21 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v69 = v21;
          if ( v21 )
          {
            if ( v21 >= 0x20 )
            {
              if ( v21 > v1 )
                v21 = v1;
              v69 = v21;
            }
            else
            {
              v69 = 32;
            }
          }
          else
          {
            v22 = 512;
            if ( byte_1C00961FA == 1 )
              v22 = 32;
            v69 = v22;
          }
        }
        *((_QWORD *)&v48 + 1) = L"NtfsCachedRunsDelta";
        LODWORD(v48) = 2621478;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v23 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v70 = v23;
          if ( v23 )
          {
            if ( v23 >= 0x200 )
            {
              if ( v23 > v1 )
                v23 = v1;
              v70 = v23;
            }
            else
            {
              v70 = 512;
            }
          }
          else
          {
            v24 = 0x2000;
            if ( byte_1C00961FA == 1 )
              v24 = 512;
            v70 = v24;
          }
        }
        *((_QWORD *)&v48 + 1) = L"NtfsCachedRunsLimitMode";
        LODWORD(v48) = 3145774;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v25 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v90 = v25;
          if ( (unsigned int)(v25 - 1) > 3 )
            v25 = 4;
          v90 = v25;
        }
        *((_QWORD *)&v48 + 1) = L"NtfsCachedRunsInsertLimit";
        LODWORD(v48) = 3407922;
        ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                 (unsigned int)&DestinationString,
                                 (unsigned int)&v63,
                                 (unsigned int)&v48,
                                 (unsigned int)&v46,
                                 (__int64)&P,
                                 (__int64)v44);
        if ( ValueKeyWithFallBack >= 0 )
        {
          v26 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
          v80 = v26;
          if ( v26 )
          {
            if ( v26 >= 0x400 )
            {
              if ( v26 > v1 )
                v26 = v1;
              v80 = v26;
            }
            else
            {
              v80 = 1024;
            }
          }
          else
          {
            v80 = 0x4000;
          }
        }
        v27 = 1;
        *((_QWORD *)&v48 + 1) = L"NtfsLimitPhysicalSectorSize";
        LODWORD(v48) = 2097206;
        ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
        if ( ValueKeyWithFallBack >= 0
          || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                       (unsigned int)&DestinationString,
                                       (unsigned int)&v63,
                                       (unsigned int)&v48,
                                       (unsigned int)&v46,
                                       (__int64)&P,
                                       (__int64)v44),
              ValueKeyWithFallBack >= 0) )
        {
          v27 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
        }
        v28 = 0;
        v98 = 0;
        if ( (unsigned int)Feature_1193384250__private_IsEnabledDeviceUsageNoInline() )
        {
          *((_QWORD *)&v48 + 1) = L"EnforceDirectoryChangeNotificationPermissionCheck";
          LODWORD(v48) = 6553698;
          ValueKeyWithFallBack = NtfsQueryValueKey(&v82, &v48, &v46, &P, v44);
          if ( ValueKeyWithFallBack >= 0
            || (ValueKeyWithFallBack = NtfsQueryValueKeyWithFallBack(
                                         (unsigned int)&DestinationString,
                                         (unsigned int)&v63,
                                         (unsigned int)&v48,
                                         (unsigned int)&v46,
                                         (__int64)&P,
                                         (__int64)v44),
                ValueKeyWithFallBack >= 0) )
          {
            v28 = *(_DWORD *)((char *)P + *((unsigned int *)P + 2));
            v98 = v28;
          }
        }
        ExAcquireResourceExclusiveLite(&Resource, 1u);
        v55 = 1;
        v29 = dword_1C00966D8;
        if ( v91 == 1 )
        {
          if ( (dword_1C00966D8 & 0x80000) != 0 )
            goto LABEL_230;
          v29 = dword_1C00966D8 | 0x80000;
        }
        else
        {
          if ( (dword_1C00966D8 & 0x80000) == 0 )
            goto LABEL_230;
          v29 = dword_1C00966D8 & 0xFFF7FFFF;
        }
        dword_1C00966D8 = v29;
        v53 = 1;
LABEL_230:
        if ( v99 == 1 )
          v30 = v29 | 0x20000;
        else
          v30 = v29 & 0xFFFDFFFF;
        dword_1C00966D8 = v30;
        if ( dword_1C00963D4 != v107 )
        {
          dword_1C00963D4 = v107;
          v58 = 1;
        }
        dword_1C0096AE4 = v92;
        qword_1C0096AE8 = (unsigned __int64)v100 << 30;
        if ( v101 )
          v31 = v30 | 0x10;
        else
          v31 = v30 & 0xFFFFFFEF;
        dword_1C00966D8 = v31;
        if ( (v86 & 1) != 0 )
          v32 = v31 | 4;
        else
          v32 = v31 & 0xFFFFFFFB;
        dword_1C00966D8 = v32;
        if ( (v86 & 2) != 0 )
          v33 = v32 | 8;
        else
          v33 = v32 & 0xFFFFFFF7;
        dword_1C00966D8 = v33;
        if ( v72 == 1 )
          v34 = v33 | 0x100;
        else
          v34 = v33 & 0xFFFFFEFF;
        dword_1C00966D8 = v34;
        if ( v73 == 1 )
          v35 = v34 | 0x200;
        else
          v35 = v34 & 0xFFFFFDFF;
        dword_1C00966D8 = v35;
        if ( v74 > 0xF )
          v74 = (v35 >> 14) & 1;
        if ( dword_1C00963D8 != v74 )
        {
          dword_1C00963D8 = v74;
          v59 = 1;
        }
        if ( dword_1C00963DC != v75 )
        {
          dword_1C00963DC = v75;
          v60 = 1;
        }
        if ( v62 && a1 && dword_1C0096AD0 != v76 )
        {
          dword_1C0096AD0 = v76;
          dword_1C0096AE0 = v76 < 0x2EE ? 1000 : 2000;
        }
        v36 = v77;
        if ( NtfsMaxTrimTotalSize < v77 )
        {
          v36 = (unsigned int)NtfsMaxTrimTotalSize;
          v77 = NtfsMaxTrimTotalSize;
          v50 = 1;
        }
        v37 = NtfsMinTrimTotalSize;
        if ( NtfsMinTrimTotalSize != (_DWORD)v36 )
        {
          if ( (!*(_QWORD *)v84 || (*(_DWORD *)(*(_QWORD *)v84 + 16LL) & 0x100000) == 0)
            && (Microsoft_Windows_NtfsLog_4539dab7390732ef263ed8022a9ab47cEnableBits & 0x40) != 0 )
          {
            McTemplateU0q_EtwWriteTransfer(v36, &ntfsinit_c6370, (unsigned int)v36);
            LODWORD(v36) = v77;
          }
          v37 = v36;
          NtfsMinTrimTotalSize = v36;
          v50 = 1;
        }
        v38 = v78;
        if ( v78 < v37 )
          v38 = v37;
        v78 = v38;
        if ( NtfsMaxTrimTotalSize != (_DWORD)v38 )
        {
          if ( (!*(_QWORD *)v84 || (*(_DWORD *)(*(_QWORD *)v84 + 16LL) & 0x100000) == 0)
            && (Microsoft_Windows_NtfsLog_4539dab7390732ef263ed8022a9ab47cEnableBits & 0x40) != 0 )
          {
            McTemplateU0q_EtwWriteTransfer(v38, &ntfsinit_c6391, (unsigned int)v38);
            LODWORD(v38) = v78;
          }
          NtfsMaxTrimTotalSize = v38;
          v50 = 1;
        }
        if ( v51 )
          NtfsTrimListLengthThreshold = v102;
        NtfsMaxWaitTimeForDeallocatedClustersInTrim = 10000 * (unsigned __int64)v106 / (unsigned int)dword_1C00963D0;
        if ( v56 )
        {
          if ( v93 )
          {
            if ( v93 == 1 )
              LOBYTE(word_1C0096AF0) = 1;
          }
          else
          {
            LOBYTE(word_1C0096AF0) = 0;
          }
        }
        if ( v87 != dword_1C0096AD4 )
          dword_1C0096AD4 = v87;
        if ( v88 != dword_1C00968C4 )
          dword_1C00968C4 = v88;
        if ( v108 != dword_1C0096AD8 )
          dword_1C0096AD8 = 100000;
        if ( v109 != dword_1C0096ADC )
          dword_1C0096ADC = 25;
        if ( v57 )
          HIBYTE(word_1C0096AF0) = v103 != 0;
        dword_1C0096AF4 = v104;
        if ( v105 )
        {
          if ( dword_1C00966D8 < 0 )
            goto LABEL_299;
          v39 = dword_1C00966D8 | 0x80000000;
        }
        else
        {
          if ( dword_1C00966D8 >= 0 )
            goto LABEL_299;
          v39 = dword_1C00966D8 & 0x7FFFFFFF;
        }
        dword_1C00966D8 = v39;
LABEL_299:
        byte_1C0096AF2 = v94 == 1;
        dword_1C0096AF8 = v65;
        dword_1C0096AFC = v95;
        dword_1C0096C80 = v67;
        dword_1C0096C84 = v68;
        if ( dword_1C0096C34 != v79 )
        {
          dword_1C0096C34 = v79;
          v61 = 1;
        }
        if ( v52 )
          IoPerfRegistryConfig = v96 != 0;
        if ( v49 )
          dword_1C009563C = v89;
        dword_1C0096C0C = v19;
        v40 = NtfsMaxDelayCloseCount;
        if ( !NtfsMaxDelayCloseCount )
        {
          v40 = 0x4000;
          NtfsMaxDelayCloseCount = 0x4000;
        }
        if ( v16 < v40 )
        {
          NtfsMinDelayCloseCount = 4 * v16 / 5;
          NtfsMaxDelayCloseCount = v16;
        }
        else
        {
          NtfsMaxDelayCloseCount = v16;
          NtfsMinDelayCloseCount = 4 * v16 / 5;
        }
        v41 = (unsigned __int8)FsRtlIsMobileOS() == 0;
        v42 = NtfsMinDelayCloseCount;
        if ( v41 )
          v42 = 2 * NtfsMinDelayCloseCount;
        NtfsThrottleCreates = v42;
        if ( qword_1C0096C78 != v20 )
        {
          qword_1C0096C78 = v20;
          v54 = 1;
        }
        if ( (unsigned int)(v83 - 1) <= 1 )
          dword_1C0096C8C = v83;
        else
          dword_1C0096C8C = (byte_1C00961FA == 1) + 1;
        if ( word_1C0096C90 != (_WORD)v71 )
        {
          word_1C0096C90 = v71;
          v54 = 1;
        }
        word_1C0096C92 = v69;
        word_1C0096C94 = v70;
        dword_1C0096C98 = v90;
        word_1C0096C9C = v80;
        byte_1C0096C76 = v27 != 0;
        if ( (unsigned int)Feature_1193384250__private_IsEnabledDeviceUsageNoInline() )
          byte_1C0096C9E = v28 != 0;
        ExReleaseResourceLite(&Resource);
        v55 = 0;
        if ( a1 )
        {
          v43 = v84[0];
          if ( v53 )
            NtfsForEachVcb(v84[0], 0, 0, (unsigned int)NtfsUpdateDeleteNotificationVolumeSetting, 0LL, 0);
          if ( v50 )
            NtfsForEachVcb(v43, 0, 0, (unsigned int)NtfsUpdateTrimLimitsVolumeSetting, 0LL, 0);
          if ( v58 )
            NtfsForEachVcb(v43, 0, 0, (unsigned int)NtfsUpdateShortNameCreationVolumeSetting, 0LL, 0);
          if ( v59 || v60 )
            NtfsForEachVcb(v43, 0, 0, (unsigned int)NtfsUpdateCorruptionHandlingVolumeSetting, 0LL, 0);
          if ( v61 )
            NtfsForEachVcb(v43, 0, 0, (unsigned int)NtfsUpdateLockSystemFilePagesVolumeSetting, 0LL, 1);
          if ( v54 )
            NtfsForEachVcb(v43, 0, 0, (unsigned int)NtfsUpdateVcbStateToReloadClusters, 0LL, 0);
          if ( v49 )
            IoPerfRegistryUpdateConfig();
        }
        v3 = *(_QWORD *)v84;
        NtfsExtendedCompleteRequestInternal(*(_QWORD *)v84, 0LL, 0LL, 0LL, 1);
        v4 = ValueKeyWithFallBack;
        if ( ValueKeyWithFallBack != -1073741608 && ValueKeyWithFallBack != -1073741432 )
          break;
        v1 = v71;
      }
    }
    if ( v44[0] )
      ExFreePoolWithTag(P, 0);
    ExReleaseResourceLite(&NtfsDynamicRegistrySettingsResource);
    KeLeaveCriticalRegion();
  }
}
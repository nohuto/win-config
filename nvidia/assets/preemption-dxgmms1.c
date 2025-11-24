__int64 __fastcall VidSchiReadGlobalConfiguration(__int64 a1)
{
  __int64 v1; // rbx
  int v3; // edi
  __int64 v4; // rax
  int NodeConfiguration; // r10d
  unsigned int v6; // r8d
  unsigned int v7; // r9d
  __int64 v8; // rcx
  unsigned int v9; // edx
  int v10; // eax
  bool v11; // zf
  __int64 v12; // rcx
  bool IsEnabled; // al
  int v14; // ecx
  _QWORD *v15; // rcx
  int v16; // eax
  bool v17; // cc
  int v18; // eax
  __int64 v19; // rax
  bool v20; // cf
  int v21; // edx
  int v22; // eax
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  __int64 v26; // rax
  __int64 result; // rax
  unsigned int v28; // [rsp+38h] [rbp-D0h] BYREF
  unsigned int v29; // [rsp+3Ch] [rbp-CCh] BYREF
  unsigned int v30; // [rsp+40h] [rbp-C8h] BYREF
  int v31; // [rsp+44h] [rbp-C4h] BYREF
  unsigned int v32; // [rsp+48h] [rbp-C0h] BYREF
  int v33; // [rsp+4Ch] [rbp-BCh] BYREF
  int v34; // [rsp+50h] [rbp-B8h] BYREF
  int v35; // [rsp+54h] [rbp-B4h] BYREF
  int v36; // [rsp+58h] [rbp-B0h] BYREF
  int v37; // [rsp+5Ch] [rbp-ACh] BYREF
  int v38; // [rsp+60h] [rbp-A8h] BYREF
  int v39; // [rsp+64h] [rbp-A4h] BYREF
  int v40; // [rsp+68h] [rbp-A0h] BYREF
  int v41; // [rsp+6Ch] [rbp-9Ch] BYREF
  int v42; // [rsp+70h] [rbp-98h] BYREF
  int v43; // [rsp+74h] [rbp-94h] BYREF
  int v44; // [rsp+78h] [rbp-90h] BYREF
  int v45; // [rsp+7Ch] [rbp-8Ch] BYREF
  int v46; // [rsp+80h] [rbp-88h] BYREF
  int v47; // [rsp+84h] [rbp-84h] BYREF
  int v48; // [rsp+88h] [rbp-80h] BYREF
  int v49; // [rsp+8Ch] [rbp-7Ch] BYREF
  int v50; // [rsp+90h] [rbp-78h] BYREF
  int v51; // [rsp+94h] [rbp-74h] BYREF
  int v52; // [rsp+98h] [rbp-70h] BYREF
  int v53; // [rsp+9Ch] [rbp-6Ch] BYREF
  int v54; // [rsp+A0h] [rbp-68h] BYREF
  unsigned int v55; // [rsp+A4h] [rbp-64h] BYREF
  int v56; // [rsp+A8h] [rbp-60h] BYREF
  int v57; // [rsp+ACh] [rbp-5Ch] BYREF
  int v58; // [rsp+B0h] [rbp-58h] BYREF
  int v59; // [rsp+B4h] [rbp-54h] BYREF
  int v60; // [rsp+B8h] [rbp-50h] BYREF
  int v61; // [rsp+BCh] [rbp-4Ch] BYREF
  int v62; // [rsp+C0h] [rbp-48h] BYREF
  int v63; // [rsp+C4h] [rbp-44h] BYREF
  int v64; // [rsp+C8h] [rbp-40h] BYREF
  int v65; // [rsp+CCh] [rbp-3Ch] BYREF
  int v66; // [rsp+D0h] [rbp-38h] BYREF
  int v67; // [rsp+D4h] [rbp-34h] BYREF
  int v68; // [rsp+D8h] [rbp-30h] BYREF
  int v69; // [rsp+DCh] [rbp-2Ch] BYREF
  int v70; // [rsp+E0h] [rbp-28h] BYREF
  int v71; // [rsp+E4h] [rbp-24h] BYREF
  int v72; // [rsp+E8h] [rbp-20h] BYREF
  int v73; // [rsp+ECh] [rbp-1Ch] BYREF
  int v74; // [rsp+F0h] [rbp-18h] BYREF
  int v75; // [rsp+F4h] [rbp-14h] BYREF
  int v76; // [rsp+F8h] [rbp-10h] BYREF
  int v77; // [rsp+FCh] [rbp-Ch] BYREF
  int v78; // [rsp+100h] [rbp-8h] BYREF
  int v79; // [rsp+104h] [rbp-4h] BYREF
  _QWORD v80[190]; // [rsp+108h] [rbp+0h] BYREF
  _DWORD v81[64]; // [rsp+6F8h] [rbp+5F0h] BYREF

  v1 = 0LL;
  v78 = 8;
  v56 = 0;
  v62 = 0;
  v76 = 900;
  v3 = 1;
  v45 = 900;
  v57 = 25000;
  v34 = 7;
  v33 = 7;
  v59 = 1;
  v70 = 20;
  v32 = 20;
  v58 = 50000;
  v60 = 2;
  v61 = 3;
  v63 = 0;
  v64 = 1;
  v65 = 1;
  v66 = 1;
  v67 = 1;
  v68 = 0;
  v72 = 0;
  v69 = 1;
  v71 = 2;
  v35 = 1;
  v74 = 0;
  v75 = 0;
  v77 = 1000;
  v73 = 1;
  v79 = 0;
  v37 = 0;
  v28 = 25000;
  v29 = 50000;
  v39 = 1;
  v36 = 2;
  v30 = 3;
  v55 = 0;
  v38 = 0;
  v40 = 1;
  v41 = 1;
  v42 = 1;
  v50 = 1;
  v51 = 0;
  v52 = 0;
  v53 = 1;
  v54 = 2;
  v31 = 1;
  v49 = 0;
  v43 = 0;
  v46 = 1000;
  v48 = 1;
  v47 = 8;
  v44 = 0;
  memset(v81, 0, sizeof(v81));
  v4 = *(_QWORD *)(a1 + 16);
  if ( *(int *)(v4 + 3004) >= 1300 && *(_BYTE *)(v4 + 2941) )
  {
    v34 = 1;
    v33 = 1;
  }
  if ( KeQueryActiveProcessorCountEx(0xFFFFu) >= 2 )
  {
    v35 = 0;
    v31 = 0;
  }
  memset(v80, 0, 0x5E8uLL);
  v80[7] = 0LL;
  LODWORD(v80[1]) = 288;
  LODWORD(v80[4]) = 67108868;
  LODWORD(v80[6]) = 4;
  v80[2] = L"AutoSyncToCPUPriority";
  v80[3] = &v37;
  v80[5] = &v56;
  v80[9] = L"QuantumUnit";
  v80[10] = &v28;
  v80[12] = &v57;
  v80[16] = L"PreemptionQuantumUnit";
  v80[17] = &v29;
  v80[19] = &v58;
  v80[23] = L"EnablePreemption";
  v80[24] = &v39;
  v80[26] = &v59;
  v80[30] = L"HwQueuedRenderPacketGroupLimit";
  v80[31] = &v36;
  v80[33] = &v60;
  v80[37] = L"QueuedPresentLimit";
  v80[38] = &v30;
  v80[40] = &v61;
  v80[44] = L"InitDriverFenceId";
  v80[45] = &v55;
  v80[47] = &v62;
  v80[51] = L"CarryOverUsedQuantum";
  LODWORD(v80[8]) = 288;
  LODWORD(v80[11]) = 67108868;
  LODWORD(v80[13]) = 4;
  v80[14] = 0LL;
  LODWORD(v80[15]) = 288;
  LODWORD(v80[18]) = 67108868;
  LODWORD(v80[20]) = 4;
  v80[21] = 0LL;
  LODWORD(v80[22]) = 288;
  LODWORD(v80[25]) = 67108868;
  LODWORD(v80[27]) = 4;
  v80[28] = 0LL;
  LODWORD(v80[29]) = 288;
  LODWORD(v80[32]) = 67108868;
  LODWORD(v80[34]) = 4;
  v80[35] = 0LL;
  LODWORD(v80[36]) = 288;
  LODWORD(v80[39]) = 67108868;
  LODWORD(v80[41]) = 4;
  v80[42] = 0LL;
  LODWORD(v80[43]) = 288;
  LODWORD(v80[46]) = 67108868;
  LODWORD(v80[48]) = 4;
  v80[49] = 0LL;
  LODWORD(v80[50]) = 288;
  v80[52] = &v38;
  v80[54] = &v63;
  v80[58] = L"EnableFlipOnVSyncHwFlipQueue";
  v80[59] = &v40;
  v80[61] = &v64;
  v80[65] = L"EnableFlipOnVSyncSwFlipQueue";
  v80[66] = &v41;
  v80[68] = &v65;
  v80[72] = L"EnableFlipImmediateSwFlipQueue";
  v80[73] = &v42;
  v80[75] = &v66;
  v80[79] = L"AdjustWorkerThreadPriority";
  v80[80] = &v50;
  v80[82] = &v67;
  v80[86] = L"CountFlipTowardHwLimit";
  v80[87] = &v51;
  v80[89] = &v68;
  v80[93] = L"AllowUserModeToSetFlipLimit";
  v80[94] = &v53;
  v80[96] = &v69;
  v80[100] = L"NumberOfDmaPacketPool";
  v80[101] = &v32;
  v80[103] = &v70;
  v80[107] = L"ProfileLevel";
  v80[108] = &v54;
  LODWORD(v80[53]) = 67108868;
  LODWORD(v80[55]) = 4;
  v80[56] = 0LL;
  LODWORD(v80[57]) = 288;
  LODWORD(v80[60]) = 67108868;
  LODWORD(v80[62]) = 4;
  v80[63] = 0LL;
  LODWORD(v80[64]) = 288;
  LODWORD(v80[67]) = 67108868;
  LODWORD(v80[69]) = 4;
  v80[70] = 0LL;
  LODWORD(v80[71]) = 288;
  LODWORD(v80[74]) = 67108868;
  LODWORD(v80[76]) = 4;
  v80[77] = 0LL;
  LODWORD(v80[78]) = 288;
  LODWORD(v80[81]) = 67108868;
  LODWORD(v80[83]) = 4;
  v80[84] = 0LL;
  LODWORD(v80[85]) = 288;
  LODWORD(v80[88]) = 67108868;
  LODWORD(v80[90]) = 4;
  v80[91] = 0LL;
  LODWORD(v80[92]) = 288;
  LODWORD(v80[95]) = 67108868;
  LODWORD(v80[97]) = 4;
  v80[98] = 0LL;
  LODWORD(v80[99]) = 288;
  LODWORD(v80[102]) = 67108868;
  LODWORD(v80[104]) = 4;
  v80[105] = 0LL;
  LODWORD(v80[106]) = 288;
  LODWORD(v80[109]) = 67108868;
  v80[110] = &v71;
  v80[114] = L"VSyncIdleTimeout";
  v80[115] = &v33;
  v80[117] = &v34;
  v80[121] = L"EnableDirectSubmission";
  v80[122] = &v31;
  v80[124] = &v35;
  v80[128] = L"CountPresentTowardHwLimit";
  v80[129] = &v52;
  v80[131] = &v72;
  v80[135] = L"EnableContextDelay";
  v80[136] = &v48;
  v80[138] = &v73;
  v80[142] = L"ForcePreemptionAware";
  v80[143] = &v49;
  v80[145] = &v74;
  v80[149] = L"LogDriverVSyncCallback";
  v80[150] = &v43;
  v80[152] = &v75;
  v80[156] = L"MaximumAllowedPreemptionDelay";
  v80[157] = &v45;
  v80[159] = &v76;
  v80[163] = L"ContextSchedulingPenaltyDelay";
  v80[164] = &v46;
  LODWORD(v80[111]) = 4;
  v80[112] = 0LL;
  LODWORD(v80[113]) = 288;
  LODWORD(v80[116]) = 67108868;
  LODWORD(v80[118]) = 4;
  v80[119] = 0LL;
  LODWORD(v80[120]) = 288;
  LODWORD(v80[123]) = 67108868;
  LODWORD(v80[125]) = 4;
  v80[126] = 0LL;
  LODWORD(v80[127]) = 288;
  LODWORD(v80[130]) = 67108868;
  LODWORD(v80[132]) = 4;
  v80[133] = 0LL;
  LODWORD(v80[134]) = 288;
  LODWORD(v80[137]) = 67108868;
  LODWORD(v80[139]) = 4;
  v80[140] = 0LL;
  LODWORD(v80[141]) = 288;
  LODWORD(v80[144]) = 67108868;
  LODWORD(v80[146]) = 4;
  v80[147] = 0LL;
  LODWORD(v80[148]) = 288;
  LODWORD(v80[151]) = 67108868;
  LODWORD(v80[153]) = 4;
  v80[154] = 0LL;
  LODWORD(v80[155]) = 288;
  LODWORD(v80[158]) = 67108868;
  LODWORD(v80[160]) = 4;
  v80[161] = 0LL;
  LODWORD(v80[162]) = 288;
  LODWORD(v80[165]) = 67108868;
  LODWORD(v80[169]) = 288;
  v80[166] = &v77;
  LODWORD(v80[172]) = 67108868;
  v80[170] = L"BackgroundProcessMaximumAllowedPreemptionDelay";
  LODWORD(v80[176]) = 288;
  v80[171] = &v47;
  LODWORD(v80[179]) = 67108868;
  v80[173] = &v78;
  LODWORD(v80[167]) = 4;
  v80[177] = L"ForceIndependentFlip";
  v80[178] = &v44;
  v80[180] = &v79;
  v80[168] = 0LL;
  LODWORD(v80[174]) = 4;
  v80[175] = 0LL;
  LODWORD(v80[181]) = 4;
  RtlQueryRegistryValuesEx(2LL, L"GraphicsDrivers\\Scheduler", v80, 0LL, 0LL);
  NodeConfiguration = VidSchiReadNodeConfiguration(a1, v81);
  v6 = 0;
  if ( *(_DWORD *)(a1 + 56) )
  {
    v7 = v36;
    do
    {
      v8 = v6;
      if ( NodeConfiguration < 0 || (v9 = v81[v6]) == 0 )
      {
        v9 = v7;
        v81[v6] = v7;
      }
      v10 = 1;
      if ( v9 > 1 )
        v10 = v9;
      ++v6;
      *(_DWORD *)(a1 + 4 * v8 + 2228) = v10;
    }
    while ( v6 < *(_DWORD *)(a1 + 56) );
  }
  v11 = v44 == 0;
  *(_DWORD *)(a1 + 2208) = (v43 != 0 ? 0x8000 : 0) | (v42 != 0 ? 0x400 : 0) | (v41 != 0 ? 0x200 : 0) | (v40 != 0 ? 0x100 : 0) | (v39 != 0) | (v38 != 0 ? 8 : 0) | (v37 != 0 ? 4 : 0) | *(_DWORD *)(a1 + 2208) & 0xFFFF78F2;
  v12 = (unsigned int)(10000 * v45);
  *(_BYTE *)(a1 + 49) |= !v11;
  *(_QWORD *)(a1 + 2632) = v12;
  *(_QWORD *)(a1 + 2640) = (unsigned int)(10000 * v46);
  *(_QWORD *)(a1 + 2648) = (unsigned int)(10000 * v47);
  if ( !v48 || (IsEnabled = TdrIsEnabled(), v14 = 0x10000, !IsEnabled) )
    v14 = 0;
  *(_DWORD *)(a1 + 2208) = v14 | *(_DWORD *)(a1 + 2208) & 0xFFFEFFFF;
  if ( v49 )
    *(_BYTE *)(a1 + 46) = 1;
  v15 = (_QWORD *)(a1 + 2544);
  do
  {
    v16 = 1;
    if ( v28 > 1 )
      v16 = v28;
    v17 = v29 <= 1;
    *(v15 - 6) = (unsigned int)(*(_DWORD *)((char *)&gulQuantumMultiplierTableByPriorityClass + v1) * v16);
    v18 = 1;
    if ( !v17 )
      v18 = v29;
    v19 = (unsigned int)(*(_DWORD *)((char *)&gulPreemptionQuantumMultiplierTableByPriorityClass + v1) * v18);
    v1 += 4LL;
    *v15++ = v19;
  }
  while ( v1 < 24 );
  if ( v30 > 1 )
    v3 = v30;
  v20 = v31 != 0;
  v21 = *(_DWORD *)(a1 + 2208);
  v22 = v50;
  *(_DWORD *)(a1 + 2224) = v3;
  v23 = (v20 ? 2 : 0) | v21 & 0xFFFFFFFD;
  v20 = v22 != 0;
  v24 = 16;
  v25 = v33;
  v17 = v32 <= 0x10;
  *(_DWORD *)(a1 + 2208) = (v53 != 0 ? 0x4000 : 0) | (v52 != 0 ? 0x2000 : 0) | (v51 != 0 ? 0x1000 : 0) | (v20 ? 0x800 : 0) | v23 & 0xFFFF87FF;
  if ( !v17 )
    v24 = v32;
  *(_DWORD *)(a1 + 2488) = v24;
  *(_DWORD *)(a1 + 5360) = v54;
  v26 = *(_QWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 2088) = v25;
  if ( *(int *)(v26 + 3004) < 1300 )
  {
    if ( v25 >= 4 )
    {
      if ( v25 > 0xFFFFFFFD )
        *(_DWORD *)(a1 + 2088) = -3;
    }
    else
    {
      *(_DWORD *)(a1 + 2088) = 4;
    }
  }
  result = v55;
  *(_DWORD *)(a1 + 2624) = v55;
  *(_DWORD *)(a1 + 2616) = result;
  *(_DWORD *)(a1 + 2608) = result;
  *(_DWORD *)(a1 + 2600) = result;
  *(_DWORD *)(a1 + 2592) = result;
  return result;
}
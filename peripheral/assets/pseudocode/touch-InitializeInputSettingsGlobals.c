__int64 InitializeInputSettingsGlobals(void)
{
  __int64 v0; // rdi
  __int128 v1; // xmm1
  __int128 v2; // xmm0
  __int64 result; // rax
  __int128 v4; // [rsp+20h] [rbp-E0h]
  const wchar_t *Src; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v6; // [rsp+38h] [rbp-C8h]
  const wchar_t *v7; // [rsp+40h] [rbp-C0h]
  __int64 v8; // [rsp+48h] [rbp-B8h]
  const wchar_t *v9; // [rsp+50h] [rbp-B0h]
  unsigned __int64 v10; // [rsp+58h] [rbp-A8h]
  const wchar_t *v11; // [rsp+60h] [rbp-A0h]
  __int64 v12; // [rsp+68h] [rbp-98h]
  const wchar_t *v13; // [rsp+70h] [rbp-90h]
  __int64 v14; // [rsp+78h] [rbp-88h]
  const wchar_t *v15; // [rsp+80h] [rbp-80h]
  int v16; // [rsp+88h] [rbp-78h]
  int v17; // [rsp+8Ch] [rbp-74h]
  const wchar_t *v18; // [rsp+90h] [rbp-70h]
  int v19; // [rsp+98h] [rbp-68h]
  int v20; // [rsp+9Ch] [rbp-64h]
  const wchar_t *v21; // [rsp+A0h] [rbp-60h]
  __int64 v22; // [rsp+A8h] [rbp-58h]
  const wchar_t *v23; // [rsp+B0h] [rbp-50h]
  int v24; // [rsp+B8h] [rbp-48h]
  int v25; // [rsp+BCh] [rbp-44h]
  const wchar_t *v26; // [rsp+C0h] [rbp-40h]
  int v27; // [rsp+C8h] [rbp-38h]
  int v28; // [rsp+CCh] [rbp-34h]
  const wchar_t *v29; // [rsp+D0h] [rbp-30h]
  const wchar_t *v30; // [rsp+D8h] [rbp-28h]
  const wchar_t *v31; // [rsp+E0h] [rbp-20h]
  unsigned __int64 v32; // [rsp+E8h] [rbp-18h]
  const wchar_t *v33; // [rsp+F0h] [rbp-10h]
  int v34; // [rsp+F8h] [rbp-8h]
  int v35; // [rsp+FCh] [rbp-4h]
  const wchar_t *v36; // [rsp+100h] [rbp+0h]
  __int64 v37; // [rsp+108h] [rbp+8h]
  const wchar_t *v38; // [rsp+110h] [rbp+10h]
  __int64 v39; // [rsp+118h] [rbp+18h]
  const wchar_t *v40; // [rsp+120h] [rbp+20h]
  __int64 v41; // [rsp+128h] [rbp+28h]
  __int128 v42; // [rsp+130h] [rbp+30h]
  __int128 v43; // [rsp+140h] [rbp+40h]
  __int128 v44; // [rsp+150h] [rbp+50h]

  v6 = 0LL;
  v30 = 0LL;
  v0 = W32GetUserSessionState() + 17408;
  v32 = 0LL;
  v8 = 0x100000001LL;
  Src = L"PanningDisabled";
  v7 = L"Inertia";
  v9 = L"Bouncing";
  v11 = L"Friction";
  v13 = L"TouchModeN_DtapDist";
  v15 = L"TouchModeN_DtapTime";
  v18 = L"TouchGate";
  v21 = L"TouchModeN_HoldTime_Animation";
  v23 = L"TouchModeN_HoldTime_BeforeAnimation";
  v26 = L"TouchMode_hold";
  v29 = L"Mobile_Inertia_Enabled";
  v31 = L"Minimum_Velocity";
  v33 = L"Thumb_Flick_Enabled";
  v10 = 0x100000001LL;
  v12 = 0x3200000032LL;
  v14 = 0x3200000032LL;
  v16 = 50;
  v17 = 50;
  v19 = 1;
  v20 = 1;
  v22 = 0x3200000032LL;
  v24 = 50;
  v25 = 50;
  v27 = 1;
  v28 = 1;
  v34 = 1;
  v35 = 1;
  memmove((void *)v0, &Src, 0xD0uLL);
  *(_QWORD *)(v0 + 216) = v0;
  *(_QWORD *)(v0 + 224) = L"MultiTouchEnabled";
  *(_DWORD *)(v0 + 232) = 1;
  *(_DWORD *)(v0 + 236) = 1;
  *(_QWORD *)(v0 + 248) = v0 + 224;
  Src = L"AAPThreshold";
  v6 = 0x200000002LL;
  v7 = L"CursorSpeed";
  v8 = 0xA0000000ALL;
  v9 = L"FeedbackIntensity";
  v11 = L"ClickForceSensitivity";
  v10 = 0x3200000032LL;
  v12 = 0x3200000032LL;
  v13 = L"LeaveOnWithMouse";
  v15 = L"FeedbackEnabled";
  v14 = 0x100000001LL;
  v18 = L"TapsEnabled";
  v21 = L"TapAndDrag";
  v16 = 1;
  v23 = L"TwoFingerTapEnabled";
  v26 = L"RightClickZoneEnabled";
  v29 = L"HonorMouseAccelSetting";
  v31 = L"PanEnabled";
  v33 = L"ZoomEnabled";
  v36 = L"ScrollDirection";
  v38 = L"RightClickZoneWidth";
  v40 = L"RightClickZoneHeight";
  v17 = 1;
  v19 = 1;
  v20 = 1;
  v22 = 0x100000001LL;
  v24 = 1;
  v25 = 1;
  v27 = 1;
  v28 = 1;
  v30 = 0LL;
  v32 = 0x100000001LL;
  v34 = 1;
  v35 = 1;
  v37 = 0LL;
  v39 = 0LL;
  v41 = 0LL;
  memmove((void *)(v0 + 256), &Src, 0x100uLL);
  *(_QWORD *)(v0 + 520) = v0 + 256;
  v6 = 0x3200000032LL;
  Src = L"Splash";
  v7 = L"DblDist";
  v9 = L"DblTime";
  v11 = L"TapTime";
  v12 = 0x6400000064LL;
  v13 = L"WaitTime";
  v15 = L"HoldTime";
  v16 = 2300;
  v17 = 2300;
  v18 = L"FlickMode";
  v8 = 0x3200000032LL;
  v10 = 0x12C0000012CLL;
  v14 = 0x12C0000012CLL;
  v19 = 1;
  v20 = 1;
  v21 = L"FlickTolerance";
  v22 = 0x3200000032LL;
  memmove((void *)(v0 + 656), &Src, 0x80uLL);
  *(_QWORD *)(v0 + 792) = v0 + 656;
  v9 = (const wchar_t *)0x47F38E42CEFA51BCLL;
  Src = L"Left";
  v15 = (const wchar_t *)0x47F38E42CEFA51BCLL;
  v8 = (__int64)L"UpLeft";
  v23 = (const wchar_t *)0x47F38E42CEFA51BCLL;
  v11 = L"Up";
  v31 = (const wchar_t *)0x47F38E42CEFA51BCLL;
  v14 = (__int64)L"UpRight";
  v6 = 0x4846455758C33841LL;
  v18 = L"Right";
  v22 = (__int64)L"DownRight";
  v26 = L"Down";
  v30 = L"DownLeft";
  v7 = (const wchar_t *)0x9F7145B888BB26B8LL;
  v10 = 0xEBDFECA56A8CB1ACuLL;
  v12 = 0x450285124653D974LL;
  v13 = (const wchar_t *)0x8090833CF6D41AA0LL;
  v16 = 1787605420;
  v17 = -337646427;
  v19 = -1033389858;
  v20 = 1336411790;
  v21 = (const wchar_t *)0x4E301EF93B324FABLL;
  v24 = 1787605420;
  v25 = -337646427;
  v27 = 1142583377;
  v28 = 1129805542;
  v29 = (const wchar_t *)0xF7C82D37F0853D9BLL;
  v32 = 0xEBDFECA56A8CB1ACuLL;
  memmove((void *)(v0 + 800), &Src, 0xC0uLL);
  *(_QWORD *)(v0 + 1000) = v0 + 800;
  *((_QWORD *)&v42 + 1) = 0x800000008LL;
  *(_QWORD *)&v42 = L"Latency";
  *(_QWORD *)&v43 = L"SampleTime";
  *(_QWORD *)&v44 = L"UseHWTimeStamp";
  *((_QWORD *)&v43 + 1) = 0x800000008LL;
  *((_QWORD *)&v44 + 1) = 0x100000001LL;
  v6 = 0LL;
  v1 = v43;
  *(_OWORD *)(v0 + 1008) = v42;
  v8 = 0x100000001LL;
  v2 = v44;
  *(_OWORD *)(v0 + 1024) = v1;
  v10 = 0LL;
  *(_OWORD *)(v0 + 1040) = v2;
  *(_QWORD *)(v0 + 1064) = v0 + 1008;
  Src = L"SguiMode";
  v7 = L"HoldMode";
  v9 = L"MouseInputResolutionX";
  v11 = L"MouseInputResolutionY";
  v13 = L"MouseInputFrequency";
  v15 = L"EraseEnable";
  v18 = L"RightMaskEnable";
  v12 = 0LL;
  v14 = 0LL;
  v16 = 1;
  v17 = 1;
  v19 = 1;
  v20 = 1;
  memmove((void *)(v0 + 528), &Src, 0x70uLL);
  *(_QWORD *)(v0 + 648) = v0 + 528;
  *(_QWORD *)&v4 = L"Color";
  *((_QWORD *)&v4 + 1) = 0xC0000000C0000000uLL;
  *(_OWORD *)(v0 + 1072) = v4;
  *(_QWORD *)(v0 + 1096) = v0 + 1072;
  result = 0LL;
  *(_DWORD *)(v0 + 1104) = 16;
  *(_DWORD *)(v0 + 1108) = 8;
  *(_DWORD *)(v0 + 1112) = 8;
  *(_QWORD *)(v0 + 1116) = 1LL;
  *(_QWORD *)(v0 + 1124) = 105LL;
  *(_QWORD *)(v0 + 1132) = 8229LL;
  *(_QWORD *)(v0 + 1140) = 175LL;
  *(_QWORD *)(v0 + 1148) = 33LL;
  return result;
}
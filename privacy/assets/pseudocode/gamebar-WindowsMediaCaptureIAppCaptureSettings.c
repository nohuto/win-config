// Hidden C++ exception states: #wind=27
__int64 __fastcall Windows::Media::Capture::AppCaptureSettings::ApplySettings(
        struct Windows::Media::Capture::IAppCaptureSettings *a1,
        bool *a2,
        bool *a3,
        bool *a4)
{
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // r9d
  int v11; // ecx
  __int64 (__fastcall *v12)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *); // rbx
  __int64 v13; // rcx
  __int64 v14; // rbx
  __int64 (__fastcall *v15)(__int64, __int64 (__fastcall ****)(_QWORD, GUID *, __int64 *)); // rsi
  __int64 (__fastcall ***v16)(_QWORD, _QWORD, _QWORD); // rcx
  __int64 (__fastcall ***v17)(_QWORD, _QWORD, _QWORD); // rbx
  __int64 (__fastcall *v18)(_QWORD, GUID *, __int64 *); // rsi
  __int64 v19; // rcx
  __int64 (__fastcall ***v20)(_QWORD, _QWORD, _QWORD); // rbx
  __int64 (__fastcall *v21)(_QWORD, GUID *, __int64 *); // rsi
  __int64 v22; // rcx
  __int64 (__fastcall *v23)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *); // rbx
  __int64 v24; // rcx
  __int64 (__fastcall *v25)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *); // rbx
  __int64 v26; // rcx
  Windows::Media::Capture::Internal::GameDVRUtility *v27; // rcx
  const char *v28; // rax
  int v29; // r9d
  int v30; // ecx
  unsigned int v31; // eax
  _DWORD *v32; // rax
  unsigned int v33; // edx
  _DWORD *v34; // rcx
  unsigned int v35; // ecx
  double v36; // xmm0_8
  unsigned __int64 v37; // rax
  double v38; // xmm0_8
  unsigned __int64 v39; // rax
  __int64 v40; // rcx
  __int64 v41; // rcx
  __int64 v42; // rcx
  __int64 v43; // rcx
  __int64 v44; // rcx
  __int64 v45; // rcx
  __int64 v46; // rcx
  __int64 v47; // rcx
  __int64 (__fastcall ***v48)(_QWORD, _QWORD, _QWORD); // rcx
  struct Windows::Media::Capture::IAppCaptureSettings *v49; // rcx
  unsigned int v51; // [rsp+20h] [rbp-E0h]
  unsigned int v52; // [rsp+20h] [rbp-E0h]
  unsigned int v53; // [rsp+20h] [rbp-E0h]
  unsigned int v54; // [rsp+20h] [rbp-E0h]
  unsigned int v55; // [rsp+20h] [rbp-E0h]
  unsigned int v56; // [rsp+20h] [rbp-E0h]
  unsigned int v57; // [rsp+20h] [rbp-E0h]
  unsigned int v58; // [rsp+20h] [rbp-E0h]
  unsigned int v59; // [rsp+20h] [rbp-E0h]
  unsigned int v60; // [rsp+20h] [rbp-E0h]
  unsigned int v61; // [rsp+20h] [rbp-E0h]
  bool *v62; // [rsp+20h] [rbp-E0h]
  unsigned int v63; // [rsp+20h] [rbp-E0h]
  unsigned int v64; // [rsp+20h] [rbp-E0h]
  unsigned int v65; // [rsp+20h] [rbp-E0h]
  unsigned int v66; // [rsp+20h] [rbp-E0h]
  unsigned int v67; // [rsp+20h] [rbp-E0h]
  unsigned int v68; // [rsp+20h] [rbp-E0h]
  unsigned int v69; // [rsp+20h] [rbp-E0h]
  unsigned int v70; // [rsp+20h] [rbp-E0h]
  unsigned int v71; // [rsp+20h] [rbp-E0h]
  unsigned int v72; // [rsp+20h] [rbp-E0h]
  unsigned int v73; // [rsp+20h] [rbp-E0h]
  unsigned int v74; // [rsp+20h] [rbp-E0h]
  unsigned int v75; // [rsp+20h] [rbp-E0h]
  unsigned int v76; // [rsp+20h] [rbp-E0h]
  unsigned int v77; // [rsp+20h] [rbp-E0h]
  unsigned int v78; // [rsp+20h] [rbp-E0h]
  unsigned int v79; // [rsp+20h] [rbp-E0h]
  unsigned int v80; // [rsp+20h] [rbp-E0h]
  unsigned int v81; // [rsp+20h] [rbp-E0h]
  unsigned int v82; // [rsp+20h] [rbp-E0h]
  unsigned int v83; // [rsp+20h] [rbp-E0h]
  unsigned int v84; // [rsp+20h] [rbp-E0h]
  bool *v85; // [rsp+20h] [rbp-E0h]
  bool *v86; // [rsp+20h] [rbp-E0h]
  __int64 (__fastcall ***v87)(_QWORD, GUID *, __int64 *); // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int8 v88; // [rsp+48h] [rbp-B8h] BYREF
  unsigned __int8 v89; // [rsp+49h] [rbp-B7h] BYREF
  unsigned __int8 v90; // [rsp+4Ah] [rbp-B6h] BYREF
  unsigned __int8 v91; // [rsp+4Bh] [rbp-B5h] BYREF
  unsigned int v92; // [rsp+4Ch] [rbp-B4h] BYREF
  __int64 v93; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v94; // [rsp+58h] [rbp-A8h] BYREF
  __int64 v95; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v96; // [rsp+68h] [rbp-98h] BYREF
  __int64 v97; // [rsp+70h] [rbp-90h] BYREF
  __int64 v98; // [rsp+78h] [rbp-88h] BYREF
  unsigned int v99; // [rsp+80h] [rbp-80h] BYREF
  unsigned int v100; // [rsp+84h] [rbp-7Ch] BYREF
  unsigned int v101; // [rsp+88h] [rbp-78h] BYREF
  unsigned int v102; // [rsp+8Ch] [rbp-74h] BYREF
  unsigned int v103; // [rsp+90h] [rbp-70h] BYREF
  unsigned int v104; // [rsp+94h] [rbp-6Ch] BYREF
  double v105; // [rsp+98h] [rbp-68h] BYREF
  double v106; // [rsp+A0h] [rbp-60h] BYREF
  struct Windows::Media::Capture::IAppCaptureSettings *v107; // [rsp+A8h] [rbp-58h] BYREF
  unsigned int v108; // [rsp+B0h] [rbp-50h] BYREF
  unsigned int v109; // [rsp+B4h] [rbp-4Ch] BYREF
  unsigned int v110; // [rsp+B8h] [rbp-48h] BYREF
  unsigned int v111; // [rsp+BCh] [rbp-44h] BYREF
  unsigned int v112; // [rsp+C0h] [rbp-40h] BYREF
  unsigned int v113; // [rsp+C4h] [rbp-3Ch] BYREF
  unsigned int v114; // [rsp+C8h] [rbp-38h] BYREF
  unsigned int v115; // [rsp+CCh] [rbp-34h] BYREF
  unsigned int v116; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int v117; // [rsp+D4h] [rbp-2Ch] BYREF
  unsigned int v118; // [rsp+D8h] [rbp-28h] BYREF
  unsigned int v119; // [rsp+DCh] [rbp-24h] BYREF
  unsigned int v120; // [rsp+E0h] [rbp-20h] BYREF
  unsigned int v121; // [rsp+E4h] [rbp-1Ch] BYREF
  unsigned int v122; // [rsp+E8h] [rbp-18h] BYREF
  unsigned int v123; // [rsp+ECh] [rbp-14h] BYREF
  unsigned int v124; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int v125; // [rsp+F4h] [rbp-Ch] BYREF
  __int64 v126; // [rsp+F8h] [rbp-8h] BYREF
  __int64 v127; // [rsp+100h] [rbp+0h] BYREF
  const unsigned __int16 *v128; // [rsp+108h] [rbp+8h] BYREF
  _QWORD v129[4]; // [rsp+110h] [rbp+10h] BYREF
  unsigned __int8 v130; // [rsp+190h] [rbp+90h] BYREF
  unsigned __int8 v131; // [rsp+198h] [rbp+98h] BYREF
  unsigned __int8 v132; // [rsp+1A0h] [rbp+A0h] BYREF
  unsigned __int8 v133; // [rsp+1A8h] [rbp+A8h] BYREF

  v107 = 0LL;
  v87 = 0LL;
  v96 = 0LL;
  v93 = 0LL;
  v129[0] = a1;
  if ( a1 )
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *))(*(_QWORD *)a1 + 8LL))(a1);
  v98 = 0LL;
  v97 = 0LL;
  v95 = 0LL;
  v94 = 0LL;
  v127 = 0LL;
  v126 = 0LL;
  v129[1] = 0LL;
  v129[2] = 0LL;
  v130 = 1;
  v131 = 1;
  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  v8 = Microsoft::WRL::Details::MakeAndInitialize<Windows::Media::Capture::AppCaptureSettings,Windows::Media::Capture::IAppCaptureSettings,>(&v107);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 97;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, __int64 *))(*(_QWORD *)a1 + 56LL))(
         a1,
         &v127);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 100;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 72LL))(
         a1,
         &v116);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 101;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 88LL))(
         a1,
         &v133);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 102;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 104LL))(
         a1,
         &v99);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 103;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 120LL))(
         a1,
         &v100);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 104;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 136LL))(
         a1,
         &v101);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 105;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 152LL))(
         a1,
         &v92);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 106;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 168LL))(
         a1,
         &v102);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 107;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 296LL))(
         a1,
         &v88);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 108;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 184LL))(
         a1,
         &v89);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 109;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 200LL))(
         a1,
         &v90);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 110;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned __int8 *))(*(_QWORD *)a1 + 216LL))(
         a1,
         &v91);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 111;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, const unsigned __int16 **))(*(_QWORD *)a1 + 232LL))(
         a1,
         &v128);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 112;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, __int64 *))(*(_QWORD *)a1 + 248LL))(
         a1,
         &v126);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 113;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 264LL))(
         a1,
         &v103);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 114;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *, unsigned int *))(*(_QWORD *)a1 + 280LL))(
         a1,
         &v104);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 115;
    goto LABEL_5;
  }
  v12 = **(__int64 (__fastcall ***)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *))a1;
  v13 = v98;
  if ( v98 )
  {
    v98 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v13 + 16LL))(v13);
  }
  v8 = v12(a1, &GUID_fcb8cee7_e26b_476f_9b1a_ec342d2a8fde, &v98);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 117;
    goto LABEL_5;
  }
  v14 = v98;
  v15 = *(__int64 (__fastcall **)(__int64, __int64 (__fastcall ****)(_QWORD, GUID *, __int64 *)))(*(_QWORD *)v98 + 56LL);
  v16 = (__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD))v87;
  if ( v87 )
  {
    v87 = 0LL;
    ((void (__fastcall *)(__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD)))(*v16)[2])(v16);
  }
  v8 = v15(v14, &v87);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 118;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[7])(
         v87,
         &v118);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 120;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[9])(
         v87,
         &v119);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 121;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[11])(
         v87,
         &v120);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 122;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[13])(
         v87,
         &v121);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 123;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[15])(
         v87,
         &v122);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 124;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[17])(
         v87,
         &v123);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 125;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[19])(
         v87,
         &v124);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 126;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[21])(
         v87,
         &v125);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 127;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[23])(
         v87,
         &v108);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 128;
    goto LABEL_5;
  }
  v8 = ((__int64 (__fastcall *)(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *), unsigned int *))(*v87)[25])(
         v87,
         &v109);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 129;
    goto LABEL_5;
  }
  v17 = (__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD))v87;
  v18 = **v87;
  v19 = v96;
  if ( v96 )
  {
    v96 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16LL))(v19);
  }
  v8 = v18(v17, &GUID_c3669090_dd17_47f0_95e5_ce42286cf338, &v96);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 131;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v96 + 56LL))(v96, &v110);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 132;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v96 + 72LL))(v96, &v111);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 133;
    goto LABEL_5;
  }
  v20 = (__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD))v87;
  v21 = **v87;
  v22 = v93;
  if ( v93 )
  {
    v93 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v22 + 16LL))(v22);
  }
  v8 = v21(v20, &GUID_7b81448c_418e_469c_a49a_45b597c826b6, &v93);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 135;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v93 + 56LL))(v93, &v112);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 136;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v93 + 72LL))(v93, &v113);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 137;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v93 + 88LL))(v93, &v114);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 138;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v93 + 104LL))(v93, &v115);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 139;
    goto LABEL_5;
  }
  v23 = **(__int64 (__fastcall ***)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *))a1;
  v24 = v97;
  if ( v97 )
  {
    v97 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v24 + 16LL))(v24);
  }
  v8 = v23(a1, &GUID_a93502fe_88c2_42d6_aaaa_40feffd75aec, &v97);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 141;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *))(*(_QWORD *)v97 + 56LL))(v97, &v132);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 142;
    goto LABEL_5;
  }
  v8 = Microsoft::WRL::ComPtr<Windows::Media::Capture::IAppCaptureSettings>::As<Windows::Media::Capture::IAppCaptureSettings4>(
         v129,
         &v95);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 144;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *))(*(_QWORD *)v95 + 56LL))(v95, &v132);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 145;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, double *))(*(_QWORD *)v95 + 72LL))(v95, &v105);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 146;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, double *))(*(_QWORD *)v95 + 88LL))(v95, &v106);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 147;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v95 + 104LL))(v95, &v117);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 148;
    goto LABEL_5;
  }
  v25 = **(__int64 (__fastcall ***)(struct Windows::Media::Capture::IAppCaptureSettings *, GUID *, __int64 *))a1;
  v26 = v94;
  if ( v94 )
  {
    v94 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16LL))(v26);
  }
  v8 = v25(a1, &GUID_18894522_b0e8_4ba0_8f13_3eaa5fa4013b, &v94);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 150;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *))(*(_QWORD *)v94 + 56LL))(v94, &v130);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 151;
    goto LABEL_5;
  }
  v8 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *))(*(_QWORD *)v94 + 72LL))(v94, &v131);
  v9 = v8;
  if ( v8 < 0 )
  {
    v10 = 152;
    goto LABEL_5;
  }
  if ( v102 )
  {
    if ( v102 != 1 )
    {
      v9 = -2147418113;
      v28 = "bufferLengthUnit == Wmc::AppCaptureHistoricalBufferLengthUnit_Seconds";
      v29 = 162;
LABEL_120:
      v30 = v9;
      goto LABEL_115;
    }
    if ( v92 < 0xA )
    {
      v28 = "Wmci::c_dwMinBufferLengthInSeconds <= dwBufferlength";
      v29 = 163;
      goto LABEL_113;
    }
    if ( v92 > 0x258 )
    {
      v30 = -2110640110;
      v28 = "dwBufferlength <= Wmci::c_dwMaxBufferLengthInSeconds";
      v29 = 164;
      goto LABEL_114;
    }
  }
  else
  {
    if ( v92 < 0xA )
    {
      v28 = "Wmci::c_dwMinBufferLengthInMegabytes <= dwBufferlength";
      v29 = 157;
LABEL_113:
      v30 = -2110640109;
LABEL_114:
      v9 = v30;
LABEL_115:
      BcastDVRLogProviderBase::LogErrorEx(
        v30,
        "Windows::Media::Capture::AppCaptureSettings::ApplySettings",
        "multimedia\\bcastdvr\\server\\appcapturesettings\\lib\\appcapturesettings.cpp",
        v29,
        "IFCEXPECT",
        v28,
        1);
      goto LABEL_230;
    }
    v31 = Windows::Media::Capture::Internal::GameDVRUtility::MaxHistoricalBufferLengthInMegabytes(v27);
    if ( v92 > v31 )
    {
      v30 = -2110640110;
      v28 = "dwBufferlength <= GameDVRUtility::MaxHistoricalBufferLengthInMegabytes()";
      v29 = 158;
      goto LABEL_114;
    }
  }
  v32 = &unk_1801182A4;
  if ( !v104 )
  {
    v33 = 0;
    v34 = &unk_1801182A4;
    while ( v101 != *(v34 - 1) || v100 != *v34 )
    {
      ++v33;
      v34 += 4;
      if ( v33 >= 0x12 )
      {
        v9 = -2110640112;
        v28 = "fCustomResolutionValid";
        v29 = 182;
        goto LABEL_120;
      }
    }
  }
  if ( !v103 )
  {
    v35 = 0;
    while ( v101 != *(v32 - 1) || v100 != *v32 || v99 < v32[1] || v99 > v32[2] )
    {
      ++v35;
      v32 += 4;
      if ( v35 >= 0x12 )
      {
        v9 = -2110640111;
        v28 = "fCustomBitrateValid";
        v29 = 204;
        goto LABEL_120;
      }
    }
  }
  if ( (unsigned __int64)(v128 - 300000000) > 0x21634E5A00LL )
  {
    v9 = -2110640108;
    v10 = 211;
    v11 = -2110640108;
    goto LABEL_229;
  }
  if ( fmin(2.0, v105) >= 0.0 )
  {
    if ( v105 > 2.0 )
      v105 = DOUBLE_2_0;
  }
  else
  {
    v105 = 0.0;
  }
  if ( fmin(2.0, v106) >= 0.0 )
  {
    if ( v106 > 2.0 )
      v106 = DOUBLE_2_0;
  }
  else
  {
    v106 = 0.0;
  }
  v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
         (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
         (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
         L"AudioEncodingBitrate",
         (const unsigned __int16 *)v116,
         v51);
  v9 = v8;
  if ( v8 >= 0 )
  {
    v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
           (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
           (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
           L"AudioCaptureEnabled",
           (const unsigned __int16 *)v133,
           v52);
    v9 = v8;
    if ( v8 >= 0 )
    {
      v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
             (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
             (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
             L"CustomVideoEncodingBitrate",
             (const unsigned __int16 *)v99,
             v53);
      v9 = v8;
      if ( v8 >= 0 )
      {
        v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
               (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
               (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
               L"CustomVideoEncodingHeight",
               (const unsigned __int16 *)v100,
               v54);
        v9 = v8;
        if ( v8 >= 0 )
        {
          v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                 (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                 (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                 L"CustomVideoEncodingWidth",
                 (const unsigned __int16 *)v101,
                 v55);
          v9 = v8;
          if ( v8 >= 0 )
          {
            v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                   (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                   (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                   L"AppCaptureEnabled",
                   (const unsigned __int16 *)v88,
                   v56);
            v9 = v8;
            if ( v8 >= 0 )
            {
              v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                     (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                     (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                     L"HistoricalBufferLength",
                     (const unsigned __int16 *)v92,
                     v57);
              v9 = v8;
              if ( v8 >= 0 )
              {
                v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                       (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                       (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                       L"HistoricalBufferLengthUnit",
                       (const unsigned __int16 *)v102,
                       v58);
                v9 = v8;
                if ( v8 >= 0 )
                {
                  v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                         (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                         (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                         L"HistoricalCaptureEnabled",
                         (const unsigned __int16 *)v89,
                         v59);
                  v9 = v8;
                  if ( v8 >= 0 )
                  {
                    v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                           (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                           (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                           L"HistoricalCaptureOnBatteryAllowed",
                           (const unsigned __int16 *)v90,
                           v60);
                    v9 = v8;
                    if ( v8 >= 0 )
                    {
                      v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                             (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                             (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                             L"HistoricalCaptureOnWirelessDisplayAllowed",
                             (const unsigned __int16 *)v91,
                             v61);
                      v9 = v8;
                      if ( v8 >= 0 )
                      {
                        v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetQwordValue(
                               (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                               (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                               L"MaximumRecordLength",
                               v128,
                               (unsigned __int64)v62);
                        v9 = v8;
                        if ( v8 >= 0 )
                        {
                          v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                 (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                 (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                 L"VideoEncodingBitrateMode",
                                 (const unsigned __int16 *)v103,
                                 v63);
                          v9 = v8;
                          if ( v8 >= 0 )
                          {
                            v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                   (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                   (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                   L"VideoEncodingResolutionMode",
                                   (const unsigned __int16 *)v104,
                                   v64);
                            v9 = v8;
                            if ( v8 >= 0 )
                            {
                              v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                     (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                     (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                     L"VideoEncodingFrameRateMode",
                                     (const unsigned __int16 *)v117,
                                     v65);
                              v9 = v8;
                              if ( v8 >= 0 )
                              {
                                v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                       (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                       (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                       L"EchoCancellationEnabled",
                                       (const unsigned __int16 *)v130,
                                       v66);
                                v9 = v8;
                                if ( v8 >= 0 )
                                {
                                  v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                         (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                         (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                         L"CursorCaptureEnabled",
                                         (const unsigned __int16 *)v131,
                                         v67);
                                  v9 = v8;
                                  if ( v8 >= 0 )
                                  {
                                    v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                           (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                           (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                           L"VKToggleGameBar",
                                           (const unsigned __int16 *)v118,
                                           v68);
                                    v9 = v8;
                                    if ( v8 >= 0 )
                                    {
                                      v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                             (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                             (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                             L"VKMToggleGameBar",
                                             (const unsigned __int16 *)v119,
                                             v69);
                                      v9 = v8;
                                      if ( v8 >= 0 )
                                      {
                                        v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                               (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                               (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                               L"VKSaveHistoricalVideo",
                                               (const unsigned __int16 *)v120,
                                               v70);
                                        v9 = v8;
                                        if ( v8 >= 0 )
                                        {
                                          v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                 (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                 (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                 L"VKMSaveHistoricalVideo",
                                                 (const unsigned __int16 *)v121,
                                                 v71);
                                          v9 = v8;
                                          if ( v8 >= 0 )
                                          {
                                            v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                   (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                   (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                   L"VKToggleRecording",
                                                   (const unsigned __int16 *)v122,
                                                   v72);
                                            v9 = v8;
                                            if ( v8 >= 0 )
                                            {
                                              v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                     (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                     (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                     L"VKMToggleRecording",
                                                     (const unsigned __int16 *)v123,
                                                     v73);
                                              v9 = v8;
                                              if ( v8 >= 0 )
                                              {
                                                v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                       (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                       (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                       L"VKTakeScreenshot",
                                                       (const unsigned __int16 *)v124,
                                                       v74);
                                                v9 = v8;
                                                if ( v8 >= 0 )
                                                {
                                                  v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                         (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                         (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                         L"VKMTakeScreenshot",
                                                         (const unsigned __int16 *)v125,
                                                         v75);
                                                  v9 = v8;
                                                  if ( v8 >= 0 )
                                                  {
                                                    v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                           (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                           (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                           L"VKToggleRecordingIndicator",
                                                           (const unsigned __int16 *)v108,
                                                           v76);
                                                    v9 = v8;
                                                    if ( v8 >= 0 )
                                                    {
                                                      v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                             (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                             (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                             L"VKMToggleRecordingIndicator",
                                                             (const unsigned __int16 *)v109,
                                                             v77);
                                                      v9 = v8;
                                                      if ( v8 >= 0 )
                                                      {
                                                        v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                               (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                               (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                               L"VKToggleMicrophoneCapture",
                                                               (const unsigned __int16 *)v110,
                                                               v78);
                                                        v9 = v8;
                                                        if ( v8 >= 0 )
                                                        {
                                                          v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                 (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                 (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                 L"VKMToggleMicrophoneCapture",
                                                                 (const unsigned __int16 *)v111,
                                                                 v79);
                                                          v9 = v8;
                                                          if ( v8 >= 0 )
                                                          {
                                                            v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                   (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                   (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                   L"VKToggleCameraCapture",
                                                                   (const unsigned __int16 *)v112,
                                                                   v80);
                                                            v9 = v8;
                                                            if ( v8 >= 0 )
                                                            {
                                                              v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                     (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                     (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                     L"VKMToggleCameraCapture",
                                                                     (const unsigned __int16 *)v113,
                                                                     v81);
                                                              v9 = v8;
                                                              if ( v8 >= 0 )
                                                              {
                                                                v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                       (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                       (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                       L"VKToggleBroadcast",
                                                                       (const unsigned __int16 *)v114,
                                                                       v82);
                                                                v9 = v8;
                                                                if ( v8 >= 0 )
                                                                {
                                                                  v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                         (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                         (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                         L"VKMToggleBroadcast",
                                                                         (const unsigned __int16 *)v115,
                                                                         v83);
                                                                  v9 = v8;
                                                                  if ( v8 >= 0 )
                                                                  {
                                                                    v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetDwordValue(
                                                                           (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                           (HKEY)L"Software\\Microsoft\\Windows\\CurrentVersion\\GameDVR",
                                                                           L"MicrophoneCaptureEnabled",
                                                                           (const unsigned __int16 *)v132,
                                                                           v84);
                                                                    v9 = v8;
                                                                    if ( v8 >= 0 )
                                                                    {
                                                                      v36 = v105 * 10000.0;
                                                                      v37 = 0LL;
                                                                      if ( v105 * 10000.0 >= 9.223372036854776e18 )
                                                                      {
                                                                        v36 = v36 - 9.223372036854776e18;
                                                                        if ( v36 < 9.223372036854776e18 )
                                                                          v37 = 0x8000000000000000uLL;
                                                                      }
                                                                      v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetQwordValue(
                                                                             (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                             (HKEY)L"Software\\Microsoft\\Windows\\Current"
                                                                                    "Version\\GameDVR",
                                                                             L"SystemAudioGain",
                                                                             (const unsigned __int16 *)(v37 + (unsigned int)(int)v36),
                                                                             (unsigned __int64)v85);
                                                                      v9 = v8;
                                                                      if ( v8 >= 0 )
                                                                      {
                                                                        v38 = v106 * 10000.0;
                                                                        v39 = 0LL;
                                                                        if ( v106 * 10000.0 >= 9.223372036854776e18 )
                                                                        {
                                                                          v38 = v38 - 9.223372036854776e18;
                                                                          if ( v38 < 9.223372036854776e18 )
                                                                            v39 = 0x8000000000000000uLL;
                                                                        }
                                                                        v8 = Windows::Media::Capture::Internal::GameDVRUtility::RegSetQwordValue(
                                                                               (Windows::Media::Capture::Internal::GameDVRUtility *)0xFFFFFFFF80000001LL,
                                                                               (HKEY)L"Software\\Microsoft\\Windows\\Curre"
                                                                                      "ntVersion\\GameDVR",
                                                                               L"MicrophoneGain",
                                                                               (const unsigned __int16 *)(v39 + (unsigned int)(int)v38),
                                                                               (unsigned __int64)v86);
                                                                        v9 = v8;
                                                                        if ( v8 >= 0 )
                                                                        {
                                                                          v8 = Windows::Media::Capture::AppCaptureSettings::CompareSettings(
                                                                                 v107,
                                                                                 a1,
                                                                                 a2,
                                                                                 a3,
                                                                                 a4);
                                                                          v9 = v8;
                                                                          if ( v8 >= 0 )
                                                                            goto LABEL_230;
                                                                          v10 = 269;
                                                                        }
                                                                        else
                                                                        {
                                                                          v10 = 266;
                                                                        }
                                                                      }
                                                                      else
                                                                      {
                                                                        v10 = 263;
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      v10 = 259;
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    v10 = 256;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  v10 = 255;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                v10 = 254;
                                                              }
                                                            }
                                                            else
                                                            {
                                                              v10 = 253;
                                                            }
                                                          }
                                                          else
                                                          {
                                                            v10 = 252;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          v10 = 251;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        v10 = 250;
                                                      }
                                                    }
                                                    else
                                                    {
                                                      v10 = 249;
                                                    }
                                                  }
                                                  else
                                                  {
                                                    v10 = 248;
                                                  }
                                                }
                                                else
                                                {
                                                  v10 = 247;
                                                }
                                              }
                                              else
                                              {
                                                v10 = 246;
                                              }
                                            }
                                            else
                                            {
                                              v10 = 245;
                                            }
                                          }
                                          else
                                          {
                                            v10 = 244;
                                          }
                                        }
                                        else
                                        {
                                          v10 = 243;
                                        }
                                      }
                                      else
                                      {
                                        v10 = 242;
                                      }
                                    }
                                    else
                                    {
                                      v10 = 241;
                                    }
                                  }
                                  else
                                  {
                                    v10 = 238;
                                  }
                                }
                                else
                                {
                                  v10 = 237;
                                }
                              }
                              else
                              {
                                v10 = 236;
                              }
                            }
                            else
                            {
                              v10 = 235;
                            }
                          }
                          else
                          {
                            v10 = 234;
                          }
                        }
                        else
                        {
                          v10 = 233;
                        }
                      }
                      else
                      {
                        v10 = 232;
                      }
                    }
                    else
                    {
                      v10 = 231;
                    }
                  }
                  else
                  {
                    v10 = 230;
                  }
                }
                else
                {
                  v10 = 229;
                }
              }
              else
              {
                v10 = 228;
              }
            }
            else
            {
              v10 = 227;
            }
          }
          else
          {
            v10 = 226;
          }
        }
        else
        {
          v10 = 225;
        }
      }
      else
      {
        v10 = 224;
      }
    }
    else
    {
      v10 = 223;
    }
  }
  else
  {
    v10 = 222;
  }
LABEL_5:
  v11 = v8;
LABEL_229:
  BcastDVRLogProviderBase::LogError(
    v11,
    "Windows::Media::Capture::AppCaptureSettings::ApplySettings",
    "multimedia\\bcastdvr\\server\\appcapturesettings\\lib\\appcapturesettings.cpp",
    v10,
    1);
LABEL_230:
  v40 = v126;
  if ( v126 )
  {
    v126 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v40 + 16LL))(v40);
  }
  v41 = v127;
  if ( v127 )
  {
    v127 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v41 + 16LL))(v41);
  }
  v42 = v94;
  if ( v94 )
  {
    v94 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v42 + 16LL))(v42);
  }
  v43 = v95;
  if ( v95 )
  {
    v95 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v43 + 16LL))(v43);
  }
  v44 = v97;
  if ( v97 )
  {
    v97 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v44 + 16LL))(v44);
  }
  v45 = v98;
  if ( v98 )
  {
    v98 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v45 + 16LL))(v45);
  }
  if ( a1 )
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *))(*(_QWORD *)a1 + 16LL))(a1);
  v46 = v93;
  if ( v93 )
  {
    v93 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v46 + 16LL))(v46);
  }
  v47 = v96;
  if ( v96 )
  {
    v96 = 0LL;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v47 + 16LL))(v47);
  }
  v48 = (__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD))v87;
  if ( v87 )
  {
    v87 = 0LL;
    ((void (__fastcall *)(__int64 (__fastcall ***)(_QWORD, _QWORD, _QWORD)))(*v48)[2])(v48);
  }
  v49 = v107;
  if ( v107 )
  {
    v107 = 0LL;
    (*(void (__fastcall **)(struct Windows::Media::Capture::IAppCaptureSettings *))(*(_QWORD *)v49 + 16LL))(v49);
  }
  return v9;
}
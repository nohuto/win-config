__int64 __fastcall GetRawMouseThrottlingThresholds(__int64 a1)
{
  __int64 v2; // rcx
  __int128 v3; // xmm1
  __int128 v4; // xmm0
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int64 v9; // xmm1_8
  __int64 result; // rax
  __int128 v11; // [rsp+20h] [rbp-29h]
  __int128 v12; // [rsp+30h] [rbp-19h]
  __int128 v13; // [rsp+40h] [rbp-9h]
  __int128 v14; // [rsp+50h] [rbp+7h]
  __int128 v15; // [rsp+60h] [rbp+17h]
  __int128 v16; // [rsp+70h] [rbp+27h]

  v2 = *(_QWORD *)(W32GetUserSessionState() + 3136);
  if ( v2 )
  {
    v3 = *(_OWORD *)(v2 + 1904);
    *(_OWORD *)a1 = *(_OWORD *)(v2 + 1888);
    v4 = *(_OWORD *)(v2 + 1920);
    *(_OWORD *)(a1 + 16) = v3;
    v5 = *(_OWORD *)(v2 + 1936);
    *(_OWORD *)(a1 + 32) = v4;
    v6 = *(_OWORD *)(v2 + 1952);
    *(_OWORD *)(a1 + 48) = v5;
    v7 = *(_OWORD *)(v2 + 1968);
    *(_OWORD *)(a1 + 64) = v6;
    v8 = *(_OWORD *)(v2 + 1984);
    *(_OWORD *)(a1 + 80) = v7;
    v9 = *(_QWORD *)(v2 + 2000);
  }
  else
  {
    *(_QWORD *)&v13 = 0LL;                      // Forced = 0 (default)
    *((_QWORD *)&v11 + 1) = 1LL;                // Enabled = 1 (default)
    *(_QWORD *)&v11 = L"RawMouseThrottleEnabled";
    *((_QWORD *)&v12 + 1) = L"RawMouseThrottleForced";
    *(_QWORD *)&v14 = L"RawMouseThrottleDuration";
    *(_OWORD *)a1 = v11;
    *(_QWORD *)&v12 = 1LL;                      // Enabled = 1 (maximum)
    *((_QWORD *)&v13 + 1) = 1LL;                // Forced = 1
    *((_QWORD *)&v14 + 1) = 0x100000008LL;      // Duration = 8 (default, 125Hz)
    *(_OWORD *)(a1 + 16) = v12;
    *(_QWORD *)&v15 = 20LL;                     // Duration = 20 (maximum)
    *(_OWORD *)(a1 + 32) = v13;
    *((_QWORD *)&v15 + 1) = L"RawMouseThrottleLeeway";
    *(_QWORD *)&v16 = 2LL;                      // Leeway = 2 (default)
    *(_OWORD *)(a1 + 48) = v14;
    *((_QWORD *)&v16 + 1) = 5LL;                // Leeway = 5 (maximum)
    *(_OWORD *)(a1 + 64) = v15;
    v8 = 0x32uLL;
    *(_OWORD *)(a1 + 80) = v16;
    v9 = 0LL;
  }
  *(_OWORD *)(a1 + 96) = v8;
  result = a1;
  *(_QWORD *)(a1 + 112) = v9;
  return result;
}
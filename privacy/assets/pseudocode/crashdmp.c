__int64 __fastcall sub_1C0008BBC(__int64 a1)
{
  int v2; // eax
  int v3; // ecx
  int v4; // ebx
  __int64 v5; // rsi
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // ebx
  _DWORD v10[4]; // [rsp+20h] [rbp-60h] BYREF
  _WORD v11[32]; // [rsp+30h] [rbp-50h] BYREF

  v10[0] = 0;
  sub_1C0012710(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl", L"CrashDumpEnabled", v10, 0);
  switch ( v10[0] )
  {
    case 0:
      goto LABEL_11;
    case 1:
      *(_DWORD *)(a1 + 24) = 5;
      goto LABEL_12;
    case 2:
      goto LABEL_9;
    case 3:
      *(_DWORD *)(a1 + 24) = 4;
      goto LABEL_12;
    case 4:
LABEL_11:
      *(_DWORD *)(a1 + 24) = v10[0];
      goto LABEL_12;
    case 7:
LABEL_9:
      *(_DWORD *)(a1 + 24) = 6;
      goto LABEL_12;
  }
  *(_DWORD *)(a1 + 24) = 0;
LABEL_12:
  if ( (int)sub_1C0012710(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl", L"LogEvent", v10, 0) >= 0
    && v10[0]
    && !*(_DWORD *)(a1 + 24) )
  {
    *(_DWORD *)(a1 + 24) = 4;
  }
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"SendAlert",
              v10,
              0) >= 0
    && v10[0]
    && !*(_DWORD *)(a1 + 24) )
  {
    *(_DWORD *)(a1 + 24) = 4;
  }
  v2 = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 28) = v2;
  *(_DWORD *)(a1 + 1464) = v2;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"ResumeCapable",
              v10,
              0xFFFFFFFFLL) < 0
    || v10[0] == -1 )
  {
    dword_1C001C500 = -1;
  }
  else
  {
    dword_1C001C500 = v10[0] == 1;
  }
  byte_1C001C4EB = (int)sub_1C0012710(
                          L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"EnableLogFile",
                          v10,
                          0) >= 0
                && (*(_DWORD *)(a1 + 32) & 0x10000) == 0
                && v10[0] != 0;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"DumpLogLevel",
              v10,
              0) < 0 )
  {
    dword_1C001C504 = 0;
  }
  else
  {
    v3 = v10[0];
    if ( (unsigned int)(v10[0] - 2) <= 0xFFFFFFFC )
      v3 = 0;
    dword_1C001C504 = v3;
  }
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"SimulateError",
              v10,
              0) >= 0 )
    *(_DWORD *)(a1 + 1796) = v10[0];
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"SimulateNotReady",
              v10,
              0) >= 0
    && v10[0] )
  {
    *(_DWORD *)(a1 + 32) |= 0x10u;
  }
  if ( (int)sub_1C0012710(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl", L"Flags", v10, 4) >= 0 )
    dword_1C001C508 = v10[0];
  *(_DWORD *)(a1 + 32) |= 0x20u;
  v10[0] = 0;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\StorageTelemetry",
              L"DeviceDumpEnabled",
              v10,
              1) >= 0 )
    *(_DWORD *)(a1 + 32) = (v10[0] != 0 ? 0x20 : 0) | *(_DWORD *)(a1 + 32) & 0xFFFFFFDF;
  v4 = 0;
  v5 = 1808;
  while ( v4 < 8 )
  {
    v11[0] = 0;
    sub_1C0008FC8(v11, 32, L"StorageTCCode_%1x", (unsigned int)v4);
    v6 = sub_1C0012710(
           L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\StorageTelemetry",
           v11,
           v10,
           0);
    v7 = 0;
    if ( v6 >= 0 )
      v7 = v10[0];
    ++v4;
    *(_DWORD *)(v5 + a1) = v7;
    v5 += 4;
  }
  *(_DWORD *)(a1 + 1496) &= ~1u;
  dword_1C001C2D8 &= ~2u;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"FilterPages",
              v10,
              0) >= 0
    && v10[0] )
  {
    dword_1C001C2D8 |= 2u;
  }
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"EnablePartialKernelDumpFallback",
              v10,
              0) >= 0 )
    byte_1C001C560 = v10[0] != 0;
  *(_WORD *)(a1 + 2004) = 110;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"IoSpaceLargeDumpThreshold",
              v10,
              0) >= 0
    && v10[0] )
  {
    if ( v10[0] > 0xFFFFu )
      *(_WORD *)(a1 + 2004) = -1;
    else
      *(_WORD *)(a1 + 2004) = v10[0];
  }
  *(_WORD *)(a1 + 2006) = 1024;
  if ( (int)sub_1C0012710(
              L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
              L"RegularLargeDumpThreshold",
              v10,
              0) >= 0
    && v10[0] )
  {
    if ( v10[0] > 0xFFFFu )
      *(_WORD *)(a1 + 2006) = -1;
    else
      *(_WORD *)(a1 + 2006) = v10[0];
  }
  v8 = *(_DWORD *)(a1 + 24) == 0 ? 0xC0000001 : 0;
  sub_1C0008AC8(a1);
  return v8;
}
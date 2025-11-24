__int64 __fastcall CWin32OS::PutInstance(CWin32OS *this, const struct CInstance *a2, char a3)
{
  int v5; // r12d
  __int64 v6; // r15
  unsigned __int16 *v7; // rdx
  unsigned __int16 *v8; // rax
  __int64 v9; // r8
  int v10; // edx
  int v11; // ecx
  __int64 v12; // rax
  unsigned __int16 *v13; // rdx
  unsigned int v14; // r8d
  unsigned int v15; // eax
  int v16; // r14d
  unsigned int v17; // edi
  int v18; // edi
  unsigned int v19; // ebx
  int v20; // eax
  const wchar_t *v21; // rax
  HKEY v22; // rax
  LSTATUS v23; // eax
  unsigned __int16 *v24; // rdx
  unsigned int v25; // r8d
  unsigned __int8 v26[4]; // [rsp+30h] [rbp-D0h] BYREF
  BYTE Data[4]; // [rsp+34h] [rbp-CCh] BYREF
  unsigned __int8 *v28; // [rsp+38h] [rbp-C8h] BYREF
  int v29; // [rsp+40h] [rbp-C0h]
  __int64 v30; // [rsp+48h] [rbp-B8h] BYREF
  _BYTE v31[8]; // [rsp+50h] [rbp-B0h] BYREF
  _BYTE v32[8]; // [rsp+58h] [rbp-A8h] BYREF
  _BYTE v33[8]; // [rsp+60h] [rbp-A0h] BYREF
  _BYTE v34[8]; // [rsp+68h] [rbp-98h] BYREF
  _BYTE v35[608]; // [rsp+70h] [rbp-90h] BYREF

  if ( (a3 & 2) != 0 )
    return 2147749941LL;
  CHString::CHString((CHString *)v33);
  CHString::CHString((CHString *)v32);
  v29 = 0;
  CRegistry::CRegistry((CRegistry *)v35);
  v5 = 0;
  v26[0] = 0;
  CSystemName::CSystemName((CSystemName *)v31);
  v30 = 0LL;
  v6 = 0LL;
  v28 = 0LL;
  if ( CInstance::IsNull(a2, L"Description") )
    goto LABEL_15;
  CInstance::GetCHString(a2, L"Description", (struct CHString *)v32);
  if ( (unsigned int)CNetAPI32::Init((CNetAPI32 *)&v30)
    || CNetAPI32::NetServerGetInfo((CNetAPI32 *)&v30, v7, 0x65u, &v28) )
  {
    goto LABEL_15;
  }
  v8 = (unsigned __int16 *)CHString::operator unsigned short const *(v32);
  v9 = *((_QWORD *)v28 + 4) - (_QWORD)v8;
  do
  {
    v10 = *(unsigned __int16 *)((char *)v8 + v9);
    v11 = *v8 - v10;
    if ( v11 )
      break;
    ++v8;
  }
  while ( v10 );
  if ( !v11 )
  {
LABEL_15:
    v16 = 0;
LABEL_16:
    v18 = -2147217407;
    v19 = -2147217407;
    v20 = CRegistry::Open(
            (CRegistry *)v35,
            HKEY_LOCAL_MACHINE,
            L"SYSTEM\\CurrentControlSet\\Control\\PriorityControl",
            0x2001Fu);
    if ( v20 )
    {
      if ( v20 == 5 )
        v18 = -2147217405;
      v19 = v18;
    }
    else
    {
      if ( !CRegistry::GetCurrentKeyValue((CRegistry *)v35, L"Win32PrioritySeparation", (struct CHString *)v33) )
      {
        v19 = 0;
        v21 = (const wchar_t *)CHString::operator unsigned short const *(v33);
        *(_DWORD *)Data = _wtoi(v21);
        if ( !CInstance::IsNull(a2, L"ForegroundApplicationBoost") )
        {
          CInstance::GetByte(a2, L"ForegroundApplicationBoost", v26);
          if ( (v26[0] & 0xFC) != 0 || v26[0] == 3 )
            v19 = -2147217365;
          else
            v29 |= v26[0];
          *(_DWORD *)Data &= 0xFFFFFFFC;
          v5 = 1;
        }
      }
      if ( !v5 )
      {
LABEL_30:
        if ( !v19 )
          goto LABEL_39;
        goto LABEL_35;
      }
      if ( !v19 )
      {
        *(_DWORD *)Data |= v29;
        CHString::CHString((CHString *)v34);
        CHString::Format((CHString *)v34, L"%d", *(unsigned int *)Data);
        v22 = CRegistry::GethKey((CRegistry *)v35);
        v23 = RegSetValueExW(v22, L"Win32PrioritySeparation", 0, 4u, Data, 4u);
        if ( v23 == 5 )
          v19 = -2147217405;
        else
          v19 = v23 != 0 ? 0x80041001 : 0;
        CHString::~CHString((CHString *)v34);
        goto LABEL_30;
      }
    }
LABEL_35:
    if ( v16 && !(unsigned int)CNetAPI32::Init((CNetAPI32 *)&v30) )
    {
      if ( !v28 )
      {
LABEL_41:
        if ( !v19 && !CInstance::IsNull(a2, L"LargeSystemCache") )
          v19 = -2147217396;
        CNetAPI32::~CNetAPI32((CNetAPI32 *)&v30);
        CRegistry::~CRegistry((CRegistry *)v35);
        CHString::~CHString((CHString *)v32);
        CHString::~CHString((CHString *)v33);
        return v19;
      }
      *((_QWORD *)v28 + 4) = v6;
      CNetAPI32::NetServerSetInfo((CNetAPI32 *)&v30, v24, v25, v28, 0LL);
    }
LABEL_39:
    if ( v28 )
    {
      *((_QWORD *)v28 + 4) = v6;
      CNetAPI32::NetApiBufferFree((CNetAPI32 *)&v30, v28);
    }
    goto LABEL_41;
  }
  v6 = *((_QWORD *)v28 + 4);
  v12 = CHString::operator unsigned short const *(v32);
  *((_QWORD *)v28 + 4) = v12;
  v15 = CNetAPI32::NetServerSetInfo((CNetAPI32 *)&v30, v13, v14, v28, 0LL);
  if ( !v15 )
  {
    v16 = 1;
    goto LABEL_16;
  }
  v17 = -2147217407;
  if ( v15 == 5 )
    v17 = -2147217405;
  *((_QWORD *)v28 + 4) = v6;
  CNetAPI32::NetApiBufferFree((CNetAPI32 *)&v30, v28);
  CNetAPI32::~CNetAPI32((CNetAPI32 *)&v30);
  CRegistry::~CRegistry((CRegistry *)v35);
  CHString::~CHString((CHString *)v32);
  CHString::~CHString((CHString *)v33);
  return v17;
}
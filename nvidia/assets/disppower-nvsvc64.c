_QWORD *__fastcall sub_1800869D0(__int64 (__fastcall ***a1)(_QWORD))
{
  DWORD v2; // esi
  _QWORD *v3; // rdi
  void *v4; // rax
  HPOWERNOTIFY v5; // rbx
  _QWORD *v6; // rax
  _QWORD *v8; // [rsp+38h] [rbp+10h] BYREF

  v2 = 1;
  v3 = 0LL;
  if ( (unsigned int)sub_18007C6DC(L"DisplayPowerSaving") == 1 )
  {
    LODWORD(v8) = -1;
    if ( !(unsigned int)sub_1800A11F0(&v8) && (_DWORD)v8 != -1 )
    {
      v4 = (void *)(**a1)(a1);
      v5 = RegisterPowerSettingNotification(v4, &Buf2, 0);
      if ( v5 )
      {
        v2 = 0;
        v6 = operator new(0x10uLL);
        v8 = v6;
        if ( v6 )
        {
          v6[1] = v5;
          *v6 = &CNvDPS::`vftable';
          v3 = v6;
        }
      }
    }
  }
  PowerWriteSettingAttributes(&SubGroupGuid, &Buf2, v2);
  return v3;
}
__int64 __fastcall anonymous_namespace_::TextScaleDialogTemplate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // r8
  int v7; // eax
  unsigned int v8; // ebx
  unsigned int v10; // [rsp+20h] [rbp-28h] BYREF
  wil::details::in1diag3 *retaddr; // [rsp+48h] [rbp+0h]

  v10 = 0;
  if ( (int)SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\Accessibility", L"TextScaleFactor", &v10) < 0
    || (v6 = v10, v10 - 101 > 0x7C) )
  {
    v6 = 100LL;
  }
  v7 = anonymous_namespace_::ScaleDialogTemplate(a1, a2, v6, a3);
  v8 = v7;
  if ( v7 >= 0 )
    return 0LL;
  wil::details::in1diag3::Return_Hr(
    retaddr,
    (void *)0xA3,
    (unsigned int)"onecore\\internal\\shell\\inc\\private\\ShCore-Win32DialogResourceHelpers.h",
    (const char *)(unsigned int)v7,
    v10);
  return v8;
}
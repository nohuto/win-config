# Disable Rounded Corners

Uses [Win11DisableRoundedCorners](https://github.com/valinet/Win11DisableRoundedCorners), which patches (a copy, keeps original as `System32\uDWM_win11drc.bak`) `CTopLevelWindow::GetEffectiveCornerStyle` in `uDWM.dll` that exists on every W11 build so far.

### Rounded Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/rounded.png?raw=true)

### Angular Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/angular.png?raw=true)

## [GetEffectiveCornerStyle](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/uDWM/-GetEffectiveCornerStyle@CTopLevelWindow@@AEAA-AW4CORNER_STYLE@@XZ.c)

It works by overriding the first 8 bytes in the function with `48 C7 C0 00 00 00 00 C3`:

```c
mov rax, 0; ret // result = 0
```

That start usually picks a windows corner style (style apps set (`CWindowList::SetCornerStyle`) would still be used):

```c
// CTopLevelWindow::GetEffectiveCornerStyle (uDWM, 25H2)

/*
 * XREFs of ?GetEffectiveCornerStyle@CTopLevelWindow@@AEAA?AW4CORNER_STYLE@@XZ
 * Callers:
 *     ?GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ
 *     ?GetShadowStyle@CTopLevelWindow@@AEAA?AW4ShadowStyle@CWindowBorder@@XZ
 * Callees:
 *     ?HasThinRenderedBorder@CTopLevelWindow@@SA_NI@Z
 *     ?HasRenderedBorder@CTopLevelWindow@@SA_NI@Z
 *     ?ReportUsage@?$FeatureImpl@U__WilFeatureTraits_Feature_RAIL_ServerWindowRounding@@@details@wil@@QEAAX_NW4ReportingKind@3@_K@Z
 */

  result = *(unsigned int *)(*(_QWORD *)(a1 + 712) + 184LL); // style set by app, 0 = none
  if ( !(_DWORD)result )
  {
    if ( CTopLevelWindow::HasThinRenderedBorder(*(_DWORD *)(a1 + 584)) )
      return 3LL; // small rounded
    else
      return (unsigned int)CTopLevelWindow::HasRenderedBorder(v4) + 1; // 2 = rounded, 1 = square
  }
  return result;

// after patch

  __int64 CTopLevelWindow::GetEffectiveCornerStyle()
{
  return 0LL;
}
```

### [GetRadiusFromCornerStyle](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/uDWM/-GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ.c)

After the patch `GetEffectiveCornerStyle` returns `0` for every window, its callers are [`GetRadiusFromCornerStyle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/uDWM/-GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ.c) & [`GetShadowStyle`](https://github.com/nohuto/pseudocode/blob/main/11-25H2/uDWM/-GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ.c):

```c
/*
 * XREFs of ?GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ @ 0x18000F9FC
 * Callers:
 *     ?GetFloatCornerRadiusForCurrentStyle@CTopLevelWindow@@AEAAMXZ @ 0x18000F534 (-GetFloatCornerRadiusForCurrentStyle@CTopLevelWindow@@AEAAMXZ.c)
 *     ?GetDpiAdjustedFloatCornerRadius@CTopLevelWindow@@QEAAMXZ @ 0x18007DC28 (-GetDpiAdjustedFloatCornerRadius@CTopLevelWindow@@QEAAMXZ.c)
 * Callees:
 *     ?GetEffectiveCornerStyle@CTopLevelWindow@@AEAA?AW4CORNER_STYLE@@XZ @ 0x18000F8BC (-GetEffectiveCornerStyle@CTopLevelWindow@@AEAA-AW4CORNER_STYLE@@XZ.c)
 */

float __fastcall CTopLevelWindow::GetRadiusFromCornerStyle(CTopLevelWindow *this, __int64 a2)
{
  float v2; // xmm6_4
  int v3; // eax
  int v4; // eax

  v2 = 0.0;
  v3 = CTopLevelWindow::GetEffectiveCornerStyle((__int64)this, a2) - 2;
  if ( !v3 )
    return FLOAT_8_0; // 2 = rounded
  v4 = v3 - 1;
  if ( !v4 )
    return FLOAT_4_0; // 3 = small rounded
  if ( v4 == 1 )
    return FLOAT_8_0; // 0 & 1 = square
  return v2; // every other style = square
}
```

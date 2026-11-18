# Disable Rounded Corners

This currently works via [Win11DisableRoundedCorners](https://github.com/valinet/Win11DisableRoundedCorners) which works fine on [latest version since the function exists/works the same on latest builds](https://noverse.dev/diff?kind=pseudocode). Note that the revert doesn't run `sfc /scannow` to restore proper file permissions to `uDWM.dll` since it does a lot more than restoring permissions. If you're aware if it, run the command after reverting the option.

It works by overriding the first 8 bytes in the function with `48 C7 C0 00 00 00 00 C3`:

```c
mov rax, 0; ret // result = 0
```

### Rounded Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/rounded.png?raw=true)

### Angular Corners

![](https://github.com/nohuto/win-config/blob/main/visibility/images/angular.png?raw=true)

## [GetEffectiveCornerStyle](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-GetEffectiveCornerStyle@CTopLevelWindow@@AEAA-AW4CORNER_STYLE@@XZ.c)

That function calculates the effective corner mode, its callers include border/shadow/radius.
```c
/*
 * XREFs of ?GetEffectiveCornerStyle@CTopLevelWindow@@AEAA?AW4CORNER_STYLE@@XZ @ 0x18003AB74
 * Callers:
 *     ?GetShadowStyle@CTopLevelWindow@@AEAA?AW4ShadowStyle@CWindowBorder@@XZ @ 0x18001AA04 (-GetShadowStyle@CTopLevelWindow@@AEAA-AW4ShadowStyle@CWindowBorder@@XZ.c)
 *     ?UpdateWindowVisuals@CTopLevelWindow@@AEAAJXZ @ 0x18003D8E0 (-UpdateWindowVisuals@CTopLevelWindow@@AEAAJXZ.c)
 *     ?GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ @ 0x1800E5B98 (-GetRadiusFromCornerStyle@CTopLevelWindow@@AEAAMXZ.c)
 * Callees:
 *     IsOpenThemeDataPresent @ 0x18005DB28 (IsOpenThemeDataPresent.c)
 */

__int64 __fastcall CTopLevelWindow::GetEffectiveCornerStyle(__int64 a1)
{
  __int64 result; // rax
  int v2; // ebx

  if ( *((_BYTE *)CDesktopManager::s_pDesktopManagerInstance + 27)
    && !*((_BYTE *)CDesktopManager::s_pDesktopManagerInstance + 29)
    || *((int *)CDesktopManager::s_pDesktopManagerInstance + 8) >= 2 )
  {
    return 1LL;
  }
  result = *(unsigned int *)(*(_QWORD *)(a1 + 752) + 184LL);
  if ( !(_DWORD)result )
  {
    v2 = *(_DWORD *)(a1 + 624);
    if ( (v2 & 2) != 0 )
      return 3LL;
    if ( !(unsigned __int8)IsOpenThemeDataPresent() )
      return 1LL;
    result = 2LL;
    if ( (v2 & 6) == 0 )
      return 1LL;
  }
  return result;
}
```

Obviously, `GetEffectiveCornerStyle` only exists in W11 builds (as you can see in [decompiled-pseudocode](https://github.com/nohuto/decompiled-pseudocode)).


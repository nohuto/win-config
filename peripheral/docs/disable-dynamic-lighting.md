# Disable Dynamic Lighting

> "*Dynamic Lighting is a feature that allows you to control LED-powered devices such as keyboards, mice, and other illuminated accessories. This feature enables you to coordinate the colors of LEDs, creating a unified lighting experience both within Windows and across all your devices.*"
>
> — Microsoft, [Dynamic Lighting devices](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/dynamic-lighting-devices)

```c
"HKCU\\Software\\Microsoft\\Lighting";
  // InputService.dll, SettingsHandlers_Lighting.dll
  "AmbientLightingEnabled" = 1; // REG_DWORD (bool), Dynamic Lighting on/off
  "UseSystemAccentColor" = 1; // REG_DWORD (bool), 1 = match the Windows accent color
  "Color" = ?; // REG_DWORD, COLORREF 0x00BBGGRR, used when UseSystemAccentColor = 0
  "Color2" = ?; // REG_DWORD, COLORREF, second color of some effects
  "EffectType" = 0; // REG_DWORD, 0 = solid, 1 = breathing, 2 = rainbow, 4 = wave, 5 = wheel, 6 = gradient
  "EffectMode" = 0; // REG_DWORD, direction per effect, rainbow 0 forward, 1 reverse, wave 0 right, 1 left, 2 down, 3 up, wheel 0 clockwise, 1 counterclockwise, gradient 0 horizontal, 1 vertical, 2 outward
  "Speed" = 7; // REG_DWORD, range 1-10
  "Brightness" = 100; // REG_DWORD, range 0-100 (%)
  "ControlledByForegroundApp" = 0; // REG_DWORD (bool), 1 = apps can take control
```

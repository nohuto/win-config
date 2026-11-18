# Disable Dynamic Lighting

> "*Dynamic Lighting is a feature that allows you to control LED-powered devices such as keyboards, mice, and other illuminated accessories. This feature enables you to coordinate the colors of LEDs, creating a unified lighting experience both within Windows and across all your devices.*"
>
> — Microsoft, [Dynamic Lighting devices](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/dynamic-lighting-devices)

| Value | Type | Values | Ranges | Notes |
| --- | --- | --- | --- | --- |
| `AmbientLightingEnabled` | REG_DWORD | `0 = off`, `1 = on` | `0–1` | Main toggle for Dynamic Lighting |
| `UseSystemAccentColor` | REG_DWORD | `0 = use custom Color/Color2`, `1 = match Windows accent` | `0–1` | When `1`, `Color` is ignored |
| `Color` | REG_DWORD | `COLORREF (RGB)` | `0x00000000–0x00FFFFFF`    | Format `0x00BBGGRR`. Used when `UseSystemAccentColor = 0` |
| `Color2` | REG_DWORD | `COLORREF (RGB)` | `0x00000000–0x00FFFFFF`    | Secondary color for some effects. |
| `EffectType` | REG_DWORD | `0 = Solid`, `1 = Breathing`, `2 = Rainbow`, `4 = Wave`, `5 = Wheel`, `6 = Gradient` | `discrete enum` | Defines animation |
| `Speed` | REG_DWORD | `integer` | `1–10` | Higher = faster. |
| `EffectMode` | REG_DWORD | Rainbow: `0 = Forward`, `1 = Reverse`, Wave: `0 = Right`, `1 = Left`, `2 = Down`, `3 = Up`, Wheel: `0 = Clockwise`, `1 = Counterclockwise`, Gradient: `0 = Horizontal`, `1 = Vertical`, `2 = Outward` | `discrete enum per effect` | Depends on `EffectType`. |
| `Brightness` | REG_DWORD | `integer (%)` | `0–100` | - |
| `ControlledByForegroundApp` | REG_DWORD | `0 = ignore apps`, `1 = apps can take control` | `0–1` | - |


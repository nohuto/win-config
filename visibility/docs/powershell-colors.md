# PowerShell Colors

If you use Windows Terminal, this option will have no effect.

- `ScreenColors`, located in `HKCU\Console\%WINDIR%_System32_WindowsPowerShell_v1.0_powershell.exe`  
  - `0-3` bit = `Foreground color`  
  - `4-7` bit = `Background color`

### Color Table

| Color | Binary | Decimal |
| ----- | :----: | :-----: |
| Black | `0000` | `0` |
| DarkBlue | `0001` | `1` |
| DarkGreen | `0010` | `2` |
| DarkCyan | `0011` | `3` |
| DarkRed | `0100` | `4` |
| DarkMagenta | `0101` | `5` |
| DarkYellow | `0110` | `6` |
| Gray | `0111` | `7` |
| DarkGray | `1000` | `8` |
| Blue | `1001` | `9` |
| Green | `1010` | `10` |
| Cyan | `1011` | `11` |
| Red | `1100` | `12` |
| Magenta | `1101` | `13` |
| Yellow | `1110` | `14` |
| White | `1111` | `15` |

Calculate it on your own, by using [bitmask-calc](https://noverse.dev/terminal#bitmask) - e.g. set bit `1-3` and `7`, to get `Yellow` (foreground) and `DarkGray` (background).

## Miscellaneous Notes

If you've set a custom foreground/background color, they won't override the colors changed within the code, e.g.:

```powershell
Write-Host "Noverse"
```

`Noverse` will have use foreground & background color of `ScreenColors`

```powershell
Write-Host "Noverse" -ForegroundColor Blue
```

`Noverse` will be blue, `ScreenColors` gets skipped.

```powershell
[console]::BackgroundColor = 'Black'
```

If it doesn't get changed within the code, it'll use the background color set by `ScreenColor`.


# Windows Configuration

Note that this is a powerful and highly customizable tool, so you shouldn't go through every section and enable everything. Read the documentation first, as some options may require specific operations before you can use them. Dynamic state detection is strict, if values **A** and **C** are correct but **B** is not, the option is considered **disabled**.

Also note that many options have suboptions that aren't always included in the main option. You can use these to customize the settings if you don't like the default behavior. See `Explorer Options` (Visibility) for an example.

The documentation is based on the GitHub repository and parses it's information out of it. All [`App Tools`](https://github.com/nohuto/app-tools)/[`Game Tools`](https://github.com/nohuto/game-tools) are external PowerShell scripts, same goes for the [`Component Manager`](https://github.com/nohuto/comp-mgr), [`Blocklist Manager`](https://github.com/nohuto/blocklist-mgr) & [`Bitmask Calculator`](https://github.com/nohuto/bitmask-calc).

## Tool Settings

All tool settings can be changed via registry or the gear on the top left, these are personal recommendations, warnings and notes on each setting:
```c
// Search filter - note that enabling these will increase search time
reg add "HKCU\Software\Noverse" /v IncludeValueNames /t REG_DWORD /d 1 /f // Includes value (registry) names which would get set by a option
reg add "HKCU\Software\Noverse" /v IncludeTextContent /t REG_DWORD /d 1 /f // Includes markdown content (option description)
reg add "HKCU\Software\Noverse" /v IncludeSuboptionNames /t REG_DWORD /d 1 f // Includes option names from 'Suboptions for customization' part

// Maximum of 10000, minimum of 100 (not recommended). Please increase it if you write slowly
reg add "HKCU\Software\Noverse" /v SearchDelayMs /t REG_DWORD /d 1000 /f

// Personal preference, these are personal recommendations
reg add "HKCU\Software\Noverse" /v ResizeCoalesceDelayMs /t REG_DWORD /d 0 /f // default 10, range 0-1000
reg add "HKCU\Software\Noverse" /v MinCardWidth /t REG_DWORD /d 250  /f // default 200, range 50-1000
reg add "HKCU\Software\Noverse" /v MaxOptionColumns /t REG_DWORD /d 20 /f // default 10, range 1-20
reg add "HKCU\Software\Noverse" /v MaxVisibleRows /t REG_DWORD /d 8 /f // default 6, range 1-20

// Personal preference
reg add "HKCU\Software\Noverse" /v LogsHidden /t REG_DWORD /d 1 /f

// Experimental, preferable leave it disabled
reg add "HKCU\Software\Noverse" /v TrayIconEnabled /t REG_DWORD /d 0 /f

// The tool has no accent color/theme defaults, it reads the system defaults and uses them as long as you don't override them via the tool settings/registry

// Chaning accent color/theme via registry (any 6 digit hex value)
reg add "HKCU\Software\Noverse" /v AccentColor /t REG_SZ /d "#356A9F" /f

// 'dark'/'light' (dark mode has better implementation at the moment)
reg add "HKCU\Software\Noverse" /v Theme /t REG_SZ /d "dark" /f // fallback to dark theme
```

## Shortcuts

| Shortcut | Action |
| --- | --- |
| `Ctrl+F` | Focus the search bar and select the current query |
| `Ctrl+H` / `Ctrl+0` | Jump back to the Home view |
| `Ctrl+Tab` | Cycle forward through sections |
| `Ctrl+Shift+Tab` | Cycle backward through sections |
| `Ctrl+R` / `F5` | Refresh the active section or rerun the current search |
| `Ctrl+{num}` | Load the corresponding section (`{num}` = e.g. `1` for the first section) |
| `Space` / `Enter` | Run the currently focused option card (toggle/execute) |

## Support

You can reach me either by email or, preferably, via Discord:
> https://discord.gg/E2ybG4j9jU
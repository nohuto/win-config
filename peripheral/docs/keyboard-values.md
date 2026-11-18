# Keyboard Values

| Setting | Description | Default | Changed To |
| --- | --- | --- | --- |
| **Repeat Delay**      | Controls how long you need to hold down a key before it starts repeating when typing.                    | 1           | 0              |
| **Repeat Rate**       | Adjusts how quickly a key repeats when held down after the repeat delay.                                 | 31          | 31             |
| **Cursor Blink Rate** | Controls the speed at which the text cursor blinks on the screen. You can set it to be faster or slower. | 530         | 900            |

`Disable Language Switch Hotkey` applies: `Time & language > Typing > Advanced keyboard settings : Input language hot keys`, `Between input languages` to `Not assigned` (`None`):
```powershell
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Language Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Hotkey	Type: REG_SZ, Length: 4, Data: 3
rundll32.exe	RegSetValue	HKCU\Keyboard Layout\Toggle\Layout Hotkey	Type: REG_SZ, Length: 4, Data: 3
```


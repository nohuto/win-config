# Enable Dynamic Lock

Automatically locks your device when you're away. It requires Bluetooth to be active. This option is disabled by default.

### Accounts Captures

Toggling it via `Accounts > Sign-in options`:
```c
// Enabled
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 1

// Disabled (default)
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 0
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure dynamic lock factors](https://noverse.dev/policies?p=Passport*MSPassport_UseDynamicLock) | `HKLM\SOFTWARE\Policies\Microsoft\PassportForWork\DynamicLock` | `DynamicLock`<br>`Plugins` |


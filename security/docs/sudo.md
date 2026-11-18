# Sudo

[Sudo](https://github.com/microsoft/sudo) ([introduction](https://devblogs.microsoft.com/commandline/introducing-sudo-for-windows/)) is a new way for users to run elevated commands (as an administrator) directly from an unelevated console session on Windows.

Note that sudo uses administrator previledges and doesn't include `TrustedInstaller`/`SYSTEM` previledges.

### Modes

| Mode | Description |
| ---- | ---- |
| `forceNewWindow` | Runs the command elevated in a new console window. |
| `disableInput` | Runs elevated in the same window but blocks keyboard input while it runs. |
| `normal` | Runs elevated in the same window with normal input and output behavior. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure the behavior of the sudo command](https://noverse.dev/policies?p=Sudo*EnableSudo) | `HKLM\Software\Policies\Microsoft\Windows\Sudo` | `Enabled` |


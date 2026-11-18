# Detailed Status Messages

Enables detailed messages at restart, shut down, sign out, and sign in, e.g.: "*RPCSS is starting...*" or "*Waiting for machine group policies to finish...*".

> "*This policy setting directs the system to display highly detailed status messages.*
>
> *This policy setting is designed for advanced users who require this information.*
>
> *If you enable this policy setting, the system displays status messages that reflect each step in the process of starting, shutting down, logging on, or logging off the system.*
>
> *If you disable or do not configure this policy setting, only the default status messages are displayed to the user during these processes.*
>
> *Note: This policy setting is ignored if the ""Remove Boot/Shutdown/Logon/Logoff status messages"" policy setting is enabled.*

If this option is disabled you'll still see normal messages like "*Applying your personal settings...*" or "*Applying computer settings...*".

## Suboptions

### Detailed BSoD

As the value name already says (`DisplayParameters`) it will just show additional paramters on the top left.

#### Enabled

![](https://github.com/nohuto/win-config/blob/main/system/images/detailed-bsod.jpg?raw=true)

#### Disabled

![](https://github.com/nohuto/win-config/blob/main/system/images/default-bsod.jpg?raw=true)

Enabling the options includes setting [`AutoReboot`](https://learn.microsoft.com/en-us/troubleshoot/windows-client/performance/configure-system-failure-and-recovery-options) to `0`, to prevent auto restarting.

### BsOD Smiley

Hides the smiley which is shown on the BsOD screen:

![](https://github.com/nohuto/win-config/blob/main/system/images/BSOD-smiley.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Display highly detailed status messages](https://noverse.dev/policies?p=Logon*VerboseStatus) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `VerboseStatus` |


# Hide Last Logged-In User

Note that if you use this option and don't have a password, you'll have to enter your username at each boot ([policy](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/interactive-logon-do-not-display-last-user-name)).

> "*This security setting determines whether the Windows sign-in screen will show the username of the last person who signed in on this PC.*"

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayLastUserName	Type: REG_DWORD, Length: 4, Data: 0
```

`Hide Username at Sign-In`:  
"This security setting determines whether the username of the person signing in to this PC appears at Windows sign-in, after credentials are entered, and before the PC desktop is shown."

```c
// Enabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\DontDisplayUserName	Type: REG_DWORD, Length: 4, Data: 0
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Display information about previous logons during user logon](https://noverse.dev/policies?p=WinLogon*DisplayLastLogonInfoDescription) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `DisplayLastLogonInfo` |
| [Remove logon hours expiration warnings](https://noverse.dev/policies?p=WinLogon*LogonHoursNotificationPolicyDescription) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `DontDisplayLogonHoursWarnings` |


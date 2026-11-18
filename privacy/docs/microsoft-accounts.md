# Microsoft Accounts

> "*This setting prevents using the Settings app to add a Microsoft account for single sign-on (SSO) authentication for Microsoft services and some background services, or using a Microsoft account for single sign-on to other applications or services.*
>
> *There are two options if this setting is enabled:*  
> *- Users can't add Microsoft accounts means that existing connected accounts can still sign in to the device (and appear on the Sign in screen). However, users cannot use the Settings app to add new connected accounts (or connect local accounts to Microsoft accounts).*  
> *- Users can't add or log on with Microsoft accounts means that users cannot add new connected accounts (or connect local accounts to Microsoft accounts) or use existing connected accounts through Settings.*
>
> *This setting does not affect adding a Microsoft account for application authentication. For example, if this setting is enabled, a user can still provide a Microsoft account for authentication with an application such as Mail, but the user cannot use the Microsoft account for single sign-on authentication for other applications or services (in other words, the user will be prompted to authenticate for other applications or services).*"

```c
// This policy is disabled
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 0

// Users can't add Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 1

// Users can't add or log on with Microsoft accounts
services.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System\NoConnectedUser	Type: REG_DWORD, Length: 4, Data: 3
```


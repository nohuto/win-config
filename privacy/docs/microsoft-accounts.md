# Microsoft Accounts

Local Security Policy option "Accounts: Block Microsoft accounts" (Security Settings > Local Policies > Security Options, [Accounts: Block Microsoft accounts](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/accounts-block-microsoft-accounts)):

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

## Block Microsoft Account Authentication

Stops every app/service from authenticating with a consumer MS account, only enable it if you don't use a Microsoft account anywhere on the PC.

> "*This setting controls whether users can provide Microsoft accounts for authentication for applications or services. If this setting is enabled, all applications and services on the device are prevented from using Microsoft accounts for authentication. This applies both to existing users of a device and new users who may be added. However, any application or service that has already authenticated a user will not be affected by enabling this setting until the authentication cache expires. It is recommended to enable this setting before any user signs in to a device to prevent cached tokens from being present. If this setting is disabled or not configured, applications and services can use Microsoft accounts for authentication. By default, this setting is Disabled. This setting does not affect whether users can sign in to devices by using Microsoft accounts, or the ability for users to provide Microsoft accounts via the browser for authentication with web-based applications.*"

`wlidsvc.dll` (Microsoft Account Sign-in Assistant) fails the request with `ERROR_ACCESS_DISABLED_BY_POLICY` once enabled:

```c
// IsAuthDisabledByPolicy (23H2)

v10 = (*(__int64 (__fastcall **)(struct IServiceExecutionContext *))(*(_QWORD *)a1 + 40LL))(a1);
if ( (int)RegistryHelper::ReadValueFromRegistry<unsigned long>(
            (unsigned int)&v10,
            -2147483646, // HKEY_LOCAL_MACHINE
            (unsigned int)L"Software\\Policies\\Microsoft\\MicrosoftAccount",
            (unsigned int)L"DisableUserAuth",
            v9,
            (__int64)&v14) >= 0
  && v14 )
{
  v5 = 4140;
  goto LABEL_12;
}

LABEL_12:
  v12 = -2147023636; // 0x800704EC
  Telemetry::IfFailExit(
    "onecoreuap\\ds\\ext\\live\\identity\\ntservice\\lib\\svccommon\\svcapi.cpp",
    "IsAuthDisabledByPolicy",
    v5,
    -2147023636,
    "hr = HRESULT_FROM_WIN32(ERROR_ACCESS_DISABLED_BY_POLICY)");
```

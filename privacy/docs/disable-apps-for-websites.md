# Disable Apps for Websites

Prevents websites from opening their associated apps through HTTP or HTTPS links, keeping those links in the default browser instead.

> "*This policy setting determines whether Windows supports web-to-app linking with app URI handlers.*
>
> *Enabling this policy setting enables web-to-app linking so that apps can be launched with a http(s) URI.*
>
> *Disabling this policy disables web-to-app linking and http(s) URIs will be opened in the default browser instead of launching the associated app.*
>
> *If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.*"

## Suboption

### Website Access to Language List

"Sets the HTTP Accept Language from the Language List opt-out setting." Disables [`Let websites provide locally relevant content by accessing my language list`](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#181-general).

Using [`Set-WinAcceptLanguageFromLanguageListOptOut`](https://learn.microsoft.com/en-us/powershell/module/international/set-winacceptlanguagefromlanguagelistoptout?view=windowsserver2025-ps):

```powershell
Set-WinAcceptLanguageFromLanguageListOptOut -OptOut $True
```

```c
// $True
"powershell.exe","RegSetValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut","Type: REG_DWORD, Length: 4, Data: 1"
"powershell.exe","RegDeleteValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage",""
// $False
"powershell.exe","RegDeleteValue","HKCU\Control Panel\International\User Profile\HttpAcceptLanguageOptOut",""
"powershell.exe","RegSetValue","HKCU\Software\Microsoft\Internet Explorer\International\AcceptLanguage","Type: REG_SZ, Length: 54, Data: en-US;q=0.7,en;q=0.3"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure web-to-app linking with app URI handlers](https://noverse.dev/policies?p=GroupPolicy*EnableAppUriHandlers) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableAppUriHandlers` |


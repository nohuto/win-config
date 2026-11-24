# Disable Apps for Websites

Prevents websites from opening their associated apps through HTTP or HTTPS links, keeping those links in the default browser instead.

> "*This policy setting determines whether Windows supports web-to-app linking with app URI handlers.*
>
> *Enabling this policy setting enables web-to-app linking so that apps can be launched with a http(s) URI.*
>
> *Disabling this policy disables web-to-app linking and http(s) URIs will be opened in the default browser instead of launching the associated app.*
>
> *If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure web-to-app linking with app URI handlers](https://noverse.dev/policies?p=GroupPolicy*EnableAppUriHandlers) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableAppUriHandlers` |


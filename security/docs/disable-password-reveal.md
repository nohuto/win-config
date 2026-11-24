# Disable Password Reveal

> "*This policy setting allows you to configure the display of the password reveal button in password entry user experiences. If you enable this policy setting, the password reveal button won't be displayed after a user types a password in the password entry text box. If you disable or don't configure this policy setting, the password reveal button will be displayed after a user types a password in the password entry text box. By default, the password reveal button is displayed after a user types a password in the password entry text box.*"
>
> — Microsoft, [Do not display the password reveal button](https://noverse.dev/policies?p=CredUI*DisablePasswordReveal)

## Suboption

### Picture Password Sign-In

> "*This policy setting allows you to control whether a domain user can sign in using a picture password. If you enable this policy setting, a domain user can't set up or sign in with a picture password. If you disable or don't configure this policy setting, a domain user can set up and use a picture password. Note that the user's domain password will be cached in the system vault when using this feature.*"
>
> — Microsoft, [Turn off picture password sign-in](https://noverse.dev/policies?p=CredentialProviders*BlockDomainPicturePassword)

Only applies to domain accounts, local & MS accounts keep the picture password option.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off picture password sign-in](https://noverse.dev/policies?p=CredentialProviders*BlockDomainPicturePassword) | `HKLM\Software\Policies\Microsoft\Windows\System` | `BlockDomainPicturePassword` |
| [Do not display the password reveal button](https://noverse.dev/policies?p=CredUI*DisablePasswordReveal) | `HKLM\Software\Policies\Microsoft\Windows\CredUI`<br>`HKCU\Software\Policies\Microsoft\Windows\CredUI` | `DisablePasswordReveal` |


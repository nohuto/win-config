# Account Picture

Copies the chosen PNG/BMP to `C:\ProgramData\Microsoft\User Account Pictures\*` and `user.bmp` (backup in `%ProgramData%\Noverse\AccountPictures`, which can be applied (reverted) via the suboption).

### Global Account Picture

> "*This policy setting allows an administrator to standardize the account pictures for all users on a system to the default account picture.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Apply the default account picture to all users](https://noverse.dev/policies?p=Cpls*UseDefaultTile) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `UseDefaultTile` |


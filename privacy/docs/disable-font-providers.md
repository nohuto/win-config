# Disable Font Providers

> "*This policy setting determines whether Windows is allowed to download fonts and font catalog data from an online font provider. If you enable this policy setting, Windows periodically queries an online font provider to determine whether a new font catalog is available. Windows may also download font data if needed to format or render text. If you disable this policy setting, Windows does not connect to an online font provider and only enumerates locally-installed fonts.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Font Providers](https://noverse.dev/policies?p=GroupPolicy*EnableFontProviders) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableFontProviders` |


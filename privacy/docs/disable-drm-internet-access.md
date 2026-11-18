# Disable DRM Internet Access

Prevents Windows Media Digital Rights Management (DRM) from accessing the Internet (or intranet). When enabled, Windows Media DRM is prevented from accessing the Internet (or intranet) for license acquisition and security upgrades. Secure content that is already licensed to the local computer will continue to play.

Means whenever you've DRM protected files, don't enable this option.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent Windows Media DRM Internet Access](https://noverse.dev/policies?p=WindowsMediaDRM*DisableOnline) | `HKLM\Software\Policies\Microsoft\WMDRM` | `DisableOnline` |


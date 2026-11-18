# Disable Wi-Fi Sense

Beginning with Windows 10, version 1803, Wi-Fi Sense is no longer available. The following section only applies to Windows 10, version 1709 and prior.

[Wi-Fi Sense](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#23-wi-fi-sense) is enabled by default and, when you're signed in with a Microsoft account, can share Wi-Fi access (password stays encrypted in MS servers) with your Outlook and Skype contacts, Facebook contacts can be added. When you join a new network, it asks whether to share it. Networks you used before the upgrade won't trigger the prompt.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Windows to automatically connect to suggested open hotspots, to networks shared by contacts, and to hotspots offering paid services](https://noverse.dev/policies?p=wlansvc*WiFiSense) | `HKLM\Software\Microsoft\wcmsvc\wifinetworkmanager\config` | `AutoConnectAllowedOEM` |


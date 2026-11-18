# Disable ICS / Mobile Hotspot

Disables Internet Connection Sharing (ICS), which lets Windows use one network adapter as the public/uplink interface and another as the private/downlink interface. In full mode, ICS turns the PC into a small gateway for other devices by providing NAT and local network services such as addressing through DHCP and name resolution on the private side.

When disabled, the PC can no longer share its internet connection to other devices through the connection Sharing tab / ICS UI, and ICS backed gateway scenarios such as adapter-to-adapter internet sharing or related hotspot-style sharing cannot use the SharedAccess service. ICS is only available when two or more network connections are present.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `icssvc` | Provides the ability to share a cellular data connection with another device. | Win32 Share Process (32) | RpcSs, wcmsvc | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `ALG` | Provides support for 3rd party protocol plug-ins for Internet Connection Sharing | Win32 Own Process (16) | - | C:\Windows\System32\alg.exe |
| `SharedAccess` | Provides network address translation, addressing, name resolution and/or intrusion prevention services for a home or small office network. | Win32 Share Process (32) | BFE | C:\Windows\System32\svchost.exe -k netsvcs -p |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prohibit use of Internet Connection Sharing on your DNS domain network](https://noverse.dev/policies?p=NetworkConnections*NC_ShowSharedAccessUI) | `HKLM\Software\Policies\Microsoft\Windows\Network Connections` | `NC_ShowSharedAccessUI` |


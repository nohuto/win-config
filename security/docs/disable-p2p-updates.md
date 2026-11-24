# Disable P2P Updates

Default is configured to LAN. The Group Download mode combined with Group ID, enables administrators to create custom device groups that share content between devices in the group. Download mode dictates which download sources clients are allowed to use when downloading Windows updates in addition to Windows Update servers.

Delivery Optimization keeps its own settings under `HKEY_USERS\S-1-5-20\SOFTWARE\Microsoft\Windows\CurrentVersion\DeliveryOptimization` (`\Config`, `\Settings`, `doclient.dll` `CPersistenceLocation`) and ignores them while the policy is set.

> "*Delivery Optimization is a cloud-managed, peer-to-peer client; and a downloader service that delivers updates to an organization's networked devices. Delivery Optimization allows devices to download updates from alternate sources (such as other peers on the network), in addition to Microsoft servers. Delivery Optimization combines partial bits from local devices, with partial bits from Microsoft servers to update devices in the network environment. The expected result is reduced bandwidth usage, and a faster update process.*"
>
> — Microsoft, [Delivery Optimization](https://learn.microsoft.com/en-us/windows/win32/delivery_optimization/delivery-optimization-portal)

### [DODownloadMode Data](https://learn.microsoft.com/en-us/windows/deployment/do/waas-delivery-optimization-reference#download-mode)

| Download mode option | Data  | Functionality when configured |
| ---- | :----: | ---- |
| HTTP Only | `0` | This setting disables peer-to-peer caching but still allows Delivery Optimization to download content over HTTP from the download's original source or a Microsoft Connected Cache server. This mode uses additional metadata provided by the Delivery Optimization cloud services for a peerless, reliable and efficient download experience. |
| LAN (Default) | `1` | This default operating mode for Delivery Optimization enables peer sharing on the same network. The Delivery Optimization cloud service finds other clients that connect to the Internet using the same public IP as the target client. These clients then try to connect to other peers on the same network by using their private subnet IP. |
| Group | `2` | When group mode is set, the group is automatically selected based on the device's Active Directory Domain Services (AD DS) site (Windows 10, version 1607) or the domain the device is authenticated to (Windows 10, version 1511). In group mode, peering occurs across internal subnets, between devices that belong to the same group, including devices in remote offices. You can use GroupID option to create your own custom group independently of domains and AD DS sites. Starting with Windows 10, version 1803, you can use the GroupIDSource parameter to take advantage of other method to create groups dynamically. Group download mode is the recommended option for most organizations looking to achieve the best bandwidth optimization with Delivery Optimization. |
| Internet | `3` | Enable Internet peer sources for Delivery Optimization. |
| Simple | `99` | Simple mode disables the use of Delivery Optimization cloud services completely (for offline environments). Delivery Optimization switches to this mode automatically when the Delivery Optimization cloud services are unavailable, unreachable, or when the content file size is less than 50 MB, as the default. In this mode, Delivery Optimization provides a reliable download experience over HTTP from the download's original source or a Microsoft Connected Cache server, with no peer-to-peer caching. |
| Bypass | `100` | Starting in Windows 11, this option is deprecated. Don't configure Download mode to '100' (Bypass), which can cause some content to fail to download. If you want to disable peer-to-peer functionality, configure DownloadMode to (0). If your device doesn't have internet access, configure Download Mode to (99). When you configure Bypass (100), the download bypasses Delivery Optimization and uses BITS instead. You don't need to configure this option if you're using Configuration Manager. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Download Mode](https://noverse.dev/policies?p=DeliveryOptimization*DownloadMode) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\DeliveryOptimization` | `DODownloadMode` |


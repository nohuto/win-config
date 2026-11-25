# Disable Wi-Fi

Disables Wi-Fi services/drivers, scheduled tasks, etc.

`AutoConnectEnabled` under `HKLM\SOFTWARE\Microsoft\DataCollection\Default\WifiAutoConnectConfig` exists, but no binary of W11 23H2/25H2, W10 22H2 reads it.

## Services/Drivers

| Name | Default Start | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- | --- |
| `WlanSvc` | `3` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. | Win32 Own Process (16) | nativewifip, RpcSs, Ndisuio, wcmsvc | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vwififlt` | `1` | Virtual WiFi Filter Driver | Kernel Driver (1) | - | System32\drivers\vwififlt.sys |
| `wcncsvc` | `3` | WCNCSVC hosts the Windows Connect Now Configuration which is Microsoft's Implementation of Wireless Protected Setup (WPS) protocol. This is used to configure Wireless LAN settings for an Access Point (AP) or a Wireless Device. The service is started programmatically as needed. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `WFDSConMgrSvc` | `3` | Manages connections to wireless services, including wireless display and docking. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NativeWifiP` | `3` | NativeWiFi Filter | Kernel Driver (1) | - | system32\DRIVERS\nwifi.sys |
| `Wificx` | `3` (not on Windows 10 22H2) | Wifi Network Adapter Class Extension | Kernel Driver (1) | NetAdapterCx | system32\drivers\WifiCx.sys |
| `WwanSvc` | `3` | This service manages mobile broadband (GSM & CDMA) data card/embedded module adapters and connections by auto-configuring the networks. It is strongly recommended that this service be kept running for best user experience of mobile broadband devices. | Win32 Share Process (32) | RpcSs, NdisUio | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

---

```c
"\\Microsoft\\Windows\\WCM\\WiFiTask" // %WINDIR%\System32\WiFiTask.exe
"\\Microsoft\\Windows\\WwanSvc\\NotificationTask" // %WINDIR%\System32\WiFiTask.exe wwan
```

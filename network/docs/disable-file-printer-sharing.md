# Disable File/Printer Sharing

Disables "Allow other on the network to access shared files and printers on this device" via `@FirewallAPI.dll,-28502` & `ms_server`.

```powershell
PS C:\Users\Nohuto> Get-NetFirewallRule | sort -unique Group | sort DisplayGroup | ft DisplayGroup, Group

DisplayGroup                                                                      Group
------------                                                                      -----
File and Printer Sharing                                                          @FirewallAPI.dll,-28502
File and Printer Sharing (Restrictive)                                            @FirewallAPI.dll,-28672

PS C:\Users\Nohuto> Get-NetAdapterBinding -Name *

Name                           DisplayName                                        ComponentID          Enabled
----                           -----------                                        -----------          -------
Ethernet                       File and Printer Sharing for Microsoft Networks    ms_server            False
```

## Services/Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `LanmanServer` | Supports file, print, and named-pipe sharing over the network for this computer. If this service is stopped, these functions will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SamSS, Srv2 | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `LanmanWorkstation` | Creates and maintains client network connections to remote servers using the SMB protocol. If this service is stopped, these connections will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | Bowser, MRxSmb20, NSI | C:\Windows\System32\svchost.exe -k NetworkService -p |
| `CSC` | Allows network files to be used while the local computer is offline. | Kernel Driver (1) | rdbss | system32\drivers\csc.sys |
| `CscService` | The Offline Files service performs maintenance activities on the Offline Files cache, responds to user logon and logoff events, implements the internals of the public API, and dispatches interesting events to those interested in Offline Files activities and changes in cache state. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `Dfsc` | Client driver for access to DFS Namespaces | File System Driver (2) | Mup | System32\Drivers\dfsc.sys |
| `MRxDAV` | Network Redirector that provides WebDAV file access for the WebClient service | File System Driver (2) | rdbss | \SystemRoot\system32\drivers\mrxdav.sys |
| `mrxsmb` | Implements the framework for the SMB filesystem redirector | File System Driver (2) | rdbss | system32\DRIVERS\mrxsmb.sys |
| `mrxsmb20` | Implements the SMB 2.0 protocol, which provides connectivity to network resources on Windows Vista and later servers | File System Driver (2) | mrxsmb | system32\DRIVERS\mrxsmb20.sys |
| `P9Rdr` | Plan 9 Redirector Driver | Kernel Driver (1) | RDBSS | System32\drivers\p9rdr.sys |
| `P9RdrService` | Enables trigger-starting plan9 file servers. | Win32 Share Process, User Service (96) | P9Rdr, RPCSS | C:\Windows\system32\svchost.exe -k P9RdrService -p |
| `rdbss` | Provides the framework for network mini-redirectors | File System Driver (2) | Mup | system32\DRIVERS\rdbss.sys |
| `WebClient` | Enables Windows-based programs to create, access, and modify Internet-based files. If this service is stopped, these functions will not be available. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | MRxDAV | C:\Windows\system32\svchost.exe -k LocalService -p |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow printer sharing with Windows Sandbox](https://noverse.dev/policies?p=WindowsSandbox*AllowPrinterRedirection) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Sandbox` | `AllowPrinterRedirection` |


# Disable Remote Desktop

Disables remote desktop, remote assistance, RPC traffic, and device redirection. See [remote desktop FAQs](https://learn.microsoft.com/en-us/windows-server/remote/remote-desktop-services/remotepc/remote-pc-connections-faq) for more information & [Terminal-Server.txt](https://github.com/nohuto/regkit/blob/main/assets/records/Terminal-Server.txt) for a list of read values on boot (`\Registry\Machine\SYSTEM\ControlSet001\Control\Terminal Server\*` key).

## Services/Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SessionEnv` | Remote Desktop Configuration service (RDCS) is responsible for all Remote Desktop Services and Remote Desktop related configuration and session maintenance activities that require SYSTEM context. These include per-session temporary folders, RD themes, and RD certificates. | Win32 Share Process (32) | RPCSS, LanmanWorkstation | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `TermService` | Allows users to connect interactively to a remote computer. Remote Desktop and Remote Desktop Session Host Server depend on this service. To prevent remote use of this computer, clear the checkboxes on the Remote tab of the System properties control panel item. | Win32 Share Process (32) | RPCSS | C:\Windows\System32\svchost.exe -k NetworkService |
| `UmRdpService` | Allows the redirection of Printers/Drives/Ports for RDP connections | Win32 Share Process (32) | TermService, RDPDR | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `rdpbus` | Remote Desktop Device Redirector Bus Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rdpbus.sys |
| `RDPDR` | Remote Desktop Device Redirector Driver | Kernel Driver (1) | RDBSS | System32\drivers\rdpdr.sys |
| `terminpt` | Microsoft Remote Desktop Input Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\terminpt.sys |
| `TsUsbFlt` | Remote Desktop USB Hub Class Filter Driver | Kernel Driver (1) | - | system32\drivers\tsusbflt.sys |
| `TsUsbGD` | Remote Desktop Generic USB Device | Kernel Driver (1) | - | \SystemRoot\System32\drivers\TsUsbGD.sys |
| `tsusbhub` | Remote Desktop USB Hub | Kernel Driver (1) | - | \SystemRoot\System32\drivers\tsusbhub.sys |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure Solicited Remote Assistance](https://noverse.dev/policies?p=RemoteAssistance*RA_Solicit) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `fAllowToGetHelp`<br>`fAllowFullControl` |
| [Configure Offer Remote Assistance](https://noverse.dev/policies?p=RemoteAssistance*RA_Unsolicit) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `fAllowUnsolicited`<br>`fAllowUnsolicitedFullControl` |
| [Turn on session logging](https://noverse.dev/policies?p=RemoteAssistance*RA_Logging) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `LoggingEnabled` |
| [Allow only Windows Vista or later connections](https://noverse.dev/policies?p=RemoteAssistance*RA_EncryptedTicketOnly) | `HKLM\Software\policies\Microsoft\Windows NT\Terminal Services` | `CreateEncryptedOnlyTickets` |
| [Restrict Unauthenticated RPC clients](https://noverse.dev/policies?p=RPC*RpcRestrictRemoteClients) | `HKLM\Software\Policies\Microsoft\Windows NT\Rpc` | `RestrictRemoteClients` |
| [Don't allow this PC to be projected to](https://noverse.dev/policies?p=WirelessDisplay*AllowProjectionToPC) | `HKLM\Software\Policies\Microsoft\Windows\Connect` | `AllowProjectionToPC` |
| [Require pin for pairing](https://noverse.dev/policies?p=WirelessDisplay*RequirePinForPairing) | `HKLM\Software\Policies\Microsoft\Windows\Connect` | `RequirePinForPairing` |


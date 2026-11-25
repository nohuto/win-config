# Disable Network Discovery

LLTDIO and Responder are network protocol drivers used for Link Layer Topology Discovery and network diagnostics. LLTDIO discovers network topology and supports QoS functions, while Responder allows the device to be identified and take part in network health assessments.

The [Link Layer Discovery Protocol (LLDP)](https://en.wikipedia.org/wiki/Link_Layer_Discovery_Protocol) is a vendor neutral link layer protocol used by network devices for advertising their identity, capabilities, and neighbors on a local area network based on IEEE 802 technology, principally wired Ethernet. LLDP performs functions similar to several proprietary protocols, such as CDP, FDP, NDP and LLTD.

### NetFirewallRule Capture

Disable network discovery (includes LLTDIO, Rspndr, LLTD), the group name `@FirewallAPI.dll,-32752` works on every display language:
```powershell
Get-NetFirewallRule -Group '@FirewallAPI.dll,-32752' | Disable-NetFirewallRule
```
Get the current states with:
```powershell
Get-NetFirewallRule -Group '@FirewallAPI.dll,-32752' | Select-Object Name, Enabled, Profile
```

```powershell
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\EnableLLTDIO	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\AllowLLTDIOOnDomain	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\AllowLLTDIOOnPublicNet	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\ProhibitLLTDIOOnPrivateNet	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\EnableRspndr	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\AllowRspndrOnDomain	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\AllowRspndrOnPublicNet	Type: REG_DWORD, Length: 4, Data: 0
svchost.exe	RegSetValue	HKLM\SOFTWARE\Policies\Microsoft\Windows\LLTD\ProhibitRspndrOnPrivateNet	Type: REG_DWORD, Length: 4, Data: 0
```

## Default Entries

Defaults on W11 LTSC IoT Enterprise:
```
Name                               Enabled        Profile
----                               -------        -------
NETDIS-UPnPHost-Out-TCP              False         Public
NETDIS-SSDPSrv-Out-UDP-Active         True        Private
NETDIS-WSDEVNT-Out-TCP-Active         True        Private
NETDIS-NB_Name-Out-UDP               False         Public
NETDIS-NB_Datagram-Out-UDP           False         Public
NETDIS-LLMNR-In-UDP                  False Domain, Public
NETDIS-DAS-In-UDP-Active              True        Private
NETDIS-SSDPSrv-In-UDP-Teredo          True         Public
NETDIS-UPnP-Out-TCP                  False Domain, Public
NETDIS-FDPHOST-In-UDP-Active          True        Private
NETDIS-WSDEVNT-In-TCP-Active          True        Private
NETDIS-UPnPHost-Out-TCP-Active        True        Private
NETDIS-WSDEVNTS-In-TCP-Active         True        Private
NETDIS-UPnPHost-In-TCP-Active         True        Private
NETDIS-NB_Name-In-UDP                False         Public
NETDIS-NB_Datagram-In-UDP-NoScope    False         Domain
NETDIS-FDRESPUB-WSD-In-UDP-Active     True        Private
NETDIS-WSDEVNTS-Out-TCP              False         Public
NETDIS-UPnPHost-Out-TCP-NoScope      False         Domain
NETDIS-WSDEVNT-In-TCP-NoScope        False         Domain
NETDIS-WSDEVNT-Out-TCP-NoScope       False         Domain
NETDIS-FDRESPUB-WSD-Out-UDP-Active    True        Private
NETDIS-LLMNR-Out-UDP                 False Domain, Public
NETDIS-WSDEVNTS-In-TCP-NoScope       False         Domain
NETDIS-SSDPSrv-In-UDP                False Domain, Public
NETDIS-DAS-In-UDP                    False Domain, Public
NETDIS-NB_Name-In-UDP-Active          True        Private
NETDIS-NB_Datagram-Out-UDP-Active     True        Private
NETDIS-NB_Datagram-In-UDP            False         Public
NETDIS-UPnPHost-In-TCP               False         Public
NETDIS-NB_Name-In-UDP-NoScope        False         Domain
NETDIS-WSDEVNTS-Out-TCP-NoScope      False         Domain
NETDIS-LLMNR-Out-UDP-Active           True        Private
NETDIS-UPnPHost-In-TCP-Teredo         True         Public
NETDIS-FDRESPUB-WSD-Out-UDP          False Domain, Public
NETDIS-SSDPSrv-In-UDP-Active          True        Private
NETDIS-LLMNR-In-UDP-Active            True        Private
NETDIS-WSDEVNT-Out-TCP               False         Public
NETDIS-WSDEVNTS-In-TCP               False         Public
NETDIS-NB_Datagram-In-UDP-Active      True        Private
NETDIS-SSDPSrv-Out-UDP               False Domain, Public
NETDIS-NB_Datagram-Out-UDP-NoScope   False         Domain
NETDIS-FDPHOST-Out-UDP               False Domain, Public
NETDIS-WSDEVNT-In-TCP                False         Public
NETDIS-UPnPHost-In-TCP-NoScope       False         Domain
NETDIS-WSDEVNTS-Out-TCP-Active        True        Private
NETDIS-FDRESPUB-WSD-In-UDP           False Domain, Public
NETDIS-FDPHOST-Out-UDP-Active         True        Private
NETDIS-FDPHOST-In-UDP                False Domain, Public
NETDIS-UPnP-Out-TCP-Active            True        Private
NETDIS-NB_Name-Out-UDP-Active         True        Private
NETDIS-NB_Name-Out-UDP-NoScope       False         Domain
```

## Services/Drivers

| Name | Description |
| --- | --- |
| `fdPHost` | The FDPHOST service hosts the Function Discovery (FD) network discovery providers. These FD providers supply network discovery services for the Simple Services Discovery Protocol (SSDP) and Web Services - Discovery (WS-D) protocol. Stopping or disabling the FDPHOST service will disable network discovery for these protocols when using FD. When this service is unavailable, network services using FD and relying on these discovery protocols will be unable to find network devices or resources. |
| `FDResPub` | Publishes this computer and resources attached to this computer so they can be discovered over the network. If this service is stopped, network resources will no longer be published and they will not be discovered by other computers on the network. |
| `SSDPSRV` | Discovers networked devices and services that use the SSDP discovery protocol, such as UPnP devices. Also announces SSDP devices and services running on the local computer. If this service is stopped, SSDP-based devices will not be discovered. If this service is disabled, any services that explicitly depend on it will fail to start. |
| `upnphost` | Allows UPnP devices to be hosted on this computer. If this service is stopped, any hosted UPnP devices will stop functioning and no additional hosted devices can be added. If this service is disabled, any services that explicitly depend on it will fail to start. |
| `MsLldp` | Microsoft Link-Layer Discovery Protocol Driver |
| `rspndr` | Link-Layer Topology Discovery Responder |
| `lltdio` | Link-Layer Topology Discovery Mapper I/O Driver |
| `lltdsvc` | Creates a Network Map, consisting of PC and device topology (connectivity) information, and metadata describing each PC and device. If this service is disabled, the Network Map will not function properly. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn on Mapper I/O (LLTDIO) driver](https://noverse.dev/policies?p=LinkLayerTopologyDiscovery*LLTD_EnableLLTDIO) | `HKLM\Software\Policies\Microsoft\Windows\LLTD` | `EnableLLTDIO`<br>`AllowLLTDIOOnDomain`<br>`AllowLLTDIOOnPublicNet`<br>`ProhibitLLTDIOOnPrivateNet` |
| [Turn on Responder (RSPNDR) driver](https://noverse.dev/policies?p=LinkLayerTopologyDiscovery*LLTD_EnableRspndr) | `HKLM\Software\Policies\Microsoft\Windows\LLTD` | `EnableRspndr`<br>`AllowRspndrOnDomain`<br>`AllowRspndrOnPublicNet`<br>`ProhibitRspndrOnPrivateNet` |


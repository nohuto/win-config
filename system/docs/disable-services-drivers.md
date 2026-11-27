# Disable Services/Drivers

I personally recommend using only the main option. This includes disabling telemetry/tracking/diagnostics/location/certain drivers/services, etc. It is not necessary to disable more than this, as most other features won't start automatically anyway. You can use the suboptions if you want to disable services/drivers (e.g. *"Autoplay Service, Bluetooth Services, Camera Services, File/Printer Sharing Services, Printer Services, Store Services"*) for a **specific** reason (note that this may cause broken functionalities). Disabling/enabling features via other options (e.g WER, Windows Search, Clipboard) includes changing service/driver `Start` data/setting policies etc, instead of only changing services/drivers state, so again, rather leave the suboptions alone.

## Service/Driver Table

You can dump all kind of information (including information like type, required privileges, failure actions, triggers, thread/handle count, KM/UM time etc. which the normal `services.msc` or any other programs won't show) using my [dumpServicesDrivers.ps1](https://github.com/nohuto/win-config/blob/main/system/assets/scripts/dumpServicesDrivers.ps1) script (which I also used for creating the tables below, see [services.txt](https://github.com/nohuto/win-config/blob/main/system/assets/reference/services.txt)/[drivers.txt](https://github.com/nohuto/win-config/blob/main/system/assets/reference/drivers.txt)), I've commented out some fields by default, edit the file if you want to see them.

The suboptions probably overlap the documentation. If so, you can open the [page on my website](https://noverse.dev/docs/win-config/system/disable-services-drivers/) instead.

### Activity Moderation

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `bam` | Controls activity of background applications | Kernel Driver (1) | - | system32\drivers\bam.sys |

### Autoplay

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `ShellHWDetection` | *Disabling causes CmdPal to not start directly after boot for whatever reason.* -Provides notifications for AutoPlay hardware events. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Beep

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Beep` | Legacy PC speaker/tone driver. It provides simple beeps for apps that call the Windows Beep API. | Kernel Driver (1) | - | - |

### Biometrics

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WbioSrvc` | The Windows biometric service gives client applications the ability to capture, compare, manipulate, and store biometric data without gaining direct access to any biometric hardware or samples. The service is hosted in a privileged SVCHOST process. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k WbioSvcGroup |

### Bluetooth

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `BTAGService` | Service supporting the audio gateway role of the Bluetooth Handsfree Profile. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted |
| `BluetoothUserService_*` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service, User Service Instance (224) | - | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BluetoothUserService` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service (96) | bthserv, rpcss | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BthA2dp` | Microsoft Bluetooth A2dp driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthA2dp.sys |
| `BthAvctpSvc` | This is Audio Video Control Transport Protocol service | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BthEnum` | Bluetooth Enumerator Service | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthEnum.sys |
| `BthHFEnum` | Microsoft Bluetooth Hands-Free Profile driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthhfenum.sys |
| `BthLEEnum` | Bluetooth Low Energy Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.Legacy.LEEnumerator.sys |
| `BthMini` | Bluetooth Radio Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHMINI.sys |
| `BTHMODEM` | Bluetooth Modem Communications Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthmodem.sys |
| `BTHPORT` | Bluetooth Port Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHport.sys |
| `bthserv` | The Bluetooth service supports discovery and association of remote Bluetooth devices. Stopping or disabling this service may cause already installed Bluetooth devices to fail to operate properly and prevent new devices from being discovered or associated. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BTHUSB` | Bluetooth Radio USB Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHUSB.sys |
| `DeviceAssociationBrokerSvc` | Enables apps to pair devices | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow -p |
| `DeviceAssociationService` | Enables pairing between the system and wired or wireless devices. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `Microsoft_Bluetooth_AvrcpTransport` | Microsoft Bluetooth Avrcp Transport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.AvrcpTransport.sys |
| `RFCOMM` | Bluetooth Device (RFCOMM Protocol TDI) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rfcomm.sys |

### Broadcasts

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `BcastDVRUserService` | This user service is used for Game Recordings and Live Broadcasts | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k BcastDVRUserService |
| `CaptureService_*` | Enables optional screen capture functionality for applications that call the Windows.Graphics.Capture API. | Win32 Share Process, User Service, User Service Instance (224) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `AJRouter` | Routes AllJoyn messages for the local AllJoyn clients. If this service is stopped the AllJoyn clients that do not have their own bundled routers will be unable to run. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `CaptureService` | Enables optional screen capture functionality for applications that call the Windows.Graphics.Capture API. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |
| `CDPSvc` | This service is used for Connected Devices Platform scenarios | Win32 Share Process (32) | ncbservice, RpcSS, Tcpip | C:\Windows\system32\svchost.exe -k LocalService -p |
| `CDPUserSvc` | This user service is used for Connected Devices Platform scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `DevicePickerUserSvc` | This user service is used for managing the Miracast, DLNA, and DIAL UI | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `DevicesFlowUserSvc` | Allows ConnectUX and PC Settings to Connect and Pair with WiFi displays and Bluetooth devices. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `NcbService` | Brokers connections that allow packaged Microsoft Store apps to receive notifications from the internet. | Win32 Share Process (32) | RpcSS, tcpip, BrokerInfrastructure | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `NcdAutoSetup` | Network Connected Devices Auto-Setup service monitors and installs qualified devices that connect to a qualified network. Stopping or disabling this service will prevent Windows from discovering and installing qualified network connected devices automatically. Users can still manually add network connected devices to a PC through the user interface. | Win32 Share Process (32) | netprofm | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `p2pimsvc` | Provides identity services for the Peer Name Resolution Protocol (PNRP) and Peer-to-Peer Grouping services. If disabled, the Peer Name Resolution Protocol (PNRP) and Peer-to-Peer Grouping services may not function, and some applications, such as HomeGroup and Remote Assistance, may not function correctly. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `p2psvc` | Enables multi-party communication using Peer-to-Peer Grouping. If disabled, some applications, such as HomeGroup, may not function. | Win32 Share Process (32) | p2pimsvc, PNRPSvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `PNRPAutoReg` | This service publishes a machine name using the Peer Name Resolution Protocol. Configuration is managed via the netsh context `p2p pnrp peer`. | Win32 Share Process (32) | pnrpsvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `PNRPsvc` | Enables serverless peer name resolution over the Internet using the Peer Name Resolution Protocol (PNRP). If disabled, some peer-to-peer and collaborative applications, such as Remote Assistance, may not function. | Win32 Share Process (32) | p2pimsvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |

### Camera

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `FrameServer` | Enables multiple clients to access video frames from camera devices. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k Camera |
| `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k CameraMonitor |
| `StiSvc` | Provides image acquisition services for scanners and cameras | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k imgsvc |

### CDROM

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cdrom` | CD-ROM Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\cdrom.sys |

### Clipboard

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cbdhsvc` | This user service is used for Clipboard scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k ClipboardSvcGroup -p |

### Cloud Filter

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CldFlt` | Cloud Files Mini Filter Driver | File System Driver (2) | FltMgr | system32\drivers\cldflt.sys |

### DHCP

> "*Dynamic Host Configuration Protocol (DHCP) is a standardized protocol that enables clients to be dynamically assigned with various configuration parameters, such as an IP address, subnet mask, default gateway, and other critical network configuration information. DHCP servers centrally manage such configuration data, and are configured by network administrators with settings that are appropriate for a given network environment. DHCP servers in turn communicate with DHCP clients through the use of DHCP messages.*"
>
> — Microsoft, [About Dynamic Host Configuration Protocol](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Dhcp` | Registers and updates IP addresses and DNS records for this computer. If this service is stopped, this computer will not receive dynamic IP addresses and DNS updates. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | NSI, Afd | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Diagnostics

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DusmSvc` | Network data usage, data limit, restrict background data, metered networks. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `DPS` | The Diagnostic Policy Service enables problem detection, troubleshooting and resolution for Windows components. If this service is stopped, diagnostics will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `diagsvc` | Executes diagnostic actions for troubleshooting support | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k diagnostics |
| `WdiServiceHost` | The Diagnostic Service Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local Service context. If this service is stopped, any diagnostics that depend on it will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalService -p |
| `WdiSystemHost` | The Diagnostic System Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local System context. If this service is stopped, any diagnostics that depend on it will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `TroubleshootingSvc` | Enables automatic mitigation for known problems by applying recommended troubleshooting. If stopped, your device will not get recommended troubleshooting for problems on your device. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Domain/RPC

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Netlogon` | Maintains a secure channel between this computer and the domain controller for authenticating users and services. If this service is stopped, the computer may not authenticate users and services and the domain controller cannot register DNS records. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | LanmanWorkstation | C:\Windows\system32\lsass.exe |
| `MsRPC` | MsRPC | Kernel Driver (1) | - | - |
| `RpcLocator` | In Windows 2003 and earlier versions of Windows, the Remote Procedure Call (RPC) Locator service manages the RPC name service database. In Windows Vista and later versions of Windows, this service does not provide any functionality and is present for application compatibility. | Win32 Own Process (16) | - | C:\Windows\system32\locator.exe |

### Edge

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MicrosoftEdgeElevationService` | Provides elevated privileges for Microsoft Edge. | - | - | - |
| `edgeupdate` | Keeps your Microsoft software up to date. If this service is disabled or stopped, your Microsoft software will not be kept up to date, meaning security vulnerabilities that may arise cannot be fixed and features may not work. This service uninstalls itself when there is no Microsoft software using it. | - | - | - |
| `edgeupdatem` | Keeps your Microsoft software up to date. If this service is disabled or stopped, your Microsoft software will not be kept up to date, meaning security vulnerabilities that may arise cannot be fixed and features may not work. This service uninstalls itself when there is no Microsoft software using it. | - | - | - |

### File/Printer Sharing

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

### GameInput

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `GameInputSvc` | Enables keyboards, mice, gamepads, and other input devices to be used with the GameInput API. | Win32 Own Process (16) | - | C:\Windows\System32\GameInputSvc.exe |

### HyperV

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `bttflt` | Microsoft Hyper-V VHDPMEM BTT Filter | Kernel Driver (1) | - | System32\drivers\bttflt.sys |
| `gencounter` | Microsoft Hyper-V Generation Counter | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgencounter.sys |
| `hvcrash` | Hyper-V Crashdump | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvcrash.sys |
| `HvHost` | Provides an interface for the Hyper-V hypervisor to provide per-partition performance counters to the host operating system. | Win32 Share Process (32) | hvservice | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `hvservice` | Microsoft Hypervisor Service Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvservice.sys |
| `hyperkbd` | Microsoft VMBus Synthetic Keyboard Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hyperkbd.sys |
| `HyperVideo` | Microsoft VMBus Video Device Miniport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\HyperVideo.sys |
| `storflt` | Microsoft Hyper-V Storage Accelerator | Kernel Driver (1) | - | System32\drivers\vmstorfl.sys |
| `Vid` | Microsoft Hyper-V Virtualization Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Vid.sys |
| `vmbus` | Virtual Machine Bus | Kernel Driver (1) | - | System32\drivers\vmbus.sys |
| `vmgid` | Microsoft Hyper-V Guest Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgid.sys |
| `vmicguestinterface` | Provides an interface for the Hyper-V host to interact with specific services running inside the virtual machine. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicheartbeat` | Monitors the state of this virtual machine by reporting a heartbeat at regular intervals. This service helps you identify running virtual machines that have stopped responding. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmickvpexchange` | Provides a mechanism to exchange data between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicrdv` | Provides a platform for communication between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmicshutdown` | Provides a mechanism to shut down the operating system of this virtual machine from the management interfaces on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmictimesync` | Synchronizes the system time of this virtual machine with the system time of the physical computer. | Win32 Share Process (32) | VmGid | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `vmicvmsession` | Provides a mechanism to manage virtual machine with PowerShell via VM session without a virtual network. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicvss` | Coordinates the communications that are required to use Volume Shadow Copy Service to back up applications and data on this virtual machine from the operating system on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vpci` | Microsoft Hyper-V Virtual PCI Bus | Kernel Driver (1) | - | System32\drivers\vpci.sys |

### IPv6

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Tcpip6` | @todo.dll,-100;Microsoft IPv6 Protocol Driver | Kernel Driver (1) | Tcpip | System32\drivers\tcpip.sys |
| `IpxlatCfgSvc` | Configures and enables translation from v4 to v6 and vice versa | Win32 Share Process (32) | nsi | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |

### IP Helper

> "*Internet Protocol Helper (IP Helper) assists network administration of the local computer by enabling applications to retrieve information about the network configuration of the local computer, and to modify that configuration. IP Helper also provides notification mechanisms to ensure that an application is notified when certain aspects of the local computer network configuration change.*"
>
> — Microsoft, [About IP Helper](https://learn.microsoft.com/en-us/windows/win32/iphlp/about-ip-helper)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `iphlpsvc` | Provides tunnel connectivity using IPv6 transition technologies (6to4, ISATAP, Port Proxy, and Teredo), and IP-HTTPS. If this service is stopped, the computer will not have the enhanced connectivity benefits that these technologies offer. | Win32 Share Process (32) | RpcSS, tcpip, nsi, WinHttpAutoProxySvc | C:\Windows\System32\svchost.exe -k NetSvcs -p |

### Kernel Debug Network

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `kdnic` | Microsoft Kernel Debugger Network Miniport | Kernel Driver (1) | - | \SystemRoot\System32\drivers\kdnic.sys |

### Location

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `lfsvc` | This service monitors the current location of the system and manages geofences (a geographical location with associated events). If you turn off this service, applications will be unable to use or receive notifications for geolocation or geofences. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Maps Manager

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MapsBroker` | Windows service for application access to downloaded maps. This service is started on-demand by application accessing downloaded maps. Disabling this service will prevent apps from accessing maps. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k NetworkService -p |

### Network Discovery

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `fdPHost` | The FDPHOST service hosts the Function Discovery (FD) network discovery providers. These FD providers supply network discovery services for the Simple Services Discovery Protocol (SSDP) and Web Services Discovery (WS-D) protocol. Stopping or disabling the FDPHOST service will disable network discovery for these protocols when using FD. When this service is unavailable, network services using FD and relying on these discovery protocols will be unable to find network devices or resources. | Win32 Share Process (32) | RpcSs, http | C:\Windows\system32\svchost.exe -k LocalService -p |
| `FDResPub` | Publishes this computer and resources attached to this computer so they can be discovered over the network. If this service is stopped, network resources will no longer be published and they will not be discovered by other computers on the network. | Win32 Share Process (32) | RpcSs, http, fdphost | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SSDPSRV` | Discovers networked devices and services that use the SSDP discovery protocol, such as UPnP devices. Also announces SSDP devices and services running on the local computer. If this service is stopped, SSDP-based devices will not be discovered. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | HTTP, NSI | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `upnphost` | Allows UPnP devices to be hosted on this computer. If this service is stopped, any hosted UPnP devices will stop functioning and no additional hosted devices can be added. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SSDPSRV, HTTP | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `MsLldp` | Microsoft Link-Layer Discovery Protocol Driver | Kernel Driver (1) | - | system32\drivers\mslldp.sys |
| `rspndr` | Link-Layer Topology Discovery Responder | Kernel Driver (1) | - | system32\drivers\rspndr.sys |
| `lltdio` | Link-Layer Topology Discovery Mapper I/O Driver | Kernel Driver (1) | - | system32\drivers\lltdio.sys |
| `lltdsvc` | Creates a Network Map, consisting of PC and device topology (connectivity) information, and metadata describing each PC and device. If this service is disabled, the Network Map will not function properly. | Win32 Share Process (32) | rpcss, lltdio | C:\Windows\System32\svchost.exe -k LocalService -p |

### Office

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `ClickToRunSvc` | - | - | - | - |

### Telephony

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `PhoneSvc` | Manages the telephony state on the device | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |
| `TapiSrv` | Provides Telephony API (TAPI) support for programs that control telephony devices on the local computer and, through the LAN, on servers that are also running the service. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k NetworkService -p |

### Radio Management

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RmSvc` | Radio Management and Airplane Mode Service. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted |

### Parental Control

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WpcMonSvc` | Enforces parental controls for child accounts in Windows. If this service is stopped or disabled, parental controls may not be enforced. | Win32 Own Process (16) | - | C:\Windows\system32\svchost.exe -k LocalService |

### Printer

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `McpManagementService` | Universal Print Management Service | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k McpManagementServiceGroup |
| `PrintDeviceConfigurationService` | The Print Device Configuration Service manages the installation of IPP and UP printers. If this service is stopped, any printer installations that are in-progress may be canceled. | - | - | - |
| `PrintNotify` | This service opens custom printer dialog boxes and handles notifications from a remote print server or a printer. If you turn off this service, you wont be able to see printer extensions or notifications. | Win32 Share Process, Interactive (288) | RpcSs | C:\Windows\system32\svchost.exe -k print |
| `PrintScanBrokerService` | Provides support for secure privileged operations needed by low priv spooler. | - | - | - |
| `PrintWorkflowUserSvc` | Provides support for Print Workflow applications. If you turn off this service, you may not be able to print successfully. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k PrintWorkflow |
| `Spooler` | This service spools print jobs and handles interaction with the printer. If you turn off this service, you won't be able to print or see your printers. | Win32 Own Process, Interactive (272) | RPCSS, http | C:\Windows\System32\spoolsv.exe |
| `usbprint` | Microsoft USB PRINTER Class | Kernel Driver (1) | - | \SystemRoot\System32\drivers\usbprint.sys |

### Recovery / Backup

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CloudBackupRestoreSvc` | Monitors the system for changes in application and setting states and performs cloud backup and restore operations when required. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `SDRSVC` | Provides Windows Backup and Restore capabilities. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\svchost.exe -k SDRSVC |
| `swprv` | Manages software-based volume shadow copies taken by the Volume Shadow Copy service. If this service is stopped, software-based volume shadow copies cannot be managed. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS | C:\Windows\System32\svchost.exe -k swprv |
| `VSS` | Manages and implements Volume Shadow Copies used for backup and other purposes. If this service is stopped, shadow copies will be unavailable for backup and the backup may fail. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\vssvc.exe |
| `wbengine` | The WBENGINE service is used by Windows Backup to perform backup and recovery operations. If this service is stopped by a user, it may cause the currently running backup or recovery operation to fail. Disabling this service may disable backup and recovery operations using Windows Backup on this computer. | Win32 Own Process (16) | - | "C:\Windows\system32\wbengine.exe" |

### Remote Desktop

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

### Sensor

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SensorDataService` | Delivers data from a variety of sensors | Win32 Own Process (16) | - | C:\Windows\System32\SensorDataService.exe |
| `SensrSvc` | Monitors various sensors in order to expose data and adapt to system and user state. If this service is stopped or disabled, the display brightness will not adapt to lighting conditions. Stopping this service may affect other system functionality and features as well. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SensorService` | A service for sensors that manages different sensors' functionality. Manages Simple Device Orientation (SDO) and History for sensors. Loads the SDO sensor that reports device orientation changes. If this service is stopped or disabled, the SDO sensor will not be loaded and so auto-rotation will not occur. History collection from Sensors will also be stopped. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `perceptionsimulation` | Enables spatial perception simulation, virtual camera management and spatial input simulation. | Win32 Own Process (16) | rpcss | C:\Windows\system32\PerceptionSimulation\PerceptionSimulationService.exe |
| `spectrum` | Enables spatial perception, spatial input, and holographic rendering. | Win32 Own Process (16) | rpcss | C:\Windows\system32\spectrum.exe |
| `VacSvc` | Hosts spatial analysis for Mixed Reality audio simulation. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Sign-In Assistant

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wlidsvc` | Enables user sign-in through Microsoft account identity services. If this service is stopped, users will not be able to logon to the computer with their Microsoft account. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `NaturalAuthentication` | Signal aggregator service, that evaluates signals based on time, network, geolocation, bluetooth and cdf factors. Supported features are Device Unlock, Dynamic Lock and Dynamo MDM policies | Win32 Share Process (32) | RpcSs, ProfSvc, Schedule | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `NgcCtnrSvc` | Manages local user identity keys used to authenticate user to identity providers as well as TPM virtual smart cards. If this service is disabled, local user identity keys and TPM virtual smart cards will not be accessible. It is recommended that you do not reconfigure this service. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NgcSvc` | Provides process isolation for cryptographic keys used to authenticate to a user's associated identity providers. If this service is disabled, all uses and management of these keys will not be available, which includes machine logon and single-sign on for apps and websites. This service starts and stops automatically. It is recommended that you do not reconfigure this service. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Smart Card

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SCardSvr` | Manages access to smart cards read by this computer. If this service is stopped, this computer will be unable to read smart cards. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation |
| `ScDeviceEnum` | Creates software device nodes for all smart card readers accessible to a given session. If this service is disabled, WinRT APIs will not be able to enumerate smart card readers. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted |
| `SCPolicySvc` | Allows the system to be configured to lock the user desktop upon smart card removal. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs |
| `scfilter` | Smart card reader filter driver enabling smart card PnP. | Kernel Driver (1) | - | System32\DRIVERS\scfilter.sys |

### SysMain

Note that disabling this service will cause memory management features like memory compression/combining to not start anymore, see '[Memory Compression](https://noverse.dev/docs/win-config/system/memory-compression/)' & '[Page Combining](https://noverse.dev/docs/win-config/system/page-combining/)'.

- Service = `C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p`
- DLL = `C:\Windows\System32\sysmain.dll`

The `EnableSuperfetch` value has no effect whenever this service is disabled, `EnablePrefetcher` seems to may still be used at some point in the kernel.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SysMain` | SysMain (Superfetch) records app usage patterns, builds prefetch metadata (layout.ini), and warms the cache by preloading files/pages to cut boot and app startup latency, it also handles prefetcher behavior via EnablePrefetcher settings. ([Windows Internals, E7-P1](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)) | Win32 Share Process (32) | rpcss, fileinfo | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Microsoft Store

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `AppXSvc` | *Disabling breaks CmdPal and other store applications.* - Provides infrastructure support for deploying Store applications. This service is started on demand and if disabled Store applications will not be deployed to the system, and may not function properly. | Win32 Share Process (32) | rpcss, staterepository | C:\Windows\system32\svchost.exe -k wsappx -p |
| `camsvc` | Provides facilities for managing UWP apps access to app capabilities as well as checking an app's access to specific app capabilities | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k osprivacy -p |
| `ClipSVC` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled applications bought using the Microsoft Store will not behave correctly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k wsappx -p |
| `InstallService` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then installations will not function properly. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `LicenseManager` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then content acquired through the Microsoft Store will not function properly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalService -p |
| `PushToInstall` | Provides infrastructure support for the Microsoft Store. This service is started automatically and if disabled then remote installations will not function properly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k netsvcs -p |

### TCP/IP NetBIOS Helper

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `lmhosts` | Provides support for the NetBIOS over TCP/IP (NetBT) service and NetBIOS name resolution for clients on the network, therefore enabling users to share files, print, and log on to the network. If this service is stopped, these functions might be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | Afd | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Telemetry

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DiagTrack` | The Connected User Experiences and Telemetry service enables features that support in-application and connected user experiences. Additionally, this service manages the event driven collection and transmission of diagnostic and usage information (used to improve the experience and quality of the Windows Platform) when the diagnostics and usage privacy option settings are enabled under Feedback and Diagnostics. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k utcsvc -p |
| `dmwappushservice` | Routes Wireless Application Protocol (WAP) Push messages received by the device and synchronizes Device Management sessions | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `Ndu` | This service provides network data usage monitoring functionality, disabling breaks e.g. the Send/Reveice graphcs in task manager, use System Informer anyways which will continue to show the graph | Kernel Driver (1) | tcpip | system32\drivers\Ndu.sys |
| `InventorySvc` | This service performs background system inventory, compatibility appraisal, and maintenance used by numerous system components. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k InvSvcGroup -p |
| `PcaSvc` | This service provides support for the Program Compatibility Assistant (PCA). PCA monitors programs installed and run by the user and detects known compatibility problems. If this service is stopped, PCA will not function properly. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `wuqisvc` | A Microsoft service producing summary facts and insights related to usage and quality of experience. Facts are used to automate on-device self-healing and other optional workflows, such as Personalized offers. | - | - | - |

### Themes

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Themes` | Provides user experience theme management. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Time

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `autotimesvc` | This service sets time based on NITZ messages from a Mobile Network | Win32 Own Process (16) | rpcss | C:\Windows\system32\svchost.exe -k autoTimeSvc |
| `tzautoupdate` | Automatically sets the system time zone. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |

### Trusted Runtime

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WindowsTrustedRT` | Windows Trusted Runtime Interface Driver | Kernel Driver (1) | - | system32\drivers\WindowsTrustedRT.sys |
| `WindowsTrustedRTProxy` | Windows Trusted Runtime Service Proxy Driver | Kernel Driver (1) | - | System32\drivers\WindowsTrustedRTProxy.sys |
| `PEAUTH` | Protected Environment Authentication and Authorization Export Driver | Kernel Driver (1) | - | system32\drivers\peauth.sys |

### UAC

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `luafv` | Virtualizes file write failures to per-user locations. | File System Driver (2) | FltMgr | \SystemRoot\system32\drivers\luafv.sys |

### User Data & Sync Platform

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `UnistoreSvc` | Handles storage of structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. | Win32 Share Process, User Service (96) | - | C:\Windows\System32\svchost.exe -k UnistackSvcGroup |
| `UserDataSvc` | Provides apps access to structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. | Win32 Share Process, User Service (96) | UnistoreSvc | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `ConsentUxUserSvc` | Allows the system to request user consent to allow apps to access sensitive resources and information such as the device's location | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `MessagingService` | Service supporting text messaging and related functionality. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `PimIndexMaintenanceSvc` | Indexes contact data for fast contact searching. If you stop or disable this service, contacts might be missing from your search results. | Win32 Share Process, User Service (96) | UnistoreSvc | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |

### Virtual Bus

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CompositeBus` | Multi-Transport Composite Bus Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\compositebus.inf_amd64_2e50c98177d80a40\CompositeBus.sys |
| `umbus` | User-Mode Bus Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\umbus.inf_amd64_3702527f0d5a77cf\umbus.sys |
| `vdrvroot` | Virtual Drive Root Enumerator | Kernel Driver (1) | - | System32\drivers\vdrvroot.sys |
| `NdisVirtualBus` | Microsoft Virtual Network Adapter Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\drivers\NdisVirtualBus.sys |

### WER

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WerSvc` | Allows errors to be reported when programs stop working or responding and allows existing solutions to be delivered. Also allows logs to be generated for diagnostic and repair services. If this service is stopped, error reporting might not work correctly and results of diagnostic services and repairs might not be displayed. | Win32 Own Process (16) | - | C:\Windows\System32\svchost.exe -k WerSvcGroup |
| `wercplsupport` | This service provides support for viewing, sending and deletion of system-level problem reports for the Problem Reports control panel. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Wi-Fi

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WlanSvc` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. | Win32 Own Process (16) | nativewifip, RpcSs, Ndisuio, wcmsvc | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vwififlt` | Virtual WiFi Filter Driver | Kernel Driver (1) | - | System32\drivers\vwififlt.sys |
| `wcncsvc` | WCNCSVC hosts the Windows Connect Now Configuration which is Microsoft's Implementation of Wireless Protected Setup (WPS) protocol. This is used to configure Wireless LAN settings for an Access Point (AP) or a Wireless Device. The service is started programmatically as needed. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `WFDSConMgrSvc` | Manages connections to wireless services, including wireless display and docking. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NativeWifiP` | NativeWiFi Filter | Kernel Driver (1) | - | system32\DRIVERS\nwifi.sys |
| `Wificx` | Wifi Network Adapter Class Extension | Kernel Driver (1) | NetAdapterCx | system32\drivers\WifiCx.sys |

### Windows Defender

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WinDefend` | Helps protect users from malware and other potentially unwanted software | Win32 Own Process (16) | RpcSs | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\MsMpEng.exe" |
| `MsSecCore` | Microsoft Security Core Boot Driver | Kernel Driver (1) | - | system32\drivers\msseccore.sys |
| `wscsvc` | The WSCSVC (Windows Security Center) service monitors and reports security health settings on the computer.  The health settings include firewall (on/off), antivirus (on/off/out of date), antispyware (on/off/out of date), Windows Update (automatically/manually download and install updates), User Account Control (on/off), and Internet settings (recommended/not recommended). The service provides COM APIs for independent software vendors to register and record the state of their products to the Security Center service.  The Security and Maintenance UI uses the service to provide systray alerts and a graphical view of the security health states in the Security and Maintenance control panel.  Network Access Protection (NAP) uses the service to report the security health states of clients to the NAP Network Policy Server to make network quarantine decisions.  The service also has a public API that allows external consumers to programmatically retrieve the aggregated security health state of the system. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `WdFilter` | Microsoft Defender Antivirus On-Access Malware Protection Mini-Filter Driver | File System Driver (2) | FltMgr | system32\drivers\wd\WdFilter.sys |
| `WdBoot` | Microsoft Defender Antivirus Boot Driver | Kernel Driver (1) | - | system32\drivers\wd\WdBoot.sys |
| `WdNisSvc` | Helps guard against intrusion attempts targeting known and newly discovered vulnerabilities in network protocols | Win32 Own Process (16) | WdNisDrv | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\NisSrv.exe" |
| `WdNisDrv` | Helps guard against intrusion attempts targeting known and newly discovered vulnerabilities in network protocols | Kernel Driver (1) | BFE | system32\drivers\wd\WdNisDrv.sys |
| `SecurityHealthService` | Windows Security Service handles unified device protection and health information | Win32 Own Process (16) | RpcSs | C:\Windows\system32\SecurityHealthService.exe |
| `Sense` | Windows Defender Advanced Threat Protection service helps protect against advanced threats by monitoring and reporting security events that happen on the computer. | Win32 Own Process (16) | - | "C:\Program Files\Windows Defender Advanced Threat Protection\MsSense.exe" |
| `MDCoreSvc` | Monitors the availability, health, and performance of various security components | Win32 Own Process (16) | - | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\MpDefenderCoreService.exe" |

### Windows Insider

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wisvc` | Provides infrastructure support for the Windows Insider Program. This service must remain enabled for the Windows Insider Program to work. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Windows Search

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WSearch` | Provides content indexing, property caching, and search results for files, e-mail, and other content. | Win32 Own Process (16) | RPCSS, BrokerInfrastructure | C:\Windows\system32\SearchIndexer.exe /Embedding |

### Windows Update

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WaaSMedicSvc` | Repairs damaged Windows Update components so that the computer can keep getting updates. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k wusvcs -p |
| `UsoSvc` | Manages Windows Updates. If stopped, your devices will not be able to download and install the latest updates. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `wuauserv` | Enables the detection, download, and installation of updates for Windows and other programs. If this service is disabled, users of this computer will not be able to use Windows Update or its automatic updating feature, and programs will not be able to use the Windows Update Agent (WUA) API. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Xbox

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `XboxGipSvc` | This service manages connected Xbox Accessories. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `xboxgip` | Xbox Game Input Protocol Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\xboxgip.sys |
| `XblAuthManager` | Provides authentication and authorization services for interacting with Xbox Live. If this service is stopped, some applications may not operate correctly. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `XblGameSave` | This service syncs save data for Xbox Live save enabled games. If this service is stopped, game save data will not upload to or download from Xbox Live. | Win32 Share Process (32) | UserManager, XblAuthManager | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `XboxNetApiSvc` | This service supports the Windows.Networking.XboxLive application programming interface. | Win32 Share Process (32) | BFE, mpssvc, IKEEXT, KeyIso | C:\Windows\system32\svchost.exe -k netsvcs -p |

### VBox

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `VBoxNetAdp` | VirtualBox NDIS 6.0 Host-Only Network Adapter Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxNetAdp6.sys |
| `VBoxNetLwf` | VirtualBox NDIS 6.0 Lightweight Filter Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxNetLwf.sys |
| `VBoxSup` | VirtualBox Support Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxSup.sys |
| `VBoxUSBMon` | VirtualBox USB Monitor Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxUSBMon.sys |
| `VBoxSDS` | Used as a COM server for VirtualBox API. VirtualBox Global Interface. | Win32 Own Process (16) | RPCSS | "C:\Program Files\Oracle\VirtualBox\VBoxSDS.exe" |

### VPN/RAS Services

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RemoteAccess` | Offers routing services to businesses in local area and wide area network environments. | Win32 Share Process (32) | RpcSS, Bfe, RasMan, Http | C:\Windows\System32\svchost.exe -k netsvcs |
| `wanarp` | Remote Access IP ARP Driver | Kernel Driver (1) | - | System32\DRIVERS\wanarp.sys |
| `wanarpv6` | Remote Access IPv6 ARP Driver | Kernel Driver (1) | - | System32\DRIVERS\wanarp.sys |
| `RasMan` | Manages dial-up and virtual private network (VPN) connections from this computer to the Internet or other remote networks. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SstpSvc, DnsCache | C:\Windows\System32\svchost.exe -k netsvcs |
| `RasAuto` | Creates a connection to a remote network whenever a program references a remote DNS or NetBIOS name or address. | Win32 Share Process (32) | RasAcd | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `PptpMiniport` | WAN Miniport (PPTP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\raspptp.sys |
| `RasAgileVpn` | WAN Miniport (IKEv2) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\AgileVpn.sys |
| `Rasl2tp` | WAN Miniport (L2TP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rasl2tp.sys |
| `RasSstp` | WAN Miniport (SSTP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rassstp.sys |
| `SstpSvc` | Provides support for the Secure Socket Tunneling Protocol (SSTP) to connect to remote computers using VPN. If this service is disabled, users will not be able to use SSTP to access remote servers. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `RasAcd` | Remote Access Auto Connection Driver | Kernel Driver (1) | - | System32\DRIVERS\rasacd.sys |

### Media Sharing / Portable Devices

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WMPNetworkSvc` | Shares Windows Media Player libraries to other networked players and media devices using Universal Plug and Play | - | - | - |
| `WPDBusEnum` | Enforces group policy for removable mass-storage devices. Enables applications such as Windows Media Player and Image Import Wizard to transfer and synchronize content using removable mass-storage devices. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted |

### BranchCache

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `PeerDistSvc` | This service caches network content from peers on the local subnet. | Win32 Share Process (32) | http | C:\Windows\System32\svchost.exe -k PeerDist |

### QoS/AV Streaming (qWave)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `QWAVE` | Quality Windows Audio Video Experience (qWave) is a networking platform for Audio Video (AV) streaming applications on IP home networks. qWave enhances AV streaming performance and reliability by ensuring network quality-of-service (QoS) for AV applications. It provides mechanisms for admission control, run time monitoring and enforcement, application feedback, and traffic prioritization. | Win32 Share Process (32) | rpcss, psched, QWAVEdrv, LLTDIO | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `QWAVEdrv` | Quality Windows Audio/Video Experience component driver | Kernel Driver (1) | - | \SystemRoot\system32\drivers\qwavedrv.sys |

### NFC/Payments

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SEMgrSvc` | Manages payments and Near Field Communication (NFC) based secure elements. | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |

### Optimize Drives

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `defragsvc` | Helps the computer run more efficiently by optimizing files on storage drives. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\svchost.exe -k defragsvc |

### Mobile Hotspot / ICS Service

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `icssvc` | Provides the ability to share a cellular data connection with another device. | Win32 Share Process (32) | RpcSs, wcmsvc | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `ALG` | Provides support for 3rd party protocol plug-ins for Internet Connection Sharing | Win32 Own Process (16) | - | C:\Windows\System32\alg.exe |
| `SharedAccess` | Provides network address translation, addressing, name resolution and/or intrusion prevention services for a home or small office network. | Win32 Share Process (32) | BFE | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Network Capture Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NdisCap` | Microsoft NDIS Capture | Kernel Driver (1) | - | System32\drivers\ndiscap.sys |

### Container File System Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CimFS` | - | File System Driver (2) | - | \??\C:\Program Files (x86)\Windows Kits\10\Assessment and Deployment Kit\Deployment Tools\AMD64\DISM\cimfs.sys |
| `wcifs` | Provides a virtual filesystem view for processes running within Windows Containers | File System Driver (2) | FltMgr | \SystemRoot\system32\drivers\wcifs.sys |

### Consumer IR Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `circlass` | Consumer IR Class Driver for eHome | Kernel Driver (1) | - | \SystemRoot\System32\drivers\circlass.sys |

### iSCSI Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `msisadrv` | Disabling breaks laptop keyboards. | Kernel Driver (1) | - | System32\drivers\msisadrv.sys |

### NetBIOS Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NetBIOS` | NetBIOS Interface | File System Driver (2) | - | system32\drivers\netbios.sys |
| `NetBT` | This service implements NetBios over TCP/IP. | Kernel Driver (1) | Tdx, tcpip | System32\DRIVERS\netbt.sys |

### Epic Games

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `EpicGamesUpdater` | - | - | - | - |
| `EpicOnlineServices` | - | - | - | - |

### Logitech

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `LGHUBUpdaterService` | LGHUB Updater Service | Win32 Own Process (16) | - | "C:\Program Files\LGHUB\lghub_updater.exe" --run-as-service |
| `logi_joy_bus_enum` | Logitech G HUB Virtual Bus Enumerator Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\logi_joy_bus_enum.x64.sys |
| `logi_joy_vir_hid` | Logitech G HUB Virtual HID Device Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\logi_joy_vir_hid.x64.sys |
| `logi_lamparray_service` | Provides HID LampArray Lighting support to Logitech devices. | Win32 Own Process (16) | logi_lamparray | C:\Windows\System32\DriverStore\FileRepository\logi_lamparray_usb.inf_amd64_dc165490f32791ad\logi_lamparray_service.AMD64.exe |

### SteelSeries

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SteelSeries_Sonar_VAD` | SteelSeries Sonar Driver | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\steelseries-sonar-vad.inf_amd64_036e27f3054ae1bc\SteelSeries-Sonar-VAD.sys |
| `SteelSeriesGGUpdateServiceProxy` | Launches the SteelSeries Update Service. | Win32 Own Process (16) | - | "C:\Program Files\SteelSeries\GG\updateService\SteelSeriesGGUpdateServiceProxy.exe" |
| `ssdevfactory` | SteelSeries Device Factory Service | Kernel Driver (1) | - | \SystemRoot\System32\drivers\ssdevfactory.sys |

### NVIDIA Container

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NVDisplay.ContainerLocalSystem` | Container service for NVIDIA root features, required for NVCPL to work. | Win32 Own Process (16) | - | C:\Windows\System32\DriverStore\FileRepository\nv_dispi.inf_amd64_c8bc842500fab35b\Display.NvContainer\NVDisplay.Container.exe -arg <ExeDir>\arguments.txt |

### Everything

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Everything (1.5a)` | Provides NTFS indexing, ReFS indexing and USN Journal services to the Everything search client. | Win32 Own Process (16) | - | "C:\Program Files\Everything 1.5a\Everything.exe" -svc |
| `Everything` | ^ | - | - | - |

### App Deployment

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `AppMgmt` | Processes installation, removal, and enumeration requests for software deployed through Group Policy. If the service is disabled, users will be unable to install, remove, or enumerate software deployed through Group Policy. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `AxInstSV` | Provides User Account Control validation for the installation of ActiveX controls from the Internet and enables management of ActiveX control installation based on Group Policy settings. This service is started on demand and if disabled the installation of ActiveX controls will behave according to default browser settings. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k AxInstSVGroup |
| `BITS` | Transfers files in the background using idle network bandwidth. If the service is disabled, then any applications that depend on BITS, such as Windows Update or MSN Explorer, will be unable to automatically download programs and other information. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `EntAppSvc` | Enables enterprise application management. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k appmodel -p |

### Network Authentication

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `dot3svc` | The Wired AutoConfig (DOT3SVC) service is responsible for performing IEEE 802.1X authentication on Ethernet interfaces. If your current wired network deployment enforces 802.1X authentication, the DOT3SVC service should be configured to run for establishing Layer 2 connectivity and/or providing access to network resources. Wired networks that do not enforce 802.1X authentication are unaffected by the DOT3SVC service. | Win32 Share Process (32) | RpcSs, Ndisuio, Eaphost | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `EapHost` | The Extensible Authentication Protocol (EAP) service provides network authentication in such scenarios as 802.1x wired and wireless, VPN, and Network Access Protection (NAP). EAP also provides application programming interfaces (APIs) that are used by network access clients, including wireless and VPN clients, during the authentication process. If you disable this service, this computer is prevented from accessing networks that require EAP authentication. | Win32 Share Process (32) | RPCSS, KeyIso | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Network Profile & Connectivity UX

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NcaSvc` | Provides DirectAccess status notification for UI components | Win32 Share Process (32) | BFE, dnscache, NSI, iphlpsvc | C:\Windows\System32\svchost.exe -k NetSvcs -p |
| `NlaSvc` | Collects and stores configuration information for the network and notifies programs when this information is modified. If this service is stopped, configuration information might be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netprofm -p |
| `Wcmsvc` | Makes automatic connect and disconnect decisions based on the network connectivity options currently available to the PC and enables management of network connectivity based on Group Policy settings. | Win32 Own Process (16) | RpcSs, NSI | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Enterprise Transaction & Storage

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MSDTC` | Coordinates transactions that span multiple resource managers, such as databases, message queues, and file systems. If this service is stopped, these transactions will fail. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS, SamSS | C:\Windows\System32\msdtc.exe |
| `MSiSCSI` | Manages Internet SCSI (iSCSI) sessions from this computer to remote iSCSI target devices. If this service is stopped, this computer will not be able to login or access iSCSI targets. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `smphost` | Host service for the Microsoft Storage Spaces management provider. If this service is stopped or disabled, Storage Spaces cannot be managed. | Win32 Own Process (16) | RPCSS | C:\Windows\System32\svchost.exe -k smphost |

### Management / Encryption Broker

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SNMPTRAP` | Receives trap messages generated by local or remote Simple Network Management Protocol (SNMP) agents and forwards the messages to SNMP management programs running on this computer. If this service is stopped, SNMP-based programs on this computer will not receive SNMP trap messages. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | - | C:\Windows\System32\snmptrap.exe |
| `WEPHOSTSVC` | Windows Encryption Provider Host Service brokers encryption related functionalities from 3rd Party Encryption Providers to processes that need to evaluate and apply EAS policies. Stopping this will compromise EAS compliancy checks that have been established by the connected Mail Accounts | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k WepHostSvcGroup |

### Demo / Shared Device

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RetailDemo` | The Retail Demo service controls device activity while the device is in retail demo mode. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k rdxgroup |
| `shpamsvc` | Manages profiles and accounts on a SharedPC configured device | Win32 Share Process (32) | RpcSs, ProfSvc | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Graphics Compatibility

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WarpJITSvc` | Enables JIT compilation support in d3d10warp.dll for processes in which code generation is disabled. | Win32 Own Process (16) | - | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted |

### Mobile Broadband

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wlpasvc` | This service provides profile management for subscriber identity modules | Win32 Share Process (32) | WwanSvc, RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `WwanSvc` | This service manages mobile broadband (GSM & CDMA) data card/embedded module adapters and connections by auto-configuring the networks. It is strongly recommended that this service be kept running for best user experience of mobile broadband devices. | Win32 Share Process (32) | RpcSs, NdisUio | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Miscellaneous

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WalletService` | Hosts objects used by clients of the wallet | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k appmodel -p |
| `PenService` | Part of Windows Ink Services Platform Tablet Input Subsystem and is used to implement Microsoft Tablet PC functionality. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k PenService |
| `buttonconverter` | Service for Portable Device Control devices | Kernel Driver (1) | - | \SystemRoot\System32\drivers\buttonconverter.sys |
| `SmsRouter` | Routes messages based on rules to appropriate clients. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

## [Windows Internals](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/services1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services4.png?raw=true)


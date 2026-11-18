# Disable Hyper-V

> "*The Hyper-V hypervisor (also known as Windows hypervisor) is a type-1 (native or bare-metal) hypervisor: a mini operating system that runs directly on the host's hardware to manage a single root and one or more guest operating systems. Unlike type-2 (or hosted) hypervisors, which run on the base of a conventional OS like normal applications, the Windows hypervisor abstracts the root OS, which knows about the existence of the hypervisor and communicates with it to allow the execution of one or more guest virtual machines.*"
>
> — Windows Internals, [E7, P2: 'The Windows hypervisor'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

> "*Many third-party virtualization applications don't work together with Hyper-V. Affected applications include VMware Workstation and VirtualBox. These applications might not start virtual machines, or they may fall back to a slower, emulated mode. Many virtualization applications depend on hardware virtualization extensions that are available on most modern processors. It includes Intel VT-x and AMD-V. Only one software component can use this hardware at a time. The hardware cannot be shared between virtualization applications.*"
>
> — Microsoft, [Virtualization applications don't work together with Hyper-V](https://learn.microsoft.com/en-us/troubleshoot/windows-client/application-management/virtualization-apps-not-work-with-hyper-v)

## Service/Driver Table

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


# SMB

SMB uses a client-side remote file system driver (LANMan Redirector) and a server-side remote FSD (`Srv2.sys`). Client settings under `LanmanWorkstation` and server settings under `LanmanServer` govern how those components negotiate and handle SMB traffic.

## Suboptions

- [SMB Client](https://learn.microsoft.com/en-us/powershell/module/smbshare/set-smbclientconfiguration?view=windowsserver2025-ps) -> Outbound connections
- [SMB Server](https://learn.microsoft.com/en-us/powershell/module/smbshare/set-smbserverconfiguration?view=windowsserver2025-ps) -> Inbound connections

### Disable SMBv1

SMBv1 is [deprecated, insecure, and should stay disabled](https://techcommunity.microsoft.com/blog/filecab/stop-using-smb1/425858) unless you are dealing with legacy systems that cannot use SMB2 or newer.

See current states with:
```powershell
Get-SmbServerConfiguration | Select EnableSMB1Protocol
```

```powershell
Set-SmbServerConfiguration -EnableSMB1Protocol $false -Force
Disable-WindowsOptionalFeature -Online -FeatureName SMB1Protocol
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\SMB1	Type: REG_DWORD, Length: 4, Data: 0
```

### Disable SMBv2

Disables the SMBv2/SMBv3 part on the server side. Microsoft recommends using this only for troubleshooting because it also disables SMBv3 functionality (or if you don't use it).

See current states with:
```powershell
Get-SmbServerConfiguration | Select EnableSMB2Protocol
```

```powershell
Set-SmbServerConfiguration -EnableSMB2Protocol $false -Force
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\SMB2	Type: REG_DWORD, Length: 4, Data: 0
```

#### [Effects of Disabling](https://learn.microsoft.com/en-us/windows-server/storage/file-server/troubleshoot/detect-enable-and-disable-smbv1-v2-v3?tabs=client#disable-smbv2-or-smbv3-for-troubleshooting)

| Functionality | Disabled when SMBv3 is off | Disabled when SMBv2 is off |
| --- | --- | --- |
| Transparent failover | Yes | No |
| Scale-out file server access | Yes | No |
| SMB Multichannel | Yes | No |
| SMB Direct (RDMA) | Yes | No |
| Encryption (end-to-end) | Yes | No |
| Directory leasing | Yes | No |
| Performance optimization (small random I/O) | Yes | No |
| Request compounding | No | Yes |
| Larger reads and writes | No | Yes |
| Caching of folder and file properties | No | Yes |
| Durable handles | No | Yes |
| Improved message signing (HMAC SHA-256) | No  | Yes |
| Improved scalability for file sharing | No | Yes |
| Support for symbolic links | No | Yes |
| Client oplock leasing model | No | Yes |
| Large MTU / 10 GbE support | No | Yes |
| Improved energy efficiency (clients can sleep) | No | Yes |

### Enforce SMB Signing

> "*The `EnableSecuritySignature` registry setting for SMB2 and later clients and servers is ignored. Therefore, this setting does nothing unless you're using SMB1. SMB 2.02 and later signing is controlled solely by being required or not. This setting is used when either the server or client requires SMB signing. Signing doesn't occur only when both the server and client have signing set to `0`.*"
>
> — Microsoft, [SMB signing overview](https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-signing-overview#understanding-requiresecuritysignature-and-enablesecuritysignature)

In summary SMB is signed when:

- Both the SMB client and server have `RequireSecuritySignature` set to `1`.
- The SMB client has `RequireSecuritySignature` set to `1` and the server has `RequireSecuritySignature` set to `0`.
- The SMB server has `RequireSecuritySignature` set to `1` and the client has `RequireSecuritySignature` set to `0`.

Signing isn't used when:

- The SMB client and server have `RequireSecuritySignature` set to `0`.

```powershell
Set-SmbClientConfiguration -RequireSecuritySignature $true
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\RequireSecuritySignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbClientConfiguration -EnableSecuritySignature $true
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\enablesecuritysignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -RequireSecuritySignature $true
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\RequireSecuritySignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EnableSecuritySignature $true
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\enablesecuritysignature	Type: REG_DWORD, Length: 4, Data: 1
```

### Prefer AES-256 SMB Ciphers

Specifies the supported SMB encryption ciphers and their preference order, the suboption restricts both client and server to `AES_256_GCM`/`AES_256_CCM`, so the peer must support one of those ciphers.

`CipherSuiteOrder` only exists on W11.

```powershell
Set-SmbClientConfiguration -EncryptionCiphers "AES_256_GCM, AES_256_CCM"
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\CipherSuiteOrder	Type: REG_MULTI_SZ, Length: 52, Data: AES_256_GCM, AES_256_CCM, 

Set-SmbServerConfiguration -EncryptionCiphers "AES_256_GCM, AES_256_CCM"
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\CipherSuiteOrder	Type: REG_MULTI_SZ, Length: 52, Data: AES_256_GCM, AES_256_CCM, 
```

### Disable Admin Shares

> "*By default, Windows Server automatically creates special hidden administrative shares that administrators, programs, and services can use to manage the computer environment or network. These special shared resources aren't visible in Windows Explorer or in My Computer. However, you can view them by using the Shared Folders tool in Computer Management. Depending on the configuration of your computer, some or all of the following special shared resources may be listed in the Shares folder in Shared Folders:*
>
> - *`<DriveLetter>$`: It's a shared root partition or volume. Shared root partitions and volumes are displayed as the drive letter name appended with the dollar sign (`$`). For example, when drive letters C and D are shared, they're displayed as `C$` and `D$`.*
> - *`ADMIN$`: It's a resource that is used during remote administration of a computer.*
> - *`IPC$`: It's a resource that shares the named pipes that you must have for communication between programs. This resource cannot be deleted.*
> - *`NETLOGON`: It's a resource that is used on domain controllers.*
> - *`SYSVOL`: It's a resource that is used on domain controllers.*
> - *`PRINT$`: It's a resource that is used during the remote administration of printers.*
> - *`FAX$`: It's a shared folder on a server that is used by fax clients during fax transmission.*
>
> *`NETLOGON` and `SYSVOL` aren't hidden shares. Instead, they are special administrative shares.*"
>
> — Microsoft, [Remove administrative shares](https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/remove-administrative-shares)

Disable default sharing:
```powershell
Set-SmbServerConfiguration -AutoShareServer $false -AutoShareWorkstation $false -Force
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\AutoShareServer	Type: REG_DWORD, Length: 4, Data: 0
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\AutoShareWks	Type: REG_DWORD, Length: 4, Data: 0
```

### Force Encryption

It can add additional processing, so measure throughput on your hardware, since some reported slow read/write speeds.

```powershell
Set-SmbServerConfiguration -EncryptData $true
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\EncryptData	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -RejectUnencryptedAccess $true
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\RejectUnencryptedAccess	Type: REG_DWORD, Length: 4, Data: 1
```

### Enable SMB Over QUIC

> "*SMB over QUIC introduces an alternative to the TCP network transport, providing secure, reliable connectivity to edge file servers over untrusted networks like the Internet. QUIC is an IETF-standardized protocol with many benefits when compared with TCP:*
>
> - *All packets are always encrypted and handshake is authenticated with TLS 1.3*
> - *Parallel streams of reliable and unreliable application data*
> - *Exchanges application data in the first round trip (0-RTT)*
> - *Improved congestion control and loss recovery*
> - *Survives a change in the clients IP address or port*
>
> *SMB over QUIC offers an "SMB VPN" for telecommuters, mobile device users, and high security organizations. The server certificate creates a TLS 1.3-encrypted tunnel over the internet-friendly UDP port 443 instead of the legacy TCP port 445. All SMB traffic, including authentication and authorization within the tunnel is never exposed to the underlying network. SMB behaves normally within the QUIC tunnel, meaning the user experience doesn't change. SMB features like multichannel, signing, compression, continuous availability, directory leasing, and so on, work normally.*"
>
> — Microsoft, [SMB over QUIC](https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-over-quic?tabs=windows-admin-center%2Cpowershell2%2Cwindows-admin-center1)

```powershell
Set-SmbClientConfiguration -EnableSMBQUIC $true
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnableSMBQUIC	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EnableSMBQUIC $true
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\EnableSMBQUIC	Type: REG_DWORD, Length: 4, Data: 1
```

> https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-over-quic

### [SMB 3.1.1 Only](https://techcommunity.microsoft.com/blog/filecab/controlling-smb-dialects/860024)

By default it's `None`, which means that the client can use any supported version. SMB 3.1.1 is the most secure dialect of the protocol. The minimum is SMB 3.1.1 (`0x311` = 785), so devices that only speak SMB 3.0 or 3.0.2 can't connect either.

`None` = No min/max protocol version  
`SMB202` = SMB 2.0.2  
`SMB210` = SMB 2.1.0  
`SMB300` = SMB 3.0.0  
`SMB302` = SMB 3.0.2  
`SMB311` = SMB 3.1.1

```powershell
Set-SmbServerConfiguration -Smb2DialectMin SMB311 -Smb2DialectMax None
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\MaxSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 65536
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\MinSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 785

Set-SmbClientConfiguration -Smb2DialectMin SMB311 -Smb2DialectMax None
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\MaxSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 65536
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\MinSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 785
```

> https://learn.microsoft.com/en-us/windows-server/storage/file-server/manage-smb-dialects?tabs=powershell  
> https://techcommunity.microsoft.com/blog/filecab/controlling-smb-dialects/860024

### Disable Bandwidth Throttling

```powershell
Set-SmbClientConfiguration -EnableBandwidthThrottling $false
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableBandwidthThrottling	Type: REG_DWORD, Length: 4, Data: 1
```

### Enable Large MTU

MTU = maximum transmission unit.

```powershell
Set-SmbClientConfiguration -EnableLargeMtu $true
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableLargeMtu	Type: REG_DWORD, Length: 4, Data: 0
```

### Enable SMB Multichannel

> "*SMB Multichannel is part of the Server Message Block (SMB) 3.0 protocol, which increases network performance and the availability of file servers.*
>
> *SMB Multichannel enables file servers to use multiple network connections simultaneously. It facilitates aggregation of network bandwidth and network fault tolerance when multiple paths are available between the SMB 3.0 client and the SMB 3.0 server. This allows server applications to take full advantage of all available network bandwidth and makes them more resilient to network failures.*
>
> *SMB Multichannel provides the following capabilities:*
> - ***Increased throughput.** The file server can simultaneously transmit additional data by using multiple connections for high-speed network adapters or multiple network adapters.*
> - ***Network fault tolerance.** When clients simultaneously use multiple network connections, the clients can continue without interruption despite the loss of a network connection.*
> - ***Automatic configuration.** SMB Multichannel automatically discovers multiple available network paths and dynamically adds connections as necessary.*"
>
> — Microsoft, [Manage SMB Multichannel](https://learn.microsoft.com/en-us/windows-server/storage/storage-spaces/manage-smb-multichannel)

```powershell
Set-SmbClientConfiguration -EnableMultiChannel $true
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableMultiChannel	Type: REG_DWORD, Length: 4, Data: 0
```

### Disable Leasing

Disabling leasing [may help](https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/slow-smb-file-transfer#slow-open-of-office-documents), but it disables core features like read/write/handle caching that negatively impact many applications, which rely on it.

```powershell
Set-SmbServerConfiguration -EnableLeasing $false
HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\DisableLeasing	Type: REG_DWORD, Length: 4, Data: 1
```

### Disable SMB Direct (RDMA)

If you disable [SMB Direct](https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-direct?tabs=disable), RDMA backed SMB traffic is no longer available.

```powershell
Get-WindowsOptionalFeature -Online -FeatureName SMBDirect
Disable-WindowsOptionalFeature -Online -FeatureName SMBDirect
```

### Require NTLMv2 Session Security

> "*This security setting allows a client to require the negotiation of 128-bit encryption and/or NTLMv2 session security. These values are dependent on the LAN Manager Authentication Level security setting value. The options are:*
>
> *Require NTLMv2 session security: The connection will fail if NTLMv2 protocol is not negotiated.*  
> *Require 128-bit encryption: The connection will fail if strong encryption (128-bit) is not negotiated.*"
>
> — Microsoft, Local Security Policy explain text (`wsecedit.dll.mui`), [Network security: Minimum session security for NTLM SSP based (including secure RPC) clients](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/network-security-minimum-session-security-for-ntlm-ssp-based-including-secure-rpc-clients)

```c
// NTLMv2 Off - 128 Bit Encryption On (default)
HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 536870912

// NTLMv2 On - 128 Bit Encryption On
HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 537395200

// NTLMv2 Off - 128 Bit Encryption Off
HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 0
```

### Allow Plaintext Passwords

```c
// Enabled (security risk)
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnablePlainTextPassword	Type: REG_DWORD, Length: 4, Data: 1

// Disabled (default)
HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnablePlainTextPassword	Type: REG_DWORD, Length: 4, Data: 0
```


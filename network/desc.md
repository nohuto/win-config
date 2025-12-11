# Encrypted DNS

The option currently uses the encrypted `Mullvad` - `extended.dns.mullvad.net` (DoH), which includes blocklists against ads, tackers and malware by default. If you want the most private setup, run your self hosted DNS server. This option will only work on W11.

| Hostname                 | IPv4        | IPv6         | DoH port | DoT port | Ads | Trackers | Malware | Adult | Gambling | Social media |
| ------------------------ | ----------- | ------------ | -------: | -------: | :-: | :------: | :-----: | :---: | :------: | :----------: |
| dns.mullvad.net          | 194.242.2.2 | 2a07:e340::2 |      443 |      853 |     |          |         |       |          |              |
| adblock.dns.mullvad.net  | 194.242.2.3 | 2a07:e340::3 |      443 |      853 |  x  |     x    |         |       |          |              |
| base.dns.mullvad.net     | 194.242.2.4 | 2a07:e340::4 |      443 |      853 |  x  |     x    |    x    |       |          |              |
| extended.dns.mullvad.net | 194.242.2.5 | 2a07:e340::5 |      443 |      853 |  x  |     x    |    x    |       |          |              |
| family.dns.mullvad.net   | 194.242.2.6 | 2a07:e340::6 |      443 |      853 |  x  |     x    |    x    |   x   |     x    |              |
| all.dns.mullvad.net      | 194.242.2.9 | 2a07:e340::9 |      443 |      853 |  x  |     x    |    x    |   x   |     x    |       x      |

> https://github.com/mullvad/dns-blocklists

The DNS server get's applied via registry (tracked while applying it via the settings):
```csv
HKLM\System\CurrentControlSet\Services\Tcpip\Parameters\Interfaces\{NetID}\NameServer  Type: REG_SZ, Length: 24, Data: 194.242.2.5
HKLM\System\CurrentControlSet\Services\Dnscache\InterfaceSpecificParameters\{NetID}\DohInterfaceSettings\Doh\194.242.2.5\DohTemplate  Type: ad.net/dns-query
HKLM\System\CurrentControlSet\Services\Dnscache\InterfaceSpecificParameters\{NetID}\DohInterfaceSettings\Doh\194.242.2.5\DohFlags  Type: REG_QWORD, Length: 8, Data: 2
```
`NetID` is saved in your network adapter GUID key (`{4d36e972-e325-11ce-bfc1-08002be10318}`) named `NetCfgInstanceId`.

---

| DNS Provider | Protocols | Logging / Privacy Policy | [ECS](https://www.privacyguides.org/en/advanced/dns-overview/#what-is-edns-client-subnet-ecs) | Filtering | Signed Apple Profile |
|---|---|---|---|---|---|
| [**AdGuard Public DNS**](https://adguard-dns.io/en/public-dns.html) | Cleartext <br>DoH/3 <br>DoT <br>DoQ <br>DNSCrypt | Anonymized | Anonymized | Based on server choice. Filter list being used can be found here. [*](https://github.com/AdguardTeam/AdGuardSDNSFilter) | Yes [*](https://adguard-dns.io/en/blog/encrypted-dns-ios-14.html) |
| [**Cloudflare**](https://developers.cloudflare.com/1.1.1.1/setup) | Cleartext <br>DoH/3 <br>DoT | Anonymized | No | Based on server choice. | No [*](https://community.cloudflare.com/t/requesting-1-1-1-1-signed-profiles-for-apple/571846) |
| [**Control D Free DNS**](https://controld.com/free-dns) | Cleartext <br>DoH/3 <br>DoT <br>DoQ | No | No | Based on server choice. | Yes <br>[*IOS](https://docs.controld.com/docs/ios-platform) <br>[*MacOS](https://docs.controld.com/docs/macos-platform#manual-setup-profile) |
| [**Mullvad**](https://mullvad.net/en/help/dns-over-https-and-dns-over-tls) | DoH <br>DoT | No | No | Based on server choice. Filter list being used can be found here. [*](https://github.com/mullvad/dns-adblock) | Yes [*](https://github.com/mullvad/encrypted-dns-profiles) |
| [**Quad9**](https://quad9.net) | Cleartext <br>DoH <br>DoT <br>DNSCrypt | Anonymized | Optional | Based on server choice. Malware blocking is included by default. | Yes <br>[*IOS](https://docs.quad9.net/Setup_Guides/iOS/iOS_14_and_later_(Encrypted) <br>[*MacOS](https://docs.quad9.net/Setup_Guides/MacOS/Big_Sur_and_later_(Encrypted) |

> https://www.privacyguides.org/en/dns/  

| Protocol  | Explanation |
| --------- | ---- |
| Cleartext | Traditional DNS over UDP/TCP 53 with no encryption, so anyone on the path can read or alter your queries. |
| DoH/3     | DNS sent inside HTTPS using HTTP/3 on port 443, encrypting lookups and making them look like normal web traffic. |
| DoT       | DNS sent over a TLS encrypted connection on port 853, protecting queries in transit at the transport layer. |
| DoQ       | DNS carried over QUIC with built in encryption and faster handshakes, improving reliability.|
| DNSCrypt  | A non IETF protocol that encrypts and authenticates DNS between client and resolver, with more limited ecosystem support. |
| DoH       | DNS sent inside HTTPS (typically HTTP/2) on port 443, providing encrypted lookups that blend in with regular HTTPS traffic. |

> https://www.cloudflare.com/learning/dns/dns-over-tls/  
> https://www.privacyguides.org/en/advanced/dns-overview/

## DNS Explained

DNS (domain name system) is the phonebook of the internet, which means that it translates domains to the corresponding IP addresses (DNS resolution).

The four types of DNS servers:  
The **recursive resolver** sends requests to the other three nameservers (root -> TLD -> authoritative), if there's no cached data. It saves the data from the authoritative nameserver so the resolver can skip the requests and send back the IP from the domain to the client. If you're not using any specific DNS server, you're using the resolver from your ISP.

The resolver firstly queries a [**root nameserver**](https://root-servers.org/), which returns the [TLD](https://www.iana.org/domains/root/db) (extension or last segment) -> e.g. `.com`, `.org`, `.net` & more. The root servers are managed by [ICANN](https://www.icann.org/resources/pages/what-2012-02-25-en). If the extension e.g. ends with `.org`, the root server would direct to the `.org` TLD nameserver.

The **TLD nameserver** includes data for domain names, it redirects to the authoritative nameserver, after the correct TLD nameserver was found. They are managed from [IANA](https://www.iana.org/domains/root/db), which splits the TLDs into two groups, generic/gTLD (sTLD and uTLD - sponsored & unsponsored, ngTLD counts as gTLD) and county code/ccTLD.

Types of TLDs:  
- **gTLD** -> Generic, common domain names like `.com`, `.org`
- **ccTLD** -> Country code TLDs, like `.us`, `.de`, `.uk` etc.
- [**sTLD**](https://icannwiki.org/index.php?title=Sponsored_Top_level_Domain#List_of_Sponsored_Top_Level_Domains) -> Sponsored by private organizations, reserved for these groups: `.mil`, `.app`, `.gov`
- [**ARPA**](https://www.iana.org/domains/arpa) -> Infrastructural TLD, only contains `.arpa`. Used for reversed DNS lookups, you won't use it
- **ngTLD** -> New gTLD, used for branding, niches, etc.: `.shop`, `.online`, `.tech`
- **Reserved TLD** -> Used for testing, they cannot be used: `.localhost`, `.example`

The **authoritative nameserver** tells the resolver the IP address, from the [A record](https://support.dnsimple.com/articles/a-record/). [Records](https://www.cloudflare.com/learning/dns/dns-records/) are included in authoritative DNS servers and contain information like the IP address, TTL value and more.

Step 9 is the HTTP request from the browser to the IP from the resolver & step 10 returns the web page (mostly HTML data). 

![](https://github.com/nohuto/win-config/blob/main/network/images/dnslookup.png?raw=true)

Some additional info about HTTP request methods you may want to know:  
`GET` & `POST` HTTP request methods are the most common ones. `GET` request awaits data (read a web page), `POST` request means that the user is sending data. There more [request methods](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Methods), but I won't add them here. You're able to turn off `GET` requests in the DDG search engine settings, to hide search queries in the request body (queries aren't visible in browser history or logs), which is why I added this info. You can see request in the network tab (`F12`).

> https://www.privacyguides.org/en/dns/  
> https://dnsimple.com/comics

# SMB Configuration

SMB Client -> Outbound connections:  
> https://learn.microsoft.com/en-us/powershell/module/smbshare/set-smbclientconfiguration?view=windowsserver2025-ps

SMB Server -> Inbound connections:  
> https://learn.microsoft.com/en-us/powershell/module/smbshare/set-smbserverconfiguration?view=windowsserver2025-ps

```powershell
Set-SmbClientConfiguration -EnableBandwidthThrottling $false
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableBandwidthThrottling	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbClientConfiguration -EnableLargeMtu $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableLargeMtu	Type: REG_DWORD, Length: 4, Data: 0
```

```powershell
Set-SmbClientConfiguration -RequireSecuritySignature $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\RequireSecuritySignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbClientConfiguration -EnableSecuritySignature $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\enablesecuritysignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbClientConfiguration -EncryptionCiphers "AES_256_GCM, AES_256_CCM"
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\CipherSuiteOrder	Type: REG_MULTI_SZ, Length: 52, Data: AES_256_GCM, AES_256_CCM, 

Set-SmbServerConfiguration -RequireSecuritySignature $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\RequireSecuritySignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EnableSecuritySignature $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\enablesecuritysignature	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EncryptData $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\EncryptData	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EncryptionCiphers "AES_256_GCM, AES_256_CCM"
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\CipherSuiteOrder	Type: REG_MULTI_SZ, Length: 52, Data: AES_256_GCM, AES_256_CCM, 

Set-SmbServerConfiguration -RejectUnencryptedAccess $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\RejectUnencryptedAccess	Type: REG_DWORD, Length: 4, Data: 1
```
Encryption is enabled by default, some users reported slow read and write speeds. Disabling the encryption  (`$false`) may improve it, otherwise leave it enabled for your own security. Windows automatically uses the most advanced cipher, still 3.1.1 uses `128-GCM` by default. The last command prevent clients that do not support SMB encryption from connecting to encrypted shares.
> https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/overview-server-message-block-signing  
> https://techcommunity.microsoft.com/blog/filecab/configure-smb-signing-with-confidence/2418102

```powershell
Set-SmbClientConfiguration -EnableMultiChannel $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\DisableMultiChannel	Type: REG_DWORD, Length: 4, Data: 0
```
Part of SMB3, is enabled by default. "Multichannel enables file servers to use multiple network connections simultaneously"
> https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/dn610980(v=ws.11)

Disabling leasing may help, but it disables core features like read/write/handle caching that negatively impact many applications, which rely on it.
```powershell
Set-SmbServerConfiguration -EnableLeasing $false
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\DisableLeasing	Type: REG_DWORD, Length: 4, Data: 1
```
> https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/slow-smb-file-transfer#slow-open-of-office-documents

```powershell
Set-SmbClientConfiguration -EnableSMBQUIC $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnableSMBQUIC	Type: REG_DWORD, Length: 4, Data: 1

Set-SmbServerConfiguration -EnableSMBQUIC $true
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\EnableSMBQUIC	Type: REG_DWORD, Length: 4, Data: 1
```
Uses QUIC instead of TCP - [SMB over QUIC prerequisites](https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-over-quic?tabs=windows-admin-center%2Cpowershell2%2Cwindows-admin-center1#prerequisites)
> https://learn.microsoft.com/en-us/windows-server/storage/file-server/smb-over-quic?tabs=powershell%2Cpowershell2%2Cwindows-admin-center1

`None` - No min/max protocol version
`SMB202` - SMB 2.0.2
`SMB210` - SMB 2.1.0
`SMB300` - SMB 3.0.0
`SMB302` - SMB 3.0.2
`SMB311` - SMB 3.1.1

```powershell
Set-SmbServerConfiguration -Smb2DialectMin SMB311 -Smb2DialectMax None
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\MaxSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 65536
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\MinSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 785

Set-SmbClientConfiguration -Smb2DialectMin SMB311 -Smb2DialectMax None
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\MaxSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 65536
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\MinSmb2Dialect	Type: REG_DWORD, Length: 4, Data: 785
```
By default is it set to `None`, which means that the client can use any supported version. SMB 3.1.1, the most secure dialect of the protocol.
> https://learn.microsoft.com/en-us/windows-server/storage/file-server/manage-smb-dialects?tabs=powershell  
> https://techcommunity.microsoft.com/blog/filecab/controlling-smb-dialects/860024

Disable default sharing:
```powershell
Set-SmbServerConfiguration -AutoShareServer $false -AutoShareWorkstation $false -Force
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\AutoShareServer	Type: REG_DWORD, Length: 4, Data: 0
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\AutoShareWks	Type: REG_DWORD, Length: 4, Data: 0
```
> https://learn.microsoft.com/en-us/powershell/module/smbshare/set-smbserverconfiguration?view=windowsserver2025-ps  
> https://woshub.com/enable-remote-access-to-admin-shares-in-workgroup/

---

`Require NTLMv2 Session Security` (options applied for clients & servers):  
"This security setting allows a client to require the negotiation of 128-bit encryption and/or NTLMv2 session security. These values are dependent on the LAN Manager Authentication Level security setting value. The options are:

Require NTLMv2 session security: The connection will fail if NTLMv2 protocol is not negotiated.
Require 128-bit encryption: The connection will fail if strong encryption (128-bit) is not negotiated."

> https://en.wikipedia.org/wiki/NTLM#NTLMv2

```c
// NTLMv2 Off - 128 Bit Encryption On (default)
RegSetValue	HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 536870912

// NTLMv2 On - 128 Bit Encryption On
RegSetValue	HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 537395200

// NTLMv2 Off - 128 Bit Encryption Off
RegSetValue	HKLM\System\CurrentControlSet\Control\Lsa\MSV1_0\NTLMMinClientSec	Type: REG_DWORD, Length: 4, Data: 0
```

---

`Send unencrypted password to connect to third-party SMB servers`:  
```c
// Enabled (security risk)
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnablePlainTextPassword	Type: REG_DWORD, Length: 4, Data: 1

// Disabled (default)
RegSetValue	HKLM\System\CurrentControlSet\Services\LanmanWorkstation\Parameters\EnablePlainTextPassword	Type: REG_DWORD, Length: 4, Data: 0
```

# QoS Policy

Adding the QoS policy via LGPE:
```powershell
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Version    Type: REG_SZ, Length: 8, Data: 1.0
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Application Name    Type: REG_SZ, Length: 68, Data: FortniteClient-Win64-Shipping.exe
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Protocol    Type: REG_SZ, Length: 4, Data: * # TCP and UDP
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Local Port    Type: REG_SZ, Length: 4, Data: * # Any source port
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Local IP    Type: REG_SZ, Length: 4, Data: * # Any source IP
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Local IP Prefix Length    Type: REG_SZ, Length: 4, Data: *
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Remote Port    Type: REG_SZ, Length: 4, Data: * # Any destination port
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Remote IP    Type: REG_SZ, Length: 4, Data: * # Any destination IP
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Remote IP Prefix Length    Type: REG_SZ, Length: 4, Data: *
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\DSCP Value    Type: REG_SZ, Length: 6, Data: 46 # High Priority, Expedited Forwarding (EF)
HKLM\SOFTWARE\Policies\Microsoft\Windows\QoS\Fortnite\Throttle Rate    Type: REG_SZ, Length: 6, Data: -1 # Unspecified throttle rate (none), 'Data' would specify rate in KBps
```
Capturing the network activity after adding the policy:
```powershell
+ Versions: IPv4, Internet Protocol, Header Length = 20
- DifferentiatedServicesField: DSCP: 46, ECN: 0 # Works
   DSCP: (101110..) Differentiated services codepoint 46
   ECT:  (......0.) ECN-Capable Transport not set
   CE:   (.......0) ECN-CE not set
  TotalLength: 132 (0x84)
  Identification: 28587 (0x6FAB)
```
> https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/network-monitor-3  
> https://www.cisco.com/c/en/us/td/docs/switches/datacenter/nexus1000/sw/4_0/qos/configuration/guide/nexus1000v_qos/qos_6dscp_val.pdf  
> https://github.com/valleyofdoom/PC-Tuning/blob/main/docs/research.md#2-how-can-you-verify-whether-a-dscp-qos-policy-is-working-permalink  
> https://webhostinggeeks.com/blog/what-is-differentiated-services-code-point-dscp/  
> https://learn.microsoft.com/en-us/windows-server/networking/technologies/qos/qos-policy-top  
> https://learn.microsoft.com/en-us/windows-server/networking/technologies/qos/qos-policy-manage

![](https://github.com/nohuto/win-config/blob/main/network/images/qosvalues.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/network/images/qosexplanation.png?raw=true)

# Disable Network Discovery

"LLTDIO and Responder are network protocol drivers used for Link Layer Topology Discovery and network diagnostics. LLTDIO discovers network topology and supports QoS functions, while Responder allows the device to be identified and take part in network health assessments."

"The Link Layer Discovery Protocol (LLDP) is a vendor-neutral link layer protocol used by network devices for advertising their identity, capabilities, and neighbors on a local area network based on IEEE 802 technology, principally wired Ethernet. LLDP performs functions similar to several proprietary protocols, such as CDP, FDP, NDP and LLTD."

> https://en.wikipedia.org/wiki/Link_Layer_Discovery_Protocol  
> https://gpsearch.azurewebsites.net/#1829  
> https://gpsearch.azurewebsites.net/#1830

Disable network discovery (includes LLTDIO, Rspndr, LLTD), by pasting the desired command into `powershell`:
```powershell
Set-NetFirewallRule -DisplayGroup "Network Discovery" -Enabled False -Profile Any​ # Domain​, Private, Public​
```
Get the current states with:
```powershell
Get-NetFirewallRule -DisplayGroup "Network Discovery" | Select-Object Name, Enabled, Profile
```
> https://learn.microsoft.com/en-us/powershell/module/netsecurity/set-netfirewallrule?view=windowsserver2025-ps

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

```c
RegistryKey<unsigned char>::Initialize(
    this + 40,
    *(ADAPTER_CONTEXT**)this,
    *(((NDIS_HANDLE*)this) + 1),
    "DisableLLDP",
    0,
    1,
    0,  // default
    0,
    0
)
```
> > [network/assets | networkdisc-DataCenterBridgingConfiguration.c](https://github.com/nohuto/win-config/blob/main/network/assets/networkdisc-DataCenterBridgingConfiguration.c)

---

```json
{
"File": "LinkLayerTopologyDiscovery.admx",
"CategoryName": "LLTD_Category",
"PolicyName": "LLTD_EnableLLTDIO",
"NameSpace": "Microsoft.Policies.LinkLayerTopology",
"Supported": "WindowsVista",
"DisplayName": "Turn on Mapper I/O (LLTDIO) driver",
"ExplainText": "This policy setting changes the operational behavior of the Mapper I/O network protocol driver. LLTDIO allows a computer to discover the topology of a network it's connected to. It also allows a computer to initiate Quality-of-Service requests such as bandwidth estimation and network health analysis. If you enable this policy setting, additional options are available to fine-tune your selection. You may choose the \"Allow operation while in domain\" option to allow LLTDIO to operate on a network interface that's connected to a managed network. On the other hand, if a network interface is connected to an unmanaged network, you may choose the \"Allow operation while in public network\" and \"Prohibit operation while in private network\" options instead. If you disable or do not configure this policy setting, the default behavior of LLTDIO will apply.",
"KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LLTD"
],
"ValueName": "EnableLLTDIO",
"Elements": [
    { "Type": "Boolean", "ValueName": "AllowLLTDIOOnDomain", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "AllowLLTDIOOnPublicNet", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "ProhibitLLTDIOOnPrivateNet", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
]
},
{
"File": "LinkLayerTopologyDiscovery.admx",
"CategoryName": "LLTD_Category",
"PolicyName": "LLTD_EnableRspndr",
"NameSpace": "Microsoft.Policies.LinkLayerTopology",
"Supported": "WindowsVista",
"DisplayName": "Turn on Responder (RSPNDR) driver",
"ExplainText": "This policy setting changes the operational behavior of the Responder network protocol driver. The Responder allows a computer to participate in Link Layer Topology Discovery requests so that it can be discovered and located on the network. It also allows a computer to participate in Quality-of-Service activities such as bandwidth estimation and network health analysis. If you enable this policy setting, additional options are available to fine-tune your selection. You may choose the \"Allow operation while in domain\" option to allow the Responder to operate on a network interface that's connected to a managed network. On the other hand, if a network interface is connected to an unmanaged network, you may choose the \"Allow operation while in public network\" and \"Prohibit operation while in private network\" options instead. If you disable or do not configure this policy setting, the default behavior for the Responder will apply.",
"KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\LLTD"
],
"ValueName": "EnableRspndr",
"Elements": [
    { "Type": "Boolean", "ValueName": "AllowRspndrOnDomain", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "AllowRspndrOnPublicNet", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "ProhibitRspndrOnPrivateNet", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
]
},
```

# Congestion Provider

Placeholder.

> https://www3.cs.stonybrook.edu/~anshul/comsnets24_bbrbbrv2.pdf  
> https://github.com/google/bbr  
> https://www.rfc-editor.org/rfc/rfc6582  
> https://internet2.edu/wp-content/uploads/2022/12/techex22-AdvancedNetworking-ExploringtheBBRv2CongestionControlAlgorithm-Tierney.pdf  
> https://datatracker.ietf.org/meeting/104/materials/slides-104-iccrg-an-update-on-bbr-00  
> https://www.speedguide.net/articles/tcp-congestion-control-algorithms-comparison-7423  
> https://datatracker.ietf.org/meeting/105/materials/slides-105-iccrg-bbr-v2-a-model-based-congestion-control-00

Get your current congestion provider, by pasting the following into powershell:
```
Get-NetTCPSetting | Select SettingName, CongestionProvider
```

![](https://github.com/nohuto/win-config/blob/main/network/images/congnet.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/network/images/congnet2.png?raw=true)

# Disable Wi-Fi

Disables Wi-Fi services/drivers, scheduled tasks.

| Service/Driver | Description |
| --- | --- |
| `WlanSvc` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. |
| `vwififlt` | Virtual WiFi Filter Driver |
| `WwanSvc` | This service manages mobile broadband (GSM & CDMA) data card/embedded module adapters and connections by auto-configuring the networks. It is strongly recommended that this service be kept running for best user experience of mobile broadband devices. |

---

```c
"\\Microsoft\\Windows\\WCM\\WiFiTask" // %SystemRoot%\System32\WiFiTask.exe
"\\Microsoft\\Windows\\WwanSvc\\NotificationTask" // %SystemRoot%\System32\WiFiTask.exe wwan
```

# Disable Active Probing

Active probing sends HTTP requests from the client to a predefined web probe server (by default `www.msftconnecttest.com/connecttest.txt`), using both IPv4 and IPv6 in parallel. If it gets an HTTP 200 response with the expected payload, NCSI marks the interface as having internet connectivity, if the probe fails or returns errors (for example, blocked by a proxy or DNS issues), NCSI treats connectivity as limited.

Passive probing doesn't send its own traffic, it inspects received packets and uses their hop count to infer connectivity. If the measured hop count for an interface meets or exceeds a system minimum (default 8, often changed to 3 in enterprises), NCSI upgrades the interface to "internet" and suppresses further active probes until conditions change, if the hop count is too low, missing, or there's no route to the internet, and no successful active probe has occurred, connectivity is treated as local-only. Passive probes run periodically (every 15 seconds by default) when allowed by Group Policy and when a user has recently logged on, and they serve to keep connectivity status accurate, especially with intermittent network issues.

Disabling passive probing will break the network icon, causing for example spotify to be in offline mode.

See links below for a detailed documentation.

|Icon|Description|
|--|--|
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wired.jpg?raw=true)| Connected (Wired) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wireless.jpg?raw=true)| Connected (Wireless) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-no-internet.jpg?raw=true)| Connected (No internet) |

`PassivePollPeriod` is set to `15` by default = Runs passive probe every 15 seconds. `MaxActiveProbes` to `0` (unlimited) = breaks connection status. If disabling active probes, but leaving passive probes enabled, enable `Enable Passive Mode`.

> https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview  
> https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-frequently-asked-questions  
> https://github.com/nohuto/wpr-reg-records/blob/main/records/NlaSvc.txt  
> [network/assets | probing-NcsiConfigData.c](https://github.com/nohuto/win-config/blob/main/network/assets/probing-NcsiConfigData.c)

---

Miscellaneous notes:

```json
"HKLM\\System\\CurrentControlSet\\services\\NlaSvc\\Parameters\\Internet": {
  "EnableUserActiveProbing": { "Type": "REG_DWORD", "Data": 0 },
  "MaxActiveProbes": { "Type": "REG_DWORD", "Data": 1 }
}
```
```c
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveDnsProbeContent
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveDnsProbeContentV6
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveDnsProbeHost
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveDnsProbeHostV6
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbeContent
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbeContentV6
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbeHost
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbeHostV6
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbePath
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ActiveWebProbePathV6
\Registry\Machine\SYSTEM\ControlSet001\Services\NlaSvc\Parameters\Internet : ReprobeThreshold

HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\Connectivity\DisallowNetworkConnectivityActiveTests: value (DWord 1)
```
```json
{
  "File": "ICM.admx",
  "CategoryName": "InternetManagement_Settings",
  "PolicyName": "NoActiveProbe",
  "NameSpace": "Microsoft.Policies.InternetCommunicationManagement",
  "Supported": "WindowsVista - At least Windows Vista",
  "DisplayName": "Turn off Windows Network Connectivity Status Indicator active tests",
  "ExplainText": "This policy setting turns off the active tests performed by the Windows Network Connectivity Status Indicator (NCSI) to determine whether your computer is connected to the Internet or to a more limited network. As part of determining the connectivity level, NCSI performs one of two active tests: downloading a page from a dedicated Web server or making a DNS request for a dedicated address. If you enable this policy setting, NCSI does not run either of the two active tests. This may reduce the ability of NCSI, and of other components that use NCSI, to determine Internet access. If you disable or do not configure this policy setting, NCSI runs one of the two active tests.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetworkConnectivityStatusIndicator"
  ],
  "ValueName": "NoActiveProbe",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "NCSI.admx",
  "CategoryName": "NCSI_Category",
  "PolicyName": "NCSI_PassivePolling",
  "NameSpace": "Microsoft.Policies.NCSI",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "Specify passive polling",
  "ExplainText": "This Policy setting enables you to specify passive polling behavior. NCSI polls various measurements throughout the network stack on a frequent interval to determine if network connectivity has been lost. Use the options to control the passive polling behavior.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\NetworkConnectivityStatusIndicator"
  ],
  "Elements": [
    { "Type": "Boolean", "ValueName": "DisablePassivePolling", "TrueValue": "1", "FalseValue": "0" }
  ]
},
{
  "File": "nca.admx",
  "CategoryName": "NetworkConnectivityAssistant",
  "PolicyName": "PassiveMode",
  "NameSpace": "Microsoft.Policies.NetworkConnectivityAssistant",
  "Supported": "Windows7 - At least Windows Server 2008 R2 or Windows 7",
  "DisplayName": "DirectAccess Passive Mode",
  "ExplainText": "Specifies whether NCA service runs in Passive Mode or not. Set this to Disabled to keep NCA probing actively all the time. If this setting is not configured, NCA probing is in active mode by default.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\NetworkConnectivityAssistant"
  ],
  "ValueName": "PassiveMode",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable VPNs

SSTP VPN & other VPNs - enable the services, to revert it.

Get current VPN connections:
```powershell
Get-VpnConnection
```
Remove a VPN connection with (or `Remove-VpnConnection`):
```bat
rasphone -r "Name"
```
or `WIN + I` > Network & Internet > VPN > Remove

> https://learn.microsoft.com/en-us/powershell/module/vpnclient/remove-vpnconnection?view=windowsserver2025-ps  
> https://learn.microsoft.com/en-us/powershell/module/vpnclient/?view=windowsserver2025-ps

`Allow VPN over metered networks`:
```c
OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1 = 
    L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\Parameters\\Config\\VpnCostedNetworkSettings",

VpnRegQueryDWord(
    v13,
    OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1,
    L"NoCostedNetwork",
    &g_donotUseCosted,
    v17),

if ( !v17[0] )
    g_donotUseCosted = 0, // default
```
`Allow VPN while Roaming`:
```c
OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters = 
    L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\Parameters\\Config\\VpnCostedNetworkSettings",

VpnRegQueryDWord(
    v15,
    OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters,
    L"NoRoamingNetwork",
    &g_donotUseRoaming,
    v17),

if ( !v17[0] )
    g_donotUseRoaming = 0, // default
```

> [network/assets | vpn-NlmGetCostedNetworkSettings.c](https://github.com/nohuto/win-config/blob/main/network/assets/vpn-NlmGetCostedNetworkSettings.c)

# Disable SMBv1/SMBv2

SMBv1 is only needed for old computers or software (that you usually don't have) and should be disabled, as it's unsafe & not efficient.

Detect current states with:
```powershell
Get-SmbServerConfiguration | Select EnableSMB1Protocol, EnableSMB2Protocol
```
Disable it with (`$true` to enable it):
```powershell
Set-SmbServerConfiguration -EnableSMB1Protocol $false -Force
Disable-WindowsOptionalFeature -Online -FeatureName SMB1Protocol
```

If you want to disable SMBv2 (& SMBv3):
```powershell
Set-SmbServerConfiguration -EnableSMB2Protocol $false -Force
```
`Set-SmbServerConfiguration $false`:
```powershell
"wmiprvse.exe","RegSetValue","HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\SMB2","Type: REG_DWORD, Length: 4, Data: 0"
"wmiprvse.exe","RegSetValue","HKLM\System\CurrentControlSet\Services\LanmanServer\Parameters\SMB1","Type: REG_DWORD, Length: 4, Data: 0"
```

| Functionality                                      | Disabled when SMBv3 is off       | Disabled when SMBv2 is off       |
|----------------------------------------------------|----------------------------------|----------------------------------|
| Transparent failover                               | Yes                              | No                               |
| Scale-out file server access                       | Yes                              | No                               |
| SMB Multichannel                                   | Yes                              | No                               |
| SMB Direct (RDMA)                                  | Yes                              | No                               |
| Encryption (end-to-end)                            | Yes                              | No                               |
| Directory leasing                                  | Yes                              | No                               |
| Performance optimization (small random I/O)        | Yes                              | No                               |
| Request compounding                                | No                               | Yes                              |
| Larger reads and writes                            | No                               | Yes                              |
| Caching of folder and file properties              | No                               | Yes                              |
| Durable handles                                    | No                               | Yes                              |
| Improved message signing (HMAC SHA-256)            | No                               | Yes                              |
| Improved scalability for file sharing              | No                               | Yes                              |
| Support for symbolic links                         | No                               | Yes                              |
| Client oplock leasing model                        | No                               | Yes                              |
| Large MTU / 10 GbE support                         | No                               | Yes                              |
| Improved energy efficiency (clients can sleep)     | No                               | Yes                              |

> https://learn.microsoft.com/en-us/windows-server/storage/file-server/troubleshoot/detect-enable-and-disable-smbv1-v2-v3?tabs=client#disable-smbv2-or-smbv3-for-troubleshooting  
> https://learn.microsoft.com/en-us/windows-server/storage/file-server/troubleshoot/detect-enable-and-disable-smbv1-v2-v3?tabs=server  
> https://techcommunity.microsoft.com/blog/filecab/stop-using-smb1/425858  
> https://thelinuxcode.com/how-to-detect-and-turn-on-off-smbv1-smbv2-and-smbv3-in-windows/

# Disable NetBIOS/mDNS/LLMNR

"`NetbiosOptions` specifies the configurable security settings for the NetBIOS service and determines the mode of operation for NetBIOS over TCP/IP on the parent interface."

Enabling the option includes disabling `LMHOSTS Lookups` - "LMHOSTS is a local text file Windows uses to map NetBIOS names to IPs when other NetBIOS methods (WINS, broadcast) don't give an answer. It lives in C:\Windows\System32\drivers\etc, there's an `lmhosts.sam` example, and it's checked only if `Enable LMHOSTS lookup` is on."

> https://en.wikipedia.org/wiki/LMHOSTS  
> https://github.com/nohuto/wpr-reg-records/blob/main/records/NetBT.txt

`NetbiosOptions`:

| Value | Description                                                                                 |
| ----- | ------------------------------------------------------------------------------------------- |
| 0     | Specifies that the Dynamic Host Configuration Protocol (DHCP) setting is used if available. |
| 1     | Specifies that NetBIOS is enabled. This is the default value if DHCP is not available.      |
| 2     | Specifies that NetBIOS is disabled.                                                         |

Disabling `NetbiosOptions` via network center:
```powershell
RegSetValue	HKLM\System\CurrentControlSet\Services\NetBT\Parameters\Interfaces\Tcpip_{58f1d738-585f-40e2-aa37-39937f740875}\NetbiosOptions	Type: REG_DWORD, Length: 4, Data: 2
```

| Protocol | Purpose | How it works | Notes |
| -------- | ------- | ------------ | ----- |
| LLMNR (Link-Local Multicast Name Resolution) | Local name resolution when DNS isn't available | Sends multicast queries on the local link (IPv4 224.0.0.252, UDP 5355) asking "who has this name?", hosts that own the name reply | Windows-specific legacy fallback, vulnerable to spoofing/poisoning |
| mDNS (Multicast DNS) | Zero-config service/host discovery on local networks (e.g. printer.local) | Uses multicast to 224.0.0.251 (IPv6 ff02::fb) on UDP 5353, devices answer for their own .local names | Cross-platform (Apple Bonjour, now Windows), modern replacement for LLMNR in many cases |
| NetBIOS over TCP/IP | Legacy Windows naming, service announcement and sessions | Uses broadcasts or WINS to resolve NetBIOS names, historically used by SMB/Windows networking | Very old, chatty, bigger attack surface, kept for backward compatibility |

> https://en.wikipedia.org/wiki/Link-Local_Multicast_Name_Resolution  
> https://en.wikipedia.org/wiki/Multicast_DNS  
> https://en.wikipedia.org/wiki/NetBIOS  

```json
{
  "File": "DnsClient.admx",
  "CategoryName": "DNS_Client",
  "PolicyName": "DNS_MDNS",
  "NameSpace": "Microsoft.Policies.DNSClient",
  "Supported": "Windows_10_0_RS2",
  "DisplayName": "Configure multicast DNS (mDNS) protocol",
  "ExplainText": "Specifies if the DNS client will perform name resolution over mDNS. If you enable this policy, the DNS client will use mDNS protocol. If you disable this policy setting, or if you do not configure this policy setting, the DNS client will use locally configured settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\DNSClient"
  ],
  "ValueName": "EnableMDNS",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DnsClient.admx",
  "CategoryName": "DNS_Client",
  "PolicyName": "DNS_SmartMultiHomedNameResolution",
  "NameSpace": "Microsoft.Policies.DNSClient",
  "Supported": "Windows8",
  "DisplayName": "Turn off smart multi-homed name resolution",
  "ExplainText": "Specifies that a multi-homed DNS client should optimize name resolution across networks. The setting improves performance by issuing parallel DNS, link local multicast name resolution (LLMNR) and NetBIOS over TCP/IP (NetBT) queries across all networks. In the event that multiple positive responses are received, the network binding order is used to determine which response to accept. If you enable this policy setting, the DNS client will not perform any optimizations. DNS queries will be issued across all networks first. LLMNR queries will be issued if the DNS queries fail, followed by NetBT queries if LLMNR queries fail. If you disable this policy setting, or if you do not configure this policy setting, name resolution will be optimized when issuing DNS, LLMNR and NetBT queries.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\DNSClient"
  ],
  "ValueName": "DisableSmartNameResolution",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DnsClient.admx",
  "CategoryName": "DNS_Client",
  "PolicyName": "DNS_Netbios",
  "NameSpace": "Microsoft.Policies.DNSClient",
  "Supported": "WindowsVista",
  "DisplayName": "Configure NetBIOS settings",
  "ExplainText": "Specifies if the DNS client will perform name resolution over NetBIOS. By default, the DNS client will disable NetBIOS name resolution on public networks for security reasons. To use this policy setting, click Enabled, and then select one of the following options from the drop-down list: Disable NetBIOS name resolution: Never allow NetBIOS name resolution. Allow NetBIOS name resolution: Always allow NetBIOS name resolution. Disable NetBIOS name resolution on public networks: Only allow NetBIOS name resolution on network adapters which are not connected to public networks. NetBIOS learning mode: Always allow NetBIOS name resolution and use it as a fallback after mDNS/LLMNR queries fail. If you disable this policy setting, or if you do not configure this policy setting, the DNS client will use locally configured settings.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\DNSClient"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "EnableNetbios", "Items": [
        { "DisplayName": "Disable NetBIOS name resolution", "Data": "0" },
        { "DisplayName": "Allow NetBIOS name resolution", "Data": "1" },
        { "DisplayName": "Disable NetBIOS name resolution on public networks", "Data": "2" },
        { "DisplayName": "NetBIOS learning mode", "Data": "3" }
      ]
    }
  ]
},
{
  "File": "DnsClient.admx",
  "CategoryName": "DNS_Client",
  "PolicyName": "Turn_Off_Multicast",
  "NameSpace": "Microsoft.Policies.DNSClient",
  "Supported": "WindowsVista",
  "DisplayName": "Turn off multicast name resolution",
  "ExplainText": "Specifies that link local multicast name resolution (LLMNR) is disabled on the DNS client. LLMNR is a secondary name resolution protocol. With LLMNR, queries are sent using multicast over a local network link on a single subnet from a DNS client to another DNS client on the same subnet that also has LLMNR enabled. LLMNR does not require a DNS server or DNS client configuration, and provides name resolution in scenarios in which conventional DNS name resolution is not possible. If you enable this policy setting, LLMNR will be disabled on all available network adapters on the DNS client. If you disable this policy setting, or you do not configure this policy setting, LLMNR will be enabled on all available network adapters.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows NT\\DNSClient"
  ],
  "ValueName": "EnableMulticast",
  "Elements": [
    { "Type": "EnabledValue", "Data": "0" },
    { "Type": "DisabledValue", "Data": "1" }
  ]
},
```

# Disable IPv6

`0xFFFFFFFF` disables all IPv6 interfaces, even ones Windows needs. The TCP/IP stack then waits for them to initialize and times out, which adds the `~5s` boot delay. The documentation below was taken from the official support articles.

Min Value: `0x00` (default value)  
Max Value: `0xFF` (IPv6 disabled)
Recommended by Microsoft: `0x20` (Prefer IPv4 over IPv6)

|IPv6 Functionality|Registry value and comments|
|---|---|
|Prefer IPv4 over IPv6|Decimal 32<br/>Hexadecimal 0x20<br/>Binary xx1x xxxx<br/><br/>Recommended instead of disabling IPv6.<br/><br/>To confirm preference of IPv4 over IPv6, perform the following commands:<br/><br/>- Open the command prompt or PowerShell.<br/>- Use the 'ping' command to check the preferred IP version. For example, "ping bing.com". <br/>- If IPv4 is preferred, you should see an IPv4 address being returned in the response.<br/><br/>Network Connections:<br/><br/>- Open the command prompt or PowerShell.<br/>- Use 'netsh interface ipv6 show prefixpolicies<br/>- Check if the 'Prefix' policies have been modified to prioritize IPv4.<br/>- The '::ffff:0:0/96' prefix should have a higher precedence than the '::/0' prefix.<br/><br/>For Example, if you have two entries, one with precedence 35 and another with precedence 40, the one with precedence 40 will be preferred.|
|Disable IPv6|Decimal 255<br/>Hexadecimal 0xFF<br/>Binary 1111 1111<br/><br/>See [startup delay occurs after you disable IPv6 in Windows](https://support.microsoft.com/help/3014406) if you encounter startup delay after disabling IPv6 in Windows 7 SP1 or Windows Server 2008 R2 SP1. <br/><br/> Additionally, system startup will be delayed for five seconds if IPv6 is disabled by incorrectly, setting the **DisabledComponents** registry setting to a value of 0xffffffff. The correct value should be 0xff. <br/><br/>  The **DisabledComponents** registry value doesn't affect the state of the check box. Even if the **DisabledComponents** registry key is set to disable IPv6, the check box in the Networking tab for each interface can be checked. This is an expected behavior.<br/><br/> You cannot completely disable IPv6 as IPv6 is used internally on the system for many TCPIP tasks. For example, you will still be able to run ping `::1` after configuring this setting.|
|Disable IPv6 on all nontunnel interfaces|Decimal 16<br/>Hexadecimal 0x10<br/>Binary xxx1 xxxx|
|Disable IPv6 on all tunnel interfaces|Decimal 1<br/>Hexadecimal 0x01<br/>Binary xxxx xxx1|
|Disable IPv6 on all nontunnel interfaces (except the loopback) and on IPv6 tunnel interface|Decimal 17<br/>Hexadecimal 0x11<br/>Binary xxx1 xxx1|
|Prefer IPv6 over IPv4|Binary xx0x xxxx|
|Re-enable IPv6 on all nontunnel interfaces|Binary xxx0 xxxx|
|Re-enable IPv6 on all tunnel interfaces|Binary xxx xxx0|
|Re-enable IPv6 on nontunnel interfaces and on IPv6 tunnel interfaces|Binary xxx0 xxx0|

## How to calculate the registry value

Windows use bitmasks to check the `DisabledComponents` values and determine whether a component should be disabled.

|Name|Setting|
|---|---|
|Tunnel|Disable tunnel interfaces|
|Tunnel6to4|Disable 6to4 interfaces|
|TunnelIsatap|Disable Isatap interfaces|
|Tunnel Teredo|Disable Teredo interfaces|
|Native|Disable native interfaces (also PPP)|
|PreferIpv4|Prefer IPv4 in default prefix policy|
|TunnelCp|Disable CP interfaces|
|TunnelIpTls|Disable IP-TLS interfaces|
  
For each bit, **0** means false and **1** means true. Refer to the following table for an example.

|Setting|Prefer IPv4 over IPv6 in prefix policies|Disable IPv6 on all nontunnel interfaces|Disable IPv6 on all tunnel interfaces|Disable IPv6 on nontunnel interfaces (except the loopback) and on IPv6 tunnel interface|
|---|---|---|---|---|
|Disable tunnel interfaces|0|0|1|1|
|Disable 6to4 interfaces|0|0|0|0|
|Disable Isatap interfaces|0|0|0|0|
|Disable Teredo interfaces|0|0|0|0|
|Disable native interfaces (also PPP)|0|1|0|1|
|Prefer IPv4 in default prefix policy.|1|0|0|0|
|Disable CP interfaces|0|0|0|0|
|Disable IP-TLS interfaces|0|0|0|0|
|Binary|0010 0000|0001 0000|0000 0001|0001 0001|
|Hexadecimal|0x20|0x10|0x01|0x11|

> https://github.com/MicrosoftDocs/SupportArticles-docs/blob/main/support/windows-server/networking/configure-ipv6-in-windows.md  
> https://support.microsoft.com/en-us/topic/startup-delay-occurs-after-you-disable-ipv6-in-windows-da7e0f60-27b0-c27e-7709-7ee9abfc6ef1

# Disable Wi-Fi Sense

Wi-Fi Sense is enabled by default and, when you're signed in with a Microsoft account, can share Wi-Fi access (password stays encrypted in MS servers) with your Outlook and Skype contacts, Facebook contacts can be added. When you join a new network, it asks whether to share it. Networks you used before the upgrade won't trigger the prompt.

> https://learn.microsoft.com/en-us/troubleshoot/windows-client/networking/configure-wifi-sense-and-paid-wifi-service

```json
{
  "File": "wlansvc.admx",
  "CategoryName": "WlanSettings_Category",
  "PolicyName": "WiFiSense",
  "NameSpace": "Microsoft.Policies.WlanSvc",
  "Supported": "Windows_10_0_NOSERVER",
  "DisplayName": "Allow Windows to automatically connect to suggested open hotspots, to networks shared by contacts, and to hotspots offering paid services",
  "ExplainText": "This policy setting determines whether users can enable the following WLAN settings: \"Connect to suggested open hotspots,\" \"Connect to networks shared by my contacts,\" and \"Enable paid services\". \"Connect to suggested open hotspots\" enables Windows to automatically connect users to open hotspots it knows about by crowdsourcing networks that other people using Windows have connected to. \"Connect to networks shared by my contacts\" enables Windows to automatically connect to networks that the user's contacts have shared with them, and enables users on this device to share networks with their contacts. \"Enable paid services\" enables Windows to temporarily connect to open hotspots to determine if paid services are available. If this policy setting is disabled, both \"Connect to suggested open hotspots,\" \"Connect to networks shared by my contacts,\" and \"Enable paid services\" will be turned off and users on this device will be prevented from enabling them. If this policy setting is not configured or is enabled, users can choose to enable or disable either \"Connect to suggested open hotspots\" or \"Connect to networks shared by my contacts\".",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\wcmsvc\\wifinetworkmanager\\config"
  ],
  "ValueName": "AutoConnectAllowedOEM",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Enable Offloads

Network offload features transfer processing tasks from the CPU to the network adapter hardware, reducing system overhead and improving overall network performance. Common offload features include TCP checksum offload, Large Send Offload (LSO), and Receive Side Scaling (RSS).

Enabling network adapter offload features is usually beneficial. However, the network adapter might not be powerful enough to handle the offload capabilities with high throughput. For example, consider a network adapter with limited hardware resources. In that case, enabling segmentation offload features might reduce the maximum sustainable throughput of the adapter. However, if the reduced throughput is acceptable, you should enable the segmentation offload features.

Excludes (deprecated, chimney too):
```json
"SaOffloadCapacityEnabled" = 0
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "*IPChecksumOffloadIPv4" = 3; // range 0-3
  "*LsoV1IPv4" = 1; // range 0-1
  "*LsoV2IPv4" = 1; // range 0-1
  "*LsoV2IPv6" = 1; // range 0-1
  "*PMARPOffload" = 0; // range 0-1
  "*PMNSOffload" = 0; // range 0-1
  "*TCPChecksumOffloadIPv4" = 3; // range 0-3
  "*TCPChecksumOffloadIPv6" = 3; // range 0-3
  "*UDPChecksumOffloadIPv4" = 3; // range 0-3
  "*UDPChecksumOffloadIPv6" = 3; // range 0-3

  "LSOSize" = 64000; // range 1024-64000 - The maximum number of bytes that the TCP/IP stack can pass to an adapter in a single packet.
  "LSOMinSegment" = 2; // range 2-32 - The minimum number of segments that a large TCP packet must be divisible by, before the transport can offload it to a NIC for segmentation.
  "LSOTcpOptions" = 1; // range 0-1 - Enables that the miniport driver to segment a large TCP packet whose TCP header contains TCP options.
  "LSOIpOptions" = 1; // range 0-1 - Enables its NIC to segment a large TCP packet whose IP header contains IP options.

```

| Keyword | Description | Default | Minimum | Maximum |
| --- | --- | --- | --- | --- |
| `*IPChecksumOffloadIPv4` | Device IPv4 checksum handling (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*TCPChecksumOffloadIPv4` | TCP checksum offload for IPv4 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*TCPChecksumOffloadIPv6` | TCP checksum offload for IPv6 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*UDPChecksumOffloadIPv4` | UDP checksum offload for IPv4 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*UDPChecksumOffloadIPv6` | UDP checksum offload for IPv6 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*LsoV1IPv4` | Large Send Offload V1 for IPv4 (0 disabled, 1 enabled) | 1 | 0 | 1 |
| `*LsoV2IPv4` | Large Send Offload V2 for IPv4 (0 disabled, 1 enabled) | 1 | 0 | 1 |
| `*LsoV2IPv6` | Large Send Offload V2 for IPv6 (0 disabled, 1 enabled) | 1 | 0 | 1 |
| `*IPsecOffloadV1IPv4` | IPsec offload V1 for IPv4 (0 disabled, 1 AH enabled, 2 ESP enabled, 3 AH & ESP enabled) | 3 | 0 | 3 |
| `*IPsecOffloadV2` | IPsec offload V2 (0 disabled, 1 AH enabled, 2 ESP enabled, 3 AH & ESP enabled) | 3 | 0 | 3 |
| `*IPsecOffloadV2IPv4` | IPsec offload V2 for IPv4 (0 disabled, 1 AH enabled, 2 ESP enabled, 3 AH & ESP enabled) | 3 | 0 | 3 |
| `*TCPUDPChecksumOffloadIPv4` | Combined IP/TCP/UDP checksum offload for IPv4 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*TCPUDPChecksumOffloadIPv6` | Combined TCP/UDP checksum offload for IPv6 packets (0 disabled, 1 Tx enabled, 2 Rx enabled, 3 Tx & Rx enabled) | 3 | 0 | 3 |
| `*PMARPOffload` | A value that describes whether the device should be enabled to offload the Address Resolution Protocol (ARP) when the system enters a sleep state. | 1 | 0 | 1 |
| `*PMNSOffload` | A value that describes whether the device should be enabled to offload neighbor solicitation (NS) when the system enters a sleep state. | 1 | 0 | 1 |
| `*PMWiFiRekeyOffload` | A value that describes whether the device should be enabled to offload group temporal key (GTK) rekeying for wake-on-wireless-LAN (WOL) when the computer enters a sleep state. | 1 | 0 | 1 |

> https://github.com/nohuto/wpr-reg-records#intel-nic-values  
> https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-top  
> https://www.intel.com/content/www/us/en/support/articles/000005593/ethernet-products.html  
> https://docs.nvidia.com/networking/display/winof2v320/configuring+the+driver+registry+keys#src-111583782_ConfiguringtheDriverRegistryKeys-OffloadRegistryKeys  
> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-power-management.md  
> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/using-registry-values-to-enable-and-disable-task-offloading.md

# Disable WoL

The wake-on-LAN (WOL) feature wakes the computer from a low power state when a network adapter detects a WOL event (typically, a specially constructed Ethernet packet). WOL is supported from *S3* sleep or *S4* hibernate. It's not supported from fast startup or *S5* soft off shutdown states. NICs aren't armed for wake in these states because users don't expect their systems to wake up on their own. WOL is not officially supported from the *S5* soft off state. However, the BIOS on some systems might support arming NICs for wake, even though Windows isn't involved in the process.

> https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#wake-on-lan-behavior

```bat
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```
`powercfg /devicequery wake_programmable` -> devices that are user-configurable to wake the system from a sleep state  
`powercfg /devicequery wake_armed` -> currently configured to wake the system from any sleep state

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "*WakeOnMagicPacket" = 1; // range 0-1
  "*WakeOnPattern" = 1; // range 0-1
  "WakeFromS5" = 2; // range 0-65535
  "WakeOn" = 0; // range 0-4
  "WakeOnLink" = 0; // range 0-2
```

> https://github.com/nohuto/wpr-reg-records#intel-nic-values

`Disable Wait for Link`:
```inf
, Wait for Link
HKR, Ndi\Params\WaitAutoNegComplete,            ParamDesc,              0, %WaitAutoNegComplete%
HKR, Ndi\Params\WaitAutoNegComplete,            default,                0, "2"
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "0",                    0, %Off%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "1",                    0, %On%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "2",                    0, %AutoDetect%
HKR, Ndi\Params\WaitAutoNegComplete,            type,                   0, "enum"
```

---

```inf
HKR, Ndi\Params\*WakeOnMagicPacket,		ParamDesc,	0, 	%MagicPacket%
HKR, Ndi\Params\*WakeOnMagicPacket,		Type,		0, 	"enum"
HKR, Ndi\Params\*WakeOnMagicPacket\enum,	"1",		0, 	%Enabled%
HKR, Ndi\Params\*WakeOnMagicPacket\enum,	"0",		0, 	%Disabled%
HKR, Ndi\Params\*WakeOnMagicPacket,		Default,	0, 	"1"

HKR, Ndi\Params\*WakeOnPattern,			ParamDesc,	0, 	%PatternMatch%
HKR, Ndi\Params\*WakeOnPattern,			Type,		0, 	"enum"
HKR, Ndi\Params\*WakeOnPattern\enum,		"1",		0, 	%Enabled%
HKR, Ndi\Params\*WakeOnPattern\enum,		"0",		0, 	%Disabled%
HKR, Ndi\Params\*WakeOnPattern,			Default,	0, 	"1"

HKR,Ndi\params\S5WakeOnLan,       ParamDesc,  0, %S5WakeOnLan%
HKR,Ndi\params\S5WakeOnLan,       Type,       0, "enum"
HKR,Ndi\params\S5WakeOnLan,       Default,    0, "1"
HKR,Ndi\params\S5WakeOnLan\enum,  "0",        0, %Disabled%
HKR,Ndi\params\S5WakeOnLan\enum,  "1",        0, %Enabled%

HKR, Ndi\Params\ShutdownWake,			ParamDesc,	0,	 %ShutDW%
HKR, Ndi\Params\ShutdownWake,			Type,		0,	 "enum"
HKR, Ndi\Params\ShutdownWake\enum,		1,		0,	 %Enabled%
HKR, Ndi\Params\ShutdownWake\enum,		0,		0,	 %Disabled%
HKR, Ndi\Params\ShutdownWake,			Default,	0,	 "1"

HKR, Ndi\params\WakeFromS5,                     ParamDesc,  0, %WakeFromS5%
HKR, Ndi\params\WakeFromS5,                     default,    0, "1"
HKR, Ndi\params\WakeFromS5,                     type,       0, "enum"
HKR, Ndi\params\WakeFromS5\enum,                "0",        0, %Disable%
HKR, Ndi\params\WakeFromS5\enum,                "1",        0, %Enable%

HKR, Ndi\Params\WakeOnLink,        ParamDesc, , %WakeOnLink%
HKR, Ndi\Params\WakeOnLink,        default,   , "0"
HKR, Ndi\Params\WakeOnLink,        type,      , "enum"
HKR, Ndi\Params\WakeOnLink\enum,   0,         , %WakeOnLink_Disable%
HKR, Ndi\Params\WakeOnLink\enum,   1,         , %WakeOnLink_Enable%

HKR, Ndi\params\WakeOnLinkChange,        ParamDesc,  0, %LinkChgWol%
HKR, Ndi\params\WakeOnLinkChange,        type,       0, "enum"
HKR, Ndi\params\WakeOnLinkChange,        default,    0, "1"
HKR, Ndi\params\WakeOnLinkChange\enum,   "0",        0, %Disabled%
HKR, Ndi\params\WakeOnLinkChange\enum,   "1",        0, %Enabled%

HKR, Ndi\Params\WakeOnMagicPacketFromS5,                ParamDesc,              0, %WakeOnMagicPacketFromS5Settings%
HKR, Ndi\Params\WakeOnMagicPacketFromS5\Enum,           "0",                    0, %Disabled%
HKR, Ndi\Params\WakeOnMagicPacketFromS5\Enum,           "1",                    0, %Enabled%
HKR, Ndi\Params\WakeOnMagicPacketFromS5,                type,                   0, "enum"
HKR, Ndi\Params\WakeOnMagicPacketFromS5,                default,                0, "1"

HKR, Ndi\Params\WakeUpModeCap,       ParamDesc,   0 , %WakeUpMode%
HKR, Ndi\Params\WakeUpModeCap,       default,  0  , "2"
HKR, Ndi\Params\WakeUpModeCap,       type,      0  , "enum"
HKR, Ndi\Params\WakeUpModeCap\enum,  "0",        0 , %WakeUpMode_None%
HKR, Ndi\Params\WakeUpModeCap\enum,  "1",        0 , %WakeUpMode_Magic%
HKR, Ndi\Params\WakeUpModeCap\enum,  "2",        0 , %WakeUpMode_Pattern%
```


# Increase Buffers

The maximum data differs for users, e.g. if applying `4096` it may get rejected, see `inf` blocks below.

Transmit Buffers:  
> Defines the number of Transmit Descriptors. Transmit Descriptors are data segments that enable the adapter to track transmit packets in the system memory. Depending on the size of the packet, each transmit packet requires one or more Transmit Descriptors. You might choose to increase the number of Transmit Descriptors if you notice a problem with transmit performance. Increasing the number of Transmit Descriptors can enhance transmit performance. But, Transmit Descriptors consume system memory. If transmit performance is not an issue, use the default setting.

Receive Buffers:  
> Sets the number of buffers used by the driver when copying data to the protocol memory. Increasing this value can enhance the receive performance, but also consumes system memory. Receive Descriptors are data segments that enable the adapter to allocate received packets to memory. Each received packet requires one Receive Descriptor, and each descriptor uses 2 KB of memory.

> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/29.3.1/receive-buffers/  
> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/transmit-buffers/

```inf
, *TransmitBuffers
HKR, Ndi\params\*TransmitBuffers,               ParamDesc,              0, %TransmitBuffers%
HKR, Ndi\params\*TransmitBuffers,               default,                0, "512"
HKR, Ndi\params\*TransmitBuffers,               min,                    0, "80"
HKR, Ndi\params\*TransmitBuffers,               max,                    0, "2048"
HKR, Ndi\params\*TransmitBuffers,               step,                   0, "8"
HKR, Ndi\params\*TransmitBuffers,               Base,                   0, "10"
HKR, Ndi\params\*TransmitBuffers,               type,                   0, "int"

, *ReceiveBuffers
HKR, Ndi\params\*ReceiveBuffers,                ParamDesc,              0, %ReceiveBuffers%
HKR, Ndi\params\*ReceiveBuffers,                default,                0, "256"
HKR, Ndi\params\*ReceiveBuffers,                min,                    0, "80"
HKR, Ndi\params\*ReceiveBuffers,                max,                    0, "2048"
HKR, Ndi\params\*ReceiveBuffers,                step,                   0, "8"
HKR, Ndi\params\*ReceiveBuffers,                Base,                   0, "10"
HKR, Ndi\params\*ReceiveBuffers,                type,                   0, "int"

HKR, NDI\Params\*ReceiveBuffers,  ParamDesc, 0, "%RecvRingSize%"
HKR, NDI\Params\*ReceiveBuffers,  default,    0, "512"
HKR, NDI\Params\*ReceiveBuffers,  min, 	   0, "64"
HKR, NDI\Params\*ReceiveBuffers,  max, 	   0, "4096"
HKR, NDI\Params\*ReceiveBuffers,  step,	   0, "1"
HKR, NDI\Params\*ReceiveBuffers,  Base,	   0, "10"
HKR, NDI\Params\*ReceiveBuffers,  type,	   0, "dword"
HKR, "", *ReceiveBuffers, 0, "512"

HKR, NDI\Params\*TransmitBuffers,  ParamDesc, 0, "%SendRingSize%"
HKR, NDI\Params\*TransmitBuffers,  default,	  0, "2048"
HKR, NDI\Params\*TransmitBuffers,  min,	   0, "256"
HKR, NDI\Params\*TransmitBuffers,  max,	   0, "4096"
HKR, NDI\Params\*TransmitBuffers,  step,    0, "1"
HKR, NDI\Params\*TransmitBuffers,  Base,    0, "10"
HKR, NDI\Params\*TransmitBuffers,  type,    0, "dword"
HKR, "", *TransmitBuffers,  %REG_SZ%, "2048"
```

Reminder: Each adapter uses it's own default values, means that the `default`/`min`/`max` may be different for you.

# Enable IM/ITR

Some NICs expose multiple interrupt-moderation levels. Use interrupt moderation for CPU-bound workloads and weigh host-CPU savings against added latency. For the lowest possible latency, disable Interrupt Moderation, accepting higher CPU use as a tradeoff. At higher link speeds more interrupts drive up CPU and hurt performance, increasing the ITR lowers the interrupt rate and improves performance. IM batches received packets and starts a timer on first arrival, interrupting when the buffer fills or the timer expires. Many NICs offer more than on/off, with low/medium/high rates that map to shorter or longer timers to favor latency or reduce interrupts.

> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/interrupt-moderation-rate/  
> https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-tuning-nics?tabs=powershell#interrupt-moderation  
> https://enterprise-support.nvidia.com/s/article/understanding-interrupt-moderation

```
Off: ITR = 0 (no limit)
Minimal: ITR = 200
Low: ITR = 400
Medium: ITR = 950
High: ITR = 2000
Extreme: ITR = 3600
Adaptive: ITR = 65535
```
ITR = Interrupt Throttle Rate.

```inf
,  Interrupt Throttle Rate
HKR, Ndi\Params\ITR,                                    ParamDesc,              0, %InterruptThrottleRate%
HKR, Ndi\Params\ITR,                                    default,                0, "65535"
HKR, Ndi\Params\ITR\Enum,                               "65535",                0, %Adaptive%
HKR, Ndi\Params\ITR\Enum,                               "3600",                 0, %Extreme%
HKR, Ndi\Params\ITR\Enum,                               "2000",                 0, %High%
HKR, Ndi\Params\ITR\Enum,                               "950",                  0, %Medium%
HKR, Ndi\Params\ITR\Enum,                               "400",                  0, %Low%
HKR, Ndi\Params\ITR\Enum,                               "200",                  0, %Minimal%
HKR, Ndi\Params\ITR\Enum,                               "0",                    0, %Off%
HKR, Ndi\Params\ITR,                                    type,                   0, "enum"

, *InterruptModeration
HKR, Ndi\Params\*InterruptModeration,                   ParamDesc,              0, %InterruptModeration%
HKR, Ndi\Params\*InterruptModeration,                   default,                0, "1"
HKR, Ndi\Params\*InterruptModeration\Enum,              "0",                    0, %Disabled%
HKR, Ndi\Params\*InterruptModeration\Enum,              "1",                    0, %Enabled%
HKR, Ndi\Params\*InterruptModeration,                   type,                   0, "enum"
```

```
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : ITR
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *InterruptModeration
```

---

Miscellaneous notes:
```c
"RecvIntModCount" = ?; // found it in the "Mellanox ConnectX based IPoIB Adapter (NDIS 6.4)" driver
"RecvIntModTime" = ?; // ^
"SendIntModCount" = ?; // ^
"SendIntModTime" = ?; // ^
```

# Enable RSS

"Receive-Side Scaling (RSS), also known as multi-queue receive, distributes network receive processing across several hardware-based receive queues, allowing inbound network traffic to be processed by multiple CPUs. RSS can be used to relieve bottlenecks in receive interrupt processing caused by overloading a single CPU, and to reduce network latency."

> https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/6/html/performance_tuning_guide/network-rss

Task offloading has to be enabled, or RSS won't work (`DisableTaskOffload`).

I may add more details here soon. RSS is enabled by default, so this is currently more of a placeholder containing the official documentation (see links below) - disabling the option therefore won't "disable" RSS, it only removes the created values.

`RSS::RssReadRegistryParameters` shows miscellaneous values which are related to RSS, see [intelnet6x.c](https://github.com/nohuto/wpr-reg-records/blob/main/assets/intelnet6x.c) for reference:
```c
void __fastcall RSS::RssReadRegistryParameters(RSS *this, struct ADAPTER_CONTEXT *a2, void *a3)
{
  v5 = L"*RSS";
  v13 = L"*RssBaseProcNumber";
  v21 = L"*MaxRssProcessors";
  v29 = L"*NumaNodeId";
  v37 = L"DisablePortScaling";
  v45 = L"ManyCoreScaling";
  v52 = L"*NumRssQueues";
  v60 = L"NumRssQueuesPerVPort";
  v69 = L"EnableLHRssWA";
  v77 = L"ReceiveScalingMode";
  REGISTRY::RegReadRegTable(v3, a2, a3, (struct REGTABLE_ENTRY *)&v4, 0xAu);
}
```
--- 

`*MaxRssProcessors`:  
The maximum number of RSS processors.

`*NumRssQueues`:  
The maximum number of the RSS queues that the device should use.

Configures the number of RSS queues:  
- One queue is used when low CPU utilization is required.
- Two queues are used when good throughput and low CPU utilization are required.
- Four or more queues are used for applications that demand high transaction rates such as web server based applications. With this setting, the CPU utilization may be higher.

(Not all adapters support all RSS queue settings. RSS is not supported on some adapters configured to use Virtual Machine Queues (VMQ). For these adapters VMQ takes precedence over RSS. RSS is disabled.)

`*RssBaseProcGroup`:  
Sets the RSS base processor group for systems with more than 64 processors.

`*RssBaseProcNumber`:  
Sets the desired base CPU number for each interface. The number can be different for each interface. This allows partitioning of CPUs across network adapters.

You might want to set it to a different core than 0 default / 1, e.g. core 2/3.

`*RssMaxProcGroup`:  
The maximum processor group of the RSS interface.

`*RssMaxProcNumber`:  
The maximum processor number of the RSS interface. If `*RssMaxProcNumber` is specified, then `*RssMaxProcGroup` should also be specified.

```json
{ "*NumRssQueues", "2" },
{ "*RssBaseProcNumber", "2" },
{ "*RssMaxProcNumber", "3" },
```

`*RssProfile`:  
|SubkeyName|ParamDesc|Value|EnumDesc|
|--- |--- |--- |--- |
|**\*RSSProfile**|RSS load balancing profile|1|**ClosestProcessor**: Default behavior is consistent with that of Windows Server 2008 R2.|
|||2|**ClosestProcessorStatic**: No dynamic load-balancing - Distribute but don't load-balance at runtime.|
|||3|**NUMAScaling**: Assign RSS CPUs in a round robin basis across every NUMA node to enable applications that are running on NUMA servers to scale well.|
|||4 (Default)|**NUMAScalingStatic**: RSS processor selection is the same as for NUMA scalability without dynamic load-balancing.|
|||5|**ConservativeScaling**: RSS uses as few processors as possible to sustain the load. This option helps reduce the number of interrupts.|
|||6 (Default on heterogeneous CPU systems)|**NdisRssProfileBalanced**: RSS processor selection is based on traffic workload. Only available in [NetAdapterCx](https://learn.microsoft.com/en-us/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-), starting in WDK preview version 25197.|

`RssV2`:  
Enables the RSS v2 feature which improves the Receive Side Scaling by offering dynamic, per-VPort spreading of queues. It reduces the time to update the indirection table. Note: RSSv2 is only supported by NDIS 6.80 and later versions.

`ValidateRssV2`:  
Enables strict argument validation for upper layer testing. Set along with the RssV2 key to enable the RSSv2 feature.  

> https://docs.kernel.org/networking/scaling.html  
> https://docs.nvidia.com/networking/display/winof2v280/configuring+the+driver+registry+keys  
> https://docs.nvidia.com/networking/display/winofv55052000/receive+side+scaling+(rss)  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/introduction-to-receive-side-scaling  
> https://www.intel.com/content/www/us/en/support/articles/000005593/ethernet-products.html

---

```
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *MaxRssProcessors
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *NumRssQueues
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *Rss
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssBaseProcGroup
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssBaseProcNumber
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssMaxProcGroup
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssMaxProcNumber
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssProfile
\Registry\Machine\SYSTEM\ControlSet001\Services\HTTP\Parameters : RssStatusCheckControl
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : MaxNumRssCpus
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : RssBaseCpu
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : MaxNumRssCpus
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : RssBaseCpu
```

# Disable File/Printer Sharing

Disables "Allow other on the network to access shared files and printers on this device" via `@FirewallAPI.dll,-28502` & `ms_msclient`.

```powershell
PS C:\Users\Nohuxi> Get-NetFirewallRule | sort -unique Group | sort DisplayGroup | ft DisplayGroup, Group

DisplayGroup                                                                      Group
------------                                                                      -----
File and Printer Sharing                                                          @FirewallAPI.dll,-28502
File and Printer Sharing (Restrictive)                                            @FirewallAPI.dll,-28672

PS C:\Users\Nohuxi> Get-NetAdapterBinding -Name *

Name                           DisplayName                                        ComponentID          Enabled
----                           -----------                                        -----------          -------
Ethernet                       File and Printer Sharing for Microsoft Networks    ms_server            False
```

> https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/networking-mpssvc-svc-firewallgroups-firewallgroup-group  
> https://learn.microsoft.com/en-us/powershell/module/netadapter/get-netadapterbinding?view=windowsserver2025-ps

```json
{
  "File": "WindowsSandbox.admx",
  "CategoryName": "WindowsSandbox",
  "PolicyName": "AllowPrinterRedirection",
  "NameSpace": "Microsoft.Policies.WindowsSandbox",
  "Supported": "Windows_11_0_NOSERVER_ENTERPRISE_EDUCATION_PRO_SANDBOX",
  "DisplayName": "Allow printer sharing with Windows Sandbox",
  "ExplainText": "This policy setting enables or disables printer sharing from the host into the Sandbox. If you enable this policy setting, host printers will be shared into Windows Sandbox. If you disable this policy setting, Windows Sandbox will not be able to view printers from the host. If you do not configure this policy setting, printer redirection will be disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Sandbox"
  ],
  "ValueName": "AllowPrinterRedirection",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable LLSE

This setting is used to enable/disable the logging of link state changes. If enabled, a link-up change event or a link-down change event generates a message that is displayed in the system event logger. This message contains the link's speed and duplex. Administrators view the event message from the system event log.

The following events are logged:  
- The link is up. (`LINK_UP_CHANGE`)
- The link is down. (`LINK_DOWN_CHANGE`)
- Mismatch in duplex. (`LINK_DUPLEX_MISMATCH`)
- Spanning Tree Protocol detected.

```inf
,Log Link State Event
HKR,Ndi\Params\LogLinkStateEvent,                       ParamDesc,              0, %LogLinkState%
HKR,Ndi\Params\LogLinkStateEvent,                       Type,                   0, "enum"
HKR,Ndi\Params\LogLinkStateEvent,                       Default,                0, "51"
HKR,Ndi\Params\LogLinkStateEvent\Enum,                  "51",                   0, %Enabled%
HKR,Ndi\Params\LogLinkStateEvent\Enum,                  "16",                   0, %Disabled%
```

---

Miscellaenous notes:
```c
"LogWolEvent" = 16  // ?
```

# Disable Flow Control

A sending station (computer or network switch) may be transmitting data faster than the other end of the link can accept it. Using flow control, the receiving station can signal the sender requesting suspension of transmissions until the receiver catches up.

- For adapters to benefit from this feature, link partners must support flow control frames.  
- On systems running a Microsoft Windows Server* operating system, enabling QoS/priority flow control will disable link level flow control.  
- Some devices support Auto Negotiation. Selecting this will cause the device to advertise the value stored in its NVM (usually "Disabled").

> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/flow-control/

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*FlowControl" = 4; // range 0-4
```

> https://github.com/nohuto/wpr-reg-records#intel-nic-values

```inf
, *FlowControl
HKR, Ndi\Params\*FlowControl,                   ParamDesc,              0, %FlowControl%
HKR, Ndi\Params\*FlowControl,                   default,                0, "3"
HKR, Ndi\Params\*FlowControl\Enum,              "0",                    0, %Disabled%
HKR, Ndi\Params\*FlowControl\Enum,              "1",                    0, %FlowControl_TxOnly%
HKR, Ndi\Params\*FlowControl\Enum,              "2",                    0, %FlowControl_RxOnly%
HKR, Ndi\Params\*FlowControl\Enum,              "3",                    0, %FlowControl_Full%
HKR, Ndi\Params\*FlowControl,                   type,                   0, "enum"
```

These 2 examples also show that each adapter/driver have their own defaults.

# Enable Jumbo Packets

As the name says ("Jumbo"), it is used for big packets, you won't use this feature. Jumbo packets are disabled by default. Enable Jumbo Packets **only if all devices across the network support them** and are configured to use the same frame size.

The Jumbo Frames feature enables or disables Jumbo Packet capability. The standard Ethernet frame size is about `1514 bytes`, while Jumbo Packets are larger than this. Jumbo Packets can increase throughput and decrease CPU utilization. However, additional latency may be introduced.

- Enable Jumbo frames only if devices across the network support them and are configured to use the same frame size. When setting up Jumbo Frames on other network devices, be aware that different network devices calculate Jumbo Frame sizes differently. Some devices include the header information in the frame size while others do not. Intel® adapters do not include header information in the frame size.
- Supported protocols are limited to IP (TCP, UDP).
- Using Jumbo frames at 10 or 100 Mbps can result in poor performance or loss of link.
- You must not lower Receive_Buffers or Transmit_Buffers below 256 if jumbo frames are enabled. Doing so will cause loss of link.
- When configuring Jumbo frames on a switch, set the frame size 4 bytes higher for CRC, plus 4 bytes if using VLANs or QoS packet tagging.

> https://www.intel.com/content/www/us/en/support/articles/000005593/ethernet-products.html  
> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/30.5/jumbo-frames/

```inf
HKR, Ndi\params\*JumboPacket,	ParamDesc,	0, %JumboPacket%
HKR, Ndi\params\*JumboPacket,	Type,		0, "enum"
HKR, Ndi\params\*JumboPacket\enum,	"0",	0, "%Bytes1514%"
HKR, Ndi\params\*JumboPacket\enum,	"1",	0, "%Bytes4088%"
HKR, Ndi\params\*JumboPacket\enum,	"2",	0, "%Bytes9014%"
HKR, Ndi\params\*JumboPacket,	Default,	0, "0"
```
`1514` = Disabled.

# Enable RSC/URO

When receiving data, the miniport driver, NDIS, and TCP/IP must all look at each protocol data unit (PDU) header information separately. When large amounts of data are being received, a large amount of overhead is created. Receive segment coalescing (RSC) reduces this overhead by coalescing a sequence of received segments and passing them to the host TCP/IP stack in one operation, so that NDIS and TCP/IP need to only look at one header for the entire sequence.

Starting in Windows 11, version 24H2, UDP receive segment coalescing offload (URO) enables network interface cards (NICs) to coalesce UDP receive segments. NICs can combine UDP datagrams from the same flow that match a set of rules into a logically contiguous buffer. These combined datagrams are then indicated to the Windows networking stack as a single large packet.

Coalescing UDP datagrams reduces the CPU cost to process packets in high-bandwidth flows, resulting in higher throughput and fewer cycles per byte.

> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-receive-segment-coalescing

`"*UdpRsc": { "Type": "REG_SZ", "Data": 1 }` causes high usage of the system idle process for whatever reason, I'll leave it out for now.

```c
```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*RSCIPv4" = 0; // range 0-1
    "*RSCIPv6" = 0; // range 0-1
    "ForceRscEnabled" = 0; // range 0-1
    "RscMode" = 1; // range 0-2
```

> https://github.com/nohuto/wpr-reg-records#intel-nic-values

```c
void __fastcall ReceiveSideCoalescing::ReadRegistryParameters(struct ADAPTER_CONTEXT **this)
{
  RegistryKey<unsigned char>::Initialize(
    (enum RegKeyState *)((char *)this + 36),
    this[1],
    *((NDIS_HANDLE *)this[1] + 383),
    (PUCHAR)"*RSCIPv4",
    0,
    1u,     // range 0-1
    0,
    0,
    0),

  RegistryKey<unsigned char>::Initialize(
    (enum RegKeyState *)((char *)this + 44),
    this[1],
    *((NDIS_HANDLE *)this[1] + 383),
    (PUCHAR)"*RSCIPv6",
    0,
    1u,     // range 0-1
    0,
    0,
    0),

  RegistryKey<unsigned char>::Initialize(
    (enum RegKeyState *)(this + 2),
    this[1],
    *((NDIS_HANDLE *)this[1] + 383),
    (PUCHAR)"ForceRscEnabled",
    0,
    1u,     // range 0-1
    0,
    0,
    0),

  RegistryKey<enum HdSplitLocation>::Initialize(
    (enum RegKeyState *)(this + 3),
    this[1],
    *((NDIS_HANDLE *)this[1] + 383),
    (PUCHAR)"RscMode",
    0,
    2u,     // range 0-2
    1u,
    0,
    0),
}
```

---

Miscellaneous notes:
```c
"ForceRscEnabled": { "Type": "REG_SZ", "Data": 1 },
"RscMode": { "Type": "REG_SZ", "Data": 1 },
```

# Disable VMQ

VMQ is a scaling networking technology for the Hyper-V switch. Without VMQ the networking performance of the Hyper-V switch bound to this network adapter may be reduced. VMQ offloads packet processing to NIC hardware queues, with each queue tied to a specific VM. This increases throughput, spreads work across CPU cores, lowers host CPU use, and scales effectively as more VMs are added on Hyper-V.

It depends on your adapter/driver if VMQ is enabled/disabled by default:

```c
// Intel
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*RssOrVmqPreference" = 0; // range 0-1
    "*VMQ" = 0; // range 0-1
    "*VMQLookaheadSplit" = 0; // range 0-1
    "*VMQVlanFiltering" = 1; // range 0-1
    "VMQSupported" = 0; // range 0-1

    "MaxNumVmqs"; = ?; // found it in the "Mellanox ConnectX based IPoIB Adapter (NDIS 6.4)" driver
```

> https://github.com/nohuto/wpr-reg-records#intel-nic-values

```inf
; Mellanox
; mlx4eth NT specific
HKR, Ndi\Params\*VMQ,  ParamDesc, 0, "%VMQ%"
HKR, Ndi\Params\*VMQ,  Type,      0, "enum"
HKR, Ndi\Params\*VMQ,  Default,   0, "1"
HKR, Ndi\Params\*VMQ,  Optional,  0, "0"
HKR, Ndi\Params\*VMQ\enum,  "0",  0, "%Disabled%"
HKR, Ndi\Params\*VMQ\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQ, %REG_SZ%, "1"
```

| Value | Description | Allowed Values | Default | Notes |
| ----  | ---- | ---- | ---- | ---- |
| `*VMQ`| Enable/disable the VMQ feature. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*VMQLookaheadSplit` | Enable/disable splitting RX buffers into lookahead and post-lookahead buffers. | `0` Disabled - `1` Enabled | `1` | Starting with NDIS 6.30 / Windows Server 2012, this keyword is no longer supported. |
| `*VMQVlanFiltering` | Enable/disable filtering packets by VLAN ID in the MAC header. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*RssOrVmqPreference` | Define whether VMQ capabilities should be enabled instead of RSS. | `0` Report RSS capabilities - `1` Report VMQ capabilities | `0`     | - |
| `*TenGigVmqEnabled` | Enable/disable VMQ on all 10 Gbps adapters. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |
| `*BelowTenGigVmqEnabled` | Enable/disable VMQ on all adapters <10 Gbps. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |

> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-vmq.md  
> https://docs.nvidia.com/networking/display/winofv55053000/ethernet+registry+keys#src-25134589_EthernetRegistryKeys-FlowControlOptions  
> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/virtual-machine-queue-architecture.md  
> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/introduction-to-ndis-virtual-machine-queue--vmq-.md


# Disable SR-IOV

Single Root I/O Virtualization (SR-IOV) is an extension to the PCI Express (PCIe) specification that improves network performance in virtualized environments. SR-IOV allows devices, such as network adapters, to separate access to their resources among various PCIe hardware functions, enabling near-native network performance in Hyper-V virtual machines.

> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-  

It depends on your adapter/driver if SR-IOV is enabled/disabled by default:

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*Sriov" = 0; // range 0-1
    "*SriovPreferred" = 0; // range 0-1
```

> https://github.com/nohuto/wpr-reg-records#intel-nic-values

| SubkeyName            | Value       | EnumDesc |
| --------------------  | ----------- | ---- |
| `*SRIOV`              | 0           | Disabled |
|                       | 1 (Default) | Enabled |
| `*SriovPreferred`     | 0 (Default) | Report RSS/VMQ (per *VmqOrRssPreferrence), do not report SR-IOV |
|                       | 1           | Report SR-IOV capabilities |

> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-sr-iov

```inf
, SRIOV Default switch registry keys.
,
HKR, NicSwitches\0, *SwitchId,   %REG_DWORD%, 0
HKR, NicSwitches\0, *SwitchName, %REG_SZ%, "%DefaultSwitchName%"
HKR, NicSwitches\0, *SwitchType,   %REG_DWORD%, 1
HKR, NicSwitches\0, *Flags,   %REG_DWORD%, 0
HKR, NicSwitches\0, *NumVFs,   %REG_DWORD%, 32

HKR, NDI\Params\*Sriov,      paramDesc, , %Sriov%
HKR, NDI\Params\*Sriov,      type,      , "enum"
HKR, NDI\Params\*Sriov,  Default,   0, "1"
HKR, NDI\Params\*Sriov\enum, 0,         , %Disabled%
HKR, NDI\Params\*Sriov\enum, 1,         , %Enabled%
HKR, "", *SRIOV, %REG_SZ%, "1"

HKR, NDI\Params\*VMQ,  ParamDesc, 0, "%VMQ%"
HKR, NDI\Params\*VMQ,  Type,      0, "enum"
HKR, NDI\Params\*VMQ,  Default,   0, "1"
HKR, NDI\Params\*VMQ,  Optional,  0, "0"
HKR, NDI\Params\*VMQ\enum,  "0",  0, "%Disabled%"
HKR, NDI\Params\*VMQ\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQ, %REG_SZ%, "1"

HKR, NDI\Params\*VMQVlanFiltering,  ParamDesc, 0, "%VMQVlanFiltering%"
HKR, NDI\Params\*VMQVlanFiltering,  Type,      0, "enum"
HKR, NDI\Params\*VMQVlanFiltering,  Default,   0, "1"
HKR, NDI\Params\*VMQVlanFiltering,  Optional,  0, "0"
HKR, NDI\Params\*VMQVlanFiltering\enum,  "0",  0, "%Disabled%"
HKR, NDI\Params\*VMQVlanFiltering\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQVlanFiltering, %REG_SZ%, "1"
```

# Disable FEC

FEC (forwarded error correction) improves link stability, but increases latency. Many high quality optics, direct attach cables, and backplane channels provide a stable link without FEC.

`Auto FEC`: Sets the FEC Mode based on the capabilities of the attached cable.  
`CL108 RS-FEC`: Selects only RS-FEC ability and request capabilities.  
`CL74 FC-FEC/BASE-R`: Selects only BASE-R ability and request capabilities.  
`No FEC`: Disables FEC.

> https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/forward-error-correction-fec-mode/


```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "FecMode" = 0; // range 0-3
```

> https://github.com/nohuto/wpr-reg-records?tab=readme-ov-file#intel-nic-values

```c
RegistryKey<enum HdSplitLocation>::Initialize(
    (struct ADAPTER_CONTEXT *)((char *)*this + 1004),
    *this,
    *((NDIS_HANDLE *)*this + 383),
    (PUCHAR)"FecMode",
    0, // min
    3u, // max
    0, // default
    0,
    1),
```
```inf
HKR, Ndi\Params\FecMode,                         ParamDesc,              0, %FecMode%
HKR, Ndi\Params\FecMode,                         default,                0, "0"
HKR, Ndi\Params\FecMode,                         min,                    0, "0"
HKR, Ndi\Params\FecMode,                         max,                    0, "3"
HKR, Ndi\Params\FecMode\Enum,                    "0",                    0, %Auto_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "1",                    0, %RS_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "2",                    0, %FC_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "3",                    0, %NO_FEC%
HKR, Ndi\Params\FecMode,                         type,                   0, "enum"
```

# Enable Legacy Switch Compatibility Mode

Probably a setting that controls how the adapter handles link negotiation when it's connected behind certain (usually older) network switches. There's no official documentation on it, but it seems to be disabled by default. Some older switches may have problems with modern auto negotiation behavior, enabling the mode (probably) changes how the NIC negotiates speed/duplex so that it behaves more like older hardware.

This should only be enabled, if needed. The text above is just a personal assumption.

`2` = Enabled  
`1` = Disabled

```inf
; Legacy Switch Compatibility Mode
HKR, Ndi\params\LinkNegotiationProcess,                 ParamDesc,              0, %LinkNegotiationProcess%
HKR, Ndi\params\LinkNegotiationProcess,                 default,                0, "1"
HKR, Ndi\params\LinkNegotiationProcess,                 type,                   0, "enum"
HKR, Ndi\params\LinkNegotiationProcess\enum,            "2",                    0, %Enabled%
HKR, Ndi\params\LinkNegotiationProcess\enum,            "1",                    0, %Disabled%
HKR, PROSetNdi\NdiExt\Params\LinkNegotiationProcess,    ExposeLevel,            0, "3"
```

# NDIS Poll Mode

`Threaded DPC + Adaptive` = NDIS poll mode disabled, aptive receive completion method, packet burst buffering via threaded DPC.  
`NDIS Poll Mode` = Packet burst handing disabled (unsupported), NDIS poll mode enabled.

## NDIS Poll Mode

"NDIS Poll Mode is an OS controlled polling execution model that drives the network interface datapath.

Previously, NDIS had no formal definition of a datapath execution context. NDIS drivers typically relied on Deferred Procedure Calls (DPCs) to implement their execution model. However using DPCs can overwhelm the system when long indication chains are made and avoiding this problem requires a lot of code that's tricky to get right. NDIS Poll Mode offers an alternative to DPCs and similar execution tools."

When enabled on RX side, the following capabilities are not be supported:
- AsyncReceiveIndicate
- Receive side Threaded DPC
- Force low resource indication

When enabled on TX side, the following capabilities are not be supported:
- Transmit side Threaded DPC
- TxMaxPostSendsCoalescing is limited to 32

For a detailed documentation, see:
> https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-poll-mode

| Value | Data | Comments |
| ---- | ---- | ---- |
| RecvCompletionMethod | Set to 4 to register and use Ndis Poll Mode | Default is 1 (Adaptive) |
| SendCompletionMethod | Set to 2 to register and use Ndis Poll Mode | Default is 1 (Interrupt) |

```inf
HKR, Ndi\params\*NdisPoll,       ParamDesc,            0, "Ndis Poll Mode"
HKR, Ndi\params\*NdisPoll,       Type,                 0, "enum"
HKR, Ndi\params\*NdisPoll,       Default,              0, "1"
HKR, Ndi\params\*NdisPoll,       Optional,             0, "0"
HKR, Ndi\params\*NdisPoll\enum,  "0",                  0, "Disabled"
HKR, Ndi\params\*NdisPoll\enum,  "1",                  0, "Enabled"
```

Note: `*NdisPoll` is available to NDIS 6.85 and later miniport drivers.

## AsyncReceiveIndicate (Packet Burst Handling)

This feature allows packet burst handling, while avoiding packet drops that may occur when a large amount of packets is sent in a short period of time.

"A threaded DPC is a DPC that the system executes at `IRQL = PASSIVE_LEVEL`. An ordinary DPC preempts the execution of all threads, and cannot be preempted by a thread or by another DPC. If the system has a large number of ordinary DPCs queued, or if one of those DPCs runs for a long period time, every thread will remain paused for an arbitrarily long period of time. Thus, each ordinary DPC increases the system latency, which can damage the performance of time-sensitive applications, such as audio or video playback. Conversely, a threaded DPC can be preempted by an ordinary DPC, but not by other threads. Therefore, the user should use threaded DPCs rather than ordinary DPCs, unless a particular DPC must not be preempted, even by another DPC."

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
    "ThreadDpcEnable"; = 1; // KeThreadDpcEnable
```

> https://github.com/nohuto/wpr-reg-records?tab=readme-ov-file#session-manager-values  
> https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs

| Data | Meaning |
| :----: | ---- |
| 0 | Disabled (default) |
| 1 | Enables packet burst buffering using threaded DPC |
| 2 | Enables packet burst buffering using polling |

> https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf

## Receive Completion Method

Sets the completion methods of the receive packets, and it affects network throughput and CPU utilization. The supported methods are:

- Polling - increases the CPU utilization, because the system polls the received rings for incoming packets; however, it may increase the network bandwidth since the incoming packet is handled faster.
- Adaptive - combines the interrupt and polling methods dynamically, depending on traffic type and network usage.

```inf
HKR, NDI\Params\RecvCompletionMethod,  ParamDesc, 0, "%RecvCompletionMethod%"
HKR, NDI\Params\RecvCompletionMethod,  Type,  0, "enum"
HKR, NDI\Params\RecvCompletionMethod,  Default, 0, "1"
HKR, NDI\Params\RecvCompletionMethod,  Optional, 0, "0"
HKR, NDI\Params\RecvCompletionMethod\enum,  "0", 0, "%Polling%"
HKR, NDI\Params\RecvCompletionMethod\enum,  "1", 0, "%Adaptive%"
HKR, NDI\Params\RecvCompletionMethod\enum,  "2", 0x00000004 , ""
HKR, "", RecvCompletionMethod, 0, "1"
```

> https://docs.nvidia.com/networking/display/winofv55053000/performance+registry+keys
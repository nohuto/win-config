# Disable NetBIOS/mDNS/LLMNR

`NetbiosOptions` specifies the configurable security settings for the NetBIOS service and determines the mode of operation for NetBIOS over TCP/IP on the parent interface.

Enabling the option also turns off [LMHOSTS](https://en.wikipedia.org/wiki/LMHOSTS) lookups, which is a text file in `C:\Windows\System32\drivers\etc` that maps NetBIOS names to IP addresses when WINS and broadcasts find no answer.

`NetbiosOptions`:

| Value | Description |
| --- | --- |
| 0 | Specifies that the Dynamic Host Configuration Protocol (DHCP) setting is used if available. |
| 1 | Specifies that NetBIOS is enabled. This is the default value if DHCP is not available. |
| 2 | Specifies that NetBIOS is disabled. |

Disabling `NetbiosOptions` via network center:
```powershell
HKLM\System\CurrentControlSet\Services\NetBT\Parameters\Interfaces\Tcpip_{58f1d738-585f-40e2-aa37-39937f740875}\NetbiosOptions	Type: REG_DWORD, Length: 4, Data: 2
```

### Protocols Notes

| Protocol | Purpose | How it works | Notes |
| -------- | ------- | ------------ | ----- |
| [LLMNR](https://en.wikipedia.org/wiki/Link-Local_Multicast_Name_Resolution) (Link-Local Multicast Name Resolution) | Local name resolution when DNS isn't available | Sends multicast queries on the local link (IPv4 224.0.0.252, UDP 5355) asking "who has this name?", hosts that own the name reply | Windows-specific legacy fallback, vulnerable to spoofing/poisoning |
| [mDNS](https://en.wikipedia.org/wiki/Multicast_DNS) (Multicast DNS) | Zero-config service/host discovery on local networks (e.g. printer.local) | Uses multicast to 224.0.0.251 (IPv6 ff02::fb) on UDP 5353, devices answer for their own .local names | Cross-platform (Apple Bonjour, now Windows), modern replacement for LLMNR in many cases |
| [NetBIOS](https://en.wikipedia.org/wiki/NetBIOS) over TCP/IP | Legacy Windows naming, service announcement and sessions | Uses broadcasts or WINS to resolve NetBIOS names, historically used by SMB/Windows networking | Very old, chatty, bigger attack surface, kept for backward compatibility |

These defaults are from the `RegPropertyTable` entry in `dnsapi.dll`:

```c
// RegPropertyTable (23H2)

0x1800BB5A0 b'EnableMDNS' default=1 policy=1 tcpip=0 dnscache=1 // 0 = no mDNS queries
0x1800BB5B0 b'EnableNetbios' default=3 policy=1 tcpip=0 dnscache=1 // 0 = no NetBIOS name resolution, 1 allow, 2 off on public networks, 3 learning mode
0x1800BB560 b'EnableMulticast' default=1 policy=1 tcpip=0 dnscache=1 // 0 = no LLMNR queries
0x1800BB2C0 b'DisableSmartNameResolution' default=0 policy=1 tcpip=0 dnscache=1 // 1 = no parallel DNS, LLMNR, NetBT queries
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure multicast DNS (mDNS) protocol](https://noverse.dev/policies?p=DnsClient*DNS_MDNS) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableMDNS` |
| [Turn off smart multi-homed name resolution](https://noverse.dev/policies?p=DnsClient*DNS_SmartMultiHomedNameResolution) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `DisableSmartNameResolution` |
| [Configure NetBIOS settings](https://noverse.dev/policies?p=DnsClient*DNS_Netbios) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableNetbios` |
| [Turn off multicast name resolution](https://noverse.dev/policies?p=DnsClient*Turn_Off_Multicast) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableMulticast` |


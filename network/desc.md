# Encrypted DNS

If you're wondering what `Family`/`Malware`/`Extended` etc. behind the provider names mean, see '[Mullvad](https://mullvad.net/en/help/dns-over-https-and-dns-over-tls#specifications)', '[Quad9](https://docs.quad9.net/services/)', '[AdGuard](https://adguard-dns.io/kb/general/dns-providers/)', '[Cloudflare](https://developers.cloudflare.com/1.1.1.1/setup/)' for details.

The DNS server get's applied via registry (captured while applying it via the settings):
```c
HKLM\System\CurrentControlSet\Services\Tcpip\Parameters\Interfaces\{NetID}\NameServer  Type: REG_SZ, Length: 24, Data: 194.242.2.5
HKLM\System\CurrentControlSet\Services\Dnscache\InterfaceSpecificParameters\{NetID}\DohInterfaceSettings\Doh\194.242.2.5\DohTemplate  Type: ad.net/dns-query
HKLM\System\CurrentControlSet\Services\Dnscache\InterfaceSpecificParameters\{NetID}\DohInterfaceSettings\Doh\194.242.2.5\DohFlags  Type: REG_QWORD, Length: 8, Data: 2
```

`NetID` is saved in your network adapter GUID key (`{4d36e972-e325-11ce-bfc1-08002be10318}`) named `NetCfgInstanceId`.

## [`DNS_DOH_SERVER_SETTINGS`](https://learn.microsoft.com/en-us/windows/win32/api/netioapi/ns-netioapi-dns_doh_server_settings)

This is I guess used for the `DohFlags` value.

```cpp
typedef struct _DNS_DOH_SERVER_SETTINGS {
#if ...
  PWSTR   Template;
#else
  PWSTR   Template;
#endif
  ULONG64 Flags;
} DNS_DOH_SERVER_SETTINGS;
```

| Flag | Meaning |
| --- | --- |
| `DNS_DOH_SERVER_SETTINGS_ENABLE_AUTO (0x0001)` | If this option is present, then the DNS server that's referenced by this property will load its URI template from the system DNS-over-HTTPS system list. When this option is present, the Template field must be set to NULL. This option must not be used together with the `DNS_DOH_SERVER_SETTINGS_ENABLE` option. |
| `DNS_DOH_SERVER_SETTINGS_ENABLE (0x0002)` | If this option is present, then the Template field must point to a valid DNS-over-HTTPS URI template. This option must not be used together with the `DNS_DOH_SERVER_SETTINGS_ENABLE_AUTO` option. |
| `DNS_DOH_SERVER_SETTINGS_FALLBACK_TO_UDP (0x0004)` | This option indicates that the referenced server may fallback to unsecure name resolution (UDP/TCP) if the DNS-over-HTTPS query failed. This option can be used only in addition to `DNS_DOH_SERVER_SETTINGS_ENABLE_AUTO` or `DNS_DOH_SERVER_SETTINGS_ENABLE`. |
| `DNS_DOH_AUTO_UPGRADE_SERVER (0x0008)` | This option allows a DNS server present in an NRPT rule to use the DNS-over-HTTPS template if it has the same IP address as the server referenced by this property. This option can't be used by itself; it must be in addition to `DNS_DOH_SERVER_SETTINGS_ENABLE_AUTO` or `DNS_DOH_SERVER_SETTINGS_ENABLE`. |

## Providers Compared

| Provider | Encryption | DNSSEC | ECS | QNAME | Logging Policy | Filtering | Jurisdiction / Owner |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Quad9](https://quad9.net/) | DoH, DoT | Yes | Off (disabled) | Yes | No logs ([no IP stored](https://quad9.net/privacy/policy)) | Malware/phishing | Switzerland (nonprofit) |
| [Mullvad DNS](https://mullvad.net/en/help/dns-over-https-and-dns-over-tls) | DoH, DoT | Yes | Off | [Yes](https://mullvad.net/en/help/dns-over-https-and-dns-over-tls) | [No logs](https://mullvad.net/en/blog/clarifying-our-no-logging-policy) | Ads/trackers (optional) | Sweden (Mullvad AB) |
| [NextDNS](https://nextdns.io/) | DoH, DoT, DoQ | Yes | Off | [Yes](https://nextdns.io/privacy) | Opt-in ([default no-logs](https://nextdns.io/privacy)) | Ads/trackers/malware | US (NextDNS Inc.) |
| [Cloudflare 1.1.1.1](https://developers.cloudflare.com/1.1.1.1/) | DoH, DoT, DoQ | Yes | Off | Unspecified | [Minimal logs](https://developers.cloudflare.com/1.1.1.1/privacy/public-dns-resolver/) (IP truncated, deleted <25h) | Malware/family (optional) | US (Cloudflare) |
| [AdGuard DNS](https://adguard-dns.io/) | DoH, DoT, DoQ, DNSCrypt | Yes | Unspecified | Unspecified | No personal data on public DNS | Ads/malware blocking | EU (AdGuard team) |

`Quad9/Mullvad > AdGuard > NextDNS > Cloudflare` in my option based on my findings. I wouldn't recommend to use DNS resolvers like 'Google Public DNS', just read through their privacy policies and see if they support DNSSEC/QNAME minimalisation/encrypted DNS, disable ECS (EDNS Client Subnet), and don't collect identifiable query logs (that's how I created the table above, including some other facts like Mullvad supporting anycast).

## DNS Explained

DNS (domain name system) is the phonebook of the internet, which means that it translates domains to the corresponding IP addresses (DNS resolution). See [DNSimple comics](https://dnsimple.com/comics) for a very simple explanation/[DNSimple glossary](https://support.dnsimple.com/articles/dns-glossary/) and/or [Cloudflare DNS docs](https://www.cloudflare.com/learning/dns/what-is-dns/).

### Protocols

| Protocol  | Explanation |
| --- | --- |
| Cleartext | Traditional DNS over UDP/TCP 53 with no encryption, so anyone on the path can read or alter your queries. |
| DoH/3 | DNS sent inside HTTPS using HTTP/3 on port 443, encrypting lookups and making them look like normal web traffic. |
| DoT | DNS sent over a TLS encrypted connection on port 853, protecting queries in transit at the transport layer. |
| DoQ | DNS carried over QUIC with built in encryption and faster handshakes, improving reliability. |
| DNSCrypt | A non IETF protocol that encrypts and authenticates DNS between client and resolver, with more limited ecosystem support. |
| DoH | DNS sent inside HTTPS (typically HTTP/2) on port 443, providing encrypted lookups that blend in with regular HTTPS traffic. |

### Types of DNS servers

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

## Note for iOS users

I personally use [AdGuard](https://adguard-dns.io/), since it's possible to add custom blocklists/user rules (and it supports all lists of Hagezi while [NextDNS](https://my.nextdns.io/) only supports the main ones), while [NextDNS](https://my.nextdns.io/) only provides a specific set of blocklists and doesn't allow custom rules (there're also several other reasons why I wouldn't use their private DNS at the moment, e.g.: their TIF isn't public ([and many other ones](https://github.com/nextdns/metadata))), they didn't solve issues which got reported months ago (), they use lists that aren't actively maintained by default (they also don't update [obselete links](https://github.com/nextdns/blocklists/tree/main/blocklists), causing 10 empty blocklists), they don't look into their GitHub issues (e.g. nextdns/blocklists). Use 'Configuration Profile' instead of downloading the app, you can configure the profile using the links below.

## [Blocklist Manager](https://github.com/nohuto/win-config/blob/main/network/assets/Blocklist-Manger.ps1)

This is an old project of mine ([preview video](https://github.com/nohuto/win-config/blob/main/network/assets/blocklist-mgr/blocklist-mgr.mp4)), which lets you select one or more blocklists (hosts or URLs, for e.g. UBO). The hosts file is a local DNS override used to block domains or redirect websites (`C:\Windows\System32\drivers\etc\hosts`).

- Download: [Blocklist-Manager.ps1](https://github.com/nohuto/win-config/blob/main/network/assets/Blocklist-Manger.ps1)

Examples:

```
0.0.0.0 ads.com -> non routable address
127.0.0.1 ads.com -> loopback address

||ads.com^ -> filter (browser)
@@||ads.com^ -> exception
```

First numbers (IP address) is where the domain will be directed to, the second (domain name) is the site, which is getting redirected (blocked). 

- [`0.0.0.0`](https://en.wikipedia.org/wiki/0.0.0.0) blocks/drops the request instantly - making them "unreachable" (known as being faster than `127.0.01`, but may be incompatible on some systems)
- [`127.0.0.1`](https://en.wikipedia.org/wiki/localhost) redirects the domain to the localhost (your computer) - called "*loopback address*"
- [`||ads.com^`](https://adblockplus.org/filter-cheatsheet?DE_EXCEPTION=1) blocks the domain - wouldn't block `http://domain.com/redirect/http://ads.com/` -> can't be used within the hosts file
⠀
You should never use all blocklists, as it slows down your system by a lot (and also caused apps to not run as expected anymore). Applying all lists won't give you a better browsing experience, rather try to use at least lists as possible (or use the default preset). Using big lists system wide (hosts file) is also not recommended, if you're planning to use a big list, do that via e.g. uBO (even if the list is compatible with the hosts file).

My suggestion is to choose a specific provider instead of using lists from different ones (if they're meant to block the same things). As you might see, I would choose hagezi at the moment. It's also recommended to apply e.g. 'Native Microsoft' seperately (without 'Pro', 'TIF', etc. so it gets written into the hosts file).

### Issues after importing multiple lists

Open `cmd` and paste `del /f /q C:\Windows\System32\drivers\etc\hosts` into it, if it shows that the DNS client used it, flush your DNS cache (`ipconfig /flushdns`). If this didn't help, boot into safemode (`bcdedit /set safeboot minimal`) & remove the hosts file. This may be needed, if importing too many lists.

The hosts file is empty by default (only comments).

### GUI Buttons

The presets are just examples, use lists from the vendor you prefer.

| Button | Description |
| --- | --- |
| `Minimal` | Preset which can be used by anyone. |
| `Default` | Default preset, uses Pro/TIF without adding the extra lists that aren't included in them. |
| `Maximum` | Aggressive blocking, uses Pro++, TIF and all additional security related lists which aren't included in them (doesn't apply any protections for children). |
| `Import` | Imports the currently selected lists into the `hosts` file (if compatible). |
| `Copy Links` | Copies URLs of all selected lists. Add these links to the custom filter lists:<br>![](https://github.com/nohuto/win-config/blob/main/network/assets/blocklist-mgr/ubolinks.png?raw=true) |
| `Restore` | Imports the backup from: `C:\Windows\System32\drivers\etc\hosts.noverse`. |
| `Open File` | Opens the file: `C:\Windows\System32\drivers\etc\hosts`. |

### Additional Features

- Click on the category name (blue) to open the source link
- Adjust the window size, to increase the size of the hosts/log box
- `hosts` preview refreshes itself automatically
- You can edit the hosts file via the panel in the GUI (doesn't create a backup)

# Enable Network Offloads

Since all topics below are well documented by MS, I won't add much details. Click on the title links for more information on each topic. Note that the main option disables PM protocol offloads, all other offload features are used.

## !ndiskd.netadapter

One way to see the current offload states/capabilities is by using [`!ndiskd.netadapter`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-ndiskd-netadapter):

```c
lkd> !ndiskd.netadapter
    
    .reload ndis.sys....
                     Reload succeeded.

    Driver             NetAdapter          Name                                                                     
    ffffcb06c0111020   ffffcb06c3130030    Intel(R) Ethernet Controller (2) I225-V
    ffffcb06c1115a70   ffffcb06c312c1a0    VirtualBox Host-Only Ethernet Adapter
```

Use the `NetAdapter` address of your adapter with the `-offloads` (PM protocol offloads via `-protocoloffloads`) param and you'll see current state/cabability of each.

```c
lkd> !ndiskd.netadapter ffffcb06c3130030 -offloads


TASK OFFLOADS

    Offload type       Current config                         Hardware capability                                   
    Large Send Offload v1 (LSOv1) with TCP/IPv4
        Encapsulation  802_3                                  802_3
        Max size       0n64240                                0n64240
        Min segments   2                                      2
        IP options     Yes                                    Yes
        TCP options    Yes                                    Yes

    Large Send Offload v2 (LSOv2) with TCP/IPv4
        Encapsulation  802_3                                  802_3
        Max size       0n64240                                0n64240
        Min segments   2                                      2

    Large Send Offload v2 (LSOv2) with TCP/IPv6
        Encapsulation  802_3                                  802_3
        Max size       0n64240                                0n64240
        Min segments   2                                      2
        IP extensions  Yes                                    Yes
        TCP options    Yes                                    Yes

    Checksum offload with TCP/IPv4 on transmit path
        Encapsulation  802_3                                  802_3
        IP checksum    Yes                                    Yes
        TCP checksum   Yes                                    Yes
        UDP checksum   Yes                                    Yes
        IP options     Yes                                    Yes
        TCP options    Yes                                    Yes

    Checksum offload with TCP/IPv4 on receive path
        Encapsulation  802_3                                  802_3
        IP checksum    Yes                                    Yes
        TCP checksum   Yes                                    Yes
        UDP checksum   Yes                                    Yes
        IP options     Yes                                    Yes
        TCP options    Yes                                    Yes

    Checksum offload with TCP/IPv6 on transmit path
        Encapsulation  802_3                                  802_3
        TCP checksum   Yes                                    Yes
        UDP checksum   Yes                                    Yes
        IP extensions  Yes                                    Yes
        TCP options    Yes                                    Yes

    Checksum offload with TCP/IPv6 on receive path
        Encapsulation  802_3                                  802_3
        TCP checksum   Yes                                    Yes
        UDP checksum   Yes                                    Yes
        IP extensions  Yes                                    Yes
        TCP options    Yes                                    Yes

    Receive Segment Coalescing (RSC) with TCP/IPv4
        Enabled        Yes                                    Yes

    Receive Segment Coalescing (RSC) with TCP/IPv6
        Enabled        Yes                                    Yes

    UDP Segmentation Offload (USO) with UDP/IPv4
        Encapsulation  802_3                                  802_3
        Max size       0n64240                                0n64240
        Min segments   2                                      2

    UDP Segmentation Offload (USO) with UDP/IPv6
        Encapsulation  802_3                                  802_3
        Max size       0n64240                                0n64240
        Min segments   2                                      2
        IP extensions  Yes                                    Yes
```

- [OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/oid-tcp-offload-current-config)
- [OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/oid-tcp-offload-hardware-capabilities)

## [NDIS_OFFLOAD_PARAMETERS](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload_parameters)

```c
typedef struct _NDIS_OFFLOAD_PARAMETERS {
  NDIS_OBJECT_HEADER                 Header;
  UCHAR                              IPv4Checksum;
  UCHAR                              TCPIPv4Checksum;
  UCHAR                              UDPIPv4Checksum;
  UCHAR                              TCPIPv6Checksum;
  UCHAR                              UDPIPv6Checksum;
  UCHAR                              LsoV1;
  UCHAR                              IPsecV1;
  UCHAR                              LsoV2IPv4;
  UCHAR                              LsoV2IPv6;
  UCHAR                              TcpConnectionIPv4;
  UCHAR                              TcpConnectionIPv6;
  ULONG                              Flags;
  UCHAR                              IPsecV2;
  UCHAR                              IPsecV2IPv4;
  struct {
    UCHAR RscIPv4;
    UCHAR RscIPv6;
  };
  struct {
    UCHAR EncapsulatedPacketTaskOffload;
    UCHAR EncapsulationTypes;
  };
  union {
    struct {
      USHORT VxlanUDPPortNumber;
    } VxlanParameters;
    ULONG Value;
  } EncapsulationProtocolParameters;
  _ENCAPSULATION_PROTOCOL_PARAMETERS _ENCAPSULATION_PROTOCOL_PARAMETERS;
  struct {
    UCHAR IPv4;
    UCHAR IPv6;
  } UdpSegmentation;
  struct {
    UCHAR Enabled;
  } UdpRsc;
} NDIS_OFFLOAD_PARAMETERS, *PNDIS_OFFLOAD_PARAMETERS;
```

## Registry Values

See [task offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-task-offloading), [network device INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-network-devices), [RSC INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-rsc), [URO](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload), [NVGRE task offload keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-nvgre-task-offload), [connection offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-connection-offloading), [power management keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management), [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic).

```c
"HKLM\\System\\CurrentControlSet\\Services\\TCPIP\\Parameters";
  "DisableTaskOffload" = 0; // REG_DWORD (bool)

"HKLM\\System\\CurrentControlSet\\Services\\Ipsec";
  "EnabledOffload" = 1; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "*IPChecksumOffloadIPv4" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*TCPChecksumOffloadIPv4" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*TCPChecksumOffloadIPv6" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*UDPChecksumOffloadIPv4" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*UDPChecksumOffloadIPv6" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*TCPUDPChecksumOffloadIPv4" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx
  "*TCPUDPChecksumOffloadIPv6" = 3; // REG_SZ, 0 disabled, 1 Tx, 2 Rx, 3 Tx/Rx

  "*LsoV1IPv4" = 1; // REG_SZ (bool)
  "*LsoV2IPv4" = 1; // REG_SZ (bool)
  "*LsoV2IPv6" = 1; // REG_SZ (bool)
  "*UsoIPv4" = 1; // REG_SZ (bool)
  "*UsoIPv6" = 1; // REG_SZ (bool)

  "*RscIPv4" = 1; // REG_SZ (bool)
  "*RscIPv6" = 1; // REG_SZ (bool)
  "*UdpRsc" = 1; // REG_SZ (bool)
  "ForceRscEnabled" = 0; // REG_SZ (bool)
  "RscMode" = 1; // REG_SZ, range 0-2

  "*EncapsulatedPacketTaskOffload" = 1; // REG_SZ (bool)
  "*EncapsulatedPacketTaskOffloadNvgre" = 1; // REG_SZ (bool)
  "*EncapsulatedPacketTaskOffloadVxlan" = 1; // REG_SZ (bool)
  "*VxlanUDPPortNumber" = 4789; // REG_SZ, range 1-65535

  "*IPsecOffloadV1IPv4" = 3; // REG_SZ, 0 disabled, 1 AH, 2 ESP, 3 AH/ESP
  "*IPsecOffloadV2" = 3; // REG_SZ, 0 disabled, 1 AH, 2 ESP, 3 AH/ESP
  "*IPsecOffloadV2IPv4" = 3; // REG_SZ, 0 disabled, 1 AH, 2 ESP, 3 AH/ESP

  "*TCPConnectionOffloadIPv4" = 1; // REG_SZ (bool)
  "*TCPConnectionOffloadIPv6" = 1; // REG_SZ (bool)

  "*PMARPOffload" = 1; // REG_SZ (bool)
  "*PMNSOffload" = 1; // REG_SZ (bool)
  "*PMWiFiRekeyOffload" = 1; // REG_SZ (bool)

  "SaOffloadCapacityEnabled" = 0; // REG_SZ (bool)

  "LSOSize" = 64000; // range 1024-64000 - "The maximum number of bytes that the TCP/IP stack can pass to an adapter in a single packet."
  "LSOMinSegment" = 2; // range 2-32 - "The minimum number of segments that a large TCP packet must be divisible by, before the transport can offload it to a NIC for segmentation."
  "LSOTcpOptions" = 1; // range 0-1 - "Enables that the miniport driver to segment a large TCP packet whose TCP header contains TCP options."
  "LSOIpOptions" = 1; // range 0-1 - "Enables its NIC to segment a large TCP packet whose IP header contains IP options."
```

### [Checksum Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/offloading-checksum-tasks)

Checksums are small integrity values in packet headers. They let the receiver see whether header or payload data changed while the packet was being carried.

With checksum offload enabled, TCP/IP still prepares the packet, but marks the needed checksum work in the [`NET_BUFFER_LIST`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/net-buffer-list-structure) OOB data so the adapter can finish it. For TCP & UDP, TCP/IP writes the pseudoheader sum first, then the adapter completes the final checksum before sending. If checksum offload is disabled or not supported, TCP/IP completes the checksum work in software before handing the packet to the adapter.

On receive, the adapter can check supported checksums and report whether they passed or failed before handing the packet up to NDIS and TCP/IP. IPv4 has an IP header checksum, while IPv6 doesn't, TCP and UDP checksums still apply to both IPv4 and IPv6 traffic.

### [Large Send Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/offloading-the-segmentation-of-large-tcp-packets)

LSO lets TCP/IP give the adapter one large TCP packet with large send metadata in the [`NET_BUFFER_LIST`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/net-buffer-list-structure), instead of building every MTU (maximum transmission unit) sized packet in software.

The adapter uses that large packet as a template and creates normal TCP packets that fit the network MTU. It copies or adjusts the headers, keeps non final packets at MSS (maximum segment size) payload size, updates TCP sequence numbers and length fields, and calculates checksums for the generated packets.

### [UDP Segmentation Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-segmentation-offload-uso-)

USO applies the same large packet segmentation model to UDP traffic, it requires the application to opt into large UDP sends with [`UDP_SEND_MSG_SIZE`](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetudpsendmessagesize) or [`WSASetUdpSendMessageSize`](https://learn.microsoft.com/en-us/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetudpsendmessagesize).

When USO is used, TCP/IP sends one large UDP packet with segmentation metadata. The adapter uses it as a template and creates normal UDP datagrams. USO is independent from UDP checksum offload (so disabling `*UDPChecksumOffloadIPv4` doesn't disable `*UsoIPv4`).

### [Receive Segment Coalescing](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-receive-segment-coalescing)

RSC reduces receive processing for TCP traffic, an RSC capable adapter can combine a valid sequence of TCP segments from the same connection and pass them upward as one larger coalesced unit. This lowers overhead as NDIS & TCP/IP inspect fewer packet indications during high throughput receive traffic.

### [UDP Receive Segment Coalescing Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload)

URO is the UDP receive side coalescing feature introduced in 24H2 & NDIS 6.89. With URO, a NIC can combine UDP datagrams from the same flow into one logically contiguous receive buffer and indicate it to the networking stack as a single large packet (reducing per packet CPU usage).

NDIS can query URO state through [`OID_TCP_OFFLOAD_CURRENT_CONFIG`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/oid-tcp-offload-current-config) and change it through [`OID_TCP_OFFLOAD_PARAMETERS`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/oid-tcp-offload-parameters).

### [Encapsulated Packet Task Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-nvgre-task-offload)

Encapsulated packet task offload is used for overlay traffic such as NVGRE or VXLAN, these packets contain an inner packet wrapped in outer tunnel headers, so the adapter needs to understand both layers before it can offload checksum or segmentation work correctly.

### [IPsec Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-task-offloading)

IPsec offload lets the adapter handle supported AH and ESP work instead of doing all IPsec processing in software.

### [TCP Connection Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/connection-offload)

TCP connection offload moves supported TCP connection processing to the adapter for IPv4 or IPv6 connections. It's different from packet task offloads, which only move specific per packet work such as checksum calculation or segmentation.

### [PM Protocol Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management)

Power management protocol offloads keep selected network presence tasks active while the system sleeps. So for example after the system enters sleep, a NIC can remain in a low power listening state. With `*PMARPOffload`, it can answer ARP requests, with `*PMNSOffload`, it can answer IPv6 neighbor solicitation, with `*PMWiFiRekeyOffload`, a WiFi NIC can handle GTK rekeying for wake on wireless LAN.

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

Specifies the encryption ciphers used by the SMB client and the preferred order, the suboption uses `AES_256_GCM`/`AES_256_CCM`. Windows automatically uses the most advanced cipher available. 3.1.1 still uses `AES-128-GCM` by default unless you explicitly prefer AES-256-capable ciphers.

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

Encryption is enabled by default, some users reported slow read and write speeds. Disabling the encryption (`$false`) may improve it, otherwise leave it enabled for your own security. The last command prevents clients that do not support SMB encryption from connecting to encrypted shares.

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

### [SMB3 Only](https://techcommunity.microsoft.com/blog/filecab/controlling-smb-dialects/860024)

By default is it set to `None`, which means that the client can use any supported version. SMB 3.1.1 is the most secure dialect of the protocol.

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

"This security setting allows a client to require the negotiation of 128-bit encryption and/or NTLMv2 session security. These values are dependent on the LAN Manager Authentication Level security setting value. The options are:

Require NTLMv2 session security: The connection will fail if NTLMv2 protocol is not negotiated.
Require 128-bit encryption: The connection will fail if strong encryption (128-bit) is not negotiated."

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

# Disable Network Discovery

LLTDIO and Responder are network protocol drivers used for Link Layer Topology Discovery and network diagnostics. LLTDIO discovers network topology and supports QoS functions, while Responder allows the device to be identified and take part in network health assessments.

The [Link Layer Discovery Protocol (LLDP)](https://en.wikipedia.org/wiki/Link_Layer_Discovery_Protocol) is a vendor neutral link layer protocol used by network devices for advertising their identity, capabilities, and neighbors on a local area network based on IEEE 802 technology, principally wired Ethernet. LLDP performs functions similar to several proprietary protocols, such as CDP, FDP, NDP and LLTD.

### NetFirewallRule Capture

Disable network discovery (includes LLTDIO, Rspndr, LLTD), by pasting the desired command into `powershell`:
```powershell
Set-NetFirewallRule -DisplayGroup "Network Discovery" -Enabled False -Profile Any​ # Domain​, Private, Public​
```
Get the current states with:
```powershell
Get-NetFirewallRule -DisplayGroup "Network Discovery" | Select-Object Name, Enabled, Profile
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

- [network/assets | networkdisc-DataCenterBridgingConfiguration.c](https://github.com/nohuto/win-config/blob/main/network/assets/networkdisc-DataCenterBridgingConfiguration.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn on Mapper I/O (LLTDIO) driver](https://noverse.dev/policies?p=LinkLayerTopologyDiscovery*LLTD_EnableLLTDIO) | `HKLM\Software\Policies\Microsoft\Windows\LLTD` | `EnableLLTDIO`<br>`AllowLLTDIOOnDomain`<br>`AllowLLTDIOOnPublicNet`<br>`ProhibitLLTDIOOnPrivateNet` |
| [Turn on Responder (RSPNDR) driver](https://noverse.dev/policies?p=LinkLayerTopologyDiscovery*LLTD_EnableRspndr) | `HKLM\Software\Policies\Microsoft\Windows\LLTD` | `EnableRspndr`<br>`AllowRspndrOnDomain`<br>`AllowRspndrOnPublicNet`<br>`ProhibitRspndrOnPrivateNet` |

# NDIS Poll Mode

> "*NDIS Poll Mode is an OS controlled polling execution model that drives the network interface datapath.*
>
> *Previously, NDIS had no formal definition of a datapath execution context. NDIS drivers typically relied on Deferred Procedure Calls (DPCs) to implement their execution model. However using DPCs can overwhelm the system when long indication chains are made and avoiding this problem requires a lot of code that's tricky to get right. NDIS Poll Mode offers an alternative to DPCs and similar execution tools.*
>
> *NDIS Poll Mode moves the complexity of scheduling decisions away from NIC drivers and into NDIS, where NDIS sets work limits per iteration. To achieve this Poll Mode provides:*  
> *- A mechanism for the OS to exert back pressure on the NIC.*  
> *- A mechanism for the OS to finely control interrupts.*
>
> *NDIS Poll Mode is available to NDIS 6.85 and later miniport drivers.*"
>
> — Microsoft, [NDIS Poll Mode](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-poll-mode)

## MS INF

`*NdisPoll` is a MS INF keyword for enabling/disabling NDIS Poll Mode support:

```c
HKR, Ndi\params\*NdisPoll,       ParamDesc,            0, "Ndis Poll Mode"
HKR, Ndi\params\*NdisPoll,       Type,                 0, "enum"
HKR, Ndi\params\*NdisPoll,       Default,              0, "1"
HKR, Ndi\params\*NdisPoll,       Optional,             0, "0"
HKR, Ndi\params\*NdisPoll\enum,  "0",                  0, "Disabled"
HKR, Ndi\params\*NdisPoll\enum,  "1",                  0, "Enabled"
```

## [NVIDIA WinOF-2](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)

That guide ([WinOF-2 v23.7](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)) uses the values to register and use NDIS Poll Mode, it depends on your driver version whenever they're accepted (e.g. `mlx5.sys` `2.53.23539` has a range of `0-3` for `RecvCompletionMethod`, `4` would be invalid causing it to fallback to the default (`1`)).

| Side | Value | Default |
| ---- | ---- | ---- |
| Receive | `RecvCompletionMethod = 4` | `1` (Adaptive) |
| Transmit | `SendCompletionMethod = 2` | `1` (Interrupt) |

## [AsyncReceiveIndicate](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf) (Packet Burst Handling)

This feature (used by mlx driver) allows packet burst handling, while avoiding packet drops that may occur when a large amount of packets is sent in a short period of time.

| Data | Meaning |
| ---- | ---- |
| 0 | Disabled (default) |
| 1 | Enables packet burst buffering using threaded DPC |
| 2 | Enables packet burst buffering using polling |

## [Receive Completion Method](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)

`RecvCompletionMethod` selects how the Mellanox (NVIDIA) driver handles receive completions:

- `0` (`Polling`) polls the receive ring until the configured `ThreadPoll` count is reached without receiving a packet, then stops polling and rearms the interrupt (`CRxQueue::PollFunction`)
- `1` (`Adaptive`, default) combines interrupts and polling according to traffic and network use
- `4` registers and uses NDIS Poll Mode (on WinOF-2 drivers that support it)

### Setup Information

```c
HKR, NDI\Params\RecvCompletionMethod,  ParamDesc, 0, "%RecvCompletionMethod%"
HKR, NDI\Params\RecvCompletionMethod,  Type,  0, "enum"
HKR, NDI\Params\RecvCompletionMethod,  Default, 0, "1"
HKR, NDI\Params\RecvCompletionMethod,  Optional, 0, "0"
HKR, NDI\Params\RecvCompletionMethod\enum,  "0", 0, "%Polling%"
HKR, NDI\Params\RecvCompletionMethod\enum,  "1", 0, "%Adaptive%"
HKR, "", RecvCompletionMethod, 0, "1"
```

# Congestion Provider

The following information isn't meant to be complete or whatever, it's a short overview including some basics.

## Congestion and when it happens

[Congestion control](https://datatracker.ietf.org/doc/rfc5681/) lives in the kernel transport layer, a socket gets a TCP setting/template, and that template carries the congestion provider and related TCP behavior. Congestion happens when one or more flows put more data onto the path than the bottleneck can forward at that moment, so packets build up in queues or get dropped. Windows can apply these settings globally, automatically, or through transport filters bound to prefixes or port ranges.

Note that CongestionProvider (as the cmdlet `Get-NetTCPSetting` tells) controls TCP behavior.

### Terms

[*Queue buildup*](https://www.rfc-editor.org/rfc/rfc7567) happens when packets reach the bottleneck faster than they leave. That is the basic congestion event.

*RTT growth* is usually the earliest visible symptom, because extra in-flight data turns into queueing delay. CTCP explicitly uses RTT growth as an early signal, especially on higher-latency paths.

[*ECN marking*](https://www.rfc-editor.org/rfc/rfc3168.html) happens on ECN-enabled paths when queues cross a marking threshold. This is typical in controlled datacenter fabrics and Hyper-V/virtual-switch environments built for DCTCP.

*Packet loss* happens when queue growth exceeds available buffer, or when the path has random/noisy loss. Loss based algorithms treat that as the main congestion signal.

## SettingName Table

| SettingName | Purpose / When to use |
|---|---|
| `Automatic` | Default selector. Uses latency to choose `Internet` or `Datacenter`. If `AutomaticUseCustom` is enabled, it chooses `InternetCustom` or `DatacenterCustom` instead. |
| `Internet` | Built-in template for higher latency, lower throughput networks. |
| `Datacenter` | Built-in template for lower latency, higher throughput networks. |
| `Compat` | Compatibility template for legacy equipment or older application/network behavior. |
| `InternetCustom` | Custom Internet side template. Use when you want to override the provider. |
| `DatacenterCustom` | Custom datacenter side template. Use when you want to override the provider. |

## CongestionProvider Table

| Provider | Description / algorithm |
|---|---|
| `Default` | System default provider ([CUBIC](https://www.ietf.org/rfc/rfc9438.html)) |
| `CTCP` | Microsoft hybrid loss + delay control. It adds a delay based window to standard TCP behavior and uses RTT/queue growth as an early signal.|
| `DCTCP` | ECN-based datacenter control. It estimates the fraction of marked packets and reduces the window proportionally, keeping queues small. |
| [`CUBIC`](https://www.ietf.org/rfc/rfc9438.html) | Loss based control with a cubic window growth function after a congestion event. Built for scalable high BDP (bandwidth delay product) behavior. |
| `BBR2` | BBR = Bottleneck Bandwidth and Round-trip Time. Public literature describes it as using delivery rate, RTT, and loss to target high throughput with low queueing. |

See your current congestion provider via:
```powershell
Get-NetTCPSetting | Select SettingName, CongestionProvider
```

# Speed & Duplex

Speed = rate at which data is transmitted.
Duplex = nature of the communication:
- Half-duplex: data can either be sent or received, but not both at the same time
- Full-duplex: data transmission occurs in both directions at once

![](https://github.com/nohuto/win-config/blob/main/network/images/duplex.jpg?raw=true)

You should always use `Full-duplex`, `Half-duplex` was used in older networks with hubs. In auto negotiation, both devices announce their capabilities for speed and duplex.

For example:
- A computer's network interface can operate at 10 or 100 Mbps and supports both half-duplex and full-duplex
- A network switch's interface can operate at 10, 100, or 1000 Mbps and supports both duplex modes

Once these capabilities are shared, they agree on the highest common speed and prioritize full-duplex over half-duplex.

NDIS is the network "port" driver, and vendor miniport drivers interpret adapter specific settings. `*SpeedDuplex` is a miniport defined advanced property, unsupported values are ignored or treated as auto negotiation by the driver.

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*SpeedDuplex" = 0; // range 0-50000
```

## Setup Information

Intel driver example:
```c
HKR, Ndi\params\*SpeedDuplex,                           ParamDesc,              0, %SpeedDuplex%
HKR, Ndi\params\*SpeedDuplex,                           default,                0, "0"
HKR, Ndi\params\*SpeedDuplex,                           type,                   0, "enum"
HKR, Ndi\params\*SpeedDuplex\enum,                      "0",                    0, %AutoNegotiation%
HKR, Ndi\params\*SpeedDuplex\enum,                      "1",                    0, %10Mb_Half_Duplex%
HKR, Ndi\params\*SpeedDuplex\enum,                      "2",                    0, %10Mb_Full_Duplex%
HKR, Ndi\params\*SpeedDuplex\enum,                      "3",                    0, %100Mb_Half_Duplex%
HKR, Ndi\params\*SpeedDuplex\enum,                      "4",                    0, %100Mb_Full_Duplex%
HKR, Ndi\params\*SpeedDuplex\enum,                      "6",                    0, %1000Mb_Full_Duplex%
HKR, Ndi\params\*SpeedDuplex\enum,                      "2500",                 0, %2500Mb_Full_Duplex%

; Localizable Strings
SpeedDuplex                     = "Speed & Duplex"
10Mb_Half_Duplex                = "10 Mbps Half Duplex"
10Mb_Full_Duplex                = "10 Mbps Full Duplex"
100Mb_Half_Duplex               = "100 Mbps Half Duplex"
100Mb_Full_Duplex               = "100 Mbps Full Duplex"
1000Mb_Full_Duplex              = "1.0 Gbps Full Duplex"
2500Mb_Full_Duplex              = "2.5 Gbps Full Duplex"
```

Note: 2.5 Gbps Full Duplex may be driver specific. The 10/100/1000 enums are typically consistent across drivers. You can get all valid data from:
```c
HKLM\SYSTEM\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX\Ndi\Params\*SpeedDuplex
```
`00XX` depends on the used adapter.

# Disable Wi-Fi

Disables Wi-Fi services/drivers, scheduled tasks.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WlanSvc` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. | Win32 Own Process (16) | nativewifip, RpcSs, Ndisuio, wcmsvc | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vwififlt` | Virtual WiFi Filter Driver | Kernel Driver (1) | - | System32\drivers\vwififlt.sys |
| `wcncsvc` | WCNCSVC hosts the Windows Connect Now Configuration which is Microsoft's Implementation of Wireless Protected Setup (WPS) protocol. This is used to configure Wireless LAN settings for an Access Point (AP) or a Wireless Device. The service is started programmatically as needed. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `WFDSConMgrSvc` | Manages connections to wireless services, including wireless display and docking. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NativeWifiP` | NativeWiFi Filter | Kernel Driver (1) | - | system32\DRIVERS\nwifi.sys |
| `Wificx` | Wifi Network Adapter Class Extension | Kernel Driver (1) | NetAdapterCx | system32\drivers\WifiCx.sys |
| `WwanSvc` | This service manages mobile broadband (GSM & CDMA) data card/embedded module adapters and connections by auto-configuring the networks. It is strongly recommended that this service be kept running for best user experience of mobile broadband devices. | Win32 Share Process (32) | RpcSs, NdisUio | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

---

```c
"\\Microsoft\\Windows\\WCM\\WiFiTask" // %WINDIR%\System32\WiFiTask.exe
"\\Microsoft\\Windows\\WwanSvc\\NotificationTask" // %WINDIR%\System32\WiFiTask.exe wwan
```

# Static IP

Reads the active adapter's IPv4 settings from `netsh int ip show config` and applies them directly via registry. A static IP is useful for devices that must keep the same address (NAS, game servers, port forwarding, monitoring agents) so clients and firewall rules always target a stable IP. **Static IP requires a manual DNS server**. Use the `Encrypted DNS` option above to set `NameServer` for the same adapter.

### Terms Meaning

- `IP Address` is the device's local IPv4 on your LAN
- `Default Gateway` is your router IP used to reach other networks (internet)
- `Subnet Mask` defines which IPs are local (same subnet) vs routed via the gateway
- [`DHCP`](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol) (Dynamic Host Configuration Protocol) registers and updates IP address, subnet mask, gateway, and DNS

# Disable Active Probing

### Active Probing

Active probing sends HTTP requests from the client to a predefined web probe server (by default `www.msftconnecttest.com/connecttest.txt`), using both IPv4 and IPv6 in parallel. If it gets an HTTP 200 response with the expected payload, NCSI marks the interface as having internet connectivity, if the probe fails or returns errors (for example, blocked by a proxy or DNS issues), NCSI treats connectivity as limited. See [NCSI FAQs](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-frequently-asked-questions) for more information.

### Passive Probing

Passive probing doesn't send its own traffic, it inspects received packets and uses their hop count to infer connectivity. If the measured hop count for an interface meets or exceeds a system minimum (default 8, often changed to 3 in enterprises), NCSI upgrades the interface to "internet" and suppresses further active probes until conditions change, if the hop count is too low, missing, or there's no route to the internet, and no successful active probe has occurred, connectivity is treated as local-only. Passive probes run periodically (every 15 seconds by default) when allowed by Group Policy and when a user has recently logged on, and they serve to keep connectivity status accurate, especially with intermittent network issues.

Disabling passive probing will break the network icon, causing for example spotify to be in offline mode.

See links below for a detailed documentation.

## [Network Icon Meaning](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview)

|Icon|Description|
|--|--|
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wired.jpg?raw=true)| Connected (Wired) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wireless.jpg?raw=true)| Connected (Wireless) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-no-internet.jpg?raw=true)| Connected (No internet) |

`PassivePollPeriod` is set to `15` by default = Runs passive probe every 15 seconds. `MaxActiveProbes` to `0` (unlimited) = breaks connection status. If disabling active probes, but leaving passive probes enabled, enable `Enable Passive Mode`.

- [network/assets | probing-NcsiConfigData.c](https://github.com/nohuto/win-config/blob/main/network/assets/probing-NcsiConfigData.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Network Connectivity Status Indicator active tests](https://noverse.dev/policies?p=ICM*NoActiveProbe) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `NoActiveProbe` |
| [DirectAccess Passive Mode](https://noverse.dev/policies?p=nca*PassiveMode) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\NetworkConnectivityAssistant` | `PassiveMode` |
| [Specify passive polling](https://noverse.dev/policies?p=NCSI*NCSI_PassivePolling) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `DisablePassivePolling` |

# Disable VPNs

Get current VPN connections:

```powershell
Get-VpnConnection
```

Remove a VPN connection with (or `Remove-VpnConnection`):

```bat
rasphone -r "Name"
```
or `WIN + I` > Network & Internet > VPN > Remove

### Allow VPN over metered networks

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

### Allow VPN while Roaming

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

- [network/assets | vpn-NlmGetCostedNetworkSettings.c](https://github.com/nohuto/win-config/blob/main/network/assets/vpn-NlmGetCostedNetworkSettings.c)

# Disable NetBIOS/mDNS/LLMNR

`NetbiosOptions` specifies the configurable security settings for the NetBIOS service and determines the mode of operation for NetBIOS over TCP/IP on the parent interface.

Enabling the option includes disabling [LMHOSTS](https://en.wikipedia.org/wiki/LMHOSTS) Lookups - "*LMHOSTS is a local text file Windows uses to map NetBIOS names to IPs when other NetBIOS methods (WINS, broadcast) don't give an answer. It lives in C:\Windows\System32\drivers\etc, there's an `lmhosts.sam` example, and it's checked only if `Enable LMHOSTS lookup` is on.*"

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

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Configure multicast DNS (mDNS) protocol](https://noverse.dev/policies?p=DnsClient*DNS_MDNS) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableMDNS` |
| [Turn off smart multi-homed name resolution](https://noverse.dev/policies?p=DnsClient*DNS_SmartMultiHomedNameResolution) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `DisableSmartNameResolution` |
| [Configure NetBIOS settings](https://noverse.dev/policies?p=DnsClient*DNS_Netbios) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableNetbios` |
| [Turn off multicast name resolution](https://noverse.dev/policies?p=DnsClient*Turn_Off_Multicast) | `HKLM\Software\Policies\Microsoft\Windows NT\DNSClient` | `EnableMulticast` |

# Disable IPv6

`0xFFFFFFFF` disables all IPv6 interfaces, even ones Windows needs. The TCP/IP stack then waits for them to initialize and times out, which adds the `~5s` boot delay. The documentation below was taken from the official support articles.

- Min Value: `0x00` (default value)  
- Max Value: `0xFF` (IPv6 disabled)

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

## [Value Calculation](https://github.com/MicrosoftDocs/SupportArticles-docs/blob/main/support/windows-server/networking/configure-ipv6-in-windows.md#how-to-calculate-the-registry-value)

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

# Disable Wi-Fi Sense

Beginning with Windows 10, version 1803, Wi-Fi Sense is no longer available. The following section only applies to Windows 10, version 1709 and prior.

[Wi-Fi Sense](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#23-wi-fi-sense) is enabled by default and, when you're signed in with a Microsoft account, can share Wi-Fi access (password stays encrypted in MS servers) with your Outlook and Skype contacts, Facebook contacts can be added. When you join a new network, it asks whether to share it. Networks you used before the upgrade won't trigger the prompt.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Windows to automatically connect to suggested open hotspots, to networks shared by contacts, and to hotspots offering paid services](https://noverse.dev/policies?p=wlansvc*WiFiSense) | `HKLM\Software\Microsoft\wcmsvc\wifinetworkmanager\config` | `AutoConnectAllowedOEM` |

# Disable WoL

> "*The wake-on-LAN (WOL) feature wakes the computer from a low power state when a network adapter detects a WOL event (typically, a specially constructed Ethernet packet). WOL is supported from `S3` sleep or `S4` hibernate. It's not supported from fast startup or `S5` soft off shutdown states. NICs aren't armed for wake in these states because users don't expect their systems to wake up on their own. WOL is not officially supported from the `S5` soft off state. However, the BIOS on some systems might support arming NICs for wake, even though Windows isn't involved in the process.*"
>
> — Microsoft, [System power states](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#wake-on-lan-behavior)

```bat
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```
`powercfg /devicequery wake_programmable` -> devices that are user-configurable to wake the system from a sleep state  
`powercfg /devicequery wake_armed` -> currently configured to wake the system from any sleep state

## Registry Values

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "*WakeOnMagicPacket" = 1; // range 0-1
  "*WakeOnPattern" = 1; // range 0-1
  "WakeFromS5" = 2; // range 0-65535
  "WakeOn" = 0; // range 0-4
  "WakeOnLink" = 0; // range 0-2
```

### Setup Information

`Disable Wait for Link`:
```powershell
; Wait for Link
HKR, Ndi\Params\WaitAutoNegComplete,            ParamDesc,              0, %WaitAutoNegComplete%
HKR, Ndi\Params\WaitAutoNegComplete,            default,                0, "2"
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "0",                    0, %Off%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "1",                    0, %On%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "2",                    0, %AutoDetect%
HKR, Ndi\Params\WaitAutoNegComplete,            type,                   0, "enum"
```

```c
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

# Network Buffers

The `default`/`min`/`max` data differs for users, e.g. if applying `4096` it may get rejected, see `inf` blocks below (this option won't try to apply the maximum size, read descriptions below).

[Transmit Buffers](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/transmit-buffers/):  
> Defines the number of Transmit Descriptors. Transmit Descriptors are data segments that enable the adapter to track transmit packets in the system memory. Depending on the size of the packet, each transmit packet requires one or more Transmit Descriptors. You might choose to increase the number of Transmit Descriptors if you notice a problem with transmit performance. Increasing the number of Transmit Descriptors can enhance transmit performance. But, Transmit Descriptors consume system memory. If transmit performance is not an issue, use the default setting.

[Receive Buffers](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/29.3.1/receive-buffers/):  
> Sets the number of buffers used by the driver when copying data to the protocol memory. Increasing this value can enhance the receive performance, but also consumes system memory. Receive Descriptors are data segments that enable the adapter to allocate received packets to memory. Each received packet requires one Receive Descriptor, and each descriptor uses 2 KB of memory.

## Setup Information

```powershell
; *TransmitBuffers
HKR, Ndi\params\*TransmitBuffers,               ParamDesc,              0, %TransmitBuffers%
HKR, Ndi\params\*TransmitBuffers,               default,                0, "512"
HKR, Ndi\params\*TransmitBuffers,               min,                    0, "80"
HKR, Ndi\params\*TransmitBuffers,               max,                    0, "2048"
HKR, Ndi\params\*TransmitBuffers,               step,                   0, "8"
HKR, Ndi\params\*TransmitBuffers,               Base,                   0, "10"
HKR, Ndi\params\*TransmitBuffers,               type,                   0, "int"

; *ReceiveBuffers
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

# Interrupt Moderation

> "*To control interrupt moderation, some network adapters expose different interrupt moderation levels, different buffer coalescing parameters (sometimes separately for send and receive buffers), or both.*
>
> *You should consider interrupt moderation for CPU-bound workloads. When using interrupt moderation, consider the trade-off between the host CPU savings and latency versus the increased host CPU savings because of more interrupts and less latency. If the network adapter doesn't perform interrupt moderation, but it does expose buffer coalescing, you can improve performance by increasing the number of coalesced buffers to allow more buffers per send or receive.*"
>
> — Microsoft, [Performance tuning network adapters](https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-tuning-nics?tabs=powershell#interrupt-moderation)

### Data Range

The correct data might be the comment data, if so edit it manually.
```c
Off: ITR = 0 (no limit)
Minimal: ITR = 200 // 32
Low: ITR = 400 // 64
Medium: ITR = 950 // 125
High: ITR = 2000 // 250
Extreme: ITR = 3600 // 500
Adaptive: ITR = 65535
```
ITR = Interrupt Throttle Rate.

## Setup Information

Data/default is driver specific.
```c
;  Interrupt Throttle Rate
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

;  Interrupt Throttle Rate
HKR, Ndi\Params\ITR,                                    ParamDesc,              0, %InterruptThrottleRate%
HKR, Ndi\Params\ITR,                                    default,                0, "64"
HKR, Ndi\Params\ITR\Enum,                               "500",                  0, %Extreme%
HKR, Ndi\Params\ITR\Enum,                               "250",                  0, %High%
HKR, Ndi\Params\ITR\Enum,                               "125",                  0, %Medium%
HKR, Ndi\Params\ITR\Enum,                               "64",                   0, %Low%
HKR, Ndi\Params\ITR\Enum,                               "32",                   0, %Minimal%
HKR, Ndi\Params\ITR\Enum,                               "0",                    0, %Off%
HKR, Ndi\Params\ITR,                                    type,                   0, "enum"

; *InterruptModeration
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

> "*[Receive-Side Scaling (RSS)](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/introduction-to-receive-side-scaling), also known as multi-queue receive, distributes network receive processing across several hardware-based receive queues, allowing inbound network traffic to be processed by multiple CPUs. RSS can be used to relieve bottlenecks in receive interrupt processing caused by overloading a single CPU, and to reduce network latency.*"
>
> — Red Hat Documentation, [Receive-Side Scaling](https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/6/html/performance_tuning_guide/network-rss)

Task offloading has to be enabled, or RSS won't work (`DisableTaskOffload`).

I may add more details here soon. RSS is enabled by default, so this is currently more of a placeholder containing the official documentation (see links below), disabling the option therefore won't "disable" RSS, it only removes the created values.

## Registry Values

`*MaxRssProcessors`:  
The maximum number of RSS processors.

[`*NumRssQueues`](https://www.intel.com/content/www/us/en/support/articles/000005593/ethernet-products.html):  
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

### RssReadRegistryParameters

[`RSS::RssReadRegistryParameters`](https://github.com/nohuto/win-config/blob/main/network/assets/intel-nic/RSS_RssReadRegistryParameters.c) shows miscellaneous values which are related to RSS, see [intelnet6x.c](https://github.com/nohuto/win-config/blob/main/power/assets/intelnet6x.c) for reference:
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

# Disable ICS / Mobile Hotspot

Disables Internet Connection Sharing (ICS), which lets Windows use one network adapter as the public/uplink interface and another as the private/downlink interface. In full mode, ICS turns the PC into a small gateway for other devices by providing NAT and local network services such as addressing through DHCP and name resolution on the private side.

When disabled, the PC can no longer share its internet connection to other devices through the connection Sharing tab / ICS UI, and ICS backed gateway scenarios such as adapter-to-adapter internet sharing or related hotspot-style sharing cannot use the SharedAccess service. ICS is only available when two or more network connections are present.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `icssvc` | Provides the ability to share a cellular data connection with another device. | Win32 Share Process (32) | RpcSs, wcmsvc | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `ALG` | Provides support for 3rd party protocol plug-ins for Internet Connection Sharing | Win32 Own Process (16) | - | C:\Windows\System32\alg.exe |
| `SharedAccess` | Provides network address translation, addressing, name resolution and/or intrusion prevention services for a home or small office network. | Win32 Share Process (32) | BFE | C:\Windows\System32\svchost.exe -k netsvcs -p |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prohibit use of Internet Connection Sharing on your DNS domain network](https://noverse.dev/policies?p=NetworkConnections*NC_ShowSharedAccessUI) | `HKLM\Software\Policies\Microsoft\Windows\Network Connections` | `NC_ShowSharedAccessUI` |

# Disable LLSE

This setting is used to enable/disable the logging of link state changes. If enabled, a link-up change event or a link-down change event generates a message that is displayed in the system event logger. This message contains the link's speed and duplex. Administrators view the event message from the system event log.

The following events are logged:  
- The link is up. (`LINK_UP_CHANGE`)
- The link is down. (`LINK_DOWN_CHANGE`)
- Mismatch in duplex. (`LINK_DUPLEX_MISMATCH`)
- Spanning Tree Protocol detected.

## Setup Information

```c
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

> - *For adapters to benefit from this feature, link partners must support flow control frames.*
> - *On systems running a Microsoft Windows Server operating system, enabling QoS/priority flow control will disable link level flow control.*
> - *Some devices support Auto Negotiation. Selecting this will cause the device to advertise the value stored in its NVM (usually `Disabled`).*"
>
> — Intel, [Flow Control](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/flow-control/)

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*FlowControl" = 4; // range 0-4
```

## Setup Information

```c
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

> "*The Jumbo Frames feature enables or disables Jumbo Packet capability. The standard Ethernet frame size is about `1514 bytes`, while Jumbo Packets are larger than this. Jumbo Packets can increase throughput and decrease CPU utilization. However, additional latency may be introduced.*
>
> - *Enable Jumbo frames only if devices across the network support them and are configured to use the same frame size. When setting up Jumbo Frames on other network devices, be aware that different network devices calculate Jumbo Frame sizes differently. Some devices include the header information in the frame size while others do not. Intel® adapters do not include header information in the frame size.*
> - *Supported protocols are limited to IP (TCP, UDP).*
> - *Using Jumbo frames at 10 or 100 Mbps can result in poor performance or loss of link.*
> - *You must not lower Receive_Buffers or Transmit_Buffers below 256 if jumbo frames are enabled. Doing so will cause loss of link.*
> - *When configuring Jumbo frames on a switch, set the frame size 4 bytes higher for CRC, plus 4 bytes if using VLANs or QoS packet tagging.*"
>
> — Intel, [Jumbo Frames](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/30.5/jumbo-frames/)

## Setup Information

```c
HKR, Ndi\params\*JumboPacket,	ParamDesc,	0, %JumboPacket%
HKR, Ndi\params\*JumboPacket,	Type,		0, "enum"
HKR, Ndi\params\*JumboPacket\enum,	"0",	0, "%Bytes1514%"
HKR, Ndi\params\*JumboPacket\enum,	"1",	0, "%Bytes4088%"
HKR, Ndi\params\*JumboPacket\enum,	"2",	0, "%Bytes9014%"
HKR, Ndi\params\*JumboPacket,	Default,	0, "0"
```
`1514` = Disabled.

# Disable VMQ

[VMQ](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/virtual-machine-queue-architecture.md) is a scaling networking technology for the Hyper-V switch. Without VMQ the networking performance of the Hyper-V switch bound to this network adapter may be reduced. VMQ offloads packet processing to NIC hardware queues, with each queue tied to a specific VM. This increases throughput, spreads work across CPU cores, lowers host CPU use, and scales effectively as more VMs are added on Hyper-V.

It depends on your adapter/driver if VMQ is enabled/disabled by default:

## [Registry Values](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-vmq.md)

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
// Intel
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*RssOrVmqPreference" = 0; // range 0-1
    "*VMQ" = 0; // range 0-1
    "*VMQLookaheadSplit" = 0; // range 0-1
    "*VMQVlanFiltering" = 1; // range 0-1
    "VMQSupported" = 0; // range 0-1

    "MaxNumVmqs" = ?; // found it in the "Mellanox ConnectX based IPoIB Adapter (NDIS 6.4)" driver
```

| Value | Description | Allowed Values | Default | Notes |
| ----  | ---- | ---- | ---- | ---- |
| `*VMQ`| Enable/disable the VMQ feature. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*VMQLookaheadSplit` | Enable/disable splitting RX buffers into lookahead and post-lookahead buffers. | `0` Disabled - `1` Enabled | `1` | Starting with NDIS 6.30 / Windows Server 2012, this keyword is no longer supported. |
| `*VMQVlanFiltering` | Enable/disable filtering packets by VLAN ID in the MAC header. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*RssOrVmqPreference` | Define whether VMQ capabilities should be enabled instead of RSS. | `0` Report RSS capabilities - `1` Report VMQ capabilities | `0`     | - |
| `*TenGigVmqEnabled` | Enable/disable VMQ on all 10 Gbps adapters. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |
| `*BelowTenGigVmqEnabled` | Enable/disable VMQ on all adapters <10 Gbps. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |

### Setup Information

```powershell
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

# Disable SR-IOV

> "*Single Root I/O Virtualization (SR-IOV) is an extension to the PCI Express (PCIe) specification that improves network performance in virtualized environments. SR-IOV allows devices, such as network adapters, to separate access to their resources among various PCIe hardware functions, enabling near-native network performance in Hyper-V virtual machines.*"
>
> — Microsoft, [SR-IOV](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-)

It depends on your adapter/driver if SR-IOV is enabled/disabled by default:

## [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-sr-iov)

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*Sriov" = 0; // range 0-1
    "*SriovPreferred" = 0; // range 0-1
```


| SubkeyName            | Value       | EnumDesc |
| --------------------  | ----------- | ---- |
| `*SRIOV`              | 0           | Disabled |
|                       | 1 (Default) | Enabled |
| `*SriovPreferred`     | 0 (Default) | Report RSS/VMQ (per *VmqOrRssPreferrence), do not report SR-IOV |
|                       | 1           | Report SR-IOV capabilities |

### Setup Information

```powershell
; SRIOV Default switch registry keys.

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

[FEC](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/forward-error-correction-fec-mode/) (forwarded error correction) improves link stability, but increases latency. Many high quality optics, direct attach cables, and backplane channels provide a stable link without FEC.

`Auto FEC`: Sets the FEC Mode based on the capabilities of the attached cable.  
`CL108 RS-FEC`: Selects only RS-FEC ability and request capabilities.  
`CL74 FC-FEC/BASE-R`: Selects only BASE-R ability and request capabilities.  
`No FEC`: Disables FEC.

## Registry Values

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "FecMode" = 0; // range 0-3
```

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

### Setup Information

```powershell
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

# Disable Microsoft Client/Multiplexor

Disables the Client for Microsoft Networks (`ms_msclient`) and the Microsoft Network Adapter Multiplexor Protocol (`ms_implat`) bindings on all adapters. This blocks SMB client access and disables NIC teaming.

SMB client I/O is handled by the LANMan Redirector (client-side remote FSD) which translates file I/O into SMB commands, while the server side uses `Srv2.sys`. Disabling `ms_msclient` prevents the redirector from binding to the adapter, so SMB client access is effectively disabled regardless of SMB version. This is broader than the SMBv1 toggle (which only removes the legacy protocol).

# QoS Policy

> "*Policy-based QoS lets Windows identify outgoing network traffic by application, user, computer, IP address, port, or protocol, and then either mark the traffic with a DSCP value for priority handling or limit it with an outbound throttle rate. It's most useful on a managed network where routers, switches, and wireless access points are configured to recognize DSCP markings and give matching traffic higher priority when the network is busy. Without QoS aware network equipment, DSCP marking may have little practical effect beyond the local device, while throttling still works because Windows enforces the send rate locally on outgoing traffic.*"
>
> — Microsoft, [Policy-based QoS](https://learn.microsoft.com/en-us/windows-server/networking/technologies/qos/qos-policy-top)

![](https://github.com/nohuto/win-config/blob/main/network/images/qosvalues.png?raw=true)

- [nexus1000v_qos/qos_6dscp_val.pdf](https://www.cisco.com/c/en/us/td/docs/switches/datacenter/nexus1000/sw/4_0/qos/configuration/guide/nexus1000v_qos/qos_6dscp_val.pdf)

![](https://github.com/nohuto/win-config/blob/main/network/images/qosexplanation.png?raw=true)

## Policy-based QoS (LGPE) Capture

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

## Live Capture

Capturing the network activity after adding the policy using [network monitor](https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/network-monitor-3):
```powershell
+ Versions: IPv4, Internet Protocol, Header Length = 20
- DifferentiatedServicesField: DSCP: 46, ECN: 0 # Works
   DSCP: (101110..) Differentiated services codepoint 46
   ECT:  (......0.) ECN-Capable Transport not set
   CE:   (.......0) ECN-CE not set
  TotalLength: 132 (0x84)
  Identification: 28587 (0x6FAB)
```

# Enable Legacy Switch Compatibility Mode

Probably a setting that controls how the adapter handles link negotiation when it's connected behind certain (usually older) network switches. There's no official documentation on it, but it seems to be disabled by default. Some older switches may have problems with modern auto negotiation behavior, enabling the mode (probably) changes how the NIC negotiates speed/duplex so that it behaves more like older hardware.

This should only be enabled, if needed. The text above is just a personal assumption.

`2` = Enabled  
`1` = Disabled

## Setup Information

```c
; Legacy Switch Compatibility Mode
HKR, Ndi\params\LinkNegotiationProcess,                 ParamDesc,              0, %LinkNegotiationProcess%
HKR, Ndi\params\LinkNegotiationProcess,                 default,                0, "1"
HKR, Ndi\params\LinkNegotiationProcess,                 type,                   0, "enum"
HKR, Ndi\params\LinkNegotiationProcess\enum,            "2",                    0, %Enabled%
HKR, Ndi\params\LinkNegotiationProcess\enum,            "1",                    0, %Disabled%
HKR, PROSetNdi\NdiExt\Params\LinkNegotiationProcess,    ExposeLevel,            0, "3"
```

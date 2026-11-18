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

See [task offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-task-offloading), [network device INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-network-devices), [RSC INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-rsc), [URO](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload), [NVGRE task offload keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-nvgre-task-offload), [connection offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-connection-offloading), [power management keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management), [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic).

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


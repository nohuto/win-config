# Enable Network Offloads

> "*Enable static offloads. For example, enable the UDP Checksums, TCP Checksums, and Send Large Offload (LSO) settings.*"
>
> — Microsoft, [Low-latency packet processing](https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-tuning-nics?tabs=powershell#low-latency-packet-processing)

- [Checksum Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/offloading-checksum-tasks)
- [Large Send Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/offloading-the-segmentation-of-large-tcp-packets)
- [UDP Segmentation Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-segmentation-offload-uso-)
- [Receive Segment Coalescing](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-receive-segment-coalescing)
- [UDP Receive Segment Coalescing Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload)
- [Encapsulated Packet Task Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-nvgre-task-offload)
- [IPsec Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-task-offloading)
- [TCP Connection Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/connection-offload)
- [PM Protocol Offload](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management)

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

See [task offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-task-offloading), [network device INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-network-devices), [RSC INF keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-rsc), [URO](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/udp-rsc-offload), [NVGRE task offload keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-nvgre-task-offload), [connection offload registry values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/using-registry-values-to-enable-and-disable-connection-offloading), [power management keywords](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management). 

Intel drivers read the offload keywords in `OffLdReadRegistryParameters` (`e1i68x64.sys`), RSC ones in `ReceiveSideCoalescing::ReadRegistryParameters` (`e2f68.sys`).

NDIS reads these keywords itself when the adapter starts ([`ndisReadOffloadRegistry`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ndis/-ndisReadOffloadRegistry@@YAHPEAU_NDIS_MINIPORT_BLOCK@@@Z.c)), `*UdpRsc` only on 24H2 and later.

```c
"HKLM\\System\\CurrentControlSet\\Services\\TCPIP\\Parameters";
  "DisableTaskOffload" = 0; // REG_DWORD (bool)

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

  // vendor values, not written by this option, Intel e2f68.sys
  "ForceRscEnabled" = 0; // REG_SZ (bool)
  "RscMode" = 1; // REG_SZ, range 0-2

  // vendor values, not written by this option, Mellanox/NVIDIA mlx5.sys, mlx4eth63.sys, ipoib6x.sys
  "LSOSize" = 64000; // range 1024-64000 - "The maximum number of bytes that the TCP/IP stack can pass to an adapter in a single packet."
  "LSOMinSegment" = 2; // range 2-32 - "The minimum number of segments that a large TCP packet must be divisible by, before the transport can offload it to a NIC for segmentation."
  "LSOTcpOptions" = 1; // bool - "Enables that the miniport driver to segment a large TCP packet whose TCP header contains TCP options."
  "LSOIpOptions" = 1; // bool - "Enables its NIC to segment a large TCP packet whose IP header contains IP options."

  // no driver reads it, only a CIM property name in NetAdapterCim.dll
  "SaOffloadCapacityEnabled" = 0; // REG_SZ (bool)

// not read anymore, no binary of Windows 10 22H2, Windows 11 23H2 or 25H2 contains the name
"HKLM\\System\\CurrentControlSet\\Services\\Ipsec";
  "EnabledOffload" = 1; // REG_DWORD (bool)
```

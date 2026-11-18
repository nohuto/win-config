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


# Enable Jumbo Packets

> "*The Jumbo Frames feature enables or disables Jumbo Packet capability. The standard Ethernet frame size is about 1514 bytes, while Jumbo Packets are larger than this. Jumbo Packets can increase throughput and decrease CPU utilization. However, additional latency may be introduced.*
>
> - *Enable Jumbo Packets only if all devices across the network support them and are configured to use the same frame size.*
> - *Jumbo frames require compatible switch connections that forward Jumbo Frames. Contact your switch vendor for more information.*
> - *When standard-sized Ethernet frames (64 to 1518 bytes) are used, there is no benefit to configuring Jumbo Frames.*
> - *End-to-end hardware must support this capability; otherwise, packets will be dropped.*"
>
> — Intel, [Jumbo Frames](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/jumbo-frames/)

## Registry Values

`*JumboPacket` is the frame size in bytes, the allowed values are up to the vendor, most drivers are fine with `4088` and revert `1514`, some, e.g. Marvell Yukon (`netmyk64.inf`) use `0`/`1`/`2` for 1514/4088/9014, Killer/Atheros list 1514/2048/3072/4096 without 4088.

```c
// Marvell Yukon (netmyk64.inf)

HKR, Ndi\params\*JumboPacket,	ParamDesc,	0, %JumboPacket%
HKR, Ndi\params\*JumboPacket,	Type,		0, "enum"
HKR, Ndi\params\*JumboPacket\enum,	"0",	0, "%Bytes1514%"
HKR, Ndi\params\*JumboPacket\enum,	"1",	0, "%Bytes4088%"
HKR, Ndi\params\*JumboPacket\enum,	"2",	0, "%Bytes9014%"
HKR, Ndi\params\*JumboPacket,	Default,	0, "0"
```

Means, maybe rather read your adapters list under `HKLM\SYSTEM\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX\Ndi\Params\*JumboPacket\enum`.

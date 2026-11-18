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


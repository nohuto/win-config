# Network Buffers

Each driver has its own range (see `Ndi\Params\*ReceiveBuffers` & `*TransmitBuffers` of your adapter).

> *This setting defines the number of Transmit Buffers, which are data segments that enable the adapter to track transmit packets in the system memory. Depending on the size of the packet, each transmit packet requires one or more Transmit Buffers. You might choose to increase the number of Transmit Buffers if you notice a possible problem with transmit performance. Although increasing the number of Transmit Buffers can enhance transmit performance, Transmit Buffers do consume system memory. If transmit performance is not an issue, use the default setting. This default setting varies with the type of adapter.*
>
> — Intel, [Transmit Buffers](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/transmit-buffers/)

> *This setting defines the number of Receive Buffers, which are data segments. They are allocated in the host memory and used to store the received packets. Each received packet requires at least one Receive Buffer, and each buffer uses 2KB of memory. You might choose to increase the number of Receive Buffers if you notice a significant decrease in the performance of received traffic. If receive performance is not an issue, use the default setting appropriate to the adapter.*
>
> — Intel, [Receive Buffers](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/29.3.1/receive-buffers/)

## Setup Information

Intel 1GbE inbox INF (`net1ic64.inf`, `nete1g3e.inf`, ...):

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
```

Mellanox ConnectX inbox INF (`netmlx5.inf`):

```powershell
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


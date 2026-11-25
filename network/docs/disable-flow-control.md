# Disable Flow Control


> "*This feature enables adapters to more effectively regulate traffic. Adapters generate flow control frames when their receive queues reach a pre-defined limit. Generating flow control frames signals the transmitter to slow transmission. Adapters respond to flow control frames by pausing packet transmission for the time specified in the flow control frame.*
>
> *By enabling adapters to adjust packet transmission, flow control helps prevent dropped packets.*"
>
> — Intel, [Flow Control](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/flow-control/)

While KD is enabled, NDIS already returns `0` for `*FlowControl` ([`NdisReadConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ndis/NdisReadConfiguration.c), [`ndisReadRegistry`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ndis/-ndisReadRegistry@@YAXXZ.c)).

| Value | Default | Meaning |
| --- | --- | --- |
| `0` | Server | Tx and Rx disabled |
| `1` | | Tx enabled |
| `2` | | Rx enabled |
| `3` | Client | Rx and Tx enabled |
| `4` | | Auto negotiation (usually disabled) |

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


# Disable Flow Control

A sending station (computer or network switch) may be transmitting data faster than the other end of the link can accept it. Using flow control, the receiving station can signal the sender requesting suspension of transmissions until the receiver catches up.

> - *For adapters to benefit from this feature, link partners must support flow control frames.*
> - *On systems running a Microsoft Windows Server operating system, enabling QoS/priority flow control will disable link level flow control.*
> - *Some devices support Auto Negotiation. Selecting this will cause the device to advertise the value stored in its NVM (usually `Disabled`).*"
>
> — Intel, [Flow Control](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/flow-control/)

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

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


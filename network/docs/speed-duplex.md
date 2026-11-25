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

Keep `Auto Negotiation` unless the link doesn't come up.

> *Note: The settings at the switch must always match the adapter settings. Adapter performance may suffer, or your adapter might not operate correctly if you configure the adapter differently from your switch. The default setting is for auto-negotiation to be enabled. Only change this setting to match your link partner’s speed and duplex setting if you are having trouble connecting.*
>
> — Intel, [Setting Speed and Duplex](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/setting-speed-and-duplex/)

MS defines `0`-`10`, faster/specific speeds are written as the Mbps number (e.g. `2500` = 2.5 Gbps).

| Value | Meaning |
| --- | --- |
| `0` | Auto Negotiation |
| `1` | 10 Mbps Half Duplex |
| `2` | 10 Mbps Full Duplex |
| `3` | 100 Mbps Half Duplex |
| `4` | 100 Mbps Full Duplex |
| `5` | 1.0 Gbps Half Duplex |
| `6` | 1.0 Gbps Full Duplex |
| `7` | 10 Gbps Full Duplex |
| `8` | 20 Gbps Full Duplex |
| `9` | 40 Gbps Full Duplex |
| `10` | 100 Gbps Full Duplex |
| `2500`, `5000`, ... | Speed in Mbps (1000+) |

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*SpeedDuplex" = 0; // range 0-50000
```

Theres also a hidden `LinkNegotiationProcess` value (Intel, shown as "Legacy Switch Compatibility Mode"), which seems to be meant for link problems with older switches, `1` = Disabled, `2` = Enabled.

## Disable Wait for Link

This is for Intel only.

> *This setting determines whether the driver waits for auto-negotiation to be successful before reporting the link state. If this feature is off, the driver does not wait for auto-negotiation. If the feature is on, the driver does wait for auto-negotiation.*
>
> *If this feature is on and the speed is not set to auto-negotiation, the driver will wait for a short time for link to be established before reporting the link state.*
>
> *If the feature is set to Auto Detect, this feature is automatically set to On or Off depending on speed and adapter type when the driver is installed. The setting is:*
> - *Off for copper Intel gigabit adapters with a speed of “Auto”*
> - *On for copper Intel gigabit adapters with a forced speed and duplex*
> - *On for fiber Intel gigabit adapters with a speed of “Auto”*
>
> — Intel, [Wait for Link](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/wait-for-link/)

```powershell
; Wait for Link
HKR, Ndi\Params\WaitAutoNegComplete,            ParamDesc,              0, %WaitAutoNegComplete%
HKR, Ndi\Params\WaitAutoNegComplete,            default,                0, "2"
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "0",                    0, %Off%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "1",                    0, %On%
HKR, Ndi\Params\WaitAutoNegComplete\Enum,       "2",                    0, %AutoDetect%
HKR, Ndi\Params\WaitAutoNegComplete,            type,                   0, "enum"
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

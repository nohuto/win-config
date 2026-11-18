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

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

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


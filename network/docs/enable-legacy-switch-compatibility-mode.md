# Enable Legacy Switch Compatibility Mode

Probably a setting that controls how the adapter handles link negotiation when it's connected behind certain (usually older) network switches. There's no official documentation on it, but it seems to be disabled by default. Some older switches may have problems with modern auto negotiation behavior, enabling the mode (probably) changes how the NIC negotiates speed/duplex so that it behaves more like older hardware.

This should only be enabled, if needed. The text above is just a personal assumption.

`2` = Enabled  
`1` = Disabled

## Setup Information

```c
; Legacy Switch Compatibility Mode
HKR, Ndi\params\LinkNegotiationProcess,                 ParamDesc,              0, %LinkNegotiationProcess%
HKR, Ndi\params\LinkNegotiationProcess,                 default,                0, "1"
HKR, Ndi\params\LinkNegotiationProcess,                 type,                   0, "enum"
HKR, Ndi\params\LinkNegotiationProcess\enum,            "2",                    0, %Enabled%
HKR, Ndi\params\LinkNegotiationProcess\enum,            "1",                    0, %Disabled%
HKR, PROSetNdi\NdiExt\Params\LinkNegotiationProcess,    ExposeLevel,            0, "3"
```

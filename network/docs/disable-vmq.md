# Disable VMQ

> *VMQ is a scaling networking technology for the Hyper-V switch. Without VMQ the networking performance of the Hyper-V switch bound to this network adapter may be reduced.*
>
> — Microsoft, [Disable-NetAdapterVmq](https://learn.microsoft.com/en-us/powershell/module/netadapter/disable-netadaptervmq)

This only matters on a Hyper-V host with a server NIC.

## [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-vmq)

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

```c
// e1i68x64.sys
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*RssOrVmqPreference" = 0; // bool
    "*VMQ" = 0; // bool
    "*VMQLookaheadSplit" = 0; // bool
    "*VMQVlanFiltering" = 1; // bool
    "VMQSupported" = 0; // bool

    // ipoib6x.sys/mlx4eth63.sys
    "MaxNumVmqs" = ?; // found it in the "Mellanox ConnectX based IPoIB Adapter (NDIS 6.4)" driver
```

| Value | Description | Allowed Values | Default | Notes |
| ----  | ---- | ---- | ---- | ---- |
| `*VMQ`| Enable/disable the VMQ feature. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*VMQLookaheadSplit` | Enable/disable splitting RX buffers into lookahead and post-lookahead buffers. | `0` Disabled - `1` Enabled | `1` | Starting with NDIS 6.30 / Windows Server 2012, this keyword is no longer supported. |
| `*VMQVlanFiltering` | Enable/disable filtering packets by VLAN ID in the MAC header. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*RssOrVmqPreference` | Define whether VMQ capabilities should be enabled instead of RSS. | `0` Report RSS capabilities - `1` Report VMQ capabilities | `0`     | - |
### Setup Information

```powershell
; Mellanox
; mlx4eth NT specific
HKR, Ndi\Params\*VMQ,  ParamDesc, 0, "%VMQ%"
HKR, Ndi\Params\*VMQ,  Type,      0, "enum"
HKR, Ndi\Params\*VMQ,  Default,   0, "1"
HKR, Ndi\Params\*VMQ,  Optional,  0, "0"
HKR, Ndi\Params\*VMQ\enum,  "0",  0, "%Disabled%"
HKR, Ndi\Params\*VMQ\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQ, %REG_SZ%, "1"
```


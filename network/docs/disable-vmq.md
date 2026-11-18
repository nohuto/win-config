# Disable VMQ

[VMQ](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/virtual-machine-queue-architecture) is a scaling networking technology for the Hyper-V switch. Without VMQ the networking performance of the Hyper-V switch bound to this network adapter may be reduced. VMQ offloads packet processing to NIC hardware queues, with each queue tied to a specific VM. This increases throughput, spreads work across CPU cores, lowers host CPU use, and scales effectively as more VMs are added on Hyper-V.

It depends on your adapter/driver if VMQ is enabled/disabled by default:

## [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-vmq)

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

```c
// Intel
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*RssOrVmqPreference" = 0; // range 0-1
    "*VMQ" = 0; // range 0-1
    "*VMQLookaheadSplit" = 0; // range 0-1
    "*VMQVlanFiltering" = 1; // range 0-1
    "VMQSupported" = 0; // range 0-1

    "MaxNumVmqs" = ?; // found it in the "Mellanox ConnectX based IPoIB Adapter (NDIS 6.4)" driver
```

| Value | Description | Allowed Values | Default | Notes |
| ----  | ---- | ---- | ---- | ---- |
| `*VMQ`| Enable/disable the VMQ feature. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*VMQLookaheadSplit` | Enable/disable splitting RX buffers into lookahead and post-lookahead buffers. | `0` Disabled - `1` Enabled | `1` | Starting with NDIS 6.30 / Windows Server 2012, this keyword is no longer supported. |
| `*VMQVlanFiltering` | Enable/disable filtering packets by VLAN ID in the MAC header. | `0` Disabled - `1` Enabled | `1` | Enumeration keyword. |
| `*RssOrVmqPreference` | Define whether VMQ capabilities should be enabled instead of RSS. | `0` Report RSS capabilities - `1` Report VMQ capabilities | `0`     | - |
| `*TenGigVmqEnabled` | Enable/disable VMQ on all 10 Gbps adapters. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |
| `*BelowTenGigVmqEnabled` | Enable/disable VMQ on all adapters <10 Gbps. | `0` System default (disabled for Windows Server 2008 R2) - `1` Enabled - `2` Explicitly disabled | - | Miniport that supports VMQ must not read this subkey. |

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


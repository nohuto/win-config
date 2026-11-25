# Disable SR-IOV

> "*Single Root I/O Virtualization (SR-IOV) is an extension to the PCI Express (PCIe) specification that improves network performance in virtualized environments. SR-IOV allows devices, such as network adapters, to separate access to their resources among various PCIe hardware functions, enabling near-native network performance in Hyper-V virtual machines.*"
>
> — Microsoft, [SR-IOV](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-)

This only matters on SR-IOV capable server NICs used by a Hyper-V virtual switch.

## [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-sr-iov)

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*Sriov" = 0; // range 0-1
    "*SriovPreferred" = 0; // range 0-1
```

| SubkeyName            | Value       | EnumDesc |
| --------------------  | ----------- | ---- |
| `*SRIOV`              | 0           | Disabled |
|                       | 1 (Default) | Enabled |
| `*SriovPreferred`     | 0 (Default) | Report RSS/VMQ capabilities (per `*RssOrVmqPreference`), don't report SR-IOV |
|                       | 1           | Report SR-IOV capabilities |

### Setup Information

Mellanox ConnectX inbox INF (`netmlx5.inf` 2.53.23539.0):

```powershell
; SRIOV Default switch registry keys.

HKR, NicSwitches\0, *SwitchId,   %REG_DWORD%, 0
HKR, NicSwitches\0, *SwitchName, %REG_SZ%, "%DefaultSwitchName%"
HKR, NicSwitches\0, *SwitchType,   %REG_DWORD%, 1
HKR, NicSwitches\0, *Flags,   %REG_DWORD%, 0
HKR, NicSwitches\0, *NumVFs,   %REG_DWORD%, 32

HKR, NDI\Params\*Sriov,      paramDesc, , %Sriov%
HKR, NDI\Params\*Sriov,      type,      , "enum"
HKR, NDI\Params\*Sriov,  Default,   0, "1"
HKR, NDI\Params\*Sriov\enum, 0,         , %Disabled%
HKR, NDI\Params\*Sriov\enum, 1,         , %Enabled%
HKR, "", *SRIOV, %REG_SZ%, "1"

HKR, NDI\Params\*VMQ,  ParamDesc, 0, "%VMQ%"
HKR, NDI\Params\*VMQ,  Type,      0, "enum"
HKR, NDI\Params\*VMQ,  Default,   0, "1"
HKR, NDI\Params\*VMQ,  Optional,  0, "0"
HKR, NDI\Params\*VMQ\enum,  "0",  0, "%Disabled%"
HKR, NDI\Params\*VMQ\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQ, %REG_SZ%, "1"

HKR, NDI\Params\*VMQVlanFiltering,  ParamDesc, 0, "%VMQVlanFiltering%"
HKR, NDI\Params\*VMQVlanFiltering,  Type,      0, "enum"
HKR, NDI\Params\*VMQVlanFiltering,  Default,   0, "1"
HKR, NDI\Params\*VMQVlanFiltering,  Optional,  0, "0"
HKR, NDI\Params\*VMQVlanFiltering\enum,  "0",  0, "%Disabled%"
HKR, NDI\Params\*VMQVlanFiltering\enum,  "1",  0, "%Enabled%"
HKR, "", *VMQVlanFiltering, %REG_SZ%, "1"
```


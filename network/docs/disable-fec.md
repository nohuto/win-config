# Disable FEC

[FEC](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/forward-error-correction-fec-mode/) (forward error correction) improves link stability, but increases latency. Many high quality optics, direct attach cables, and backplane channels provide a stable link without FEC.

`Auto FEC`: Sets the FEC Mode based on the capabilities of the attached cable.  
`CL108 RS-FEC`: Selects only RS-FEC ability and request capabilities.  
`CL74 FC-FEC/BASE-R`: Selects only BASE-R ability and request capabilities.  
`No FEC`: Disables FEC.

## Registry Values

See [network/assets/pseudocode/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/pseudocode/intel-nic) for reference.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "FecMode" = 0; // range 0-3
```

```c
RegistryKey<enum HdSplitLocation>::Initialize(
    (struct ADAPTER_CONTEXT *)((char *)*this + 1004),
    *this,
    *((NDIS_HANDLE *)*this + 383),
    (PUCHAR)"FecMode",
    0, // min
    3u, // max
    0, // default
    0,
    1),
```

### Setup Information

```powershell
HKR, Ndi\Params\FecMode,                         ParamDesc,              0, %FecMode%
HKR, Ndi\Params\FecMode,                         default,                0, "0"
HKR, Ndi\Params\FecMode,                         min,                    0, "0"
HKR, Ndi\Params\FecMode,                         max,                    0, "3"
HKR, Ndi\Params\FecMode\Enum,                    "0",                    0, %Auto_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "1",                    0, %RS_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "2",                    0, %FC_FEC%
HKR, Ndi\Params\FecMode\Enum,                    "3",                    0, %NO_FEC%
HKR, Ndi\Params\FecMode,                         type,                   0, "enum"
```


# DMA Remapping

[DMA remapping](https://learn.microsoft.com/en-us/windows-hardware/drivers/pci/enabling-dma-remapping-for-device-drivers) lets PCIe device drivers declare whether they are compatible with IOMMU backed DMA isolation. Windows uses this with [Kernel DMA Protection](https://learn.microsoft.com/en-us/windows/security/hardware-security/kernel-dma-protection-for-thunderbolt) and DMAGuard policy to reduce memory corruption and malicious DMA attack exposure. Devices with DMA remapping compatible drivers can start and perform DMA, incompatible external or exposed PCIe devices can be blocked by DMAGuard policy on systems where Kernel DMA Protection is enabled.

`Opt-In` marks matching existing entries as compatible with DMA remapping. `Opt-Out` marks them as incompatible, which can reduce DMA remapping coverage and can cause external devices to be blocked until sign in or unlock.

`per-device` - recommended and preferred mechanism for Windows 24H2 and later (`RemappingSupported`)
`per-driver` - legacy mechanism for Windows versions up to Windows 11 23H2 (`DmaRemappingCompatible`)

If both are present, the per-device setting takes precedence and `DmaRemappingCompatible` is ignored. The PCI driver documentation still warns that DMA remapping is not supported through this path for graphics drivers. Display drivers use the separate [WDDM IOMMU DMA remapping](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/iommu-dma-remapping) path.

### `RemappingSupported`

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates the device and driver are incompatible with DMA remapping. |
| 1 | Opt-in, indicates the device and driver are fully compatible with DMA remapping. |
| No registry key | Let the system determine the policy. |

### `RemappingFlags`

| Value | Meaning |
|--|--|
| 0 | If **RemappingSupported** is 1, opt in, unconditionally. |
| 1 | If **RemappingSupported** is 1, opt in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt). B. DMA verification is enabled in Driver Verifier |
| No registry key | Same as 0 value. |

### `DmaRemappingCompatible`

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates that your driver is incompatible with DMA remapping. |
| 1 | Opt-in, indicates that your driver is fully compatible with DMA remapping. |
| 2 | Opt-in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt). B. DMA verification is enabled in Driver Verifier |
| 3 | Opt-in. Support was added in Windows 11 and degrades gracefully on Windows 10. |
| No registry key | Let the system determine the policy. |

Example paths:
```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\msisadrv\Parameters : DmaRemappingCompatible
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingFlags
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingSupported
```


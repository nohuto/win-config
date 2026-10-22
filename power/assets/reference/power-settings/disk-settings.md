---
title: Disk settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings
description: Settings in this subgroup control the power management of disk devices.
note: This was modified by Nohuto using PowrProf API
---

# Disk settings overview | Microsoft Learn

Settings in this subgroup control the power management of disk devices.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Disk settings
- **GUID:** 0012ee47-9041-4b5d-9b77-535fba8b1442
- **Windows provisioning path:**`Common\Power\Policy\Settings\Disk`
- **PowerCfg alias:**`SUB_DISK`
- **Hidden setting:** Yes

## Maximum Power Level

- **GUID:** 51dea550-bb38-4bc4-991b-eacf37be5ec8
- **PowerCfg alias:**`DISKMAXPOWER`
- **Description:** Specifies the the power consumption level storage devices should not exceed.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Secondary NVMe Idle Timeout

- **GUID:** d3d55efd-c1ff-424e-9dc3-441be7833010
- **PowerCfg alias:**`N/A`
- **Description:** Specifies the amount of time the NVMe device must be in the primary non-operational power state before transitioning to the secondary non-operational power state.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 60,000 |
| Increment | 1 |
| Units | milliseconds |

## Primary NVMe Idle Timeout

- **GUID:** d639518a-e56d-4345-8af2-b9f32fb26109
- **PowerCfg alias:**`NVMEPRIMARYIDLETIMEOUT`
- **Description:** Specifies the amount of time the NVMe device must be idle before transitioning to the primary non-operational power state.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 60,000 |
| Increment | 1 |
| Units | milliseconds |

## Secondary NVMe Power State Transition Latency Tolerance

- **GUID:** dbc9e238-6de9-49e3-92cd-8c2b4946b472
- **PowerCfg alias:**`N/A`
- **Description:** After the NVMe device has been in the primary non-operational power state for a certain amount of time, transition to the lowest non-operational power state whose ENLAT+EXLAT value is less than or equal to the value specified by this setting.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 60,000 |
| Increment | 1 |
| Units | milliseconds |

## NVMe NOPPME

- **GUID:** fc7372b6-ab2d-43ee-8797-15e9841f2cca
- **PowerCfg alias:**`DISKNVMENOPPME`
- **Description:** Enable or Disable NVMe Non-Operational Power State Permissive Mode.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |

## Primary NVMe Power State Transition Latency Tolerance

- **GUID:** fc95af4d-40e7-4b6d-835a-56d131dbc80e
- **PowerCfg alias:**`N/A`
- **Description:** When the NVMe device has been idle for a certain amount of time, transition to the lowest non-operational power state whose ENLAT+EXLAT value is less than or equal to the value specified by this setting.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 60,000 |
| Increment | 1 |
| Units | milliseconds |


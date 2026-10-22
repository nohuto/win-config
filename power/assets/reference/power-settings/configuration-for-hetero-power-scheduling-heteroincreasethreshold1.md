---
title: HeteroIncreaseThreshold1 | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold1
description: HeteroIncreaseThreshold1 specifies the threshold value to cross above, which is required to unpark the Nth class 2 core. There is a separate value for each core index. The threshold is relative to class 1 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 2 cores, the 4th value is used for all remaining cores of the same class.
note: This was modified by Nohuto using PowrProf API
---

# HeteroIncreaseThreshold1 | Microsoft Learn

`HeteroIncreaseThreshold1` specifies the threshold value to cross above, which is required to unpark the Nth class 2 core. There is a separate value for each core index. The threshold is relative to class 1 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 2 cores, the 4th value is used for all remaining cores of the same class.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Definitions\Processor\HeteroIncreaseThreshold1`
- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\HeteroIncreaseThreshold1`
- **PowerCfg:**`HETEROINCREASETHRESHOLD1`
- **GUID:** b000397d-9b0b-483d-98c9-692a6060cfc0
- **Description:** Specifies the performance level increase threshold at which the Processor Power Efficiency Class 2 processor count is increased (in units of Processor Power Efficiency Class 1 processor performance).
- **Hidden setting:** Yes

## Values

`HeteroIncreaseThreshold1` is a four-byte unsigned integer where each byte represents a threshold in percentage. See [HeteroIncreaseThreshold](configuration-for-hetero-power-scheduling-heteroincreasethreshold.md) for configuring the thresholds.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 255 | Processor performance level threshold change for Processor Power Efficiency Class 2 processor count change | 1515870810 | Processor performance level threshold change for Processor Power Efficiency Class 2 processor count change relative to Processor Power Efficiency Class 1 performance level. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

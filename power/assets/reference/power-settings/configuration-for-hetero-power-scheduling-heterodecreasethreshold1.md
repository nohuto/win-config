---
title: HeteroDecreaseThreshold1 | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold1
description: HeteroDecreaseThreshold1 specifies the threshold to cross below, which is required to park the Nth class 2 core. There is a separate value for each core index. The threshold is relative to efficiency class 1 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 2 cores, the 4th value is used for all remaining cores of the same class.
note: This was modified by Nohuto using PowrProf API
---

# HeteroDecreaseThreshold1 | Microsoft Learn

`HeteroDecreaseThreshold1` specifies the threshold to cross below, which is required to park the Nth class 2 core. There is a separate value for each core index. The threshold is relative to efficiency class 1 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 2 cores, the 4th value is used for all remaining cores of the same class.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Definitions\Processor\HeteroDecreaseThreshold1`
- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroDecreaseThreshold1`
- **PowerCfg:**`HETERODECREASETHRESHOLD1`
- **GUID:** f8861c27-95e7-475c-865b-13c0cb3f9d6c
- **Description:** Specifies the performance level decrease threshold at which the Processor Power Efficiency Class 2 processor count is decreased (in units of Processor Power Efficiency Class 1 processor performance).
- **Hidden setting:** Yes

## Values

`HeteroDecreaseThreshold1` is a four-byte unsigned integer where each byte represents a threshold in percentage. See [HeteroIncreaseThreshold](configuration-for-hetero-power-scheduling-heteroincreasethreshold.md) for configuring the thresholds.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 255 | Processor performance level threshold change for Processor Power Efficiency Class 2 processor count change | 842150450 | Processor performance level threshold change for Processor Power Efficiency Class 2 processor count change relative to Processor Power Efficiency Class 1 performance level. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

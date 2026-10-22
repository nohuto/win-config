---
title: HeteroDecreaseThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold
description: HeteroDecreaseThreshold specifies the threshold to cross below, which is required to park the Nth efficiency class 1 core. There is a separate value for each core index. The threshold is relative to efficiency class 0 performance.
note: This was modified by Nohuto using PowrProf API
---

# HeteroDecreaseThreshold | Microsoft Learn

`HeteroDecreaseThreshold` specifies the threshold to cross below, which is required to park the Nth efficiency class 1 core. There is a separate value for each core index. The threshold is relative to efficiency class 0 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 1 cores, the 4th value is used for all remaining cores of the same class.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Definitions\Processor\HeteroDecreaseThreshold`
- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroDecreaseThreshold`
- **PowerCfg:**`HETERODECREASETHRESHOLD`
- **GUID:** f8861c27-95e7-475c-865b-13c0cb3f9d6b
- **Description:** Specifies the performance level decrease threshold at which the Processor Power Efficiency Class 1 processor count is decreased (in units of Processor Power Efficiency Class 0 processor performance).
- **Hidden setting:** Yes

## Values

`HeteroDecreaseThreshold` is a four-byte unsigned integer where each byte represents a threshold in percentage. See [HeteroIncreaseThreshold](configuration-for-hetero-power-scheduling-heteroincreasethreshold.md) for configuring the thresholds.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 254 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change | 421075225 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change relative to Processor Power Efficiency Class 0 performance level. |
| 255 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change | 842150450 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change relative to Processor Power Efficiency Class 0 performance level. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

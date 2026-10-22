---
title: PerfDecreasePolicy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perfdecreasepolicy
description: PerfDecreasePolicy specifies the algorithm used to select a new performance state when the ideal performance state is lower than the current performance state.
note: This was modified by Nohuto using PowrProf API
---

# PerfDecreasePolicy | Microsoft Learn

`PerfDecreasePolicy` specifies the algorithm used to select a new performance state when the ideal performance state is lower than the current performance state. The ideal state is such that the utilization would be between the decrease and increase thresholds.

Not applicable to [Enabled](options-for-perf-state-engine-perfautonomousmode.md) autonomous performance states systems.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\PerfDecreasePolicy`, `Common\Power\Policy\Settings\Processor\PerfDecreasePolicy1`
- **PowerCfg:**`PERFDECPOL`, `PERFDECPOL1`
- **GUID:** 40fbefc7-2e9d-4d25-a185-0cfd8574bac6, 40fbefc7-2e9d-4d25-a185-0cfd8574bac7
- **Description:** Specify the algorithm used to select a new performance state when the ideal performance state is lower than the current performance state. / Specify the algorithm used to select a new performance state when the ideal performance state is lower than the current performance state for Processor Power Efficiency Class 1.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Ideal | 0 | Select the ideal processor performance state. |
| 001 | Single | 1 | Select the processor performance state one closer to ideal than the current processor performance state. |
| 002 | Rocket | 2 | Select the lowest speed/power processor performance state. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

---
title: PerfDecreaseThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perfdecreasethreshold
description: PerfDecreaseThreshold specifies the percentage of processor utilization, in terms of the maximum processor utilization, that is required to reduce the processor to a lower performance state.
note: This was modified by Nohuto using PowrProf API
---

# PerfDecreaseThreshold | Microsoft Learn

`PerfDecreaseThreshold` specifies the percentage of processor utilization, in terms of the maximum processor utilization, that is required to reduce the processor to a lower performance state.

Not applicable to [Enabled](options-for-perf-state-engine-perfautonomousmode.md) autonomous performance states systems.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\PerfDecreaseThreshold`, `Common\Power\Policy\Settings\Processor\PerfDecreaseThreshold1`
- **PowerCfg:**`PERFDECTHRESHOLD`, `PERFDECTHRESHOLD1`
- **GUID:** 12a0ab44-fe28-4fa9-b3bd-4b64f44960a6, 12a0ab44-fe28-4fa9-b3bd-4b64f44960a7
- **Description:** Specify the lower busy threshold that must be met before decreasing the processor's performance state (in percentage). / Specify the lower busy threshold that must be met before decreasing the processor's performance state (in percentage) for Processor Power Efficiency Class 1.
- **Hidden setting:** Yes

## Values

The value denotes percentage (%).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | percent |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

---
title: HeteroClass1InitialPerf | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heteroclass1initialperf
description: HeteroClass1InitialPerf specifies the initial performance percentage of the efficiency class 1 core when this core is unparked.
note: This was modified by Nohuto using PowrProf API
---

# HeteroClass1InitialPerf | Microsoft Learn

`HeteroClass1InitialPerf` specifies the initial performance percentage of the efficiency class 1 core when this core is unparked.

Not applicable to [Enabled](options-for-perf-state-engine-perfautonomousmode.md) autonomous performance states systems.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroClass1InitialPerf`
- **PowerCfg:**`HETEROCLASS1INITIALPERF`
- **GUID:** 1facfc65-a930-4bc5-9f38-504ec097bbc0
- **Description:** Initial performance state for Processor Power Efficiency Class 1 when woken from a parked state.
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

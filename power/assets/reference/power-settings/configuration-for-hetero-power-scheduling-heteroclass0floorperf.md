---
title: HeteroClass0FloorPerf | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heteroclass0floorperf
description: HeteroClass0FloorPerf specifies the performance level floor, in percentage, to use for efficiency class 0 processors if there is at least one unparked efficiency class 1 processor.
note: This was modified by Nohuto using PowrProf API
---

# HeteroClass0FloorPerf | Microsoft Learn

`HeteroClass0FloorPerf` specifies the performance level floor, in percentage, to use for efficiency class 0 processors if there is at least one unparked efficiency class 1 processor.

Not applicable with [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service).

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroClass0FloorPerf`
- **PowerCfg:**`HETEROCLASS0FLOORPERF`
- **GUID:** fddc842b-8364-4edc-94cf-c17f60de1c80
- **Description:** Performance state floor for Processor Power Efficiency Class 0 when Processor Power Efficiency Class 1 is woken from a parked state.
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

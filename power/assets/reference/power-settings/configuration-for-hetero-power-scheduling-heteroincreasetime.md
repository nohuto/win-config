---
title: HeteroIncreaseTime | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heteroincreasetime
description: HeteroIncreaseTime specifies the minimum amount of time that must elapse before additional efficiency class 1 logical processors can be transitioned form the parked state to the unparked state.
note: This was modified by Nohuto using PowrProf API
---

# HeteroIncreaseTime | Microsoft Learn

`HeteroIncreaseTime` specifies the minimum amount of time that must elapse before additional efficiency class 1 logical processors can be transitioned form the parked state to the unparked state. The time is specified in processor performance time check intervals.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroIncreaseTime`
- **PowerCfg:**`HETEROINCREASETIME`
- **GUID:** 4009efa7-e72d-4cba-9edf-91084ea8cbc3
- **Description:** Specify the minimum number of perf check intervals since the last performance state change before the performance state may be increased for Processor Power Efficiency Class 1.
- **Hidden setting:** Yes

## Values

The value denotes time check intervals.

| Property | Value |
| --- | --- |
| Minimum value | 1 |
| Maximum value | 100 |
| Increment | 1 |
| Units | Time check intervals |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

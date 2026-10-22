---
title: HeteroDecreaseTime | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heterodecreasetime
description: HeteroDecreaseTime specifies the minimum amount of time that must elapse before additional efficiency class 1 logical processors can be transitioned from the unparked state to the parked state. The time is specified in performance time check intervals.
note: This was modified by Nohuto using PowrProf API
---

# HeteroDecreaseTime | Microsoft Learn

`HeteroDecreaseTime` specifies the minimum amount of time that must elapse before additional efficiency class 1 logical processors can be transitioned from the unparked state to the parked state. The time is specified in performance time check intervals.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\HeteroDecreaseTime`
- **PowerCfg:**`HETERODECREASETIME`
- **GUID:** 7f2492b6-60b1-45e5-ae55-773f8cd5caec
- **Description:** Specify the minimum number of perf check intervals since the last performance state change before the performance state may be decreased for Processor Power Efficiency Class 1.
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

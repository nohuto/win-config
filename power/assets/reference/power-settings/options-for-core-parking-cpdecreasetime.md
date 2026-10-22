---
title: CPDecreaseTime | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpdecreasetime
description: CPDecreaseTime specifies the minimum amount of time that must elapse before additional logical processors can be transitioned from the unparked state to the parked state.
note: This was modified by Nohuto using PowrProf API
---

# CPDecreaseTime | Microsoft Learn

`CPDecreaseTime` specifies the minimum amount of time that must elapse before additional logical processors can be transitioned from the unparked state to the parked state. The time is specified in units of the number of processor performance time check intervals. The eligible processors are based on the HeteroPolicy.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPDecreaseTime`
- **PowerCfg:**`CPDECREASETIME`
- **GUID:** dfd10d17-d5eb-45dd-877a-9a34ddd15c82
- **Description:** Specify the minimum number of perf check intervals that must elapse before more cores/packages can be parked.
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

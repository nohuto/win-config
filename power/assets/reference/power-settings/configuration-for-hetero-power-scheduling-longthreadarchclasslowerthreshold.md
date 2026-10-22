---
title: LongThreadArchClassLowerThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold
description: LongThreadArchClassLowerThreshold specify the lower limit of processor architecture class for long running threads on systems with processors with heterogeneous architecture. See  [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Long running threads cannot be run on cores whose normalized architectural class is lower than this limit.
note: This was modified by Nohuto using PowrProf API
---

# LongThreadArchClassLowerThreshold | Microsoft Learn

`LongThreadArchClassLowerThreshold` specify the lower limit of processor architecture class for long running threads on systems with processors with heterogeneous architecture. See [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Long running threads cannot be run on cores whose normalized architectural class is lower than this limit.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\LongThreadArchClassLowerThreshold`
- **PowerCfg:**`LongThreadArchClassLowerThreshold`
- **GUID:** 43f278bc-0f8a-46d0-8b31-9a23e615d713
- **Description:** Specify the lower limit of processor architecture class for long running threads
- **Hidden setting:** Yes

## Values

The value denotes processor architecture class.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 255 |
| Increment | 1 |
| Units | Processor Architecture Class |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

---
title: ShortThreadArchClassLowerThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold
description: ShortThreadArchClassLowerThreshold specify the lower limit of processor architecture class for short running threads on systems with processors with heterogeneous architecture.See [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Short running threads cannot be run on cores whose normalized architectural class is lower than this limit.
note: This was modified by Nohuto using PowrProf API
---

# ShortThreadArchClassLowerThreshold | Microsoft Learn

`ShortThreadArchClassLowerThreshold` specify the lower limit of processor architecture class for short running threads on systems with processors with heterogeneous architecture.See [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Short running threads cannot be run on cores whose normalized architectural class is lower than this limit.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\ShortThreadArchClassLowerThreshold`
- **PowerCfg:**`ShortThreadArchClassLowerThreshold`
- **GUID:** 53824d46-87bd-4739-aa1b-aa793fac36d6
- **Description:** Specify the lower limit of processor architecture class for short running threads
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

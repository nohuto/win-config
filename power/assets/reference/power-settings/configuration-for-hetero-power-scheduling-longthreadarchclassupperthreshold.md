---
title: LongThreadArchClassUpperThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold
description: LongThreadArchClassUpperThreshold specify the upper limit of processor architecture class for long running threads on systems with processors with heterogeneous architecture. See  [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Long running threads cannot be run on cores whose normalized architectural class is higher than this limit.
note: This was modified by Nohuto using PowrProf API
---

# LongThreadArchClassUpperThreshold | Microsoft Learn

`LongThreadArchClassUpperThreshold` specify the upper limit of processor architecture class for long running threads on systems with processors with heterogeneous architecture. See [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running. Long running threads cannot be run on cores whose normalized architectural class is higher than this limit.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\LongThreadArchClassUpperThreshold`
- **PowerCfg:**`LongThreadArchClassUpperThreshold`
- **GUID:** bf903d33-9d24-49d3-a468-e65e0325046a
- **Description:** Specify the upper limit of processor architecture class for long running threads
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

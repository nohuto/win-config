---
title: ShortSchedulingPolicy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-shortschedulingpolicy
description: ShortSchedulingPolicy specifies the preference (or constraint) in processor scheduling for short running threads on systems with processors with heterogeneous architecture.
note: This was modified by Nohuto using PowrProf API
---

# ShortSchedulingPolicy | Microsoft Learn

`ShortSchedulingPolicy` specifies the preference (or constraint) in processor scheduling for short running threads on systems with processors with heterogeneous architecture. See [ShortThreadRuntimeThreshold](configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) for configuring the threshold for determination of short versus long running.

Value of Automatic lets the OS determines the policy based on system configuration and QoS type.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\ShortSchedulingPolicy`
- **PowerCfg:**`SHORTSCHEDPOLICY`
- **GUID:** bae08b81-2d5e-4688-ad6a-13243356654b
- **Description:** Specify what thread scheduling policy to use for short running threads on heterogeneous systems.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | All processors | 0 | Schedule to any available processor. |
| 001 | Performant processors | 1 | Schedule exclusively to more performant processors. |
| 002 | Prefer performant processors | 2 | Schedule to more performant processors when possible. |
| 003 | Efficient processors | 3 | Schedule exclusively to more efficient processors. |
| 004 | Prefer efficient processors | 4 | Schedule to more efficient processors when possible. |
| 005 | Automatic | 5 | Let the system choose an appropriate policy. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

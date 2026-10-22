---
title: ShortThreadRuntimeThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-shortthreadruntimethreshold
description: ShortThreadRuntimeThreshold specifies the runtime threshold for distinguishing a short versus long running thread.
note: This was modified by Nohuto using PowrProf API
---

# ShortThreadRuntimeThreshold | Microsoft Learn

`ShortThreadRuntimeThreshold` specifies the runtime threshold for distinguishing a short versus long running thread. Threads with an expected runtime less than this value are considered short running and have scheduling configured by [ShortSchedulingPolicy](configuration-for-hetero-power-scheduling-shortschedulingpolicy.md) on systems with processors with heterogeneous architecture.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Processor\ShortThreadRuntimeThreshold`
- **PowerCfg:**`SHORTTHREADRUNTIMETHRESHOLD`
- **GUID:** d92998c2-6a48-49ca-85d4-8cceec294570
- **Description:** Specifies the global threshold that designates which threads have a short versus a long runtime.
- **Hidden setting:** Yes

## Values

The value denotes microseconds (us).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100,000 |
| Increment | 1 |
| Units | Microseconds |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

---
title: IdlePromoteThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-idlepromotethreshold
description: IdlePromoteThreshold specifies the amount of processor idleness that is required before a processor is set to the next lower power processor idle state. When the processor idleness goes above the value of this setting, the processor transitions to the next higher indexed idle state.
note: This was modified by Nohuto using PowrProf API
---

# IdlePromoteThreshold | Microsoft Learn

`IdlePromoteThreshold` specifies the amount of processor idleness that is required before a processor is set to the next lower power processor idle state. When the processor idleness goes above the value of this setting, the processor transitions to the next higher indexed idle state.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\IdlePromoteThreshold`
- **PowerCfg:**`IDLEPROMOTE`
- **GUID:** 7b224883-b3cc-4d79-819f-8374152cbe7c
- **Description:** Specify the lower busy threshold that must be met before promoting the processor to a deeper idle state (in percentage).
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
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

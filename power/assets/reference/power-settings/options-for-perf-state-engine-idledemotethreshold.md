---
title: IdleDemoteThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-idledemotethreshold
description: IdleDemoteThreshold specifies the amount of processor idleness that is required before a processor is set to the next higher power processor idle state. When the processor idleness goes below the value of this setting, the processor transitions to the next lower indexed idle state.
note: This was modified by Nohuto using PowrProf API
---

# IdleDemoteThreshold | Microsoft Learn

`IdleDemoteThreshold` specifies the amount of processor idleness that is required before a processor is set to the next higher power processor idle state. When the processor idleness goes below the value of this setting, the processor transitions to the next lower indexed idle state.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\IdleDemoteThreshold`
- **PowerCfg:**`IDLEDEMOTE`
- **GUID:** 4b92d758-5a24-4851-a470-815d78aee119
- **Description:** Specify the upper busy threshold that must be met before demoting the processor to a lighter idle state (in percentage).
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

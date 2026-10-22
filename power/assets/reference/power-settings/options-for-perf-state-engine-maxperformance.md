---
title: MaxPerformance | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-maxperformance
description: MaxPerformance specifies the maximum processor performance state, which is specified as a percentage of maximum processor performance.
note: This was modified by Nohuto using PowrProf API
---

# MaxPerformance | Microsoft Learn

`MaxPerformance` specifies the maximum processor performance state, which is specified as a percentage of maximum processor performance.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\MaxPerformance`, `Common\Power\Policy\Settings\Processor\MaxPerformance1`
- **PowerCfg:**`PROCTHROTTLEMAX`, `PROCTHROTTLEMAX1`
- **GUID:** bc5038f7-23e0-4960-96da-33abaf5935ec, bc5038f7-23e0-4960-96da-33abaf5935ed
- **Description:** Specify the maximum performance state of your processor (in percentage). / Specify the maximum performance state of your Processor Power Efficiency Class 1 processor (in percentage).
- **Hidden setting:** No

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
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

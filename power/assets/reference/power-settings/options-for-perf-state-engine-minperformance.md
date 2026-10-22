---
title: MinPerformance | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-minperformance
description: MinPerformance specifies the minimum processor performance state, which is specified as a percentage of maximum processor performance.
note: This was modified by Nohuto using PowrProf API
---

# MinPerformance | Microsoft Learn

`MinPerformance` specifies the minimum processor performance state, which is specified as a percentage of maximum processor performance.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\MinPerformance`, `Common\Power\Policy\Settings\Processor\MinPerformance1`
- **PowerCfg:**`PROCTHROTTLEMIN`, `PROCTHROTTLEMIN1`
- **GUID:** 893dee8e-2bef-41e0-89c6-b55d0929964c, 893dee8e-2bef-41e0-89c6-b55d0929964d
- **Description:** Specify the minimum performance state of your processor (in percentage). / Specify the minimum performance state of your Processor Power Efficiency Class 1 processor (in percentage).
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

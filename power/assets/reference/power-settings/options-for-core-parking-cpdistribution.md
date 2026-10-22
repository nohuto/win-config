---
title: CPDistribution | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpdistribution
description: CPDistribution specifies the utilization, in percentage, to use in the concurrency distribution to select the number of logical processors to distribute utility to.
note: This was modified by Nohuto using PowrProf API
---

# CPDistribution | Microsoft Learn

`CPDistribution` specifies the utilization, in percentage, to use in the concurrency distribution to select the number of logical processors to distribute utility to. This may be fewer, but never greater, than the number of logical processors that are selected to be unparked. This affects performance selection.

Not applicable to [Enabled](options-for-perf-state-engine-perfautonomousmode.md) autonomous performance states systems.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPDistribution`
- **PowerCfg:**`CPDISTRIBUTION`
- **GUID:** 4bdaf4e9-d103-46d7-a5f0-6280121616ef
- **Description:** Specify the percentage utilization used to calculate the distribution concurrency (in percentage).
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
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

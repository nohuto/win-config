---
title: CPMinCores | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpmincores
description: CPMinCores specifies the minimum percentage of logical processors (in terms of all logical processors that are enabled on the system within each NUMA node) that can be placed in the un-parked state at any given time.
note: This was modified by Nohuto using PowrProf API
---

# CPMinCores | Microsoft Learn

`CPMinCores` specifies the minimum percentage of logical processors (in terms of all logical processors that are enabled on the system within each NUMA node) that can be placed in the un-parked state at any given time.

For example, in a NUMA node with 16 logical processors, configuring the value of this setting to 25% ensures that at least 4 logical processors are always in the un-parked state. The Core Parking algorithm is disabled if the value of this setting is 100%.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPMinCores`, `Common\Power\Policy\Settings\Processor\CPMinCores1`
- **PowerCfg:**`CPMINCORES`, `CPMINCORES1`

- **GUID:** 0cc5b647-c1df-4637-891a-dec35c318583, 0cc5b647-c1df-4637-891a-dec35c318584
- **Description:** Specify the minimum number of unparked cores/packages allowed (in percentage). / Specify the minimum number of unparked cores/packages allowed for Processor Power Efficiency Class 1 (in percentage).
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

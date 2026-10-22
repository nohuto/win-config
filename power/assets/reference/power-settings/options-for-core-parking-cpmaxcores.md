---
title: CPMaxCores | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpmaxcores
description: CPMaxCores specifies the maximum percentage of logical processors (in terms of logical processors within each NUMA node) that can be in the un-parked state at any given time.
note: This was modified by Nohuto using PowrProf API
---

# CPMaxCores | Microsoft Learn

`CPMaxCores` specifies the maximum percentage of logical processors (in terms of logical processors within each NUMA node) that can be in the un-parked state at any given time.

For example, in a NUMA node with 16 logical processors, configuring the value of this setting to 50% ensures that no more than 8 logical processors are ever in the un-parked state at the same time.

If the value of `CPMaxCores` is less than the value of [CPMinCores](options-for-core-parking-cpmincores.md), it will be rounded up internally to the latter setting's value.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPMaxCores`, `Common\Power\Policy\Settings\Processor\CPMaxCores1`
- **PowerCfg:**`CPMAXCORES`, `CPMAXCORES1`
- **GUID:** ea062031-0e34-4ff1-9b6d-eb1059334028, ea062031-0e34-4ff1-9b6d-eb1059334029
- **Description:** Specify the maximum number of unparked cores/packages allowed (in percentage). / Specify the maximum number of unparked cores/packages allowed for Processor Power Efficiency Class 1 (in percentage).
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

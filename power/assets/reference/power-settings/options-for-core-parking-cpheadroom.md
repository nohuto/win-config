---
title: CPHeadroom | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpheadroom
description: CPHeadroom specifies the value of utilization that would cause the core parking engine to unpark an additional logical processor if the least utilized processor out of the unparked set of processors had more utilization.
note: This was modified by Nohuto using PowrProf API
---

# CPHeadroom | Microsoft Learn

`CPHeadroom` specifies the value of utilization that would cause the core parking engine to unpark an additional logical processor if the least utilized processor out of the unparked set of processors had more utilization. This enables increases in concurrency to be detected. The eligible processors are based on the HeteroPolicy.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPHeadroom`
- **PowerCfg:**`CPHEADROOM`
- **GUID:** f735a673-2066-4f80-a0c5-ddee0cf1bf5d
- **Description:** Specify the busy threshold that must be met by all cores in a concurrency set to unpark an extra core.
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

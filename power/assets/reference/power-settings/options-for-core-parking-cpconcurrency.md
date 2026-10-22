---
title: CPConcurrency | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-core-parking-cpconcurrency
description: CPConcurrency specifies the threshold for determining concurrency of the node.
note: This was modified by Nohuto using PowrProf API
---

# CPConcurrency | Microsoft Learn

`CPConcurrency` specifies the threshold for determining concurrency of the node. It is the percentage of time that is spent at N processors or fewer for the concurrency to be counted as N. Processors are eligible to be parked based on the determined concurrency and on the HeteroPolicy.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\CPConcurrency`
- **PowerCfg:**`CPCONCURRENCY`
- **GUID:** 2430ab6f-a520-44a2-9601-f7f23b5134b1
- **Description:** Specify the busy threshold that must be met when calculating the concurrency of a node.
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

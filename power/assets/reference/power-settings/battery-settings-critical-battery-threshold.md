---
title: Critical battery threshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings-critical-battery-threshold
description: Specifies a percentage of capacity when the critical battery action is taken.
note: This was modified by Nohuto using PowrProf API
---

# Critical battery threshold | Microsoft Learn

Specifies a percentage of capacity that contributes to deciding when the critical battery action is taken.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Battery\CriticalBatteryLevel`
- **PowerCfg:**`BATLEVELCRIT`
- **GUID:** 9a66d8d7-4ff7-4ef9-b5a2-5a326ca2a469
- **Description:** Percentage of battery capacity remaining that initiates the critical battery action.
- **Hidden setting:** Yes

## Values

The value denotes the percentage (%).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | percent |

## Applies to

Available in Windows Vista and later versions of Windows.

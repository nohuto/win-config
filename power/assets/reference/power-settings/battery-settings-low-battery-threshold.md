---
title: Low battery threshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings-low-battery-threshold
description: Specifies a percentage of capacity when the low battery action is taken and the low battery warning, if enabled, appears.
note: This was modified by Nohuto using PowrProf API
---

# Low battery threshold | Microsoft Learn

Specifies a percentage of capacity when the low battery action is taken and the [low battery warning](battery-settings-low-battery-warning.md), if enabled, appears.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Battery\LowBatteryLevel`
- **PowerCfg:**`BATLEVELLOW`
- **GUID:** 8183ba9a-e910-48da-8769-14ae6dc1170a
- **Description:** Percentage of battery capacity remaining that initiates the low battery action.
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

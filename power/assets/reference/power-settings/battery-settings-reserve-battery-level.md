---
title: Reserve battery level | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings-reserve-battery-level
description: Specifies a percentage of capacity when the reserve battery warning is shown to the user.
note: This was modified by Nohuto using PowrProf API
---

# Reserve battery level | Microsoft Learn

Specifies a percentage of capacity when the reserve battery warning is shown to the user.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Battery\ReserveBatteryLevel`
- **PowerCfg:**`BATLEVELRESERVE           `
- **GUID:** f3c5027d-cd16-4930-aa6b-90db844a8f00
- **Description:** Percent battery power remaining when we enter Reserve power mode.
- **Hidden setting:** Yes

## Values

The value denotes the percentage (%).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Applies to

Available in Windows 7 and later versions of Windows.

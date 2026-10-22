---
title: Energy Saver settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/energy-saver-settings
description: Settings in this subgroup control the battery threshold and brightness when Energy Saver is turned on.
note: This was modified by Nohuto using PowrProf API
---

# Energy Saver settings overview | Microsoft Learn

Settings in this subgroup control the battery threshold and brightness when Energy Saver is turned on.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Energy Saver settings
- **GUID:** de830923-a562-41af-a086-e3a2c6bad2da
- **Windows provisioning path:**`Common\Power\Policy\Settings\EnergySaver`
- **PowerCfg alias:**`SUB_ENERGYSAVER`
- **Hidden setting:** Yes

## Display brightness weight

- **GUID:** 13d09884-f74e-474a-a852-b6bde8ad03a8
- **PowerCfg alias:**`ESBRIGHTNESS`
- **Description:** Specifies the percentage value to scale brightness when Energy Saver is on.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Energy Saver Policy

- **GUID:** 5c5bb349-ad29-4ee2-9d0b-2b25270f7a81
- **PowerCfg alias:**`ESPOLICY`
- **Description:** Specifies the policy to control Energy Saver.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | User | 0 | Engage Energy Saver based on user settings. |
| 001 | Aggressive | 1 | Allow Windows to engage Energy Saver aggressively. |

## Charge level

- **GUID:** e69653ca-cf7f-4f05-aa73-cb833fa90ad4
- **PowerCfg alias:**`ESBATTTHRESHOLD`
- **Description:** Specifies battery charge level at which Energy Saver is turned on.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | Percent battery charge |


---
title: Display settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/display-settings
description: Settings in this subgroup control the power management of the display.
note: This was modified by Nohuto using PowrProf API
---

# Display settings overview | Microsoft Learn

Settings in this subgroup control the power management of the display.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Display settings
- **GUID:** 7516b95f-f776-4464-8c53-06167f40cc99
- **Windows provisioning path:**`Common\Power\Policy\Settings\Display`
- **PowerCfg alias:**`SUB_VIDEO`
- **Hidden setting:** Yes

## Console lock display off timeout

- **GUID:** 8ec4b3a5-6868-48c2-be75-4f3044be88a7
- **PowerCfg alias:**`VIDEOCONLOCK`
- **Description:** Specifies console lock display off timeout

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Enable adaptive brightness

- **GUID:** fbd9aa66-9553-4097-ba44-ed6e9d65eab8
- **PowerCfg alias:**`ADAPTBRIGHT`
- **Description:** Monitors ambient light sensors to detect changes in ambient light and adjust the display brightness.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |


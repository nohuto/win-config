---
title: Low battery action | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings-low-battery-action
description: Specifies the action to take when the low batter level is reached.
note: This was modified by Nohuto using PowrProf API
---

# Low battery action | Microsoft Learn

Specifies the action to take when the low batter level is reached.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Battery\LowAction`
- **PowerCfg:**`BATACTIONLOW`
- **GUID:** d8742dcb-3e6a-4b3c-b3fe-374623cdcf06
- **Description:** Specify the action that your computer takes when battery capacity reaches the low level.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Do nothing | 0 | Do nothing |
| 001 | Sleep | 2 | Sleep |
| 002 | Hibernate | 3 | Hibernate |
| 003 | Shut down | 6 | Shut down |

## Applies to

Available in Windows Vista and later versions of Windows.

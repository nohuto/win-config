---
title: Critical battery action | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings-critical-battery-action
description: Specifies the action to take when the critical batter level is reached.
note: This was modified by Nohuto using PowrProf API
---

# Critical battery action | Microsoft Learn

Specifies the action to take when the critical battery level is reached.

## Aliases and setting visibility

- **PowerCfg:**`BATACTIONCRIT`
- **GUID:** 637ea02f-bbcb-4015-8e2c-a1c7b9c0b546
- **Description:** Specify the action to take when the battery capacity reaches the critical level.
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

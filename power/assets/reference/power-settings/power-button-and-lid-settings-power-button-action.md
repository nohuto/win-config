---
title: Power button action | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-button-and-lid-settings-power-button-action
description: Specifies the action to take when the system power button is pressed.
note: This was modified by Nohuto using PowrProf API
---

# Power button action | Microsoft Learn

Specifies the action to take when the system power button is pressed.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Button\PowerButtonAction`
- **PowerCfg:**`PBUTTONACTION         `
- **GUID:** 7648efa3-dd9c-4e3e-b566-50f929386280
- **Description:** Specify the action to take when you press the power button.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Do nothing | 0 | Do nothing |
| 001 | Sleep | 2 | Sleep |
| 002 | Hibernate | 3 | Hibernate |
| 003 | Shut down | 6 | Shut down |
| 004 | Turn off the display | 8 | Turn off the display |

## Applies to

Available in Windows Vista and later versions of Windows.

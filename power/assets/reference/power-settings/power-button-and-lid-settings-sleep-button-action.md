---
title: Sleep button action | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-button-and-lid-settings-sleep-button-action
description: Specifies the action to take when the sleep power button is pressed.
note: This was modified by Nohuto using PowrProf API
---

# Sleep button action | Microsoft Learn

Specifies the action to take when the sleep power button is pressed.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Button\SleepButtonAction`
- **PowerCfg:**`SleepButtonAction           `
- **GUID:** 96996bc0-ad50-47ec-923b-6f41874dd9eb
- **Description:** Specify the action to take when you press the sleep button.
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

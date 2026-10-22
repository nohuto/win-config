---
title: Power button forced shutdown | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-button-and-lid-settings-power-button-forced-shutdown
description: Specifies the type of system shutdown that occurs when the system power button is pressed if the power button action is set to Shut Down.
note: This was modified by Nohuto using PowrProf API
---

# Power button forced shutdown | Microsoft Learn

Specifies the type of system shutdown that occurs when the system power button is pressed if the [power button action](power-button-and-lid-settings-power-button-action.md) is set to Shut Down.

**Warning** If you enable this setting and a user presses the power button to shut down the system, any open documents might not be saved and data loss could occur.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\Button\ForcedShutdown`
- **PowerCfg:**`SHUTDOWN `
- **GUID:** 833a6b62-dfa4-46d1-82f8-e09e34d029d6
- **Description:** Enable forced shutdown for button and lid actions
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |

## Applies to

Available in Windows 7 and later versions of Windows.

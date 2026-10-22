---
title: Power button and lid settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-button-and-lid-settings
description: Settings in this subgroup control the customization of system button actions.
note: This was modified by Nohuto using PowrProf API
---

# Power button and lid settings overview | Microsoft Learn

Settings in this subgroup control the customization of system button actions.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Power button and lid settings
- **GUID:** 4f971e89-eebd-4455-a8de-9e59040e7347
- **Windows provisioning path:**`Common\Power\Policy\Settings\Button`
- **PowerCfg alias:**`SUB_BUTTONS`
- **Hidden setting:** Yes

## Start menu power button

- **GUID:** a7066653-8d6c-40a8-910e-a1f54b84c7e5
- **PowerCfg alias:**`UIBUTTON_ACTION`
- **Description:** Specify the action to take when you press the Start menu power button.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Sleep | 2 | Sleep |
| 001 | Hibernate | 3 | Hibernate |
| 002 | Shut down | 6 | Shut down |


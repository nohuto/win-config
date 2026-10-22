---
title: Lid switch close action | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-button-and-lid-settings-lid-switch-close-action
description: Specifies the action to take when the system lid is closed.
note: This was modified by Nohuto using PowrProf API
---

# Lid switch close action | Microsoft Learn

Specifies the action to take when the system lid is closed.

## Aliases and setting visibility

- **Windows Provisioning:**`Common\Power\Policy\Settings\ButtonLidAction`
- **PowerCfg:**`LIDACTION       `
- **GUID:** 5ca83367-6e45-459f-a27b-476b1d01c936
- **Description:** Specify the action that your computer takes when you close the lid on your mobile PC.
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

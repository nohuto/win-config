---
title: Allow display required policy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/display-settings-allow-display-required-policy
description: Specifies whether Windows allows applications to temporarily prevent the display from automatically reducing brightness or turning off to save power.
note: This was modified by Nohuto using PowrProf API
---

# Allow display required policy | Microsoft Learn

Specifies whether Windows allows applications to temporarily prevent the display from automatically reducing brightness or turning off to save power.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Display\AllowDisplayRequired`
- **PowerCfg:**`ALLOWDISPLAY`
- **GUID:** a9ceb8da-cd46-44fb-a98b-02af69de4623
- **Description:** Allow programs to prevent display from turning off automatically
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | No | 0 | Don't allow programs to prevent display from turning off automatically |
| 001 | Yes | 1 | Allow programs to prevent display from turning off automatically |

## Applies to

Available in Windows 7 and later versions of Windows.

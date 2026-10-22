---
title: Dim annoyance timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/display-settings-dim-annoyance-timeout
description: This setting denotes the user annoyance detection threshold. It specifies the duration between automatic display brightness level reduction and user input to consider the automatic display brightness level reduction as an annoyance to the user.
note: This was modified by Nohuto using PowrProf API
---

# Dim annoyance timeout | Microsoft Learn

This setting denotes the user annoyance detection threshold. It specifies the duration between automatic display brightness level reduction and user input to consider the automatic display brightness level reduction as an annoyance to the user.

This setting applies only to portable computers that support Windows control of the brightness level of an integrated display device. In most situations, you should not change the default value of this setting.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Display\AdapativeIncrease`
- **PowerCfg:**`VIDEOADAPTINC       `
- **GUID:** 17aaa29b-8b43-4b94-aafe-35f64daaf1ee
- **Description:** Specify how long your computer is inactive before your display dims.
- **Hidden setting:** Yes

## Values

The value denotes the number of seconds.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Applies to

Available in Windows 7 and later versions of Windows.

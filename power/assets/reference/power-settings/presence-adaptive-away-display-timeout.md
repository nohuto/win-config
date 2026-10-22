---
title: Human Presence Sensor Adaptive Away Display Timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/presence-adaptive-away-display-timeout
description: Specifies the display timeout after a Human Presence sensor has signaled the user as not present
note: This was modified by Nohuto using PowrProf API
---

# Human Presence Sensor Adaptive Away Display Timeout | Microsoft Learn

Specifies the display timeout after a Human Presence sensor has signaled the user as not present. For more details see [Presence sensing](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/sensors-presence-sensing).

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\HuprVideoIdle`
- **PowerCfg:**`HUPRVIDEOIDLE`
- **GUID:** 0a7d6ab6-ac83-4ad1-8282-eca5b58308f3
- **Description:** Specifies the display timeout after a Human Presence sensor has signaled the user as not present
- **Hidden setting:** Yes

## Values

The value denotes the time, in seconds.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Applies to

Available in Windows 11, version 21H2 and later versions of Windows.

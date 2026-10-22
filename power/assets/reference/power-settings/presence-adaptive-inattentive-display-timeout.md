---
title: Human Presence Sensor Adaptive Inattentive Display Timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/presence-adaptive-inattentive-display-timeout
description: Specifies the display timeout after a Human Presence sensor has signaled the user is inattentive
note: This was modified by Nohuto using PowrProf API
---

# Human Presence Sensor Adaptive Inattentive Display Timeout | Microsoft Learn

Specifies the display timeout after a Human Presence sensor has signaled the user is inattentive. For more details see [Presence sensing](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/sensors-presence-sensing).

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\HuprVideoIdleInattentive`
- **PowerCfg:**`HUPRVIDEOIDLEINATTENTIVE`
- **GUID:** ee16691e-6ab3-4619-bb48-1c77c9357e5a
- **Description:** Specifies the display timeout after a Human Presence sensor has signaled the user is inattentive
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

Available in Windows 11, version 22H2 and later versions of Windows.

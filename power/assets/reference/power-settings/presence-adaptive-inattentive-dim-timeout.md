---
title: Human Presence Sensor Adaptive Inattentive Dim Timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/presence-adaptive-inattentive-dim-timeout
description: Specifies the dim timeout after a Human Presence sensor has signaled the user is inattentive.
note: This was modified by Nohuto using PowrProf API
---

# Human Presence Sensor Adaptive Inattentive Dim Timeout | Microsoft Learn

Specifies the dim timeout after a Human Presence sensor has signaled the user is inattentive. For more details see [Presence sensing](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/sensors-presence-sensing).

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\HuprVideoDim`
- **PowerCfg:**`HUPRVIDEODIM`
- **GUID:** cf8c6097-12b8-4279-bbdd-44601ee5209d
- **Description:** Specifies the dim timeout after a Human Presence sensor has signaled the user is inattentive
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

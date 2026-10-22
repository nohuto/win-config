---
title: Human Presence Sensor Adaptive Away Dim Timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/presence-adaptive-away-dim-timeout
description: Specifies the dim timeout after a Human Presence sensor has signaled the user as not present
note: This was modified by Nohuto using PowrProf API
---

# Human Presence Sensor Adaptive Away Dim Timeout | Microsoft Learn

Specifies the dim timeout after a Human Presence sensor has signaled the user as not present. For more details see [Presence sensing](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/sensors-presence-sensing).

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\HuprVideoDimAway`
- **PowerCfg:**`HUPRVIDEODIMAWAY`
- **GUID:** a79c8e0e-f271-482d-8f8a-5db9a18312de
- **Description:** Specifies the dim timeout after a Human Presence sensor has signaled the user as not present
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

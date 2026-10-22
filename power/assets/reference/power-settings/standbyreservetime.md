---
title: StandbyReserveTime | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/standbyreservetime
description: Defines the screen on time, in seconds, that will be available to the user after standby exists and the screen turns on.
note: This was modified by Nohuto using PowrProf API
---

# StandbyReserveTime | Microsoft Learn

Defines the screen on time, in seconds, that will be available to the user after standby exists and the screen turns on.

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\StandbyReserveTime`
- **GUID:** 468fe7e5-1158-46ec-88bc-5b96c9e44fd0
- **Description:** Specifies the minimun active usage time that the battery charge level should allow before taking an adaptive action
- **Hidden setting:** Yes

## Values

The value denotes the time, in seconds.

You can configure the values for the following sub-settings: `DcValue` and `AcValue`

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Applies to

Available in Windows 10, version 1607 and later versions of Windows.

---
title: Sleep idle timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-sleep-idle-timeout
description: Specifies the duration of inactivity before the system automatically enters sleep.
note: This was modified by Nohuto using PowrProf API
---

# Sleep idle timeout | Microsoft Learn

Specifies the duration of inactivity before the system automatically enters sleep.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Sleep\StandbyTimeout`
- **PowerCfg:**`STANDBYIDLE     `
- **GUID:** 29f6c1db-86da-48c5-9fdb-f2b67b1f44da
- **Description:** Specify how long your computer is inactive before going to sleep.
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

Available in Windows Vista and later versions of Windows.

---
title: Automatically wake for tasks | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-automatically-wake-for-tasks
description: Specifies whether the system uses the system-wide wake-on-timer capability. The system can automatically use wake-on-timer on capable hardware to perform scheduled tasks. For example, the system might wake automatically to install updates.
note: This was modified by Nohuto using PowrProf API
---

# Automatically wake for tasks | Microsoft Learn

Specifies whether the system uses the system-wide wake-on-timer capability.

The system can automatically use wake-on-timer on capable hardware to perform scheduled tasks. For example, the system might wake automatically to install updates.

## Aliases and setting visibility

- **PowerCfg:**`RTCWAKE `
- **GUID:** bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d
- **Description:** Specify if timed events should be allowed to wake the computer from sleep.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disable | 0 | Do not allow Windows to wake from sleep on timed events. |
| 001 | Enable | 1 | Allow Windows to wake from sleep on timed events. |
| 002 | Important Wake Timers Only | 2 | Allow Windows to wake from sleep only on important timed events. |

## Applies to

Available in Windows Vista and later versions of Windows.

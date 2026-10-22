---
title: Sleep unattended idle timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-sleep-unattended-idle-timeout
description: Specifies the duration of inactivity before the system automatically enters sleep after waking from sleep in an unattended state.
note: This was modified by Nohuto using PowrProf API
---

# Sleep unattended idle timeout | Microsoft Learn

Specifies the duration of inactivity before the system automatically enters sleep after waking from sleep in an unattended state.

For example, if the system wakes from sleep because of a timed event or a wake on LAN (WoL) event, the sleep unattended idle timeout value will be used instead of the [sleep idle timeout](sleep-settings-sleep-idle-timeout.md) value.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Sleep\UnattendTimeout`
- **PowerCfg:**`UnattendTimeout       `
- **GUID:** 7bc4a2f9-d8fc-4469-b07b-33eb785aaca0
- **Description:** Idle timeout before the system returns to a low power sleep state after waking unattended.
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

Available in Windows Vista with Service Pack 1 (SP1), Windows Server 2008 R2, and later versions of Windows.

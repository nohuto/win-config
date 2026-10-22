---
title: Disk idle timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings-disk-idle-timeout
description: Specifies the period of inactivity before the disk is automatically powered down.
note: This was modified by Nohuto using PowrProf API
---

# Disk idle timeout | Microsoft Learn

Specifies the period of inactivity before the disk is automatically powered down.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Disk\IdleTimeout`
- **PowerCfg:**`DISKIDLE               `
- **GUID:** 6738e2c4-e8a5-4a42-b16a-e040e769756e
- **Description:** Specify how long your hard drive is inactive before the disk turns off.
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

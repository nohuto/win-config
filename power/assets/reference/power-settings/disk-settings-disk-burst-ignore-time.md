---
title: Disk burst ignore time | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings-disk-burst-ignore-time
description: Specifies the period of inactivity to ignore when attempting to aggressively power down the disk.
note: This was modified by Nohuto using PowrProf API
---

# Disk burst ignore time | Microsoft Learn

Specifies the period of inactivity to ignore when attempting to aggressively power down the disk.

## Aliases and setting visibility

- **Windows provisioning:**`N/A`
- **PowerCfg:**`N/A               `
- **GUID:** 80e3c60e-bb94-4ad8-bbe0-0d3195efc663
- **Description:** Ignore a burst of disk activity up to the specified time when determining if the disk is idle.
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

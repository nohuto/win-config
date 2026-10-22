---
title: Link power management mode - adaptive | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings-link-power-management-mode---adaptive
description: Specifies the period of AHCI link idle time before the link is put into a slumber state when Host-Initiated Power Management (HIPM) or Device-Initiated Power Management (DIPM) is enabled.
note: This was modified by Nohuto using PowrProf API
---

# Link power management mode - adaptive | Microsoft Learn

Specifies the period of AHCI link idle time before the link is put into a slumber state when Host-Initiated Power Management (HIPM) or Device-Initiated Power Management (DIPM) is enabled.

## Aliases and setting visibility

- **Windows provisioning:**`N/A`
- **PowerCfg:**`N/A               `
- **GUID:** dab60367-53fe-4fbc-825e-521d069d2456
- **Description:** Automatically transit from Partial to Slumber.
- **Hidden setting:** Yes

## Values

The value denotes the number of milliseconds.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 300,000 |
| Increment | 1 |
| Units | millisecond |

## Applies to

Available in Windows 7 and later versions of Windows.

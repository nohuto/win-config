---
title: Link power management mode - HIPM/DIPM | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/disk-settings-link-power-management-mode---hipm-dipm
description: Configures the link power management mode for disk and storage devices that are attached to the system through an AHCI interface.
note: This was modified by Nohuto using PowrProf API
---

# Link power management mode - HIPM/DIPM | Microsoft Learn

Configures the link power management mode for disk and storage devices that are attached to the system through an AHCI interface.

## Aliases and setting visibility

- **Windows provisioning:**`N/A`
- **PowerCfg:**`N/A         `
- **GUID:** 0b2d69d7-a2a1-449c-9680-f91c70521c60
- **Description:** Configures the LPM state.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Active | 0 | Neither Host or Device initiated allowed |
| 001 | HIPM | 1 | Host initiated allowed only |
| 002 | HIPM+DIPM | 3 | Both Host and Device initiated allowed |
| 003 | DIPM | 2 | Device initiated allowed only |
| 004 | Lowest | 7 | HIPM+DIPM+DEVSLP |

## Applies to

Available in Windows 7 and later versions of Windows.

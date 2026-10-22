---
title: Device idle policy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/no-subgroup-settings-device-idle-policy
description: Determines whether conservation idle timeouts or performance idle timeouts are used for devices that are integrated with Windows kernel power manager device idle detection.
note: This was modified by Nohuto using PowrProf API
---

# Device idle policy | Microsoft Learn

Determines whether conservation idle timeouts or performance idle timeouts are used for devices that are integrated with Windows kernel power manager device idle detection.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Misc\DeviceIdlePolicy`
- **PowerCfg:**`N/A `
- **GUID:** 4faab71a-92e5-4726-b531-224559672d19
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 0 | Performance | 0 | Favor performance over power savings. |
| 1 | Power savings | 1 | Favor power savings over performance. |

## Applies to

Available in Windows Vista with Service Pack 1 (SP1), Windows Server 2008 R2, and later versions of Windows.

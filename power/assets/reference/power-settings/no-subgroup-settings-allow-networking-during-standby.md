---
title: Allow networking during standby | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/no-subgroup-settings-allow-networking-during-standby
description: Specifies whether to allow networking during standby.
note: This was modified by Nohuto using PowrProf API
---

# Allow networking during standby | Microsoft Learn

Specifies whether to allow networking during standby.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Misc\ConnectivityInStandby`
- **GUID:** f15576e8-98b7-4186-b944-eafa664402d9
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 0 | Disable | 0 | Disable networking in Standby. |
| 1 | Enable | 1 | Enable networking in Standby. |
| 2 | Managed by Windows | 2 | Network connection state in Standby is managed by Windows. |

## Applies to

Available in Windows Vista through Windows 10, version 1909.

Note

Deprecated starting in Windows 10, version 2004.

For more information about network connectivity in Modern Standby, refer to [Network connectivity](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby-network-connectivity).

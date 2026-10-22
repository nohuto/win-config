---
title: Link state power management | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/pci-express-settings-link-state-power-management
description: Specifies the personality of the power plan.
note: This was modified by Nohuto using PowrProf API
---

# Link state power management | Microsoft Learn

Specifies the personality of the power plan.

**Warning** System administrators should not change the power plan personality settings.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\PCIExpress\ASPM`
- **PowerCfg:**`ASPM`
- **GUID:** ee12f906-d277-404b-b6da-e5fa1a576df5
- **Description:** Specifies the Active State Power Management (ASPM) policy to use for capable links when the link is idle.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Turn off ASPM for all links. |
| 001 | Moderate power savings | 1 | Attempt to use the L0S state when link is idle. |
| 002 | Maximum power savings | 2 | Attempt to use the L1 state when the link is idle. |

## Applies to

Available in Windows Vista and later versions of Windows.

---
title: Other power settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/no-subgroup-settings
description: Settings in this subgroup do not belong to any other subgroup.
note: This was modified by Nohuto using PowrProf API
---

# Other power settings overview | Microsoft Learn

Settings in this subgroup do not belong to any other subgroup.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** No subgroup settings
- **GUID:** fea3413e-7e05-4911-9a71-700331f1c294
- **Windows provisioning path:**`Common\Power\Policy\Settings\Misc`
- **PowerCfg alias:**`SUB_NONE`
- **Hidden setting:** Yes

## Power plan type

- **GUID:** 245d8541-3943-4422-b025-13a784f679b7
- **PowerCfg alias:**`PERSONALITY`
- **Description:** The default Windows power plan types include Balanced, Power saver, and High performance. The three types are designed to balance power savings while providing performance on demand, maximize power savings, or maximize performance. Many system components use the power plan type to deciding whether to optimize power savings or performance.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Power saver | a1841308-3541-4fab-bc81-f71556f20b4a | Saves energy by reducing your computer's performance where possible. |
| 001 | High performance | 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c | Favors performance, but may use more energy. |
| 002 | Balanced | 381b4222-f694-41f0-9685-ff5bb260df2e | Automatically balances performance with energy consumption on capable hardware. |

## Disconnected Standby Mode

- **GUID:** 68afb2d9-ee95-47a8-8f50-4115088073b1
- **PowerCfg alias:**`DISCONNECTEDSTANDBYMODE`
- **Description:** Specifies the disconnected standby mode.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Normal | 0 | Normal |
| 001 | Aggressive | 1 | Aggressive |


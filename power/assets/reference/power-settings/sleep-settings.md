---
title: Sleep settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings
description: Settings in this subgroup control sleep, resume, and other related functionality.
note: This was modified by Nohuto using PowrProf API
---

# Sleep settings overview | Microsoft Learn

Settings in this subgroup control sleep, resume, and other related functionality.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Sleep settings
- **GUID:** 238c9fa8-0aad-41ed-83f4-97be242c8f20
- **Windows provisioning path:**`Common\Power\Policy\Settings\Sleep`
- **PowerCfg alias:**`SUB_SLEEP`
- **Hidden setting:** Yes

## Legacy RTC mitigations

- **GUID:** 1a34bdc3-7e6b-442e-a9d0-64b6ef378e84
- **PowerCfg alias:**`LEGACYRTCMITIGATION`
- **Description:** Avoid waking from hiberate via the legacy RTC wake alarm. Also defer hibernate in the presence of an immanent wake alarm.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disable | 0 | Disable legacy RTC mitigations |
| 001 | Enable | 1 | Enable legacy RTC mitigations |


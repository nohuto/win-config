---
title: Battery settings overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/battery-settings
description: Settings in this subgroup control the customization of battery actions and thresholds.
note: This was modified by Nohuto using PowrProf API
---

# Battery settings overview | Microsoft Learn

Settings in this subgroup control the customization of battery actions and thresholds.

Windows will execute the [Critical Battery Action](battery-settings-critical-battery-action.md) when the battery is in the critical battery power state. The critical battery power state is determined when the battery percentage reaches the higher of:

1. The [DefaultAlert1 Threshold](https://learn.microsoft.com/en-us/windows/win32/power/battery-information-str), for systems which use the ACPI control method battery interface, is provided by default capacity of low
2. The battery charge level configured via provisioning or powercfg (the [Critical Battery Threshold](battery-settings-critical-battery-threshold.md))

For example, if a device with one battery has the first value as 10% and the second value as 5%, the battery would enter the critical battery power state at 10%.

To view these two values, run **pwrtest.exe /info:battery** from a repro system.

In the case of a device with multiple batteries, the Critical Battery Action will execute if any of the batteries are in a critical battery power state.

## Subgroup, GUID, aliases, and setting visibility

- **Subgroup:** Battery settings
- **GUID:** e73a048d-bf27-4f12-9731-8b2076e8891f
- **Windows provisioning path:**`Common\Power\Policy\Settings\Battery`
- **PowerCfg alias:**`SUB_BATTERY`
- **Hidden setting:** Yes

## Critical battery notification

- **GUID:** 5dbb7c9f-38e9-40d2-9749-4f8a0e9f640f
- **PowerCfg alias:**`BATFLAGSCRIT`
- **Description:** Specify whether a notification is shown when the battery capacity reaches the critical level.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |

## Low battery notification

- **GUID:** bcded951-187b-4d05-bccc-f7e51960c258
- **PowerCfg alias:**`BATFLAGSLOW`
- **Description:** Specify whether a notification is shown when the battery capacity reaches the low level.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |


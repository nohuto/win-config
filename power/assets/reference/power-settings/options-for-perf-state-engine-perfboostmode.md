---
title: PERFBOOSTMODE | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perfboostmode
description: PERFBOOSTMODE determines how processors select a performance level when current operating conditions allow for boosting performance above the nominal level.
note: This was modified by Nohuto using PowrProf API
---

# PERFBOOSTMODE | Microsoft Learn

`PERFBOOSTMODE` determines how processors select a performance level when current operating conditions allow for boosting performance above the nominal level.

For non-autonomous CPPC/PEP, the OS selects a target boost performance when Enabled and selects the maximum boost performance when Aggressive.

## GUID, alias, and setting visibility

- **GUID:** be337238-0d82-4146-a960-4f3749d470c7
- **PowerCfg alias:**`PERFBOOSTMODE`
- **Description:** Specify the performance boost mode.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 0 | Disabled | 0 | Don't select target frequencies above maximum frequency. |
| 1 | Enabled | 1 | Select target frequencies above maximum frequency. |
| 2 | Aggressive | 2 | Always select the highest possible target frequency above nominal frequency. |
| 3 | Efficient Enabled | 3 | Select target frequencies above maximum frequency if hardware supports doing so efficiently. |
| 4 | Efficient Aggressive | 4 | Always select the highest possible target frequency above nominal frequency if hardware supports doing so efficiently. |
| 5 | Aggressive At Guaranteed | 5 | Always select the highest possible target frequency above guaranteed frequency. |
| 6 | Efficient Aggressive At Guaranteed | 6 | Always select the highest possible target frequency above guaranteed frequency if hardware supports doing so efficiently. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

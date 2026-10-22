---
title: StandbyBudgetPercent | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/standbybudgetpercent
description: Defines the battery drain percentage that the user is allowed in a standby session.
note: This was modified by Nohuto using PowrProf API
---

# StandbyBudgetPercent | Microsoft Learn

Defines the battery drain percentage that the system is allowed in a StandbyBudgetRefreshInterval.

Prior to Windows 11, version 24H2: Defines the battery drain percentage that the user is allowed in a standby session.

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Policy\Settings\AdaptivePowerBehavior\StandbyBudgetPercent`
- **GUID:** 9fe527be-1b70-48da-930d-7bcf17b44990
- **Description:** Specifies percentage of battery per unit of time allowed to be consumed by the system while it is in standby
- **Hidden setting:** Yes

## Values

The value denotes the percentage, example: `5` = 5%.

You can configure the values for the following sub-settings: `DcValue` and `AcValue`

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | percent |

## Applies to

Available in Windows 10, version 1607 and later versions of Windows.

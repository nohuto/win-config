---
title: Dim display brightness | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/display-settings-dim-display-brightness
description: Denotes the reduced display brightness level after the dim idle timeout has been reached.
note: This was modified by Nohuto using PowrProf API
---

# Dim display brightness | Microsoft Learn

Denotes the reduced display brightness level after the dim idle timeout has been reached.

This setting applies only to portable computers that support Windows control of the brightness level of an integrated display device.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Display\DimLevel`
- **PowerCfg:**`VIDEODIMLEVEL         `
- **GUID:** f1fbfde2-a960-4165-9f88-50667911ce96
- **Description:** Specify the dim brightness level of your display.
- **Hidden setting:** Yes

## Values

The value denotes the percentage (%).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Applies to

Available in Windows 7 and later versions of Windows.

---
title: Adaptive display idle timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/display-settings-adaptive-display-idle-timeout
description: Specifies whether the OS automatically scales the display idle time-out based on user activity.
note: This was modified by Nohuto using PowrProf API
---

# Adaptive display idle timeout | Microsoft Learn

Specifies whether the OS automatically scales the display idle time-out based on user activity.

If the user provides input to the system shortly after the display idle timeout is reached, Windows automatically extends the display idle time-out to deliver a better user experience.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Display\AdaptiveTimeout `
- **PowerCfg:**`VIDEOADAPT`
- **GUID:** 90959d22-d6a1-49b9-af93-bce885ad335b
- **Description:** Extends the time that Windows waits to turn off the display if you repeatedly turn on the display with the keyboard or mouse.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |

## Applies to

Available in Windows Vista and later versions of Windows.

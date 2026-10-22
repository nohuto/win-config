---
title: LidNotificationsAreReliable | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-controls-lidnotificationsarereliable
description: Use to notify the OS whether the platform guarantees that lid notifications are sent whenever the lid is opened or closed.
---

# LidNotificationsAreReliable | Microsoft Learn

Use to notify the OS whether the platform guarantees that lid notifications are sent whenever the lid is opened or closed.

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Controls\LidNotificationsAreReliable`
- **Description:** Not applicable; this page documents a power control rather than a power setting GUID.
- **Hidden setting:** Yes

## Values

| Value | Description |
| --- | --- |
| True | The platform guarantees that lid notifications will be sent every time the device lid is opened or closed. The OS suppresses Windows Hello when the device lid is closed to ensure further input is not processed and to save battery life.OEMs must reliably report lid open and lid close events to opt-in to this setting. If there are scenarios where a lid open event is not reliably reported to the OS, Windows Hello may not work for the user. |
| False | The platform does not guarantee that lid notifications are sent every time the device lid is opened or closed. |

## Remarks

Depending on your platform scenarios, you may also want to set the `LidOpenWake` setting ([Lid open wake action](lid-open-wake-action.md)). For example:

- If you want to implement a platform that does nothing when the lid is opened, but you want to suppress Windows Hello when the lid is closed, you'll want to set `LidOpenWake`=0 and `LidNotificationsAreReliable`=True.
- If you have a device that has a rigid keyboard and the risk of the lid opening and causing the device to turn on is low, you may want to implement a platform that turns on the display when the lid is opened, but you want to suppress Windows Hello when the lid is closed, you'll want to set `LidOpenWake`=1 and `LidNotificationsAreReliable`=True.

## Applies to

Available in Windows 10, version 1607 and later versions of Windows.

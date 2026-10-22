---
title: EnableInputSuppression | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/power-controls-enableinputsuppression
description: Use to enable input suppression on a Modern Standby system with a clamshell form factor when the lid is closed and there is no external monitor connected.
---

# EnableInputSuppression | Microsoft Learn

Enables input suppression on Modern Standby clamshell systems to prevent unintended wakes when the lid is closed and no external display is connected.

For Windows 10 through Windows 11, version 23H2, input suppression applies only on DC power. Starting in Windows 11, version 24H2, input suppression can apply on both DC and AC power.

When these conditions are met, the system is expected to remain in a low-power state to preserve battery life. However, some input devices can wake the system even when the user is not actively using it. For example, a paired Bluetooth mouse may move inside a laptop bag and trigger wakes. Input suppression helps prevent these unintended wakes.

## Aliases and setting visibility

- **Windows provisioning path:**`Common\Power\Controls\EnableInputSuppression`
- **Description:** Not applicable; this page documents a power control rather than a power setting GUID.
- **Hidden setting:** Yes

## Values

| Value | Description |
| --- | --- |
| 1 | Enable input suppression (default). |
| 0 | Disable input suppression. |

## Applies to

Available in Windows 10, version 1803 and later versions of Windows.

Note

Starting with Windows 11, version 24H2, the power button action is suppressed when input suppression is active. When the lid is closed and no external display is connected, pressing the power button does not turn on the display in clamshell mode on either DC or AC power.

If an external display is connected while the lid is closed, input suppression does not apply and the external display may turn on.

Note

Input suppression does not engage when the lid is closed and the lid close action (for the current power source) is set to **Do nothing**. If the system enters standby for any other reason, input suppression remains disengaged even if all other conditions are met (for example, the lid stays closed and no external display is connected). For more information, see [Lid switch close action](power-button-and-lid-settings-lid-switch-close-action.md).

## Lid close action **Do nothing** behavior and examples

Input suppression respects the user's lid close action setting for the current power source. If the lid close action for the current power source is **Do nothing**, input suppression remains disengaged.

The following examples illustrate how input suppression interacts with different lid close action settings across power sources:

Examples:

- If the device is on DC and the lid close action is set to **Sleep**, but on AC it's set to **Do nothing**, closing the lid while on DC puts the system to sleep as expected. If the user then connects a dock that provides AC, the system remains asleep, but input suppression is disengaged based on the AC lid close policy of **Do nothing**.
- If the user closes the lid while on AC (lid close action = **Do nothing**), the system stays active until the video idle timeout expires or the user unplugs AC. Once AC is unplugged, Windows re-evaluates the DC lid close policy. If the DC policy is **Sleep**, the system transitions to sleep at that point.

Starting with Windows 11, version 24H2, input suppression is evaluated on AC as well. If the user's lid close action preference on AC is **Do nothing**, input suppression is disengaged.

Note

Disabling **EnableInputSuppression** is not recommended.

Input suppression (including on AC in Windows 11, version 24H2 and later) is intended to help prevent unexpected wakes in "hotbag" scenarios. One example is when a device is on AC, the user closes the lid, disconnects AC, and then puts the device in a bag while an input device continuously attempts to wake the system (for example, a USB mouse left on, or repeated/buggy touch inputs after lid close).

In these scenarios, timing/race conditions can occur between the components that enact input suppression and the input stack that processes device input and triggers wakes.

Disabling input suppression entirely can increase the risk of unexpected wakes and reduce battery life. If a change is required for AC scenarios, prefer using the lid close action setting for AC power and set it to **Do nothing**, which disengages input suppression.

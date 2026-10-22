---
title: Presence Sensing Power Settings Overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/presence-adaptive
description: Presence Sensing Power Settings provide ways for OEMs to configure power behaviours on Systems with Presence Sensing.
---

# Presence Sensing Power Settings Overview | Microsoft Learn

These power settings help configure [Presence sensing](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/sensors-presence-sensing) on Windows.The purpose of the registry keys laid out in this paper is NOT for runtime configuration of the feature. The purpose of the on/off registry key is to give OEMs the control to turn off the feature if there is an unforeseen problem in the manufacturing process, or other reason to necessitate disabling the feature on certain devices.

OEMs or users can also configure a fixed doze to hibernate timer. However, the timer-based logic has significant user experience drawbacks. A fixed doze timer can result in the system fully draining the battery in standby if the drain happened within the doze timeout or cut short a low-drain Modern Standby experience by hibernating at the doze timeout. Consequently, it is preferable to leverage adaptive hibernate to hibernate dynamically based on battery drain.

Note

. Some settings such as Dim Brightness level need to be configured via [Display settings overview](display-settings.md).

## System requirements

Presence Sensing is available on Windows 11 and later systems. You can also configure the settings below using a custom provisioning package file for OEM images. For more information about powercfg, see [Powercfg command-line options](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options)

## Human Presence Sensor Adaptive Away Dim Timeout

Specifies the display timeout after a Human Presence sensor has signaled the user is inattentive. .

## Human Presence Sensor Adaptive Inattentive Dim Timeout

Specifies the dim timeout after a Human Presence sensor has signaled the user is inattentive.

## Human Presence Sensor Adaptive Away Display Timeout

Specifies the display timeout after a Human Presence sensor has signaled the user as not present.

## Human Presence Sensor Adaptive Inattentive Display Timeout

Specifies the display timeout after a Human Presence sensor has signaled the user is inattentive.

## Windows provisioning package sample

You can use the Windows Provisioning framework to configure the adaptive hibernate settings described in this section. First, create a provisioning package using [Windows Configuration Designer](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-install-icd). You will then edit the customizations.xml file contained in the package to include your power settings, which appear under the `Common\Power\Policy\Settings\AdaptivePowerBehavior` namespace. Use the XML file as one of the inputs to the Windows Configuration Designer command-line interface to generate either a provisioning package that contains the power settings. You can then apply the provisioning package to the image. For information on how to use the Windows Configuration Designer CLI, see [Use the Windows Configuration Designer command-line interface](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-command-line).


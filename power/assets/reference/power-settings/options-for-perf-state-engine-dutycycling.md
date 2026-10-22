---
title: DutyCycling | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-dutycycling
description: DutyCycling enables or disables the duty cycling capability on systems that support processor duty cycling.
note: This was modified by Nohuto using PowrProf API
---

# DutyCycling | Microsoft Learn

`DutyCycling` enables or disables the duty cycling capability on systems that support processor duty cycling.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\DutyCycling`
- **PowerCfg:**`PERFDUTYCYCLING`
- **GUID:** 4e4450b3-6179-4e91-b8f1-5bb9938f81a1
- **Description:** Specify whether the processor may use duty cycling.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Disallow processor duty cycling. |
| 001 | Enabled | 1 | Allow processor duty cycling. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |

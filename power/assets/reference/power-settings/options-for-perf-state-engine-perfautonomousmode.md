---
title: PerfAutonomousMode | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perfautonomousmode
description: PerfAutonomousMode controls whether autonomous mode is enabled on systems that implement version 2 of the CPPC interface, and determines whether desired performance requests should be provided to the platform.
note: This was modified by Nohuto using PowrProf API
---

# PerfAutonomousMode | Microsoft Learn

`PerfAutonomousMode` controls whether autonomous mode is enabled on systems that implement version 2 of the CPPC interface, and determines whether desired performance requests should be provided to the platform. On systems with other performance state interfaces, this setting has no effect.

**Note** Platforms that support CPPC version 2 may only support autonomous disabled or autonomous enabled mode. If only one mode is supported, the OS uses that mode and ignores the `PerfAutonomousMode` power setting.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\PerfAutonomousMode`
- **PowerCfg:**`PERFAUTONOMOUS`
- **GUID:** 8baa4a8a-14c6-4451-8e8b-14bdbd197537
- **Description:** Specify whether processors should autonomously determine their target performance state.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Determine target performance state using operating system algorithms. |
| 001 | Enabled | 1 | Determine target performance state using autonomous selection. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

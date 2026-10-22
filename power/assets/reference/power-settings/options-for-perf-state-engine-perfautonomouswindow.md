---
title: PerfAutonomousWindow | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perfautonomouswindow
description: PerfAutonomousWindow specifies the value to program in the autonomous activity window register on systems that implement version 2 of the CPPC interface and have autonomous mode enabled.
note: This was modified by Nohuto using PowrProf API
---

# PerfAutonomousWindow | Microsoft Learn

`PerfAutonomousWindow` specifies the value to program in the autonomous activity window register on systems that implement version 2 of the CPPC interface and have autonomous mode enabled. Longer values indicate to the platform that it should be less sensitive to short duration spikes/dips in processor utilization.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\PerfAutonomousWindow`
- **PowerCfg:**`PERFAUTONOMOUSWINDOW`
- **GUID:** cfeda3d0-7697-4566-a922-a9086cd49dfa
- **Description:** Specify the time period over which to observe processor utilization when operating in autonomous mode.
- **Hidden setting:** Yes

## Values

The value denotes microseconds.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 1,270,000,000 |
| Increment | 1 |
| Units | Microseconds |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |

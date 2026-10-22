---
title: LatencyHintEpp | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-latencyhintepp
description: LatencyHintEpp specifies the processor energy performance preference in response to latency sensitivity hints.
note: This was modified by Nohuto using PowrProf API
---

# LatencyHintEpp | Microsoft Learn

`LatencyHintEpp` specifies the processor energy performance preference in response to latency sensitivity hints. Such hints are generated when an event preceding an expected latency-sensitive operation is detected. Examples include mouse button up events (for all mouse buttons), touch gesture start and gesture stop (finger down and finger up), and keyboard enter key down. This setting is only applicable to [Enabled](options-for-perf-state-engine-perfautonomousmode.md) autonomous performance states systems.

It is also used for Deadline [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service) performance. The value could be changed by setting `LatencyHintEpp` in Media QoS profile.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\LatencyHintEpp`, `Common\Power\Policy\Settings\Processor\LatencyHintEpp1`
- **PowerCfg:**`LATENCYHINTEPP`, `LATENCYHINTEPP1`
- **GUID:** 4b70f900-cdd9-4e66-aa26-ae8417f98173, 4b70f900-cdd9-4e66-aa26-ae8417f98174
- **Description:** Specify the processor energy performance preference in response to latency sensitivity hints. / Specify the Processor Power Efficiency Class 1 processor energy performance preference in response to latency sensitivity hints.
- **Hidden setting:** Yes

## Values

The value denotes percentage (%).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | percent |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 24H2 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

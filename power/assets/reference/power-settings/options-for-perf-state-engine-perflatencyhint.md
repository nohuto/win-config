---
title: PerfLatencyHint | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-perflatencyhint
description: PerfLatencyHint specifies the processor performance in response to latency sensitivity hints.
note: This was modified by Nohuto using PowrProf API
---

# PerfLatencyHint | Microsoft Learn

`PerfLatencyHint` specifies the processor performance in response to latency sensitivity hints. Such hints are generated when an event preceding an expected latency-sensitive operation is detected. Examples include mouse button up events (for all mouse buttons), touch gesture start and gesture stop (finger down and finger up), and keyboard enter key down.

It is also used for Deadline [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service) performance. The value could be changed by setting `PerfLatencyHint` in Media QoS profile.

When set to 0, the processor performance engine does not take latency sensitivity hints to account when selecting a performance state. Otherwise, the performance is raised system-wide to the specified performance level.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\PerfLatencyHint`, `Common\Power\Policy\Settings\Processor\PerfLatencyHint1`
- **PowerCfg:**`LATENCYHINTPERF`, `LATENCYHINTPERF1`
- **GUID:** 619b7505-003b-4e82-b7a6-4dd29c300971, 619b7505-003b-4e82-b7a6-4dd29c300972
- **Description:** Specify the processor performance in response to latency sensitivity hints. / Specify the processor performance in response to latency sensitivity hints for Processor Power Efficiency Class 1.
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
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | N/A |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

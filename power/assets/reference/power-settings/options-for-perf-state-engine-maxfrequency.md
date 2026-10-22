---
title: MaxFrequency | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-maxfrequency
description: MaxFrequency specifies the maximum processor performance state, which is specified in Megahertz (MHz).
note: This was modified by Nohuto using PowrProf API
---

# MaxFrequency | Microsoft Learn

`MaxFrequency` specifies the maximum processor performance state, which is specified in Megahertz (MHz).

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\MaxFrequency`, `Common\Power\Policy\Settings\Processor\MaxFrequency1`
- **PowerCfg:**`PROCFREQMAX`, `PROCFREQMAX1`
- **GUID:** 75b0ae3f-bce0-45a7-8c89-c9611c25e100, 75b0ae3f-bce0-45a7-8c89-c9611c25e101
- **Description:** Specify the approximate maximum frequency of your processor (in MHz). / Specify the approximate maximum frequency of your Processor Power Efficiency Class 1 processor (in MHz).
- **Hidden setting:** Yes

## Values

The value denotes Megahertz (MHz).

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | MHz |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

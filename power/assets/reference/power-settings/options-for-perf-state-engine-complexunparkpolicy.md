---
title: ComplexUnparkPolicy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-complexunparkpolicy
description: A complex is defined as logical processors sharing same LLC cache. ComplexUnparkPolicy specifies the complex unparking policy. As per this policy Lp is unparked as per value selected for this policy.
note: This was modified by Nohuto using PowrProf API
---

# ComplexUnparkPolicy | Microsoft Learn

`ComplexUnparkPolicy` A complex is defined as logical processors sharing same LLC cache. ComplexUnparkPolicy specifies the complex unparking policy. As per this policy Lp is unparked as per value selected for this policy.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\ComplexUnparkPolicy`
- **PowerCfg:**`ComplexUnparkPolicy`
- **GUID:** b669a5e9-7b1d-4132-baaa-49190abcfeb6
- **Description:** Specify what policy to be used to unpark complex llc.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | No preference for unparking from complexes. |
| 001 | Round robin | 1 | Use round robin policy to unpark among complexes. |
| 002 | Sequential | 2 | Use sequential policy to unpark one by one from a complex. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

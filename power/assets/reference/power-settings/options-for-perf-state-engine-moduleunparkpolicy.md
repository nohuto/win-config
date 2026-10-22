---
title: ModuleUnparkPolicy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-moduleunparkpolicy
description: A module is defined as logical processors sharing same L2 cache. ModuleUnparkPolicy specifies the module unparking policy. As per this policy Lp is unparked as per value selected for this policy.
note: This was modified by Nohuto using PowrProf API
---

# ModuleUnparkPolicy | Microsoft Learn

`ModuleUnparkPolicy` A module is defined as logical processors sharing same L2 cache. ModuleUnparkPolicy specifies the module unparking policy. As per this policy Lp is unparked as per value selected for this policy.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\ModuleUnparkPolicy`
- **PowerCfg:**`ModuleUnparkPolicy`
- **GUID:** b0deaf6b-59c0-4523-8a45-ca7f40244114
- **Description:** Specify what policy to be used to unpark modules.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | No preference for unparking from modules. |
| 001 | Round robin | 1 | Use round robin policy to unpark among modules. |
| 002 | Sequential | 2 | Use sequential policy to unpark one by one from a module. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

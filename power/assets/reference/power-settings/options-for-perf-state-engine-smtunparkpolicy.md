---
title: SmtUnparkPolicy | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/options-for-perf-state-engine-smtunparkpolicy
description: SmtUnparkPolicy is Smt threads unpark policy. This policy specify the policy to be used to unpark SMT threads within a processor core. The various values for this policy is defined below.
note: This was modified by Nohuto using PowrProf API
---

# SmtUnparkPolicy | Microsoft Learn

`SmtUnparkPolicy` SmtUnparkPolicy is Smt threads unpark policy. This policy specify the policy to be used to unpark SMT threads within a processor core. The various values for this policy is defined below..

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\SmtUnparkPolicy`
- **PowerCfg:**`SmtUnparkPolicy`
- **GUID:** b28a6829-c5f7-444e-8f61-10e24e85c532
- **Description:** Specify the policy to be used to unpark SMT threads within a processor core.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Core | 0 | Use cores policy to unpark all logical processors in a core as a group |
| 001 | Core per Thread | 1 | Use core per thread policy to unpark one core per each thread |
| 002 | Round robin | 2 | Use round robin policy to unpark logical processors among cores |
| 003 | Sequential | 3 | Use sequential policy to unpark logical processors one by one from a core. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

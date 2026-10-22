---
title: Allow system required requests | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-allow-system-required-requests
description: Configures the power manager to accept or ignore application system required requests. These requests prevent the system from automatically entering sleep after a period of user inactivity.
note: This was modified by Nohuto using PowrProf API
---

# Allow system required requests | Microsoft Learn

Configures the power manager to accept or ignore application system required requests. These requests prevent the system from automatically entering sleep after a period of user inactivity.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Sleep\AllowSystemRequired`
- **PowerCfg:**`SYSTEMREQUIRED `
- **GUID:** a4b195f5-8225-47d8-8012-9d41369786e2
- **Description:** Allow programs to prevent machine from going to sleep automatically
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | No | 0 | Don't allow programs to prevent machine from going to sleep automatically |
| 001 | Yes | 1 | Allow programs to prevent machine from going to sleep automatically |

## Applies to

Available in Windows 7 and later versions of Windows.

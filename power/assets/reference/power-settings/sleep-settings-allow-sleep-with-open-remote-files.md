---
title: Allow sleep with open remote files | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-allow-sleep-with-open-remote-files
description: Configures the network file system to prevent the computer from automatically entering sleep when remote network files are open.
note: This was modified by Nohuto using PowrProf API
---

# Allow sleep with open remote files | Microsoft Learn

Configures the network file system to prevent the computer from automatically entering sleep when remote network files are open.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Sleep\AllowRemoteOpenSleep`
- **PowerCfg:**`ALLOWREMOTEOPENSLEEP`
- **GUID:** d4c1d4c8-d5cc-43d3-b83e-fc51215cb04d
- **Description:** Allow your machine to go to sleep when files opened remotely have not been written to.
- **Hidden setting:** Yes

## Values

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disable | 0 | Disable. |
| 001 | Enable | 1 | Enable. |

## Applies to

Available in Windows Vista and later versions of Windows.

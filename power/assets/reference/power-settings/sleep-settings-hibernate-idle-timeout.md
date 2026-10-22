---
title: Hibernate idle timeout | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/sleep-settings-hibernate-idle-timeout
description: Specifies the duration of time after sleep that the system automatically wakes and enters hibernation.
note: This was modified by Nohuto using PowrProf API
---

# Hibernate idle timeout | Microsoft Learn

Specifies the duration of time after sleep that the system automatically wakes and enters hibernation.

This settings enables hibernate option on Modern Standby systems.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Settings\Sleep\HibernateTimeout`
- **PowerCfg:**`HIBERNATEIDLE   `
- **GUID:** 9d7815a6-7ee4-497e-8888-515a05f02364
- **Description:** Specify how long your computer is inactive before hibernating.
- **Hidden setting:** Yes

## Values

The value denotes the number of seconds.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Applies to

Available in Windows Vista and later versions of Windows.

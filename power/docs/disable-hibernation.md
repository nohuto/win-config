# Disable Hibernation

Hibernation is Windows S4 power state, it writes the resume state to `Hiberfil.sys` on the system volume, transitions the platform to ACPI S4, and later resumes through Boot Manager and the Windows Resume application (`Winresume.efi`).


> "*Windows uses hibernation to provide a fast startup experience. When available, it's also used on mobile devices to extend the usable battery life of a system by giving a mechanism to save all of the user's state prior to shutting down the system. In a hibernate transition, all the contents of memory are written to a file on the primary system drive, the hibernation file. This preserves the state of the operating system, applications, and devices. In the case where the combined memory footprint consumes all of physical memory, the hibernation file must be large enough to ensure there's space to save all the contents of physical memory. Since data is written to non-volatile storage, DRAM does not need to maintain self-refresh and can be powered off, which means power consumption of hibernation is very low, almost the same as power off.*
> *During a full shutdown and boot (S5), the entire user session is torn down and restarted on the next boot. In contrast, during a hibernation (S4), the user session is closed and the user state is saved.*"
>
> — Microsoft, [System power states, Hibernate state: S4](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#hibernate-state-s4)

`powercfg /hibernate off` disables normal hibernation, hybrid sleep, and Fast Startup as a consequence.

## [Power State Table](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states)

| Power state | ACPI state | Description | 
|-------------|------------|-------------|
| Working | *S0* | The system is fully usable. Hardware components that aren't in use can save power by entering a lower power state. | 
| Sleep (Modern Standby) | *S0* low-power idle | Some SoC systems support a low-power idle state known as [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby). In this state, the system can very quickly switch from a low-power state to high-power state in response to hardware and network events. **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Sleep | *S1*<br> *S2*<br> *S3* | The system appears to be off. The amount of power consumed in states *S1-S3* is less than *S0* and more than *S4*. *S3* consumes less power than *S2*, and *S2* consumes less power than *S1*. Systems typically support one of these three states, not all three.<br><br> In states *S1-S3*, volatile memory is kept refreshed to maintain the system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device.<br><br> *Hybrid sleep*, used on desktops, is where a system uses a hibernation file with *S1-S3*. The hibernation file saves the system state in case the system loses power while in sleep.<br><br> **Note:** SoC systems that support Modern Standby don't use *S1-S3*. | 
| Hibernate | *S4* | The system appears to be off. Power consumption is reduced to the lowest level. The system saves the contents of volatile memory to a hibernation file to preserve system state. Some components remain powered so the computer can wake from input from the keyboard, LAN, or a USB device. The working context can be restored if it's stored on nonvolatile media.<br><br> *Fast startup* is where the user is logged off before the hibernation file is created. This allows for a smaller hibernation file, more appropriate for systems with less storage capabilities. | 
| Soft off | *S5* | The system appears to be off. This state is comprised of a full shutdown and boot cycle. | 
| Mechanical off | *G3* | The system is completely off and consumes no power. The system returns to the working state only after a full reboot. | 

## Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "AllowHibernate" = 4294967295; // PopAllowHibernateReg, REG_DWORD
    "EnableMinimalHiberFile" = 0; // PopEnableMinimalHiberFile, REG_DWORD
    "ForceMinimalHiberFile" = 0; // PopForceMinimalHiberFile, REG_DWORD
    "HibernateChecksummingEnabled" = 1; // PopHiberChecksummingEnabledReg 
    "HibernateEnabledDefault" = 1; // PopHiberEnabledDefaultReg 
    "PromoteHibernateToShutdown" = 0; // PopPromoteHibernateToShutdown 
    "SkipHibernateMemoryMapValidation" = 4294967295; // PopEnableHibernateMemoryMapValidationOverride (4294967295)

    "HibernateEnabled" = 1; // that's the value 'powercfg /hibernate off' would set

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost" = 0; // unk_140FC5234, if nonzero, PopHibernateEvaluation treats hibernation as force disabled
    "Policy" = 0; // PopHiberForceDisabledReg, ^
```

## Disable Hiberboot

Fast Startup (also called *hiberboot*/*hybrid shutdown*) is a shutdown mechamism built on hibernation. It logs off the interactive user sessions first, then hibernates the kernel session and loaded kernel mode drivers. The next boot can skip much of kernel and driver initialization. Restart doesn't use Fast Startup, it performs a full boot cycle so drivers and Windows components are initialized from a new state. For `shutdown.exe`, `/s /t 0` = full shutdown, while `/s /hybrid /t 0` = hybrid shutdown.

Boot Manager uses the `resume`, `resumeobject`, `hiberboot`, `filepath`, `filedevice` BCD elements ([bcd-edits/#valuedata-list](https://noverse.dev/docs/win-config/system/bcd-edits/#valuedata-list)) to locate the Windows Resume application and hibernation file on the next boot.

> *Fast startup is a type of shutdown that uses a hibernation file to speed up the subsequent boot. During this type of shutdown, the user is logged off before the hibernation file is created. Fast startup allows for a smaller hibernation file, more appropriate for systems with less storage capabilities.*
> *When using fast startup, the system appears to the user as though a full shutdown (S5) has occurred, even though the system has actually gone through S4. This includes how the system responds to device wake alarms.*
> *Fast startup logs off user sessions, but the contents of kernel (session 0) are written to hard disk. This enables faster boot.*
>
> — Microsoft, [System power states, Fast startup: reduced hibernation file](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#fast-startup-reduced-hibernation-file)

### Registry Values

All three values exist as shown below. [`PopReadHiberbootPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PopReadHiberbootPolicy.c) checks [`PopReadHiberbootGroupPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PopReadHiberbootGroupPolicy.c) (`\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\System`) before the setting under `Control\\Session Manager\\Power`, but only a nonzero policy value would be preferred.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "HiberbootEnabled" = 1; // PopHiberbootEnabledReg 
    "DisableIdleStatesAtBoot" = 0; // PpmIdleDisableStatesAtBoot 
    "HibernateBootOptimizationEnabled" = 0; // PopHiberBootOptimizationEnabledReg 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "HiberbootEnabled" = 1; // REG_DWORD, range 0-1

    // HybridBootAnimationTime records the boot animation duration during fast boot, HiberIoCpuTime is CPU time spent on hibernation I/O during resume, ResumeCompleteTimestamp is the system timestamp when resume from hibernation completed. So all of them are just counters and changing their data won't affect the boot.
    "HybridBootAnimationTime" = 1601; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "HiberIoCpuTime" = 0; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "ResumeCompleteTimestamp" = 0; // REG_QWORD, range 0-0xFFFFFFFFFFFFFFFF
```

```c
__int64 __fastcall PopOpenPowerKey(__int64 a1)
{
  return PopOpenKey(a1, L"Control\\Session Manager\\Power");
}
```

```c
// PopReadHiberbootPolicy.c
result = PopOpenPowerKey(&KeyHandle);
if ( result >= 0 )
{
  RtlInitUnicodeString(&DestinationString, L"HiberbootEnabled");
  if ( ZwQueryValueKey(
         KeyHandle,
         &DestinationString,
         KeyValuePartialInformation,
         &KeyValueInformation,
         0x14u,
         &ResultLength) >= 0 )
    v1 = BYTE12(KeyValueInformation);
  result = ZwClose(KeyHandle);
}
```

## Reduced HiberFile

Hibernation files are used for hybrid sleep, fast startup, and [standard hibernation](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#hibernate-state-s4). There are two types, a full and reduced size hibernation file, only fast startup can use a reduced hibernation file.

| Hibernation file type | Default size | Supports |
| --- | --- | --- |
| Full | 40% of physical memory | hibernate, hybrid sleep, fast startup |
| Reduced | 20% of physical memory | fast startup |

### Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "HiberFileSizePercent" = 100; // PopHiberFileSizePercent, REG_DWORD, 0-39 keeps the type logic, 40-100 uses the percent directly and PopSetHiberFileSize forces a full file

    // DWORD 1 = Reduced, DWORD 2 = Full, only used while HiberFileSizePercent < 40
    "HiberFileType" = 4294967295; // PopHiberFileTypeReg (4294967295)
    "HiberFileTypeDefault" = 4294967295; // PopHiberFileTypeDefaultReg (4294967295), fallback when HiberFileType is unset

// Percent<MemoryBucket><Type>, PopCalculateHiberFileSize uses the first matching RAM bucket then uses Full or Reduced percentage (when HiberFileSizePercent < 40)
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\HiberFileBucket";
    "Percent16GBFull" = 40;
    "Percent16GBReduced" = 20;
    "Percent1GBFull" = 40;
    "Percent1GBReduced" = 20;
    "Percent2GBFull" = 40;
    "Percent2GBReduced" = 20;
    "Percent32GBFull" = 40;
    "Percent32GBReduced" = 20;
    "Percent4GBFull" = 40;
    "Percent4GBReduced" = 20;
    "Percent8GBFull" = 40;
    "Percent8GBReduced" = 20;
    "PercentUnlimitedFull" = 40;
    "PercentUnlimitedReduced" = 20;
```

### PowerCFG Captures

| Option | Description |
| --- | --- |
| `powercfg /a` | **Verify the hibernation file type.** When a full hibernation file is used, the results state that hibernation is an available option. When a reduced hibernation file is used, the results say hibernation is not supported. If the system has no hibernation file at all, the results say hibernation hasn't been enabled. |
| `powercfg /h /type full` | **Change the hibernation file type to full.** This isn't recommended on systems with less than 32GB of storage. |
| `powercfg /h /type reduced` | **Change the hibernation file type to reduced.** If the command returns "the parameter is incorrect," see the following example. |
| `powercfg /h /size 0`<br> `powercfg /h /type reduced` | **Retry changing the hibernation file type to reduced.** If the hibernation file is set to a custom size greater than 40%, you must first set the size of the file to zero. Then retry the reduced configuration. |

```c
// powercfg /h /size 0
HKLM\System\CurrentControlSet\Control\Power\HiberFileSizePercent	SUCCESS	Type: REG_DWORD, Length: 4, Data: 0

// powercfg /h /type full
HKLM\System\CurrentControlSet\Control\Power\HiberFileType	SUCCESS	Type: REG_DWORD, Length: 4, Data: 2

// powercfg /h /type reduced`
HKLM\System\CurrentControlSet\Control\Power\HiberFileType	SUCCESS	Type: REG_DWORD, Length: 4, Data: 1
```

## DisableIdleStatesAtBoot

Notes on `Disable Idle States At Boot` SUBOPTION, data `-1` (`PpmIdleDisableStatesAtBoot dd 0FFFFFFFFh`) = `0`:

```cpp
if ( PpmIdleDisableStatesAtBoot == -1 )
  PpmIdleDisableStatesAtBoot = 0;
```

`0` = skips all PpmInstall*IdleStates disable writes
`1` = would write disable in `PpmInstallCoordinatedIdleStates`/`PpmInstallPlatformIdleStates`

```cpp
if ( PpmIdleDisableStatesAtBoot )
  *(_DWORD *)(v20 + 80) = 0x80000000;

```

`2` = would do the same as `1` including disable write in `PpmInstallNewIdleStates`

```cpp
if ( v20 && PpmIdleDisableStatesAtBoot == 2 )
  *(_DWORD *)(v23 + 32) = 0x80000000;
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Require use of fast startup](https://noverse.dev/policies?p=WinInit*Hiberboot) | `HKLM\Software\Policies\Microsoft\Windows\System` | `HiberbootEnabled` |


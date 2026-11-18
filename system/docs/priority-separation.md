# Priority Separation

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\PriorityControl
; ValueName = Win32PrioritySeparation
; Destination = PsRawPrioritySeparation
; Length/Type/Flags = 0

INIT:0000000140BA3E40                 dq offset aPrioritycontro ; "PriorityControl"
INIT:0000000140BA3E48                 dq offset aWin32prioritys ; "Win32PrioritySeparation"
INIT:0000000140BA3E50                 dq offset PsRawPrioritySeparation
INIT:0000000140BA3E58                 dq 3 dup(0)
```

See '[CmControlVector](https://noverse.dev/docs/win-config/system/kernel-values/#cmcontrolvector)' if you don't understand the comments.

Use my [minimal (32 bit) bitmask calculator](https://noverse.dev/terminal#bitmask) whenever you want to get/read hex/dec values.

## KiUpdateRunTime Quantum Expiration

Using `disabledynamictick` can cause the issue while [per CPU clock tick scheduling](https://noverse.dev/docs/win-config/system/timer-expiration/#enablepercpuclocktickscheduling) is enabled. As shown in the '[ClockTickIdleEstimateFix (24H2+)](https://noverse.dev/docs/win-config/system/priority-separation/#clocktickidleestimatefix-24h2)' section, 24/25H2 have a new function which seems to try to fix the issue.

Before a processor enters idle ([`PpmIdleExecuteTransition`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmIdleExecuteTransition.c)), Windows can stop its clock timer. After the processor leaves idle, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeResumeClockTimerFromIdle.c) usually programs the timer again, but with `disabledynamictick` (`KiDynamicTickDisableReason`) set, that function returns before doing so (unless something else programs the counter that means no `KeClockInterruptNotify`).

Means that stopped timer no longer sends the clock interrupt used to call [`KiUpdateRunTime`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiUpdateRunTime.c), so the running threads `CycleTime >= QuantumTarget` check isn't reached and `KPRCB.QuantumEnd` isn't set.

### ClockTickIdleEstimateFix (24H2+)

`Feature_Servicing_Kernel_ClockTickIdleEstimateFix` can make the `KClockTimerKTimerExpirationPseudoHr` deadline (`ClockTimerEntries[1]`) waking, which keeps clock interrupts running after something initially programs the timer. 23H2 always sets its low `TypeFlags` bits to `3` (active + non waking):

```c
// KiUpdateTime (23H2)

CurrentPrcb->ClockTimerState.ClockTimerEntries[1].TypeFlags |= 3u; // KClockTimerKTimerExpirationPseudoHr
```

Depending on the state of the feature, [`KiSetClockTimerKTimerDeadlines`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiSetClockTimerKTimerDeadlines.c) programs `KClockTimerKTimerExpirationPseudoHr`:

```c
// KiSetClockTimerKTimerDeadlines (25H2)

v7 = (unsigned int)Feature_Servicing_Kernel_ClockTickIdleEstimateFix__private_IsEnabledNoReportingNoInline() == 0;
result = KiSetClockTimer(a1, a2, v4, KeMinimumIncrement, 1, v7, 0);
```

```c
lkd> dd nt!Feature_Servicing_Kernel_ClockTickIdleEstimateFix__private_featureState L1
fffff802`defc3b20  00000047 // bit 0 = 1 = feature enabled

lkd> r @$t0 = dwo(nt!Feature_Servicing_Kernel_ClockTickIdleEstimateFix__private_featureState)
lkd> .printf "state=%x direct=%u enabled=%u\n", @$t0, ((@$t0 >> 1) & 1), (@$t0 & 1)
state=47 direct=1 enabled=1
```

With the feature enabled, `KClockTimerKTimerExpirationPseudoHr` has low bits `1`, so [`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KePrepareClockTimerForIdle.c) keeps/rearms the timer (its clock interrupts reach `KiUpdateRunTime`), which also explains why the issue doesn't appear the same way on 25H2 as on 23H2.

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-clocktickidleestimatefix-25h2.png?raw=true)

### Captures

I've used two CPUStress threads with *Maximum* activity, the same priority/affinity & dynamic boosts disabled, causing a permanent ready/running switch (with `WrQuantumEnd` CS reason, as they reach their quantum).

#### 23H2 (Per CPU Clock Timer Active)

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-dyntick-on-perfmon-max.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/ps-dyntick-on-mxa.png?raw=true)

#### 23H2 (Per CPU Clock Timer Stopped)

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-dyntick-off-perfmon-max.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/ps-dyntick-off-mxa.png?raw=true)

##### Busy Activity

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-dyntick-off-perfmon-busy.png?raw=true)

##### Per CPU Clock Tick Scheduling Disabled

This is just to prove that when disabling per CPU clock tick scheduling, the issue won't happen.

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-percpu-tick-scheduling-off.png?raw=true)

### QuantumTarget & Expiration

[`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitializeClock.c) sets `KiDynamicTickDisableReason` = `1` if the BCD settings include `DISABLEDYNAMICTICK`, see [Timer Expiration, KiDynamicTickDisableReason](https://noverse.dev/docs/win-config/system/timer-expiration/#kidynamictickdisablereason) for more details on the global.

```c
// KeInitializeClock (23H2)

if ( v18 && strstr(v18, "DISABLEDYNAMICTICK") )
  KiDynamicTickDisableReason = 1;
```

```c
lkd> db nt!KiDynamicTickDisableReason L1
fffff806`6d71d300  01                                               .
```

[`KiSetQuantumTargetThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiSetQuantumTargetThread.c) stores an absolute cycle target:

```c
// KiSetQuantumTargetThread (23H2)

v15 = v8 + KiCyclesPerClockQuantum * (unsigned int)*(unsigned __int8 *)(a1 + 651);
*(_QWORD *)(a1 + 32) = v15;
```

XREFs (in 23/25H2) show that only [`KeClockInterruptNotify`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeClockInterruptNotify.c) & [`KiUpdateTime`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiUpdateTime.c) call `KiUpdateRunTime`, which programs `KClockTimerQuantumEnd` (`ClockTimerEntries[3]`), checks the current threads accumulated cycles and requests a dispatch interrupt when the target is reached:

```c
// KiUpdateRunTime (25H2)

CurrentPrcb->ClockTimerState.ClockTimerEntries[3].TypeFlags |= 3u; // KClockTimerQuantumEnd, low bits now 3
CurrentPrcb->ClockTimerState.ClockTimerEntries[3].DueTime = v28;
CurrentPrcb->ClockTimerState.ClockTimerEntries[3].TolerableDelay = v26;

result = (LARGE_INTEGER)CurrentThread->CycleTime;
if ( result.QuadPart >= CurrentThread->QuantumTarget )
  goto LABEL_16;

// other checks & the non expired return excluded
LABEL_16:
CurrentPrcb->QuantumEnd = 1;
```

The idle function shown below only treats entries whose low bits equal `1` as waking deadlines, so it skips `KClockTimerQuantumEnd` and that deadline doesn't keep the clock timer armed while the processor is idle.

### ClockTimer not Rearmed

Before the processor enters idle, 23H2 uses [`KePrepareNonClockOwnerForIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KePrepareNonClockOwnerForIdle.c) in per CPU scheduling, while 25H2 uses [`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KePrepareClockTimerForIdle.c).

If per CPU clock tick scheduling are disabled, `KiUpdateRunTime` doesn't program `KClockTimerQuantumEnd` & the clock owner uses [`KiForwardTick`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiForwardTick.c) to send ticks to the other processors, so their quantum checks don't depend on that per CPU timer being rearmed (see '[Per CPU Clock Tick Scheduling Disabled](https://noverse.dev/docs/win-config/system/priority-separation/#per-cpu-clock-tick-scheduling-disabled)' capture).

You can see whether per CPU scheduling is used via ([Timer Expiration, EnablePerCpuClockTickScheduling](https://noverse.dev/docs/win-config/system/timer-expiration/#enablepercpuclocktickscheduling) for more details):

```c
lkd> db nt!KiDynamicTickDisableReason L1
fffff806`6d71d300  01                                               .
lkd> db nt!KiClockTimerPerCpu L1
fffff806`6d71eaa4  01                                               .
lkd> db nt!KiSerializeTimerExpiration L1
fffff806`6d71d03c  01                                               .
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff806`6d71ea45  01                                               .
```

Both read the seven clock entries and only keep the timer armed if one has low `TypeFlags` bits equal to `1`:

```c
// KePrepareNonClockOwnerForIdle (23H2)

while ( (v8->TypeFlags & 3) != 1 )
{
  ++v7;
  v8 += 16;
  if ( v7 >= 7 )
  {
    v9 = KeGetCurrentPrcb();
    if ( (v9->PendingTickFlags & 1) != 0 )
    {
      ((void (__fastcall *)($7B5CACFB46652731FD5E219DB549FF78 *))off_140C01C98[0])(v8);
      v9->PendingTickFlags &= ~1u;
      v9->ClockTimerState.ClockActive = 0;
    }
    if ( v9->ClockOwner )
      v9->ClockOwner = 0;

    NextTickDueTime = -1LL;
    goto LABEL_20;
  }
}
```

As shown above `KClockTimerQuantumEnd` has low bits `3`, so the function skips it. If no other entry needs to wake the processor, the function stops the hardware timer and clears `ClockActive`/`ClockOwner`. When the processor leaves idle, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KeResumeClockTimerFromIdle.c) checks `KiDynamicTickDisableReason` before it calls [`KiSetClockTimer`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiSetClockTimer.c):

```c
// KeResumeClockTimerFromIdle (25H2)

if ( (_BYTE)KiDynamicTickDisableReason )
  return (char)v3;

// not reached with disabledynamictick
KiSetClockTimer(
  (__int64)CurrentPrcb,
  InterruptTimePrecise,
  -(__int64)(unsigned int)KeQuantumEndTimerIncrement,
  KeMinimumIncrement,
  3, // KClockTimerQuantumEnd
  1,
  0);
```

23H2 has the same early return, but uses `KeMaximumIncrement` for the deadline.

### WrQuantumEnd & WrDispatchInt

[`KiDispatchInterrupt`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiDispatchInterrupt.c) reads the quantum flag first, if its set, it calls [`KiQuantumEnd`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/KiQuantumEnd.c). Its separate `NextThread` branch stores reason `31`:

```c
// KiDispatchInterrupt (25H2)

result = CurrentPrcb->QuantumEnd;
if ( result )
{
  CurrentPrcb->QuantumEnd = 0;
  return KiQuantumEnd();
}
else if ( CurrentPrcb->NextThread )
{
```

```c
// KiDispatchInterrupt, NextThread branch

*(_BYTE *)(CurrentThread + 643) = 31;
KiQueueReadyThread(CurrentPrcb);
```

```c
// KiQuantumEnd (25H2)

*(_BYTE *)(v4 + 643) = 30;
KiQueueReadyThread(v102);
```

## PsChangeQuantumTable

As everything below will reference to that function at some point, I'll quickly explain what it does:

1. Reads and clamps `PsPrioritySeparation`
2. Selects fixed/variable quantums
3. Selects short/long table
4. Enables/disables job scheduling class QuantumReset values (enabled if fixed+long)
5. Goes through active processes and updates their QuantumReset values (optional)

## PsPrioritySeparation (`1:0`)

The priority applies to dynamic priorities below the RT (real time) range and is capped at priority `15`, disabling dynamic priority boosts for a thread/process would also prevent this FG boost. The quantum unit change is obviously only visible when the variable table is used, as all three in a fixed table are the same, so changing the low bits doesn't change its quantum. [`PsChangeQuantumTable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PsChangeQuantumTable.c) clamps the field and saves it in `PsPrioritySeparation`:

```c
// PsChangeQuantumTable

v3 = a2 & 3; // bits 1:0
if ( v3 >= 2 )
  v3 = 2;
PsPrioritySeparation = v3; // range 0-2
```

| Bits `1:0` | `PsPrioritySeparation` | Meaning |
| --- | ---: | --- |
| `00` | `0` | No FG priority boost (index `0`), "*The threads of foreground processes get the same amount of processor time as the threads of background processes and as the threads of processes with a priority class of Idle.*" |
| `01` | `1` | `+1` priority boost (index `1`), "*The threads of foreground processes get twice the processor time as the threads of background processes each time they are scheduled for the processor.*" |
| `10` | `2` | `+2` priority boost (index `2`), "*The threads of foreground processes get three times the processor time as the threads of background processes each time they are scheduled for the processor.*" |
| `11` | `2` | Same as `10` as it's clamped |

```c
lkd> dd PsPrioritySeparation L1
fffff804`1a31ec7c  00000000 // 0x18 (00)

lkd> dd PsPrioritySeparation L1
fffff801`2611ec7c  00000001 // 0x19 (01)

lkd> dd PsPrioritySeparation L1
fffff802`6b91ec7c  00000002 // 0x1A (10)

lkd> dd PsPrioritySeparation L1
fffff801`2971ec7c  00000002 // 0x1B (11)
```

### Index Table

The mentioned index above is used for the quantum table, BG (background) processes use index `0`, FG processes use the index from `PsPrioritySeparation` (`a2` is the process state, `2` for FG, `0` otherwise):

```c
// PspComputeQuantum

v2 = *(_QWORD *)(a1 + 1296);
if ( !v2 || !PspUseJobSchedulingClasses )
  return *((_BYTE *)&PspForegroundQuantum + (PsPrioritySeparation & (unsigned int)-(a2 != 0))); // a2 == 0 uses index 0
```

The ms were calculated while `KeMaximumIncrement` (maximum time between clock interrupts) = `2625a`/`15.625 ms` (`~5.208 ms` per QU on 23H2, `~0.868 ms` per 24H2 `ShortThreadQuantum` QU), see '[Cycles per QU](https://noverse.dev/docs/win-config/system/priority-separation/#cycles-per-qu)'.

As shown in the [captures](https://noverse.dev/docs/win-config/system/priority-separation/#duration-captures) below, using *Variable* on 24H2+ will cause threads to get their QU from the [`BamQosLevel`](https://noverse.dev/docs/win-config/system/priority-separation/#qos-quantum-override-bamqoslevel) field, only if that field has a value of `8+` the QU of the table below are used. If using fixed intervals, the QU from the table are used.

| Quantum table | Index `0` | Index `1` | Index `2` |
| --- | ---: | ---: | ---: |
| Variable short | `6` QU (`31.250 ms`) | `12` QU (`62.500 ms`) | `18` QU (`93.750 ms`) |
| Variable short (`ShortThreadQuantum`) | `2` QU (`1.736 ms`) | `4` QU (`3.472 ms`) | `36` QU (`31.250 ms`) |
| Fixed short | `18` QU (`93.750 ms`) | `18` QU (`93.750 ms`) | `18` QU (`93.750 ms`) |
| Fixed short (`ShortThreadQuantum`) | `18` QU (`15.625 ms`) | `18` QU (`15.625 ms`) | `18` QU (`15.625 ms`) |
| Variable long | `12` QU (`62.500 ms`) | `24` QU (`125.000 ms`) | `36` QU (`187.500 ms`) |
| Variable long (`ShortThreadQuantum`) | `4` QU (`3.472 ms`) | `8` QU (`6.944 ms`) | `72` QU (`62.500 ms`) |
| Fixed long | `36` QU (`187.500 ms`) | `36` QU (`187.500 ms`) | `36` QU (`187.500 ms`) |
| Fixed long (`ShortThreadQuantum`) | `36` QU (`31.250 ms`) | `36` QU (`31.250 ms`) | `36` QU (`31.250 ms`) |

Client uses variable + short ("*Performance Options: Programs*) and server fixed + long ("*Performance Options: Background services*") by default.

```c
// Background services
SystemPropertiesAdvanced.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\PriorityControl\Win32PrioritySeparation	Type: REG_DWORD, Length: 4, Data: 24 // 0x18

// Programs
SystemPropertiesAdvanced.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\PriorityControl\Win32PrioritySeparation	Type: REG_DWORD, Length: 4, Data: 38 // 0x26
```

#### Duration Captures

Same setup as in '[KiUpdateRunTime, Captures](https://noverse.dev/docs/win-config/system/priority-separation/#captures)', to cause threads to exhaust their quantum.

##### 6/18 QU, 23H2

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-6-18-23H2.png?raw=true)

##### 18 QU, 23H2

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-18-23H2.png?raw=true)

##### 6/18 QU, 25H2

As shown in the '[QoS Quantum Override (BamQosLevel)](https://noverse.dev/docs/win-config/system/priority-separation/#qos-quantum-override-bamqoslevel)', whenever using the variable table on 24H2+, the threads get their QU from the BamQosField.

This capture also proofs that, as it uses `31.250ms` all the time (FG/BG).

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-6-18-25H2.png?raw=true)

##### 18 QU, 25H2

When using the fixed table entries on 24H2+, then [`BamQosLevel` isn't used](https://noverse.dev/docs/win-config/system/priority-separation/#qos-quantum-override-bamqoslevel), and all threads use 18/36 QU depending on the interval.

![](https://github.com/nohuto/win-config/blob/main/system/images/ps-18-25H2.png?raw=true)

#### Default Bitmasks

![](https://github.com/nohuto/win-config/blob/main/system/images/0x2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/0x26.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/0x18.png?raw=true)

To see whenever your current build is a client/server, use:

```powershell
(Get-CimInstance Win32_OperatingSystem).ProductType
```

- `0` = Unknown
- `1` = WorkStation (client)
- `2` = DomainController
- `3` = Server

Or display it directly via reading [`MmIsThisAnNtAsSystem`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmisthisanntassystem), see '[Long/Short Interval (`5:4`)](https://noverse.dev/docs/win-config/system/priority-separation/#longshort-interval-54)' section.

Or via the `ProductType` value:

```c
// WinNT = Windows client
// LanmanNT = Windows server (domain controller)
// ServerNT = Windows server (server only)

HKLM\SYSTEM\CurrentControlSet\Control\ProductOptions : ProductType
```

### FG Priority Boost

[`KiApplyForegroundBoostThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiApplyForegroundBoostThread.c) shows the calculation, add `PsPrioritySeparation` to the base priority & cap the dynamic priority at `15`.

```c
// KiApplyForegroundBoostThread

v10 = PsPrioritySeparation + *(_BYTE *)(a1 + 563); // PsPrioritySeparation + BasePriority
if ( v10 >= 16 )
  v10 = 15;
```

The same separation is included in the priority when [`KiDeferredReadySingleThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiDeferredReadySingleThread.c) readies a FG thread after a wait:

```c
// KiDeferredReadySingleThread

LABEL_64:
v35 += (char)PsPrioritySeparation; // add PsPrioritySeparation to the priority
```

#### ForceForegroundBoostDecay

Controls whether dynamic priority decay can remove the FG priority boost added by `PsPrioritySeparation`, changing it to `1` allows scheduler functions such as [`KiQuantumEnd`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KiQuantumEnd.c) to remove that boost during priority decay. If the process is still FG (and the thread can still get dynamic priority boosts), [`KiTryScheduleNextForegroundBoost`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KiTryScheduleNextForegroundBoost.c) schedules the boost to be applied again (leaving the FG obviously removes the boost no matter what the value is set to).

```asm
INIT:0000000140BA67E0                 dq offset aSessionManager_5 ; "Session Manager\\Kernel"
INIT:0000000140BA67E8                 dq offset aForceforegroun ; "ForceForegroundBoostDecay"
INIT:0000000140BA67F0                 dq offset KiSchedulerForegroundBoostDecayPolicy
INIT:0000000140BA67F8                 dq 3 dup(0)
```

Default is `0` ([compare PE init value](https://noverse.dev/diff?kind=globals&left=11-23H2&right=11-24H2&module=ntoskrnl&name=KiSchedulerForegroundBoostDecayPolicy&mode=side-by-side)), which keeps the boost while the process is in FG:

```c
lkd> dd KiSchedulerForegroundBoostDecayPolicy L1
fffff802`4711d31c  00000000
```

##### Force Decay

Both PerfMon captures aren't the same as the ones shown in MXA, I've also noticed that the GUI thread doesn't seem to be impacted from it. As written above, the scheduler applies the boost of `PsPrioritySeparation` again, if its still in FG (CPUSTRES was in FG all the time here).

![](https://github.com/nohuto/win-config/blob/main/system/images/force-decay.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/force-cpustres.png?raw=true)

---

![](https://github.com/nohuto/win-config/blob/main/system/images/force-decay-perfmon.png?raw=true)

##### Don't Force Decay

![](https://github.com/nohuto/win-config/blob/main/system/images/dont-force-decay.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/dont-force-cpustres.png?raw=true)

---

![](https://github.com/nohuto/win-config/blob/main/system/images/dont-force-decay-perfmon.png?raw=true)

### Watching the FG Priority Boost

I'll use WPR below to capture the boost, if you're not familiar with WPA/MXA, you can look at the boost live via perfmon, follow '[EXPERIMENT: Watching foreground priority boosts and decays](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)' if you want to do it that way instead.

1. Set bits `1:0` to the separation you want to look at
2. Start [CPUSTRES](https://learn.microsoft.com/en-us/sysinternals/downloads/cpustres) and set worker thread 1 to `Busy`
3. Open WPRUI, select: ('Light' includes `CSwitch`, `ReadyThread`, `ThreadPriority`)

![](https://github.com/nohuto/win-config/blob/main/system/images/wpr-win32prio.png?raw=true)

4. Move CPUSTRES between FG/BG several times
5. Stop the capture

![](https://github.com/nohuto/win-config/blob/main/system/images/0-sep.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/1-sep.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/2-sep.png?raw=true)

#### PerfMon Example

![](https://github.com/nohuto/win-config/blob/main/system/images/perfmon-PsPrioritySeparation.png?raw=true)

#### WrQuantumEnd CS

You can also see if a [context switch](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/context-switching/) was caused by `WrQuantumEnd` via '*Processes and Threads - CS Reason*', but note that there've to be two threads with the same priority & processor, otherwise the thread will just get another quantum without a context switch. In the example below I've created two threads with the same priority/affinity using [CPUStress](https://github.com/zodiacon/CPUStress), but as you can see none ever needed more than its quantum in the 10sec record (FG/BG 36QU was used here).

See '[Thread States](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/thread-states/)' for more details on the topic & a example on how [`WrQuantumEnd`](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/context-switching/#wrquantumend) works, and when the `WrQuantumEnd` reason is used (beside `CycleTime >= QuantumTarget`).

![](https://github.com/nohuto/win-config/blob/main/system/images/WrQuantumEnd-23H2.png?raw=true)

##### 25H2 Max Activity

This is just a "extreme" example of what it could cause, using two thread with maximum activity (runs continuously, no sleep) + same priority + same affinity. This was captured while the windows default (`0x2`) was used, means BG threads have a time of `1.736 ms` (CPUStress was in BG):

![](https://github.com/nohuto/win-config/blob/main/system/images/WrQuantumEnd-25H2-Default.png?raw=true)

#### _KTHREAD Priority

You can practically also look at it via WinDbg, but rather use WPR.

```c
// 0x2A
lkd> !process 0 4 CPUSTRES.exe
PROCESS ffffb9878e2023c0
    SessionId: 1  Cid: 1c98    Peb: 004dc000  ParentCid: 0e64
    DirBase: 7159f4000  ObjectTable: ffffde0c8aed3b40  HandleCount: 197.
    Image: CPUSTRES.EXE

        THREAD ffffb9878e2300c0  Cid 1c98.1c8c  Teb: 00000000004de000 Win32Thread: ffffb9878ccb6e20 WAIT
        THREAD ffffb9878f5c2080  Cid 1c98.1cd4  Teb: 00000000004ee000 Win32Thread: 0000000000000000 RUNNING on processor 5
        THREAD ffffb9878e2e20c0  Cid 1c98.1ca8  Teb: 00000000004f2000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffb9878d9bb0c0  Cid 1c98.1c74  Teb: 00000000004f6000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffb9878e1c6080  Cid 1c98.0cf4  Teb: 00000000004fa000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffffb9878f5c2080 Priority
   +0x0c3 Priority : 8 '' // BG
lkd> .sleep 0n3000; dt _KTHREAD ffffb9878f5c2080 Priority
   +0x0c3 Priority : 10 '' // FG

// 0x18
lkd> !process 0 4 CPUSTRES.exe
PROCESS ffff800f510cf300
    SessionId: 1  Cid: 0778    Peb: 00259000  ParentCid: 0f70
    DirBase: 7ca6b5000  ObjectTable: ffffaf88087a9b40  HandleCount: 199.
    Image: CPUSTRES.EXE

        THREAD ffff800f50dcb080  Cid 0778.1bec  Teb: 000000000025b000 Win32Thread: ffff800f5068b830 WAIT
        THREAD ffff800f50dc90c0  Cid 0778.1bb4  Teb: 0000000000263000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff800f4f96b080  Cid 0778.1bfc  Teb: 000000000026b000 Win32Thread: 0000000000000000 RUNNING on processor 5
        THREAD ffff800f4f96a080  Cid 0778.1bc8  Teb: 000000000026f000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff800f4f969080  Cid 0778.1b30  Teb: 0000000000273000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff800f4f968080  Cid 0778.1af8  Teb: 0000000000277000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff800f50dca040  Cid 0778.0fd0  Teb: 000000000027b000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff800f4f96c080  Cid 0778.0d44  Teb: 000000000027f000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffff800f4f96b080 Priority
nt!_KTHREAD
   +0x0c3 Priority : 8 '' // BG
lkd> .sleep 0n3000; dt _KTHREAD ffff800f4f96b080 Priority
nt!_KTHREAD
   +0x0c3 Priority : 8 '' // FG
```

#### Game Mode

If you're using a priority boost via `PsPrioritySeparation` while having game mode enabled (default), the FG boost doesn't work (for processes that register with game mode). This issue seems to exist on 23H2, while on 25H2 its fixed.

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-game.png?raw=true)

See '[FG Boost with Game Mode](https://noverse.dev/docs/win-config/system/game-mode/#fg-boost-with-game-mode)' for more captures & details.

## Quantum

Note that a thread might not even get to complete its quantum, however, because Windows implements a preemptive scheduler. That is, if another thread with a higher priority becomes ready to run, the currently running thread might be preempted before finishing its time slice. In fact, a thread can be selected to run next and be preempted before even beginning its quantum.

> "*A quantum is the amount of time a thread is permitted to run before Windows checks to see whether another thread at the same priority is waiting to run. If a thread completes its quantum and there are no other threads at its priority, Windows permits the thread to run for another quantum.*
>
> *On client versions of Windows, threads run for two clock intervals by default. On server systems, threads run for 12 clock intervals by default. The rationale for the longer default value on server systems is to minimize [context switching](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/context-switching/). By having a longer quantum, server applications that wake up because of a client request have a better chance of completing the request and going back into a wait state before their quantum ends.*
>
> *The length of the clock interval varies according to the hardware platform. The frequency of the clock interrupts is up to the HAL, not the kernel. For example, the clock interval for most x86 uniprocessors is about 10 milliseconds (note that these machines are no longer supported by Windows and are used here only for example purposes), and for most x86 and x64 multiprocessors it is about 15 milliseconds. This clock interval is stored in the kernel variable KeMaximumIncrement as hundreds of nanoseconds. Although threads run in units of clock intervals, the system does not use the count of clock ticks as the gauge for how long a thread has run and whether its quantum has expired. This is because thread run-time accounting is based on processor cycles. When the system starts up, it multiplies the processor speed (CPU clock cycles per second) in hertz (Hz) by the number of seconds it takes for one clock tick to fire (based on the KeMaximumIncrement value described earlier) to calculate the number of clock cycles to which each quantum is equivalent. This value is stored in the kernel variable KiCyclesPerClockQuantum.*"
>
> — Windows Internals, [E7, P1: 'Quantum'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

The client default of two clock intervals is the background (index `0`) value, see '[Index Table](https://noverse.dev/docs/win-config/system/priority-separation/#index-table)'. The quote above is valid on 23H2, but with `ShortThreadQuantum` on 24H2, it makes each unit six times smaller (`clock interval / 18` instead of `clock interval / 3`) and adds a per thread `BamQosLevel` override (see '[QoS Quantum Override (`BamQosLevel`)](https://noverse.dev/docs/win-config/system/priority-separation/#qos-quantum-override-bamqoslevel)').

### Threads QuantumReset

You can display the current `QuantumReset` of threads via `dt _KTHREAD <thread address> QuantumReset`, I've used `0x18` while running the commands below.

```c
// 0x18
lkd> db PspForegroundQuantum L3
fffff805`45954bec  24 24 24                                         $$$

lkd> !process 0 4 CPUSTRES.exe
PROCESS ffff8084c5d5f080
    SessionId: 1  Cid: 1644    Peb: 00f27000  ParentCid: 0b8c
    DirBase: 73a73e000  ObjectTable: ffffdb8a6c01fc40  HandleCount: 201.
    Image: CPUSTRES.EXE

        THREAD ffff8084c125d080  Cid 1644.1694  Teb: 0000000000f29000 Win32Thread: ffff8084c4f9ec90 WAIT
        THREAD ffff8084c0ced080  Cid 1644.272c  Teb: 0000000000f2d000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084c23ba300  Cid 1644.1630  Teb: 0000000000f31000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084be291080  Cid 1644.0e10  Teb: 0000000000f35000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084c293e080  Cid 1644.15d4  Teb: 0000000000f39000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084be31f080  Cid 1644.0d28  Teb: 0000000000f3d000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084c06c1080  Cid 1644.14e0  Teb: 0000000000f41000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff8084bf5be080  Cid 1644.14bc  Teb: 0000000000f45000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffff8084c125d080 QuantumReset
   +0x28b QuantumReset : 0x24 '$'

// 0x2 (default)
lkd> db PspForegroundQuantum L3
fffff800`56354bec  06 0c 12                                         ...

lkd> !process 0 4 CPUSTRES.exe
PROCESS ffffd687c63fb380
    SessionId: 1  Cid: 09d4    Peb: 011dd000  ParentCid: 0fd0
    DirBase: 7862de000  ObjectTable: ffffe6886846cc40  HandleCount: 197.
    Image: CPUSTRES.EXE

        THREAD ffffd687c48a8080  Cid 09d4.1ad4  Teb: 00000000011df000 Win32Thread: ffffd687c6c95ed0 WAIT
        THREAD ffffd687c5949080  Cid 09d4.195c  Teb: 00000000011e3000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c2269140  Cid 09d4.19a4  Teb: 00000000011e7000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c43460c0  Cid 09d4.1a28  Teb: 00000000011eb000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c43350c0  Cid 09d4.13d0  Teb: 00000000011ef000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c70020c0  Cid 09d4.1018  Teb: 00000000011f3000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c6e75080  Cid 09d4.1b18  Teb: 00000000011f7000 Win32Thread: 0000000000000000 WAIT
        THREAD ffffd687c4f8f080  Cid 09d4.1b34  Teb: 00000000011fb000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffffd687c48a8080 QuantumReset
nt!_KTHREAD
   +0x28b QuantumReset : 0x6 '' // BG

lkd> .sleep 0n3000; dt _KTHREAD ffffd687c48a8080 QuantumReset
nt!_KTHREAD
   +0x28b QuantumReset : 0x12 '' // FG
```

This is also a practical example of "*BG (background) processes use index `0`, FG processes use the index from `PsPrioritySeparation`*" ([Index Table](https://noverse.dev/docs/win-config/system/priority-separation/#index-table)). 

### Variable/Fixed Quantum (`3:2`)

[`PsChangeQuantumTable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PsChangeQuantumTable.c) uses the variable table for `01` and the fixed table for `10`. You can imagine the difference between them like that ([process.c](https://doxygen.reactos.org/d2/d9f/ntoskrnl_2ps_2process_8c_source.html#l00031)):

```c
/* Fixed quantum table */
CHAR PspFixedQuantums[6] =
{
    /* Short quantums */
    3 * 6, /* Level 1 */
    3 * 6, /* Level 2 */
    3 * 6, /* Level 3 */
 
    /* Long quantums */
    6 * 6, /* Level 1 */
    6 * 6, /* Level 2 */
    6 * 6  /* Level 3 */
};
 
/* Variable quantum table */
CHAR PspVariableQuantums[6] =
{
    /* Short quantums */
    1 * 6, /* Level 1 */
    2 * 6, /* Level 2 */
    3 * 6, /* Level 3 */
 
    /* Long quantums */
    2 * 6, /* Level 1 */
    4 * 6, /* Level 2 */
    6 * 6  /* Level 3 */
};
```

| Bits `3:2` | Result |
| --- | --- |
| `00` | client variable, server fixed |
| `01` | variable |
| `10` | fixed |
| `11` | client variable, server fixed |

```c
// PsChangeQuantumTable (23H2)

v5 = a2 & 0xC; // bits 3:2
if ( (a2 & 0xC) != 0 )
{
  if ( v5 == 4 )
  {
    v8 = (char *)&PspVariableQuantums; // 01 (variable)
    goto LABEL_7;
  }
  if ( v5 == 8 )
  {
    v8 = PspFixedQuantums; // 10 (fixed)
    goto LABEL_7;
  }
}
```

24H2 stores the table thats used in `KiVariableQuantumEnabled`, means it sets it to `1` if variable quantums via `01`, or `00`/`11` (when client) are used.

```c
// PsChangeQuantumTable (24H2)

v6 = a2 & 0xC; // bits 3:2
if ( (a2 & 0xC) == 0 )
{
LABEL_17:
  if ( !MmIsThisAnNtAsSystem() )
    goto LABEL_7; // client default (variable)
LABEL_22:
  KiVariableQuantumEnabled = 0;
  v2 = (int *)PspFixedQuantums;
  goto LABEL_8;
}
if ( v6 != 4 )
{
  if ( v6 == 8 )
    goto LABEL_22; // 10 = fixed
  goto LABEL_17; // 11 = default
}
LABEL_7:
KiVariableQuantumEnabled = 1; // 01/client default
```

See '[QoS Quantum Override (`BamQosLevel`)](https://noverse.dev/docs/win-config/system/priority-separation/#qos-quantum-override-bamqoslevel)' to understand what `KiVariableQuantumEnabled` is used for.

### Long/Short Interval (`5:4`)

Each table has six bytes, the first three are the short entries, the last three are the long entries, see '[Index Table](https://noverse.dev/docs/win-config/system/priority-separation/#index-table)' for the length differences.

| Bits `5:4` | Meaning |
| --- | --- |
| `00` | client short, server long |
| `01` | long |
| `10` | short |
| `11` | client short, server long |

```c
// PsChangeQuantumTable

v9 = a2 & 0x30; // bits 5:4
if ( !v9 )
{
LABEL_8:
  if ( !MmIsThisAnNtAsSystem() ) // FALSE on client, TRUE on server
    goto LABEL_9;
  goto LABEL_22;
}
if ( v9 != 16 )
{
  if ( v9 == 32 )
    goto LABEL_9; // 10 = first three (short)
  goto LABEL_8;
}
LABEL_22:
v8 += 3; // 01 = last three (long)
LABEL_9:
PspForegroundQuantum = *(_WORD *)v8;
result = v8[2]; // copy selected three entries
```

Whenever using `00`/`11`, you can display the state of [`MmIsThisAnNtAsSystem`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmisthisanntassystem) (which is a bool as shown below) via:

```c
lkd> u nt!MmIsThisAnNtAsSystem L2
nt!MmIsThisAnNtAsSystem:
fffff802`63c907d0 8a0516caa800    mov     al,byte ptr [nt!MmRegistryState+0x2c (fffff802`6471d1ec)]
fffff802`63c907d6 c3              ret
lkd> dd fffff802`6471d1ec L1
fffff802`6471d1ec  00000000 // FALSE
```

```c
// mmsup.c (ReactOS)

BOOLEAN
NTAPI
MmIsThisAnNtAsSystem(VOID)
{
    /* Return if this is a server system */
    return MmProductType & 0xFF;
}
```
```c
// mminit.c

/* These values store the type of system this is (small, med, large) and if server */
ULONG MmProductType;
MM_SYSTEMSIZE MmSystemSize;
```

### Quantum Units (23H2)

Without the 24H2 `ShortThreadQuantum` function, one QU is one third of the maximum clock interval. [`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitSystem.c) calculates the related processor cycle count:

```c
// KeInitSystem

v17 = *(unsigned int *)(KiProcessorBlock[0] + 68); // processor frequency (MHz)
v18 = v17 * (unsigned __int64)(unsigned int)KeMaximumIncrement / 0xA; // cycles per maximum clock interval
KiShortExecutionCycles = v18 / 0xF0;
KiCyclesPerClockQuantum = v18 / 3; // processor cycles shown as a QU
```

#### PspVariableQuantums/PspFixedQuantums

Compare the output to the '[Index Table](#index-table)' (or the table below) and you'll see the relations. `db` shows hexadecimal bytes, means e.g. `24 24 24` are three `0x24` (`36`) entries.

```c
lkd> db PspVariableQuantums L6
fffff805`45677ae0  06 0c 12 0c 18 24                                .....$

lkd> dq PspVariableQuantums L1
fffff805`45677ae0  00002418`0c120c06

lkd> db PspFixedQuantums L6
fffff805`45677a4c  12 12 12 24 24 24                                ...$$$

// 0x18

lkd> db PspForegroundQuantum L3
fffff805`45954bec  24 24 24                                         $$$
```

| Table | Short (`PsPrioritySeparation` 0/1/2) | Long (`PsPrioritySeparation` 0/1/2) |
| --- | --- | --- |
| Variable | `6 / 12 / 18` units = `2 / 4 / 6` clock intervals | `12 / 24 / 36` units = `4 / 8 / 12` clock intervals |
| Fixed | `18 / 18 / 18` units = `6` clock intervals | `36 / 36 / 36` units = `12` clock intervals |

So for example, on 23H2 with short variable quantums and separation `2`, a FG process gets a reset of `18` QU (`6` clock intervals), while a BG process gets `6` QU (`2` clock intervals), the FG reset is therefore three times the BG reset.

##### Cycles per QU

This follows the Windows Internals '[EXPERIMENT: Determining the clock cycles per quantum](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)', first use `!cpuinfo` to get the processor frequency stored in the PRCB:

```c
lkd> !cpuinfo
CP  F/M/S Manufacturer  MHz PRCB Signature    MSR 8B Signature Features ArchitectureClass
 0 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 1 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 2 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 3 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 4 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 5 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 6 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 7 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 8 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
 9 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
10 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
11 25,33,2 AuthenticAMD 3700 000000000a201213                   3c3b3dff 0
```

Then combine that MHz value with the decimal `KeMaximumIncrement` (same as clockres '*Maximum timer interval*') value. `KeMaximumIncrement` is measured in 100ns units, means `0x2625A` is `156250` (`15.625 ms`), one QU is therefore `15.625 / 3 = ~5.208 ms`.

```c
lkd> dd KeMaximumIncrement L1
fffff805`4591ea54  0002625a
```

```c
lkd> ? 0n3700 * 0n156250 / 0n10 / 0n3
Evaluate expression: 19270833 = 00000000`01260cb1

lkd> dd KiCyclesPerClockQuantum L1
fffff805`4591d0d4  01260cb1
```

`/10` converts the clock interval from 100ns units to microseconds, `/3` converts that into cycles per QU, and the output should then match the `KiCyclesPerClockQuantum` read.

#### Quantum Exceptions

Most processes get their reset from the selected three entries in `PspForegroundQuantum`, but [`PspComputeQuantum`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PspComputeQuantum.c) has two exceptions, first are processes the *Idle* priority class (not the system Idle thread) which always get `6` QU. 

The other exception is for processes in a job when long + fixed is used, which select one of ten resets from `PspJobSchedulingClasses` instead of `PspForegroundQuantum`, means as every job gets class 5 (`36QU`) during `NtCreateJobObject`, processes within jobs get the same QU as FG/BG threads, but the class can be changed via `SetInformationJobObject` (classes above `5` require `SeIncreaseBasePriorityPrivilege`).

```c
lkd> db PspUseJobSchedulingClasses L1
fffff805`45954a07  01                                               . // TRUE if long + fixed

lkd> db PspJobSchedulingClasses La
fffff805`45677c48  06 0c 12 18 1e 24 2a 30-36 3c                    .....$*06< // 6, 12, 18, 24, 30, 36, 42, 48, 54, 60 QU
```

ReactOS [process.c](https://doxygen.reactos.org/d2/d9f/ntoskrnl_2ps_2process_8c_source.html#l00286) also shows these parts clearly:

```c
/* Check if we're using long fixed quantums */
if (QuantumTable == &PspFixedQuantums[3])
{
    /* Use Job scheduling classes */
      PspUseJobSchedulingClasses = TRUE;
}
else
{
    /* Otherwise, we don't */
    PspUseJobSchedulingClasses = FALSE;
}
```
```c
/* Make sure that the process isn't idle */
if (Process->PriorityClass != PROCESS_PRIORITY_CLASS_IDLE)
{
    /* Does the process have a job? */
    if ((Process->Job) && (PspUseJobSchedulingClasses))
    {
        /* Use job quantum */
        Quantum = PspJobSchedulingClasses[Process->Job->SchedulingClass];
    }
    else
    {
        /* Use calculated quantum */
        Quantum = PspForegroundQuantum[i];
    }
}
else
{
    /* Process is idle, use default quantum */
    Quantum = 6;
}
```

`PspJobSchedulingClasses` definition:

```c
CHAR PspJobSchedulingClasses[PSP_JOB_SCHEDULING_CLASSES] =
{
    1 * 6, // class 0: 6 QU = 0x06
    2 * 6, // class 1: 12 QU = 0x0C
    3 * 6, // class 2: 18 QU = 0x12
    4 * 6, // class 3: 24 QU = 0x18
    5 * 6, // class 4: 30 QU = 0x1E
    6 * 6, // class 5: 36 QU = 0x24 (default)
    7 * 6, // class 6: 42 QU = 0x2A
    8 * 6, // class 7: 48 QU = 0x30
    9 * 6, // class 8: 54 QU = 0x36
    10 * 6 // class 9: 60 QU = 0x3C
};
```

### ShortThreadQuantum (24H2+)

In 24H2+, [`KiInitializeVelocity`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KiInitializeVelocity.c) calls the `Feature_ShortThreadQuantum__private_ReportDeviceUsage` helper and then sets bit `0x40000` in `KiVelocityFlags` (without conditions):

```c
// KiInitializeVelocity
Feature_ShortThreadQuantum__private_ReportDeviceUsage();
KiVelocityFlags |= 0x40000u;
```

```c
lkd> ? dwo(nt!KiVelocityFlags) & 0x40000 // 25H2
Evaluate expression: 262144 = 00000000`00040000 // 0x40000 = ShortThreadQuantum used
```

With that flag, [`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KeInitSystem.c) divides the older quantum unit by another six:

```c
// KeInitSystem
if ( (KiVelocityFlags & 0x40000) != 0 )
{
  KiCyclesPerClockQuantum = (unsigned int)v17 / 6; // clock interval / 18
  KiLockQuantumTarget = 2 * ((unsigned int)v17 / 6);
}
```

It also causes [`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KeInitializeClock.c) to set `KeQuantumEndTimerIncrement` (doesn't exist in 23H2) to `1.740 ms`:

```c
// KeInitializeClock

v6 = KeMaximumIncrement;
if ( (KiVelocityFlags & 0x40000) != 0 )
  v6 = 17400; // 1.740 ms
KiTimeUpdateTryAcquireTickLock = 1;
KeQuantumEndTimerIncrement = v6;
```

Clock interrupts call [`KiUpdateRunTime`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KiUpdateRunTime.c), which checks the running threads quantum, 23H2 uses the normal clock interval (`KeMaximumIncrement`, up to `15.625 ms`), 24H2 caps the requested quantum end clock interrupt interval (`KeQuantumEndTimerIncrement`) at `1.740 ms` (which isn't good).

```asm
PAGE:0000000140B3D09C PspVariableQuantums_With_ShortQuantum dd 4240402h
PAGE:0000000140B3D0A0                 db 8, 48h, 2 dup(0)
PAGE:0000000140B3D0A4 PspVariableQuantums dd 0C120C06h
PAGE:0000000140B3D0A8                 dq 2418h, 100000041h
PAGE:0000000140B3CD78 PspFixedQuantums db 3 dup(12h)
PAGE:0000000140B3CD7B                 db 3 dup(24h), 2 dup(0)
```

```c
// 23H2
lkd> db nt!PspForegroundQuantum L3
fffff803`6f954bec  06 0c 12                                         ... // 6, 12, 18

// 25H2
lkd> db nt!PspForegroundQuantum L3
fffff806`739d8b54  02 04 24                                         ..$ // 2, 4, 36
lkd> db nt!PspVariableQuantums_With_ShortQuantum L6
fffff806`7353b3ac  02 04 24 04 08 48                                ..$..H // 2, 4, 36, 4, 8, 72
```

Means with the `clock interval / 18` unit, the table now is:

| Table | Short (`PsPrioritySeparation` 0/1/2) | Long (`PsPrioritySeparation` 0/1/2) |
| --- | --- | --- |
| Variable | `2 / 4 / 36` = `1/9 / 2/9 / 2` clock intervals | `4 / 8 / 72` = `2/9 / 4/9 / 4` clock intervals |
| Fixed | `18 / 18 / 18` = `1` clock interval | `36 / 36 / 36` = `2` clock intervals |

#### [QoS](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service) Quantum Override (`BamQosLevel`)

See '[Duration Captures, 6/18 QU, 25H2](https://noverse.dev/docs/win-config/system/priority-separation/#618-qu-25h2)' for a capture showing that threads use their `BamQosLevel` to get the QU, instead of the 6 (BG)/18 (FG) QU.

`BamQosLevel` override doesn't use the `PspVariableQuantums`/`PspFixedQuantums` tables, those still fill `PspForegroundQuantum`, which [`PspComputeQuantum`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/PspComputeQuantum.c) uses to get the stored quantum reset (except for idle class & job scheduling class). When `ShortThreadQuantum` and variable quantums are used, [`KiQueryQuantumReset`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/ntoskrnl/KiQueryQuantumReset.c) (exists since 24H2) can instead return a QoS reset (fixed quantums set `KiVariableQuantumEnabled` to `0` and won't use that override, see '[18 QU, 25H2](https://noverse.dev/docs/win-config/system/priority-separation/#18-qu-25h2)' capture). `_KTHREAD.BamQosLevel` is at `0x204`, which is the `a1 + 516` byte read below.

```c
// KiQueryQuantumReset

v1 = *(unsigned __int8 *)(a1 + 651); // stored QuantumReset
if ( (KiVelocityFlags & 0x40000) != 0 && KiVariableQuantumEnabled )
{
  v2 = *(unsigned __int8 *)(a1 + 516); // BamQosLevel
  if ( !v2 )
    return 36; // High
  v3 = v2 - 1;
  if ( !v3 )
    return 18; // Medium
  v4 = v3 - 1;
  if ( !v4 )
    return 2; // Low
  v5 = v4 - 1;
  if ( !v5 )
    return 36; // Multimedia
  v6 = v5 - 1;
  if ( !v6 )
    return 36; // Deadline
  v8 = v6 - 1;
  if ( !v8 || (unsigned int)(v8 - 1) <= 1 )
    return 2; // Eco/Utility/Dynamic
}
return v1; // use stored QuantumReset for 8+
```

```powershell
nohuto@ENDLESS:~/Desktop$ $a = [Reflection.Assembly]::LoadFrom('C:\Program Files (x86)\Windows Kits\10\Windows Performance Toolkit\CustomDataSources\XPerf\Microsoft.Windows.EventTracing.Cpu.dll')
nohuto@ENDLESS:~/Desktop$ $t = $a.GetType('Microsoft.Windows.EventTracing.Cpu.QualityOfServiceLevel')
nohuto@ENDLESS:~/Desktop$ [Enum]::GetValues($t) | ForEach-Object { "{0} = {1}" -f $_, [int]$_ }
High = 0
Medium = 1
Low = 2
Multimedia = 3
Deadline = 4
Eco = 5
Utility = 6
Dynamic = 7
```

Look at '[Quality of Service levels](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service#quality-of-service-levels)' for the meaning of each QoS level.

With the `clock interval / 18` unit, the `QuantumReset` are:

| `BamQosLevel` | QoS | Reset | Time |
| --- | --- | --- | --- |
| `0` | High | `36` QU | `31.250 ms` |
| `1` | Medium | `18` QU | `15.625 ms` |
| `2` | Low | `2` QU | `1.736 ms` |
| `3` | Multimedia | `36` QU | `31.250 ms` |
| `4` | Deadline | `36` QU | `31.250 ms` |
| `5` | Eco | `2` QU | `1.736 ms` |
| `6` | Utility | `2` QU | `1.736 ms` |
| `7` | Dynamic | `2` QU | `1.736 ms` |
| `8+` | ? | stored `QuantumReset` | table dependent |

It seems to be possible to display the current `BamQosLevel` of a thread via `_KTHREAD <thread address> BamQosLevel`:

```c
lkd> !process 0 4 CPUStress.exe
PROCESS ffff9b82c556f080
    SessionId: none  Cid: 37d4    Peb: 53b4829000  ParentCid: 1870
    DirBase: 2b7cb7000  ObjectTable: ffffe48e828562c0  HandleCount: 201.
    Image: CPUStress.exe

        THREAD ffff9b82c556e080  Cid 37d4.37d8  Teb: 00000053b482a000 Win32Thread: ffff9b82c4e95190 WAIT
        THREAD ffff9b82c55ae080  Cid 37d4.37ec  Teb: 00000053b4832000 Win32Thread: 0000000000000000 RUNNING on processor 3
        THREAD ffff9b82c55ad080  Cid 37d4.37f0  Teb: 00000053b4834000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c55ac080  Cid 37d4.37f4  Teb: 00000053b4836000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c55ab0c0  Cid 37d4.37f8  Teb: 00000053b4838000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c683a040  Cid 37d4.2b54  Teb: 00000053b483e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c5cf5080  Cid 37d4.1e74  Teb: 00000053b4840000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c69b7080  Cid 37d4.2740  Teb: 00000053b4842000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffff9b82c55ae080 BamQosLevel // active worker thread
nt!_KTHREAD
   +0x204 BamQosLevel : 0x1 '' // Medium = 18QU = 15.625
lkd> dt _KTHREAD ffff9b82c556e080 BamQosLevel // GUI thread
nt!_KTHREAD
   +0x204 BamQosLevel : 0x1 ''
lkd> dt _KTHREAD ffff9b82c55ad080 BamQosLevel
nt!_KTHREAD
   +0x204 BamQosLevel : 0x1 ''

lkd> !process 0 4 dwm.exe
PROCESS ffff9b82be56a080
    SessionId: none  Cid: 05f8    Peb: 1042bd0000  ParentCid: 0430
    DirBase: 13090a000  ObjectTable: ffffe48e7ce9cbc0  HandleCount: 1652.
    Image: dwm.exe

        THREAD ffff9b82be56b080  Cid 05f8.05fc  Teb: 0000001042bd1000 Win32Thread: ffff9b82be078ea0 WAIT
        THREAD ffff9b82be5b7080  Cid 05f8.0624  Teb: 0000001042bd7000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82be6a0080  Cid 05f8.0760  Teb: 0000001042bd9000 Win32Thread: ffff9b82be6aa2c0 WAIT
        THREAD ffff9b82be909080  Cid 05f8.082c  Teb: 0000001042bdd000 Win32Thread: ffff9b82be6ad180 WAIT
        THREAD ffff9b82be90b080  Cid 05f8.083c  Teb: 0000001042bdf000 Win32Thread: ffff9b82be6ab910 WAIT
        THREAD ffff9b82be90c080  Cid 05f8.0844  Teb: 0000001042be1000 Win32Thread: ffff9b82be6ac900 WAIT
        THREAD ffff9b82be90d080  Cid 05f8.0848  Teb: 0000001042be3000 Win32Thread: ffff9b82be6adc20 WAIT
        THREAD ffff9b82be994080  Cid 05f8.08a0  Teb: 0000001042be7000 Win32Thread: ffff9b82be6ac3b0 WAIT
        THREAD ffff9b82be9d2080  Cid 05f8.08f4  Teb: 0000001042beb000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82bec6a080  Cid 05f8.0aa0  Teb: 0000001042bf1000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82bedf2080  Cid 05f8.0bc4  Teb: 0000001042bf3000 Win32Thread: ffff9b82be6ba600 WAIT
        THREAD ffff9b82bee4f080  Cid 05f8.0810  Teb: 0000001042bf5000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82bee540c0  Cid 05f8.080c  Teb: 0000001042bf7000 Win32Thread: ffff9b82be6b6860 WAIT
        THREAD ffff9b82befec0c0  Cid 05f8.0d58  Teb: 0000001042bf9000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82beff1080  Cid 05f8.0d7c  Teb: 0000001042bfb000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04c9080  Cid 05f8.0fdc  Teb: 0000001042bfd000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04ca080  Cid 05f8.0fe0  Teb: 0000001042a00000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04cb080  Cid 05f8.0fe4  Teb: 0000001042a02000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04cc080  Cid 05f8.0fe8  Teb: 0000001042a04000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04cd080  Cid 05f8.0fec  Teb: 0000001042a06000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04ce080  Cid 05f8.0ff0  Teb: 0000001042a08000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04cf080  Cid 05f8.0ff4  Teb: 0000001042a0a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04d0080  Cid 05f8.0ff8  Teb: 0000001042a0c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04d1080  Cid 05f8.0ffc  Teb: 0000001042a0e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04d2080  Cid 05f8.0850  Teb: 0000001042a10000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c04d3080  Cid 05f8.0cfc  Teb: 0000001042a12000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c02130c0  Cid 05f8.0cd0  Teb: 0000001042a14000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c021a080  Cid 05f8.0dc4  Teb: 0000001042a16000 Win32Thread: ffff9b82c39c43a0 WAIT
        THREAD ffff9b82c0421080  Cid 05f8.0f20  Teb: 0000001042a18000 Win32Thread: ffff9b82c39a8890 WAIT
        THREAD ffff9b82c03ba080  Cid 05f8.102c  Teb: 0000001042a1a000 Win32Thread: ffff9b82c019b410 WAIT
        THREAD ffff9b82c03ea080  Cid 05f8.1054  Teb: 0000001042a1c000 Win32Thread: ffff9b82c019d3f0 WAIT
        THREAD ffff9b82c03f4080  Cid 05f8.106c  Teb: 0000001042a20000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0555080  Cid 05f8.1070  Teb: 0000001042a22000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c05e6080  Cid 05f8.1080  Teb: 0000001042a24000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c06020c0  Cid 05f8.1084  Teb: 0000001042a26000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0603080  Cid 05f8.1088  Teb: 0000001042a28000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0604080  Cid 05f8.108c  Teb: 0000001042a2a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0605080  Cid 05f8.1090  Teb: 0000001042a2c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0606080  Cid 05f8.1094  Teb: 0000001042a2e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0607080  Cid 05f8.1098  Teb: 0000001042a30000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0608080  Cid 05f8.109c  Teb: 0000001042a32000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0609080  Cid 05f8.10a0  Teb: 0000001042a34000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c060a080  Cid 05f8.10a4  Teb: 0000001042a36000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c060b080  Cid 05f8.10a8  Teb: 0000001042a38000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c060c080  Cid 05f8.10ac  Teb: 0000001042a3a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c07330c0  Cid 05f8.11f4  Teb: 0000001042a3c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0736080  Cid 05f8.11f8  Teb: 0000001042a3e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c077c080  Cid 05f8.126c  Teb: 0000001042a40000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c077d080  Cid 05f8.1270  Teb: 0000001042a42000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c077e080  Cid 05f8.1274  Teb: 0000001042a44000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c077f080  Cid 05f8.1278  Teb: 0000001042a46000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0780080  Cid 05f8.127c  Teb: 0000001042a48000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0781080  Cid 05f8.1280  Teb: 0000001042a4a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0782080  Cid 05f8.1284  Teb: 0000001042a4c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0783080  Cid 05f8.1288  Teb: 0000001042a4e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0784080  Cid 05f8.128c  Teb: 0000001042a50000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0785080  Cid 05f8.1290  Teb: 0000001042a52000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0786080  Cid 05f8.1294  Teb: 0000001042a54000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c07880c0  Cid 05f8.1298  Teb: 0000001042a56000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c0797080  Cid 05f8.12dc  Teb: 0000001042a58000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c2249080  Cid 05f8.1d74  Teb: 0000001042a5a000 Win32Thread: ffff9b82c27d46e0 WAIT
        THREAD ffff9b82c3ecf080  Cid 05f8.29fc  Teb: 0000001042a5c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ece080  Cid 05f8.2a00  Teb: 0000001042a5e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ecd080  Cid 05f8.2a04  Teb: 0000001042a60000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ecc080  Cid 05f8.2a08  Teb: 0000001042a62000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ecb080  Cid 05f8.2a0c  Teb: 0000001042a64000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3eca0c0  Cid 05f8.2a10  Teb: 0000001042a66000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ea7080  Cid 05f8.2a14  Teb: 0000001042a68000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ea6080  Cid 05f8.2a18  Teb: 0000001042a6a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ea5080  Cid 05f8.2a1c  Teb: 0000001042a6c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f9c080  Cid 05f8.2a24  Teb: 0000001042a6e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f9b080  Cid 05f8.2a28  Teb: 0000001042a70000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f9a080  Cid 05f8.2a2c  Teb: 0000001042a72000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f11080  Cid 05f8.2a44  Teb: 0000001042a74000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f10080  Cid 05f8.2a48  Teb: 0000001042a76000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0f080  Cid 05f8.2a4c  Teb: 0000001042a78000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0e080  Cid 05f8.2a50  Teb: 0000001042a7a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0d080  Cid 05f8.2a54  Teb: 0000001042a7c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0c080  Cid 05f8.2a58  Teb: 0000001042a7e000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0b080  Cid 05f8.2a5c  Teb: 0000001042a80000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f0a080  Cid 05f8.2a60  Teb: 0000001042a82000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3f09080  Cid 05f8.2a64  Teb: 0000001042a84000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ef8080  Cid 05f8.2a68  Teb: 0000001042a86000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ef7080  Cid 05f8.2a6c  Teb: 0000001042a88000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3ef6080  Cid 05f8.2a70  Teb: 0000001042a8a000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3fac080  Cid 05f8.2a8c  Teb: 0000001042a8c000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9b82c3fa8080  Cid 05f8.2aa0  Teb: 0000001042a92000 Win32Thread: ffff9b82c4e90620 WAIT
        THREAD ffff9b82c55a9080  Cid 05f8.37fc  Teb: 0000001042a96000 Win32Thread: ffff9b82c4e9cbc0 WAIT
        THREAD ffff9b82c6ce6080  Cid 05f8.03b8  Teb: 0000001042ab4000 Win32Thread: ffff9b82c4e9f420 WAIT
        THREAD ffff9b82c6fea080  Cid 05f8.1884  Teb: 0000001042aba000 Win32Thread: 0000000000000000 WAIT

lkd> dt _KTHREAD ffff9b82be6a0080 BamQosLevel // DWM compositor thread
nt!_KTHREAD
   +0x204 BamQosLevel : 0 '' // High = 36QU = 31.250ms


lkd> dt _KTHREAD ffff9b82c077c080 BamQosLevel // Idle thread
nt!_KTHREAD
   +0x204 BamQosLevel : 0x6 '' // Utility = 2 QU = 1.736ms
```


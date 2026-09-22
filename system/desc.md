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

Use my [minimal (32 bit) bitmask calculator](https://noverse.dev/#bitmask) whenever you want to get/read hex/dec values.

## KiUpdateRunTime Quantum Expiration

Using `disabledynamictick` can cause the issue while [per CPU clock tick scheduling](https://noverse.dev/docs/win-config/system/timer-expiration/#enablepercpuclocktickscheduling) is enabled. As shown in the '[ClockTickIdleEstimateFix (24H2+)](https://noverse.dev/docs/win-config/system/priority-separation/#clocktickidleestimatefix-24h2)' section, 24/25H2 have a new function which seems to try to fix the issue.

Before a processor enters idle ([`PpmIdleExecuteTransition`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/PpmIdleExecuteTransition.c)), Windows can stop its clock timer. After the processor leaves idle, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeResumeClockTimerFromIdle.c) usually programs the timer again, but with `disabledynamictick` (`KiDynamicTickDisableReason`) set, that function returns before doing so (unless something else programs the counter that means no `KeClockInterruptNotify`).

Means that stopped timer no longer sends the clock interrupt used to call [`KiUpdateRunTime`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiUpdateRunTime.c), so the running threads `CycleTime >= QuantumTarget` check isn't reached and `KPRCB.QuantumEnd` isn't set.

### ClockTickIdleEstimateFix (24H2+)

`Feature_Servicing_Kernel_ClockTickIdleEstimateFix` can make the `KClockTimerKTimerExpirationPseudoHr` deadline (`ClockTimerEntries[1]`) waking, which keeps clock interrupts running after something initially programs the timer. 23H2 always sets its low `TypeFlags` bits to `3` (active + non waking):

```c
// KiUpdateTime (23H2)

CurrentPrcb->ClockTimerState.ClockTimerEntries[1].TypeFlags |= 3u; // KClockTimerKTimerExpirationPseudoHr
```

Depending on the state of the feature, [`KiSetClockTimerKTimerDeadlines`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KiSetClockTimerKTimerDeadlines.c) programs `KClockTimerKTimerExpirationPseudoHr`:

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

With the feature enabled, `KClockTimerKTimerExpirationPseudoHr` has low bits `1`, so [`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KePrepareClockTimerForIdle.c) keeps/rearms the timer (its clock interrupts reach `KiUpdateRunTime`), which also explains why the issue doesn't appear the same way on 25H2 as on 23H2.

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

[`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeInitializeClock.c) sets `KiDynamicTickDisableReason` = `1` if the BCD settings include `DISABLEDYNAMICTICK`, see [Timer Expiration, KiDynamicTickDisableReason](https://noverse.dev/docs/win-config/system/timer-expiration/#kidynamictickdisablereason) for more details on the global.

```c
// KeInitializeClock (23H2)

if ( v18 && strstr(v18, "DISABLEDYNAMICTICK") )
  KiDynamicTickDisableReason = 1;
```

```c
lkd> db nt!KiDynamicTickDisableReason L1
fffff806`6d71d300  01                                               .
```

[`KiSetQuantumTargetThread`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiSetQuantumTargetThread.c) stores an absolute cycle target:

```c
// KiSetQuantumTargetThread (23H2)

v15 = v8 + KiCyclesPerClockQuantum * (unsigned int)*(unsigned __int8 *)(a1 + 651);
*(_QWORD *)(a1 + 32) = v15;
```

XREFs (in 23/25H2) show that only [`KeClockInterruptNotify`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeClockInterruptNotify.c) & [`KiUpdateTime`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiUpdateTime.c) call `KiUpdateRunTime`, which programs `KClockTimerQuantumEnd` (`ClockTimerEntries[3]`), checks the current threads accumulated cycles and requests a dispatch interrupt when the target is reached:

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

Before the processor enters idle, 23H2 uses [`KePrepareNonClockOwnerForIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KePrepareNonClockOwnerForIdle.c) in per CPU scheduling, while 25H2 uses [`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KePrepareClockTimerForIdle.c).

If per CPU clock tick scheduling are disabled, `KiUpdateRunTime` doesn't program `KClockTimerQuantumEnd` & the clock owner uses [`KiForwardTick`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiForwardTick.c) to send ticks to the other processors, so their quantum checks don't depend on that per CPU timer being rearmed (see '[Per CPU Clock Tick Scheduling Disabled](https://noverse.dev/docs/win-config/system/priority-separation/#per-cpu-clock-tick-scheduling-disabled)' capture).

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

As shown above `KClockTimerQuantumEnd` has low bits `3`, so the function skips it. If no other entry needs to wake the processor, the function stops the hardware timer and clears `ClockActive`/`ClockOwner`. When the processor leaves idle, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KeResumeClockTimerFromIdle.c) checks `KiDynamicTickDisableReason` before it calls [`KiSetClockTimer`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KiSetClockTimer.c):

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

[`KiDispatchInterrupt`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KiDispatchInterrupt.c) reads the quantum flag first, if its set, it calls [`KiQuantumEnd`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/KiQuantumEnd.c). Its separate `NextThread` branch stores reason `31`:

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

The priority applies to dynamic priorities below the RT (real time) range and is capped at priority `15`, disabling dynamic priority boosts for a thread/process would also prevent this FG boost. The quantum unit change is obviously only visible when the variable table is used, as all three in a fixed table are the same, so changing the low bits doesn't change its quantum. [`PsChangeQuantumTable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/PsChangeQuantumTable.c) clamps the field and saves it in `PsPrioritySeparation`:

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
fffff801`2611ec7c  00000001 // 0x19 (01)https://x.com/TweakingTruth

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

[`KiApplyForegroundBoostThread`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiApplyForegroundBoostThread.c) shows the calculation, add `PsPrioritySeparation` to the base priority & cap the dynamic priority at `15`.

```c
// KiApplyForegroundBoostThread

v10 = PsPrioritySeparation + *(_BYTE *)(a1 + 563); // PsPrioritySeparation + BasePriority
if ( v10 >= 16 )
  v10 = 15;
```

The same separation is included in the priority when [`KiDeferredReadySingleThread`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiDeferredReadySingleThread.c) readies a FG thread after a wait:

```c
// KiDeferredReadySingleThread

LABEL_64:
v35 += (char)PsPrioritySeparation; // add PsPrioritySeparation to the priority
```

#### ForceForegroundBoostDecay

Controls whether dynamic priority decay can remove the FG priority boost added by `PsPrioritySeparation`, changing it to `1` allows scheduler functions such as [`KiQuantumEnd`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KiQuantumEnd.c) to remove that boost during priority decay. If the process is still FG (and the thread can still get dynamic priority boosts), [`KiTryScheduleNextForegroundBoost`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KiTryScheduleNextForegroundBoost.c) schedules the boost to be applied again (leaving the FG obviously removes the boost no matter what the value is set to).

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

See '[Thread States](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/thread-states/)' for more details on the topic & a example on how [`WrQuantumEnd`](https://noverse.dev/docs/windbg-notes/threads/thread-scheduling/thread-states/#wrquantumend) works, and when the `WrQuantumEnd` reason is used (beside `CycleTime >= QuantumTarget`).

![](https://github.com/nohuto/win-config/blob/main/system/images/WrQuantumEnd-23H2.png?raw=true)

##### 25H2 Max Activity

This is just a "extreme" example of what it could cause, using two thread with maximum activity (runs continuously, no sleep) + same priority + same affinity. This was captured while the windows default (`0x2`) was used, means BG threads have a time of `1.736 ms` (CPUStress was in BG):

![](https://github.com/nohuto/win-config/blob/main/system/images/WrQuantumEnd-25H2-Default.png?raw=true)

#### _KTHREAD Priority

You can practically also look at it via WinDbg, but rather use WPR.

```c
// 0xA1
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

[`PsChangeQuantumTable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/PsChangeQuantumTable.c) uses the variable table for `01` and the fixed table for `10`. You can imagine the difference between them like that ([process.c](https://doxygen.reactos.org/d2/d9f/ntoskrnl_2ps_2process_8c_source.html#l00031)):

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

Without the 24H2 `ShortThreadQuantum` function, one QU is one third of the maximum clock interval. [`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeInitSystem.c) calculates the related processor cycle count:

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

`/10` converts the clock interval from 100ns units to ms (cycles per microsecond) & `/3` converts one clock interval into one QU, the output should be then the same as the `KiCyclesPerClockQuantum` read.

#### Quantum Exceptions

Most processes get their reset from the selected three entries in `PspForegroundQuantum`, but [`PspComputeQuantum`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/PspComputeQuantum.c) has two exceptions, first are processes the *Idle* priority class (not the system Idle thread) which always get `6` QU. 

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

In 24H2+, [`KiInitializeVelocity`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KiInitializeVelocity.c) calls the `Feature_ShortThreadQuantum__private_ReportDeviceUsage` helper and then sets bit `0x40000` in `KiVelocityFlags` (without conditions):

```c
// KiInitializeVelocity
Feature_ShortThreadQuantum__private_ReportDeviceUsage();
KiVelocityFlags |= 0x40000u;
```

```c
lkd> ? dwo(nt!KiVelocityFlags) & 0x40000 // 25H2
Evaluate expression: 262144 = 00000000`00040000 // 0x40000 = ShortThreadQuantum used
```

With that flag, [`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KeInitSystem.c) divides the older quantum unit by another six:

```c
// KeInitSystem
if ( (KiVelocityFlags & 0x40000) != 0 )
{
  KiCyclesPerClockQuantum = (unsigned int)v17 / 6; // clock interval / 18
  KiLockQuantumTarget = 2 * ((unsigned int)v17 / 6);
}
```

It also causes [`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KeInitializeClock.c) to set `KeQuantumEndTimerIncrement` (doesn't exist in 23H2) to `1.740 ms`:

```c
// KeInitializeClock

v6 = KeMaximumIncrement;
if ( (KiVelocityFlags & 0x40000) != 0 )
  v6 = 17400; // 1.740 ms
KiTimeUpdateTryAcquireTickLock = 1;
KeQuantumEndTimerIncrement = v6;
```

Clock interrupts call [`KiUpdateRunTime`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KiUpdateRunTime.c), which checks the running threads quantum, 23H2 uses the normal clock interval (`KeMaximumIncrement`, up to `15.625 ms`), 24H2 caps the requested quantum end clock interrupt interval (`KeQuantumEndTimerIncrement`) at `1.740 ms` (which isn't good).

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

`BamQosLevel` doesn't use the `PspVariableQuantums`/`PspFixedQuantums` tables, these're still getting filled by the threads stored `QuantumReset`. When `ShortThreadQuantum` and variable quantums are used, [`KiQueryQuantumReset`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-24H2/ntoskrnl/KiQueryQuantumReset.c) (exists since 24H2) can instead return a QoS reset (fixed quantums set `KiVariableQuantumEnabled` to `0` and won't use that override, see '[18 QU, 25H2](https://noverse.dev/docs/win-config/system/priority-separation/#18-qu-25h2)' capture). `_KTHREAD.BamQosLevel` is at `0x204`, which is the `a1 + 516` byte read below.

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

# MMCSS Values

Everything below is based on the 11-23H2 mmcss driver pseudocode (see [diff](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-25H2&module=mmcss&name=CiConfigInitialize.c&mode=side-by-side) if you want to see changes on newer builds)/ WPR (`Microsoft-Windows-MMCSS` provider).

> "*The Multimedia Class Scheduler service (MMCSS) enables multimedia applications to ensure that their time-sensitive processing receives prioritized access to CPU resources. This service enables multimedia applications to utilize as much of the CPU as possible without denying CPU resources to lower-priority applications.*"
>
> — Microsoft, [Multimedia Class Scheduler Service](https://learn.microsoft.com/en-us/windows/win32/procthread/multimedia-class-scheduler-service)

The MMCSS scheduler thread is set to priority `27`, as it must preempt Pro Audio threads so it can lower them to the exhausted category when their guaranteed period is over.

```c
// CiSchedulerThreadFunction
CurrentThread = KeGetCurrentThread();
CiThreadsMovedUp = 1;
CiSchedulerThread = CurrentThread;
CiSchedulerInLazyMode = 0;
KeSetActualBasePriorityThread(CurrentThread, 27LL); // scheduler thread priority
```

![](https://github.com/nohuto/win-config/blob/main/system/images/mmcssprio.png?raw=true)

You can practically also see the priority of `CiSchedulerThread` using WinDbg:

```c
lkd> dq mmcss!CiSchedulerThread L1
fffff800`3aee8298  ffffe409`67145040

lkd> !thread ffffe409`67145040
THREAD ffffe40967145040  Cid 0004.0a2c  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT: (Executive) KernelMode Alertable
    ffffe409634683b0  Timer2SynchronizationObject
Not impersonating
DeviceMap                 ffff840575e1a610
Owning Process            ffffe4095d502080       Image:         System
Attached Process          N/A            Image:         N/A
Wait Start TickCount      224914         Ticks: 28 (0:00:00:00.437)
Context Switch Count      376449         IdealProcessor: 2             
UserTime                  00:00:00.000
KernelTime                00:00:00.000
Win32 Start Address 0xfffff8003aee2e60
Stack Init fffffa80b5f7fc30 Current fffffa80b5f7f350
Base fffffa80b5f80000 Limit fffffa80b5f79000 Call 0000000000000000
Priority 27  BasePriority 27  Priority Floor 27  IoPriority 2  PagePriority 5
```

## Registry Values

All values below are read via [`CiConfigReadDWORD`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiConfigReadDWORD.c), means the accepted type is `REG_DWORD`.  The values shown below are fallbacks used when the value is missing/not in range/not a `REG_DWORD` (`SystemResponsiveness` = `20`, `NetworkThrottlingIndex` = `10` exist on a new installation, so beside these the data listed below is used).

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile";
    "SystemResponsiveness" = 100; // clamped to 10-100, 100 disables MMCSS, <10 or >100 = 20
    "NetworkThrottlingIndex" = 10; // 0 = 1, 1-70 stay, 71-0xFFFFFFFE = 70, 0xFFFFFFFF disables MMCSS's override (NDIS_INDICATE_ALL_NBLS)
    "NoLazyMode" = 0; // bool
    "IdleDetectionCycles" = 2; // range 1-31
    "LazyModeTimeout" = 1000000; // 0 replaced with 1000000, no upper clamp?
    "SchedulerTimerResolution" = 10000; // values above 10000 capped to 10000
    "SchedulerPeriod" = 100000; // range 50000-1000000
    "MaxThreadsPerProcess" = 32; // range 8-128
    "MaxThreadsTotal" = 256; // range 64-65535
```

### DriverStart + RVAs

Everything below isn't needed when reloading the MMCSS module, simple way:

```c
lkd> .reload /f mmcss.sys
lkd> lm m mmcss
Browse full module list
start             end                 module name
fffff801`890e0000 fffff801`890f6000   mmcss      (pdb symbols)          C:\ProgramData\Dbg\sym\mmcss.pdb\9E36707273FDF82AB362DBA6ACCC09671\mmcss.pdb
lkd> dd mmcss!CiSystemResponsiveness L1
fffff801`890e82f8  00000014
lkd> dd mmcss!CiNetworkThrottlingIndex L1
fffff801`890e81c0  0000000a
lkd> db mmcss!CiSchedulerDisallowLazyMode L1
fffff801`890e82d5  00                                               .
lkd> dd mmcss!CiSchedulerIdleDetectionCycles L1
fffff801`890e828c  00000002
lkd> dd mmcss!CiSchedulerLazyModeTimeout L1
fffff801`890e81c4  000f4240
lkd> dd mmcss!CiSchedulerTimerResolution L1
fffff801`890e81c8  00002710
lkd> dd mmcss!CiSchedulerPeriod L1
fffff801`890e81cc  000186a0
lkd> dd mmcss!CiMaxThreadsTotal L1
fffff801`890e8090  00000100
lkd> dd mmcss!CiMaxThreadsPerProcess L1
fffff801`890e8094  00000020
```

A different way to read current values is via RVAs (*Relative Virtual Address*, means an address relative to the modules image base), to do so get the `DriverStart` address + the RVA of whatever you want to read.

```c
lkd> !drvobj MMCSS
Driver object (ffffb68b3754ba70) is for:
 \Driver\MMCSS

Driver Extension List: (id , addr)

Device Object list:
ffffb68b375dfca0  
lkd> dt nt!_DRIVER_OBJECT ffffb68b3754ba70 DriverStart
   +0x018 DriverStart : 0xfffff801`890e0000 Void

// or just via lm

lkd> lm m mmcss
Browse full module list
start             end                 module name
fffff801`890e0000 fffff801`890f6000   mmcss      (pdb symbols)          C:\ProgramData\Dbg\sym\mmcss.pdb\9E36707273FDF82AB362DBA6ACCC09671\mmcss.pdb
```

So for example you want to read the current value of `CiSystemResponsiveness` (IDA):

```asm
.data:00000001C00082F8 CiSystemResponsiveness dd 0
```

Get the current image base from `Edit > Segments > Rebase program` (`0x1C0000000` for me), and subtract it from the address above, means `0x1C00082F8 - 0x1C0000000 = 0x82F8` which is the RVA for `CiSystemResponsiveness`.

Then use the `DriverStart` address + RVA:

```c
lkd> dd 0xfffff801`890e82F8 L1
fffff801`3aee82f8  0000000a // 10
```

## NetworkThrottlingIndex

`NetworkThrottlingIndex` = maximum number of received [`NET_BUFFER_LIST`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures (NBLs) that MMCSS can ask NDIS to allow a miniport to indicate in one receive DPC (runs after network interrupt), to reduce the processing time it spends at `DISPATCH_LEVEL`. Note that DPCs run at `DISPATCH_LEVEL` (higher than threads, means long DPCs harm performance, by blocking threads, see [interrupt-request-levels](https://noverse.dev/docs/windbg-notes/system-mechanisms/trap-dispatching/interrupt-request-levels/)).

![](https://github.com/nohuto/windbg-notes/blob/main/images/irql-levels.png?raw=true)

Miniport drivers use [`NdisMIndicateReceiveNetBufferLists`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/NdisMIndicateReceiveNetBufferLists.c) to indicate received network data, its [`NetBufferList` argument](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) points to a linked list of NBLs, and `NumberOfNetBufferLists` gives the number of NBLs in that list. Each [NBL contains a linked list of `NET_BUFFER` structures](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/net-buffer-list-structure) & each [`NET_BUFFER`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) represents one network packet, with its data stored in buffers.

```c
union _SLIST_HEADER// Size=0x10 (Id=223)
{
    unsigned long long Alignment;// Offset=0x0 Size=0x8
    unsigned long long Region;// Offset=0x8 Size=0x8
    struct <unnamed-type-HeaderX64>// Size=0x10 (Id=13423)
    {
        unsigned long long Depth:16;// Offset=0x0 Size=0x8 BitOffset=0x0 BitSize=0x10
        unsigned long long Sequence:48;// Offset=0x0 Size=0x8 BitOffset=0x10 BitSize=0x30
        unsigned long long Reserved:4;// Offset=0x8 Size=0x8 BitOffset=0x0 BitSize=0x4
        unsigned long long NextEntry:60;// Offset=0x8 Size=0x8 BitOffset=0x4 BitSize=0x3c
    };
    struct _SLIST_HEADER::<unnamed-type-HeaderX64> HeaderX64;// Offset=0x0 Size=0x10
};

struct _NET_BUFFER_LIST_DATA// Size=0x10 (Id=964)
{
    struct _NET_BUFFER_LIST * Next;// Offset=0x0 Size=0x8
    struct _NET_BUFFER * FirstNetBuffer;// Offset=0x8 Size=0x8
};

union _NET_BUFFER_LIST_HEADER// Size=0x10 (Id=933)
{
    struct _NET_BUFFER_LIST_DATA NetBufferListData;// Offset=0x0 Size=0x10, a NET_BUFFER_LIST_DATA structure
    union _SLIST_HEADER Link;// Offset=0x0 Size=0x10, reserved for NDIS
};

struct _NET_BUFFER_LIST// Size=0x180 (Id=164)
{
    union // Size=0x10 (Id=0)
    {
        struct _NET_BUFFER_LIST * Next;// Offset=0x0 Size=0x8, the next NET_BUFFER_LIST structure in the chain
        struct _NET_BUFFER * FirstNetBuffer;// Offset=0x8 Size=0x8, the first NET_BUFFER on this NET_BUFFER_LIST
        union _SLIST_HEADER Link;// Offset=0x0 Size=0x10, reserved for NDIS
        union _NET_BUFFER_LIST_HEADER NetBufferListHeader;// Offset=0x0 Size=0x10, a NET_BUFFER_LIST_HEADER structure
    };
    struct _NET_BUFFER_LIST_CONTEXT * Context;// Offset=0x10 Size=0x8
    struct _NET_BUFFER_LIST * ParentNetBufferList;// Offset=0x18 Size=0x8
    void * NdisPoolHandle;// Offset=0x20 Size=0x8
    void * NdisReserved[2];// Offset=0x30 Size=0x10
    void * ProtocolReserved[4];// Offset=0x40 Size=0x20
    void * MiniportReserved[2];// Offset=0x60 Size=0x10
    void * Scratch;// Offset=0x70 Size=0x8
    void * SourceHandle;// Offset=0x78 Size=0x8
    unsigned long NblFlags;// Offset=0x80 Size=0x4
    long ChildRefCount;// Offset=0x84 Size=0x4
    unsigned long Flags;// Offset=0x88 Size=0x4
    union // Size=0x4 (Id=0)
    {
        int Status;// Offset=0x8c Size=0x4
        unsigned long NdisReserved2;// Offset=0x8c Size=0x4
    };
    void * NetBufferListInfo[29];// Offset=0x90 Size=0xe8
};
```

See [diff](https://noverse.dev/diff?kind=type&left=11-23H2&right=11-24H2&module=ndis&name=_NET_BUFFER_LIST&mode=side-by-side) whenever you want to compare the type layout with different NDIS build versions, or to look at other layouts.

### CiConfigInitialize

```c
// CiConfigInitialize
v3 = CiConfigReadDWORD(KeyHandle, 0x1C00110A0LL, 10LL);
LODWORD(WPP_MAIN_CB.Dpc.DpcData) = v3; // 1-70 & 0xFFFFFFFF stay unchanged
v4 = v3;
if ( v3 )
{
  if ( (unsigned int)(v3 - 71) <= 0xFFFFFFB7 )
  {
    v4 = 70;
    LODWORD(WPP_MAIN_CB.Dpc.DpcData) = 70; // 71-0xFFFFFFFE = 70
  }
}
else
{
  v4 = 1;
  LODWORD(WPP_MAIN_CB.Dpc.DpcData) = 1; // 0 = 1
}
```

[`CsInitialize`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CsInitialize.c) allocates the NDIS work item and opens `\Device\Ndis` only when the value isn't `4294967295` and `SystemResponsiveness != 100`.

### Throttle State

Only scheduled threads whose task use a `Scheduling Category` of `Medium` or `High` are included in `CiScheduledThreadCount`. [`CiThreadIncrementScheduledCount`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CiThreadIncrementScheduledCount.c) and [`CiThreadDecrementScheduledCount`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CiThreadDecrementScheduledCount.c) update this count and call [`CiNdisUpdateThrottleState`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CiNdisUpdateThrottleState.c) when it changes from `0` to `1`/from `1` to `0`. When the work item runs, [`CiNdisThrottle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CiNdisThrottle.c) sends `NetworkThrottlingIndex` when the count is nonzero, or `4294967295` when the count is zero.

[`CiNdisThrottle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/mmcss/CiNdisThrottle.c) sends the request to the previously opened `\Device\Ndis` handle using [`ZwDeviceIoControlFile`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwdeviceiocontrolfile).

```c
// CiNdisThrottle

v2 = ZwDeviceIoControlFile(CiNdisDeviceHandle, 0LL, 0LL, 0LL, &IoStatusBlock, 0x170040u, InputBuffer, 0x10u, 0LL, 0);
```

Using the [`CTL_CODE`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/defining-i-o-control-codes) layout, `0x170040` would mean ([FILE_DEVICE_PHYSICAL_NETCARD](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/specifying-device-types), [METHOD_BUFFERED](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes), [FILE_ANY_ACCESS](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/defining-i-o-control-codes#guidance-for-setting-the-access-bits)):

![](https://github.com/nohuto/win-config/blob/main/system/images/ioctl-bit-layout.png?raw=true)

```c
// IOCTL hex = 0x00170040
// device type = 0x17
// access = 0
// function = 16
// method = 0
// function name = CiNdisThrottle

CTL_CODE(
    FILE_DEVICE_PHYSICAL_NETCARD, // device type 0x17
    0x10, // function 0x10
    METHOD_BUFFERED, // 0
    FILE_ANY_ACCESS // 0
) // 0x170040
```

Note that the `_NDIS_SET_RECEIVE_RATE` (recreated from pseudocode) type here is only used to understand the layout as public PDBs don't include it.

```c
typedef struct _NDIS_SET_RECEIVE_RATE {
  USHORT Type; // 1
  USHORT Size; // 16
  ULONG  MaxNblsToIndicate; // maximum NBL count or 0xFFFFFFFF
  LONGLONG Period; // -1
} NDIS_SET_RECEIVE_RATE;
```

When the [IOCTL](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes) succeeds, `CiNdisThrottledDown` records whether the MMCSS maximum is active.

### NDIS Request

[`ndisHandlePnPRequest`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/-ndisHandlePnPRequest@@_Y2PAGENPNP@@AJPEAU_IRP@@@Z.c) receives [IOCTL](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes) `0x170040`, which requires 16 input bytes, `Type = 1`, `Size = 16`, and a nonzero `MaxNblsToIndicate` (`Period` must also be nonzero unless `MaxNblsToIndicate = 0xFFFFFFFF`). That input is then passed to [`ndisConfigurePeriodicReceives`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/-ndisConfigurePeriodicReceives@@YAXPEAU_NDIS_SET_RECEIVE_RATE@@@Z.c).

> "*`MaxNblsToIndicate`*
>
> *The maximum number of [NET_BUFFER_LIST](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that a miniport driver should include in a receive indication. If this value is NDIS_INDICATE_ALL_NBLS, the miniport can indicate all of the [NET_BUFFER_LIST](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that it has.*"
>
> — Microsoft, [NDIS_RECEIVE_THROTTLE_PARAMETERS structure](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters)

When MMCSS sends `1-70`, NDIS stores it as the MMCSS maximum and saves `Period = -1` (NDIS headers define `4294967295` as `NDIS_INDICATE_ALL_NBLS`, means when using it, MMCSS maximum is set to `4294967295` and `Period` gets cleared).

The NDIS maximum starts at 64 NBLs as [`ndisMInitializeAdapter`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/-ndisMInitializeAdapter@@YAHPEAU_NDIS_M_DRIVER_BLOCK@@PEAU_NDIS_MINIPORT_BLOCK@@PEAU_NDIS_WRAPPE.c) basically hard codes every per processor table index to `6` (`64`), which can also be read:

```c
lkd> dq ffffb605cc5fa030+ce0 L1 // _NDIS_MINIPORT_BLOCK PeriodicReceivesNblCountIndex
ffffb605`cc5fad10  ffffcc00`eb341170
lkd> dd ffffcc00eb341170 L1
ffffcc00`eb341170  00000006 // processor 0 RST index 6 = 64 NBLs
```

```c
// ndisMInitializeAdapter

PerProcessorSlot = ndisAllocatePerProcessorSlot(0x527374u);
a2->PeriodicReceivesNblCountIndex = PerProcessorSlot;
v20 = ndisMaxNumberOfProcessors;
for ( i = 0; i < v20; *(_DWORD *)((char *)a2->PeriodicReceivesNblCountIndex + v22) = 6 )
  v22 = i++ << 12;
```

[`ndisPeriodicReceivesLearning`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/-ndisPeriodicReceivesLearning@@YAXPEAU_NDIS_MINIPORT_BLOCK@@KPEAT_LARGE_INTEGER@@@Z.c) can change the current processors RST index using for example the number of received NBLs, the RST values are stored in `ndis!ndisPeriodicReceivesNblCounts`:

```c
lkd> dd ndis!ndisPeriodicReceivesNblCounts Lb
fffff801`78dbb6d0  00000001 00000002 00000004 00000008 // 1, 2, 4, 8
fffff801`78dbb6e0  00000010 00000020 00000040 00000080 // 16, 32, 64, 128
fffff801`78dbb6f0  00000100 00000200 00000400 // 256, 512, 1024
```

[`ndisMiniportDpc`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/ndisMiniportDpc.c) passes the result to an miniport as `MaxNblsToIndicate` in [`NDIS_RECEIVE_THROTTLE_PARAMETERS`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters), an MMCSS maximum of `10` would limit the values (`4294967295` obviously doesn't):

```c
RST values: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
With max: 1, 2, 4, 8, 10, 10, 10, 10, 10, 10, 10
```

Note that this only works whenever your miniport supports NDIS [RST (receive side throttle)](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/receive-side-throttle-in-ndis-6-20), if not, NDIS can't pass that structure to it (fallback uses [`ndisMIndicateReceiveNblsWithThrottling`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/-ndisMIndicateReceiveNblsWithThrottling@@YAXPEAXPEAU_NET_BUFFER_LIST@@KKK@Z.c), haven't looked into that yet)..

> "*NDIS 6.20 introduces receive-side throttle (RST) enhancements to reduce the possibility of disruptions during media playback in multimedia applications. RST support is mandatory for NDIS 6.20 and later drivers.*
>
> *If an NDIS driver spends too much time at dispatch IRQ level in a deferred procedure call (DPC), it increases the scheduling latency for multimedia application threads and might cause disruptions during media playback. To improve media playback with NDIS 6.20 and later drivers, NDIS can control the number of packets that a miniport driver indicates in a receive DPC.*"
>
> — Microsoft, [Receive Side Throttle in NDIS 6.20](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/receive-side-throttle-in-ndis-6-20)

This also explains why `ndis.sys` DPC execution times can be higher with `4294967295`, as with a maximum of `10` (and RST being supported), [`ndisInterruptDpc`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/ndisInterruptDpc.c) adds the miniport callback to a per processor NDIS receive worker queue and returns. [`ndisReceiveWorkerThread`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ndis/ndisReceiveWorkerThread.c) would then later run the callback at `DISPATCH_LEVEL` with `MaxNblsToIndicate = 10`. Using `4294967295`, would cause NDIS to remove the MMCSS maximum and may run the callback before the current `ndisInterruptDpc` returns, means the callback work is included in that DPCs measured execution time.

### WinDbg

#### 0xA (Active MMCSS Threads)

```c
lkd> dd mmcss!CiNetworkThrottlingIndex L1
fffff801`867a81c0  0000000a // 10
lkd> dd mmcss!CiScheduledThreadCount L1
fffff801`867a8100  00000005 // 5 scheduled Medium/High (Scheduling Category) threads
lkd> db mmcss!CiNdisThrottledDown L1
fffff801`867a82b0  01 // MMCSS maximum is used
lkd> db mmcss!CiNdisThrottleInProgress L1
fffff801`867a82c0  00 // no NDIS update queued
lkd> dq mmcss!CiNdisDeviceHandle L1
fffff801`867a82a8  ffffffff`80001250 // open \Device\Ndis handle
lkd> dd ndis!ndisPeriodicReceives+4 L1
fffff801`78dd5204  0000000a // current MMCSS maximum
lkd> dd ndis!ndisPeriodicReceives+c L1
fffff801`78dd520c  00000000 // use the smaller of RST value & MMCSS maximum
lkd> dq ndis!ndisPeriodicReceives+28 L1
fffff801`78dd5228  ffffffff`ffffffff // Period = -1
```

#### 0xA (No Active MMCSS Threads)

```c
lkd> dd mmcss!CiNetworkThrottlingIndex L1
fffff805`a92c81c0  0000000a // 10
lkd> dd mmcss!CiScheduledThreadCount L1
fffff805`a92c8100  00000000 // no scheduled Medium/High threads
lkd> db mmcss!CiNdisThrottledDown L1
fffff805`a92c82b0  00 // MMCSS maximum inactive
lkd> db mmcss!CiNdisThrottleInProgress L1
fffff805`a92c82c0  00 // no NDIS update queued
lkd> dq mmcss!CiNdisDeviceHandle L1
fffff805`a92c82a8  ffffffff`80001248 // open \Device\Ndis handle
lkd> dq mmcss!CiNdisThrottleWorkItem L1
fffff805`a92c82c8  ffffc60c`321481e0 // NDIS update work item allocated
lkd> dd ndis!ndisPeriodicReceives+4 L1
fffff805`7cc65204  ffffffff // no MMCSS maximum
lkd> dq ndis!ndisPeriodicReceives+28 L1
fffff805`7cc65228  00000000`00000000 // Period = 0
```

#### 0xFFFFFFFF

```c
lkd> dd mmcss!CiNetworkThrottlingIndex L1
fffff803`af4581c0  ffffffff
lkd> dd mmcss!CiScheduledThreadCount L1
fffff803`af458100  00000003 // 3 scheduled Medium/High threads
lkd> db mmcss!CiNdisThrottledDown L1
fffff803`af4582b0  00 // MMCSS maximum inactive
lkd> db mmcss!CiNdisThrottleInProgress L1
fffff803`af4582c0  00 // no NDIS update queued
lkd> dq mmcss!CiNdisDeviceHandle L1
fffff803`af4582a8  00000000`00000000 // \Device\Ndis wasn't opened
lkd> dq mmcss!CiNdisThrottleWorkItem L1
fffff803`af4582c8  00000000`00000000 // NDIS work item not allocated
lkd> dd ndis!ndisPeriodicReceives+4 L1
fffff803`855c5204  ffffffff // no MMCSS maximum
lkd> dq ndis!ndisPeriodicReceives+28 L1
fffff803`855c5228  00000000`00000000 // Period = 0
```

## SystemResponsiveness

Used to split each scheduler period (`SchedulerPeriod`) between MMCSS & ordinary system work.

For other values than 100, [`CiSchedulerInitialize`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerInitialize.c) splits `SchedulerPeriod` with `CiSystemResponsiveness`, see [`SchedulerPeriod`](https://noverse.dev/docs/win-config/system/mmcss-values/#schedulerperiod) section for more details on that. If `SystemResponsiveness == 100`, [`CiConfigInitialize`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiConfigInitialize.c) returns before the rest of the values and the `Tasks` key are read, it also prevents scheduler initialization later in [`CsInitialize`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CsInitialize.c), means it disables MMCSS.

```c
exhausted = SchedulerPeriod * CiSystemResponsiveness / 100
boosted = SchedulerPeriod - (SchedulerPeriod * CiSystemResponsiveness / 100)
```

During the boosted duration, scheduled MMCSS threads run at their task priority & during the exhausted duration, [`CiSchedulerSetPriority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerSetPriority.c) lowers them to their exhausted priority (`1-7`), which gives lower priority work a chance to run.

`CiSystemResponsiveness` is also used later by [`CiSchedulerWait`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerWait.c) when checking idle/starvation state, so the value affects more than just the initial boosted/exhausted split.

![](https://github.com/nohuto/win-config/blob/main/system/images/mmcss-10-100.png?raw=true)

```c
// CiConfigInitialize
DWORD = CiConfigReadDWORD(KeyHandle, 0x1C0011090LL, 100LL); // SystemResponsiveness, fallback = 100
if ( DWORD - 10 > 0x5A )
  v2 = 20; // <10 or >100
else
  v2 = 10 * (DWORD / 0xA); // round down to multiple of 10
CiSystemResponsiveness = v2;

if ( CiSystemResponsiveness == 100 )
{
  v0 = -1073741696; // STATUS_SERVER_DISABLED
}
else
{
// values and Tasks
}
```

### Calculation

```c
CiSystemResponsiveness = 10 * (value / 10);

< 10 -> 20 // fallback since not in range
10-19 -> 10
20-29 -> 20
30-39 -> 30
40-49 -> 40
50-59 -> 50
60-69 -> 60
70-79 -> 70
80-89 -> 80
90-99 -> 90
== 100 -> 100 // STATUS_SERVER_DISABLED
> 100 -> 20 // fallback since not in range
```

## SchedulerPeriod

As the name says it's the MMCSS scheduler period where registered multimedia threads run at their category priority for a guaranteed part, then get lowered (`1-7`) so other threads can run. Means for example a larger period = fewer scheduler transitions but longer uninterrupted boosted/exhausted switches.

```c
// CiConfigInitialize
v9 = CiConfigReadDWORD(KeyHandle, 0x1C00110E0LL, 100000LL); // SchedulerPeriod, fallback = 100000
*(&WPP_MAIN_CB.ActiveThreadCount + 1) = v9;
if ( (unsigned int)(v9 - 50000) > 0xE7EF0 )
  *(&WPP_MAIN_CB.ActiveThreadCount + 1) = 100000; // range 50000-1000000
```

Used by [`CiSchedulerInitialize`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerInitialize.c), where `SystemResponsiveness` splits the period into two durations:

```c
// CiSchedulerInitialize
HIDWORD(WPP_MAIN_CB.SecurityDescriptor) =
  SchedulerPeriod * CiSystemResponsiveness / 100; // exhausted duration

LODWORD(WPP_MAIN_CB.SecurityDescriptor) =
  SchedulerPeriod - SchedulerPeriod * CiSystemResponsiveness / 100; // boosted duration
```

With `SchedulerPeriod = 50000` & `SystemResponsiveness = 30`, this would mean:

```c
exhausted duration = 50000 * 30 / 100 = 15000
boosted duration = 50000 - (50000 * 30 / 100) = 35000
```

You can see that split (when `NoLazyMode` is 1) in `Scheduler_Sleep` via `Realtime` (boosted)/`SleepResponsiveness` (exhausted) reasons:

![](https://github.com/nohuto/win-config/blob/main/system/images/SchedulerPeriod.png?raw=true)

### Calculation Examples

> "*By default, multimedia threads get 80 percent of the CPU time available, while other threads receive 20 percent. (Based on a sample of 10 ms, that would be 8 ms and 2 ms, respectively.)*"
>
> — Windows Internals, [E7, P1: 'Priority boosts for multimedia applications and games'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

The "*10 ms*" in that quote = `SchedulerPeriod = 100000`.

```c
// SchedulerPeriod = 100000 (default)
SystemResponsiveness = 10
exhausted = 100000 * 10 / 100 = 10000 // 1ms
boosted = 100000 - 10000 = 90000 // 9ms

// Windows Internals example (both default data)
SystemResponsiveness = 20
exhausted = 100000 * 20 / 100 = 20000 // 2ms
boosted = 100000 - 20000 = 80000 // 8ms

// SchedulerPeriod = 50000 (min)
SystemResponsiveness = 20
exhausted = 50000 * 20 / 100 = 10000 // 1ms
boosted = 50000 - 10000 = 40000 // 4ms

// SchedulerPeriod = 1000000 (max)
SystemResponsiveness = 20
exhausted = 1000000 * 20 / 100 = 200000 // 20ms
boosted = 1000000 - 200000 = 800000 // 80ms
```

## NoLazyMode

Controls whether [`CiSchedulerWait`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerWait.c) does CPU idle/starvation detection and updates `CiProcessorIdleHistoryBits`, any nonzero registry value sets `CiSchedulerDisallowLazyMode` to `1`.

- `NoLazyMode = 0` = MMCSS samples processor idle state and total cycle counters after its boosted sleep, when no (potentially) starved processor is found, it updates the idle history as `(history << 1 | 1) & CiSchedulerIdleCycleBitMask`. A nonzero history below the mask causes an `IdleDetection` sleep for `SchedulerPeriod`, reaching the mask sets `CiSchedulerInLazyMode` and creates `IdleDetectionLazy` sleeps for `LazyModeTimeout`.
- `NoLazyMode = 1` = sampling/history update is skipped, configuration is read before the scheduler starts, while `CiProcessorIdleHistoryBits` and `CiSchedulerInLazyMode` are clear, so normal startup cannot enter lazy mode. Active MMCSS threads therefore use `Realtime` boosted sleep & `SleepResponsiveness` exhausted sleep (doesn't disable normal sleeps/`DeepSleep`).

`SleepRealtimeLazy` isn't used with `NoLazyMode = 1`.

You can see that in the picture of the [SchedulerPeriod](https://noverse.dev/docs/win-config/system/mmcss-values/#schedulerperiod) section.

```c
// CiConfigInitialize
v5 = (unsigned __int8)CiConfigReadDWORD(KeyHandle, 0x1C0011080LL, 0LL) != 0;
CiSchedulerDisallowLazyMode = v5; // '!= 0' = DisallowLazyMode
```

```c
// CiSchedulerWait
if ( !CiSchedulerDisallowLazyMode )
{
// CPU idle stats, update CiProcessorIdleHistoryBits
}
```

### Scheduler_Sleep Reasons

| Reason | Meaning | Duration |
| --- | --- | --- |
| `Realtime` | boosted sleep | boosted duration `SchedulerPeriod - (SchedulerPeriod * SystemResponsiveness / 100)` |
| `SleepResponsiveness` | exhausted sleep | exhausted duration `SchedulerPeriod * SystemResponsiveness / 100` |
| `SleepRealtimeLazy` | when `CiSchedulerInLazyMode` was already set before the normal boosted sleep | `LazyModeTimeout` |
| `IdleDetection` | idle history exists but hasn't reached `CiSchedulerIdleCycleBitMask` | `SchedulerPeriod` |
| `IdleDetectionLazy` | idle history reached `CiSchedulerIdleCycleBitMask` | `LazyModeTimeout` |
| `DeepSleep` | [`CiSchedulerDeepSleep`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerDeepSleep.c) | ETW shows `0xFFFFFFFF`, means the wait is indefinite (`Timeout = NULL`) |

For `DeepSleep`, `0xFFFFFFFF` is a kind of placeholder written into the `Scheduler_Sleep.Duration` field, [`CiSchedulerDeepSleep`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerDeepSleep.c) calls `KeWaitForSingleObject` with a null timeout and continues to sleep until a scheduler wakeup happens.

```xml
<bitMap name="wakeupReasonMap">
  <map value="0x1" message="$(string.map_wakeupReasonMapNewThread)"/>
  <map value="0x2" message="$(string.map_wakeupReasonMapProcessResume)"/>
  <map value="0x4" message="$(string.map_wakeupReasonMapProcessSuspend)"/>
  <map value="0x8" message="$(string.map_wakeupReasonMapExit)"/>
  <map value="0x10" message="$(string.map_wakeupReasonMapInternalDeadline)"/>
  <map value="0x20" message="$(string.map_wakeupReasonMapYieldDeadline)"/>
  <map value="0x80" message="$(string.map_wakeupReasonMapNoClientThreads)"/>
  <map value="0x8000" message="$(string.map_wakeupReasonMapDeepSleep)"/>
</bitMap>
<valueMap name="sleepReasonMap">
  <map value="0x0" message="$(string.map_sleepReasonMapSleepResponsiveness)"/>
  <map value="0x1" message="$(string.map_sleepReasonMapRealtime)"/>
  <map value="0x2" message="$(string.map_sleepReasonMapSleepRealtimeLazy)"/>
  <map value="0x3" message="$(string.map_sleepReasonMapIdleDetection)"/>
  <map value="0x4" message="$(string.map_sleepReasonMapIdleDetectionLazy)"/>
  <map value="0x5" message="$(string.map_sleepReasonMapDeepSleep)"/>
</valueMap>
```

- [Manifests-Win10-18990/Microsoft-Windows-MMCSS.xml](https://github.com/repnz/etw-providers-docs/blob/master/Manifests-Win10-18990/Microsoft-Windows-MMCSS.xml)

## IdleDetectionCycles

[`CiSchedulerWait`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerWait.c) compares `CiProcessorIdleHistoryBits` against `CiSchedulerIdleCycleBitMask`, so larger values need more idle detection passes before lazy mode can be entered. While the history is nonzero but still below the mask, it logs `IdleDetection` and sleeps for `SchedulerPeriod`. Once the history reaches the mask, it logs `IdleDetectionLazy` and sleeps for `LazyModeTimeout`.

This can be seen in `Scheduler_Sleep` (usually `IdleDetectionCycles - 1`, as `IdleDetectionLazy` is only logged on the pass where `CiProcessorIdleHistoryBits` first reaches the full mask):

![](https://github.com/nohuto/win-config/blob/main/system/images/IdleDetectionCycles.png?raw=true)

```c
// CiConfigInitialize
v6 = CiConfigReadDWORD(KeyHandle, 0x1C00110B0LL, 2LL); // fallback = 2
CiSchedulerIdleDetectionCycles = v6;
if ( (unsigned int)(v6 - 1) > 0x1E )
  CiSchedulerIdleDetectionCycles = 2; // range 1-31

CiSchedulerIdleCycleBitMask = (1 << CiSchedulerIdleDetectionCycles) - 1;
```

## LazyModeTimeout

Sleep duration used when MMCSS is in lazy mode. This is used for `IdleDetectionLazy` (or `SleepRealtimeLazy`):

![](https://github.com/nohuto/win-config/blob/main/system/images/LazyModeTimeout.png?raw=true)

```c
// CiConfigInitialize
HIDWORD(WPP_MAIN_CB.Dpc.DpcData) =
  CiConfigReadDWORD(KeyHandle, 0x1C00110C0LL, 1000000LL); // LazyModeTimeout, fallback = 1000000

if ( !HIDWORD(WPP_MAIN_CB.Dpc.DpcData) )
  HIDWORD(WPP_MAIN_CB.Dpc.DpcData) = 1000000; // 0 replaced
```

[`CiSchedulerWait`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerWait.c) passes this value to [`CiSchedulerSleep`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerSleep.c) when `CiSchedulerInLazyMode` is true.

```c
// CiSchedulerWait
if ( CiSchedulerInLazyMode )
{
  DpcData_high = HIDWORD(WPP_MAIN_CB.Dpc.DpcData); // LazyModeTimeout
  v4 = 2;
}

CiSchedulerSleep(v4, DpcData_high, v2);
```

## SchedulerTimerResolution

Clamps the requested yield/deadline times so they aren't shorter than this value (unrelated to system timer resolution). With `SchedulerTimerResolution = 10000` (`1 ms`), a request like `0.5 ms` is raised to `1 ms`, so the deadline/yield part won't schedule the thread back to its higher priority sooner than `1 ms` after the yield request.

This is used by [`CiSchedulerTaskIndexYield`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiSchedulerTaskIndexYield.c), the requested `Duration` and `PreDuration` are raised to `SchedulerTimerResolution` if they're smaller (changed values are logged by `TaskIndex_Yield`).

While doing several captures I didn't see any request below `1 ms` so from my current state I would say that this has no actual use.

> "*MMCSS also supports a feature called deadline scheduling. The idea is that an audio-playing program does not always need the highest priority level in its category. If such a program uses buffering (obtaining audio data from disk or network) and then plays the buffer while building the next buffer, deadline scheduling allows a client thread to indicate a time when it must get the high priority level to avoid glitches, but live with a slightly lower priority (within its category) in the meantime. A thread can use the AvTaskIndexYield function to indicate the next time it must be allowed to run, specifying the time it needs to get the highest priority within its category. Until that time arrives, it gets the lowest priority within its category, potentially freeing more CPU time to the system*"
>
> — Windows Internals, [E7, P1: 'Priority boosts for multimedia applications and games'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

```c
// CiConfigInitialize
WPP_MAIN_CB.ActiveThreadCount =
  CiConfigReadDWORD(KeyHandle, 0x1C00110D0LL, 10000LL); // SchedulerTimerResolution, fallback = 10000

if ( WPP_MAIN_CB.ActiveThreadCount > 0x2710 ) // 0x2710 = 10000
  WPP_MAIN_CB.ActiveThreadCount = 10000; // upper clamp
```

```c
// CiSchedulerTaskIndexYield
if ( a2 < WPP_MAIN_CB.ActiveThreadCount )
  ActiveThreadCount = WPP_MAIN_CB.ActiveThreadCount;

if ( a3 < WPP_MAIN_CB.ActiveThreadCount )
  v4 = WPP_MAIN_CB.ActiveThreadCount;
```

## MaxThreadsPerProcess / MaxThreadsTotal

Limits how many MMCSS threads can exist, `MaxThreadsTotal` is checked against `CiTotalThreads` (MMCSS threads of all processes), `MaxThreadsPerProcess` after that against the MMCSS thread count of the current process.

```c
// CiConfigInitialize
v10 = CiConfigReadDWORD(KeyHandle, 0x1C00110F0LL, 32LL); // MaxThreadsPerProcess, fallback = 32
CiMaxThreadsPerProcess = v10;
if ( (unsigned int)(v10 - 8) > 0x78 )
  CiMaxThreadsPerProcess = 32; // range 8-128

v11 = CiConfigReadDWORD(KeyHandle, 0x1C0011100LL, 256LL); // MaxThreadsTotal, fallback = 256
CiMaxThreadsTotal = v11;
if ( (unsigned int)(v11 - 64) > 0xFFBF )
  CiMaxThreadsTotal = 256; // range 64-65535
```

[`CiTryIncrementTotalThreadCount`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiTryIncrementTotalThreadCount.c) would return an error (`STATUS_TOO_MANY_THREADS`) whenever the count is at or above the maximum.

```c
// CiThreadCreate
v9 = CiTryIncrementTotalThreadCount(&CiTotalThreads, CiMaxThreadsTotal);

v9 = CiTryIncrementTotalThreadCount((volatile signed __int32 *)(v8 + 92), CiMaxThreadsPerProcess);
```

You can use WinDbg to see the current total:

```c
lkd> dd mmcss!CiTotalThreads L1
fffff800`3aee82d0  00000004
```

You can also get MMCSS thread counts from processes via WinDbg but thats not as simple which is why I won't add it here.

## Tasks

> *MMCSS uses information stored in the registry to identify supported tasks and determine the relative priority of threads performing these tasks. Each thread that is performing work related to a particular task calls the [AvSetMmMaxThreadCharacteristics](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmmaxthreadcharacteristicsa) or [AvSetMmThreadCharacteristics](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) function to inform MMCSS that it is working on that task.*"
>
> — Microsoft, [Multimedia Class Scheduler Service](https://learn.microsoft.com/en-us/windows/win32/procthread/multimedia-class-scheduler-service)

Task keys are read only if `SystemResponsiveness != 100` as already shown above. These are the default tasks:

- `Audio`
- `Capture`
- `Distribution`
- `Games`
- `Playback`
- `Pro Audio`
- `Window Manager`
- `DisplayPostProcessing`

You can see in `Thread_SetChars` (or `Thread_Join`) which task a thread registered with. I didn't see any app registering with other tasks than `Audio`/`Pro Audio` yet.

![](https://github.com/nohuto/win-config/blob/main/system/images/Thread_SetChars.png?raw=true)

### [Task Values](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ProcThread/multimedia-class-scheduler-service.md#registry-settings)

| Value | Format | Possible values |
| --- | --- | --- |
| **Affinity** | `REG_DWORD` | A bitmask that indicates the processor affinity. Both `0x00` and `0xFFFFFFFF` indicate that processor affinity is not used. |
| **Background Only** | `REG_SZ` | Indicates whether this is a background task (no user interface). The threads of a background task do not change because of a change in window focus. This value can be set to `True` or `False`. |
| **BackgroundPriority** | `REG_DWORD` | The background priority. The range of values is `1-8`. |
| **Clock Rate** | `REG_DWORD` | A hint used by MMCSS to determine the granularity of processor resource scheduling. **Windows Server 2008 and Windows Vista:** The maximum guaranteed clock rate the system uses if a thread joins this task, in 100-nanosecond intervals. Starting with Windows 7 and Windows Server 2008 R2, this guarantee was removed to reduce system power consumption.<br/> |
| **GPU Priority** | `REG_DWORD` | The GPU priority. The range of values is `0-31`. This priority is not yet used. |
| **Priority** | `REG_DWORD` | The task priority. The range of values is `1` (low) to `8` (high). For tasks with a **Scheduling Category** of High, this value is always treated as `2`. |
| **Scheduling Category** | `REG_SZ` | The scheduling category. This value can be set to High, Medium, or Low. |
| **SFIO Priority** | `REG_SZ` | The scheduled I/O priority. This value can be set to Idle, Low, Normal, or High. This value is not used. |

Some additional notes:
- `Clock Rate` range `5000-10000`, default of `10000` (not used anymore)
- `Latency Sensitive` (`REG_SZ`, can be `True`/`False`) also exists (is visible in logging), but I didn't find any point where this is used
- `Priority When Yielded` (`REG_DWORD`) range `1-19`, default of `16`
- MS adding "not used" to `GPU Priority`/`SFIO Priority` isn't really accurate, as mmcss driver doesn't read them at all
- `Background Only` isn't used

### Boosted/Exhausted Priorities

This part `For tasks with a Scheduling Category of High, this value is always treated as 2.` doesn't refer to the exhausted priority, only to the boosted priority. `Priority` gets stored as `prio - 1`, means 2 = 1, 3 = 2 etc., value 1 (which would be 0) gets clamped to 1 when calculating the exhausted priority. This doesn't mean that 1 and 2 are the same (they've the same exhaused priority), but boosted priority still differs.

The boosted priority gets calculated using the `Scheduling Category` and the `Priority` value (after subtraction), so if using category `Medium` + priority of `6` the boosted priority would be `16 + 5 = 21`. If using category `High` and `Priority = 6`, the exhausted priority would be `5`, but the boosted base is forced to `24` (by [`CiConfigTaskPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/mmcss/CiConfigTaskPolicy.c)). Relative priority can then move that boosted value within `23-26` (see [relative-priorities](https://noverse.dev/docs/win-config/system/mmcss-values/#relative-priorities)), means:

```c
// Low
boosted = 8 + (backgroundPriority - 1);

// Medium
boosted = categoryBase + (Priority - 1) + relativePriority

// High
boosted = 24 + relativePriority // with relative priority it can be 23-26
```

### [Thread Priorities](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ProcThread/multimedia-class-scheduler-service.md#thread-priorities)

The MMCSS boosts the priority of threads that are working on high-priority multimedia tasks. MMCSS determines the priority of a thread using the following factors:

- The base priority of the task.
- The *Priority* parameter of the [**AvSetMmThreadPriority**](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadpriority) function.
- Whether the application is in the foreground.
- How much CPU time is being consumed by the threads in each category.

MMCSS sets the priority of client threads depending on their scheduling category.

| Category | Priority | Description |
| --- | --- | --- |
| High | 23-26 | These threads run at a thread priority that is lower than only certain system-level tasks. This category is designed for Pro Audio tasks. |
| Medium | 16-22 | These threads are part of the application that is in the foreground. |
| Low | 8-15 | This category contains the remainder of the threads. They are guaranteed a minimum percentage of the CPU resources if required. |
| | 1-7 | These threads have used their quota of CPU resource. They can continue to run if no low-priority threads are ready to run. |

## Watching the MMCSS Boost

> "*The main mechanism behind MMCSS boosts the priority of threads inside a registered process to the priority level matching their scheduling category and relative priority within this category for a guaranteed period. It then lowers those threads to the exhausted category so that other, non-multimedia threads on the system can also get a chance to execute.*"
>
> *As discussed, changing the relative thread priorities within a process does not usually make sense, and no tool allows this because only developers understand the importance of the various threads in their programs. On the other hand, because applications must manually register with MMCSS and provide it with information about what kind of thread this is, MMCSS does have the necessary data to change these relative thread priorities—and developers are well aware that this will happen.*
>
> — Windows Internals, [E7, P1: 'Priority boosts for multimedia applications and games'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

[`mmcss_task`](https://github.com/nohuto/win-config/blob/main/system/assets/mmcss_task) calls [`AvSetMmThreadCharacteristicsW`](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadcharacteristicsw) for the used MMCSS task, optionally calls [`AvSetMmThreadPriority`](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadpriority), then keeps the thread busy (loop), this also means that the examples below make it easy to see the changes, but when capturing Spotify/audiodg it won't look the same.

This follows the `EXPERIMENT: MMCSS priority boosting` guide of [Windows Internals E7, P1](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf), but uses `mmcss_task` instead of Media Player/CPUSTRES.

Perfmon has a minumum sample rate of 1 second which isn't optimal for looking at priority switches, as the default MMCSS scheduler period is `10 ms` (`SchedulerPeriod = 100000`, means one PerfMon point can cover ~100 MMCSS cycles), which is why I used WPA & MXA to show examples. You can still use it but don't use the graph as "accurate priority changes".

1. Download [mmcss_task](https://github.com/nohuto/win-config/blob/main/system/assets/mmcss_task.exe), or build it yourself from [source](https://github.com/nohuto/win-config/blob/main/system/assets/mmcss_task):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\mmcss_task.exe
```

2. Run it with the MMCSS task you want to test, e.g.:

```powershell
.\mmcss_task.exe Audio
```

3. Start Performance Monitor & set it's priority class to `Realtime`
4. In Performance Monitor, click `Add Counter` or press `Ctrl+I`
5. Select the `Thread` object, then add `Priority Current`
6. In `Instances`, search for `mmcss_task` and select `mmcss_task/0`
7. Open graph properties and set the maximum vertical scale to `32`
8. Watch `Priority Current`

You can also change the relative priority by adding an argument (the number):

```c
// avrt.h

typedef enum _AVRT_PRIORITY
{
    AVRT_PRIORITY_VERYLOW = -2,
    AVRT_PRIORITY_LOW, // -1
    AVRT_PRIORITY_NORMAL, // 0 or nothing
    AVRT_PRIORITY_HIGH, // 1
    AVRT_PRIORITY_CRITICAL // 2
} AVRT_PRIORITY, *PAVRT_PRIORITY;
```

[MS doc](https://learn.microsoft.com/en-us/windows/win32/api/avrt/nf-avrt-avsetmmthreadpriority) doesn't define `-2`, SDK does and it works so I'll leave it.

```powershell
.\mmcss_task.exe Audio 1 # AVRT_PRIORITY_HIGH
.\mmcss_task.exe Audio -1 # AVRT_PRIORITY_LOW
```

### Relative Priorities

Spotify/audiodg seem to use `AVRT_PRIORITY_HIGH`.

Example using `Scheduling Category = High` and `Priority = 6` (this would normally always use boosted priority of 24):

| Relative priority | Range |
| --- | --- |
| `-2` | `3-23` |
| `-1` | `4-23` |
| `0` | `5-24` |
| `1` | `6-25` |
| `2` | `7-26` |

`-2` and `-1` have the same boosted priority as *High category* is clamped to `23`.

![](https://github.com/nohuto/win-config/blob/main/system/images/relativeprios.png?raw=true)

### Scheduling Category / Priority

| Color | Scheduling Category | Priority | Range |
| --- | --- | --- | --- |
| Green | `Medium` | `2` | `1-17` |
| Red | `Medium` | `3` | `2-18` |
| Purple | `Medium` | `5` | `4-20` |
| Yellow | `High` | `1` | `1-24` |

![](https://github.com/nohuto/win-config/blob/main/system/images/categories.png?raw=true)

# Timer Expiration

```asm
INIT:0000000140BA15F0 dq offset aSessionManager_5     ; "Session Manager\\Kernel"
INIT:0000000140BA15F8 dq offset aSerializetimer       ; "SerializeTimerExpiration" // default = 1
INIT:0000000140BA1600 dq offset KiSerializeTimerExpiration

INIT:0000000140BA1680 dq offset aSessionManager_5     ; "Session Manager\\Kernel"
INIT:0000000140BA1688 dq offset aEnablepercpucl       ; "EnablePerCpuClockTickScheduling" // default = 0 (exists since W11)
INIT:0000000140BA1690 dq offset KiEnableClockTimerPerCpuTickScheduling
```

## Build Differences

Everything below is based on 23H2, when comparing it to 25H2, nothing in relation to `SerializeTimerExpiration` changed, but `KiClockTimerPerCpuTickScheduling` isn't dependend on `KiSerializeTimerExpiration` anymore, when using the default `KiEnableClockTimerPerCpuTickScheduling` (`0`).

### 23H2

```c
// KeInitializeClock
if ( KiClockTimerPerCpu && KiSerializeTimerExpiration )
  KiClockTimerPerCpuTickScheduling = 1;
```

```c
lkd> db nt!KiClockTimerPerCpu L1
fffff802`30f1eaa4  01                                               .
lkd> dd nt!KiSerializeTimerExpiration L1
fffff802`30f1d03c  00000000
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff802`30f1ea45  00                                               . // not 01 as KiSerializeTimerExpiration isnt 1
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff802`30f1edc8  0000000 // default

lkd> db nt!KiClockTimerPerCpu L1
fffff807`3891eaa4  01                                               .
lkd> dd nt!KiSerializeTimerExpiration L1
fffff807`3891d03c  00000000
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff807`3891ea45  01                                               . // override as KiEnableClockTimerPerCpuTickScheduling is set to 1
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff807`3891edc8  00000001 // set to 1
```

### 25H2

```c
// KeInitializeClock
if ( KiClockTimerPerCpu )
{
  if ( !KiSerializeTimerExpiration )
  {
    // feature reporting
  }
  KiClockTimerPerCpuTickScheduling = 1;
}
```
```c
lkd> db nt!KiClockTimerPerCpu L1
fffff800`b07c5ae8  01                                               .
lkd> dd nt!KiSerializeTimerExpiration L1
fffff800`b07c4034  00000000
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff800`b07c5a85  01                                               . // isnt dependend on KiSerializeTimerExpiration anymore
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff800`b07c5e64  00000000 // default
```

## SerializeTimerExpiration

`SerializeTimerExpiration` decides which processor timer table is used for kernel timer (`KTIMER`) expiration.

- Disabled = current processor uses its own PRCB (processor control block) timer table
- Enabled = uses CPU 0 timer table (`KiProcessorBlock[0]`), only the current clock owner is allowed to enter expiration handling (this also means that CPU 0 timer table is used, but the expiration code runs on the clock owner (`KiClockTimerOwner`), see [KiDynamicTickDisableReason](https://noverse.dev/docs/win-config/system/timer-expiration/#kidynamictickdisablereason))

```c
// SerializeTimerExpiration = 1
lkd> dx -r2 ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->TimerTable.TableState
((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->TimerTable.TableState                 [Type: _KTIMER_TABLE_STATE]
    [+0x000] LastTimerExpiration [Type: unsigned __int64 [2]]
        [0]              : 0x48c22221b [Type: unsigned __int64]
        [1]              : 0x48c22221b [Type: unsigned __int64]
    [+0x010] LastTimerHand    [Type: unsigned long [2]]
        [0]              : 0x12308 [Type: unsigned long]
        [1]              : 0x12308 [Type: unsigned long]
lkd> dx -r2 ((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->TimerTable.TableState
((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->TimerTable.TableState                 [Type: _KTIMER_TABLE_STATE]
    [+0x000] LastTimerExpiration [Type: unsigned __int64 [2]]
        [0]              : 0x0 [Type: unsigned __int64]
        [1]              : 0x0 [Type: unsigned __int64]
    [+0x010] LastTimerHand    [Type: unsigned long [2]]
        [0]              : 0x0 [Type: unsigned long]
        [1]              : 0x0 [Type: unsigned long]

// SerializeTimerExpiration = 2
lkd> dx -r2 ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->TimerTable.TableState
((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->TimerTable.TableState                 [Type: _KTIMER_TABLE_STATE]
    [+0x000] LastTimerExpiration [Type: unsigned __int64 [2]]
        [0]              : 0x22edea8e [Type: unsigned __int64]
        [1]              : 0x22ec8a9a [Type: unsigned __int64]
    [+0x010] LastTimerHand    [Type: unsigned long [2]]
        [0]              : 0x8bb [Type: unsigned long]
        [1]              : 0x8bb [Type: unsigned long]
lkd> dx -r2 ((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->TimerTable.TableState
((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->TimerTable.TableState                 [Type: _KTIMER_TABLE_STATE]
    [+0x000] LastTimerExpiration [Type: unsigned __int64 [2]]
        [0]              : 0x26cb150b [Type: unsigned __int64]
        [1]              : 0x26c93fe0 [Type: unsigned __int64]
    [+0x010] LastTimerHand    [Type: unsigned long [2]]
        [0]              : 0x9b3 [Type: unsigned long]
        [1]              : 0x9b3 [Type: unsigned long]
```

> "*A critical determination that must be made when a timer is inserted is to pick the appropriate table to use—in other words, the most optimal processor choice. First, the kernel checks whether timer serialization is disabled. If it is, it then checks whether the timer has a DPC associated with its expiration, and if the DPC has been affinitized to a target processor, in which case it selects that processor's timer table. If the timer has no DPC associated with it, or if the DPC has not been bound to a processor, the kernel scans all processors in the current processor's group that have not been parked. (For more information on core parking, see Chapter 4 of Part 1.) If the current processor is parked, it picks the next closest neighboring unparked processor in the same NUMA node; otherwise, the current processor is used.*
>
> *This behavior, although highly beneficial on servers, does not typically affect client systems that much. Additionally, it makes each timer expiration event (such as a clock tick) more complex because a processor may have gone idle but still have had timers associated with it, meaning that the processor(s) still receiving clock ticks need to potentially scan everyone else's processor tables, too. Further, as various processors may be cancelling and inserting timers simultaneously, it means there's inherent asynchronous behaviors in timer expiration, which may not always be desired. This complexity makes it nearly impossible to implement Modern Standby's resiliency phase because no one single processor can ultimately remain to manage the clock. Therefore, on client systems, timer serialization is enabled if Modern Standby is available, which causes the kernel to choose CPU 0 no matter what. This allows CPU 0 to behave as the default clock owner—the processor that will always be active to pick up clock interrupts.*"
>
> — Windows Internals, [E7, P2: 'Processor selection'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/ser1-timer.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/ser1-clock.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/ser2-timer.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/ser2-clock.png?raw=true)

To read the current value, use:

```c
dd nt!KiSerializeTimerExpiration L1
```

`SerializeTimerExpiration` gets read in [`KeInitializeTimerTable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeInitializeTimerTable.c):

```c
// KeInitializeTimerTable

if ( !*(_DWORD *)(a1 + 36) ) // CPU 0
{
  if ( KiSerializeTimerExpiration ) // nonzero
  {
    if ( KiSerializeTimerExpiration != 1 )
      KiSerializeTimerExpiration = 0; // any nonzero value except 1 = forced off
  }
  else
  {
    KiSerializeTimerExpiration = (unsigned __int8)off_140C01C70[0]() != 0; // auto default
  }
}
```

The callback used for the auto default gets set in [`HalpSetPlatformFlags`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/HalpSetPlatformFlags.c):

```c
// HalpSetPlatformFlags

off_140C01C70[0] = (__int64 (__fastcall *)())HalpAcpiAoacCapable; // default used above
if ( (*(_DWORD *)(a1 + 112) & 0x200000) != 0 ) // 0x200000 = bit 21
  HalpPlatformFlags |= 8u; // HAL flag set from FADT bit 21
```

[`HalpAcpiAoacCapable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/HalpAcpiAoacCapable.c) returns `(HalpPlatformFlags & 8) != 0`, which is FADT flag bit 21:

> "*LOW_POWER_S0_IDLE_CAPABLE*
> *Bit offset 21. Indicates that the platform supports low-power idle states within the ACPI S0 system power state that are more energy efficient than any Sx sleep state. If this flag is set, Windows won't try to sleep and resume, but will instead use platform idle states and connected standby.*"
>
> — Microsoft, [Fixed ACPI Description Table (FADT)](https://learn.microsoft.com/en-us/windows-hardware/drivers/bringup/acpi-system-description-tables#fixed-acpi-description-table-fadt)

### ActiveTimerTable

Serialized expiration uses CPU 0 timer table (`KiProcessorBlock[0]`) instead of the current processors timer table ([`KiTimerExpirationDpc`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiTimerExpirationDpc.c) & [`KiCheckForTimerExpiration`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KiCheckForTimerExpiration.c) work the same), non serialized uses the current PRCB timer table.

```c
// KiSelectActiveTimerTable

if ( !KiSerializeTimerExpiration )
  return a1 + 15360; // current PRCB timer table
if ( a2 && !*(_BYTE *)(a1 + 33) )
  return 0LL; // serialized can reject non-clock-owner CPUs
return KiProcessorBlock[0] + 15360; // serialized table
```

The timer table stores queued timers until their due time (left = serialized):

![](https://github.com/nohuto/win-config/blob/main/system/images/timerqueue.png?raw=true)

*Windows Internals [Table 8-10](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)*

| KPRCB field | Type | Description |
| --- | --- | --- |
| `LastTimerHand` (`TimerTable.TableState.LastTimerHand[2]`) | Index (up to 256) | The last timer hand that was processed by this processor. In recent builds, part of TimerTable because there are now two tables. |
| `ClockOwner` | Boolean | Indicates whether the current processor is the clock owner. |
| `TimerTable` | KTIMER_TABLE | List heads for the timer table lists (256, or 512 on more recent builds). |
| `DpcNormalTimerExpiration` | Bit | Indicates that a `DISPATCH_LEVEL` interrupt has been raised to request timer expiration. |

### !timer

[`!timer`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-timer) shows where `KTIMER` objects are queued (dumps all the current registered timers), which is another way to see the timer table differences (the code blocks below show snippets from my output, not everything).

With `SerializeTimerExpiration = 1`, all timers (`KTIMER`) are queued under CPU 0:

```c
lkd> !timer
Dump system timers

PROCESSOR 0 (nt!_KTIMER_TABLE fffff8065b91dd80 - Type 0 - High precision)
List Timer             Interrupt Low/High Fire Time                  DPC/thread
 16 ffffbe86c0eee238    441c2e96 00000006 [ 5/29/2026 13:34:01.683]  thread ffffbe86c0eee640 
 19 ffffbe86d4d65180    d44c68de 00000006 [ 5/29/2026 13:38:03.591]  thread ffffbe86d4d65080 
    ffffbe86d2f31180    d44e2aeb 00000006 [ 5/29/2026 13:38:03.603]  thread ffffbe86d2f31080 
 21 ffffbe86d4d4a180    d454410b 00000006 [ 5/29/2026 13:38:03.643]  thread ffffbe86d4d4a080 

PROCESSOR 0 (nt!_KTIMER_TABLE fffff8065b91dd80 - Type 1 - Standard)
List Timer             Interrupt Low/High Fire Time                  DPC/thread
  0 ffffbe86cc224770 P  43fc2e63 00000006 [ 5/29/2026 13:34:01.473]  thread ffffbe86d4d53080 
  3 ffffbe86c7ad5710    ff76233d 00000006 [ 5/29/2026 13:39:16.007]   (DPC @ ffffbe86c7ad5750)+fffff80670ac16b0 
    ffffbe86ca9a9180    000d455a 00000007 [ 5/29/2026 13:39:16.997]  thread ffffbe86ca9a9080 
  4 ffffbe86c71dcc10    4c103c37 00000006 [ 5/29/2026 13:34:15.027]  thread ffffbe86c73ea0c0 

Total Timers: 241, Maximum List: 16
```

With `SerializeTimerExpiration = 2` (`KiSerializeTimerExpiration = 0`), timers are queued across processor timer tables:

```c
lkd> !timer
Dump system timers

PROCESSOR 0 (nt!_KTIMER_TABLE fffff807495e1d80 - Type 0 - High precision)
List Timer             Interrupt Low/High Fire Time                  DPC/thread

PROCESSOR 0 (nt!_KTIMER_TABLE fffff807495e1d80 - Type 1 - Standard)
List Timer             Interrupt Low/High Fire Time                  DPC/thread
 12 ffffd6042a34c620    4b37a16e 00000000 [ 5/29/2026 13:37:27.627]  thread ffffd60425c61080 
 22 ffffd604202ffc20    475e55fa 00000000 [ 5/29/2026 13:37:21.170]   (DPC @ ffffd604202ffc60)+fffff80750181970 
    ffffd604202ff9e0    475e55fa 00000000 [ 5/29/2026 13:37:21.170]   (DPC @ ffffd604202ffa20)

PROCESSOR 1 (nt!_KTIMER_TABLE ffffe70115adfd80 - Type 0 - High precision)
List Timer             Interrupt Low/High Fire Time                  DPC/thread
 29 ffffd60428791700    38759ca6 00000000 [ 5/29/2026 13:36:56.156]  thread ffffd60428791600 

PROCESSOR 1 (nt!_KTIMER_TABLE ffffe70115adfd80 - Type 1 - Standard)
List Timer             Interrupt Low/High Fire Time                  DPC/thread
  8 ffffd604277df180    10232936 80000000 [         NEVER         ]  thread ffffd604277df080 
110 ffffd60428bfe180    35bbf4f8 00000000 [ 5/29/2026 13:36:51.584]  thread ffffd60428bfe080 
117 ffffd60428b37700    35d7db2a 00000000 [ 5/29/2026 13:36:51.767]  thread ffffd60428b37600 
121 ffffd60427d021c0    3de6890c 00000000 [ 5/29/2026 13:37:05.285]  thread ffffd60427d020c0 

// all other processors

Total Timers: 301, Maximum List: 6
```

### KiDynamicTickDisableReason

`KiClockTimerOwner` moving between CPUs can happen through dynamic tick clock idle/resume. With dynamic tick enabled, it can stop using the periodic clock tick while the system is idle and set the clock timer for the next required due time instead, without it, it keeps using the periodic clock tick (this doesn't mean that `KiClockTimerOwner` changes). Clock owner selection also works a bit different on 23H2 when compared to 25H2, since everything below is based on 23H2 this might not be valid for all W11 builds.

Also see '[Priority Separation, KiUpdateRunTime Quantum Expiration](https://noverse.dev/docs/win-config/system/priority-separation/#kiupdateruntime-quantum-expiration)', which shows why `disabledynamictick` can stop the clock interrupts used to check quantum expiration.

![](https://github.com/nohuto/win-config/blob/main/system/images/a-6-clock.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/a-6-timer.png?raw=true)

You can use WinDbg to see the current clock owner CPU:

```c
dd nt!KiClockTimerOwner L1

// would also work
lkd> dx ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockOwner
((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockOwner : 0x1 [Type: unsigned char]
lkd> dx ((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockOwner
((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockOwner : 0x0 [Type: unsigned char]
```

![](https://github.com/nohuto/win-config/blob/main/system/images/dyntick.png?raw=true)

[`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KePrepareClockTimerForIdle.c) is that idle part:

```c
// KePrepareClockTimerForIdle

if ( !KiDynamicTickInitialized || (_BYTE)KiDynamicTickDisableReason ) // dynamic tick disabled or not initialized
  goto LABEL_5;
LOBYTE(v8) = KiLastRequestedTimeIncrement;
if ( a3 <= (unsigned int)KiLastRequestedTimeIncrement ) // idle duration too short
{
LABEL_4:
  v6 = 2;
  goto LABEL_5;
}
if ( a3 > KiMaxDynamicTickDuration )
{
  ++dword_140C41B2C;
  v9 = KiMaxDynamicTickDuration; // cap idle duration
}
v12 = _InterlockedExchange(&KiClockState, 3); // some kind of transition before entering idle?
LOBYTE(v8) = PoAllProcessorsDeepIdle(); // only continue if all processors are deep idle
if ( !(_BYTE)v8 )
{
  v6 = 1;
  goto LABEL_5;
}
```

```c
// KePrepareClockTimerForIdle

((void (__fastcall *)(__int64, unsigned __int64, __int64 *))off_140C01CA0[0])(1LL, v16, &v25); // set clock timer for the next due time
KiLogClockIncrementUpdate((_DWORD)CurrentPrcb, InterruptTimePrecise, v16, v25, 1);
KiSetPendingTick(1); // set pending clock tick flag (dx ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->PendingTickFlags)
KiClockTimerOneShotStartTime = InterruptTimePrecise;
KiEventClockStateChange(1LL, v12, &v25, &v29);
```

```c
// KePrepareClockTimerForIdle

CurrentPrcb->ClockOwner = 0; // clear current PRCB ClockOwner
```

```c
// KePrepareClockTimerForIdle

KiClockTimerNextTickTime = InterruptTimePrecise + v25; // global next tick due time
CurrentPrcb->ClockTimerState.NextTickDueTime = InterruptTimePrecise + v25; // per PRCB next tick due time
```

When the system leaves that idle state, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeResumeClockTimerFromIdle.c) resumes clock handling, if per CPU clock timers are supported (`KiClockTimerPerCpu`), this can make the selected CPU the clock owner:

```c
// KeResumeClockTimerFromIdle

if ( !KiClockTimerPerCpu
  || (KeQuerySystemAllowedCpuSetAffinity(KiClockOwnerAllowedCpuSet, (__int64 *)&KiClockOwnerAllowedCpuSetVersion),
      FirstSetRightAffinity = *p_Number,
      !(unsigned int)KeCheckProcessorAffinityEx(KiClockOwnerAllowedCpuSet, *p_Number))
  && (FirstSetRightAffinity = KeFindFirstSetRightAffinityEx(&KiIntSteerMask), FirstSetRightAffinity == -1) ) // get fallback if current CPU isn't allowed and no steered CPU found
{
  FirstSetRightAffinity = *p_Number; // use the current CPU
}
v17 = *p_Number; // current CPU number
if ( *p_Number == FirstSetRightAffinity ) // current CPU is selected clock owner
{
  if ( v14 + (unsigned int)KiLastRequestedTimeIncrement <= KiClockTimerNextTickTime )
  {
    if ( KiClockTimerPerCpu )
    {
      CurrentPrcb->ClockOwner = 1; // use current PRCB as clock owner
      LODWORD(KiClockTimerOwner) = v17; // set KiClockTimerOwner to current CPU
      if ( !(unsigned __int8)KiGetPendingTick() )
        off_140C01C90[0]();
    }
```

or move owner to another selected CPU:

```c
// KeResumeClockTimerFromIdle

else
{
  ++qword_140C41B38;
  v18 = 2;
  KiEventClockStateChange(2LL, 1LL, 0LL, 0LL);
  LODWORD(KiClockTimerOwner) = FirstSetRightAffinity; // set KiClockTimerOwner to selected CPU
  KiSendClockInterruptToClockOwner();
}
```

`KePrepareClockTimerForIdle` & `KeResumeClockTimerFromIdle` (they read `KiDynamicTickDisableReason` as shown above) would get skipped when `DISABLEDYNAMICTICK` is enabled:

```c
// KeInitializeClock

v18 = *(const char **)(a2 + 216);
qword_140C41B48 = -1LL;
qword_140C41B68 = -1LL;
if ( v18 && strstr(v18, "DISABLEDYNAMICTICK") )
  KiDynamicTickDisableReason = 1;
```

```c
db nt!KiDynamicTickInitialized L1
dd nt!KiDynamicTickDisableReason L1
```

## EnablePerCpuClockTickScheduling

`EnablePerCpuClockTickScheduling` controls `KiClockTimerPerCpuTickScheduling`, but only when `KiClockTimerPerCpu` is nonzero.

```c
db nt!KiClockTimerPerCpu L1
```

From my understanding this value has practically no meaning (when `SerializeTimerExpiration` = 1) unless you want to disable `KiClockTimerPerCpuTickScheduling`, as it depends on `KiClockTimerPerCpu` whenever the value is even used. If that returns `1` it wouldn't matter if `EnablePerCpuClockTickScheduling` = `0`/`1` (`>=2` = disable), and if it returns `0`, `EnablePerCpuClockTickScheduling` isn't used.

```c
// EnablePerCpuClockTickScheduling = 0
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff806`5df1ea45  01                                               .
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff806`5df1edc8  00000000
lkd> db nt!KiClockTimerPerCpu L1
fffff806`5df1eaa4  01                                               .

// EnablePerCpuClockTickScheduling = 1
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff800`6511ea45  01                                               .
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff800`6511edc8  00000001

// EnablePerCpuClockTickScheduling = 2
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff801`2e11ea45  00                                               .
lkd> dd nt!KiEnableClockTimerPerCpuTickScheduling L1
fffff801`2e11edc8  00000002
```

`KiClockTimerPerCpuTickScheduling` decides whether clock tick scheduling uses global clock state or per PRCB clock timer state. When it is `0`, it uses global values like `KiClockTimerNextTickTime`/`KeTimeIncrement`/`KiLastRequestedTimeIncrement`, when it is `1`, it uses `CurrentPrcb->ClockTimerState`.

Below you can see that with `KiClockTimerPerCpuTickScheduling = 01` each PRCB has its own `NextTickDueTime`/`TimeIncrement`/`LastRequestedTimeIncrement` (not following the global values), and with `00`, PRCB 1 has no own values (uses global) & PRCB 0 has values, which are equal to the global values (these aren't used), means all use the same values.

- `LastRequestedTimeIncrement` = requested timer interval
- `TimeIncrement` = actual timer interval used

You can practically see the differences here too by requesting a interval via [`NtSetTimerResolution`](https://ntdoc.m417z.com/ntsettimerresolution).

```c
// KiClockTimerPerCpuTickScheduling = 01
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff804`6bf1ea45  01                                               .
lkd> dx -r1 ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockTimerState
((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockTimerState                 [Type: _KCLOCK_TIMER_STATE]
    [+0x000] NextTickDueTime  : 0x4dd8e7478 [Type: unsigned __int64]
    [+0x008] TimeIncrement    : 0x270c [Type: unsigned long] // 0.9996 ms
    [+0x00c] LastRequestedTimeIncrement : 0x2710 [Type: unsigned long] // 1 ms
    [+0x010] OneShotState     : KClockTimerOneShotUnarmed (0) [Type: _KCLOCK_TIMER_ONE_SHOT_STATE]
    [+0x014] ExpectedWakeReason : KClockTimerKTimerExpirationPseudoHr (1) [Type: _KCLOCK_TIMER_DEADLINE_TYPE]
    [+0x018] ClockTimerEntries [Type: _KCLOCK_TIMER_DEADLINE_ENTRY [7]]
    [+0x088] ClockActive      : 0x1 [Type: unsigned char]
    [+0x08c] ClockTickTraceIndex : 0x2 [Type: unsigned long]
    [+0x090] ClockIncrementTraceIndex : 0xd [Type: unsigned long]
    [+0x098] ClockTickTraces  [Type: _KCLOCK_TICK_TRACE [16]]
    [+0x318] ClockIncrementTraces [Type: _KCLOCK_INCREMENT_TRACE [16]]
lkd> dx -r1 ((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockTimerState
((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockTimerState                 [Type: _KCLOCK_TIMER_STATE]
    [+0x000] NextTickDueTime  : 0x12e6147 [Type: unsigned __int64]
    [+0x008] TimeIncrement    : 0x26259 [Type: unsigned long] // 15.6249 ms
    [+0x00c] LastRequestedTimeIncrement : 0x2625a [Type: unsigned long] // 15.625 ms
    [+0x010] OneShotState     : KClockTimerOneShotUnarmed (0) [Type: _KCLOCK_TIMER_ONE_SHOT_STATE]
    [+0x014] ExpectedWakeReason : KClockTimerQuantumEnd (3) [Type: _KCLOCK_TIMER_DEADLINE_TYPE]
    [+0x018] ClockTimerEntries [Type: _KCLOCK_TIMER_DEADLINE_ENTRY [7]]
    [+0x088] ClockActive      : 0x0 [Type: unsigned char]
    [+0x08c] ClockTickTraceIndex : 0x7 [Type: unsigned long]
    [+0x090] ClockIncrementTraceIndex : 0x2 [Type: unsigned long]
    [+0x098] ClockTickTraces  [Type: _KCLOCK_TICK_TRACE [16]]
    [+0x318] ClockIncrementTraces [Type: _KCLOCK_INCREMENT_TRACE [16]]
lkd> dq nt!KiClockTimerNextTickTime L1
fffff804`6be41bb0  00000004`e142cb4a
lkd> dd nt!KeTimeIncrement L1
fffff804`6bf1eaf8  0000270c // 0.9996 ms
lkd> dd nt!KiLastRequestedTimeIncrement L1
fffff804`6be41ba8  00002710 // 1 ms

// KiClockTimerPerCpuTickScheduling = 00
lkd> db nt!KiClockTimerPerCpuTickScheduling L1
fffff805`33b1ea45  00                                               .
lkd> dx -r1 ((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockTimerState
((nt!_KPRCB**)&nt!KiProcessorBlock)[0]->ClockTimerState                 [Type: _KCLOCK_TIMER_STATE]
    [+0x000] NextTickDueTime  : 0x55f57b3b [Type: unsigned __int64]
    [+0x008] TimeIncrement    : 0x270c [Type: unsigned long] // 0.9996 ms
    [+0x00c] LastRequestedTimeIncrement : 0x2710 [Type: unsigned long] // 1 ms
    [+0x010] OneShotState     : KClockTimerOneShotUnarmed (0) [Type: _KCLOCK_TIMER_ONE_SHOT_STATE]
    [+0x014] ExpectedWakeReason : KClockTimerKTimerExpirationNonHr (0) [Type: _KCLOCK_TIMER_DEADLINE_TYPE]
    [+0x018] ClockTimerEntries [Type: _KCLOCK_TIMER_DEADLINE_ENTRY [7]]
    [+0x088] ClockActive      : 0x1 [Type: unsigned char]
    [+0x08c] ClockTickTraceIndex : 0x7 [Type: unsigned long]
    [+0x090] ClockIncrementTraceIndex : 0xa [Type: unsigned long]
    [+0x098] ClockTickTraces  [Type: _KCLOCK_TICK_TRACE [16]]
    [+0x318] ClockIncrementTraces [Type: _KCLOCK_INCREMENT_TRACE [16]]
lkd> dx -r1 ((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockTimerState
((nt!_KPRCB**)&nt!KiProcessorBlock)[1]->ClockTimerState                 [Type: _KCLOCK_TIMER_STATE]
    [+0x000] NextTickDueTime  : 0x0 [Type: unsigned __int64]
    [+0x008] TimeIncrement    : 0x0 [Type: unsigned long]
    [+0x00c] LastRequestedTimeIncrement : 0x0 [Type: unsigned long]
    [+0x010] OneShotState     : KClockTimerOneShotUnarmed (0) [Type: _KCLOCK_TIMER_ONE_SHOT_STATE]
    [+0x014] ExpectedWakeReason : KClockTimerKTimerExpirationNonHr (0) [Type: _KCLOCK_TIMER_DEADLINE_TYPE]
    [+0x018] ClockTimerEntries [Type: _KCLOCK_TIMER_DEADLINE_ENTRY [7]]
    [+0x088] ClockActive      : 0x0 [Type: unsigned char]
    [+0x08c] ClockTickTraceIndex : 0xe [Type: unsigned long]
    [+0x090] ClockIncrementTraceIndex : 0x0 [Type: unsigned long]
    [+0x098] ClockTickTraces  [Type: _KCLOCK_TICK_TRACE [16]]
    [+0x318] ClockIncrementTraces [Type: _KCLOCK_INCREMENT_TRACE [16]]
lkd> dq nt!KiClockTimerNextTickTime L1
fffff805`33a41bb0  00000000`60cd11f3
lkd> dd nt!KeTimeIncrement L1
fffff804`6bf1eaf8  0000270c // 0.9996 ms
lkd> dd nt!KiLastRequestedTimeIncrement L1
fffff804`6be41ba8  00002710 // 1 ms
```

```c
// KeGetNextClockTickDuration

CurrentPrcb = KeGetCurrentPrcb();
v1 = 0LL;
InterruptTimePrecise = RtlGetInterruptTimePrecise(&v5);
if ( KiClockTimerPerCpuTickScheduling )
  NextTickDueTime = CurrentPrcb->ClockTimerState.NextTickDueTime; // per PRCB next tick due time
else
  NextTickDueTime = KiClockTimerNextTickTime; // global next tick due time
```

```c
// KeGetClockTimerResolution

CurrentPrcb = KeGetCurrentPrcb();
v4 = KiClockTimerPerCpuTickScheduling == 0;
*a3 = 0;
if ( v4 )
{
  *a2 = KeTimeIncrement; // see above
  *a1 = KiLastRequestedTimeIncrement; // see above
  result = (unsigned __int8)*a3;
  if ( KiClockOwnerOneShotRequestState == 1 )
    result = 1LL;
  *a3 = result;
}
else
{
  *a2 = CurrentPrcb->ClockTimerState.TimeIncrement;
  result = CurrentPrcb->ClockTimerState.LastRequestedTimeIncrement;
  *a1 = result;
  if ( CurrentPrcb->ClockTimerState.OneShotState == KClockTimerOneShotArmed )
    *a3 = 1;
}
```

See the current state via:

```c
db nt!KiClockTimerPerCpuTickScheduling L1
dd nt!KiEnableClockTimerPerCpuTickScheduling L1 // registry value
```

### KiClockTimerPerCpu

`KiClockTimerPerCpu` is set whenever [`HalpTimerGetClockConfiguration`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/HalpTimerGetClockConfiguration.c) returns flag `0x4` (can't really tell yet what requirement that has, related to `HalpClockTimer` flag `0x1`?):

```c
// KeInitializeClock

((void (__fastcall *)(__int128 *))off_140C01C80[0])(&v23); // off_140C01C80 = HalpTimerGetClockConfiguration
if ( (v23 & 4) != 0 )
  KiClockTimerPerCpu = 1; // platform supports per CPU clock timers
if ( (v23 & 2) != 0 )
  KiClockTimerHighLatency = 1;
if ( (v23 & 1) != 0 )
  KiClockTimerAlwaysOnPresent = 1;
if ( !(_BYTE)KiDynamicTickDisableReason && (v23 & 8) == 0 )
  KiDynamicTickDisableReason = 2;
```

[`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeInitializeClock.c) only checks `KiEnableClockTimerPerCpuTickScheduling` when `KiClockTimerPerCpu` is already true:

```c
// KeInitializeClock

if ( KiClockTimerPerCpu && KiSerializeTimerExpiration ) // SerializeTimerExpiration must be 1 here (as >=2 = 0 as shown above)
  KiClockTimerPerCpuTickScheduling = 1; // serialization enables per CPU clock tick scheduling
if ( KiEnableClockTimerPerCpuTickScheduling && KiClockTimerPerCpu )
  KiClockTimerPerCpuTickScheduling = KiEnableClockTimerPerCpuTickScheduling == 1; // override
```

[`KeClockInterruptNotify`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeClockInterruptNotify.c) has a branch for `KiClockTimerPerCpuTickScheduling && !KiSerializeTimerExpiration` (means `SerializeTimerExpiration = 2` & `EnablePerCpuClockTickScheduling = 1`), but I haven't looked into what it's used for yet.

## Structures

### _KTIMER

```c
lkd> dt nt!_KTIMER
   +0x000 Header           : _DISPATCHER_HEADER
   +0x018 DueTime          : _ULARGE_INTEGER
   +0x020 TimerListEntry   : _LIST_ENTRY
   +0x030 Dpc              : Ptr64 _KDPC
   +0x038 Processor        : Uint2B
   +0x03a TimerType        : Uint2B
   +0x03c Period           : Uint4B
```

### _KTIMER_TABLE

```c
lkd> dt nt!_KTIMER_TABLE
   +0x000 TimerExpiry      : [64] Ptr64 _KTIMER
   +0x200 TimerEntries     : [2] [256] _KTIMER_TABLE_ENTRY
   +0x4200 TableState       : _KTIMER_TABLE_STATE
```

### _KTIMER_TABLE_STATE

```c
lkd> dt nt!_KTIMER_TABLE_STATE
   +0x000 LastTimerExpiration : [2] Uint8B
   +0x010 LastTimerHand    : [2] Uint4B
```

### _KTIMER_TABLE_ENTRY

```c
lkd> dt nt!_KTIMER_TABLE_ENTRY
   +0x000 Lock             : Uint8B
   +0x008 Entry            : _LIST_ENTRY
   +0x018 Time             : _ULARGE_INTEGER
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/timerexpiration1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/timerexpiration2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/timerexpiration3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/timerexpiration4.png?raw=true)

# DWM Values

DWM = Desktop Window Manager, the component *which allows for compositing visible window rendering into a single surface*. Instead of every application drawing directly to the display, each top level window normally produces content into an offscreen surface, and DWM combines the visible parts of those surfaces into the desktop image that's then presented on the monitor. Without DWM, each program would effectively draw into the visible desktop/output directly (which can cause [visual artifacts](https://github.com/nohuto/win32/blob/docs/desktop-src/LearnWin32/the-desktop-window-manager.md#the-desktop-window-manager) if a window doesn't repaint itself correctly), with DWM, each program draws into its own surface first, DWM then takes those surfaces and creates the final desktop image.

Composition means building the visible frame from multiple inputs (that are visible), so for DWM that can include normal application windows, transparent or rounded window frames, shadows, animations, blur/backdrop effects, etc. DWM decides the order (image below), and presents the result.

So for example when you've a terminal opened on the right (renders through DXGI) and a browser with a video playing on the left (wouldn't show up in [PresentMon](https://github.com/GameTechDev/PresentMon/releases) if on a empty tab as DWM can just reuse the content for the desktop frame), [PresentMon](https://github.com/GameTechDev/PresentMon/releases) can show present events for both processes while both are presenting (the browser video may show `Hardware Composed: Independent Flip` if it can use DirectFlip/iFlip + MPO, the terminal should normally be part of the composed DWM frame and it always shows up cause of the blinking cursor, I guess). If the terminal covers the browser, the browser content is no longer visible, means it no longer needs to be shown as a visible plane/surface which causes it to disappear in [PresentMon](https://github.com/GameTechDev/PresentMon/releases).

Use [PresentMon](https://github.com/GameTechDev/PresentMon/releases) without process filters to see which processes are actually producing presents and which `PresentMode` is used (only for apps that present through a graphics presentation API, e.g. DXGI, classic Win32/common control apps like my regkit project/System Informer won't show up, as their UI repainting doesn't use an DXGI swapchain).

Simple way to imagine DWM composition:

![](https://github.com/nohuto/win-config/blob/main/system/images/dwm-composition.png?raw=true)

### [Buffers, Surfaces, Presents](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#diagram-of-buffers-surfaces-and-presents)

- Presentation = showing the result of drawing work on screen
- Present = one instance of presentation, used to show drawing results from a buffer on screen (optionally with timing/metadata for when/how)
- Presentation buffer = texture containing the rendered image (apps usually have multiple buffers so one can be displayed while another is being rendered)
- Presentation surface = content placeholder that can show one buffer at a time

Means the app renders into buffers, presents one of those buffers, the surface is what DWM/presentation system can place into the desktop composition.

![](https://github.com/nohuto/win-config/blob/main/system/images/buffers-surfaces-and-presents.png?raw=true)

#### DXGI Flip Model Swapchain

Another different example including more params, see '[Swap Chain Parameters](https://www.intel.com/content/www/us/en/developer/articles/code-sample/sample-application-for-direct3d-12-flip-model-swap-chains.html)' for details on the parameters.

![](https://github.com/nohuto/win-config/blob/main/system/images/intel-presentation.png?raw=true)

### Direct Scanout

Means that presented content can be scanned out by the display hardware without first being rendered into DWMs composed desktop frame.

> "*Buffers presented by your application can be displayed by the system in a few different ways.*
>
> *The simplest way, which is the default, is that the present will be sent to DWM, and the DWM will render a frame based on the buffer that was presented. That is, there is a copy (or more accurately, a 3D render) of the presentation buffer into the backbuffer that the DWM sends to the display. This method of displaying a present is called Composition.*
>
> *A more performant mode of displaying a present would be to scan out the presentation buffer directly to hardware, and eliminate the copy that takes place. This method of displaying a present is called direct scanout. When handling presents, DWM can decide to program the hardware to directly scan out of a presentation buffer, by either assigning the buffer to a multiplane overlay plane (or MPO plane, for short), or directly flip the buffer to the hardware (known as direct flip).*
>
> *An even more performant way to display a present would be to have presents be displayed directly by the graphics kernel, and bypass the DWM entirely. This method of presentation is known as independent flip (iFlip).*
>
> — Microsoft, [Presentation modes - composition, multiplane overlay, and independent flip](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#presentation-modescomposition-multiplane-overlay-and-independent-flip)

#### Multiplane Overlay (MPO)

Used when DWM can place an app/video surface on a dedicated hardware overlay plane instead of adding it into the composed desktop frame.

> "*A type of display hardware that is able to show multiple planes shown over top of one another. Presents from the presentation manager can be displayed as part of a plane in an MPO configuration to avoid needing to copy the presentation buffer into the backbuffer that DWM sends to the display hardware."*

Means that with MPO, DWM still manages the window surface, but instead of blending that surface into the composed desktop frame, it can assign it to a hardware overlay plane. The DWM composed desktop is normally the primary plane, while MPO planes are extra hardware planes (there's also a limit of `MaxPlanes` which is why reducing `OverlayMinFPS` shouldn't be done). The final image is then created by the display hardware combining those planes, and if the display hardware handles that plane composition incorrectly, such "artifacts" can appear.

Wether an app uses MPO it usually shows as `Hardware Composed: Independent Flip`, so for example a browser playing video can show this, as the video/app surface can be placed on an overlay plane and the display hardware combines it with the DWM desktop plane. A fullscreen game for example may show `Hardware: Independent Flip` (even with MPO enabled), as it doesn't need an extra overlay plane (see DirectFlip cases below).

#### DirectFlip / iFlip

A (DXGI) swapchain buffer that can be flipped directly to the display, simplified:

- DirectFlip = app swapchain can be sent directly to display hardware instead of DWM composing it
- Independent Flip (iFlip) = DirectFlip state where the app can keep presenting directly without waking DWM every frame

DirectFlip cases:

> "*1. **DirectFlip**: Your swapchain buffers match the screen dimensions, and your window client region covers the screen. Instead of using the DWM swapchain to display on the screen, the application swapchain is used.*  
> *2. **DirectFlip with panel fitters**: Your window client region covers the screen, and your swapchain buffers are within some hardware-dependent scaling factor (for example, 0.25x to 4x) of the screen. The GPU scanout hardware is used to scale your buffer while sending it to the display.*  
> *3. **DirectFlip with multi-plane overlay (MPO)**: Your swapchain buffers are within some hardware-dependent scaling factor of your window dimensions. The DWM is able to reserve a dedicated hardware scanout plane for your application, which is then scanned out and potentially stretched to an alpha-blended sub-region of the screen.*
>
> — Microsoft, [DirectFlip](https://github.com/nohuto/win32/blob/docs/desktop-src/direct3ddxgi/for-best-performance--use-dxgi-flip-model.md#directflip)

In [PresentMon](https://github.com/GameTechDev/PresentMon/releases) ([`PresentMode` header](https://github.com/GameTechDev/PresentMon/blob/main/README-ConsoleApplication.md#csv-columns)) DirectFlip/independent flip = `Hardware: Independent Flip`/`Hardware Composed: Independent Flip` (MPO).

### [Present Modes](https://github.com/GameTechDev/PresentMon/blob/main/README-ConsoleApplication.md#csv-columns)

| PresentMode | Description |
| --- | --- |
| `Hardware: Legacy Flip` | Indicates the app took ownership of the screen, and is swapping the displayed surface every frame. (FSE) |
| `Hardware: Legacy Copy to front buffer` | Indicates the app took ownership of the screen, and is copying new contents to an already-on-screen surface every frame. |
| `Hardware: Independent Flip` | Indicates the app does not have ownership of the screen, but is still swapping the displayed surface every frame. |
| `Composed: Flip` | Indicates the app is windowed, is using ["flip model" swapchains](https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-flip-model), and is sharing its surfaces with DWM to be composed. |
| `Hardware Composed: Independent Flip` | Indicates the app is using ["flip model" swapchains](https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-flip-model), and has been granted a hardware overlay plane (MPO). |
| `Composed: Copy with GPU GDI` | Indicates the app is windowed, and is copying contents into a surface that's shared with GDI. |
| `Composed: Copy with CPU GDI` | Indicates the app is windowed, and is copying contents into a dedicated DirectX window surface. GDI contents are stored separately, and are composed together with DX contents by the DWM. |

## [Composition Swapchain Glossary](https://github.com/nohuto/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain-glossary.md)

| Term | Meaning |
| --- | --- |
| **Available (presentation buffer)** | A buffer that's safe for your application to render to without corrupting any previous presents. To be available, a buffer must have no previous presents that reference it that haven't entered into the retiring or retired state. A present may implicitly reference a buffer from a previous present if your application didn't update a surface, as is shown in the example in [Diagram of buffers, surfaces, and presents](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/comp_swapchain/comp-swapchain.md#diagram-of-buffers-surfaces-and-presents). |
| **Composition (presentation mode)** | A form of presentation in which the buffer presented by your application is copied into the backbuffer that DWM renders and sends to display hardware. This form of presentation has lower system requirements than direct scanout or iflip, but it's also less efficient. |
| **Composition Surface Handle** | A **HANDLE** that can bind a visual tree visual with a given swapchain, or presentation surface. |
| **Direct flip** | A form of presentation in which the buffer presentation by your application is sent directly to display hardware on systems that don't support multiplane overlay. |
| **Direct scanout** | A form of presentation in which the buffer presented by your application is not re-rendered into the buffer DWM sends to screen, but instead sent directly to the GPU scanout hardware. This might involve DWM assigning the buffer to a multiplane overlay plane, or it might be a mode in which the buffer is sent to the scanout hardware directly via *direct flip*. In a direct scanout presentation mode, DWM might be involved in programming the hardware to display the present, or it might be bypassed entirely when the system is in *iflip* mode. |
| **Front buffer rendering** | Drawing work issued for a buffer that is currently being displayed by the system. Depending on how the buffer is being displayed, this can result in corruption or an application hang, since Direct3D protects against issuing rendering work to buffers being displayed by scanout hardware. |
| **Hardware flip queue** | An operating system (OS) feature supported by some GPU hardware that allows GPUs to display presents independently, without CPU involvement, resulting in reduced power consumption, but potentially delaying CPU state updates such as buffer available events, present retiring fence, and present statistics. |
| **Independent flip (iflip)** | A more efficient method of direct scanout presentation in which the presents are sent directly to the GPU scanout hardware, completely bypassing the DWM. This form of presentation has higher system requirements, but allows for lower latencies, and system power savings. |
| **Multiplane overlay (MPO)** | A type of display hardware that is able to show multiple planes shown over top of one another. Presents from the presentation manager can be displayed as part of a plane in an MPO configuration to avoid needing to copy the presentation buffer into the backbuffer that DWM sends to the display hardware. |
| **Present** | A single instance of presentation. A present that is intended to show the results of a drawing operation to a single buffer to the screen. |
| **Present identifier (ID)** | An incrementing identifier, unique within a given presentation manager, associated with each present to allow it to be referred to by things such as  presentation statistics and present fences. |
| **Present queue** | A queue of presents that a presentation manager has issued but have yet to be processed by the system. All presents issued are processed in queue order, even if their target times are not increasing. That is to say, before present *n* can be process, present *n-1* must also be processed; so if subsequent presents have an earlier target time than a particular present, then they'll immediately override that particular present. |
| **(Present) target time** | The time at which a particular present should be shown on screen. The system will attempt to show the present as close to this time as it can. |
| **Presentation statistics** | information returned to your application that describe how a particular present was processed. Statistics are queued in the presentation manager to be read back by your application. |
| **Presentation surface** | a content placeholder that can be bound to a visual in a visual tree. A presentation surface can have a single displayed buffer at a time. Presentation manager presents will update the buffers for one or more presentation surfaces. |
| **Presentation** | The concept of showing the results of drawing operations on screen. |
| **Presentation buffer** | A Direct3D texture that has been associated with a presentation manager, and can therefore be presented by that presentation manager to screen. |
| **Visual tree** | A tree of visuals that describes an application's layout. The composition swapchain API issues presents to one or more visuals in a visual tree. |
| **VSync interrupt** | When a GPU displays a present, it issues a VSync interrupt to awaken the CPU to notify it that that present took place. This allows the CPU to update state such as the buffer available events, the present retiring fence, and present statistics. If the GPU supports hardware flip queue, your application can explicitly control which presents should force a VSync interrupt and immediately update state, and which presents should not, allowing for improved power efficiency at the expense of delayed feedback. |

## Registry Values

Based on pseudocode of [`dwmcore.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwmcore), [`win32kfull.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/win32kfull), [`dwm.exe`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwm), [`dwminit.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dwminit), [`uDWM.dll`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/uDWM).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm";
    // dwmcore
    "BlackOutAllReadback" = 0; // REG_DWORD (bool)
    "ConfigureInput" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableDebugColors" = 0; // REG_DWORD (bool)
    "CpuClipAASinkEnableIntermediates" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableOcclusion" = 1; // REG_DWORD (bool)
    "CpuClipAASinkEnableRender" = 1; // REG_DWORD (bool)
    "CpuClipAASinkForceEnable" = 0; // REG_DWORD (bool)
    "CpuClipAreaThreshold" = 20000; // REG_DWORD
    "CpuClipWarpPartitionThreshold" = 1024; // REG_DWORD
    "DisableDrawListCaching" = 0; // REG_DWORD (bool)
    "DisableProjectedShadows" = 0; // REG_DWORD (bool), probably related to https://learn.microsoft.com/en-us/uwp/api/windows.ui.composition.compositionprojectedshadow
                                   // "Represents a scene-based shadow calculated using the relationship between the light, the visual that casts the shadow,and the visual that receives the shadow, such that the shadow is drawn differently on each receiver."
    "EnableBackdropBlurCaching" = 1; // REG_DWORD (bool), nonzero allows updating/reusing cached backdrop blur
    "EnableCommonSuperSets" = 1; // REG_DWORD (bool)
    "EnableCpuClipping" = 1; // REG_DWORD (bool)
    "EnableDDisplayScanoutCaching" = 1; // REG_DWORD (bool)
    "EnableEffectCaching" = 1; // REG_DWORD (bool)
    "EnableFrontBufferRenderChecks" = 1; // REG_DWORD (bool)
    "EnableMegaRects" = 1; // REG_DWORD (bool)
    "EnablePrimitiveReordering" = 1; // REG_DWORD (bool)
    "ForceDesktopTreeFullDirty" = 0; // REG_DWORD (bool)
    "GammaBlendPencil" = 1; // REG_DWORD (bool)
    "GammaBlendWithFP16" = 1; // REG_DWORD (bool)
    "InkGPUAccelOverrideVendorWhitelist" = 0; // REG_DWORD (bool)
    "LayerClippingMode" = 2; // REG_DWORD
    "LogExpressionPerfStats" = 0; // REG_DWORD (bool)
    "MajorityScreenTest_MaxCoverage" = 10; // REG_DWORD
    "MajorityScreenTest_MinArea" = 80; // REG_DWORD
    "MajorityScreenTest_MinLength" = 80; // REG_DWORD
    "MaxD3DFeatureLevel" = 0; // REG_DWORD
    "MegaRectSearchCount" = 100; // REG_DWORD
    "MegaRectSize" = 100000; // REG_DWORD
    "MousewheelAnimationDurationMs" = 250; // REG_DWORD
    "MousewheelScrollingMode" = 0; // REG_DWORD
    "OptimizeForDirtyExpressions" = 1; // REG_DWORD (bool)
    "OverlayMinFPS" = 15; // If this value is present and set to zero, the DWM disables its minimum frame rate requirement for assigning DirectX swap chains to overlay planes in hardware that supports overlays. This makes it more likely that a low frame rate swap chain will get assigned and stay assigned to an overlay plane, if available. (https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/dwm/registry-values.md)
                          // Practically means that currently only swapchains with a min FPS of 15 would get their (MPO) overlay plane, but since overlay planes aren't unlimited ("MaxPlanes" which is sometimes only 2 and the primary DWM plane is included in there) that shouldn't be lowered
                          // You can see your MaxPlanes via dxdiag (click "Save All Information" then search for MPO MaxPlanes)
    "RenderThreadTimeoutMilliseconds" = 5000; // REG_DWORD, range 0-4294967295, threshold for the DWM compositor scheduler loop
    "SuperWetEnabled" = 1; // REG_DWORD (bool)
    "SuperWetExtensionTimeMicroseconds" = 1000; // REG_DWORD
    "TelemetryFramesReportPeriodMilliseconds" = 300000; // REG_DWORD
    "TelemetryFramesSequenceIdleIntervalMilliseconds" = 1000; // REG_DWORD
    "TelemetryFramesSequenceMaximumPeriodMilliseconds" = 1000; // REG_DWORD
    "UniformSpaceDpiMode" = 1; // REG_DWORD (bool)
    "UseHWDrawListEntriesOnWARP" = 0; // REG_DWORD (bool)

    // dwmcore CCommonRegistryData::InitializeDWMKeysFromRegistry
    "BackdropBlurCachingThrottleMs" = 25; // REG_DWORD (ms), >1000 = 1000, throttles cached backdrop blur invalidation/rebuilds
    "CpuClipFlatteningTolerance" = 0; // REG_DWORD
    "CustomRefreshRateMode" = 0; // REG_DWORD, range 0-2, >2 = default
    "DisableAdvancedDirectFlip" = 0; // REG_DWORD
    "DisableIndependentFlip" = 0; // REG_DWORD (bool)
    "DisableProjectedShadowsRendering" = 0; // REG_DWORD, read but seems unused
    "EnableRenderPathTestMode" = ?; // REG_DWORD
    "FlattenVirtualSurfaceEffectInput" = 0; // REG_DWORD (bool)
    "ForceEffectMode" = 0; // REG_DWORD, range 0-2
    "FrameCounterPosition" = 0; // REG_DWORD (bool), nonzero sets vertical debug frame counter
    "InteractionOutputPredictionDisabled" = 0; // REG_DWORD (bool)
    "OverlayTestMode" = 0; // REG_DWORD, 4 = forced MPO support, 5 = MPO disabled
    "ParallelModePolicy" = 1; // REG_DWORD, range 0-2, >=3 = 1
    "ResampleInLinearSpace" = 0; // REG_DWORD bool, nonzero forces pixel format 91
    "ResampleModeOverride" = 0; // REG_DWORD, 0 = requested mode, 1 = Lanczos?, 2 = XBR?
    "SDRBoostPercentOverride" = 0; // REG_DWORD
    "ShaderLinkingGPUBlacklist" = ?; // REG_SZ

    // dwm CSettingsManager preferences
    "AnimationsShiftKey" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x2)
    "DisableLockingMemory" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x40)
    "ModeChangeCurtainUseDebugColor" = 0; // REG_DWORD, nonzero sets bit (preference bit 0x80)
    "UseDPIScaling" = 1; // REG_DWORD, nonzero (default) sets bit (preference bit 0x1)

    // animation/colorization policy related
    "DefaultColorizationColorState" = 0; // REG_DWORD, nonzero sets bit (policy bit 0x4)
                                         // "This policy setting controls the default color for window frames when the user does not specify a color. If you enable this policy setting and specify a default color, this color is used in glass window frames, if the user does not specify a color. If you disable or do not configure this policy setting, the default internal color is used, if the user does not specify a color. Note: This policy setting can be used in conjunction with the "Prevent color changes of window frames" setting, to enforce a specific color for window frames that cannot be changed by users."
                                         // https://noverse.dev/policies?p=DWM*DwmDefaultColorizationColor_2
    "DisallowAnimations" = 0; // REG_DWORD, nonzero sets bit (policy bit 0x1) which disables DWM window animations (also causes DWM reject live preview / Aero Peek)
                              // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-SetWindowAnimation@CDesktopManager@@SAX_N@Z.c
                              // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/uDWM/-IsLivePreviewAllowed@CDesktopManager@@SA_NXZ.c
                              // "This policy setting controls the appearance of window animations such as those found when restoring, minimizing, and maximizing windows. If you enable this policy setting, window animations are turned off. If you disable or do not configure this policy setting, window animations are turned on. Changing this policy setting requires a logoff for it to be applied.
                              // https://noverse.dev/policies?p=DWM*DwmDisallowAnimations_2
    "ForceDisableModeChangeAnimation" = 0; // REG_DWORD (bool), nonzero disables display mode change animations (duplicate/extend/disconnect style monitor change visuals)
                                           // https://blogs.windows.com/windows-insider/2024/06/13/releasing-windows-11-builds-22621-3807-and-22631-3807-to-the-release-preview-channel/
    "DisallowColorizationColorChanges" = 0; // REG_DWORD nonzero sets bit (policy bit 0x2) which blocks DWM colorization parameter changes
                                            // This policy setting controls the ability to change the color of window frames. If you enable this policy setting, you prevent users from changing the default window frame color. If you disable or do not configure this policy setting, you allow users to change the default window frame color. Note: This policy setting can be used in conjunction with the "Specify a default color for window frames" policy setting, to enforce a specific color for window frames that cannot be changed by users."
                                            // https://noverse.dev/policies?p=DWM*DwmDisallowColorizationColorChanges_1

    // uDWM colorization
    "AccentColor" = ?; // REG_DWORD, only read when ColorPrevalence is nonzero
    "AccentColorInactive" = ?; // REG_DWORD, only read when ColorPrevalence is nonzero
    "ColorPrevalence" = ?; // REG_DWORD, nonzero enables reading AccentColor/AccentColorInactive
    "ColorizationAfterglow" = 0; // REG_DWORD
    "ColorizationAfterglowBalance" = 0; // REG_DWORD
    "ColorizationBlurBalance" = 73; // REG_DWORD
    "ColorizationColor" = 0xFF409EFE; // REG_DWORD
    "ColorizationColorBalance" = 27; // REG_DWORD
    "ColorizationGlassAttribute" = 0; // REG_DWORD
    "DefaultColorizationColorAlpha" = 0; // REG_DWORD (used when DefaultColorizationColorState)
    "DefaultColorizationColorBlue" = 0; // REG_DWORD ^
    "DefaultColorizationColorGreen" = 0; // REG_DWORD ^
    "DefaultColorizationColorRed" = 0; // REG_DWORD ^
    "EnableWindowColorization" = 1; // REG_DWORD

    // uDWM compositor
    "DisableHologramCompositor" = 0; // REG_DWORD, nonzero skips holographic driver watcher registration, which seems to be used for special monitors that are ignored by DWM
                                     // https://learn.microsoft.com/en-us/windows-hardware/drivers/display/specialized-monitors
                                     // https://learn.microsoft.com/en-us/uwp/api/windows.devices.display.core

    // win32kfull
    "ChildWindowDpiIsolation" = 1; // REG_DWORD (bool)
    "DisableDeviceBitmaps" = 0; // REG_DWORD (bool), nonzero makes bDwmDeviceBitmapsEnabled return false
    "DisableDeviceBitmapsForMultiAdapter" = 0; // REG_DWORD (bool), nonzero makes bDwmDeviceBitmapsEnabledForMultiAdapter return false
    "EnableDesktopOverlays" = ?; // seems to get queried but bDwmDesktopOverlaysEnabled returns 1 ("forced"?)
    "EnableResizeOptimization" = 0; // REG_DWORD bitfield, present = override
                                  // 0x1 = resize optimization for redirected windows?, 0x2 = resize optimization with DComposition synchronization?
                                  // 0x4 = use ResizeTimeoutGdi for 0x1, 0x8 = use ResizeTimeoutModern for 0x2
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-bDwmResizeOptimizationOverride@@YAHPEAK00@Z.c
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/GreWindowResizeStarted.c
                                  // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/GreEnableWindowResizeOptimization.c
    "ResizeTimeoutGdi" = 0; // REG_DWORD, only used if 0x4 in EnableResizeOptimization set (GDI = Graphics Device Interface, a library of functions for graphics output devices and includes functions for line, text, and figure drawing and for graphics manipulation?)
    "ResizeTimeoutModern" = 0; // REG_DWORD, only used if 0x8 in EnableResizeOptimization set

    // procmon
    "AnimationAttributionEnabled" = 1; // REG_DWORD, comment marshaling for composition animation attributions (probably related to MarshalAllDebugInfo)
    "AnimationAttributionHashingEnabled" = 1; // REG_DWORD, hashes those ^ comments into GUID strings
    "CompositorClockPolicy" = 1; // ?
    "DebugFailFast" = ?;
    "DisableSessionTermination" = 0; // ?
    "DisplayChangeTimeoutMs" = 1000; // ?
    "DwmInitSessionActivityId_00000001" = ?; // REG_SZ
    "ForceBasicDisplayAdapterOnDWMRestart" = 0; // ?
    "ForceFullDirtyRendering" = 0; // ?
    "ForceUDwmSoftwareDevice" = ?; // ?
    "MarshalAllDebugInfo" = ?;
    "ParallelModeRateThreshold" = 119; // ?
    "ShowDirtyRegions" = 0; // ?
    "UseFastestMonitorAsPrimary" = 0; // ?
    "vBlankWaitTimeoutMonitorOffMs" = 250; // ?
    "WarpEnableDebugColor" = 0; // ?

    // ISM
    "CaptureDisabledFor6dof" = 0; // REG_DWORD (bool)
    "DisableBloomFor6dof" = 0; // REG_DWORD (bool)
    "EnableMPCPerfCounter" = 0; // REG_DWORD (bool)
    "MPCInputRouterWaitForDebugger" = 0; // REG_DWORD (bool)
    "OneCoreNoBootDWM" = ?; // REG_DWORD
    "OneCoreNoDWMRawGameController" = 0; // REG_DWORD (bool)
    "TouchHoverReportThrottleTimeInMs" = 100; // REG_DWORD (ms), no clamp?

"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\Scene";
    // dwmcore
    "EnableBloom" = 0; // REG_DWORD (bool)
    "EnableDrawToBackbuffer" = 1; // REG_DWORD (bool)
    "EnableImageProcessing" = 1; // REG_DWORD (bool)
    "EnableShadow" = 0; // REG_DWORD (bool)
    "ImageProcessing8bit" = 0; // REG_DWORD (bool)
    "ImageProcessingMinHeight" = 200; // REG_DWORD
    "ImageProcessingMinWidth" = 200; // REG_DWORD
    "ImageProcessingResizeGrowth" = 200; // REG_DWORD
    "MsaaQualityMode" = 2; // REG_DWORD
    "SceneVisualCutoffCountOfConsecutiveIncidentsAllowed" = 5; // REG_DWORD
    "SceneVisualCutoffThresholdInMS" = 1000; // REG_DWORD

    // dwmcore CCommonRegistryData::InitializeDWMKeysFromRegistry
    "ForceNonPrimaryDisplayAdapter" = 0; // REG_DWORD (bool)
    "ImageProcessingResizeThreshold" = 0; // REG_DWORD

"HKLM\\SOFTWARE\\Microsoft\\Windows\\Dwm\\GpuAccelInkTiming";
    // dwmcore SuperWetTiming
    "ExtensionTimeMicroseconds" = 1000; // REG_DWORD
    "PeriodicFenceMinDifferenceMicroseconds" = 500; // REG_DWORD
    "RefreshRatePercentage" = 10; // REG_DWORD

"HKLM\\SOFTWARE\\Microsoft\\Avalon.Graphics";
    // dwmcore
    "UseD3DDebugLayer" = 0; // REG_DWORD
    "Force10Level9" = 0; // REG_DWORD
    "Force10OnWDDM1_0" = 0; // REG_DWORD
```

### BackdropBlurCachingThrottleMs

It's used as a minimum time before cached blur outputs are marked dirty again (see examples below to understand what effect it has).

```c
// CCommonRegistryData::InitializeDWMKeysFromRegistry
if ( RegGetDwmDwordHelper(L"BackdropBlurCachingThrottleMs", &v11, 0LL) )
{
  v7 = v11;
  if ( v11 > 0x3E8 )
    v7 = 1000; // >1000 clamp to 1000
  v2 = g_qpcFrequency.QuadPart * v7;
}
else
{
  v2 = 25 * g_qpcFrequency.QuadPart; // missing = 25ms
}
CCommonRegistryData::m_backdropBlurCachingThrottleQPCTimeDelta = v2 / 1000;
```

[`CBackdropVisualImage::ValidateRootAndSourceRectangle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-ValidateRootAndSourceRectangle@CBackdropVisualImage@@QEAAJPEAVCVisual@@AEBV-$TMilRect_@MUMilRec.c) uses it before marking cached targets dirty again:

```c
// CBackdropVisualImage::ValidateRootAndSourceRectangle

v33 = CCommonRegistryData::m_backdropBlurCachingThrottleQPCTimeDelta & -(__int64)(*((_BYTE *)this + 1912) != 0);

if ( v32 - *((_QWORD *)v34 + 5) > v33 ) // current composition QPC time - cached target update time > throttle
{
  CCachedVisualImage::CCachedTarget::MarkDirty(v34); // rebuild afterwards
  v14 = 1;
}
```

#### Examples

You can see the differences by moving a blurry window above a animation, for example. I used a simple [rotating dot](https://github.com/nohuto/win-config/blob/main/system/assets/rotatingdot.html).

##### 1000ms

<video controls width="800">
  <source src="https://raw.githubusercontent.com/nohuto/win-config/main/system/videos/BackdropBlur1000.mp4" type="video/mp4">
</video>


##### 0ms

<video controls width="800">
  <source src="https://raw.githubusercontent.com/nohuto/win-config/main/system/videos/BackdropBlur0.mp4" type="video/mp4">
</video>

### [OverlayTestMode](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-InitializeDWMKeysFromRegistry@CCommonRegistryData@@CAXXZ.c)

See [Multiplane Overlay (MPO)](https://noverse.dev/docs/win-config/system/dwm-values/#multiplane-overlay-mpo) for what MPO is.

```c
// OverlayTestMode = 0
brave.exe[5508]:
    000001C2D33F0050 (DXGI): SyncInterval=1 Flags=256 CPU=16.715ms (59.9 fps) Display=16.675ms (60.0 fps) GPU=16.714ms Latency=22.490ms Hardware Composed: Independent Flip

// OverlayTestMode = 3
brave.exe[6944]:
    000001DD865B2050 (DXGI): SyncInterval=1 Flags=256 CPU=16.636ms (60.2 fps) Display=16.675ms (60.0 fps) GPU=16.635ms Latency=22.392ms Hardware Composed: Independent Flip

// OverlayTestMode = 5
brave.exe[4556]:
    000002AFEE8B3050 (DXGI): SyncInterval=1 Flags=256 CPU=16.643ms (60.1 fps) Display=17.046ms (58.7 fps) GPU=3.548ms Latency=22.678ms Composed: Flip

// OverlayTestMode = 6
brave.exe[4584]:
    00000218E3C90050 (DXGI): SyncInterval=1 Flags=256 CPU=38.330ms (26.1 fps) Display=43.594ms (23.0 fps) GPU=38.078ms Latency=44.017ms Hardware Composed: Independent Flip
```

| Data | Meaning |
| --- | --- |
| missing | No override of `m_dwOverlayTestMode`, I guess that's the same as `0` |
| `0` | Allows MPO and no "*OverlayColor*" ([`CDrawingContext::GetSwapChainOverlayColor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-GetSwapChainOverlayColor@CDrawingContext@@AEBA-AU_D3DCOLORVALUE@@PEAVISwapChainRealization@@PEB.c) returns zero if value is `0`) |
| `1-3` | Allows MPO + "*OverlayColor*" is enabled as the value is nonzero |
| `4` | Kind of "Force success" for MPO support ([`COverlayContext::CheckMultiPlaneOverlaySupport`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-CheckMultiPlaneOverlaySupport@COverlayContext@@CA_NAEBV-$span@PEAVCOverlayContext@@$0-0@gsl@@AE.c) bypasses support query), this doesn't mean that surfaces get a overlay plane |
| `5` | Disable MPO ([`COverlayContext::OverlaysEnabled`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-OverlaysEnabled@COverlayContext@@AEBA_NXZ.c) returns false & [`COverlayContext::IsCompatibleOutputScaling`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-IsCompatibleOutputScaling@COverlayContext@@AEAA_NAEBVCMILMatrix@@@Z.c) returns 0 for one "*CompatibleOutputScaling*") |
| `>=6` | Would go into `>=4` part in [`COverlayContext::CheckMultiPlaneOverlaySupport`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-CheckMultiPlaneOverlaySupport@COverlayContext@@CA_NAEBV-$span@PEAVCOverlayContext@@$0-0@gsl@@AE.c), but only exactly `4` has the this force success case? Using `6` does allow MPO + uses the "*OverlayColor*", so it's the same as `1-3` after all.  |

#### [GetSwapChainOverlayColor](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-GetSwapChainOverlayColor%40CDrawingContext%40%40AEBA-AU_D3DCOLORVALUE%40%40PEAVISwapChainRealization%40%40PEB.c)

The mentioned "*OverlayColor*" are overlay debug rectrangles from DWM, there are 4 different colors that DWM can use (red, yellow, orange, cyan). These colors aren't related to present modes, and I can't really tell their actual meaning yet, here's my current findings:

- Transparent = DWM draws no color
- Red = `IBitmapResource::IsWhitePixelInTopLeft()` = true
- Yellow = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` succeeds + swap chain has advanced DirectFlip
- Cyan = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` fails + no advanced DirectFlip
- Orange = `swapChain->QueryInterface(GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6)` fails (similar to cyan but it has an extra flag?)

"Advanced DirectFlip" isn't the same as DirectFlip described at the beginning.

```c
// CDrawingContext::GetSwapChainOverlayColor

v4 = CCommonRegistryData::m_dwOverlayTestMode == 0;
*(_OWORD *)&retstr->r = 0LL; // transparent
if ( v4 )
  return retstr; // OverlayTestMode = 0

if ( (*(unsigned __int8 (__fastcall **)(const struct IBitmapResource *))(*(_QWORD *)a4 + 56LL))(a4) )
{
  retstr->g = 0.0;
  retstr->b = 0.0;
  retstr->r = 1.0;
  retstr->a = 0.5; // red
  goto LABEL_12;
}

if ( v9(v8 + 8, &GUID_51e2a1f0_4a0d_4788_800f_3cee7a2512a6, &v14) < 0 )
{
  v11 = *(_BYTE *)(*((_QWORD *)this + 6) + 11297LL);
  retstr->a = 0.5;

  if ( v11 )
  {
    retstr->r = 1.0;
    retstr->g = 0.77999997;
    retstr->b = 0.055; // orange
    goto LABEL_12;
  }

  retstr->r = 0.0;
  retstr->b = 1.0; // cyan
}
else
{
  retstr->b = 0.0;
  retstr->r = 1.0;
  retstr->a = 0.5; // yellow
}

retstr->g = 1.0;
```

Example (screenshot APIs don't capture the overlay color which is why I've used my phone):

![](https://github.com/nohuto/win-config/blob/main/system/images/debugcolor.jpg?raw=true)

### [RenderThreadTimeoutMilliseconds](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/_dynamic_initializer_for__CCommonRegistryData--RenderThreadTimeoutMilliseconds__.c)

It looks like a diagnostic threshold only, which controls when DWM may write the TraceLogging event `SinceWatchdogTimerStarted` (provider `Microsoft.Windows.Dwm.DwmCore`/`{1BF43430-9464-4B83-B7FB-E2638876AEEF}`). Since the default is `5000ms` I guess this is intended to be used as a kind of "compositor thread hang" event? The value [gets read](https://github.com/nohuto/regkit/blob/main/records/Windows-Dwm.txt) but as said, this event should normally not happen & the provider shouldn't run by default (don't see this as my final answer, just as an possible description).

The related thread gets created by [`CConnection::StartCompositionThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-StartCompositionThread@CConnection@@AEAAJH@Z.c), which sets it's description to `DWM Compositor Thread`. The time is from the end of the previous [`CPartitionVerticalBlankScheduler::WaitForWork`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-WaitForWork@CPartitionVerticalBlankScheduler@@AEAAXXZ.c) call to the start of the next one.

![](https://github.com/nohuto/win-config/blob/main/system/images/compositor-thread.png?raw=true)

```c
// CPartitionVerticalBlankScheduler::WaitForWork
v4 = g_renderThreadTick;
g_renderThreadTick = 0LL;
if ( v4 )
{
  TickCount64 = GetTickCount64();
  v6 = TickCount64 - v4;
  if ( TickCount64 - v4 > (unsigned int)CCommonRegistryData::RenderThreadTimeoutMilliseconds // threshold check
    && !IsDebuggerPresent()
    && !(unsigned int)IsKernelDebuggerPresent()
    && (unsigned int)dword_1803E3B40 > 5
    && (unsigned __int8)tlgKeywordOn(&dword_1803E3B40, 0x400000000000LL) ) // provider/keyword
  {
    v32 = v6;
    si128.m128i_i64[0] = 0x1000000LL;
    _tlgWriteTemplate<long (_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),&long _tlgWriteTransfer_EventWriteTransfer(_tlgProvider_t const *,void const *,_GUID const *,_GUID const *,unsigned int,_EVENT_DATA_DESCRIPTOR *),_GUID const *,_GUID const *>::Write<_tlgWrapperByVal<8>,_tlgWrapperByVal<4>>(
      v26,
      (unsigned int)&unk_18037F354, // TraceLogging metadata, starts with "SinceWatchdogTimerStarted"
      v27,
      v28,
      (__int64)&si128,
      (__int64)&v32);
  }
}

// ...

g_renderThreadTick = GetTickCount64();
```

### MsaaQualityMode

[`CSceneResourceManager::EnsureSceneCompositor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dwmcore/-EnsureSceneCompositor@CSceneResourceManager@@AEAAJXZ.c) passes it into `DwmScene.dll` / `CreateDwmSceneRenderer` which is the only relation I found, and [`ID3D11Device::CheckMultisampleQualityLevels`](https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-id3d11device-checkmultisamplequalitylevels) seems to work the same as the part in the pseudocode.

| Data | AA quality | Sample count |
| --- | --- | --- |
| `0` | `1` | no MSAA (single sample) |
| `1` | `2` | up to `2x` MSAA |
| `2` | `3` | up to `4x` MSAA (default) |
| `3` | `4` | up to `8x` MSAA |
| `>=4` | `1` | no MSAA (fallback, same as 0) |

## RegistryMachine_* Keys

### win32kfull

Since some values above are from `win32kfull.sys` I'll add that here. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// win32kfull.sys
aRegistryMachin = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP"
aRegistryMachin_1 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
aRegistryMachin_2 = "\\Registry\\Machine\\software\\microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_3 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\EAS\\Policies"
aRegistryMachin_4 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontLink\\SystemLink"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC"
aRegistryMachin_6 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\FontDPI"
aRegistryMachin_8 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Type 1 Installer\\Type 1 Fonts"
aRegistryMachin_9 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_10 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize\\SmallFont"
aRegistryMachin_11 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\CodePage"
aRegistryMachin_13 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize"
aRegistryMachin_14 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\AutoRotation"
aRegistryMachin_15 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontLink\\"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\UIPI\\Clipboard\\ExceptionFormats"
aRegistryMachin_18 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Gre_Initialize\\LargeFont"
aRegistryMachin_19 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\UIPI\\Clipboard\\IntegrityLevelDef"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles"
aRegistryMachin_22 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC\\UserLinearityData"
aRegistryMachin_23 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\AutoRotation\\NonPreserve"
aRegistryMachin_24 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI"
aRegistryMachin_25 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Edgy"
aRegistryMachin_26 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\FontMapper\\FamilyDefaults"
aRegistryMachin_27 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TabletPC\\LinearityData"
```

### win32kbase

Added for documentational purposes and future references.

```c
// win32kbase.sys
aRegistryMachin = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\DefaultPressure"
aRegistryMachin_0 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\LegacyDevices"
aRegistryMachin_1 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Terminal Server\\Video\\"
aRegistryMachin_2 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_3 = "\\Registry\\Machine\\SYSTEM\\INPUT"
aRegistryMachin_4 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\LegacyControlled"
aRegistryMachin_5 = "\\Registry\\Machine\\Hardware\\DeviceMap\\Video"
aRegistryMachin_6 = "\\Registry\\Machine\\"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Wow6432Node\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_8 = "\\Registry\\Machine\\OSDATA\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\CIT"
aRegistryMachin_9 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\PrecisionTouchPad\\IgnoredExternalMice"
aRegistryMachin_10 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION\\WINDOWS"
aRegistryMachin_11 = "\\REGISTRY\\Machine\\System\\CurrentControlSet\\Services\\TSDDD\\Device0"
aRegistryMachin_12 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows"
aRegistryMachin_13 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\DWM"
aRegistryMachin_14 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_15 = "\\Registry\\Machine\\Software\\Microsoft\\Wisp\\Pen\\Digimon"
aRegistryMachin_16 = "\\Registry\\Machine\\SYSTEM\\Setup"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Control Panel\\Theme"
aRegistryMachin_18 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\CIT"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers"
aRegistryMachin_21 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Input\\DelayZonePalmRejection"
aRegistryMachin_22 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\State"
aRegistryMachin_23 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_24 = "\\Registry\\Machine\\Software\\Microsoft\\Wisp\\ExcludedDEvices"
aRegistryMachin_26 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\InvalidDisplay"
aRegistryMachin_27 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\"
aRegistryMachin_28 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\DPI"
aRegistryMachin_29 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Win32kWPP"
aRegistryMachin_30 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager"
aRegistryMachin_31 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows\\Control Panel\\Desktop"
aRegistryMachin_32 = "\\Registry\\Machine\\Software\\WowAA32Node\\Microsoft\\Windows\\Tablet PC"
aRegistryMachin_33 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Power"
```

# Kernel Values

## CmControlVector

CM = configuration manager, it loads & manages registry hives, inserts the `\REGISTRY` key object into the namespace and more. See regkits '[Registry fundamentals](https://noverse.dev/docs/regkit/overview/#registry-fundamentals)' documentation for more information on the topic.

`CmControlVector` is a table used by [`CmpGetSystemControlValues`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/CmpGetSystemControlValues.c) while early CM init. Each entry is `0x30` bytes (six pointers), this is just a simple way to imagine each block:

```c
struct CM_CONTROL_VECTOR_ENTRY {
  PCWSTR KeyPath; // relative to \CurrentControlSet\Control
  PCWSTR ValueName; // registry value name
  PVOID  Destination; // kernel global receiving the data
  PULONG Length; // defaults to 4 bytes when NULL (optional)
  PULONG Type; // registry type (optional)
  ULONG_PTR Flags; // checked for ControlSetOverride (optional)
};
```

The function first opens the active control set and then the `control` key, means the key paths are relative to `HKLM\SYSTEM\CurrentControlSet\Control`.

```c
// CmpGetSystemControlValues

RtlInitUnicodeString(&DestinationString, L"current"); // active control set
ControlSet = CmpFindControlSet((ULONG_PTR)&CmControlHive, v7, (int)&DestinationString, (_BYTE *)&v28 + 1);
if ( ControlSet == -1 )
  KeBugCheckEx(0x74u, 1uLL, 2uLL, (ULONG_PTR)&CmControlHive, (ULONG_PTR)&DestinationString);

RtlInitUnicodeString(&DestinationString, L"control"); // "base key" for CmControlVector
SubKeyByName = CmpFindSubKeyByName((ULONG_PTR)&CmControlHive);
if ( SubKeyByName == -1 )
  KeBugCheckEx(0x74u, 1uLL, 3uLL, v10, (ULONG_PTR)&DestinationString);
```

Table walk related snippets:

```c
// CmpGetSystemControlValues

v3 = CmControlVector; // first table entry

if ( a3 != 1 || *((_BYTE *)v3 + 40) ) // low byte of Flags

v14 = CmpWalkPath((ULONG_PTR)&CmControlHive, SubKeyByName, *v3); // KeyPath

RtlInitUnicodeString(&DestinationString, v3[1]); // ValueName
ValueByName = CmpFindValueByName((int)&CmControlHive, v16, (int)&DestinationString);

v21 = (unsigned int *)v3[3]; // Length
v22 = 4;
if ( v21 )
  v22 = *v21;

if ( v13 && !(unsigned __int8)CmpGetBootValueData(0x80000000LL, v24, v3[2], v13) ) // Destination

v26 = v3[4]; // Type
if ( v26 )
  *(_DWORD *)v26 = *(_DWORD *)(v24 + 12);

v18 = (unsigned int *)v3[3];
if ( v18 )
  *v18 = v13;

v3 += 6; // next entry
```

### Examples

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power
; ValueName = CoalescingTimerInterval
; Destination = PopCoalescingTimerInterval
; Length/Type/Flags = 0

INIT:0000000140BA2B20                 dq offset aPower_2        ; "Power"
INIT:0000000140BA2B28                 dq offset aCoalescingtime ; "CoalescingTimerInterval"
INIT:0000000140BA2B30                 dq offset PopCoalescingTimerInterval
INIT:0000000140BA2B38                 dq 3 dup(0)
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Power
; ValueName = SleepStudyDisabled
; Destination = PopSleepStudyDisabled
; Length/Type/Flags = 0

INIT:0000000140BA1B00                 dq offset aSessionManager_4 ; "Session Manager\\Power"
INIT:0000000140BA1B08                 dq offset aSleepstudydisa   ; "SleepStudyDisabled"
INIT:0000000140BA1B10                 dq offset PopSleepStudyDisabled
INIT:0000000140BA1B18                 dq 3 dup(0)
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management
; ValueName = LargePageDrivers
; Destination = MmLargePageDriverBuffer
; Length = MmLargePageDriverBufferLength
; Type/Flags = 0

INIT:0000000140BA04B0                 dq offset aSessionManager_7 ; "Session Manager\\Memory Management"
INIT:0000000140BA04B8                 dq offset aLargepagedrive ; "LargePageDrivers"
INIT:0000000140BA04C0                 dq offset MmLargePageDriverBuffer
INIT:0000000140BA04C8                 dq offset MmLargePageDriverBufferLength
INIT:0000000140BA04D0                 align 20h
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\ProductOptions
; ValueName = ProductSuite
; Destination = CmSuiteBuffer
; Length = CmSuiteBufferLength
; Type = CmSuiteBufferType
; Flags = 0

INIT:0000000140BA3870                 dq offset aProductoptions_1 ; "ProductOptions"
INIT:0000000140BA3878                 dq offset aProductsuite ; "ProductSuite"
INIT:0000000140BA3880                 dq offset CmSuiteBuffer
INIT:0000000140BA3888                 dq offset CmSuiteBufferLength
INIT:0000000140BA3890                 dq offset CmSuiteBufferType
INIT:0000000140BA3898                 dq 0
```

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management
; ValueName = VerifyDrivers
; Destination = MmVerifyDriverBuffer
; Length = MmVerifyDriverBufferLength
; Type = 0
; Flags = 1

INIT:0000000140BA0960                 dq offset aSessionManager_7 ; "Session Manager\\Memory Management"
INIT:0000000140BA0968                 dq offset aVerifydrivers ; "VerifyDrivers"
INIT:0000000140BA0970                 dq offset MmVerifyDriverBuffer
INIT:0000000140BA0978                 dq offset MmVerifyDriverBufferLength
INIT:0000000140BA0980                 dq 0
INIT:0000000140BA0988                 dq 1
```

## Registry Values

This includes details on several `HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\...` keys, not only the `Session Manager\\Kernel` key. See [diff](https://noverse.dev/diff) (globals) section for reference (or [disp-sym](https://noverse.dev/docs/windbg-notes/symbols/reading-symbols/#mass-display-symbols) if you want to display the current values). The comments of some values with more details are based on pseudocode, if so I added the function name to the end of the comment. Search for the function name in [decompiled-pseudocode/tree/main/11-23H2/ntoskrnl](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl).

| Prefix | Component |
| --- | --- |
| `Alpcp` | Advanced Local Procedure Calls |
| `Cc` | Common Cache |
| `Cm` / `Cmp` | Configuration manager |
| `Dbgk` | Debugging Framework for user mode |
| `Ex` / `Exp` | Executive support routines |
| `Hvl` | Hypervisor library |
| `Io` / `Iop` | I/O manager |
| `Kd` / `Kdp` | Kernel debugger |
| `Ke` / `Ki` | Kernel / Kernel internal |
| `Mm` | Memory manager |
| `Ob` / `Obp` | Object manager |
| `Po` / `Pop` | Power manager |
| `Ppm` | Processor power manager |
| `Ps` / `Psp` | Process support |
| `Rtlp` | Run-time library |
| `Se` / `Sep` | Security Reference Monitor |
| `Vf` / `Vi` / `Dif*` | Driver Verifier |

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel";
    "AdjustDpcThreshold" = 20; // KiAdjustDpcThreshold, per CPU countdown value. When it reaches 1, it's reloaded and current DPC queue depth is incremented up to DpcQueueDepth ("number of clock ticks before DpcQueueDepth is incremented if DPCs are not pending")
    "AlwaysTrackIoBoosting" = 0; // PspAlwaysTrackIoBoosting enabling forces IO-boost tracking part in PsBoostThreadIoEx
    "AmdTprLowerInterruptDelayConfig" = 0; // KiAmdTprLowerInterruptDelayConfig
    "BoostingPeriodMultiplier" = 3; // KiNormalPriorityBoostingPeriodMultiplier clamped to 1-20 and used as multiplier in 'NormalPriority AntiStarvation' scheduling parts
    "BugCheckUnexpectedInterrupts" = 0; // KiBugCheckUnexpectedInterrupts
    "CacheAwareScheduling" = 47; // KiCacheAwareScheduling
    "CacheErrataOverride" = 0; // KiTLBCOverride
    "CacheIsoBitmap" = 0; // KiCacheIsoBitmap
    "DebuggerIsStallOwner" = 0; // KiDebuggerIsStallOwner (KiSetDebuggerOwner)
    "DebugPollInterval" = 2000; // KiDebugPollInterval, if debugger enabled (KdDebuggerEnabled) timer path uses 10000 * value (KiGetNextTimerExpirationDueTime)
    "DefaultDynamicHeteroCpuPolicy" = 3; // KiDefaultDynamicHeteroCpuPolicy, behavior of Dynamic hetero policy All (0) (all available) Large (1) LargeOrIdle (2) Small (3) SmallOrIdle (4) Dynamic (5) (use priority and other metrics to decide) BiasedSmall (6) (use priority and other metrics, but prefer small) BiasedLarge (7).
    "DefaultHeteroCpuPolicy" = 5; // KiDefaultHeteroCpuPolicy
    "DeviceOwnerProtectionDowngradeAllowed" = 0; // SeDeviceOwnerProtectionDowngradeAllowed
    "DisableControlFlowGuardExportSuppression" = 0; // PspDisableControlFlowGuardExportSuppression
    "DisableControlFlowGuardXfg" = ? // MmDisableControlFlowGuardXfgOverride
    "DisableExceptionChainValidation" = 2; // PspSehValidationPolicy
    "DisableLightWeightSuspend" = 0; // KiDisableLightWeightSuspend, nonzero blocks lightweight suspend part in KiSuspendThread and uses the APC path (KiSuspendThread)
    "DisableLowQosTimerResolution" = 1; // KeDisableLowQosTimerResolution, uses ExpUpdateTimerResolution for specific processes etc? (PspSetProcessTimerResolutionPolicy)
    "DisablePointerParameterAlignmentValidation" = 0; // KiDisablePointerParameterAlignmentValidation
    "DisableTsx" = 0; // KiDisableTsx
    "DpcCumulativeSoftTimeout" = 120000; // KeDpcCumulativeSoftTimeoutMs, range 2000-DpcWatchdogPeriod, gets multiplied by KeVerifierDpcScalingFactor (KiInitDpcThresholds, KiApplyDpcVerificationScaleSettings)
    "DpcQueueDepth" = 4; // KiMaximumDpcQueueDepth, "Number of DPCs queued before an interrupt will be sent even for Medium or below DPCs"
    "DpcSoftTimeout" = 20000; // KeDpcSoftTimeoutMs, range 20-DPCTimeout, gets multiplied by KeVerifierDpcScalingFactor (KiInitDpcThresholds, KiApplyDpcVerificationScaleSettings)
    "DPCTimeout" = 20000; // KeDpcTimeoutMs, data 1-19 = 20, "specific DPC execution time limit control" (KiInitDpcThresholds)
    "DpcWatchdogPeriod" = 120000; // KeDpcWatchdogPeriodMs
    "DpcWatchdogProfileBufferSizeBytes" = 266240; // KeDpcWatchdogProfileBufferSizeBytes
    "DpcWatchdogProfileCumulativeDpcThreshold" = 110000; // KeDpcWatchdogProfileCumulativeDpcThresholdMs
    "DpcWatchdogProfileOffset" = 10000; // KeDpcWatchdogProfileOffsetMs
    "DpcWatchdogProfileSingleDpcThreshold" = 18333; // KeDpcWatchdogProfileSingleDpcThresholdMs
    "DriveRemappingMitigation" = 1; // ObpDriveRemappingMitigation
    "DynamicHeteroCpuPolicyExpectedRuntime" = 5200; // KiDynamicHeteroCpuPolicyExpectedRuntime
    "DynamicHeteroCpuPolicyImportant" = 2; // (LargeOrIdle)
    // Policy for a dynamic thread that is deemed important.
    "DynamicHeteroCpuPolicyImportantPriority" = 8; // KiDynamicHeteroCpuPolicyImportantPriority
    // Priority above which threads are considered important if prioritybased dynamic policy is chosen.
    "DynamicHeteroCpuPolicyImportantShort" = 3; // (Small)
    // Policy for dynamic thread that is deemed important but run a short amount of time.
    "DynamicHeteroCpuPolicyMask" = 7; // (foreground status = 1, priority = 2, expected run time = 4)
    // Determine what is considered in assessing whether a thread is important.
    "EnablePerCpuClockTickScheduling" = 0; // KiEnableClockTimerPerCpuTickScheduling, https://noverse.dev/docs/win-config/system/timer-expiration/#enablepercpuclocktickscheduling
    "EnableTickAccumulationFromAccountingPeriods" = 0; // KiEnableTickAccumulationFromAccountingPeriods, controls how CPU time used by threads etc. get counted?
                                                       // >= 2 = disabled (adds CPU time when clock ticks happen)
                                                       // 0/1/missing = enabled (measure time between accounting points)
    "EnableWerUserReporting" = 1; // DbgkEnableWerUserReporting, https://noverse.dev/docs/win-config/privacy/disable-wer/#enableweruserreporting
    "ForceBugcheckForDpcWatchdog" = 0; // KiForceBugcheckForDpcWatchdog
    "ForceForegroundBoostDecay" = 0; // KiSchedulerForegroundBoostDecayPolicy, https://noverse.dev/docs/win-config/system/priority-separation/#forceforegroundboostdecay
    "ForceIdleGracePeriod" = 5; // KiForceIdleGracePeriodInSec
    "ForceParkingRequested" = 1; // KiForceParkingConfiguration
    "GlobalTimerResolutionRequests" = 0; // KiGlobalTimerResolutionRequests
    "HeteroFavoredCoreFallback" = 0; // PpmHeteroFavoredCoreFallback
    "HeteroSchedulerOptions" = 0; // KiHeteroSchedulerOptions
    "HeteroSchedulerOptionsMask" = 0; // KiHeteroSchedulerOptionsMask
    "HgsPlusFeedbackUpdateThresholdNetRuntime" = 20;
    "HgsPlusFeedbackUpdateThresholdRuntime" = 20;
    "HgsPlusHigherPerfClassFeedbackThreshold" = 1;
    "HgsPlusInvalidFeedbackDefaultClass" = 0;
    "HgsPlusInvalidFeedbackDefaultClassSet" = 0;
    "HgsPlusInvalidFeedbackLimit" = 50;
    "HgsPlusLowerPerfClassFeedbackThreshold" = 4;
    "HgsPlusMinimumScoreDifferenceForSwap" = 25;
    "HgsPlusThreadCreationDefaultClass" = 0;
    "HotpatchTestMode" = 0; // KeHotpatchTestMode
    "HyperStartDisabled" = 0; // HvlVpStartDisabled, Hvl = Hypervisor library
    "IdealDpcRate" = 20; // KiIdealDpcRate, "Number of DPCs per clock tick before the maximum DPC queue depth is decremented if DPCs are pending but no interrupt was generated"
    "IdealNodeRandomized" = 1; // PspIdealNodeRandomized
    "InterruptSteeringFlags" = 0; // KiInterruptSteeringFlags
    "LongDpcQueueThreshold" = 3; // KiLongDpcQueueThreshold
    "LongDpcRuntimeThreshold" = 100; // KiLongDpcRuntimeThreshold
    "MaxDynamicTickDuration" = 8; // KiMaxDynamicTickDurationSize
    "MaximumCooperativeIdleSearchWidth" = 16; // KiMaximumCooperativeIdleSearchWidth
    "MaximumSharedReadyQueueSize" = 260; // KiMaximumSharedReadyQueueSize
    "MinimumDpcRate" = 3; // KiMinimumDpcRate, "Number of DPCs per clock tick where low DPCs will not cause a local interrupt to be generated"
    "MitigationAuditOptions" = 0; // PspSystemMitigationAuditOptions
    "MitigationOptions" = 0; // PspSystemMitigationOptions
    "ObCaseInsensitive" = 1; // ObpCaseInsensitive
    "ObObjectSecurityInheritance" = 0; // ObpObjectSecurityInheritance
    "ObTracePermanent" = 0; // ObpTracePermanent
    "ObTracePoolTags" = 0; // ObpTracePoolTagsBuffer / ObpTracePoolTagsLength
    "ObTraceProcessName" = 0; // ObpTraceProcessNameBuffer / ObpTraceProcessNameLength
    "ObUnsecureGlobalNames" = 6619246; // ObpUnsecureGlobalNamesBuffer / ObpUnsecureGlobalNamesLength
    "PassiveWatchdogTimeout" = 300; // KiPassiveWatchdogTimeout
    "PerfIsoEnabled" = 0; // KiPerfIsoEnabled, cache isolation aware processor placement for threads whose scheduling group KSCB has RankBias set, range 0-64dec
    "PoCleanShutdownFlags" = 0; // PopShutdownCleanly
    "PowerOffFrozenProcessors" = 1; // KiPowerOffFrozenProcessors, seems unused (but initialized), was probably used to "power off" processors that are frozen (see windbg !frozen)
    "ReadyTimeTicks" = 6; // KiNormalPriorityBoostReadyTimeTicks
    "RebalanceMinPriority" = 1; // if _KTHREAD.Priority >= KiRebalanceMinPriority (or current _KPRCB.IdleState has 0x08 set, means that processor is soft parked), its scheduling group has CPU time available & _KTHREAD.Affinity allows an idle CPU in _KSCHEDULER_SUBNODE.IdleNonParkedCpuSet, KiQueueReadyThread continues through KiEnterDeferredReadyState/KiDeferredReadyThread/KiDeferredReadySingleThread for processor selection 
                                // otherwise KiAddThreadToReadyQueue uses the current CPU
                                // default uses all threads (prio 1-31) excluding zero page thread
    "ReservedCpuSets" = 0; // KiReservedCpuSets
    "ScanLatencyTicks" = 7; // KiNormalPriorityBoostScanLatencyTicks
    "SchedulerAssistThreadFlagOverride" = 0; // KiSchedulerAssistThreadFlagOverride
    "SeAllowAllApplicationAceRemoval" = 0; // SepAllowAllApplicationAceRemoval
    "SeAllowSessionImpersonationCapability" = 0; // SepAllowSessionImpersonationCap
    "SeCompatFlags" = 0; // SeCompatFlags
    "SeLpacEnableWatsonReporting" = 0; // SeLpacEnableWatsonReporting, https://noverse.dev/docs/win-config/privacy/disable-wer/#selpacenablewatsonreporting
    "SeLpacEnableWatsonThrottling" = 1; // SeLpacEnableWatsonThrottling
    "SerializeTimerExpiration" = 1; // KiSerializeTimerExpiration, https://noverse.dev/docs/win-config/system/timer-expiration/#serializetimerexpiration
    "SeTokenDoesNotTrackSessionObject" = 0; // SeTokenDoesNotTrackSessionObject
    "SeTokenLeakDiag" = 0; // SeTokenLeakTracking
    "SeTokenSingletonAttributesConfig" = 3; // SepTokenSingletonAttributesConfig
    "SplitLargeCaches" = 0; // KiSplitLargeCaches
    "ThreadDpcEnable" = 1; // KeThreadDpcEnable
    "ThreadReadyCount" = 1; // KiNormalPriorityBoostMaximumThreadReadyCount
    "TimerCheckFlags" = 1; // REG_DWORD, KeTimerCheckFlags
    "VerifierDpcScalingFactor" = 1; // KeVerifierDpcScalingFactor
    "VirtualHeteroHysteresis" = 4294967295; // PpmPerfQosTransitionHysteresisOverride
    "VpThreadSystemWorkPriority" = 30; // KiVpThreadSystemWorkPriority
    "WpsSimulationOverride" = 0; // PpmWpsSimulationOverride / PpmWpsSimulationOverrideSize
    "XStateContextLookasidePerProcMaxDepth" = 0; // KiXStateContextLookasidePerProcMaxDepth

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\RNG";
    "RNGAuxiliarySeed" = ; // ExpRNGAuxiliarySeed, REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "AlpcMessageLog" = 0; // AlpcpMessageLogEnabled
    "AlpcWakePolicy" = 1; // AlpcpWakePolicyDefault
    "CriticalSectionTimeout" = 2592000;
    "CWDIllegalInDLLSearch" = 0; // PspCurDirDevicesSkippedForDlls, can cause "There was a problem starting PolicyAgentProvider.dll The specified module could not be found" if set to 0xFFFFFFFF (https://learn.microsoft.com/en-us/troubleshoot/mem/configmgr/client-installation/client-installation-fails-with-policyagentprovider-dll)
    "Debugger Retries" = 20; // KdpContext
    "DebuggerMaxModuleMsgs" = 500; // DbgkpMaxModuleMsgs, 0 is changed to 500 by DbgkpInitializePhase0
    "DisableIFEOCaching" = 0; // RtlpDisableIFEOCaching
    "ErrorPortCommTimeout" = 10000; // DbgkErrorPortCommTimeout
    "ErrorPortStartTimeout" = 15000; // DbgkErrorPortStartTimeout
    "GlobalFlag" = 0; // CmNtGlobalFlag <> 0x7061006c ? https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/gflags-details
    "GlobalFlag2" = 0; // CmNtGlobalFlag2 <> 0x6c642e30 ?
    // lkd> !gflag
    // Current NtGlobalFlag contents: 0x00000000
    // Current NtGlobalFlag2 contents: 0x00000000
    "HeapSegmentReserve" = 1048576; // REG_DWORD, range 65536-16580608, 65536 steps
    "HeapSegmentCommit" = 8192; // REG_DWORD, range 4096-16580608, 4096 steps
    "HeapDeCommitFreeBlockThreshold" = 4096; // REG_DWORD, range 0-4294967280, 16 steps
    "HeapDeCommitTotalFreeThreshold" = 65536; // REG_DWORD, range 0-4294967280, 16 steps
    "ImageExecutionOptions" = 0; // ViImageExecutionOptions
    "InitConsoleFlags" = 0; // InitConsoleFlags
    "MultiUsersInSessionSupported" = 0; // RtlpMultiUsersInSessionSupported
    "ObjectSecurityMode" = 1; // ObpObjectSecurityMode
    "PowerSimulateHiberBugcheck" = 4294967295; // PopSimulateHiberBugcheck
    "PowerPolicySimulate" = 0; // PopSimulate
    "ProtectionMode" = 1; // ObpProtectionMode, REG_DWORD
    "ResourceCheckFlags" = 3; // REG_DWORD, ExResourceCheckFlags
    "ResourceEnforceOwnerTransfer" = 0; // ExpResourceEnforceOwnerTransfer
    "ResourceTimeoutCount" = 45; // ExResourceTimeoutCount
    "SkipRegistryInit" = 0; // CmNtSkipRegistryInit

    // procmon boot trace
    "ObjectDirectories" = \Windows, \RPC Control; // ? - REG_MULTI_SZ
    "BootExecute" = ?; // REG_SZ
    "BootExecuteNoPnpSync" = ?;
    "PlatformExecute" = ?;
    "SetupExecute" = ?;
    "SetupExecuteNoPnpSync" = ?;
    "S0InitialCommand" = ?;
    "NumberOfInitialSessions" = 2; // ? - REG_DWORD
    "PendingFileRenameOperations" = ?;
    "PendingFileRenameOperations2" = ?;
    "AllowProtectedRenames" = ?;
    "ClearTempFiles" = ?;
    "TempFileDirectory" = ?;
    "ExcludeFromKnownDlls" = ?; // REG_MULTI_SZ
    "BackgroundLoadKnownDlls" = 0;
    "DisableWpbtExecution" = 0; // REG_DWORD (bool), https://noverse.dev/docs/win-config/security/disable-wpbt/
    "RaiseExceptionOnPossibleDeadlock" = ?;
    "ResourcePolicies" = ?;
    "SafeDllSearchMode" = ?; // https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order#standard-search-order-for-unpackaged-apps
    "SafeProcessSearchMode" = ?;
    "SmtDelayBaseYield" = ?;
    "SmtDelayMaxYield" = ?;
    "SmtDelaySleepLoopWindowSize" = ?;
    "SmtDelaySpinCountThreshold" = ?;
    "SmtFactorYield" = ?;
    "SystemUpdateOnBoot" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Quota System";
    "ApplicationBlockedMessageLimit" = 50; // PspJobNoWakeChargeLimit
    "JobTimeLimitsPeriodSeconds" = 7; // PspJobTimeLimitsPeriodSeconds
    "SystemBlockedMessageLimit" = 200; // PspSystemNoWakeChargeLimit

    // DFSS = Dynamic, fair share scheduling
    // "Dynamic fair share scheduling (DFSS) is a mechanism that can be used to fairly distribute CPU time among sessions running on a machine. It prevents one session from potentially monopolizing the CPU if some threads running under that session have a relatively high priority and run a lot."
    // Means whenever you only use a single account/session (which you most likely do, use "query session"), this has no impact for you
    "DfssGenerationLengthMS" = 600; // PsDfssGenerationLengthMS, "The generation time over which to track CPU usage"
    "DfssLongTermFraction1024" = 512; // sDfssLongTermFraction1024, "The value used in a formula for an exponential moving average used for long-term cycles computation"
    "DfssLongTermSharingMS" = 15; // PsDfssLongTermSharingMS, "The time it takes to jump from rank 0 to a non-zero rank when the threads exceed their quota within the generation cycle"
    "DfssResolutionMS" = 4294967295; // PsDfssDesiredTimerResolutionMs
    "DfssShortTermSharingMS" = 30; // PsDfssShortTermSharingMS, "The time it takes for the group rank to increase within a generation cycle"
    "EnableCpuQuota" = 0; // nonzero = DFSS enabled, if enabled PsCpuFairShareEnabled is TRUE
                          // lkd> db nt!PsCpuFairShareEnabled L1
                          // fffff807`21f1eaa0  00                                               .

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management";
    "AllocationPreference" = 0;
    "AllowUserHotPatchWithoutVbs" = 0;
    "CacheUnmapBehindLengthInMB" = 8388608; // CcUnmapBehindLength
    "CustomDTPDenominator" = 8; // CcClientDTPDenominator
    "DeadlockRecursionDepthLimit" = 0; // ViRecursionDepthLimitFromRegistry
    "DeadlockSearchNodesLimit" = 0; // ViSearchedNodesLimitFromRegistry
    "DifPluginConfigData" = 635710207; // DifPluginConfigData
    "DifPluginConfigDataLength" = 1276097421; // DifPluginConfigDataLength
    "DisableCacheTelemetry" = 2; // CcDisableTelemetryRegKeyAtInit
    "DisablePageCombining" = 0;
    "DisablePagingExecutive" = 0;
    "EnableAsyncLazywrite" = 2; // CcEnableAsyncLazywriteOverride
    "EnableAsyncLazywriteMulti" = 2; // CcEnableAsyncLazywriteMultiOverride
    "EnableCooling" = 0;
    "EnablePerVolumeLazyWriter" = 2; // CcEnablePerVolumeLazyWriterOverride
    "ForceValidateIo" = 0;
    "HighMemoryThreshold" = 0;
    "KernelPadSectionsOverride" = 0;
    "LargePageDrivers" = ?; // MmLargePageDriverBuffer, maximum length 1024 bytes
    "LargeWriteSize" = 0; // CcAzure_LargeWriteSize
    "LazyWriterPercentageOfNumProcs" = 0; // CcAzure_LazyWriterPercentageOfNumProcs
    "LowMemoryThreshold" = 0; // qword_140FC3230
    "MaxLazyWritePages" = 0; // CcMaxLazyWritePagesOverride
    "MinimumStackCommitInBytes" = 0;
    "Mirroring" = 0;
    "ModifiedWriteMaximum" = ?;
    "MoveImages" = 1; // MmRegistryState
    "NonPagedPoolQuota" = 4294967295; // PspDefaultResourceLimits
    "PagedPoolQuota" = ?; // unk_140FD7DE4
    "PageValidationAction" = 0; // MmPageValidationAction
    "PageValidationFrequency" = 0; // MmPageValidationFrequency
    "PagingFileQuota" = ?; // unk_140FD7DE8
    "PhysicalMemoryMapperEnforcementMode" = 0;
    "PoolForceFullDecommit" = 0; // PoolForceFullDecommit
    "PoolTag" = 0; // MmSpecialPoolTag, https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/gflags-details
    "PoolTagOverruns" = 1; // MmSpecialPoolCatchOverruns
    "PoolTagSmallTableSize" = 4097; // PoolTrackTableSize
    "ProtectNonPagedPool" = 0; // MmProtectFreedNonPagedPool
    "RemoteFileDirtyPageThreshold" = 1310720; // CcRemoteFileDPInlineFlushThreshold, "This value determines the maximum number of dirty pages in the cache (on a per file basis) for a remote write before an inline flush is performed."
    "SimulateCommitSavings" = 0;
    "SoftThrottleDelayInMs" = 0; // CcAzure_SoftThrottleDelayInMs
    "SoftThrottleLargeWriteAtPct" = 0; // CcAzure_SoftThrottleLargeWriteAtPct
    "SpecialPurposeMemoryPages" = 0; // MmSpecialPurposeMemoryPages
    "SpecialPurposeMemoryStartPage" = 0; // MmSpecialPurposeMemoryStartPage
    "SpecialPurposeMemoryStartPageValueSize" = 4294967295; // MmSpecialPurposeMemoryStartPageValueSize
    "TopBottomDPTEqual" = 0; // CcAzure_TopBottomDPTEqual
    "TrackLockedPages" = 0; // MmTrackLockedPages
    "TrackPtes" = 0;
    "VerifierDifPoolTags" = 0; // DifpPoolTags
    "VerifierDifPoolTagsSizeBytes" = 4294967295; // DifpPoolTagsSizeBytes
    "VerifierFaultApplications" = 0; // VerifierFaultApplicationsBuffer
    "VerifierFaultApplicationsSize" = 4294967295; // VerifierFaultApplicationsBufferSize
    "VerifierFaultBootMinutes" = 8; // VfFaultInjectionBootMinutes
    "VerifierFaultProbability" = 600; // VfFaultInjectionProbability
    "VerifierFaultTags" = 0; // VerifierFaultTagsBuffer
    "VerifierFaultTagsSize" = 4294967295; // VerifierFaultTagsBufferSize
    "VerifierHandleTraces" = 16384; // VfHandleTracingEntries
    "VerifierIrpStackTraces" = 16384; // IovIrpTracesLength
    "VerifierIrpTimeout" = 0; // VfWdIrpTimeoutMsec
    "VerifierNewRuleWorkaround" = 0; // VerifierNewRuleWorkaround
    "VerifierOptions" = 0; // VfOptionFlags
    "VerifierPoolTracesLength" = 0; // VfPoolTracesLength
    "VerifierRandomTargets" = 0; // VfRandomVerifiedDrivers
    "VerifierSettingState" = 0; // VfRuleClasses
    "VerifierSettingStateSize" = 4294967295; // VfRuleClassesSize
    "VerifierTipDisable" = 0; // VerifierTipDisable
    "VerifierTipLimitDenominator" = 0; // DifiPluginControlDenominator
    "VerifierTipLimitNumerator" = 0; // DifiPluginControlNumerator
    "VerifierTipSparseness" = 0; // DifiPluginControlSparseness
    "VerifierTriageContext" = 0; // VfTriageContext
    "VerifyBTSBufferSize" = 0; // ViVerifyBTSBufferSize
    "VerifyDriverLevel" = 4294967295; // MmVerifyDriverLevel
    "VerifyDrivers" = 3905129288; // MmVerifyDriverBuffer
    "VerifyDriversLength" = 1207968387; // MmVerifyDriverBufferLength
    "VerifyDriversSuppress" = 276138824; // VfXdvSuppressDriversBuffer
    "VerifyDriversSuppressLength" = 3482011648; // VfXdvSuppressDriversBufferLength
    "VerifyMode" = 4; // VfVerifyMode
    "VerifyTriage" = 4294967295; // ViVerifyTriage
    "VerifyTriageRules" = 0; // ViVerifyTriageRules
    "VerifyTriageRulesSize" = 4294967295; // ViVerifyTriageRulesSize
    "VmPauseOutswapSizeCapMB" = 512; // VmPauseOutswapSizeCapMB
    "WorkingSetPagesQuota" = ?; // unk_140FD7DEC
    "WorkingSetSwapSharedPages" = 0; // PspOutSwapSharedPages
    "XdvTipTag" = 0; // CarTipTag
    "XdvVerifierOptions" = 0; // CarXdvOptions
    "XdvVerifierOptions" = 0; // VfFlightOptions

    // procmon boot trace
    "PagingFiles" = C:\pagefile.sys <int> <int> // REG_MULTI_SZ
    "PagefileOnOsVolume" = ?; // 4,094
    "WaitForPagingFiles" = ?; // 4,094
    "ExistingPageFiles" = \??\C:\pagefile.sys; // REG_MULTI_SZ
    "DisableDedicatedMemoryCaching" = ?;
    "DedicatedMemoryPagefileSizeMB" = ?
    "PagefileHybridPriority" = ?;
    "SwapfileControl" = ?;
    "SwapFile" = ?;
    "TempPageFile" = ?;
    "FeatureSettings" = ? // DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Executive";
    "AdditionalCriticalWorkerThreads" = 0; // ExpAdditionalCriticalWorkerThreads
    "AdditionalDelayedWorkerThreads" = 0; // ExpAdditionalDelayedWorkerThreads
    "CoverageMaxPagedPool" = 4194304; // ExCovMaxPagedPoolToUse
    "ForceEnableMutantAutoboost" = 0; // ExpForceEnableMutantAutoboost
    "KernelWorkerTestFlags" = 0; // ExpWorkerQueueTestFlags
    "MaximumKernelWorkerThreads" = 4096; // ExpMaximumKernelWorkerThreads
    "MaxTimeSeparationBeforeCorrect" = 60; // ExpMaxTimeSeperationBeforeCorrect
    "WorkerFactoryThreadCreationTimeout" = 10; // ExpWorkerFactoryThreadCreationTimeoutInSeconds
    "WorkerFactoryThreadIdleTimeout" = 67; // ExpWorkerFactoryThreadIdleTimeoutInSeconds
    "WorkerThreadTimeoutInSeconds" = 600; // ExpWorkerThreadTimeoutInSeconds
    "TickcountRolloverDelay" = ; // ?

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "FlushPolicy" = 0; // PopFlushPolicy
    "IdleScanInterval" = 30; // PopIdleScanInterval
    "SkipTickOverride" = 1; // PopSkipTickPolicy
    "SleepStudyDeviceAccountingLevel" = 4; // PopSleepStudyDeviceAccountingLevel
    "SleepStudyDisabled" = 0; // PopSleepStudyDisabled
    "WatchdogResumeTimeout" = 120; // PopWatchdogResumeTimeout
    "WatchdogSleepTimeout" = 300; // PopWatchdogSleepTimeout
    "Win32CalloutWatchdogBugcheckEnabled" = 0; // PopWin32CalloutWatchdogBugcheckEnabled

    // PopOpenPowerKey
    "AwayModeEnabled" = 0; // REG_DWORD, range 0-1
    "HiberbootEnabled" = 1; // REG_DWORD, range 0-1
    "KernelResumeIoCpuTime" = 0; // REG_DWORD, milliseconds, range 0-4294967295
    "MaxHuffRatio" = 1; // REG_DWORD, range 1-98
    "MultiPhaseResumeDisabled" = 0; // REG_DWORD, range 0-1
    "SystemPowerPolicy" = "<STRUCT 232 BYTES>"; // REG_BINARY

    // HybridBootAnimationTime records the boot animation duration during fast boot, HiberIoCpuTime is CPU time spent on hibernation I/O during resume, ResumeCompleteTimestamp is the system timestamp when resume from hibernation completed. So all of them are just counters and changing their data won't affect the boot.
    "HybridBootAnimationTime" = 1601; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "HiberIoCpuTime" = 0; // REG_DWORD (ms), range 0-0xFFFFFFFF
    "ResumeCompleteTimestamp" = 0; // REG_QWORD, range 0-0xFFFFFFFFFFFFFFFF

    // PpmInitIllegalThrottleLogging
    "ProcessorThrottleLogInterval" = 10000; // REG_DWORD, milliseconds, range 0-10000 (values >10000 are clamped to 10000)

    // procmon boot trace
    "SleepStudyBufferSizeInMB" = ?;
    "SleepStudyHistoryDays" = ?;
    "SleepStudyPerfTrackDripsThresholdPercentage" = ?;
    "SleepStudyTraceDirectory" = ?;

"HKLM\\System\\CurrentControlSet\\Control\\Session Manager\\Throttle";
    "PerfEnablePackageIdle" = 0;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Segment Heap";
  "Enabled"; // REG_DWORD, 0 = disable, nonzero = enable (global)

// Miscellaneous values

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\LSA";
    "AuditBaseDirectories" = 0; // ObpAuditBaseDirectories
    "AuditBaseObjects" = 0; // ObpAuditBaseObjects

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\LSA\\audit";
    "ProcessAccessesToAudit" = 0; // SepProcessAccessesToAudit

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\TimeZoneInformation";
    "ActiveTimeBias" = ?;
    "Bias" = 480; // ExpAltTimeZoneBias
    "RealTimeIsUniversal" = 0; // ExpRealTimeIsUniversal

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\I/O System";
    "DisableDiskCounters" = 0; // PsDisableDiskCounters
    "IoAllowLoadCrashDumpDriver" = 0; // IopAllowLoadCrashDumpDriver
    "IoBlockLegacyFsFilters" = 0; // IopBlockLegacyFsFilters
    "IoCaseInsensitive" = 1; // IopCaseInsensitive
    "IoEnableSessionZeroAccessCheck" = 0; // IopSessionZeroAccessCheckEnabled
    "IoFailZeroAccessCreate" = 1; // IopFailZeroAccessCreate
    "IoIrpCompletionTimeoutInSeconds" = 300; // IopIrpCompletionTimeoutInSeconds
    "IoKeepAliveTimeMs" = 5000; // IopKeepAliveTimeMs
    "LargeIrpStackLocations" = 14; // IopLargeIrpStackLocations
    "MediumIrpStackLocations" = 2; // IopMediumIrpStackLocations
    "RequireDeviceAccessCheck" = 1; // IopRequireDeviceAccessCheck

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager";
    "BugcheckRecoveryEnabled" = 0; // CmBugcheckRecoveryEnabled
    "CallbackMemoryFromPerProcLookaside" = 1; // CmpAllocateCallbackMemoryFromPerProcLookaside
    "CallbackMemoryFromPool" = 0; // CmpAllocateCallbackMemoryFromPool
    "DelayCloseSize" = 2048; // CmpDelayedCloseSize
    "EnablePeriodicBackup" = 0; // CmpDoIdleProcessing, https://learn.microsoft.com/en-us/troubleshoot/windows-client/installing-updates-features-roles/system-registry-no-backed-up-regback-folder#more-information
    "FastBoot" = 1; // CmFastBoot
    "FreezeThawTimeoutInSeconds" = 60; // CmFreezeThawTimeoutInSeconds
    "RegistryFlushGlobalFlags" = 0; // CmpGlobalFlushControlFlags
    "RegistryLazyFlushBootDelay" = 60; // CmpEnableLazyFlushBootDelayInterval
    "RegistryLazyFlushInterval" = 60; // CmpLazyFlushIntervalInSeconds
    "RegistryLazyLocalizeInterval" = 60; // CmpLazyLocalizeIntervalInSeconds
    "RegistryLazyReconcileInterval" = 3600; // CmpLazyReconcileIntervalInSeconds
    "RegistryLogFileSizeCap" = 0; // CmpLogFileSizeCap
    "RegistryReorganizationLimit" = 1048576; // CmpReorganizeLimit
    "RegistryReorganizationLimitDays" = 7; // CmpReorganizeDelayDays
    "SelfHealingEnabled" = 1; // CmSelfHeal
    "SystemHiveLimitSize" = 1610612736; // CmSystemHiveLimitSize
    "VirtualizationEnabled" = 1; // CmVEEnabled
    "VolatileBoot" = 0; // CmpVolatileBoot

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager\\LastKnownGood";
    "Enabled" = 0; // CmpLKGEnabled

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\QoS";
    "StorageBaseIOSize" = 8192; // IopDiskIoAttributionBaseIoSize

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StateSeparation\\Policy";
    "AllHivesVolatile" = 0; // CmStateSeparationAllHivesVolatile
    "DevelopmentMode" = 0; // CmStateSeparationDevMode
    "Enabled" = 0; // CmStateSeparationEnabled

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\ValidationRunlevels";
    "Global" = 1210938368; // CmGlobalValidationRunlevel

"HKLM\\System\\CurrentControlSet\\Control\\Processor";
    "AllowGuestPerfStates" = 0;
    "AllowPepPerfStates" = 0;
    "Capabilities" = 0; // REG_QWORD
    "DisableAsserts" = 0;
    "Overrides" = 0;
```

### Capabilities

`Globals[0]` is the capability mask that shows what the system supports, `qword_1C00124C8` = `Capabilities` value. `Globals[0] &= ~qword_1C00124C8` removes active capability bits which are set in the registry value, so `Capabilities` is a kind of disable mask.

```c
// ProcLibGlobalInit

GetRegistryQwordValue(v13, v12, &qword_1C00124C8); // Capabilities var


if ( qword_1C00124C8 )
{
  DisplayPPMFlags(~qword_1C00124C8, 5u);
  Globals[0] &= ~qword_1C00124C8;
}
```

#### DisplayPPMFlags

Most masks below are the same for `amdppm`/`intelppm`, the labels are from [`DisplayPPMFlags`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/amdppm/DisplayPPMFlags.c) WPP metadata extracted via [`tracepdb`](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/tracepdb).

| Mask | `DisplayPPMFlags` label |
| --- | --- |
| `0x0000000000000001` | ACPI 1.0 C1 |
| `0x0000000000000002` | ACPI 1.0 C2 |
| `0x0000000000000004` | ACPI 1.0 C3 |
| `0x0000000000100000` | ACPI 1.0 IO TStates |
| `0x0000000000200000` | ACPI 1.0 MP TStates |
| `0x0000000000000010` | ACPI 2.0+ C1 |
| `0x0000000000000020` | ACPI 2.0+ C2 |
| `0x0000000000000040` | ACPI 2.0+ C3 |
| `0x000000000007F000` | ACPI 2.0+ MWAIT C-States |
| `0x0000080000000000` | ACPI 2.0+ LPI states IO |
| `0x0000020000000000` | ACPI 2.0+ LPI states MW |
| `0x0000040000000000` | ACPI 2.0+ LPI states PSCI |
| `0x00000E0000000000` | ACPI 2.0+ LPI states |
| `0x0000000001000000` | ACPI 2.0+ TStates IO |
| `0x0000000002000000` | ACPI 2.0+ TStates FFH |
| `0x0000000010000000` | ACPI 2.0+ PStates IO |
| `0x0000000020000000` | ACPI 2.0+ PStates FFH |
| `0x0000000040000000` | ACPI 2.0+ PStates XPSS |
| `0x0000000080000000` | ACPI 2.0+ Legacy PCC |
| `0x0000000008000000` | ACPI 2.0+ CPC |
| `0x0000004000000000` | ACPI 2.0+ CPC Interrupt (not used by `amdppm`?) |
| `0x0000000004000000` | ACPI 2.0+ HW Feedback |
| `0x0000000100000000` | PEP Mini-PEP Idle |
| `0x0000000200000000` | PEP Micro-PEP Idle |
| `0x0000000000000300` | PEP C-State Idle |
| `0x0000100000000000` | PEP LPI Idle |
| `0x0000000000000400` | PEP Park pref |
| `0x0000001000000000` | PEP Perf states |
| `0x0000010000000000` | PEP Notifications |
| `0x0000200000000000` | Driver Hidden Processors |
| `0x0000400000000000` | Driver VM Perf Control (not used by `amdppm`?) |
| `0x0000000800000000` | Driver Hardware Debug |
| `0x0000002000000000` | Driver Energy Estimation |

Additional masks I found that aren't in `DisplayPPMFlags`:

| Mask | Meaning |
| --- | --- |
| [`0x0000000000800000`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/amdppm/InitAcpiProcessorDomains.c) | ACPI processor domain init |
| [`0x00000010FF300000`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/amdppm/ValidatePerfDomainSymmetry.c) | performance domain validation/registration |
| [`0x0000800000000000`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/amdppm/EmiInit.c) | EMI init |
| [`0x0001000000000000`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/intelppm/InitDriver.c) | Energy counter init (not used by `amdppm`?) |

#### tracepdb

Short explanation of how to get the `DisplayPPMFlags` labels:

```powershell
.\tracepdb.exe -f "C:\Symbols\amdppm.pdb\0728D8E84177E8B0FCF8B265B1C92A591\amdppm.pdb" -p "$env:USERPROFILE\Desktop\tmf" -v
```

In [`DisplayPPMFlags`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/amdppm/DisplayPPMFlags.c) you can see the many masks + GUIDs + hex numbers, example:

```c
if ( a2 < 5u
  || LOWORD(WPP_GLOBAL_Control->DeviceType) )
{
  if ( (a1 & 0x2000000000LL) == 0 ) // mask
    v4 = "Dis";
  WPP_RECORDER_SF_s(
    (__int64)WPP_GLOBAL_Control->DeviceExtension,
    a2,
    2u,
    0x64u, // 100
    (__int64)&WPP_6d86976f8bee3b8eeb87bd96dd02b852_Traceguids, // 6d86976f-8bee-3b8e-eb87-bd96dd02b852.tmf
    v4);
}
```

```
}
#typev Unknown_cxx00 100 "%0  Energy Estimation  = %10!s!abled" //   LEVEL=DbgLevel FLAGS=PLATFORMINFO FUNC=DisplayPPMFlags
{
```

#### Default Data & Globals

See '[DriverStart + RVAs](https://noverse.dev/docs/win-config/system/mmcss-values/#driverstart--rvas)' whenever you want to read the current value on your system (you can get the variable name by looking at callers of `GetRegistryQwordValue` in `amdppm`/`intelppm`).

```c
lkd> lm m amdppm
Browse full module list
start             end                 module name
fffff801`a9130000 fffff801`a9176000   amdppm     (pdb symbols)          C:\ProgramData\Dbg\sym\amdppm.pdb\0728D8E84177E8B0FCF8B265B1C92A591\amdppm.pdb

// .data:00000001C00124C8 qword_1C00124C8 dq 0

lkd> dq fffff801`a91424c8 L1
fffff801`a91424c8  00000000`00000000
```

```c
// .data:00000001C00124C0 Globals         dq 0

lkd> dq fffff801`a91424c0 L1
fffff801`a91424c0  0000bb8c`bdd7f677
```

### TimerCheckFlags

```asm
INIT:0000000140BA1A70                 dq offset aSessionManager_5 ; "Session Manager\\Kernel"
INIT:0000000140BA1A78                 dq offset aTimercheckflag ; "TimerCheckFlags"
INIT:0000000140BA1A80                 dq offset KeTimerCheckFlags
INIT:0000000140BA1A88                 align 20h
```

`KeTimerCheckFlags` is used by [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeCheckForTimer.c), only bit `0` seems to be meaningful, means any value with that bit set should behave like `1`.

#### [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeCheckForTimer.c)

That function checks active timer tables for a timer object/DPC object/DPC routine related to the memory range being checked.

```c
// KeCheckForTimer

result = KeTimerCheckFlags;
if ( (KeTimerCheckFlags & 1) != 0 ) // bit 0 set = check enabled
{
  BugCheckParameter4 = BugCheckParameter3 + a2; // end of the checked range
  result = KeQueryActiveProcessorCountEx(0xFFFFu); // active processor count
```

If `KeTimerCheckFlags & 1` isn't set, the function returns without checking timer tables. When enabled, it checks each active processors timer tables for these addresses:

```c
// KeCheckForTimer

if ( v16 > v15 && v16 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 0LL, v16, BugCheckParameter3, BugCheckParameter4); // timer object (parameter 1 = 0x0)

if ( v17 > v15 && v17 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 1uLL, v17, BugCheckParameter3, BugCheckParameter4); // DPC object (parameter 1 = 0x1)

if ( v18 >= BugCheckParameter3 && v18 < BugCheckParameter4 )
  KeBugCheckEx(0xC7u, 2uLL, v18, BugCheckParameter3, BugCheckParameter4); // DPC routine (parameter 1 = 0x2)
```

The second argument to `KeBugCheckEx` = parameter 1 in the `0xC7` ([`TIMER_OR_DPC_INVALID`](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/debugger/bug-check-0xc7--timer-or-dpc-invalid.md)) bugcheck.

```cpp
VOID KeBugCheckEx(
  [in] ULONG     BugCheckCode,
  [in] ULONG_PTR BugCheckParameter1,
  [in] ULONG_PTR BugCheckParameter2,
  [in] ULONG_PTR BugCheckParameter3,
  [in] ULONG_PTR BugCheckParameter4
);
```

##### [TIMER_OR_DPC_INVALID](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/debugger/bug-check-0xc7--timer-or-dpc-invalid.md)

*The `TIMER_OR_DPC_INVALID` bug check has a value of `0x000000C7`. This is issued if a kernel timer or deferred procedure call (DPC) is found somewhere in memory where it is not permitted. This condition is usually caused by a driver failing to cancel a timer or DPC before freeing the memory where it resides.*

| Parameter 1 | Parameter 2 | Parameter 3 | Parameter 4 | Cause of error |
| --- | --- | --- | --- | --- |
| `0x0` | Address of the timer object | Start of memory range being checked | End of memory range being checked | The timer object was found in a block of memory where a timer object is not permitted. . |
| `0x1` | Address of the DPC object | Start of memory range being checked | End of memory range being checked | The DPC object was found in a block of memory where a DPC object is not permitted. |
| `0x2` | Address of the DPC routine | Start of memory range being checked | End of memory range being checked | The DPC routine was found in a block of memory where a DPC object is not permitted. |
| `0x3` | Address of the DPC object | Processor number | Number of processors in the system | The processor number for the DPC object is not correct. |
| `0x4` | Address of the DPC routine | The thread's APC disable count before the kernel calls the DPC routine | The thread's APC disable count after the DPC routine is called | The thread's APC disable count was changed during DPC routine execution.<br><br>The APC disable count is decremented each time a driver calls **KeEnterCriticalRegion**, **FsRtlEnterFileSystem**, or acquires a mutex.<br><br>The APC disable count is incremented each time a driver calls **KeLeaveCriticalRegion**, **KeReleaseMutex**, or **FsRtlExitFileSystem**. |
| `0x5` | Address of the DPC routine | The thread's APC disable count before the kernel calls the DPC routine | The thread's APC disable count after the DPC routine is called | The thread's APC disable count was changed during the execution of timer DPC routine.<br><br>The APC disable count is decremented each time a driver calls **KeEnterCriticalRegion**, **FsRtlEnterFileSystem**, or acquires a mutex.<br><br>The APC disable count is incremented each time a driver calls **KeLeaveCriticalRegion**, **KeReleaseMutex**, or **FsRtlExitFileSystem**. |

##### Callers

Pool free checks (in [ExpFreePoolChecks](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/ExpFreePoolChecks.c) & [ExFreeHeapPool](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/ExFreeHeapPool.c)) call [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeCheckForTimer.c) (only when `ExpPoolFlags & 1` is set?):

```c
// ExpFreePoolChecks / ExFreeHeapPool

if ( (ExpPoolFlags & 1) != 0 )
  KeCheckForTimer(BugCheckParameter3);
```

[VfMiscKeInitializeTimerEx_Entry](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/VfMiscKeInitializeTimerEx_Entry.c) calls [KeCheckForTimer](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/KeCheckForTimer.c) for the timer object range ([only until `11-23H2`](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-25H2&module=ntoskrnl&name=KeCheckForTimer.c&mode=side-by-side), builds above use [ViMiscValidateSynchronizationObject](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-25H2/ntoskrnl/ViMiscValidateSynchronizationObject.c)).

```c
// VfMiscKeInitializeTimerEx_Entry (23H2)

if ( (VfRuleClasses & 0x400000) == 0 )
  return KeCheckForTimer(*(_QWORD *)(a1 + 16), 64LL); // timer object 64 byte range check
```

```c
// VfMiscKeInitializeTimerEx_Entry (25H2)

return ViMiscValidateSynchronizationObject(*(_QWORD *)(a1 + 16));
```

### ResourceCheckFlags

```asm
INIT:0000000140BA36C0                 dq offset aSessionManager_11 ; "Session Manager"
INIT:0000000140BA36C8                 dq offset aResourcecheckf ; "ResourceCheckFlags"
INIT:0000000140BA36D0                 dq offset ExResourceCheckFlags
INIT:0000000140BA36D8                 dq 3 dup(0)
```

`ResourceCheckFlags` is related to [`TimerCheckFlags`](https://noverse.dev/docs/win-config/system/kernel-values/#timercheckflags) as both control checks for kernel objects left inside pool memory being freed, they're independent of each other as they use different `ExpPoolFlags` bits. Note that this check only runs on a single processor system.

| Data | Meaning |
| --- | --- |
| `0` (or any even value) | `ERESOURCE` check disabled |
| `3` (or any odd value) | `ERESOURCE` check enabled |

Only bit `0` of the value is read which is why any even/odd value would work.

```c
// ExpFreePoolChecks / ExFreeHeapPool

if ( (ExpPoolFlags & 1) != 0 )
  KeCheckForTimer(BugCheckParameter3); // TimerCheckFlags (timer/DPC check)
if ( (ExpPoolFlags & 4) != 0 )
  ExpCheckForResource(BugCheckParameter3, a3); // ResourceCheckFlags (ERESOURCE check)
```

[ExpCheckForResource](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/ExpCheckForResource.c) checks whether the freed range contains an `ERESOURCE` still linked in `ExpSystemResourcesList`, means `ExDeleteResourceLite` wasn't called before freeing its memory.

```c
// ExpCheckForResource

if ( ((MmVerifierData & 0x800) == 0
   || (MmVerifierData & 0x10) == 0
   || !(unsigned int)VfCheckForResource((ULONG_PTR)a1, a2))
  && (unsigned int)KeNumberProcessors_0 <= 1 // one processor
  && (ExResourceCheckFlags & 1) != 0 ) // bit 0 enables check
{
  v4 = ExAcquireSpinLockShared(&ExpResourceSpinLock);
  v5 = (__int64 *)ExpSystemResourcesList;
  v6 = v4;
  while ( v5 != &ExpSystemResourcesList )
  {
    if ( v5 >= a1 && v5 < (__int64 *)((char *)a1 + a2) ) // listed ERESOURCE inside freed range
    {
      DbgPrintEx(
        0,
        0,
        "EX: ExFreePool( %p, %Ix ) contains an ERESOURCE structure that has not been ExDeleteResourced\n",
        a1,
        a2);
      __debugbreak();
    }
    v5 = (__int64 *)*v5;
  }
}
```

### ThreadDpcEnable

```asm
INIT:0000000140BA14A0                 dq offset aSessionManager_5 ; "Session Manager\\Kernel"
INIT:0000000140BA14A8                 dq offset aThreaddpcenabl ; "ThreadDpcEnable"
INIT:0000000140BA14B0                 dq offset KeThreadDpcEnable
INIT:0000000140BA14B8                 dq 3 dup(0)
```

Has a default of `1`, and is a kind of bool, `>1` data is probably the same as `1`.

```c
lkd> dd nt!KeThreadDpcEnable L1
fffff806`6d11d17c  00000001
```

It seems to also be possible to dump the state via the [KPRCB structure](https://noverse.dev/docs/windbg-notes/system-mechanisms/processor-execution-model/processor-control-region/#_kprcb-structure) (per processor):

```c
lkd> !prcb // processor 0
PRCB for Processor 0 at fffff8026b2a4180:
Current IRQL -- 0
Threads--  Current ffff80025babc080 Next 0000000000000000 Idle fffff8026dd4d700
Processor Index 0 Number (0, 0) GroupSetMember 1
Interrupt Count -- 0001f496
Times -- Dpc    00000003 Interrupt 00000002 
         Kernel 00000cb1 User      000000bf 
lkd> dt nt!_KPRCB fffff8026b2a4180 ThreadDpcEnable
   +0x33b8 ThreadDpcEnable : 0x1 ''
lkd> !prcb 6 // processor 6
PRCB for Processor 6 at ffffd981f4fb2180:
Current IRQL -- 0
Threads--  Current ffff80025054f040 Next 0000000000000000 Idle ffff80025054f040
Processor Index 6 Number (0, 6) GroupSetMember 40
Interrupt Count -- 0008feae
Times -- Dpc    00000007 Interrupt 00000000 
         Kernel 000012a3 User      00000000 
lkd> dt nt!_KPRCB ffffd981f4fb2180 ThreadDpcEnable
   +0x33b8 ThreadDpcEnable : 0x1 ''
```

> "*A threaded DPC is a DPC that the system executes at IRQL equal to PASSIVE_LEVEL.*
> *An ordinary DPC preempts the execution of all threads, and cannot be preempted by a thread or by another DPC. If the system has a large number of ordinary DPCs queued, or if one of those DPCs runs for a long time, every thread will remain paused for an arbitrarily long time. Thus, each ordinary DPC increases system latency, which can hurt the performance of time-sensitive applications, such as audio or video playback.*
> *Conversely, a threaded DPC can be preempted by an ordinary DPC, but not by other threads. Therefore, you should use threaded DPCs rather than ordinary DPCs—unless a particular DPC must not be preempted, not even by another DPC.*"
>
> — Microsoft, [Introduction to threaded DPCs](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs)

![](https://github.com/nohuto/windbg-notes/blob/main/assets/irql-levels.png?raw=true)

[`KiInitializeProcessor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiInitializeProcessor.c) initializes per processor threaded DPC:

```c
// KiInitializeProcessor

if ( KeThreadDpcEnable )
{
  KeInitializeGate(a1 + 32320, 0);
  KiInitializeDpcList((_QWORD *)(a1 + 13168));
  *(_QWORD *)(a1 + 13184) = 0LL;
  *(_DWORD *)(a1 + 13192) = 0;
}
```

[`KeInitSystem`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitSystem.c) (same for [`KiInitializeDynamicProcessor`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiInitializeDynamicProcessor.c)) starts one DPC thread per active processor:

```c
// KeInitSystem

KiInitializeProcessor(*v13);
if ( KeThreadDpcEnable )
{
  if ( (int)KiStartDpcThread(v14) < 0 )
    break;
}
```

[`KiStartDpcThread`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiStartDpcThread.c) creates a system thread whose start routine is [`KiExecuteDpc`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiExecuteDpc.c), and that thread raises itself to priority 31 and runs DPC work through [`KiExecuteAllDpcs`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiExecuteAllDpcs.c).

#### DpcCount

A simple way to see the amount of DPCs that got executed.

- `0` = [`DPC_NORMAL`](https://doxygen.reactos.org/d7/deb/xdk_2ketypes_8h.html#a653ff687e27d13535119d66b179e2325) (ordinary)
- `1` = [`DPC_THREADED`](https://doxygen.reactos.org/d7/deb/xdk_2ketypes_8h.html#aea037d3f0bccb0e36940b37c2b9a9c71) (threaded)

```c
lkd> dt nt!_KPRCB poi(nt!KiProcessorBlock) DpcData
   +0x3340 DpcData : [2] _KDPC_DATA
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA (*)[2])0xfffff806684ef4c0))
(*((ntkrnlmp!_KDPC_DATA (*)[2])0xfffff806684ef4c0))                 [Type: _KDPC_DATA [2]]
    [0]              [Type: _KDPC_DATA] // DPC_NORMAL
    [1]              [Type: _KDPC_DATA] // DPC_THREADED
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4c0))
(*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4c0))                 [Type: _KDPC_DATA]
    [+0x000] DpcList          [Type: _KDPC_LIST]
    [+0x010] DpcLock          : 0x0 [Type: unsigned __int64]
    [+0x018] DpcQueueDepth    : 0 [Type: long]
    [+0x01c] DpcCount         : 0x16c08 [Type: unsigned long] // ordinary DPCs
    [+0x020] ActiveDpc        : 0x0 [Type: _KDPC *]
    [+0x028] LongDpcPresent   : 0x0 [Type: unsigned long]
    [+0x02c] Padding          : 0x0 [Type: unsigned long]
lkd> dx -id 0,0,ffffdc09a24ca080 -r1 (*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4f0))
(*((ntkrnlmp!_KDPC_DATA *)0xfffff806684ef4f0))                 [Type: _KDPC_DATA]
    [+0x000] DpcList          [Type: _KDPC_LIST]
    [+0x010] DpcLock          : 0x0 [Type: unsigned __int64]
    [+0x018] DpcQueueDepth    : 0 [Type: long]
    [+0x01c] DpcCount         : 0x0 [Type: unsigned long] // threaded DPCs
    [+0x020] ActiveDpc        : 0x0 [Type: _KDPC *]
    [+0x028] LongDpcPresent   : 0x0 [Type: unsigned long]
    [+0x02c] Padding          : 0x0 [Type: unsigned long]
```

#### [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/threaddpcenable1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/threaddpcenable2.png?raw=true)

## RegistryMachin_* Keys

These are from `ntoskrnl.exe`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// ntoskrnl.exe
aRegistryMachin = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Restrictions"
aRegistryMachin_0 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters"
aRegistryMachin_1 = "\\Registry\\Machine\\HARDWARE"
aRegistryMachin_2 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\FileSystems\\NTFS"
aRegistryMachin_3 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters\\CacheInfo"
aRegistryMachin_4 = "\\Registry\\Machine\\SAM\\SAM"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\AppCompatCache"
aRegistryMachin_6 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa"
aRegistryMachin_7 = "\\Registry\\Machine\\Software\\Microsoft\\SQMClient\\Windows"
aRegistryMachin_8 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage"
aRegistryMachin_9 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_10 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\CodePage"
aRegistryMachin_11 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CommonGlobUserSettings\\"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class"
aRegistryMachin_13 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WHEA"
aRegistryMachin_14 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp"
aRegistryMachin_15 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Memory Management"
aRegistryMachin_16 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"
aRegistryMachin_17 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs"
aRegistryMachin_18 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\EventLog\\Security"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\"
aRegistryMachin_20 = "\\Registry\\Machine\\OSBOOT\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_21 = "\\REGISTRY\\MACHINE"
aRegistryMachin_22 = "\\REGISTRY\\MACHINE\\HARDWARE\\RESOURCEMAP"
aRegistryMachin_23 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WMI"
aRegistryMachin_24 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_25 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices"
aRegistryMachin_26 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_27 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\ProfileSource"
aRegistryMachin_28 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\FirmwareResources"
aRegistryMachin_29 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Kernel\\KGroups"
aRegistryMachin_30 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility"
aRegistryMachin_31 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\MEMORY MANAGEMENT"
aRegistryMachin_32 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_33 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\ApiSetSchemaExtensions"
aRegistryMachin_34 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server"
aRegistryMachin_35 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides"
aRegistryMachin_36 = "\\registry\\machine\\system\\currentcontrolset\\control\\hiveredirectionlist"
aRegistryMachin_37 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions"
aRegistryMachin_38 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\HAL\\OriginalImageFeatures"
aRegistryMachin_39 = "\\Registry\\Machine\\OSBOOT\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_40 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\PnP"
aRegistryMachin_41 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood"
aRegistryMachin_42 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters"
aRegistryMachin_43 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPEs"
aRegistryMachin_44 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\TieredStorage"
aRegistryMachin_45 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_46 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_47 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel\\CPU Partitions"
aRegistryMachin_48 = "\\Registry\\MACHINE\\System\\CurrentControlSet\\Control\\CI\\NGEN"
aRegistryMachin_49 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Language"
aRegistryMachin_50 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft"
aRegistryMachin_51 = "\\Registry\\Machine\\Software\\Microsoft\\SecurityManager\\AdminCapabilities"
aRegistryMachin_52 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Config"
aRegistryMachin_53 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\VolatileNotifications"
aRegistryMachin_54 = "\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION\\SYSTEM"
aRegistryMachin_55 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StateSeparation\\RedirectionMap\\Keys"
aRegistryMachin_56 = "\\REGISTRY\\MACHINE\\OSBOOT\\ControlSetOverride\\Session Manager\\Memory Management"
aRegistryMachin_57 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GroupOrderList"
aRegistryMachin_58 = "\\REGISTRY\\MACHINE\\SYSTEM\\CONTROLSET001"
aRegistryMachin_59 = "\\Registry\\Machine\\%ws\\ControlSet%03d"
aRegistryMachin_60 = "\\Registry\\Machine\\System\\Select"
aRegistryMachin_61 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\GlobalLogger"
aRegistryMachin_62 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DedupChange"
aRegistryMachin_63 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Update\\TargetingInfo\\DynamicInstalled"
aRegistryMachin_64 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_65 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\.NETFramework"
aRegistryMachin_66 = "\\Registry\\Machine\\SYSTEM"
aRegistryMachin_67 = "\\REGISTRY\\MACHINE"
aRegistryMachin_68 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control"
aRegistryMachin_69 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters"
aRegistryMachin_70 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\HAL"
aRegistryMachin_71 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management"
aRegistryMachin_72 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM\\ROOT"
aRegistryMachin_73 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\FullLiveKernelReports"
aRegistryMachin_74 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\FileSystems\\NTFS"
aRegistryMachin_75 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_76 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services"
aRegistryMachin_77 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Notifications"
aRegistryMachin_78 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_79 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\BOOTLOG"
aRegistryMachin_80 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages\\PendingDelete"
aRegistryMachin_81 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\EncryptionCertificates\\Certificate.1"
aRegistryMachin_82 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI"
aRegistryMachin_83 = "\\registry\\machine\\system\\CurrentControlSet\\Control\\Session Manager\\Configuration Manager\\Defrag"
aRegistryMachin_84 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings"
aRegistryMachin_85 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\LsaInformation"
aRegistryMachin_86 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_87 = "\\REGISTRY\\MACHINE\\HARDWARE\\DESCRIPTION"
aRegistryMachin_88 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\AutoLogger"
aRegistryMachin_89 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPs"
aRegistryMachin_90 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\EarlyLaunch"
aRegistryMachin_91 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
aRegistryMachin_92 = "\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\EarlyLaunch"
aRegistryMachin_93 = "\\REGISTRY\\MACHINE\\SOFTWARE"
aRegistryMachin_94 = "\\REGISTRY\\MACHINE"
aRegistryMachin_95 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_96 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET"
aRegistryMachin_97 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\Hardware Profiles\\%04d"
aRegistryMachin_98 = "\\REGISTRY\\MACHINE\\SOFTWARE\\CLASSES"
aRegistryMachin_99 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Executive"
aRegistryMachin_100 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FileInfo"
aRegistryMachin_101 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\condrv"
aRegistryMachin_102 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WindowsTrustedRT\\Parameters"
aRegistryMachin_103 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_104 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\MCUpdate\\PatchConfig"
aRegistryMachin_105 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\LastCrashdump"
aRegistryMachin_106 = "\\registry\\machine\\"
aRegistryMachin_107 = "\\REGISTRY\\MACHINE\\HARDWARE\\UEFI"
aRegistryMachin_108 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem\\GroupPolicyKeys"
aRegistryMachin_109 = "\\Registry\\Machine\\HARDWARE\\UEFI"
aRegistryMachin_110 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_111 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Policies\\Microsoft\\Windows\\WDI"
aRegistryMachin_112 = "\\Registry\\Machine\\Hardware\\Description\\System"
aRegistryMachin_113 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Errata\\Dynamic"
aRegistryMachin_114 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET"
aRegistryMachin_115 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS\\CURRENTVERSION\\SHUTDOWN"
aRegistryMachin_116 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ProductOptions"
aRegistryMachin_117 = "\\REGISTRY\\MACHINE\\HARDWARE\\DEVICEMAP"
aRegistryMachin_118 = "\\Registry\\Machine\\SOFTWARE"
aRegistryMachin_119 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement\\EnterpriseTempControls\\Active"
aRegistryMachin_120 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\Control\\WDI\\Scenarios"
aRegistryMachin_121 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_122 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies\\CAPEs"
aRegistryMachin_123 = "\\Registry\\Machine\\System\\DriverDatabase\\Policies"
aRegistryMachin_124 = "\\REGISTRY\\MACHINE\\OSDATA"
aRegistryMachin_125 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows\\Appx"
aRegistryMachin_126 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\KernelVelocity"
aRegistryMachin_127 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_128 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\CAD"
aRegistryMachin_129 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppModelUnlock"
aRegistryMachin_130 = "\\Registry\\Machine\\Hardware\\Description\\System\\CentralProcessor"
aRegistryMachin_131 = "\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Microsoft\\Compatibility"
aRegistryMachin_132 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\InstalledSDB"
aRegistryMachin_133 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES\\EVENTLOG"
aRegistryMachin_134 = "\\Registry\\Machine\\%wZ\\CurrentControlSet"
aRegistryMachin_135 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\CMF\\SqmData"
aRegistryMachin_136 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Windows"
aRegistryMachin_137 = "\\registry\\machine\\SYSTEM\\CurrentControlSet\\Control\\NUMA"
aRegistryMachin_138 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion"
aRegistryMachin_139 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_140 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FsDepends\\Parameters"
aRegistryMachin_141 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\Hardware Profiles\\%04d"
aRegistryMachin_142 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Device"
aRegistryMachin_143 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceGuard"
aRegistryMachin_144 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\DeviceContainerPropertyUpdateEvents"
aRegistryMachin_145 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Syspart"
aRegistryMachin_146 = "\\Registry\\Machine\\%ws"
aRegistryMachin_147 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\HARDWARE PROFILES\\CURRENT"
aRegistryMachin_148 = "\\REGISTRY\\MACHINE\\SOFTWARE\\WowAA32Node"
aRegistryMachin_149 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\DeviceInstall"
aRegistryMachin_150 = "\\Registry\\Machine\\System\\ControlSet%03d"
aRegistryMachin_151 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Quota System"
aRegistryMachin_152 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\LeapSecondInformation"
aRegistryMachin_153 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options"
aRegistryMachin_154 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\IPT"
aRegistryMachin_155 = "\\REGISTRY\\MACHINE\\SOFTWARE\\Wow6432Node"
aRegistryMachin_156 = "\\registry\\machine\\system\\currentcontrolset\\control\\hivelist"
aRegistryMachin_157 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\PXE"
aRegistryMachin_158 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\OneCore"
aRegistryMachin_159 = "\\REGISTRY\\MACHINE\\"
aRegistryMachin_160 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility\\Driver"
aRegistryMachin_161 = "\\Registry\\Machine\\Hardware\\Description\\System"
aRegistryMachin_162 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\SQMClient\\Windows"
aRegistryMachin_163 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\LicenseInfoSuites"
aRegistryMachin_164 = "\\REGISTRY\\MACHINE\\%s"
aRegistryMachin_165 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement"
aRegistryMachin_166 = "\\Registry\\Machine"
aRegistryMachin_167 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI\\Security"
aRegistryMachin_168 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SESSION MANAGER\\Configuration Manager"
aRegistryMachin_169 = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\WindowsUpdate"
aRegistryMachin_170 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Diagnostics\\Performance"
aRegistryMachin_171 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\SecureBoot"
aRegistryMachin_172 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AutoAttachVirtualDisks"
aRegistryMachin_173 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\UILanguages"
aRegistryMachin_174 = "\\Registry\\Machine\\Hardware\\DeviceMap"
aRegistryMachin_175 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StateSeparation\\RedirectionMap\\Files"
aRegistryMachin_176 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\FeatureManagement\\EnterpriseTempControls"
aRegistryMachin_177 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystemVolumes\\{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}"
aRegistryMachin_178 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\HARDWARE PROFILES\\CURRENT"
aRegistryMachin_179 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Nls\\Normalization"
aRegistryMachin_180 = "\\REGISTRY\\MACHINE\\SYSTEM"
aRegistryMachin_181 = "\\Registry\\Machine\\Security\\SAM"
aRegistryMachin_182 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\NLS\\Language"
aRegistryMachin_183 = "\\REGISTRY\\MACHINE\\HARDWARE\\OWNERMAP"
aRegistryMachin_184 = "\\Registry\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_185 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood.Tmp"
aRegistryMachin_186 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\Session Manager\\Quota System"
aRegistryMachin_187 = "\\Registry\\Machine\\ELAM"
aRegistryMachin_188 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa"
aRegistryMachin_189 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_190 = "\\Registry\\Machine\\System\\CurrentControlSet\\ServiceState"
aRegistryMachin_191 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\SAFEBOOT"
aRegistryMachin_192 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters"
aRegistryMachin_193 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\WMI\\Restrictions"
aRegistryMachin_194 = "\\Registry\\Machine\\"
aRegistryMachin_195 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\MUI\\Settings"
aRegistryMachin_196 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\SERVICES"
aRegistryMachin_197 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\BitlockerStatus"
aRegistryMachin_198 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IDConfigDB"
aRegistryMachin_199 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION\\PERFLIB"
aRegistryMachin_200 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT"
aRegistryMachin_201 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Compatibility"
aRegistryMachin_202 = "\\REGISTRY\\MACHINE\\SYSTEM"
aRegistryMachin_203 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\DeviceOverrides"
aRegistryMachin_204 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\ForceDumpsDisabled"
aRegistryMachin_205 = "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\ACPI\\Parameters"
aRegistryMachin_206 = "\\REGISTRY\\MACHINE\\HARDWARE"
aRegistryMachin_207 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\ENUM"
aRegistryMachin_208 = "\\REGISTRY\\MACHINE\\SOFTWARE"
aRegistryMachin_209 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\WMI"
aRegistryMachin_210 = "\\REGISTRY\\MACHINE\\SYSTEM\\Software\\Microsoft"
aRegistryMachin_211 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\International"
aRegistryMachin_212 = "\\Registry\\Machine\\System\\Setup"
aRegistryMachin_213 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ValidationRunlevels"
aRegistryMachin_214 = "\\REGISTRY\\MACHINE\\"
aRegistryMachin_215 = "\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_216 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters"
aRegistryMachin_217 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_218 = "\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\Kernel DMA Protection"
aRegistryMachin_219 = "\\Registry\\Machine\\System\\LastKnownGoodRecovery\\LastGood"
aRegistryMachin_220 = "\\Registry\\Machine"
aRegistryMachin_221 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem"
aRegistryMachin_222 = "\\Registry\\Machine\\OSDATA\\System\\CurrentControlSet\\Control\\CrashControl"
aRegistryMachin_223 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control"
aRegistryMachin_224 = "\\REGISTRY\\MACHINE\\SYSTEM\\CURRENTCONTROLSET\\CONTROL\\CLASS"
aRegistryMachin_225 = "\\REGISTRY\\MACHINE\\SOFTWARE\\MICROSOFT\\WINDOWS NT\\CURRENTVERSION"
aRegistryMachin_226 = "\\Registry\\Machine\\System\\DriverDatabase\\Updates"
aRegistryMachin_227 = "\\Registry\\Machine\\%wZ\\CurrentControlSet\\%wZ"
aRegistryMachin_228 = "\\Registry\\Machine\\OSDATA\\System\\CurrentControlSet\\Control\\LiveDump"
aRegistryMachin_229 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Power"
aRegistryMachin_230 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\"
aRegistryMachin_231 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ServiceGroupOrder"
aRegistryMachin_232 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters"
aRegistryMachin_233 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa\\CentralizedAccessPolicies"
aRegistryMachin_234 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Notifications"
aRegistryMachin_235 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\kernel"
aRegistryMachin_236 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\7503491f-4a39-4f84-b231-8aca3e203b94"
aRegistryMachin_237 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MUI\\Settings\\LanguageConfiguration"
aRegistryMachin_238 = "\\REGISTRY\\MACHINE\\OSDATA\\Notifications"
aRegistryMachin_239 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Windows"
aRegistryMachin_240 = "\\Registry\\Machine\\System\\Select"
```

# Game Mode

Game Mode is a RM (Resource Manager) feature for a foreground process that Windows identifies as a game through `expandedResources` (or GCS data). Note that everything below is based on pseudocode (from 23H2, things might've changed in newer builds, see [diff](https://noverse.dev/diff?kind=pseudocode)) and interpretations, this isn't official documentation just a personal attempt to document how Game Mode works, mistakes may exist and feel free to correct me. I don't claim that anything below is correct nor complete, that's just how I understood the sequence of Game Mode initialization + (un)registration. I've tried to link all functions that I used, for anyone who wants to take a look for themselves.

It can apply CPU set policy, GPU scheduler/budget policy, optional process priority, optional Game Mode power profile notification, global Game Mode active state, optional expanded resource extension notification. The global state is updated through `WNF_RM_GAME_MODE_ACTIVE` (`RM` prefix in `WNF_RM_GAME_MODE_ACTIVE` = '*Game Mode Resource Manager*').

This means that we can check the game mode state via `WNF_RM_GAME_MODE_ACTIVE`. `PsmServiceExtHost.dll` writes this state from [`RmpSystemPublishGlobalGameModeState`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemPublishGlobalGameModeState@@YAXK@Z.c). The public [`HasExpandedResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/gamemode/HasExpandedResources.c) API reads the same state and returns true only when the value equals the current PID.

Note that you don't have to restart your PC/game when going from disabled to enabled (since it registers the PID when game gets in FG), but you need to restart the game when going from enabled to disabled (since the PID stays registered, which is why restarting the game is enough as that causes the PID to change).

```c
// RmpSystemPublishGlobalGameModeState
v3 = a1; // active Game Mode PID or 0 when no process is active (GameModeActivePid=0 in gm_effects)
if ( (int)RtlPublishWnfStateData(WNF_RM_GAME_MODE_ACTIVE, 0LL, &v3, 4LL, 0LL) < 0
```

```c
// HasExpandedResources
if ( (int)NtQueryWnfStateData(&WNF_RM_GAME_MODE_ACTIVE, 0LL, 0LL, &v6, &v4, &v5) >= 0 )
{
  LOBYTE(v1) = GetCurrentProcessId() == v4; // true only for the active Game Mode PID
  *hasExpandedResources = v1;
}
```

## gm_effects

I've created [`gm_effects.exe`](https://github.com/nohuto/win-config/blob/main/system/assets/gm_effects.exe), which reads the current foreground PID, active Game Mode PID, process default CPU sets (and CPU set IDs), and the Game Mode power profile WNF low value. You can either use the prebuild binary, or build it yourself from [source](https://github.com/nohuto/win-config/blob/main/system/assets/gm_effects):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\gm_effects.exe
```

If you want it to loop faster/slower, change `Sleep(1000)`, it also support a `--pid` argument which lets you track a single PID instead of the current foreground process.

Microsoft also documents behavior that I didn't find in the RM functions, so I guess it's handled somewhere else, such as "Game Mode can suppress Windows Update driver installs and Windows Update restart notifications while a game is running".

## Registry Values

The `AllowAutoGameMode` value gets read by [`EvaluateAppForGameMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateAppForGameMode@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUBroadcastDVRActive.c), but isn't present in the default LGPE policy list ([policies.json](https://raw.githubusercontent.com/nohuto/admx-parser/refs/heads/main/assets/policies.json)). Other registry values are used in [`GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c) and [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c).

```c
"HKCU\\Software\\Microsoft\\GameBar";
    "AutoGameModeEnabled" = 1; // missing/nonzero allows registration
    "GpuGameMemoryBudgetPercentage" = 50; // fallback game GPU memory budget percent
    "GpuDwmMemoryBudgetPercentage" = 30; // fallback system compositor GPU memory budget percent
    "GpuYieldPercentage" = 2; // fallback GPU yield percent, range 2-10
    "DisallowSystemAllowedCpuSets" // nonzero disallows system allowed CPU set policy

"HKLM\\Software\\Policies\\Microsoft\\Windows\\GameDVR";
    "AllowAutoGameMode" = 1; // missing/nonzero allows registration, adding this with a value of 0 would hide the Game Mode part in system settings
```

## Game Mode Process

Obviously, this doesn't include every single part, rather I've tried to keep it simple and focus on the main parts.

### Shell Entry

It starts in `twinui.pcshell.dll`, [`BroadcastDVRComponent::EvaluateAppForGameMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateAppForGameMode@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUBroadcastDVRActive.c) is called if application change, application view change, Game Mode enable change tasks happen.

The application change task calls `EvaluateAppForGameMode` after it has updated the active app information for the changed application view:

```c
// BroadcastDVRComponent::ApplicationChangedTask
BroadcastDVRComponent::EvaluateAppForGameMode((BroadcastDVRComponent *)a1, v7, v13); // v7 = application view, v13 = active app info
```

The application view change task uses the same function when the changed view is already known to the BroadcastDVR component:

```c
// BroadcastDVRComponent::OnApplicationViewChangedGameMode
BroadcastDVRComponent::EvaluateAppForGameMode((BroadcastDVRComponent *)a1, a2, (HWND *)v8); // a2 = application view, v8 = active app info
```

When the user enables Game Mode for the active window, [`OnGameModeEnableChangeTask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-OnGameModeEnableChangeTask@BroadcastDVRComponent@@AEAAXPEAUHWND__@@_N@Z.c) refreshes the GCS (game config store) state and then calls the same Game Mode check:

```c
// BroadcastDVRComponent::OnGameModeEnableChangeTask
BroadcastDVRComponent::EvaluateAppForGameMode(this, v6, (HWND *)v7); // v6 = application view, v7 = active app info
```

### Get Values

`EvaluateAppForGameMode` first gets the two values, a missing value passes, `0` blocks registration. Means if you set one of these values to `0`, all steps below won't run.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode

v29 = 0;
if ( (SHRegGetDWORD(
        HKEY_LOCAL_MACHINE,
        L"Software\\Policies\\Microsoft\\Windows\\GameDVR",
        L"AllowAutoGameMode",
        &v29) < 0
    || v29)
&& (SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"AutoGameModeEnabled", &v29) < 0 || v29) )
```

Note that this is a AND logic (`&&`) so both must either be `1` or not present.

### Check expandedResources

`EvaluateAppForGameMode` first checks whether the active view has the `expandedResources` capability through [`BroadcastDVRComponent::IsExpandedResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsExpandedResources@BroadcastDVRComponent@@AEAAJPEAUIApplicationView@@PEA_N@Z.c) (this is separate from the public [`HasExpandedResources`](https://learn.microsoft.com/en-us/windows/win32/api/expandedresources/nf-expandedresources-hasexpandedresources) API in `gamemode.dll`).

If `expandedResources` is present, it continues with Game Mode reason `5`. If it's not present it calls [`IsGameModeGame`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsGameModeGame@BroadcastDVRComponent@@AEAA_NPEAUGameConfigInfo@@PEAW4GameModeReason@@@Z.c), which uses GCS data filled by [`EvaluateIfViewIsGame`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateIfViewIsGame@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUGameConfigInfo@@PEA_.c). If `IsGameModeGame` returns false, the function exits before process registration, so all steps below won't run again.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
IsExpandedResources = BroadcastDVRComponent::IsExpandedResources(v6, a2, &v27); // v27 = has expandedResources
v12 = v27 ? 5 : 0; // reason 5
if ( !v27 ) // fallback to GCS
{
  if ( !BroadcastDVRComponent::IsGameModeGame(v11, v7, (enum GameModeReason *)&v30) )
    return; // not a Game Mode game
  v12 = (unsigned int)v30; // Game Mode reason returned by IsGameModeGame
}
```

### Resolve the Process

It converts the active HWND (window handle) to a PID with [`GetWindowThreadProcessId`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowthreadprocessid). If the same PID is already registered, it doesn't register the primary process again.

For a new PID, it opens the process with [`PROCESS_QUERY_LIMITED_INFORMATION`](https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights) ("*Required to retrieve certain information about a process (see [GetExitCodeProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess), [GetPriorityClass](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getpriorityclass), [IsProcessInJob](https://learn.microsoft.com/en-us/windows/win32/api/jobapi/nf-jobapi-isprocessinjob), [QueryFullProcessImageName](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-queryfullprocessimagenamea))*"). If the active view is a WinRT (Windows Runtime) application, it reads the process image name and skips `applicationframehost.exe` since that's the UWP frame host.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
if ( v8 )
  v9 = v8; // v9 = HWND
GetWindowThreadProcessId(v9, &v28); // v28 = active process ID
if ( v28 )
{
  if ( v28 == *((_DWORD *)this + 114) ) // already registered primary PID
  {
    BroadcastDVRComponent::GetNonServiceProcessListAndIds(this, &v33);
    BroadcastDVRComponent::ApplyGameRelatedForGameModeProcess((__int64)this, v28, &v33);
    BroadcastDVRComponent::TelemetryLogProcessesLaunchedAfterGame(v15, &v35);
    return;
  }
}
```

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
hProcess = 0LL;
v18 = OpenProcess(0x1000u, 0, v28); // 0x1000 = PROCESS_QUERY_LIMITED_INFORMATION, v28 = PID
wil::details::unique_storage<wil::details::handle_null_resource_policy<int (*)(void *),&int CloseHandle(void *)>>::reset(&hProcess, v18);
v20 = (char *)hProcess; // process handle used below
```

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
if ( a2 )
{
  if ( (int)Microsoft::WRL::ComPtr<IApplicationView>::As<IWinRTApplicationView>(&v30, (__int64)&v31) >= 0 )
  {
    if ( K32GetModuleFileNameExW(v20, 0LL, Filename, 0x104u) )
    {
      FileNameW = PathFindFileNameW(Filename);
      if ( CompareStringOrdinal(FileNameW, -1, L"applicationframehost.exe", -1, 1) == 2 )
        goto LABEL_28; // skip the UWP frame host process
    }
  }
}
```

### Build the Request

It initializes a RM request, asks the service for the current request limits, then adds GCS and registry values in [`GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c).

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
v35 = 0LL;
v36 = 0LL;
v37 = 0LL;
RmGameModeInitializeResourceRequest(&v35); // v35 = resource request buffer
LargestValidResourceRequest = RmGameModeGetLargestValidResourceRequest(&v35);
if ( LargestValidResourceRequest < 0 )
{
  wil::details::in1diag3::_Log_Hr(
    retaddr,
    (void *)0x825,
    (int)"pcshell\\twinui\\broadcastdvrcomponent\\lib\\broadcastdvrprovider.cpp",
    (const char *)(LargestValidResourceRequest | 0x10000000u));
  goto LABEL_28;
}
BroadcastDVRComponent::GetGameModeRequest(this, v12, v7, &v35);
v23 = RmGameModeRegisterProcess(v20, &v35, 0LL);
```

In `rmclient.dll`, [`RmGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/rmclient/RmGameModeRegisterProcess.c) sends the process handle and Game Mode request to the RM service through RPC.

```c
// RmGameModeRegisterProcess
if ( (int)sub_180005FC0(&unk_180022A10, Binding) >= 0 )
{
  v6 = 1;
  v10 = a3;
  v8.Pointer = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&stru_180020F80, 0, 0LL, Binding[0], a1, a2, v10).Pointer;
  Pointer = (unsigned int)v8.Pointer;
  Binding[1] = v8.Pointer;
  if ( SLODWORD(v8.Simple) >= 0 )
    Pointer = 0;
}
```

### Set Defaults

[`RmGameModeInitializeResourceRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/rmclient/RmGameModeInitializeResourceRequest.c) writes the default values into the request.

```c
// RmGameModeInitializeResourceRequest
__int64 __fastcall RmGameModeInitializeResourceRequest(__int64 a1)
{
  __int64 result; // rax

  result = 0LL;
  *(_OWORD *)a1 = 0LL;
  *(_OWORD *)(a1 + 16) = 0LL;
  *(_QWORD *)(a1 + 32) = 0LL;
  *(_DWORD *)a1 = 6; // request version
  *(_DWORD *)(a1 + 16) = 10; // GPU yield percentage
  *(_DWORD *)(a1 + 20) = 50; // game GPU memory budget
  *(_DWORD *)(a1 + 24) = 30; // system compositor GPU memory budget
  return result;
}
```

### Validate in the Service

[`RmSrvGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmSrvGameModeRegisterProcess@@YAJPEAU_RM_SERVICE_GLOBALS@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c) receives the registration request inside the service, it validates the request in [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c), then calls [`RmpGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRegisterProcess@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c).

- Request version must be `6`
- GPU yield must be `2-10`
- Game and system compositor memory percentages must total `<= 100`
- Priority class may be unset or one of `2`, `3`, `6`

```c
// RmSrvGameModeRegisterProcess
if ( a4 )
{
  v8 = -1073741583;
}
else if ( RmpGameModeIsResourceRequestValid(v4, a3) ) // a3 = Game Mode request
{
  v8 = RmpGameModeRegisterProcess((struct _RM_SERVICE_GLOBALS *)((char *)v4 + 2096), a2, a3); // a2 = process handle
  if ( v8 >= 0 )
    v8 = 0;
}
else
{
  v8 = -1073741584; // invalid request
}
```

The validator has two parts, the first part accepts a default request only when the CPU allocation fields are empty and the graphics values still match the base defaults, the second part checks the normal limits for CPU count, CPU set mask, priority class, GPU yield, and GPU memory budgets.

```c
// RmpGameModeIsResourceRequestValid
if ( *(_DWORD *)a2 == 6 ) // request version
{
  v6 = *((_DWORD *)a2 + 8) & 5; // selects which request form is being validated
  if ( v6 != 4
    && (v6 != 1
     || !*((_DWORD *)a2 + 1) // cannot carry an CPU count
     && !*((_QWORD *)a2 + 1) // cannot carry an CPU set mask
     && *((_DWORD *)a2 + 4) == 10 // GPU yield must stay at default
     && *((_DWORD *)a2 + 5) == 50 // game GPU memory budget must stay at default
     && *((_DWORD *)a2 + 6) == 30 // system compositor GPU memory budget must stay at default
     && (*((_BYTE *)a2 + 32) & 8) == 0) ) // graphics priority cant be set
  {
    v7 = RtlNumberOfSetBitsUlongPtr(*((_QWORD *)a2 + 1), a2, a3, a4); // number of CPUs in the CPU set mask
    v8 = *((_DWORD *)a2 + 1); // requested exclusive CPU count
    if ( v8 >= v7
      && v8 <= 0x40
      && RmpCpuSetManagerIsGameModeRequestSatisfiable(
           (struct _RM_SERVICE_GLOBALS *)((char *)a1 + 680),
           (*((_DWORD *)a2 + 7) & 0x40) != 0, // CPU count increase
           v8,
           *((_QWORD *)a2 + 1)) // CPU set mask
      && (!*((_BYTE *)a2 + 36) || *((_BYTE *)a2 + 36) == 2 || *((_BYTE *)a2 + 36) == 3 || *((_BYTE *)a2 + 36) == 6) // priority class
      && (unsigned int)(*((_DWORD *)a2 + 4) - 2) <= 8 // GPU yield range = 2-10
      && (unsigned int)(*((_DWORD *)a2 + 5) + *((_DWORD *)a2 + 6)) <= 0x64 // GPU memory budgets = total 100 or less
      && (*((_BYTE *)a2 + 28) & 0x18) != 0x18 )
    {
      return 1;
    }
  }
}
```

### Create Process State

After validation [`RmpGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRegisterProcess@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c) turns the request into a service managed process state. The request is copied by [`RmpGameModeInitializeRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeInitializeRecipientProcess@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RESOURCE.c), then [`RmpGameModeFindProcessOrCompleteInsertion`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeFindProcessOrCompleteInsertion@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_.c) checks whether that PID is already known to the service.

If it's a new PID, [`RmpGameModeAllocateObjectsForRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAllocateObjectsForRecipientProcess@@YAJPEAU_RM_GAME_MODE_RECIPIENT_PROCESS@@PEAX@Z.c) prepares the service state for it, it creates the process exit wait object, opens its own process handle and stores the PID. [`RmpGameModeInsertRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeInsertRecipientProcess@@YAXPEAU_RM_GAME_MODE_RECIPIENT_PROCESS@@@Z.c) then adds that process state to the Game Mode context, starts the exit wait, and queues the policy worker.

### Apply Resource Policies

[`RmpGameModePolicyWorker`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModePolicyWorker@@YAXPEAU_TP_CALLBACK_INSTANCE@@PEAXPEAU_TP_WORK@@@Z.c) applies Game Mode policy. For newly registered processes it can acquire global resources (`RmpGameModeAcquireGlobalResources`), apply per process policies (`RmpGameModeApplyNewRecipientPolicies`), apply global policies (`RmpGameModeApplyGlobalPolicies`), release unused global resources (`RmpGameModeReleaseUnusedGlobalResources`).

```c
// RmpGameModePolicyWorker
if ( v14 )
  RmpGameModeNotifyExtensionRecipientsPresent((struct _RM_GAME_MODE_CONTEXT *)a2, v14 != 0);
if ( v47.Flink != &v47 ) // v47 = list of processes that need policy work
{
  RmpGameModeAcquireGlobalResources((struct _RM_GAME_MODE_CONTEXT *)a2, &v47);
  RmpGameModeApplyNewRecipientPolicies((struct _RM_GAME_MODE_CONTEXT *)a2, &v47);
  RmpGameModeApplyGlobalPolicies((struct _RM_GAME_MODE_CONTEXT *)a2);
  RmpGameModeReleaseUnusedGlobalResources((struct _RM_GAME_MODE_CONTEXT *)a2);
}
```

```c
// RmpGameModeApplyNewRecipientPolicies
while ( a2->Flink != a2 ) // a2 = list of processes waiting for policy application
{
  v4 = CempListRemoveHeadAndClear(a2); // remove one process from the work list
  RmpGameModeAcquireAndApplyRecipientResources(a1, (struct _RM_GAME_MODE_RECIPIENT_PROCESS *)(v4 - 11)); // run the policy table for that process
  *((_BYTE *)v4 + 83) &= ~1u;
  v5 = (char *)a1 + 16 * *((int *)v4 + 4) + 88;
```

[`RmpGameModeAcquireAndApplyRecipientResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAcquireAndApplyRecipientResources@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_R.c) uses five resource policy entries and calls the apply function for each active entry. 

More detail about them in [CPU set policy](https://noverse.dev/docs/win-config/system/game-mode/#cpu-sets), [GPU policy](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget), [power profile state](https://noverse.dev/docs/win-config/system/game-mode/#game-mode-power-profile-wnf-state), [process priority](https://noverse.dev/docs/win-config/system/game-mode/#process-priority-class), [extension state](https://noverse.dev/docs/win-config/system/game-mode/#expanded-resource-extension-notification).

```c
// RmpGameModeAcquireAndApplyRecipientResources
v2 = 0;
v3 = off_1800B40C0; // Game Mode resource policies
for ( i = 0; i < 5; ++i )
{
  v7 = 1 << i; // one bit per policy entry
  if ( *((_BYTE *)v3 + 33) )
    goto LABEL_11;
  if ( !*v3 )
    goto LABEL_10;
  if ( *((_BYTE *)v3 + 32) )
  {
    if ( (v7 & *((_DWORD *)a1 + 32)) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  v8 = (*v3)(a1, a2); // apply one policy entry to process
  if ( v8 >= 0 && v8 != 255 )
  {
    *((_DWORD *)a2 + 40) |= v7; // remember that policy was applied
LABEL_10:
    v2 |= v7; // remember that policy was handled in this pass
  }
LABEL_11:
  v3 += 5;
}
```

### Register Related Processes

After primary registration, `twinui.pcshell.dll` stores the registered PID, gets the current non service process list and calls [`ApplyGameRelatedForGameModeProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForGameModeProcess@BroadcastDVRComponent@@AEAAXKAEBV-$vector@U-$pair@KVString@I.c). It asks the game manager for related process names, compares process image names, and calls [`ApplyGameRelatedForRelatedProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForRelatedProcess@BroadcastDVRComponent@@AEAAXKGK@Z.c) for matches.

See more detail in [Related Processes](https://noverse.dev/docs/win-config/system/game-mode/#related-processes).

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
*((_DWORD *)this + 114) = v28; // remember primary PID
v33 = 0LL;
v34 = 0LL;
BroadcastDVRComponent::GetNonServiceProcessListAndIds(this, &v33);
BroadcastDVRComponent::ApplyGameRelatedForGameModeProcess((__int64)this, v28, &v33); // register matching related processes
std::vector<Windows::Internal::String>::clear((char *)this + 352);
BroadcastDVRComponent::GetSortedUniqueProcessList(v25, &v33, (char *)this + 352);
BroadcastDVRComponent::TelemetryLogProcessesLaunchedWithGame(v26, (char *)this + 352);
```

### Pair Auxiliary Processes

Related processes are paired with the primary process through `RmGameModeRegisterPairedAuxiliaryProcess`, they're matched by process image name against the related process list returned by the GCS/game manager.

### End by Toggle Disable

When Game Mode is disabled for the active HWND/PID, [`OnGameModeEnableChangeTask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-OnGameModeEnableChangeTask@BroadcastDVRComponent@@AEAAXPEAUHWND__@@_N@Z.c) calls `RmGameModeDisableForRegisteredProcess`, then `RmGameModeUnregisterProcess`.

```c
// BroadcastDVRComponent::OnGameModeEnableChangeTask
v14 = RmGameModeDisableForRegisteredProcess(pv); // disable Game Mode policy
if ( v14 < 0 )
  goto LABEL_26;
v14 = RmGameModeUnregisterProcess(v13); // remove process
```

### End by Process Exit or Focus Change

The service also watches process lifetime with a threadpool wait. When the process terminates, paired auxiliary processes are cleared and the process is removed from Game Mode service state ([`RmpGameModeRecipientProcessTerminationCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRecipientProcessTerminationCallback@@YAXPEAU_TP_CALLBACK_INSTANCE@@PEAXPEAU_TP_WAIT@.c)). Input focus changes queue the same policy worker so the active Game Mode state can move to another registered primary process ([`RmpSystemNotificationInputFocusChangeCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemNotificationInputFocusChangeCallback@@YAJU_WNF_STATE_NAME@@KPEAU_WNF_TYPE_ID@@PEAXPEBX.c)).

This can be validated using [`gm_effects`](https://noverse.dev/docs/win-config/system/game-mode#gm_effects) with the `--pid` argument, so you enable Game Mode, start the game, use `--pid` with the PID of the game, move the game to FG/BG. By doing so you'll see that the state changes.

```ini
; not in FG
Timestamp=20:47:10.665
FGPid=3996
GameModeActivePid=0
PowerProfileLowValue=1
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

; in FG
Timestamp=20:47:11.668
FGPid=9968
GameModeActivePid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
PowerProfileLowValue=3
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

Timestamp=20:47:12.670
FGPid=9968
GameModeActivePid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
PowerProfileLowValue=3
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

; not in FG
Timestamp=20:47:13.685
FGPid=3372
GameModeActivePid=0
PowerProfileLowValue=1
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
```

## Effect Details

### Process Priority Class

Game Mode can temporarily change a registered process priority class if the request priority byte is nonzero (`2`/`6`/`3`, see below).

The request byte is the native `ProcessPriorityClass` value used by `NtSetInformationProcess`.

> "*Each thread has a base priority that is a function of its process priority class and its relative thread priority.*"
>
> "*Scheduling decisions are made based on the current priority.*"
>
> — Microsoft, [Windows Internals E7, P1: Chapter 4, Threads](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

That means a process priority class isn't the final scheduling value by itself. It sets the base priority that the process threads start from, the scheduler then uses each thread's current priority, which can include wait completion boosts, GUI boosts, MMCSS boosts, etc.

| Request byte | Public class | Thread base |
| --- | --- | --- |
| `0` | - | - |
| `2` | `NORMAL_PRIORITY_CLASS` | `8` |
| `6` | `ABOVE_NORMAL_PRIORITY_CLASS` | `10` |
| `3` | `HIGH_PRIORITY_CLASS` | `13` |

The accepted classes stay in the dynamic priority range, they obviously don't enter the real time range.

For the primary game process, [`BroadcastDVRComponent::GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c) sets priority byte `2`. That means the primary game process is set to normal process priority class by Game Mode unless another component changes it later.

Example with a game that sets itself to real time (there're probably any game devs who do that without thinking about the impact) priority before Game Mode registers it:

1. The game starts as `REALTIME_PRIORITY_CLASS`
2. Game Mode registers the primary game process
3. The service saves the old priority class
4. The service writes `NORMAL_PRIORITY_CLASS`
5. When Game Mode is removed, the service can restore the saved old class

```c
// BroadcastDVRComponent::GetGameModeRequest
*(_BYTE *)(a4 + 36) = 2; // primary game request priority class
```

#### FG Boost with Game Mode

See '[PsPrioritySeparation (`1:0`)](https://noverse.dev/docs/win-config/system/priority-separation/#pspriorityseparation-10)' for more details on the FG process priority boosting.

You can test it by following the '[Watching the FG Priority Boost](https://noverse.dev/docs/win-config/system/priority-separation/#watching-the-fg-priority-boost)' guide while using the main game thread instead of the first CPUSTRES thread, get the instance name of a TID via e,g,:

```powershell
$TID = # add TID
Get-CimInstance Win32_PerfRawData_PerfProc_Thread | Where-Object { $_.IDThread -eq $TID } | Select-Object Name #, IDProcess, IDThread
```

> "*Whenever a thread in the foreground process completes a wait operation on a kernel object, the kernel boosts its current (not base) priority by the current value of PsPrioritySeparation.*"
>
> "*The windowing system is responsible for determining which process is considered to be in the foreground.*"
>
> — Microsoft, [Windows Internals E7, P1: Chapter 4, Threads](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

##### 23H2 (Game)

I've done it using Overwatch, both times I switched the state between FG/BG:

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-game.png?raw=true)

##### 23H2 (Other app)

Means that the missing FG boost only happens for processes that register with the game mode.

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-app-off.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-app-on.png?raw=true)

##### 25H2

The issue doesn't seem to appear anymore on 25H2:

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-25H2.png?raw=true)

#### Related Processes

[`ApplyGameRelatedForGameModeProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForGameModeProcess@BroadcastDVRComponent@@AEAAXKAEBV-$vector@U-$pair@KVString@I.c) compares running process image names against the related process list returned by the GCS/game manager. For matches, [`ApplyGameRelatedForRelatedProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForRelatedProcess@BroadcastDVRComponent@@AEAAXKGK@Z.c) builds the related process request. 

Related processes can get the normal, above normal, or high process priority class.

```c
// BroadcastDVRComponent::ApplyGameRelatedForRelatedProcess
if ( (a3 & 4) != 0 )
{
  BYTE4(v20) = 6; // above normal priority
}
else
{
  v14 = 2; // default normal priority
  if ( (a3 & 8) != 0 )
    v14 = 3; // high priority
  BYTE4(v20) = v14;
}
```

### CPU Sets

Game Mode can request CPU set allocation and apply CPU set restrictions and defaults to the registered process. A CPU set ID usually means one logical processor, and a process or thread can be assigned a list of CPU set IDs. Game Mode uses this to give the game a preferred or limited processor selection while moving selected system activity away from those CPU sets.

> "*Game mode tries to kind of steer away the processors from your game so the system itself and all the kernel threads and stuff like that are not going to use some processors, so your game can use those processors exclusively.*"
>
> — Pavel Yosifovich, [Windows Internals](https://youtu.be/h6BXMcRqYhA?t=3251)

> "*You've seen how affinity (sometimes referred to as hard affinity) can limit threads to certain processors, which is always honored by the scheduler. The ideal processor mechanism tries to run threads on their ideal processors (sometimes referred to as soft affinity), generally expecting to have the thread's state be part of the processor's cache. The ideal processor may or may not be used, and it does not prevent the thread from being scheduled on other processors. Both these mechanisms don't work on system-related activity, such as system threads activity. Also, there is no easy way to set hard affinity to all processes on a system in one stroke. Even walking the process would not work. System processes are generally protected from external affinity changes because they require the PROCESS_SET_INFORMATION access right, which is not granted for protected processes.*
> *Windows 10 and Server 2016 introduce a mechanism called CPU sets. These are a form of affinity that you can set for use by the system as a whole (including system threads activity), processes, and even individual threads. For example, a low-latency audio application may want to use a processor exclusively while the rest of the system is diverted to use other processors. CPU sets provide a way to achieve that.*
> *The documented user mode API is somewhat limited at the time of this writing. [GetSystemCpuSetInformation](https://learn.microsoft.com/en-us/windows/win32/procthread/getsystemcpusetinformation) returns an array of [SYSTEM_CPU_SET_INFORMATION](https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-system_cpu_set_information) that contains data for each CPU set. In the current implementation, a CPU set is equivalent to a single CPU. This means the returned array's length is the number of logical processors on the system. Each CPU set is identified by its ID, which is arbitrarily selected to be 256 (0x100) plus the CPU index (0, 1, ...). These IDs are the ones that must be passed to [SetProcessDefaultCpuSets](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusets) and [SetThreadSelectedCpuSets](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets) functions to set default CPU sets for a process and a CPU set for a specific thread, respectively. An example for setting thread CPU set would be for an "important" thread that should not be interrupted if possible. This thread could have a CPU set that contains one CPU, while setting the default process CPU set to include all other CPUs. One missing function in the Windows API is the ability to reduce the system CPU set. This can be achieved by a call to the [NtSetSystemInformation](https://learn.microsoft.com/en-us/windows/win32/sysinfo/ntsetsysteminformation) system call. For this to succeed, the caller must have SeIncreaseBasePriorityPrivilege.*
>
> — Microsoft, [Windows Internals E7, P1: 'Chapter 4, Multiprocessor systems'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

I've tried to see differences between on/off within Overwatch/CS2, but `GetProcessDefaultCpuSets` returned `DefaultCpuSetCount=0` even while Game Mode was active. Other games I tested were Forza Horizon 5/Cyberpunk 2077 which don't register with Game Mode at all.

During registration ([9 - Apply Resource Policies](https://noverse.dev/docs/win-config/system/game-mode/#9---apply-resource-policies)), [`RmpGameModeAcquireCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAcquireCpuSetAllocation@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_P.c) asks the CPU set manager for a valid allocation, the CPU set manager chooses the actual CPU sets from the request and current system CPU set state, then [`RmpCpuSetManagerApplySystemAllowedMask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpCpuSetManagerApplySystemAllowedMask@@YAJPEAU_RM_CPU_SET_MANAGER@@@Z.c) can reduce the CPU sets available to general system activity. [`RmpGameModeTryApplyCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyCpuSetAllocation@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_.c) then applies that allocation to the registered process.

The final calls are [`RmpSystemSetProcessDefaultCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessDefaultCpuSets@@YAJPEAXPEA_K@Z.c) (preferred selection), [`RmpSystemSetProcessConstrainedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessConstrainedCpuSets@@YAJPEAXE@Z.c) (limit to selected CPU sets), [`RmpSystemSetProcessAllowedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessAllowedCpuSets@@YAJPEAXPEA_K@Z.c) (updated when the allocation changes).

When Game Mode is removed from the process, [`RmpGameModeUnapplyCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeUnapplyCpuSetAllocation@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_P.c) clears default CPU sets etc.

### GPU scheduler & GPU memory budget

Game Mode changes graphics policy through D3DKMT calls, the service applies a scheduler yield percentage with `D3DKMTSetYieldPercentage` and a GPU memory budget target with `D3DKMTSetMemoryBudgetTarget`.

| Part | Description |
| --- | --- |
| GPU yield percentage | Scheduler policy value passed to `D3DKMTSetYieldPercentage`, Game Mode accepts `2-10`. From my understanding a lower yield value means that the game yields less GPU scheduling time in relation to other work and the opposite. |
| Game GPU memory budget percentage | First budget target passed to `D3DKMTSetMemoryBudgetTarget`, the default fallback is `50`. Note that this is a "target" not a reservation of VRAM. |
| System compositor GPU memory budget percentage | Second budget target passed to `D3DKMTSetMemoryBudgetTarget`, the default fallback is `30`. |

The RM initializer starts with `10/50/30`, but the shell request builder normally uses the HKCU fallback values `2/50/30` when no valid per game profile is present (see below). 

The stored GPU profile is created as four bytes, but the Game Mode service only receives the yield byte, the game budget byte, the system compositor budget byte, the fourth byte is calculated by [`GameModeConfigurationServer::_SaveToGameConfigStore`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/Windows-Gaming-Preview/-_SaveToGameConfigStore@GameModeConfigurationServer@GamesEnumeration@Preview@Gaming@Windows@@AEA.c) as `100 - game - system compositor`. [`GameModeConfigurationServer::_LoadPropertyValues`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/Windows-Gaming-Preview/-_LoadPropertyValues@GameModeConfigurationServer@GamesEnumeration@Preview@Gaming@Windows@@AEAAJX.c) shows only the top three bytes again, I'll just call the fourth byte the stored remainder.

```c
// SetGameGpuProfile
if ( a4 + a6 + (unsigned __int8)a5 != 100 ) // game budget + system compositor budget + stored remainder == 100
{
  v6 = -2147024809;
  v7 = 397LL;
LABEL_7:
  wil::details::in1diag3::Return_Hr(
    retaddr,
    (void *)v7,
    (int)"onecoreuap\\xbox\\windows.gaming.preview\\dll\\gameconfigutils.cpp",
    (const char *)v6);
  return v6;
}
if ( a3 > 0x64u ) // yield byte <= 100
{
  v6 = -2147024809;
  v7 = 402LL;
  goto LABEL_7;
}
v9 = (__int128)*a2;
a5 = a6 | (((unsigned __int8)a5 | ((a4 | (a3 << 8)) << 8)) << 8); // yield, game budget, system compositor budget, stored remainder
```

`GetGameModeRequest` then builds the service request from either the per game profile or the HKCU fallback values, if the per game profile is absent or invalid, it uses the fallback values.

```c
// RmGameModeInitializeResourceRequest
*(_DWORD *)(a1 + 16) = 10; // GPU yield
*(_DWORD *)(a1 + 20) = 50; // game GPU memory budget
*(_DWORD *)(a1 + 24) = 30; // system compositor GPU memory budget
```

```c
// BroadcastDVRComponent::GetGameModeRequest
DWORD = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuGameMemoryBudgetPercentage", &v53);
v10 = 50;
if ( DWORD >= 0 )
  v10 = v53;
v46 = v10;
v11 = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuDwmMemoryBudgetPercentage", &v53);
v12 = 30;
if ( v11 >= 0 )
  v12 = v53;
v47 = v12;
v13 = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuYieldPercentage", &v53);
v14 = 2;
if ( v13 >= 0 )
  v14 = v53;
v45 = v14;
```

```c
// BroadcastDVRComponent::GetGameModeRequest
if ( !v15 )
  goto LABEL_44; // no GPU profile, use HKCU fallback values
*v33 = HIBYTE(v15); // GPU yield
if ( HIBYTE(v15) > 0xAu )
  *v34 = 100 - HIBYTE(v15);
v35 = v45;
*(_DWORD *)(a4 + 20) = BYTE2(v15); // GPU memory budget
v36 = BYTE1(v15);
*(_DWORD *)(a4 + 24) = BYTE1(v15); // system compositor budget
LABEL_45:
v37 = *(_DWORD *)(a4 + 20);
if ( !v37 && !v36 )
{
  v38 = 1;
LABEL_81:
  v17 = 0;
  goto LABEL_82;
}
v38 = 0;
if ( v37 < 0x64 && v36 < 0x64 )
  goto LABEL_81;
LABEL_82:
if ( v38 || v17 || v37 + v36 >= 0x64 ) // invalid pair falls back to HKCU values
{
  *(_DWORD *)(a4 + 20) = v46;
  *(_DWORD *)(a4 + 24) = v47;
}
result = *v34 - 2;
if ( (unsigned int)result > 8 )
  *v34 = v35; // invalid yield falls back to HKCU value
```

The service validates the final request in [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c) with ranges listed in [7 - Validate in the Service](https://noverse.dev/docs/win-config/system/game-mode/#7---validate-in-the-service). The actual graphics update is in [`RmpGameModeTryApplyGraphicsPriority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyGraphicsPriority@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_.c), Game Mode saves the original graphics settings during initialization, applies the Game Mode values while active, and restores the saved values when Game Mode is removed.

```c
// RmpGameModeTryApplyGraphicsPriority
v7 = *v3;
v20 = 0;
v21 = 0;
v22 = v7; // accepted GPU yield value
v19 = 16;
v6 = D3DKMTSetYieldPercentage(&v19);
v8 = v3;
if ( v6 < 0 )
  goto LABEL_6;
v9 = *((_DWORD *)a2 + 33);
v20 = 0;
v2 = 1;
v21 = v9; // accepted game budget target
v22 = *((_DWORD *)a2 + 34); // accepted system compositor budget target
v19 = 16;
v6 = D3DKMTSetMemoryBudgetTarget(&v19);
```

### Game Mode Power Profile WNF State

Game Mode can update `WNF_SEB_GAME_MODE` through [`RmpSystemEnableDisableGameModePowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemEnableDisableGameModePowerProfile@@YAJE@Z.c), the apply function is [`RmpGameModeTryApplyPowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyPowerProfile@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_PROC.c), it applies only to the primary process and only when the request builder asks for this policy.

WNF = Windows Notification Facility

> "*The Windows Notification Facility, or WNF, is the core underpinning of a modern registrationless publisher/subscriber mechanism*"
>
> "*The ability to define a state name that can be subscribed to, or published to by arbitrary processes*"
>
> "*The ability to associate such a state name with a payload of up to 4 KB*"
>
> "*The Power Manager and various related components use WNF to signal actions*"
>
> — Microsoft, [Windows Internals E7, P2: Chapter 8, System mechanisms](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

That is why the Game Mode power part uses WNF, it writes `WNF_SEB_GAME_MODE`, and the power/SEB side can get that state and apply the `GameMode` processor power profile.

Microsoft documents `GameMode` as a processor power management profile that OEMs can configure through provisioning packages.

> "*The power profiles are used by the power processor engine to adapt the performance and parking algorithm on various system use cases.*"
> "*GameMode profile is enabled when the 'Game Mode' setting toggle is turned on and the user is playing a game.*"
>
> — Microsoft, [Processor power management options](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#power-profiles)

> "*Power profiles provide system wide configuration of processor power management, impacting all running workloads equally.*"
>
> — Microsoft, [Processor power management options](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#quality-of-service)

```c
// RmpGameModeTryApplyPowerProfile
if ( *((_DWORD *)a2 + 26) || (*((_BYTE *)a2 + 144) & 8) == 0 )
  return 255LL;
v2 = RmpSystemEnableDisableGameModePowerProfile(1u);
if ( v2 < 0 )
  MicrosoftTelemetryAssertTriggeredNoArgs();
```

```c
// RmpSystemEnableDisableGameModePowerProfile
v2 = 0xFFFFFFFF00000001uLL;
if ( a1 )
  LODWORD(v2) = 3;
return NtUpdateWnfStateData(&WNF_SEB_GAME_MODE, &v2, 8LL, 0LL, 0LL, 0, 0);
```

When enabled, WNF uses low value `3`, when disabled, it uses low value `1`. The high value stays `0xFFFFFFFF` in both cases. The GameMode profile has one processor override `Minimum processor state` = `100%` for AC/DC (note that you won't see the changes via powercfg, as these are profile values not a scheme).

You can use [`gm_effects`](https://noverse.dev/docs/win-config/system/game-mode#gm_effects) to see what value is set.

[`BroadcastDVRComponent::IsUsingPowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsUsingPowerProfile@BroadcastDVRComponent@@AEAA_NAEBU_GUID@@@Z.c) checks whether the active power scheme is `GUID_MIN_POWER_SAVINGS` (High Performance), the request builder uses that result as "already using a performance plan". In the default cases, it asks the service for the GameMode power profile only when the current plan isn't High Performance (`GUID_MIN_POWER_SAVINGS` has `PROCTHROTTLEMIN`/`PROCTHROTTLEMIN1` at `100` by default).

```c
// BroadcastDVRComponent::IsUsingPowerProfile
v2 = PowerGetActiveScheme(0LL, &v6) == 0;
if ( v7 )
  hMem = v6;
if ( v2 )
{
  v3 = *(_QWORD *)&hMem->Data1 - *(_QWORD *)&GUID_MIN_POWER_SAVINGS.Data1;
  if ( *(_QWORD *)&hMem->Data1 == *(_QWORD *)&GUID_MIN_POWER_SAVINGS.Data1 )
    v3 = *(_QWORD *)hMem->Data4 - *(_QWORD *)GUID_MIN_POWER_SAVINGS.Data4;
  v4 = v3 == 0;
}
```

### Expanded Resource Extension Notification

When the optional extension is present, RM notifies it when Game Mode has active policy recipients and when the main Game Mode process enters or leaves expanded resource mode. [`PsmInitializeServiceExtension4`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/PsmInitializeServiceExtension4.c) shows why this is optional, the service only initializes the extension when the extension functions are present.

```c
// PsmInitializeServiceExtension4
if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent(v4) ) // extension exists
{
  v10[0] = RmGameModeCpuSetManagerCreateClientContext;
  v10[1] = RmGameModeCpuSetManagerAcquireExplicitCpuSets;
  v10[2] = RmGameModeCpuSetManagerRegisterProcessWithAllocation;
  v10[3] = RmGameModeCpuSetManagerReleaseAllocation;
  v10[4] = RmGameModeCpuSetManagerReleaseProcessRegistration;
  InitializeGameModeExtension(v10, v8); // give extension those callbacks + RM service globals
}
```

[`RmpGameModeNotifyExtensionRecipientsPresent`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeNotifyExtensionRecipientsPresent@@YAXPEAU_RM_GAME_MODE_CONTEXT@@E@Z.c) sends the global "Game Mode recipients exist" state, it only calls the extension when that state changes.

```c
// RmpGameModeNotifyExtensionRecipientsPresent
if ( *((_BYTE *)a1 + 140) != a2 ) // cached state differs from new state
{
  v4 = 0;
  *((_DWORD *)a1 + 20) = 0;
  RtlReleaseSRWLockExclusive((char *)a1 + 72);
  if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent() ) // extension exists
  {
    LOBYTE(v4) = a2 != 0; // convert state to boolean
    NotifyGameModeExtensionRecipientsPresent(v4); // notify whether Game Mode recipients exist
  }
  *((_BYTE *)a1 + 140) = a2; // cache the state after notification
  RtlAcquireSRWLockExclusive((char *)a1 + 72);
  *((_DWORD *)a1 + 20) = GetCurrentThreadId();
}
```

[`RmpGameModeTryApplySystemExtensionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplySystemExtensionPolicy@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIP.c) sends the enabled state for the main Game Mode recipient (related or auxiliary recipients skip this). [`RmpGameModeUnapplySystemExtensionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeUnapplySystemExtensionPolicy@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPI.c) sends the disabled state when the policy is removed.

```c
// RmpGameModeTryApplySystemExtensionPolicy
if ( *((_DWORD *)a2 + 26) )
  return 255LL; // not the main recipient = skipped
RmpSystemNotifyGameModeExtensionStateChange(*((void **)a2 + 5), 1u); // enabled for this process handle
```

```c
// RmpGameModeUnapplySystemExtensionPolicy
RmpSystemNotifyGameModeExtensionStateChange(a2[5], 0); // disabled for this process handle
```

```c
// RmpSystemNotifyGameModeExtensionStateChange
v4 = IsNotifyGameModeExtensionRecipientsPresentPresent();
v5 = 0LL;
if ( v4 )
{
  LOBYTE(v5) = a2 != 0; // enabled/disabled
  NotifySystemExpandedResourceModeStateChange(a1, v5); // process handle + expanded resource mode state
}
```

The same optional extension can also change how the system allowed CPU set mask is applied, [`RmpSystemSetSystemAllowedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetSystemAllowedCpuSets@@YAJPEA_K@Z.c) uses the extension when it's present, otherwise it writes the mask directly through `NtSetSystemInformation`.

```c
// RmpSystemSetSystemAllowedCpuSets
if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent(SystemInformation) )
  return DelegateSetSystemAllowedCpuSets(SystemInformation, v2); // extension handles system allowed CPU set
else
  return NtSetSystemInformation(SystemPlugPlayBusInformation|0x80, SystemInformation, v2);
```

## Summary (& Opinion)

- WU driver updates/automatic restarts/restart notifications shouldn't be enabled, so that behavior doesn't matter.
- [Process priority class](https://noverse.dev/docs/win-config/system/game-mode/#process-priority-class) can prevent a game from setting itself to `REALTIME_PRIORITY_CLASS` as Game Mode would overwrite that with `NORMAL_PRIORITY_CLASS`. If a game doesn't have such issues, the priority classes Game Mode uses are usually similar to what normal games already use.
- Game Mode prevents the FG boost from happening (tested on 23H2), if you don't use `PsPrioritySeparation` FG boost (`1`/`2`), then this doesn't matter (follow '[Watching the FG Priority Boost](https://noverse.dev/docs/win-config/system/priority-separation/#watching-the-fg-priority-boost)' but with the game, as said in the section).
- I haven't seen any game yet where Game Mode applied [CPU Sets](https://noverse.dev/docs/win-config/system/game-mode/#cpu-sets) through `GetProcessDefaultCpuSets`, if Game Mode chose proper CPU set IDs, this could be useful, but I wouldn't trust Microsoft with that.
- [GPU policy](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget) should only be noticeable if the system has GPU scheduling (`D3DKMTSetYieldPercentage`, means when there's a lot of GPU work in the background, see '[GPU yield percentage](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget)' description?) or GPU memory issues (if VRAM is kind of used while background processes need GPU memory, e.g. high quality captures?).
- [Game Mode power profile](https://noverse.dev/docs/win-config/system/game-mode/#game-mode-power-profile-wnf-state) doesn't seem to have any effect when the active scheme is already `GUID_MIN_POWER_SAVINGS` or a modified version of that scheme (must be GUID of `GUID_MIN_POWER_SAVINGS`, so not a copied version of it).

FPS testing isn't a good way to decide whether Game Mode has any benefits for you, rather check whether the game registers with Game Mode at all, whether the game already sets priority class correctly itself, whether CPU sets are applied, and if they are applied, which CPU set IDs are used. Use [gm_effects](https://noverse.dev/docs/win-config/system/game-mode#gm_effects)/WPR (see below, I'll add more on it soon to see if it's actually useful, since wevtutil doesn't show events)/SI for it.

```powershell
Provider: Microsoft.Windows.ResourceManager
GUID:     {4180C4F7-E238-5519-338F-EC214F0B49AA}

resourceFileName: %SystemRoot%\system32\PsmServiceExtHost.dll
messageFileName:  %SystemRoot%\system32\PsmServiceExtHost.dll
```

# DXG Kernel Values

## Registry Values

Based on pseudocode of [`dxgkrnl.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dxgkrnl)/[`dxgmms2.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/dxgmms2) of 23H2/25H2 as they differ at some point, see [records/Graphics-Drivers.txt](https://github.com/nohuto/regkit/blob/main/records/Graphics-Drivers.txt) for values that get read on boot ([boot capture guide](https://noverse.dev/docs/regkit/guides/wpr-wpa/)). Unless written otherwise, `REG_DWORD` ones accept the full range (`0-4294967295`), same for `REG_QWORD` (`0-18446744073709551615`).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    // GetCabcOptionFromRegistry
    "CABCOption" = 2; // REG_DWORD, if missing + if DisableCABC == 1 its 0, otherwise 2
    "DisableCABC" = 0; // REG_DWORD (bool), fallback for missing CABCOption

    // DXGADAPTER::ReadConfig
    "ContextNoPatchMode" = 0; // REG_DWORD
    "CreateGdiPrimaryOnSlaveGpu" = 0; // REG_DWORD (bool)
    "CrtcPhaseFrames" = 2; // REG_DWORD
    "DeadlockPulse" = 5000; // REG_DWORD
    "DeadlockPulseTolerance" = 500; // REG_DWORD
    "DeadlockTimeout" = 30000; // REG_DWORD
    "DisableBadDriverCheckForHwProtection" = 0; // REG_DWORD (bool)
    "DisableBoostedVSyncVirtualization" = 0; // REG_DWORD (bool)
    "DisableGdiContextGpuVa" = 0; // REG_DWORD (bool)
    "DisableIndependentVidPnVSync" = 0; // REG_DWORD (bool), VidPn = video present network
    "DisableMonitoredFenceGpuVa" = 0; // REG_DWORD (bool)
    "DisableMultiSourceMPOCheck" = 0; // REG_DWORD (bool)
                                      // From my understaning, if this is set to 0 it would let dxgkrnl mark an supported MPO layout as TryAgain (DXGK_CHECK_MULTIPLANE_OVERLAY_SUPPORT_RETURN_INFO, d3dkmddi.h WDK) when multiple unsynced outputs change at once, so DWM retries later (1 skips that)
    "DisableOverlays" = 0; // REG_DWORD (bool)
    "DisablePagingContextGpuVa" = 0; // REG_DWORD (bool)
    "DisableSecondaryIFlipSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "DriverManagesResidencyOverride" = 1; // REG_DWORD (bool)
    "DriverStoreCopyMode" = 1; // REG_DWORD, >1 = 2
    "EnableDecodeMPO" = 1; // REG_DWORD (bool)
    "EnableFbrValidation" = 1; // REG_DWORD (bool), Fbr = Front buffer rendering
    "EnableMultiPlaneOverlay3DDIs" = 0; // REG_DWORD (bool)
    "EnableOfferReclaimOnDriver" = 1; // REG_DWORD (bool)
    "EnablePanelFitterSupport" = 0; // REG_DWORD (bool)
    "EnableTimedCalls" = 0; // REG_DWORD (bool)
    "EnableWDDM23Synchronization" = 0; // REG_DWORD (bool)
    "Force32BitFences" = 0; // REG_DWORD (bool)
    "ForceAccessedPhysically" = 0; // REG_DWORD (bool)
    "ForceDirectFlip" = 0; // REG_DWORD (bool), if enabled it forces SupportDirectFlip (D3DKMDT_PREEMPTION_CAPS) to return true, which would for example skip such requirements (which would happen if SupportDirectFlip is false)
                           // "Driver reports SupportMultiPlaneOverlay cap but DirectFlip is not supported." (DXGADAPTER::Initialize)
    "ForceEnableDxgMms2" = 0; // REG_DWORD (bool)
    "ForceExplicitResidencyNotification" = 0; // REG_DWORD (bool)
    "ForceInitPagingProcessVaSpace" = 0; // REG_DWORD (bool)
    "ForceReplicateGdiContent" = 0; // REG_DWORD (bool)
    "ForceSecondaryIFlipSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "ForceSecondaryMPOSupport" = 0; // REG_DWORD (bool), secondary = secondary display
    "ForceSurpriseRemovalSupport" = 0; // REG_DWORD (bool)
    "ForceToMapGpuVa" = 0; // REG_DWORD (bool)
    "ForceVariableRefresh" = 0; // REG_DWORD (bool)
    "GdiPhysicalAdapterIndex" = 0; // REG_DWORD
    "InitialPagingQueueFenceValue" = 7000; // REG_DWORD
    "IoMmuFlags" = 0; // REG_DWORD
    "LeanMemoryLimit" = 1395864371; // REG_QWORD
    "NumVirtualFunctions" = 0; // REG_DWORD

    "EnableBasicRenderGpuPv" = 0; // REG_DWORD (bool), 25H2
    "KnownProcessBoostMode" = 1; // REG_DWORD, 25H2
    "SmallQuantumMode" = 1; // REG_DWORD, 25H2, 0 = disabled, 1 = auto (if GPU is MCDM adapter enabled), 2 = force enable
                            // related to VidSch scheduling quanta for GPU contexts
                            // pnputil /enum-devices /class ComputeAccelerator
    "HighPriorityCompletionMode" = 1; // REG_DWORD, 25H2
    "GpuPriorityChangeMode" = 1; // REG_DWORD, 25H2

    // DXGADAPTER::InitializePowerManagement
    "DefaultActiveIdleThreshold" = 2000; // REG_DWORD
    "DefaultD3TransitionIdleLongTimeThreshold" = 60000; // REG_DWORD
    "DefaultD3TransitionIdleShortTimeThreshold" = 10000; // REG_DWORD
    "DefaultD3TransitionIdleVeryLongTimeThreshold" = 60000; // REG_DWORD
    "DefaultD3TransitionLatencyActivelyUsed" = 80; // REG_DWORD
    "DefaultD3TransitionLatencyIdleLongTime" = 140000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleMonitorOff" = 250000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleNoContext" = 250000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleShortTime" = 80000; // REG_DWORD
    "DefaultD3TransitionLatencyIdleVeryLongTime" = 200000; // REG_DWORD
    "DefaultExpectedResidency" = 2000; // REG_DWORD
    "DefaultIdleThresholdIdle0" = 200; // REG_DWORD
    "DefaultIdleThresholdIdle0MonitorOff" = 100; // REG_DWORD
    "DefaultLatencyToleranceIdle0" = 80; // REG_DWORD
    "DefaultLatencyToleranceIdle0MonitorOff" = 2000; // REG_DWORD
    "DefaultLatencyToleranceIdle1" = 15000; // REG_DWORD
    "DefaultLatencyToleranceIdle1MonitorOff" = 50000; // REG_DWORD
    "DefaultLatencyToleranceMemory" = 15000; // REG_DWORD
    "DefaultLatencyToleranceMemoryNoContext" = 30000; // REG_DWORD
    "DefaultLatencyToleranceNoContext" = 35000; // REG_DWORD
    "DefaultLatencyToleranceNoContextMonitorOff" = 100000; // REG_DWORD
    "DefaultLatencyToleranceOther" = 4294967295; // REG_DWORD
    "DefaultLatencyToleranceTimerPeriod" = 200; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceActivelyUsed" = 80; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceIdleShortTime" = 15000; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceMonitorOff" = 80000; // REG_DWORD
    "DefaultMemoryRefreshLatencyToleranceNoContext" = 30000; // REG_DWORD
    "DefaultPowerNotRequiredTimeout" = 25000; // REG_DWORD
    "DisableDevicePowerRequired" = 0; // REG_DWORD (bool)
    "DisablePStateManagement" = 0; // REG_DWORD (bool), nonzero skips P-state query
    "EnablePODebounce" = 0; // REG_DWORD (bool)
    "EnableRuntimePowerManagement" = 1; // REG_DWORD (bool)
    "lowdebounce" = 3; // REG_DWORD
    "MonitorLatencyTolerance" = 300000; // REG_DWORD
    "MonitorRefreshLatencyTolerance" = 17000; // REG_DWORD
    "uglitch" = 900; // REG_DWORD, P-state requires ulow < uideal < uhigh < uglitch <= 1000
    "uhigh" = 700; // REG_DWORD, ^
    "uideal" = 500; // REG_DWORD, ^
    "ulow" = 300; // REG_DWORD, ^

    // DXGGLOBAL::Initialize
    "AllowAdvancedEtwLogging" = 0; // REG_DWORD (bool)
    "DiagnosticsBufferExpansionTime" = 300; // REG_DWORD
    "EnableFuzzing" = 0; // REG_DWORD (bool)
    "EnableHMDTestMode" = 0; // REG_DWORD (bool), HMD = head mounted display
    "EnableIgnoreWin32ProcessStatus" = 0; // REG_DWORD (bool)
    "ExternalDiagnosticsBufferMultiplier" = 1; // REG_DWORD
    "ExternalDiagnosticsBufferSize" = 16384; // REG_DWORD
    "ForceUsb4MonitorSupport" = 0; // REG_DWORD (bool)
    "InternalDiagnosticsBufferMultiplier" = 2; // REG_DWORD
    "InternalDiagnosticsBufferSize" = 65536; // REG_DWORD
    "InvestigationDebugParameter" = 0; // REG_DWORD
    "MaximumAdapterCount" = 32; // REG_DWORD
    "PreserveFirmwareMode" = 0; // REG_DWORD (bool)
    "PreventFullscreenWireFormatChange" = 0; // REG_DWORD (bool)
    "RapidHpdMaxChainInMilliseconds" = 0; // REG_DWORD
    "RapidHpdTimeoutInMilliseconds" = 0; // REG_DWORD
    "TerminationListSizeLimit" = 67108864; // REG_DWORD
    "TreatUsb4MonitorAsNormal" = 0; // REG_DWORD (bool)
    "Usb4MonitorDpcdDP_IN_Adapter_Number" = 0; // REG_DWORD
    "Usb4MonitorDpcdUSB4_Driver_ID" = 0; // REG_DWORD
    "Usb4MonitorPowerOnDelayInSeconds" = 0; // REG_DWORD
    "Usb4MonitorTargetId" = 0; // REG_DWORD
    "ValidateWDDMCaps" = 0; // REG_DWORD (bool)
    "WDDM2LockManagement" = 1; // REG_DWORD (bool)

    "NodeUsageTelemetryTimerInterval" = 86400; // REG_DWORD, 25H2

    // DpiFdoInitializeFdo
    "DisableVaBackedVm" = 0; // REG_DWORD (bool)
    "DisableVersionMismatchCheck" = 0; // REG_DWORD (bool)
    "GpuVirtualizationFlags" = ?; // REG_DWORD
    "DisableContainerSessionVersionCheck" = 0; // REG_DWORD (bool)
    "LimitNumberOfVfs" = 0; // REG_DWORD
    "VirtualGpuOnly" = 0; // REG_DWORD (bool)

    // DpiInitializeGlobalState
    "ForceBddFallbackOnly" = 0; // REG_DWORD (bool), 25H2
    "MiracastDefaultRtspPort" = 7236; // REG_DWORD, 0 = 7236
    "PlatformSupportMiracast" = 0; // REG_DWORD (bool)
                                   // "Miracast enables seamless display of multimedia content — including high-resolution pictures, high-definition video content, live television shows and sports, and other copy-protected premium content — between Wi-Fi devices, even if a Wi-Fi network is not available."
                                   // https://learn.microsoft.com/en-us/windows-hardware/drivers/display/wireless-displays--miracast-
    "SupportMultipleIntegratedDisplays" = 0; // REG_DWORD (bool)
    "SuspendAdapterTimerPeriod" = 500000; // REG_DWORD

    // https://noverse.dev/docs/win-config/system/hags/
    "HwSchMode" = 0; // REG_DWORD, range 0-2, >=3 = 0
    "HwSchOverrideBlockList" = 1; // REG_DWORD (bool)
    "HwSchTreatExperimentalAsStable" = 0; // REG_DWORD (bool)

    // VIDPN_MGR::_ReadConfiguration
    "EnableExperimentalRefreshRates" = 0; // REG_DWORD (bool), 25H2
    "RapidHPDThresholdCount" = 5; // REG_DWORD
    "RapidHPDTime" = 1000; // REG_DWORD

    // TdrInit, see https://noverse.dev/docs/win-config/security/increase-tdr/ for descriptions etc.
    "TdrDdiDelay" = 5; // REG_DWORD, range 1-900
    "TdrDebugMode" = 2; // REG_DWORD, range 0-3, other = 2
    "TdrDelay" = 2; // REG_DWORD, range 1-900
    "TdrDodPresentDelay" = 2; // REG_DWORD, range 1-900
    "TdrDodVSyncDelay" = 2; // REG_DWORD, range 1-900
    "TdrLevel" = 3; // REG_DWORD, range 0/1/3, other = 3
    "TdrLimitCount" = 5; // REG_DWORD, range 1-32
    "TdrLimitTime" = 60; // REG_DWORD, range 5-3600

    // DpiMiracastGetForcedMode
    "MiracastForceDisable" = 2; // REG_DWORD
                                // 0/>=2 = allow miracast
                                // 1 = force disable miracast
    "MiracastUseIhvDriver" = 2; // REG_DWORD

    // DxgMonitor::MonitorColorState::OnInitialized, 25H2
    "DefaultExternalSdrWhiteLevel" = 3000; // REG_DWORD
    "DefaultIntegratedSdrWhiteLevel" = 1000; // REG_DWORD

    // misc (single function)
    "DRTTestEnable" = 0; // REG_DWORD, DxgkpIsDrtEnabled, 1484026436 = enabled?
    "DisableAutoAcpiPostDeivce" = 0; // REG_DWORD (bool), DpiFdoDetectPostDevice, typo?
    "DxgEnableDesktopDuplicationDiagnostics" = 1; // REG_DWORD (bool), OUTPUTDUPL_MGR::IsDiagRegKeyEnabled
    "EnableAcmSupportDeveloperPreview" = 0; // REG_DWORD (bool), Acm = AutoColorManagement
    "EnableManualBrightnessMode" = 0; // REG_DWORD (bool), DpiBrightnessEscape
    "ForceEnableDWMClone" = ?; // REG_DWORD, ADAPTER_DISPLAY::Initialize (default depends on VirtualModeSupport, see DXGK_DISPLAY_DRIVERCAPS_EXTENSION in WDK)
    "HybridInternalPanelOverrideEnable" = 0; // REG_DWORD (bool), DpiHybridInternalPanelOverride
    "IsInternalRelease" = 0; // REG_DWORD (bool), DriverEntry
    "MultiMonSupport" = 1; // REG_DWORD (bool), DpiFdoHandleStartDevice
    "OutputDuplicationSessionApplicationLimit" = 4; // REG_DWORD, OUTPUTDUPL_SESSION_MGR::InitializeMaxActiveOutputDuplApps
    "PageFaultDebugMode" = 1; // REG_DWORD, VidSchInitializeAdapter, range 0-1, >1 = 1
    "TdrTestMode" = 0; // REG_DWORD (bool), _TdrIsTestMode
    "UnsupportedMonitorModesAllowed" = ?; // REG_DWORD (bool), CCD_BTL::CCD_BTL

    "CddBootImageMode" = ?;
    "CddBootScreenMode" = ?;
    "DisableLddmSpriteTearDown" = ?;
    "DisplayBrokerShouldNotBeActive" = ?;
    "DODPreferredPresentMoveRegeionsOverride" = ?;
    "DxgKrnlVersion" = ?;
    "MinDxgKrnlVersion" = ?;

    // from procmon boot trace
    "DispBrokerDebugCtrl" = ?;
    "WarpOverrideWDDMVersion" = ?;
    "WarpSupportHybridDiscrete" = ?;
    "WarpSupportsResourceResidency" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Scheduler";
    // VidSchiReadGlobalConfiguration
    "AdjustWorkerThreadPriority" = 1; // REG_DWORD (bool)
    "AutoSyncToCPUPriority" = 0; // REG_DWORD (bool)
    "BackgroundProcessMaximumAllowedPreemptionDelay" = 8; // REG_DWORD
    "CarryOverUsedQuantum" = 0; // REG_DWORD (bool)
    "ContextSchedulingPenaltyDelay" = 1000; // REG_DWORD
    "CountFlipTowardHwLimit" = 0; // REG_DWORD (bool)
    "CountPresentTowardHwLimit" = 0; // REG_DWORD (bool)
    "EnablePreemption" = 1; // REG_DWORD (bool)
    "FlipDoNotFlipMode" = 0; // REG_DWORD, range 0-2
    "ForceEnableFlipFenceModel" = 0; // REG_DWORD (bool)
    "ForceFlipTrueImmediateMode" = 0; // REG_DWORD, range 0-2, other ignored
    "ForegroundPriorityBoost" = 1; // REG_DWORD (bool)
    "HistoryLogSize" = 64; // REG_DWORD, range 16-65536 (must be power of two)
    "HwQueuedRenderPacketGroupLimit" = 2; // REG_DWORD, min 1
    "HwQueuedRenderPacketGroupLimitPerNode" = ?; // REG_BINARY
    "HwQueuePacketCap" = ?; // REG_DWORD, driver default, range 1-14
    "MaximumAllowedPreemptionDelay" = 900; // REG_DWORD
    "MaxYieldInterval" = 16; // REG_DWORD
    "NumberOfDmaPacketPool" = 20; // REG_DWORD, minimum 16
    "PerSourceCustomDuration" = ?; // REG_DWORD (bool)
    "PfnCpuOverride" = 0; // REG_DWORD, range 0-3
    "PreemptionQuantumUnit" = 50000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 0 (or 1 when GPU isn't MCDM adapter))
    "ProfileLevel" = 2; // REG_DWORD
    "QuantumUnit" = 25000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 0 (or 1 when GPU isn't MCDM adapter))
    "QueuedPresentLimit" = 3; // REG_DWORD, minimum 1
    "VSyncIdleTimeout" = 7; // REG_DWORD
    "YieldPercentage" = 10; // REG_DWORD, range 1-84

    "MaxFocusGpuQuantumWithoutPresent" = 100; // REG_DWORD, 25H2

    // VidSchiReadGlobalConfiguration (23H2)
    "DdiSuspendMode" = 0; // REG_DWORD, range 0-2
    "EnableContextDelay" = 1; // REG_DWORD (bool)
    "EnableFlipImmediateSwFlipQueue" = 1; // REG_DWORD (bool)
    "InitDriverFenceId" = 0; // REG_DWORD
    "LogDriverVSyncCallback" = 0; // REG_DWORD (bool)

    // VidSchiReadGlobalConfiguration (25H2)
    "AudioDgAutoBoostPriority" = 24; // REG_DWORD
    "DebugLargeSmoothenedDuration" = 1; // REG_DWORD (bool)
    "EnableDirectSubmission" = ?; // REG_DWORD (bool)
    "FrameServerAutoBoostPriority" = 17; // REG_DWORD

    "HwSchThreadOffloadMode" = 2; // REG_DWORD, 24H2+
    "MinYieldInterval" = 8000; // REG_DWORD
    "NpuContextSwitchQuantum" = 30000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 2 (or 1 when GPU is MCDM adapter))
    "NpuPreemptionQuantum" = 60000; // REG_DWORD, minimum 1 (only used if SmallQuantumMode = 2 (or 1 when GPU is MCDM adapter))

    // VidSchiReadDeviceConfiguration
    "FlipOverrideMode" = 0; // REG_DWORD, range 0-2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\MemoryManager";
    // VIDMM_GLOBAL::ReadConfiguration
    "BugcheckOnApertureCorruption" = 0; // REG_DWORD (bool)
    "CommitProcessHeapOnDemand" = 1; // REG_DWORD (bool)
    "DirectFlipMemoryRequirement" = 200; // REG_DWORD
    "DisablePrefetching" = 0; // REG_DWORD, bit 0 only
    "DmaBufferBytesLimitAllDevices" = 8388608; // REG_DWORD
    "DmaBufferListBytesLimitAllDevices" = 4194304; // REG_DWORD
    "EventThrottleThreshold" = 300; // REG_DWORD
    "EvictTemporaryPeriod" = 60; // REG_DWORD
    "EvictUnusedPeriod" = 60; // REG_DWORD
    "ExcessiveMemTransferFlipThreshold" = 15; // REG_DWORD
    "ExcessiveMemTransferPenalty" = 5; // REG_DWORD
    "MemTransferThreshold" = 10; // REG_DWORD
    "NbCddDmaBufferLimitPerDevice" = 4; // REG_DWORD
    "NbDmaBufferLimitCompareWatermark" = 10; // REG_DWORD
    "NbDmaBufferLimitPerDevice" = 256; // REG_DWORD
    "NbPagingHistoryRecords" = 0; // REG_DWORD
    "PagesHistory" = 0; // REG_DWORD, final max 134217727
    "PinDWMAllocationBackingStore" = 1; // REG_DWORD (bool)
    "PinnedApertureMemoryLimit" = 40; // REG_DWORD, range 0-89, >=90 = 40
    "PinnedMemoryLimit" = 25; // REG_DWORD, range 0-89, >=90 = 25
    "PrivateHeapPackingBlockSize" = 8388608; // REG_DWORD
    "PrivateHeapPackingThreshold" = 1048576; // REG_DWORD
    "ProcessPendingOfferPeriod" = 1; // REG_DWORD
    "ProcessSysmemOfferPeriod" = 8; // REG_DWORD
    "QuickApertureCorruptionCheck" = 0; // REG_DWORD (bool)
    "RemovePagesFromWorkingSetOnPagingForDwm" = 1; // REG_DWORD, bit 0 only
    "SegmentBalancingPolicy" = 2; // REG_DWORD
    "SegmentCleanupCountThreshold" = 6; // REG_DWORD
    "SegmentCleanupSizeThreshold" = 4096; // REG_DWORD
    "SegmentCleanupTime" = 20; // REG_DWORD
    "SelfRefreshVramForceEvictionTimer" = 900; // REG_DWORD
    "UseUnreset" = 1; // REG_DWORD, bit 0 only

    "PhysicalHeapHighestAddress" = 4294967295; // REG_QWORD
    "PhysicalHeapLowestAddress" = 0; // REG_QWORD
    "PhysicalHeapSize" = 0; // REG_QWORD

    "MaxSegmentSize" = 0; // REG_DWORD, dynamic name (MaxSegmentSize<0-31>), nonzero rounded to 4KB & min 8MB

    // VIDMM_GLOBAL::ReadCommitLimitInformation
    "MinimumSystemMemoryCommitLimit" = 0; // REG_DWORD
    "PinnedBackingStoreLimit" = 0; // REG_DWORD
    "SecondaryPartitionCommitLimitPercentage" = 80; // REG_DWORD, range 5-100
    "SmallSystemMemorySize" = 0; // REG_DWORD
    "SystemPartitionCommitLimitPercentage" = 50; // REG_DWORD, range 5-100

    // VIDMM_GLOBAL::ReadWorkingSetConfiguration
    "WorkingSet.DefaultMaximumPercentile" = 90; // REG_DWORD
    "WorkingSet.DefaultMinimumPercentile" = 65; // REG_DWORD

    // VIDMM_GLOBAL::ReadUnusedAllocationConfiguration
    "Unused.EvictApertureOfferHighThreshold" = 30; // REG_DWORD
    "Unused.EvictApertureOfferLowThreshold" = 15; // REG_DWORD
    "Unused.EvictApertureOfferMaximumThreshold" = 30; // REG_DWORD
    "Unused.EvictApertureOfferNormalThreshold" = 15; // REG_DWORD
    "Unused.HighThreshold" = 120; // REG_DWORD
    "Unused.LowThreshold" = 15; // REG_DWORD
    "Unused.MaximumThreshold" = 1000000; // REG_DWORD
    "Unused.MinimumThreshold" = 0; // REG_DWORD
    "Unused.NormalThreshold" = 45; // REG_DWORD
    "Unused.SelfTrimHighThreshold" = 5; // REG_DWORD
    "Unused.SelfTrimLowThreshold" = 1; // REG_DWORD
    "Unused.SelfTrimMaximumThreshold" = 1000000; // REG_DWORD
    "Unused.SelfTrimMinimumThreshold" = 0; // REG_DWORD
    "Unused.SelfTrimNormalThreshold" = 2; // REG_DWORD
    "UnusedTrimmingPeriod" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadPreparationPeriodConfiguration
    "Period.AlwaysForceMemReset" = 1; // REG_DWORD (bool)
    "Period.EvictionThresholdForMemReset" = 32; // REG_DWORD
    "Period.MaximumPolicyHeldPeriod" = 64; // REG_DWORD
    "Period.MinimumPolicyHeldPeriod" = 4; // REG_DWORD
    "Period.NbOfAllocationsThresholdToMRU" = 2147483647; // REG_DWORD
    "PreparationPeriod" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadHeapConfiguration
    "DebouncedDecommitAge" = 15; // REG_DWORD
    "DebouncedPageManagement" = 1; // REG_DWORD (bool)
    "DebouncedUnlockAge" = 15; // REG_DWORD
    "LeanRecycleHeapPackingBlockSize" = 8; // REG_DWORD
    "LeanRecycleHeapPackingThreshold" = 4; // REG_DWORD
    "LeanRecycleHeapPTDBlockSize" = 64; // REG_DWORD
    "MaximumDecommitDebounce" = 256; // REG_DWORD
    "MaximumUnlockDebounce" = 256; // REG_DWORD
    "RecycleHeapPackingBlockSize" = 32; // REG_DWORD
    "RecycleHeapPackingThreshold" = 4; // REG_DWORD
    "RecycleHeapPTDBlockSize" = 1024; // REG_DWORD
    "RecycleHistory" = 0; // REG_DWORD (bool)
    "RecycleHistorySize" = 64; // REG_DWORD
    "ZeroedRecyclePages" = 1; // REG_DWORD (bool)
    "ZeroPageLockThreshold" = 2097152; // REG_DWORD, 25H2

    // VIDMM_GLOBAL::ReadPowerConfiguration
    "MemoryComponentActiveThreshold" = 300; // REG_DWORD
    "SelfRefreshMemoryEvictionThreshold" = 300; // REG_DWORD

    // VIDMM_GLOBAL::ReadGpuVaConfiguration
    "AllocateGpuVaFromHighAddresses" = 0; // REG_DWORD (bool)
    "CompanionContextMaxPendingOperations" = 128; // REG_DWORD, max 2147483647, 25H2
    "DisableMakeIoMmuAddressValid" = 0; // REG_DWORD (bool)
    "DisableUncommitGpuVaInPagingProcess" = 0; // REG_DWORD (bool)
    "EnableGpuVaGuardPages" = 0; // REG_DWORD (bool)
    "EnableZeroFlagInPde" = 0; // REG_DWORD (bool)
    "GpuVaFirstValidAddress" = 65536; // REG_DWORD
    "PagingProcessVaSpaceBitCount" = 30; // REG_DWORD

    // VIDMM_GLOBAL::ReadGpuVaPagingHistoryConfiguration
    "GpuVaPagingHistoryMask" = 391174; // REG_DWORD, 391190 on 25H2?
    "GpuVaPagingHistorySize" = 0; // REG_DWORD, default 64 on 23H2 / 1024 on 25H2 if system memory > 1395864371

    // VIDMM_GLOBAL::ReadPagingConfiguration
    "BreakOnPagingFailure" = 0; // REG_DWORD (bool)
    "DemotionWithinDeviceEnabled" = 1; // REG_DWORD (bool)
    "DeviceResumePeriodMax" = 1000; // REG_DWORD
    "DeviceResumePeriodMin" = 1000; // REG_DWORD
    "DeviceSuspendPeriodMax" = 500; // REG_DWORD
    "DeviceSuspendPeriodMin" = 500; // REG_DWORD
    "EnableAsyncResidency" = 1; // REG_DWORD (bool)
    "EnablePromotion" = 1; // REG_DWORD (bool), 25H2
    "ForceSynchronousEvict" = 0; // REG_DWORD (bool)
    "ForceUncommitGpuVAOnEvict" = 0; // REG_DWORD (bool)
    "InitialPromotionInterval" = 48; // REG_DWORD
    "MaximumPromotionInterval" = 5000; // REG_DWORD
    "PagingQueueProcessingPeriodTime" = 50; // REG_DWORD, range 16-300
    "PromotionNumberCapPerInterval" = 50; // REG_DWORD
    "PromotionTargetSizePerInterval" = 33554432; // REG_QWORD
    "TemporaryResourcePolicy" = 0; // REG_DWORD, 25H2
    "TransferFlushThreshold" = 1; // REG_DWORD

    // VIDMM_GLOBAL::ReadTestAndStagingConfiguration
    "AlwaysDecommitOnOffer" = 0; // REG_DWORD (bool)
    "BudgetThreshold" = 25; // REG_DWORD, max 100
    "DecommitRepurposeMode" = 1; // REG_DWORD, range 0-2, 23H2
    "DxgMms2OfferReclaim" = 4294967295; // REG_DWORD, uses 0/1/2/4294967295
    "ExpandTo64KBAllocationSizeThreshold" = 4194304; // REG_DWORD
    "LargifyUpgradeThresholdBytes" = 0; // REG_DWORD, 25H2
    "LargifyUpgradeThresholdPercent" = 0; // REG_DWORD, max 100, 25H2
    "LazyDecommitChunkSizeMB" = 32; // REG_DWORD, max 512
    "PagingQueueFenceIncrement" = 1; // REG_DWORD, 0 = 1, max 85899345
    "RestrictToPreferredSegment" = 0; // REG_DWORD (bool)
    "Use64KPages" = 0; // REG_DWORD (bool)

    // VIDMM_GLOBAL::ReadVPRConfiguration
    "VPRCapacityRatioDenominator" = 5; // REG_DWORD
    "VPRCapacityRatioNumerator" = 1; // REG_DWORD
    "VPRGrowRatioDenominator" = 5; // REG_DWORD
    "VPRGrowRatioNumerator" = 4; // REG_DWORD

    // VIDMM_GLOBAL::ReadBudgetConfiguration
    "CriticalPeriodicTrimThreshold" = 10; // REG_DWORD, max StartPeriodicTrimThreshold
    "EnableTrimWnfCallback" = 1; // REG_DWORD (bool)
    "ForegroundTrimInterval" = 90000; // REG_DWORD, max 1200000
    "GlobalCommitmentBudget" = 0; // REG_QWORD
    "IdleTrimInterval" = 90000; // REG_DWORD, max 1200000, not less than MaximumTrimInterval
    "L_LocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "L_LocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "LNL_LocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "LNL_LocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "LNL_NonLocalMemoryBudgetDWMTarget" = 30; // REG_DWORD
    "LNL_NonLocalMemoryBudgetFocusTarget" = 50; // REG_DWORD, range 5-90
    "MaximumTrimInterval" = 10000; // REG_DWORD, range 16-60000
    "MaxProcessBudgetCapBuffer" = 256; // REG_DWORD
    "MaxVideoMemoryFragmentationBuffer" = 512; // REG_DWORD
    "MinimumTrimInterval" = 2000; // REG_DWORD, clamped to MaximumTrimInterval, min 16
    "ProcessBudgetCapBuffer" = 5; // REG_DWORD, max 50
    "StartPeriodicTrimThreshold" = 40; // REG_DWORD, max 100
    "SystemMemoryFragmentationBuffer" = 5; // REG_DWORD, max 50
    "VideoMemoryFragmentationBuffer" = 10; // REG_DWORD, max 50

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Paravirtualization";
    // DXGVIRTUALGPUMANAGER_PARAV::CreateVirtualGpu
    "GuestIoSpaceSizeInMb" = ?; // REG_DWORD, 23H2 default 1, 25H2 default 8192

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Power";
    // DXGADAPTER::InitializePowerManagement
    "UseSelfRefreshVRAMInS3" = 1; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\BasicDisplay";
    // NotifyUserMSBDAIfApplicable
    "BasicDisplayUserNotified" = 0; // REG_DWORD (bool)

    // DpiInitializeGlobalState
    "DisableBasicDisplayFallback" = 4294967295; // REG_DWORD
    "EnableBasicDisplayFallback" = 4294967295; // REG_DWORD
    "ForcePreserveBootDisplay" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Mdm";
    // DISPLAY_MUX_MGR::Init, 25H2
    "EnableMdmExperimentalDynamicFeature" = 0; // REG_DWORD (bool)
    "EnableMdmExperimentalStaticFeature" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Smm";
    // SmmQueryRegistry
    "DebugMode" = 0; // REG_DWORD, bit 0 only
    "EnablePageTracking" = 0; // REG_DWORD (bool)
    "ForceDmaRemapping" = 0; // REG_DWORD, bit 0 only
    "ForceEnableIommu" = 0; // REG_DWORD, range 0-2
    "IdentityMappedPassthrough" = 0; // REG_DWORD (bool), 25H2 only
    "LogicalAddressMode" = 0; // REG_DWORD, range 0-2
    "PreferHighLogicalAddresses" = 0; // REG_DWORD, bit 0 only

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    // VIDPN_MGR::_ReadConfiguration
    "AssertOnDdiViolation" = 0; // REG_DWORD (bool)
    "BadMonitorModeDiag" = 2; // REG_DWORD, range 1-2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\DMM";
    // ADAPTER_DISPLAY::Initialize
    "EnableVirtualRefreshRateOnExternalMonitor" = 0; // REG_DWORD (bool)
    "HPDFilterLimit" = 20000000; // REG_DWORD, range 1000000-100000000
    "LongLinkTrainingTimeout" = 1000; // REG_DWORD, valid when greater than ShortLinkTrainingTimeout + less than 30000
    "ModeListCaching" = 1; // REG_DWORD, enabled only if exactly 1
    "SetTimingsFlags" = 0; // REG_DWORD
    "ShortLinkTrainingTimeout" = 200; // REG_DWORD, valid when less than LongLinkTrainingTimeout

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Validation";
    // DXGVALIDATION::InitializeBootSettings
    "FailEscapeDDI" = 0; // REG_DWORD, only used when Level is nonzero and data exactly 1
    "FailRenderDDI" = 0; // REG_DWORD, ^
    "FailReserveGPUVA" = 0; // REG_DWORD, ^
    "ReportVirtualMachine" = 0; // REG_DWORD, ^
    "Level" = 0; // REG_DWORD, max 2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\MonitorDataStore\\MONITOR-ID"
    // DXGMONITOR::_RetrieveMonitorConfigurationFromMonitorStore
    "DockedOrientation" = 0; // REG_DWORD, range 0-3
    "EnableBoostRefreshRateByDefault" = 0; // REG_DWORD (bool)
    "MonitorOrientation" = 4294967295; // REG_DWORD, default depends on monitor

    // DXGMONITOR::_InitializeMonitorWithDriver
    "EnableIntegratedPanelBoostRefreshRateByDefault" = 0; // REG_DWORD (bool), 25H2
    "PreferredScaleFactor" = 0; // REG_DWORD, 0 = no per monitor override
    "VMSDisabled" = 0; // REG_DWORD (bool)

    // DxgMonitor::MonitorColorState::OnInitialized
    "AdvancedColorEnabled" = 0; // REG_DWORD (bool), 25H2 uses that as fallback
    "AutoColorManagementEnabled" = 0; // REG_DWORD (bool), 25H2
    "AutoColorManagementSupported" = 0; // REG_DWORD (bool)
    "HDREnabled" = 0; // REG_DWORD (bool), 25H2
    "SDRWhiteLevel" = 1000; // REG_DWORD, internal default 1000, external 3000

    // DxgMonitor::MonitorColorState::OnFunctionDriverArrival, Acm = AutoColorManagement
    "EnableIntegratedPanelAcmByDefault" = 0; // REG_DWORD (bool)
    "EnableIntegratedPanelHdrByDefault" = 0; // REG_DWORD (bool)
    "MicrosoftApprovedAcmSupport" = 0; // REG_DWORD (bool)

    // DxgMonitor::MonitorColorState::WcgDriverCapsSet
    "OverrideWCGCapabilities" = 0; // REG_DWORD (bool)

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration"; // https://noverse.dev/policies?p=Display*DisplaySetClonePreferredResolutionSource
    "DefaultCloneResolutionSetting" = 0; // "Set Cloned Monitor Preferred Resolution Source"
                                         // 0 = Default
                                         // 1 = Internal
                                         // 2 = External
                                         // https://noverse.dev/policies?p=Display*DisplaySetClonePreferredResolutionSource
    "DefaultTopologySetting" = 0; // "Configure Multiple Display Mode"
                                  // 0 = Default
                                  // 1 = Internal Only
                                  // 2 = External Only
                                  // 3 = Clone
                                  // 4 = Extend
                                  // https://noverse.dev/policies?p=Display*DisplayConfigureMultipleDisplayMode

// the keys below are based on a testing monitor, therefore the defaults will be different depending on the monitor

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\<CONFIG_ID>\\00\\00";
    "ActiveSize.cx" = ?; // REG_DWORD, horizontal pixels
    "ActiveSize.cy" = ?; // REG_DWORD, vertical lines
    "BoostRefreshRateMultiplier" = ?; // REG_DWORD
    "ColorBasis" = ?; // REG_DWORD
    "DwmClipBox.bottom" = ?; // REG_DWORD
    "DwmClipBox.left" = ?; // REG_DWORD
    "DwmClipBox.right" = ?; // REG_DWORD
    "DwmClipBox.top" = ?; // REG_DWORD
    "Flags" = ?; // REG_DWORD
    "HSyncFreq.Denominator" = ?; // REG_DWORD
    "HSyncFreq.Numerator" = ?; // REG_DWORD
    "PixelFormat" = ?; // REG_DWORD
    "PixelRate" = ?; // REG_DWORD
    "PrimSurfSize.cx" = ?; // REG_DWORD
    "PrimSurfSize.cy" = ?; // REG_DWORD
    "Rotation" = ?; // REG_DWORD
    "Scaling" = ?; // REG_DWORD
    "ScanlineOrdering" = ?; // REG_DWORD
    "Stride" = ?; // REG_DWORD
    "VideoStandard" = ?; // REG_DWORD
    "VirtualRefreshRate.Denominator" = ?; // REG_DWORD
    "VirtualRefreshRate.Numerator" = ?; // REG_DWORD
    "VSyncFreq.Denominator" = ?; // REG_DWORD
    "VSyncFreq.Numerator" = ?; // REG_DWORD, refresh rate

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\<CONFIG_ID>\\00";
    "CcdDbVersion" = ?; // REG_DWORD
    "ColorBasis" = ?; // REG_DWORD
    "PixelFormat" = ?; // REG_DWORD
    "Position.cx" = ?; // REG_DWORD
    "Position.cy" = ?; // REG_DWORD
    "PrimSurfSize.cx" = ?; // REG_DWORD
    "PrimSurfSize.cy" = ?; // REG_DWORD
    "Stride" = ?; // REG_DWORD

"HKLM\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\ScaleFactors\\MONITOR-ID";
    // DpiPersistence::ReadDpiFromRegistry
    "DpiValue" = 0; // REG_DWORD, https://noverse.dev/docs/win-config/system/display-scaling/

// miscellaneous (display adapter) PnP key values that I found while looking through xrefs of RtlQueryRegistryValuesEx within dxgkrnl/dxgmms2

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX";
    // DpiReadPnpRegistryValue
    "AllowUnspecifiedHSync" = 0; // REG_DWORD (bool)
    "AllowUnspecifiedPixelRate" = 0; // REG_DWORD (bool)
    "AllowUnspecifiedVSync" = 0; // REG_DWORD (bool)
    "DisableNonPOSTDevice" = 0; // REG_DWORD (bool)
    "EnableVirtualTopologySupport" = 0; // REG_DWORD (bool)
    "ForceDualViewBehavior" = 0; // REG_DWORD (bool)
    "NeedToSuspendVidSchBeforeSetGammaRamp" = ?; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX\\MemoryManager";
    // VIDMM_GLOBAL::ReadPhysicalAdapterConfiguration
    "MaxLocalSegmentSize" = 0; // REG_DWORD (MB)
    "MaxNonLocalSegmentSize" = 0; // REG_DWORD (MB)
    "SelfRefreshVramForceEvictionTimerAC" = 900; // REG_DWORD, 25H2
    "SelfRefreshVramForceEvictionTimerDC" = 900; // REG_DWORD, 25H2
    "Supports64KBPages" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e968-e325-11ce-bfc1-08002be10318}\\XXXX\\DxgkSettings";
    // DXGADAPTER::InitializePowerManagement, adapter override (for GraphicsDrivers\\Power value) when version < 2400 (2.4) which was used in W10 1803
    "UseSelfRefreshVRAMInS3" = 1; // REG_DWORD (bool)
```

### EnablePreemption

With [GPU preemption](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-preemption) the video scheduler can interrupt the context executing on a GPU engine, run another context, and later resume the interrupted work (context here = GPU command stream & execution state). The scheduler requests such an interrupt using a preemption packet, the [black packet](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-hardware-queue#types-of-dma-packets) is a such a preemption packet:

![](https://github.com/nohuto/win-config/blob/main/system/images/gpu-preemption.png?raw=true)

[`VidSchiReadGlobalConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiReadGlobalConfiguration.c) stores any nonzero data as bit `0`:

```c
// VidSchiReadGlobalConfiguration

v59 = 1; // default
v112[23] = L"EnablePreemption";
v112[24] = &v59;

*(_DWORD *)(a1 + 2536) = (v62 != 0 ? 0x400 : 0) | (v61 != 0 ? 0x100 : 0) | (v60 != 0 ? 0x10 : 0) | (v59 != 0) | (v58 != 0 ? 4 : 0) | (v57 != 0 ? 2 : 0) | *(_DWORD *)(a1 + 2536) & 0xFFFFFAE8;
// v59 != 0 sets bit 0
```

[`VidSchiCheckPreemptionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiCheckPreemptionPolicy.c) reads that bit when deciding whether the context should preempt the running one. If disabled, [`VidSchiSubmitPreemptionCommand`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiSubmitPreemptionCommand.c) isn't called, means it can't interrupt the current work so other contexts have to wait.

You can read bit `0` via (the offsets will very likely be different for you):

```c
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8) // DXGGLOBAL::m_pGlobal
lkd> r @$t1 = poi(@$t0+0x300) // DXGADAPTER
lkd> r @$t2 = poi(@$t1+0xb70) // ADAPTER_RENDER
lkd> r @$t3 = poi(@$t2+0x2e8) // VIDSCH_GLOBAL
lkd> .printf "EnablePreemption=%u\n", dwo(@$t3+0x9e8)&1
EnablePreemption=1
```

### DisableOverlays

Any nonzero data disables dxgkrnl [MPO support](https://noverse.dev/docs/win-config/system/dwm-values/#multiplane-overlay-mpo) for the adapter, so DWM/apps fall back to [composed](https://noverse.dev/docs/win-config/system/dwm-values/#present-modes) or non MPO presentation modes, `0` allows MPO support.

```c
// DisableOverlays = 0
brave.exe[8984]:
    000001EA9107F050 (DXGI): SyncInterval=1 Flags=256 CPU=16.623ms (60.2 fps) Display=16.676ms (60.0 fps) GPU=16.622ms Latency=22.396ms Hardware Composed: Independent Flip

// DisableOverlays = 1
brave.exe[7444]:
    000002CDD6A4F050 (DXGI): SyncInterval=1 Flags=256 CPU=16.696ms (59.9 fps) Display=19.413ms (51.6 fps) GPU=3.510ms Latency=23.017ms Composed: Flip
```

```c
// DXGADAPTER::ReadConfig

v61 = 0;
v123 = L"DisableOverlays";
v124 = &v61;

if ( v61 )
  *((_BYTE *)this + 2756) = 0;

// ADAPTER_RENDER::IsMultiPlaneOverlaySupported
return *(_BYTE *)(*((_QWORD *)this + 2) + 2756LL);
```

That value is also kind of related to DWM's [`OverlayTestMode`](https://noverse.dev/docs/win-config/system/dwm-values/#overlaytestmode), `OverlayTestMode = 5` disables DWM's overlay use in `dwmcore`, while `DisableOverlays = 1` disables MPO support in `dxgkrnl` (both can prevent `Hardware Composed: Independent Flip`).

### ForegroundPriorityBoost

Gives foreground graphics contexts with a priority below `16` a minimum GPU scheduling priority of `16`, means when the GPU is busy, their queued GPU work can run before work with a lower scheduling priority.

```c
// ForegroundPriorityBoost = 0
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8) // DXGGLOBAL::m_pGlobal
lkd> r @$t1 = poi(@$t0+0x300) // DXGADAPTER
lkd> r @$t2 = poi(@$t1+0xb70) // ADAPTER_RENDER
lkd> r @$t3 = poi(@$t2+0x2e8) // VIDSCH_GLOBAL
lkd> .printf "ForegroundPriorityBoost=%u\n", (dwo(@$t3+0x9E8)&0x400)>>0xa // see below
ForegroundPriorityBoost=0
```

```c
// ForegroundPriorityBoost = 1
lkd> .reload /f dxgkrnl.sys
lkd> r @$t0 = poi(dxgkrnl+0x140aa8)
lkd> r @$t1 = poi(@$t0+0x300)
lkd> r @$t2 = poi(@$t1+0xb70)
lkd> r @$t3 = poi(@$t2+0x2e8)
lkd> .printf "ForegroundPriorityBoost=%u\n", (dwo(@$t3+0x9E8)&0x400)>>0xa
ForegroundPriorityBoost=1
```

[`VidSchiReadGlobalConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiReadGlobalConfiguration.c) sets bit `0x400` in the scheduler flags at offset `2536` (`0x9E8`) if `ForegroundPriorityBoost` is nonzero, [`VidSchiComputePriority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgmms2/VidSchiComputePriority.c) reads that bit before applying the priority floor.

```c
// VidSchiReadGlobalConfiguration

v112[156] = L"ForegroundPriorityBoost";
v112[157] = &v62; // value data

*(_DWORD *)(a1 + 2536) = (v62 != 0 ? 0x400 : 0) | (v61 != 0 ? 0x100 : 0) | (v60 != 0 ? 0x10 : 0) | (v59 != 0) | (v58 != 0 ? 4 : 0) | (v57 != 0 ? 2 : 0) | *(_DWORD *)(a1 + 2536) & 0xFFFFFAE8;
```

```c
// VidSchiComputePriority

{
  if ( (*(_DWORD *)(v8 + 2536) & 0x400) != 0 && (a4 & 1) != 0 && *a5 < 0x10u )
    *a5 = 16;
  return 0LL;
}
```

### DisableVersionMismatchCheck

Controls whether the display driver's INF & KMD (`.sys`) versions get compared and if they match. `0` (default) = compare versions, nonzero = skip. See the current `.inf` file name via:

```powershell
Get-PnpDevice -Class Display -PresentOnly | Get-PnpDeviceProperty -KeyName DEVPKEY_Device_DriverInfPath | Select-Object -ExpandProperty Data
```

```c
// C:\Windows\INF\oem23.inf

[Version]
Signature   = "$Windows NT$"
Provider    = %NVIDIA%
ClassGUID   = {4D36E968-E325-11CE-BFC1-08002BE10318}
Class       = Display
DriverVer   = 05/19/2026, 32.0.16.1047
PnpLockdown = 1
CatalogFile = NV_DISP.CAT
[nv_CplInstaller]
Default_addreg = nv_CplInstaller_addreg
Default_copyfiles = nv_CplInstaller_copyfiles
```

`nvlddmkm.sys` = version `32.0.16.1047`, means the version matches. An mismatch fails adapter initialization with `STATUS_DEVICE_CONFIGURATION_ERROR` (`0xC0000182`) and records a live dump. There're some allowed mismatched, e.g. both major versions are below `21`.

## RegistryMachin_* Keys

These are from `dxgkrnl.sys`. Looking at xrefs of these names is sometimes a start point when trying to find values within a binary or to see what keys are somewhere used, therefore I'm adding it (note that `aRegistryMachin_*` are IDA generated names so you won't find them in strings, nor will they be the exact same for you unless you disassemble the same binary build version).

```c
// dxgkrnl.sys
aRegistryMachin = "\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\DWM"
aRegistryMachin_0 = "\\Registry\\Machine\\Software\\Microsoft\\Shell\\Docking"
aRegistryMachin_1 = "\\Registry\\Machine\\System\\Platform\\DeviceTargetingInfo"
aRegistryMachin_2 = "\\Registry\\Machine\\SOFTWARE\\Policies\\Microsoft\\Windows NT\\Terminal Services"
aRegistryMachin_3 = "\\Registry\\Machine\\"
aRegistryMachin_4 = "\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\MultiScreen"
aRegistryMachin_5 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BlockList\\Runtime"
aRegistryMachin_6 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BlockList\\Kernel"
aRegistryMachin_7 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class"
aRegistryMachin_8 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Control Panel\\Theme"
aRegistryMachin_9 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers"
aRegistryMachin_10 = "\\REGISTRY\\MACHINE\\OSDATA\\Software\\Microsoft\\Durango\\LiveSettings\\HevcOverride"
aRegistryMachin_11 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Connectivity\\"
aRegistryMachin_12 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\Configuration\\"
aRegistryMachin_13 = "\\REGISTRY\\MACHINE\\System\\ControlSet001\\Control\\Terminal Server\\WinStations"
aRegistryMachin_14 = "\\Registry\\Machine\\Software\\Microsoft\\DirectX"
aRegistryMachin_15 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\BreakOnBadEDID"
aRegistryMachin_16 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\MiniNT"
aRegistryMachin_17 = "\\Registry\\Machine\\Software\\Microsoft\\PolicyManager\\current\\Experience"
aRegistryMachin_18 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Video\\"
aRegistryMachin_19 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\MonitorDataStore"
aRegistryMachin_20 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\AdditionalModeLists\\"
aRegistryMachin_21 = "\\Registry\\Machine\\Software\\Microsoft\\Windows\\Dwm"
aRegistryMachin_22 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\FeatureSetUsage"
aRegistryMachin_23 = "\\Registry\\Machine\\System\\CurrentControlSet\\Control\\GraphicsDrivers\\InternalMonEdid"
aRegistryMachin_24 = "\\Registry\\Machine\\Software\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\CurrentVersion\\AppModel\\PackageRepository\\Packages"
aRegistryMachin_25 = "\\Registry\\Machine\\System"
aRegistryMachin_26 = "\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\\WinStations"
```

# HAGS

[HAGS](https://devblogs.microsoft.com/directx/hardware-accelerated-gpu-scheduling/) (*Hardware-accelerated GPU scheduling*) changes who handles high frequency GPU scheduling work, classic WDDM uses a high priority CPU scheduler thread, HAGS offloads much of that scheduling/context switch work to a GPU scheduling processor. Note that `TEAS` in the dropdown = `TreatExperimentalAsStable`.

![](https://github.com/nohuto/win-config/blob/main/system/images/HwQueue.png?raw=true)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers";
    "HwSchMode" = 0; // REG_DWORD, range 0-2, >=3 = 0
    "HwSchOverrideBlockList" = 1; // REG_DWORD (bool)
    "HwSchTreatExperimentalAsStable" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\\Scheduler";
    "HwSchThreadOffloadMode" = 2; // REG_DWORD, 24H2+
    "HwQueuedRenderPacketGroupLimit" = 2; // REG_DWORD, min 1
    "HwQueuedRenderPacketGroupLimitPerNode" = ?; // REG_BINARY
    "HwQueuePacketCap" = ?; // REG_DWORD, driver default, range 1-14
```

Query the current states using the name RVAs (`dword_1C01404B8` = HwSchMode, `byte_1C01404BC` = HwSchOverrideBlockList, `byte_1C01404BD` = HwSchTreatExperimentalAsStable for the part below, obviously these names depend on the IDA auto generation so they'll unlikely be the same for you), follow the [DriverStart + RVAs](https://noverse.dev/docs/win-config/system/mmcss-values/#driverstart--rvas) guide if you want to try it.

```c
lkd> dd dxgkrnl+1404b8 L1
fffff803`72b404b8  00000000 // HwSchMode

lkd> db dxgkrnl+1404bc L2
fffff803`72b404bc  01 00 // HwSchOverrideBlockList + HwSchTreatExperimentalAsStable
```

```c
// DpiInitializeGlobalState

v41 = L"HwSchMode";
v42 = (int *)&v24;
v26 = 1; // HwSchOverrideBlockList default
v25 = 0; // HwSchTreatExperimentalAsStable default
*(_QWORD *)&v48 = L"HwSchOverrideBlockList";
*((_QWORD *)&v48 + 1) = &v26;
v53 = L"HwSchTreatExperimentalAsStable";
v54 = (unsigned int *)&v25;
v6 = RtlQueryRegistryValuesEx(2LL, L"GraphicsDrivers", &v39, 0LL, 0LL);
if ( v6 >= 0 && v24 < 3 ) // HwSchMode range 0-2
{
  dword_1C01404B8 = v24;
  goto LABEL_19;
}
else
  dword_1C01404B8 = 0; // default if missing/query failed/value >= 3
if ( v6 >= 0 )
{
LABEL_19:
  byte_1C01404BC = 0; // can't really tell what impact that would have yet
  byte_1C01404BD = v25 != 0; // HwSchTreatExperimentalAsStable
  if ( !v26 ) // HwSchOverrideBlockList == 0
    goto LABEL_21;
}
byte_1C01404BC = 1; // query failed/HwSchOverrideBlockList nonzero (default)
```

`DXGK_FEATURE_SUPPORT_*` values are returned by the driver, these registry values are basically kind of "overrides" how dxgkrnl handles that support state.

| Value | Data | Meaning |
| --- | --- | --- |
| `HwSchMode` | `0` | Default OS policy |
| `HwSchMode` | `1` | Disable stable/experimental support (`DXGK_FEATURE_SUPPORT_ALWAYS_ON` would still turn it on) |
| `HwSchMode` | `2` | Allow stable support |
| `HwSchTreatExperimentalAsStable` | `0` | Experimental stays experimental |
| `HwSchTreatExperimentalAsStable` | nonzero | Experimental = stable (used when driver returns `DXGK_FEATURE_SUPPORT_EXPERIMENTAL`, then it would be `DXGK_FEATURE_SUPPORT_STABLE`) |

## DXGK_FEATURE_SUPPORT

```c
// DXGK_FEATURE_SUPPORT constants

// When a driver doesn't support a feature, it doesn't call into QueryFeatureSupport with that feature ID.
// This value is provided for implementation convenience of enumerating possible driver support states
// for a particular feature.
#define DXGK_FEATURE_SUPPORT_ALWAYS_OFF ((UINT)0)

// Driver support for a feature is in the experimental state
#define DXGK_FEATURE_SUPPORT_EXPERIMENTAL ((UINT)1)

// Driver support for a feature is in the stable state
#define DXGK_FEATURE_SUPPORT_STABLE ((UINT)2)

// Driver support for a feature is in the always on state,
// and it doesn't operate without this feature enabled.
#define DXGK_FEATURE_SUPPORT_ALWAYS_ON ((UINT)3)
```

## DXGK_FEATURE_ID

There're more than that, but I only included these as [`DpQueryFeatureSupport`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/dxgkrnl/DpQueryFeatureSupport.c) applies the same `HwSchMode`/`HwSchTreatExperimentalAsStable` policy to them.

- [`HWFLIPQUEUE` | drivers/display/hardware-flip-queue](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/hardware-flip-queue)
- [`USER_MODE_SUBMISSION` | drivers/display/user-mode-work-submission](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/user-mode-work-submission)

```cpp
// For each feature in this enumeration, if the driver supports it,
// it must invoke the OS QueryFeatureSupport callback
// to report the level of support (experimental, stable, always on),
// and only enable the feature if the OS returned Enabled=TRUE.
// Drivers that don't support the feature don't have to call the OS to query its status.
//
typedef enum _DXGK_FEATURE_ID
{
    DXGK_FEATURE_HWSCH                          = DXGK_DEFINE_FEATURE_ID(DXGK_FEATURE_CATEGORY_DRIVER, DXGK_DRIVER_FEATURE_HWSCH),
    DXGK_FEATURE_HWFLIPQUEUE                    = DXGK_DEFINE_FEATURE_ID(DXGK_FEATURE_CATEGORY_DRIVER, DXGK_DRIVER_FEATURE_HWFLIPQUEUE), // A hardware flip queue allows multiple future frames to be submitted to the display controller queue. The CPU and parts of the GPU can transition to lower power states while the display controller is processing multiple queued frames, improving power efficiency of video playback scenarios on capable hardware.
    DXGK_FEATURE_USER_MODE_SUBMISSION           = DXGK_DEFINE_FEATURE_ID(DXGK_FEATURE_CATEGORY_DRIVER, DXGK_DRIVER_FEATURE_USER_MODE_SUBMISSION),
} DXGK_FEATURE_ID;
```

## Scheduler Values

These are related to (dxgmms2) scheduler [hardware queue](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-hardware-queue) behavior.

| Value | Default data | Description |
| --- | --- | --- |
| `HwSchThreadOffloadMode` (24H2+) | `2` | Decides whether staged HW queues are handled via `ProcessHwQueue` or by the scheduler thread |
| `HwQueuedRenderPacketGroupLimit` | `2`, minimum `1` | Per node render packet group token count |
| `HwQueuedRenderPacketGroupLimitPerNode` | `REG_BINARY` | Per node override for the value above |
| `HwQueuePacketCap` | driver default, clamped `1-14` | Max DMA packets allowed queued to a node |

### HwSchThreadOffloadMode

`HwSchThreadOffloadMode` decides where staged [hardware queues](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/gpu-hardware-queue) are getting handled.

- `0`/`>=3` handles all staged queues through `ProcessHwQueue` on current caller
- `1` moves (offloads) all staged HW queues to the scheduler list and wakes the scheduler thread (`VidSchiWorkerThread`)
- `2` (default) only moves queues marked with `VIDSCH_HW_QUEUE`, others get handled by `ProcessHwQueue`

`ProcessHwQueues` has no `HwSchThreadOffloadMode`/`KLOCK_QUEUE_HANDLE` argument in [23H2 and previous builds](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-25H2&module=dxgmms2&name=VidSchiReadGlobalConfiguration.c&mode=side-by-side), means it's very similar to the "other values" part of `HwSchThreadOffloadMode`.

```c
// HwQueueStagingList::ProcessHwQueues

v6 = *(_DWORD *)(*(_QWORD *)this + 304LL); // HwSchThreadOffloadMode

if ( v6 == 1 )
{
  // move all staged HW queues to scheduler HW queue list
  goto LABEL_20;
}

if ( v6 == 2 ) // default
{
  if ( *((_BYTE *)v12 - 30) ) // VIDSCH_HW_QUEUE + 146
  {
    // move selected HW queue to same scheduler HW queue list
    v5 = 1;
  }
  if ( v5 )
  {
LABEL_20:
    *(_BYTE *)(*(_QWORD *)this + 296LL) = 0;
    *(_QWORD *)(*(_QWORD *)this + 1480LL) = MEMORY[0xFFFFF78000000320];
    KeSetEvent((PRKEVENT)(*(_QWORD *)this + 1448LL), 0, 0);
  }
}

// remaining queues
HwQueueStagingList::ProcessHwQueue(this, (HwQueueStagingList *)((char *)v18 - 176), a2);
```

## query_hwsch

`query_hwsch` calls `D3DKMTQueryAdapterInfo` (`KMTQAITYPE_WDDM_2_9_CAPS`/`KMTQAITYPE_WDDM_3_0_CAPS`) to get the `DriverSupportState`/`Enabled` bits, you can either use the [prebuild binary](https://github.com/nohuto/win-config/blob/main/system/assets/query_hwsch.exe), or build it yourself from [source](https://github.com/nohuto/win-config/tree/main/system/assets/query_hwsch):

```powershell
cmake -S . -B build
cmake --build build --config Release
```

Example output:

```c
// HwSchMode = 2
\\.\DISPLAY1
  AdapterLuid=00000000:00007552 VidPnSourceId=0 hAdapter=1073741824
  WDDM_2_9 HWSCH DriverSupportState=2 Enabled=1
  WDDM_3_0 HWFLIPQUEUE DriverSupportState=2 Enabled=1 DisplayableSupported=1

// HwSchMode = 1
\\.\DISPLAY1
  AdapterLuid=00000000:0000759f VidPnSourceId=0 hAdapter=1073741824
  WDDM_2_9 HWSCH DriverSupportState=2 Enabled=0
  WDDM_3_0 HWFLIPQUEUE DriverSupportState=2 Enabled=0 DisplayableSupported=1
```

### dxdiag

You can practically also use dxdiag, but that won't show the enabled bit of e.g. `HWFLIPQUEUE` via:

```powershell
dxdiag /t .\dxdiag.txt
```

Then look for the `Display Devices` section which should include `Hardware Scheduling` & other details.

# Heap Type

> *A heap is a memory management structure inside a process thats used for dynamic allocation. When code requests memory through APIs such as [`HeapAlloc()`](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc) / [`RtlAllocateHeap()`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap), the heap manager finds or creates a block inside the process address space and returns a pointer to it. When the code calls [`HeapFree()`](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapfree) / [`RtlFreeHeap()`](https://learn.microsoft.com/en-us/windows/win32/devnotes/rtlfreeheap), that block is returned to the heaps internal free space so it can be reused.*

Windows has two UM (user mode) heap implementations, the older NT heap and the newer Segment Heap. UWP/modern apps and some system processes normally use Segment Heap, while traditional desktop processes keep NT heap behavior (unless opted in via values below for example).

Most normal software in my testing (`ida.exe`, `VSCodium.exe`, `mullvadbrowser.exe`, `Procmon.exe`, `powershell.exe`, `ripgrep.exe`, `steam.exe`) used NT Heap. Segment Heap was used by Windows components/service hosts (`audiodg.exe`, `svchost.exe`, `lsass.exe`, `winlogon.exe`, `dwm.exe`, `ShellExperienceHost.exe`, `sihost.exe`, `WindowsTerminal.exe`) and some VBox processes. Note that one process can use more than one heap type.

Changing it to Segment Heap for a game won't impact FPS, rather read '[W10 Segment Heap Internals](https://www.blackhat.com/docs/us-16/materials/us-16-Yason-Windows-10-Segment-Heap-Internals-wp.pdf)' (or [Windows Internals](https://noverse.dev/docs/win-config/system/heap-type/#windows-internals)) to understand differences between NT/Segment Heap.

## heapType GUI

[`heapType.ps1`](https://github.com/nohuto/win-config/blob/main/system/assets/heapType.ps1) is a small GUI for the values (read everything below/above before using it):

![](https://github.com/nohuto/win-config/blob/main/system/images/heapType.png?raw=true)

## heap_dump

[`heap_dump.exe`](https://github.com/nohuto/win-config/blob/main/system/assets/heap_dump.exe) queries all running processes and lists their heaps as `NT Heap`/`NT Heap (LFH)`/`Segment Heap`. You can either use the [prebuilt binary](https://github.com/nohuto/win-config/blob/main/system/assets/heap_dump.exe), or build it yourself from [source](https://github.com/nohuto/win-config/blob/main/system/assets/heap_dump):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\heap_dump.exe
.\build\Release\heap_dump.exe --heaps > heaps.csv
```

It uses `RtlQueryProcessDebugInformation` for the heap list, then reads heap offsets (I've taken the same as [System Informer](https://github.com/winsiderss/systeminformer/blob/master/SystemInformer/include/heapstruct.h) uses here) uses to get `LFH`/`Lookaside` (`FrontEndHeapType`) & `NT Heap`/`Segment Heap` (`SegmentSignature`). By default it shows heap type counts, `--heaps` shows process name + PID + heap.

## Registry Values

These are easier to understand if comparing them to the [`RTL_HEAP_PARAMETERS`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters) structure, which is why I've added quotes from it to the parts below. The mentioned fallback in that MS doc also match with the default data I've found.

The `HeapSegment*` and `HeapDeCommit*` values are NT heap defaults (heap creation starts in [`RtlCreateHeap`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlCreateHeap.c), the Segment Heap path calls [`RtlpHpHeapCreate`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpHeapCreate.c) before those NT heap defaults are loaded).

```c
typedef struct _RTL_HEAP_PARAMETERS {
  ULONG                    Length;
  SIZE_T                   SegmentReserve; // 1MB fallback
  SIZE_T                   SegmentCommit; // PAGE_SIZE * 2 fallback
  SIZE_T                   DeCommitFreeBlockThreshold; // PAGE_SIZE fallback
  SIZE_T                   DeCommitTotalFreeThreshold; // 65536 fallback
  SIZE_T                   MaximumAllocationSize;
  SIZE_T                   VirtualMemoryThreshold;
  SIZE_T                   InitialCommit;
  SIZE_T                   InitialReserve;
  PRTL_HEAP_COMMIT_ROUTINE CommitRoutine;
  SIZE_T                   Reserved[2];
} RTL_HEAP_PARAMETERS, *PRTL_HEAP_PARAMETERS;
```

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "HeapSegmentReserve" = 1048576; // REG_DWORD, range 65536-16580608, 65536 steps
    "HeapSegmentCommit" = 8192; // REG_DWORD, range 4096-16580608, 4096 steps
    "HeapDeCommitFreeBlockThreshold" = 4096; // REG_DWORD, range 0-4294967280, 16 steps
    "HeapDeCommitTotalFreeThreshold" = 65536; // REG_DWORD, range 0-4294967280, 16 steps

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Segment Heap";
    "Enabled"; // REG_DWORD, 0 = disable, nonzero = enable (global)

"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\<executable>";
    "FrontEndHeapDebugOptions" = 0; // REG_DWORD, see bitfield below
    "DisableHeapLookaside" = 0; // REG_DWORD (bitfield), looks like a legacy value used to prevent ActivateLowFragmentationHeap (LFH) if 1
    "GCInterval"; // REG_DWORD, range 0-4294967295 seconds, only used if FrontEndHeapDebugOptions bit 22 is set
```

Enabling Segment Heap globally [sets the `ntdll` process flag](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpApplySegmentHeapConfigurations.c) before the per process opt in part runs, this can impact traditional desktop processes that weren't intended to use Segment Heap and may cause compatibility errors (it's not recommended to enable it globally).

### HeapSegmentReserve

> "*Segment reserve size, in bytes. If this value is not specified, 1 MB is used.*"
>
> — Microsoft, [RTL_HEAP_PARAMETERS](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters)

Preferred reserve size for a new NT heap segment, the heap compares it with allocation size + `8192`, uses the larger value, then rounds/caps.

`1 MB` = `1048576` bytes (`1024 * 1024`).

```c
// RtlpExtendHeap
v8 = a2 + 0x2000; // minimum reserve
if ( v8 <= *(_QWORD *)(a1 + 160) )
  v8 = *(_QWORD *)(a1 + 160); // use HeapSegmentReserve if it's larger
v9 = (v8 + 0xFFFF) & 0xFFFFFFFFFFFF0000uLL; // round up to 65536
if ( v9 >= 0xFD0000 )
  v9 = 16580608LL; // cap
```

### HeapSegmentCommit

> "*Segment commit size, in bytes. If this value is not specified, PAGE_SIZE * 2 is used.*"
>
> — Microsoft, [RTL_HEAP_PARAMETERS](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters)

[`PAGE_SIZE` = `4096`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntdll/RtlpExtendHeap.c) bytes, so `PAGE_SIZE * 2` = `8192`.

```c
// RtlpExtendHeap
v11 = a2 + 4096; // minimum commit
if ( v11 <= *(_QWORD *)(a1 + 168) )
  v11 = *(_QWORD *)(a1 + 168); // use HeapSegmentCommit if it is larger
v16[0] = (v11 + 4095) & 0xFFFFFFFFFFFFF000uLL; // round up to 4096
RtlpHpHeapCheckCommitLimit(v16[0], v12, a1, (unsigned __int64 *)(a1 + 376));
ZwAllocateVirtualMemory((HANDLE)0xFFFFFFFFFFFFFFFFLL, &BaseAddress, 0LL, v16, 0x1000u, 4u);
```

### HeapDeCommitFreeBlockThreshold

> "*Decommit free block threshold, in bytes. If this value is not specified, PAGE_SIZE is used.*"
>
> — Microsoft, [RTL_HEAP_PARAMETERS](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters)

```c
// RtlCreateHeap
*((_QWORD *)v43 + 22) = v56 >> 4; // store in 16 byte steps
```

### HeapDeCommitTotalFreeThreshold

> "*Decommit total free threshold, in bytes. If this value is not specified, 65536 is used.*"
>
> — Microsoft, [RTL_HEAP_PARAMETERS](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/ns-ntifs-rtl_heap_parameters)

```c
// RtlCreateHeap
*((_QWORD *)v43 + 23) = *(_QWORD *)&v61[0] >> 4; // store in 16 byte steps
```

### Enabled

Global Segment Heap switch read by [`RtlpHpApplySegmentHeapConfigurations`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpApplySegmentHeapConfigurations.c) during heap manager init, [`RtlInitializeHeapManager`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlInitializeHeapManager.c) uses those flags, `0x10` ([`RtlpHpOptIntoSegmentHeap`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpOptIntoSegmentHeap.c)) enables Segment Heap, `8` clears it after the opt in part.

When setting that value to `0` it would "force" NT Heap, means it overrides per process `FrontEndHeapDebugOptions = 8` (segment heap) changes too.

```c
// RtlpHpApplySegmentHeapConfigurations
result = NtQueryValueKey();
if ( result >= 0 && v1 == 4 ) // data length
{
  if ( v2 )
    RtlpLowFragHeapGlobalFlags |= 0x10; // nonzero = enable
  else
    RtlpLowFragHeapGlobalFlags |= 8; // zero = disable
}
```

#### heap_dump Results

`CSRSS port` is a small Windows communication heap used for talking to CSRSS, it stays NT Heap even when the app uses Segment Heap (as [`CsrpConnectToServer`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/CsrpConnectToServer.c) creates `HEAP_CLASS_8` on a fixed shared memory, means `HeapBase` =/ NULL).

Some requirements for Segment Heap (in [`RtlCreateHeap`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlCreateHeap.c)) also are that the heap is [`Growable` & `HeapBase` = NULL](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap), means that a heap would also use NT heap if this doesn't match (`HEAP_CLASS_7`/`HEAP_CLASS_8` aren't growable + don't have a `HeapBase` of NULL since they use a fixed shared memory).

```c
#define HEAP_CLASS_0 0x00000000 // Process heap
#define HEAP_CLASS_1 0x00001000 // Private heap
#define HEAP_CLASS_2 0x00002000 // Kernel heap
#define HEAP_CLASS_3 0x00003000 // GDI heap
#define HEAP_CLASS_4 0x00004000 // User heap
#define HEAP_CLASS_5 0x00005000 // Console heap
#define HEAP_CLASS_6 0x00006000 // User desktop heap
#define HEAP_CLASS_7 0x00007000 // CSR shared heap
#define HEAP_CLASS_8 0x00008000 // CSR port heap
```

- [processhacker.sourceforge.io/doc/ntrtl_8h_source](https://processhacker.sourceforge.io/doc/ntrtl_8h_source.html)

Use [heap_dump](https://noverse.dev/docs/win-config/system/heap-type/#heap_dump) to test it with your running processes. If the `Enabled` value is set *kind* of all types (process/private) went to Segement Heap, example:

```c
// Enabled = not present
"mullvadbrowser.exe",9616,1,0x000002184C9F0000,"NT Heap (LFH)","Process","Growable",0x2,1684,499712
"mullvadbrowser.exe",9616,2,0x000002184C9D0000,"NT Heap (LFH)","Process","Growable",0x2,22,36864
"mullvadbrowser.exe",9616,3,0x000002184C7D0000,"NT Heap","CSRSS port","-",0x0,3,4096
"mullvadbrowser.exe",9616,4,0x000002184C9C0000,"NT Heap (LFH)","Private","Growable",0x2,767,618496
"mullvadbrowser.exe",9968,1,0x0000020A76F40000,"NT Heap (LFH)","Process","Growable",0x2,28427,13340672
"mullvadbrowser.exe",9968,2,0x0000020A76DF0000,"NT Heap","CSRSS port","-",0x0,3,4096
"mullvadbrowser.exe",9968,3,0x0000020A77290000,"NT Heap (LFH)","Private","Growable",0x2,919,516096
"mullvadbrowser.exe",9968,4,0x0000020A00000000,"NT Heap","Private","Growable",0x2,12,8192
"mullvadbrowser.exe",9968,5,0x0000020A006D0000,"NT Heap","Process","Growable",0x2,3,8192
"mullvadbrowser.exe",9968,6,0x0000020A46690000,"NT Heap","Process","NoSerialize",0x1,7,16384

// Enabled = 1
"mullvadbrowser.exe",4436,1,0x00000215201A0000,"Segment Heap","Process","-",0x0,1630,536576
"mullvadbrowser.exe",4436,2,0x00000215201D0000,"Segment Heap","Process","-",0x0,5,16384
"mullvadbrowser.exe",4436,3,0x00000215200C0000,"NT Heap","CSRSS port","-",0x0,3,4096
"mullvadbrowser.exe",4436,4,0x0000021520550000,"Segment Heap","Private","-",0x0,310,262144
"mullvadbrowser.exe",8352,1,0x00000180998D0000,"Segment Heap","Process","-",0x0,14577,4730880
"mullvadbrowser.exe",8352,2,0x0000018099800000,"NT Heap","CSRSS port","-",0x0,3,4096
"mullvadbrowser.exe",8352,3,0x0000018099C50000,"Segment Heap","Private","-",0x0,43,45056
"mullvadbrowser.exe",8352,4,0x0000018099CC0000,"Segment Heap","Private","-",0x0,12,16384
"mullvadbrowser.exe",8352,5,0x000001809A710000,"Segment Heap","Process","-",0x0,3,16384
```

### FrontEndHeapDebugOptions

IFEO bitfield for one executable, bits `2`/`3` are the "meaningful" ones here which enable/disable Segement Heap (if both bits are set it would end in disable). I didn't search for actual behaviours for the flags beside them, therefore the "meaning" for the other ones is more likely only to show that they exist (for now).

```c
// LdrpInitializeExecutionOptions
RtlQueryApplicationKeyOption(v11, v9, (__int64)L"FrontEndHeapDebugOptions", 4u, (__int64)&v47, 4, v33, 0LL);
v10 = v47;

// RtlSetLowFragHeapGlobalFlags
RtlSetLowFragHeapGlobalFlags(v10, *(_DWORD *)(*(_QWORD *)(a2 + 32) + 8LL));
```

Some notes:
- enabling bit `4` enables heap stack tracing which allocates via [`RtlpHpStackDbAllocRoutine`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpStackDbAllocRoutine.c), [`RtlpHpMetadataAlloc`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpMetadataAlloc.c), [`RtlpHpMetadataHeapStart`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpMetadataHeapStart.c), [`RtlpHpMetadataHeapCreate`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpMetadataHeapCreate.c), [`RtlpHpHeapCreate`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpHeapCreate.c)
  - [`RtlpHpHeapCreate`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpHeapCreate.c) causes an extra segment heap here
- enabling bit `4` & `6` together causes a heap query error

![](https://github.com/nohuto/win-config/blob/main/system/images/RtlpHpStackTraceEnable.png?raw=true)

| Bit | Meaning |
| --- | --- |
| `0` | LFH global flag `4` |
| `1` | LFH global flag `2` |
| `2` | disable Segment Heap (flag `8`) |
| `3` | enable Segment Heap (flag `16`) |
| `4` | enables heap stack trace ([`RtlpHpStackTraceEnable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntdll/RtlpHpStackTraceEnable.c)) |
| `5` | `RtlpHpHeapFeatures \|= 4u`? |
| `6` | `RtlpHpAppCompatFlags \|= 11`? |
| `7` | `RtlpHpHeapFeatures \|= 8u`? |
| `8-15` | `RtlpHpLfhContentionLimit = BYTE1(a1)`? |
| `16-27` | `RtlpHpLfhPerfFlags = HIWORD(a1) & 4095`? |
| `22` | enables the `GCInterval` override |

## Validating Changes

You can see wether a program uses 'Segment Heap' or 'NT Heap' via for example [SI](https://github.com/winsiderss/systeminformer/) (Right Click > Miscellaneous > Heaps), it gets the heap list from `RtlQueryProcessDebugInformation`.

`HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\mullvadbrowser.exe`, `FrontEndHeapDebugOptions` = `4`:

![](https://github.com/nohuto/win-config/blob/main/system/images/ntheap.png?raw=true)

`HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\mullvadbrowser.exe`, `FrontEndHeapDebugOptions` = `8`:

![](https://github.com/nohuto/win-config/blob/main/system/images/segmentheap.png?raw=true)

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/segment1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/segment2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/segment3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/segment4.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/segment5.png?raw=true)

## Desktop Heap Logging

> "*It is meant to log information about desktop heap usage. This can be helpful when diagnosing issues where system resources for desktop objects might be strained.*"
>
> — Microsoft Community, [Question about some DWM registry settings](https://answers.microsoft.com/en-us/windows/forum/all/question-about-some-dwm-registry-settings/341cac5c-d85a-43e5-89d3-d9734f84da4e) (this isn't a verified answer, therefore can't be trusted)

```c
__int64 IsDesktopHeapLoggingOn(void)
{
  int v1 = 0; // default state
  int v4 = *(_DWORD *)(W32GetUserSessionState() + 62792);

  if ( v4 )
    v1 = 0; // fallback to the default when registry access fails
  return v1 != 0;
}
```

`DesktopHeapLogging` seems to have a fallback of `0`, but the value exists by default and is set to `1`. Means deleting it/setting it to `0` should do the same.

- [system/assets | IsDesktopHeapLoggingOn.c](https://github.com/nohuto/win-config/blob/main/system/assets/IsDesktopHeapLoggingOn.c)

# Memory Compression

Memory compression stores infrequently accessed, private memory pages in compressed form so they occupy less physical memory, causing Windows to keep more data in RAM and reduce pagefile I/O. Whenever a process references a compressed page again, it gets decompressed which is normally faster than reading it from storage, although compression and decompression consume CPU time. 

Disable it whenever you want to avoid the `SysMain` (`Disable (SysMain Off)` suboption which causes other MMAgent features to not work too) background activity, or when your system has enough RAM (which you never completely use) as compression will unlikely happen then anyway as shown below. See '[Services/Drivers, SysMain](https://noverse.dev/docs/win-config/system/disable-services-drivers/#sysmain)' before using that suboption as it handles other features too, which are beneficial on slow disks.

Compressed pages are stored in a dedicated "Memory Compression" (`MemCompression`) process managed by the Store Manager. Note that `SysMain` includes config functions used by `MMAgent`, while the actual compression work is done by the kernel Store Manager, means for the MMAgent state to apply and report correctly, `SysMain` must be allowed to run (if not, `MemCompression` won't be created).

On systems with enough free memory, it may stay **almost** unused even when it's enabled, as it becomes more relevant when active/cold private pages would otherwise have to be paged out. Means its just a processes which consumes no resources, and has inactive threads:

![](https://github.com/nohuto/win-config/blob/main/system/images/memory-compression.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/MemCompression.png?raw=true)

See '[Thread Activity](https://noverse.dev/docs/windbg-notes/threads/examining-thread-activity/thread-activity/)' whenever you want to read a bit more about the column meanings.

### MMAgent Cmdlet

`Enable-MMAgent -MemoryCompression` calls the `PS_MMAgent` CIM provider in `sysmain.dll`, which goes to `MmaConfigure`, sets the memory compression admin bit in the Superfetch key, may set `SysMain` to automatic start and (re)starts `SysMain` so the component state can be applied.

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Superfetch"
    AdminEnable & 0x200 // MemoryCompression requested enabled
    AdminDisable & 0x200 // MemoryCompression requested disabled
    StartedComponents & 0x200 // MemoryCompression started by SysMain
```

`0x200` = bit `9`, you can use my [bitmask calculator](https://noverse.dev/#bitmask) to see whenever that bit is set in your current `StartedComponents` data, example:

![](https://github.com/nohuto/win-config/blob/main/system/images/StartedComponents.png?raw=true)

See the current memory compression state via [MMAgent](https://learn.microsoft.com/en-us/powershell/module/mmagent/get-mmagent?view=windowsserver2025-ps):

```powershell
Get-MMAgent

ApplicationLaunchPrefetching : True
ApplicationPreLaunch         : True
MaxOperationAPIFiles         : 512
MemoryCompression            : True # Enabled
OperationAPI                 : True
PageCombining                : True
PSComputerName               :
```

### WinDbg

If memory compression was applied by `SysMain`, the process should exist:

```c
lkd> !process 0 0 MemCompression
PROCESS ffff9c06c430e040
    SessionId: none  Cid: 0654    Peb: 00000000  ParentCid: 0004
    DirBase: 121450000  ObjectTable: ffffb20888e79c00  HandleCount:   0.
    Image: MemCompression
```

On a 32GB RAM system without memory pressure, the process may exist but stay almost unused (different address as not executed in same session):

```c
lkd> !process ffff9c06c430e040 1
PROCESS ffff9c06c430e040
    SessionId: none  Cid: 0654    Peb: 00000000  ParentCid: 0004
    DirBase: 121450000  ObjectTable: ffffb20888e79c00  HandleCount:   0.
    Image: MemCompression
    VadRoot 0000000000000000 Vads 0 Clone 0 Private 5. Modified 0. Locked 0.
    DeviceMap 0000000000000000
    Token                             ffffb20888dd8040
    ElapsedTime                       00:39:09.121
    UserTime                          00:00:00.000
    KernelTime                        00:00:00.000
    QuotaPoolUsage[PagedPool]         4224
    QuotaPoolUsage[NonPagedPool]      0
    Working Set Sizes (now,min,max)  (5, 50, 345) (20KB, 200KB, 1380KB)
    PeakWorkingSetSize                0
    VirtualSize                       0 Mb
    PeakVirtualSize                   0 Mb
    PageFaultCount                    5
    MemoryPriority                    BACKGROUND
    BasePriority                      8
    CommitCharge                      10
```

After compression happened, the same process has actual private memory and a larger working set:

```c
lkd> !process ffffb4865f1cf040 1
PROCESS ffffb4865f1cf040
    SessionId: none  Cid: 06c0    Peb: 00000000  ParentCid: 0004
    DirBase: 1290ad000  ObjectTable: ffffe781db853b40  HandleCount:   0.
    Image: MemCompression
    VadRoot ffffb48667f8b020 Vads 2351 Clone 0 Private 75392. Modified 0. Locked 0.
    DeviceMap 0000000000000000
    Token                             ffffe781db893040
    ElapsedTime                       00:36:02.082
    UserTime                          00:00:00.000
    KernelTime                        00:00:00.078
    QuotaPoolUsage[PagedPool]         4224
    QuotaPoolUsage[NonPagedPool]      0
    Working Set Sizes (now,min,max)  (75392, 50, 345) (301568KB, 200KB, 1380KB)
    PeakWorkingSetSize                75459
    VirtualSize                       293 Mb
    PeakVirtualSize                   294 Mb
    PageFaultCount                    75680
    MemoryPriority                    BACKGROUND
    BasePriority                      8
    CommitCharge                      164
```

`75392` pages * `4096` bytes = `308,805,632` bytes, means the current size is about `294.5 MiB`.

The threads show whether the compression process is idle or doing work:

```c
lkd> !process ffff9c06c430e040 4
PROCESS ffff9c06c430e040
    SessionId: none  Cid: 0654    Peb: 00000000  ParentCid: 0004
    DirBase: 121450000  ObjectTable: ffffb20888e79c00  HandleCount:   0.
    Image: MemCompression

        THREAD ffff9c06c4327080  Cid 0654.0658  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c4326080  Cid 0654.065c  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c4321080  Cid 0654.0670  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c4320080  Cid 0654.0674  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c431e080  Cid 0654.067c  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c431d080  Cid 0654.0680  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c6e8e080  Cid 0654.11e4  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c708b0c0  Cid 0654.1008  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c495e080  Cid 0654.1e30  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
        THREAD ffff9c06c72cb080  Cid 0654.0758  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT
```

A thread can also show the SM (store manager) routine it is waiting in:

```c
lkd> !thread ffff9c06c4327080
THREAD ffff9c06c4327080  Cid 0654.0658  Teb: 0000000000000000 Win32Thread: 0000000000000000 WAIT: (WrKernel) KernelMode Non-Alertable
    ffff9c06baff4530  NotificationEvent
Owning Process            ffff9c06c430e040       Image:         MemCompression
Wait Start TickCount      238            Ticks: 10642 (0:00:02:46.281)
UserTime                  00:00:00.000
KernelTime                00:00:00.000
Win32 Start Address nt!SMKM_STORE_MGR<SM_TRAITS>::SmCompressCtxBalancerThread (0xfffff8031b3b5460)
Priority 25  BasePriority 25  Priority Floor 25  IoPriority 2  PagePriority 5
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/memcompress3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/memcompress2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/memcompress1.png?raw=true)

# Page Combining

Memory combining finds duplicate pages in RAM and replaces them with one shared physical page. All processes using those pages then reference the shared copy, and if a process modifies it, Windows creates a private copy for that process through `copy-on-write`.

![](https://github.com/nohuto/win-config/blob/main/system/images/copy-on-write-before.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/copy-on-write-after.png?raw=true)

The purpose of this memory management feature is to save physical memory, but on modern systems with 32-64GB of RAM the impact of page combining is often minimal (a page has a size of 4KB = 4096 byte).

![](https://github.com/nohuto/win-config/blob/main/system/images/page-sizes.png?raw=true)

```powershell
$ .\memcombine64 # while having several similar apps opened
Combining pages, please wait...
Success. Total pages combined: 284535 # 284535 * 4096 = 1,165,455,360 bytes = 1165.46 MB = 1.1655 GB

$ .\memcombine64
Combining pages, please wait...
Success. Total pages combined: 29490 # 29490 * 4096 = 120,791,040 bytes = 120.79 MB = 0.120791 GB
```

The amount of pages that can be combined is obviously not always same as it depends on how many identical private pages exist. See '[MemCombineTest](https://noverse.dev/docs/win-config/system/page-combining/#memcombinetest)' for notes on what memcombine64 does.

There's no separate process for page combining (like `MemCompression`), SysMain requests the work and the kernel Memory Manager does the combine work.

Disable it whenever you want to avoid the `SysMain` (`Disable (SysMain Off)` suboption which causes other MMAgent features to not work too) background activity, or when your system has enough RAM (which you never completely use) even tho the state of this memory managment feature is unrelated to RAM usage. See '[Services/Drivers, SysMain](https://noverse.dev/docs/win-config/system/disable-services-drivers/#sysmain)' before using that suboption as it handles other features too, which are beneficial on slow disks.

`Disable (MMAgent only)` won't set `DisablePageCombining = 1`, causing e.g. `MemCombine64.exe` to still be able to ask the memory manager to combine pages, if that value is set (bit `0`) the feature won't work at all ([`STATUS_NOT_SUPPORTED`](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55)):

```powershell
$ .\memcombine64
Combining pages, please wait...
Error: C00000BB # STATUS_NOT_SUPPORTED
```

### DisablePageCombining

> "*Page combining can be disabled by setting a DWORD value named `DisablePageCombining` to `1` in the `HKLM\System\CurrentControlSet\Control\Session Manager\Memory Management` registry key.*"
>
> — Windows Internals, [E7, P1: 'Memory combining'](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

That value is read from the `Memory Management` registry key into `nt!MmRegistryState+0x8` and read by `MiCombineIdenticalPages`, if bit 0 is set, the combine request returns [`STATUS_NOT_SUPPORTED`](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55) (not used by MMAgent obviously).

```asm
INIT:0000000140B9C340                 dq offset aSessionManager_7 ; "Session Manager\\Memory Management"
INIT:0000000140B9C348                 dq offset aDisablepagecom ; "DisablePageCombining"
INIT:0000000140B9C350                 dq offset dword_140D1D1C8

ALMOSTRO:0000000140D1D1C8 dword_140D1D1C8 dd 0                    ; DATA XREF: MiCombineIdenticalPages:loc_1407F7E3A↑r
```

```c
lkd> dd nt!MmRegistryState+8 L1
fffff803`1bd1d1c8  00000000
```

### MMAgent Cmdlet

`Enable-MMAgent -PageCombining` calls the `PS_MMAgent` CIM provider in `sysmain.dll`, which goes to `MmaConfigure`, sets the page combining admin bit in the Superfetch key, and relies on `SysMain` to apply the component state.

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Superfetch"
    AdminEnable & 0x100 // PageCombining requested enabled
    AdminDisable & 0x100 // PageCombining requested disabled
    StartedComponents & 0x100 // PageCombining started by SysMain
```

`0x100` = bit `8`, you can use my [bitmask calculator](https://noverse.dev/#bitmask) to see whenever that bit is set in your current `StartedComponents` data, example:

![](https://github.com/nohuto/win-config/blob/main/system/images/StartedComponents.png?raw=true)

See the requested page combining state via [MMAgent](https://learn.microsoft.com/en-us/powershell/module/mmagent/get-mmagent?view=windowsserver2025-ps):

```powershell
Get-MMAgent

ApplicationLaunchPrefetching : True
ApplicationPreLaunch         : True
MaxOperationAPIFiles         : 512
MemoryCompression            : True
OperationAPI                 : True
PageCombining                : True # Enabled
PSComputerName               :
```

### MemCombineTest

Start by downloading the [Windows Internals tools](https://github.com/zodiacon/WindowsInternals/releases/download/1.1/x64.zip) which include the two binaries we need & [VMMap](https://live.sysinternals.com/vmmap.exe).

[`MemCombineTest.exe`](https://github.com/zodiacon/WindowsInternals/blob/master/MemCombineTest/MemCombineTest.cpp) allocates two same content private buffers and waits, [`MemCombine64.exe`](https://github.com/zodiacon/WindowsInternals/blob/master/MemCombine/MemCombine.cpp) enables `SeProfileSingleProcessPrivilege` and calls `NtSetSystemInformation(SystemCombinePhysicalMemoryInformation = 130)`, which asks the memory manager to combine pages now instead of waiting for the normal background pass.

1. Start `MemCombineTest.exe` and leave it open
2. Open VMMap as admin and select the PID shown by `MemCombineTest` 
3. Take first VMMap screenshot of the process address space and note the two private buffers

![](https://github.com/nohuto/win-config/blob/main/system/images/MemCombineTest1.png?raw=true)

4. Run `MemCombine64.exe` as admin
5. Refresh VMMap and compare the private/shared working set

![](https://github.com/nohuto/win-config/blob/main/system/images/MemCombineTest2.png?raw=true)

6. Press a key in `MemCombineTest.exe` to modify one byte in the first buffer
7. Refresh VMMap again, the modified page should become private again cause of `copy-on-write`

![](https://github.com/nohuto/win-config/blob/main/system/images/MemCombineTest3.png?raw=true)

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/pagecomb1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/pagecomb2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/pagecomb3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/pagecomb4.png?raw=true)

# Disable Services/Drivers

I personally recommend using only the main option. This includes disabling telemetry/tracking/diagnostics/location/certain drivers/services, etc. It is not necessary to disable more than this, as most other features won't start automatically anyway. You can use the suboptions if you want to disable services/drivers (e.g. *"Autoplay Service, Bluetooth Services, Camera Services, File/Printer Sharing Services, Printer Services, Store Services"*) for a **specific** reason (note that this may cause broken functionalities). Disabling/enabling features via other options (e.g WER, Windows Search, Clipboard) includes changing service/driver `Start` data/setting policies etc, instead of only changing services/drivers state, so again, rather leave the suboptions alone.

## Service/Driver Table

You can dump all kind of information (including information like type, required privileges, failure actions, triggers, thread/handle count, KM/UM time etc. which the normal `services.msc` or any other programs won't show) using my [dumpServicesDrivers.ps1](https://github.com/nohuto/win-config/blob/main/system/assets/dumpServicesDrivers.ps1) script (which I also used for creating the tables below, see [services.txt](https://github.com/nohuto/win-config/blob/main/system/assets/services.txt)/[drivers.txt](https://github.com/nohuto/win-config/blob/main/system/assets/drivers.txt)), I've commented out some fields by default, edit the file if you want to see them.

The suboptions probably overlap the documentation. If so, you can open the [page on my website](https://github.com/nohuto/win-config/blob/main/system/desc.md#disable-servicesdrivers) instead.

### Activity Moderation

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `bam` | Controls activity of background applications | Kernel Driver (1) | - | system32\drivers\bam.sys |

### Autoplay

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `ShellHWDetection` | *Disabling causes CmdPal to not start directly after boot for whatever reason.* -Provides notifications for AutoPlay hardware events. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Beep

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Beep` | Legacy PC speaker/tone driver. It provides simple beeps for apps that call the Windows Beep API. | Kernel Driver (1) | - | - |

### Biometrics

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WbioSrvc` | The Windows biometric service gives client applications the ability to capture, compare, manipulate, and store biometric data without gaining direct access to any biometric hardware or samples. The service is hosted in a privileged SVCHOST process. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k WbioSvcGroup |

### Bluetooth

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `BTAGService` | Service supporting the audio gateway role of the Bluetooth Handsfree Profile. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted |
| `BluetoothUserService_*` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service, User Service Instance (224) | - | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BluetoothUserService` | The Bluetooth user service supports proper functionality of Bluetooth features relevant to each user session. | Win32 Share Process, User Service (96) | bthserv, rpcss | C:\Windows\system32\svchost.exe -k BthAppGroup -p |
| `BthA2dp` | Microsoft Bluetooth A2dp driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthA2dp.sys |
| `BthAvctpSvc` | This is Audio Video Control Transport Protocol service | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BthEnum` | Bluetooth Enumerator Service | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BthEnum.sys |
| `BthHFEnum` | Microsoft Bluetooth Hands-Free Profile driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthhfenum.sys |
| `BthLEEnum` | Bluetooth Low Energy Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.Legacy.LEEnumerator.sys |
| `BthMini` | Bluetooth Radio Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHMINI.sys |
| `BTHMODEM` | Bluetooth Modem Communications Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\bthmodem.sys |
| `BTHPORT` | Bluetooth Port Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHport.sys |
| `bthserv` | The Bluetooth service supports discovery and association of remote Bluetooth devices. Stopping or disabling this service may cause already installed Bluetooth devices to fail to operate properly and prevent new devices from being discovered or associated. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `BTHUSB` | Bluetooth Radio USB Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\BTHUSB.sys |
| `DeviceAssociationBrokerSvc` | Enables apps to pair devices | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow -p |
| `DeviceAssociationService` | Enables pairing between the system and wired or wireless devices. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `Microsoft_Bluetooth_AvrcpTransport` | Microsoft Bluetooth Avrcp Transport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Microsoft.Bluetooth.AvrcpTransport.sys |
| `RFCOMM` | Bluetooth Device (RFCOMM Protocol TDI) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rfcomm.sys |

### Broadcasts

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `BcastDVRUserService` | This user service is used for Game Recordings and Live Broadcasts | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k BcastDVRUserService |
| `CaptureService_*` | Enables optional screen capture functionality for applications that call the Windows.Graphics.Capture API. | Win32 Share Process, User Service, User Service Instance (224) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `AJRouter` | Routes AllJoyn messages for the local AllJoyn clients. If this service is stopped the AllJoyn clients that do not have their own bundled routers will be unable to run. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `CaptureService` | Enables optional screen capture functionality for applications that call the Windows.Graphics.Capture API. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |
| `CDPSvc` | This service is used for Connected Devices Platform scenarios | Win32 Share Process (32) | ncbservice, RpcSS, Tcpip | C:\Windows\system32\svchost.exe -k LocalService -p |
| `CDPUserSvc` | This user service is used for Connected Devices Platform scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `DevicePickerUserSvc` | This user service is used for managing the Miracast, DLNA, and DIAL UI | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `DevicesFlowUserSvc` | Allows ConnectUX and PC Settings to Connect and Pair with WiFi displays and Bluetooth devices. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `NcbService` | Brokers connections that allow packaged Microsoft Store apps to receive notifications from the internet. | Win32 Share Process (32) | RpcSS, tcpip, BrokerInfrastructure | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `NcdAutoSetup` | Network Connected Devices Auto-Setup service monitors and installs qualified devices that connect to a qualified network. Stopping or disabling this service will prevent Windows from discovering and installing qualified network connected devices automatically. Users can still manually add network connected devices to a PC through the user interface. | Win32 Share Process (32) | netprofm | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `p2pimsvc` | Provides identity services for the Peer Name Resolution Protocol (PNRP) and Peer-to-Peer Grouping services. If disabled, the Peer Name Resolution Protocol (PNRP) and Peer-to-Peer Grouping services may not function, and some applications, such as HomeGroup and Remote Assistance, may not function correctly. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `p2psvc` | Enables multi-party communication using Peer-to-Peer Grouping. If disabled, some applications, such as HomeGroup, may not function. | Win32 Share Process (32) | p2pimsvc, PNRPSvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `PNRPAutoReg` | This service publishes a machine name using the Peer Name Resolution Protocol. Configuration is managed via the netsh context `p2p pnrp peer`. | Win32 Share Process (32) | pnrpsvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |
| `PNRPsvc` | Enables serverless peer name resolution over the Internet using the Peer Name Resolution Protocol (PNRP). If disabled, some peer-to-peer and collaborative applications, such as Remote Assistance, may not function. | Win32 Share Process (32) | p2pimsvc | C:\Windows\System32\svchost.exe -k LocalServicePeerNet |

### Camera

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `FrameServer` | Enables multiple clients to access video frames from camera devices. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k Camera |
| `FrameServerMonitor` | Monitors the health and state for the Windows Camera Frame Server service. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k CameraMonitor |
| `StiSvc` | Provides image acquisition services for scanners and cameras | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k imgsvc |

### CDROM

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cdrom` | CD-ROM Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\cdrom.sys |

### Clipboard

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cbdhsvc` | This user service is used for Clipboard scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k ClipboardSvcGroup -p |

### Cloud Filter

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CldFlt` | Cloud Files Mini Filter Driver | File System Driver (2) | FltMgr | system32\drivers\cldflt.sys |

### DHCP

> "*Dynamic Host Configuration Protocol (DHCP) is a standardized protocol that enables clients to be dynamically assigned with various configuration parameters, such as an IP address, subnet mask, default gateway, and other critical network configuration information. DHCP servers centrally manage such configuration data, and are configured by network administrators with settings that are appropriate for a given network environment. DHCP servers in turn communicate with DHCP clients through the use of DHCP messages.*"
>
> — Microsoft, [About Dynamic Host Configuration Protocol](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Dhcp` | Registers and updates IP addresses and DNS records for this computer. If this service is stopped, this computer will not receive dynamic IP addresses and DNS updates. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | NSI, Afd | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Diagnostics

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DusmSvc` | Network data usage, data limit, restrict background data, metered networks. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `DPS` | The Diagnostic Policy Service enables problem detection, troubleshooting and resolution for Windows components. If this service is stopped, diagnostics will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `diagsvc` | Executes diagnostic actions for troubleshooting support | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k diagnostics |
| `WdiServiceHost` | The Diagnostic Service Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local Service context. If this service is stopped, any diagnostics that depend on it will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalService -p |
| `WdiSystemHost` | The Diagnostic System Host is used by the Diagnostic Policy Service to host diagnostics that need to run in a Local System context. If this service is stopped, any diagnostics that depend on it will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `TroubleshootingSvc` | Enables automatic mitigation for known problems by applying recommended troubleshooting. If stopped, your device will not get recommended troubleshooting for problems on your device. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Domain/RPC

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Netlogon` | Maintains a secure channel between this computer and the domain controller for authenticating users and services. If this service is stopped, the computer may not authenticate users and services and the domain controller cannot register DNS records. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | LanmanWorkstation | C:\Windows\system32\lsass.exe |
| `MsRPC` | MsRPC | Kernel Driver (1) | - | - |
| `RpcLocator` | In Windows 2003 and earlier versions of Windows, the Remote Procedure Call (RPC) Locator service manages the RPC name service database. In Windows Vista and later versions of Windows, this service does not provide any functionality and is present for application compatibility. | Win32 Own Process (16) | - | C:\Windows\system32\locator.exe |

### Edge

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MicrosoftEdgeElevationService` | Provides elevated privileges for Microsoft Edge. | - | - | - |
| `edgeupdate` | Keeps your Microsoft software up to date. If this service is disabled or stopped, your Microsoft software will not be kept up to date, meaning security vulnerabilities that may arise cannot be fixed and features may not work. This service uninstalls itself when there is no Microsoft software using it. | - | - | - |
| `edgeupdatem` | Keeps your Microsoft software up to date. If this service is disabled or stopped, your Microsoft software will not be kept up to date, meaning security vulnerabilities that may arise cannot be fixed and features may not work. This service uninstalls itself when there is no Microsoft software using it. | - | - | - |

### File/Printer Sharing

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `LanmanServer` | Supports file, print, and named-pipe sharing over the network for this computer. If this service is stopped, these functions will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SamSS, Srv2 | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `LanmanWorkstation` | Creates and maintains client network connections to remote servers using the SMB protocol. If this service is stopped, these connections will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | Bowser, MRxSmb20, NSI | C:\Windows\System32\svchost.exe -k NetworkService -p |
| `CSC` | Allows network files to be used while the local computer is offline. | Kernel Driver (1) | rdbss | system32\drivers\csc.sys |
| `CscService` | The Offline Files service performs maintenance activities on the Offline Files cache, responds to user logon and logoff events, implements the internals of the public API, and dispatches interesting events to those interested in Offline Files activities and changes in cache state. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `Dfsc` | Client driver for access to DFS Namespaces | File System Driver (2) | Mup | System32\Drivers\dfsc.sys |
| `MRxDAV` | Network Redirector that provides WebDAV file access for the WebClient service | File System Driver (2) | rdbss | \SystemRoot\system32\drivers\mrxdav.sys |
| `mrxsmb` | Implements the framework for the SMB filesystem redirector | File System Driver (2) | rdbss | system32\DRIVERS\mrxsmb.sys |
| `mrxsmb20` | Implements the SMB 2.0 protocol, which provides connectivity to network resources on Windows Vista and later servers | File System Driver (2) | mrxsmb | system32\DRIVERS\mrxsmb20.sys |
| `P9Rdr` | Plan 9 Redirector Driver | Kernel Driver (1) | RDBSS | System32\drivers\p9rdr.sys |
| `P9RdrService` | Enables trigger-starting plan9 file servers. | Win32 Share Process, User Service (96) | P9Rdr, RPCSS | C:\Windows\system32\svchost.exe -k P9RdrService -p |
| `rdbss` | Provides the framework for network mini-redirectors | File System Driver (2) | Mup | system32\DRIVERS\rdbss.sys |
| `WebClient` | Enables Windows-based programs to create, access, and modify Internet-based files. If this service is stopped, these functions will not be available. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | MRxDAV | C:\Windows\system32\svchost.exe -k LocalService -p |

### GameInput

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `GameInputSvc` | Enables keyboards, mice, gamepads, and other input devices to be used with the GameInput API. | Win32 Own Process (16) | - | C:\Windows\System32\GameInputSvc.exe |

### HyperV

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `bttflt` | Microsoft Hyper-V VHDPMEM BTT Filter | Kernel Driver (1) | - | System32\drivers\bttflt.sys |
| `gencounter` | Microsoft Hyper-V Generation Counter | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgencounter.sys |
| `hvcrash` | Hyper-V Crashdump | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvcrash.sys |
| `HvHost` | Provides an interface for the Hyper-V hypervisor to provide per-partition performance counters to the host operating system. | Win32 Share Process (32) | hvservice | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `hvservice` | Microsoft Hypervisor Service Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvservice.sys |
| `hyperkbd` | Microsoft VMBus Synthetic Keyboard Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hyperkbd.sys |
| `HyperVideo` | Microsoft VMBus Video Device Miniport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\HyperVideo.sys |
| `storflt` | Microsoft Hyper-V Storage Accelerator | Kernel Driver (1) | - | System32\drivers\vmstorfl.sys |
| `Vid` | Microsoft Hyper-V Virtualization Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Vid.sys |
| `vmbus` | Virtual Machine Bus | Kernel Driver (1) | - | System32\drivers\vmbus.sys |
| `vmgid` | Microsoft Hyper-V Guest Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgid.sys |
| `vmicguestinterface` | Provides an interface for the Hyper-V host to interact with specific services running inside the virtual machine. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicheartbeat` | Monitors the state of this virtual machine by reporting a heartbeat at regular intervals. This service helps you identify running virtual machines that have stopped responding. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmickvpexchange` | Provides a mechanism to exchange data between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicrdv` | Provides a platform for communication between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmicshutdown` | Provides a mechanism to shut down the operating system of this virtual machine from the management interfaces on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmictimesync` | Synchronizes the system time of this virtual machine with the system time of the physical computer. | Win32 Share Process (32) | VmGid | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `vmicvmsession` | Provides a mechanism to manage virtual machine with PowerShell via VM session without a virtual network. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicvss` | Coordinates the communications that are required to use Volume Shadow Copy Service to back up applications and data on this virtual machine from the operating system on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vpci` | Microsoft Hyper-V Virtual PCI Bus | Kernel Driver (1) | - | System32\drivers\vpci.sys |

### IPv6

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Tcpip6` | @todo.dll,-100;Microsoft IPv6 Protocol Driver | Kernel Driver (1) | Tcpip | System32\drivers\tcpip.sys |
| `IpxlatCfgSvc` | Configures and enables translation from v4 to v6 and vice versa | Win32 Share Process (32) | nsi | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |

### IP Helper

> "*Internet Protocol Helper (IP Helper) assists network administration of the local computer by enabling applications to retrieve information about the network configuration of the local computer, and to modify that configuration. IP Helper also provides notification mechanisms to ensure that an application is notified when certain aspects of the local computer network configuration change.*"
>
> — Microsoft, [About IP Helper](https://learn.microsoft.com/en-us/windows/win32/iphlp/about-ip-helper)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `iphlpsvc` | Provides tunnel connectivity using IPv6 transition technologies (6to4, ISATAP, Port Proxy, and Teredo), and IP-HTTPS. If this service is stopped, the computer will not have the enhanced connectivity benefits that these technologies offer. | Win32 Share Process (32) | RpcSS, tcpip, nsi, WinHttpAutoProxySvc | C:\Windows\System32\svchost.exe -k NetSvcs -p |

### Kernel Debug Network

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `kdnic` | Microsoft Kernel Debugger Network Miniport | Kernel Driver (1) | - | \SystemRoot\System32\drivers\kdnic.sys |

### Location

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `lfsvc` | This service monitors the current location of the system and manages geofences (a geographical location with associated events). If you turn off this service, applications will be unable to use or receive notifications for geolocation or geofences. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Maps Manager

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MapsBroker` | Windows service for application access to downloaded maps. This service is started on-demand by application accessing downloaded maps. Disabling this service will prevent apps from accessing maps. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k NetworkService -p |

### Network Discovery

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `fdPHost` | The FDPHOST service hosts the Function Discovery (FD) network discovery providers. These FD providers supply network discovery services for the Simple Services Discovery Protocol (SSDP) and Web Services Discovery (WS-D) protocol. Stopping or disabling the FDPHOST service will disable network discovery for these protocols when using FD. When this service is unavailable, network services using FD and relying on these discovery protocols will be unable to find network devices or resources. | Win32 Share Process (32) | RpcSs, http | C:\Windows\system32\svchost.exe -k LocalService -p |
| `FDResPub` | Publishes this computer and resources attached to this computer so they can be discovered over the network. If this service is stopped, network resources will no longer be published and they will not be discovered by other computers on the network. | Win32 Share Process (32) | RpcSs, http, fdphost | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SSDPSRV` | Discovers networked devices and services that use the SSDP discovery protocol, such as UPnP devices. Also announces SSDP devices and services running on the local computer. If this service is stopped, SSDP-based devices will not be discovered. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | HTTP, NSI | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `upnphost` | Allows UPnP devices to be hosted on this computer. If this service is stopped, any hosted UPnP devices will stop functioning and no additional hosted devices can be added. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SSDPSRV, HTTP | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `MsLldp` | Microsoft Link-Layer Discovery Protocol Driver | Kernel Driver (1) | - | system32\drivers\mslldp.sys |
| `rspndr` | Link-Layer Topology Discovery Responder | Kernel Driver (1) | - | system32\drivers\rspndr.sys |
| `lltdio` | Link-Layer Topology Discovery Mapper I/O Driver | Kernel Driver (1) | - | system32\drivers\lltdio.sys |
| `lltdsvc` | Creates a Network Map, consisting of PC and device topology (connectivity) information, and metadata describing each PC and device. If this service is disabled, the Network Map will not function properly. | Win32 Share Process (32) | rpcss, lltdio | C:\Windows\System32\svchost.exe -k LocalService -p |

### Office

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `ClickToRunSvc` | - | - | - | - |

### Telephony

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `PhoneSvc` | Manages the telephony state on the device | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |
| `TapiSrv` | Provides Telephony API (TAPI) support for programs that control telephony devices on the local computer and, through the LAN, on servers that are also running the service. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k NetworkService -p |

### Radio Management

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RmSvc` | Radio Management and Airplane Mode Service. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted |

### Parental Control

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WpcMonSvc` | Enforces parental controls for child accounts in Windows. If this service is stopped or disabled, parental controls may not be enforced. | Win32 Own Process (16) | - | C:\Windows\system32\svchost.exe -k LocalService |

### Printer

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `McpManagementService` | Universal Print Management Service | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k McpManagementServiceGroup |
| `PrintDeviceConfigurationService` | The Print Device Configuration Service manages the installation of IPP and UP printers. If this service is stopped, any printer installations that are in-progress may be canceled. | - | - | - |
| `PrintNotify` | This service opens custom printer dialog boxes and handles notifications from a remote print server or a printer. If you turn off this service, you wont be able to see printer extensions or notifications. | Win32 Share Process, Interactive (288) | RpcSs | C:\Windows\system32\svchost.exe -k print |
| `PrintScanBrokerService` | Provides support for secure privileged operations needed by low priv spooler. | - | - | - |
| `PrintWorkflowUserSvc` | Provides support for Print Workflow applications. If you turn off this service, you may not be able to print successfully. | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k PrintWorkflow |
| `Spooler` | This service spools print jobs and handles interaction with the printer. If you turn off this service, you won't be able to print or see your printers. | Win32 Own Process, Interactive (272) | RPCSS, http | C:\Windows\System32\spoolsv.exe |
| `usbprint` | Microsoft USB PRINTER Class | Kernel Driver (1) | - | \SystemRoot\System32\drivers\usbprint.sys |

### Recovery / Backup

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CloudBackupRestoreSvc` | Monitors the system for changes in application and setting states and performs cloud backup and restore operations when required. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `SDRSVC` | Provides Windows Backup and Restore capabilities. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\svchost.exe -k SDRSVC |
| `swprv` | Manages software-based volume shadow copies taken by the Volume Shadow Copy service. If this service is stopped, software-based volume shadow copies cannot be managed. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS | C:\Windows\System32\svchost.exe -k swprv |
| `VSS` | Manages and implements Volume Shadow Copies used for backup and other purposes. If this service is stopped, shadow copies will be unavailable for backup and the backup may fail. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\vssvc.exe |
| `wbengine` | The WBENGINE service is used by Windows Backup to perform backup and recovery operations. If this service is stopped by a user, it may cause the currently running backup or recovery operation to fail. Disabling this service may disable backup and recovery operations using Windows Backup on this computer. | Win32 Own Process (16) | - | "C:\Windows\system32\wbengine.exe" |

### Remote Desktop

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SessionEnv` | Remote Desktop Configuration service (RDCS) is responsible for all Remote Desktop Services and Remote Desktop related configuration and session maintenance activities that require SYSTEM context. These include per-session temporary folders, RD themes, and RD certificates. | Win32 Share Process (32) | RPCSS, LanmanWorkstation | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `TermService` | Allows users to connect interactively to a remote computer. Remote Desktop and Remote Desktop Session Host Server depend on this service. To prevent remote use of this computer, clear the checkboxes on the Remote tab of the System properties control panel item. | Win32 Share Process (32) | RPCSS | C:\Windows\System32\svchost.exe -k NetworkService |
| `UmRdpService` | Allows the redirection of Printers/Drives/Ports for RDP connections | Win32 Share Process (32) | TermService, RDPDR | C:\Windows\System32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `rdpbus` | Remote Desktop Device Redirector Bus Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rdpbus.sys |
| `RDPDR` | Remote Desktop Device Redirector Driver | Kernel Driver (1) | RDBSS | System32\drivers\rdpdr.sys |
| `terminpt` | Microsoft Remote Desktop Input Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\terminpt.sys |
| `TsUsbFlt` | Remote Desktop USB Hub Class Filter Driver | Kernel Driver (1) | - | system32\drivers\tsusbflt.sys |
| `TsUsbGD` | Remote Desktop Generic USB Device | Kernel Driver (1) | - | \SystemRoot\System32\drivers\TsUsbGD.sys |
| `tsusbhub` | Remote Desktop USB Hub | Kernel Driver (1) | - | \SystemRoot\System32\drivers\tsusbhub.sys |

### Sensor

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SensorDataService` | Delivers data from a variety of sensors | Win32 Own Process (16) | - | C:\Windows\System32\SensorDataService.exe |
| `SensrSvc` | Monitors various sensors in order to expose data and adapt to system and user state. If this service is stopped or disabled, the display brightness will not adapt to lighting conditions. Stopping this service may affect other system functionality and features as well. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SensorService` | A service for sensors that manages different sensors' functionality. Manages Simple Device Orientation (SDO) and History for sensors. Loads the SDO sensor that reports device orientation changes. If this service is stopped or disabled, the SDO sensor will not be loaded and so auto-rotation will not occur. History collection from Sensors will also be stopped. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `perceptionsimulation` | Enables spatial perception simulation, virtual camera management and spatial input simulation. | Win32 Own Process (16) | rpcss | C:\Windows\system32\PerceptionSimulation\PerceptionSimulationService.exe |
| `spectrum` | Enables spatial perception, spatial input, and holographic rendering. | Win32 Own Process (16) | rpcss | C:\Windows\system32\spectrum.exe |
| `VacSvc` | Hosts spatial analysis for Mixed Reality audio simulation. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Sign-In Assistant

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wlidsvc` | Enables user sign-in through Microsoft account identity services. If this service is stopped, users will not be able to logon to the computer with their Microsoft account. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `NaturalAuthentication` | Signal aggregator service, that evaluates signals based on time, network, geolocation, bluetooth and cdf factors. Supported features are Device Unlock, Dynamic Lock and Dynamo MDM policies | Win32 Share Process (32) | RpcSs, ProfSvc, Schedule | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `NgcCtnrSvc` | Manages local user identity keys used to authenticate user to identity providers as well as TPM virtual smart cards. If this service is disabled, local user identity keys and TPM virtual smart cards will not be accessible. It is recommended that you do not reconfigure this service. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NgcSvc` | Provides process isolation for cryptographic keys used to authenticate to a user's associated identity providers. If this service is disabled, all uses and management of these keys will not be available, which includes machine logon and single-sign on for apps and websites. This service starts and stops automatically. It is recommended that you do not reconfigure this service. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Smart Card

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SCardSvr` | Manages access to smart cards read by this computer. If this service is stopped, this computer will be unable to read smart cards. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation |
| `ScDeviceEnum` | Creates software device nodes for all smart card readers accessible to a given session. If this service is disabled, WinRT APIs will not be able to enumerate smart card readers. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted |
| `SCPolicySvc` | Allows the system to be configured to lock the user desktop upon smart card removal. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs |
| `scfilter` | Smart card reader filter driver enabling smart card PnP. | Kernel Driver (1) | - | System32\DRIVERS\scfilter.sys |

### SysMain

Note that disabling this service will cause memory management features like memory compression/combining to not start anymore, see '[Memory Compression](https://noverse.dev/docs/win-config/system/memory-compression/)' & '[Page Combining](https://noverse.dev/docs/win-config/system/page-combining/)'.

- Service = `C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p`
- DLL = `C:\Windows\System32\sysmain.dll`

The `EnableSuperfetch` value has no effect whenever this service is disabled, `EnablePrefetcher` seems to may still be used at some point in the kernel.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SysMain` | SysMain (Superfetch) records app usage patterns, builds prefetch metadata (layout.ini), and warms the cache by preloading files/pages to cut boot and app startup latency, it also handles prefetcher behavior via EnablePrefetcher settings. ([Windows Internals, E7-P1](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)) | Win32 Share Process (32) | rpcss, fileinfo | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Microsoft Store

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `AppXSvc` | *Disabling breaks CmdPal and other store applications.* - Provides infrastructure support for deploying Store applications. This service is started on demand and if disabled Store applications will not be deployed to the system, and may not function properly. | Win32 Share Process (32) | rpcss, staterepository | C:\Windows\system32\svchost.exe -k wsappx -p |
| `camsvc` | Provides facilities for managing UWP apps access to app capabilities as well as checking an app's access to specific app capabilities | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k osprivacy -p |
| `ClipSVC` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled applications bought using the Microsoft Store will not behave correctly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k wsappx -p |
| `InstallService` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then installations will not function properly. | Win32 Own Process (16) | rpcss | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `LicenseManager` | Provides infrastructure support for the Microsoft Store. This service is started on demand and if disabled then content acquired through the Microsoft Store will not function properly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalService -p |
| `PushToInstall` | Provides infrastructure support for the Microsoft Store. This service is started automatically and if disabled then remote installations will not function properly. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k netsvcs -p |

### TCP/IP NetBIOS Helper

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `lmhosts` | Provides support for the NetBIOS over TCP/IP (NetBT) service and NetBIOS name resolution for clients on the network, therefore enabling users to share files, print, and log on to the network. If this service is stopped, these functions might be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | Afd | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Telemetry

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DiagTrack` | The Connected User Experiences and Telemetry service enables features that support in-application and connected user experiences. Additionally, this service manages the event driven collection and transmission of diagnostic and usage information (used to improve the experience and quality of the Windows Platform) when the diagnostics and usage privacy option settings are enabled under Feedback and Diagnostics. | Win32 Own Process (16) | RpcSs | C:\Windows\System32\svchost.exe -k utcsvc -p |
| `dmwappushservice` | Routes Wireless Application Protocol (WAP) Push messages received by the device and synchronizes Device Management sessions | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `Ndu` | This service provides network data usage monitoring functionality, disabling breaks e.g. the Send/Reveice graphcs in task manager, use System Informer anyways which will continue to show the graph | Kernel Driver (1) | tcpip | system32\drivers\Ndu.sys |
| `InventorySvc` | This service performs background system inventory, compatibility appraisal, and maintenance used by numerous system components. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k InvSvcGroup -p |
| `PcaSvc` | This service provides support for the Program Compatibility Assistant (PCA). PCA monitors programs installed and run by the user and detects known compatibility problems. If this service is stopped, PCA will not function properly. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `wuqisvc` | A Microsoft service producing summary facts and insights related to usage and quality of experience. Facts are used to automate on-device self-healing and other optional workflows, such as Personalized offers. | - | - | - |

### Themes

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Themes` | Provides user experience theme management. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Time

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `autotimesvc` | This service sets time based on NITZ messages from a Mobile Network | Win32 Own Process (16) | rpcss | C:\Windows\system32\svchost.exe -k autoTimeSvc |
| `tzautoupdate` | Automatically sets the system time zone. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |

### Trusted Runtime

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WindowsTrustedRT` | Windows Trusted Runtime Interface Driver | Kernel Driver (1) | - | system32\drivers\WindowsTrustedRT.sys |
| `WindowsTrustedRTProxy` | Windows Trusted Runtime Service Proxy Driver | Kernel Driver (1) | - | System32\drivers\WindowsTrustedRTProxy.sys |
| `PEAUTH` | Protected Environment Authentication and Authorization Export Driver | Kernel Driver (1) | - | system32\drivers\peauth.sys |

### UAC

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `luafv` | Virtualizes file write failures to per-user locations. | File System Driver (2) | FltMgr | \SystemRoot\system32\drivers\luafv.sys |

### User Data & Sync Platform

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `UnistoreSvc` | Handles storage of structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. | Win32 Share Process, User Service (96) | - | C:\Windows\System32\svchost.exe -k UnistackSvcGroup |
| `UserDataSvc` | Provides apps access to structured user data, including contact info, calendars, messages, and other content. If you stop or disable this service, apps that use this data might not work correctly. | Win32 Share Process, User Service (96) | UnistoreSvc | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `ConsentUxUserSvc` | Allows the system to request user consent to allow apps to access sensitive resources and information such as the device's location | Win32 Share Process, User Service (96) | RpcSs | C:\Windows\system32\svchost.exe -k DevicesFlow |
| `MessagingService` | Service supporting text messaging and related functionality. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |
| `PimIndexMaintenanceSvc` | Indexes contact data for fast contact searching. If you stop or disable this service, contacts might be missing from your search results. | Win32 Share Process, User Service (96) | UnistoreSvc | C:\Windows\system32\svchost.exe -k UnistackSvcGroup |

### Virtual Bus

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CompositeBus` | Multi-Transport Composite Bus Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\compositebus.inf_amd64_2e50c98177d80a40\CompositeBus.sys |
| `umbus` | User-Mode Bus Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\umbus.inf_amd64_3702527f0d5a77cf\umbus.sys |
| `vdrvroot` | Virtual Drive Root Enumerator | Kernel Driver (1) | - | System32\drivers\vdrvroot.sys |
| `NdisVirtualBus` | Microsoft Virtual Network Adapter Enumerator | Kernel Driver (1) | - | \SystemRoot\System32\drivers\NdisVirtualBus.sys |

### WER

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WerSvc` | Allows errors to be reported when programs stop working or responding and allows existing solutions to be delivered. Also allows logs to be generated for diagnostic and repair services. If this service is stopped, error reporting might not work correctly and results of diagnostic services and repairs might not be displayed. | Win32 Own Process (16) | - | C:\Windows\System32\svchost.exe -k WerSvcGroup |
| `wercplsupport` | This service provides support for viewing, sending and deletion of system-level problem reports for the Problem Reports control panel. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Wi-Fi

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WlanSvc` | The WLANSVC service provides the logic required to configure, discover, connect to, and disconnect from a wireless local area network (WLAN) as defined by IEEE 802.11 standards. It also contains the logic to turn your computer into a software access point so that other devices or computers can connect to your computer wirelessly using a WLAN adapter that can support this. Stopping or disabling the WLANSVC service will make all WLAN adapters on your computer inaccessible from the Windows networking UI. It is strongly recommended that you have the WLANSVC service running if your computer has a WLAN adapter. | Win32 Own Process (16) | nativewifip, RpcSs, Ndisuio, wcmsvc | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vwififlt` | Virtual WiFi Filter Driver | Kernel Driver (1) | - | System32\drivers\vwififlt.sys |
| `wcncsvc` | WCNCSVC hosts the Windows Connect Now Configuration which is Microsoft's Implementation of Wireless Protected Setup (WPS) protocol. This is used to configure Wireless LAN settings for an Access Point (AP) or a Wireless Device. The service is started programmatically as needed. | Win32 Share Process (32) | rpcss | C:\Windows\System32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `WFDSConMgrSvc` | Manages connections to wireless services, including wireless display and docking. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `NativeWifiP` | NativeWiFi Filter | Kernel Driver (1) | - | system32\DRIVERS\nwifi.sys |
| `Wificx` | Wifi Network Adapter Class Extension | Kernel Driver (1) | NetAdapterCx | system32\drivers\WifiCx.sys |

### Windows Defender

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WinDefend` | Helps protect users from malware and other potentially unwanted software | Win32 Own Process (16) | RpcSs | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\MsMpEng.exe" |
| `MsSecCore` | Microsoft Security Core Boot Driver | Kernel Driver (1) | - | system32\drivers\msseccore.sys |
| `wscsvc` | The WSCSVC (Windows Security Center) service monitors and reports security health settings on the computer.  The health settings include firewall (on/off), antivirus (on/off/out of date), antispyware (on/off/out of date), Windows Update (automatically/manually download and install updates), User Account Control (on/off), and Internet settings (recommended/not recommended). The service provides COM APIs for independent software vendors to register and record the state of their products to the Security Center service.  The Security and Maintenance UI uses the service to provide systray alerts and a graphical view of the security health states in the Security and Maintenance control panel.  Network Access Protection (NAP) uses the service to report the security health states of clients to the NAP Network Policy Server to make network quarantine decisions.  The service also has a public API that allows external consumers to programmatically retrieve the aggregated security health state of the system. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `WdFilter` | Microsoft Defender Antivirus On-Access Malware Protection Mini-Filter Driver | File System Driver (2) | FltMgr | system32\drivers\wd\WdFilter.sys |
| `WdBoot` | Microsoft Defender Antivirus Boot Driver | Kernel Driver (1) | - | system32\drivers\wd\WdBoot.sys |
| `WdNisSvc` | Helps guard against intrusion attempts targeting known and newly discovered vulnerabilities in network protocols | Win32 Own Process (16) | WdNisDrv | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\NisSrv.exe" |
| `WdNisDrv` | Helps guard against intrusion attempts targeting known and newly discovered vulnerabilities in network protocols | Kernel Driver (1) | BFE | system32\drivers\wd\WdNisDrv.sys |
| `SecurityHealthService` | Windows Security Service handles unified device protection and health information | Win32 Own Process (16) | RpcSs | C:\Windows\system32\SecurityHealthService.exe |
| `Sense` | Windows Defender Advanced Threat Protection service helps protect against advanced threats by monitoring and reporting security events that happen on the computer. | Win32 Own Process (16) | - | "C:\Program Files\Windows Defender Advanced Threat Protection\MsSense.exe" |
| `MDCoreSvc` | Monitors the availability, health, and performance of various security components | Win32 Own Process (16) | - | "C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.26060.3008-0\MpDefenderCoreService.exe" |

### Windows Insider

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wisvc` | Provides infrastructure support for the Windows Insider Program. This service must remain enabled for the Windows Insider Program to work. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Windows Search

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WSearch` | Provides content indexing, property caching, and search results for files, e-mail, and other content. | Win32 Own Process (16) | RPCSS, BrokerInfrastructure | C:\Windows\system32\SearchIndexer.exe /Embedding |

### Windows Update

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WaaSMedicSvc` | Repairs damaged Windows Update components so that the computer can keep getting updates. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k wusvcs -p |
| `UsoSvc` | Manages Windows Updates. If stopped, your devices will not be able to download and install the latest updates. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `wuauserv` | Enables the detection, download, and installation of updates for Windows and other programs. If this service is disabled, users of this computer will not be able to use Windows Update or its automatic updating feature, and programs will not be able to use the Windows Update Agent (WUA) API. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |

### Xbox

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `XboxGipSvc` | This service manages connected Xbox Accessories. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `xboxgip` | Xbox Game Input Protocol Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\xboxgip.sys |
| `XblAuthManager` | Provides authentication and authorization services for interacting with Xbox Live. If this service is stopped, some applications may not operate correctly. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `XblGameSave` | This service syncs save data for Xbox Live save enabled games. If this service is stopped, game save data will not upload to or download from Xbox Live. | Win32 Share Process (32) | UserManager, XblAuthManager | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `XboxNetApiSvc` | This service supports the Windows.Networking.XboxLive application programming interface. | Win32 Share Process (32) | BFE, mpssvc, IKEEXT, KeyIso | C:\Windows\system32\svchost.exe -k netsvcs -p |

### VBox

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `VBoxNetAdp` | VirtualBox NDIS 6.0 Host-Only Network Adapter Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxNetAdp6.sys |
| `VBoxNetLwf` | VirtualBox NDIS 6.0 Lightweight Filter Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxNetLwf.sys |
| `VBoxSup` | VirtualBox Support Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxSup.sys |
| `VBoxUSBMon` | VirtualBox USB Monitor Driver | Kernel Driver (1) | - | \SystemRoot\system32\DRIVERS\VBoxUSBMon.sys |
| `VBoxSDS` | Used as a COM server for VirtualBox API. VirtualBox Global Interface. | Win32 Own Process (16) | RPCSS | "C:\Program Files\Oracle\VirtualBox\VBoxSDS.exe" |

### VPN/RAS Services

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RemoteAccess` | Offers routing services to businesses in local area and wide area network environments. | Win32 Share Process (32) | RpcSS, Bfe, RasMan, Http | C:\Windows\System32\svchost.exe -k netsvcs |
| `wanarp` | Remote Access IP ARP Driver | Kernel Driver (1) | - | System32\DRIVERS\wanarp.sys |
| `wanarpv6` | Remote Access IPv6 ARP Driver | Kernel Driver (1) | - | System32\DRIVERS\wanarp.sys |
| `RasMan` | Manages dial-up and virtual private network (VPN) connections from this computer to the Internet or other remote networks. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | SstpSvc, DnsCache | C:\Windows\System32\svchost.exe -k netsvcs |
| `RasAuto` | Creates a connection to a remote network whenever a program references a remote DNS or NetBIOS name or address. | Win32 Share Process (32) | RasAcd | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `PptpMiniport` | WAN Miniport (PPTP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\raspptp.sys |
| `RasAgileVpn` | WAN Miniport (IKEv2) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\AgileVpn.sys |
| `Rasl2tp` | WAN Miniport (L2TP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rasl2tp.sys |
| `RasSstp` | WAN Miniport (SSTP) | Kernel Driver (1) | - | \SystemRoot\System32\drivers\rassstp.sys |
| `SstpSvc` | Provides support for the Secure Socket Tunneling Protocol (SSTP) to connect to remote computers using VPN. If this service is disabled, users will not be able to use SSTP to access remote servers. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalService -p |
| `RasAcd` | Remote Access Auto Connection Driver | Kernel Driver (1) | - | System32\DRIVERS\rasacd.sys |

### Media Sharing / Portable Devices

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WMPNetworkSvc` | Shares Windows Media Player libraries to other networked players and media devices using Universal Plug and Play | - | - | - |
| `WPDBusEnum` | Enforces group policy for removable mass-storage devices. Enables applications such as Windows Media Player and Image Import Wizard to transfer and synchronize content using removable mass-storage devices. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted |

### BranchCache

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `PeerDistSvc` | This service caches network content from peers on the local subnet. | Win32 Share Process (32) | http | C:\Windows\System32\svchost.exe -k PeerDist |

### QoS/AV Streaming (qWave)

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `QWAVE` | Quality Windows Audio Video Experience (qWave) is a networking platform for Audio Video (AV) streaming applications on IP home networks. qWave enhances AV streaming performance and reliability by ensuring network quality-of-service (QoS) for AV applications. It provides mechanisms for admission control, run time monitoring and enforcement, application feedback, and traffic prioritization. | Win32 Share Process (32) | rpcss, psched, QWAVEdrv, LLTDIO | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `QWAVEdrv` | Quality Windows Audio/Video Experience component driver | Kernel Driver (1) | - | \SystemRoot\system32\drivers\qwavedrv.sys |

### NFC/Payments

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SEMgrSvc` | Manages payments and Near Field Communication (NFC) based secure elements. | Win32 Own Process (16) | RpcSs | C:\Windows\system32\svchost.exe -k LocalService -p |

### Optimize Drives

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `defragsvc` | Helps the computer run more efficiently by optimizing files on storage drives. | Win32 Own Process (16) | RPCSS | C:\Windows\system32\svchost.exe -k defragsvc |

### Mobile Hotspot / ICS Service

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `icssvc` | Provides the ability to share a cellular data connection with another device. | Win32 Share Process (32) | RpcSs, wcmsvc | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `ALG` | Provides support for 3rd party protocol plug-ins for Internet Connection Sharing | Win32 Own Process (16) | - | C:\Windows\System32\alg.exe |
| `SharedAccess` | Provides network address translation, addressing, name resolution and/or intrusion prevention services for a home or small office network. | Win32 Share Process (32) | BFE | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Network Capture Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NdisCap` | Microsoft NDIS Capture | Kernel Driver (1) | - | System32\drivers\ndiscap.sys |

### Container File System Drivers

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `CimFS` | - | File System Driver (2) | - | \??\C:\Program Files (x86)\Windows Kits\10\Assessment and Deployment Kit\Deployment Tools\AMD64\DISM\cimfs.sys |
| `wcifs` | Provides a virtual filesystem view for processes running within Windows Containers | File System Driver (2) | FltMgr | \SystemRoot\system32\drivers\wcifs.sys |

### Consumer IR Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `circlass` | Consumer IR Class Driver for eHome | Kernel Driver (1) | - | \SystemRoot\System32\drivers\circlass.sys |

### iSCSI Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `msisadrv` | Disabling breaks laptop keyboards. | Kernel Driver (1) | - | System32\drivers\msisadrv.sys |

### NetBIOS Driver

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NetBIOS` | NetBIOS Interface | File System Driver (2) | - | system32\drivers\netbios.sys |
| `NetBT` | This service implements NetBios over TCP/IP. | Kernel Driver (1) | Tdx, tcpip | System32\DRIVERS\netbt.sys |

### Epic Games

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `EpicGamesUpdater` | - | - | - | - |
| `EpicOnlineServices` | - | - | - | - |

### Logitech

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `LGHUBUpdaterService` | LGHUB Updater Service | Win32 Own Process (16) | - | "C:\Program Files\LGHUB\lghub_updater.exe" --run-as-service |
| `logi_joy_bus_enum` | Logitech G HUB Virtual Bus Enumerator Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\logi_joy_bus_enum.x64.sys |
| `logi_joy_vir_hid` | Logitech G HUB Virtual HID Device Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\logi_joy_vir_hid.x64.sys |
| `logi_lamparray_service` | Provides HID LampArray Lighting support to Logitech devices. | Win32 Own Process (16) | logi_lamparray | C:\Windows\System32\DriverStore\FileRepository\logi_lamparray_usb.inf_amd64_dc165490f32791ad\logi_lamparray_service.AMD64.exe |

### SteelSeries

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SteelSeries_Sonar_VAD` | SteelSeries Sonar Driver | Kernel Driver (1) | - | \SystemRoot\System32\DriverStore\FileRepository\steelseries-sonar-vad.inf_amd64_036e27f3054ae1bc\SteelSeries-Sonar-VAD.sys |
| `SteelSeriesGGUpdateServiceProxy` | Launches the SteelSeries Update Service. | Win32 Own Process (16) | - | "C:\Program Files\SteelSeries\GG\updateService\SteelSeriesGGUpdateServiceProxy.exe" |
| `ssdevfactory` | SteelSeries Device Factory Service | Kernel Driver (1) | - | \SystemRoot\System32\drivers\ssdevfactory.sys |

### NVIDIA Container

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NVDisplay.ContainerLocalSystem` | Container service for NVIDIA root features, required for NVCPL to work. | Win32 Own Process (16) | - | C:\Windows\System32\DriverStore\FileRepository\nv_dispi.inf_amd64_c8bc842500fab35b\Display.NvContainer\NVDisplay.Container.exe -arg <ExeDir>\arguments.txt |

### Everything

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `Everything (1.5a)` | Provides NTFS indexing, ReFS indexing and USN Journal services to the Everything search client. | Win32 Own Process (16) | - | "C:\Program Files\Everything 1.5a\Everything.exe" -svc |
| `Everything` | ^ | - | - | - |

### App Deployment

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `AppMgmt` | Processes installation, removal, and enumeration requests for software deployed through Group Policy. If the service is disabled, users will be unable to install, remove, or enumerate software deployed through Group Policy. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `AxInstSV` | Provides User Account Control validation for the installation of ActiveX controls from the Internet and enables management of ActiveX control installation based on Group Policy settings. This service is started on demand and if disabled the installation of ActiveX controls will behave according to default browser settings. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k AxInstSVGroup |
| `BITS` | Transfers files in the background using idle network bandwidth. If the service is disabled, then any applications that depend on BITS, such as Windows Update or MSN Explorer, will be unable to automatically download programs and other information. | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k netsvcs -p |
| `EntAppSvc` | Enables enterprise application management. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k appmodel -p |

### Network Authentication

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `dot3svc` | The Wired AutoConfig (DOT3SVC) service is responsible for performing IEEE 802.1X authentication on Ethernet interfaces. If your current wired network deployment enforces 802.1X authentication, the DOT3SVC service should be configured to run for establishing Layer 2 connectivity and/or providing access to network resources. Wired networks that do not enforce 802.1X authentication are unaffected by the DOT3SVC service. | Win32 Share Process (32) | RpcSs, Ndisuio, Eaphost | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `EapHost` | The Extensible Authentication Protocol (EAP) service provides network authentication in such scenarios as 802.1x wired and wireless, VPN, and Network Access Protection (NAP). EAP also provides application programming interfaces (APIs) that are used by network access clients, including wireless and VPN clients, during the authentication process. If you disable this service, this computer is prevented from accessing networks that require EAP authentication. | Win32 Share Process (32) | RPCSS, KeyIso | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Network Profile & Connectivity UX

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `NcaSvc` | Provides DirectAccess status notification for UI components | Win32 Share Process (32) | BFE, dnscache, NSI, iphlpsvc | C:\Windows\System32\svchost.exe -k NetSvcs -p |
| `NlaSvc` | Collects and stores configuration information for the network and notifies programs when this information is modified. If this service is stopped, configuration information might be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k netprofm -p |
| `Wcmsvc` | Makes automatic connect and disconnect decisions based on the network connectivity options currently available to the PC and enables management of network connectivity based on Group Policy settings. | Win32 Own Process (16) | RpcSs, NSI | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

### Enterprise Transaction & Storage

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `MSDTC` | Coordinates transactions that span multiple resource managers, such as databases, message queues, and file systems. If this service is stopped, these transactions will fail. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | RPCSS, SamSS | C:\Windows\System32\msdtc.exe |
| `MSiSCSI` | Manages Internet SCSI (iSCSI) sessions from this computer to remote iSCSI target devices. If this service is stopped, this computer will not be able to login or access iSCSI targets. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `smphost` | Host service for the Microsoft Storage Spaces management provider. If this service is stopped or disabled, Storage Spaces cannot be managed. | Win32 Own Process (16) | RPCSS | C:\Windows\System32\svchost.exe -k smphost |

### Management / Encryption Broker

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SNMPTRAP` | Receives trap messages generated by local or remote Simple Network Management Protocol (SNMP) agents and forwards the messages to SNMP management programs running on this computer. If this service is stopped, SNMP-based programs on this computer will not receive SNMP trap messages. If this service is disabled, any services that explicitly depend on it will fail to start. | Win32 Own Process (16) | - | C:\Windows\System32\snmptrap.exe |
| `WEPHOSTSVC` | Windows Encryption Provider Host Service brokers encryption related functionalities from 3rd Party Encryption Providers to processes that need to evaluate and apply EAS policies. Stopping this will compromise EAS compliancy checks that have been established by the connected Mail Accounts | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k WepHostSvcGroup |

### Demo / Shared Device

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `RetailDemo` | The Retail Demo service controls device activity while the device is in retail demo mode. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k rdxgroup |
| `shpamsvc` | Manages profiles and accounts on a SharedPC configured device | Win32 Share Process (32) | RpcSs, ProfSvc | C:\Windows\System32\svchost.exe -k netsvcs -p |

### Graphics Compatibility

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WarpJITSvc` | Enables JIT compilation support in d3d10warp.dll for processes in which code generation is disabled. | Win32 Own Process (16) | - | C:\Windows\System32\svchost.exe -k LocalServiceNetworkRestricted |

### Mobile Broadband

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `wlpasvc` | This service provides profile management for subscriber identity modules | Win32 Share Process (32) | WwanSvc, RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `WwanSvc` | This service manages mobile broadband (GSM & CDMA) data card/embedded module adapters and connections by auto-configuring the networks. It is strongly recommended that this service be kept running for best user experience of mobile broadband devices. | Win32 Share Process (32) | RpcSs, NdisUio | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

### Miscellaneous

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `WalletService` | Hosts objects used by clients of the wallet | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k appmodel -p |
| `PenService` | Part of Windows Ink Services Platform Tablet Input Subsystem and is used to implement Microsoft Tablet PC functionality. | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k PenService |
| `buttonconverter` | Service for Portable Device Control devices | Kernel Driver (1) | - | \SystemRoot\System32\drivers\buttonconverter.sys |
| `SmsRouter` | Routes messages based on rules to appropriate clients. | Win32 Share Process (32) | RpcSs | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |

## [Windows Internals](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/services1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/services4.png?raw=true)

# Disable Scheduled Tasks

This list was created using my small [`ScheduledTasksList.ps1`](https://github.com/nohuto/win-config/blob/main/system/assets/ScheduledTasksList.ps1) parser which displays name, path, description, principals, settings, triggers, actions if given.

## Scheduled Tasks Table

### CEIP

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Autochk\Proxy` | This task collects and uploads autochk SQM data if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\rundll32.exe /d acproxy.dll,PerformAutochkOperations` |
| `\Microsoft\Windows\Customer Experience Improvement Program\UsbCeip` | The USB CEIP (Customer Experience Improvement Program) task collects Universal Serial Bus related statistics and information about your machine and sends it to the Windows Device Connectivity engineering group at Microsoft.  The information received is used to help improve the reliability, stability, and overall functionality of USB in Windows.  If the user has not consented to participate in Windows CEIP, this task does not do anything. | `ClassId:{C27F6B1D-FE0B-45E4-9257-38799FA69BC8}` |
| `\Microsoft\Windows\Customer Experience Improvement Program\Consolidator` | If the user has consented to participate in the Windows Customer Experience Improvement Program, this job collects and sends usage data to Microsoft. | `%WINDIR%\System32\wsqmcons.exe` |
| `\Microsoft\Windows\Customer Experience Improvement Program\Uploader` | - | - |
| `\Microsoft\Windows\Customer Experience Improvement Program\Server\ServerCeipAssistant` | - | - |
| `\Microsoft\Windows\Customer Experience Improvement Program\Server\ServerRoleUsageCollector` | - | - |

### Error Reporting

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\ErrorDetails\EnableErrorDetailsUpdate` | - | - |
| `\Microsoft\Windows\Windows Error Reporting\QueueReporting` | Windows Error Reporting task to process queued reports. | `%windir%\system32\wermgr.exe -upload` |

### Offline Files

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Offline Files\Background Synchronization` | This task controls periodic background synchronization of Offline Files when the user is working in an offline mode. | `ClassId:{FA3F3DD9-4C1A-456B-A8FA-C76EF3ED83B8}` |
| `\Microsoft\Windows\Offline Files\Logon Synchronization` | This task initiates synchronization of Offline Files when a user logs onto the system. | `ClassId:{FA3F3DD9-4C1A-456B-A8FA-C76EF3ED83B8}` |

### Printing

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Printing\PrintJobCleanupTask` | - | `ClassId:{8ABCE260-32B6-476C-AE13-B34D0C91292D}` |
| `\Microsoft\Windows\Printing\PrinterCleanupTask` | - | `ClassId:{C56F065E-DE49-4E42-BE7C-305C45609D25}` |
| `\Microsoft\Windows\Printing\EduPrintProv` | - | `%windir%\system32\eduprintprov.exe` |

### Wi-Fi Service

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\WCM\WiFiTask` | Background task for performing per user and web interactions | `%WINDIR%\System32\WiFiTask.exe` |
| `\Microsoft\Windows\WlanSvc\CDSSync` | - | `ClassId:{B0D2B535-12E1-439F-86B3-BADA289510F0}` |
| `\Microsoft\Windows\WwanSvc\NotificationTask` | Background task for performing per user and web interactions | `%WINDIR%\System32\WiFiTask.exe wwan` |
| `\Microsoft\Windows\WwanSvc\OobeDiscovery` | - | `ClassId:{C93CF9D5-031B-4AAA-AB0B-EF802347B381}` |
| `\Microsoft\Windows\WlanSvc\MoProfileManagement` | - | `ClassId:{085EDA12-CF4A-4944-8222-8ADCADE137CB}` |

### Office Telemetry

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Office\OfficeTelemetryAgentFallBack` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentFallBack2016` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentLogOn` | - | - |
| `\Microsoft\Office\OfficeTelemetryAgentLogOn2016` | - | - |

### NVIDIA Telemetry

| Task | Description | Action Command |
| --- | --- | --- |
| `NvTmRep_*` | Sends data at 12:25PM daily | - |
| `NvTmRepOnLogon*` | Sends data on logon | - |
| `NvTmMon_*` | Sends data on logon, then in a 1H interval | - |

### Feedback

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Feedback\Siuf\DmClient` | Update SIUF strings | `%windir%\system32\dmclient.exe` |
| `\Microsoft\Windows\Feedback\Siuf\DmClientOnScenarioDownload` | Update SIUF strings | `%windir%\system32\dmclient.exe utcwnf` |

### Application Experience

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Application Experience\MareBackup` | Gathers Win32 application data for App Backup scenario | `%windir%\system32\compattelrunner.exe -m:aeinv.dll -f:UpdateSoftwareInventoryW invsvc ; %windir%\system32\compattelrunner.exe -m:appraiser.dll -f:DoScheduledTelemetryRun ; %windir%\system32\compattelrunner.exe -m:aemarebackup.dll -f:BackupMareData` |
| `\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser` | Collects program telemetry information if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\sc.exe start InventorySvc` |
| `\Microsoft\Windows\Application Experience\Microsoft Compatibility Appraiser Exp` | Collects program telemetry information if opted-in to the Microsoft Customer Experience Improvement Program. | `%windir%\system32\compattelrunner.exe -m:appraiser.dll -f:DoScheduledTelemetryRun express` |
| `\Microsoft\Windows\Application Experience\PcaPatchDbTask` | Updates compatibility database | `%windir%\system32\rundll32.exe %windir%\system32\PcaSvc.dll,PcaPatchSdbTask` |
| `\Microsoft\Windows\Application Experience\SdbinstMergeDbTask` | Merges shim databases that are pending merge. | `%windir%\system32\sdbinst.exe -mm` |
| `\Microsoft\Windows\Application Experience\StartupAppTask` | Scans startup entries and raises notification to the user if there are too many startup entries. | `%windir%\system32\rundll32.exe Startupscan.dll,SusRunTask` |

### Maintenance

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\ApplicationData\DsSvcCleanup` | Performs maintenance for the Data Sharing Service. | `%windir%\system32\dstokenclean.exe` |
| `\Microsoft\Windows\CloudExperienceHost\CreateObjectTask` | - | `ClassId:{E4544ABA-62BF-4C54-AAB2-EC246342626C}` |
| `\Microsoft\Windows\Defrag\ScheduledDefrag` | This task optimizes local storage drives. | `%windir%\system32\defrag.exe -c -h -o -$` |
| `\Microsoft\Windows\Diagnosis\RecommendedTroubleshootingScanner` | Check for recommended troubleshooting from Microsoft | `ClassId:{AD08DCC2-4E35-4486-9D49-547CBD30942D}` |
| `\Microsoft\Windows\Diagnosis\Scheduled` | The Windows Scheduled Maintenance Task performs periodic maintenance of the computer system by fixing problems automatically or reporting them through Security and Maintenance. | `ClassId:{C1F85EF8-BCC2-4606-BB39-70C523715EB3}` |
| `\Microsoft\Windows\Diagnosis\UnexpectedCodePath` | - | - |
| `\Microsoft\Windows\DiskCleanup\SilentCleanup` | Maintenance task used by the system to launch a silent auto disk cleanup when running low on free disk space. | `%windir%\system32\cleanmgr.exe /autocleanstoragesense /d %systemdrive%` |
| `\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticDataCollector` | The Windows Disk Diagnostic reports general disk and system information to Microsoft for users participating in the Customer Experience Program. | `%windir%\system32\rundll32.exe dfdts.dll,DfdGetDefaultPolicyAndSMART` |
| `\Microsoft\Windows\DiskDiagnostic\Microsoft-Windows-DiskDiagnosticResolver` | The Microsoft-Windows-DiskDiagnosticResolver warns users about faults reported by hard disks that support the Self Monitoring and Reporting Technology (S.M.A.R.T.) standard. This task is triggered automatically by the Diagnostic Policy Service when a S.M.A.R.T. fault is detected. | `%windir%\system32\DFDWiz.exe` |
| `\Microsoft\Windows\DiskFootprint\Diagnostics` | - | `%windir%\system32\disksnapshot.exe -z` |
| `\Microsoft\Windows\DiskFootprint\StorageSense` | - | `ClassId:{AB2A519B-03B0-43CE-940A-A73DF850B49A}` |
| `\Microsoft\Windows\Speech\SpeechModelDownloadTask` | - | `%windir%\system32\speech_onecore\common\SpeechModelDownload.exe` |
| `\Microsoft\Windows\UNP\RunUpdateNotificationMgr` | - | - |
| `\Microsoft\Windows\BrokerInfrastructure\BgTaskRegistrationMaintenanceTask` | Maintains registrations for background tasks for Universal Windows Platform applications. | `ClassId:{E984D939-0E00-4DD9-AC3A-7ACA04745521}` |
| `\Microsoft\Windows\capabilityaccessmanager\maintenancetasks` | Capability Access Manager Maintenance Tasks | `%windir%\system32\rundll32.exe %windir%\system32\CapabilityAccessManager.dll,CapabilityAccessManagerDoStoreMaintenance` |

### Census

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Device Information\Device User` | - | `%windir%\system32\devicecensus.exe UserCxt` |
| `\Microsoft\Windows\Device Information\Device` | - | `%windir%\system32\devicecensus.exe SystemCxt` |

### Update Service

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\InstallService\ScanForUpdates` | - | `ClassId:{A558C6A5-B42B-4C98-B610-BF9559143139}` |
| `\Microsoft\Windows\InstallService\ScanForUpdatesAsUser` | - | `ClassId:{DDAFAEA2-8842-4E96-BADE-D44A8D676FDB}` |
| `\Microsoft\Windows\InstallService\SmartRetry` | - | `ClassId:{F3A219C3-2698-4CBF-9C07-037EDB8E72E6}` |
| `\Microsoft\Windows\InstallService\WakeUpAndContinueUpdates` | - | `ClassId:{0DC331EE-8438-49D5-A721-E10B937CE459}` |
| `\Microsoft\Windows\InstallService\WakeUpAndScanForUpdates` | - | `ClassId:{D5A04D91-6FE6-4FE4-A98A-FEB4500C5AF7}` |

### Localization

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\International\Synchronize Language Settings` | Synchronize User Language Settings from other devices. | `ClassId:{10D62541-90D0-42FE-848C-0DBC1AC42EDA}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\Installation` | Install language components that match the user's language list. | `ClassId:{6F58F65F-EC0E-4ACA-99FE-FC5A1A25E4BE}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\ReconcileLanguageResources` | Install language components that match the user's language list. | `ClassId:{D0582E3B-3126-4CAA-9155-AC37C912A489}` |
| `\Microsoft\Windows\LanguageComponentsInstaller\Uninstallation` | Uninstall language components that are not in any user's language list. | `ClassId:{6F58F65F-EC0E-4ACA-99FE-FC5A1A25E4BE}` |

### Maps

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Maps\MapsUpdateTask` | This task checks for updates to maps which you have downloaded for offline use. Disabling this task will prevent Windows from notifying you of updated maps. | `ClassId:{B9033E87-33CF-4D77-BC9B-895AFBBA72E4}` |
| `\Microsoft\Windows\Maps\MapsToastTask` | This task shows various Map related toasts | `ClassId:{9885AEF2-BD9F-41E0-B15E-B3141395E803}` |

### Sleep Study

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Power Efficiency Diagnostics\AnalyzeSystem` | This task analyzes the system looking for conditions that may cause high energy use. | `ClassId:{927EA2AF-1C54-43D5-825E-0074CE028EEE}` |

### Time Sync

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Time Synchronization\ForceSynchronizeTime` | This task performs time synchronization. | `ClassId:{A31AD6C2-FF4C-43D4-8E90-7101023096F9}` |
| `\Microsoft\Windows\Time Synchronization\SynchronizeTime` | Maintains date and time synchronization on all clients and servers in the network. If this service is stopped, date and time synchronization will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. | `%windir%\system32\sc.exe start w32time task_started` |

### Miscellaneous

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Registry\RegIdleBackup` | Registry Idle Backup Task | `ClassId:{CA767AA8-9157-4604-B64B-40747123D5F2}` |
| `\Microsoft\Windows\RetailDemo\CleanupOfflineContent` | Auto cleanup RetailDemo Offline content | `ClassId:{61F77D5E-AFE9-400B-A5E6-E9E80FC8E601}` |

### WU

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\UpdateOrchestrator\Report policies` | - | `%WINDIR%\system32\usoclient.exe ReportPolicies` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Maintenance Work` | - | `%WINDIR%\system32\usoclient.exe StartMaintenanceWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Scan` | - | `%WINDIR%\system32\usoclient.exe StartScan` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Scan Static Task` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartScan` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Wake To Work` | - | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Schedule Work` | - | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\Start Oobe Expedite Work` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartWork` |
| `\Microsoft\Windows\UpdateOrchestrator\StartOobeAppsScan_LicenseAccepted` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartOobeAppsScan` |
| `\Microsoft\Windows\UpdateOrchestrator\StartOobeAppsScanAfterUpdate` | This task performs a scheduled Windows Update scan. | `%WINDIR%\system32\usoclient.exe StartOobeAppsScanAfterUpdate` |
| `\Microsoft\Windows\UpdateOrchestrator\USO_UxBroker` | This task triggers a system reboot following update installation. | `%WINDIR%\system32\MusNotification.exe` |
| `\Microsoft\Windows\UpdateOrchestrator\UUS Failover Task` | - | `%windir%\System32\MLEngineStub.exe HandleUusFailoverEvaluationSignalFromWnf` |
| `\Microsoft\Windows\WindowsUpdate\Scheduled Start` | This task is used to start the Windows Update service when needed to perform scheduled operations such as scans. | `%WINDIR%\System32\sc.exe start wuauserv` |
| `\Microsoft\Windows\WindowsUpdate\Refresh Group Policy Cache` | This task is used to refresh group policy cache in Windows Update | `ClassId:{07369A67-07A6-4608-ABEA-379491CB7C46}` |

### BitLocker

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\BitLocker\BitLocker Encrypt All Drives` | - | `ClassId:{61BCD1B9-340C-40EC-9D41-D7F1C0632F05}` |
| `\Microsoft\Windows\BitLocker\BitLocker MDM Policy Refresh` | - | - |

### Microsoft Account

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\AccountHealth\RecoverabilityToastTask` | AccountHealth Task Handler evaluates the state of a Microsoft Account and takes any necessary repair action | `ClassId:{B7F5B442-EBF8-46CD-9F0B-D8E45ED43492}` |

### Chkdsk

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Chkdsk\ProactiveScan` | NTFS Volume Health Scan | `ClassId:{CF4270F5-2E43-4468-83B3-A8C45BB33EA1}` |
| `\Microsoft\Windows\Chkdsk\SyspartRepair` | - | `%windir%\system32\bcdboot.exe %windir% /sysrepair` |

### OneSettings

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Flighting\OneSettings\RefreshCache` | Task periodically refreshing data for OneSettings clients. | `ClassId:{E07647F7-AED2-48D9-9720-939BC24A8A3C}` |

### Location Notification

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Location\WindowsActionDialog` | Location Notification | `%windir%\System32\WindowsActionDialog.exe` |

### Memory Diagnostic

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\MemoryDiagnostic\AutomaticOfflineMemoryDiagnostic` | Schedules an offline memory diagnostic in response to system events. | `ClassId:{44F6C389-604A-4363-B09A-F38DA08E6079}` |
| `\Microsoft\Windows\MemoryDiagnostic\ProcessMemoryDiagnosticEvents` | Schedules a memory diagnostic in response to system events. | `ClassId:{8168E74A-B39F-46D8-ADCD-7BED477B80A3}` |
| `\Microsoft\Windows\MemoryDiagnostic\RunFullMemoryDiagnostic` | Detects and mitigates problems in physical memory (RAM). | `ClassId:{8168E74A-B39F-46D8-ADCD-7BED477B80A3}` |

### Remote Assistance

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\RemoteAssistance\RemoteAssistanceTask` | Checks group policy for changes relevant to Remote Assistance | `%windir%\system32\RAServer.exe /offerraupdate` |

### SR

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\SystemRestore\SR` | This task creates regular system protection points. | `%windir%\system32\srtasks.exe ExecuteScheduledSPPCreation` |

### Windows Defender

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Windows Defender\Windows Defender Cache Maintenance` | Periodic maintenance task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdCacheMaintenance` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Cleanup` | Periodic cleanup task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdCleanup` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Scheduled Scan` | Periodic scan task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe Scan -ScheduleJob -ScanTrigger 55 -IdleScheduledJob` |
| `\Microsoft\Windows\Windows Defender\Windows Defender Verification` | Periodic verification task. | `C:\ProgramData\Microsoft\Windows Defender\Platform\4.18.25110.6-0\MpCmdRun.exe -IdleTask -TaskName WdVerification` |

### AI

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\WindowsAI\Recall\InitialConfiguration` | - | `ClassId:{709FD5EF-7296-4154-BD3A-E9830FCFA60A}` |
| `\Microsoft\Windows\WindowsAI\Recall\PolicyConfiguration` | - | `ClassId:{0BE6820D-B667-4CB6-931B-C153A77DA895}` |
| `\Microsoft\Windows\WindowsAI\Settings\InitialConfiguration` | - | `ClassId:{2886E5FB-4F01-4A89-9A0E-5D6A9C8048AC}` |

### Work Folders

| Task | Description | Action Command |
| --- | --- | --- |
| `\Microsoft\Windows\Work Folders\Work Folders Logon Synchronization` | This task initiates synchronization of Work Folders partnerships when a user logs onto the system. | `ClassId:{97D47D56-3777-49FB-8E8F-90D7E30E1A1E}` |
| `\Microsoft\Windows\Work Folders\Work Folders Maintenance Work` | This task initiates maintenance work required for on-going good performance of data synchronization of Work Folders partnerships. | `ClassId:{63260BCE-A3FB-4A34-AA51-D4D8E877B62B}` |

# BCD Edits

BCDEdit is the CL editor for the *Boot Configuration Database* (BCD), a registry hive under `HKLM\BCD00000000` backed by a hidden BCD file (UEFI: `\EFI\Microsoft\Boot\BCD`). The BCD replaced `boot.ini` (before Windows Vista) and stores per installation boot configuration. Each entry is a BCD object (GUID) under `Objects`, and each object has `Elements` subkeys with numeric element IDs. The `Element` value is the data that maps to a readable BCDEdit option or boot parameter. BCDEdit exposes symbolic names for objects/elements and can edit online or offline stores (`/store`), and the same data can be modified by loading the BCD hive (including remote hives).

BCDEdit is primarily used for boot troubleshooting, recovery, debugging, and security/boot behavior changes. Some may not be used on latest Windows versions anymore (e.g. HalpTscSyncPolicy, see pseudocode below).

## Registry Values

### Key & Value Structure

As kind of everything else, BCD edits are also stored in the registry:
```c
HKLM\BCD00000000\Objects

// Structure
HKLM\BCD00000000\Objects\{GUID} // {GUID} depends on the object, e.g. {bootmgr}, {current}, {globalsettings}
HKLM\BCD00000000\Objects\{GUID}\Elements\XXXXXXXX // XXXXXXXX is a specific setting for the object (8 digit)
HKLM\BCD00000000\Objects\{GUID}\Elements\XXXXXXXX : Element // (REG_BINARY/REG_MULTI_SZ/REG_SZ - depends on the setting) this value includes the state of the setting
```

See all object identifiers via `bcdedit /enum all /v` (`identifier`). Note that the list below uses `{bootmgr}`, `{current}` etc. which must be replaced by the actual GUID (see block above).

### Value/Data List

Here are elements which I tracked via Procmon (taken from default store and the MS documentation - [bcd-settings-and-bitlocker](https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/bcd-settings-and-bitlocker), [bcd-enumerations](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/bcd/bcd-enumerations)).

Note that this doesn't show default states, instead it shows several options and their possible states. And obviously the descriptions are most likely parsed, means that even "useless" descriptions will be included whenever the mentioned MS docs above include them.

- `{badmemory}` = RAM Defects
- `{bootloadersettings}` = Boot Loader Settings
- `{bootmgr}` = Windows Boot Manager
- `{current}` = Windows Boot Loader (current OS entry)
- `{dbgsettings}` = Debugger Settings
- `{emssettings}` = EMS Settings
- `{fwbootmgr}` = Firmware Boot Manager
- `{globalsettings}` = Global Settings
- `{hypervisorsettings}` = Hypervisor Settings
- `{memdiag}` = Windows Memory Diagnostic
- `{ramdiskoptions}` = Device Options for Ramdisk (boot.sdi)
- `{resume}` = Windows Resume Application (resumeobject)
- `{resumeloadersettings}` = Resume Loader Settings
- `{winre}` = Windows Recovery Environment Loader (recoverysequence)

#### Windows Boot Loader

```c
"HKLM\\BCD00000000\\Objects\\{current}\\Elements";
    "\\26000141"; "Element" = 01; // REG_BINARY, event = true, false = 00
    "\\26000116"; "Element" = 01; // REG_BINARY, hypervisorusevapic = true, false = 00
    "\\260000F8"; "Element" = 01; // REG_BINARY, hypervisordisableslat = true, false = 00
    "\\260000FC"; "Element" = 01; // REG_BINARY, hypervisoruselargevtlb = true, false = 00 - Increases virtual Translation Lookaside Buffer (TLB) size.
    "\\260000F2"; "Element" = 01; // REG_BINARY, hypervisordebug = true, false = 00 - Controls whether the hypervisor debugger is enabled.
    "\\260000E1"; "Element" = 00; // REG_BINARY, disableelamdrivers = false, true = 01 - The OS loader removes this entry for security reasons. This option can only be triggered by using the F8 menu.
    "\\260000C3"; "Element" = 01; // REG_BINARY, onetimeadvancedoptions = true, false = 00 - Controls whether the system boots to the legacy menu (F8 menu) on the next boot.
    "\\260000C4"; "Element" = 01; // REG_BINARY, onetimeoptionsedit = true, false = 00
    "\\260000B0"; "Element" = 01; // REG_BINARY, ems = true, false = 00 - Indicates whether EMS should be enabled in the kernel.
    "\\260000A5"; "Element" = 01; // REG_BINARY, disabledynamictick = true, false = 00 - https://noverse.dev/docs/win-config/system/timer-expiration/#kidynamictickdisablereason
    "\\260000A4"; "Element" = 01; // REG_BINARY, useplatformtick = true (forces platform clock source, often HPET), false = 00
    "\\260000A3"; "Element" = 01; // REG_BINARY, forcelegacyplatform = true, false = 00 - Forces the OS to assume the presence of legacy PC devices like CMOS and keyboard controllers.
    "\\260000A2"; "Element" = 01; // REG_BINARY, useplatformclock = true (forces the use of the platform clock as the system's performance counter), false = 00
    "\\260000A1"; "Element" = 01; // REG_BINARY, halbreakpoint = true, false = 00 - Indicates whether the HAL should call DbgBreakPoint at the start of HalInitSystem for phase 0 initialization of the kernel.
    "\\260000A0"; "Element" = 01; // REG_BINARY, debug = true, false = 00 - Indicates whether the kernel debugger should be enabled using the settings in the inherited debugger object.
    "\\26000091"; "Element" = 01; // REG_BINARY, sos = true, false = 00 - Indicates whether the system should display verbose information.
    "\\26000090"; "Element" = 01; // REG_BINARY, bootlog = true, false = 00 - Indicates whether the system should write logging information to %SystemRoot%\Ntbtlog.txt during initialization.
    "\\25000080"; "Element" = 0000000000000000; // REG_BINARY, safeboot = 0 (Minimal, SafeBoot\\Minimal), Network = 0100000000000000 (SafeBoot\\Network), DsRepair = 0200000000000000 (Directory Services Restore), Unset = not present
    "\\26000081"; "Element" = 01; // REG_BINARY, safebootalternateshell = true, false = 00 - Indicates whether the system should use the shell specified under the following registry key instead of the default shell: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SafeBoot\AlternateShell.
    "\\26000070"; "Element" = 01; // REG_BINARY, usefirmwarepcisettings = true, false = 00 - Indicates whether the system should use I/O and IRQ resources created by the system firmware instead of using dynamically configured resources.
    "\\26000065"; "Element" = 01; // REG_BINARY, groupaware = true, false = 00 - This setting makes drivers group aware and can be used to determine improper group usage.
    "\\26000064"; "Element" = 01; // REG_BINARY, maxgroup = true, false = 00 - Maximizes the number of groups created when assigning nodes to processor groups.
    "\\26000062"; "Element" = 01; // REG_BINARY, maxproc = true, false = 00 - Indicates whether the system should use the maximum number of processors.
    "\\26000060"; "Element" = 01; // REG_BINARY, onecpu = true, false = 00 - Indicates whether the operating system should initialize or start non-boot processors.
    "\\26000054"; "Element" = 01; // REG_BINARY, uselegacyapicmode = true (forces X2APICPOLICY=DISABLE), false = 00 (no-op) - Used to force legacy APIC mode, even if the processors and chipset support extended APIC mode.
    "\\26000051"; "Element" = 01; // REG_BINARY, usephysicaldestination = true, false = 00 - Indicates whether to enable physical-destination mode for all APIC messages.
    "\\26000043"; "Element" = 01; // REG_BINARY, novga = true, false = 00 - Disables the use of VGA modes in the OS.
    "\\26000042"; "Element" = 01; // REG_BINARY, novesa = true, false = 00 - Indicates whether the VGA driver should avoid VESA BIOS calls.
    "\\26000041"; "Element" = 01; // REG_BINARY, quietboot = true, false = 00 - Indicates whether the system should initialize the VGA driver responsible for displaying simple graphics during the boot process. If not, there is no display is presented during the boot process.
    "\\26000040"; "Element" = 01; // REG_BINARY, vga = true, false = 00 - Indicates whether the system should use the standard VGA display driver instead of a high-performance display driver.
    "\\26000030"; "Element" = 01; // REG_BINARY, nolowmem = true, false = 00 - Indicates whether the system should utilize the first 4GB of physical memory. This option requires 5GB of physical memory, and on x86 systems it requires PAE to be enabled.
    "\\26000027"; "Element" = 01; // REG_BINARY, allowprereleasesignatures = true, false = 00 - Indicates whether the test code signing certificate is supported.
    "\\26000025"; "Element" = 01; // REG_BINARY, lastknowngood = true, false = 00 - Indicates that the system should use the last-known good settings.
    "\\26000024"; "Element" = 01; // REG_BINARY, nocrashautoreboot = true, false = 00 - Indicates that the system should not automatically reboot when it crashes.
    "\\26000010"; "Element" = 01; // REG_BINARY, detectkernelandhal = true, false = 00 - Indicates whether the operating system loader should determine the kernel and HAL to load based on the platform features.
    "\\26000004"; "Element" = 01; // REG_BINARY, stampdisks = true, false = 00
    "\\25000142"; "Element" = 0100000000000000; // REG_BINARY, vsmlaunchtype = 1 (auto), Off = 0000000000000000
    "\\25000130"; "Element" = 0000000000000000; // REG_BINARY, claimedtpmcounter = 0
    "\\2500012B"; "Element" = 0100000000000000; // REG_BINARY, xsavedisable = 1, 0 = 0000000000000000 - When set to a value other than zero (0), disables XSAVE functionality in the kernel.
    "\\2500012A"; "Element" = 0000000000000000; // REG_BINARY, xsaveprocessorsmask = 0
    "\\25000129"; "Element" = 0000000000000000; // REG_BINARY, xsaveremovefeature = 0
    "\\25000128"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature7 = 0
    "\\25000127"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature6 = 0
    "\\25000126"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature5 = 0
    "\\25000125"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature4 = 0
    "\\25000124"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature3 = 0
    "\\25000123"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature2 = 0
    "\\25000122"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature1 = 0
    "\\25000121"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature0 = 0
    "\\25000120"; "Element" = 0000000000000000; // REG_BINARY, xsavepolicy = 0
    "\\25000115"; "Element" = 0100000000000000; // REG_BINARY, hypervisoriommupolicy = 1 (enable), Default = 0000000000000000, Disable = 0200000000000000 - Controls whether the hypervisor uses an Input Output Memory Management Unit (IOMMU).
    "\\25000113"; "Element" = 0200000000000000; // REG_BINARY, hypervisorrootproc = 2
    "\\25000100"; "Element" = 0200000000000000; // REG_BINARY, tpmbootentropy = 2 (forceenable), Default = 0000000000000000, ForceDisable = 0100000000000000 - Determines whether entropy is gathered from the trusted platform module (TPM) to help seed the random number generator in the OS.
    "\\250000FB"; "Element" = 0100000000000000; // REG_BINARY, hypervisorrootprocpernode = 1 - Specifies the total number of virtual processors in the root partition that can be started within a pre-split Non-Uniform Memory Architecture (NUMA) node.
    "\\250000FA"; "Element" = 0200000000000000; // REG_BINARY, hypervisornumproc = 2 - Specifies the total number of logical processors that can be started in the hypervisor.
    "\\250000F7"; "Element" = 0000000000000000; // REG_BINARY, bootuxpolicy = 0 (Disabled), Basic = 0100000000000000, Standard = 0200000000000000 (defunct) - Values are Disabled (0), Basic (1), and Standard (2).
    "\\250000F0"; "Element" = 0000000000000000; // REG_BINARY, hypervisorlaunchtype = 0 (Off), Auto = 0100000000000000 - Controls the hypervisor launch type. Options are HyperVisorLaunchOff (0) and HypervisorLaunchAuto (1).
    "\\250000E0"; "Element" = 0000000000000000; // REG_BINARY, bootstatuspolicy = 0 (displayallfailures), IgnoreAllFailures = 0100000000000000, IgnoreBootFailures = 0300000000000000, IgnoreCheckpointFailures = 0400000000000000, IgnoreShutdownFailures = 0200000000000000, DisplayBootFailures = 0600000000000000, DisplayCheckpointFailures = 0700000000000000, DisplayShutdownFailures = 0500000000000000
    "\\250000C2"; "Element" = 0000000000000000; // REG_BINARY, bootmenupolicy = 0 (Legacy), Standard = 0100000000000000 - Defines the type of boot menu the system will use. For Windows 10/11, Windows 8.1, Windows 8 and Windows RT the default is Standard. For Windows Server 2012 R2, Windows Server 2012, the default is Legacy. When Legacy is selected, the Advanced options menu (F8) is available. When Standard is selected, the boot menu appears but only under certain conditions: for example, if there is a startup failure, if you are booting up from a repair disk or installation media, if you have configured multiple boot entries, or if you manually configured the computer to use Advanced startup. When Standard is selected, the F8 key is ignored during boot. - Defines the type of boot menus the system will use. Possible values include menupolicylegacy (0) or menupolicystandard (1).
    "\\250000C1"; "Element" = 0000000000000000; // REG_BINARY, driverloadfailurepolicy = 0 (fatal), UseErrorControl = 0100000000000000 - Indicates the driver load failure policy. Zero (0) indicates that a failed driver load is fatal and the boot will not continue, one (1) indicates that the standard error control is used.
    "\\250000A6"; "Element" = 0100000000000000; // REG_BINARY, tscsyncpolicy = 1 (legacy), Default = 0000000000000000, Enhanced = 0200000000000000 (HalpTscSyncPolicy symbol not present means this doesn't do anything), this should exist on older Windows versions and controls the TSC synchronization policy
    "\\25000072"; "Element" = 0100000000000000; // REG_BINARY, pciexpress = 1 (forcedisable), Default = 0000000000000000
    "\\25000071"; "Element" = 0100000000000000; // REG_BINARY, msi = 1 (forcedisable), Default = 0000000000000000, ForceEnable only via loadoptions FORCEMSI - The PCI Message Signaled Interrupt (MSI) policy. Zero (0) indicates default, and one (1) indicates that MSI interrupts are disabled.
    "\\25000066"; "Element" = 4000000000000000; // REG_BINARY, groupsize = 64 - Specifies the size of all processor groups. Must be set to a power of 2 (max of 64, see pseudocode below).
    "\\25000063"; "Element" = 0100000000000000; // REG_BINARY, configflags = 1 - Indicates whether processor specific configuration flags are to be used.
    "\\25000061"; "Element" = 0200000000000000; // REG_BINARY, numproc = 2 - The maximum number of processors that can be utilized by the system, all other processors are ignored.
    "\\25000055"; "Element" = 0200000000000000; // REG_BINARY, x2apicpolicy = 2 (enable), Default = 0000000000000000, Disable = 0100000000000000 - Enables the use of extended APIC mode, if supported. Zero (0) indicates default behavior, one (1) indicates that extended APIC mode is disabled, and two (2) indicates that extended APIC mode is enabled. The system defaults to using extended APIC mode if available.
    "\\25000050"; "Element" = 0100000000000000; // REG_BINARY, clustermodeaddressing = 1 - Indicates that cluster-mode APIC addressing should be utilized, and the value is the maximum number of processors per cluster.
    "\\25000052"; "Element" = 0000000000000000; // REG_BINARY, restrictapicluster = 0 - The maximum number of APIC clusters that should be used by cluster-mode addressing.
    "\\25000032"; "Element" = 0004000000000000; // REG_BINARY, increaseuserva = 1024 - Increasing this value from the default 2GB decreases the amount of virtual address space available to the system and device drivers. The amount of memory that should be utilized by the process address space, in bytes. This value should be between 2GB and 3GB.
    "\\25000033"; "Element" = 0000000000000000; // REG_BINARY, perfmem = 0 - BcdOSLoaderInteger_PerformaceDataMemory (integer)
    "\\25000031"; "Element" = 8000000000000000; // REG_BINARY, removememory = 128 - The amount of memory the system should ignore.
    "\\25000021"; "Element" = 0100000000000000; // REG_BINARY, pae = 1 (forceenable), Default = 0000000000000000, ForceDisable = 0200000000000000 - If this value is not specified, the default is PaePolicyDefault which follows the rule "enable PAE if hot-pluggable memory is above 4GB"
    "\\25000020"; "Element" = 0000000000000000; // REG_BINARY, nx = 0 (OptIn, NX off by default), OptOut = 0100000000000000 (NX on by default), AlwaysOff = 0200000000000000, AlwaysOn = 0300000000000000 - If this value is not specified, the default is NxPolicyAlwaysOff.
    "\\23000003"; "Element" = {resume}; // REG_SZ, resumeobject = {resume} - The default boot environment application to load if the user does not select one.
    "\\22000053"; "Element" = \EFI\Microsoft\Boot\EVStore.dat; // REG_SZ, evstore = \EFI\Microsoft\Boot\EVStore.dat
    "\\22000041"; "Element" = recovery message; // REG_SZ, fverecoverymessage = recovery message
    "\\22000040"; "Element" = https://example.com/recovery; // REG_SZ, fverecoveryurl = https://example.com/recovery
    "\\22000013"; "Element" = kdcom.dll; // REG_SZ, dbgtransport = kdcom.dll - The transport DLL to be loaded by the operating system loader. This value overrides the default Kdcom.dll.
    "\\22000012"; "Element" = hal.dll; // REG_SZ, hal = hal.dll - The HAL to be loaded by the operating system loader. This value overrides the default HAL.
    "\\22000011"; "Element" = ntoskrnl.exe; // REG_SZ, kernel = ntoskrnl.exe - The kernel to be loaded by the operating system loader. This value overrides the default kernel.
    "\\22000002"; "Element" = \Windows; // REG_SZ, systemroot = \Windows - This value is reserved.
    "\\21000001"; "Element" = partition=C:; // REG_BINARY, filedevice = partition=C: - This value is reserved.
    "\\17000077"; "Element" = 7500001500000000; // REG_BINARY, allowedinmemorysettings = 0x15000075 - Indicates whether or not an in-memory BCD setting passed between boot apps will trigger BitLocker recovery. This value should not be modified as it could trigger a BitLocker recovery action.
    "\\1600007B"; "Element" = 01; // REG_BINARY, forcefipscrypto = true, false = 00 (BitLocker validation profile)
    "\\16000079"; "Element" = 01; // REG_BINARY, forcefipscrypto = true, false = 00 (BCD library enum, the one above is probably the used one) - Force the use of FIPS cryptography checks on boot applications.
    "\\16000074"; "Element" = 01; // REG_BINARY, bootshutdowndisabled = true, false = 00 - Disables the 1-minute timer that triggers shutdown on boot error screens, and the F8 menu, on UEFI systems.
    "\\16000072"; "Element" = 01; // REG_BINARY, nokeyboard = true, false = 00
    "\\1600006C"; "Element" = 01; // REG_BINARY, bootuxdisabled = true, false = 00 - This setting disables the progress bar and default Windows logo. If a custom text string has been defined, it is also disabled by this setting.
    "\\16000069"; "Element" = 01; // REG_BINARY, custom:16000069 = true, false = 00 - disables the loading circle while booting (see image at the bottom)
    "\\16000067"; "Element" = 01; // REG_BINARY, custom:16000067 = true, false = 00 - disables the Windows logo while booting (see image at the bottom)
    "\\16000060"; "Element" = 01; // REG_BINARY, isolatedcontext = true, false = 00 - Do not modify this setting. If this setting is removed from a Windows 8 installation, it will not boot. If this setting is added to a Windows 7 installation, it will not boot. - This setting is used to differentiate between the Windows 7 and Windows 8 implementations of UEFI.
    "\\16000054"; "Element" = 01; // REG_BINARY, highestmode = true, false = 00 - Forces highest available graphics resolution at boot. This value can only be used on UEFI systems.
    "\\16000053"; "Element" = 01; // REG_BINARY, restartonfailure = true, false = 00 - If enabled, specifies that boot error screens are not shown when OS launch errors occur, and the system is reset rather than exiting directly back to the firmware.
    "\\16000050"; "Element" = 01; // REG_BINARY, consoleextendedinput = true, false = 00 - Specifies that legacy BIOS systems should use INT 16h Function 10h for console input instead of INT 16h Function 0h.
    "\\16000049"; "Element" = 01; // REG_BINARY, testsigning = true, false = 00 - Indicates whether the test code signing certificate is supported.
    "\\16000048"; "Element" = 01; // REG_BINARY, nointegritychecks = true, false = 00 - This value is ignored by Windows 7 and Windows 8. - Disables integrity checks. Cannot be set when secure boot is enabled.
    "\\16000046"; "Element" = 01; // REG_BINARY, graphicsmodedisabled = true, false = 00 - Indicates whether graphics mode is disabled and boot applications must use text mode display.
    "\\16000041"; "Element" = 01; // REG_BINARY, optionsedit = true, false = 00 - Indicates whether the boot options editor is enabled.
    "\\16000040"; "Element" = 01; // REG_BINARY, advancedoptions = true, false = 00 - Indicates whether the advanced options boot menu (F8) is displayed.
    "\\1600001E"; "Element" = 01; // REG_BINARY, vm = true, false = 00
    "\\1600000F"; "Element" = 01; // REG_BINARY, traditionalkseg = true, false = 00
    "\\16000009"; "Element" = 01; // REG_BINARY, recoveryenabled = true, false = 00 - Indicates whether the recovery sequence executes automatically if the boot application fails. Otherwise, the recovery sequence only runs on demand.
    "\\15000081"; "Element" = 0000000000000000; // REG_BINARY, logcontrol = 0
    "\\15000088"; "Element" = 0000000000000000; // REG_BINARY, linearaddress57 = 0 (Default), OptOut = 0100000000000000, OptIn = 0200000000000000
    "\\15000066"; "Element" = 0300000000000000; // REG_BINARY, displaymessageoverride = 3 (Recovery), Resume = 0100000000000000
    "\\15000052"; "Element" = 0000000000000000; // REG_BINARY, graphicsresolution = 0 (1024x768), 800x600 = 0100000000000000, 1024x600 = 0200000000000000 - Forces a specific graphics resolution at boot. Possible values include GraphicsResolution1024x768 (0), GraphicsResolution800x600 (1), and GraphicsResolution1024x600 (2).
    "\\15000051"; "Element" = 0000000000000000; // REG_BINARY, initialconsoleinput = 0
    "\\1500004C"; "Element" = 0000000000000000; // REG_BINARY, volumebandid = 0 (fvebandid) - This value (if present) should not be modified.
    "\\1500004B"; "Element" = 0000000000000000; // REG_BINARY, integrityservices = 0 (Default, Enabled - Kernel Mode Code Signing), Enable = 0100000000000000, Disable = 0200000000000000
    "\\15000047"; "Element" = 0000000000000000; // REG_BINARY, configaccesspolicy = 0 (Default, allow MMCONFIG), DisallowMmConfig = 0100000000000000 (use CF8/CFC instead) - Indicates the access policy for PCI configuration space.
    "\\15000042"; "Element" = 0000000000000000; // REG_BINARY, keyringaddress = 0
    "\\1500000E"; "Element" = 0000000000000000; // REG_BINARY, avoidlowphysicalmemory = 0 - Specifies a minimum physical address to use in the boot environment.
    "\\1500000D"; "Element" = 0000000000000000; // REG_BINARY, relocatephysicalmemory = 0 - This value is not used in Windows 8 or Windows Server 2012. - Relocates physical memory on certain AMD processors.
    "\\1500000C"; "Element" = 0000000000000000; // REG_BINARY, firstmegabytepolicy = 0 (UseNone, use none of first MB), UseAll = 0100000000000000 (use all of first MB), UsePrivate = 0200000000000000 (reserved) - Indicates how the first megabyte of memory is to be used.
    "\\15000007"; "Element" = 0000008000000000; // REG_BINARY, truncatememory = 2147483648 - Maximum physical address a boot environment application should recognize. All memory above this address is ignored.
    "\\14000008"; "Element" = {winre}; // REG_MULTI_SZ, recoverysequence = {winre} - List of boot environment applications to be executed if the associated application fails. The applications are executed in the order they appear in this list.
    "\\14000006"; "Element" = {bootloadersettings}; // REG_MULTI_SZ, inherit = {bootloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\1200004A"; "Element" = \Windows\Fonts; // REG_SZ, fontpath = \Windows\Fonts - Use caution when modifying this setting. Boot screens will not work if the correct fonts are not present. - Overrides the default location of the boot fonts.
    "\\12000044"; "Element" = \Boot\BCD-Log; // REG_SZ, bsdlogpath = \Boot\BCD-Log - Allows a path override for the bootstat.dat log file in the boot manager and winload.exe.
    "\\12000030"; "Element" = NOCRASHONCTRL; // REG_SZ, loadoptions = NOCRASHONCTRL - String that is appended to the load options string passed to the kernel to be consumed by kernel-mode components. This is useful for communicating with kernel-mode components that are not BCD-aware.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows 11; // REG_SZ, description = Windows 11 - Display name of the boot environment application.
    "\\12000002"; "Element" = \Windows\system32\winload.efi; // REG_SZ, path = \Windows\system32\winload.efi - Path to a boot environment application.
    "\\11000043"; "Element" = partition=C:; // REG_BINARY, bsdlogdevice = partition=C: - Allows a device override for the bootstat.dat log in the boot manager and winload.exe.
    "\\11000001"; "Element" = partition=C:; // REG_BINARY, device = partition=C: - Device on which a boot environment application resides.
```

#### Windows Resume Application

```c
"HKLM\\BCD00000000\\Objects\\{resume}\\Elements";
    "\\26000006"; "Element" = 00; // REG_BINARY, debugoptionenabled = false, true = 01 - Enables kernel debugging on resume from hibernate.
    "\\26000004"; "Element" = 01; // REG_BINARY, pae = true, false = 00
    "\\26000003"; "Element" = 01; // REG_BINARY, usecustomsettings = true, false = 00 - Allows the resume loader BCD object to use custom settings. If this setting is not specified or is not enabled, default settings are applied by the OS before resume.
    "\\25000008"; "Element" = 0100000000000000; // REG_BINARY, bootmenupolicy = 1 (Standard), Legacy = 0000000000000000 - Defines the type of boot menus the system will use. Possible values are menupolicylegacy (0) or menupolicystandard (1). The default setting is menupolicylegacy (0).
    "\\25000007"; "Element" = 0000000000000000; // REG_BINARY, bootux = 0 (Disabled), Basic = 0100000000000000, Standard = 0200000000000000 (defunct)
    "\\22000002"; "Element" = \hiberfil.sys; // REG_SZ, filepath = \hiberfil.sys - This value is reserved.
    "\\21000026"; "Element" = partition=C:; // REG_BINARY, custom:21000026 = partition=C:
    "\\21000005"; "Element" = partition=C:; // REG_BINARY, associatedosdevice = partition=C: - Specifies the name of the OS device associated with the hibernated OS. This is only used if the hibernation file is not stored on the OS device.
    "\\21000001"; "Element" = partition=C:; // REG_BINARY, filedevice = partition=C: - This value is reserved.
    "\\17000077"; "Element" = 7500001500000000; // REG_BINARY, allowedinmemorysettings = 0x15000075 - Indicates whether or not an in-memory BCD setting passed between boot apps will trigger BitLocker recovery. This value should not be modified as it could trigger a BitLocker recovery action.
    "\\16000060"; "Element" = 01; // REG_BINARY, isolatedcontext = true, false = 00 - Do not modify this setting. If this setting is removed from a Windows 8 installation, it will not boot. If this setting is added to a Windows 7 installation, it will not boot. - This setting is used to differentiate between the Windows 7 and Windows 8 implementations of UEFI.
    "\\16000009"; "Element" = 01; // REG_BINARY, recoveryenabled = true, false = 00 - Indicates whether the recovery sequence executes automatically if the boot application fails. Otherwise, the recovery sequence only runs on demand.
    "\\14000008"; "Element" = {winre}; // REG_MULTI_SZ, recoverysequence = {winre} - List of boot environment applications to be executed if the associated application fails. The applications are executed in the order they appear in this list.
    "\\14000006"; "Element" = {resumeloadersettings}; // REG_MULTI_SZ, inherit = {resumeloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Resume Application; // REG_SZ, description = Windows Resume Application - Display name of the boot environment application.
    "\\12000002"; "Element" = \Windows\system32\winresume.efi; // REG_SZ, path = \Windows\system32\winresume.efi - Path to a boot environment application.
    "\\11000001"; "Element" = partition=C:; // REG_BINARY, device = partition=C: - Device on which a boot environment application resides.
```

#### Windows Boot Manager

```c
"HKLM\\BCD00000000\\Objects\\{bootmgr}\\Elements";
    "\\27000030"; "Element" = 0000000000000000; // REG_BINARY, customactionslist = <integer list> - For more information see Custom Bootstrap Actions in Windows Vista.
    "\\26000031"; "Element" = 01; // REG_BINARY, persistbootsequence = true, false = 00 - Controls whether a boot sequence persists across multiple boots.
    "\\26000028"; "Element" = 01; // REG_BINARY, processcustomactionsfirst = true, false = 00 - Controls whether custom actions are processed before a boot sequence.
    "\\26000021"; "Element" = 01; // REG_BINARY, noerrordisplay = true, false = 00 - Indicates whether the display of errors should be suppressed. If this setting is enabled, the boot manager exits to the multi-OS menu on OS launch error.
    "\\26000020"; "Element" = 01; // REG_BINARY, displaybootmenu = true, false = 00 - Forces the display of the legacy boot menu, regardless of the number of OS entries in the BCD store and their BcdOSLoaderInteger_BootMenuPolicy.
    "\\26000005"; "Element" = 01; // REG_BINARY, attemptresume = true, false = 00 - Indicates that a resume operation should be attempted during a system restart.
    "\\25000004"; "Element" = 0300000000000000; // REG_BINARY, timeout = 3 - The boot menu time-out determines how long the boot menu is displayed before the default boot entry is loaded. It is calibrated in seconds. If you want extra time to choose the operating system that loads on your computer, you can extend the time-out value. Or, you can shorten the time-out value so that the default operating system starts faster. - If this value is not specified, the boot manager waits for the user to make a selection. - The maximum number of seconds a boot selection menu is to be displayed to the user. The menu is displayed until the user selects an option or the time-out expires.
    "\\24000010"; "Element" = {memdiag}; // REG_MULTI_SZ, toolsdisplayorder = {memdiag} - The boot manager tools display order list.
    "\\24000002"; "Element" = {current}; // REG_MULTI_SZ, bootsequence = {current} - If the firmware boot manager does not support loading multiple applications, this list cannot contain more than one entry. - List of boot environment applications the boot manager should execute. The applications are executed in the order they appear in this list.
    "\\24000001"; "Element" = {current}; // REG_MULTI_SZ, displayorder = {current} - The order in which BCD objects should be displayed. Objects are displayed using the string specified by the BcdLibraryString_Description element.
    "\\23000006"; "Element" = {resume}; // REG_SZ, resumeobject = {resume} - The resume application object.
    "\\23000003"; "Element" = {current}; // REG_SZ, default = {current} - The default boot environment application to load if the user does not select one.
    "\\22000023"; "Element" = \EFI\Microsoft\Boot\BCD; // REG_SZ, bcdfilepath = \EFI\Microsoft\Boot\BCD - The boot application.
    "\\21000022"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, bcddevice = partition=\Device\HarddiskVolume1 - The device on which the boot application resides.
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Boot Manager; // REG_SZ, description = Windows Boot Manager - Display name of the boot environment application.
    "\\12000002"; "Element" = \EFI\MICROSOFT\BOOT\BOOTMGFW.EFI; // REG_SZ, path = \EFI\MICROSOFT\BOOT\BOOTMGFW.EFI - Path to a boot environment application.
    "\\11000001"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, device = partition=\Device\HarddiskVolume1 - Device on which a boot environment application resides.
```

#### Windows Memory Diagnostic

```c
"HKLM\\BCD00000000\\Objects\\{memdiag}\\Elements";
    "\\26000004"; "Element" = 01; // REG_BINARY, failuresenabled = true, false = 00
    "\\25000009"; "Element" = 0000000000000000; // REG_BINARY, chckrfailcount = 0
    "\\25000007"; "Element" = 0000000000000000; // REG_BINARY, matsfailcount = 0
    "\\25000006"; "Element" = 0000000000000000; // REG_BINARY, invcfailcount = 0
    "\\25000005"; "Element" = 0000000000000000; // REG_BINARY, stridefailcount = 0
    "\\25000003"; "Element" = 0000000000000000; // REG_BINARY, failurecount = 0 - The number of pages that contain errors. This is useful for simulating error flows in the absence of bad physical memory.
    "\\25000002"; "Element" = 0000000000000000; // REG_BINARY, testmix = 0
    "\\25000001"; "Element" = 0000000000000000; // REG_BINARY, passcount = 0 - If this value is not specified, the default is to run memory diagnostic tests until the computer is powered off or the user logs off. - The number of passes for the current test mix.
    "\\1600000B"; "Element" = 01; // REG_BINARY, badmemoryaccess = true, false = 00 - If TRUE, indicates that a boot application can use memory listed in the BcdLibraryIntegerList_BadMemoryList.
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Memory Diagnostic; // REG_SZ, description = Windows Memory Diagnostic - Display name of the boot environment application.
    "\\12000002"; "Element" = \EFI\Microsoft\Boot\memtest.efi; // REG_SZ, path = \EFI\Microsoft\Boot\memtest.efi - Path to a boot environment application.
    "\\11000001"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, device = partition=\Device\HarddiskVolume1 - Device on which a boot environment application resides.
```

#### RAM Defects

```c
"HKLM\\BCD00000000\\Objects\\{badmemory}\\Elements";
    "\\1700000A"; "Element" = 0000000000000000; // REG_BINARY, badmemorylist = <integer list> - List of page frame numbers describing faulty memory in the system.
```

#### Windows Recovery Environment Loader

```c
"HKLM\\BCD00000000\\Objects\\{winre}\\Elements";
    "\\46000010"; "Element" = 01; // REG_BINARY, custom:46000010 = true, false = 00
    "\\26000022"; "Element" = 01; // REG_BINARY, winpe = true, false = 00 - Indicates that the system should be started in Windows Preinstallation Environment (Windows PE) mode.
    "\\250000C2"; "Element" = 0100000000000000; // REG_BINARY, bootmenupolicy = 1 (Standard), Legacy = 0000000000000000 - Defines the type of boot menus the system will use. Possible values include menupolicylegacy (0) or menupolicystandard (1). The default value is menupolicylegacy (0).
    "\\25000020"; "Element" = 0000000000000000; // REG_BINARY, nx = 0 (OptIn), OptOut = 0100000000000000, AlwaysOff = 0200000000000000, AlwaysOn = 0300000000000000 - If this value is not specified, the default is NxPolicyAlwaysOff. - The no-execute page protection policy.
    "\\22000002"; "Element" = \windows; // REG_SZ, systemroot = \windows - This value is reserved.
    "\\21000001"; "Element" = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions}; // REG_BINARY, osdevice = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions} - This value is reserved.
    "\\15000065"; "Element" = 0300000000000000; // REG_BINARY, displaymessage = 3 (Recovery), Resume = 0100000000000000
    "\\14000006"; "Element" = {bootloadersettings}; // REG_MULTI_SZ, inherit = {bootloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-us; // REG_SZ, locale = en-us - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Recovery Environment; // REG_SZ, description = Windows Recovery Environment - Display name of the boot environment application.
    "\\12000002"; "Element" = \windows\system32\winload.efi; // REG_SZ, path = \windows\system32\winload.efi - Path to a boot environment application.
    "\\11000001"; "Element" = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions}; // REG_BINARY, device = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions} - Device on which a boot environment application resides.
```

#### Device Options for Ramdisk

```c
"HKLM\\BCD00000000\\Objects\\{ramdiskoptions}\\Elements";
    "\\3600000B"; "Element" = 01; // REG_BINARY, ramdisktftpvarwindow = true, false = 00 - Enables or disables the TFTP variable window size extension.
    "\\3600000A"; "Element" = 01; // REG_BINARY, ramdiskmulticasttftpfallback = true, false = 00 (ramdiskmctftpfallback) - Enables fallback to TFTP if multicast fails.
    "\\36000009"; "Element" = 01; // REG_BINARY, ramdiskmulticastenabled = true, false = 00 (ramdiskmcenabled) - Enables or disables multicast for the RAM disk WIM file.
    "\\36000008"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpwindowsize = 0 - Defines the TFTP window size for the RAM disk WIM file.
    "\\36000007"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpblocksize = 0 - Defines the TFTP block size for the RAM disk Windows Imaging (WIM) file.
    "\\36000006"; "Element" = 01; // REG_BINARY, ramdiskexportascd = true, false = 00 - Enables exporting the RAM disk as a CD.
    "\\35000008"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpwindowsize = 0 (BitLocker list uses 0x35000008)
    "\\35000007"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpblocksize = 0 (BitLocker list uses 0x35000007)
    "\\35000005"; "Element" = 0000000000000000; // REG_BINARY, ramdiskimagelength = 0 - The length of the image for the RAM disk.
    "\\35000002"; "Element" = 0000000000000000; // REG_BINARY, tftpclientport = 0 - If this value is not specified, the default TFTP protocol port is used. - The IP port number to be used for Trivial File Transfer Protocol (TFTP) reads.
    "\\35000001"; "Element" = 0000000000000000; // REG_BINARY, ramdiskimageoffset = 0 - The RAM disk image offset.
    "\\32000004"; "Element" = \Recovery\WindowsRE\boot.sdi; // REG_SZ, ramdisksdipath = \Recovery\WindowsRE\boot.sdi - The path from the root of the SDI device to the RAM disk file.
    "\\31000003"; "Element" = partition=C:; // REG_BINARY, ramdisksdidevice = partition=C: - The device that contains the SDI object.
    "\\12000004"; "Element" = Windows Recovery; // REG_SZ, description = Windows Recovery - Display name of the boot environment application.
```

#### Global Settings

```c
"HKLM\\BCD00000000\\Objects\\{globalsettings}\\Elements";
    "\\16000069"; "Element" = 01; // REG_BINARY, custom:16000069 = true, false = 00
    "\\16000067"; "Element" = 01; // REG_BINARY, custom:16000067 = true, false = 00
    "\\14000006"; "Element" = {dbgsettings};{emssettings};{badmemory}; // REG_MULTI_SZ, inherit = {dbgsettings}, {emssettings}, {badmemory} - List of BCD objects from which the current object should inherit elements.
```

#### Resume Loader Settings

```c
"HKLM\\BCD00000000\\Objects\\{resumeloadersettings}\\Elements";
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
```

#### Boot Loader Settings

```c
"HKLM\\BCD00000000\\Objects\\{bootloadersettings}\\Elements";
    "\\14000006"; "Element" = {globalsettings};{hypervisorsettings}; // REG_MULTI_SZ, inherit = {globalsettings}, {hypervisorsettings} - List of BCD objects from which the current object should inherit elements.
```

#### Debugger Settings

```c
"HKLM\\BCD00000000\\Objects\\{dbgsettings}\\Elements";
    "\\1600001C"; "Element" = 01; // REG_BINARY, debuggernetdhcp = true, false = 00 - Controls the use of DHCP by the network debugger. Setting this to false causes the OS to only use link-local addresses.
    "\\16000017"; "Element" = 01; // REG_BINARY, debuggerignoreusermodeexceptions = true, false = 00 - If TRUE, the debugger will ignore user mode exceptions and only stop for kernel mode exceptions.
    "\\16000010"; "Element" = 01; // REG_BINARY, debuggerenabled = true, false = 00 - Indicates whether the boot debugger should be enabled.
    "\\1500001B"; "Element" = 0000000000000000; // REG_BINARY, debuggernetport = 0 - Defines the network port for the network debugger.
    "\\1500001A"; "Element" = 0000000000000000; // REG_BINARY, debuggernethostip = 0 - Defines the host IP address for the network debugger.
    "\\15000018"; "Element" = 0000000000000000; // REG_BINARY, debuggerstartpolicy = 0 - Indicates the debugger start policy.
    "\\15000015"; "Element" = 0000000000000000; // REG_BINARY, debugger1394channel = 0 - Channel number for 1394 debugging.
    "\\15000014"; "Element" = 00c2010000000000; // REG_BINARY, debuggerserialbaudrate = 115200 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Baud rate for serial debugging.
    "\\15000013"; "Element" = 0100000000000000; // REG_BINARY, debuggerserialport = 1 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Serial port number for serial debugging.
    "\\15000012"; "Element" = 0000000000000000; // REG_BINARY, debuggerserialportaddress = 0 - I/O port address for the serial debugger.
    "\\15000011"; "Element" = 0400000000000000; // REG_BINARY, debugtype = 4 (Local - undocumented), Serial = 0000000000000000, 1394 = 0100000000000000, USB = 0200000000000000, NET = 0300000000000000 - Debugger type.
    "\\1200001D"; "Element" = testkey; // REG_SZ, debuggernetkey = testkey - Holds the key used to encrypt the network debug connection.
    "\\12000019"; "Element" = 0.25.0; // REG_SZ, debuggerbusparams = 0.25.0 - Defines the PCI bus, device, and function numbers of the debugging device. For example, 1.5.0 describes the debugging device on bus 1, device 5, function 0.
    "\\12000016"; "Element" = usbtarget; // REG_SZ, debuggerusbtargetname = usbtarget - The target name for the USB debugger. The target name is arbitrary but must match between the debugger and the debug target.
```

#### EMS Settings

```c
"HKLM\\BCD00000000\\Objects\\{emssettings}\\Elements";
    "\\16000020"; "Element" = 00; // REG_BINARY, bootems = false, true = 01 - Indicates whether EMS redirection should be enabled.
    "\\15000023"; "Element" = 00c2010000000000; // REG_BINARY, emsbaudrate = 115200 - Baud rate for EMS redirection.
    "\\15000022"; "Element" = 0100000000000000; // REG_BINARY, emsport = 1 - If this value is not specified, the default is specified by the SPCR ACPI table settings. - COM port number for EMS redirection.
```

#### Firmware Boot Manager

```c
"HKLM\\BCD00000000\\Objects\\{fwbootmgr}\\Elements";
    "\\25000004"; "Element" = 0100000000000000; // REG_BINARY, timeout = 1 - If this value is not specified, the boot manager waits for the user to make a selection. - The maximum number of seconds a boot selection menu is to be displayed to the user. The menu is displayed until the user selects an option or the time-out expires.
    "\\24000001"; "Element" = {bootmgr}; // REG_MULTI_SZ, displayorder = {bootmgr} - The order in which BCD objects should be displayed. Objects are displayed using the string specified by the BcdLibraryString_Description element.
```

#### Hypervisor Settings

```c
"HKLM\\BCD00000000\\Objects\\{hypervisorsettings}\\Elements";
    "\\26000114"; "Element" = 00; // REG_BINARY, hypervisordhcp = false, true = 01 - Controls use of DHCP by the network debugger used with the hypervisor. Setting this to false forces local link only address.
    "\\250000FE"; "Element" = 50c3000000000000; // REG_BINARY, hypervisorhostport = 50000 - Defines the network UDP port for the network debugger.
    "\\250000FD"; "Element" = 0201a8c000000000; // REG_BINARY, hypervisorhostip = 3232235778 (192.168.1.2) - Defines the host IPv4 address for the network debugger.
    "\\250000F6"; "Element" = 0000000000000000; // REG_BINARY, hypervisorchannel = 0 - Specifies the channel number for 1394 debugging.
    "\\250000F5"; "Element" = 00c2010000000000; // REG_BINARY, hypervisorbaudrate = 115200 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Specifies the baud rate for serial debugging.
    "\\250000F4"; "Element" = 0100000000000000; // REG_BINARY, hypervisordebugport = 1 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Specifies the serial port number for serial debugging.
    "\\250000F3"; "Element" = 0000000000000000; // REG_BINARY, hypervisordebugtype = 0 (Serial), 1394 = 0100000000000000, NET = 0300000000000000 - Controls the hypervisor debugger type. Can be set to SERIAL (0), 1394 (1), or NET (2).
    "\\22000110"; "Element" = testkey; // REG_SZ, hypervisorusekey = testkey - Holds the key used to encrypt the network debug connection used with the hypervisor.
    "\\220000F9"; "Element" = 0.25.0; // REG_SZ, hypervisorbusparams = 0.25.0 - Defines the PCI bus, device, and function numbers of the debugging device used with the hypervisor. For example, 1.5.0 describes the debugging device on bus 1, device 5, function 0.
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit4.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit5.png?raw=true)

## Pseudocode Notes

Notes on several features in relation of [HalpMiscGetParameters](https://github.com/nohuto/win-config/blob/main/system/assets/bcdedit-HalpMiscGetParameters.c).

```c
lkd> db HalpInterruptX2ApicPolicy l1
fffff807`8d20a5dc  01

if ( strstr(v3, "X2APICPOLICY=ENABLE") )
    HalpInterruptX2ApicPolicy = 1;

if ( strstr(v3, "X2APICPOLICY=DISABLE") )
    HalpInterruptX2ApicPolicy = 0;

if ( strstr(v3, "USELEGACYAPICMODE") )
    HalpInterruptX2ApicPolicy = 0; // force disable
```
```c
lkd> db HalpTscSyncPolicy l1
Couldnt resolve error at HalpTscSyncPolicy // doesn't exist

HalpTscSyncPolicy = 1; // TSCSYNCPOLICY=LEGACY
HalpTscSyncPolicy = 2; // TSCSYNCPOLICY=ENHANCED
```

`bcdedit /set loadoptions SYSTEMWATCHDOGPOLICY=DISABLED`
```c
if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=DISABLED") )
{
    HalpTimerWatchdogDisable = 1;
}
else if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=PHYSICALONLY") )
{
    HalpTimerWatchdogPhysicalOnly = 1;
}

lkd> db HalpTimerWatchdogDisable l1
fffff803`d21c0712  00 // default
```
```c
lkd> db HalpTimerPlatformSourceForced l1
fffff803`d21c25d0  00
lkd> db HalpTimerPlatformClockSourceForced l1
fffff803`d21c2678  00

if ( strstr(v3, "USEPLATFORMCLOCK") )
    HalpTimerPlatformSourceForced = 1;

if ( strstr(v3, "USEPLATFORMTICK") )
    HalpTimerPlatformClockSourceForced = 1;
```
```c
v17 = strstr(v3, "GROUPSIZE");
if ( v17 )
{
    while ( 1 )
    {
        v18 = *v17;
        if ( !*v17 || v18 == 32 || (unsigned __int8)(v18 - 48) <= 9u )
            break;
        ++v17;
    }
    HalpMaximumGroupSize = atoi(v17);
    if ( (unsigned int)(HalpMaximumGroupSize - 1) > 0x3F )
        HalpMaximumGroupSize = 64; // clamp to 1..64
}

strstr(v3, "HALTPROFILINGPOLICY=BLOCKED");
strstr(v3, "HALTPROFILINGPOLICY=RELAXED");
return strstr(v3, "HALTPROFILINGPOLICY=RESTRICTED"); // only returns pointer if present
```
```c
lkd> db HalpMiscDiscardLowMemory l1
fffff803`d21bff79  01 // USENONE / USEPRIVATE?
lkd> db HalpHvCpuManager l1
fffff804`c27c0490  00

if ( (unsigned int)HalpInterruptModel() == 1 )
    HalpMiscDiscardLowMemory = 1; // default if HalpInterruptModel() == 1

if ( HalpHvCpuManager )
{
    v19[0] = 0;
    if ( (unsigned __int8)HalpGetCpuInfo(0LL, 0LL, 0LL, v19) )
    {
        if ( v19[0] == 2 && (__readmsr(0xFEu) & 0x8000) != 0 )
        HalpMiscDiscardLowMemory = 1; // 1 if HV CPU manager + CPU type 2 + MSR 0xFE bit 15 set
    }
}
if (strstr(BootOptions, "FIRSTMEGABYTEPOLICY=USEALL") || // one of them have to be true to get 0
    (HalpIsMicrosoftCompatibleHvLoaded() && !HalpHvCpuManager)) // system running under hypervisor & not HalpHvCpuManager
{
    HalpMiscDiscardLowMemory = 0; // forced 0 if above is true
}
```
```c
v3 = *(const char **)(a1 + 216);
if ( v3 )
{
    strstr(*(const char **)(a1 + 216), "SAFEBOOT:"); // does nothing here

    if ( strstr(v3, "ONECPU") )
        HalpInterruptProcessorCap = 1;

    if ( strstr(v3, "USEPHYSICALAPIC") )
        HalpInterruptPhysicalModeOnly = 1;

    if ( strstr(v3, "BREAK") )
        HalpMiscDebugBreakRequested = 1;
}
```
```c
v4 = strstr(v3, "MAXPROCSPERCLUSTER");
if ( v4 )
{
    while ( 1 )
    {
        v5 = *v4;
        if ( !*v4 || v5 == 32 || (unsigned __int8)(v5 - 48) <= 9u )
            break;
        ++v4;
    }
    v6 = atoi(v4);
    HalpInterruptForceClusterMode(v6);
}

v7 = strstr(v3, "MAXAPICCLUSTER");
if ( v7 )
{
    while ( 1 )
    {
        v8 = *v7;
        if ( !*v7 || v8 == 32 || (unsigned __int8)(v8 - 48) <= 9u )
            break;
        ++v7;
    }
    v9 = atoi(v7);
    if ( v9 )
        LODWORD(HalpInterruptMaxCluster) = v9;
}
```
```c
if ( strstr(v3, "CONFIGACCESSPOLICY=DISALLOWMMCONFIG") )
    HalpAvoidMmConfigAccessMethod = 1; // force avoid
```
```c
if ( strstr(v3, "MSIPOLICY=FORCEDISABLE") ) // HalpInterruptSetMsiOverride(0)
{
    v10 = 0LL;
}
else
{
    if ( !strstr(v3, "FORCEMSI") ) // HalpInterruptSetMsiOverride(1)
        goto LABEL_46;
    LOBYTE(v10) = 1;
}
HalpInterruptSetMsiOverride(v10);
```

## Custom Edits

`custom:16000067 true` disables the Windows logo while booting:

![](https://github.com/nohuto/win-config/blob/main/system/images/logo.png?raw=true)

`custom:16000069 true` disables the loading circle while booting:

![](https://github.com/nohuto/win-config/blob/main/system/images/load.png?raw=true)

## Default Entries

All existing default boot loader entries (25H2):

```powershell
Windows Boot Loader
-------------------
identifier              {current}
device                  partition=C:
path                    \WINDOWS\system32\winload.exe
description             Windows 11
locale                  en-US
inherit                 {bootloadersettings}
recoverysequence        {1c945b5b-7654-11f1-adb7-b9bb2ba517f9}
displaymessageoverride  Recovery
recoveryenabled         Yes
allowedinmemorysettings 0x15000075
osdevice                partition=C:
systemroot              \WINDOWS
resumeobject            {1c945b59-7654-11f1-adb7-b9bb2ba517f9}
nx                      OptIn
bootmenupolicy          Standard
debug                   No
```

# Page File

Will be updated soon, date of commit `04.07.2026`.

## Suboption

### Clear Page File on Shutdown

Paging files can contain fragments of process or kernel data, enabling the option mitigates offline data exposure at the cost of longer shutdowns.

> "*This security setting determines whether the virtual memory pagefile is cleared when the system is shut down.*
>
> *Virtual memory support uses a system pagefile to swap pages of memory to disk when they are not used. On a running system, this pagefile is opened exclusively by the operating system, and it is well protected. However, systems that are configured to allow booting to other operating systems might have to make sure that the system pagefile is wiped clean when this system shuts down. This ensures that sensitive information from process memory that might go into the pagefile is not available to an unauthorized user who manages to directly access the pagefile.*
>
> *When this policy is enabled, it causes the system pagefile to be cleared upon clean shutdown. If you enable this security option, the hibernation file (hiberfil.sys) is also zeroed out when hibernation is disabled.*"

# Disable Notifications

The '*System Template*' won't disable all notifications, so e.g. critical Defender notifications will still be shown.

## (Sub)Options

| Option | Description |
| ---- | ---- |
| Main | Disables all kind of notifications completely. |
| Disable Low Disk Space Checks | Disables the `Low Disk Space` notification. ![](https://github.com/nohuto/win-config/blob/main/system/images/lowdiskspace.jpg?raw=true) |
| Hide all Windows Security notifications | Disables all notifications via the `DisableNotifications`  policy (this probably overrides all other security notifications below). |
| Hide non-critical Windows Security notifications | Disables non-critical/enhanced notifications via the Windows Security and Microsoft Defender Antivirus `DisableEnhancedNotifications` policies. |
| Disable Enhanced Phishing Protection warnings | Disables the Enhanced Phishing Protection warning prompts for malicious sites, password reuse, and unsafe apps. |
| Disable Virus & threat protection notifications | Disables all in `Windows Security > Settings > Manage notifications: Virus & threat protection notifications` |
| Disable Account protection notifications | Disables all in `Windows Security > Settings > Manage notifications: Account protection notifications` |
| Disable Firewall & network protection notifications | Disables all in `Windows Security > Settings > Manage notifications: Firewall & network protection notifications` |
| Disable Security & Maintenance Notifications | Disables it via `SystemSettings > System > Notifications: Security and Maintenance` |
| Disable Sync Provider Notifications | Disables it via `Explorer > View > Options > View: Show sync provider notifications` |
| Disable account-related notifications | Disables it via `SystemSettings > Personalization > Start: Show account related notifications occasionally in Start` |
| Disable Clock Change notifications | Disables it via `Control Panel > Clock and Region > Date and Time: Notify me when the clock chanes` |
| Hide Notification Center | Works via `NoAutoTrayNotify`/`DisableNotificationCenter` policies and `SystemSettings > System > Notifications: Show notification bell icon` |
| Disable Notification Sound | Disables it via `SystemSettings > System > Notifications > Allow notifications to play sound` |
| Disable Lockscreen Notifications | Works via `DisableLockScreenAppNotifications` policy and `SystemSettings > System > Notifications: Show notifications on the lock screen + Show reminders and incoming VoIP calls on the lock screen` |
| Turn off access to the Store | `NoUseStoreOpenWith` policy - "*This policy setting specifies whether to use the Store service for finding an application to open a file with an unhandled file type or protocol association. When a user opens a file type or protocol that is not associated with any applications on the computer, the user is given the choice to select a local application or use the Store service to find an application. If you enable this policy setting, the "Look for an app in the Store" item in the Open With dialog is removed. If you disable or do not configure this policy setting, the user is allowed to use the Store service and the Store item is available in the Open With dialog.*" |
| Hide Time in Notification Center | Works via `SystemSettings > Time & language > Date & time: Show time and date in the System tray` |

## Miscellaneous Notes

### WnsEndpoint

"`WnsEndpoint` (`REG_SZ`) determines which Windows Notification Service (WNS) endpoint will be used to connect for Windows push notifications. If you disable or don't configure this setting, the push notifications will connect to the default endpoint of `client.wns.windows.com`. " Located in `HKLM\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications`. Block `client.wns.windows.com` via the hosts file.

### Registry Values

All `NOC_GLOBAL_SETTING_*` I found in `NotificationController.dll`:
```c
"HKLM\\SOFTWARE\\Microsoft\\WINDOWS\\CurrentVersion\\Notifications\\Settings"
  'NOC_GLOBAL_SETTING_SUPRESS_TOASTS_WHILE_DUPLICATING'; // Hide notifications when I'm duplicating my screen
  'NOC_GLOBAL_SETTING_ALLOW_TOASTS_ABOVE_LOCK'; // Show notifications on the lock screen
  'NOC_GLOBAL_SETTING_ALLOW_CRITICAL_TOASTS_ABOVE_LOCK'; // Show reminders and incoming VoIP calls on the lock screen
  'NOC_GLOBAL_SETTING_CORTANA_MANAGED_NOTIFICATIONS';
  'NOC_GLOBAL_SETTING_ALLOW_ACTION_CENTER_ABOVE_LOCK';
  'NOC_GLOBAL_SETTING_HIDE_NOTIFICATION_CONTENT';
  'NOC_GLOBAL_SETTING_TOASTS_ENABLED';
  'NOC_GLOBAL_SETTING_BADGE_ENABLED'; // Don't show number of notifications
  'NOC_GLOBAL_SETTING_GLEAM_ENABLED'; // App icons (Action Center)
  'NOC_GLOBAL_SETTING_ALLOW_HMD_NOTIFICATIONS'; // Show notifications on my head mounted display
  'NOC_GLOBAL_SETTING_ALLOW_CONTROL_CENTER_ABOVE_LOCK';
  'NOC_GLOBAL_SETTING_ALLOW_NOTIFICATION_SOUND'; // Allow notification to play sounds
```
The options I've commented on are included in the options under `System > Notifications`/right click menu of notification center.

Since `BackupReminderToastCount` isn't a well known value, I've done quick research where it exists and if it does exist. While doing so I found different values:
```c
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\StorageSense\\Parameters\\StoragePolicy";
    "StoragePoliciesNotified" = 0; // REG_DWORD, default 0 if missing, range: 0-1
    "StoragePoliciesChanged" = 0; // REG_DWORD, default 0 if missing, range: 0-1
    "OptinToastFired" = 0; // REG_DWORD, default 0 if missing, range: 0-1
    "FirstLaunchToastFired" = 0; // REG_DWORD, default 0 if missing, range: 0-1
    "CloudfilePolicyConsent" = 0; // REG_DWORD, default 0 if missing, range: 0-1
    "CloudConsentToastCount" = 0; // REG_DWORD, default 0 if missing, range: 0-3
    "OptOutButtonClicked" = 0; // REG_DWORD, default 0 if missing, range: 0-1

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\DiskSpaceChecking";
    "LastInstallTimeLowStorageNotify" = 0; // REG_QWORD FILETIME, range: FILETIME, ComparedTo: OneDay
    "NumWinOldLowStorageNotify" = 0; // REG_DWORD, default 0 if missing, range: 0-3

"HKLM\\Software\\Microsoft\\Windows NT\\CurrentVersion";
    "InstallTime" = 0; // REG_QWORD FILETIME, range: FILETIME, ComparedTo: TwoHours

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\StorageSense\\Parameters\\BackupReminder";
    "TestBackupReminderToast" = 0; // REG_DWORD, default 0 if missing, range: 0-2?

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\StorageSense\\Parameters\\BackupReminder";
    "FirstProfileSeenTime" = 0; // REG_QWORD FILETIME, default set to current system time if missing, range: FILETIME, ComparedTo: FourMinutes
    "BackupReminderToastCount" = 0; // REG_DWORD, default 0 if missing, range: 0-3
    "LastTimeBackupReminderNotify" = 0; // REG_QWORD FILETIME, range: FILETIME, ComparedTo: TwoMinutes

// FILETIME THRESHOLDS
"OneDay" = 0xC92A69C000; // Seconds: 86400, 1 day, LastInstallTimeLowStorageNotify
"TwoHours" = 0x10C388D000; // Seconds: 7200, 2 hours, InstallTime
"FourMinutes" = 0x8F0D1800; // Seconds: 240, 4 minutes, FirstProfileSeenTime
"TwoMinutes" = 0x47868C00; // Seconds: 120, 2 minutes, LastTimeBackupReminderNotify
```

See [system/assets | noti-CLowDiskSpaceUI_CanShowStorageSenseToast.c](https://github.com/nohuto/win-config/blob/main/system/assets/noti-CLowDiskSpaceUI_CanShowStorageSenseToast.c) for used pseudocode. Note that I added my chosen values to the `Disable Low Disk Space Checks` suboption for safety reasons.

```c
"HKCU\\Control Panel\\Accessibility";
  // Dismiss notifications after this amount of time
  "MessageDuration" = 5; // REG_DWORD, range 5-300(s) - According to pseudocode, it has a range from `0` to `0xFFFFFFFF`. Fallback of `5`, SystemSettings supports ranges from `5` (5 seconds) to `300` (5 minutes). Anything above/below will likely be limited (haven't tested it yet).

"HKCU\\Software\\Microsoft\\Windows\\MiracastDiscovery"
  "DisableNotification" = 0; // read on boot - "HKCU\Software\Microsoft\Windows\MiracastDiscovery\DisableNotification","Type: REG_DWORD, Length: 4, Data: 0"
  "NotificationCount" = 0; // read on boot - "HKCU\Software\Microsoft\Windows\MiracastDiscovery\NotificationCount","Type: REG_DWORD, Length: 4, Data: 0"

// miscellaneous procmon boot trace values
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\IsDebugEnabled","Length: 16"
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\SmartOptOut\\InitialTimerCooldown","Length: 20"
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\SmartOptOut\\PeriodicTimerCooldown","Length: 20"
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\SmartOptOut\\SmartOptOutRevision","Type: REG_QWORD, Length: 8, Data: "
"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Notifications\\TimestampWhenSeen","Length: 20"
```

## SystemSettings Captures

```c
// System > Notifications

// Get notifications from apps and other senders
// On = 1 or value missing
// Off = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\PushNotifications\ToastEnabled // Type: REG_DWORD

// Allow notifications to play sounds
// On = delete
// Off = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\NOC_GLOBAL_SETTING_ALLOW_NOTIFICATION_SOUND // Type: REG_DWORD

// Show notifications on the lock screen
// On = NOC value deleted, LockScreenToastEnabled = 1
// Off = NOC value 0, LockScreenToastEnabled = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\NOC_GLOBAL_SETTING_ALLOW_TOASTS_ABOVE_LOCK // Type: REG_DWORD
HKCU\Software\Microsoft\Windows\CurrentVersion\PushNotifications\LockScreenToastEnabled // Type: REG_DWORD

// Show reminders and incoming VoIP calls on the lock screen
// On = delete
// Off = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\NOC_GLOBAL_SETTING_ALLOW_CRITICAL_TOASTS_ABOVE_LOCK // Type: REG_DWORD

// Show notification bell icon
// On = 1
// Off = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\ShowNotificationIcon // Type: REG_DWORD

// Notifications from apps and other senders (examples since this depends on the installed apps)
// On = delete
// Off = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\Windows.ActionCenter.SmartOptOut\Enabled // Notification Suggestions
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\Microsoft.Windows.Explorer\Enabled // File Explorer
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\Windows.SystemToast.SecurityAndMaintenance\Enabled // Security and Maintenance
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\Windows.SystemToast.PinConsent\Enabled // Apps
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\windows.immersivecontrolpanel_cw5n1h2txyewy!microsoft.windows.immersivecontrolpanel\Enabled // Settings
HKCU\Software\Microsoft\Windows\CurrentVersion\Notifications\Settings\Windows.SystemToast.StartupApp\Enabled // Startup App Notification
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off account notifications in Start](https://noverse.dev/policies?p=AccountNotifications*DisableAccountNotifications) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\AccountNotifications` | `DisableAccountNotifications` |
| [Turn off access to the Store](https://noverse.dev/policies?p=ICM*ShellNoUseStoreOpenWith_2) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `NoUseStoreOpenWith` |
| [Turn off app notifications on the lock screen](https://noverse.dev/policies?p=Logon*DisableLockScreenAppNotifications) | `HKLM\Software\Policies\Microsoft\Windows\System` | `DisableLockScreenAppNotifications` |
| [Remove Notifications and Action Center](https://noverse.dev/policies?p=Taskbar*DisableNotificationCenter) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `DisableNotificationCenter` |
| [Notify Malicious](https://noverse.dev/policies?p=WebThreatDefense*NotifyMalicious) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyMalicious` |
| [Notify Password Reuse](https://noverse.dev/policies?p=WebThreatDefense*NotifyPasswordReuse) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyPasswordReuse` |
| [Notify Unsafe App](https://noverse.dev/policies?p=WebThreatDefense*NotifyUnsafeApp) | `HKLM\Software\Policies\Microsoft\Windows\WTDS\Components` | `NotifyUnsafeApp` |
| [Turn off enhanced notifications](https://noverse.dev/policies?p=WindowsDefender*Reporting_DisableEnhancedNotifications) | `HKLM\Software\Policies\Microsoft\Windows Defender\Reporting` | `DisableEnhancedNotifications` |
| [Hide all notifications](https://noverse.dev/policies?p=WindowsDefenderSecurityCenter*Notifications_DisableNotifications) | `HKLM\SOFTWARE\Policies\Microsoft\Windows Defender Security Center\Notifications` | `DisableNotifications` |
| [Hide non-critical notifications](https://noverse.dev/policies?p=WindowsDefenderSecurityCenter*Notifications_DisableEnhancedNotifications) | `HKLM\SOFTWARE\Policies\Microsoft\Windows Defender Security Center\Notifications` | `DisableEnhancedNotifications` |
| [Turn off tile notifications](https://noverse.dev/policies?p=WPN*NoTileNotification) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `NoTileApplicationNotification` |
| [Turn on multiple expanded toast notifications in action center](https://noverse.dev/policies?p=WPN*ExpandedToastNotifications) | `HKCU\Software\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `EnableExpandedToastNotifications` |
| [Turn off toast notifications](https://noverse.dev/policies?p=WPN*NoToastNotification) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `NoToastApplicationNotification` |
| [Turn off toast notifications on the lock screen](https://noverse.dev/policies?p=WPN*NoLockScreenToastNotification) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `NoToastApplicationNotificationOnLockScreen` |
| [Turn off notifications network usage](https://noverse.dev/policies?p=WPN*NoCloudNotification) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `NoCloudApplicationNotification` |
| [Turn off notification mirroring](https://noverse.dev/policies?p=WPN*NoNotificationMirroring) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CurrentVersion\PushNotifications` | `DisallowNotificationMirroring` |
| [Show notification bell icon](https://noverse.dev/policies?p=Taskbar*AlwaysShowNotificationIcon) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `AlwaysShowNotificationIcon` |
| [Disable showing balloon notifications as toasts.](https://noverse.dev/policies?p=Taskbar*EnableLegacyBalloonNotifications) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `EnableLegacyBalloonNotifications` |
| [Turn off notification area cleanup](https://noverse.dev/policies?p=StartMenu*NoAutoTrayNotify) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `NoAutoTrayNotify` |
| [Turn off all balloon notifications](https://noverse.dev/policies?p=Taskbar*TaskbarNoNotification) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `TaskbarNoNotification` |
| [Turn off feature advertisement balloon notifications](https://noverse.dev/policies?p=Taskbar*NoBalloonFeatureAdvertisements) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `NoBalloonFeatureAdvertisements` |

# Minimal Window Snapping

The main option leaves window snapping enabled, while disabling the snap bar/snap flyout/ snap group etc., for a "minimal" version of it. You can configure window snapping behaviour via the suboptions, if you don't like the main option.

![](https://github.com/nohuto/win-config/blob/main/visibility/images/window-snapping.png?raw=true)

## Suboptions

### Snap Flyout

Hides the snap assist flyout that would appear after hovering over the maximize/restore down icon:

![](https://github.com/nohuto/win-config/blob/main/visibility/images/snapflyout.png?raw=true)

### Window Shake

Prevents windows from being minimized or restored when the active window is shaken back and forth with the mouse.

![](https://www.techjunkie.com/wp-content/uploads/2018/10/windows-aero-shake-example.gif)

#### SystemSettings Captures

```c
// System > Multitasking: Title bar window shake

// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DisallowShaking	Type: REG_DWORD, Length: 4, Data: 0

// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DisallowShaking	Type: REG_DWORD, Length: 4, Data: 1
```

#### [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Aero Shake window minimizing mouse gesture](https://noverse.dev/policies?p=Desktop*NoWindowMinimizingShortcuts) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `NoWindowMinimizingShortcuts` |

## SystemSettings Captures

```c
// System > Multitasking : Snap windows
// Disabled 
HKCU\Control Panel\Desktop\WindowArrangementActive	Type: REG_SZ, Length: 4, Data: 0
// Enabled
HKCU\Control Panel\Desktop\WindowArrangementActive	Type: REG_SZ, Length: 4, Data: 1

// System > Multitasking > Snap windows : When I snap a window, suggest what I can snap next to it
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SnapAssist	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\SnapAssist	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show snap layouts when I hover over a window's maximize button
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapAssistFlyout	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapAssistFlyout	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show snap layouts when I drag a window to the top of my screen
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapBar	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableSnapBar	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : Show my snapped windows when I hover over taskbar apps, in Task View, and when I press Alt+Tab
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableTaskGroups	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableTaskGroups	Type: REG_DWORD, Length: 4, Data: 1

// System > Multitasking > Snap windows : When I drag a window, let me snap it without dragging all the way to the screen edge
// Disabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DITest	Type: REG_DWORD, Length: 4, Data: 0
// Enabled
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\DITest	Type: REG_DWORD, Length: 4, Data: 1
```

# File System Values

Small documentation on several values the option applies, see links below for more details.

### Registry Values

This list isn't complete yet, see [FileSystem](https://github.com/nohuto/regkit/blob/main/records/FileSystem.txt) for all values that get read on boot ([boot capture guide](https://noverse.dev/docs/regkit/guides/wpr-wpa/)).

| Value | Description |
| ----- | ------------ |
| `DisableDeleteNotification` | 0 = TRIM/UNMAP enabled, 1 = disabled. Controls whether delete operations send trim/unmap notifications to the underlying storage. |
| `DontVerifyRandomDrivers` | 0 = Driver Verifier may pick random drivers, 1 = random selection suppressed, so only explicitly chosen drivers are verified. |
| [`LongPathsEnabled`](https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=registry) | 0 = legacy `MAX_PATH` limit, 1 = Win32 long paths enabled (paths up to ~32k characters for apps and policies that opt in). |
| `NtfsAllowExtendedCharacter8dot3Rename` | 0 = 8.3 short names restricted to basic ASCII, 1 = extended characters (including diacritics). |
| `NtfsBugcheckOnCorrupt` | 0 = NTFS attempts self healing without forcing a bugcheck, 1 = triggers a bugcheck when corruption is detected on an NTFS volume, avoiding "silent" data loss with self healing NTFS. |
| `NtfsDisable8dot3NameCreation` | Disables the creation of 8.3 character-length file names on FAT- and NTFS-formatted volumes.<br>0: Enables 8dot3 name creation for all volumes on the system.<br>1: Disables 8dot3 name creation for all volumes on the system.<br>2: Sets 8dot3 name creation on a per volume basis.<br>3: Disables 8dot3 name creation for all volumes except the system volume. |
| `NtfsDisableCompression` | 0 = NTFS compression allowed, 1 = new compressed files/folders cannot be created (existing compressed data remains readable). |
| `NtfsDisableCompressionLimit` | 0 = when a compressed file gets highly fragmented, NTFS stops compressing new extents so the file can grow larger uncompressed, 1 = disables this behavior and enforces the internal compression limit. |
| `NtfsDisableEncryption` | 0 = NTFS EFS file/folder encryption available, 1 = EFS disabled on NTFS volumes. |
| `NTFSDisableLastAccessUpdate` | Controls Last Access Time updates on NTFS files/directories. |
| `NtfsDisableSpotCorruptionHandling` | 0 = NTFS spot corruption handling active, 1 = disabled, so NTFS relies on manual tools. Also allows running CHKDSK to analyze a volume online without taking it offline. |
| `NtfsEncryptPagingFile` | 0 = pagefile.sys stored unencrypted, 1 = paging file encrypted. |
| `NtfsMemoryUsage` | Configures the internal cache levels of NTFS paged-pool memory and NTFS nonpaged-pool memory. |
| `NtfsMftZoneReservation` | Sets reserved NTFS MFT zone size as 200 MB x value: 1 = 200 MB (default), up to 4 = 800 MB. Larger values reduce MFT fragmentation on volumes with many small files. |
| `RefsDisableLastAccessUpdate` | Related to NTFSDisableLastAccessUpdate (both get set via disablelastaccess). |
| `SymlinkXToXEvaluation` | 0 = x->x symlinks not followed, 1 = resolved (X = Local/Remote). Symlinksare shortcuts or references that point to a file or folder in another location, like a portal. They're not duplicates, just pointers. File at: `C:\Projects\Game\assets\logo.png`, Symlink: `C:\Users\YourName\Desktop\logo.png`. |
| `Win31FileSystem` | 0 = standard modern FAT behavior (long filenames, richer timestamps), 1 = legacy Windows 3.1–compatible mode with stricter 8.3 naming and older timestamp semantics. |

- [system/assets | filesystem-NtfsUpdateDynamicRegistrySettings.c](https://github.com/nohuto/win-config/blob/main/system/assets/filesystem-NtfsUpdateDynamicRegistrySettings.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Win32 long paths](https://noverse.dev/policies?p=FileSys*LongPathsEnabled) | `HKLM\System\CurrentControlSet\Control\FileSystem` | `LongPathsEnabled` |

# Disable Hyper-V

> "*The Hyper-V hypervisor (also known as Windows hypervisor) is a type-1 (native or bare-metal) hypervisor: a mini operating system that runs directly on the host's hardware to manage a single root and one or more guest operating systems. Unlike type-2 (or hosted) hypervisors, which run on the base of a conventional OS like normal applications, the Windows hypervisor abstracts the root OS, which knows about the existence of the hypervisor and communicates with it to allow the execution of one or more guest virtual machines.*"
>
> — Windows Internals, [E7, P2: 'The Windows hypervisor'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

> "*Many third-party virtualization applications don't work together with Hyper-V. Affected applications include VMware Workstation and VirtualBox. These applications might not start virtual machines, or they may fall back to a slower, emulated mode. Many virtualization applications depend on hardware virtualization extensions that are available on most modern processors. It includes Intel VT-x and AMD-V. Only one software component can use this hardware at a time. The hardware cannot be shared between virtualization applications.*"
>
> — Microsoft, [Virtualization applications don't work together with Hyper-V](https://learn.microsoft.com/en-us/troubleshoot/windows-client/application-management/virtualization-apps-not-work-with-hyper-v)

## Service/Driver Table

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `bttflt` | Microsoft Hyper-V VHDPMEM BTT Filter | Kernel Driver (1) | - | System32\drivers\bttflt.sys |
| `gencounter` | Microsoft Hyper-V Generation Counter | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgencounter.sys |
| `hvcrash` | Hyper-V Crashdump | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvcrash.sys |
| `HvHost` | Provides an interface for the Hyper-V hypervisor to provide per-partition performance counters to the host operating system. | Win32 Share Process (32) | hvservice | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `hvservice` | Microsoft Hypervisor Service Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hvservice.sys |
| `hyperkbd` | Microsoft VMBus Synthetic Keyboard Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\hyperkbd.sys |
| `HyperVideo` | Microsoft VMBus Video Device Miniport Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\HyperVideo.sys |
| `storflt` | Microsoft Hyper-V Storage Accelerator | Kernel Driver (1) | - | System32\drivers\vmstorfl.sys |
| `Vid` | Microsoft Hyper-V Virtualization Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\Vid.sys |
| `vmbus` | Virtual Machine Bus | Kernel Driver (1) | - | System32\drivers\vmbus.sys |
| `vmgid` | Microsoft Hyper-V Guest Infrastructure Driver | Kernel Driver (1) | - | \SystemRoot\System32\drivers\vmgid.sys |
| `vmicguestinterface` | Provides an interface for the Hyper-V host to interact with specific services running inside the virtual machine. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicheartbeat` | Monitors the state of this virtual machine by reporting a heartbeat at regular intervals. This service helps you identify running virtual machines that have stopped responding. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmickvpexchange` | Provides a mechanism to exchange data between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicrdv` | Provides a platform for communication between the virtual machine and the operating system running on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k ICService -p |
| `vmicshutdown` | Provides a mechanism to shut down the operating system of this virtual machine from the management interfaces on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmictimesync` | Synchronizes the system time of this virtual machine with the system time of the physical computer. | Win32 Share Process (32) | VmGid | C:\Windows\system32\svchost.exe -k LocalServiceNetworkRestricted -p |
| `vmicvmsession` | Provides a mechanism to manage virtual machine with PowerShell via VM session without a virtual network. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vmicvss` | Coordinates the communications that are required to use Volume Shadow Copy Service to back up applications and data on this virtual machine from the operating system on the physical computer. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |
| `vpci` | Microsoft Hyper-V Virtual PCI Bus | Kernel Driver (1) | - | System32\drivers\vpci.sys |

# Service Splitting

Prevents services hosted by `svchost.exe` from being split into separate host processes. This reduces the amount of `svchost.exe` instances, but also reduces service isolation, just be aware of what negative impact grouping has before chaning the option, the template therefore keeps the client default. If you've less than 3.5GB of RAM splitting is disabled by default.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control";
    "SvcHostSplitThresholdInKB" = 3670016; // REG_DWORD, client default = ~3.5 GB, server default = ~3.7 GB
    "SvcHostDebug" = 0; // REG_DWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\<service>";
    "SvcHostSplitDisable" = 0; // REG_DWORD, per service disable
```

`SvcHostSplitThresholdInKB` = global memory threshold, during SCM startup, it gets read and compared against total physical memory from `GlobalMemoryStatusEx`. If physical memory is greater than or equal to the threshold, SCM enables the `g_fSplitSvcHost` flag (`0` would prevent splitting). `SvcHostDebug` is a fallback override, which is only read whenever `SvcHostSplitThresholdInKB` didn't enable splitting. If its set to `1` it causes `g_fSplitSvcHost = 1`.

```c
// SvcHostSplitThresholdInKB = 3670016 (while having 32GB)
lkd> dd services!g_fSplitSvcHost L1
00007ff7`21586374  00000001

// SvcHostSplitThresholdInKB = 4294967295 (4TB)
lkd> dd services!g_fSplitSvcHost L1
00007ff7`40976374  00000000

// SvcHostSplitThresholdInKB = 0, SvcHostDebug = 0
lkd> dd services!g_fSplitSvcHost L1
00007ff6`5ce06374  00000000

// SvcHostSplitThresholdInKB = 0, SvcHostDebug = 1
lkd> dd services!g_fSplitSvcHost L1
00007ff6`820a6374  00000001
```

Get the current amount of `svchost.exe` process instances via:

```powershell
(Get-Process -Name "svchost" | Measure-Object).Count
```

> "*When the SCM starts, it reads three values from the registry representing the services global commit limits (divided in: low, medium, and hard caps). These values are used by the SCM to send “low resources” messages in case the system runs under low-memory conditions. It then reads the Svchost Service split threshold value from the `HKLM\SYSTEM\CurrentControlSet\Control\SvcHostSplitThresholdInKB` registry value. The value contains the minimum amount of system physical memory (expressed in KB) needed to enable Svchost Service splitting (the default value is 3.5 GB on client systems and around 3.7 GB on server systems). The SCM then obtains the value of the total system physical memory using the GlobalMemoryStatusEx API and compares it with the threshold previously read from the registry. If the total physical memory is above the threshold, it enables Svchost service splitting (by setting an internal global variable). Svchost service splitting, when active, modifies the behavior in which SCM starts the host Svchost process of shared services. As already discussed in the “Service start” section earlier in this chapter, the SCM does not search for an existing image record in its database if service splitting is allowed for a service. This means that, even though a service is marked as sharable, it is started using its private hosting process (and its type is changed to SERVICE_WIN32_OWN_PROCESS). Service splitting is allowed only if the following conditions apply:*  
> *- Svchost Service splitting is globally enabled.*  
> *- The service is not marked as critical. A service is marked as critical if its next recovery action specifies to reboot the machine (as discussed previously in the “Service failures” section).*  
> *- The service host process name is Svchost.exe.*  
> *- Service splitting is not explicitly disabled for the service through the SvcHostSplitDisable registry value in the service control key*  
>
> — Windows Internals, [E7, P2: 'Svchost service splitting'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/servicesplitting2.png?raw=true)

# Disable Storage Sense

Storage Sense deletes temporary/user files automatically, see [windows policies](https://noverse.dev/docs/win-config/system/disable-storage-sense/#windows-policies) for more & [disable-notifications/#registry-values](https://noverse.dev/docs/win-config/system/disable-notifications/#registry-values) for storage sense related notification values.

Head over to the `Policies` tab, then `StorageSense` to configure other related policies.

### SystemSettings Captures

The main storage sense toggle in `System > Storage` does the same as the `Automatic User content cleanup` in `System > Storage > Storage Sense`.

```c
// System > Storage > Storage Sense

// Keep WIndows running smoothly by automatically cleaning up temorary system and app files
// 1 = On
// 0 = Off
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\04 // Type: REG_DWORD

// Automatic User content cleanup
// 1 = On
// 0 = Off
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\01 // Type: REG_DWORD

// Run Storage Sense
// During low free disk space (default) = 0
// Every month = 30
// Every week = 7
// Every day = 1
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\2048	// Type: REG_DWORD

// Delete files in my recycle bin if they have been there for over
// 30 days (default): 08 = 1, 25 = 30
// 60 days: 08 = 1, 256 = 60
// 14 days: 08 = 1, 256 = 14
// 1 day: 08 = 1, 256 = 1
// Never: 08 = 0, 256 = 0
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\08 // Type: REG_DWORD
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\256 // Type: REG_DWORD

// Delete files in my Downloads folder if they haven't been opened for more than
// Never (default): 32 = 0, 512 = 0
// 1 day: 32 = 1, 512 = 1
// 14 days: 32 = 1, 512 = 14
// 30 days: 32 = 1, 512 = 30
// 60 days: 32 = 1, 512 = 60
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\32 // Type: REG_DWORD
HKCU\Software\Microsoft\Windows\CurrentVersion\StorageSense\Parameters\StoragePolicy\512 // Type: REG_DWORD
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Storage Sense](https://noverse.dev/policies?p=StorageSense*SS_AllowStorageSenseGlobal) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `AllowStorageSenseGlobal` |
| [Allow Storage Sense Temporary Files cleanup](https://noverse.dev/policies?p=StorageSense*SS_AllowStorageSenseTemporaryFilesCleanup) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `AllowStorageSenseTemporaryFilesCleanup` |
| [Configure Storage Sense Recycle Bin cleanup threshold](https://noverse.dev/policies?p=StorageSense*SS_ConfigStorageSenseRecycleBinCleanupThreshold) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `ConfigStorageSenseRecycleBinCleanupThreshold` |
| [Configure Storage Storage Downloads cleanup threshold](https://noverse.dev/policies?p=StorageSense*SS_ConfigStorageSenseDownloadsCleanupThreshold) | `HKLM\Software\Policies\Microsoft\Windows\StorageSense` | `ConfigStorageSenseDownloadsCleanupThreshold` |

# Disable Accessibility Features

Disables all kind of accessibility features such as `Voice Access`, `Live Captions`, `Narrator`, `Magnifier`, `OSK` etc. (`SystemSettings > Accessibility`/`Control Panel > All Control Panel Items > Ease of Access Center`). Specific features can be enabled via the suboptions.

## Suboptions

| Suboption | Description |
| --- | --- |
| Audio Description | Hear descriptions of what's happening in videos (when available). |
| Dynamic Scrollbars | "Always show scrollbars", `On` dynamically hide them. |
| [Voice Access](https://support.microsoft.com/en-us/topic/use-voice-access-to-control-your-pc-author-text-with-your-voice-4dcd23ee-f1b9-4fd1-bacc-862ab611f55d) | Modern voice command feature to help you interact with your PC and dictate text. |
| Live Captions | Audio and video will be captioned live on your screen. |
| Notification Box Visbility Time | Time how long the Windows notification boxes should stay opened. |
| Narrator | Narrator reads aloud any text on the screen. You will need speakers. |
| Sound Sentry | Visual notifications for sounds (this option chooses 'None' as visual warning). |
| Color Filters | "Use a color filter to make colors on your screen easier to see and differentiate." |
| Magnifier | Magnifier zooms in anywhere on the screen, and makes everything in that area larger. You can move Magnifier around, lock it in one place, or resize it. |
| On-Screen Keyboard | Tyoe using the mouse or another pointing device such as a joystick by selecting keys from a picture of a keyboard. |
| [Accessibility Insights Telemetry](https://github.com/microsoft/accessibility-insights-windows/blob/main/docs/TelemetryOverview.md#control-of-telemery) | "Accessibility Insights for Windows uses telemetry to better understand what features are most helpful to users, as well as to help identify potential issues that users are experiencing." |

## SystemSettings Captures

Based on `SystemSettings > Accessibility`, not complete yet.

```c
// Visual effects

  // Always show scrollbars
  // Enabled
  HKCU\Control Panel\Accessibility\DynamicScrollbars	Type: REG_DWORD, Length: 4, Data: 0
  // Disabled
  HKCU\Control Panel\Accessibility\DynamicScrollbars	Type: REG_DWORD, Length: 4, Data: 1

  // Transparency effects
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize\EnableTransparency	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize\EnableTransparency	Type: REG_DWORD, Length: 4, Data: 0

  // Animation effects (https://noverse.dev/docs/win-config/visibility/optimize-visual-effects/#userpreferencesmask)
  // Enabled
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 92 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 96 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 16 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 1E 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\WindowMetrics\MinAnimate	Type: REG_SZ, Length: 4, Data: 1
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 1E 07 80 12 00 00 00
  // Disabled
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9C 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 98 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 1A 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\WindowMetrics\MinAnimate	Type: REG_SZ, Length: 4, Data: 0
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 07 80 10 00 00 00

  // Dismiss notifications after this amount of time
  // 5 seconds
  HKCU\Control Panel\Accessibility\MessageDuration	Type: REG_DWORD, Length: 4, Data: 5
  // 5 minutes
  HKCU\Control Panel\Accessibility\MessageDuration	Type: REG_DWORD, Length: 4, Data: 300

// Mouse pointer and touch

  // Size
  // 1 (min)
  HKCU\Software\Microsoft\Accessibility\CursorSize	Type: REG_DWORD, Length: 4, Data: 1
  // 15 (max)
  HKCU\Software\Microsoft\Accessibility\CursorSize	Type: REG_DWORD, Length: 4, Data: 15

  // Touch indicator
  // Enabled
  HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 1
  HKCU\Control Panel\Cursors\GestureVisualization	Type: REG_DWORD, Length: 4, Data: 31
    // Make the circle darker and larger
    HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 2
  // Disabled
  HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 0
  HKCU\Control Panel\Cursors\GestureVisualization	Type: REG_DWORD, Length: 4, Data: 2

// Text cursor

  // Text cursor indicator
  // Enabled
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 32, Data: cursorindicator
  // Disabled
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 2, Data: 

  // Text cursor thickness
  // 1 (min)
  HKCU\Control Panel\Desktop\CaretWidth	Type: REG_DWORD, Length: 4, Data: 1
  // 20 (max)
  HKCU\Control Panel\Desktop\CaretWidth	Type: REG_DWORD, Length: 4, Data: 20

// Magnifier

  // Zoom level
  // 100%
  HKCU\Software\Microsoft\ScreenMagnifier\Magnification	Type: REG_DWORD, Length: 4, Data: 100
  // 500%
  HKCU\Software\Microsoft\ScreenMagnifier\Magnification	Type: REG_DWORD, Length: 4, Data: 500

  // Zoom increment
  // 5%
  HKCU\Software\Microsoft\ScreenMagnifier\ZoomIncrement	Type: REG_DWORD, Length: 4, Data: 5
  // 400%
  HKCU\Software\Microsoft\ScreenMagnifier\ZoomIncrement	Type: REG_DWORD, Length: 4, Data: 400

  // View
  // Docked
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 1
    // Have Magnifier follow my (Docked & Full screen only), these are just bools
    // Mouse pointer
    HKCU\Software\Microsoft\ScreenMagnifier\FollowMouse	Type: REG_DWORD, Length: 4, Data: 0
    // Keyboard focus
    HKCU\Software\Microsoft\ScreenMagnifier\FollowFocus	Type: REG_DWORD, Length: 4, Data: 0
    // Text cursor
    HKCU\Software\Microsoft\ScreenMagnifier\FollowCaret	Type: REG_DWORD, Length: 4, Data: 0
    // Narrator cursor
    HKCU\Software\Microsoft\ScreenMagnifier\FollowNarrator	Type: REG_DWORD, Length: 4, Data: 0
  
  // Full screen
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 2
    // Keep the mouse pointer
    // Within the edges of the screen
    HKCU\Software\Microsoft\ScreenMagnifier\FullScreenTrackingMode	Type: REG_DWORD, Length: 4, Data: 0
    // Centered on the screen
    HKCU\Software\Microsoft\ScreenMagnifier\FullScreenTrackingMode	Type: REG_DWORD, Length: 4, Data: 1

    // Keep the text cursor
    // Within the edges of the screen
    HKCU\Software\Microsoft\ScreenMagnifier\CenterTextInsertionPoint	Type: REG_DWORD, Length: 4, Data: 0
    // Centered on the screen
    HKCU\Software\Microsoft\ScreenMagnifier\CenterTextInsertionPoint	Type: REG_DWORD, Length: 4, Data: 1

  // Lens
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 3
    // Change lens size
    // Height (in 10 steps)
    // 10 (min)
    HKCU\Software\Microsoft\ScreenMagnifier\LensHeight	Type: REG_DWORD, Length: 4, Data: 10
    // 100 (max)
    HKCU\Software\Microsoft\ScreenMagnifier\LensHeight	Type: REG_DWORD, Length: 4, Data: 100

    // Width (in 10 steps)
    // 10 (min)
    HKCU\Software\Microsoft\ScreenMagnifier\LensWidth	Type: REG_DWORD, Length: 4, Data: 10
    // 100 (max)
    HKCU\Software\Microsoft\ScreenMagnifier\LensWidth	Type: REG_DWORD, Length: 4, Data: 100

  // Invert colors
  // Enabled
  HKCU\Software\Microsoft\ScreenMagnifier\Invert	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ScreenMagnifier\Invert	Type: REG_DWORD, Length: 4, Data: 0
  
  // Smooth edges of images and text
  // Enabled
  HKCU\Software\Microsoft\ScreenMagnifier\UseBitmapSmoothing	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ScreenMagnifier\UseBitmapSmoothing	Type: REG_DWORD, Length: 4, Data: 0

  // Reading shortcut
  // Ctrl + Alt
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 1
  // Caps Lock
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 2
  // Insert
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 4
  // Caps Lock or Insert
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 6

// Color filters

  // Color filters
  // Enabled
  HKCU\Software\Microsoft\ColorFiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 30, Data: colorfiltering
    // Red-green
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3

    // Red-green
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Blue-yellow
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Grayscale
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Grayscale inverted
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2

    // Inverted
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1

  // Disabled
  HKCU\Software\Microsoft\ColorFiltering\Active	Type: REG_DWORD, Length: 4, Data: 0
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 2, Data: 

  // Keyboard shortcut for color filters
  // Enabled
  HKCU\Software\Microsoft\ColorFiltering\HotkeyEnabled	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ColorFiltering\HotkeyEnabled	Type: REG_DWORD, Length: 4, Data: 0

// Audio

  // Mono audio
  // Enabled
  HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 0

  // Flash my screen during audio notifications
  // Never
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 0
  // Flash the title bar of the active window
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 1
  // Flash the active window
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 2
  // Flash the entire screen
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 3

// Keyboard

  // Sticky keys, this is a bitmask
  // Enabled
  HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 1
    // Keyboard shortcut for Sticky keys (bit 2)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 4
    // Show the Sticky keys icon on the taskbar (bit 5)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 32
    // Lock shortcut keys when pressed twice in a row (bit 7)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 8, Data: 128
    // Turn of Sticky keys when two keys are pressed at the same time (bit 8)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 8, Data: 256
    // Play a sound when shortcut keys are pressed and released (bit 6)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 64
  // Disabled
  HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Filter keys, also a bitmask
  // Enabled
  HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 1
    // Keboard shortcut for Filter keys (bit 2)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 4
    // Show the Filter keys icon on the taskbar (bit 5)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 32
    // Beep when keys are pressed or accepted (bit 6)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 64
    // Ignore quick keystrokes (slow keys)
      // 0.0 seconds (off)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 0
      // 0.3 seconds (min)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 300
      HKCU\Software\Microsoft\Osk\LastKeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 300
      // 20.0 seconds (max)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 20000
      HKCU\Software\Microsoft\Osk\LastKeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 20000
    // Ignore unintended keystrokes (bounce keys)
      // 0.0 seconds (off)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 0
      // 0.3 seconds (min)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 300
      HKCU\Software\Microsoft\Osk\LastBounceTime	Type: REG_DWORD, Length: 4, Data: 300
      // 2.0 seconds (max)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 2000
      HKCU\Software\Microsoft\Osk\LastBounceTime	Type: REG_DWORD, Length: 4, Data: 2000
    // Ignore repeated keystrokes (repeated keys)
      // Wait before accepting the first repeatable keystroke
        // 0.0 seconds (off)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        // 0.3 seconds (min)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        // 2.0 seconds (max)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
      // Wait before accepting subsequent repeated keystrokes
        // 0.0 seconds (off)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        // 0.3 seconds (min)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        // 2.0 seconds (max)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
  // Disabled
  HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Toggle keys
  // Enabled
  HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 1
  // Disabled
  HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Notification preferences
    // Nofify me when I turn on Sticky, Filter, or Toggle keys from the keyboard
    // Enabled (bit 3)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\Warning Sounds	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\Warning Sounds	Type: REG_DWORD, Length: 4, Data: 0

    // Play a sound when I turn Sticky, Filter, or Toggle keys on or off from the keyboard
    // Enabled (bit 4)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\Sound on Activation	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\Sound on Activation	Type: REG_DWORD, Length: 4, Data: 0

  // Underline access keys
  // Enabled
  HKCU\Control Panel\Accessibility\Keyboard Preference\On	Type: REG_SZ, Length: 4, Data: 1
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: B0 12 03 80 10 00 00 00
  // Disabled
  HKCU\Control Panel\Accessibility\Keyboard Preference\On	Type: REG_SZ, Length: 4, Data: 0
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 03 80 10 00 00 00

  // Use the Print screen key to open screen capture
  // Enabled
  HKCU\Control Panel\Keyboard\PrintScreenKeyForSnippingEnabled	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Control Panel\Keyboard\PrintScreenKeyForSnippingEnabled	Type: REG_DWORD, Length: 4, Data: 0

// Mouse

  // Mouse keys (bitmask again)
  // Enabled
  HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159
    // Only use mouse keys when Num lock is on (bit 7)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 6, Data: 31
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Show the mouse keys icon on the taskbar (bit 5)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 191
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Hold the Ctrl key to speed up and the Shift key to slow down (bit 6)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 223
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Mouse keys speed
    // 1 (min)
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 6, Data: 10
    // 50
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 182
    // 75
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 266
    // 100 (max)
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 358

    // Mouse keys acceleration
    // 1 (min)
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 5000
    // 50
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 3040
    // 75
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 2000
    // 100 (max)
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 1000
  // Disabled
  HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 158
```

# Disable Windows Search

Windows search provides content indexing, property caching, and search results for files, e-mail, and other content. Instead of using the explorer/windows start menu to search for a file/folder/app, use [`Everything`](https://www.voidtools.com/downloads/) for searching for files/folders and [SAB](https://www.startallback.com/) ([manual SAB activation](https://noverse.dev/docs/win-config/misc/startallback-config/#sab-activation)) as start menu. Note that enabling this option breaks the start menu, and apps like e.g. CmdPal (PowerToys) do need the `WSearch` service for the `File Search` extension to work.

### Search Indexing

[Search indexing](https://learn.microsoft.com/en-us/windows/win32/search/-search-indexing-process-overview) builds a database of file names, properties, and contents to speed up searches, runs as `SearchIndexer.exe`, updates automatically. Disabling it slows down searches, but as shows below you should use everything anyway. Additionally you can disable content and property indexing per drive, by right clicking on the drive, then unticking the box as shown in the picture:

![](https://github.com/nohuto/win-config/blob/main/system/images/searchindex.png?raw=true)

## Suboptions

| Suboption | Description |
| ---- | ---- |
| Disable SafeSearch | Disables the SafeSearch filter for web search, preventing strict filtering of search results. |
| Prevent Index on Battery | Prevents Windows from indexing content while running on battery power, saving system resources. |
| Disable Index Usage for System File Search | Disables the use of the index when searching system files, requiring a full scan each time. |
| Find Partial Matches | Allows partial matches to be found when searching for files, enabling more flexible search results. |
| Exclude System Directories | Excludes system directories from search results, narrowing down the search to user files and folders. |
| Exclude Archived Files | Prevents archived files from being included in search results. |
| Disable Natural Language Search | Disables the use of natural language search, which allows more conversational queries for search results. |
| Search Only in Indexed Locations | Restricts searches in non-indexed locations to only file names, rather than searching both names and contents. |
| Exclude System Directories | Excludes system directories (e.g., Windows folders) in search results when searching non-indexed locations. |
| Exclude Compressed Files | Excludes compressed files (e.g., ZIP, CAB) in search results when searching non-indexed locations. |
| Search Only in Indexed Locations | Disables: "Ensures that file names and contents are always searched in non-indexed locations, which may take more time." |
| [Disallow Indexing of Encrypted Items](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-search#allowindexingencryptedstoresoritems) | This policy setting allows encrypted items to be indexed. |
| [Disable Language Detection](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-search#alwaysuseautolangdetection) | This policy setting determines when Windows uses automatic language detection results, and when it relies on indexing history. |
| [Prevent Querying Index Remotely](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-search#preventremotequeries) | If enabled, clients will be unable to query this computer's index remotely. Thus, when they're browsing network shares that are stored on this computer, they won't search them using the index. If disabled, client search requests will use this computer's index. |
| [Disable Web Results in Search](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-search#donotusewebresults) | This policy setting allows you to control whether or not Search can perform queries on the web, and if the web results are displayed in Search. |
| Disable Search Highlights | If enabled: "See content suggestions in the search boxi and in search home". |
| Disable Web Search | If disabled: "removes the option of searching the Web from Windows Desktop Search". |
| Hide Most Used Apps | ![](https://github.com/nohuto/win-config/blob/main/system/images/mostused.jpg?raw=true) |
| Hide Recently Added Apps | |
| Hide Frequently Used Apps | |
| Hide New App Notifications | |
| Start Layout | ![](https://github.com/nohuto/win-config/blob/main/system/images/start-layout.png?raw=true) |

## Miscellaneous Notes

Exists in [Search Policies](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-search), but isn't present anymore on 24H2 and probably versions above.

```c
// Disabling this setting turns off search highlights in the start menu search box and in search home. Enabling or not configuring this setting turns on search highlights in the start menu search box and in search home.
"Disable Search Highlights": {
  "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search": {
    "EnableDynamicContentInWSB": { "Type": "REG_DWORD", "Data": 0 }
  }
}
```

It probably got replaced by:
```c
// Privacy & security > Search - Show search highlights
HKCU\Software\Microsoft\Windows\CurrentVersion\SearchSettings\IsDynamicSearchBoxEnabled	Type: REG_DWORD, Length: 4, Data: 0
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Prevent clients from querying the index remotely](https://noverse.dev/policies?p=Search*PreventRemoteQueries) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `PreventRemoteQueries` |
| [Prevent indexing when running on battery power to conserve energy](https://noverse.dev/policies?p=Search*PreventIndexOnBattery) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `PreventIndexOnBattery` |
| [Always use automatic language detection when indexing content and properties](https://noverse.dev/policies?p=Search*AlwaysUseAutoLangDetection) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AlwaysUseAutoLangDetection` |
| [Don't search the web or display web results in Search](https://noverse.dev/policies?p=Search*DoNotUseWebResults) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `ConnectedSearchUseWeb` |
| [Don't search the web or display web results in Search over metered connections](https://noverse.dev/policies?p=Search*DoNotUseWebResultsOnMeteredConnections) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `ConnectedSearchUseWebOverMeteredConnections` |
| [Do not allow web search](https://noverse.dev/policies?p=Search*DisableWebSearch) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `DisableWebSearch` |
| [Set the SafeSearch setting for Search](https://noverse.dev/policies?p=Search*SafeSearch) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `ConnectedSearchSafeSearch` |
| [Do not allow locations on removable drives to be added to libraries](https://noverse.dev/policies?p=Search*DisableRemovableDriveIndexing) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `DisableRemovableDriveIndexing` |
| [Fully disable Search UI](https://noverse.dev/policies?p=Search*DisableSearch) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `DisableSearch` |
| [Show or hide "Most used" list from Start menu](https://noverse.dev/policies?p=StartMenu*ShowOrHideMostUsedApps) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `ShowOrHideMostUsedApps` |
| [Remove frequent programs list from the Start Menu](https://noverse.dev/policies?p=StartMenu*NoFrequentUsedPrograms) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`<br>`HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoStartMenuMFUprogramsList` |
| [Turn off user tracking](https://noverse.dev/policies?p=StartMenu*NoInstrumentation) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoInstrumentation` |
| [Remove "Recently added" list from Start Menu](https://noverse.dev/policies?p=StartMenu*HideRecentlyAddedApps) | `HKLM\Software\Policies\Microsoft\Windows\Explorer`<br>`HKCU\Software\Policies\Microsoft\Windows\Explorer` | `HideRecentlyAddedApps` |
| [Do not show the 'new application installed' notification](https://noverse.dev/policies?p=WindowsExplorer*NoNewAppAlert) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `NoNewAppAlert` |

# Enable FSO

Will be updated within the next weeks (date of commit 20.05.2026)

### ResourcePolicyServer

Values found that are `GameDVR` related in `ResourcePolicyServer.dll`:

```c
GameDVR_DXGIHonorFSEWindowsCompatible
GameDVR_EFSEFeatureFlags
GameDVR_FSEBehavior
GameDVR_FSEBehaviorMode
GameDVR_HonorUserFSEBehaviorMode
```

`GameDVR_DSEBehavior` does not exist on the current system.

### Compatibility Flags

The Compatibility UI option `Disable fullscreen optimizations` writes an application compatibility layer value. This can exist per-user or machine-wide.

```c
// User
HKCU\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\<exe path> = "~ DISABLEDXMAXIMIZEDWINDOWEDMODE"

// Machine
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers\<exe path> = "~ DISABLEDXMAXIMIZEDWINDOWEDMODE"
```

# Time Zone

| ID                              | Display Name                                                  | ID                              | Display Name                                              |
| ------------------------------- | ------------------------------------------------------------- | ------------------------------- | --------------------------------------------------------- |
| Afghanistan Standard Time       | (UTC+04:30) Kabul                                             | Alaskan Standard Time           | (UTC-09:00) Alaska                                        |
| Aleutian Standard Time          | (UTC-10:00) Aleutian Islands                                  | Altai Standard Time             | (UTC+07:00) Barnaul, Gorno-Altaysk                        |
| Arab Standard Time              | (UTC+03:00) Kuwait, Riyadh                                    | Arabian Standard Time           | (UTC+04:00) Abu Dhabi, Muscat                             |
| Arabic Standard Time            | (UTC+03:00) Baghdad                                           | Argentina Standard Time         | (UTC-03:00) City of Buenos Aires                          |
| Astrakhan Standard Time         | (UTC+04:00) Astrakhan, Ulyanovsk                              | Atlantic Standard Time          | (UTC-04:00) Atlantic Time (Canada)                        |
| AUS Central Standard Time       | (UTC+09:30) Darwin                                            | Aus Central W. Standard Time    | (UTC+08:45) Eucla                                         |
| AUS Eastern Standard Time       | (UTC+10:00) Canberra, Melbourne, Sydney                       | Azerbaijan Standard Time        | (UTC+04:00) Baku                                          |
| Azores Standard Time            | (UTC-01:00) Azores                                            | Bahia Standard Time             | (UTC-03:00) Salvador                                      |
| Bangladesh Standard Time        | (UTC+06:00) Dhaka                                             | Belarus Standard Time           | (UTC+03:00) Minsk                                         |
| Bougainville Standard Time      | (UTC+11:00) Bougainville Island                               | Canada Central Standard Time    | (UTC-06:00) Saskatchewan                                  |
| Cape Verde Standard Time        | (UTC-01:00) Cabo Verde Is.                                    | Caucasus Standard Time          | (UTC+04:00) Yerevan                                       |
| Cen. Australia Standard Time    | (UTC+09:30) Adelaide                                          | Central America Standard Time   | (UTC-06:00) Central America                               |
| Central Asia Standard Time      | (UTC+06:00) Nur-Sultan                                        | Central Brazilian Standard Time | (UTC-04:00) Cuiaba                                        |
| Central Europe Standard Time    | (UTC+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague | Central European Standard Time  | (UTC+01:00) Sarajevo, Skopje, Warsaw, Zagreb              |
| Central Pacific Standard Time   | (UTC+11:00) Solomon Is., New Caledonia                        | Central Standard Time           | (UTC-06:00) Central Time (US & Canada)                    |
| Central Standard Time (Mexico)  | (UTC-06:00) Guadalajara, Mexico City, Monterrey               | Chatham Islands Standard Time   | (UTC+12:45) Chatham Islands                               |
| China Standard Time             | (UTC+08:00) Beijing, Chongqing, Hong Kong, Urumqi             | Cuba Standard Time              | (UTC-05:00) Havana                                        |
| Dateline Standard Time          | (UTC-12:00) International Date Line West                      | E. Africa Standard Time         | (UTC+03:00) Nairobi                                       |
| E. Australia Standard Time      | (UTC+10:00) Brisbane                                          | E. Europe Standard Time         | (UTC+02:00) Chisinau                                      |
| E. South America Standard Time  | (UTC-03:00) Brasilia                                          | Easter Island Standard Time     | (UTC-06:00) Easter Island                                 |
| Eastern Standard Time           | (UTC-05:00) Eastern Time (US & Canada)                        | Eastern Standard Time (Mexico)  | (UTC-05:00) Chetumal                                      |
| Egypt Standard Time             | (UTC+02:00) Cairo                                             | Ekaterinburg Standard Time      | (UTC+05:00) Ekaterinburg                                  |
| Fiji Standard Time              | (UTC+12:00) Fiji                                              | FLE Standard Time               | (UTC+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius |
| Georgian Standard Time          | (UTC+04:00) Tbilisi                                           | GMT Standard Time               | (UTC+00:00) Dublin, Edinburgh, Lisbon, London             |
| Greenland Standard Time         | (UTC-02:00) Greenland                                         | Greenwich Standard Time         | (UTC+00:00) Monrovia, Reykjavik                           |
| GTB Standard Time               | (UTC+02:00) Athens, Bucharest                                 | Haiti Standard Time             | (UTC-05:00) Haiti                                         |
| Hawaiian Standard Time          | (UTC-10:00) Hawaii                                            | India Standard Time             | (UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi           |
| Iran Standard Time              | (UTC+03:30) Tehran                                            | Israel Standard Time            | (UTC+02:00) Jerusalem                                     |
| Jordan Standard Time            | (UTC+03:00) Amman                                             | Kaliningrad Standard Time       | (UTC+02:00) Kaliningrad                                   |
| Kamchatka Standard Time         | (UTC+12:00) Petropavlovsk-Kamchatsky - Old                    | Korea Standard Time             | (UTC+09:00) Seoul                                         |
| Libya Standard Time             | (UTC+02:00) Tripoli                                           | Line Islands Standard Time      | (UTC+14:00) Kiritimati Island                             |
| Lord Howe Standard Time         | (UTC+10:30) Lord Howe Island                                  | Magadan Standard Time           | (UTC+11:00) Magadan                                       |
| Magallanes Standard Time        | (UTC-03:00) Punta Arenas                                      | Marquesas Standard Time         | (UTC-09:30) Marquesas Islands                             |
| Mauritius Standard Time         | (UTC+04:00) Port Louis                                        | Mid-Atlantic Standard Time      | (UTC-02:00) Mid-Atlantic - Old                            |
| Middle East Standard Time       | (UTC+02:00) Beirut                                            | Montevideo Standard Time        | (UTC-03:00) Montevideo                                    |
| Morocco Standard Time           | (UTC+01:00) Casablanca                                        | Mountain Standard Time          | (UTC-07:00) Mountain Time (US & Canada)                   |
| Mountain Standard Time (Mexico) | (UTC-07:00) La Paz, Mazatlan                                  | Myanmar Standard Time           | (UTC+06:30) Yangon (Rangoon)                              |
| N. Central Asia Standard Time   | (UTC+07:00) Novosibirsk                                       | Namibia Standard Time           | (UTC+02:00) Windhoek                                      |
| Nepal Standard Time             | (UTC+05:45) Kathmandu                                         | New Zealand Standard Time       | (UTC+12:00) Auckland, Wellington                          |
| Newfoundland Standard Time      | (UTC-03:30) Newfoundland                                      | Norfolk Standard Time           | (UTC+11:00) Norfolk Island                                |
| North Asia East Standard Time   | (UTC+08:00) Irkutsk                                           | North Asia Standard Time        | (UTC+07:00) Krasnoyarsk                                   |
| North Korea Standard Time       | (UTC+09:00) Pyongyang                                         | Omsk Standard Time              | (UTC+06:00) Omsk                                          |
| Pacific SA Standard Time        | (UTC-04:00) Santiago                                          | Pacific Standard Time           | (UTC-08:00) Pacific Time (US & Canada)                    |
| Pacific Standard Time (Mexico)  | (UTC-08:00) Baja California                                   | Pakistan Standard Time          | (UTC+05:00) Islamabad, Karachi                            |
| Paraguay Standard Time          | (UTC-04:00) Asuncion                                          | Qyzylorda Standard Time         | (UTC+05:00) Qyzylorda                                     |
| Romance Standard Time           | (UTC+01:00) Brussels, Copenhagen, Madrid, Paris               | Russia Time Zone 10             | (UTC+11:00) Chokurdakh                                    |
| Russia Time Zone 11             | (UTC+12:00) Anadyr, Petropavlovsk-Kamchatsky                  | Russia Time Zone 3              | (UTC+04:00) Izhevsk, Samara                               |
| Russian Standard Time           | (UTC+03:00) Moscow, St. Petersburg                            | SA Eastern Standard Time        | (UTC-03:00) Cayenne, Fortaleza                            |
| SA Pacific Standard Time        | (UTC-05:00) Bogota, Lima, Quito, Rio Branco                   | SA Western Standard Time        | (UTC-04:00) Georgetown, La Paz, Manaus, San Juan          |
| Sakhalin Standard Time          | (UTC+11:00) Sakhalin                                          | Saint Pierre Standard Time      | (UTC-03:00) Saint Pierre and Miquelon                     |
| Samoa Standard Time             | (UTC+13:00) Samoa                                             | Sao Tome Standard Time          | (UTC+00:00) Sao Tome                                      |
| Saratov Standard Time           | (UTC+04:00) Saratov                                           | SE Asia Standard Time           | (UTC+07:00) Bangkok, Hanoi, Jakarta                       |
| Singapore Standard Time         | (UTC+08:00) Kuala Lumpur, Singapore                           | South Africa Standard Time      | (UTC+02:00) Harare, Pretoria                              |
| South Sudan Standard Time       | (UTC+02:00) Juba                                              | Sri Lanka Standard Time         | (UTC+05:30) Sri Jayawardenepura                           |
| Sudan Standard Time             | (UTC+02:00) Khartoum                                          | Syria Standard Time             | (UTC+03:00) Damascus                                      |
| Taipei Standard Time            | (UTC+08:00) Taipei                                            | Tasmania Standard Time          | (UTC+10:00) Hobart                                        |
| Tocantins Standard Time         | (UTC-03:00) Araguaina                                         | Tokyo Standard Time             | (UTC+09:00) Osaka, Sapporo, Tokyo                         |
| Tomsk Standard Time             | (UTC+07:00) Tomsk                                             | Tonga Standard Time             | (UTC+13:00) Nuku'alofa                                    |
| Transbaikal Standard Time       | (UTC+09:00) Chita                                             | Turkey Standard Time            | (UTC+03:00) Istanbul                                      |
| Turks And Caicos Standard Time  | (UTC-05:00) Turks and Caicos                                  | Ulaanbaatar Standard Time       | (UTC+08:00) Ulaanbaatar                                   |
| US Eastern Standard Time        | (UTC-05:00) Indiana (East)                                    | US Mountain Standard Time       | (UTC-07:00) Arizona                                       |
| UTC                             | (UTC) Coordinated Universal Time                              | UTC+12                          | (UTC+12:00) Coordinated Universal Time+12                 |
| UTC+13                          | (UTC+13:00) Coordinated Universal Time+13                     | UTC-02                          | (UTC-02:00) Coordinated Universal Time-02                 |
| UTC-08                          | (UTC-08:00) Coordinated Universal Time-08                     | UTC-09                          | (UTC-09:00) Coordinated Universal Time-09                 |
| UTC-11                          | (UTC-11:00) Coordinated Universal Time-11                     | Venezuela Standard Time         | (UTC-04:00) Caracas                                       |
| Vladivostok Standard Time       | (UTC+10:00) Vladivostok                                       | Volgograd Standard Time         | (UTC+03:00) Volgograd                                     |
| W. Australia Standard Time      | (UTC+08:00) Perth                                             | W. Central Africa Standard Time | (UTC+01:00) West Central Africa                           |
| W. Europe Standard Time         | (UTC+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna  | W. Mongolia Standard Time       | (UTC+07:00) Hovd                                          |
| West Asia Standard Time         | (UTC+05:00) Ashgabat, Tashkent                                | West Bank Standard Time         | (UTC+02:00) Gaza, Hebron                                  |
| West Pacific Standard Time      | (UTC+10:00) Guam, Port Moresby                                | Yakutsk Standard Time           | (UTC+09:00) Yakutsk                                       |
| Yukon Standard Time             | (UTC-07:00) Yukon                                             |                                 |                                                           |

Get a list of available timezones with more detail via:
```powershell
Get-TimeZone -ListAvailable
```

# Display Scaling

Changes the size of text, apps, and other items. Note that on laptops the default display scaling might not be `100%`. You can set a custom scaling size via `System > Display > Custom scaling`:

![](https://github.com/nohuto/win-config/blob/main/system/images/displayscaling.png?raw=true)

### SystemSettings Captures

```c
// 100%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 0

// 125%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 1

// 150%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 2
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 2

// 175%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 3
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 3

// 200%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 4
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 4

// 225%
HKLM\System\CurrentControlSet\Control\GraphicsDrivers\ScaleFactors\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 5
HKCU\Control Panel\Desktop\PerMonitorSettings\<MONITORID>\DpiValue	Type: REG_DWORD, Length: 4, Data: 5
```

## Suboptions

### Prevent Window Minimization on Monitor Disconnection

```c
// System > Display : Minimize windows when a monitor is disconnected

// Enabled
HKCU\Control Panel\Desktop\MonitorRemovalRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 0

// Disabled
HKCU\Control Panel\Desktop\MonitorRemovalRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 1
```

### Forget Window Locations for Connected Monitors

```c
// System > Display : Remember windows locations based on monitor connection

// Enabled
HKCU\Control Panel\Desktop\RestorePreviousStateRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 0

// Disabled
HKCU\Control Panel\Desktop\RestorePreviousStateRecalcBehavior	Type: REG_DWORD, Length: 4, Data: 1
```

# Disable Hung Screen

Causes hung apps to get automatically get terminated, making the 'Hung program' screen to not show up. It's recommended to leave the timeouts at their default, see 'Windows Internals' section below for more details on each value.

![](https://github.com/nohuto/win-config/blob/main/system/images/hung-program.png?raw=true)

### Registry Values

Windows Internals says that the default of `WaitToKillServiceTimeout` is `20000` ("*The SCM's timeout value in milliseconds resides in the HKLM\SYSTEM\CurrentControlSet\Control\WaitToKillServiceTimeout registry value, and it defaults to 20 seconds.*"), while the value exists by default on W11 with the data of `5000`, when looking at the win32kbase driver it also shows a default of `5000`.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control";
    "WaitToKillServiceTimeout" = 5000; // REG_SZ (ms), SCM timeout used by CSRSS while the SCM notifies services and waits for service cleanup

"HKCU\\Control Panel\\Desktop";
    "WaitToKillTimeout" = 5000; // REG_SZ (ms), time CSRSS waits for a console control handler/process to exit before showing the hung program screen
    "HungAppTimeout" = 5000; // REG_SZ (ms), time CSRSS waits for a GUI thread/process to exit after shutdown messages before seeing it as hung
    "AutoEndTasks" = 0; // REG_SZ (ms), 1 disables the 'Hung program' screen
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown3.png?raw=true)

# Detailed Status Messages

Enables detailed messages at restart, shut down, sign out, and sign in, e.g.: "*RPCSS is starting...*" or "*Waiting for machine group policies to finish...*".

> "*This policy setting directs the system to display highly detailed status messages.*
>
> *This policy setting is designed for advanced users who require this information.*
>
> *If you enable this policy setting, the system displays status messages that reflect each step in the process of starting, shutting down, logging on, or logging off the system.*
>
> *If you disable or do not configure this policy setting, only the default status messages are displayed to the user during these processes.*
>
> *Note: This policy setting is ignored if the ""Remove Boot/Shutdown/Logon/Logoff status messages"" policy setting is enabled.*

If this option is disabled you'll still see normal messages like "*Applying your personal settings...*" or "*Applying computer settings...*".

## Suboptions

### Detailed BSoD

As the value name already says (`DisplayParameters`) it will just show additional paramters on the top left.

#### Enabled

![](https://github.com/nohuto/win-config/blob/main/system/images/detailed-bsod.jpg?raw=true)

#### Disabled

![](https://github.com/nohuto/win-config/blob/main/system/images/default-bsod.jpg?raw=true)

Enabling the options includes setting [`AutoReboot`](https://learn.microsoft.com/en-us/troubleshoot/windows-client/performance/configure-system-failure-and-recovery-options) to `0`, to prevent auto restarting.

### BsOD Smiley

Hides the smiley which is shown on the BsOD screen:

![](https://github.com/nohuto/win-config/blob/main/system/images/BSOD-smiley.png?raw=true)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Display highly detailed status messages](https://noverse.dev/policies?p=Logon*VerboseStatus) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\System` | `VerboseStatus` |

# Disable Autoruns

The `Open` buttons downloads & executes [`Autoruns`](https://learn.microsoft.com/en-us/sysinternals/downloads/autoruns). It's recommended to disable all kind of autoruns in the `Logon` section that you don't need, examples:
```c
OneDrive
Spotify
Discord
Steam
WingetUI
Lghub
SecurityHealth

Microsoft Edge // preferable remove edge from the mounted image, otherwise it'll create keys/values in many different places
```

Try to minimize the amount of applications that run automatically on system startup. You can go through the other sections, but this option was created for the `Logon` section, see `Disable Scheduled Tasks`/`Disable Services`.

See your current autoruns of installed apps:
```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\Run
```
```powershell
HKLM\Software\Microsoft\Windows\CurrentVersion\Run
```

## Suboption

### App Archive

"Automatically archive your infrequently used apps to save storage and internet bandwidth. Your files and data will still be saved, and the app's full version will be restored on your next use if it's still available."

If enabled, the system will periodically check for such infrequently used apps. By default app archiving is turned on.

#### SystemSettings Records

Toggling the option via `Apps > Advanced app settings`:
```c
// On
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\InstallService\Stubification\S-{ID}\EnableAppOffloading    Type: REG_DWORD, Length: 4, Data: 1

// Off
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\InstallService\Stubification\S-{ID}\EnableAppOffloading    Type: REG_DWORD, Length: 4, Data: 0
```

#### [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Archive infrequently used apps](https://noverse.dev/policies?p=AppxPackageManager*AllowAutomaticAppArchiving) | `HKLM\Software\Policies\Microsoft\Windows\Appx` | `AllowAutomaticAppArchiving` |

# Export Explorer/Taskbar Pins

Can be useful when creating your own image and trying to automate the installation and configuration part.

### Quick Access Pins

Quick access pins are saved in a file named `f01b4d95cf55d32a.automaticDestinations-ms`, located at:
```bat
%appdata%\Microsoft\Windows\Recent\AutomaticDestinations
```
You can either terminate `explorer` while copying it to the path, or just restart it afterwards.
```bat
copy /y ".\f01b4d95cf55d32a.automaticDestinations-ms" "%appdata%\Microsoft\Windows\Recent\AutomaticDestinations"
```

### Taskbar Pins

Taskbar pins are saved in a folder and a key, the folder includes the shortcuts:
```bat
%appdata%\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar
```
```powershell
HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Taskband # Only "Favorites" is needed
```

Post install example (copy the `TaskBar` folder to any folder):
```powershell
del "$env:appdata\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar" -Recurse -Force
xcopy ".\TaskBar" "%appdata%\Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar" /e /i /y
```

The option gets current values of `Favorites` (taskbar pins) & `UIOrderList` (system tray icons) and copies all necessary files to `$home\Desktop` (edit `$dest` & `$bat` to whatever you want).

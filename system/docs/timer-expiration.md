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

`SerializeTimerExpiration` gets read in [`KeInitializeTimerTable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitializeTimerTable.c):

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

The callback used for the auto default gets set in [`HalpSetPlatformFlags`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/HalpSetPlatformFlags.c):

```c
// HalpSetPlatformFlags

off_140C01C70[0] = (__int64 (__fastcall *)())HalpAcpiAoacCapable; // default used above
if ( (*(_DWORD *)(a1 + 112) & 0x200000) != 0 ) // 0x200000 = bit 21
  HalpPlatformFlags |= 8u; // HAL flag set from FADT bit 21
```

[`HalpAcpiAoacCapable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/HalpAcpiAoacCapable.c) returns `(HalpPlatformFlags & 8) != 0`, which is FADT flag bit 21:

> "*LOW_POWER_S0_IDLE_CAPABLE*
> *Bit offset 21. Indicates that the platform supports low-power idle states within the ACPI S0 system power state that are more energy efficient than any Sx sleep state. If this flag is set, Windows won't try to sleep and resume, but will instead use platform idle states and connected standby.*"
>
> — Microsoft, [Fixed ACPI Description Table (FADT)](https://learn.microsoft.com/en-us/windows-hardware/drivers/bringup/acpi-system-description-tables#fixed-acpi-description-table-fadt)

### ActiveTimerTable

Serialized expiration uses CPU 0 timer table (`KiProcessorBlock[0]`) instead of the current processors timer table ([`KiTimerExpirationDpc`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiTimerExpirationDpc.c) & [`KiCheckForTimerExpiration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KiCheckForTimerExpiration.c) work the same), non serialized uses the current PRCB timer table.

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

[`KePrepareClockTimerForIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KePrepareClockTimerForIdle.c) is that idle part:

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

When the system leaves that idle state, [`KeResumeClockTimerFromIdle`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeResumeClockTimerFromIdle.c) resumes clock handling, if per CPU clock timers are supported (`KiClockTimerPerCpu`), this can make the selected CPU the clock owner:

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

`KiClockTimerPerCpu` is set whenever [`HalpTimerGetClockConfiguration`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/HalpTimerGetClockConfiguration.c) returns flag `0x4` (can't really tell yet what requirement that has, related to `HalpClockTimer` flag `0x1`?):

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

[`KeInitializeClock`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeInitializeClock.c) only checks `KiEnableClockTimerPerCpuTickScheduling` when `KiClockTimerPerCpu` is already true:

```c
// KeInitializeClock

if ( KiClockTimerPerCpu && KiSerializeTimerExpiration ) // SerializeTimerExpiration must be 1 here (as >=2 = 0 as shown above)
  KiClockTimerPerCpuTickScheduling = 1; // serialization enables per CPU clock tick scheduling
if ( KiEnableClockTimerPerCpuTickScheduling && KiClockTimerPerCpu )
  KiClockTimerPerCpuTickScheduling = KiEnableClockTimerPerCpuTickScheduling == 1; // override
```

[`KeClockInterruptNotify`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/KeClockInterruptNotify.c) has a branch for `KiClockTimerPerCpuTickScheduling && !KiSerializeTimerExpiration` (means `SerializeTimerExpiration = 0` on non AOAC platforms, or >= 2 & `EnablePerCpuClockTickScheduling = 1`), but I haven't looked into what it's used for yet.

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


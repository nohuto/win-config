# xHCI IMOD

The *xHCI Interrupter Moderation Register* sets the minimum time between interrupt messages from one xHCI Interrupter, note that each interrupter has its own [register set](https://noverse.dev/docs/win-config/power/xhci-imod/#registers) (including IMODI/IMODC).

> "*Interrupt Moderation allows multiple events to be processed in the context of a single Interrupt Service Request (ISR), rather than generating an ISR for each event.*
>
> *The interrupt generation that results from the assertion of the Interrupt Pending (IP) flag may be throttled by the settings of the Interrupter Moderation (IMOD) register of the associated Interrupter. The IMOD register consists of two 16 -bit fields: the Interrupt Moderation Counter (IMODC) and the Interrupt Moderation Interval (IMODI).*"
>
> — Intel, [eXtensible Host Controller Interface for Universal Serial Bus](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

## Interrupt Wait Time

`IMODI` is the interval, `IMODC` is the counter and each tick is 250 ns.

```c
max moderation = IMODI * 250 ns
remaining moderation wait = IMODC * 250 ns
```

> "*An Interrupter manages events and their notification to the host. The xHCI supports up to 1024 Interrupters. The MaxIntrs field in HCSPARAMS1 determines the Number of Interrupters implemented in the xHC. Each Interrupter consists of an Interrupter Management Register, an Interrupter Moderation Register and an Event Ring. Each Interrupter shall be mapped to a single MSI or MSI-X interrupt vector. An Interrupter shall assert an interrupt if it is enabled and its associated Event Ring contains Event TRBs that require an interrupt.*"
>
> — Intel, [eXtensible Host Controller Interface for Universal Serial Bus](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

Whenever `IP` is cleared, hardware loads `IMODC = IMODI` and counts down to zero and stays there until another interrupt reloads it. This causes for example the first event after an idle to be immediate, and an event that arrives while the counter is running to get the IMOD wait time. With the interval of 50 us (Windows default), an event 10 us after the previous interrupt would wait about 40 us, an event 80 us after the previous interrupt wouldn't wait, means:

```powershell
$ .\xhci_imod --no-write
[~] xHCI controller at PCI 02:00.0
    xHCI 1.10, register base 0x00000000FC700000
    Runtime base 0x00000000FC701000, 8 implemented, 8 initialized
[-] Interrupter 0: IMODI=200, IMODC=0 at 0x00000000FC701024 # IMODI = 200 ticks = 50 us
[-] Interrupter 1: IMODI=200, IMODC=0 at 0x00000000FC701044
[-] Interrupter 2: IMODI=200, IMODC=0 at 0x00000000FC701064
[-] Interrupter 3: IMODI=200, IMODC=0 at 0x00000000FC701084
[-] Interrupter 4: IMODI=200, IMODC=0 at 0x00000000FC7010A4
[-] Interrupter 5: IMODI=200, IMODC=0 at 0x00000000FC7010C4
[-] Interrupter 6: IMODI=200, IMODC=0 at 0x00000000FC7010E4
[-] Interrupter 7: IMODI=200, IMODC=0 at 0x00000000FC701104
```

| State | Result |
| --- | --- |
| `IMODC = 0`, `EHB = 0`, `IE = 1` | Interrupt sent immediately |
| `IMODC > 0`, `EHB = 0`, `IE = 1` | Event waits for the remaining counter time |
| `EHB = 1` | Existing DPC/work item owns the Event Ring, it can process new events without another interrupt |
| `IE = 0` | Interrupter cannot send an interrupt |

An event below in the figures = Event TRB written to an Event Ring, for a mouse/keyboard, a completed interrupt IN transfer normally creates such a Transfer Event TRB.

### Interrupt Throttle Flow

![](https://github.com/nohuto/win-config/blob/main/power/images/imod-flow.png?raw=true)

### Heavy Load

![](https://github.com/nohuto/win-config/blob/main/power/images/heavy-load-imod.png?raw=true)

> "*Under heavy load conditions (Figure 4-23), Interrupt Pending Enable (IPE) is asserted almost constantly, so if IPE = '1' when the IMODC counts down to '0' and the Event Handler is not busy (EHB = '0'), an interrupt is generated immediately, i.e. Interrupt Pending (IP) is set to '1'. When IP is asserted, the IMODC is reloaded with the IMODI and the IMODC begins counting down again.*
>
> *Thus, the next interrupt event will be delayed by the IMODI delay. Also note that in this example, the assertion of Interrupt Pending (IP) triggers the Interrupt Service Routine (ISR). The ISR schedules a Deferred Procedure Call (DPC) that will process the events on the Event Ring at a later time. The DPC processes events until Event Ring is empty then clears the Event Handler Busy (EHB) flag. Interrupt Pending Enable is cleared when the Event Ring goes empty, i.e. the DPC writes the Event Ring Dequeue Pointer (ERDP) register with a value that is equal to the Event Ring Enqueue Pointer.*"
>
> — Intel, [eXtensible Host Controller Interface for Universal Serial Bus](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

### Light Load

![](https://github.com/nohuto/win-config/blob/main/power/images/light-load-imod.png?raw=true)

> "*Under light load conditions (Figure 4-24) it is desirable to fire off interrupts with minimum latency. In this case, when the IMODC counts down to '0' and no interrupts are pending (IPE = '0'), the IMODC is not reloaded with the IMODI but stays at '0'. Thus, the next assertion of Interrupt Pending Enable will trigger an interrupt immediately. Triggering the interrupt will also cause the IMODC to be reloaded with the IMODI and begin counting down again.*
>
> *In the first case where the IMOD Delay Expires, Interrupt Pending (IP) is not set (so the ISR is not triggered) because the Event Ring is empty. Since IMODC = 0 when event 3 is posted, Interrupt Pending (IP) is asserted immediately.*
>
> *In the second case, Interrupt Pending (IP) is not set because the Event Handler is busy (EHB = '1'). The DPC was not able to empty the Event Ring the first time it was scheduled (i.e. it only processed event 3), so it rescheduled itself to process the remaining events in the ring (i.e. event 4). While waiting for the DPC to be scheduled, events 5, 6, and 7 are posted. The rescheduled DPC processes events until Event Ring is empty then clears the Event Handler Busy (EHB) flag, reenabling an immediate interrupt the next time an event is posted.*"
>
> — Intel, [eXtensible Host Controller Interface for Universal Serial Bus](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

## USBXHCI Pseudocode

![](https://github.com/nohuto/win-config/blob/main/power/images/usb-driver-stack.png?raw=true)

[`Interrupter_PrepareInterrupter`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBXHCI/Interrupter_PrepareInterrupter.c) gets the register set at `RuntimeBase + 0x20 + 0x20 * InterrupterId`, [`Interrupter_InterruptEnable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBXHCI/Interrupter_InterruptEnable.c) then writes decimal `200` to `IMOD` (low half of `0x000000C8` sets `IMODI = 200`, the high writes `IMODC` to zero) and enables `IMAN.IE`, W10 1507 - W11 26H1 all use `200`.

```c
// Interrupter_InterruptEnable (23H2)

v2 = (_DWORD *)(*(_QWORD *)(a1 + 24) + 4LL); // a1 + 24 = interrupter register set, + 4 = IMOD
v3 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 88LL);
*(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 96) & 0xFFFFFFF9 | 4;
if ( *(_BYTE *)(v3 + 137) )
{
  *v2 = 200;
  _InterlockedOr(v8, 0);
}
else
{
  XilRegister_WriteUlong(v3, v2, 200); // IMOD = 0x000000C8, IMODI = 200 (50 us), IMODC = 0
}
v4 = *(unsigned int **)(a1 + 24);
if ( *(_BYTE *)(v3 + 137) )
  Ulong = *v4;
else
  Ulong = XilRegister_ReadUlong(v3, v4); // IMAN
v6 = *(_DWORD **)(a1 + 24);
result = Ulong | 2; // IMAN.IE = 1
if ( !*(_BYTE *)(v3 + 137) )
  return XilRegister_WriteUlong(v3, v6, result);
```

[`Interrupter_CreateInterrupter`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBXHCI/Interrupter_CreateInterrupter.c) registers [`Interrupter_WdfEvtInterruptEnable`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBXHCI/Interrupter_WdfEvtInterruptEnable.c) as the KMDF interrupt enable callback, KMDF calls it every time the controller enters D0, and USBXHCI also calls `Interrupter_InterruptEnable` after a controller reset.

> "*The framework calls the driver's EvtInterruptEnable and EvtDeviceD0EntryPostInterruptsEnabled callback functions each time the device enters its working (D0) state, after the framework has called the driver's EvtDeviceD0Entry callback function.*"
>
> — Microsoft, [Enabling and Disabling Interrupts](https://learn.microsoft.com/en-us/windows-hardware/drivers/wdf/enabling-and-disabling-interrupts)

```c
// Interrupter_InterruptEnable (23H2)

 * Callers:
 *     Interrupter_WdfEvtInterruptEnable @ 0x1C0013980 (Interrupter_WdfEvtInterruptEnable.c)
 *     Interrupter_ControllerResetPostReset @ 0x1C003DCC4 (Interrupter_ControllerResetPostReset.c)
```

USBXHCI lets an idle controller go to D3 after 10sec, unless [`DisableHCS0Idle`](https://noverse.dev/docs/win-config/peripheral/usbflags-values/#registry-values) is set or the platform cant wake it from D1/deeper:

```c
// Controller_ConfigureS0IdleSettings (25H2)

LOBYTE(v2) = Controller_IsRegKeySetToDisableS0Idle(a1); // DisableHCS0Idle, see below
if ( !(_BYTE)v2 )

v7 = ((__int64 (__fastcall *)(_QWORD, __int64, int *))v16[5])(v16[1], 1LL, &v17); // GetIdleWakeInfo, v17 = DEVICE_WAKE_DEPTH

if ( v17 > 1 ) // wake from D1/deeper
{
  *v9 = 0;
  LOBYTE(v2) = Controller_UpdateIdleTimeout(a1, 10000LL); // idle timeout 10000 ms
```

## Mouse/Keyboard Input

USB mouse & keyboards normally use interrupt IN endpoints, so a 1000 Hz endpoint has one USB service chance every 1 ms, and an 8000 Hz endpoint has one every 125 us ([needs high speed, as full speed interrupt endpoints cannot be faster than once per 1 ms frame](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor#members)). `bInterval`, endpoint type & the device speed decide that schedule.

> "*`bInterval`*
>
> *The bInterval value contains the polling interval for interrupt and isochronous endpoints. For other types of endpoint, this value should be ignored. This value reflects the device's configuration in firmware. Drivers cannot change it.*
>
> *The polling interval, together with the speed of the device and the type of host controller, determine the frequency with which the driver should initiate an interrupt or an isochronous transfer. The value in bInterval does not represent a fixed amount of time. It is a relative value, and the actual polling frequency will also depend on whether the device and the USB host controller operate at low, full or high speed.*"
>
> — Microsoft, [USB_ENDPOINT_DESCRIPTOR structure](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor#members)

So IMOD usually adds no interrupt notification wait in relation to the polling interval here, as the 50 us counter is usually already at zero whenever the next service chance happens, see '[Light Load](https://noverse.dev/docs/win-config/power/xhci-imod/#light-load)' example, therefore I would generally keep IMOD at its default value and move your USB devices onto different xHCI controllers, so they don't get the same `InterrupterTarget` on one controller.

| Rate | Polling Interval | Isolated endpoint with 50 us IMOD |
| --- | --- | --- |
| 1000 Hz | 1000 us | Counter reached zero ~950 us earlier |
| 8000 Hz | 125 us | Counter reached zero ~75 us earlier |

But note that another event on the same interrupter could change that, if it caused an interrupt during the previous 50 us, the mouse/keyboard report can wait for the remaining time.

## WinDbg usb3kd

### xhci_dumpall

Using [`xhci_dumpall`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-usb3kd-xhci-dumpall) you can see your controllers and their locations.

```c
lkd> !usb3kd.xhci_dumpall
List of XHCI controllers
-------------------------
1)  AMD - PCI: VendorId 0x1022 DeviceId 0x149c RevisionId 0x00 SubVendorId 0x1043 SubSystemId 0x87c0 // PCI 09:00.3
    !xhci_capability 0xffff85824c5bfe90
    !xhci_registers 0xffff85824c5bfe90
    !pci 100 0x9 0x0 0x3 // PCI bus 09, device 00, function 3

2)  AMD - PCI: VendorId 0x1022 DeviceId 0x43ee RevisionId 0x00 SubVendorId 0x1b21 SubSystemId 0x1142 // PCI 02:00.0
    !xhci_capability 0xffff85824c45dec0
    !xhci_registers 0xffff85824c45dec0
    !pci 100 0x2 0x0 0x0 // PCI bus 02, device 00, function 0
```

### xhci_capability

Via [`xhci_capability`](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/-usb3kd-xhci-capability) you can see the amount of interrupters a controller has (and if windows supports them).

```c
lkd> !usb3kd.xhci_capability 0xffff85824c5bfe90
Controller Capabilities
-----------------------
    Interrupters: 8 // HCSPARAMS1.MaxIntrs

Software Supported Capabilities
-------------------------------
    Interrupters: 8 // what USBXHCI set up, 8 on this controller

lkd> !usb3kd.xhci_registers 0xffff85824c5bfe90
Runtime Registers
-----------------
    dt USBXHCI!_RUNTIME_REGISTERS 0xffffde81645004c0 // controller register base + RTSOFF
    dt -ba8 USBXHCI!_INTERRUPTER_REGISTER_SET 0xffffde81645004e0 // interrupter 0 starts at runtimeBase + 0x20
```

USBXHCI doesn't always use every interrupter a controller implements, it sets up the primary interrupter 0 and up to 16 secondary ones, at most one per active processor and limited by the message interrupts (MSI-X) the controller gets, this also means that with a single message only interrupter 0 is used:

```c
// Interrupter_DetermineSecondaryInterrupterCount (25H2)

ActiveProcessorCount = KeQueryActiveProcessorCountEx(0);
v5 = *(_QWORD *)(a1 + 8);
v6 = 0;
v7 = ActiveProcessorCount;
if ( (*(_QWORD *)(v5 + 736) & 0x1000LL) == 0 )
{
  v8 = (*(_DWORD *)(*(_QWORD *)(a1 + 8) + 1044LL) == 1) + 1;
  if ( a2 != v8 ) // a2 = message interrupt count
  {
    v6 = a2 - v8;
    if ( (unsigned int)(a2 - v8) > 0x10 )
      v6 = 16; // at most 16 secondary interrupters
    if ( v7 <= v6 )
      v6 = v7; // at most one per active processor
  }
}
```

### USBXHCI _IMOD

The [`_IMOD` type](https://noverse.dev/diff?kind=type&left=11-23H2&right=11-24H2&module=USBXHCI&name=_IMOD&mode=side-by-side) shows that the low half is the interval and the high half is the counter. I guess `Inverval` is a typo and means `Interval`?

```c
lkd> dt USBXHCI!_IMOD
   +0x000 AsUlong32        : Uint4B
   +0x000 Inverval         : Pos 0, 16 Bits // IMODI
   +0x000 Counter          : Pos 16, 16 Bits // IMODC

lkd> dt -ba8 USBXHCI!_INTERRUPTER_REGISTER_SET 0xffffde81645004e0
[0] @ ffffde81`645004e0 // interrupter 0 register set
   +0x000 InterrupterManagement : _IMAN
      +0x000 AsUlong32        : 2 // IMAN
      +0x000 Pending          : 0y0 // IP
      +0x000 Enable           : 0y1 // IE
   +0x004 InterrupterModeration : _IMOD
      +0x000 AsUlong32        : 0xc8 // IMOD
      +0x000 Inverval         : 0y0000000011001000 (0xc8) // IMODI = 200 ticks = 50 us
      +0x000 Counter          : 0y0000000000000000 (0) // IMODC
   +0x018 EventRingDequeuePointerRegister : _ERDP
      +0x000 EventHandlerBusy : 0y0 // EHB
```

And all eight IMOD registers on this controller have the same value:

```c
lkd> dd 0xffffde81645004e4 L1 // RuntimeBase + 0x24 + 0x20 * 0 (interrupter 0 IMOD)
ffffde81`645004e4  000000c8 // IMODI & IMODC
lkd> dd 0xffffde8164500504 L1 // interrupter 1 IMOD
ffffde81`64500504  000000c8
lkd> dd 0xffffde8164500524 L1 // interrupter 2 IMOD
ffffde81`64500524  000000c8
lkd> dd 0xffffde8164500544 L1 // interrupter 3 IMOD
ffffde81`64500544  000000c8
lkd> dd 0xffffde8164500564 L1 // interrupter 4 IMOD
ffffde81`64500564  000000c8
lkd> dd 0xffffde8164500584 L1 // interrupter 5 IMOD
ffffde81`64500584  000000c8
lkd> dd 0xffffde81645005a4 L1 // interrupter 6 IMOD
ffffde81`645005a4  000000c8
lkd> dd 0xffffde81645005c4 L1 // interrupter 7 IMOD
ffffde81`645005c4  000000c8
```

### Mouse/Keyboard Transfers

Just some additional notes for now.

As both of my devices are at full speed I'll add the table here, see [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor#members) for the low/high speed tables.

| Value of bInterval | Polling Period (1-millisecond frames) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 1 | 1 | Supported. | Supported. |
| 2 to 3 | 2 | Supported. | Supported. |
| 4 to 7 | 4 | Supported. | Supported. |
| 8 to 15 | 8 | Supported. | Supported. |
| 16 to 31 | 16 | Supported. | Not supported. |
| 32 to 255 | 32 | Supported. | Not supported. |
| > 255 | Polling intervals > 255 are forbidden by the USB specification. | | |

See [USB_INTERFACE_DESCRIPTOR](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_interface_descriptor) and [USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor) for field definitions.

```c
lkd> !usb3kd.xhci_deviceslots 0xffff85824c45dec0 3 verbose
[3] SlotID : dt USBXHCI!_USBDEVICE_DATA 0xffff85826ba895b0 dt USBXHCI!_SLOT_CONTEXT32 0xffff85824f7fe000
    USB\VID_046D&PID_C547 Logitech Inc. // mouse
    Speed: Full PortPathDepth: 1 PortPath: [ 5 ] DeviceAddress: 3 // full speed = period is measured in units of 1 millisecond frames

    [3] : dt USBXHCI!_ENDPOINT_DATA 0xffff8582a4bdea60 dt USBXHCI!_ENDPOINT_CONTEXT32 0xffff85824f7fe060 ES_RUNNING
        EndpointType_InterruptIn Address: 0x81 PacketSize: 64 Interval: 1
        [1] dt USBXHCI!_BULK_TRANSFER_DATA 0xffff85824f96cc20
            [0] dt USBXHCI!_BULK_STAGE_DATA 0xffff85824f96ccb0 !xhci_transfertrbs 0xffff85824f96cd10

lkd> !usb3kd.configdescriptor 0xffff858353ae57a0
USB_INTERFACE_DESCRIPTOR:
  bInterfaceClass:         0x03 HID (Human Interface Device) Interface Class
  bInterfaceSubClass:      0x01
  bInterfaceProtocol:      0x02
USB_ENDPOINT_DESCRIPTOR:
  bEndpointAddress:        0x81
    Endpoint Direction: IN
  bmAttributes:            0x03
    Interrupt Endpoint
  wMaxPacketSize:          0x0040 // up to 64 bytes per service
  bInterval:               0x01 // 1 ms frame (as device is full speed)
```

```c
lkd> !usb3kd.xhci_transfertrbs 0xffff85824f96cd10 // _BULK_STAGE_DATA.TrbRange at 0xffff85824f96ccb0 + 0x60
    [  0] NORMAL       0x0000000631175d40 CycleBit 1 IOC 0 CH 1 BEI 0 InterrupterTarget 1 TransferLength    13 TDSize  0
    [  1] EVENT_DATA   0x0000000631175d50 CycleBit 1 IOC 1 CH 0 BEI 0 InterrupterTarget 1 Data 0xffff85824f96ccb3 TotalBytes 13
```

```c
lkd> !usb3kd.xhci_deviceslots 0xffff85824c5bfe90 2 verbose
[2] SlotID : USB\VID_1038&PID_161E SteelSeries ApS // keyboard
    Speed: Full PortPath: [ 4 ] DeviceAddress: 2 // full speed

    [3] EndpointType_InterruptIn Address: 0x81 PacketSize: 8 Interval: 1 // bInterval = 1
        PendingTransferList:
        [0] dt USBXHCI!_BULK_TRANSFER_DATA 0xffff85824f8c6890
            [0] dt USBXHCI!_BULK_STAGE_DATA 0xffff85824f8c6920 !xhci_transfertrbs 0xffff85824f8c6980
        [1] dt USBXHCI!_BULK_TRANSFER_DATA 0xffff85824f702890

lkd> !usb3kd.xhci_transfertrbs 0xffff85824f8c6980 // _BULK_STAGE_DATA.TrbRange at 0xffff85824f8c6920 + 0x60
    [  0] NORMAL       0x000000010da40ec0 CycleBit 1 IOC 0 CH 1 BEI 0 InterrupterTarget 1 TransferLength     8 TDSize  0
    [  1] EVENT_DATA   0x000000010da40ed0 CycleBit 1 IOC 1 CH 0 BEI 0 InterrupterTarget 1 Data 0xffff85824f8c6923 TotalBytes 8
```

## xhci_imod

Download and extract [xhci_imod.zip](https://github.com/nohuto/utils/releases/download/0.1.0/xhci_imod.zip), keeping `xhci_imod.exe` and the signed `inpoutx64.sys` driver in the same folder. You can also build the executable from [source](https://github.com/nohuto/utils/tree/main/xhci_imod):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\xhci_imod.exe
```

The executable can also read/write physical addresses via `read8`, `read16`, `read32`, `read64`, `write8`, `write16`, `write32`, `write64`, `readblk`, `writeblk`.

| Flag | Description |
| --- | --- |
| `--driver PATH` | Override the colocated `inpoutx64.sys` path |
| `--bdf BB:DD.F` | Hexadecimal xHCI PCI address (BB:DD.F) |
| `--xhci-index N` | Select the Nth xHCI controller |
| `--all` | Go through every PCI xHCI controller |
| `--interrupter ID` / `-i ID` | Interrupter ID to process, can be repeated (defaults to initialized Event Rings) |
| `--interval VALUE` | IMODI in 250 ns units, 0 disables moderation, range 0-65535 |
| `--no-write` | Read and output without MMIO writes |
| `--startup` | Create a highest privilege logon task |
| `--delete` | Delete the logon task and `%LOCALAPPDATA%\Noverse\IMOD` folder |
| `--no-exit` | Keep the console open until Ctrl+C |
| `--verbose` | Show driver and controller details |

Examples:

```c
--all --no-write --no-exit // information only
--all --no-write --verbose --no-exit // driver and controller details
--all // IMODI = 0 for all initialized Event Rings
--all --interval 0xC800 // testing, 12.8 ms (~78 interrupts/s maximum)
--all --startup // 0 for all controllers, creates scheduled task
--delete // removes the task and IMOD folder
```

## [Registers](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

![](https://github.com/nohuto/win-config/blob/main/power/images/interrupter-register-set.png?raw=true)

### IMOD

Interrupter Moderation Register.

| Bit | Description |
| --- | --- |
| 15:0 | Interrupt Moderation Interval (IMODI) - RW. Default = '4000' (~1ms). Minimum inter-interrupt interval. The interval is specified in 250ns increments. A value of '0' disables interrupt throttling logic and interrupts shall be generated immediately if IP = '0', EHB = '0', and the Event Ring is not empty. |
| 31:16 | Interrupt Moderation Counter (IMODC) - RW. Default = undefined. Down counter. Loaded with the IMODI value whenever IP is cleared to '0', counts down to '0', and stops. The associated interrupt shall be signaled whenever this counter is '0', the Event Ring is not empty, the IE and IP flags = '1', and EHB = '0'.<br><br>This counter may be directly written by software at any time to alter the interrupt rate. |

### HCSPARAMS1

Host Controller Structural Parameters 1.

| Bits | Description |
| --- | --- |
| 7:0 | **Number of Device Slots (MaxSlots).** This field specifies the maximum number of Device Context Structures and Doorbell Array entries this host controller can support. Valid values are in the range of 1 to 255. The value of `0` is reserved. |
| 18:8 | **Number of Interrupters (MaxIntrs).** This field specifies the number of Interrupters implemented on this host controller. Each Interrupter may be allocated to a MSI or MSI-X vector and controls its generation and moderation.<br><br>The value of this field determines how many Interrupter Register Sets are addressable in the Runtime Register Space. Refer to section 5.5. Valid values are in the range of `1h` to `400h`. A `0` in this field is undefined. |
| 23:19 | Reserved. |
| 31:24 | **Number of Ports (MaxPorts).** This field specifies the maximum Port Number value, meaning the highest numbered Port Register Set that is addressable in the Operational Register Space. Refer to Table 5-18. Valid values are in the range of `1h` to `FFh`.<br><br>The value in this field shall reflect the maximum Port Number value assigned by an xHCI Supported Protocol Capability, described in section 7.2. Software shall refer to these capabilities to identify whether a specific Port Number is valid and the protocol supported by the associated Port Register Set. |

### HCSPARAMS2

Host Controller Structural Parameters 2.

| Bit | Description |
| --- | --- |
| 3:0 | **Isochronous Scheduling Threshold (IST).** Default = implementation dependent. The value in this field indicates to system software the minimum distance (in time) that it is required to stay ahead of the host controller while adding TRBs, in order to have the host controller process them at the correct time. The value shall be specified in terms of number of frames/microframes.<br><br>If bit 3 of IST is cleared to '0', software can add a TRB no later than IST 2:0 Microframes before that TRB is scheduled to be executed.<br><br>If bit 3 of IST is set to '1', software can add a TRB no later than IST 2:0 Frames before that TRB is scheduled to be executed.<br><br>Refer to Section 4.14.2 for details on how software uses this information for scheduling isochronous transfers. |
| 7:4 | **Event Ring Segment Table Max (ERST Max).** Default = implementation dependent. Valid values are 0-15. This field determines the maximum value supported by the Event Ring Segment Table Size registers, where:<br><br>The maximum number of Event Ring Segment Table entries = 2<sup>ERST Max</sup>.<br><br>For example, ERST Max = 7 supports up to 128 entries and ERST Max = 15 supports up to 32K entries. |
| 20:8 | Reserved. |
| 25:21 | **Max Scratchpad Buffers (Max Scratchpad Bufs Hi).** Default = implementation dependent. This field contains the high-order 5 bits of the number of Scratchpad Buffers that system software shall reserve for the xHC. Refer to section 4.20. |
| 26 | **Scratchpad Restore (SPR).** Default = implementation dependent. If Max Scratchpad Buffers is greater than `0`, this field indicates whether the xHC uses the Scratchpad Buffers during Save and Restore State operations. A value of `1` requires the Scratchpad Buffer contents to remain intact across power events. A value of `0` allows the buffers to be freed and reallocated between power events. This field shall be `0` when Max Scratchpad Buffers is `0`. Refer to section 4.23.2. |
| 31:27 | **Max Scratchpad Buffers (Max Scratchpad Bufs Lo).** Default = implementation dependent. This field contains the low-order 5 bits of the number of Scratchpad Buffers that system software shall reserve for the xHC. The combined valid range is 0 to 1023. Refer to section 4.20. |

![](https://github.com/nohuto/win-config/blob/main/power/images/HCSPARAMS2-structure.png?raw=true)

### RTSOFF

Runtime Register Space Offset Register.

| Bit | Description |
| --- | --- |
| 4:0 | Rsvd. |
| 31:5 | Runtime Register Space Offset - RO. Default = implementation dependent. This field defines the 32-byte offset of the xHCI Runtime Registers from the Base. i.e. Runtime Register Base Address = Base + Runtime Register Set Offset.<br><br>Note: Normally the Runtime Register Space is 32-byte aligned, however if virtualization is supported by the xHC (either through IOV or VTIO) then it shall be PAGESIZE aligned. e.g. If the PAGESIZE = 4K and the Runtime Register Space is positioned at a 1 page offset from the Base, then this register shall report 0000 1000h. |

![](https://github.com/nohuto/win-config/blob/main/power/images/RTSOFF-structure.png?raw=true)

### USBCMD

USB Command Register.

| Bits | Description |
| --- | --- |
| 0 | Run/Stop (R/S) - RW. Default = '0'. '1' = Run. '0' = Stop. When set to a '1', the xHC proceeds with execution of the schedule. The xHC continues execution as long as this bit is set to a '1'. When this bit is cleared to '0', the xHC completes any current or queued commands or TDs, and any USB transactions associated with them, then halts.<br><br>Refer to section 5.4.1.1 for more information on how R/S shall be managed.<br><br>The xHC shall halt within 16 ms. after software clears the Run/Stop bit if the above conditions have been met.<br><br>The HCHalted (HCH) bit in the USBSTS register indicates when the xHC has finished its pending pipelined transactions and has entered the stopped state. Software shall not write a '1' to this flag unless the xHC is in the Halted state (i.e. HCH in the USBSTS register is '1'). Doing so may yield undefined results. Writing a '0' to this flag when the xHC is in the Running state (i.e. HCH = '0') and any Event Rings are in the Event Ring Full state (refer to section 4.9.4) may result in lost events.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls the run state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 1 | Host Controller Reset (HCRST) - RW. Default = '0'. This control bit is used by software to reset the host controller. The effects of this bit on the xHC and the Root Hub registers are similar to a Chip Hardware Reset.<br><br>When software writes a '1' to this bit, the Host Controller resets its internal pipelines, timers, counters, state machines, etc. to their initial value. Any transaction currently in progress on the USB is immediately terminated. A USB reset shall not be driven on USB2 downstream ports, however a Hot or Warm Reset<sup>79</sup> shall be initiated on USB3 Root Hub downstream ports.<br><br>PCI Configuration registers are not affected by this reset. All operational registers, including port registers and port state machines are set to their initial values. Software shall reinitialize the host controller as described in Section 4.2 in order to return the host controller to an operational state.<br><br>This bit is cleared to '0' by the Host Controller when the reset process is complete. Software cannot terminate the reset process early by writing a '0' to this bit and shall not write any xHC Operational or Runtime registers until while HCRST is '1'. Note, the completion of the xHC reset process is not gated by the Root Hub port reset process.<br><br>Software shall not set this bit to '1' when the HCHalted (HCH) bit in the USBSTS register is a '0'. Attempting to reset an actively running host controller may result in undefined behavior.<br><br>When this register is exposed by a Virtual Function (VF), this bit only resets the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 2 | Interrupter Enable (INTE) - RW. Default = '0'. This bit provides system software with a means of enabling or disabling the host system interrupts generated by Interrupters. When this bit is a '1', then Interrupter host system interrupt generation is allowed, e.g. the xHC shall issue an interrupt at the next interrupt threshold if the host system interrupt mechanism (e.g. MSI, MSI-X, etc.) is enabled. The interrupt is acknowledged by a host system interrupt specific mechanism.<br><br>When this register is exposed by a Virtual Function (VF), this bit only enables the set of Interrupters assigned to the selected VF. Refer to section 7.7.2 for more information. |
| 3 | Host System Error Enable (HSEE) - RW. Default = '0'. When this bit is a '1', and the HSE bit in the USBSTS register is a '1', the xHC shall assert out-of-band error signaling to the host. The signaling is acknowledged by software clearing the HSE bit. Refer to section 4.10.2.6 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the effect of the assertion of this bit on the Physical Function (PF0) is determined by the VMM. Refer to section 8 for more information. |
| 6:4 | RsvdP. |
| 7 | Light Host Controller Reset (LHCRST) - RO or RW. Optional normative. Default = '0'. If the Light HC Reset Capability (LHRC) bit in the HCCPARAMS1 register is '1', then this flag allows the driver to reset the xHC without affecting the state of the ports.<br><br>A system software read of this bit as '0' indicates the Light Host Controller Reset has completed and it is safe for software to re-initialize the xHC. A software read of this bit as a '1' indicates the Light Host Controller Reset has not yet completed.<br><br>If not implemented, a read of this flag shall always return a '0'.<br><br>All registers in the Aux Power well shall maintain the values that had been asserted prior to the Light Host Controller Reset. Refer to section 4.23.1 for more information.<br><br>When this register is exposed by a Virtual Function (VF), this bit only generates a Light Reset to the xHC instance presented by the selected VF, e.g. Disable the VFs' device slots and set the associated VF Run bit to Stopped. Refer to section 8 for more information. |
| 8 | Controller Save State (CSS) - RW. Default = '0'. When written by software with '1' and HCHalted (HCH) = '1', then the xHC shall save any internal state (that may be restored by a subsequent Restore State operation) and if FSC = '1' any cached Slot, Endpoint, Stream, or other Context information (so that software may save it). When written by software with '1' and HCHalted (HCH) = '0', or written with '0', no Save State operation shall be performed. This flag always returns '0' when read. Refer to the Save State Status (SSS) flag in the USBSTS register for information on Save State completion. Refer to section 4.23.2 for more information on xHC Save/Restore operation. Note that undefined behavior may occur if a Save State operation is initiated while Restore State Status (RSS) = '1'.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls saving the state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 9 | Controller Restore State (CRS) - RW. Default = '0'. When set to '1', and HCHalted (HCH) = '1', then the xHC shall perform a Restore State operation and restore its internal state. When set to '1' and Run/Stop (R/S) = '1' or HCHalted (HCH) = '0', or when cleared to '0', no Restore State operation shall be performed. This flag always returns '0' when read. Refer to the Restore State Status (RSS) flag in the USBSTS register for information on Restore State completion. Refer to section 4.23.2 for more information. Note that undefined behavior may occur if a Restore State operation is initiated while Save State Status (SSS) = '1'.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls restoring the state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 10 | Enable Wrap Event (EWE) - RW. Default = '0'. When set to '1', the xHC shall generate a MFINDEX Wrap Event every time the MFINDEX register transitions from 03FFFh to 0. When cleared to '0' no MFINDEX Wrap Events are generated. Refer to section 4.14.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the generation of MFINDEX Wrap Events to VFs shall be emulated by the VMM. |
| 11 | Enable U3 MFINDEX Stop (EU3S) - RW. Default = '0'. When set to '1', the xHC may stop the MFINDEX counting action if all Root Hub ports are in the U3, Disconnected, Disabled, or Powered-off state. When cleared to '0' the xHC may stop the MFINDEX counting action if all Root Hub ports are in the Disconnected, Disabled, Training, or Powered-off state. Refer to section 4.14.2 for more information. |
| 12 | RsvdP. |
| 13 | CEM Enable (CME) - RW. Default = '0'. When set to '1', a Max Exit Latency Too Large Capability Error may be returned by a Configure Endpoint Command. When cleared to '0', a Max Exit Latency Too Large Capability Error shall not be returned by a Configure Endpoint Command. This bit is Reserved if CMC = '0'. Refer to section 4.23.5.2.2 for more information. |
| 14 | Extended TBC Enable (ETE). This flag indicates that the host controller implementation is enabled to support Transfer Burst Count (TBC) values greater that 4 in isoch TDs. When this bit is '1', the Isoch TRB TD Size/TBC field presents the TBC value, and the TBC/RsvdZ field is RsvdZ. When this bit is '0', the TDSize/TCB field presents the TD Size value, and the TBC/RsvdZ field presents the TBC value. This bit may be set only if ETC = '1'. Refer to section 4.11.2.3 for more information. |
| 15 | Extended TBC TRB Status Enable (TSC_EN). This flag indicates that the host controller implementation is enabled to support ETC_TSC capability. When this is '1', TRBSts field in the TRB updated to indicate if it is last transfer TRB in the TD. This bit may be set only if ETC_TSC='1'. Refer to section 4.11.2.3 for more information. |
| 16 | VTIO Enable (VTIOE) - RW. Default = '0'. When set to '1', XHCI HW will enable its VTIO capability and begin to use the information provided via that VTIO Registers to determine its DMA-ID. When cleared to '0', XHCI HW will use the Primary DMA-ID for all accesses. This bit may be set only if VTC = '1'. |
| 31:17 | RsvdP. |

### USBSTS

USB Status Register.

| Bit | Description |
| --- | --- |
| 0 | HCHalted (HCH) - RO. Default = '1'. This bit is a '0' whenever the Run/Stop (R/S) bit is a '1'. The xHC sets this bit to '1' after it has stopped executing as a result of the Run/Stop (R/S) bit being cleared to '0', either by software or by the xHC hardware (e.g. internal error).<br><br>If this bit is '1', then SOFs, microSOFs, or Isochronous Timestamp Packets (ITP) shall not be generated by the xHC, and any received Transaction Packet shall be dropped.<br><br>When this register is exposed by a Virtual Function (VF), this bit only reflects the Halted state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 1 | RsvdZ. |
| 2 | Host System Error (HSE) - RW1C. Default = '0'. The xHC sets this bit to '1' when a serious error is detected, either internal to the xHC or during a host system access involving the xHC module. (In a PCI system, conditions that set this bit to '1' include PCI Parity error, PCI Master Abort, and PCI Target Abort.) When this error occurs, the xHC clears the Run/Stop (R/S) bit in the USBCMD register to prevent further execution of the scheduled TDs. If the HSEE bit in the USBCMD register is a '1', the xHC shall also assert out-of-band error signaling to the host. Refer to section 4.10.2.6 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the assertion of this bit affects all VFs and reflects the Host System Error state of the Physical Function (PF0). Refer to section 8 for more information. |
| 3 | Event Interrupt (EINT) - RW1C. Default = '0'. The xHC sets this bit to '1' when the Interrupt Pending (IP) bit of any Interrupter transitions from '0' to '1'. Refer to section 7.1.2 for use.<br><br>Software that uses EINT shall clear it prior to clearing any IP flags. A race condition may occur if software clears the IP flags then clears the EINT flag, and between the operations another IP '0' to '1' transition occurs. In this case the new IP transition shall be lost.<br><br>When this register is exposed by a Virtual Function (VF), this bit is the logical 'OR' of the IP bits for the Interrupters assigned to the selected VF. And it shall be cleared to '0' when all associated interrupter IP bits are cleared, i.e. all the VF's Interrupter Event Ring(s) are empty. Refer to section 8 for more information. |
| 4 | Port Change Detect (PCD) - RW1C. Default = '0'. The xHC sets this bit to a '1' when any port has a change bit transition from a '0' to a '1'.<br><br>This bit is allowed to be maintained in the Aux Power well. Alternatively, it is also acceptable that on a D3 to D0 transition of the xHC, this bit is loaded with the OR of all of the PORTSC change bits. Refer to section 4.19.3.<br><br>This bit provides system software an efficient means of determining if there has been Root Hub port activity. Refer to section 4.15.2.3 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the Root Hub Ports associated with the Device Slots assigned to the selected VF. Refer to section 8 for more information. |
| 7:5 | RsvdZ. |
| 8 | Save State Status (SSS) - RO. Default = '0'. When the Controller Save State (CSS) flag in the USBCMD register is written with '1' this bit shall be set to '1' and remain 1 while the xHC saves its internal state. When the Save State operation is complete, this bit shall be cleared to '0'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the saving the state for the selected VF. Refer to section 8 for more information. |
| 9 | Restore State Status (RSS) - RO. Default = '0'. When the Controller Restore State (CRS) flag in the USBCMD register is written with '1' this bit shall be set to '1' and remain 1 while the xHC restores its internal state. When the Restore State operation is complete, this bit shall be cleared to '0'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the restoring the state for the selected VF. Refer to section 8 for more information. |
| 10 | Save/Restore Error (SRE) - RW1C. Default = '0'. If an error occurs during a Save or Restore operation this bit shall be set to '1'. This bit shall be cleared to '0' when a Save or Restore operation is initiated or when written with '1'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the Save/Restore completion status for the selected VF. Refer to section 8 for more information. |
| 11 | Controller Not Ready (CNR) - RO. Default = '1'. '0' = Ready and '1' = Not Ready. Software shall not write any Doorbell or Operational register of the xHC, other than the USBSTS register, until CNR = '0'. This flag is set by the xHC after a Chip Hardware Reset and cleared when the xHC is ready to begin accepting register writes. This flag shall remain cleared ('0') until the next Chip Hardware Reset. |
| 12 | Host Controller Error (HCE) - RO. Default = 0. 0' = No internal xHC error conditions exist and '1' = Internal xHC error condition. This flag shall be set to indicate that an internal error condition has been detected which requires software to reset and reinitialize the xHC. Refer to section 4.24.1 for more information. |
| 31:13 | RsvdZ. |

### MFINDEX

Microframe Index Register.

| Bit | Description |
| --- | --- |
| 13:0 | Microframe Index - RO. The value in this register increments at the end of each microframe (e.g. 125us.). Bits 13:3 may be used to determine the current 1ms. Frame Index. |
| 31:14 | RsvdZ. |

### IMAN

Interrupter Management Register.

| Bit | Description |
| --- | --- |
| 0 | Interrupt Pending (IP) - RW1C. Default = '0'. This flag represents the current state of the Interrupter. If IP = '1', an interrupt is pending for this Interrupter. A '0' value indicates that no interrupt is pending for the Interrupter. Refer to section 4.17.3 for the conditions that modify the state of this flag. |
| 1 | Interrupt Enable (IE) - RW. Default = '0'. This flag specifies whether the Interrupter is capable of generating an interrupt. When this bit and the IP bit are set ('1'), the Interrupter shall generate an interrupt when the Interrupter Moderation Counter reaches '0'. If this bit is '0', then the Interrupter is prohibited from generating interrupts. |
| 31:2 | RsvdP. |

### ERSTSZ

Event Ring Segment Table Size Register.

| Bit | Description |
| --- | --- |
| 15:0 | Event Ring Segment Table Size - RW. Default = '0'. This field identifies the number of valid Event Ring Segment Table entries in the Event Ring Segment Table pointed to by the Event Ring Segment Table Base Address register. The maximum value supported by an xHC implementation for this register is defined by the ERST Max field in the HCSPARAMS2 register (5.3.4).<br><br>For Secondary Interrupters: Writing a value of '0' to this field disables the Event Ring. Any events targeted at this Event Ring when it is disabled shall result in undefined behavior of the Event Ring.<br><br>For the Primary Interrupter: Writing a value of '0' to this field shall result in undefined behavior of the Event Ring. The Primary Event Ring cannot be disabled. |
| 31:16 | RsvdP. |

### ERSTBA

Event Ring Segment Table Base Address Register.

| Bit | Description |
| --- | --- |
| 5:0 | RsvdP. |
| 63:6 | Event Ring Segment Table Base Address Register - RW. Default = '0'. This field defines the high order bits of the start address of the Event Ring Segment Table.<br><br>Writing this register sets the Event Ring State Machine:EREP Advancement to the Start state. Refer to Figure 4-12 for more information.<br><br>For Secondary Interrupters: This field may be modified at any time.<br><br>For the Primary Interrupter: This field shall not be modified if HCHalted (HCH) = '0'. |

### ERDP

Event Ring Dequeue Pointer Register.

| Bit | Description |
| --- | --- |
| 2:0 | Dequeue ERST Segment Index (DESI) - RW. Default = '0'. This field may be used by the xHC to accelerate checking the Event Ring full condition. This field is written with the low order 3 bits of the offset of the ERST entry which defines the Event Ring segment that the Event Ring Dequeue Pointer resides in. Refer to section 6.5 for the definition of an ERST entry. |
| 3 | Event Handler Busy (EHB) - RW1C. Default = '0'. This flag shall be set to '1' when the IP bit is set to '1' and cleared to '0' by software when the Dequeue Pointer register is written. Refer to section 4.17.2 for more information. |
| 63:4 | Event Ring Dequeue Pointer - RW. Default = '0'. This field defines the high order bits of the 64-bit address of the current Event Ring Dequeue Pointer. |


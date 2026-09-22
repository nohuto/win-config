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

Usually, clearing `IP` (interrupt pending) loads `IMODC` from `IMODI`, `IMODC` then counts down which is the "remaining wait" above.

> "*An Interrupter manages events and their notification to the host. The xHCI supports up to 1024 Interrupters. The MaxIntrs field in HCSPARAMS1 determines the Number of Interrupters implemented in the xHC. Each Interrupter consists of an Interrupter Management Register, an Interrupter Moderation Register and an Event Ring. Each Interrupter shall be mapped to a single MSI or MSI-X interrupt vector. An Interrupter shall assert an interrupt if it is enabled and its associated Event Ring contains Event TRBs that require an interrupt.*"
>
> Intel, [eXtensible Host Controller Interface for Universal Serial Bus](https://www.intel.com/content/dam/www/public/us/en/documents/technical-specifications/extensible-host-controler-interface-usb-xhci.pdf)

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

An event below in the figures = Event TRB written to an Event Ring, for a mouse/keyboard, a completed interrupt IN transfer normally creates such an Transfer Event TRB.

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

Not complete yet.

![](https://github.com/nohuto/win-config/blob/main/power/images/usb-driver-stack.png?raw=true)

[`Interrupter_PrepareInterrupter`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/USBXHCI/Interrupter_PrepareInterrupter.c) gets the register set at `RuntimeBase + 0x20 + 0x20 * InterrupterId`, [`Interrupter_InterruptEnable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/USBXHCI/Interrupter_InterruptEnable.c) then writes decimal `200` to `IMOD` (low half of `0x000000C8` sets `IMODI = 200`, the high writes `IMODC` to zero) and enables `IMAN.IE`, W10 1507 - W11 26H1 all use `200`.

```c
// Interrupter_InterruptEnable

v2 = (_DWORD *)(*(_QWORD *)(a1 + 24) + 4LL);
XilRegister_WriteUlong(v3, v2, 200); // IMOD = 0x000000C8, 50 us
Ulong = XilRegister_ReadUlong(v3, v4);
result = Ulong | 2; // IMAN.IE = 1
return XilRegister_WriteUlong(v3, v6, result);
```

[`Interrupter_CreateInterrupter`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/USBXHCI/Interrupter_CreateInterrupter.c) registers [`Interrupter_WdfEvtInterruptEnable`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/USBXHCI/Interrupter_WdfEvtInterruptEnable.c) as the KMDF interrupt enable callback, which calls it whenever the controller enters D0 (as written in [Enabling and Disabling Interrupts](https://learn.microsoft.com/en-us/windows-hardware/drivers/wdf/enabling-and-disabling-interrupts)).

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
    Interrupters: 8 // windows supports all

lkd> !usb3kd.xhci_registers 0xffff85824c5bfe90
Runtime Registers
-----------------
    dt USBXHCI!_RUNTIME_REGISTERS 0xffffde81645004c0 // controller register base + RTSOFF
    dt -ba8 USBXHCI!_INTERRUPTER_REGISTER_SET 0xffffde81645004e0 // interrupter 0 starts at runtimeBase + 0x20
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
lkd> !usb3kd.xhci_transfertrbs 0xffff85824f96cd10 // // _BULK_STAGE_DATA.TrbRange at 0xffff85824f96ccb0 + 0x60
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

Download [xhci_imod.exe](https://github.com/nohuto/win-config/blob/main/power/assets/xhci_imod.exe) and the signed [inpoutx64.sys](https://github.com/nohuto/win-config/blob/main/power/assets/inpoutx64.sys) driver (kernel level port access driver), you can also build the executeable from [source](https://github.com/nohuto/win-config/tree/main/power/assets/xhci_imod):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\xhci_imod.exe
```

The executable is also capable to read/write physical addresses via `read8`, `read16`, `read32`, `read64`, `write8`, `write16`, `write32`, `write64`, `readblk`, `writeblk`.

| Flag | Description |
| --- | --- |
| `--driver PATH` | Override the colocated `inpoutx64.sys` path |
| `--bdf BB:DD.F` | Hexadecimal xHCI PCI address (BB:DD.F) |
| `--xhci-index N` | Select Nth xHCI controller |
| `--all` | Go through every PCI xHCI controller |
| `--interrupter ID` / `-i ID` | Interrupter ID to process (defaults to initialized Event Rings) |
| `--interval VALUE` | IMODI in 250 ns units, 0 disables moderation, range 0-65535 |
| `--no-write` | Read and output without MMIO writes |
| `--startup` | Create a highest privilege logon task |
| `--delete` | Delete the logon task and `%LOCALAPPDATA%\Noverse\IMOD` folder |
| `--no-exit` | Keep the console open after completion |
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
| 15:0 | Interrupt Moderation Interval (IMODI) – RW. Default = '4000' (~1ms). Minimum inter-interrupt interval. The interval is specified in 250ns increments. A value of '0' disables interrupt throttling logic and interrupts shall be generated immediately if IP = '0', EHB = '0', and the Event Ring is not empty. |
| 31:16 | Interrupt Moderation Counter (IMODC) – RW. Default = undefined. Down counter. Loaded with the IMODI value whenever IP is cleared to '0', counts down to '0', and stops. The associated interrupt shall be signaled whenever this counter is '0', the Event Ring is not empty, the IE and IP flags = '1', and EHB = '0'.<br><br>This counter may be directly written by software at any time to alter the interrupt rate. |

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
| 7:4 | **Event Ring Segment Table Max (ERST Max).** Default = implementation dependent. Valid values are 0 – 15. This field determines the maximum value supported by the Event Ring Segment Table Size registers, where:<br><br>The maximum number of Event Ring Segment Table entries = 2<sup>ERST Max</sup>.<br><br>For example, ERST Max = 7 supports up to 128 entries and ERST Max = 15 supports up to 32K entries. |
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
| 0 | Run/Stop (R/S) – RW. Default = '0'. '1' = Run. '0' = Stop. When set to a '1', the xHC proceeds with execution of the schedule. The xHC continues execution as long as this bit is set to a '1'. When this bit is cleared to '0', the xHC completes any current or queued commands or TDs, and any USB transactions associated with them, then halts.<br><br>Refer to section 5.4.1.1 for more information on how R/S shall be managed.<br><br>The xHC shall halt within 16 ms. after software clears the Run/Stop bit if the above conditions have been met.<br><br>The HCHalted (HCH) bit in the USBSTS register indicates when the xHC has finished its pending pipelined transactions and has entered the stopped state. Software shall not write a '1' to this flag unless the xHC is in the Halted state (i.e. HCH in the USBSTS register is '1'). Doing so may yield undefined results. Writing a '0' to this flag when the xHC is in the Running state (i.e. HCH = '0') and any Event Rings are in the Event Ring Full state (refer to section 4.9.4) may result in lost events.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls the run state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 1 | Host Controller Reset (HCRST) – RW. Default = '0'. This control bit is used by software to reset the host controller. The effects of this bit on the xHC and the Root Hub registers are similar to a Chip Hardware Reset.<br><br>When software writes a '1' to this bit, the Host Controller resets its internal pipelines, timers, counters, state machines, etc. to their initial value. Any transaction currently in progress on the USB is immediately terminated. A USB reset shall not be driven on USB2 downstream ports, however a Hot or Warm Reset<sup>79</sup> shall be initiated on USB3 Root Hub downstream ports.<br><br>PCI Configuration registers are not affected by this reset. All operational registers, including port registers and port state machines are set to their initial values. Software shall reinitialize the host controller as described in Section 4.2 in order to return the host controller to an operational state.<br><br>This bit is cleared to '0' by the Host Controller when the reset process is complete. Software cannot terminate the reset process early by writing a '0' to this bit and shall not write any xHC Operational or Runtime registers until while HCRST is '1'. Note, the completion of the xHC reset process is not gated by the Root Hub port reset process.<br><br>Software shall not set this bit to '1' when the HCHalted (HCH) bit in the USBSTS register is a '0'. Attempting to reset an actively running host controller may result in undefined behavior.<br><br>When this register is exposed by a Virtual Function (VF), this bit only resets the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 2 | Interrupter Enable (INTE) – RW. Default = '0'. This bit provides system software with a means of enabling or disabling the host system interrupts generated by Interrupters. When this bit is a '1', then Interrupter host system interrupt generation is allowed, e.g. the xHC shall issue an interrupt at the next interrupt threshold if the host system interrupt mechanism (e.g. MSI, MSI-X, etc.) is enabled. The interrupt is acknowledged by a host system interrupt specific mechanism.<br><br>When this register is exposed by a Virtual Function (VF), this bit only enables the set of Interrupters assigned to the selected VF. Refer to section 7.7.2 for more information. |
| 3 | Host System Error Enable (HSEE) – RW. Default = '0'. When this bit is a '1', and the HSE bit in the USBSTS register is a '1', the xHC shall assert out-of-band error signaling to the host. The signaling is acknowledged by software clearing the HSE bit. Refer to section 4.10.2.6 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the effect of the assertion of this bit on the Physical Function (PF0) is determined by the VMM. Refer to section 8 for more information. |
| 6:4 | RsvdP. |
| 7 | Light Host Controller Reset (LHCRST) – RO or RW. Optional normative. Default = '0'. If the Light HC Reset Capability (LHRC) bit in the HCCPARAMS1 register is '1', then this flag allows the driver to reset the xHC without affecting the state of the ports.<br><br>A system software read of this bit as '0' indicates the Light Host Controller Reset has completed and it is safe for software to re-initialize the xHC. A software read of this bit as a '1' indicates the Light Host Controller Reset has not yet completed.<br><br>If not implemented, a read of this flag shall always return a '0'.<br><br>All registers in the Aux Power well shall maintain the values that had been asserted prior to the Light Host Controller Reset. Refer to section 4.23.1 for more information.<br><br>When this register is exposed by a Virtual Function (VF), this bit only generates a Light Reset to the xHC instance presented by the selected VF, e.g. Disable the VFs' device slots and set the associated VF Run bit to Stopped. Refer to section 8 for more information. |
| 8 | Controller Save State (CSS) - RW. Default = '0'. When written by software with '1' and HCHalted (HCH) = '1', then the xHC shall save any internal state (that may be restored by a subsequent Restore State operation) and if FSC = '1' any cached Slot, Endpoint, Stream, or other Context information (so that software may save it). When written by software with '1' and HCHalted (HCH) = '0', or written with '0', no Save State operation shall be performed. This flag always returns '0' when read. Refer to the Save State Status (SSS) flag in the USBSTS register for information on Save State completion. Refer to section 4.23.2 for more information on xHC Save/Restore operation. Note that undefined behavior may occur if a Save State operation is initiated while Restore State Status (RSS) = '1'.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls saving the state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 9 | Controller Restore State (CRS) - RW. Default = '0'. When set to '1', and HCHalted (HCH) = '1', then the xHC shall perform a Restore State operation and restore its internal state. When set to '1' and Run/Stop (R/S) = '1' or HCHalted (HCH) = '0', or when cleared to '0', no Restore State operation shall be performed. This flag always returns '0' when read. Refer to the Restore State Status (RSS) flag in the USBSTS register for information on Restore State completion. Refer to section 4.23.2 for more information. Note that undefined behavior may occur if a Restore State operation is initiated while Save State Status (SSS) = '1'.<br><br>When this register is exposed by a Virtual Function (VF), this bit only controls restoring the state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 10 | Enable Wrap Event (EWE) - RW. Default = '0'. When set to '1', the xHC shall generate a MFINDEX Wrap Event every time the MFINDEX register transitions from 03FFFh to 0. When cleared to '0' no MFINDEX Wrap Events are generated. Refer to section 4.14.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the generation of MFINDEX Wrap Events to VFs shall be emulated by the VMM. |
| 11 | Enable U3 MFINDEX Stop (EU3S) - RW. Default = '0'. When set to '1', the xHC may stop the MFINDEX counting action if all Root Hub ports are in the U3, Disconnected, Disabled, or Powered-off state. When cleared to '0' the xHC may stop the MFINDEX counting action if all Root Hub ports are in the Disconnected, Disabled, Training, or Powered-off state. Refer to section 4.14.2 for more information. |
| 12 | RsvdP. |
| 13 | CEM Enable (CME) - RW. Default = '0'. When set to '1', a Max Exit Latency Too Large Capability Error may be returned by a Configure Endpoint Command. When cleared to '0', a Max Exit Latency Too Large Capability Error shall not be returned by a Configure Endpoint Command. This bit is Reserved if CMC = '0'. Refer to section 4.23.5.2.2 for more information. |
| 14 | Extended TBC Enable (ETE). This flag indicates that the host controller implementation is enabled to support Transfer Burst Count (TBC) values greater that 4 in isoch TDs. When this bit is '1', the Isoch TRB TD Size/TBC field presents the TBC value, and the TBC/RsvdZ field is RsvdZ. When this bit is '0', the TDSize/TCB field presents the TD Size value, and the TBC/RsvdZ field presents the TBC value. This bit may be set only if ETC = '1'. Refer to section 4.11.2.3 for more information. |
| 15 | Extended TBC TRB Status Enable (TSC_EN). This flag indicates that the host controller implementation is enabled to support ETC_TSC capability. When this is '1', TRBSts field in the TRB updated to indicate if it is last transfer TRB in the TD. This bit may be set only if ETC_TSC='1'. Refer to section 4.11.2.3 for more information. |
| 16 | VTIO Enable (VTIOE) – RW. Default = '0'. When set to '1', XHCI HW will enable its VTIO capability and begin to use the information provided via that VTIO Registers to determine its DMA-ID. When cleared to '0', XHCI HW will use the Primary DMA-ID for all accesses. This bit may be set only if VTC = '1'. |
| 31:17 | RsvdP. |

### USBSTS

USB Status Register.

| Bit | Description |
| --- | --- |
| 0 | HCHalted (HCH) – RO. Default = '1'. This bit is a '0' whenever the Run/Stop (R/S) bit is a '1'. The xHC sets this bit to '1' after it has stopped executing as a result of the Run/Stop (R/S) bit being cleared to '0', either by software or by the xHC hardware (e.g. internal error).<br><br>If this bit is '1', then SOFs, microSOFs, or Isochronous Timestamp Packets (ITP) shall not be generated by the xHC, and any received Transaction Packet shall be dropped.<br><br>When this register is exposed by a Virtual Function (VF), this bit only reflects the Halted state of the xHC instance presented by the selected VF. Refer to section 8 for more information. |
| 1 | RsvdZ. |
| 2 | Host System Error (HSE) – RW1C. Default = '0'. The xHC sets this bit to '1' when a serious error is detected, either internal to the xHC or during a host system access involving the xHC module. (In a PCI system, conditions that set this bit to '1' include PCI Parity error, PCI Master Abort, and PCI Target Abort.) When this error occurs, the xHC clears the Run/Stop (R/S) bit in the USBCMD register to prevent further execution of the scheduled TDs. If the HSEE bit in the USBCMD register is a '1', the xHC shall also assert out-of-band error signaling to the host. Refer to section 4.10.2.6 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the assertion of this bit affects all VFs and reflects the Host System Error state of the Physical Function (PF0). Refer to section 8 for more information. |
| 3 | Event Interrupt (EINT) – RW1C. Default = '0'. The xHC sets this bit to '1' when the Interrupt Pending (IP) bit of any Interrupter transitions from '0' to '1'. Refer to section 7.1.2 for use.<br><br>Software that uses EINT shall clear it prior to clearing any IP flags. A race condition may occur if software clears the IP flags then clears the EINT flag, and between the operations another IP '0' to '1' transition occurs. In this case the new IP transition shall be lost.<br><br>When this register is exposed by a Virtual Function (VF), this bit is the logical 'OR' of the IP bits for the Interrupters assigned to the selected VF. And it shall be cleared to '0' when all associated interrupter IP bits are cleared, i.e. all the VF's Interrupter Event Ring(s) are empty. Refer to section 8 for more information. |
| 4 | Port Change Detect (PCD) – RW1C. Default = '0'. The xHC sets this bit to a '1' when any port has a change bit transition from a '0' to a '1'.<br><br>This bit is allowed to be maintained in the Aux Power well. Alternatively, it is also acceptable that on a D3 to D0 transition of the xHC, this bit is loaded with the OR of all of the PORTSC change bits. Refer to section 4.19.3.<br><br>This bit provides system software an efficient means of determining if there has been Root Hub port activity. Refer to section 4.15.2.3 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the Root Hub Ports associated with the Device Slots assigned to the selected VF. Refer to section 8 for more information. |
| 7:5 | RsvdZ. |
| 8 | Save State Status (SSS) - RO. Default = '0'. When the Controller Save State (CSS) flag in the USBCMD register is written with '1' this bit shall be set to '1' and remain 1 while the xHC saves its internal state. When the Save State operation is complete, this bit shall be cleared to '0'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the saving the state for the selected VF. Refer to section 8 for more information. |
| 9 | Restore State Status (RSS) - RO. Default = '0'. When the Controller Restore State (CRS) flag in the USBCMD register is written with '1' this bit shall be set to '1' and remain 1 while the xHC restores its internal state. When the Restore State operation is complete, this bit shall be cleared to '0'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the restoring the state for the selected VF. Refer to section 8 for more information. |
| 10 | Save/Restore Error (SRE) - RW1C. Default = '0'. If an error occurs during a Save or Restore operation this bit shall be set to '1'. This bit shall be cleared to '0' when a Save or Restore operation is initiated or when written with '1'. Refer to section 4.23.2 for more information.<br><br>When this register is exposed by a Virtual Function (VF), the VMM determines the state of this bit as a function of the Save/Restore completion status for the selected VF. Refer to section 8 for more information. |
| 11 | Controller Not Ready (CNR) – RO. Default = '1'. '0' = Ready and '1' = Not Ready. Software shall not write any Doorbell or Operational register of the xHC, other than the USBSTS register, until CNR = '0'. This flag is set by the xHC after a Chip Hardware Reset and cleared when the xHC is ready to begin accepting register writes. This flag shall remain cleared ('0') until the next Chip Hardware Reset. |
| 12 | Host Controller Error (HCE) – RO. Default = 0. 0' = No internal xHC error conditions exist and '1' = Internal xHC error condition. This flag shall be set to indicate that an internal error condition has been detected which requires software to reset and reinitialize the xHC. Refer to section 4.24.1 for more information. |
| 31:13 | RsvdZ. |

### MFINDEX

Microframe Index Register.

| Bit | Description |
| --- | --- |
| 13:0 | Microframe Index – RO. The value in this register increments at the end of each microframe (e.g. 125us.). Bits 13:3 may be used to determine the current 1ms. Frame Index. |
| 31:14 | RsvdZ. |

### IMAN

Interrupter Management Register.

| Bit | Description |
| --- | --- |
| 0 | Interrupt Pending (IP) - RW1C. Default = '0'. This flag represents the current state of the Interrupter. If IP = '1', an interrupt is pending for this Interrupter. A '0' value indicates that no interrupt is pending for the Interrupter. Refer to section 4.17.3 for the conditions that modify the state of this flag. |
| 1 | Interrupt Enable (IE) – RW. Default = '0'. This flag specifies whether the Interrupter is capable of generating an interrupt. When this bit and the IP bit are set ('1'), the Interrupter shall generate an interrupt when the Interrupter Moderation Counter reaches '0'. If this bit is '0', then the Interrupter is prohibited from generating interrupts. |
| 31:2 | RsvdP. |

### ERSTSZ

Event Ring Segment Table Size Register.

| Bit | Description |
| --- | --- |
| 15:0 | Event Ring Segment Table Size – RW. Default = '0'. This field identifies the number of valid Event Ring Segment Table entries in the Event Ring Segment Table pointed to by the Event Ring Segment Table Base Address register. The maximum value supported by an xHC implementation for this register is defined by the ERST Max field in the HCSPARAMS2 register (5.3.4).<br><br>For Secondary Interrupters: Writing a value of '0' to this field disables the Event Ring. Any events targeted at this Event Ring when it is disabled shall result in undefined behavior of the Event Ring.<br><br>For the Primary Interrupter: Writing a value of '0' to this field shall result in undefined behavior of the Event Ring. The Primary Event Ring cannot be disabled. |
| 31:16 | RsvdP. |

### ERSTBA

Event Ring Segment Table Base Address Register.

| Bit | Description |
| --- | --- |
| 5:0 | RsvdP. |
| 63:6 | Event Ring Segment Table Base Address Register – RW. Default = '0'. This field defines the high order bits of the start address of the Event Ring Segment Table.<br><br>Writing this register sets the Event Ring State Machine:EREP Advancement to the Start state. Refer to Figure 4-12 for more information.<br><br>For Secondary Interrupters: This field may be modified at any time.<br><br>For the Primary Interrupter: This field shall not be modified if HCHalted (HCH) = '0'. |

### ERDP

Event Ring Dequeue Pointer Register.

| Bit | Description |
| --- | --- |
| 2:0 | Dequeue ERST Segment Index (DESI) – RW. Default = '0'. This field may be used by the xHC to accelerate checking the Event Ring full condition. This field is written with the low order 3 bits of the offset of the ERST entry which defines the Event Ring segment that the Event Ring Dequeue Pointer resides in. Refer to section 6.5 for the definition of an ERST entry. |
| 3 | Event Handler Busy (EHB) - RW1C. Default = '0'. This flag shall be set to '1' when the IP bit is set to '1' and cleared to '0' by software when the Dequeue Pointer register is written. Refer to section 4.17.2 for more information. |
| 63:4 | Event Ring Dequeue Pointer - RW. Default = '0'. This field defines the high order bits of the 64-bit address of the current Event Ring Dequeue Pointer. |

# Power Plan

### Noverse Performance

It's a clone of `SCHEME_MIN` including ~60 changes related to disabling parking/selective suspend/(deep) sleep/battery features/ display dimming/hard disk power savings/slide show/PAPB features, several changes to the processor power management (keeps processor idle enabled, which shouldn't be changed). This can be used by desktop users.

### Noverse Balanced

This power plan should be used by laptop users, it's a clone of `SCHEME_BALANCED` including several specific changes, e.g. pausing slide shows, changing time check intervals while keeping power savings (to prevent overheating) and subgroup settings of `Battery`, `Presence Aware Power Behaviour`, `Display`, `Sleep` etc. unchanged.

## Power Settings Documentation

Most markdown files below are backed up from [windows-hardware/customize/power-settings](https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-power-settings), many missing or incomplete parts were also added manually by me (mentioned on the top if so), with the additional setting/value data gathered via the PowrProf API (`PowerReadPossibleDescription`, `PowerReadFriendlyName`, `PowerReadPossibleFriendlyName`, `PowerReadValueMin`, `PowerReadValueMax`, `PowerReadValueIncrement`, `PowerReadValueUnits`).

Structure is heading level 3 = subgroup name, linked text = setting name, the brackets include `PowerCfg` naming & setting GUID.

### [Settings belonging to no subgroup](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings.md)

- [Require a password on wakeup](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings-prompt-for-password-on-resume.md) (`CONSOLELOCK`, `0e796bdb-100d-47d6-a2d5-f7d2daa51f51`)
- [Power plan type](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings.md#power-plan-type) (`PERSONALITY`, `245d8541-3943-4422-b025-13a784f679b7`)
- [Device idle policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings-device-idle-policy.md) (`DEVICEIDLE`, `4faab71a-92e5-4726-b531-224559672d19`)
- [Disconnected Standby Mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings.md#disconnected-standby-mode) (`DISCONNECTEDSTANDBYMODE`, `68afb2d9-ee95-47a8-8f50-4115088073b1`)
- [Networking connectivity in Standby](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/no-subgroup-settings-allow-networking-during-standby.md) (`CONNECTIVITYINSTANDBY`, `f15576e8-98b7-4186-b944-eafa664402d9`)

### [Hard disk](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md)

- [AHCI Link Power Management - HIPM/DIPM](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings-link-power-management-mode---hipm-dipm.md) (`0b2d69d7-a2a1-449c-9680-f91c70521c60`)
- [Maximum Power Level](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#maximum-power-level) (`DISKMAXPOWER`, `51dea550-bb38-4bc4-991b-eacf37be5ec8`)
- [Turn off hard disk after](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings-disk-idle-timeout.md) (`DISKIDLE`, `6738e2c4-e8a5-4a42-b16a-e040e769756e`)
- [Hard disk burst ignore time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings-disk-burst-ignore-time.md) (`DISKBURSTIGNORE`, `80e3c60e-bb94-4ad8-bbe0-0d3195efc663`)
- [Secondary NVMe Idle Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#secondary-nvme-idle-timeout) (`d3d55efd-c1ff-424e-9dc3-441be7833010`)
- [Primary NVMe Idle Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#primary-nvme-idle-timeout) (`NVMEPRIMARYIDLETIMEOUT`, `d639518a-e56d-4345-8af2-b9f32fb26109`)
- [AHCI Link Power Management - Adaptive](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings-link-power-management-mode---adaptive.md) (`dab60367-53fe-4fbc-825e-521d069d2456`)
- [Secondary NVMe Power State Transition Latency Tolerance](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#secondary-nvme-power-state-transition-latency-tolerance) (`dbc9e238-6de9-49e3-92cd-8c2b4946b472`)
- [NVMe NOPPME](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#nvme-noppme) (`DISKNVMENOPPME`, `fc7372b6-ab2d-43ee-8797-15e9841f2cca`)
- [Primary NVMe Power State Transition Latency Tolerance](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/disk-settings.md#primary-nvme-power-state-transition-latency-tolerance) (`fc95af4d-40e7-4b6d-835a-56d131dbc80e`)

### [Desktop background settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Slide show](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#slide-show) (`309dce9b-bef4-4119-9921-a851fb12f0f4`)

### [Wireless Adapter Settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Power Saving Mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#power-saving-mode) (`12bbebe6-58d6-4636-95bb-3217ef867c1a`)

### [Sleep](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings.md)

- [Legacy RTC mitigations](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings.md#legacy-rtc-mitigations) (`LEGACYRTCMITIGATION`, `1a34bdc3-7e6b-442e-a9d0-64b6ef378e84`)
- [Allow Away Mode Policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-allow-away-mode.md) (`AWAYMODE`, `25dfa149-5dd1-4736-b5ab-e8a37b5b8187`)
- [Sleep after](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-sleep-idle-timeout.md) (`STANDBYIDLE`, `29f6c1db-86da-48c5-9fdb-f2b67b1f44da`)
- [System unattended sleep timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-sleep-unattended-idle-timeout.md) (`UNATTENDSLEEP`, `7bc4a2f9-d8fc-4469-b07b-33eb785aaca0`)
- [Allow hybrid sleep](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-hybrid-sleep.md) (`HYBRIDSLEEP`, `94ac6d29-73ce-41a6-809f-6363ba21b47e`)
- [Hibernate after](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-hibernate-idle-timeout.md) (`HIBERNATEIDLE`, `9d7815a6-7ee4-497e-8888-515a05f02364`)
- [Allow system required policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-allow-system-required-requests.md) (`SYSTEMREQUIRED`, `a4b195f5-8225-47d8-8012-9d41369786e2`)
- [Allow Standby States](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-allow-sleep-states.md) (`ALLOWSTANDBY`, `abfc2519-3608-4c2a-94ea-171b0ed546ab`)
- [Allow wake timers](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-automatically-wake-for-tasks.md) (`RTCWAKE`, `bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d`)
- [Allow sleep with remote opens](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/sleep-settings-allow-sleep-with-open-remote-files.md) (`REMOTEFILESLEEP`, `d4c1d4c8-d5cc-43d3-b83e-fc51215cb04d`)

### [USB settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Hub Selective Suspend Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#hub-selective-suspend-timeout) (`0853a681-27c8-4100-a2fd-82013e970683`)
- [USB selective suspend setting](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#usb-selective-suspend-setting) (`48e6b7a6-50f5-4782-a5d4-53bb8f07e226`)
- [Setting IOC on all TDs](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#setting-ioc-on-all-tds) (`498c044a-201b-4631-a522-5c744ed4e678`)
- [USB 3 Link Power Mangement](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#usb-3-link-power-mangement) (`d4e98f31-5ffe-4ce1-be31-1b38b384c009`)

### [Idle Resiliency](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Execution Required power request timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#execution-required-power-request-timeout) (`EXECTIME`, `3166bc41-7e98-4e03-b34e-ec0f5f2b218e`)
- [IO coalescing timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#io-coalescing-timeout) (`COALTIME`, `c36f0eb4-2988-4a70-8eee-0884fc2c2433`)
- [Processor Idle Resiliency Timer Resolution](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#processor-idle-resiliency-timer-resolution) (`PROCIR`, `c42b79aa-aa3a-484b-a98f-2cf32aa90a28`)
- [Deep Sleep Enabled/Disabled](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#deep-sleep-enableddisabled) (`DEEPSLEEP`, `d502f7ee-1dc7-4efd-a55d-f04b6f5c0545`)

### [Interrupt Steering Settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Interrupt Steering Mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#interrupt-steering-mode) (`MODE`, `2bfc24f9-5ea2-4801-8213-3dbae01aa39d`)
- [Target Load](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#target-load) (`PERPROCLOAD`, `73cde64d-d720-4bb2-a860-c755afe77ef2`)
- [Unparked time trigger](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#unparked-time-trigger) (`UNPARKTIME`, `d6ba4903-386f-4c2c-8adb-5c21b3328d25`)

### [Power buttons and lid](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings.md)

- [Lid close action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings-lid-switch-close-action.md) (`LIDACTION`, `5ca83367-6e45-459f-a27b-476b1d01c936`)
- [Power button action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings-power-button-action.md) (`PBUTTONACTION`, `7648efa3-dd9c-4e3e-b566-50f929386280`)
- [Enable forced button/lid shutdown](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings-power-button-forced-shutdown.md) (`SHUTDOWN`, `833a6b62-dfa4-46d1-82f8-e09e34d029d6`)
- [Sleep button action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings-sleep-button-action.md) (`SBUTTONACTION`, `96996bc0-ad50-47ec-923b-6f41874dd9eb`)
- [Lid open action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/lid-open-wake-action.md) (`LIDOPENWAKE`, `99ff10e7-23b1-4c07-a9d1-5c3206d741b4`)
- [Start menu power button](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/power-button-and-lid-settings.md#start-menu-power-button) (`UIBUTTON_ACTION`, `a7066653-8d6c-40a8-910e-a1f54b84c7e5`)

### [PCI Express](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/pci-express-settings.md)

- [Link State Power Management](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/pci-express-settings-link-state-power-management.md) (`ASPM`, `ee12f906-d277-404b-b6da-e5fa1a576df5`)

### [Processor power management](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md)

- [Processor performance increase threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasethreshold.md) (`PERFINCTHRESHOLD`, `06cadf0e-64ed-448a-8927-ce7bf90eb35d`)
- [Processor performance increase threshold for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasethreshold.md) (`PERFINCTHRESHOLD1`, `06cadf0e-64ed-448a-8927-ce7bf90eb35e`)
- [Processor performance core parking min cores](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpmincores.md) (`CPMINCORES`, `0cc5b647-c1df-4637-891a-dec35c318583`)
- [Processor performance core parking min cores for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpmincores.md) (`CPMINCORES1`, `0cc5b647-c1df-4637-891a-dec35c318584`)
- [Processor performance decrease threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasethreshold.md) (`PERFDECTHRESHOLD`, `12a0ab44-fe28-4fa9-b3bd-4b64f44960a6`)
- [Processor performance decrease threshold for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasethreshold.md) (`PERFDECTHRESHOLD1`, `12a0ab44-fe28-4fa9-b3bd-4b64f44960a7`)
- [Initial performance for Processor Power Efficiency Class 1 when unparked](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heteroclass1initialperf.md) (`HETEROCLASS1INITIALPERF`, `1facfc65-a930-4bc5-9f38-504ec097bbc0`)
- [Processor performance core parking concurrency threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpconcurrency.md) (`CPCONCURRENCY`, `2430ab6f-a520-44a2-9601-f7f23b5134b1`)
- [Processor performance core parking increase time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpincreasetime.md) (`CPINCREASETIME`, `2ddd5a84-5a71-437e-912a-db0b8c788732`)
- [Processor energy performance preference policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfenergypreference.md) (`PERFEPP`, `36687f9e-e3a5-4dbf-b1dc-15eb381c6863`)
- [Processor energy performance preference policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfenergypreference.md) (`PERFEPP1`, `36687f9e-e3a5-4dbf-b1dc-15eb381c6864`)
- [Allow Throttle States](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#allow-throttle-states) (`THROTTLING`, `3b04d4fd-1cc7-4f23-ab1c-d1337819c4bb`)
- [Processor performance increase time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heteroincreasetime.md) (`HETEROINCREASETIME`, `4009efa7-e72d-4cba-9edf-91084ea8cbc3`)
- [Processor performance decrease policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasepolicy.md) (`PERFDECPOL`, `40fbefc7-2e9d-4d25-a185-0cfd8574bac6`)
- [Processor performance decrease policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasepolicy.md) (`PERFDECPOL1`, `40fbefc7-2e9d-4d25-a185-0cfd8574bac7`)
- [Long running threads' processor architecture lower limit](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold.md) (`LONGTHREADARCHCLASSLOWERTHRESHOLD`, `43f278bc-0f8a-46d0-8b31-9a23e615d713`)
- [Processor performance core parking parked performance state](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-parked-performance-state) (`CPPERF`, `447235c7-6a8d-4cc0-8e24-9eaf70b96e2b`)
- [Processor performance core parking parked performance state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-parked-performance-state-for-processor-power-efficiency-class-1) (`CPPERF1`, `447235c7-6a8d-4cc0-8e24-9eaf70b96e2c`)
- [Processor performance boost policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/legacy-config-options-perfboostpol.md) (`PERFBOOSTPOL`, `45bcc044-d885-43e2-8605-ee0ec6e96b59`)
- [Processor performance increase policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasepolicy.md) (`PERFINCPOL`, `465e1f50-b610-473a-ab58-00d1077dc418`)
- [Processor performance increase policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasepolicy.md) (`PERFINCPOL1`, `465e1f50-b610-473a-ab58-00d1077dc419`)
- [Latency sensitivity hint processor energy performance preference](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-latencyhintepp.md) (`LATENCYHINTEPP`, `4b70f900-cdd9-4e66-aa26-ae8417f98173`)
- [Latency sensitivity hint processor energy performance preference for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-latencyhintepp.md) (`LATENCYHINTEPP1`, `4b70f900-cdd9-4e66-aa26-ae8417f98174`)
- [Processor idle demote threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-idledemotethreshold.md) (`IDLEDEMOTE`, `4b92d758-5a24-4851-a470-815d78aee119`)
- [Processor performance core parking distribution threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpdistribution.md) (`CPDISTRIBUTION`, `4bdaf4e9-d103-46d7-a5f0-6280121616ef`)
- [Processor performance time check interval](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-time-check-interval) (`PERFCHECK`, `4d2b0152-7d5c-498b-88e2-34345392a2c5`)
- [Processor duty cycling](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-dutycycling.md) (`PERFDUTYCYCLING`, `4e4450b3-6179-4e91-b8f1-5bb9938f81a1`)
- [Short running threads' processor architecture lower limit](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold.md) (`SHORTTHREADARCHCLASSLOWERTHRESHOLD`, `53824d46-87bd-4739-aa1b-aa793fac36d6`)
- [Processor idle disable](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-idle-disable) (`IDLEDISABLE`, `5d76a2ca-e8c0-402f-a133-2158492d58ad`)
- [Latency sensitivity hint min unparked cores/packages](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cplatencyhintunpark.md) (`LATENCYHINTUNPARK`, `616cdaa5-695e-4545-97ad-97dc2d1bdd88`)
- [Latency sensitivity hint min unparked cores/packages for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cplatencyhintunpark.md) (`LATENCYHINTUNPARK1`, `616cdaa5-695e-4545-97ad-97dc2d1bdd89`)
- [Latency sensitivity hint processor performance](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perflatencyhint.md) (`LATENCYHINTPERF`, `619b7505-003b-4e82-b7a6-4dd29c300971`)
- [Latency sensitivity hint processor performance for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perflatencyhint.md) (`LATENCYHINTPERF1`, `619b7505-003b-4e82-b7a6-4dd29c300972`)
- [Processor idle threshold scaling](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-idle-threshold-scaling) (`IDLESCALING`, `6c2993b0-8f48-481f-bcc6-00dd2742aa06`)
- [Processor performance core parking decrease policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-decrease-policy) (`CPDECREASEPOL`, `71021b41-c749-4d21-be74-a00f335d582b`)
- [Maximum processor frequency](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxfrequency.md) (`PROCFREQMAX`, `75b0ae3f-bce0-45a7-8c89-c9611c25e100`)
- [Maximum processor frequency for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxfrequency.md) (`PROCFREQMAX1`, `75b0ae3f-bce0-45a7-8c89-c9611c25e101`)
- [Processor idle promote threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-idlepromotethreshold.md) (`IDLEPROMOTE`, `7b224883-b3cc-4d79-819f-8374152cbe7c`)
- [Processor performance history count](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-history-count) (`PERFHISTORY`, `7d24baa7-0b84-480f-840c-1b0743c00f5f`)
- [Processor performance history count for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-history-count-for-processor-power-efficiency-class-1) (`PERFHISTORY1`, `7d24baa7-0b84-480f-840c-1b0743c00f60`)
- [Processor performance decrease time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heterodecreasetime.md) (`HETERODECREASETIME`, `7f2492b6-60b1-45e5-ae55-773f8cd5caec`)
- [Heterogeneous policy in effect](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#heterogeneous-policy-in-effect) (`HETEROPOLICY`, `7f2f5cfa-f10c-4823-b5e1-e93ae85f46b5`)
- [Short running threads' processor architecture upper limit](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclassupperthreshold.md) (`SHORTTHREADARCHCLASSUPPERTHRESHOLD`, `828423eb-8662-4344-90f7-52bf15870f5a`)
- [Minimum processor state](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-minperformance.md) (`PROCTHROTTLEMIN`, `893dee8e-2bef-41e0-89c6-b55d0929964c`)
- [Minimum processor state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-minperformance.md) (`PROCTHROTTLEMIN1`, `893dee8e-2bef-41e0-89c6-b55d0929964d`)
- [Processor performance autonomous mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfautonomousmode.md) (`PERFAUTONOMOUS`, `8baa4a8a-14c6-4451-8e8b-14bdbd197537`)
- [Heterogeneous thread scheduling policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-schedulingpolicy.md) (`SCHEDPOLICY`, `93b8b6dc-0698-4d1c-9ee4-0644e900c85d`)
- [Processor performance core parking overutilization threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-overutilization-threshold) (`CPOVERUTIL`, `943c8cb6-6f93-4227-ad87-e9a3feec08d1`)
- [System cooling policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#system-cooling-policy) (`SYSCOOLPOL`, `94d3a615-a899-4ac5-ae2b-e4d8f634367f`)
- [Processor performance core parking soft park latency](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-softparklatency.md) (`SOFTPARKLATENCY`, `97cfac41-2217-47eb-992d-618b1977c907`)
- [Processor performance increase time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasetime.md) (`PERFINCTIME`, `984cf492-3bed-4488-a8f9-4286c97bf5aa`)
- [Processor performance increase time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfincreasetime.md) (`PERFINCTIME1`, `984cf492-3bed-4488-a8f9-4286c97bf5ab`)
- [Processor idle state maximum](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-idle-state-maximum) (`IDLESTATEMAX`, `9943e905-9a30-4ec1-9b99-44dd3b76f7a2`)
- [Processor performance level increase threshold for Processor Power Efficiency Class 1 processor count increase](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold.md) (`HETEROINCREASETHRESHOLD`, `b000397d-9b0b-483d-98c9-692a6060cfbf`)
- [Processor performance level increase threshold for Processor Power Efficiency Class 2 processor count increase](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold1.md) (`HETEROINCREASETHRESHOLD1`, `b000397d-9b0b-483d-98c9-692a6060cfc0`)
- [Module unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-moduleunparkpolicy.md) (`MODULEUNPARKPOLICY`, `b0deaf6b-59c0-4523-8a45-ca7f40244114`)
- [Smt threads unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-smtunparkpolicy.md) (`SMTUNPARKPOLICY`, `b28a6829-c5f7-444e-8f61-10e24e85c532`)
- [Complex unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-complexunparkpolicy.md) (`COMPLEXUNPARKPOLICY`, `b669a5e9-7b1d-4132-baaa-49190abcfeb6`)
- [Heterogeneous short running thread scheduling policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortschedulingpolicy.md) (`SHORTSCHEDPOLICY`, `bae08b81-2d5e-4688-ad6a-13243356654b`)
- [Maximum processor state](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxperformance.md) (`PROCTHROTTLEMAX`, `bc5038f7-23e0-4960-96da-33abaf5935ec`)
- [Maximum processor state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxperformance.md) (`PROCTHROTTLEMAX1`, `bc5038f7-23e0-4960-96da-33abaf5935ed`)
- [Processor performance boost mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfboostmode.md) (`PERFBOOSTMODE`, `be337238-0d82-4146-a960-4f3749d470c7`)
- [Long running threads' processor architecture upper limit](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold.md) (`LONGTHREADARCHCLASSUPPERTHRESHOLD`, `bf903d33-9d24-49d3-a468-e65e0325046a`)
- [Processor idle time check](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-idle-time-check) (`IDLECHECK`, `c4581c31-89ab-4597-8e2b-9c9cab440e6b`)
- [Processor performance core parking increase policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-increase-policy) (`CPINCREASEPOL`, `c7be0679-2817-4d69-9d02-519a537ed0c6`)
- [Processor autonomous activity window](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfautonomouswindow.md) (`PERFAUTONOMOUSWINDOW`, `cfeda3d0-7697-4566-a922-a9086cd49dfa`)
- [Processor performance decrease time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasetime.md) (`PERFDECTIME`, `d8edeb9b-95cf-4f95-a73c-b061973693c8`)
- [Processor performance decrease time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfdecreasetime.md) (`PERFDECTIME1`, `d8edeb9b-95cf-4f95-a73c-b061973693c9`)
- [Short vs. long running thread threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) (`SHORTTHREADRUNTIMETHRESHOLD`, `d92998c2-6a48-49ca-85d4-8cceec294570`)
- [Processor performance core parking decrease time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpdecreasetime.md) (`CPDECREASETIME`, `dfd10d17-d5eb-45dd-877a-9a34ddd15c82`)
- [Processor performance core parking utility distribution](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-utility-distribution) (`DISTRIBUTEUTIL`, `e0007330-f589-42ed-a401-5ddb10e785d3`)
- [Processor performance core parking max cores](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpmaxcores.md) (`CPMAXCORES`, `ea062031-0e34-4ff1-9b6d-eb1059334028`)
- [Processor performance core parking max cores for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpmaxcores.md) (`CPMAXCORES1`, `ea062031-0e34-4ff1-9b6d-eb1059334029`)
- [Processor performance core parking concurrency headroom threshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-core-parking-cpheadroom.md) (`CPHEADROOM`, `f735a673-2066-4f80-a0c5-ddee0cf1bf5d`)
- [Processor performance level decrease threshold for Processor Power Efficiency Class 1 processor count decrease](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold.md) (`HETERODECREASETHRESHOLD`, `f8861c27-95e7-475c-865b-13c0cb3f9d6b`)
- [Processor performance level decrease threshold for Processor Power Efficiency Class 2 processor count decrease](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold1.md) (`HETERODECREASETHRESHOLD1`, `f8861c27-95e7-475c-865b-13c0cb3f9d6c`)
- [A floor performance for Processor Power Efficiency Class 0 when there are Processor Power Efficiency Class 1 processors unparked](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-heteroclass0floorperf.md) (`HETEROCLASS0FLOORPERF`, `fddc842b-8364-4edc-94cf-c17f60de1c80`)

### [Graphics settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [GPU preference policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#gpu-preference-policy) (`GPUPREFERENCEPOLICY`, `dd848b2a-8a5d-4451-9ae2-39cd41658f6c`)

### [Display](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings.md)

- [Dim display after](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-dim-annoyance-timeout.md) (`VIDEODIM`, `17aaa29b-8b43-4b94-aafe-35f64daaf1ee`)
- [Turn off display after](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-display-idle-timeout.md) (`VIDEOIDLE`, `3c0bc021-c8a8-4e07-a973-6b14cbcb2b7e`)
- [Advanced Color quality bias](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-advanced-color-quality-bias.md) (`ADVANCEDCOLORQUALITYBIAS`, `684c3e69-a4f7-4014-8754-d45179a56167`)
- [Console lock display off timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings.md#console-lock-display-off-timeout) (`VIDEOCONLOCK`, `8ec4b3a5-6868-48c2-be75-4f3044be88a7`)
- [Adaptive display](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-adaptive-display-idle-timeout.md) (`VIDEOADAPT`, `90959d22-d6a1-49b9-af93-bce885ad335b`)
- [Allow display required policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-allow-display-required-policy.md) (`ALLOWDISPLAY`, `a9ceb8da-cd46-44fb-a98b-02af69de4623`)
- [Display brightness](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-display-brightness-level.md) (`VIDEONORMALLEVEL`, `aded5e82-b909-4619-9949-f5d71dac0bcb`)
- [Dimmed display brightness](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings-dim-display-brightness.md) (`f1fbfde2-a960-4165-9f88-50667911ce96`)
- [Enable adaptive brightness](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/display-settings.md#enable-adaptive-brightness) (`ADAPTBRIGHT`, `fbd9aa66-9553-4097-ba44-ed6e9d65eab8`)

### [Presence Aware Power Behavior](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/presence-adaptive.md)

- [Human Presence Sensor Adaptive Away Display Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/presence-adaptive-away-display-timeout.md) (`HUPRVIDEOIDLE`, `0a7d6ab6-ac83-4ad1-8282-eca5b58308f3`)
- [Standby Reserve Time](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#standby-reserve-time) (`STANDBYRESERVETIME`, `468fe7e5-1158-46ec-88bc-5b96c9e44fd0`)
- [Standby Reset Percentage](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#standby-reset-percentage) (`STANDBYRESETPERCENT`, `49cb11a5-56e2-4afb-9d38-3df47872e21b`)
- [Non-sensor Input Presence Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#non-sensor-input-presence-timeout) (`NSENINPUTPRETIME`, `5adbbfbc-074e-4da1-ba38-db8b36b2c8f3`)
- [Standby Budget Grace Period](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#standby-budget-grace-period) (`STANDBYBUDGETGRACEPERIOD`, `60c07fe1-0556-45cf-9903-d56e32210242`)
- [User Presence Prediction mode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#user-presence-prediction-mode) (`USERPRESENCEPREDICTION`, `82011705-fb95-4d46-8d35-4042b1d20def`)
- [Standby Budget Percent](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#standby-budget-percent) (`STANDBYBUDGETPERCENT`, `9fe527be-1b70-48da-930d-7bcf17b44990`)
- [Human Presence Sensor Adaptive Away Dim Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/presence-adaptive-away-dim-timeout.md) (`HUPRVIDEODIMAWAY`, `a79c8e0e-f271-482d-8f8a-5db9a18312de`)
- [Standby Reserve Grace Period](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#standby-reserve-grace-period) (`STANDBYRESERVEGRACEPERIOD`, `c763ee92-71e8-4127-84eb-f6ed043a3e3d`)
- [Human Presence Sensor Adaptive Inattentive Dim Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/presence-adaptive-inattentive-dim-timeout.md) (`HUPRVIDEODIM`, `cf8c6097-12b8-4279-bbdd-44601ee5209d`)
- [Human Presence Sensor Adaptive Inattentive Display Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/presence-adaptive-inattentive-display-timeout.md) (`HUPRVIDEOIDLEINATTENTIVE`, `ee16691e-6ab3-4619-bb48-1c77c9357e5a`)

### [Video playback quality](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md)

- [Video playback quality bias](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#video-playback-quality-bias) (`10778347-1370-4ee0-8bbd-33bdacaade49`)
- [When playing video](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configure-power-settings.md#when-playing-video) (`34c7b99f-9a6d-4b3c-8dc7-b6693b78cef4`)

### [Energy Saver settings](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/energy-saver-settings.md)

- [Display brightness weight](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/energy-saver-settings.md#display-brightness-weight) (`ESBRIGHTNESS`, `13d09884-f74e-474a-a852-b6bde8ad03a8`)
- [Energy Saver Policy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/energy-saver-settings.md#energy-saver-policy) (`ESPOLICY`, `5c5bb349-ad29-4ee2-9d0b-2b25270f7a81`)
- [Charge level](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/energy-saver-settings.md#charge-level) (`ESBATTTHRESHOLD`, `e69653ca-cf7f-4f05-aa73-cb833fa90ad4`)

### [Battery](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings.md)

- [Critical battery notification](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings.md#critical-battery-notification) (`BATFLAGSCRIT`, `5dbb7c9f-38e9-40d2-9749-4f8a0e9f640f`)
- [Critical battery action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings-critical-battery-action.md) (`BATACTIONCRIT`, `637ea02f-bbcb-4015-8e2c-a1c7b9c0b546`)
- [Low battery level](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings-low-battery-threshold.md) (`BATLEVELLOW`, `8183ba9a-e910-48da-8769-14ae6dc1170a`)
- [Critical battery level](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings-critical-battery-threshold.md) (`BATLEVELCRIT`, `9a66d8d7-4ff7-4ef9-b5a2-5a326ca2a469`)
- [Low battery notification](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings.md#low-battery-notification) (`BATFLAGSLOW`, `bcded951-187b-4d05-bccc-f7e51960c258`)
- [Low battery action](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings-low-battery-action.md) (`BATACTIONLOW`, `d8742dcb-3e6a-4b3c-b3fe-374623cdcf06`)
- [Reserve battery level](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/battery-settings-reserve-battery-level.md) (`f3c5027d-cd16-4930-aa6b-90db844a8f00`)

## Suboptions

I've added some specific settings to toggle some features if wanted, note that this applies to the current active scheme. If you want to change more specific settings rather use a tool such as [PowerSettingsExplorer](https://github.com/nohuto/win-config/blob/main/power/assets/PowerSettingsExplorer.exe).

### Default Schemes

`Delete` = deletes the default schemes (select one of the `Noverse x` schemes before deleting them, otherwise a scheme named `Noverse Temporary Scheme` gets created which is a clone of `SCHEME_BALANCED`):

```c
381b4222-f694-41f0-9685-ff5bb260df2e // SCHEME_BALANCED (Balanced)
8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c // SCHEME_MIN (High Performance)
a1841308-3541-4fab-bc81-f71556f20b4a // SCHEME_MAX (Power saver)
```

`Restore` = restores the default schemes, note that this removes all imported/custom plans

### Context Menu Import

Adds a `Import` option when right clicking on `.pow` files.

![](https://github.com/nohuto/win-config/blob/main/power/images/powcontextmenu.png?raw=true)

# Disable Timer Coalescing

## InitTimerCoalescing

`TimerCoalescing` (queried by [InitTimerCoalescing](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/InitTimerCoalescing.c)) is a binary value (`v18 == 3`) with a size of 80 bytes (`v19 == 80`), interpreted as 20 DWORDs. The value is used to load two four entry timer coalescing tolerance blocks.

```c
// InitTimerCoalescing

if ( ZwQueryValueKey(
      KeyHandle,
      &DestinationString,
      KeyValuePartialInformation,
      KeyValueInformation,
      0x60u,
      &ResultLength) >= 0
&& v16 == 3 // registry Type must be REG_BINARY
&& v17 == 80 // data must be exactly 20 DWORDs
&& !v18 ) // DWORD 0 must be zero
```

### Data Formatting

```c
// InitTimerCoalescing

for ( i = &v19; !*(_DWORD *)i; i += 4 ) // DWORDs 1-3 must be zero
{
  if ( (unsigned int)++v2 >= 3 )
  {
    v4 = 0;
    for ( j = &v21; !*(_DWORD *)j; j += 4 ) // DWORDs 8-11 must be zero
    {
      if ( (unsigned int)++v4 >= 4 )
      {
        v6 = 0;
        for ( k = &v23; !*(_DWORD *)k; k += 4 ) // DWORDs 16-19 must be zero
        {
          if ( (unsigned int)++v6 >= 4 )
          {
            v8 = 0;
            for ( m = &v20; *(_DWORD *)m <= 0x7FFFFFF5u; m = (__int128 *)((char *)m + 4) ) // DWORDs 4-7 range
            {
              if ( (unsigned int)++v8 >= 4 )
              {
                for ( n = &v22; *(_DWORD *)n <= 0x7FFFFFF5u; n = (__int128 *)((char *)n + 4) ) // DWORDs 12-15 range
                {
                  if ( (unsigned int)++v0 >= 4 )
                  {
                    xmmword_1C035A178 = v20; // stores one four DWORD tolerance block
                    *(_OWORD *)&gTimerCoalescingSpec = v22; // stores the other four DWORD tolerance block
                    SetTimerCoalescingTolerance(0LL); // applies mode 0 after load
```

| DWORD | Data | Note |
| --- | --- | --- |
| `0` | `0` | Reserved value checked before the loop validation |
| `1-3` | all `0` | Reserved |
| `4-7` | each `<= 0x7FFFFFF5` | Four accepted tolerance values, copied as one block |
| `8-11` | all `0` | Reserved |
| `12-15` | each `<= 0x7FFFFFF5` | Four accepted tolerance values, copied to `gTimerCoalescingSpec` |
| `16-19` | all `0` | Reserved |

Note that this only shows the data range etc., there's more information in relation to [`SetTimerCoalescingTolerance`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/SetTimerCoalescingTolerance.c) (mode selection), `gCurrentTimerCoalescingTolerance`, [`InternalSetTimer`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/InternalSetTimer.c), coalescable timers (affected ones) etc. I might or might not add more details whenever I've time.

## InitTimerPowerSaving

```c
// 23H2
void InitTimerPowerSaving(void)
{
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveElapse", 43200000LL, &gdwRITdaemonTimerPowerSaveElapse); // 12H
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveCoalescing", 43200000LL, &gdwRITdaemonTimerPowerSaveCoalescing); // 12H
}

// 2004
void InitTimerPowerSaving(void)
{
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveElapse", 43200000LL, &gdwRITdemonTimerPowerSaveElapse);
  FastGetProfileDword(0LL, 2LL, L"RITdemonTimerPowerSaveCoalescing", 43200000LL, &gdwRITdemonTimerPowerSaveCoalescing);
}
```

Looks like a typo from MS (`demon` = `daemon`), which got probably fixed within the first W11 builds, see  [diff 2004 & 21H2](https://noverse.dev/diff?kind=pseudocode&left=2004&right=11-21H2&module=win32kfull&name=-InitTimerPowerSaving%40%40YAXXZ.c&mode=side-by-side) comparision (the value name didn't change).

### When TimerPowerSaving Applies

`RITdemonTimerPowerSaveElapse` is the base timer interval. `RITdemonTimerPowerSaveCoalescing` is passed as the timer coalescing value into the timer setup path.

At [RawInputThread](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/RawInputThread.c) start it does call `InitTimerPowerSaving();` but also directly calls `ConfigureRITDelayableTimers(0);` which isn't the "TimerPowerSave" mode. So [`ConfigureRITDelayableTimers`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/-ConfigureRITDelayableTimers@@YAXW4RitTimerRate@@@Z.c) uses these values as we can see here:

```c
// ConfigureRITDelayableTimers
if ( !a1 ) goto LABEL_4;
if ( gnRITdaemonTimerId ) {
    if ( a1 != 1 ) {
        v2 = InternalSetTimer(
            0,
            gnRITdaemonTimerId,
            gdwRITdaemonTimerPowerSaveElapse,
            lambda_2bb7a2ff8864d6893c712a9e9ac801fb_::_lambda_invoker_cdecl_,
            gdwRITdaemonTimerPowerSaveCoalescing,
            4);
    } else {
LABEL_4:
        v2 = SetRITTimer(gnRITdaemonTimerId, 1000LL, ..., 0LL);
    }
}
```

This shows `a1 == 0` & `a1 == 1` don't use the TimerPowerSave values, so any other value uses them, but when does it get anything else than `0`/`1`?

```c
// SetTimerCoalescingTolerance
if ( !(_DWORD)v1 ) {
    gdwRITdaemonLockState = 0;
    return ConfigureRITDelayableTimers(1); // goes to LABEL_4
}

v7 = 2; // either 2
v8 = v1 - 2;
if ( !v8 ) {
    gdwRITdaemonLockState |= 1u;
    if ( (gdwRITdaemonLockState & 2) == 0
      && giScreenSaveTimeOutMs > 0
      && (gbLockConsoleActive || (*gpsi & 0x200) != 0) ) {
        v7 = 1; // or 1
    }
    return ConfigureRITDelayableTimers(v7);
}

if ( v8 == 1 ) {
    gdwRITdaemonLockState |= 2u;
    if ( (gdwRITdaemonLockState & 1) != 0 )
        return ConfigureRITDelayableTimers(2); // always 2 but only if bit 1 isn't 0
}
```

Note that only applies to non service sessions (`if ( v3 != gServiceSessionId )`, [SetTimerCoalescingTolerance](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/SetTimerCoalescingTolerance.c)).

So this TimerPowerSave part only applies when [`SetTimerCoalescingTolerance`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/win32kfull/SetTimerCoalescingTolerance.c) returns `ConfigureRITDelayableTimers(2)` which happens through lock/screensaver (`giScreenSaveTimeOutMs`)/session state transitions.

### Default Data

```c
lkd> dd win32kfull!gdwRITdaemonTimerPowerSaveElapse L1
fffff11d`f1289214  02932e00 // 43200000

lkd> dd win32kfull!gdwRITdaemonTimerPowerSaveCoalescing L1
fffffa1a`ab689210  02932e00 // 43200000
```

```c
// ConfigureRITDelayableTimers
v2 = InternalSetTimer(
        0,
        gnRITdaemonTimerId,
        gdwRITdaemonTimerPowerSaveElapse, // a3
        (unsigned int)lambda_2bb7a2ff8864d6893c712a9e9ac801fb_::_lambda_invoker_cdecl_,
        gdwRITdaemonTimerPowerSaveCoalescing, // a5
);

// InternalSetTimer
v10 = 10;
if ( a3 >= 0xA )
    v10 = a3;
if ( v10 > 0x7FFFFFFF )
    v10 = 0x7FFFFFFF;
*(_DWORD *)(v22 + 40) = v10;
*(_DWORD *)(v22 + 52) = v10;

// RITdemonTimerPowerSaveCoalescing
if ( a5 == -1 || !a5 && v14 && _bittest64((const signed __int64 *)(v14 + 648), 0x23u) )
    v15 = a6 & 0xFFFFFDFF;
else
    v15 = a6 | 0x200;
if ( (v15 & 0x200) != 0 )
    *(_DWORD *)(v22 + 44) = a5;

// false if bit 0x200 cleared
if ( (v32 & 0x200) != 0 )
{
    v34 = *(_DWORD *)(v22 + 44);
    v35 = gCurrentTimerCoalescingTolerance;
    v36 = gCurrentTimerCoalescingTolerance;
    v37 = *(_DWORD *)(v22 + 52);
    if ( v34 > gCurrentTimerCoalescingTolerance )
        v36 = *(_DWORD *)(v22 + 44);
    if ( v37 + v36 >= 0x7FFFFFFF )
    {
        v38 = 0x7FFFFFFF;
    }
    else
    {
        if ( v34 > gCurrentTimerCoalescingTolerance )
            v35 = *(_DWORD *)(v22 + 44);
        v38 = v37 + v35;
    }
}
else
{
    v38 = *(_DWORD *)(v22 + 52);
}
```

### Range (& Meaning)

#### RITdemonTimerPowerSaveElapse

- Default = `43200000`
- Minimum = `10`
- Maximum = `0x7FFFFFFF`

#### RITdemonTimerPowerSaveCoalescing

- Default = `43200000`
- No min/max clamp (means `0-0xFFFFFFFF`)
- `0xFFFFFFFF` (`-1`) disables coalescing here, as it always clears bit `0x200`, means no coalescing value is written
- `0` could also disable coalescing, but only when the thread has bit `0x800000000` set in `GetAppCompatFlags2QuadWord` (saved in THREADINFO)

You can dump the bit via WinDbg:

```c
lkd> !process 0 0 csrss.exe
PROCESS ffffdb8b6da2f080
    SessionId: 0  Cid: 02e4    Peb: f56fc32000  ParentCid: 02b8
    DirBase: 10a790000  ObjectTable: ffffb587a746dc40  HandleCount: 299.
    Image: csrss.exe

PROCESS ffffdb8b6ec33140
    SessionId: 1  Cid: 036c    Peb: 83046d0000  ParentCid: 035c
    DirBase: 10ffb9000  ObjectTable: ffffb587aa7a2c40  HandleCount: 454.
    Image: csrss.exe

lkd> .process /p /r ffffdb8b6ec33140
Implicit process is now ffffdb8b`6ec33140
Loading User Symbols
.......................
lkd> dq win32kbase!gptiRit L1
fffff11d`f0e94028  ffffb587`aa7b9010
lkd> r @$t0 = poi(win32kbase!gptiRit)
lkd> dq @$t0+0x288 L1
ffffb587`aa7b9298  00000000`00000000
lkd> ? poi(@$t0+0x288) & 0x800000000 // tagTHREADINFO offset
Evaluate expression: 0 = 00000000`00000000 // not set
```

## Miscellaneous Values

| Prefix | Component |
| --- | --- |
| `Pop` | Power Manager |

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "CoalescingTimerInterval" = 1500; // PopCoalescingTimerInterval (0x000005DC) - Units: seconds (multiplies value by -10,000,000, one second in 100 ns units, so the default corresponds to a 25min cadence)
    "DeepIoCoalescingEnabled" = 0; // PopDeepIoCoalescingEnabled 
```

The `CoalescingTimerInterval` value exist (takes a default of `1500` dec, `DeepIoCoalescingEnabled` one is set to `0` by default, both are located in `ntoskrnl.exe`), but doesn't get read on 24H2, the `RITdemonTimerPowerSave...` & `TimerCoalescing` ones get read.

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/power/images/coalesc.png?raw=true)

# PnP Device Values

This currently applies the values for the `USB` enumerator only, since most values were found in USB related drivers and kind of all of them (which I use in the option) only get read in the USB enumerator.

Disables USB selective suspend, idle states, and related LP features if supported.

## Registry Values

Windows Plug and Play (PnP) creates a device node (devnode) for each detected device instance ("The PnP manager is the primary component involved in supporting the ability of Windows to recognize and adapt to changing hardware configurations."). In WinDbg (`!devnode`), `InstancePath` assigns to the device instance key under:
```c
HKLM\SYSTEM\CurrentControlSet\Enum\<enumerator>\<deviceID>\<instanceID>

// miscellaneous notes
HKLM\SYSTEM\CurrentControlSet\Enum // hardware instance key - per-device-instance data
HKLM\SYSTEM\CurrentControlSet\Control\Class\{ClassGUID} // class key - class-wide settings and optional class filters
HKLM\SYSTEM\CurrentControlSet\Services\<ServiceName> // software key - service/driver configuration for the function or filter driver
```

### Common Subkeys under `<instanceID>`

- `Device Parameters`: Per-instance parameters and state used by the drivers in the stack
- `Properties`: Device property store for this instance
- `LogConf` (optional): Resource configuration data for the instance
- `Control` (optional): Additional PnP/device state

Not every instance has the same subkeys or values. I won't add details on the PnP manager here, as that's not the purpose of the option. For more details, read [Windows Internals E7, P1](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf), Chapter 6 (`The Plug and Play manager`).

### Default Data

One thing to point out here is that there're two APIs which I almost didn't notice. [`IoOpenDeviceRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendeviceregistrykey) & `PLUGPLAY_REGKEY_DEVICE` opens the per-device-instance hardware key in the `Enum` branch (`HKLM\SYSTEM\CCS\Enum\<Enumerator>\<DeviceID>\<InstanceID>\Device Parameters`). [`IoOpenDriverRegistryKey`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-ioopendriverregistrykey) opens the per-driver-service key in the `Services` branch (`HKLM\SYSTEM\CCS\Services\<ServiceName>\Parameters`). See [power/assets/pnp](https://github.com/nohuto/win-config/tree/main/power/assets/pnp) for all used functions.

A simple example here would be [GetEnhancedVerifierOptions](https://github.com/nohuto/win-config/tree/main/power/assets/pnp/GetEnhancedVerifierOptions.c) which uses `IoOpenDriverRegistryKey` and as you can see in a boot trace, `EnhancedVerifierOptions` is used in for example `\Registry\Machine\SYSTEM\ControlSet001\Services\PEAUTH\Parameters\Wdf : EnhancedVerifierOptions`.

`INF default` = install-time default from INF entries.

To create this list, I've used many driver pseudocodes (usbhub, winhub, acpi, pci, wdf, hidclass, USBHUB3...), several INF files, and W10 source for comments (which may not be accurate anymore).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters";
    "AllowIdleIrpInD3" = 1; // REG_DWORD (bool), INF default (input.inf)
    "CollectionReenumerateSelfInterfaceEnabled" = 0; // REG_DWORD (bool)
    "ComboHardwareIdV2Enabled" = 0; // REG_DWORD (bool)
    "CyclePortEnabled" = 0; // REG_DWORD (bool)
    "D3ColdReconnectTimeout" = 1000; // REG_DWORD
    "DefaultIdleState" = 1; // REG_DWORD (bool), "This registry value sets the default value of the AUTO_SUSPEND power policy setting. This registry key is used to enable or disable selective suspend when a handle isn't open to the device. A value of zero or the absence of this value indicates that by default, the device isn't suspended when idle. The device be allowed to suspend when idle only when the AUTO_SUSPEND power policy is enabled. A nonzero value indicates that by default the device can be suspended when idle. This value is ignored if DeviceIdleEnabled isn't set."
    "DefaultIdleTimeout" = 5000/30000; // REG_DWORD, the USBCCID UM driver uses 5sec, devices that support MTP use 30sec? (UsbccidDriver, wpdmtp) "This registry value sets the default state of the SUSPEND_DELAY power policy setting. The value indicates the amount of time in milliseconds to wait before determining that a device is idle."
    "DeviceIdleEnabled" = 1; // REG_DWORD (bool), ^ "This registry value indicates whether the device is capable of being powered down when idle (Selective Suspend)."
    "DeviceIdleIgnoreWakeEnable" = 1; // REG_DWORD (bool), ^ "When set to a nonzero value, it suspends the device even if it doesn't support RemoteWake."
    "DeviceInterfaceGUID" = "{52783fc2-0179-4eca-bb46-128bba61975e}"; // REG_SZ, written if missing by HUBREG_SetWinUsbIdleDefaults, WinUSB_GetRegParams uses it as fallback when DeviceInterfaceGUIDs is unavailable
    "DeviceInterfaceGUIDs" = "{...}"; // REG_MULTI_SZ, WinUSB example: {F72FE0D4-CBCB-407d-8814-9ED673D0DD6B}
    "DevicePowerUpOnS0Entry" = 1; // REG_DWORD, when 1 = "Always enter D0 upon resume from sleep regardless of IdleInWorkingState of its power policy owner"
    "DeviceResetNotificationEnabled" = 1; // REG_DWORD, INF default (input.inf, hidi2c.inf, hidspi_km.inf, hidvhf.inf)
    "DeviceSelectiveSuspended" = ?; // "Update Registry that this device has tried to selective Suspend."
    "EndpointPriorities" = ?; // validated by HUBREG_ValidateAndPopulateEndpointPriorities?
    "EnhancedPowerManagementEnabled" = 1; // REG_DWORD (bool)
    "EnhancedPowerManagementUseMonitor" = ?; // REG_DWORD (bool), read only when EnhancedPowerManagementEnabled is set to 1
    "ExtPropDescSemaphore" = 1; // REG_DWORD, written by HUBMISC_SetExtPropDescSemaphoreInRegistry, query path also checks RevisionId/VendorRevision, "Writes the "ExtPropDescSemaphore" registry flag to the device's hardware key to indicate that the device does not need to be queried for MS OS Extended Property Descriptors in the future.", "We only care whether or not it already exists, not what data it has."
    "ForceSelectiveSuspend" = ?; // REG_DWORD (bool?), from BthUsb_QuerySelectiveSuspend
    "FriendlyName" = ?; // REG_SZ
    "LegacyTouchScaling" = 0; // REG_DWORD, INF default (input.inf)
    "RemoteWakeEnabled" = ?; // REG_DWORD (bool)
    "ResetPortEnabled" = 0; // REG_DWORD (bool)
    "RetainWWIrpWhenDeviceAbsent" = 0; // REG_DWORD (bool)
    "RevisionId" = ; // REG_DWORD
    "SelectiveSuspendEnabled" = 0/1; // REG_DWORD/REG_BINARY (bool), INF has both, 0 in default install, 1 in selective-suspend opt-in (unsure when DWORD/BINARY is used, but when searching for the value in the standart hives via regkit you can see that it uses both types)
    "SelectiveSuspendOn" = 1; // REG_DWORD (bool)
    "SelectiveSuspendSupported" = ?; // REG_DWORD (bool?), from BthUsb_QuerySelectiveSuspend
    "SelectiveSuspendTimeout" = 5000; // REG_DWORD
    "SelSuspCancelBehavior" = ?; // REG_DWORD (bool)
    "SessionSecurityEnabled" = ?; // REG_DWORD (bool)
    "SuppressInputInCS" = 0; // REG_DWORD (bool), clears WakeScreenOnInputSupport when enabled?
    "SystemInputSuppressionEnabled" = 1; // REG_DWORD (bool)
    "SystemWakeEnabled" = 1; // REG_DWORD (bool), "This value indicates whether the device should be allowed to wake the system from a low power state. A value of zero, or the absence of this value indicates that the device isn't allowed to wake the system. To allow a device to wake the system, set SystemWakeEnabled to a nonzero value. A check box in the device Properties page is automatically enabled so that the user can override the setting."
    "TestIdleMonitorDim" = 1000; // REG_DWORD
    "TestIdleTimeoutNoHandles" = 1000; // REG_DWORD
    "TestIdleTimeoutNoHandlesInitial" = 5000; // REG_DWORD
    "UserSetDeviceIdleEnabled" = 1; // REG_DWORD (bool) "This registry value indicates whether a check box should be enabled in the device Properties page that allows a user to override the idle defaults. When UserSetDeviceIdleEnabled is set to a nonzero value the check box is enabled and the user can disable powering down the device when idle. A value of zero, or the absence of this value indicates that the check box isn't enabled. The UserSetDeviceIdleEnabled is ignored if DeviceIdleEnabled isn't set."
    "VendorRevision" = ; // REG_DWORD
    "WakeScreenOnInputSupport" = 1; // REG_DWORD (bool)
    "WakeScreenOnInputTimeout" = ?; // REG_DWORD, queried only when WakeScreenOnInputSupport is enabled
    "WinRtInterfaceRestrictionLevel" = 255; // REG_DWORD, fallback 255, accepts 0/1, if >1 = 0
    "WinusbIsochUsed" = 0; // REG_DWORD
    "WinUsbPowerPolicyOwnershipDisabled" = 1; // REG_DWORD (bool)
    "WriteReportExSupported" = 1; // REG_DWORD

    "AOCID" = ?;
    "AutoplayOnSpecialInterface" = ?;
    "CustomWake" = ?;
    "DefaultSimulatedTarget" = ?;
    "DeviceDumpVendorGPLogAddress" = ?; // from storport.sys
    "DeviceGroup" = ?;
    "DeviceGroups" = ?;
    "DeviceHandlers" = ?;
    "FailReasonID" = ?;
    "FirmwareCapsuleFilename" = ?;
    "FirmwareFilename" = ?;
    "FirmwareId" = ?;
    "FirmwareIntegrityFilename" = ?;
    "FirmwareMeasurementsFilename" = ?;
    "FirmwareStatus" = ?;
    "FirmwareVersion" = ?;
    "FirmwareVersionFormat" = ?;
    "FlipFlopHScroll" = ?;
    "FlipFlopWheel" = ?;
    "ForceVirtualDesktop" = ?;
    "FullPowerDownOnTransientDx" = ?;
    "FunctionDriverOptIn" = ?;
    "HackFlags" = ?;
    "HardResetCount" = ?; // REG_DWORD, "Writes into registry information about how many times this hub has been reset for the lifetime of the devnode. It also writes the invalid port status if that is the reason for hub reset. This infromation will be read by the SQM engine."
    "HasPhysicalKeys" = ?;
    "HScrollHighResolutionDisable" = ?;
    "HScrollPageOverride" = ?;
    "HScrollScalingFactor" = ?;
    "HScrollUsageOverride" = ?;
    "HubFWUpdateProtocol" = ?; // REG_DWORD
    "Icons" = ?;
    "IdleSupported" = ?;
    "IdleTimeoutPeriodInMilliSec" = ?;
    "KeyboardNumberFunctionKeysOverride" = ?;
    "KeyboardNumberIndicatorsOverride" = ?;
    "KeyboardNumberTotalKeysOverride" = ?;
    "KeyboardSubtypeOverride" = ?;
    "KeyboardTypeOverride" = ?;
    "Label" = ?;
    "NoMediaIcons" = ?;
    "NoSoftEject" = ?;
    "NumberOfPairingSlots" = ?;
    "OriginalConfigurationValue" = ?;
    "OvercurrentDetected" = ?; // REG_DWORD (bool)
    "RootBus" = ?;
    "TargetForcePriorityList" = ?;
    "TargetPriorityList" = ?;
    "Usb4HostName" = ?;
    "UsbccgpCapabilities" = ?;
    "UseStrictBiosHandoff" = ?;
    "VhfMode" = ?;
    "VideoID" = ?;
    "VScrollHighResolutionDisable" = ?;
    "VScrollPageOverride" = ?;
    "VScrollUsageOverride" = ?;
    "WakeSystemOnConnect" = ?; // REG_DWORD (bool)
    "WheelScalingFactor" = ?;
    
    "IdleUsbSelectiveSuspendPolicy" = ?; // https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/usb-driver-installation-based-on-compatible-ids#configure-selective-suspend-for-usbsersys
                                         // 0x00000001 	Enter selective suspend when idle, that is, when there are no active data transfers to or from the device.
                                         // 0x00000000 	Enter selective suspend only when there are no open handles to the device.

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\e5b3b5ac-9725-4f78-963f-03dfb1d828c7";
    "BusDataLinkSettleTime" = ?; // REG_DWORD, accepted if <= 150, larger values are ignored
    "D3ColdSupported" = 1; // REG_DWORD (bool)
    "DeviceD0DelayTime" = 100; // REG_DWORD, accepts <= 100 (ms), larger values are ignored
    "DeviceDpcCleanUpActionOverride" = 0; // REG_DWORD, 0 <= value <= 1, larger values are ignored (doesn't exist on 23H2 in pci?)
    "DeviceDpcResetActionOverride" = 0; // REG_DWORD, 0 <= value <= 4, larger values are ignored (doesn't exist on 23H2 in pci?)
    "DevicePowerResetDelayTime" = ?; // REG_DWORD (doesn't exist on 23H2 in pci?)
    "ForceSBR" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "IgnoreErrorsDuringPLDR" = 1; // REG_DWORD, ^
    "IoNotRequired" = 1; // REG_DWORD, INF default (pci.inf)
    "RecoveryDisabled" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "RecoveryEnabled" = 1; // REG_DWORD, INF default (pci.inf/machine.inf)
    "SettleTimeRequired" = 1; // REG_DWORD, INF default (pci.inf/machine.inf), "Child devices can opt into this delay by including the PciExtraSettleTimeRequired from machine.inf or pci.inf."
    "SriovSupported" = 1; // REG_DWORD, INF default (pci.inf)

    // xrefs of PciIsDeviceFeatureEnabled (which opens key e5b3b5ac-9725-4f78-963f-03dfb1d828c7)

    "ASPMOptOut" = ?; // REG_DWORD (bool), used when BaseVersion >= 1.1 (BaseVersion = PCIe base spec level)
    "ASPMOptIn" = ?; // REG_DWORD (bool), used when BaseVersion < 1.1 so basically never?
    "AtomicsOptIn" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - PciDeviceQueryAtomics
    "BridgeUseNativeWakeInfo" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - PciAddDevice
    "EnableAllBridgeInterrupts" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) "If a third-party driver has installed itself as a filter it may invoke the PciEnableAllBridgeInterrupts section from machine.inf to disable filtering of PCI Bridge interrupts." - PciBridgeInterface_Constructor
    "DoNotUseAcs" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - ExpressProcessExtendedPortCapabilities
    "AcsNotRequired" = 1; // REG_DWORD, INF default (pci.inf/machine.inf) - ExpressProcessNewPort

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Ceip"; // g_DeviceCeipKey
    "DeviceInformation" = ; // REG_DWORD, missing treated as 0 before HUBREG_UpdateSqmFlags update
    "PortInterconnectType" = ?; // REG_DWORD
    "DescriptorValidationInfo0" = ?; // REG_DWORD, written by HUBREG_UpdateSqmFlags
    "DescriptorValidationInfo1" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo2" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo3" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo4" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo5" = ?; // REG_DWORD, ^
    "DescriptorValidationInfo6" = ?; // REG_DWORD, ^

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Wdf";
    "IdleInWorkingState" = 0; // REG_DWORD (bool), INF default (1394.inf), read when UserControlOfIdleSettings is allowed
    "WakeFromSleepState" = ?; // REG_DWORD (bool)
    "WdfDefaultIdleInWorkingState" = 0; // REG_DWORD, INF default (wpdmtp.inf)
    "WdfDirectedPowerTransitionChildrenOptional" = 1; // REG_DWORD (bool), INF default (acxhdaudiop.inf)
    "WdfDirectedPowerTransitionEnable" = 1; // REG_DWORD (bool), INF default (acxhdaudiop.inf, hdaudbus.inf, iaLPSS2i_I2C_CNL.inf)
    "WdfUseWdfTimerForPofx" = ?; // REG_DWORD (bool)
    "SleepstudyState" = 0; // REG_DWORD (bool), nonzero = enabled, only used on AoAc systems (Always on, Always connected)
    "WdfDefaultWakeFromSleepState" = 0; // REG_DWORD, INF default (UsbccidDriver.inf, wudfusbcciddriver.inf)

// Interrupt Management

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties";
    "MessageNumberLimit" = ?; // REG_DWORD, cap for requested MSI messages
    "MSISupported" = ?; // REG_DWORD (bool), set by many device INFs (device specific)

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\MessageSignaledInterruptProperties\\Range\\<n>";
    // "Build a table of values. Each will be filled in only if it exists."
    "StartingMessage" = 0; // REG_DWORD
    "EndingMessage" = 0; // REG_DWORD
    "MessagesPerProcessor" = 0; // REG_DWORD, affinity helper treats 0 as 1

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy";
    "AssignmentSetOverride" = 0; // can be a REG_BINARY, REG_DWORD, or REG_QWORD value that specifies a KAFFINITY mask (KAFFINITY type is an affinity mask that represents a set of logical processors in a group). For REG_BINARY, size must be less than or equal to the KAFFINITY size for the platform, and input byte order is little endian. If DevicePolicy is 0x04 (IrqPolicySpecifiedProcessors), then this mask specifies a set of processors to assign the device's interrupts to. "For backwards compatibility handle several types. In the case where multi-byte binary data is found, treat the input byte order as little endian." https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/interrupt-affinity-and-priority
    "DevicePolicy" = 0; // REG_DWORD, https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ne-wdm-_irq_device_policy
    "DevicePriority" = 0; // REG_DWORD
    "GroupOverride" = ;
    "GroupPolicy" = ; // REG_DWORD, default GroupAffinityAllGroupZero when missing

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Affinity Policy - Temporal";
    "TargetGroup" = ?; // REG_DWORD
    "TargetSet" = ?; // REG_QWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Interrupt Management\\Routing Info";
    // "This routine deletes any interrupt routing data that the interrupt arbiter has cached (for performance reasons) about this device."
    "Flags" = ?; // REG_DWORD, data size 1
    "LinkNode" = ?; // REG_BINARY, ACPIAmliBuildObjectPathname
    "StaticVector" = ?; // REG_DWORD, PcisuppSetRoutingInfo writes this when no LinkNode is present

// miscellaneous values from boot trace, haven't looked into them yet
"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>";
    "Address" = ?;
    "Capabilities" = ?;
    "CompatibleIDs" = ?;
    "ConfigFlags" = ?;
    "ContainerID" = ?;
    "DeviceCharacteristics" = ?;
    "DeviceDesc" = ?;
    "DeviceReported" = ?;
    "DeviceType" = ?;
    "Driver" = ?;
    "Exclusive" = ?;
    "HardwareID" = ?;
    "InstallFlags" = ?;
    "LocationInformation" = ?;
    "LowerFilters" = ?;
    "Mfg" = ?;
    "ParentIdPrefix" = ?;
    "Phantom" = ?;
    "RemovalPolicy" = ?;
    "SECURITY" = ?;
    "Service" = ?;
    "UINumber" = ?;
    "UINumberDescFormat" = ?;
    "UniqueParentID" = ?;
    "UpperFilters" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Control";
    "AllocConfig" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\LogConf";
    "AllocConfig" = ?;
    "BootConfig" = ?;
    "ForcedConfig" = ?;
    "OverrideConfigVector" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\BiosConfig";
    "DEV_00&FUN_00" = ?;
    "DEV_00&FUN_01" = ?;
    "DEV_00&FUN_02" = ?;
    "DEV_00&FUN_03" = ?;
    "DEV_01&FUN_00" = ?;
    "DEV_01&FUN_01" = ?;
    "DEV_01&FUN_02" = ?;
    "DEV_02&FUN_00" = ?;
    "DEV_03&FUN_00" = ?;
    "DEV_03&FUN_01" = ?;
    "DEV_04&FUN_00" = ?;
    "DEV_05&FUN_00" = ?;
    "DEV_07&FUN_00" = ?;
    "DEV_07&FUN_01" = ?;
    "DEV_08&FUN_00" = ?;
    "DEV_08&FUN_01" = ?;
    "DEV_09&FUN_00" = ?;
    "DEV_14&FUN_00" = ?;
    "DEV_14&FUN_03" = ?;
    "DEV_18&FUN_00" = ?;
    "DEV_18&FUN_01" = ?;
    "DEV_18&FUN_02" = ?;
    "DEV_18&FUN_03" = ?;
    "DEV_18&FUN_04" = ?;
    "DEV_18&FUN_05" = ?;
    "DEV_18&FUN_06" = ?;
    "DEV_18&FUN_07" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\StorPort";
    "DlrmDisable" = ?;
    "EnableNVMeInterface" = ?;
    "FwActivateTimeoutForController" = ?;
    "TotalSenseDataBytes" = ?;

    // from storport.sys - https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A88F4.c
    "AdapterGuid" = ; // REG_BINARY, 16 bytes
    "BusSpecificResetTimeout" = 5; // REG_DWORD, range 1-4294967295, 0 ignored
    "DisableD3Cold" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "DisableNVMeActiveNamespaceIDListCheck" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "DisableRuntimePowerManagement" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "EnableIdlePowerManagement" = 0; // REG_DWORD, range 0-4294967295 (bool)
    "GeneratedID" = ; // REG_BINARY, 16 bytes
    "IdleTimeoutInMS" = 60000; // REG_DWORD, range 0-4294967295
    "InitialTimestamp" = ; // REG_QWORD
    "Is1667Device" = 4294967295; // REG_DWORD, range 0-4294967295
    "PLDRTimeout" = 10; // REG_DWORD, range 1-4294967295, 0 ignored
    "PowerCycleCount" = 0; // REG_DWORD, range 0-4294967295, used only when PowerCycleCountOverride doesn't exist
    "PowerCycleCountOverride" = ; // REG_DWORD, range 0-4294967295
    "PowerSrbTimeout" = ; // REG_DWORD, range 1-110, >110 clamps to 110, 0 ignored
    "TotalSenseDataBytes" = 256; // REG_DWORD
    "UseDMAv3" = 0; // REG_DWORD, range 0-4294967295 (bool)

    // https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00A4268.c
    "BusyPauseTime" = 250; // REG_DWORD, range 0-4294967295
    "BusyRetryCount" = 20; // REG_DWORD, range 0-4294967295
    "DisableIdlePowerManagement" = 0; // REG_DWORD, range 0-4294967295
    "EnableLogoETW" = 0; // REG_DWORD, range 0-4294967295
    "MinimumIdleTimeoutInMS" = 4294967295; // REG_DWORD, range 0-4294967295
    "QueueFullWaitIoPercentage" = 25; // REG_DWORD, range 0-100

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\DMA Management";
    "RemappingFlags" = ?;
    "RemappingSupported" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\partmgr";
    "Attributes" = ?;
    "DiskId" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF";
    "SoftwareDeviceTag" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\WUDF\\CompanionConfigurations\\USBXHCI";
    "CompanionServiceList" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Enum\\<enumerator>\\<deviceID>\\<instanceID>\\Device Parameters\\Disk"; // enumerator is usually SCSI here
  "UserWriteCacheSetting" = 1; // REG_DWORD, from storport.sys - https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C00633B0.c
```

## MSPower_DeviceEnable

Note that the known `MSPower_DeviceEnable` command does nothing more than recursively setting `IdleInWorkingState` & `SelectiveSuspendOn` to `0`.
```powershell
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\ROOT_HUB30\5&2c35141&0&0\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\ROOT_HUB30\5&2bce96aa&0&0\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_0ABA&MI_03\7&41505d0&0&0003\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_05E3&PID_0610\6&3365fbaf&0&11\Device Parameters\WDF\IdleInWorkingState	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_0B05&PID_1939&MI_02\7&40fe908&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_00\7&1fc2034b&0&0000\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_01\7&1fc2034b&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_046D&PID_C547&MI_02\7&1fc2034b&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_00\7&a6e656e&0&0000\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_01\7&a6e656e&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_02\7&a6e656e&0&0002\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_03\7&a6e656e&0&0003\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_1038&PID_161E&MI_04\7&a6e656e&0&0004\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Enum\USB\VID_0CF2&PID_A102&MI_01\8&7b0cf2a&0&0001\Device Parameters\SelectiveSuspendOn	Type: REG_DWORD, Length: 4, Data: 0
```

On my 25H2 VM it also switched `PnPCapabilities`:
```c
// MSPower_DeviceEnable enabled
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0000\PnPCapabilities	Type: REG_DWORD, Length: 4, Data: 16

// MSPower_DeviceEnable disabled
wmiprvse.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0000\PnPCapabilities	Type: REG_DWORD, Length: 4, Data: 24
```

## Storport Idle (`Device Parameters\\StorPort`)

> "*Storport provides support for idle power management to allow storage devices to enter a low power state when not in use. Storport's idle power management (IPM) support includes handling idle power management for storage devices under its management, in coordination with the Power Manager in Windows.*"
>
> — Microsoft, [Registry entries for Storport miniport drivers](https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/registry-entries-for-storport-miniport-drivers)

- [power/assets | storport.c](https://github.com/nohuto/win-config/blob/main/power/assets/storport.c)

# Power Values

Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation. No values are applied that apply to other options in this section.

## Registry Values

See [power-symbols](https://github.com/nohuto/win-config/tree/main/power/assets/power/power-symbols.txt) for reference ([disp-sym](https://noverse.dev/docs/windbg-notes/symbols/reading-symbols/#mass-display-symbols)). The list doesn't include all existing values yet, but the listed ones do exist. [assets/power](https://github.com/nohuto/win-config/tree/main/power/assets/power) contains the split pseudocode for several `Session Manager\\Power` values.

| Prefix | Component |
| --- | --- |
| `PoFx` | Power Framework |
| `Pop` | Power Manager |
| `Ppm` | Processor Power Manager |

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "ActiveIdleLevel" = 1; // PopFxActiveIdleLevel 
    "ActiveIdleThreshold" = 5000000; // PopFxActiveIdleThreshold
    "ActiveIdleTimeout" = 1000; // PopFxActiveIdleTimeout
    "AllowAudioToEnableExecutionRequiredPowerRequests" = 1; // PopPowerRequestActiveAudioEnablesExecutionRequired 
    "AllowHibernate" = 4294967295; // PopAllowHibernateReg, REG_DWORD
    "AllowSystemRequiredPowerRequests" = 1; // PopPowerRequestConvertSystemToExecution 
    "AlwaysComputeQosHints" = 0; // PpmPerfAlwaysComputeQosEnabled, can be used to cause a condition in PopInitializeHeteroProcessors to be true, see PowerThrottlingOff section
    "BootHeteroPolicyOverride" = 0; // PpmPerfBootHeteroPolicyOverrideEnabled 
    "CheckpointSystemSleep" = 0; // PopCheckpointSystemSleepEnabledReg 
    "CheckpointSystemSleepSimulateFlags" = 0; // PopCheckpointSystemSleepSimulateFlags 
    "CheckPowerSourceAfterRtcWakeTime" = 30; // PopCheckPowerSourceAfterRtcWakeTime
    "Class1InitialUnparkCount" = 64; // PpmParkInitialClass1UnParkCount
    "CoalescingFlushInterval" = 60; // PopCoalescingFlushInterval 
    "CoalescingTimerInterval" = 1500; // PopCoalescingTimerInterval - Units: seconds (multiplies value by -10,000,000, one second in 100?ns units, so the default corresponds to a 25min cadence)
    "DeepIoCoalescingEnabled" = 0; // PopDeepIoCoalescingEnabled 
    "DirectedDripsAction" = 3; // PopDirectedDripsAction 
    "DirectedDripsDebounceInterval" = 120; // PopDirectedDripsDebounceInterval
    "DirectedDripsDfxEnforcementPolicy" = 1; // PopDirectedDripsDfxEnforcementPolicy 
    "DirectedDripsOverride" = 4294967295; // PopDirectedDripsOverride
    "DirectedDripsSurprisePowerOnTimeout" = 5; // PopDirectedDripsSurprisePowerOnTimeoutSeconds 
    "DirectedDripsTimeout" = 300; // PopDirectedDripsTimeout
    "DirectedDripsWaitWakeTimeout" = 5; // PopDirectedDripsWaitWakeTimeoutSeconds 
    "DirectedFxDefaultTimeout" = 120; // PopFxDirectedFxDefaultTimeout
    "DisableDisplayBurstOnPowerSourceChange" = 0; // PopDisableDisplayBurstOnPowerSourceChange 
    "DisableIdleStatesAtBoot" = 0; // PpmIdleDisableStatesAtBoot 
    "DisableInboxPepGeneratedConstraints" = 4294967295; // PopDisableInboxPepGeneratedConstraintsOverride
    "DisableVsyncLatencyUpdate" = 0; // PpmDisableVsyncLatencyUpdate 
    "DozeDeferralChecksToIgnore" = 0; // PopDozeDeferralChecksToIgnore 
    "DozeDeferralMaxSeconds" = 259200; // PopDozeDeferralMaxSeconds
    "DripsCallbackInterval" = 35; // PopDripsCallbackInterval 
    "DripsSwHwDivergenceEnableLiveDump" = 0; // PopDripsSwHwDivergenceEnableLiveDump 
    "DripsSwHwDivergenceThreshold" = 270; // PopDripsSwHwDivergenceThreshold
    "DripsWatchdogAction" = 198; // PopDripsWatchdogAction
    "DripsWatchdogDebounceInterval" = 120; // PopDripsWatchdogDebounceInterval
    "DripsWatchdogTimeout" = 300; // PopDripsWatchdogTimeout
    "EnableInputSuppression" = 4294967295; // PopEnableInputSuppressionOverride
    "EnableMinimalHiberFile" = 0; // PopEnableMinimalHiberFile, REG_DWORD
    "EnablePowerButtonSuppression" = 4294967295; // PopEnablePowerButtonSuppressionOverride
    "EnergyEstimationEnabled" = 1; // PopEnergyEstimationEnabled 
    "EnforceAusterityMode" = 0; // PopEnforceAusterityMode 
    "EnforceConsoleLockScreenTimeout" = 0; // PopEnforceConsoleLockScreenTimeout 
    "EnforceDisconnectedStandby" = 0; // PopEnforceDisconnectedStandby 
    "EventProcessorEnabled" = 1; // PopEventProcessorEnabled 
    "ExitLatencyCheckEnabled" = 0; // PpmExitLatencyCheckEnabled 
    "ExperimentalClusterIdleMitigation" = 0; // PpmIdleClusterIdleMitigation 
    "ForceMinimalHiberFile" = 0; // PopForceMinimalHiberFile, REG_DWORD
    "FxAccountingTelemetryDisabled" = 0; // PopDiagFxAccountingTelemetryDisabled 
    "FxRuntimeLogNumberEntries" = 64; // PopFxRuntimeLogNumberEntries - Changing it to 0 will end up with a BSoD
    "HeteroFavoredCoreRotationTimeoutMs" = 30000; // PpmHeteroFavoredCoreRotationTimeoutMs
    "HeteroHgsEePerfHintsIndependentEnabled" = 0; // PpmHeteroHgsEePerfHintsIndependentEnabled 
    "HeteroHgsPlusDisabled" = 0; // PpmHeteroHgsThreadDisabled 
    "HeteroMultiClassParkingEnabled" = 4294967295; // PpmHeteroMultiClassParkingRegValue
    "HeteroMultiCoreClassesEnabled" = 4294967295; // PpmHeteroMultiCoreClassesRegValue
    "HeteroWpsContainmentEnumOverride" = 0; // PpmHeteroWpsContainmentEnumOverride 
    "HeteroWpsWorkloadProminenceCutoff" = 35; // PpmHeteroWpsWorkloadProminenceCutoff
    "HiberbootEnabled" = 1; // PopHiberbootEnabledReg 
    "HiberFileSizePercent" = 100; // PopHiberFileSizePercent, REG_DWORD, 0-39 keeps the type logic, 40-100 uses the percent directly and PopSetHiberFileSize forces a full file
    "HiberFileType" = 4294967295; // PopHiberFileTypeReg, DWORD 1 = Reduced, DWORD 2 = Full, only used while HiberFileSizePercent < 40
    "HiberFileTypeDefault" = 4294967295; // PopHiberFileTypeDefaultReg, fallback when HiberFileType is unset
    "HibernateBootOptimizationEnabled" = 0; // PopHiberBootOptimizationEnabledReg 
    "HibernateChecksummingEnabled" = 1; // PopHiberChecksummingEnabledReg 
    "HibernateEnabledDefault" = 1; // PopHiberEnabledDefaultReg, REG_DWORD
    "HibernateEnabled" = 1; // that's the value 'powercfg /hibernate off' would set
    "HighPerfDurationBoot" = 90000; // PpmHighPerfDuration
    "HighPerfDurationCSExit" = ?;
    "HighPerfDurationSxExit" = ?;
    "IdleDurationExpirationTimeout" = 4; // PpmIdleDurationExpirationTimeoutMs 
    "IdleProcessorsRequireQosManagement" = 4294967295; // PpmPerfQosManageIdleProcessors
    "IdleStateTimeout" = 500; // PopPepIdleStateTimeout
    "IgnoreCsComplianceCheck" = 0; // PopIgnoreCsComplianceCheck 
    "IgnoreLidStateForInputSuppression" = 4294967295; // PopLidStateForInputSuppressionOverride
    "IpiLastClockOwnerDisable" = 0; // PpmIpiLastClockOwnerDisable 
    "LatencyToleranceDefault" = 100000; // PpmLatencyToleranceLimit
    "LatencyToleranceFSVP" = 20000;
    "LatencyToleranceIdleResiliency" = 1500000;
    "LatencyToleranceParked" = 0; // PpmIdleParkedLatencyLimit 
    "LatencyToleranceSoftParked" = 0; // PpmIdleSoftParkedLatencyLimit 
    "LatencyToleranceVSyncEnabled" = 13001;
    "LidReliabilityState" = 1; // REG_DWORD, range 0-1
    "ManualDimTimeout" = 0; // PopAdaptiveManualDimTimeout 
    "MaximumFrequencyOverride" = 0; // PpmFrequencyOverride 
    "MfBufferingThreshold" = 0; // PpmMfBufferingThreshold 
    "MfOverridesDisabled" = 1; // PpmMfOverridesDisabled 
    "MSDisabled" = 0; // PopModernStandbyDisabled 
    "MultiparkGranularity" = 8; // PpmParkMultiparkGranularity 
    "PdcIdlePhaseDefaultWatchdogTimeoutSeconds" = 30; // PopPdcIdlePhaseDefaultWatchdogTimeoutSeconds
    "PdcOneWayEntry" = 0; // PopPowerAggregatorOneWayEntry 
    "PerfArtificialDomain" = 4294967295; // PpmPerfArtificialDomainSetting
    "PerfBoostAtGuaranteed" = 0; // PpmPerfBoostAtGuaranteed 
    "PerfCalculateActualUtilization" = 1; // PpmPerfCalculateActualUtilization 
    "PerfCheckTimerImplementation" = 0; // PpmCheckTimerImplementation 
    "PerfIdealAggressiveIncreasePolicyThreshold" = 90; // PpmPerfIdealAggressiveIncreaseThreshold
    "PerfQueryOnDevicePowerChanges" = 0; // PopFxPerfQueryOnDevicePowerChanges 
    "PerfSingleStepSize" = 5; // PpmPerfSingleStepSize
    "PlatformAoAcOverride" = 4294967295; // PopPlatformAoAcOverride
    "PlatformRoleOverride" = 4294967295; // PopPlatformRoleOverride
    "PoFxSystemIrpWaitForReportDevicePowered" = 0; // PopPoFxSystemIrpWaitForReportDevicePoweredReg 
    "PowerActionResumeWatchdogTimeoutDefault" = 300; // PopPowerActionResumingWatchdogTimeoutDefault
    "PowerActionTransitioningWatchdogTimeoutDefault" = 600; // PopPowerActionTransitioningWatchdogTimeoutDefault
    "PromoteHibernateToShutdown" = 0; // PopPromoteHibernateToShutdown 
    "ProximityEscapeMsec" = 0; // TtmpProximityEscapeMsec 
    "RestrictedStandbyDozeTimeoutSeconds" = 0; // PopPowerAggregatorRestrictedStandbyDozeTimeoutSeconds 
    "SkipHibernateMemoryMapValidation" = 4294967295; // PopEnableHibernateMemoryMapValidationOverride 
    "SleepstudyAccountingEnabled" = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit" = 3000; // SleepstudyHelperBlockerGlobalLimit
    "SleepstudyLibraryBlockerLimit" = 200; // SleepstudyHelperBlockerLibraryLimit
    "SmartUserPresenceAction" = 0; // PopSmartUserPresenceAction 
    "SmartUserPresenceCheckTimeout" = 10800; // PopSmartUserPresenceCheckTimeout
    "SmartUserPresenceGracePeriod" = 1800; // PopSmartUserPresenceGracePeriod
    "SmartUserPresenceWakeOffset" = 300; // PopSmartUserPresenceWakeOffset
    "StandbyConnectivityGracePeriod" = 0; // PopStandbyConnectivityGracePeriod 
    "SuppressResumePrompt" = 0; // PopSuppressResumePrompt 
    "ThermalPollingMode" = 0; // PopThermalPollingMode 
    "ThermalTelemetryVerbosity" = 1; // PopThermalTelemetryVerbosity 
    "TimerRebaseThresholdOnDripsExit" = 60; // PopTimerRebaseThresholdRegValue
    "TtmEnabled" = 0; // TtmpEnabled 
    "UserBatteryChargeEstimator" = 0; // PopUserBatteryChargingEstimator 
    "UserBatteryDischargeEstimator" = 0; // PopDisableBatteryDischargeEstimator 
    "WatchdogWorkOrderTimeout" = 300000; // PopFxWatchdogWorkOrderTimeout
    "Win32kCalloutWatchdogTimeoutSeconds" = 30; // PopWin32kCalloutWatchdogTimeoutSeconds

    // UmpoRestoreEsOverrideState
    "EnergySaverState" = 2; // 1 = override state (more power savings) if != 1 no override? (WNF_PO_ENERGY_SAVER_OVERRIDE/WNF_SEB_ENERGY_SAVER_STATE_V2), this value is controlled by System > Power: Always use energy saver (1=on, 2=off)

    // InitializePowerWatchdogTimeoutDefaults
    "PowerWatchdogDrvSetMonitorTimeoutMsec" = 10000;
    "PowerWatchdogDwmSyncFlushTimeoutMsec" = 30000;
    "PowerWatchdogPoCalloutTimeoutMsec" = 10000;
    "PowerWatchdogPowerOnGdiTimeoutMsec" = 30000;
    "PowerWatchdogRequestQueueTimeoutMsec" = 30000;

    // from procmon boot trace
    "DisableHotKeyWhenConsoleOff" = ?;
    "EmiPollingInterval" = ?;
    "EmiTelemetryActivePollingInterval" = ?;
    "EmiTelemetryCsPollingInterval" = ?;
    "LidNotifyReliable" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ForceHibernateDisabled";
    "GuardedHost" = 0; // if nonzero, PopHibernateEvaluation treats hibernation as force disabled
    "Policy" = 0; // PopHiberForceDisabledReg, ^

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

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\ModernSleep";
    "EnabledActions" = 0; // PopAggressiveStandbyActionsRegValue 
    "EnableDsNetRefresh" = 0; // PopEnableDsNetRefresh 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "PowerThrottlingOff" = 0; // PpmPerfQosGroupPolicyDisable 
```

### PowerThrottlingOff

`PowerThrottlingOff` is one of nine `_PPM_PERF_QOS_DISABLE_REASON`, changing it to nonzero would set bit 8 in six of seven QoS classes, consumers of that bitmask only check whenever its `!= 0`, so it doesn't matter which reason is set.

If PPM QoS is disabled, six of seven (excluding *High*) classes follow the class above them (all *High*).

`MaxFrequency`, `MaxPerformance`, `MinPerformance`, `PerfAutonomousMode`, `PerfAutonomousWindow`, `PerfBoostMode`, `PerfEnergyPreference`, `PerfLatencyHint`, `LatencyHintEpp` (other ones are scheduling settings) are in `QosPolicies[class]`, built by `PpmPerfCalculateQosClassPolicies`. All of these aren't used whenever PPM QoS (of the class) is unsupported, means that they'll follow the settings of their parent class (which is *High* if all six are unsupported) for them, which are the current power plan settings (`PpmCurrentProfile`). They get parents differently than expected, heres how I understood it:

| Class | Parent |
| --- | --- |
| High | - |
| Medium | High |
| Low | Medium |
| Multimedia | High |
| Deadline | High |
| Eco | Utility |
| Utility | Low |

```c
lkd> dd nt!PpmQosClassesOrderedIndexMap L7
fffff806`62023528  00000000 00000001 00000002 00000005
fffff806`62023538  00000006 00000004 00000003
```

> "*Quality of Service*
>
> *Power profiles provide system wide configuration of processor power management, impacting all running workloads equally. In contrast, the Quality of Service (QoS) feature provides differentiated performance and power for workloads with different QoS levels. For example, this enables tuning foreground HighQoS activity to prioritize performance, while tuning other QoS levels to prioritize power efficiency. For more information, see [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service).*
>
> *Each QoS level supports the following configuration settings:*
>
> *- [MaxFrequency](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxfrequency.md)*
> *- [MaxPerformance](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxperformance.md)*
> *- [MinPerformance](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-minperformance.md)*
> *- [PerfAutonomousMode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfautonomousmode.md)*
> *- [PerfAutonomousWindow](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfautonomouswindow.md)*
> *- [PerfBoostMode](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfboostmode.md)*
> *- [PerfEnergyPreference](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfenergypreference.md)*
> *- [PerfLatencyHint](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perflatencyhint.md)*
> *- [LatencyHintEpp](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-latencyhintepp.md)*
> *- [SchedulingPolicy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-schedulingpolicy.md)*
> *- [ShortSchedulingPolicy](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortschedulingpolicy.md)*
> *- [LongThreadArchClassLowerThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold.md)*
> *- [LongThreadArchClassUpperThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold.md)*
> *- [ShortThreadArchClassLowerThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold.md)*
> *- [ShortThreadArchClassUpperThreshold](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclassupperthreshold.md)*
>
> *On systems with processors with heterogeneous architecture, the configuration settings for efficiency class 1 cores use a similar naming convention.*
>
> *The common parameters have the suffix "1" to indicate efficiency class.*
>
> *- [MaxFrequency1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxfrequency.md)*
> *- [MaxPerformance1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-maxperformance.md)*
> *- [MinPerformance1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-minperformance.md)*
> *- [PerfEnergyPreference1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perfenergypreference.md)*
> *- [PerfLatencyHint1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-perflatencyhint.md)*
> *- [LatencyHintEpp1](https://github.com/nohuto/win-config/blob/main/power/assets/power-settings/options-for-perf-state-engine-latencyhintepp.md)*
>
> — Microsoft, [Processor power management options](https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-processor-power-management-options#quality-of-service)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling";
    "PowerThrottlingOff" = 0; // PpmPerfQosGroupPolicyDisable
```

The value is read as a bool, so all nonzero data are the same.

#### CmControlVector

See [kernel-values/#cmcontrolvector](https://noverse.dev/docs/win-config/system/kernel-values/#cmcontrolvector) for details on what the comments mean.

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power\PowerThrottling
; ValueName = PowerThrottlingOff
; Destination = PpmPerfQosGroupPolicyDisable
; Length/Type/Flags = 0

INIT:0000000140BA3300                 dq offset aPowerPowerthro ; "Power\PowerThrottling"
INIT:0000000140BA3308                 dq offset aPowerthrottlin ; "PowerThrottlingOff"
INIT:0000000140BA3310                 dq offset PpmPerfQosGroupPolicyDisable
INIT:0000000140BA3318                 dq 3 dup(0)
```

The value was `0` for this capture:

```c
lkd> dd nt!PpmPerfQosGroupPolicyDisable L1
fffff806`1491ed24  00000000
```

#### PopInitializeHeteroProcessors

```c
// PopInitializeHeteroProcessors

  v3 = 1;
  v4 = 0; // capability
  if ( (PpmBackgroundProfile || PpmEntryLevelPerfProfile || PpmMultimediaQosProfile || PpmPerfAlwaysComputeQosEnabled) // one must be nonzero here
    && PpmPerfSchedulerDirectedPerfStatesSupported
    && KeQueryActiveProcessorCountEx(0) >= 2 ) // at least two active processors
  {
    v4 = 1;
  }
  if ( PpmPerfVmQosSupported )
  {
    v4 = 1;
    goto LABEL_13;
  }
  if ( v4 )
  {
LABEL_13:
    v5 = 1; // enable processor performance QoS
    if ( !PpmPerfQosGroupPolicyDisable ) // PowerThrottlingOff = 0
      goto LABEL_15;
  }
  v5 = 0; // unsupported/PowerThrottlingOff is nonzero
LABEL_15:
```

Afterwards, `v5` is passed as the second argument into `KeConfigureHeteroProcessors`:

```c
// PopInitializeHeteroProcessors

LOBYTE(v20) = v2;
v22 = PopConfigureHeteroPolicies(v7, v20);
if ( (v3 || v7 && v22 || PpmPerfQosSupportedAndAllowed != v5)
  && (unsigned int)KeConfigureHeteroProcessors(v1, v5, &v32) )
{
  PsEnumProcesses((__int64 (__fastcall *)(__int64 *, __int64))PopUpdateSingleProcessHeteroPolicies, 0LL);
}
```

At the end that result is written into `PpmPerfQosSupportedAndAllowed`:

```c
// PopInitializeHeteroProcessors

PpmPerfQosSupportedAndAllowed = v5;
```

##### Reading Globals

Example output of my testing system, here all conditions aren't true, means `v4` and `v5` stay at `0`, means chaning `PowerThrottlingOff` has no impact.

```c
lkd> dd nt!PpmPerfQosDisableReasons L1
fffff803`35d1ed20  00000082 // bit 1 NoProfile, bit 7 NoHardwareSupport
lkd> dq nt!PpmBackgroundProfile L1
fffff806`14839488  00000000`00000000
lkd> dq nt!PpmEntryLevelPerfProfile L1
fffff806`14839480  00000000`00000000
lkd> dq nt!PpmMultimediaQosProfile L1
fffff806`148394a0  00000000`00000000
lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff806`1491eec8  00                                               .
lkd> db nt!PpmPerfSchedulerDirectedPerfStatesSupported L1
fffff806`1491eaa7  00                                               .
lkd> dq nt!KeActiveProcessors+8 L1
fffff806`1491efe8  00000000`00000fff // bit 0-11
lkd> db nt!PpmPerfVmQosSupported L1
fffff806`1491eb52  00                                               .
lkd> db nt!PpmPerfQosSupportedAndAllowed L1
fffff806`1491ebf5  00                                               .
```

##### PpmPerfSchedulerDirectedPerfStatesSupported

This may not be correct yet, and is based on the amdppm driver.

Each PPM performance domain gets an `AllowSchedulerDirectedPerfStates` value from its PP driver (amdppm/intelppm...), [`PpmRegisterPerfStates`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmRegisterPerfStates.c) then sets `PpmPerfSchedulerDirectedPerfStatesSupported` to `1` only when every registered domain has a nonzero value.

On AMDs `_CPC` for example, [`InitCpcStatesInternal`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/InitCpcStatesInternal.c) uses these conditions:

```c
// InitCpcStatesInternal

if ( (*(_DWORD *)(v80 + 280) & 0x400000) != 0 && v83 && v136 && (v84 == 254 || v81 == 1) ) // 0x400000 = IsACountMCountSupported & processor family >= 17
                                                                                           // v83 = native CPPC handler availaile
                                                                                           // v136 = CPPC handler returned AllowSchedulerDirectedPerfStates = 1
                                                                                           // v84 == 254 || v81 == 1, domain uses HW_ALL/has one processor
{
  *(_BYTE *)(v5 + 11) = 1; // v5 + 11 = _PROCESSOR_PERF_STATES.AllowSchedulerDirectedPerfStates
  if ( !_bittest64((const signed __int64 *)(v80 + 280), 0x22u) || (v97 = 0, v129[0]) )
    v97 = 1;
  *(_BYTE *)(v5 + 12) = v97;
  *(_DWORD *)(v5 + 48) = v146;
}
```

```c
if ( (unsigned __int8)IsACountMCountSupported() )
{
  v7 = 0LL;
  GetCpuIdInfo(1u, &v7);
  if ( (v7 & 0xF00) == 0xF00 && (unsigned int)(unsigned __int8)((unsigned int)v7 >> 20) + 15 >= 0x17 )
    v4 |= 0x400000uLL;
}
```

[`InitDriver`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/amdppm/InitDriver.c) only gives the native CPPC handler when CPUID `Fn8000_0008_EBX[27]` is set (which is CPPC):

```c
// InitDriver

GetCpuIdInfo(0x80000000, &v7);
if ( (unsigned int)v7 >= 8 )
{
  GetCpuIdInfo(0x80000008, &v8);
  if ( (DWORD1(v8) & 0x8000000) != 0 ) // 0x8000000 = bit 27
    *(_QWORD *)(a1 + 176) = GetCppcRequestMsrPerfControlHandler;
}
```

```c
CPUID.01H: EAX=00A20F12 family=19h ECX=7EF8320B hypervisor=0
CPUID.06H: ECX=00000001 ECX[0]=1
CPUID.80000008H: EBX=111EF657 EBX[27]=0
```

Bit 27 is `0` here which causes `AllowSchedulerDirectedPerfStates` to stay at `0`, means `PpmPerfSchedulerDirectedPerfStatesSupported` is also `0`:

```c
lkd> dt nt!_PROC_PERF_DOMAIN ffff930d`77ff35a0 Id ProcessorCount Coordination AllowSchedulerDirectedPerfStates QosSupported
   +0x128 ProcessorCount                   : 1
   +0x1b0 Id                               : 1
   +0x1e1 Coordination                     : 0xfe ''
   +0x1e5 AllowSchedulerDirectedPerfStates : 0 ''
   +0x2fa QosSupported                     : 0 ''
```

##### AlwaysComputeQosHints

```asm
; KeyPath = HKLM\SYSTEM\CurrentControlSet\Control\Power
; ValueName = AlwaysComputeQosHints
; Destination = PpmPerfAlwaysComputeQosEnabled

INIT:0000000140BA28B0                 dq offset aPower_2      ; "Power"
INIT:0000000140BA28B8                 dq offset aAlwayscomputeq ; "AlwaysComputeQosHints"
INIT:0000000140BA28C0                 dq offset PpmPerfAlwaysComputeQosEnabled
INIT:0000000140BA28C8                 align 20h
```

This can be used to make the first codition true in the `PopInitializeHeteroProcessors` part shown above.

```c
if ( (PpmBackgroundProfile || PpmEntryLevelPerfProfile || PpmMultimediaQosProfile || PpmPerfAlwaysComputeQosEnabled)
```

```c
lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff804`49f1eec8  00                                               . // AlwaysComputeQosHints = 0

lkd> db nt!PpmPerfAlwaysComputeQosEnabled L1
fffff803`35d1eec8  01                                               . // AlwaysComputeQosHints = 1
```

[PpmPerfAlwaysComputeQosEnabled](https://github.com/nohuto/globals/blob/main/11-23H2/ntoskrnl/PpmPerfAlwaysComputeQosEnabled.cpp) has a PE init default of `0` and doesn't get changed afterwards, so missing = `0`.

#### PpmPerfCalculateQosClassPolicies

An "PPM performance domain" has one/more logical processors that share the same performance controls, `Members` here tells its logical processors, `QosPolicies[7]` & `QosDisableReasons[7]` include one entry for each of the *High*, *Medium*, *Low*, *Multimedia*, *Deadline*, *Eco*, *Utility* classes.

```c
lkd> dq nt!KeActiveProcessors+8 L1
fffff806`1491efe8  00000000`00000fff // bit 0-11

lkd> dd nt!PpmPerfDomainCount L1
fffff806`1491ec48  0000000c // 12 = each processor has its own domain

lkd> dt nt!_PROC_PERF_DOMAIN ffffbd04`acfb3700 Link Members ProcessorCount EfficiencyClass Id QosDisableReasons QosSupported
   +0x000 Link              : _LIST_ENTRY [ 0xffffbd04`acfb9010 - 0xfffff806`62d1eb38 ]
   +0x018 Members           : _KAFFINITY_EX
   +0x128 ProcessorCount    : 1
   +0x12c EfficiencyClass   : 0 ''
   +0x1b0 Id                : 1
   +0x2d0 QosDisableReasons : [7] 0
   +0x2fa QosSupported      : 0 ''

lkd> dd ffffbd04`acfb3700+0x2d0 L7
ffffbd04`acfb39d0  00000000 00000082 00000082 00000082 // class 0 = 00000000, all others bit 1+7
ffffbd04`acfb39e0  00000082 00000082 00000082
```

[`PpmPerfUpdateDomainPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmPerfUpdateDomainPolicy.c) goes through those domains and calls [`PpmPerfCalculateQosClassPolicies`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PpmPerfCalculateQosClassPolicies.c) to get their seven `QosPolicies` & `QosDisableReasons` entries:

```c
// PpmPerfCalculateQosClassPolicies

if ( PpmPerfQosGroupPolicyDisable )
  v16 |= 0x100u; // bit 8
if ( !PpmPerfSchedulerDirectedPerfStatesSupported )
  v16 |= 0x80u; // bit 7
```

```c
enum _PPM_PERF_QOS_DISABLE_REASON
{
    PpmPerfQosDisableInternal=0, // PpmPerfQosDisableRefcount
    PpmPerfQosDisableNoProfile=1,
    PpmPerfQosDisableNoPolicy=2,
    PpmPerfQosDisableInsufficientPolicy=3,
    PpmPerfQosDisableMaxOverride=4, // PpmPerfMaxOverrideEnabled
    PpmPerfQosDisableLowLatency=5, // GUID_POWER_POLICY_PROFILE_LOW_LATENCY
    PpmPerfQosDisableSmtScheduler=6, // !PopHeteroSystem
    PpmPerfQosDisableNoHardwareSupport=7, // 0x80
    PpmPerfQosDisableGroupPolicy=8, // 0x100
    PpmPerfQosDisableMax=9
};
```

```cpp
struct _PROC_PERF_DOMAIN// Size=0x428 (Id=1969)
{
    struct _LIST_ENTRY Link;// Offset=0x0 Size=0x10
    struct _PROC_PERF_CHECK_CONTEXT * Master;// Offset=0x10 Size=0x8
    struct _KAFFINITY_EX Members;// Offset=0x18 Size=0x108
    unsigned long long DomainContext;// Offset=0x120 Size=0x8
    unsigned long ProcessorCount;// Offset=0x128 Size=0x4
    unsigned char EfficiencyClass;// Offset=0x12c Size=0x1
    unsigned char NominalPerformanceClass;// Offset=0x12d Size=0x1
    unsigned char HighestPerformanceClass;// Offset=0x12e Size=0x1
    enum _PROCESSOR_PRESENCE Presence;// Offset=0x130 Size=0x4
    struct _PROC_PERF_CONSTRAINT * Processors;// Offset=0x138 Size=0x8
    void  ( * GetFFHThrottleState)(unsigned long long * );// Offset=0x140 Size=0x8
    void  ( * TimeWindowHandler)(unsigned long long ,unsigned long );// Offset=0x148 Size=0x8
    void  ( * BoostPolicyHandler)(unsigned long long ,unsigned long );// Offset=0x150 Size=0x8
    void  ( * BoostModeHandler)(unsigned long long ,unsigned long );// Offset=0x158 Size=0x8
    void  ( * AutonomousActivityWindowHandler)(unsigned long long ,unsigned long );// Offset=0x160 Size=0x8
    void  ( * AutonomousModeHandler)(unsigned long long ,unsigned long );// Offset=0x168 Size=0x8
    void  ( * ReinitializeHandler)(unsigned long long );// Offset=0x170 Size=0x8
    unsigned long  ( * PerfSelectionHandler)(unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long ,unsigned long * ,unsigned long long * );// Offset=0x178 Size=0x8
    void  ( * PerfControlHandler)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x180 Size=0x8
    void  ( * PerfControlHandlerHidden)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x188 Size=0x8
    void  ( * DomainPerfControlHandler)(unsigned long long ,struct _PERF_CONTROL_STATE_SELECTION * ,unsigned char ,unsigned char );// Offset=0x190 Size=0x8
    void  ( * PerfUpdateHwDebugData)(unsigned long long ,unsigned long long ,unsigned char );// Offset=0x198 Size=0x8
    unsigned long  ( * PerfQueryProcMeasurementCapabilities)();// Offset=0x1a0 Size=0x8
    long  ( * PerfQueryProcMeasurementValues)(unsigned long ,unsigned long * ,void * ,unsigned long );// Offset=0x1a8 Size=0x8
    unsigned long Id;// Offset=0x1b0 Size=0x4
    unsigned long MaxFrequency;// Offset=0x1b4 Size=0x4
    unsigned long NominalFrequency;// Offset=0x1b8 Size=0x4
    unsigned long MaxPercent;// Offset=0x1bc Size=0x4
    unsigned long MinPerfPercent;// Offset=0x1c0 Size=0x4
    unsigned long MinThrottlePercent;// Offset=0x1c4 Size=0x4
    unsigned long AdvertizedMaximumFrequency;// Offset=0x1c8 Size=0x4
    unsigned long long MinimumRelativePerformance;// Offset=0x1d0 Size=0x8
    unsigned long long NominalRelativePerformance;// Offset=0x1d8 Size=0x8
    unsigned char NominalRelativePerformancePercent;// Offset=0x1e0 Size=0x1
    unsigned char Coordination;// Offset=0x1e1 Size=0x1
    unsigned char HardPlatformCap;// Offset=0x1e2 Size=0x1
    unsigned char AffinitizeControl;// Offset=0x1e3 Size=0x1
    unsigned char EfficientThrottle;// Offset=0x1e4 Size=0x1
    unsigned char AllowSchedulerDirectedPerfStates;// Offset=0x1e5 Size=0x1
    unsigned char InitiateAllProcessors;// Offset=0x1e6 Size=0x1
    unsigned char AllowVmPerfSelection;// Offset=0x1e7 Size=0x1
    unsigned char TurboRangeKnown;// Offset=0x1e8 Size=0x1
    unsigned long VmFrequencyStepMhz;// Offset=0x1ec Size=0x4
    unsigned long VmHighestFrequencyMhz;// Offset=0x1f0 Size=0x4
    unsigned long VmNominalFrequencyMhz;// Offset=0x1f4 Size=0x4
    unsigned long VmLowestFrequencyMhz;// Offset=0x1f8 Size=0x4
    unsigned char AutonomousMode;// Offset=0x1fc Size=0x1
    unsigned char AutonomousCapability;// Offset=0x1fd Size=0x1
    unsigned char ProvideGuidance;// Offset=0x1fe Size=0x1
    unsigned long DesiredPercent;// Offset=0x200 Size=0x4
    unsigned long GuaranteedPercent;// Offset=0x204 Size=0x4
    unsigned char EngageResponsivenessOverrides;// Offset=0x208 Size=0x1
    struct _PROC_PERF_QOS_CLASS_POLICY QosPolicies[7];// Offset=0x20c Size=0xc4
    unsigned long QosDisableReasons[7];// Offset=0x2d0 Size=0x1c
    unsigned short QosEquivalencyMasks[7];// Offset=0x2ec Size=0xe
    unsigned char QosSupported;// Offset=0x2fa Size=0x1
    unsigned long SelectionGeneration;// Offset=0x2fc Size=0x4
    struct _PERF_CONTROL_STATE_SELECTION QosSelection[7];// Offset=0x300 Size=0x118
    unsigned long long PerfChangeTime;// Offset=0x418 Size=0x8
    unsigned long PerfChangeIntervalCount;// Offset=0x420 Size=0x4
    unsigned char Force;// Offset=0x424 Size=0x1
    unsigned char Update;// Offset=0x425 Size=0x1
    unsigned char Apply;// Offset=0x426 Size=0x1
};
```

## [StorageD3InModernStandby](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/power-management-for-storage-hardware-devices-intro#d3-support)

Used in the `Disable D3 in Modern Standby` suboption, the value isn't in the power key, but since the first suboption is already related to ModernStandby, and creating a new option for that would be too much, I'll add it here for now.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage";
    "StorageD3InModernStandby" = 4294967295; // REG_DWORD, 0 = Disable D3 support, 1 = Enable D3 support
```

> "*When the system is not in use, Windows may opportunistically turn off power to some set of devices to conserve energy. In Modern Standby, the system remains in S0. Even while in S0, all peripheral devices may eventually be powered down due to idle timeouts. This state is defined as "S0 Low Power Idle". Once all devices are in a low-power state, even more of the system infrastructure (e.g. busses, timers, ...) may be powered down. The general rule of thumb is to place the device in the deepest possible D-state when it is idle, even when the system state is S0. Depending on implementation details of the processor complex and platform design, peripheral devices may be required to go to an F-state, D3 Hot, or D3 Cold (power is cut). To mitigate the need for a function driver to manage these implementation details, drivers should go to the deepest appropriate device state in order to maximize battery life.*"
>
> — Microsoft, [Power Management for Storage Hardware Devices, D3 Support](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/power-management-for-storage-hardware-devices-intro#d3-support)

# USB Audio Idle

It's a mechanism (for audio drivers) for idle detection that switches an audio device between active `D0` (highest power state) and low power sleep (normally [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) = *lowest powered device low power state*), after the configured timeout expires.

Note that `IdlePowerState` only has a meaning if timeouts are nonzero, means as you can see below `PerformanceIdleTime` is set to `0` by default = stays in D0, only when being on DC (battery) it would enter [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3) after 30 seconds. You can see your current device power state (Dx) via [`Device Manager > Sound, video and game controllers > <USB audio device> > Properties > Details > Power data`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/ns-wdm-cm_power_data_s) (`PD_MostRecentPowerState`).

It works via [`DeviceStart`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/DeviceStart.c) -> [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) -> [`PoRegisterDeviceForIdleDetection`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PoRegisterDeviceForIdleDetection.c). In 24H2+ it also registers [`PowerSettingCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/PowerSettingCallback.c) for `GUID_LOW_POWER_EPOCH`, which is why the additional `CS*` values exist.

> "*`[in] ConservationIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for energy conservation. Specify zero to disable idle detection when conservation policy is in effect.*  
> *`[in] PerformanceIdleTime`*  
> *Sets the time-out value (in seconds) to apply when the system power policy optimizes for performance. Specify zero to disable idle detection when performance policy is in effect.*"
>
> — Microsoft, [`PoRegisterDeviceForIdleDetection`](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterdeviceforidledetection)

## Registry Values

[INF values](https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/portcls-registry-power-settings) have type `REG_BINARY`, but [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) only checks the returned value data length (`4`), see '[Build Differences](https://noverse.dev/docs/win-config/power/usb-audio-idle/#build-differences)' section.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e96c-e325-11ce-bfc1-08002be10318}\\00xx\\PowerSettings";
    "ConservationIdleTime" = 30; // DC (battery) timeout
    "PerformanceIdleTime" = 0; // AC timeout
    "IdlePowerState" = 3; // see below
    "CSConservationIdleTime" = 30; // 24H2+, see below
    "CSPerformanceIdleTime" = 30; // 24H2+, ^
```

`IoOpenDeviceRegistryKey(DeviceObject, 2)` opens the driver specific software key (`2` = `PLUGPLAY_REGKEY_DRIVER`), [`RegistryGetIdleInfo`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c) then opens the `PowerSettings` subkey. [`{4d36e96c-e325-11ce-bfc1-08002be10318}`](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/system-defined-device-setup-classes-available-to-vendors) is the `Media` device setup class GUID, [`USBAUDIO.sys` is under that `Media` setup class for USB audio devices](https://learn.microsoft.com/en-us/windows-hardware/drivers/usbcon/supported-usb-classes).

`IdlePowerState` gets "translated" by `USBAUDIO` to (which is why `*a4 = 4` = [`D3`](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/device-sleeping-states#device-power-state-d3)):

| Data | `DEVICE_POWER_STATE` | Meaning |
| --- | --- | --- |
| `1` | `2` | `PowerDeviceD1` |
| `2` | `3` | `PowerDeviceD2` |
| `3` | `4` | `PowerDeviceD3` |
| anything else | `1` | `PowerDeviceD0` |
| missing | `4` | `PowerDeviceD3` |

### Build Differences

Use [diff](https://noverse.dev/diff?kind=pseudocode&left=11-23H2&right=11-24H2&module=USBAUDIO&name=RegistryGetIdleInfo.c&mode=side-by-side) for direct comparison.

23H2 (and below) has two timeout values `ConservationIdleTime`/`PerformanceIdleTime`:

```c
// RegistryGetIdleInfo
*a3 = 0; // PerformanceIdleTime
*a2 = 30; // ConservationIdleTime
*a4 = 4; // PowerDeviceD3

RtlInitUnicodeString(&ValueName, L"ConservationIdleTime");
RtlInitUnicodeString(&v11, L"PerformanceIdleTime");
RtlInitUnicodeString(&v12, L"IdlePowerState");

if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, Pool2, 0x14u, &ResultLength) >= 0
  && Pool2[2] == 4 ) // DataLength == 4
{
  *a2 = Pool2[3];
}
```

24H2+ adds another two timeout values for low power epoch:

```c
// RegistryGetIdleInfo
*a4 = 0; // PerformanceIdleTime
*a2 = 30; // ConservationIdleTime
*a3 = 30; // CSConservationIdleTime
*v6 = 30; // CSPerformanceIdleTime
*v8 = 4; // PowerDeviceD3

RtlInitUnicodeString(&ValueName, L"ConservationIdleTime");
RtlInitUnicodeString(&v15, L"CSConservationIdleTime");
RtlInitUnicodeString(&v16, L"PerformanceIdleTime");
RtlInitUnicodeString(&v17, L"CSPerformanceIdleTime");
RtlInitUnicodeString(&v18, L"IdlePowerState");
```

`GUID_LOW_POWER_EPOCH` is a power setting GUID, if the callbacks 4 byte value is nonzero, `Context + 1080` becomes `1` and the `CS*` values are used, otherwise the other two are used.

```c
// DeviceStart
if ( *((_DWORD *)Context + 270) ) // LOW_POWER_EPOCH stored by PowerSettingCallback
{
  v11 = *((_DWORD *)Context + 139); // CSPerformanceIdleTime
  v12 = *((_DWORD *)Context + 137); // CSConservationIdleTime
}
else
{
  v11 = *((_DWORD *)Context + 138); // PerformanceIdleTime
  v12 = *((_DWORD *)Context + 136); // ConservationIdleTime
}
*((_QWORD *)Context + 66) = PoRegisterDeviceForIdleDetection(
                              a1->PhysicalDeviceObject,
                              v12,
                              v11,
                              (DEVICE_POWER_STATE)*((_DWORD *)Context + 135));

PoRegisterPowerSettingCallback( // https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterpowersettingcallback
  a1->PhysicalDeviceObject,
  &GUID_LOW_POWER_EPOCH,
  (PPOWER_SETTING_CALLBACK)PowerSettingCallback,
  a1,
  (PVOID *)Context + 134);
```

```c
// PowerSettingCallback
if ( *SettingGuid == *(_OWORD *)&GUID_LOW_POWER_EPOCH )
{
  if ( (_DWORD)ValueLength == 4 && Value )
  {
    *(_DWORD *)(v8 + 1080) = *v6 != 0; // LOW_POWER_EPOCH
  }
}
```

- [11-23H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-24H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-25H2/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/USBAUDIO/RegistryGetIdleInfo.c)
- [11-26H1/USBAUDIO/RegistryGetIdleInfo.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/USBAUDIO/RegistryGetIdleInfo.c)

# Disable NIC Power Savings

You can get a lot of information about data ranges and more from `.inf` files, see examples below.

## [Registry Value](https://github.com/nohuto/regkit/blob/main/records/NIC-Intel.txt) Overview

See [network/assets/intel-nic](https://github.com/nohuto/win-config/tree/main/network/assets/intel-nic) for reference.

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    "*DeviceSleepOnDisconnect" = 0; // range 0-1
    "*EnableDynamicPowerGating" = 1; // range 0-1
    "DisableIntelRST" = 1; // range 0-1
    "DMACoalescing" = 0; // range 0-10240
    "EnableDisconnectedStandby" = 0; // range 0-1
    "EnableModernStandby" = 0; // range 0-1
    "EnablePME" = 0; // range 0-1
    "EnablePowerManagement" = 1; // range 0-1
    "ForceHostExitUlp" = 0; // range 0-1
    "ForceLtrValue" = 65535; // range 0-65535
    "I218DisablePLLShut" = 0; // range 0-1
    "I218DisablePLLShutGiga" = 0; // range 0-1
    "I219DisableK1Off" = 0; // range 0-1
    "ULPMode" = 1; // range 0-1
```

| SubkeyName | ParamDesc | Default | Minimum | Maximum |
| --- | --- | --- | --- | --- |
| `*WakeOnPattern` | A value that describes whether the device should be enabled to wake the computer when a network packet matches a specified pattern. | 1 | 0 | 1 |
| `*WakeOnMagicPacket` | A value that describes whether the device should be enabled to wake the computer when the device receives a magic packet. A magic packet is a packet that contains 16 contiguous copies of the receiving network adapter's ethernet address. | 1 | 0 | 1 |
| `*EEE` | A value that describes whether the device should enable IEEE 802.3az energy-efficient ethernet. | 1 | 0 | 1 |
| `*IdleRestriction` | If a network device has both idle power down and wake on packet filter capabilities, this setting allows the user to decide when the device idle power down can happen. `1` = Only idle when user isn't present, `0` = No restriction | 0 | 0 | 1 |
| `*ModernStandbyWoLMagicPacket` | A value that describes whether the device should be enabled to wake the computer when the device receives a magic packet and the system is in the S0ix power state. This doesn't apply when the system is in the S4 power state. | 0 | 0 | 1 |
| `*DeviceSleepOnDisconnect` | A value that describes whether the device should be enabled to put the device into a low-power state (sleep state) when media is disconnected and return to a full-power state (wake state) when media is connected again. | 1 | 0 | 1 |
| [`*SelectiveSuspend`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-selective-suspend) | Selective suspend (0 disabled, 1 enabled) | 1 | 0 | 1 |
| [`*SSIdleTimeout`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend#ssidletimeout-inf-keyword) | This keyword specifies the idle time-out period in units of seconds. If NDIS does not detect any activity on the network adapter for a period that exceeds the *SSIdleTimeout value, NDIS starts a selective suspend operation by calling the miniport driver's MiniportIdleNotification handler function. | 5 | 1 | 60 |
| [`*SSIdleTimeoutScreenOff`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend#ssidletimeoutscreenoff-inf-keyword) | This keyword specifies the idle time-out period in units of seconds and is only applicable when the screen is off. If NDIS does not detect any activity on the network adapter for a period that exceeds the *SSIdleTimeoutScreenOff value after the screen is off, NDIS starts a selective suspend operation by calling the miniport driver's MiniportIdleNotification handler function. | 3 | 1 | 60 |

- [network/standardized-inf-keywords-for-power-management](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-power-management.md)
- [network/standardized-inf-keywords-for-ndis-selective-suspend](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/network/standardized-inf-keywords-for-ndis-selective-suspend.md)

### Setup Information

```powershell
HKR,Ndi\Params\*DeviceSleepOnDisconnect,ParamDesc,    ,%DeviceSleepOnDisconnectDesc%
HKR,Ndi\Params\*DeviceSleepOnDisconnect,type,         ,enum
HKR,Ndi\Params\*DeviceSleepOnDisconnect,default,      ,0
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,0,       ,%Disabled%
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,1,       ,%Enabled%

HKR, Ndi\Params\*EEE,    	                ParamDesc,      0,       %EEE%
HKR, Ndi\Params\*EEE,    	                Type,           0,       "enum"
HKR, Ndi\Params\*EEE\enum, 	                "1",            0,       %Enabled%
HKR, Ndi\Params\*EEE\enum, 	                "0",            0,       %Disabled%
HKR, Ndi\Params\*EEE,    	                Default,        0,       "0"

HKR,Ndi\params\*SelectiveSuspend,	    ParamDesc,  0, %SelectiveSuspend%
HKR,Ndi\params\*SelectiveSuspend,	    default,    0, "1"
HKR,Ndi\params\*SelectiveSuspend,	    type,       0, "enum"
HKR,Ndi\params\*SelectiveSuspend\enum,   "0",        0, "Disabled"
HKR,Ndi\params\*SelectiveSuspend\enum,   "1",        0, "Enabled"

HKR,Ndi\Params\*SSIdleTimeout,      ParamDesc,  0, "SSIdleTimeout"
HKR,Ndi\Params\*SSIdleTimeout,      Type,       0, "int"
HKR,Ndi\Params\*SSIdleTimeout,      Default,    0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Min,        0, "1" ; might also be at 5
HKR,Ndi\Params\*SSIdleTimeout,      Max,        0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Step,       0, "1"
HKR,Ndi\Params\*SSIdleTimeout,      Base,       0, "10"

HKR, Ndi\params\AdvancedEEE,        ParamDesc,  0, %AdvancedEEE%
HKR, Ndi\params\AdvancedEEE,        optional,   0, "1"
HKR, Ndi\params\AdvancedEEE,        Type,       0, "enum"
HKR, Ndi\params\AdvancedEEE,        Default,    0, "0"
HKR, Ndi\params\AdvancedEEE\enum,   "0",        0, %Disabled%
HKR, Ndi\params\AdvancedEEE\enum,   "1",        0, %Enabled%

[DisableAutoPowerSave.reg]
HKR,,				       AutoPowerSaveModeEnabled, 0, "0"

HKR, Ndi\params\EnableGreenEthernet,        ParamDesc,  0, %GreenEthernet%
;HKR, Ndi\params\EnableGreenEthernet,        optional,   0, "1"
HKR, Ndi\params\EnableGreenEthernet,        Type,       0, "enum"
HKR, Ndi\params\EnableGreenEthernet,        Default,    0, "0"
HKR, Ndi\params\EnableGreenEthernet\enum,   "0",        0, %Disabled%
HKR, Ndi\params\EnableGreenEthernet\enum,   "1",        0, %Enabled%

HKR, Ndi\params\GigaLite,        ParamDesc,  0, %GigaLite%
;HKR, Ndi\params\GigaLite,        optional,   0, "1"
HKR, Ndi\params\GigaLite,        Type,       0, "enum"
HKR, Ndi\params\GigaLite,        Default,    0, "1"
HKR, Ndi\params\GigaLite\enum,   "0",        0, %Disabled%
HKR, Ndi\params\GigaLite\enum,   "1",        0, %Enabled%

HKR,Ndi\params\*IdleRestriction,        ParamDesc,  0, %IdleRestriction%
HKR,Ndi\params\*IdleRestriction,        Type,       0, "enum"
HKR,Ndi\params\*IdleRestriction,        Default,    0, "0"
HKR,Ndi\params\*IdleRestriction\enum,   "0",        0, %RestrictionDisable%
HKR,Ndi\params\*IdleRestriction\enum,   "1",        0, %RestrictionEnable%

HKR,Ndi\params\PowerSavingMode,    ParamDesc,  0, %PowerSavingMode%
HKR,Ndi\params\PowerSavingMode,    Type,       0, "enum"
HKR,Ndi\params\PowerSavingMode,    Default,    0, "1"
HKR,Ndi\params\PowerSavingMode\enum,   "0",    0, %Disabled%
HKR,Ndi\params\PowerSavingMode\enum,   "1",    0, %Enabled%

HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  ParamDesc,              0, %ReduceSpeedOnPowerDown%
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Type,                   0, "enum"
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Default,                0, "1"
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "1",                    0, %Enabled%
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "0",                    0, %Disabled%

HKR,Ndi\Params\ULPMode,                                 Type,                   0, "enum"
HKR,Ndi\Params\ULPMode,                                 Default,                0, "1"
HKR,Ndi\Params\ULPMode\Enum,                            "1",                    0, %Enabled%
HKR,Ndi\Params\ULPMode\Enum,                            "0",                    0, %Disabled%

; Allow host driver to force exit ULP on ME systems
HKR,,                                                   ForceHostExitUlp,       0, "1"

HKR,Ndi\params\WolShutdownLinkSpeed,           ParamDesc,       0, %WolShutdownLinkSpeed%
;HKR,Ndi\params\WolShutdownLinkSpeed,          optional,        0, "1"
HKR,Ndi\params\WolShutdownLinkSpeed,           Type,            0, "enum"
HKR,Ndi\params\WolShutdownLinkSpeed,           Default,         0, "0"
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "0",             0, %10MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "1",             0, %100MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "2",             0, %NotSpeedDown%
```

Reminder: Each adapter uses it's own default values, means that the `default`/`min`/`max` may be different for you. E.g. `SSIdleTimeout` minimum value was `1` in the first setup information file (`.inf`), but `5` in the second.

### Miscellaneous Values

```c
"DynamicLTR": { "Type": "REG_SZ", "Data": 0 },
"EnableAdvancedDynamicITR": { "Type": "REG_SZ", "Data": 0 },
"S3S4WolPowerSaving": { "Type": "REG_SZ", "Data": 0 },
"AutoLinkDownPcieMacOff": { "Type": "REG_SZ", "Data": 0 }, // "Auto Disable PCIe"
"BatteryModeLinkSpeed": { "Type": "REG_SZ", "Data": 2 },  // Similar to WolShutdownLinkSpeed?
// 10MbFirst                      = "10 Mbps First"
// 100MbFirst                     = "100 Mbps First"
// NotSpeedDown                   = "Not Speed Down"
// AdaptiveLinkSpeed              = "Adaptive Link Speed"
// BatteryModeLinkSpeed           = "Battery Mode Link Speed"
"CLKREQ": { "Type": "REG_SZ", "Data": 0 },
"EnableCoalesce": { "Type": "REG_SZ", "Data": 0 },
"DMACoalescing": { "Type": "REG_SZ", "Data": 0 },
"CoalesceBufferSize": { "Type": "REG_SZ", "Data": 0 },
"*PacketCoalescing": { "Type": "REG_SZ", "Data": 0 },

"SVOFFMode": { "Type": "REG_SZ", "Data": 1 },  // SV: Save?
"SVOFFModeHWM": { "Type": "REG_SZ", "Data": 0 },
"SVOFFModeTimer": { "Type": "REG_SZ", "Data": 0 }

"EnabledDatapathCycleCounters":  { "Type": "REG_SZ", "Data": ? }
"EnabledDatapathEventCounters": { "Type": "REG_SZ", "Data": ? }
```

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

# Remove Power Options

Removes the `Hibernate`, `Lock`, `Sleep` power options.

If hiding `Lock` for example via `Control Panel > All Control Panel Items > Power Options > Choose what the power buttons do > Change settings that are currently unavailable`, it sets:
```c
DllHost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FlyoutMenuSettings\ShowLockOption	Type: REG_DWORD, Length: 4, Data: 1
```

---

Miscellaneous keys:
```powershell
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HidePowerButton
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideRestart
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideShutDown
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSignOut
HKLM\SOFTWARE\Microsoft\PolicyManager\default\Start\HideSwitchAccount
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Show lock in the user tile menu](https://noverse.dev/policies?p=WindowsExplorer*ShowLockOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowLockOption` |
| [Show sleep in the power options menu](https://noverse.dev/policies?p=WindowsExplorer*ShowSleepOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowSleepOption` |
| [Show hibernate in the power options menu](https://noverse.dev/policies?p=WindowsExplorer*ShowHibernateOption) | `HKLM\Software\Policies\Microsoft\Windows\Explorer` | `ShowHibernateOption` |

# Disable Energy Estimation

Energy estimation accounts for estimated power usage, components report modeled energy costs, which are tracked per process and used for battery and standby telemetry.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "UserBatteryDischargeEstimator" = 0; // PopDisableBatteryDischargeEstimator, 0 allows WNF_PO_DISCHARGE_ESTIMATE updates, https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PopBatteryWorker.c
    "UserBatteryChargeEstimator" = 0; // PopUserBatteryChargingEstimator, 0 clears WNF_PO_CHARGE_ESTIMATE, https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PopBatteryWorker.c
    "EnergyEstimationEnabled" = 1; // PopEnergyEstimationEnabled, https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/ntoskrnl/PoEnergyEstimationEnabled.c
```

- [power/assets | PtInitializeTelemetry.c](https://github.com/nohuto/win-config/blob/main/power/assets/energyesti-PtInitializeTelemetry.c)

![](https://github.com/nohuto/win-config/blob/main/power/images/energyesti.png?raw=true)

## Suboption

### Battery Capacity Section

Disables the battery capacity section on the battery saver page of the system settings app.

## IdleStatesNumber

These values are located in `partmgr.sys` and can be misunderstood. `IdleStatesNumber` just tells `partmgr` how many `IdleState\x` estimation "profiles" to load, example:

- `IdleStatesNumber = 1` -> read only `IdleState\1`
- `IdleStatesNumber = 3` -> read `IdleState\1`, `IdleState\2`, `IdleState\3`

So these values seem to change the estimated energy *math* part.

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Control\Power\EnergyEstimation\Storage\NVME : IdleStatesNumber
\Registry\Machine\SYSTEM\ControlSet001\Control\Power\EnergyEstimation\Storage\NVME\IdleState\1 : IdleExitEnergyMicroJoules
\Registry\Machine\SYSTEM\ControlSet001\Control\Power\EnergyEstimation\Storage\NVME\IdleState\1 : IdleExitLatencyMs
\Registry\Machine\SYSTEM\ControlSet001\Control\Power\EnergyEstimation\Storage\NVME\IdleState\1 : IdlePowerMw
\Registry\Machine\SYSTEM\ControlSet001\Control\Power\EnergyEstimation\Storage\NVME\IdleState\1 : IdleTimeLengthMs
```

- [power/assets | PmPowerContextInitialization.c](https://github.com/nohuto/win-config/blob/main/power/assets/energyesti-PmPowerContextInitialization.c)

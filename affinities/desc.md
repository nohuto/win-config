# Interrupt Handling and Affinity Policies

Note that everything written below is based on:
> [affinities/assets | E7-P2.pdf](https://github.com/5Noxi/win-config/blob/main/affinities/assets/E7-P2.pdf)  
> [drivers/kernel | introduction-to-interrupt-service-routines](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-interrupt-service-routines)  
> [drivers/kernel | interrupt-affinity-and-priority](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/interrupt-affinity-and-priority)  
> [drivers/kernel | introduction-to-message-signaled-interrupts](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/introduction-to-message-signaled-interrupts)

## Line-Based vs. Message-Signaled Interrupts

Shared line-based interrupts cause high latency and can even create stability problems because multiple device drivers must share the limited physical interrupt lines that exist on a computer. A single 7-in-1 media reader, for example, connects each of its controllers to one interrupt line, forcing the operating system to invoke each driver in sequence to discover which controller actually raised the interrupt. Giving each controller its own line would lower latency, but it would also exhaust the traditional IRQ lines very quickly, and PCI devices are physically wired to a single IRQ line, so they cannot consume more than one line even if drivers wanted to.

Mismanaged line-based interrupts introduce additional problems. Because the interrupt controller drives the signal high or low until the ISR acknowledges it (and until the controller receives an explicit end of interrupt signal), a buggy driver can leave the system stuck servicing a single interrupt forever or mask additional interrupts entirely. Line-based interrupts also scale poorly on multiprocessor systems, because hardware, not the operating system, makes the final decision about which processor in the allowed set actually receives the interrupt.

Message-signaled interrupts (MSI), first introduced in the PCI 2.2 standard and now common thanks to PCI Express 3.0 and later, solve these problems by having the device write a message to a specific memory address over the PCI bus. Hardware treats the write like a DMA operation, Windows raises the interrupt, and the ISR receives both the message content and the address that was targeted. MSI removes the need for drivers to query devices after the interrupt fires, which further reduces latency.

## MSI Mode and Limits

A single MSI-capable device can deliver multiple messages (up to 32) to the same memory address, using different payloads for different events. MSI-X, introduced in PCI 3.0, extends the model by supporting 32-bit messages (instead of 16-bit), up to 2,048 different messages (instead of 32), and the ability to use a different target address for each payload. That flexibility allows hardware to route interrupts to the processors that initiated the related work so that interrupt completion is NUMA-aware and latency-sensitive.

Because MSI delivers interrupts via memory writes, the architecture no longer depends on the physical IRQ lines. The total system limit of MSIs therefore equals the number of interrupt vectors rather than the number of available lines, which eliminates the incentive for sharing interrupts and removes the line count bottleneck that constrained traditional IRQ designs. Windows often refers to interrupts in this context by their global system interrupt vector (GSIV), which can represent a legacy line-based IRQ, a negative MSI vector, or even a GPIO pin. (On ARM and ARM64 systems, Windows instead uses the Generic Interrupt Controller architecture to deliver interrupts.)

## IRQ Basics

External device interrupts enter an interrupt controller such as an IOAPIC, which then interrupts one or more processors through their LAPICs. When a processor is interrupted, it queries the controller for the global system interrupt vector, which is sometimes represented as an interrupt request (IRQ) number. The controller translates that GSIV/IRQ value into a processor interrupt vector that indexes the Interrupt Dispatch Table (IDT), allowing the processor to transfer control to the appropriate Ring 0 interrupt routine.

## Interrupt Affinity and Priority

Driver writers and administrators can choose both the processors (or processor groups) that will receive a given interrupt (affinity) and the policy that determines how processors are picked inside that group. Affinity policy is configured through the `InterruptPolicyValue` registry value under `Interrupt Management\Affinity Policy` within the device's instance key. Microsoft documents the affinity interface at [kernel/interrupt-affinity-and-priority](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/interrupt-affinity-and-priority). In addition to affinity policy, a separate registry value controls the interrupt's priority, which adjusts the IRQL Windows assigns to the vector.

### IRQ Affinity Policies

| Policy | Meaning |
| --- | --- |
| `IrqPolicyMachineDefault` | The device does not require a particular affinity policy. Windows uses the default machine policy, which (for machines with less than eight logical processors) is to select any available processor on the machine. |
| `IrqPolicyAllCloseProcessors` | On a NUMA machine, the Plug and Play manager assigns the interrupt to all the processors that are close to the device (on the same node). On non-NUMA machines, this is the same as `IrqPolicyAllProcessorsInMachine`. |
| `IrqPolicyOneCloseProcessor` | On a NUMA machine, the Plug and Play manager assigns the interrupt to one processor that is close to the device (on the same node). On non-NUMA machines, the chosen processor will be any available processor on the system. |
| `IrqPolicyAllProcessorsInMachine` | The interrupt is processed by any available processor on the machine. |
| `IrqPolicySpecifiedProcessors` | The interrupt is processed only by one of the processors specified in the affinity mask under the `AssignmentSetOverride` registry value. |
| `IrqPolicySpreadMessagesAcrossAllProcessors` | Different message-signaled interrupts are distributed across an optimal set of eligible processors, keeping track of NUMA topology issues, if possible. This requires MSI-X support on the device and platform. |
| `IrqPolicyAllProcessorsInGroupWhenSteered` | The interrupt is subject to interrupt steering, and as such, the interrupt should be assigned to all processor IDTs as the target processor will be dynamically selected based on steering rules. |

`AssignmentSetOverride` calculation:
```powershell
$cpus = @(8,9) # CPU 8 & 9
$mask = 0
$cpus | % { $mask = $mask -bor (1 -shl $_) }
'{0:X16}' -f $mask # 0000000000000300
```

### IRQ Priorities

| Priority | Meaning |
| --- | --- |
| `IrqPriorityUndefined` | No particular priority is required by the device. It receives the default priority (`IrqPriorityNormal`). |
| `IrqPriorityLow` | The device can tolerate high latency and should receive a lower IRQL than usual (3 or 4). |
| `IrqPriorityNormal` | The device expects average latency. It receives the default IRQL associated with its interrupt vector (5 to 11). |
| `IrqPriorityHigh` | The device requires as little latency as possible. It receives an elevated IRQL beyond its normal assignment (12). |

Windows is not a real-time operating system, so these IRQ priorities simply adjust the IRQL Windows associates with the interrupt, they do not provide additional scheduling priority.

## Avoiding IRQ Sharing

Shared, line-based interrupts are usually the cause of higher latency and stability issues because every driver wired to that IRQ must run in sequence before the real source is found. You can confirm sharing by using [windbg](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/) to dump a device node (`!devnode <address> f`), which prints the raw and translated resource lists for that device, if multiple devices list the same IRQ entry (same level, vector, and affinity), they are sharing a line. The Device Manager shows the same information under each device's "Resources" tab, and the System Information tool lists current "Conflicts/Sharing", so you can see duplicated IRQ numbers without attaching a debugger. On ACPI-based systems you can also run `!acpiirqarb` to display the IRQ-to-IDT mapping table and see the current GSIV assignments across the platform.

When you discover shared lines, switch the device to MSI mode so it no longer consumes a limited physical IRQ line. If the hardware cannot use MSI, you can still reduce contention by adjusting `InterruptPolicyValue` so the PnP manager keeps the interrupt close to the device and avoids repeatedly switching it across processors.

---

Previous MSI Mode JSON part, ignore it.

```json
"apply": {
  "COMMANDS": {
    "EnableMSI": {
      "Action": "registry_pattern",
      "Pattern": "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\PCI\\**\\Device Parameters\\Interrupt Management",
      "Operations": [
        { "SubKey": "MessageSignaledInterruptProperties", "Value": "MSISupported", "Type": "REG_DWORD", "Data": 1 },
        { "SubKey": "MessageSignaledInterruptProperties", "Value": "MessageNumberLimit", "Operation": "deletevalue" }
      ]
    }
  }
},
"revert": {
  "COMMANDS": {
    "RemoveMSI": {
      "Action": "registry_pattern",
      "Pattern": "HKLM\\SYSTEM\\CurrentControlSet\\Enum\\PCI\\**\\Device Parameters\\Interrupt Management",
      "Operations": [
        { "SubKey": "MessageSignaledInterruptProperties", "Value": "MSISupported", "Operation": "deletevalue" },
        { "SubKey": "MessageSignaledInterruptProperties", "Value": "MessageNumberLimit", "Operation": "deletevalue" }
      ]
    }
  }
}
```

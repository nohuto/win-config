# Interrupt Handling & Affinities

The sections below will be extended somewhat soon.

## Validating Changes

You can either analyze the record via WPA or MXA, I personally prefer MXA here.

```c
wpr -start CPU.light -start GPU.light
wpr -stop "%USERPROFILE%\Desktop\gpu_trace.etl"
```

Open the `.etl` in MXA, expand `CPU > ISRs and DPCs > Drivers` and drag the driver into the panel (e.g. `nvlddmkm.sys`), if selecting core 8/9 for the GPU:

![](https://github.com/nohuto/win-config/blob/main/affinities/images/mxanvlddmkm.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/affinities/images/mxadxgkrnl.png?raw=true)

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
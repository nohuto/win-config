# NDIS Poll Mode

> "*NDIS Poll Mode is an OS controlled polling execution model that drives the network interface datapath.*
>
> *Previously, NDIS had no formal definition of a datapath execution context. NDIS drivers typically relied on Deferred Procedure Calls (DPCs) to implement their execution model. However using DPCs can overwhelm the system when long indication chains are made and avoiding this problem requires a lot of code that's tricky to get right. NDIS Poll Mode offers an alternative to DPCs and similar execution tools.*
>
> *NDIS Poll Mode moves the complexity of scheduling decisions away from NIC drivers and into NDIS, where NDIS sets work limits per iteration. To achieve this Poll Mode provides:*  
> *- A mechanism for the OS to exert back pressure on the NIC.*  
> *- A mechanism for the OS to finely control interrupts.*
>
> *NDIS Poll Mode is available to NDIS 6.85 and later miniport drivers.*"
>
> — Microsoft, [NDIS Poll Mode](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-poll-mode)

## MS INF

`*NdisPoll` is a MS INF keyword for enabling/disabling NDIS Poll Mode support:

```c
HKR, Ndi\params\*NdisPoll,       ParamDesc,            0, "Ndis Poll Mode"
HKR, Ndi\params\*NdisPoll,       Type,                 0, "enum"
HKR, Ndi\params\*NdisPoll,       Default,              0, "1"
HKR, Ndi\params\*NdisPoll,       Optional,             0, "0"
HKR, Ndi\params\*NdisPoll\enum,  "0",                  0, "Disabled"
HKR, Ndi\params\*NdisPoll\enum,  "1",                  0, "Enabled"
```

## [NVIDIA WinOF-2](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)

That guide ([WinOF-2 v23.7](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)) uses the values to register and use NDIS Poll Mode, it depends on your driver version whenever they're accepted (e.g. `mlx5.sys` `2.53.23539` has a range of `0-3` for `RecvCompletionMethod`, `4` would be invalid causing it to fallback to the default (`1`)).

| Side | Value | Default |
| ---- | ---- | ---- |
| Receive | `RecvCompletionMethod = 4` | `1` (Adaptive) |
| Transmit | `SendCompletionMethod = 2` | `1` (Interrupt) |

## [AsyncReceiveIndicate](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf) (Packet Burst Handling)

This feature (used by mlx driver) allows packet burst handling, while avoiding packet drops that may occur when a large amount of packets is sent in a short period of time.

| Data | Meaning |
| ---- | ---- |
| 0 | Disabled (default) |
| 1 | Enables packet burst buffering using threaded DPC |
| 2 | Enables packet burst buffering using polling |

## [Receive Completion Method](https://docs.nvidia.com/nvidia-winof-2-documentation-v23-7.pdf)

`RecvCompletionMethod` selects how the Mellanox (NVIDIA) driver handles receive completions:

- `0` (`Polling`) polls the receive ring until the configured `ThreadPoll` count is reached without receiving a packet, then stops polling and rearms the interrupt (`CRxQueue::PollFunction`)
- `1` (`Adaptive`, default) combines interrupts and polling according to traffic and network use
- `4` registers and uses NDIS Poll Mode (on WinOF-2 drivers that support it)

### Setup Information

```c
HKR, NDI\Params\RecvCompletionMethod,  ParamDesc, 0, "%RecvCompletionMethod%"
HKR, NDI\Params\RecvCompletionMethod,  Type,  0, "enum"
HKR, NDI\Params\RecvCompletionMethod,  Default, 0, "1"
HKR, NDI\Params\RecvCompletionMethod,  Optional, 0, "0"
HKR, NDI\Params\RecvCompletionMethod\enum,  "0", 0, "%Polling%"
HKR, NDI\Params\RecvCompletionMethod\enum,  "1", 0, "%Adaptive%"
HKR, "", RecvCompletionMethod, 0, "1"
```


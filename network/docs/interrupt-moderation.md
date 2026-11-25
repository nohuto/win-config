# Interrupt Moderation

> "*To control interrupt moderation, some network adapters expose different interrupt moderation levels, different buffer coalescing parameters (sometimes separately for send and receive buffers), or both.*
>
> *You should consider interrupt moderation for CPU-bound workloads. When using interrupt moderation, consider the trade-off between the host CPU savings and latency versus the increased host CPU savings because of more interrupts and less latency. If the network adapter doesn't perform interrupt moderation, but it does expose buffer coalescing, you can improve performance by increasing the number of coalesced buffers to allow more buffers per send or receive.*"
>
> — Microsoft, [Performance tuning network adapters](https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-tuning-nics?tabs=powershell#interrupt-moderation)

> *Disable the Interrupt Moderation setting for network card drivers that require the lowest possible latency. Remember, this configuration can use more CPU time and it represents a tradeoff.*
>
> — Microsoft, [Low-latency packet processing](https://learn.microsoft.com/en-us/windows-server/networking/technologies/network-subsystem/net-sub-performance-tuning-nics#low-latency-packet-processing)

### ITR (Intel)

| Value | Default | Meaning |
| --- | --- | --- |
| `0` | | Off |
| `32` / `200` | | Minimal (I225/I226 / I219 and older) |
| `64` / `400` | I225/I226 | Low |
| `125` / `950` | | Medium |
| `250` / `2000` | | High |
| `500` / `3600` | | Extreme |
| `65535` | I219 and older | Adaptive (older drivers only) |

## Setup Information

Data/default is driver specific.
```c
;  Interrupt Throttle Rate
HKR, Ndi\Params\ITR,                                    ParamDesc,              0, %InterruptThrottleRate%
HKR, Ndi\Params\ITR,                                    default,                0, "65535"
HKR, Ndi\Params\ITR\Enum,                               "65535",                0, %Adaptive%
HKR, Ndi\Params\ITR\Enum,                               "3600",                 0, %Extreme%
HKR, Ndi\Params\ITR\Enum,                               "2000",                 0, %High%
HKR, Ndi\Params\ITR\Enum,                               "950",                  0, %Medium%
HKR, Ndi\Params\ITR\Enum,                               "400",                  0, %Low%
HKR, Ndi\Params\ITR\Enum,                               "200",                  0, %Minimal%
HKR, Ndi\Params\ITR\Enum,                               "0",                    0, %Off%
HKR, Ndi\Params\ITR,                                    type,                   0, "enum"

;  Interrupt Throttle Rate
HKR, Ndi\Params\ITR,                                    ParamDesc,              0, %InterruptThrottleRate%
HKR, Ndi\Params\ITR,                                    default,                0, "64"
HKR, Ndi\Params\ITR\Enum,                               "500",                  0, %Extreme%
HKR, Ndi\Params\ITR\Enum,                               "250",                  0, %High%
HKR, Ndi\Params\ITR\Enum,                               "125",                  0, %Medium%
HKR, Ndi\Params\ITR\Enum,                               "64",                   0, %Low%
HKR, Ndi\Params\ITR\Enum,                               "32",                   0, %Minimal%
HKR, Ndi\Params\ITR\Enum,                               "0",                    0, %Off%
HKR, Ndi\Params\ITR,                                    type,                   0, "enum"

; *InterruptModeration
HKR, Ndi\Params\*InterruptModeration,                   ParamDesc,              0, %InterruptModeration%
HKR, Ndi\Params\*InterruptModeration,                   default,                0, "1"
HKR, Ndi\Params\*InterruptModeration\Enum,              "0",                    0, %Disabled%
HKR, Ndi\Params\*InterruptModeration\Enum,              "1",                    0, %Enabled%
HKR, Ndi\Params\*InterruptModeration,                   type,                   0, "enum"
```

```
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : ITR
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *InterruptModeration
```

---

Miscellaneous notes (NVIDIA/Mellanox ConnectX coalescing values):

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "RecvIntModCount" = ?; // range 0-1000, mlx5.sys
  "RecvIntModTime" = ?; // ipoib6x.sys, mlx4eth63.sys
  "SendIntModCount" = ?; // range 0-1000, mlx5.sys
  "SendIntModTime" = ?; // range 0-1000, mlx5.sys
```

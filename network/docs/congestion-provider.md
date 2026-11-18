# Congestion Provider

## Congestion and when it happens

See [TCP Congestion Control, RFC 5681](https://datatracker.ietf.org/doc/rfc5681/) for details.

## SettingName Table

| SettingName | Purpose / When to use |
|---|---|
| `Automatic` | Default selector, uses latency to choose `Internet` or `Datacenter`, if `AutomaticUseCustom` is enabled, it chooses `InternetCustom` or `DatacenterCustom` instead |
| `Internet` | Built-in template for higher latency, lower throughput networks |
| `Datacenter` | Built-in template for lower latency, higher throughput networks |
| `Compat` | Compatibility template for legacy equipment or older application/network behavior |
| `InternetCustom` | Custom Internet side template, use when you want to override the provider |
| `DatacenterCustom` | Custom datacenter side template, use when you want to override the provider |

## CongestionProvider Table

| Provider | Description / algorithm |
|---|---|
| `Default` | System default provider ([CUBIC](https://www.ietf.org/rfc/rfc9438.html)) |
| `CTCP` | Microsoft hybrid loss + delay control, adds a delay based window to standard TCP behavior and uses RTT/queue growth as an early signal |
| `DCTCP` | ECN-based datacenter control, estimates the fraction of marked packets and reduces the window proportionally, keeping queues small |
| [`CUBIC`](https://www.ietf.org/rfc/rfc9438.html) | Loss based control with a cubic window growth function after a congestion event. Built for scalable high BDP (bandwidth delay product) behavior |
| `BBR2` | BBR = Bottleneck Bandwidth and Round-trip Time, public literature describes it as using delivery rate, RTT, and loss to target high throughput with low queueing |

See your current congestion provider via:

```powershell
Get-NetTCPSetting | Select SettingName, CongestionProvider
```

## Unsupported

Note that `Get-NetTCPSetting` & `netsh int tcp show supplemental` only show what got stored, not what actually runs for a connection, e.g. on W11 `netsh int tcp set supplemental template=internet congestionprovider=ctcp` works and both show `CTCP`, but new connections still use CUBIC.

- W11, `NewReno` & `CTCP` (there are no functions of these anymore) = use `CUBIC`
- W10, `BBR2` not available

The records below are from a `Microsoft-Windows-TCPIP` ETW trace, some events are only written by one algorithms code (see public symbols of `tcpip.sys`), which tells what is used:

| Event | Written by | Algorithm |
|---|---|---|
| 1429 | `CubicCumulativeAck` | CUBIC |
| 1583 | `Bbr2OnSend` | BBR2 |
| 1225 | `DctcpUpdateEcnAlpha` (via `DctcpCumulativeAck`) | DCTCP |
| 1380 | `LedbatCumulativeAck` | LEDBAT |
| 1162, 1331 | CTCP module (W10) | CTCP |

### W11 25H2 Records

```c
// default (1429)
  conn default port 59781 tcb 0xFFFFE3883EB369F0 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/CUBIC
    module events : 1429 CUBIC=35 | acks 1330=1441 sends 1332=89 paced 1447=0
    sample before CUBIC: TCP: connection 0xffffe3883eb369f0: Cumulative Ack event, SeqNo = 2343609397, BytesAcked = 0, CWnd = 29200, SndWnd = 65535, InRecovery = 0, TimeSinceLastLossMS = 0, CubicCwnd = 0, AimdCwnd = 0, K = 0, Wmax = 0, LastWmax = 0, MaxSndWnd = 65535 IsLimitedSlowStart = 0.

// SIO_PRIORITY_HINT VeryLow (1380)
  conn ledbat-hint port 58190 tcb 0xFFFFE3883DAE57A0 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/LEDBAT
    module events : 1380 LEDBAT=1442 | acks 1330=1441 sends 1332=126 paced 1447=0
    sample before LEDBAT: TCP: LEDBAT Ack: Connection 0xffffe3883dae57a0, BaseDelayMs = 1, CurrentDelayMs = 1, CWnd = 3739, SsThresh = 4294967295, SndWnd = 65535, DelayBasedCwndFactor 100%%, RemainingTimeMs = 0.

// NewReno (still 1429)
  conn new-after-newreno port 58741 tcb 0xFFFFE3883DAE57A0 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/NewReno
    module events : 1429 CUBIC=35 | acks 1330=1440 sends 1332=86 paced 1447=0
    sample before CUBIC: TCP: connection 0xffffe3883dae57a0: Cumulative Ack event, SeqNo = 3145196530, BytesAcked = 0, CWnd = 29200, SndWnd = 65535, InRecovery = 0, TimeSinceLastLossMS = 0, CubicCwnd = 0, AimdCwnd = 0, K = 0, Wmax = 0, LastWmax = 0, MaxSndWnd = 65535 IsLimitedSlowStart = 0.

// CTCP (still 1429)
  conn new-after-ctcp port 55035 tcb 0xFFFFE3883DAE57A0 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/CTCP
    module events : 1429 CUBIC=35 | acks 1330=1441 sends 1332=85 paced 1447=0
    sample before CUBIC: TCP: connection 0xffffe3883dae57a0: Cumulative Ack event, SeqNo = 4248635853, BytesAcked = 0, CWnd = 29200, SndWnd = 65535, InRecovery = 0, TimeSinceLastLossMS = 0, CubicCwnd = 0, AimdCwnd = 0, K = 0, Wmax = 0, LastWmax = 0, MaxSndWnd = 65535 IsLimitedSlowStart = 0.

// BBR2 (1583)
  conn new-after-bbr2 port 55034 tcb 0xFFFFE3883D4C1550 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/BBR2
    module events : 1583 BBR2=88 | acks 1330=1441 sends 1332=92 paced 1447=53
    sample before BBR2: BBR2: TCB 0xffffe3883d4c1550 bbr_bw 121106 min_rtt_us 151 mode 0 cycle_idx 0 CWnd 64240 PacingRate 342607 BytesSent 1132 SRtt 403

// DCTCP (1225)
  conn new-after-dctcp port 55036 tcb 0xFFFFE3883DAE07A0 first ids 1002,1003,1004,1332,1551,1626 | 1223 committed TcpTemplateTypeInternet/DCTCP
    module events : 1225 EcnAlpha=47 | acks 1330=1440 sends 1332=87 paced 1447=0
    sample before EcnAlpha: TCP: connection 0xffffe3883dae07a0: End of a round, SndRound = 45096, Bytes sent = 46556. Bytes marked = 0, ThAck = 3592477059, updated EcnAlpha = 0.
```

### W10 22H2 Records

```c
// default (1429)
  conn default port 49950 tcb 0xFFFFAF0FC3A4CA20 first ids 1002,1003,1004,1332,1161,1167 | 1223 committed TcpTemplateTypeInternet/CUBIC
    module events : 1429 CUBIC=35 1475 CUBIC=1 | acks 1330=1441 sends 1332=160 paced 1447=0
    sample before CUBIC: TCP: connection 0xffffaf0fc3a4ca20: Cumulative Ack event, SeqNo = 3095657116, BytesAcked = 0, CWnd = 29200, SndWnd = 65535, InRecovery = 0, TimeSinceLastLossMS = 0, CubicCwnd = 0, AimdCwnd = 0, K = 0, Wmax = 0, LastWmax = 0, MaxSndWnd = 65535 IsLimitedSlowStart = 0.

// SIO_PRIORITY_HINT VeryLow (1380)
  conn ledbat-hint port 49952 tcb 0xFFFFAF0FC3F7D9A0 first ids 1002,1003,1004,1332,1161,1167 | 1223 committed TcpTemplateTypeInternet/LEDBAT
    module events : 1380 LEDBAT=1441 | acks 1330=1440 sends 1332=183 paced 1447=0
    sample before LEDBAT: TCP: LEDBAT Ack: Connection 0xffffaf0fc3f7d9a0, BaseDelayMs = 1, CurrentDelayMs = 1, CWnd = 3739, SsThresh = 4294967295, SndWnd = 65535, DelayBasedCwndFactor 100%%, RemainingTimeMs = 0.

// NewReno (own module)
  conn new-after-newreno port 49957 tcb 0xFFFFAF0FC3F7D9A0 first ids 1002,1003,1004,1332,1161,1167 | 1223 committed TcpTemplateTypeInternet/NewReno
    module events : none | acks 1330=1441 sends 1332=173 paced 1447=0

// CTCP (1162 & 1331)
  conn new-after-ctcp port 49960 tcb 0xFFFFAF0FC3F7D9A0 first ids 1002,1003,1004,1332,1161,1167 | 1223 committed TcpTemplateTypeInternet/CTCP
    module events : 1162 CTCP=162 1331 CTCP=1441 | acks 1330=1441 sends 1332=165 paced 1447=0
    sample before CTCP: TCP: connection 0xffffaf0fc3f7d9a0: CTCP Cumulative Ack event, SeqNo = 2420567891, BytesAcked = 1460, CWnd = 27740, SndWnd =65535.

// DCTCP (1225)
  conn new-after-dctcp port 49962 tcb 0xFFFFAF0FC3A4CA20 first ids 1002,1003,1004,1332,1161,1167 | 1223 committed TcpTemplateTypeInternet/DCTCP
    module events : 1225 EcnAlpha=38 | acks 1330=1441 sends 1332=160 paced 1447=0
    sample before EcnAlpha: TCP: connection 0xffffaf0fc3a4ca20: End of a round, SndRound = 55480, Bytes sent = 56940. Bytes marked = 0, ThAck = 1883735025, updated EcnAlpha = 0.
```


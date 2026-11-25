# Congestion Provider

See [TCP Congestion Control, RFC 5681](https://datatracker.ietf.org/doc/rfc5681/) for other details.

WinConfig applies it via the NSI store ([`NsiSetAllParameters`](https://ntdoc.m417z.com/nsisetallparameters), [`NsiSetAllPersistentParametersWithMask`](https://ntdoc.m417z.com/nsisetallpersistentparameterswithmask)):

```c
/**
 * The NsiSetAllParameters routine creates, updates, deletes or flushes an NSI object instance by writing its whole read-write
 * row. This is how iphlpapi implements CreateIpForwardEntry2/DeleteIpForwardEntry2, CreateIpNetEntry/DeleteIpNetEntry,
 * AddIPAddress/DeleteIPAddress, SetIpInterfaceEntry, FlushIpNetTable and SetTcpEntry (closing a TCP connection).
 *
 * \param[in] Store The NSI store to update (NsiPersistent, NsiActive or NsiBoth).
 * \param[in] Action The set action (NSI_SET_ACTION): NsiSetDefault to update an existing instance, NsiSetCreateOnly,
 *        NsiSetCreateOrSet, NsiSetDelete, NsiSetReset (flush), NsiSetClear, or the reference-counted
 *        NsiSetCreateOrSetWithReference/NsiSetDeleteWithReference (used by EnableRouter/UnenableRouter).
 * \param[in] ModuleId A pointer to the NPI module identifier.
 * \param[in] ObjectId The identifier of the NSI object.
 * \param[in] Key Optional pointer to the key identifying the object instance (e.g. The interface LUID, or LUID + address).
 * \param[in] KeySize The size of the key in bytes.
 * \param[in] ReadWriteBuffer Optional read-write row to write. Usually NULL for NsiSetDelete and NsiSetReset.
 * \param[in] ReadWriteBufferSize The size of ReadWriteBuffer in bytes.
 * \return A Win32 error code. ERROR_SUCCESS on success.
 * \remarks Uses IOCTL 0x120013 with a 0x48-byte request. For example,
 *          InternalSetIpInterfaceEntry: NsiSetAllParameters(NsiActive, NsiSetDefault, ModuleId, 7, &Luid, 8, &RwRow, 240).
 */
NTSYSAPI
ULONG
NTAPI
NsiSetAllParameters(
    _In_ NSI_STORE Store,
    _In_ NSI_SET_ACTION Action,
    _In_ PNPI_MODULEID ModuleId,
    _In_ NSI_OBJECT_ID ObjectId,
    _In_reads_bytes_opt_(KeySize) PVOID Key,
    _In_ ULONG KeySize,
    _In_reads_bytes_opt_(ReadWriteBufferSize) PVOID ReadWriteBuffer,
    _In_ ULONG ReadWriteBufferSize
    );
```
```c
/**
 * The NsiSetAllPersistentParametersWithMask routine writes the persisted (registry-backed) configuration of one NSI object
 * instance, merging only the fields selected by the mask, e.g. SetIpInterfaceEntry persisting changed interface settings.
 *
 * \param[in] Action The set action (NSI_SET_ACTION): NsiSetDefault to update an existing instance, NsiSetCreateOnly,
 *        NsiSetCreateOrSet, NsiSetDelete, NsiSetReset (flush), NsiSetClear, or the reference-counted
 *        NsiSetCreateOrSetWithReference/NsiSetDeleteWithReference (used by EnableRouter/UnenableRouter).
 *        netio.sys validates the value (NsiSetReset and NsiSetClear are handled specially); iphlpapi passes NsiSetCreateOrSet.
 * \param[in] ModuleId A pointer to the NPI module identifier.
 * \param[in] ObjectId The identifier of the NSI object.
 * \param[in] Key A pointer to the key identifying the object instance.
 * \param[in] KeySize The size of the key in bytes.
 * \param[in] ParameterData Optional buffer containing the row to persist.
 * \param[in] ParameterMask Optional field mask (same size as ParameterData; 0xFF bytes select the fields to persist).
 * \param[in] ParameterDataSize The size of ParameterData and of ParameterMask in bytes.
 * \return A Win32 error code. ERROR_SUCCESS on success.
 */
NTSYSAPI
ULONG
NTAPI
NsiSetAllPersistentParametersWithMask(
    _In_ NSI_SET_ACTION Action,
    _In_ PNPI_MODULEID ModuleId,
    _In_ NSI_OBJECT_ID ObjectId,
    _In_reads_bytes_(KeySize) PVOID Key,
    _In_ ULONG KeySize,
    _In_reads_bytes_opt_(ParameterDataSize) PVOID ParameterData,
    _In_reads_bytes_opt_(ParameterDataSize) PVOID ParameterMask,
    _In_ ULONG ParameterDataSize
    );
```

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

## BBR2 & Loopback Large MTU

These are some first notes on the topic and may not be complete yet.

If using BBR2 while having loopback large MTU enabled, TCP over `127.0.0.1` basically stalls, which is why apps like Steam show "no connection", records:

| Provider | Loopback large MTU | 256 MB | 200 round trips |
|---|---|---|---|
| CUBIC | enabled | 126 ms | 52 ms |
| BBR2 | enabled | 22186 ms | 3017 ms |
| BBR2 | disabled | 1177 ms | 41 ms |
| CUBIC | disabled | 503 ms | 35 ms |

Loopback large MTU increases the loopback MSS from `1460` to `65495` bytes, BBR2 paces its sends, it calcs the pacing rate in bytes per second as a 64 bit value and stores it as bytes per ms, but the division by 1000 only takes the low 32 bits (`mul ebx`), so a rate above `4,294,967,295` bytes/s (4.29 GB/s) causes a wrap:

```c
// bbr_set_pacing_rate (23H2 tcpip.sys)

__int64 __fastcall bbr_set_pacing_rate(unsigned int *a1, unsigned int a2, int a3) // a2 = bandwidth, a3 = gain
{
  unsigned int *v3; // r11
  unsigned __int64 v4; // rbx
  __int64 result; // rax

  v3 = a1;
  v4 = (980000 * ((a3 * a2 * (unsigned __int64)a1[42]) >> 8)) >> 24; // a1[42] = MSS, v4 = bytes/s (64 bit)
  if ( v4 <= 1 )
    LODWORD(v4) = 1;
  if ( (a1[62] & 0x4000000) == 0 && a1[180] )
    bbr_init_pacing_rate_from_rtt(a1); // first rate from cwnd / RTT
  if ( (v3[63] & 0x400000) != 0 || (result = (unsigned int)(274877907 * v4), (unsigned int)v4 / 0x3E8 > v3[128]) )
  {
    result = (unsigned int)(274877907 * v4);
    v3[128] = (unsigned int)v4 / 0x3E8; // low 32 bits / 1000 = pacing rate in bytes per ms
  }
  return result;
}
```

With a `65495` byte MSS and loopback RTTs ~50 µs, BBR2s rates are way above that limit.

```c
// TcpPaceSend (23H2 tcpip.sys)

  v12 = *(unsigned int *)(a1 + 512); // pacing rate, bytes per ms
  if ( *(int *)(a1 + 116) >= 0 )
  {
    v17 = 16 * v12;
    LOBYTE(v14) = v17;
    v15 = v17;
  }
  else
  {
    v13 = v12 * (unsigned int)(MicrosecondCount - *(_DWORD *)(a1 + 516)); // rate * µs since last send
    MicrosecondCount = *(_DWORD *)(a1 + 816);
    v14 = v13 / 0x3E8;
    v15 = v14;
    if ( (MicrosecondCount & 0x20) == 0 )
    {
      v16 = 5000;
      if ( *(_DWORD *)(a1 + 168) < 0x1388u ) // MSS
        v16 = *(_DWORD *)(a1 + 168);
      LOBYTE(MicrosecondCount) = 4 * v16;
      if ( (unsigned int)v14 < 4 * v16 && (unsigned int)v14 < *v6 )
        v15 = 0;
    }
  }
  v18 = *v6;
  if ( *v6 > v15 )
  {

    *v6 = v15; // send only the budget
    if ( !*(_DWORD *)(a1 + 1208) )
      LOBYTE(MicrosecondCount) = TcpStartTimerTcbAndTraceInternal(a1, 5, 16, a5, a6, 5); // rest after 16 ms
  }
```

`Microsoft-Windows-TCPIP` event 1583 (`Bbr2OnSend`) shows the wrapped values (`bbr_bw` is in bytes per ms):

```c
// loopback large MTU enabled, MSS 65495
SRtt=50 CWnd=654950 PacingRate=2697125
bbr_bw=3852650 mode=2 PacingRate=424529
PacingRate 2697125, 2765446, 4127050, 3565840, 162333

// loopback large MTU disabled, MSS 1460
SRtt=47 CWnd=14600 PacingRate=878790
bbr_bw up to 663636, PacingRate 400988 to 1397953
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


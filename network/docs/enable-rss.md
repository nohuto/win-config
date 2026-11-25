# Enable RSS

> "*[Receive-Side Scaling (RSS)](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/introduction-to-receive-side-scaling), also known as multi-queue receive, distributes network receive processing across several hardware-based receive queues, allowing inbound network traffic to be processed by multiple CPUs. RSS can be used to relieve bottlenecks in receive interrupt processing caused by overloading a single CPU, and to reduce network latency.*"
>
> — Red Hat Documentation, [Receive-Side Scaling](https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/6/html/performance_tuning_guide/network-rss)


Note that RSS is enabled by default.

## Registry Values

`*MaxRssProcessors`:  
The maximum number of RSS processors.

[`*NumRssQueues`](https://www.intel.com/content/www/us/en/support/articles/000005593/ethernet-products.html):  
The maximum number of the RSS queues that the device should use.

Configures the number of RSS queues:  
- One queue is used when low CPU utilization is required.
- Two queues are used when good throughput and low CPU utilization are required.
- Four or more queues are used for applications that demand high transaction rates such as web server based applications. With this setting, the CPU utilization may be higher.

(Not all adapters support all RSS queue settings. RSS is not supported on some adapters configured to use Virtual Machine Queues (VMQ). For these adapters VMQ takes precedence over RSS. RSS is disabled.)

`*RssBaseProcGroup`:  
Sets the RSS base processor group for systems with more than 64 processors.

`*RssBaseProcNumber`:  
Sets the desired base CPU number for each interface. The number can be different for each interface. This allows partitioning of CPUs across network adapters.

You might want to set it to a different core than 0 default / 1, e.g. core 2/3.

`*RssMaxProcGroup`:  
The maximum processor group of the RSS interface.

`*RssMaxProcNumber`:  
The maximum processor number of the RSS interface. If `*RssMaxProcNumber` is specified, then `*RssMaxProcGroup` should also be specified.

```json
{ "*NumRssQueues", "2" },
{ "*RssBaseProcNumber", "2" },
{ "*RssMaxProcNumber", "3" },
```

`*RssProfile`:  
|SubkeyName|ParamDesc|Value|EnumDesc|
|--- |--- |--- |--- |
|**\*RSSProfile**|RSS load balancing profile|1|**ClosestProcessor**: Default behavior is consistent with that of Windows Server 2008 R2.|
|||2|**ClosestProcessorStatic**: No dynamic load-balancing - Distribute but don't load-balance at runtime.|
|||3|**NUMAScaling**: Assign RSS CPUs in a round robin basis across every NUMA node to enable applications that are running on NUMA servers to scale well.|
|||4 (Default)|**NUMAScalingStatic**: RSS processor selection is the same as for NUMA scalability without dynamic load-balancing.|
|||5|**ConservativeScaling**: RSS uses as few processors as possible to sustain the load. This option helps reduce the number of interrupts.|
|||6 (Default on heterogeneous CPU systems)|**NdisRssProfileBalanced**: RSS processor selection is based on traffic workload. Only available in [NetAdapterCx](https://learn.microsoft.com/en-us/windows-hardware/drivers/netcx/netadaptercx-receive-side-scaling-rss-), starting in WDK preview version 25197.|

`RssV2`:  
Enables the RSS v2 feature which improves the Receive Side Scaling by offering dynamic, per-VPort spreading of queues. It reduces the time to update the indirection table. Note: RSSv2 is only supported by NDIS 6.80 and later versions.

`ValidateRssV2`:  
Enables strict argument validation for upper layer testing, only `mlx5.sys` reads it (range 0-1, default `0`), it's a test switch.

---

```
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *MaxRssProcessors
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *NumRssQueues
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *Rss
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssBaseProcGroup
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssBaseProcNumber
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssMaxProcGroup
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssMaxProcNumber
\Registry\Machine\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\00XX : *RssProfile
\Registry\Machine\SYSTEM\ControlSet001\Services\HTTP\Parameters : RssStatusCheckControl
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : MaxNumRssCpus
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\Parameters : RssBaseCpu
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : MaxNumRssCpus
\Registry\Machine\SYSTEM\ControlSet001\Services\NDIS\SharedState : RssBaseCpu
```

### RssReadRegistryParameters

[`RSS::RssReadRegistryParameters`](https://github.com/nohuto/win-config/blob/main/network/assets/pseudocode/intel-nic/RSS_RssReadRegistryParameters.c) shows miscellaneous values which are related to RSS, see [intelnet6x.c](https://github.com/nohuto/win-config/blob/main/power/assets/pseudocode/intelnet6x.c) for reference:
```c
void __fastcall RSS::RssReadRegistryParameters(RSS *this, struct ADAPTER_CONTEXT *a2, void *a3)
{
  v5 = L"*RSS";
  v13 = L"*RssBaseProcNumber";
  v21 = L"*MaxRssProcessors";
  v29 = L"*NumaNodeId";
  v37 = L"DisablePortScaling";
  v45 = L"ManyCoreScaling";
  v52 = L"*NumRssQueues";
  v60 = L"NumRssQueuesPerVPort";
  v69 = L"EnableLHRssWA";
  v77 = L"ReceiveScalingMode";
  REGISTRY::RegReadRegTable(v3, a2, a3, (struct REGTABLE_ENTRY *)&v4, 0xAu);
}
```

### ndisReadRssKeywords

Some miscellanous notes for now.

NDIS reads the profile & processor keywords itself when the adapter starts ([`ndisReadRssKeywords`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ndis/-ndisReadRssKeywords@@YAXPEAU_NDIS_MINIPORT_BLOCK@@@Z.c)), on 24H2+ the default profile is `6` (Balanced) on CPUs with P & E cores, and *Balanced* ignores the base/max processor keywords.

```c
// ndisReadRssKeywords (25H2)

v4 = NdisRssProfileNumaStatic;
*((_DWORD *)&ConfigObject.Header + 1) = 0;
if ( ndisHeterogeneousCpuSystem )
  v4 = NdisRssProfileBalanced; // default 6 on P/E core CPUs

NdisReadConfiguration(&Status, &ParameterValue, v6, &MaxRssProcStr, NdisParameterInteger); // *MaxRssProcessors
if ( !Status )
  a1->MaxNumRssProcessors = ParameterValue->ParameterData.IntegerData;
NdisReadConfiguration(&Status, &ParameterValue, v6, &RssProfileStr, NdisParameterInteger); // *RSSProfile
if ( !Status )
{
  IntegerData = ParameterValue->ParameterData.IntegerData;
  if ( IntegerData )
  {
    if ( IntegerData < 7 )
      v4 = ParameterValue->ParameterData.IntegerData;
  }
}
if ( v4 == NdisRssProfileBalanced ) // base/max processor keywords arent read
```

```c
// ndisGetProcessorInfo (25H2)

v11 = ndisRssBaseCpu; // RssBaseCpu
v12 = 0LL;
while ( v11 < ndisNumberOfActiveProcessorsAtBoot && (unsigned int)v12 < ndisMaxNumRssCpus )
{
  for ( i = 0LL; (unsigned int)i < (unsigned int)v12; i = (unsigned int)(i + 1) )
  {
    ProcessorIndexFromNumber = KeGetProcessorIndexFromNumber((PPROCESSOR_NUMBER)ndisRssProcessors + i);
    if ( ndisCpuInfo[ProcessorIndexFromNumber].SocketId == ndisCpuInfo[v11].SocketId
      && ndisCpuInfo[ProcessorIndexFromNumber].CoreId == ndisCpuInfo[v11].CoreId )
    {
      break; // core already listed
    }
  }
```

```c
// ndisReadRssKeywords (25H2)

KeGetProcessorNumberFromIndex(ndisRssBaseCpu, &ProcNumber);
```

```c
// ndisReadRssKeywords (25H2)

if ( (int)ndisCompareProcNum(ProcNumber, v5) > 0 )
  v5 = ProcNumber; // base is never below RssBaseCpu
```

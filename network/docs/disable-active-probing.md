# Disable Active Probing

### Active Probing

Active probing sends HTTP requests from the client to a predefined web probe server (by default `www.msftconnecttest.com/connecttest.txt`), using both IPv4 and IPv6 in parallel. If it gets an HTTP 200 response with the expected payload, NCSI marks the interface as having internet connectivity, if the probe fails or returns errors (for example, blocked by a proxy or DNS issues), NCSI treats connectivity as limited. See [NCSI FAQs](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-frequently-asked-questions) for more information.

### NCSI Evaluation

Currently works via `DisableNCSIConnectivityEvaluation` (missing by default), `ncsi.dll` then queues no active probe and turns passive polling off, seems to only exist on 24H2+.

```c
// ActiveProbeManager::TryNcsiQueueActiveInternetProbe (25H2)

  if ( NcsiConfigData::IsDisableNCSIConnectivityEvaluationSet(v7, v6, v8) )
  {
```

```c
// NcsiConfigData::InternalQueryGPParamRegistry (25H2)

  if ( HIDWORD(qword_18009CA9C)
    || (IsDisableNCSIConnectivityEvaluationSet = NcsiConfigData::IsDisableNCSIConnectivityEvaluationSet(v4),
        v8 = 1,
        IsDisableNCSIConnectivityEvaluationSet) )
  {
    v8 = 0;
  }
  Ncsi::PassivePoll::PassivePollManager::EnablePolling(v8); // off when the policy/value is set
```

NCSI then doesn't check the connection at all, Windows may still show a cache probe (saved in `HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Cache`)

```c
// NlaSvc\Parameters\Cache example, gateway MAC 52-54-00-12-35-00
"OpportunisticInternetGatewaysV4" = 065254001235000000965F0200; // REG_BINARY
```

```c
// NCSI_INTERFACE_ATTRIBUTES::SetReadyTimestamp (25H2)

if ( (unsigned __int8)IsMacKnownToBeOppInternet((char *)&a1[v5 + 548] + 4, v30, (unsigned int)v3) ) // gateway MAC is in cache
  NCSI_INTERFACE_ATTRIBUTES::SetOppInternetFlag(a1, v3);
```

```c
// NcsiAllocateAndGetConnectivityStatusSet (25H2)

v18[20] = v22; // IPv4 capability from probes/passive polling
if ( v19[4355] ) // set by SetOppInternetFlag
{
  if ( (unsigned __int8)NCSI_INTERFACE_ATTRIBUTES::IsStackReady((char *)v12 + 12896 * v17, 0LL) ) // IP address present (SetIpAddressExistence)
    break;
}

  v18[22] = 256;
LABEL_125:
  v18[20] = 2; // Internet
  goto LABEL_32;
```

### Custom WebProbeHost

Keeps active probing on but sends the web probe to my server instead of Microsofts (`http://ncsi.noverse.dev/ncsi.txt`, which answers `connect test`, for IPv4 & IPv6). This is obviously only used whenever active probing is on.

#### ncsi.noverse.dev

If you don't use WinConfig, you can use my probe server via:

```bat
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeHost /t REG_SZ /d "ncsi.noverse.dev" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbePath /t REG_SZ /d "ncsi.txt" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeContent /t REG_SZ /d "connect test" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeHostV6 /t REG_SZ /d "ncsi.noverse.dev" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbePathV6 /t REG_SZ /d "ncsi.txt" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeContentV6 /t REG_SZ /d "connect test" /f
```

#### msftconnecttest.com

Windows defaults:

```bat
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeHost /t REG_SZ /d "www.msftconnecttest.com" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbePath /t REG_SZ /d "connecttest.txt" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeContent /t REG_SZ /d "Microsoft Connect Test" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeHostV6 /t REG_SZ /d "ipv6.msftconnecttest.com" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbePathV6 /t REG_SZ /d "connecttest.txt" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet" /v ActiveWebProbeContentV6 /t REG_SZ /d "Microsoft Connect Test" /f
```

### Passive Probing

> "*Similar to active probing, passive probing uses learned information from received packets to determine network status. Both probing methods complement one another as they determine intermittent network conditions differently. Certain conditions prevent active probes from functioning correctly, such as, a temporary router having intermittent connectivity issue where a client device doesn't experience any change in the interface state. If intermittent connectivity issues cause active probing to have false negative results, passive polling can determine the connectivity status based on network traffic. This helps maintain accurate internet connectivity status.*
>
> *The main goal of the passive probe is to update NCSI’s connectivity status for all active network interfaces based on packet data received. For each active interface, the probe can update the status to either internet or local by constantly inspecting inbound packets for the number of hops traversed from the sender.*"
>
> — Microsoft, [NCSI Overview: Passive probing](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview#passive-probing)

With active probing off, NCSI relies on passive polling, [MS warns](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview) that passive polling itself can't notics every connectivity problem.


`ncsi.dll` reads the pref value first, then the policy one:

```c
// ActiveProbeManager::TryNcsiQueueActiveInternetProbe (23H2)

if ( g_ncsiConfigData ) // EnableActiveProbing
{
  if ( _InterlockedCompareExchange((volatile signed __int32 *)&dword_18009514C, 0, 0) ) // NoActiveProbe
  {
      v42 = (ActiveProbeManager::ActiveProbeStage *)"Disabled by Group Policy";

    v29[0] = "Disabled by registry"; // EnableActiveProbing = 0
```

### NCSI Values

Additional notes for now, `ncsi.dll` reads these from `HKLM\SYSTEM\CurrentControlSet\Services\NlaSvc\Parameters\Internet` (`NcsiConfigData::InternalQueryRegParamRegistry`).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\NlaSvc\\Parameters\\Internet";
    "EnableActiveProbing" = 0; // REG_DWORD, 25H2 sets it to 1
    "PassivePollPeriod" = 15; // REG_DWORD, passive poll period in sec
    "MinimumInternetHopCount" = 8; // REG_DWORD, passive hop count needed for "internet"
    "DisablePassivePollActiveSessionRequirement" = 0; // REG_DWORD
    "StaleThreshold" = 30; // REG_DWORD
    "WebTimeout" = 35; // REG_DWORD, web probe timeout (c_regValueHttpTimeout)
    "MaxActiveProbes" = 0; // REG_DWORD
    "ReprobeThreshold" = 10000; // REG_DWORD
    "UserActiveProbing" = 0; // REG_DWORD
    "CaptivePortalTimer" = 0; // REG_DWORD
    "CaptivePortalTimerBackOffIncrementsInSeconds" = 5; // REG_DWORD
    "CaptivePortalTimerMaxInSeconds" = 30; // REG_DWORD
    "CorpLocationProbeTimeout" = 35; // REG_DWORD
    "CorpLocationInitialRetryBackoff" = 1; // REG_DWORD
    "CorpLocationRetryBackoffCap" = 1024; // REG_DWORD
    "DisableRetryFallbackUrl" = 0; // REG_DWORD
    "DisableNCSIConnectivityEvaluation" = 0; // REG_DWORD, see above
    "TestMode" = 0; // REG_DWORD

// LoadCacheStateFromKey, gateway caches (see NCSI Evaluation)
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\NlaSvc\\Parameters\\Cache";
    "DisableOppInetCache" = 0; // REG_DWORD, 1 = dont the internet gateway cache
    "DisableProxyOppInetCache" = 0; // REG_DWORD, 1 = dont use proxied internet gateway cache
    "DisableHotspotCache" = 0; // REG_DWORD, 1 = dont use hotspot gateway cache
    "OpportunisticInternetGatewaysV4" = ?; // REG_BINARY, gateways confirmed by a probe
    "OpportunisticInternetGatewaysV6" = ?; // REG_BINARY
    "ProxiedOpportunisticInternetGatewaysV4" = ?; // REG_BINARY
    "ProxiedOpportunisticInternetGatewaysV6" = ?; // REG_BINARY
    "KnownHotspotGatewaysV4" = ?; // REG_BINARY
    "KnownHotspotGatewaysV6" = ?; // REG_BINARY
```

## [Network Icon Meaning](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview)

|Icon|Description|
|--|--|
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wired.jpg?raw=true)| Connected (Wired) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wireless.jpg?raw=true)| Connected (Wireless) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-no-internet.jpg?raw=true)| Connected (No internet) |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Network Connectivity Status Indicator active tests](https://noverse.dev/policies?p=ICM*NoActiveProbe) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `NoActiveProbe` |
| [Specify passive polling](https://noverse.dev/policies?p=NCSI*NCSI_PassivePolling) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `DisablePassivePolling` |


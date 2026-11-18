# Disable Active Probing

### Active Probing

Active probing sends HTTP requests from the client to a predefined web probe server (by default `www.msftconnecttest.com/connecttest.txt`), using both IPv4 and IPv6 in parallel. If it gets an HTTP 200 response with the expected payload, NCSI marks the interface as having internet connectivity, if the probe fails or returns errors (for example, blocked by a proxy or DNS issues), NCSI treats connectivity as limited. See [NCSI FAQs](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-frequently-asked-questions) for more information.

### Passive Probing

Passive probing doesn't send its own traffic, it inspects received packets and uses their hop count to infer connectivity. If the measured hop count for an interface meets or exceeds a system minimum (default 8, often changed to 3 in enterprises), NCSI upgrades the interface to "internet" and suppresses further active probes until conditions change, if the hop count is too low, missing, or there's no route to the internet, and no successful active probe has occurred, connectivity is treated as local-only. Passive probes run periodically (every 15 seconds by default) when allowed by Group Policy and when a user has recently logged on, and they serve to keep connectivity status accurate, especially with intermittent network issues.

Disabling passive probing will break the network icon, causing for example spotify to be in offline mode.

See links below for a detailed documentation.

## [Network Icon Meaning](https://learn.microsoft.com/en-us/windows-server/networking/ncsi/ncsi-overview)

|Icon|Description|
|--|--|
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wired.jpg?raw=true)| Connected (Wired) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-wireless.jpg?raw=true)| Connected (Wireless) |
|![](https://github.com/MicrosoftDocs/windowsserverdocs/blob/main/WindowsServerDocs/networking/media/ncsi/ncsi-overview/ncsi-icon-connected-no-internet.jpg?raw=true)| Connected (No internet) |

`PassivePollPeriod` is set to `15` by default = Runs passive probe every 15 seconds. `MaxActiveProbes` to `0` (unlimited) = breaks connection status. If disabling active probes, but leaving passive probes enabled, enable `Enable Passive Mode`.

- [network/assets/pseudocode | probing-NcsiConfigData.c](https://github.com/nohuto/win-config/blob/main/network/assets/pseudocode/probing-NcsiConfigData.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Network Connectivity Status Indicator active tests](https://noverse.dev/policies?p=ICM*NoActiveProbe) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `NoActiveProbe` |
| [DirectAccess Passive Mode](https://noverse.dev/policies?p=nca*PassiveMode) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\NetworkConnectivityAssistant` | `PassiveMode` |
| [Specify passive polling](https://noverse.dev/policies?p=NCSI*NCSI_PassivePolling) | `HKLM\Software\Policies\Microsoft\Windows\NetworkConnectivityStatusIndicator` | `DisablePassivePolling` |


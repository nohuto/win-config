# Disable VPNs

Get current VPN connections:

```powershell
Get-VpnConnection
```

Remove a VPN connection with (or `Remove-VpnConnection`):

```bat
rasphone -r "Name"
```
or `WIN + I` > Network & Internet > VPN > Remove

### Allow VPN over metered networks

```c
OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1 = 
    L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\Parameters\\Config\\VpnCostedNetworkSettings",

VpnRegQueryDWord(
    v13,
    OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1,
    L"NoCostedNetwork",
    &g_donotUseCosted,
    v17),

if ( !v17[0] )
    g_donotUseCosted = 0, // default
```

### Allow VPN while Roaming

```c
OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters = 
    L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\Parameters\\Config\\VpnCostedNetworkSettings",

VpnRegQueryDWord(
    v15,
    OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters,
    L"NoRoamingNetwork",
    &g_donotUseRoaming,
    v17),

if ( !v17[0] )
    g_donotUseRoaming = 0, // default
```

- [network/assets/pseudocode | vpn-NlmGetCostedNetworkSettings.c](https://github.com/nohuto/win-config/blob/main/network/assets/pseudocode/vpn-NlmGetCostedNetworkSettings.c)


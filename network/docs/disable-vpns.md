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

## Registry Values

`rasmans.dll` reads both in `int_NlmGetCostedNetworkSettings`:

```c
// int_NlmGetCostedNetworkSettings (23H2)

      OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1 = L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\"
                                                                           "Parameters\\Config\\VpnCostedNetworkSettings";
      IsPolicySetByMobileDeviceManager = VpnRegQueryDWord(
                                           v13,
                                           OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters_1,
                                           L"NoCostedNetwork",
                                           &g_donotUseCosted,
                                           v17);

      if ( !v17[0] ) // value missing
        g_donotUseCosted = 0; // VPN over metered networks allowed

      OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters = L"SYSTEM\\CurrentControlSet\\Services\\RasMan\\P"
                                                                         "arameters\\Config\\VpnCostedNetworkSettings";
      IsPolicySetByMobileDeviceManager = VpnRegQueryDWord(
                                           v15,
                                           OSDATA__SYSTEM__CurrentControlSet__Services__RasMan__Parameters,
                                           L"NoRoamingNetwork",
                                           &g_donotUseRoaming,
                                           v17);

      if ( !v17[0] ) // value missing
        g_donotUseRoaming = 0; // VPN while roaming allowed
```


## Services/Drivers

| Name | Default Start | Description |
| --- | --- | --- |
| `RasMan` | `3` | Manages dial-up and virtual private network (VPN) connections from this computer to the Internet or other remote networks. If this service is disabled, any services that explicitly depend on it will fail to start. |
| `SstpSvc` | `3` | Provides support for the Secure Socket Tunneling Protocol (SSTP) to connect to remote computers using VPN. If this service is disabled, users will not be able to use SSTP to access remote servers. |

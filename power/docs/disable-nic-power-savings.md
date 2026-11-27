# Disable NIC Power Savings

You can get a lot of information about data ranges and more from `.inf` files, see examples below.

## [Registry Value](https://github.com/nohuto/regkit/blob/main/assets/records/NIC-Intel.txt) Overview

Intel drivers read most of them in `POWER::PwrReadRegistryParameters`, `LINK::LinkReadRegistryParameters` (`e1i68x64.sys`) and in `Power::ReadRegistryParameters` (`e2f68.sys`).

Everything listed below is based on personal findings, mistakes may exist.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
    // ndis.sys & standardized keywords
    "PnPCapabilities" = ?; // REG_DWORD, 0x8 = no power management, 0x10 = no wake
    "*DeviceSleepOnDisconnect" = 0; // bool
    "*EEE" = ?;
    "*IdleRestriction" = 0;
    "*ModernStandbyWoLMagicPacket" = ?;
    "*NicAutoPowerSaver" = ?;
    "*SelectiveSuspend" = ?;
    "*SSIdleTimeout" = ?; // seconds (no effect while *SelectiveSuspend is 0)
    "*SSIdleTimeoutScreenOff" = ?; // seconds (no effect while *SelectiveSuspend is 0)
    "*EnableDynamicPowerGating" = 1; // bool

    // e1i68x64.sys, e2f68.sys
    "AutoPowerSaveModeEnabled" = 0;
    "EEELinkAdvertisement" = 1;
    "EnableAdvancedDynamicITR" = ?;
    "EnableD0PHYFlexibleSpeed" = ?;
    "EnableD3ColdInS0" = ?;
    "EnableDisconnectedStandby" = 0; // bool
    "EnableModernStandby" = 0; // bool
    "EnablePHYFlexibleSpeed" = ?;
    "EnablePHYWakeUp" = ?;
    "EnablePME" = 0; // bool
    "EnablePowerManagement" = 1; // bool
    "EnableSavePowerNow" = ?;
    "ForceHostExitUlp" = 0; // bool (1 = "Allow host driver to force exit ULP on ME systems")
    "I218DisablePLLShut" = 0; // bool
    "I218DisablePLLShutGiga" = 0; // bool
    "OBFFEnabled" = ?;
    "ReduceSpeedOnPowerDown" = 1;
    "SipsEnabled" = ?;
    "SleepWhileWaiting" = ?;
    "ULPMode" = 1; // bool

    // Intel values
    "DisableIntelRST" = 1; // bool
    "DMACoalescing" = 0; // bool0240
    "ForceLtrValue" = 65535; // range 0-65535
    "I219DisableK1Off" = 0; // bool

    // Realtek
    "AdvancedEEE" = ?;
    "ASPM" = ?; // RtAdapterCheckSetupAspmAndClkReq
    "EEEPlus" = ?;
    "EnableAspm" = ?;
    "EnableExtraPowerSaving" = ?; // USB drivers
    "EnableGreenEthernet" = 0;
    "GigaLite" = ?;
    "PowerDownPll" = 1;
    "PowerSavingMode" = ?;
    "WolShutdownLinkSpeed" = 0; // 0 = 10 Mbps first, 1 = 100 Mbps first, 2 = not speed down
```

`PnPCapabilities = 24` (no power management + no wake) is same as unchecking "Allow the computer to turn off this device to save power" in Device Manager.

```c
// ndisMInitializeAdapter (25H2)

PnPCapabilities = a2->PnPCapabilities;
if ( (PnPCapabilities & 8) == 0 ) // power management allowed
```

```c
// ndisUpdatePMCurrentCapabilities (25H2)

if ( (PnPCapabilities & 0x10) == 0 ) // wake allowed
```

| SubkeyName | ParamDesc | Default | Minimum | Maximum |
| --- | --- | --- | --- | --- |
| `*WakeOnPattern` | A value that describes whether the device should be enabled to wake the computer when a network packet matches a specified pattern. | 1 | 0 | 1 |
| `*WakeOnMagicPacket` | A value that describes whether the device should be enabled to wake the computer when the device receives a magic packet. A magic packet is a packet that contains 16 contiguous copies of the receiving network adapter's ethernet address. | 1 | 0 | 1 |
| `*EEE` | A value that describes whether the device should enable IEEE 802.3az energy-efficient ethernet. | 1 | 0 | 1 |
| `*IdleRestriction` | If a network device has both idle power down and wake on packet filter capabilities, this setting allows the user to decide when the device idle power down can happen. `1` = Only idle when user isn't present, `0` = No restriction | 0 | 0 | 1 |
| `*ModernStandbyWoLMagicPacket` | A value that describes whether the device should be enabled to wake the computer when the device receives a magic packet and the system is in the S0ix power state. This doesn't apply when the system is in the S4 power state. | 0 | 0 | 1 |
| `*DeviceSleepOnDisconnect` | A value that describes whether the device should be enabled to put the device into a low-power state (sleep state) when media is disconnected and return to a full-power state (wake state) when media is connected again. | 1 | 0 | 1 |
| [`*SelectiveSuspend`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/ndis-selective-suspend) | Selective suspend (0 disabled, 1 enabled) | 1 | 0 | 1 |
| [`*SSIdleTimeout`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend#ssidletimeout-inf-keyword) | This keyword specifies the idle time-out period in units of seconds. If NDIS does not detect any activity on the network adapter for a period that exceeds the *SSIdleTimeout value, NDIS starts a selective suspend operation by calling the miniport driver's MiniportIdleNotification handler function. | 5 | 1 | 60 |
| [`*SSIdleTimeoutScreenOff`](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend#ssidletimeoutscreenoff-inf-keyword) | This keyword specifies the idle time-out period in units of seconds and is only applicable when the screen is off. If NDIS does not detect any activity on the network adapter for a period that exceeds the *SSIdleTimeoutScreenOff value after the screen is off, NDIS starts a selective suspend operation by calling the miniport driver's MiniportIdleNotification handler function. | 3 | 1 | 60 |

- [network/standardized-inf-keywords-for-power-management](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-power-management)
- [network/standardized-inf-keywords-for-ndis-selective-suspend](https://learn.microsoft.com/en-us/windows-hardware/drivers/network/standardized-inf-keywords-for-ndis-selective-suspend)

### Setup Information

```powershell
HKR,Ndi\Params\*DeviceSleepOnDisconnect,ParamDesc,    ,%DeviceSleepOnDisconnectDesc%
HKR,Ndi\Params\*DeviceSleepOnDisconnect,type,         ,enum
HKR,Ndi\Params\*DeviceSleepOnDisconnect,default,      ,0
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,0,       ,%Disabled%
HKR,Ndi\Params\*DeviceSleepOnDisconnect\enum,1,       ,%Enabled%

HKR, Ndi\Params\*EEE,    	                ParamDesc,      0,       %EEE%
HKR, Ndi\Params\*EEE,    	                Type,           0,       "enum"
HKR, Ndi\Params\*EEE\enum, 	                "1",            0,       %Enabled%
HKR, Ndi\Params\*EEE\enum, 	                "0",            0,       %Disabled%
HKR, Ndi\Params\*EEE,    	                Default,        0,       "0"

HKR,Ndi\params\*SelectiveSuspend,	    ParamDesc,  0, %SelectiveSuspend%
HKR,Ndi\params\*SelectiveSuspend,	    default,    0, "1"
HKR,Ndi\params\*SelectiveSuspend,	    type,       0, "enum"
HKR,Ndi\params\*SelectiveSuspend\enum,   "0",        0, "Disabled"
HKR,Ndi\params\*SelectiveSuspend\enum,   "1",        0, "Enabled"

HKR,Ndi\Params\*SSIdleTimeout,      ParamDesc,  0, "SSIdleTimeout"
HKR,Ndi\Params\*SSIdleTimeout,      Type,       0, "int"
HKR,Ndi\Params\*SSIdleTimeout,      Default,    0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Min,        0, "1" ; might also be at 5
HKR,Ndi\Params\*SSIdleTimeout,      Max,        0, "60"
HKR,Ndi\Params\*SSIdleTimeout,      Step,       0, "1"
HKR,Ndi\Params\*SSIdleTimeout,      Base,       0, "10"

HKR, Ndi\params\AdvancedEEE,        ParamDesc,  0, %AdvancedEEE%
HKR, Ndi\params\AdvancedEEE,        optional,   0, "1"
HKR, Ndi\params\AdvancedEEE,        Type,       0, "enum"
HKR, Ndi\params\AdvancedEEE,        Default,    0, "0"
HKR, Ndi\params\AdvancedEEE\enum,   "0",        0, %Disabled%
HKR, Ndi\params\AdvancedEEE\enum,   "1",        0, %Enabled%

[DisableAutoPowerSave.reg]
HKR,,				       AutoPowerSaveModeEnabled, 0, "0"

HKR, Ndi\params\EnableGreenEthernet,        ParamDesc,  0, %GreenEthernet%
;HKR, Ndi\params\EnableGreenEthernet,        optional,   0, "1"
HKR, Ndi\params\EnableGreenEthernet,        Type,       0, "enum"
HKR, Ndi\params\EnableGreenEthernet,        Default,    0, "0"
HKR, Ndi\params\EnableGreenEthernet\enum,   "0",        0, %Disabled%
HKR, Ndi\params\EnableGreenEthernet\enum,   "1",        0, %Enabled%

HKR, Ndi\params\GigaLite,        ParamDesc,  0, %GigaLite%
;HKR, Ndi\params\GigaLite,        optional,   0, "1"
HKR, Ndi\params\GigaLite,        Type,       0, "enum"
HKR, Ndi\params\GigaLite,        Default,    0, "1"
HKR, Ndi\params\GigaLite\enum,   "0",        0, %Disabled%
HKR, Ndi\params\GigaLite\enum,   "1",        0, %Enabled%

HKR,Ndi\params\*IdleRestriction,        ParamDesc,  0, %IdleRestriction%
HKR,Ndi\params\*IdleRestriction,        Type,       0, "enum"
HKR,Ndi\params\*IdleRestriction,        Default,    0, "0"
HKR,Ndi\params\*IdleRestriction\enum,   "0",        0, %RestrictionDisable%
HKR,Ndi\params\*IdleRestriction\enum,   "1",        0, %RestrictionEnable%

HKR,Ndi\params\PowerSavingMode,    ParamDesc,  0, %PowerSavingMode%
HKR,Ndi\params\PowerSavingMode,    Type,       0, "enum"
HKR,Ndi\params\PowerSavingMode,    Default,    0, "1"
HKR,Ndi\params\PowerSavingMode\enum,   "0",    0, %Disabled%
HKR,Ndi\params\PowerSavingMode\enum,   "1",    0, %Enabled%

HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  ParamDesc,              0, %ReduceSpeedOnPowerDown%
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Type,                   0, "enum"
HKR,Ndi\Params\ReduceSpeedOnPowerDown,                  Default,                0, "1"
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "1",                    0, %Enabled%
HKR,Ndi\Params\ReduceSpeedOnPowerDown\Enum,             "0",                    0, %Disabled%

HKR,Ndi\Params\ULPMode,                                 Type,                   0, "enum"
HKR,Ndi\Params\ULPMode,                                 Default,                0, "1"
HKR,Ndi\Params\ULPMode\Enum,                            "1",                    0, %Enabled%
HKR,Ndi\Params\ULPMode\Enum,                            "0",                    0, %Disabled%

; Allow host driver to force exit ULP on ME systems
HKR,,                                                   ForceHostExitUlp,       0, "1"

HKR,Ndi\params\WolShutdownLinkSpeed,           ParamDesc,       0, %WolShutdownLinkSpeed%
;HKR,Ndi\params\WolShutdownLinkSpeed,          optional,        0, "1"
HKR,Ndi\params\WolShutdownLinkSpeed,           Type,            0, "enum"
HKR,Ndi\params\WolShutdownLinkSpeed,           Default,         0, "0"
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "0",             0, %10MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "1",             0, %100MbFirst%
HKR,Ndi\params\WolShutdownLinkSpeed\enum,      "2",             0, %NotSpeedDown%
```

Reminder: Each adapter uses it's own default values, means that the `default`/`min`/`max` may be different for you. E.g. `SSIdleTimeout` minimum value was `1` in the first setup information file (`.inf`), but `5` in the second.

### Miscellaneous Values

```c
"DynamicLTR": { "Type": "REG_SZ", "Data": 0 },
"EnableAdvancedDynamicITR": { "Type": "REG_SZ", "Data": 0 },
"S3S4WolPowerSaving": { "Type": "REG_SZ", "Data": 0 },
"AutoLinkDownPcieMacOff": { "Type": "REG_SZ", "Data": 0 }, // "Auto Disable PCIe"
"BatteryModeLinkSpeed": { "Type": "REG_SZ", "Data": 2 },  // Similar to WolShutdownLinkSpeed?
// 10MbFirst                      = "10 Mbps First"
// 100MbFirst                     = "100 Mbps First"
// NotSpeedDown                   = "Not Speed Down"
// AdaptiveLinkSpeed              = "Adaptive Link Speed"
// BatteryModeLinkSpeed           = "Battery Mode Link Speed"
"CLKREQ": { "Type": "REG_SZ", "Data": 0 },
"EnableCoalesce": { "Type": "REG_SZ", "Data": 0 },
"DMACoalescing": { "Type": "REG_SZ", "Data": 0 },
"CoalesceBufferSize": { "Type": "REG_SZ", "Data": 0 },
"*PacketCoalescing": { "Type": "REG_SZ", "Data": 0 },

"SVOFFMode": { "Type": "REG_SZ", "Data": 1 },  // SV: Save?
"SVOFFModeHWM": { "Type": "REG_SZ", "Data": 0 },
"SVOFFModeTimer": { "Type": "REG_SZ", "Data": 0 }

"EnabledDatapathCycleCounters":  { "Type": "REG_SZ", "Data": ? }
"EnabledDatapathEventCounters": { "Type": "REG_SZ", "Data": ? }
```


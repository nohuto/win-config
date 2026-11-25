# Disable WoL

> "*The wake-on-LAN (WOL) feature wakes the computer from a low power state when a network adapter detects a WOL event (typically, a specially constructed Ethernet packet). WOL is supported from `S3` sleep or `S4` hibernate. It's not supported from fast startup or `S5` soft off shutdown states. NICs aren't armed for wake in these states because users don't expect their systems to wake up on their own. WOL is not officially supported from the `S5` soft off state. However, the BIOS on some systems might support arming NICs for wake, even though Windows isn't involved in the process.*"
>
> — Microsoft, [System power states](https://learn.microsoft.com/en-us/windows/win32/power/system-power-states#wake-on-lan-behavior)

```bat
powercfg /devicequery wake_programmable
powercfg /devicequery wake_armed
```
`powercfg /devicequery wake_programmable` -> devices that are user-configurable to wake the system from a sleep state  
`powercfg /devicequery wake_armed` -> currently configured to wake the system from any sleep state

## Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}\\00XX";
  "*WakeOnMagicPacket" = 1; // REG_SZ (bool)
  "*WakeOnPattern" = 1; // REG_SZ (bool)
  "WakeOn" = 0; // REG_SZ, range 0-4
  "WakeFromS5" = 2; // REG_SZ, range 0-65535
  "WakeOnLink" = 0; // REG_SZ, range 0-2
  "WakeOnFastStartup" = 0; // REG_SZ
  "EnableWakeOnManagmentOnTCO" = 0; // REG_SZ (bool)
  "WakeOnMagicPacketFromS5" = 1; // REG_SZ
  "S5WakeOnLan" = ?; // REG_SZ
  "WakeOnLinkChange" = ?; // REG_SZ
  "ShutdownWake" = ?; // REG_SZ
  "WakeUpModeCap" = ?; // REG_SZ
```

### Setup Information

```c
HKR, Ndi\Params\*WakeOnMagicPacket,		ParamDesc,	0, 	%MagicPacket%
HKR, Ndi\Params\*WakeOnMagicPacket,		Type,		0, 	"enum"
HKR, Ndi\Params\*WakeOnMagicPacket\enum,	"1",		0, 	%Enabled%
HKR, Ndi\Params\*WakeOnMagicPacket\enum,	"0",		0, 	%Disabled%
HKR, Ndi\Params\*WakeOnMagicPacket,		Default,	0, 	"1"

HKR, Ndi\Params\*WakeOnPattern,			ParamDesc,	0, 	%PatternMatch%
HKR, Ndi\Params\*WakeOnPattern,			Type,		0, 	"enum"
HKR, Ndi\Params\*WakeOnPattern\enum,		"1",		0, 	%Enabled%
HKR, Ndi\Params\*WakeOnPattern\enum,		"0",		0, 	%Disabled%
HKR, Ndi\Params\*WakeOnPattern,			Default,	0, 	"1"

HKR,Ndi\params\S5WakeOnLan,       ParamDesc,  0, %S5WakeOnLan%
HKR,Ndi\params\S5WakeOnLan,       Type,       0, "enum"
HKR,Ndi\params\S5WakeOnLan,       Default,    0, "1"
HKR,Ndi\params\S5WakeOnLan\enum,  "0",        0, %Disabled%
HKR,Ndi\params\S5WakeOnLan\enum,  "1",        0, %Enabled%

HKR, Ndi\Params\ShutdownWake,			ParamDesc,	0,	 %ShutDW%
HKR, Ndi\Params\ShutdownWake,			Type,		0,	 "enum"
HKR, Ndi\Params\ShutdownWake\enum,		1,		0,	 %Enabled%
HKR, Ndi\Params\ShutdownWake\enum,		0,		0,	 %Disabled%
HKR, Ndi\Params\ShutdownWake,			Default,	0,	 "1"

HKR, Ndi\params\WakeFromS5,                     ParamDesc,  0, %WakeFromS5%
HKR, Ndi\params\WakeFromS5,                     default,    0, "1"
HKR, Ndi\params\WakeFromS5,                     type,       0, "enum"
HKR, Ndi\params\WakeFromS5\enum,                "0",        0, %Disable%
HKR, Ndi\params\WakeFromS5\enum,                "1",        0, %Enable%

HKR, Ndi\Params\WakeOnLink,        ParamDesc, , %WakeOnLink%
HKR, Ndi\Params\WakeOnLink,        default,   , "0"
HKR, Ndi\Params\WakeOnLink,        type,      , "enum"
HKR, Ndi\Params\WakeOnLink\enum,   0,         , %WakeOnLink_Disable%
HKR, Ndi\Params\WakeOnLink\enum,   1,         , %WakeOnLink_Enable%

HKR, Ndi\params\WakeOnLinkChange,        ParamDesc,  0, %LinkChgWol%
HKR, Ndi\params\WakeOnLinkChange,        type,       0, "enum"
HKR, Ndi\params\WakeOnLinkChange,        default,    0, "1"
HKR, Ndi\params\WakeOnLinkChange\enum,   "0",        0, %Disabled%
HKR, Ndi\params\WakeOnLinkChange\enum,   "1",        0, %Enabled%

HKR, Ndi\Params\WakeOnMagicPacketFromS5,                ParamDesc,              0, %WakeOnMagicPacketFromS5Settings%
HKR, Ndi\Params\WakeOnMagicPacketFromS5\Enum,           "0",                    0, %Disabled%
HKR, Ndi\Params\WakeOnMagicPacketFromS5\Enum,           "1",                    0, %Enabled%
HKR, Ndi\Params\WakeOnMagicPacketFromS5,                type,                   0, "enum"
HKR, Ndi\Params\WakeOnMagicPacketFromS5,                default,                0, "1"

HKR, Ndi\Params\WakeUpModeCap,       ParamDesc,   0 , %WakeUpMode%
HKR, Ndi\Params\WakeUpModeCap,       default,  0  , "2"
HKR, Ndi\Params\WakeUpModeCap,       type,      0  , "enum"
HKR, Ndi\Params\WakeUpModeCap\enum,  "0",        0 , %WakeUpMode_None%
HKR, Ndi\Params\WakeUpModeCap\enum,  "1",        0 , %WakeUpMode_Magic%
HKR, Ndi\Params\WakeUpModeCap\enum,  "2",        0 , %WakeUpMode_Pattern%
```


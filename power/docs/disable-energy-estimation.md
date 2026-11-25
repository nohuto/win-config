# Disable Energy Estimation

Energy estimation accounts for estimated power usage, components report modeled energy costs, which are tracked per process and used for battery and standby telemetry.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "UserBatteryDischargeEstimator" = 0; // PopDisableBatteryDischargeEstimator, 0 = the kernel publishes WNF_PO_DISCHARGE_ESTIMATE (battery time left), the item writes the default
    "UserBatteryChargeEstimator" = 0; // PopUserBatteryChargingEstimator, 0 = the kernel publishes WNF_PO_CHARGE_ESTIMATE (time until full), the item writes the default
    "EnergyEstimationEnabled" = 1; // PopEnergyEstimationEnabled, https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/ntoskrnl/PoEnergyEstimationEnabled.c
```

`EnergyEstimationDisabled` was the name before W10 1709 (`PopEnergyEstimationDisabled` in 1507 & 1607), current builds only read `EnergyEstimationEnabled`.

```c
// PopBatteryWorker (25H2)

if ( !PopUserBatteryChargingEstimator )
  ZwUpdateWnfStateData(&WNF_PO_CHARGE_ESTIMATE, &v159, 8u, 0LL, 0LL, 0, 0);
if ( PopDisableBatteryDischargeEstimator )
{
  v98 = v137;
}
else
{
  v97 = PopBatteryEstimatesSpoiled();
  v98 = v97;
  if ( (_DWORD)v92 != -1 && !v97 )
    v160 = v92;
  ZwUpdateWnfStateData(&WNF_PO_DISCHARGE_ESTIMATE, &v160, 8u, 0LL, 0LL, 0, 0);
}
```

![](https://github.com/nohuto/win-config/blob/main/power/images/energyesti.png?raw=true)

## TaggedEnergy

`eeprov.dll` only tags process energy when `DisableTaggedEnergyLogging` exists and is `0` (or `EnergyEstimationEnabled = 0`).

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\TaggedEnergy";
    "DisableTaggedEnergyLogging" = 0; // REG_DWORD
    "TelemetryMaxApplication" = 250; // REG_DWORD, missing/above 500 = 500, 0 stops provider
    "TelemetryMaxTagPerApplication" = 50; // REG_DWORD, missing/above 100 = 100, 0 stops provider
```

## Suboption

### Battery Capacity Section

Hides the battery capacity section on the battery saver page of the *Settings* app.

```c
// CBatterySaverBatteryCapacity::get_IsApplicable (SettingsHandlers_OneCore_BatterySaver.dll, 25H2)

v3 = 0;
if ( (unsigned __int8)RtlIsStateSeparationEnabled(this) )
{
  if ( (unsigned __int8)IsPolicyManager_GetPolicyPresent() )
  {
    v8 = 1;
    v9 = 2;
    v10 = 0LL;
    if ( (int)PolicyManager_GetPolicy(L"Settings", L"EnableBatteryCapacity", &v8, &v10) >= 0
      && *(_DWORD *)(v10 + 16) == 1 )
    {
      goto LABEL_8;
    }
  }
}
else
{
  v8 = 0;
  if ( (int)SHRegGetDWORD(v5, v4, v6, &v8) >= 0 && v8 ) // Control\Power EnableSettingsAppBatteryCapacitySection
LABEL_8:
    v3 = 1; // section shown
}
```

## IdleStatesNumber

These values are located in `partmgr.sys` and can be misunderstood. `IdleStatesNumber` just tells `partmgr` how many `IdleState\x` estimation "profiles" to load, example:

- `IdleStatesNumber = 1` -> read only `IdleState\1`
- `IdleStatesNumber = 3` -> read `IdleState\1`, `IdleState\2`, `IdleState\3`

So these values seem to change the estimated energy *math* part.

Miscellaneous values in that key:

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\<SD|SSD|HDD|NVME>"; // subkey by DISK_DEVICEPOWER_TYPE
    "SmallRandomReadPowerMw" = ?;
    "SmallRandomWritePowerMw" = ?;
    "SmallSequentialReadPowerMw" = ?;
    "SmallSequentialWritePowerMw" = ?;
    "LargeRandomReadPowerMw" = ?;
    "LargeRandomWritePowerMw" = ?;
    "LargeSequentialReadPowerMw" = ?;
    "LargeSequentialWritePowerMw" = ?;
    "FlushPowerMw" = ?;
    "IdleStatesNumber" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\EnergyEstimation\\Storage\\<SD|SSD|HDD|NVME>\\IdleState\\<n>";
    "IdleExitLatencyMs" = ?;
    "IdleExitEnergyMicroJoules" = ?;
    "IdleTimeLengthMs" = ?;
    "IdlePowerMw" = ?;
```

# StorPort Values

This currently includes the values [`storport.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/storport) reads from these keys.

## Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort";
    "DpcCompletionLimit" = 128; // REG_DWORD, 0 = 4294967295
    "HiberFileHybridPriority" = 65535; // REG_BINARY
    "HmbAllocationPolicy" = 2; // REG_DWORD, range 0-4294967295, but only 1/2/3 seem to be used other values are invalid
    "HmbMaximumSizeInBytes" = 67108864; // REG_DWORD
    "MiniportBugActionPolicy" = 1; // REG_DWORD, range 0-2, >=3 replaced with 1
    "AsyncStart" = 0; // REG_DWORD (bool)
    "TelemetryPerformanceHighResolutionTimer" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryPerformanceEnabled" = 4294967295; // REG_DWORD
    "TelemetryIoSizeDistributionEnabled" = 0; // REG_DWORD, range 0-4294967295, queried only when TelemetryPerformanceEnabled is nonzero
    "TelemetryPerformancePeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryErrorDataEnabled" = 4294967295; // REG_DWORD
    "TelemetryDeviceHealthEnabled" = 4294967295; // REG_DWORD
    "TelemetryDeviceHealthPeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryCriticalEventEnabled" = 0; // REG_DWORD, missing = storport turns critical event telemetry on by itself for some disks, 0 = never, nonzero = always, each up to TelemetryCriticalEventMaximum events
    "TelemetryCriticalEventMaximum" = 4294967295; // REG_DWORD, range 0-4294967295
    "ExtendedDSMCommandsSupported" = 0; // REG_DWORD (bool)
    "FUAEnable" = 0; // REG_DWORD (bool)
    "QoSFlags" = 0; // REG_DWORD, range 0-4294967295
    "MaxPreAllocatedIoResourceCount" = 4096; // REG_DWORD, range 1-4294967295, 0 ignored
    "DFxEnable" = 1; // REG_DWORD (bool)
    "OverrideDeviceUniqueIDCapability" = 1; // REG_DWORD (bool)
    "DisableRuntimePower" = 0; // REG_DWORD (bool)
    "ProcsPerGateway" = 8; // REG_DWORD, clamped to 4-16, then capped to the processor count (default too)
    "MFNDEnable" = 0; // REG_DWORD (bool)
    "CreateControlObject" = 0; // REG_DWORD (bool)
    "DisableIEEE1667" = 0; // REG_DWORD (bool)
    "EnableNativeTcg" = 0; // REG_DWORD (bool)
    "EnableRegistryWatch" = 1; // REG_DWORD (bool), nonzero = storport rereads dynamic values below when the key changes
    "LogControlEnable" = 8013; // REG_QWORD
    "LogSize" = 256; // REG_DWORD, 1-63 = 64, above 393216 = 393216, 0 = no log and LogControlEnable 0
    "DeviceQueueIoWaitThreshold" = 300000000; // REG_QWORD, range 1-4294967295
    "HighLatencyIoThreshold" = 300000000; // REG_QWORD, range 1-4294967295
    "TelemetryDeviceLogPagesPeriod" = 24; // REG_DWORD, range 1-24 hours, >=24 clamps to 24
    "DeviceTelemetryLiveDumpEnable" = 4294967295; // REG_DWORD, 1 = always, 0 = never (kernel dumps on device telemetry events)
    "StorportEtwErrorThrottleLimit" = 60; // REG_DWORD, range 1-4294967295
    "StorportEtwWarningThrottleLimit" = 30; // REG_DWORD, range 1-4294967295
    "StorportEtwInfoThrottleLimit" = 10; // REG_DWORD, range 1-4294967295
    "ReportAllWheaErrorsAsNonFatal" = 0; // REG_DWORD (bool)
    "DisableExtensionDriver" = 0; // REG_DWORD (bool)

    // W11 24H2+, DllInitialize
    "DisableNativeNVMeStack" = 0; // REG_DWORD (bool)
    "EnableNVMeICE" = 1; // REG_DWORD, nonzero sets EnableNVMeICE, 2+ also EnableNVMeICEV2, 3+ EnableNVMeICEV3 (feature SteelixNvmeIceInterfaceV3)
    "EnableSolitaryIO" = 0; // REG_DWORD (bool), 26H1
    "ForwardedIo" = 0; // REG_DWORD (bool)
    "KsrPowerDownOptimizationEnabled" = 1; // REG_DWORD (bool)

    // W11 24H2+, StorpUpdateDynamicRegistrySettings
    "DlrmScaleDownThresholdFactorPercent" = 40; // REG_DWORD, 5-100
    "DlrmScaleDownTimeWindow100ns" = 5000000; // REG_QWORD, 100ns units, 2000000-50000000
    "DlrmScaleUpThresholdFactorPercent" = 10; // REG_DWORD, 5-100
    "DlrmScaleUpTimeWindow100ns" = 200000; // REG_QWORD, 100ns units, 100000-1000000
    "FirmwareActivateTimeout" = 60; // REG_DWORD
    "NvmeKeepAliveTimeoutDefault" = 120; // REG_DWORD, below 60 = 60, above 600 = 600 (sec)
    "StorLivedumpCodesEnabled" = 4294967295; // REG_DWORD
    "TestFlags" = 0; // REG_QWORD

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort\\Verifier";
    "VerifyLevel" = 0; // REG_DWORD, range 0-4294967295
                       // "The value assigned to this entry will determine which Storport Verification tests will be active. The value 0x1 will give maximum verification."
                       // "If the VerifyLevel value does not exist, or is equal to 0xFFFFFFFF, Storport Verification will be disabled."
                       // https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/dv-storport-verification

// miscellaneous values from storport driver

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage"; // https://noverse.dev/docs/win-config/power/power-values/#storaged3inmodernstandby
    "StorageD3InModernStandby" = 4294967295;

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\StorageTelemetry"; // storport, ataport
    "DeviceDumpLevel" = 1; // REG_DWORD
    "DeviceDumpMaxSize" = 32768; // REG_DWORD
```

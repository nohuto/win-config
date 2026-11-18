# StorPort Values

This currently includes all values from [`storport.sys`](https://github.com/nohuto/decompiled-pseudocode/tree/main/11-23H2/storport) (in relation to that StorPort key, this binary also has some PnP values/other single values, see [pnp-device-values/#default-data](https://noverse.dev/docs/win-config/power/pnp-device-values/#default-data)), see [DllInitialize](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/DllInitialize.c) & [sub_1C0042F20](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/storport/sub_1C0042F20.c) functions. More details on StorPort topic/values may be added soon.

Values that include `(bool)` as comment accept range `0-4294967295` but any nonzero has the same behaviour as `1`.

## Registry Values

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort";
    "DpcCompletionLimit" = 128; // REG_DWORD, range 0-4294967295
    "HiberFileHybridPriority" = 65535; // REG_BINARY
    "HmbAllocationPolicy" = 2; // REG_DWORD, range 0-4294967295, but only 1/2/3 seem to be used other values are invalid
    "HmbMaximumSizeInBytes" = 67108864; // REG_DWORD, range 0-67108864
    "MiniportBugActionPolicy" = 1; // REG_DWORD, range 0-2, >=3 replaced with 1
    "AsyncStart" = 0; // REG_DWORD (bool)
    "TelemetryPerformanceHighResolutionTimer" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryPerformanceEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryIoSizeDistributionEnabled" = 0; // REG_DWORD, range 0-4294967295, queried only when TelemetryPerformanceEnabled is nonzero
    "TelemetryPerformancePeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryErrorDataEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryDeviceHealthEnabled" = 4294967295; // REG_DWORD, range 0-4294967295
    "TelemetryDeviceHealthPeriod" = 1; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "TelemetryCriticalEventEnabled" = 0; // REG_DWORD, range 0-4294967295
    "TelemetryCriticalEventMaximum" = 4294967295; // REG_DWORD, range 0-4294967295
    "ExtendedDSMCommandsSupported" = 0; // REG_DWORD (bool)
    "FUAEnable" = 0; // REG_DWORD (bool)
    "QoSFlags" = 0; // REG_DWORD, range 0-4294967295
    "MaxPreAllocatedIoResourceCount" = 4096; // REG_DWORD, range 1-4294967295, 0 ignored
    "DFxEnable" = 1; // REG_DWORD (bool)
    "OverrideDeviceUniqueIDCapability" = 1; // REG_DWORD (bool)
    "DisableRuntimePower" = 0; // REG_DWORD (bool)
    "ProcsPerGateway" = 8; // REG_DWORD, range 4-16 (capped to maximum processor count?)
    "MFNDEnable" = 0; // REG_DWORD (bool)
    "CreateControlObject" = 0; // REG_DWORD (bool)
    "DisableIEEE1667" = 0; // REG_DWORD (bool)
    "EnableNativeTcg" = 0; // REG_DWORD (bool)
    "EnableRegistryWatch" = 0; // REG_DWORD (bool)
    "LogControlEnable" = 7757; // REG_QWORD, range 0-4294967295, 0 forces LogSize 0
    "LogSize" = 256; // REG_DWORD, range 0 or 64-393216
    "DeviceQueueIoWaitThreshold" = 300000000; // REG_QWORD, range 1-4294967295, 0 ignored
    "HighLatencyIoThreshold" = 300000000; // REG_QWORD, range 1-4294967295, 0 ignored
    "TelemetryDeviceLogPagesPeriod" = 24; // REG_DWORD, range 1-24 hours, 0 ignored, >=24 clamps to 24
    "DeviceTelemetryLiveDumpEnable" = 4294967295; // REG_DWORD (bool)
    "StorportEtwErrorThrottleLimit" = 60; // REG_DWORD, range 1-4294967295, 0 ignored
    "StorportEtwWarningThrottleLimit" = 30; // REG_DWORD, range 1-4294967295, 0 ignored
    "StorportEtwInfoThrottleLimit" = 10; // REG_DWORD, range 1-4294967295, 0 ignored
    "ReportAllWheaErrorsAsNonFatal" = 0; // REG_DWORD (bool)
    "DisableExtensionDriver" = 0; // REG_DWORD (bool)

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorPort\\Verifier";
    "VerifyLevel" = 0; // REG_DWORD, range 0-4294967295
                       // "The value assigned to this entry will determine which Storport Verification tests will be active. The value 0x1 will give maximum verification."
                       // "If the VerifyLevel value does not exist, or is equal to 0xFFFFFFFF, Storport Verification will be disabled."
                       // https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/dv-storport-verification

// miscellaneous values from storport driver

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage";
    "StorageD3InModernStandby" = 4294967295; // REG_DWORD, 0 = Disable D3 support, 1 = Enable D3 support - https://noverse.dev/docs/win-config/power/power-values/#storaged3inmodernstandby

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\StorageTelemetry";
    "DeviceDumpLevel" = 2; // REG_DWORD, range 0-4294967295
    "DeviceDumpMaxSize" = 0; // REG_DWORD, range 0-4294967295
```


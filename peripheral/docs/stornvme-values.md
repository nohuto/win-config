# StorNVMe Values

This option serves as a general values overview for the `stornvme` key. Several values are applied, some have been changed, others are default values. The applied data is sometimes pure speculation.

## Registry Values

Most values are read via `ReadMultiSzRegistryValueAndCompareId` using the device id match string `VEN_vvvv&DEV_dddd&REV_rr`, so I currently assume that their type is REG_MULTI_SZ. Several values are set to 0 which sometimes also means "ignore" for example. Note that the information in this list is based on `stornvme.sys` only (if value has comment).

[Database-engine/database-file-operations](https://learn.microsoft.com/en-us/troubleshoot/sql/database-engine/database-file-operations/troubleshoot-os-4kb-disk-sector-size?tabs=registry-editor#resolution-steps-for-disk-sector-size-errors-in-sql-server) validates that `ForcedPhysicalSectorSizeInBytes` is a Multi-String value, which confirms a part of my assumption, but I'm still not 100% sure about the rest. Feel free to correct me.

See [GetRegistrySettings23H2.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/stornvme/GetRegistrySettings.c), [GetRegistrySettings24H2.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-24H2/stornvme/GetRegistrySettings.c), [stornvmeGetDynamicRegistrySettings26H1.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/stornvme/GetDynamicRegistrySettings.c), and [GetRegistrySettingsForSpecificKey26H1.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-26H1/stornvme/GetRegistrySettingsForSpecificKey.c) for details.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters\\Device";
    "MaxTransferSize" = 0; // REG_MULTI_SZ, range 1-2048
    "IoQueueDepth" = 0; // REG_MULTI_SZ
    "IoSubmissionQueueCount" = 0; // REG_MULTI_SZ
    "IoCompletionQueueCount" = 0; // REG_MULTI_SZ
    "InterruptCoalescingTime" = 0; // REG_MULTI_SZ
    "InterruptCoalescingEntry" = 0; // REG_MULTI_SZ
    "ArbitrationBurst" = 255; // REG_MULTI_SZ
    "ContiguousMemoryFromAnyNode" = 0; // REG_MULTI_SZ
    "ShutdownTimeout" = 0; // REG_MULTI_SZ, >0xFF clamped to 0xFF, 0 ignored
    "DeallocateMaxLbaCount" = 0; // REG_MULTI_SZ
    "DisableDeallocate" = 0; // REG_MULTI_SZ
    "ControllerBasicInit" = 0; // REG_MULTI_SZ
    "AsyncEventMask" = ?; // REG_MULTI_SZ
    "IdlePowerMode" = 0; // REG_MULTI_SZ, applied only if value < 6
    "DiagnosticFlags" = 0; // REG_MULTI_SZ, bit 1 (0x2) forces LogSize default to 0x100000 bytes
    "LogSize" = 0; // REG_MULTI_SZ, 0 ignored (unless DiagnosticFlags set)
    "IoStripeAlignment" = 0; // REG_MULTI_SZ
    "MedPowerFxIdleTimeout" = 4294967295; // REG_MULTI_SZ
    "LowestPowerFxIdleTimeout" = 50; // REG_MULTI_SZ
    "MedPowerD3IdleTimeout" = 3000; // REG_MULTI_SZ
    "LowestPowerD3IdleTimeout" = 1000; // REG_MULTI_SZ
    "MedPowerResumeLatency" = 4294967295; // REG_MULTI_SZ
    "LowestPowerResumeLatency" = 4294967295; // REG_MULTI_SZ
    "HostMemoryBufferBytes" = 4294967295; // REG_MULTI_SZ
    "BypassSgl" = 1; // REG_MULTI_SZ, only value bit 0 is used
    "TestMdlDataBufferOffsetInBytes" = 0; // REG_MULTI_SZ
    "UseDumpPointers" = 0; // REG_MULTI_SZ
    "ReservedQueuePairCount" = 0; // REG_MULTI_SZ, valid 1-65535
    "NvmeTestSwitch" = 1; // REG_MULTI_SZ
    "IoQueuePercentageInPollingMode" = 0; // REG_MULTI_SZ, >100 clamped to 100
    "IoPollingInterval" = 0; // REG_MULTI_SZ, >100000 clamped to 100000
    "IoCompletionCapInDPC" = 100; // REG_MULTI_SZ, if nonzero clamp to 128
    "IoPollingSize" = 0x4000; // REG_MULTI_SZ
    "ErrorEtwThrottleInterval" = 0xD693A400; // REG_MULTI_SZ, if nonzero clamp to max 0xD693A400
    "ResetEnableMask" = 0; // REG_MULTI_SZ
    "ReliabilityDegraded" = 0; // REG_MULTI_SZ
    "ReadOnly" = 0; // REG_MULTI_SZ
    "VolatileMemoryBackupDeviceFailed" = 0; // REG_MULTI_SZ
    "AvailableSpare" = 0; // REG_MULTI_SZ
    "AvailableSpareThreshold" = 0; // REG_MULTI_SZ
    "ForcedPhysicalSectorSizeInBytes" = ?; // REG_MULTI_SZ
    "RetainAsyncEventControlMask" = ?; // REG_MULTI_SZ
    "ShutdownTimeoutForSurpriseRemove" = 0; // REG_MULTI_SZ, >0xFF clamped to 0xFF, 0 ignored
    "MaxIoCountLimit" = 0; // REG_MULTI_SZ
    "SubmissionQueueAssignmentPolicy" = 0; // REG_MULTI_SZ
    "DisableMFNDCCDuringRemoval" = ?; // REG_MULTI_SZ
    "EnableSingleDpcForIoCompletion" = ?; // REG_MULTI_SZ
    "DisableNamespacePreferredValueCheck" = ?; // REG_MULTI_SZ
    "IgnoreNamespacePreferredValues" = ?; // REG_MULTI_SZ
    "DisableBypassIO" = ?; // REG_MULTI_SZ
    "DisableGetActiveNSIDList" = 0; // REG_MULTI_SZ
    "ForceCryptoEraseToUseFormatNVM" = 0; // REG_MULTI_SZ

    "ControllerResetWaitTimeCushion" = 20000; // REG_MULTI_SZ
    "DisableActivateFWWithoutReset" = 0; // REG_MULTI_SZ

    // present in 24H2 path (not present in 23H2 path)
    "DisableDSTThrottle" = ?; // REG_MULTI_SZ
    "DisableF0TimestampSync" = 0; // REG_MULTI_SZ
    "DisableForwardedIO" = 0; // REG_MULTI_SZ
    "EnableIntelTSESplitIOWorkaround" = 0; // REG_MULTI_SZ
    "EnforceActiveNamespaceIdentification" = 0; // REG_MULTI_SZ
    "SupportZeroActiveNamespace" = 0; // REG_MULTI_SZ
    "WeightedRoundRobinEnabled" = 0; // REG_MULTI_SZ

    "DriverParameter" = ?;
    "HostIdentifier" = ?;
    "LinkTimeout" = ?;
    "MaximumLogicalUnit" = ?;
    "MaximumUCXAddress" = ?;
    "MinimumUCXAddress" = ?;
    "NumberOfRequests" = ?;
    "UncachedExtAlignment" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters";
    "StorageSupportedFeatures" = 1; // "Support ByPassIO"
                                    // "BypassIO is an optimized I/O path for reading from files. The goal of this path is to reduce the CPU overhead of doing reads, which helps to meet the I/O demands of loading and running next-generation games on Windows. BypassIO is a part of the infrastructure to support DirectStorage on Windows, and is available starting in Windows 11."
                                    // https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/bypassio
    "DmaRemappingCompatible" = 2; // https://github.com/nohuto/win-config/blob/main/security/desc.md#opt-out-dma-remapping
    "BusType" = ?; // bustype 0x11 is value of BusTypeNVMe
    "BusyPauseTimeInMs" = ?;
    "BusyRetryCount" = ?;
    "IoLatencyCap" = ?;
    "IoTimeoutValue" = 10;
    "PnpAsyncNewDevices" = ?;
```


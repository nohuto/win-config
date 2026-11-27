# StorNVMe Values


This is currently just a list of values, more about the topic itself may be added soon.

## Registry Values

`stornvme.sys` reads the values below with `ReadMultiSzRegistryValueAndCompareId`, which asks storport for a `REG_MULTI_SZ` from `Services\stornvme\Parameters\Device`, each string of the value is `<device> <number>`:

```
HKR, "Parameters\Device", "IoStripeAlignment", %REG_MULTI_SZ_APPEND%, "VEN_8086&DEV_0953&REV_?? 128"
```

[MS SQL Server sector size fix](https://learn.microsoft.com/en-us/troubleshoot/sql/database-engine/database-file-operations/troubleshoot-os-4kb-disk-sector-size?tabs=registry-editor#resolution-steps-for-disk-sector-size-errors-in-sql-server) uses e.g. `* 4095` for `ForcedPhysicalSectorSizeInBytes`, which matches every controller.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters\\Device";
    "MaxTransferSize" = 0; // REG_MULTI_SZ, KB, clamped to 2048, 0 ignored
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
    "AsyncEventMask" = 1823; // REG_MULTI_SZ
    "IdlePowerMode" = 0; // REG_MULTI_SZ, 2 & 5 = runtime D3 cold allowed, 3 = APST only, 4 = no idle power setup
    "DiagnosticFlags" = 0; // REG_MULTI_SZ, bit 1 (0x2) forces LogSize default to 0x100000 bytes
    "LogSize" = 0; // REG_MULTI_SZ, KB, 0 ignored (unless DiagnosticFlags set)
    "IoStripeAlignment" = 0; // REG_MULTI_SZ, KB
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
    "DisableDSTThrottle" = 0; // REG_MULTI_SZ
    "DisableF0TimestampSync" = 0; // REG_MULTI_SZ
    "DisableForwardedIO" = 0; // REG_MULTI_SZ
    "EnableIntelTSESplitIOWorkaround" = 0; // REG_MULTI_SZ
    "EnforceActiveNamespaceIdentification" = 0; // REG_MULTI_SZ
    "SupportZeroActiveNamespace" = 0; // REG_MULTI_SZ
    "WeightedRoundRobinEnabled" = 0; // REG_MULTI_SZ

    "HostIdentifier" = ?; // REG_BINARY

    // storport reads these for every storport miniport
    "DriverParameter" = ?;
    "LinkTimeout" = ?;
    "MaximumLogicalUnit" = ?;
    "MaximumUCXAddress" = ?;
    "MinimumUCXAddress" = ?;
    "NumberOfRequests" = ?;
    "UncachedExtAlignment" = ?;

"HKLM\\SYSTEM\\CurrentControlSet\\Services\\stornvme\\Parameters";
    "BusType" = 17; // REG_DWORD
    "BusyPauseTimeInMs" = ?; // REG_DWORD
    "BusyRetryCount" = ?; // REG_DWORD
    "DmaRemappingCompatible" = 2; // REG_DWORD, https://noverse.dev/docs/win-config/security/dma-remapping/
    "IoLatencyCap" = ?; // REG_DWORD
    "IoTimeoutValue" = 10; // REG_DWORD, 1-65535 (sec)
    "PnpAsyncNewDevices" = ?; // REG_DWORD
    "StorageSupportedFeatures" = 1; // REG_DWORD, "Support ByPass IO"
                                    // "BypassIO is an optimized I/O path for reading from files. The goal of this path is to reduce the CPU overhead of doing reads, which helps to meet the I/O demands of loading and running next-generation games on Windows. BypassIO is a part of the infrastructure to support DirectStorage on Windows, and is available starting in Windows 11."
                                    // https://learn.microsoft.com/en-us/windows-hardware/drivers/storage/bypassio
```

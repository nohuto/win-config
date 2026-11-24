# Disable Startup ETS

"The AutoLogger event tracing session records events that occur early in the operating system boot process. Applications and device drivers can use the AutoLogger session to capture traces before the user logs in. Note that some device drivers, such as disk device drivers, are not loaded at the time the AutoLogger session begins."

See the configured startup sessions in `Performance Monitor > Data Collector Sets > Startup Event Trace Sessions`, the running ones under `Event Trace Sessions`.

| Session | Owner |
| --- | --- |
| `DiagLog` | Diagnostic Policy Service (`dps.dll`, diagnosticinfrastructure-settings manifest) |
| `Diagtrack-Listener` | Connected User Experiences and Telemetry (`diagtrack.dll`) |
| `FilterMgr-Logger` | no 23H2 manifest/binary includes it, but a January 2026 kernel debugger list of running sessions ([ThreatIntelligenceConsumer](https://github.com/preludeorg/ThreatIntelligenceConsumer) shows it |
| `LwtNetLog` | NDIS lightweight trace, `netsh wlan show wlanreport` reads it (`wlancfg.dll`) |
| `NtfsLog` | NTFS (fsd manifest) |
| `ReFSLog` | ReFS (refs-fsd manifest) |

Logs are saved in:
```c
C:\WINDOWS\system32\Logfiles\WMI

// C:\Windows\System32\drivers\DriverData\LogFiles\WMI
// C:\PerfLogs\Admin
```

Removing all autologgers will cause issues, therefore it's not recommended to remove all of them.

## [Autologger Value Table](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/configuring-and-starting-an-autologger-session.md)

| Value | Type | Description | 
|-------|------|-------------|
| **BufferSize** | **REG_DWORD** | The size of each buffer, in kilobytes. Should be less than one megabyte. ETW uses the size of physical memory to calculate this value.|
| **ClockType** | **REG_DWORD** | The timer to use when logging the time stamp for each event. <br> - 1 = Performance counter value (high resolution)<br> - 2 = System timer<br> - 3 = CPU cycle counter <br> For a description of each clock type, see the **ClientContext** member of [WNODE_HEADER](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/wnode-header.md).<br> The default value is 1 (performance counter value) on Windows Vista and later. Prior to Windows Vista, the default value is 2 (system timer). | 
| **DisableRealtimePersistence** | **REG_DWORD** | To disable real time persistence, set this value to 1. The default is 0 (enabled) for real time sessions.<br> If real time persistence is enabled, real-time events that were not delivered by the time the computer was shutdown will be persisted. The events will then be delivered to the consumer the next time the consumer connects to the session. |
| **FileCounter** | **REG_DWORD** | Do not set or modify this value. This value is the serial number used to increment the log file name if **FileMax** is specified. If the value is not valid, 1 will be assumed.|
| **FileName** | **REG_SZ** | The fully qualified path of the log file. The path to this file must exist. The log file is a sequential log file. The path is limited to 1024 characters.<br> If **FileName** is not specified, events are written to `%WINDIR%\System32\LogFiles\WMI\\<sessionname>.etl`. |
| **FileMax** | **REG_DWORD** | The maximum number of instances of the log file that ETW creates. If the log file specified in **FileName** exists, ETW appends the **FileCounter** value to the file name. For example, if the default log file name is used, the form is `%WINDIR%\System32\LogFiles\WMI\\<sessionname>.etl.NNNN`. <br> The first time the computer is started, the file name is `<sessionname>.etl.0001`, the second time the file name is `<sessionname>.etl.0002`, and so on. If **FileMax** is 3, on the fourth restart of the computer, ETW resets the counter to 1 and overwrites `<sessionname>.etl.0001`, if it exists.<br> The maximum number of instances of the log file that are supported is 16.<br> Do not use this feature with the [EVENT_TRACE_FILE_MODE_NEWFILE](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md) log file mode.|
| **FlushTimer** | **REG_DWORD** | How often, in seconds, the trace buffers are forcibly flushed. The minimum flush time is 1 second. This forced flush is in addition to the automatic flush that occurs when a buffer is full and when the trace session stops. <br> For the case of a real-time logger, a value of zero (the default value) means that the flush time will be set to 1 second. A real-time logger is when **LogFileMode** is set to **EVENT_TRACE_REAL_TIME_MODE**.<br> The default value is 0. By default, buffers are flushed only when they are full. |
| **Guid** | **REG_SZ** | A string that contains a GUID that uniquely identifies the session. This value is required. | 
| **LogFileMode** | **REG_DWORD** | Specify one or more log modes. For possible values, see [Logging Mode Constants](https://github.com/MicrosoftDocs/win32/blob/docs/desktop-src/ETW/logging-mode-constants.md). The default is **EVENT_TRACE_FILE_MODE_SEQUENTIAL**. Instead of writing to a log file, you can specify either **EVENT_TRACE_BUFFERING_MODE** or **EVENT_TRACE_REAL_TIME_MODE**.<br> Specifying **EVENT_TRACE_BUFFERING_MODE** avoids the cost of flushing the contents of the session to disk when the file system becomes available. <br> Note that using **EVENT_TRACE_BUFFERING_MODE** will cause the system to ignore the **MaximumBuffers** value, as the buffer size is instead the product of **MinimumBuffers** and **BufferSize**.<br> AutoLogger sessions do not support the **EVENT_TRACE_FILE_MODE_NEWFILE** logging mode.<br> If **EVENT_TRACE_FILE_MODE_APPEND** is specified, **BufferSize** must be explicitly provided and must be the same in both the logger and the file being appended.|
| **MaxFileSize** | **REG_DWORD** | The maximum file size of the log file, in megabytes. The session is closed when the maximum size is reached, unless you are in circular log file mode. To specify no limit, set value to 0. The default is 100 MB, if not set. The behavior that occurs when the maximum file size is reached depends on the value of **LogFileMode**.|
| **MaximumBuffers** | **REG_DWORD** | The maximum number of buffers to allocate. Typically, this value is the minimum number of buffers plus twenty. ETW uses the buffer size and the size of physical memory to calculate this value. This value must be greater than or equal to the value for **MinimumBuffers**.|
| **MinimumBuffers** | **REG_DWORD** | The minimum number of buffers to allocate at startup. The minimum number of buffers that you can specify is two buffers per processor. For example, on a single processor computer, the minimum number of buffers is two.|
| **Start** | **REG_DWORD** | To have the AutoLogger session start the next time the computer is restarted, set this value to 1; otherwise, set this value to 0.|
| **Status** | **REG_DWORD** | The startup status of the AutoLogger. If the AutoLogger failed to start, the value of this key is the appropriate Win32 error code. If the AutoLogger successfully started, the value of this key is **ERROR_SUCCESS** (0).|
| **Boot** | **REG_DWORD** | This feature should not be used outside of debugging scenarios.<br> If this registry key is set to 1, the autologger will be started earlier than normal during kernel initialization, allowing it to capture events during the initialization of many important kernel subsystems. However, enabling this option has a negative impact on boot times and imposes additional restrictions on the autologger. If this feature is enabled, the autologger session GUID must be populated, and many other autologger settings may not work. <br> This key is supported on Windows Server 2022 and later. |


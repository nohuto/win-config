# BSoD Memory Dump Files

Removes kernel crash dump data created after a system bugcheck. Useful if you want to reclaim disk space or you have already analyzed the crash.

This option clears `LiveKernelReports`, `MEMORY.DMP`, and per-crash minidumps in `%WINDIR%\Minidump`.

Paths removed:
```c
%WINDIR%\LiveKernelReports
%WINDIR%\MEMORY.DMP
%WINDIR%\Minidump\*.dmp
```


# Increase TDR

Turning detection off (`TdrLevel = 0`) removes the recovery, means a hung GPU then freezes the whole system, so rather leave it enabled.

> "*TDR is a feature in Windows that detects when the graphics card takes longer than expected to complete an operation. It then resets the graphics card to prevent the entire system from becoming unresponsive.*
>
> *One of the most common stability problems in graphics occurs when a computer appears to "hang" or be completely "frozen" while it's actually processing an end-user command or operation. Many users wait a few seconds and then decide to reboot the computer. The frozen appearance of the computer frequently occurs because the GPU is busy processing intensive graphical operations, typically during game play, and hence doesn't update the display screen. TDRs enable the operating system to detect that the UI isn't responsive.*"
>
> — Microsoft, [WDDM support for timeout detection and recovery (TDR)](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/timeout-detection-and-recovery)

![](https://github.com/nohuto/win-config/blob/main/security/images/tdr-process.jpg?raw=true)

### [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/tdr-registry-keys)

See '[DXG Kernel Values](https://noverse.dev/docs/win-config/system/dxg-kernel-values/#registry-values)' for types and ranges.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    "TdrLevel" = 3;
    "TdrDelay" = 2;
    "TdrDdiDelay" = 5;
    "TdrDebugMode" = 2;
    "TdrLimitTime" = 60;
    "TdrLimitCount" = 5;
    "TdrTestMode" = 0;
    "TdrDodPresentDelay" = 2;
    "TdrDodVSyncDelay" = 2;
```


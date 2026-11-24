# Increase TDR

Turning detection off (`TdrLevel = 0`) removes the recovery, means a hung GPU then freezes the whole system, so rather leave it enabled.

> "*TDR is a feature in Windows that detects when the graphics card takes longer than expected to complete an operation. It then resets the graphics card to prevent the entire system from becoming unresponsive.*
>
> *One of the most common stability problems in graphics occurs when a computer appears to "hang" or be completely "frozen" while it's actually processing an end-user command or operation. Many users wait a few seconds and then decide to reboot the computer. The frozen appearance of the computer frequently occurs because the GPU is busy processing intensive graphical operations, typically during game play, and hence doesn't update the display screen. TDRs enable the operating system to detect that the UI isn't responsive.*"
>
> — Microsoft, [WDDM support for timeout detection and recovery (TDR)](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/timeout-detection-and-recovery)

![](https://github.com/nohuto/win-config/blob/main/security/images/tdr-process.jpg?raw=true)

### [Registry Values](https://learn.microsoft.com/en-us/windows-hardware/drivers/display/tdr-registry-keys)

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers"
    "TdrLevel" = 3; // REG_DWORD, 0/1/3, other = 3
    // "Specifies the initial level of recovery."
    // 0 (TdrLevelOff) = Detection disabled
    // 1 (TdrLevelBugcheck) = Bug check on detected timeout, for example, no recovery
    // 2 (TdrLevelRecoverVGA) = Recover to VGA (not implemented)
    // 3 (TdrLevelRecover) = Recover on timeout (default value)

    "TdrDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the GPU can delay the preempt request from the GPU scheduler. TdrDelay is effectively the timeout threshold."

    "TdrDdiDelay" = 5; // REG_DWORD, range 1-900
    // "Specifies the number of seconds that the OS allows threads to leave the driver. After the specified time, the OS bug-checks the computer with the code VIDEO_TDR_FAILURE (0x116)."

    "TdrDebugMode" = 2; // REG_DWORD, range 0-3, other = 2
    // "Specifies the debugging-related behavior of the TDR process. The default value is TDR_DEBUG_MODE_RECOVER_NO_PROMPT, which indicates not to break into the debugger."
    // 0 = Break to kernel debugger before the recovery to allow investigation of the timeout.
    // 1 = Ignore any timeout.
    // 2 = Recover without breaking into the debugger (default value).
    // 3 = Recover even if some recovery conditions aren't met (for example, recover on consecutive timeouts).

    "TdrLimitTime" = 60; // REG_DWORD, range 5-3600
    // "Specifies the default time within which a specific number of TDRs (specified by the TdrLimitCount key) are allowed without crashing the computer."

    "TdrLimitCount" = 5; // REG_DWORD, range 1-32
    // "Specifies the default number of TDRs (0x117) that the system allows during the time specified by the TdrLimitTime key without crashing the computer."

    // _TdrIsTestMode
    "TdrTestMode" = 0; // REG_DWORD (bool)
    // "Reserved. Don't use."

    // TdrInit
    "TdrDodPresentDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds allowed for the kernel-mode display-only driver's (KMDOD) DxgkDdiPresentDisplayOnly function to complete an asynchronous present by reporting progress to pfnPresentDisplayOnlyProgress (which is passed in the DXGKARG_PRESENT_DISPLAYONLY structure)."

    "TdrDodVSyncDelay" = 2; // REG_DWORD, range 1-900
    // "Specifies the number of seconds the V-sync watchdog waits for a V-sync signal to be reported before triggering a TDR in a KMDOD."
```


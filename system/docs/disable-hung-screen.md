# Disable Hung Screen

Causes hung apps to get automatically get terminated, making the 'Hung program' screen to not show up. It's recommended to leave the timeouts at their default, see 'Windows Internals' section below for more details on each value.

![](https://github.com/nohuto/win-config/blob/main/system/images/hung-program.png?raw=true)

### Registry Values

Windows Internals says that the default of `WaitToKillServiceTimeout` is `20000` ("*The SCM's timeout value in milliseconds resides in the HKLM\SYSTEM\CurrentControlSet\Control\WaitToKillServiceTimeout registry value, and it defaults to 20 seconds.*"), while the value exists by default on W11 with the data of `5000`, when looking at the win32kbase driver it also shows a default of `5000`.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control";
    "WaitToKillServiceTimeout" = 5000; // REG_SZ (ms), SCM timeout used by CSRSS while the SCM notifies services and waits for service cleanup

"HKCU\\Control Panel\\Desktop";
    "WaitToKillTimeout" = 5000; // REG_SZ (ms), time CSRSS waits for a console control handler/process to exit before showing the hung program screen
    "HungAppTimeout" = 5000; // REG_SZ (ms), time CSRSS waits for a GUI thread/process to exit after shutdown messages before seeing it as hung
    "AutoEndTasks" = 0; // REG_SZ,  1 disables the 'Hung program' screen
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/shutdown3.png?raw=true)


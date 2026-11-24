# Disable Auto Maintenance

Runs updates and scans daily when your PC is idle, it helps keep your system secure and efficient without affecting performance. Theres no actual reason to disable it, as it doesn't do anything while being active, however if you've any reason for not wanting it to run the tasks while being in idle, toggle the switch.

You can see your current maintenance tasks with:

```powershell
Get-ScheduledTask | ? {$_.Settings.MaintenanceSettings}
```

Boot trace:

```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Activation Boundary
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : MaintenanceDisabled
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Random Delay
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Randomized
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : WakeUp
```

Without these maintenance runs daily at 02:00 with a random delay of up to 4h and may wake the PC for it (`UbpmpInitializeMaintenanceParameters`: `2000-01-01T02:00:00`, `PT4H`, `WakeUp` 1), `MaintenanceDisabled = 1` stops automatic maintenance, `WakeUp = 0` stops the wake timer.

---

Miscellaneous notes:
```json
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppModel\\StateRepository": {
  "MaintenanceInterval": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\Repository": {
  "MaintenanceInterval": { "Type": "REG_DWORD", "Data": 0 }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Schedule\\Maintenance": {
  "Random Delay": { "Type": "REG_SZ", "Data": "PT0S" },
  "Randomized": { "Type": "REG_DWORD", "Data": 0 }
}
```

`Random Delay` is an ISO 8601 time span (default `PT4H`), `UbpmUtilsParseTimeSpan` (`ubpm.dll`) rejects anything that doesn't start with `P`, and `UbpmpReadMaintenanceSettings` then stops with error 87 before it reads `WakeUp` and `MaintenanceDisabled`:

```c
// UbpmUtilsParseTimeSpan (23H2)

if ( *a1 != 80 ) // 'P'
  return 87;
```


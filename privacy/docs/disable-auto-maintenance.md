# Disable Auto Maintenance

Runs updates and scans daily when your PC is idle, it helps keep your system secure and efficient without affecting performance. Theres no actual reason to disable it, as it doesn't do anything while being active, however if you've any reason for not wanting it to run the tasks while being in idle, toggle the switch.

You can see your current maintenance tasks with:

```powershell
Get-ScheduledTask | ? {$_.Settings.MaintenanceSettings}
```

`SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance` trace:

```
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Activation Boundary
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : MaintenanceDisabled
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Random Delay
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : Randomized
\Registry\Machine\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\Maintenance : WakeUp
```

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
  "Random Delay": { "Type": "REG_DWORD", "Data": 0 },
  "Randomized": { "Type": "REG_DWORD", "Data": 0 }
}
```


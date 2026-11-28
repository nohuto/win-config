# Disable Scheduled Tasks

Disables NVIDIA telemetry tasks recursively, note that the old NVIDIA telemetry container created them, means that these don't exist on newer drivers.

- `NvTmRep.exe` = NVIDIA crash and telemetry reporter
- `NvTmMon` = Sends data on logon, then in a 1H interval
- `NvTmRepOnLogon` = Sends data on logon
- `NvTmRep` = Sends data at 12:25PM daily

```powershell
["NvTmRep_*", "NvTmRepOnLogon*", "NvTmMon_*"]
```


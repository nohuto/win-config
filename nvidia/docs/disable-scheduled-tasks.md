# Disable Scheduled Tasks

Disables NVIDIA scheduled tasks recusively. All 3 tasks no longer seem to be created, I'll leave this option for now.

- `NvTmRep.exe` = NVIDIA crash and telemetry reporter
- `NvTmMon` = Sends data on logon, then in a 1H interval
- `NvTmRepOnLogon` = Sends data on logon
- `NvTmRep` = Sends data at 12:25PM daily

```powershell
["NvTmRep_*", "NvTmRepOnLogon*", "NvTmMon_*"]
```


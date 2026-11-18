# Event Logs

Only do this if you want to export the data elsewhere or purposely delete logs (security logs can't be recovered afterward).

Display all logs via [wevtutil](https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/wevtutil):
```powershell
wevtutil el
```

Command used:
```powershell
$logs = wevtutil el
foreach ($log in $logs) { wevtutil cl $log | Out-Null }
```


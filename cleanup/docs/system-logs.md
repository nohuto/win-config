# System Logs

Cleans up a broad set of Windows log files (setup, component servicing, WMI, firewall, update logs, and related trace files). Use this after troubleshooting or when you want to reduce accumulated log size. This doesn't affect live event logs (see the separate Event Logs option).

Paths removed:
```c
"%WINDIR%\\*.log",
"%ALLUSERSPROFILE%\\Application Data\\Microsoft\\Dr Watson\\*.log",
"%ALLUSERSPROFILE%\\Application Data\\Microsoft\\Dr Watson\\user.dmp",
"%WINDIR%\\debug\\*.log",
"%WINDIR%\\debug\\PASSWD.LOG",
"%WINDIR%\\debug\\Setup\\UpdSh.log",
"%WINDIR%\\debug\\UserMode\\*.log",
"%WINDIR%\\debug\\UserMode\\ChkAcc.bak",
"%WINDIR%\\debug\\UserMode\\userenv.bak",
"%LOCALAPPDATA%\\Microsoft\\Internet Explorer\\brndlog.bak",
"%LOCALAPPDATA%\\Microsoft\\Internet Explorer\\brndlog.txt",
"%WINDIR%\\Logs\\CBS",
"%WINDIR%\\Logs\\DISM",
"%WINDIR%\\Logs\\NetSetup",
"%WINDIR%\\Logs\\SIH",
"%WINDIR%\\Logs\\waasmedic",
"%WINDIR%\\Microsoft.NET\\Framework\\*\\*.log",
"%WINDIR%\\ntbtlog.txt", // bcdedit /set bootlog Yes
"%WINDIR%\\OEWABLog.txt",
"%WINDIR%\\REGLOCS.OLD",
"%WINDIR%\\SchedLgU.txt",
"%WINDIR%\\security\\logs\\*.log",
"%WINDIR%\\security\\logs\\*.old",
"%WINDIR%\\setuplog.txt",
"%WINDIR%\\SoftwareDistribution\\*.log",
"%WINDIR%\\SoftwareDistribution\\DataStore\\Logs\\*",
"%WINDIR%\\System32\\*.log",
"%WINDIR%\\System32\\TZLog.log",
"%WINDIR%\\System32\\config\\systemprofile\\Application Data\\Microsoft\\Internet Explorer\\brndlog.bak",
"%WINDIR%\\System32\\config\\systemprofile\\Application Data\\Microsoft\\Internet Explorer\\brndlog.txt",
"%WINDIR%\\System32\\LogFiles\\AIT\\AitEventLog.etl.???",
"%WINDIR%\\System32\\LogFiles\\Firewall\\pfirewall.log*",
"%WINDIR%\\System32\\LogFiles\\Scm\\SCM.EVM*",
"%WINDIR%\\System32\\LogFiles\\setupcln",
"%WINDIR%\\System32\\LogFiles\\WMI",
"%WINDIR%\\System32\\LogFiles\\WMI\\Terminal*.etl",
"%WINDIR%\\System32\\LogFiles\\WMI\\RTBackup\\EtwRT.*etl",
"%WINDIR%\\System32\\wbem\\Logs\\*.lo_",
"%WINDIR%\\System32\\wbem\\Logs\\*.log"
```

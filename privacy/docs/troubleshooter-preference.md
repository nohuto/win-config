# Troubleshooter Preference

Without a `UserPreference` value `MitigationClient.dll` uses a OneSettings value first, then `Ask me before running` on Insider builds, then an edition default (`Ask me before running` on Home/Pro, `Don't run any` on Enterprise/Education).

| Option | Description |
| ---- | ---- |
| Run automatically, don't notify me | Windows will automatically run recommended troubleshooters for problems detected on your device without bothering you. |
| Run automatically, then notify me | Windows will tell you after recommended troubleshooters have solved a problem so you know what happened. |
| Ask me before running (default on Home/Pro) | We'll let you know when recommended troubleshooting is available. You can review the problem and changes before running the troubleshooters. |
| Don't run any | Turns troubleshooting off completely, critical troubleshooters included. |

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `DPS` | The Diagnostic Policy Service enables problem detection, troubleshooting and resolution for Windows components. If this service is stopped, diagnostics will no longer function. | Win32 Share Process (32) | - | C:\Windows\System32\svchost.exe -k LocalServiceNoNetwork -p |
| `TroubleshootingSvc` | Enables automatic mitigation for known problems by applying recommended troubleshooting. If stopped, your device will not get recommended troubleshooting for problems on your device. | Win32 Share Process (32) | rpcss | C:\Windows\system32\svchost.exe -k netsvcs -p |
| `diagsvc` | Executes diagnostic actions for troubleshooting support | Win32 Share Process (32) | RpcSs | C:\Windows\System32\svchost.exe -k diagnostics |

### SystemSettings Captures

`System > Troubleshoot` - `Recommended troubleshooter preferences`:
```c
// Don't run any
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 1

// Ask me before running (default)
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 2

// Run automatically, then notify me
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 3

// Run automatically, don't notify me
HKLM\SOFTWARE\Microsoft\WindowsMitigation\UserPreference	Type: REG_DWORD, Length: 4, Data: 4
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Microsoft Support Diagnostic Tool: Turn on MSDT interactive communication with support provider](https://noverse.dev/policies?p=MSDT*MsdtSupportProvider) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnosticsProvider\Policy` | `DisableQueryRemoteServer` |
| [Troubleshooting: Allow users to access and run Troubleshooting Wizards](https://noverse.dev/policies?p=sdiageng*ScriptedDiagnosticsExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnostics` | `EnableDiagnostics` |
| [Troubleshooting: Allow users to access online troubleshooting content on Microsoft servers from the Troubleshooting Control Panel (via the Windows Online Troubleshooting Service - WOTS)](https://noverse.dev/policies?p=sdiageng*BetterWhenConnected) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScriptedDiagnosticsProvider\Policy` | `EnableQueryRemoteServer` |
| [Troubleshooting: Allow users to access recommended troubleshooting for known problems](https://noverse.dev/policies?p=MSDT*TroubleshootingAllowRecommendations) | `HKLM\Software\Policies\Microsoft\Windows\Troubleshooting\AllowRecommendations` | `TroubleshootingAllowRecommendations` |
| [Configure Scheduled Maintenance Behavior](https://noverse.dev/policies?p=sdiagschd*ScheduledDiagnosticsExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\ScheduledDiagnostics` | `EnabledExecution`<br>`EnabledExecutionLevel` |
| [Diagnostics: Configure scenario execution level](https://noverse.dev/policies?p=WDI*WdiDpsScenarioExecutionPolicy) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WDI` | `ScenarioExecutionEnabled`<br>`EnabledScenarioExecutionLevel` |


# PS Execution Policy

> "*PowerShell execution policy is a safety feature that controls when PowerShell loads configuration files and runs scripts, helping prevent accidental execution of malicious scripts.*
>
> *On Windows, you can set it for the local computer, current user, a single session, or through Group Policy. Local computer and current user policies are stored in PowerShell configuration files, while session policy exists only in memory until the session closes.*
>
> *It is not a real security boundary, since users can bypass it, but it helps enforce basic rules and avoid accidental misuse.*
>
> *On non-Windows systems, the reported default is `Unrestricted` and cannot be changed, though the actual behavior is closer to `Bypass` because Windows security zones do not exist there.*"
>
> — Microsoft, [about_Execution_Policies](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5)

### [Execution Policy](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5)

| **Execution Policy**  | **Description** |
| ---- | ---- |
| `AllSigned` | All scripts must be signed by a trusted publisher. Prompts for untrusted publishers. |
| `Bypass` | No prompts or restrictions. Used in apps or environments with their own security. |
| `Default` | Acts like `RemoteSigned` on Windows. |
| `RemoteSigned` | Scripts run freely unless downloaded from the internet. Internet scripts need a trusted signature or must be unblocked. Local scripts don't require signatures. |
| `Restricted` | No scripts allowed (only individual commands). Blocks all `.ps1`, `.psm1`, `.ps1xml`, and profile scripts. |
| `Undefined` | No policy in this scope. If all scopes are undefined, defaults to `Restricted` (clients) or `RemoteSigned` (servers). |
| `Unrestricted` | Unsigned scripts can run. Prompts for scripts from outside the intranet zone. |

### Scope

| **Scope** | **Description** |
|---- | ---- |
| `MachinePolicy` | Set by a Group Policy for all users of the computer |
| `UserPolicy` | Set by a Group Policy for the current user of the computer |
| `Process` | Sets the execution policy only for the current session - stored in an environment variable & removed when the session ends |
| `CurrentUser` | The execution policy affects only the current user - stored in the HKCU subkey |
| `LocalMachine` | The execution policy affects all users on the current computer - stored in the HKLM subkey |

### [Registry Values](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_powershell_config?view=powershell-7.5)

| **Value Name** | **Description** |
| ---- | ---- |
| `EnableScriptBlockLogging` | Enables or disables logging of PowerShell script input to the event log. If enabled, it logs the processing of commands, script blocks, functions, and scripts. |
| `EnableScriptBlockInvocationLogging` | Enables or disables logging of invocation events for commands, script blocks, functions, or scripts. Enabling this generates high volume of event logs for start/stop events. |
| `EnableModuleLogging` | Enables or disables logging of pipeline execution events for specified PowerShell modules. If enabled, logs events in Event Viewer for the specified modules. |
| `EnableTranscripting` | Enables or disables transcription of PowerShell commands. If enabled, records the input and output of PowerShell commands into text-based transcripts stored by default in My Documents. |
| `EnableScripts` | Controls which types of scripts are allowed to run on the system. Options include allowing only signed scripts, allowing local scripts and remote signed scripts, or allowing all scripts to run. |

See your current execution policies via:
```powershell
Get-ExecutionPolicy -List
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn on Script Execution](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableScripts) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell` | `EnableScripts`<br>`ExecutionPolicy` |
| [Turn on Module Logging](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableModuleLogging) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\ModuleLogging`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\ModuleLogging` | `EnableModuleLogging` |
| [Turn on PowerShell Transcription](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableTranscripting) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\Transcription`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\Transcription` | `EnableTranscripting`<br>`OutputDirectory`<br>`EnableInvocationHeader` |
| [Turn on PowerShell Script Block Logging](https://noverse.dev/policies?p=PowerShellExecutionPolicy*EnableScriptBlockLogging) | `HKLM\Software\Policies\Microsoft\Windows\PowerShell\ScriptBlockLogging`<br>`HKCU\Software\Policies\Microsoft\Windows\PowerShell\ScriptBlockLogging` | `EnableScriptBlockLogging`<br>`EnableScriptBlockInvocationLogging` |


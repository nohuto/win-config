# Disable PowerShell & .NET Telemetry

### [POWERSHELL_TELEMETRY_OPTOUT](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_telemetry?view=powershell-7.5)

> "*At startup, PowerShell sends diagnostic data including OS manufacturer, name, and version; PowerShell version; `POWERSHELL_DISTRIBUTION_CHANNEL`; Application Insights SDK version; approximate location from IP; command-line parameters (without values); current Execution Policy; and randomly generated GUIDs for the user and session.*"

```bat
setx POWERSHELL_TELEMETRY_OPTOUT 1
```

The var only affects PS 7 (`pwsh`).

### [DOTNET_CLI_TELEMETRY_OPTOUT](https://learn.microsoft.com/en-us/dotnet/core/tools/telemetry#how-to-opt-out)

> "*To opt out after you started the installer: close the installer, set the environment variable, and then run the installer again with that value set.*"

```bat
setx DOTNET_CLI_TELEMETRY_OPTOUT 1
```

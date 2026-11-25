# Disable OneSettings Download

[Services Configuration](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#31-services-configuration) is used by Windows components and apps, such as the telemetry service, to dynamically update their configuration. If you turn off this service, apps using this service may stop working.

If enabled = "Windows will periodically attempt to connect with the OneSettings service to download configuration settings".

---

The policy doesn't seem stop every OneSettings request, e.g. on 23H2 only `OneSettingsClient.dll`, `DiagnosticDataSettings.dll`, `KernelBase.dll`, `SettingsHandlers_SIUF.dll` include the value name, while 30 binaries have `settings-win.data.microsoft.com` built in (e.g. `diagtrack.dll`, `appraiser.dll`, `InstallService.dll`, `QualityUpdateAssistant.dll`). 

With the privacy configuration preset applied on stock 25H2, WU (`MoUsoCoreWorker.exe`, `WaaSMedicSvc`, `wuauserv`) still looked up `settings-win.data.microsoft.com`, so this only applies for some parts.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable OneSettings Auditing](https://noverse.dev/policies?p=DataCollection*EnableOneSettingsAuditing) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `EnableOneSettingsAuditing` |
| [Disable OneSettings Downloads](https://noverse.dev/policies?p=DataCollection*DisableOneSettingsDownloads) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableOneSettingsDownloads` |

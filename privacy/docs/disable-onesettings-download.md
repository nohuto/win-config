# Disable OneSettings Download

[Services Configuration](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#31-services-configuration) is used by Windows components and apps, such as the telemetry service, to dynamically update their configuration. If you turn off this service, apps using this service may stop working.

If enabled = "Windows will periodically attempt to connect with the OneSettings service to download configuration settings".

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable OneSettings Auditing](https://noverse.dev/policies?p=DataCollection*EnableOneSettingsAuditing) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `EnableOneSettingsAuditing` |
| [Disable OneSettings Downloads](https://noverse.dev/policies?p=DataCollection*DisableOneSettingsDownloads) | `HKLM\Software\Policies\Microsoft\Windows\DataCollection` | `DisableOneSettingsDownloads` |

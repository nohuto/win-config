# Disable Time Sync

Stops Windows from correcting the system clock through network time sources (the clock continues running from the hardware clock, but it may become inaccurate and eventually cause incorrect timestamps, certificate/sign-in errors, invalid authentication codes, or unreliable scheduled tasks). You can change your time zone via `System > Time Zone`.

| Service/Task | Description |
| --- | --- |
| `W32Time` | Maintains date and time synchronization on all clients and servers in the network. If this service is stopped, date and time synchronization will be unavailable. If this service is disabled, any services that explicitly depend on it will fail to start. |
| `\Microsoft\Windows\Time Synchronization\ForceSynchronizeTime` | Forces Windows to synchronize the system clock. |
| `\Microsoft\Windows\Time Synchronization\SynchronizeTime` | Starts `W32Time` to perform scheduled time synchronization. |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Windows NTP Client](https://noverse.dev/policies?p=W32Time*W32TIME_POLICY_ENABLE_NTPCLIENT) | `HKLM\Software\Policies\Microsoft\W32Time\TimeProviders\NtpClient` | `Enabled` |


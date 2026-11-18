# Disable Cortana

Cortana is [deprecated](https://support.microsoft.com/en-us/cortana/end-of-support-for-cortana) in W11 and is no longer the supported voice assistant.

> "*[Cortana](https://en.wikipedia.org/wiki/Cortana_(virtual_assistant)) was a virtual assistant developed by Microsoft that used the Bing search engine to perform tasks such as setting reminders and answering questions for users.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Cortana](https://noverse.dev/policies?p=Search*AllowCortana) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCortana` |
| [Allow Cortana above lock screen](https://noverse.dev/policies?p=Search*AllowCortanaAboveLock) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCortanaAboveLock` |
| [Allow search and Cortana to use location](https://noverse.dev/policies?p=Search*AllowSearchToUseLocation) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowSearchToUseLocation` |
| [Allow Cloud Search](https://noverse.dev/policies?p=Search*AllowCloudSearch) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search` | `AllowCloudSearch` |
| [Allow Cortana Page in OOBE on an AAD account](https://noverse.dev/policies?p=Search*AllowCortanaInAAD) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Windows Search\AllowCortanaInAAD` | `AllowCortanaInAADPathOOBE` |

## Miscellaneous Notes
```c
"HKCU\Software\Microsoft\Windows\CurrentVersion\Cortana\DevOverrideOneSettings","Length: 16"
"HKCU\Software\Microsoft\Windows\CurrentVersion\Cortana\IsAvailable","Type: REG_DWORD, Length: 4, Data: 1"
```


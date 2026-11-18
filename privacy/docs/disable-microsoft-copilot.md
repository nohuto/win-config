# Disable Microsoft Copilot

> "*Microsoft introduced Windows Copilot in May 2023. It became available in Windows 11 starting with build 23493 (Dev), 22631.2129 (Beta), and 25982 (Canary). A public preview began rolling out on September 26, 2023, with build 22621.2361 (Windows 11 22H2 KB5030310). It adds integrated AI features to assist with tasks like summarizing web content, writing, and generating images. Windows Copilot appears as a sidebar docked to the right and runs alongside open apps. In Windows 10, Copilot is available in build 19045.3754 for eligible devices in the Release Preview Channel running version 22H2. Users must enable "Get the latest updates as soon as they're available" and check for updates. The rollout is phased via Controlled Feature Rollout (CFR). Windows 10 Pro devices managed by organizations, and all Enterprise or Education editions, are excluded from the initial rollout. Copilot requires signing in with a Microsoft account (MSA) or Azure Active Directory (Entra ID). Users with local accounts can use Copilot up to ten times before sign-in is enforced.*"

`CopilotDisabledReason`:
```c
ValueW = RegGetValueW(
    HKEY_CURRENT_USER,
    L"SOFTWARE\\Microsoft\\Windows\\Shell\\Copilot",
    L"CopilotDisabledReason",
    2u, // REG_SZ
    0LL,
    pvData,
    pcbData);

v16 = L"FailedToGetReason"; // if value is missing
```

```json
"HKCU\\SOFTWARE\\Microsoft\\Windows\\Shell\\Copilot": {
  "CopilotDisabledReason": { "Type": "REG_SZ", "Data": "FeatureIsDisabled" }
}
```

`FeatureIsDisabled` seems to be used by default here (`IsRequiredEdgeBrowserInstalledFailed` exists too):

```c
// procmon boot trace (value unset)
"Explorer.EXE","HKCU\Software\Microsoft\Windows\Shell\Copilot\CopilotDisabledReason","SUCCESS","Type: REG_SZ, Length: 36, Data: FeatureIsDisabled"

// ?
"HKCU\Software\Microsoft\Windows\Shell\Copilot\CopilotLogonTelemetryTime","Type: REG_BINARY, Length: 8, Data: 7A 84 DA 49 6B 89 DC 01"
```

---

Miscellaneous notes:
```c
"OneDrive.exe","HKCU\Software\Microsoft\OneDrive\Accounts\Personal\CopilotEducationalExperienceInfoIconDismissed","NAME NOT FOUND","Length: 16"
"MicrosoftEdgeUpdate.exe","HKLM\SOFTWARE\WOW6432Node\Microsoft\EdgeUpdate\CopilotUpgradeCheck","NAME NOT FOUND","Length: 16"
"Explorer.EXE","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoInstalledPWAs\CopilotHWKeyChoiceSet","SUCCESS","Type: REG_DWORD, Length: 4, Data: 1"
"Explorer.EXE","HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\AutoInstalledPWAs\CopilotPWAPreinstallCompleted","SUCCESS","Type: REG_DWORD, Length: 4, Data: 1"
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Windows Copilot](https://noverse.dev/policies?p=WindowsCopilot*TurnOffWindowsCopilot) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsCopilot` | `TurnOffWindowsCopilot` |
| [Set Copilot Hardware Key](https://noverse.dev/policies?p=WindowsCopilot*SetCopilotHardwareKey) | `HKCU\SOFTWARE\Policies\Microsoft\Windows\CopilotKey` | `SetCopilotHardwareKey` |
| [Disable Image Creator](https://noverse.dev/policies?p=WindowsCopilot*DisableImageCreator) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableImageCreator` |
| [Disable Cocreator](https://noverse.dev/policies?p=WindowsCopilot*DisableCocreator) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableCocreator` |
| [Disable generative fill](https://noverse.dev/policies?p=WindowsCopilot*DisableGenerativeFill) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Paint` | `DisableGenerativeFill` |


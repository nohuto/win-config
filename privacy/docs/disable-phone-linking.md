# Disable Phone Linking

> "*This policy allows IT admins to turn off the ability to Link a Phone with a PC to continue reading, emailing and other tasks that requires linking between Phone and PC.If you enable this policy setting, the Windows device will be able to enroll in Phone-PC linking functionality and participate in Continue on PC experiences.If you disable this policy setting, the Windows device is not allowed to be linked to Phones, will remove itself from the device list of any linked Phones, and cannot participate in Continue on PC experiences.If you do not configure this policy setting, the default behavior depends on the Windows edition. Changes to this policy take effect on reboot.*"

### SystemSettings Captures

This option will also disable resume ("Start something on one device and continue on this PC") - `System Settings > Apps > Resume`.

```c
// Off
HKCU\Software\Microsoft\Windows\CurrentVersion\CrossDeviceResume\Configuration\IsResumeAllowed	Type: REG_DWORD, Length: 4, Data: 0

// On
HKCU\Software\Microsoft\Windows\CurrentVersion\CrossDeviceResume\Configuration\IsResumeAllowed	Type: REG_DWORD, Length: 4, Data: 1
```

By default resume is enabled, OneDrive is the only app which exists under the "Control which apps can use Resume" on a stock 25H2 installation and can be toggled via `IsOneDriveResumeAllowed` (same key as `IsResumeAllowed`). Disabling resume will disallow all apps to use Resume (doesn't set `IsXResumeAllowed` to `0`).

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Phone-PC linking on this device](https://noverse.dev/policies?p=GroupPolicy*EnableMMX) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableMmx` |


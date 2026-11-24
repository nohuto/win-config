# Disable Cross-Device Experiences

Disables Cross-Device experiences (allows you to use `Share Across Devices`/`Nearby Sharing` functionalities) & share across devices. With `Share across devices`, you can continue app experiences on other devices connected to your account (set to `My device only` by default).

### SystemSettings Captures

Changing "Share across devices" option via `SystemSettings`:

```c
// Off
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 0
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 0

// My device only
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\SettingsPage\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 1

// Everyone nearby
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\SettingsPage\RomeSdkChannelUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\CdpSessionUserAuthzPolicy	Type: REG_DWORD, Length: 4, Data: 2

// Miscellaneous note
HKCU\Software\Microsoft\Windows\CurrentVersion\CDP\EnableRemoteLaunchToast  Type: REG_DWORD, Length: 4, Data: 1
```

`RomeSdkChannelUserAuthzPolicy` (`CDP\SettingsPage`) is only used for "My device only"/"Everyone nearby" (it's still getting changed to `0` in this option).

```c
L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"BluetoothLastDisabledNearShare",

L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CDP\\SettingsPage",
L"WifiLastDisabledNearShare",
```

Settings writes these two values when it turns 'Nearby sharing' off as Bluetooth (`BluetoothLastDisabledNearShare`) or Wi-Fi (`WifiLastDisabledNearShare`) were disabled, these seem to only control toasts (I guess).

- [privacy/assets/pseudocode | crossdev-SharedExperiencesSingleton.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/crossdev-SharedExperiencesSingleton.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Continue experiences on this device](https://noverse.dev/policies?p=GroupPolicy*EnableCDP) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableCdp` |


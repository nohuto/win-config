# Disable Find My Device

> "*Find My Device is a feature that can help you locate your Windows 10 or Windows 11 device if it's lost or stolen. To use this feature, sign in to your device with a Microsoft account and make sure you're an administrator on it. This feature works when location is turned on for your device, even if other users on the device have turned off location settings for their apps. Any time you attempt to locate the device, users using the device will see a notification in the notification area.*
>
> *- This setting works for any Windows device, such as a PC, laptop, Surface, or Surface Pen. It needs to be turned on before you can use it.*  
> *- You can't use it with a work or school account, and it doesn't work for iOS devices, Android devices, or Xbox One consoles.*"
>
> — Microsoft, [Find and lock a lost Windows device](https://support.microsoft.com/en-us/accounts-billing/security/find-and-lock-a-lost-windows-device)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn On/Off Find My Device](https://noverse.dev/policies?p=FindMy*FindMy_AllowFindMyDeviceConfig) | `HKLM\SOFTWARE\Policies\Microsoft\FindMyDevice` | `AllowFindMyDevice` |

## Pen Location

`InputService.dll` starts it for every user and, while a pen is used, writes the device location to `HKCU\Software\Microsoft\Windows NT\CurrentVersion\Windows\Pen\PLOC` `LOC` (every 3min unless `TrackInterval` got changed). It only checks `TrackingEnabled`, which is missing by default (tracking on), only the '*Find my device*' Settings page writes it.

```c
"HKCU\\Software\\Microsoft\\Windows NT\\CurrentVersion\\Windows\\Pen\\PLOC\\Settings";
    "TrackingEnabled" = 1; // REG_DWORD
    "TrackInterval" = 3; // REG_DWORD
```

```c
// InputTracker::LoadSettings (23H2)

v2 = 1;
LOBYTE(v5) = 1; // tracking on when TrackingEnabled is missing
if ( (int)InputTrackerUtils::GetLocationTrackingEnabled((bool *)&v5) >= 0 )
  v2 = v5;
v5 = 0LL;
*((_BYTE *)this + 64) = v2;
```

```c
// InputTracker::OnInputWnf (23H2)

v5 = *((_BYTE *)this + 64) == 0;
*((_QWORD *)this + 6) = v4;
*((FILETIME *)this + 13) = v3;
if ( v5 )
  return 0LL; // TrackingEnabled = 0, no RecordPenLocation
```


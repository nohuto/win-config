# Disable Location Access

Disables app access to your location, locating your system will be disabled, geolocation service gets disabled.

`Privacy & security` > `Location`:
```powershell
"Process Name","Operation","Path","Detail"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\NonPackaged\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\ShowGlobalPrompts","Type: REG_DWORD, Length: 4, Data: 1"
```

- [privacy/assets/pseudocode | locationaccess-LocationApi.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/locationaccess-LocationApi.c)

---

There's also a value named `CSEnable` which I found in `srms.dat`, it doesn't seem to exist anymore.

```html
<!-- Help improve Microsoft services by sending some location data when you use location-aware apps -->
<pattern type="Registry">HKLM\Software\Microsoft\Sensors\LocationProvider [CSEnable]</pattern>
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Let Windows apps access location](https://noverse.dev/policies?p=AppPrivacy*LetAppsAccessLocation) | `HKLM\Software\Policies\Microsoft\Windows\AppPrivacy` | `LetAppsAccessLocation` |
| [Turn off Windows Location Provider](https://noverse.dev/policies?p=LocationProviderAdm*DisableWindowsLocationProvider_1) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableWindowsLocationProvider` |
| [Turn off sensors](https://noverse.dev/policies?p=Sensors*DisableSensors_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableSensors` |
| [Turn off location](https://noverse.dev/policies?p=Sensors*DisableLocation_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocation` |
| [Turn off location scripting](https://noverse.dev/policies?p=Sensors*DisableLocationScripting_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocationScripting` |


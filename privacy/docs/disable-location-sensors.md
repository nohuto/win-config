# Disable Location & Sensors

Disables app access to your location, locating your system will be disabled, geolocation service gets disabled.

Blocks apps/system from using hardware sensors such as ambient light, orientation, and other motion/position sensors (features like adaptive brightness, auto rotation and sensor based behaviors will no longer work).

`Privacy & security` > `Location`:
```powershell
"Process Name","Operation","Path","Detail"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\NonPackaged\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\Value","Type: REG_SZ, Length: 10, Data: Deny"
"svchost.exe","RegSetValue","HKCU\Software\Microsoft\Windows\CurrentVersion\CapabilityAccessManager\ConsentStore\location\ShowGlobalPrompts","Type: REG_DWORD, Length: 4, Data: 1" #24H2+
```

- [privacy/assets/pseudocode | locationaccess-LocationApi.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/locationaccess-LocationApi.c)

> "*This policy setting turns off the sensor feature for this computer. If you enable this policy setting, the sensor feature is turned off, and all programs on this computer can't use the sensor feature.*"

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `SensorDataService` | Delivers data from a variety of sensors | Win32 Own Process (16) | - | C:\Windows\System32\SensorDataService.exe |
| `SensrSvc` | Monitors various sensors in order to expose data and adapt to system and user state. If this service is stopped or disabled, the display brightness will not adapt to lighting conditions. Stopping this service may affect other system functionality and features as well. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalServiceAndNoImpersonation -p |
| `SensorService` | A service for sensors that manages different sensors' functionality. Manages Simple Device Orientation (SDO) and History for sensors. Loads the SDO sensor that reports device orientation changes. If this service is stopped or disabled, the SDO sensor will not be loaded and so auto-rotation will not occur. History collection from Sensors will also be stopped. | Win32 Share Process (32) | - | C:\Windows\system32\svchost.exe -k LocalSystemNetworkRestricted -p |

No other [services](https://github.com/nohuto/win-config/blob/main/system/assets/reference/services.txt)/[drivers](https://github.com/nohuto/win-config/blob/main/system/assets/reference/drivers.txt) depend on these three services.

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
| [Turn off sensors](https://noverse.dev/policies?p=Sensors*DisableSensors_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableSensors` |
| [Turn off location](https://noverse.dev/policies?p=Sensors*DisableLocation_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocation` |
| [Turn off location scripting](https://noverse.dev/policies?p=Sensors*DisableLocationScripting_2) | `HKLM\Software\Policies\Microsoft\Windows\LocationAndSensors` | `DisableLocationScripting` |

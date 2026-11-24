# Enable Camera OSD Indicator

> "*`NoPhysicalCameraLED` indicates that there is no physical LED for the device's camera. An example of a physical LED for a camera is the small blue light that turns on whenever the camera is streaming video. This setting is used to indicate to the shell component that it will need to provide a small indicator in the user interface (UI) to show when video frames are streaming or not streaming to replace the notification by physical LED.*"
>
> — Microsoft, [NoPhysicalCameraLED](https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/microsoft-windows-coremmres-nophysicalcameraled)

![](https://github.com/nohuto/win-config/blob/main/security/images/cameraosd.png?raw=true)

| Value | Meaning |
| :---: | --- |
| 0 | Does not draw an indicator in the UI to show when the camera is on or off. Instead, a physical LED exists to show when video frames are streaming or not streaming. This is the default value. |
| 1 | Draws an indicator in the UI to show when video frames are streaming or not streaming. |

`ks.sys` (kernel streaming) reads it `KspGetNotification`:

```c
// KspGetNotification (23H2)

  RtlInitUnicodeString(&DestinationString, L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\OEM\\Device\\Capture");
  RtlInitUnicodeString(&ValueName, L"NoPhysicalCameraLED");
```
```c
// KspGetNotification (23H2)

        if ( ZwQueryValueKey(KeyHandle, &ValueName, KeyValuePartialInformation, v3, Length, &Length) >= 0
          && v3[1] == 4 // REG_DWORD
          && v3[2] == 4 ) // 4 bytes
        {
          v2 = v3[3] != 0; // any nonzero value draws indicator
        }
```

# Disable Find My Device

> "*Find My Device is a feature that can help you locate your Windows 10 or Windows 11 device if it's lost or stolen. To use this feature, sign in to your device with a Microsoft account and make sure you're an administrator on it. This feature works when location is turned on for your device, even if other users on the device have turned off location settings for their apps. Any time you attempt to locate the device, users using the device will see a notification in the notification area.*
>
> *- This setting works for any Windows device, such as a PC, laptop, Surface, or Surface Pen. It needs to be turned on before you can use it.*  
> *- You can't use it with a work or school account, and it doesn't work for iOS devices, Android devices, or Xbox One consoles.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn On/Off Find My Device](https://noverse.dev/policies?p=FindMy*FindMy_AllowFindMyDeviceConfig) | `HKLM\SOFTWARE\Policies\Microsoft\FindMyDevice` | `AllowFindMyDevice` |


# Disable Clipboard

If you copy or cut something it gets stored to your clipboard, see policies below for more details.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cbdhsvc` | This user service is used for Clipboard scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k ClipboardSvcGroup -p |

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Clipboard synchronization across devices](https://noverse.dev/policies?p=OSPolicy*AllowCrossDeviceClipboard) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowCrossDeviceClipboard` |
| [Allow Clipboard History](https://noverse.dev/policies?p=OSPolicy*AllowClipboardHistory) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowClipboardHistory` |
| [Do not allow Clipboard redirection](https://noverse.dev/policies?p=TerminalServer*TS_CLIENT_CLIPBOARD) | `HKLM\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services` | `fDisableClip` |
| [Allow clipboard sharing with Windows Sandbox](https://noverse.dev/policies?p=WindowsSandbox*AllowClipboardRedirection) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Sandbox` | `AllowClipboardRedirection` |


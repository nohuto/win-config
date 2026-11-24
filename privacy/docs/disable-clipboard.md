# Disable Clipboard

If you copy or cut something it gets stored to your clipboard, the option turns off clipboard history and the Win+V panel (`EnableClipboardHistory`, `AllowClipboardHistory`), cloud clipboard sync (`CloudClipboardAutomaticUpload`, `AllowCrossDeviceClipboard`), clipboard redirection into *Remote Desktop* sessions and *Windows Sandbox*, and disables the clipboard user service (`cbdhsvc`).

Plain copy & paste in desktop apps keeps working.

| Name | Description | Type | Dependencies | Command Line |
| --- | --- | --- | --- | --- |
| `cbdhsvc` | This user service is used for Clipboard scenarios | Win32 Share Process, User Service (96) | - | C:\Windows\system32\svchost.exe -k ClipboardSvcGroup -p |

Note that `PastedFromClipboardUI = 0` isn't a bool or whatever, the clipboard UI sets it after a paste from Win+V (`ClipboardSettingsImpl::put_PastedFromClipboardUI` in `cbdhsvc.dll`), and a missing value reads as 0, menas that just resets it:

```c
// ClipboardSettingsImpl::LoadRegValues (23H2)

*((_BYTE *)this + 73) = (unsigned int)ClipboardSettingsImpl::GetClipboardDWORDRegValue(
                                        v5,
                                        L"PastedFromClipboardUI",
                                        0) != 0; // 0 = fallback for a missing value
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Clipboard synchronization across devices](https://noverse.dev/policies?p=OSPolicy*AllowCrossDeviceClipboard) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowCrossDeviceClipboard` |
| [Allow Clipboard History](https://noverse.dev/policies?p=OSPolicy*AllowClipboardHistory) | `HKLM\Software\Policies\Microsoft\Windows\System` | `AllowClipboardHistory` |
| [Do not allow Clipboard redirection](https://noverse.dev/policies?p=TerminalServer*TS_CLIENT_CLIPBOARD) | `HKLM\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services` | `fDisableClip` |
| [Allow clipboard sharing with Windows Sandbox](https://noverse.dev/policies?p=WindowsSandbox*AllowClipboardRedirection) (only exists with 'Windows Sandbox' installed) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\Sandbox` | `AllowClipboardRedirection` |

# Disable Bitlocker & EFS

Windows turns on device encryption automatically on devices that qualify (after OOBE, or later), `PreventDeviceEncryption` stops that ([BitLocker overview](https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/#disable-device-encryption)).

> "*BitLocker is a Windows security feature that provides encryption for entire volumes, addressing the threats of data theft or exposure from lost, stolen, or inappropriately decommissioned devices.*
>
> *Data on a lost or stolen device is vulnerable to unauthorized access, either by running a software-attack tool against it, or by transferring the device's hard drive to a different device. BitLocker helps mitigate unauthorized data access by enhancing file and system protections, rendering data inaccessible when BitLocker-protected devices are decommissioned or recycled.*
>
> — Microsoft, [BitLocker overview](https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/)

Drives that are already encrypted stay encrypted, decrypt them with:

```powershell
$nvbvol = Get-BitLockerVolume
Disable-BitLocker -MountPoint $nvbvol
```

## NtfsDisableEncryption Notes

`fsutil behavior set disableencryption 1` sets:
```powershell
fsutil.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\FileSystem\NtfsDisableEncryption	Type: REG_DWORD, Length: 4, Data: 1
```
```
\Registry\Machine\SYSTEM\ControlSet001\Policies : NtfsDisableEncryption
\Registry\Machine\SYSTEM\ControlSet001\Control\FileSystem : NtfsDisableEncryption
```

### 0x8007177E Error

Enabling `NtfsDisableEncryption` (`1`) may cause Xbox games to fail to install (error code `0x8007177E` - "Allow encryption on selected disk volume to install this game"):

```c
#define ERROR_VOLUME_NOT_SUPPORT_EFS     6014L // 0x177E, HRESULT 0x8007177E, "The disk partition does not support file encryption."
```

- Microsoft, [System Error Codes (6000-8199)](https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--6000-8199-)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not allow encryption on all NTFS volumes](https://noverse.dev/policies?p=FileSys*DisableEncryption) | `HKLM\System\CurrentControlSet\Policies` | `NtfsDisableEncryption` |

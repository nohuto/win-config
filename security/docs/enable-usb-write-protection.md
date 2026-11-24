# Enable USB Write Protection

Denies write access to removable disks (USB sticks, SD cards) through the [Removable Disks: Deny write access](https://noverse.dev/policies?p=RemovableStorage*RemovableDisks_DenyWrite_Access_1) policy & `WriteProtect` (reconnect the device afterwards). You can also change it with `diskpart`, by selecting the disk with `select disk` and changing it to read only with `attributes disk set readonly` (revert it with `attributes disk clear readonly`).

The suboption turns off Settings > Bluetooth & devices > USB > Connection notifications, rather leave it enabled unless there's a specific reason.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Removable Disks: Deny write access](https://noverse.dev/policies?p=RemovableStorage*RemovableDisks_DenyWrite_Access_1) | `HKLM\Software\Policies\Microsoft\Windows\RemovableStorageDevices\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}`<br>`HKCU\Software\Policies\Microsoft\Windows\RemovableStorageDevices\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}` | `Deny_Write` |


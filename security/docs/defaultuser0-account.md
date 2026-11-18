# defaultuser0 Account

defaultuser0 is a temporary Windows setup account.

### Miscellaneous Notes

If extracting the whole System32 folder recursively using [strings2](https://github.com/nohuto/strings2-tui) you'll see that the string `defaultuser0` only exists in `DeviceEnroller.exe` (at least for me). The notes below are based on several decompiled functions from `DeviceEnroller.exe` (`MakeActiveUserLocalAdmin`).

`defaultuser0` is only used as a "do not elevate" sentinel in the admin promotion path.

```c
// WinMainCommon
if (!HasActiveLocalAdminAccount()) {
    MakeActiveUserLocalAdmin();
}
```
```c
// MakeActiveUserLocalAdmin
DmGetActiveUserSid(&StringSid);
LookupAccountSidW(..., &name, &domain, ...);
if (_wcsicmp(name, L"defaultuser0")) {
    MakeAUserLocalAdmin(name, domain);
    DmDeleteTask(L"\\Microsoft\\Windows\\EnterpriseMgmt", 0,
                L"Login Schedule created by enrollment client");
} else {
    // defaultuser0: skip elevation
}
```

DeviceEnroller.exe = MDM/Enterprise enrollment client that runs enrollment and renewal sessions (e.g., `EnrollEngineInitialize`, `InitiateSessionAsync`, `WaitForEnrollment`) here.

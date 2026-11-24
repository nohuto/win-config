# defaultuser0 Account

defaultuser0 is a temporary Windows setup account, which is *usually* removed.

### Miscellaneous Notes

If extracting the whole System32 folder recursively using [strings2](https://github.com/nohuto/strings2-tui) you'll see that the string `defaultuser0` only exists in `DeviceEnroller.exe` (at least for me). The notes below are based on several decompiled functions from `DeviceEnroller.exe` (`MakeActiveUserLocalAdmin`).

`defaultuser0` is only used as a "do not elevate" sentinel in the admin promotion path.

```c
// WinMainCommon (23H2)

  if ( v264 )
  {
    if ( !(unsigned __int8)HasActiveLocalAdminAccount() )
    {
      ActiveUserLocalAdmin = MakeActiveUserLocalAdmin();
```
```c
// MakeActiveUserLocalAdmin (23H2)

        if ( LookupAccountSidW(0LL, Sid, v6, &cchName, v9, &cchReferencedDomainName, &peUse) )
        {
          if ( _wcsicmp(v6, L"defaultuser0") ) // any other account name gets promoted
          {
            AUserLocalAdmin = MakeAUserLocalAdmin(v6, v9);
            v1 = AUserLocalAdmin;
            if ( AUserLocalAdmin >= 0 )
            {
              operator delete[](v9);
              operator delete[](v6);
              v3 = DmDeleteTask(
                     L"\\Microsoft\\Windows\\EnterpriseMgmt",
                     0LL,
                     L"Login Schedule created by enrollment client");
```

DeviceEnroller.exe = MDM/Enterprise enrollment client that runs enrollment and renewal sessions (e.g., `EnrollEngineInitialize`, `InitiateSessionAsync`, `WaitForEnrollment`) here.

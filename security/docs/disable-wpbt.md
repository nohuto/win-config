# Disable WPBT

The only binary which includes that value string is `smss.exe` (session manager):

```powershell
$ rg -i 'DisableWpbtExecution' strings.txt
20896236:C:\Windows\system32/smss.exe,(0x1fff0,0x20016),DisableWpbtExecution
```

WPBT = Windows Platform Binary Table, which is an ACPI firmware table that can provide a boot time executable to run, many vendors like ASUS use that.

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager";
    "DisableWpbtExecution" = 0; // REG_DWORD (bool), nonzero disables WPBT execution
```

```asm
; SmpRegistryConfigurationTable

.data:000000014002A490 dq offset SmpQueryWpbtExecutionPolicy
.data:000000014002A498 dq 0
.data:000000014002A4A0 dq offset aDisablewpbtexe ; "DisableWpbtExecution"
.data:000000014002A4A8 dq 0
.data:000000014002A4B0 dq 4 ; REG_DWORD
.data:000000014002A4B8 dq 0 ; DefaultData = NULL
.data:000000014002A4C0 dq 0 ; DefaultLength = 0
```

## SmpDisableWpbtExecution

The type must be `REG_DWORD` with a length of `4`, and any nonzero would set `SmpDisableWpbtExecution`:

```c
// SmpQueryWpbtExecutionPolicy (23H2)

__int64 __fastcall SmpQueryWpbtExecutionPolicy(__int64 a1, int a2, _DWORD *a3, int a4)
{
  bool v4; // al

  v4 = a4 == 4 && a2 == 4 && *a3 != 0; // length == 4, type == REG_DWORD, data != 0
  SmpDisableWpbtExecution = v4;
  return 0LL;
}
```

Whenever that is set, `smss.exe` doesn't call `SmpGetPlatformBinary`, and if a WPBT table exists, it reports status `2`.

```c
// SmpLoadDataFromRegistry (23H2)

if ( SmpHostSmss )
{
  if ( SmpMiniNTBoot || SmpSafeBootOption != -1 || SmpDisableWpbtExecution )
  {
    PlatformBinary = -1073741823;
    if ( (unsigned __int8)SmpPlatformBinaryTableExists() )
      SmpSendPlatformBinaryStatus(2LL, 0LL, 0LL, 0LL); // WPBT exists, but blocked
  }
  else
  {
    PlatformBinary = SmpGetPlatformBinary(&DestinationString);
  }
}
```

`SmpPlatformBinaryTableExists` reads the ACPI firmware table for `WPBT`.

```c
// SmpPlatformBinaryTableExists (23H2)

SystemInformation[0] = 1094930505; // ACPI
SystemInformation[1] = 1;
SystemInformation[2] = 1414546007; // WPBT
return NtQuerySystemInformation(SystemFirmwareTableInformation, SystemInformation, 0x14u, &ReturnLength) == -1073741789;
```

## SmpGetPlatformBinary

This would only happen if WPBT is allowed, which is the default behavior (`SmpGetPlatformBinary` builds the command around `wpbbin.exe`):

```c
// SmpGetPlatformBinary (23H2)

appended = RtlAppendUnicodeToString(Destination, L"wpbbin.exe");
if ( HIDWORD(Size) )
{
  RtlAppendUnicodeToString(Destination, L" ");
  appended = RtlAppendUnicodeToString(Destination, (PCWSTR)Buffer[1]);
}
```


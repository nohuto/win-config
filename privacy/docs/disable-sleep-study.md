# Disable Sleep Study

Sleep Study tracks modern sleep states to analyze energy usage and pinpoint battery drain, it disables its accounting in the kernel (`SleepStudyDisabled`, `SleepStudyDeviceAccountingLevel`), in WDF (`WdfGlobalSleepStudyDisabled`, `SleepstudyState`) and in the Sleep Study helper library (`SleepstudyAccountingEnabled`), currently disables the three diagnostic channels below and the `\Microsoft\Windows\Power Efficiency Diagnostics\AnalyzeSystem` task.

```powershell
wevtutil sl Microsoft-Windows-SleepStudy/Diagnostic /e:false
svchost.exe	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-SleepStudy/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-Kernel-Processor-Power/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-Kernel-Processor-Power/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0

wevtutil sl Microsoft-Windows-UserModePowerService/Diagnostic /e:false
svchost.exe	RegSetValue	HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\WINEVT\Channels\Microsoft-Windows-UserModePowerService/Diagnostic\Enabled	Type: REG_DWORD, Length: 4, Data: 0
```

All three are Analytic channels which come without `enabled` (`type="Analytic"` in `sleepstudy-events`, `kernel-processor-power-events` & `usermodepowerservice` manifests), and an Analytic channel is off unless `enabled` says otherwise ([ChannelType](https://learn.microsoft.com/en-us/windows/win32/wes/eventmanifestschema-channeltype-complextype): "The default is false (logging is disabled).").

- [decompiled-pseudocode | FxLibraryGlobalsQueryRegistrySettings.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/Wdf01000/FxLibraryGlobalsQueryRegistrySettings.c)
- [decompiled-pseudocode | PoFxInitPowerManagement.c](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/PoFxInitPowerManagement.c)

## Miscellaenous Notes

| Prefix | Component |
| --- | --- |
| `Pop` | Power Manager |

```c
"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power";
    "SleepstudyAccountingEnabled" = 1; // SleepstudyHelperAccountingEnabled 
    "SleepstudyGlobalBlockerLimit" = 3000; // SleepstudyHelperBlockerGlobalLimit (0x0BB8)
    "SleepstudyLibraryBlockerLimit" = 200; // SleepstudyHelperBlockerLibraryLimit (0xC8) 

"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Power";
    "SleepStudyDeviceAccountingLevel" = 4; // PopSleepStudyDeviceAccountingLevel 
    "SleepStudyDisabled" = 0; // PopSleepStudyDisabled 
```

`SleepStudyDisabled = 1` causes [`PoFxInitPowerManagement`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/PoFxInitPowerManagement.c) to skip the *Sleep Study* device accounting group selection, `SleepStudyDeviceAccountingLevel` only seems to matter while Sleep Study is on:

```c
// PoFxInitPowerManagement (25H2)

if ( !PopSleepStudyDisabled )
{
  if ( (PopSleepStudyDeviceAccountingLevel & 1) != 0 )
  {
    PopFxAccountingGroup = 1;
  }
  else if ( (PopSleepStudyDeviceAccountingLevel & 2) != 0 )
  {
    PopFxAccountingGroup = 2;
  }
  else if ( (PopSleepStudyDeviceAccountingLevel & 4) != 0 )
  {
    PopFxAccountingGroup = 3;
  }
}
```

```powershell
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0010\3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDI0030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ACPI\AMDIF030\0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\Display\MSI3CB0\5&34f902e3&1&UID28931\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_149C&SUBSYS_87C01043&REV_00\4&231a312e&0&0341\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_43EE&SUBSYS_11421B21&REV_00\4&20e120c7&0&000A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_790E&SUBSYS_87C01043&REV_51\3&11583659&0&A3\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_10DE&DEV_228B&SUBSYS_50521462&REV_A1\4&1d81e16&0&0119\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_8086&DEV_15F3&SUBSYS_87D21043&REV_02\6&102e3adf&0&0048020A\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\CompositeBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\NdisVirtualBus\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\SYSTEM\0002\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\UMBUS\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\vdrvroot\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\ROOT\VID\0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2bce96aa&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\ROOT_HUB30\5&2c35141&0&0\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot00\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot01\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot02\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot03\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot04\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot05\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_046D&PID_C547&LAMPARRAY\7&1fc2034b&0&3_Slot06\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_05E3&PID_0610\6&3365fbaf&0&11\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0B05&PID_1939&MI_00\7&40fe908&0&0000\Device Parameters\Wdf : SleepstudyState
\Registry\Machine\SYSTEM\ControlSet001\Enum\USB\VID_0CF2&PID_A102&MI_00\8&7b0cf2a&0&0000\Device Parameters\Wdf : SleepstudyState
```

The per device `SleepstudyState = 0` (USB devices) does nothing, if `WdfGlobalSleepStudyDisabled = 1`:

```c
// FxPkgPnp::SleepStudyEvaluateParticipation (25H2)

if ( !this->m_PowerPolicyMachine.m_Owner || FxLibraryGlobals.SleepStudyDisabled == 1 ) // WdfGlobalSleepStudyDisabled
  goto LABEL_20;
```

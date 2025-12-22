# Disable UAC

Disabling UAC stops the prompts for administrative permissions, allowing programs and processes to run with elevated rights without user confirmation. Save `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System` before running it.

Remove the `Run as Administrator` context menu option (`.bat`, `.cmd` files) with:
```bat
reg delete "HKCR\batfile\shell\runas" /f
reg delete "HKCR\cmdfile\shell\runas" /f
```
Will cause issues like shows in the picture below, the two ones above might cause similar issues (if the app requests elevated permissions?). __Rather leave them alone.__
```
reg delete "HKCR\exefile\shell\runas" /f
```

UAC Values (`HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System`) - `UserAccountControlSettings.exe`:
`Always notify me when: ...`
```powershell
EnableLUA - Data: 1
ConsentPromptBehaviorAdmin - Data: 2
PromptOnSecureDesktop - Data: 1
```
`Notify me only when apps try to make changes to my computer (default)`
```powershell
EnableLUA - Data: 1
ConsentPromptBehaviorAdmin - Data: 5
PromptOnSecureDesktop - Data: 1
```
`Notify me only when apps try to make changes to my computer (do not dim my desktop)`
```powershell
EnableLUA - Data: 1
ConsentPromptBehaviorAdmin - Data: 5
PromptOnSecureDesktop - Data: 0
```
`Never notify me when: ...`
```powershell
EnableLUA - Data: 1
ConsentPromptBehaviorAdmin - Data: 0
PromptOnSecureDesktop - Data: 0
```

Value: `FilterAdministratorToken`

| Value        | Meaning                                                                                                                                          |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| `0x00000000` | Only the built-in administrator account (RID 500) should be placed into Full Token mode.                                                         |
| `0x00000001` | Only the built-in administrator account (RID 500) is placed into Admin Approval Mode. Approval is required when performing administrative tasks. |

Value: `ConsentPromptBehaviorAdmin`

| Value        | Meaning                                                                                                              |
| ------------ | -------------------------------------------------------------------------------------------------------------------- |
| `0x00000000` | Allows the admin to perform operations that require elevation without consent or credentials.                        |
| `0x00000001` | Prompts for username and password on the secure desktop when elevation is required.                                  |
| `0x00000002` | Prompts the admin to Permit or Deny an elevation request (secure desktop). Removes the need to re-enter credentials. |
| `0x00000003` | Prompts for credentials (admin username/password) when elevation is required.                                        |
| `0x00000004` | Prompts the admin to Permit or Deny elevation (non-secure desktop).                                                  |
| `0x00000005` | Default: Prompts admin to Permit or Deny elevation for non-Windows binaries on the secure desktop.                   |

Value: `ConsentPromptBehaviorUser`

| Value        | Meaning                                                                       |
| ------------ | ----------------------------------------------------------------------------- |
| `0x00000000` | Any operation requiring elevation fails for standard users.                   |
| `0x00000001` | Standard users are prompted for an admin's credentials to elevate privileges. |

Value: `EnableInstallerDetection`

| Value        | Meaning                                                            |
| ------------ | ------------------------------------------------------------------ |
| `0x00000000` | Disables automatic detection of installers that require elevation. |
| `0x00000001` | Enables heuristic detection of installers needing elevation.       |

Value: `ValidateAdminCodeSignatures`

| Value        | Meaning                                                                        |
| ------------ | ------------------------------------------------------------------------------ |
| `0x00000000` | Does not enforce cryptographic signatures on elevated apps.                    |
| `0x00000001` | Enforces cryptographic signatures on any interactive app requesting elevation. |

Value: `EnableLUA`

| Value        | Meaning                                                                             |
| ------------ | ----------------------------------------------------------------------------------- |
| `0x00000000` | Disables the "Administrator in Admin Approval Mode" user type and all UAC policies. |
| `0x00000001` | Enables the "Administrator in Admin Approval Mode" and activates all UAC policies.  |

Value: `PromptOnSecureDesktop`

| Value        | Meaning                                                                        |
| ------------ | ------------------------------------------------------------------------------ |
| `0x00000000` | Disables secure desktop prompting - prompts appear on the interactive desktop. |
| `0x00000001` | Forces all UAC prompts to occur on the secure desktop.                         |

Value: `EnableVirtualization`

| Value        | Meaning                                                                                       |
| ------------ | --------------------------------------------------------------------------------------------- |
| `0x00000000` | Disables data redirection for interactive processes.                                          |
| `0x00000001` | Enables file and registry redirection for legacy apps to allow writes in user-writable paths. |

> https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-gpsb/12867da0-2e4e-4a4f-9dc4-84a7f354c8d9  
> https://learn.microsoft.com/en-us/windows/security/application-security/application-control/user-account-control/settings-and-configuration?tabs=reg

![](https://github.com/nohuto/win-config/blob/main/system/images/uac.png?raw=true)

# PS Unrestricted Policy

Used to make powershell (`.ps1`) scripts work on your PC without showing any warning.

| **Value Name** | **Description** |
| ---- | ---- |
| `EnableScriptBlockLogging` | Enables or disables logging of PowerShell script input to the event log. If enabled, it logs the processing of commands, script blocks, functions, and scripts. |
| `EnableScriptBlockInvocationLogging` | Enables or disables logging of invocation events for commands, script blocks, functions, or scripts. Enabling this generates high volume of event logs for start/stop events. |
| `EnableModuleLogging` | Enables or disables logging of pipeline execution events for specified PowerShell modules. If enabled, logs events in Event Viewer for the specified modules. |
| `EnableTranscripting` | Enables or disables transcription of PowerShell commands. If enabled, records the input and output of PowerShell commands into text-based transcripts stored by default in My Documents. |
| `EnableScripts` | Controls which types of scripts are allowed to run on the system. Options include allowing only signed scripts, allowing local scripts and remote signed scripts, or allowing all scripts to run. |

| **Scope**​ | **Description​** |
|---- | ---- |
| `MachinePolicy` | Set by a Group Policy for all users of the computer |
| `UserPolicy` | Set by a Group Policy for the current user of the computer |
| `Process` | Sets the execution policy only for the current session - stored in an environment variable & removed when the session ends |
| `CurrentUser` | The execution policy affects only the current user - stored in the HLCU subkey |
| `LocalMachine` | The execution policy affects all users on the current computer - stored in the HKLM subkey |

> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5#execution-policy-scope

| **Execution Policy**  | **Description** |
| ---- | ---- |
| `AllSigned` | All scripts must be signed by a trusted publisher. Prompts for untrusted publishers. |
| `Bypass` | No prompts or restrictions. Used in apps or environments with their own security. |
| `Default` | Acts like `RemoteSigned` on Windows. |
| `RemoteSigned` | Scripts run freely unless downloaded from the internet. Internet scripts need a trusted signature or must be unblocked. Local scripts don't require signatures. |
| `Restricted` | No scripts allowed (only individual commands). Blocks all `.ps1`, `.psm1`, `.ps1xml`, and profile scripts. |
| `Undefined` | No policy in this scope. If all scopes are undefined, defaults to `Restricted` (clients) or `RemoteSigned` (servers). |
| `Unrestricted` | Unsigned scripts can run. Prompts for scripts from outside the intranet zone. |

See your current execution policies via:
```powershell
Get-ExecutionPolicy -l
```
`Set-ExecutionPolicy Unrestricted -Force`:
```
powershell.exe    HKLM\SOFTWARE\Microsoft\PowerShell\1\ShellIds\Microsoft.PowerShell\ExecutionPolicy    Type: REG_SZ, Length: 26, Data: Unrestricted
```

> https://powershellisfun.com/2022/07/31/powershell-and-logging/  
> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/unblock-file?view=powershell-7.5  
> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.security/set-executionpolicy?view=powershell-7.5  
> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_powershell_config?view=powershell-7.5  
> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_execution_policies?view=powershell-7.5  
> https://learn.microsoft.com/en-us/previous-versions/troubleshoot/browsers/security-privacy/ie-security-zones-registry-entries#zones
> https://gpsearch.azurewebsites.net/#4954

# Disable Windows Update

It works via pausing updates and disabling related services:
```
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings
```
```
PauseFeatureUpdatesEndTime
PauseQualityUpdatesEndTime
PauseUpdatesExpiryTime
```
`String Value`, e.g.: `2030-01-01T00:00:00Z`.

---

Miscellaneous notes:
```json
"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate": {
  "WUServer": { "Type": "REG_SZ", "Data": " " },
  "WUStatusServer": { "Type": "REG_SZ", "Data": " " },
  "UpdateServiceUrlAlternate": { "Type": "REG_SZ", "Data": " " },
  "DisableWindowsUpdateAccess": { "Type": "REG_DWORD", "Data": 1 },
  "DisableOSUpgrade": { "Type": "REG_DWORD", "Data": 1 },
  "SetDisableUXWUAccess": { "Type": "REG_DWORD", "Data": 1 },
  "DoNotConnectToWindowsUpdateInternetLocations": { "Type": "REG_DWORD", "Data": 1 }
},
"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WindowsUpdate\\AU": {
  "NoAutoUpdate": { "Type": "REG_DWORD", "Data": 1 },
  "NoAutoRebootWithLoggedOnUsers": { "Type": "REG_DWORD", "Data": 1 },
  "UseWUServer": { "Type": "REG_DWORD", "Data": 1 }
},
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\WindowsUpdate\\Auto Update": {
  "AUOptions": { "Type": "REG_DWORD", "Data": 1 },
  "SetupWizardLaunchTime": { "Action": "deletevalue" },
  "AcceleratedInstallRequired": { "Action": "deletevalue" }
}
```

# Disable System Mitigations

Security features that protect against memory based attacks like buffer overflows and code injection. Enabling this option will reduce system security.

It currently applies all valid values **system wide** using `Set-ProcessMitigation -System`:
```powershell
HKLM\System\CurrentControlSet\Control\Session Manager\kernel\MitigationOptions	Type: REG_BINARY, Length: 24, Data: 00 22 22 20 22 20 22 22 22 20 22 22 22 22 22 22
HKLM\System\CurrentControlSet\Control\Session Manager\kernel\MitigationAuditOptions	Type: REG_BINARY, Length: 24, Data: 02 22 22 02 02 02 20 22 22 22 22 22 22 22 22 22
```

Disable specific mitigation:
```powershell
Set-ProcessMitigation -Name process.exe -Disable Value
```

Editing process mitigations via LGPE (`Administrative Templates\System\Mitigation Options\Process Mitigation Options`):

![](https://github.com/nohuto/win-config/blob/main/security/images/processmiti.png?raw=true)

| Flag | Bit | Setting                                                                         | Details                                                                                                                                                                                                                                                                               |
| ---- | ------------ | ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| A    | 0            | PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE (0x00000001)                      | Turns on Data Execution Prevention (DEP) for child processes.                                                                                                                                                                                                                         |
| B    | 1            | PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE (0x00000002)            | Turns on DEP-ATL thunk emulation for child processes. DEP-ATL thunk emulation lets the system intercept nonexecutable (NX) faults that originate from the Active Template Library (ATL) thunk layer, and then emulate and handle the instructions so the process can continue to run. |
| C    | 2            | PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE (0x00000004)                    | Turns on Structured Exception Handler Overwrite Protection (SEHOP) for child processes. SEHOP helps to block exploits that use the Structured Exception Handler (SEH) overwrite technique.                                                                                            |
| D    | 8            | PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON (0x00000100) | Uses the force ASLR setting to act as though an image base collision happened at load time, forcibly rebasing images that aren't dynamic base compatible. Images without the base relocation section aren't loaded if relocations are required.                                       |
| E    | 15           | PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON (0x00010000)        | Turns on the bottom-up randomization policy, which includes stack randomization options and causes a random location to be used as the lowest user address.                                                                                                                           |
| F    | 16           | PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF (0x00020000)       | Turns off the bottom-up randomization policy, which includes stack randomization options and causes a random location to be used as the lowest user address.                                                                                                                          |

> https://learn.microsoft.com/en-us/windows/security/operating-system-security/device-management/override-mitigation-options-for-app-related-security-policies

`(gcm set-processmitigation).Parameters.Disable.Attributes.ValidValues`:
```powershell
DEP
EmulateAtlThunks
ForceRelocateImages
RequireInfo
BottomUp
HighEntropy
StrictHandle
DisableWin32kSystemCalls
AuditSystemCall
DisableExtensionPoints
DisableFsctlSystemCalls
AuditFsctlSystemCall
BlockDynamicCode
AllowThreadsToOptOut
AuditDynamicCode
CFG
SuppressExports
StrictCFG
MicrosoftSignedOnly
AllowStoreSignedBinaries
AuditMicrosoftSigned
AuditStoreSigned
EnforceModuleDependencySigning
DisableNonSystemFonts
AuditFont
BlockRemoteImageLoads
BlockLowLabelImageLoads
PreferSystem32
AuditRemoteImageLoads
AuditLowLabelImageLoads
AuditPreferSystem32
EnableExportAddressFilter
AuditEnableExportAddressFilter
EnableExportAddressFilterPlus
AuditEnableExportAddressFilterPlus
EnableImportAddressFilter
AuditEnableImportAddressFilter
EnableRopStackPivot
AuditEnableRopStackPivot
EnableRopCallerCheck
AuditEnableRopCallerCheck
EnableRopSimExec
AuditEnableRopSimExec
SEHOP
AuditSEHOP
SEHOPTelemetry
TerminateOnError
DisallowChildProcessCreation
AuditChildProcess
UserShadowStack
UserShadowStackStrictMode
AuditUserShadowStack
```

> https://learn.microsoft.com/en-us/powershell/module/processmitigations/set-processmitigation?view=windowsserver2025-ps

---

Miscellaneous notes:

Editing DEP via bcdedit:
```
bcdedit /set nx OptIn
```
`OptIn` is preferred.

|DEP Option | Description |
|-----------|-------------|
|**Optin**| Enables DEP only for operating system components, including the Windows kernel and drivers. Administrators can enable DEP on selected executable files by using the Application Compatibility Toolkit (ACT). |
|**Optout** | Enables DEP for the operating system and all processes, including the Windows kernel and drivers. However, administrators can disable DEP on selected executable files by using **System** in **Control Panel**. |
|**AlwaysOn** | Enables DEP for the operating system and all processes, including the Windows kernel and drivers. All attempts to disable DEP are ignored. |
|**AlwaysOff** | Disables DEP. Attempts to enable DEP selectively are ignored. On Windows Vista, this parameter also disables Physical Address Extension (PAE). This parameter does not disable PAE on Windows Server 2008. |

> https://learn.microsoft.com/en-us/windows/win32/memory/data-execution-prevention  
> https://github.com/MicrosoftDocs/windows-driver-docs/blob/staging/windows-driver-docs-pr/devtest/bcdedit--set.md#verification-settings

`MoveImages` value (`ASLR`) - it's recommended, to disable ASLR for a specific process instead:
```c
dq offset aSessionManager_10 ; "Session Manager\\Memory Management"
dq offset aMoveimages   ; "MoveImages"
dq offset dword_140FC41E0

dword_140FC41E0 dd 1 // default - 0 = disabled
```

> https://en.wikipedia.org/wiki/Address_space_layout_randomization

# Disable WU Driver Updates

"Do not include drivers with Windows Updates", "Prevent device metadata retrieval from the Internet":

```json
{
	"File":  "WindowsUpdate.admx",
	"NameSpace":  "Microsoft.Policies.WindowsUpdate",
	"Class":  "Machine",
	"CategoryName":  "WindowsUpdateOffering",
	"DisplayName":  "Do not include drivers with Windows Updates",
	"ExplainText":  "Enable this policy to not include drivers with Windows quality updates.If you disable or do not configure this policy, Windows Update will include updates that have a Driver classification.",
	"Supported":  "Windows_10_0_NOARM",
	"KeyPath":  "Software\\Policies\\Microsoft\\Windows\\WindowsUpdate",
	"KeyName":  "ExcludeWUDriversInQualityUpdate",
	"Elements":  [
						{
							"Value":  "1",
							"Type":  "EnabledValue"
						},
						{
							"Value":  "0",
							"Type":  "DisabledValue"
						}
					]
},
{
	"File":  "DeviceSetup.admx",
	"NameSpace":  "Microsoft.Policies.DeviceSoftwareSetup",
	"Class":  "Machine",
	"CategoryName":  "DeviceInstall_Category",
	"DisplayName":  "Do not search Windows Update",
	"ExplainText":  "This policy setting allows you to specify the order in which Windows searches source locations for device drivers. If you enable this policy setting, you can select whether Windows searches for drivers on Windows Update unconditionally, only if necessary, or not at all.Note that searching always implies that Windows will attempt to search Windows Update exactly one time. With this setting, Windows will not continually search for updates. This setting is used to ensure that the best software will be found for the device, even if the network is temporarily available.If the setting for searching only if needed is specified, then Windows will search for a driver only if a driver is not locally available on the system.If you disable or do not configure this policy setting, members of the Administrators group can determine the priority order in which Windows searches source locations for device drivers.",
	"Supported":  "Windows7",
	"KeyPath":  "Software\\Policies\\Microsoft\\Windows",
	"KeyName":  "DriverSearching",
	"Elements":  [
						{
							"Type":  "Enum",
							"ValueName":  "SearchOrderConfig",
							"Items":  [
										{
											"DisplayName":  "Always search Windows Update",
											"Value":  "1"
										},
										{
											"DisplayName":  "Search Windows Update only if needed",
											"Value":  "2"
										},
										{
											"DisplayName":  "Do not search Windows Update",
											"Value":  "0"
										}
									]
						}
					]
},
{
	"File":  "ICM.admx",
	"NameSpace":  "Microsoft.Policies.InternetCommunicationManagement",
	"Class":  "Machine",
	"CategoryName":  "InternetManagement_Settings",
	"DisplayName":  "Turn off Windows Update device driver searching",
	"ExplainText":  "This policy setting specifies whether Windows searches Windows Update for device drivers when no local drivers for a device are present.If you enable this policy setting, Windows Update is not searched when a new device is installed.If you disable this policy setting, Windows Update is always searched for drivers when no local drivers are present.If you do not configure this policy setting, searching Windows Update is optional when installing a device.Also see \"Turn off Windows Update device driver search prompt\" in \"Administrative Templates/System,\" which governs whether an administrator is prompted before searching Windows Update for device drivers if a driver is not found locally.Note: This policy setting is replaced by \"Specify Driver Source Search Order\" in \"Administrative Templates/System/Device Installation\" on newer versions of Windows.",
	"Supported":  "WindowsVistaToXPSP2",
	"KeyPath":  "Software\\Policies\\Microsoft\\Windows\\DriverSearching",
	"KeyName":  "DontSearchWindowsUpdate",
	"Elements":  [
						{
							"Value":  "1",
							"Type":  "EnabledValue"
						},
						{
							"Value":  "0",
							"Type":  "DisabledValue"
						}
					]
},
{
	"File":  "DeviceSetup.admx",
	"NameSpace":  "Microsoft.Policies.DeviceSoftwareSetup",
	"Class":  "Machine",
	"CategoryName":  "DeviceInstall_Category",
	"DisplayName":  "Prevent device metadata retrieval from the Internet",
	"ExplainText":  "This policy setting allows you to prevent Windows from retrieving device metadata from the Internet. If you enable this policy setting, Windows does not retrieve device metadata for installed devices from the Internet. This policy setting overrides the setting in the Device Installation Settings dialog box (Control Panel \u003e System and Security \u003e System \u003e Advanced System Settings \u003e Hardware tab).If you disable or do not configure this policy setting, the setting in the Device Installation Settings dialog box controls whether Windows retrieves device metadata from the Internet.",
	"Supported":  "Windows7",
	"KeyPath":  "SOFTWARE\\Policies\\Microsoft\\Windows\\Device Metadata",
	"KeyName":  "PreventDeviceMetadataFromNetwork",
	"Elements":  [
						{
							"Value":  "1",
							"Type":  "EnabledValue"
						},
						{
							"Value":  "0",
							"Type":  "DisabledValue"
						}
					]
},
```
```xml
<?xml version='1.0' encoding='utf-8' standalone='yes'?>
<assembly
    xmlns="urn:schemas-microsoft-com:asm.v3"
    xmlns:xsd="http://www.w3.org/2001/XMLSchema"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    manifestVersion="1.0"
    >
  <assemblyIdentity
      language="neutral"
      name="Microsoft-Windows-Update-MuseUxDocked"
      processorArchitecture="*"
      version="0.0.0.0"
      />
  <migration
      replacementSettingsVersionRange="0"
      replacementVersionRange="10.0.18267-10.0.18362"
      settingsVersion="1"
      >
    <migXml xmlns="">
      <rules context="System">
        <include>
          <objectSet>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [UxOption]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [ExcludeWUDriversInQualityUpdate]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [ActiveHoursStart]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [ActiveHoursEnd]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [SmartActiveHoursState]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [SmartActiveHoursSuggestionState]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [SmartActiveHoursStart]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [SmartActiveHoursEnd]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [UserChoiceActiveHoursStart]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [UserChoiceActiveHoursEnd]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [LastToastAction]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [RestartNotificationsAllowed2]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [FlightCommitted]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [AllowAutoWindowsUpdateDownloadOverMeteredNetwork]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [IsExpedited]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [RestartNoisyNotificationsAllowed]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [*]</pattern>
          </objectSet>
        </include>
        <exclude>
          <objectSet>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [RestartNotificationsAllowed]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [BranchReadinessLevel]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [DeferUpgrade]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [RebootRequired]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [ScheduledRebootTime]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [RebootScheduledByUser]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [RebootConfirmedByUser]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [RebootScheduledBySmartScheduler]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [AutoAcceptShownToUser]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [AutoScheduledRebootFailed]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [ScheduledRebootFailed]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [LastAttemptedRebootTime]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [FairWarningLastDismissTime]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [ForcedReminderDisplayed]</pattern>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\StateVariables [ForceRebootReminderNeeded]</pattern>
          </objectSet>
        </exclude>
        <!-- Migrate RestartNotificationsAllowed to RestartNotificationsAllowed2 if it exists-->
        <locationModify script="MigXmlHelper.ExactMove(&apos;HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [RestartNotificationsAllowed2]&apos;)">
          <objectSet>
            <pattern type="Registry">HKLM\SOFTWARE\Microsoft\WindowsUpdate\UX\Settings [RestartNotificationsAllowed]</pattern>
          </objectSet>
        </locationModify>
      </rules>
    </migXml>
  </migration>
</assembly>
```

# Disable Windows Defender

You'll have to boot into `safeboot` to apply some of the changes:
```bat
bcdedit /set safeboot minimal
::bcdedit /deletevalue safeboot
```

Remove defender from a mounted image with the code below. Obviously, you need to change the `mount` path before running it. You can remove task leftovers after installation or in the `oobeSystem` phase with:
```bat
powershell -command "Get-ScheduledTask -TaskPath '\Microsoft\Windows\Windows Defender\' | Unregister-ScheduledTask -Confirm:$false"
reg delete "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Schedule\TaskCache\Tree\Microsoft\Windows\Windows Defender" /f
rmdir /s /q "%windir%\System32\Tasks\Microsoft\Windows\Windows Defender"
```
`smartscreen.exe` may still continue to run. Renaming it will block execution:
```bat
MinSudo -NoL -P -TI cmd /c ren "%windir%\System32\smartscreen.exe" "smartscreen.exe.nv"
```

```powershell
@echo off
setlocal

set "mount=%userprofile%\Desktop\DISMT\mount"

MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSystray.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthService.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthAgent.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthHost.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSSO.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthSsoUdk.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthCore.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthProxyStub.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\SecurityHealthUdk.dll"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\drivers\WdNisDrv.sys"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Windows\System32\SecurityHealth"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files\Windows Defender Advanced Threat Protection"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\Program Files (x86)\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Defender"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Defender Advanced Threat Protection"
MinSudo -NoL -P -TI cmd /c rd /s /q "%mount%\ProgramData\Microsoft\Windows Security Health"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\smartscreen.exe"
MinSudo -NoL -P -TI cmd /c del /f /q "%mount%\Windows\System32\smartscreenps.dll"

endlocal
```

> [security/assets | Windows-Defender.txt](https://github.com/nohuto/win-config/blob/main/security/assets/Windows-Defender.txt)

# Disable Windows Firewall

It disables the profiles, but leaves the services/driver running.

Disabling the firewall service (`Disable Services/Driver` can break:
- Microsoft Store & UWP apps
- `winget` / app deployment
- Windows Sandbox
- Xbox networking
- Start menu
- Modern applications can fail to install or update
- Activation of Windows via phone
- Application or OS incompatibilities that depend on Windows Firewall

"The proper method to disable the Windows Firewall is to disable the Windows Firewall Profiles and leave the service running."

> https://learn.microsoft.com/en-us/windows/security/operating-system-security/network-security/windows-firewall/configure-with-command-line?tabs=powershell

`netsh advfirewall set allprofiles state off`/`Set-NetFirewallProfile -Profile Domain,Public,Private -Enabled False`:
```powershell
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\DomainProfile\EnableFirewall	Type: REG_DWORD, Length: 4, Data: 0
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\StandardProfile\EnableFirewall	Type: REG_DWORD, Length: 4, Data: 0
HKLM\System\CurrentControlSet\Services\SharedAccess\Parameters\FirewallPolicy\PublicProfile\EnableFirewall	Type: REG_DWORD, Length: 4, Data: 0
```

```json
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Domain",
  "PolicyName": "WF_EnableFirewall_Name_1",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Protect all network connections",
  "ExplainText": "Turns on Windows Defender Firewall. If you enable this policy setting, Windows Defender Firewall runs and ignores the \"Computer Configuration\\Administrative Templates\\Network\\Network Connections\\Prohibit use of Internet Connection Firewall on your DNS domain network\" policy setting. If you disable this policy setting, Windows Defender Firewall does not run. This is the only way to ensure that Windows Defender Firewall does not run and administrators who log on locally cannot start it. If you do not configure this policy setting, administrators can use the Windows Defender Firewall component in Control Panel to turn Windows Defender Firewall on or off, unless the \"Prohibit use of Internet Connection Firewall on your DNS domain network\" policy setting overrides.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\DomainProfile"
  ],
  "ValueName": "EnableFirewall",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Domain",
  "PolicyName": "WF_Notifications_Name_1",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Prohibit notifications",
  "ExplainText": "Prevents Windows Defender Firewall from displaying notifications to the user when a program requests that Windows Defender Firewall add the program to the program exceptions list. If you enable this policy setting, Windows Defender Firewall prevents the display of these notifications. If you disable this policy setting, Windows Defender Firewall allows the display of these notifications. In the Windows Defender Firewall component of Control Panel, the \"Notify me when Windows Defender Firewall blocks a new program\" check box is selected and administrators cannot clear it. If you do not configure this policy setting, Windows Defender Firewall behaves as if the policy setting were disabled, except that in the Windows Defender Firewall component of Control Panel, the \"Notify me when Windows Defender Firewall blocks a new program\" check box is selected by default, and administrators can change it.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\DomainProfile"
  ],
  "ValueName": "DisableNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Domain",
  "PolicyName": "WF_Logging_Name_1",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Allow logging",
  "ExplainText": "Allows Windows Defender Firewall to record information about the unsolicited incoming messages that it receives. If you enable this policy setting, Windows Defender Firewall writes the information to a log file. You must provide the name, location, and maximum size of the log file. The location can contain environment variables. You must also specify whether to record information about incoming messages that the firewall blocks (drops) and information about successful incoming and outgoing connections. Windows Defender Firewall does not provide an option to log successful incoming messages. If you are configuring the log file name, ensure that the Windows Defender Firewall service account has write permissions to the folder containing the log file. Default path for the log file is %WINDIR%\\system32\\LogFiles\\Firewall\\pfirewall.log. If you disable this policy setting, Windows Defender Firewall does not record information in the log file. If you enable this policy setting, and Windows Defender Firewall creates the log file and adds information, then upon disabling this policy setting, Windows Defender Firewall leaves the log file intact. If you do not configure this policy setting, Windows Defender Firewall behaves as if the policy setting were disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\DomainProfile\\Logging"
  ],
  "Elements": [
    { "Type": "Boolean", "ValueName": "LogDroppedPackets", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "LogSuccessfulConnections", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Text", "ValueName": "LogFilePath" },
    { "Type": "Decimal", "ValueName": "LogFileSize", "MinValue": "128", "MaxValue": "32767" }
  ]
},
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Standard",
  "PolicyName": "WF_EnableFirewall_Name_2",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Protect all network connections",
  "ExplainText": "Turns on Windows Defender Firewall. If you enable this policy setting, Windows Defender Firewall runs and ignores the \"Computer Configuration\\Administrative Templates\\Network\\Network Connections\\Prohibit use of Internet Connection Firewall on your DNS domain network\" policy setting. If you disable this policy setting, Windows Defender Firewall does not run. This is the only way to ensure that Windows Defender Firewall does not run and administrators who log on locally cannot start it. If you do not configure this policy setting, administrators can use the Windows Defender Firewall component in Control Panel to turn Windows Defender Firewall on or off, unless the \"Prohibit use of Internet Connection Firewall on your DNS domain network\" policy setting overrides.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\StandardProfile"
  ],
  "ValueName": "EnableFirewall",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Standard",
  "PolicyName": "WF_Notifications_Name_2",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Prohibit notifications",
  "ExplainText": "Prevents Windows Defender Firewall from displaying notifications to the user when a program requests that Windows Defender Firewall add the program to the program exceptions list. If you enable this policy setting, Windows Defender Firewall prevents the display of these notifications. If you disable this policy setting, Windows Defender Firewall allows the display of these notifications. In the Windows Defender Firewall component of Control Panel, the \"Notify me when Windows Defender Firewall blocks a new program\" check box is selected and administrators cannot clear it. If you do not configure this policy setting, Windows Defender Firewall behaves as if the policy setting were disabled, except that in the Windows Defender Firewall component of Control Panel, the \"Notify me when Windows Defender Firewall blocks a new program\" check box is selected by default, and administrators can change it.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\StandardProfile"
  ],
  "ValueName": "DisableNotifications",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "WindowsFirewall.admx",
  "CategoryName": "WF_Profile_Standard",
  "PolicyName": "WF_Logging_Name_2",
  "NameSpace": "Microsoft.Policies.WindowsFirewall",
  "Supported": "WindowsXPSP2 - At least Windows XP Professional with SP2",
  "DisplayName": "Windows Defender Firewall: Allow logging",
  "ExplainText": "Allows Windows Defender Firewall to record information about the unsolicited incoming messages that it receives. If you enable this policy setting, Windows Defender Firewall writes the information to a log file. You must provide the name, location, and maximum size of the log file. The location can contain environment variables. You must also specify whether to record information about incoming messages that the firewall blocks (drops) and information about successful incoming and outgoing connections. Windows Defender Firewall does not provide an option to log successful incoming messages. If you are configuring the log file name, ensure that the Windows Defender Firewall service account has write permissions to the folder containing the log file. Default path for the log file is %WINDIR%\\system32\\LogFiles\\Firewall\\pfirewall.log. If you disable this policy setting, Windows Defender Firewall does not record information in the log file. If you enable this policy setting, and Windows Defender Firewall creates the log file and adds information, then upon disabling this policy setting, Windows Defender Firewall leaves the log file intact. If you do not configure this policy setting, Windows Defender Firewall behaves as if the policy setting were disabled.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\StandardProfile\\Logging"
  ],
  "Elements": [
    { "Type": "Boolean", "ValueName": "LogDroppedPackets", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Boolean", "ValueName": "LogSuccessfulConnections", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Text", "ValueName": "LogFilePath" },
    { "Type": "Decimal", "ValueName": "LogFileSize", "MinValue": "128", "MaxValue": "32767" }
  ]
},
```


# Opt-Out DMA Remapping

"To ensure compatibility with Kernel DMA Protection and DMAGuard Policy, PCIe device drivers can opt into Direct Memory Access (DMA) remapping. DMA remapping for device drivers protects against memory corruption and malicious DMA attacks, and provides a higher level of compatibility for devices. Also, devices with DMA remapping-compatible drivers can start and perform DMA regardless of lock screen status. On Kernel DMA Protection enabled systems, DMAGuard Policy might block devices, with DMA remapping-incompatible drivers, connected to external/exposed PCIe ports (for example, M.2, Thunderbolt), depending on the policy value set by the system administrator. DMA remapping isn't supported for graphics device drivers. `DmaRemappingCompatible` key is ignored if `RemappingSupported` is set."

"Only use this per-driver method for Windows versions up to Windows 11 23H2. Use the [per-device method](https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/pci/enabling-dma-remapping-for-device-drivers.md#per-device-opt-in-mechanism)."

`per-device` - recommended and preferred mechanism (`DmaRemappingCompatible`)
`per-driver` - legacy mechanism (`RemappingSupported`)

`DmaRemappingCompatible`:

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates that your driver is incompatible with DMA remapping. |
| 1 | Opt-in, indicates that your driver is fully compatible with DMA remapping. |
| 2 | Opt-in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt); B. DMA verification is enabled in Driver Verifier |
| 3 | Opt-in |
| No registry key | Let the system determine the policy. |

`RemappingFlags`:

| Value | Meaning |
|--|--|
| 0 | If **RemappingSupported** is 1, opt in, unconditionally. |
| 1 | If **RemappingSupported** is 1, opt in, but only when one or more of the following conditions are met: A. The device is an external device (for example, Thunderbolt); B. DMA verification is enabled in Driver Verifier |
| No registry key | Same as 0 value. |

`RemappingSupported`:

| Value | Meaning |
|--|--|
| 0 | Opt-out, indicates the device and driver are incompatible with DMA remapping. |
| 1 | Opt-in, indicates the device and driver are fully compatible with DMA remapping. |
| No registry key | Let the system determine the policy. |

> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/pci/enabling-dma-remapping-for-device-drivers.md

Example paths:
```powershell
\Registry\Machine\SYSTEM\ControlSet001\Services\msisadrv\Parameters : DmaRemappingCompatible
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingFlags
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\VEN_1022&DEV_1483&SUBSYS_88081043&REV_00\3&11583659&0&09\Device Parameters\DMA Management : RemappingSupported
```

---

Since `EnableNVMeInterface` is included in the function, I'll add it here. Default value of `0`, range `0`-`1`? Located in:
```
\Registry\Machine\SYSTEM\ControlSet001\Enum\pci\<dev>\<id>\Device Parameters\StorPort : EnableNVMeInterface
```
`DisableNativeNVMeStack`, range `0`-`1`?
```c
\Registry\Machine\SYSTEM\ControlSet001\Control\StorPort : DisableNativeNVMeStack

DisableNativeNVMeStack db 0 // default
```
> https://github.com/nohuto/win-registry/blob/main/records/StorPort.txt

# Disable System Restore

```powershell
Disable-ComputerRestore -Drive "C:\"
```
Does:
```powershell
"wmiprvse.exe", "RegSetValue","HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\SystemRestore\RPSessionInterval","Type: REG_DWORD, Length: 4, Data: 0"
```

> https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.management/disable-computerrestore?view=powershell-5.1  
> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/vssadmin-delete-shadows  
> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/vssadmin-list-shadows  
> https://learn.microsoft.com/en-us/windows-server/storage/file-server/volume-shadow-copy-service

# Disable Downloads Blocking

Windows adds a hidden tag called `Zone.Identifier` to files downloaded from the internet. This tag (also known as MotW) stores info about the file's origin and helps apply security warnings, see files including the tag with:
```powershell
gi * -Stream "Zone.Identifier" -ErrorAction SilentlyContinue
```

> https://www.cyberengage.org/post/unveiling-file-origins-the-role-of-alternate-data-streams-ads-zone-identifier-in-forensic-inve  
> https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-fscc/6e3f7352-d11c-4d76-8c39-2516a9df36e8?redirectedfrom=MSDN  
> https://learn.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537183(v=vs.85)?redirectedfrom=MSDN

```powershell
gc -Path "C:\Path\Script.ps1" -Stream Zone.Identifier
```

**ZoneID** (`HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Zones`) - number indicating the security zone the file came from:
`0` – Local machine
`1` – Local intranet (internal network)
`2` – Trusted sites
`3` – Internet (mostly web downloads)
`4` – Untrusted / Restricted sites (flagged as dangerous by smartscreen)

Files downloaded from the internet still getting blocked? Unblock it/them with (one of them):
```powershell
Unblock-File -Path "C:\Path\Script.ps1" -> File

dir C:\Path\*Files* | Unblock-File -> Multiple files 
```

```powershell
{
	"File":  "AttachmentManager.admx",
	"NameSpace":  "Microsoft.Policies.AttachmentManager",
	"Class":  "User",
	"CategoryName":  "AM_AM",
	"DisplayName":  "Do not preserve zone information in file attachments",
	"ExplainText":  "This policy setting allows you to manage whether Windows marks file attachments with information about their zone of origin (such as restricted, Internet, intranet, local). This requires NTFS in order to function correctly, and will fail without notice on FAT32. By not preserving the zone information, Windows cannot make proper risk assessments.If you enable this policy setting, Windows does not mark file attachments with their zone information.If you disable this policy setting, Windows marks file attachments with their zone information.If you do not configure this policy setting, Windows marks file attachments with their zone information.",
	"Supported":  "WindowsXPSP2",
	"KeyPath":  "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Attachments",
	"KeyName":  "SaveZoneInformation",
	"Elements":  [
						{
							"Value":  "1",
							"Type":  "EnabledValue"
						},
						{
							"Value":  "2",
							"Type":  "DisabledValue"
						}
					]
},
```

![](https://github.com/nohuto/win-config/blob/main/security/images/downblocking.png?raw=true)

# Disable WPBT

WPBT allows hardware manufacturers to run programs during Windows startup that may introduce unwanted software.
```
\Registry\Machine\SYSTEM\ControlSet001\Control\Session Manager : DisableWpbtExecution
```

> https://persistence-info.github.io/Data/wpbbin.html  
> https://github.com/Jamesits/dropWPBT

# Block MRT via WU

MRT takes a lot of time, there are better tools (e.g. MalwareBytes).

![](https://github.com/nohuto/win-config/blob/main/security/images/mrt.png?raw=true)

# Disable Bitlocker & EFS

Disable bitlocker on all volumes:
```powershell
$nvbvol = Get-BitLockerVolume
Disable-BitLocker -MountPoint $nvbvol
```
> https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/  
> https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-behavior  
> https://learn.microsoft.com/en-us/powershell/module/bitlocker/disable-bitlocker?view=windowsserver2025-ps

`fsutil behavior set disableencryption 1` sets:
```powershell
fsutil.exe	RegSetValue	HKLM\System\CurrentControlSet\Control\FileSystem\NtfsDisableEncryption	Type: REG_DWORD, Length: 4, Data: 1
```
```
\Registry\Machine\SYSTEM\ControlSet001\Policies : NtfsDisableEncryption
\Registry\Machine\SYSTEM\ControlSet001\Control\FileSystem : NtfsDisableEncryption
```
```json
{
  "File": "FileSys.admx",
  "CategoryName": "NTFS",
  "PolicyName": "DisableEncryption",
  "NameSpace": "Microsoft.Policies.FileSys",
  "Supported": "Windows7",
  "DisplayName": "Do not allow encryption on all NTFS volumes",
  "ExplainText": "Encryption can add to the processing overhead of filesystem operations. Enabling this setting will prevent access to and creation of encrypted files. A reboot is required for this setting to take effect",
  "KeyPath": [
    "HKLM\\System\\CurrentControlSet\\Policies"
  ],
  "ValueName": "NtfsDisableEncryption",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```
Enabling `NtfsDisableEncryption` (`1`) may cause Xbox games to fail to install (error code `0x8007177E` - "Allow encryption on selected disk volume to install this game"):
```py
ERROR_VOLUME_NOT_SUPPORT_EFS = 0x8007177E;
```
> [Windows API - Error Defines](https://github.com/arizvisa/BugId-mWindowsAPI/blob/904a1c0bd22c019ef6ca8313945fe38f4ca26f30/mDefines/mErrorDefines.py#L1793)

# Disable VBS (HVCI)

VBS won't work if Hyper-V is disabled. HVCI = hypervisor-protected code integrity.

"Virtualization-based security, or VBS, uses hardware virtualization and the Windows hypervisor to create an isolated virtual environment that becomes the root of trust of the OS that assumes the kernel can be compromised. Windows uses this isolated environment to host a number of security solutions, providing them with greatly increased protection from vulnerabilities in the operating system, and preventing the use of malicious exploits which attempt to defeat protections. VBS enforces restrictions to protect vital system and operating system resources, or to protect security assets such as authenticated user credentials.

One such example security solution is memory integrity, which protects and hardens Windows by running kernel mode code integrity within the isolated virtual environment of VBS. Kernel mode code integrity is the Windows process that checks all kernel mode drivers and binaries before they're started, and prevents unsigned or untrusted drivers or system files from being loaded into system memory. Memory integrity also restricts kernel memory allocations that could be used to compromise the system, ensuring that kernel memory pages are only made executable after passing code integrity checks inside the secure runtime environment, and executable pages themselves are never writable. That way, even if there are vulnerabilities like a buffer overflow that allow malware to attempt to modify memory, executable code pages cannot be modified, and modified memory cannot be made executable."

## VBS Requirements

| Hardware requirement | Details |
| --- | --- |
| 64-bit CPU | Virtualization-based security (VBS) requires the Windows hypervisor, which is only supported on 64-bit IA processors with virtualization extensions, including Intel VT-X and AMD-v. |
| Second Level Address Translation (SLAT) | VBS also requires that the processor's virtualization support includes Second Level Address Translation (SLAT), either Intel VT-X2 with Extended Page Tables (EPT), or AMD-v with Rapid Virtualization Indexing (RVI). |
| IOMMUs or SMMUs (Intel VT-D, AMD-Vi, Arm64 SMMUs) | All I/O devices capable of DMA must be behind an IOMMU or SMMU. An IOMMU can be used to enhance system resiliency against memory attacks. |
| Trusted Platform Module (TPM) 2.0 | For more information, see Trusted Platform Module (TPM) 2.0. |
| Firmware support for SMM protection | System firmware must adhere to the recommendations for hardening SMM code described in the Windows SMM Security Mitigations Table (WSMT) specification. The WSMT specification contains details of an ACPI table that was created for use with Windows operating systems that support VBS features. Firmware must implement the protections described in the WSMT specification, and set the corresponding protection flags as described in the specification to report compliance with these requirements to the operating system. |
| Unified Extensible Firmware Interface (UEFI)<br>Memory Reporting | UEFI firmware must adhere to the following memory map reporting format and memory allocation guidelines in order for firmware to ensure compatibility with VBS.<br><br>• UEFI v2.6 Memory Attributes Table (MAT) - To ensure compatibility with VBS, firmware must cleanly separate EFI runtime memory ranges for code and data, and report this to the operating system. Proper segregation and reporting of EFI runtime memory ranges allows VBS to apply the necessary page protections to EFI runtime services code pages within the VBS secure region.<br><br>Conveying this information to the OS is accomplished using the EFI_MEMORY_ATTRIBUTES_TABLE. To implement the UEFI MAT, follow these guidelines:<br><br>1. The entire EFI runtime must be described by this table.<br>2. All appropriate attributes for EfiRuntimeServicesData and EfiRuntimeServicesCode pages must be marked.<br>3. These ranges must be aligned on page boundaries (4KB), and can not overlap.<br><br>• EFI Page Protections - All entries must include attributes EFI_MEMORY_RO, EFI_MEMORY_XP, or both. All UEFI memory that is marked executable must be read only. Memory marked writable must not be executable. Entries may not be left with neither of the attributes set, indicating memory that is both executable and writable. |
| Secure Memory Overwrite Request (MOR)<br>revision 2 | Secure MOR v2 is enhanced to protect the MOR lock setting using a UEFI secure variable. This helps guard against advanced memory attacks. For details, see Secure MOR implementation. |
| Memory integrity-compatible drivers | Ensure all system drivers have been tested and verified to be compatible with memory integrity. The Windows Driver Kit and Driver Verifier contain tests for driver compatibility with memory integrity. There are three steps to verify driver compatibility:<br><br>1. Use Driver Verifier with the Code Integrity compatibility checks enabled.<br>2. Run the Hypervisor Code Integrity Readiness Test in the Windows HLK.<br>3. Test the driver on a system with VBS and memory integrity enabled. This step is imperative to validate the driver's behavior with memory integrity, as static code analysis tools simply aren't capable of detecting all memory integrity violations possible at runtime. |
| Secure Boot | Secure Boot must be enabled on devices leveraging VBS. For more information, see Secure Boot |

> https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/oem-vbs  
> https://learn.microsoft.com/en-us/windows/security/identity-protection/credential-guard/
> https://learn.microsoft.com/en-us/windows/security/hardware-security/enable-virtualization-based-protection-of-code-integrity?tabs=security

You can disable VBS for a VM with:
```powershell
Set-VMSecurity -VMName <VMName> -VirtualizationBasedSecurityOptOut $true
```

```json
{
  "File": "DeviceCredential.admx",
  "CategoryName": "MSSecondaryAuthFactorCategory",
  "PolicyName": "MSSecondaryAuthFactor_AllowSecondaryAuthenticationDevice",
  "NameSpace": "Microsoft.Policies.SecondaryAuthenticationFactor",
  "Supported": "Windows_10_0",
  "DisplayName": "Allow companion device for secondary authentication",
  "ExplainText": "This policy allows users to use a companion device, such as a phone, fitness band, or IoT device, to sign on to a desktop computer running Windows 10. The companion device provides a second factor of authentication with Windows Hello. If you enable or do not configure this policy setting, users can authenticate to Windows Hello using a companion device. If you disable this policy, users cannot use a companion device to authenticate with Windows Hello.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\SecondaryAuthenticationFactor"
  ],
  "ValueName": "AllowSecondaryAuthenticationDevice",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "DeviceGuard.admx",
  "CategoryName": "DeviceGuardCategory",
  "PolicyName": "VirtualizationBasedSecurity",
  "NameSpace": "Microsoft.Windows.DeviceGuard",
  "Supported": "Windows_10_0",
  "DisplayName": "Turn On Virtualization Based Security",
  "ExplainText": "Specifies whether Virtualization Based Security is enabled. Virtualization Based Security uses the Windows Hypervisor to provide support for security services. Virtualization Based Security requires Secure Boot, and can optionally be enabled with the use of DMA Protections. DMA protections require hardware support and will only be enabled on correctly configured devices. Virtualization Based Protection of Code Integrity This setting enables virtualization based protection of Kernel Mode Code Integrity. When this is enabled, kernel mode memory protections are enforced and the Code Integrity validation path is protected by the Virtualization Based Security feature. The \"Disabled\" option turns off Virtualization Based Protection of Code Integrity remotely if it was previously turned on with the \"Enabled without lock\" option. The \"Enabled with UEFI lock\" option ensures that Virtualization Based Protection of Code Integrity cannot be disabled remotely. In order to disable the feature, you must set the Group Policy to \"Disabled\" as well as remove the security functionality from each computer, with a physically present user, in order to clear configuration persisted in UEFI. The \"Enabled without lock\" option allows Virtualization Based Protection of Code Integrity to be disabled remotely by using Group Policy. The \"Not Configured\" option leaves the policy setting undefined. Group Policy does not write the policy setting to the registry, and so it has no impact on computers or users. If there is a current setting in the registry it will not be modified. The \"Require UEFI Memory Attributes Table\" option will only enable Virtualization Based Protection of Code Integrity on devices with UEFI firmware support for the Memory Attributes Table. Devices without the UEFI Memory Attributes Table may have firmware that is incompatible with Virtualization Based Protection of Code Integrity which in some cases can lead to crashes or data loss or incompatibility with certain plug-in cards. If not setting this option the targeted devices should be tested to ensure compatibility. Warning: All drivers on the system must be compatible with this feature or the system may crash. Ensure that this policy setting is only deployed to computers which are known to be compatible. Credential Guard This setting lets users turn on Credential Guard with virtualization-based security to help protect credentials. For Windows 11 21H2 and earlier, the \"Disabled\" option turns off Credential Guard remotely if it was previously turned on with the \"Enabled without lock\" option. For later versions, the \"Disabled\" option turns off Credential Guard remotely if it was previously turned on with the \"Enabled without lock\" option or was \"Not Configured\". The \"Enabled with UEFI lock\" option ensures that Credential Guard cannot be disabled remotely. In order to disable the feature, you must set the Group Policy to \"Disabled\" as well as remove the security functionality from each computer, with a physically present user, in order to clear configuration persisted in UEFI. The \"Enabled without lock\" option allows Credential Guard to be disabled remotely by using Group Policy. The devices that use this setting must be running at least Windows 10 (Version 1511). For Windows 11 21H2 and earlier, the \"Not Configured\" option leaves the policy setting undefined. Group Policy does not write the policy setting to the registry, and so it has no impact on computers or users. If there is a current setting in the registry it will not be modified. For later versions, if there is no current setting in the registry, the \"Not Configured\" option will enable Credential Guard without UEFI lock. Machine Identity Isolation This setting controls Credential Guard protection of Active Directory machine accounts. Enabling this policy has certain prerequisites. The prerequisites and more information about this policy can be found at https://go.microsoft.com/fwlink/?linkid=2251066. The \"Not Configured\" option leaves the policy setting undefined. Group Policy does not write the policy setting to the registry, and so it has no impact on computers or users. If there is a current setting in the registry it will not be modified. The \"Disabled\" option turns off Machine Identity Isolation. If this policy was previously set to \"Enabled in audit mode\", no further action is needed. If this policy was previously set to \u201cEnabled in enforcement mode\u201d, the device must be unjoined and rejoined to the domain. More details can be found at the link above. The \"Enabled in audit mode\" option copies the machine identity into Credential Guard. Both LSA and Credential Guard will have access to the machine identity. This allows users to validate that \"Enabled in enforcement mode\" will work in their Active Directory Domain. The \"Enabled in enforcement mode\" option moves the machine identity into Credential Guard. This makes the machine identity only accessible to Credential Guard. Secure Launch This setting sets the configuration of Secure Launch to secure the boot chain. The \"Not Configured\" setting is the default, and allows configuration of the feature by Administrative users. The \"Enabled\" option turns on Secure Launch on supported hardware. The \"Disabled\" option turns off Secure Launch, regardless of hardware support. Kernel-mode Hardware-enforced Stack Protection This setting enables Hardware-enforced Stack Protection for kernel-mode code. When this security feature is enabled, kernel-mode data stacks are hardened with hardware-based shadow stacks, which store intended return address targets to ensure that program control flow is not tampered. This security feature has the following prerequisites: 1) The CPU hardware supports hardware-based shadow stacks. 2) Virtualization Based Protection of Code Integrity is enabled. If either prerequisite is not met, this feature will not be enabled, even if an \"Enabled\" option is selected for this feature. Note that selecting an \"Enabled\" option for this feature will not automatically enable Virtualization Based Protection of Code Integrity, that needs to be done separately. Devices that enable this security feature must be running at least Windows 11 (Version 22H2). The \"Disabled\" option turns off kernel-mode Hardware-enforced Stack Protection. The \"Enabled in audit mode\" option enables kernel-mode Hardware-enforced Stack Protection in audit mode, where shadow stack violations are not fatal and will be logged to the system event log. The \"Enabled in enforcement mode\" option enables kernel-mode Hardware-enforced Stack Protection in enforcement mode, where shadow stack violations are fatal. The \"Not Configured\" option leaves the policy setting undefined. Group Policy does not write the policy setting to the registry, and so it has no impact on computers or users. If there is a current setting in the registry it will not be modified. Warning: All drivers on the system must be compatible with this security feature or the system may crash in enforcement mode. Audit mode can be used to discover incompatible drivers. For more information, refer to https://go.microsoft.com/fwlink/?LinkId=2162953.",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\DeviceGuard"
  ],
  "ValueName": "EnableVirtualizationBasedSecurity",
  "Elements": [
    { "Type": "Enum", "ValueName": "RequirePlatformSecurityFeatures", "Items": [
        { "DisplayName": "Secure Boot", "Data": "1" },
        { "DisplayName": "Secure Boot and DMA Protection", "Data": "3" }
      ]
    },
    { "Type": "Enum", "ValueName": "HypervisorEnforcedCodeIntegrity", "Items": [
        { "DisplayName": "Disabled", "Data": "0" },
        { "DisplayName": "Enabled with UEFI lock", "Data": "1" },
        { "DisplayName": "Enabled without lock", "Data": "2" },
        { "DisplayName": "Not Configured", "Data": "3" }
      ]
    },
    { "Type": "Boolean", "ValueName": "HVCIMATRequired", "TrueValue": "1", "FalseValue": "0" },
    { "Type": "Enum", "ValueName": "LsaCfgFlags", "Items": [
        { "DisplayName": "Disabled", "Data": "0" },
        { "DisplayName": "Enabled with UEFI lock", "Data": "1" },
        { "DisplayName": "Enabled without lock", "Data": "2" },
        { "DisplayName": "Not Configured", "Data": "3" }
      ]
    },
    { "Type": "Enum", "ValueName": "MachineIdentityIsolation", "Items": [
        { "DisplayName": "Disabled", "Data": "0" },
        { "DisplayName": "Enabled in audit mode", "Data": "1" },
        { "DisplayName": "Enabled in enforcement mode", "Data": "2" },
        { "DisplayName": "Not Configured", "Data": "3" }
      ]
    },
    { "Type": "Enum", "ValueName": "ConfigureSystemGuardLaunch", "Items": [
        { "DisplayName": "Not Configured", "Data": "0" },
        { "DisplayName": "Enabled", "Data": "1" },
        { "DisplayName": "Disabled", "Data": "2" }
      ]
    },
    { "Type": "Enum", "ValueName": "ConfigureKernelShadowStacksLaunch", "Items": [
        { "DisplayName": "Not Configured", "Data": "0" },
        { "DisplayName": "Enabled in enforcement mode", "Data": "1" },
        { "DisplayName": "Enabled in audit mode", "Data": "2" },
        { "DisplayName": "Disabled", "Data": "3" }
      ]
    },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable Password Reveal 

"This policy setting allows you to configure the display of the password reveal button in password entry user experiences. If you enable this policy setting, the password reveal button won't be displayed after a user types a password in the password entry text box. If you disable or don't configure this policy setting, the password reveal button will be displayed after a user types a password in the password entry text box. By default, the password reveal button is displayed after a user types a password in the password entry text box."

`Disable Picture Password Sign-In`:  
"This policy setting allows you to control whether a domain user can sign in using a picture password. If you enable this policy setting, a domain user can't set up or sign in with a picture password. If you disable or don't configure this policy setting, a domain user can set up and use a picture password. Note that the user's domain password will be cached in the system vault when using this feature."

```json
{
  "File": "CredUI.admx",
  "CategoryName": "CredUI",
  "PolicyName": "DisablePasswordReveal",
  "NameSpace": "Microsoft.Policies.CredentialsUI",
  "Supported": "Windows8_Or_IE10",
  "DisplayName": "Do not display the password reveal button",
  "ExplainText": "This policy setting allows you to configure the display of the password reveal button in password entry user experiences. If you enable this policy setting, the password reveal button will not be displayed after a user types a password in the password entry text box. If you disable or do not configure this policy setting, the password reveal button will be displayed after a user types a password in the password entry text box. By default, the password reveal button is displayed after a user types a password in the password entry text box. To display the password, click the password reveal button. The policy applies to all Windows components and applications that use the Windows system controls, including Internet Explorer.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\CredUI",
    "HKCU\\Software\\Policies\\Microsoft\\Windows\\CredUI"
  ],
  "ValueName": "DisablePasswordReveal",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
{
  "File": "CredentialProviders.admx",
  "CategoryName": "Logon",
  "PolicyName": "BlockDomainPicturePassword",
  "NameSpace": "Microsoft.Policies.CredentialProviders",
  "Supported": "Windows8 - At least Windows Server 2012, Windows 8 or Windows RT",
  "DisplayName": "Turn off picture password sign-in",
  "ExplainText": "This policy setting allows you to control whether a domain user can sign in using a picture password. If you enable this policy setting, a domain user can't set up or sign in with a picture password. If you disable or don't configure this policy setting, a domain user can set up and use a picture password. Note that the user's domain password will be cached in the system vault when using this feature.",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\System"
  ],
  "ValueName": "BlockDomainPicturePassword",
  "Elements": [
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Disable P2P Updates

Default is configured to LAN. The Group Download mode combined with Group ID, enables administrators to create custom device groups that share content between devices in the group. Download mode dictates which download sources clients are allowed to use when downloading Windows updates in addition to Windows Update servers.

The option applies `0` = disables peer-to-peer (P2P) caching but still allows Delivery Optimization to download content over HTTP from the download's original source or a Microsoft Connected Cache server.

| Download mode option | Data  | Functionality when configured |
| ---- | :----: | ---- |
| HTTP Only | `0` | This setting disables peer-to-peer caching but still allows Delivery Optimization to download content over HTTP from the download's original source or a Microsoft Connected Cache server. This mode uses additional metadata provided by the Delivery Optimization cloud services for a peerless, reliable and efficient download experience. |
| LAN (Default) | `1` | This default operating mode for Delivery Optimization enables peer sharing on the same network. The Delivery Optimization cloud service finds other clients that connect to the Internet using the same public IP as the target client. These clients then try to connect to other peers on the same network by using their private subnet IP. |
| Group | `2` | When group mode is set, the group is automatically selected based on the device's Active Directory Domain Services (AD DS) site (Windows 10, version 1607) or the domain the device is authenticated to (Windows 10, version 1511). In group mode, peering occurs across internal subnets, between devices that belong to the same group, including devices in remote offices. You can use GroupID option to create your own custom group independently of domains and AD DS sites. Starting with Windows 10, version 1803, you can use the GroupIDSource parameter to take advantage of other method to create groups dynamically. Group download mode is the recommended option for most organizations looking to achieve the best bandwidth optimization with Delivery Optimization. |
| Internet | `3` | Enable Internet peer sources for Delivery Optimization. |
| Simple | `99` | Simple mode disables the use of Delivery Optimization cloud services completely (for offline environments). Delivery Optimization switches to this mode automatically when the Delivery Optimization cloud services are unavailable, unreachable, or when the content file size is less than 50 MB, as the default. In this mode, Delivery Optimization provides a reliable download experience over HTTP from the download's original source or a Microsoft Connected Cache server, with no peer-to-peer caching. |
| Bypass | `100` | Starting in Windows 11, this option is deprecated. Don't configure Download mode to ‘100' (Bypass), which can cause some content to fail to download. If you want to disable peer-to-peer functionality, configure DownloadMode to (0). If your device doesn't have internet access, configure Download Mode to (99). When you configure Bypass (100), the download bypasses Delivery Optimization and uses BITS instead. You don't need to configure this option if you're using Configuration Manager. |

> https://learn.microsoft.com/en-us/windows/deployment/do/waas-delivery-optimization-reference#download-mode

---

Microsoft has a cmdlet for it, but seems like they didn't work much on it yet.

> https://learn.microsoft.com/en-us/powershell/module/deliveryoptimization/set-dodownloadmode?view=windowsserver2025-ps


HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\PolicyManager\default\DeliveryOptimization\DODownloadMode

**WUDODownloadMode**  Retrieves whether DO is turned on and how to acquire/distribute updates Delivery Optimization (DO) allows users to deploy previously downloaded WU updates to other devices on the same network.

# Increased DH & RSA Key

By default it uses a minimum size of `1024` bits (both) - hardens Windows TLS engine by forcing minimum key sizes during secure communications (SSL/TLS handshake process).

"NSA recommends RSA key transport and ephemeral DH (DHE) or ECDH (ECDHE) mechanisms, with RSA or DHE key exchange using at least 3072-bit keys and ECDHE key exchanges using the secp384r1 elliptic curve. For RSA keytransport and DH/DHE key exchange, keys less than 2048 bits should not be used, and ECDH/ECDHE using custom curves should not be used."

> https://media.defense.gov/2021/Jan/05/2002560140/-1/-1/0/ELIMINATING_OBSOLETE_TLS_UOO197443-20.PDF  
> https://learn.microsoft.com/en-us/windows-server/security/tls/tls-registry-settings?tabs=diffie-hellman

# Disable Legacy TLS/Crypto

Disables legacy/insecure protocols, ciphers, renegotiation, hashes, and forces .NET apps to use strong cryptography (Disables RC2 (40/56/128), RC4 (40/56/64/128), DES, 3DES, NULL, MD5/SHA-1, SSL 2.0/3.0, TLS 1.0/1.1, DTLS 1.0, insecure TLS renegotiation - Enables TLS SCSV, .NET StrongCrypto & SystemDefaultTlsVersions, NTLMv2 only). Windows may use insecure connections for e.g. older software (compatibility reasons), so disabling them can cause issues with old software.

| Setting | Description | Registry security level |
| ---- | ---- | ---- |
| Send LM & NTLM responses | Client devices use LM and NTLM authentication, and they never use NTLMv2 session security. Domain controllers accept LM, NTLM, and NTLMv2 authentication. | 0 |
| Send LM & NTLM – use NTLMv2 session security if negotiated | Client devices use LM and NTLM authentication, and they use NTLMv2 session security if the server supports it. Domain controllers accept LM, NTLM, and NTLMv2 authentication. | 1 |
| Send NTLM response only | Client devices use NTLMv1 authentication, and they use NTLMv2 session security if the server supports it. Domain controllers accept LM, NTLM, and NTLMv2 authentication. | 2 |
| Send NTLMv2 response only | Client devices use NTLMv2 authentication, and they use NTLMv2 session security if the server supports it. Domain controllers accept LM, NTLM, and NTLMv2 authentication. | 3 |
| Send NTLMv2 response only. Refuse LM | Client devices use NTLMv2 authentication, and they use NTLMv2 session security if the server supports it. Domain controllers refuse to accept LM authentication, and they'll accept only NTLM and NTLMv2 authentication. | 4 |
| Send NTLMv2 response only. Refuse LM & NTLM | Client devices use NTLMv2 authentication, and they use NTLMv2 session security if the server supports it. Domain controllers refuse to accept LM and NTLM authentication, and they'll accept only NTLMv2 authentication. | 5 |

Level `5` gets applied.

> https://learn.microsoft.com/en-us/dotnet/framework/network-programming/tls#schusestrongcrypto  
> https://dirteam.com/sander/2019/07/30/howto-disable-weak-protocols-cipher-suites-and-hashing-algorithms-on-web-application-proxies-ad-fs-servers-and-windows-servers-running-azure-ad-connect/  
> https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/network-security-lan-manager-authentication-level

![](https://github.com/nohuto/win-config/blob/main/security/images/insecureconn.png?raw=true)

DTLS 1.2 & TLS 1.3:
```json
{
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\SecurityProviders\\SCHANNEL\\Protocols\\DTLS 1.2\\Server": {
    "Enabled": { "Type": "REG_DWORD", "Data": 1 },
    "DisabledByDefault": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\SecurityProviders\\SCHANNEL\\Protocols\\DTLS 1.2\\Client": {
    "Enabled": { "Type": "REG_DWORD", "Data": 1 },
    "DisabledByDefault": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\SecurityProviders\\SCHANNEL\\Protocols\\TLS 1.3\\Server": {
    "Enabled": { "Type": "REG_DWORD", "Data": 1 },
    "DisabledByDefault": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\SecurityProviders\\SCHANNEL\\Protocols\\TLS 1.3\\Client": {
    "Enabled": { "Type": "REG_DWORD", "Data": 1 },
    "DisabledByDefault": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SOFTWARE\\Microsoft\\.NETFramework\\v2.0.50727": {
    "SystemDefaultTlsVersions": { "Type": "REG_DWORD", "Data": 1 }
  },
  "HKLM\\SOFTWARE\\WOW6432Node\\Microsoft\\.NETFramework\\v2.0.50727": {
    "SystemDefaultTlsVersions": { "Type": "REG_DWORD", "Data": 1 }
  },
  "HKLM\\SOFTWARE\\Microsoft\\.NETFramework\\v4.0.30319": {
    "SystemDefaultTlsVersions": { "Type": "REG_DWORD", "Data": 1 }
  },
  "HKLM\\SOFTWARE\\WOW6432Node\\Microsoft\\.NETFramework\\v4.0.30319": {
    "SystemDefaultTlsVersions": { "Type": "REG_DWORD", "Data": 1 }
  },
  "HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\WinRM\\Client": {
    "AllowBasic": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\Lsa": {
    "restrictanonymoussam": { "Type": "REG_DWORD", "Data": 1 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Services\\LanManServer\\Parameters": {
    "restrictnullsessaccess": { "Type": "REG_DWORD", "Data": 1 },
    "AutoShareWks": { "Type": "REG_DWORD", "Data": 0 }
  },
  "HKLM\\SYSTEM\\CurrentControlSet\\Control\\LSA": {
    "restrictanonymous": { "Type": "REG_DWORD", "Data": 1 }
  }
}
```

# Enable USB Write Protection
Restricts write access to USB devices (read only). You can also change it with `diskpart`, by selecting the disk with `select disk` and chaning it to read only with `attributes disk set readonly` (revert it with `attributes disk clear readonly`).

Rather leave USB connection error notifications enabled, unless there's a specific reason for it.

# Increase TDR

"TDR stands for Timeout Detection and Recovery. This is a feature of the Windows operating system which detects response problems from a graphics card, and recovers to a functional desktop by resetting the card. If the operating system does not receive a response from a graphics card within a certain amount of time (default is 2 seconds), the operating system resets the graphics card."

> Disabling TDR removes a valuable layer of protection, so it is generally recommended that you keep it enabled.

| Registry key       | Value name           | Default value                | Description                                                                                               |
| ------------------ | -------------------- | ---------------------------- | --------------------------------------------------------------------------------------------------------- |
| TdrLevel           | `TdrLevel`           | `3` (TdrLevelRecover)        | Controls the GPU timeout behavior. `0` = disabled, `1` = bugcheck, `3` = reset/recover (Windows default). |
| TdrDelay           | `TdrDelay`           | `2` seconds                  | Timeout threshold before Windows starts TDR handling. Longer value = GPU gets more time.                  |
| TdrDdiDelay        | `TdrDdiDelay`        | `5` seconds                  | Extra time for driver/user-mode threads to exit after a timeout before VIDEO_TDR_FAILURE (0x116).         |
| TdrDebugMode       | `TdrDebugMode`       | `2`                          | TDR debug control: `0` break, `1` ignore, `2` recover (default), `3` always recover.                      |
| TdrLimitTime       | `TdrLimitTime`       | `60` seconds                 | Time window to count repeated TDRs before forcing a crash. Works with `TdrLimitCount`.                    |
| TdrLimitCount      | `TdrLimitCount`      | `5`                          | Max number of TDRs allowed within `TdrLimitTime` before Windows stops recovering and bugchecks.           |
| TdrTestMode        | `TdrTestMode`        | -                            | Reserved/test entry, not for normal use.                                                                  |
| TdrDodPresentDelay | `TdrDodPresentDelay` | `2` seconds (min 1, max 900) | Extra time for display-only drivers to report an async present before a TDR is triggered.                 |
| TdrDodVSyncDelay   | `TdrDodVSyncDelay`   | `2` seconds (min 1, max 900) | Time the VSync watchdog waits for VSync from a display-only driver before triggering TDR.                 |

> https://github.com/nohuto/windows-driver-docs/blob/staging/windows-driver-docs-pr/display/tdr-registry-keys.md  
> https://docs.nvidia.com/gameworks/content/developertools/desktop/timeout_detection_recovery.htm

Default values:  
`TdrLimitTime` - `60` (doc) / `5` driver?  
`TdrLimitCount` - `5`  
`TdrLevel` - `3` (`TdrLevelRecover`)  
`TdrDelay` - `2`  
`TdrDdiDelay` - `5`  
`TdrDebugMode` `2` (`TDR_DEBUG_MODE_RECOVER_NO_PROMPT`)

Driver code snippets:
```c
if ( v0 < 0 )
{
  v13 = 3; // TdrLevel
  v8 = 2; // TdrDelay
  v9 = 2; // TdrDodPresentDelay
  v10 = 2; // TdrDodVSyncDelay
  v11 = 5; // TdrDdiDelay
  v12 = 2; // TdrDebugMode
  WdLogSingleEntry1(3LL, v0);
  WdLogGlobalForLineNumber = 2211;
}

v67 = L"TdrLimitTime";
v66 = 288;
v68 = &v15;
v6 = v15;
v7 = 3600LL;
if (v15 <= 0xE10) { // 3600
  if (v15 < 5)
    v6 = 5; // set to 5 minimum
  else
    v6 = v15;
  dword_1C015B874 = v6;
} else {
  dword_1C015B874 = 3600; // clamp max
}

if (dword_1C015B874 != v15) {
    WdLogSingleEntry2(3LL, v15, (unsigned int)dword_1C015B874);
    WdLogGlobalForLineNumber = 2387;
}
```
> https://github.com/nohuto/win-registry/blob/main/records/Graphics-Drivers.txt  
> [security/assets | TdrInit.c](https://github.com/nohuto/win-config/blob/main/security/assets/TdrInit.c)

# Password Age

`/MAXPWAGE:{days | UNLIMITED}`:  
"Sets the maximum number of days that a password is valid. No limit is specified by using UNLIMITED. /MAXPWAGE can't be less than /MINPWAGE. The range is 1-999; the default is 90 days."

```powershell
NET ACCOUNTS  
[/FORCELOGOFF:{minutes | NO}]  
[/MINPWLEN:length]  
[/MAXPWAGE:{days | UNLIMITED}]  
[/MINPWAGE:days]  
[/UNIQUEPW:number] [/DOMAIN]
```

Congigure the policy yourself via `Computer Configuration > Windows Settings > Security Settings > Account Policies > Password Policy`:

![](https://github.com/nohuto/win-config/blob/main/security/images/passwordage.png?raw=true)

# Trusted Path Credential Prompting

This policy setting requires the user to enter Microsoft Windows credentials using a trusted path, to prevent a Trojan horse or other types of malicious code from stealing the user's Windows credentials.

```json
{
  "File": "CredUI.admx",
  "CategoryName": "CredUI",
  "PolicyName": "EnableSecureCredentialPrompting",
  "NameSpace": "Microsoft.Policies.CredentialsUI",
  "Supported": "WindowsVista",
  "DisplayName": "Require trusted path for credential entry",
  "ExplainText": "This policy setting requires the user to enter Microsoft Windows credentials using a trusted path, to prevent a Trojan horse or other types of malicious code from stealing the user\u2019s Windows credentials. Note: This policy affects nonlogon authentication tasks only. As a security best practice, this policy should be enabled. If you enable this policy setting, users will be required to enter Windows credentials on the Secure Desktop by means of the trusted path mechanism. If you disable or do not configure this policy setting, users will enter Windows credentials within the user\u2019s desktop session, potentially allowing malicious code access to the user\u2019s Windows credentials.",
  "KeyPath": [
    "HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\CredUI"
  ],
  "ValueName": "EnableSecureCredentialPrompting",
  "Elements": []
},
```

# Enable Dynamic Lock

Automatically locks your device when you're away. It requires Bluetooth to be active. This option is disabled by default.

Toggling it via `Accounts > Sign-in options`:
```c
// Enabled
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 1

// Disabled (default)
HKCU\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\EnableGoodbye	Type: REG_DWORD, Length: 4, Data: 0
```

---

Miscellaneous notes:

```json
{
  "File": "Passport.admx",
  "CategoryName": "MSPassportForWorkCategory",
  "PolicyName": "MSPassport_UseDynamicLock",
  "NameSpace": "Microsoft.Policies.MicrosoftPassportForWork",
  "Supported": "Windows_10_0_NOSERVER - At least Windows 10",
  "DisplayName": "Configure dynamic lock factors",
  "ExplainText": "Configure a comma separated list of signal rules in the form of xml for each signal type. If you enable this policy setting, these signal rules will be evaluated to detect user absence and automatically lock the device. If you disable or do not configure this policy setting, users can continue to lock with existing locking options. For more information see: https://go.microsoft.com/fwlink/?linkid=849684",
  "KeyPath": [
    "HKLM\\SOFTWARE\\Policies\\Microsoft\\PassportForWork\\DynamicLock"
  ],
  "ValueName": "DynamicLock",
  "Elements": [
    { "Type": "Text", "ValueName": "Plugins" },
    { "Type": "EnabledValue", "Data": "1" },
    { "Type": "DisabledValue", "Data": "0" }
  ]
},
```

# Sudo

[Sudo](https://github.com/microsoft/sudo) is a new way for users to run elevated commands (as an administrator) directly from an unelevated console session on Windows.

Note that sudo uses administrator previledges and doesn't include `TrustedInstaller`/`SYSTEM` previledges.

| Mode | Description |
| ---- | ---- |
| `forceNewWindow` | Runs the command elevated in a new console window. |
| `disableInput` | Runs elevated in the same window but blocks keyboard input while it runs. |
| `normal` | Runs elevated in the same window with normal input and output behavior. |

```json
{
  "File": "Sudo.admx",
  "CategoryName": "System",
  "PolicyName": "EnableSudo",
  "NameSpace": "Microsoft.Policies.DeveloperTools",
  "Supported": "Windows_11_0_NOSERVER - At least Windows 11",
  "DisplayName": "Configure the behavior of the sudo command",
  "ExplainText": "This policy setting controls use of the sudo.exe command line tool. If you enable this policy setting, then you may set a maximum allowed mode to run sudo in. This restricts the ways in which users may interact with command-line applications run with sudo. You may pick one of the following modes to allow sudo to run in: \"Disabled\": sudo is entirely disabled on this machine. When the user tries to run sudo, sudo will print an error message and exit. \"Force new window\": When sudo launches a command line application, it will launch that app in a new console window. \"Disable input\": When sudo launches a command line application, it will launch the app in the current console window, but the user will not be able to type input to the command line app. The user may also choose to run sudo in \"Force new window\" mode. \"Normal\": When sudo launches a command line application, it will launch the app in the current console window. The user may also choose to run sudo in \"Force new window\" or \"Disable input\" mode. If you disable this policy or do not configure it, the user will be able to run sudo.exe normally (after enabling the setting in the Settings app).",
  "KeyPath": [
    "HKLM\\Software\\Policies\\Microsoft\\Windows\\Sudo"
  ],
  "Elements": [
    { "Type": "Enum", "ValueName": "Enabled", "Items": [
        { "DisplayName": "Disabled", "Data": "0" },
        { "DisplayName": "Force new window", "Data": "1" },
        { "DisplayName": "Disable input", "Data": "2" },
        { "DisplayName": "Normal", "Data": "3" }
      ]
    }
  ]
}
```

> https://learn.microsoft.com/en-us/windows/advanced-settings/sudo/  
> https://devblogs.microsoft.com/commandline/introducing-sudo-for-windows/

# Enable Camera OSD Indicator

"`NoPhysicalCameraLED` indicates that there is no physical LED for the device's camera. An example of a physical LED for a camera is the small blue light that turns on whenever the camera is streaming video. This setting is used to indicate to the shell component that it will need to provide a small indicator in the user interface (UI) to show when video frames are streaming or not streaming to replace the notification by physical LED."

![](https://github.com/nohuto/win-config/blob/main/system/images/cameraosd.png?raw=true)

| Data | Description |
| :---: | --- |
| 0 | Does not draw an indicator in the UI to show when the camera is on or off. Instead, a physical LED exists to show when video frames are streaming or not streaming. This is the default value. |
| 1 | Draws an indicator in the UI to show when video frames are streaming or not streaming. |

> https://learn.microsoft.com/en-us/windows-hardware/customize/desktop/unattend/microsoft-windows-coremmres-nophysicalcameraled

```
\Registry\Machine\SOFTWARE\Microsoft\OEM\Device\Capture : NoPhysicalCameraLED
```
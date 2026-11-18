# BCD Edits

BCDEdit is the CL editor for the *Boot Configuration Database* (BCD), a registry hive under `HKLM\BCD00000000` backed by a hidden BCD file (UEFI: `\EFI\Microsoft\Boot\BCD`). The BCD replaced `boot.ini` (before Windows Vista) and stores per installation boot configuration. Each entry is a BCD object (GUID) under `Objects`, and each object has `Elements` subkeys with numeric element IDs. The `Element` value is the data that maps to a readable BCDEdit option or boot parameter. BCDEdit exposes symbolic names for objects/elements and can edit online or offline stores (`/store`), and the same data can be modified by loading the BCD hive (including remote hives).

BCDEdit is primarily used for boot troubleshooting, recovery, debugging, and security/boot behavior changes. Some may not be used on latest Windows versions anymore (e.g. HalpTscSyncPolicy, see pseudocode below).

## Registry Values

### Key & Value Structure

As kind of everything else, BCD edits are also stored in the registry:
```c
HKLM\BCD00000000\Objects

// Structure
HKLM\BCD00000000\Objects\{GUID} // {GUID} depends on the object, e.g. {bootmgr}, {current}, {globalsettings}
HKLM\BCD00000000\Objects\{GUID}\Elements\XXXXXXXX // XXXXXXXX is a specific setting for the object (8 digit)
HKLM\BCD00000000\Objects\{GUID}\Elements\XXXXXXXX : Element // (REG_BINARY/REG_MULTI_SZ/REG_SZ - depends on the setting) this value includes the state of the setting
```

See all object identifiers via `bcdedit /enum all /v` (`identifier`). Note that the list below uses `{bootmgr}`, `{current}` etc. which must be replaced by the actual GUID (see block above).

### Value/Data List

Here are elements which I tracked via Procmon (taken from default store and the MS documentation - [bcd-settings-and-bitlocker](https://learn.microsoft.com/en-us/windows/security/operating-system-security/data-protection/bitlocker/bcd-settings-and-bitlocker), [bcd-enumerations](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/bcd/bcd-enumerations)).

Note that this doesn't show default states, instead it shows several options and their possible states. And obviously the descriptions are most likely parsed, means that even "useless" descriptions will be included whenever the mentioned MS docs above include them.

- `{badmemory}` = RAM Defects
- `{bootloadersettings}` = Boot Loader Settings
- `{bootmgr}` = Windows Boot Manager
- `{current}` = Windows Boot Loader (current OS entry)
- `{dbgsettings}` = Debugger Settings
- `{emssettings}` = EMS Settings
- `{fwbootmgr}` = Firmware Boot Manager
- `{globalsettings}` = Global Settings
- `{hypervisorsettings}` = Hypervisor Settings
- `{memdiag}` = Windows Memory Diagnostic
- `{ramdiskoptions}` = Device Options for Ramdisk (boot.sdi)
- `{resume}` = Windows Resume Application (resumeobject)
- `{resumeloadersettings}` = Resume Loader Settings
- `{winre}` = Windows Recovery Environment Loader (recoverysequence)

#### Windows Boot Loader

```c
"HKLM\\BCD00000000\\Objects\\{current}\\Elements";
    "\\26000141"; "Element" = 01; // REG_BINARY, event = true, false = 00
    "\\26000116"; "Element" = 01; // REG_BINARY, hypervisorusevapic = true, false = 00
    "\\260000F8"; "Element" = 01; // REG_BINARY, hypervisordisableslat = true, false = 00
    "\\260000FC"; "Element" = 01; // REG_BINARY, hypervisoruselargevtlb = true, false = 00 - Increases virtual Translation Lookaside Buffer (TLB) size.
    "\\260000F2"; "Element" = 01; // REG_BINARY, hypervisordebug = true, false = 00 - Controls whether the hypervisor debugger is enabled.
    "\\260000E1"; "Element" = 00; // REG_BINARY, disableelamdrivers = false, true = 01 - The OS loader removes this entry for security reasons. This option can only be triggered by using the F8 menu.
    "\\260000C3"; "Element" = 01; // REG_BINARY, onetimeadvancedoptions = true, false = 00 - Controls whether the system boots to the legacy menu (F8 menu) on the next boot.
    "\\260000C4"; "Element" = 01; // REG_BINARY, onetimeoptionsedit = true, false = 00
    "\\260000B0"; "Element" = 01; // REG_BINARY, ems = true, false = 00 - Indicates whether EMS should be enabled in the kernel.
    "\\260000A5"; "Element" = 01; // REG_BINARY, disabledynamictick = true, false = 00 - https://noverse.dev/docs/win-config/system/timer-expiration/#kidynamictickdisablereason
    "\\260000A4"; "Element" = 01; // REG_BINARY, useplatformtick = true (forces platform clock source, often HPET), false = 00
    "\\260000A3"; "Element" = 01; // REG_BINARY, forcelegacyplatform = true, false = 00 - Forces the OS to assume the presence of legacy PC devices like CMOS and keyboard controllers.
    "\\260000A2"; "Element" = 01; // REG_BINARY, useplatformclock = true (forces the use of the platform clock as the system's performance counter), false = 00
    "\\260000A1"; "Element" = 01; // REG_BINARY, halbreakpoint = true, false = 00 - Indicates whether the HAL should call DbgBreakPoint at the start of HalInitSystem for phase 0 initialization of the kernel.
    "\\260000A0"; "Element" = 01; // REG_BINARY, debug = true, false = 00 - Indicates whether the kernel debugger should be enabled using the settings in the inherited debugger object.
    "\\26000091"; "Element" = 01; // REG_BINARY, sos = true, false = 00 - Indicates whether the system should display verbose information.
    "\\26000090"; "Element" = 01; // REG_BINARY, bootlog = true, false = 00 - Indicates whether the system should write logging information to %SystemRoot%\Ntbtlog.txt during initialization.
    "\\25000080"; "Element" = 0000000000000000; // REG_BINARY, safeboot = 0 (Minimal, SafeBoot\\Minimal), Network = 0100000000000000 (SafeBoot\\Network), DsRepair = 0200000000000000 (Directory Services Restore), Unset = not present
    "\\26000081"; "Element" = 01; // REG_BINARY, safebootalternateshell = true, false = 00 - Indicates whether the system should use the shell specified under the following registry key instead of the default shell: HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SafeBoot\AlternateShell.
    "\\26000070"; "Element" = 01; // REG_BINARY, usefirmwarepcisettings = true, false = 00 - Indicates whether the system should use I/O and IRQ resources created by the system firmware instead of using dynamically configured resources.
    "\\26000065"; "Element" = 01; // REG_BINARY, groupaware = true, false = 00 - This setting makes drivers group aware and can be used to determine improper group usage.
    "\\26000064"; "Element" = 01; // REG_BINARY, maxgroup = true, false = 00 - Maximizes the number of groups created when assigning nodes to processor groups.
    "\\26000062"; "Element" = 01; // REG_BINARY, maxproc = true, false = 00 - Indicates whether the system should use the maximum number of processors.
    "\\26000060"; "Element" = 01; // REG_BINARY, onecpu = true, false = 00 - Indicates whether the operating system should initialize or start non-boot processors.
    "\\26000054"; "Element" = 01; // REG_BINARY, uselegacyapicmode = true (forces X2APICPOLICY=DISABLE), false = 00 (no-op) - Used to force legacy APIC mode, even if the processors and chipset support extended APIC mode.
    "\\26000051"; "Element" = 01; // REG_BINARY, usephysicaldestination = true, false = 00 - Indicates whether to enable physical-destination mode for all APIC messages.
    "\\26000043"; "Element" = 01; // REG_BINARY, novga = true, false = 00 - Disables the use of VGA modes in the OS.
    "\\26000042"; "Element" = 01; // REG_BINARY, novesa = true, false = 00 - Indicates whether the VGA driver should avoid VESA BIOS calls.
    "\\26000041"; "Element" = 01; // REG_BINARY, quietboot = true, false = 00 - Indicates whether the system should initialize the VGA driver responsible for displaying simple graphics during the boot process. If not, there is no display is presented during the boot process.
    "\\26000040"; "Element" = 01; // REG_BINARY, vga = true, false = 00 - Indicates whether the system should use the standard VGA display driver instead of a high-performance display driver.
    "\\26000030"; "Element" = 01; // REG_BINARY, nolowmem = true, false = 00 - Indicates whether the system should utilize the first 4GB of physical memory. This option requires 5GB of physical memory, and on x86 systems it requires PAE to be enabled.
    "\\26000027"; "Element" = 01; // REG_BINARY, allowprereleasesignatures = true, false = 00 - Indicates whether the test code signing certificate is supported.
    "\\26000025"; "Element" = 01; // REG_BINARY, lastknowngood = true, false = 00 - Indicates that the system should use the last-known good settings.
    "\\26000024"; "Element" = 01; // REG_BINARY, nocrashautoreboot = true, false = 00 - Indicates that the system should not automatically reboot when it crashes.
    "\\26000010"; "Element" = 01; // REG_BINARY, detectkernelandhal = true, false = 00 - Indicates whether the operating system loader should determine the kernel and HAL to load based on the platform features.
    "\\26000004"; "Element" = 01; // REG_BINARY, stampdisks = true, false = 00
    "\\25000142"; "Element" = 0100000000000000; // REG_BINARY, vsmlaunchtype = 1 (auto), Off = 0000000000000000
    "\\25000130"; "Element" = 0000000000000000; // REG_BINARY, claimedtpmcounter = 0
    "\\2500012B"; "Element" = 0100000000000000; // REG_BINARY, xsavedisable = 1, 0 = 0000000000000000 - When set to a value other than zero (0), disables XSAVE functionality in the kernel.
    "\\2500012A"; "Element" = 0000000000000000; // REG_BINARY, xsaveprocessorsmask = 0
    "\\25000129"; "Element" = 0000000000000000; // REG_BINARY, xsaveremovefeature = 0
    "\\25000128"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature7 = 0
    "\\25000127"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature6 = 0
    "\\25000126"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature5 = 0
    "\\25000125"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature4 = 0
    "\\25000124"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature3 = 0
    "\\25000123"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature2 = 0
    "\\25000122"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature1 = 0
    "\\25000121"; "Element" = 0000000000000000; // REG_BINARY, xsaveaddfeature0 = 0
    "\\25000120"; "Element" = 0000000000000000; // REG_BINARY, xsavepolicy = 0
    "\\25000115"; "Element" = 0100000000000000; // REG_BINARY, hypervisoriommupolicy = 1 (enable), Default = 0000000000000000, Disable = 0200000000000000 - Controls whether the hypervisor uses an Input Output Memory Management Unit (IOMMU).
    "\\25000113"; "Element" = 0200000000000000; // REG_BINARY, hypervisorrootproc = 2
    "\\25000100"; "Element" = 0200000000000000; // REG_BINARY, tpmbootentropy = 2 (forceenable), Default = 0000000000000000, ForceDisable = 0100000000000000 - Determines whether entropy is gathered from the trusted platform module (TPM) to help seed the random number generator in the OS.
    "\\250000FB"; "Element" = 0100000000000000; // REG_BINARY, hypervisorrootprocpernode = 1 - Specifies the total number of virtual processors in the root partition that can be started within a pre-split Non-Uniform Memory Architecture (NUMA) node.
    "\\250000FA"; "Element" = 0200000000000000; // REG_BINARY, hypervisornumproc = 2 - Specifies the total number of logical processors that can be started in the hypervisor.
    "\\250000F7"; "Element" = 0000000000000000; // REG_BINARY, bootuxpolicy = 0 (Disabled), Basic = 0100000000000000, Standard = 0200000000000000 (defunct) - Values are Disabled (0), Basic (1), and Standard (2).
    "\\250000F0"; "Element" = 0000000000000000; // REG_BINARY, hypervisorlaunchtype = 0 (Off), Auto = 0100000000000000 - Controls the hypervisor launch type. Options are HyperVisorLaunchOff (0) and HypervisorLaunchAuto (1).
    "\\250000E0"; "Element" = 0000000000000000; // REG_BINARY, bootstatuspolicy = 0 (displayallfailures), IgnoreAllFailures = 0100000000000000, IgnoreBootFailures = 0300000000000000, IgnoreCheckpointFailures = 0400000000000000, IgnoreShutdownFailures = 0200000000000000, DisplayBootFailures = 0600000000000000, DisplayCheckpointFailures = 0700000000000000, DisplayShutdownFailures = 0500000000000000
    "\\250000C2"; "Element" = 0000000000000000; // REG_BINARY, bootmenupolicy = 0 (Legacy), Standard = 0100000000000000 - Defines the type of boot menu the system will use. For Windows 10/11, Windows 8.1, Windows 8 and Windows RT the default is Standard. For Windows Server 2012 R2, Windows Server 2012, the default is Legacy. When Legacy is selected, the Advanced options menu (F8) is available. When Standard is selected, the boot menu appears but only under certain conditions: for example, if there is a startup failure, if you are booting up from a repair disk or installation media, if you have configured multiple boot entries, or if you manually configured the computer to use Advanced startup. When Standard is selected, the F8 key is ignored during boot. - Defines the type of boot menus the system will use. Possible values include menupolicylegacy (0) or menupolicystandard (1).
    "\\250000C1"; "Element" = 0000000000000000; // REG_BINARY, driverloadfailurepolicy = 0 (fatal), UseErrorControl = 0100000000000000 - Indicates the driver load failure policy. Zero (0) indicates that a failed driver load is fatal and the boot will not continue, one (1) indicates that the standard error control is used.
    "\\250000A6"; "Element" = 0100000000000000; // REG_BINARY, tscsyncpolicy = 1 (legacy), Default = 0000000000000000, Enhanced = 0200000000000000 (HalpTscSyncPolicy symbol not present means this doesn't do anything), this should exist on older Windows versions and controls the TSC synchronization policy
    "\\25000072"; "Element" = 0100000000000000; // REG_BINARY, pciexpress = 1 (forcedisable), Default = 0000000000000000
    "\\25000071"; "Element" = 0100000000000000; // REG_BINARY, msi = 1 (forcedisable), Default = 0000000000000000, ForceEnable only via loadoptions FORCEMSI - The PCI Message Signaled Interrupt (MSI) policy. Zero (0) indicates default, and one (1) indicates that MSI interrupts are disabled.
    "\\25000066"; "Element" = 4000000000000000; // REG_BINARY, groupsize = 64 - Specifies the size of all processor groups. Must be set to a power of 2 (max of 64, see pseudocode below).
    "\\25000063"; "Element" = 0100000000000000; // REG_BINARY, configflags = 1 - Indicates whether processor specific configuration flags are to be used.
    "\\25000061"; "Element" = 0200000000000000; // REG_BINARY, numproc = 2 - The maximum number of processors that can be utilized by the system, all other processors are ignored.
    "\\25000055"; "Element" = 0200000000000000; // REG_BINARY, x2apicpolicy = 2 (enable), Default = 0000000000000000, Disable = 0100000000000000 - Enables the use of extended APIC mode, if supported. Zero (0) indicates default behavior, one (1) indicates that extended APIC mode is disabled, and two (2) indicates that extended APIC mode is enabled. The system defaults to using extended APIC mode if available.
    "\\25000050"; "Element" = 0100000000000000; // REG_BINARY, clustermodeaddressing = 1 - Indicates that cluster-mode APIC addressing should be utilized, and the value is the maximum number of processors per cluster.
    "\\25000052"; "Element" = 0000000000000000; // REG_BINARY, restrictapicluster = 0 - The maximum number of APIC clusters that should be used by cluster-mode addressing.
    "\\25000032"; "Element" = 0004000000000000; // REG_BINARY, increaseuserva = 1024 - Increasing this value from the default 2GB decreases the amount of virtual address space available to the system and device drivers. The amount of memory that should be utilized by the process address space, in bytes. This value should be between 2GB and 3GB.
    "\\25000033"; "Element" = 0000000000000000; // REG_BINARY, perfmem = 0 - BcdOSLoaderInteger_PerformaceDataMemory (integer)
    "\\25000031"; "Element" = 8000000000000000; // REG_BINARY, removememory = 128 - The amount of memory the system should ignore.
    "\\25000021"; "Element" = 0100000000000000; // REG_BINARY, pae = 1 (forceenable), Default = 0000000000000000, ForceDisable = 0200000000000000 - If this value is not specified, the default is PaePolicyDefault which follows the rule "enable PAE if hot-pluggable memory is above 4GB"
    "\\25000020"; "Element" = 0000000000000000; // REG_BINARY, nx = 0 (OptIn = DEP for Windows components & opted in 32-bit apps), OptOut = 0100000000000000 (DEP for all 32-bit apps except exemptions), AlwaysOff = 0200000000000000, AlwaysOn = 0300000000000000 - If this value is not specified, the default is NxPolicyAlwaysOff.
    "\\23000003"; "Element" = {resume}; // REG_SZ, resumeobject = {resume} - The default boot environment application to load if the user does not select one.
    "\\22000053"; "Element" = \EFI\Microsoft\Boot\EVStore.dat; // REG_SZ, evstore = \EFI\Microsoft\Boot\EVStore.dat
    "\\22000041"; "Element" = recovery message; // REG_SZ, fverecoverymessage = recovery message
    "\\22000040"; "Element" = https://example.com/recovery; // REG_SZ, fverecoveryurl = https://example.com/recovery
    "\\22000013"; "Element" = kdcom.dll; // REG_SZ, dbgtransport = kdcom.dll - The transport DLL to be loaded by the operating system loader. This value overrides the default Kdcom.dll.
    "\\22000012"; "Element" = hal.dll; // REG_SZ, hal = hal.dll - The HAL to be loaded by the operating system loader. This value overrides the default HAL.
    "\\22000011"; "Element" = ntoskrnl.exe; // REG_SZ, kernel = ntoskrnl.exe - The kernel to be loaded by the operating system loader. This value overrides the default kernel.
    "\\22000002"; "Element" = \Windows; // REG_SZ, systemroot = \Windows - This value is reserved.
    "\\21000001"; "Element" = partition=C:; // REG_BINARY, filedevice = partition=C: - This value is reserved.
    "\\17000077"; "Element" = 7500001500000000; // REG_BINARY, allowedinmemorysettings = 0x15000075 - Indicates whether or not an in-memory BCD setting passed between boot apps will trigger BitLocker recovery. This value should not be modified as it could trigger a BitLocker recovery action.
    "\\1600007B"; "Element" = 01; // REG_BINARY, forcefipscrypto = true, false = 00 (BitLocker validation profile)
    "\\16000079"; "Element" = 01; // REG_BINARY, forcefipscrypto = true, false = 00 (BCD library enum, the one above is probably the used one) - Force the use of FIPS cryptography checks on boot applications.
    "\\16000074"; "Element" = 01; // REG_BINARY, bootshutdowndisabled = true, false = 00 - Disables the 1-minute timer that triggers shutdown on boot error screens, and the F8 menu, on UEFI systems.
    "\\16000072"; "Element" = 01; // REG_BINARY, nokeyboard = true, false = 00
    "\\1600006C"; "Element" = 01; // REG_BINARY, bootuxdisabled = true, false = 00 - This setting disables the progress bar and default Windows logo. If a custom text string has been defined, it is also disabled by this setting.
    "\\16000069"; "Element" = 01; // REG_BINARY, custom:16000069 = true, false = 00 - disables the loading circle while booting (see image at the bottom)
    "\\16000067"; "Element" = 01; // REG_BINARY, custom:16000067 = true, false = 00 - disables the Windows logo while booting (see image at the bottom)
    "\\16000060"; "Element" = 01; // REG_BINARY, isolatedcontext = true, false = 00 - Do not modify this setting. If this setting is removed from a Windows 8 installation, it will not boot. If this setting is added to a Windows 7 installation, it will not boot. - This setting is used to differentiate between the Windows 7 and Windows 8 implementations of UEFI.
    "\\16000054"; "Element" = 01; // REG_BINARY, highestmode = true, false = 00 - Forces highest available graphics resolution at boot. This value can only be used on UEFI systems.
    "\\16000053"; "Element" = 01; // REG_BINARY, restartonfailure = true, false = 00 - If enabled, specifies that boot error screens are not shown when OS launch errors occur, and the system is reset rather than exiting directly back to the firmware.
    "\\16000050"; "Element" = 01; // REG_BINARY, consoleextendedinput = true, false = 00 - Specifies that legacy BIOS systems should use INT 16h Function 10h for console input instead of INT 16h Function 0h.
    "\\16000049"; "Element" = 01; // REG_BINARY, testsigning = true, false = 00 - Indicates whether the test code signing certificate is supported.
    "\\16000048"; "Element" = 01; // REG_BINARY, nointegritychecks = true, false = 00 - This value is ignored by Windows 7 and Windows 8. - Disables integrity checks. Cannot be set when secure boot is enabled.
    "\\16000046"; "Element" = 01; // REG_BINARY, graphicsmodedisabled = true, false = 00 - Indicates whether graphics mode is disabled and boot applications must use text mode display.
    "\\16000041"; "Element" = 01; // REG_BINARY, optionsedit = true, false = 00 - Indicates whether the boot options editor is enabled.
    "\\16000040"; "Element" = 01; // REG_BINARY, advancedoptions = true, false = 00 - Indicates whether the advanced options boot menu (F8) is displayed.
    "\\1600001E"; "Element" = 01; // REG_BINARY, vm = true, false = 00
    "\\1600000F"; "Element" = 01; // REG_BINARY, traditionalkseg = true, false = 00
    "\\16000009"; "Element" = 01; // REG_BINARY, recoveryenabled = true, false = 00 - Indicates whether the recovery sequence executes automatically if the boot application fails. Otherwise, the recovery sequence only runs on demand.
    "\\15000081"; "Element" = 0000000000000000; // REG_BINARY, logcontrol = 0
    "\\15000088"; "Element" = 0000000000000000; // REG_BINARY, linearaddress57 = 0 (Default), OptOut = 0100000000000000, OptIn = 0200000000000000
    "\\15000066"; "Element" = 0300000000000000; // REG_BINARY, displaymessageoverride = 3 (Recovery), Resume = 0100000000000000
    "\\15000052"; "Element" = 0000000000000000; // REG_BINARY, graphicsresolution = 0 (1024x768), 800x600 = 0100000000000000, 1024x600 = 0200000000000000 - Forces a specific graphics resolution at boot. Possible values include GraphicsResolution1024x768 (0), GraphicsResolution800x600 (1), and GraphicsResolution1024x600 (2).
    "\\15000051"; "Element" = 0000000000000000; // REG_BINARY, initialconsoleinput = 0
    "\\1500004C"; "Element" = 0000000000000000; // REG_BINARY, volumebandid = 0 (fvebandid) - This value (if present) should not be modified.
    "\\1500004B"; "Element" = 0000000000000000; // REG_BINARY, integrityservices = 0 (Default, Enabled - Kernel Mode Code Signing), Enable = 0100000000000000, Disable = 0200000000000000
    "\\15000047"; "Element" = 0000000000000000; // REG_BINARY, configaccesspolicy = 0 (Default, allow MMCONFIG), DisallowMmConfig = 0100000000000000 (use CF8/CFC instead) - Indicates the access policy for PCI configuration space.
    "\\15000042"; "Element" = 0000000000000000; // REG_BINARY, keyringaddress = 0
    "\\1500000E"; "Element" = 0000000000000000; // REG_BINARY, avoidlowphysicalmemory = 0 - Specifies a minimum physical address to use in the boot environment.
    "\\1500000D"; "Element" = 0000000000000000; // REG_BINARY, relocatephysicalmemory = 0 - This value is not used in Windows 8 or Windows Server 2012. - Relocates physical memory on certain AMD processors.
    "\\1500000C"; "Element" = 0000000000000000; // REG_BINARY, firstmegabytepolicy = 0 (UseNone, use none of first MB), UseAll = 0100000000000000 (use all of first MB), UsePrivate = 0200000000000000 (reserved) - Indicates how the first megabyte of memory is to be used.
    "\\15000007"; "Element" = 0000008000000000; // REG_BINARY, truncatememory = 2147483648 - Maximum physical address a boot environment application should recognize. All memory above this address is ignored.
    "\\14000008"; "Element" = {winre}; // REG_MULTI_SZ, recoverysequence = {winre} - List of boot environment applications to be executed if the associated application fails. The applications are executed in the order they appear in this list.
    "\\14000006"; "Element" = {bootloadersettings}; // REG_MULTI_SZ, inherit = {bootloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\1200004A"; "Element" = \Windows\Fonts; // REG_SZ, fontpath = \Windows\Fonts - Use caution when modifying this setting. Boot screens will not work if the correct fonts are not present. - Overrides the default location of the boot fonts.
    "\\12000044"; "Element" = \Boot\BCD-Log; // REG_SZ, bsdlogpath = \Boot\BCD-Log - Allows a path override for the bootstat.dat log file in the boot manager and winload.exe.
    "\\12000030"; "Element" = NOCRASHONCTRL; // REG_SZ, loadoptions = NOCRASHONCTRL - String that is appended to the load options string passed to the kernel to be consumed by kernel-mode components. This is useful for communicating with kernel-mode components that are not BCD-aware.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows 11; // REG_SZ, description = Windows 11 - Display name of the boot environment application.
    "\\12000002"; "Element" = \Windows\system32\winload.efi; // REG_SZ, path = \Windows\system32\winload.efi - Path to a boot environment application.
    "\\11000043"; "Element" = partition=C:; // REG_BINARY, bsdlogdevice = partition=C: - Allows a device override for the bootstat.dat log in the boot manager and winload.exe.
    "\\11000001"; "Element" = partition=C:; // REG_BINARY, device = partition=C: - Device on which a boot environment application resides.
```

#### Windows Resume Application

```c
"HKLM\\BCD00000000\\Objects\\{resume}\\Elements";
    "\\26000006"; "Element" = 00; // REG_BINARY, debugoptionenabled = false, true = 01 - Enables kernel debugging on resume from hibernate.
    "\\26000004"; "Element" = 01; // REG_BINARY, pae = true, false = 00
    "\\26000003"; "Element" = 01; // REG_BINARY, usecustomsettings = true, false = 00 - Allows the resume loader BCD object to use custom settings. If this setting is not specified or is not enabled, default settings are applied by the OS before resume.
    "\\25000008"; "Element" = 0100000000000000; // REG_BINARY, bootmenupolicy = 1 (Standard), Legacy = 0000000000000000 - Defines the type of boot menus the system will use. Possible values are menupolicylegacy (0) or menupolicystandard (1). The default setting is menupolicylegacy (0).
    "\\25000007"; "Element" = 0000000000000000; // REG_BINARY, bootux = 0 (Disabled), Basic = 0100000000000000, Standard = 0200000000000000 (defunct)
    "\\22000002"; "Element" = \hiberfil.sys; // REG_SZ, filepath = \hiberfil.sys - This value is reserved.
    "\\21000026"; "Element" = partition=C:; // REG_BINARY, custom:21000026 = partition=C:
    "\\21000005"; "Element" = partition=C:; // REG_BINARY, associatedosdevice = partition=C: - Specifies the name of the OS device associated with the hibernated OS. This is only used if the hibernation file is not stored on the OS device.
    "\\21000001"; "Element" = partition=C:; // REG_BINARY, filedevice = partition=C: - This value is reserved.
    "\\17000077"; "Element" = 7500001500000000; // REG_BINARY, allowedinmemorysettings = 0x15000075 - Indicates whether or not an in-memory BCD setting passed between boot apps will trigger BitLocker recovery. This value should not be modified as it could trigger a BitLocker recovery action.
    "\\16000060"; "Element" = 01; // REG_BINARY, isolatedcontext = true, false = 00 - Do not modify this setting. If this setting is removed from a Windows 8 installation, it will not boot. If this setting is added to a Windows 7 installation, it will not boot. - This setting is used to differentiate between the Windows 7 and Windows 8 implementations of UEFI.
    "\\16000009"; "Element" = 01; // REG_BINARY, recoveryenabled = true, false = 00 - Indicates whether the recovery sequence executes automatically if the boot application fails. Otherwise, the recovery sequence only runs on demand.
    "\\14000008"; "Element" = {winre}; // REG_MULTI_SZ, recoverysequence = {winre} - List of boot environment applications to be executed if the associated application fails. The applications are executed in the order they appear in this list.
    "\\14000006"; "Element" = {resumeloadersettings}; // REG_MULTI_SZ, inherit = {resumeloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Resume Application; // REG_SZ, description = Windows Resume Application - Display name of the boot environment application.
    "\\12000002"; "Element" = \Windows\system32\winresume.efi; // REG_SZ, path = \Windows\system32\winresume.efi - Path to a boot environment application.
    "\\11000001"; "Element" = partition=C:; // REG_BINARY, device = partition=C: - Device on which a boot environment application resides.
```

#### Windows Boot Manager

```c
"HKLM\\BCD00000000\\Objects\\{bootmgr}\\Elements";
    "\\27000030"; "Element" = 0000000000000000; // REG_BINARY, customactionslist = <integer list> - For more information see Custom Bootstrap Actions in Windows Vista.
    "\\26000031"; "Element" = 01; // REG_BINARY, persistbootsequence = true, false = 00 - Controls whether a boot sequence persists across multiple boots.
    "\\26000028"; "Element" = 01; // REG_BINARY, processcustomactionsfirst = true, false = 00 - Controls whether custom actions are processed before a boot sequence.
    "\\26000021"; "Element" = 01; // REG_BINARY, noerrordisplay = true, false = 00 - Indicates whether the display of errors should be suppressed. If this setting is enabled, the boot manager exits to the multi-OS menu on OS launch error.
    "\\26000020"; "Element" = 01; // REG_BINARY, displaybootmenu = true, false = 00 - Forces the display of the legacy boot menu, regardless of the number of OS entries in the BCD store and their BcdOSLoaderInteger_BootMenuPolicy.
    "\\26000005"; "Element" = 01; // REG_BINARY, attemptresume = true, false = 00 - Indicates that a resume operation should be attempted during a system restart.
    "\\25000004"; "Element" = 0300000000000000; // REG_BINARY, timeout = 3 - The boot menu time-out determines how long the boot menu is displayed before the default boot entry is loaded. It is calibrated in seconds. If you want extra time to choose the operating system that loads on your computer, you can extend the time-out value. Or, you can shorten the time-out value so that the default operating system starts faster. - If this value is not specified, the boot manager waits for the user to make a selection. - The maximum number of seconds a boot selection menu is to be displayed to the user. The menu is displayed until the user selects an option or the time-out expires.
    "\\24000010"; "Element" = {memdiag}; // REG_MULTI_SZ, toolsdisplayorder = {memdiag} - The boot manager tools display order list.
    "\\24000002"; "Element" = {current}; // REG_MULTI_SZ, bootsequence = {current} - If the firmware boot manager does not support loading multiple applications, this list cannot contain more than one entry. - List of boot environment applications the boot manager should execute. The applications are executed in the order they appear in this list.
    "\\24000001"; "Element" = {current}; // REG_MULTI_SZ, displayorder = {current} - The order in which BCD objects should be displayed. Objects are displayed using the string specified by the BcdLibraryString_Description element.
    "\\23000006"; "Element" = {resume}; // REG_SZ, resumeobject = {resume} - The resume application object.
    "\\23000003"; "Element" = {current}; // REG_SZ, default = {current} - The default boot environment application to load if the user does not select one.
    "\\22000023"; "Element" = \EFI\Microsoft\Boot\BCD; // REG_SZ, bcdfilepath = \EFI\Microsoft\Boot\BCD - The boot application.
    "\\21000022"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, bcddevice = partition=\Device\HarddiskVolume1 - The device on which the boot application resides.
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Boot Manager; // REG_SZ, description = Windows Boot Manager - Display name of the boot environment application.
    "\\12000002"; "Element" = \EFI\MICROSOFT\BOOT\BOOTMGFW.EFI; // REG_SZ, path = \EFI\MICROSOFT\BOOT\BOOTMGFW.EFI - Path to a boot environment application.
    "\\11000001"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, device = partition=\Device\HarddiskVolume1 - Device on which a boot environment application resides.
```

#### Windows Memory Diagnostic

```c
"HKLM\\BCD00000000\\Objects\\{memdiag}\\Elements";
    "\\26000004"; "Element" = 01; // REG_BINARY, failuresenabled = true, false = 00
    "\\25000009"; "Element" = 0000000000000000; // REG_BINARY, chckrfailcount = 0
    "\\25000007"; "Element" = 0000000000000000; // REG_BINARY, matsfailcount = 0
    "\\25000006"; "Element" = 0000000000000000; // REG_BINARY, invcfailcount = 0
    "\\25000005"; "Element" = 0000000000000000; // REG_BINARY, stridefailcount = 0
    "\\25000003"; "Element" = 0000000000000000; // REG_BINARY, failurecount = 0 - The number of pages that contain errors. This is useful for simulating error flows in the absence of bad physical memory.
    "\\25000002"; "Element" = 0000000000000000; // REG_BINARY, testmix = 0
    "\\25000001"; "Element" = 0000000000000000; // REG_BINARY, passcount = 0 - If this value is not specified, the default is to run memory diagnostic tests until the computer is powered off or the user logs off. - The number of passes for the current test mix.
    "\\1600000B"; "Element" = 01; // REG_BINARY, badmemoryaccess = true, false = 00 - If TRUE, indicates that a boot application can use memory listed in the BcdLibraryIntegerList_BadMemoryList.
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-US; // REG_SZ, locale = en-US - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Memory Diagnostic; // REG_SZ, description = Windows Memory Diagnostic - Display name of the boot environment application.
    "\\12000002"; "Element" = \EFI\Microsoft\Boot\memtest.efi; // REG_SZ, path = \EFI\Microsoft\Boot\memtest.efi - Path to a boot environment application.
    "\\11000001"; "Element" = partition=\Device\HarddiskVolume1; // REG_BINARY, device = partition=\Device\HarddiskVolume1 - Device on which a boot environment application resides.
```

#### RAM Defects

```c
"HKLM\\BCD00000000\\Objects\\{badmemory}\\Elements";
    "\\1700000A"; "Element" = 0000000000000000; // REG_BINARY, badmemorylist = <integer list> - List of page frame numbers describing faulty memory in the system.
```

#### Windows Recovery Environment Loader

```c
"HKLM\\BCD00000000\\Objects\\{winre}\\Elements";
    "\\46000010"; "Element" = 01; // REG_BINARY, custom:46000010 = true, false = 00
    "\\26000022"; "Element" = 01; // REG_BINARY, winpe = true, false = 00 - Indicates that the system should be started in Windows Preinstallation Environment (Windows PE) mode.
    "\\250000C2"; "Element" = 0100000000000000; // REG_BINARY, bootmenupolicy = 1 (Standard), Legacy = 0000000000000000 - Defines the type of boot menus the system will use. Possible values include menupolicylegacy (0) or menupolicystandard (1). The default value is menupolicylegacy (0).
    "\\25000020"; "Element" = 0000000000000000; // REG_BINARY, nx = 0 (OptIn), OptOut = 0100000000000000, AlwaysOff = 0200000000000000, AlwaysOn = 0300000000000000 - If this value is not specified, the default is NxPolicyAlwaysOff. - The no-execute page protection policy.
    "\\22000002"; "Element" = \windows; // REG_SZ, systemroot = \windows - This value is reserved.
    "\\21000001"; "Element" = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions}; // REG_BINARY, osdevice = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions} - This value is reserved.
    "\\15000065"; "Element" = 0300000000000000; // REG_BINARY, displaymessage = 3 (Recovery), Resume = 0100000000000000
    "\\14000006"; "Element" = {bootloadersettings}; // REG_MULTI_SZ, inherit = {bootloadersettings} - List of BCD objects from which the current object should inherit elements.
    "\\12000005"; "Element" = en-us; // REG_SZ, locale = en-us - Preferred locale, in RFC 3066 format.
    "\\12000004"; "Element" = Windows Recovery Environment; // REG_SZ, description = Windows Recovery Environment - Display name of the boot environment application.
    "\\12000002"; "Element" = \windows\system32\winload.efi; // REG_SZ, path = \windows\system32\winload.efi - Path to a boot environment application.
    "\\11000001"; "Element" = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions}; // REG_BINARY, device = ramdisk=[C:]\Recovery\WindowsRE\Winre.wim,{ramdiskoptions} - Device on which a boot environment application resides.
```

#### Device Options for Ramdisk

```c
"HKLM\\BCD00000000\\Objects\\{ramdiskoptions}\\Elements";
    "\\3600000B"; "Element" = 01; // REG_BINARY, ramdisktftpvarwindow = true, false = 00 - Enables or disables the TFTP variable window size extension.
    "\\3600000A"; "Element" = 01; // REG_BINARY, ramdiskmulticasttftpfallback = true, false = 00 (ramdiskmctftpfallback) - Enables fallback to TFTP if multicast fails.
    "\\36000009"; "Element" = 01; // REG_BINARY, ramdiskmulticastenabled = true, false = 00 (ramdiskmcenabled) - Enables or disables multicast for the RAM disk WIM file.
    "\\36000008"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpwindowsize = 0 - Defines the TFTP window size for the RAM disk WIM file.
    "\\36000007"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpblocksize = 0 - Defines the TFTP block size for the RAM disk Windows Imaging (WIM) file.
    "\\36000006"; "Element" = 01; // REG_BINARY, ramdiskexportascd = true, false = 00 - Enables exporting the RAM disk as a CD.
    "\\35000008"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpwindowsize = 0 (BitLocker list uses 0x35000008)
    "\\35000007"; "Element" = 0000000000000000; // REG_BINARY, ramdisktftpblocksize = 0 (BitLocker list uses 0x35000007)
    "\\35000005"; "Element" = 0000000000000000; // REG_BINARY, ramdiskimagelength = 0 - The length of the image for the RAM disk.
    "\\35000002"; "Element" = 0000000000000000; // REG_BINARY, tftpclientport = 0 - If this value is not specified, the default TFTP protocol port is used. - The IP port number to be used for Trivial File Transfer Protocol (TFTP) reads.
    "\\35000001"; "Element" = 0000000000000000; // REG_BINARY, ramdiskimageoffset = 0 - The RAM disk image offset.
    "\\32000004"; "Element" = \Recovery\WindowsRE\boot.sdi; // REG_SZ, ramdisksdipath = \Recovery\WindowsRE\boot.sdi - The path from the root of the SDI device to the RAM disk file.
    "\\31000003"; "Element" = partition=C:; // REG_BINARY, ramdisksdidevice = partition=C: - The device that contains the SDI object.
    "\\12000004"; "Element" = Windows Recovery; // REG_SZ, description = Windows Recovery - Display name of the boot environment application.
```

#### Global Settings

```c
"HKLM\\BCD00000000\\Objects\\{globalsettings}\\Elements";
    "\\16000069"; "Element" = 01; // REG_BINARY, custom:16000069 = true, false = 00
    "\\16000067"; "Element" = 01; // REG_BINARY, custom:16000067 = true, false = 00
    "\\14000006"; "Element" = {dbgsettings};{emssettings};{badmemory}; // REG_MULTI_SZ, inherit = {dbgsettings}, {emssettings}, {badmemory} - List of BCD objects from which the current object should inherit elements.
```

#### Resume Loader Settings

```c
"HKLM\\BCD00000000\\Objects\\{resumeloadersettings}\\Elements";
    "\\14000006"; "Element" = {globalsettings}; // REG_MULTI_SZ, inherit = {globalsettings} - List of BCD objects from which the current object should inherit elements.
```

#### Boot Loader Settings

```c
"HKLM\\BCD00000000\\Objects\\{bootloadersettings}\\Elements";
    "\\14000006"; "Element" = {globalsettings};{hypervisorsettings}; // REG_MULTI_SZ, inherit = {globalsettings}, {hypervisorsettings} - List of BCD objects from which the current object should inherit elements.
```

#### Debugger Settings

```c
"HKLM\\BCD00000000\\Objects\\{dbgsettings}\\Elements";
    "\\1600001C"; "Element" = 01; // REG_BINARY, debuggernetdhcp = true, false = 00 - Controls the use of DHCP by the network debugger. Setting this to false causes the OS to only use link-local addresses.
    "\\16000017"; "Element" = 01; // REG_BINARY, debuggerignoreusermodeexceptions = true, false = 00 - If TRUE, the debugger will ignore user mode exceptions and only stop for kernel mode exceptions.
    "\\16000010"; "Element" = 01; // REG_BINARY, debuggerenabled = true, false = 00 - Indicates whether the boot debugger should be enabled.
    "\\1500001B"; "Element" = 0000000000000000; // REG_BINARY, debuggernetport = 0 - Defines the network port for the network debugger.
    "\\1500001A"; "Element" = 0000000000000000; // REG_BINARY, debuggernethostip = 0 - Defines the host IP address for the network debugger.
    "\\15000018"; "Element" = 0000000000000000; // REG_BINARY, debuggerstartpolicy = 0 - Indicates the debugger start policy.
    "\\15000015"; "Element" = 0000000000000000; // REG_BINARY, debugger1394channel = 0 - Channel number for 1394 debugging.
    "\\15000014"; "Element" = 00c2010000000000; // REG_BINARY, debuggerserialbaudrate = 115200 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Baud rate for serial debugging.
    "\\15000013"; "Element" = 0100000000000000; // REG_BINARY, debuggerserialport = 1 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Serial port number for serial debugging.
    "\\15000012"; "Element" = 0000000000000000; // REG_BINARY, debuggerserialportaddress = 0 - I/O port address for the serial debugger.
    "\\15000011"; "Element" = 0400000000000000; // REG_BINARY, debugtype = 4 (Local - undocumented), Serial = 0000000000000000, 1394 = 0100000000000000, USB = 0200000000000000, NET = 0300000000000000 - Debugger type.
    "\\1200001D"; "Element" = testkey; // REG_SZ, debuggernetkey = testkey - Holds the key used to encrypt the network debug connection.
    "\\12000019"; "Element" = 0.25.0; // REG_SZ, debuggerbusparams = 0.25.0 - Defines the PCI bus, device, and function numbers of the debugging device. For example, 1.5.0 describes the debugging device on bus 1, device 5, function 0.
    "\\12000016"; "Element" = usbtarget; // REG_SZ, debuggerusbtargetname = usbtarget - The target name for the USB debugger. The target name is arbitrary but must match between the debugger and the debug target.
```

#### EMS Settings

```c
"HKLM\\BCD00000000\\Objects\\{emssettings}\\Elements";
    "\\16000020"; "Element" = 00; // REG_BINARY, bootems = false, true = 01 - Indicates whether EMS redirection should be enabled.
    "\\15000023"; "Element" = 00c2010000000000; // REG_BINARY, emsbaudrate = 115200 - Baud rate for EMS redirection.
    "\\15000022"; "Element" = 0100000000000000; // REG_BINARY, emsport = 1 - If this value is not specified, the default is specified by the SPCR ACPI table settings. - COM port number for EMS redirection.
```

#### Firmware Boot Manager

```c
"HKLM\\BCD00000000\\Objects\\{fwbootmgr}\\Elements";
    "\\25000004"; "Element" = 0100000000000000; // REG_BINARY, timeout = 1 - If this value is not specified, the boot manager waits for the user to make a selection. - The maximum number of seconds a boot selection menu is to be displayed to the user. The menu is displayed until the user selects an option or the time-out expires.
    "\\24000001"; "Element" = {bootmgr}; // REG_MULTI_SZ, displayorder = {bootmgr} - The order in which BCD objects should be displayed. Objects are displayed using the string specified by the BcdLibraryString_Description element.
```

#### Hypervisor Settings

```c
"HKLM\\BCD00000000\\Objects\\{hypervisorsettings}\\Elements";
    "\\26000114"; "Element" = 00; // REG_BINARY, hypervisordhcp = false, true = 01 - Controls use of DHCP by the network debugger used with the hypervisor. Setting this to false forces local link only address.
    "\\250000FE"; "Element" = 50c3000000000000; // REG_BINARY, hypervisorhostport = 50000 - Defines the network UDP port for the network debugger.
    "\\250000FD"; "Element" = 0201a8c000000000; // REG_BINARY, hypervisorhostip = 3232235778 (192.168.1.2) - Defines the host IPv4 address for the network debugger.
    "\\250000F6"; "Element" = 0000000000000000; // REG_BINARY, hypervisorchannel = 0 - Specifies the channel number for 1394 debugging.
    "\\250000F5"; "Element" = 00c2010000000000; // REG_BINARY, hypervisorbaudrate = 115200 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Specifies the baud rate for serial debugging.
    "\\250000F4"; "Element" = 0100000000000000; // REG_BINARY, hypervisordebugport = 1 - If this value is not specified, the default is specified by the DBGP ACPI table settings. - Specifies the serial port number for serial debugging.
    "\\250000F3"; "Element" = 0000000000000000; // REG_BINARY, hypervisordebugtype = 0 (Serial), 1394 = 0100000000000000, NET = 0300000000000000 - Controls the hypervisor debugger type. Can be set to SERIAL (0), 1394 (1), or NET (2).
    "\\22000110"; "Element" = testkey; // REG_SZ, hypervisorusekey = testkey - Holds the key used to encrypt the network debug connection used with the hypervisor.
    "\\220000F9"; "Element" = 0.25.0; // REG_SZ, hypervisorbusparams = 0.25.0 - Defines the PCI bus, device, and function numbers of the debugging device used with the hypervisor. For example, 1.5.0 describes the debugging device on bus 1, device 5, function 0.
```

## [Windows Internals](https://github.com/nohuto/Windows-Books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit1.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit2.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit3.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit4.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/bcdedit5.png?raw=true)

## Pseudocode Notes

Notes on several features in relation of [HalpMiscGetParameters](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-25H2/ntoskrnl/HalpMiscGetParameters.c).

```c
lkd> db HalpInterruptX2ApicPolicy l1
fffff807`8d20a5dc  01

if ( strstr(v3, "X2APICPOLICY=ENABLE") )
    HalpInterruptX2ApicPolicy = 1;

if ( strstr(v3, "X2APICPOLICY=DISABLE") )
    HalpInterruptX2ApicPolicy = 0;

if ( strstr(v3, "USELEGACYAPICMODE") )
    HalpInterruptX2ApicPolicy = 0; // force disable
```
```c
lkd> db HalpTscSyncPolicy l1
Couldnt resolve error at HalpTscSyncPolicy // doesn't exist

HalpTscSyncPolicy = 1; // TSCSYNCPOLICY=LEGACY
HalpTscSyncPolicy = 2; // TSCSYNCPOLICY=ENHANCED
```

`bcdedit /set loadoptions SYSTEMWATCHDOGPOLICY=DISABLED`
```c
if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=DISABLED") )
{
    HalpTimerWatchdogDisable = 1;
}
else if ( strstr(v3, "SYSTEMWATCHDOGPOLICY=PHYSICALONLY") )
{
    HalpTimerWatchdogPhysicalOnly = 1;
}

lkd> db HalpTimerWatchdogDisable l1
fffff803`d21c0712  00 // default
```
```c
lkd> db HalpTimerPlatformSourceForced l1
fffff803`d21c25d0  00
lkd> db HalpTimerPlatformClockSourceForced l1
fffff803`d21c2678  00

if ( strstr(v3, "USEPLATFORMCLOCK") )
    HalpTimerPlatformSourceForced = 1;

if ( strstr(v3, "USEPLATFORMTICK") )
    HalpTimerPlatformClockSourceForced = 1;
```
```c
v17 = strstr(v3, "GROUPSIZE");
if ( v17 )
{
    while ( 1 )
    {
        v18 = *v17;
        if ( !*v17 || v18 == 32 || (unsigned __int8)(v18 - 48) <= 9u )
            break;
        ++v17;
    }
    HalpMaximumGroupSize = atoi(v17);
    if ( (unsigned int)(HalpMaximumGroupSize - 1) > 0x3F )
        HalpMaximumGroupSize = 64; // clamp to 1..64
}

strstr(v3, "HALTPROFILINGPOLICY=BLOCKED");
strstr(v3, "HALTPROFILINGPOLICY=RELAXED");
return strstr(v3, "HALTPROFILINGPOLICY=RESTRICTED"); // only returns pointer if present
```
```c
lkd> db HalpMiscDiscardLowMemory l1
fffff803`d21bff79  01 // USENONE / USEPRIVATE?
lkd> db HalpHvCpuManager l1
fffff804`c27c0490  00

if ( (unsigned int)HalpInterruptModel() == 1 )
    HalpMiscDiscardLowMemory = 1; // default if HalpInterruptModel() == 1

if ( HalpHvCpuManager )
{
    v19[0] = 0;
    if ( (unsigned __int8)HalpGetCpuInfo(0LL, 0LL, 0LL, v19) )
    {
        if ( v19[0] == 2 && (__readmsr(0xFEu) & 0x8000) != 0 )
        HalpMiscDiscardLowMemory = 1; // 1 if HV CPU manager + CPU type 2 + MSR 0xFE bit 15 set
    }
}
if (strstr(BootOptions, "FIRSTMEGABYTEPOLICY=USEALL") || // one of them have to be true to get 0
    (HalpIsMicrosoftCompatibleHvLoaded() && !HalpHvCpuManager)) // system running under hypervisor & not HalpHvCpuManager
{
    HalpMiscDiscardLowMemory = 0; // forced 0 if above is true
}
```
```c
v3 = *(const char **)(a1 + 216);
if ( v3 )
{
    strstr(*(const char **)(a1 + 216), "SAFEBOOT:"); // does nothing here

    if ( strstr(v3, "ONECPU") )
        HalpInterruptProcessorCap = 1;

    if ( strstr(v3, "USEPHYSICALAPIC") )
        HalpInterruptPhysicalModeOnly = 1;

    if ( strstr(v3, "BREAK") )
        HalpMiscDebugBreakRequested = 1;
}
```
```c
v4 = strstr(v3, "MAXPROCSPERCLUSTER");
if ( v4 )
{
    while ( 1 )
    {
        v5 = *v4;
        if ( !*v4 || v5 == 32 || (unsigned __int8)(v5 - 48) <= 9u )
            break;
        ++v4;
    }
    v6 = atoi(v4);
    HalpInterruptForceClusterMode(v6);
}

v7 = strstr(v3, "MAXAPICCLUSTER");
if ( v7 )
{
    while ( 1 )
    {
        v8 = *v7;
        if ( !*v7 || v8 == 32 || (unsigned __int8)(v8 - 48) <= 9u )
            break;
        ++v7;
    }
    v9 = atoi(v7);
    if ( v9 )
        LODWORD(HalpInterruptMaxCluster) = v9;
}
```
```c
if ( strstr(v3, "CONFIGACCESSPOLICY=DISALLOWMMCONFIG") )
    HalpAvoidMmConfigAccessMethod = 1; // force avoid
```
```c
if ( strstr(v3, "MSIPOLICY=FORCEDISABLE") ) // HalpInterruptSetMsiOverride(0)
{
    v10 = 0LL;
}
else
{
    if ( !strstr(v3, "FORCEMSI") ) // HalpInterruptSetMsiOverride(1)
        goto LABEL_46;
    LOBYTE(v10) = 1;
}
HalpInterruptSetMsiOverride(v10);
```

## Custom Edits

`custom:16000067 true` disables the Windows logo while booting:

![](https://github.com/nohuto/win-config/blob/main/system/images/logo.png?raw=true)

`custom:16000069 true` disables the loading circle while booting:

![](https://github.com/nohuto/win-config/blob/main/system/images/load.png?raw=true)

## Default Entries

All existing default boot loader entries (25H2):

```powershell
Windows Boot Loader
-------------------
identifier              {current}
device                  partition=C:
path                    \WINDOWS\system32\winload.exe
description             Windows 11
locale                  en-US
inherit                 {bootloadersettings}
recoverysequence        {1c945b5b-7654-11f1-adb7-b9bb2ba517f9}
displaymessageoverride  Recovery
recoveryenabled         Yes
allowedinmemorysettings 0x15000075
osdevice                partition=C:
systemroot              \WINDOWS
resumeobject            {1c945b59-7654-11f1-adb7-b9bb2ba517f9}
nx                      OptIn
bootmenupolicy          Standard
debug                   No
```


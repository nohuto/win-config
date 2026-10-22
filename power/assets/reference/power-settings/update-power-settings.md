---
title: Update power settings | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/update-power-settings
description: This section contains information about how you can update the power settings that you configured using the Windows provisioning framework.
---

# Update power settings | Microsoft Learn

Before including your Power Configuration provisioning package in your device image, please consider a mechanism to update the OEM-generated Power provisioning package after the device is in market. Here are additional notes on image configuration and updates.

1. The OEM-generated Power provisioning package needs to be excluded from the PBR migration to avoid duplicate entries, see [Exclude Files and Settings](https://learn.microsoft.com/en-us/windows/deployment/usmt/usmt-exclude-files-and-settings).

    - To test that the exclusion file was successful, you will need to have a factory image with PBR implemented. There should also only be one OEM-generated Power provisioning package in the %WINDIR%\Provisioning\Packages folder.

    Example:

    ```xml
    <migration urlid="http://www.microsoft.com/migration/1.0/migxmlext/MyFileExclusions">
      <component type="Documents" context="System">
        <displayName>File exclusions</displayName>
        <role role="Data">
          <rules>       
            <unconditionalExclude>
              <objectSet>
                <pattern type="File">%SystemDrive%\Windows\Provisioning\Packages* [*]</pattern>
              </objectSet>
            </unconditionalExclude>
          </rules>
        </role>
      </component>
    </migration>
    ```
2. Customization configured by the OEM-generated Power provisioning package will need to be maintained by the OEM. As such, you should ensure you have a mechanism to update these in the future.

    - Update of the package is handled by a driver package and Windows Update
    - You will need to ensure you have an existing device driver on the device for the power component and the INF file is set to copy the PPKG
    - Follow the instructions in [this document](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-copyfiles-directive) to author the INF file

        Example:

        ```xml
        [SourceDisksNames]
        1 = %DiskId1%
        
        [SourceDisksFiles]
        ContosoPowerCustomization.ppkg = 1
        ContosoPowerCustomizationWithDataClass.xml = 1
        ; other driver package files omitted from example for brevity
        
        [DestinationDirs]
        PowerCustomization.CopyList =10,Provisioning\Package
        ; other CopyFiles sections in DestinationDirs omitted from example for brevity
        
        ; Manufacturer and Models sections omitted for brevity. Assume Models section indicates a DDInstall section of ContosoInstallSection
        
        [ContosoInstallSection]
        CopyFiles=PowerCustomization.CopyList
        
        [PowerCustomization.CopyList]
        ContosoPowerCustomization.ppkg
        ContosoPowerCustomizationWithDataClass.xml
        ```
    - The driver package needs to be preloaded on your factory image so that if you update the driver package on Windows Update in the future the system will scan for and find a newer version of this driver package to download and install.
    - You should test the update mechanism via Windows Update in the same mechanism as you would test driver package updates for a prerelease system or driver package.
    - If you have an alternate mechanism to update the OEM-generated Power provisioning package, ensure that it works both on the factory image, and on the device package after push button reset is run to test the end user scenario.

Note

By design, the provisioning packages are not applied when the PPKG are copied to the specified location. Instead, the PPKG is applied on the following events:

- After OS Reboot when system is idle
- After User Login when system is idle

Power provisioning packages require SYSTEM privileges, or else provisioning will faill with `HRESULT=0xc0000061, STATUS_PRIVILEGE_NOT_HELD` error. The provisioning engine will apply the power provisioning package with the correct context after OS reboots when system is idle.

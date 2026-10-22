---
title: Configure power settings | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-power-settings
description: This section contains information about the power settings that you can configure using the Windows provisioning framework. Each power setting topic includes the allowed values, meaning, and common usage scenarios for the setting.
note: This was modified by Nohuto using PowrProf API
---

# Configure power settings | Microsoft Learn

This section contains information about the power settings that you can configure using the Windows provisioning framework. Each power setting topic includes the allowed values, meaning, and common usage scenarios for the setting.

Tip

The primary audience for these topics is Original Equipment Manufacturers (OEMs). If you're a Windows device owner (consumer) and would like to learn more about power settings in Windows, please see [Shut down, sleep, or hibernate your PC](https://aka.ms/AAszj4j) on Microsoft's support site.

## Use Windows Configuration Designer to configure power settings

To configure the power settings, you will first create a provisioning package using [Windows Configuration Designer](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-install-icd). You will then edit the customizations.xml file contained in the package to include your power settings. Use the XML file as one of the inputs to the Windows Configuration Designer command-line to generate either a provisioning package or a Windows image that contains the power settings. For information on how to use the Windows Configuration Designer CLI, see [Use the Windows Configuration Designer command-line interface](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-command-line).

The power settings are not visible in the Windows Configuration Designer UI but appear under the main `Common\Power` namespace. This namespace is further divided into various groups including:

- `Policy\Settings` which includes the following subgroups:

    - `AdaptivePowerBehavior`
    - `Processor`
    - `Battery`
    - `Button`
    - `Display`
    - `Disk`
    - `EnergySaver`
    - `PCIExpress`
    - `Sleep`
    - `Misc`
- `Controls` which includes the following settings:

    - `LidNotificationsAreReliable`
    - `EnableInputSuppression`

The following example shows what your Windows provisioning answer file might look like after you've written it.

```XML
<?xml version="1.0" encoding="utf-8"?>
<WindowsCustomizatons>
  <PackageConfig xmlns="urn:schemas-Microsoft-com:Windows-ICD-Package-Config.v1.0">
    <ID>{<!-- ID needs to be the unique GUID for the package -->}</ID>
    <Name>CustomOEM.Power.Settings.Control</Name>
    <Version>1.0</Version>
    <OwnerType>OEM</OwnerType>
  </PackageConfig>

  <Settings xmlns="urn:schemas-microsoft-com:windows-provisioning">
    <Customizations>
      <Common>
          <Power>
            <Policy>
              <Settings>
                <Sleep>
                  <SchemePersonality>
                    <Default SchemeAlias="Balanced">
                      <Setting>
                      <!-- Duration of time after sleep that the system automatically wakes and 
                           enters hibernate in seconds -->
                         <HibernateTimeout> 
                          <AcValue>1800</AcValue> <!-- 30 minutes -->
                          <DcValue>1800</DcValue> <!-- 30 minutes -->
                        </HibernateTimeout>
                      </Setting>
                    </Default>
                   </SchemePersonality>
                 </Sleep>
                 <Misc>
                   <SchemePersonality>
                     <Default SchemeAlias="Balanced">
                       <Setting>
                       <!-- Enables/Disables only WiFi connection during standby -->
                         <AllowWifiInStandby>
                           <AcValue>0</AcValue>
                           <DcValue>0</DcValue>
                         </AllowWifiInStandby>
                       </Setting>
                     </Default>
                   </SchemePersonality>
                  </Misc>
             </Settings>
           </Policy>
        </Power>
      </Common>
    </Customizations>
  </Settings>
</WindowsCustomizatons>
```

## Use Powercfg.exe to control power schemes

You can use the powercfg.exe tool to control power schemes by providing the GUID or alias for the setting. For more information on how to use this tool, see [Powercfg command-line options](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options).

## Slide show

- **GUID:** 309dce9b-bef4-4119-9921-a851fb12f0f4
- **PowerCfg alias:**`N/A`
- **Description:** Specify when you want the desktop background slide show to be available.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Available | 0 | Available |
| 001 | Paused | 1 | The slide show is paused to save power. |

## Power Saving Mode

- **GUID:** 12bbebe6-58d6-4636-95bb-3217ef867c1a
- **PowerCfg alias:**`N/A`
- **Description:** Control the power saving mode of wireless adapters.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Maximum Performance | c1ab164f-834f-463d-8544-a40e93ab5472 | Achieve maximum wireless performance with no power savings. |
| 001 | Low Power Saving | 787cbccb-cd4b-4776-8be5-5f8ae4726f2b | Achieve minimum power savings. |
| 002 | Medium Power Saving | 6728e412-40d1-4ab0-8d15-f3c56f303eb5 | Balance between performance and power savings based on network traffic. |
| 003 | Maximum Power Saving | e012dc0f-8397-46b5-a060-0de84f96388e | Achieve maximum power savings. |

## Hub Selective Suspend Timeout

- **GUID:** 0853a681-27c8-4100-a2fd-82013e970683
- **PowerCfg alias:**`N/A`
- **Description:** This value will be used as idle timeouts for all USB hubs

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100,000 |
| Increment | 1 |
| Units | Millisecond |

## USB selective suspend setting

- **GUID:** 48e6b7a6-50f5-4782-a5d4-53bb8f07e226
- **PowerCfg alias:**`N/A`
- **Description:** Specify whether USB selective suspend is turned on or off

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Do not enable USB selective suspend |
| 001 | Enabled | 1 | Enable USB selective suspend |

## Setting IOC on all TDs

- **GUID:** 498c044a-201b-4631-a522-5c744ed4e678
- **PowerCfg alias:**`N/A`
- **Description:** Should IOC be set for all TDs

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Set IOC only for the last TD in a transfer |
| 001 | Enabled | 1 | Set IOC for for all TDs |

## USB 3 Link Power Mangement

- **GUID:** d4e98f31-5ffe-4ce1-be31-1b38b384c009
- **PowerCfg alias:**`N/A`
- **Description:** Specifies the power management policy to use for USB 3 links when they are idle

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Do not enable the U1 U2 states |
| 001 | Minimum power savings | 1 | Enable the U1 U2 states but choose conservative timeout values to optimize for peformance |
| 002 | Moderate power savings | 2 | Enable the U1 U2 states and choose optimal timeout values to balance power and peformance |
| 003 | Maximum power savings | 3 | Enable the U1 U2 states and choose aggressive timeout values to optimize for power |

## Execution Required power request timeout

- **GUID:** 3166bc41-7e98-4e03-b34e-ec0f5f2b218e
- **PowerCfg alias:**`EXECTIME`
- **Description:** Specifies Execution Required power request timeout

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## IO coalescing timeout

- **GUID:** c36f0eb4-2988-4a70-8eee-0884fc2c2433
- **PowerCfg alias:**`COALTIME`
- **Description:** Specifies IO coalescing timeout

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Milliseconds |

## Processor Idle Resiliency Timer Resolution

- **GUID:** c42b79aa-aa3a-484b-a98f-2cf32aa90a28
- **PowerCfg alias:**`PROCIR`
- **Description:** Specifies Processor Idle Resiliency Timer Resolution

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 65,000 |
| Increment | 1 |
| Units | Milliseconds |

## Deep Sleep Enabled/Disabled

- **GUID:** d502f7ee-1dc7-4efd-a55d-f04b6f5c0545
- **PowerCfg alias:**`DEEPSLEEP`
- **Description:** Specifies if Deep Sleep is Enabled

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Deep Sleep Disabled | 0 | Deep Sleep Disabled |
| 001 | Deep Sleep Enabled | 1 | Deep Sleep Enabled |

## Interrupt Steering Mode

- **GUID:** 2bfc24f9-5ea2-4801-8213-3dbae01aa39d
- **PowerCfg alias:**`MODE`
- **Description:** Interrupt Steering Mode

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Default | 0 | Default |
| 001 | Any processor | 1 | Route interrupts to any processor |
| 002 | Any unparked processor with time delay | 2 | Route interrupts to any unparked processor with time delay |
| 003 | Any unparked processor | 3 | Route interrupts to any unparked processor |
| 004 | Lock Interrupt Routing | 4 | Lock Interrupt Routing |
| 005 | Processor 0 | 5 | Route interrupts to Processor 0 |
| 006 | Processor 1 | 6 | Route interrupts to Processor 1 |

## Target Load

- **GUID:** 73cde64d-d720-4bb2-a860-c755afe77ef2
- **PowerCfg alias:**`PERPROCLOAD`
- **Description:** Target Load for each Processor

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 10,000 |
| Increment | 1 |
| Units | Tenths of a percent |

## Unparked time trigger

- **GUID:** d6ba4903-386f-4c2c-8adb-5c21b3328d25
- **PowerCfg alias:**`UNPARKTIME`
- **Description:** Time a processor must remain unparked before interrupts are moved onto it

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100,000 |
| Increment | 1 |
| Units | Milliseconds |

## GPU preference policy

- **GUID:** dd848b2a-8a5d-4451-9ae2-39cd41658f6c
- **PowerCfg alias:**`GPUPREFERENCEPOLICY`
- **Description:** Policy to determine GPU preference

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | None | 0 | No preference |
| 001 | Low Power | 1 | Prefer low-power GPU |

## Standby Reserve Time

- **GUID:** 468fe7e5-1158-46ec-88bc-5b96c9e44fd0
- **PowerCfg alias:**`STANDBYRESERVETIME`
- **Description:** Specifies the minimun active usage time that the battery charge level should allow before taking an adaptive action

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Standby Reset Percentage

- **GUID:** 49cb11a5-56e2-4afb-9d38-3df47872e21b
- **PowerCfg alias:**`STANDBYRESETPERCENT`
- **Description:** Specifies percentage of battery charge which resets the adaptive budget

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Non-sensor Input Presence Timeout

- **GUID:** 5adbbfbc-074e-4da1-ba38-db8b36b2c8f3
- **PowerCfg alias:**`NSENINPUTPRETIME`
- **Description:** Specifies Non-sensor Input Presence Timeout

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Standby Budget Grace Period

- **GUID:** 60c07fe1-0556-45cf-9903-d56e32210242
- **PowerCfg alias:**`STANDBYBUDGETGRACEPERIOD`
- **Description:** Specifies the grace period before taking an adaptive action when the system has exceeded its standby budget

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## User Presence Prediction mode

- **GUID:** 82011705-fb95-4d46-8d35-4042b1d20def
- **PowerCfg alias:**`USERPRESENCEPREDICTION`
- **Description:** Specify User Presence Prediction mode for your computer

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Disable User Presence Prediction mode. |
| 001 | Enabled | 1 | Enable User Presence Prediction mode. |

## Standby Budget Percent

- **GUID:** 9fe527be-1b70-48da-930d-7bcf17b44990
- **PowerCfg alias:**`STANDBYBUDGETPERCENT`
- **Description:** Specifies percentage of battery per unit of time allowed to be consumed by the system while it is in standby

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 100 |
| Increment | 1 |
| Units | % |

## Standby Reserve Grace Period

- **GUID:** c763ee92-71e8-4127-84eb-f6ed043a3e3d
- **PowerCfg alias:**`STANDBYRESERVEGRACEPERIOD`
- **Description:** Specifies the grace period before taking an adaptive action when the system is below the reserve battery charge level

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 4,294,967,295 |
| Increment | 1 |
| Units | Seconds |

## Video playback quality bias

- **GUID:** 10778347-1370-4ee0-8bbd-33bdacaade49
- **PowerCfg alias:**`N/A`
- **Description:** Specify the policy to bias video playback quality.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Video playback power-saving bias | 0 | Video playback quality would be biased towards battery life. |
| 001 | Video playback performance bias | 1 | Video playback quality would be biased towards performance. |

## When playing video

- **GUID:** 34c7b99f-9a6d-4b3c-8dc7-b6693b78cef4
- **PowerCfg alias:**`N/A`
- **Description:** The power optimization mode used by your computer's video playback pipeline

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Optimize video quality | 5c67a112-a4c9-483f-b4a7-1d473becafdc | Gives the optimum video quality during playback |
| 001 | Balanced | 651288e5-a7ed-4076-a96b-6cc62d848fe1 | A balance of video quality and power savings |
| 002 | Optimize power savings | 16260968-c914-4aa1-8736-b7a6f3c5ae9b | Gives optimum power savings during playback |

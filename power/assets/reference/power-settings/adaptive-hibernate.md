---
title: Adaptive Hibernate Overview | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/adaptive-hibernate
description: Adaptive hibernate provides triggers to allow the system to hibernate intelligently.
---

# Adaptive Hibernate Overview | Microsoft Learn

Users can set the Hibernate option in their Windows devices to put the system into a low power state when the system is not in use. The current logic for hibernate in the OS relies on adaptive hibernate to put the system in hibernate after draining a certain percentage of battery capacity during Modern Standby.

OEMs or users can also configure a fixed doze to hibernate timer. However, the timer-based logic has significant user experience drawbacks. A fixed doze timer can result in the system fully draining the battery in standby if the drain happened within the doze timeout or cut short a low-drain Modern Standby experience by hibernating at the doze timeout. Consequently, it is preferable to leverage adaptive hibernate to hibernate dynamically based on battery drain.

Adaptive hibernate provides triggers which allow the system to hibernate intelligently. These triggers provide the following benefits:

- Eliminate resuming to a dead battery.
- Provide a great [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby) experience by ensuring that the system remains in Modern Standby for as long as possible.

To support the adaptive hibernate triggers, the system is enabled with default values. However, OEMs can program these triggers to ensure that machines hibernate to provide the best possible experience to users.

## System Requirements

The triggers apply to Modern Standby systems only.

## Default Behavior

Machines will have adaptive hibernate timeout enabled by default; however, OEMs can configure the settings using a provisioning package file. See the following sections for more information on how to do this.

Note

Windows has a 15-minute grace period before either of these triggers are applied. This is to ensure that the system does not rapidly transition into hibernate.

## Hibernate Triggers

Adaptive hibernate settings (standby budget settings and standby reserve time setting) are exposed as hidden power settings. The settings are applied on DC only and have no impact on AC.

### Standby Budget Settings

The following table lists the settings you can use to set the standby budget, which drain allowed during standby. If the device drains less than the StandbyBudgetPercent over the StandbyBudgetRefreshInterval, it is allowed to stay in standby. Otherwise, the device will hibernate. If the device is draining less than the StandbyBudgetPercent, then it will continue to refresh the budget up to the StandbyBudgetRefreshCount.

| Budget Setting | Definition | Exposed As | Powercfg Command |
| --- | --- | --- | --- |
| [StandbyBudgetPercent](standbybudgetpercent.md) | Defines the battery drain % that the user is allowed in a refresh interval. Default is 5%. | Power setting | `powercfg /setdcvalueindex scheme_current sub_presence standbybudgetpercent` |
| [StandbyBudgetRefreshInterval](#standby-budget-settings) | Defines the length of time before the StandbyBudgetPercent is refreshed. If the StandbyBudgetPercent is reached before this time, the device will hibernate, otherwise it will stay in Standby. Default is 12 hours. | Power setting | `powercfg /setdcvalueindex SCHEME_CURRENT SUB_PRESENCE STANDBYBUDGETREFRESHINTERVAL` |
| [StandbyBudgetRefreshCount](#standby-budget-settings) | Defines the number of times the budget will refresh if the StandbyBudgetPercent is not reached within the StandbyBudgetRefreshInterval. Default is 4 refreshes. | Power setting | `powercfg /setdcvalueindex SCHEME_CURRENT SUB_PRESENCE STANDBYBUDGETREFRESHCOUNT` |

You can also configure these settings using a custom provisioning package file for OEM images. For more information about powercfg, see [Powercfg command-line options](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options).

### Standby Reserve Time Setting

Reserve time is the amount of time the user is guaranteed to have the screen on after the system resumes from standby or hibernate. The following table lists the settings you can use to set the reserve time.

| Budget Setting | Definition | Exposed As | Powercfg Command |
| --- | --- | --- | --- |
| [StandbyReserveTime](standbyreservetime.md) | Defines the screen on time, in seconds, that will be available to the user after standby exits and the screen turns on. Default is 1200 seconds. | Power setting | `powercfg /setdcvalueindex scheme_current sub_presence standbyreservetime` |

You can also configure these settings using a custom provisioning package file for OEM images. For more information about powercfg, see [Powercfg command-line options](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/powercfg-command-line-options).

## Windows Provisioning Package Sample

You can use the Windows Provisioning framework to configure the adaptive hibernate settings described in this section. First, create a provisioning package using [Windows Configuration Designer](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-install-icd). You will then edit the customizations.xml file contained in the package to include your power settings, which appear under the `Common\Power\Policy\Settings\AdaptivePowerBehavior` namespace. Use the XML file as one of the inputs to the Windows Configuration Designer command-line interface to generate either a provisioning package that contains the power settings. You can then apply the provisioning package to the image. For information on how to use the Windows Configuration Designer CLI, see [Use the Windows Configuration Designer command-line interface](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-command-line).

The following example shows what your Windows provisioning answer file might look like after you've written it to configure adaptive hibernate settings.

```xml
<?xml version="1.0" encoding="utf-8"?>
<WindowsCustomizations>
  <PackageConfig xmlns="urn:schemas-Microsoft-com:Windows-ICD-Package-Config.v1.0">
    <ID>{XXXX GUID}</ID>  <!-- ID needs to be unique GUID for the package -->
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
                    <AdaptivePowerBehavior>
                       <SchemePersonality>
                          <Default SchemeAlias="Balanced">
                             <Setting>
                                <!-- After entering standby, battery drain percentage allowed before the device transitions to hibernate. -->
                                <StandbyBudgetPercent>
                                   <DcValue>3</DcValue>
                                </StandbyBudgetPercent>
                                <!-- Specifies the minimum remaining battery time required for active use for the amount of time.-->
                                <StandbyReserveTime>
                                   <DcValue>600</DcValue>
                                </StandbyReserveTime>
                             </Setting>
                          </Default>
                       </SchemePersonality>
                    </AdaptivePowerBehavior>
                 </Settings>
              </Policy>
           </Power>
        </Common>
     </Customizations>
  </Settings>
</WindowsCustomizations>
```

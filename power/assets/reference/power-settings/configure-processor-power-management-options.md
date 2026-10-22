---
title: Processor power management options | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-processor-power-management-options
description: The Windows 10 processor power management (PPM) algorithms implement OS-level functionality that allows the OS to efficiently use the available processing resources on a platform by balancing the user's expectations of performance and energy efficiency.
note: This was modified by Nohuto using PowrProf API
---

# Processor power management options | Microsoft Learn

The Windows 10 processor power management (PPM) algorithms implement OS-level functionality that allows the OS to efficiently use the available processing resources on a platform by balancing the user's expectations of performance and energy efficiency.

The algorithms have the following characteristics:

- They scale from big servers to tablet form factors.
- They are customizable through a statically configurable power policy infrastructure.
- They are hierarchical and abstracted in a manner that separates platform-agnostic portions of the algorithms from platform-specific portions.

At a high-level, the Windows PPM is made up of the following parts:

- **Core parking engine** - Makes global scalability decisions about the workload and determines the optimum set of compute cores to execute with.
- **Performance state engine** - Makes per-processor performance scaling decisions.
- **Platform specific controls** - Implements the mechanics of state transitions and optionally provides feedback about the effectiveness of OS state decisions and runtime platform constraints.

IHV partners can enable preliminary validation and measurement of the effects of the policy controls on different hardware configurations.

## Power profiles

You can use the Windows Provisioning framework to configure the processor power settings described in this section. First, create a provisioning package using [Windows Configuration Designer](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-install-icd). You will then edit the customizations.xml file contained in the package to include your power settings, which appear under the `Common\Power\Policy\Settings\Processor` namespace. Use the XML file as one of the inputs to the Windows Configuration Designer command-line interface to generate either a provisioning package that contains the power settings. You can then apply the provisioning package to the image. For information on how to use the Windows Configuration Designer CLI, see [Use the Windows Configuration Designer command-line interface](https://learn.microsoft.com/en-us/windows/configuration/provisioning-packages/provisioning-command-line).

The processor namespace is divided into sets of identical power processor configurations called power profiles. The power profiles are used by the power processor engine to adapt the performance and parking algorithm on various system use cases.

Windows 10 supports the following profiles:

- *Default* profile is the configuration set that is active most of the time. These settings are indentical to those for the balanced power scheme. This provides for an alternative method to configure the balanced power scheme settings via the windows provisioning framework.
- *LowLatency* is the profile that is activated during boot and during app launch time.
- *LowPower* is the profile that is activated during the buffering phase of media playback scenarios. This profile is not applicable if Media [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service) is configured.
- *GameMode* profile is enabled when the 'Game Mode' setting toggle is turned on and the user is playing a game. You can use this profile to finetune processor settings for your devices with Game Mode.
- *Mixed Reality* is the profile that is activated when a Windows Mixed Reality headset is connected to the system and the user is interacting with a MR application.
- *Constrained* is a profile activated by the battery saver feature on Windows 10 for desktop editions (Home, Pro, Enterprise, and Education). This is not available on Windows 10 Mobile.
- *ScreenOff* is a profile used on [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby) systems. It is engaged when is screen is turned off -- no remote desktop connections and there are no system & execution required power requests outstanding, no mobile hotspot is engaged. It is disengaged when the system enters the sleep or display turn back on. Please refer to diagram in the section [Summary of key points](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby-states). This profile corresponds to Presence to DAM phase in that diagram.
- *Standby* is a profile used on [Modern Standby](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby) systems. It is engaged when the system enters its long term sleep phase -- all system quiescing behavior has completed. It is disengaged when the system awakes from the sleep. Please refer to diagram in the section [Summary of key points](https://learn.microsoft.com/en-us/windows-hardware/design/device-experiences/modern-standby-states). This profile corresponds to Low power phase to Resiliency phase in that diagram.

Each profile supports the following configuration settings:

- [CPMinCores](options-for-core-parking-cpmincores.md)
- [CPMaxCores](options-for-core-parking-cpmaxcores.md)
- [CPIncreaseTime](options-for-core-parking-cpincreasetime.md)
- [CPDecreaseTime](options-for-core-parking-cpdecreasetime.md)
- [CPConcurrency](options-for-core-parking-cpconcurrency.md)
- [CPDistribution](options-for-core-parking-cpdistribution.md)
- [CPHeadroom](options-for-core-parking-cpheadroom.md)
- [CpLatencyHintUnpark](options-for-core-parking-cplatencyhintunpark.md)
- [IdleDemoteThreshold](options-for-perf-state-engine-idledemotethreshold.md)
- [IdlePromoteThreshold](options-for-perf-state-engine-idlepromotethreshold.md)
- [MaxPerformance](options-for-perf-state-engine-maxperformance.md)
- [MinPerformance](options-for-perf-state-engine-minperformance.md)
- [PerfIncreasePolicy](options-for-perf-state-engine-perfincreasepolicy.md)
- [PerfIncreaseThreshold](options-for-perf-state-engine-perfincreasethreshold.md)
- [PerfIncreaseTime](options-for-perf-state-engine-perfincreasetime.md)
- [PerfDecreasePolicy](options-for-perf-state-engine-perfdecreasepolicy.md)
- [PerfDecreaseThreshold](options-for-perf-state-engine-perfdecreasethreshold.md)
- [PerfDecreaseTime](options-for-perf-state-engine-perfdecreasetime.md)
- [PerfLatencyHint](options-for-perf-state-engine-perflatencyhint.md)
- [LatencyHintEpp](options-for-perf-state-engine-latencyhintepp.md)
- [PerfAutonomousMode](options-for-perf-state-engine-perfautonomousmode.md)
- [PerfEnergyPreference](options-for-perf-state-engine-perfenergypreference.md)
- [ModuleUnparkPolicy](options-for-perf-state-engine-moduleunparkpolicy.md)
- [ComplexUnparkPolicy](options-for-perf-state-engine-complexunparkpolicy.md)
- [SmtUnparkPolicy](options-for-perf-state-engine-smtunparkpolicy.md)

On systems with processors with heterogeneous architecture, the configuration settings for efficiency class 1 cores use a similar naming convention.

The common parameters have the suffix "1" to indicate efficiency class. Hetero-specific parameters have the prefix "Hetero".

- [CPMinCores1](options-for-core-parking-cpmincores.md)
- [CPMaxCores1](options-for-core-parking-cpmaxcores.md)
- [HeteroIncreaseTime](configuration-for-hetero-power-scheduling-heteroincreasetime.md)
- [HeteroDecreaseTime](configuration-for-hetero-power-scheduling-heterodecreasetime.md)
- [HeteroIncreaseThreshold](configuration-for-hetero-power-scheduling-heteroincreasethreshold.md)
- [HeteroDecreaseThreshold](configuration-for-hetero-power-scheduling-heterodecreasethreshold.md)
- [CpLatencyHintUnpark1](options-for-core-parking-cplatencyhintunpark.md)
- [MaxPerformance1](options-for-perf-state-engine-maxperformance.md)
- [MinPerformance1](options-for-perf-state-engine-minperformance.md)
- [PerfIncreasePolicy1](options-for-perf-state-engine-perfincreasepolicy.md)
- [PerfIncreaseThreshold1](options-for-perf-state-engine-perfincreasethreshold.md)
- [PerfIncreaseTime1](options-for-perf-state-engine-perfincreasetime.md)
- [PerfDecreasePolicy1](options-for-perf-state-engine-perfdecreasepolicy.md)
- [PerfDecreaseThreshold1](options-for-perf-state-engine-perfdecreasethreshold.md)
- [PerfDecreaseTime1](options-for-perf-state-engine-perfdecreasetime.md)
- [PerfLatencyHint1](options-for-perf-state-engine-perflatencyhint.md)
- [LatencyHintEpp1](options-for-perf-state-engine-latencyhintepp.md)
- [HeteroClass1InitialPerf](configuration-for-hetero-power-scheduling-heteroclass1initialperf.md)
- [HeteroClass0FloorPerf](configuration-for-hetero-power-scheduling-heteroclass0floorperf.md)
- [HeteroIncreaseThreshold1](configuration-for-hetero-power-scheduling-heteroincreasethreshold1.md)
- [HeteroDecreaseThreshold1](configuration-for-hetero-power-scheduling-heterodecreasethreshold1.md)

**Game Mode Profile**

The game mode power profile is available as an OEM opt-in feature for laptops starting with the Windows 10 May 2019 Update (19H1) and you'll have to deploy it via provisioning packages during image creation. See below for an example of a customization xml file that defines processor power management settings for the Game Mode Power Profile and refer to the 'Game Mode Test Instructions' document for further guidance on customization options and deployment. This example sets the minimum processor performance state to 100% thereby biasing the CPU towards performance. For more tuning guidance, please reach out to your silicon vendor.

```xml
<?xml version="1.0" encoding="utf-8"?>
<WindowsCustomizatons>  
  <PackageConfig xmlns="urn:schemas-Microsoft-com:Windows-ICD-Package-Config.v1.0">  
    <ID>b8aca924-e386-436e-a50e-bdec4d1715a1</ID>  <!-- ID needs to be be unique GUID for the package -->  
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
                <Processor> 
                  <SchemePersonality> 
                    <Profile SchemeAlias="Balanced"> 
                      <Setting ProfileAlias="GameMode"> 
                        <MinPerformance> 
                          <AcValue>100</AcValue> 
                          <DcValue>100</DcValue> 
                        </MinPerformance> 
                      </Setting> 
                    </Profile> 
                  </SchemePersonality> 
                </Processor> 
              </Settings> 
            </Policy> 
          </Power>  
      </Common>  
    </Customizations>  
  </Settings>  
</WindowsCustomizatons> 
```

**Power Profiles and their Provisioning ProfileAlias**

Using the customization XML as an example, you can create a provisioning package for all power profiles by matching the `<Setting ProfileAlias="?">` xml tag to their provisioning aliases. See below for list of power profiles and their corresponding aliases.

Note

PPM profiles are tuned by Silicon vendors to optimize power and performance of processors. Please reach out to your silicon vendor for tuning guidance before modifying processor power management settings.

| Profile Name | Profile Alias |
| --- | --- |
| Default | "Default" |
| Low Latency | "LowLatency" |
| Low Power | "LowPower" |
| Constrained | "Constrained" |
| Screen Off | "ScreenOff" |
| Standby | "Standby" |
| Game Mode | "GameMode" |
| Mixed Reality | "SustainedPerf" |

## Quality of Service

Power profiles provide system wide configuration of processor power management, impacting all running workloads equally. In contrast, the Quality of Service (QoS) feature provides differentiated performance and power for workloads with different QoS levels. For example, this enables tuning foreground HighQoS activity to prioritize performance, while tuning other QoS levels to prioritize power efficiency. For more information, see [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service).

Each QoS level supports the following configuration settings:

- [MaxFrequency](options-for-perf-state-engine-maxfrequency.md)
- [MaxPerformance](options-for-perf-state-engine-maxperformance.md)
- [MinPerformance](options-for-perf-state-engine-minperformance.md)
- [PerfAutonomousMode](options-for-perf-state-engine-perfautonomousmode.md)
- [PerfAutonomousWindow](options-for-perf-state-engine-perfautonomouswindow.md)
- [PerfBoostMode](options-for-perf-state-engine-perfboostmode.md)
- [PerfEnergyPreference](options-for-perf-state-engine-perfenergypreference.md)
- [PerfLatencyHint](options-for-perf-state-engine-perflatencyhint.md)
- [LatencyHintEpp](options-for-perf-state-engine-latencyhintepp.md)
- [SchedulingPolicy](configuration-for-hetero-power-scheduling-schedulingpolicy.md)
- [ShortSchedulingPolicy](configuration-for-hetero-power-scheduling-shortschedulingpolicy.md)
- [LongThreadArchClassLowerThreshold](configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold.md)
- [LongThreadArchClassUpperThreshold](configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold.md)
- [ShortThreadArchClassLowerThreshold](configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold.md)
- [ShortThreadArchClassUpperThreshold](configuration-for-hetero-power-scheduling-shortthreadarchclassupperthreshold.md)

On systems with processors with heterogeneous architecture, the configuration settings for efficiency class 1 cores use a similar naming convention.

The common parameters have the suffix "1" to indicate efficiency class.

- [MaxFrequency1](options-for-perf-state-engine-maxfrequency.md)
- [MaxPerformance1](options-for-perf-state-engine-maxperformance.md)
- [MinPerformance1](options-for-perf-state-engine-minperformance.md)
- [PerfEnergyPreference1](options-for-perf-state-engine-perfenergypreference.md)
- [PerfLatencyHint1](options-for-perf-state-engine-perflatencyhint.md)
- [LatencyHintEpp1](options-for-perf-state-engine-latencyhintepp.md)

**Quality of Service Levels and their Provisioning ProfileAlias**

Using the customization XML as an example, you can create a provisioning package for all QoS levels by matching the `<Setting ProfileAlias="?">` xml tag to their provisioning aliases. See below for list of QoS levels and their corresponding aliases.

Note

QoS levels are tuned by Silicon vendors to optimize power and performance of processors. Please reach out to your silicon vendor for tuning guidance before modifying processor power management settings. For details about various QoS levels refer [Quality of Service](https://learn.microsoft.com/en-us/windows/win32/procthread/quality-of-service)

| Quality of Service Level | Profile Alias |
| --- | --- |
| High | "Default" |
| Medium | "EntryLevelPerf" |
| Low | "Background" |
| Utility | "Utility" |
| Eco | "Eco" |
| Media | "Multimedia" |
| Deadline | Uses only [PerfLatencyHint](options-for-perf-state-engine-perflatencyhint.md) and [LatencyHintEpp](options-for-perf-state-engine-latencyhintepp.md) from "Multimedia" profile |

## Power Setting Reference

## Allow Throttle States

- **GUID:** 3b04d4fd-1cc7-4f23-ab1c-d1337819c4bb
- **PowerCfg alias:**`THROTTLING`
- **Description:** Allow processors to use throttle states in addition to performance states.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Off | 0 | Off |
| 001 | On | 1 | On |
| 002 | Automatic | 2 | Automatically use throttle states when they are power efficient. |

## Processor performance core parking parked performance state

- **GUID:** 447235c7-6a8d-4cc0-8e24-9eaf70b96e2b
- **PowerCfg alias:**`CPPERF`
- **Description:** Specify what performance state a processor enters when parked.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | No Preference | 0 | No Preference |
| 001 | Deepest Performance State | 1 | Deepest Performance State |
| 002 | Lightest Performance State | 2 | Lightest Performance State |

## Processor performance core parking parked performance state for Processor Power Efficiency Class 1

- **GUID:** 447235c7-6a8d-4cc0-8e24-9eaf70b96e2c
- **PowerCfg alias:**`CPPERF1`
- **Description:** Specify what performance state a Processor Power Efficiency Class 1 processor enters when parked.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | No Preference | 0 | No Preference |
| 001 | Deepest Performance State | 1 | Deepest Performance State |
| 002 | Lightest Performance State | 2 | Lightest Performance State |

## Processor performance time check interval

- **GUID:** 4d2b0152-7d5c-498b-88e2-34345392a2c5
- **PowerCfg alias:**`PERFCHECK`
- **Description:** Specify the amount that must expire before processor performance states and parked cores may be reevaluated (in milliseconds).

| Property | Value |
| --- | --- |
| Minimum value | 1 |
| Maximum value | 5,000 |
| Increment | 1 |
| Units | Milliseconds |

## Processor idle disable

- **GUID:** 5d76a2ca-e8c0-402f-a133-2158492d58ad
- **PowerCfg alias:**`IDLEDISABLE`
- **Description:** Specify if idle states should be disabled.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Enable idle | 0 | Enable idle states. |
| 001 | Disable idle | 1 | Disable idle states. |

## Processor idle threshold scaling

- **GUID:** 6c2993b0-8f48-481f-bcc6-00dd2742aa06
- **PowerCfg alias:**`IDLESCALING`
- **Description:** Specify if idle state promotion and demotion values should be scaled based on the current performance state.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disable scaling | 0 | Disable scaling of idle state promotion and demotion values based on the current performance state. |
| 001 | Enable scaling | 1 | Enable scaling of idle state promotion and demotion values based on the current performance state. |

## Processor performance core parking decrease policy

- **GUID:** 71021b41-c749-4d21-be74-a00f335d582b
- **PowerCfg alias:**`CPDECREASEPOL`
- **Description:** Specify the number of cores/packages to park when fewer cores are required.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Ideal number of cores | 0 | Ideal number of cores |
| 001 | Single core | 1 | Single core |
| 002 | All possible cores | 2 | All possible cores |
| 003 | One eighth cores | 3 | One eighth cores |

## Processor performance history count

- **GUID:** 7d24baa7-0b84-480f-840c-1b0743c00f5f
- **PowerCfg alias:**`PERFHISTORY`
- **Description:** Specify the number of processor performance time check intervals to use when calculating the average utility.

| Property | Value |
| --- | --- |
| Minimum value | 1 |
| Maximum value | 128 |
| Increment | 1 |
| Units | Time check intervals |

## Processor performance history count for Processor Power Efficiency Class 1

- **GUID:** 7d24baa7-0b84-480f-840c-1b0743c00f60
- **PowerCfg alias:**`PERFHISTORY1`
- **Description:** Specify the number of processor performance time check intervals to use when calculating the average utility for Processor Power Efficiency Class 1.

| Property | Value |
| --- | --- |
| Minimum value | 1 |
| Maximum value | 128 |
| Increment | 1 |
| Units | Time check intervals |

## Heterogeneous policy in effect

- **GUID:** 7f2f5cfa-f10c-4823-b5e1-e93ae85f46b5
- **PowerCfg alias:**`HETEROPOLICY`
- **Description:** Specify what policy to be used on systems with at least two different Processor Power Efficiency Classes.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Use heterogeneous policy 0 | 0 | Heterogeneous policy 0. |
| 001 | Use heterogeneous policy 1 | 1 | Heterogeneous policy 1. |
| 002 | Use heterogeneous policy 2 | 2 | Heterogeneous policy 2. |
| 003 | Use heterogeneous policy 3 | 3 | Heterogeneous policy 3. |
| 004 | Use heterogeneous policy 4 | 4 | Heterogeneous policy 4. |

## Processor performance core parking overutilization threshold

- **GUID:** 943c8cb6-6f93-4227-ad87-e9a3feec08d1
- **PowerCfg alias:**`CPOVERUTIL`
- **Description:** Specify the busy threshold that must be met before a parked core is considered overutilized (in percentage).

| Property | Value |
| --- | --- |
| Minimum value | 5 |
| Maximum value | 100 |
| Increment | 1 |
| Units | percent |

## System cooling policy

- **GUID:** 94d3a615-a899-4ac5-ae2b-e4d8f634367f
- **PowerCfg alias:**`SYSCOOLPOL`
- **Description:** Specify the cooling mode for your system

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Passive | 1 | Slow the processor before increasing fan speed |
| 001 | Active | 0 | Increase fan speed before slowing the processor |

## Processor idle state maximum

- **GUID:** 9943e905-9a30-4ec1-9b99-44dd3b76f7a2
- **PowerCfg alias:**`IDLESTATEMAX`
- **Description:** Specify the deepest idle state that should be used.

| Property | Value |
| --- | --- |
| Minimum value | 0 |
| Maximum value | 20 |
| Increment | 1 |
| Units | State Type |

## Processor idle time check

- **GUID:** c4581c31-89ab-4597-8e2b-9c9cab440e6b
- **PowerCfg alias:**`IDLECHECK`
- **Description:** Specify the time that elapsed since the last idle state promotion or demotion before idle states may be promoted or demoted again (in microseconds).

| Property | Value |
| --- | --- |
| Minimum value | 1 |
| Maximum value | 200,000 |
| Increment | 1 |
| Units | Microseconds |

## Processor performance core parking increase policy

- **GUID:** c7be0679-2817-4d69-9d02-519a537ed0c6
- **PowerCfg alias:**`CPINCREASEPOL`
- **Description:** Specify the number of cores/packages to unpark when more cores are required.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Ideal number of cores | 0 | Ideal number of cores |
| 001 | Single core | 1 | Single core |
| 002 | All possible cores | 2 | All possible cores |
| 003 | One eighth cores | 3 | One eighth cores |

## Processor performance core parking utility distribution

- **GUID:** e0007330-f589-42ed-a401-5ddb10e785d3
- **PowerCfg alias:**`DISTRIBUTEUTIL`
- **Description:** Specify whether the core parking engine should distribute utility across processors.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 000 | Disabled | 0 | Disabled |
| 001 | Enabled | 1 | Enabled |

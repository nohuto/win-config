---
title: HeteroIncreaseThreshold | Microsoft Learn
canonicalUrl: https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold
description: HeteroIncreaseThreshold specifies the threshold value to cross above, which is required to unpark the Nth efficiency class 1 core. There is a separate value for each core index. The threshold is relative to efficiency class 0 performance.
note: This was modified by Nohuto using PowrProf API
---

# HeteroIncreaseThreshold | Microsoft Learn

`HeteroIncreaseThreshold` specifies the threshold value to cross above, which is required to unpark the Nth efficiency class 1 core. There is a separate value for each core index. The threshold is relative to efficiency class 0 performance. The provisioning interface can specify up to 4 different thresholds. If the system has 5 or more class 1 cores, the 4th value is used for all remaining cores of the same class.

## Aliases and setting visibility

- **Windows provisioning:**`Common\Power\Policy\Definitions\Processor\HeteroIncreaseThreshold`
- **Windows provisioning:**`Common\Power\Policy\Settings\Processor\HeteroIncreaseThreshold`
- **PowerCfg:**`HETEROINCREASETHRESHOLD`
- **GUID:** b000397d-9b0b-483d-98c9-692a6060cfbf
- **Description:** Specifies the performance level increase threshold at which the Processor Power Efficiency Class 1 processor count is increased (in units of Processor Power Efficiency Class 0 processor performance).
- **Hidden setting:** Yes

## Values

- **Windows provisioning method**

`HeteroIncreaseThreshold` needs to setup in two steps. First a definition needs to be setup for the threshold values. This is a four-byte unsigned integer where each byte represents a threshold in percentage. The lowest byte is the first threshold. For example, to set four thresholds A, B, C, and D, the value of the parameter will be **A + B\*256 + C\*65536 + D\*16777216**. This formula is applicable for provisioning package index values.


Step 1: These index values should be put in: **Windows provisioning:**`Common\Power\Policy\Definitions\Processor\HeteroIncreaseThreshold`

*Example:*

- First class 1 core A threshold = 10%
- Second class 1 core B threshold = 10%
- Third class 1 core C threshold = 60%
- Fourth class 1 core D threshold = 70%

Then **Index Id = 0** is 10 + 10\*256 + 60\*65536 + 70\*16777216 = 1178339850

Another index can be set for different threshold values A = 5%, B = 5%, C = 30%, and D = 35%

**Index Id = 1** is 5 + 5\*256 + 30\*65536 + 35\*16777216 = 589169925

In the above example the definition of 2 index can be set as follow is how various entry id can be set

```
        <Settings>
         <Power>
           <Policy>
             <Definitions>
               <Processor>
                 <HeteroIncreaseThreshold>
                   <List>
                     <Entry Id="0">
                       <!-- Set to 10 10 60 70 -->
                       <Value>1178339850</Value>
                     </Entry>
                     <Entry Id="1">
                       <!-- Set to 5 5 30 35 -->
                       <Value>589169925</Value>
                     </Entry>
                   </List>
                 </HeteroIncreaseThreshold>
               </Processor>
             </Definitions>
```


Step 2: These Index id need to be referenced in the other provisioning located at **Windows provisioning:**`Common\Power\Policy\Settings\Processor\HeteroIncreaseThreshold`

```
                       <HeteroIncreaseThreshold>
                         <AcValue>1</AcValue>
                         <DcValue>0</DcValue>
                       </HeteroIncreaseThreshold>
```

This means that for **AC index id = 1** is selected. That entry id corresponds to 5,5,30,35% threshold for first 4 class 1 cores wheras for **DC index id = 0** is selected and in above example that corresponds to 10,10,60,70% threshold value for first 4 class 1 cores.

- **Powercfg method** Once Index has been populated via windows provisioning method then runtime these index can be changed with powercfg command line tool.

*Example:*

- First class 1 core A threshold = 20%
- Second class 1 core B threshold = 20%
- Third class 1 core C threshold = 70%
- Fourth class 1 core D threshold = 80%

To set four thresholds A, B, C, and D, the value of the parameter will be **D + C\*256 + B\*65536 + A\*16777216**. Note this formula is differnt than provisioning value. In this example the value that runtime can be override with powercfg for Index 0 = 80 + 70\*256 + 20\*65536 + 20\*16777216 = 336,873,040. In hex this value is 0x14144650

These are the commands to override the index 0 with new thresholds via powercfg method

```
powercfg /SetPossibleValue SUB_PROCESSOR HETEROINCREASETHRESHOLD 0 BINARY 0x14144650

powercfg /setactive scheme_current

```

This way Index 0 have new threshold of 20,20,70,80% from first to last core respectively and `HeteroIncreaseThreshold` work on these new thresholds.

| Index | Friendly Name | Raw Value | Description |
| --- | --- | --- | --- |
| 254 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change | 1010580540 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change relative to Processor Power Efficiency Class 0 performance level. |
| 255 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change | 1515870810 | Processor performance level threshold change for Processor Power Efficiency Class 1 processor count change relative to Processor Power Efficiency Class 0 performance level. |

## Applies to

| Windows edition | x86-based devices | x64-based devices | Arm-based devices |
| --- | --- | --- | --- |
| Windows 10 for desktop editions (Home, Pro, Enterprise, and Education) | Supported | Supported | Supported |
| Windows 10 Mobile | N/A | N/A | Supported |
| Windows 11 for desktop editions (Home, Pro, Enterprise, and Education) | N/A | Supported | Supported |

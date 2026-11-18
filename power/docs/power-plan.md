# Power Plan

### Noverse Performance

It's a clone of `SCHEME_MIN` including ~60 changes related to disabling parking/selective suspend/(deep) sleep/battery features/ display dimming/hard disk power savings/slide show/PAPB features, several changes to the processor power management (keeps processor idle enabled, which shouldn't be changed). This can be used by desktop users.

### Noverse Balanced

This power plan should be used by laptop users, it's a clone of `SCHEME_BALANCED` including several specific changes, e.g. pausing slide shows, changing time check intervals while keeping power savings (to prevent overheating) and subgroup settings of `Battery`, `Presence Aware Power Behaviour`, `Display`, `Sleep` etc. unchanged.

## Power Settings Documentation

Most markdown files below are backed up from [windows-hardware/customize/power-settings](https://learn.microsoft.com/en-us/windows-hardware/customize/power-settings/configure-power-settings), many missing or incomplete parts were also added manually by me (mentioned on the top if so), with the additional setting/value data gathered via the PowrProf API (`PowerReadPossibleDescription`, `PowerReadFriendlyName`, `PowerReadPossibleFriendlyName`, `PowerReadValueMin`, `PowerReadValueMax`, `PowerReadValueIncrement`, `PowerReadValueUnits`).

Structure is heading level 3 = subgroup name, linked text = setting name, the brackets include `PowerCfg` naming & setting GUID.

### [Settings belonging to no subgroup](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings.md)

- [Require a password on wakeup](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings-prompt-for-password-on-resume.md) (`CONSOLELOCK`, `0e796bdb-100d-47d6-a2d5-f7d2daa51f51`)
- [Power plan type](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings.md#power-plan-type) (`PERSONALITY`, `245d8541-3943-4422-b025-13a784f679b7`)
- [Device idle policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings-device-idle-policy.md) (`DEVICEIDLE`, `4faab71a-92e5-4726-b531-224559672d19`)
- [Disconnected Standby Mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings.md#disconnected-standby-mode) (`DISCONNECTEDSTANDBYMODE`, `68afb2d9-ee95-47a8-8f50-4115088073b1`)
- [Networking connectivity in Standby](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/no-subgroup-settings-allow-networking-during-standby.md) (`CONNECTIVITYINSTANDBY`, `f15576e8-98b7-4186-b944-eafa664402d9`)

### [Hard disk](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md)

- [AHCI Link Power Management - HIPM/DIPM](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings-link-power-management-mode---hipm-dipm.md) (`0b2d69d7-a2a1-449c-9680-f91c70521c60`)
- [Maximum Power Level](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#maximum-power-level) (`DISKMAXPOWER`, `51dea550-bb38-4bc4-991b-eacf37be5ec8`)
- [Turn off hard disk after](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings-disk-idle-timeout.md) (`DISKIDLE`, `6738e2c4-e8a5-4a42-b16a-e040e769756e`)
- [Hard disk burst ignore time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings-disk-burst-ignore-time.md) (`DISKBURSTIGNORE`, `80e3c60e-bb94-4ad8-bbe0-0d3195efc663`)
- [Secondary NVMe Idle Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#secondary-nvme-idle-timeout) (`d3d55efd-c1ff-424e-9dc3-441be7833010`)
- [Primary NVMe Idle Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#primary-nvme-idle-timeout) (`NVMEPRIMARYIDLETIMEOUT`, `d639518a-e56d-4345-8af2-b9f32fb26109`)
- [AHCI Link Power Management - Adaptive](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings-link-power-management-mode---adaptive.md) (`dab60367-53fe-4fbc-825e-521d069d2456`)
- [Secondary NVMe Power State Transition Latency Tolerance](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#secondary-nvme-power-state-transition-latency-tolerance) (`dbc9e238-6de9-49e3-92cd-8c2b4946b472`)
- [NVMe NOPPME](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#nvme-noppme) (`DISKNVMENOPPME`, `fc7372b6-ab2d-43ee-8797-15e9841f2cca`)
- [Primary NVMe Power State Transition Latency Tolerance](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/disk-settings.md#primary-nvme-power-state-transition-latency-tolerance) (`fc95af4d-40e7-4b6d-835a-56d131dbc80e`)

### [Desktop background settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Slide show](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#slide-show) (`309dce9b-bef4-4119-9921-a851fb12f0f4`)

### [Wireless Adapter Settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Power Saving Mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#power-saving-mode) (`12bbebe6-58d6-4636-95bb-3217ef867c1a`)

### [Sleep](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings.md)

- [Legacy RTC mitigations](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings.md#legacy-rtc-mitigations) (`LEGACYRTCMITIGATION`, `1a34bdc3-7e6b-442e-a9d0-64b6ef378e84`)
- [Allow Away Mode Policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-allow-away-mode.md) (`AWAYMODE`, `25dfa149-5dd1-4736-b5ab-e8a37b5b8187`)
- [Sleep after](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-sleep-idle-timeout.md) (`STANDBYIDLE`, `29f6c1db-86da-48c5-9fdb-f2b67b1f44da`)
- [System unattended sleep timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-sleep-unattended-idle-timeout.md) (`UNATTENDSLEEP`, `7bc4a2f9-d8fc-4469-b07b-33eb785aaca0`)
- [Allow hybrid sleep](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-hybrid-sleep.md) (`HYBRIDSLEEP`, `94ac6d29-73ce-41a6-809f-6363ba21b47e`)
- [Hibernate after](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-hibernate-idle-timeout.md) (`HIBERNATEIDLE`, `9d7815a6-7ee4-497e-8888-515a05f02364`)
- [Allow system required policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-allow-system-required-requests.md) (`SYSTEMREQUIRED`, `a4b195f5-8225-47d8-8012-9d41369786e2`)
- [Allow Standby States](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-allow-sleep-states.md) (`ALLOWSTANDBY`, `abfc2519-3608-4c2a-94ea-171b0ed546ab`)
- [Allow wake timers](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-automatically-wake-for-tasks.md) (`RTCWAKE`, `bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d`)
- [Allow sleep with remote opens](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/sleep-settings-allow-sleep-with-open-remote-files.md) (`REMOTEFILESLEEP`, `d4c1d4c8-d5cc-43d3-b83e-fc51215cb04d`)

### [USB settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Hub Selective Suspend Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#hub-selective-suspend-timeout) (`0853a681-27c8-4100-a2fd-82013e970683`)
- [USB selective suspend setting](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#usb-selective-suspend-setting) (`48e6b7a6-50f5-4782-a5d4-53bb8f07e226`)
- [Setting IOC on all TDs](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#setting-ioc-on-all-tds) (`498c044a-201b-4631-a522-5c744ed4e678`)
- [USB 3 Link Power Mangement](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#usb-3-link-power-mangement) (`d4e98f31-5ffe-4ce1-be31-1b38b384c009`)

### [Idle Resiliency](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Execution Required power request timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#execution-required-power-request-timeout) (`EXECTIME`, `3166bc41-7e98-4e03-b34e-ec0f5f2b218e`)
- [IO coalescing timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#io-coalescing-timeout) (`COALTIME`, `c36f0eb4-2988-4a70-8eee-0884fc2c2433`)
- [Processor Idle Resiliency Timer Resolution](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#processor-idle-resiliency-timer-resolution) (`PROCIR`, `c42b79aa-aa3a-484b-a98f-2cf32aa90a28`)
- [Deep Sleep Enabled/Disabled](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#deep-sleep-enableddisabled) (`DEEPSLEEP`, `d502f7ee-1dc7-4efd-a55d-f04b6f5c0545`)

### [Interrupt Steering Settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Interrupt Steering Mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#interrupt-steering-mode) (`MODE`, `2bfc24f9-5ea2-4801-8213-3dbae01aa39d`)
- [Target Load](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#target-load) (`PERPROCLOAD`, `73cde64d-d720-4bb2-a860-c755afe77ef2`)
- [Unparked time trigger](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#unparked-time-trigger) (`UNPARKTIME`, `d6ba4903-386f-4c2c-8adb-5c21b3328d25`)

### [Power buttons and lid](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings.md)

- [Lid close action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings-lid-switch-close-action.md) (`LIDACTION`, `5ca83367-6e45-459f-a27b-476b1d01c936`)
- [Power button action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings-power-button-action.md) (`PBUTTONACTION`, `7648efa3-dd9c-4e3e-b566-50f929386280`)
- [Enable forced button/lid shutdown](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings-power-button-forced-shutdown.md) (`SHUTDOWN`, `833a6b62-dfa4-46d1-82f8-e09e34d029d6`)
- [Sleep button action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings-sleep-button-action.md) (`SBUTTONACTION`, `96996bc0-ad50-47ec-923b-6f41874dd9eb`)
- [Lid open action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/lid-open-wake-action.md) (`LIDOPENWAKE`, `99ff10e7-23b1-4c07-a9d1-5c3206d741b4`)
- [Start menu power button](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/power-button-and-lid-settings.md#start-menu-power-button) (`UIBUTTON_ACTION`, `a7066653-8d6c-40a8-910e-a1f54b84c7e5`)

### [PCI Express](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/pci-express-settings.md)

- [Link State Power Management](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/pci-express-settings-link-state-power-management.md) (`ASPM`, `ee12f906-d277-404b-b6da-e5fa1a576df5`)

### [Processor power management](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md)

- [Processor performance increase threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasethreshold.md) (`PERFINCTHRESHOLD`, `06cadf0e-64ed-448a-8927-ce7bf90eb35d`)
- [Processor performance increase threshold for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasethreshold.md) (`PERFINCTHRESHOLD1`, `06cadf0e-64ed-448a-8927-ce7bf90eb35e`)
- [Processor performance core parking min cores](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpmincores.md) (`CPMINCORES`, `0cc5b647-c1df-4637-891a-dec35c318583`)
- [Processor performance core parking min cores for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpmincores.md) (`CPMINCORES1`, `0cc5b647-c1df-4637-891a-dec35c318584`)
- [Processor performance decrease threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasethreshold.md) (`PERFDECTHRESHOLD`, `12a0ab44-fe28-4fa9-b3bd-4b64f44960a6`)
- [Processor performance decrease threshold for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasethreshold.md) (`PERFDECTHRESHOLD1`, `12a0ab44-fe28-4fa9-b3bd-4b64f44960a7`)
- [Initial performance for Processor Power Efficiency Class 1 when unparked](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heteroclass1initialperf.md) (`HETEROCLASS1INITIALPERF`, `1facfc65-a930-4bc5-9f38-504ec097bbc0`)
- [Processor performance core parking concurrency threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpconcurrency.md) (`CPCONCURRENCY`, `2430ab6f-a520-44a2-9601-f7f23b5134b1`)
- [Processor performance core parking increase time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpincreasetime.md) (`CPINCREASETIME`, `2ddd5a84-5a71-437e-912a-db0b8c788732`)
- [Processor energy performance preference policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfenergypreference.md) (`PERFEPP`, `36687f9e-e3a5-4dbf-b1dc-15eb381c6863`)
- [Processor energy performance preference policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfenergypreference.md) (`PERFEPP1`, `36687f9e-e3a5-4dbf-b1dc-15eb381c6864`)
- [Allow Throttle States](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#allow-throttle-states) (`THROTTLING`, `3b04d4fd-1cc7-4f23-ab1c-d1337819c4bb`)
- [Processor performance increase time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heteroincreasetime.md) (`HETEROINCREASETIME`, `4009efa7-e72d-4cba-9edf-91084ea8cbc3`)
- [Processor performance decrease policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasepolicy.md) (`PERFDECPOL`, `40fbefc7-2e9d-4d25-a185-0cfd8574bac6`)
- [Processor performance decrease policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasepolicy.md) (`PERFDECPOL1`, `40fbefc7-2e9d-4d25-a185-0cfd8574bac7`)
- [Long running threads' processor architecture lower limit](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclasslowerthreshold.md) (`LONGTHREADARCHCLASSLOWERTHRESHOLD`, `43f278bc-0f8a-46d0-8b31-9a23e615d713`)
- [Processor performance core parking parked performance state](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-parked-performance-state) (`CPPERF`, `447235c7-6a8d-4cc0-8e24-9eaf70b96e2b`)
- [Processor performance core parking parked performance state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-parked-performance-state-for-processor-power-efficiency-class-1) (`CPPERF1`, `447235c7-6a8d-4cc0-8e24-9eaf70b96e2c`)
- [Processor performance boost policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/legacy-config-options-perfboostpol.md) (`PERFBOOSTPOL`, `45bcc044-d885-43e2-8605-ee0ec6e96b59`)
- [Processor performance increase policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasepolicy.md) (`PERFINCPOL`, `465e1f50-b610-473a-ab58-00d1077dc418`)
- [Processor performance increase policy for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasepolicy.md) (`PERFINCPOL1`, `465e1f50-b610-473a-ab58-00d1077dc419`)
- [Latency sensitivity hint processor energy performance preference](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-latencyhintepp.md) (`LATENCYHINTEPP`, `4b70f900-cdd9-4e66-aa26-ae8417f98173`)
- [Latency sensitivity hint processor energy performance preference for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-latencyhintepp.md) (`LATENCYHINTEPP1`, `4b70f900-cdd9-4e66-aa26-ae8417f98174`)
- [Processor idle demote threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-idledemotethreshold.md) (`IDLEDEMOTE`, `4b92d758-5a24-4851-a470-815d78aee119`)
- [Processor performance core parking distribution threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpdistribution.md) (`CPDISTRIBUTION`, `4bdaf4e9-d103-46d7-a5f0-6280121616ef`)
- [Processor performance time check interval](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-time-check-interval) (`PERFCHECK`, `4d2b0152-7d5c-498b-88e2-34345392a2c5`)
- [Processor duty cycling](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-dutycycling.md) (`PERFDUTYCYCLING`, `4e4450b3-6179-4e91-b8f1-5bb9938f81a1`)
- [Short running threads' processor architecture lower limit](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclasslowerthreshold.md) (`SHORTTHREADARCHCLASSLOWERTHRESHOLD`, `53824d46-87bd-4739-aa1b-aa793fac36d6`)
- [Processor idle disable](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-idle-disable) (`IDLEDISABLE`, `5d76a2ca-e8c0-402f-a133-2158492d58ad`)
- [Latency sensitivity hint min unparked cores/packages](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cplatencyhintunpark.md) (`LATENCYHINTUNPARK`, `616cdaa5-695e-4545-97ad-97dc2d1bdd88`)
- [Latency sensitivity hint min unparked cores/packages for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cplatencyhintunpark.md) (`LATENCYHINTUNPARK1`, `616cdaa5-695e-4545-97ad-97dc2d1bdd89`)
- [Latency sensitivity hint processor performance](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perflatencyhint.md) (`LATENCYHINTPERF`, `619b7505-003b-4e82-b7a6-4dd29c300971`)
- [Latency sensitivity hint processor performance for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perflatencyhint.md) (`LATENCYHINTPERF1`, `619b7505-003b-4e82-b7a6-4dd29c300972`)
- [Processor idle threshold scaling](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-idle-threshold-scaling) (`IDLESCALING`, `6c2993b0-8f48-481f-bcc6-00dd2742aa06`)
- [Processor performance core parking decrease policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-decrease-policy) (`CPDECREASEPOL`, `71021b41-c749-4d21-be74-a00f335d582b`)
- [Maximum processor frequency](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxfrequency.md) (`PROCFREQMAX`, `75b0ae3f-bce0-45a7-8c89-c9611c25e100`)
- [Maximum processor frequency for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxfrequency.md) (`PROCFREQMAX1`, `75b0ae3f-bce0-45a7-8c89-c9611c25e101`)
- [Processor idle promote threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-idlepromotethreshold.md) (`IDLEPROMOTE`, `7b224883-b3cc-4d79-819f-8374152cbe7c`)
- [Processor performance history count](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-history-count) (`PERFHISTORY`, `7d24baa7-0b84-480f-840c-1b0743c00f5f`)
- [Processor performance history count for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-history-count-for-processor-power-efficiency-class-1) (`PERFHISTORY1`, `7d24baa7-0b84-480f-840c-1b0743c00f60`)
- [Processor performance decrease time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heterodecreasetime.md) (`HETERODECREASETIME`, `7f2492b6-60b1-45e5-ae55-773f8cd5caec`)
- [Heterogeneous policy in effect](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#heterogeneous-policy-in-effect) (`HETEROPOLICY`, `7f2f5cfa-f10c-4823-b5e1-e93ae85f46b5`)
- [Short running threads' processor architecture upper limit](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortthreadarchclassupperthreshold.md) (`SHORTTHREADARCHCLASSUPPERTHRESHOLD`, `828423eb-8662-4344-90f7-52bf15870f5a`)
- [Minimum processor state](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-minperformance.md) (`PROCTHROTTLEMIN`, `893dee8e-2bef-41e0-89c6-b55d0929964c`)
- [Minimum processor state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-minperformance.md) (`PROCTHROTTLEMIN1`, `893dee8e-2bef-41e0-89c6-b55d0929964d`)
- [Processor performance autonomous mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfautonomousmode.md) (`PERFAUTONOMOUS`, `8baa4a8a-14c6-4451-8e8b-14bdbd197537`)
- [Heterogeneous thread scheduling policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-schedulingpolicy.md) (`SCHEDPOLICY`, `93b8b6dc-0698-4d1c-9ee4-0644e900c85d`)
- [Processor performance core parking overutilization threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-overutilization-threshold) (`CPOVERUTIL`, `943c8cb6-6f93-4227-ad87-e9a3feec08d1`)
- [System cooling policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#system-cooling-policy) (`SYSCOOLPOL`, `94d3a615-a899-4ac5-ae2b-e4d8f634367f`)
- [Processor performance core parking soft park latency](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-softparklatency.md) (`SOFTPARKLATENCY`, `97cfac41-2217-47eb-992d-618b1977c907`)
- [Processor performance increase time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasetime.md) (`PERFINCTIME`, `984cf492-3bed-4488-a8f9-4286c97bf5aa`)
- [Processor performance increase time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfincreasetime.md) (`PERFINCTIME1`, `984cf492-3bed-4488-a8f9-4286c97bf5ab`)
- [Processor idle state maximum](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-idle-state-maximum) (`IDLESTATEMAX`, `9943e905-9a30-4ec1-9b99-44dd3b76f7a2`)
- [Processor performance level increase threshold for Processor Power Efficiency Class 1 processor count increase](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold.md) (`HETEROINCREASETHRESHOLD`, `b000397d-9b0b-483d-98c9-692a6060cfbf`)
- [Processor performance level increase threshold for Processor Power Efficiency Class 2 processor count increase](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heteroincreasethreshold1.md) (`HETEROINCREASETHRESHOLD1`, `b000397d-9b0b-483d-98c9-692a6060cfc0`)
- [Module unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-moduleunparkpolicy.md) (`MODULEUNPARKPOLICY`, `b0deaf6b-59c0-4523-8a45-ca7f40244114`)
- [Smt threads unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-smtunparkpolicy.md) (`SMTUNPARKPOLICY`, `b28a6829-c5f7-444e-8f61-10e24e85c532`)
- [Complex unpark policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-complexunparkpolicy.md) (`COMPLEXUNPARKPOLICY`, `b669a5e9-7b1d-4132-baaa-49190abcfeb6`)
- [Heterogeneous short running thread scheduling policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortschedulingpolicy.md) (`SHORTSCHEDPOLICY`, `bae08b81-2d5e-4688-ad6a-13243356654b`)
- [Maximum processor state](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxperformance.md) (`PROCTHROTTLEMAX`, `bc5038f7-23e0-4960-96da-33abaf5935ec`)
- [Maximum processor state for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-maxperformance.md) (`PROCTHROTTLEMAX1`, `bc5038f7-23e0-4960-96da-33abaf5935ed`)
- [Processor performance boost mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfboostmode.md) (`PERFBOOSTMODE`, `be337238-0d82-4146-a960-4f3749d470c7`)
- [Long running threads' processor architecture upper limit](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-longthreadarchclassupperthreshold.md) (`LONGTHREADARCHCLASSUPPERTHRESHOLD`, `bf903d33-9d24-49d3-a468-e65e0325046a`)
- [Processor idle time check](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-idle-time-check) (`IDLECHECK`, `c4581c31-89ab-4597-8e2b-9c9cab440e6b`)
- [Processor performance core parking increase policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-increase-policy) (`CPINCREASEPOL`, `c7be0679-2817-4d69-9d02-519a537ed0c6`)
- [Processor autonomous activity window](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfautonomouswindow.md) (`PERFAUTONOMOUSWINDOW`, `cfeda3d0-7697-4566-a922-a9086cd49dfa`)
- [Processor performance decrease time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasetime.md) (`PERFDECTIME`, `d8edeb9b-95cf-4f95-a73c-b061973693c8`)
- [Processor performance decrease time for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-perf-state-engine-perfdecreasetime.md) (`PERFDECTIME1`, `d8edeb9b-95cf-4f95-a73c-b061973693c9`)
- [Short vs. long running thread threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-shortthreadruntimethreshold.md) (`SHORTTHREADRUNTIMETHRESHOLD`, `d92998c2-6a48-49ca-85d4-8cceec294570`)
- [Processor performance core parking decrease time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpdecreasetime.md) (`CPDECREASETIME`, `dfd10d17-d5eb-45dd-877a-9a34ddd15c82`)
- [Processor performance core parking utility distribution](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#processor-performance-core-parking-utility-distribution) (`DISTRIBUTEUTIL`, `e0007330-f589-42ed-a401-5ddb10e785d3`)
- [Processor performance core parking max cores](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpmaxcores.md) (`CPMAXCORES`, `ea062031-0e34-4ff1-9b6d-eb1059334028`)
- [Processor performance core parking max cores for Processor Power Efficiency Class 1](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpmaxcores.md) (`CPMAXCORES1`, `ea062031-0e34-4ff1-9b6d-eb1059334029`)
- [Processor performance core parking concurrency headroom threshold](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/options-for-core-parking-cpheadroom.md) (`CPHEADROOM`, `f735a673-2066-4f80-a0c5-ddee0cf1bf5d`)
- [Processor performance level decrease threshold for Processor Power Efficiency Class 1 processor count decrease](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold.md) (`HETERODECREASETHRESHOLD`, `f8861c27-95e7-475c-865b-13c0cb3f9d6b`)
- [Processor performance level decrease threshold for Processor Power Efficiency Class 2 processor count decrease](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heterodecreasethreshold1.md) (`HETERODECREASETHRESHOLD1`, `f8861c27-95e7-475c-865b-13c0cb3f9d6c`)
- [A floor performance for Processor Power Efficiency Class 0 when there are Processor Power Efficiency Class 1 processors unparked](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configuration-for-hetero-power-scheduling-heteroclass0floorperf.md) (`HETEROCLASS0FLOORPERF`, `fddc842b-8364-4edc-94cf-c17f60de1c80`)

### [Graphics settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [GPU preference policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#gpu-preference-policy) (`GPUPREFERENCEPOLICY`, `dd848b2a-8a5d-4451-9ae2-39cd41658f6c`)

### [Display](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings.md)

- [Dim display after](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-dim-annoyance-timeout.md) (`VIDEODIM`, `17aaa29b-8b43-4b94-aafe-35f64daaf1ee`)
- [Turn off display after](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-display-idle-timeout.md) (`VIDEOIDLE`, `3c0bc021-c8a8-4e07-a973-6b14cbcb2b7e`)
- [Advanced Color quality bias](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-advanced-color-quality-bias.md) (`ADVANCEDCOLORQUALITYBIAS`, `684c3e69-a4f7-4014-8754-d45179a56167`)
- [Console lock display off timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings.md#console-lock-display-off-timeout) (`VIDEOCONLOCK`, `8ec4b3a5-6868-48c2-be75-4f3044be88a7`)
- [Adaptive display](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-adaptive-display-idle-timeout.md) (`VIDEOADAPT`, `90959d22-d6a1-49b9-af93-bce885ad335b`)
- [Allow display required policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-allow-display-required-policy.md) (`ALLOWDISPLAY`, `a9ceb8da-cd46-44fb-a98b-02af69de4623`)
- [Display brightness](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-display-brightness-level.md) (`VIDEONORMALLEVEL`, `aded5e82-b909-4619-9949-f5d71dac0bcb`)
- [Dimmed display brightness](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings-dim-display-brightness.md) (`f1fbfde2-a960-4165-9f88-50667911ce96`)
- [Enable adaptive brightness](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/display-settings.md#enable-adaptive-brightness) (`ADAPTBRIGHT`, `fbd9aa66-9553-4097-ba44-ed6e9d65eab8`)

### [Presence Aware Power Behavior](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/presence-adaptive.md)

- [Human Presence Sensor Adaptive Away Display Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/presence-adaptive-away-display-timeout.md) (`HUPRVIDEOIDLE`, `0a7d6ab6-ac83-4ad1-8282-eca5b58308f3`)
- [Standby Reserve Time](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#standby-reserve-time) (`STANDBYRESERVETIME`, `468fe7e5-1158-46ec-88bc-5b96c9e44fd0`)
- [Standby Reset Percentage](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#standby-reset-percentage) (`STANDBYRESETPERCENT`, `49cb11a5-56e2-4afb-9d38-3df47872e21b`)
- [Non-sensor Input Presence Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#non-sensor-input-presence-timeout) (`NSENINPUTPRETIME`, `5adbbfbc-074e-4da1-ba38-db8b36b2c8f3`)
- [Standby Budget Grace Period](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#standby-budget-grace-period) (`STANDBYBUDGETGRACEPERIOD`, `60c07fe1-0556-45cf-9903-d56e32210242`)
- [User Presence Prediction mode](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#user-presence-prediction-mode) (`USERPRESENCEPREDICTION`, `82011705-fb95-4d46-8d35-4042b1d20def`)
- [Standby Budget Percent](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#standby-budget-percent) (`STANDBYBUDGETPERCENT`, `9fe527be-1b70-48da-930d-7bcf17b44990`)
- [Human Presence Sensor Adaptive Away Dim Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/presence-adaptive-away-dim-timeout.md) (`HUPRVIDEODIMAWAY`, `a79c8e0e-f271-482d-8f8a-5db9a18312de`)
- [Standby Reserve Grace Period](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#standby-reserve-grace-period) (`STANDBYRESERVEGRACEPERIOD`, `c763ee92-71e8-4127-84eb-f6ed043a3e3d`)
- [Human Presence Sensor Adaptive Inattentive Dim Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/presence-adaptive-inattentive-dim-timeout.md) (`HUPRVIDEODIM`, `cf8c6097-12b8-4279-bbdd-44601ee5209d`)
- [Human Presence Sensor Adaptive Inattentive Display Timeout](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/presence-adaptive-inattentive-display-timeout.md) (`HUPRVIDEOIDLEINATTENTIVE`, `ee16691e-6ab3-4619-bb48-1c77c9357e5a`)

### [Video playback quality](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md)

- [Video playback quality bias](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#video-playback-quality-bias) (`10778347-1370-4ee0-8bbd-33bdacaade49`)
- [When playing video](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-power-settings.md#when-playing-video) (`34c7b99f-9a6d-4b3c-8dc7-b6693b78cef4`)

### [Energy Saver settings](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/energy-saver-settings.md)

- [Display brightness weight](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/energy-saver-settings.md#display-brightness-weight) (`ESBRIGHTNESS`, `13d09884-f74e-474a-a852-b6bde8ad03a8`)
- [Energy Saver Policy](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/energy-saver-settings.md#energy-saver-policy) (`ESPOLICY`, `5c5bb349-ad29-4ee2-9d0b-2b25270f7a81`)
- [Charge level](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/energy-saver-settings.md#charge-level) (`ESBATTTHRESHOLD`, `e69653ca-cf7f-4f05-aa73-cb833fa90ad4`)

### [Battery](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings.md)

- [Critical battery notification](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings.md#critical-battery-notification) (`BATFLAGSCRIT`, `5dbb7c9f-38e9-40d2-9749-4f8a0e9f640f`)
- [Critical battery action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings-critical-battery-action.md) (`BATACTIONCRIT`, `637ea02f-bbcb-4015-8e2c-a1c7b9c0b546`)
- [Low battery level](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings-low-battery-threshold.md) (`BATLEVELLOW`, `8183ba9a-e910-48da-8769-14ae6dc1170a`)
- [Critical battery level](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings-critical-battery-threshold.md) (`BATLEVELCRIT`, `9a66d8d7-4ff7-4ef9-b5a2-5a326ca2a469`)
- [Low battery notification](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings.md#low-battery-notification) (`BATFLAGSLOW`, `bcded951-187b-4d05-bccc-f7e51960c258`)
- [Low battery action](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings-low-battery-action.md) (`BATACTIONLOW`, `d8742dcb-3e6a-4b3c-b3fe-374623cdcf06`)
- [Reserve battery level](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/battery-settings-reserve-battery-level.md) (`f3c5027d-cd16-4930-aa6b-90db844a8f00`)

## Suboptions

I've added some specific settings to toggle some features if wanted, note that this applies to the current active scheme. If you want to change more specific settings rather use a tool such as [PowerSettingsExplorer](https://github.com/nohuto/win-config/blob/main/power/assets/tools/PowerSettingsExplorer.exe).

### Default Schemes

`Delete` = deletes the default schemes (select one of the `Noverse x` schemes before deleting them, otherwise a scheme named `Noverse Temporary Scheme` gets created which is a clone of `SCHEME_BALANCED`):

```c
381b4222-f694-41f0-9685-ff5bb260df2e // SCHEME_BALANCED (Balanced)
8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c // SCHEME_MIN (High Performance)
a1841308-3541-4fab-bc81-f71556f20b4a // SCHEME_MAX (Power saver)
```

`Restore` = restores the default schemes, note that this removes all imported/custom plans

### Context Menu Import

Adds a `Import` option when right clicking on `.pow` files.

![](https://github.com/nohuto/win-config/blob/main/power/images/powcontextmenu.png?raw=true)



bool DisplayNameHelper::HideManufacturerName(bool isNotebookDisplay)
{
    optional<RegistryKey> regKey;
    DWORD hideManufacturerName = isNotebookDisplay ? 1 : 0;
    if(ERROR_SUCCESS == RegistryKey::TryOpen(regKey, HKEY_LOCAL_MACHINE, RegistryKeys::GetServicesControlPanelKey(), KEY_QUERY_VALUE))
    {
        regKey->TryGetValue(_T("HideManufacturerFromMonitorName"), hideManufacturerName);
    }
    return (hideManufacturerName == 1);
}

---

        <regkey name="HideManufacturerFromMonitorName">
            <root>HKLM</root>
            <path>Software\NVIDIA Corporation\Global\NVTweak</path>
            <type>REG_DWORD</type>
            <description>TBD</description>
            <keyNameSrcAlias>const</keyNameSrcAlias>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\Display\Panel\NvCpl.cpp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\AppProfiles\AppProfilesUtil.cpp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\uxd\Features\ShimWrappers.lib\DisplayNameHelper.cp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\AppProfiles\CEdid.cpp</codePath>
            <flags></flags>
            <osRestrictionList></osRestrictionList>
            <category>NV_CPL</category>
            <owner>unknown</owner>
        </regkey>

        <regkey name="HideManufacturerFromMonitorName">
            <root>HKR</root>
            <path>Global\NVTweak</path>
            <type>REG_DWORD</type>
            <description>TBD</description>
            <keyNameSrcAlias>const</keyNameSrcAlias>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\Display\Panel\NvCpl.cpp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\AppProfiles\AppProfilesUtil.cpp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\uxd\Features\ShimWrappers.lib\DisplayNameHelper.cp</codePath>
            <codePath>${NV_ROOT}\${NV_BRANCH}\drivers\ui\AppProfiles\CEdid.cpp</codePath>
            <flags></flags>
            <osRestrictionList></osRestrictionList>
            <category>NV_CPL</category>
            <owner>unknown</owner>
        </regkey>
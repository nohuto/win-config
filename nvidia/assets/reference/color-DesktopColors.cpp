void DesktopColorSettings::SaveParametric(const DesktopColors& colors, ApiXModelSlice& modelSlice)
{
	try
	{
		LoggedOnUserImpersonator impersonator;
		// open the registry key that corresponds to the colors 
		wstring regPath = GetRegistryPath(colors, modelSlice);
		optional<RegistryKey> regKey;

		if (RegistryKey::TryOpenCurrentUser(regKey, regPath, KEY_ALL_ACCESS, true, 0) == ERROR_SUCCESS)
		{

			regKey->SetDWORDValue(RegistryKeys::GetNvcplColorPersistenceRegKey(), 1);

			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_BrightnessRed::SettingId), colors.GetBrightnessRed());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_BrightnessGreen::SettingId), colors.GetBrightnessGreen());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_BrightnessBlue::SettingId), colors.GetBrightnessBlue());

			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_ContrastRed::SettingId), colors.GetContrastRed());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_ContrastGreen::SettingId), colors.GetContrastGreen());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_ContrastBlue::SettingId), colors.GetContrastBlue());

			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_GammaRed::SettingId), colors.GetGammaRed());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_GammaGreen::SettingId), colors.GetGammaGreen());
			regKey->SetDWORDValue(lexical_cast<wstring>(DesktopColors::_GammaBlue::SettingId), colors.GetGammaBlue());
		}
	}
	catch (RegistryException&)
	{
		// nothing to do here - we will simply use the defaults
	}
}

bool SessionEventFeatures::SetLoginColors(StartupModel &model)
{
    if (!DesktopUtil::IsSecureDesktopActive())
    {
        SetWritePolicyForColors(model);
        LOG(Debug, L"Setting desktop colors on login.");
        System system = model.GetSystem();
        OemSettings oemSettings = system.GetOemSettings();

        if(!oemSettings.GetDisableApplyColorsAtStartup())
        {
            vector<Source> sources;
            SystemUtil::GetSources(system, back_inserter(sources));

            int sleepTime = oemSettings.GetAllowStartupDelay();

            if (sleepTime > 0)
            {
                Sleep(sleepTime);;
            }

            BOOST_FOREACH(Source &source, sources)
            {
                BOOST_FOREACH(Target target, source.GetTargets())
                {
                    LoggedOnUserImpersonator impersonator;
                    DesktopColors colors = target.GetDesktopColors();
                    wstring regPath = TargetUtil::GetRegKeyPathForNvColors(target);
                    optional<RegistryKey> regKey;

                    if (RegistryKey::TryOpenCurrentUser(regKey, regPath, KEY_ALL_ACCESS, true) == ERROR_SUCCESS)
                    {        
                        bool bApplyPersistence = false;
                        DWORD regKeyValue = 0;
                        if((regKey->TryGetValue(RegistryKeys::GetNvcplColorPersistenceRegKey(), regKeyValue) == ERROR_SUCCESS) &&
                           (regKeyValue != 0))
                        {
                            bApplyPersistence = true;
                        } 
                        else 
                        if ((regKey->TryGetValue(_T(NV_REG_CPL_USE_COLOR_CORRECTION), regKeyValue) == ERROR_SUCCESS) &&
                            (regKeyValue != 0))
                        {/*In case of over install from pre RID 50787 driver, we will have to rely on NV_REG_CPL_USE_COLOR_CORRECTION
                         * for persistence
                        */
                            bApplyPersistence = true;
                        }

                        if (bApplyPersistence)
                        {
                            ApplyColorsFromRegistry(colors);
                        }
                    }
                }
            }
        }
    }

    return true;
}
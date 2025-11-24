NvAPI_Status NGXCubinGeneric::Init(NGXCubinDevice InDevice)
{
#if defined(NV_WINDOWS)
    // Registry hive : HKLM\SOFTWARE\NVIDIA Corporation\Global\NGXCore
    // Value name : ShowDlssIndicator
    // Value data : 0
    // Value name : NgxCubinDisableResourceCache
    // Value data : 0
    HKEY Key;
    LONG RegRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\NVIDIA Corporation\\Global\\NGXCore", 0, KEY_READ, &Key);
    if (RegRes == ERROR_SUCCESS)
    {
        DWORD regShowIndicator;
        RegRes = GetDwordRegKey(Key, L"ShowDlssIndicator", &regShowIndicator);
        if (RegRes == ERROR_SUCCESS)
        {
            m_ShowIndicator = regShowIndicator;
        }

        DWORD regDisableResourcesCache;
        RegRes = GetDwordRegKey(Key, L"NgxCubinDisableResourceCache", &regDisableResourcesCache);
        if (RegRes == ERROR_SUCCESS)
        {
            m_DisableResourceCache = regDisableResourcesCache;
        }
        RegCloseKey(Key);
    }
    else
    {
        LOG("error: failed to open registry key SOFTWARE\\NVIDIA Corporation\\Global\\NGXCore");
    }
#else // defined(NV_WINDOWS)
    // TODO: Port NGX configuration mechanisms to Linux.  For now, use an
    //       env variable to enable the indicator.
    const char *ngxShowIndicatorStr = getenv("__NGX_SHOW_INDICATOR");
    if (ngxShowIndicatorStr) {
        m_ShowIndicator = atoi(ngxShowIndicatorStr);
    }
    // TODO: Port NGX configuration mechanisms to Linux.  For now, use an
    //       env variable to disable the Cubin Resource Caching.
    const char *ngxDisableResourcesCacheStr = getenv("__NGX_CUBIN_DISABLE_RESOURCE_CACHE");
    if (ngxDisableResourcesCacheStr) {
        m_DisableResourceCache = atoi(ngxDisableResourcesCacheStr);
    }
#endif // defined(NV_WINDOWS)

    // DLSS devs get banned from games if they forget to disable DLSS indicator when playing.
    // So Release snippet won't respond to any value except 1024.
#if defined(_PRODUCTION)
    if (m_ShowIndicator != 1024)
    {
        m_ShowIndicator = 0;
    }
#endif

    return NVAPI_OK;
}
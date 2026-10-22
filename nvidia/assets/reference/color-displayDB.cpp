CODE_SEGMENT(PAGE_CODE)
DD_STATUS
CDisplayDB::setHueData
(
    CNvLMonitor *pMonitor,
    NvS32 cosHue_x10K,
    NvS32 sinHue_x10K
)
{
    FUNCTION_PROLOG();
    CHECK_IRQL(PASSIVE_LEVEL);

    NTSTATUS ntStatus = STATUS_SUCCESS; 
    DD_STATUS ddStatus = DD_STATUS_SUCCESS;

    acquireMutex();

    // sanity check
    if (!m_RegistryPath.Buffer || !pMonitor)
    {
        ddStatus = DD_STATUS_ERROR;
        goto setHueData_Exit;
    }

    // construct the registry path
    ddStatus = constructRegistryPath(ENUM_DISPLAYDB_KEY_TYPE_MONITOR, pMonitor);
    if (ddStatus != DD_STATUS_SUCCESS)
    {
        goto setHueData_Exit;
    }

    // make sure the registry path for this monitor exists
    ntStatus = nvServiceRegistryCreateKeyPath(&m_RegistryPath, NvDriverRegKeyPersistentState);
    if (!NT_SUCCESS(ntStatus))
    {
        ddStatus = DD_STATUS_ERROR;
        goto setHueData_Exit;
    }

    REGISTRY_HUE_DATA hue;
    ::initialize(&hue);
    hue.cosHue_x10K = cosHue_x10K;
    hue.sinHue_x10K = sinHue_x10K;
    hue.checksum    = registryChecksum(&hue, sizeof(REGISTRY_HUE_DATA));

    // try to set the value
    ntStatus = nvServiceSubkeyRegistryWrite(&m_RegistryPath,
                                            &m_HueRegistryKey,
                                            REG_BINARY,
                                            &hue,
                                            sizeof(REGISTRY_HUE_DATA),
                                            NvDriverRegKeyPersistentState);
    if (!NT_SUCCESS(ntStatus))
    {
        ddStatus = DD_STATUS_ERROR;
    }

setHueData_Exit:
    releaseMutex();

    return ddStatus;
}
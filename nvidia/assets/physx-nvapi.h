#define NVAPI_PHSYX_GPU_REG_VALUE          L"physxGpuId"
typedef struct _NV_ESC_NVAPI_SET_PHSYX_STATE
{
    NVAPI_ESC_HEADER escHeader;         //IN/OUT header

    struct
    {
        NvU32   hPhysicalGpu;
        NvU32   bState:1;               //1 enable, 0 disable

        struct
        {
            NvU32   bUpdateRequired:1;
            NvU32   bState:1;
        } idmState;

    } input;

} NV_ESC_NVAPI_SET_PHSYX_STATE;

#if NVCFG(GLOBAL_FEATURE_WDDM2_5_SUPPORT)
NvAPI_Status nvapi_isGpuPhysxEnabled(NvU32 queriedGpuId, bool& physxGpuFound)
{
    NvAPI_Status ret = NVAPI_ERROR;
    physxGpuFound = false;

    NV_ALLOCATE_HEAP_REF(NVAPI_REGISTRY_DETAILS, registryDetails);
    registryDetails.registryType = NVAPI_REG_BINARY;
    registryDetails.locationType = NVAPI_REG_LOCATION_SERVICEKEY;
    wcscpy_s(registryDetails.szKeyName, MAX_PATH, L"\\NVAPI\\PhysxGpuId");
    registryDetails.pvData = 0;
    registryDetails.cbData = 0;
    ret = nvapi_GetRegistryUsingQAI(&registryDetails);
    NV_RETURN_IF_FAIL_MSG(TRACE_LEVEL_ERROR, Gpu, (ret != NVAPI_OK), ret, "Internal function nvapi_GetRegistryUsingQAI failed.");

    NV_ALLOCATE_HEAP_ARRAY(BYTE, tempBuffer, registryDetails.cbData);
    registryDetails.pvData = tempBuffer;
    ret = nvapi_GetRegistryUsingQAI(&registryDetails);
    NV_RETURN_IF_FAIL_MSG(TRACE_LEVEL_ERROR, Gpu, (ret != NVAPI_OK), ret, "Internal function nvapi_GetRegistryUsingQAI failed.");

    NvU32 rmGpuId = (NvU32)(*((DWORD*)registryDetails.pvData));
    if ((queriedGpuId == rmGpuId) || ((queriedGpuId == NVAPI_ANY_GPU_HANDLE) && (rmGpuId != 0)))
    {
        physxGpuFound = true;
    }
    return NVAPI_OK;
}
#endif
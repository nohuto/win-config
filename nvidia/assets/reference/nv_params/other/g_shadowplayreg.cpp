/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_SHADOWPLAY_BLACK_LIST = "SHADOWPLAY_BLACK_LIST";
static const char *g_pszDefinedWhen_SHADOWPLAY_BLACK_LIST = "1";
static const char *g_pszRemappedName_SHADOWPLAY_BLACK_LIST = "SHADOWPLAY_14586201";
static const char *g_pszMainDocs_SHADOWPLAY_BLACK_LIST = "Prohibit ShadowPlay shim in DX apps";

static const char * (g_ppszDefineDataNames_SHADOWPLAY_BLACK_LIST_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SHADOWPLAY_BLACK_LIST_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SHADOWPLAY_BLACK_LIST[] =
{
    { (const char **)g_ppszDefineDataNames_SHADOWPLAY_BLACK_LIST_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_SHADOWPLAY_BLACK_LIST_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_SHADOWPLAY_BLACK_LIST[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_SHADOWPLAY_BLACK_LIST(
    0x90de9159,
    g_pszKeyName_SHADOWPLAY_BLACK_LIST,
    g_pszRemappedName_SHADOWPLAY_BLACK_LIST,
    g_pszMainDocs_SHADOWPLAY_BLACK_LIST,
    g_pszDefinedWhen_SHADOWPLAY_BLACK_LIST,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SHADOWPLAY_BLACK_LIST, 
    2, 
    g_aDefaultData_SHADOWPLAY_BLACK_LIST, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_SHADOWPLAY_BLACK_LIST, 
};

bool AddSettingsToHashByPlainNameSHADOWPLAY(NvSettingsHash &settingsHash)
{
    bool result;
    NvU32 index;
    for(index=0; index < sizeof(g_listofSettings)/sizeof(g_listofSettings[0]); index++) {
        NvDrsStringPtrA str(g_listofSettings[index]->getPlainName());
        result = settingsHash.add(str, g_listofSettings[index]);
        if (!result) {
            settingsHash.destroy();
            return false;
        }
    }
    return true;
}
bool AddSettingsToHashByIdSHADOWPLAY(NvSettingsIdHash &settingsIdHash)
{
    bool result;
    NvU32 index;
    for(index=0; index < sizeof(g_listofSettings)/sizeof(g_listofSettings[0]); index++) {
        NvU32 id = g_listofSettings[index]->getBinaryId();
        result = settingsIdHash.add(id, g_listofSettings[index]);
        if (!result) {
            settingsIdHash.destroy();
            return false;
        }
    }
    return true;
}

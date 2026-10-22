/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_AUDIO_INJECT_RXINPUT_DLL = "AUDIO_INJECT_RXINPUT_DLL";
static const char *g_pszDefinedWhen_AUDIO_INJECT_RXINPUT_DLL = "1";
static const char *g_pszRemappedName_AUDIO_INJECT_RXINPUT_DLL = "_";
static const char *g_pszMainDocs_AUDIO_INJECT_RXINPUT_DLL = "Decide whether to inject rxinput.dll or not";

static const char * (g_ppszDefineDataNames_AUDIO_INJECT_RXINPUT_DLL_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AUDIO_INJECT_RXINPUT_DLL_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_AUDIO_INJECT_RXINPUT_DLL[] =
{
    { (const char **)g_ppszDefineDataNames_AUDIO_INJECT_RXINPUT_DLL_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AUDIO_INJECT_RXINPUT_DLL_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_AUDIO_INJECT_RXINPUT_DLL[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_AUDIO_INJECT_RXINPUT_DLL(
    0x80303a19,
    g_pszKeyName_AUDIO_INJECT_RXINPUT_DLL,
    g_pszRemappedName_AUDIO_INJECT_RXINPUT_DLL,
    g_pszMainDocs_AUDIO_INJECT_RXINPUT_DLL,
    g_pszDefinedWhen_AUDIO_INJECT_RXINPUT_DLL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AUDIO_INJECT_RXINPUT_DLL, 
    2, 
    g_aDefaultData_AUDIO_INJECT_RXINPUT_DLL, 
    1 
);

static const char *g_pszKeyName_GFE_ADDRESSED = "GFE_ADDRESSED";
static const char *g_pszDefinedWhen_GFE_ADDRESSED = "1";
static const char *g_pszRemappedName_GFE_ADDRESSED = "_";
static const char *g_pszMainDocs_GFE_ADDRESSED = "Fingerprinted and addressed";

static const char * (g_ppszDefineDataNames_GFE_ADDRESSED_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFE_ADDRESSED_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_GFE_ADDRESSED[] =
{
    { (const char **)g_ppszDefineDataNames_GFE_ADDRESSED_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFE_ADDRESSED_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_GFE_ADDRESSED[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFE_ADDRESSED(
    0x80d206b4,
    g_pszKeyName_GFE_ADDRESSED,
    g_pszRemappedName_GFE_ADDRESSED,
    g_pszMainDocs_GFE_ADDRESSED,
    g_pszDefinedWhen_GFE_ADDRESSED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GFE_ADDRESSED, 
    2, 
    g_aDefaultData_GFE_ADDRESSED, 
    1 
);

static const char *g_pszKeyName_GFE_DISPLAY_IN_UI = "GFE_DISPLAY_IN_UI";
static const char *g_pszDefinedWhen_GFE_DISPLAY_IN_UI = "1";
static const char *g_pszRemappedName_GFE_DISPLAY_IN_UI = "_";
static const char *g_pszMainDocs_GFE_DISPLAY_IN_UI = "Display in UI even if no OPS exist";

static const char * (g_ppszDefineDataNames_GFE_DISPLAY_IN_UI_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFE_DISPLAY_IN_UI_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_GFE_DISPLAY_IN_UI[] =
{
    { (const char **)g_ppszDefineDataNames_GFE_DISPLAY_IN_UI_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFE_DISPLAY_IN_UI_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_GFE_DISPLAY_IN_UI[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFE_DISPLAY_IN_UI(
    0x80303e0e,
    g_pszKeyName_GFE_DISPLAY_IN_UI,
    g_pszRemappedName_GFE_DISPLAY_IN_UI,
    g_pszMainDocs_GFE_DISPLAY_IN_UI,
    g_pszDefinedWhen_GFE_DISPLAY_IN_UI,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GFE_DISPLAY_IN_UI, 
    2, 
    g_aDefaultData_GFE_DISPLAY_IN_UI, 
    1 
);

static const char *g_pszKeyName_GFE_GAMESESSION_TELEMETRY_REDESIGN = "GFE_GAMESESSION_TELEMETRY_REDESIGN";
static const char *g_pszDefinedWhen_GFE_GAMESESSION_TELEMETRY_REDESIGN = "1";
static const char *g_pszRemappedName_GFE_GAMESESSION_TELEMETRY_REDESIGN = "_";
static const char *g_pszMainDocs_GFE_GAMESESSION_TELEMETRY_REDESIGN = "Decide whether to use container plugin to send telemetry data";

static const char * (g_ppszDefineDataNames_GFE_GAMESESSION_TELEMETRY_REDESIGN_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFE_GAMESESSION_TELEMETRY_REDESIGN_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_GFE_GAMESESSION_TELEMETRY_REDESIGN[] =
{
    { (const char **)g_ppszDefineDataNames_GFE_GAMESESSION_TELEMETRY_REDESIGN_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFE_GAMESESSION_TELEMETRY_REDESIGN_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_GFE_GAMESESSION_TELEMETRY_REDESIGN[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFE_GAMESESSION_TELEMETRY_REDESIGN(
    0x80303e0f,
    g_pszKeyName_GFE_GAMESESSION_TELEMETRY_REDESIGN,
    g_pszRemappedName_GFE_GAMESESSION_TELEMETRY_REDESIGN,
    g_pszMainDocs_GFE_GAMESESSION_TELEMETRY_REDESIGN,
    g_pszDefinedWhen_GFE_GAMESESSION_TELEMETRY_REDESIGN,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GFE_GAMESESSION_TELEMETRY_REDESIGN, 
    2, 
    g_aDefaultData_GFE_GAMESESSION_TELEMETRY_REDESIGN, 
    1 
);

static const char *g_pszKeyName_GFE_MONITOR_USAGE = "GFE_MONITOR_USAGE";
static const char *g_pszDefinedWhen_GFE_MONITOR_USAGE = "1";
static const char *g_pszRemappedName_GFE_MONITOR_USAGE = "_";
static const char *g_pszMainDocs_GFE_MONITOR_USAGE = "Collect usage statistics";

static const char * (g_ppszDefineDataNames_GFE_MONITOR_USAGE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFE_MONITOR_USAGE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_GFE_MONITOR_USAGE[] =
{
    { (const char **)g_ppszDefineDataNames_GFE_MONITOR_USAGE_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFE_MONITOR_USAGE_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_GFE_MONITOR_USAGE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFE_MONITOR_USAGE(
    0x80857a28,
    g_pszKeyName_GFE_MONITOR_USAGE,
    g_pszRemappedName_GFE_MONITOR_USAGE,
    g_pszMainDocs_GFE_MONITOR_USAGE,
    g_pszDefinedWhen_GFE_MONITOR_USAGE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GFE_MONITOR_USAGE, 
    2, 
    g_aDefaultData_GFE_MONITOR_USAGE, 
    1 
);

static const char *g_pszKeyName_GFE_SUPPORTED = "GFE_SUPPORTED";
static const char *g_pszDefinedWhen_GFE_SUPPORTED = "1";
static const char *g_pszRemappedName_GFE_SUPPORTED = "_";
static const char *g_pszMainDocs_GFE_SUPPORTED = "Support for fingerprint and OPS";

static const char * (g_ppszDefineDataNames_GFE_SUPPORTED_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFE_SUPPORTED_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_GFE_SUPPORTED[] =
{
    { (const char **)g_ppszDefineDataNames_GFE_SUPPORTED_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFE_SUPPORTED_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_GFE_SUPPORTED[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFE_SUPPORTED(
    0x801dc1b0,
    g_pszKeyName_GFE_SUPPORTED,
    g_pszRemappedName_GFE_SUPPORTED,
    g_pszMainDocs_GFE_SUPPORTED,
    g_pszDefinedWhen_GFE_SUPPORTED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GFE_SUPPORTED, 
    2, 
    g_aDefaultData_GFE_SUPPORTED, 
    1 
);

static const char *g_pszKeyName_SHADOWPLAY_FLAGS = "SHADOWPLAY_FLAGS";
static const char *g_pszDefinedWhen_SHADOWPLAY_FLAGS = "1";
static const char *g_pszRemappedName_SHADOWPLAY_FLAGS = "_";
static const char *g_pszMainDocs_SHADOWPLAY_FLAGS = "ShadowPlay Flags. Bit0: if set, app is whitelisted for Desktop capture . Other bits are ununsed for now";

DataDefaultDWORD g_aDefaultData_SHADOWPLAY_FLAGS[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_SHADOWPLAY_FLAGS(
    0x809d5f60,
    g_pszKeyName_SHADOWPLAY_FLAGS,
    g_pszRemappedName_SHADOWPLAY_FLAGS,
    g_pszMainDocs_SHADOWPLAY_FLAGS,
    g_pszDefinedWhen_SHADOWPLAY_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_SHADOWPLAY_FLAGS, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_AUDIO_INJECT_RXINPUT_DLL, 
    &g_setting_GFE_ADDRESSED, 
    &g_setting_GFE_DISPLAY_IN_UI, 
    &g_setting_GFE_GAMESESSION_TELEMETRY_REDESIGN, 
    &g_setting_GFE_MONITOR_USAGE, 
    &g_setting_GFE_SUPPORTED, 
    &g_setting_SHADOWPLAY_FLAGS, 
};

bool AddSettingsToHashByPlainNameGFE(NvSettingsHash &settingsHash)
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
bool AddSettingsToHashByIdGFE(NvSettingsIdHash &settingsIdHash)
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

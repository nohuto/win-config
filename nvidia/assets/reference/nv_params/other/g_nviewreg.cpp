/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME = "NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME = "The name of the current active desktop";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME(
    0x596265e8,
    g_pszKeyName_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME,
    g_pszRemappedName_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME,
    g_pszMainDocs_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME,
    g_pszDefinedWhen_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME, 
    1 
);

static const char *g_pszKeyName_NVIEW_DESKTOPS_ADD = "NVIEW_DESKTOPS_ADD";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_ADD = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_ADD = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_ADD = "Add a new desktop with specified properties. Format is <b><i>desktop name;per-monitor flag;path to the file with wallpaper image,wallpaper option</i></b>. Per-monitor flag could be 0 or 1, wallpaper options are 0 - center, 1 - tile, 2 - stretch. Example: <b><i>MyDesktop;1;wallpaper.jpg,3</i></b>";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_ADD_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_ADD[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_ADD_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_ADD[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_ADD(
    0x5971500b,
    g_pszKeyName_NVIEW_DESKTOPS_ADD,
    g_pszRemappedName_NVIEW_DESKTOPS_ADD,
    g_pszMainDocs_NVIEW_DESKTOPS_ADD,
    g_pszDefinedWhen_NVIEW_DESKTOPS_ADD,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_ADD, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_ADD, 
    1 
);

static const char *g_pszKeyName_NVIEW_DESKTOPS_DESKTOP_PROPERTIES = "NVIEW_DESKTOPS_DESKTOP_PROPERTIES";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_DESKTOP_PROPERTIES = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_DESKTOP_PROPERTIES = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_DESKTOP_PROPERTIES = "Get the properties like desktop name and wallpaper path for the specified desktop";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_DESKTOP_PROPERTIES_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_DESKTOP_PROPERTIES[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_DESKTOP_PROPERTIES_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_DESKTOP_PROPERTIES[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_DESKTOP_PROPERTIES(
    0x59affa30,
    g_pszKeyName_NVIEW_DESKTOPS_DESKTOP_PROPERTIES,
    g_pszRemappedName_NVIEW_DESKTOPS_DESKTOP_PROPERTIES,
    g_pszMainDocs_NVIEW_DESKTOPS_DESKTOP_PROPERTIES,
    g_pszDefinedWhen_NVIEW_DESKTOPS_DESKTOP_PROPERTIES,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_DESKTOP_PROPERTIES, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_DESKTOP_PROPERTIES, 
    1 
);

static const char *g_pszKeyName_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS = "NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS = "List with all available desktops";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS(
    0x59e85d5d,
    g_pszKeyName_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS,
    g_pszRemappedName_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS,
    g_pszMainDocs_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS,
    g_pszDefinedWhen_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_DESKTOPS_MODIFY_DESKTOP = "NVIEW_DESKTOPS_MODIFY_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_MODIFY_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_MODIFY_DESKTOP = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_MODIFY_DESKTOP = "Modify properties of a desktop. Format is <b><i>desktop name;per-monitor flag;path to the file with wallpaper image,wallpaper option</i></b>. Per-monitor flag could be 0 or 1, wallpaper options are 0 - center, 1 - tile, 2 - stretch. Example: <b><i>MyDesktop;1;wallpaper.jpg,3</i></b>";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_MODIFY_DESKTOP_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_MODIFY_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_MODIFY_DESKTOP_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_MODIFY_DESKTOP[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_MODIFY_DESKTOP(
    0x5932b06f,
    g_pszKeyName_NVIEW_DESKTOPS_MODIFY_DESKTOP,
    g_pszRemappedName_NVIEW_DESKTOPS_MODIFY_DESKTOP,
    g_pszMainDocs_NVIEW_DESKTOPS_MODIFY_DESKTOP,
    g_pszDefinedWhen_NVIEW_DESKTOPS_MODIFY_DESKTOP,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_MODIFY_DESKTOP, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_MODIFY_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_DESKTOPS_REMOVE = "NVIEW_DESKTOPS_REMOVE";
static const char *g_pszDefinedWhen_NVIEW_DESKTOPS_REMOVE = "1";
static const char *g_pszRemappedName_NVIEW_DESKTOPS_REMOVE = "_";
static const char *g_pszMainDocs_NVIEW_DESKTOPS_REMOVE = "Remove a desktop";

static const char * (g_ppszDefineDataNames_NVIEW_DESKTOPS_REMOVE_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_DESKTOPS_REMOVE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_DESKTOPS_REMOVE_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_DESKTOPS_REMOVE[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_DESKTOPS_REMOVE(
    0x5935fcd2,
    g_pszKeyName_NVIEW_DESKTOPS_REMOVE,
    g_pszRemappedName_NVIEW_DESKTOPS_REMOVE,
    g_pszMainDocs_NVIEW_DESKTOPS_REMOVE,
    g_pszDefinedWhen_NVIEW_DESKTOPS_REMOVE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_DESKTOPS_REMOVE, 
    1, 
    g_aDefaultData_NVIEW_DESKTOPS_REMOVE, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_COLLAPSE_DESKTOP = "NVIEW_ENABLE_COLLAPSE_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_COLLAPSE_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_COLLAPSE_DESKTOP = "NVIEW_SystemSubMenu_Collapse_to_this_desktop";
static const char *g_pszMainDocs_NVIEW_ENABLE_COLLAPSE_DESKTOP = "Enable/Disable nView Menu Option Collapse to this desktop";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_COLLAPSE_DESKTOP_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_COLLAPSE_DESKTOP_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_COLLAPSE_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_COLLAPSE_DESKTOP_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_COLLAPSE_DESKTOP_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_COLLAPSE_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_COLLAPSE_DESKTOP(
    0x59224b67,
    g_pszKeyName_NVIEW_ENABLE_COLLAPSE_DESKTOP,
    g_pszRemappedName_NVIEW_ENABLE_COLLAPSE_DESKTOP,
    g_pszMainDocs_NVIEW_ENABLE_COLLAPSE_DESKTOP,
    g_pszDefinedWhen_NVIEW_ENABLE_COLLAPSE_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_COLLAPSE_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_COLLAPSE_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION = "NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION = "Enable/Disable Show active desktop in Windows taskbar notification area";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION(
    0x591c2281,
    g_pszKeyName_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION,
    g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION,
    g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION,
    g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION = "NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION = "Enable/Disable Allow desktops to use different resolutions";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION(
    0x599ee73d,
    g_pszKeyName_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION,
    g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION,
    g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION,
    g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING = "NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING = "Enable/Disable Show desktop name when switching";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING(
    0x59fb742f,
    g_pszKeyName_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING,
    g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING,
    g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING,
    g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED = "NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED = "Enable/Disable Maximize desktop switching speed";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED(
    0x59d055dc,
    g_pszKeyName_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED,
    g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED,
    g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED,
    g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS = "NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS = "Enable/Disable Multiple desktops";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS(
    0x599a2b4e,
    g_pszKeyName_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS,
    g_pszRemappedName_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS,
    g_pszMainDocs_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS,
    g_pszDefinedWhen_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_INDIVIDUAL_SETTINGS = "NVIEW_ENABLE_INDIVIDUAL_SETTINGS";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_INDIVIDUAL_SETTINGS = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_INDIVIDUAL_SETTINGS = "NVIEW_SystemSubMenu_Individual_settings";
static const char *g_pszMainDocs_NVIEW_ENABLE_INDIVIDUAL_SETTINGS = "Enable/Disable nView Menu Option Individual settings";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_INDIVIDUAL_SETTINGS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_INDIVIDUAL_SETTINGS_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_INDIVIDUAL_SETTINGS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_INDIVIDUAL_SETTINGS_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_INDIVIDUAL_SETTINGS_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_INDIVIDUAL_SETTINGS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_INDIVIDUAL_SETTINGS(
    0x59f95c1d,
    g_pszKeyName_NVIEW_ENABLE_INDIVIDUAL_SETTINGS,
    g_pszRemappedName_NVIEW_ENABLE_INDIVIDUAL_SETTINGS,
    g_pszMainDocs_NVIEW_ENABLE_INDIVIDUAL_SETTINGS,
    g_pszDefinedWhen_NVIEW_ENABLE_INDIVIDUAL_SETTINGS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_INDIVIDUAL_SETTINGS, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_INDIVIDUAL_SETTINGS, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_LOCK_BUTTONBAR = "NVIEW_ENABLE_LOCK_BUTTONBAR";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_LOCK_BUTTONBAR = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_LOCK_BUTTONBAR = "NVIEW_SystemSubMenu_Lock_Buttonbar";
static const char *g_pszMainDocs_NVIEW_ENABLE_LOCK_BUTTONBAR = "Enable/Disable nView Menu Option Lock title bar buttons";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_LOCK_BUTTONBAR_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_LOCK_BUTTONBAR_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_LOCK_BUTTONBAR[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_LOCK_BUTTONBAR_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_LOCK_BUTTONBAR_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_LOCK_BUTTONBAR[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_LOCK_BUTTONBAR(
    0x590ce624,
    g_pszKeyName_NVIEW_ENABLE_LOCK_BUTTONBAR,
    g_pszRemappedName_NVIEW_ENABLE_LOCK_BUTTONBAR,
    g_pszMainDocs_NVIEW_ENABLE_LOCK_BUTTONBAR,
    g_pszDefinedWhen_NVIEW_ENABLE_LOCK_BUTTONBAR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_LOCK_BUTTONBAR, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_LOCK_BUTTONBAR, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP = "NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP = "NVIEW_SystemSubMenu_Maximize_to_desktop";
static const char *g_pszMainDocs_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP = "Enable/Disable nView Menu Option nView maximize(shift-Max)";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP(
    0x59d49f0b,
    g_pszKeyName_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP,
    g_pszRemappedName_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP,
    g_pszMainDocs_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP,
    g_pszDefinedWhen_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP = "NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP = "NVIEW_SystemSubMenu_Send_application_to_desktop";
static const char *g_pszMainDocs_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP = "Enable/Disable nView Menu Option Send application to desktop n";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP(
    0x592a2071,
    g_pszKeyName_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP,
    g_pszRemappedName_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP,
    g_pszMainDocs_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP,
    g_pszDefinedWhen_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR = "NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR = "NVIEW_SystemSubMenu_Send_application_to_monitor";
static const char *g_pszMainDocs_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR = "Enable/Disable nView Menu Option Send application to display n";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR(
    0x59873c39,
    g_pszKeyName_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR,
    g_pszRemappedName_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR,
    g_pszMainDocs_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR,
    g_pszDefinedWhen_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP = "NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP = "NVIEW_SystemSubMenu_Send_window_to_desktop";
static const char *g_pszMainDocs_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP = "Enable/Disable nView Menu Option Send window to desktop n";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP(
    0x59718ca3,
    g_pszKeyName_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP,
    g_pszRemappedName_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP,
    g_pszMainDocs_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP,
    g_pszDefinedWhen_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR = "NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR = "NVIEW_SystemSubMenu_Send_window_to_monitor";
static const char *g_pszMainDocs_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR = "Enable/Disable nView Menu Option Send window to monitor n";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR(
    0x59f48756,
    g_pszKeyName_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR,
    g_pszRemappedName_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR,
    g_pszMainDocs_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR,
    g_pszDefinedWhen_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP = "NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP = "NVIEW_SystemSubMenu_Always_on_top";
static const char *g_pszMainDocs_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP = "Enable/Disable nView Menu Option 'Always on top'";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP(
    0x5999a457,
    g_pszKeyName_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP,
    g_pszRemappedName_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP,
    g_pszMainDocs_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP,
    g_pszDefinedWhen_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_SYSTEMMENU = "NVIEW_ENABLE_SYSTEMMENU";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_SYSTEMMENU = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_SYSTEMMENU = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_SYSTEMMENU = "Enable/Disable Add nView options to system menus";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SYSTEMMENU_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_SYSTEMMENU_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_SYSTEMMENU[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SYSTEMMENU_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_SYSTEMMENU_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_SYSTEMMENU[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_SYSTEMMENU(
    0x59cf13f4,
    g_pszKeyName_NVIEW_ENABLE_SYSTEMMENU,
    g_pszRemappedName_NVIEW_ENABLE_SYSTEMMENU,
    g_pszMainDocs_NVIEW_ENABLE_SYSTEMMENU,
    g_pszDefinedWhen_NVIEW_ENABLE_SYSTEMMENU,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_SYSTEMMENU, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_SYSTEMMENU, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_TITLEBAR_COLLAPSE = "NVIEW_ENABLE_TITLEBAR_COLLAPSE";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_COLLAPSE = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_COLLAPSE = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_COLLAPSE = "Enable/Disable Title bar button Collapse to title bar";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_COLLAPSE_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_COLLAPSE_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_TITLEBAR_COLLAPSE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_COLLAPSE_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_COLLAPSE_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_TITLEBAR_COLLAPSE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_TITLEBAR_COLLAPSE(
    0x590b712c,
    g_pszKeyName_NVIEW_ENABLE_TITLEBAR_COLLAPSE,
    g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_COLLAPSE,
    g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_COLLAPSE,
    g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_COLLAPSE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_TITLEBAR_COLLAPSE, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_TITLEBAR_COLLAPSE, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_TITLEBAR_MAXIMIZE = "NVIEW_ENABLE_TITLEBAR_MAXIMIZE";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_MAXIMIZE = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_MAXIMIZE = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_MAXIMIZE = "Enable/Disable Title bar button Maximize";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_MAXIMIZE_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_MAXIMIZE_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_TITLEBAR_MAXIMIZE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_MAXIMIZE_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_MAXIMIZE_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_TITLEBAR_MAXIMIZE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_TITLEBAR_MAXIMIZE(
    0x599f9564,
    g_pszKeyName_NVIEW_ENABLE_TITLEBAR_MAXIMIZE,
    g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_MAXIMIZE,
    g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_MAXIMIZE,
    g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_MAXIMIZE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_TITLEBAR_MAXIMIZE, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_TITLEBAR_MAXIMIZE, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY = "NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY = "Enable/Disable Title bar button Next display";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY(
    0x59f14c39,
    g_pszKeyName_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY,
    g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY,
    g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY,
    g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS = "NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS = "_";
static const char *g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS = "Enable/Disable Title bar button nView options button";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS(
    0x59bbcc16,
    g_pszKeyName_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS,
    g_pszRemappedName_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS,
    g_pszMainDocs_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS,
    g_pszDefinedWhen_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_TRANSPARENT = "NVIEW_ENABLE_TRANSPARENT";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_TRANSPARENT = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_TRANSPARENT = "NVIEW_SystemSubMenu_Transparent";
static const char *g_pszMainDocs_NVIEW_ENABLE_TRANSPARENT = "Enable/Disable nView Menu Option Transparent";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TRANSPARENT_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_TRANSPARENT_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_TRANSPARENT[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TRANSPARENT_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_TRANSPARENT_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_TRANSPARENT[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_TRANSPARENT(
    0x59f9425b,
    g_pszKeyName_NVIEW_ENABLE_TRANSPARENT,
    g_pszRemappedName_NVIEW_ENABLE_TRANSPARENT,
    g_pszMainDocs_NVIEW_ENABLE_TRANSPARENT,
    g_pszDefinedWhen_NVIEW_ENABLE_TRANSPARENT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_TRANSPARENT, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_TRANSPARENT, 
    1 
);

static const char *g_pszKeyName_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS = "NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS";
static const char *g_pszDefinedWhen_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS = "1";
static const char *g_pszRemappedName_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS = "NVIEW_SystemSubMenu_Visible_on_all_desktops";
static const char *g_pszMainDocs_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS = "Enable/Disable nView Menu Option Visible on all desktops";

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS_ENABLE, 1 , "Enable menu item for a feature" },
    { (const char **)g_ppszDefineDataNames_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS_DISABLE, 0 , "Disable menu item for a feature" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS(
    0x5951917b,
    g_pszKeyName_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS,
    g_pszRemappedName_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS,
    g_pszMainDocs_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS,
    g_pszDefinedWhen_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS, 
    2, 
    g_aDefaultData_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_GRIDLINE_EDITOR = "NVIEW_GRIDLINE_EDITOR";
static const char *g_pszDefinedWhen_NVIEW_GRIDLINE_EDITOR = "1";
static const char *g_pszRemappedName_NVIEW_GRIDLINE_EDITOR = "NVIEW_ControlPanel_ShowGridlines";
static const char *g_pszMainDocs_NVIEW_GRIDLINE_EDITOR = "Show/Hide Gridline Editor feature";

static const char * (g_ppszDefineDataNames_NVIEW_GRIDLINE_EDITOR_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_GRIDLINE_EDITOR_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_GRIDLINE_EDITOR[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_GRIDLINE_EDITOR_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_GRIDLINE_EDITOR_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_GRIDLINE_EDITOR[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_GRIDLINE_EDITOR(
    0x5971e144,
    g_pszKeyName_NVIEW_GRIDLINE_EDITOR,
    g_pszRemappedName_NVIEW_GRIDLINE_EDITOR,
    g_pszMainDocs_NVIEW_GRIDLINE_EDITOR,
    g_pszDefinedWhen_NVIEW_GRIDLINE_EDITOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_GRIDLINE_EDITOR, 
    2, 
    g_aDefaultData_NVIEW_GRIDLINE_EDITOR, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE = "NVIEW_HOTKEY_SAVE_WORKSPACE_STATE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE = "NVIEW_Hotkeys_Disable__WorkspaceSaveTag";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE = "Show/Hide Hotkey action that will save workspace state, current display,desktop management and open application state";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE(
    0x59c8134b,
    g_pszKeyName_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE,
    g_pszRemappedName_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE,
    g_pszMainDocs_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS = "NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS = "NVIEW_Hotkeys_Disable__ShowAppOnAllDesktops";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS = "Show/Hide Hotkey action that will Toggle show on all desktops";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS(
    0x597d8b59,
    g_pszKeyName_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS,
    g_pszRemappedName_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS,
    g_pszMainDocs_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOWGRID = "NVIEW_HOTKEY_SHOWGRID";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOWGRID = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOWGRID = "NVIEW_Hotkeys_Disable__ShowGrid";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOWGRID = "Show/Hide Hotkey action that will show display grid";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWGRID_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWGRID_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOWGRID[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWGRID_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOWGRID_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOWGRID[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOWGRID(
    0x59414ae2,
    g_pszKeyName_NVIEW_HOTKEY_SHOWGRID,
    g_pszRemappedName_NVIEW_HOTKEY_SHOWGRID,
    g_pszMainDocs_NVIEW_HOTKEY_SHOWGRID,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOWGRID,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOWGRID, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOWGRID, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP = "NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP = "NVIEW_Hotkeys_Disable__SwitchDesktop";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP = "Show/Hide Hotkey action that will Activate desktop";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP(
    0x59987658,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA = "NVIEW_HOTKEY_SHOW_ADJUST_GAMMA";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA = "NVIEW_Hotkeys_Disable__Gamma";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA = "Show/Hide Hotkey action adjust display gamma";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA(
    0x5915308a,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_ALWAYSONTOP = "NVIEW_HOTKEY_SHOW_ALWAYSONTOP";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ALWAYSONTOP = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_ALWAYSONTOP = "NVIEW_Hotkeys_Disable__AlwaysOnTop";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_ALWAYSONTOP = "Show/Hide Hotkey action Toggle always on top";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ALWAYSONTOP_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ALWAYSONTOP_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_ALWAYSONTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ALWAYSONTOP_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ALWAYSONTOP_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_ALWAYSONTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_ALWAYSONTOP(
    0x59cfa545,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_ALWAYSONTOP,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_ALWAYSONTOP,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_ALWAYSONTOP,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ALWAYSONTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_ALWAYSONTOP, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_ALWAYSONTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_BRIGHTNESS = "NVIEW_HOTKEY_SHOW_BRIGHTNESS";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_BRIGHTNESS = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_BRIGHTNESS = "NVIEW_Hotkeys_Disable__Brightness";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_BRIGHTNESS = "Show/Hide Hotkey action adjust display brightness";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_BRIGHTNESS_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_BRIGHTNESS_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_BRIGHTNESS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_BRIGHTNESS_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_BRIGHTNESS_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_BRIGHTNESS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_BRIGHTNESS(
    0x5933274d,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_BRIGHTNESS,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_BRIGHTNESS,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_BRIGHTNESS,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_BRIGHTNESS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_BRIGHTNESS, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_BRIGHTNESS, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_COLLAPSEALL = "NVIEW_HOTKEY_SHOW_COLLAPSEALL";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_COLLAPSEALL = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_COLLAPSEALL = "NVIEW_Hotkeys_Disable__CollapseAll";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_COLLAPSEALL = "Show/Hide Hotkey action Collapse all windows";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSEALL_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSEALL_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_COLLAPSEALL[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSEALL_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSEALL_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_COLLAPSEALL[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_COLLAPSEALL(
    0x590fc640,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_COLLAPSEALL,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_COLLAPSEALL,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_COLLAPSEALL,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_COLLAPSEALL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_COLLAPSEALL, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_COLLAPSEALL, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP = "NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP = "NVIEW_Hotkeys_Disable__CollapseToDesktop";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP = "Show/Hide Hotkey action Collapse to desktop";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP(
    0x59c3330f,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_CONTRAST = "NVIEW_HOTKEY_SHOW_CONTRAST";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_CONTRAST = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_CONTRAST = "NVIEW_Hotkeys_Disable__Contrast";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_CONTRAST = "Show/Hide Hotkey action adjust display contrast";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_CONTRAST_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_CONTRAST_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_CONTRAST[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_CONTRAST_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_CONTRAST_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_CONTRAST[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_CONTRAST(
    0x591ae39e,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_CONTRAST,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_CONTRAST,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_CONTRAST,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_CONTRAST,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_CONTRAST, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_CONTRAST, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_DESKTOPLOCK = "NVIEW_HOTKEY_SHOW_DESKTOPLOCK";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_DESKTOPLOCK = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_DESKTOPLOCK = "NVIEW_Hotkeys_Disable__DesktopLock";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_DESKTOPLOCK = "Show/Hide Hotkey action that will lock your desktop";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_DESKTOPLOCK_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_DESKTOPLOCK_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_DESKTOPLOCK[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_DESKTOPLOCK_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_DESKTOPLOCK_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_DESKTOPLOCK[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_DESKTOPLOCK(
    0x592cec41,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_DESKTOPLOCK,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_DESKTOPLOCK,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_DESKTOPLOCK,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_DESKTOPLOCK,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_DESKTOPLOCK, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_DESKTOPLOCK, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_GAMMA_RESET = "NVIEW_HOTKEY_SHOW_GAMMA_RESET";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_GAMMA_RESET = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_GAMMA_RESET = "NVIEW_Hotkeys_Disable__GammaReset";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_GAMMA_RESET = "Show/Hide Hotkey action reset gamma brightness and contrast to default";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GAMMA_RESET_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GAMMA_RESET_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_GAMMA_RESET[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GAMMA_RESET_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GAMMA_RESET_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_GAMMA_RESET[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_GAMMA_RESET(
    0x5910e51f,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_GAMMA_RESET,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_GAMMA_RESET,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_GAMMA_RESET,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_GAMMA_RESET,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_GAMMA_RESET, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_GAMMA_RESET, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1 = "NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1 = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1 = "NVIEW_Hotkeys_Disable__GatherAllToMonitor1";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1 = "Show/Hide Hotkey action Send all windows to display";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1(
    0x59fea9b8,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_LOADPROFILE = "NVIEW_HOTKEY_SHOW_LOADPROFILE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_LOADPROFILE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_LOADPROFILE = "NVIEW_Hotkeys_Disable__LoadProfile";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_LOADPROFILE = "Show/Hide Hotkey action that will load profile";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_LOADPROFILE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_LOADPROFILE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_LOADPROFILE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_LOADPROFILE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_LOADPROFILE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_LOADPROFILE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_LOADPROFILE(
    0x596f125a,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_LOADPROFILE,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_LOADPROFILE,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_LOADPROFILE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_LOADPROFILE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_LOADPROFILE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_LOADPROFILE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_MAX_RESTORE = "NVIEW_HOTKEY_SHOW_MAX_RESTORE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_MAX_RESTORE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_MAX_RESTORE = "NVIEW_Hotkeys_Disable__MaxRestore";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_MAX_RESTORE = "Show/Hide Hotkey action Max/Restore window";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_MAX_RESTORE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_MAX_RESTORE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_MAX_RESTORE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_MAX_RESTORE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_MAX_RESTORE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_MAX_RESTORE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_MAX_RESTORE(
    0x592c5c9d,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_MAX_RESTORE,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_MAX_RESTORE,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_MAX_RESTORE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_MAX_RESTORE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_MAX_RESTORE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_MAX_RESTORE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY = "NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY = "NVIEW_Hotkeys_Disable__RotateMonitor";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY = "Show/Hide Hotkey action that will rotate the display (or the desktop) by an amount you specify";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY(
    0x59f10483,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION = "NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION = "NVIEW_Hotkeys_Disable__RunApplication";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION = "Show/Hide Hotkey action that will run a user specified application";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION(
    0x593a2a63,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS = "NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS = "NVIEW_Hotkeys_Disable__NVTaskSwitchSystemApps";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS = "Show/Hide Hotkey action that will allow you to switch between applications on all desktops";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS(
    0x595eb7da,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS = "NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS = "NVIEW_Hotkeys_Disable__NVTaskSwitchDesktopApps";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS = "Show/Hide Hotkey action that allows to toggle desktop applications";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS(
    0x596c172f,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS = "NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS = "NVIEW_Hotkeys_Disable__NVTaskSwitchDesktops";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS = "Show/Hide Hotkey action that allows to toggle desktops";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS(
    0x596bf876,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTOOLBAR = "NVIEW_HOTKEY_SHOW_NVTOOLBAR";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTOOLBAR = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTOOLBAR = "NVIEW_Hotkeys_Disable__NVToolbar";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTOOLBAR = "Show/Hide Hotkey action that will show and hide the nView toolbar";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTOOLBAR_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTOOLBAR_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_NVTOOLBAR[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTOOLBAR_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_NVTOOLBAR_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTOOLBAR[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_NVTOOLBAR(
    0x59f512c8,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_NVTOOLBAR,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_NVTOOLBAR,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_NVTOOLBAR,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_NVTOOLBAR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_NVTOOLBAR, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_NVTOOLBAR, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE = "NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE = "NVIEW_Hotkeys_Disable__WorkspaceRestTag";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE = "Show/Hide Hotkey action that will restore a save workspace state including display, desktop management and open applications";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE(
    0x597ddc7f,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL = "NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL = "NVIEW_Hotkeys_Disable__RunControlPanel";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL = "Show/Hide Hotkey action that will open the nView control panel";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL(
    0x59eec40f,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SAVEPROFILE = "NVIEW_HOTKEY_SHOW_SAVEPROFILE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SAVEPROFILE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SAVEPROFILE = "NVIEW_Hotkeys_Disable__SaveProfile";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SAVEPROFILE = "Show/Hide Hotkeys action that will save profile";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SAVEPROFILE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SAVEPROFILE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SAVEPROFILE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SAVEPROFILE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SAVEPROFILE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SAVEPROFILE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SAVEPROFILE(
    0x59a0b829,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SAVEPROFILE,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SAVEPROFILE,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SAVEPROFILE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SAVEPROFILE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SAVEPROFILE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SAVEPROFILE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP = "NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP = "NVIEW_Hotkeys_Disable__SendWindowToDesktop";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP = "Show/Hide Hotkey action that will move window to desktop";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP(
    0x59979785,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY = "NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY = "NVIEW_Hotkeys_Disable__SendWindowToMonitor";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY = "Show/Hide Hotkey action that will move window to display";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY(
    0x59ae7814,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY = "NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY = "NVIEW_Hotkeys_Disable__SendToNextMon";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY = "Show/Hide Hotkey action that will move window to next display";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY(
    0x5989e671,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SHOWDESKNAME = "NVIEW_HOTKEY_SHOW_SHOWDESKNAME";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SHOWDESKNAME = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SHOWDESKNAME = "NVIEW_Hotkeys_Disable__ShowDeskName";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SHOWDESKNAME = "Show/Hide Hotkey action that will show desktop name";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SHOWDESKNAME_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SHOWDESKNAME_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SHOWDESKNAME[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SHOWDESKNAME_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SHOWDESKNAME_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SHOWDESKNAME[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SHOWDESKNAME(
    0x591c9979,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SHOWDESKNAME,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SHOWDESKNAME,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SHOWDESKNAME,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SHOWDESKNAME,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SHOWDESKNAME, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SHOWDESKNAME, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_SYSTEMMENU = "NVIEW_HOTKEY_SHOW_SYSTEMMENU";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SYSTEMMENU = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_SYSTEMMENU = "NVIEW_Hotkeys_Disable__SystemMenu";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_SYSTEMMENU = "Show/Hide Hotkey action that will Show nView options menu";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SYSTEMMENU_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SYSTEMMENU_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_SYSTEMMENU[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SYSTEMMENU_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_SYSTEMMENU_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_SYSTEMMENU[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_SYSTEMMENU(
    0x5908b520,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_SYSTEMMENU,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_SYSTEMMENU,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_SYSTEMMENU,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_SYSTEMMENU,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_SYSTEMMENU, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_SYSTEMMENU, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLECLONE = "NVIEW_HOTKEY_SHOW_TOGGLECLONE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLECLONE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLECLONE = "NVIEW_Hotkeys_Disable__ToggleClone";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLECLONE = "Show/Hide Hotkey action that will toggle clone mode on or off";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLECLONE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLECLONE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLECLONE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLECLONE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLECLONE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLECLONE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_TOGGLECLONE(
    0x5944ae99,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLECLONE,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLECLONE,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLECLONE,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLECLONE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLECLONE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLECLONE, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING = "NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING = "NVIEW_Hotkeys_Disable__ToggleLCDScale";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING = "Show/Hide Hotkey action that will toggle LCD scaling on and off";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING(
    0x5917ccee,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT = "NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT = "NVIEW_Hotkeys_Disable__ToggleOutput";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT = "Show/Hide Hotkey action that will Switch to next display device";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT(
    0x5900fa12,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY = "NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY = "NVIEW_Hotkeys_Disable__TransparentWindow";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY = "Show/Hide Hotkey action that will Toggle transparency";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY(
    0x59d5d836,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_SHOW_ZOOMWINDOW = "NVIEW_HOTKEY_SHOW_ZOOMWINDOW";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ZOOMWINDOW = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_SHOW_ZOOMWINDOW = "NVIEW_Hotkeys_Disable__ZoomWindow";
static const char *g_pszMainDocs_NVIEW_HOTKEY_SHOW_ZOOMWINDOW = "Show/Hide Hotkey action that will show and hide the zoom window";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ZOOMWINDOW_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ZOOMWINDOW_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_SHOW_ZOOMWINDOW[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ZOOMWINDOW_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_SHOW_ZOOMWINDOW_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_SHOW_ZOOMWINDOW[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_SHOW_ZOOMWINDOW(
    0x5993eb80,
    g_pszKeyName_NVIEW_HOTKEY_SHOW_ZOOMWINDOW,
    g_pszRemappedName_NVIEW_HOTKEY_SHOW_ZOOMWINDOW,
    g_pszMainDocs_NVIEW_HOTKEY_SHOW_ZOOMWINDOW,
    g_pszDefinedWhen_NVIEW_HOTKEY_SHOW_ZOOMWINDOW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_SHOW_ZOOMWINDOW, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_SHOW_ZOOMWINDOW, 
    1 
);

static const char *g_pszKeyName_NVIEW_HOTKEY_ZOOMTYPE = "NVIEW_HOTKEY_ZOOMTYPE";
static const char *g_pszDefinedWhen_NVIEW_HOTKEY_ZOOMTYPE = "1";
static const char *g_pszRemappedName_NVIEW_HOTKEY_ZOOMTYPE = "NVIEW_Hotkeys_Disable__ZoomType";
static const char *g_pszMainDocs_NVIEW_HOTKEY_ZOOMTYPE = "Show/Hide Hotkey action that toggles zoom window style between Cursor & Magnifying Glass and Fixed Frame";

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_ZOOMTYPE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_HOTKEY_ZOOMTYPE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_HOTKEY_ZOOMTYPE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_ZOOMTYPE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_HOTKEY_ZOOMTYPE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_HOTKEY_ZOOMTYPE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_HOTKEY_ZOOMTYPE(
    0x59400fae,
    g_pszKeyName_NVIEW_HOTKEY_ZOOMTYPE,
    g_pszRemappedName_NVIEW_HOTKEY_ZOOMTYPE,
    g_pszMainDocs_NVIEW_HOTKEY_ZOOMTYPE,
    g_pszDefinedWhen_NVIEW_HOTKEY_ZOOMTYPE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_HOTKEY_ZOOMTYPE, 
    2, 
    g_aDefaultData_NVIEW_HOTKEY_ZOOMTYPE, 
    1 
);

static const char *g_pszKeyName_NVIEW_PROFILE_CURRENT_PROFILE_NAME = "NVIEW_PROFILE_CURRENT_PROFILE_NAME";
static const char *g_pszDefinedWhen_NVIEW_PROFILE_CURRENT_PROFILE_NAME = "1";
static const char *g_pszRemappedName_NVIEW_PROFILE_CURRENT_PROFILE_NAME = "_";
static const char *g_pszMainDocs_NVIEW_PROFILE_CURRENT_PROFILE_NAME = "The name of the current profile";

static const char * (g_ppszDefineDataNames_NVIEW_PROFILE_CURRENT_PROFILE_NAME_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_PROFILE_CURRENT_PROFILE_NAME[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_PROFILE_CURRENT_PROFILE_NAME_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_PROFILE_CURRENT_PROFILE_NAME[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_PROFILE_CURRENT_PROFILE_NAME(
    0x59d169d7,
    g_pszKeyName_NVIEW_PROFILE_CURRENT_PROFILE_NAME,
    g_pszRemappedName_NVIEW_PROFILE_CURRENT_PROFILE_NAME,
    g_pszMainDocs_NVIEW_PROFILE_CURRENT_PROFILE_NAME,
    g_pszDefinedWhen_NVIEW_PROFILE_CURRENT_PROFILE_NAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_PROFILE_CURRENT_PROFILE_NAME, 
    1, 
    g_aDefaultData_NVIEW_PROFILE_CURRENT_PROFILE_NAME, 
    1 
);

static const char *g_pszKeyName_NVIEW_PROFILE_DELETE = "NVIEW_PROFILE_DELETE";
static const char *g_pszDefinedWhen_NVIEW_PROFILE_DELETE = "1";
static const char *g_pszRemappedName_NVIEW_PROFILE_DELETE = "_";
static const char *g_pszMainDocs_NVIEW_PROFILE_DELETE = "Delete the specified profile from nView Desktop Manager";

static const char * (g_ppszDefineDataNames_NVIEW_PROFILE_DELETE_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_PROFILE_DELETE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_PROFILE_DELETE_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_PROFILE_DELETE[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_PROFILE_DELETE(
    0x59ed4cae,
    g_pszKeyName_NVIEW_PROFILE_DELETE,
    g_pszRemappedName_NVIEW_PROFILE_DELETE,
    g_pszMainDocs_NVIEW_PROFILE_DELETE,
    g_pszDefinedWhen_NVIEW_PROFILE_DELETE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_PROFILE_DELETE, 
    1, 
    g_aDefaultData_NVIEW_PROFILE_DELETE, 
    1 
);

static const char *g_pszKeyName_NVIEW_PROFILE_LOAD = "NVIEW_PROFILE_LOAD";
static const char *g_pszDefinedWhen_NVIEW_PROFILE_LOAD = "1";
static const char *g_pszRemappedName_NVIEW_PROFILE_LOAD = "_";
static const char *g_pszMainDocs_NVIEW_PROFILE_LOAD = "Load the selected profile in nView Desktop Manager. All current nView Desktop Manager settings will be replaced with profile's";

DataDefaultDWORD g_aDefaultData_NVIEW_PROFILE_LOAD[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_PROFILE_LOAD(
    0x593c6eed,
    g_pszKeyName_NVIEW_PROFILE_LOAD,
    g_pszRemappedName_NVIEW_PROFILE_LOAD,
    g_pszMainDocs_NVIEW_PROFILE_LOAD,
    g_pszDefinedWhen_NVIEW_PROFILE_LOAD,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_NVIEW_PROFILE_LOAD, 
    1 
);

static const char *g_pszKeyName_NVIEW_PROFILE_LOCK = "NVIEW_PROFILE_LOCK";
static const char *g_pszDefinedWhen_NVIEW_PROFILE_LOCK = "1";
static const char *g_pszRemappedName_NVIEW_PROFILE_LOCK = "_";
static const char *g_pszMainDocs_NVIEW_PROFILE_LOCK = "Lock the selected profile";

static const char * (g_ppszDefineDataNames_NVIEW_PROFILE_LOCK_LOCK)[] =
{
    "LOCK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_PROFILE_LOCK_UNLOCK)[] =
{
    "UNLOCK",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_PROFILE_LOCK[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_PROFILE_LOCK_LOCK, 0 , "Lock nView profile" },
    { (const char **)g_ppszDefineDataNames_NVIEW_PROFILE_LOCK_UNLOCK, 1 , "Unlock nView profile" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_PROFILE_LOCK[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_PROFILE_LOCK(
    0x59ef38a2,
    g_pszKeyName_NVIEW_PROFILE_LOCK,
    g_pszRemappedName_NVIEW_PROFILE_LOCK,
    g_pszMainDocs_NVIEW_PROFILE_LOCK,
    g_pszDefinedWhen_NVIEW_PROFILE_LOCK,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_PROFILE_LOCK, 
    2, 
    g_aDefaultData_NVIEW_PROFILE_LOCK, 
    1 
);

static const char *g_pszKeyName_NVIEW_PROFILE_SAVE = "NVIEW_PROFILE_SAVE";
static const char *g_pszDefinedWhen_NVIEW_PROFILE_SAVE = "1";
static const char *g_pszRemappedName_NVIEW_PROFILE_SAVE = "_";
static const char *g_pszMainDocs_NVIEW_PROFILE_SAVE = "Save current nView Desktop Manager setting to selected profile";

static const char * (g_ppszDefineDataNames_NVIEW_PROFILE_SAVE_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVIEW_PROFILE_SAVE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_PROFILE_SAVE_NONE, "none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVIEW_PROFILE_SAVE[] =
{
    {"DEFAULT", "none", "" }, 
};

SettingWSTRING g_setting_NVIEW_PROFILE_SAVE(
    0x5980cd81,
    g_pszKeyName_NVIEW_PROFILE_SAVE,
    g_pszRemappedName_NVIEW_PROFILE_SAVE,
    g_pszMainDocs_NVIEW_PROFILE_SAVE,
    g_pszDefinedWhen_NVIEW_PROFILE_SAVE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_PROFILE_SAVE, 
    1, 
    g_aDefaultData_NVIEW_PROFILE_SAVE, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_APPLICATION = "NVIEW_TAB_APPLICATION";
static const char *g_pszDefinedWhen_NVIEW_TAB_APPLICATION = "1";
static const char *g_pszRemappedName_NVIEW_TAB_APPLICATION = "NVIEW_ControlPanel_ShowApps";
static const char *g_pszMainDocs_NVIEW_TAB_APPLICATION = "Show/Hide Applications feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_APPLICATION_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_APPLICATION_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_APPLICATION[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_APPLICATION_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_APPLICATION_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_APPLICATION[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_APPLICATION(
    0x59a27815,
    g_pszKeyName_NVIEW_TAB_APPLICATION,
    g_pszRemappedName_NVIEW_TAB_APPLICATION,
    g_pszMainDocs_NVIEW_TAB_APPLICATION,
    g_pszDefinedWhen_NVIEW_TAB_APPLICATION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_APPLICATION, 
    2, 
    g_aDefaultData_NVIEW_TAB_APPLICATION, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_DESKTOP = "NVIEW_TAB_DESKTOP";
static const char *g_pszDefinedWhen_NVIEW_TAB_DESKTOP = "1";
static const char *g_pszRemappedName_NVIEW_TAB_DESKTOP = "NVIEW_ControlPanel_ShowDesktops";
static const char *g_pszMainDocs_NVIEW_TAB_DESKTOP = "Show/Hide Virtual Desktop Editor feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_DESKTOP_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_DESKTOP_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_DESKTOP[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_DESKTOP_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_DESKTOP_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_DESKTOP[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_DESKTOP(
    0x598170ab,
    g_pszKeyName_NVIEW_TAB_DESKTOP,
    g_pszRemappedName_NVIEW_TAB_DESKTOP,
    g_pszMainDocs_NVIEW_TAB_DESKTOP,
    g_pszDefinedWhen_NVIEW_TAB_DESKTOP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_DESKTOP, 
    2, 
    g_aDefaultData_NVIEW_TAB_DESKTOP, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_HOT_KEY = "NVIEW_TAB_HOT_KEY";
static const char *g_pszDefinedWhen_NVIEW_TAB_HOT_KEY = "1";
static const char *g_pszRemappedName_NVIEW_TAB_HOT_KEY = "NVIEW_ControlPanel_ShowHotkeys";
static const char *g_pszMainDocs_NVIEW_TAB_HOT_KEY = "Show/Hide Hotkey Manager feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_HOT_KEY_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_HOT_KEY_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_HOT_KEY[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_HOT_KEY_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_HOT_KEY_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_HOT_KEY[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_HOT_KEY(
    0x59014748,
    g_pszKeyName_NVIEW_TAB_HOT_KEY,
    g_pszRemappedName_NVIEW_TAB_HOT_KEY,
    g_pszMainDocs_NVIEW_TAB_HOT_KEY,
    g_pszDefinedWhen_NVIEW_TAB_HOT_KEY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_HOT_KEY, 
    2, 
    g_aDefaultData_NVIEW_TAB_HOT_KEY, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_PROFILE = "NVIEW_TAB_PROFILE";
static const char *g_pszDefinedWhen_NVIEW_TAB_PROFILE = "1";
static const char *g_pszRemappedName_NVIEW_TAB_PROFILE = "NVIEW_ControlPanel_ShowProfiles";
static const char *g_pszMainDocs_NVIEW_TAB_PROFILE = "Show/Hide Profile Manager feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_PROFILE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_PROFILE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_PROFILE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_PROFILE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_PROFILE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_PROFILE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_PROFILE(
    0x59a7d007,
    g_pszKeyName_NVIEW_TAB_PROFILE,
    g_pszRemappedName_NVIEW_TAB_PROFILE,
    g_pszMainDocs_NVIEW_TAB_PROFILE,
    g_pszDefinedWhen_NVIEW_TAB_PROFILE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_PROFILE, 
    2, 
    g_aDefaultData_NVIEW_TAB_PROFILE, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_USERINTERFACE = "NVIEW_TAB_USERINTERFACE";
static const char *g_pszDefinedWhen_NVIEW_TAB_USERINTERFACE = "1";
static const char *g_pszRemappedName_NVIEW_TAB_USERINTERFACE = "NVIEW_ControlPanel_ShowUI";
static const char *g_pszMainDocs_NVIEW_TAB_USERINTERFACE = "Show/Hide User Interface feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_USERINTERFACE_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_USERINTERFACE_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_USERINTERFACE[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_USERINTERFACE_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_USERINTERFACE_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_USERINTERFACE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_USERINTERFACE(
    0x5935f891,
    g_pszKeyName_NVIEW_TAB_USERINTERFACE,
    g_pszRemappedName_NVIEW_TAB_USERINTERFACE,
    g_pszMainDocs_NVIEW_TAB_USERINTERFACE,
    g_pszDefinedWhen_NVIEW_TAB_USERINTERFACE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_USERINTERFACE, 
    2, 
    g_aDefaultData_NVIEW_TAB_USERINTERFACE, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_WINDOW = "NVIEW_TAB_WINDOW";
static const char *g_pszDefinedWhen_NVIEW_TAB_WINDOW = "1";
static const char *g_pszRemappedName_NVIEW_TAB_WINDOW = "NVIEW_ControlPanel_ShowWindows";
static const char *g_pszMainDocs_NVIEW_TAB_WINDOW = "Show/Hide Window Manager feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_WINDOW_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_WINDOW_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_WINDOW[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_WINDOW_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_WINDOW_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_WINDOW[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_WINDOW(
    0x5972babb,
    g_pszKeyName_NVIEW_TAB_WINDOW,
    g_pszRemappedName_NVIEW_TAB_WINDOW,
    g_pszMainDocs_NVIEW_TAB_WINDOW,
    g_pszDefinedWhen_NVIEW_TAB_WINDOW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_WINDOW, 
    2, 
    g_aDefaultData_NVIEW_TAB_WINDOW, 
    1 
);

static const char *g_pszKeyName_NVIEW_TAB_ZOOM = "NVIEW_TAB_ZOOM";
static const char *g_pszDefinedWhen_NVIEW_TAB_ZOOM = "1";
static const char *g_pszRemappedName_NVIEW_TAB_ZOOM = "NVIEW_ControlPanel_ShowZoom";
static const char *g_pszMainDocs_NVIEW_TAB_ZOOM = "Show/Hide Zoom feature";

static const char * (g_ppszDefineDataNames_NVIEW_TAB_ZOOM_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVIEW_TAB_ZOOM_HIDE)[] =
{
    "HIDE",
    NULL
};

DataValueDWORD g_aDefineData_NVIEW_TAB_ZOOM[] =
{
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_ZOOM_SHOW, 1 , "Show feature menu" },
    { (const char **)g_ppszDefineDataNames_NVIEW_TAB_ZOOM_HIDE, 0 , "Hide feature menu" },
};

DataDefaultDWORD g_aDefaultData_NVIEW_TAB_ZOOM[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVIEW_TAB_ZOOM(
    0x59f49c46,
    g_pszKeyName_NVIEW_TAB_ZOOM,
    g_pszRemappedName_NVIEW_TAB_ZOOM,
    g_pszMainDocs_NVIEW_TAB_ZOOM,
    g_pszDefinedWhen_NVIEW_TAB_ZOOM,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVIEW_TAB_ZOOM, 
    2, 
    g_aDefaultData_NVIEW_TAB_ZOOM, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_NVIEW_DESKTOPS_ACTIVE_DESKTOP_NAME, 
    &g_setting_NVIEW_DESKTOPS_ADD, 
    &g_setting_NVIEW_DESKTOPS_DESKTOP_PROPERTIES, 
    &g_setting_NVIEW_DESKTOPS_LIST_AVAILABLE_DESKTOPS, 
    &g_setting_NVIEW_DESKTOPS_MODIFY_DESKTOP, 
    &g_setting_NVIEW_DESKTOPS_REMOVE, 
    &g_setting_NVIEW_ENABLE_COLLAPSE_DESKTOP, 
    &g_setting_NVIEW_ENABLE_DESKTOPS_ACTIVEDESKTOP_NOTIFICATION, 
    &g_setting_NVIEW_ENABLE_DESKTOPS_ALLOW_DESKTOP_DIFFERENT_RESOLUTION, 
    &g_setting_NVIEW_ENABLE_DESKTOPS_DESKTOP_NAME_IN_SWITCHING, 
    &g_setting_NVIEW_ENABLE_DESKTOPS_MAXIMIZE_DESKTOP_SWITCHSPEED, 
    &g_setting_NVIEW_ENABLE_DESKTOPS_MULTIPLE_DESKTOPS, 
    &g_setting_NVIEW_ENABLE_INDIVIDUAL_SETTINGS, 
    &g_setting_NVIEW_ENABLE_LOCK_BUTTONBAR, 
    &g_setting_NVIEW_ENABLE_MAXIMIZE_TO_DESKTOP, 
    &g_setting_NVIEW_ENABLE_SEND_APPLICATION_TO_DESKTOP, 
    &g_setting_NVIEW_ENABLE_SEND_APPLICATION_TO_MONITOR, 
    &g_setting_NVIEW_ENABLE_SEND_WINDOW_TO_DESKTOP, 
    &g_setting_NVIEW_ENABLE_SEND_WINDOW_TO_MONITOR, 
    &g_setting_NVIEW_ENABLE_SETTING_ALWAYS_ON_TOP, 
    &g_setting_NVIEW_ENABLE_SYSTEMMENU, 
    &g_setting_NVIEW_ENABLE_TITLEBAR_COLLAPSE, 
    &g_setting_NVIEW_ENABLE_TITLEBAR_MAXIMIZE, 
    &g_setting_NVIEW_ENABLE_TITLEBAR_NEXT_DISPLAY, 
    &g_setting_NVIEW_ENABLE_TITLEBAR_NVIEWOPTIONS, 
    &g_setting_NVIEW_ENABLE_TRANSPARENT, 
    &g_setting_NVIEW_ENABLE_VISIBLE_ON_ALL_DESKTOPS, 
    &g_setting_NVIEW_GRIDLINE_EDITOR, 
    &g_setting_NVIEW_HOTKEY_SAVE_WORKSPACE_STATE, 
    &g_setting_NVIEW_HOTKEY_SHOWAPPONALLDESKTOPS, 
    &g_setting_NVIEW_HOTKEY_SHOWGRID, 
    &g_setting_NVIEW_HOTKEY_SHOW_ACTIVATE_DESKTOP, 
    &g_setting_NVIEW_HOTKEY_SHOW_ADJUST_GAMMA, 
    &g_setting_NVIEW_HOTKEY_SHOW_ALWAYSONTOP, 
    &g_setting_NVIEW_HOTKEY_SHOW_BRIGHTNESS, 
    &g_setting_NVIEW_HOTKEY_SHOW_COLLAPSEALL, 
    &g_setting_NVIEW_HOTKEY_SHOW_COLLAPSE_TO_DESKTOP, 
    &g_setting_NVIEW_HOTKEY_SHOW_CONTRAST, 
    &g_setting_NVIEW_HOTKEY_SHOW_DESKTOPLOCK, 
    &g_setting_NVIEW_HOTKEY_SHOW_GAMMA_RESET, 
    &g_setting_NVIEW_HOTKEY_SHOW_GATHERALL_MONITOR1, 
    &g_setting_NVIEW_HOTKEY_SHOW_LOADPROFILE, 
    &g_setting_NVIEW_HOTKEY_SHOW_MAX_RESTORE, 
    &g_setting_NVIEW_HOTKEY_SHOW_NEXT_ROTATE_DISPLAY, 
    &g_setting_NVIEW_HOTKEY_SHOW_NEXT_RUN_APPLICATION, 
    &g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_ALL_APPLICATIONS, 
    &g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPAPPS, 
    &g_setting_NVIEW_HOTKEY_SHOW_NVTASKSWITCH_DESKTOPS, 
    &g_setting_NVIEW_HOTKEY_SHOW_NVTOOLBAR, 
    &g_setting_NVIEW_HOTKEY_SHOW_RESTORE_WORKSPACE_STATE, 
    &g_setting_NVIEW_HOTKEY_SHOW_RUN_CONTROL_PANEL, 
    &g_setting_NVIEW_HOTKEY_SHOW_SAVEPROFILE, 
    &g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DESKTOP, 
    &g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_DISPLAY, 
    &g_setting_NVIEW_HOTKEY_SHOW_SEND_WINDOW_NEXTDISPLAY, 
    &g_setting_NVIEW_HOTKEY_SHOW_SHOWDESKNAME, 
    &g_setting_NVIEW_HOTKEY_SHOW_SYSTEMMENU, 
    &g_setting_NVIEW_HOTKEY_SHOW_TOGGLECLONE, 
    &g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_LCDSCALING, 
    &g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_OUTPUT, 
    &g_setting_NVIEW_HOTKEY_SHOW_TOGGLE_TRANSPARENCY, 
    &g_setting_NVIEW_HOTKEY_SHOW_ZOOMWINDOW, 
    &g_setting_NVIEW_HOTKEY_ZOOMTYPE, 
    &g_setting_NVIEW_PROFILE_CURRENT_PROFILE_NAME, 
    &g_setting_NVIEW_PROFILE_DELETE, 
    &g_setting_NVIEW_PROFILE_LOAD, 
    &g_setting_NVIEW_PROFILE_LOCK, 
    &g_setting_NVIEW_PROFILE_SAVE, 
    &g_setting_NVIEW_TAB_APPLICATION, 
    &g_setting_NVIEW_TAB_DESKTOP, 
    &g_setting_NVIEW_TAB_HOT_KEY, 
    &g_setting_NVIEW_TAB_PROFILE, 
    &g_setting_NVIEW_TAB_USERINTERFACE, 
    &g_setting_NVIEW_TAB_WINDOW, 
    &g_setting_NVIEW_TAB_ZOOM, 
};

bool AddSettingsToHashByPlainNameNVIEW(NvSettingsHash &settingsHash)
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
bool AddSettingsToHashByIdNVIEW(NvSettingsIdHash &settingsIdHash)
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

/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_DISPLAY_CLONE_GROUP_IDS = "DISPLAY_CLONE_GROUP_IDS";
static const char *g_pszDefinedWhen_DISPLAY_CLONE_GROUP_IDS = "1";
static const char *g_pszRemappedName_DISPLAY_CLONE_GROUP_IDS = "_";
static const char *g_pszMainDocs_DISPLAY_CLONE_GROUP_IDS = "Clone group IDs in a grid";

static const char * (g_ppszDefineDataNames_DISPLAY_CLONE_GROUP_IDS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_CLONE_GROUP_IDS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_CLONE_GROUP_IDS_NONE, L"" , "No clone group IDs" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_CLONE_GROUP_IDS[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_DISPLAY_CLONE_GROUP_IDS(
    0x5818a91d,
    g_pszKeyName_DISPLAY_CLONE_GROUP_IDS,
    g_pszRemappedName_DISPLAY_CLONE_GROUP_IDS,
    g_pszMainDocs_DISPLAY_CLONE_GROUP_IDS,
    g_pszDefinedWhen_DISPLAY_CLONE_GROUP_IDS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_CLONE_GROUP_IDS, 
    1, 
    g_aDefaultData_DISPLAY_CLONE_GROUP_IDS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_COLS = "DISPLAY_COLS";
static const char *g_pszDefinedWhen_DISPLAY_COLS = "1";
static const char *g_pszRemappedName_DISPLAY_COLS = "_";
static const char *g_pszMainDocs_DISPLAY_COLS = "Number of columns in a display grid";

static const char * (g_ppszDefineDataNames_DISPLAY_COLS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_COLS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_COLS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_COLS_MIN, 1 , "Min number of displays per dimension" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_COLS_MAX, 255 , "Max number of displays per dimension in SW (HW limits might be lower)" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_COLS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_DISPLAY_COLS(
    0x58e21bd4,
    g_pszKeyName_DISPLAY_COLS,
    g_pszRemappedName_DISPLAY_COLS,
    g_pszMainDocs_DISPLAY_COLS,
    g_pszDefinedWhen_DISPLAY_COLS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_COLS, 
    2, 
    g_aDefaultData_DISPLAY_COLS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_BRIGHTNESS = "DISPLAY_GRID_BRIGHTNESS";
static const char *g_pszDefinedWhen_DISPLAY_GRID_BRIGHTNESS = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_BRIGHTNESS = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_BRIGHTNESS = "Display grid relative brightness (in % of safe dynamic range)";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_NORMAL)[] =
{
    "NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_BRIGHTNESS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_MIN, 0x00000000 , "minimum brightness" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_NORMAL, 0x42480000 , "normal brightness" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_BRIGHTNESS_MAX, 0x42C80000 , "maximum brightness" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_BRIGHTNESS[] =
{
    {"DEFAULT", 0x42480000, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_BRIGHTNESS(
    0x5888f014,
    g_pszKeyName_DISPLAY_GRID_BRIGHTNESS,
    g_pszRemappedName_DISPLAY_GRID_BRIGHTNESS,
    g_pszMainDocs_DISPLAY_GRID_BRIGHTNESS,
    g_pszDefinedWhen_DISPLAY_GRID_BRIGHTNESS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_GRID_BRIGHTNESS, 
    3, 
    g_aDefaultData_DISPLAY_GRID_BRIGHTNESS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_CONTRAST = "DISPLAY_GRID_CONTRAST";
static const char *g_pszDefinedWhen_DISPLAY_GRID_CONTRAST = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_CONTRAST = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_CONTRAST = "Display grid relative contrast (in % of safe dynamic range)";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_NORMAL)[] =
{
    "NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_CONTRAST[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_MIN, 0x00000000 , "minimum contrast" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_NORMAL, 0x42480000 , "normal brightness" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_CONTRAST_MAX, 0x42C80000 , "maximum brightness" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_CONTRAST[] =
{
    {"DEFAULT", 0x42480000, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_CONTRAST(
    0x5899d709,
    g_pszKeyName_DISPLAY_GRID_CONTRAST,
    g_pszRemappedName_DISPLAY_GRID_CONTRAST,
    g_pszMainDocs_DISPLAY_GRID_CONTRAST,
    g_pszDefinedWhen_DISPLAY_GRID_CONTRAST,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_GRID_CONTRAST, 
    3, 
    g_aDefaultData_DISPLAY_GRID_CONTRAST, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_CSC = "DISPLAY_GRID_CSC";
static const char *g_pszDefinedWhen_DISPLAY_GRID_CSC = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_CSC = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_CSC = "File path to Color Space Conversion data for a display grid";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_CSC_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_GRID_CSC[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_CSC_NONE, L"" , "default" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_GRID_CSC[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_DISPLAY_GRID_CSC(
    0x5822d5ee,
    g_pszKeyName_DISPLAY_GRID_CSC,
    g_pszRemappedName_DISPLAY_GRID_CSC,
    g_pszMainDocs_DISPLAY_GRID_CSC,
    g_pszDefinedWhen_DISPLAY_GRID_CSC,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_GRID_CSC, 
    1, 
    g_aDefaultData_DISPLAY_GRID_CSC, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_GAMMA = "DISPLAY_GRID_GAMMA";
static const char *g_pszDefinedWhen_DISPLAY_GRID_GAMMA = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_GAMMA = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_GAMMA = "Display grid gamma";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_NORMAL)[] =
{
    "NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_GAMMA[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_MIN, 0x3E99999A , "minimum gamma" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_NORMAL, 0x3f800000 , "normal gamma" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_MAX, 0x40333333 , "maximum gamma" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_GAMMA[] =
{
    {"DEFAULT", 0x3f800000, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_GAMMA(
    0x58f95c9b,
    g_pszKeyName_DISPLAY_GRID_GAMMA,
    g_pszRemappedName_DISPLAY_GRID_GAMMA,
    g_pszMainDocs_DISPLAY_GRID_GAMMA,
    g_pszDefinedWhen_DISPLAY_GRID_GAMMA,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_GRID_GAMMA, 
    3, 
    g_aDefaultData_DISPLAY_GRID_GAMMA, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_GAMMA_RAMP = "DISPLAY_GRID_GAMMA_RAMP";
static const char *g_pszDefinedWhen_DISPLAY_GRID_GAMMA_RAMP = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_GAMMA_RAMP = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_GAMMA_RAMP = "File path to Gamma Ramp data for a display grid";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_RAMP_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_GRID_GAMMA_RAMP[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_GAMMA_RAMP_NONE, L"" , "default" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_GRID_GAMMA_RAMP[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_DISPLAY_GRID_GAMMA_RAMP(
    0x58d3388f,
    g_pszKeyName_DISPLAY_GRID_GAMMA_RAMP,
    g_pszRemappedName_DISPLAY_GRID_GAMMA_RAMP,
    g_pszMainDocs_DISPLAY_GRID_GAMMA_RAMP,
    g_pszDefinedWhen_DISPLAY_GRID_GAMMA_RAMP,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_GRID_GAMMA_RAMP, 
    1, 
    g_aDefaultData_DISPLAY_GRID_GAMMA_RAMP, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_POS_COL = "DISPLAY_GRID_POS_COL";
static const char *g_pszDefinedWhen_DISPLAY_GRID_POS_COL = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_POS_COL = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_POS_COL = "Display Grid GDI column position(in pixels)";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_POS_COL_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_POS_COL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_POS_COL[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_POS_COL_MIN, 0 , "Minimal offset in pixels" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_POS_COL_MAX, 100000 , "Maximal offset in pixels" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_POS_COL[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_POS_COL(
    0x58ba728b,
    g_pszKeyName_DISPLAY_GRID_POS_COL,
    g_pszRemappedName_DISPLAY_GRID_POS_COL,
    g_pszMainDocs_DISPLAY_GRID_POS_COL,
    g_pszDefinedWhen_DISPLAY_GRID_POS_COL,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_GRID_POS_COL, 
    2, 
    g_aDefaultData_DISPLAY_GRID_POS_COL, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_POS_ROW = "DISPLAY_GRID_POS_ROW";
static const char *g_pszDefinedWhen_DISPLAY_GRID_POS_ROW = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_POS_ROW = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_POS_ROW = "Display Grid GDI row position(in pixels)";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_POS_ROW_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_POS_ROW_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_POS_ROW[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_POS_ROW_MIN, 0 , "Minimal offset in pixels" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_POS_ROW_MAX, 100000 , "Maximal offset in pixels" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_POS_ROW[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_POS_ROW(
    0x584b70fe,
    g_pszKeyName_DISPLAY_GRID_POS_ROW,
    g_pszRemappedName_DISPLAY_GRID_POS_ROW,
    g_pszMainDocs_DISPLAY_GRID_POS_ROW,
    g_pszDefinedWhen_DISPLAY_GRID_POS_ROW,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_GRID_POS_ROW, 
    2, 
    g_aDefaultData_DISPLAY_GRID_POS_ROW, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_ROTATION = "DISPLAY_GRID_ROTATION";
static const char *g_pszDefinedWhen_DISPLAY_GRID_ROTATION = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_ROTATION = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_ROTATION = "Display grid rotation";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_0)[] =
{
    "ROTATE_0",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_90)[] =
{
    "ROTATE_90",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_180)[] =
{
    "ROTATE_180",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_270)[] =
{
    "ROTATE_270",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_IGNORED)[] =
{
    "ROTATE_IGNORED",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_ROTATION[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_0, 0 , "0 degrees" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_90, 1 , "90 degrees" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_180, 2 , "180 degrees" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_270, 3 , "270 degrees" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_ROTATION_ROTATE_IGNORED, 4 , "ignored" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_ROTATION[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_ROTATION(
    0x589fe89a,
    g_pszKeyName_DISPLAY_GRID_ROTATION,
    g_pszRemappedName_DISPLAY_GRID_ROTATION,
    g_pszMainDocs_DISPLAY_GRID_ROTATION,
    g_pszDefinedWhen_DISPLAY_GRID_ROTATION,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_GRID_ROTATION, 
    5, 
    g_aDefaultData_DISPLAY_GRID_ROTATION, 
    1 
);

static const char *g_pszKeyName_DISPLAY_GRID_SCALING = "DISPLAY_GRID_SCALING";
static const char *g_pszDefinedWhen_DISPLAY_GRID_SCALING = "1";
static const char *g_pszRemappedName_DISPLAY_GRID_SCALING = "_";
static const char *g_pszMainDocs_DISPLAY_GRID_SCALING = "Display grid scaling mode";

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_CLOSEST)[] =
{
    "SCALING_TO_CLOSEST",
    "SCALING_MONITOR_SCALING",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_NATIVE)[] =
{
    "SCALING_TO_NATIVE",
    "SCALING_ADAPTER_SCALING",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCANOUT_TO_NATIVE)[] =
{
    "SCANOUT_TO_NATIVE",
    "SCALING_CENTERED",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE)[] =
{
    "SCALING_TO_ASPECT_SCANOUT_TO_NATIVE",
    "SCALING_ASPECT_SCALING",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_CLOSEST)[] =
{
    "SCALING_TO_ASPECT_SCANOUT_TO_CLOSEST",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCANOUT_TO_CLOSEST)[] =
{
    "SCANOUT_TO_CLOSEST",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_GRID_SCALING[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_CLOSEST, 1 , "Balanced  - Full Screen" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_NATIVE, 2 , "Force GPU - Full Screen" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCANOUT_TO_NATIVE, 3 , "Force GPU - Centered, No Scaling" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE, 5 , "Force GPU - Aspect Ratio" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_CLOSEST, 6 , "Balanced  - Aspect Ratio" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_GRID_SCALING_SCANOUT_TO_CLOSEST, 7 , "Balanced  - Centered, No Scaling" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_GRID_SCALING[] =
{
    {"DEFAULT", 5, "" }, 
};

SettingDWORD g_setting_DISPLAY_GRID_SCALING(
    0x58d4b0b4,
    g_pszKeyName_DISPLAY_GRID_SCALING,
    g_pszRemappedName_DISPLAY_GRID_SCALING,
    g_pszMainDocs_DISPLAY_GRID_SCALING,
    g_pszDefinedWhen_DISPLAY_GRID_SCALING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_GRID_SCALING, 
    6, 
    g_aDefaultData_DISPLAY_GRID_SCALING, 
    1 
);

static const char *g_pszKeyName_DISPLAY_IDS = "DISPLAY_IDS";
static const char *g_pszDefinedWhen_DISPLAY_IDS = "1";
static const char *g_pszRemappedName_DISPLAY_IDS = "_";
static const char *g_pszMainDocs_DISPLAY_IDS = "Display IDs in a grid";

static const char * (g_ppszDefineDataNames_DISPLAY_IDS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_IDS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_IDS_NONE, L"" , "No display IDs" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_IDS[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_DISPLAY_IDS(
    0x58b21e43,
    g_pszKeyName_DISPLAY_IDS,
    g_pszRemappedName_DISPLAY_IDS,
    g_pszMainDocs_DISPLAY_IDS,
    g_pszDefinedWhen_DISPLAY_IDS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_IDS, 
    1, 
    g_aDefaultData_DISPLAY_IDS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_MODE = "DISPLAY_MODE";
static const char *g_pszDefinedWhen_DISPLAY_MODE = "1";
static const char *g_pszRemappedName_DISPLAY_MODE = "_";
static const char *g_pszMainDocs_DISPLAY_MODE = "Mode of a display grid";

static const char * (g_ppszDefineDataNames_DISPLAY_MODE_NATIVE)[] =
{
    "NATIVE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_MODE_NATIVE, L"native" , "native display mode (recommended)" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_MODE[] =
{
    {"DEFAULT", L"native", "" }, 
};

SettingWSTRING g_setting_DISPLAY_MODE(
    0x58c7b07c,
    g_pszKeyName_DISPLAY_MODE,
    g_pszRemappedName_DISPLAY_MODE,
    g_pszMainDocs_DISPLAY_MODE,
    g_pszDefinedWhen_DISPLAY_MODE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_MODE, 
    1, 
    g_aDefaultData_DISPLAY_MODE, 
    1 
);

static const char *g_pszKeyName_DISPLAY_POS_COLS = "DISPLAY_POS_COLS";
static const char *g_pszDefinedWhen_DISPLAY_POS_COLS = "1";
static const char *g_pszRemappedName_DISPLAY_POS_COLS = "_";
static const char *g_pszMainDocs_DISPLAY_POS_COLS = "Display positions in columns of display grid (in pixels)";

static const char * (g_ppszDefineDataNames_DISPLAY_POS_COLS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_POS_COLS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_POS_COLS_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_POS_COLS[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_DISPLAY_POS_COLS(
    0x586748c2,
    g_pszKeyName_DISPLAY_POS_COLS,
    g_pszRemappedName_DISPLAY_POS_COLS,
    g_pszMainDocs_DISPLAY_POS_COLS,
    g_pszDefinedWhen_DISPLAY_POS_COLS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_POS_COLS, 
    1, 
    g_aDefaultData_DISPLAY_POS_COLS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_POS_ROWS = "DISPLAY_POS_ROWS";
static const char *g_pszDefinedWhen_DISPLAY_POS_ROWS = "1";
static const char *g_pszRemappedName_DISPLAY_POS_ROWS = "_";
static const char *g_pszMainDocs_DISPLAY_POS_ROWS = "Display positions in rows of display grid (in pixels)";

static const char * (g_ppszDefineDataNames_DISPLAY_POS_ROWS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_POS_ROWS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_POS_ROWS_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_POS_ROWS[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_DISPLAY_POS_ROWS(
    0x5879ddc6,
    g_pszKeyName_DISPLAY_POS_ROWS,
    g_pszRemappedName_DISPLAY_POS_ROWS,
    g_pszMainDocs_DISPLAY_POS_ROWS,
    g_pszDefinedWhen_DISPLAY_POS_ROWS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_POS_ROWS, 
    1, 
    g_aDefaultData_DISPLAY_POS_ROWS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_ROTATION = "DISPLAY_ROTATION";
static const char *g_pszDefinedWhen_DISPLAY_ROTATION = "1";
static const char *g_pszRemappedName_DISPLAY_ROTATION = "_";
static const char *g_pszMainDocs_DISPLAY_ROTATION = "Per-display rotation";

static const char * (g_ppszDefineDataNames_DISPLAY_ROTATION_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_ROTATION[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_ROTATION_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_ROTATION[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_DISPLAY_ROTATION(
    0x58decfa8,
    g_pszKeyName_DISPLAY_ROTATION,
    g_pszRemappedName_DISPLAY_ROTATION,
    g_pszMainDocs_DISPLAY_ROTATION,
    g_pszDefinedWhen_DISPLAY_ROTATION,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_ROTATION, 
    1, 
    g_aDefaultData_DISPLAY_ROTATION, 
    1 
);

static const char *g_pszKeyName_DISPLAY_ROWS = "DISPLAY_ROWS";
static const char *g_pszDefinedWhen_DISPLAY_ROWS = "1";
static const char *g_pszRemappedName_DISPLAY_ROWS = "_";
static const char *g_pszMainDocs_DISPLAY_ROWS = "Number of rows in a display grid";

static const char * (g_ppszDefineDataNames_DISPLAY_ROWS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_ROWS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_ROWS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_ROWS_MIN, 1 , "Min number of displays per dimension" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_ROWS_MAX, 255 , "Max number of displays per dimension in SW (HW limits might be lower)" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_ROWS[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_DISPLAY_ROWS(
    0x5822918d,
    g_pszKeyName_DISPLAY_ROWS,
    g_pszRemappedName_DISPLAY_ROWS,
    g_pszMainDocs_DISPLAY_ROWS,
    g_pszDefinedWhen_DISPLAY_ROWS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_DISPLAY_ROWS, 
    2, 
    g_aDefaultData_DISPLAY_ROWS, 
    1 
);

static const char *g_pszKeyName_DISPLAY_SCALING = "DISPLAY_SCALING";
static const char *g_pszDefinedWhen_DISPLAY_SCALING = "1";
static const char *g_pszRemappedName_DISPLAY_SCALING = "_";
static const char *g_pszMainDocs_DISPLAY_SCALING = "Per-display scaling mode";

static const char * (g_ppszDefineDataNames_DISPLAY_SCALING_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_DISPLAY_SCALING[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_SCALING_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_DISPLAY_SCALING[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_DISPLAY_SCALING(
    0x587b0428,
    g_pszKeyName_DISPLAY_SCALING,
    g_pszRemappedName_DISPLAY_SCALING,
    g_pszMainDocs_DISPLAY_SCALING,
    g_pszDefinedWhen_DISPLAY_SCALING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_SCALING, 
    1, 
    g_aDefaultData_DISPLAY_SCALING, 
    1 
);

static const char *g_pszKeyName_OVERLAP_COLS = "OVERLAP_COLS";
static const char *g_pszDefinedWhen_OVERLAP_COLS = "1";
static const char *g_pszRemappedName_OVERLAP_COLS = "_";
static const char *g_pszMainDocs_OVERLAP_COLS = "Distance between displays per column. Positive number indicates overlap, negative - gap (in pixels)";

static const char * (g_ppszDefineDataNames_OVERLAP_COLS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_OVERLAP_COLS[] =
{
    { (const char **)g_ppszDefineDataNames_OVERLAP_COLS_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_OVERLAP_COLS[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_OVERLAP_COLS(
    0x58eb619d,
    g_pszKeyName_OVERLAP_COLS,
    g_pszRemappedName_OVERLAP_COLS,
    g_pszMainDocs_OVERLAP_COLS,
    g_pszDefinedWhen_OVERLAP_COLS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_OVERLAP_COLS, 
    1, 
    g_aDefaultData_OVERLAP_COLS, 
    1 
);

static const char *g_pszKeyName_OVERLAP_ROWS = "OVERLAP_ROWS";
static const char *g_pszDefinedWhen_OVERLAP_ROWS = "1";
static const char *g_pszRemappedName_OVERLAP_ROWS = "_";
static const char *g_pszMainDocs_OVERLAP_ROWS = "Distance between displays per row. Positive number indicates overlap, negative - gap (in pixels)";

static const char * (g_ppszDefineDataNames_OVERLAP_ROWS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_OVERLAP_ROWS[] =
{
    { (const char **)g_ppszDefineDataNames_OVERLAP_ROWS_NONE, L"0" , "None" },
};

DataDefaultWSTRING g_aDefaultData_OVERLAP_ROWS[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_OVERLAP_ROWS(
    0x58dd36c1,
    g_pszKeyName_OVERLAP_ROWS,
    g_pszRemappedName_OVERLAP_ROWS,
    g_pszMainDocs_OVERLAP_ROWS,
    g_pszDefinedWhen_OVERLAP_ROWS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_OVERLAP_ROWS, 
    1, 
    g_aDefaultData_OVERLAP_ROWS, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_DISPLAY_CLONE_GROUP_IDS, 
    &g_setting_DISPLAY_COLS, 
    &g_setting_DISPLAY_GRID_BRIGHTNESS, 
    &g_setting_DISPLAY_GRID_CONTRAST, 
    &g_setting_DISPLAY_GRID_CSC, 
    &g_setting_DISPLAY_GRID_GAMMA, 
    &g_setting_DISPLAY_GRID_GAMMA_RAMP, 
    &g_setting_DISPLAY_GRID_POS_COL, 
    &g_setting_DISPLAY_GRID_POS_ROW, 
    &g_setting_DISPLAY_GRID_ROTATION, 
    &g_setting_DISPLAY_GRID_SCALING, 
    &g_setting_DISPLAY_IDS, 
    &g_setting_DISPLAY_MODE, 
    &g_setting_DISPLAY_POS_COLS, 
    &g_setting_DISPLAY_POS_ROWS, 
    &g_setting_DISPLAY_ROTATION, 
    &g_setting_DISPLAY_ROWS, 
    &g_setting_DISPLAY_SCALING, 
    &g_setting_OVERLAP_COLS, 
    &g_setting_OVERLAP_ROWS, 
};

bool AddSettingsToHashByPlainNameDISP(NvSettingsHash &settingsHash)
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
bool AddSettingsToHashByIdDISP(NvSettingsIdHash &settingsIdHash)
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

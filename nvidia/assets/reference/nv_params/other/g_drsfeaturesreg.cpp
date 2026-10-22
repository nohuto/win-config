/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_NVDRS_FEATURE_AA = "NVDRS_FEATURE_AA";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_AA = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_AA = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_AA = "Antialiasing - Setting";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_OVERRIDE_AS_APP_CONTROLLED)[] =
{
    "TREAT_OVERRIDE_AS_APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_OVERRIDE_AS_ENHANCE)[] =
{
    "TREAT_OVERRIDE_AS_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_OVERRIDE)[] =
{
    "DISABLE_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_ENHANCE_AS_APP_CONTROLLED)[] =
{
    "TREAT_ENHANCE_AS_APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_ENHANCE_AS_OVERRIDE)[] =
{
    "TREAT_ENHANCE_AS_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_ENHANCE)[] =
{
    "DISABLE_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MAP_VCAA_TO_MULTISAMPLING)[] =
{
    "MAP_VCAA_TO_MULTISAMPLING",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING)[] =
{
    "SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_CPLAA)[] =
{
    "DISABLE_CPLAA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_SKIP_RT_DIM_CHECK_FOR_ENHANCE)[] =
{
    "SKIP_RT_DIM_CHECK_FOR_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_SLIAA)[] =
{
    "DISABLE_SLIAA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_AA_RT_BPP_DIV_4)[] =
{
    "AA_RT_BPP_DIV_4",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_AA_RT_BPP_DIV_4_SHIFT)[] =
{
    "AA_RT_BPP_DIV_4_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_NON_AA_RT_BPP_DIV_4)[] =
{
    "NON_AA_RT_BPP_DIV_4",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_NON_AA_RT_BPP_DIV_4_SHIFT)[] =
{
    "NON_AA_RT_BPP_DIV_4_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_AA[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_OVERRIDE_AS_APP_CONTROLLED, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_OVERRIDE_AS_ENHANCE, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_OVERRIDE, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_ENHANCE_AS_APP_CONTROLLED, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_TREAT_ENHANCE_AS_OVERRIDE, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_ENHANCE, 0x0000000c , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MAP_VCAA_TO_MULTISAMPLING, 0x00010000 , "Map VCAA modes to their equivalent multisampling format" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING, 0x00020000 , "Disable transparency supersampling mode for SLI" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_CPLAA, 0x00040000 , "Disable CPL AA ,opengl only" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_SKIP_RT_DIM_CHECK_FOR_ENHANCE, 0x00080000 , "Don't check the render target dimensions when considering enhance mode" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_DISABLE_SLIAA, 0x00100000 , "Disable SLIAA" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_AA_RT_BPP_DIV_4, 0xf0000000 , "The number of bytes needed for AA render targets divided by 4 (not including the AA buffers themselves)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_AA_RT_BPP_DIV_4_SHIFT, 28 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_NON_AA_RT_BPP_DIV_4, 0x0f000000 , "The number of bytes needed for non-AA render targets divided by 4" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_NON_AA_RT_BPP_DIV_4_SHIFT, 24 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MASK, 0xff1f000f , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_AA[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_AA(
    0xa0100006,
    g_pszKeyName_NVDRS_FEATURE_AA,
    g_pszRemappedName_NVDRS_FEATURE_AA,
    g_pszMainDocs_NVDRS_FEATURE_AA,
    g_pszDefinedWhen_NVDRS_FEATURE_AA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_AA, 
    18, 
    g_aDefaultData_NVDRS_FEATURE_AA, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_AA_GAMMA_CORRECTION = "NVDRS_FEATURE_AA_GAMMA_CORRECTION";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_AA_GAMMA_CORRECTION = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_AA_GAMMA_CORRECTION = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_AA_GAMMA_CORRECTION = "Antialiasing - Gamma correction";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_ON_IF_FOS)[] =
{
    "ON_IF_FOS",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_ON_ALWAYS)[] =
{
    "ON_ALWAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT_TESLA)[] =
{
    "DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT_FERMI)[] =
{
    "DEFAULT_FERMI",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_AA_GAMMA_CORRECTION[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_MASK, 0x00000003 , "use gamma corrected AA mode when possible (2X diagonal and 4x only, at this time)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_ON_IF_FOS, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_ON_ALWAYS, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_MAX, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT, 0x00000005 , "OFF" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT_TESLA, 0x00000006 , "ON_ALWAYS" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_GAMMA_CORRECTION_DEFAULT_FERMI, 0x00000007 , "ON_ALWAYS" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_AA_GAMMA_CORRECTION[] =
{
    {"DEFAULT", 0x00000005, "Default" }, 
    {"DEFAULT_FERMI", 0x00000007, "Default Fermi" }, 
    {"DEFAULT_TESLA", 0x00000006, "Default Tesla" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_AA_GAMMA_CORRECTION(
    0xa0100004,
    g_pszKeyName_NVDRS_FEATURE_AA_GAMMA_CORRECTION,
    g_pszRemappedName_NVDRS_FEATURE_AA_GAMMA_CORRECTION,
    g_pszMainDocs_NVDRS_FEATURE_AA_GAMMA_CORRECTION,
    g_pszDefinedWhen_NVDRS_FEATURE_AA_GAMMA_CORRECTION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_AA_GAMMA_CORRECTION, 
    8, 
    g_aDefaultData_NVDRS_FEATURE_AA_GAMMA_CORRECTION, 
    3 
);

static const char *g_pszKeyName_NVDRS_FEATURE_AA_MODE_SELECTOR = "NVDRS_FEATURE_AA_MODE_SELECTOR";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_AA_MODE_SELECTOR = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_AA_MODE_SELECTOR = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_AA_MODE_SELECTOR = "Antialiasing - Mode";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_APP_CONTROL)[] =
{
    "APP_CONTROL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_OVERRIDE)[] =
{
    "OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_ENHANCE)[] =
{
    "ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_AA_MODE_SELECTOR[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_MASK, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_APP_CONTROL, 0x00000000 , "do what the app says" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_OVERRIDE, 0x00000001 , "override the app setting with what the user says (via CP/registry) for both enable and mode" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_ENHANCE, 0x00000002 , "enhance the app-specified mode (but not enable) with the CP mode" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_MODE_SELECTOR_MAX, 0x00000004 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_AA_MODE_SELECTOR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
    {"DEFAULT_FERMI", 0x00000000, "" }, 
    {"DEFAULT_TESLA", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_AA_MODE_SELECTOR(
    0xa0100005,
    g_pszKeyName_NVDRS_FEATURE_AA_MODE_SELECTOR,
    g_pszRemappedName_NVDRS_FEATURE_AA_MODE_SELECTOR,
    g_pszMainDocs_NVDRS_FEATURE_AA_MODE_SELECTOR,
    g_pszDefinedWhen_NVDRS_FEATURE_AA_MODE_SELECTOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_AA_MODE_SELECTOR, 
    5, 
    g_aDefaultData_NVDRS_FEATURE_AA_MODE_SELECTOR, 
    3 
);

static const char *g_pszKeyName_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY = "NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY = "Antialiasing - Transparency";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_MASK)[] =
{
    "SAMPLES_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_ONE)[] =
{
    "SAMPLES_ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_TWO)[] =
{
    "SAMPLES_TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_FOUR)[] =
{
    "SAMPLES_FOUR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_EIGHT)[] =
{
    "SAMPLES_EIGHT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_MAX)[] =
{
    "SAMPLES_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_MASK)[] =
{
    "MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_OFF)[] =
{
    "MODE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_ALPHA_TEST)[] =
{
    "MODE_ALPHA_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_PIXEL_KILL)[] =
{
    "MODE_PIXEL_KILL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_DYN_BRANCH)[] =
{
    "MODE_DYN_BRANCH",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_OPTIMAL)[] =
{
    "MODE_OPTIMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_ALL)[] =
{
    "MODE_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_MAX)[] =
{
    "MODE_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY)[] =
{
    "TRANSPARENCY",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_DISALLOW_TRAA)[] =
{
    "DISALLOW_TRAA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT)[] =
{
    "TRANSPARENCY_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT_TESLA)[] =
{
    "TRANSPARENCY_DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT_FERMI)[] =
{
    "TRANSPARENCY_DEFAULT_FERMI",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_MASK, 0x00000070 , "number of times to replay the geometry" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_ONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_TWO, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_FOUR, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_EIGHT, 0x00000030 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_SAMPLES_MAX, 0x00000030 , "Since Tesla has 8xMS" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_MASK, 0x0000000f , "convert alpha to coverage for D3D app" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_OFF, 0x00000000 , "disabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_ALPHA_TEST, 0x00000001 , "alpha tested primitives" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_PIXEL_KILL, 0x00000002 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_DYN_BRANCH, 0x00000004 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_OPTIMAL, 0x00000004 , "Optimal Replay mode" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_ALL, 0x00000008 , "all types" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MODE_MAX, 0x0000000f , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY, 0x00000023 , "the standard control-panel setting (REPLAY_MODE_ALPHA_TEST|REPLAY_MODE_PIXEL_KILL|REPLAY_SAMPLES_FOUR)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_DISALLOW_TRAA, 0x00000100 , "some apps do not work correctly with TRAA. Disallow it even if the user has created an app profile with it enabled." },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT_TESLA, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_TRANSPARENCY_DEFAULT_FERMI, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY_MASK, 0x0000017f , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY[] =
{
    {"DEFAULT", 0x00000000, "TRANSPARENCY_DEFAULT" }, 
    {"DEFAULT_FERMI", 0x00000000, "TRANSPARENCY_DEFAULT_FERMI" }, 
    {"DEFAULT_TESLA", 0x00000000, "TRANSPARENCY_DEFAULT_TESLA" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY(
    0xa0100007,
    g_pszKeyName_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY,
    g_pszRemappedName_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY,
    g_pszMainDocs_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY,
    g_pszDefinedWhen_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY, 
    20, 
    g_aDefaultData_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY, 
    3 
);

static const char *g_pszKeyName_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY = "NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY = "Override CPU frequency for ACE power Mode, can be set differently for each game";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY_NO_OVERRIDE)[] =
{
    "NO_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY_NO_OVERRIDE, 0xffffffff , "Do not over ride, disabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY_DEFAULT, 0x00000000 , "Default value for CPU frequency" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY(
    0xa02fa782,
    g_pszKeyName_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY,
    g_pszRemappedName_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY,
    g_pszMainDocs_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY,
    g_pszDefinedWhen_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_ANISO = "NVDRS_FEATURE_ANISO";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_ANISO = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_ANISO = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_ANISO = "Anisotropic Filtering";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_APP_CONTROL)[] =
{
    "APP_CONTROL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_2X)[] =
{
    "2X",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_4X)[] =
{
    "4X",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_8X)[] =
{
    "8X",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_16X)[] =
{
    "16X",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_ANISO[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_APP_CONTROL, 0x00100000 , "Application-controlled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OFF, 1 , "Off" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_2X, 2 , "2X" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_4X, 4 , "4X" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_8X, 8 , "8X" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_16X, 16 , "16X" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_MASK, 0x0000ffff , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_MAX, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_DEFAULT, 1 , "OFF" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_ANISO[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_ANISO(
    0xa0100002,
    g_pszKeyName_NVDRS_FEATURE_ANISO,
    g_pszRemappedName_NVDRS_FEATURE_ANISO,
    g_pszMainDocs_NVDRS_FEATURE_ANISO,
    g_pszDefinedWhen_NVDRS_FEATURE_ANISO,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_ANISO, 
    9, 
    g_aDefaultData_NVDRS_FEATURE_ANISO, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_ANISO_OPTS = "NVDRS_FEATURE_ANISO_OPTS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_ANISO_OPTS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_ANISO_OPTS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_ANISO_OPTS = "Texture filtering - Anisotropic filter optimization";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OPTS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OPTS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_ANISO_OPTS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OPTS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_OPTS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_ANISO_OPTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_ANISO_OPTS(
    0xa010001a,
    g_pszKeyName_NVDRS_FEATURE_ANISO_OPTS,
    g_pszRemappedName_NVDRS_FEATURE_ANISO_OPTS,
    g_pszMainDocs_NVDRS_FEATURE_ANISO_OPTS,
    g_pszDefinedWhen_NVDRS_FEATURE_ANISO_OPTS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_ANISO_OPTS, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_ANISO_OPTS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_ANISO_SAMPLE_OPS = "NVDRS_FEATURE_ANISO_SAMPLE_OPS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_ANISO_SAMPLE_OPS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_ANISO_SAMPLE_OPS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_ANISO_SAMPLE_OPS = "Texture filtering - Anisotropic sample optimization";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_SAMPLE_OPS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_SAMPLE_OPS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_ANISO_SAMPLE_OPS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_SAMPLE_OPS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_ANISO_SAMPLE_OPS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_ANISO_SAMPLE_OPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_ANISO_SAMPLE_OPS(
    0xa0100016,
    g_pszKeyName_NVDRS_FEATURE_ANISO_SAMPLE_OPS,
    g_pszRemappedName_NVDRS_FEATURE_ANISO_SAMPLE_OPS,
    g_pszMainDocs_NVDRS_FEATURE_ANISO_SAMPLE_OPS,
    g_pszDefinedWhen_NVDRS_FEATURE_ANISO_SAMPLE_OPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_ANISO_SAMPLE_OPS, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_ANISO_SAMPLE_OPS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_AO_MODE = "NVDRS_FEATURE_AO_MODE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_AO_MODE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_AO_MODE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_AO_MODE = "Ambient Occlusion";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_LOW)[] =
{
    "LOW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_MEDIUM)[] =
{
    "MEDIUM",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_HIGH)[] =
{
    "HIGH",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_NOT_SUPPORTED)[] =
{
    "NOT_SUPPORTED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_AO_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_LOW, 1 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_MEDIUM, 2 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_HIGH, 3 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_AO_MODE_NOT_SUPPORTED, -1 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_AO_MODE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_AO_MODE(
    0xa0100001,
    g_pszKeyName_NVDRS_FEATURE_AO_MODE,
    g_pszRemappedName_NVDRS_FEATURE_AO_MODE,
    g_pszMainDocs_NVDRS_FEATURE_AO_MODE,
    g_pszDefinedWhen_NVDRS_FEATURE_AO_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_AO_MODE, 
    5, 
    g_aDefaultData_NVDRS_FEATURE_AO_MODE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_BATTERY_BOOST = "NVDRS_FEATURE_BATTERY_BOOST";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_BATTERY_BOOST = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_BATTERY_BOOST = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_BATTERY_BOOST = "Battery Boost";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_OPTIMAL)[] =
{
    "OPTIMAL",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_BATTERY_BOOST[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_MAX, 0x000000ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_ENABLED, 0x10000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BATTERY_BOOST_OPTIMAL, 0x0000001e , "Optimal" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_BATTERY_BOOST[] =
{
    {"DEFAULT", 0x0000001e, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_BATTERY_BOOST(
    0xa0100020,
    g_pszKeyName_NVDRS_FEATURE_BATTERY_BOOST,
    g_pszRemappedName_NVDRS_FEATURE_BATTERY_BOOST,
    g_pszMainDocs_NVDRS_FEATURE_BATTERY_BOOST,
    g_pszDefinedWhen_NVDRS_FEATURE_BATTERY_BOOST,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_BATTERY_BOOST, 
    4, 
    g_aDefaultData_NVDRS_FEATURE_BATTERY_BOOST, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_BUFFER_FLIP_MODE = "NVDRS_FEATURE_BUFFER_FLIP_MODE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_BUFFER_FLIP_MODE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_BUFFER_FLIP_MODE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_BUFFER_FLIP_MODE = "Buffer-flipping Mode";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BUFFER_FLIP_MODE_ON)[] =
{
    "ON",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_BUFFER_FLIP_MODE_OFF)[] =
{
    "OFF",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_BUFFER_FLIP_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BUFFER_FLIP_MODE_ON, 1 , "Force Blit On" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_BUFFER_FLIP_MODE_OFF, 0 , "Force Blit Off" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_BUFFER_FLIP_MODE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_BUFFER_FLIP_MODE(
    0xa0100008,
    g_pszKeyName_NVDRS_FEATURE_BUFFER_FLIP_MODE,
    g_pszRemappedName_NVDRS_FEATURE_BUFFER_FLIP_MODE,
    g_pszMainDocs_NVDRS_FEATURE_BUFFER_FLIP_MODE,
    g_pszDefinedWhen_NVDRS_FEATURE_BUFFER_FLIP_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_BUFFER_FLIP_MODE, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_BUFFER_FLIP_MODE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS = "NVDRS_FEATURE_CUDA_EXCLUDED_GPUS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS = "CUDA  - GPUs";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS_NONE, L"none" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS[] =
{
    {"DEFAULT", L"none", "" }, 
};

SettingWSTRING g_setting_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS(
    0xa0100009,
    g_pszKeyName_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS,
    g_pszRemappedName_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS,
    g_pszMainDocs_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS,
    g_pszDefinedWhen_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS, 
    1, 
    g_aDefaultData_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_DISPLAY_STEREO_MODE = "NVDRS_FEATURE_DISPLAY_STEREO_MODE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_DISPLAY_STEREO_MODE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_DISPLAY_STEREO_MODE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_DISPLAY_STEREO_MODE = "Stereo - Display mode";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SHUTTER_GLASSES)[] =
{
    "SHUTTER_GLASSES",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_VERTICAL_INTERLACED)[] =
{
    "VERTICAL_INTERLACED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TWINVIEW)[] =
{
    "TWINVIEW",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO)[] =
{
    "NV17_SHUTTER_GLASSES_AUTO",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0)[] =
{
    "NV17_SHUTTER_GLASSES_DAC0",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1)[] =
{
    "NV17_SHUTTER_GLASSES_DAC1",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_COLOR_LINE)[] =
{
    "COLOR_LINE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_COLOR_INTERLEAVED)[] =
{
    "COLOR_INTERLEAVED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_ANAGLYPH)[] =
{
    "ANAGLYPH",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_HORIZONTAL_INTERLACED)[] =
{
    "HORIZONTAL_INTERLACED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SIDE_FIELD)[] =
{
    "SIDE_FIELD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SUB_FIELD)[] =
{
    "SUB_FIELD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_CHECKERBOARD)[] =
{
    "CHECKERBOARD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_INVERSE_CHECKERBOARD)[] =
{
    "INVERSE_CHECKERBOARD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TRIDELITY_SL)[] =
{
    "TRIDELITY_SL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TRIDELITY_MV)[] =
{
    "TRIDELITY_MV",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SEEFRONT)[] =
{
    "SEEFRONT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_STEREO_MIRROR)[] =
{
    "STEREO_MIRROR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_FRAME_SEQUENTIAL)[] =
{
    "FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_AUTODETECT_PASSIVE_MODE)[] =
{
    "AUTODETECT_PASSIVE_MODE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL)[] =
{
    "AEGIS_DT_FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL)[] =
{
    "OEM_EMITTER_FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_USE_HW_DEFAULT)[] =
{
    "USE_HW_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_DEFAULT_GL)[] =
{
    "DEFAULT_GL",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_DISPLAY_STEREO_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SHUTTER_GLASSES, 0 , "Active stereo mode frame interleaved shutter glasses via DDC adapter shutter glasses (ELSA Revelator)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_VERTICAL_INTERLACED, 1 , "Passive stereo mode vertical interlaced" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TWINVIEW, 2 , "Passive stereo mode clone mode" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO, 3 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN auto" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0, 4 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC0" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1, 5 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC1" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_COLOR_LINE, 6 , "Active stereo mode frame interleaved shutter glasses via blue line adapter (StereoGraphics)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_COLOR_INTERLEAVED, 7 , "Passive stereo mode color interleaved (Sharp 3D)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_ANAGLYPH, 8 , "Passive stereo mode colored anaglyph (left:red right:cyan(blue+green))" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_HORIZONTAL_INTERLACED, 9 , "Passive stereo mode horizontal interlaced (Arisawa/Hyundai/Zalman/Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SIDE_FIELD, 10 , "Passive stereo mode vertical subfield (Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SUB_FIELD, 11 , "Passive stereo mode horizontal subfield (Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_CHECKERBOARD, 12 , "Passive stereo mode checkerboard pattern (3D DLP)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_INVERSE_CHECKERBOARD, 13 , "Passive stereo mode inverse checkerboard pattern (3D DLP)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TRIDELITY_SL, 14 , "Passive stereo mode line-wise biased vertical interlaced (Tridelity SL/SV -> SingleView)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_TRIDELITY_MV, 15 , "Passive stereo mode slanted line-wise biased vertical interlaced 5 view (Tridelity MV -> MultiView)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_SEEFRONT, 16 , "Passive stereo mode using Seefront pattern (SeeFront)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_STEREO_MIRROR, 17 , "Passive stereo mode clone mode with right eye mirrored (Planar)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_FRAME_SEQUENTIAL, 18 , "Active stereo mode frame interleaved (NVIDIA 3D Vision)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_AUTODETECT_PASSIVE_MODE, 19 , "Passive stereo mode autodetected by monitor capabilities" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL, 20 , "Active stereo mode frame interleaved (NVIDIA AegisDT embedded emitter)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL, 21 , "Active stereo mode frame interleaved (GPIO connected OEM emitter)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_USE_HW_DEFAULT, 0xffffffff , "Select hardware default based on capabilities" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_DISPLAY_STEREO_MODE_DEFAULT_GL, 3 , "Default for Quadro: NV17_SHUTTER_GLASSES_AUTO" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_DISPLAY_STEREO_MODE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_DISPLAY_STEREO_MODE(
    0xa0100013,
    g_pszKeyName_NVDRS_FEATURE_DISPLAY_STEREO_MODE,
    g_pszRemappedName_NVDRS_FEATURE_DISPLAY_STEREO_MODE,
    g_pszMainDocs_NVDRS_FEATURE_DISPLAY_STEREO_MODE,
    g_pszDefinedWhen_NVDRS_FEATURE_DISPLAY_STEREO_MODE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_DISPLAY_STEREO_MODE, 
    24, 
    g_aDefaultData_NVDRS_FEATURE_DISPLAY_STEREO_MODE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_FXAA = "NVDRS_FEATURE_FXAA";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_FXAA = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_FXAA = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_FXAA = "Antialiasing - FXAA";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_FXAA_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_FXAA_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_FXAA[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_FXAA_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_FXAA_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_FXAA[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_FXAA(
    0xa0100003,
    g_pszKeyName_NVDRS_FEATURE_FXAA,
    g_pszRemappedName_NVDRS_FEATURE_FXAA,
    g_pszMainDocs_NVDRS_FEATURE_FXAA,
    g_pszDefinedWhen_NVDRS_FEATURE_FXAA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_FXAA, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_FXAA, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_GAMESTREAM_FRAMECAP = "NVDRS_FEATURE_GAMESTREAM_FRAMECAP";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_GAMESTREAM_FRAMECAP = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_GAMESTREAM_FRAMECAP = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_GAMESTREAM_FRAMECAP = "Game stream frame capping";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_20)[] =
{
    "FPS_20",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_30)[] =
{
    "FPS_30",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_40)[] =
{
    "FPS_40",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPSMASK)[] =
{
    "FPSMASK",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FRL2)[] =
{
    "FRL2",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_LOWER_FPS_TO_ALIGN)[] =
{
    "LOWER_FPS_TO_ALIGN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FORCE_VSYNC_OFF)[] =
{
    "FORCE_VSYNC_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_GPS_WEB)[] =
{
    "GPS_WEB",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_DISALLOWED)[] =
{
    "DISALLOWED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_USE_CPU_WAIT)[] =
{
    "USE_CPU_WAIT",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_NO_LAG_OFFSET)[] =
{
    "NO_LAG_OFFSET",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ACCURATE)[] =
{
    "ACCURATE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ALLOW_WINDOWED)[] =
{
    "ALLOW_WINDOWED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FORCEON)[] =
{
    "FORCEON",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_OPENGL_REMOTE_DESKTOP)[] =
{
    "OPENGL_REMOTE_DESKTOP",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_GAMESTREAM_FRAMECAP[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_20, 0x00000014 , "Framerate set to 20 frames per sec" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_30, 0x0000001e , "Framerate set to 30 frames per sec" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPS_40, 0x00000028 , "Framerate set to 40 frames per sec" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FPSMASK, 0x000000ff , "Frames per sec mask" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FRL2, 0x00010000 , "Enable a new FRL (v2) design on supported configurations" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_LOWER_FPS_TO_ALIGN, 0x00020000 , "Lower FPS to align with refresh for windowed or FS VSYNC ON case." },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FORCE_VSYNC_OFF, 0x00040000 , "Force VSYNC OFF if this bit is set." },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_GPS_WEB, 0x00080000 , "GPS WEB controller enabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_DISALLOWED, 0x00200000 , "Per app disable bit" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_USE_CPU_WAIT, 0x00400000 , "CPU wait instead of GPU wait (VGX requires CPU)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_NO_LAG_OFFSET, 0x00800000 , "Do not apply offset to account for observed lag" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ACCURATE, 0x10000000 , "Accurate setting of fps but higer CPU usage" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ALLOW_WINDOWED, 0x20000000 , "Allow limiting of windowed applications" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_FORCEON, 0x40000000 , "Force enable, ignore AC/DC status" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_ENABLED, 0x80000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_OPENGL_REMOTE_DESKTOP, 0xe000003c , "Setting used for OpenGL Remote Desktop Sessions" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_GAMESTREAM_FRAMECAP_MASK, 0xf0ef00ff , "Mask of all bits used" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_GAMESTREAM_FRAMECAP[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_GAMESTREAM_FRAMECAP(
    0xa0100021,
    g_pszKeyName_NVDRS_FEATURE_GAMESTREAM_FRAMECAP,
    g_pszRemappedName_NVDRS_FEATURE_GAMESTREAM_FRAMECAP,
    g_pszMainDocs_NVDRS_FEATURE_GAMESTREAM_FRAMECAP,
    g_pszDefinedWhen_NVDRS_FEATURE_GAMESTREAM_FRAMECAP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_GAMESTREAM_FRAMECAP, 
    18, 
    g_aDefaultData_NVDRS_FEATURE_GAMESTREAM_FRAMECAP, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_HW_ACCEL_MULTIMON = "NVDRS_FEATURE_HW_ACCEL_MULTIMON";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_HW_ACCEL_MULTIMON = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_HW_ACCEL_MULTIMON = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_HW_ACCEL_MULTIMON = "Multi-display/mixed-GPU acceleration";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_SINGLE_MONITOR)[] =
{
    "SINGLE_MONITOR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_COMPATIBILITY_LCD)[] =
{
    "COMPATIBILITY_LCD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_COMPATIBILITY_GCD)[] =
{
    "COMPATIBILITY_GCD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_LCD)[] =
{
    "PERFORMANCE_LCD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_GCD)[] =
{
    "PERFORMANCE_GCD",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_EXTENDED_SINGLE_MONITOR)[] =
{
    "EXTENDED_SINGLE_MONITOR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_QUADRO)[] =
{
    "PERFORMANCE_QUADRO",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_MULTIMON_BUFFER)[] =
{
    "MULTIMON_BUFFER",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_HW_ACCEL_MULTIMON[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_SINGLE_MONITOR, 0 , "Single monitor" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_COMPATIBILITY_LCD, 1 , "Compatibility mode, lowest common denominator" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_COMPATIBILITY_GCD, 2 , "Compatibility mode, greatest common denominator" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_LCD, 3 , "Performance mode, lowest common denominator" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_GCD, 4 , "Performance mode, greatest common denominator" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_EXTENDED_SINGLE_MONITOR, 5 , "Extended single monitor" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_PERFORMANCE_QUADRO, 6 , "Performance mode, Quadro only" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_HW_ACCEL_MULTIMON_MULTIMON_BUFFER, 7 , "Multimon Buffer" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_HW_ACCEL_MULTIMON[] =
{
    {"DEFAULT", 3, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_HW_ACCEL_MULTIMON(
    0xa010000e,
    g_pszKeyName_NVDRS_FEATURE_HW_ACCEL_MULTIMON,
    g_pszRemappedName_NVDRS_FEATURE_HW_ACCEL_MULTIMON,
    g_pszMainDocs_NVDRS_FEATURE_HW_ACCEL_MULTIMON,
    g_pszDefinedWhen_NVDRS_FEATURE_HW_ACCEL_MULTIMON,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_HW_ACCEL_MULTIMON, 
    8, 
    g_aDefaultData_NVDRS_FEATURE_HW_ACCEL_MULTIMON, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_MFAA_INTERLEAVED = "NVDRS_FEATURE_MFAA_INTERLEAVED";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_MFAA_INTERLEAVED = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_MFAA_INTERLEAVED = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_MFAA_INTERLEAVED = "Multi-Frame Sampled AA (MFAA)";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_UNKNOWN)[] =
{
    "UNKNOWN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_OFF)[] =
{
    "OFF",
    "1",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_ON)[] =
{
    "ON",
    "2",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_MFAA_INTERLEAVED[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_UNKNOWN, 0 , "Unknown" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_OFF, 1 , "Off" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_MFAA_INTERLEAVED_ON, 2 , "On" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_MFAA_INTERLEAVED[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_MFAA_INTERLEAVED(
    0xa010000d,
    g_pszKeyName_NVDRS_FEATURE_MFAA_INTERLEAVED,
    g_pszRemappedName_NVDRS_FEATURE_MFAA_INTERLEAVED,
    g_pszMainDocs_NVDRS_FEATURE_MFAA_INTERLEAVED,
    g_pszDefinedWhen_NVDRS_FEATURE_MFAA_INTERLEAVED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_MFAA_INTERLEAVED, 
    3, 
    g_aDefaultData_NVDRS_FEATURE_MFAA_INTERLEAVED, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_NEG_LOD_BIAS = "NVDRS_FEATURE_NEG_LOD_BIAS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_NEG_LOD_BIAS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_NEG_LOD_BIAS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_NEG_LOD_BIAS = "Texture filtering - Negative LOD bias";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_NEG_LOD_BIAS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_NEG_LOD_BIAS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_NEG_LOD_BIAS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_NEG_LOD_BIAS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_NEG_LOD_BIAS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_NEG_LOD_BIAS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_NEG_LOD_BIAS(
    0xa0100017,
    g_pszKeyName_NVDRS_FEATURE_NEG_LOD_BIAS,
    g_pszRemappedName_NVDRS_FEATURE_NEG_LOD_BIAS,
    g_pszMainDocs_NVDRS_FEATURE_NEG_LOD_BIAS,
    g_pszDefinedWhen_NVDRS_FEATURE_NEG_LOD_BIAS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_NEG_LOD_BIAS, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_NEG_LOD_BIAS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_OPTIMAL_REFRESHRATE = "NVDRS_FEATURE_OPTIMAL_REFRESHRATE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_OPTIMAL_REFRESHRATE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_OPTIMAL_REFRESHRATE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_OPTIMAL_REFRESHRATE = "Optimal Refresh Rate";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OPTIMAL_REFRESHRATE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OPTIMAL_REFRESHRATE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_OPTIMAL_REFRESHRATE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OPTIMAL_REFRESHRATE_MIN, 0x00000000 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OPTIMAL_REFRESHRATE_MAX, 0x000000ff , "Maximum" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_OPTIMAL_REFRESHRATE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_OPTIMAL_REFRESHRATE(
    0xa010001f,
    g_pszKeyName_NVDRS_FEATURE_OPTIMAL_REFRESHRATE,
    g_pszRemappedName_NVDRS_FEATURE_OPTIMAL_REFRESHRATE,
    g_pszMainDocs_NVDRS_FEATURE_OPTIMAL_REFRESHRATE,
    g_pszDefinedWhen_NVDRS_FEATURE_OPTIMAL_REFRESHRATE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_OPTIMAL_REFRESHRATE, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_OPTIMAL_REFRESHRATE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE = "NVDRS_FEATURE_OVERLAY_PIXEL_TYPE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE = "Exported pixel types";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_CI)[] =
{
    "CI",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_RGBA)[] =
{
    "RGBA",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_CI_AND_RGBA)[] =
{
    "CI_AND_RGBA",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_NONE, 0x0 , "No OpenGL overlay support" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_CI, 0x1 , "Export LPD_TYPE_COLORINDEX only" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_RGBA, 0x2 , "Export LPD_TYPE_RGBA only" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE_CI_AND_RGBA, 0x3 , "Export both LPD_TYPE_COLORINDEX and LPD_TYPE_RGBA" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE(
    0xa010000b,
    g_pszKeyName_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE,
    g_pszRemappedName_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE,
    g_pszMainDocs_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE,
    g_pszDefinedWhen_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE, 
    4, 
    g_aDefaultData_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_OVERLAY_SUPPORT = "NVDRS_FEATURE_OVERLAY_SUPPORT";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_OVERLAY_SUPPORT = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_OVERLAY_SUPPORT = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_OVERLAY_SUPPORT = "Enable overlay";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_ON)[] =
{
    "ON",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_FORCE_SW)[] =
{
    "FORCE_SW",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_OVERLAY_SUPPORT[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_OFF, 0 , "Disable OpenGL overlay support" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_ON, 1 , "Use best possible overlay support" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_OVERLAY_SUPPORT_FORCE_SW, 2 , "Use software emulation ( mergeblit ) overlays" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_OVERLAY_SUPPORT[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_OVERLAY_SUPPORT(
    0xa010000a,
    g_pszKeyName_NVDRS_FEATURE_OVERLAY_SUPPORT,
    g_pszRemappedName_NVDRS_FEATURE_OVERLAY_SUPPORT,
    g_pszMainDocs_NVDRS_FEATURE_OVERLAY_SUPPORT,
    g_pszDefinedWhen_NVDRS_FEATURE_OVERLAY_SUPPORT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_OVERLAY_SUPPORT, 
    3, 
    g_aDefaultData_NVDRS_FEATURE_OVERLAY_SUPPORT, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_POWER_MGMT_MODE = "NVDRS_FEATURE_POWER_MGMT_MODE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_POWER_MGMT_MODE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_POWER_MGMT_MODE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_POWER_MGMT_MODE = "Power management mode";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_ADAPTIVE)[] =
{
    "ADAPTIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_MAX)[] =
{
    "PREFER_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_DRIVER_CONTROLLED)[] =
{
    "DRIVER_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_CONSISTENT_PERFORMANCE)[] =
{
    "PREFER_CONSISTENT_PERFORMANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_MIN)[] =
{
    "PREFER_MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_POWER_MGMT_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_ADAPTIVE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_MAX, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_DRIVER_CONTROLLED, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_CONSISTENT_PERFORMANCE, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_PREFER_MIN, 0x00000004 , "Currently Unsupported" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_POWER_MGMT_MODE_MAX, 0x00000004 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_POWER_MGMT_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
    {"DEFAULT_GL", 0x00000002, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_POWER_MGMT_MODE(
    0xa0100011,
    g_pszKeyName_NVDRS_FEATURE_POWER_MGMT_MODE,
    g_pszRemappedName_NVDRS_FEATURE_POWER_MGMT_MODE,
    g_pszMainDocs_NVDRS_FEATURE_POWER_MGMT_MODE,
    g_pszDefinedWhen_NVDRS_FEATURE_POWER_MGMT_MODE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_NVDRS_FEATURE_POWER_MGMT_MODE, 
    7, 
    g_aDefaultData_NVDRS_FEATURE_POWER_MGMT_MODE, 
    2 
);

static const char *g_pszKeyName_NVDRS_FEATURE_PREFERRED_OGL_GPU = "NVDRS_FEATURE_PREFERRED_OGL_GPU";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_PREFERRED_OGL_GPU = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_PREFERRED_OGL_GPU = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_PREFERRED_OGL_GPU = "OpenGL rendering GPU";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PREFERRED_OGL_GPU_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

DataValueWSTRING g_aDefineData_NVDRS_FEATURE_PREFERRED_OGL_GPU[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PREFERRED_OGL_GPU_AUTOSELECT, L"autoselect" , "" },
};

DataDefaultWSTRING g_aDefaultData_NVDRS_FEATURE_PREFERRED_OGL_GPU[] =
{
    {"DEFAULT", L"autoselect", "" }, 
};

SettingWSTRING g_setting_NVDRS_FEATURE_PREFERRED_OGL_GPU(
    0xa010000f,
    g_pszKeyName_NVDRS_FEATURE_PREFERRED_OGL_GPU,
    g_pszRemappedName_NVDRS_FEATURE_PREFERRED_OGL_GPU,
    g_pszMainDocs_NVDRS_FEATURE_PREFERRED_OGL_GPU,
    g_pszDefinedWhen_NVDRS_FEATURE_PREFERRED_OGL_GPU,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_PREFERRED_OGL_GPU, 
    1, 
    g_aDefaultData_NVDRS_FEATURE_PREFERRED_OGL_GPU, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_PRERENDER_LIMIT = "NVDRS_FEATURE_PRERENDER_LIMIT";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_PRERENDER_LIMIT = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_PRERENDER_LIMIT = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_PRERENDER_LIMIT = "Maximum pre-rendered frames";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_APP_CONTROLLED)[] =
{
    "APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_ONE)[] =
{
    "ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_TWO)[] =
{
    "TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_THREE)[] =
{
    "THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_FOUR)[] =
{
    "FOUR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_FIVE)[] =
{
    "FIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_SIX)[] =
{
    "SIX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_SEVEN)[] =
{
    "SEVEN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_EIGHT)[] =
{
    "EIGHT",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_PRERENDER_LIMIT[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_MIN, 0x00 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_MAX, 0xff , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_APP_CONTROLLED, 0x00 , "The present limit will be controlled by application or driver adjustments." },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_NONE, 0 , "None" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_ONE, 1 , "One" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_TWO, 2 , "Two" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_THREE, 3 , "Three" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_FOUR, 4 , "Four" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_FIVE, 5 , "Five" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_SIX, 6 , "Six" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_SEVEN, 7 , "Seven" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_PRERENDER_LIMIT_EIGHT, 8 , "Eight" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_PRERENDER_LIMIT[] =
{
    {"DEFAULT", 0x00, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_PRERENDER_LIMIT(
    0xa010000c,
    g_pszKeyName_NVDRS_FEATURE_PRERENDER_LIMIT,
    g_pszRemappedName_NVDRS_FEATURE_PRERENDER_LIMIT,
    g_pszMainDocs_NVDRS_FEATURE_PRERENDER_LIMIT,
    g_pszDefinedWhen_NVDRS_FEATURE_PRERENDER_LIMIT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_PRERENDER_LIMIT, 
    12, 
    g_aDefaultData_NVDRS_FEATURE_PRERENDER_LIMIT, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_QUALITY_ENHANCEMENTS = "NVDRS_FEATURE_QUALITY_ENHANCEMENTS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_QUALITY_ENHANCEMENTS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_QUALITY_ENHANCEMENTS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_QUALITY_ENHANCEMENTS = "Texture filtering - Quality";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_HIGHQUALITY)[] =
{
    "HIGHQUALITY",
    "HQ",
    "-a",
    "-0xa",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_QUALITY)[] =
{
    "QUALITY",
    "Q",
    "0",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_PERFORMANCE)[] =
{
    "PERFORMANCE",
    "P",
    "a",
    "0xa",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_HIGHPERFORMANCE)[] =
{
    "HIGHPERFORMANCE",
    "HP",
    "14",
    "0x14",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_QUALITY_ENHANCEMENTS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_HIGHQUALITY, 0xfffffff6 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_QUALITY, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_PERFORMANCE, 0x0000000a , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUALITY_ENHANCEMENTS_HIGHPERFORMANCE, 0x00000014 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_QUALITY_ENHANCEMENTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_QUALITY_ENHANCEMENTS(
    0xa0100018,
    g_pszKeyName_NVDRS_FEATURE_QUALITY_ENHANCEMENTS,
    g_pszRemappedName_NVDRS_FEATURE_QUALITY_ENHANCEMENTS,
    g_pszMainDocs_NVDRS_FEATURE_QUALITY_ENHANCEMENTS,
    g_pszDefinedWhen_NVDRS_FEATURE_QUALITY_ENHANCEMENTS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_QUALITY_ENHANCEMENTS, 
    4, 
    g_aDefaultData_NVDRS_FEATURE_QUALITY_ENHANCEMENTS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_QUIET_MODE = "NVDRS_FEATURE_QUIET_MODE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_QUIET_MODE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_QUIET_MODE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_QUIET_MODE = "Enables the Quiet Mode functionality, cap FPS for AC mode only";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_OPTIMAL)[] =
{
    "OPTIMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_QUIET_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_MAX, 0x000000ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_OPTIMAL, 0x0000003c , "Optimal" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_ENABLED, 0x10000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_QUIET_MODE_DISABLED, 0x00000000 , "Disabled" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_QUIET_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_QUIET_MODE(
    0xa0100022,
    g_pszKeyName_NVDRS_FEATURE_QUIET_MODE,
    g_pszRemappedName_NVDRS_FEATURE_QUIET_MODE,
    g_pszMainDocs_NVDRS_FEATURE_QUIET_MODE,
    g_pszDefinedWhen_NVDRS_FEATURE_QUIET_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_QUIET_MODE, 
    5, 
    g_aDefaultData_NVDRS_FEATURE_QUIET_MODE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_SHADER_DISK_CACHE = "NVDRS_FEATURE_SHADER_DISK_CACHE";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_SHADER_DISK_CACHE = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_SHADER_DISK_CACHE = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_SHADER_DISK_CACHE = "Shader Cache";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_SHADER_DISK_CACHE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_SHADER_DISK_CACHE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_SHADER_DISK_CACHE[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_SHADER_DISK_CACHE_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_SHADER_DISK_CACHE_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_SHADER_DISK_CACHE[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_SHADER_DISK_CACHE(
    0xa0100012,
    g_pszKeyName_NVDRS_FEATURE_SHADER_DISK_CACHE,
    g_pszRemappedName_NVDRS_FEATURE_SHADER_DISK_CACHE,
    g_pszMainDocs_NVDRS_FEATURE_SHADER_DISK_CACHE,
    g_pszDefinedWhen_NVDRS_FEATURE_SHADER_DISK_CACHE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_SHADER_DISK_CACHE, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_SHADER_DISK_CACHE, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_STEREO_EYES_SWAP = "NVDRS_FEATURE_STEREO_EYES_SWAP";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_STEREO_EYES_SWAP = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_STEREO_EYES_SWAP = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_STEREO_EYES_SWAP = "Stereo - Swap eyes";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_EYES_SWAP_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_EYES_SWAP_ON)[] =
{
    "ON",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_STEREO_EYES_SWAP[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_EYES_SWAP_OFF, 0 , "Stereo eyes exchange off" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_EYES_SWAP_ON, 1 , "Stereo eyes exchange on" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_STEREO_EYES_SWAP[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_STEREO_EYES_SWAP(
    0xa0100015,
    g_pszKeyName_NVDRS_FEATURE_STEREO_EYES_SWAP,
    g_pszRemappedName_NVDRS_FEATURE_STEREO_EYES_SWAP,
    g_pszMainDocs_NVDRS_FEATURE_STEREO_EYES_SWAP,
    g_pszDefinedWhen_NVDRS_FEATURE_STEREO_EYES_SWAP,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_STEREO_EYES_SWAP, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_STEREO_EYES_SWAP, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_STEREO_SUPPORT = "NVDRS_FEATURE_STEREO_SUPPORT";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_STEREO_SUPPORT = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_STEREO_SUPPORT = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_STEREO_SUPPORT = "Stereo - Enable";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_SUPPORT_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_SUPPORT_ON)[] =
{
    "ON",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_STEREO_SUPPORT[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_SUPPORT_OFF, 0 , "Disable API stereo support" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_STEREO_SUPPORT_ON, 1 , "Enable API stereo support" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_STEREO_SUPPORT[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_STEREO_SUPPORT(
    0xa0100014,
    g_pszKeyName_NVDRS_FEATURE_STEREO_SUPPORT,
    g_pszRemappedName_NVDRS_FEATURE_STEREO_SUPPORT,
    g_pszMainDocs_NVDRS_FEATURE_STEREO_SUPPORT,
    g_pszDefinedWhen_NVDRS_FEATURE_STEREO_SUPPORT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_STEREO_SUPPORT, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_STEREO_SUPPORT, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_THREAD_CONTROL = "NVDRS_FEATURE_THREAD_CONTROL";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_THREAD_CONTROL = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_THREAD_CONTROL = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_THREAD_CONTROL = "Threaded optimization";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_THREAD_CONTROL_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_THREAD_CONTROL_DISABLE)[] =
{
    "DISABLE",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_THREAD_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_THREAD_CONTROL_ENABLE, 0x00000001 , "Force Enables threading" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_THREAD_CONTROL_DISABLE, 0x00000002 , "Force Disable threading" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_THREAD_CONTROL[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_THREAD_CONTROL(
    0xa010001b,
    g_pszKeyName_NVDRS_FEATURE_THREAD_CONTROL,
    g_pszRemappedName_NVDRS_FEATURE_THREAD_CONTROL,
    g_pszMainDocs_NVDRS_FEATURE_THREAD_CONTROL,
    g_pszDefinedWhen_NVDRS_FEATURE_THREAD_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NVDRS_FEATURE_THREAD_CONTROL, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_THREAD_CONTROL, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_TRILINEAR_OPTS = "NVDRS_FEATURE_TRILINEAR_OPTS";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_TRILINEAR_OPTS = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_TRILINEAR_OPTS = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_TRILINEAR_OPTS = "Texture filtering - Trilinear optimization";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_TRILINEAR_OPTS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_TRILINEAR_OPTS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_TRILINEAR_OPTS[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_TRILINEAR_OPTS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_TRILINEAR_OPTS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_TRILINEAR_OPTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_TRILINEAR_OPTS(
    0xa0100019,
    g_pszKeyName_NVDRS_FEATURE_TRILINEAR_OPTS,
    g_pszRemappedName_NVDRS_FEATURE_TRILINEAR_OPTS,
    g_pszMainDocs_NVDRS_FEATURE_TRILINEAR_OPTS,
    g_pszDefinedWhen_NVDRS_FEATURE_TRILINEAR_OPTS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_TRILINEAR_OPTS, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_TRILINEAR_OPTS, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_TRIPPLE_BUFFERING = "NVDRS_FEATURE_TRIPPLE_BUFFERING";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_TRIPPLE_BUFFERING = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_TRIPPLE_BUFFERING = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_TRIPPLE_BUFFERING = "Triple buffering";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_TRIPPLE_BUFFERING_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_TRIPPLE_BUFFERING_ENABLED)[] =
{
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_TRIPPLE_BUFFERING[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_TRIPPLE_BUFFERING_DISABLED, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_TRIPPLE_BUFFERING_ENABLED, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_TRIPPLE_BUFFERING[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_TRIPPLE_BUFFERING(
    0xa010001c,
    g_pszKeyName_NVDRS_FEATURE_TRIPPLE_BUFFERING,
    g_pszRemappedName_NVDRS_FEATURE_TRIPPLE_BUFFERING,
    g_pszMainDocs_NVDRS_FEATURE_TRIPPLE_BUFFERING,
    g_pszDefinedWhen_NVDRS_FEATURE_TRIPPLE_BUFFERING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_TRIPPLE_BUFFERING, 
    2, 
    g_aDefaultData_NVDRS_FEATURE_TRIPPLE_BUFFERING, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_VRPRERENDER_LIMIT = "NVDRS_FEATURE_VRPRERENDER_LIMIT";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_VRPRERENDER_LIMIT = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_VRPRERENDER_LIMIT = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_VRPRERENDER_LIMIT = "Virtual Reality pre-rendered frames";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_APP_CONTROLLED)[] =
{
    "APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_ONE)[] =
{
    "ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_TWO)[] =
{
    "TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_THREE)[] =
{
    "THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_FOUR)[] =
{
    "FOUR",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_FIVE)[] =
{
    "FIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_SIX)[] =
{
    "SIX",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_SEVEN)[] =
{
    "SEVEN",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_EIGHT)[] =
{
    "EIGHT",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_VRPRERENDER_LIMIT[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_MIN, 0x00 , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_MAX, 0xff , "" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_APP_CONTROLLED, 0x00 , "The present limit will be controlled by application or driver adjustments." },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_NONE, 0 , "None" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_ONE, 1 , "One" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_TWO, 2 , "Two" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_THREE, 3 , "Three" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_FOUR, 4 , "Four" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_FIVE, 5 , "Five" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_SIX, 6 , "Six" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_SEVEN, 7 , "Seven" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VRPRERENDER_LIMIT_EIGHT, 8 , "Eight" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_VRPRERENDER_LIMIT[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_VRPRERENDER_LIMIT(
    0xa010001e,
    g_pszKeyName_NVDRS_FEATURE_VRPRERENDER_LIMIT,
    g_pszRemappedName_NVDRS_FEATURE_VRPRERENDER_LIMIT,
    g_pszMainDocs_NVDRS_FEATURE_VRPRERENDER_LIMIT,
    g_pszDefinedWhen_NVDRS_FEATURE_VRPRERENDER_LIMIT,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_NVDRS_FEATURE_VRPRERENDER_LIMIT, 
    12, 
    g_aDefaultData_NVDRS_FEATURE_VRPRERENDER_LIMIT, 
    1 
);

static const char *g_pszKeyName_NVDRS_FEATURE_VSYNC = "NVDRS_FEATURE_VSYNC";
static const char *g_pszDefinedWhen_NVDRS_FEATURE_VSYNC = "1";
static const char *g_pszRemappedName_NVDRS_FEATURE_VSYNC = "_";
static const char *g_pszMainDocs_NVDRS_FEATURE_VSYNC = "Vertical sync";

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_APPCONTROLLED)[] =
{
    "APPCONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEOFF)[] =
{
    "FORCEOFF",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEON)[] =
{
    "FORCEON",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEON_INTERVAL2)[] =
{
    "FORCEON_INTERVAL2",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_ADAPTIVE)[] =
{
    "ADAPTIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_ADAPTIVE_HALF_REFRESH_RATE)[] =
{
    "ADAPTIVE_HALF_REFRESH_RATE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_SMOOTH)[] =
{
    "SMOOTH",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_GSYNC_ENABLE)[] =
{
    "GSYNC_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_GSYNC_NOT_SUPPORTED)[] =
{
    "GSYNC_NOT_SUPPORTED",
    NULL
};

DataValueDWORD g_aDefineData_NVDRS_FEATURE_VSYNC[] =
{
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_APPCONTROLLED, 0 , "Use the 3D application setting" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEOFF, 1 , "Off" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEON, 2 , "On" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_FORCEON_INTERVAL2, 3 , "Force On (Interval 2)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_ADAPTIVE, 4 , "Adaptive" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_ADAPTIVE_HALF_REFRESH_RATE, 5 , "Adaptive (half refresh rate)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_SMOOTH, 6 , "On (smooth)" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_GSYNC_ENABLE, 7 , "G-SYNC" },
    { (const char **)g_ppszDefineDataNames_NVDRS_FEATURE_VSYNC_GSYNC_NOT_SUPPORTED, 8 , "G-SYNC not supported" },
};

DataDefaultDWORD g_aDefaultData_NVDRS_FEATURE_VSYNC[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NVDRS_FEATURE_VSYNC(
    0xa010001d,
    g_pszKeyName_NVDRS_FEATURE_VSYNC,
    g_pszRemappedName_NVDRS_FEATURE_VSYNC,
    g_pszMainDocs_NVDRS_FEATURE_VSYNC,
    g_pszDefinedWhen_NVDRS_FEATURE_VSYNC,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDRS_FEATURE_VSYNC, 
    9, 
    g_aDefaultData_NVDRS_FEATURE_VSYNC, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_NVDRS_FEATURE_AA, 
    &g_setting_NVDRS_FEATURE_AA_GAMMA_CORRECTION, 
    &g_setting_NVDRS_FEATURE_AA_MODE_SELECTOR, 
    &g_setting_NVDRS_FEATURE_AA_REPLAY_TRANSPARENCY, 
    &g_setting_NVDRS_FEATURE_ACE_POWERMODE_CPU_FREQUENCY, 
    &g_setting_NVDRS_FEATURE_ANISO, 
    &g_setting_NVDRS_FEATURE_ANISO_OPTS, 
    &g_setting_NVDRS_FEATURE_ANISO_SAMPLE_OPS, 
    &g_setting_NVDRS_FEATURE_AO_MODE, 
    &g_setting_NVDRS_FEATURE_BATTERY_BOOST, 
    &g_setting_NVDRS_FEATURE_BUFFER_FLIP_MODE, 
    &g_setting_NVDRS_FEATURE_CUDA_EXCLUDED_GPUS, 
    &g_setting_NVDRS_FEATURE_DISPLAY_STEREO_MODE, 
    &g_setting_NVDRS_FEATURE_FXAA, 
    &g_setting_NVDRS_FEATURE_GAMESTREAM_FRAMECAP, 
    &g_setting_NVDRS_FEATURE_HW_ACCEL_MULTIMON, 
    &g_setting_NVDRS_FEATURE_MFAA_INTERLEAVED, 
    &g_setting_NVDRS_FEATURE_NEG_LOD_BIAS, 
    &g_setting_NVDRS_FEATURE_OPTIMAL_REFRESHRATE, 
    &g_setting_NVDRS_FEATURE_OVERLAY_PIXEL_TYPE, 
    &g_setting_NVDRS_FEATURE_OVERLAY_SUPPORT, 
    &g_setting_NVDRS_FEATURE_POWER_MGMT_MODE, 
    &g_setting_NVDRS_FEATURE_PREFERRED_OGL_GPU, 
    &g_setting_NVDRS_FEATURE_PRERENDER_LIMIT, 
    &g_setting_NVDRS_FEATURE_QUALITY_ENHANCEMENTS, 
    &g_setting_NVDRS_FEATURE_QUIET_MODE, 
    &g_setting_NVDRS_FEATURE_SHADER_DISK_CACHE, 
    &g_setting_NVDRS_FEATURE_STEREO_EYES_SWAP, 
    &g_setting_NVDRS_FEATURE_STEREO_SUPPORT, 
    &g_setting_NVDRS_FEATURE_THREAD_CONTROL, 
    &g_setting_NVDRS_FEATURE_TRILINEAR_OPTS, 
    &g_setting_NVDRS_FEATURE_TRIPPLE_BUFFERING, 
    &g_setting_NVDRS_FEATURE_VRPRERENDER_LIMIT, 
    &g_setting_NVDRS_FEATURE_VSYNC, 
};

bool AddSettingsToHashByPlainNameDRSFEATURES(NvSettingsHash &settingsHash)
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
bool AddSettingsToHashByIdDRSFEATURES(NvSettingsIdHash &settingsIdHash)
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

/* 
* This is an automatically generated file. Do not edit it manually. 
* Changes in this file are tied to the corresponding RKY file. 
*/

#include <stdio.h>
#include <assert.h>
#include "nvtypes.h"
#include "NvRkySetting.h"
#include "NvRkySettingsHash.h"

static const char *g_pszKeyName_AAMODE = "AAMODE";
static const char *g_pszDefinedWhen_AAMODE = "1";
static const char *g_pszRemappedName_AAMODE = "D3DOGL_70835937";
static const char *g_pszMainDocs_AAMODE = "";

static const char * (g_ppszDefineDataNames_AAMODE_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_2X_H)[] =
{
    "SUPERSAMPLE_2X_H",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_2X_V)[] =
{
    "SUPERSAMPLE_2X_V",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_1_5X1_5)[] =
{
    "SUPERSAMPLE_1_5X1_5",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x03)[] =
{
    "FREE_0x03",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x04)[] =
{
    "FREE_0x04",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X)[] =
{
    "SUPERSAMPLE_4X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_BIAS)[] =
{
    "SUPERSAMPLE_4X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_GAUSSIAN)[] =
{
    "SUPERSAMPLE_4X_GAUSSIAN",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x08)[] =
{
    "FREE_0x08",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x09)[] =
{
    "FREE_0x09",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_9X)[] =
{
    "SUPERSAMPLE_9X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_9X_BIAS)[] =
{
    "SUPERSAMPLE_9X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_16X)[] =
{
    "SUPERSAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_16X_BIAS)[] =
{
    "SUPERSAMPLE_16X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL)[] =
{
    "MULTISAMPLE_2X_DIAGONAL",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_QUINCUNX)[] =
{
    "MULTISAMPLE_2X_QUINCUNX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X)[] =
{
    "MULTISAMPLE_4X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x11)[] =
{
    "FREE_0x11",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_GAUSSIAN)[] =
{
    "MULTISAMPLE_4X_GAUSSIAN",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_4X_SKEWED_4TAP)[] =
{
    "MIXEDSAMPLE_4X_SKEWED_4TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x14)[] =
{
    "FREE_0x14",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FREE_0x15)[] =
{
    "FREE_0x15",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_6X)[] =
{
    "MIXEDSAMPLE_6X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_6X_SKEWED_6TAP)[] =
{
    "MIXEDSAMPLE_6X_SKEWED_6TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_8X)[] =
{
    "MIXEDSAMPLE_8X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_8X_SKEWED_8TAP)[] =
{
    "MIXEDSAMPLE_8X_SKEWED_8TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_16X)[] =
{
    "MIXEDSAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_GAMMA)[] =
{
    "MULTISAMPLE_4X_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_16X)[] =
{
    "MULTISAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_VCAA_32X_8v24)[] =
{
    "VCAA_32X_8v24",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_CORRUPTION_CHECK)[] =
{
    "CORRUPTION_CHECK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_6X_CT)[] =
{
    "6X_CT",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL_GAMMA)[] =
{
    "MULTISAMPLE_2X_DIAGONAL_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_GAMMA)[] =
{
    "SUPERSAMPLE_4X_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_FOSGAMMA)[] =
{
    "MULTISAMPLE_4X_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA)[] =
{
    "MULTISAMPLE_2X_DIAGONAL_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_FOSGAMMA)[] =
{
    "SUPERSAMPLE_4X_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MULTISAMPLE_8X)[] =
{
    "MULTISAMPLE_8X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_VCAA_8X_4v4)[] =
{
    "VCAA_8X_4v4",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_VCAA_16X_4v12)[] =
{
    "VCAA_16X_4v12",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_VCAA_16X_8v8)[] =
{
    "VCAA_16X_8v8",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_32X)[] =
{
    "MIXEDSAMPLE_32X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERVCAA_64X_4v12)[] =
{
    "SUPERVCAA_64X_4v12",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SUPERVCAA_64X_8v8)[] =
{
    "SUPERVCAA_64X_8v8",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_64X)[] =
{
    "MIXEDSAMPLE_64X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_128X)[] =
{
    "MIXEDSAMPLE_128X",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_COUNT)[] =
{
    "COUNT",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_METHOD_MASK)[] =
{
    "METHOD_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_METHOD_MAX)[] =
{
    "METHOD_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_MASK)[] =
{
    "SELECTOR_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_APP_CONTROL)[] =
{
    "SELECTOR_APP_CONTROL",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_OVERRIDE)[] =
{
    "SELECTOR_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_ENHANCE)[] =
{
    "SELECTOR_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_SLIAA_MASK)[] =
{
    "SELECTOR_SLIAA_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_SELECTOR_MAX)[] =
{
    "SELECTOR_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_MASK)[] =
{
    "REPLAY_SAMPLES_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_ONE)[] =
{
    "REPLAY_SAMPLES_ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_TWO)[] =
{
    "REPLAY_SAMPLES_TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_FOUR)[] =
{
    "REPLAY_SAMPLES_FOUR",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_EIGHT)[] =
{
    "REPLAY_SAMPLES_EIGHT",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_MAX)[] =
{
    "REPLAY_SAMPLES_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_MASK)[] =
{
    "REPLAY_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_OFF)[] =
{
    "REPLAY_MODE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_ALPHA_TEST)[] =
{
    "REPLAY_MODE_ALPHA_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_PIXEL_KILL)[] =
{
    "REPLAY_MODE_PIXEL_KILL",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_DYN_BRANCH)[] =
{
    "REPLAY_MODE_DYN_BRANCH",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_OPTIMAL)[] =
{
    "REPLAY_MODE_OPTIMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_ALL)[] =
{
    "REPLAY_MODE_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_MODE_MAX)[] =
{
    "REPLAY_MODE_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY)[] =
{
    "REPLAY_TRANSPARENCY",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT)[] =
{
    "REPLAY_TRANSPARENCY_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA)[] =
{
    "REPLAY_TRANSPARENCY_DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI)[] =
{
    "REPLAY_TRANSPARENCY_DEFAULT_FERMI",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FORCE_FOS_MASK)[] =
{
    "FORCE_FOS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FORCE_FOS_DISABLED)[] =
{
    "FORCE_FOS_DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_FORCE_FOS_PASSIVE)[] =
{
    "FORCE_FOS_PASSIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_MASK)[] =
{
    "IGNORE_FOS_MEM_LIMITS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_ENABLE)[] =
{
    "IGNORE_FOS_MEM_LIMITS_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_PASSIVE)[] =
{
    "IGNORE_FOS_MEM_LIMITS_PASSIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_MASK)[] =
{
    "ALPHATOCOVERAGE_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_OFF)[] =
{
    "ALPHATOCOVERAGE_MODE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_ON)[] =
{
    "ALPHATOCOVERAGE_MODE_ON",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_MAX)[] =
{
    "ALPHATOCOVERAGE_MODE_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_MASK)[] =
{
    "GAMMACORRECTION_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_OFF)[] =
{
    "GAMMACORRECTION_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_ON_IF_FOS)[] =
{
    "GAMMACORRECTION_ON_IF_FOS",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_ON_ALWAYS)[] =
{
    "GAMMACORRECTION_ON_ALWAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_MAX)[] =
{
    "GAMMACORRECTION_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT)[] =
{
    "GAMMACORRECTION_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT_TESLA)[] =
{
    "GAMMACORRECTION_DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT_FERMI)[] =
{
    "GAMMACORRECTION_DEFAULT_FERMI",
    NULL
};

DataValueDWORD g_aDefineData_AAMODE[] =
{
    { (const char **)g_ppszDefineDataNames_AAMODE_NONE, 0x0 , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_2X_H, 0x1 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_2X_V, 0x2 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_1_5X1_5, 0x2 , "OGL only - 1.5 x 1.5 -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x03, 0x3 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x04, 0x4 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X, 0x5 , "D3D only, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_BIAS, 0x6 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_GAUSSIAN, 0x7 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x08, 0x8 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x09, 0x9 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_9X, 0xA , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_9X_BIAS, 0xB , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_16X, 0xC , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_16X_BIAS, 0xD , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL, 0xE , "OGL and D3D -- CP, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_QUINCUNX, 0xF , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X, 0x10 , "OGL and D3D -- CP, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x11, 0x11 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_GAUSSIAN, 0x12 , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_4X_SKEWED_4TAP, 0x13 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x14, 0x14 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FREE_0x15, 0x15 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_6X, 0x16 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_6X_SKEWED_6TAP, 0x17 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_8X, 0x18 , "4xMS, 2xSS OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_8X_SKEWED_8TAP, 0x19 , "2xMS, 4xSS OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_16X, 0x1a , "OGL only -- CP" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_GAMMA, 0x1b , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_16X, 0x1c , "D3D and OGL" },
    { (const char **)g_ppszDefineDataNames_AAMODE_VCAA_32X_8v24, 0x1d , "D3D and OGL" },
    { (const char **)g_ppszDefineDataNames_AAMODE_CORRUPTION_CHECK, 0x1e , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_6X_CT, 0x1f , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL_GAMMA, 0x20 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_GAMMA, 0x21 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_4X_FOSGAMMA, 0x22 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA, 0x23 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERSAMPLE_4X_FOSGAMMA, 0x24 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MULTISAMPLE_8X, 0x25 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_VCAA_8X_4v4, 0x26 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_VCAA_16X_4v12, 0x27 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_VCAA_16X_8v8, 0x28 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_32X, 0x29 , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERVCAA_64X_4v12, 0x2a , "D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SUPERVCAA_64X_8v8, 0x2b , "D3D" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_64X, 0x2c , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_MIXEDSAMPLE_128X, 0x2d , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AAMODE_COUNT, 0x2e , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_METHOD_MASK, 0x0000ffff , "contains one of the methods enumerated below" },
    { (const char **)g_ppszDefineDataNames_AAMODE_METHOD_MAX, 0xf1c57815 , "AA_METHOD_COUNT-1" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_MASK, 0x30000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_APP_CONTROL, 0x00000000 , "do what the app says" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_OVERRIDE, 0x10000000 , "override the app setting with what the user says (via CP/registry) for both enable and mode" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_ENHANCE, 0x20000000 , "enhance the app-specified mode (but not enable) with the CP mode" },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_SLIAA_MASK, 0x40000000 , "support for SLIAA this bit should tell us if we have selected SLIAA from CPL." },
    { (const char **)g_ppszDefineDataNames_AAMODE_SELECTOR_MAX, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_MASK, 0x07000000 , "number of times to replay the geometry" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_ONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_TWO, 0x01000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_FOUR, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_EIGHT, 0x03000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_SAMPLES_MAX, 0x03000000 , "Since Tesla has 8xMS" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_MASK, 0x00f00000 , "convert alpha to coverage for D3D app" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_OFF, 0x00000000 , "disabled" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_ALPHA_TEST, 0x00100000 , "alpha tested primitives" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_PIXEL_KILL, 0x00200000 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_DYN_BRANCH, 0x00400000 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_OPTIMAL, 0x00400000 , "Optimal Replay mode" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_ALL, 0x00800000 , "all types" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_MODE_MAX, 0x00f00000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY, 0x02300000 , "the standard control-panel setting (REPLAY_MODE_ALPHA_TEST|REPLAY_MODE_PIXEL_KILL|REPLAY_SAMPLES_FOUR)" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FORCE_FOS_MASK, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FORCE_FOS_DISABLED, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_FORCE_FOS_PASSIVE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_MASK, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_ENABLE, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_IGNORE_FOS_MEM_LIMITS_PASSIVE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_MASK, 0x00040000 , "convert alpha to coverage for D3D app" },
    { (const char **)g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_OFF, 0x00000000 , "Only for alpha tested primitive" },
    { (const char **)g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_ON, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_ALPHATOCOVERAGE_MODE_MAX, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_MASK, 0x00030000 , "use gamma corrected AA mode when possible (2X diagonal and 4x only, at this time)" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_ON_IF_FOS, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_ON_ALWAYS, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_MAX, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT, 0x00000000 , "GAMMACORRECTION_OFF" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT_TESLA, 0x00020000 , "GAMMACORRECTION_ON_ALWAYS" },
    { (const char **)g_ppszDefineDataNames_AAMODE_GAMMACORRECTION_DEFAULT_FERMI, 0x00020000 , "GAMMACORRECTION_ON_ALWAYS" },
};

DataDefaultDWORD g_aDefaultData_AAMODE[] =
{
    {"DEFAULT", 0x00000000, "SELECTOR_APP_CONTROL|GAMMACORRECTION_DEFAULT|REPLAY_TRANSPARENCY_DEFAULT|AA_METHOD_NONE" }, 
    {"DEFAULT_FERMI", 0x00020000, "SELECTOR_APP_CONTROL|GAMMACORRECTION_DEFAULT_FERMI|REPLAY_TRANSPARENCY_DEFAULT_FERMI|AA_METHOD_NONE" }, 
    {"DEFAULT_TESLA", 0x00020000, "SELECTOR_APP_CONTROL|GAMMACORRECTION_DEFAULT_TESLA|REPLAY_TRANSPARENCY_DEFAULT_TESLA|AA_METHOD_NONE" }, 
};

SettingDWORD g_setting_AAMODE(
    0x100b8ede,
    g_pszKeyName_AAMODE,
    g_pszRemappedName_AAMODE,
    g_pszMainDocs_AAMODE,
    g_pszDefinedWhen_AAMODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AAMODE, 
    92, 
    g_aDefaultData_AAMODE, 
    3 
);

static const char *g_pszKeyName_AA_BEHAVIOR_FLAGS = "AA_BEHAVIOR_FLAGS";
static const char *g_pszDefinedWhen_AA_BEHAVIOR_FLAGS = "1";
static const char *g_pszRemappedName_AA_BEHAVIOR_FLAGS = "D3DOGL_05143845";
static const char *g_pszMainDocs_AA_BEHAVIOR_FLAGS = "Flags for altering how the driver interprets 'Antialiasing - Setting'";

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_APP_CONTROLLED)[] =
{
    "TREAT_OVERRIDE_AS_APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_ENHANCE)[] =
{
    "TREAT_OVERRIDE_AS_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_OVERRIDE)[] =
{
    "DISABLE_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_APP_CONTROLLED)[] =
{
    "TREAT_ENHANCE_AS_APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_OVERRIDE)[] =
{
    "TREAT_ENHANCE_AS_OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_ENHANCE)[] =
{
    "DISABLE_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_MAP_VCAA_TO_MULTISAMPLING)[] =
{
    "MAP_VCAA_TO_MULTISAMPLING",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING)[] =
{
    "SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_CPLAA)[] =
{
    "DISABLE_CPLAA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_SKIP_RT_DIM_CHECK_FOR_ENHANCE)[] =
{
    "SKIP_RT_DIM_CHECK_FOR_ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_SLIAA)[] =
{
    "DISABLE_SLIAA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4)[] =
{
    "AA_RT_BPP_DIV_4",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4_SHIFT)[] =
{
    "AA_RT_BPP_DIV_4_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4)[] =
{
    "NON_AA_RT_BPP_DIV_4",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4_SHIFT)[] =
{
    "NON_AA_RT_BPP_DIV_4_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_AA_BEHAVIOR_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_APP_CONTROLLED, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_ENHANCE, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_OVERRIDE, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_APP_CONTROLLED, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_OVERRIDE, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_ENHANCE, 0x0000000c , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_MAP_VCAA_TO_MULTISAMPLING, 0x00010000 , "Map VCAA modes to their equivalent multisampling format" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING, 0x00020000 , "Disable transparency supersampling mode for SLI" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_CPLAA, 0x00040000 , "Disable CPL AA ,opengl only" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_SKIP_RT_DIM_CHECK_FOR_ENHANCE, 0x00080000 , "Don't check the render target dimensions when considering enhance mode" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DISABLE_SLIAA, 0x00100000 , "Disable SLIAA" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4, 0xf0000000 , "The number of bytes needed for AA render targets divided by 4 (not including the AA buffers themselves)" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4_SHIFT, 28 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4, 0x0f000000 , "The number of bytes needed for non-AA render targets divided by 4" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4_SHIFT, 24 , "" },
    { (const char **)g_ppszDefineDataNames_AA_BEHAVIOR_FLAGS_MASK, 0xff1f000f , "" },
};

DataDefaultDWORD g_aDefaultData_AA_BEHAVIOR_FLAGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_AA_BEHAVIOR_FLAGS(
    0x10ecdb82,
    g_pszKeyName_AA_BEHAVIOR_FLAGS,
    g_pszRemappedName_AA_BEHAVIOR_FLAGS,
    g_pszMainDocs_AA_BEHAVIOR_FLAGS,
    g_pszDefinedWhen_AA_BEHAVIOR_FLAGS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_BEHAVIOR_FLAGS, 
    18, 
    g_aDefaultData_AA_BEHAVIOR_FLAGS, 
    1 
);

static const char *g_pszKeyName_AA_MODE_ALPHATOCOVERAGE = "AA_MODE_ALPHATOCOVERAGE";
static const char *g_pszDefinedWhen_AA_MODE_ALPHATOCOVERAGE = "1";
static const char *g_pszRemappedName_AA_MODE_ALPHATOCOVERAGE = "D3DOGL_70835937D";
static const char *g_pszMainDocs_AA_MODE_ALPHATOCOVERAGE = "";

static const char * (g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_MASK)[] =
{
    "MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_OFF)[] =
{
    "MODE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_ON)[] =
{
    "MODE_ON",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_MAX)[] =
{
    "MODE_MAX",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_ALPHATOCOVERAGE[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_MASK, 0x00000004 , "convert alpha to coverage for D3D app" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_OFF, 0x00000000 , "Only for alpha tested primitive" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_ON, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_ALPHATOCOVERAGE_MODE_MAX, 0x00000004 , "" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_ALPHATOCOVERAGE[] =
{
    {"DEFAULT", 0x00000000, "MODE_OFF" }, 
    {"DEFAULT_FERMI", 0x00000000, "MODE_OFF" }, 
    {"DEFAULT_TESLA", 0x00000000, "MODE_OFF" }, 
};

SettingDWORD g_setting_AA_MODE_ALPHATOCOVERAGE(
    0x10fc2d9c,
    g_pszKeyName_AA_MODE_ALPHATOCOVERAGE,
    g_pszRemappedName_AA_MODE_ALPHATOCOVERAGE,
    g_pszMainDocs_AA_MODE_ALPHATOCOVERAGE,
    g_pszDefinedWhen_AA_MODE_ALPHATOCOVERAGE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_ALPHATOCOVERAGE, 
    4, 
    g_aDefaultData_AA_MODE_ALPHATOCOVERAGE, 
    3 
);

static const char *g_pszKeyName_AA_MODE_FOS = "AA_MODE_FOS";
static const char *g_pszDefinedWhen_AA_MODE_FOS = "1";
static const char *g_pszRemappedName_AA_MODE_FOS = "D3DOGL_70835937C";
static const char *g_pszMainDocs_AA_MODE_FOS = "";

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_MASK)[] =
{
    "FORCE_FOS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_DISABLED)[] =
{
    "FORCE_FOS_DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_PASSIVE)[] =
{
    "FORCE_FOS_PASSIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_MASK)[] =
{
    "IGNORE_FOS_MEM_LIMITS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_ENABLE)[] =
{
    "IGNORE_FOS_MEM_LIMITS_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_PASSIVE)[] =
{
    "IGNORE_FOS_MEM_LIMITS_PASSIVE",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_FOS[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_MASK, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_DISABLED, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_FORCE_FOS_PASSIVE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_MASK, 0x00000080 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_ENABLE, 0x00000080 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_PASSIVE, 0x00000000 , "" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_FOS[] =
{
    {"DEFAULT", 0x00000000, "FORCE_FOS_PASSIVE|IGNORE_FOS_MEM_LIMITS_PASSIVE" }, 
    {"DEFAULT_FERMI", 0x00000000, "FORCE_FOS_PASSIVE|IGNORE_FOS_MEM_LIMITS_PASSIVE" }, 
    {"DEFAULT_TESLA", 0x00000000, "FORCE_FOS_PASSIVE|IGNORE_FOS_MEM_LIMITS_PASSIVE" }, 
};

SettingDWORD g_setting_AA_MODE_FOS(
    0x10e8bf72,
    g_pszKeyName_AA_MODE_FOS,
    g_pszRemappedName_AA_MODE_FOS,
    g_pszMainDocs_AA_MODE_FOS,
    g_pszDefinedWhen_AA_MODE_FOS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_FOS, 
    6, 
    g_aDefaultData_AA_MODE_FOS, 
    3 
);

static const char *g_pszKeyName_AA_MODE_GAMMACORRECTION = "AA_MODE_GAMMACORRECTION";
static const char *g_pszDefinedWhen_AA_MODE_GAMMACORRECTION = "1";
static const char *g_pszRemappedName_AA_MODE_GAMMACORRECTION = "D3DOGL_70835937E";
static const char *g_pszMainDocs_AA_MODE_GAMMACORRECTION = "";

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_ON_IF_FOS)[] =
{
    "ON_IF_FOS",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_ON_ALWAYS)[] =
{
    "ON_ALWAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT_TESLA)[] =
{
    "DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT_FERMI)[] =
{
    "DEFAULT_FERMI",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_GAMMACORRECTION[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_MASK, 0x00000003 , "use gamma corrected AA mode when possible (2X diagonal and 4x only, at this time)" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_ON_IF_FOS, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_ON_ALWAYS, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_MAX, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT, 0x00000000 , "OFF" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT_TESLA, 0x00000002 , "ON_ALWAYS" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_GAMMACORRECTION_DEFAULT_FERMI, 0x00000002 , "ON_ALWAYS" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_GAMMACORRECTION[] =
{
    {"DEFAULT", 0x00000000, "DEFAULT" }, 
    {"DEFAULT_FERMI", 0x00000002, "DEFAULT_FERMI" }, 
    {"DEFAULT_TESLA", 0x00000002, "DEFAULT_TESLA" }, 
};

SettingDWORD g_setting_AA_MODE_GAMMACORRECTION(
    0x107d639d,
    g_pszKeyName_AA_MODE_GAMMACORRECTION,
    g_pszRemappedName_AA_MODE_GAMMACORRECTION,
    g_pszMainDocs_AA_MODE_GAMMACORRECTION,
    g_pszDefinedWhen_AA_MODE_GAMMACORRECTION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_GAMMACORRECTION, 
    8, 
    g_aDefaultData_AA_MODE_GAMMACORRECTION, 
    3 
);

static const char *g_pszKeyName_AA_MODE_METHOD = "AA_MODE_METHOD";
static const char *g_pszDefinedWhen_AA_MODE_METHOD = "1";
static const char *g_pszRemappedName_AA_MODE_METHOD = "D3DOGL_70835937F";
static const char *g_pszMainDocs_AA_MODE_METHOD = "Controls method and number of antialising samples";

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_2X_H)[] =
{
    "SUPERSAMPLE_2X_H",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_2X_V)[] =
{
    "SUPERSAMPLE_2X_V",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_1_5X1_5)[] =
{
    "SUPERSAMPLE_1_5X1_5",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x03)[] =
{
    "FREE_0x03",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x04)[] =
{
    "FREE_0x04",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X)[] =
{
    "SUPERSAMPLE_4X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_BIAS)[] =
{
    "SUPERSAMPLE_4X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_GAUSSIAN)[] =
{
    "SUPERSAMPLE_4X_GAUSSIAN",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x08)[] =
{
    "FREE_0x08",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x09)[] =
{
    "FREE_0x09",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_9X)[] =
{
    "SUPERSAMPLE_9X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_9X_BIAS)[] =
{
    "SUPERSAMPLE_9X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_16X)[] =
{
    "SUPERSAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_16X_BIAS)[] =
{
    "SUPERSAMPLE_16X_BIAS",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL)[] =
{
    "MULTISAMPLE_2X_DIAGONAL",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_QUINCUNX)[] =
{
    "MULTISAMPLE_2X_QUINCUNX",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X)[] =
{
    "MULTISAMPLE_4X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x11)[] =
{
    "FREE_0x11",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_GAUSSIAN)[] =
{
    "MULTISAMPLE_4X_GAUSSIAN",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_4X_SKEWED_4TAP)[] =
{
    "MIXEDSAMPLE_4X_SKEWED_4TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x14)[] =
{
    "FREE_0x14",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x15)[] =
{
    "FREE_0x15",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_6X)[] =
{
    "MIXEDSAMPLE_6X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_6X_SKEWED_6TAP)[] =
{
    "MIXEDSAMPLE_6X_SKEWED_6TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_8X)[] =
{
    "MIXEDSAMPLE_8X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_8X_SKEWED_8TAP)[] =
{
    "MIXEDSAMPLE_8X_SKEWED_8TAP",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_16X)[] =
{
    "MIXEDSAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_GAMMA)[] =
{
    "MULTISAMPLE_4X_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_16X)[] =
{
    "MULTISAMPLE_16X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_32X_8v24)[] =
{
    "VCAA_32X_8v24",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_CORRUPTION_CHECK)[] =
{
    "CORRUPTION_CHECK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_6X_CT)[] =
{
    "6X_CT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_GAMMA)[] =
{
    "MULTISAMPLE_2X_DIAGONAL_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_GAMMA)[] =
{
    "SUPERSAMPLE_4X_GAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_FOSGAMMA)[] =
{
    "MULTISAMPLE_4X_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA)[] =
{
    "MULTISAMPLE_2X_DIAGONAL_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_FOSGAMMA)[] =
{
    "SUPERSAMPLE_4X_FOSGAMMA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_8X)[] =
{
    "MULTISAMPLE_8X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_8X_4v4)[] =
{
    "VCAA_8X_4v4",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_16X_4v12)[] =
{
    "VCAA_16X_4v12",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_16X_8v8)[] =
{
    "VCAA_16X_8v8",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_32X)[] =
{
    "MIXEDSAMPLE_32X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERVCAA_64X_4v12)[] =
{
    "SUPERVCAA_64X_4v12",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_SUPERVCAA_64X_8v8)[] =
{
    "SUPERVCAA_64X_8v8",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_64X)[] =
{
    "MIXEDSAMPLE_64X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_128X)[] =
{
    "MIXEDSAMPLE_128X",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_COUNT)[] =
{
    "COUNT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_METHOD_MASK)[] =
{
    "METHOD_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_METHOD_METHOD_MAX)[] =
{
    "METHOD_MAX",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_METHOD[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_NONE, 0x0 , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_2X_H, 0x1 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_2X_V, 0x2 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_1_5X1_5, 0x2 , "OGL only - 1.5 x 1.5 -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x03, 0x3 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x04, 0x4 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X, 0x5 , "D3D only, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_BIAS, 0x6 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_GAUSSIAN, 0x7 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x08, 0x8 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x09, 0x9 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_9X, 0xA , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_9X_BIAS, 0xB , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_16X, 0xC , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_16X_BIAS, 0xD , "unused by CP, but functional via regkey" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL, 0xE , "OGL and D3D -- CP, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_QUINCUNX, 0xF , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X, 0x10 , "OGL and D3D -- CP, can be gamma corrected" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x11, 0x11 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_GAUSSIAN, 0x12 , "OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_4X_SKEWED_4TAP, 0x13 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x14, 0x14 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_FREE_0x15, 0x15 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_6X, 0x16 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_6X_SKEWED_6TAP, 0x17 , "D3D only -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_8X, 0x18 , "4xMS, 2xSS OGL and D3D -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_8X_SKEWED_8TAP, 0x19 , "2xMS, 4xSS OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_16X, 0x1a , "OGL only -- CP" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_GAMMA, 0x1b , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_16X, 0x1c , "D3D and OGL" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_32X_8v24, 0x1d , "D3D and OGL" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_CORRUPTION_CHECK, 0x1e , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_6X_CT, 0x1f , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_GAMMA, 0x20 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_GAMMA, 0x21 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_4X_FOSGAMMA, 0x22 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA, 0x23 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERSAMPLE_4X_FOSGAMMA, 0x24 , "D3D only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MULTISAMPLE_8X, 0x25 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_8X_4v4, 0x26 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_16X_4v12, 0x27 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_VCAA_16X_8v8, 0x28 , "OGL and D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_32X, 0x29 , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERVCAA_64X_4v12, 0x2a , "D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_SUPERVCAA_64X_8v8, 0x2b , "D3D" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_64X, 0x2c , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_MIXEDSAMPLE_128X, 0x2d , "OGL only" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_COUNT, 0x2e , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_METHOD_MASK, 0x0000ffff , "contains one of the methods enumerated below" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_METHOD_METHOD_MAX, 0xf1c57815 , "AA_METHOD_COUNT-1" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_METHOD[] =
{
    {"DEFAULT", 0x0, "AA_METHOD_NONE" }, 
    {"DEFAULT_FERMI", 0x0, "AA_METHOD_NONE" }, 
    {"DEFAULT_TESLA", 0x0, "AA_METHOD_NONE" }, 
};

SettingDWORD g_setting_AA_MODE_METHOD(
    0x10d773d2,
    g_pszKeyName_AA_MODE_METHOD,
    g_pszRemappedName_AA_MODE_METHOD,
    g_pszMainDocs_AA_MODE_METHOD,
    g_pszDefinedWhen_AA_MODE_METHOD,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_METHOD, 
    50, 
    g_aDefaultData_AA_MODE_METHOD, 
    3 
);

static const char *g_pszKeyName_AA_MODE_REPLAY = "AA_MODE_REPLAY";
static const char *g_pszDefinedWhen_AA_MODE_REPLAY = "1";
static const char *g_pszRemappedName_AA_MODE_REPLAY = "D3DOGL_70835937B";
static const char *g_pszMainDocs_AA_MODE_REPLAY = "";

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_MASK)[] =
{
    "SAMPLES_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_ONE)[] =
{
    "SAMPLES_ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_TWO)[] =
{
    "SAMPLES_TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_FOUR)[] =
{
    "SAMPLES_FOUR",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_EIGHT)[] =
{
    "SAMPLES_EIGHT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_MAX)[] =
{
    "SAMPLES_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_MASK)[] =
{
    "MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_OFF)[] =
{
    "MODE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_ALPHA_TEST)[] =
{
    "MODE_ALPHA_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_PIXEL_KILL)[] =
{
    "MODE_PIXEL_KILL",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_DYN_BRANCH)[] =
{
    "MODE_DYN_BRANCH",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_OPTIMAL)[] =
{
    "MODE_OPTIMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_ALL)[] =
{
    "MODE_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_MAX)[] =
{
    "MODE_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY)[] =
{
    "TRANSPARENCY",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_DISALLOW_TRAA)[] =
{
    "DISALLOW_TRAA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT)[] =
{
    "TRANSPARENCY_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA)[] =
{
    "TRANSPARENCY_DEFAULT_TESLA",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI)[] =
{
    "TRANSPARENCY_DEFAULT_FERMI",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_REPLAY_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_REPLAY[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_MASK, 0x00000070 , "number of times to replay the geometry" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_ONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_TWO, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_FOUR, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_EIGHT, 0x00000030 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_SAMPLES_MAX, 0x00000030 , "Since Tesla has 8xMS" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_MASK, 0x0000000f , "convert alpha to coverage for D3D app" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_OFF, 0x00000000 , "disabled" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_ALPHA_TEST, 0x00000001 , "alpha tested primitives" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_PIXEL_KILL, 0x00000002 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_DYN_BRANCH, 0x00000004 , "pixel-kill shaders" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_OPTIMAL, 0x00000004 , "Optimal Replay mode" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_ALL, 0x00000008 , "all types" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MODE_MAX, 0x0000000f , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY, 0x00000023 , "the standard control-panel setting (REPLAY_MODE_ALPHA_TEST|REPLAY_MODE_PIXEL_KILL|REPLAY_SAMPLES_FOUR)" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_DISALLOW_TRAA, 0x00000100 , "some apps do not work correctly with TRAA. Disallow it even if the user has created an app profile with it enabled." },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_REPLAY_MASK, 0x0000017f , "" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_REPLAY[] =
{
    {"DEFAULT", 0x00000000, "TRANSPARENCY_DEFAULT" }, 
    {"DEFAULT_FERMI", 0x00000000, "TRANSPARENCY_DEFAULT_FERMI" }, 
    {"DEFAULT_TESLA", 0x00000000, "TRANSPARENCY_DEFAULT_TESLA" }, 
};

SettingDWORD g_setting_AA_MODE_REPLAY(
    0x10d48a85,
    g_pszKeyName_AA_MODE_REPLAY,
    g_pszRemappedName_AA_MODE_REPLAY,
    g_pszMainDocs_AA_MODE_REPLAY,
    g_pszDefinedWhen_AA_MODE_REPLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_REPLAY, 
    20, 
    g_aDefaultData_AA_MODE_REPLAY, 
    3 
);

static const char *g_pszKeyName_AA_MODE_SELECTOR = "AA_MODE_SELECTOR";
static const char *g_pszDefinedWhen_AA_MODE_SELECTOR = "1";
static const char *g_pszRemappedName_AA_MODE_SELECTOR = "D3DOGL_70835937A";
static const char *g_pszMainDocs_AA_MODE_SELECTOR = "";

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_APP_CONTROL)[] =
{
    "APP_CONTROL",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_OVERRIDE)[] =
{
    "OVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_ENHANCE)[] =
{
    "ENHANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_SELECTOR[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_MASK, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_APP_CONTROL, 0x00000000 , "do what the app says" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_OVERRIDE, 0x00000001 , "override the app setting with what the user says (via CP/registry) for both enable and mode" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_ENHANCE, 0x00000002 , "enhance the app-specified mode (but not enable) with the CP mode" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_MAX, 0x00000002 , "" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_SELECTOR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
    {"DEFAULT_FERMI", 0x00000000, "" }, 
    {"DEFAULT_TESLA", 0x00000000, "" }, 
};

SettingDWORD g_setting_AA_MODE_SELECTOR(
    0x107efc5b,
    g_pszKeyName_AA_MODE_SELECTOR,
    g_pszRemappedName_AA_MODE_SELECTOR,
    g_pszMainDocs_AA_MODE_SELECTOR,
    g_pszDefinedWhen_AA_MODE_SELECTOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_SELECTOR, 
    5, 
    g_aDefaultData_AA_MODE_SELECTOR, 
    3 
);

static const char *g_pszKeyName_AA_MODE_SELECTOR_SLIAA = "AA_MODE_SELECTOR_SLIAA";
static const char *g_pszDefinedWhen_AA_MODE_SELECTOR_SLIAA = "1";
static const char *g_pszRemappedName_AA_MODE_SELECTOR_SLIAA = "D3DOGL_70835937SA";
static const char *g_pszMainDocs_AA_MODE_SELECTOR_SLIAA = "";

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_SLIAA_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_AA_MODE_SELECTOR_SLIAA_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_AA_MODE_SELECTOR_SLIAA[] =
{
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_SLIAA_DISABLED, 0 , "Do not use SLI AA" },
    { (const char **)g_ppszDefineDataNames_AA_MODE_SELECTOR_SLIAA_ENABLED, 1 , "Use SLI AA" },
};

DataDefaultDWORD g_aDefaultData_AA_MODE_SELECTOR_SLIAA[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_AA_MODE_SELECTOR_SLIAA(
    0x107afc5b,
    g_pszKeyName_AA_MODE_SELECTOR_SLIAA,
    g_pszRemappedName_AA_MODE_SELECTOR_SLIAA,
    g_pszMainDocs_AA_MODE_SELECTOR_SLIAA,
    g_pszDefinedWhen_AA_MODE_SELECTOR_SLIAA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AA_MODE_SELECTOR_SLIAA, 
    2, 
    g_aDefaultData_AA_MODE_SELECTOR_SLIAA, 
    1 
);

static const char *g_pszKeyName_AFRSLIAA = "AFRSLIAA";
static const char *g_pszDefinedWhen_AFRSLIAA = "1";
static const char *g_pszRemappedName_AFRSLIAA = "D3DOGL_12677979";
static const char *g_pszMainDocs_AFRSLIAA = "";

static const char * (g_ppszDefineDataNames_AFRSLIAA_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AFRSLIAA_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_AFRSLIAA[] =
{
    { (const char **)g_ppszDefineDataNames_AFRSLIAA_OFF, 0x51621661 , "" },
    { (const char **)g_ppszDefineDataNames_AFRSLIAA_ON, 0x29060798 , "" },
};

DataDefaultDWORD g_aDefaultData_AFRSLIAA[] =
{
    {"DEFAULT", 0x51621661, "" }, 
};

SettingDWORD g_setting_AFRSLIAA(
    0x10f115bc,
    g_pszKeyName_AFRSLIAA,
    g_pszRemappedName_AFRSLIAA,
    g_pszMainDocs_AFRSLIAA,
    g_pszDefinedWhen_AFRSLIAA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AFRSLIAA, 
    2, 
    g_aDefaultData_AFRSLIAA, 
    1 
);

static const char *g_pszKeyName_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ = "ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ";
static const char *g_pszDefinedWhen_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ = "1";
static const char *g_pszRemappedName_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ = "D3DOGL_0xd6c4e8";
static const char *g_pszMainDocs_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ = "GA10x+ only.  Enables PixelShader and TiledCache Barriers to also operate before EarlyZ, instead of just before Pixel shader as done on previous chips.  See http://nvbugs/2080801";

static const char * (g_ppszDefineDataNames_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ[] =
{
    { (const char **)g_ppszDefineDataNames_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ(
    0x10d6c4e8,
    g_pszKeyName_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ,
    g_pszRemappedName_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ,
    g_pszMainDocs_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ,
    g_pszDefinedWhen_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ, 
    2, 
    g_aDefaultData_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ, 
    1 
);

static const char *g_pszKeyName_ANISOMODE = "ANISOMODE";
static const char *g_pszDefinedWhen_ANISOMODE = "1";
static const char *g_pszRemappedName_ANISOMODE = "D3DOGL_74095213";
static const char *g_pszMainDocs_ANISOMODE = "Controls how the anisotropic filtering mode is applied";

static const char * (g_ppszDefineDataNames_ANISOMODE_SELECTOR_MASK)[] =
{
    "SELECTOR_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_SELECTOR_APP)[] =
{
    "SELECTOR_APP",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_SELECTOR_USER)[] =
{
    "SELECTOR_USER",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_SELECTOR_COND)[] =
{
    "SELECTOR_COND",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_SELECTOR_MAX)[] =
{
    "SELECTOR_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_LEVEL_MASK)[] =
{
    "LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_LEVEL_NONE_POINT)[] =
{
    "LEVEL_NONE_POINT",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_LEVEL_NONE_LINEAR)[] =
{
    "LEVEL_NONE_LINEAR",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_LEVEL_MAX)[] =
{
    "LEVEL_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISOMODE_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_ANISOMODE[] =
{
    { (const char **)g_ppszDefineDataNames_ANISOMODE_SELECTOR_MASK, 0xf0000000 , "" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_SELECTOR_APP, 0x00000000 , "do what the app says" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_SELECTOR_USER, 0x10000000 , "do what the user says (via CP/registry)" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_SELECTOR_COND, 0x20000000 , "do what the user says unless the app already specified something" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_SELECTOR_MAX, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_LEVEL_MASK, 0x0000ffff , "" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_LEVEL_NONE_POINT, 0x00000000 , "no aniso, fall back to point" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_LEVEL_NONE_LINEAR, 0x00000001 , "no aniso, fall back to linear" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_LEVEL_MAX, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_ANISOMODE_DEFAULT, 0x00000001 , "(SELECTOR_APP|LEVEL_NONE_LINEAR)" },
};

DataDefaultDWORD g_aDefaultData_ANISOMODE[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_ANISOMODE(
    0x10f74257,
    g_pszKeyName_ANISOMODE,
    g_pszRemappedName_ANISOMODE,
    g_pszMainDocs_ANISOMODE,
    g_pszDefinedWhen_ANISOMODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANISOMODE, 
    10, 
    g_aDefaultData_ANISOMODE, 
    1 
);

static const char *g_pszKeyName_ANISO_MODE_LEVEL = "ANISO_MODE_LEVEL";
static const char *g_pszDefinedWhen_ANISO_MODE_LEVEL = "1";
static const char *g_pszRemappedName_ANISO_MODE_LEVEL = "D3DOGL_74095213B";
static const char *g_pszMainDocs_ANISO_MODE_LEVEL = "Controls number of samples and algorithm of anisotropic filtering";

static const char * (g_ppszDefineDataNames_ANISO_MODE_LEVEL_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_LEVEL_NONE_POINT)[] =
{
    "NONE_POINT",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_LEVEL_NONE_LINEAR)[] =
{
    "NONE_LINEAR",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_LEVEL_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_LEVEL_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_ANISO_MODE_LEVEL[] =
{
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_LEVEL_MASK, 0x0000ffff , "" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_LEVEL_NONE_POINT, 0x00000000 , "no aniso, fall back to point" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_LEVEL_NONE_LINEAR, 0x00000001 , "no aniso, fall back to linear" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_LEVEL_MAX, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_LEVEL_DEFAULT, 0x00000001 , "NONE_LINEAR" },
};

DataDefaultDWORD g_aDefaultData_ANISO_MODE_LEVEL[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_ANISO_MODE_LEVEL(
    0x101e61a9,
    g_pszKeyName_ANISO_MODE_LEVEL,
    g_pszRemappedName_ANISO_MODE_LEVEL,
    g_pszMainDocs_ANISO_MODE_LEVEL,
    g_pszDefinedWhen_ANISO_MODE_LEVEL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANISO_MODE_LEVEL, 
    5, 
    g_aDefaultData_ANISO_MODE_LEVEL, 
    1 
);

static const char *g_pszKeyName_ANISO_MODE_SELECTOR = "ANISO_MODE_SELECTOR";
static const char *g_pszDefinedWhen_ANISO_MODE_SELECTOR = "1";
static const char *g_pszRemappedName_ANISO_MODE_SELECTOR = "D3DOGL_74095213A";
static const char *g_pszMainDocs_ANISO_MODE_SELECTOR = "";

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_APP)[] =
{
    "APP",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_USER)[] =
{
    "USER",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_COND)[] =
{
    "COND",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_ANISO_MODE_SELECTOR_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_ANISO_MODE_SELECTOR[] =
{
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_MASK, 0x0000000f , "" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_APP, 0x00000000 , "do what the app says" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_USER, 0x00000001 , "do what the user says (via CP/registry)" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_COND, 0x00000002 , "do what the user says unless the app already specified something" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_MAX, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_ANISO_MODE_SELECTOR_DEFAULT, 0x00000000 , "APP" },
};

DataDefaultDWORD g_aDefaultData_ANISO_MODE_SELECTOR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_ANISO_MODE_SELECTOR(
    0x10d2bb16,
    g_pszKeyName_ANISO_MODE_SELECTOR,
    g_pszRemappedName_ANISO_MODE_SELECTOR,
    g_pszMainDocs_ANISO_MODE_SELECTOR,
    g_pszDefinedWhen_ANISO_MODE_SELECTOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANISO_MODE_SELECTOR, 
    6, 
    g_aDefaultData_ANISO_MODE_SELECTOR, 
    1 
);

static const char *g_pszKeyName_ANSEL_ALLOW = "ANSEL_ALLOW";
static const char *g_pszDefinedWhen_ANSEL_ALLOW = "1";
static const char *g_pszRemappedName_ANSEL_ALLOW = "D3DOGL_10682898";
static const char *g_pszMainDocs_ANSEL_ALLOW = "Empowers an app profile to disallow Ansel";

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_DISALLOWED)[] =
{
    "DISALLOWED",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_ALLOWED)[] =
{
    "ALLOWED",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ALLOW[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_DISALLOWED, 0 , "Ansel is not allowed" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_ALLOWED, 1 , "Ansel is allowed" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ALLOW[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_ANSEL_ALLOW(
    0x1035db89,
    g_pszKeyName_ANSEL_ALLOW,
    g_pszRemappedName_ANSEL_ALLOW,
    g_pszMainDocs_ANSEL_ALLOW,
    g_pszDefinedWhen_ANSEL_ALLOW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANSEL_ALLOW, 
    2, 
    g_aDefaultData_ANSEL_ALLOW, 
    1 
);

static const char *g_pszKeyName_ANSEL_ALLOWLISTED = "ANSEL_ALLOWLISTED";
static const char *g_pszDefinedWhen_ANSEL_ALLOWLISTED = "1";
static const char *g_pszRemappedName_ANSEL_ALLOWLISTED = "D3DOGL_14792591";
static const char *g_pszMainDocs_ANSEL_ALLOWLISTED = "Temporary allowlisting of apps allowed to enable Ansel";

static const char * (g_ppszDefineDataNames_ANSEL_ALLOWLISTED_DISALLOWED)[] =
{
    "DISALLOWED",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ALLOWLISTED_ALLOWED)[] =
{
    "ALLOWED",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ALLOWLISTED[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOWLISTED_DISALLOWED, 0 , "Ansel is not allowed" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOWLISTED_ALLOWED, 1 , "Ansel is allowed" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ALLOWLISTED[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_ANSEL_ALLOWLISTED(
    0x1085da8a,
    g_pszKeyName_ANSEL_ALLOWLISTED,
    g_pszRemappedName_ANSEL_ALLOWLISTED,
    g_pszMainDocs_ANSEL_ALLOWLISTED,
    g_pszDefinedWhen_ANSEL_ALLOWLISTED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANSEL_ALLOWLISTED, 
    2, 
    g_aDefaultData_ANSEL_ALLOWLISTED, 
    1 
);

static const char *g_pszKeyName_ANSEL_ALLOW_FREESTYLE_MODE = "ANSEL_ALLOW_FREESTYLE_MODE";
static const char *g_pszDefinedWhen_ANSEL_ALLOW_FREESTYLE_MODE = "1";
static const char *g_pszRemappedName_ANSEL_ALLOW_FREESTYLE_MODE = "D3DOGL_33999624";
static const char *g_pszMainDocs_ANSEL_ALLOW_FREESTYLE_MODE = "Ansel Global Enablement Key";

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_FREESTYLE_MODE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_FREESTYLE_MODE_ENABLED)[] =
{
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ALLOW_FREESTYLE_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_FREESTYLE_MODE_DISABLED, 0x0000 , "FreeStyle mode is not allowed" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_FREESTYLE_MODE_ENABLED, 0x0001 , "FreeStyle mode is allowed" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ALLOW_FREESTYLE_MODE[] =
{
    {"DEFAULT", 0x0000, "" }, 
};

SettingDWORD g_setting_ANSEL_ALLOW_FREESTYLE_MODE(
    0x101baaaf,
    g_pszKeyName_ANSEL_ALLOW_FREESTYLE_MODE,
    g_pszRemappedName_ANSEL_ALLOW_FREESTYLE_MODE,
    g_pszMainDocs_ANSEL_ALLOW_FREESTYLE_MODE,
    g_pszDefinedWhen_ANSEL_ALLOW_FREESTYLE_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ANSEL_ALLOW_FREESTYLE_MODE, 
    2, 
    g_aDefaultData_ANSEL_ALLOW_FREESTYLE_MODE, 
    1 
);

static const char *g_pszKeyName_ANSEL_ALLOW_OFFLINE = "ANSEL_ALLOW_OFFLINE";
static const char *g_pszDefinedWhen_ANSEL_ALLOW_OFFLINE = "1";
static const char *g_pszRemappedName_ANSEL_ALLOW_OFFLINE = "D3DOGL_93980749";
static const char *g_pszMainDocs_ANSEL_ALLOW_OFFLINE = "Determines if Ansel is allowed to be loaded and activated offline without the need for any network checks.";

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_OFFLINE_DISALLOWED)[] =
{
    "DISALLOWED",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ALLOW_OFFLINE_ALLOWED)[] =
{
    "ALLOWED",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ALLOW_OFFLINE[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_OFFLINE_DISALLOWED, 0 , "Offline Ansel is not allowed" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ALLOW_OFFLINE_ALLOWED, 1 , "Offline Ansel is allowed" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ALLOW_OFFLINE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_ANSEL_ALLOW_OFFLINE(
    0x10d5c2db,
    g_pszKeyName_ANSEL_ALLOW_OFFLINE,
    g_pszRemappedName_ANSEL_ALLOW_OFFLINE,
    g_pszMainDocs_ANSEL_ALLOW_OFFLINE,
    g_pszDefinedWhen_ANSEL_ALLOW_OFFLINE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANSEL_ALLOW_OFFLINE, 
    2, 
    g_aDefaultData_ANSEL_ALLOW_OFFLINE, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_DEPTH_SETTINGS = "ANSEL_BUFFERS_DEPTH_SETTINGS";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_DEPTH_SETTINGS = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_DEPTH_SETTINGS = "D3DOGL_16068746";
static const char *g_pszMainDocs_ANSEL_BUFFERS_DEPTH_SETTINGS = "Toggle various settings useful for tuning how to identify Depth buffers in Ansel. More info: https://confluence.nvidia.com/display/NGX/Depth+Buffer+Detection+Design.";

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_USE_STATS)[] =
{
    "USE_STATS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_USE_VIEWPORT)[] =
{
    "USE_VIEWPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_VIEWPORT_SCALING)[] =
{
    "VIEWPORT_SCALING",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_OVERRIDE_EN)[] =
{
    "OVERRIDE_EN",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Y)[] =
{
    "INVERT_Y",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Z)[] =
{
    "INVERT_Z",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_ALL)[] =
{
    "ALL",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_BUFFERS_DEPTH_SETTINGS[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_NONE, 0x00000000 , "None of the depth settings will be enabled." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_USE_STATS, 0x00000001 , "Use the Stats Mechanism to identify which buffer has Depth information." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_USE_VIEWPORT, 0x00000002 , "Use Viewport ratio to compare with backbuffer ratio as a metric for determining whether a buffer has Depth." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_VIEWPORT_SCALING, 0x00000004 , "Use Viewport information to scale Depth image which is needed for games with Dynamic Resolution Scaling. Can only be used when USE_VIEWPORT is enabled." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_OVERRIDE_EN, 0x00000008 , "Enable Depth Settings overrides for Y/Z Inversion." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Y, 0x00000010 , "Indicate whether a game's depth is inverted in Y-plane, if OVERRIDE_EN is set. Inverted means Bottom=1.0, Top = 0.0" },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Z, 0x00000020 , "Indicate whether a game's depth is inverted in Z-plane, if OVERRIDE_EN is set. Inverted means Near=1.0, Far = 0.0" },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DEPTH_SETTINGS_ALL, 0xFFFFFFFF , "All of the depth settings will be enabled." },
};

DataDefaultDWORD g_aDefaultData_ANSEL_BUFFERS_DEPTH_SETTINGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_ANSEL_BUFFERS_DEPTH_SETTINGS(
    0x101314ce,
    g_pszKeyName_ANSEL_BUFFERS_DEPTH_SETTINGS,
    g_pszRemappedName_ANSEL_BUFFERS_DEPTH_SETTINGS,
    g_pszMainDocs_ANSEL_BUFFERS_DEPTH_SETTINGS,
    g_pszDefinedWhen_ANSEL_BUFFERS_DEPTH_SETTINGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ANSEL_BUFFERS_DEPTH_SETTINGS, 
    8, 
    g_aDefaultData_ANSEL_BUFFERS_DEPTH_SETTINGS, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_DEPTH_WEIGHTS = "ANSEL_BUFFERS_DEPTH_WEIGHTS";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_DEPTH_WEIGHTS = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_DEPTH_WEIGHTS = "D3DOGL_16068747";
static const char *g_pszMainDocs_ANSEL_BUFFERS_DEPTH_WEIGHTS = "Key-value pair in the form 'string=uint32'. Each keyval pair delimited by comma. The weights can be used to fine-tune a game based on in-game heuristics for correctly finding the depth buffer.";

DataDefaultWSTRING g_aDefaultData_ANSEL_BUFFERS_DEPTH_WEIGHTS[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_ANSEL_BUFFERS_DEPTH_WEIGHTS(
    0x10079dbc,
    g_pszKeyName_ANSEL_BUFFERS_DEPTH_WEIGHTS,
    g_pszRemappedName_ANSEL_BUFFERS_DEPTH_WEIGHTS,
    g_pszMainDocs_ANSEL_BUFFERS_DEPTH_WEIGHTS,
    g_pszDefinedWhen_ANSEL_BUFFERS_DEPTH_WEIGHTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_ANSEL_BUFFERS_DEPTH_WEIGHTS, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_DISABLED = "ANSEL_BUFFERS_DISABLED";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_DISABLED = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_DISABLED = "D3DOGL_16068745";
static const char *g_pszMainDocs_ANSEL_BUFFERS_DISABLED = "Specifies which buffers are blocked from being captured in NvCamera. Specify multiple buffers by or'ing them tegether with '|'.";

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_DEPTH)[] =
{
    "DEPTH",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_HDR)[] =
{
    "HDR",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_HUDLESS)[] =
{
    "HUDLESS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_FINAL_COLOR)[] =
{
    "FINAL_COLOR",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_ALL)[] =
{
    "ALL",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_BUFFERS_DISABLED[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_NONE, 0x00000000 , "Disables nothing. All buffers can be captured." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_DEPTH, 0x00000001 , "Disables Depth buffer capture." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_HDR, 0x00000002 , "Disables HDR buffer capture." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_HUDLESS, 0x00000004 , "Disables HUDless buffer capture." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_FINAL_COLOR, 0x00000008 , "Disables Final Color buffer capture." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_DISABLED_ALL, 0xFFFFFFFF , "Disables everything. No buffers can be captured other than the default present buffer." },
};

DataDefaultDWORD g_aDefaultData_ANSEL_BUFFERS_DISABLED[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_ANSEL_BUFFERS_DISABLED(
    0x10e74421,
    g_pszKeyName_ANSEL_BUFFERS_DISABLED,
    g_pszRemappedName_ANSEL_BUFFERS_DISABLED,
    g_pszMainDocs_ANSEL_BUFFERS_DISABLED,
    g_pszDefinedWhen_ANSEL_BUFFERS_DISABLED,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ANSEL_BUFFERS_DISABLED, 
    6, 
    g_aDefaultData_ANSEL_BUFFERS_DISABLED, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_HUDLESS_DRAWCALL = "ANSEL_BUFFERS_HUDLESS_DRAWCALL";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_DRAWCALL = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_DRAWCALL = "D3DOGL_16068750";
static const char *g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_DRAWCALL = "Sets the draw call at which point the Hudless buffer will be copied, with the goal of selecting the last draw call before any HUD draws occur. More info: https://confluence.nvidia.com/display/NGX/Hudless+Buffer+Detection+Design.";

DataDefaultDWORD g_aDefaultData_ANSEL_BUFFERS_HUDLESS_DRAWCALL[] =
{
    {"DEFAULT", 2, "" }, 
};

SettingDWORD g_setting_ANSEL_BUFFERS_HUDLESS_DRAWCALL(
    0x101fd0c1,
    g_pszKeyName_ANSEL_BUFFERS_HUDLESS_DRAWCALL,
    g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_DRAWCALL,
    g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_DRAWCALL,
    g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_DRAWCALL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_ANSEL_BUFFERS_HUDLESS_DRAWCALL, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_HUDLESS_SETTINGS = "ANSEL_BUFFERS_HUDLESS_SETTINGS";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_SETTINGS = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_SETTINGS = "D3DOGL_16068748";
static const char *g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_SETTINGS = "Toggle various settings useful for tuning how to identify Hudless buffers in Ansel. More info: https://confluence.nvidia.com/display/NGX/Hudless+Buffer+Detection+Design.";

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_USE_STATS)[] =
{
    "USE_STATS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_ONLY_SINGLE_RTV_BINDS)[] =
{
    "ONLY_SINGLE_RTV_BINDS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_RESTRICT_FORMATS)[] =
{
    "RESTRICT_FORMATS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_ALL)[] =
{
    "ALL",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_BUFFERS_HUDLESS_SETTINGS[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_NONE, 0x00000000 , "None of the hudless settings will be enabled." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_USE_STATS, 0x00000001 , "Use the Stats Mechanism to identify which buffer has Hudless information." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_ONLY_SINGLE_RTV_BINDS, 0x00000002 , "Toggle whether to restrict buffer candidates to those which are bound individually." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_RESTRICT_FORMATS, 0x00000004 , "Toggle whether to restrict buffer candidates to specific colour formats." },
    { (const char **)g_ppszDefineDataNames_ANSEL_BUFFERS_HUDLESS_SETTINGS_ALL, 0xFFFFFFFF , "All of the hudless settings will be enabled." },
};

DataDefaultDWORD g_aDefaultData_ANSEL_BUFFERS_HUDLESS_SETTINGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_ANSEL_BUFFERS_HUDLESS_SETTINGS(
    0x10ad7f3b,
    g_pszKeyName_ANSEL_BUFFERS_HUDLESS_SETTINGS,
    g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_SETTINGS,
    g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_SETTINGS,
    g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_SETTINGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ANSEL_BUFFERS_HUDLESS_SETTINGS, 
    5, 
    g_aDefaultData_ANSEL_BUFFERS_HUDLESS_SETTINGS, 
    1 
);

static const char *g_pszKeyName_ANSEL_BUFFERS_HUDLESS_WEIGHTS = "ANSEL_BUFFERS_HUDLESS_WEIGHTS";
static const char *g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_WEIGHTS = "1";
static const char *g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_WEIGHTS = "D3DOGL_16068749";
static const char *g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_WEIGHTS = "Key-value pair in the form 'string=uint32'. Each keyval pair delimited by comma. The weights can be used to fine-tune a game based on in-game heuristics for correctly finding the hudless buffer.";

DataDefaultWSTRING g_aDefaultData_ANSEL_BUFFERS_HUDLESS_WEIGHTS[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_ANSEL_BUFFERS_HUDLESS_WEIGHTS(
    0x10c41bb5,
    g_pszKeyName_ANSEL_BUFFERS_HUDLESS_WEIGHTS,
    g_pszRemappedName_ANSEL_BUFFERS_HUDLESS_WEIGHTS,
    g_pszMainDocs_ANSEL_BUFFERS_HUDLESS_WEIGHTS,
    g_pszDefinedWhen_ANSEL_BUFFERS_HUDLESS_WEIGHTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_ANSEL_BUFFERS_HUDLESS_WEIGHTS, 
    1 
);

static const char *g_pszKeyName_ANSEL_DENYLIST_ALL_PROFILED = "ANSEL_DENYLIST_ALL_PROFILED";
static const char *g_pszDefinedWhen_ANSEL_DENYLIST_ALL_PROFILED = "1";
static const char *g_pszRemappedName_ANSEL_DENYLIST_ALL_PROFILED = "D3DOGL_43102335";
static const char *g_pszMainDocs_ANSEL_DENYLIST_ALL_PROFILED = "Specifies denylisting combinations for Ansel. This is meant to be set identically for all Ansel enabled profiles.";

DataDefaultWSTRING g_aDefaultData_ANSEL_DENYLIST_ALL_PROFILED[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_ANSEL_DENYLIST_ALL_PROFILED(
    0x10f272b9,
    g_pszKeyName_ANSEL_DENYLIST_ALL_PROFILED,
    g_pszRemappedName_ANSEL_DENYLIST_ALL_PROFILED,
    g_pszMainDocs_ANSEL_DENYLIST_ALL_PROFILED,
    g_pszDefinedWhen_ANSEL_DENYLIST_ALL_PROFILED,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_ANSEL_DENYLIST_ALL_PROFILED, 
    1 
);

static const char *g_pszKeyName_ANSEL_DENYLIST_PER_GAME = "ANSEL_DENYLIST_PER_GAME";
static const char *g_pszDefinedWhen_ANSEL_DENYLIST_PER_GAME = "1";
static const char *g_pszRemappedName_ANSEL_DENYLIST_PER_GAME = "D3DOGL_23776708";
static const char *g_pszMainDocs_ANSEL_DENYLIST_PER_GAME = "Specifies denylisting combinations for Ansel. Set this per-game.";

DataDefaultWSTRING g_aDefaultData_ANSEL_DENYLIST_PER_GAME[] =
{
    {"DEFAULT", L"", "" }, 
};

SettingWSTRING g_setting_ANSEL_DENYLIST_PER_GAME(
    0x100d51f7,
    g_pszKeyName_ANSEL_DENYLIST_PER_GAME,
    g_pszRemappedName_ANSEL_DENYLIST_PER_GAME,
    g_pszMainDocs_ANSEL_DENYLIST_PER_GAME,
    g_pszDefinedWhen_ANSEL_DENYLIST_PER_GAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_ANSEL_DENYLIST_PER_GAME, 
    1 
);

static const char *g_pszKeyName_ANSEL_ENABLE = "ANSEL_ENABLE";
static const char *g_pszDefinedWhen_ANSEL_ENABLE = "1";
static const char *g_pszRemappedName_ANSEL_ENABLE = "D3DOGL_97373802";
static const char *g_pszMainDocs_ANSEL_ENABLE = "Toggle Ansel on or off";

static const char * (g_ppszDefineDataNames_ANSEL_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ENABLE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ENABLE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ENABLE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_ANSEL_ENABLE(
    0x1075d972,
    g_pszKeyName_ANSEL_ENABLE,
    g_pszRemappedName_ANSEL_ENABLE,
    g_pszMainDocs_ANSEL_ENABLE,
    g_pszDefinedWhen_ANSEL_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANSEL_ENABLE, 
    2, 
    g_aDefaultData_ANSEL_ENABLE, 
    1 
);

static const char *g_pszKeyName_ANSEL_ENABLE_OPTIMUS = "ANSEL_ENABLE_OPTIMUS";
static const char *g_pszDefinedWhen_ANSEL_ENABLE_OPTIMUS = "1";
static const char *g_pszRemappedName_ANSEL_ENABLE_OPTIMUS = "D3DOGL_97373801";
static const char *g_pszMainDocs_ANSEL_ENABLE_OPTIMUS = "Toggle Ansel on or off on Optimus systems";

static const char * (g_ppszDefineDataNames_ANSEL_ENABLE_OPTIMUS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_ENABLE_OPTIMUS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_ENABLE_OPTIMUS[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_ENABLE_OPTIMUS_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_ANSEL_ENABLE_OPTIMUS_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_ENABLE_OPTIMUS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_ANSEL_ENABLE_OPTIMUS(
    0x1075d973,
    g_pszKeyName_ANSEL_ENABLE_OPTIMUS,
    g_pszRemappedName_ANSEL_ENABLE_OPTIMUS,
    g_pszMainDocs_ANSEL_ENABLE_OPTIMUS,
    g_pszDefinedWhen_ANSEL_ENABLE_OPTIMUS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ANSEL_ENABLE_OPTIMUS, 
    2, 
    g_aDefaultData_ANSEL_ENABLE_OPTIMUS, 
    1 
);

static const char *g_pszKeyName_ANSEL_FREESTYLE_MODE = "ANSEL_FREESTYLE_MODE";
static const char *g_pszDefinedWhen_ANSEL_FREESTYLE_MODE = "1";
static const char *g_pszRemappedName_ANSEL_FREESTYLE_MODE = "D3DOGL_27152819";
static const char *g_pszMainDocs_ANSEL_FREESTYLE_MODE = "List of supported FreeStyle modes";

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLED)[] =
{
    "MULTIPLAYER_DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_APPROVED_ONLY)[] =
{
    "APPROVED_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_APPROVED_ONLY)[] =
{
    "MULTIPLAYER_APPROVED_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_EXTRA_BUFFERS)[] =
{
    "MULTIPLAYER_DISABLE_EXTRA_BUFFERS",
    NULL
};

static const char * (g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_DEPTH)[] =
{
    "MULTIPLAYER_DISABLE_DEPTH",
    NULL
};

DataValueDWORD g_aDefineData_ANSEL_FREESTYLE_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_DISABLED, 0x0000 , "Ansel freestyle mode is not allowed" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_ENABLED, 0x0001 , "Takes precedence over all other bits" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLED, 0x0002 , "Disabled in multiplayer/network activity" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_APPROVED_ONLY, 0x0004 , "Restrict to NV-approved filters" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_APPROVED_ONLY, 0x0008 , "Restrict to MultiPlayer-approved filters" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_EXTRA_BUFFERS, 0x0010 , "Disable all special buffers, including depth" },
    { (const char **)g_ppszDefineDataNames_ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_DEPTH, 0x0020 , "Disable depth" },
};

DataDefaultDWORD g_aDefaultData_ANSEL_FREESTYLE_MODE[] =
{
    {"DEFAULT", 0x0000, "" }, 
};

SettingDWORD g_setting_ANSEL_FREESTYLE_MODE(
    0x105e2a1d,
    g_pszKeyName_ANSEL_FREESTYLE_MODE,
    g_pszRemappedName_ANSEL_FREESTYLE_MODE,
    g_pszMainDocs_ANSEL_FREESTYLE_MODE,
    g_pszDefinedWhen_ANSEL_FREESTYLE_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ANSEL_FREESTYLE_MODE, 
    7, 
    g_aDefaultData_ANSEL_FREESTYLE_MODE, 
    1 
);

static const char *g_pszKeyName_APIINDICATOR = "APIINDICATOR";
static const char *g_pszDefinedWhen_APIINDICATOR = "1";
static const char *g_pszRemappedName_APIINDICATOR = "D3DOGL_111baea9";
static const char *g_pszMainDocs_APIINDICATOR = "Display the API version indicator";

static const char * (g_ppszDefineDataNames_APIINDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_APIINDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_APIINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_APIINDICATOR_OFF, 0x0 , "Disable API version indicator" },
    { (const char **)g_ppszDefineDataNames_APIINDICATOR_ON, 0x1 , "Enable API version indicator" },
};

DataDefaultDWORD g_aDefaultData_APIINDICATOR[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_APIINDICATOR(
    0x107b1e3d,
    g_pszKeyName_APIINDICATOR,
    g_pszRemappedName_APIINDICATOR,
    g_pszMainDocs_APIINDICATOR,
    g_pszDefinedWhen_APIINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_APIINDICATOR, 
    2, 
    g_aDefaultData_APIINDICATOR, 
    1 
);

static const char *g_pszKeyName_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT = "APPLICATION_PROFILE_NOTIFICATION_TIMEOUT";
static const char *g_pszDefinedWhen_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT = "1";
static const char *g_pszRemappedName_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT = "D3DOGL_4554b6";
static const char *g_pszMainDocs_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT = "This setting specifies how many seconds the popup displaying information about which profile is being applied should appear. Zero counts as disabled.";

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "ZERO",
    NULL
};

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_NINE_SECONDS)[] =
{
    "NINE_SECONDS",
    NULL
};

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_FIFTEEN_SECONDS)[] =
{
    "FIFTEEN_SECONDS",
    NULL
};

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_THIRTY_SECONDS)[] =
{
    "THIRTY_SECONDS",
    NULL
};

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ONE_MINUTE)[] =
{
    "ONE_MINUTE",
    NULL
};

static const char * (g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_TWO_MINUTES)[] =
{
    "TWO_MINUTES",
    NULL
};

DataValueDWORD g_aDefineData_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT[] =
{
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED, 0 , "This value disables the popup from appearing." },
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_NINE_SECONDS, 9 , "The popup will appear for 9 seconds" },
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_FIFTEEN_SECONDS, 15 , "The popup will appear for 15 seconds" },
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_THIRTY_SECONDS, 30 , "The popup will appear for 30 seconds" },
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ONE_MINUTE, 60 , "The popup will appear for 1 minute" },
    { (const char **)g_ppszDefineDataNames_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_TWO_MINUTES, 120 , "The popup will appear for 2 minutes" },
};

DataDefaultDWORD g_aDefaultData_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT(
    0x104554b6,
    g_pszKeyName_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT,
    g_pszRemappedName_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT,
    g_pszMainDocs_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT,
    g_pszDefinedWhen_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT, 
    6, 
    g_aDefaultData_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT, 
    1 
);

static const char *g_pszKeyName_APPLICATION_STEAM_ID = "APPLICATION_STEAM_ID";
static const char *g_pszDefinedWhen_APPLICATION_STEAM_ID = "1";
static const char *g_pszRemappedName_APPLICATION_STEAM_ID = "D3DOGL_7cddbc";
static const char *g_pszMainDocs_APPLICATION_STEAM_ID = "Steam Application ID is used to identify which Steam applications are installed";

DataDefaultDWORD g_aDefaultData_APPLICATION_STEAM_ID[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_APPLICATION_STEAM_ID(
    0x107cddbc,
    g_pszKeyName_APPLICATION_STEAM_ID,
    g_pszRemappedName_APPLICATION_STEAM_ID,
    g_pszMainDocs_APPLICATION_STEAM_ID,
    g_pszDefinedWhen_APPLICATION_STEAM_ID,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_APPLICATION_STEAM_ID, 
    1 
);

static const char *g_pszKeyName_AUTOFL = "AUTOFL";
static const char *g_pszDefinedWhen_AUTOFL = "1";
static const char *g_pszRemappedName_AUTOFL = "D3DOGL_C0009600";
static const char *g_pszMainDocs_AUTOFL = "Enable AutoFL support.";

static const char * (g_ppszDefineDataNames_AUTOFL_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_AUTOFL_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_AUTOFL[] =
{
    { (const char **)g_ppszDefineDataNames_AUTOFL_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_AUTOFL_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_AUTOFL[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_AUTOFL(
    0x10834ffe,
    g_pszKeyName_AUTOFL,
    g_pszRemappedName_AUTOFL,
    g_pszMainDocs_AUTOFL,
    g_pszDefinedWhen_AUTOFL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_AUTOFL, 
    2, 
    g_aDefaultData_AUTOFL, 
    1 
);

static const char *g_pszKeyName_BATTERY_BOOST = "BATTERY_BOOST";
static const char *g_pszDefinedWhen_BATTERY_BOOST = "1";
static const char *g_pszRemappedName_BATTERY_BOOST = "D3DOGL_f1846870";
static const char *g_pszMainDocs_BATTERY_BOOST = "Enables the Battery Boost functionality, cap FPS for DC mode only";

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_XQM)[] =
{
    "XQM",
    NULL
};

DataValueDWORD g_aDefineData_BATTERY_BOOST[] =
{
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_MAX, 0x000003ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_ENABLED, 0x10000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_XQM, 0x1000001e , "External Quiet Mode Setting" },
};

DataDefaultDWORD g_aDefaultData_BATTERY_BOOST[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_BATTERY_BOOST(
    0x10115c89,
    g_pszKeyName_BATTERY_BOOST,
    g_pszRemappedName_BATTERY_BOOST,
    g_pszMainDocs_BATTERY_BOOST,
    g_pszDefinedWhen_BATTERY_BOOST,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_BATTERY_BOOST, 
    5, 
    g_aDefaultData_BATTERY_BOOST, 
    1 
);

static const char *g_pszKeyName_BATTERY_BOOST_APP_FPS = "BATTERY_BOOST_APP_FPS";
static const char *g_pszDefinedWhen_BATTERY_BOOST_APP_FPS = "1";
static const char *g_pszRemappedName_BATTERY_BOOST_APP_FPS = "D3DOGL_f1846873";
static const char *g_pszMainDocs_BATTERY_BOOST_APP_FPS = "Override FPS for Battery Boost, can be set differently for each application";

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_NO_OVERRIDE)[] =
{
    "NO_OVERRIDE",
    NULL
};

DataValueDWORD g_aDefineData_BATTERY_BOOST_APP_FPS[] =
{
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_MAX, 0x000003ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_BATTERY_BOOST_APP_FPS_NO_OVERRIDE, 0x00000000 , "No override" },
};

DataDefaultDWORD g_aDefaultData_BATTERY_BOOST_APP_FPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_BATTERY_BOOST_APP_FPS(
    0x10115c8c,
    g_pszKeyName_BATTERY_BOOST_APP_FPS,
    g_pszRemappedName_BATTERY_BOOST_APP_FPS,
    g_pszMainDocs_BATTERY_BOOST_APP_FPS,
    g_pszDefinedWhen_BATTERY_BOOST_APP_FPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_BATTERY_BOOST_APP_FPS, 
    3, 
    g_aDefaultData_BATTERY_BOOST_APP_FPS, 
    1 
);

static const char *g_pszKeyName_BG_FRL_FPS = "BG_FRL_FPS";
static const char *g_pszDefinedWhen_BG_FRL_FPS = "1";
static const char *g_pszRemappedName_BG_FRL_FPS = "D3DOGL_00008608";
static const char *g_pszMainDocs_BG_FRL_FPS = "Background Application Max Frame Rate";

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_BG_FRL_FPS[] =
{
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_MAX, 0x000003ff , "" },
};

DataDefaultDWORD g_aDefaultData_BG_FRL_FPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_BG_FRL_FPS(
    0x10835005,
    g_pszKeyName_BG_FRL_FPS,
    g_pszRemappedName_BG_FRL_FPS,
    g_pszMainDocs_BG_FRL_FPS,
    g_pszDefinedWhen_BG_FRL_FPS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_BG_FRL_FPS, 
    3, 
    g_aDefaultData_BG_FRL_FPS, 
    1 
);

static const char *g_pszKeyName_BG_FRL_FPS_NVCPL = "BG_FRL_FPS_NVCPL";
static const char *g_pszDefinedWhen_BG_FRL_FPS_NVCPL = "1";
static const char *g_pszRemappedName_BG_FRL_FPS_NVCPL = "D3DOGL_00008609";
static const char *g_pszMainDocs_BG_FRL_FPS_NVCPL = "Background Application Max Frame Rate for NVCPL ";

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_BG_FRL_FPS_NVCPL[] =
{
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_BG_FRL_FPS_NVCPL_MAX, 0x000003ff , "" },
};

DataDefaultDWORD g_aDefaultData_BG_FRL_FPS_NVCPL[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_BG_FRL_FPS_NVCPL(
    0x10835006,
    g_pszKeyName_BG_FRL_FPS_NVCPL,
    g_pszRemappedName_BG_FRL_FPS_NVCPL,
    g_pszMainDocs_BG_FRL_FPS_NVCPL,
    g_pszDefinedWhen_BG_FRL_FPS_NVCPL,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_BG_FRL_FPS_NVCPL, 
    3, 
    g_aDefaultData_BG_FRL_FPS_NVCPL, 
    1 
);

static const char *g_pszKeyName_CBF_THRESHOLD = "CBF_THRESHOLD";
static const char *g_pszDefinedWhen_CBF_THRESHOLD = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CBF_THRESHOLD = "D3DOGL_48576894";
static const char *g_pszMainDocs_CBF_THRESHOLD = "Min number of scalar vertex shader inputs to enable CBF (see bug 501556)";

static const char * (g_ppszDefineDataNames_CBF_THRESHOLD_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_CBF_THRESHOLD_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_CBF_THRESHOLD[] =
{
    { (const char **)g_ppszDefineDataNames_CBF_THRESHOLD_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CBF_THRESHOLD_MAX, 0xffffffff , "" },
};

DataDefaultDWORD g_aDefaultData_CBF_THRESHOLD[] =
{
    {"DEFAULT", 12, "" }, 
};

SettingDWORD g_setting_CBF_THRESHOLD(
    0x10291d8e,
    g_pszKeyName_CBF_THRESHOLD,
    g_pszRemappedName_CBF_THRESHOLD,
    g_pszMainDocs_CBF_THRESHOLD,
    g_pszDefinedWhen_CBF_THRESHOLD,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_CBF_THRESHOLD, 
    2, 
    g_aDefaultData_CBF_THRESHOLD, 
    1 
);

static const char *g_pszKeyName_CB_ALPHA_CACHELINES_PER_SM = "CB_ALPHA_CACHELINES_PER_SM";
static const char *g_pszDefinedWhen_CB_ALPHA_CACHELINES_PER_SM = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CB_ALPHA_CACHELINES_PER_SM = "D3DOGL_FF54EC98";
static const char *g_pszMainDocs_CB_ALPHA_CACHELINES_PER_SM = "Sets the number of cachelines per SM we request for alpha circular buffers. Zero means to use driver default.";

static const char * (g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MIN)[] =
{
    "MIN",
    "AUTOMATIC",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_FERMI_MAX)[] =
{
    "FERMI_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MAXWELL_MAX)[] =
{
    "MAXWELL_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_PASCAL_MAX)[] =
{
    "PASCAL_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_CB_ALPHA_CACHELINES_PER_SM[] =
{
    { (const char **)g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_FERMI_MAX, 0x000003ff , "" },
    { (const char **)g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MAXWELL_MAX, 0x000003fff , "" },
    { (const char **)g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_PASCAL_MAX, 0x000003fffff , "" },
    { (const char **)g_ppszDefineDataNames_CB_ALPHA_CACHELINES_PER_SM_MAX, 0x000003fffff , "" },
};

DataDefaultDWORD g_aDefaultData_CB_ALPHA_CACHELINES_PER_SM[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_CB_ALPHA_CACHELINES_PER_SM(
    0x1080b678,
    g_pszKeyName_CB_ALPHA_CACHELINES_PER_SM,
    g_pszRemappedName_CB_ALPHA_CACHELINES_PER_SM,
    g_pszMainDocs_CB_ALPHA_CACHELINES_PER_SM,
    g_pszDefinedWhen_CB_ALPHA_CACHELINES_PER_SM,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_CB_ALPHA_CACHELINES_PER_SM, 
    5, 
    g_aDefaultData_CB_ALPHA_CACHELINES_PER_SM, 
    1 
);

static const char *g_pszKeyName_CB_CACHELINES_PER_SM = "CB_CACHELINES_PER_SM";
static const char *g_pszDefinedWhen_CB_CACHELINES_PER_SM = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CB_CACHELINES_PER_SM = "D3DOGL_FF54EC97";
static const char *g_pszMainDocs_CB_CACHELINES_PER_SM = "Sets the number of cachelines per SM we request for circular buffers. Zero means to use driver default.";

static const char * (g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MIN)[] =
{
    "MIN",
    "AUTOMATIC",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_CACHELINES_PER_SM_FERMI_MAX)[] =
{
    "FERMI_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MAXWELL_MAX)[] =
{
    "MAXWELL_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_CACHELINES_PER_SM_PASCAL_MAX)[] =
{
    "PASCAL_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_CB_CACHELINES_PER_SM[] =
{
    { (const char **)g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CB_CACHELINES_PER_SM_FERMI_MAX, 0x000003ff , "" },
    { (const char **)g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MAXWELL_MAX, 0x000003fff , "" },
    { (const char **)g_ppszDefineDataNames_CB_CACHELINES_PER_SM_PASCAL_MAX, 0x000003fffff , "" },
    { (const char **)g_ppszDefineDataNames_CB_CACHELINES_PER_SM_MAX, 0x000003fffff , "" },
};

DataDefaultDWORD g_aDefaultData_CB_CACHELINES_PER_SM[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_CB_CACHELINES_PER_SM(
    0x1080b677,
    g_pszKeyName_CB_CACHELINES_PER_SM,
    g_pszRemappedName_CB_CACHELINES_PER_SM,
    g_pszMainDocs_CB_CACHELINES_PER_SM,
    g_pszDefinedWhen_CB_CACHELINES_PER_SM,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_CB_CACHELINES_PER_SM, 
    5, 
    g_aDefaultData_CB_CACHELINES_PER_SM, 
    1 
);

static const char *g_pszKeyName_COLLECTGFEINFO = "COLLECTGFEINFO";
static const char *g_pszDefinedWhen_COLLECTGFEINFO = "1";
static const char *g_pszRemappedName_COLLECTGFEINFO = "D3DOGL_50273967";
static const char *g_pszMainDocs_COLLECTGFEINFO = "Switches to enable/disable GFE data collection";

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_GFE_MS_PER_FRAME_HIST)[] =
{
    "GFE_MS_PER_FRAME_HIST",
    NULL
};

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_GFE_MS_PER_FRAME_DERIV_HIST)[] =
{
    "GFE_MS_PER_FRAME_DERIV_HIST",
    NULL
};

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_GFE_PSTATE_HIST)[] =
{
    "GFE_PSTATE_HIST",
    NULL
};

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_GFE_PCT_BATTERY)[] =
{
    "GFE_PCT_BATTERY",
    NULL
};

static const char * (g_ppszDefineDataNames_COLLECTGFEINFO_GFE_STEREO_INFO)[] =
{
    "GFE_STEREO_INFO",
    NULL
};

DataValueDWORD g_aDefineData_COLLECTGFEINFO[] =
{
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_DISABLE, 0x00000000 , "The default mode, the driver will collect no data." },
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_GFE_MS_PER_FRAME_HIST, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_GFE_MS_PER_FRAME_DERIV_HIST, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_GFE_PSTATE_HIST, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_GFE_PCT_BATTERY, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_COLLECTGFEINFO_GFE_STEREO_INFO, 0x00000010 , "" },
};

DataDefaultDWORD g_aDefaultData_COLLECTGFEINFO[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_COLLECTGFEINFO(
    0x1088513a,
    g_pszKeyName_COLLECTGFEINFO,
    g_pszRemappedName_COLLECTGFEINFO,
    g_pszMainDocs_COLLECTGFEINFO,
    g_pszDefinedWhen_COLLECTGFEINFO,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_COLLECTGFEINFO, 
    6, 
    g_aDefaultData_COLLECTGFEINFO, 
    1 
);

static const char *g_pszKeyName_COMPILER_KNOBS = "COMPILER_KNOBS";
static const char *g_pszDefinedWhen_COMPILER_KNOBS = "1";
static const char *g_pszRemappedName_COMPILER_KNOBS = "D3DOGL_0xe6a55a";
static const char *g_pszMainDocs_COMPILER_KNOBS = "String for passing compiler knobs, deprecates OCGCONTROL_KNOBS_STRING.";

DataDefaultSTRING g_aDefaultData_COMPILER_KNOBS[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_COMPILER_KNOBS(
    0x10e6855a,
    g_pszKeyName_COMPILER_KNOBS,
    g_pszRemappedName_COMPILER_KNOBS,
    g_pszMainDocs_COMPILER_KNOBS,
    g_pszDefinedWhen_COMPILER_KNOBS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_COMPILER_KNOBS, 
    1 
);

static const char *g_pszKeyName_COMPILER_STATS_FILE = "COMPILER_STATS_FILE";
static const char *g_pszDefinedWhen_COMPILER_STATS_FILE = "1";
static const char *g_pszRemappedName_COMPILER_STATS_FILE = "D3DOGL_0xe0389b";
static const char *g_pszMainDocs_COMPILER_STATS_FILE = "File where Compiler Stats will be written.";

DataDefaultSTRING g_aDefaultData_COMPILER_STATS_FILE[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_COMPILER_STATS_FILE(
    0x10e0089b,
    g_pszKeyName_COMPILER_STATS_FILE,
    g_pszRemappedName_COMPILER_STATS_FILE,
    g_pszMainDocs_COMPILER_STATS_FILE,
    g_pszDefinedWhen_COMPILER_STATS_FILE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_COMPILER_STATS_FILE, 
    1 
);

static const char *g_pszKeyName_COMPILER_STATS_LEVEL = "COMPILER_STATS_LEVEL";
static const char *g_pszDefinedWhen_COMPILER_STATS_LEVEL = "1";
static const char *g_pszRemappedName_COMPILER_STATS_LEVEL = "D3DOGL_0xe0388b";
static const char *g_pszMainDocs_COMPILER_STATS_LEVEL = "Control support for Granularity of Dumping Compile Time and Memory Usage of CGC and OCG Compiler.";

static const char * (g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL0)[] =
{
    "LEVEL0",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL1)[] =
{
    "LEVEL1",
    NULL
};

static const char * (g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL2)[] =
{
    "LEVEL2",
    NULL
};

static const char * (g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL3)[] =
{
    "LEVEL3",
    NULL
};

static const char * (g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL4)[] =
{
    "LEVEL4",
    NULL
};

DataValueDWORD g_aDefineData_COMPILER_STATS_LEVEL[] =
{
    { (const char **)g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL0, 0x0 , "Disable." },
    { (const char **)g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL1, 0x1 , "Level 1 Profiling" },
    { (const char **)g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL2, 0X2 , "Level 2 Profiling" },
    { (const char **)g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL3, 0X3 , "Level 3 Profiling" },
    { (const char **)g_ppszDefineDataNames_COMPILER_STATS_LEVEL_LEVEL4, 0X4 , "Level 4 Profiling" },
};

DataDefaultDWORD g_aDefaultData_COMPILER_STATS_LEVEL[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_COMPILER_STATS_LEVEL(
    0x10e0088b,
    g_pszKeyName_COMPILER_STATS_LEVEL,
    g_pszRemappedName_COMPILER_STATS_LEVEL,
    g_pszMainDocs_COMPILER_STATS_LEVEL,
    g_pszDefinedWhen_COMPILER_STATS_LEVEL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_COMPILER_STATS_LEVEL, 
    5, 
    g_aDefaultData_COMPILER_STATS_LEVEL, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_ENABLE = "CONSTANT_COLOR_RENDERING_ENABLE";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_ENABLE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_ENABLE = "D3DOGL_c0457a47";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_ENABLE = "When set to ENABLED, the driver will enable the hardware's constant color rendering feature on chips that support it (beginning with GK20A).";

static const char * (g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

DataValueDWORD g_aDefineData_CONSTANT_COLOR_RENDERING_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_ENABLE_ON, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_ENABLE_OFF, 0x00000000 , "" },
};

DataDefaultDWORD g_aDefaultData_CONSTANT_COLOR_RENDERING_ENABLE[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_CONSTANT_COLOR_RENDERING_ENABLE(
    0x10f20b10,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_ENABLE,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_ENABLE,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_ENABLE,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CONSTANT_COLOR_RENDERING_ENABLE, 
    2, 
    g_aDefaultData_CONSTANT_COLOR_RENDERING_ENABLE, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA = "CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA = "D3DOGL_c0457a9c";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA = "Constant color override for alpha channel.";

DataDefaultFLOAT g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA[] =
{
    {"DEFAULT", 1.0f, "" }, 
};

SettingFLOAT g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA(
    0x10937ecb,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE = "CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE = "D3DOGL_c0457a8b";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE = "Constant color override for blue channel.";

DataDefaultFLOAT g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE[] =
{
    {"DEFAULT", 1.0f, "" }, 
};

SettingFLOAT g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE(
    0x1019a5fe,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE = "CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE = "D3DOGL_c0457a58";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE = "When set to ENABLED, the color used for any constant color rendering will be overridden with the color specified by CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_{RED,GREEN,BLUE,ALPHA}.";

static const char * (g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

DataValueDWORD g_aDefineData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_ON, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_OFF, 0x00000000 , "" },
};

DataDefaultDWORD g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE(
    0x10c04a01,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE, 
    2, 
    g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN = "CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN = "D3DOGL_c0457a7a";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN = "Constant color override for green channel.";

DataDefaultFLOAT g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN[] =
{
    {"DEFAULT", 0.0f, "" }, 
};

SettingFLOAT g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN(
    0x10d825e1,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN, 
    1 
);

static const char *g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED = "CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED";
static const char *g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED = "D3DOGL_c0457a69";
static const char *g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED = "Constant color override for red channel.";

DataDefaultFLOAT g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED[] =
{
    {"DEFAULT", 1.0f, "" }, 
};

SettingFLOAT g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED(
    0x1012afd6,
    g_pszKeyName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED,
    g_pszRemappedName_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED,
    g_pszMainDocs_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED,
    g_pszDefinedWhen_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED, 
    1 
);

static const char *g_pszKeyName_CONSUMER_STEREO_ENABLE = "CONSUMER_STEREO_ENABLE";
static const char *g_pszDefinedWhen_CONSUMER_STEREO_ENABLE = "1";
static const char *g_pszRemappedName_CONSUMER_STEREO_ENABLE = "D3DOGL_EnableConsumerStereoSupport";
static const char *g_pszMainDocs_CONSUMER_STEREO_ENABLE = "";

static const char * (g_ppszDefineDataNames_CONSUMER_STEREO_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_CONSUMER_STEREO_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_CONSUMER_STEREO_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_CONSUMER_STEREO_ENABLE_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_CONSUMER_STEREO_ENABLE_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_CONSUMER_STEREO_ENABLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_CONSUMER_STEREO_ENABLE(
    0x10c8e380,
    g_pszKeyName_CONSUMER_STEREO_ENABLE,
    g_pszRemappedName_CONSUMER_STEREO_ENABLE,
    g_pszMainDocs_CONSUMER_STEREO_ENABLE,
    g_pszDefinedWhen_CONSUMER_STEREO_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CONSUMER_STEREO_ENABLE, 
    2, 
    g_aDefaultData_CONSUMER_STEREO_ENABLE, 
    1 
);

static const char *g_pszKeyName_CONTROLFLOWGUARD_ENABLE = "CONTROLFLOWGUARD_ENABLE";
static const char *g_pszDefinedWhen_CONTROLFLOWGUARD_ENABLE = "1";
static const char *g_pszRemappedName_CONTROLFLOWGUARD_ENABLE = "D3DOGL_73163701";
static const char *g_pszMainDocs_CONTROLFLOWGUARD_ENABLE = "Toggle CFG on or off (For release, default is ON else default is OFF)";

static const char * (g_ppszDefineDataNames_CONTROLFLOWGUARD_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_CONTROLFLOWGUARD_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_CONTROLFLOWGUARD_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_CONTROLFLOWGUARD_ENABLE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_CONTROLFLOWGUARD_ENABLE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_CONTROLFLOWGUARD_ENABLE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_CONTROLFLOWGUARD_ENABLE(
    0x1053e972,
    g_pszKeyName_CONTROLFLOWGUARD_ENABLE,
    g_pszRemappedName_CONTROLFLOWGUARD_ENABLE,
    g_pszMainDocs_CONTROLFLOWGUARD_ENABLE,
    g_pszDefinedWhen_CONTROLFLOWGUARD_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CONTROLFLOWGUARD_ENABLE, 
    2, 
    g_aDefaultData_CONTROLFLOWGUARD_ENABLE, 
    1 
);

static const char *g_pszKeyName_COPROC_STAGING_BUFFER_PLACEMENT = "COPROC_STAGING_BUFFER_PLACEMENT";
static const char *g_pszDefinedWhen_COPROC_STAGING_BUFFER_PLACEMENT = "1";
static const char *g_pszRemappedName_COPROC_STAGING_BUFFER_PLACEMENT = "D3DOGL_30008600";
static const char *g_pszMainDocs_COPROC_STAGING_BUFFER_PLACEMENT = "Controls the placement of the staging buffer.";

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_DEFAULT_WITH_FALLBACK)[] =
{
    "DEFAULT_WITH_FALLBACK",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_APERTURE_ONLY)[] =
{
    "APERTURE_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_SYSMEM_ONLY)[] =
{
    "SYSMEM_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_HALLOC_ONLY)[] =
{
    "HALLOC_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUCOPY_ONLY)[] =
{
    "CPUCOPY_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2COPY_ONLY)[] =
{
    "CPUSSE2COPY_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD1_ONLY)[] =
{
    "CPUSSE2THREAD1_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD2_ONLY)[] =
{
    "CPUSSE2THREAD2_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD4_ONLY)[] =
{
    "CPUSSE2THREAD4_ONLY",
    NULL
};

DataValueDWORD g_aDefineData_COPROC_STAGING_BUFFER_PLACEMENT[] =
{
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_DEFAULT_WITH_FALLBACK, 0x00000000 , "Prefer Aperture memory, with fallback" },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_APERTURE_ONLY, 0x00000001 , "Aperture placement only." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_SYSMEM_ONLY, 0x00000002 , "Force system mem only." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_HALLOC_ONLY, 0x00000003 , "Using KMT hAllocation for present." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUCOPY_ONLY, 0x00000004 , "Use CPU Copy with memcpy." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2COPY_ONLY, 0x00000005 , "Use CPU Copy with SSE2 memcpy." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD1_ONLY, 0x00000006 , "Use CPU Copy with 1 thread." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD2_ONLY, 0x00000007 , "Use CPU Copy with 2 threads." },
    { (const char **)g_ppszDefineDataNames_COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD4_ONLY, 0x00000008 , "Use CPU Copy with 4 threads." },
};

DataDefaultDWORD g_aDefaultData_COPROC_STAGING_BUFFER_PLACEMENT[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_COPROC_STAGING_BUFFER_PLACEMENT(
    0x10038600,
    g_pszKeyName_COPROC_STAGING_BUFFER_PLACEMENT,
    g_pszRemappedName_COPROC_STAGING_BUFFER_PLACEMENT,
    g_pszMainDocs_COPROC_STAGING_BUFFER_PLACEMENT,
    g_pszDefinedWhen_COPROC_STAGING_BUFFER_PLACEMENT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_COPROC_STAGING_BUFFER_PLACEMENT, 
    9, 
    g_aDefaultData_COPROC_STAGING_BUFFER_PLACEMENT, 
    1 
);

static const char *g_pszKeyName_COPROC_WINSAT_SPLIT = "COPROC_WINSAT_SPLIT";
static const char *g_pszDefinedWhen_COPROC_WINSAT_SPLIT = "1";
static const char *g_pszRemappedName_COPROC_WINSAT_SPLIT = "D3DOGL_20008600";
static const char *g_pszMainDocs_COPROC_WINSAT_SPLIT = "Used to control winsat dwm/d3d determination";

static const char * (g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_IGPU_ONLY)[] =
{
    "IGPU_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_DGPU_ONLY)[] =
{
    "DGPU_ONLY",
    NULL
};

DataValueDWORD g_aDefineData_COPROC_WINSAT_SPLIT[] =
{
    { (const char **)g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_DISABLE, 0x00000000 , "Do not split dwm/d3d tests." },
    { (const char **)g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_ENABLE, 0x00000001 , "Split dwm/d3d tests." },
    { (const char **)g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_IGPU_ONLY, 0x00000002 , "Direct all winsat tests onto iGPU." },
    { (const char **)g_ppszDefineDataNames_COPROC_WINSAT_SPLIT_DGPU_ONLY, 0x00000003 , "Direct all winsat tests onto dGPU." },
};

DataDefaultDWORD g_aDefaultData_COPROC_WINSAT_SPLIT[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_COPROC_WINSAT_SPLIT(
    0x10028600,
    g_pszKeyName_COPROC_WINSAT_SPLIT,
    g_pszRemappedName_COPROC_WINSAT_SPLIT,
    g_pszMainDocs_COPROC_WINSAT_SPLIT,
    g_pszDefinedWhen_COPROC_WINSAT_SPLIT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_COPROC_WINSAT_SPLIT, 
    4, 
    g_aDefaultData_COPROC_WINSAT_SPLIT, 
    1 
);

static const char *g_pszKeyName_CPL_HIDDEN_PROFILE = "CPL_HIDDEN_PROFILE";
static const char *g_pszDefinedWhen_CPL_HIDDEN_PROFILE = "1";
static const char *g_pszRemappedName_CPL_HIDDEN_PROFILE = "D3DOGL_6d5cff";
static const char *g_pszMainDocs_CPL_HIDDEN_PROFILE = "This setting indicates to the Control Panel that a given profile should not be displayed.";

static const char * (g_ppszDefineDataNames_CPL_HIDDEN_PROFILE_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_CPL_HIDDEN_PROFILE_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_CPL_HIDDEN_PROFILE[] =
{
    { (const char **)g_ppszDefineDataNames_CPL_HIDDEN_PROFILE_DISABLED, 0 , "" },
    { (const char **)g_ppszDefineDataNames_CPL_HIDDEN_PROFILE_ENABLED, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_CPL_HIDDEN_PROFILE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_CPL_HIDDEN_PROFILE(
    0x106d5cff,
    g_pszKeyName_CPL_HIDDEN_PROFILE,
    g_pszRemappedName_CPL_HIDDEN_PROFILE,
    g_pszMainDocs_CPL_HIDDEN_PROFILE,
    g_pszDefinedWhen_CPL_HIDDEN_PROFILE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CPL_HIDDEN_PROFILE, 
    2, 
    g_aDefaultData_CPL_HIDDEN_PROFILE, 
    1 
);

static const char *g_pszKeyName_CROP_L2_CACHE_CONTROL = "CROP_L2_CACHE_CONTROL";
static const char *g_pszDefinedWhen_CROP_L2_CACHE_CONTROL = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CROP_L2_CACHE_CONTROL = "D3DOGL_0x1fd4";
static const char *g_pszMainDocs_CROP_L2_CACHE_CONTROL = "Each nibble controls the CROP L2 cache policy for particular operations on the CROP clients. Ada+ architectures only";

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_FIRST)[] =
{
    "CROP_NONINTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "CROP_NONINTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_LAST)[] =
{
    "CROP_NONINTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_SHIFT)[] =
{
    "CROP_NONINTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_FIRST)[] =
{
    "CROP_INTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "CROP_INTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_LAST)[] =
{
    "CROP_INTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_SHIFT)[] =
{
    "CROP_INTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_FIRST)[] =
{
    "CROP_PREFETCH_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_NORMAL)[] =
{
    "CROP_PREFETCH_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_LAST)[] =
{
    "CROP_PREFETCH_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_SHIFT)[] =
{
    "CROP_PREFETCH_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "CROP_NONINTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "CROP_NONINTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "CROP_NONINTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_SHIFT)[] =
{
    "CROP_NONINTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "CROP_INTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "CROP_INTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "CROP_INTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_SHIFT)[] =
{
    "CROP_INTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_USE_LEGACY)[] =
{
    "USE_LEGACY",
    NULL
};

DataValueDWORD g_aDefineData_CROP_L2_CACHE_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_NORMAL, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_LAST, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_SHIFT, 0 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_NORMAL, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_LAST, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_SHIFT, 4 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_NORMAL, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_LAST, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_SHIFT, 8 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_NORMAL, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_LAST, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_SHIFT, 12 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_NORMAL, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_LAST, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_SHIFT, 16 , "" },
    { (const char **)g_ppszDefineDataNames_CROP_L2_CACHE_CONTROL_USE_LEGACY, 0x00100000 , "Use values specified by FERMI_SET_L2_CACHE_CONTROL" },
};

DataDefaultDWORD g_aDefaultData_CROP_L2_CACHE_CONTROL[] =
{
    {"DEFAULT", 0x00100000, "" }, 
};

SettingDWORD g_setting_CROP_L2_CACHE_CONTROL(
    0x10001fd4,
    g_pszKeyName_CROP_L2_CACHE_CONTROL,
    g_pszRemappedName_CROP_L2_CACHE_CONTROL,
    g_pszMainDocs_CROP_L2_CACHE_CONTROL,
    g_pszDefinedWhen_CROP_L2_CACHE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_CROP_L2_CACHE_CONTROL, 
    21, 
    g_aDefaultData_CROP_L2_CACHE_CONTROL, 
    1 
);

static const char *g_pszKeyName_CUDA_EXCLUDED_GPUS = "CUDA_EXCLUDED_GPUS";
static const char *g_pszDefinedWhen_CUDA_EXCLUDED_GPUS = "1";
static const char *g_pszRemappedName_CUDA_EXCLUDED_GPUS = "D3DOGL_19103765";
static const char *g_pszMainDocs_CUDA_EXCLUDED_GPUS = "Unicode string containing a list of Universal GPU ids, item separator is ';'. Exposed in UI as 'CUDA - GPUs'.";

static const char * (g_ppszDefineDataNames_CUDA_EXCLUDED_GPUS_NONE)[] =
{
    "NONE",
    NULL
};

DataValueWSTRING g_aDefineData_CUDA_EXCLUDED_GPUS[] =
{
    { (const char **)g_ppszDefineDataNames_CUDA_EXCLUDED_GPUS_NONE, L"none" , "" },
};

DataDefaultWSTRING g_aDefaultData_CUDA_EXCLUDED_GPUS[] =
{
    {"DEFAULT", L"none", "" }, 
};

SettingWSTRING g_setting_CUDA_EXCLUDED_GPUS(
    0x10354ff8,
    g_pszKeyName_CUDA_EXCLUDED_GPUS,
    g_pszRemappedName_CUDA_EXCLUDED_GPUS,
    g_pszMainDocs_CUDA_EXCLUDED_GPUS,
    g_pszDefinedWhen_CUDA_EXCLUDED_GPUS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CUDA_EXCLUDED_GPUS, 
    1, 
    g_aDefaultData_CUDA_EXCLUDED_GPUS, 
    1 
);

static const char *g_pszKeyName_CULL_BEFORE_FETCH = "CULL_BEFORE_FETCH";
static const char *g_pszDefinedWhen_CULL_BEFORE_FETCH = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_CULL_BEFORE_FETCH = "D3DOGL_48576893";
static const char *g_pszMainDocs_CULL_BEFORE_FETCH = "value for Cull Before Fetch (after Fermi)";

static const char * (g_ppszDefineDataNames_CULL_BEFORE_FETCH_DYNAMIC)[] =
{
    "DYNAMIC",
    NULL
};

static const char * (g_ppszDefineDataNames_CULL_BEFORE_FETCH_ALWAYS)[] =
{
    "ALWAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_CULL_BEFORE_FETCH_NEVER)[] =
{
    "NEVER",
    NULL
};

static const char * (g_ppszDefineDataNames_CULL_BEFORE_FETCH_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_CULL_BEFORE_FETCH_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_CULL_BEFORE_FETCH[] =
{
    { (const char **)g_ppszDefineDataNames_CULL_BEFORE_FETCH_DYNAMIC, 0x00000006 , "" },
    { (const char **)g_ppszDefineDataNames_CULL_BEFORE_FETCH_ALWAYS, 0x00000007 , "" },
    { (const char **)g_ppszDefineDataNames_CULL_BEFORE_FETCH_NEVER, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_CULL_BEFORE_FETCH_MIN, 0x00000006 , "" },
    { (const char **)g_ppszDefineDataNames_CULL_BEFORE_FETCH_MAX, 0x00000008 , "" },
};

DataDefaultDWORD g_aDefaultData_CULL_BEFORE_FETCH[] =
{
    {"DEFAULT", 0x00000006, "" }, 
};

SettingDWORD g_setting_CULL_BEFORE_FETCH(
    0x10510e76,
    g_pszKeyName_CULL_BEFORE_FETCH,
    g_pszRemappedName_CULL_BEFORE_FETCH,
    g_pszMainDocs_CULL_BEFORE_FETCH,
    g_pszDefinedWhen_CULL_BEFORE_FETCH,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_CULL_BEFORE_FETCH, 
    5, 
    g_aDefaultData_CULL_BEFORE_FETCH, 
    1 
);

static const char *g_pszKeyName_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION = "D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION";
static const char *g_pszDefinedWhen_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION = "1";
static const char *g_pszRemappedName_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION = "OGL_c9d12c";
static const char *g_pszMainDocs_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION = "Control where OGL driver should store the shader disk cache files";

static const char * (g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL)[] =
{
    "LOCAL",
    NULL
};

static const char * (g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL_LOW)[] =
{
    "LOCAL_LOW",
    NULL
};

DataValueDWORD g_aDefineData_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION[] =
{
    { (const char **)g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_AUTOSELECT, 0x00000000 , "Let driver decide the shader cache location based on process integrity levels" },
    { (const char **)g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL, 0x00000001 , "Force to use LOCAL folder (only for debug and make sure untrusty process cannot create cache)" },
    { (const char **)g_ppszDefineDataNames_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL_LOW, 0x00000002 , "Force to use LOCALLOW folder (only for debug and make sure trusty process can still create cache)" },
};

DataDefaultDWORD g_aDefaultData_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION(
    0x10c9d12c,
    g_pszKeyName_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION,
    g_pszRemappedName_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION,
    g_pszMainDocs_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION,
    g_pszDefinedWhen_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION, 
    3, 
    g_aDefaultData_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION, 
    1 
);

static const char *g_pszKeyName_D3DOGL_GPU_MAX_POWER = "D3DOGL_GPU_MAX_POWER";
static const char *g_pszDefinedWhen_D3DOGL_GPU_MAX_POWER = "1";
static const char *g_pszRemappedName_D3DOGL_GPU_MAX_POWER = "D3dOGL_GpuMaxPower";
static const char *g_pszMainDocs_D3DOGL_GPU_MAX_POWER = "Maximum power, that GPU is allowed to use";

static const char * (g_ppszDefineDataNames_D3DOGL_GPU_MAX_POWER_DEFAULTPOWER)[] =
{
    "DEFAULTPOWER",
    NULL
};

DataValueWSTRING g_aDefineData_D3DOGL_GPU_MAX_POWER[] =
{
    { (const char **)g_ppszDefineDataNames_D3DOGL_GPU_MAX_POWER_DEFAULTPOWER, L"0" , "" },
};

DataDefaultWSTRING g_aDefaultData_D3DOGL_GPU_MAX_POWER[] =
{
    {"DEFAULT", L"0", "" }, 
};

SettingWSTRING g_setting_D3DOGL_GPU_MAX_POWER(
    0x10d1ef29,
    g_pszKeyName_D3DOGL_GPU_MAX_POWER,
    g_pszRemappedName_D3DOGL_GPU_MAX_POWER,
    g_pszMainDocs_D3DOGL_GPU_MAX_POWER,
    g_pszDefinedWhen_D3DOGL_GPU_MAX_POWER,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_D3DOGL_GPU_MAX_POWER, 
    1, 
    g_aDefaultData_D3DOGL_GPU_MAX_POWER, 
    1 
);

static const char *g_pszKeyName_D3DOGL_SANDBAG_DEVICEID = "D3DOGL_SANDBAG_DEVICEID";
static const char *g_pszDefinedWhen_D3DOGL_SANDBAG_DEVICEID = "1";
static const char *g_pszRemappedName_D3DOGL_SANDBAG_DEVICEID = "OGL_0x054eeb";
static const char *g_pszMainDocs_D3DOGL_SANDBAG_DEVICEID = "Treat given devId as being part of the sandbag devId list.  All follow-on allow/deny mechanisms still apply.  Intended to test new sandbag allow/deny mechanisms on any GPU.";

static const char * (g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_DEVID_MASK)[] =
{
    "DEVID_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_DEVID_ANY)[] =
{
    "DEVID_ANY",
    NULL
};

static const char * (g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_IGNORE_ALLOW_LIST)[] =
{
    "IGNORE_ALLOW_LIST",
    NULL
};

DataValueDWORD g_aDefineData_D3DOGL_SANDBAG_DEVICEID[] =
{
    { (const char **)g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_DEVID_MASK, 0x00ffffff , "mask for devId to be sandbagged" },
    { (const char **)g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_DEVID_ANY, 0x00ffffff , "use this pseudo devId to sandbag all devIds" },
    { (const char **)g_ppszDefineDataNames_D3DOGL_SANDBAG_DEVICEID_IGNORE_ALLOW_LIST, 0x01000000 , "If devId is sandbagged by this key, then it controls whether allowlist should be ignored." },
};

DataDefaultDWORD g_aDefaultData_D3DOGL_SANDBAG_DEVICEID[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_D3DOGL_SANDBAG_DEVICEID(
    0x10054eeb,
    g_pszKeyName_D3DOGL_SANDBAG_DEVICEID,
    g_pszRemappedName_D3DOGL_SANDBAG_DEVICEID,
    g_pszMainDocs_D3DOGL_SANDBAG_DEVICEID,
    g_pszDefinedWhen_D3DOGL_SANDBAG_DEVICEID,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_D3DOGL_SANDBAG_DEVICEID, 
    3, 
    g_aDefaultData_D3DOGL_SANDBAG_DEVICEID, 
    1 
);

static const char *g_pszKeyName_D3DOGL_UNSANDBAG_VIEWPERF = "D3DOGL_UNSANDBAG_VIEWPERF";
static const char *g_pszDefinedWhen_D3DOGL_UNSANDBAG_VIEWPERF = "1";
static const char *g_pszRemappedName_D3DOGL_UNSANDBAG_VIEWPERF = "OGL_0x749c79";
static const char *g_pszMainDocs_D3DOGL_UNSANDBAG_VIEWPERF = "Unsandbag Viewperf.";

static const char * (g_ppszDefineDataNames_D3DOGL_UNSANDBAG_VIEWPERF_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_D3DOGL_UNSANDBAG_VIEWPERF_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_D3DOGL_UNSANDBAG_VIEWPERF[] =
{
    { (const char **)g_ppszDefineDataNames_D3DOGL_UNSANDBAG_VIEWPERF_DISABLE, 0 , "No special handling for Viewperf." },
    { (const char **)g_ppszDefineDataNames_D3DOGL_UNSANDBAG_VIEWPERF_ENABLE, 0xe25aba79 , "unsandbag Viewperf" },
};

DataDefaultDWORD g_aDefaultData_D3DOGL_UNSANDBAG_VIEWPERF[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_D3DOGL_UNSANDBAG_VIEWPERF(
    0x10749c79,
    g_pszKeyName_D3DOGL_UNSANDBAG_VIEWPERF,
    g_pszRemappedName_D3DOGL_UNSANDBAG_VIEWPERF,
    g_pszMainDocs_D3DOGL_UNSANDBAG_VIEWPERF,
    g_pszDefinedWhen_D3DOGL_UNSANDBAG_VIEWPERF,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_D3DOGL_UNSANDBAG_VIEWPERF, 
    2, 
    g_aDefaultData_D3DOGL_UNSANDBAG_VIEWPERF, 
    1 
);

static const char *g_pszKeyName_DACACHELINESIZE = "DACACHELINESIZE";
static const char *g_pszDefinedWhen_DACACHELINESIZE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_DACACHELINESIZE = "D3DOGL_74095218";
static const char *g_pszMainDocs_DACACHELINESIZE = "value for NV5097_SET_DA_ATTRIBUTE_CACHE_LINE method";

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_BYTES128)[] =
{
    "BYTES128",
    NULL
};

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_BYTES64)[] =
{
    "BYTES64",
    NULL
};

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_BYTES32)[] =
{
    "BYTES32",
    NULL
};

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_DYNAMIC)[] =
{
    "DYNAMIC",
    NULL
};

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_DACACHELINESIZE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_DACACHELINESIZE[] =
{
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_BYTES128, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_BYTES64, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_BYTES32, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_DYNAMIC, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_DACACHELINESIZE_MAX, 0x00000003 , "" },
};

DataDefaultDWORD g_aDefaultData_DACACHELINESIZE[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_DACACHELINESIZE(
    0x10148135,
    g_pszKeyName_DACACHELINESIZE,
    g_pszRemappedName_DACACHELINESIZE,
    g_pszMainDocs_DACACHELINESIZE,
    g_pszDefinedWhen_DACACHELINESIZE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DACACHELINESIZE, 
    6, 
    g_aDefaultData_DACACHELINESIZE, 
    1 
);

static const char *g_pszKeyName_DEFAULT_ALLOC_LIST_SIZE = "DEFAULT_ALLOC_LIST_SIZE";
static const char *g_pszDefinedWhen_DEFAULT_ALLOC_LIST_SIZE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_DEFAULT_ALLOC_LIST_SIZE = "D3DOGL_60025699";
static const char *g_pszMainDocs_DEFAULT_ALLOC_LIST_SIZE = "to set the initial Alloc list size used by KMD. If not set, driver defaults to 0x00 for all Channel types. Will work only on debug & develop drivers.";

DataDefaultDWORD g_aDefaultData_DEFAULT_ALLOC_LIST_SIZE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_DEFAULT_ALLOC_LIST_SIZE(
    0x10b55c79,
    g_pszKeyName_DEFAULT_ALLOC_LIST_SIZE,
    g_pszRemappedName_DEFAULT_ALLOC_LIST_SIZE,
    g_pszMainDocs_DEFAULT_ALLOC_LIST_SIZE,
    g_pszDefinedWhen_DEFAULT_ALLOC_LIST_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_DEFAULT_ALLOC_LIST_SIZE, 
    1 
);

static const char *g_pszKeyName_DEFAULT_PATCH_LIST_SIZE = "DEFAULT_PATCH_LIST_SIZE";
static const char *g_pszDefinedWhen_DEFAULT_PATCH_LIST_SIZE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_DEFAULT_PATCH_LIST_SIZE = "D3DOGL_60025688";
static const char *g_pszMainDocs_DEFAULT_PATCH_LIST_SIZE = "to set the initial Patch list size used by KMD. If not set, driver defaults to 0x400 for 3D Channel & 0x200 for rest of the Channel types. Will work only on debug & develop drivers.";

DataDefaultDWORD g_aDefaultData_DEFAULT_PATCH_LIST_SIZE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_DEFAULT_PATCH_LIST_SIZE(
    0x10c55d78,
    g_pszKeyName_DEFAULT_PATCH_LIST_SIZE,
    g_pszRemappedName_DEFAULT_PATCH_LIST_SIZE,
    g_pszMainDocs_DEFAULT_PATCH_LIST_SIZE,
    g_pszDefinedWhen_DEFAULT_PATCH_LIST_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_DEFAULT_PATCH_LIST_SIZE, 
    1 
);

static const char *g_pszKeyName_DISABLE_ALLOCINUSE_WAR_MSHYBRID = "DISABLE_ALLOCINUSE_WAR_MSHYBRID";
static const char *g_pszDefinedWhen_DISABLE_ALLOCINUSE_WAR_MSHYBRID = "1";
static const char *g_pszRemappedName_DISABLE_ALLOCINUSE_WAR_MSHYBRID = "D3DOGL_2022013";
static const char *g_pszMainDocs_DISABLE_ALLOCINUSE_WAR_MSHYBRID = "Disable AllocInUse WAR on MS hybrid";

static const char * (g_ppszDefineDataNames_DISABLE_ALLOCINUSE_WAR_MSHYBRID_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_DISABLE_ALLOCINUSE_WAR_MSHYBRID_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_DISABLE_ALLOCINUSE_WAR_MSHYBRID[] =
{
    { (const char **)g_ppszDefineDataNames_DISABLE_ALLOCINUSE_WAR_MSHYBRID_DISABLED, 0x0 , "WAR is NOT disabled" },
    { (const char **)g_ppszDefineDataNames_DISABLE_ALLOCINUSE_WAR_MSHYBRID_ENABLED, 0x1 , "WAR is disabled" },
};

DataDefaultDWORD g_aDefaultData_DISABLE_ALLOCINUSE_WAR_MSHYBRID[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_DISABLE_ALLOCINUSE_WAR_MSHYBRID(
    0x10fadc97,
    g_pszKeyName_DISABLE_ALLOCINUSE_WAR_MSHYBRID,
    g_pszRemappedName_DISABLE_ALLOCINUSE_WAR_MSHYBRID,
    g_pszMainDocs_DISABLE_ALLOCINUSE_WAR_MSHYBRID,
    g_pszDefinedWhen_DISABLE_ALLOCINUSE_WAR_MSHYBRID,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISABLE_ALLOCINUSE_WAR_MSHYBRID, 
    2, 
    g_aDefaultData_DISABLE_ALLOCINUSE_WAR_MSHYBRID, 
    1 
);

static const char *g_pszKeyName_DISABLE_MSHYBRID_SYNC_ON_RRI = "DISABLE_MSHYBRID_SYNC_ON_RRI";
static const char *g_pszDefinedWhen_DISABLE_MSHYBRID_SYNC_ON_RRI = "1";
static const char *g_pszRemappedName_DISABLE_MSHYBRID_SYNC_ON_RRI = "D3DOGL_200189347";
static const char *g_pszMainDocs_DISABLE_MSHYBRID_SYNC_ON_RRI = "No sync between 3D and CE from RRI on MS hybrid";

static const char * (g_ppszDefineDataNames_DISABLE_MSHYBRID_SYNC_ON_RRI_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_DISABLE_MSHYBRID_SYNC_ON_RRI_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_DISABLE_MSHYBRID_SYNC_ON_RRI[] =
{
    { (const char **)g_ppszDefineDataNames_DISABLE_MSHYBRID_SYNC_ON_RRI_DISABLED, 0x0 , " sync between 3D and CE from RRI on MS hybrid" },
    { (const char **)g_ppszDefineDataNames_DISABLE_MSHYBRID_SYNC_ON_RRI_ENABLED, 0x1 , "No sync between 3D and CE from RRI on MS hybrid" },
};

DataDefaultDWORD g_aDefaultData_DISABLE_MSHYBRID_SYNC_ON_RRI[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_DISABLE_MSHYBRID_SYNC_ON_RRI(
    0x10fadc86,
    g_pszKeyName_DISABLE_MSHYBRID_SYNC_ON_RRI,
    g_pszRemappedName_DISABLE_MSHYBRID_SYNC_ON_RRI,
    g_pszMainDocs_DISABLE_MSHYBRID_SYNC_ON_RRI,
    g_pszDefinedWhen_DISABLE_MSHYBRID_SYNC_ON_RRI,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISABLE_MSHYBRID_SYNC_ON_RRI, 
    2, 
    g_aDefaultData_DISABLE_MSHYBRID_SYNC_ON_RRI, 
    1 
);

static const char *g_pszKeyName_DISABLE_POST_L2_COMPRESSION = "DISABLE_POST_L2_COMPRESSION";
static const char *g_pszDefinedWhen_DISABLE_POST_L2_COMPRESSION = "1";
static const char *g_pszRemappedName_DISABLE_POST_L2_COMPRESSION = "D3D_20200910";
static const char *g_pszMainDocs_DISABLE_POST_L2_COMPRESSION = "Disable Post-L2 Compression (PLC) on Turing+.";

static const char * (g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_NEVER)[] =
{
    "NEVER",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_ALWAYS)[] =
{
    "ALWAYS",
    "ON",
    "1",
    "TRUE",
    NULL
};

static const char * (g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_DISABLE_IF_BUG_3046774)[] =
{
    "DISABLE_IF_BUG_3046774",
    NULL
};

DataValueDWORD g_aDefineData_DISABLE_POST_L2_COMPRESSION[] =
{
    { (const char **)g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_NEVER, 0x00000000 , "Enable PLC on all hardware that supports it." },
    { (const char **)g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_ALWAYS, 0x00000001 , "If set, disable PLC on all hardware." },
    { (const char **)g_ppszDefineDataNames_DISABLE_POST_L2_COMPRESSION_DISABLE_IF_BUG_3046774, 0x00000002 , "If set, disable PLC on hardware affected by bug 3046774." },
};

DataDefaultDWORD g_aDefaultData_DISABLE_POST_L2_COMPRESSION[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_DISABLE_POST_L2_COMPRESSION(
    0x101218cf,
    g_pszKeyName_DISABLE_POST_L2_COMPRESSION,
    g_pszRemappedName_DISABLE_POST_L2_COMPRESSION,
    g_pszMainDocs_DISABLE_POST_L2_COMPRESSION,
    g_pszDefinedWhen_DISABLE_POST_L2_COMPRESSION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_DISABLE_POST_L2_COMPRESSION, 
    3, 
    g_aDefaultData_DISABLE_POST_L2_COMPRESSION, 
    1 
);

static const char *g_pszKeyName_DISABLE_USER_DVM = "DISABLE_USER_DVM";
static const char *g_pszDefinedWhen_DISABLE_USER_DVM = "1";
static const char *g_pszRemappedName_DISABLE_USER_DVM = "D3DOGL_09090909";
static const char *g_pszMainDocs_DISABLE_USER_DVM = "";

static const char * (g_ppszDefineDataNames_DISABLE_USER_DVM_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_DISABLE_USER_DVM_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_DISABLE_USER_DVM[] =
{
    { (const char **)g_ppszDefineDataNames_DISABLE_USER_DVM_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_DISABLE_USER_DVM_ON, 0x00000001 , "" },
};

SettingDWORD g_setting_DISABLE_USER_DVM(
    0x101ae753,
    g_pszKeyName_DISABLE_USER_DVM,
    g_pszRemappedName_DISABLE_USER_DVM,
    g_pszMainDocs_DISABLE_USER_DVM,
    g_pszDefinedWhen_DISABLE_USER_DVM,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISABLE_USER_DVM, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_DISPLAYMUX_INDICATOR = "DISPLAYMUX_INDICATOR";
static const char *g_pszDefinedWhen_DISPLAYMUX_INDICATOR = "1";
static const char *g_pszRemappedName_DISPLAYMUX_INDICATOR = "D3DOGL_2521863";
static const char *g_pszMainDocs_DISPLAYMUX_INDICATOR = "Display the Display Mux State Indicator";

static const char * (g_ppszDefineDataNames_DISPLAYMUX_INDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAYMUX_INDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAYMUX_INDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAYMUX_INDICATOR_OFF, 0x0 , "Disable Display Mux State Indicator" },
    { (const char **)g_ppszDefineDataNames_DISPLAYMUX_INDICATOR_ON, 0x1 , "Enable Display Mux State Indicator" },
};

DataDefaultDWORD g_aDefaultData_DISPLAYMUX_INDICATOR[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_DISPLAYMUX_INDICATOR(
    0x10029540,
    g_pszKeyName_DISPLAYMUX_INDICATOR,
    g_pszRemappedName_DISPLAYMUX_INDICATOR,
    g_pszMainDocs_DISPLAYMUX_INDICATOR,
    g_pszDefinedWhen_DISPLAYMUX_INDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAYMUX_INDICATOR, 
    2, 
    g_aDefaultData_DISPLAYMUX_INDICATOR, 
    1 
);

static const char *g_pszKeyName_DISPLAY_MUX_SWITCH_FLAGS = "DISPLAY_MUX_SWITCH_FLAGS";
static const char *g_pszDefinedWhen_DISPLAY_MUX_SWITCH_FLAGS = "1";
static const char *g_pszRemappedName_DISPLAY_MUX_SWITCH_FLAGS = "D3DOGL_2677349";
static const char *g_pszMainDocs_DISPLAY_MUX_SWITCH_FLAGS = "Dynamic Display Mux switch flags to control display mux switch behavior.";

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_1_SEC)[] =
{
    "D_TO_I_TIMEOUT_1_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_2_SEC)[] =
{
    "D_TO_I_TIMEOUT_2_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_3_SEC)[] =
{
    "D_TO_I_TIMEOUT_3_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_4_SEC)[] =
{
    "D_TO_I_TIMEOUT_4_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_5_SEC)[] =
{
    "D_TO_I_TIMEOUT_5_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_6_SEC)[] =
{
    "D_TO_I_TIMEOUT_6_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_7_SEC)[] =
{
    "D_TO_I_TIMEOUT_7_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_8_SEC)[] =
{
    "D_TO_I_TIMEOUT_8_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_9_SEC)[] =
{
    "D_TO_I_TIMEOUT_9_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_10_SEC)[] =
{
    "D_TO_I_TIMEOUT_10_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_15_SEC)[] =
{
    "D_TO_I_TIMEOUT_15_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_20_SEC)[] =
{
    "D_TO_I_TIMEOUT_20_SEC",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_NVDLIST)[] =
{
    "MUX_SWITCH_FROM_NVDLIST",
    NULL
};

static const char * (g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_CORE_UMD)[] =
{
    "MUX_SWITCH_FROM_CORE_UMD",
    NULL
};

DataValueDWORD g_aDefineData_DISPLAY_MUX_SWITCH_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_1_SEC, 0x000003E8 , "Set the D to I mux switch timeout delay as 1000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_2_SEC, 0x000007D0 , "Set the D to I mux switch timeout delay as 2000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_3_SEC, 0x00000BB8 , "Set the D to I mux switch timeout delay as 3000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_4_SEC, 0x00000FA0 , "Set the D to I mux switch timeout delay as 4000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_5_SEC, 0x00001388 , "Set the D to I mux switch timeout delay as 5000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_6_SEC, 0x00001770 , "Set the D to I mux switch timeout delay as 6000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_7_SEC, 0x00001B58 , "Set the D to I mux switch timeout delay as 7000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_8_SEC, 0x00001F40 , "Set the D to I mux switch timeout delay as 8000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_9_SEC, 0x00002328 , "Set the D to I mux switch timeout delay as 9000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_10_SEC, 0x00002710 , "Set the D to I mux switch timeout delay as 10000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_15_SEC, 0x00003A98 , "Set the D to I mux switch timeout delay as 15000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_20_SEC, 0x00004E20 , "Set the D to I mux switch timeout delay as 20000 msec" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_NVDLIST, 0x00010000 , "Allow to switch the Mux from NV DList" },
    { (const char **)g_ppszDefineDataNames_DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_CORE_UMD, 0x00020000 , "Allow to switch the Mux from CORE UMD" },
};

DataDefaultDWORD g_aDefaultData_DISPLAY_MUX_SWITCH_FLAGS[] =
{
    {"DEFAULT", 0x00010bb8, "MUX_SWITCH_FROM_NVDLIST | D_TO_I_TIMEOUT_3_SEC" }, 
};

SettingDWORD g_setting_DISPLAY_MUX_SWITCH_FLAGS(
    0x10e75807,
    g_pszKeyName_DISPLAY_MUX_SWITCH_FLAGS,
    g_pszRemappedName_DISPLAY_MUX_SWITCH_FLAGS,
    g_pszMainDocs_DISPLAY_MUX_SWITCH_FLAGS,
    g_pszDefinedWhen_DISPLAY_MUX_SWITCH_FLAGS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DISPLAY_MUX_SWITCH_FLAGS, 
    14, 
    g_aDefaultData_DISPLAY_MUX_SWITCH_FLAGS, 
    1 
);

static const char *g_pszKeyName_DRIVERINFOOVERLAY = "DRIVERINFOOVERLAY";
static const char *g_pszDefinedWhen_DRIVERINFOOVERLAY = "1";
static const char *g_pszRemappedName_DRIVERINFOOVERLAY = "D3DOGL_13975394";
static const char *g_pszMainDocs_DRIVERINFOOVERLAY = "";

static const char * (g_ppszDefineDataNames_DRIVERINFOOVERLAY_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_DRIVERINFOOVERLAY_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_DRIVERINFOOVERLAY[] =
{
    { (const char **)g_ppszDefineDataNames_DRIVERINFOOVERLAY_OFF, 0x34045364 , "" },
    { (const char **)g_ppszDefineDataNames_DRIVERINFOOVERLAY_ON, 0x24554582 , "" },
};

DataDefaultDWORD g_aDefaultData_DRIVERINFOOVERLAY[] =
{
    {"DEFAULT", 0x34045364, "" }, 
};

SettingDWORD g_setting_DRIVERINFOOVERLAY(
    0x104a7524,
    g_pszKeyName_DRIVERINFOOVERLAY,
    g_pszRemappedName_DRIVERINFOOVERLAY,
    g_pszMainDocs_DRIVERINFOOVERLAY,
    g_pszDefinedWhen_DRIVERINFOOVERLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DRIVERINFOOVERLAY, 
    2, 
    g_aDefaultData_DRIVERINFOOVERLAY, 
    1 
);

static const char *g_pszKeyName_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY = "DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY";
static const char *g_pszDefinedWhen_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY = "1";
static const char *g_pszRemappedName_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY = "D3DOGL_16374916";
static const char *g_pszMainDocs_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY = "Default driver policy for Dynamic Display Mux switch, used when neither ALLOW_DYNAMIC_DISPLAY_MUX_SWITCH or DISALLOW_DYNAMIC_DISPLAY_MUX_SWITCH are set in SHIM_RENDERING_OPTIONS. Application profiles should not set this (use SHIM_RENDERING_OPTIONS instead). Note that an applications must still be allowlisted for Optimus to trigger a mux switch.";

static const char * (g_ppszDefineDataNames_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_DISALLOW_BY_DEFAULT)[] =
{
    "DISALLOW_BY_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_ALLOW_BY_DEFAULT)[] =
{
    "ALLOW_BY_DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY[] =
{
    { (const char **)g_ppszDefineDataNames_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_DISALLOW_BY_DEFAULT, 0x00000001 , "Disallow Dynamic Display Mux switch from IGPU to dGPU by default." },
    { (const char **)g_ppszDefineDataNames_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_ALLOW_BY_DEFAULT, 0x00000002 , "Allow Dynamic Display Mux switch from IGPU to dGPU by default." },
};

DataDefaultDWORD g_aDefaultData_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY(
    0x10e75806,
    g_pszKeyName_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY,
    g_pszRemappedName_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY,
    g_pszMainDocs_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY,
    g_pszDefinedWhen_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY, 
    2, 
    g_aDefaultData_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY, 
    1 
);

static const char *g_pszKeyName_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING = "DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING";
static const char *g_pszDefinedWhen_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING = "1";
static const char *g_pszRemappedName_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING = "D3DOGL_16374918";
static const char *g_pszMainDocs_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING = "Driver handling for desktop apps which are launched when Mux is in DGPU and now Mux is switched back from D to I.";

static const char * (g_ppszDefineDataNames_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING[] =
{
    { (const char **)g_ppszDefineDataNames_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_DISABLED, 0x0 , "Disable Driver handling for desktop apps for Mux switch scenarios" },
    { (const char **)g_ppszDefineDataNames_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ENABLED, 0x1 , "Enable Driver handling for desktop apps for Mux switch scenarios" },
};

DataDefaultDWORD g_aDefaultData_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING(
    0x10e75809,
    g_pszKeyName_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING,
    g_pszRemappedName_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING,
    g_pszMainDocs_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING,
    g_pszDefinedWhen_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING, 
    2, 
    g_aDefaultData_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING, 
    1 
);

static const char *g_pszKeyName_EARLYZHYSTERESIS = "EARLYZHYSTERESIS";
static const char *g_pszDefinedWhen_EARLYZHYSTERESIS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_EARLYZHYSTERESIS = "D3DOGL_74095215";
static const char *g_pszMainDocs_EARLYZHYSTERESIS = "Tesla: value set directly in the NV5097_SET_EARLY_Z_HYSTERESIS method (sets hysteresis values for transitioning from LateZ mode to EarlyZ mode)\nFermi+\\DX10+: disables EarlyZ when LATEZ_ALWAYS is set";

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS_INSTANTANEOUS)[] =
{
    "INSTANTANEOUS",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__16)[] =
{
    "_16",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__32)[] =
{
    "_32",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__64)[] =
{
    "_64",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__128)[] =
{
    "_128",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__256)[] =
{
    "_256",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__512)[] =
{
    "_512",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__1024)[] =
{
    "_1024",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__2048)[] =
{
    "_2048",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__4096)[] =
{
    "_4096",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__8192)[] =
{
    "_8192",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__16384)[] =
{
    "_16384",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__32768)[] =
{
    "_32768",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS__65536)[] =
{
    "_65536",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS_LATEZ_INFINITE)[] =
{
    "LATEZ_INFINITE",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZHYSTERESIS_LATEZ_ALWAYS)[] =
{
    "LATEZ_ALWAYS",
    NULL
};

DataValueDWORD g_aDefineData_EARLYZHYSTERESIS[] =
{
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS_INSTANTANEOUS, 0x0 , "Hardware makes instantaneous EarlyZ/LateZ decision based on current state" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__16, 0x1 , "Hardware waits 16 nvclk cycles before enabling EarlyZ mode" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__32, 0x2 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__64, 0x3 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__128, 0x4 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__256, 0x5 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__512, 0x6 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__1024, 0x7 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__2048, 0x8 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__4096, 0x9 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__8192, 0xa , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__16384, 0xb , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__32768, 0xc , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS__65536, 0xd , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS_LATEZ_INFINITE, 0xe , "If mode settings force LateZ mode stay in LateZ mode forever" },
    { (const char **)g_ppszDefineDataNames_EARLYZHYSTERESIS_LATEZ_ALWAYS, 0xf , "Always operate in LateZ mode" },
};

SettingDWORD g_setting_EARLYZHYSTERESIS(
    0x1073e558,
    g_pszKeyName_EARLYZHYSTERESIS,
    g_pszRemappedName_EARLYZHYSTERESIS,
    g_pszMainDocs_EARLYZHYSTERESIS,
    g_pszDefinedWhen_EARLYZHYSTERESIS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_EARLYZHYSTERESIS, 
    16, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_EARLYZ_EXPERIMENTS = "EARLYZ_EXPERIMENTS";
static const char *g_pszDefinedWhen_EARLYZ_EXPERIMENTS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_EARLYZ_EXPERIMENTS = "D3DOGL_74099215";
static const char *g_pszMainDocs_EARLYZ_EXPERIMENTS = "";

static const char * (g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_FORCE_EARLYZ)[] =
{
    "FORCE_EARLYZ",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_DEFAULTS)[] =
{
    "DEFAULTS",
    NULL
};

DataValueDWORD g_aDefineData_EARLYZ_EXPERIMENTS[] =
{
    { (const char **)g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_FORCE_EARLYZ, 0x00000001 , "force alpha-test off in the case where it disables EarlyZ" },
    { (const char **)g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_MASK, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_EARLYZ_EXPERIMENTS_DEFAULTS, 0x00000000 , "" },
};

DataDefaultDWORD g_aDefaultData_EARLYZ_EXPERIMENTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_EARLYZ_EXPERIMENTS(
    0x10dd5f61,
    g_pszKeyName_EARLYZ_EXPERIMENTS,
    g_pszRemappedName_EARLYZ_EXPERIMENTS,
    g_pszMainDocs_EARLYZ_EXPERIMENTS,
    g_pszDefinedWhen_EARLYZ_EXPERIMENTS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_EARLYZ_EXPERIMENTS, 
    3, 
    g_aDefaultData_EARLYZ_EXPERIMENTS, 
    1 
);

static const char *g_pszKeyName_ENABLE_ASYNC_WIN32_CALLS = "ENABLE_ASYNC_WIN32_CALLS";
static const char *g_pszDefinedWhen_ENABLE_ASYNC_WIN32_CALLS = "1";
static const char *g_pszRemappedName_ENABLE_ASYNC_WIN32_CALLS = "D3DOGL_1242273";
static const char *g_pszMainDocs_ENABLE_ASYNC_WIN32_CALLS = "Enable creation of a dedicated worker thread to make win32 system calls asynchronously";

static const char * (g_ppszDefineDataNames_ENABLE_ASYNC_WIN32_CALLS_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_ASYNC_WIN32_CALLS_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_ASYNC_WIN32_CALLS[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_ASYNC_WIN32_CALLS_DISABLED, 0x0 , "Disable async system calls" },
    { (const char **)g_ppszDefineDataNames_ENABLE_ASYNC_WIN32_CALLS_ENABLED, 0x1 , "Enable async system calls" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_ASYNC_WIN32_CALLS[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_ENABLE_ASYNC_WIN32_CALLS(
    0x10fadc98,
    g_pszKeyName_ENABLE_ASYNC_WIN32_CALLS,
    g_pszRemappedName_ENABLE_ASYNC_WIN32_CALLS,
    g_pszMainDocs_ENABLE_ASYNC_WIN32_CALLS,
    g_pszDefinedWhen_ENABLE_ASYNC_WIN32_CALLS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_ASYNC_WIN32_CALLS, 
    2, 
    g_aDefaultData_ENABLE_ASYNC_WIN32_CALLS, 
    1 
);

static const char *g_pszKeyName_ENABLE_BLURAY3D = "ENABLE_BLURAY3D";
static const char *g_pszDefinedWhen_ENABLE_BLURAY3D = "1";
static const char *g_pszRemappedName_ENABLE_BLURAY3D = "VIDEO_EnableBluray3D";
static const char *g_pszMainDocs_ENABLE_BLURAY3D = "";

static const char * (g_ppszDefineDataNames_ENABLE_BLURAY3D_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_BLURAY3D_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_BLURAY3D[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_BLURAY3D_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_ENABLE_BLURAY3D_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_BLURAY3D[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_ENABLE_BLURAY3D(
    0x10ad7687,
    g_pszKeyName_ENABLE_BLURAY3D,
    g_pszRemappedName_ENABLE_BLURAY3D,
    g_pszMainDocs_ENABLE_BLURAY3D,
    g_pszDefinedWhen_ENABLE_BLURAY3D,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_BLURAY3D, 
    2, 
    g_aDefaultData_ENABLE_BLURAY3D, 
    1 
);

static const char *g_pszKeyName_ENABLE_CE_COMPONENT_REMAPPING = "ENABLE_CE_COMPONENT_REMAPPING";
static const char *g_pszDefinedWhen_ENABLE_CE_COMPONENT_REMAPPING = "1";
static const char *g_pszRemappedName_ENABLE_CE_COMPONENT_REMAPPING = "D3DOGL_200161427";
static const char *g_pszMainDocs_ENABLE_CE_COMPONENT_REMAPPING = "Enable CE using component remapping for CAS tranfers on MS hybrid in case of format mis-match between src and dst";

static const char * (g_ppszDefineDataNames_ENABLE_CE_COMPONENT_REMAPPING_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_CE_COMPONENT_REMAPPING_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_CE_COMPONENT_REMAPPING[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_COMPONENT_REMAPPING_DISABLED, 0x0 , "Disable CE component remapping" },
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_COMPONENT_REMAPPING_ENABLED, 0x1 , "Enable CE using component remapping for CAS tranfers on MS hybrid in case of format mis-match between src and dst" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_CE_COMPONENT_REMAPPING[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_ENABLE_CE_COMPONENT_REMAPPING(
    0x10fadc94,
    g_pszKeyName_ENABLE_CE_COMPONENT_REMAPPING,
    g_pszRemappedName_ENABLE_CE_COMPONENT_REMAPPING,
    g_pszMainDocs_ENABLE_CE_COMPONENT_REMAPPING,
    g_pszDefinedWhen_ENABLE_CE_COMPONENT_REMAPPING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_CE_COMPONENT_REMAPPING, 
    2, 
    g_aDefaultData_ENABLE_CE_COMPONENT_REMAPPING, 
    1 
);

static const char *g_pszKeyName_ENABLE_CE_DIRECT_FLIP = "ENABLE_CE_DIRECT_FLIP";
static const char *g_pszDefinedWhen_ENABLE_CE_DIRECT_FLIP = "1";
static const char *g_pszRemappedName_ENABLE_CE_DIRECT_FLIP = "D3DOGL_1242272";
static const char *g_pszMainDocs_ENABLE_CE_DIRECT_FLIP = "Enable CE for tranfers on Optimus and MS hybrid for DidectFlip";

static const char * (g_ppszDefineDataNames_ENABLE_CE_DIRECT_FLIP_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_CE_DIRECT_FLIP_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_CE_DIRECT_FLIP[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_DIRECT_FLIP_DISABLED, 0x0 , "Disable CE for tranfers on Optimus and MS hybrid for DidectFlip" },
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_DIRECT_FLIP_ENABLED, 0x1 , "Enable CE for tranfers on Optimus and MS hybrid for DidectFlip" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_CE_DIRECT_FLIP[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_ENABLE_CE_DIRECT_FLIP(
    0x10fadc85,
    g_pszKeyName_ENABLE_CE_DIRECT_FLIP,
    g_pszRemappedName_ENABLE_CE_DIRECT_FLIP,
    g_pszMainDocs_ENABLE_CE_DIRECT_FLIP,
    g_pszDefinedWhen_ENABLE_CE_DIRECT_FLIP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_CE_DIRECT_FLIP, 
    2, 
    g_aDefaultData_ENABLE_CE_DIRECT_FLIP, 
    1 
);

static const char *g_pszKeyName_ENABLE_CE_MS_HYBRID = "ENABLE_CE_MS_HYBRID";
static const char *g_pszDefinedWhen_ENABLE_CE_MS_HYBRID = "1";
static const char *g_pszRemappedName_ENABLE_CE_MS_HYBRID = "D3DOGL_1242271";
static const char *g_pszMainDocs_ENABLE_CE_MS_HYBRID = "Enable CE for tranfers on MS hybrid";

static const char * (g_ppszDefineDataNames_ENABLE_CE_MS_HYBRID_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_CE_MS_HYBRID_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_CE_MS_HYBRID[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_MS_HYBRID_DISABLED, 0x0 , "Disable CE for tranfers on MS hybrid" },
    { (const char **)g_ppszDefineDataNames_ENABLE_CE_MS_HYBRID_ENABLED, 0x1 , "Enable CE for tranfers on MS hybrid" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_CE_MS_HYBRID[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_ENABLE_CE_MS_HYBRID(
    0x10fadc84,
    g_pszKeyName_ENABLE_CE_MS_HYBRID,
    g_pszRemappedName_ENABLE_CE_MS_HYBRID,
    g_pszMainDocs_ENABLE_CE_MS_HYBRID,
    g_pszDefinedWhen_ENABLE_CE_MS_HYBRID,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_CE_MS_HYBRID, 
    2, 
    g_aDefaultData_ENABLE_CE_MS_HYBRID, 
    1 
);

static const char *g_pszKeyName_ENABLE_INVARIANT_RENDERING = "ENABLE_INVARIANT_RENDERING";
static const char *g_pszDefinedWhen_ENABLE_INVARIANT_RENDERING = "1";
static const char *g_pszRemappedName_ENABLE_INVARIANT_RENDERING = "D3DOGL_53d30c";
static const char *g_pszMainDocs_ENABLE_INVARIANT_RENDERING = "disable any strategies that cause LSB differences between frames";

static const char * (g_ppszDefineDataNames_ENABLE_INVARIANT_RENDERING_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_ENABLE_INVARIANT_RENDERING_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_ENABLE_INVARIANT_RENDERING[] =
{
    { (const char **)g_ppszDefineDataNames_ENABLE_INVARIANT_RENDERING_OFF, 91917306 , "off" },
    { (const char **)g_ppszDefineDataNames_ENABLE_INVARIANT_RENDERING_ON, 11519843 , "on" },
};

DataDefaultDWORD g_aDefaultData_ENABLE_INVARIANT_RENDERING[] =
{
    {"DEFAULT", 91917306, "" }, 
};

SettingDWORD g_setting_ENABLE_INVARIANT_RENDERING(
    0x1053d30c,
    g_pszKeyName_ENABLE_INVARIANT_RENDERING,
    g_pszRemappedName_ENABLE_INVARIANT_RENDERING,
    g_pszMainDocs_ENABLE_INVARIANT_RENDERING,
    g_pszDefinedWhen_ENABLE_INVARIANT_RENDERING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ENABLE_INVARIANT_RENDERING, 
    2, 
    g_aDefaultData_ENABLE_INVARIANT_RENDERING, 
    1 
);

static const char *g_pszKeyName_EXPORT_PERF_COUNTERS = "EXPORT_PERF_COUNTERS";
static const char *g_pszDefinedWhen_EXPORT_PERF_COUNTERS = "1";
static const char *g_pszRemappedName_EXPORT_PERF_COUNTERS = "D3DOGL_74095214";
static const char *g_pszMainDocs_EXPORT_PERF_COUNTERS = "";

static const char * (g_ppszDefineDataNames_EXPORT_PERF_COUNTERS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_EXPORT_PERF_COUNTERS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_EXPORT_PERF_COUNTERS[] =
{
    { (const char **)g_ppszDefineDataNames_EXPORT_PERF_COUNTERS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_EXPORT_PERF_COUNTERS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_EXPORT_PERF_COUNTERS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_EXPORT_PERF_COUNTERS(
    0x108f0841,
    g_pszKeyName_EXPORT_PERF_COUNTERS,
    g_pszRemappedName_EXPORT_PERF_COUNTERS,
    g_pszMainDocs_EXPORT_PERF_COUNTERS,
    g_pszDefinedWhen_EXPORT_PERF_COUNTERS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_EXPORT_PERF_COUNTERS, 
    2, 
    g_aDefaultData_EXPORT_PERF_COUNTERS, 
    1 
);

static const char *g_pszKeyName_EXTERNAL_QUIET_MODE = "EXTERNAL_QUIET_MODE";
static const char *g_pszDefinedWhen_EXTERNAL_QUIET_MODE = "1";
static const char *g_pszRemappedName_EXTERNAL_QUIET_MODE = "D3DOGL_f1846874";
static const char *g_pszMainDocs_EXTERNAL_QUIET_MODE = "Separate key for OEM tool to enable Whisper Mode and Battery Boost, so that it will not corrupt (equivalent) GFE settings, and vice versa.";

static const char * (g_ppszDefineDataNames_EXTERNAL_QUIET_MODE_ON)[] =
{
    "ON",
    NULL
};

static const char * (g_ppszDefineDataNames_EXTERNAL_QUIET_MODE_OFF)[] =
{
    "OFF",
    NULL
};

DataValueDWORD g_aDefineData_EXTERNAL_QUIET_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_EXTERNAL_QUIET_MODE_ON, 0x00000001 , "On" },
    { (const char **)g_ppszDefineDataNames_EXTERNAL_QUIET_MODE_OFF, 0x00000000 , "Off" },
};

DataDefaultDWORD g_aDefaultData_EXTERNAL_QUIET_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_EXTERNAL_QUIET_MODE(
    0x10115c8d,
    g_pszKeyName_EXTERNAL_QUIET_MODE,
    g_pszRemappedName_EXTERNAL_QUIET_MODE,
    g_pszMainDocs_EXTERNAL_QUIET_MODE,
    g_pszDefinedWhen_EXTERNAL_QUIET_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_EXTERNAL_QUIET_MODE, 
    2, 
    g_aDefaultData_EXTERNAL_QUIET_MODE, 
    1 
);

static const char *g_pszKeyName_FERMI_DUMP_NVIR_FLAG = "FERMI_DUMP_NVIR_FLAG";
static const char *g_pszDefinedWhen_FERMI_DUMP_NVIR_FLAG = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_FERMI_DUMP_NVIR_FLAG = "D3DOGL_50299698";
static const char *g_pszMainDocs_FERMI_DUMP_NVIR_FLAG = "when set, will notify OCG to generate NVIR & return it in the compiled ucode blob. Will work only on debug & develop drivers.";

static const char * (g_ppszDefineDataNames_FERMI_DUMP_NVIR_FLAG_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_DUMP_NVIR_FLAG_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FERMI_DUMP_NVIR_FLAG[] =
{
    { (const char **)g_ppszDefineDataNames_FERMI_DUMP_NVIR_FLAG_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_DUMP_NVIR_FLAG_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_FERMI_DUMP_NVIR_FLAG[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_FERMI_DUMP_NVIR_FLAG(
    0x105ba0cb,
    g_pszKeyName_FERMI_DUMP_NVIR_FLAG,
    g_pszRemappedName_FERMI_DUMP_NVIR_FLAG,
    g_pszMainDocs_FERMI_DUMP_NVIR_FLAG,
    g_pszDefinedWhen_FERMI_DUMP_NVIR_FLAG,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FERMI_DUMP_NVIR_FLAG, 
    2, 
    g_aDefaultData_FERMI_DUMP_NVIR_FLAG, 
    1 
);

static const char *g_pszKeyName_FERMI_SET_L2_CACHE_CONTROL = "FERMI_SET_L2_CACHE_CONTROL";
static const char *g_pszDefinedWhen_FERMI_SET_L2_CACHE_CONTROL = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_FERMI_SET_L2_CACHE_CONTROL = "_";
static const char *g_pszMainDocs_FERMI_SET_L2_CACHE_CONTROL = "Each nibble controls the L2 cache policy for particular operations on the VAF and ROP clients. Starting Ada+ the ROP bits of this regkey maybe overidden by the CROP_L2_CACHE_CONTROL and/or ZROP_L2_CACHE_CONTROL regkeys";

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_FIRST)[] =
{
    "VAF_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_NORMAL)[] =
{
    "VAF_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_LAST)[] =
{
    "VAF_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_SHIFT)[] =
{
    "VAF_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_FIRST)[] =
{
    "ROP_NONINTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "ROP_NONINTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_LAST)[] =
{
    "ROP_NONINTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_SHIFT)[] =
{
    "ROP_NONINTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_FIRST)[] =
{
    "ROP_INTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "ROP_INTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_LAST)[] =
{
    "ROP_INTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_SHIFT)[] =
{
    "ROP_INTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_FIRST)[] =
{
    "ROP_PREFETCH_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_NORMAL)[] =
{
    "ROP_PREFETCH_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_LAST)[] =
{
    "ROP_PREFETCH_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_SHIFT)[] =
{
    "ROP_PREFETCH_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "ROP_NONINTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "ROP_NONINTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "ROP_NONINTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_SHIFT)[] =
{
    "ROP_NONINTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "ROP_INTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "ROP_INTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "ROP_INTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_SHIFT)[] =
{
    "ROP_INTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_CLASS_DEFAULT)[] =
{
    "CLASS_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_DX10_DEFAULT)[] =
{
    "DX10_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_OGL_DEFAULT)[] =
{
    "OGL_DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_FERMI_SET_L2_CACHE_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_NORMAL, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_LAST, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_VAF_SHIFT, 0 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_NORMAL, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_LAST, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_SHIFT, 4 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_NORMAL, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_LAST, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_SHIFT, 8 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_NORMAL, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_LAST, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_SHIFT, 12 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_NORMAL, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_LAST, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_SHIFT, 16 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_NORMAL, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_LAST, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_SHIFT, 20 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_CLASS_DEFAULT, 0x00101001 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_DX10_DEFAULT, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_L2_CACHE_CONTROL_OGL_DEFAULT, 0x00111111 , "OGL default for perf, see bugs 589224 and 1163844" },
};

DataDefaultDWORD g_aDefaultData_FERMI_SET_L2_CACHE_CONTROL[] =
{
    {"DEFAULT", 0x00101001, "" }, 
};

SettingDWORD g_setting_FERMI_SET_L2_CACHE_CONTROL(
    0x10001fd3,
    g_pszKeyName_FERMI_SET_L2_CACHE_CONTROL,
    g_pszRemappedName_FERMI_SET_L2_CACHE_CONTROL,
    g_pszMainDocs_FERMI_SET_L2_CACHE_CONTROL,
    g_pszDefinedWhen_FERMI_SET_L2_CACHE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_FERMI_SET_L2_CACHE_CONTROL, 
    27, 
    g_aDefaultData_FERMI_SET_L2_CACHE_CONTROL, 
    1 
);

static const char *g_pszKeyName_FERMI_SET_PRIM_CB_THROTTLE = "FERMI_SET_PRIM_CB_THROTTLE";
static const char *g_pszDefinedWhen_FERMI_SET_PRIM_CB_THROTTLE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_FERMI_SET_PRIM_CB_THROTTLE = "D3DOGL_B40D9E03d";
static const char *g_pszMainDocs_FERMI_SET_PRIM_CB_THROTTLE = "For Fermi-generation GPUs, sets max cumulative area (in pixels) of the prims in the CB. Zero means to use driver default. Max is treated as INF, which disabling throttling.";

static const char * (g_ppszDefineDataNames_FERMI_SET_PRIM_CB_THROTTLE_MIN)[] =
{
    "MIN",
    "AUTOMATIC",
    NULL
};

static const char * (g_ppszDefineDataNames_FERMI_SET_PRIM_CB_THROTTLE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_FERMI_SET_PRIM_CB_THROTTLE[] =
{
    { (const char **)g_ppszDefineDataNames_FERMI_SET_PRIM_CB_THROTTLE_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FERMI_SET_PRIM_CB_THROTTLE_MAX, 0x003fffff , "" },
};

DataDefaultDWORD g_aDefaultData_FERMI_SET_PRIM_CB_THROTTLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FERMI_SET_PRIM_CB_THROTTLE(
    0x10951b32,
    g_pszKeyName_FERMI_SET_PRIM_CB_THROTTLE,
    g_pszRemappedName_FERMI_SET_PRIM_CB_THROTTLE,
    g_pszMainDocs_FERMI_SET_PRIM_CB_THROTTLE,
    g_pszDefinedWhen_FERMI_SET_PRIM_CB_THROTTLE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_FERMI_SET_PRIM_CB_THROTTLE, 
    2, 
    g_aDefaultData_FERMI_SET_PRIM_CB_THROTTLE, 
    1 
);

static const char *g_pszKeyName_FERMI_SHADER_HEAP_SIZE = "FERMI_SHADER_HEAP_SIZE";
static const char *g_pszDefinedWhen_FERMI_SHADER_HEAP_SIZE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_FERMI_SHADER_HEAP_SIZE = "D3DOGL_50299699";
static const char *g_pszMainDocs_FERMI_SHADER_HEAP_SIZE = "to set size of the shader heap in bytes. This is only on Fermi. When this is set to a non zero value, Driver will not reclaim space in the heap when deleting a shader. Will work only on debug & develop drivers.";

DataDefaultDWORD g_aDefaultData_FERMI_SHADER_HEAP_SIZE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_FERMI_SHADER_HEAP_SIZE(
    0x10a77a06,
    g_pszKeyName_FERMI_SHADER_HEAP_SIZE,
    g_pszRemappedName_FERMI_SHADER_HEAP_SIZE,
    g_pszMainDocs_FERMI_SHADER_HEAP_SIZE,
    g_pszDefinedWhen_FERMI_SHADER_HEAP_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FERMI_SHADER_HEAP_SIZE, 
    1 
);

static const char *g_pszKeyName_FORCE_FLUSH_ON_ACQUIRE_RESOURCE = "FORCE_FLUSH_ON_ACQUIRE_RESOURCE";
static const char *g_pszDefinedWhen_FORCE_FLUSH_ON_ACQUIRE_RESOURCE = "1";
static const char *g_pszRemappedName_FORCE_FLUSH_ON_ACQUIRE_RESOURCE = "D3DOGL_0x639bc3";
static const char *g_pszMainDocs_FORCE_FLUSH_ON_ACQUIRE_RESOURCE = "Force flush from acquire resource even in case of iflip";

static const char * (g_ppszDefineDataNames_FORCE_FLUSH_ON_ACQUIRE_RESOURCE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FORCE_FLUSH_ON_ACQUIRE_RESOURCE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FORCE_FLUSH_ON_ACQUIRE_RESOURCE[] =
{
    { (const char **)g_ppszDefineDataNames_FORCE_FLUSH_ON_ACQUIRE_RESOURCE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_FORCE_FLUSH_ON_ACQUIRE_RESOURCE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_FORCE_FLUSH_ON_ACQUIRE_RESOURCE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FORCE_FLUSH_ON_ACQUIRE_RESOURCE(
    0x10639bc3,
    g_pszKeyName_FORCE_FLUSH_ON_ACQUIRE_RESOURCE,
    g_pszRemappedName_FORCE_FLUSH_ON_ACQUIRE_RESOURCE,
    g_pszMainDocs_FORCE_FLUSH_ON_ACQUIRE_RESOURCE,
    g_pszDefinedWhen_FORCE_FLUSH_ON_ACQUIRE_RESOURCE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FORCE_FLUSH_ON_ACQUIRE_RESOURCE, 
    2, 
    g_aDefaultData_FORCE_FLUSH_ON_ACQUIRE_RESOURCE, 
    1 
);

static const char *g_pszKeyName_FPSINDICATOR = "FPSINDICATOR";
static const char *g_pszDefinedWhen_FPSINDICATOR = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_FPSINDICATOR = "D3DOGL_13975395";
static const char *g_pszMainDocs_FPSINDICATOR = "Show an FPS counter for the app.";

static const char * (g_ppszDefineDataNames_FPSINDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FPSINDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FPSINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_FPSINDICATOR_OFF, 0x34045364 , "" },
    { (const char **)g_ppszDefineDataNames_FPSINDICATOR_ON, 0x24554582 , "" },
};

DataDefaultDWORD g_aDefaultData_FPSINDICATOR[] =
{
    {"DEFAULT", 0x34045364, "" }, 
};

SettingDWORD g_setting_FPSINDICATOR(
    0x108853e6,
    g_pszKeyName_FPSINDICATOR,
    g_pszRemappedName_FPSINDICATOR,
    g_pszMainDocs_FPSINDICATOR,
    g_pszDefinedWhen_FPSINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FPSINDICATOR, 
    2, 
    g_aDefaultData_FPSINDICATOR, 
    1 
);

static const char *g_pszKeyName_FRL_FPS = "FRL_FPS";
static const char *g_pszDefinedWhen_FRL_FPS = "1";
static const char *g_pszRemappedName_FRL_FPS = "D3DOGL_00008605";
static const char *g_pszMainDocs_FRL_FPS = "Framerate Limiter FPS";

static const char * (g_ppszDefineDataNames_FRL_FPS_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_FPS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_FPS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_FRL_FPS[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_FPS_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_FRL_FPS_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FRL_FPS_MAX, 0x000003ff , "" },
};

DataDefaultDWORD g_aDefaultData_FRL_FPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_FRL_FPS(
    0x10835002,
    g_pszKeyName_FRL_FPS,
    g_pszRemappedName_FRL_FPS,
    g_pszMainDocs_FRL_FPS,
    g_pszDefinedWhen_FRL_FPS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_FRL_FPS, 
    3, 
    g_aDefaultData_FRL_FPS, 
    1 
);

static const char *g_pszKeyName_FRL_FPS_NVCPL = "FRL_FPS_NVCPL";
static const char *g_pszDefinedWhen_FRL_FPS_NVCPL = "1";
static const char *g_pszRemappedName_FRL_FPS_NVCPL = "D3DOGL_0000860A";
static const char *g_pszMainDocs_FRL_FPS_NVCPL = "Framerate Limiter FPS only for NVCPL to maintain the previous slider value when the FRL_FPS is set to Disabled.";

static const char * (g_ppszDefineDataNames_FRL_FPS_NVCPL_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_FPS_NVCPL_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_FPS_NVCPL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_FRL_FPS_NVCPL[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_FPS_NVCPL_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_FRL_FPS_NVCPL_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FRL_FPS_NVCPL_MAX, 0x000003ff , "" },
};

DataDefaultDWORD g_aDefaultData_FRL_FPS_NVCPL[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_FRL_FPS_NVCPL(
    0x1083500a,
    g_pszKeyName_FRL_FPS_NVCPL,
    g_pszRemappedName_FRL_FPS_NVCPL,
    g_pszMainDocs_FRL_FPS_NVCPL,
    g_pszDefinedWhen_FRL_FPS_NVCPL,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_FRL_FPS_NVCPL, 
    3, 
    g_aDefaultData_FRL_FPS_NVCPL, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY = "FRL_LOW_LATENCY";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY = "D3DOGL_00008603";
static const char *g_pszMainDocs_FRL_LOW_LATENCY = "Cap FPS just below GPU render time to reduce latency. DX9+DX11 supported.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    "PASSIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY(
    0x10835000,
    g_pszKeyName_FRL_LOW_LATENCY,
    g_pszRemappedName_FRL_LOW_LATENCY,
    g_pszMainDocs_FRL_LOW_LATENCY,
    g_pszDefinedWhen_FRL_LOW_LATENCY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY, 
    2, 
    g_aDefaultData_FRL_LOW_LATENCY, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_BUFFER = "FRL_LOW_LATENCY_BUFFER";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_BUFFER = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_BUFFER = "D3DOGL_00008604";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_BUFFER = "Buffer time above GPU render time to limit FPS in microseconds. Default 800 (0.8ms).";

SettingDWORD g_setting_FRL_LOW_LATENCY_BUFFER(
    0x10835001,
    g_pszKeyName_FRL_LOW_LATENCY_BUFFER,
    g_pszRemappedName_FRL_LOW_LATENCY_BUFFER,
    g_pszMainDocs_FRL_LOW_LATENCY_BUFFER,
    g_pszDefinedWhen_FRL_LOW_LATENCY_BUFFER,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_BUFFER_MAX = "FRL_LOW_LATENCY_BUFFER_MAX";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_BUFFER_MAX = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_BUFFER_MAX = "D3DOGL_00008647";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_BUFFER_MAX = "Maximum buffer time in microseconds. Default 1500 (1.5ms)";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_BUFFER_MAX[] =
{
    {"DEFAULT", 1500, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_BUFFER_MAX(
    0x1083501f,
    g_pszKeyName_FRL_LOW_LATENCY_BUFFER_MAX,
    g_pszRemappedName_FRL_LOW_LATENCY_BUFFER_MAX,
    g_pszMainDocs_FRL_LOW_LATENCY_BUFFER_MAX,
    g_pszDefinedWhen_FRL_LOW_LATENCY_BUFFER_MAX,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_BUFFER_MAX, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_CPU_RENDER_MARGIN = "FRL_LOW_LATENCY_CPU_RENDER_MARGIN";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_CPU_RENDER_MARGIN = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_CPU_RENDER_MARGIN = "D3DOGL_00008623";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_CPU_RENDER_MARGIN = "Reflex's CPU Render Thread Bound Optimization settings.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_MASK_US)[] =
{
    "MASK_US",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_EXCLUDE_OVERLAP)[] =
{
    "EXCLUDE_OVERLAP",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_TEST_ENABLE)[] =
{
    "TEST_ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY_CPU_RENDER_MARGIN[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_MASK_US, 0x000003ff , "Mask for margin in microseconds" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_EXCLUDE_OVERLAP, 0x10000000 , "Exclude overlap between sim and render" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_CPU_RENDER_MARGIN_TEST_ENABLE, 0x08000000 , "Enable test mode" },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_CPU_RENDER_MARGIN[] =
{
    {"DEFAULT", 0x0000012c, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_CPU_RENDER_MARGIN(
    0x1083500b,
    g_pszKeyName_FRL_LOW_LATENCY_CPU_RENDER_MARGIN,
    g_pszRemappedName_FRL_LOW_LATENCY_CPU_RENDER_MARGIN,
    g_pszMainDocs_FRL_LOW_LATENCY_CPU_RENDER_MARGIN,
    g_pszDefinedWhen_FRL_LOW_LATENCY_CPU_RENDER_MARGIN,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY_CPU_RENDER_MARGIN, 
    3, 
    g_aDefaultData_FRL_LOW_LATENCY_CPU_RENDER_MARGIN, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_GAIN_A = "FRL_LOW_LATENCY_GAIN_A";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_GAIN_A = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_GAIN_A = "D3DOGL_00008606";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_GAIN_A = "LLFRL controller gain A.";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_GAIN_A[] =
{
    {"DEFAULT", 500, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_GAIN_A(
    0x10835003,
    g_pszKeyName_FRL_LOW_LATENCY_GAIN_A,
    g_pszRemappedName_FRL_LOW_LATENCY_GAIN_A,
    g_pszMainDocs_FRL_LOW_LATENCY_GAIN_A,
    g_pszDefinedWhen_FRL_LOW_LATENCY_GAIN_A,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_GAIN_A, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_GAIN_B = "FRL_LOW_LATENCY_GAIN_B";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_GAIN_B = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_GAIN_B = "D3DOGL_00008607";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_GAIN_B = "LLFRL controller gain B.";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_GAIN_B[] =
{
    {"DEFAULT", 20, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_GAIN_B(
    0x10835004,
    g_pszKeyName_FRL_LOW_LATENCY_GAIN_B,
    g_pszRemappedName_FRL_LOW_LATENCY_GAIN_B,
    g_pszMainDocs_FRL_LOW_LATENCY_GAIN_B,
    g_pszDefinedWhen_FRL_LOW_LATENCY_GAIN_B,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_GAIN_B, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_GAP_TARGET = "FRL_LOW_LATENCY_GAP_TARGET";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_GAP_TARGET = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_GAP_TARGET = "D3DOGL_00008620";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_GAP_TARGET = "LLFRL controller target gap time in microseconds.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_GAP_TARGET_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_GAP_TARGET_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY_GAP_TARGET[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_GAP_TARGET_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_GAP_TARGET_MAX, 0x000003e8 , "" },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_GAP_TARGET[] =
{
    {"DEFAULT", 100, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_GAP_TARGET(
    0x10835008,
    g_pszKeyName_FRL_LOW_LATENCY_GAP_TARGET,
    g_pszRemappedName_FRL_LOW_LATENCY_GAP_TARGET,
    g_pszMainDocs_FRL_LOW_LATENCY_GAP_TARGET,
    g_pszDefinedWhen_FRL_LOW_LATENCY_GAP_TARGET,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY_GAP_TARGET, 
    2, 
    g_aDefaultData_FRL_LOW_LATENCY_GAP_TARGET, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_MAX_SLEEP_PCT = "FRL_LOW_LATENCY_MAX_SLEEP_PCT";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_MAX_SLEEP_PCT = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_MAX_SLEEP_PCT = "D3DOGL_00008646";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_MAX_SLEEP_PCT = "Maximum percentage of sleep for Reflex. 0 == just spinloop and 100 == no limit";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_MAX_SLEEP_PCT[] =
{
    {"DEFAULT", 48, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_MAX_SLEEP_PCT(
    0x1083501e,
    g_pszKeyName_FRL_LOW_LATENCY_MAX_SLEEP_PCT,
    g_pszRemappedName_FRL_LOW_LATENCY_MAX_SLEEP_PCT,
    g_pszMainDocs_FRL_LOW_LATENCY_MAX_SLEEP_PCT,
    g_pszDefinedWhen_FRL_LOW_LATENCY_MAX_SLEEP_PCT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_MAX_SLEEP_PCT, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_OVERLAP_TARGET = "FRL_LOW_LATENCY_OVERLAP_TARGET";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_OVERLAP_TARGET = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_OVERLAP_TARGET = "D3DOGL_00008619";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_OVERLAP_TARGET = "LLFRL controller target overlap time in microseconds.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_OVERLAP_TARGET_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_OVERLAP_TARGET_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY_OVERLAP_TARGET[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_OVERLAP_TARGET_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_OVERLAP_TARGET_MAX, 0x00002710 , "" },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_OVERLAP_TARGET[] =
{
    {"DEFAULT", 1500, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_OVERLAP_TARGET(
    0x10835007,
    g_pszKeyName_FRL_LOW_LATENCY_OVERLAP_TARGET,
    g_pszRemappedName_FRL_LOW_LATENCY_OVERLAP_TARGET,
    g_pszMainDocs_FRL_LOW_LATENCY_OVERLAP_TARGET,
    g_pszDefinedWhen_FRL_LOW_LATENCY_OVERLAP_TARGET,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY_OVERLAP_TARGET, 
    2, 
    g_aDefaultData_FRL_LOW_LATENCY_OVERLAP_TARGET, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_PROACTIVE_FLUSH = "FRL_LOW_LATENCY_PROACTIVE_FLUSH";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_PROACTIVE_FLUSH = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_PROACTIVE_FLUSH = "D3DOGL_00008618";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_PROACTIVE_FLUSH = "Proactively flush the 3d pushbuffer once per frame to ensure a pre-present kickoff.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_PROACTIVE_FLUSH_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_PROACTIVE_FLUSH_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY_PROACTIVE_FLUSH[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_PROACTIVE_FLUSH_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_PROACTIVE_FLUSH_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_PROACTIVE_FLUSH[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_PROACTIVE_FLUSH(
    0x10835015,
    g_pszKeyName_FRL_LOW_LATENCY_PROACTIVE_FLUSH,
    g_pszRemappedName_FRL_LOW_LATENCY_PROACTIVE_FLUSH,
    g_pszMainDocs_FRL_LOW_LATENCY_PROACTIVE_FLUSH,
    g_pszDefinedWhen_FRL_LOW_LATENCY_PROACTIVE_FLUSH,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY_PROACTIVE_FLUSH, 
    2, 
    g_aDefaultData_FRL_LOW_LATENCY_PROACTIVE_FLUSH, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_RTBO_TARGET = "FRL_LOW_LATENCY_RTBO_TARGET";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_RTBO_TARGET = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_RTBO_TARGET = "D3DOGL_00008645";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_RTBO_TARGET = "Render Thread Bound Optimization (RTBO) target gap time in microseconds.";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_RTBO_TARGET[] =
{
    {"DEFAULT", 100, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_RTBO_TARGET(
    0x1083501d,
    g_pszKeyName_FRL_LOW_LATENCY_RTBO_TARGET,
    g_pszRemappedName_FRL_LOW_LATENCY_RTBO_TARGET,
    g_pszMainDocs_FRL_LOW_LATENCY_RTBO_TARGET,
    g_pszDefinedWhen_FRL_LOW_LATENCY_RTBO_TARGET,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_RTBO_TARGET, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR = "FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR = "D3DOGL_00008644";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR = "Overlap calculations take average of first trivial buffer and first significant buffer. 0 == large buffer only and 100 == small buffer only.  Value is a percentage from 0 to 100 because app profiles do not support floats.";

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR(
    0x1083501c,
    g_pszKeyName_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR,
    g_pszRemappedName_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR,
    g_pszMainDocs_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR,
    g_pszDefinedWhen_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR, 
    1 
);

static const char *g_pszKeyName_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP = "FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP";
static const char *g_pszDefinedWhen_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP = "1";
static const char *g_pszRemappedName_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP = "D3DOGL_0000aa44";
static const char *g_pszMainDocs_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP = "Calculate overlap with the lesser of the first submit timestamp and the present marker timestamp.  Helpful for apps that only have one buffer at present time blocked by the OS.";

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP[] =
{
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_DISABLED, 0x0 , "Do not consider present markers." },
    { (const char **)g_ppszDefineDataNames_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_ENABLED, 0x1 , "Use present marker when it comes before 3d submit." },
};

DataDefaultDWORD g_aDefaultData_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP(
    0x10835ffc,
    g_pszKeyName_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP,
    g_pszRemappedName_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP,
    g_pszMainDocs_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP,
    g_pszDefinedWhen_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP, 
    2, 
    g_aDefaultData_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP, 
    1 
);

static const char *g_pszKeyName_FXAA_ALLOW = "FXAA_ALLOW";
static const char *g_pszDefinedWhen_FXAA_ALLOW = "1";
static const char *g_pszRemappedName_FXAA_ALLOW = "D3DOGL_10572898";
static const char *g_pszMainDocs_FXAA_ALLOW = "Empowers an app profile to disallow FXAA";

static const char * (g_ppszDefineDataNames_FXAA_ALLOW_DISALLOWED)[] =
{
    "DISALLOWED",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FXAA_ALLOW_ALLOWED)[] =
{
    "ALLOWED",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FXAA_ALLOW[] =
{
    { (const char **)g_ppszDefineDataNames_FXAA_ALLOW_DISALLOWED, 0 , "FXAA is not allowed" },
    { (const char **)g_ppszDefineDataNames_FXAA_ALLOW_ALLOWED, 1 , "FXAA is allowed" },
};

DataDefaultDWORD g_aDefaultData_FXAA_ALLOW[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_FXAA_ALLOW(
    0x1034cb89,
    g_pszKeyName_FXAA_ALLOW,
    g_pszRemappedName_FXAA_ALLOW,
    g_pszMainDocs_FXAA_ALLOW,
    g_pszDefinedWhen_FXAA_ALLOW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FXAA_ALLOW, 
    2, 
    g_aDefaultData_FXAA_ALLOW, 
    1 
);

static const char *g_pszKeyName_FXAA_ENABLE = "FXAA_ENABLE";
static const char *g_pszDefinedWhen_FXAA_ENABLE = "1";
static const char *g_pszRemappedName_FXAA_ENABLE = "D3DOGL_97263802";
static const char *g_pszMainDocs_FXAA_ENABLE = "Toggle FXAA on or off";

static const char * (g_ppszDefineDataNames_FXAA_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FXAA_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FXAA_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_FXAA_ENABLE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_FXAA_ENABLE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_FXAA_ENABLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FXAA_ENABLE(
    0x1074c972,
    g_pszKeyName_FXAA_ENABLE,
    g_pszRemappedName_FXAA_ENABLE,
    g_pszMainDocs_FXAA_ENABLE,
    g_pszDefinedWhen_FXAA_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FXAA_ENABLE, 
    2, 
    g_aDefaultData_FXAA_ENABLE, 
    1 
);

static const char *g_pszKeyName_FXAA_INDICATOR_ENABLE = "FXAA_INDICATOR_ENABLE";
static const char *g_pszDefinedWhen_FXAA_INDICATOR_ENABLE = "1";
static const char *g_pszRemappedName_FXAA_INDICATOR_ENABLE = "D3DOGL_68fb9c";
static const char *g_pszMainDocs_FXAA_INDICATOR_ENABLE = "Toggle FXAA Indicator on or off";

static const char * (g_ppszDefineDataNames_FXAA_INDICATOR_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_FXAA_INDICATOR_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_FXAA_INDICATOR_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_FXAA_INDICATOR_ENABLE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_FXAA_INDICATOR_ENABLE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_FXAA_INDICATOR_ENABLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_FXAA_INDICATOR_ENABLE(
    0x1068fb9c,
    g_pszKeyName_FXAA_INDICATOR_ENABLE,
    g_pszRemappedName_FXAA_INDICATOR_ENABLE,
    g_pszMainDocs_FXAA_INDICATOR_ENABLE,
    g_pszDefinedWhen_FXAA_INDICATOR_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_FXAA_INDICATOR_ENABLE, 
    2, 
    g_aDefaultData_FXAA_INDICATOR_ENABLE, 
    1 
);

static const char *g_pszKeyName_G80_MODEB_OVERRIDE = "G80_MODEB_OVERRIDE";
static const char *g_pszDefinedWhen_G80_MODEB_OVERRIDE = "1";
static const char *g_pszRemappedName_G80_MODEB_OVERRIDE = "D3DOGL_74098073";
static const char *g_pszMainDocs_G80_MODEB_OVERRIDE = "NVPMAPI G80 ModeB Override";

static const char * (g_ppszDefineDataNames_G80_MODEB_OVERRIDE_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_G80_MODEB_OVERRIDE_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_G80_MODEB_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_G80_MODEB_OVERRIDE_DISABLE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_G80_MODEB_OVERRIDE_ENABLE, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_G80_MODEB_OVERRIDE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_G80_MODEB_OVERRIDE(
    0x10fc00ff,
    g_pszKeyName_G80_MODEB_OVERRIDE,
    g_pszRemappedName_G80_MODEB_OVERRIDE,
    g_pszMainDocs_G80_MODEB_OVERRIDE,
    g_pszDefinedWhen_G80_MODEB_OVERRIDE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_G80_MODEB_OVERRIDE, 
    2, 
    g_aDefaultData_G80_MODEB_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_GFN_FRL_FPS = "GFN_FRL_FPS";
static const char *g_pszDefinedWhen_GFN_FRL_FPS = "1";
static const char *g_pszRemappedName_GFN_FRL_FPS = "D3DOGL_0000860B";
static const char *g_pszMainDocs_GFN_FRL_FPS = "GFN's Frame Rate Limiter";

static const char * (g_ppszDefineDataNames_GFN_FRL_FPS_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_GFN_FRL_FPS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_GFN_FRL_FPS_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_GFN_FRL_FPS[] =
{
    { (const char **)g_ppszDefineDataNames_GFN_FRL_FPS_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_GFN_FRL_FPS_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_GFN_FRL_FPS_MAX, 0x000003ff , "" },
};

DataDefaultDWORD g_aDefaultData_GFN_FRL_FPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_GFN_FRL_FPS(
    0x1083500f,
    g_pszKeyName_GFN_FRL_FPS,
    g_pszRemappedName_GFN_FRL_FPS,
    g_pszMainDocs_GFN_FRL_FPS,
    g_pszDefinedWhen_GFN_FRL_FPS,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_GFN_FRL_FPS, 
    3, 
    g_aDefaultData_GFN_FRL_FPS, 
    1 
);

static const char *g_pszKeyName_GRAPHICS_SHADER_PREFETCH = "GRAPHICS_SHADER_PREFETCH";
static const char *g_pszDefinedWhen_GRAPHICS_SHADER_PREFETCH = "1";
static const char *g_pszRemappedName_GRAPHICS_SHADER_PREFETCH = "D3DOGL_0x121044";
static const char *g_pszMainDocs_GRAPHICS_SHADER_PREFETCH = "Set value in bytes for GA10x+ Shader prefetch feature. See bugs 2498256 2913514. Only applies to Vertex_B and pixel shaders. Note that this value will be aligned to 256B.  The maximum value allowed is capped to the shader size.";

DataDefaultDWORD g_aDefaultData_GRAPHICS_SHADER_PREFETCH[] =
{
    {"DEFAULT", 0x4000, "" }, 
};

SettingDWORD g_setting_GRAPHICS_SHADER_PREFETCH(
    0x10121044,
    g_pszKeyName_GRAPHICS_SHADER_PREFETCH,
    g_pszRemappedName_GRAPHICS_SHADER_PREFETCH,
    g_pszMainDocs_GRAPHICS_SHADER_PREFETCH,
    g_pszDefinedWhen_GRAPHICS_SHADER_PREFETCH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_GRAPHICS_SHADER_PREFETCH, 
    1 
);

static const char *g_pszKeyName_GSYNC_COMPATIBILITY = "GSYNC_COMPATIBILITY";
static const char *g_pszDefinedWhen_GSYNC_COMPATIBILITY = "1";
static const char *g_pszRemappedName_GSYNC_COMPATIBILITY = "D3DOGL_81598022";
static const char *g_pszMainDocs_GSYNC_COMPATIBILITY = "";

static const char * (g_ppszDefineDataNames_GSYNC_COMPATIBILITY_NO)[] =
{
    "NO",
    NULL
};

static const char * (g_ppszDefineDataNames_GSYNC_COMPATIBILITY_YES)[] =
{
    "YES",
    NULL
};

DataValueDWORD g_aDefineData_GSYNC_COMPATIBILITY[] =
{
    { (const char **)g_ppszDefineDataNames_GSYNC_COMPATIBILITY_NO, 0x0 , "Not G-Sync Compatible" },
    { (const char **)g_ppszDefineDataNames_GSYNC_COMPATIBILITY_YES, 0x1 , "G-Sync Compatible" },
};

DataDefaultDWORD g_aDefaultData_GSYNC_COMPATIBILITY[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_GSYNC_COMPATIBILITY(
    0x109db0d3,
    g_pszKeyName_GSYNC_COMPATIBILITY,
    g_pszRemappedName_GSYNC_COMPATIBILITY,
    g_pszMainDocs_GSYNC_COMPATIBILITY,
    g_pszDefinedWhen_GSYNC_COMPATIBILITY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_GSYNC_COMPATIBILITY, 
    2, 
    g_aDefaultData_GSYNC_COMPATIBILITY, 
    1 
);

static const char *g_pszKeyName_HDRINDICATOR = "HDRINDICATOR";
static const char *g_pszDefinedWhen_HDRINDICATOR = "1";
static const char *g_pszRemappedName_HDRINDICATOR = "D3DOGL_111bae27";
static const char *g_pszMainDocs_HDRINDICATOR = "Display the HDR indicator";

static const char * (g_ppszDefineDataNames_HDRINDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_HDRINDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_HDRINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_HDRINDICATOR_OFF, 0x0 , "Disable HDR Indicator" },
    { (const char **)g_ppszDefineDataNames_HDRINDICATOR_ON, 0x1 , "Enable HDR Indicator" },
};

DataDefaultDWORD g_aDefaultData_HDRINDICATOR[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_HDRINDICATOR(
    0x107b1e3e,
    g_pszKeyName_HDRINDICATOR,
    g_pszRemappedName_HDRINDICATOR,
    g_pszMainDocs_HDRINDICATOR,
    g_pszDefinedWhen_HDRINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_HDRINDICATOR, 
    2, 
    g_aDefaultData_HDRINDICATOR, 
    1 
);

static const char *g_pszKeyName_HYBRIDPERFSLIENABLE = "HYBRIDPERFSLIENABLE";
static const char *g_pszDefinedWhen_HYBRIDPERFSLIENABLE = "1";
static const char *g_pszRemappedName_HYBRIDPERFSLIENABLE = "D3DOGL_19726778";
static const char *g_pszMainDocs_HYBRIDPERFSLIENABLE = "";

static const char * (g_ppszDefineDataNames_HYBRIDPERFSLIENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_HYBRIDPERFSLIENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_HYBRIDPERFSLIENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_HYBRIDPERFSLIENABLE_OFF, 0x51616260 , "" },
    { (const char **)g_ppszDefineDataNames_HYBRIDPERFSLIENABLE_ON, 0x02906797 , "" },
};

DataDefaultDWORD g_aDefaultData_HYBRIDPERFSLIENABLE[] =
{
    {"DEFAULT", 0x51616260, "" }, 
};

SettingDWORD g_setting_HYBRIDPERFSLIENABLE(
    0x109a6a85,
    g_pszKeyName_HYBRIDPERFSLIENABLE,
    g_pszRemappedName_HYBRIDPERFSLIENABLE,
    g_pszMainDocs_HYBRIDPERFSLIENABLE,
    g_pszDefinedWhen_HYBRIDPERFSLIENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_HYBRIDPERFSLIENABLE, 
    2, 
    g_aDefaultData_HYBRIDPERFSLIENABLE, 
    1 
);

static const char *g_pszKeyName_KEPLER_BALANCED_PRIM_TIMESLICED_MODE = "KEPLER_BALANCED_PRIM_TIMESLICED_MODE";
static const char *g_pszDefinedWhen_KEPLER_BALANCED_PRIM_TIMESLICED_MODE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_KEPLER_BALANCED_PRIM_TIMESLICED_MODE = "D3DOGL_2165ae";
static const char *g_pszMainDocs_KEPLER_BALANCED_PRIM_TIMESLICED_MODE = "Set balanced primitive mode when in timesliced mode. Affects uneven TPC configs.";

static const char * (g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_TIMESLICED_MODE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_TIMESLICED_MODE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_KEPLER_BALANCED_PRIM_TIMESLICED_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_TIMESLICED_MODE_OFF, 0x0 , "OFF" },
    { (const char **)g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_TIMESLICED_MODE_ON, 0x1 , "ON" },
};

DataDefaultDWORD g_aDefaultData_KEPLER_BALANCED_PRIM_TIMESLICED_MODE[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_KEPLER_BALANCED_PRIM_TIMESLICED_MODE(
    0x102165ae,
    g_pszKeyName_KEPLER_BALANCED_PRIM_TIMESLICED_MODE,
    g_pszRemappedName_KEPLER_BALANCED_PRIM_TIMESLICED_MODE,
    g_pszMainDocs_KEPLER_BALANCED_PRIM_TIMESLICED_MODE,
    g_pszDefinedWhen_KEPLER_BALANCED_PRIM_TIMESLICED_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_KEPLER_BALANCED_PRIM_TIMESLICED_MODE, 
    2, 
    g_aDefaultData_KEPLER_BALANCED_PRIM_TIMESLICED_MODE, 
    1 
);

static const char *g_pszKeyName_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE = "KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE";
static const char *g_pszDefinedWhen_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE = "D3DOGL_2165ad";
static const char *g_pszMainDocs_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE = "Set balanced primitive mode when in unpartitioned mode. Affects uneven TPC configs.";

static const char * (g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_OFF, 0x0 , "OFF" },
    { (const char **)g_ppszDefineDataNames_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_ON, 0x1 , "ON" },
};

DataDefaultDWORD g_aDefaultData_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE(
    0x102165ad,
    g_pszKeyName_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE,
    g_pszRemappedName_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE,
    g_pszMainDocs_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE,
    g_pszDefinedWhen_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE, 
    2, 
    g_aDefaultData_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE, 
    1 
);

static const char *g_pszKeyName_KEPLER_L1_CACHE_WAR_BUG_986473 = "KEPLER_L1_CACHE_WAR_BUG_986473";
static const char *g_pszDefinedWhen_KEPLER_L1_CACHE_WAR_BUG_986473 = "1";
static const char *g_pszRemappedName_KEPLER_L1_CACHE_WAR_BUG_986473 = "D3DOGL_0x528ab2";
static const char *g_pszMainDocs_KEPLER_L1_CACHE_WAR_BUG_986473 = "Disable Kepler L1 cache WAR - see bug 986473";

static const char * (g_ppszDefineDataNames_KEPLER_L1_CACHE_WAR_BUG_986473_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_KEPLER_L1_CACHE_WAR_BUG_986473_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_KEPLER_L1_CACHE_WAR_BUG_986473[] =
{
    { (const char **)g_ppszDefineDataNames_KEPLER_L1_CACHE_WAR_BUG_986473_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_KEPLER_L1_CACHE_WAR_BUG_986473_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_KEPLER_L1_CACHE_WAR_BUG_986473[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_KEPLER_L1_CACHE_WAR_BUG_986473(
    0x10528ab2,
    g_pszKeyName_KEPLER_L1_CACHE_WAR_BUG_986473,
    g_pszRemappedName_KEPLER_L1_CACHE_WAR_BUG_986473,
    g_pszMainDocs_KEPLER_L1_CACHE_WAR_BUG_986473,
    g_pszDefinedWhen_KEPLER_L1_CACHE_WAR_BUG_986473,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_KEPLER_L1_CACHE_WAR_BUG_986473, 
    2, 
    g_aDefaultData_KEPLER_L1_CACHE_WAR_BUG_986473, 
    1 
);

static const char *g_pszKeyName_KEPLER_USE_SHUFFLE_INSTRUCTION = "KEPLER_USE_SHUFFLE_INSTRUCTION";
static const char *g_pszDefinedWhen_KEPLER_USE_SHUFFLE_INSTRUCTION = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_KEPLER_USE_SHUFFLE_INSTRUCTION = "D3DOGL_BBAADDDD";
static const char *g_pszMainDocs_KEPLER_USE_SHUFFLE_INSTRUCTION = "";

static const char * (g_ppszDefineDataNames_KEPLER_USE_SHUFFLE_INSTRUCTION_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_KEPLER_USE_SHUFFLE_INSTRUCTION_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_KEPLER_USE_SHUFFLE_INSTRUCTION[] =
{
    { (const char **)g_ppszDefineDataNames_KEPLER_USE_SHUFFLE_INSTRUCTION_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_KEPLER_USE_SHUFFLE_INSTRUCTION_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_KEPLER_USE_SHUFFLE_INSTRUCTION[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_KEPLER_USE_SHUFFLE_INSTRUCTION(
    0x10a1b2f8,
    g_pszKeyName_KEPLER_USE_SHUFFLE_INSTRUCTION,
    g_pszRemappedName_KEPLER_USE_SHUFFLE_INSTRUCTION,
    g_pszMainDocs_KEPLER_USE_SHUFFLE_INSTRUCTION,
    g_pszDefinedWhen_KEPLER_USE_SHUFFLE_INSTRUCTION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_KEPLER_USE_SHUFFLE_INSTRUCTION, 
    2, 
    g_aDefaultData_KEPLER_USE_SHUFFLE_INSTRUCTION, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_AUTOALIGN = "LATENCY_INDICATOR_AUTOALIGN";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_AUTOALIGN = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_AUTOALIGN = "D3DOGL_53304098";
static const char *g_pszMainDocs_LATENCY_INDICATOR_AUTOALIGN = "";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_AUTOALIGN_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_AUTOALIGN_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_AUTOALIGN[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_AUTOALIGN_DISABLED, 0x0 , "Do not autoalign flash indicator" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_AUTOALIGN_ENABLED, 0x1 , "Autoalign flash indicator" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_AUTOALIGN[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_AUTOALIGN(
    0x1095f170,
    g_pszKeyName_LATENCY_INDICATOR_AUTOALIGN,
    g_pszRemappedName_LATENCY_INDICATOR_AUTOALIGN,
    g_pszMainDocs_LATENCY_INDICATOR_AUTOALIGN,
    g_pszDefinedWhen_LATENCY_INDICATOR_AUTOALIGN,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_AUTOALIGN, 
    2, 
    g_aDefaultData_LATENCY_INDICATOR_AUTOALIGN, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_DRAW_NEGATIVE = "LATENCY_INDICATOR_DRAW_NEGATIVE";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_DRAW_NEGATIVE = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_DRAW_NEGATIVE = "D3DOGL_A0022605";
static const char *g_pszMainDocs_LATENCY_INDICATOR_DRAW_NEGATIVE = "Draw a negative indicator when the Reflex flash indicator is not active.  Duration is indefinite.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_DRAW_NEGATIVE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_DRAW_NEGATIVE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_DRAW_NEGATIVE[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_DRAW_NEGATIVE_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_DRAW_NEGATIVE_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_DRAW_NEGATIVE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_DRAW_NEGATIVE(
    0x10824f19,
    g_pszKeyName_LATENCY_INDICATOR_DRAW_NEGATIVE,
    g_pszRemappedName_LATENCY_INDICATOR_DRAW_NEGATIVE,
    g_pszMainDocs_LATENCY_INDICATOR_DRAW_NEGATIVE,
    g_pszDefinedWhen_LATENCY_INDICATOR_DRAW_NEGATIVE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_DRAW_NEGATIVE, 
    2, 
    g_aDefaultData_LATENCY_INDICATOR_DRAW_NEGATIVE, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_DURATION = "LATENCY_INDICATOR_DURATION";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_DURATION = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_DURATION = "D3DOGL_A0022604";
static const char *g_pszMainDocs_LATENCY_INDICATOR_DURATION = "Duration in microseconds to draw the Reflex flash indicator when the TRIGGER_FLASH marker is seen.";

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_DURATION[] =
{
    {"DEFAULT", 0xFA, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_DURATION(
    0x10824f18,
    g_pszKeyName_LATENCY_INDICATOR_DURATION,
    g_pszRemappedName_LATENCY_INDICATOR_DURATION,
    g_pszMainDocs_LATENCY_INDICATOR_DURATION,
    g_pszDefinedWhen_LATENCY_INDICATOR_DURATION,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_LATENCY_INDICATOR_DURATION, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_ENABLE = "LATENCY_INDICATOR_ENABLE";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_ENABLE = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_ENABLE = "D3DOGL_A0122705";
static const char *g_pszMainDocs_LATENCY_INDICATOR_ENABLE = "Enable the Reflex flash indicator.  Usually enabled with the AutoFL MMF file.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_ENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_ENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_ENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_ENABLE_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_ENABLE_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_ENABLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_ENABLE(
    0x10833f19,
    g_pszKeyName_LATENCY_INDICATOR_ENABLE,
    g_pszRemappedName_LATENCY_INDICATOR_ENABLE,
    g_pszMainDocs_LATENCY_INDICATOR_ENABLE,
    g_pszDefinedWhen_LATENCY_INDICATOR_ENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_ENABLE, 
    2, 
    g_aDefaultData_LATENCY_INDICATOR_ENABLE, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_HEIGHT = "LATENCY_INDICATOR_HEIGHT";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_HEIGHT = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_HEIGHT = "D3DOGL_A0018604";
static const char *g_pszMainDocs_LATENCY_INDICATOR_HEIGHT = "Height in pixels of latency flash indicator in PS_FramerateMonitor.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_DEFAULT_SIZE)[] =
{
    "DEFAULT_SIZE",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_HEIGHT[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_MAX, 0x000000ff , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_HEIGHT_DEFAULT_SIZE, 0x00000008 , "" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_HEIGHT[] =
{
    {"DEFAULT", 0x00000008, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_HEIGHT(
    0x10844f18,
    g_pszKeyName_LATENCY_INDICATOR_HEIGHT,
    g_pszRemappedName_LATENCY_INDICATOR_HEIGHT,
    g_pszMainDocs_LATENCY_INDICATOR_HEIGHT,
    g_pszDefinedWhen_LATENCY_INDICATOR_HEIGHT,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_HEIGHT, 
    3, 
    g_aDefaultData_LATENCY_INDICATOR_HEIGHT, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_POS_X = "LATENCY_INDICATOR_POS_X";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_POS_X = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_POS_X = "D3DOGL_A0008601";
static const char *g_pszMainDocs_LATENCY_INDICATOR_POS_X = "Screen position by % of latency flash indicator in PS_FramerateMonitor. 0 = left edge, 100 = right edge.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_POS_X_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_POS_X_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_POS_X[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_POS_X_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_POS_X_MAX, 0x00000064 , "" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_POS_X[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_POS_X(
    0x10834f15,
    g_pszKeyName_LATENCY_INDICATOR_POS_X,
    g_pszRemappedName_LATENCY_INDICATOR_POS_X,
    g_pszMainDocs_LATENCY_INDICATOR_POS_X,
    g_pszDefinedWhen_LATENCY_INDICATOR_POS_X,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_POS_X, 
    2, 
    g_aDefaultData_LATENCY_INDICATOR_POS_X, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_POS_Y = "LATENCY_INDICATOR_POS_Y";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_POS_Y = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_POS_Y = "D3DOGL_A0008602";
static const char *g_pszMainDocs_LATENCY_INDICATOR_POS_Y = "Screen position by % of latency flash indicator in PS_FramerateMonitor. 0 = top edge, 100 = bottom edge.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_DEFAULT_POS_Y)[] =
{
    "DEFAULT_POS_Y",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_POS_Y[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_MAX, 0x00000064 , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_POS_Y_DEFAULT_POS_Y, 0x00000032 , "" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_POS_Y[] =
{
    {"DEFAULT", 0x00000032, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_POS_Y(
    0x10834f16,
    g_pszKeyName_LATENCY_INDICATOR_POS_Y,
    g_pszRemappedName_LATENCY_INDICATOR_POS_Y,
    g_pszMainDocs_LATENCY_INDICATOR_POS_Y,
    g_pszDefinedWhen_LATENCY_INDICATOR_POS_Y,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_POS_Y, 
    3, 
    g_aDefaultData_LATENCY_INDICATOR_POS_Y, 
    1 
);

static const char *g_pszKeyName_LATENCY_INDICATOR_WIDTH = "LATENCY_INDICATOR_WIDTH";
static const char *g_pszDefinedWhen_LATENCY_INDICATOR_WIDTH = "1";
static const char *g_pszRemappedName_LATENCY_INDICATOR_WIDTH = "D3DOGL_A0008603";
static const char *g_pszMainDocs_LATENCY_INDICATOR_WIDTH = "Width in pixels of latency flash indicator in PS_FramerateMonitor.";

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_DEFAULT_SIZE)[] =
{
    "DEFAULT_SIZE",
    NULL
};

DataValueDWORD g_aDefineData_LATENCY_INDICATOR_WIDTH[] =
{
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_MAX, 0x000000ff , "" },
    { (const char **)g_ppszDefineDataNames_LATENCY_INDICATOR_WIDTH_DEFAULT_SIZE, 0x00000004 , "" },
};

DataDefaultDWORD g_aDefaultData_LATENCY_INDICATOR_WIDTH[] =
{
    {"DEFAULT", 0x00000004, "" }, 
};

SettingDWORD g_setting_LATENCY_INDICATOR_WIDTH(
    0x10834f17,
    g_pszKeyName_LATENCY_INDICATOR_WIDTH,
    g_pszRemappedName_LATENCY_INDICATOR_WIDTH,
    g_pszMainDocs_LATENCY_INDICATOR_WIDTH,
    g_pszDefinedWhen_LATENCY_INDICATOR_WIDTH,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_LATENCY_INDICATOR_WIDTH, 
    3, 
    g_aDefaultData_LATENCY_INDICATOR_WIDTH, 
    1 
);

static const char *g_pszKeyName_MAXGPUS_MULTIGPU_BROADCAST_SHIM = "MAXGPUS_MULTIGPU_BROADCAST_SHIM";
static const char *g_pszDefinedWhen_MAXGPUS_MULTIGPU_BROADCAST_SHIM = "1";
static const char *g_pszRemappedName_MAXGPUS_MULTIGPU_BROADCAST_SHIM = "D3D_54312268";
static const char *g_pszMainDocs_MAXGPUS_MULTIGPU_BROADCAST_SHIM = "This value is used in Multi-GPU Broadcast shim to define maximum number of GPUs in a mosaic group";

static const char * (g_ppszDefineDataNames_MAXGPUS_MULTIGPU_BROADCAST_SHIM_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXGPUS_MULTIGPU_BROADCAST_SHIM_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_MAXGPUS_MULTIGPU_BROADCAST_SHIM[] =
{
    { (const char **)g_ppszDefineDataNames_MAXGPUS_MULTIGPU_BROADCAST_SHIM_MIN, 0x1 , "" },
    { (const char **)g_ppszDefineDataNames_MAXGPUS_MULTIGPU_BROADCAST_SHIM_MAX, 0x4 , "" },
};

DataDefaultDWORD g_aDefaultData_MAXGPUS_MULTIGPU_BROADCAST_SHIM[] =
{
    {"DEFAULT", 0x4, "" }, 
};

SettingDWORD g_setting_MAXGPUS_MULTIGPU_BROADCAST_SHIM(
    0x108f0843,
    g_pszKeyName_MAXGPUS_MULTIGPU_BROADCAST_SHIM,
    g_pszRemappedName_MAXGPUS_MULTIGPU_BROADCAST_SHIM,
    g_pszMainDocs_MAXGPUS_MULTIGPU_BROADCAST_SHIM,
    g_pszDefinedWhen_MAXGPUS_MULTIGPU_BROADCAST_SHIM,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_MAXGPUS_MULTIGPU_BROADCAST_SHIM, 
    2, 
    g_aDefaultData_MAXGPUS_MULTIGPU_BROADCAST_SHIM, 
    1 
);

static const char *g_pszKeyName_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY = "MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY";
static const char *g_pszDefinedWhen_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY = "1";
static const char *g_pszRemappedName_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY = "D3DOGL_0xbd10fb";
static const char *g_pszMainDocs_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY = "Force Maxwell circular buffer eviction policy (NV_PTPC_PRI_PE_L2_EVICT_POLICY, NV_PGPC_PRI_RASTERARB_LINE_CLASS).";

static const char * (g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_FIRST)[] =
{
    "FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_NORMAL)[] =
{
    "NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_LAST)[] =
{
    "LAST",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_FIRST, 0 , "First" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_NORMAL, 1 , "Normal" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_LAST, 2 , "Last" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY[] =
{
    {"DEFAULT", 2, "" }, 
};

SettingDWORD g_setting_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY(
    0x10bd10fb,
    g_pszKeyName_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY,
    g_pszRemappedName_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY,
    g_pszMainDocs_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY,
    g_pszDefinedWhen_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY, 
    3, 
    g_aDefaultData_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY, 
    1 
);

static const char *g_pszKeyName_MAXWELL_LOW_LOD_OPTIMIZATION = "MAXWELL_LOW_LOD_OPTIMIZATION";
static const char *g_pszDefinedWhen_MAXWELL_LOW_LOD_OPTIMIZATION = "1";
static const char *g_pszRemappedName_MAXWELL_LOW_LOD_OPTIMIZATION = "D3DOGL_0x524dc7";
static const char *g_pszMainDocs_MAXWELL_LOW_LOD_OPTIMIZATION = "Controls behavior of Low LOD optimization";

static const char * (g_ppszDefineDataNames_MAXWELL_LOW_LOD_OPTIMIZATION_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_LOW_LOD_OPTIMIZATION_TESSELLATION_ONLY)[] =
{
    "TESSELLATION_ONLY",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_LOW_LOD_OPTIMIZATION[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_LOW_LOD_OPTIMIZATION_ENABLE, 1 , "enable optimization" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_LOW_LOD_OPTIMIZATION_TESSELLATION_ONLY, 2 , "restrict the optimization only to tessellation shaders (currently noop for DX as we don't yet support VS-GS part)" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_LOW_LOD_OPTIMIZATION[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_MAXWELL_LOW_LOD_OPTIMIZATION(
    0x10524dc7,
    g_pszKeyName_MAXWELL_LOW_LOD_OPTIMIZATION,
    g_pszRemappedName_MAXWELL_LOW_LOD_OPTIMIZATION,
    g_pszMainDocs_MAXWELL_LOW_LOD_OPTIMIZATION,
    g_pszDefinedWhen_MAXWELL_LOW_LOD_OPTIMIZATION,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_MAXWELL_LOW_LOD_OPTIMIZATION, 
    2, 
    g_aDefaultData_MAXWELL_LOW_LOD_OPTIMIZATION, 
    1 
);

static const char *g_pszKeyName_MAXWELL_MMU_WAR_BUG_1317235 = "MAXWELL_MMU_WAR_BUG_1317235";
static const char *g_pszDefinedWhen_MAXWELL_MMU_WAR_BUG_1317235 = "1";
static const char *g_pszRemappedName_MAXWELL_MMU_WAR_BUG_1317235 = "D3DOGL_0x5234d4";
static const char *g_pszMainDocs_MAXWELL_MMU_WAR_BUG_1317235 = "Set _MMU_RSRVD._LTP_UTLB_CL_VC_NB PRI WAR for bug 1317235";

static const char * (g_ppszDefineDataNames_MAXWELL_MMU_WAR_BUG_1317235_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_MMU_WAR_BUG_1317235_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_MMU_WAR_BUG_1317235[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_MMU_WAR_BUG_1317235_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_MMU_WAR_BUG_1317235_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_MMU_WAR_BUG_1317235[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_MAXWELL_MMU_WAR_BUG_1317235(
    0x105234d4,
    g_pszKeyName_MAXWELL_MMU_WAR_BUG_1317235,
    g_pszRemappedName_MAXWELL_MMU_WAR_BUG_1317235,
    g_pszMainDocs_MAXWELL_MMU_WAR_BUG_1317235,
    g_pszDefinedWhen_MAXWELL_MMU_WAR_BUG_1317235,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_MMU_WAR_BUG_1317235, 
    2, 
    g_aDefaultData_MAXWELL_MMU_WAR_BUG_1317235, 
    1 
);

static const char *g_pszKeyName_MAXWELL_PIXEL_SHADER_BARRIER = "MAXWELL_PIXEL_SHADER_BARRIER";
static const char *g_pszDefinedWhen_MAXWELL_PIXEL_SHADER_BARRIER = "1";
static const char *g_pszRemappedName_MAXWELL_PIXEL_SHADER_BARRIER = "D3DOGL_0x523dc9";
static const char *g_pszMainDocs_MAXWELL_PIXEL_SHADER_BARRIER = "Use PSB for GPU waits when applicable. If disabled, use WFI instead.";

static const char * (g_ppszDefineDataNames_MAXWELL_PIXEL_SHADER_BARRIER_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_PIXEL_SHADER_BARRIER_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_PIXEL_SHADER_BARRIER[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_PIXEL_SHADER_BARRIER_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_PIXEL_SHADER_BARRIER_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_PIXEL_SHADER_BARRIER[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_MAXWELL_PIXEL_SHADER_BARRIER(
    0x10523dc9,
    g_pszKeyName_MAXWELL_PIXEL_SHADER_BARRIER,
    g_pszRemappedName_MAXWELL_PIXEL_SHADER_BARRIER,
    g_pszMainDocs_MAXWELL_PIXEL_SHADER_BARRIER,
    g_pszDefinedWhen_MAXWELL_PIXEL_SHADER_BARRIER,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_PIXEL_SHADER_BARRIER, 
    2, 
    g_aDefaultData_MAXWELL_PIXEL_SHADER_BARRIER, 
    1 
);

static const char *g_pszKeyName_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT = "MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT";
static const char *g_pszDefinedWhen_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT = "1";
static const char *g_pszRemappedName_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT = "D3DOGL_0xb134fc";
static const char *g_pszMainDocs_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT = "Set Max number of SMs which can be used for compute_1 (async) work on GM20x+";

DataDefaultDWORD g_aDefaultData_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT[] =
{
    {"DEFAULT", 256, "" }, 
};

SettingDWORD g_setting_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT(
    0x10b134fc,
    g_pszKeyName_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT,
    g_pszRemappedName_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT,
    g_pszMainDocs_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT,
    g_pszDefinedWhen_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT, 
    1 
);

static const char *g_pszKeyName_MAXWELL_SCG_FLAGS = "MAXWELL_SCG_FLAGS";
static const char *g_pszDefinedWhen_MAXWELL_SCG_FLAGS = "1";
static const char *g_pszRemappedName_MAXWELL_SCG_FLAGS = "D3DOGL_0xb134fd";
static const char *g_pszMainDocs_MAXWELL_SCG_FLAGS = "Flags to control SCG behaviour";

static const char * (g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_DISABLE_BLITS_ON_ASYNC_COMPUTE)[] =
{
    "DISABLE_BLITS_ON_ASYNC_COMPUTE",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_FORCE_I2M_FOR_ASYNC_COMPUTE_BLITS)[] =
{
    "FORCE_I2M_FOR_ASYNC_COMPUTE_BLITS",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_FORCE_CE_FOR_ASYNC_COMPUTE_BLITS)[] =
{
    "FORCE_CE_FOR_ASYNC_COMPUTE_BLITS",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_USE_HELPER_CH_FOR_PROGRESS_FORWARD)[] =
{
    "USE_HELPER_CH_FOR_PROGRESS_FORWARD",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_SCG_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_DISABLE_BLITS_ON_ASYNC_COMPUTE, 0x00000010 , "Disable promoting blits to async compute stream for legacy apps SCG" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_FORCE_I2M_FOR_ASYNC_COMPUTE_BLITS, 0x00000020 , "Force usage of in-compute class i2m for all async compute blits (Maxwell default)" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_FORCE_CE_FOR_ASYNC_COMPUTE_BLITS, 0x00000040 , "Force usage of in-compute class CE for all async compute blits (Pascal+ default)" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_SCG_FLAGS_USE_HELPER_CH_FOR_PROGRESS_FORWARD, 0x00000080 , "GR/CS reports thier own progress fences. Use this regkey to force legacy helper channel use" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_SCG_FLAGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MAXWELL_SCG_FLAGS(
    0x10b134fd,
    g_pszKeyName_MAXWELL_SCG_FLAGS,
    g_pszRemappedName_MAXWELL_SCG_FLAGS,
    g_pszMainDocs_MAXWELL_SCG_FLAGS,
    g_pszDefinedWhen_MAXWELL_SCG_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_MAXWELL_SCG_FLAGS, 
    5, 
    g_aDefaultData_MAXWELL_SCG_FLAGS, 
    1 
);

static const char *g_pszKeyName_MAXWELL_SM_WAR_BUG_1318757 = "MAXWELL_SM_WAR_BUG_1318757";
static const char *g_pszDefinedWhen_MAXWELL_SM_WAR_BUG_1318757 = "1";
static const char *g_pszRemappedName_MAXWELL_SM_WAR_BUG_1318757 = "D3DOGL_0x58a234";
static const char *g_pszMainDocs_MAXWELL_SM_WAR_BUG_1318757 = "Enable OCG WAR for SM bug SW1318757";

static const char * (g_ppszDefineDataNames_MAXWELL_SM_WAR_BUG_1318757_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_SM_WAR_BUG_1318757_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_SM_WAR_BUG_1318757[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_SM_WAR_BUG_1318757_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_SM_WAR_BUG_1318757_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_SM_WAR_BUG_1318757[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_MAXWELL_SM_WAR_BUG_1318757(
    0x1058a234,
    g_pszKeyName_MAXWELL_SM_WAR_BUG_1318757,
    g_pszRemappedName_MAXWELL_SM_WAR_BUG_1318757,
    g_pszMainDocs_MAXWELL_SM_WAR_BUG_1318757,
    g_pszDefinedWhen_MAXWELL_SM_WAR_BUG_1318757,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_SM_WAR_BUG_1318757, 
    2, 
    g_aDefaultData_MAXWELL_SM_WAR_BUG_1318757, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE = "MAXWELL_TILEDCACHE";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE = "D3DOGL_0x523dc0";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE = "enable/disable tiled cache";

static const char * (g_ppszDefineDataNames_MAXWELL_TILEDCACHE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_TILEDCACHE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_TILEDCACHE[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_TILEDCACHE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_TILEDCACHE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE(
    0x10523dc0,
    g_pszKeyName_MAXWELL_TILEDCACHE,
    g_pszRemappedName_MAXWELL_TILEDCACHE,
    g_pszMainDocs_MAXWELL_TILEDCACHE,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_TILEDCACHE, 
    2, 
    g_aDefaultData_MAXWELL_TILEDCACHE, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE = "MAXWELL_TILEDCACHE_BUFFERINTERLEAVE";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE = "D3DOGL_0x523dc2";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE = "4 3-bit fields to set buffering mode for betaCb / PagePool / cbTblIndex / BinnerCount (default for all - double buffered)";

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE[] =
{
    {"DEFAULT", 0x0000210A, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE(
    0x10523dc2,
    g_pszKeyName_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE,
    g_pszRemappedName_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE,
    g_pszMainDocs_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_CONTROL = "MAXWELL_TILEDCACHE_CONTROL";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_CONTROL = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_CONTROL = "D3DOGL_0x523dc3";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_CONTROL = "set value of TiledCacheControl method";

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_CONTROL[] =
{
    {"DEFAULT", 0x08080202, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_CONTROL(
    0x10523dc3,
    g_pszKeyName_MAXWELL_TILEDCACHE_CONTROL,
    g_pszRemappedName_MAXWELL_TILEDCACHE_CONTROL,
    g_pszMainDocs_MAXWELL_TILEDCACHE_CONTROL,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_CONTROL, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_CONTROL_EXTENDED = "MAXWELL_TILEDCACHE_CONTROL_EXTENDED";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_CONTROL_EXTENDED = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_CONTROL_EXTENDED = "D3DOGL_0x523dd3";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_CONTROL_EXTENDED = "set value of TiledCacheControlExtended method";

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_CONTROL_EXTENDED[] =
{
    {"DEFAULT", 0x00000008, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_CONTROL_EXTENDED(
    0x10523dd3,
    g_pszKeyName_MAXWELL_TILEDCACHE_CONTROL_EXTENDED,
    g_pszRemappedName_MAXWELL_TILEDCACHE_CONTROL_EXTENDED,
    g_pszMainDocs_MAXWELL_TILEDCACHE_CONTROL_EXTENDED,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_CONTROL_EXTENDED,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_CONTROL_EXTENDED, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE = "MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE = "D3DOGL_0x523dc6";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE = "Force L2 invalidate on AA downsample";

static const char * (g_ppszDefineDataNames_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE(
    0x10523dc6,
    g_pszKeyName_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE,
    g_pszRemappedName_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE,
    g_pszMainDocs_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE, 
    2, 
    g_aDefaultData_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_L2_USAGE = "MAXWELL_TILEDCACHE_L2_USAGE";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_L2_USAGE = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_L2_USAGE = "D3DOGL_0x523dc5";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_L2_USAGE = "set ratio of L2 allowed to be used for Tiled Caching";

DataDefaultFLOAT g_aDefaultData_MAXWELL_TILEDCACHE_L2_USAGE[] =
{
    {"DEFAULT", 0.3f, "" }, 
};

SettingFLOAT g_setting_MAXWELL_TILEDCACHE_L2_USAGE(
    0x10523dc5,
    g_pszKeyName_MAXWELL_TILEDCACHE_L2_USAGE,
    g_pszRemappedName_MAXWELL_TILEDCACHE_L2_USAGE,
    g_pszMainDocs_MAXWELL_TILEDCACHE_L2_USAGE,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_L2_USAGE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_L2_USAGE, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_STATETHRESHOLD = "MAXWELL_TILEDCACHE_STATETHRESHOLD";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_STATETHRESHOLD = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_STATETHRESHOLD = "D3DOGL_0x523dc4";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_STATETHRESHOLD = "set value of TiledCacheStateThreshold method";

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_STATETHRESHOLD[] =
{
    {"DEFAULT", 0x00080001, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_STATETHRESHOLD(
    0x10523dc4,
    g_pszKeyName_MAXWELL_TILEDCACHE_STATETHRESHOLD,
    g_pszRemappedName_MAXWELL_TILEDCACHE_STATETHRESHOLD,
    g_pszMainDocs_MAXWELL_TILEDCACHE_STATETHRESHOLD,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_STATETHRESHOLD,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_STATETHRESHOLD, 
    1 
);

static const char *g_pszKeyName_MAXWELL_TILEDCACHE_TILESIZE = "MAXWELL_TILEDCACHE_TILESIZE";
static const char *g_pszDefinedWhen_MAXWELL_TILEDCACHE_TILESIZE = "1";
static const char *g_pszRemappedName_MAXWELL_TILEDCACHE_TILESIZE = "D3DOGL_0x523dc1";
static const char *g_pszMainDocs_MAXWELL_TILEDCACHE_TILESIZE = "set X (low 16 bits) and Y (high 16 bits) of tile size";

DataDefaultDWORD g_aDefaultData_MAXWELL_TILEDCACHE_TILESIZE[] =
{
    {"DEFAULT", 0x00400040, "" }, 
};

SettingDWORD g_setting_MAXWELL_TILEDCACHE_TILESIZE(
    0x10523dc1,
    g_pszKeyName_MAXWELL_TILEDCACHE_TILESIZE,
    g_pszRemappedName_MAXWELL_TILEDCACHE_TILESIZE,
    g_pszMainDocs_MAXWELL_TILEDCACHE_TILESIZE,
    g_pszDefinedWhen_MAXWELL_TILEDCACHE_TILESIZE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MAXWELL_TILEDCACHE_TILESIZE, 
    1 
);

static const char *g_pszKeyName_MAXWELL_WDDM2_FORCE_128K_PTE = "MAXWELL_WDDM2_FORCE_128K_PTE";
static const char *g_pszDefinedWhen_MAXWELL_WDDM2_FORCE_128K_PTE = "1";
static const char *g_pszRemappedName_MAXWELL_WDDM2_FORCE_128K_PTE = "_";
static const char *g_pszMainDocs_MAXWELL_WDDM2_FORCE_128K_PTE = "enable/disable forcing large page sizes to be 128KB on Maxwell under WDDM2";

static const char * (g_ppszDefineDataNames_MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_ON)[] =
{
    "FORCE_ON",
    NULL
};

DataValueDWORD g_aDefineData_MAXWELL_WDDM2_FORCE_128K_PTE[] =
{
    { (const char **)g_ppszDefineDataNames_MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_OFF, 0 , "Force large page sizes to *not* be 128KB on Maxwell under WDDM2" },
    { (const char **)g_ppszDefineDataNames_MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_ON, 1 , "Force large page sizes to be 128KB on Maxwell under WDDM2" },
};

DataDefaultDWORD g_aDefaultData_MAXWELL_WDDM2_FORCE_128K_PTE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_MAXWELL_WDDM2_FORCE_128K_PTE(
    0x10c158ad,
    g_pszKeyName_MAXWELL_WDDM2_FORCE_128K_PTE,
    g_pszRemappedName_MAXWELL_WDDM2_FORCE_128K_PTE,
    g_pszMainDocs_MAXWELL_WDDM2_FORCE_128K_PTE,
    g_pszDefinedWhen_MAXWELL_WDDM2_FORCE_128K_PTE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MAXWELL_WDDM2_FORCE_128K_PTE, 
    2, 
    g_aDefaultData_MAXWELL_WDDM2_FORCE_128K_PTE, 
    1 
);

static const char *g_pszKeyName_MCAFRSHOWOVERLAP = "MCAFRSHOWOVERLAP";
static const char *g_pszDefinedWhen_MCAFRSHOWOVERLAP = "1";
static const char *g_pszRemappedName_MCAFRSHOWOVERLAP = "D3DOGL_1eee1671";
static const char *g_pszMainDocs_MCAFRSHOWOVERLAP = "";

static const char * (g_ppszDefineDataNames_MCAFRSHOWOVERLAP_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MCAFRSHOWOVERLAP_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MCAFRSHOWOVERLAP[] =
{
    { (const char **)g_ppszDefineDataNames_MCAFRSHOWOVERLAP_OFF, 0x34045364 , "" },
    { (const char **)g_ppszDefineDataNames_MCAFRSHOWOVERLAP_ON, 0x24554582 , "" },
};

DataDefaultDWORD g_aDefaultData_MCAFRSHOWOVERLAP[] =
{
    {"DEFAULT", 0x34045364, "" }, 
};

SettingDWORD g_setting_MCAFRSHOWOVERLAP(
    0x101a3258,
    g_pszKeyName_MCAFRSHOWOVERLAP,
    g_pszRemappedName_MCAFRSHOWOVERLAP,
    g_pszMainDocs_MCAFRSHOWOVERLAP,
    g_pszDefinedWhen_MCAFRSHOWOVERLAP,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MCAFRSHOWOVERLAP, 
    2, 
    g_aDefaultData_MCAFRSHOWOVERLAP, 
    1 
);

static const char *g_pszKeyName_MCALLOWUNRESTRICTEDAFR = "MCALLOWUNRESTRICTEDAFR";
static const char *g_pszDefinedWhen_MCALLOWUNRESTRICTEDAFR = "1";
static const char *g_pszRemappedName_MCALLOWUNRESTRICTEDAFR = "D3DOGL_fd4c5f";
static const char *g_pszMainDocs_MCALLOWUNRESTRICTEDAFR = "Bypass limitation of AFR to 2 GPUs on Pascal and newer GPUs";

static const char * (g_ppszDefineDataNames_MCALLOWUNRESTRICTEDAFR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MCALLOWUNRESTRICTEDAFR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MCALLOWUNRESTRICTEDAFR[] =
{
    { (const char **)g_ppszDefineDataNames_MCALLOWUNRESTRICTEDAFR_OFF, 0x49368db , "" },
    { (const char **)g_ppszDefineDataNames_MCALLOWUNRESTRICTEDAFR_ON, 0x1f296c1 , "" },
};

DataDefaultDWORD g_aDefaultData_MCALLOWUNRESTRICTEDAFR[] =
{
    {"DEFAULT", 0x49368db, "" }, 
};

SettingDWORD g_setting_MCALLOWUNRESTRICTEDAFR(
    0x10fd4c5f,
    g_pszKeyName_MCALLOWUNRESTRICTEDAFR,
    g_pszRemappedName_MCALLOWUNRESTRICTEDAFR,
    g_pszMainDocs_MCALLOWUNRESTRICTEDAFR,
    g_pszDefinedWhen_MCALLOWUNRESTRICTEDAFR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MCALLOWUNRESTRICTEDAFR, 
    2, 
    g_aDefaultData_MCALLOWUNRESTRICTEDAFR, 
    1 
);

static const char *g_pszKeyName_MCCOMPAT = "MCCOMPAT";
static const char *g_pszDefinedWhen_MCCOMPAT = "1";
static const char *g_pszRemappedName_MCCOMPAT = "D3DOGL_67207556";
static const char *g_pszMainDocs_MCCOMPAT = "";

static const char * (g_ppszDefineDataNames_MCCOMPAT_AUTOSELECT)[] =
{
    "AUTOSELECT",
    "ENABLE_SLI_AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR)[] =
{
    "FORCE_AFR",
    "FORCE_2AFR",
    "FORCE_2_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_SFR)[] =
{
    "FORCE_SFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_2AFR)[] =
{
    "FORCE_AFR_OF_SFR__FALLBACK_2AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISABLE_SLI)[] =
{
    "DISABLE_SLI",
    "FORCE_SINGLE",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_4AFR)[] =
{
    "FORCE_4AFR",
    "FORCE_4_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_3AFR)[] =
{
    "FORCE_3AFR",
    "FORCE_3_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_3AFR)[] =
{
    "FORCE_AFR_OF_SFR__FALLBACK_3AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_SLI_MODE_MASK)[] =
{
    "SLI_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RESERVED4)[] =
{
    "RESERVED4",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_STATIC_OR_WRITEONLY_VB_IN_HOST)[] =
{
    "STATIC_OR_WRITEONLY_VB_IN_HOST",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_LOCKABLE_TEXTURES_IN_HOST)[] =
{
    "LOCKABLE_TEXTURES_IN_HOST",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RELEASE_GPU_FOR_CUDA)[] =
{
    "RELEASE_GPU_FOR_CUDA",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_IGNORE_TINY_LOCKS)[] =
{
    "IGNORE_TINY_LOCKS",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_IGNORE_LOCK_ON_PRIMARY)[] =
{
    "IGNORE_LOCK_ON_PRIMARY",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_IGNORE_PIXELQUERY)[] =
{
    "IGNORE_PIXELQUERY",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_TEXTURING_SYNC)[] =
{
    "AFR_DISCARD_TEXTURING_SYNC",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_APPBUG_FORCE_FLIPCHAIN_SYNC)[] =
{
    "APPBUG_FORCE_FLIPCHAIN_SYNC",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_LASTMINUTE_FIXES)[] =
{
    "LASTMINUTE_FIXES",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_IGNORE_EVENTQUERY)[] =
{
    "IGNORE_EVENTQUERY",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISABLE_TEXTURE_PUSH)[] =
{
    "DISABLE_TEXTURE_PUSH",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_LIMIT_EARLY_PUSH_UP_TO_MIDSIZE_SURFACES)[] =
{
    "LIMIT_EARLY_PUSH_UP_TO_MIDSIZE_SURFACES",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_TEXTURING_SYNC_ON_ZB)[] =
{
    "DISCARD_TEXTURING_SYNC_ON_ZB",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_SYNC_TEXTURE_LARGER_THAN_PRIMARY)[] =
{
    "AFR_DISCARD_SYNC_TEXTURE_LARGER_THAN_PRIMARY",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RESERVED19)[] =
{
    "RESERVED19",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_CONTENT_OF_CUBE_MIP_TEXTURES)[] =
{
    "DISCARD_CONTENT_OF_CUBE_MIP_TEXTURES",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_ALL_BUT_TINY_TEXTURING_SYNC)[] =
{
    "AFR_DISCARD_ALL_BUT_TINY_TEXTURING_SYNC",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_SFR_ON_TEXTURES)[] =
{
    "SFR_ON_TEXTURES",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_SRT)[] =
{
    "DISCARD_RT_CONTENTS_ON_SRT",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_ASSUME_NOINTERFRAME_BLITS)[] =
{
    "ASSUME_NOINTERFRAME_BLITS",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_LIMIT_EARLY_PUSH_TO_TINY_SURFACES_ONLY)[] =
{
    "LIMIT_EARLY_PUSH_TO_TINY_SURFACES_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT)[] =
{
    "DISCARD_RT_CONTENTS_ON_PARTIAL_SRT",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_AFR2_FLAGS)[] =
{
    "AFR2_FLAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_2_AFR2)[] =
{
    "FORCE_2_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_3_AFR2)[] =
{
    "FORCE_3_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_FORCE_4_AFR2)[] =
{
    "FORCE_4_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_OPTIMAL)[] =
{
    "OPTIMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT2)[] =
{
    "DISCARD_RT_CONTENTS_ON_PARTIAL_SRT2",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RESERVED27)[] =
{
    "RESERVED27",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RESERVED28)[] =
{
    "RESERVED28",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_RESERVED29)[] =
{
    "RESERVED29",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_WHEN_BLENDING)[] =
{
    "DISCARD_RT_CONTENTS_WHEN_BLENDING",
    NULL
};

static const char * (g_ppszDefineDataNames_MCCOMPAT_OVERRIDE_BIT)[] =
{
    "OVERRIDE_BIT",
    NULL
};

DataValueDWORD g_aDefineData_MCCOMPAT[] =
{
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_AUTOSELECT, 0x00000000 , "the default value when no sli mode is set" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR, 0x00000001 , "Same as FORCE_2AFR, force 2-AFR rendering mode for this app" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_SFR, 0x00000002 , "force SFR rendering mode for this app" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_2AFR, 0x00000003 , "force 2-AFR on 2-way and 3-way, AFR_OF_SFR on 4-way" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISABLE_SLI, 0x00000004 , "disable SLI mode entirely" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_4AFR, 0x00000005 , "force N-way AFR on N-way system" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_3AFR, 0x00000006 , "force 2-AFR on 2-way system and 3-AFR on N-way" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_3AFR, 0x00000007 , "force 2-AFR on 2-way system, 3-AFR on 3-way, AFR_OF_SFR on 4-way" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_SLI_MODE_MASK, 0x00000007 , " --- not a value. This is a mask to select sli mode enum field" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RESERVED4, 0x00000008 , "Reserved" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_STATIC_OR_WRITEONLY_VB_IN_HOST, 0x00000010 , "when no broadcast HW is available, we might put VBs in host to avoid syncing" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_LOCKABLE_TEXTURES_IN_HOST, 0x00000020 , "when no broadcast HW is available, we want to put lockable textures in host to avoid syncing" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RELEASE_GPU_FOR_CUDA, 0x00000040 , "if cuda is active, release the last gpu for cuda, Tesla only" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_IGNORE_TINY_LOCKS, 0x00000080 , "ignore surface locks for <= 2x2 surfaces or 2x2 lock rectangles" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_IGNORE_LOCK_ON_PRIMARY, 0x00000100 , "ignore primary surface locks" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_IGNORE_PIXELQUERY, 0x00000200 , "ignore pixel queries (sync/locks)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_TEXTURING_SYNC, 0x00000400 , "Hacky bit, use only when absolutely non-avoidable: Do not AFR-sync texture before texturing. (65/70 drivers: it was DONT_SYNC_ON_TEXTURE_PUSH)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_APPBUG_FORCE_FLIPCHAIN_SYNC, 0x00000800 , "sync flipchain, if app does not clear every frame. Was used in nvr70 as ENABLE_VTEX_IN_AFR." },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_LASTMINUTE_FIXES, 0x00001000 , "use this bit for the critical last minute's fixes. Was used in nvr65 drivers (DONT_ASSUME_SRT_ON_TEXTURE_MEANS_CLEAN)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_IGNORE_EVENTQUERY, 0x00002000 , "ignore event queries (sync/locks)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISABLE_TEXTURE_PUSH, 0x00004000 , "disable texture push for syncing in AFR's mode" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_LIMIT_EARLY_PUSH_UP_TO_MIDSIZE_SURFACES, 0x00008000 , "Limit early push strategy up to midsize 0x100 x 0x100 sufaces" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_TEXTURING_SYNC_ON_ZB, 0x00010000 , "Skip sync on texturing for Z-buffers" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_SYNC_TEXTURE_LARGER_THAN_PRIMARY, 0x00020000 , "for disabling textures that are larger than primary" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RESERVED19, 0x00040000 , "Reserved" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_CONTENT_OF_CUBE_MIP_TEXTURES, 0x00080000 , "Discard content of cube maped or mip mapped textures" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_AFR_DISCARD_ALL_BUT_TINY_TEXTURING_SYNC, 0x00100000 , "Even hackier bit: skip all texture sycns but very small ones (2x2)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_SFR_ON_TEXTURES, 0x00200000 , "split textures in SFR." },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_SRT, 0x00400000 , "Assume a surface will be fully rendered on full target sets and" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_ASSUME_NOINTERFRAME_BLITS, 0x00800000 , "Assume blits don't need to migrate, even if semantics suggest we do." },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_LIMIT_EARLY_PUSH_TO_TINY_SURFACES_ONLY, 0x01000000 , "Allow early push strategy for tiny 2x2 and smaller surfaces only" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT, 0x02000000 , "Assume even a partial SRT can safely discard contents" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_AFR2_FLAGS, 0x02400000 , "'fast' SLI mode for UI in app profiles (DISCARD_RT_CONTENTS_ON_PARTIAL_SRT|DISCARD_RT_CONTENTS_ON_SRT" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_2_AFR2, 0x02400001 , "(AFR2_FLAGS|FORCE_2AFR)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_3_AFR2, 0x02400006 , "(AFR2_FLAGS|FORCE_3AFR)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_FORCE_4_AFR2, 0x02400005 , "(AFR2_FLAGS|FORCE_4AFR)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_OPTIMAL, 0x02400001 , "deprecated: for compatibility only (FORCE_2_AFR2)" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT2, 0x04000000 , "Assume partial SRT can be safely discarded, unless it uses more than one viewport" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RESERVED27, 0x08000000 , "Reserved" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RESERVED28, 0x10000000 , "Reserved" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_RESERVED29, 0x20000000 , "Reserved" },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_DISCARD_RT_CONTENTS_WHEN_BLENDING, 0x40000000 , "Skip sync before blending." },
    { (const char **)g_ppszDefineDataNames_MCCOMPAT_OVERRIDE_BIT, 0x80000000 , "" },
};

DataDefaultDWORD g_aDefaultData_MCCOMPAT[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MCCOMPAT(
    0x1095def8,
    g_pszKeyName_MCCOMPAT,
    g_pszRemappedName_MCCOMPAT,
    g_pszMainDocs_MCCOMPAT,
    g_pszDefinedWhen_MCCOMPAT,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_MCCOMPAT, 
    43, 
    g_aDefaultData_MCCOMPAT, 
    1 
);

static const char *g_pszKeyName_MCSFRLOADBALANCE = "MCSFRLOADBALANCE";
static const char *g_pszDefinedWhen_MCSFRLOADBALANCE = "1";
static const char *g_pszRemappedName_MCSFRLOADBALANCE = "D3DOGL_57567671";
static const char *g_pszMainDocs_MCSFRLOADBALANCE = "";

static const char * (g_ppszDefineDataNames_MCSFRLOADBALANCE_STATIC)[] =
{
    "STATIC",
    NULL
};

static const char * (g_ppszDefineDataNames_MCSFRLOADBALANCE_DYNAMIC)[] =
{
    "DYNAMIC",
    NULL
};

DataValueDWORD g_aDefineData_MCSFRLOADBALANCE[] =
{
    { (const char **)g_ppszDefineDataNames_MCSFRLOADBALANCE_STATIC, 0x28384382 , "each GPU receives a equal amount of pixels to process" },
    { (const char **)g_ppszDefineDataNames_MCSFRLOADBALANCE_DYNAMIC, 0x60606064 , "moves the split line dynamically to accomodate the load" },
};

DataDefaultDWORD g_aDefaultData_MCSFRLOADBALANCE[] =
{
    {"DEFAULT", 0x60606064, "" }, 
};

SettingDWORD g_setting_MCSFRLOADBALANCE(
    0x103c2e03,
    g_pszKeyName_MCSFRLOADBALANCE,
    g_pszRemappedName_MCSFRLOADBALANCE,
    g_pszMainDocs_MCSFRLOADBALANCE,
    g_pszDefinedWhen_MCSFRLOADBALANCE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MCSFRLOADBALANCE, 
    2, 
    g_aDefaultData_MCSFRLOADBALANCE, 
    1 
);

static const char *g_pszKeyName_MCSFRSHOWSPLIT = "MCSFRSHOWSPLIT";
static const char *g_pszDefinedWhen_MCSFRSHOWSPLIT = "1";
static const char *g_pszRemappedName_MCSFRSHOWSPLIT = "D3DOGL_1ee11671";
static const char *g_pszMainDocs_MCSFRSHOWSPLIT = "Show or hide the SLI on-screen indicator";

static const char * (g_ppszDefineDataNames_MCSFRSHOWSPLIT_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_MCSFRSHOWSPLIT_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_MCSFRSHOWSPLIT[] =
{
    { (const char **)g_ppszDefineDataNames_MCSFRSHOWSPLIT_DISABLED, 0x34534064 , "there is no loadbalance information displayed" },
    { (const char **)g_ppszDefineDataNames_MCSFRSHOWSPLIT_ENABLED, 0x24545582 , "moves the split line dynamically" },
};

DataDefaultDWORD g_aDefaultData_MCSFRSHOWSPLIT[] =
{
    {"DEFAULT", 0x34534064, "" }, 
};

SettingDWORD g_setting_MCSFRSHOWSPLIT(
    0x10287051,
    g_pszKeyName_MCSFRSHOWSPLIT,
    g_pszRemappedName_MCSFRSHOWSPLIT,
    g_pszMainDocs_MCSFRSHOWSPLIT,
    g_pszDefinedWhen_MCSFRSHOWSPLIT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MCSFRSHOWSPLIT, 
    2, 
    g_aDefaultData_MCSFRSHOWSPLIT, 
    1 
);

static const char *g_pszKeyName_MCTIMELINE = "MCTIMELINE";
static const char *g_pszDefinedWhen_MCTIMELINE = "1";
static const char *g_pszRemappedName_MCTIMELINE = "D3DOGL_1671ee11";
static const char *g_pszMainDocs_MCTIMELINE = "";

static const char * (g_ppszDefineDataNames_MCTIMELINE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MCTIMELINE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MCTIMELINE[] =
{
    { (const char **)g_ppszDefineDataNames_MCTIMELINE_OFF, 0x40345364 , "" },
    { (const char **)g_ppszDefineDataNames_MCTIMELINE_ON, 0x24545582 , "" },
};

DataDefaultDWORD g_aDefaultData_MCTIMELINE[] =
{
    {"DEFAULT", 0x40345364, "" }, 
};

SettingDWORD g_setting_MCTIMELINE(
    0x10de0e9f,
    g_pszKeyName_MCTIMELINE,
    g_pszRemappedName_MCTIMELINE,
    g_pszMainDocs_MCTIMELINE,
    g_pszDefinedWhen_MCTIMELINE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MCTIMELINE, 
    2, 
    g_aDefaultData_MCTIMELINE, 
    1 
);

static const char *g_pszKeyName_MESSAGE_BOX_ON_GPU_DISCONNECT = "MESSAGE_BOX_ON_GPU_DISCONNECT";
static const char *g_pszDefinedWhen_MESSAGE_BOX_ON_GPU_DISCONNECT = "1";
static const char *g_pszRemappedName_MESSAGE_BOX_ON_GPU_DISCONNECT = "D3DOGL_200205511";
static const char *g_pszMainDocs_MESSAGE_BOX_ON_GPU_DISCONNECT = "";

static const char * (g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_SAFE_EXIT)[] =
{
    "HIDE_SAFE_EXIT",
    NULL
};

static const char * (g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_SHOW)[] =
{
    "SHOW",
    NULL
};

static const char * (g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_NOEXIT)[] =
{
    "HIDE_NOEXIT",
    NULL
};

static const char * (g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_UNSAFE_EXIT)[] =
{
    "HIDE_UNSAFE_EXIT",
    NULL
};

DataValueDWORD g_aDefineData_MESSAGE_BOX_ON_GPU_DISCONNECT[] =
{
    { (const char **)g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_SAFE_EXIT, 0x00000001 , "Hide the dialog and exit silently with ExitProcess() // invokes DllMain" },
    { (const char **)g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_SHOW, 0x00000002 , "Show the dialog and exit if requested" },
    { (const char **)g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_NOEXIT, 0x00000004 , "Hide the dialog and do not exit" },
    { (const char **)g_ppszDefineDataNames_MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_UNSAFE_EXIT, 0x00000008 , "Hide the dialog and exit silently with TerminateProcess() // doesn't invoke DllMain" },
};

DataDefaultDWORD g_aDefaultData_MESSAGE_BOX_ON_GPU_DISCONNECT[] =
{
    {"DEFAULT", 0x00000004, "" }, 
};

SettingDWORD g_setting_MESSAGE_BOX_ON_GPU_DISCONNECT(
    0x10fadc95,
    g_pszKeyName_MESSAGE_BOX_ON_GPU_DISCONNECT,
    g_pszRemappedName_MESSAGE_BOX_ON_GPU_DISCONNECT,
    g_pszMainDocs_MESSAGE_BOX_ON_GPU_DISCONNECT,
    g_pszDefinedWhen_MESSAGE_BOX_ON_GPU_DISCONNECT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MESSAGE_BOX_ON_GPU_DISCONNECT, 
    4, 
    g_aDefaultData_MESSAGE_BOX_ON_GPU_DISCONNECT, 
    1 
);

static const char *g_pszKeyName_MIPMAPMODE = "MIPMAPMODE";
static const char *g_pszDefinedWhen_MIPMAPMODE = "1";
static const char *g_pszRemappedName_MIPMAPMODE = "D3DOGL_03385531";
static const char *g_pszMainDocs_MIPMAPMODE = "trilinear mipmap optimizations";

static const char * (g_ppszDefineDataNames_MIPMAPMODE_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_MIPMAPMODE_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_MIPMAPMODE_BILINEAR)[] =
{
    "BILINEAR",
    NULL
};

static const char * (g_ppszDefineDataNames_MIPMAPMODE_TRILINEAR)[] =
{
    "TRILINEAR",
    NULL
};

DataValueDWORD g_aDefineData_MIPMAPMODE[] =
{
    { (const char **)g_ppszDefineDataNames_MIPMAPMODE_MASK, 0x0000000f , "" },
    { (const char **)g_ppszDefineDataNames_MIPMAPMODE_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_MIPMAPMODE_BILINEAR, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_MIPMAPMODE_TRILINEAR, 0x00000002 , "" },
};

DataDefaultDWORD g_aDefaultData_MIPMAPMODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MIPMAPMODE(
    0x10c73892,
    g_pszKeyName_MIPMAPMODE,
    g_pszRemappedName_MIPMAPMODE,
    g_pszMainDocs_MIPMAPMODE,
    g_pszDefinedWhen_MIPMAPMODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MIPMAPMODE, 
    4, 
    g_aDefaultData_MIPMAPMODE, 
    1 
);

static const char *g_pszKeyName_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS = "MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS";
static const char *g_pszDefinedWhen_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS = "1";
static const char *g_pszRemappedName_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS = "D3DOGL_200330308";
static const char *g_pszMainDocs_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS = "Enable Disable D3D12 Present time feature optimization";

static const char * (g_ppszDefineDataNames_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS[] =
{
    { (const char **)g_ppszDefineDataNames_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_DISABLED, 0x0 , " Disable D3D12 Present time feature optimization" },
    { (const char **)g_ppszDefineDataNames_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ENABLED, 0x1 , "Enable D3D12 Present time feature optimization" },
};

DataDefaultDWORD g_aDefaultData_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS(
    0x10fadc96,
    g_pszKeyName_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS,
    g_pszRemappedName_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS,
    g_pszMainDocs_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS,
    g_pszDefinedWhen_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS, 
    2, 
    g_aDefaultData_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS, 
    1 
);

static const char *g_pszKeyName_MS_HYBRID_COPY_QUEUE_FLAGS = "MS_HYBRID_COPY_QUEUE_FLAGS";
static const char *g_pszDefinedWhen_MS_HYBRID_COPY_QUEUE_FLAGS = "1";
static const char *g_pszRemappedName_MS_HYBRID_COPY_QUEUE_FLAGS = "D3DOGL_1242270";
static const char *g_pszMainDocs_MS_HYBRID_COPY_QUEUE_FLAGS = "Override flags for copy queue creation on MsHybrid";

static const char * (g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_3D)[] =
{
    "COMMAND_QUEUE_FLAG_3D",
    NULL
};

static const char * (g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COMPUTE)[] =
{
    "COMMAND_QUEUE_FLAG_COMPUTE",
    NULL
};

static const char * (g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COPY)[] =
{
    "COMMAND_QUEUE_FLAG_COPY",
    NULL
};

DataValueDWORD g_aDefineData_MS_HYBRID_COPY_QUEUE_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_3D, 0x00000001 , "Create 3D context" },
    { (const char **)g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COMPUTE, 0x00000002 , "Create Compute context" },
    { (const char **)g_ppszDefineDataNames_MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COPY, 0x00000004 , "Create CE context" },
};

DataDefaultDWORD g_aDefaultData_MS_HYBRID_COPY_QUEUE_FLAGS[] =
{
    {"DEFAULT", 0x00000004, "" }, 
};

SettingDWORD g_setting_MS_HYBRID_COPY_QUEUE_FLAGS(
    0x10fadc83,
    g_pszKeyName_MS_HYBRID_COPY_QUEUE_FLAGS,
    g_pszRemappedName_MS_HYBRID_COPY_QUEUE_FLAGS,
    g_pszMainDocs_MS_HYBRID_COPY_QUEUE_FLAGS,
    g_pszDefinedWhen_MS_HYBRID_COPY_QUEUE_FLAGS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MS_HYBRID_COPY_QUEUE_FLAGS, 
    3, 
    g_aDefaultData_MS_HYBRID_COPY_QUEUE_FLAGS, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM = "MULTIGPU_BROADCAST_SHIM";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM = "1";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM = "D3D_54312267";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM = "Enable Multi-GPU Broadcast shim";

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MULTIGPU_BROADCAST_SHIM[] =
{
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_MULTIGPU_BROADCAST_SHIM[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_MULTIGPU_BROADCAST_SHIM(
    0x108f0842,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MULTIGPU_BROADCAST_SHIM, 
    2, 
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME = "MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME = "D3D_54312270";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME = "App name for which backbuffer is to be dumped.";

DataDefaultSTRING g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME(
    0x108f0845,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER = "MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER = "D3D_54312269";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER = "Dump backbuffer from Multi-GPU Broadcast shim";

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER[] =
{
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER(
    0x108f0844,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER, 
    2, 
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER = "MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER = "D3D_54312271";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER = "Frame number to dump";

DataDefaultDWORD g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER[] =
{
    {"DEFAULT", 0x20, "" }, 
};

SettingDWORD g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER(
    0x108f0846,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_PATH = "MULTIGPU_BROADCAST_SHIM_DUMP_PATH";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_PATH = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_PATH = "D3D_54312272";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_PATH = "Path where backbuffer is to be dumped.";

DataDefaultSTRING g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_PATH[] =
{
    {"DEFAULT", "C:\\FD", "" }, 
};

SettingSTRING g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_PATH(
    0x108f0847,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_DUMP_PATH,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_DUMP_PATH,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_DUMP_PATH,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_DUMP_PATH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_DUMP_PATH, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_LOG = "MULTIGPU_BROADCAST_SHIM_LOG";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_LOG = "1";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_LOG = "D3D_54312273";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_LOG = "Dump log from Multi-GPU Broadcast shim";

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_LOG_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_LOG_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_MULTIGPU_BROADCAST_SHIM_LOG[] =
{
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_LOG_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_MULTIGPU_BROADCAST_SHIM_LOG_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_MULTIGPU_BROADCAST_SHIM_LOG[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MULTIGPU_BROADCAST_SHIM_LOG(
    0x108f0848,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_LOG,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_LOG,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_LOG,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_LOG,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_MULTIGPU_BROADCAST_SHIM_LOG, 
    2, 
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_LOG, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_BROADCAST_SHIM_LOG_FILE = "MULTIGPU_BROADCAST_SHIM_LOG_FILE";
static const char *g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_LOG_FILE = "1";
static const char *g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_LOG_FILE = "D3D_54312274";
static const char *g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_LOG_FILE = "File where log is to be created.";

DataDefaultSTRING g_aDefaultData_MULTIGPU_BROADCAST_SHIM_LOG_FILE[] =
{
    {"DEFAULT", "C:\\log", "" }, 
};

SettingSTRING g_setting_MULTIGPU_BROADCAST_SHIM_LOG_FILE(
    0x108f0874,
    g_pszKeyName_MULTIGPU_BROADCAST_SHIM_LOG_FILE,
    g_pszRemappedName_MULTIGPU_BROADCAST_SHIM_LOG_FILE,
    g_pszMainDocs_MULTIGPU_BROADCAST_SHIM_LOG_FILE,
    g_pszDefinedWhen_MULTIGPU_BROADCAST_SHIM_LOG_FILE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MULTIGPU_BROADCAST_SHIM_LOG_FILE, 
    1 
);

static const char *g_pszKeyName_MULTIGPU_EOF_COPY_LOOP = "MULTIGPU_EOF_COPY_LOOP";
static const char *g_pszDefinedWhen_MULTIGPU_EOF_COPY_LOOP = "1";
static const char *g_pszRemappedName_MULTIGPU_EOF_COPY_LOOP = "D3DOGL_93284741";
static const char *g_pszMainDocs_MULTIGPU_EOF_COPY_LOOP = "Number of times to loop the copy to simulate transfer bound cases on MsHybrid and SLI";

DataDefaultDWORD g_aDefaultData_MULTIGPU_EOF_COPY_LOOP[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_MULTIGPU_EOF_COPY_LOOP(
    0x10f9dc01,
    g_pszKeyName_MULTIGPU_EOF_COPY_LOOP,
    g_pszRemappedName_MULTIGPU_EOF_COPY_LOOP,
    g_pszMainDocs_MULTIGPU_EOF_COPY_LOOP,
    g_pszDefinedWhen_MULTIGPU_EOF_COPY_LOOP,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_MULTIGPU_EOF_COPY_LOOP, 
    1 
);

static const char *g_pszKeyName_NGX_CDN_MODE = "NGX_CDN_MODE";
static const char *g_pszDefinedWhen_NGX_CDN_MODE = "1";
static const char *g_pszRemappedName_NGX_CDN_MODE = "D3DOGL_11515748";
static const char *g_pszMainDocs_NGX_CDN_MODE = "Used to set the server to use for snippet OTA.";

static const char * (g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_PRODUCTION)[] =
{
    "NGX_CDN_MODE_PRODUCTION",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_STAGING)[] =
{
    "NGX_CDN_MODE_STAGING",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_DISABLED)[] =
{
    "NGX_CDN_MODE_DISABLED",
    NULL
};

DataValueDWORD g_aDefineData_NGX_CDN_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_PRODUCTION, 0x0000 , "Use the production server." },
    { (const char **)g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_STAGING, 0x0001 , "Use the staging server. FOR INTERNAL TESTING ONLY." },
    { (const char **)g_ppszDefineDataNames_NGX_CDN_MODE_NGX_CDN_MODE_DISABLED, 0xFFFF , "Do not use the downloaded snippets. Force use of the embedded snippets. FOR INTERNAL TESTING ONLY." },
};

DataDefaultDWORD g_aDefaultData_NGX_CDN_MODE[] =
{
    {"DEFAULT", 0x0000, "" }, 
};

SettingDWORD g_setting_NGX_CDN_MODE(
    0x10afb764,
    g_pszKeyName_NGX_CDN_MODE,
    g_pszRemappedName_NGX_CDN_MODE,
    g_pszMainDocs_NGX_CDN_MODE,
    g_pszDefinedWhen_NGX_CDN_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NGX_CDN_MODE, 
    3, 
    g_aDefaultData_NGX_CDN_MODE, 
    1 
);

static const char *g_pszKeyName_NGX_CDN_PRODUCTION_URI = "NGX_CDN_PRODUCTION_URI";
static const char *g_pszDefinedWhen_NGX_CDN_PRODUCTION_URI = "1";
static const char *g_pszRemappedName_NGX_CDN_PRODUCTION_URI = "D3DOGL_11515749";
static const char *g_pszMainDocs_NGX_CDN_PRODUCTION_URI = "Used to specify the production server URI to use for snippet OTA updates. Advanced use only.";

DataDefaultSTRING g_aDefaultData_NGX_CDN_PRODUCTION_URI[] =
{
    {"DEFAULT", "https://static.nvidiagrid.net/models/org/nvidia/team/ngx/models/", "" }, 
};

SettingSTRING g_setting_NGX_CDN_PRODUCTION_URI(
    0x10afb765,
    g_pszKeyName_NGX_CDN_PRODUCTION_URI,
    g_pszRemappedName_NGX_CDN_PRODUCTION_URI,
    g_pszMainDocs_NGX_CDN_PRODUCTION_URI,
    g_pszDefinedWhen_NGX_CDN_PRODUCTION_URI,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_NGX_CDN_PRODUCTION_URI, 
    1 
);

static const char *g_pszKeyName_NGX_CDN_STAGING_URI = "NGX_CDN_STAGING_URI";
static const char *g_pszDefinedWhen_NGX_CDN_STAGING_URI = "1";
static const char *g_pszRemappedName_NGX_CDN_STAGING_URI = "D3DOGL_11515750";
static const char *g_pszMainDocs_NGX_CDN_STAGING_URI = "Used to specify the staging server URI to use for snippet OTA updates. Advanced use only.";

DataDefaultSTRING g_aDefaultData_NGX_CDN_STAGING_URI[] =
{
    {"DEFAULT", "https://static.nvidiagrid.net/stg-models/org/nvidia/team/ngx/models/", "" }, 
};

SettingSTRING g_setting_NGX_CDN_STAGING_URI(
    0x10afb766,
    g_pszKeyName_NGX_CDN_STAGING_URI,
    g_pszRemappedName_NGX_CDN_STAGING_URI,
    g_pszMainDocs_NGX_CDN_STAGING_URI,
    g_pszDefinedWhen_NGX_CDN_STAGING_URI,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_NGX_CDN_STAGING_URI, 
    1 
);

static const char *g_pszKeyName_NGX_DLSS_MODE = "NGX_DLSS_MODE";
static const char *g_pszDefinedWhen_NGX_DLSS_MODE = "1";
static const char *g_pszRemappedName_NGX_DLSS_MODE = "D3DOGL_11515752";
static const char *g_pszMainDocs_NGX_DLSS_MODE = "Used to force DLSS to a specific mode. Used for testing.";

static const char * (g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_PERFORMANCE)[] =
{
    "NGX_DLSS_MODE_PERFORMANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_BALANCED)[] =
{
    "NGX_DLSS_MODE_BALANCED",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_QUALITY)[] =
{
    "NGX_DLSS_MODE_QUALITY",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_SNIPPET_CONTROLLED)[] =
{
    "NGX_DLSS_MODE_SNIPPET_CONTROLLED",
    NULL
};

DataValueDWORD g_aDefineData_NGX_DLSS_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_PERFORMANCE, 0x0000 , "Force DLSS to use perfomance mode." },
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_BALANCED, 0x0001 , "Force DLSS to use balanced mode." },
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_QUALITY, 0x0002 , "Force DLSS to use quality mode." },
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_MODE_NGX_DLSS_MODE_SNIPPET_CONTROLLED, 0x0003 , "Allow snippet to control DLSS mode. Default setting." },
};

DataDefaultDWORD g_aDefaultData_NGX_DLSS_MODE[] =
{
    {"DEFAULT", 0x0003, "" }, 
};

SettingDWORD g_setting_NGX_DLSS_MODE(
    0x10afb768,
    g_pszKeyName_NGX_DLSS_MODE,
    g_pszRemappedName_NGX_DLSS_MODE,
    g_pszMainDocs_NGX_DLSS_MODE,
    g_pszDefinedWhen_NGX_DLSS_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NGX_DLSS_MODE, 
    4, 
    g_aDefaultData_NGX_DLSS_MODE, 
    1 
);

static const char *g_pszKeyName_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS = "NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS";
static const char *g_pszDefinedWhen_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS = "1";
static const char *g_pszRemappedName_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS = "D3DOGL_11515756";
static const char *g_pszMainDocs_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS = "Force some optimal settings to values outside of what they were when the game launched. Mostly used to override 4X scaling ratio to 9X for Ampere launch. Bitfield so that we can combine several override in the future..";

static const char * (g_ppszDefineDataNames_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NONE)[] =
{
    "NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_PERF_TO_9X)[] =
{
    "NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_PERF_TO_9X",
    NULL
};

DataValueDWORD g_aDefineData_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NONE, 0x0000 , "No change to optimal rendering resolution." },
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_PERF_TO_9X, 0x0001 , "Force DLSS to return 9X optimal rendering resolution instead of 4X in Perf mode." },
};

DataDefaultDWORD g_aDefaultData_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS[] =
{
    {"DEFAULT", 0x0000, "" }, 
};

SettingDWORD g_setting_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS(
    0x10afb76c,
    g_pszKeyName_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS,
    g_pszRemappedName_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS,
    g_pszMainDocs_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS,
    g_pszDefinedWhen_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS, 
    2, 
    g_aDefaultData_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS, 
    1 
);

static const char *g_pszKeyName_NGX_DLSS_SHARPNESS_SETTING = "NGX_DLSS_SHARPNESS_SETTING";
static const char *g_pszDefinedWhen_NGX_DLSS_SHARPNESS_SETTING = "1";
static const char *g_pszRemappedName_NGX_DLSS_SHARPNESS_SETTING = "D3DOGL_11515751";
static const char *g_pszMainDocs_NGX_DLSS_SHARPNESS_SETTING = "String contains multiple sharpness values that are to be used per resolution bucket (1080p, 1440p, 2160p, 2160p+)/ upscale type. Example sharpness.lanczos=[[2.4][3.0][4.1][4.1]];sharpness.deepisp=[[2.4][3.0][4.1][4.1]];sharpness.nvtaa[[2.9][3.1][3.3][3.5]]";

DataDefaultSTRING g_aDefaultData_NGX_DLSS_SHARPNESS_SETTING[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_NGX_DLSS_SHARPNESS_SETTING(
    0x10afb767,
    g_pszKeyName_NGX_DLSS_SHARPNESS_SETTING,
    g_pszRemappedName_NGX_DLSS_SHARPNESS_SETTING,
    g_pszMainDocs_NGX_DLSS_SHARPNESS_SETTING,
    g_pszDefinedWhen_NGX_DLSS_SHARPNESS_SETTING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_NGX_DLSS_SHARPNESS_SETTING, 
    1 
);

static const char *g_pszKeyName_NGX_DLSS_TYPE = "NGX_DLSS_TYPE";
static const char *g_pszDefinedWhen_NGX_DLSS_TYPE = "1";
static const char *g_pszRemappedName_NGX_DLSS_TYPE = "D3DOGL_11515753";
static const char *g_pszMainDocs_NGX_DLSS_TYPE = "Used to force DLSS to a specific algorithm. Used for testing.";

static const char * (g_ppszDefineDataNames_NGX_DLSS_TYPE_NGX_DLSS_TYPE_DLTSS)[] =
{
    "NGX_DLSS_TYPE_DLTSS",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_DLSS_TYPE_NGX_DLSS_TYPE_NvTAA4x)[] =
{
    "NGX_DLSS_TYPE_NvTAA4x",
    NULL
};

DataValueDWORD g_aDefineData_NGX_DLSS_TYPE[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_TYPE_NGX_DLSS_TYPE_DLTSS, 0x0000 , "Force DLSS to use DLTSS algorithm (DLSS 2.0)." },
    { (const char **)g_ppszDefineDataNames_NGX_DLSS_TYPE_NGX_DLSS_TYPE_NvTAA4x, 0x0001 , "Force DLSS to use NvTAA4x algorithm (DLSS 1.3)." },
};

DataDefaultDWORD g_aDefaultData_NGX_DLSS_TYPE[] =
{
    {"DEFAULT", 0x0000, "" }, 
};

SettingDWORD g_setting_NGX_DLSS_TYPE(
    0x10afb769,
    g_pszKeyName_NGX_DLSS_TYPE,
    g_pszRemappedName_NGX_DLSS_TYPE,
    g_pszMainDocs_NGX_DLSS_TYPE,
    g_pszDefinedWhen_NGX_DLSS_TYPE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NGX_DLSS_TYPE, 
    2, 
    g_aDefaultData_NGX_DLSS_TYPE, 
    1 
);

static const char *g_pszKeyName_NGX_LOG_PATH = "NGX_LOG_PATH";
static const char *g_pszDefinedWhen_NGX_LOG_PATH = "1";
static const char *g_pszRemappedName_NGX_LOG_PATH = "D3DOGL_11515755";
static const char *g_pszMainDocs_NGX_LOG_PATH = "Path where NGX stores the logs";

DataDefaultSTRING g_aDefaultData_NGX_LOG_PATH[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_NGX_LOG_PATH(
    0x10afb76b,
    g_pszKeyName_NGX_LOG_PATH,
    g_pszRemappedName_NGX_LOG_PATH,
    g_pszMainDocs_NGX_LOG_PATH,
    g_pszDefinedWhen_NGX_LOG_PATH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_NGX_LOG_PATH, 
    1 
);

static const char *g_pszKeyName_NGX_OVERRIDE_HW_CHECK = "NGX_OVERRIDE_HW_CHECK";
static const char *g_pszDefinedWhen_NGX_OVERRIDE_HW_CHECK = "1";
static const char *g_pszRemappedName_NGX_OVERRIDE_HW_CHECK = "D3DOGL_11515757";
static const char *g_pszMainDocs_NGX_OVERRIDE_HW_CHECK = "Suppress HW arch detection for NGX support";

static const char * (g_ppszDefineDataNames_NGX_OVERRIDE_HW_CHECK_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_OVERRIDE_HW_CHECK_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NGX_OVERRIDE_HW_CHECK[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_OVERRIDE_HW_CHECK_OFF, 0 , "Normal operation" },
    { (const char **)g_ppszDefineDataNames_NGX_OVERRIDE_HW_CHECK_ON, 1 , "Force enable NGX support" },
};

DataDefaultDWORD g_aDefaultData_NGX_OVERRIDE_HW_CHECK[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NGX_OVERRIDE_HW_CHECK(
    0x10e41df2,
    g_pszKeyName_NGX_OVERRIDE_HW_CHECK,
    g_pszRemappedName_NGX_OVERRIDE_HW_CHECK,
    g_pszMainDocs_NGX_OVERRIDE_HW_CHECK,
    g_pszDefinedWhen_NGX_OVERRIDE_HW_CHECK,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NGX_OVERRIDE_HW_CHECK, 
    2, 
    g_aDefaultData_NGX_OVERRIDE_HW_CHECK, 
    1 
);

static const char *g_pszKeyName_NGX_PRIVATE_FLAGS = "NGX_PRIVATE_FLAGS";
static const char *g_pszDefinedWhen_NGX_PRIVATE_FLAGS = "1";
static const char *g_pszRemappedName_NGX_PRIVATE_FLAGS = "D3DOGL_11515754";
static const char *g_pszMainDocs_NGX_PRIVATE_FLAGS = "Private flags used by NGX.";

static const char * (g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_TURING)[] =
{
    "ENABLE_ZBC_TURING",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_AMPERE)[] =
{
    "ENABLE_ZBC_AMPERE",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_AFTER_AMPERE)[] =
{
    "ENABLE_ZBC_AFTER_AMPERE",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_DVS_CYCLESTATS)[] =
{
    "ENABLE_DVS_CYCLESTATS",
    NULL
};

static const char * (g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_DVS_PUSHBUFFER_DUMP)[] =
{
    "ENABLE_DVS_PUSHBUFFER_DUMP",
    NULL
};

DataValueDWORD g_aDefineData_NGX_PRIVATE_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_TURING, 0x00000001 , "enable ZBC on Turing" },
    { (const char **)g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_AMPERE, 0x00000002 , "enable ZBC on Ampere" },
    { (const char **)g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_ZBC_AFTER_AMPERE, 0x00000004 , "enable ZBC beyond Ampere" },
    { (const char **)g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_DVS_CYCLESTATS, 0x00000008 , "generate cyclestats when running on DVS" },
    { (const char **)g_ppszDefineDataNames_NGX_PRIVATE_FLAGS_ENABLE_DVS_PUSHBUFFER_DUMP, 0x00000010 , "dump pushbuffer when running on DVS" },
};

SettingDWORD g_setting_NGX_PRIVATE_FLAGS(
    0x10afb76a,
    g_pszKeyName_NGX_PRIVATE_FLAGS,
    g_pszRemappedName_NGX_PRIVATE_FLAGS,
    g_pszMainDocs_NGX_PRIVATE_FLAGS,
    g_pszDefinedWhen_NGX_PRIVATE_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_NGX_PRIVATE_FLAGS, 
    5, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_NOFLOATMADENABLE = "NOFLOATMADENABLE";
static const char *g_pszDefinedWhen_NOFLOATMADENABLE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_NOFLOATMADENABLE = "D3DOGL_19286545";
static const char *g_pszMainDocs_NOFLOATMADENABLE = "Force all float MAD to MUL + ADD";

static const char * (g_ppszDefineDataNames_NOFLOATMADENABLE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NOFLOATMADENABLE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NOFLOATMADENABLE[] =
{
    { (const char **)g_ppszDefineDataNames_NOFLOATMADENABLE_OFF, 0x16528890 , "" },
    { (const char **)g_ppszDefineDataNames_NOFLOATMADENABLE_ON, 0x65481281 , "" },
};

DataDefaultDWORD g_aDefaultData_NOFLOATMADENABLE[] =
{
    {"DEFAULT", 0x16528890, "" }, 
};

SettingDWORD g_setting_NOFLOATMADENABLE(
    0x109f5848,
    g_pszKeyName_NOFLOATMADENABLE,
    g_pszRemappedName_NOFLOATMADENABLE,
    g_pszMainDocs_NOFLOATMADENABLE,
    g_pszDefinedWhen_NOFLOATMADENABLE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NOFLOATMADENABLE, 
    2, 
    g_aDefaultData_NOFLOATMADENABLE, 
    1 
);

static const char *g_pszKeyName_NVDEVTOOLS_ENABLE_DEBUGGER = "NVDEVTOOLS_ENABLE_DEBUGGER";
static const char *g_pszDefinedWhen_NVDEVTOOLS_ENABLE_DEBUGGER = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_NVDEVTOOLS_ENABLE_DEBUGGER = "D3DOGL_20120516";
static const char *g_pszMainDocs_NVDEVTOOLS_ENABLE_DEBUGGER = "Enable Nsight debug mode. Used to set the driver in debug mode, in the absence of Nsight";

static const char * (g_ppszDefineDataNames_NVDEVTOOLS_ENABLE_DEBUGGER_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVDEVTOOLS_ENABLE_DEBUGGER_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVDEVTOOLS_ENABLE_DEBUGGER[] =
{
    { (const char **)g_ppszDefineDataNames_NVDEVTOOLS_ENABLE_DEBUGGER_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_NVDEVTOOLS_ENABLE_DEBUGGER_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_NVDEVTOOLS_ENABLE_DEBUGGER[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_NVDEVTOOLS_ENABLE_DEBUGGER(
    0x10b787c3,
    g_pszKeyName_NVDEVTOOLS_ENABLE_DEBUGGER,
    g_pszRemappedName_NVDEVTOOLS_ENABLE_DEBUGGER,
    g_pszMainDocs_NVDEVTOOLS_ENABLE_DEBUGGER,
    g_pszDefinedWhen_NVDEVTOOLS_ENABLE_DEBUGGER,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVDEVTOOLS_ENABLE_DEBUGGER, 
    2, 
    g_aDefaultData_NVDEVTOOLS_ENABLE_DEBUGGER, 
    1 
);

static const char *g_pszKeyName_NVFEATURES_ALLOW = "NVFEATURES_ALLOW";
static const char *g_pszDefinedWhen_NVFEATURES_ALLOW = "1";
static const char *g_pszRemappedName_NVFEATURES_ALLOW = "D3DOGL_0xb135fe";
static const char *g_pszMainDocs_NVFEATURES_ALLOW = "Empowers an app profile to denylist NV features like MFAA,FXAA,Gsync,Ansel,FRL,FRM etc. for any app";

static const char * (g_ppszDefineDataNames_NVFEATURES_ALLOW_DISALLOWED)[] =
{
    "DISALLOWED",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVFEATURES_ALLOW_ALLOWED)[] =
{
    "ALLOWED",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVFEATURES_ALLOW[] =
{
    { (const char **)g_ppszDefineDataNames_NVFEATURES_ALLOW_DISALLOWED, 0 , "NV features are disallowed" },
    { (const char **)g_ppszDefineDataNames_NVFEATURES_ALLOW_ALLOWED, 1 , "Keep NV features in their default state" },
};

DataDefaultDWORD g_aDefaultData_NVFEATURES_ALLOW[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_NVFEATURES_ALLOW(
    0x10b135fe,
    g_pszKeyName_NVFEATURES_ALLOW,
    g_pszRemappedName_NVFEATURES_ALLOW,
    g_pszMainDocs_NVFEATURES_ALLOW,
    g_pszDefinedWhen_NVFEATURES_ALLOW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVFEATURES_ALLOW, 
    2, 
    g_aDefaultData_NVFEATURES_ALLOW, 
    1 
);

static const char *g_pszKeyName_NVINDICATOR = "NVINDICATOR";
static const char *g_pszDefinedWhen_NVINDICATOR = "1";
static const char *g_pszRemappedName_NVINDICATOR = "D3DOGL_1f42d4b3";
static const char *g_pszMainDocs_NVINDICATOR = "Display generic NV Indicator";

static const char * (g_ppszDefineDataNames_NVINDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NVINDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NVINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_NVINDICATOR_OFF, 0x0 , "Disable generic NV Indicator" },
    { (const char **)g_ppszDefineDataNames_NVINDICATOR_ON, 0x1 , "Enable generic NV Indicator" },
};

DataDefaultDWORD g_aDefaultData_NVINDICATOR[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_NVINDICATOR(
    0x10029ab8,
    g_pszKeyName_NVINDICATOR,
    g_pszRemappedName_NVINDICATOR,
    g_pszMainDocs_NVINDICATOR,
    g_pszDefinedWhen_NVINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NVINDICATOR, 
    2, 
    g_aDefaultData_NVINDICATOR, 
    1 
);

static const char *g_pszKeyName_NV_QUALITY_UPSCALING = "NV_QUALITY_UPSCALING";
static const char *g_pszDefinedWhen_NV_QUALITY_UPSCALING = "1";
static const char *g_pszRemappedName_NV_QUALITY_UPSCALING = "D3DOGL_0x444444";
static const char *g_pszMainDocs_NV_QUALITY_UPSCALING = "Toggle NVIDIA Quality upscaling on or off";

static const char * (g_ppszDefineDataNames_NV_QUALITY_UPSCALING_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_NV_QUALITY_UPSCALING_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_NV_QUALITY_UPSCALING[] =
{
    { (const char **)g_ppszDefineDataNames_NV_QUALITY_UPSCALING_OFF, 0 , "Off" },
    { (const char **)g_ppszDefineDataNames_NV_QUALITY_UPSCALING_ON, 1 , "On" },
};

DataDefaultDWORD g_aDefaultData_NV_QUALITY_UPSCALING[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_NV_QUALITY_UPSCALING(
    0x10444444,
    g_pszKeyName_NV_QUALITY_UPSCALING,
    g_pszRemappedName_NV_QUALITY_UPSCALING,
    g_pszMainDocs_NV_QUALITY_UPSCALING,
    g_pszDefinedWhen_NV_QUALITY_UPSCALING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_NV_QUALITY_UPSCALING, 
    2, 
    g_aDefaultData_NV_QUALITY_UPSCALING, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_FP16_SUPPORT = "OCGCONTROL_FP16_SUPPORT";
static const char *g_pszDefinedWhen_OCGCONTROL_FP16_SUPPORT = "1";
static const char *g_pszRemappedName_OCGCONTROL_FP16_SUPPORT = "D3DOGL_0xe0036b";
static const char *g_pszMainDocs_OCGCONTROL_FP16_SUPPORT = "Control support of FP16 math on GPUs that include such support (GM20Y+).";

static const char * (g_ppszDefineDataNames_OCGCONTROL_FP16_SUPPORT_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_FP16_SUPPORT_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_FP16_SUPPORT[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_FP16_SUPPORT_DISABLE, 0x00000000 , "Disable FP16 math support." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_FP16_SUPPORT_ENABLE, 0x00000001 , "Enable FP16 math support." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_FP16_SUPPORT[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_FP16_SUPPORT(
    0x10e0036b,
    g_pszKeyName_OCGCONTROL_FP16_SUPPORT,
    g_pszRemappedName_OCGCONTROL_FP16_SUPPORT,
    g_pszMainDocs_OCGCONTROL_FP16_SUPPORT,
    g_pszDefinedWhen_OCGCONTROL_FP16_SUPPORT,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_FP16_SUPPORT, 
    2, 
    g_aDefaultData_OCGCONTROL_FP16_SUPPORT, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_FP16_USE_FP32_CONVERTERS = "OCGCONTROL_FP16_USE_FP32_CONVERTERS";
static const char *g_pszDefinedWhen_OCGCONTROL_FP16_USE_FP32_CONVERTERS = "1";
static const char *g_pszRemappedName_OCGCONTROL_FP16_USE_FP32_CONVERTERS = "D3DOGL_0x7b4428";
static const char *g_pszMainDocs_OCGCONTROL_FP16_USE_FP32_CONVERTERS = "Control support of FP16 math on GPUs that include such support (GM20Y+).";

static const char * (g_ppszDefineDataNames_OCGCONTROL_FP16_USE_FP32_CONVERTERS_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_FP16_USE_FP32_CONVERTERS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_FP16_USE_FP32_CONVERTERS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_FP16_USE_FP32_CONVERTERS_DISABLE, 0x00000000 , "Don't allow FP16 instructions to use inline FP32 converters." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_FP16_USE_FP32_CONVERTERS_ENABLE, 0x00000001 , "Allow FP16 instructions to use inline FP32 converters." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_FP16_USE_FP32_CONVERTERS[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_FP16_USE_FP32_CONVERTERS(
    0x107b4428,
    g_pszKeyName_OCGCONTROL_FP16_USE_FP32_CONVERTERS,
    g_pszRemappedName_OCGCONTROL_FP16_USE_FP32_CONVERTERS,
    g_pszMainDocs_OCGCONTROL_FP16_USE_FP32_CONVERTERS,
    g_pszDefinedWhen_OCGCONTROL_FP16_USE_FP32_CONVERTERS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_FP16_USE_FP32_CONVERTERS, 
    2, 
    g_aDefaultData_OCGCONTROL_FP16_USE_FP32_CONVERTERS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_GS = "OCGCONTROL_GS";
static const char *g_pszDefinedWhen_OCGCONTROL_GS = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_OCGCONTROL_GS = "D3DOGL_92809063";
static const char *g_pszMainDocs_OCGCONTROL_GS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_GS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_GS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_GS(
    0x10550492,
    g_pszKeyName_OCGCONTROL_GS,
    g_pszRemappedName_OCGCONTROL_GS,
    g_pszMainDocs_OCGCONTROL_GS,
    g_pszDefinedWhen_OCGCONTROL_GS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_GS, 
    8, 
    g_aDefaultData_OCGCONTROL_GS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_HS = "OCGCONTROL_HS";
static const char *g_pszDefinedWhen_OCGCONTROL_HS = "1";
static const char *g_pszRemappedName_OCGCONTROL_HS = "D3DOGL_4189FAC3";
static const char *g_pszMainDocs_OCGCONTROL_HS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_HS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_HS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_HS(
    0x10940f02,
    g_pszKeyName_OCGCONTROL_HS,
    g_pszRemappedName_OCGCONTROL_HS,
    g_pszMainDocs_OCGCONTROL_HS,
    g_pszDefinedWhen_OCGCONTROL_HS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_HS, 
    8, 
    g_aDefaultData_OCGCONTROL_HS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_KNOBS_STRING = "OCGCONTROL_KNOBS_STRING";
static const char *g_pszDefinedWhen_OCGCONTROL_KNOBS_STRING = "defined(DEBUG) || defined(DEVELOP) || defined(NV_MODS)";
static const char *g_pszRemappedName_OCGCONTROL_KNOBS_STRING = "D3DOGL_CA345840";
static const char *g_pszMainDocs_OCGCONTROL_KNOBS_STRING = "String containing multiple packed OCG knobs (space separated).";

DataDefaultSTRING g_aDefaultData_OCGCONTROL_KNOBS_STRING[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_OCGCONTROL_KNOBS_STRING(
    0x10e107e0,
    g_pszKeyName_OCGCONTROL_KNOBS_STRING,
    g_pszRemappedName_OCGCONTROL_KNOBS_STRING,
    g_pszMainDocs_OCGCONTROL_KNOBS_STRING,
    g_pszDefinedWhen_OCGCONTROL_KNOBS_STRING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_KNOBS_STRING, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_GS = "OCGCONTROL_LATENCY_GS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_GS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_GS = "D3DOGL_92809064";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_GS = "Gets copied to ParamsForCOP.latency";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_GS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_GS(
    0x109bbccd,
    g_pszKeyName_OCGCONTROL_LATENCY_GS,
    g_pszRemappedName_OCGCONTROL_LATENCY_GS,
    g_pszMainDocs_OCGCONTROL_LATENCY_GS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_GS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_GS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_HS = "OCGCONTROL_LATENCY_HS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_HS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_HS = "D3DOGL_80772310";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_HS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_HS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_HS(
    0x10fbcf49,
    g_pszKeyName_OCGCONTROL_LATENCY_HS,
    g_pszRemappedName_OCGCONTROL_LATENCY_HS,
    g_pszMainDocs_OCGCONTROL_LATENCY_HS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_HS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_HS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_MS = "OCGCONTROL_LATENCY_MS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_MS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_MS = "D3DOGL_A3AB0301";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_MS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_MS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_MS(
    0x10a3ab03,
    g_pszKeyName_OCGCONTROL_LATENCY_MS,
    g_pszRemappedName_OCGCONTROL_LATENCY_MS,
    g_pszMainDocs_OCGCONTROL_LATENCY_MS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_MS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_MS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_MTS = "OCGCONTROL_LATENCY_MTS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_MTS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_MTS = "D3DOGL_A3AB0201";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_MTS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_MTS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_MTS(
    0x10a3ab02,
    g_pszKeyName_OCGCONTROL_LATENCY_MTS,
    g_pszRemappedName_OCGCONTROL_LATENCY_MTS,
    g_pszMainDocs_OCGCONTROL_LATENCY_MTS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_MTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_MTS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_PS = "OCGCONTROL_LATENCY_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_PS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_PS = "D3DOGL_92179064";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_PS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_PS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_PS(
    0x104a6e33,
    g_pszKeyName_OCGCONTROL_LATENCY_PS,
    g_pszRemappedName_OCGCONTROL_LATENCY_PS,
    g_pszMainDocs_OCGCONTROL_LATENCY_PS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_PS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_TS = "OCGCONTROL_LATENCY_TS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_TS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_TS = "D3DOGL_800C2310";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_TS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_TS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_TS(
    0x10a491a9,
    g_pszKeyName_OCGCONTROL_LATENCY_TS,
    g_pszRemappedName_OCGCONTROL_LATENCY_TS,
    g_pszMainDocs_OCGCONTROL_LATENCY_TS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_TS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_TS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_LATENCY_VS = "OCGCONTROL_LATENCY_VS";
static const char *g_pszDefinedWhen_OCGCONTROL_LATENCY_VS = "1";
static const char *g_pszRemappedName_OCGCONTROL_LATENCY_VS = "D3DOGL_85612310";
static const char *g_pszMainDocs_OCGCONTROL_LATENCY_VS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_LATENCY_VS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_LATENCY_VS(
    0x1010c152,
    g_pszKeyName_OCGCONTROL_LATENCY_VS,
    g_pszRemappedName_OCGCONTROL_LATENCY_VS,
    g_pszMainDocs_OCGCONTROL_LATENCY_VS,
    g_pszDefinedWhen_OCGCONTROL_LATENCY_VS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_LATENCY_VS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_GS = "OCGCONTROL_MAXINSTINBASICBLOCK_GS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_GS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_GS = "D3DOGL_62317182";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_GS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_GS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_GS(
    0x102d16ca,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_GS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_GS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_GS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_GS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_GS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_HS = "OCGCONTROL_MAXINSTINBASICBLOCK_HS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_HS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_HS = "D3DOGL_C023777F";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_HS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_HS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_HS(
    0x1041fa09,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_HS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_HS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_HS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_HS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_HS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_MS = "OCGCONTROL_MAXINSTINBASICBLOCK_MS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_MS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_MS = "D3DOGL_A3AB0901";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_MS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_MS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_MS(
    0x10a3ab09,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_MS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_MS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_MS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_MS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_MS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_MTS = "OCGCONTROL_MAXINSTINBASICBLOCK_MTS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_MTS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_MTS = "D3DOGL_A3AB0801";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_MTS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_MTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_MTS(
    0x10a3ab08,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_MTS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_MTS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_MTS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_MTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_MTS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_PS = "OCGCONTROL_MAXINSTINBASICBLOCK_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_PS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_PS = "D3DOGL_94812574";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_PS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_PS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_PS(
    0x10689da1,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_PS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_PS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_PS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_PS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_TS = "OCGCONTROL_MAXINSTINBASICBLOCK_TS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_TS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_TS = "D3DOGL_A7044887";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_TS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_TS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_TS(
    0x1093f019,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_TS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_TS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_TS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_TS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_TS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_VS = "OCGCONTROL_MAXINSTINBASICBLOCK_VS";
static const char *g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_VS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_VS = "D3DOGL_80546710";
static const char *g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_VS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_VS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_VS(
    0x100af0f1,
    g_pszKeyName_OCGCONTROL_MAXINSTINBASICBLOCK_VS,
    g_pszRemappedName_OCGCONTROL_MAXINSTINBASICBLOCK_VS,
    g_pszMainDocs_OCGCONTROL_MAXINSTINBASICBLOCK_VS,
    g_pszDefinedWhen_OCGCONTROL_MAXINSTINBASICBLOCK_VS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_MAXINSTINBASICBLOCK_VS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MS = "OCGCONTROL_MS";
static const char *g_pszDefinedWhen_OCGCONTROL_MS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MS = "D3DOGL_A3AB0101";
static const char *g_pszMainDocs_OCGCONTROL_MS = "Optimization override for mesh shaders.";

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_MS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MS(
    0x10a3ab01,
    g_pszKeyName_OCGCONTROL_MS,
    g_pszRemappedName_OCGCONTROL_MS,
    g_pszMainDocs_OCGCONTROL_MS,
    g_pszDefinedWhen_OCGCONTROL_MS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_MS, 
    8, 
    g_aDefaultData_OCGCONTROL_MS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_MTS = "OCGCONTROL_MTS";
static const char *g_pszDefinedWhen_OCGCONTROL_MTS = "1";
static const char *g_pszRemappedName_OCGCONTROL_MTS = "D3DOGL_A3AB0001";
static const char *g_pszMainDocs_OCGCONTROL_MTS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_MTS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_MTS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_MTS(
    0x10a3ab00,
    g_pszKeyName_OCGCONTROL_MTS,
    g_pszRemappedName_OCGCONTROL_MTS,
    g_pszMainDocs_OCGCONTROL_MTS,
    g_pszDefinedWhen_OCGCONTROL_MTS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_MTS, 
    8, 
    g_aDefaultData_OCGCONTROL_MTS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_ORI = "OCGCONTROL_ORI";
static const char *g_pszDefinedWhen_OCGCONTROL_ORI = "1";
static const char *g_pszRemappedName_OCGCONTROL_ORI = "D3DOGL_92350358";
static const char *g_pszMainDocs_OCGCONTROL_ORI = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_ORI[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_ORI(
    0x10c209bb,
    g_pszKeyName_OCGCONTROL_ORI,
    g_pszRemappedName_OCGCONTROL_ORI,
    g_pszMainDocs_OCGCONTROL_ORI,
    g_pszDefinedWhen_OCGCONTROL_ORI,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_ORI, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_PS = "OCGCONTROL_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_PS = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_OCGCONTROL_PS = "D3DOGL_92179063";
static const char *g_pszMainDocs_OCGCONTROL_PS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_PS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_PS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_PS(
    0x10c64d06,
    g_pszKeyName_OCGCONTROL_PS,
    g_pszRemappedName_OCGCONTROL_PS,
    g_pszMainDocs_OCGCONTROL_PS,
    g_pszDefinedWhen_OCGCONTROL_PS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_PS, 
    8, 
    g_aDefaultData_OCGCONTROL_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_GS = "OCGCONTROL_TEXBATCH_GS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_GS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_GS = "D3DOGL_92809065";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_GS = "If set THEN (ParamsForCOP.TexDontAutobatch = TRUE, ParamsForCOP.texBatchSize = regkey value) ELSE (ParamsForCOP.TexDontAutobatch = FALSE, ParamsForCOP.texBatchSzie = ignored)";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_GS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_GS(
    0x10109bc3,
    g_pszKeyName_OCGCONTROL_TEXBATCH_GS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_GS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_GS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_GS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_GS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_HS = "OCGCONTROL_TEXBATCH_HS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_HS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_HS = "D3DOGL_9F279065";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_HS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_HS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_HS(
    0x106ff684,
    g_pszKeyName_OCGCONTROL_TEXBATCH_HS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_HS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_HS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_HS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_HS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_MS = "OCGCONTROL_TEXBATCH_MS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_MS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_MS = "D3DOGL_A3AB0501";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_MS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_MS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_MS(
    0x10a3ab05,
    g_pszKeyName_OCGCONTROL_TEXBATCH_MS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_MS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_MS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_MS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_MS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_MTS = "OCGCONTROL_TEXBATCH_MTS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_MTS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_MTS = "D3DOGL_A3AB0401";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_MTS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_MTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_MTS(
    0x10a3ab04,
    g_pszKeyName_OCGCONTROL_TEXBATCH_MTS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_MTS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_MTS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_MTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_MTS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_PS = "OCGCONTROL_TEXBATCH_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_PS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_PS = "D3DOGL_92179065";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_PS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_PS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_PS(
    0x10385209,
    g_pszKeyName_OCGCONTROL_TEXBATCH_PS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_PS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_PS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_PS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_TS = "OCGCONTROL_TEXBATCH_TS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_TS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_TS = "D3DOGL_9AA29065";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_TS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_TS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_TS(
    0x1058199d,
    g_pszKeyName_OCGCONTROL_TEXBATCH_TS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_TS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_TS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_TS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_TS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXBATCH_VS = "OCGCONTROL_TEXBATCH_VS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXBATCH_VS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXBATCH_VS = "D3DOGL_85612311";
static const char *g_pszMainDocs_OCGCONTROL_TEXBATCH_VS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXBATCH_VS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXBATCH_VS(
    0x10f75a0a,
    g_pszKeyName_OCGCONTROL_TEXBATCH_VS,
    g_pszRemappedName_OCGCONTROL_TEXBATCH_VS,
    g_pszMainDocs_OCGCONTROL_TEXBATCH_VS,
    g_pszDefinedWhen_OCGCONTROL_TEXBATCH_VS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXBATCH_VS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_GS = "OCGCONTROL_TEXMINPHASE_GS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_GS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_GS = "D3DOGL_92809066";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_GS = "// Gets copied to ParamsForCOP.texMinPhase";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_GS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_GS(
    0x107a30b3,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_GS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_GS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_GS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_GS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_GS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_HS = "OCGCONTROL_TEXMINPHASE_HS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_HS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_HS = "D3DOGL_17AA230C";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_HS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_HS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_HS(
    0x10f54313,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_HS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_HS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_HS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_HS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_HS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_MS = "OCGCONTROL_TEXMINPHASE_MS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_MS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_MS = "D3DOGL_A3AB0701";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_MS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_MS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_MS(
    0x10a3ab07,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_MS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_MS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_MS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_MS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_MS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_MTS = "OCGCONTROL_TEXMINPHASE_MTS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_MTS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_MTS = "D3DOGL_A3AB0601";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_MTS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_MTS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_MTS(
    0x10a3ab06,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_MTS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_MTS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_MTS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_MTS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_MTS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_PS = "OCGCONTROL_TEXMINPHASE_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_PS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_PS = "D3DOGL_92179066";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_PS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_PS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_PS(
    0x10421fb3,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_PS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_PS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_PS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_PS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_TS = "OCGCONTROL_TEXMINPHASE_TS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_TS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_TS = "D3DOGL_4889AC02";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_TS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_TS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_TS(
    0x109ad328,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_TS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_TS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_TS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_TS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_TS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TEXMINPHASE_VS = "OCGCONTROL_TEXMINPHASE_VS";
static const char *g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_VS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TEXMINPHASE_VS = "D3DOGL_85612312";
static const char *g_pszMainDocs_OCGCONTROL_TEXMINPHASE_VS = "";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TEXMINPHASE_VS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TEXMINPHASE_VS(
    0x10ead8d9,
    g_pszKeyName_OCGCONTROL_TEXMINPHASE_VS,
    g_pszRemappedName_OCGCONTROL_TEXMINPHASE_VS,
    g_pszMainDocs_OCGCONTROL_TEXMINPHASE_VS,
    g_pszDefinedWhen_OCGCONTROL_TEXMINPHASE_VS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TEXMINPHASE_VS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TS = "OCGCONTROL_TS";
static const char *g_pszDefinedWhen_OCGCONTROL_TS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TS = "D3DOGL_A7149200";
static const char *g_pszMainDocs_OCGCONTROL_TS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_TS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TS(
    0x10661a36,
    g_pszKeyName_OCGCONTROL_TS,
    g_pszRemappedName_OCGCONTROL_TS,
    g_pszMainDocs_OCGCONTROL_TS,
    g_pszDefinedWhen_OCGCONTROL_TS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_TS, 
    8, 
    g_aDefaultData_OCGCONTROL_TS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_TXDBATCHSIZE_PS = "OCGCONTROL_TXDBATCHSIZE_PS";
static const char *g_pszDefinedWhen_OCGCONTROL_TXDBATCHSIZE_PS = "1";
static const char *g_pszRemappedName_OCGCONTROL_TXDBATCHSIZE_PS = "D3DOGL_56196962";
static const char *g_pszMainDocs_OCGCONTROL_TXDBATCHSIZE_PS = "copied to txdBatchSize";

DataDefaultDWORD g_aDefaultData_OCGCONTROL_TXDBATCHSIZE_PS[] =
{
    {"DEFAULT", 0x00000002, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_TXDBATCHSIZE_PS(
    0x10fc0cb9,
    g_pszKeyName_OCGCONTROL_TXDBATCHSIZE_PS,
    g_pszRemappedName_OCGCONTROL_TXDBATCHSIZE_PS,
    g_pszMainDocs_OCGCONTROL_TXDBATCHSIZE_PS,
    g_pszDefinedWhen_OCGCONTROL_TXDBATCHSIZE_PS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_OCGCONTROL_TXDBATCHSIZE_PS, 
    1 
);

static const char *g_pszKeyName_OCGCONTROL_VS = "OCGCONTROL_VS";
static const char *g_pszDefinedWhen_OCGCONTROL_VS = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_OCGCONTROL_VS = "D3DOGL_85612309";
static const char *g_pszMainDocs_OCGCONTROL_VS = "";

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_ENABLE)[] =
{
    "OCG_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_BRANCH_OPT)[] =
{
    "OCG_BRANCH_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_ENABLE)[] =
{
    "OCG_OPT_FORCE_LEVEL_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_MASK)[] =
{
    "OCG_OPT_FORCE_LEVEL_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O0)[] =
{
    "OCG_OPT_FORCE_LEVEL_O0",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O1)[] =
{
    "OCG_OPT_FORCE_LEVEL_O1",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O2)[] =
{
    "OCG_OPT_FORCE_LEVEL_O2",
    NULL
};

static const char * (g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O3)[] =
{
    "OCG_OPT_FORCE_LEVEL_O3",
    NULL
};

DataValueDWORD g_aDefineData_OCGCONTROL_VS[] =
{
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_BRANCH_OPT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_ENABLE, 0x00000008 , "If set, force a specific optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_MASK, 0x00000030 , "Bits specifying forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O0, 0x00000000 , "Use -O0 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O1, 0x00000010 , "Use -O1 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O2, 0x00000020 , "Use -O2 as the forced optimization level." },
    { (const char **)g_ppszDefineDataNames_OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O3, 0x00000030 , "Use -O3 as the forced optimization level." },
};

DataDefaultDWORD g_aDefaultData_OCGCONTROL_VS[] =
{
    {"DEFAULT", 0x00000003, "" }, 
};

SettingDWORD g_setting_OCGCONTROL_VS(
    0x10bad271,
    g_pszKeyName_OCGCONTROL_VS,
    g_pszRemappedName_OCGCONTROL_VS,
    g_pszMainDocs_OCGCONTROL_VS,
    g_pszDefinedWhen_OCGCONTROL_VS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OCGCONTROL_VS, 
    8, 
    g_aDefaultData_OCGCONTROL_VS, 
    1 
);

static const char *g_pszKeyName_OPTIMUS_DEBUG = "OPTIMUS_DEBUG";
static const char *g_pszDefinedWhen_OPTIMUS_DEBUG = "1";
static const char *g_pszRemappedName_OPTIMUS_DEBUG = "D3DOGL_93284751";
static const char *g_pszMainDocs_OPTIMUS_DEBUG = "Debug bits for optimus performance";

static const char * (g_ppszDefineDataNames_OPTIMUS_DEBUG_NULL_RENDER_TRANSPORT)[] =
{
    "NULL_RENDER_TRANSPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_OPTIMUS_DEBUG_NULL_DISPLAY_TRANSPORT)[] =
{
    "NULL_DISPLAY_TRANSPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_OPTIMUS_DEBUG_DISABLE_CE_USAGE)[] =
{
    "DISABLE_CE_USAGE",
    NULL
};

static const char * (g_ppszDefineDataNames_OPTIMUS_DEBUG_DETECT_FRONT_BUFFER_RENDERING_MISSING_SYNC)[] =
{
    "DETECT_FRONT_BUFFER_RENDERING_MISSING_SYNC",
    NULL
};

DataValueDWORD g_aDefineData_OPTIMUS_DEBUG[] =
{
    { (const char **)g_ppszDefineDataNames_OPTIMUS_DEBUG_NULL_RENDER_TRANSPORT, 0x00000001 , "Disable render transport layer  - screen will be black" },
    { (const char **)g_ppszDefineDataNames_OPTIMUS_DEBUG_NULL_DISPLAY_TRANSPORT, 0x00000002 , "Disable display transport layer - screen will be black" },
    { (const char **)g_ppszDefineDataNames_OPTIMUS_DEBUG_DISABLE_CE_USAGE, 0x00000004 , "Disable Copy Engine Usage in transport layer for Optimus" },
    { (const char **)g_ppszDefineDataNames_OPTIMUS_DEBUG_DETECT_FRONT_BUFFER_RENDERING_MISSING_SYNC, 0x00000008 , "Detect missing sync and Front Buffer rendering scenarios in MS hybrid " },
};

DataDefaultDWORD g_aDefaultData_OPTIMUS_DEBUG[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_OPTIMUS_DEBUG(
    0x10f9dc03,
    g_pszKeyName_OPTIMUS_DEBUG,
    g_pszRemappedName_OPTIMUS_DEBUG,
    g_pszMainDocs_OPTIMUS_DEBUG,
    g_pszDefinedWhen_OPTIMUS_DEBUG,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OPTIMUS_DEBUG, 
    4, 
    g_aDefaultData_OPTIMUS_DEBUG, 
    1 
);

static const char *g_pszKeyName_OPTIMUS_HCLONE = "OPTIMUS_HCLONE";
static const char *g_pszDefinedWhen_OPTIMUS_HCLONE = "1";
static const char *g_pszRemappedName_OPTIMUS_HCLONE = "D3DOGL_42429123";
static const char *g_pszMainDocs_OPTIMUS_HCLONE = "Temporary regkey to enable heterogeneous clone during development. Set it to ALLOWED for apps to be aware of hclone. Set it to ENABLED to turn clone on. Clear ENABLED to turn clone off.";

static const char * (g_ppszDefineDataNames_OPTIMUS_HCLONE_ALLOWED)[] =
{
    "ALLOWED",
    NULL
};

static const char * (g_ppszDefineDataNames_OPTIMUS_HCLONE_ENABLED)[] =
{
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_OPTIMUS_HCLONE[] =
{
    { (const char **)g_ppszDefineDataNames_OPTIMUS_HCLONE_ALLOWED, 0x00000001 , "HClone is allowed - must be set before starting app" },
    { (const char **)g_ppszDefineDataNames_OPTIMUS_HCLONE_ENABLED, 0x00000002 , "User has entered HClone - can be turned on/off will app is running" },
};

DataDefaultDWORD g_aDefaultData_OPTIMUS_HCLONE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_OPTIMUS_HCLONE(
    0x10f9ae81,
    g_pszKeyName_OPTIMUS_HCLONE,
    g_pszRemappedName_OPTIMUS_HCLONE,
    g_pszMainDocs_OPTIMUS_HCLONE,
    g_pszDefinedWhen_OPTIMUS_HCLONE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_OPTIMUS_HCLONE, 
    2, 
    g_aDefaultData_OPTIMUS_HCLONE, 
    1 
);

static const char *g_pszKeyName_OPTIMUS_MAXAA = "OPTIMUS_MAXAA";
static const char *g_pszDefinedWhen_OPTIMUS_MAXAA = "1";
static const char *g_pszRemappedName_OPTIMUS_MAXAA = "D3DOGL_52180886";
static const char *g_pszMainDocs_OPTIMUS_MAXAA = "Maximum AA we are going to allow for a given application";

static const char * (g_ppszDefineDataNames_OPTIMUS_MAXAA_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_OPTIMUS_MAXAA_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_OPTIMUS_MAXAA[] =
{
    { (const char **)g_ppszDefineDataNames_OPTIMUS_MAXAA_MIN, 0 , "" },
    { (const char **)g_ppszDefineDataNames_OPTIMUS_MAXAA_MAX, 16 , "" },
};

DataDefaultDWORD g_aDefaultData_OPTIMUS_MAXAA[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_OPTIMUS_MAXAA(
    0x10f9dc83,
    g_pszKeyName_OPTIMUS_MAXAA,
    g_pszRemappedName_OPTIMUS_MAXAA,
    g_pszMainDocs_OPTIMUS_MAXAA,
    g_pszDefinedWhen_OPTIMUS_MAXAA,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_OPTIMUS_MAXAA, 
    2, 
    g_aDefaultData_OPTIMUS_MAXAA, 
    1 
);

static const char *g_pszKeyName_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT = "PASCAL_SCG_COMPUTE1_MIN_SM_COUNT";
static const char *g_pszDefinedWhen_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT = "1";
static const char *g_pszRemappedName_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT = "D3DOGL_0xb134ff";
static const char *g_pszMainDocs_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT = "Set Min number of SMs which is reserved for compute_1 (async) when more work is pending (GP10x+)";

DataDefaultDWORD g_aDefaultData_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT(
    0x10b134ff,
    g_pszKeyName_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT,
    g_pszRemappedName_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT,
    g_pszMainDocs_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT,
    g_pszDefinedWhen_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT, 
    1 
);

static const char *g_pszKeyName_PASCAL_SCG_COMPUTE1_SM_FACTOR = "PASCAL_SCG_COMPUTE1_SM_FACTOR";
static const char *g_pszDefinedWhen_PASCAL_SCG_COMPUTE1_SM_FACTOR = "1";
static const char *g_pszRemappedName_PASCAL_SCG_COMPUTE1_SM_FACTOR = "D3DOGL_0x234098";
static const char *g_pszMainDocs_PASCAL_SCG_COMPUTE1_SM_FACTOR = "Percentage of total SM count assigned to compute during SCG, when MAX_SM_COUNT isn't specified (0.0 to 1.0).";

DataDefaultFLOAT g_aDefaultData_PASCAL_SCG_COMPUTE1_SM_FACTOR[] =
{
    {"DEFAULT", 0.6f, "" }, 
};

SettingFLOAT g_setting_PASCAL_SCG_COMPUTE1_SM_FACTOR(
    0x10234098,
    g_pszKeyName_PASCAL_SCG_COMPUTE1_SM_FACTOR,
    g_pszRemappedName_PASCAL_SCG_COMPUTE1_SM_FACTOR,
    g_pszMainDocs_PASCAL_SCG_COMPUTE1_SM_FACTOR,
    g_pszDefinedWhen_PASCAL_SCG_COMPUTE1_SM_FACTOR,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PASCAL_SCG_COMPUTE1_SM_FACTOR, 
    1 
);

static const char *g_pszKeyName_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE = "PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE";
static const char *g_pszDefinedWhen_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE = "1";
static const char *g_pszRemappedName_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE = "D3DOGL_0xb134fe";
static const char *g_pszMainDocs_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE = "controls if MaxSmCount is applied in all compute mode (GP10x+)";

static const char * (g_ppszDefineDataNames_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE(
    0x10b134fe,
    g_pszKeyName_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE,
    g_pszRemappedName_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE,
    g_pszMainDocs_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE,
    g_pszDefinedWhen_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE, 
    2, 
    g_aDefaultData_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE, 
    1 
);

static const char *g_pszKeyName_PERF_TESLA_UNIT_SELECTION = "PERF_TESLA_UNIT_SELECTION";
static const char *g_pszDefinedWhen_PERF_TESLA_UNIT_SELECTION = "1";
static const char *g_pszRemappedName_PERF_TESLA_UNIT_SELECTION = "D3DOGL_505365c";
static const char *g_pszMainDocs_PERF_TESLA_UNIT_SELECTION = "NVPMAPI Perf Counter Selection Control for Tesla";

static const char * (g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_TPC_MASK)[] =
{
    "TPC_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_ROP_MASK)[] =
{
    "ROP_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_FIRST_SM_MASK)[] =
{
    "FIRST_SM_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_LAST_SM_MASK)[] =
{
    "LAST_SM_MASK",
    NULL
};

DataValueDWORD g_aDefineData_PERF_TESLA_UNIT_SELECTION[] =
{
    { (const char **)g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_TPC_MASK, 0x000000ff , "" },
    { (const char **)g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_ROP_MASK, 0x0000ff00 , "" },
    { (const char **)g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_FIRST_SM_MASK, 0x000f0000 , "" },
    { (const char **)g_ppszDefineDataNames_PERF_TESLA_UNIT_SELECTION_LAST_SM_MASK, 0x00f00000 , "" },
};

DataDefaultDWORD g_aDefaultData_PERF_TESLA_UNIT_SELECTION[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PERF_TESLA_UNIT_SELECTION(
    0x10dc2830,
    g_pszKeyName_PERF_TESLA_UNIT_SELECTION,
    g_pszRemappedName_PERF_TESLA_UNIT_SELECTION,
    g_pszMainDocs_PERF_TESLA_UNIT_SELECTION,
    g_pszDefinedWhen_PERF_TESLA_UNIT_SELECTION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PERF_TESLA_UNIT_SELECTION, 
    4, 
    g_aDefaultData_PERF_TESLA_UNIT_SELECTION, 
    1 
);

static const char *g_pszKeyName_PHYSXINDICATOR = "PHYSXINDICATOR";
static const char *g_pszDefinedWhen_PHYSXINDICATOR = "1";
static const char *g_pszRemappedName_PHYSXINDICATOR = "D3DOGL_73304097";
static const char *g_pszMainDocs_PHYSXINDICATOR = "";

static const char * (g_ppszDefineDataNames_PHYSXINDICATOR_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_PHYSXINDICATOR_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_PHYSXINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_PHYSXINDICATOR_DISABLED, 0x34534064 , "" },
    { (const char **)g_ppszDefineDataNames_PHYSXINDICATOR_ENABLED, 0x24545582 , "" },
};

DataDefaultDWORD g_aDefaultData_PHYSXINDICATOR[] =
{
    {"DEFAULT", 0x34534064, "" }, 
};

SettingDWORD g_setting_PHYSXINDICATOR(
    0x1094f16f,
    g_pszKeyName_PHYSXINDICATOR,
    g_pszRemappedName_PHYSXINDICATOR,
    g_pszMainDocs_PHYSXINDICATOR,
    g_pszDefinedWhen_PHYSXINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PHYSXINDICATOR, 
    2, 
    g_aDefaultData_PHYSXINDICATOR, 
    1 
);

static const char *g_pszKeyName_PHYSX_APPLICATION = "PHYSX_APPLICATION";
static const char *g_pszDefinedWhen_PHYSX_APPLICATION = "1";
static const char *g_pszRemappedName_PHYSX_APPLICATION = "D3D_30170611";
static const char *g_pszMainDocs_PHYSX_APPLICATION = "Set for PhysX applications";

static const char * (g_ppszDefineDataNames_PHYSX_APPLICATION_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    "NO",
    NULL
};

static const char * (g_ppszDefineDataNames_PHYSX_APPLICATION_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    "YES",
    NULL
};

DataValueDWORD g_aDefineData_PHYSX_APPLICATION[] =
{
    { (const char **)g_ppszDefineDataNames_PHYSX_APPLICATION_OFF, 0x0 , "Default" },
    { (const char **)g_ppszDefineDataNames_PHYSX_APPLICATION_ON, 0x1 , "PhysX application" },
};

DataDefaultDWORD g_aDefaultData_PHYSX_APPLICATION[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_PHYSX_APPLICATION(
    0x10e3293a,
    g_pszKeyName_PHYSX_APPLICATION,
    g_pszRemappedName_PHYSX_APPLICATION,
    g_pszMainDocs_PHYSX_APPLICATION,
    g_pszDefinedWhen_PHYSX_APPLICATION,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PHYSX_APPLICATION, 
    2, 
    g_aDefaultData_PHYSX_APPLICATION, 
    1 
);

static const char *g_pszKeyName_PREFERRED_PSTATE = "PREFERRED_PSTATE";
static const char *g_pszDefinedWhen_PREFERRED_PSTATE = "1";
static const char *g_pszRemappedName_PREFERRED_PSTATE = "D3DOGL_12039265";
static const char *g_pszMainDocs_PREFERRED_PSTATE = "Preferential power states";

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_ADAPTIVE)[] =
{
    "ADAPTIVE",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_MAX)[] =
{
    "PREFER_MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_DRIVER_CONTROLLED)[] =
{
    "DRIVER_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_CONSISTENT_PERFORMANCE)[] =
{
    "PREFER_CONSISTENT_PERFORMANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_MIN)[] =
{
    "PREFER_MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_OPTIMAL_POWER)[] =
{
    "OPTIMAL_POWER",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PREFERRED_PSTATE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PREFERRED_PSTATE[] =
{
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_ADAPTIVE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_MAX, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_DRIVER_CONTROLLED, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_CONSISTENT_PERFORMANCE, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_PREFER_MIN, 0x00000004 , "Currently Unsupported" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_OPTIMAL_POWER, 0x00000005 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PREFERRED_PSTATE_MAX, 0x00000005 , "" },
};

DataDefaultDWORD g_aDefaultData_PREFERRED_PSTATE[] =
{
    {"DEFAULT", 0x00000005, "" }, 
    {"DEFAULT_GL", 0x00000002, "" }, 
};

SettingDWORD g_setting_PREFERRED_PSTATE(
    0x1057eb71,
    g_pszKeyName_PREFERRED_PSTATE,
    g_pszRemappedName_PREFERRED_PSTATE,
    g_pszMainDocs_PREFERRED_PSTATE,
    g_pszDefinedWhen_PREFERRED_PSTATE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PREFERRED_PSTATE, 
    8, 
    g_aDefaultData_PREFERRED_PSTATE, 
    2 
);

static const char *g_pszKeyName_PREVENT_UI_AF_OVERRIDE = "PREVENT_UI_AF_OVERRIDE";
static const char *g_pszDefinedWhen_PREVENT_UI_AF_OVERRIDE = "1";
static const char *g_pszRemappedName_PREVENT_UI_AF_OVERRIDE = "Prevent_AfOverride";
static const char *g_pszMainDocs_PREVENT_UI_AF_OVERRIDE = "This setting tells our UI that it cannot override Anisotropic filtering for this application";

static const char * (g_ppszDefineDataNames_PREVENT_UI_AF_OVERRIDE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PREVENT_UI_AF_OVERRIDE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PREVENT_UI_AF_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_PREVENT_UI_AF_OVERRIDE_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_PREVENT_UI_AF_OVERRIDE_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_PREVENT_UI_AF_OVERRIDE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_PREVENT_UI_AF_OVERRIDE(
    0x103bccb5,
    g_pszKeyName_PREVENT_UI_AF_OVERRIDE,
    g_pszRemappedName_PREVENT_UI_AF_OVERRIDE,
    g_pszMainDocs_PREVENT_UI_AF_OVERRIDE,
    g_pszDefinedWhen_PREVENT_UI_AF_OVERRIDE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PREVENT_UI_AF_OVERRIDE, 
    2, 
    g_aDefaultData_PREVENT_UI_AF_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_PS_ALPHABETA = "PS_ALPHABETA";
static const char *g_pszDefinedWhen_PS_ALPHABETA = "1";
static const char *g_pszRemappedName_PS_ALPHABETA = "D3DOGL_39867584";
static const char *g_pszMainDocs_PS_ALPHABETA = "Set the behavior for Alpha/Beta performance strategy (static or dynamic)";

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_STATIC)[] =
{
    "STATIC",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_DYNAMIC_SHADER)[] =
{
    "DYNAMIC_SHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_DYNAMIC_VBIB)[] =
{
    "DYNAMIC_VBIB",
    NULL
};

DataValueDWORD g_aDefineData_PS_ALPHABETA[] =
{
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_STATIC, 0x00000000 , "The driver always uses Alpha fraction set via PS_ALPHABETA_FRACTION regkey" },
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_DYNAMIC_SHADER, 0x00000001 , "The driver adjusts a shader unique Alpha fraction via AlphaBeta clocks" },
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_DYNAMIC_VBIB, 0x00000002 , "The driver adjusts a vb/ib ID unique Alpha fraction via AlphaBeta clocks" },
};

DataDefaultDWORD g_aDefaultData_PS_ALPHABETA[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_ALPHABETA(
    0x106044ce,
    g_pszKeyName_PS_ALPHABETA,
    g_pszRemappedName_PS_ALPHABETA,
    g_pszMainDocs_PS_ALPHABETA,
    g_pszDefinedWhen_PS_ALPHABETA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_ALPHABETA, 
    3, 
    g_aDefaultData_PS_ALPHABETA, 
    1 
);

static const char *g_pszKeyName_PS_ALPHABETA_FRACTION = "PS_ALPHABETA_FRACTION";
static const char *g_pszDefinedWhen_PS_ALPHABETA_FRACTION = "1";
static const char *g_pszRemappedName_PS_ALPHABETA_FRACTION = "D3DOGL_49867584";
static const char *g_pszMainDocs_PS_ALPHABETA_FRACTION = "Fixed Alpha fraction to use when PS_ALPHABETA is in static mode";

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_FRACTION_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_FRACTION_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PS_ALPHABETA_FRACTION[] =
{
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_FRACTION_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_FRACTION_MAX, 0x000000ff , "" },
};

DataDefaultDWORD g_aDefaultData_PS_ALPHABETA_FRACTION[] =
{
    {"DEFAULT", 63, "" }, 
};

SettingDWORD g_setting_PS_ALPHABETA_FRACTION(
    0x10842563,
    g_pszKeyName_PS_ALPHABETA_FRACTION,
    g_pszRemappedName_PS_ALPHABETA_FRACTION,
    g_pszMainDocs_PS_ALPHABETA_FRACTION,
    g_pszDefinedWhen_PS_ALPHABETA_FRACTION,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PS_ALPHABETA_FRACTION, 
    2, 
    g_aDefaultData_PS_ALPHABETA_FRACTION, 
    1 
);

static const char *g_pszKeyName_PS_ALPHABETA_STATS = "PS_ALPHABETA_STATS";
static const char *g_pszDefinedWhen_PS_ALPHABETA_STATS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_ALPHABETA_STATS = "D3DOGL_56418352";
static const char *g_pszMainDocs_PS_ALPHABETA_STATS = "";

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_STATS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_ALPHABETA_STATS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_ALPHABETA_STATS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_STATS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_ALPHABETA_STATS_ON, 0x00000001 , "" },
};

SettingDWORD g_setting_PS_ALPHABETA_STATS(
    0x10768dd3,
    g_pszKeyName_PS_ALPHABETA_STATS,
    g_pszRemappedName_PS_ALPHABETA_STATS,
    g_pszMainDocs_PS_ALPHABETA_STATS,
    g_pszDefinedWhen_PS_ALPHABETA_STATS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_ALPHABETA_STATS, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_APPSHADEROPT_CANIGNOREINF = "PS_APPSHADEROPT_CANIGNOREINF";
static const char *g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNOREINF = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_APPSHADEROPT_CANIGNOREINF = "D3D_6af9fa3f";
static const char *g_pszMainDocs_PS_APPSHADEROPT_CANIGNOREINF = "Override canIgnoreInf compiler option";

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNOREINF_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNOREINF_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_APPSHADEROPT_CANIGNOREINF[] =
{
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNOREINF_OFF, 0x97395a35 , "(DEFAULT) don't ignore Inf's" },
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNOREINF_ON, 0xde325a38 , "ignore Inf's" },
};

DataDefaultDWORD g_aDefaultData_PS_APPSHADEROPT_CANIGNOREINF[] =
{
    {"DEFAULT", 0x97395a35, "" }, 
};

SettingDWORD g_setting_PS_APPSHADEROPT_CANIGNOREINF(
    0x1078d9c8,
    g_pszKeyName_PS_APPSHADEROPT_CANIGNOREINF,
    g_pszRemappedName_PS_APPSHADEROPT_CANIGNOREINF,
    g_pszMainDocs_PS_APPSHADEROPT_CANIGNOREINF,
    g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNOREINF,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_APPSHADEROPT_CANIGNOREINF, 
    2, 
    g_aDefaultData_PS_APPSHADEROPT_CANIGNOREINF, 
    1 
);

static const char *g_pszKeyName_PS_APPSHADEROPT_CANIGNORENAN = "PS_APPSHADEROPT_CANIGNORENAN";
static const char *g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNORENAN = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_APPSHADEROPT_CANIGNORENAN = "D3D_6af9fa2f";
static const char *g_pszMainDocs_PS_APPSHADEROPT_CANIGNORENAN = "Override canIgnoreNaN compiler option";

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORENAN_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORENAN_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_APPSHADEROPT_CANIGNORENAN[] =
{
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORENAN_OFF, 0x97395a35 , "(DEFAULT) don't ignore NaN's -> NaN*0=NaN" },
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORENAN_ON, 0xde325a38 , "ignore NaN's -> x*0=0" },
};

DataDefaultDWORD g_aDefaultData_PS_APPSHADEROPT_CANIGNORENAN[] =
{
    {"DEFAULT", 0x97395a35, "" }, 
};

SettingDWORD g_setting_PS_APPSHADEROPT_CANIGNORENAN(
    0x1078d9a8,
    g_pszKeyName_PS_APPSHADEROPT_CANIGNORENAN,
    g_pszRemappedName_PS_APPSHADEROPT_CANIGNORENAN,
    g_pszMainDocs_PS_APPSHADEROPT_CANIGNORENAN,
    g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNORENAN,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_APPSHADEROPT_CANIGNORENAN, 
    2, 
    g_aDefaultData_PS_APPSHADEROPT_CANIGNORENAN, 
    1 
);

static const char *g_pszKeyName_PS_APPSHADEROPT_CANIGNORESIGNEDZERO = "PS_APPSHADEROPT_CANIGNORESIGNEDZERO";
static const char *g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNORESIGNEDZERO = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_APPSHADEROPT_CANIGNORESIGNEDZERO = "D3D_6af9fa4f";
static const char *g_pszMainDocs_PS_APPSHADEROPT_CANIGNORESIGNEDZERO = "Override CanIgnoreSignedZero compiler option";

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORESIGNEDZERO_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORESIGNEDZERO_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_APPSHADEROPT_CANIGNORESIGNEDZERO[] =
{
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORESIGNEDZERO_OFF, 0x97395a35 , "(DEFAULT) don't ignore SignedZero's" },
    { (const char **)g_ppszDefineDataNames_PS_APPSHADEROPT_CANIGNORESIGNEDZERO_ON, 0xde325a38 , "ignore SignedZero's" },
};

DataDefaultDWORD g_aDefaultData_PS_APPSHADEROPT_CANIGNORESIGNEDZERO[] =
{
    {"DEFAULT", 0x97395a35, "" }, 
};

SettingDWORD g_setting_PS_APPSHADEROPT_CANIGNORESIGNEDZERO(
    0x1078d9d8,
    g_pszKeyName_PS_APPSHADEROPT_CANIGNORESIGNEDZERO,
    g_pszRemappedName_PS_APPSHADEROPT_CANIGNORESIGNEDZERO,
    g_pszMainDocs_PS_APPSHADEROPT_CANIGNORESIGNEDZERO,
    g_pszDefinedWhen_PS_APPSHADEROPT_CANIGNORESIGNEDZERO,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_APPSHADEROPT_CANIGNORESIGNEDZERO, 
    2, 
    g_aDefaultData_PS_APPSHADEROPT_CANIGNORESIGNEDZERO, 
    1 
);

static const char *g_pszKeyName_PS_CYCLESTATS = "PS_CYCLESTATS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS = "1";
static const char *g_pszRemappedName_PS_CYCLESTATS = "D3D_87f6275666";
static const char *g_pszMainDocs_PS_CYCLESTATS = "This key is the global enable for both CycleStatsCPU and CycleStatsGPU";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_ON, 0x00000001 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS(
    0x10f36127,
    g_pszKeyName_PS_CYCLESTATS,
    g_pszRemappedName_PS_CYCLESTATS,
    g_pszMainDocs_PS_CYCLESTATS,
    g_pszDefinedWhen_PS_CYCLESTATS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_CYCLESTATS, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_BUCKET_FLAGS = "PS_CYCLESTATS_BUCKET_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_BUCKET_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_BUCKET_FLAGS = "D3D_97f727566e";
static const char *g_pszMainDocs_PS_CYCLESTATS_BUCKET_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_MASK)[] =
{
    "OUTER_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_API_CALL)[] =
{
    "OUTER_MODE_API_CALL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SAME_STATE)[] =
{
    "OUTER_MODE_SAME_STATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SEGMENT)[] =
{
    "OUTER_MODE_SEGMENT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_CMDBUF)[] =
{
    "OUTER_MODE_CMDBUF",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_FRAME)[] =
{
    "OUTER_MODE_FRAME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_START_END)[] =
{
    "OUTER_MODE_START_END",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_MASK)[] =
{
    "INNER_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_API_CALL)[] =
{
    "INNER_MODE_API_CALL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SAME_STATE)[] =
{
    "INNER_MODE_SAME_STATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SEGMENT)[] =
{
    "INNER_MODE_SEGMENT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_CMDBUF)[] =
{
    "INNER_MODE_CMDBUF",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_FRAME)[] =
{
    "INNER_MODE_FRAME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_START_END)[] =
{
    "INNER_MODE_START_END",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_MASK)[] =
{
    "INNER_PM_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_NONE)[] =
{
    "INNER_PM_MODE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIG)[] =
{
    "INNER_PM_MODE_PMTRIG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIGEND)[] =
{
    "INNER_PM_MODE_PMTRIGEND",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_MASK)[] =
{
    "INNER_WFI_MODE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_NONE)[] =
{
    "INNER_WFI_MODE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_GPUIDLE)[] =
{
    "INNER_WFI_MODE_GPUIDLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_ALWAYS)[] =
{
    "INNER_WFI_MODE_ALWAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_SEPARATE_REPLAYER_STATE)[] =
{
    "SEPARATE_REPLAYER_STATE",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_BUCKET_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_MASK, 0x0000000f , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_API_CALL, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SAME_STATE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SEGMENT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_CMDBUF, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_FRAME, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_START_END, 0x00000005 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_MASK, 0x000f0000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_API_CALL, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SAME_STATE, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SEGMENT, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_CMDBUF, 0x00030000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_FRAME, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_START_END, 0x00050000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_MASK, 0x00f00000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIG, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIGEND, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_MASK, 0x0f000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_GPUIDLE, 0x01000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_ALWAYS, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_BUCKET_FLAGS_SEPARATE_REPLAYER_STATE, 0x10000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_BUCKET_FLAGS(
    0x10c5c18e,
    g_pszKeyName_PS_CYCLESTATS_BUCKET_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_BUCKET_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_BUCKET_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_BUCKET_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_BUCKET_FLAGS, 
    23, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_CAPTURE_FLAGS = "PS_CYCLESTATS_CAPTURE_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_CAPTURE_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_CAPTURE_FLAGS = "D3D_97f627566e";
static const char *g_pszMainDocs_PS_CYCLESTATS_CAPTURE_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_BUCKET_COUNT)[] =
{
    "CAPTURE_BUCKET_COUNT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_PER_FRAME_DATA)[] =
{
    "CAPTURE_PER_FRAME_DATA",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_MERGED_STATE)[] =
{
    "CAPTURE_MERGED_STATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_BOOKMARKS)[] =
{
    "GENERATE_BOOKMARKS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_ENCODED_PMTRIGGERID)[] =
{
    "GENERATE_ENCODED_PMTRIGGERID",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_GPUIDLE_BUCKETS)[] =
{
    "HIDE_GPUIDLE_BUCKETS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_REPLAYER_BUCKETS)[] =
{
    "HIDE_REPLAYER_BUCKETS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_USE_PTIMER_TIMEBASE)[] =
{
    "USE_PTIMER_TIMEBASE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_MASK)[] =
{
    "TIMEBASE_CYCLES_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_DISABLED)[] =
{
    "TIMEBASE_CYCLES_DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_1K)[] =
{
    "TIMEBASE_CYCLES_1K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_2K)[] =
{
    "TIMEBASE_CYCLES_2K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_4K)[] =
{
    "TIMEBASE_CYCLES_4K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_8K)[] =
{
    "TIMEBASE_CYCLES_8K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_16K)[] =
{
    "TIMEBASE_CYCLES_16K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_32K)[] =
{
    "TIMEBASE_CYCLES_32K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_64K)[] =
{
    "TIMEBASE_CYCLES_64K",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_USE_LARGE_CAPTURE_BUFFER)[] =
{
    "USE_LARGE_CAPTURE_BUFFER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_PROCESS_SNAPSHOTS_AT_END)[] =
{
    "PROCESS_SNAPSHOTS_AT_END",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_AUTOEXIT_AT_END_FRAME)[] =
{
    "AUTOEXIT_AT_END_FRAME",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_CAPTURE_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_BUCKET_COUNT, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_PER_FRAME_DATA, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_MERGED_STATE, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_BOOKMARKS, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_ENCODED_PMTRIGGERID, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_GPUIDLE_BUCKETS, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_REPLAYER_BUCKETS, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_USE_PTIMER_TIMEBASE, 0x00008000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_MASK, 0x00ff0000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_DISABLED, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_1K, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_2K, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_4K, 0x00030000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_8K, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_16K, 0x00050000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_32K, 0x00060000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_64K, 0x00070000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_USE_LARGE_CAPTURE_BUFFER, 0x01000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_PROCESS_SNAPSHOTS_AT_END, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_CAPTURE_FLAGS_AUTOEXIT_AT_END_FRAME, 0x10000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_CAPTURE_FLAGS(
    0x10cc518e,
    g_pszKeyName_PS_CYCLESTATS_CAPTURE_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_CAPTURE_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_CAPTURE_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_CAPTURE_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_CAPTURE_FLAGS, 
    20, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG = "PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG = "D3D_97f6275680";
static const char *g_pszMainDocs_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG = "Capture results for a specific command queue, numbered in zero-based creation order. DX12 only.";

SettingDWORD g_setting_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG(
    0x107f047d,
    g_pszKeyName_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG,
    g_pszRemappedName_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG,
    g_pszMainDocs_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG,
    g_pszDefinedWhen_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_DEVICE_TO_LOG = "PS_CYCLESTATS_DEVICE_TO_LOG";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_DEVICE_TO_LOG = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_DEVICE_TO_LOG = "D3D_97f6275670";
static const char *g_pszMainDocs_PS_CYCLESTATS_DEVICE_TO_LOG = "Capture results for a specific device, numbered in zero-based creation order. Only supported on DX drivers.";

SettingDWORD g_setting_PS_CYCLESTATS_DEVICE_TO_LOG(
    0x106f047d,
    g_pszKeyName_PS_CYCLESTATS_DEVICE_TO_LOG,
    g_pszRemappedName_PS_CYCLESTATS_DEVICE_TO_LOG,
    g_pszMainDocs_PS_CYCLESTATS_DEVICE_TO_LOG,
    g_pszDefinedWhen_PS_CYCLESTATS_DEVICE_TO_LOG,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_DIRECTORY = "PS_CYCLESTATS_DIRECTORY";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_DIRECTORY = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_DIRECTORY = "D3D_97f627566b";
static const char *g_pszMainDocs_PS_CYCLESTATS_DIRECTORY = "This registry key is an override to the default directory for dumping the cyclestat (CPU and GPU) statistics.";

SettingSTRING g_setting_PS_CYCLESTATS_DIRECTORY(
    0x1092404a,
    g_pszKeyName_PS_CYCLESTATS_DIRECTORY,
    g_pszRemappedName_PS_CYCLESTATS_DIRECTORY,
    g_pszMainDocs_PS_CYCLESTATS_DIRECTORY,
    g_pszDefinedWhen_PS_CYCLESTATS_DIRECTORY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_DX12_TAGS_HACK = "PS_CYCLESTATS_DX12_TAGS_HACK";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_DX12_TAGS_HACK = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_DX12_TAGS_HACK = "D3D_01648913";
static const char *g_pszMainDocs_PS_CYCLESTATS_DX12_TAGS_HACK = "Enable the DX12 tags hack.";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_DX12_TAGS_HACK_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_DX12_TAGS_HACK_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_DX12_TAGS_HACK[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_DX12_TAGS_HACK_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_DX12_TAGS_HACK_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_CYCLESTATS_DX12_TAGS_HACK[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_CYCLESTATS_DX12_TAGS_HACK(
    0x102c8747,
    g_pszKeyName_PS_CYCLESTATS_DX12_TAGS_HACK,
    g_pszRemappedName_PS_CYCLESTATS_DX12_TAGS_HACK,
    g_pszMainDocs_PS_CYCLESTATS_DX12_TAGS_HACK,
    g_pszDefinedWhen_PS_CYCLESTATS_DX12_TAGS_HACK,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_CYCLESTATS_DX12_TAGS_HACK, 
    2, 
    g_aDefaultData_PS_CYCLESTATS_DX12_TAGS_HACK, 
    1 
);

static const char *g_pszKeyName_PS_CYCLESTATS_END_FRAME = "PS_CYCLESTATS_END_FRAME";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_END_FRAME = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_END_FRAME = "D3D_97f6275669";
static const char *g_pszMainDocs_PS_CYCLESTATS_END_FRAME = "";

SettingDWORD g_setting_PS_CYCLESTATS_END_FRAME(
    0x106f045d,
    g_pszKeyName_PS_CYCLESTATS_END_FRAME,
    g_pszRemappedName_PS_CYCLESTATS_END_FRAME,
    g_pszMainDocs_PS_CYCLESTATS_END_FRAME,
    g_pszDefinedWhen_PS_CYCLESTATS_END_FRAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_FLAGS = "PS_CYCLESTATS_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_FLAGS = "D3D_97f6275666";
static const char *g_pszMainDocs_PS_CYCLESTATS_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TAGS)[] =
{
    "TAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_RT)[] =
{
    "RT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PSHADER)[] =
{
    "PSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_VSHADER)[] =
{
    "VSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_FOG)[] =
{
    "FOG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_COLORWRITE)[] =
{
    "COLORWRITE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_DEPTHTEST)[] =
{
    "DEPTHTEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_ALPHATEST)[] =
{
    "ALPHATEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_STENCILENABLE)[] =
{
    "STENCILENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_CLIPPLANE)[] =
{
    "CLIPPLANE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_VB_TYPE)[] =
{
    "VB_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TEXTURE)[] =
{
    "TEXTURE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_LIGHTING)[] =
{
    "LIGHTING",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_BLEND)[] =
{
    "BLEND",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_GSHADER)[] =
{
    "GSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_STREAMOUT)[] =
{
    "STREAMOUT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_RES_HANDLE)[] =
{
    "RES_HANDLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_CULL)[] =
{
    "CULL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PERFSTRAT)[] =
{
    "PERFSTRAT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_IB_TYPE)[] =
{
    "IB_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PRIM_TYPE)[] =
{
    "PRIM_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_MINIMIZE_RT)[] =
{
    "MINIMIZE_RT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_API_STATE)[] =
{
    "API_STATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_POLYGON)[] =
{
    "POLYGON",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_QUERIES)[] =
{
    "QUERIES",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_APPSTATE)[] =
{
    "APPSTATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TESS)[] =
{
    "TESS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_COMPUTE)[] =
{
    "COMPUTE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_DRIVERSTATE)[] =
{
    "DRIVERSTATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_BUCKET_COUNT)[] =
{
    "BUCKET_COUNT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PER_FRAME_DATA)[] =
{
    "PER_FRAME_DATA",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TAGS, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_RT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PSHADER, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_VSHADER, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_FOG, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_COLORWRITE, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_DEPTHTEST, 0x00000040 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_ALPHATEST, 0x00000080 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_STENCILENABLE, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_CLIPPLANE, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_VB_TYPE, 0x00000400 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TEXTURE, 0x00000800 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_LIGHTING, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_BLEND, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_GSHADER, 0x00004000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_STREAMOUT, 0x00008000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_RES_HANDLE, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_CULL, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PERFSTRAT, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_IB_TYPE, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PRIM_TYPE, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_MINIMIZE_RT, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_API_STATE, 0x00400000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_POLYGON, 0x00800000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_QUERIES, 0x04000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_APPSTATE, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_TESS, 0x10000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_COMPUTE, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_DRIVERSTATE, 0x40000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_BUCKET_COUNT, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS_PER_FRAME_DATA, 0x80000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_FLAGS(
    0x10af471b,
    g_pszKeyName_PS_CYCLESTATS_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_FLAGS, 
    31, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_FLAGS2 = "PS_CYCLESTATS_FLAGS2";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_FLAGS2 = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_FLAGS2 = "D3D_97f627566a";
static const char *g_pszMainDocs_PS_CYCLESTATS_FLAGS2 = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_RT)[] =
{
    "RT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_EARLYZ)[] =
{
    "EARLYZ",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_ZCULL)[] =
{
    "ZCULL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_IDX)[] =
{
    "IDX",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_VSHADER)[] =
{
    "VSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_GSHADER)[] =
{
    "GSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PSHADER)[] =
{
    "PSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_TEXHEADER)[] =
{
    "TEXHEADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_TEXSAMPLER)[] =
{
    "TEXSAMPLER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_ALPHA_TEST)[] =
{
    "ALPHA_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_DEPTH_TEST)[] =
{
    "DEPTH_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_STENCIL_TEST)[] =
{
    "STENCIL_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_POLYGON_OFFSET)[] =
{
    "POLYGON_OFFSET",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_CULL)[] =
{
    "CULL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_POINTSPRITE)[] =
{
    "POINTSPRITE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_BLEND)[] =
{
    "BLEND",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_USERCLIP)[] =
{
    "USERCLIP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_STREAMOUT)[] =
{
    "STREAMOUT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PEEK_AT_DRV_MASKS)[] =
{
    "PEEK_AT_DRV_MASKS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PTE_TRAVERSAL)[] =
{
    "PTE_TRAVERSAL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_TILEDREGION)[] =
{
    "NO_TILEDREGION",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_ZCULL_DETAILS)[] =
{
    "NO_ZCULL_DETAILS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_PTE_COUNTS)[] =
{
    "NO_PTE_COUNTS",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_FLAGS2[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_RT, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_EARLYZ, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_ZCULL, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_IDX, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_VSHADER, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_GSHADER, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PSHADER, 0x00000040 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_TEXHEADER, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_TEXSAMPLER, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_ALPHA_TEST, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_DEPTH_TEST, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_STENCIL_TEST, 0x00004000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_POLYGON_OFFSET, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_CULL, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_POINTSPRITE, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_BLEND, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_USERCLIP, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_STREAMOUT, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PEEK_AT_DRV_MASKS, 0x04000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_PTE_TRAVERSAL, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_TILEDREGION, 0x10000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_ZCULL_DETAILS, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_FLAGS2_NO_PTE_COUNTS, 0x40000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_FLAGS2(
    0x100bb035,
    g_pszKeyName_PS_CYCLESTATS_FLAGS2,
    g_pszRemappedName_PS_CYCLESTATS_FLAGS2,
    g_pszMainDocs_PS_CYCLESTATS_FLAGS2,
    g_pszDefinedWhen_PS_CYCLESTATS_FLAGS2,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_FLAGS2, 
    23, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_GPU_TO_LOG = "PS_CYCLESTATS_GPU_TO_LOG";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_GPU_TO_LOG = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_GPU_TO_LOG = "D3D_97f6275672";
static const char *g_pszMainDocs_PS_CYCLESTATS_GPU_TO_LOG = "Capture results for a specific gpu, numbered in zero-based creation order. Only supported on DX drivers.";

SettingDWORD g_setting_PS_CYCLESTATS_GPU_TO_LOG(
    0x106f047f,
    g_pszKeyName_PS_CYCLESTATS_GPU_TO_LOG,
    g_pszRemappedName_PS_CYCLESTATS_GPU_TO_LOG,
    g_pszMainDocs_PS_CYCLESTATS_GPU_TO_LOG,
    g_pszDefinedWhen_PS_CYCLESTATS_GPU_TO_LOG,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_HOTKEY = "PS_CYCLESTATS_HOTKEY";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_HOTKEY = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_HOTKEY = "D3D_01648912";
static const char *g_pszMainDocs_PS_CYCLESTATS_HOTKEY = "Set custom key for cyclestats 'hotkey' event [also need to set HOTKEYS regkey] (default is ctrl+F6)";

DataDefaultDWORD g_aDefaultData_PS_CYCLESTATS_HOTKEY[] =
{
    {"DEFAULT", 0x75, "" }, 
};

SettingDWORD g_setting_PS_CYCLESTATS_HOTKEY(
    0x102c8746,
    g_pszKeyName_PS_CYCLESTATS_HOTKEY,
    g_pszRemappedName_PS_CYCLESTATS_HOTKEY,
    g_pszMainDocs_PS_CYCLESTATS_HOTKEY,
    g_pszDefinedWhen_PS_CYCLESTATS_HOTKEY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_CYCLESTATS_HOTKEY, 
    1 
);

static const char *g_pszKeyName_PS_CYCLESTATS_LAUNCH_FLAGS = "PS_CYCLESTATS_LAUNCH_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_LAUNCH_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_LAUNCH_FLAGS = "D3D_a766215670";
static const char *g_pszMainDocs_PS_CYCLESTATS_LAUNCH_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_DEFER_INIT)[] =
{
    "DO_NOT_DEFER_INIT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_DWM)[] =
{
    "DONT_IGNORE_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_INIT)[] =
{
    "DO_NOT_INIT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_COMPUTE_ONLY)[] =
{
    "IGNORE_COMPUTE_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_NON_COMPUTE_ONLY)[] =
{
    "IGNORE_NON_COMPUTE_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_METRO_APPS)[] =
{
    "DONT_IGNORE_METRO_APPS",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_LAUNCH_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_DEFER_INIT, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_DWM, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_INIT, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_COMPUTE_ONLY, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_NON_COMPUTE_ONLY, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_METRO_APPS, 0x00000020 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_LAUNCH_FLAGS(
    0x106c51f0,
    g_pszKeyName_PS_CYCLESTATS_LAUNCH_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_LAUNCH_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_LAUNCH_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_LAUNCH_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_LAUNCH_FLAGS, 
    6, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH = "PS_CYCLESTATS_MAX_APP_REGIME_DEPTH";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH = "D3D_97f6275487";
static const char *g_pszMainDocs_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH = "Maximum depth of the app's regime description stack (e.g., 1 -> 'SCENE', 2 -> 'SCENE/PASS', 3 -> 'SCENE/PASS/BATCH'";

SettingDWORD g_setting_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH(
    0x10f68487,
    g_pszKeyName_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH,
    g_pszRemappedName_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH,
    g_pszMainDocs_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH,
    g_pszDefinedWhen_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_MERGE_FLAGS = "PS_CYCLESTATS_MERGE_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_MERGE_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_MERGE_FLAGS = "D3D_97f627566d";
static const char *g_pszMainDocs_PS_CYCLESTATS_MERGE_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TAGS)[] =
{
    "TAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_RT)[] =
{
    "RT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PSHADER)[] =
{
    "PSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_VSHADER)[] =
{
    "VSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_FOG)[] =
{
    "FOG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_COLORWRITE)[] =
{
    "COLORWRITE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DEPTHTEST)[] =
{
    "DEPTHTEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_ALPHATEST)[] =
{
    "ALPHATEST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_STENCILENABLE)[] =
{
    "STENCILENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_CLIPPLANE)[] =
{
    "CLIPPLANE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_VB_TYPE)[] =
{
    "VB_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TEXTURE)[] =
{
    "TEXTURE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_LIGHTING)[] =
{
    "LIGHTING",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_BLEND)[] =
{
    "BLEND",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_GSHADER)[] =
{
    "GSHADER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_STREAMOUT)[] =
{
    "STREAMOUT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_RES_HANDLE)[] =
{
    "RES_HANDLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_CULL)[] =
{
    "CULL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PERFSTRAT)[] =
{
    "PERFSTRAT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_IB_TYPE)[] =
{
    "IB_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PRIM_TYPE)[] =
{
    "PRIM_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DISPATCH_TYPE)[] =
{
    "DISPATCH_TYPE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_API_ARGS)[] =
{
    "API_ARGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_POLYGON)[] =
{
    "POLYGON",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_QUERIES)[] =
{
    "QUERIES",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_APPSTATE)[] =
{
    "APPSTATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TESS)[] =
{
    "TESS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_COMPUTE)[] =
{
    "COMPUTE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DRIVERSTATE)[] =
{
    "DRIVERSTATE",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_MERGE_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TAGS, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_RT, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PSHADER, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_VSHADER, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_FOG, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_COLORWRITE, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DEPTHTEST, 0x00000040 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_ALPHATEST, 0x00000080 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_STENCILENABLE, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_CLIPPLANE, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_VB_TYPE, 0x00000400 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TEXTURE, 0x00000800 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_LIGHTING, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_BLEND, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_GSHADER, 0x00004000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_STREAMOUT, 0x00008000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_RES_HANDLE, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_CULL, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PERFSTRAT, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_IB_TYPE, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_PRIM_TYPE, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DISPATCH_TYPE, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_API_ARGS, 0x00400000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_POLYGON, 0x00800000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_QUERIES, 0x04000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_APPSTATE, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_TESS, 0x10000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_COMPUTE, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_MERGE_FLAGS_DRIVERSTATE, 0x40000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_MERGE_FLAGS(
    0x105bbe5a,
    g_pszKeyName_PS_CYCLESTATS_MERGE_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_MERGE_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_MERGE_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_MERGE_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_MERGE_FLAGS, 
    29, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_PM_CONFIG = "PS_CYCLESTATS_PM_CONFIG";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_PM_CONFIG = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_PM_CONFIG = "D3D_b7f6275666";
static const char *g_pszMainDocs_PS_CYCLESTATS_PM_CONFIG = "";

SettingSTRING g_setting_PS_CYCLESTATS_PM_CONFIG(
    0x10ec5979,
    g_pszKeyName_PS_CYCLESTATS_PM_CONFIG,
    g_pszRemappedName_PS_CYCLESTATS_PM_CONFIG,
    g_pszMainDocs_PS_CYCLESTATS_PM_CONFIG,
    g_pszDefinedWhen_PS_CYCLESTATS_PM_CONFIG,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_PROCESS_TO_LOG = "PS_CYCLESTATS_PROCESS_TO_LOG";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_PROCESS_TO_LOG = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_PROCESS_TO_LOG = "D3D_97f6275671";
static const char *g_pszMainDocs_PS_CYCLESTATS_PROCESS_TO_LOG = "Capture results for a specific process, given as 'process.exe'. Only supported on DX drivers.";

SettingSTRING g_setting_PS_CYCLESTATS_PROCESS_TO_LOG(
    0x106f047e,
    g_pszKeyName_PS_CYCLESTATS_PROCESS_TO_LOG,
    g_pszRemappedName_PS_CYCLESTATS_PROCESS_TO_LOG,
    g_pszMainDocs_PS_CYCLESTATS_PROCESS_TO_LOG,
    g_pszDefinedWhen_PS_CYCLESTATS_PROCESS_TO_LOG,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_PROFILER_FLAGS = "PS_CYCLESTATS_PROFILER_FLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_PROFILER_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_PROFILER_FLAGS = "D3D_97f627566f";
static const char *g_pszMainDocs_PS_CYCLESTATS_PROFILER_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_FORCE_SINGLE_INSTANCE)[] =
{
    "FORCE_SINGLE_INSTANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_AUTOEXIT_AFTER_N_LOOPS_MASK)[] =
{
    "AUTOEXIT_AFTER_N_LOOPS_MASK",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_PROFILER_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_ENABLE, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_FORCE_SINGLE_INSTANCE, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_PROFILER_FLAGS_AUTOEXIT_AFTER_N_LOOPS_MASK, 0xff000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_PROFILER_FLAGS(
    0x10cc518f,
    g_pszKeyName_PS_CYCLESTATS_PROFILER_FLAGS,
    g_pszRemappedName_PS_CYCLESTATS_PROFILER_FLAGS,
    g_pszMainDocs_PS_CYCLESTATS_PROFILER_FLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_PROFILER_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_PROFILER_FLAGS, 
    3, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_START_FRAME = "PS_CYCLESTATS_START_FRAME";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_START_FRAME = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_START_FRAME = "D3D_97f6275668";
static const char *g_pszMainDocs_PS_CYCLESTATS_START_FRAME = "";

SettingDWORD g_setting_PS_CYCLESTATS_START_FRAME(
    0x10f68558,
    g_pszKeyName_PS_CYCLESTATS_START_FRAME,
    g_pszRemappedName_PS_CYCLESTATS_START_FRAME,
    g_pszMainDocs_PS_CYCLESTATS_START_FRAME,
    g_pszDefinedWhen_PS_CYCLESTATS_START_FRAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_CYCLESTATS_XFLAGS = "PS_CYCLESTATS_XFLAGS";
static const char *g_pszDefinedWhen_PS_CYCLESTATS_XFLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_CYCLESTATS_XFLAGS = "D3D_97f6275667";
static const char *g_pszMainDocs_PS_CYCLESTATS_XFLAGS = "";

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_READ_PM_USING_CPU)[] =
{
    "READ_PM_USING_CPU",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_IDENTIFY_BUCKETS)[] =
{
    "IDENTIFY_BUCKETS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_STALL_CHECK)[] =
{
    "NO_STALL_CHECK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SKIP_DEAD_FRAMES)[] =
{
    "SKIP_DEAD_FRAMES",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_TRANSITIONS)[] =
{
    "REPORT_TRANSITIONS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_VPM_ENABLE_EOT)[] =
{
    "VPM_ENABLE_EOT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_TIMESTAMPS)[] =
{
    "NO_TIMESTAMPS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_SEGMENTS)[] =
{
    "MERGE_SEGMENTS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_MASK)[] =
{
    "SORT_BY_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_NAME)[] =
{
    "SORT_BY_NAME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_APPEARANCE)[] =
{
    "SORT_BY_APPEARANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_TIME)[] =
{
    "SORT_BY_TIME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_CLEAR)[] =
{
    "DUMP_BEFORE_CLEAR",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_TRANS)[] =
{
    "DUMP_BEFORE_TRANS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_FLIP)[] =
{
    "DUMP_BEFORE_FLIP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_SELECTION)[] =
{
    "DUMP_SELECTION",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_HTML_REPORT)[] =
{
    "HTML_REPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_PMTRIGGERCT)[] =
{
    "REPORT_PMTRIGGERCT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_TAG_OWN_PB_METHODS)[] =
{
    "TAG_OWN_PB_METHODS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_WAIT_UNTIL_KB_TRIGGER)[] =
{
    "WAIT_UNTIL_KB_TRIGGER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_ANNOTATE)[] =
{
    "ANNOTATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_FORCE_DONOTWAIT)[] =
{
    "FORCE_DONOTWAIT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_VPM_SIGNAL_START_END)[] =
{
    "VPM_SIGNAL_START_END",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MINIMIZE_WFI_PMTRIG)[] =
{
    "MINIMIZE_WFI_PMTRIG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_3DSTATEBUCKETS)[] =
{
    "MERGE_3DSTATEBUCKETS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_TRANSITION_RESET)[] =
{
    "NO_TRANSITION_RESET",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_RESET_PMTRIGGERCT)[] =
{
    "RESET_PMTRIGGERCT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_RENDBATCHCT)[] =
{
    "REPORT_RENDBATCHCT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_FULL_FRAME_MODE)[] =
{
    "FULL_FRAME_MODE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_SCG)[] =
{
    "MERGE_SCG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_START_WITH_PM_PAUSED)[] =
{
    "START_WITH_PM_PAUSED",
    NULL
};

DataValueDWORD g_aDefineData_PS_CYCLESTATS_XFLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_READ_PM_USING_CPU, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_IDENTIFY_BUCKETS, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_STALL_CHECK, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SKIP_DEAD_FRAMES, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_TRANSITIONS, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_VPM_ENABLE_EOT, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_TIMESTAMPS, 0x00000040 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_SEGMENTS, 0x00000080 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_MASK, 0x00000300 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_NAME, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_APPEARANCE, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_SORT_BY_TIME, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_CLEAR, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_TRANS, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_FLIP, 0x00004000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_DUMP_SELECTION, 0x00008000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_HTML_REPORT, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_PMTRIGGERCT, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_TAG_OWN_PB_METHODS, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_WAIT_UNTIL_KB_TRIGGER, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_ANNOTATE, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_FORCE_DONOTWAIT, 0x00400000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_VPM_SIGNAL_START_END, 0x00800000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MINIMIZE_WFI_PMTRIG, 0x01000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_3DSTATEBUCKETS, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_NO_TRANSITION_RESET, 0x04000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_RESET_PMTRIGGERCT, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_REPORT_RENDBATCHCT, 0x10000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_FULL_FRAME_MODE, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_MERGE_SCG, 0x40000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_CYCLESTATS_XFLAGS_START_WITH_PM_PAUSED, 0x80000000 , "" },
};

SettingDWORD g_setting_PS_CYCLESTATS_XFLAGS(
    0x10cc5188,
    g_pszKeyName_PS_CYCLESTATS_XFLAGS,
    g_pszRemappedName_PS_CYCLESTATS_XFLAGS,
    g_pszMainDocs_PS_CYCLESTATS_XFLAGS,
    g_pszDefinedWhen_PS_CYCLESTATS_XFLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_CYCLESTATS_XFLAGS, 
    31, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_DUMPREGISTERS = "PS_DUMPREGISTERS";
static const char *g_pszDefinedWhen_PS_DUMPREGISTERS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_DUMPREGISTERS = "D3D_d13733f12";
static const char *g_pszMainDocs_PS_DUMPREGISTERS = "Dumps all registers value specified in PS_DUMPREGISTERS_INPUT_FILE";

static const char * (g_ppszDefineDataNames_PS_DUMPREGISTERS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_DUMPREGISTERS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_DUMPREGISTERS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_DUMPREGISTERS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_DUMPREGISTERS_ON, 0x00000001 , "" },
};

SettingDWORD g_setting_PS_DUMPREGISTERS(
    0x10dd1fa3,
    g_pszKeyName_PS_DUMPREGISTERS,
    g_pszRemappedName_PS_DUMPREGISTERS,
    g_pszMainDocs_PS_DUMPREGISTERS,
    g_pszDefinedWhen_PS_DUMPREGISTERS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_DUMPREGISTERS, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_DUMPREGISTERS_INPUT_FILE = "PS_DUMPREGISTERS_INPUT_FILE";
static const char *g_pszDefinedWhen_PS_DUMPREGISTERS_INPUT_FILE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_DUMPREGISTERS_INPUT_FILE = "D3D_df1f9812";
static const char *g_pszMainDocs_PS_DUMPREGISTERS_INPUT_FILE = "";

SettingSTRING g_setting_PS_DUMPREGISTERS_INPUT_FILE(
    0x10dd1fa4,
    g_pszKeyName_PS_DUMPREGISTERS_INPUT_FILE,
    g_pszRemappedName_PS_DUMPREGISTERS_INPUT_FILE,
    g_pszMainDocs_PS_DUMPREGISTERS_INPUT_FILE,
    g_pszDefinedWhen_PS_DUMPREGISTERS_INPUT_FILE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_FRAMERATE_LIMITER = "PS_FRAMERATE_LIMITER";
static const char *g_pszDefinedWhen_PS_FRAMERATE_LIMITER = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_LIMITER = "D3DOGL_00008600";
static const char *g_pszMainDocs_PS_FRAMERATE_LIMITER = "Framerate Limiter parameters, bit 31 to enable and LOWBYTE set to frames/sec";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_20)[] =
{
    "FPS_20",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_30)[] =
{
    "FPS_30",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_40)[] =
{
    "FPS_40",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPSMASK)[] =
{
    "FPSMASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_DYNAMIC)[] =
{
    "ALLOW_DYNAMIC",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_YIELD_PROCESSOR)[] =
{
    "YIELD_PROCESSOR",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FORCE_VSYNC_OFF)[] =
{
    "FORCE_VSYNC_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_DISALLOWED)[] =
{
    "DISALLOWED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_NO_LAG_OFFSET)[] =
{
    "NO_LAG_OFFSET",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_SLEEP_WITH_REFLEX)[] =
{
    "ALLOW_SLEEP_WITH_REFLEX",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ACCURATE)[] =
{
    "ACCURATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_WINDOWED)[] =
{
    "ALLOW_WINDOWED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FORCEON)[] =
{
    "FORCEON",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_OPENGL_REMOTE_DESKTOP)[] =
{
    "OPENGL_REMOTE_DESKTOP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_LOW_LATENCY_DEFAULT)[] =
{
    "LOW_LATENCY_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_MFR_FLAGS)[] =
{
    "MFR_FLAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GFN_FLAGS)[] =
{
    "GFN_FLAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_MASK)[] =
{
    "MASK",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_LIMITER[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_20, 0x00000014 , "Framerate set to 20 frames per sec" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_30, 0x0000001e , "Framerate set to 30 frames per sec" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPS_40, 0x00000028 , "Framerate set to 40 frames per sec" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FPSMASK, 0x000003ff , "Frames per sec mask" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_DYNAMIC, 0x00001000 , "Allow limit to be set dynamically" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_YIELD_PROCESSOR, 0x00002000 , "Use YieldProcessor() for accurate CPU wait, instead of Sleep(0)" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FORCE_VSYNC_OFF, 0x00040000 , "Force VSYNC OFF if this bit is set." },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_DISALLOWED, 0x00200000 , "Per app disable bit" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_NO_LAG_OFFSET, 0x00800000 , "Do not apply offset to account for observed lag" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_SLEEP_WITH_REFLEX, 0x02000000 , "Allow sleep with Reflex" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ACCURATE, 0x10000000 , "Accurate setting of fps but higer CPU usage" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ALLOW_WINDOWED, 0x20000000 , "Allow limiting of windowed applications" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_FORCEON, 0x40000000 , "Force enable, ignore AC/DC status" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_ENABLED, 0x80000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_OPENGL_REMOTE_DESKTOP, 0xe000003c , "Setting used for OpenGL Remote Desktop Sessions" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_LOW_LATENCY_DEFAULT, 0xb0802000 , "Setting used for low latency" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_MFR_FLAGS, 0xf0802000 , "Setting used for max frame rate" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GFN_FLAGS, 0xf2803000 , "Setting used for GFN" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_MASK, 0xf2a433ff , "Mask of all bits used" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_LIMITER[] =
{
    {"DEFAULT", 0xb0802000, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_LIMITER(
    0x10834fee,
    g_pszKeyName_PS_FRAMERATE_LIMITER,
    g_pszRemappedName_PS_FRAMERATE_LIMITER,
    g_pszMainDocs_PS_FRAMERATE_LIMITER,
    g_pszDefinedWhen_PS_FRAMERATE_LIMITER,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_LIMITER, 
    20, 
    g_aDefaultData_PS_FRAMERATE_LIMITER, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_LIMITER_2_CONTROL = "PS_FRAMERATE_LIMITER_2_CONTROL";
static const char *g_pszDefinedWhen_PS_FRAMERATE_LIMITER_2_CONTROL = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_LIMITER_2_CONTROL = "D3DOGL_00008602";
static const char *g_pszMainDocs_PS_FRAMERATE_LIMITER_2_CONTROL = "Framerate Limiter 2 controls (deprecated)";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE)[] =
{
    "DELAY_CE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_3D)[] =
{
    "DELAY_3D",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_AVOID_NOOP)[] =
{
    "AVOID_NOOP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE_PRESENT_3D)[] =
{
    "DELAY_CE_PRESENT_3D",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL_MAXWELL)[] =
{
    "ALLOW_ALL_MAXWELL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL)[] =
{
    "ALLOW_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ENABLE_VCE)[] =
{
    "ENABLE_VCE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DEFAULT_FOR_GM10X)[] =
{
    "DEFAULT_FOR_GM10X",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_LIMITER_2_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE, 0x00000000 , "Always block CE" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_3D, 0x00000001 , "Always block 3D" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_AVOID_NOOP, 0x00000002 , "Avoid the noop buffer. Block CE when CE is used and 3D when 3D is used" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE_PRESENT_3D, 0x00000008 , "For All, FRL delay buffer on CE And For discrete, Present on 3D" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL_MAXWELL, 0x00000010 , "Do not restrict to Maxwell_b, but allow on all maxwell chips" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL, 0x00000020 , "Allow on all chips" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_FORCE_OFF, 0x00000040 , "Force off on all chips" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_ENABLE_VCE, 0x00000080 , "Delay on Virtual CE node if DELAY_CE is set for Mshybrid" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_2_CONTROL_DEFAULT_FOR_GM10X, 0x00000011 , "Default setting for GM10X" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_LIMITER_2_CONTROL[] =
{
    {"DEFAULT", 0x00000088, "ENABLE_VCE | DELAY_CE_PRESENT_3D" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_LIMITER_2_CONTROL(
    0x10834fff,
    g_pszKeyName_PS_FRAMERATE_LIMITER_2_CONTROL,
    g_pszRemappedName_PS_FRAMERATE_LIMITER_2_CONTROL,
    g_pszMainDocs_PS_FRAMERATE_LIMITER_2_CONTROL,
    g_pszDefinedWhen_PS_FRAMERATE_LIMITER_2_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_LIMITER_2_CONTROL, 
    9, 
    g_aDefaultData_PS_FRAMERATE_LIMITER_2_CONTROL, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_LIMITER_GPS_CTRL = "PS_FRAMERATE_LIMITER_GPS_CTRL";
static const char *g_pszDefinedWhen_PS_FRAMERATE_LIMITER_GPS_CTRL = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_LIMITER_GPS_CTRL = "D3DOGL_70008600";
static const char *g_pszMainDocs_PS_FRAMERATE_LIMITER_GPS_CTRL = "FRM parameters (deprecated)";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_DECREASE_FILTER_MASK)[] =
{
    "DECREASE_FILTER_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_MASK)[] =
{
    "PAUSE_TIME_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_SHIFT)[] =
{
    "PAUSE_TIME_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_MASK)[] =
{
    "TARGET_RENDER_TIME_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_SHIFT)[] =
{
    "TARGET_RENDER_TIME_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_MASK)[] =
{
    "PERF_STEP_SIZE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_SHIFT)[] =
{
    "PERF_STEP_SIZE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_MASK)[] =
{
    "INCREASE_FILTER_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_SHIFT)[] =
{
    "INCREASE_FILTER_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_OPTIMAL_SETTING)[] =
{
    "OPTIMAL_SETTING",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_LIMITER_GPS_CTRL[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_DECREASE_FILTER_MASK, 0x000001FF , "*8 milliseconds" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_MASK, 0x0000FE00 , "*4 milliseconds" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_SHIFT, 9 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_MASK, 0x00FF0000 , "percentage" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_SHIFT, 16 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_MASK, 0x1F000000 , "percentage" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_SHIFT, 24 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_MASK, 0xE0000000 , "frames" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_SHIFT, 29 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LIMITER_GPS_CTRL_OPTIMAL_SETTING, 0x4A5A3219 , "Current optimal settings" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_LIMITER_GPS_CTRL[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_LIMITER_GPS_CTRL(
    0x10834f01,
    g_pszKeyName_PS_FRAMERATE_LIMITER_GPS_CTRL,
    g_pszRemappedName_PS_FRAMERATE_LIMITER_GPS_CTRL,
    g_pszMainDocs_PS_FRAMERATE_LIMITER_GPS_CTRL,
    g_pszDefinedWhen_PS_FRAMERATE_LIMITER_GPS_CTRL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_LIMITER_GPS_CTRL, 
    11, 
    g_aDefaultData_PS_FRAMERATE_LIMITER_GPS_CTRL, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_LOGGER = "PS_FRAMERATE_LOGGER";
static const char *g_pszDefinedWhen_PS_FRAMERATE_LOGGER = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_LOGGER = "D3DOGL_90008600";
static const char *g_pszMainDocs_PS_FRAMERATE_LOGGER = "FPS overlay and simple text logging";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_DISPLAY)[] =
{
    "DISPLAY",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_LOGTOFILE)[] =
{
    "LOGTOFILE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_LOGTOETW)[] =
{
    "LOGTOETW",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_ALLOWDWM)[] =
{
    "ALLOWDWM",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_LOGGER[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_DISPLAY, 0x00000001 , "Display on screen" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_LOGTOFILE, 0x00000002 , "Log to file framerate.log" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_LOGTOETW, 0x00000004 , "Log to ETW" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_LOGGER_ALLOWDWM, 0x00000008 , "Permit DWM Monitoring" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_LOGGER[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_LOGGER(
    0x10834f03,
    g_pszKeyName_PS_FRAMERATE_LOGGER,
    g_pszRemappedName_PS_FRAMERATE_LOGGER,
    g_pszMainDocs_PS_FRAMERATE_LOGGER,
    g_pszDefinedWhen_PS_FRAMERATE_LOGGER,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_FRAMERATE_LOGGER, 
    5, 
    g_aDefaultData_PS_FRAMERATE_LOGGER, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_MONITOR_CTRL = "PS_FRAMERATE_MONITOR_CTRL";
static const char *g_pszDefinedWhen_PS_FRAMERATE_MONITOR_CTRL = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_MONITOR_CTRL = "D3DOGL_B0008600";
static const char *g_pszMainDocs_PS_FRAMERATE_MONITOR_CTRL = "FRM control parameters";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_THRESHOLD_PCT_MASK)[] =
{
    "THRESHOLD_PCT_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_MASK)[] =
{
    "MOVING_AVG_X_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_SHIFT)[] =
{
    "MOVING_AVG_X_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_MASK)[] =
{
    "VSYNC_OFFSET_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_SHIFT)[] =
{
    "VSYNC_OFFSET_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_MASK)[] =
{
    "FRL_OFFSET_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_SHIFT)[] =
{
    "FRL_OFFSET_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_USE_FRL)[] =
{
    "FPS_USE_FRL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_LOW_LATENCY_LOG)[] =
{
    "LOW_LATENCY_LOG",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_ALLOW_AUTOFL_WITH_REFLEX)[] =
{
    "ALLOW_AUTOFL_WITH_REFLEX",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_DISABLE_MAP_GPU_TIMER)[] =
{
    "DISABLE_MAP_GPU_TIMER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_ENABLE_ON_VSYNC)[] =
{
    "ENABLE_ON_VSYNC",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_30)[] =
{
    "FPS_30",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_60)[] =
{
    "FPS_60",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_MASK)[] =
{
    "FPS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_SHIFT)[] =
{
    "FPS_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING)[] =
{
    "OPTIMAL_SETTING",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING_V2)[] =
{
    "OPTIMAL_SETTING_V2",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING)[] =
{
    "VSYNC_OPTIMAL_SETTING",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING_V2)[] =
{
    "VSYNC_OPTIMAL_SETTING_V2",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_MONITOR_CTRL[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_THRESHOLD_PCT_MASK, 0x000000FF , "Trigger threshold in 0.01%" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_MASK, 0x00000F00 , "Number of frames to apply moving average over" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_SHIFT, 8 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_MASK, 0x0000F000 , "offset to target in 0.25ms for VSYNC mode" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_SHIFT, 12 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_MASK, 0x000F0000 , "offset to target in 0.25ms for FRL mode" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_SHIFT, 16 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_USE_FRL, 0x00000000 , "Enable FRM only when FRL is enabled (default)" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_LOW_LATENCY_LOG, 0x00100000 , "Enable data collection for low latency." },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_ALLOW_AUTOFL_WITH_REFLEX, 0x00200000 , "Allow AutoFL with Reflex" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_DISABLE_MAP_GPU_TIMER, 0x00400000 , "Use GPU Timer registers to get GPU timestamps" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_ENABLE_ON_VSYNC, 0x00800000 , "Enable FRM when (adaptive) VSYNC is ON" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_30, 0x1E000000 , "Enable FRM at 30 FPS regardless of FRL" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_60, 0x3C000000 , "Enable FRM at 60 FPS regardless of FRL" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_MASK, 0xFF000000 , "Enable FRM at target FPS" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_FPS_SHIFT, 24 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING, 0x00600364 , "Optimal settings (no VSYNC mode)" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING_V2, 0x00680364 , "Optimal settings (no VSYNC mode) V2" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING, 0x00E0f364 , "Optimal settings (with VSYNC mode)" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING_V2, 0x00E8f364 , "Optimal settings (with VSYNC mode) V2" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_MONITOR_CTRL[] =
{
    {"DEFAULT", 0x00600364, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_MONITOR_CTRL(
    0x10834f05,
    g_pszKeyName_PS_FRAMERATE_MONITOR_CTRL,
    g_pszRemappedName_PS_FRAMERATE_MONITOR_CTRL,
    g_pszMainDocs_PS_FRAMERATE_MONITOR_CTRL,
    g_pszDefinedWhen_PS_FRAMERATE_MONITOR_CTRL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_MONITOR_CTRL, 
    21, 
    g_aDefaultData_PS_FRAMERATE_MONITOR_CTRL, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_MONITOR_OVERRIDE = "PS_FRAMERATE_MONITOR_OVERRIDE";
static const char *g_pszDefinedWhen_PS_FRAMERATE_MONITOR_OVERRIDE = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_MONITOR_OVERRIDE = "D3DOGL_C0008600";
static const char *g_pszMainDocs_PS_FRAMERATE_MONITOR_OVERRIDE = "FRM override parameters";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_ALL)[] =
{
    "DISABLE_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_VSYNC)[] =
{
    "IGNORE_VSYNC",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_AND_IGNORE_REQUEST_MAXPERF)[] =
{
    "DISABLE_AND_IGNORE_REQUEST_MAXPERF",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_MULTI_DEVICE)[] =
{
    "IGNORE_MULTI_DEVICE",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_MONITOR_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_NONE, 0x00000000 , "No override" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_ALL, 0x00000001 , "Disable FRM" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_VSYNC, 0x00000002 , "Ignore VSYNC is ON" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_AND_IGNORE_REQUEST_MAXPERF, 0x00000004 , "Disable FRM and ignore requesting max perf so that OPTP does not get disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_MULTI_DEVICE, 0x00000008 , "Bypass refcounting. DO NOT SET FOR GAMES THAT ACTIVELY USE MULTIPLE DEVICES!!!" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_MONITOR_OVERRIDE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_MONITOR_OVERRIDE(
    0x10834f06,
    g_pszKeyName_PS_FRAMERATE_MONITOR_OVERRIDE,
    g_pszRemappedName_PS_FRAMERATE_MONITOR_OVERRIDE,
    g_pszMainDocs_PS_FRAMERATE_MONITOR_OVERRIDE,
    g_pszDefinedWhen_PS_FRAMERATE_MONITOR_OVERRIDE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_MONITOR_OVERRIDE, 
    5, 
    g_aDefaultData_PS_FRAMERATE_MONITOR_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_MONITOR_REPORTING = "PS_FRAMERATE_MONITOR_REPORTING";
static const char *g_pszDefinedWhen_PS_FRAMERATE_MONITOR_REPORTING = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_MONITOR_REPORTING = "D3DOGL_80008600";
static const char *g_pszMainDocs_PS_FRAMERATE_MONITOR_REPORTING = "Enable FRM reporting per present basis";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_REPORTING_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_REPORTING_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_MONITOR_REPORTING[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_REPORTING_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_REPORTING_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_MONITOR_REPORTING[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_MONITOR_REPORTING(
    0x10834f02,
    g_pszKeyName_PS_FRAMERATE_MONITOR_REPORTING,
    g_pszRemappedName_PS_FRAMERATE_MONITOR_REPORTING,
    g_pszMainDocs_PS_FRAMERATE_MONITOR_REPORTING,
    g_pszDefinedWhen_PS_FRAMERATE_MONITOR_REPORTING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_FRAMERATE_MONITOR_REPORTING, 
    2, 
    g_aDefaultData_PS_FRAMERATE_MONITOR_REPORTING, 
    1 
);

static const char *g_pszKeyName_PS_FRAMERATE_MONITOR_VR = "PS_FRAMERATE_MONITOR_VR";
static const char *g_pszDefinedWhen_PS_FRAMERATE_MONITOR_VR = "1";
static const char *g_pszRemappedName_PS_FRAMERATE_MONITOR_VR = "D3DOGL_D0008600";
static const char *g_pszMainDocs_PS_FRAMERATE_MONITOR_VR = "FRM control parameters for VR";

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_RENDER_TIME_MASK)[] =
{
    "TARGET_RENDER_TIME_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_MASK)[] =
{
    "TARGET_COMPOSITION_TIME_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_SHIFT)[] =
{
    "TARGET_COMPOSITION_TIME_SHIFT",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRAMERATE_MONITOR_VR[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_RENDER_TIME_MASK, 0x0000ffff , "VR target render time in microseconds" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_MASK, 0xffff0000 , "VR target composition time in microseconds" },
    { (const char **)g_ppszDefineDataNames_PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_SHIFT, 16 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_FRAMERATE_MONITOR_VR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_FRAMERATE_MONITOR_VR(
    0x10834f07,
    g_pszKeyName_PS_FRAMERATE_MONITOR_VR,
    g_pszRemappedName_PS_FRAMERATE_MONITOR_VR,
    g_pszMainDocs_PS_FRAMERATE_MONITOR_VR,
    g_pszDefinedWhen_PS_FRAMERATE_MONITOR_VR,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRAMERATE_MONITOR_VR, 
    4, 
    g_aDefaultData_PS_FRAMERATE_MONITOR_VR, 
    1 
);

static const char *g_pszKeyName_PS_FRL_LOADING_WAR = "PS_FRL_LOADING_WAR";
static const char *g_pszDefinedWhen_PS_FRL_LOADING_WAR = "1";
static const char *g_pszRemappedName_PS_FRL_LOADING_WAR = "D3DOGL_A0008600";
static const char *g_pszMainDocs_PS_FRL_LOADING_WAR = "FRL workaround for long loading scene";

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_SAFE_FPS_MASK)[] =
{
    "SAFE_FPS_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_ON_MASK)[] =
{
    "FILTER_ON_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_ON_SHIFT)[] =
{
    "FILTER_ON_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_OFF_MASK)[] =
{
    "FILTER_OFF_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_OFF_SHIFT)[] =
{
    "FILTER_OFF_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_THRESHOLD_US_MASK)[] =
{
    "THRESHOLD_US_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_THRESHOLD_US_SHIFT)[] =
{
    "THRESHOLD_US_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_FRL_LOADING_WAR_DEFAULT_SETTING)[] =
{
    "DEFAULT_SETTING",
    NULL
};

DataValueDWORD g_aDefineData_PS_FRL_LOADING_WAR[] =
{
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_SAFE_FPS_MASK, 0x000000FF , "Safe FPS" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_ON_MASK, 0x00003F00 , "Number of frames below threshold before turning WAR on" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_ON_SHIFT, 8 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_OFF_MASK, 0x000FC000 , "Number of frames above threshold before turning WAR off" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_FILTER_OFF_SHIFT, 14 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_THRESHOLD_US_MASK, 0xFFF00000 , "Render time threshold in microseconds" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_THRESHOLD_US_SHIFT, 20 , "" },
    { (const char **)g_ppszDefineDataNames_PS_FRL_LOADING_WAR_DEFAULT_SETTING, 0xBB814A3C , "Current default setting" },
};

DataDefaultDWORD g_aDefaultData_PS_FRL_LOADING_WAR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_FRL_LOADING_WAR(
    0x10834f04,
    g_pszKeyName_PS_FRL_LOADING_WAR,
    g_pszRemappedName_PS_FRL_LOADING_WAR,
    g_pszMainDocs_PS_FRL_LOADING_WAR,
    g_pszDefinedWhen_PS_FRL_LOADING_WAR,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_FRL_LOADING_WAR, 
    9, 
    g_aDefaultData_PS_FRL_LOADING_WAR, 
    1 
);

static const char *g_pszKeyName_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT = "PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT";
static const char *g_pszDefinedWhen_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT = "D3D_0xce2348";
static const char *g_pszMainDocs_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT = "This regkey is to set NV_PGRAPH_PRI_GPC0_SWDX_TC_TIMEOUT";

DataDefaultDWORD g_aDefaultData_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT[] =
{
    {"DEFAULT", 0x10000, "" }, 
};

SettingDWORD g_setting_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT(
    0x10ce2238,
    g_pszKeyName_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT,
    g_pszRemappedName_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT,
    g_pszMainDocs_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT,
    g_pszDefinedWhen_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT, 
    1 
);

static const char *g_pszKeyName_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING = "PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING";
static const char *g_pszDefinedWhen_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING = "D3D_fa35cc4";
static const char *g_pszMainDocs_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING = "When present, sets the value of NV_PGRAPH_PRI_GPCS_SWDX_CONFIG:_TILED_CACHING. Note PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ENABLE=0.";

static const char * (g_ppszDefineDataNames_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING[] =
{
    { (const char **)g_ppszDefineDataNames_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_OFF, 0x1 , "OFF" },
    { (const char **)g_ppszDefineDataNames_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ON, 0x0 , "ON" },
};

DataDefaultDWORD g_aDefaultData_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING(
    0x10a35cc4,
    g_pszKeyName_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING,
    g_pszRemappedName_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING,
    g_pszMainDocs_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING,
    g_pszDefinedWhen_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING, 
    2, 
    g_aDefaultData_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER = "PS_PGO_PIECEMEAL_PROFILER";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER = "D3D_554c9a13";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER = "Controls piecemeal profiling (dx11 and dx12)";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_OFF, 0xa2b53761 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_ON, 0x79292610 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER[] =
{
    {"DEFAULT", 0xa2b53761, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER(
    0x105d7198,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE = "PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE = "D3DOGL_c0946a81";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE = "The number of points in the search space that we should profile at once";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MIN, 1 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MAX, 32 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE(
    0x10000009,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE = "PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE = "D3DOGL_00861b73";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE = "The number of words of system memory for storing counters.";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MIN, 64 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MAX, 1073741824 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE[] =
{
    {"DEFAULT", 0x100, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE(
    0x1049ce34,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_EPOCH = "PS_PGO_PIECEMEAL_PROFILER_EPOCH";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_EPOCH = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_EPOCH = "D3DOGL_c0946a01";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_EPOCH = "The starting point in the search space that we should profile";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_EPOCH_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_EPOCH_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_EPOCH[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_EPOCH_MIN, 1 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_EPOCH_MAX, 32 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_EPOCH[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_EPOCH(
    0x100f913a,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_EPOCH,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_EPOCH,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_EPOCH,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_EPOCH,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_EPOCH, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_EPOCH, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FLAGS = "PS_PGO_PIECEMEAL_PROFILER_FLAGS";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FLAGS = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FLAGS = "D3D_34deabc0";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_ALL)[] =
{
    "ENABLE_FOR_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_PS)[] =
{
    "ENABLE_FOR_PS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_CS)[] =
{
    "ENABLE_FOR_CS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_TURING_AND_ABOVE)[] =
{
    "TURING_AND_ABOVE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_AMPERE_AND_ABOVE)[] =
{
    "AMPERE_AND_ABOVE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX11_ONLY)[] =
{
    "DX11_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX12_ONLY)[] =
{
    "DX12_ONLY",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_ALL, 0x00000000 , "enable for all, no filters as below" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_PS, 0x00000001 , "enable only for pixel shaders" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_CS, 0x00000002 , "enable only for compute shaders" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_TURING_AND_ABOVE, 0x00000004 , "enable for TU+" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_AMPERE_AND_ABOVE, 0x00000008 , "enable for GA+" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX11_ONLY, 0x00000010 , "enable for DX12 Only" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX12_ONLY, 0x00000020 , "enable for DX12 Only" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FLAGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_FLAGS(
    0x1018a4c7,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FLAGS,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FLAGS,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FLAGS,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_FLAGS, 
    7, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FLAGS, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH = "PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH = "D3DOGL_00861a82";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH = "Whether we should focus on a particular shader with D3D10 hash";

DataDefaultQWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingQWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH(
    0x1049ff34,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING = "PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING = "D3D_b5f01a82";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING = "Specifies a space-delimited list of hashes for applying PGO instrumentation. The hash must be in 0x12345678 form";

DataDefaultSTRING g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING(
    0x10049f4b,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_PRESET = "PS_PGO_PIECEMEAL_PROFILER_PRESET";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_PRESET = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_PRESET = "D3D_34dca8c0";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_PRESET = "";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_HIGH)[] =
{
    "VERY_HIGH",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_MEDIUM)[] =
{
    "MEDIUM",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_LOW)[] =
{
    "LOW",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_LOW)[] =
{
    "VERY_LOW",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_PRESET[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_NONE, 0x00000000 , "No Presets, use individual regkeys" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_HIGH, 0x00000001 , "Instrument 100 percent of shaders and blocks" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_MEDIUM, 0x00000002 , "Instrument 50 percent of shaders and blocks" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_LOW, 0x00000004 , "Instrument 25 percent of shaders and blocks" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_LOW, 0x00000014 , "Instrument 5 percent of shaders and blocks" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_PRESET[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_PRESET(
    0x1019a4c6,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_PRESET,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_PRESET,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_PRESET,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_PRESET,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_PRESET, 
    5, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_PRESET, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND = "PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND = "D3D_34deabc1";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND = "";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_ZEROPLOIT)[] =
{
    "ZEROPLOIT",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_DISABLED, 0x00000000 , "Profiling is disabled" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_ZEROPLOIT, 0x00000001 , "Enable Zeroploit instrumentation" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND(
    0x10a2a7c6,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ = "PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ = "D3DOGL_c0457aab";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ = "The probability of sampling any given draw call.";

DataDefaultFLOAT g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ[] =
{
    {"DEFAULT", 0.0f, "" }, 
};

SettingFLOAT g_setting_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ(
    0x1000000f,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ, 
    1 
);

static const char *g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE = "PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE";
static const char *g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE = "1";
static const char *g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE = "D3DOGL_c0e4fb91";
static const char *g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE = "The number of words of video memory for storing counters.";

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MIN, 64 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MAX, 1073741824 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE[] =
{
    {"DEFAULT", 0x100, "" }, 
};

SettingDWORD g_setting_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE(
    0x1000000e,
    g_pszKeyName_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE,
    g_pszRemappedName_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE,
    g_pszMainDocs_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE,
    g_pszDefinedWhen_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE, 
    2, 
    g_aDefaultData_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE, 
    1 
);

static const char *g_pszKeyName_PS_PIXEL_SHADER_STATS_FLAGS = "PS_PIXEL_SHADER_STATS_FLAGS";
static const char *g_pszDefinedWhen_PS_PIXEL_SHADER_STATS_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_PIXEL_SHADER_STATS_FLAGS = "D3D_27815290";
static const char *g_pszMainDocs_PS_PIXEL_SHADER_STATS_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_TSS)[] =
{
    "DUMP_NON_HAND_TUNED_TSS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_TSS)[] =
{
    "DUMP_HAND_TUNED_TSS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_REAL)[] =
{
    "DUMP_NON_HAND_TUNED_REAL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_REAL)[] =
{
    "DUMP_HAND_TUNED_REAL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NVINST)[] =
{
    "DUMP_NVINST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_CONST_HISTOGRAMS)[] =
{
    "DUMP_CONST_HISTOGRAMS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME)[] =
{
    "DUMP_SHADER_MEASURE_TIME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED)[] =
{
    "DUMP_SHADER_MEASURE_SPEED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS)[] =
{
    "DUMP_SHADER_MEASURE_STALLS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER)[] =
{
    "DUMP_SHADER_MEASURE_PCSAMPLER",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME_RUNTIME)[] =
{
    "DUMP_SHADER_COMPILE_TIME_RUNTIME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME)[] =
{
    "DUMP_SHADER_COMPILE_TIME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_RAW_COMBINERS)[] =
{
    "DUMP_RAW_COMBINERS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_TEXTURE_STAGE_INFO)[] =
{
    "DUMP_TEXTURE_STAGE_INFO",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_API_BYTECODE)[] =
{
    "DUMP_SHADER_API_BYTECODE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_USAGE_MAP)[] =
{
    "DUMP_SHADER_USAGE_MAP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SURFACE_AND_STATE_INFO)[] =
{
    "DUMP_SURFACE_AND_STATE_INFO",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS)[] =
{
    "DUMP_ZERO_USAGE_SHADERS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_FLAGS)[] =
{
    "DUMP_FLAGS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_DSR_SHADERS)[] =
{
    "DUMP_DSR_SHADERS",
    NULL
};

DataValueDWORD g_aDefineData_PS_PIXEL_SHADER_STATS_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_TSS, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_TSS, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_REAL, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_REAL, 0x00000008 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NVINST, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_CONST_HISTOGRAMS, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER, 0x00080000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME_RUNTIME, 0x00100000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME, 0x00200000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_RAW_COMBINERS, 0x01000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_TEXTURE_STAGE_INFO, 0x02000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_API_BYTECODE, 0x04000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_USAGE_MAP, 0x08000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SURFACE_AND_STATE_INFO, 0x10000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS, 0x20000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_FLAGS, 0x40000000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_PIXEL_SHADER_STATS_FLAGS_DUMP_DSR_SHADERS, 0x80000000 , "" },
};

DataDefaultDWORD g_aDefaultData_PS_PIXEL_SHADER_STATS_FLAGS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_PS_PIXEL_SHADER_STATS_FLAGS(
    0x10e1e86b,
    g_pszKeyName_PS_PIXEL_SHADER_STATS_FLAGS,
    g_pszRemappedName_PS_PIXEL_SHADER_STATS_FLAGS,
    g_pszMainDocs_PS_PIXEL_SHADER_STATS_FLAGS,
    g_pszDefinedWhen_PS_PIXEL_SHADER_STATS_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_PIXEL_SHADER_STATS_FLAGS, 
    20, 
    g_aDefaultData_PS_PIXEL_SHADER_STATS_FLAGS, 
    1 
);

static const char *g_pszKeyName_PS_PUSHBUFFER_DUMP_END_FRAME = "PS_PUSHBUFFER_DUMP_END_FRAME";
static const char *g_pszDefinedWhen_PS_PUSHBUFFER_DUMP_END_FRAME = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_PUSHBUFFER_DUMP_END_FRAME = "D3D_97e6275669";
static const char *g_pszMainDocs_PS_PUSHBUFFER_DUMP_END_FRAME = "Ending frame to write out pushbuffer dump, inclusive";

SettingDWORD g_setting_PS_PUSHBUFFER_DUMP_END_FRAME(
    0x10e68559,
    g_pszKeyName_PS_PUSHBUFFER_DUMP_END_FRAME,
    g_pszRemappedName_PS_PUSHBUFFER_DUMP_END_FRAME,
    g_pszMainDocs_PS_PUSHBUFFER_DUMP_END_FRAME,
    g_pszDefinedWhen_PS_PUSHBUFFER_DUMP_END_FRAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_PUSHBUFFER_DUMP_START_FRAME = "PS_PUSHBUFFER_DUMP_START_FRAME";
static const char *g_pszDefinedWhen_PS_PUSHBUFFER_DUMP_START_FRAME = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_PUSHBUFFER_DUMP_START_FRAME = "D3D_97e6275668";
static const char *g_pszMainDocs_PS_PUSHBUFFER_DUMP_START_FRAME = "Starting frame to write out pushbuffer dump, inclusive";

SettingDWORD g_setting_PS_PUSHBUFFER_DUMP_START_FRAME(
    0x10e68558,
    g_pszKeyName_PS_PUSHBUFFER_DUMP_START_FRAME,
    g_pszRemappedName_PS_PUSHBUFFER_DUMP_START_FRAME,
    g_pszMainDocs_PS_PUSHBUFFER_DUMP_START_FRAME,
    g_pszDefinedWhen_PS_PUSHBUFFER_DUMP_START_FRAME,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_REDUCTION_HACK_HASH_LIST = "PS_REDUCTION_HACK_HASH_LIST";
static const char *g_pszDefinedWhen_PS_REDUCTION_HACK_HASH_LIST = "1";
static const char *g_pszRemappedName_PS_REDUCTION_HACK_HASH_LIST = "D3DOGL_fa5840";
static const char *g_pszMainDocs_PS_REDUCTION_HACK_HASH_LIST = "String for passing list of appHashes to turn reduction hack on for. '0x' 'delimited' eg: '0xbadcf00d0xdeadbeef'";

DataDefaultSTRING g_aDefaultData_PS_REDUCTION_HACK_HASH_LIST[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_PS_REDUCTION_HACK_HASH_LIST(
    0x10fa5840,
    g_pszKeyName_PS_REDUCTION_HACK_HASH_LIST,
    g_pszRemappedName_PS_REDUCTION_HACK_HASH_LIST,
    g_pszMainDocs_PS_REDUCTION_HACK_HASH_LIST,
    g_pszDefinedWhen_PS_REDUCTION_HACK_HASH_LIST,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_REDUCTION_HACK_HASH_LIST, 
    1 
);

static const char *g_pszKeyName_PS_REDUCTION_KNOBS_LIST = "PS_REDUCTION_KNOBS_LIST";
static const char *g_pszDefinedWhen_PS_REDUCTION_KNOBS_LIST = "1";
static const char *g_pszRemappedName_PS_REDUCTION_KNOBS_LIST = "D3DOGL_fa6640";
static const char *g_pszMainDocs_PS_REDUCTION_KNOBS_LIST = "String for passing a list of per-shaderHash entries to control knobs related to reduction. ':' delimits each value, ';' delimits each entry. The entry format is 'ShaderHash:warpsPerSubtile:applyReductionHack:schedMaxRTarget;', with no space inbetween entries. All values must be 0x formatted hexadecimal e.g. 0x195f7f6c093b396b:0x8:0x1:0x0;0x2fa5375360b0cf54:0x8:0x1:0x0; (see NvShaderSpecificReduction12 for more details)";

DataDefaultSTRING g_aDefaultData_PS_REDUCTION_KNOBS_LIST[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_PS_REDUCTION_KNOBS_LIST(
    0x10fa6640,
    g_pszKeyName_PS_REDUCTION_KNOBS_LIST,
    g_pszRemappedName_PS_REDUCTION_KNOBS_LIST,
    g_pszMainDocs_PS_REDUCTION_KNOBS_LIST,
    g_pszDefinedWhen_PS_REDUCTION_KNOBS_LIST,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_PS_REDUCTION_KNOBS_LIST, 
    1 
);

static const char *g_pszKeyName_PS_REFLEX_INDICATOR = "PS_REFLEX_INDICATOR";
static const char *g_pszDefinedWhen_PS_REFLEX_INDICATOR = "1";
static const char *g_pszRemappedName_PS_REFLEX_INDICATOR = "D3DOGL_A0008604";
static const char *g_pszMainDocs_PS_REFLEX_INDICATOR = "Enable a visual onscreen indicator for reflex metrics";

static const char * (g_ppszDefineDataNames_PS_REFLEX_INDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_REFLEX_INDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_REFLEX_INDICATOR_CODE_COVERAGE)[] =
{
    "CODE_COVERAGE",
    NULL
};

DataValueDWORD g_aDefineData_PS_REFLEX_INDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_PS_REFLEX_INDICATOR_OFF, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_PS_REFLEX_INDICATOR_ON, 0x00000001 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_PS_REFLEX_INDICATOR_CODE_COVERAGE, 0x00000003 , "Code coverage testing for ReflexMetrics" },
};

DataDefaultDWORD g_aDefaultData_PS_REFLEX_INDICATOR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_PS_REFLEX_INDICATOR(
    0x10834f18,
    g_pszKeyName_PS_REFLEX_INDICATOR,
    g_pszRemappedName_PS_REFLEX_INDICATOR,
    g_pszMainDocs_PS_REFLEX_INDICATOR,
    g_pszDefinedWhen_PS_REFLEX_INDICATOR,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_REFLEX_INDICATOR, 
    3, 
    g_aDefaultData_PS_REFLEX_INDICATOR, 
    1 
);

static const char *g_pszKeyName_PS_VERTEX_SHADER_STATS_FLAGS = "PS_VERTEX_SHADER_STATS_FLAGS";
static const char *g_pszDefinedWhen_PS_VERTEX_SHADER_STATS_FLAGS = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_VERTEX_SHADER_STATS_FLAGS = "D3D_487074847";
static const char *g_pszMainDocs_PS_VERTEX_SHADER_STATS_FLAGS = "";

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED)[] =
{
    "DUMP_NON_HAND_TUNED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_HAND_TUNED)[] =
{
    "DUMP_HAND_TUNED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_VSFP)[] =
{
    "DUMP_VSFP",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_DECL)[] =
{
    "DUMP_DECL",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SYSTEM)[] =
{
    "DUMP_SYSTEM",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NVINST)[] =
{
    "DUMP_NVINST",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SOURCE_TOKENS)[] =
{
    "DUMP_SOURCE_TOKENS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS)[] =
{
    "DUMP_ZERO_USAGE_SHADERS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADERS_AT_CREATE)[] =
{
    "DUMP_SHADERS_AT_CREATE",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME)[] =
{
    "DUMP_SHADER_MEASURE_TIME",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED)[] =
{
    "DUMP_SHADER_MEASURE_SPEED",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS)[] =
{
    "DUMP_SHADER_MEASURE_STALLS",
    NULL
};

static const char * (g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER)[] =
{
    "DUMP_SHADER_MEASURE_PCSAMPLER",
    NULL
};

DataValueDWORD g_aDefineData_PS_VERTEX_SHADER_STATS_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED, 0x00000001 , "Dumps non hand tuned vertex shaders" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_HAND_TUNED, 0x00000002 , "Dumps hand tuned vertex shaders" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_VSFP, 0x00000004 , "Dumps the vertex shaders that are generated by vertex shader fixed pipe. Unlike the other dump types, the output shaders cannot be used as hand-tuned shaders due to the different input/output mapping. Therefore this dump is for informational purposes only. VSFP shaders are indicated in the dump by the labels BEGIN/END VSFP SHADER." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_DECL, 0x00000008 , "Dumps all the DECLS that were created." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SYSTEM, 0x00000010 , "Dumps information for passthrough vertex shaders." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NVINST, 0x00000020 , "Dumps nvInst & COP args for the shader" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SOURCE_TOKENS, 0x00000080 , "Dumps the D3D code token DWORDs." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS, 0x00000100 , "By default, vertex shaders that were created by the app but not used are not dumped by the flags above. If you set this key, zero usage shaders are dumped." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADERS_AT_CREATE, 0x00001000 , "Dumps the vertex shaders at the time of their creation, when a new GPU program is added. It overrides DUMP_ZERO_USAGE_SHADERS, as at creation time, there is no information about their usage. It can be useful for applications that do not explicitly destroy the allocated shaders, and consequently would not dump their content at deletion." },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME, 0x00010000 , "Measure Vertex shader execution time" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS, 0x00040000 , "" },
    { (const char **)g_ppszDefineDataNames_PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER, 0x00080000 , "" },
};

SettingDWORD g_setting_PS_VERTEX_SHADER_STATS_FLAGS(
    0x10ed52e4,
    g_pszKeyName_PS_VERTEX_SHADER_STATS_FLAGS,
    g_pszRemappedName_PS_VERTEX_SHADER_STATS_FLAGS,
    g_pszMainDocs_PS_VERTEX_SHADER_STATS_FLAGS,
    g_pszDefinedWhen_PS_VERTEX_SHADER_STATS_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_PS_VERTEX_SHADER_STATS_FLAGS, 
    13, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_ZBC_COLOR_VALUES = "PS_ZBC_COLOR_VALUES";
static const char *g_pszDefinedWhen_PS_ZBC_COLOR_VALUES = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_ZBC_COLOR_VALUES = "D3DOGL_10F2565";
static const char *g_pszMainDocs_PS_ZBC_COLOR_VALUES = "A comma- or space-separated list of '(format,r,g,b,a)' strings specifying values to add to the ZBC table - e.g. '(4, 0x123, 0x456, 256, 100000), (4, 0 0xFFFF00FF 0 1)'.  The r,g,b,a values are 32-bit integers specifying the DS clear values.  Matching FB clear values will be computed by the driver.  For floating-point and normalized formats, these should be the raw bit encoding of a floating-point clear value - e.g., 0x3F800000 for 1.0.  To specify raw FB values for PLC compression, use 4 to specify RF32_GF32_BF32_AF32 format. (See NV9096_CTRL_CMD_SET_ZBC_COLOR_CLEAR RM call for more details)";

SettingSTRING g_setting_PS_ZBC_COLOR_VALUES(
    0x100f2565,
    g_pszKeyName_PS_ZBC_COLOR_VALUES,
    g_pszRemappedName_PS_ZBC_COLOR_VALUES,
    g_pszMainDocs_PS_ZBC_COLOR_VALUES,
    g_pszDefinedWhen_PS_ZBC_COLOR_VALUES,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_ZBC_DEPTH_VALUES = "PS_ZBC_DEPTH_VALUES";
static const char *g_pszDefinedWhen_PS_ZBC_DEPTH_VALUES = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_ZBC_DEPTH_VALUES = "D3DOGL_10F2566";
static const char *g_pszMainDocs_PS_ZBC_DEPTH_VALUES = "A comma- or space-separated list of strings specifying depth values to add to the ZBC table - e.g. '0x3f000000, 0x3e800000'. The values are 32-bit integers specifying the DS and FB clear values. F32 floating-point format is used for depth values, specified as the raw bit encoding of a floating-point clear value - e.g., 0x3F800000 for 1.0. (See NV9096_CTRL_CMD_SET_ZBC_DEPTH_CLEAR RM call for more details)";

SettingSTRING g_setting_PS_ZBC_DEPTH_VALUES(
    0x100f2566,
    g_pszKeyName_PS_ZBC_DEPTH_VALUES,
    g_pszRemappedName_PS_ZBC_DEPTH_VALUES,
    g_pszMainDocs_PS_ZBC_DEPTH_VALUES,
    g_pszDefinedWhen_PS_ZBC_DEPTH_VALUES,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_PS_ZBC_STENCIL_VALUES = "PS_ZBC_STENCIL_VALUES";
static const char *g_pszDefinedWhen_PS_ZBC_STENCIL_VALUES = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_PS_ZBC_STENCIL_VALUES = "D3DOGL_10F2567";
static const char *g_pszMainDocs_PS_ZBC_STENCIL_VALUES = "A comma- or space-separated list of strings specifying stencil values to add to the ZBC table - e.g. '0xF1, 35, 0x15'. The values are 8-bit integers specifying the DS and FB clear values. (See NV9096_CTRL_CMD_SET_ZBC_STENCIL_CLEAR RM call for more details)";

SettingSTRING g_setting_PS_ZBC_STENCIL_VALUES(
    0x100f2567,
    g_pszKeyName_PS_ZBC_STENCIL_VALUES,
    g_pszRemappedName_PS_ZBC_STENCIL_VALUES,
    g_pszMainDocs_PS_ZBC_STENCIL_VALUES,
    g_pszDefinedWhen_PS_ZBC_STENCIL_VALUES,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    NULL,
    0 // No values
);

static const char *g_pszKeyName_QMD_OCC_MAX_ASYNC = "QMD_OCC_MAX_ASYNC";
static const char *g_pszDefinedWhen_QMD_OCC_MAX_ASYNC = "1";
static const char *g_pszRemappedName_QMD_OCC_MAX_ASYNC = "D3DOGL_0x1e1070";
static const char *g_pszMainDocs_QMD_OCC_MAX_ASYNC = "Set Occupancy fields in the QMD to program the High Occupancy Watermark for resources specific to async queue dispatches. GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link. Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB). Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_MAX_ASYNC[] =
{
    {"DEFAULT", 0xFFFFFF, "" }, 
};

SettingDWORD g_setting_QMD_OCC_MAX_ASYNC(
    0x101e1070,
    g_pszKeyName_QMD_OCC_MAX_ASYNC,
    g_pszRemappedName_QMD_OCC_MAX_ASYNC,
    g_pszMainDocs_QMD_OCC_MAX_ASYNC,
    g_pszDefinedWhen_QMD_OCC_MAX_ASYNC,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_MAX_ASYNC, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_MAX_NON_RT = "QMD_OCC_MAX_NON_RT";
static const char *g_pszDefinedWhen_QMD_OCC_MAX_NON_RT = "1";
static const char *g_pszRemappedName_QMD_OCC_MAX_NON_RT = "D3DOGL_0x1c1045";
static const char *g_pszMainDocs_QMD_OCC_MAX_NON_RT = "Set Occupancy fields in the QMD to program the High Occupancy Watermark for resources.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW. Overrides default regkeys set for sync/async compute work";

DataDefaultDWORD g_aDefaultData_QMD_OCC_MAX_NON_RT[] =
{
    {"DEFAULT", 0xFFFFFF, "" }, 
};

SettingDWORD g_setting_QMD_OCC_MAX_NON_RT(
    0x101c1045,
    g_pszKeyName_QMD_OCC_MAX_NON_RT,
    g_pszRemappedName_QMD_OCC_MAX_NON_RT,
    g_pszMainDocs_QMD_OCC_MAX_NON_RT,
    g_pszDefinedWhen_QMD_OCC_MAX_NON_RT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_MAX_NON_RT, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_MAX_RT = "QMD_OCC_MAX_RT";
static const char *g_pszDefinedWhen_QMD_OCC_MAX_RT = "1";
static const char *g_pszRemappedName_QMD_OCC_MAX_RT = "D3DOGL_0x1e1045";
static const char *g_pszMainDocs_QMD_OCC_MAX_RT = "Set Occupancy fields in the QMD to program the High Occupancy Watermark for resources for Ray Tracing specific submissions.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW. Overrides default regkeys set for sync/async compute work";

DataDefaultDWORD g_aDefaultData_QMD_OCC_MAX_RT[] =
{
    {"DEFAULT", 0xFFFFFF, "" }, 
};

SettingDWORD g_setting_QMD_OCC_MAX_RT(
    0x101e1045,
    g_pszKeyName_QMD_OCC_MAX_RT,
    g_pszRemappedName_QMD_OCC_MAX_RT,
    g_pszMainDocs_QMD_OCC_MAX_RT,
    g_pszDefinedWhen_QMD_OCC_MAX_RT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_MAX_RT, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_MAX_SYNC = "QMD_OCC_MAX_SYNC";
static const char *g_pszDefinedWhen_QMD_OCC_MAX_SYNC = "1";
static const char *g_pszRemappedName_QMD_OCC_MAX_SYNC = "D3DOGL_0x1e106e";
static const char *g_pszMainDocs_QMD_OCC_MAX_SYNC = "Set Occupancy fields in the QMD to program the High Occupancy Watermark for resources specific to sync queue dispatches.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_MAX_SYNC[] =
{
    {"DEFAULT", 0xFFFFFF, "" }, 
};

SettingDWORD g_setting_QMD_OCC_MAX_SYNC(
    0x101e106e,
    g_pszKeyName_QMD_OCC_MAX_SYNC,
    g_pszRemappedName_QMD_OCC_MAX_SYNC,
    g_pszMainDocs_QMD_OCC_MAX_SYNC,
    g_pszDefinedWhen_QMD_OCC_MAX_SYNC,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_MAX_SYNC, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC = "QMD_OCC_THRESHOLD_ASYNC";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC = "D3DOGL_0x1e1069";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for each resource specific to async queue dispatches (VEID>0).  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC[] =
{
    {"DEFAULT", 0x104000, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_ASYNC(
    0x101e1069,
    g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC,
    g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC,
    g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL = "QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL = "D3DOGL_0x1e106b";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for resources specific to async queue BVH build dispatches.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL[] =
{
    {"DEFAULT", 0x104000, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL(
    0x101e106b,
    g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL,
    g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL,
    g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH = "QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH = "D3DOGL_0x1e106d";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for resources specific to async queue RT (non-BVH) dispatches.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH[] =
{
    {"DEFAULT", 0x104000, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH(
    0x101e106d,
    g_pszKeyName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH,
    g_pszRemappedName_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH,
    g_pszMainDocs_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_NON_RT = "QMD_OCC_THRESHOLD_NON_RT";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_NON_RT = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_NON_RT = "D3DOGL_0x1b1045";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_NON_RT = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for each resource.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW. Overrides default regkeys set for sync/async compute work";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_NON_RT[] =
{
    {"DEFAULT", 0xF0F00, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_NON_RT(
    0x101b1045,
    g_pszKeyName_QMD_OCC_THRESHOLD_NON_RT,
    g_pszRemappedName_QMD_OCC_THRESHOLD_NON_RT,
    g_pszMainDocs_QMD_OCC_THRESHOLD_NON_RT,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_NON_RT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_NON_RT, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_RT = "QMD_OCC_THRESHOLD_RT";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_RT = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_RT = "D3DOGL_0x1d1045";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_RT = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for resources for Ray Tracing specific submissions.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW. Overrides default regkeys set for sync/async compute work";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_RT[] =
{
    {"DEFAULT", 0xF0F00, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_RT(
    0x101d1045,
    g_pszKeyName_QMD_OCC_THRESHOLD_RT,
    g_pszRemappedName_QMD_OCC_THRESHOLD_RT,
    g_pszMainDocs_QMD_OCC_THRESHOLD_RT,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_RT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_RT, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_SYNC = "QMD_OCC_THRESHOLD_SYNC";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC = "D3DOGL_0x1e1068";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for each resource specific to sync queue dispatches (VEID==0).  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_SYNC[] =
{
    {"DEFAULT", 0x104000, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_SYNC(
    0x101e1068,
    g_pszKeyName_QMD_OCC_THRESHOLD_SYNC,
    g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC,
    g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_SYNC, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL = "QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL = "D3DOGL_0x1e106a";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for resources specific to sync queue BVH build dispatches.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL[] =
{
    {"DEFAULT", 0x040400, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL(
    0x101e106a,
    g_pszKeyName_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL,
    g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL,
    g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL, 
    1 
);

static const char *g_pszKeyName_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH = "QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH";
static const char *g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH = "1";
static const char *g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH = "D3DOGL_0x1e106c";
static const char *g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH = "Set Occupancy fields in the QMD to program the Low Occupancy Watermark for resources specific to sync queue RT (non-BVH) dispatches.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.  Regkey has 8 bits each for warp threshold, RF threshold, and ShM threshold respectively (ShM being the LSB).  Clamped to 128 by HW";

DataDefaultDWORD g_aDefaultData_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH[] =
{
    {"DEFAULT", 0x104000, "" }, 
};

SettingDWORD g_setting_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH(
    0x101e106c,
    g_pszKeyName_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH,
    g_pszRemappedName_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH,
    g_pszMainDocs_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH,
    g_pszDefinedWhen_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH, 
    1 
);

static const char *g_pszKeyName_QUIET_MODE = "QUIET_MODE";
static const char *g_pszDefinedWhen_QUIET_MODE = "1";
static const char *g_pszRemappedName_QUIET_MODE = "D3DOGL_f1846871";
static const char *g_pszMainDocs_QUIET_MODE = "Enables the Whisper Mode functionality, cap FPS for AC mode only";

static const char * (g_ppszDefineDataNames_QUIET_MODE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_ENABLED)[] =
{
    "ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_XQM)[] =
{
    "XQM",
    NULL
};

DataValueDWORD g_aDefineData_QUIET_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_MAX, 0x000003ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_ENABLED, 0x10000000 , "Enabled" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_DISABLED, 0x00000000 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_XQM, 0x10000028 , "External Quiet Mode Setting" },
};

DataDefaultDWORD g_aDefaultData_QUIET_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_QUIET_MODE(
    0x10115c8a,
    g_pszKeyName_QUIET_MODE,
    g_pszRemappedName_QUIET_MODE,
    g_pszMainDocs_QUIET_MODE,
    g_pszDefinedWhen_QUIET_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_QUIET_MODE, 
    5, 
    g_aDefaultData_QUIET_MODE, 
    1 
);

static const char *g_pszKeyName_QUIET_MODE_APP_FPS = "QUIET_MODE_APP_FPS";
static const char *g_pszDefinedWhen_QUIET_MODE_APP_FPS = "1";
static const char *g_pszRemappedName_QUIET_MODE_APP_FPS = "D3DOGL_f1846872";
static const char *g_pszMainDocs_QUIET_MODE_APP_FPS = "Override FPS for Whisper Mode, can be set differently for each application";

static const char * (g_ppszDefineDataNames_QUIET_MODE_APP_FPS_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_APP_FPS_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_QUIET_MODE_APP_FPS_NO_OVERRIDE)[] =
{
    "NO_OVERRIDE",
    NULL
};

DataValueDWORD g_aDefineData_QUIET_MODE_APP_FPS[] =
{
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_APP_FPS_MIN, 0x00000001 , "Minimum" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_APP_FPS_MAX, 0x000003ff , "Maximum" },
    { (const char **)g_ppszDefineDataNames_QUIET_MODE_APP_FPS_NO_OVERRIDE, 0x00000000 , "No override" },
};

DataDefaultDWORD g_aDefaultData_QUIET_MODE_APP_FPS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_QUIET_MODE_APP_FPS(
    0x10115c8b,
    g_pszKeyName_QUIET_MODE_APP_FPS,
    g_pszRemappedName_QUIET_MODE_APP_FPS,
    g_pszMainDocs_QUIET_MODE_APP_FPS,
    g_pszDefinedWhen_QUIET_MODE_APP_FPS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_QUIET_MODE_APP_FPS, 
    3, 
    g_aDefaultData_QUIET_MODE_APP_FPS, 
    1 
);

static const char *g_pszKeyName_REFLEX_TEST_MODE = "REFLEX_TEST_MODE";
static const char *g_pszDefinedWhen_REFLEX_TEST_MODE = "1";
static const char *g_pszRemappedName_REFLEX_TEST_MODE = "D3DOGL_A0008605";
static const char *g_pszMainDocs_REFLEX_TEST_MODE = "Enable Reflex test mode";

static const char * (g_ppszDefineDataNames_REFLEX_TEST_MODE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_REFLEX_TEST_MODE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_REFLEX_TEST_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_REFLEX_TEST_MODE_OFF, 0 , "Disabled" },
    { (const char **)g_ppszDefineDataNames_REFLEX_TEST_MODE_ON, 1 , "Enabled" },
};

DataDefaultDWORD g_aDefaultData_REFLEX_TEST_MODE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_REFLEX_TEST_MODE(
    0x10834f19,
    g_pszKeyName_REFLEX_TEST_MODE,
    g_pszRemappedName_REFLEX_TEST_MODE,
    g_pszMainDocs_REFLEX_TEST_MODE,
    g_pszDefinedWhen_REFLEX_TEST_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_REFLEX_TEST_MODE, 
    2, 
    g_aDefaultData_REFLEX_TEST_MODE, 
    1 
);

static const char *g_pszKeyName_ROOT_TABLE_PREFETCH = "ROOT_TABLE_PREFETCH";
static const char *g_pszDefinedWhen_ROOT_TABLE_PREFETCH = "1";
static const char *g_pszRemappedName_ROOT_TABLE_PREFETCH = "D3DOGL_0x191043";
static const char *g_pszMainDocs_ROOT_TABLE_PREFETCH = "Set values for GA10x+ Root Table prefetch feature. See http://nvbugs/2498256.  Note Vertex (bit 1) and Pixel (bit 5) are the only stages implemented on GA10x";

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_VERTEX_CULL_BEFORE_FETCH)[] =
{
    "VERTEX_CULL_BEFORE_FETCH",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_VERTEX)[] =
{
    "VERTEX",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_TESSELLATION_INIT)[] =
{
    "TESSELLATION_INIT",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_TESSELLATION)[] =
{
    "TESSELLATION",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_GEOMETRY)[] =
{
    "GEOMETRY",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_PIXEL)[] =
{
    "PIXEL",
    NULL
};

static const char * (g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_ENABLE_ALL)[] =
{
    "ENABLE_ALL",
    NULL
};

DataValueDWORD g_aDefineData_ROOT_TABLE_PREFETCH[] =
{
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_OFF, 0x00000000 , "Disable for all stages" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_VERTEX_CULL_BEFORE_FETCH, 0x00000001 , "Prefetch root tables for VERTEX_CULL_BEFORE_FETCH stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_VERTEX, 0x00000002 , "Prefetch root tables for VERTEX stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_TESSELLATION_INIT, 0x00000004 , "Prefetch root tables for TESSELLATION_INIT stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_TESSELLATION, 0x00000008 , "Prefetch root tables for TESSELLATION stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_GEOMETRY, 0x00000010 , "Prefetch root tables for GEOMETRY stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_PIXEL, 0x00000020 , "Prefetch root tables for PIXEL stage" },
    { (const char **)g_ppszDefineDataNames_ROOT_TABLE_PREFETCH_ENABLE_ALL, 0x0000003f , "Enable for all stages" },
};

DataDefaultDWORD g_aDefaultData_ROOT_TABLE_PREFETCH[] =
{
    {"DEFAULT", 0x0000003f, "" }, 
};

SettingDWORD g_setting_ROOT_TABLE_PREFETCH(
    0x10191043,
    g_pszKeyName_ROOT_TABLE_PREFETCH,
    g_pszRemappedName_ROOT_TABLE_PREFETCH,
    g_pszMainDocs_ROOT_TABLE_PREFETCH,
    g_pszDefinedWhen_ROOT_TABLE_PREFETCH,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ROOT_TABLE_PREFETCH, 
    8, 
    g_aDefaultData_ROOT_TABLE_PREFETCH, 
    1 
);

static const char *g_pszKeyName_RTCORE_BVH_DUMP_HOTKEY = "RTCORE_BVH_DUMP_HOTKEY";
static const char *g_pszDefinedWhen_RTCORE_BVH_DUMP_HOTKEY = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_BVH_DUMP_HOTKEY = "D3D_0x6136c3";
static const char *g_pszMainDocs_RTCORE_BVH_DUMP_HOTKEY = "Set custom key for BVH bin data dump. Also need to set RTCORE_BVH_DUMP_MODE to HOTKEY. (default is ctrl+home)";

DataDefaultDWORD g_aDefaultData_RTCORE_BVH_DUMP_HOTKEY[] =
{
    {"DEFAULT", 0x24, "" }, 
};

SettingDWORD g_setting_RTCORE_BVH_DUMP_HOTKEY(
    0x106136c3,
    g_pszKeyName_RTCORE_BVH_DUMP_HOTKEY,
    g_pszRemappedName_RTCORE_BVH_DUMP_HOTKEY,
    g_pszMainDocs_RTCORE_BVH_DUMP_HOTKEY,
    g_pszDefinedWhen_RTCORE_BVH_DUMP_HOTKEY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_BVH_DUMP_HOTKEY, 
    1 
);

static const char *g_pszKeyName_RTCORE_BVH_DUMP_MODE = "RTCORE_BVH_DUMP_MODE";
static const char *g_pszDefinedWhen_RTCORE_BVH_DUMP_MODE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_BVH_DUMP_MODE = "D3D_0xb775da";
static const char *g_pszMainDocs_RTCORE_BVH_DUMP_MODE = "Enable to dump BVH bin data at ECL. This feature reduces performance and increases memory usage.";

static const char * (g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_CONTINUOUS)[] =
{
    "CONTINUOUS",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_HOTKEY)[] =
{
    "HOTKEY",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_SAVE_SYNC_CACHE)[] =
{
    "SAVE_SYNC_CACHE",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_LOAD_SYNC_CACHE)[] =
{
    "LOAD_SYNC_CACHE",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_BVH_DUMP_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_OFF, 0x00000000 , "Feature disabled" },
    { (const char **)g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_CONTINUOUS, 0x00000001 , "Continuously dump BVHs" },
    { (const char **)g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_HOTKEY, 0x00000002 , "Trigger BVH dump using a hotkey (Can be changed with RTCORE_BVH_DUMP_HOTKEY. Default is ctrl+home)" },
    { (const char **)g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_SAVE_SYNC_CACHE, 0x00000003 , "Save a BLAS-cache from a determinisic synchronous program." },
    { (const char **)g_ppszDefineDataNames_RTCORE_BVH_DUMP_MODE_LOAD_SYNC_CACHE, 0x00000004 , "Load a BLAS-cache in a determinisic synchronous program." },
};

DataDefaultDWORD g_aDefaultData_RTCORE_BVH_DUMP_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_RTCORE_BVH_DUMP_MODE(
    0x10b775da,
    g_pszKeyName_RTCORE_BVH_DUMP_MODE,
    g_pszRemappedName_RTCORE_BVH_DUMP_MODE,
    g_pszMainDocs_RTCORE_BVH_DUMP_MODE,
    g_pszDefinedWhen_RTCORE_BVH_DUMP_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_RTCORE_BVH_DUMP_MODE, 
    5, 
    g_aDefaultData_RTCORE_BVH_DUMP_MODE, 
    1 
);

static const char *g_pszKeyName_RTCORE_BVH_DUMP_PATH = "RTCORE_BVH_DUMP_PATH";
static const char *g_pszDefinedWhen_RTCORE_BVH_DUMP_PATH = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_BVH_DUMP_PATH = "D3D_0xef26c6";
static const char *g_pszMainDocs_RTCORE_BVH_DUMP_PATH = "Path where BVH bin data will be dumped";

DataDefaultSTRING g_aDefaultData_RTCORE_BVH_DUMP_PATH[] =
{
    {"DEFAULT", ".", "" }, 
};

SettingSTRING g_setting_RTCORE_BVH_DUMP_PATH(
    0x10ef26c6,
    g_pszKeyName_RTCORE_BVH_DUMP_PATH,
    g_pszRemappedName_RTCORE_BVH_DUMP_PATH,
    g_pszMainDocs_RTCORE_BVH_DUMP_PATH,
    g_pszDefinedWhen_RTCORE_BVH_DUMP_PATH,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_BVH_DUMP_PATH, 
    1 
);

static const char *g_pszKeyName_RTCORE_DEFAULT_CACHE_CONFIG = "RTCORE_DEFAULT_CACHE_CONFIG";
static const char *g_pszDefinedWhen_RTCORE_DEFAULT_CACHE_CONFIG = "1";
static const char *g_pszRemappedName_RTCORE_DEFAULT_CACHE_CONFIG = "D3DOGL_0x00156d";
static const char *g_pszMainDocs_RTCORE_DEFAULT_CACHE_CONFIG = "RTcore default L1/SMEM cache configuration. Does not work with Turing SM-SCG. Individual kernels may override this.";

static const char * (g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_NONE)[] =
{
    "PREFER_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_SHARED)[] =
{
    "PREFER_SHARED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_L1)[] =
{
    "PREFER_L1",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_EQUAL)[] =
{
    "PREFER_EQUAL",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_DEFAULT_CACHE_CONFIG[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_NONE, 0x00000000 , "No preference for shared memory or L1" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_SHARED, 0x00000001 , "Prefer larger shared memory and smaller L1 cache" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_L1, 0x00000002 , "Prefer larger L1 cache and smaller shared memory" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DEFAULT_CACHE_CONFIG_PREFER_EQUAL, 0x00000003 , "Prefer equal sized L1 cache and shared memory" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_DEFAULT_CACHE_CONFIG[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_RTCORE_DEFAULT_CACHE_CONFIG(
    0x1000156d,
    g_pszKeyName_RTCORE_DEFAULT_CACHE_CONFIG,
    g_pszRemappedName_RTCORE_DEFAULT_CACHE_CONFIG,
    g_pszMainDocs_RTCORE_DEFAULT_CACHE_CONFIG,
    g_pszDefinedWhen_RTCORE_DEFAULT_CACHE_CONFIG,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_DEFAULT_CACHE_CONFIG, 
    4, 
    g_aDefaultData_RTCORE_DEFAULT_CACHE_CONFIG, 
    1 
);

static const char *g_pszKeyName_RTCORE_DISABLE_SMEM_SPILLS = "RTCORE_DISABLE_SMEM_SPILLS";
static const char *g_pszDefinedWhen_RTCORE_DISABLE_SMEM_SPILLS = "1";
static const char *g_pszRemappedName_RTCORE_DISABLE_SMEM_SPILLS = "D3DOGL_0x001570";
static const char *g_pszMainDocs_RTCORE_DISABLE_SMEM_SPILLS = "RTcore SMEM spilling policy. OFF = allow spills to SMEM, ON = disable spills to SMEM";

static const char * (g_ppszDefineDataNames_RTCORE_DISABLE_SMEM_SPILLS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DISABLE_SMEM_SPILLS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_DISABLE_SMEM_SPILLS[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_DISABLE_SMEM_SPILLS_OFF, 0x00000000 , "Allow spills to SMEM" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DISABLE_SMEM_SPILLS_ON, 0x00000001 , "Disable spills to SMEM" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_DISABLE_SMEM_SPILLS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_RTCORE_DISABLE_SMEM_SPILLS(
    0x10001570,
    g_pszKeyName_RTCORE_DISABLE_SMEM_SPILLS,
    g_pszRemappedName_RTCORE_DISABLE_SMEM_SPILLS,
    g_pszMainDocs_RTCORE_DISABLE_SMEM_SPILLS,
    g_pszDefinedWhen_RTCORE_DISABLE_SMEM_SPILLS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_DISABLE_SMEM_SPILLS, 
    2, 
    g_aDefaultData_RTCORE_DISABLE_SMEM_SPILLS, 
    1 
);

static const char *g_pszKeyName_RTCORE_DUMP_MODULE_CUBINS = "RTCORE_DUMP_MODULE_CUBINS";
static const char *g_pszDefinedWhen_RTCORE_DUMP_MODULE_CUBINS = "1";
static const char *g_pszRemappedName_RTCORE_DUMP_MODULE_CUBINS = "D3DOGL_0x00156e";
static const char *g_pszMainDocs_RTCORE_DUMP_MODULE_CUBINS = "Dump CUBINs of compiled raytracing shaders to file. Will not dump internal modules such as traversers or schedulers.";

static const char * (g_ppszDefineDataNames_RTCORE_DUMP_MODULE_CUBINS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DUMP_MODULE_CUBINS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_DUMP_MODULE_CUBINS[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_DUMP_MODULE_CUBINS_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DUMP_MODULE_CUBINS_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_DUMP_MODULE_CUBINS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_DUMP_MODULE_CUBINS(
    0x1000156e,
    g_pszKeyName_RTCORE_DUMP_MODULE_CUBINS,
    g_pszRemappedName_RTCORE_DUMP_MODULE_CUBINS,
    g_pszMainDocs_RTCORE_DUMP_MODULE_CUBINS,
    g_pszDefinedWhen_RTCORE_DUMP_MODULE_CUBINS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_DUMP_MODULE_CUBINS, 
    2, 
    g_aDefaultData_RTCORE_DUMP_MODULE_CUBINS, 
    1 
);

static const char *g_pszKeyName_RTCORE_DXR_USE_CUDA = "RTCORE_DXR_USE_CUDA";
static const char *g_pszDefinedWhen_RTCORE_DXR_USE_CUDA = "1";
static const char *g_pszRemappedName_RTCORE_DXR_USE_CUDA = "D3DOGL_0x001573";
static const char *g_pszMainDocs_RTCORE_DXR_USE_CUDA = "Use CUDA as the backend for rtcore with DXR";

static const char * (g_ppszDefineDataNames_RTCORE_DXR_USE_CUDA_NO)[] =
{
    "NO",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_DXR_USE_CUDA_YES)[] =
{
    "YES",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_DXR_USE_CUDA[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_DXR_USE_CUDA_NO, 0 , "CUDA is not used as the backend for RTCORE with DXR" },
    { (const char **)g_ppszDefineDataNames_RTCORE_DXR_USE_CUDA_YES, 1 , "CUDA is used as the backend for RTCORE with DXR" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_DXR_USE_CUDA[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_RTCORE_DXR_USE_CUDA(
    0x10001573,
    g_pszKeyName_RTCORE_DXR_USE_CUDA,
    g_pszRemappedName_RTCORE_DXR_USE_CUDA,
    g_pszMainDocs_RTCORE_DXR_USE_CUDA,
    g_pszDefinedWhen_RTCORE_DXR_USE_CUDA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_DXR_USE_CUDA, 
    2, 
    g_aDefaultData_RTCORE_DXR_USE_CUDA, 
    1 
);

static const char *g_pszKeyName_RTCORE_EXCEPTION_FLAGS = "RTCORE_EXCEPTION_FLAGS";
static const char *g_pszDefinedWhen_RTCORE_EXCEPTION_FLAGS = "1";
static const char *g_pszRemappedName_RTCORE_EXCEPTION_FLAGS = "D3DOGL_0x001572";
static const char *g_pszMainDocs_RTCORE_EXCEPTION_FLAGS = "Override RTCORE default exception flags";

static const char * (g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_STACK_OVERFLOW)[] =
{
    "STACK_OVERFLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_TRACE_DEPTH)[] =
{
    "TRACE_DEPTH",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_RTCORE_DEFAULT)[] =
{
    "RTCORE_DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_EXCEPTION_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_STACK_OVERFLOW, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_TRACE_DEPTH, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_RTCORE_EXCEPTION_FLAGS_RTCORE_DEFAULT, 0xffffffff , "" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_EXCEPTION_FLAGS[] =
{
    {"DEFAULT", 0xffffffff, "" }, 
};

SettingDWORD g_setting_RTCORE_EXCEPTION_FLAGS(
    0x10001572,
    g_pszKeyName_RTCORE_EXCEPTION_FLAGS,
    g_pszRemappedName_RTCORE_EXCEPTION_FLAGS,
    g_pszMainDocs_RTCORE_EXCEPTION_FLAGS,
    g_pszDefinedWhen_RTCORE_EXCEPTION_FLAGS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_RTCORE_EXCEPTION_FLAGS, 
    4, 
    g_aDefaultData_RTCORE_EXCEPTION_FLAGS, 
    1 
);

static const char *g_pszKeyName_RTCORE_KNOBS = "RTCORE_KNOBS";
static const char *g_pszDefinedWhen_RTCORE_KNOBS = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_KNOBS = "D3DOGL_0x001567";
static const char *g_pszMainDocs_RTCORE_KNOBS = "String containing multiple knobs passed to RTcore. The format is JSON, with the following differences:  1) the enclosing '{' and '}' are omitted.  2) key identifiers don't have to be in quotes.  3) objects ('{','}') are not supported.  4) C and C++ style comments are supported. Example: 'pipeline.logLaunchDetails:true'";

DataDefaultSTRING g_aDefaultData_RTCORE_KNOBS[] =
{
    {"DEFAULT", "", "" }, 
};

SettingSTRING g_setting_RTCORE_KNOBS(
    0x10001567,
    g_pszKeyName_RTCORE_KNOBS,
    g_pszRemappedName_RTCORE_KNOBS,
    g_pszMainDocs_RTCORE_KNOBS,
    g_pszDefinedWhen_RTCORE_KNOBS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_KNOBS, 
    1 
);

static const char *g_pszKeyName_RTCORE_LOG_LEVEL = "RTCORE_LOG_LEVEL";
static const char *g_pszDefinedWhen_RTCORE_LOG_LEVEL = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_LOG_LEVEL = "D3DOGL_0x001568";
static const char *g_pszMainDocs_RTCORE_LOG_LEVEL = "The log level passed to RTcore, in [0,100]";

DataDefaultDWORD g_aDefaultData_RTCORE_LOG_LEVEL[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_RTCORE_LOG_LEVEL(
    0x10001568,
    g_pszKeyName_RTCORE_LOG_LEVEL,
    g_pszRemappedName_RTCORE_LOG_LEVEL,
    g_pszMainDocs_RTCORE_LOG_LEVEL,
    g_pszDefinedWhen_RTCORE_LOG_LEVEL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_LOG_LEVEL, 
    1 
);

static const char *g_pszKeyName_RTCORE_MAX_REGISTERS = "RTCORE_MAX_REGISTERS";
static const char *g_pszDefinedWhen_RTCORE_MAX_REGISTERS = "1";
static const char *g_pszRemappedName_RTCORE_MAX_REGISTERS = "D3DOGL_0x00156c";
static const char *g_pszMainDocs_RTCORE_MAX_REGISTERS = "Maximum register count for ray tracing pipelines, zero means default";

DataDefaultDWORD g_aDefaultData_RTCORE_MAX_REGISTERS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_MAX_REGISTERS(
    0x1000156c,
    g_pszKeyName_RTCORE_MAX_REGISTERS,
    g_pszRemappedName_RTCORE_MAX_REGISTERS,
    g_pszMainDocs_RTCORE_MAX_REGISTERS,
    g_pszDefinedWhen_RTCORE_MAX_REGISTERS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_MAX_REGISTERS, 
    1 
);

static const char *g_pszKeyName_RTCORE_NUM_ATTRIBUTE_REGS = "RTCORE_NUM_ATTRIBUTE_REGS";
static const char *g_pszDefinedWhen_RTCORE_NUM_ATTRIBUTE_REGS = "1";
static const char *g_pszRemappedName_RTCORE_NUM_ATTRIBUTE_REGS = "D3DOGL_0x00156a";
static const char *g_pszMainDocs_RTCORE_NUM_ATTRIBUTE_REGS = "The number of attribute registers used with RTcore, zero means default";

DataDefaultDWORD g_aDefaultData_RTCORE_NUM_ATTRIBUTE_REGS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_NUM_ATTRIBUTE_REGS(
    0x1000156a,
    g_pszKeyName_RTCORE_NUM_ATTRIBUTE_REGS,
    g_pszRemappedName_RTCORE_NUM_ATTRIBUTE_REGS,
    g_pszMainDocs_RTCORE_NUM_ATTRIBUTE_REGS,
    g_pszDefinedWhen_RTCORE_NUM_ATTRIBUTE_REGS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_NUM_ATTRIBUTE_REGS, 
    1 
);

static const char *g_pszKeyName_RTCORE_PRINT_CONTINUATION_SPILLS = "RTCORE_PRINT_CONTINUATION_SPILLS";
static const char *g_pszDefinedWhen_RTCORE_PRINT_CONTINUATION_SPILLS = "1";
static const char *g_pszRemappedName_RTCORE_PRINT_CONTINUATION_SPILLS = "D3DOGL_0x00156f";
static const char *g_pszMainDocs_RTCORE_PRINT_CONTINUATION_SPILLS = "For each continuation call, print a list of values that are spilled.";

static const char * (g_ppszDefineDataNames_RTCORE_PRINT_CONTINUATION_SPILLS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_PRINT_CONTINUATION_SPILLS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_PRINT_CONTINUATION_SPILLS[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_PRINT_CONTINUATION_SPILLS_OFF, 0 , "off" },
    { (const char **)g_ppszDefineDataNames_RTCORE_PRINT_CONTINUATION_SPILLS_ON, 1 , "on" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_PRINT_CONTINUATION_SPILLS[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_PRINT_CONTINUATION_SPILLS(
    0x1000156f,
    g_pszKeyName_RTCORE_PRINT_CONTINUATION_SPILLS,
    g_pszRemappedName_RTCORE_PRINT_CONTINUATION_SPILLS,
    g_pszMainDocs_RTCORE_PRINT_CONTINUATION_SPILLS,
    g_pszDefinedWhen_RTCORE_PRINT_CONTINUATION_SPILLS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_PRINT_CONTINUATION_SPILLS, 
    2, 
    g_aDefaultData_RTCORE_PRINT_CONTINUATION_SPILLS, 
    1 
);

static const char *g_pszKeyName_RTCORE_PROFILING = "RTCORE_PROFILING";
static const char *g_pszDefinedWhen_RTCORE_PROFILING = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_PROFILING = "D3DOGL_0x00156b";
static const char *g_pszMainDocs_RTCORE_PROFILING = "RTcore profiling mode. Change dumping behavior using RTCORE_PROFILING_DUMP_MODE and RTCORE_PROFILING_DUMP_HOTKEY";

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_STATEFUNC)[] =
{
    "STATEFUNC",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_RAYS)[] =
{
    "RAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_LAUNCHBUFFER)[] =
{
    "LAUNCHBUFFER",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_PROFILING[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_NONE, 0x00000000 , "Feature disabled" },
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_STATEFUNC, 0x00000001 , "Dump state function profile to file" },
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_RAYS, 0x00000002 , "Dump ray data to file" },
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_LAUNCHBUFFER, 0x00000004 , "Dump launch buffer to file" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_PROFILING[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_RTCORE_PROFILING(
    0x1000156b,
    g_pszKeyName_RTCORE_PROFILING,
    g_pszRemappedName_RTCORE_PROFILING,
    g_pszMainDocs_RTCORE_PROFILING,
    g_pszDefinedWhen_RTCORE_PROFILING,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_RTCORE_PROFILING, 
    4, 
    g_aDefaultData_RTCORE_PROFILING, 
    1 
);

static const char *g_pszKeyName_RTCORE_PROFILING_ALLOCATION_SIZE = "RTCORE_PROFILING_ALLOCATION_SIZE";
static const char *g_pszDefinedWhen_RTCORE_PROFILING_ALLOCATION_SIZE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_PROFILING_ALLOCATION_SIZE = "D3DOGL_0xe6cd57";
static const char *g_pszMainDocs_RTCORE_PROFILING_ALLOCATION_SIZE = "RTcore profiling buffer allocation size. Defaults to 4MiB.";

DataDefaultDWORD g_aDefaultData_RTCORE_PROFILING_ALLOCATION_SIZE[] =
{
    {"DEFAULT", 4194304, "" }, 
};

SettingDWORD g_setting_RTCORE_PROFILING_ALLOCATION_SIZE(
    0x10e6cd57,
    g_pszKeyName_RTCORE_PROFILING_ALLOCATION_SIZE,
    g_pszRemappedName_RTCORE_PROFILING_ALLOCATION_SIZE,
    g_pszMainDocs_RTCORE_PROFILING_ALLOCATION_SIZE,
    g_pszDefinedWhen_RTCORE_PROFILING_ALLOCATION_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_PROFILING_ALLOCATION_SIZE, 
    1 
);

static const char *g_pszKeyName_RTCORE_PROFILING_DUMP_COUNT = "RTCORE_PROFILING_DUMP_COUNT";
static const char *g_pszDefinedWhen_RTCORE_PROFILING_DUMP_COUNT = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_PROFILING_DUMP_COUNT = "D3D_0x782b48";
static const char *g_pszMainDocs_RTCORE_PROFILING_DUMP_COUNT = "Specifies the number of ECLs to dump profile data over, on hotkey press.";

DataDefaultDWORD g_aDefaultData_RTCORE_PROFILING_DUMP_COUNT[] =
{
    {"DEFAULT", 10, "" }, 
};

SettingDWORD g_setting_RTCORE_PROFILING_DUMP_COUNT(
    0x10782b48,
    g_pszKeyName_RTCORE_PROFILING_DUMP_COUNT,
    g_pszRemappedName_RTCORE_PROFILING_DUMP_COUNT,
    g_pszMainDocs_RTCORE_PROFILING_DUMP_COUNT,
    g_pszDefinedWhen_RTCORE_PROFILING_DUMP_COUNT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_PROFILING_DUMP_COUNT, 
    1 
);

static const char *g_pszKeyName_RTCORE_PROFILING_DUMP_HOTKEY = "RTCORE_PROFILING_DUMP_HOTKEY";
static const char *g_pszDefinedWhen_RTCORE_PROFILING_DUMP_HOTKEY = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_PROFILING_DUMP_HOTKEY = "D3D_0x674b85";
static const char *g_pszMainDocs_RTCORE_PROFILING_DUMP_HOTKEY = "Set custom key for triggering RTCore profile write. Also need to set RTCORE_BVH_DUMP_MODE to HOTKEY. (default is ctrl+pageup)";

DataDefaultDWORD g_aDefaultData_RTCORE_PROFILING_DUMP_HOTKEY[] =
{
    {"DEFAULT", 0x21, "" }, 
};

SettingDWORD g_setting_RTCORE_PROFILING_DUMP_HOTKEY(
    0x10674b85,
    g_pszKeyName_RTCORE_PROFILING_DUMP_HOTKEY,
    g_pszRemappedName_RTCORE_PROFILING_DUMP_HOTKEY,
    g_pszMainDocs_RTCORE_PROFILING_DUMP_HOTKEY,
    g_pszDefinedWhen_RTCORE_PROFILING_DUMP_HOTKEY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_PROFILING_DUMP_HOTKEY, 
    1 
);

static const char *g_pszKeyName_RTCORE_PROFILING_DUMP_MODE = "RTCORE_PROFILING_DUMP_MODE";
static const char *g_pszDefinedWhen_RTCORE_PROFILING_DUMP_MODE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_RTCORE_PROFILING_DUMP_MODE = "D3D_0xbda13e";
static const char *g_pszMainDocs_RTCORE_PROFILING_DUMP_MODE = "Specify how frequently profiling data is written to file.";

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_DUMP_MODE_CONTINUOUS)[] =
{
    "CONTINUOUS",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_PROFILING_DUMP_MODE_HOTKEY)[] =
{
    "HOTKEY",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_PROFILING_DUMP_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_DUMP_MODE_CONTINUOUS, 0x00000000 , "Continuously dump to file" },
    { (const char **)g_ppszDefineDataNames_RTCORE_PROFILING_DUMP_MODE_HOTKEY, 0x00000001 , "Trigger profile dump using a hotkey (Can be changed with RTCORE_PROFILING_DUMP_HOTKEY)" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_PROFILING_DUMP_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_RTCORE_PROFILING_DUMP_MODE(
    0x10bda13e,
    g_pszKeyName_RTCORE_PROFILING_DUMP_MODE,
    g_pszRemappedName_RTCORE_PROFILING_DUMP_MODE,
    g_pszMainDocs_RTCORE_PROFILING_DUMP_MODE,
    g_pszDefinedWhen_RTCORE_PROFILING_DUMP_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_RTCORE_PROFILING_DUMP_MODE, 
    2, 
    g_aDefaultData_RTCORE_PROFILING_DUMP_MODE, 
    1 
);

static const char *g_pszKeyName_RTCORE_USE_CUDA = "RTCORE_USE_CUDA";
static const char *g_pszDefinedWhen_RTCORE_USE_CUDA = "1";
static const char *g_pszRemappedName_RTCORE_USE_CUDA = "D3DOGL_0x001571";
static const char *g_pszMainDocs_RTCORE_USE_CUDA = "Use CUDA as the backend for rtcore";

static const char * (g_ppszDefineDataNames_RTCORE_USE_CUDA_NO)[] =
{
    "NO",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_USE_CUDA_YES)[] =
{
    "YES",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_USE_CUDA[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_USE_CUDA_NO, 0 , "CUDA is not used as the backend for RTCORE" },
    { (const char **)g_ppszDefineDataNames_RTCORE_USE_CUDA_YES, 1 , "CUDA is used as the backend for RTCORE" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_USE_CUDA[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_RTCORE_USE_CUDA(
    0x10001571,
    g_pszKeyName_RTCORE_USE_CUDA,
    g_pszRemappedName_RTCORE_USE_CUDA,
    g_pszMainDocs_RTCORE_USE_CUDA,
    g_pszDefinedWhen_RTCORE_USE_CUDA,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_USE_CUDA, 
    2, 
    g_aDefaultData_RTCORE_USE_CUDA, 
    1 
);

static const char *g_pszKeyName_RTCORE_WARPS_PER_CTA = "RTCORE_WARPS_PER_CTA";
static const char *g_pszDefinedWhen_RTCORE_WARPS_PER_CTA = "1";
static const char *g_pszRemappedName_RTCORE_WARPS_PER_CTA = "D3DOGL_0x011532";
static const char *g_pszMainDocs_RTCORE_WARPS_PER_CTA = "Suggested warp per CTA count for supported schedulers. Zero is disabled.";

DataDefaultDWORD g_aDefaultData_RTCORE_WARPS_PER_CTA[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_WARPS_PER_CTA(
    0x10011532,
    g_pszKeyName_RTCORE_WARPS_PER_CTA,
    g_pszRemappedName_RTCORE_WARPS_PER_CTA,
    g_pszMainDocs_RTCORE_WARPS_PER_CTA,
    g_pszDefinedWhen_RTCORE_WARPS_PER_CTA,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_WARPS_PER_CTA, 
    1 
);

static const char *g_pszKeyName_RTCORE_WARPS_PER_CTA_AMPERE = "RTCORE_WARPS_PER_CTA_AMPERE";
static const char *g_pszDefinedWhen_RTCORE_WARPS_PER_CTA_AMPERE = "1";
static const char *g_pszRemappedName_RTCORE_WARPS_PER_CTA_AMPERE = "D3DOGL_0x011534";
static const char *g_pszMainDocs_RTCORE_WARPS_PER_CTA_AMPERE = "Suggested warp per CTA count for supported schedulers for Ampere if global is not set. Zero is disabled.";

DataDefaultDWORD g_aDefaultData_RTCORE_WARPS_PER_CTA_AMPERE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_WARPS_PER_CTA_AMPERE(
    0x10011534,
    g_pszKeyName_RTCORE_WARPS_PER_CTA_AMPERE,
    g_pszRemappedName_RTCORE_WARPS_PER_CTA_AMPERE,
    g_pszMainDocs_RTCORE_WARPS_PER_CTA_AMPERE,
    g_pszDefinedWhen_RTCORE_WARPS_PER_CTA_AMPERE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_WARPS_PER_CTA_AMPERE, 
    1 
);

static const char *g_pszKeyName_RTCORE_WARPS_PER_CTA_TURING = "RTCORE_WARPS_PER_CTA_TURING";
static const char *g_pszDefinedWhen_RTCORE_WARPS_PER_CTA_TURING = "1";
static const char *g_pszRemappedName_RTCORE_WARPS_PER_CTA_TURING = "D3DOGL_0x011533";
static const char *g_pszMainDocs_RTCORE_WARPS_PER_CTA_TURING = "Suggested warp per CTA count for supported schedulers for Turing if global is not set. Zero is disabled.";

DataDefaultDWORD g_aDefaultData_RTCORE_WARPS_PER_CTA_TURING[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_RTCORE_WARPS_PER_CTA_TURING(
    0x10011533,
    g_pszKeyName_RTCORE_WARPS_PER_CTA_TURING,
    g_pszRemappedName_RTCORE_WARPS_PER_CTA_TURING,
    g_pszMainDocs_RTCORE_WARPS_PER_CTA_TURING,
    g_pszDefinedWhen_RTCORE_WARPS_PER_CTA_TURING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_RTCORE_WARPS_PER_CTA_TURING, 
    1 
);

static const char *g_pszKeyName_RTCORE_WAR_BUG_2648362 = "RTCORE_WAR_BUG_2648362";
static const char *g_pszDefinedWhen_RTCORE_WAR_BUG_2648362 = "1";
static const char *g_pszRemappedName_RTCORE_WAR_BUG_2648362 = "D3DOGL_0x9cbc33";
static const char *g_pszMainDocs_RTCORE_WAR_BUG_2648362 = "Issue warmup TTU requests to prevent cold-start TTU issues on TU10x. See bugs 2648362, 3225100.";

static const char * (g_ppszDefineDataNames_RTCORE_WAR_BUG_2648362_NO)[] =
{
    "NO",
    "0",
    "OFF",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_RTCORE_WAR_BUG_2648362_YES)[] =
{
    "YES",
    "1",
    "ON",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_RTCORE_WAR_BUG_2648362[] =
{
    { (const char **)g_ppszDefineDataNames_RTCORE_WAR_BUG_2648362_NO, 0 , "Do not issue any dummy TTU requests" },
    { (const char **)g_ppszDefineDataNames_RTCORE_WAR_BUG_2648362_YES, 1 , "Issue dummy TTU requests on TU10x" },
};

DataDefaultDWORD g_aDefaultData_RTCORE_WAR_BUG_2648362[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_RTCORE_WAR_BUG_2648362(
    0x109cbc33,
    g_pszKeyName_RTCORE_WAR_BUG_2648362,
    g_pszRemappedName_RTCORE_WAR_BUG_2648362,
    g_pszMainDocs_RTCORE_WAR_BUG_2648362,
    g_pszDefinedWhen_RTCORE_WAR_BUG_2648362,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_RTCORE_WAR_BUG_2648362, 
    2, 
    g_aDefaultData_RTCORE_WAR_BUG_2648362, 
    1 
);

static const char *g_pszKeyName_SETTICKCONTROL = "SETTICKCONTROL";
static const char *g_pszDefinedWhen_SETTICKCONTROL = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_SETTICKCONTROL = "D3DOGL_74095216";
static const char *g_pszMainDocs_SETTICKCONTROL = "value for NV5097_SET_TICK_CONTROL method, where bit 0 is Z_ENABLE, bit 1 is COLOR_ENABLE, bits 5:2 are MAX_TICK_COUNT, bits 13:6 are ACCUM_TIMEOUT, bits 19:14 are ZBAR_TICK_WINDOW, bits 25:20 are CBAR_TICK_WINDOW, and bits 31:26 are PUDDLE_AREA";

static const char * (g_ppszDefineDataNames_SETTICKCONTROL_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_SETTICKCONTROL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_SETTICKCONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_SETTICKCONTROL_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SETTICKCONTROL_MAX, 0xffffffff , "" },
};

SettingDWORD g_setting_SETTICKCONTROL(
    0x10018809,
    g_pszKeyName_SETTICKCONTROL,
    g_pszRemappedName_SETTICKCONTROL,
    g_pszMainDocs_SETTICKCONTROL,
    g_pszDefinedWhen_SETTICKCONTROL,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_SETTICKCONTROL, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_SETTICKCONTROLEARLYZ = "SETTICKCONTROLEARLYZ";
static const char *g_pszDefinedWhen_SETTICKCONTROLEARLYZ = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_SETTICKCONTROLEARLYZ = "D3DOGL_74095217";
static const char *g_pszMainDocs_SETTICKCONTROLEARLYZ = "value for NV5097_SET_TICK_CONTROL_EARLY_Z method, where bit 0 is Z_ENABLE, bit 1 is COLOR_ENABLE, bits 5:2 are MAX_TICK_COUNT, bits 13:6 are ACCUM_TIMEOUT, bits 19:14 are ZBAR_TICK_WINDOW, bits 25:20 are CBAR_TICK_WINDOW, and bits 31:26 are PUDDLE_AREA";

static const char * (g_ppszDefineDataNames_SETTICKCONTROLEARLYZ_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_SETTICKCONTROLEARLYZ_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_SETTICKCONTROLEARLYZ[] =
{
    { (const char **)g_ppszDefineDataNames_SETTICKCONTROLEARLYZ_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SETTICKCONTROLEARLYZ_MAX, 0xffffffff , "" },
};

SettingDWORD g_setting_SETTICKCONTROLEARLYZ(
    0x10ae0f30,
    g_pszKeyName_SETTICKCONTROLEARLYZ,
    g_pszRemappedName_SETTICKCONTROLEARLYZ,
    g_pszMainDocs_SETTICKCONTROLEARLYZ,
    g_pszDefinedWhen_SETTICKCONTROLEARLYZ,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_SETTICKCONTROLEARLYZ, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_SET_ASYNC_LAUNCH_QUEUE_1 = "SET_ASYNC_LAUNCH_QUEUE_1";
static const char *g_pszDefinedWhen_SET_ASYNC_LAUNCH_QUEUE_1 = "1";
static const char *g_pszRemappedName_SET_ASYNC_LAUNCH_QUEUE_1 = "D3DOGL_0x1a1067";
static const char *g_pszMainDocs_SET_ASYNC_LAUNCH_QUEUE_1 = "Allows CWD to launch all VEID>0 (async compute work ) work in CtaLaunchQueue==1. GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.";

static const char * (g_ppszDefineDataNames_SET_ASYNC_LAUNCH_QUEUE_1_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SET_ASYNC_LAUNCH_QUEUE_1_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SET_ASYNC_LAUNCH_QUEUE_1[] =
{
    { (const char **)g_ppszDefineDataNames_SET_ASYNC_LAUNCH_QUEUE_1_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SET_ASYNC_LAUNCH_QUEUE_1_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_SET_ASYNC_LAUNCH_QUEUE_1[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_SET_ASYNC_LAUNCH_QUEUE_1(
    0x101a1067,
    g_pszKeyName_SET_ASYNC_LAUNCH_QUEUE_1,
    g_pszRemappedName_SET_ASYNC_LAUNCH_QUEUE_1,
    g_pszMainDocs_SET_ASYNC_LAUNCH_QUEUE_1,
    g_pszDefinedWhen_SET_ASYNC_LAUNCH_QUEUE_1,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SET_ASYNC_LAUNCH_QUEUE_1, 
    2, 
    g_aDefaultData_SET_ASYNC_LAUNCH_QUEUE_1, 
    1 
);

static const char *g_pszKeyName_SET_NON_RT_LAUNCH_QUEUE_1 = "SET_NON_RT_LAUNCH_QUEUE_1";
static const char *g_pszDefinedWhen_SET_NON_RT_LAUNCH_QUEUE_1 = "1";
static const char *g_pszRemappedName_SET_NON_RT_LAUNCH_QUEUE_1 = "D3DOGL_0x1a1042";
static const char *g_pszMainDocs_SET_NON_RT_LAUNCH_QUEUE_1 = "Allows CWD to launch all compute work from async queue. Default is OFF.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link. Overrides default regkeys set for sync/async compute work";

static const char * (g_ppszDefineDataNames_SET_NON_RT_LAUNCH_QUEUE_1_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SET_NON_RT_LAUNCH_QUEUE_1_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SET_NON_RT_LAUNCH_QUEUE_1[] =
{
    { (const char **)g_ppszDefineDataNames_SET_NON_RT_LAUNCH_QUEUE_1_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SET_NON_RT_LAUNCH_QUEUE_1_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_SET_NON_RT_LAUNCH_QUEUE_1[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SET_NON_RT_LAUNCH_QUEUE_1(
    0x101a1042,
    g_pszKeyName_SET_NON_RT_LAUNCH_QUEUE_1,
    g_pszRemappedName_SET_NON_RT_LAUNCH_QUEUE_1,
    g_pszMainDocs_SET_NON_RT_LAUNCH_QUEUE_1,
    g_pszDefinedWhen_SET_NON_RT_LAUNCH_QUEUE_1,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SET_NON_RT_LAUNCH_QUEUE_1, 
    2, 
    g_aDefaultData_SET_NON_RT_LAUNCH_QUEUE_1, 
    1 
);

static const char *g_pszKeyName_SET_RT_LAUNCH_QUEUE_1 = "SET_RT_LAUNCH_QUEUE_1";
static const char *g_pszDefinedWhen_SET_RT_LAUNCH_QUEUE_1 = "1";
static const char *g_pszRemappedName_SET_RT_LAUNCH_QUEUE_1 = "D3DOGL_0x1a1044";
static const char *g_pszMainDocs_SET_RT_LAUNCH_QUEUE_1 = "Allows CWD to launch Ray tracing compute work from async queue.  GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link. Overrides default regkeys set for sync/async compute work";

static const char * (g_ppszDefineDataNames_SET_RT_LAUNCH_QUEUE_1_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SET_RT_LAUNCH_QUEUE_1_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SET_RT_LAUNCH_QUEUE_1[] =
{
    { (const char **)g_ppszDefineDataNames_SET_RT_LAUNCH_QUEUE_1_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SET_RT_LAUNCH_QUEUE_1_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_SET_RT_LAUNCH_QUEUE_1[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_SET_RT_LAUNCH_QUEUE_1(
    0x101a1044,
    g_pszKeyName_SET_RT_LAUNCH_QUEUE_1,
    g_pszRemappedName_SET_RT_LAUNCH_QUEUE_1,
    g_pszMainDocs_SET_RT_LAUNCH_QUEUE_1,
    g_pszDefinedWhen_SET_RT_LAUNCH_QUEUE_1,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SET_RT_LAUNCH_QUEUE_1, 
    2, 
    g_aDefaultData_SET_RT_LAUNCH_QUEUE_1, 
    1 
);

static const char *g_pszKeyName_SET_SYNC_LAUNCH_QUEUE_1 = "SET_SYNC_LAUNCH_QUEUE_1";
static const char *g_pszDefinedWhen_SET_SYNC_LAUNCH_QUEUE_1 = "1";
static const char *g_pszRemappedName_SET_SYNC_LAUNCH_QUEUE_1 = "D3DOGL_0x1a1066";
static const char *g_pszMainDocs_SET_SYNC_LAUNCH_QUEUE_1 = "Allows CWD to launch all VEID==0 (compute work on main graphics queue) work in CtaLaunchQueue==1. GA10x+ SMSCC feature. See http://nvbugs/2509750 for further details and FD link.";

static const char * (g_ppszDefineDataNames_SET_SYNC_LAUNCH_QUEUE_1_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SET_SYNC_LAUNCH_QUEUE_1_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SET_SYNC_LAUNCH_QUEUE_1[] =
{
    { (const char **)g_ppszDefineDataNames_SET_SYNC_LAUNCH_QUEUE_1_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SET_SYNC_LAUNCH_QUEUE_1_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_SET_SYNC_LAUNCH_QUEUE_1[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SET_SYNC_LAUNCH_QUEUE_1(
    0x101a1066,
    g_pszKeyName_SET_SYNC_LAUNCH_QUEUE_1,
    g_pszRemappedName_SET_SYNC_LAUNCH_QUEUE_1,
    g_pszMainDocs_SET_SYNC_LAUNCH_QUEUE_1,
    g_pszDefinedWhen_SET_SYNC_LAUNCH_QUEUE_1,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SET_SYNC_LAUNCH_QUEUE_1, 
    2, 
    g_aDefaultData_SET_SYNC_LAUNCH_QUEUE_1, 
    1 
);

static const char *g_pszKeyName_SHIM_IGPU_TRANSCODING = "SHIM_IGPU_TRANSCODING";
static const char *g_pszDefinedWhen_SHIM_IGPU_TRANSCODING = "1";
static const char *g_pszRemappedName_SHIM_IGPU_TRANSCODING = "D3DOGL_52180906";
static const char *g_pszMainDocs_SHIM_IGPU_TRANSCODING = "iGPU transcoding";

static const char * (g_ppszDefineDataNames_SHIM_IGPU_TRANSCODING_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_IGPU_TRANSCODING_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_SHIM_IGPU_TRANSCODING[] =
{
    { (const char **)g_ppszDefineDataNames_SHIM_IGPU_TRANSCODING_DISABLE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_SHIM_IGPU_TRANSCODING_ENABLE, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_SHIM_IGPU_TRANSCODING[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SHIM_IGPU_TRANSCODING(
    0x10f9dc85,
    g_pszKeyName_SHIM_IGPU_TRANSCODING,
    g_pszRemappedName_SHIM_IGPU_TRANSCODING,
    g_pszMainDocs_SHIM_IGPU_TRANSCODING,
    g_pszDefinedWhen_SHIM_IGPU_TRANSCODING,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_SHIM_IGPU_TRANSCODING, 
    2, 
    g_aDefaultData_SHIM_IGPU_TRANSCODING, 
    1 
);

static const char *g_pszKeyName_SHIM_MAXRES = "SHIM_MAXRES";
static const char *g_pszDefinedWhen_SHIM_MAXRES = "1";
static const char *g_pszRemappedName_SHIM_MAXRES = "D3DOGL_52180876";
static const char *g_pszMainDocs_SHIM_MAXRES = "Maximum resolution we are going to allow for a given application";

DataDefaultDWORD g_aDefaultData_SHIM_MAXRES[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SHIM_MAXRES(
    0x10f9dc82,
    g_pszKeyName_SHIM_MAXRES,
    g_pszRemappedName_SHIM_MAXRES,
    g_pszMainDocs_SHIM_MAXRES,
    g_pszDefinedWhen_SHIM_MAXRES,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_SHIM_MAXRES, 
    1 
);

static const char *g_pszKeyName_SHIM_MCCOMPAT = "SHIM_MCCOMPAT";
static const char *g_pszDefinedWhen_SHIM_MCCOMPAT = "1";
static const char *g_pszRemappedName_SHIM_MCCOMPAT = "D3DOGL_52180856";
static const char *g_pszMainDocs_SHIM_MCCOMPAT = "allow list for shim layer";

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_INTEGRATED)[] =
{
    "INTEGRATED",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_USER_EDITABLE)[] =
{
    "USER_EDITABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_VIDEO_MASK)[] =
{
    "VIDEO_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_VARYING_BIT)[] =
{
    "VARYING_BIT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_AUTO_SELECT)[] =
{
    "AUTO_SELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_MCCOMPAT_OVERRIDE_BIT)[] =
{
    "OVERRIDE_BIT",
    NULL
};

DataValueDWORD g_aDefineData_SHIM_MCCOMPAT[] =
{
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_INTEGRATED, 0x00000000 , "Run on IGPU" },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_ENABLE, 0x00000001 , "Run on DGPU" },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_USER_EDITABLE, 0x00000002 , "ReadOnly Profile a.k.a. NOT user editable a.k.a. SHIM_RENDERING_OPTIONS_NAMESPACE::IGNORE_OVERRIDES" },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_MASK, 0x00000003 , "ENABLE|USER_EDITABLE" },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_VIDEO_MASK, 0x00000004 , "Video bit." },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_VARYING_BIT, 0x00000008 , "Varying behavior. Behavior is different based on type of app/platform" },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_AUTO_SELECT, 0x00000010 , "In Global Setting this means AutoSelect. In per-app setting, this means use Global Setting." },
    { (const char **)g_ppszDefineDataNames_SHIM_MCCOMPAT_OVERRIDE_BIT, 0x80000000 , "" },
};

DataDefaultDWORD g_aDefaultData_SHIM_MCCOMPAT[] =
{
    {"DEFAULT", 0x00000010, "" }, 
};

SettingDWORD g_setting_SHIM_MCCOMPAT(
    0x10f9dc80,
    g_pszKeyName_SHIM_MCCOMPAT,
    g_pszRemappedName_SHIM_MCCOMPAT,
    g_pszMainDocs_SHIM_MCCOMPAT,
    g_pszDefinedWhen_SHIM_MCCOMPAT,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_SHIM_MCCOMPAT, 
    8, 
    g_aDefaultData_SHIM_MCCOMPAT, 
    1 
);

static const char *g_pszKeyName_SHIM_RENDERING_MODE = "SHIM_RENDERING_MODE";
static const char *g_pszDefinedWhen_SHIM_RENDERING_MODE = "1";
static const char *g_pszRemappedName_SHIM_RENDERING_MODE = "D3DOGL_52180866";
static const char *g_pszMainDocs_SHIM_RENDERING_MODE = "Allow list for shim layer per application";

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_INTEGRATED)[] =
{
    "INTEGRATED",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_ENABLE)[] =
{
    "ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_USER_EDITABLE)[] =
{
    "USER_EDITABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_VIDEO_MASK)[] =
{
    "VIDEO_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_VARYING_BIT)[] =
{
    "VARYING_BIT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_AUTO_SELECT)[] =
{
    "AUTO_SELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_MODE_OVERRIDE_BIT)[] =
{
    "OVERRIDE_BIT",
    NULL
};

DataValueDWORD g_aDefineData_SHIM_RENDERING_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_INTEGRATED, 0x00000000 , "Run on IGPU" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_ENABLE, 0x00000001 , "Run on DGPU" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_USER_EDITABLE, 0x00000002 , "ReadOnly Profile a.k.a. NOT user editable a.k.a. SHIM_RENDERING_OPTIONS_NAMESPACE::IGNORE_OVERRIDES" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_MASK, 0x00000003 , "ENABLE|USER_EDITABLE" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_VIDEO_MASK, 0x00000004 , "Video bit." },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_VARYING_BIT, 0x00000008 , "Varying behavior. Behavior is different based on type of app/platform" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_AUTO_SELECT, 0x00000010 , "In Global Setting this means AutoSelect. In per-app setting, this means use Global Setting." },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_MODE_OVERRIDE_BIT, 0x80000000 , "" },
};

DataDefaultDWORD g_aDefaultData_SHIM_RENDERING_MODE[] =
{
    {"DEFAULT", 0x00000010, "" }, 
};

SettingDWORD g_setting_SHIM_RENDERING_MODE(
    0x10f9dc81,
    g_pszKeyName_SHIM_RENDERING_MODE,
    g_pszRemappedName_SHIM_RENDERING_MODE,
    g_pszMainDocs_SHIM_RENDERING_MODE,
    g_pszDefinedWhen_SHIM_RENDERING_MODE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_SHIM_RENDERING_MODE, 
    8, 
    g_aDefaultData_SHIM_RENDERING_MODE, 
    1 
);

static const char *g_pszKeyName_SHIM_RENDERING_OPTIONS = "SHIM_RENDERING_OPTIONS";
static const char *g_pszDefinedWhen_SHIM_RENDERING_OPTIONS = "1";
static const char *g_pszRemappedName_SHIM_RENDERING_OPTIONS = "D3DOGL_52180896";
static const char *g_pszMainDocs_SHIM_RENDERING_OPTIONS = "Rendering Mode Options for shim layer per application";

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DEFAULT_RENDERING_MODE)[] =
{
    "DEFAULT_RENDERING_MODE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_ASYNC_PRESENT)[] =
{
    "DISABLE_ASYNC_PRESENT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_EHSHELL_DETECT)[] =
{
    "EHSHELL_DETECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_FLASHPLAYER_HOST_DETECT)[] =
{
    "FLASHPLAYER_HOST_DETECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_VIDEO_DRM_APP_DETECT)[] =
{
    "VIDEO_DRM_APP_DETECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGNORE_OVERRIDES)[] =
{
    "IGNORE_OVERRIDES",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_RESERVED1)[] =
{
    "RESERVED1",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ENABLE_DWM_ASYNC_PRESENT)[] =
{
    "ENABLE_DWM_ASYNC_PRESENT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_RESERVED2)[] =
{
    "RESERVED2",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_INHERITANCE)[] =
{
    "ALLOW_INHERITANCE",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_WRAPPERS)[] =
{
    "DISABLE_WRAPPERS",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_DXGI_WRAPPERS)[] =
{
    "DISABLE_DXGI_WRAPPERS",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_PRUNE_UNSUPPORTED_FORMATS)[] =
{
    "PRUNE_UNSUPPORTED_FORMATS",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ENABLE_ALPHA_FORMAT)[] =
{
    "ENABLE_ALPHA_FORMAT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING)[] =
{
    "IGPU_TRANSCODING",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_CUDA)[] =
{
    "DISABLE_CUDA",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_CP_CAPS_FOR_VIDEO)[] =
{
    "ALLOW_CP_CAPS_FOR_VIDEO",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING_FWD_OPTIMUS)[] =
{
    "IGPU_TRANSCODING_FWD_OPTIMUS",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_DURING_SECURE_BOOT)[] =
{
    "DISABLE_DURING_SECURE_BOOT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_INVERT_FOR_QUADRO)[] =
{
    "INVERT_FOR_QUADRO",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_INVERT_FOR_MSHYBRID)[] =
{
    "INVERT_FOR_MSHYBRID",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_REGISTER_PROCESS_ENABLE_GOLD)[] =
{
    "REGISTER_PROCESS_ENABLE_GOLD",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_HANDLE_WINDOWED_MODE_PERF_OPT)[] =
{
    "HANDLE_WINDOWED_MODE_PERF_OPT",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_HANDLE_WIN7_ASYNC_RUNTIME_BUG)[] =
{
    "HANDLE_WIN7_ASYNC_RUNTIME_BUG",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_EXPLICIT_ADAPTER_OPTED_BY_APP)[] =
{
    "EXPLICIT_ADAPTER_OPTED_BY_APP",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_DYNAMIC_DISPLAY_MUX_SWITCH)[] =
{
    "ALLOW_DYNAMIC_DISPLAY_MUX_SWITCH",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISALLOW_DYNAMIC_DISPLAY_MUX_SWITCH)[] =
{
    "DISALLOW_DYNAMIC_DISPLAY_MUX_SWITCH",
    NULL
};

static const char * (g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_TURING_POWER_POLICY)[] =
{
    "DISABLE_TURING_POWER_POLICY",
    NULL
};

DataValueDWORD g_aDefineData_SHIM_RENDERING_OPTIONS[] =
{
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DEFAULT_RENDERING_MODE, 0x00000000 , "No overrides for Shim rendering methods" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_ASYNC_PRESENT, 0x00000001 , "Disable Async Presents (for video apps on DX shim to begin with)" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_EHSHELL_DETECT, 0x00000002 , "Video shim - specific, detect App as WMC, use customized present path" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_FLASHPLAYER_HOST_DETECT, 0x00000004 , "Video shim - specific, App can use flash, use customized present path" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_VIDEO_DRM_APP_DETECT, 0x00000008 , "Video DRM app detected" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGNORE_OVERRIDES, 0x00000010 , "Ignore Right-click Overrides for this app" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_RESERVED1, 0x00000020 , "Reserved1" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ENABLE_DWM_ASYNC_PRESENT, 0x00000040 , "Enable async present for DWM ON desktop scheme" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_RESERVED2, 0x00000080 , "Reserved2" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_INHERITANCE, 0x00000100 , "Benchmarks or Test suites that launch other standalone apps but with the suite's GPU Preference" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_WRAPPERS, 0x00000200 , "Disable all wrappers" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_DXGI_WRAPPERS, 0x00000400 , "Disable DXGI wrappers" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_PRUNE_UNSUPPORTED_FORMATS, 0x00000800 , "Prune NV formats unsupported on intel" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ENABLE_ALPHA_FORMAT, 0x00001000 , "Replace X8R8G8B8 with A8R8G8B8 for autocad application group" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING, 0x00002000 , "Enable IGPU Transcoding" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_CUDA, 0x00004000 , "Disable CUDA" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_CP_CAPS_FOR_VIDEO, 0x00008000 , "Allow UMD Shim to return Content Protection Caps for video playback" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING_FWD_OPTIMUS, 0x00010000 , "Enable IGPU Transcoding on FWD Optimus configs only" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_DURING_SECURE_BOOT, 0x00020000 , "Disable this app (force to iGPU) if booting in secure boot mode with incompatible drivers" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_INVERT_FOR_QUADRO, 0x00040000 , "Used only by CPL to allow app run on the DGPU when it detects Quadro GPU. (used for MobileMark2012)" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_INVERT_FOR_MSHYBRID, 0x00080000 , "Used only by CPL to invert suggested GPU for an app between MSHybrid and NV Optimus" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_REGISTER_PROCESS_ENABLE_GOLD, 0x00100000 , "Identifies if the given app doesn't need to turn on dGPU for its entire lifetime (but it might use it for querying, e.g. fmsiscan.exe)" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_HANDLE_WINDOWED_MODE_PERF_OPT, 0x00200000 , "Handle Windowed mode perf optimization of creating alternate back buffer to avoid corruption due to app bugs" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_HANDLE_WIN7_ASYNC_RUNTIME_BUG, 0x00400000 , "Disable Async Presents on Win7 Only to hide a Dx10 runtime bug" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_EXPLICIT_ADAPTER_OPTED_BY_APP, 0x00800000 , "Explicit Adapter opted by App for rendering" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_ALLOW_DYNAMIC_DISPLAY_MUX_SWITCH, 0x01000000 , "Allow Dynamic Display Mux switch from IGPU to dGPU for this app" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISALLOW_DYNAMIC_DISPLAY_MUX_SWITCH, 0x02000000 , "Dis-allow Dynamic Display Mux switch from IGPU to dGPU for this app" },
    { (const char **)g_ppszDefineDataNames_SHIM_RENDERING_OPTIONS_DISABLE_TURING_POWER_POLICY, 0x04000000 , "Disable Turing Power Policy for apps like SearchUI.exe, Desktop Components or some OEMs apps which hampers Laptop Battery Life due to keeping GPU ON for app's lifetime" },
};

DataDefaultDWORD g_aDefaultData_SHIM_RENDERING_OPTIONS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SHIM_RENDERING_OPTIONS(
    0x10f9dc84,
    g_pszKeyName_SHIM_RENDERING_OPTIONS,
    g_pszRemappedName_SHIM_RENDERING_OPTIONS,
    g_pszMainDocs_SHIM_RENDERING_OPTIONS,
    g_pszDefinedWhen_SHIM_RENDERING_OPTIONS,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_SHIM_RENDERING_OPTIONS, 
    28, 
    g_aDefaultData_SHIM_RENDERING_OPTIONS, 
    1 
);

static const char *g_pszKeyName_SHOW_OPTIMUS_OVERLAY = "SHOW_OPTIMUS_OVERLAY";
static const char *g_pszDefinedWhen_SHOW_OPTIMUS_OVERLAY = "1";
static const char *g_pszRemappedName_SHOW_OPTIMUS_OVERLAY = "D3DOGL_8578b94a";
static const char *g_pszMainDocs_SHOW_OPTIMUS_OVERLAY = "";

static const char * (g_ppszDefineDataNames_SHOW_OPTIMUS_OVERLAY_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SHOW_OPTIMUS_OVERLAY_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SHOW_OPTIMUS_OVERLAY[] =
{
    { (const char **)g_ppszDefineDataNames_SHOW_OPTIMUS_OVERLAY_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_SHOW_OPTIMUS_OVERLAY_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_SHOW_OPTIMUS_OVERLAY[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_SHOW_OPTIMUS_OVERLAY(
    0x10061221,
    g_pszKeyName_SHOW_OPTIMUS_OVERLAY,
    g_pszRemappedName_SHOW_OPTIMUS_OVERLAY,
    g_pszMainDocs_SHOW_OPTIMUS_OVERLAY,
    g_pszDefinedWhen_SHOW_OPTIMUS_OVERLAY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SHOW_OPTIMUS_OVERLAY, 
    2, 
    g_aDefaultData_SHOW_OPTIMUS_OVERLAY, 
    1 
);

static const char *g_pszKeyName_SLIVIDEO = "SLIVIDEO";
static const char *g_pszDefinedWhen_SLIVIDEO = "1";
static const char *g_pszRemappedName_SLIVIDEO = "D3DOGL_17267978";
static const char *g_pszMainDocs_SLIVIDEO = "";

static const char * (g_ppszDefineDataNames_SLIVIDEO_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SLIVIDEO_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SLIVIDEO[] =
{
    { (const char **)g_ppszDefineDataNames_SLIVIDEO_OFF, 0x51661620 , "" },
    { (const char **)g_ppszDefineDataNames_SLIVIDEO_ON, 0x60792907 , "" },
};

DataDefaultDWORD g_aDefaultData_SLIVIDEO[] =
{
    {"DEFAULT", 0x51661620, "" }, 
};

SettingDWORD g_setting_SLIVIDEO(
    0x1048e95e,
    g_pszKeyName_SLIVIDEO,
    g_pszRemappedName_SLIVIDEO,
    g_pszMainDocs_SLIVIDEO,
    g_pszDefinedWhen_SLIVIDEO,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLIVIDEO, 
    2, 
    g_aDefaultData_SLIVIDEO, 
    1 
);

static const char *g_pszKeyName_SLI_GPU_COUNT = "SLI_GPU_COUNT";
static const char *g_pszDefinedWhen_SLI_GPU_COUNT = "1";
static const char *g_pszRemappedName_SLI_GPU_COUNT = "D3DOGL_SLI_GPU_COUNT";
static const char *g_pszMainDocs_SLI_GPU_COUNT = "User visible exposed number of GPUs to use on SLI";

static const char * (g_ppszDefineDataNames_SLI_GPU_COUNT_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_GPU_COUNT_ONE)[] =
{
    "ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_GPU_COUNT_TWO)[] =
{
    "TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_GPU_COUNT_THREE)[] =
{
    "THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_GPU_COUNT_FOUR)[] =
{
    "FOUR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_GPU_COUNT[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_GPU_COUNT_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_GPU_COUNT_ONE, 0x00000001 , "Use a single GPU" },
    { (const char **)g_ppszDefineDataNames_SLI_GPU_COUNT_TWO, 0x00000002 , "Use 2 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_GPU_COUNT_THREE, 0x00000003 , "Use 3 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_GPU_COUNT_FOUR, 0x00000004 , "Use 4 GPUs" },
};

DataDefaultDWORD g_aDefaultData_SLI_GPU_COUNT[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_GPU_COUNT(
    0x1033dcd1,
    g_pszKeyName_SLI_GPU_COUNT,
    g_pszRemappedName_SLI_GPU_COUNT,
    g_pszMainDocs_SLI_GPU_COUNT,
    g_pszDefinedWhen_SLI_GPU_COUNT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_GPU_COUNT, 
    5, 
    g_aDefaultData_SLI_GPU_COUNT, 
    1 
);

static const char *g_pszKeyName_SLI_PREDEFINED_GPU_COUNT = "SLI_PREDEFINED_GPU_COUNT";
static const char *g_pszDefinedWhen_SLI_PREDEFINED_GPU_COUNT = "1";
static const char *g_pszRemappedName_SLI_PREDEFINED_GPU_COUNT = "D3DOGL_PREDEFINED_SLI_GPU_COUNT";
static const char *g_pszMainDocs_SLI_PREDEFINED_GPU_COUNT = "Setting to indicate in the Control Panel how many GPUs to use by default on this SLI profile";

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_ONE)[] =
{
    "ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_TWO)[] =
{
    "TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_THREE)[] =
{
    "THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_FOUR)[] =
{
    "FOUR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_PREDEFINED_GPU_COUNT[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_ONE, 0x00000001 , "Use a single GPU" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_TWO, 0x00000002 , "Use 2 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_THREE, 0x00000003 , "Use 3 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_FOUR, 0x00000004 , "Use 4 GPUs" },
};

DataDefaultDWORD g_aDefaultData_SLI_PREDEFINED_GPU_COUNT[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_PREDEFINED_GPU_COUNT(
    0x1033dcd2,
    g_pszKeyName_SLI_PREDEFINED_GPU_COUNT,
    g_pszRemappedName_SLI_PREDEFINED_GPU_COUNT,
    g_pszMainDocs_SLI_PREDEFINED_GPU_COUNT,
    g_pszDefinedWhen_SLI_PREDEFINED_GPU_COUNT,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_PREDEFINED_GPU_COUNT, 
    5, 
    g_aDefaultData_SLI_PREDEFINED_GPU_COUNT, 
    1 
);

static const char *g_pszKeyName_SLI_PREDEFINED_GPU_COUNT_DX10 = "SLI_PREDEFINED_GPU_COUNT_DX10";
static const char *g_pszDefinedWhen_SLI_PREDEFINED_GPU_COUNT_DX10 = "1";
static const char *g_pszRemappedName_SLI_PREDEFINED_GPU_COUNT_DX10 = "D3DOGL_PREDEFINED_SLI_GPU_COUNT_DX10";
static const char *g_pszMainDocs_SLI_PREDEFINED_GPU_COUNT_DX10 = "Setting to indicate in the Control Panel how many GPUs to use by default on this SLI profile on DirectX10";

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_ONE)[] =
{
    "ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_TWO)[] =
{
    "TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_THREE)[] =
{
    "THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_FOUR)[] =
{
    "FOUR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_PREDEFINED_GPU_COUNT_DX10[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_ONE, 0x00000001 , "Use a single GPU" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_TWO, 0x00000002 , "Use 2 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_THREE, 0x00000003 , "Use 3 GPUs" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_GPU_COUNT_DX10_FOUR, 0x00000004 , "Use 4 GPUs" },
};

DataDefaultDWORD g_aDefaultData_SLI_PREDEFINED_GPU_COUNT_DX10[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_PREDEFINED_GPU_COUNT_DX10(
    0x1033dcd3,
    g_pszKeyName_SLI_PREDEFINED_GPU_COUNT_DX10,
    g_pszRemappedName_SLI_PREDEFINED_GPU_COUNT_DX10,
    g_pszMainDocs_SLI_PREDEFINED_GPU_COUNT_DX10,
    g_pszDefinedWhen_SLI_PREDEFINED_GPU_COUNT_DX10,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_PREDEFINED_GPU_COUNT_DX10, 
    5, 
    g_aDefaultData_SLI_PREDEFINED_GPU_COUNT_DX10, 
    1 
);

static const char *g_pszKeyName_SLI_PREDEFINED_MODE = "SLI_PREDEFINED_MODE";
static const char *g_pszDefinedWhen_SLI_PREDEFINED_MODE = "1";
static const char *g_pszRemappedName_SLI_PREDEFINED_MODE = "D3DOGL_SLI_PREDEFINED_MODE";
static const char *g_pszMainDocs_SLI_PREDEFINED_MODE = "Setting to indicate in the Control Panel which SLI mode is active by default";

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_SINGLE)[] =
{
    "FORCE_SINGLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR)[] =
{
    "FORCE_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR2)[] =
{
    "FORCE_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_SFR)[] =
{
    "FORCE_SFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR)[] =
{
    "FORCE_AFR_OF_SFR__FALLBACK_3AFR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_PREDEFINED_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_SINGLE, 0x00000001 , "Force the driver to use Single mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR, 0x00000002 , "Force AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR2, 0x00000003 , "Special AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_SFR, 0x00000004 , "Deprecated SFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR, 0x00000005 , "For 4-Way systems, combined mode" },
};

DataDefaultDWORD g_aDefaultData_SLI_PREDEFINED_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_PREDEFINED_MODE(
    0x1033cec1,
    g_pszKeyName_SLI_PREDEFINED_MODE,
    g_pszRemappedName_SLI_PREDEFINED_MODE,
    g_pszMainDocs_SLI_PREDEFINED_MODE,
    g_pszDefinedWhen_SLI_PREDEFINED_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_PREDEFINED_MODE, 
    6, 
    g_aDefaultData_SLI_PREDEFINED_MODE, 
    1 
);

static const char *g_pszKeyName_SLI_PREDEFINED_MODE_DX10 = "SLI_PREDEFINED_MODE_DX10";
static const char *g_pszDefinedWhen_SLI_PREDEFINED_MODE_DX10 = "1";
static const char *g_pszRemappedName_SLI_PREDEFINED_MODE_DX10 = "D3DOGL_SLI_PREDEFINED_MODE_DX10";
static const char *g_pszMainDocs_SLI_PREDEFINED_MODE_DX10 = "Setting to indicate in the Control Panel which SLI mode is active by default on DirectX 10";

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_SINGLE)[] =
{
    "FORCE_SINGLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR)[] =
{
    "FORCE_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR2)[] =
{
    "FORCE_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_SFR)[] =
{
    "FORCE_SFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR_OF_SFR__FALLBACK_3AFR)[] =
{
    "FORCE_AFR_OF_SFR__FALLBACK_3AFR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_PREDEFINED_MODE_DX10[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_SINGLE, 0x00000001 , "Force the driver to use Single mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR, 0x00000002 , "Force AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR2, 0x00000003 , "Special AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_SFR, 0x00000004 , "Deprecated SFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_PREDEFINED_MODE_DX10_FORCE_AFR_OF_SFR__FALLBACK_3AFR, 0x00000005 , "For 4-Way systems, combined mode" },
};

DataDefaultDWORD g_aDefaultData_SLI_PREDEFINED_MODE_DX10[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_PREDEFINED_MODE_DX10(
    0x1033cec2,
    g_pszKeyName_SLI_PREDEFINED_MODE_DX10,
    g_pszRemappedName_SLI_PREDEFINED_MODE_DX10,
    g_pszMainDocs_SLI_PREDEFINED_MODE_DX10,
    g_pszDefinedWhen_SLI_PREDEFINED_MODE_DX10,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_PREDEFINED_MODE_DX10, 
    6, 
    g_aDefaultData_SLI_PREDEFINED_MODE_DX10, 
    1 
);

static const char *g_pszKeyName_SLI_RENDERING_MODE = "SLI_RENDERING_MODE";
static const char *g_pszDefinedWhen_SLI_RENDERING_MODE = "1";
static const char *g_pszRemappedName_SLI_RENDERING_MODE = "D3DOGL_SLI_RENDERING_MODE";
static const char *g_pszMainDocs_SLI_RENDERING_MODE = "User visible exposed SLI Modes";

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_SINGLE)[] =
{
    "FORCE_SINGLE",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR)[] =
{
    "FORCE_AFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR2)[] =
{
    "FORCE_AFR2",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_SFR)[] =
{
    "FORCE_SFR",
    NULL
};

static const char * (g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR)[] =
{
    "FORCE_AFR_OF_SFR__FALLBACK_3AFR",
    NULL
};

DataValueDWORD g_aDefineData_SLI_RENDERING_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_AUTOSELECT, 0x00000000 , "The default mode, the driver will pick what's best" },
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_SINGLE, 0x00000001 , "Force the driver to use Single mode" },
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR, 0x00000002 , "Force AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR2, 0x00000003 , "Special AFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_SFR, 0x00000004 , "Deprecated SFR mode" },
    { (const char **)g_ppszDefineDataNames_SLI_RENDERING_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR, 0x00000005 , "For 4-Way systems, combined mode" },
};

DataDefaultDWORD g_aDefaultData_SLI_RENDERING_MODE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_SLI_RENDERING_MODE(
    0x1033ced1,
    g_pszKeyName_SLI_RENDERING_MODE,
    g_pszRemappedName_SLI_RENDERING_MODE,
    g_pszMainDocs_SLI_RENDERING_MODE,
    g_pszDefinedWhen_SLI_RENDERING_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SLI_RENDERING_MODE, 
    6, 
    g_aDefaultData_SLI_RENDERING_MODE, 
    1 
);

static const char *g_pszKeyName_SPLIT_ADAPTER_RENDER_DEVICE = "SPLIT_ADAPTER_RENDER_DEVICE";
static const char *g_pszDefinedWhen_SPLIT_ADAPTER_RENDER_DEVICE = "1";
static const char *g_pszRemappedName_SPLIT_ADAPTER_RENDER_DEVICE = "D3DOGL_19103865";
static const char *g_pszMainDocs_SPLIT_ADAPTER_RENDER_DEVICE = "";

static const char * (g_ppszDefineDataNames_SPLIT_ADAPTER_RENDER_DEVICE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_SPLIT_ADAPTER_RENDER_DEVICE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_SPLIT_ADAPTER_RENDER_DEVICE[] =
{
    { (const char **)g_ppszDefineDataNames_SPLIT_ADAPTER_RENDER_DEVICE_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_SPLIT_ADAPTER_RENDER_DEVICE_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_SPLIT_ADAPTER_RENDER_DEVICE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_SPLIT_ADAPTER_RENDER_DEVICE(
    0x10354ff9,
    g_pszKeyName_SPLIT_ADAPTER_RENDER_DEVICE,
    g_pszRemappedName_SPLIT_ADAPTER_RENDER_DEVICE,
    g_pszMainDocs_SPLIT_ADAPTER_RENDER_DEVICE,
    g_pszDefinedWhen_SPLIT_ADAPTER_RENDER_DEVICE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_SPLIT_ADAPTER_RENDER_DEVICE, 
    2, 
    g_aDefaultData_SPLIT_ADAPTER_RENDER_DEVICE, 
    1 
);

static const char *g_pszKeyName_STEREO_MCCOMPAT = "STEREO_MCCOMPAT";
static const char *g_pszDefinedWhen_STEREO_MCCOMPAT = "1";
static const char *g_pszRemappedName_STEREO_MCCOMPAT = "D3DOGL_49119164";
static const char *g_pszMainDocs_STEREO_MCCOMPAT = "";

static const char * (g_ppszDefineDataNames_STEREO_MCCOMPAT_LEGACY)[] =
{
    "LEGACY",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_MCCOMPAT_BROADCAST)[] =
{
    "BROADCAST",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_MCCOMPAT_DISABLE_SLI)[] =
{
    "DISABLE_SLI",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_MCCOMPAT_MASK)[] =
{
    "MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_MCCOMPAT_OVERRIDE_BIT)[] =
{
    "OVERRIDE_BIT",
    NULL
};

DataValueDWORD g_aDefineData_STEREO_MCCOMPAT[] =
{
    { (const char **)g_ppszDefineDataNames_STEREO_MCCOMPAT_LEGACY, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_STEREO_MCCOMPAT_BROADCAST, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_STEREO_MCCOMPAT_DISABLE_SLI, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_STEREO_MCCOMPAT_MASK, 0x00000007 , "LEGACY|BROADCAST|DISABLE_SLI" },
    { (const char **)g_ppszDefineDataNames_STEREO_MCCOMPAT_OVERRIDE_BIT, 0x80000000 , "" },
};

DataDefaultDWORD g_aDefaultData_STEREO_MCCOMPAT[] =
{
    {"DEFAULT", 0x00000004, "" }, 
};

SettingDWORD g_setting_STEREO_MCCOMPAT(
    0x102e048d,
    g_pszKeyName_STEREO_MCCOMPAT,
    g_pszRemappedName_STEREO_MCCOMPAT,
    g_pszMainDocs_STEREO_MCCOMPAT,
    g_pszDefinedWhen_STEREO_MCCOMPAT,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_STEREO_MCCOMPAT, 
    5, 
    g_aDefaultData_STEREO_MCCOMPAT, 
    1 
);

static const char *g_pszKeyName_STEREO_WIN_MODE_IN_SURROUND = "STEREO_WIN_MODE_IN_SURROUND";
static const char *g_pszDefinedWhen_STEREO_WIN_MODE_IN_SURROUND = "1";
static const char *g_pszRemappedName_STEREO_WIN_MODE_IN_SURROUND = "D3DOGL_WindowedModeStereoInSurround";
static const char *g_pszMainDocs_STEREO_WIN_MODE_IN_SURROUND = "NV private interface to enable/disable windowed mode Stereo in Surround";

static const char * (g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_SINGLE_MODE)[] =
{
    "ENABLE_DX10_SINGLE_MODE",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_BROADCAST)[] =
{
    "ENABLE_DX10_BROADCAST",
    NULL
};

static const char * (g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_MASK_DX10)[] =
{
    "ENABLE_MASK_DX10",
    NULL
};

DataValueDWORD g_aDefineData_STEREO_WIN_MODE_IN_SURROUND[] =
{
    { (const char **)g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_OFF, 0x00000000 , "No windowed mode Stereo in Surround" },
    { (const char **)g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_SINGLE_MODE, 0x00000100 , "DX10/11 in MC_SINGLE_MODE mode" },
    { (const char **)g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_BROADCAST, 0x00000200 , "DX10/11 in BROADCAST SLI mode (2 GPUs)" },
    { (const char **)g_ppszDefineDataNames_STEREO_WIN_MODE_IN_SURROUND_ENABLE_MASK_DX10, 0x0000FF00 , "DX10/11 enabled mode" },
};

DataDefaultDWORD g_aDefaultData_STEREO_WIN_MODE_IN_SURROUND[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_STEREO_WIN_MODE_IN_SURROUND(
    0x107ecb8d,
    g_pszKeyName_STEREO_WIN_MODE_IN_SURROUND,
    g_pszRemappedName_STEREO_WIN_MODE_IN_SURROUND,
    g_pszMainDocs_STEREO_WIN_MODE_IN_SURROUND,
    g_pszDefinedWhen_STEREO_WIN_MODE_IN_SURROUND,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_STEREO_WIN_MODE_IN_SURROUND, 
    4, 
    g_aDefaultData_STEREO_WIN_MODE_IN_SURROUND, 
    1 
);

static const char *g_pszKeyName_TESLAINTERTPCARBITRATIONCONTROL = "TESLAINTERTPCARBITRATIONCONTROL";
static const char *g_pszDefinedWhen_TESLAINTERTPCARBITRATIONCONTROL = "1";
static const char *g_pszRemappedName_TESLAINTERTPCARBITRATIONCONTROL = "D3D_5379259";
static const char *g_pszMainDocs_TESLAINTERTPCARBITRATIONCONTROL = "value for the NV5097_SET_INTER_TPC_ARBITRATION_CONTROL method, where bit 0 is ENABLE, bits 11:4 are WAVEFRONT_WINDOW_SIZE, and bits 19:12 are TEXTURE_PHASE_WINDOW_SIZE";

static const char * (g_ppszDefineDataNames_TESLAINTERTPCARBITRATIONCONTROL_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLAINTERTPCARBITRATIONCONTROL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_TESLAINTERTPCARBITRATIONCONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_TESLAINTERTPCARBITRATIONCONTROL_MIN, 0x00000 , "" },
    { (const char **)g_ppszDefineDataNames_TESLAINTERTPCARBITRATIONCONTROL_MAX, 0xfffff , "" },
};

SettingDWORD g_setting_TESLAINTERTPCARBITRATIONCONTROL(
    0x10d9604d,
    g_pszKeyName_TESLAINTERTPCARBITRATIONCONTROL,
    g_pszRemappedName_TESLAINTERTPCARBITRATIONCONTROL,
    g_pszMainDocs_TESLAINTERTPCARBITRATIONCONTROL,
    g_pszDefinedWhen_TESLAINTERTPCARBITRATIONCONTROL,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_TESLAINTERTPCARBITRATIONCONTROL, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_TESLAOCTVERTICESPERTPC = "TESLAOCTVERTICESPERTPC";
static const char *g_pszDefinedWhen_TESLAOCTVERTICESPERTPC = "1";
static const char *g_pszRemappedName_TESLAOCTVERTICESPERTPC = "D3D_57310220";
static const char *g_pszMainDocs_TESLAOCTVERTICESPERTPC = "value for the NV5097_SET_OCTVERTICES_PER_TPC method, bits 7:0 are the value, bit 8 is SWITCH_TPC_ON_FLUSH";

static const char * (g_ppszDefineDataNames_TESLAOCTVERTICESPERTPC_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLAOCTVERTICESPERTPC_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_TESLAOCTVERTICESPERTPC[] =
{
    { (const char **)g_ppszDefineDataNames_TESLAOCTVERTICESPERTPC_MIN, 0x000 , "" },
    { (const char **)g_ppszDefineDataNames_TESLAOCTVERTICESPERTPC_MAX, 0x1ff , "" },
};

SettingDWORD g_setting_TESLAOCTVERTICESPERTPC(
    0x10166e3d,
    g_pszKeyName_TESLAOCTVERTICESPERTPC,
    g_pszRemappedName_TESLAOCTVERTICESPERTPC,
    g_pszMainDocs_TESLAOCTVERTICESPERTPC,
    g_pszDefinedWhen_TESLAOCTVERTICESPERTPC,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_TESLAOCTVERTICESPERTPC, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_TESLAPSWAIT = "TESLAPSWAIT";
static const char *g_pszDefinedWhen_TESLAPSWAIT = "1";
static const char *g_pszRemappedName_TESLAPSWAIT = "D3D_54312266";
static const char *g_pszMainDocs_TESLAPSWAIT = "value for the NV5097_SET_PS_WAIT method";

static const char * (g_ppszDefineDataNames_TESLAPSWAIT_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLAPSWAIT_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_TESLAPSWAIT[] =
{
    { (const char **)g_ppszDefineDataNames_TESLAPSWAIT_MIN, 0x0 , "cause the timeout to expire immediately" },
    { (const char **)g_ppszDefineDataNames_TESLAPSWAIT_MAX, 0xffffffff , "" },
};

SettingDWORD g_setting_TESLAPSWAIT(
    0x109c8e50,
    g_pszKeyName_TESLAPSWAIT,
    g_pszRemappedName_TESLAPSWAIT,
    g_pszMainDocs_TESLAPSWAIT,
    g_pszDefinedWhen_TESLAPSWAIT,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_TESLAPSWAIT, 
    2, 
    NULL,
    0 // No values
);

static const char *g_pszKeyName_TESLA_ADDDUMMYCREAD = "TESLA_ADDDUMMYCREAD";
static const char *g_pszDefinedWhen_TESLA_ADDDUMMYCREAD = "1";
static const char *g_pszRemappedName_TESLA_ADDDUMMYCREAD = "D3DOGL_75494732";
static const char *g_pszMainDocs_TESLA_ADDDUMMYCREAD = "value for COPBaseArgs::AddDummyCRead";

static const char * (g_ppszDefineDataNames_TESLA_ADDDUMMYCREAD_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ADDDUMMYCREAD_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_TESLA_ADDDUMMYCREAD[] =
{
    { (const char **)g_ppszDefineDataNames_TESLA_ADDDUMMYCREAD_OFF, 0 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ADDDUMMYCREAD_ON, 1 , "" },
};

DataDefaultDWORD g_aDefaultData_TESLA_ADDDUMMYCREAD[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_TESLA_ADDDUMMYCREAD(
    0x1037df7d,
    g_pszKeyName_TESLA_ADDDUMMYCREAD,
    g_pszRemappedName_TESLA_ADDDUMMYCREAD,
    g_pszMainDocs_TESLA_ADDDUMMYCREAD,
    g_pszDefinedWhen_TESLA_ADDDUMMYCREAD,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_TESLA_ADDDUMMYCREAD, 
    2, 
    g_aDefaultData_TESLA_ADDDUMMYCREAD, 
    1 
);

static const char *g_pszKeyName_TESLA_ANISO_QUALITY = "TESLA_ANISO_QUALITY";
static const char *g_pszDefinedWhen_TESLA_ANISO_QUALITY = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_TESLA_ANISO_QUALITY = "D3DOGL_24189123";
static const char *g_pszMainDocs_TESLA_ANISO_QUALITY = "aniso quality on tesla (aka NV50TexPerfSetting)";

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNV30)[] =
{
    "tpsNV30",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNV40)[] =
{
    "tpsNV40",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsDefault)[] =
{
    "tpsDefault",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsAssertive)[] =
{
    "tpsAssertive",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsAggressive)[] =
{
    "tpsAggressive",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsFerocious)[] =
{
    "tpsFerocious",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNSettings)[] =
{
    "tpsNSettings",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_ANISO_QUALITY_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_TESLA_ANISO_QUALITY[] =
{
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNV30, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNV40, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsDefault, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsAssertive, 0x00000003 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsAggressive, 0x00000004 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsFerocious, 0x00000005 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_tpsNSettings, 0x6 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_ANISO_QUALITY_MAX, 0x5 , "tpsNSettings-1" },
};

DataDefaultDWORD g_aDefaultData_TESLA_ANISO_QUALITY[] =
{
    {"DEFAULT", 0x00000002, "" }, 
};

SettingDWORD g_setting_TESLA_ANISO_QUALITY(
    0x107c493b,
    g_pszKeyName_TESLA_ANISO_QUALITY,
    g_pszRemappedName_TESLA_ANISO_QUALITY,
    g_pszMainDocs_TESLA_ANISO_QUALITY,
    g_pszDefinedWhen_TESLA_ANISO_QUALITY,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_TESLA_ANISO_QUALITY, 
    9, 
    g_aDefaultData_TESLA_ANISO_QUALITY, 
    1 
);

static const char *g_pszKeyName_TESLA_REGBANKSIZE = "TESLA_REGBANKSIZE";
static const char *g_pszDefinedWhen_TESLA_REGBANKSIZE = "defined(DEBUG) || defined(DEVELOP)";
static const char *g_pszRemappedName_TESLA_REGBANKSIZE = "D3DOGL_83451133";
static const char *g_pszMainDocs_TESLA_REGBANKSIZE = "tesla's register bank size";

static const char * (g_ppszDefineDataNames_TESLA_REGBANKSIZE_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_TESLA_REGBANKSIZE_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_TESLA_REGBANKSIZE[] =
{
    { (const char **)g_ppszDefineDataNames_TESLA_REGBANKSIZE_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_TESLA_REGBANKSIZE_MAX, 0xffffffff , "" },
};

DataDefaultDWORD g_aDefaultData_TESLA_REGBANKSIZE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_TESLA_REGBANKSIZE(
    0x10c38467,
    g_pszKeyName_TESLA_REGBANKSIZE,
    g_pszRemappedName_TESLA_REGBANKSIZE,
    g_pszMainDocs_TESLA_REGBANKSIZE,
    g_pszDefinedWhen_TESLA_REGBANKSIZE,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_TESLA_REGBANKSIZE, 
    2, 
    g_aDefaultData_TESLA_REGBANKSIZE, 
    1 
);

static const char *g_pszKeyName_TESSELLATION_LOD_MULTIPLIER = "TESSELLATION_LOD_MULTIPLIER";
static const char *g_pszDefinedWhen_TESSELLATION_LOD_MULTIPLIER = "1";
static const char *g_pszRemappedName_TESSELLATION_LOD_MULTIPLIER = "D3DOGL_0x9e1f10";
static const char *g_pszMainDocs_TESSELLATION_LOD_MULTIPLIER = "16:16 fixed-point multiplier for hull shader LOD output";

DataDefaultDWORD g_aDefaultData_TESSELLATION_LOD_MULTIPLIER[] =
{
    {"DEFAULT", 0x00010000, "" }, 
};

SettingDWORD g_setting_TESSELLATION_LOD_MULTIPLIER(
    0x109e1f10,
    g_pszKeyName_TESSELLATION_LOD_MULTIPLIER,
    g_pszRemappedName_TESSELLATION_LOD_MULTIPLIER,
    g_pszMainDocs_TESSELLATION_LOD_MULTIPLIER,
    g_pszDefinedWhen_TESSELLATION_LOD_MULTIPLIER,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    NULL,
    0, // No values
    g_aDefaultData_TESSELLATION_LOD_MULTIPLIER, 
    1 
);

static const char *g_pszKeyName_TILE_COALESCER_TILE_SIZE = "TILE_COALESCER_TILE_SIZE";
static const char *g_pszDefinedWhen_TILE_COALESCER_TILE_SIZE = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_TILE_COALESCER_TILE_SIZE = "D3D_545221";
static const char *g_pszMainDocs_TILE_COALESCER_TILE_SIZE = "Tile coalescer's tile size. Default is 8x8 tile size for pre GP10x and 16x16 for GP10x +";

static const char * (g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_TILE_SIZE_NOOVERRIDE)[] =
{
    "TILE_SIZE_NOOVERRIDE",
    NULL
};

static const char * (g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_16x16)[] =
{
    "INTERLOCK_TILE_SIZE_16x16",
    NULL
};

static const char * (g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_8x8)[] =
{
    "INTERLOCK_TILE_SIZE_8x8",
    NULL
};

static const char * (g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_16x16)[] =
{
    "NO_INTERLOCK_TILE_SIZE_16x16",
    NULL
};

static const char * (g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_8x8)[] =
{
    "NO_INTERLOCK_TILE_SIZE_8x8",
    NULL
};

DataValueDWORD g_aDefineData_TILE_COALESCER_TILE_SIZE[] =
{
    { (const char **)g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_TILE_SIZE_NOOVERRIDE, 0x00000000 , "Do not override tile size. Default on Maxwell B and Pascal A is 8x8 when running with pixel shader interlock, and 16x16 when not in pixel shader interlock mode. On Pascal B and later it's 16x16 irrespective of pixel shader interlock" },
    { (const char **)g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_16x16, 0x00000001 , "16x16 tile size for interlock mode" },
    { (const char **)g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_8x8, 0x00000002 , "8x8 tile size for interlock mode" },
    { (const char **)g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_16x16, 0x00000004 , "16x16 tile size for no interlock mode" },
    { (const char **)g_ppszDefineDataNames_TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_8x8, 0x00000008 , "8x8 tile size for no interlock mode" },
};

DataDefaultDWORD g_aDefaultData_TILE_COALESCER_TILE_SIZE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_TILE_COALESCER_TILE_SIZE(
    0x10545221,
    g_pszKeyName_TILE_COALESCER_TILE_SIZE,
    g_pszRemappedName_TILE_COALESCER_TILE_SIZE,
    g_pszMainDocs_TILE_COALESCER_TILE_SIZE,
    g_pszDefinedWhen_TILE_COALESCER_TILE_SIZE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_TILE_COALESCER_TILE_SIZE, 
    5, 
    g_aDefaultData_TILE_COALESCER_TILE_SIZE, 
    1 
);

static const char *g_pszKeyName_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS = "TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS";
static const char *g_pszDefinedWhen_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS = "1";
static const char *g_pszRemappedName_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS = "D3DOGL_0xc5c1e8";
static const char *g_pszMainDocs_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS = "used to enable the new SM-SCG protocol called 'ComputeInGraphics'";

static const char * (g_ppszDefineDataNames_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS[] =
{
    { (const char **)g_ppszDefineDataNames_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS(
    0x10c5c1e8,
    g_pszKeyName_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS,
    g_pszRemappedName_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS,
    g_pszMainDocs_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS,
    g_pszDefinedWhen_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS, 
    2, 
    g_aDefaultData_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS, 
    1 
);

static const char *g_pszKeyName_UMD_HIDE_QUADRO_IDENTITY = "UMD_HIDE_QUADRO_IDENTITY";
static const char *g_pszDefinedWhen_UMD_HIDE_QUADRO_IDENTITY = "1";
static const char *g_pszRemappedName_UMD_HIDE_QUADRO_IDENTITY = "D3DOGL_0xaaa36c";
static const char *g_pszMainDocs_UMD_HIDE_QUADRO_IDENTITY = "disable Quadro optimization features";

static const char * (g_ppszDefineDataNames_UMD_HIDE_QUADRO_IDENTITY_DISABLE)[] =
{
    "DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_UMD_HIDE_QUADRO_IDENTITY_ENABLE)[] =
{
    "ENABLE",
    NULL
};

DataValueDWORD g_aDefineData_UMD_HIDE_QUADRO_IDENTITY[] =
{
    { (const char **)g_ppszDefineDataNames_UMD_HIDE_QUADRO_IDENTITY_DISABLE, 0 , "do not hide Quadro optimizations" },
    { (const char **)g_ppszDefineDataNames_UMD_HIDE_QUADRO_IDENTITY_ENABLE, 1 , "hide Quadro optimizations, act as a GeForce" },
};

DataDefaultDWORD g_aDefaultData_UMD_HIDE_QUADRO_IDENTITY[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_UMD_HIDE_QUADRO_IDENTITY(
    0x10aaa36c,
    g_pszKeyName_UMD_HIDE_QUADRO_IDENTITY,
    g_pszRemappedName_UMD_HIDE_QUADRO_IDENTITY,
    g_pszMainDocs_UMD_HIDE_QUADRO_IDENTITY,
    g_pszDefinedWhen_UMD_HIDE_QUADRO_IDENTITY,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_UMD_HIDE_QUADRO_IDENTITY, 
    2, 
    g_aDefaultData_UMD_HIDE_QUADRO_IDENTITY, 
    1 
);

static const char *g_pszKeyName_VCAA_HILITE = "VCAA_HILITE";
static const char *g_pszDefinedWhen_VCAA_HILITE = "defined(DEVELOP) || defined(DEBUG)";
static const char *g_pszRemappedName_VCAA_HILITE = "D3D_78E16B9C";
static const char *g_pszMainDocs_VCAA_HILITE = "";

static const char * (g_ppszDefineDataNames_VCAA_HILITE_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VCAA_HILITE_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_VCAA_HILITE[] =
{
    { (const char **)g_ppszDefineDataNames_VCAA_HILITE_OFF, 0x22754241 , "" },
    { (const char **)g_ppszDefineDataNames_VCAA_HILITE_ON, 0x66855023 , "" },
};

DataDefaultDWORD g_aDefaultData_VCAA_HILITE[] =
{
    {"DEFAULT", 0x22754241, "" }, 
};

SettingDWORD g_setting_VCAA_HILITE(
    0x10d3a8ef,
    g_pszKeyName_VCAA_HILITE,
    g_pszRemappedName_VCAA_HILITE,
    g_pszMainDocs_VCAA_HILITE,
    g_pszDefinedWhen_VCAA_HILITE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VCAA_HILITE, 
    2, 
    g_aDefaultData_VCAA_HILITE, 
    1 
);

static const char *g_pszKeyName_VRPRERENDERLIMIT = "VRPRERENDERLIMIT";
static const char *g_pszDefinedWhen_VRPRERENDERLIMIT = "1";
static const char *g_pszRemappedName_VRPRERENDERLIMIT = "D3DOGL_0x111133";
static const char *g_pszMainDocs_VRPRERENDERLIMIT = "";

static const char * (g_ppszDefineDataNames_VRPRERENDERLIMIT_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_VRPRERENDERLIMIT_MAX)[] =
{
    "MAX",
    NULL
};

static const char * (g_ppszDefineDataNames_VRPRERENDERLIMIT_APP_CONTROLLED)[] =
{
    "APP_CONTROLLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VRPRERENDERLIMIT_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_VRPRERENDERLIMIT[] =
{
    { (const char **)g_ppszDefineDataNames_VRPRERENDERLIMIT_MIN, 0x00 , "" },
    { (const char **)g_ppszDefineDataNames_VRPRERENDERLIMIT_MAX, 0xff , "" },
    { (const char **)g_ppszDefineDataNames_VRPRERENDERLIMIT_APP_CONTROLLED, 0x00 , "The present limit will be controlled by application or driver adjustments." },
    { (const char **)g_ppszDefineDataNames_VRPRERENDERLIMIT_DEFAULT, 0x01 , "" },
};

DataDefaultDWORD g_aDefaultData_VRPRERENDERLIMIT[] =
{
    {"DEFAULT", 0x01, "" }, 
};

SettingDWORD g_setting_VRPRERENDERLIMIT(
    0x10111133,
    g_pszKeyName_VRPRERENDERLIMIT,
    g_pszRemappedName_VRPRERENDERLIMIT,
    g_pszMainDocs_VRPRERENDERLIMIT,
    g_pszDefinedWhen_VRPRERENDERLIMIT,
    0,
    SettingGeneric::ATTRIBUTE_RANGE, 
    false, 
    g_aDefineData_VRPRERENDERLIMIT, 
    4, 
    g_aDefaultData_VRPRERENDERLIMIT, 
    1 
);

static const char *g_pszKeyName_VRRFEATUREINDICATOR = "VRRFEATUREINDICATOR";
static const char *g_pszDefinedWhen_VRRFEATUREINDICATOR = "1";
static const char *g_pszRemappedName_VRRFEATUREINDICATOR = "D3DOGL_73314097";
static const char *g_pszMainDocs_VRRFEATUREINDICATOR = "";

static const char * (g_ppszDefineDataNames_VRRFEATUREINDICATOR_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_VRRFEATUREINDICATOR_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_VRRFEATUREINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_VRRFEATUREINDICATOR_DISABLED, 0x0 , "Disable the feature toggle" },
    { (const char **)g_ppszDefineDataNames_VRRFEATUREINDICATOR_ENABLED, 0x1 , "Enable the feature toggle" },
};

DataDefaultDWORD g_aDefaultData_VRRFEATUREINDICATOR[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_VRRFEATUREINDICATOR(
    0x1094f157,
    g_pszKeyName_VRRFEATUREINDICATOR,
    g_pszRemappedName_VRRFEATUREINDICATOR,
    g_pszMainDocs_VRRFEATUREINDICATOR,
    g_pszDefinedWhen_VRRFEATUREINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRRFEATUREINDICATOR, 
    2, 
    g_aDefaultData_VRRFEATUREINDICATOR, 
    1 
);

static const char *g_pszKeyName_VRRINDICATOR = "VRRINDICATOR";
static const char *g_pszDefinedWhen_VRRINDICATOR = "1";
static const char *g_pszRemappedName_VRRINDICATOR = "D3DOGL_1042d483";
static const char *g_pszMainDocs_VRRINDICATOR = "Display the VRR State Indicator";

static const char * (g_ppszDefineDataNames_VRRINDICATOR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VRRINDICATOR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_VRRINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_VRRINDICATOR_OFF, 0x0 , "Disable G-Sync State Indicator" },
    { (const char **)g_ppszDefineDataNames_VRRINDICATOR_ON, 0x1 , "Enable G-Sync State Indicator" },
};

DataDefaultDWORD g_aDefaultData_VRRINDICATOR[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_VRRINDICATOR(
    0x10029538,
    g_pszKeyName_VRRINDICATOR,
    g_pszRemappedName_VRRINDICATOR,
    g_pszMainDocs_VRRINDICATOR,
    g_pszDefinedWhen_VRRINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRRINDICATOR, 
    2, 
    g_aDefaultData_VRRINDICATOR, 
    1 
);

static const char *g_pszKeyName_VRROVERLAYINDICATOR = "VRROVERLAYINDICATOR";
static const char *g_pszDefinedWhen_VRROVERLAYINDICATOR = "1";
static const char *g_pszRemappedName_VRROVERLAYINDICATOR = "D3DOGL_53304097";
static const char *g_pszMainDocs_VRROVERLAYINDICATOR = "";

static const char * (g_ppszDefineDataNames_VRROVERLAYINDICATOR_DISABLED)[] =
{
    "DISABLED",
    "OFF",
    "0",
    "FALSE",
    NULL
};

static const char * (g_ppszDefineDataNames_VRROVERLAYINDICATOR_ENABLED)[] =
{
    "ENABLED",
    "ON",
    "1",
    "TRUE",
    NULL
};

DataValueDWORD g_aDefineData_VRROVERLAYINDICATOR[] =
{
    { (const char **)g_ppszDefineDataNames_VRROVERLAYINDICATOR_DISABLED, 0x0 , "Disable VRR Onverlay" },
    { (const char **)g_ppszDefineDataNames_VRROVERLAYINDICATOR_ENABLED, 0x1 , "Enable VRR Overlay" },
};

DataDefaultDWORD g_aDefaultData_VRROVERLAYINDICATOR[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_VRROVERLAYINDICATOR(
    0x1095f16f,
    g_pszKeyName_VRROVERLAYINDICATOR,
    g_pszRemappedName_VRROVERLAYINDICATOR,
    g_pszMainDocs_VRROVERLAYINDICATOR,
    g_pszDefinedWhen_VRROVERLAYINDICATOR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRROVERLAYINDICATOR, 
    2, 
    g_aDefaultData_VRROVERLAYINDICATOR, 
    1 
);

static const char *g_pszKeyName_VRRREQUESTSTATE = "VRRREQUESTSTATE";
static const char *g_pszDefinedWhen_VRRREQUESTSTATE = "1";
static const char *g_pszRemappedName_VRRREQUESTSTATE = "D3DOGL_73314027";
static const char *g_pszMainDocs_VRRREQUESTSTATE = "";

static const char * (g_ppszDefineDataNames_VRRREQUESTSTATE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VRRREQUESTSTATE_FULLSCREEN_ONLY)[] =
{
    "FULLSCREEN_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_VRRREQUESTSTATE_FULLSCREEN_AND_WINDOWED)[] =
{
    "FULLSCREEN_AND_WINDOWED",
    NULL
};

DataValueDWORD g_aDefineData_VRRREQUESTSTATE[] =
{
    { (const char **)g_ppszDefineDataNames_VRRREQUESTSTATE_DISABLED, 0x0 , "Disable G-Sync" },
    { (const char **)g_ppszDefineDataNames_VRRREQUESTSTATE_FULLSCREEN_ONLY, 0x1 , "Enable G-SYNC in fullscreen mode only" },
    { (const char **)g_ppszDefineDataNames_VRRREQUESTSTATE_FULLSCREEN_AND_WINDOWED, 0x2 , "Enable G-SYNC in fullscreen and windowed modes" },
};

DataDefaultDWORD g_aDefaultData_VRRREQUESTSTATE[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_VRRREQUESTSTATE(
    0x1094f1f7,
    g_pszKeyName_VRRREQUESTSTATE,
    g_pszRemappedName_VRRREQUESTSTATE,
    g_pszMainDocs_VRRREQUESTSTATE,
    g_pszDefinedWhen_VRRREQUESTSTATE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRRREQUESTSTATE, 
    3, 
    g_aDefaultData_VRRREQUESTSTATE, 
    1 
);

static const char *g_pszKeyName_VRR_APP_OVERRIDE = "VRR_APP_OVERRIDE";
static const char *g_pszDefinedWhen_VRR_APP_OVERRIDE = "1";
static const char *g_pszRemappedName_VRR_APP_OVERRIDE = "D3DOGL_60461793";
static const char *g_pszMainDocs_VRR_APP_OVERRIDE = "Profile-specific override. Overrides the VRR_MODE global setting";

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_ALLOW)[] =
{
    "ALLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_DISALLOW)[] =
{
    "DISALLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_ULMB)[] =
{
    "ULMB",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_FIXED_REFRESH)[] =
{
    "FIXED_REFRESH",
    NULL
};

DataValueDWORD g_aDefineData_VRR_APP_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_ALLOW, 0 , "Honor the VRR_MODE setting,G-SYNC On" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_FORCE_OFF, 1 , "G-SYNC cannot be enabled for this app" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_DISALLOW, 2 , "VRR off" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_ULMB, 3 , "ULMB On" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_FIXED_REFRESH, 4 , "Fixed Refresh mode" },
};

DataDefaultDWORD g_aDefaultData_VRR_APP_OVERRIDE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_VRR_APP_OVERRIDE(
    0x10a879cf,
    g_pszKeyName_VRR_APP_OVERRIDE,
    g_pszRemappedName_VRR_APP_OVERRIDE,
    g_pszMainDocs_VRR_APP_OVERRIDE,
    g_pszDefinedWhen_VRR_APP_OVERRIDE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRR_APP_OVERRIDE, 
    5, 
    g_aDefaultData_VRR_APP_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_VRR_APP_OVERRIDE_REQUEST_STATE = "VRR_APP_OVERRIDE_REQUEST_STATE";
static const char *g_pszDefinedWhen_VRR_APP_OVERRIDE_REQUEST_STATE = "1";
static const char *g_pszRemappedName_VRR_APP_OVERRIDE_REQUEST_STATE = "D3DOGL_60461788";
static const char *g_pszMainDocs_VRR_APP_OVERRIDE_REQUEST_STATE = "Profile-specific override. Overrides the VRR_MODE global setting";

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_ALLOW)[] =
{
    "ALLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_DISALLOW)[] =
{
    "DISALLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_ULMB)[] =
{
    "ULMB",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_FIXED_REFRESH)[] =
{
    "FIXED_REFRESH",
    NULL
};

DataValueDWORD g_aDefineData_VRR_APP_OVERRIDE_REQUEST_STATE[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_ALLOW, 0 , "Honor the VRR_MODE setting,G-SYNC On" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_FORCE_OFF, 1 , "G-SYNC cannot be enabled for this app" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_DISALLOW, 2 , "VRR off" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_ULMB, 3 , "ULMB On" },
    { (const char **)g_ppszDefineDataNames_VRR_APP_OVERRIDE_REQUEST_STATE_FIXED_REFRESH, 4 , "Fixed Refresh mode" },
};

DataDefaultDWORD g_aDefaultData_VRR_APP_OVERRIDE_REQUEST_STATE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_VRR_APP_OVERRIDE_REQUEST_STATE(
    0x10a879ac,
    g_pszKeyName_VRR_APP_OVERRIDE_REQUEST_STATE,
    g_pszRemappedName_VRR_APP_OVERRIDE_REQUEST_STATE,
    g_pszMainDocs_VRR_APP_OVERRIDE_REQUEST_STATE,
    g_pszDefinedWhen_VRR_APP_OVERRIDE_REQUEST_STATE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRR_APP_OVERRIDE_REQUEST_STATE, 
    5, 
    g_aDefaultData_VRR_APP_OVERRIDE_REQUEST_STATE, 
    1 
);

static const char *g_pszKeyName_VRR_DEBUG_OVERRIDE = "VRR_DEBUG_OVERRIDE";
static const char *g_pszDefinedWhen_VRR_DEBUG_OVERRIDE = "1";
static const char *g_pszRemappedName_VRR_DEBUG_OVERRIDE = "D3DOGL_72504593";
static const char *g_pszMainDocs_VRR_DEBUG_OVERRIDE = "For debugging G-SYNC, bits to alter behavior";

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_ON)[] =
{
    "FORCE_ON",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_ENABLE_VIDEOBRIDGE)[] =
{
    "ENABLE_VIDEOBRIDGE",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_ENABLE_DWM_SUPPORT)[] =
{
    "ENABLE_DWM_SUPPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_TIMER_OFF)[] =
{
    "FORCE_TIMER_OFF",
    NULL
};

DataValueDWORD g_aDefineData_VRR_DEBUG_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_NONE, 0x00000000 , "Use standard configuration" },
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_ON, 0x00000001 , "Force use of VRR regardless of application profile (unless UNSUPPORTED)" },
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_OFF, 0x00000002 , "Disable use of VRR regardless of application profile" },
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_ENABLE_VIDEOBRIDGE, 0x00000004 , "Allow UMDs to make use of the VideoBridge" },
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_ENABLE_DWM_SUPPORT, 0x00000008 , "Enable with DWM on" },
    { (const char **)g_ppszDefineDataNames_VRR_DEBUG_OVERRIDE_FORCE_TIMER_OFF, 0x00000010 , "Force Timer usage off" },
};

DataDefaultDWORD g_aDefaultData_VRR_DEBUG_OVERRIDE[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_VRR_DEBUG_OVERRIDE(
    0x115fb4e7,
    g_pszKeyName_VRR_DEBUG_OVERRIDE,
    g_pszRemappedName_VRR_DEBUG_OVERRIDE,
    g_pszMainDocs_VRR_DEBUG_OVERRIDE,
    g_pszDefinedWhen_VRR_DEBUG_OVERRIDE,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_VRR_DEBUG_OVERRIDE, 
    6, 
    g_aDefaultData_VRR_DEBUG_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_VRR_MODE = "VRR_MODE";
static const char *g_pszDefinedWhen_VRR_MODE = "1";
static const char *g_pszRemappedName_VRR_MODE = "D3DOGL_73314098";
static const char *g_pszMainDocs_VRR_MODE = "";

static const char * (g_ppszDefineDataNames_VRR_MODE_DISABLED)[] =
{
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_MODE_FULLSCREEN_ONLY)[] =
{
    "FULLSCREEN_ONLY",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_MODE_FULLSCREEN_AND_WINDOWED)[] =
{
    "FULLSCREEN_AND_WINDOWED",
    NULL
};

DataValueDWORD g_aDefineData_VRR_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_MODE_DISABLED, 0x0 , "Disable G-Sync" },
    { (const char **)g_ppszDefineDataNames_VRR_MODE_FULLSCREEN_ONLY, 0x1 , "Enable G-SYNC in fullscreen mode only" },
    { (const char **)g_ppszDefineDataNames_VRR_MODE_FULLSCREEN_AND_WINDOWED, 0x2 , "Enable G-SYNC in fullscreen and windowed modes" },
};

DataDefaultDWORD g_aDefaultData_VRR_MODE[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_VRR_MODE(
    0x1194f158,
    g_pszKeyName_VRR_MODE,
    g_pszRemappedName_VRR_MODE,
    g_pszMainDocs_VRR_MODE,
    g_pszDefinedWhen_VRR_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRR_MODE, 
    3, 
    g_aDefaultData_VRR_MODE, 
    1 
);

static const char *g_pszKeyName_VRR_OVERRIDE_CONTROL = "VRR_OVERRIDE_CONTROL";
static const char *g_pszDefinedWhen_VRR_OVERRIDE_CONTROL = "1";
static const char *g_pszRemappedName_VRR_OVERRIDE_CONTROL = "D3DOGL_72504592";
static const char *g_pszMainDocs_VRR_OVERRIDE_CONTROL = "Override VRR configuration";

static const char * (g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_ON)[] =
{
    "FORCE_ON",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_ENABLE_VIDEOBRIDGE)[] =
{
    "ENABLE_VIDEOBRIDGE",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_ENABLE_DWM_SUPPORT)[] =
{
    "ENABLE_DWM_SUPPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_TIMER_OFF)[] =
{
    "FORCE_TIMER_OFF",
    NULL
};

DataValueDWORD g_aDefineData_VRR_OVERRIDE_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_ON, 0x00000001 , "Force use of VRR regardless of application profile" },
    { (const char **)g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_OFF, 0x00000002 , "Disable use of VRR regardless of application profile" },
    { (const char **)g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_ENABLE_VIDEOBRIDGE, 0x00000004 , "Allow UMDs to make use of the VideoBridge" },
    { (const char **)g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_ENABLE_DWM_SUPPORT, 0x00000008 , "Enable with DWM on" },
    { (const char **)g_ppszDefineDataNames_VRR_OVERRIDE_CONTROL_FORCE_TIMER_OFF, 0x00000010 , "Force Timer usage off" },
};

DataDefaultDWORD g_aDefaultData_VRR_OVERRIDE_CONTROL[] =
{
    {"DEFAULT", 0x00000008, "" }, 
};

SettingDWORD g_setting_VRR_OVERRIDE_CONTROL(
    0x115fb4e6,
    g_pszKeyName_VRR_OVERRIDE_CONTROL,
    g_pszRemappedName_VRR_OVERRIDE_CONTROL,
    g_pszMainDocs_VRR_OVERRIDE_CONTROL,
    g_pszDefinedWhen_VRR_OVERRIDE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_VRR_OVERRIDE_CONTROL, 
    5, 
    g_aDefaultData_VRR_OVERRIDE_CONTROL, 
    1 
);

static const char *g_pszKeyName_VRR_WINDOWED_APP_OVERRIDE = "VRR_WINDOWED_APP_OVERRIDE";
static const char *g_pszDefinedWhen_VRR_WINDOWED_APP_OVERRIDE = "1";
static const char *g_pszRemappedName_VRR_WINDOWED_APP_OVERRIDE = "D3DOGL_60461797";
static const char *g_pszMainDocs_VRR_WINDOWED_APP_OVERRIDE = "Profile-specific override for windowed mode G-SYNC. Overrides the VRR_MODE global setting";

static const char * (g_ppszDefineDataNames_VRR_WINDOWED_APP_OVERRIDE_ALLOW)[] =
{
    "ALLOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VRR_WINDOWED_APP_OVERRIDE_FORCE_OFF)[] =
{
    "FORCE_OFF",
    NULL
};

DataValueDWORD g_aDefineData_VRR_WINDOWED_APP_OVERRIDE[] =
{
    { (const char **)g_ppszDefineDataNames_VRR_WINDOWED_APP_OVERRIDE_ALLOW, 0 , "Honor the VRR_MODE setting, windowed G-SYNC On" },
    { (const char **)g_ppszDefineDataNames_VRR_WINDOWED_APP_OVERRIDE_FORCE_OFF, 1 , "Winowed G-SYNC cannot be enabled for this app" },
};

DataDefaultDWORD g_aDefaultData_VRR_WINDOWED_APP_OVERRIDE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_VRR_WINDOWED_APP_OVERRIDE(
    0x10a879ef,
    g_pszKeyName_VRR_WINDOWED_APP_OVERRIDE,
    g_pszRemappedName_VRR_WINDOWED_APP_OVERRIDE,
    g_pszMainDocs_VRR_WINDOWED_APP_OVERRIDE,
    g_pszDefinedWhen_VRR_WINDOWED_APP_OVERRIDE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VRR_WINDOWED_APP_OVERRIDE, 
    2, 
    g_aDefaultData_VRR_WINDOWED_APP_OVERRIDE, 
    1 
);

static const char *g_pszKeyName_VR_PERF_LEVEL = "VR_PERF_LEVEL";
static const char *g_pszDefinedWhen_VR_PERF_LEVEL = "1";
static const char *g_pszRemappedName_VR_PERF_LEVEL = "D3DOGL_D0018600";
static const char *g_pszMainDocs_VR_PERF_LEVEL = "Requirement ID 10 - Regkey setting to set power modes";

static const char * (g_ppszDefineDataNames_VR_PERF_LEVEL_POWER_SAVINGS)[] =
{
    "POWER_SAVINGS",
    NULL
};

static const char * (g_ppszDefineDataNames_VR_PERF_LEVEL_SUSTAINED_LOW)[] =
{
    "SUSTAINED_LOW",
    NULL
};

static const char * (g_ppszDefineDataNames_VR_PERF_LEVEL_SUSTAINED_HIGH)[] =
{
    "SUSTAINED_HIGH",
    NULL
};

static const char * (g_ppszDefineDataNames_VR_PERF_LEVEL_BOOST)[] =
{
    "BOOST",
    NULL
};

static const char * (g_ppszDefineDataNames_VR_PERF_LEVEL_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_VR_PERF_LEVEL[] =
{
    { (const char **)g_ppszDefineDataNames_VR_PERF_LEVEL_POWER_SAVINGS, 0 , "" },
    { (const char **)g_ppszDefineDataNames_VR_PERF_LEVEL_SUSTAINED_LOW, 25 , "" },
    { (const char **)g_ppszDefineDataNames_VR_PERF_LEVEL_SUSTAINED_HIGH, 50 , "" },
    { (const char **)g_ppszDefineDataNames_VR_PERF_LEVEL_BOOST, 75 , "" },
    { (const char **)g_ppszDefineDataNames_VR_PERF_LEVEL_MAX, 100 , "" },
};

DataDefaultDWORD g_aDefaultData_VR_PERF_LEVEL[] =
{
    {"DEFAULT", 75, "" }, 
};

SettingDWORD g_setting_VR_PERF_LEVEL(
    0x10834f08,
    g_pszKeyName_VR_PERF_LEVEL,
    g_pszRemappedName_VR_PERF_LEVEL,
    g_pszMainDocs_VR_PERF_LEVEL,
    g_pszDefinedWhen_VR_PERF_LEVEL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_VR_PERF_LEVEL, 
    5, 
    g_aDefaultData_VR_PERF_LEVEL, 
    1 
);

static const char *g_pszKeyName_VSYNCSMOOTHAFR = "VSYNCSMOOTHAFR";
static const char *g_pszDefinedWhen_VSYNCSMOOTHAFR = "1";
static const char *g_pszRemappedName_VSYNCSMOOTHAFR = "D3DOGL_09090919";
static const char *g_pszMainDocs_VSYNCSMOOTHAFR = "Key to control smooth AFR mode";

static const char * (g_ppszDefineDataNames_VSYNCSMOOTHAFR_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_VSYNCSMOOTHAFR_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_VSYNCSMOOTHAFR[] =
{
    { (const char **)g_ppszDefineDataNames_VSYNCSMOOTHAFR_OFF, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_VSYNCSMOOTHAFR_ON, 0x00000001 , "" },
};

DataDefaultDWORD g_aDefaultData_VSYNCSMOOTHAFR[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_VSYNCSMOOTHAFR(
    0x101ae763,
    g_pszKeyName_VSYNCSMOOTHAFR,
    g_pszRemappedName_VSYNCSMOOTHAFR,
    g_pszMainDocs_VSYNCSMOOTHAFR,
    g_pszDefinedWhen_VSYNCSMOOTHAFR,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VSYNCSMOOTHAFR, 
    2, 
    g_aDefaultData_VSYNCSMOOTHAFR, 
    1 
);

static const char *g_pszKeyName_VSYNCVRRCONTROL = "VSYNCVRRCONTROL";
static const char *g_pszDefinedWhen_VSYNCVRRCONTROL = "1";
static const char *g_pszRemappedName_VSYNCVRRCONTROL = "D3DOGL_60461792";
static const char *g_pszMainDocs_VSYNCVRRCONTROL = "Controls enabling or disabling VRR for OGL or D3D";

static const char * (g_ppszDefineDataNames_VSYNCVRRCONTROL_DISABLE)[] =
{
    "DISABLE",
    "FALSE",
    "0",
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_VSYNCVRRCONTROL_ENABLE)[] =
{
    "ENABLE",
    "TRUE",
    "1",
    "ON",
    NULL
};

static const char * (g_ppszDefineDataNames_VSYNCVRRCONTROL_NOTSUPPORTED)[] =
{
    "NOTSUPPORTED",
    "NONE",
    NULL
};

DataValueDWORD g_aDefineData_VSYNCVRRCONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_VSYNCVRRCONTROL_DISABLE, 0x00000000 , "VRR off" },
    { (const char **)g_ppszDefineDataNames_VSYNCVRRCONTROL_ENABLE, 0x00000001 , "VRR on" },
    { (const char **)g_ppszDefineDataNames_VSYNCVRRCONTROL_NOTSUPPORTED, 0x9f95128e , "VRR not supported" },
};

DataDefaultDWORD g_aDefaultData_VSYNCVRRCONTROL[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_VSYNCVRRCONTROL(
    0x10a879ce,
    g_pszKeyName_VSYNCVRRCONTROL,
    g_pszRemappedName_VSYNCVRRCONTROL,
    g_pszMainDocs_VSYNCVRRCONTROL,
    g_pszDefinedWhen_VSYNCVRRCONTROL,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VSYNCVRRCONTROL, 
    3, 
    g_aDefaultData_VSYNCVRRCONTROL, 
    1 
);

static const char *g_pszKeyName_VSYNC_BEHAVIOR_FLAGS = "VSYNC_BEHAVIOR_FLAGS";
static const char *g_pszDefinedWhen_VSYNC_BEHAVIOR_FLAGS = "1";
static const char *g_pszRemappedName_VSYNC_BEHAVIOR_FLAGS = "D3DOGL_00fdec23";
static const char *g_pszMainDocs_VSYNC_BEHAVIOR_FLAGS = "Flags for altering how the driver interprets VSYNC";

static const char * (g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_IGNORE_FLIPINTERVAL_MULTIPLE)[] =
{
    "IGNORE_FLIPINTERVAL_MULTIPLE",
    NULL
};

DataValueDWORD g_aDefineData_VSYNC_BEHAVIOR_FLAGS[] =
{
    { (const char **)g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_NONE, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_DEFAULT, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_VSYNC_BEHAVIOR_FLAGS_IGNORE_FLIPINTERVAL_MULTIPLE, 0x00000001 , "Ignore flip interval when it is greater than 1. Usually, it is used on CPL half refresh rates." },
};

DataDefaultDWORD g_aDefaultData_VSYNC_BEHAVIOR_FLAGS[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_VSYNC_BEHAVIOR_FLAGS(
    0x10fdec23,
    g_pszKeyName_VSYNC_BEHAVIOR_FLAGS,
    g_pszRemappedName_VSYNC_BEHAVIOR_FLAGS,
    g_pszMainDocs_VSYNC_BEHAVIOR_FLAGS,
    g_pszDefinedWhen_VSYNC_BEHAVIOR_FLAGS,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_VSYNC_BEHAVIOR_FLAGS, 
    3, 
    g_aDefaultData_VSYNC_BEHAVIOR_FLAGS, 
    1 
);

static const char *g_pszKeyName_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW = "WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW";
static const char *g_pszDefinedWhen_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW = "1";
static const char *g_pszRemappedName_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW = "D3DOGL_0xfbdf11";
static const char *g_pszMainDocs_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW = "Number of Sources we can extend on Single GPU";

static const char * (g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE)[] =
{
    "SOURCE_ONE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_TWO)[] =
{
    "SOURCE_TWO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_THREE)[] =
{
    "SOURCE_THREE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_FOUR)[] =
{
    "SOURCE_FOUR",
    NULL
};

DataValueDWORD g_aDefineData_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE, 0x1 , "One Source per GPU" },
    { (const char **)g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_TWO, 0x2 , "Two Sources per GPU" },
    { (const char **)g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_THREE, 0x3 , "Three Sources per GPU" },
    { (const char **)g_ppszDefineDataNames_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_FOUR, 0x4 , "Four Sources per GPU" },
};

DataDefaultDWORD g_aDefaultData_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW(
    0x11fbdf11,
    g_pszKeyName_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW,
    g_pszRemappedName_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW,
    g_pszMainDocs_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW,
    g_pszDefinedWhen_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW, 
    4, 
    g_aDefaultData_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW, 
    1 
);

static const char *g_pszKeyName_WKS_API_STEREO_EYES_EXCHANGE = "WKS_API_STEREO_EYES_EXCHANGE";
static const char *g_pszDefinedWhen_WKS_API_STEREO_EYES_EXCHANGE = "1";
static const char *g_pszRemappedName_WKS_API_STEREO_EYES_EXCHANGE = "D3DOGL_APIStereoEyesExchange";
static const char *g_pszMainDocs_WKS_API_STEREO_EYES_EXCHANGE = "Swaps image for the left eye with image for the right eye";

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_EYES_EXCHANGE_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_EYES_EXCHANGE_ON)[] =
{
    "ON",
    NULL
};

DataValueDWORD g_aDefineData_WKS_API_STEREO_EYES_EXCHANGE[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_EYES_EXCHANGE_OFF, 0 , "Stereo eyes exchange off" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_EYES_EXCHANGE_ON, 1 , "Stereo eyes exchange on" },
};

DataDefaultDWORD g_aDefaultData_WKS_API_STEREO_EYES_EXCHANGE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_WKS_API_STEREO_EYES_EXCHANGE(
    0x11ae435c,
    g_pszKeyName_WKS_API_STEREO_EYES_EXCHANGE,
    g_pszRemappedName_WKS_API_STEREO_EYES_EXCHANGE,
    g_pszMainDocs_WKS_API_STEREO_EYES_EXCHANGE,
    g_pszDefinedWhen_WKS_API_STEREO_EYES_EXCHANGE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_API_STEREO_EYES_EXCHANGE, 
    2, 
    g_aDefaultData_WKS_API_STEREO_EYES_EXCHANGE, 
    1 
);

static const char *g_pszKeyName_WKS_API_STEREO_MODE = "WKS_API_STEREO_MODE";
static const char *g_pszDefinedWhen_WKS_API_STEREO_MODE = "1";
static const char *g_pszRemappedName_WKS_API_STEREO_MODE = "D3DOGL_APIStereoMode";
static const char *g_pszMainDocs_WKS_API_STEREO_MODE = "Display mode to use when stereo is enabled";

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_SHUTTER_GLASSES)[] =
{
    "SHUTTER_GLASSES",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_VERTICAL_INTERLACED)[] =
{
    "VERTICAL_INTERLACED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_TWINVIEW)[] =
{
    "TWINVIEW",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO)[] =
{
    "NV17_SHUTTER_GLASSES_AUTO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0)[] =
{
    "NV17_SHUTTER_GLASSES_DAC0",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1)[] =
{
    "NV17_SHUTTER_GLASSES_DAC1",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_COLOR_LINE)[] =
{
    "COLOR_LINE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_COLOR_INTERLEAVED)[] =
{
    "COLOR_INTERLEAVED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_ANAGLYPH)[] =
{
    "ANAGLYPH",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED)[] =
{
    "HORIZONTAL_INTERLACED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_SIDE_FIELD)[] =
{
    "SIDE_FIELD",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_SUB_FIELD)[] =
{
    "SUB_FIELD",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_CHECKERBOARD)[] =
{
    "CHECKERBOARD",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD)[] =
{
    "INVERSE_CHECKERBOARD",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_TRIDELITY_SL)[] =
{
    "TRIDELITY_SL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_TRIDELITY_MV)[] =
{
    "TRIDELITY_MV",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_SEEFRONT)[] =
{
    "SEEFRONT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_STEREO_MIRROR)[] =
{
    "STEREO_MIRROR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_FRAME_SEQUENTIAL)[] =
{
    "FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE)[] =
{
    "AUTODETECT_PASSIVE_MODE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL)[] =
{
    "AEGIS_DT_FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL)[] =
{
    "OEM_EMITTER_FRAME_SEQUENTIAL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_DP_INBAND)[] =
{
    "DP_INBAND",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_USE_HW_DEFAULT)[] =
{
    "USE_HW_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_MODE_DEFAULT_GL)[] =
{
    "DEFAULT_GL",
    NULL
};

DataValueDWORD g_aDefineData_WKS_API_STEREO_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_SHUTTER_GLASSES, 0 , "Active stereo mode frame interleaved shutter glasses via DDC adapter shutter glasses (ELSA Revelator)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_VERTICAL_INTERLACED, 1 , "Passive stereo mode vertical interlaced" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_TWINVIEW, 2 , "Passive stereo mode clone mode" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO, 3 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN auto" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0, 4 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC0" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1, 5 , "Active stereo mode frame interleaved shutter glasses via 3-pin mini-DIN DAC1" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_COLOR_LINE, 6 , "Active stereo mode frame interleaved shutter glasses via blue line adapter (StereoGraphics)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_COLOR_INTERLEAVED, 7 , "Passive stereo mode color interleaved (Sharp 3D)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_ANAGLYPH, 8 , "Passive stereo mode colored anaglyph (left:red right:cyan(blue+green))" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED, 9 , "Passive stereo mode horizontal interlaced (Arisawa/Hyundai/Zalman/Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_SIDE_FIELD, 10 , "Passive stereo mode vertical subfield (Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_SUB_FIELD, 11 , "Passive stereo mode horizontal subfield (Pavione/Miracube)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_CHECKERBOARD, 12 , "Passive stereo mode checkerboard pattern (3D DLP)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD, 13 , "Passive stereo mode inverse checkerboard pattern (3D DLP)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_TRIDELITY_SL, 14 , "Passive stereo mode line-wise biased vertical interlaced (Tridelity SL/SV -> SingleView)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_TRIDELITY_MV, 15 , "Passive stereo mode slanted line-wise biased vertical interlaced 5 view (Tridelity MV -> MultiView)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_SEEFRONT, 16 , "Passive stereo mode using Seefront pattern (SeeFront)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_STEREO_MIRROR, 17 , "Passive stereo mode clone mode with right eye mirrored (Planar)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_FRAME_SEQUENTIAL, 18 , "Active stereo mode frame interleaved (NVIDIA 3D Vision)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE, 19 , "Passive stereo mode autodetected by monitor capabilities" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL, 20 , "Active stereo mode frame interleaved (NVIDIA AegisDT embedded emitter)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL, 21 , "Active stereo mode frame interleaved (GPIO connected OEM emitter)" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_DP_INBAND, 22 , "Active stereo mode frame interleaved via DisplayPort inband MSA signal" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_USE_HW_DEFAULT, 0xffffffff , "Select hardware default based on capabilities" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_MODE_DEFAULT_GL, 3 , "Default for Quadro: NV17_SHUTTER_GLASSES_AUTO" },
};

DataDefaultDWORD g_aDefaultData_WKS_API_STEREO_MODE[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_WKS_API_STEREO_MODE(
    0x11e91a61,
    g_pszKeyName_WKS_API_STEREO_MODE,
    g_pszRemappedName_WKS_API_STEREO_MODE,
    g_pszMainDocs_WKS_API_STEREO_MODE,
    g_pszDefinedWhen_WKS_API_STEREO_MODE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_API_STEREO_MODE, 
    25, 
    g_aDefaultData_WKS_API_STEREO_MODE, 
    1 
);

static const char *g_pszKeyName_WKS_API_STEREO_OSD = "WKS_API_STEREO_OSD";
static const char *g_pszDefinedWhen_WKS_API_STEREO_OSD = "1";
static const char *g_pszRemappedName_WKS_API_STEREO_OSD = "D3DOGL_STEREO_OSD";
static const char *g_pszMainDocs_WKS_API_STEREO_OSD = "";

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_OSD_USE_DRIVER_DEFAULT)[] =
{
    "USE_DRIVER_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_OSD_FORCE_ENABLE)[] =
{
    "FORCE_ENABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_OSD_FORCE_DISABLE)[] =
{
    "FORCE_DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_OSD_MIN)[] =
{
    "MIN",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_API_STEREO_OSD_MAX)[] =
{
    "MAX",
    NULL
};

DataValueDWORD g_aDefineData_WKS_API_STEREO_OSD[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_OSD_USE_DRIVER_DEFAULT, 0x00000000 , "dont change driver strategy" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_OSD_FORCE_ENABLE, 0x00000001 , "turn on OSD rendering" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_OSD_FORCE_DISABLE, 0x00000002 , "turn off OSD rendering" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_OSD_MIN, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_WKS_API_STEREO_OSD_MAX, 0x00000002 , "" },
};

DataDefaultDWORD g_aDefaultData_WKS_API_STEREO_OSD[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_WKS_API_STEREO_OSD(
    0x10deadee,
    g_pszKeyName_WKS_API_STEREO_OSD,
    g_pszRemappedName_WKS_API_STEREO_OSD,
    g_pszMainDocs_WKS_API_STEREO_OSD,
    g_pszDefinedWhen_WKS_API_STEREO_OSD,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_API_STEREO_OSD, 
    5, 
    g_aDefaultData_WKS_API_STEREO_OSD, 
    1 
);

static const char *g_pszKeyName_WKS_CLIENT_ARBITRATION_LOGGING = "WKS_CLIENT_ARBITRATION_LOGGING";
static const char *g_pszDefinedWhen_WKS_CLIENT_ARBITRATION_LOGGING = "1";
static const char *g_pszRemappedName_WKS_CLIENT_ARBITRATION_LOGGING = "D3DOGL_WksLogging";
static const char *g_pszMainDocs_WKS_CLIENT_ARBITRATION_LOGGING = "";

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_ON)[] =
{
    "ON",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_DUMP)[] =
{
    "DBG_DUMP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_LOGS)[] =
{
    "DBG_RESTRICT_LOGS",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_ALL)[] =
{
    "DBG_RESTRICT_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_SWAPGROUP)[] =
{
    "SWAPGROUP",
    NULL
};

DataValueDWORD g_aDefineData_WKS_CLIENT_ARBITRATION_LOGGING[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_OFF, 0 , "don't log" },
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_ON, 1 , "log" },
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_DUMP, 2 , "dump the data to debug" },
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_LOGS, 4 , "restrict non-clientArb event logs" },
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_ALL, 8 , "restrict all non-clientArb logs" },
    { (const char **)g_ppszDefineDataNames_WKS_CLIENT_ARBITRATION_LOGGING_SWAPGROUP, 16 , "log Swapgroup Info" },
};

DataDefaultDWORD g_aDefaultData_WKS_CLIENT_ARBITRATION_LOGGING[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_WKS_CLIENT_ARBITRATION_LOGGING(
    0x11e21a53,
    g_pszKeyName_WKS_CLIENT_ARBITRATION_LOGGING,
    g_pszRemappedName_WKS_CLIENT_ARBITRATION_LOGGING,
    g_pszMainDocs_WKS_CLIENT_ARBITRATION_LOGGING,
    g_pszDefinedWhen_WKS_CLIENT_ARBITRATION_LOGGING,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_CLIENT_ARBITRATION_LOGGING, 
    6, 
    g_aDefaultData_WKS_CLIENT_ARBITRATION_LOGGING, 
    1 
);

static const char *g_pszKeyName_WKS_CURSOR_MODE = "WKS_CURSOR_MODE";
static const char *g_pszDefinedWhen_WKS_CURSOR_MODE = "1";
static const char *g_pszRemappedName_WKS_CURSOR_MODE = "D3DOGL_WksCursor";
static const char *g_pszMainDocs_WKS_CURSOR_MODE = "Control of workstation cursor";

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_TYPE_MASK)[] =
{
    "CURSOR_TYPE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_SW_CURSOR)[] =
{
    "SW_CURSOR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CPU_POSITION_WARP)[] =
{
    "CPU_POSITION_WARP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_SOC_EMULATED_CURSOR)[] =
{
    "SOC_EMULATED_CURSOR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_COMBINED_CURSOR)[] =
{
    "COMBINED_CURSOR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_METHOD_MASK)[] =
{
    "REDRAW_METHOD_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_SETPIXEL)[] =
{
    "REDRAW_SETPIXEL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_RENDER_BEFORE_FLIP)[] =
{
    "REDRAW_RENDER_BEFORE_FLIP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_DESKTOP)[] =
{
    "REDRAW_DESKTOP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_CURSOR_SHAPE_MASK)[] =
{
    "REPLACE_CURSOR_SHAPE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_OFF)[] =
{
    "REPLACE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_ON)[] =
{
    "REPLACE_ON",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_MASK)[] =
{
    "CURSOR_INFO_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_OFF)[] =
{
    "CURSOR_INFO_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_HW)[] =
{
    "CURSOR_INFO_HW",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_SOC)[] =
{
    "CURSOR_INFO_SOC",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_WARP)[] =
{
    "CURSOR_INFO_WARP",
    NULL
};

DataValueDWORD g_aDefineData_WKS_CURSOR_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_TYPE_MASK, 0x0000F , "which bits tell us the cursor type to use" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_SW_CURSOR, 0x00001 , "OS SW cursor" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CPU_POSITION_WARP, 0x00002 , "HW cursor with position adjustment calculated by CPU when warping is enabled, but no shape adjustment" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_SOC_EMULATED_CURSOR, 0x00003 , "NO HW cursor, but cursor emulated by blending cursor shape on scanoutComposition present" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_COMBINED_CURSOR, 0x00004 , "Combined mode that DWM flipping uses SW_CURSOR, app flipping uses REDRAW_DESKTOP (only on WDDM2)" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_METHOD_MASK, 0x000F0 , "which bits tell us the redrawing method to trigger cursor drawing" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_SETPIXEL, 0x00010 , "use set pixel to trigger the scanout composition pipeline" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_RENDER_BEFORE_FLIP, 0x00020 , "use render before flip call to trigger the scanout composition pipeline, draws directly to the primary" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REDRAW_DESKTOP, 0x00040 , "use redraw window to trigger the scanout composition pipeline" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_CURSOR_SHAPE_MASK, 0x00F00 , "which bits tell us whether replacing cursor shape with pre-defined shape when CPU_POSITION_WARP is set" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_OFF, 0x00000 , "do not replace the cursor shape with pre-defined shape" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_REPLACE_ON, 0x00100 , "replace cursor shape with pre-defined shape" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_MASK, 0x0F000 , "mask which bits are responsible to select a cursor shape tagging with type indicator" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_OFF, 0x00000 , "no visible cursor shape tagging" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_HW, 0x01000 , "tag gpu 'H'w cursor with a 'H' in the lower right corner (not rotation aware)" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_SOC, 0x02000 , "tag so'C' emulated cursor with a 'S' in the lower right corner (not rotation aware)" },
    { (const char **)g_ppszDefineDataNames_WKS_CURSOR_MODE_CURSOR_INFO_WARP, 0x04000 , "tag gpu hw cursor 'W'arp shape replacement with a 'W' in the lower right corner (not rotation aware)" },
};

DataDefaultDWORD g_aDefaultData_WKS_CURSOR_MODE[] =
{
    {"DEFAULT", 0x00000023, "REDRAW_RENDER_BEFORE_FLIP | SOC_EMULATED_CURSOR" }, 
};

SettingDWORD g_setting_WKS_CURSOR_MODE(
    0x11e21666,
    g_pszKeyName_WKS_CURSOR_MODE,
    g_pszRemappedName_WKS_CURSOR_MODE,
    g_pszMainDocs_WKS_CURSOR_MODE,
    g_pszDefinedWhen_WKS_CURSOR_MODE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_CURSOR_MODE, 
    17, 
    g_aDefaultData_WKS_CURSOR_MODE, 
    1 
);

static const char *g_pszKeyName_WKS_DEEP_COLOR_DWM_CONTROL = "WKS_DEEP_COLOR_DWM_CONTROL";
static const char *g_pszDefinedWhen_WKS_DEEP_COLOR_DWM_CONTROL = "1";
static const char *g_pszRemappedName_WKS_DEEP_COLOR_DWM_CONTROL = "D3DOGL_WksDeepColorDWMControl";
static const char *g_pszMainDocs_WKS_DEEP_COLOR_DWM_CONTROL = "Workaround to disable DWM RGBA8_TO_RGB10A2 format spoofing due to remote connection issues.";

static const char * (g_ppszDefineDataNames_WKS_DEEP_COLOR_DWM_CONTROL_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_DEEP_COLOR_DWM_CONTROL_DISABLE_RGB10A2_SPOOFING)[] =
{
    "DISABLE_RGB10A2_SPOOFING",
    NULL
};

DataValueDWORD g_aDefineData_WKS_DEEP_COLOR_DWM_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_DEEP_COLOR_DWM_CONTROL_OFF, 0x00000000 , "No workaraound enabled." },
    { (const char **)g_ppszDefineDataNames_WKS_DEEP_COLOR_DWM_CONTROL_DISABLE_RGB10A2_SPOOFING, 0x00000001 , "If set the default for primary format does not allow RGB10A2 spoofing." },
};

DataDefaultDWORD g_aDefaultData_WKS_DEEP_COLOR_DWM_CONTROL[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_WKS_DEEP_COLOR_DWM_CONTROL(
    0x11c21ee5,
    g_pszKeyName_WKS_DEEP_COLOR_DWM_CONTROL,
    g_pszRemappedName_WKS_DEEP_COLOR_DWM_CONTROL,
    g_pszMainDocs_WKS_DEEP_COLOR_DWM_CONTROL,
    g_pszDefinedWhen_WKS_DEEP_COLOR_DWM_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_DEEP_COLOR_DWM_CONTROL, 
    2, 
    g_aDefaultData_WKS_DEEP_COLOR_DWM_CONTROL, 
    1 
);

static const char *g_pszKeyName_WKS_DISPLAY_REARRANGEMENT_WITHIN16K = "WKS_DISPLAY_REARRANGEMENT_WITHIN16K";
static const char *g_pszDefinedWhen_WKS_DISPLAY_REARRANGEMENT_WITHIN16K = "1";
static const char *g_pszRemappedName_WKS_DISPLAY_REARRANGEMENT_WITHIN16K = "D3DOGL_DisplayRearrangement";
static const char *g_pszMainDocs_WKS_DISPLAY_REARRANGEMENT_WITHIN16K = "Displays rearrangement when crossed overall 16K resolution limit enabled or not";

static const char * (g_ppszDefineDataNames_WKS_DISPLAY_REARRANGEMENT_WITHIN16K_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_DISPLAY_REARRANGEMENT_WITHIN16K_ON)[] =
{
    "ON",
    NULL
};

DataValueDWORD g_aDefineData_WKS_DISPLAY_REARRANGEMENT_WITHIN16K[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_DISPLAY_REARRANGEMENT_WITHIN16K_OFF, 0x0 , "Displays rearrangement off" },
    { (const char **)g_ppszDefineDataNames_WKS_DISPLAY_REARRANGEMENT_WITHIN16K_ON, 0x1 , "Display rearrangement on" },
};

DataDefaultDWORD g_aDefaultData_WKS_DISPLAY_REARRANGEMENT_WITHIN16K[] =
{
    {"DEFAULT", 0x1, "" }, 
};

SettingDWORD g_setting_WKS_DISPLAY_REARRANGEMENT_WITHIN16K(
    0x10d91a4c,
    g_pszKeyName_WKS_DISPLAY_REARRANGEMENT_WITHIN16K,
    g_pszRemappedName_WKS_DISPLAY_REARRANGEMENT_WITHIN16K,
    g_pszMainDocs_WKS_DISPLAY_REARRANGEMENT_WITHIN16K,
    g_pszDefinedWhen_WKS_DISPLAY_REARRANGEMENT_WITHIN16K,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_DISPLAY_REARRANGEMENT_WITHIN16K, 
    2, 
    g_aDefaultData_WKS_DISPLAY_REARRANGEMENT_WITHIN16K, 
    1 
);

static const char *g_pszKeyName_WKS_DX_SWAPGROUPS = "WKS_DX_SWAPGROUPS";
static const char *g_pszDefinedWhen_WKS_DX_SWAPGROUPS = "1";
static const char *g_pszRemappedName_WKS_DX_SWAPGROUPS = "D3DOGL_WKS_DX_SWAPGROUPS";
static const char *g_pszMainDocs_WKS_DX_SWAPGROUPS = "";

static const char * (g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_USE_DRIVER_DEFAULT)[] =
{
    "USE_DRIVER_DEFAULT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_FORCE_NVAPI_FLIP_WAIT)[] =
{
    "FORCE_NVAPI_FLIP_WAIT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_PRE_PRESENT_WAIT)[] =
{
    "PRE_PRESENT_WAIT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_FORCE_WAIT_PREVIOUS_PRESENT)[] =
{
    "FORCE_WAIT_PREVIOUS_PRESENT",
    NULL
};

DataValueDWORD g_aDefineData_WKS_DX_SWAPGROUPS[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_USE_DRIVER_DEFAULT, 0x00000004 , "dont change driver strategy" },
    { (const char **)g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_FORCE_NVAPI_FLIP_WAIT, 0x00000001 , "Force the driver not to wait on the flip event in the present, but rather in NVAPI" },
    { (const char **)g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_PRE_PRESENT_WAIT, 0x00000002 , "If bit is set, dx swapgroup wait before present." },
    { (const char **)g_ppszDefineDataNames_WKS_DX_SWAPGROUPS_FORCE_WAIT_PREVIOUS_PRESENT, 0x00000004 , "If bit is set, force dx presentBarrier to wait for previous present" },
};

DataDefaultDWORD g_aDefaultData_WKS_DX_SWAPGROUPS[] =
{
    {"DEFAULT", 0x00000004, "" }, 
};

SettingDWORD g_setting_WKS_DX_SWAPGROUPS(
    0x10dead12,
    g_pszKeyName_WKS_DX_SWAPGROUPS,
    g_pszRemappedName_WKS_DX_SWAPGROUPS,
    g_pszMainDocs_WKS_DX_SWAPGROUPS,
    g_pszDefinedWhen_WKS_DX_SWAPGROUPS,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_DX_SWAPGROUPS, 
    4, 
    g_aDefaultData_WKS_DX_SWAPGROUPS, 
    1 
);

static const char *g_pszKeyName_WKS_FEATURE_DEBUG_CONTROL = "WKS_FEATURE_DEBUG_CONTROL";
static const char *g_pszDefinedWhen_WKS_FEATURE_DEBUG_CONTROL = "1";
static const char *g_pszRemappedName_WKS_FEATURE_DEBUG_CONTROL = "D3DOGL_WksFeatureDebugControl";
static const char *g_pszMainDocs_WKS_FEATURE_DEBUG_CONTROL = "Scanout composition backend debug helper controls.";

static const char * (g_ppszDefineDataNames_WKS_FEATURE_DEBUG_CONTROL_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_DEBUG_CONTROL_ENABLE_HDR_INDICATOR)[] =
{
    "ENABLE_HDR_INDICATOR",
    NULL
};

DataValueDWORD g_aDefineData_WKS_FEATURE_DEBUG_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_DEBUG_CONTROL_OFF, 0x00000000 , "No debug helper enabled." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_DEBUG_CONTROL_ENABLE_HDR_INDICATOR, 0x00000001 , "If set the scanout composition HDR indicator is enabled: showing 2 color encoded 20x20 pixel big rectangles are shown on the top left corner of the hdr scanout buffer." },
};

DataDefaultDWORD g_aDefaultData_WKS_FEATURE_DEBUG_CONTROL[] =
{
    {"DEFAULT", 0x00000000, "" }, 
};

SettingDWORD g_setting_WKS_FEATURE_DEBUG_CONTROL(
    0x11e21667,
    g_pszKeyName_WKS_FEATURE_DEBUG_CONTROL,
    g_pszRemappedName_WKS_FEATURE_DEBUG_CONTROL,
    g_pszMainDocs_WKS_FEATURE_DEBUG_CONTROL,
    g_pszDefinedWhen_WKS_FEATURE_DEBUG_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_FEATURE_DEBUG_CONTROL, 
    2, 
    g_aDefaultData_WKS_FEATURE_DEBUG_CONTROL, 
    1 
);

static const char *g_pszKeyName_WKS_FEATURE_SUPPORT_CONTROL = "WKS_FEATURE_SUPPORT_CONTROL";
static const char *g_pszDefinedWhen_WKS_FEATURE_SUPPORT_CONTROL = "1";
static const char *g_pszRemappedName_WKS_FEATURE_SUPPORT_CONTROL = "D3DOGL_WorkstationFeatureControl";
static const char *g_pszMainDocs_WKS_FEATURE_SUPPORT_CONTROL = "NV private interface to enable/disable workstation features";

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO)[] =
{
    "SRS_1714_WIN8_STEREO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED)[] =
{
    "WIN8_STEREO_EXPORT_IF_ENABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_HDMI_STEREO)[] =
{
    "HDMI_STEREO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_HDMI_EXCLUSIVE_STEREO)[] =
{
    "HDMI_EXCLUSIVE_STEREO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_USE_ANY_FRAME_FLIP_STEREO_MODE_FOR_TFP_AND_SWAPGROUP)[] =
{
    "USE_ANY_FRAME_FLIP_STEREO_MODE_FOR_TFP_AND_SWAPGROUP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ALLOW_SPLIT_STEREO_PRESENT_BLITS)[] =
{
    "ALLOW_SPLIT_STEREO_PRESENT_BLITS",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DEEP_COLOR_SUPPORT)[] =
{
    "DISABLE_DEEP_COLOR_SUPPORT",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION)[] =
{
    "DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_ALL)[] =
{
    "ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_ALL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING)[] =
{
    "DISABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_SCANOUT_COMP_IFLIP)[] =
{
    "DISABLE_SCANOUT_COMP_IFLIP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_CSC_FOR_NON_DWM_PRIMARIES)[] =
{
    "DISABLE_CSC_FOR_NON_DWM_PRIMARIES",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DWM_STEREO_DFLIP)[] =
{
    "DISABLE_DWM_STEREO_DFLIP",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES)[] =
{
    "DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_EXPORT_HIGH_COLOR_CAPS_ON_10BPC_DISPLAYS)[] =
{
    "EXPORT_HIGH_COLOR_CAPS_ON_10BPC_DISPLAYS",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_NON_DWM)[] =
{
    "DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_NON_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_DWM)[] =
{
    "DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SWAPGROUP_DWM_FLIP_BROADCASTING)[] =
{
    "ENABLE_SWAPGROUP_DWM_FLIP_BROADCASTING",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_ENFORCE_DIN_SIGNAL)[] =
{
    "WIN8_STEREO_ENFORCE_DIN_SIGNAL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SMOOTHSCALING_SUPPORT_ON_QUADRO)[] =
{
    "ENABLE_SMOOTHSCALING_SUPPORT_ON_QUADRO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_DL_DSR_SUPPORT_ON_QUADRO)[] =
{
    "ENABLE_DL_DSR_SUPPORT_ON_QUADRO",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_STEREO_OUTPUT_CONTROL_OVERRIDE)[] =
{
    "DISALLOW_STEREO_OUTPUT_CONTROL_OVERRIDE",
    NULL
};

DataValueDWORD g_aDefineData_WKS_FEATURE_SUPPORT_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_OFF, 0x00000000 , "No workstation features controled by this key enabled yet" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO, 0x00000001 , "Enable wks stereo for native dx11 Win8 stereo" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED, 0x00000002 , "Export wddm 1.2 stereo modes only if wks stereo is enabled" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_HDMI_STEREO, 0x00000004 , "Enables HDMI stereo by overriding any suitable display mode to stereo" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_HDMI_EXCLUSIVE_STEREO, 0x00000008 , "Enables stereo just on HDMI displays (requires HDMI_STEREO)" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_USE_ANY_FRAME_FLIP_STEREO_MODE_FOR_TFP_AND_SWAPGROUP, 0x00000020 , "Use ANY_FRAME instead of PAIR_FLIP flipping mode on Kepler when tearfree or swapgroup is enabled" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ALLOW_SPLIT_STEREO_PRESENT_BLITS, 0x00000040 , "Allow split stereo present blits to avoid tearing on the right-eye" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DEEP_COLOR_SUPPORT, 0x00000080 , "If bit is set, don't allow scanout from 10bpc buffer (create no dwm/gdi 10bpc primary buffer)" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION, 0x00000100 , "If bit is set win8 stereo modes are exported with their real refreshrate (and not refreshrate/2)" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_ALL, 0x00000200 , "If bit is set vipn blanking is forced for all vidpnownership changes (per default this is done for resource preallocation only)." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING, 0x00000400 , "If bit is set vipn blanking is not skipped (per default this is done for resource preallocation). Overrides ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_FULL." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_SCANOUT_COMP_IFLIP, 0x00000800 , "If bit is set, don't allow scanoutComposition on iFlip on WDDM2" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_CSC_FOR_NON_DWM_PRIMARIES, 0x00001000 , "If bit is set sw emulated color space conversion operations and bloating will be performed on primaries allocated by dwm only." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DWM_STEREO_DFLIP, 0x00002000 , "If bit is set, don't allow DFlip for DWM stereo swapchain on WDDM2.3" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES, 0x00004000 , "If bit is set, display driver does not export MS stereo modes on internal (laptop) panels" },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_EXPORT_HIGH_COLOR_CAPS_ON_10BPC_DISPLAYS, 0x00008000 , "If bit is set, DXGK_MONITORLINKINFO_CAPABILITIES::HighColorSpace is exported for 10bpc capable (non-HDR) displays on Quadro (which allows FP16 desktops on RS4+)." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_NON_DWM, 0x00010000 , "If bit is set, the usage of kmd's private context channel is disallowed for all applications besides dwm." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_DWM, 0x00020000 , "If bit is set, the usage of kmd's private context channel is disallowed for the dwm process." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SWAPGROUP_DWM_FLIP_BROADCASTING, 0x00040000 , "If bit is set a swapgroup will control the flip of all heads (including dwm owned heads). Fallback option until verified that this is fixed and no longer needed." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_ENFORCE_DIN_SIGNAL, 0x00080000 , "If bit is set, 3pin DIN stereo signal is persistently enabled for active stereo mode." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SMOOTHSCALING_SUPPORT_ON_QUADRO, 0x00100000 , "If bit is set, dsr aka smoothscaling aka hyperscaling is supported on Quadro boards." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_ENABLE_DL_DSR_SUPPORT_ON_QUADRO, 0x00200000 , "If bit is set, dl dsr is supported on Quadro boards." },
    { (const char **)g_ppszDefineDataNames_WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_STEREO_OUTPUT_CONTROL_OVERRIDE, 0x00400000 , "If bit is set, preferred stereo output target control via NVL_CLIENT_ARB_MODE_MODULE_STEREO_OUTPUT_CONTROL is disallowed." },
};

DataDefaultDWORD g_aDefaultData_WKS_FEATURE_SUPPORT_CONTROL[] =
{
    {"DEFAULT", 0x00086143, "SRS_1714_WIN8_STEREO|WIN8_STEREO_EXPORT_IF_ENABLED|ALLOW_SPLIT_STEREO_PRESENT_BLITS|DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION|DISABLE_DWM_STEREO_DFLIP|DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES|WIN8_STEREO_ENFORCE_DIN_SIGNAL" }, 
};

SettingDWORD g_setting_WKS_FEATURE_SUPPORT_CONTROL(
    0x11d9dc84,
    g_pszKeyName_WKS_FEATURE_SUPPORT_CONTROL,
    g_pszRemappedName_WKS_FEATURE_SUPPORT_CONTROL,
    g_pszMainDocs_WKS_FEATURE_SUPPORT_CONTROL,
    g_pszDefinedWhen_WKS_FEATURE_SUPPORT_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_WKS_FEATURE_SUPPORT_CONTROL, 
    23, 
    g_aDefaultData_WKS_FEATURE_SUPPORT_CONTROL, 
    1 
);

static const char *g_pszKeyName_WKS_MEMORY_ALLOCATION_POLICY = "WKS_MEMORY_ALLOCATION_POLICY";
static const char *g_pszDefinedWhen_WKS_MEMORY_ALLOCATION_POLICY = "1";
static const char *g_pszRemappedName_WKS_MEMORY_ALLOCATION_POLICY = "D3DOGL_11223344";
static const char *g_pszMainDocs_WKS_MEMORY_ALLOCATION_POLICY = "";

static const char * (g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_AS_NEEDED)[] =
{
    "AS_NEEDED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_MODERATE_PRE_ALLOCATION)[] =
{
    "MODERATE_PRE_ALLOCATION",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_AGGRESSIVE_PRE_ALLOCATION)[] =
{
    "AGGRESSIVE_PRE_ALLOCATION",
    NULL
};

DataValueDWORD g_aDefineData_WKS_MEMORY_ALLOCATION_POLICY[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_AS_NEEDED, 0x0 , "As Needed" },
    { (const char **)g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_MODERATE_PRE_ALLOCATION, 0x1 , "Moderate pre-allocation" },
    { (const char **)g_ppszDefineDataNames_WKS_MEMORY_ALLOCATION_POLICY_AGGRESSIVE_PRE_ALLOCATION, 0x2 , "Aggressive pre-allocation" },
};

DataDefaultDWORD g_aDefaultData_WKS_MEMORY_ALLOCATION_POLICY[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_WKS_MEMORY_ALLOCATION_POLICY(
    0x11112233,
    g_pszKeyName_WKS_MEMORY_ALLOCATION_POLICY,
    g_pszRemappedName_WKS_MEMORY_ALLOCATION_POLICY,
    g_pszMainDocs_WKS_MEMORY_ALLOCATION_POLICY,
    g_pszDefinedWhen_WKS_MEMORY_ALLOCATION_POLICY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_MEMORY_ALLOCATION_POLICY, 
    3, 
    g_aDefaultData_WKS_MEMORY_ALLOCATION_POLICY, 
    1 
);

static const char *g_pszKeyName_WKS_MOSAIC_TOPOLOGY_REQUESTED = "WKS_MOSAIC_TOPOLOGY_REQUESTED";
static const char *g_pszDefinedWhen_WKS_MOSAIC_TOPOLOGY_REQUESTED = "1";
static const char *g_pszRemappedName_WKS_MOSAIC_TOPOLOGY_REQUESTED = "D3DOGL_0x4fa775";
static const char *g_pszMainDocs_WKS_MOSAIC_TOPOLOGY_REQUESTED = "This setting suggest that a new Mosaic Topology is requested or not";

static const char * (g_ppszDefineDataNames_WKS_MOSAIC_TOPOLOGY_REQUESTED_OFF)[] =
{
    "OFF",
    "0",
    "FALSE",
    "REQUEST_DISABLED",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_MOSAIC_TOPOLOGY_REQUESTED_ON)[] =
{
    "ON",
    "1",
    "TRUE",
    "REQUEST_ENABLED",
    NULL
};

DataValueDWORD g_aDefineData_WKS_MOSAIC_TOPOLOGY_REQUESTED[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_MOSAIC_TOPOLOGY_REQUESTED_OFF, 0 , "Request Disable" },
    { (const char **)g_ppszDefineDataNames_WKS_MOSAIC_TOPOLOGY_REQUESTED_ON, 1 , "Request Enable" },
};

DataDefaultDWORD g_aDefaultData_WKS_MOSAIC_TOPOLOGY_REQUESTED[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_WKS_MOSAIC_TOPOLOGY_REQUESTED(
    0x114fa775,
    g_pszKeyName_WKS_MOSAIC_TOPOLOGY_REQUESTED,
    g_pszRemappedName_WKS_MOSAIC_TOPOLOGY_REQUESTED,
    g_pszMainDocs_WKS_MOSAIC_TOPOLOGY_REQUESTED,
    g_pszDefinedWhen_WKS_MOSAIC_TOPOLOGY_REQUESTED,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_MOSAIC_TOPOLOGY_REQUESTED, 
    2, 
    g_aDefaultData_WKS_MOSAIC_TOPOLOGY_REQUESTED, 
    1 
);

static const char *g_pszKeyName_WKS_POST_PROCESSING_ENGINE_CONTROL = "WKS_POST_PROCESSING_ENGINE_CONTROL";
static const char *g_pszDefinedWhen_WKS_POST_PROCESSING_ENGINE_CONTROL = "1";
static const char *g_pszRemappedName_WKS_POST_PROCESSING_ENGINE_CONTROL = "D3DOGL_WksPostProcessingEngineControl";
static const char *g_pszMainDocs_WKS_POST_PROCESSING_ENGINE_CONTROL = "NV private interface to adjust the behavior of the post processing engine";

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_DWM)[] =
{
    "EXECUTE_ON_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_NON_DWM)[] =
{
    "EXECUTE_ON_NON_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE)[] =
{
    "USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_DLDSR)[] =
{
    "DRAW_ON_SCREEN_INDICATOR_DLDSR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_DEVICE_RENDER_CHANNEL)[] =
{
    "USE_DEVICE_RENDER_CHANNEL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_UMD_SHADER_RESOURCE)[] =
{
    "USE_UMD_SHADER_RESOURCE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_UPSCALE)[] =
{
    "DRAW_ON_SCREEN_INDICATOR_UPSCALE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_ALL_CONTROLLED_BITS)[] =
{
    "MASK_FOR_ALL_CONTROLLED_BITS",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_DWM)[] =
{
    "MASK_FOR_EXECUTE_ON_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_NON_DWM)[] =
{
    "MASK_FOR_EXECUTE_ON_NON_DWM",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE)[] =
{
    "MASK_FOR_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_DLDSR)[] =
{
    "MASK_FOR_DRAW_ON_SCREEN_INDICATOR_DLDSR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_DEVICE_RENDER_CHANNEL)[] =
{
    "MASK_FOR_USE_DEVICE_RENDER_CHANNEL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_UMD_SHADER_RESOURCE)[] =
{
    "MASK_FOR_USE_UMD_SHADER_RESOURCE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_UPSCALE)[] =
{
    "MASK_FOR_DRAW_ON_SCREEN_INDICATOR_UPSCALE",
    NULL
};

DataValueDWORD g_aDefineData_WKS_POST_PROCESSING_ENGINE_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_OFF, 0x00000000 , "No specific adjustments for the post processing engine are selected" },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_DWM, 0x00000001 , "If bit is set, post processing engine operations are executed on desktop compositor owned fullscreen buffers." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_NON_DWM, 0x00000002 , "If bit is set, post processing engine operations are executed fullscreen buffers no owned by the desktop compositor." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE, 0x00000004 , "If bit is set, a global os hidden scratch framebuffer portion is used as gpu storage instead of context allocations." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_DLDSR, 0x00000008 , "If bit is set, an on screen indicator should be rendered for DLDSR on top of the executed post processing engine gpu program output." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_DEVICE_RENDER_CHANNEL, 0x00000010 , "If bit is set, 'If bit is set, the UMDs are instructed to schedule kernel assisted ppe work on the standard 3d render channel (this might not be supported by all umds)." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_USE_UMD_SHADER_RESOURCE, 0x00000020 , "If bit is set, use shader resource allocated by UMD for gpu program storage. This overrides the USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE bit." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_UPSCALE, 0x00000040 , "If bit is set, draw an on-screen indicator for Upscale." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_ALL_CONTROLLED_BITS, 0xFFFF0000 , "Combined mask bits for all potential mask bit controlled entries." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_DWM, 0x00010000 , "EXECUTE_ON_DWM settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_NON_DWM, 0x00020000 , "EXECUTE_ON_NON_DWM settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE, 0x00040000 , "USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_DLDSR, 0x00080000 , "DRAW_ON_SCREEN_INDICATOR_DLDSR settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_DEVICE_RENDER_CHANNEL, 0x00100000 , "USE_DEVICE_RENDER_CHANNEL settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_UMD_SHADER_RESOURCE, 0x00200000 , "USE_UMD_SHADER_RESOURCE settings are just modified in case this mask bit is also set." },
    { (const char **)g_ppszDefineDataNames_WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_UPSCALE, 0x00400000 , "DRAW_ON_SCREEN_INDICATOR_UPSCALE settings are just modified in case this mask bit is also set." },
};

DataDefaultDWORD g_aDefaultData_WKS_POST_PROCESSING_ENGINE_CONTROL[] =
{
    {"DEFAULT", 0x00000033, "EXECUTE_ON_DWM + EXECUTE_ON_NON_DWM + USE_DEVICE_RENDER_CHANNEL + USE_UMD_SHADER_RESOURCE" }, 
};

SettingDWORD g_setting_WKS_POST_PROCESSING_ENGINE_CONTROL(
    0x11112256,
    g_pszKeyName_WKS_POST_PROCESSING_ENGINE_CONTROL,
    g_pszRemappedName_WKS_POST_PROCESSING_ENGINE_CONTROL,
    g_pszMainDocs_WKS_POST_PROCESSING_ENGINE_CONTROL,
    g_pszDefinedWhen_WKS_POST_PROCESSING_ENGINE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_WKS_POST_PROCESSING_ENGINE_CONTROL, 
    16, 
    g_aDefaultData_WKS_POST_PROCESSING_ENGINE_CONTROL, 
    1 
);

static const char *g_pszKeyName_WKS_SCANOUT_COMPOSITION_CONTROL = "WKS_SCANOUT_COMPOSITION_CONTROL";
static const char *g_pszDefinedWhen_WKS_SCANOUT_COMPOSITION_CONTROL = "1";
static const char *g_pszRemappedName_WKS_SCANOUT_COMPOSITION_CONTROL = "D3DOGL_WksScanoutCompositionControl";
static const char *g_pszMainDocs_WKS_SCANOUT_COMPOSITION_CONTROL = "NV private interface to enable/disable scanoutComposition features";

static const char * (g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_UNICAST)[] =
{
    "MULTIGPU_MOSAIC_UNICAST",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_ALLOC_PACKING)[] =
{
    "MULTIGPU_MOSAIC_ALLOC_PACKING",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_ENABLE_GAMMA_FOR_PER_PIXEL_INTENSITY)[] =
{
    "ENABLE_GAMMA_FOR_PER_PIXEL_INTENSITY",
    NULL
};

DataValueDWORD g_aDefineData_WKS_SCANOUT_COMPOSITION_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_OFF, 0x00000000 , "No specific adjustments for scanoutComposition backend are selected" },
    { (const char **)g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_UNICAST, 0x00000001 , "If bit is set, scanoutComposition performs composition in unicast manner" },
    { (const char **)g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_ALLOC_PACKING, 0x00000002 , "If bit is set, scanoutComposition allocation is packed to save memory usage and unicasting is required (for RID 52174)" },
    { (const char **)g_ppszDefineDataNames_WKS_SCANOUT_COMPOSITION_CONTROL_ENABLE_GAMMA_FOR_PER_PIXEL_INTENSITY, 0x00000004 , "If bit is set, per pixel intensity operations on non-float allocations are performed in linear space by doing a de-gamma on reads and re-gamma on writes." },
};

DataDefaultDWORD g_aDefaultData_WKS_SCANOUT_COMPOSITION_CONTROL[] =
{
    {"DEFAULT", 0x00000003, "MULTIGPU_MOSAIC_UNICAST + MULTIGPU_MOSAIC_ALLOC_PACKING" }, 
};

SettingDWORD g_setting_WKS_SCANOUT_COMPOSITION_CONTROL(
    0x11112255,
    g_pszKeyName_WKS_SCANOUT_COMPOSITION_CONTROL,
    g_pszRemappedName_WKS_SCANOUT_COMPOSITION_CONTROL,
    g_pszMainDocs_WKS_SCANOUT_COMPOSITION_CONTROL,
    g_pszDefinedWhen_WKS_SCANOUT_COMPOSITION_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_WKS_SCANOUT_COMPOSITION_CONTROL, 
    4, 
    g_aDefaultData_WKS_SCANOUT_COMPOSITION_CONTROL, 
    1 
);

static const char *g_pszKeyName_WKS_STEREO_DONGLE_SUPPORT = "WKS_STEREO_DONGLE_SUPPORT";
static const char *g_pszDefinedWhen_WKS_STEREO_DONGLE_SUPPORT = "1";
static const char *g_pszRemappedName_WKS_STEREO_DONGLE_SUPPORT = "D3DOGL_EnableStereoDongleSupport";
static const char *g_pszMainDocs_WKS_STEREO_DONGLE_SUPPORT = "Control of the stereo dongle";

static const char * (g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_DAC)[] =
{
    "DAC",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_DLP)[] =
{
    "DLP",
    NULL
};

DataValueDWORD g_aDefineData_WKS_STEREO_DONGLE_SUPPORT[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_OFF, 0 , "Disable stereo dongle support" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_DAC, 1 , "Enable stereo dongle using stereo signal from GPU" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_DONGLE_SUPPORT_DLP, 2 , "Enable stereo dongle using stereo signal from DLP" },
};

DataDefaultDWORD g_aDefaultData_WKS_STEREO_DONGLE_SUPPORT[] =
{
    {"DEFAULT", 1, "" }, 
};

SettingDWORD g_setting_WKS_STEREO_DONGLE_SUPPORT(
    0x112493bd,
    g_pszKeyName_WKS_STEREO_DONGLE_SUPPORT,
    g_pszRemappedName_WKS_STEREO_DONGLE_SUPPORT,
    g_pszMainDocs_WKS_STEREO_DONGLE_SUPPORT,
    g_pszDefinedWhen_WKS_STEREO_DONGLE_SUPPORT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_STEREO_DONGLE_SUPPORT, 
    3, 
    g_aDefaultData_WKS_STEREO_DONGLE_SUPPORT, 
    1 
);

static const char *g_pszKeyName_WKS_STEREO_SUPPORT = "WKS_STEREO_SUPPORT";
static const char *g_pszDefinedWhen_WKS_STEREO_SUPPORT = "1";
static const char *g_pszRemappedName_WKS_STEREO_SUPPORT = "D3DOGL_EnableStereoSupport";
static const char *g_pszMainDocs_WKS_STEREO_SUPPORT = "Support of the stereo API for workstations";

static const char * (g_ppszDefineDataNames_WKS_STEREO_SUPPORT_OFF)[] =
{
    "OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_SUPPORT_ON)[] =
{
    "ON",
    NULL
};

DataValueDWORD g_aDefineData_WKS_STEREO_SUPPORT[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SUPPORT_OFF, 0 , "Disable API stereo support" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SUPPORT_ON, 1 , "Enable API stereo support" },
};

DataDefaultDWORD g_aDefaultData_WKS_STEREO_SUPPORT[] =
{
    {"DEFAULT", 0, "" }, 
};

SettingDWORD g_setting_WKS_STEREO_SUPPORT(
    0x11aa9e99,
    g_pszKeyName_WKS_STEREO_SUPPORT,
    g_pszRemappedName_WKS_STEREO_SUPPORT,
    g_pszMainDocs_WKS_STEREO_SUPPORT,
    g_pszDefinedWhen_WKS_STEREO_SUPPORT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_STEREO_SUPPORT, 
    2, 
    g_aDefaultData_WKS_STEREO_SUPPORT, 
    1 
);

static const char *g_pszKeyName_WKS_STEREO_SWAP_MODE = "WKS_STEREO_SWAP_MODE";
static const char *g_pszDefinedWhen_WKS_STEREO_SWAP_MODE = "1";
static const char *g_pszRemappedName_WKS_STEREO_SWAP_MODE = "D3DOGL_33333333";
static const char *g_pszMainDocs_WKS_STEREO_SWAP_MODE = "";

static const char * (g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL)[] =
{
    "APPLICATION_CONTROL",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE)[] =
{
    "PER_EYE",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE_PAIR)[] =
{
    "PER_EYE_PAIR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_LEGACY_BEHAVIOR)[] =
{
    "LEGACY_BEHAVIOR",
    NULL
};

static const char * (g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE_FOR_SWAP_GROUP)[] =
{
    "PER_EYE_FOR_SWAP_GROUP",
    NULL
};

DataValueDWORD g_aDefineData_WKS_STEREO_SWAP_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL, 0x0 , "Application Control" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE, 0x1 , "Per Eye" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE_PAIR, 0x2 , "Per Eye-Pair" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_LEGACY_BEHAVIOR, 0x3 , "Legacy Behavior" },
    { (const char **)g_ppszDefineDataNames_WKS_STEREO_SWAP_MODE_PER_EYE_FOR_SWAP_GROUP, 0x4 , "Per Eye swap for swapgroup" },
};

DataDefaultDWORD g_aDefaultData_WKS_STEREO_SWAP_MODE[] =
{
    {"DEFAULT", 0x0, "" }, 
};

SettingDWORD g_setting_WKS_STEREO_SWAP_MODE(
    0x11333333,
    g_pszKeyName_WKS_STEREO_SWAP_MODE,
    g_pszRemappedName_WKS_STEREO_SWAP_MODE,
    g_pszMainDocs_WKS_STEREO_SWAP_MODE,
    g_pszDefinedWhen_WKS_STEREO_SWAP_MODE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_WKS_STEREO_SWAP_MODE, 
    5, 
    g_aDefaultData_WKS_STEREO_SWAP_MODE, 
    1 
);

static const char *g_pszKeyName_YUV_EMULATION_MODE = "YUV_EMULATION_MODE";
static const char *g_pszDefinedWhen_YUV_EMULATION_MODE = "1";
static const char *g_pszRemappedName_YUV_EMULATION_MODE = "D3DOGL_WksYuvEmulationMode";
static const char *g_pszMainDocs_YUV_EMULATION_MODE = "Controling yuv emulation settings.";

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_OVERRIDE_OFF)[] =
{
    "OVERRIDE_OFF",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_MASK)[] =
{
    "RANGE_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_NONE)[] =
{
    "RANGE_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_FULL)[] =
{
    "RANGE_OVERRIDE_FULL",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_LIMITED)[] =
{
    "RANGE_OVERRIDE_LIMITED",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_MASK)[] =
{
    "COLORIMETRY_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_NONE)[] =
{
    "COLORIMETRY_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT601)[] =
{
    "COLORIMETRY_OVERRIDE_BT601",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT709)[] =
{
    "COLORIMETRY_OVERRIDE_BT709",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020C)[] =
{
    "COLORIMETRY_OVERRIDE_BT2020C",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020NC)[] =
{
    "COLORIMETRY_OVERRIDE_BT2020NC",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_RGB)[] =
{
    "COLORIMETRY_OVERRIDE_RGB",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_MASK)[] =
{
    "BPC_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_NONE)[] =
{
    "BPC_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_8_BPC)[] =
{
    "BPC_OVERRIDE_8_BPC",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_10_BPC)[] =
{
    "BPC_OVERRIDE_10_BPC",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_12_BPC)[] =
{
    "BPC_OVERRIDE_12_BPC",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_MASK)[] =
{
    "LUT_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_NONE)[] =
{
    "LUT_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_NO_LUT)[] =
{
    "LUT_OVERRIDE_NO_LUT",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_MASK)[] =
{
    "SAT_HUE_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NONE)[] =
{
    "SAT_HUE_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NO_SAT_HUE)[] =
{
    "SAT_HUE_OVERRIDE_NO_SAT_HUE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_MASK)[] =
{
    "HDR_MODE_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_NONE)[] =
{
    "HDR_MODE_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_SDR)[] =
{
    "HDR_MODE_OVERRIDE_SDR",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_HDR)[] =
{
    "HDR_MODE_OVERRIDE_HDR",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_EDR)[] =
{
    "HDR_MODE_OVERRIDE_EDR",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_LDR)[] =
{
    "HDR_MODE_OVERRIDE_LDR",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_MASK)[] =
{
    "HDR_CONTROL_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NONE)[] =
{
    "HDR_CONTROL_OVERRIDE_NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_CSC)[] =
{
    "HDR_CONTROL_OVERRIDE_NO_CSC",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_SCALING)[] =
{
    "HDR_CONTROL_OVERRIDE_NO_SCALING",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_OETF)[] =
{
    "HDR_CONTROL_OVERRIDE_NO_OETF",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_ALL_FORMATS)[] =
{
    "HDR_CONTROL_OVERRIDE_HDR_ALL_FORMATS",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_DCIP3_OUTPUT)[] =
{
    "HDR_CONTROL_OVERRIDE_HDR_DCIP3_OUTPUT",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_MASK)[] =
{
    "YUV_PREALLOC_OVERRIDE_MASK",
    NULL
};

static const char * (g_ppszDefineDataNames_YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_PREALLOC_HDR)[] =
{
    "YUV_PREALLOC_OVERRIDE_PREALLOC_HDR",
    NULL
};

DataValueDWORD g_aDefineData_YUV_EMULATION_MODE[] =
{
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_OVERRIDE_OFF, 0x00000000 , "No override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_MASK, 0x00000003 , "Bitmask for range overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_NONE, 0x00000000 , "No range override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_FULL, 0x00000001 , "Always use limited range." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_RANGE_OVERRIDE_LIMITED, 0x00000002 , "Always use full range." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_MASK, 0x00000070 , "Bitmask for colorimetry overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_NONE, 0x00000000 , "No colorimetry override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT601, 0x00000010 , "Always use BT601." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT709, 0x00000020 , "Always use BT709." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020C, 0x00000030 , "Always use BT2020 constant luminance." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020NC, 0x00000040 , "Always use BT2020 non-constant luminance." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_RGB, 0x00000050 , "RGB aka don't do a rgb yuv csc." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_MASK, 0x00000300 , "Bitmask for bpc overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_NONE, 0x00000000 , "No bpc override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_8_BPC, 0x00000100 , "Always use 8bpc." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_10_BPC, 0x00000200 , "Always use 10bpc." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_BPC_OVERRIDE_12_BPC, 0x00000300 , "Always use 12bpc." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_MASK, 0x00001000 , "Bitmask for lut overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_NONE, 0x00000000 , "No lut override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_LUT_OVERRIDE_NO_LUT, 0x00001000 , "Ignore the lut (always of)." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_MASK, 0x00002000 , "Bitmask for saturation and hue overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NONE, 0x00000000 , "No saturation and hue override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NO_SAT_HUE, 0x00002000 , "Ignore Saturation and Hue (always off)." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_MASK, 0x00070000 , "Bitmask for hdr overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_NONE, 0x00000000 , "No hdr mode override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_SDR, 0x00010000 , "Disable HDR" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_HDR, 0x00020000 , "Keep hdr enabled all the time (always on)." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_EDR, 0x00030000 , "Keep edr enabled all the time (always on)." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_LDR, 0x00040000 , "Keep ldr enabled all the time (always on)." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_MASK, 0x01F00000 , "Bitmask for hdr setting overrides." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NONE, 0x00000000 , "No hdr control override." },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_CSC, 0x00100000 , "Don't use scRGB->rec BT2020 colorspace conversion" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_SCALING, 0x00200000 , "Don't perform 80 -> 10000 nits scaling (*0.008)" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_OETF, 0x00400000 , "Don't perform inverse PQ EOTF" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_ALL_FORMATS, 0x00800000 , "Apply hdr conversion on all primaries (no matter which format they have)" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_DCIP3_OUTPUT, 0x01000000 , "Output DCIP3 PQ output for compatibility with Dolby Maui HDR monitor" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_MASK, 0x02000000 , "Bitmask for yuv preallocation overrides" },
    { (const char **)g_ppszDefineDataNames_YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_PREALLOC_HDR, 0x02000000 , "Preallocate a yuv portion for all potential hdr allocations as intrinsic alloc type. Default until on the fly transitions are working." },
};

DataDefaultDWORD g_aDefaultData_YUV_EMULATION_MODE[] =
{
    {"DEFAULT", 0x02000000, "" }, 
};

SettingDWORD g_setting_YUV_EMULATION_MODE(
    0x11e21665,
    g_pszKeyName_YUV_EMULATION_MODE,
    g_pszRemappedName_YUV_EMULATION_MODE,
    g_pszMainDocs_YUV_EMULATION_MODE,
    g_pszDefinedWhen_YUV_EMULATION_MODE,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_YUV_EMULATION_MODE, 
    38, 
    g_aDefaultData_YUV_EMULATION_MODE, 
    1 
);

static const char *g_pszKeyName_ZCULL_SUBREGION_ALIQUOT_LIMIT = "ZCULL_SUBREGION_ALIQUOT_LIMIT";
static const char *g_pszDefinedWhen_ZCULL_SUBREGION_ALIQUOT_LIMIT = "1";
static const char *g_pszRemappedName_ZCULL_SUBREGION_ALIQUOT_LIMIT = "D3DOGL_8AD8AD00";
static const char *g_pszMainDocs_ZCULL_SUBREGION_ALIQUOT_LIMIT = "Specify an artificial upper limit on the total number of aliquots available for a region when using subregions.";

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_ALIQUOT_LIMIT_ZERO)[] =
{
    "ZERO",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_ALIQUOT_LIMIT_NONE)[] =
{
    "NONE",
    NULL
};

DataValueDWORD g_aDefineData_ZCULL_SUBREGION_ALIQUOT_LIMIT[] =
{
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_ALIQUOT_LIMIT_ZERO, 0x00000000 , "Pretend we have 0 aliquots" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_ALIQUOT_LIMIT_NONE, 0xFFFFFFFF , "Don't place an artificial limit on the number of aliquots available" },
};

DataDefaultDWORD g_aDefaultData_ZCULL_SUBREGION_ALIQUOT_LIMIT[] =
{
    {"DEFAULT", 0xFFFFFFFF, "" }, 
};

SettingDWORD g_setting_ZCULL_SUBREGION_ALIQUOT_LIMIT(
    0x107cffba,
    g_pszKeyName_ZCULL_SUBREGION_ALIQUOT_LIMIT,
    g_pszRemappedName_ZCULL_SUBREGION_ALIQUOT_LIMIT,
    g_pszMainDocs_ZCULL_SUBREGION_ALIQUOT_LIMIT,
    g_pszDefinedWhen_ZCULL_SUBREGION_ALIQUOT_LIMIT,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ZCULL_SUBREGION_ALIQUOT_LIMIT, 
    2, 
    g_aDefaultData_ZCULL_SUBREGION_ALIQUOT_LIMIT, 
    1 
);

static const char *g_pszKeyName_ZCULL_SUBREGION_FORMATS_0 = "ZCULL_SUBREGION_FORMATS_0";
static const char *g_pszDefinedWhen_ZCULL_SUBREGION_FORMATS_0 = "1";
static const char *g_pszRemappedName_ZCULL_SUBREGION_FORMATS_0 = "D3DOGL_808EE280";
static const char *g_pszMainDocs_ZCULL_SUBREGION_FORMATS_0 = "Set the Zcull Subregion distribution for subregion IDs 0-7.\nSee ZCULL_SUBREGION_FORMATS_1 for the other 8 subregions.\nZCULL_SUBREGION_STRATEGY must be set to EXPLICIT for these keys to take effect.\n\nEach nibble specifies the zcull format for a single subregion, where the lowest order (least significant) 4 bits sets the 0th subregion etc. For adaptive/dynamic subregion assignment, the highest precision formats should be assigned to the lowest numbered IDs (that is, the LSBs in this setting). If there are insufficient aliquots, as many of the requested formats as possible are used (the final of which may have fewer aliquots than required to cover its subregion), and the remaining are set to NONE and given 0 aliquots.\n\nSee below for the available zcull formats (the normalized aliquot scaling factor is in parentheses) and some sample distributions.";

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16X2_4X4)[] =
{
    "Z_16X16X2_4X4",
    "Z_4X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X16_4X4)[] =
{
    "ZS_16X16_4X4",
    "ZS_4x4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X2)[] =
{
    "Z_16X16_4X2",
    "Z_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_2X4)[] =
{
    "Z_16X16_2X4",
    "Z_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X8_4X4)[] =
{
    "Z_16X8_4X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_8X8_4X2)[] =
{
    "Z_8X8_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_8X8_2X4)[] =
{
    "Z_8X8_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X8)[] =
{
    "Z_16X16_4X8",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_4X8_2X2)[] =
{
    "Z_4X8_2X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X8_4X2)[] =
{
    "ZS_16X8_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X8_2X4)[] =
{
    "ZS_16X8_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_8X8_2X2)[] =
{
    "ZS_8X8_2X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_4X8_1X1)[] =
{
    "Z_4X8_1X1",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ONEHIGH)[] =
{
    "ONEHIGH",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_COARSEHIRES)[] =
{
    "COARSEHIRES",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_ZCULL_SUBREGION_FORMATS_0[] =
{
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16X2_4X4, 0x0 , "(0.5X) Standard 'high res' (coarse) zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X16_4X4, 0x1 , "(1X  ) Standard zcull with stencil" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X2, 0x2 , "(1X  ) Standard non-stencil format" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_2X4, 0x3 , "(1X  ) Standard non-stencil format (alternate occluder orientation)" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X8_4X4, 0x4 , "(1X  )" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_8X8_4X2, 0x5 , "(2X  ) High precision" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_8X8_2X4, 0x6 , "(2X  ) High precision" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X8, 0x7 , "(0.5X) Large occluder coarse zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_4X8_2X2, 0x8 , "(4X  ) *** Useful in AA mode _only_ *** (highest available precision)" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X8_4X2, 0x9 , "(2X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_16X8_2X4, 0xa , "(2X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ZS_8X8_2X2, 0xb , "(4X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_Z_4X8_1X1, 0xc , "(8X  ) *** Unimplemented *** Useful in AA _only_" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_NONE, 0xf , "(0X  ) No zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_ONEHIGH, 0xfffffff8 , "1st @ Z_4X8_2X2 (only a win in AA), no zcull for the rest" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_COARSEHIRES, 0x00000000 , "Use high res zcull (Z_16X16X2_4X4 aka Z_4X4) for all of the first 8 subregions" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_0_DEFAULT, 0x22555555 , "6 @ Z_8X8_4X2, 2 @ Z_16X16_4X2 (aka Z_4X2)" },
};

DataDefaultDWORD g_aDefaultData_ZCULL_SUBREGION_FORMATS_0[] =
{
    {"DEFAULT", 0x22555555, "" }, 
};

SettingDWORD g_setting_ZCULL_SUBREGION_FORMATS_0(
    0x107c254a,
    g_pszKeyName_ZCULL_SUBREGION_FORMATS_0,
    g_pszRemappedName_ZCULL_SUBREGION_FORMATS_0,
    g_pszMainDocs_ZCULL_SUBREGION_FORMATS_0,
    g_pszDefinedWhen_ZCULL_SUBREGION_FORMATS_0,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ZCULL_SUBREGION_FORMATS_0, 
    17, 
    g_aDefaultData_ZCULL_SUBREGION_FORMATS_0, 
    1 
);

static const char *g_pszKeyName_ZCULL_SUBREGION_FORMATS_1 = "ZCULL_SUBREGION_FORMATS_1";
static const char *g_pszDefinedWhen_ZCULL_SUBREGION_FORMATS_1 = "1";
static const char *g_pszRemappedName_ZCULL_SUBREGION_FORMATS_1 = "D3DOGL_FAF8A723";
static const char *g_pszMainDocs_ZCULL_SUBREGION_FORMATS_1 = "Set the Zcull Subregion distribution for subregion IDs 8-15.\nSee ZCULL_SUBREGION_FORMATS_0 for the other 8 subregions.\nZCULL_SUBREGION_STRATEGY must be set to EXPLICIT for these keys to take effect.\n\nEach nibble specifies the zcull format for a single subregion, where the lowest order (least significant) 4 bits sets the 8th subregion, the next 4 set the 9th, and on through the highest order nibble setting the last. For adaptive/dynamic subregion assignment, the lowest precision formats should be assigned to the highest numbered IDs (that is, the MSBs in this setting). If there are insufficient aliquots, as many of the requested formats as possible are used (the final of which may have fewer aliquots than required to cover its subregion), and the remaining are set to NONE and given 0 aliquots.\n\nSee below for the available zcull formats (the normalized aliquot scaling factor is in parentheses) and some sample distributions.";

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16X2_4X4)[] =
{
    "Z_16X16X2_4X4",
    "Z_4X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X16_4X4)[] =
{
    "ZS_16X16_4X4",
    "ZS_4x4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X2)[] =
{
    "Z_16X16_4X2",
    "Z_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_2X4)[] =
{
    "Z_16X16_2X4",
    "Z_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X8_4X4)[] =
{
    "Z_16X8_4X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_8X8_4X2)[] =
{
    "Z_8X8_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_8X8_2X4)[] =
{
    "Z_8X8_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X8)[] =
{
    "Z_16X16_4X8",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_4X8_2X2)[] =
{
    "Z_4X8_2X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X8_4X2)[] =
{
    "ZS_16X8_4X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X8_2X4)[] =
{
    "ZS_16X8_2X4",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_8X8_2X2)[] =
{
    "ZS_8X8_2X2",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_4X8_1X1)[] =
{
    "Z_4X8_1X1",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_NONE)[] =
{
    "NONE",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ONELOW)[] =
{
    "ONELOW",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_COARSEHIRES)[] =
{
    "COARSEHIRES",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_DEFAULT)[] =
{
    "DEFAULT",
    NULL
};

DataValueDWORD g_aDefineData_ZCULL_SUBREGION_FORMATS_1[] =
{
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16X2_4X4, 0x0 , "(0.5X) Standard 'high res' (coarse) zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X16_4X4, 0x1 , "(1X  ) Standard zcull with stencil" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X2, 0x2 , "(1X  ) Standard non-stencil format" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_2X4, 0x3 , "(1X  ) Standard non-stencil format (alternate occluder orientation)" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X8_4X4, 0x4 , "(1X  )" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_8X8_4X2, 0x5 , "(2X  ) High precision" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_8X8_2X4, 0x6 , "(2X  ) High precision" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X8, 0x7 , "(0.5X) Large occluder coarse zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_4X8_2X2, 0x8 , "(4X  ) *** Useful in AA mode _only_ *** (highest available precision)" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X8_4X2, 0x9 , "(2X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_16X8_2X4, 0xa , "(2X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ZS_8X8_2X2, 0xb , "(4X  ) *** Unimplemented ***" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_Z_4X8_1X1, 0xc , "(8X  ) *** Unimplemented *** Useful in AA _only_" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_NONE, 0xf , "(0X  ) No zcull" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_ONELOW, 0x02222222 , "Last (15th) subregion @ high res zcull, normal zcull for the rest" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_COARSEHIRES, 0x00000000 , "Use high res zcull (Z_16X16X2_4X4 aka Z_4X4) for all of the last 8 subregions" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_FORMATS_1_DEFAULT, 0xff222222 , "Subregion IDs 8-13 get normal zcull Z_16X16_4X2 (aka Z_4X2), the last two (IDs 14 and 15) get NONE" },
};

DataDefaultDWORD g_aDefaultData_ZCULL_SUBREGION_FORMATS_1[] =
{
    {"DEFAULT", 0xff222222, "" }, 
};

SettingDWORD g_setting_ZCULL_SUBREGION_FORMATS_1(
    0x109c67d1,
    g_pszKeyName_ZCULL_SUBREGION_FORMATS_1,
    g_pszRemappedName_ZCULL_SUBREGION_FORMATS_1,
    g_pszMainDocs_ZCULL_SUBREGION_FORMATS_1,
    g_pszDefinedWhen_ZCULL_SUBREGION_FORMATS_1,
    0,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ZCULL_SUBREGION_FORMATS_1, 
    17, 
    g_aDefaultData_ZCULL_SUBREGION_FORMATS_1, 
    1 
);

static const char *g_pszKeyName_ZCULL_SUBREGION_REPORT_TYPE = "ZCULL_SUBREGION_REPORT_TYPE";
static const char *g_pszDefinedWhen_ZCULL_SUBREGION_REPORT_TYPE = "1";
static const char *g_pszRemappedName_ZCULL_SUBREGION_REPORT_TYPE = "D3DOGL_8AD8A75";
static const char *g_pszMainDocs_ZCULL_SUBREGION_REPORT_TYPE = "Specify what the counters in the ZCull subregions should count.\n\nThere is one counter per subregion and all subregions count the same type of event. The counters only increment when the specified event Type affects a tile.";

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST)[] =
{
    "DEPTH_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_NO_ACCEPT)[] =
{
    "DEPTH_TEST_NO_ACCEPT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_LATE_Z)[] =
{
    "DEPTH_TEST_LATE_Z",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_STENCIL_TEST)[] =
{
    "STENCIL_TEST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

DataValueDWORD g_aDefineData_ZCULL_SUBREGION_REPORT_TYPE[] =
{
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST, 0x00000000 , "Counts 8x8s that are depth tested" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_NO_ACCEPT, 0x00000001 , "Counts 8x8s that are depth tested but not trival accepted" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_LATE_Z, 0x00000002 , "Counts 8x8s that are depth tested in late Z" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_STENCIL_TEST, 0x00000003 , "Counts stencil tested 8x8s" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_REPORT_TYPE_AUTOSELECT, 0xFFFFFFFF , "Let the driver choose" },
};

DataDefaultDWORD g_aDefaultData_ZCULL_SUBREGION_REPORT_TYPE[] =
{
    {"DEFAULT", 0xFFFFFFFF, "" }, 
};

SettingDWORD g_setting_ZCULL_SUBREGION_REPORT_TYPE(
    0x1006114d,
    g_pszKeyName_ZCULL_SUBREGION_REPORT_TYPE,
    g_pszRemappedName_ZCULL_SUBREGION_REPORT_TYPE,
    g_pszMainDocs_ZCULL_SUBREGION_REPORT_TYPE,
    g_pszDefinedWhen_ZCULL_SUBREGION_REPORT_TYPE,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ZCULL_SUBREGION_REPORT_TYPE, 
    5, 
    g_aDefaultData_ZCULL_SUBREGION_REPORT_TYPE, 
    1 
);

static const char *g_pszKeyName_ZCULL_SUBREGION_STRATEGY = "ZCULL_SUBREGION_STRATEGY";
static const char *g_pszDefinedWhen_ZCULL_SUBREGION_STRATEGY = "1";
static const char *g_pszRemappedName_ZCULL_SUBREGION_STRATEGY = "D3DOGL_18ADD00D";
static const char *g_pszMainDocs_ZCULL_SUBREGION_STRATEGY = "Select the Zcull Subregion distribution strategy. Set this to EXPLICIT and also set ZCULL_SUBREGION_FORMATS_0 and ZCULL_SUBREGION_FORMATS_1 for testing and performance shmooing.";

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_FORCE_DISABLE)[] =
{
    "FORCE_DISABLE",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_AUTOSELECT)[] =
{
    "AUTOSELECT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_EXPLICIT)[] =
{
    "EXPLICIT",
    NULL
};

DataValueDWORD g_aDefineData_ZCULL_SUBREGION_STRATEGY[] =
{
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_FORCE_DISABLE, 0x00000000 , "Force subregions off" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_AUTOSELECT, 0x00000001 , "The default mode, the driver will pick a strategy" },
    { (const char **)g_ppszDefineDataNames_ZCULL_SUBREGION_STRATEGY_EXPLICIT, 0x00000002 , "Use the formats specified in ZCULL_SUBREGION_FORMATS_0 and ZCULL_SUBREGION_FORMATS_1" },
};

DataDefaultDWORD g_aDefaultData_ZCULL_SUBREGION_STRATEGY[] =
{
    {"DEFAULT", 0x00000001, "" }, 
};

SettingDWORD g_setting_ZCULL_SUBREGION_STRATEGY(
    0x10b083ee,
    g_pszKeyName_ZCULL_SUBREGION_STRATEGY,
    g_pszRemappedName_ZCULL_SUBREGION_STRATEGY,
    g_pszMainDocs_ZCULL_SUBREGION_STRATEGY,
    g_pszDefinedWhen_ZCULL_SUBREGION_STRATEGY,
    SettingGeneric::LIMIT_VALUES_TO_LIST,
    SettingGeneric::ATTRIBUTE_SAMPLES, 
    false, 
    g_aDefineData_ZCULL_SUBREGION_STRATEGY, 
    3, 
    g_aDefaultData_ZCULL_SUBREGION_STRATEGY, 
    1 
);

static const char *g_pszKeyName_ZROP_L2_CACHE_CONTROL = "ZROP_L2_CACHE_CONTROL";
static const char *g_pszDefinedWhen_ZROP_L2_CACHE_CONTROL = "PERF_STRATEGY_REGKEYS";
static const char *g_pszRemappedName_ZROP_L2_CACHE_CONTROL = "D3DOGL_0x1fd5";
static const char *g_pszMainDocs_ZROP_L2_CACHE_CONTROL = "Each nibble controls the ZROP L2 cache policy for particular operations on the ZROP clients. Ada+ architectures only";

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_FIRST)[] =
{
    "ZROP_NONINTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "ZROP_NONINTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_LAST)[] =
{
    "ZROP_NONINTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_SHIFT)[] =
{
    "ZROP_NONINTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_FIRST)[] =
{
    "ZROP_INTERLOCKED_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_NORMAL)[] =
{
    "ZROP_INTERLOCKED_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_LAST)[] =
{
    "ZROP_INTERLOCKED_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_SHIFT)[] =
{
    "ZROP_INTERLOCKED_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_FIRST)[] =
{
    "ZROP_PREFETCH_READ_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_NORMAL)[] =
{
    "ZROP_PREFETCH_READ_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_LAST)[] =
{
    "ZROP_PREFETCH_READ_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_SHIFT)[] =
{
    "ZROP_PREFETCH_READ_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "ZROP_NONINTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "ZROP_NONINTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "ZROP_NONINTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_SHIFT)[] =
{
    "ZROP_NONINTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_FIRST)[] =
{
    "ZROP_INTERLOCKED_WRITE_EVICT_FIRST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_NORMAL)[] =
{
    "ZROP_INTERLOCKED_WRITE_EVICT_NORMAL",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_LAST)[] =
{
    "ZROP_INTERLOCKED_WRITE_EVICT_LAST",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_SHIFT)[] =
{
    "ZROP_INTERLOCKED_WRITE_SHIFT",
    NULL
};

static const char * (g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_USE_LEGACY)[] =
{
    "USE_LEGACY",
    NULL
};

DataValueDWORD g_aDefineData_ZROP_L2_CACHE_CONTROL[] =
{
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_NORMAL, 0x00000001 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_LAST, 0x00000002 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_SHIFT, 0 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_NORMAL, 0x00000010 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_LAST, 0x00000020 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_SHIFT, 4 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_NORMAL, 0x00000100 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_LAST, 0x00000200 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_SHIFT, 8 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_NORMAL, 0x00001000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_LAST, 0x00002000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_SHIFT, 12 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_FIRST, 0x00000000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_NORMAL, 0x00010000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_LAST, 0x00020000 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_SHIFT, 16 , "" },
    { (const char **)g_ppszDefineDataNames_ZROP_L2_CACHE_CONTROL_USE_LEGACY, 0x00100000 , "Use values specified by FERMI_SET_L2_CACHE_CONTROL" },
};

DataDefaultDWORD g_aDefaultData_ZROP_L2_CACHE_CONTROL[] =
{
    {"DEFAULT", 0x00100000, "" }, 
};

SettingDWORD g_setting_ZROP_L2_CACHE_CONTROL(
    0x10001fd5,
    g_pszKeyName_ZROP_L2_CACHE_CONTROL,
    g_pszRemappedName_ZROP_L2_CACHE_CONTROL,
    g_pszMainDocs_ZROP_L2_CACHE_CONTROL,
    g_pszDefinedWhen_ZROP_L2_CACHE_CONTROL,
    0,
    SettingGeneric::ATTRIBUTE_BITFIELDS, 
    false, 
    g_aDefineData_ZROP_L2_CACHE_CONTROL, 
    21, 
    g_aDefaultData_ZROP_L2_CACHE_CONTROL, 
    1 
);

static SettingGeneric * g_listofSettings[] = {
    &g_setting_AAMODE, 
    &g_setting_AA_BEHAVIOR_FLAGS, 
    &g_setting_AA_MODE_ALPHATOCOVERAGE, 
    &g_setting_AA_MODE_FOS, 
    &g_setting_AA_MODE_GAMMACORRECTION, 
    &g_setting_AA_MODE_METHOD, 
    &g_setting_AA_MODE_REPLAY, 
    &g_setting_AA_MODE_SELECTOR, 
    &g_setting_AA_MODE_SELECTOR_SLIAA, 
    &g_setting_AFRSLIAA, 
    &g_setting_ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ, 
    &g_setting_ANISOMODE, 
    &g_setting_ANISO_MODE_LEVEL, 
    &g_setting_ANISO_MODE_SELECTOR, 
    &g_setting_ANSEL_ALLOW, 
    &g_setting_ANSEL_ALLOWLISTED, 
    &g_setting_ANSEL_ALLOW_FREESTYLE_MODE, 
    &g_setting_ANSEL_ALLOW_OFFLINE, 
    &g_setting_ANSEL_BUFFERS_DEPTH_SETTINGS, 
    &g_setting_ANSEL_BUFFERS_DEPTH_WEIGHTS, 
    &g_setting_ANSEL_BUFFERS_DISABLED, 
    &g_setting_ANSEL_BUFFERS_HUDLESS_DRAWCALL, 
    &g_setting_ANSEL_BUFFERS_HUDLESS_SETTINGS, 
    &g_setting_ANSEL_BUFFERS_HUDLESS_WEIGHTS, 
    &g_setting_ANSEL_DENYLIST_ALL_PROFILED, 
    &g_setting_ANSEL_DENYLIST_PER_GAME, 
    &g_setting_ANSEL_ENABLE, 
    &g_setting_ANSEL_ENABLE_OPTIMUS, 
    &g_setting_ANSEL_FREESTYLE_MODE, 
    &g_setting_APIINDICATOR, 
    &g_setting_APPLICATION_PROFILE_NOTIFICATION_TIMEOUT, 
    &g_setting_APPLICATION_STEAM_ID, 
    &g_setting_AUTOFL, 
    &g_setting_BATTERY_BOOST, 
    &g_setting_BATTERY_BOOST_APP_FPS, 
    &g_setting_BG_FRL_FPS, 
    &g_setting_BG_FRL_FPS_NVCPL, 
    &g_setting_CBF_THRESHOLD, 
    &g_setting_CB_ALPHA_CACHELINES_PER_SM, 
    &g_setting_CB_CACHELINES_PER_SM, 
    &g_setting_COLLECTGFEINFO, 
    &g_setting_COMPILER_KNOBS, 
    &g_setting_COMPILER_STATS_FILE, 
    &g_setting_COMPILER_STATS_LEVEL, 
    &g_setting_CONSTANT_COLOR_RENDERING_ENABLE, 
    &g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA, 
    &g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE, 
    &g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE, 
    &g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN, 
    &g_setting_CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED, 
    &g_setting_CONSUMER_STEREO_ENABLE, 
    &g_setting_CONTROLFLOWGUARD_ENABLE, 
    &g_setting_COPROC_STAGING_BUFFER_PLACEMENT, 
    &g_setting_COPROC_WINSAT_SPLIT, 
    &g_setting_CPL_HIDDEN_PROFILE, 
    &g_setting_CROP_L2_CACHE_CONTROL, 
    &g_setting_CUDA_EXCLUDED_GPUS, 
    &g_setting_CULL_BEFORE_FETCH, 
    &g_setting_D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION, 
    &g_setting_D3DOGL_GPU_MAX_POWER, 
    &g_setting_D3DOGL_SANDBAG_DEVICEID, 
    &g_setting_D3DOGL_UNSANDBAG_VIEWPERF, 
    &g_setting_DACACHELINESIZE, 
    &g_setting_DEFAULT_ALLOC_LIST_SIZE, 
    &g_setting_DEFAULT_PATCH_LIST_SIZE, 
    &g_setting_DISABLE_ALLOCINUSE_WAR_MSHYBRID, 
    &g_setting_DISABLE_MSHYBRID_SYNC_ON_RRI, 
    &g_setting_DISABLE_POST_L2_COMPRESSION, 
    &g_setting_DISABLE_USER_DVM, 
    &g_setting_DISPLAYMUX_INDICATOR, 
    &g_setting_DISPLAY_MUX_SWITCH_FLAGS, 
    &g_setting_DRIVERINFOOVERLAY, 
    &g_setting_DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY, 
    &g_setting_DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING, 
    &g_setting_EARLYZHYSTERESIS, 
    &g_setting_EARLYZ_EXPERIMENTS, 
    &g_setting_ENABLE_ASYNC_WIN32_CALLS, 
    &g_setting_ENABLE_BLURAY3D, 
    &g_setting_ENABLE_CE_COMPONENT_REMAPPING, 
    &g_setting_ENABLE_CE_DIRECT_FLIP, 
    &g_setting_ENABLE_CE_MS_HYBRID, 
    &g_setting_ENABLE_INVARIANT_RENDERING, 
    &g_setting_EXPORT_PERF_COUNTERS, 
    &g_setting_EXTERNAL_QUIET_MODE, 
    &g_setting_FERMI_DUMP_NVIR_FLAG, 
    &g_setting_FERMI_SET_L2_CACHE_CONTROL, 
    &g_setting_FERMI_SET_PRIM_CB_THROTTLE, 
    &g_setting_FERMI_SHADER_HEAP_SIZE, 
    &g_setting_FORCE_FLUSH_ON_ACQUIRE_RESOURCE, 
    &g_setting_FPSINDICATOR, 
    &g_setting_FRL_FPS, 
    &g_setting_FRL_FPS_NVCPL, 
    &g_setting_FRL_LOW_LATENCY, 
    &g_setting_FRL_LOW_LATENCY_BUFFER, 
    &g_setting_FRL_LOW_LATENCY_BUFFER_MAX, 
    &g_setting_FRL_LOW_LATENCY_CPU_RENDER_MARGIN, 
    &g_setting_FRL_LOW_LATENCY_GAIN_A, 
    &g_setting_FRL_LOW_LATENCY_GAIN_B, 
    &g_setting_FRL_LOW_LATENCY_GAP_TARGET, 
    &g_setting_FRL_LOW_LATENCY_MAX_SLEEP_PCT, 
    &g_setting_FRL_LOW_LATENCY_OVERLAP_TARGET, 
    &g_setting_FRL_LOW_LATENCY_PROACTIVE_FLUSH, 
    &g_setting_FRL_LOW_LATENCY_RTBO_TARGET, 
    &g_setting_FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR, 
    &g_setting_FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP, 
    &g_setting_FXAA_ALLOW, 
    &g_setting_FXAA_ENABLE, 
    &g_setting_FXAA_INDICATOR_ENABLE, 
    &g_setting_G80_MODEB_OVERRIDE, 
    &g_setting_GFN_FRL_FPS, 
    &g_setting_GRAPHICS_SHADER_PREFETCH, 
    &g_setting_GSYNC_COMPATIBILITY, 
    &g_setting_HDRINDICATOR, 
    &g_setting_HYBRIDPERFSLIENABLE, 
    &g_setting_KEPLER_BALANCED_PRIM_TIMESLICED_MODE, 
    &g_setting_KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE, 
    &g_setting_KEPLER_L1_CACHE_WAR_BUG_986473, 
    &g_setting_KEPLER_USE_SHUFFLE_INSTRUCTION, 
    &g_setting_LATENCY_INDICATOR_AUTOALIGN, 
    &g_setting_LATENCY_INDICATOR_DRAW_NEGATIVE, 
    &g_setting_LATENCY_INDICATOR_DURATION, 
    &g_setting_LATENCY_INDICATOR_ENABLE, 
    &g_setting_LATENCY_INDICATOR_HEIGHT, 
    &g_setting_LATENCY_INDICATOR_POS_X, 
    &g_setting_LATENCY_INDICATOR_POS_Y, 
    &g_setting_LATENCY_INDICATOR_WIDTH, 
    &g_setting_MAXGPUS_MULTIGPU_BROADCAST_SHIM, 
    &g_setting_MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY, 
    &g_setting_MAXWELL_LOW_LOD_OPTIMIZATION, 
    &g_setting_MAXWELL_MMU_WAR_BUG_1317235, 
    &g_setting_MAXWELL_PIXEL_SHADER_BARRIER, 
    &g_setting_MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT, 
    &g_setting_MAXWELL_SCG_FLAGS, 
    &g_setting_MAXWELL_SM_WAR_BUG_1318757, 
    &g_setting_MAXWELL_TILEDCACHE, 
    &g_setting_MAXWELL_TILEDCACHE_BUFFERINTERLEAVE, 
    &g_setting_MAXWELL_TILEDCACHE_CONTROL, 
    &g_setting_MAXWELL_TILEDCACHE_CONTROL_EXTENDED, 
    &g_setting_MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE, 
    &g_setting_MAXWELL_TILEDCACHE_L2_USAGE, 
    &g_setting_MAXWELL_TILEDCACHE_STATETHRESHOLD, 
    &g_setting_MAXWELL_TILEDCACHE_TILESIZE, 
    &g_setting_MAXWELL_WDDM2_FORCE_128K_PTE, 
    &g_setting_MCAFRSHOWOVERLAP, 
    &g_setting_MCALLOWUNRESTRICTEDAFR, 
    &g_setting_MCCOMPAT, 
    &g_setting_MCSFRLOADBALANCE, 
    &g_setting_MCSFRSHOWSPLIT, 
    &g_setting_MCTIMELINE, 
    &g_setting_MESSAGE_BOX_ON_GPU_DISCONNECT, 
    &g_setting_MIPMAPMODE, 
    &g_setting_MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS, 
    &g_setting_MS_HYBRID_COPY_QUEUE_FLAGS, 
    &g_setting_MULTIGPU_BROADCAST_SHIM, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_DUMP_PATH, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_LOG, 
    &g_setting_MULTIGPU_BROADCAST_SHIM_LOG_FILE, 
    &g_setting_MULTIGPU_EOF_COPY_LOOP, 
    &g_setting_NGX_CDN_MODE, 
    &g_setting_NGX_CDN_PRODUCTION_URI, 
    &g_setting_NGX_CDN_STAGING_URI, 
    &g_setting_NGX_DLSS_MODE, 
    &g_setting_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS, 
    &g_setting_NGX_DLSS_SHARPNESS_SETTING, 
    &g_setting_NGX_DLSS_TYPE, 
    &g_setting_NGX_LOG_PATH, 
    &g_setting_NGX_OVERRIDE_HW_CHECK, 
    &g_setting_NGX_PRIVATE_FLAGS, 
    &g_setting_NOFLOATMADENABLE, 
    &g_setting_NVDEVTOOLS_ENABLE_DEBUGGER, 
    &g_setting_NVFEATURES_ALLOW, 
    &g_setting_NVINDICATOR, 
    &g_setting_NV_QUALITY_UPSCALING, 
    &g_setting_OCGCONTROL_FP16_SUPPORT, 
    &g_setting_OCGCONTROL_FP16_USE_FP32_CONVERTERS, 
    &g_setting_OCGCONTROL_GS, 
    &g_setting_OCGCONTROL_HS, 
    &g_setting_OCGCONTROL_KNOBS_STRING, 
    &g_setting_OCGCONTROL_LATENCY_GS, 
    &g_setting_OCGCONTROL_LATENCY_HS, 
    &g_setting_OCGCONTROL_LATENCY_MS, 
    &g_setting_OCGCONTROL_LATENCY_MTS, 
    &g_setting_OCGCONTROL_LATENCY_PS, 
    &g_setting_OCGCONTROL_LATENCY_TS, 
    &g_setting_OCGCONTROL_LATENCY_VS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_GS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_HS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_MS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_MTS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_PS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_TS, 
    &g_setting_OCGCONTROL_MAXINSTINBASICBLOCK_VS, 
    &g_setting_OCGCONTROL_MS, 
    &g_setting_OCGCONTROL_MTS, 
    &g_setting_OCGCONTROL_ORI, 
    &g_setting_OCGCONTROL_PS, 
    &g_setting_OCGCONTROL_TEXBATCH_GS, 
    &g_setting_OCGCONTROL_TEXBATCH_HS, 
    &g_setting_OCGCONTROL_TEXBATCH_MS, 
    &g_setting_OCGCONTROL_TEXBATCH_MTS, 
    &g_setting_OCGCONTROL_TEXBATCH_PS, 
    &g_setting_OCGCONTROL_TEXBATCH_TS, 
    &g_setting_OCGCONTROL_TEXBATCH_VS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_GS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_HS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_MS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_MTS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_PS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_TS, 
    &g_setting_OCGCONTROL_TEXMINPHASE_VS, 
    &g_setting_OCGCONTROL_TS, 
    &g_setting_OCGCONTROL_TXDBATCHSIZE_PS, 
    &g_setting_OCGCONTROL_VS, 
    &g_setting_OPTIMUS_DEBUG, 
    &g_setting_OPTIMUS_HCLONE, 
    &g_setting_OPTIMUS_MAXAA, 
    &g_setting_PASCAL_SCG_COMPUTE1_MIN_SM_COUNT, 
    &g_setting_PASCAL_SCG_COMPUTE1_SM_FACTOR, 
    &g_setting_PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE, 
    &g_setting_PERF_TESLA_UNIT_SELECTION, 
    &g_setting_PHYSXINDICATOR, 
    &g_setting_PHYSX_APPLICATION, 
    &g_setting_PREFERRED_PSTATE, 
    &g_setting_PREVENT_UI_AF_OVERRIDE, 
    &g_setting_PS_ALPHABETA, 
    &g_setting_PS_ALPHABETA_FRACTION, 
    &g_setting_PS_ALPHABETA_STATS, 
    &g_setting_PS_APPSHADEROPT_CANIGNOREINF, 
    &g_setting_PS_APPSHADEROPT_CANIGNORENAN, 
    &g_setting_PS_APPSHADEROPT_CANIGNORESIGNEDZERO, 
    &g_setting_PS_CYCLESTATS, 
    &g_setting_PS_CYCLESTATS_BUCKET_FLAGS, 
    &g_setting_PS_CYCLESTATS_CAPTURE_FLAGS, 
    &g_setting_PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG, 
    &g_setting_PS_CYCLESTATS_DEVICE_TO_LOG, 
    &g_setting_PS_CYCLESTATS_DIRECTORY, 
    &g_setting_PS_CYCLESTATS_DX12_TAGS_HACK, 
    &g_setting_PS_CYCLESTATS_END_FRAME, 
    &g_setting_PS_CYCLESTATS_FLAGS, 
    &g_setting_PS_CYCLESTATS_FLAGS2, 
    &g_setting_PS_CYCLESTATS_GPU_TO_LOG, 
    &g_setting_PS_CYCLESTATS_HOTKEY, 
    &g_setting_PS_CYCLESTATS_LAUNCH_FLAGS, 
    &g_setting_PS_CYCLESTATS_MAX_APP_REGIME_DEPTH, 
    &g_setting_PS_CYCLESTATS_MERGE_FLAGS, 
    &g_setting_PS_CYCLESTATS_PM_CONFIG, 
    &g_setting_PS_CYCLESTATS_PROCESS_TO_LOG, 
    &g_setting_PS_CYCLESTATS_PROFILER_FLAGS, 
    &g_setting_PS_CYCLESTATS_START_FRAME, 
    &g_setting_PS_CYCLESTATS_XFLAGS, 
    &g_setting_PS_DUMPREGISTERS, 
    &g_setting_PS_DUMPREGISTERS_INPUT_FILE, 
    &g_setting_PS_FRAMERATE_LIMITER, 
    &g_setting_PS_FRAMERATE_LIMITER_2_CONTROL, 
    &g_setting_PS_FRAMERATE_LIMITER_GPS_CTRL, 
    &g_setting_PS_FRAMERATE_LOGGER, 
    &g_setting_PS_FRAMERATE_MONITOR_CTRL, 
    &g_setting_PS_FRAMERATE_MONITOR_OVERRIDE, 
    &g_setting_PS_FRAMERATE_MONITOR_REPORTING, 
    &g_setting_PS_FRAMERATE_MONITOR_VR, 
    &g_setting_PS_FRL_LOADING_WAR, 
    &g_setting_PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT, 
    &g_setting_PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_EPOCH, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_FLAGS, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_PRESET, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ, 
    &g_setting_PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE, 
    &g_setting_PS_PIXEL_SHADER_STATS_FLAGS, 
    &g_setting_PS_PUSHBUFFER_DUMP_END_FRAME, 
    &g_setting_PS_PUSHBUFFER_DUMP_START_FRAME, 
    &g_setting_PS_REDUCTION_HACK_HASH_LIST, 
    &g_setting_PS_REDUCTION_KNOBS_LIST, 
    &g_setting_PS_REFLEX_INDICATOR, 
    &g_setting_PS_VERTEX_SHADER_STATS_FLAGS, 
    &g_setting_PS_ZBC_COLOR_VALUES, 
    &g_setting_PS_ZBC_DEPTH_VALUES, 
    &g_setting_PS_ZBC_STENCIL_VALUES, 
    &g_setting_QMD_OCC_MAX_ASYNC, 
    &g_setting_QMD_OCC_MAX_NON_RT, 
    &g_setting_QMD_OCC_MAX_RT, 
    &g_setting_QMD_OCC_MAX_SYNC, 
    &g_setting_QMD_OCC_THRESHOLD_ASYNC, 
    &g_setting_QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL, 
    &g_setting_QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH, 
    &g_setting_QMD_OCC_THRESHOLD_NON_RT, 
    &g_setting_QMD_OCC_THRESHOLD_RT, 
    &g_setting_QMD_OCC_THRESHOLD_SYNC, 
    &g_setting_QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL, 
    &g_setting_QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH, 
    &g_setting_QUIET_MODE, 
    &g_setting_QUIET_MODE_APP_FPS, 
    &g_setting_REFLEX_TEST_MODE, 
    &g_setting_ROOT_TABLE_PREFETCH, 
    &g_setting_RTCORE_BVH_DUMP_HOTKEY, 
    &g_setting_RTCORE_BVH_DUMP_MODE, 
    &g_setting_RTCORE_BVH_DUMP_PATH, 
    &g_setting_RTCORE_DEFAULT_CACHE_CONFIG, 
    &g_setting_RTCORE_DISABLE_SMEM_SPILLS, 
    &g_setting_RTCORE_DUMP_MODULE_CUBINS, 
    &g_setting_RTCORE_DXR_USE_CUDA, 
    &g_setting_RTCORE_EXCEPTION_FLAGS, 
    &g_setting_RTCORE_KNOBS, 
    &g_setting_RTCORE_LOG_LEVEL, 
    &g_setting_RTCORE_MAX_REGISTERS, 
    &g_setting_RTCORE_NUM_ATTRIBUTE_REGS, 
    &g_setting_RTCORE_PRINT_CONTINUATION_SPILLS, 
    &g_setting_RTCORE_PROFILING, 
    &g_setting_RTCORE_PROFILING_ALLOCATION_SIZE, 
    &g_setting_RTCORE_PROFILING_DUMP_COUNT, 
    &g_setting_RTCORE_PROFILING_DUMP_HOTKEY, 
    &g_setting_RTCORE_PROFILING_DUMP_MODE, 
    &g_setting_RTCORE_USE_CUDA, 
    &g_setting_RTCORE_WARPS_PER_CTA, 
    &g_setting_RTCORE_WARPS_PER_CTA_AMPERE, 
    &g_setting_RTCORE_WARPS_PER_CTA_TURING, 
    &g_setting_RTCORE_WAR_BUG_2648362, 
    &g_setting_SETTICKCONTROL, 
    &g_setting_SETTICKCONTROLEARLYZ, 
    &g_setting_SET_ASYNC_LAUNCH_QUEUE_1, 
    &g_setting_SET_NON_RT_LAUNCH_QUEUE_1, 
    &g_setting_SET_RT_LAUNCH_QUEUE_1, 
    &g_setting_SET_SYNC_LAUNCH_QUEUE_1, 
    &g_setting_SHIM_IGPU_TRANSCODING, 
    &g_setting_SHIM_MAXRES, 
    &g_setting_SHIM_MCCOMPAT, 
    &g_setting_SHIM_RENDERING_MODE, 
    &g_setting_SHIM_RENDERING_OPTIONS, 
    &g_setting_SHOW_OPTIMUS_OVERLAY, 
    &g_setting_SLIVIDEO, 
    &g_setting_SLI_GPU_COUNT, 
    &g_setting_SLI_PREDEFINED_GPU_COUNT, 
    &g_setting_SLI_PREDEFINED_GPU_COUNT_DX10, 
    &g_setting_SLI_PREDEFINED_MODE, 
    &g_setting_SLI_PREDEFINED_MODE_DX10, 
    &g_setting_SLI_RENDERING_MODE, 
    &g_setting_SPLIT_ADAPTER_RENDER_DEVICE, 
    &g_setting_STEREO_MCCOMPAT, 
    &g_setting_STEREO_WIN_MODE_IN_SURROUND, 
    &g_setting_TESLAINTERTPCARBITRATIONCONTROL, 
    &g_setting_TESLAOCTVERTICESPERTPC, 
    &g_setting_TESLAPSWAIT, 
    &g_setting_TESLA_ADDDUMMYCREAD, 
    &g_setting_TESLA_ANISO_QUALITY, 
    &g_setting_TESLA_REGBANKSIZE, 
    &g_setting_TESSELLATION_LOD_MULTIPLIER, 
    &g_setting_TILE_COALESCER_TILE_SIZE, 
    &g_setting_TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS, 
    &g_setting_UMD_HIDE_QUADRO_IDENTITY, 
    &g_setting_VCAA_HILITE, 
    &g_setting_VRPRERENDERLIMIT, 
    &g_setting_VRRFEATUREINDICATOR, 
    &g_setting_VRRINDICATOR, 
    &g_setting_VRROVERLAYINDICATOR, 
    &g_setting_VRRREQUESTSTATE, 
    &g_setting_VRR_APP_OVERRIDE, 
    &g_setting_VRR_APP_OVERRIDE_REQUEST_STATE, 
    &g_setting_VRR_DEBUG_OVERRIDE, 
    &g_setting_VRR_MODE, 
    &g_setting_VRR_OVERRIDE_CONTROL, 
    &g_setting_VRR_WINDOWED_APP_OVERRIDE, 
    &g_setting_VR_PERF_LEVEL, 
    &g_setting_VSYNCSMOOTHAFR, 
    &g_setting_VSYNCVRRCONTROL, 
    &g_setting_VSYNC_BEHAVIOR_FLAGS, 
    &g_setting_WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW, 
    &g_setting_WKS_API_STEREO_EYES_EXCHANGE, 
    &g_setting_WKS_API_STEREO_MODE, 
    &g_setting_WKS_API_STEREO_OSD, 
    &g_setting_WKS_CLIENT_ARBITRATION_LOGGING, 
    &g_setting_WKS_CURSOR_MODE, 
    &g_setting_WKS_DEEP_COLOR_DWM_CONTROL, 
    &g_setting_WKS_DISPLAY_REARRANGEMENT_WITHIN16K, 
    &g_setting_WKS_DX_SWAPGROUPS, 
    &g_setting_WKS_FEATURE_DEBUG_CONTROL, 
    &g_setting_WKS_FEATURE_SUPPORT_CONTROL, 
    &g_setting_WKS_MEMORY_ALLOCATION_POLICY, 
    &g_setting_WKS_MOSAIC_TOPOLOGY_REQUESTED, 
    &g_setting_WKS_POST_PROCESSING_ENGINE_CONTROL, 
    &g_setting_WKS_SCANOUT_COMPOSITION_CONTROL, 
    &g_setting_WKS_STEREO_DONGLE_SUPPORT, 
    &g_setting_WKS_STEREO_SUPPORT, 
    &g_setting_WKS_STEREO_SWAP_MODE, 
    &g_setting_YUV_EMULATION_MODE, 
    &g_setting_ZCULL_SUBREGION_ALIQUOT_LIMIT, 
    &g_setting_ZCULL_SUBREGION_FORMATS_0, 
    &g_setting_ZCULL_SUBREGION_FORMATS_1, 
    &g_setting_ZCULL_SUBREGION_REPORT_TYPE, 
    &g_setting_ZCULL_SUBREGION_STRATEGY, 
    &g_setting_ZROP_L2_CACHE_CONTROL, 
};

bool AddSettingsToHashByPlainNameD3DOGL(NvSettingsHash &settingsHash)
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
bool AddSettingsToHashByIdD3DOGL(NvSettingsIdHash &settingsIdHash)
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

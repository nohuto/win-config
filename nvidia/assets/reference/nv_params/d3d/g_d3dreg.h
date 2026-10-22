
/* THIS FILE IS AUTO-GENERATED!  DO NOT EDIT!
**
** To modify this file, regenerate after editing
** any RKY file
*/

#if !defined (_G_D3DREG_H_)
#define _G_D3DREG_H_

#if !defined KERNEL_NOTIFICATION_ID_FLAG 
#define KERNEL_NOTIFICATION_ID_FLAG                                    0x01000000
#define NEEDS_KERNEL_NOTIFICATION(id)                                  (id & KERNEL_NOTIFICATION_ID_FLAG)
#endif // KERNEL_NOTIFICATION_ID_FLAG 

#define AAFEATUREBITS_STRING                                           "32661390"
#define AAFEATUREBITS_ID                                               0x00d55f7d
#define AAFEATUREBITS_OVERINSTALL                                      0 // OVERRIDE
#define AAFEATUREBITS_DEFAULT                                          0x00000000
#define AAFEATUREBITS_FORCE_AA_ON_A16B16G16R16F_TEXTURES_OF_PRIMARY_SIZE 0x00000001
#define AAFEATUREBITS_FORCE_AA_ON_X16B16G16R16F_TEXTURES_OF_PRIMARY_SIZE 0x00000001
#define AAFEATUREBITS_FORCE_AA_ON_A32B32G32R32F_TEXTURES_OF_PRIMARY_SIZE 0x00000002
#define AAFEATUREBITS_DISABLE_AA_ON_PRIMARY                            0x00000004
#define AAFEATUREBITS_UPGRADE_Z24_TO_Z32_FOR_Z_PARTITIONING            0x00000010
#define AAFEATUREBITS_FORCE_SUPERSAMPLING_ON_PRIMARY                   0x00000020
#define AAFEATUREBITS_FORCE_AA_ON_A8R8G8B8_TEXTURES_OF_PRIMARY_SIZE    0x00000040
#define AAFEATUREBITS_FORCE_AA_ON_X8R8G8B8_TEXTURES_OF_PRIMARY_SIZE    0x00000040
#define AAFEATUREBITS_FORCE_OFFSCREEN_SUPERBUFFERS_TO_NOT_DOWNFILTER   0x00000080
#define AAFEATUREBITS_SHARE_A16B16G16R16F_TEXTURE_SUPERBUFFERS         0x00000100
#define AAFEATUREBITS_FORCE_AA_ON_R32F_TEXTURES_OF_PRIMARY_SIZE        0x00000200
#define AAFEATUREBITS_USE_ALTERNATE_BIOSHOCK_TONE_MAPPING_SHADER       0x00000400
#define AAFEATUREBITS_FORCE_SHADER_REPLAY_FOR_A8R8G8B8                 0x00000800
#define AAFEATUREBITS_ALLOW_AA_WITH_MRT                                0x00001000
#define AAFEATUREBITS_FORCE_SHADER_SUPERSAMPLING_WITH_AA_TEXTURES      0x00002000
#define AAFEATUREBITS_USE_ALTERNATE_STALKER_TONE_MAPPING_SHADER        0x00004000
#define AAFEATUREBITS_DISABLE_FOS                                      0x00008000
#define AAFEATUREBITS_FORCE_FILTERING_ON_AA_TEXTURES                   0x00010000
#define AAFEATUREBITS_FORCE_AA_ON_G16R16_TEXTURES_OF_PRIMARY_SIZE      0x00020000
#define AAFEATUREBITS_FORCE_SHADER_REPLAY_WITH_R32F_AA_TEXTURES        0x00040000
#define AAFEATUREBITS_FORCE_POINT_SAMPLING_WITH_R32F_AA_TEXTURES       0x00080000
#define AAFEATUREBITS_ONLY_APPLY_AA_ON_FIRST_A16B16G16R16F_RT          0x00100000
#define AAFEATUREBITS_SHARE_A8R8G8B8_TEXTURE_SUPERBUFFERS              0x00200000
#define AAFEATUREBITS_FORCE_AA_ON_Z24S8_TEXTURES_OF_PRIMARY_SIZE       0x00400000
#define AAFEATUREBITS_FORCE_AA_ON_Z24X8_TEXTURES_OF_PRIMARY_SIZE       0x00400000
#define AAFEATUREBITS_FORCE_AA_ON_SIZES_GREATER_OR_EQUAL               0x08000000
#define AAFEATUREBITS_FORCE_TEXLDP_TO_TEXLD                            0x10000000
#define AAFEATUREBITS_FORCE_CENTROID_EVERYWHERE                        0x20000000
#define AAFEATUREBITS_DISABLE_TESLA_AA_QUALITY_LEVELS                  0x40000000
#define AAFEATUREBITS_COMPILE_BOOL_CONSTS_STATICALLY                   0x80000000
#define AAFEATUREBITS_MASK                                             0xf87ffff7


#define AAMASKENABLE_STRING                                            "10491844"
#define AAMASKENABLE_ID                                                0x00aedcf0
#define AAMASKENABLE_OVERINSTALL                                       0 // OVERRIDE
#define AAMASKENABLE_OFF                                               0x71066283
#define AAMASKENABLE_DISABLED                                          0x71066283
#define AAMASKENABLE_ON                                                0x27658080
#define AAMASKENABLE_ENABLED                                           0x27658080
#define AAMASKENABLE_DEFAULT                                           AAMASKENABLE_ON


#define AATOGGLEHOTKEY_STRING                                          "36594076"
#define AATOGGLEHOTKEY_ID                                              0x0077faf4
#define AATOGGLEHOTKEY_OVERINSTALL                                     0 // OVERRIDE
#define AATOGGLEHOTKEY_MIN                                             0x00000000
#define AATOGGLEHOTKEY_MAX                                             0x0000ffff
#define AATOGGLEHOTKEY_DEFAULT                                         0


#define AA_QUAD_LINE_WIDTH_STRING                                      "82d8cc"
#define AA_QUAD_LINE_WIDTH_ID                                          0x0082d8cc
#define AA_QUAD_LINE_WIDTH_OVERINSTALL                                 0 // OVERRIDE
#define AA_QUAD_LINE_WIDTH_DEFAULT                                     1.0f


#define ACE_POWERMODE_CPU_FREQUENCY_STRING                             "211020"
#define ACE_POWERMODE_CPU_FREQUENCY_ID                                 0x00211020
#define ACE_POWERMODE_CPU_FREQUENCY_OVERINSTALL                        0 // OVERRIDE
#define ACE_POWERMODE_CPU_FREQUENCY_NO_OVERRIDE                        0xffffffff
#define ACE_POWERMODE_CPU_FREQUENCY_DEFAULT_VALUE                      0x00000000


#define ADA_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                       "0x212300"
#define ADA_A_TILEDCACHE_BUFFERINTERLEAVE_ID                           0x00212300
#define ADA_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL                  0 // OVERRIDE
#define ADA_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                      0x0003331B


#define ADA_A_TILEDCACHE_CONTROL_STRING                                "0x212301"
#define ADA_A_TILEDCACHE_CONTROL_ID                                    0x00212301
#define ADA_A_TILEDCACHE_CONTROL_OVERINSTALL                           0 // OVERRIDE
#define ADA_A_TILEDCACHE_CONTROL_DEFAULT                               0x08080202


#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_STRING                       "0x212302"
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_ID                           0x00212302
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL                  0 // OVERRIDE
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_LEVEL1_BBOX_PRIM_COUNT_MASK  0x0000003F
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_LEVEL1_BBOX_PRIM_COUNT_SHIFT 0
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_MAX_CYCLES_WITHOUT_BINNER_DRAIN_MASK 0x00000FC0
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_MAX_CYCLES_WITHOUT_BINNER_DRAIN_SHIFT 6
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_AREA_THRESHOLD_MASK          0x0001F000
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_AREA_THRESHOLD_SHIFT         12
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_UNUSED_MASK                  0xFFFE0000
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_UNUSED_SHIFT                 17
#define ADA_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                      0x0000E008


#define ADA_A_TILEDCACHE_L2_USAGE_STRING                               "0x212304"
#define ADA_A_TILEDCACHE_L2_USAGE_ID                                   0x00212304
#define ADA_A_TILEDCACHE_L2_USAGE_OVERINSTALL                          0 // OVERRIDE
#define ADA_A_TILEDCACHE_L2_USAGE_DEFAULT                              0.7f


#define ADA_A_TILEDCACHE_STATETHRESHOLD_STRING                         "0x0x212303"
#define ADA_A_TILEDCACHE_STATETHRESHOLD_ID                             0x00212303
#define ADA_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                    0 // OVERRIDE
#define ADA_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                        0x00080001


#define AFTERMATH_ENABLE_STRING                                        "110992"
#define AFTERMATH_ENABLE_ID                                            0x00110992
#define AFTERMATH_ENABLE_OVERINSTALL                                   0 // OVERRIDE
#define AFTERMATH_ENABLE_OFF                                           0x00000000
#define AFTERMATH_ENABLE_DISABLED                                      0x00000000
#define AFTERMATH_ENABLE_ON                                            0x00000001
#define AFTERMATH_ENABLE_ENABLED                                       0x00000001
#define AFTERMATH_ENABLE_DEFAULT                                       AFTERMATH_ENABLE_OFF


#define AFTERMATH_FILENAME_STRING                                      "110998"
#define AFTERMATH_FILENAME_ID                                          0x00110998
#define AFTERMATH_FILENAME_OVERINSTALL                                 0 // OVERRIDE


#define AFTERMATH_FLAGS_STRING                                         "110993"
#define AFTERMATH_FLAGS_ID                                             0x00110993
#define AFTERMATH_FLAGS_OVERINSTALL                                    0 // OVERRIDE
#define AFTERMATH_FLAGS_OFF                                            0x00000000
#define AFTERMATH_FLAGS_0                                              0x00000000
#define AFTERMATH_FLAGS_FALSE                                          0x00000000
#define AFTERMATH_FLAGS_DISABLED                                       0x00000000
#define AFTERMATH_FLAGS_MARKERS                                        0x00000001
#define AFTERMATH_FLAGS_RESOURCE_TRACKING                              0x00000002
#define AFTERMATH_FLAGS_GENERATE_CRASH_DUMPS                           0x00000004
#define AFTERMATH_FLAGS_GENERATE_SHADER_DEBUG_INFO                     0x00000008
#define AFTERMATH_FLAGS_LOG_TO_FILE                                    0x20000000
#define AFTERMATH_FLAGS_DETAILED_MARKERS                               0x40000000
#define AFTERMATH_FLAGS_AUTOMATIC_MODE                                 0x80000000
#define AFTERMATH_FLAGS_DEFAULT                                        AFTERMATH_FLAGS_OFF


#define AFTERMATH_FLAGS_DISABLE_MASK_STRING                            "11099A"
#define AFTERMATH_FLAGS_DISABLE_MASK_ID                                0x0011099a
#define AFTERMATH_FLAGS_DISABLE_MASK_OVERINSTALL                       0 // OVERRIDE
#define AFTERMATH_FLAGS_DISABLE_MASK_DEFAULT                           0x0


#define AFTERMATH_INDICATOR_ENABLE_STRING                              "110994"
#define AFTERMATH_INDICATOR_ENABLE_ID                                  0x00110994
#define AFTERMATH_INDICATOR_ENABLE_OVERINSTALL                         0 // OVERRIDE
#define AFTERMATH_INDICATOR_ENABLE_NEVER                               0x00000000
#define AFTERMATH_INDICATOR_ENABLE_0                                   0x00000000
#define AFTERMATH_INDICATOR_ENABLE_OFF                                 0x00000000
#define AFTERMATH_INDICATOR_ENABLE_DISABLED                            0x00000000
#define AFTERMATH_INDICATOR_ENABLE_ALWAYS                              0x00000001
#define AFTERMATH_INDICATOR_ENABLE_1                                   0x00000001
#define AFTERMATH_INDICATOR_ENABLE_DEVELOPER_MODE_ONLY                 0x00000002
#define AFTERMATH_INDICATOR_ENABLE_2                                   0x00000002
#define AFTERMATH_INDICATOR_ENABLE_DEFAULT                             AFTERMATH_INDICATOR_ENABLE_NEVER


#define AFTERMATH_INDICATOR_MODE_STRING                                "11099B"
#define AFTERMATH_INDICATOR_MODE_ID                                    0x0011099b
#define AFTERMATH_INDICATOR_MODE_OVERINSTALL                           0 // OVERRIDE
#define AFTERMATH_INDICATOR_MODE_MINIMAL                               0x00000000
#define AFTERMATH_INDICATOR_MODE_VERBOSE                               0x00000001
#define AFTERMATH_INDICATOR_MODE_DEFAULT                               AFTERMATH_INDICATOR_MODE_MINIMAL


#define AFTERMATH_NUM_EVENTS_PER_BUNDLE_STRING                         "110997"
#define AFTERMATH_NUM_EVENTS_PER_BUNDLE_ID                             0x00110997
#define AFTERMATH_NUM_EVENTS_PER_BUNDLE_OVERINSTALL                    0 // OVERRIDE
#define AFTERMATH_NUM_EVENTS_PER_BUNDLE_DEFAULT                        0x40


#define AFTERMATH_NUM_EVENTS_PER_COMMANDLIST_STRING                    "110996"
#define AFTERMATH_NUM_EVENTS_PER_COMMANDLIST_ID                        0x00110996
#define AFTERMATH_NUM_EVENTS_PER_COMMANDLIST_OVERINSTALL               0 // OVERRIDE
#define AFTERMATH_NUM_EVENTS_PER_COMMANDLIST_DEFAULT                   0x400


#define AFTERMATH_NUM_EVENTS_PER_COMMANDQUEUE_STRING                   "110999"
#define AFTERMATH_NUM_EVENTS_PER_COMMANDQUEUE_ID                       0x00110999
#define AFTERMATH_NUM_EVENTS_PER_COMMANDQUEUE_OVERINSTALL              0 // OVERRIDE
#define AFTERMATH_NUM_EVENTS_PER_COMMANDQUEUE_DEFAULT                  0x200


#define AFTERMATH_NUM_EVENTS_PER_IMMCONTEXT_STRING                     "110995"
#define AFTERMATH_NUM_EVENTS_PER_IMMCONTEXT_ID                         0x00110995
#define AFTERMATH_NUM_EVENTS_PER_IMMCONTEXT_OVERINSTALL                0 // OVERRIDE
#define AFTERMATH_NUM_EVENTS_PER_IMMCONTEXT_DEFAULT                    0x4000


#define ALLOW_DUALPIXEL_RENDERING_STRING                               "4387617f"
#define ALLOW_DUALPIXEL_RENDERING_ID                                   0x00c84ebd
#define ALLOW_DUALPIXEL_RENDERING_OVERINSTALL                          0 // OVERRIDE
#define ALLOW_DUALPIXEL_RENDERING_DEFAULT                              1


#define ALPHA2COVG_DITHER_FOOTPRINT_STRING                             "beeffeeb"
#define ALPHA2COVG_DITHER_FOOTPRINT_ID                                 0x007970a3
#define ALPHA2COVG_DITHER_FOOTPRINT_OVERINSTALL                        0 // OVERRIDE
#define ALPHA2COVG_DITHER_FOOTPRINT_PIXELS_1X1                         0x00000000
#define ALPHA2COVG_DITHER_FOOTPRINT_PIXELS_2X2                         0x00000001
#define ALPHA2COVG_DITHER_FOOTPRINT_PIXELS_1X1_VIRTUAL_SAMPLES         0x00000002
#define ALPHA2COVG_DITHER_FOOTPRINT_DEFAULT                            ALPHA2COVG_DITHER_FOOTPRINT_PIXELS_1X1_VIRTUAL_SAMPLES


#define ALPHABIAS_STRING                                               "A9F3CA0F"
#define ALPHABIAS_ID                                                   0x00fb91ca
#define ALPHABIAS_OVERINSTALL                                          0 // OVERRIDE
#define ALPHABIAS_MIN                                                  0
#define ALPHABIAS_MAX                                                  255
#define ALPHABIAS_DEFAULT                                              0


#define AL_SIZE_12ON7_STRING                                           "0xb21d48"
#define AL_SIZE_12ON7_ID                                               0x00b21d48
#define AL_SIZE_12ON7_OVERINSTALL                                      0 // OVERRIDE
#define AL_SIZE_12ON7_DEFAULT                                          0x3000


#define AMPERE_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                    "0x523df1"
#define AMPERE_A_TILEDCACHE_BUFFERINTERLEAVE_ID                        0x00523df1
#define AMPERE_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL               0 // OVERRIDE
#define AMPERE_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                   0x00022313


#define AMPERE_A_TILEDCACHE_CONTROL_STRING                             "0x523df2"
#define AMPERE_A_TILEDCACHE_CONTROL_ID                                 0x00523df2
#define AMPERE_A_TILEDCACHE_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define AMPERE_A_TILEDCACHE_CONTROL_DEFAULT                            0x08080202


#define AMPERE_A_TILEDCACHE_CONTROL_EXTENDED_STRING                    "0x523df3"
#define AMPERE_A_TILEDCACHE_CONTROL_EXTENDED_ID                        0x00523df3
#define AMPERE_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL               0 // OVERRIDE
#define AMPERE_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                   0x00000008


#define AMPERE_A_TILEDCACHE_L2_USAGE_STRING                            "0x523df5"
#define AMPERE_A_TILEDCACHE_L2_USAGE_ID                                0x00523df5
#define AMPERE_A_TILEDCACHE_L2_USAGE_OVERINSTALL                       0 // OVERRIDE
#define AMPERE_A_TILEDCACHE_L2_USAGE_DEFAULT                           0.5f


#define AMPERE_A_TILEDCACHE_STATETHRESHOLD_STRING                      "0x523df4"
#define AMPERE_A_TILEDCACHE_STATETHRESHOLD_ID                          0x00523df4
#define AMPERE_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                 0 // OVERRIDE
#define AMPERE_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                     0x00080001


#define AMPERE_B_TILEDCACHE_BUFFERINTERLEAVE_STRING                    "0x19104a"
#define AMPERE_B_TILEDCACHE_BUFFERINTERLEAVE_ID                        0x0019104a
#define AMPERE_B_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL               0 // OVERRIDE
#define AMPERE_B_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                   0x0003331B


#define AMPERE_B_TILEDCACHE_CONTROL_STRING                             "0x19104b"
#define AMPERE_B_TILEDCACHE_CONTROL_ID                                 0x0019104b
#define AMPERE_B_TILEDCACHE_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define AMPERE_B_TILEDCACHE_CONTROL_DEFAULT                            0x08080202


#define AMPERE_B_TILEDCACHE_CONTROL_EXTENDED_STRING                    "0x19104c"
#define AMPERE_B_TILEDCACHE_CONTROL_EXTENDED_ID                        0x0019104c
#define AMPERE_B_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL               0 // OVERRIDE
#define AMPERE_B_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                   0x00000008


#define AMPERE_B_TILEDCACHE_L2_USAGE_STRING                            "0x523df6"
#define AMPERE_B_TILEDCACHE_L2_USAGE_ID                                0x00523df6
#define AMPERE_B_TILEDCACHE_L2_USAGE_OVERINSTALL                       0 // OVERRIDE
#define AMPERE_B_TILEDCACHE_L2_USAGE_DEFAULT                           0.7f


#define AMPERE_B_TILEDCACHE_STATETHRESHOLD_STRING                      "0x19104d"
#define AMPERE_B_TILEDCACHE_STATETHRESHOLD_ID                          0x0019104d
#define AMPERE_B_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                 0 // OVERRIDE
#define AMPERE_B_TILEDCACHE_STATETHRESHOLD_DEFAULT                     0x00080001


#define AMPERE_COMPLETION_TRACKER_STRING                               "554321"
#define AMPERE_COMPLETION_TRACKER_ID                                   0x00554321
#define AMPERE_COMPLETION_TRACKER_OVERINSTALL                          0 // OVERRIDE
#define AMPERE_COMPLETION_TRACKER_DISABLE                              0
#define AMPERE_COMPLETION_TRACKER_ENABLE                               0x00000001
#define AMPERE_COMPLETION_TRACKER_FORCE_FOR_GRAPHICS_TIMESTAMPS        0x00000002
#define AMPERE_COMPLETION_TRACKER_DISALLOW_FOR_DIRECT_QUEUES           0x00000004
#define AMPERE_COMPLETION_TRACKER_DISALLOW_HELPER_ON_DIRECT_QUEUES     0x00000008
#define AMPERE_COMPLETION_TRACKER_FORCE_HELPER_ON_ASYNC_QUEUES         0x00000010
#define AMPERE_COMPLETION_TRACKER_DISALLOW_CPU_PATCH_MODE              0x00000080
#define AMPERE_COMPLETION_TRACKER_DISALLOW_DEPENDENT_AFTER_BARRIER     0x00000100
#define AMPERE_COMPLETION_TRACKER_DISALLOW_ACQUIRE_DEFERRAL            0x00000200
#define AMPERE_COMPLETION_TRACKER_DISALLOW_DSC_DEFERRED_BARRIER        0x00000400
#define AMPERE_COMPLETION_TRACKER_DISALLOW_GSCB_PREFETCH               0x00000800
#define AMPERE_COMPLETION_TRACKER_DBG_SKIP_SYSMEMBAR                   0x00008000
#define AMPERE_COMPLETION_TRACKER_MAX_TRACKED_LAUNCHES_SHIFT           16
#define AMPERE_COMPLETION_TRACKER_MAX_TRACKED_LAUNCHES_DEFAULT         0
#define AMPERE_COMPLETION_TRACKER_DEFAULT                              AMPERE_COMPLETION_TRACKER_ENABLE


#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_STRING                     "554561"
#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_ID                         0x00554561
#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_OVERINSTALL                0 // OVERRIDE
#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_DISABLE                    0
#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_ENABLE                     1
#define AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_DEFAULT                    AMPERE_FORCE_MUTABLE_AS_HEAVYWEIGHT_DISABLE


#define AMPERE_GCC_CACHE_BUG_WAR_STRING                                "537561"
#define AMPERE_GCC_CACHE_BUG_WAR_ID                                    0x00537561
#define AMPERE_GCC_CACHE_BUG_WAR_OVERINSTALL                           0 // OVERRIDE
#define AMPERE_GCC_CACHE_BUG_WAR_DISABLE                               0
#define AMPERE_GCC_CACHE_BUG_WAR_ALL_LINES_BY_METHOD                   0x01
#define AMPERE_GCC_CACHE_BUG_WAR_ALL_GCC_BY_PRI                        0x02
#define AMPERE_GCC_CACHE_BUG_WAR_DEFAULT                               AMPERE_GCC_CACHE_BUG_WAR_ALL_LINES_BY_METHOD


#define AMPERE_WAR_HWBUG_3123136_STRING                                "047faff2"
#define AMPERE_WAR_HWBUG_3123136_ID                                    0x003dd400
#define AMPERE_WAR_HWBUG_3123136_OVERINSTALL                           0 // OVERRIDE
#define AMPERE_WAR_HWBUG_3123136_OFF                                   0x00000000
#define AMPERE_WAR_HWBUG_3123136_ON                                    0x00000001
#define AMPERE_WAR_HWBUG_3123136_DEFAULT                               AMPERE_WAR_HWBUG_3123136_ON


#define ANISO_QUALITY_STRING                                           "bfbeee4a"
#define ANISO_QUALITY_ID                                               0x004e9be7
#define ANISO_QUALITY_OVERINSTALL                                      0 // OVERRIDE
#define ANISO_QUALITY_MIN                                              0x0
#define ANISO_QUALITY_tpsNV30                                          0x0
#define ANISO_QUALITY_0                                                0x0
#define ANISO_QUALITY_tpsNV40                                          0x1
#define ANISO_QUALITY_1                                                0x1
#define ANISO_QUALITY_tpsDefault                                       0x2
#define ANISO_QUALITY_2                                                0x2
#define ANISO_QUALITY_tpsAssertive                                     0x3
#define ANISO_QUALITY_3                                                0x3
#define ANISO_QUALITY_tpsAggressive                                    0x4
#define ANISO_QUALITY_4                                                0x4
#define ANISO_QUALITY_tpsFerocious                                     0x5
#define ANISO_QUALITY_5                                                0x5
#define ANISO_QUALITY_tpsNSettings                                     0x6
#define ANISO_QUALITY_6                                                0x6
#define ANISO_QUALITY_MAX                                              0x6
#define ANISO_QUALITY_DEFAULT                                          ANISO_QUALITY_tpsDefault


#define AO2PARAMETERBITS_STRING                                        "85513599"
#define AO2PARAMETERBITS_ID                                            0x0059d320
#define AO2PARAMETERBITS_OVERINSTALL                                   0 // OVERRIDE
#define AO2PARAMETERBITS_DEFAULT                                       0x00000000
#define AO2PARAMETERBITS_NDOTV_BIAS                                    0x00000007
#define AO2PARAMETERBITS_R_MULTIPLIER                                  0x000000f0
#define AO2PARAMETERBITS_AOFOG_DIST_OF_HALF_STRENGTH                   0x0000f000
#define AO2PARAMETERBITS_AOFOG_AMOUNT                                  0x000f0000
#define AO2PARAMETERBITS_BLUR_SHARPNESS                                0x00f00000
#define AO2PARAMETERBITS_STRENGTH                                      0x0f000000
#define AO2PARAMETERBITS_POWER_EXPONENT                                0x30000000
#define AO2PARAMETERBITS_USE_FP16_LINEARZ                              0x80000000
#define AO2PARAMETERBITS_MASK                                          0xbffff0f7


#define AOPARAMETERBITS_STRING                                         "57857894"
#define AOPARAMETERBITS_ID                                             0x00453934
#define AOPARAMETERBITS_OVERINSTALL                                    0 // OVERRIDE
#define AOPARAMETERBITS_DEFAULT                                        0x0033341e
#define AOPARAMETERBITS_ANGLE_BIAS                                     0x0000003f
#define AOPARAMETERBITS_SSAO_SHADER_TYPE                               0x000000c0
#define AOPARAMETERBITS_R_MULTIPLIER                                   0x00000f00
#define AOPARAMETERBITS_NUMBER_OF_DIRECTIONS                           0x0000f000
#define AOPARAMETERBITS_NUMBER_OF_SAMPLES                              0x000f0000
#define AOPARAMETERBITS_SHARPNESS                                      0x00f00000
#define AOPARAMETERBITS_STRENGTH                                       0x0f000000
#define AOPARAMETERBITS_USE_HALFRES_AO                                 0x10000000
#define AOPARAMETERBITS_USE_HALFRES_LINEARZ                            0x20000000
#define AOPARAMETERBITS_USE_FP16_LINEARZ                               0x40000000
#define AOPARAMETERBITS_MASK                                           0x7fffffff


#define AOPARAMETEREXBITS_STRING                                       "57857896"
#define AOPARAMETEREXBITS_ID                                           0x00b7f613
#define AOPARAMETEREXBITS_OVERINSTALL                                  0 // OVERRIDE
#define AOPARAMETEREXBITS_DEFAULT                                      0x0007020a
#define AOPARAMETEREXBITS_BLUR_RADIUS                                  0x0000003f
#define AOPARAMETEREXBITS_AOFOG_DIST_OF_HALF_STRENGTH                  0x00000fc0
#define AOPARAMETEREXBITS_AOFOG_AMOUNT                                 0x0000f000
#define AOPARAMETEREXBITS_MAX_RADIUS_IN_SCREEN_FRACTION                0x00070000
#define AOPARAMETEREXBITS_USE_QUARTER_RESOLUTION                       0x00080000
#define AOPARAMETEREXBITS_USE_BLOCK_REJECTION                          0x00100000
#define AOPARAMETEREXBITS_USE_BLUR_BLOCK_REJECTION                     0x00200000
#define AOPARAMETEREXBITS_USE_MULTI_RESOLUTION                         0x00400000
#define AOPARAMETEREXBITS_USE_FULLRES_REFINEMENT_FOR_LOW_MODE          0x00800000
#define AOPARAMETEREXBITS_DUALRES_VARIATION_THRESHOLD                  0x0f000000
#define AOPARAMETEREXBITS_MASK                                         0x0fffffff


#define AO_MODE_STRING                                                 "AO_MODE"
#define AO_MODE_ID                                                     0x00667329
#define AO_MODE_OVERINSTALL                                            1 // MERGE
#define AO_MODE_OFF                                                    0
#define AO_MODE_LOW                                                    1
#define AO_MODE_MEDIUM                                                 2
#define AO_MODE_HIGH                                                   3
#define AO_MODE_DEFAULT                                                AO_MODE_OFF


#define AO_MODE_ACTIVE_STRING                                          "AO_MODE_ACTIVE"
#define AO_MODE_ACTIVE_ID                                              0x00664339
#define AO_MODE_ACTIVE_OVERINSTALL                                     0 // OVERRIDE
#define AO_MODE_ACTIVE_DISABLED                                        0
#define AO_MODE_ACTIVE_OFF                                             0
#define AO_MODE_ACTIVE_ENABLED                                         1
#define AO_MODE_ACTIVE_ON                                              1
#define AO_MODE_ACTIVE_DEFAULT                                         AO_MODE_ACTIVE_DISABLED


#define AO_MODE_FLAGS_STRING                                           "AO_FLAGS"
#define AO_MODE_FLAGS_ID                                               0x002c7f45
#define AO_MODE_FLAGS_OVERINSTALL                                      0 // OVERRIDE
#define AO_MODE_FLAGS_NONE                                             0
#define AO_MODE_FLAGS_DEFAULT                                          AO_MODE_FLAGS_NONE


#define APPCOMMANDLINE_STRING                                          "23132857"
#define APPCOMMANDLINE_ID                                              0x00d9ca3b
#define APPCOMMANDLINE_OVERINSTALL                                     0 // OVERRIDE


#define APP_COMPAT_SHIM_STRING                                         "B8231431"
#define APP_COMPAT_SHIM_ID                                             0x00b82343
#define APP_COMPAT_SHIM_OVERINSTALL                                    0 // OVERRIDE
#define APP_COMPAT_SHIM_DISABLED                                       0x00000000
#define APP_COMPAT_SHIM_OFF                                            0x00000000
#define APP_COMPAT_SHIM_0                                              0x00000000
#define APP_COMPAT_SHIM_DX11_FORCE_DDI_CRITICAL_SECTION                0x00000001
#define APP_COMPAT_SHIM_DX11_FORCE_DDI_CRITICAL_SECTION_FOR_STEREO     0x00000002
#define APP_COMPAT_SHIM_MASK                                           0x00000003
#define APP_COMPAT_SHIM_DEFAULT                                        APP_COMPAT_SHIM_DISABLED


#define ASSERT_ON_SHADER_FP64_STRING                                   "220125"
#define ASSERT_ON_SHADER_FP64_ID                                       0x00220125
#define ASSERT_ON_SHADER_FP64_OVERINSTALL                              0 // OVERRIDE
#define ASSERT_ON_SHADER_FP64_OFF                                      0
#define ASSERT_ON_SHADER_FP64_DISABLED                                 0
#define ASSERT_ON_SHADER_FP64_ON                                       1
#define ASSERT_ON_SHADER_FP64_ENABLED                                  1
#define ASSERT_ON_SHADER_FP64_DEFAULT                                  ASSERT_ON_SHADER_FP64_OFF


#define ASYNC10_DEVFLAGS_STRING                                        "34217570"
#define ASYNC10_DEVFLAGS_ID                                            0x0007e65d
#define ASYNC10_DEVFLAGS_OVERINSTALL                                   0 // OVERRIDE
#define ASYNC10_DEVFLAGS_DISPLAY_HISTORY                               0x00000001
#define ASYNC10_DEVFLAGS_DISPLAY_CPU_METER                             0x00000002
#define ASYNC10_DEVFLAGS_DISPLAY_FPS                                   0x00000004
#define ASYNC10_DEVFLAGS_DISPLAY_ONLY_WHEN_HOT_KEY_DOWN                0x00000008
#define ASYNC10_DEVFLAGS_DUMP_STATISTICS                               0x00000010
#define ASYNC10_DEVFLAGS_INCLUDE_PER_FRAME_STATS                       0x00000020
#define ASYNC10_DEVFLAGS_INCLUDE_QUEUE_LENGTH_STATS                    0x00000040
#define ASYNC10_DEVFLAGS_INCLUDE_COMMUNICATION_STATS                   0x00000080
#define ASYNC10_DEVFLAGS_RECORD_ONLY_WHEN_HOT_KEY_DOWN                 0x00000100
#define ASYNC10_DEVFLAGS_SET_ALLOWED_PROCESSOR                         0x00001000
#define ASYNC10_DEVFLAGS_SET_IDEAL_PROCESSOR                           0x00002000
#define ASYNC10_DEVFLAGS_SET_IDEAL_PROCESSOR_AVOID_DPCS                0x00004000
#define ASYNC10_DEVFLAGS_DISABLE_REFCOUNT_PRESENTLIMIT                 0x00080000
#define ASYNC10_DEVFLAGS_DISABLE_OS_THREADING_APIS                     0x00100000
#define ASYNC10_DEVFLAGS_ON_ONLY_WHEN_HOT_KEY_DOWN                     0x04000000
#define ASYNC10_DEVFLAGS_FORCE_DUAL_CORE                               0x20000000


#define ASYNC10_ENABLE_STRING                                          "83527290"
#define ASYNC10_ENABLE_ID                                              0x0005f511
#define ASYNC10_ENABLE_OVERINSTALL                                     0 // OVERRIDE
#define ASYNC10_ENABLE_APP                                             0x37605835
#define ASYNC10_ENABLE_OFF                                             0x53850673
#define ASYNC10_ENABLE_ON                                              0x42563729


#define ASYNC10_HOT_KEYS_STRING                                        "93764542"
#define ASYNC10_HOT_KEYS_ID                                            0x0008831a
#define ASYNC10_HOT_KEYS_OVERINSTALL                                   0 // OVERRIDE


#define ASYNC10_NVAPI_MODE_STRING                                      "83527a31"
#define ASYNC10_NVAPI_MODE_ID                                          0x005f5a32
#define ASYNC10_NVAPI_MODE_OVERINSTALL                                 0 // OVERRIDE
#define ASYNC10_NVAPI_MODE_ALLOW_NONBLOCKING_NVAPI                     1
#define ASYNC10_NVAPI_MODE_ALLOW_NOBLOCKING_SLISTATE                   2
#define ASYNC10_NVAPI_MODE_DEFAULT                                     0x00000003


#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_STRING                 "0562AEDF"
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_ID                     0x00effedf
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_OVERINSTALL            0 // OVERRIDE
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_ECORE                  0x00000001
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_PCORE                  0x00000002
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_ALL                    0x00000003
#define ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_DEFAULT                ASYNC10_PREFERRED_EFFICIENCY_CLASS_MASK_ALL


#define ASYNC10_PRESENT_MODE_STRING                                    "83527291"
#define ASYNC10_PRESENT_MODE_ID                                        0x0005f512
#define ASYNC10_PRESENT_MODE_OVERINSTALL                               0 // OVERRIDE
#define ASYNC10_PRESENT_MODE_DEFAULT                                   0x96184013
#define ASYNC10_PRESENT_MODE_SYNC                                      0x53855200
#define ASYNC10_PRESENT_MODE_ASYNC                                     0x89624578
#define ASYNC10_PRESENT_MODE_ASYNC_ALL                                 0x89344578


#define ASYNC10_QUERYGETDATA_GPUWAIT_COUNT_STRING                      "83527a33"
#define ASYNC10_QUERYGETDATA_GPUWAIT_COUNT_ID                          0x005f5a33
#define ASYNC10_QUERYGETDATA_GPUWAIT_COUNT_OVERINSTALL                 0 // OVERRIDE
#define ASYNC10_QUERYGETDATA_GPUWAIT_COUNT_DEFAULT                     10


#define ASYNC10_QUERYGETDATA_SLEEP_COUNT_STRING                        "83527a34"
#define ASYNC10_QUERYGETDATA_SLEEP_COUNT_ID                            0x005f5a34
#define ASYNC10_QUERYGETDATA_SLEEP_COUNT_OVERINSTALL                   0 // OVERRIDE
#define ASYNC10_QUERYGETDATA_SLEEP_COUNT_DEFAULT                       1000


#define ASYNC10_QUEUE_SIZE_STRING                                      "76256344"
#define ASYNC10_QUEUE_SIZE_ID                                          0x006ea977
#define ASYNC10_QUEUE_SIZE_OVERINSTALL                                 0 // OVERRIDE


#define ASYNC10_SPIN_COUNT_STRING                                      "23654839"
#define ASYNC10_SPIN_COUNT_ID                                          0x00f32647
#define ASYNC10_SPIN_COUNT_OVERINSTALL                                 0 // OVERRIDE


#define ASYNC10_STACK_SIZE_STRING                                      "63539284"
#define ASYNC10_STACK_SIZE_ID                                          0x00c26905
#define ASYNC10_STACK_SIZE_OVERINSTALL                                 0 // OVERRIDE


#define ASYNC10_STATS_FIRST_FRAME_STRING                               "46382920"
#define ASYNC10_STATS_FIRST_FRAME_ID                                   0x00b96730
#define ASYNC10_STATS_FIRST_FRAME_OVERINSTALL                          0 // OVERRIDE


#define ASYNC10_STATS_LAST_FRAME_STRING                                "93745629"
#define ASYNC10_STATS_LAST_FRAME_ID                                    0x0054f34e
#define ASYNC10_STATS_LAST_FRAME_OVERINSTALL                           0 // OVERRIDE


#define ASYNC10_SYNC_CALLBACK_MASK_STRING                              "72638202"
#define ASYNC10_SYNC_CALLBACK_MASK_ID                                  0x0050afe7
#define ASYNC10_SYNC_CALLBACK_MASK_OVERINSTALL                         0 // OVERRIDE


#define ASYNC10_THREAD_PRIORITY_STRING                                 "93764541"
#define ASYNC10_THREAD_PRIORITY_ID                                     0x00088319
#define ASYNC10_THREAD_PRIORITY_OVERINSTALL                            0 // OVERRIDE


#define ASYNC9_AFFINITY_STRING                                         "93527201"
#define ASYNC9_AFFINITY_ID                                             0x0015f522
#define ASYNC9_AFFINITY_OVERINSTALL                                    0 // OVERRIDE
#define ASYNC9_AFFINITY_AVOID_CLIENT_AFFINITY                          0x000000
#define ASYNC9_AFFINITY_DONT_CHANGE_AFFINITY                           0x000001
#define ASYNC9_AFFINITY_FORCE_AFFINITY_ONCE                            0x000002
#define ASYNC9_AFFINITY_FORCE_AFFINITY                                 0x000003
#define ASYNC9_AFFINITY_AFFINITY_MASK                                  0x0000ff
#define ASYNC9_AFFINITY_CLIENT_PROCESSOR_MASK                          0x00ff00
#define ASYNC9_AFFINITY_SERVER_PROCESSOR_MASK                          0xff0000
#define ASYNC9_AFFINITY_CLIENT_PROCESSOR_SHIFT                         8
#define ASYNC9_AFFINITY_SERVER_PROCESSOR_SHIFT                         16


#define ASYNC9_DEVFLAGS_STRING                                         "44217570"
#define ASYNC9_DEVFLAGS_ID                                             0x0017e65d
#define ASYNC9_DEVFLAGS_OVERINSTALL                                    0 // OVERRIDE
#define ASYNC9_DEVFLAGS_DISPLAY_CPU_METER                              0x00000002
#define ASYNC9_DEVFLAGS_DISPLAY_FPS                                    0x00000004
#define ASYNC9_DEVFLAGS_DISPLAY_ONLY_WHEN_HOT_KEY_DOWN                 0x00000008
#define ASYNC9_DEVFLAGS_DUMP_STATISTICS                                0x00000010
#define ASYNC9_DEVFLAGS_INCLUDE_PER_FRAME_STATS                        0x00000020
#define ASYNC9_DEVFLAGS_INCLUDE_QUEUE_LENGTH_STATS                     0x00000040
#define ASYNC9_DEVFLAGS_INCLUDE_COMMUNICATION_STATS                    0x00000080
#define ASYNC9_DEVFLAGS_RECORD_ONLY_WHEN_HOT_KEY_DOWN                  0x00000100
#define ASYNC9_DEVFLAGS_PAUSE_FOR_DEBUG_AT_CREATION                    0x00000200
#define ASYNC9_DEVFLAGS_SET_ALLOWED_PROCESSOR                          0x00001000
#define ASYNC9_DEVFLAGS_SET_IDEAL_PROCESSOR                            0x00002000
#define ASYNC9_DEVFLAGS_DISABLE_ASYNC_LOCKS                            0x00010000
#define ASYNC9_DEVFLAGS_DISABLE_UM_STREAM0_OPT                         0x00080000
#define ASYNC9_DEVFLAGS_DISABLE_UM_DRAW_WHILE_LOCKED                   0x00100000
#define ASYNC9_DEVFLAGS_FORCE_DUAL_CORE                                0x20000000


#define ASYNC9_ENABLE_STRING                                           "a392f4de"
#define ASYNC9_ENABLE_ID                                               0x0092f4de
#define ASYNC9_ENABLE_OVERINSTALL                                      0 // OVERRIDE
#define ASYNC9_ENABLE_APP                                              0x37605835
#define ASYNC9_ENABLE_WHENSAFE                                         0x37605846
#define ASYNC9_ENABLE_OFF                                              0x53850673
#define ASYNC9_ENABLE_ON                                               0x42563729
#define ASYNC9_ENABLE_ONIFQUADRO                                       0x42563730
#define ASYNC9_ENABLE_MICROSOFT                                        0x75328097


#define ASYNC9_HOT_KEYS_STRING                                         "03764542"
#define ASYNC9_HOT_KEYS_ID                                             0x0018831a
#define ASYNC9_HOT_KEYS_OVERINSTALL                                    0 // OVERRIDE


#define ASYNC9_MAX_QUEUED_UPDATE_SIZE_STRING                           "00374528"
#define ASYNC9_MAX_QUEUED_UPDATE_SIZE_ID                               0x00c6b2f6
#define ASYNC9_MAX_QUEUED_UPDATE_SIZE_OVERINSTALL                      0 // OVERRIDE


#define ASYNC9_PRESENT_MODE_STRING                                     "93527291"
#define ASYNC9_PRESENT_MODE_ID                                         0x0015f512
#define ASYNC9_PRESENT_MODE_OVERINSTALL                                0 // OVERRIDE
#define ASYNC9_PRESENT_MODE_SYNC                                       0x53855200
#define ASYNC9_PRESENT_MODE_ASYNC                                      0x96184013
#define ASYNC9_PRESENT_MODE_ASYNCFS                                    0x57236402
#define ASYNC9_PRESENT_MODE_FORCEASYNC                                 0x89624578
#define ASYNC9_PRESENT_MODE_FORCEASYNCFS                               0x32469276


#define ASYNC9_QUEUE_SIZE_STRING                                       "86256344"
#define ASYNC9_QUEUE_SIZE_ID                                           0x007ea977
#define ASYNC9_QUEUE_SIZE_OVERINSTALL                                  0 // OVERRIDE


#define ASYNC9_SPIN_COUNT_STRING                                       "33654839"
#define ASYNC9_SPIN_COUNT_ID                                           0x00032647
#define ASYNC9_SPIN_COUNT_OVERINSTALL                                  0 // OVERRIDE


#define ASYNC9_STACK_SIZE_STRING                                       "73539284"
#define ASYNC9_STACK_SIZE_ID                                           0x00d26905
#define ASYNC9_STACK_SIZE_OVERINSTALL                                  0 // OVERRIDE


#define ASYNC9_STATS_FIRST_FRAME_STRING                                "56382920"
#define ASYNC9_STATS_FIRST_FRAME_ID                                    0x00c96730
#define ASYNC9_STATS_FIRST_FRAME_OVERINSTALL                           0 // OVERRIDE


#define ASYNC9_STATS_LAST_FRAME_STRING                                 "03745629"
#define ASYNC9_STATS_LAST_FRAME_ID                                     0x0064f34e
#define ASYNC9_STATS_LAST_FRAME_OVERINSTALL                            0 // OVERRIDE


#define ASYNC9_THREAD_PRIORITY_STRING                                  "93764540"
#define ASYNC9_THREAD_PRIORITY_ID                                      0x00088318
#define ASYNC9_THREAD_PRIORITY_OVERINSTALL                             0 // OVERRIDE


#define ASYNC_UMD_METERING_STRING                                      "c96f61"
#define ASYNC_UMD_METERING_ID                                          0x00c96f61
#define ASYNC_UMD_METERING_OVERINSTALL                                 0 // OVERRIDE
#define ASYNC_UMD_METERING_ALLOW_2WAY                                  0x01
#define ASYNC_UMD_METERING_ALLOW_3WAY                                  0x02
#define ASYNC_UMD_METERING_ALLOW_4WAY                                  0x04
#define ASYNC_UMD_METERING_METER0_ENABLED                              0x08
#define ASYNC_UMD_METERING_METER1_ENABLED                              0x10
#define ASYNC_UMD_METERING_DEFAULT                                     0x00000017


#define ATOCBIAS_STRING                                                "56393763"
#define ATOCBIAS_ID                                                    0x00bf7c7f
#define ATOCBIAS_OVERINSTALL                                           0 // OVERRIDE
#define ATOCBIAS_MIN                                                   0
#define ATOCBIAS_MAX                                                   255
#define ATOCBIAS_DEFAULT                                               127


#define ATOCSHARPNESS_STRING                                           "56393762"
#define ATOCSHARPNESS_ID                                               0x00f6eb29
#define ATOCSHARPNESS_OVERINSTALL                                      0 // OVERRIDE
#define ATOCSHARPNESS_MIN                                              0x0000
#define ATOCSHARPNESS_MAX                                              0x2000
#define ATOCSHARPNESS_DEFAULT                                          0


#define AUTO_LODBIASADJUST_STRING                                      "88481300"
#define AUTO_LODBIASADJUST_ID                                          0x00638e8f
#define AUTO_LODBIASADJUST_OVERINSTALL                                 1 // MERGE
#define AUTO_LODBIASADJUST_OFF                                         0x00000000
#define AUTO_LODBIASADJUST_DISABLED                                    0x00000000
#define AUTO_LODBIASADJUST_ON                                          0x00000001
#define AUTO_LODBIASADJUST_ENABLED                                     0x00000001
#define AUTO_LODBIASADJUST_DEFAULT                                     AUTO_LODBIASADJUST_ON


#define AVOID_HOST_REMAPPERS_STRING                                    "89527726"
#define AVOID_HOST_REMAPPERS_ID                                        0x00f63a50
#define AVOID_HOST_REMAPPERS_OVERINSTALL                               0 // OVERRIDE
#define AVOID_HOST_REMAPPERS_OFF                                       0x0
#define AVOID_HOST_REMAPPERS_DISABLED                                  0x0
#define AVOID_HOST_REMAPPERS_ON                                        0x1
#define AVOID_HOST_REMAPPERS_ENABLED                                   0x1
#define AVOID_HOST_REMAPPERS_DEFAULT                                   AVOID_HOST_REMAPPERS_OFF


#define BAR_INDICATOR_STRING                                           "452114"
#define BAR_INDICATOR_ID                                               0x00452114
#define BAR_INDICATOR_OVERINSTALL                                      0 // OVERRIDE
#define BAR_INDICATOR_OFF                                              0x00000000
#define BAR_INDICATOR_0                                                0x00000000
#define BAR_INDICATOR_FALSE                                            0x00000000
#define BAR_INDICATOR_DISABLED                                         0x00000000
#define BAR_INDICATOR_DISPLAY_COUNT_MASK                               0x0000000F
#define BAR_INDICATOR_FRAME_COUNT_MASK                                 0x000000F0
#define BAR_INDICATOR_WIDTH_PERCENT_MASK                               0x00007F00
#define BAR_INDICATOR_SPEED_MASK                                       0x00FF0000
#define BAR_INDICATOR_DRAW_PORTRAIT                                    0x00008000
#define BAR_INDICATOR_SWITCH_COLORS                                    0x80000000
#define BAR_INDICATOR_MASK                                             0x80FFFFFF
#define BAR_INDICATOR_SINGLE_MOVING_BAR                                0X00100000
#define BAR_INDICATOR_DEFAULT                                          BAR_INDICATOR_OFF


#define BCTEXCOMPRESSENABLE_STRING                                     "2161f727"
#define BCTEXCOMPRESSENABLE_ID                                         0x0085f727
#define BCTEXCOMPRESSENABLE_OVERINSTALL                                0 // OVERRIDE
#define BCTEXCOMPRESSENABLE_OFF                                        0x0
#define BCTEXCOMPRESSENABLE_ON                                         0x1
#define BCTEXCOMPRESSENABLE_DEFAULT                                    BCTEXCOMPRESSENABLE_OFF


#define BM_OFFER_RECLAIM_STRING                                        "32626594"
#define BM_OFFER_RECLAIM_ID                                            0x00dc68b0
#define BM_OFFER_RECLAIM_OVERINSTALL                                   0 // OVERRIDE
#define BM_OFFER_RECLAIM_DISABLE_OFFER_SMALL_BLOCKS                    0x00000001
#define BM_OFFER_RECLAIM_DISABLE_INTERNAL_OFFER_RECLAIM                0x00000002
#define BM_OFFER_RECLAIM_DISABLE_ALL_OFFER_RECLAIM                     0x00000004
#define BM_OFFER_RECLAIM_DEFAULT                                       0x00000000


#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_STRING                    "0162ABA0"
#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_ID                        0x0011fba0
#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_OVERINSTALL               0 // OVERRIDE
#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_OFF                       0x00000000
#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_ON                        0x00000001
#define BOUND_RESOURCE_TEX_HEADER_VERSIONING_DEFAULT                   BOUND_RESOURCE_TEX_HEADER_VERSIONING_ON


#define BREAK_ON_DEVICE_REPORTERROR_STRING                             "0562AECF"
#define BREAK_ON_DEVICE_REPORTERROR_ID                                 0x00effecf
#define BREAK_ON_DEVICE_REPORTERROR_OVERINSTALL                        0 // OVERRIDE
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_GENERATE_FAILURE          0x0001
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_D3DDDIERR_DEVICEREMOVED   0x0010
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_E_OUTOFMEMORY             0x0020
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_DXGI_DDI_ERR_NONEXCLUSIVE 0x0040
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_DXGI_DDI_ERR_WASSTILLDRAWING 0x0080
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_DXGI_DDI_ERR_UNSUPPORTED  0x0100
#define BREAK_ON_DEVICE_REPORTERROR_BREAK_ON_E_INVALIDARG              0x0200
#define BREAK_ON_DEVICE_REPORTERROR_DEFAULT                            0x0


#define BREAK_ON_ENTRY_STRING                                          "83930258"
#define BREAK_ON_ENTRY_ID                                              0x00b0ae1d
#define BREAK_ON_ENTRY_OVERINSTALL                                     0 // OVERRIDE


#define BREAK_ON_ENTRY_CALLS_STRING                                    "83930260"
#define BREAK_ON_ENTRY_CALLS_ID                                        0x006447ee
#define BREAK_ON_ENTRY_CALLS_OVERINSTALL                               0 // OVERRIDE


#define BREAK_ON_ENTRY_FRAMES_STRING                                   "83930259"
#define BREAK_ON_ENTRY_FRAMES_ID                                       0x0012a3cd
#define BREAK_ON_ENTRY_FRAMES_OVERINSTALL                              0 // OVERRIDE


#define BREAK_ON_OCG_ASSERT_STRING                                     "3aa208"
#define BREAK_ON_OCG_ASSERT_ID                                         0x003aa208
#define BREAK_ON_OCG_ASSERT_OVERINSTALL                                0 // OVERRIDE
#define BREAK_ON_OCG_ASSERT_OFF                                        0x16564886
#define BREAK_ON_OCG_ASSERT_DISABLED                                   0x16564886
#define BREAK_ON_OCG_ASSERT_ON                                         0x18826043
#define BREAK_ON_OCG_ASSERT_ENABLED                                    0x18826043
#define BREAK_ON_OCG_ASSERT_DEFAULT                                    BREAK_ON_OCG_ASSERT_ON


#define BREAK_ON_OCG_CRASH_STRING                                      "56b7d8"
#define BREAK_ON_OCG_CRASH_ID                                          0x0056b7d8
#define BREAK_ON_OCG_CRASH_OVERINSTALL                                 0 // OVERRIDE
#define BREAK_ON_OCG_CRASH_OFF                                         0x16564886
#define BREAK_ON_OCG_CRASH_DISABLED                                    0x16564886
#define BREAK_ON_OCG_CRASH_ON                                          0x18826043
#define BREAK_ON_OCG_CRASH_ENABLED                                     0x18826043
#define BREAK_ON_OCG_CRASH_DEFAULT                                     BREAK_ON_OCG_CRASH_ON


#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_STRING                  "50612337"
#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_ID                      0x00b78cbe
#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_OVERINSTALL             0 // OVERRIDE
#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_DISABLE                 0x0
#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_ENABLE                  0x1
#define BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_DEFAULT                 BROADCAST_EXPLICIT_SLI_DESCRIPTOR_HEAP_DISABLE


#define BUFFERCOMPRESSENABLE_STRING                                    "2161f726"
#define BUFFERCOMPRESSENABLE_ID                                        0x0085f726
#define BUFFERCOMPRESSENABLE_OVERINSTALL                               0 // OVERRIDE
#define BUFFERCOMPRESSENABLE_OFF                                       0x99388100
#define BUFFERCOMPRESSENABLE_DISABLED                                  0x99388100
#define BUFFERCOMPRESSENABLE_ON                                        0x25558997
#define BUFFERCOMPRESSENABLE_ENABLED                                   0x25558997
#define BUFFERCOMPRESSENABLE_FORCE_ON                                  0x25678997
#define BUFFERCOMPRESSENABLE_DEFAULT                                   BUFFERCOMPRESSENABLE_ON


#define CE_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_STRING               "012aez24"
#define CE_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_ID                   0x001f3313
#define CE_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_OVERINSTALL          0 // OVERRIDE
#define CE_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_DEFAULT              0


#define CE_LARGE_PUSHBUFFER_SIZE_STRING                                "012aez23"
#define CE_LARGE_PUSHBUFFER_SIZE_ID                                    0x001f3312
#define CE_LARGE_PUSHBUFFER_SIZE_OVERINSTALL                           0 // OVERRIDE
#define CE_LARGE_PUSHBUFFER_SIZE_DEFAULT                               0


#define CE_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_STRING               "012aez22"
#define CE_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_ID                   0x001f3311
#define CE_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_OVERINSTALL          0 // OVERRIDE
#define CE_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_DEFAULT              512


#define CE_SMALL_PUSHBUFFER_SIZE_STRING                                "012aez21"
#define CE_SMALL_PUSHBUFFER_SIZE_ID                                    0x001f3310
#define CE_SMALL_PUSHBUFFER_SIZE_OVERINSTALL                           0 // OVERRIDE
#define CE_SMALL_PUSHBUFFER_SIZE_DEFAULT                               16384


#define CHANNEL_P2P_COPY_NODE_STRING                                   "3946a9"
#define CHANNEL_P2P_COPY_NODE_ID                                       0x003946a9
#define CHANNEL_P2P_COPY_NODE_OVERINSTALL                              0 // OVERRIDE
#define CHANNEL_P2P_COPY_NODE_DISABLE                                  0
#define CHANNEL_P2P_COPY_NODE_LOW_NODE                                 1
#define CHANNEL_P2P_COPY_NODE_MEDIUM_NODE                              2
#define CHANNEL_P2P_COPY_NODE_HIGH_NODE                                3
#define CHANNEL_P2P_COPY_NODE_CE0_NODE                                 4
#define CHANNEL_P2P_COPY_NODE_CE1_NODE                                 5
#define CHANNEL_P2P_COPY_NODE_CE2_NODE                                 6
#define CHANNEL_P2P_COPY_NODE_DISABLE_MASK                             0xf0000000
#define CHANNEL_P2P_COPY_NODE_DISABLE_DX11                             0x10000000
#define CHANNEL_P2P_COPY_NODE_DISABLE_DX12                             0x20000000
#define CHANNEL_P2P_COPY_NODE_DEFAULT                                  0x20000006


#define CHANNEL_PRESENT_COPY_NODE_STRING                               "3846a8"
#define CHANNEL_PRESENT_COPY_NODE_ID                                   0x003846a8
#define CHANNEL_PRESENT_COPY_NODE_OVERINSTALL                          0 // OVERRIDE
#define CHANNEL_PRESENT_COPY_NODE_DISABLE                              0
#define CHANNEL_PRESENT_COPY_NODE_LOW_NODE                             1
#define CHANNEL_PRESENT_COPY_NODE_MEDIUM_NODE                          2
#define CHANNEL_PRESENT_COPY_NODE_HIGH_NODE                            3
#define CHANNEL_PRESENT_COPY_NODE_CE0_NODE                             4
#define CHANNEL_PRESENT_COPY_NODE_CE1_NODE                             5
#define CHANNEL_PRESENT_COPY_NODE_CE2_NODE                             6
#define CHANNEL_PRESENT_COPY_NODE_DEFAULT                              CHANNEL_PRESENT_COPY_NODE_LOW_NODE


#define CKREF_STRING                                                   "80965453"
#define CKREF_ID                                                       0x00578dc5
#define CKREF_OVERINSTALL                                              0 // OVERRIDE
#define CKREF_MIN                                                      0x00
#define CKREF_MAX                                                      0x7f
#define CKREF_DEFAULT                                                  CKREF_MIN


#define CNULLWAR_STRING                                                "B31C61BE"
#define CNULLWAR_ID                                                    0x000470d4
#define CNULLWAR_OVERINSTALL                                           0 // OVERRIDE
#define CNULLWAR_NONE                                                  0x00
#define CNULLWAR_MIN                                                   0x00
#define CNULLWAR_PIXELKILL                                             0x01
#define CNULLWAR_ALPHATEST                                             0x02
#define CNULLWAR_PIXELKILL_AND_ALPHATEST                               0x03
#define CNULLWAR_MAX                                                   0x03
#define CNULLWAR_DEFAULT                                               CNULLWAR_PIXELKILL


#define COLORCOMPRESSENABLE_STRING                                     "21612733"
#define COLORCOMPRESSENABLE_ID                                         0x0085f725
#define COLORCOMPRESSENABLE_OVERINSTALL                                0 // OVERRIDE
#define COLORCOMPRESSENABLE_OFF                                        0x99388100
#define COLORCOMPRESSENABLE_DISABLED                                   0x99388100
#define COLORCOMPRESSENABLE_ON                                         0x25558997
#define COLORCOMPRESSENABLE_ENABLED                                    0x25558997
#define COLORCOMPRESSENABLE_DEFAULT                                    COLORCOMPRESSENABLE_ON


#define COMPUTE_MME_SUPPORT_STRING                                     "F42AD0"
#define COMPUTE_MME_SUPPORT_ID                                         0x00f42ad0
#define COMPUTE_MME_SUPPORT_OVERINSTALL                                0 // OVERRIDE
#define COMPUTE_MME_SUPPORT_DISABLED                                   0
#define COMPUTE_MME_SUPPORT_OFF                                        0
#define COMPUTE_MME_SUPPORT_ENABLED                                    1
#define COMPUTE_MME_SUPPORT_ON                                         1
#define COMPUTE_MME_SUPPORT_DEFAULT                                    COMPUTE_MME_SUPPORT_ENABLED


#define COMPUTE_UAV_HAZARD_CONTROL_STRING                              "0xa25fc6"
#define COMPUTE_UAV_HAZARD_CONTROL_ID                                  0x00a25fc6
#define COMPUTE_UAV_HAZARD_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define COMPUTE_UAV_HAZARD_CONTROL_DRIVER_CONTROLLED                   0
#define COMPUTE_UAV_HAZARD_CONTROL_FORCE_WFI                           1
#define COMPUTE_UAV_HAZARD_CONTROL_FORCE_SEMAPHORE                     2
#define COMPUTE_UAV_HAZARD_CONTROL_IGNORE_HAZARD                       4
#define COMPUTE_UAV_HAZARD_CONTROL_MODE_CONTROL_MASK                   0xFF
#define COMPUTE_UAV_HAZARD_CONTROL_DISABLE_GP10x_HYSTERESIS            0x100
#define COMPUTE_UAV_HAZARD_CONTROL_FORCE_FE_METHOD_SEMAPHORE           0x200
#define COMPUTE_UAV_HAZARD_CONTROL_DEFAULT                             COMPUTE_UAV_HAZARD_CONTROL_DRIVER_CONTROLLED


#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_STRING               "211021"
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_ID                   0x00211021
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_OVERINSTALL          0 // OVERRIDE
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_DISABLED             0x0
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_OFF                  0x0
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_0                    0x0
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_FALSE                0x0
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_ENABLED              0x1
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_ON                   0x1
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_1                    0x1
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_TRUE                 0x1
#define CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_DEFAULT              CONDITIONAL_COPY_QUEUE_PROMOTION_MSHYBRID_ENABLED


#define CONVERT_TO_LDG_ENABLES_STRING                                  "0xcbe005"
#define CONVERT_TO_LDG_ENABLES_ID                                      0x00cbe005
#define CONVERT_TO_LDG_ENABLES_OVERINSTALL                             0 // OVERRIDE
#define CONVERT_TO_LDG_ENABLES_NONE                                    0x00
#define CONVERT_TO_LDG_ENABLES_UNUSED                                  0x01
#define CONVERT_TO_LDG_ENABLES_OCG_RANGE_HEADER                        0x02
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD                               0x04
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER                        0x18
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER11                      0x08
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER12                      0x10
#define CONVERT_TO_LDG_ENABLES_REDUCED_TEXHEADER11                     0x40
#define CONVERT_TO_LDG_ENABLES_REDUCED_TEXHEADER12                     0x80
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_DISABLE_CONST_INVALIDATION    0x300
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_DISABLE_CONST_INVALIDATION11  0x100
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_DISABLE_CONST_INVALIDATION12  0x200
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER_DISABLE_CONST_INVALIDATION 0xc00
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER_DISABLE_CONST_INVALIDATION11 0x400
#define CONVERT_TO_LDG_ENABLES_ULDC_LOAD_HEADER_DISABLE_CONST_INVALIDATION12 0x800
#define CONVERT_TO_LDG_ENABLES_DEFAULT                                 CONVERT_TO_LDG_ENABLES_NONE


#define CONVERT_TO_LDG_FLAGS_STRING                                    "0xcbe000"
#define CONVERT_TO_LDG_FLAGS_ID                                        0x00cbe000
#define CONVERT_TO_LDG_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define CONVERT_TO_LDG_FLAGS_NONE                                      0x00
#define CONVERT_TO_LDG_FLAGS_NORANGECHECK                              0x01
#define CONVERT_TO_LDG_FLAGS_DISABLESRV                                0x02
#define CONVERT_TO_LDG_FLAGS_DISABLEUAV                                0x04
#define CONVERT_TO_LDG_FLAGS_FORCERANGECHECK                           0x08
#define CONVERT_TO_LDG_FLAGS_CROSSRESDISABLE                           0x10
#define CONVERT_TO_LDG_FLAGS_DEFAULT                                   CONVERT_TO_LDG_FLAGS_NONE


#define CONVERT_TO_LDG_HASH_STRING                                     "0xcbe004"
#define CONVERT_TO_LDG_HASH_ID                                         0x00cbe004
#define CONVERT_TO_LDG_HASH_OVERINSTALL                                0 // OVERRIDE
#define CONVERT_TO_LDG_HASH_DEFAULT                                    0x0


#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_STRING                          "0xcbe007"
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_ID                              0x00cbe007
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_OVERINSTALL                     0 // OVERRIDE
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_ONLY_REQUIRED                   0x00
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_FORCE_ON                        0x01
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_FORCE_OFF                       0x02
#define CONVERT_TO_LDG_LDC_BOUNDS_MODE_DEFAULT                         CONVERT_TO_LDG_LDC_BOUNDS_MODE_ONLY_REQUIRED


#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_STRING                     "0xcbe006"
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_ID                         0x00cbe006
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_OVERINSTALL                0 // OVERRIDE
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_DISABLED                   0x00
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_DIVERGENT_ONLY             0x01
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_ALL_DYNAMIC_INDEXED        0x02
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_ALL                        0x03
#define CONVERT_TO_LDG_LDC_TRANSLATION_MODE_DEFAULT                    CONVERT_TO_LDG_LDC_TRANSLATION_MODE_DISABLED


#define CONVERT_TO_LDG_LDC_USE_ULDC_STRING                             "0xcbe008"
#define CONVERT_TO_LDG_LDC_USE_ULDC_ID                                 0x00cbe008
#define CONVERT_TO_LDG_LDC_USE_ULDC_OVERINSTALL                        0 // OVERRIDE
#define CONVERT_TO_LDG_LDC_USE_ULDC_OFF                                0x0
#define CONVERT_TO_LDG_LDC_USE_ULDC_0                                  0x0
#define CONVERT_TO_LDG_LDC_USE_ULDC_FALSE                              0x0
#define CONVERT_TO_LDG_LDC_USE_ULDC_DISABLED                           0x0
#define CONVERT_TO_LDG_LDC_USE_ULDC_ON                                 0x1
#define CONVERT_TO_LDG_LDC_USE_ULDC_1                                  0x1
#define CONVERT_TO_LDG_LDC_USE_ULDC_TRUE                               0x1
#define CONVERT_TO_LDG_LDC_USE_ULDC_ENABLED                            0x1
#define CONVERT_TO_LDG_LDC_USE_ULDC_DEFAULT                            CONVERT_TO_LDG_LDC_USE_ULDC_OFF


#define CONVERT_TO_LDG_SB_TO_LDC_SRV_STRING                            "0xcbe009"
#define CONVERT_TO_LDG_SB_TO_LDC_SRV_ID                                0x00cbe009
#define CONVERT_TO_LDG_SB_TO_LDC_SRV_OVERINSTALL                       0 // OVERRIDE
#define CONVERT_TO_LDG_SB_TO_LDC_SRV_DEFAULT                           ""


#define CONVERT_TO_LDG_SB_TO_LDC_UAV_STRING                            "0xcbe00a"
#define CONVERT_TO_LDG_SB_TO_LDC_UAV_ID                                0x00cbe00a
#define CONVERT_TO_LDG_SB_TO_LDC_UAV_OVERINSTALL                       0 // OVERRIDE
#define CONVERT_TO_LDG_SB_TO_LDC_UAV_DEFAULT                           ""


#define CONVERT_TO_LDG_STAGES_STRING                                   "0xcbe002"
#define CONVERT_TO_LDG_STAGES_ID                                       0x00cbe002
#define CONVERT_TO_LDG_STAGES_OVERINSTALL                              0 // OVERRIDE
#define CONVERT_TO_LDG_STAGES_NONE                                     0x00
#define CONVERT_TO_LDG_STAGES_VERTEX_SHADER                            0x01
#define CONVERT_TO_LDG_STAGES_HULL_SHADER                              0x02
#define CONVERT_TO_LDG_STAGES_DOMAIN_SHADER                            0x04
#define CONVERT_TO_LDG_STAGES_GEOMETRY_SHADER                          0x08
#define CONVERT_TO_LDG_STAGES_PIXEL_SHADER                             0x10
#define CONVERT_TO_LDG_STAGES_COMPUTE_SHADER                           0x20
#define CONVERT_TO_LDG_STAGES_ALL                                      0x3f
#define CONVERT_TO_LDG_STAGES_DEFAULT                                  CONVERT_TO_LDG_STAGES_NONE


#define CONVERT_TO_LDG_STG_CONTROL_STRING                              "0xcbe00b"
#define CONVERT_TO_LDG_STG_CONTROL_ID                                  0x00cbe00b
#define CONVERT_TO_LDG_STG_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define CONVERT_TO_LDG_STG_CONTROL_NONE                                0x00
#define CONVERT_TO_LDG_STG_CONTROL_ENABLE_STG_RAW                      0x01
#define CONVERT_TO_LDG_STG_CONTROL_ENABLE_STG_STRUCTURED               0x02
#define CONVERT_TO_LDG_STG_CONTROL_STG_ALL                             0x03
#define CONVERT_TO_LDG_STG_CONTROL_DEFAULT                             CONVERT_TO_LDG_STG_CONTROL_NONE


#define CONVERT_TO_LDG_TYPES_STRING                                    "0xcbe001"
#define CONVERT_TO_LDG_TYPES_ID                                        0x00cbe001
#define CONVERT_TO_LDG_TYPES_OVERINSTALL                               0 // OVERRIDE
#define CONVERT_TO_LDG_TYPES_NONE                                      0x0
#define CONVERT_TO_LDG_TYPES_UNUSED1                                   0x1
#define CONVERT_TO_LDG_TYPES_UNUSED2                                   0x2
#define CONVERT_TO_LDG_TYPES_STRUCTURED_LOAD                           0x4
#define CONVERT_TO_LDG_TYPES_RAW_LOAD                                  0x8
#define CONVERT_TO_LDG_TYPES_ALL                                       0xc
#define CONVERT_TO_LDG_TYPES_DEFAULT                                   CONVERT_TO_LDG_TYPES_NONE


#define COPY_ENGINE_STRING                                             "05a6872b"
#define COPY_ENGINE_ID                                                 0x009cfec8
#define COPY_ENGINE_OVERINSTALL                                        0 // OVERRIDE
#define COPY_ENGINE_ENABLE_CE1_USAGE                                   0x00000200
#define COPY_ENGINE_ENABLE_EXTRA_CONTEXT                               0x00000400
#define COPY_ENGINE_ENABLE_CE0_USAGE                                   0x00000800
#define COPY_ENGINE_DEFAULT                                            0x00000200


#define COPY_ENGINE9_STRING                                            "05a68729"
#define COPY_ENGINE9_ID                                                0x009c9ec8
#define COPY_ENGINE9_OVERINSTALL                                       0 // OVERRIDE
#define COPY_ENGINE9_OFF                                               0x00000000
#define COPY_ENGINE9_ON                                                0x00000001
#define COPY_ENGINE9_FORCE_CE_BLIT                                     0x00000002
#define COPY_ENGINE9_FORCE_BASIC_MODEL                                 0x00000004
#define COPY_ENGINE9_IGNORE_MIN_CE_TRANSFER_SIZE                       0x00000008
#define COPY_ENGINE9_ENABLE_CE1_USAGE                                  0x00000200
#define COPY_ENGINE9_MASK                                              0x00000f0f
#define COPY_ENGINE9_DEFAULT                                           0x00000201


#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_STRING                  "8df511"
#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_ID                      0x008df511
#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_OVERINSTALL             0 // OVERRIDE
#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_OFF                     0x00000000
#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_HOST                    0x00000001
#define CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_DEFAULT                 CPU_VISIBLE_QMD_SEMAPHORE_BUFFER_FLAGS_HOST


#define D3D10SATENABLED_STRING                                         "89456221"
#define D3D10SATENABLED_ID                                             0x00e0581d
#define D3D10SATENABLED_OVERINSTALL                                    0 // OVERRIDE
#define D3D10SATENABLED_OFF                                            0x22244556
#define D3D10SATENABLED_DISABLED                                       0x22244556
#define D3D10SATENABLED_ON                                             0x33355667
#define D3D10SATENABLED_ENABLED                                        0x33355667
#define D3D10SATENABLED_DEFAULT                                        D3D10SATENABLED_ON


#define D3D10_AAFEATUREBITS_STRING                                     "30346756"
#define D3D10_AAFEATUREBITS_ID                                         0x00e32f8a
#define D3D10_AAFEATUREBITS_OVERINSTALL                                0 // OVERRIDE
#define D3D10_AAFEATUREBITS_DEFAULT                                    0x00000000
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R8G8B8A8_SURFACES_OF_PRIMARY_SIZE 0x00000001
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R16G16B16A16F_SURFACES_OF_PRIMARY_SIZE 0x00000002
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R16G16B16A16_SURFACES_OF_PRIMARY_SIZE 0x00000004
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R32G32B32A32F_SURFACES_OF_PRIMARY_SIZE 0x00000008
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_Z_BUFFERS_OF_PRIMARY_SIZE      0x00000010
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R11G11B10_SURFACES_OF_PRIMARY_SIZE 0x00000020
#define D3D10_AAFEATUREBITS_FORCE_AA_ON_R24X8_SURFACES_OF_PRIMARY_SIZE 0x00000040
#define D3D10_AAFEATUREBITS_FORCE_MULTISAMPLING_ON                     0x00000100
#define D3D10_AAFEATUREBITS_NO_AA_ON_FLIP_CHAIN                        0x00000200
#define D3D10_AAFEATUREBITS_FORCE_LINEAR_MIN_FILTERING                 0x00000400
#define D3D10_AAFEATUREBITS_FORCE_R32F_DEMOTED_TO_R16                  0x00100000
#define D3D10_AAFEATUREBITS_USE_CPAA_SHIM                              0x80000000
#define D3D10_AAFEATUREBITS_MASK                                       0x8010077f
#define D3D10_AAFEATUREBITS_DEFAULT                                    0x00000000


#define D3D10_AODEBUGBITS_STRING                                       "57857895"
#define D3D10_AODEBUGBITS_ID                                           0x0003b6b2
#define D3D10_AODEBUGBITS_OVERINSTALL                                  0 // OVERRIDE
#define D3D10_AODEBUGBITS_DEFAULT                                      0x01000000
#define D3D10_AODEBUGBITS_DISABLE_BLENDING                             0x00000001
#define D3D10_AODEBUGBITS_DISABLE_BLUR                                 0x00000002
#define D3D10_AODEBUGBITS_RELOAD_PARAMS                                0x00000002
#define D3D10_AODEBUGBITS_DISPLAY_LINEAR_Z                             0x00000004
#define D3D10_AODEBUGBITS_DISPLAY_AO_ONLY                              0x00000008
#define D3D10_AODEBUGBITS_AO_DEMO_MODE                                 0x000000F0
#define D3D10_AODEBUGBITS_USE_NULL_GPU_RENDERING                       0x00000100
#define D3D10_AODEBUGBITS_DISABLE_AO_COMPUTATION                       0x00000200
#define D3D10_AODEBUGBITS_DISPLAY_DEBUG_VIEWPORTS                      0x00000400
#define D3D10_AODEBUGBITS_FORCE_AO_ONOFF_EVERY_10_FRAMES               0x00001000
#define D3D10_AODEBUGBITS_FORCE_AO_ONOFF_EVERY_100_FRAMES              0x00002000
#define D3D10_AODEBUGBITS_DISPLAY_DEBUG0                               0x00004000
#define D3D10_AODEBUGBITS_DISPLAY_DEBUG1                               0x00008000
#define D3D10_AODEBUGBITS_ENABLE_LOG_STATS_AT_PRESENT                  0x00010000
#define D3D10_AODEBUGBITS_ENABLE_LOG_ILSTATE                           0x00020000
#define D3D10_AODEBUGBITS_ENABLE_LOG_AUTOCALIBRATION                   0x00040000
#define D3D10_AODEBUGBITS_ENABLE_LOG_RENDERSTATES                      0x00080000
#define D3D10_AODEBUGBITS_ENABLE_LOG_FILE                              0x00100000
#define D3D10_AODEBUGBITS_FORCE_HBAO_PLUS                              0x01000000
#define D3D10_AODEBUGBITS_FORCE_HBAO_PLUS_INDICATOR                    0x02000000
#define D3D10_AODEBUGBITS_OVERRIDE_BIT                                 0x80000000
#define D3D10_AODEBUGBITS_MASK                                         0x831FF7FF


#define D3D10_AOINSERTIONLOGICBITS_STRING                              "57857893"
#define D3D10_AOINSERTIONLOGICBITS_ID                                  0x002073d9
#define D3D10_AOINSERTIONLOGICBITS_OVERINSTALL                         0 // OVERRIDE
#define D3D10_AOINSERTIONLOGICBITS_DEFAULT                             0x00000018
#define D3D10_AOINSERTIONLOGICBITS_APP_HAS_Z_PREPASS                   0x00000001
#define D3D10_AOINSERTIONLOGICBITS_CHECK_IF_VIEWPORT_WIDTH_MATCHES_PRIMARY 0x00000002
#define D3D10_AOINSERTIONLOGICBITS_CHECK_IF_VIEWPORT_HEIGHT_MATCHES_PRIMARY 0x00000004
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_NUMBER_OF_RT_IS_ONE    0x00000008
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_STENCIL_IS_DISABLED    0x00000010
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_CULL_IS_DISABLED       0x00000020
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_DEPTHFUNC_IS_NOT_COMPARISON_EQUAL 0x00000040
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_WHEN_RT_IS_USED_AS_SRV    0x00000080
#define D3D10_AOINSERTIONLOGICBITS_IGNORE_DRAWCALLS_WITH_FOUR_OR_LESS_VERTICES 0x00000100
#define D3D10_AOINSERTIONLOGICBITS_IGNORE_ALPHA_BLENDMODES             0x00000200
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_WHEN_DS_IS_CLEARED        0x00000400
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_DEPTH_IS_DISABLED      0x00000800
#define D3D10_AOINSERTIONLOGICBITS_USE_DS_WITH_MOST_OPAQUE_DRAWS       0x00001000
#define D3D10_AOINSERTIONLOGICBITS_USE_RT_WITH_MOST_OPAQUE_DRAWS       0x00002000
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_WHEN_RT_IS_USED_IN_RESOLVE_SUBRESOURCE 0x00004000
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_CULL_MODE_IS_FRONT     0x00008000
#define D3D10_AOINSERTIONLOGICBITS_SHADING_OPAQUE_IF_CULL_MODE_IS_BACK 0x00010000
#define D3D10_AOINSERTIONLOGICBITS_IGNORE_WRITING_COLOR_FOR_RENDER_AO  0x00020000
#define D3D10_AOINSERTIONLOGICBITS_RENDER_AO_IF_SRCBLEND_APLHA_DSTBLEND_ONE 0x00040000
#define D3D10_AOINSERTIONLOGICBITS_CALIBRATE_FROM_DYNAMIC_DEFAULT_CBS  0x00800000
#define D3D10_AOINSERTIONLOGICBITS_VIEWPROJECTION_TYPES                0x07000000
#define D3D10_AOINSERTIONLOGICBITS_VIEWPROJECTION_CHECK_ASPECT_RATIO   0x08000000
#define D3D10_AOINSERTIONLOGICBITS_VIEWPROJECTION_REVERSES_NEAR_FAR    0x10000000
#define D3D10_AOINSERTIONLOGICBITS_USE_CPAO_SHIM                       0x80000000
#define D3D10_AOINSERTIONLOGICBITS_MASK                                0x8f87ffff


#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_STRING              "31482009"
#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_ID                  0x001208cc
#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_OVERINSTALL         0 // OVERRIDE
#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_OFF                 0x00000000
#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_ON                  0x00000001
#define D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_DEFAULT             D3D11_DISABLE_FREE_THREADED_CREATE_DESTROY_OFF


#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_STRING                 "0309706"
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_ID                     0x003850fd
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_OVERINSTALL            0 // OVERRIDE
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_OFF                    0x0
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_DISABLED               0x0
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_ON                     0x1
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_ENABLED                0x1
#define D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_DEFAULT                D3D11_FORCE_INVALIDATE_ON_RESOURCE_BIND_OFF


#define D3D11_TILED_RESOURCES_STRING                                   "31482010"
#define D3D11_TILED_RESOURCES_ID                                       0x001208cd
#define D3D11_TILED_RESOURCES_OVERINSTALL                              0 // OVERRIDE
#define D3D11_TILED_RESOURCES_DISABLE                                  0x00000001
#define D3D11_TILED_RESOURCES_DISABLE_TILE_POOL_MULTIALLOC             0x00000002
#define D3D11_TILED_RESOURCES_UNUSED                                   0x00000004
#define D3D11_TILED_RESOURCES_FORCE_RT_DS_RESOURCES_TILED              0x00000008
#define D3D11_TILED_RESOURCES_DEFAULT                                  0


#define D3D12_AMPERE_SUBCHSW_OVERRIDE_STRING                           "524621"
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_ID                               0x00524621
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_OVERINSTALL                      0 // OVERRIDE
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_NO_OVERRIDE                      0
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_FE0_CE_TO_COMPUTE                0x00000001
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_FE0_3D_TO_COMPUTE                0x00000002
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_FE0_CE_TO_3D                     0x00000004
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_FE0_COMPUTE_TO_3D                0x00000008
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_FE1_CE_TO_COMPUTE                0x00000010
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_SUBCHSW_TYPE_MASK                0x0000001F
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_SHADER_CACHES_INSTR  0x01000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_SHADER_CACHES_DATA   0x02000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_SHADER_CACHES_CONST  0x04000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_SHADER_CACHES_LOCKS  0x08000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_SAMPLER_CACHE        0x10000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_TEXTURE_HEADER_CACHE 0x20000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_EXCLUDE_INV_MASK                 0x3F000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_INCLUDE_INV_RESTER_CACHE         0x40000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_INCLUDE_INV_ROP_MINI_CACHE       0x80000000
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_COMPUTE_OVERRIDE                 0x0000001b
#define D3D12_AMPERE_SUBCHSW_OVERRIDE_DEFAULT                          D3D12_AMPERE_SUBCHSW_OVERRIDE_NO_OVERRIDE


#define D3D12_BUNDLE_BAKE_THRESHOLDS_STRING                            "34598214"
#define D3D12_BUNDLE_BAKE_THRESHOLDS_ID                                0x006c2a5e
#define D3D12_BUNDLE_BAKE_THRESHOLDS_OVERINSTALL                       0 // OVERRIDE
#define D3D12_BUNDLE_BAKE_THRESHOLDS_DEFAULT                           0x00000004


#define D3D12_COMMAND_LIST_PROMOTION_STRING                            "0x2ad201"
#define D3D12_COMMAND_LIST_PROMOTION_ID                                0x00ead031
#define D3D12_COMMAND_LIST_PROMOTION_OVERINSTALL                       0 // OVERRIDE
#define D3D12_COMMAND_LIST_PROMOTION_OFF                               0
#define D3D12_COMMAND_LIST_PROMOTION_DISABLED                          0
#define D3D12_COMMAND_LIST_PROMOTION_ON                                1
#define D3D12_COMMAND_LIST_PROMOTION_ENABLED                           1
#define D3D12_COMMAND_LIST_PROMOTION_DEFAULT                           D3D12_COMMAND_LIST_PROMOTION_ON


#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_STRING                      "0xfaf030"
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ID                          0x00faf030
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_OVERINSTALL                 0 // OVERRIDE
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_WITH_DDI_SHIMS       0x01
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_FOR_MULTIPLE_DIRECT_QUEUES_ONLY 0x02
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_COPY_PROMOTION       0x04
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_BARRIER_PROMOTION    0x08
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_DXR_PROMOTION        0x10
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_ENABLE_COMPUTE_PROMOTION    0x20
#define D3D12_COMMAND_LIST_PROMOTION_FLAGS_DEFAULT                     0x00000018


#define D3D12_DESCHEAP_READ_AT_CL_RECORD_STRING                        "20151820"
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_ID                            0x00de5c4d
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_OVERINSTALL                   0 // OVERRIDE
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_OFF                           0x00000000
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_DISABLED                      0x00000000
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_ON                            0x00000001
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_ENABLED                       0x00000001
#define D3D12_DESCHEAP_READ_AT_CL_RECORD_DEFAULT                       D3D12_DESCHEAP_READ_AT_CL_RECORD_OFF


#define D3D12_DESCRIPTOR_PROMOTION_STRING                              "32195415"
#define D3D12_DESCRIPTOR_PROMOTION_ID                                  0x00132a94
#define D3D12_DESCRIPTOR_PROMOTION_OVERINSTALL                         0 // OVERRIDE
#define D3D12_DESCRIPTOR_PROMOTION_OFF                                 0x00000000
#define D3D12_DESCRIPTOR_PROMOTION_0                                   0x00000000
#define D3D12_DESCRIPTOR_PROMOTION_FALSE                               0x00000000
#define D3D12_DESCRIPTOR_PROMOTION_DISABLED                            0x00000000
#define D3D12_DESCRIPTOR_PROMOTION_CBV_GRAPHICS                        0x00000001
#define D3D12_DESCRIPTOR_PROMOTION_CBV_COMPUTE                         0x00000002
#define D3D12_DESCRIPTOR_PROMOTION_PROMOTE_UNINITIALIZED               0x00000004
#define D3D12_DESCRIPTOR_PROMOTION_DEFAULT                             0x0


#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_STRING                        "34185314"
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_ID                            0x00149b83
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_OVERINSTALL                   0 // OVERRIDE
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_CTAS_SHIFT_MASK               0x0000000f
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_CTAS_SHIFT_SHIFT              0
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_THREADS_PER_CTA_MASK          0x000003f0
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_THREADS_PER_CTA_SHIFT         4
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_USE_BAR_FOR_PATCH_ENTRIES     0x400
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_USE_VIDMEM_GPFIFO_FOR_PATCH_DST 0x800
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_USE_DESCHEAP_GPFIFO_DIRECT_PATCH 0x1000
#define D3D12_DESCRIPTOR_PROMOTION_FLAGS_DEFAULT                       0x200


#define D3D12_ENHANCED_BARRIER_SUPPORT_STRING                          "0xba41e3"
#define D3D12_ENHANCED_BARRIER_SUPPORT_ID                              0x00ba41e3
#define D3D12_ENHANCED_BARRIER_SUPPORT_OVERINSTALL                     0 // OVERRIDE
#define D3D12_ENHANCED_BARRIER_SUPPORT_OFF                             0
#define D3D12_ENHANCED_BARRIER_SUPPORT_DISABLED                        0
#define D3D12_ENHANCED_BARRIER_SUPPORT_ON                              1
#define D3D12_ENHANCED_BARRIER_SUPPORT_ENABLED                         1
#define D3D12_ENHANCED_BARRIER_SUPPORT_DEFAULT                         D3D12_ENHANCED_BARRIER_SUPPORT_ON


#define D3D12_EXECUTE_INDIRECT_USE_MME_STRING                          "20156817"
#define D3D12_EXECUTE_INDIRECT_USE_MME_ID                              0x00a7432b
#define D3D12_EXECUTE_INDIRECT_USE_MME_OVERINSTALL                     0 // OVERRIDE
#define D3D12_EXECUTE_INDIRECT_USE_MME_OFF                             0x00000000
#define D3D12_EXECUTE_INDIRECT_USE_MME_DISABLED                        0x00000000
#define D3D12_EXECUTE_INDIRECT_USE_MME_ON                              0x00000001
#define D3D12_EXECUTE_INDIRECT_USE_MME_ENABLED                         0x00000001
#define D3D12_EXECUTE_INDIRECT_USE_MME_DEFAULT                         D3D12_EXECUTE_INDIRECT_USE_MME_ON


#define D3D12_FORCE_EVICT2_STRING                                      "20151827"
#define D3D12_FORCE_EVICT2_ID                                          0x00b8a63e
#define D3D12_FORCE_EVICT2_OVERINSTALL                                 0 // OVERRIDE
#define D3D12_FORCE_EVICT2_OFF                                         0x00000000
#define D3D12_FORCE_EVICT2_DISABLED                                    0x00000000
#define D3D12_FORCE_EVICT2_ON                                          0x00000001
#define D3D12_FORCE_EVICT2_ENABLED                                     0x00000001
#define D3D12_FORCE_EVICT2_DEFAULT                                     D3D12_FORCE_EVICT2_OFF


#define D3D12_FULL_DESCRIPTOR_TABLE_SET_STRING                         "20149790"
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_ID                             0x00267312
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_OVERINSTALL                    0 // OVERRIDE
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_OFF                            0x00000000
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_DISABLED                       0x00000000
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_ON                             0x00000001
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_ENABLED                        0x00000001
#define D3D12_FULL_DESCRIPTOR_TABLE_SET_DEFAULT                        D3D12_FULL_DESCRIPTOR_TABLE_SET_ON


#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_STRING                   "2386A8BE"
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_ID                       0x00b55fd2
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_OVERINSTALL              0 // OVERRIDE
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_DISABLE                  0x00000000
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_ENABLE_INTER_COMMANDLIST_QMD_SYNC 0x00000001
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_ENABLE_COMPUTE_QUEUE_TIMESTAMP_QUERIES 0x00000002
#define D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_DEFAULT                  D3D12_GPU_COMPUTE_SYNC_KERNEL_CONTROL_DISABLE


#define D3D12_REDIST_MIN_WDDM_VERSION_STRING                           "29567355"
#define D3D12_REDIST_MIN_WDDM_VERSION_ID                               0x0003268c
#define D3D12_REDIST_MIN_WDDM_VERSION_OVERINSTALL                      0 // OVERRIDE
#define D3D12_REDIST_MIN_WDDM_VERSION_DEFAULT                          0x00002600


#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_STRING    "0xba41e4"
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ID        0x00ba41e4
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_OVERINSTALL 0 // OVERRIDE
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_TRANSITION 0x01
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_UAV 0x02
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_ALIASING 0x04
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_RANGED 0x08
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_GENERAL 0x10
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_ENABLE_COMPUTE_ONLY 0x20
#define D3D12_RESOURCE_BARRIER_TO_ENHANCED_BARRIER_PROMOTION_DEFAULT   0x0000003f


#define D3D12_RESOURCE_BINDING_CONTROL_STRING                          "20140317"
#define D3D12_RESOURCE_BINDING_CONTROL_ID                              0x00667432
#define D3D12_RESOURCE_BINDING_CONTROL_OVERINSTALL                     0 // OVERRIDE
#define D3D12_RESOURCE_BINDING_CONTROL_DEFAULT                         0x0000000
#define D3D12_RESOURCE_BINDING_CONTROL_TIER_1                          0x0000001
#define D3D12_RESOURCE_BINDING_CONTROL_TIER_2                          0x0000002
#define D3D12_RESOURCE_BINDING_CONTROL_TIER_3                          0x0000003


#define D3D12_ROV_IMPL_STRING                                          "20144709"
#define D3D12_ROV_IMPL_ID                                              0x00776870
#define D3D12_ROV_IMPL_OVERINSTALL                                     0 // OVERRIDE
#define D3D12_ROV_IMPL_USE_ROV_OLD                                     0x00000000
#define D3D12_ROV_IMPL_OFF                                             0x00000000
#define D3D12_ROV_IMPL_DISABLED                                        0x00000000
#define D3D12_ROV_IMPL_USE_ROV_NEW                                     0x00000001
#define D3D12_ROV_IMPL_ON                                              0x00000001
#define D3D12_ROV_IMPL_ENABLED                                         0x00000001
#define D3D12_ROV_IMPL_DEFAULT                                         D3D12_ROV_IMPL_USE_ROV_NEW


#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_STRING            "20151821"
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_ID                0x00de5c4e
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_OVERINSTALL       0 // OVERRIDE
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_OFF               0x00000000
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_DISABLED          0x00000000
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_ON                0x00000001
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_ENABLED           0x00000001
#define D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_DEFAULT           D3D12_TILED_RESOURCES_BATCH_UPDATE_VA_FENCES_OFF


#define D3D12_UMD_MANAGED_RESIDENCY_STRING                             "20149789"
#define D3D12_UMD_MANAGED_RESIDENCY_ID                                 0x00776830
#define D3D12_UMD_MANAGED_RESIDENCY_OVERINSTALL                        0 // OVERRIDE
#define D3D12_UMD_MANAGED_RESIDENCY_ENABLE_ON_ALL_RESOURCES            0x00000000
#define D3D12_UMD_MANAGED_RESIDENCY_EXCLUDE_RUNTIME_RESOURCES          0x00000002
#define D3D12_UMD_MANAGED_RESIDENCY_EXCLUDE_DESCRIPTORS                0x00000004
#define D3D12_UMD_MANAGED_RESIDENCY_DEFAULT                            0x00000006


#define D3D12_VIEW_INSTANCING_STRING                                   "0xacbdfe"
#define D3D12_VIEW_INSTANCING_ID                                       0x00acbdfe
#define D3D12_VIEW_INSTANCING_OVERINSTALL                              0 // OVERRIDE
#define D3D12_VIEW_INSTANCING_MAX_TIER_0                               0x0
#define D3D12_VIEW_INSTANCING_MAX_TIER_1                               0x1
#define D3D12_VIEW_INSTANCING_MAX_TIER_2                               0x2
#define D3D12_VIEW_INSTANCING_MAX_TIER_3                               0x3
#define D3D12_VIEW_INSTANCING_DEFAULT                                  0x3


#define D3D12_VPRS_FLAGS_STRING                                        "554555"
#define D3D12_VPRS_FLAGS_ID                                            0x00554555
#define D3D12_VPRS_FLAGS_OVERINSTALL                                   0 // OVERRIDE
#define D3D12_VPRS_FLAGS_VPRS_FLAGS_NONE                               0x00000000
#define D3D12_VPRS_FLAGS_AMPERE_PLUS_FORCE_LEGACY                      0x00000001
#define D3D12_VPRS_FLAGS_FORCE_VPRS_NOT_SUPPORTED                      0x00000002
#define D3D12_VPRS_FLAGS_DEFAULT                                       D3D12_VPRS_FLAGS_VPRS_FLAGS_NONE


#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_STRING                         "22141627"
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_ID                             0x00a34f23
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_OVERINSTALL                    0 // OVERRIDE
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_DISABLE_ALL                    0x00000000
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_ALLOW_RTVDSV                   0x00000001
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_DISABLE_MAXWELL                0x00020000
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_DISABLE_PASCAL                 0x00040000
#define D3D12_WDDM_2_HEAP_VA_MANAGEMENT_DEFAULT                        D3D12_WDDM_2_HEAP_VA_MANAGEMENT_DISABLE_ALL


#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_STRING                   "10798549"
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_ID                       0x00bcff1d
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_OVERINSTALL              0 // OVERRIDE
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_OFF                      0
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_DISABLED                 0
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_ON                       1
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_ENABLED                  1
#define D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_DEFAULT                  D3D1X_ENABLE_GPUVIEWTRACER_ON_RELEASE_OFF


#define D3D1X_OCGCONTROL_DIRECT_NVIR_STRING                            "78452826"
#define D3D1X_OCGCONTROL_DIRECT_NVIR_ID                                0x00e107d4
#define D3D1X_OCGCONTROL_DIRECT_NVIR_OVERINSTALL                       0 // OVERRIDE
#define D3D1X_OCGCONTROL_DIRECT_NVIR_DEFAULT                           0x0
#define D3D1X_OCGCONTROL_DIRECT_NVIR_FORCE_ENABLE                      0x1
#define D3D1X_OCGCONTROL_DIRECT_NVIR_FORCE_DISABLE                     0x2


#define D3D9_AO2INSERTIONLOGICBITS_STRING                              "26579344"
#define D3D9_AO2INSERTIONLOGICBITS_ID                                  0x000ed03d
#define D3D9_AO2INSERTIONLOGICBITS_OVERINSTALL                         0 // OVERRIDE
#define D3D9_AO2INSERTIONLOGICBITS_DEFAULT                             0x00000000
#define D3D9_AO2INSERTIONLOGICBITS_APP_HAS_Z_PREPASS                   0x00000001
#define D3D9_AO2INSERTIONLOGICBITS_CHECK_IF_VIEWPORT_WIDTH_MATCHES_PRIMARY 0x00000002
#define D3D9_AO2INSERTIONLOGICBITS_CHECK_IF_VIEWPORT_HEIGHT_MATCHES_PRIMARY 0x00000004
#define D3D9_AO2INSERTIONLOGICBITS_IGNORE_DRAW_CALLS_WITH_TWO_OR_LESS_PRIMITIVES 0x00000008
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_TYPES                0x00000030
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_0                    0x00000000
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_1                    0x00000010
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_2                    0x00000020
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_CHECK_ASPECT_RATIO   0x00000040
#define D3D9_AO2INSERTIONLOGICBITS_VIEWPROJECTION_TRANSPOSE            0x00000080
#define D3D9_AO2INSERTIONLOGICBITS_CALIBRATE_ONLY_IF_MINZ_IS_ZERO      0x00000100
#define D3D9_AO2INSERTIONLOGICBITS_CALIBRATE_ONLY_IF_MAXZ_IS_ONE       0x00000200
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_MATCH_STATES_BEFORE_STRETCHRECT 0x00000400
#define D3D9_AO2INSERTIONLOGICBITS_LINEARIZE_Z_BEFORE_ZCLEAR           0x00000800
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_AT_PRESENT                0x00001000
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_BEFORE_STRETCHRECT        0x00002000
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_BEFORE_ZCLEAR             0x00004000
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_MATCH_STATES_ON_DRAW      0x00008000
#define D3D9_AO2INSERTIONLOGICBITS_INSERT_AO_MATCH_STATES_AFTER_ZCLEAR 0x00010000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_CULL_ENABLED                0x00020000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_DEPTHFUNC_EQUAL             0x00040000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_DEPTHFUNC_LESSEQUAL         0x00080000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_STENCIL_ENABLED             0x00100000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_ALPHATEST_ENABLED           0x00200000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_ALPHABLEND_ENABLED          0x00400000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_SRCBLEND_SRCALPHA           0x00800000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_DSTBLEND_ONE                0x01000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_MRT_ENABLED                 0x02000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_DEPTHTEST_ENABLED           0x04000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_COLORWRITE_ENABLED          0x08000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_COLORFORMAT_ENABLED         0x10000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_COLORWRITE3_ENABLED         0x20000000
#define D3D9_AO2INSERTIONLOGICBITS_PATTERN_SRGBWRITE_ENABLED           0x40000000
#define D3D9_AO2INSERTIONLOGICBITS_MASK                                0x7fffffff


#define D3D9_AO2INSERTIONPATTERNMATCHMASK_STRING                       "81294563"
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_ID                           0x00078fd4
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_OVERINSTALL                  0 // OVERRIDE
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_DEFAULT                      0x00000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_CULL_ENABLED_MASK    0x00020000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_DEPTHFUNC_EQUAL_MASK 0x00040000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_DEPTHFUNC_LESSEQUAL_MASK 0x00080000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_STENCIL_ENABLED_MASK 0x00100000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_ALPHATEST_ENABLED_MASK 0x00200000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_ALPHABLEND_ENABLED_MASK 0x00400000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_SRCBLEND_SRCALPHA_MASK 0x00800000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_DSTBLEND_ONE_MASK    0x01000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_MRT_ENABLED_MASK     0x02000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_DEPTHTEST_ENABLED_MASK 0x04000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_COLORWRITE_ENABLED_MASK 0x08000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_COLORFORMAT_ENABLED_MASK 0x10000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_COLORWRITE3_ENABLED_MASK 0x20000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_PATTERN_SRGBWRITE_ENABLED_MASK 0x40000000
#define D3D9_AO2INSERTIONPATTERNMATCHMASK_MASK                         0x7ffe0000


#define D3D9_AO2WARBITS_STRING                                         "90994123"
#define D3D9_AO2WARBITS_ID                                             0x001269b5
#define D3D9_AO2WARBITS_OVERINSTALL                                    0 // OVERRIDE
#define D3D9_AO2WARBITS_DEFAULT                                        0x00000000
#define D3D9_AO2WARBITS_APP_FIELD                                      0x0000ffff
#define D3D9_AO2WARBITS_COLOR_FORMAT_IS_A2R10G10B10                    0x00010000
#define D3D9_AO2WARBITS_COLOR_FORMAT_IS_A16B16G16R16F                  0x00020000
#define D3D9_AO2WARBITS_ALLOW_GREATER_THAN_EQUAL_TO_PRIMARY            0X01000000


#define D3D9_AODEBUGBITS_STRING                                        "57857898"
#define D3D9_AODEBUGBITS_ID                                            0x00e9ffe8
#define D3D9_AODEBUGBITS_OVERINSTALL                                   0 // OVERRIDE
#define D3D9_AODEBUGBITS_DEFAULT                                       0x00000000
#define D3D9_AODEBUGBITS_DISABLE_BLENDING                              0x00000001
#define D3D9_AODEBUGBITS_RENDER_AGAINST_WHITE                          0x00000001
#define D3D9_AODEBUGBITS_DISABLE_BLUR                                  0x00000002
#define D3D9_AODEBUGBITS_RELOAD_PARAMS                                 0x00000002
#define D3D9_AODEBUGBITS_DISPLAY_LINEAR_Z                              0x00000004
#define D3D9_AODEBUGBITS_DISPLAY_AO_ONLY                               0x00000008
#define D3D9_AODEBUGBITS_AO_DEMO_MODE                                  0x000000F0
#define D3D9_AODEBUGBITS_USE_NULL_GPU_RENDERING                        0x00000100
#define D3D9_AODEBUGBITS_DISABLE_AO_COMPUTATION                        0x00000200
#define D3D9_AODEBUGBITS_DISPLAY_DEBUG_VIEWPORTS                       0x00000400
#define D3D9_AODEBUGBITS_FORCE_AO_ONOFF_EVERY_10_FRAMES                0x00001000
#define D3D9_AODEBUGBITS_FORCE_AO_ONOFF_EVERY_100_FRAMES               0x00002000
#define D3D9_AODEBUGBITS_DISPLAY_DEBUG0                                0x00004000
#define D3D9_AODEBUGBITS_DISPLAY_DEBUG1                                0x00008000
#define D3D9_AODEBUGBITS_ENABLE_LOG_STATS_AT_PRESENT                   0x00010000
#define D3D9_AODEBUGBITS_ENABLE_LOG_ILSTATE                            0x00020000
#define D3D9_AODEBUGBITS_ENABLE_LOG_AUTOCALIBRATION                    0x00040000
#define D3D9_AODEBUGBITS_ENABLE_LOG_RENDERSTATES                       0x00080000
#define D3D9_AODEBUGBITS_ENABLE_LOG_FILE                               0x00100000
#define D3D9_AODEBUGBITS_ENABLE_LOG_ILPARTICLE                         0x00200000
#define D3D9_AODEBUGBITS_ENABLE_LOG_RENDERSTATE_FILE                   0x00400000
#define D3D9_AODEBUGBITS_FORCE_HBAO_PLUS                               0x01000000
#define D3D9_AODEBUGBITS_FORCE_HBAO_PLUS_INDICATOR                     0x02000000
#define D3D9_AODEBUGBITS_OVERRIDE_BIT                                  0x80000000
#define D3D9_AODEBUGBITS_MASK                                          0x837FF7FF


#define D3D9_AOINSERTIONLOGICBITS_STRING                               "57857897"
#define D3D9_AOINSERTIONLOGICBITS_ID                                   0x000bd03d
#define D3D9_AOINSERTIONLOGICBITS_OVERINSTALL                          0 // OVERRIDE
#define D3D9_AOINSERTIONLOGICBITS_DEFAULT                              0x000803C2
#define D3D9_AOINSERTIONLOGICBITS_APP_HAS_Z_PREPASS                    0x00000001
#define D3D9_AOINSERTIONLOGICBITS_CHECK_IF_VIEWPORT_WIDTH_MATCHES_PRIMARY 0x00000002
#define D3D9_AOINSERTIONLOGICBITS_CHECK_IF_VIEWPORT_HEIGHT_MATCHES_PRIMARY 0x00000004
#define D3D9_AOINSERTIONLOGICBITS_IGNORE_DRAW_CALLS_WITH_TWO_OR_LESS_PRIMITIVES 0x00000008
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_BEFORE_STRETCHRECT         0x00000010
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_BEFORE_ZCLEAR              0x00000020
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_BEFORE_PARTICLES_ON_DRAW   0x00000040
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_CULL_IS_DISABLED        0x00000080
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_DEPTHFUNC_IS_NOT_COMPARISON_EQUAL 0x00000100
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_STENCIL_IS_DISABLED     0x00000200
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_ALPHA_TEST_DISABLED     0x00000400
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_SRCBLEND_IS_SRCALPHA    0x00000800
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_BEFORE_POSTPROCESSING_ON_DRAW 0x00001000
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_BEFORE_POSTPROCESSING_ON_ZCLEAR 0x00002000
#define D3D9_AOINSERTIONLOGICBITS_POSTPROCESSING_IF_NUMBER_OF_RT_IS_ONE 0x00004000
#define D3D9_AOINSERTIONLOGICBITS_POSTPROCESSING_IF_DEPTHTEST_IS_DISABLED 0x00008000
#define D3D9_AOINSERTIONLOGICBITS_POSTPROCESSING_IF_CULL_IS_ENABLED    0x00010000
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_ALPHA_TEST_ENABLED      0x00020000
#define D3D9_AOINSERTIONLOGICBITS_USE_RT_WITH_MOST_OPAQUE_DRAWS        0x00040000
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_DEPTHFUNC_IS_NOT_COMPARISON_LESSEQUAL 0x00080000
#define D3D9_AOINSERTIONLOGICBITS_CALIBRATE_ONLY_IF_MINZ_IS_ZERO       0x00100000
#define D3D9_AOINSERTIONLOGICBITS_CALIBRATE_ONLY_IF_MAXZ_IS_ONE        0x00200000
#define D3D9_AOINSERTIONLOGICBITS_COLOR_FORMAT_IS_A2R10G10B10          0x00400000
#define D3D9_AOINSERTIONLOGICBITS_PARTICLES_IF_DESTBLEND_IS_ONE        0x00800000
#define D3D9_AOINSERTIONLOGICBITS_VIEWPROJECTION_TYPES                 0x03000000
#define D3D9_AOINSERTIONLOGICBITS_VIEWPROJECTION_CHECK_ASPECT_RATIO    0x04000000
#define D3D9_AOINSERTIONLOGICBITS_VIEWPROJECTION_TRANSPOSE             0x08000000
#define D3D9_AOINSERTIONLOGICBITS_LINEARIZE_Z_BEFORE_ZCLEAR            0x10000000
#define D3D9_AOINSERTIONLOGICBITS_INSERT_AO_AT_PRESENT                 0x20000000
#define D3D9_AOINSERTIONLOGICBITS_USE_CPAO_SHIM                        0x80000000
#define D3D9_AOINSERTIONLOGICBITS_MASK                                 0xbfffffff


#define D3D9_CONTROL_BITS_STRING                                       "93767415"
#define D3D9_CONTROL_BITS_ID                                           0x0067345e
#define D3D9_CONTROL_BITS_OVERINSTALL                                  0 // OVERRIDE
#define D3D9_CONTROL_BITS_DEFAULT                                      0x00000000
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_MASK               0x0000000f
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_DEFAULT            0x00000000
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_24                 0x00000001
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_30                 0x00000003
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_40                 0x00000005
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_60                 0x00000007
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_128_120                0x00000009
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_MASK               0x000000f0
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_DEFAULT            0x00000000
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_24                 0x00000010
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_26                 0x00000020
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_30                 0x00000030
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_34                 0x00000040
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_40                 0x00000050
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_48                 0x00000060
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_60                 0x00000070
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_80                 0x00000080
#define D3D9_CONTROL_BITS_MAX_REG_FOR_BANK_SIZE_256_120                0x00000090
#define D3D9_CONTROL_BITS_DISABLE_DYNAMIC_VB_PROMOTION                 0x00002000
#define D3D9_CONTROL_BITS_DISALLOW_FORCE_VSYNC                         0x00004000
#define D3D9_CONTROL_BITS_DISALLOW_CPU_VISIBLE_SEGMENT                 0x00008000
#define D3D9_CONTROL_BITS_MASK                                         0x0000e0ff


#define D3D9_OCGCONTROL_DIRECT_NVIR_STRING                             "28549468"
#define D3D9_OCGCONTROL_DIRECT_NVIR_ID                                 0x00e107d3
#define D3D9_OCGCONTROL_DIRECT_NVIR_OVERINSTALL                        0 // OVERRIDE
#define D3D9_OCGCONTROL_DIRECT_NVIR_DEFAULT                            0x0
#define D3D9_OCGCONTROL_DIRECT_NVIR_FORCE_ENABLE                       0x1
#define D3D9_OCGCONTROL_DIRECT_NVIR_FORCE_DISABLE                      0x2


#define D3D_DBG_AFTER_DRAW_DISPATCH_STRING                             "12agdeee"
#define D3D_DBG_AFTER_DRAW_DISPATCH_ID                                 0x00321ddd
#define D3D_DBG_AFTER_DRAW_DISPATCH_OVERINSTALL                        0 // OVERRIDE
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_NONE                           0x00000000
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_WFI                            0x00000001
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_CACHE_INVALIDATE_NONWFI        0x00000002
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_CACHE_INVALIDATE_WFI           0x00000004
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_CACHE_INVALIDATE_PSB           0x00000008
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_TEX_HEADERS         0x00000010
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_SAMPLERS            0x00000020
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_SHADERS             0x00000040
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_CONSTANTS           0x00000080
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_TEX_OR_SURF_DATA    0x00000100
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_INVALIDATE_ALL_TARGETS         0x000001f0
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_ON_GRAPHICS                    0x10000000
#define D3D_DBG_AFTER_DRAW_DISPATCH_DBG_ON_COMPUTE                     0x20000000
#define D3D_DBG_AFTER_DRAW_DISPATCH_GRAPHICS_NONWFI_INVALIDATE_CACHE_FOR_ALL 0x100001f2
#define D3D_DBG_AFTER_DRAW_DISPATCH_GRAPHICS_WFI_INVALIDATE_CACHE_FOR_ALL 0x100001f4
#define D3D_DBG_AFTER_DRAW_DISPATCH_GRAPHICS_PSB_INVALIDATE_CACHE_FOR_ALL 0x100001f8
#define D3D_DBG_AFTER_DRAW_DISPATCH_COMPUTE_WFI_INVALIDATE_CACHE_FOR_ALL 0x200001f4
#define D3D_DBG_AFTER_DRAW_DISPATCH_GRAPHICS_WFI                       0x10000001
#define D3D_DBG_AFTER_DRAW_DISPATCH_COMPUTE_WFI                        0x20000001
#define D3D_DBG_AFTER_DRAW_DISPATCH_DEFAULT                            D3D_DBG_AFTER_DRAW_DISPATCH_DBG_NONE


#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_STRING                   "12fadeee"
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_ID                       0x00342ddd
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_OVERINSTALL              0 // OVERRIDE
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DBG_DEFAULT              0x00000000
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DBG_EVERY                0x00010001
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DBG_DRAW_MASK            0x0000ffff
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DBG_DISPATCH_MASK        0xffff0000
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DRAW_FRQUENCY_20         0x00000014
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DISPATCH_FRQUENCY_20     0x00140000
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DRAW_FRQUENCY_100        0x00000064
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DISPATCH_FRQUENCY_100    0x00640000
#define D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DEFAULT                  D3D_DBG_AFTER_DRAW_DISPATCH_FREQUENCY_DBG_DEFAULT


#define D3D_DBG_DUMP_AFTER_DRAW_STRING                                 "8bfe85ab"
#define D3D_DBG_DUMP_AFTER_DRAW_ID                                     0x00d831b3
#define D3D_DBG_DUMP_AFTER_DRAW_OVERINSTALL                            0 // OVERRIDE
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_NONE                              0x00000000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_PRE_DRAW                          0x00000001
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_RTV                               0x00000010
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_DSV                               0x00000020
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_STREAM                            0x00000040
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_PL_STATS                          0x00000100
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_ZPASS                             0x00000200
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_SO_STATS                          0x00000400
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_GFX_UAV                           0x00001000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_GFX_SRV                           0x00002000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_GFX_CBV                           0x00004000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_GFX_GSCB                          0x00008000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_GFX_TEXHEADERS                    0x00010000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_COMPUTE_UAV                       0x00100000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_COMPUTE_SRV                       0x00200000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_COMPUTE_CBV                       0x00400000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_COMPUTE_GSCB                      0x00800000
#define D3D_DBG_DUMP_AFTER_DRAW_DUMP_COMPUTE_TEXHEADERS                0x01000000
#define D3D_DBG_DUMP_AFTER_DRAW_IGNORE_BAKED_BUNDLES                   0x10000000
#define D3D_DBG_DUMP_AFTER_DRAW_DEFAULT                                D3D_DBG_DUMP_AFTER_DRAW_DUMP_NONE


#define D3D_DBG_MISC_AFTER_DRAW_STRING                                 "4891f370"
#define D3D_DBG_MISC_AFTER_DRAW_ID                                     0x00a22dc9
#define D3D_DBG_MISC_AFTER_DRAW_OVERINSTALL                            0 // OVERRIDE
#define D3D_DBG_MISC_AFTER_DRAW_MISC_NONE                              0x00000000
#define D3D_DBG_MISC_AFTER_DRAW_MISC_DISPATCH_FLUSH                    0x00000001
#define D3D_DBG_MISC_AFTER_DRAW_MISC_CHECK_DESCRIPTOR                  0x00000002
#define D3D_DBG_MISC_AFTER_DRAW_IGNORE_BAKED_BUNDLES                   0x10000000
#define D3D_DBG_MISC_AFTER_DRAW_DEFAULT                                D3D_DBG_MISC_AFTER_DRAW_MISC_NONE


#define D3D_DBG_VALIDATION_MISC_ACTIVITY_STRING                        "B8231455"
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_ID                            0x00b82355
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_OVERINSTALL                   0 // OVERRIDE
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_DISABLED                      0x00000000
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_OFF                           0x00000000
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_0                             0x00000000
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_FORCE_DDI_CRITICAL_SECTION    0x00000004
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_FORCE_DDI_INTERLOCKED_CHECK   0x00000008
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_INCREASE_TIME_DDI_CALLS       0x00000010
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_USE_ZERO_FOR_INIT_DESCRIPTORS 0x00000020
#define D3D_DBG_VALIDATION_MISC_ACTIVITY_DEFAULT                       D3D_DBG_VALIDATION_MISC_ACTIVITY_DISABLED


#define D3D_DC_CONTROL_STRING                                          "31482008"
#define D3D_DC_CONTROL_ID                                              0x001208cb
#define D3D_DC_CONTROL_OVERINSTALL                                     0 // OVERRIDE
#define D3D_DC_CONTROL_DISABLE_DC_D3D11                                0x00000001
#define D3D_DC_CONTROL_ENABLE_REPLAY_D3D12                             0x00000004
#define D3D_DC_CONTROL_ENABLE_REPLAY_ALL                               0x00000008
#define D3D_DC_CONTROL_ENABLE_BAKED_BUNDLES                            0x00000010
#define D3D_DC_CONTROL_DEFAULT                                         0x00000010


#define D3D_ENABLE_VALIDATION_SHIM_STRING                              "01e46fce"
#define D3D_ENABLE_VALIDATION_SHIM_ID                                  0x00e46fce
#define D3D_ENABLE_VALIDATION_SHIM_OVERINSTALL                         0 // OVERRIDE
#define D3D_ENABLE_VALIDATION_SHIM_OFF                                 0x00000000
#define D3D_ENABLE_VALIDATION_SHIM_DISABLED                            0x00000000
#define D3D_ENABLE_VALIDATION_SHIM_ON                                  0x00000001
#define D3D_ENABLE_VALIDATION_SHIM_ENABLED                             0x00000001
#define D3D_ENABLE_VALIDATION_SHIM_DEFAULT                             D3D_ENABLE_VALIDATION_SHIM_OFF


#define D3D_OCGCONTROL_DRIVE_COMPILE_STRING                            "OCGCONTROL_DRIVE_COMPILE"
#define D3D_OCGCONTROL_DRIVE_COMPILE_ID                                0x00e107d8
#define D3D_OCGCONTROL_DRIVE_COMPILE_OVERINSTALL                       0 // OVERRIDE
#define D3D_OCGCONTROL_DRIVE_COMPILE_OFF                               0x12542653
#define D3D_OCGCONTROL_DRIVE_COMPILE_DISABLED                          0x12542653
#define D3D_OCGCONTROL_DRIVE_COMPILE_ON                                0x78260374
#define D3D_OCGCONTROL_DRIVE_COMPILE_ENABLED                           0x78260374
#define D3D_OCGCONTROL_DRIVE_COMPILE_DEFAULT                           D3D_OCGCONTROL_DRIVE_COMPILE_OFF


#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_STRING                      "OCGCONTROL_DRIVE_COMPILE_FLAGS"
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_ID                          0x00e107d9
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_OVERINSTALL                 0 // OVERRIDE
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_USE_ALWAYS                  0x00000001
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_RANDOM_ORDER                0x00000002
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_VALIDATION                  0x00000004
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_SPACE_SEARCH                0x00000008
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_DEBUG_OUTPUT                0x00000010
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_AGGRESSIVE                  0x00000020
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_HASH_COPARGS                0x00000040
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_TRIMMED_VECTORS             0x00000080
#define D3D_OCGCONTROL_DRIVE_COMPILE_FLAGS_DEFAULT                     0


#define D3D_OCGCONTROL_KNOBS_FILE_STRING                               "78452832"
#define D3D_OCGCONTROL_KNOBS_FILE_ID                                   0x00e107d5
#define D3D_OCGCONTROL_KNOBS_FILE_OVERINSTALL                          0 // OVERRIDE
#define D3D_OCGCONTROL_KNOBS_FILE_OFF                                  0x00000000
#define D3D_OCGCONTROL_KNOBS_FILE_DISABLED                             0x00000000
#define D3D_OCGCONTROL_KNOBS_FILE_ON                                   0x00000001
#define D3D_OCGCONTROL_KNOBS_FILE_ENABLED                              0x00000001
#define D3D_OCGCONTROL_KNOBS_FILE_DEFAULT                              D3D_OCGCONTROL_KNOBS_FILE_OFF


#define D3D_OCGCONTROL_KNOBS_FILENAME_STRING                           "78452833"
#define D3D_OCGCONTROL_KNOBS_FILENAME_ID                               0x00e107d6
#define D3D_OCGCONTROL_KNOBS_FILENAME_OVERINSTALL                      0 // OVERRIDE
#define D3D_OCGCONTROL_KNOBS_FILENAME_DEFAULT                          "C:\\ocg_knobs.txt"


#define D3D_OCGCONTROL_NVIR_HASH_STRING                                "OCGCONTROL_NVIR_HASH"
#define D3D_OCGCONTROL_NVIR_HASH_ID                                    0x00e107d7
#define D3D_OCGCONTROL_NVIR_HASH_OVERINSTALL                           0 // OVERRIDE
#define D3D_OCGCONTROL_NVIR_HASH_OFF                                   0
#define D3D_OCGCONTROL_NVIR_HASH_DISABLED                              0
#define D3D_OCGCONTROL_NVIR_HASH_ON                                    1
#define D3D_OCGCONTROL_NVIR_HASH_ENABLED                               1
#define D3D_OCGCONTROL_NVIR_HASH_DEFAULT                               D3D_OCGCONTROL_NVIR_HASH_OFF


#define D3D_REFCOUNT_SPIN_TIME_AFTER_WAKEUP_STRING                     "20149791"
#define D3D_REFCOUNT_SPIN_TIME_AFTER_WAKEUP_ID                         0x00776843
#define D3D_REFCOUNT_SPIN_TIME_AFTER_WAKEUP_OVERINSTALL                0 // OVERRIDE
#define D3D_REFCOUNT_SPIN_TIME_AFTER_WAKEUP_DEFAULT                    100


#define D3D_STEREO_BLACK_LIST_STRING                                   "16190349"
#define D3D_STEREO_BLACK_LIST_ID                                       0x00161903
#define D3D_STEREO_BLACK_LIST_OVERINSTALL                              0 // OVERRIDE
#define D3D_STEREO_BLACK_LIST_OFF                                      0
#define D3D_STEREO_BLACK_LIST_DISABLED                                 0
#define D3D_STEREO_BLACK_LIST_ON                                       1
#define D3D_STEREO_BLACK_LIST_ENABLED                                  1
#define D3D_STEREO_BLACK_LIST_DEFAULT                                  D3D_STEREO_BLACK_LIST_OFF


#define D3D_TEMP_STRING                                                "3D9AB1"
#define D3D_TEMP_ID                                                    0x003d9ab1
#define D3D_TEMP_OVERINSTALL                                           0 // OVERRIDE
#define D3D_TEMP_DEFAULT                                               0


#define D3D_TEX_SMP_MERGE_STRING                                       "da98d93a"
#define D3D_TEX_SMP_MERGE_ID                                           0x00d98f93
#define D3D_TEX_SMP_MERGE_OVERINSTALL                                  0 // OVERRIDE
#define D3D_TEX_SMP_MERGE_DISABLE_MME_RESOLVE_D3D11                    0x00000001
#define D3D_TEX_SMP_MERGE_DISABLE_MME_RESOLVE_D3D12                    0x00000002
#define D3D_TEX_SMP_MERGE_DISABLE_MME_RESOLVE_D3D11_ON_KEPLER          0x00000010
#define D3D_TEX_SMP_MERGE_DISABLE_MME_RESOLVE_D3D12_ON_KEPLER          0x00000020
#define D3D_TEX_SMP_MERGE_DEFAULT                                      0


#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_STRING                            "12a622cb"
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_ID                                0x0088a9eb
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERINSTALL                       0 // OVERRIDE
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OFF                               0x00000000
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_CLIP_PRIMARY                      0x00000001
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_CLIP_OFFSCREEN                    0x00000002
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_CLIP_INDICATOR                    0x10000000
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_DEFAULT                           D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OFF


#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_STRING                  "19d332fe"
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_ID                      0x0085b4bc
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_OVERINSTALL             0 // OVERRIDE
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_MIN                     0x00000000
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_MAX                     0x0000ffff
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_H_DEFAULT                 0x00000000


#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_STRING                  "17a183bb"
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_ID                      0x0081d8aa
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_OVERINSTALL             0 // OVERRIDE
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_MIN                     0x00000000
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_MAX                     0x0000ffff
#define D3D_WS_MOSAIC_CLIP_TO_SUBDEV_OVERLAP_V_DEFAULT                 0x00000000


#define D3D_WS_STEREO_SUPPORT_STRING                                   "36190450"
#define D3D_WS_STEREO_SUPPORT_ID                                       0x00361904
#define D3D_WS_STEREO_SUPPORT_OVERINSTALL                              0 // OVERRIDE
#define D3D_WS_STEREO_SUPPORT_OFF                                      0x0
#define D3D_WS_STEREO_SUPPORT_FULLSCREEN                               0x1
#define D3D_WS_STEREO_SUPPORT_WINDOWED                                 0x2
#define D3D_WS_STEREO_SUPPORT_DEFAULT                                  D3D_WS_STEREO_SUPPORT_FULLSCREEN


#define DBGFLUSHTYPE_STRING                                            "03122586"
#define DBGFLUSHTYPE_ID                                                0x00287316
#define DBGFLUSHTYPE_OVERINSTALL                                       0 // OVERRIDE
#define DBGFLUSHTYPE_DBG_FLUSH_NONE                                    0x00000000
#define DBGFLUSHTYPE_DBG_FLUSH_STATE_OBJECTS                           0x00000001
#define DBGFLUSHTYPE_DBG_FLUSH_STATE_UPDATES                           0x00000002
#define DBGFLUSHTYPE_DBG_FLUSH_RESOURCE_BINDS                          0x00000004
#define DBGFLUSHTYPE_DBG_FLUSH_RESOURCE_UPDATES                        0x00000008
#define DBGFLUSHTYPE_DBG_FLUSH_SHADER                                  0x00000010
#define DBGFLUSHTYPE_DBG_FLUSH_CLEARS                                  0x00000020
#define DBGFLUSHTYPE_DBG_FLUSH_3D                                      0x00000040
#define DBGFLUSHTYPE_DBG_FLUSH_PIPELINE                                0x00000080
#define DBGFLUSHTYPE_DBG_FLUSH_ASYNCCOPY                               0x00000100
#define DBGFLUSHTYPE_DBG_FLUSH_COMPUTE                                 0x00000200
#define DBGFLUSHTYPE_DBG_FLUSH_COMPUTE_STATE                           0x00000400
#define DBGFLUSHTYPE_DBG_FLUSH_CE                                      0x00000800
#define DBGFLUSHTYPE_DEFAULT                                           NVDBG_FLUSH_NONE


#define DEBUG_SLI_NVAPI_FUNCTIONALITY_STRING                           "52D16193"
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_ID                               0x007bc368
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_OVERINSTALL                      0 // OVERRIDE
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_DEFAULT                          0x00000000
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_DISCARD_HINT_DISABLE             0x00000001
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_BROADCAST_HINT_DISABLE           0x00000002
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_RESPECT_SYNC_HINT_DISABLE        0x00000004
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_BEGIN_END_DISABLE                0x00000008
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_REPORT_NO_SLI_SUPPORT            0x00000010
#define DEBUG_SLI_NVAPI_FUNCTIONALITY_REPORT_ALL_BEGIN_END_ENTRIES_IN_SLI_LOG 0x00000020


#define DIRECTFLIP_CONFIG_STRING                                       "FA672346"
#define DIRECTFLIP_CONFIG_ID                                           0x0093579b
#define DIRECTFLIP_CONFIG_OVERINSTALL                                  0 // OVERRIDE
#define DIRECTFLIP_CONFIG_DISABLED                                     0x00000000
#define DIRECTFLIP_CONFIG_OFF                                          0x00000000
#define DIRECTFLIP_CONFIG_0                                            0x00000000
#define DIRECTFLIP_CONFIG_INHIBIT_FLUSH                                0x00000001
#define DIRECTFLIP_CONFIG_ON                                           0x00000001
#define DIRECTFLIP_CONFIG_1                                            0x00000001
#define DIRECTFLIP_CONFIG_MASK                                         0x00000001
#define DIRECTFLIP_CONFIG_DEFAULT                                      DIRECTFLIP_CONFIG_INHIBIT_FLUSH


#define DISABLEINT3_STRING                                             "69109020"
#define DISABLEINT3_ID                                                 0x001d9c8a
#define DISABLEINT3_OVERINSTALL                                        0 // OVERRIDE
#define DISABLEINT3_OFF                                                0x00000000
#define DISABLEINT3_DISABLED                                           0x00000000
#define DISABLEINT3_ON                                                 0x00000001
#define DISABLEINT3_ENABLED                                            0x00000001
#define DISABLEINT3_DEFAULT                                            DISABLEINT3_OFF


#define DISABLEZBUFFERMIRROR_STRING                                    "fe813414"
#define DISABLEZBUFFERMIRROR_ID                                        0x0075e020
#define DISABLEZBUFFERMIRROR_OVERINSTALL                               0 // OVERRIDE
#define DISABLEZBUFFERMIRROR_OFF                                       0x51661620
#define DISABLEZBUFFERMIRROR_DISABLED                                  0x51661620
#define DISABLEZBUFFERMIRROR_ON                                        0x60792907
#define DISABLEZBUFFERMIRROR_ENABLED                                   0x60792907
#define DISABLEZBUFFERMIRROR_DEFAULT                                   DISABLEZBUFFERMIRROR_OFF


#define DISABLE_64_BIT_REFERENCE_COUNT_STRING                          "0x190410"
#define DISABLE_64_BIT_REFERENCE_COUNT_ID                              0x00190410
#define DISABLE_64_BIT_REFERENCE_COUNT_OVERINSTALL                     0 // OVERRIDE
#define DISABLE_64_BIT_REFERENCE_COUNT_OFF                             0x000000000
#define DISABLE_64_BIT_REFERENCE_COUNT_DISABLED                        0x000000000
#define DISABLE_64_BIT_REFERENCE_COUNT_ON                              0x000000001
#define DISABLE_64_BIT_REFERENCE_COUNT_ENABLED                         0x000000001
#define DISABLE_64_BIT_REFERENCE_COUNT_DEFAULT                         DISABLE_64_BIT_REFERENCE_COUNT_OFF


#define DISABLE_ASSERTS_STRING                                         "a893b92d"
#define DISABLE_ASSERTS_ID                                             0x00367a46
#define DISABLE_ASSERTS_OVERINSTALL                                    0 // OVERRIDE
#define DISABLE_ASSERTS_OFF                                            0x00000000
#define DISABLE_ASSERTS_DISABLED                                       0x00000000
#define DISABLE_ASSERTS_ON                                             0x00000001
#define DISABLE_ASSERTS_ENABLED                                        0x00000001
#define DISABLE_ASSERTS_DEFAULT                                        DISABLE_ASSERTS_OFF


#define DISABLE_ASSERT_SUPPRESSION_STRING                              "200386643"
#define DISABLE_ASSERT_SUPPRESSION_ID                                  0x00202318
#define DISABLE_ASSERT_SUPPRESSION_OVERINSTALL                         0 // OVERRIDE
#define DISABLE_ASSERT_SUPPRESSION_OFF                                 0x0
#define DISABLE_ASSERT_SUPPRESSION_DISABLED                            0x0
#define DISABLE_ASSERT_SUPPRESSION_ON                                  0x1
#define DISABLE_ASSERT_SUPPRESSION_ENABLED                             0x1
#define DISABLE_ASSERT_SUPPRESSION_DEFAULT                             DISABLE_ASSERT_SUPPRESSION_OFF


#define DISABLE_ATOMIC_REDUCTION_OPTS_STRING                           "6af00731"
#define DISABLE_ATOMIC_REDUCTION_OPTS_ID                               0x007007ac
#define DISABLE_ATOMIC_REDUCTION_OPTS_OVERINSTALL                      0 // OVERRIDE
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_PIXEL_SHADER_ATOM        0x00000001
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_PIXEL_SHADER_SUATOM      0x00000002
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_PIXEL_SHADER_ALLOC_SHFL  0x00000004
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_PIXEL_SHADER_CONSUME_SHFL 0x00000008
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_COMPUTE_SHADER_ATOM      0x00000010
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_COMPUTE_SHADER_SUATOM    0x00000020
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_COMPUTE_SHADER_ALLOC_SHFL 0x00000040
#define DISABLE_ATOMIC_REDUCTION_OPTS_DISABLE_COMPUTE_SHADER_CONSUME_SHFL 0x00000080
#define DISABLE_ATOMIC_REDUCTION_OPTS_DEFAULT                          0x0


#define DISABLE_COMPUTE_MME_FOR_OPERATION_STRING                       "F42AC0"
#define DISABLE_COMPUTE_MME_FOR_OPERATION_ID                           0x00f42ac0
#define DISABLE_COMPUTE_MME_FOR_OPERATION_OVERINSTALL                  0 // OVERRIDE
#define DISABLE_COMPUTE_MME_FOR_OPERATION_CPU_SIDE_CB_UPLOAD_BY_I2MME  0x00000001
#define DISABLE_COMPUTE_MME_FOR_OPERATION_FILTER_SETDESCRIPTORHEAP_METHODS 0x00000002
#define DISABLE_COMPUTE_MME_FOR_OPERATION_SAVE_RESTORE_MME_ON_FE1      0x00000004
#define DISABLE_COMPUTE_MME_FOR_OPERATION_COPY_GSCSECTIONS_TO_GSCB     0x00000008
#define DISABLE_COMPUTE_MME_FOR_OPERATION_POLL_FOR_DATARAM_REUSE       0x00000010
#define DISABLE_COMPUTE_MME_FOR_OPERATION_BUILD_QMD                    0x00000100
#define DISABLE_COMPUTE_MME_FOR_OPERATION_INCREMENTAL_BUILD_QMD        0x00000200
#define DISABLE_COMPUTE_MME_FOR_OPERATION_SKIP_CPU_SIDE_QMD_UPDATE     0x00000400
#define DISABLE_COMPUTE_MME_FOR_OPERATION_DEFAULT                      0


#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_STRING                      "0x341311"
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_ID                          0x00341311
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_OVERINSTALL                 0 // OVERRIDE
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_OFF                         0
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_DISABLED                    0
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_ON                          1
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_ENABLED                     1
#define DISABLE_MME_MAX_INSTRUCTIONS_CHECK_DEFAULT                     DISABLE_MME_MAX_INSTRUCTIONS_CHECK_ON


#define DISABLE_PIXEL_KILL_STRING                                      "00034522"
#define DISABLE_PIXEL_KILL_ID                                          0x00447456
#define DISABLE_PIXEL_KILL_OVERINSTALL                                 0 // OVERRIDE
#define DISABLE_PIXEL_KILL_OFF                                         0x0
#define DISABLE_PIXEL_KILL_DISABLED                                    0x0
#define DISABLE_PIXEL_KILL_ON                                          0x1
#define DISABLE_PIXEL_KILL_ENABLED                                     0x1
#define DISABLE_PIXEL_KILL_DEFAULT                                     DISABLE_PIXEL_KILL_OFF


#define DISABLE_SHDR_IMGFROMCPU_STRING                                 "98366542"
#define DISABLE_SHDR_IMGFROMCPU_ID                                     0x003a9393
#define DISABLE_SHDR_IMGFROMCPU_OVERINSTALL                            0 // OVERRIDE
#define DISABLE_SHDR_IMGFROMCPU_OFF                                    0x89236321
#define DISABLE_SHDR_IMGFROMCPU_DISABLED                               0x89236321
#define DISABLE_SHDR_IMGFROMCPU_ON                                     0x76632452
#define DISABLE_SHDR_IMGFROMCPU_ENABLED                                0x76632452
#define DISABLE_SHDR_IMGFROMCPU_DEFAULT                                DISABLE_SHDR_IMGFROMCPU_OFF


#define DISABLE_SRGB_STRING                                            "83e19fde"
#define DISABLE_SRGB_ID                                                0x00196f1d
#define DISABLE_SRGB_OVERINSTALL                                       0 // OVERRIDE
#define DISABLE_SRGB_OFF                                               0x00000000
#define DISABLE_SRGB_DISABLE_WRITES_ON_BLEND_DISABLE                   0x00000001
#define DISABLE_SRGB_DISABLE_WRITE_CONVERSION                          0x00000002
#define DISABLE_SRGB_DISABLE_READ_CONVERSION                           0x00000004
#define DISABLE_SRGB_DISABLE_BLIT_READ_CONVERSION                      0x00000008
#define DISABLE_SRGB_DISABLE_BLIT_WRITE_CONVERSION                     0x00000010
#define DISABLE_SRGB_ON                                                0x0000001e
#define DISABLE_SRGB_DISABLE_DSR_SRGB                                  0x00000020
#define DISABLE_SRGB_DEFAULT                                           DISABLE_SRGB_OFF


#define DISABLE_STENCIL_ZBC_DX12_STRING                                "22845933"
#define DISABLE_STENCIL_ZBC_DX12_ID                                    0x00939833
#define DISABLE_STENCIL_ZBC_DX12_OVERINSTALL                           0 // OVERRIDE
#define DISABLE_STENCIL_ZBC_DX12_OFF                                   0x0
#define DISABLE_STENCIL_ZBC_DX12_DISABLED                              0x0
#define DISABLE_STENCIL_ZBC_DX12_ON                                    0x1
#define DISABLE_STENCIL_ZBC_DX12_ENABLED                               0x1
#define DISABLE_STENCIL_ZBC_DX12_DEFAULT                               DISABLE_STENCIL_ZBC_DX12_OFF


#define DISABLE_Z16_STRING                                             "a225f781"
#define DISABLE_Z16_ID                                                 0x0017fd6d
#define DISABLE_Z16_OVERINSTALL                                        0 // OVERRIDE
#define DISABLE_Z16_OFF                                                0x00000000
#define DISABLE_Z16_DISABLED                                           0x00000000
#define DISABLE_Z16_ON                                                 0x00000001
#define DISABLE_Z16_ENABLED                                            0x00000001
#define DISABLE_Z16_DEFAULT                                            DISABLE_Z16_OFF


#define DISALLOW_AGP_VB_STRING                                         "27380394"
#define DISALLOW_AGP_VB_ID                                             0x00499b0e
#define DISALLOW_AGP_VB_OVERINSTALL                                    0 // OVERRIDE
#define DISALLOW_AGP_VB_OFF                                            0x38956423
#define DISALLOW_AGP_VB_DISABLED                                       0x38956423
#define DISALLOW_AGP_VB_ON                                             0x38499743
#define DISALLOW_AGP_VB_ENABLED                                        0x38499743
#define DISALLOW_AGP_VB_DEFAULT                                        DISALLOW_AGP_VB_OFF


#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_STRING             "0xacbcc1"
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_ID                 0x00acbcc1
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_OVERINSTALL        0 // OVERRIDE
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_ONLY_CLEAR_ON_REQ_HW 0x00000000
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_CLEAR_ON_ALL_HW    0x00000001
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_SKIP_CLEAR_ON_ALL_HW 0x00000002
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_CLEAR_HW_MASK      0x0000000F
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_SKIP_CLEAR_RTVS    0x00000010
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_SKIP_CLEAR_DSVS    0x00000020
#define DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_DEFAULT            DISCARDRESOURCE_HANDLING_FOR_TILEDRESOURCES_ONLY_CLEAR_ON_REQ_HW


#define DISCARD_ENABLE_STRING                                          "47294942"
#define DISCARD_ENABLE_ID                                              0x003940a1
#define DISCARD_ENABLE_OVERINSTALL                                     0 // OVERRIDE
#define DISCARD_ENABLE_DISABLE                                         0x00000000
#define DISCARD_ENABLE_ENABLE_RTV_DISCARD                              0x00000001
#define DISCARD_ENABLE_ENABLE_SRV_DISCARD                              0x00000002
#define DISCARD_ENABLE_ENABLE_DSV_DISCARD                              0x00000004
#define DISCARD_ENABLE_ENABLE_UAV_DISCARD                              0x00000008
#define DISCARD_ENABLE_ENABLE_RESOURCE_DISCARD                         0x00000010
#define DISCARD_ENABLE_DEFAULT                                         0xFFFFFFFF


#define DISPATCH_HELPER_FLAGS_STRING                                   "4ff7729c"
#define DISPATCH_HELPER_FLAGS_ID                                       0x005d35de
#define DISPATCH_HELPER_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define DISPATCH_HELPER_FLAGS_DISABLE_CORE_DISPATCH_FOR_DX11           0x00000001
#define DISPATCH_HELPER_FLAGS_DISABLE_CORE_DISPATCH_FOR_DX11_AUTO_SCG  0x00000002
#define DISPATCH_HELPER_FLAGS_DISABLE_CORE_DISPATCH_FOR_DX11_AUTO_SCG_SLI 0x00000004
#define DISPATCH_HELPER_FLAGS_DEBUG_TRACK_COUNTER_VALUES               0x20000000
#define DISPATCH_HELPER_FLAGS_DEBUG_TRACK_CORE_DISPATCH_QMDS           0x40000000
#define DISPATCH_HELPER_FLAGS_DEBUG_TRACK_DISPATCH_HELPER_QMDS         0x80000000
#define DISPATCH_HELPER_FLAGS_DEFAULT                                  0


#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_STRING                       "b3433086"
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_ID                           0x00c7f8d3
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_OVERINSTALL                  0 // OVERRIDE
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_OFF                          0
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_DISABLED                     0
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_ON                           1
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_ENABLED                      1
#define DISPATCH_HELPER_PRE_EXECUTE_QUEUE_DEFAULT                      DISPATCH_HELPER_PRE_EXECUTE_QUEUE_OFF


#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_STRING                     "3ddac2ac"
#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_ID                         0x006c44ed
#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_OVERINSTALL                0 // OVERRIDE
#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_DISABLE_COMPUTE_QUEUE_TIMESTAMPS 0x00000001
#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_DISABLE_DIRECT_QUEUE_TIMESTAMPS 0x00000002
#define DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_DEFAULT                    DISPATCH_HELPER_QMD_TIMESTAMP_FLAGS_DISABLE_DIRECT_QUEUE_TIMESTAMPS


#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_STRING      "fac430"
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_ID          0x00fac430
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_OVERINSTALL 0 // OVERRIDE
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_OFF         0
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_DISABLED    0
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_ON          1
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_ENABLED     1
#define DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_DEFAULT     DO_WAIT_BEFORE_GPFIFO_SWITCH_IN_UMD_MANAGED_GPFIFO_ON


#define DSC_MIN_COPY_SIZE_STRING                                       "4f887791"
#define DSC_MIN_COPY_SIZE_ID                                           0x006da691
#define DSC_MIN_COPY_SIZE_OVERINSTALL                                  0 // OVERRIDE
#define DSC_MIN_COPY_SIZE_DEFAULT                                      0x0


#define DUMMY_BINARY_STRING                                            "DUMMY_BINARY"
#define DUMMY_BINARY_ID                                                0x00ba4050
#define DUMMY_BINARY_OVERINSTALL                                       0 // OVERRIDE


#define DUMMY_BOOL_STRING                                              "DUMMY_BOOL"
#define DUMMY_BOOL_ID                                                  0x001d8269
#define DUMMY_BOOL_OVERINSTALL                                         0 // OVERRIDE
#define DUMMY_BOOL_OFF                                                 0x66666666
#define DUMMY_BOOL_DISABLED                                            0x66666666
#define DUMMY_BOOL_ON                                                  0x99999999
#define DUMMY_BOOL_ENABLED                                             0x99999999


#define DUMMY_DWORD_STRING                                             "DUMMY_DWORD"
#define DUMMY_DWORD_ID                                                 0x0023d96b
#define DUMMY_DWORD_OVERINSTALL                                        0 // OVERRIDE


#define DUMMY_FLOAT_STRING                                             "DUMMY_FLOAT"
#define DUMMY_FLOAT_ID                                                 0x00780388
#define DUMMY_FLOAT_OVERINSTALL                                        0 // OVERRIDE


#define DUMMY_QWORD_STRING                                             "DUMMY_QWORD"
#define DUMMY_QWORD_ID                                                 0x003d68af
#define DUMMY_QWORD_OVERINSTALL                                        0 // OVERRIDE


#define DUMMY_STRING_STRING                                            "DUMMY_STRING"
#define DUMMY_STRING_ID                                                0x002d8faf
#define DUMMY_STRING_OVERINSTALL                                       0 // OVERRIDE


#define DUMPHEAP_STRING                                                "52971800"
#define DUMPHEAP_ID                                                    0x00604707
#define DUMPHEAP_OVERINSTALL                                           0 // OVERRIDE
#define DUMPHEAP_OFF                                                   0x00000000
#define DUMPHEAP_STANDARD                                              0x00000001
#define DUMPHEAP_DEFAULT                                               DUMPHEAP_OFF


#define DUMPPB_STRING                                                  "40194014"
#define DUMPPB_ID                                                      0x00d987a5
#define DUMPPB_OVERINSTALL                                             0 // OVERRIDE
#define DUMPPB_OFF                                                     0x00000000
#define DUMPPB_DISABLED                                                0x00000000
#define DUMPPB_ON                                                      0x00000001
#define DUMPPB_ENABLED                                                 0x00000001
#define DUMPPB_DEFAULT                                                 DUMPPB_OFF


#define DVS_TESTNAME_STRING                                            "2023179"
#define DVS_TESTNAME_ID                                                0x00202317
#define DVS_TESTNAME_OVERINSTALL                                       0 // OVERRIDE


#define DWM_LOW_LATENCY_STRING                                         "FA677634"
#define DWM_LOW_LATENCY_ID                                             0x0093d45a
#define DWM_LOW_LATENCY_OVERINSTALL                                    0 // OVERRIDE
#define DWM_LOW_LATENCY_OFF                                            0x00000000
#define DWM_LOW_LATENCY_DISABLED                                       0x00000000
#define DWM_LOW_LATENCY_ON                                             0x00000001
#define DWM_LOW_LATENCY_ENABLED                                        0x00000001
#define DWM_LOW_LATENCY_DEFAULT                                        DWM_LOW_LATENCY_OFF


#define DWM_SHIM_STRING                                                "FA672344"
#define DWM_SHIM_ID                                                    0x0093568a
#define DWM_SHIM_OVERINSTALL                                           0 // OVERRIDE
#define DWM_SHIM_DISABLED                                              0x00000000
#define DWM_SHIM_OFF                                                   0x00000000
#define DWM_SHIM_0                                                     0x00000000
#define DWM_SHIM_ENABLE_FOR_SLI                                        0x00000001
#define DWM_SHIM_ON                                                    0x00000001
#define DWM_SHIM_1                                                     0x00000001
#define DWM_SHIM_MASK                                                  0x00000001
#define DWM_SHIM_DEFAULT                                               DWM_SHIM_ENABLE_FOR_SLI


#define DX10_CLEAR_UAV_SUST_STRING                                     "63237155"
#define DX10_CLEAR_UAV_SUST_ID                                         0x00b00156
#define DX10_CLEAR_UAV_SUST_OVERINSTALL                                0 // OVERRIDE
#define DX10_CLEAR_UAV_SUST_OFF                                        0x0
#define DX10_CLEAR_UAV_SUST_DISABLED                                   0x0
#define DX10_CLEAR_UAV_SUST_ON                                         0x1
#define DX10_CLEAR_UAV_SUST_ENABLED                                    0x1
#define DX10_CLEAR_UAV_SUST_DEFAULT                                    DX10_CLEAR_UAV_SUST_OFF


#define DX11_CB_BASE_OFFSET_BYTES_STRING                               "0xacbff1"
#define DX11_CB_BASE_OFFSET_BYTES_ID                                   0x00acbff1
#define DX11_CB_BASE_OFFSET_BYTES_OVERINSTALL                          0 // OVERRIDE
#define DX11_CB_BASE_OFFSET_BYTES_OFFSET_0                             0
#define DX11_CB_BASE_OFFSET_BYTES_OFFSET_64                            64
#define DX11_CB_BASE_OFFSET_BYTES_OFFSET_128                           128
#define DX11_CB_BASE_OFFSET_BYTES_OFFSET_192                           192
#define DX11_CB_BASE_OFFSET_BYTES_DEFAULT                              0


#define DX11_DISABLE_COALESCED_ATOMICS_STRING                          ""
#define DX11_DISABLE_COALESCED_ATOMICS_ID                              0x00badbed
#define DX11_DISABLE_COALESCED_ATOMICS_OVERINSTALL                     0 // OVERRIDE
#define DX11_DISABLE_COALESCED_ATOMICS_NONE                            0x00000000
#define DX11_DISABLE_COALESCED_ATOMICS_AND                             0x00000001
#define DX11_DISABLE_COALESCED_ATOMICS_OR                              0x00000002
#define DX11_DISABLE_COALESCED_ATOMICS_XOR                             0x00000004
#define DX11_DISABLE_COALESCED_ATOMICS_ADD                             0x00000008
#define DX11_DISABLE_COALESCED_ATOMICS_DEC                             0x00000010
#define DX11_DISABLE_COALESCED_ATOMICS_INC                             0x00000020
#define DX11_DISABLE_COALESCED_ATOMICS_MAX                             0x00000040
#define DX11_DISABLE_COALESCED_ATOMICS_MIN                             0x00000080
#define DX11_DISABLE_COALESCED_ATOMICS_SWAP                            0x00000100
#define DX11_DISABLE_COALESCED_ATOMICS_CAS                             0x00000200
#define DX11_DISABLE_COALESCED_ATOMICS_ALLOC                           0x00000400
#define DX11_DISABLE_COALESCED_ATOMICS_CONSUME                         0x00000800
#define DX11_DISABLE_COALESCED_ATOMICS_ALL                             0x00000FFF
#define DX11_DISABLE_COALESCED_ATOMICS_DEFAULT                         DX11_DISABLE_COALESCED_ATOMICS_NONE


#define DX11_REENTRANCY_CHECK_STRING                                   "01e35fce"
#define DX11_REENTRANCY_CHECK_ID                                       0x00e35fce
#define DX11_REENTRANCY_CHECK_OVERINSTALL                              0 // OVERRIDE
#define DX11_REENTRANCY_CHECK_OFF                                      0x00000000
#define DX11_REENTRANCY_CHECK_DISABLED                                 0x00000000
#define DX11_REENTRANCY_CHECK_ON                                       0x00000001
#define DX11_REENTRANCY_CHECK_ENABLED                                  0x00000001
#define DX11_REENTRANCY_CHECK_DEFAULT                                  DX11_REENTRANCY_CHECK_OFF


#define DX12_COMMAND_ALLOCATOR_IGNORE_RESETS_STRING                    "c97313"
#define DX12_COMMAND_ALLOCATOR_IGNORE_RESETS_ID                        0x00c97313
#define DX12_COMMAND_ALLOCATOR_IGNORE_RESETS_OVERINSTALL               0 // OVERRIDE
#define DX12_COMMAND_ALLOCATOR_IGNORE_RESETS_DEFAULT                   0


#define DX12_EXPLICIT_SLI_BOOST_FORCE_STRING                           "52D11693"
#define DX12_EXPLICIT_SLI_BOOST_FORCE_ID                               0x007bda68
#define DX12_EXPLICIT_SLI_BOOST_FORCE_OVERINSTALL                      0 // OVERRIDE
#define DX12_EXPLICIT_SLI_BOOST_FORCE_DEFAULT                          0x00000000
#define DX12_EXPLICIT_SLI_BOOST_FORCE_FORCE_ENABLE                     0x00000001
#define DX12_EXPLICIT_SLI_BOOST_FORCE_FORCE_DISABLE                    0x00000002


#define DX12_HW_ROOT_TABLE_FLAGS_STRING                                "0x1bbb11"
#define DX12_HW_ROOT_TABLE_FLAGS_ID                                    0x001bbb11
#define DX12_HW_ROOT_TABLE_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define DX12_HW_ROOT_TABLE_FLAGS_REORDER_AND_GROUP_PARAMETERS          0x00000001
#define DX12_HW_ROOT_TABLE_FLAGS_DEFAULT                               DX12_HW_ROOT_TABLE_FLAGS_REORDER_AND_GROUP_PARAMETERS


#define DX12_MESH_SHAREDMEM_EMU_MODE_STRING                            "EB1205"
#define DX12_MESH_SHAREDMEM_EMU_MODE_ID                                0x00eb1205
#define DX12_MESH_SHAREDMEM_EMU_MODE_OVERINSTALL                       0 // OVERRIDE
#define DX12_MESH_SHAREDMEM_EMU_MODE_SINGLE_CTA_PER_SM                 0x0
#define DX12_MESH_SHAREDMEM_EMU_MODE_MAX_CTAS_PER_SM                   0x1
#define DX12_MESH_SHAREDMEM_EMU_MODE_DEFAULT                           DX12_MESH_SHAREDMEM_EMU_MODE_SINGLE_CTA_PER_SM


#define DXIL_CAPS_STRING                                               "0168475"
#define DXIL_CAPS_ID                                                   0x00168475
#define DXIL_CAPS_OVERINSTALL                                          0 // OVERRIDE
#define DXIL_CAPS_DISABLE_INT64_OPS                                    0x00000001
#define DXIL_CAPS_DISABLE_WAVE_OPS                                     0x00000002
#define DXIL_CAPS_DEPRECATED                                           0x00000004
#define DXIL_CAPS_DEFAULT                                              0


#define DXIL_DEFAULT_REFACTORING_STRING                                "0160509"
#define DXIL_DEFAULT_REFACTORING_ID                                    0x00160509
#define DXIL_DEFAULT_REFACTORING_OVERINSTALL                           0 // OVERRIDE
#define DXIL_DEFAULT_REFACTORING_OFF                                   0x00000000
#define DXIL_DEFAULT_REFACTORING_DISABLED                              0x00000000
#define DXIL_DEFAULT_REFACTORING_ON                                    0x00000001
#define DXIL_DEFAULT_REFACTORING_ENABLED                               0x00000001
#define DXIL_DEFAULT_REFACTORING_DEFAULT                               DXIL_DEFAULT_REFACTORING_ON


#define DXIL_EMULATE_IPA_WITH_LDTRAM_STRING                            "813923"
#define DXIL_EMULATE_IPA_WITH_LDTRAM_ID                                0x00813923
#define DXIL_EMULATE_IPA_WITH_LDTRAM_OVERINSTALL                       0 // OVERRIDE
#define DXIL_EMULATE_IPA_WITH_LDTRAM_OFF                               0x00000000
#define DXIL_EMULATE_IPA_WITH_LDTRAM_DISABLED                          0x00000000
#define DXIL_EMULATE_IPA_WITH_LDTRAM_ON                                0x00000001
#define DXIL_EMULATE_IPA_WITH_LDTRAM_ENABLED                           0x00000001
#define DXIL_EMULATE_IPA_WITH_LDTRAM_DEFAULT                           0x0


#define DXIL_MODE_STRING                                               "0160229"
#define DXIL_MODE_ID                                                   0x00160229
#define DXIL_MODE_OVERINSTALL                                          0 // OVERRIDE
#define DXIL_MODE_DISABLE                                              0x00000000
#define DXIL_MODE_DIRECT                                               0x00000002
#define DXIL_MODE_DEFAULT                                              DXIL_MODE_DIRECT


#define DXIL_RELEASE_SUPPORTED_VERSION_STRING                          "0187365"
#define DXIL_RELEASE_SUPPORTED_VERSION_ID                              0x00187365
#define DXIL_RELEASE_SUPPORTED_VERSION_OVERINSTALL                     0 // OVERRIDE
#define DXIL_RELEASE_SUPPORTED_VERSION_DEFAULT                         0x00060006


#define DXML_USE_CBL_STRING                                            "ababdb"
#define DXML_USE_CBL_ID                                                0x00ababdb
#define DXML_USE_CBL_OVERINSTALL                                       0 // OVERRIDE
#define DXML_USE_CBL_CUBIN_NVAPI_DX11                                  0x00000001
#define DXML_USE_CBL_CUBIN_NVAPI_DX12                                  0x00000002
#define DXML_USE_CBL_DEFAULT                                           0x3


#define DXML_USE_DEP_QMD_LAUNCHES_STRING                               "abcd32"
#define DXML_USE_DEP_QMD_LAUNCHES_ID                                   0x00abcd32
#define DXML_USE_DEP_QMD_LAUNCHES_OVERINSTALL                          0 // OVERRIDE
#define DXML_USE_DEP_QMD_LAUNCHES_CUBIN_NVAPI                          0x00000001
#define DXML_USE_DEP_QMD_LAUNCHES_METACOMMAND                          0x00000002
#define DXML_USE_DEP_QMD_LAUNCHES_DEFAULT                              0x3


#define DXML_USE_NEW_CBL_STRING                                        "ababd7"
#define DXML_USE_NEW_CBL_ID                                            0x00ababd7
#define DXML_USE_NEW_CBL_OVERINSTALL                                   0 // OVERRIDE
#define DXML_USE_NEW_CBL_OFF                                           0x0
#define DXML_USE_NEW_CBL_DISABLED                                      0x0
#define DXML_USE_NEW_CBL_ON                                            0x1
#define DXML_USE_NEW_CBL_ENABLED                                       0x1
#define DXML_USE_NEW_CBL_DEFAULT                                       DXML_USE_NEW_CBL_ON


#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_STRING                       "0x2533f7"
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_ID                           0x002533f7
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_OVERINSTALL                  0 // OVERRIDE
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_OFF                          0x00000000
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_DISABLED                     0x00000000
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_ON                           0x00000001
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_ENABLED                      0x00000001
#define DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_DEFAULT                      DXR_ASSUME_STRIDE_ALIGNED_ROOT_VA_OFF


#define DXR_BFV_OVERRIDE_STRING                                        "42526272"
#define DXR_BFV_OVERRIDE_ID                                            0x00de428c
#define DXR_BFV_OVERRIDE_OVERINSTALL                                   0 // OVERRIDE
#define DXR_BFV_OVERRIDE_NONE                                          0x00
#define DXR_BFV_OVERRIDE_DISABLE_DXR                                   0x01
#define DXR_BFV_OVERRIDE_ENABLE_DXR_BUT_LEAK_PSOS                      0x02
#define DXR_BFV_OVERRIDE_DEFAULT                                       DXR_BFV_OVERRIDE_NONE


#define DXR_BOOTSTRAP_USAGE_STRING                                     "0xc08a4e"
#define DXR_BOOTSTRAP_USAGE_ID                                         0x00c08a4e
#define DXR_BOOTSTRAP_USAGE_OVERINSTALL                                0 // OVERRIDE
#define DXR_BOOTSTRAP_USAGE_OFF                                        0x00000000
#define DXR_BOOTSTRAP_USAGE_DISABLED                                   0x00000000
#define DXR_BOOTSTRAP_USAGE_ON                                         0x00000001
#define DXR_BOOTSTRAP_USAGE_ENABLED                                    0x00000001
#define DXR_BOOTSTRAP_USAGE_DEFAULT                                    DXR_BOOTSTRAP_USAGE_ON


#define DXR_BVH_BUILD_BATCHING_STRING                                  "0x72ca18"
#define DXR_BVH_BUILD_BATCHING_ID                                      0x0072ca18
#define DXR_BVH_BUILD_BATCHING_OVERINSTALL                             0 // OVERRIDE
#define DXR_BVH_BUILD_BATCHING_OFF                                     0x00000000
#define DXR_BVH_BUILD_BATCHING_DISABLED                                0x00000000
#define DXR_BVH_BUILD_BATCHING_ON                                      0x00000001
#define DXR_BVH_BUILD_BATCHING_ENABLED                                 0x00000001
#define DXR_BVH_BUILD_BATCHING_DEFAULT                                 DXR_BVH_BUILD_BATCHING_ON


#define DXR_BVH_BUILD_BATCHING_FLAGS_STRING                            "0x225c2b"
#define DXR_BVH_BUILD_BATCHING_FLAGS_ID                                0x00225c2b
#define DXR_BVH_BUILD_BATCHING_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define DXR_BVH_BUILD_BATCHING_FLAGS_NONE                              0x00000000
#define DXR_BVH_BUILD_BATCHING_FLAGS_HAZARD_CHECK_ALL_TRANSITIONS      0x00000001
#define DXR_BVH_BUILD_BATCHING_FLAGS_HAZARD_CHECK_ALL_BARRIERS         0x00000002
#define DXR_BVH_BUILD_BATCHING_FLAGS_VALIDATE_SCRATCH_AND_RTAS_MEM     0x00000004
#define DXR_BVH_BUILD_BATCHING_FLAGS_UNUSED                            0x00000008
#define DXR_BVH_BUILD_BATCHING_FLAGS_FLUSH_ON_COPY                     0x00000010
#define DXR_BVH_BUILD_BATCHING_FLAGS_FLUSH_ON_EMIT                     0x00000020
#define DXR_BVH_BUILD_BATCHING_FLAGS_FLUSH_ON_DISPATCHRAYS             0x00000040
#define DXR_BVH_BUILD_BATCHING_FLAGS_FLUSH_ON_BARRIER                  0x00000080
#define DXR_BVH_BUILD_BATCHING_FLAGS_IGNORE_VA_RANGES                  0x00000080
#define DXR_BVH_BUILD_BATCHING_FLAGS_ALWAYS_FLUSH_AFTER_BATCH          0x80000000
#define DXR_BVH_BUILD_BATCHING_FLAGS_FORCE_SINGLE_BATCH                0x80000000
#define DXR_BVH_BUILD_BATCHING_FLAGS_DEFAULT                           DXR_BVH_BUILD_BATCHING_FLAGS_NONE


#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_STRING                   "0x4208bd"
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_ID                       0x004208bd
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_OVERINSTALL              0 // OVERRIDE
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_NONE                     0x00000000
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_ALLOW_UPDATE             0x00000001
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_ALLOW_COMPACTION         0x00000002
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_PREFER_FAST_TRACE        0x00000004
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_PREFER_FAST_BUILD        0x00000008
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_MINIMIZE_MEMORY          0x00000010
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_PERFORM_UPDATE           0x00000020
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_MASK                     0x0000003F
#define DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_DEFAULT                  DXR_BVH_BUILD_FLAG_FORCE_DISABLE_MASK_NONE


#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_STRING                    "0xf4ef16"
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_ID                        0x00f4ef16
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_OVERINSTALL               0 // OVERRIDE
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_NONE                      0x00000000
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_ALLOW_UPDATE              0x00000001
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_ALLOW_COMPACTION          0x00000002
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_PREFER_FAST_TRACE         0x00000004
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_PREFER_FAST_BUILD         0x00000008
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_MINIMIZE_MEMORY           0x00000010
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_PERFORM_UPDATE            0x00000020
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_MASK                      0x0000003F
#define DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_DEFAULT                   DXR_BVH_BUILD_FLAG_FORCE_ENABLE_MASK_NONE


#define DXR_CONVERT_TO_LDG_FLAGS_STRING                                "0x8ce000"
#define DXR_CONVERT_TO_LDG_FLAGS_ID                                    0x008ce000
#define DXR_CONVERT_TO_LDG_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define DXR_CONVERT_TO_LDG_FLAGS_NONE                                  0x00
#define DXR_CONVERT_TO_LDG_FLAGS_NORANGECHECK                          0x01
#define DXR_CONVERT_TO_LDG_FLAGS_DISABLESRV                            0x02
#define DXR_CONVERT_TO_LDG_FLAGS_DISABLEUAV                            0x04
#define DXR_CONVERT_TO_LDG_FLAGS_BRANCHLESS_HEADER                     0x08
#define DXR_CONVERT_TO_LDG_FLAGS_DEFAULT                               DXR_CONVERT_TO_LDG_FLAGS_NONE


#define DXR_CONVERT_TO_LDG_SHADERS_STRING                              "0x8ce002"
#define DXR_CONVERT_TO_LDG_SHADERS_ID                                  0x008ce002
#define DXR_CONVERT_TO_LDG_SHADERS_OVERINSTALL                         0 // OVERRIDE
#define DXR_CONVERT_TO_LDG_SHADERS_NONE                                0x00
#define DXR_CONVERT_TO_LDG_SHADERS_RAYGEN_SHADER                       0x01
#define DXR_CONVERT_TO_LDG_SHADERS_MISS_SHADER                         0x02
#define DXR_CONVERT_TO_LDG_SHADERS_CLOSESTHIT_SHADER                   0x04
#define DXR_CONVERT_TO_LDG_SHADERS_ANYHIT_SHADER                       0x08
#define DXR_CONVERT_TO_LDG_SHADERS_INTERSECTION_SHADER                 0x10
#define DXR_CONVERT_TO_LDG_SHADERS_CALLABLE_SHADER                     0x20
#define DXR_CONVERT_TO_LDG_SHADERS_ALL                                 0x3f
#define DXR_CONVERT_TO_LDG_SHADERS_DEFAULT                             DXR_CONVERT_TO_LDG_SHADERS_NONE


#define DXR_CONVERT_TO_LDG_TYPES_STRING                                "0x8ce001"
#define DXR_CONVERT_TO_LDG_TYPES_ID                                    0x008ce001
#define DXR_CONVERT_TO_LDG_TYPES_OVERINSTALL                           0 // OVERRIDE
#define DXR_CONVERT_TO_LDG_TYPES_NONE                                  0x0
#define DXR_CONVERT_TO_LDG_TYPES_UNUSED1                               0x1
#define DXR_CONVERT_TO_LDG_TYPES_UNUSED2                               0x2
#define DXR_CONVERT_TO_LDG_TYPES_STRUCTURED_LOAD                       0x4
#define DXR_CONVERT_TO_LDG_TYPES_RAW_LOAD                              0x8
#define DXR_CONVERT_TO_LDG_TYPES_ALL                                   0xf
#define DXR_CONVERT_TO_LDG_TYPES_DEFAULT                               DXR_CONVERT_TO_LDG_TYPES_NONE


#define DXR_DUMP_INTERMEDIATE_DXIL_STRING                              "0x50a161"
#define DXR_DUMP_INTERMEDIATE_DXIL_ID                                  0x0050a161
#define DXR_DUMP_INTERMEDIATE_DXIL_OVERINSTALL                         0 // OVERRIDE
#define DXR_DUMP_INTERMEDIATE_DXIL_OFF                                 0x00000000
#define DXR_DUMP_INTERMEDIATE_DXIL_DISABLED                            0x00000000
#define DXR_DUMP_INTERMEDIATE_DXIL_ON                                  0x00000001
#define DXR_DUMP_INTERMEDIATE_DXIL_ENABLED                             0x00000001
#define DXR_DUMP_INTERMEDIATE_DXIL_DEFAULT                             DXR_DUMP_INTERMEDIATE_DXIL_OFF


#define DXR_ENABLE_STRING                                              "0xde429a"
#define DXR_ENABLE_ID                                                  0x00de429a
#define DXR_ENABLE_OVERINSTALL                                         0 // OVERRIDE
#define DXR_ENABLE_OFF                                                 0
#define DXR_ENABLE_DISABLED                                            0
#define DXR_ENABLE_ON                                                  1
#define DXR_ENABLE_ENABLED                                             1
#define DXR_ENABLE_DEFAULT                                             DXR_ENABLE_ON


#define DXR_ENABLE_BINDLESS_CONSTANTS_STRING                           "0x8ce003"
#define DXR_ENABLE_BINDLESS_CONSTANTS_ID                               0x008ce003
#define DXR_ENABLE_BINDLESS_CONSTANTS_OVERINSTALL                      0 // OVERRIDE
#define DXR_ENABLE_BINDLESS_CONSTANTS_OFF                              0x00000000
#define DXR_ENABLE_BINDLESS_CONSTANTS_DISABLED                         0x00000000
#define DXR_ENABLE_BINDLESS_CONSTANTS_ON                               0x00000001
#define DXR_ENABLE_BINDLESS_CONSTANTS_ENABLED                          0x00000001
#define DXR_ENABLE_BINDLESS_CONSTANTS_DEFAULT                          DXR_ENABLE_BINDLESS_CONSTANTS_OFF


#define DXR_ENABLE_COROUTINES_STRING                                   "0x50a156"
#define DXR_ENABLE_COROUTINES_ID                                       0x0050a156
#define DXR_ENABLE_COROUTINES_OVERINSTALL                              0 // OVERRIDE
#define DXR_ENABLE_COROUTINES_OFF                                      0x00000000
#define DXR_ENABLE_COROUTINES_0                                        0x00000000
#define DXR_ENABLE_COROUTINES_FALSE                                    0x00000000
#define DXR_ENABLE_COROUTINES_DISABLED                                 0x00000000
#define DXR_ENABLE_COROUTINES_ON                                       0x00000001
#define DXR_ENABLE_COROUTINES_1                                        0x00000001
#define DXR_ENABLE_COROUTINES_TRUE                                     0x00000001
#define DXR_ENABLE_COROUTINES_ENABLED                                  0x00000001
#define DXR_ENABLE_COROUTINES_DEFAULT                                  DXR_ENABLE_COROUTINES_OFF


#define DXR_GRQ_MIN_FB_SIZE_STRING                                     "0x41ab94"
#define DXR_GRQ_MIN_FB_SIZE_ID                                         0x0041ab94
#define DXR_GRQ_MIN_FB_SIZE_OVERINSTALL                                0 // OVERRIDE
#define DXR_GRQ_MIN_FB_SIZE_DEFAULT                                    0x5A0000


#define DXR_MAX_PAYLOAD_REGISTERS_STRING                               "0x50a160"
#define DXR_MAX_PAYLOAD_REGISTERS_ID                                   0x0050a160
#define DXR_MAX_PAYLOAD_REGISTERS_OVERINSTALL                          0 // OVERRIDE
#define DXR_MAX_PAYLOAD_REGISTERS_DEFAULT                              0x00000020
#define DXR_MAX_PAYLOAD_REGISTERS_MAX                                  0xffffffff


#define DXR_PASCAL_MIN_FB_SIZE_STRING                                  "42526269"
#define DXR_PASCAL_MIN_FB_SIZE_ID                                      0x0046133d
#define DXR_PASCAL_MIN_FB_SIZE_OVERINSTALL                             0 // OVERRIDE
#define DXR_PASCAL_MIN_FB_SIZE_DEFAULT                                 0x5A0000


#define DXR_PIPELINE_FLAGS_STRING                                      "0x473935"
#define DXR_PIPELINE_FLAGS_ID                                          0x00473935
#define DXR_PIPELINE_FLAGS_OVERINSTALL                                 0 // OVERRIDE
#define DXR_PIPELINE_FLAGS_NONE                                        0x00000000
#define DXR_PIPELINE_FLAGS_TRIANGLES_ONLY                              0x00000200
#define DXR_PIPELINE_FLAGS_AABBS_ONLY                                  0x00000100
#define DXR_PIPELINE_FLAGS_DISABLED                                    0xFF000000
#define DXR_PIPELINE_FLAGS_DEFAULT                                     DXR_PIPELINE_FLAGS_NONE


#define DXR_PIPELINE_RECOMPILE_MODULE_THRESHOLD_STRING                 "5ec6ef"
#define DXR_PIPELINE_RECOMPILE_MODULE_THRESHOLD_ID                     0x005ec6ef
#define DXR_PIPELINE_RECOMPILE_MODULE_THRESHOLD_OVERINSTALL            0 // OVERRIDE
#define DXR_PIPELINE_RECOMPILE_MODULE_THRESHOLD_DEFAULT                0x14


#define DXR_PIPELINE_TYPE_STRING                                       "0x473934"
#define DXR_PIPELINE_TYPE_ID                                           0x00473934
#define DXR_PIPELINE_TYPE_OVERINSTALL                                  0 // OVERRIDE
#define DXR_PIPELINE_TYPE_MEGAKERNEL_SIMPLE                            0x00000000
#define DXR_PIPELINE_TYPE_BLOCKSYNC                                    0x00000001
#define DXR_PIPELINE_TYPE_DEFAULT                                      DXR_PIPELINE_TYPE_MEGAKERNEL_SIMPLE


#define DXR_RAYCOUNTER_CONFIG_STRING                                   "0x38a935"
#define DXR_RAYCOUNTER_CONFIG_ID                                       0x0038a935
#define DXR_RAYCOUNTER_CONFIG_OVERINSTALL                              0 // OVERRIDE
#define DXR_RAYCOUNTER_CONFIG_OFF                                      0x00
#define DXR_RAYCOUNTER_CONFIG_0                                        0x00
#define DXR_RAYCOUNTER_CONFIG_FALSE                                    0x00
#define DXR_RAYCOUNTER_CONFIG_DISABLED                                 0x00
#define DXR_RAYCOUNTER_CONFIG_GRPS_OUTPUT_INDICATOR                    0x01
#define DXR_RAYCOUNTER_CONFIG_GRPS_OUTPUT_FILE                         0x02
#define DXR_RAYCOUNTER_CONFIG_RAYCOUNT_OUTPUT_FILE                     0x04
#define DXR_RAYCOUNTER_CONFIG_RPF_OUTPUT_FILE                          0x08
#define DXR_RAYCOUNTER_CONFIG_RPF_OUTPUT_NVFT                          0x10
#define DXR_RAYCOUNTER_CONFIG_DEFAULT                                  DXR_RAYCOUNTER_CONFIG_OFF


#define DXR_RAYCOUNTER_STRIDE_STRING                                   "0xbd19e0"
#define DXR_RAYCOUNTER_STRIDE_ID                                       0x00bd19e0
#define DXR_RAYCOUNTER_STRIDE_OVERINSTALL                              0 // OVERRIDE
#define DXR_RAYCOUNTER_STRIDE_DEFAULT                                  0x10


#define DXR_RAYGEN_SCHEDULER_OVERRIDE_PATTERNS_STRING                  "0x6ea049"
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_PATTERNS_ID                      0x006ea049
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_PATTERNS_OVERINSTALL             0 // OVERRIDE
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_PATTERNS_DEFAULT                 L""


#define DXR_RAYGEN_SCHEDULER_OVERRIDE_TYPES_STRING                     "0x1f0ede"
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_TYPES_ID                         0x001f0ede
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_TYPES_OVERINSTALL                0 // OVERRIDE
#define DXR_RAYGEN_SCHEDULER_OVERRIDE_TYPES_DEFAULT                    L"BLOCKSYNC"


#define DXR_REPLAY_FLAGS_STRING                                        "42526271"
#define DXR_REPLAY_FLAGS_ID                                            0x00de428b
#define DXR_REPLAY_FLAGS_OVERINSTALL                                   0 // OVERRIDE
#define DXR_REPLAY_FLAGS_NONE                                          0x00
#define DXR_REPLAY_FLAGS_ALLOW_BUNDLE_REPLAY                           0x01
#define DXR_REPLAY_FLAGS_ALLOW_BAKED_BUNDLES                           0x02
#define DXR_REPLAY_FLAGS_ALLOW_FULL_REPLAY                             0x04
#define DXR_REPLAY_FLAGS_DEFAULT                                       DXR_REPLAY_FLAGS_ALLOW_BUNDLE_REPLAY


#define DXR_RG_CONTINUATION_REGS_STRING                                "0x50a154"
#define DXR_RG_CONTINUATION_REGS_ID                                    0x0050a154
#define DXR_RG_CONTINUATION_REGS_OVERINSTALL                           0 // OVERRIDE
#define DXR_RG_CONTINUATION_REGS_DEFAULT                               0x0


#define DXR_RG_INLINE_MODE_STRING                                      "0x50a159"
#define DXR_RG_INLINE_MODE_ID                                          0x0050a159
#define DXR_RG_INLINE_MODE_OVERINSTALL                                 0 // OVERRIDE
#define DXR_RG_INLINE_MODE_DISABLED                                    0x00000000
#define DXR_RG_INLINE_MODE_AUTO                                        0x00000001
#define DXR_RG_INLINE_MODE_ALWAYS                                      0x00000002
#define DXR_RG_INLINE_MODE_DEFAULT                                     DXR_RG_INLINE_MODE_DISABLED


#define DXR_SCRATCH_BUFFER_BYTES_STRING                                "0x82703b"
#define DXR_SCRATCH_BUFFER_BYTES_ID                                    0x0082703b
#define DXR_SCRATCH_BUFFER_BYTES_OVERINSTALL                           0 // OVERRIDE
#define DXR_SCRATCH_BUFFER_BYTES_DEFAULT                               0x10000000


#define DXR_SCRATCH_BUFFER_MAX_SIZE_STRING                             "0xbf15ec"
#define DXR_SCRATCH_BUFFER_MAX_SIZE_ID                                 0x00bf15ec
#define DXR_SCRATCH_BUFFER_MAX_SIZE_OVERINSTALL                        0 // OVERRIDE
#define DXR_SCRATCH_BUFFER_MAX_SIZE_DEFAULT                            0x40000000


#define DXR_SCRATCH_BUFFER_USE512M_PTES_STRING                         "0x8234a1"
#define DXR_SCRATCH_BUFFER_USE512M_PTES_ID                             0x008234a1
#define DXR_SCRATCH_BUFFER_USE512M_PTES_OVERINSTALL                    0 // OVERRIDE
#define DXR_SCRATCH_BUFFER_USE512M_PTES_OFF                            0x00000000
#define DXR_SCRATCH_BUFFER_USE512M_PTES_DISABLED                       0x00000000
#define DXR_SCRATCH_BUFFER_USE512M_PTES_ON                             0x00000001
#define DXR_SCRATCH_BUFFER_USE512M_PTES_ENABLED                        0x00000001
#define DXR_SCRATCH_BUFFER_USE512M_PTES_DEFAULT                        DXR_SCRATCH_BUFFER_USE512M_PTES_OFF


#define DXR_SHADER_IDENTIFIER_SIZE_STRING                              "42526270"
#define DXR_SHADER_IDENTIFIER_SIZE_ID                                  0x004cb4b1
#define DXR_SHADER_IDENTIFIER_SIZE_OVERINSTALL                         0 // OVERRIDE
#define DXR_SHADER_IDENTIFIER_SIZE_OS_DEFAULT                          0
#define DXR_SHADER_IDENTIFIER_SIZE_RS4_DEFAULT                         16
#define DXR_SHADER_IDENTIFIER_SIZE_RS5_DEFAULT                         32
#define DXR_SHADER_IDENTIFIER_SIZE_DEFAULT                             DXR_SHADER_IDENTIFIER_SIZE_OS_DEFAULT


#define DXR_TIER_OVERRIDE_STRING                                       "7c0601"
#define DXR_TIER_OVERRIDE_ID                                           0x008ee432
#define DXR_TIER_OVERRIDE_OVERINSTALL                                  0 // OVERRIDE
#define DXR_TIER_OVERRIDE_FORCE_TIER_DEFAULT                           0x00000000
#define DXR_TIER_OVERRIDE_FORCE_TIER_1_0                               0x00000001
#define DXR_TIER_OVERRIDE_FORCE_TIER_1_1                               0x00000002
#define DXR_TIER_OVERRIDE_DEFAULT                                      DXR_TIER_OVERRIDE_FORCE_TIER_DEFAULT


#define DXR_TTU_USAGE_STRING                                           "0x0e3595"
#define DXR_TTU_USAGE_ID                                               0x000e3595
#define DXR_TTU_USAGE_OVERINSTALL                                      0 // OVERRIDE
#define DXR_TTU_USAGE_OFF                                              0
#define DXR_TTU_USAGE_DISABLED                                         0
#define DXR_TTU_USAGE_DONOTUSETTU                                      0
#define DXR_TTU_USAGE_ON                                               1
#define DXR_TTU_USAGE_ENABLED                                          1
#define DXR_TTU_USAGE_USETTU                                           1
#define DXR_TTU_USAGE_DEFAULT                                          DXR_TTU_USAGE_ON


#define DXR_USE_FAST_LINKING_STRING                                    "0x50a155"
#define DXR_USE_FAST_LINKING_ID                                        0x0050a155
#define DXR_USE_FAST_LINKING_OVERINSTALL                               0 // OVERRIDE
#define DXR_USE_FAST_LINKING_OFF                                       0x00000000
#define DXR_USE_FAST_LINKING_0                                         0x00000000
#define DXR_USE_FAST_LINKING_FALSE                                     0x00000000
#define DXR_USE_FAST_LINKING_DISABLED                                  0x00000000
#define DXR_USE_FAST_LINKING_ON                                        0x00000001
#define DXR_USE_FAST_LINKING_1                                         0x00000001
#define DXR_USE_FAST_LINKING_TRUE                                      0x00000001
#define DXR_USE_FAST_LINKING_ENABLED                                   0x00000001
#define DXR_USE_FAST_LINKING_DEFAULT                                   DXR_USE_FAST_LINKING_ON


#define ENABLE24BITCOLORSURFACE_STRING                                 "69109028"
#define ENABLE24BITCOLORSURFACE_ID                                     0x00ddc9b7
#define ENABLE24BITCOLORSURFACE_OVERINSTALL                            0 // OVERRIDE
#define ENABLE24BITCOLORSURFACE_OFF                                    0x00000000
#define ENABLE24BITCOLORSURFACE_0                                      0x00000000
#define ENABLE24BITCOLORSURFACE_FALSE                                  0x00000000
#define ENABLE24BITCOLORSURFACE_DISABLED                               0x00000000
#define ENABLE24BITCOLORSURFACE_ON                                     0x00000001
#define ENABLE24BITCOLORSURFACE_1                                      0x00000001
#define ENABLE24BITCOLORSURFACE_TRUE                                   0x00000001
#define ENABLE24BITCOLORSURFACE_ENABLED                                0x00000001
#define ENABLE24BITCOLORSURFACE_DISABLE_AA_PROMOTION                   0x00000002
#define ENABLE24BITCOLORSURFACE_DEFAULT                                ENABLE24BITCOLORSURFACE_ON


#define ENABLE24BITZSURFACE_STRING                                     "69109017"
#define ENABLE24BITZSURFACE_ID                                         0x004f737f
#define ENABLE24BITZSURFACE_OVERINSTALL                                0 // OVERRIDE
#define ENABLE24BITZSURFACE_OFF                                        0x00000000
#define ENABLE24BITZSURFACE_DISABLED                                   0x00000000
#define ENABLE24BITZSURFACE_ON                                         0x00000001
#define ENABLE24BITZSURFACE_ENABLED                                    0x00000001
#define ENABLE24BITZSURFACE_DEFAULT                                    ENABLE24BITZSURFACE_OFF


#define ENABLEBASICPRIME_STRING                                        "46201342"
#define ENABLEBASICPRIME_ID                                            0x00558299
#define ENABLEBASICPRIME_OVERINSTALL                                   0 // OVERRIDE
#define ENABLEBASICPRIME_OFF                                           0xf6712345
#define ENABLEBASICPRIME_DISABLED                                      0xf6712345
#define ENABLEBASICPRIME_ON                                            0x18223234
#define ENABLEBASICPRIME_ENABLED                                       0x18223234
#define ENABLEBASICPRIME_DEFAULT                                       ENABLEBASICPRIME_ON


#define ENABLECENTROID_STRING                                          "62145389"
#define ENABLECENTROID_ID                                              0x00d1e2f5
#define ENABLECENTROID_OVERINSTALL                                     0 // OVERRIDE
#define ENABLECENTROID_OFF                                             0x08416720
#define ENABLECENTROID_FALSE                                           0x08416720
#define ENABLECENTROID_0                                               0x08416720
#define ENABLECENTROID_ON                                              0x60925212
#define ENABLECENTROID_TRUE                                            0x60925212
#define ENABLECENTROID_1                                               0x60925212
#define ENABLECENTROID_COMPLETE                                        0x47814150
#define ENABLECENTROID_ALWAYS                                          0x47814150
#define ENABLECENTROID_DEFAULT                                         ENABLECENTROID_ON


#define ENABLEFPTEXTURES_STRING                                        "75409218"
#define ENABLEFPTEXTURES_ID                                            0x00791ffa
#define ENABLEFPTEXTURES_OVERINSTALL                                   0 // OVERRIDE
#define ENABLEFPTEXTURES_OFF                                           0x68004831
#define ENABLEFPTEXTURES_DISABLED                                      0x68004831
#define ENABLEFPTEXTURES_ON                                            0x12850732
#define ENABLEFPTEXTURES_ENABLED                                       0x12850732
#define ENABLEFPTEXTURES_DEFAULT                                       ENABLEFPTEXTURES_OFF


#define ENABLEHDRRENDERTARGETS_STRING                                  "95739038"
#define ENABLEHDRRENDERTARGETS_ID                                      0x00c4cdbf
#define ENABLEHDRRENDERTARGETS_OVERINSTALL                             0 // OVERRIDE
#define ENABLEHDRRENDERTARGETS_FP16ARGB                                0x00000001
#define ENABLEHDRRENDERTARGETS_FP32ARGB                                0x00000002
#define ENABLEHDRRENDERTARGETS_ARGB10                                  0x00000004
#define ENABLEHDRRENDERTARGETS_GT16RG                                  0x00000008
#define ENABLEHDRRENDERTARGETS_ARGB16                                  0x00000010
#define ENABLEHDRRENDERTARGETS_MASK                                    0x0000001F


#define ENABLENULLTEXTURE_STRING                                       "EnableNullTexture"
#define ENABLENULLTEXTURE_ID                                           0x00291e3f
#define ENABLENULLTEXTURE_OVERINSTALL                                  0 // OVERRIDE
#define ENABLENULLTEXTURE_DEFAULT                                      0x00000000
#define ENABLENULLTEXTURE_TEXNULL1x1                                   0x00000001
#define ENABLENULLTEXTURE_TEXNULLALL                                   0x00000002


#define ENABLESPOOF_STRING                                             "23994875"
#define ENABLESPOOF_ID                                                 0x008cbf73
#define ENABLESPOOF_OVERINSTALL                                        0 // OVERRIDE
#define ENABLESPOOF_OFF                                                0x37742112
#define ENABLESPOOF_DISABLED                                           0x37742112
#define ENABLESPOOF_ON                                                 0x26648311
#define ENABLESPOOF_ENABLED                                            0x26648311
#define ENABLESPOOF_DEFAULT                                            ENABLESPOOF_OFF


#define ENABLESURFACEDUMP_STRING                                       "39031461"
#define ENABLESURFACEDUMP_ID                                           0x00637ffe
#define ENABLESURFACEDUMP_OVERINSTALL                                  0 // OVERRIDE
#define ENABLESURFACEDUMP_DEFAULT                                      0x00000000
#define ENABLESURFACEDUMP_DUMP_RT                                      0x00000001
#define ENABLESURFACEDUMP_DUMP_ZB                                      0x00000002
#define ENABLESURFACEDUMP_DUMP_PD                                      0x00000004
#define ENABLESURFACEDUMP_DUMP_PP                                      0x00000008
#define ENABLESURFACEDUMP_DUMP_DDS                                     0x00000010


#define ENABLE_CBC_COMPRESSION_HEURISTICS_STRING                       "6f01fa31"
#define ENABLE_CBC_COMPRESSION_HEURISTICS_ID                           0x006216fe
#define ENABLE_CBC_COMPRESSION_HEURISTICS_OVERINSTALL                  0 // OVERRIDE
#define ENABLE_CBC_COMPRESSION_HEURISTICS_OFF                          0x99388100
#define ENABLE_CBC_COMPRESSION_HEURISTICS_DISABLED                     0x99388100
#define ENABLE_CBC_COMPRESSION_HEURISTICS_ON                           0x25558997
#define ENABLE_CBC_COMPRESSION_HEURISTICS_ENABLED                      0x25558997
#define ENABLE_CBC_COMPRESSION_HEURISTICS_DEFAULT                      ENABLE_CBC_COMPRESSION_HEURISTICS_ON


#define ENABLE_COMPRESS_ON_BIND_STRING                                 "54fac9"
#define ENABLE_COMPRESS_ON_BIND_ID                                     0x0054fac9
#define ENABLE_COMPRESS_ON_BIND_OVERINSTALL                            0 // OVERRIDE
#define ENABLE_COMPRESS_ON_BIND_OFF                                    0x0
#define ENABLE_COMPRESS_ON_BIND_DISABLED                               0x0
#define ENABLE_COMPRESS_ON_BIND_ON                                     0x1
#define ENABLE_COMPRESS_ON_BIND_ENABLED                                0x1


#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_STRING           "F42AD6"
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_ID               0x00f42ad6
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_OVERINSTALL      0 // OVERRIDE
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_DISABLED         0
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_OFF              0
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_ENABLED          1
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_ON               1
#define ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_DEFAULT          ENABLE_COMPUTEMME_BACKINGSTORE_CLEAR_ONCREATE_ENABLED


#define ENABLE_DSC_AS_DEFAULT_BLITTER_STRING                           "4f887779"
#define ENABLE_DSC_AS_DEFAULT_BLITTER_ID                               0x006da690
#define ENABLE_DSC_AS_DEFAULT_BLITTER_OVERINSTALL                      0 // OVERRIDE
#define ENABLE_DSC_AS_DEFAULT_BLITTER_DISABLE                          0x00000000
#define ENABLE_DSC_AS_DEFAULT_BLITTER_ENABLE_ONLY_FOR_AMPERE           0x00000001
#define ENABLE_DSC_AS_DEFAULT_BLITTER_ENABLE_FOR_ALL_GPUS              0x00000002
#define ENABLE_DSC_AS_DEFAULT_BLITTER_ENABLE_FOR_ALL_COPIES_ON_ASYNC_QUEUES 0x00000004
#define ENABLE_DSC_AS_DEFAULT_BLITTER_DEFAULT                          ENABLE_DSC_AS_DEFAULT_BLITTER_DISABLE


#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_STRING                     "4f886846"
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_ID                         0x006da666
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_OVERINSTALL                0 // OVERRIDE
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_OFF                        0x00000000
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_DISABLED                   0x00000000
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_ON                         0x00000001
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_ENABLED                    0x00000001
#define ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_DEFAULT                    ENABLE_GLOBAL_PITCH_BUFFER_COPY_DSC_ON


#define ENABLE_GTX950_SPECIFIC_FEATURES_STRING                         "90572899"
#define ENABLE_GTX950_SPECIFIC_FEATURES_ID                             0x00041807
#define ENABLE_GTX950_SPECIFIC_FEATURES_OVERINSTALL                    0 // OVERRIDE
#define ENABLE_GTX950_SPECIFIC_FEATURES_DISALLOWED                     0
#define ENABLE_GTX950_SPECIFIC_FEATURES_OFF                            0
#define ENABLE_GTX950_SPECIFIC_FEATURES_DISABLED                       0
#define ENABLE_GTX950_SPECIFIC_FEATURES_ALLOWED                        1
#define ENABLE_GTX950_SPECIFIC_FEATURES_ON                             1
#define ENABLE_GTX950_SPECIFIC_FEATURES_ENABLED                        1
#define ENABLE_GTX950_SPECIFIC_FEATURES_DEFAULT                        ENABLE_GTX950_SPECIFIC_FEATURES_DISALLOWED


#define ENABLE_LZ_COPY_STRING                                          "32789544"
#define ENABLE_LZ_COPY_ID                                              0x00deef0d
#define ENABLE_LZ_COPY_OVERINSTALL                                     0 // OVERRIDE
#define ENABLE_LZ_COPY_LZ_COPY_DISABLED                                0x00000000
#define ENABLE_LZ_COPY_LZ_COPY_ENABLED                                 0x00000001
#define ENABLE_LZ_COPY_LZ_COPY_FORCED                                  0x00000002
#define ENABLE_LZ_COPY_DEFAULT                                         ENABLE_LZ_COPY_LZ_COPY_DISABLED


#define ENABLE_MEMORYINDICATOR_STRING                                  "54118411"
#define ENABLE_MEMORYINDICATOR_ID                                      0x00e67302
#define ENABLE_MEMORYINDICATOR_OVERINSTALL                             0 // OVERRIDE
#define ENABLE_MEMORYINDICATOR_OFF                                     0x54889adf
#define ENABLE_MEMORYINDICATOR_DISABLED                                0x54889adf
#define ENABLE_MEMORYINDICATOR_ON                                      0x237b4805
#define ENABLE_MEMORYINDICATOR_ENABLED                                 0x237b4805
#define ENABLE_MEMORYINDICATOR_DEFAULT                                 ENABLE_MEMORYINDICATOR_OFF


#define ENABLE_MEMORY_LEAK_STACKS_STRING                               "91240523"
#define ENABLE_MEMORY_LEAK_STACKS_ID                                   0x001d744b
#define ENABLE_MEMORY_LEAK_STACKS_OVERINSTALL                          0 // OVERRIDE
#define ENABLE_MEMORY_LEAK_STACKS_OFF                                  0x00000000
#define ENABLE_MEMORY_LEAK_STACKS_DISABLED                             0x00000000
#define ENABLE_MEMORY_LEAK_STACKS_ON                                   0x00000001
#define ENABLE_MEMORY_LEAK_STACKS_ENABLED                              0x00000001
#define ENABLE_MEMORY_LEAK_STACKS_DEFAULT                              ENABLE_MEMORY_LEAK_STACKS_OFF


#define ENABLE_PRI_WRITES_STRING                                       "0x70b3ca"
#define ENABLE_PRI_WRITES_ID                                           0x0070b3ca
#define ENABLE_PRI_WRITES_OVERINSTALL                                  0 // OVERRIDE
#define ENABLE_PRI_WRITES_OFF                                          0x0
#define ENABLE_PRI_WRITES_DISABLED                                     0x0
#define ENABLE_PRI_WRITES_ON                                           0x1
#define ENABLE_PRI_WRITES_ENABLED                                      0x1
#define ENABLE_PRI_WRITES_DEFAULT                                      ENABLE_PRI_WRITES_ON


#define ENABLE_QUIET_PREFETCH_STRING                                   "D19DDB97"
#define ENABLE_QUIET_PREFETCH_ID                                       0x00f1ba3a
#define ENABLE_QUIET_PREFETCH_OVERINSTALL                              0 // OVERRIDE
#define ENABLE_QUIET_PREFETCH_OFF                                      0xa2b53761
#define ENABLE_QUIET_PREFETCH_DISABLED                                 0xa2b53761
#define ENABLE_QUIET_PREFETCH_ON                                       0x79292610
#define ENABLE_QUIET_PREFETCH_ENABLED                                  0x79292610
#define ENABLE_QUIET_PREFETCH_DEFAULT                                  ENABLE_QUIET_PREFETCH_ON


#define ENABLE_RESOURCEHEAP_TIER2_STRING                               "0xacbcc0"
#define ENABLE_RESOURCEHEAP_TIER2_ID                                   0x00acbcc0
#define ENABLE_RESOURCEHEAP_TIER2_OVERINSTALL                          0 // OVERRIDE
#define ENABLE_RESOURCEHEAP_TIER2_OFF                                  0x0
#define ENABLE_RESOURCEHEAP_TIER2_DISABLED                             0x0
#define ENABLE_RESOURCEHEAP_TIER2_ON                                   0x1
#define ENABLE_RESOURCEHEAP_TIER2_ENABLED                              0x1
#define ENABLE_RESOURCEHEAP_TIER2_DEFAULT                              ENABLE_RESOURCEHEAP_TIER2_ON


#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_STRING                  "19328903"
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_ID                      0x0034f013
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_OVERINSTALL             0 // OVERRIDE
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_OFF                     0x00000000
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_DISABLED                0x00000000
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_ON                      0x00000001
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_ENABLED                 0x00000001
#define ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_DEFAULT                 ENABLE_SHADER_LOCAL_MEMORY_COMPRESSION_OFF


#define ENABLE_SM_COLLECTOR_HWBUG_2099239_STRING                       "0x96C1D1"
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_ID                           0x0096c1d1
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_OVERINSTALL                  0 // OVERRIDE
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_OFF                          0
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_DISABLED                     0
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_ON                           1
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_ENABLED                      1
#define ENABLE_SM_COLLECTOR_HWBUG_2099239_DEFAULT                      ENABLE_SM_COLLECTOR_HWBUG_2099239_ON


#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_STRING                       "0xfcecb0"
#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_ID                           0x00fcacb0
#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_OVERINSTALL                  0 // OVERRIDE
#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_DISABLE_PIPELINED_COPY       0x00000000
#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_ENABLE_PIPELINED_COPY        0x00000001
#define ENABLE_SYNC_CE_PIPELINED_DMA_COPY_DEFAULT                      ENABLE_SYNC_CE_PIPELINED_DMA_COPY_DISABLE_PIPELINED_COPY


#define ENABLE_TRC_WITH_GENERIC_MEMORY_STRING                          "0x9daed0"
#define ENABLE_TRC_WITH_GENERIC_MEMORY_ID                              0x009daed0
#define ENABLE_TRC_WITH_GENERIC_MEMORY_OVERINSTALL                     0 // OVERRIDE
#define ENABLE_TRC_WITH_GENERIC_MEMORY_OFF                             0x0
#define ENABLE_TRC_WITH_GENERIC_MEMORY_DISABLED                        0x0
#define ENABLE_TRC_WITH_GENERIC_MEMORY_ON                              0x1
#define ENABLE_TRC_WITH_GENERIC_MEMORY_ENABLED                         0x1
#define ENABLE_TRC_WITH_GENERIC_MEMORY_DEFAULT                         ENABLE_TRC_WITH_GENERIC_MEMORY_ON


#define ENABLE_TWOD_STRING                                             "5e975755"
#define ENABLE_TWOD_ID                                                 0x005e9757
#define ENABLE_TWOD_OVERINSTALL                                        0 // OVERRIDE
#define ENABLE_TWOD_OFF                                                0x00000000
#define ENABLE_TWOD_DISABLED                                           0x00000000
#define ENABLE_TWOD_ON                                                 0x00000001
#define ENABLE_TWOD_ENABLED                                            0x00000001
#define ENABLE_TWOD_DEFAULT                                            0x1


#define ENABLE_UMD_MANAGED_GPFIFO_STRING                               "fab419"
#define ENABLE_UMD_MANAGED_GPFIFO_ID                                   0x00fab419
#define ENABLE_UMD_MANAGED_GPFIFO_OVERINSTALL                          0 // OVERRIDE
#define ENABLE_UMD_MANAGED_GPFIFO_OFF                                  0
#define ENABLE_UMD_MANAGED_GPFIFO_DISABLED                             0
#define ENABLE_UMD_MANAGED_GPFIFO_ON                                   1
#define ENABLE_UMD_MANAGED_GPFIFO_ENABLED                              1
#define ENABLE_UMD_MANAGED_GPFIFO_DEFAULT                              ENABLE_UMD_MANAGED_GPFIFO_OFF


#define ENABLE_UMD_MANAGED_GPFIFO_DX9_STRING                           "fab519"
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_ID                               0x00fab519
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_OVERINSTALL                      0 // OVERRIDE
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_OFF                              0
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_DISABLED                         0
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_ON                               1
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_ENABLED                          1
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_DEFAULT                          ENABLE_UMD_MANAGED_GPFIFO_DX9_OFF


#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_STRING                       "fab528"
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_ID                           0x00fab528
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_OVERINSTALL                  0 // OVERRIDE
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_OFF                          0
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_DISABLED                     0
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_ON                           1
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_ENABLED                      1
#define ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_DEFAULT                      ENABLE_UMD_MANAGED_GPFIFO_DX9_SLI_OFF


#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_STRING            "0x06C0B0"
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_ID                0x00f7b1a1
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_OVERINSTALL       0 // OVERRIDE
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_OFF               0
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_DISABLED          0
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_ON                1
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_ENABLED           1
#define ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_DEFAULT           ENABLE_VOLTA_RVCH_INVALIDATE_WAR_BUG_1922829_ON


#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_STRING         "0xE231DC"
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_ID             0x00e231dc
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_OVERINSTALL    0 // OVERRIDE
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_OFF            0
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_DISABLED       0
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_ON             1
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_ENABLED        1
#define ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_DEFAULT        ENABLE_VOLTA_SCC_PAGEPOOL_ALLOC_OPT_BUG_1886508_ON


#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_STRING                       "0x035422"
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_ID                           0x00035422
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_OVERINSTALL                  0 // OVERRIDE
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_OFF                          0
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_DISABLED                     0
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_ON                           1
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_ENABLED                      1
#define ENABLE_VPRTARRAYINDEX_FROM_SHADER_DEFAULT                      ENABLE_VPRTARRAYINDEX_FROM_SHADER_OFF


#define ENABLE_Z16_COMPRESSION_STRING                                  "0x07ad1b"
#define ENABLE_Z16_COMPRESSION_ID                                      0x0007ad1b
#define ENABLE_Z16_COMPRESSION_OVERINSTALL                             0 // OVERRIDE
#define ENABLE_Z16_COMPRESSION_OFF                                     0x0
#define ENABLE_Z16_COMPRESSION_DISABLED                                0x0
#define ENABLE_Z16_COMPRESSION_ON                                      0x1
#define ENABLE_Z16_COMPRESSION_ENABLED                                 0x1
#define ENABLE_Z16_COMPRESSION_DEFAULT                                 ENABLE_Z16_COMPRESSION_OFF


#define ENABLE_ZERO_COVERAGE_KIL_STRING                                "4604c0"
#define ENABLE_ZERO_COVERAGE_KIL_ID                                    0x004604c0
#define ENABLE_ZERO_COVERAGE_KIL_OVERINSTALL                           0 // OVERRIDE
#define ENABLE_ZERO_COVERAGE_KIL_OFF                                   0x00000000
#define ENABLE_ZERO_COVERAGE_KIL_ON                                    0x00000001


#define ESTIMATE_ANIMATION_TIME_STRING                                 "B5270432"
#define ESTIMATE_ANIMATION_TIME_ID                                     0x00b75344
#define ESTIMATE_ANIMATION_TIME_OVERINSTALL                            0 // OVERRIDE
#define ESTIMATE_ANIMATION_TIME_DISABLED                               0x00000000
#define ESTIMATE_ANIMATION_TIME_ENABLED_SIMPLE                         0x00000001
#define ESTIMATE_ANIMATION_TIME_CAP_MS_MASK                            0x00003ff0
#define ESTIMATE_ANIMATION_TIME_CAP_MS_SHIFT                           4
#define ESTIMATE_ANIMATION_TIME_LAG_FRAMES_MASK                        0x0000c000
#define ESTIMATE_ANIMATION_TIME_LAG_FRAMES_SHIFT                       14
#define ESTIMATE_ANIMATION_TIME_LAG_FRAMES_MAX                         3
#define ESTIMATE_ANIMATION_TIME_TEST_20FRAMES_MASK                     0x0f000000
#define ESTIMATE_ANIMATION_TIME_TEST_20FRAMES_SHIFT                    24
#define ESTIMATE_ANIMATION_TIME_TEST_VAL_10MS_MASK                     0xf0000000
#define ESTIMATE_ANIMATION_TIME_TEST_VAL_10MS_SHIFT                    28
#define ESTIMATE_ANIMATION_TIME_MASK                                   0xff00fff1
#define ESTIMATE_ANIMATION_TIME_DEFAULT                                ESTIMATE_ANIMATION_TIME_DISABLED


#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_STRING                   "95226c4d"
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ID                       0x00953b21
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_OVERINSTALL              0 // OVERRIDE
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_DISABLED                 0x00000000
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_MEMORY_USAGE_EVENTS 0x00000001
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_MISC_ALLOC_EVENTS 0x00000002
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_MISC_REUSE_EVENTS 0x00000004
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_PERFSTRAT_ALLOC_EVENTS 0x00000008
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_PERFSTRAT_REUSE_EVENTS 0x00000010
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_DXR_LAUNCH_BUFFER_ALLOC_EVENTS 0x00000020
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_DXR_LAUNCH_BUFFER_REUSE_EVENTS 0x00000040
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_LMEM_ALLOC_EVENTS 0x00000100
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_ENABLE_SHADER_HEAP_ALLOC_EVENTS 0x00000200
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_TRACK_BVH_ALLOCATIONS    0x00001000
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_TRACK_BVH_SCRATCH_ALLOCATIONS 0x00002000
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_TRACK_COMMAND_MEMORY_USAGE 0x00004000
#define ETW_WGF2UM_COMMAND_MEMORY_USAGE_FLAGS_DEFAULT                  0x00000000


#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STRING                         "46114f3e"
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_ID                             0x007e8ac1
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_MISCSTRING                     0x0000000000000001
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_HOTKEY                         0x0000000000000002
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_DEVICE                         0x0000000000000004
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_ENTRYPOINT                     0x0000000000000008
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_SYNC                           0x0000000000000010
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_SLITRANSFER                    0x0000000000000020
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_QUERY                          0x0000000000000040
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_LOADBALANCE                    0x0000000000000080
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_FRAME             0x0000000000000100
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_BLOCKCREATE       0x0000000000000200
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_BLOCKDESTROY      0x0000000000000400
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_BLOCKPURGE        0x0000000000000800
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_SHADERCOMPILE     0x0000000000001000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_GPUSTALL          0x0000000000002000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_OUTOFORDER        0x0000000000004000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_UPDATESUBRESOURCE 0x0000000000008000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_STUTTERSTATS_SHADERCOMPILETIME 0x0000000000010000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_FBC                            0x0000000000020000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_GENERICEVENT                   0x0000000000040000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_LOADBALANCE_MASTER             0x0000000000080000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_TIMER_RESOLUTION    0x0000000000100000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_SYNC_MAP            0x0000000000200000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_RENAME_STALL        0x0000000000400000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_THREAD_AFFINITY     0x0000000000800000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_ASYNC_COMPILE_DISABLED 0x0000000001000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_SYNC_UNMAP          0x0000000002000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_STALLED_ASYNC_COMPILE 0x0000000004000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_SYNC_COMPILE        0x0000000008000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BLACK_FLAG_SERVER_CLIENT_AFFINITY 0x0000000010000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_SLI_STALL_TIMES                0x0000000020000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_COMMAND_MEMORY_USAGE           0x0000000080000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_COMMAND_MEMORY_ALLOC           0x0000000100000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_ASYNCJOB                       0x0000000200000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_LATENCY_MARKER                 0x0000000400000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_BAR1_MAP_UNMAP                 0x0000000800000000
#define ETW_WGF2UM_EXTERNAL_EVENT_FLAGS_DEFAULT                        0


#define ETW_WGF2UM_TRACE_DWM_STRING                                    "15b644bb"
#define ETW_WGF2UM_TRACE_DWM_ID                                        0x008a79bb
#define ETW_WGF2UM_TRACE_DWM_OVERINSTALL                               0 // OVERRIDE
#define ETW_WGF2UM_TRACE_DWM_OFF                                       0x48fe9bfa
#define ETW_WGF2UM_TRACE_DWM_DISABLED                                  0x48fe9bfa
#define ETW_WGF2UM_TRACE_DWM_ON                                        0xe79c3a12
#define ETW_WGF2UM_TRACE_DWM_ENABLED                                   0xe79c3a12
#define ETW_WGF2UM_TRACE_DWM_DEFAULT                                   ETW_WGF2UM_TRACE_DWM_OFF


#define ETW_WGF2UM_TRACE_INTERNAL_STRING                               "15b644aa"
#define ETW_WGF2UM_TRACE_INTERNAL_ID                                   0x008a79ea
#define ETW_WGF2UM_TRACE_INTERNAL_OVERINSTALL                          0 // OVERRIDE
#define ETW_WGF2UM_TRACE_INTERNAL_OFF                                  0x48fe9bfa
#define ETW_WGF2UM_TRACE_INTERNAL_DISABLED                             0x48fe9bfa
#define ETW_WGF2UM_TRACE_INTERNAL_ON                                   0xe79c3a12
#define ETW_WGF2UM_TRACE_INTERNAL_ENABLED                              0xe79c3a12
#define ETW_WGF2UM_TRACE_INTERNAL_DEFAULT                              ETW_WGF2UM_TRACE_INTERNAL_OFF


#define EXPORT_PERF_COUNTERS_DX9_ONLY_STRING                           "75b3c21d"
#define EXPORT_PERF_COUNTERS_DX9_ONLY_ID                               0x00b65e72
#define EXPORT_PERF_COUNTERS_DX9_ONLY_OVERINSTALL                      1 // MERGE
#define EXPORT_PERF_COUNTERS_DX9_ONLY_OFF                              0x00000000
#define EXPORT_PERF_COUNTERS_DX9_ONLY_DISABLED                         0x00000000
#define EXPORT_PERF_COUNTERS_DX9_ONLY_ON                               0x00000001
#define EXPORT_PERF_COUNTERS_DX9_ONLY_ENABLED                          0x00000001
#define EXPORT_PERF_COUNTERS_DX9_ONLY_DEFAULT                          EXPORT_PERF_COUNTERS_DX9_ONLY_OFF


#define FATTEXOPTIMIZATION_STRING                                      "86739657"
#define FATTEXOPTIMIZATION_ID                                          0x00df2ad7
#define FATTEXOPTIMIZATION_OVERINSTALL                                 0 // OVERRIDE
#define FATTEXOPTIMIZATION_PARTIAL                                     0x78347691
#define FATTEXOPTIMIZATION_0                                           0x78347691
#define FATTEXOPTIMIZATION_HEURISTIC                                   0x94837562
#define FATTEXOPTIMIZATION_1                                           0x94837562
#define FATTEXOPTIMIZATION_FULL                                        0x49683103
#define FATTEXOPTIMIZATION_2                                           0x49683103
#define FATTEXOPTIMIZATION_DEFAULT                                     FATTEXOPTIMIZATION_HEURISTIC


#define FERMI_SETCOMPRESSIONTHRESHOLD_STRING                           "e433456d"
#define FERMI_SETCOMPRESSIONTHRESHOLD_ID                               0x008fe12e
#define FERMI_SETCOMPRESSIONTHRESHOLD_OVERINSTALL                      0 // OVERRIDE
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__0                       0x0
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__1                       0x1
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__2                       0x2
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__4                       0x3
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__8                       0x4
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__16                      0x5
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__32                      0x6
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__64                      0x7
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__128                     0x8
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__256                     0x9
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__512                     0xa
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__1024                    0xb
#define FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__2048                    0xc
#define FERMI_SETCOMPRESSIONTHRESHOLD_DEFAULT                          FERMI_SETCOMPRESSIONTHRESHOLD_SAMPLES__8


#define FERMI_SETMAXTIWARPSPERBATCH_STRING                             "fbf4ac45"
#define FERMI_SETMAXTIWARPSPERBATCH_ID                                 0x00b6cf0d
#define FERMI_SETMAXTIWARPSPERBATCH_OVERINSTALL                        0 // OVERRIDE


#define FERMI_SETPSREGISTERWATERMARKS_STRING                           "beefcba4"
#define FERMI_SETPSREGISTERWATERMARKS_ID                               0x00784f2e
#define FERMI_SETPSREGISTERWATERMARKS_OVERINSTALL                      0 // OVERRIDE
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_MAXWELL                  0x08000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_PASCAL_A                 0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_PASCAL_B                 0x08000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_VOLTA_A                  0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_TURING_A                 0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_AMPERE_A                 0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_AMPERE_B                 0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_ADA_A                    0x10000080
#define FERMI_SETPSREGISTERWATERMARKS_DEFAULT_HOPPER_A                 0x10000080


#define FERMI_SETPSWARPWATERMARKS_STRING                               "beefcba3"
#define FERMI_SETPSWARPWATERMARKS_ID                                   0x0075db88
#define FERMI_SETPSWARPWATERMARKS_OVERINSTALL                          0 // OVERRIDE
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_MAXWELL                      0x00400008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_PASCAL_A                     0x00800008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_PASCAL_B                     0x00400008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_VOLTA_A                      0x00800008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_TURING_A                     0x00400008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_AMPERE_A                     0x00800008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_AMPERE_B                     0x00600008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_ADA_A                        0x00600008
#define FERMI_SETPSWARPWATERMARKS_DEFAULT_HOPPER_A                     0x00800008


#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_STRING                    "bab1fe41"
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_ID                        0x000858f7
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_OVERINSTALL               0 // OVERRIDE
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_OFF                       0x00000000
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_DISABLED                  0x00000000
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_ON                        0x00000001
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_ENABLED                   0x00000001
#define FERMI_SETREDUCECOLORTHRESHOLDSENABLE_DEFAULT                   FERMI_SETREDUCECOLORTHRESHOLDSENABLE_ON


#define FERMI_SETSUBTILINGPERFKNOBA_STRING                             "a3456abe"
#define FERMI_SETSUBTILINGPERFKNOBA_ID                                 0x00e86028
#define FERMI_SETSUBTILINGPERFKNOBA_OVERINSTALL                        0 // OVERRIDE
#define FERMI_SETSUBTILINGPERFKNOBA_GM20Y_DEFAULT                      0x087F6080
#define FERMI_SETSUBTILINGPERFKNOBA_DEFAULT                            0x20164010


#define FERMI_SETSUBTILINGPERFKNOBA_WARPS_PER_SUBTILE_STRING           "a3456515"
#define FERMI_SETSUBTILINGPERFKNOBA_WARPS_PER_SUBTILE_ID               0x00e86515
#define FERMI_SETSUBTILINGPERFKNOBA_WARPS_PER_SUBTILE_OVERINSTALL      0 // OVERRIDE
#define FERMI_SETSUBTILINGPERFKNOBA_WARPS_PER_SUBTILE_DEFAULT          0x8


#define FERMI_SETSUBTILINGPERFKNOBB_STRING                             "fa345cce"
#define FERMI_SETSUBTILINGPERFKNOBB_ID                                 0x00d0bd9f
#define FERMI_SETSUBTILINGPERFKNOBB_OVERINSTALL                        0 // OVERRIDE
#define FERMI_SETSUBTILINGPERFKNOBB_DEFAULT                            0x20


#define FERMI_UNOPT_LOD_SPREAD_STRING                                  "3001ac"
#define FERMI_UNOPT_LOD_SPREAD_ID                                      0x003001ac
#define FERMI_UNOPT_LOD_SPREAD_OVERINSTALL                             0 // OVERRIDE
#define FERMI_UNOPT_LOD_SPREAD_OFF                                     0x56023627
#define FERMI_UNOPT_LOD_SPREAD_DISABLED                                0x56023627
#define FERMI_UNOPT_LOD_SPREAD_ON                                      0x37299934
#define FERMI_UNOPT_LOD_SPREAD_ENABLED                                 0x37299934
#define FERMI_UNOPT_LOD_SPREAD_DEFAULT                                 FERMI_UNOPT_LOD_SPREAD_OFF


#define FERMI_ZCULL_INFO_STRING                                        "ffaeaefe"
#define FERMI_ZCULL_INFO_ID                                            0x0054cf05
#define FERMI_ZCULL_INFO_OVERINSTALL                                   0 // OVERRIDE
#define FERMI_ZCULL_INFO_DISABLED                                      0x00000000
#define FERMI_ZCULL_INFO_TRACE                                         0x00000001
#define FERMI_ZCULL_INFO_STATS                                         0x00000002
#define FERMI_ZCULL_INFO_PER_DRAW_STATS                                0x00000004
#define FERMI_ZCULL_INFO_REGION_INFO                                   0x00000008
#define FERMI_ZCULL_INFO_DEFAULT                                       FERMI_ZCULL_INFO_DISABLED


#define FILL_STATIC_COLOR_TEXTURES_STRING                              "0xabcd14"
#define FILL_STATIC_COLOR_TEXTURES_ID                                  0x00abcd14
#define FILL_STATIC_COLOR_TEXTURES_OVERINSTALL                         0 // OVERRIDE
#define FILL_STATIC_COLOR_TEXTURES_OFF                                 0x00000000
#define FILL_STATIC_COLOR_TEXTURES_R_CHANNEL                           0x00000001
#define FILL_STATIC_COLOR_TEXTURES_G_CHANNEL                           0x00000002
#define FILL_STATIC_COLOR_TEXTURES_B_CHANNEL                           0x00000004
#define FILL_STATIC_COLOR_TEXTURES_A_CHANNEL                           0x00000008
#define FILL_STATIC_COLOR_TEXTURES_ALL                                 0x0000000f
#define FILL_STATIC_COLOR_TEXTURES_DEFAULT                             FILL_STATIC_COLOR_TEXTURES_OFF


#define FILL_STATIC_COLOR_TEXTURES_COLOR_STRING                        "0xabcd16"
#define FILL_STATIC_COLOR_TEXTURES_COLOR_ID                            0x00abcd16
#define FILL_STATIC_COLOR_TEXTURES_COLOR_OVERINSTALL                   0 // OVERRIDE
#define FILL_STATIC_COLOR_TEXTURES_COLOR_DEFAULT                       0xFFFF00FF


#define FILL_STATIC_COLOR_TEXTURES_MIP_STRING                          "0xabcd15"
#define FILL_STATIC_COLOR_TEXTURES_MIP_ID                              0x00abcd15
#define FILL_STATIC_COLOR_TEXTURES_MIP_OVERINSTALL                     0 // OVERRIDE
#define FILL_STATIC_COLOR_TEXTURES_MIP_OFF                             0x00000000
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_0                           0x00000001
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_1                           0x00000002
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_2                           0x00000004
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_3                           0x00000008
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_4                           0x00000010
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_5                           0x00000020
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_6                           0x00000040
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_7                           0x00000080
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_8                           0x00000100
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_9                           0x00000200
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_10                          0x00000400
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_11                          0x00000800
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_12                          0x00001000
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_13                          0x00002000
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_14                          0x00004000
#define FILL_STATIC_COLOR_TEXTURES_MIP_MIP_15                          0x00008000
#define FILL_STATIC_COLOR_TEXTURES_MIP_ALL                             0xFFFFFFFF
#define FILL_STATIC_COLOR_TEXTURES_MIP_DEFAULT                         FILL_STATIC_COLOR_TEXTURES_MIP_MIP_0


#define FLIPDATADUMP_STRING                                            "ae465921"
#define FLIPDATADUMP_ID                                                0x00215796
#define FLIPDATADUMP_OVERINSTALL                                       0 // OVERRIDE
#define FLIPDATADUMP_DISABLED                                          0x00000000
#define FLIPDATADUMP_OFF                                               0x00000000
#define FLIPDATADUMP_0                                                 0x00000000
#define FLIPDATADUMP_DUMP_SUMMARY                                      0x00000001
#define FLIPDATADUMP_DUMP_RAW_FLIP_DATA                                0x00000002
#define FLIPDATADUMP_DUMP_RAW_PRESENT_DATA                             0x00000004
#define FLIPDATADUMP_DUMP_RAW_PAGING_DATA                              0x00000008
#define FLIPDATADUMP_DUMP_RAW_PRESENT_END_DATA                         0x00000010
#define FLIPDATADUMP_DUMP_RAW_FLIP_LATENCY_DATA                        0x00000020
#define FLIPDATADUMP_DUMP_RAW_VRR_DELAY                                0x00000040
#define FLIPDATADUMP_DUMP_APP_ANIMATION_TIME                           0x00000080
#define FLIPDATADUMP_DUMP_RAW_PRESENT_START_TS                         0x00000100
#define FLIPDATADUMP_DUMP_RAW_PRESENT_END_TS                           0x00000200
#define FLIPDATADUMP_DUMP_RAW_FLIP_TS                                  0x00000400
#define FLIPDATADUMP_DUMP_FLIP_TOKEN                                   0x00000800
#define FLIPDATADUMP_DUMP_RAW_APP_PRESENT_START_TS                     0x00001000
#define FLIPDATADUMP_DUMP_RAW_APP_PRESENT_END_TS                       0x00002000
#define FLIPDATADUMP_DUMP_QUEUED_FRAMES                                0x00004000
#define FLIPDATADUMP_DUMP_GPU_UTILIZATION                              0x00008000
#define FLIPDATADUMP_DUMP_FLIP_METERING_DATA                           0x00010000
#define FLIPDATADUMP_DUMP_UMDMETER_DATA                                0x00020000
#define FLIPDATADUMP_DUMP_VIDEO_MEMORY_DATA                            0x00040000
#define FLIPDATADUMP_DUMP_GPC2_CLOCK_DATA                              0x00080000
#define FLIPDATADUMP_DUMP_RAW_TRANSFER_DATA                            0x00100000
#define FLIPDATADUMP_DUMP_MEM_CLOCK_DATA                               0x00200000
#define FLIPDATADUMP_DUMP_FRM_RENDER_TIME                              0x00400000
#define FLIPDATADUMP_DUMP_LOW_LATENCY                                  0x00800000
#define FLIPDATADUMP_HOTKEY_USING_FCAT                                 0x01000000
#define FLIPDATADUMP_DUMP_PRESENT_MODE                                 0x02000000
#define FLIPDATADUMP_DUMP_VRR_FLAGS                                    0x04000000
#define FLIPDATADUMP_DUMP_MPO_DATA                                     0x08000000
#define FLIPDATADUMP_ABSOLUTE_TS                                       0x10000000
#define FLIPDATADUMP_HOTKEY                                            0x20000000
#define FLIPDATADUMP_EXCEL_FRIENDLY                                    0x40000000
#define FLIPDATADUMP_AUTO_INCREMENT_FILENAME                           0x80000000
#define FLIPDATADUMP_MASK                                              0xFFFFFFFF
#define FLIPDATADUMP_DEFAULT                                           FLIPDATADUMP_DISABLED


#define FLIPDATADUMP_INTERVAL_STRING                                   "ae459628"
#define FLIPDATADUMP_INTERVAL_ID                                       0x00257796
#define FLIPDATADUMP_INTERVAL_OVERINSTALL                              0 // OVERRIDE
#define FLIPDATADUMP_INTERVAL_DEFAULT                                  0x00000000
#define FLIPDATADUMP_INTERVAL_BEGIN_MASK                               0xFFFF0000
#define FLIPDATADUMP_INTERVAL_END_MASK                                 0x0000FFFF
#define FLIPDATADUMP_INTERVAL_BEGIN_OFFSET                             0x00000010
#define FLIPDATADUMP_INTERVAL_END_OFFSET                               0x00000000


#define FLIPDATADUMP_PATH_STRING                                       "ae465922"
#define FLIPDATADUMP_PATH_ID                                           0x00215797
#define FLIPDATADUMP_PATH_OVERINSTALL                                  0 // OVERRIDE
#define FLIPDATADUMP_PATH_DEFAULT                                      0x00000000


#define FLIPDATADUMP_TRANSFER_THRESHOLD_STRING                         "ae465923"
#define FLIPDATADUMP_TRANSFER_THRESHOLD_ID                             0x00215798
#define FLIPDATADUMP_TRANSFER_THRESHOLD_OVERINSTALL                    0 // OVERRIDE
#define FLIPDATADUMP_TRANSFER_THRESHOLD_DEFAULT                        0x200000


#define FLIPINDICATOR_STRING                                           "dae37921"
#define FLIPINDICATOR_ID                                               0x002cf156
#define FLIPINDICATOR_OVERINSTALL                                      0 // OVERRIDE
#define FLIPINDICATOR_DISABLED                                         0x00000000
#define FLIPINDICATOR_OFF                                              0x00000000
#define FLIPINDICATOR_0                                                0x00000000
#define FLIPINDICATOR_GRAPH_FLIP_FPS                                   0x00000001
#define FLIPINDICATOR_GRAPH_PRESENT_FPS                                0x00000002
#define FLIPINDICATOR_GRAPH_APP_PRESENT_FPS                            0x00000004
#define FLIPINDICATOR_DISPLAY_PAGING                                   0x00000008
#define FLIPINDICATOR_DISPLAY_APP_THREAD_WAIT                          0x00000010
#define FLIPINDICATOR_DISPLAY_FULLSCREEN_FLIP_TEXT                     0x00000020
#define FLIPINDICATOR_DISPLAY_SLI_TRANSFERS                            0x00000040
#define FLIPINDICATOR_DISPLAY_VIDEO_MEMORY_DATA                        0x00000080
#define FLIPINDICATOR_GRAPH_PAGING_SIZE                                0x00000100
#define FLIPINDICATOR_GRAPH_GPC2_CLOCK                                 0x00000200
#define FLIPINDICATOR_GRAPH_MEM_CLOCK                                  0x00000400
#define FLIPINDICATOR_ENABLED                                          0x000007FF
#define FLIPINDICATOR_ON                                               0x000007FF
#define FLIPINDICATOR_1                                                0x000007FF
#define FLIPINDICATOR_MASK                                             0x000007FF
#define FLIPINDICATOR_DEFAULT                                          FLIPINDICATOR_DISABLED


#define FOGSUPPRESS_STRING                                             "28395567"
#define FOGSUPPRESS_ID                                                 0x00dfb772
#define FOGSUPPRESS_OVERINSTALL                                        0 // OVERRIDE
#define FOGSUPPRESS_OFF                                                0x82310097
#define FOGSUPPRESS_DISABLED                                           0x82310097
#define FOGSUPPRESS_ON                                                 0x18255321
#define FOGSUPPRESS_ENABLED                                            0x18255321
#define FOGSUPPRESS_DEFAULT                                            FOGSUPPRESS_OFF


#define FOGTABLEENABLE_STRING                                          "20466189"
#define FOGTABLEENABLE_ID                                              0x00631165
#define FOGTABLEENABLE_OVERINSTALL                                     0 // OVERRIDE
#define FOGTABLEENABLE_OFF                                             0x78176879
#define FOGTABLEENABLE_DISABLED                                        0x78176879
#define FOGTABLEENABLE_ON                                              0x31259154
#define FOGTABLEENABLE_ENABLED                                         0x31259154
#define FOGTABLEENABLE_DEFAULT                                         FOGTABLEENABLE_ON


#define FORCEBLITWAITFLAGENABLE_STRING                                 "22355415"
#define FORCEBLITWAITFLAGENABLE_ID                                     0x0032e3ae
#define FORCEBLITWAITFLAGENABLE_OVERINSTALL                            0 // OVERRIDE
#define FORCEBLITWAITFLAGENABLE_OFF                                    0x50131225
#define FORCEBLITWAITFLAGENABLE_DISABLED                               0x50131225
#define FORCEBLITWAITFLAGENABLE_ON                                     0x75006102
#define FORCEBLITWAITFLAGENABLE_ENABLED                                0x75006102
#define FORCEBLITWAITFLAGENABLE_DEFAULT                                FORCEBLITWAITFLAGENABLE_OFF


#define FORCEINLINEVERTEXDATA_STRING                                   "45328143"
#define FORCEINLINEVERTEXDATA_ID                                       0x004a5389
#define FORCEINLINEVERTEXDATA_OVERINSTALL                              0 // OVERRIDE
#define FORCEINLINEVERTEXDATA_OFF                                      0x00000000
#define FORCEINLINEVERTEXDATA_DISABLED                                 0x00000000
#define FORCEINLINEVERTEXDATA_ON                                       0x00000001
#define FORCEINLINEVERTEXDATA_ENABLED                                  0x00000001
#define FORCEINLINEVERTEXDATA_DEFAULT                                  FORCEINLINEVERTEXDATA_OFF


#define FORCEPSHADERPRECISION_STRING                                   "67481245"
#define FORCEPSHADERPRECISION_ID                                       0x00d10e2e
#define FORCEPSHADERPRECISION_OVERINSTALL                              0 // OVERRIDE
#define FORCEPSHADERPRECISION_NONE                                     0x78915466
#define FORCEPSHADERPRECISION_0                                        0x78915466
#define FORCEPSHADERPRECISION_FX9                                      0x21454235
#define FORCEPSHADERPRECISION_FX12                                     0x14174657
#define FORCEPSHADERPRECISION_FP16                                     0x84654446
#define FORCEPSHADERPRECISION_FP32                                     0x72546873
#define FORCEPSHADERPRECISION_DEFAULT                                  FORCEPSHADERPRECISION_NONE


#define FORCE_1X_TEX_STRING                                            "ba5fea03"
#define FORCE_1X_TEX_ID                                                0x00f865e3
#define FORCE_1X_TEX_OVERINSTALL                                       0 // OVERRIDE
#define FORCE_1X_TEX_DISABLED                                          0x00000000
#define FORCE_1X_TEX_ENABLED_3D                                        0x00000001
#define FORCE_1X_TEX_ENABLED_COMPUTE                                   0x00000002
#define FORCE_1X_TEX_DEFAULT                                           FORCE_1X_TEX_DISABLED


#define FORCE_GPUKERNEL_COP_ARCH_STRING                                "C09C09"
#define FORCE_GPUKERNEL_COP_ARCH_ID                                    0x00c09c09
#define FORCE_GPUKERNEL_COP_ARCH_OVERINSTALL                           0 // OVERRIDE
#define FORCE_GPUKERNEL_COP_ARCH_DEFAULT_GPU_KERNEL                    0
#define FORCE_GPUKERNEL_COP_ARCH_USE_AMPERE_SM8_2                      0x7001
#define FORCE_GPUKERNEL_COP_ARCH_USE_AMPERE_SM8_6                      0x7002
#define FORCE_GPUKERNEL_COP_ARCH_USE_ADA_SM8_9                         0x7005
#define FORCE_GPUKERNEL_COP_ARCH_USE_HOPPER_SM9_0                      0x8000
#define FORCE_GPUKERNEL_COP_ARCH_USE_HOPPER_SM9_0_TRIM                 0x80008000


#define FORCE_NVAPI_AFRGROUPS_DX10PLUS_STRING                          "71F71f77"
#define FORCE_NVAPI_AFRGROUPS_DX10PLUS_ID                              0x00f71f77
#define FORCE_NVAPI_AFRGROUPS_DX10PLUS_OVERINSTALL                     0 // OVERRIDE
#define FORCE_NVAPI_AFRGROUPS_DX10PLUS_DEFAULT                         0


#define FORCE_OPTIONAL_PSO_COMPILES_OFF_STRING                         "0xDC0E5"
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_ID                             0x000dc0e5
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_OVERINSTALL                    0 // OVERRIDE
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_OFF                            0x00000000
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_DISABLED                       0x00000000
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_ON                             0x00000001
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_ENABLED                        0x00000001
#define FORCE_OPTIONAL_PSO_COMPILES_OFF_DEFAULT                        FORCE_OPTIONAL_PSO_COMPILES_OFF_OFF


#define FORCE_SERIALIZE_DSC_UAV_CLEAR_STRING                           "0x1fff2f"
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_ID                               0x00a1131f
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_OVERINSTALL                      0 // OVERRIDE
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_OFF                              0
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_DISABLED                         0
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_ON                               1
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_ENABLED                          1
#define FORCE_SERIALIZE_DSC_UAV_CLEAR_DEFAULT                          FORCE_SERIALIZE_DSC_UAV_CLEAR_OFF


#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_STRING                        "deadfed0"
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_ID                            0x007812e3
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_OVERINSTALL                   0 // OVERRIDE
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_DISABLED                      0x00000000
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_ENABLED_3D                    0x00000001
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_ENABLED_COMPUTE               0x00000002
#define FORCE_TEX_HASH_BLOCK_VTG_COMPUTE_DEFAULT                       0x00000000


#define FORCE_UAV_OVERLAP_STRING                                       "0xa25f23"
#define FORCE_UAV_OVERLAP_ID                                           0x00a25f23
#define FORCE_UAV_OVERLAP_OVERINSTALL                                  0 // OVERRIDE
#define FORCE_UAV_OVERLAP_ENABLED                                      0x00000001
#define FORCE_UAV_OVERLAP_DISABLED                                     0
#define FORCE_UAV_OVERLAP_PS_TO_PS                                     0x00000002
#define FORCE_UAV_OVERLAP_CS_TO_CS                                     0x00000004
#define FORCE_UAV_OVERLAP_DEFAULT                                      FORCE_UAV_OVERLAP_DISABLED


#define FULLSCREEN_INDICATOR_ENABLE_STRING                             "280880"
#define FULLSCREEN_INDICATOR_ENABLE_ID                                 0x00280880
#define FULLSCREEN_INDICATOR_ENABLE_OVERINSTALL                        0 // OVERRIDE
#define FULLSCREEN_INDICATOR_ENABLE_OFF                                0x00000000
#define FULLSCREEN_INDICATOR_ENABLE_0                                  0x00000000
#define FULLSCREEN_INDICATOR_ENABLE_FALSE                              0x00000000
#define FULLSCREEN_INDICATOR_ENABLE_DISABLED                           0x00000000
#define FULLSCREEN_INDICATOR_ENABLE_ON                                 0x00000001
#define FULLSCREEN_INDICATOR_ENABLE_1                                  0x00000001
#define FULLSCREEN_INDICATOR_ENABLE_TRUE                               0x00000001
#define FULLSCREEN_INDICATOR_ENABLE_ENABLED                            0x00000001
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_FRAME_NUMBER                0x00000004
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_DWM_DFLIP                   0x00000008
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_DWM_ALL                     0x00000010
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_RESOLUTION                  0x00000020
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_TEARING_INFO                0x00000040
#define FULLSCREEN_INDICATOR_ENABLE_ENABLE_RR_INFO                     0x00000080
#define FULLSCREEN_INDICATOR_ENABLE_MASK                               0x000000FF
#define FULLSCREEN_INDICATOR_ENABLE_INFO_MASK                          0x000000E5
#define FULLSCREEN_INDICATOR_ENABLE_DEFAULT                            FULLSCREEN_INDICATOR_ENABLE_OFF


#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_STRING         "0x085231"
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_ID             0x00085231
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_OVERINSTALL    0 // OVERRIDE
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_OFF            0
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_DISABLED       0
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_ON             1
#define GP100_ENABLE_TESSELLATION_PERF_LOAD_BUG_1665952_ENABLED        1


#define GP100_NUM_TESS_PRF_EXCL_CYCLES_WAR_STRING                      "0x021423"
#define GP100_NUM_TESS_PRF_EXCL_CYCLES_WAR_ID                          0x00021423
#define GP100_NUM_TESS_PRF_EXCL_CYCLES_WAR_OVERINSTALL                 0 // OVERRIDE
#define GP100_NUM_TESS_PRF_EXCL_CYCLES_WAR_DEFAULT                     0x00000200


#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_STRING       "0x086142"
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_ID           0x00086142
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_OVERINSTALL  0 // OVERRIDE
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_OFF          0
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_DISABLED     0
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_ON           1
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_ENABLED      1
#define GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_DEFAULT      GP100_OPTIMIZE_TESSELLATION_PERF_LOAD_BUG_1665952_ON


#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_STRING                "0x120555"
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_ID                    0x00120555
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_OVERINSTALL           0 // OVERRIDE
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_OFF                   0
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_DISABLED              0
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_ON                    1
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_ENABLED               1
#define GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_DEFAULT               GP100_TILED_CACHE_AND_GFXP_WARBUG1667598_ON


#define GP100_TILE_COALESCE_BUFFER_SIZE_WAR_STRING                     "0x095424"
#define GP100_TILE_COALESCE_BUFFER_SIZE_WAR_ID                         0x00095424
#define GP100_TILE_COALESCE_BUFFER_SIZE_WAR_OVERINSTALL                0 // OVERRIDE
#define GP100_TILE_COALESCE_BUFFER_SIZE_WAR_DEFAULT                    0x00000020


#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_STRING                      "0x087237"
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_ID                          0x00087237
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_OVERINSTALL                 0 // OVERRIDE
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_OFF                         0
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_DISABLED                    0
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_ON                          1
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_ENABLED                     1
#define GP10X_ENABLE_PRIMIDWAR_BUG_1722438_DEFAULT                     GP10X_ENABLE_PRIMIDWAR_BUG_1722438_ON


#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_STRING                     "0x097234"
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_ID                         0x00097234
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_OVERINSTALL                0 // OVERRIDE
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_OFF                        0
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_DISABLED                   0
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_ON                         1
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_ENABLED                    1
#define GP10X_ENABLE_SHADERZWAR_BUG_1746518_DEFAULT                    GP10X_ENABLE_SHADERZWAR_BUG_1746518_ON


#define GPU_CACHEABLE_STRING                                           "1dc9466e"
#define GPU_CACHEABLE_ID                                               0x00f204bb
#define GPU_CACHEABLE_OVERINSTALL                                      0 // OVERRIDE
#define GPU_CACHEABLE_DISABLE_ALL                                      0x00000000
#define GPU_CACHEABLE_ALLOW_RENDERTARGET                               0x00000001
#define GPU_CACHEABLE_ALLOW_DEPTH                                      0x00000002
#define GPU_CACHEABLE_ALLOW_PRIMARY                                    0x00000004
#define GPU_CACHEABLE_ALLOW_VIDEO                                      0x00000008
#define GPU_CACHEABLE_ALLOW_TEXTURE                                    0x00000010
#define GPU_CACHEABLE_ALLOW_CUBEMAP                                    0x00000020
#define GPU_CACHEABLE_ALLOW_VOLUME                                     0x00000040
#define GPU_CACHEABLE_ALLOW_VERTEXARRAY                                0x00000080
#define GPU_CACHEABLE_ALLOW_INDEXARRAY                                 0x00000100
#define GPU_CACHEABLE_ALLOW_OFFSCREEN                                  0x00000200
#define GPU_CACHEABLE_ALLOW_STREAMOUT                                  0x00000400
#define GPU_CACHEABLE_ALLOW_SEMAPHORE                                  0x00004000
#define GPU_CACHEABLE_ALLOW_PUSHBUFFER                                 0x00010000
#define GPU_CACHEABLE_ALLOW_GPFIFOBUFFER                               0x00020000
#define GPU_CACHEABLE_ALLOW_CONTEXT_SAVE                               0x00040000
#define GPU_CACHEABLE_ALLOW_TEXHEADERS                                 0x00080000
#define GPU_CACHEABLE_ALLOW_SAMPLERS                                   0x00100000
#define GPU_CACHEABLE_ALLOW_ZCULL_CONTEXT                              0x00200000
#define GPU_CACHEABLE_ALLOW_FRAGMENTPROGRAM                            0x00800000
#define GPU_CACHEABLE_ALLOW_UNKNOWN                                    0x40000000
#define GPU_CACHEABLE_ALLOW_GDI                                        0x80000000
#define GPU_CACHEABLE_ALLOW_ALL                                        0xc0bf47ff
#define GPU_CACHEABLE_MASK                                             0xc0bf47ff
#define GPU_CACHEABLE_DEFAULT                                          GPU_CACHEABLE_ALLOW_ALL


#define GPU_CACHE_CONTROL_STRING                                       "cfdcb906"
#define GPU_CACHE_CONTROL_ID                                           0x00d161f7
#define GPU_CACHE_CONTROL_OVERINSTALL                                  0 // OVERRIDE
#define GPU_CACHE_CONTROL_DISABLE_ALL                                  0x00000000
#define GPU_CACHE_CONTROL_ENABLE_GPU_CACHE                             0x00000001
#define GPU_CACHE_CONTROL_FORCE_EVICT_ON_LOCK                          0x00000002
#define GPU_CACHE_CONTROL_FORCE_INVALIDATE_ON_UNLOCK                   0x00000004
#define GPU_CACHE_CONTROL_DISABLE_SUBALLOCATION_ON_GPU_CACHED_ALLOCATIONS 0x00000008
#define GPU_CACHE_CONTROL_FORCE_EVICT_ON_SUBALLOCATION_LOCK            0x00000010
#define GPU_CACHE_CONTROL_FORCE_EVICT_ON_UNCACHE_LOCK                  0x00000020
#define GPU_CACHE_CONTROL_FORCE_EVICT_ON_WRITEONLY_LOCK                0x00000040
#define GPU_CACHE_CONTROL_FORCE_INVALIDATE_ON_ALLOC                    0x00000080
#define GPU_CACHE_CONTROL_FORCE_INVALIDATE_ON_FREE                     0x00000100
#define GPU_CACHE_CONTROL_FORCE_EVICT_CPU_COPY_SRC                     0x00000200
#define GPU_CACHE_CONTROL_FORCE_INVALIDATE_CPU_COPY_DST                0x00000400
#define GPU_CACHE_CONTROL_DISABLE_NOOVERWRITE_LOCK_OPTIMIZATION        0x00000800
#define GPU_CACHE_CONTROL_DISABLE_WRITEONLY_LOCK_OPTIMIZATION          0x00001000
#define GPU_CACHE_CONTROL_DISABLE_HW_READONLY_OPTIMIZATION             0x00002000
#define GPU_CACHE_CONTROL_USE_PRI_REGISTER                             0x00004000
#define GPU_CACHE_CONTROL_ENABLE_ALL                                   0x00007fff
#define GPU_CACHE_CONTROL_MASK                                         0x00007fff
#define GPU_CACHE_CONTROL_DEFAULT                                      GPU_CACHE_CONTROL_ENABLE_GPU_CACHE


#define GRAPHENABLE_STRING                                             "20071974"
#define GRAPHENABLE_ID                                                 0x008d2004
#define GRAPHENABLE_OVERINSTALL                                        0 // OVERRIDE
#define GRAPHENABLE_OFF                                                0x62951413
#define GRAPHENABLE_DISABLED                                           0x62951413
#define GRAPHENABLE_ON                                                 0x31415926
#define GRAPHENABLE_ENABLED                                            0x31415926
#define GRAPHENABLE_DEFAULT                                            GRAPHENABLE_OFF


#define GRID_STATE_BUFFER_SLOTS_STRING                                 "0xddc3f3"
#define GRID_STATE_BUFFER_SLOTS_ID                                     0x00ddc3f3
#define GRID_STATE_BUFFER_SLOTS_OVERINSTALL                            0 // OVERRIDE
#define GRID_STATE_BUFFER_SLOTS_DEFAULT                                32


#define GR_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_STRING               "802rea28"
#define GR_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_ID                   0x001fc151
#define GR_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_OVERINSTALL          0 // OVERRIDE
#define GR_LARGE_PUSHBUFFER_RENAMING_CHAIN_LENGTH_DEFAULT              64


#define GR_LARGE_PUSHBUFFER_SIZE_STRING                                "911reb71"
#define GR_LARGE_PUSHBUFFER_SIZE_ID                                    0x004cb365
#define GR_LARGE_PUSHBUFFER_SIZE_OVERINSTALL                           0 // OVERRIDE
#define GR_LARGE_PUSHBUFFER_SIZE_DEFAULT                               131072


#define GR_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_STRING               "802rea27"
#define GR_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_ID                   0x002ff151
#define GR_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_OVERINSTALL          0 // OVERRIDE
#define GR_SMALL_PUSHBUFFER_RENAMING_CHAIN_LENGTH_DEFAULT              512


#define GR_SMALL_PUSHBUFFER_SIZE_STRING                                "911reb70"
#define GR_SMALL_PUSHBUFFER_SIZE_ID                                    0x004ca365
#define GR_SMALL_PUSHBUFFER_SIZE_OVERINSTALL                           0 // OVERRIDE
#define GR_SMALL_PUSHBUFFER_SIZE_DEFAULT                               16384


#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_STRING    "0x097238"
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_ID        0x00097238
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_OVERINSTALL 0 // OVERRIDE
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_OFF       0
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_DISABLED  0
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_ON        1
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_ENABLED   1
#define GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_DEFAULT   GV100_ENABLE_CONSERVATIVE_RASTERIZER_WAR_BUG_1898952_ON


#define HANDLE_REPORTERROR_MODES_STRING                                "0562AECD"
#define HANDLE_REPORTERROR_MODES_ID                                    0x00effecd
#define HANDLE_REPORTERROR_MODES_OVERINSTALL                           0 // OVERRIDE
#define HANDLE_REPORTERROR_MODES_TRIGGER_UMD_ASSERT                    0x1
#define HANDLE_REPORTERROR_MODES_TRIGGER_BUGCHECK                      0x2
#define HANDLE_REPORTERROR_MODES_DEFAULT                               HANDLE_REPORTERROR_MODES_TRIGGER_UMD_ASSERT


#define HEAP_STRING                                                    "19561232"
#define HEAP_ID                                                        0x007a949b
#define HEAP_OVERINSTALL                                               0 // OVERRIDE
#define HEAP_ANY                                                       0x74621345
#define HEAP_SYSTEM                                                    0x29857394
#define HEAP_VIDEO                                                     0x80238105
#define HEAP_DEFAULT                                                   HEAP_ANY


#define HEAPEVICTFAVORPREFERRED_STRING                                 "40194015"
#define HEAPEVICTFAVORPREFERRED_ID                                     0x0081928b
#define HEAPEVICTFAVORPREFERRED_OVERINSTALL                            0 // OVERRIDE
#define HEAPEVICTFAVORPREFERRED_OFF                                    0x00000000
#define HEAPEVICTFAVORPREFERRED_DISABLED                               0x00000000
#define HEAPEVICTFAVORPREFERRED_ON                                     0x00000001
#define HEAPEVICTFAVORPREFERRED_ENABLED                                0x00000001
#define HEAPEVICTFAVORPREFERRED_DEFAULT                                HEAPEVICTFAVORPREFERRED_ON


#define HEAP_TIER2_COMPRESSION_SUPPORT_STRING                          "0xacfcc0"
#define HEAP_TIER2_COMPRESSION_SUPPORT_ID                              0x00acfcc0
#define HEAP_TIER2_COMPRESSION_SUPPORT_OVERINSTALL                     0 // OVERRIDE
#define HEAP_TIER2_COMPRESSION_SUPPORT_COMPRESS_ENTIRE_HEAP            0x00000000
#define HEAP_TIER2_COMPRESSION_SUPPORT_COMPRESS_ON_ADDITIONAL_MAPPING  0x00000001
#define HEAP_TIER2_COMPRESSION_SUPPORT_DEFAULT                         HEAP_TIER2_COMPRESSION_SUPPORT_COMPRESS_ON_ADDITIONAL_MAPPING


#define HISTORY_BUFFER_RETIRE_LIST_SIZE_STRING                         "1e8966"
#define HISTORY_BUFFER_RETIRE_LIST_SIZE_ID                             0x001e8966
#define HISTORY_BUFFER_RETIRE_LIST_SIZE_OVERINSTALL                    0 // OVERRIDE
#define HISTORY_BUFFER_RETIRE_LIST_SIZE_DEFAULT                        100


#define HOPPER_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                    "0x523dfa"
#define HOPPER_A_TILEDCACHE_BUFFERINTERLEAVE_ID                        0x00523dfa
#define HOPPER_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL               0 // OVERRIDE
#define HOPPER_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                   0x00022313


#define HOPPER_A_TILEDCACHE_CONTROL_STRING                             "0x523dfb"
#define HOPPER_A_TILEDCACHE_CONTROL_ID                                 0x00523dfb
#define HOPPER_A_TILEDCACHE_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define HOPPER_A_TILEDCACHE_CONTROL_DEFAULT                            0x08080202


#define HOPPER_A_TILEDCACHE_CONTROL_EXTENDED_STRING                    "0x523dfc"
#define HOPPER_A_TILEDCACHE_CONTROL_EXTENDED_ID                        0x00523dfc
#define HOPPER_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL               0 // OVERRIDE
#define HOPPER_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                   0x00000008


#define HOPPER_A_TILEDCACHE_L2_USAGE_STRING                            "0x523dfe"
#define HOPPER_A_TILEDCACHE_L2_USAGE_ID                                0x00523dfe
#define HOPPER_A_TILEDCACHE_L2_USAGE_OVERINSTALL                       0 // OVERRIDE
#define HOPPER_A_TILEDCACHE_L2_USAGE_DEFAULT                           0.5f


#define HOPPER_A_TILEDCACHE_STATETHRESHOLD_STRING                      "0x523dfd"
#define HOPPER_A_TILEDCACHE_STATETHRESHOLD_ID                          0x00523dfd
#define HOPPER_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                 0 // OVERRIDE
#define HOPPER_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                     0x00080001


#define HOPPER_TEXTURE_HEADER_VERSION_STRING                           "0x20201030"
#define HOPPER_TEXTURE_HEADER_VERSION_ID                               0x00201030
#define HOPPER_TEXTURE_HEADER_VERSION_OVERINSTALL                      0 // OVERRIDE
#define HOPPER_TEXTURE_HEADER_VERSION_OFF                              0
#define HOPPER_TEXTURE_HEADER_VERSION_DISABLED                         0
#define HOPPER_TEXTURE_HEADER_VERSION_ON                               1
#define HOPPER_TEXTURE_HEADER_VERSION_ENABLED                          1
#define HOPPER_TEXTURE_HEADER_VERSION_DEFAULT                          HOPPER_TEXTURE_HEADER_VERSION_ON


#define HOTKEYS_STRING                                                 "97f3456212"
#define HOTKEYS_ID                                                     0x0032cf4b
#define HOTKEYS_OVERINSTALL                                            0 // OVERRIDE
#define HOTKEYS_TEST                                                   0x00000001
#define HOTKEYS_UM_BREAK                                               0x00000002
#define HOTKEYS_TOGGLE                                                 0x00000004
#define HOTKEYS_STATS_RESET                                            0x00000008
#define HOTKEYS_GPUVIEW_EVENT                                          0x00000020
#define HOTKEYS_STUTTERSTATS_EVENT                                     0x00000040
#define HOTKEYS_CYCLESTATS_EVENT                                       0x00000080
#define HOTKEYS_KEYS_MASK                                              0x000000EF
#define HOTKEYS_DEFAULT                                                0


#define HOTKEYS_ENABLE_STRING                                          "55612183"
#define HOTKEYS_ENABLE_ID                                              0x00aaa6b3
#define HOTKEYS_ENABLE_OVERINSTALL                                     0 // OVERRIDE
#define HOTKEYS_ENABLE_OFF                                             0x00000000
#define HOTKEYS_ENABLE_DISABLED                                        0x00000000
#define HOTKEYS_ENABLE_ON                                              0x00000001
#define HOTKEYS_ENABLE_ENABLED                                         0x00000001
#define HOTKEYS_ENABLE_DEFAULT                                         HOTKEYS_ENABLE_OFF


#define HOTKEYS_USE_GLOBAL_HOOK_STRING                                 "40194444"
#define HOTKEYS_USE_GLOBAL_HOOK_ID                                     0x00813333
#define HOTKEYS_USE_GLOBAL_HOOK_OVERINSTALL                            0 // OVERRIDE
#define HOTKEYS_USE_GLOBAL_HOOK_OFF                                    0x00000000
#define HOTKEYS_USE_GLOBAL_HOOK_DISABLED                               0x00000000
#define HOTKEYS_USE_GLOBAL_HOOK_ON                                     0x00000001
#define HOTKEYS_USE_GLOBAL_HOOK_ENABLED                                0x00000001
#define HOTKEYS_USE_GLOBAL_HOOK_DEFAULT                                HOTKEYS_USE_GLOBAL_HOOK_OFF


#define HWCURSORENABLE_STRING                                          "37210571"
#define HWCURSORENABLE_ID                                              0x008b7cac
#define HWCURSORENABLE_OVERINSTALL                                     0 // OVERRIDE
#define HWCURSORENABLE_OFF                                             0x95402745
#define HWCURSORENABLE_DISABLED                                        0x95402745
#define HWCURSORENABLE_ON                                              0x12907430
#define HWCURSORENABLE_ENABLED                                         0x12907430
#define HWCURSORENABLE_DEFAULT                                         HWCURSORENABLE_ON


#define HWS_ATOMIC_SUBMIT_WAR_STRING                                   "0xfa505b2a"
#define HWS_ATOMIC_SUBMIT_WAR_ID                                       0x00fa505b
#define HWS_ATOMIC_SUBMIT_WAR_OVERINSTALL                              0 // OVERRIDE
#define HWS_ATOMIC_SUBMIT_WAR_OFF                                      0
#define HWS_ATOMIC_SUBMIT_WAR_DISABLED                                 0
#define HWS_ATOMIC_SUBMIT_WAR_ON                                       1
#define HWS_ATOMIC_SUBMIT_WAR_ENABLED                                  1
#define HWS_ATOMIC_SUBMIT_WAR_DEFAULT                                  HWS_ATOMIC_SUBMIT_WAR_ON


#define HW_BUG_WAR_ENABLES_STRING                                      "0xa25f24"
#define HW_BUG_WAR_ENABLES_ID                                          0x00a25f24
#define HW_BUG_WAR_ENABLES_OVERINSTALL                                 0 // OVERRIDE
#define HW_BUG_WAR_ENABLES_DISABLED                                    0x00000000
#define HW_BUG_WAR_ENABLES_TURING_WAR_2042382                          0x00000001
#define HW_BUG_WAR_ENABLES_DEFAULT                                     HW_BUG_WAR_ENABLES_DISABLED


#define ICAFE_LOGO_STRING                                              "da1337"
#define ICAFE_LOGO_ID                                                  0x00da1337
#define ICAFE_LOGO_OVERINSTALL                                         0 // OVERRIDE
#define ICAFE_LOGO_OFF                                                 0x00000000
#define ICAFE_LOGO_DISABLED                                            0x00000000
#define ICAFE_LOGO_ON                                                  0x00000001
#define ICAFE_LOGO_ENABLED                                             0x00000001
#define ICAFE_LOGO_DEFAULT                                             ICAFE_LOGO_OFF


#define ICAFE_LOGO_CONFIG_STRING                                       "db1337"
#define ICAFE_LOGO_CONFIG_ID                                           0x00db1337
#define ICAFE_LOGO_CONFIG_OVERINSTALL                                  0 // OVERRIDE
#define ICAFE_LOGO_CONFIG_DEFAULT                                      L""


#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_STRING                    "f3843932"
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_ID                        0x00c9af4f
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_OVERINSTALL               0 // OVERRIDE
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_OFF                       0xa2b53761
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_DISABLED                  0xa2b53761
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_ON                        0x79292610
#define IGNORE_SET_BACKGROUND_PROCESSING_DDI_ENABLED                   0x79292610


#define IMMOCCQUERY_ENABLE_STRING                                      "19527526"
#define IMMOCCQUERY_ENABLE_ID                                          0x00f83879
#define IMMOCCQUERY_ENABLE_OVERINSTALL                                 0 // OVERRIDE
#define IMMOCCQUERY_ENABLE_OFF                                         0x22754241
#define IMMOCCQUERY_ENABLE_DISABLED                                    0x22754241
#define IMMOCCQUERY_ENABLE_ON                                          0x66855023
#define IMMOCCQUERY_ENABLE_ENABLED                                     0x66855023
#define IMMOCCQUERY_ENABLE_DEFAULT                                     IMMOCCQUERY_ENABLE_OFF


#define IMMOCCQUERY_RESULT_STRING                                      "A380B747"
#define IMMOCCQUERY_RESULT_ID                                          0x0000b0cb
#define IMMOCCQUERY_RESULT_OVERINSTALL                                 0 // OVERRIDE
#define IMMOCCQUERY_RESULT_DEFAULT                                     0x1000


#define KEPLER_APPLY_ALD_WAR_STRING                                    "846411"
#define KEPLER_APPLY_ALD_WAR_ID                                        0x00846411
#define KEPLER_APPLY_ALD_WAR_OVERINSTALL                               0 // OVERRIDE
#define KEPLER_APPLY_ALD_WAR_OFF                                       0
#define KEPLER_APPLY_ALD_WAR_DISABLED                                  0
#define KEPLER_APPLY_ALD_WAR_ON                                        1
#define KEPLER_APPLY_ALD_WAR_ENABLED                                   1
#define KEPLER_APPLY_ALD_WAR_DEFAULT                                   KEPLER_APPLY_ALD_WAR_OFF


#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_STRING                 "194ff3"
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_ID                     0x007033ab
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_OVERINSTALL            0 // OVERRIDE
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_OFF                    0
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_DISABLED               0
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_ON                     1
#define KEPLER_CLEAR_SM_HALFCTL_CTRL_SCTL_CYA_6_ENABLED                1


#define KEPLER_COLOR_DECOMPRESSION_STRING                              "20adec"
#define KEPLER_COLOR_DECOMPRESSION_ID                                  0x0020adec
#define KEPLER_COLOR_DECOMPRESSION_OVERINSTALL                         0 // OVERRIDE
#define KEPLER_COLOR_DECOMPRESSION_DISABLE                             0x00000000
#define KEPLER_COLOR_DECOMPRESSION_ALLOW_DECOMPRESSION                 0x00000001
#define KEPLER_COLOR_DECOMPRESSION_DECOMPRESS_FOR_NAIVE_ENGINES        0x00000002
#define KEPLER_COLOR_DECOMPRESSION_DEFAULT                             0x00000003


#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_STRING                        "0xabd14a"
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_ID                            0x00abd14a
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_OVERINSTALL                   0 // OVERRIDE
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_ZERO                          0x0
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_ONE                           0x1
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_TWO                           0x2
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_THREE                         0x3
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_FOUR                          0x4
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_FIVE                          0x5
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_SIX                           0x6
#define KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_DEFAULT                       KEPLER_COMPUTE_EMU_CB_FIRST_SLOT_SIX


#define KEPLER_COMP_ARITHMETIC_DISABLE_STRING                          "20addd"
#define KEPLER_COMP_ARITHMETIC_DISABLE_ID                              0x0020addd
#define KEPLER_COMP_ARITHMETIC_DISABLE_OVERINSTALL                     0 // OVERRIDE
#define KEPLER_COMP_ARITHMETIC_DISABLE_NORMAL                          0x00000000
#define KEPLER_COMP_ARITHMETIC_DISABLE_FORCE                           0x00000001


#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_STRING                        "20af64"
#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_ID                            0x0078ccdd
#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_OVERINSTALL                   0 // OVERRIDE
#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_DISABLED_COMPUTE              0x00000000
#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_ENABLED_COMPUTE               0x00000001
#define KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_DEFAULT                       KEPLER_FORCE_TEXLOCK_CTA_AS_TILE_DISABLED_COMPUTE


#define KEPLER_GPCS_TC_FLUSH_WAR_STRING                                "0x120513"
#define KEPLER_GPCS_TC_FLUSH_WAR_ID                                    0x00120513
#define KEPLER_GPCS_TC_FLUSH_WAR_OVERINSTALL                           0 // OVERRIDE
#define KEPLER_GPCS_TC_FLUSH_WAR_OFF                                   0
#define KEPLER_GPCS_TC_FLUSH_WAR_DISABLED                              0
#define KEPLER_GPCS_TC_FLUSH_WAR_ON                                    1
#define KEPLER_GPCS_TC_FLUSH_WAR_ENABLED                               1
#define KEPLER_GPCS_TC_FLUSH_WAR_DEFAULT                               KEPLER_GPCS_TC_FLUSH_WAR_OFF


#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_STRING           "3001ad"
#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_ID               0x003001ad
#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_OVERINSTALL      0 // OVERRIDE
#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_INTEGER_AND_FRACTION 0x00000000
#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_INTEGER_ONLY     0x00000001
#define KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_DEFAULT          KEPLER_MIN_LOD_CLAMP_BEHAVIOR_FOR_NEAREST_MIP_INTEGER_AND_FRACTION


#define KEPLER_PRI_GPCS_TPCS_SM_POWER_THROTTLE_STRING                  "2a1f64"
#define KEPLER_PRI_GPCS_TPCS_SM_POWER_THROTTLE_ID                      0x0076caab
#define KEPLER_PRI_GPCS_TPCS_SM_POWER_THROTTLE_OVERINSTALL             0 // OVERRIDE


#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_STRING       "2a1f66"
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_ID           0x0076caad
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_OVERINSTALL  0 // OVERRIDE
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_ALL          0x1
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_HALF         0x2
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_SETS_QUARTER      0x4


#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_WAYS_STRING       "2a1f65"
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_WAYS_ID           0x0076caac
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_WAYS_OVERINSTALL  0 // OVERRIDE
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_WAYS_GF100_1      0x1
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_CFG_1_ACTIVE_WAYS_GF100_ALL    0x2


#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_0_STRING              "0xfa34888"
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_0_ID                  0x00a34888
#define KEPLER_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_0_OVERINSTALL         0 // OVERRIDE


#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_STRING                     "0xdab1da"
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_ID                         0x00dab1da
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_OVERINSTALL                0 // OVERRIDE
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_OFF                        0x0
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_DISABLED                   0x0
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_ON                         0x1
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_ENABLED                    0x1
#define KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_DEFAULT                    KEPLER_SAMPLE_INFO_DIRECT_CB_LOOKUP_ON


#define KEPLER_SHADER_FAIL_CTA_REG_LIMIT_STRING                        "0x00BADEEF"
#define KEPLER_SHADER_FAIL_CTA_REG_LIMIT_ID                            0x00badeef
#define KEPLER_SHADER_FAIL_CTA_REG_LIMIT_OVERINSTALL                   0 // OVERRIDE
#define KEPLER_SHADER_FAIL_CTA_REG_LIMIT_DEFAULT                       1024


#define KEPLER_SHADER_FAIL_CTA_THREAD_LIMIT_STRING                     "0x00BADEEE"
#define KEPLER_SHADER_FAIL_CTA_THREAD_LIMIT_ID                         0x00badeee
#define KEPLER_SHADER_FAIL_CTA_THREAD_LIMIT_OVERINSTALL                0 // OVERRIDE
#define KEPLER_SHADER_FAIL_CTA_THREAD_LIMIT_DEFAULT                    64


#define KEPLER_SHARED_MEMORY_BANK_MAPPING_STRING                       "309876"
#define KEPLER_SHARED_MEMORY_BANK_MAPPING_ID                           0x00309876
#define KEPLER_SHARED_MEMORY_BANK_MAPPING_OVERINSTALL                  0 // OVERRIDE
#define KEPLER_SHARED_MEMORY_BANK_MAPPING_FOUR_BYTES_PER_BANK          0x0
#define KEPLER_SHARED_MEMORY_BANK_MAPPING_EIGHT_BYTES_PER_BANK         0x1
#define KEPLER_SHARED_MEMORY_BANK_MAPPING_DEFAULT                      KEPLER_SHARED_MEMORY_BANK_MAPPING_FOUR_BYTES_PER_BANK


#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_STRING                    "0xae7860"
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_ID                        0x00ae7860
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_OVERINSTALL               0 // OVERRIDE
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_OFF                       0x56023627
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_DISABLED                  0x56023627
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_ON                        0x37299934
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_ENABLED                   0x37299934
#define KEPLER_SMART_TEXTURE_INVALIDATES_WFI_DEFAULT                   KEPLER_SMART_TEXTURE_INVALIDATES_WFI_ON


#define KILL_DRAWS_STRING                                              "54396503"
#define KILL_DRAWS_ID                                                  0x004426c0
#define KILL_DRAWS_OVERINSTALL                                         0 // OVERRIDE
#define KILL_DRAWS_DEFAULT                                             0


#define KILL_DRAWS_PM_TRIGGER_NUM_FRAMES_STRING                        "54396228"
#define KILL_DRAWS_PM_TRIGGER_NUM_FRAMES_ID                            0x0022840f
#define KILL_DRAWS_PM_TRIGGER_NUM_FRAMES_OVERINSTALL                   0 // OVERRIDE
#define KILL_DRAWS_PM_TRIGGER_NUM_FRAMES_DEFAULT                       0


#define LARGE_VA_STRING                                                "00101104"
#define LARGE_VA_ID                                                    0x0007fbb6
#define LARGE_VA_OVERINSTALL                                           0 // OVERRIDE
#define LARGE_VA_DISABLE                                               0x00000000
#define LARGE_VA_ENABLE_LARGEVA                                        0x00000001
#define LARGE_VA_ENABLE_LARGEVA_QUADRO                                 0x00000002
#define LARGE_VA_ENABLE_LARGEVA_QUADRO_TESLA                           0x00000003
#define LARGE_VA_DEFAULT                                               LARGE_VA_DISABLE


#define LATENCY_STRING                                                 "05f543"
#define LATENCY_ID                                                     0x0005f543
#define LATENCY_OVERINSTALL                                            1 // MERGE
#define LATENCY_BEST_PERFORMANCE                                       0x0
#define LATENCY_LOW_LATENCY                                            0x1
#define LATENCY_LOWEST_LATENCY                                         0x2
#define LATENCY_DEFAULT                                                LATENCY_BEST_PERFORMANCE


#define LCDOD_EMULATE_PANEL_PRODUCT_ID_STRING                          "aa8898"
#define LCDOD_EMULATE_PANEL_PRODUCT_ID_ID                              0x00aa8898
#define LCDOD_EMULATE_PANEL_PRODUCT_ID_OVERINSTALL                     0 // OVERRIDE
#define LCDOD_EMULATE_PANEL_PRODUCT_ID_DEFAULT                         0x0


#define LCDOD_EMULATE_PANEL_VENDOR_ID_STRING                           "aa8899"
#define LCDOD_EMULATE_PANEL_VENDOR_ID_ID                               0x00aa8899
#define LCDOD_EMULATE_PANEL_VENDOR_ID_OVERINSTALL                      0 // OVERRIDE
#define LCDOD_EMULATE_PANEL_VENDOR_ID_DEFAULT                          0x0


#define LCDOD_ENABLE_STRING                                            "598888"
#define LCDOD_ENABLE_ID                                                0x00598888
#define LCDOD_ENABLE_OVERINSTALL                                       0 // OVERRIDE
#define LCDOD_ENABLE_OFF                                               0
#define LCDOD_ENABLE_DISABLED                                          0
#define LCDOD_ENABLE_ON                                                1
#define LCDOD_ENABLE_ENABLED                                           1
#define LCDOD_ENABLE_DEFAULT                                           LCDOD_ENABLE_ON


#define LCDOD_FORCED_ENABLE_STRING                                     "aaa999"
#define LCDOD_FORCED_ENABLE_ID                                         0x00aaa999
#define LCDOD_FORCED_ENABLE_OVERINSTALL                                0 // OVERRIDE
#define LCDOD_FORCED_ENABLE_OFF                                        0x00000000
#define LCDOD_FORCED_ENABLE_ON                                         0x00000001
#define LCDOD_FORCED_ENABLE_CONDITIONAL_ON                             0x00000002
#define LCDOD_FORCED_ENABLE_DEFAULT                                    LCDOD_FORCED_ENABLE_OFF


#define LCDOD_HOTKEY_ENABLE_STRING                                     "591888"
#define LCDOD_HOTKEY_ENABLE_ID                                         0x00591888
#define LCDOD_HOTKEY_ENABLE_OVERINSTALL                                0 // OVERRIDE
#define LCDOD_HOTKEY_ENABLE_OFF                                        0
#define LCDOD_HOTKEY_ENABLE_DISABLED                                   0
#define LCDOD_HOTKEY_ENABLE_ON                                         1
#define LCDOD_HOTKEY_ENABLE_ENABLED                                    1
#define LCDOD_HOTKEY_ENABLE_DEFAULT                                    LCDOD_HOTKEY_ENABLE_OFF


#define LCDOD_INDICATOR_STRING                                         "aaa888"
#define LCDOD_INDICATOR_ID                                             0x00aaa888
#define LCDOD_INDICATOR_OVERINSTALL                                    0 // OVERRIDE
#define LCDOD_INDICATOR_OFF                                            0
#define LCDOD_INDICATOR_DISABLED                                       0
#define LCDOD_INDICATOR_ON                                             1
#define LCDOD_INDICATOR_ENABLED                                        1
#define LCDOD_INDICATOR_DEFAULT                                        LCDOD_INDICATOR_OFF


#define LIMITQUEUEDFBBLITSENABLE_STRING                                "24464826"
#define LIMITQUEUEDFBBLITSENABLE_ID                                    0x0022163e
#define LIMITQUEUEDFBBLITSENABLE_OVERINSTALL                           0 // OVERRIDE
#define LIMITQUEUEDFBBLITSENABLE_OFF                                   0x14138793
#define LIMITQUEUEDFBBLITSENABLE_DISABLED                              0x14138793
#define LIMITQUEUEDFBBLITSENABLE_ON                                    0x23812865
#define LIMITQUEUEDFBBLITSENABLE_ENABLED                               0x23812865
#define LIMITQUEUEDFBBLITSENABLE_DEFAULT                               LIMITQUEUEDFBBLITSENABLE_OFF


#define LMEM_MIN_SIZE_STRING                                           "7234fa"
#define LMEM_MIN_SIZE_ID                                               0x007234fa
#define LMEM_MIN_SIZE_OVERINSTALL                                      0 // OVERRIDE
#define LMEM_MIN_SIZE_DEFAULT                                          0


#define LODBIASADJUST_STRING                                           "88481200"
#define LODBIASADJUST_ID                                               0x00738e8f
#define LODBIASADJUST_OVERINSTALL                                      1 // MERGE
#define LODBIASADJUST_MIN                                              0xffffff80
#define LODBIASADJUST_MAX                                              128
#define LODBIASADJUST_DEFAULT                                          0


#define LOGOENABLE_STRING                                              "26771978"
#define LOGOENABLE_ID                                                  0x00beace5
#define LOGOENABLE_OVERINSTALL                                         0 // OVERRIDE
#define LOGOENABLE_OFF                                                 0x56616210
#define LOGOENABLE_DISABLED                                            0x56616210
#define LOGOENABLE_ON                                                  0x06072997
#define LOGOENABLE_ENABLED                                             0x06072997
#define LOGOENABLE_DEFAULT                                             LOGOENABLE_OFF


#define LOWLATENCY_VSYNC_INDICATOR_STRING                              "424ACB"
#define LOWLATENCY_VSYNC_INDICATOR_ID                                  0x006d663a
#define LOWLATENCY_VSYNC_INDICATOR_OVERINSTALL                         0 // OVERRIDE
#define LOWLATENCY_VSYNC_INDICATOR_OFF                                 0
#define LOWLATENCY_VSYNC_INDICATOR_DISABLED                            0
#define LOWLATENCY_VSYNC_INDICATOR_ON                                  1
#define LOWLATENCY_VSYNC_INDICATOR_ENABLED                             1
#define LOWLATENCY_VSYNC_INDICATOR_DEFAULT                             LOWLATENCY_VSYNC_INDICATOR_OFF


#define LOW_LATENCY_BLEND_FACTOR_STRING                                "bf0871"
#define LOW_LATENCY_BLEND_FACTOR_ID                                    0x00bf0871
#define LOW_LATENCY_BLEND_FACTOR_OVERINSTALL                           0 // OVERRIDE
#define LOW_LATENCY_BLEND_FACTOR_DEFAULT                               127


#define LOW_LATENCY_MODE_STRING                                        "45AB1F"
#define LOW_LATENCY_MODE_ID                                            0x0045ab1f
#define LOW_LATENCY_MODE_OVERINSTALL                                   0 // OVERRIDE
#define LOW_LATENCY_MODE_ALLOW                                         0x00000001
#define LOW_LATENCY_MODE_BLEND                                         0x00000002
#define LOW_LATENCY_MODE_DYNAMIC_FPS_CAP                               0x00000004
#define LOW_LATENCY_MODE_COLLAPSE_FLIP                                 0x00000008
#define LOW_LATENCY_MODE_DEFAULT                                       0x0000000d


#define MAXWELL_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                   "0x523dc2"
#define MAXWELL_A_TILEDCACHE_BUFFERINTERLEAVE_ID                       0x00523dc2
#define MAXWELL_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL              0 // OVERRIDE
#define MAXWELL_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                  0x0000230A


#define MAXWELL_A_TILEDCACHE_CONTROL_STRING                            "0x523dc3"
#define MAXWELL_A_TILEDCACHE_CONTROL_ID                                0x00523dc3
#define MAXWELL_A_TILEDCACHE_CONTROL_OVERINSTALL                       0 // OVERRIDE
#define MAXWELL_A_TILEDCACHE_CONTROL_DEFAULT                           0x08080202


#define MAXWELL_A_TILEDCACHE_CONTROL_EXTENDED_STRING                   "0x523dd3"
#define MAXWELL_A_TILEDCACHE_CONTROL_EXTENDED_ID                       0x00523dd3
#define MAXWELL_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL              0 // OVERRIDE
#define MAXWELL_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                  0x00000008


#define MAXWELL_A_TILEDCACHE_L2_USAGE_STRING                           "0x523dc5"
#define MAXWELL_A_TILEDCACHE_L2_USAGE_ID                               0x00523dc5
#define MAXWELL_A_TILEDCACHE_L2_USAGE_OVERINSTALL                      0 // OVERRIDE
#define MAXWELL_A_TILEDCACHE_L2_USAGE_DEFAULT                          0.3f


#define MAXWELL_A_TILEDCACHE_STATETHRESHOLD_STRING                     "0x523dc4"
#define MAXWELL_A_TILEDCACHE_STATETHRESHOLD_ID                         0x00523dc4
#define MAXWELL_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                    0x00080001


#define MAXWELL_B_EMULATE_PIXLD_OFFSET_STRING                          "675665"
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_ID                              0x00675665
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_OVERINSTALL                     0 // OVERRIDE
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_DISABLED                        0
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_OFF                             0
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_ENABLED                         1
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_ON                              1
#define MAXWELL_B_EMULATE_PIXLD_OFFSET_DEFAULT                         MAXWELL_B_EMULATE_PIXLD_OFFSET_ENABLED


#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_STRING                     "57467702"
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_ID                         0x00601f67
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_DYNAMIC                    0x92446898
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_ALWAYS                     0x83557128
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_NEVER                      0x99941284
#define MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_DEFAULT                    MAXWELL_B_FAST_GS_AUTOMATIC_COMPILE_DYNAMIC


#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_STRING                    "27693652"
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_ID                        0x00d430b0
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_OVERINSTALL               0 // OVERRIDE
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_DYNAMIC                   0xb03b67be
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_ALWAYS                    0x59bb4cef
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_NEVER                     0x8c83bdb5
#define MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_DEFAULT                   MAXWELL_B_FAST_GS_USE_VIEWPORT_ORDER_DYNAMIC


#define MAXWELL_B_FAST_GS_WAR_1514369_STRING                           "42158451"
#define MAXWELL_B_FAST_GS_WAR_1514369_ID                               0x00f56cbe
#define MAXWELL_B_FAST_GS_WAR_1514369_OVERINSTALL                      0 // OVERRIDE
#define MAXWELL_B_FAST_GS_WAR_1514369_DYNAMIC                          0x5d3cc844
#define MAXWELL_B_FAST_GS_WAR_1514369_ALWAYS                           0xbca229ec
#define MAXWELL_B_FAST_GS_WAR_1514369_NEVER                            0x451ff4aa
#define MAXWELL_B_FAST_GS_WAR_1514369_DEFAULT                          MAXWELL_B_FAST_GS_WAR_1514369_DYNAMIC


#define MAXWELL_B_SAMPLE_INTERLEAVE_STRING                             "866394547"
#define MAXWELL_B_SAMPLE_INTERLEAVE_ID                                 0x0098c1ac
#define MAXWELL_B_SAMPLE_INTERLEAVE_OVERINSTALL                        1 // MERGE
#define MAXWELL_B_SAMPLE_INTERLEAVE_OFF                                0
#define MAXWELL_B_SAMPLE_INTERLEAVE_DISABLED                           0
#define MAXWELL_B_SAMPLE_INTERLEAVE_ON                                 1
#define MAXWELL_B_SAMPLE_INTERLEAVE_ENABLED                            1
#define MAXWELL_B_SAMPLE_INTERLEAVE_DEFAULT                            MAXWELL_B_SAMPLE_INTERLEAVE_OFF


#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_STRING                       "666665"
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_ID                           0x00666665
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_OVERINSTALL                  0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_DISABLED                     0
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_OFF                          0
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_ENABLED                      1
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_ON                           1
#define MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_DEFAULT                      MAXWELL_B_SAMPLE_INTERLEAVE_ALLOW_ENABLED


#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_STRING                      "896741"
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_ID                          0x00896741
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_OVERINSTALL                 0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_OFF                         0
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_DISABLED                    0
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_ON                          1
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_ENABLED                     1
#define MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_DEFAULT                     MAXWELL_B_SAMPLE_INTERLEAVE_HOTKEY_OFF


#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_STRING                   "41234A"
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_ID                       0x0041234a
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_OVERINSTALL              0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_OFF                      0
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_DISABLED                 0
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_ON                       1
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_ENABLED                  1
#define MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_DEFAULT                  MAXWELL_B_SAMPLE_INTERLEAVE_INDICATOR_OFF


#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_STRING                 "F42AE1"
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_ID                     0x00f42ae1
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_OVERINSTALL            0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_1x_to_2x               0x0001
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_2x_to_4x               0x0002
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_4x_to_8x               0x0004
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_8x_to_16x              0x0008
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_16x_custom             0x0010
#define MAXWELL_B_SAMPLE_INTERLEAVE_MODE_ENABLE_DEFAULT                0x0000001e


#define MAXWELL_B_SAMPLE_INTERLEAVE_NUM_SETS_IN_FILE_STRING            "644111"
#define MAXWELL_B_SAMPLE_INTERLEAVE_NUM_SETS_IN_FILE_ID                0x00644111
#define MAXWELL_B_SAMPLE_INTERLEAVE_NUM_SETS_IN_FILE_OVERINSTALL       0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_NUM_SETS_IN_FILE_DEFAULT           16


#define MAXWELL_B_SAMPLE_INTERLEAVE_PATH_STRING                        "2145ba"
#define MAXWELL_B_SAMPLE_INTERLEAVE_PATH_ID                            0x002145ba
#define MAXWELL_B_SAMPLE_INTERLEAVE_PATH_OVERINSTALL                   0 // OVERRIDE


#define MAXWELL_B_SAMPLE_INTERLEAVE_PROFILED_SHADERS_STRING            "ab4312"
#define MAXWELL_B_SAMPLE_INTERLEAVE_PROFILED_SHADERS_ID                0x00ab4312
#define MAXWELL_B_SAMPLE_INTERLEAVE_PROFILED_SHADERS_OVERINSTALL       0 // OVERRIDE


#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_STRING                    "854811352"
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_ID                        0x00854cab
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_OVERINSTALL               0 // OVERRIDE
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_SAMPLES_FROM_FILE         0x0004
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_DISABLE_ON_SQUARE_TARGETS 0x0008
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_DISABLE_DITHERING         0x0010
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_DECOMPRESS_DEPTH_ON_TEXTURE_READ 0x0020
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_DISABLE_ON_DENY_LISTED_RATIOS 0x0040
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_ALLOW_ONLY_ON_ALLOWLISTED_RATIOS 0x0200
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_ALLOW_ON_BIGGER_THAN_BACK_BUFFER 0x0400
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_IGNORE_APP_PROFILE        0x1000
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_PATCH_ATTRIBUTE_EVAL_OFFSETS 0x4000
#define MAXWELL_B_SAMPLE_INTERLEAVE_SETTINGS_DEFAULT                   0x00001040


#define MAXWELL_B_TILEDCACHE_BUFFERINTERLEAVE_STRING                   "0x523dcc"
#define MAXWELL_B_TILEDCACHE_BUFFERINTERLEAVE_ID                       0x00523dcc
#define MAXWELL_B_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL              0 // OVERRIDE
#define MAXWELL_B_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                  0x00002313


#define MAXWELL_B_TILEDCACHE_CONTROL_STRING                            "0x523dcd"
#define MAXWELL_B_TILEDCACHE_CONTROL_ID                                0x00523dcd
#define MAXWELL_B_TILEDCACHE_CONTROL_OVERINSTALL                       0 // OVERRIDE
#define MAXWELL_B_TILEDCACHE_CONTROL_DEFAULT                           0x08080202


#define MAXWELL_B_TILEDCACHE_CONTROL_EXTENDED_STRING                   "0x523dde"
#define MAXWELL_B_TILEDCACHE_CONTROL_EXTENDED_ID                       0x00523dde
#define MAXWELL_B_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL              0 // OVERRIDE
#define MAXWELL_B_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                  0x00000008


#define MAXWELL_B_TILEDCACHE_L2_USAGE_STRING                           "0x523dd0"
#define MAXWELL_B_TILEDCACHE_L2_USAGE_ID                               0x00523dd0
#define MAXWELL_B_TILEDCACHE_L2_USAGE_OVERINSTALL                      0 // OVERRIDE
#define MAXWELL_B_TILEDCACHE_L2_USAGE_DEFAULT                          0.5f


#define MAXWELL_B_TILEDCACHE_STATETHRESHOLD_STRING                     "0x523dcf"
#define MAXWELL_B_TILEDCACHE_STATETHRESHOLD_ID                         0x00523dcf
#define MAXWELL_B_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_B_TILEDCACHE_STATETHRESHOLD_DEFAULT                    0x00080001


#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_STRING                     "45A109"
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_ID                         0x0045a109
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_OFF                        0x0
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_DISABLED                   0x0
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_ON                         0x1
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_ENABLED                    0x1
#define MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_DEFAULT                    MAXWELL_B_USE_LEGACY_SQRT_EXPANSION_OFF


#define MAXWELL_PRI_PES_VSC_L1_SWITCH_SM_LIMIT_STRING                  "0xfa34fc4"
#define MAXWELL_PRI_PES_VSC_L1_SWITCH_SM_LIMIT_ID                      0x00a34fc4
#define MAXWELL_PRI_PES_VSC_L1_SWITCH_SM_LIMIT_OVERINSTALL             0 // OVERRIDE


#define MAXWELL_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_5_STRING             "0xfa34887"
#define MAXWELL_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_5_ID                 0x00a34887
#define MAXWELL_PRI_PLTCG_LTCS_LTSS_TSTG_SET_MGMT_5_OVERINSTALL        0 // OVERRIDE


#define MAXWELL_UNOPT_LOD_CLAMP_STRING                                 "559109"
#define MAXWELL_UNOPT_LOD_CLAMP_ID                                     0x00559109
#define MAXWELL_UNOPT_LOD_CLAMP_OVERINSTALL                            0 // OVERRIDE
#define MAXWELL_UNOPT_LOD_CLAMP_OFF                                    0x56023627
#define MAXWELL_UNOPT_LOD_CLAMP_DISABLED                               0x56023627
#define MAXWELL_UNOPT_LOD_CLAMP_ON                                     0x37299934
#define MAXWELL_UNOPT_LOD_CLAMP_ENABLED                                0x37299934
#define MAXWELL_UNOPT_LOD_CLAMP_DEFAULT                                MAXWELL_UNOPT_LOD_CLAMP_OFF


#define MAXWELL_VDC_4TO2_DISABLE_STRING                                "0xce2888"
#define MAXWELL_VDC_4TO2_DISABLE_ID                                    0x00ce2888
#define MAXWELL_VDC_4TO2_DISABLE_OVERINSTALL                           0 // OVERRIDE
#define MAXWELL_VDC_4TO2_DISABLE_NORMAL                                0x00000000
#define MAXWELL_VDC_4TO2_DISABLE_FORCE                                 0x00000001


#define MAX_PENDING_CMD_BUFFERS_STRING                                 "79547226"
#define MAX_PENDING_CMD_BUFFERS_ID                                     0x00c63a79
#define MAX_PENDING_CMD_BUFFERS_OVERINSTALL                            0 // OVERRIDE
#define MAX_PENDING_CMD_BUFFERS_DEFAULT                                0x0


#define MAX_RENAMING_MEMORY_STRING                                     "99489574"
#define MAX_RENAMING_MEMORY_ID                                         0x00fe8cc0
#define MAX_RENAMING_MEMORY_OVERINSTALL                                0 // OVERRIDE


#define MAX_TILESIZE_BUFFERINTERLEAVE_OVERRIDE_STRING                  "0x222d1a"
#define MAX_TILESIZE_BUFFERINTERLEAVE_OVERRIDE_ID                      0x00523cc1
#define MAX_TILESIZE_BUFFERINTERLEAVE_OVERRIDE_OVERINSTALL             0 // OVERRIDE
#define MAX_TILESIZE_BUFFERINTERLEAVE_OVERRIDE_DEFAULT                 0x3431C


#define MB_DisableVideoLink_STRING                                     "DisableVideoLink"
#define MB_DisableVideoLink_ID                                         0x00e107d0
#define MB_DisableVideoLink_OVERINSTALL                                0 // OVERRIDE
#define MB_DisableVideoLink_OFF                                        0
#define MB_DisableVideoLink_DISABLED                                   0
#define MB_DisableVideoLink_FALSE                                      0
#define MB_DisableVideoLink_0                                          0
#define MB_DisableVideoLink_ON                                         1
#define MB_DisableVideoLink_ENABLED                                    1
#define MB_DisableVideoLink_TRUE                                       1
#define MB_DisableVideoLink_1                                          1


#define MC2WAYFALLBACK_STRING                                          "5656761"
#define MC2WAYFALLBACK_ID                                              0x00b29575
#define MC2WAYFALLBACK_OVERINSTALL                                     0 // OVERRIDE
#define MC2WAYFALLBACK_STATIC                                          0x56856345
#define MC2WAYFALLBACK_DYNAMIC                                         0x61671064
#define MC2WAYFALLBACK_OFF                                             0x34214578
#define MC2WAYFALLBACK_TEST                                            0x23CAE348
#define MC2WAYFALLBACK_DEFAULT                                         MC2WAYFALLBACK_DYNAMIC


#define MCAPPSPECIFICHACKS_STRING                                      "6428545A"
#define MCAPPSPECIFICHACKS_ID                                          0x00a0674a
#define MCAPPSPECIFICHACKS_OVERINSTALL                                 0 // OVERRIDE
#define MCAPPSPECIFICHACKS_NONE                                        0x00000000
#define MCAPPSPECIFICHACKS_DISCARD_ON_NOT_EQUALLY_DIRTY_CUBE_MIP_RTT   0x00000001
#define MCAPPSPECIFICHACKS_IGNORE_DISCARD_SRT                          0x00000002
#define MCAPPSPECIFICHACKS_DO_RESOLVE_ON_RTT_MATCHED_PRIMARY           0x00000004
#define MCAPPSPECIFICHACKS_RESERVED3                                   0x00000008
#define MCAPPSPECIFICHACKS_RESERVED4                                   0x00000010
#define MCAPPSPECIFICHACKS_RESERVED5                                   0x00000020
#define MCAPPSPECIFICHACKS_CRYSIS2_HACK_POSTMSAAEDGEFILTERNV_OVERRIDE  0x00000040
#define MCAPPSPECIFICHACKS_RESERVED7                                   0x00000080
#define MCAPPSPECIFICHACKS_FORCE_REPORT_NO_SLI_SUPPORT_FROM_NVAPI      0x00000100
#define MCAPPSPECIFICHACKS_RESERVED9                                   0x00000200
#define MCAPPSPECIFICHACKS_RESERVED10                                  0x00000400
#define MCAPPSPECIFICHACKS_RESERVED11                                  0x00000800
#define MCAPPSPECIFICHACKS_RESERVED12                                  0x00001000
#define MCAPPSPECIFICHACKS_RESERVED13                                  0x00002000
#define MCAPPSPECIFICHACKS_RESERVED14                                  0x00004000
#define MCAPPSPECIFICHACKS_RESERVED15                                  0x00008000
#define MCAPPSPECIFICHACKS_RESERVED16                                  0x00010000
#define MCAPPSPECIFICHACKS_RESERVED17                                  0x00020000
#define MCAPPSPECIFICHACKS_RESERVED18                                  0x00040000
#define MCAPPSPECIFICHACKS_RESERVED19                                  0x00080000
#define MCAPPSPECIFICHACKS_RESERVED20                                  0x00100000
#define MCAPPSPECIFICHACKS_RESERVED21                                  0x00200000
#define MCAPPSPECIFICHACKS_RESERVED22                                  0x00400000
#define MCAPPSPECIFICHACKS_RESERVED23                                  0x00800000
#define MCAPPSPECIFICHACKS_RESERVED24                                  0x01000000
#define MCAPPSPECIFICHACKS_RESERVED25                                  0x02000000
#define MCAPPSPECIFICHACKS_RESERVED26                                  0x04000000
#define MCAPPSPECIFICHACKS_RESERVED27                                  0x08000000
#define MCAPPSPECIFICHACKS_RESERVED28                                  0x10000000
#define MCAPPSPECIFICHACKS_RESERVED29                                  0x20000000
#define MCAPPSPECIFICHACKS_RESERVED30                                  0x40000000
#define MCAPPSPECIFICHACKS_RESERVED31                                  0x80000000
#define MCAPPSPECIFICHACKS_DEFAULT                                     MCAPPSPECIFICHACKS_NONE


#define MCAPPSPECIFICHACKS10_STRING                                    "64285456"
#define MCAPPSPECIFICHACKS10_ID                                        0x00a06746
#define MCAPPSPECIFICHACKS10_OVERINSTALL                               0 // OVERRIDE
#define MCAPPSPECIFICHACKS10_NONE                                      0x00000000
#define MCAPPSPECIFICHACKS10_DO_NOT_DISCARD_ON_SCREENSIZE_A2B10G10R10_RTT 0x00000001
#define MCAPPSPECIFICHACKS10_SKIP_TINY_TEXTURE_RESOLVE_ON_BLITTING     0x00000002
#define MCAPPSPECIFICHACKS10_FORCE_RESOLVE_ON_SECONDARY_GPU_FOR_SHARED_RESOURCES 0x00000004
#define MCAPPSPECIFICHACKS10_IGNORE_READ_LOCK_FOR_STAGING_TEXTURES     0x00000008
#define MCAPPSPECIFICHACKS10_EARLY_PUSH_ALL_SUBRESOURCES               0x00000010
#define MCAPPSPECIFICHACKS10_SKIP_NOSUBRES_RTT_BUT_TINY_RESOLVE_ON_TEXTURING 0x00000020
#define MCAPPSPECIFICHACKS10_CRYSIS2_HACK_POSTMSAAEDGEFILTERNV_OVERRIDE 0x00000040
#define MCAPPSPECIFICHACKS10_DO_NOT_DISCARD_SMALL_COMPUTE              0x00000080
#define MCAPPSPECIFICHACKS10_FORCE_REPORT_NO_SLI_SUPPORT_FROM_NVAPI    0x00000100
#define MCAPPSPECIFICHACKS10_DO_NOT_DISCARD_ON_MIDSIZE_TEXTURE_ABGR8_RTT 0x00000200
#define MCAPPSPECIFICHACKS10_DISCARD_ON_TEXTURING_AFTER_BLIT_FOR_SCREENSIZE_RTT 0x00000400
#define MCAPPSPECIFICHACKS10_DISCARD_ON_COMPUTE_1D                     0x00000800
#define MCAPPSPECIFICHACKS10_FC_GPULT_BG                               0x00001000
#define MCAPPSPECIFICHACKS10_DISCARD_ON_RESOURCES_WITH_SUBRESOURCES_GPU_COUNT 0x00002000
#define MCAPPSPECIFICHACKS10_ACIV_LOCK_WAR                             0x00004000
#define MCAPPSPECIFICHACKS10_ALLOW_P2P_FOR_COMPRESSED_TEXTURES         0x00008000
#define MCAPPSPECIFICHACKS10_RESPECT_SYNCS_FROSTBITE_SPECIFIC          0x00010000
#define MCAPPSPECIFICHACKS10_DO_SYNC_ON_BIND_FOR_SQUARE_TYPELESS_R8_R32_BGRA8_RTT 0x00020000
#define MCAPPSPECIFICHACKS10_DO_NOT_REPORT_SLI_FOR_MOSAIC_UNTIL_IN_AFR 0x00040000
#define MCAPPSPECIFICHACKS10_DO_SYNC_ON_BIND_FOR_SQUARE_ABGR16F_0x100__RTT 0x00080000
#define MCAPPSPECIFICHACKS10_ALLOW_BF1_SYNCS                           0x00100000
#define MCAPPSPECIFICHACKS10_DO_SYNC_ON_BIND_FOR_3D_RTT                0x00200000
#define MCAPPSPECIFICHACKS10_DO_SYNC_ON_BIND_FOR_SQUARE_RGBA_ABGR_0x100_0x200_RTT 0x00400000
#define MCAPPSPECIFICHACKS10_DISCARD_ON_R11G11B10_FLOAT_RT             0x00800000
#define MCAPPSPECIFICHACKS10_ALLOW_RFTA_SYNCS                          0x01000000
#define MCAPPSPECIFICHACKS10_DISCARD_ON_NVAPI_SYNC_FOR_SCREENSIZE_RTT  0x02000000
#define MCAPPSPECIFICHACKS10_RESPECT_PRIMARY_DISCARD_ON_PRESENT        0x04000000
#define MCAPPSPECIFICHACKS10_DISABLE_COPY_TRACKER_SWAPPING             0x08000000
#define MCAPPSPECIFICHACKS10_DO_SYNC_ON_SCREENSIZE_R11G11B10_FLOAT     0x10000000
#define MCAPPSPECIFICHACKS10_DISCARD_ON_NVAPI_SYNC_FOR_SQUARE_RTT_0x400 0x20000000
#define MCAPPSPECIFICHACKS10_ALLOW_JWE_SYNCS                           0x40000000
#define MCAPPSPECIFICHACKS10_RESERVED31                                0x80000000
#define MCAPPSPECIFICHACKS10_DEFAULT                                   MCAPPSPECIFICHACKS10_NONE


#define MCAPPSPECIFICHACKS12_STRING                                    "642a08746"
#define MCAPPSPECIFICHACKS12_ID                                        0x00a08746
#define MCAPPSPECIFICHACKS12_OVERINSTALL                               0 // OVERRIDE
#define MCAPPSPECIFICHACKS12_NONE                                      0x00000000
#define MCAPPSPECIFICHACKS12_DETECT_FABLE_SHADOWS                      0x00000001
#define MCAPPSPECIFICHACKS12_DISCARD_200x100_R32                       0x00000002
#define MCAPPSPECIFICHACKS12_FORCE_PUSH_20x20x20x28_VOL                0x00000004
#define MCAPPSPECIFICHACKS12_DISCARD_ON_256K_BUFFERS                   0x00000008
#define MCAPPSPECIFICHACKS12_AVOID_DISCARD_SELECTED_FABLE_RESOURCES    0x00000010
#define MCAPPSPECIFICHACKS12_FORCE_HOSTMEM_ON_1MB_1D_FMT_UNKNOWN_IN_NO_P2P 0x00000020
#define MCAPPSPECIFICHACKS12_RESERVED6                                 0x00000040
#define MCAPPSPECIFICHACKS12_RESERVED7                                 0x00000080
#define MCAPPSPECIFICHACKS12_RESERVED8                                 0x00000100
#define MCAPPSPECIFICHACKS12_EARLY_PUSH_OF_INFREQUENTLY_WRITTEN_RESOURCES 0x00000200
#define MCAPPSPECIFICHACKS12_RESERVED10                                0x00000400
#define MCAPPSPECIFICHACKS12_RESERVED11                                0x00000800
#define MCAPPSPECIFICHACKS12_RESERVED12                                0x00001000
#define MCAPPSPECIFICHACKS12_FORCE_RESOLVE_ON_SECONDARY_GPU_FOR_SHARED_RESOURCES 0x00002000
#define MCAPPSPECIFICHACKS12_RESERVED14                                0x00004000
#define MCAPPSPECIFICHACKS12_RESERVED15                                0x00008000
#define MCAPPSPECIFICHACKS12_RESERVED16                                0x00010000
#define MCAPPSPECIFICHACKS12_RESERVED17                                0x00020000
#define MCAPPSPECIFICHACKS12_RESERVED18                                0x00040000
#define MCAPPSPECIFICHACKS12_RESERVED19                                0x00080000
#define MCAPPSPECIFICHACKS12_RESERVED20                                0x00100000
#define MCAPPSPECIFICHACKS12_RESERVED21                                0x00200000
#define MCAPPSPECIFICHACKS12_RESERVED22                                0x00400000
#define MCAPPSPECIFICHACKS12_RESERVED23                                0x00800000
#define MCAPPSPECIFICHACKS12_RESERVED24                                0x01000000
#define MCAPPSPECIFICHACKS12_RESERVED25                                0x02000000
#define MCAPPSPECIFICHACKS12_RESERVED26                                0x04000000
#define MCAPPSPECIFICHACKS12_RESERVED27                                0x08000000
#define MCAPPSPECIFICHACKS12_RESERVED28                                0x10000000
#define MCAPPSPECIFICHACKS12_RESERVED29                                0x20000000
#define MCAPPSPECIFICHACKS12_RESERVED30                                0x40000000
#define MCAPPSPECIFICHACKS12_RESERVED31                                0x80000000
#define MCAPPSPECIFICHACKS12_DEFAULT                                   MCAPPSPECIFICHACKS12_NONE


#define MCBRIDGELESS_CE_SEMAPHORE_HACK_STRING                          "52167588"
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_ID                              0x00db3872
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_OVERINSTALL                     0 // OVERRIDE
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_OFF                             0x0
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_DISABLED                        0x0
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_ON                              0x1
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_ENABLED                         0x1
#define MCBRIDGELESS_CE_SEMAPHORE_HACK_DEFAULT                         MCBRIDGELESS_CE_SEMAPHORE_HACK_ON


#define MCBROADCASTRENDERINGMODE_STRING                                "45423d4f"
#define MCBROADCASTRENDERINGMODE_ID                                    0x008d624b
#define MCBROADCASTRENDERINGMODE_OVERINSTALL                           0 // OVERRIDE
#define MCBROADCASTRENDERINGMODE_OFF                                   0
#define MCBROADCASTRENDERINGMODE_DISABLED                              0
#define MCBROADCASTRENDERINGMODE_ON                                    1
#define MCBROADCASTRENDERINGMODE_ENABLED                               1
#define MCBROADCASTRENDERINGMODE_DEFAULT                               MCBROADCASTRENDERINGMODE_OFF


#define MCBROADCASTVIDEO_STRING                                        "45420d4f"
#define MCBROADCASTVIDEO_ID                                            0x008d624e
#define MCBROADCASTVIDEO_OVERINSTALL                                   0 // OVERRIDE
#define MCBROADCASTVIDEO_BROADCAST_POSTPROCESS                         0x01
#define MCBROADCASTVIDEO_DEFAULT                                       0


#define MCCOMPAT10_STRING                                              "64286456"
#define MCCOMPAT10_ID                                                  0x00a06946
#define MCCOMPAT10_OVERINSTALL                                         0 // OVERRIDE
#define MCCOMPAT10_AUTOSELECT                                          0x00000000
#define MCCOMPAT10_FORCE_2AFR                                          0x00000001
#define MCCOMPAT10_DISABLE_SLI                                         0x00000004
#define MCCOMPAT10_FORCE_4AFR                                          0x00000005
#define MCCOMPAT10_FORCE_3AFR                                          0x00000006
#define MCCOMPAT10_SLI_MODE_MASK                                       0x00000007
#define MCCOMPAT10_AFR_ONLY_APP                                        0x00000008
#define MCCOMPAT10_DISCARD_ON_RENDERING_FOR_TEXTURES                   0x00000010
#define MCCOMPAT10_DISCARD_ON_RENDERING_FOR_NON_TEXTURES               0x00000020
#define MCCOMPAT10_DISCARD_ZBUF_DATA_ON_RENDERING                      0x00000040
#define MCCOMPAT10_DISCARD_STENCIL_DATA_ON_RENDERING                   0x00000080
#define MCCOMPAT10_AFR2_FLAGS                                          0x000000F0
#define MCCOMPAT10_DISCARD_ON_STREAM_OUT                               0x00000100
#define MCCOMPAT10_SKIP_DEFERRED_RESOLVE_OF_BOUND_VIEWS                0x00000200
#define MCCOMPAT10_SKIP_RESOLVE_ON_VERTEX_BUFFER                       0x00000400
#define MCCOMPAT10_SKIP_NON_HDR_TEXTURE_RESOLVE_MATCHED_PRIMARY        0x00000800
#define MCCOMPAT10_SKIP_TEXTURE_RESOLVE_ON_TEXTURING                   0x00001000
#define MCCOMPAT10_SKIP_TEXTURE_RESOLVE_MATCHED_PRIMARY                0x00002000
#define MCCOMPAT10_SKIP_ALL_BUT_TINY_TEXTURE_RESOLVE_ON_TEXTURING      0x00004000
#define MCCOMPAT10_SKIP_TEXTURE_RESOLVE_ON_MIDSIZE_TEXTURES            0x00008000
#define MCCOMPAT10_DISCARD_ON_BLIT_DESTNATION                          0x00010000
#define MCCOMPAT10_RETURN_EVENT_QUERY_SUCCESS_IMMEDIATELY              0x00020000
#define MCCOMPAT10_RETURN_OCCLUSION_QUERY_SUCCESS_IMMEDIATELY          0x00040000
#define MCCOMPAT10_DISCARD_SRC_ON_AA_RESOLVE                           0x00080000
#define MCCOMPAT10_SKIP_INFREQUENT_TEXTURE_RESOLVES                    0x00100000
#define MCCOMPAT10_CLEAR_DISCARDED_TEXTURES                            0x00200000
#define MCCOMPAT10_DISCARD_ON_HUGE_ZB_FOR_TEXTURING                    0x00400000
#define MCCOMPAT10_APPBUG_FORCE_FLIPCHAIN_SYNC                         0x00800000
#define MCCOMPAT10_RESERVED24                                          0x01000000
#define MCCOMPAT10_ASSUME_NOINTERFRAME_BLITS                           0x02000000
#define MCCOMPAT10_DISCARD_ON_RESOURCES_WITH_SUBRESOURCES              0x04000000
#define MCCOMPAT10_DISCARD_ON_COMPUTE                                  0x08000000
#define MCCOMPAT10_RESERVED28                                          0x10000000
#define MCCOMPAT10_SKIP_TEXTURE_RESOLVE_ON_COMPUTE_TEXTURING           0x20000000
#define MCCOMPAT10_LASTMINUTE_FIXES                                    0x40000000
#define MCCOMPAT10_OVERRIDE_BIT                                        0x80000000
#define MCCOMPAT10_DEFAULT                                             MCCOMPAT10_DISABLE_SLI


#define MCCOMPAT10_BROADCAST_STRING                                    "6428645B"
#define MCCOMPAT10_BROADCAST_ID                                        0x00a0694b
#define MCCOMPAT10_BROADCAST_OVERINSTALL                               0 // OVERRIDE
#define MCCOMPAT10_BROADCAST_NONE                                      0x00000000
#define MCCOMPAT10_BROADCAST_DYNAMIC_BROADCAST_RENDER_TO_TEXTURE       0x00000001
#define MCCOMPAT10_BROADCAST_DYNAMIC_BROADCAST_TO_TEXTURES_WITH_SUBRESOURCES_ONLY 0x00000002
#define MCCOMPAT10_BROADCAST_ENABLE_BLIT_BASED_BROADCAST_STATE_CHANGES 0x00000004
#define MCCOMPAT10_BROADCAST_DYNAMIC_BROADCAST_RENDER_TO_UAVS          0x00000008
#define MCCOMPAT10_BROADCAST_RESERVED6                                 0x00000020
#define MCCOMPAT10_BROADCAST_RESERVED7                                 0x00000040
#define MCCOMPAT10_BROADCAST_RESERVED8                                 0x00000080
#define MCCOMPAT10_BROADCAST_STATIC_BROADCAST_TO_TEXTURES_WITH_SUBRESOURCES 0x00000100
#define MCCOMPAT10_BROADCAST_STATIC_BROADCAST_TO_1LINE_32BIT_TEXTURES  0x00000200
#define MCCOMPAT10_BROADCAST_RESERVED11                                0x00000400
#define MCCOMPAT10_BROADCAST_RESERVED12                                0x00000800
#define MCCOMPAT10_BROADCAST_LIMIT_BROADCAST_SPREADING_TO_ONE_LEVEL    0x00001000
#define MCCOMPAT10_BROADCAST_STATIC_BROADCAST_TO_SQUARE_R16F_RTT       0x00002000
#define MCCOMPAT10_BROADCAST_STATIC_BROADCAST_TO_SQUARE_G32R32F_RTT    0x00004000
#define MCCOMPAT10_BROADCAST_RESERVED16                                0x00008000
#define MCCOMPAT10_BROADCAST_RESERVED17                                0x00010000
#define MCCOMPAT10_BROADCAST_RESERVED18                                0x00020000
#define MCCOMPAT10_BROADCAST_RESERVED19                                0x00040000
#define MCCOMPAT10_BROADCAST_RESERVED20                                0x00080000
#define MCCOMPAT10_BROADCAST_RESERVED21                                0x00100000
#define MCCOMPAT10_BROADCAST_RESERVED22                                0x00200000
#define MCCOMPAT10_BROADCAST_RESERVED23                                0x00400000
#define MCCOMPAT10_BROADCAST_RESERVED24                                0x00800000
#define MCCOMPAT10_BROADCAST_RESERVED25                                0x01000000
#define MCCOMPAT10_BROADCAST_RESERVED26                                0x02000000
#define MCCOMPAT10_BROADCAST_RESERVED27                                0x04000000
#define MCCOMPAT10_BROADCAST_RESERVED28                                0x08000000
#define MCCOMPAT10_BROADCAST_RESERVED29                                0x10000000
#define MCCOMPAT10_BROADCAST_RESERVED30                                0x20000000
#define MCCOMPAT10_BROADCAST_RESERVED31                                0x40000000
#define MCCOMPAT10_BROADCAST_RESERVED32                                0x80000000
#define MCCOMPAT10_BROADCAST_DEFAULT                                   MCCOMPAT10_BROADCAST_NONE


#define MCCOMPAT12_STRING                                              "64a04746"
#define MCCOMPAT12_ID                                                  0x00a04746
#define MCCOMPAT12_OVERINSTALL                                         0 // OVERRIDE
#define MCCOMPAT12_AUTOSELECT                                          0x00000000
#define MCCOMPAT12_FORCE_2AFR                                          0x00000001
#define MCCOMPAT12_DISABLE_SLI                                         0x00000004
#define MCCOMPAT12_FORCE_4AFR                                          0x00000005
#define MCCOMPAT12_FORCE_3AFR                                          0x00000006
#define MCCOMPAT12_SLI_MODE_MASK                                       0x00000007
#define MCCOMPAT12_RESERVED03                                          0x00000008
#define MCCOMPAT12_DISCARD_RT_ON_RENDERING                             0x00000010
#define MCCOMPAT12_DISCARD_DS_ON_RENDERING                             0x00000020
#define MCCOMPAT12_RESERVED06                                          0x00000040
#define MCCOMPAT12_DISABLE_DESCRIPTOR_PARSING                          0x00000080
#define MCCOMPAT12_AFR2_FLAGS                                          0x000000F0
#define MCCOMPAT12_DISCARD_ON_BLIT_DST                                 0x00000100
#define MCCOMPAT12_DISCARD_ON_UAV                                      0x00000200
#define MCCOMPAT12_DISCARD_IN_WRITE_STATE_ON_PRESENT                   0x00000400
#define MCCOMPAT12_RESERVED11                                          0x00000800
#define MCCOMPAT12_RESERVED12                                          0x00001000
#define MCCOMPAT12_RESERVED13                                          0x00002000
#define MCCOMPAT12_RESERVED14                                          0x00004000
#define MCCOMPAT12_RESERVED15                                          0x00008000
#define MCCOMPAT12_RESERVED16                                          0x00010000
#define MCCOMPAT12_RESERVED17                                          0x00020000
#define MCCOMPAT12_RESERVED18                                          0x00040000
#define MCCOMPAT12_RESERVED19                                          0x00080000
#define MCCOMPAT12_RESERVED20                                          0x00100000
#define MCCOMPAT12_RESERVED21                                          0x00200000
#define MCCOMPAT12_RESERVED22                                          0x00400000
#define MCCOMPAT12_RESERVED23                                          0x00800000
#define MCCOMPAT12_RESERVED24                                          0x01000000
#define MCCOMPAT12_RESERVED25                                          0x02000000
#define MCCOMPAT12_RESERVED26                                          0x04000000
#define MCCOMPAT12_FORCE_PUSH_OF_ALL_WRITTEN_RESOURCES                 0x08000000
#define MCCOMPAT12_RESERVED28                                          0x10000000
#define MCCOMPAT12_EARLY_PUSH_1x1xR32                                  0x20000000
#define MCCOMPAT12_LASTMINUTE_FIXES                                    0x40000000
#define MCCOMPAT12_OVERRIDE_BIT                                        0x80000000
#define MCCOMPAT12_DEFAULT                                             MCCOMPAT12_AUTOSELECT


#define MCCOMPAT12_BROADCAST_STRING                                    "64a0394b"
#define MCCOMPAT12_BROADCAST_ID                                        0x00a0394b
#define MCCOMPAT12_BROADCAST_OVERINSTALL                               0 // OVERRIDE
#define MCCOMPAT12_BROADCAST_NONE                                      0x00000000
#define MCCOMPAT12_BROADCAST_RESERVED01                                0x00000001
#define MCCOMPAT12_BROADCAST_RESERVED02                                0x00000002
#define MCCOMPAT12_BROADCAST_RESERVED03                                0x00000004
#define MCCOMPAT12_BROADCAST_RESERVED04                                0x00000008
#define MCCOMPAT12_BROADCAST_RESERVED05                                0x00000010
#define MCCOMPAT12_BROADCAST_RESERVED06                                0x00000020
#define MCCOMPAT12_BROADCAST_RESERVED07                                0x00000040
#define MCCOMPAT12_BROADCAST_RESERVED08                                0x00000080
#define MCCOMPAT12_BROADCAST_RESERVED09                                0x00000100
#define MCCOMPAT12_BROADCAST_RESERVED10                                0x00000200
#define MCCOMPAT12_BROADCAST_RESERVED11                                0x00000400
#define MCCOMPAT12_BROADCAST_RESERVED12                                0x00000800
#define MCCOMPAT12_BROADCAST_RESERVED13                                0x00001000
#define MCCOMPAT12_BROADCAST_RESERVED14                                0x00002000
#define MCCOMPAT12_BROADCAST_RESERVED15                                0x00004000
#define MCCOMPAT12_BROADCAST_RESERVED16                                0x00008000
#define MCCOMPAT12_BROADCAST_RESERVED17                                0x00010000
#define MCCOMPAT12_BROADCAST_RESERVED18                                0x00020000
#define MCCOMPAT12_BROADCAST_RESERVED19                                0x00040000
#define MCCOMPAT12_BROADCAST_RESERVED20                                0x00080000
#define MCCOMPAT12_BROADCAST_RESERVED21                                0x00100000
#define MCCOMPAT12_BROADCAST_RESERVED22                                0x00200000
#define MCCOMPAT12_BROADCAST_RESERVED23                                0x00400000
#define MCCOMPAT12_BROADCAST_RESERVED24                                0x00800000
#define MCCOMPAT12_BROADCAST_RESERVED25                                0x01000000
#define MCCOMPAT12_BROADCAST_RESERVED26                                0x02000000
#define MCCOMPAT12_BROADCAST_RESERVED27                                0x04000000
#define MCCOMPAT12_BROADCAST_RESERVED28                                0x08000000
#define MCCOMPAT12_BROADCAST_RESERVED29                                0x10000000
#define MCCOMPAT12_BROADCAST_RESERVED30                                0x20000000
#define MCCOMPAT12_BROADCAST_FORCE_STATIC_BROADCAST_ON_SCREEN_SIZED_FP16 0x40000000
#define MCCOMPAT12_BROADCAST_FORCE_STATIC_BROADCAST_ON_400x400_NON_Z16 0x80000000
#define MCCOMPAT12_BROADCAST_DEFAULT                                   MCCOMPAT12_BROADCAST_NONE


#define MCCOMPAT_BROADCAST_STRING                                      "67207568"
#define MCCOMPAT_BROADCAST_ID                                          0x0095def9
#define MCCOMPAT_BROADCAST_OVERINSTALL                                 0 // OVERRIDE
#define MCCOMPAT_BROADCAST_NONE                                        0x00000000
#define MCCOMPAT_BROADCAST_RESERVED0                                   0x00000001
#define MCCOMPAT_BROADCAST_DYNAMIC_BROADCAST_RENDER_TO_TEXTURE         0x00000002
#define MCCOMPAT_BROADCAST_STICKY_BROADCAST                            0x00000004
#define MCCOMPAT_BROADCAST_PROPAGATE_BROADCAST_PROHIBITION_BETWEEN_RT_AND_ZB 0x00000008
#define MCCOMPAT_BROADCAST_STATIC_BROADCAST_CLEARS_TO_TEXTURE          0x00000010
#define MCCOMPAT_BROADCAST_STATIC_BROADCAST_RENDER_TO_TEXTURE          0x00000020
#define MCCOMPAT_BROADCAST_ALLOW_BROADCAST_ON_SMALLER_HDR_SURFACES     0x00000040
#define MCCOMPAT_BROADCAST_RESERVED4                                   0x00000080
#define MCCOMPAT_BROADCAST_USE_BROADCAST_FLAGS_FROM_RT_OR_ZB           0x00000100
#define MCCOMPAT_BROADCAST_FORCE_BROADCAST_ZB_CLEAR_IF_RT_IN_BROADCAST 0x00000200
#define MCCOMPAT_BROADCAST_RESERVED6                                   0x00000400
#define MCCOMPAT_BROADCAST_RESERVED7                                   0x00000800
#define MCCOMPAT_BROADCAST_IGNORE_DISCARD_ON_ZB_IF_RT_IN_BROADCAST     0x00001000
#define MCCOMPAT_BROADCAST_DISCARD_TEXTURING_SYNC_AFTER_BLIT_FROM_DISCARDABLE_SRC 0x00002000
#define MCCOMPAT_BROADCAST_RESERVED9                                   0x00004000
#define MCCOMPAT_BROADCAST_RESERVED10                                  0x00008000
#define MCCOMPAT_BROADCAST_BROADCAST_TO_CUBEMIP_TEXTURE                0x00010000
#define MCCOMPAT_BROADCAST_RESERVED11                                  0x00020000
#define MCCOMPAT_BROADCAST_RESERVED12                                  0x00040000
#define MCCOMPAT_BROADCAST_RESERVED13                                  0x00080000
#define MCCOMPAT_BROADCAST_BROADCAST_ON_ZB_IN_TEXTURE_ON_PARTIAL_SRT   0x00100000
#define MCCOMPAT_BROADCAST_BROADCAST_ON_STENCIL_WRITE                  0x00200000
#define MCCOMPAT_BROADCAST_RESERVED16                                  0x00400000
#define MCCOMPAT_BROADCAST_RESERVED17                                  0x00800000
#define MCCOMPAT_BROADCAST_RESERVED18                                  0x01000000
#define MCCOMPAT_BROADCAST_RESERVED19                                  0x02000000
#define MCCOMPAT_BROADCAST_RESERVED20                                  0x04000000
#define MCCOMPAT_BROADCAST_RESERVED21                                  0x08000000
#define MCCOMPAT_BROADCAST_RESERVED22                                  0x10000000
#define MCCOMPAT_BROADCAST_RESERVED23                                  0x20000000
#define MCCOMPAT_BROADCAST_RESERVED24                                  0x40000000
#define MCCOMPAT_BROADCAST_RESERVED25                                  0x80000000
#define MCCOMPAT_BROADCAST_DEFAULT                                     MCCOMPAT_BROADCAST_NONE


#define MCDEBUG_STRING                                                 "46428645"
#define MCDEBUG_ID                                                     0x00074510
#define MCDEBUG_OVERINSTALL                                            0 // OVERRIDE
#define MCDEBUG_OFF                                                    0
#define MCDEBUG_0                                                      0
#define MCDEBUG_AFR_RENDER_ALL                                         1
#define MCDEBUG_1                                                      1
#define MCDEBUG_AFR_RENDER_TEXTURE                                     2
#define MCDEBUG_2                                                      2
#define MCDEBUG_DEFAULT                                                MCDEBUG_OFF


#define MCDEBUG12_STRING                                               "d45672"
#define MCDEBUG12_ID                                                   0x00d45672
#define MCDEBUG12_OVERINSTALL                                          0 // OVERRIDE
#define MCDEBUG12_FORCE_NO_DISCARD                                     0x00000001
#define MCDEBUG12_FORCE_END_OF_FRAME_PUSH                              0x00000002
#define MCDEBUG12_ENABLE_DESCRIPTOR_PARSING                            0x00000010
#define MCDEBUG12_DISABLE_DESC_PARSING_FILTERING                       0x00000020
#define MCDEBUG12_DISABLE_EXPLICIT_UNICAST_CONTEXTS                    0x00000040
#define MCDEBUG12_DISABLE_UNICAST_P2H2P                                0x00000080
#define MCDEBUG12_DISABLE_UNICAST_SHADER_HEAPS                         0x00000100
#define MCDEBUG12_DEFAULT                                              MCDEBUG12_DISABLE_UNICAST_SHADER_HEAPS


#define MCDISABLEKMDP2P_STRING                                         "1f47621c"
#define MCDISABLEKMDP2P_ID                                             0x00ef3720
#define MCDISABLEKMDP2P_OVERINSTALL                                    0 // OVERRIDE
#define MCDISABLEKMDP2P_OFF                                            0x345fe064
#define MCDISABLEKMDP2P_DISABLED                                       0x345fe064
#define MCDISABLEKMDP2P_ON                                             0x245fe582
#define MCDISABLEKMDP2P_ENABLED                                        0x245fe582
#define MCDISABLEKMDP2P_DEFAULT                                        MCDISABLEKMDP2P_OFF


#define MCDISABLEP2H2P_STRING                                          "1fffffff"
#define MCDISABLEP2H2P_ID                                              0x00f0eb4a
#define MCDISABLEP2H2P_OVERINSTALL                                     0 // OVERRIDE
#define MCDISABLEP2H2P_OFF                                             0x345fe064
#define MCDISABLEP2H2P_DISABLED                                        0x345fe064
#define MCDISABLEP2H2P_ON                                              0x245fe582
#define MCDISABLEP2H2P_ENABLED                                         0x245fe582
#define MCDISABLEP2H2P_DEFAULT                                         MCDISABLEP2H2P_OFF


#define MCDISABLEP2P_STRING                                            "1ffffffe"
#define MCDISABLEP2P_ID                                                0x001b1e68
#define MCDISABLEP2P_OVERINSTALL                                       0 // OVERRIDE
#define MCDISABLEP2P_OFF                                               0x345fe064
#define MCDISABLEP2P_DISABLED                                          0x345fe064
#define MCDISABLEP2P_ON                                                0x245fe582
#define MCDISABLEP2P_ENABLED                                           0x245fe582
#define MCDISABLEP2P_DEFAULT                                           MCDISABLEP2P_OFF


#define MCENABLEUMA_STRING                                             "5226759b"
#define MCENABLEUMA_ID                                                 0x00745f25
#define MCENABLEUMA_OVERINSTALL                                        0 // OVERRIDE
#define MCENABLEUMA_OFF                                                0x24486422
#define MCENABLEUMA_DISABLED                                           0x24486422
#define MCENABLEUMA_ON                                                 0x13557917
#define MCENABLEUMA_ENABLED                                            0x13557917
#define MCENABLEUMA_DEFAULT                                            MCENABLEUMA_ON


#define MCENABLEUMA10_STRING                                           "52267599"
#define MCENABLEUMA10_ID                                               0x0051b006
#define MCENABLEUMA10_OVERINSTALL                                      0 // OVERRIDE
#define MCENABLEUMA10_OFF                                              0x24486420
#define MCENABLEUMA10_DISABLED                                         0x24486420
#define MCENABLEUMA10_ON                                               0x13557915
#define MCENABLEUMA10_ENABLED                                          0x13557915
#define MCENABLEUMA10_DEFAULT                                          MCENABLEUMA10_ON


#define MCEXPLICIT12_TIER_CONTROL_STRING                               "db4672"
#define MCEXPLICIT12_TIER_CONTROL_ID                                   0x00db4672
#define MCEXPLICIT12_TIER_CONTROL_OVERINSTALL                          0 // OVERRIDE
#define MCEXPLICIT12_TIER_CONTROL_NOT_SUPPORTED                        0x00000000
#define MCEXPLICIT12_TIER_CONTROL_TIER_1_EMULATED                      0x00000001
#define MCEXPLICIT12_TIER_CONTROL_TIER_1                               0x00000002
#define MCEXPLICIT12_TIER_CONTROL_TIER_2                               0x00000003
#define MCEXPLICIT12_TIER_CONTROL_TIER_3                               0x00000004
#define MCEXPLICIT12_TIER_CONTROL_DEFAULT                              MCEXPLICIT12_TIER_CONTROL_TIER_2


#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_STRING           "db4673"
#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_ID               0x00db4673
#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_OVERINSTALL      0 // OVERRIDE
#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_NOT_SUPPORTED    0x00000000
#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_TIER_1_EMULATED  0x00000001
#define MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_DEFAULT          MCEXPLICIT12_TIER_CONTROL_IF_NO_P2P_SUPPORTED_TIER_1_EMULATED


#define MCFORCEHOSTSTAGINGBUFFERSIZE_STRING                            "52267593"
#define MCFORCEHOSTSTAGINGBUFFERSIZE_ID                                0x00db3858
#define MCFORCEHOSTSTAGINGBUFFERSIZE_OVERINSTALL                       0 // OVERRIDE
#define MCFORCEHOSTSTAGINGBUFFERSIZE_DEFAULT                           0x40000


#define MCFORCEMIRRORED_STRING                                         "1ee22671"
#define MCFORCEMIRRORED_ID                                             0x00cdd40c
#define MCFORCEMIRRORED_OVERINSTALL                                    0 // OVERRIDE
#define MCFORCEMIRRORED_OFF                                            0x345fe064
#define MCFORCEMIRRORED_DISABLED                                       0x345fe064
#define MCFORCEMIRRORED_ON                                             0x245fe582
#define MCFORCEMIRRORED_ENABLED                                        0x245fe582
#define MCFORCEMIRRORED_DEFAULT                                        MCFORCEMIRRORED_OFF


#define MCFORCEP2PREAD_STRING                                          "f0d2d123"
#define MCFORCEP2PREAD_ID                                              0x00d781ca
#define MCFORCEP2PREAD_OVERINSTALL                                     0 // OVERRIDE
#define MCFORCEP2PREAD_OFF                                             0x43912743
#define MCFORCEP2PREAD_DISABLED                                        0x43912743
#define MCFORCEP2PREAD_ON                                              0x87457346
#define MCFORCEP2PREAD_ENABLED                                         0x87457346
#define MCFORCEP2PREAD_DEFAULT                                         MCFORCEP2PREAD_OFF


#define MCFORCE_FULL_P2P_VISIBILITY12_STRING                           "db2372"
#define MCFORCE_FULL_P2P_VISIBILITY12_ID                               0x00db2372
#define MCFORCE_FULL_P2P_VISIBILITY12_OVERINSTALL                      0 // OVERRIDE
#define MCFORCE_FULL_P2P_VISIBILITY12_OFF                              0
#define MCFORCE_FULL_P2P_VISIBILITY12_ON                               1
#define MCFORCE_FULL_P2P_VISIBILITY12_DEFAULT                          MCFORCE_FULL_P2P_VISIBILITY12_OFF


#define MCHOSTSTAGINGBUFFERSIZEHINT9_STRING                            "52278594"
#define MCHOSTSTAGINGBUFFERSIZEHINT9_ID                                0x00db3859
#define MCHOSTSTAGINGBUFFERSIZEHINT9_OVERINSTALL                       0 // OVERRIDE
#define MCHOSTSTAGINGBUFFERSIZEHINT9_DEFAULT                           0xc


#define MCINTERNALINDICATOR_STRING                                     "3286754A"
#define MCINTERNALINDICATOR_ID                                         0x00c84612
#define MCINTERNALINDICATOR_OVERINSTALL                                0 // OVERRIDE
#define MCINTERNALINDICATOR_SHOW_EXPLICIT_SLI_INDICATOR                0x00000001
#define MCINTERNALINDICATOR_DEFAULT                                    0


#define MCLINKINSTANCED_LIMIT_STRING                                   "5226759e"
#define MCLINKINSTANCED_LIMIT_ID                                       0x00db3857
#define MCLINKINSTANCED_LIMIT_OVERINSTALL                              0 // OVERRIDE
#define MCLINKINSTANCED_LIMIT_DEFAULT                                  0


#define MCP2PCAPOVERRIDE_STRING                                        "fd275624"
#define MCP2PCAPOVERRIDE_ID                                            0x00932dee
#define MCP2PCAPOVERRIDE_OVERINSTALL                                   0 // OVERRIDE
#define MCP2PCAPOVERRIDE_AUTO                                          0x43912743
#define MCP2PCAPOVERRIDE_OFF                                           0x43912743
#define MCP2PCAPOVERRIDE_0                                             0x43912743
#define MCP2PCAPOVERRIDE_FORCE_R_ON_W_ON                               0x87457346
#define MCP2PCAPOVERRIDE_FORCE_R_ON_W_OFF                              0x85278426
#define MCP2PCAPOVERRIDE_FORCE_R_OFF_W_ON                              0x43437463
#define MCP2PCAPOVERRIDE_FORCE_R_OFF_W_OFF                             0x68382925
#define MCP2PCAPOVERRIDE_DEFAULT                                       MCP2PCAPOVERRIDE_AUTO


#define MCP2PRESOLVE_CONFIG_STRING                                     "db4791"
#define MCP2PRESOLVE_CONFIG_ID                                         0x00db4791
#define MCP2PRESOLVE_CONFIG_OVERINSTALL                                0 // OVERRIDE
#define MCP2PRESOLVE_CONFIG_DEFAULT                                    0x00000000
#define MCP2PRESOLVE_CONFIG_FORCE_P2P_WRITES                           0x00000001
#define MCP2PRESOLVE_CONFIG_FORCE_P2P_READS                            0x00000002
#define MCP2PRESOLVE_CONFIG_FORCE_ENABLE_SW_SEMAPHORES                 0x00000004


#define MCP2PSTAGEHEAP_STRING                                          "66524598"
#define MCP2PSTAGEHEAP_ID                                              0x00cb8791
#define MCP2PSTAGEHEAP_OVERINSTALL                                     0 // OVERRIDE
#define MCP2PSTAGEHEAP_AUTO                                            0
#define MCP2PSTAGEHEAP_HOST                                            1
#define MCP2PSTAGEHEAP_VID                                             2
#define MCP2PSTAGEHEAP_VIDREAD                                         3
#define MCP2PSTAGEHEAP_VIDWRITE                                        4
#define MCP2PSTAGEHEAP_DEFAULT                                         MCP2PSTAGEHEAP_AUTO


#define MCP2PTHRESHOLD_SAMPLES_STRING                                  "52167593"
#define MCP2PTHRESHOLD_SAMPLES_ID                                      0x00db3868
#define MCP2PTHRESHOLD_SAMPLES_OVERINSTALL                             0 // OVERRIDE
#define MCP2PTHRESHOLD_SAMPLES_DEFAULT                                 0


#define MCP2P_GPUS_SYNCHRONIZER_STRING                                 "52111693"
#define MCP2P_GPUS_SYNCHRONIZER_ID                                     0x007baa68
#define MCP2P_GPUS_SYNCHRONIZER_OVERINSTALL                            0 // OVERRIDE
#define MCP2P_GPUS_SYNCHRONIZER_OFF                                    0
#define MCP2P_GPUS_SYNCHRONIZER_DISABLED                               0
#define MCP2P_GPUS_SYNCHRONIZER_ON                                     1
#define MCP2P_GPUS_SYNCHRONIZER_ENABLED                                1
#define MCP2P_GPUS_SYNCHRONIZER_DEFAULT                                MCP2P_GPUS_SYNCHRONIZER_ON


#define MCPRESENT_CONFIG_STRING                                        "db4691"
#define MCPRESENT_CONFIG_ID                                            0x00db4691
#define MCPRESENT_CONFIG_OVERINSTALL                                   0 // OVERRIDE
#define MCPRESENT_CONFIG_DEFAULT                                       0x00000000
#define MCPRESENT_CONFIG_FORCE_P2P_WRITES                              0x00000001
#define MCPRESENT_CONFIG_FORCE_P2P_READS                               0x00000002
#define MCPRESENT_CONFIG_INVERT_PLATFORM_CHOICE                        0x00000003


#define MCSLIAA3WAYFALLBACK_STRING                                     "f0d2d124"
#define MCSLIAA3WAYFALLBACK_ID                                         0x00d781cb
#define MCSLIAA3WAYFALLBACK_OVERINSTALL                                0 // OVERRIDE
#define MCSLIAA3WAYFALLBACK_OFF                                        0x43912744
#define MCSLIAA3WAYFALLBACK_DISABLED                                   0x43912744
#define MCSLIAA3WAYFALLBACK_ON                                         0x87457347
#define MCSLIAA3WAYFALLBACK_ENABLED                                    0x87457347
#define MCSLIAA3WAYFALLBACK_DEFAULT                                    MCSLIAA3WAYFALLBACK_OFF


#define MCSTAGEDYNAMICTEXTUREMAPS_STRING                               "52362cd9"
#define MCSTAGEDYNAMICTEXTUREMAPS_ID                                   0x001e5c15
#define MCSTAGEDYNAMICTEXTUREMAPS_OVERINSTALL                          0 // OVERRIDE
#define MCSTAGEDYNAMICTEXTUREMAPS_OFF                                  0x64889adf
#define MCSTAGEDYNAMICTEXTUREMAPS_DISABLED                             0x64889adf
#define MCSTAGEDYNAMICTEXTUREMAPS_ON                                   0x033fda37
#define MCSTAGEDYNAMICTEXTUREMAPS_ENABLED                              0x033fda37
#define MCSTAGEDYNAMICTEXTUREMAPS_DEFAULT                              MCSTAGEDYNAMICTEXTUREMAPS_ON


#define MCTESTSFRSPLITLINE_STRING                                      "93229056"
#define MCTESTSFRSPLITLINE_ID                                          0x0086d966
#define MCTESTSFRSPLITLINE_OVERINSTALL                                 0 // OVERRIDE
#define MCTESTSFRSPLITLINE_OFF                                         0xf6712345
#define MCTESTSFRSPLITLINE_DISABLED                                    0xf6712345
#define MCTESTSFRSPLITLINE_ON                                          0x18223234
#define MCTESTSFRSPLITLINE_ENABLED                                     0x18223234
#define MCTESTSFRSPLITLINE_DEFAULT                                     MCTESTSFRSPLITLINE_OFF


#define MCTESTSLIAA_STRING                                             "5226759d"
#define MCTESTSLIAA_ID                                                 0x00e6b48f
#define MCTESTSLIAA_OVERINSTALL                                        0 // OVERRIDE
#define MCTESTSLIAA_OFF                                                0x24486424
#define MCTESTSLIAA_DISABLED                                           0x24486424
#define MCTESTSLIAA_ON                                                 0x13557919
#define MCTESTSLIAA_ENABLED                                            0x13557919
#define MCTESTSLIAA_DEFAULT                                            MCTESTSLIAA_OFF


#define MCUNICASTSUBMIT_STRING                                         "7582fb34"
#define MCUNICASTSUBMIT_ID                                             0x00d0e7f3
#define MCUNICASTSUBMIT_OVERINSTALL                                    0 // OVERRIDE
#define MCUNICASTSUBMIT_OFF                                            0x24486421
#define MCUNICASTSUBMIT_DISABLED                                       0x24486421
#define MCUNICASTSUBMIT_ON                                             0x13557916
#define MCUNICASTSUBMIT_ENABLED                                        0x13557916
#define MCUNICASTSUBMIT_DEFAULT                                        MCUNICASTSUBMIT_OFF


#define MCUSEBLITRESOLVES_STRING                                       "1fffffee"
#define MCUSEBLITRESOLVES_ID                                           0x0091a7e8
#define MCUSEBLITRESOLVES_OVERINSTALL                                  0 // OVERRIDE
#define MCUSEBLITRESOLVES_OFF                                          0x00000000
#define MCUSEBLITRESOLVES_DISABLED                                     0x00000000
#define MCUSEBLITRESOLVES_ON                                           0x00000001
#define MCUSEBLITRESOLVES_ENABLED                                      0x00000001
#define MCUSEBLITRESOLVES_DEFAULT                                      MCUSEBLITRESOLVES_ON


#define MCWDDMV2_CONTROL_STRING                                        "db4772"
#define MCWDDMV2_CONTROL_ID                                            0x00db4772
#define MCWDDMV2_CONTROL_OVERINSTALL                                   0 // OVERRIDE
#define MCWDDMV2_CONTROL_DISABLE_IFLIP                                 0x00000002
#define MCWDDMV2_CONTROL_DISABLE_RRI_FOR_IFLIP                         0x00000004
#define MCWDDMV2_CONTROL_DISABLE_DEFDESTROY_FOR_IFLIP                  0x00000008
#define MCWDDMV2_CONTROL_DISABLE_IFLIP_DX9                             0x00000010
#define MCWDDMV2_CONTROL_DISABLE_EXPLICIT_DX12_WAR                     0x00000040
#define MCWDDMV2_CONTROL_FORCE_SYNC_CD_FOR_IFLIP                       0x00000080
#define MCWDDMV2_CONTROL_BREAK_ON_FRONT_BUFFER_RENDER                  0x00010000
#define MCWDDMV2_CONTROL_DEFAULT                                       0x0


#define MC_DISABLE_SLI_STRING                                          "60461781"
#define MC_DISABLE_SLI_ID                                              0x0078d9d9
#define MC_DISABLE_SLI_OVERINSTALL                                     0 // OVERRIDE
#define MC_DISABLE_SLI_OFF                                             0x00000000
#define MC_DISABLE_SLI_ON                                              0x00000001
#define MC_DISABLE_SLI_DEFAULT                                         0x00000000


#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_STRING                       "41521428"
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_ID                           0x00c69bcd
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_OVERINSTALL                  0 // OVERRIDE
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_DISABLE                      0x0
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_ENABLE_IFLIP                 0x1
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_ENABLE_All                   0x2
#define MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_DEFAULT                      MC_WDDMV2_OUT_OF_ORDER_FRAMES_WAR_ENABLE_IFLIP


#define MEM_FRACTION_12ON7_STRING                                      "0xb21d49"
#define MEM_FRACTION_12ON7_ID                                          0x00b21d49
#define MEM_FRACTION_12ON7_OVERINSTALL                                 0 // OVERRIDE
#define MEM_FRACTION_12ON7_DEFAULT                                     90


#define METACOMMAND_CASK_KERNEL_TEST_INDEX_STRING                      "1dab00"
#define METACOMMAND_CASK_KERNEL_TEST_INDEX_ID                          0x001dab00
#define METACOMMAND_CASK_KERNEL_TEST_INDEX_OVERINSTALL                 0 // OVERRIDE
#define METACOMMAND_CASK_KERNEL_TEST_INDEX_DEFAULT                     0xffffffff


#define METACOMMAND_DUMP_PATH_STRING                                   "ababc1"
#define METACOMMAND_DUMP_PATH_ID                                       0x00ababc1
#define METACOMMAND_DUMP_PATH_OVERINSTALL                              0 // OVERRIDE
#define METACOMMAND_DUMP_PATH_DEFAULT                                  "c:\\log"


#define METACOMMAND_ENABLE_PATCH_KERNEL_STRING                         "ababc3"
#define METACOMMAND_ENABLE_PATCH_KERNEL_ID                             0x00ababc3
#define METACOMMAND_ENABLE_PATCH_KERNEL_OVERINSTALL                    0 // OVERRIDE
#define METACOMMAND_ENABLE_PATCH_KERNEL_OFF                            0x0
#define METACOMMAND_ENABLE_PATCH_KERNEL_DISABLED                       0x0
#define METACOMMAND_ENABLE_PATCH_KERNEL_ON                             0x1
#define METACOMMAND_ENABLE_PATCH_KERNEL_ENABLED                        0x1
#define METACOMMAND_ENABLE_PATCH_KERNEL_DEFAULT                        METACOMMAND_ENABLE_PATCH_KERNEL_ON


#define METACOMMAND_LOG_STRING                                         "ababcd"
#define METACOMMAND_LOG_ID                                             0x00ababcd
#define METACOMMAND_LOG_OVERINSTALL                                    0 // OVERRIDE
#define METACOMMAND_LOG_LOG_CREATE                                     0x00000001
#define METACOMMAND_LOG_LOG_QUERY                                      0x00000002
#define METACOMMAND_LOG_LOG_INIT_EXECUTE                               0x00000004
#define METACOMMAND_LOG_DETAILED_PARAM_LOG                             0x00000008
#define METACOMMAND_LOG_DUMP_OP_TENSOR_DATA                            0x00000010
#define METACOMMAND_LOG_DUMP_IP_TENSOR_DATA                            0x00000020
#define METACOMMAND_LOG_DEFAULT                                        0


#define METACOMMAND_LOG_FILENAME_STRING                                "ababce"
#define METACOMMAND_LOG_FILENAME_ID                                    0x00ababce
#define METACOMMAND_LOG_FILENAME_OVERINSTALL                           0 // OVERRIDE
#define METACOMMAND_LOG_FILENAME_DEFAULT                               "c:\\log\\MetaCommand_log_%d.txt"


#define METACOMMAND_QUERY_LOG_FILENAME_STRING                          "ababcf"
#define METACOMMAND_QUERY_LOG_FILENAME_ID                              0x00ababcf
#define METACOMMAND_QUERY_LOG_FILENAME_OVERINSTALL                     0 // OVERRIDE
#define METACOMMAND_QUERY_LOG_FILENAME_DEFAULT                         "c:\\log\\MetaCommand_query_log.txt"


#define METACOMMAND_SUPPORT_STRING                                     "ababc2"
#define METACOMMAND_SUPPORT_ID                                         0x00ababc2
#define METACOMMAND_SUPPORT_OVERINSTALL                                0 // OVERRIDE
#define METACOMMAND_SUPPORT_DISABLED                                   0x0
#define METACOMMAND_SUPPORT_OFF                                        0x0
#define METACOMMAND_SUPPORT_FALSE                                      0x0
#define METACOMMAND_SUPPORT_ENABLED_PREFERRED                          0x1
#define METACOMMAND_SUPPORT_ENABLED_FORCED                             0x2
#define METACOMMAND_SUPPORT_DEFAULT                                    METACOMMAND_SUPPORT_ENABLED_PREFERRED


#define METACOMMAND_TENSOR_DUMP_MAX_SIZE_STRING                        "421112"
#define METACOMMAND_TENSOR_DUMP_MAX_SIZE_ID                            0x00421112
#define METACOMMAND_TENSOR_DUMP_MAX_SIZE_OVERINSTALL                   0 // OVERRIDE
#define METACOMMAND_TENSOR_DUMP_MAX_SIZE_DEFAULT                       0


#define MIN_CE_TRANSFER_SIZE_STRING                                    "dc648f84"
#define MIN_CE_TRANSFER_SIZE_ID                                        0x00cf258b
#define MIN_CE_TRANSFER_SIZE_OVERINSTALL                               0 // OVERRIDE
#define MIN_CE_TRANSFER_SIZE_MAX                                       0xFFFFFFFF
#define MIN_CE_TRANSFER_SIZE_DEFAULT                                   0x00000708


#define MIN_PREC16_ENABLED_STRING                                      "1067F73B"
#define MIN_PREC16_ENABLED_ID                                          0x0039f894
#define MIN_PREC16_ENABLED_OVERINSTALL                                 0 // OVERRIDE
#define MIN_PREC16_ENABLED_OFF                                         0x0
#define MIN_PREC16_ENABLED_DISABLED                                    0x0
#define MIN_PREC16_ENABLED_ON                                          0x1
#define MIN_PREC16_ENABLED_ENABLED                                     0x1
#define MIN_PREC16_ENABLED_DEFAULT                                     MIN_PREC16_ENABLED_ON


#define MIN_PREC_ENABLED_STRING                                        "1067F73A"
#define MIN_PREC_ENABLED_ID                                            0x0039f893
#define MIN_PREC_ENABLED_OVERINSTALL                                   0 // OVERRIDE
#define MIN_PREC_ENABLED_OFF                                           0x0
#define MIN_PREC_ENABLED_DISABLED                                      0x0
#define MIN_PREC_ENABLED_ON                                            0x1
#define MIN_PREC_ENABLED_ENABLED                                       0x1
#define MIN_PREC_ENABLED_DEFAULT                                       MIN_PREC_ENABLED_ON


#define MIPMAPDITHERMODE_STRING                                        "50269164"
#define MIPMAPDITHERMODE_ID                                            0x005c4d27
#define MIPMAPDITHERMODE_OVERINSTALL                                   0 // OVERRIDE
#define MIPMAPDITHERMODE_DISABLE                                       0x75955199
#define MIPMAPDITHERMODE_OFF                                           0x75955199
#define MIPMAPDITHERMODE_0                                             0x75955199
#define MIPMAPDITHERMODE_FALSE                                         0x75955199
#define MIPMAPDITHERMODE_ENABLE                                        0x39932250
#define MIPMAPDITHERMODE_ON                                            0x39932250
#define MIPMAPDITHERMODE_1                                             0x39932250
#define MIPMAPDITHERMODE_TRUE                                          0x39932250
#define MIPMAPDITHERMODE_SMART                                         0x71539305
#define MIPMAPDITHERMODE_2                                             0x71539305
#define MIPMAPDITHERMODE_DEFAULT                                       MIPMAPDITHERMODE_SMART


#define MISCOPTS_STRING                                                "69469623"
#define MISCOPTS_ID                                                    0x00283f72
#define MISCOPTS_OVERINSTALL                                           0 // OVERRIDE
#define MISCOPTS_FASTSRGB_DEPRECATED                                   0x00000001
#define MISCOPTS_NOPARANOIDTEXFETCHES                                  0x00000002
#define MISCOPTS_SM105_FMUL                                            0x00000004
#define MISCOPTS_FORCE_THIN_PS_THREADS                                 0x00000008
#define MISCOPTS_ENABLE_1_BIT_ZC_HEURISTIC                             0x00000010
#define MISCOPTS_MASK                                                  0x0000001f
#define MISCOPTS_DEFAULT                                               0x00000006


#define MISC_INDICATOR_STRING                                          "14B5629"
#define MISC_INDICATOR_ID                                              0x008df510
#define MISC_INDICATOR_OVERINSTALL                                     0 // OVERRIDE
#define MISC_INDICATOR_DEFAULT                                         0x00000000
#define MISC_INDICATOR_VRR_ENTROPY                                     0x00000001
#define MISC_INDICATOR_VRR_SUSPEND_REASON                              0x00000002
#define MISC_INDICATOR_VRR_SUPPORT                                     0x00000004
#define MISC_INDICATOR_MASK                                            0x00000007


#define MPOINDICATOR_STRING                                            "a88888"
#define MPOINDICATOR_ID                                                0x00a88888
#define MPOINDICATOR_OVERINSTALL                                       0 // OVERRIDE
#define MPOINDICATOR_OFF                                               0
#define MPOINDICATOR_DISABLED                                          0
#define MPOINDICATOR_ON                                                1
#define MPOINDICATOR_ENABLED                                           1
#define MPOINDICATOR_DEFAULT                                           MPOINDICATOR_OFF


#define MULTITHREAD_DDI_STRING                                         "97111606"
#define MULTITHREAD_DDI_ID                                             0x0019ad4b
#define MULTITHREAD_DDI_OVERINSTALL                                    0 // OVERRIDE
#define MULTITHREAD_DDI_OFF                                            0x37278085
#define MULTITHREAD_DDI_DISABLED                                       0x37278085
#define MULTITHREAD_DDI_ON                                             0x29465058
#define MULTITHREAD_DDI_ENABLED                                        0x29465058
#define MULTITHREAD_DDI_DEFAULT                                        MULTITHREAD_DDI_ON


#define NATIVE_16_BIT_OPS_STRING                                       "0158498"
#define NATIVE_16_BIT_OPS_ID                                           0x00158498
#define NATIVE_16_BIT_OPS_OVERINSTALL                                  0 // OVERRIDE
#define NATIVE_16_BIT_OPS_OFF                                          0x00000000
#define NATIVE_16_BIT_OPS_DISABLED                                     0x00000000
#define NATIVE_16_BIT_OPS_ON                                           0x00000001
#define NATIVE_16_BIT_OPS_ENABLED                                      0x00000001
#define NATIVE_16_BIT_OPS_DEFAULT                                      NATIVE_16_BIT_OPS_OFF


#define NEVERFAILVBCREATE_STRING                                       "28888943"
#define NEVERFAILVBCREATE_ID                                           0x00e18ce7
#define NEVERFAILVBCREATE_OVERINSTALL                                  0 // OVERRIDE
#define NEVERFAILVBCREATE_OFF                                          0x20556640
#define NEVERFAILVBCREATE_DISABLED                                     0x20556640
#define NEVERFAILVBCREATE_ON                                           0x12838744
#define NEVERFAILVBCREATE_ENABLED                                      0x12838744
#define NEVERFAILVBCREATE_DEFAULT                                      NEVERFAILVBCREATE_OFF


#define NOFMZENABLE_STRING                                             "7f860121"
#define NOFMZENABLE_ID                                                 0x003d40da
#define NOFMZENABLE_OVERINSTALL                                        0 // OVERRIDE
#define NOFMZENABLE_OFF                                                0x00000000
#define NOFMZENABLE_DISABLED                                           0x00000000
#define NOFMZENABLE_ON                                                 0x00000001
#define NOFMZENABLE_ENABLED                                            0x00000001
#define NOFMZENABLE_DEFAULT                                            NOFMZENABLE_OFF


#define NOSUBALLOC_STRING                                              "34394538"
#define NOSUBALLOC_ID                                                  0x007d833d
#define NOSUBALLOC_OVERINSTALL                                         0 // OVERRIDE
#define NOSUBALLOC_VID                                                 0x00000001
#define NOSUBALLOC_HOST                                                0x00000002
#define NOSUBALLOC_SYS                                                 0x00000004
#define NOSUBALLOC_DEFAULT                                             0


#define NOWFI_ON_TEX_INVALIDATE_STRING                                 "0xfa3d5ad"
#define NOWFI_ON_TEX_INVALIDATE_ID                                     0x00a3d5ad
#define NOWFI_ON_TEX_INVALIDATE_OVERINSTALL                            0 // OVERRIDE
#define NOWFI_ON_TEX_INVALIDATE_OFF                                    0x0
#define NOWFI_ON_TEX_INVALIDATE_DISABLED                               0x0
#define NOWFI_ON_TEX_INVALIDATE_ON                                     0x1
#define NOWFI_ON_TEX_INVALIDATE_ENABLED                                0x1
#define NOWFI_ON_TEX_INVALIDATE_DEFAULT                                NOWFI_ON_TEX_INVALIDATE_ON


#define NOWFI_UPLOAD_CONTROL_STRING                                    "0xfa345ad"
#define NOWFI_UPLOAD_CONTROL_ID                                        0x00a345ad
#define NOWFI_UPLOAD_CONTROL_OVERINSTALL                               0 // OVERRIDE
#define NOWFI_UPLOAD_CONTROL_DISABLE_NOWFI_TEX_UPLOAD_IN_DSR           0x00000001
#define NOWFI_UPLOAD_CONTROL_FORCE_NOWFI_TEX_UPLOAD                    0x00000002
#define NOWFI_UPLOAD_CONTROL_DEFAULT                                   NOWFI_UPLOAD_CONTROL_DISABLE_NOWFI_TEX_UPLOAD_IN_DSR


#define NULLALPHABLEND_STRING                                          "52975922"
#define NULLALPHABLEND_ID                                              0x00184e5f
#define NULLALPHABLEND_OVERINSTALL                                     0 // OVERRIDE
#define NULLALPHABLEND_OFF                                             0x35331782
#define NULLALPHABLEND_DISABLED                                        0x35331782
#define NULLALPHABLEND_ON                                              0x30098471
#define NULLALPHABLEND_ENABLED                                         0x30098471
#define NULLALPHABLEND_DEFAULT                                         NULLALPHABLEND_OFF


#define NULLALPHATEST_STRING                                           "97674294"
#define NULLALPHATEST_ID                                               0x00560cf0
#define NULLALPHATEST_OVERINSTALL                                      0 // OVERRIDE
#define NULLALPHATEST_OFF                                              0x34386543
#define NULLALPHATEST_DISABLED                                         0x34386543
#define NULLALPHATEST_ON                                               0x87462087
#define NULLALPHATEST_ENABLED                                          0x87462087
#define NULLALPHATEST_DEFAULT                                          NULLALPHATEST_OFF


#define NULLDRIVERENABLE_STRING                                        "50609938"
#define NULLDRIVERENABLE_ID                                            0x00f6fdef
#define NULLDRIVERENABLE_OVERINSTALL                                   0 // OVERRIDE
#define NULLDRIVERENABLE_OFF                                           0x06375634
#define NULLDRIVERENABLE_DISABLED                                      0x06375634
#define NULLDRIVERENABLE_ON                                            0x36574560
#define NULLDRIVERENABLE_ENABLED                                       0x36574560
#define NULLDRIVERENABLE_DEFAULT                                       NULLDRIVERENABLE_OFF


#define NULLFILL_STRING                                                "89403821"
#define NULLFILL_ID                                                    0x00a4b291
#define NULLFILL_OVERINSTALL                                           0 // OVERRIDE
#define NULLFILL_OFF                                                   0x53451913
#define NULLFILL_DISABLED                                              0x53451913
#define NULLFILL_ON                                                    0x83674921
#define NULLFILL_ENABLED                                               0x83674921
#define NULLFILL_DEFAULT                                               NULLFILL_OFF


#define NULLHWDRIVERENABLE_STRING                                      "39667365"
#define NULLHWDRIVERENABLE_ID                                          0x00279636
#define NULLHWDRIVERENABLE_OVERINSTALL                                 0 // OVERRIDE
#define NULLHWDRIVERENABLE_OFF                                         0x66899340
#define NULLHWDRIVERENABLE_DISABLED                                    0x66899340
#define NULLHWDRIVERENABLE_ON                                          0x92333866
#define NULLHWDRIVERENABLE_ENABLED                                     0x92333866
#define NULLHWDRIVERENABLE_DEFAULT                                     NULLHWDRIVERENABLE_OFF


#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_STRING                          "abab12"
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_ID                              0x00abab12
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_OVERINSTALL                     0 // OVERRIDE
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_OFF                             0x00000000
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_DISABLED                        0x00000000
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_ON                              0x00000001
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_ENABLED                         0x00000001
#define NVAPI_GWC_USE_LOCAL_ROOT_TABLE_DEFAULT                         NVAPI_GWC_USE_LOCAL_ROOT_TABLE_ON


#define NVAPPSHIM_DSR_DISALLOW_STRING                                  "ADA0001"
#define NVAPPSHIM_DSR_DISALLOW_ID                                      0x00ada000
#define NVAPPSHIM_DSR_DISALLOW_OVERINSTALL                             0 // OVERRIDE
#define NVAPPSHIM_DSR_DISALLOW_OFF                                     0x00000000
#define NVAPPSHIM_DSR_DISALLOW_DISABLED                                0x00000000
#define NVAPPSHIM_DSR_DISALLOW_ON                                      0x00000001
#define NVAPPSHIM_DSR_DISALLOW_ENABLED                                 0x00000001
#define NVAPPSHIM_DSR_DISALLOW_DEFAULT                                 NVAPPSHIM_DSR_DISALLOW_OFF


#define NVFBC_BUMP_SURF_PRIORITY_STRING                                "FBC00003"
#define NVFBC_BUMP_SURF_PRIORITY_ID                                    0x00fbc003
#define NVFBC_BUMP_SURF_PRIORITY_OVERINSTALL                           0 // OVERRIDE
#define NVFBC_BUMP_SURF_PRIORITY_OFF                                   0x00000000
#define NVFBC_BUMP_SURF_PRIORITY_DISABLED                              0x00000000
#define NVFBC_BUMP_SURF_PRIORITY_ON                                    0x00000001
#define NVFBC_BUMP_SURF_PRIORITY_ENABLED                               0x00000001
#define NVFBC_BUMP_SURF_PRIORITY_DEFAULT                               NVFBC_BUMP_SURF_PRIORITY_OFF


#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_STRING                        "FBC0000A"
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_ID                            0x00fbc00a
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_OVERINSTALL                   0 // OVERRIDE
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_OFF                           0x00000000
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_DISABLED                      0x00000000
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_ON                            0x00000001
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_ENABLED                       0x00000001
#define NVFBC_DX9VID_EVENT_BASED_CAPTURE_DEFAULT                       NVFBC_DX9VID_EVENT_BASED_CAPTURE_OFF


#define NVFBC_DX9VID_OPTIMIZATIONS_STRING                              "FBC00004"
#define NVFBC_DX9VID_OPTIMIZATIONS_ID                                  0x00fbc004
#define NVFBC_DX9VID_OPTIMIZATIONS_OVERINSTALL                         0 // OVERRIDE
#define NVFBC_DX9VID_OPTIMIZATIONS_OFF                                 0x00000000
#define NVFBC_DX9VID_OPTIMIZATIONS_DISABLED                            0x00000000
#define NVFBC_DX9VID_OPTIMIZATIONS_ON                                  0x00000001
#define NVFBC_DX9VID_OPTIMIZATIONS_ENABLED                             0x00000001
#define NVFBC_DX9VID_OPTIMIZATIONS_DEFAULT                             NVFBC_DX9VID_OPTIMIZATIONS_ON


#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_STRING              "90B90B"
#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_ID                  0x0090b90b
#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_OVERINSTALL         0 // OVERRIDE
#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_OFF                 0x0
#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_ON                  0x1
#define NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_DEFAULT             NVFBC_ENABLE_POST_PROCESSING_VIDEO_CAPTURE_OFF


#define NVFBC_LOW_LATENCY_STRING                                       "FBC00001"
#define NVFBC_LOW_LATENCY_ID                                           0x00fbc001
#define NVFBC_LOW_LATENCY_OVERINSTALL                                  0 // OVERRIDE
#define NVFBC_LOW_LATENCY_OFF                                          0x00000000
#define NVFBC_LOW_LATENCY_DISABLED                                     0x00000000
#define NVFBC_LOW_LATENCY_ON                                           0x00000001
#define NVFBC_LOW_LATENCY_ENABLED                                      0x00000001
#define NVFBC_LOW_LATENCY_DEFAULT                                      NVFBC_LOW_LATENCY_OFF


#define NVFBC_MULTITAP_SCALER_STRING                                   "FBC00009"
#define NVFBC_MULTITAP_SCALER_ID                                       0x00fbc009
#define NVFBC_MULTITAP_SCALER_OVERINSTALL                              0 // OVERRIDE
#define NVFBC_MULTITAP_SCALER_OFF                                      0x00000000
#define NVFBC_MULTITAP_SCALER_DISABLED                                 0x00000000
#define NVFBC_MULTITAP_SCALER_ON                                       0x00000001
#define NVFBC_MULTITAP_SCALER_ENABLED                                  0x00000001
#define NVFBC_MULTITAP_SCALER_DEFAULT                                  NVFBC_MULTITAP_SCALER_OFF


#define NVFBC_MULTI_CAPTURE_BUFFER_STRING                              "FBC00005"
#define NVFBC_MULTI_CAPTURE_BUFFER_ID                                  0x00fbc005
#define NVFBC_MULTI_CAPTURE_BUFFER_OVERINSTALL                         0 // OVERRIDE
#define NVFBC_MULTI_CAPTURE_BUFFER_OFF                                 0x00000000
#define NVFBC_MULTI_CAPTURE_BUFFER_DISABLED                            0x00000000
#define NVFBC_MULTI_CAPTURE_BUFFER_ON                                  0x00000001
#define NVFBC_MULTI_CAPTURE_BUFFER_ENABLED                             0x00000001
#define NVFBC_MULTI_CAPTURE_BUFFER_DEFAULT                             NVFBC_MULTI_CAPTURE_BUFFER_ON


#define NVFBC_OVERLAY_CAPTURE_STRING                                   "FBC00006"
#define NVFBC_OVERLAY_CAPTURE_ID                                       0x00fbc006
#define NVFBC_OVERLAY_CAPTURE_OVERINSTALL                              0 // OVERRIDE
#define NVFBC_OVERLAY_CAPTURE_OFF                                      0x00000000
#define NVFBC_OVERLAY_CAPTURE_DISABLED                                 0x00000000
#define NVFBC_OVERLAY_CAPTURE_ON                                       0x00000001
#define NVFBC_OVERLAY_CAPTURE_ENABLED                                  0x00000001
#define NVFBC_OVERLAY_CAPTURE_DEFAULT                                  NVFBC_OVERLAY_CAPTURE_OFF


#define NVFBC_QUARTER_RES_STRING                                       "FBC00008"
#define NVFBC_QUARTER_RES_ID                                           0x00fbc008
#define NVFBC_QUARTER_RES_OVERINSTALL                                  0 // OVERRIDE
#define NVFBC_QUARTER_RES_OFF                                          0x00000000
#define NVFBC_QUARTER_RES_ENABLE                                       0x00000001
#define NVFBC_QUARTER_RES_FORCE_ENABLE                                 0x00000002
#define NVFBC_QUARTER_RES_DEFAULT                                      NVFBC_QUARTER_RES_OFF


#define NVFBC_REFLEX_TIMESTAMPS_STRING                                 "FBC0000B"
#define NVFBC_REFLEX_TIMESTAMPS_ID                                     0x00fbc00b
#define NVFBC_REFLEX_TIMESTAMPS_OVERINSTALL                            0 // OVERRIDE
#define NVFBC_REFLEX_TIMESTAMPS_OFF                                    0x00000000
#define NVFBC_REFLEX_TIMESTAMPS_DISABLED                               0x00000000
#define NVFBC_REFLEX_TIMESTAMPS_ON                                     0x00000001
#define NVFBC_REFLEX_TIMESTAMPS_ENABLED                                0x00000001
#define NVFBC_REFLEX_TIMESTAMPS_DEFAULT                                NVFBC_REFLEX_TIMESTAMPS_OFF


#define NVFBC_SLI_CONTROL_STRING                                       "3112014"
#define NVFBC_SLI_CONTROL_ID                                           0x008645cd
#define NVFBC_SLI_CONTROL_OVERINSTALL                                  0 // OVERRIDE
#define NVFBC_SLI_CONTROL_CAPTUREPROCESS_COMPOSE                       0x1
#define NVFBC_SLI_CONTROL_RENDERPROCESS_COMPOSE                        0x2
#define NVFBC_SLI_CONTROL_DISABLE_CE_BLIT_OPTIMIZATION                 0x4
#define NVFBC_SLI_CONTROL_DEFAULT                                      NVFBC_SLI_CONTROL_CAPTUREPROCESS_COMPOSE


#define NVFBC_UMD_SURF_DUMP_STRING                                     "FBC00002"
#define NVFBC_UMD_SURF_DUMP_ID                                         0x00fbc002
#define NVFBC_UMD_SURF_DUMP_OVERINSTALL                                0 // OVERRIDE
#define NVFBC_UMD_SURF_DUMP_OFF                                        0x00000000
#define NVFBC_UMD_SURF_DUMP_DISABLED                                   0x00000000
#define NVFBC_UMD_SURF_DUMP_ON                                         0x00000001
#define NVFBC_UMD_SURF_DUMP_ENABLED                                    0x00000001
#define NVFBC_UMD_SURF_DUMP_DEFAULT                                    NVFBC_UMD_SURF_DUMP_OFF


#define NVFBC_ZERO_LATENCY_STRING                                      "FBC00007"
#define NVFBC_ZERO_LATENCY_ID                                          0x00fbc007
#define NVFBC_ZERO_LATENCY_OVERINSTALL                                 0 // OVERRIDE
#define NVFBC_ZERO_LATENCY_OFF                                         0x00000000
#define NVFBC_ZERO_LATENCY_DISABLED                                    0x00000000
#define NVFBC_ZERO_LATENCY_ON                                          0x00000001
#define NVFBC_ZERO_LATENCY_ENABLED                                     0x00000001
#define NVFBC_ZERO_LATENCY_DEFAULT                                     NVFBC_ZERO_LATENCY_ON


#define NVINST_FP16_FLAGS_STRING                                       "BA3A26"
#define NVINST_FP16_FLAGS_ID                                           0x00ba3a26
#define NVINST_FP16_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define NVINST_FP16_FLAGS_FORCE_MIN16FLOAT_TO_16                       0x1
#define NVINST_FP16_FLAGS_FORCE_MIN16FLOAT_TO_32                       0x2
#define NVINST_FP16_FLAGS_DEFAULT                                      OFF


#define NVNET_DRIVER_IPADDR_STRING                                     "2f3ffb"
#define NVNET_DRIVER_IPADDR_ID                                         0x002f3ffb
#define NVNET_DRIVER_IPADDR_OVERINSTALL                                0 // OVERRIDE
#define NVNET_DRIVER_IPADDR_DEFAULT                                    ":0"


#define NVNET_ENABLED_STRING                                           "2f3ff9"
#define NVNET_ENABLED_ID                                               0x002f3ff9
#define NVNET_ENABLED_OVERINSTALL                                      0 // OVERRIDE
#define NVNET_ENABLED_OFF                                              0x00000000
#define NVNET_ENABLED_DISABLED                                         0x00000000
#define NVNET_ENABLED_ON                                               0x00000001
#define NVNET_ENABLED_ENABLED                                          0x00000001
#define NVNET_ENABLED_DEFAULT                                          NVNET_ENABLED_OFF


#define NVNET_PROVIDER_IPADDR_STRING                                   "2f3ffa"
#define NVNET_PROVIDER_IPADDR_ID                                       0x002f3ffa
#define NVNET_PROVIDER_IPADDR_OVERINSTALL                              0 // OVERRIDE
#define NVNET_PROVIDER_IPADDR_DEFAULT                                  ":34343"


#define NVPMAPIBDEnabled_STRING                                        "93291387"
#define NVPMAPIBDEnabled_ID                                            0x00b960a8
#define NVPMAPIBDEnabled_OVERINSTALL                                   0 // OVERRIDE
#define NVPMAPIBDEnabled_OFF                                           0x00000000
#define NVPMAPIBDEnabled_DISABLED                                      0x00000000
#define NVPMAPIBDEnabled_ON                                            0x00000001
#define NVPMAPIBDEnabled_ENABLED                                       0x00000001


#define NVPMAPISecurity_STRING                                         "59287341"
#define NVPMAPISecurity_ID                                             0x00e501e4
#define NVPMAPISecurity_OVERINSTALL                                    0 // OVERRIDE
#define NVPMAPISecurity_OFF                                            0x00000000
#define NVPMAPISecurity_DISABLED                                       0x00000000
#define NVPMAPISecurity_ON                                             0x00000001
#define NVPMAPISecurity_ENABLED                                        0x00000001


#define NVTRACECOP_STRING                                              "08123498"
#define NVTRACECOP_ID                                                  0x00853b5e
#define NVTRACECOP_OVERINSTALL                                         0 // OVERRIDE
#define NVTRACECOP_MIN                                                 0x00000000
#define NVTRACECOP_MAX                                                 0xFFFFFFFF
#define NVTRACECOP_DEFAULT                                             0


#define NV_AMODEL_DLL_STRING                                           "27721285"
#define NV_AMODEL_DLL_ID                                               0x006241ba
#define NV_AMODEL_DLL_OVERINSTALL                                      0 // OVERRIDE
#define NV_AMODEL_DLL_DEFAULT                                          0x00000000


#define NV_DEP_QMD_COUNT_STRING                                        "0x9dc472"
#define NV_DEP_QMD_COUNT_ID                                            0x009dc472
#define NV_DEP_QMD_COUNT_OVERINSTALL                                   0 // OVERRIDE
#define NV_DEP_QMD_COUNT_DEFAULT                                       500


#define NV_DIRECTAMODEL_SIMCHIP_STRING                                 "19663358"
#define NV_DIRECTAMODEL_SIMCHIP_ID                                     0x0069474d
#define NV_DIRECTAMODEL_SIMCHIP_OVERINSTALL                            0 // OVERRIDE
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM107_MAXWELL                  0x30
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM108_MAXWELL                  0x31
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM206_MAXWELL                  0x32
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM20B_MAXWELL                  0x33
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM200_MAXWELL                  0x34
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM204_MAXWELL                  0x35
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM20C_MAXWELL                  0x36
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GM210_MAXWELL                  0x37
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP100_PASCAL                   0x38
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP102_PASCAL                   0x39
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP104_PASCAL                   0x3A
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP106_PASCAL                   0x3B
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP107_PASCAL                   0x3C
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GP108_PASCAL                   0x3D
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GV100_VOLTA                    0x3E
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_TU102_TURING                   0x40
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_TU104_TURING                   0x41
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_TU106_TURING                   0x42
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_TU116_TURING                   0x43
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_TU117_TURING                   0x44
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA100_AMPERE                   0x45
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA102_AMPERE                   0x46
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA103_AMPERE                   0x47
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA104_AMPERE                   0x48
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA106_AMPERE                   0x49
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA107_AMPERE                   0x4a
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GA10B_AMPERE                   0x4b
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD102_ADA                      0x50
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD103_ADA                      0x51
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD104_ADA                      0x52
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD106_ADA                      0x53
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD107_ADA                      0x54
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD10B_ADA                      0x55
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_AD10C_ADA                      0x56
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_GH100_HOPPER                   0x58
#define NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_NULL                           0xffffffff
#define NV_DIRECTAMODEL_SIMCHIP_DEFAULT                                NV_DIRECTAMODEL_SIMCHIP_SIMCHIP_NULL


#define NV_DIRECTAMODEL_SIMCLASS_STRING                                "19663348"
#define NV_DIRECTAMODEL_SIMCLASS_ID                                    0x0069473d
#define NV_DIRECTAMODEL_SIMCLASS_OVERINSTALL                           0 // OVERRIDE
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GM10x_MAXWELL                0x11
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GM20x_MAXWELL                0x12
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GM20x_TEGRA_MAXWELL          0x13
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GM21x_MAXWELL                0x14
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GP100_PASCAL                 0x15
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GP10x_PASCAL                 0x16
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GV10x_VOLTA                  0x17
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_TU10x_TURING                 0x18
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GA100_AMPERE                 0x19
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GA10x_AMPERE                 0x1a
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_AD10x_ADA                    0x1b
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_GH100_HOPPER                 0x1c
#define NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_NULL                         0xffffffff
#define NV_DIRECTAMODEL_SIMCLASS_DEFAULT                               NV_DIRECTAMODEL_SIMCLASS_SIMCLASS_NULL


#define NV_SM_TRAP_HANDLER_STRING                                      "dead1300"
#define NV_SM_TRAP_HANDLER_ID                                          0x00dead10
#define NV_SM_TRAP_HANDLER_OVERINSTALL                                 0 // OVERRIDE
#define NV_SM_TRAP_HANDLER_OFF                                         0x0
#define NV_SM_TRAP_HANDLER_DISABLED                                    0x0
#define NV_SM_TRAP_HANDLER_ON                                          0x1
#define NV_SM_TRAP_HANDLER_ENABLED                                     0x1


#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_STRING           "dead1302"
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_ID               0x00dead12
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_OVERINSTALL      0 // OVERRIDE
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_ENABLE           0x00000001
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_ENABLE_LVL_MASK  0x000000ff
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_ENABLE_LVL_1_MINIMAL 0x00000001
#define NV_SM_TRAP_HANDLER_DUMP_SM_EXCEPTIONS_TO_FILE_ENABLE_LVL_2_MODERATE 0x00000002


#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_STRING                          "dead1309"
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_ID                              0x00dead19
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_OVERINSTALL                     0 // OVERRIDE
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_OFF                             0x0
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_DISABLED                        0x0
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_ON                              0x1
#define NV_SM_TRAP_HANDLER_DUMP_TO_OCA_ENABLED                         0x1


#define NV_SM_TRAP_HANDLER_FLAGS_STRING                                "dead1301"
#define NV_SM_TRAP_HANDLER_FLAGS_ID                                    0x00dead11
#define NV_SM_TRAP_HANDLER_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_LOG_FILE                       0x00000001
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_SHADER_DEBUG_DATA              0x00000002
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_DEBUG_PRINTF                   0x00000004
#define NV_SM_TRAP_HANDLER_FLAGS_DUMP_SM_ERRORS                        0x00000010
#define NV_SM_TRAP_HANDLER_FLAGS_DUMP_ONLY_FIRST_FAULTY_WARP           0x00000020
#define NV_SM_TRAP_HANDLER_FLAGS_EXIT_AFTER_DUMPING_SM_ERRORS          0x00000040
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_TOAST_NOTIFICATION_ON_SM_ERROR 0x00000080
#define NV_SM_TRAP_HANDLER_FLAGS_DISABLE_GPU_TIMEOUT_AND_PREEMPTION    0x00001000
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_PRI_MMU_DEBUG_MODE             0x00010000
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_PRI_IMPLICIT_ERRBAR_ON_SHADER_EXIT 0x00020000
#define NV_SM_TRAP_HANDLER_FLAGS_ENABLE_COMMAND_TIMING                 0x00100000


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_APP_HASH_STRING                "dead1303"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_APP_HASH_ID                    0x00dead13
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_APP_HASH_OVERINSTALL           0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_DX_RUNTIME_HASH_STRING         "dead130a"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_DX_RUNTIME_HASH_ID             0x00dead1a
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_DX_RUNTIME_HASH_OVERINSTALL    0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_LINE_NUMBER_STRING             "dead1304"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_LINE_NUMBER_ID                 0x00dead14
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_LINE_NUMBER_OVERINSTALL        0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_X_STRING                   "dead1305"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_X_ID                       0x00dead15
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_X_OVERINSTALL              0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Y_STRING                   "dead1306"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Y_ID                       0x00dead16
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Y_OVERINSTALL              0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Z_STRING                   "dead1307"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Z_ID                       0x00dead17
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_POS_Z_OVERINSTALL              0 // OVERRIDE


#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_STRING                    "dead1308"
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_ID                        0x00dead18
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_OVERINSTALL               0 // OVERRIDE
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_NONE                      0x00000000
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_BREAKPOINT                0x00000001
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_PRINTF                    0x00000002
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_DUMP_REGISTERS_AND_GO     0x00000003
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_LDG_NULL                  0x00000010
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_LDG_FOO                   0x00000011
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_STG_NULL                  0x00000020
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_STG_FOO                   0x00000021
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_JMP_NULL                  0x00000030
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_JMP_FOO                   0x00000031
#define NV_SM_TRAP_HANDLER_INJECT_EVENT_TYPE_INFINITE_LOOP             0x00000040


#define NV_SM_TRAP_HANDLER_NETWORK_CONNECTION_STRING_STRING            "dead1330"
#define NV_SM_TRAP_HANDLER_NETWORK_CONNECTION_STRING_ID                0x00dead30
#define NV_SM_TRAP_HANDLER_NETWORK_CONNECTION_STRING_OVERINSTALL       0 // OVERRIDE


#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_STRING                  "0x21F8D9"
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_ID                      0x0021f8d9
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_OVERINSTALL             0 // OVERRIDE
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_OFF                     0
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_DISABLED                0
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_ON                      1
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_ENABLED                 1
#define OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_DEFAULT                 OCGCONTROL_RELAX_CONV_BLOCK_DEFINITION_OFF


#define OCG_CRASH_DUMP_STRING                                          "f9f63d"
#define OCG_CRASH_DUMP_ID                                              0x00f9f63d
#define OCG_CRASH_DUMP_OVERINSTALL                                     0 // OVERRIDE
#define OCG_CRASH_DUMP_OFF                                             0x16564886
#define OCG_CRASH_DUMP_DISABLED                                        0x16564886
#define OCG_CRASH_DUMP_ON                                              0x18826043
#define OCG_CRASH_DUMP_ENABLED                                         0x18826043
#define OCG_CRASH_DUMP_DEFAULT                                         OCG_CRASH_DUMP_ON


#define OCG_CRASH_DUMP_FILENAME_STRING                                 "1bd3ed"
#define OCG_CRASH_DUMP_FILENAME_ID                                     0x001bd3ed
#define OCG_CRASH_DUMP_FILENAME_OVERINSTALL                            0 // OVERRIDE
#define OCG_CRASH_DUMP_FILENAME_DEFAULT                                "\\ocg-crash-dump.txt"


#define OS_VRR_APP_OVERRIDE_STRING                                     "424ACC"
#define OS_VRR_APP_OVERRIDE_ID                                         0x00a879ff
#define OS_VRR_APP_OVERRIDE_OVERINSTALL                                0 // OVERRIDE
#define OS_VRR_APP_OVERRIDE_ALLOW                                      0
#define OS_VRR_APP_OVERRIDE_FORCE_OFF                                  1
#define OS_VRR_APP_OVERRIDE_DEFAULT                                    OS_VRR_APP_OVERRIDE_ALLOW


#define OVERRIDE_LMEM_BYTES_PER_SM_THROTTLE_LIMIT_STRING               "ef0875a2"
#define OVERRIDE_LMEM_BYTES_PER_SM_THROTTLE_LIMIT_ID                   0x00d153a5
#define OVERRIDE_LMEM_BYTES_PER_SM_THROTTLE_LIMIT_OVERINSTALL          0 // OVERRIDE
#define OVERRIDE_LMEM_BYTES_PER_SM_THROTTLE_LIMIT_DEFAULT              0x00800000


#define PARTIALTEXFP16ENABLE_STRING                                    "62609925"
#define PARTIALTEXFP16ENABLE_ID                                        0x0006b458
#define PARTIALTEXFP16ENABLE_OVERINSTALL                               0 // OVERRIDE
#define PARTIALTEXFP16ENABLE_PASSIVE                                   0xffffffff
#define PARTIALTEXFP16ENABLE_FORCEOFF                                  0x05584652
#define PARTIALTEXFP16ENABLE_DISABLE                                   0x05584652
#define PARTIALTEXFP16ENABLE_OFF                                       0x05584652
#define PARTIALTEXFP16ENABLE_FALSE                                     0x05584652
#define PARTIALTEXFP16ENABLE_0                                         0x05584652
#define PARTIALTEXFP16ENABLE_FORCEON                                   0x44737498
#define PARTIALTEXFP16ENABLE_ENABLE                                    0x44737498
#define PARTIALTEXFP16ENABLE_ON                                        0x44737498
#define PARTIALTEXFP16ENABLE_TRUE                                      0x44737498
#define PARTIALTEXFP16ENABLE_1                                         0x44737498
#define PARTIALTEXFP16ENABLE_DEFAULT                                   PARTIALTEXFP16ENABLE_PASSIVE


#define PARTIALTEXFP32ENABLE_STRING                                    "01780627"
#define PARTIALTEXFP32ENABLE_ID                                        0x00924126
#define PARTIALTEXFP32ENABLE_OVERINSTALL                               0 // OVERRIDE
#define PARTIALTEXFP32ENABLE_PASSIVE                                   0xffffffff
#define PARTIALTEXFP32ENABLE_FORCEOFF                                  0x18029049
#define PARTIALTEXFP32ENABLE_DISABLE                                   0x18029049
#define PARTIALTEXFP32ENABLE_OFF                                       0x18029049
#define PARTIALTEXFP32ENABLE_FALSE                                     0x18029049
#define PARTIALTEXFP32ENABLE_0                                         0x18029049
#define PARTIALTEXFP32ENABLE_FORCEON                                   0x09663533
#define PARTIALTEXFP32ENABLE_ENABLE                                    0x09663533
#define PARTIALTEXFP32ENABLE_ON                                        0x09663533
#define PARTIALTEXFP32ENABLE_TRUE                                      0x09663533
#define PARTIALTEXFP32ENABLE_1                                         0x09663533
#define PARTIALTEXFP32ENABLE_DEFAULT                                   PARTIALTEXFP32ENABLE_PASSIVE


#define PARTIALTEXHEURISTIC_STRING                                     "C472D770"
#define PARTIALTEXHEURISTIC_ID                                         0x00da0d0b
#define PARTIALTEXHEURISTIC_OVERINSTALL                                0 // OVERRIDE
#define PARTIALTEXHEURISTIC_DEFAULT                                    0x01fffe00


#define PASCAL_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                    "0x523da1"
#define PASCAL_A_TILEDCACHE_BUFFERINTERLEAVE_ID                        0x00523da1
#define PASCAL_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL               0 // OVERRIDE
#define PASCAL_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                   0x00002313


#define PASCAL_A_TILEDCACHE_CONTROL_STRING                             "0x523da2"
#define PASCAL_A_TILEDCACHE_CONTROL_ID                                 0x00523da2
#define PASCAL_A_TILEDCACHE_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define PASCAL_A_TILEDCACHE_CONTROL_DEFAULT                            0x08080202


#define PASCAL_A_TILEDCACHE_CONTROL_EXTENDED_STRING                    "0x523da3"
#define PASCAL_A_TILEDCACHE_CONTROL_EXTENDED_ID                        0x00523da3
#define PASCAL_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL               0 // OVERRIDE
#define PASCAL_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                   0x00000008


#define PASCAL_A_TILEDCACHE_L2_USAGE_STRING                            "0x523da5"
#define PASCAL_A_TILEDCACHE_L2_USAGE_ID                                0x00523da5
#define PASCAL_A_TILEDCACHE_L2_USAGE_OVERINSTALL                       0 // OVERRIDE
#define PASCAL_A_TILEDCACHE_L2_USAGE_DEFAULT                           0.5f


#define PASCAL_A_TILEDCACHE_STATETHRESHOLD_STRING                      "0x523da4"
#define PASCAL_A_TILEDCACHE_STATETHRESHOLD_ID                          0x00523da4
#define PASCAL_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                 0 // OVERRIDE
#define PASCAL_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                     0x00080001


#define PASCAL_BINNED_OCC_QUERY_STRING                                 "0xC06FF"
#define PASCAL_BINNED_OCC_QUERY_ID                                     0x000c06fc
#define PASCAL_BINNED_OCC_QUERY_OVERINSTALL                            0 // OVERRIDE
#define PASCAL_BINNED_OCC_QUERY_OFF                                    0x00000000
#define PASCAL_BINNED_OCC_QUERY_DISABLED                               0x00000000
#define PASCAL_BINNED_OCC_QUERY_ON                                     0x00000001
#define PASCAL_BINNED_OCC_QUERY_ENABLED                                0x00000001
#define PASCAL_BINNED_OCC_QUERY_DEFAULT                                PASCAL_BINNED_OCC_QUERY_OFF


#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_STRING                  "0x097245"
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_ID                      0x00097245
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_OVERINSTALL             0 // OVERRIDE
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_OFF                     0
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_DISABLED                0
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_ON                      1
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_ENABLED                 1
#define PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_DEFAULT                 PASCAL_ENABLE_CLAMP_FP_BLEND_TO_MAXVAL_ON


#define PASCAL_IQ2M_STRING                                             "0x54259"
#define PASCAL_IQ2M_ID                                                 0x00054259
#define PASCAL_IQ2M_OVERINSTALL                                        0 // OVERRIDE
#define PASCAL_IQ2M_OFF                                                0x00000000
#define PASCAL_IQ2M_DISABLED                                           0x00000000
#define PASCAL_IQ2M_ON                                                 0x00000001
#define PASCAL_IQ2M_ENABLED                                            0x00000001
#define PASCAL_IQ2M_DEFAULT                                            PASCAL_IQ2M_ON


#define PATH_TO_NVAPPS_XML_STRING                                      "XML_PATH"
#define PATH_TO_NVAPPS_XML_ID                                          0x00220a45
#define PATH_TO_NVAPPS_XML_OVERINSTALL                                 0 // OVERRIDE


#define PBSPACEMULTIPLIER_STRING                                       "72D7C740"
#define PBSPACEMULTIPLIER_ID                                           0x00dab00b
#define PBSPACEMULTIPLIER_OVERINSTALL                                  0 // OVERRIDE
#define PBSPACEMULTIPLIER_DEFAULT                                      0


#define PCITEXHEAPSIZE_STRING                                          "92521178"
#define PCITEXHEAPSIZE_ID                                              0x008a472b
#define PCITEXHEAPSIZE_OVERINSTALL                                     0 // OVERRIDE
#define PCITEXHEAPSIZE_MIN                                             0x00000000
#define PCITEXHEAPSIZE_MAX                                             0xFFFFFFFF
#define PCITEXHEAPSIZE_DEFAULT                                         0


#define PRECISIONDEMOTION_STRING                                       "56964724"
#define PRECISIONDEMOTION_ID                                           0x00ba3a25
#define PRECISIONDEMOTION_OVERINSTALL                                  0 // OVERRIDE
#define PRECISIONDEMOTION_OFF                                          0x00000000
#define PRECISIONDEMOTION_DEMOTE                                       0x00000001
#define PRECISIONDEMOTION_DISABLE                                      0x00000002
#define PRECISIONDEMOTION_DEFAULT                                      PRECISIONDEMOTION_OFF


#define PREFERRED_Z16_PAGEKIND_STRING                                  "0x07aaaa"
#define PREFERRED_Z16_PAGEKIND_ID                                      0x0007aaaa
#define PREFERRED_Z16_PAGEKIND_OVERINSTALL                             0 // OVERRIDE
#define PREFERRED_Z16_PAGEKIND_KIND_2C                                 0x1
#define PREFERRED_Z16_PAGEKIND_KIND_2CZ                                0x2


#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_STRING "0x2808D9"
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_ID 0x002808d9
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_OVERINSTALL 0 // OVERRIDE
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_OFF 0
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_DISABLED 0
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_ON 1
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_ENABLED 1
#define PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_DEFAULT PREFER_DRIVER_CREATED_SYNCOBJ_INTERCHANNEL_SYNC_BUG_2867804_OFF


#define PRERENDERLIMIT_STRING                                          "98764205"
#define PRERENDERLIMIT_ID                                              0x007ba09e
#define PRERENDERLIMIT_OVERINSTALL                                     1 // MERGE
#define PRERENDERLIMIT_MIN                                             0x00
#define PRERENDERLIMIT_MAX                                             0xff
#define PRERENDERLIMIT_APP_CONTROLLED                                  0x00
#define PRERENDERLIMIT_DEFAULT                                         PRERENDERLIMIT_APP_CONTROLLED


#define PRERENDERLIMIT_DEVFLAGS_STRING                                 "98764206"
#define PRERENDERLIMIT_DEVFLAGS_ID                                     0x007ba09f
#define PRERENDERLIMIT_DEVFLAGS_OVERINSTALL                            0 // OVERRIDE
#define PRERENDERLIMIT_DEVFLAGS_DEFAULT                                0x00000000
#define PRERENDERLIMIT_DEVFLAGS_MASK                                   0x00000003
#define PRERENDERLIMIT_DEVFLAGS_DISABLE_NOTIFIER_WAIT                  0x00000001
#define PRERENDERLIMIT_DEVFLAGS_ENABLE_NOTIFIER_VSYNC_OFF              0x00000002


#define PRESERVEZONRTCHANGE_STRING                                     "89464897"
#define PRESERVEZONRTCHANGE_ID                                         0x00044b0a
#define PRESERVEZONRTCHANGE_OVERINSTALL                                0 // OVERRIDE
#define PRESERVEZONRTCHANGE_OFF                                        0x00000000
#define PRESERVEZONRTCHANGE_DISABLED                                   0x00000000
#define PRESERVEZONRTCHANGE_ON                                         0x00000001
#define PRESERVEZONRTCHANGE_ENABLED                                    0x00000001
#define PRESERVEZONRTCHANGE_DEFAULT                                    PRESERVEZONRTCHANGE_OFF


#define PREVENTNEGATIVESQRT_STRING                                     "13385476"
#define PREVENTNEGATIVESQRT_ID                                         0x00225254
#define PREVENTNEGATIVESQRT_OVERINSTALL                                0 // OVERRIDE
#define PREVENTNEGATIVESQRT_OFF                                        0x00000000
#define PREVENTNEGATIVESQRT_VERTEX_SHADER                              0x00000001
#define PREVENTNEGATIVESQRT_GEOMETRY_SHADER                            0x00000002
#define PREVENTNEGATIVESQRT_PIXEL_SHADER                               0x00000004
#define PREVENTNEGATIVESQRT_HULL_SHADER                                0x00000008
#define PREVENTNEGATIVESQRT_DOMAIN_SHADER                              0x00000010
#define PREVENTNEGATIVESQRT_COMPUTE_SHADER                             0x00000020
#define PREVENTNEGATIVESQRT_MASK                                       0x0000003f
#define PREVENTNEGATIVESQRT_DEFAULT                                    PREVENTNEGATIVESQRT_OFF


#define PRIMARY_COMPRESSION_STRING                                     "0xb21c03"
#define PRIMARY_COMPRESSION_ID                                         0x00b21c03
#define PRIMARY_COMPRESSION_OVERINSTALL                                0 // OVERRIDE
#define PRIMARY_COMPRESSION_ENABLE_ALL                                 0x000000
#define PRIMARY_COMPRESSION_DISABLE_SINGLE_GPU                         0x000001
#define PRIMARY_COMPRESSION_DISABLE_SLI                                0x000002
#define PRIMARY_COMPRESSION_DISABLE_SFR_WITH_CE                        0x000004
#define PRIMARY_COMPRESSION_DISABLE_DX12                               0x000008
#define PRIMARY_COMPRESSION_DISABLE_DX11_SFR                           0x000010
#define PRIMARY_COMPRESSION_DISABLE_DX12_SFR                           0x000020
#define PRIMARY_COMPRESSION_DISABLE_ALL                                0x00003F
#define PRIMARY_COMPRESSION_ALLOW_PRIMARY_GPU                          0x010000
#define PRIMARY_COMPRESSION_ALLOW_PRE_TURING                           0x020000
#define PRIMARY_COMPRESSION_DEFAULT                                    PRIMARY_COMPRESSION_DISABLE_DX12_SFR


#define PRI_SETTINGS_STRING                                            "210204"
#define PRI_SETTINGS_ID                                                0x00210204
#define PRI_SETTINGS_OVERINSTALL                                       0 // OVERRIDE
#define PRI_SETTINGS_DEFAULT                                           ""


#define PROFILEFOG_STRING                                              "44457569"
#define PROFILEFOG_ID                                                  0x00cd6d35
#define PROFILEFOG_OVERINSTALL                                         0 // OVERRIDE
#define PROFILEFOG_OFF                                                 0x64321281
#define PROFILEFOG_DISABLED                                            0x64321281
#define PROFILEFOG_ON                                                  0x44283701
#define PROFILEFOG_ENABLED                                             0x44283701
#define PROFILEFOG_DEFAULT                                             PROFILEFOG_OFF


#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_STRING                 "44597415"
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_ID                     0x00f62479
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_OVERINSTALL            0 // OVERRIDE
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_OFF                    0x00000000
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_DISABLED               0x00000000
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_ON                     0x00000001
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_ENABLED                0x00000001
#define PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_DEFAULT                PROMOTE_WRITE_ONLY_DYNAMIC_IB_TO_VIDMEM_OFF


#define PROVIDE_QUAD_TEX_STATE_TO_COP_STRING                           "511f14"
#define PROVIDE_QUAD_TEX_STATE_TO_COP_ID                               0x00511f14
#define PROVIDE_QUAD_TEX_STATE_TO_COP_OVERINSTALL                      0 // OVERRIDE
#define PROVIDE_QUAD_TEX_STATE_TO_COP_OFF                              0x68331468
#define PROVIDE_QUAD_TEX_STATE_TO_COP_DISABLED                         0x68331468
#define PROVIDE_QUAD_TEX_STATE_TO_COP_ON                               0x69843965
#define PROVIDE_QUAD_TEX_STATE_TO_COP_ENABLED                          0x69843965
#define PROVIDE_QUAD_TEX_STATE_TO_COP_DEFAULT                          PROVIDE_QUAD_TEX_STATE_TO_COP_ON


#define PSVERSIONCAP_STRING                                            "59954021"
#define PSVERSIONCAP_ID                                                0x002d852f
#define PSVERSIONCAP_OVERINSTALL                                       0 // OVERRIDE
#define PSVERSIONCAP_MIN                                               0xffff0000
#define PSVERSIONCAP_MAX                                               0xffffffff
#define PSVERSIONCAP_DEFAULT                                           0xffffffff


#define PS_ADDITIONAL_MIP_LOD_BIAS_STRING                              "1db1a5"
#define PS_ADDITIONAL_MIP_LOD_BIAS_ID                                  0x001db1a5
#define PS_ADDITIONAL_MIP_LOD_BIAS_OVERINSTALL                         0 // OVERRIDE
#define PS_ADDITIONAL_MIP_LOD_BIAS_DEFAULT                             0


#define PS_AMPERE_SURF_TILE_MAP_STRING                                 "ed871b"
#define PS_AMPERE_SURF_TILE_MAP_ID                                     0x00ed871b
#define PS_AMPERE_SURF_TILE_MAP_OVERINSTALL                            0 // OVERRIDE
#define PS_AMPERE_SURF_TILE_MAP_OFF                                    0x0
#define PS_AMPERE_SURF_TILE_MAP_DISABLED                               0x0
#define PS_AMPERE_SURF_TILE_MAP_ON                                     0x1
#define PS_AMPERE_SURF_TILE_MAP_ENABLED                                0x1
#define PS_AMPERE_SURF_TILE_MAP_DEFAULT                                PS_AMPERE_SURF_TILE_MAP_OFF


#define PS_AMPERE_SURF_TILE_MAP_ENABLE_HASH_STRING                     "efb720"
#define PS_AMPERE_SURF_TILE_MAP_ENABLE_HASH_ID                         0x00efb720
#define PS_AMPERE_SURF_TILE_MAP_ENABLE_HASH_OVERINSTALL                0 // OVERRIDE
#define PS_AMPERE_SURF_TILE_MAP_ENABLE_HASH_DEFAULT                    0


#define PS_AMPERE_SURF_TILE_MAP_FLAGS_STRING                           "efb71d"
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_ID                               0x00efb71d
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_OPTIMIZE_FOR_TLD4       0x00000001
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_COMPARE_HEADER_POOL_INDICES 0x00000002
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_USE_CODEGEN_HINTS                0x00000004
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_TMKERNEL_ENABLE_TILE_PER_THREAD_SUM 0x00000008
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_TMKERNEL_ENABLE_PRE_SUM_KERNEL   0x00000010
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_ENABLE_VA_RANGE_TRACKING         0x00000020
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_PREFER_PLC_FOR_ALL_PAGES         0x00000040
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_MEMOIZE_INITS           0x00000080
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_DISABLE_CONSUMER_CODEGEN         0x00001000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_OPTIMIZE_FOR_ALLCLEAN_TILES      0x00002000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_ALLCLEAN_OR_DIRTY       0x00004000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_TMKERNEL_ENABLE_SHMEMOPT_FOR_LINEAR_FILTER 0x00008000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_CODE_SPECIALIZE_FOR_ZEROS 0x00010000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_CONSUMER_CHECK_TILEMAP_READINESS 0x00020000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_TMKERNEL_ENABLE_SUQUERY_PER_THREAD_SUM 0x00040000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_TMKERNEL_LOOP_OVER_TEXSLOTS      0x00080000
#define PS_AMPERE_SURF_TILE_MAP_FLAGS_DEFAULT                          0x000000af


#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_STRING                    "efb71f"
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_ID                        0x00efb71f
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_OVERINSTALL               0 // OVERRIDE
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_GATHER_GENERAL_STATS      0x00000001
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_GATHER_PROFILE_DATA       0x00000002
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_CONSUMER_DYNAMIC_COUNTS   0x00000004
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_CONSUMER_PMTRIGS          0x00000008
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT0             0x00001000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT1             0x00002000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT2             0x00004000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT3             0x00008000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT4             0x00010000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT5             0x00020000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DISABLE_SLOT6             0x00040000
#define PS_AMPERE_SURF_TILE_MAP_HELPER_FLAGS_DEFAULT                   0


#define PS_AMPERE_SURF_TILE_MAP_PROFILE_FILENAME_STRING                "0xefb71e"
#define PS_AMPERE_SURF_TILE_MAP_PROFILE_FILENAME_ID                    0x00efb71e
#define PS_AMPERE_SURF_TILE_MAP_PROFILE_FILENAME_OVERINSTALL           0 // OVERRIDE


#define PS_ANSEL_DEBUGGING_STRING                                      "421fe32E"
#define PS_ANSEL_DEBUGGING_ID                                          0x00ae6839
#define PS_ANSEL_DEBUGGING_OVERINSTALL                                 0 // OVERRIDE
#define PS_ANSEL_DEBUGGING_OFF                                         0x18F3902C
#define PS_ANSEL_DEBUGGING_DISABLED                                    0x18F3902C
#define PS_ANSEL_DEBUGGING_ON                                          0x18F3902D
#define PS_ANSEL_DEBUGGING_ENABLED                                     0x18F3902D
#define PS_ANSEL_DEBUGGING_DEFAULT                                     PS_ANSEL_DEBUGGING_OFF


#define PS_APPSHADEROPT_BIOSHOCK_STRING                                "6ec29f31"
#define PS_APPSHADEROPT_BIOSHOCK_ID                                    0x00fef119
#define PS_APPSHADEROPT_BIOSHOCK_OVERINSTALL                           0 // OVERRIDE
#define PS_APPSHADEROPT_BIOSHOCK_OFF                                   0x00000013
#define PS_APPSHADEROPT_BIOSHOCK_0                                     0x00000013
#define PS_APPSHADEROPT_BIOSHOCK_FALSE                                 0x00000013
#define PS_APPSHADEROPT_BIOSHOCK_DISABLED                              0x00000013
#define PS_APPSHADEROPT_BIOSHOCK_ON                                    0x95ef21de
#define PS_APPSHADEROPT_BIOSHOCK_1                                     0x95ef21de
#define PS_APPSHADEROPT_BIOSHOCK_TRUE                                  0x95ef21de
#define PS_APPSHADEROPT_BIOSHOCK_ENABLED                               0x95ef21de
#define PS_APPSHADEROPT_BIOSHOCK_DEFAULT                               PS_APPSHADEROPT_BIOSHOCK_ON


#define PS_APPSHADEROPT_CONVERT_OR2ADD_STRING                          "6af0072f"
#define PS_APPSHADEROPT_CONVERT_OR2ADD_ID                              0x007007aa
#define PS_APPSHADEROPT_CONVERT_OR2ADD_OVERINSTALL                     0 // OVERRIDE
#define PS_APPSHADEROPT_CONVERT_OR2ADD_OFF                             0x90f95a35
#define PS_APPSHADEROPT_CONVERT_OR2ADD_DISABLED                        0x90f95a35
#define PS_APPSHADEROPT_CONVERT_OR2ADD_ON                              0xf3f28a38
#define PS_APPSHADEROPT_CONVERT_OR2ADD_ENABLED                         0xf3f28a38
#define PS_APPSHADEROPT_CONVERT_OR2ADD_DEFAULT                         PS_APPSHADEROPT_CONVERT_OR2ADD_ON


#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_STRING                     "6a897a2e"
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_ID                         0x0070dea9
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_OVERINSTALL                0 // OVERRIDE
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_OFF                        0x97395a35
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_DISABLED                   0x97395a35
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_ON                         0xde325a38
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_ENABLED                    0xde325a38
#define PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_DEFAULT                    PS_APPSHADEROPT_PROMOTE1DTEXTO2DTEX_OFF


#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_STRING        "6af00730"
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_ID            0x007007ab
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_OVERINSTALL   0 // OVERRIDE
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_OFF           0x90f95a35
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_DISABLED      0x90f95a35
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_ON            0xf3f28a38
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_ENABLED       0xf3f28a38
#define PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_DEFAULT       PS_APPSHADEROPT_REFACTOR_HDAO_SAMPLE_COMPUTATION_ON


#define PS_APP_SPECIFIC_HACKS_STRING                                   "caef55"
#define PS_APP_SPECIFIC_HACKS_ID                                       0x0004ee27
#define PS_APP_SPECIFIC_HACKS_OVERINSTALL                              0 // OVERRIDE
#define PS_APP_SPECIFIC_HACKS_OFF                                      0x00000000
#define PS_APP_SPECIFIC_HACKS_DISABLED                                 0x00000000
#define PS_APP_SPECIFIC_HACKS_ON                                       0x00000001
#define PS_APP_SPECIFIC_HACKS_ENABLED                                  0x00000001
#define PS_APP_SPECIFIC_HACKS_DEFAULT                                  PS_APP_SPECIFIC_HACKS_ON


#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_STRING                     "03122587"
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_ID                         0x00287317
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_OVERINSTALL                0 // OVERRIDE
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_DISABLE_ALL                0x00000004
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_DISABLE_BOKEH_DOF          0x00000001
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_DISABLE_SSDO               0x00000002
#define PS_APP_SPECIFIC_HACKS_CRYSIS3_FLAGS_DEFAULT                    0


#define PS_APP_SPECIFIC_HACKS_FLAGS_STRING                             "cabeff"
#define PS_APP_SPECIFIC_HACKS_FLAGS_ID                                 0x00062e37
#define PS_APP_SPECIFIC_HACKS_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_APP_SPECIFIC_HACKS_FLAGS_VERBOSE_SPEW                       0x00000001
#define PS_APP_SPECIFIC_HACKS_FLAGS_DEFAULT                            0x00000000


#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_STRING                   "03122444"
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_ID                       0x00287444
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_OVERINSTALL              0 // OVERRIDE
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_ALL              0x10000000
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_MULTIPASS        0x00000001
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_MAX_REG_TARGET   0x00000002
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_USER_CLIP_PLANE_WAR 0x00000004
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_LIGHT_TILE_EARLY_EXIT 0x00000008
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_FORCE_STENCIL_GENERATE_ON_EVERY_DRAW 0x00000010
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_MSAA_SHADOW_OPT  0x00000020
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_SPRITE_DOF_SPLAT 0x00000040
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_SSSCONV          0x00000080
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_HBAO_BLUR        0x00000100
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DISABLE_LIGHT_TILE_CLEAR 0x00000200
#define PS_APP_SPECIFIC_HACKS_FROSTBITE_FLAGS_DEFAULT                  0


#define PS_APP_SPECIFIC_HACK_AMDHDAO_STRING                            "caef60"
#define PS_APP_SPECIFIC_HACK_AMDHDAO_ID                                0x0004ee2c
#define PS_APP_SPECIFIC_HACK_AMDHDAO_OVERINSTALL                       0 // OVERRIDE
#define PS_APP_SPECIFIC_HACK_AMDHDAO_OFF                               0x00000000
#define PS_APP_SPECIFIC_HACK_AMDHDAO_DISABLED                          0x00000000
#define PS_APP_SPECIFIC_HACK_AMDHDAO_ON                                0x00000001
#define PS_APP_SPECIFIC_HACK_AMDHDAO_ENABLED                           0x00000001
#define PS_APP_SPECIFIC_HACK_AMDHDAO_DEFAULT                           PS_APP_SPECIFIC_HACK_AMDHDAO_ON


#define PS_APP_SPECIFIC_HACK_COD_BO3_STRING                            "caef57"
#define PS_APP_SPECIFIC_HACK_COD_BO3_ID                                0x0004ee29
#define PS_APP_SPECIFIC_HACK_COD_BO3_OVERINSTALL                       0 // OVERRIDE
#define PS_APP_SPECIFIC_HACK_COD_BO3_OFF                               0x00000000
#define PS_APP_SPECIFIC_HACK_COD_BO3_DISABLED                          0x00000000
#define PS_APP_SPECIFIC_HACK_COD_BO3_ON                                0x00000001
#define PS_APP_SPECIFIC_HACK_COD_BO3_ENABLED                           0x00000001
#define PS_APP_SPECIFIC_HACK_COD_BO3_DEFAULT                           PS_APP_SPECIFIC_HACK_COD_BO3_ON


#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_STRING                   "caef58"
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_ID                       0x0004ee2a
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_OVERINSTALL              0 // OVERRIDE
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_OFF                      0x00000000
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_DISABLED                 0x00000000
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_ON                       0x00000001
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_ENABLED                  0x00000001
#define PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_DEFAULT                  PS_APP_SPECIFIC_HACK_METRO_LAST_LIGHT_ON


#define PS_APP_SPECIFIC_HACK_RE5_STRING                                "caef59"
#define PS_APP_SPECIFIC_HACK_RE5_ID                                    0x0004ee2b
#define PS_APP_SPECIFIC_HACK_RE5_OVERINSTALL                           0 // OVERRIDE
#define PS_APP_SPECIFIC_HACK_RE5_OFF                                   0x00000000
#define PS_APP_SPECIFIC_HACK_RE5_DISABLED                              0x00000000
#define PS_APP_SPECIFIC_HACK_RE5_ON                                    0x00000001
#define PS_APP_SPECIFIC_HACK_RE5_ENABLED                               0x00000001
#define PS_APP_SPECIFIC_HACK_RE5_DEFAULT                               PS_APP_SPECIFIC_HACK_RE5_ON


#define PS_ASYNC_SHADER_SCHEDULER_STRING                               "f3843933"
#define PS_ASYNC_SHADER_SCHEDULER_ID                                   0x00c9af50
#define PS_ASYNC_SHADER_SCHEDULER_OVERINSTALL                          0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_OFF                                  0xa2b53761
#define PS_ASYNC_SHADER_SCHEDULER_DISABLED                             0xa2b53761
#define PS_ASYNC_SHADER_SCHEDULER_ON                                   0x79292610
#define PS_ASYNC_SHADER_SCHEDULER_ENABLED                              0x79292610


#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_STRING                         "f3843934"
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_ID                             0x00313536
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_IGNORE_LOAD_BALANCING          0x00000001
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_IGNORE_QUOTAS                  0x00000002
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_IGNORE_GARBAGE_COLLECT_THRESHOLD 0x00000004
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DISABLE_GARBAGE_COLLECTION     0x00000008
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_COMPILE_IMMEDIATELY            0x00000100
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_LIMIT_SHADER_CREATION_TO_ONE_THREAD 0x00000200
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_LIMIT_OPTIMIZED_SHADER_RECOMPILE_TO_ONE_THREAD 0x00000400
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DISABLE_MULTI_APP_THREAD_HEURISTIC 0x00000800
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DISABLE_OPTIMIZED_SHADER_RECOMPILE 0x00001000
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DISABLE_SHADER_CREATION        0x00002000
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_FORCE_NV_THREADS               0x00010000
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DISABLE_BACKGROUND_PROCESSING_CAPS 0x00020000


#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_STRING                    "f3fa17f8"
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_ID                        0x0034d294
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_OVERINSTALL               0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_DISABLE_DEFAULT_PSO_ASYNC_COMPILE 0x00000004
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_DISABLE_OPTIONAL_PSO_ASYNC_COMPILE 0x00000008
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_DISABLE_DEFAULT_SO_ASYNC_COMPILE 0x00000010
#define PS_ASYNC_SHADER_SCHEDULER_FLAGS_DX12_DEFAULT                   0


#define PS_ASYNC_SHADER_SCHEDULER_MAX_CONCURRENT_COMPILES_STRING       "36508643"
#define PS_ASYNC_SHADER_SCHEDULER_MAX_CONCURRENT_COMPILES_ID           0x001f6342
#define PS_ASYNC_SHADER_SCHEDULER_MAX_CONCURRENT_COMPILES_OVERINSTALL  0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_MAX_CONCURRENT_COMPILES_DEFAULT      0x7fffffff


#define PS_ASYNC_SHADER_SCHEDULER_MAX_DEFAULT_OUTSTANDING_MEMORY_STRING "36871294"
#define PS_ASYNC_SHADER_SCHEDULER_MAX_DEFAULT_OUTSTANDING_MEMORY_ID    0x00198462
#define PS_ASYNC_SHADER_SCHEDULER_MAX_DEFAULT_OUTSTANDING_MEMORY_OVERINSTALL 0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_MAX_DEFAULT_OUTSTANDING_MEMORY_DEFAULT 0x800000


#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_OUTSTANDING_MEMORY_STRING "36098285"
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_OUTSTANDING_MEMORY_ID   0x001f7f37
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_OUTSTANDING_MEMORY_OVERINSTALL 0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_OUTSTANDING_MEMORY_DEFAULT 0x100000


#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_THREADS_STRING          "f3843935"
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_THREADS_ID              0x00313537
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_THREADS_OVERINSTALL     0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_MAX_OPTIONAL_THREADS_DEFAULT         0xFFFFFFFF


#define PS_ASYNC_SHADER_SCHEDULER_PENDING_FRAME_LIMIT_STRING           "28104837"
#define PS_ASYNC_SHADER_SCHEDULER_PENDING_FRAME_LIMIT_ID               0x0010f84f
#define PS_ASYNC_SHADER_SCHEDULER_PENDING_FRAME_LIMIT_OVERINSTALL      0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_PENDING_FRAME_LIMIT_DEFAULT          0x10


#define PS_ASYNC_SHADER_SCHEDULER_PER_FRAME_BACKGROUND_LIMIT_STRING    "34509665"
#define PS_ASYNC_SHADER_SCHEDULER_PER_FRAME_BACKGROUND_LIMIT_ID        0x000e9361
#define PS_ASYNC_SHADER_SCHEDULER_PER_FRAME_BACKGROUND_LIMIT_OVERINSTALL 0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_PER_FRAME_BACKGROUND_LIMIT_DEFAULT   0x1000


#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_STRING             "f3849836"
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_ID                 0x00c99836
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_OVERINSTALL        0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_OFF                0xa2b53761
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_DISABLED           0xa2b53761
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_ON                 0x79292610
#define PS_ASYNC_SHADER_SCHEDULER_TRACK_STACK_USAGE_ENABLED            0x79292610


#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_FRAME_LIMIT_STRING            "10293048"
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_FRAME_LIMIT_ID                0x00a83fa9
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_FRAME_LIMIT_OVERINSTALL       0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_FRAME_LIMIT_DEFAULT           0x3


#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_TIME_LIMIT_STRING             "19f01827"
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_TIME_LIMIT_ID                 0x00a2910f
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_TIME_LIMIT_OVERINSTALL        0 // OVERRIDE
#define PS_ASYNC_SHADER_SCHEDULER_UNUSED_TIME_LIMIT_DEFAULT            5.0


#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_STRING                     "f3849838"
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_ID                         0x00c99838
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_OVERINSTALL                0 // OVERRIDE
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_USE_SPINLOOP_TASKS         0x00000001
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_MASK_TASK_TYPE             0x000000ff
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_USE_NO_REQUEUE             0x00000100
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_USE_REQUEUE_IMMEDIATELY    0x00000200
#define PS_ASYNC_TASK_SCHEDULER_DEBUG_TASKS_MASK_REQUEUE_TYPE          0x0000ff00


#define PS_ASYNC_TASK_SCHEDULER_FLAGS_STRING                           "f3849837"
#define PS_ASYNC_TASK_SCHEDULER_FLAGS_ID                               0x00c99837
#define PS_ASYNC_TASK_SCHEDULER_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_ASYNC_TASK_SCHEDULER_FLAGS_COMPILE_IMMEDIATELY              0x00000001
#define PS_ASYNC_TASK_SCHEDULER_FLAGS_DISABLE_BACKGROUND_PROCESSING_CAPS 0x00000004
#define PS_ASYNC_TASK_SCHEDULER_FLAGS_FORCE_NV_THREADS                 0x00010000


#define PS_AUTOMIPMAP_STRING                                           "04457569"
#define PS_AUTOMIPMAP_ID                                               0x0074cb43
#define PS_AUTOMIPMAP_OVERINSTALL                                      0 // OVERRIDE
#define PS_AUTOMIPMAP_OFF                                              0x47476671
#define PS_AUTOMIPMAP_DISABLED                                         0x47476671
#define PS_AUTOMIPMAP_ON                                               0x76475021
#define PS_AUTOMIPMAP_ENABLED                                          0x76475021


#define PS_AUTOMIPMAP_TMAA_STRING                                      "97022526"
#define PS_AUTOMIPMAP_TMAA_ID                                          0x00522446
#define PS_AUTOMIPMAP_TMAA_OVERINSTALL                                 0 // OVERRIDE
#define PS_AUTOMIPMAP_TMAA_OFF                                         0x47476671
#define PS_AUTOMIPMAP_TMAA_DISABLED                                    0x47476671
#define PS_AUTOMIPMAP_TMAA_ON                                          0x76475021
#define PS_AUTOMIPMAP_TMAA_ENABLED                                     0x76475021
#define PS_AUTOMIPMAP_TMAA_DEFAULT                                     PS_AUTOMIPMAP_TMAA_OFF


#define PS_AUTOVRS_STRING                                              "d52e49c6"
#define PS_AUTOVRS_ID                                                  0x00d5e9c6
#define PS_AUTOVRS_OVERINSTALL                                         0 // OVERRIDE
#define PS_AUTOVRS_OFF                                                 0x00000000
#define PS_AUTOVRS_ON                                                  0x00000001
#define PS_AUTOVRS_DEFAULT                                             PS_AUTOVRS_OFF


#define PS_AUTOVRS_FLAGS_STRING                                        "524253"
#define PS_AUTOVRS_FLAGS_ID                                            0x00524253
#define PS_AUTOVRS_FLAGS_OVERINSTALL                                   0 // OVERRIDE
#define PS_AUTOVRS_FLAGS_OFF                                           0x00000000
#define PS_AUTOVRS_FLAGS_0                                             0x00000000
#define PS_AUTOVRS_FLAGS_FALSE                                         0x00000000
#define PS_AUTOVRS_FLAGS_DISABLE_STEREO                                0x00000001
#define PS_AUTOVRS_FLAGS_DISABLE_CUBEMAP_SS                            0x00000002
#define PS_AUTOVRS_FLAGS_INVERTED_WINDOW_RENDER                        0x00000004
#define PS_AUTOVRS_FLAGS_DEFAULT                                       PS_AUTOVRS_FLAGS_OFF


#define PS_AUTOVRS_FOVEA_ELLIPSE_AXESRATIO_STRING                      "524255"
#define PS_AUTOVRS_FOVEA_ELLIPSE_AXESRATIO_ID                          0x00524255
#define PS_AUTOVRS_FOVEA_ELLIPSE_AXESRATIO_OVERINSTALL                 0 // OVERRIDE
#define PS_AUTOVRS_FOVEA_ELLIPSE_AXESRATIO_DEFAULT                     1.0f


#define PS_AUTOVRS_FOVEA_SIZE_STRING                                   "524254"
#define PS_AUTOVRS_FOVEA_SIZE_ID                                       0x00524254
#define PS_AUTOVRS_FOVEA_SIZE_OVERINSTALL                              0 // OVERRIDE
#define PS_AUTOVRS_FOVEA_SIZE_DEFAULT                                  50.0f


#define PS_AUTOVRS_GAZE_USAGE_ENABLE_STRING                            "524272"
#define PS_AUTOVRS_GAZE_USAGE_ENABLE_ID                                0x00524272
#define PS_AUTOVRS_GAZE_USAGE_ENABLE_OVERINSTALL                       0 // OVERRIDE
#define PS_AUTOVRS_GAZE_USAGE_ENABLE_OFF                               0x00000000
#define PS_AUTOVRS_GAZE_USAGE_ENABLE_ON                                0x00000001
#define PS_AUTOVRS_GAZE_USAGE_ENABLE_DEFAULT                           PS_AUTOVRS_GAZE_USAGE_ENABLE_ON


#define PS_AUTOVRS_HOTKEYS_STRING                                      "d52e49c9"
#define PS_AUTOVRS_HOTKEYS_ID                                          0x00d5e9c9
#define PS_AUTOVRS_HOTKEYS_OVERINSTALL                                 0 // OVERRIDE
#define PS_AUTOVRS_HOTKEYS_OFF                                         0x00000000
#define PS_AUTOVRS_HOTKEYS_ON                                          0x00000001
#define PS_AUTOVRS_HOTKEYS_DEFAULT                                     PS_AUTOVRS_HOTKEYS_OFF


#define PS_AUTOVRS_INDICATOR_STRING                                    "524256"
#define PS_AUTOVRS_INDICATOR_ID                                        0x00524256
#define PS_AUTOVRS_INDICATOR_OVERINSTALL                               0 // OVERRIDE
#define PS_AUTOVRS_INDICATOR_OFF                                       0x00000000
#define PS_AUTOVRS_INDICATOR_ON                                        0x00000001
#define PS_AUTOVRS_INDICATOR_DEFAULT                                   PS_AUTOVRS_INDICATOR_OFF


#define PS_AUTOVRS_OPTIONS_STRING                                      "d52e49c7"
#define PS_AUTOVRS_OPTIONS_ID                                          0x00d5e9c7
#define PS_AUTOVRS_OPTIONS_OVERINSTALL                                 1 // MERGE
#define PS_AUTOVRS_OPTIONS_DISABLED                                    0x00000000
#define PS_AUTOVRS_OPTIONS_FORCED_ON                                   0x00000001
#define PS_AUTOVRS_OPTIONS_GPU_ADAPTIVE_ON                             0x00000002
#define PS_AUTOVRS_OPTIONS_FORCED_FULLSCREEN                           0x00000003
#define PS_AUTOVRS_OPTIONS_DEFAULT                                     PS_AUTOVRS_OPTIONS_DISABLED


#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_STRING                 "524251"
#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_ID                     0x00524251
#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_OVERINSTALL            0 // OVERRIDE
#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_OFF                    0x00000000
#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_ON                     0x00000001
#define PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_DEFAULT                PS_AUTOVRS_OVERRIDE_LOADBALANCE_TARGETS_OFF


#define PS_AUTOVRS_SHADING_MODE_STRING                                 "d52e49c8"
#define PS_AUTOVRS_SHADING_MODE_ID                                     0x00d5e9c8
#define PS_AUTOVRS_SHADING_MODE_OVERINSTALL                            0 // OVERRIDE
#define PS_AUTOVRS_SHADING_MODE_SR_NONE                                0x0000
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_1x1                        0x0001
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_1x2                        0x0002
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_2x1                        0x0003
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_2x2                        0x0004
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_2x4                        0x0005
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_4x2                        0x0006
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_4x4                        0x0007
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_2xSS                       0x0008
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_4xSS                       0x0009
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_8xSS                       0x000a
#define PS_AUTOVRS_SHADING_MODE_SR_CONSTANT_16xSS                      0x000b
#define PS_AUTOVRS_SHADING_MODE_DEFAULT                                PS_AUTOVRS_SHADING_MODE_SR_NONE


#define PS_AUTOVRS_TARGET_GPUPERCENT_STRING                            "524250"
#define PS_AUTOVRS_TARGET_GPUPERCENT_ID                                0x00524250
#define PS_AUTOVRS_TARGET_GPUPERCENT_OVERINSTALL                       0 // OVERRIDE
#define PS_AUTOVRS_TARGET_GPUPERCENT_DEFAULT                           0.75f


#define PS_AUTOVRS_VR_CHECK_STRING                                     "524252"
#define PS_AUTOVRS_VR_CHECK_ID                                         0x00524252
#define PS_AUTOVRS_VR_CHECK_OVERINSTALL                                0 // OVERRIDE
#define PS_AUTOVRS_VR_CHECK_OFF                                        0x00000000
#define PS_AUTOVRS_VR_CHECK_ON                                         0x00000001
#define PS_AUTOVRS_VR_CHECK_DEFAULT                                    PS_AUTOVRS_VR_CHECK_ON


#define PS_BAD_BEHAVIOR_DETECTOR_STRING                                "4073ceba"
#define PS_BAD_BEHAVIOR_DETECTOR_ID                                    0x004cc557
#define PS_BAD_BEHAVIOR_DETECTOR_OVERINSTALL                           0 // OVERRIDE
#define PS_BAD_BEHAVIOR_DETECTOR_OFF                                   0xa2b53761
#define PS_BAD_BEHAVIOR_DETECTOR_DISABLED                              0xa2b53761
#define PS_BAD_BEHAVIOR_DETECTOR_ON                                    0x79292610
#define PS_BAD_BEHAVIOR_DETECTOR_ENABLED                               0x79292610
#define PS_BAD_BEHAVIOR_DETECTOR_DEFAULT                               PS_BAD_BEHAVIOR_DETECTOR_OFF


#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_STRING                          "5f84bdcb"
#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_ID                              0x004ab556
#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_OVERINSTALL                     0 // OVERRIDE
#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_ENABLE_BAD_RESET_DETECTION      0x00000001
#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_ENABLE_STALE_ROOT_DATA_DETECTION 0x00000002
#define PS_BAD_BEHAVIOR_DETECTOR_FLAGS_DEFAULT                         0


#define PS_BASIC_STATS_STRING                                          "22845966"
#define PS_BASIC_STATS_ID                                              0x00939825
#define PS_BASIC_STATS_OVERINSTALL                                     0 // OVERRIDE
#define PS_BASIC_STATS_OFF                                             0x91861384
#define PS_BASIC_STATS_DISABLED                                        0x91861384
#define PS_BASIC_STATS_ON                                              0x32788543
#define PS_BASIC_STATS_ENABLED                                         0x32788543


#define PS_BASIC_STATS_FLAGS_STRING                                    "00916149"
#define PS_BASIC_STATS_FLAGS_ID                                        0x0082f745
#define PS_BASIC_STATS_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_BASIC_STATS_FLAGS_STATS                                     0x00000001
#define PS_BASIC_STATS_FLAGS_MEMSPEEDS                                 0x00000002


#define PS_BINKVIDEO_STRING                                            "19343368"
#define PS_BINKVIDEO_ID                                                0x0007fa5f
#define PS_BINKVIDEO_OVERINSTALL                                       0 // OVERRIDE
#define PS_BINKVIDEO_OFF                                               0x00000000
#define PS_BINKVIDEO_DISABLED                                          0x00000000
#define PS_BINKVIDEO_ON                                                0x00000001
#define PS_BINKVIDEO_ENABLED                                           0x00000001


#define PS_BLENDOPT_STRING                                             "83015938"
#define PS_BLENDOPT_ID                                                 0x00c6f27d
#define PS_BLENDOPT_OVERINSTALL                                        0 // OVERRIDE
#define PS_BLENDOPT_OFF                                                0x00000000
#define PS_BLENDOPT_0                                                  0x00000000
#define PS_BLENDOPT_FALSE                                              0x00000000
#define PS_BLENDOPT_DISABLED                                           0x00000000
#define PS_BLENDOPT_ON                                                 0x00000001
#define PS_BLENDOPT_1                                                  0x00000001
#define PS_BLENDOPT_TRUE                                               0x00000001
#define PS_BLENDOPT_ENABLED                                            0x00000001
#define PS_BLENDOPT_DEFAULT                                            PS_BLENDOPT_ON


#define PS_BLENDOPT_FLAGS_STRING                                       "83015936"
#define PS_BLENDOPT_FLAGS_ID                                           0x00c6f27b
#define PS_BLENDOPT_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define PS_BLENDOPT_FLAGS_DISABLE_FLOAT_PIXEL_KILLS                    0x00000001
#define PS_BLENDOPT_FLAGS_DISABLE_ZERO_TIMES_ANYTHING_IS_ZERO          0x00000002
#define PS_BLENDOPT_FLAGS_DISABLE_BLENDOPT_IN_SHADER                   0x00000004
#define PS_BLENDOPT_FLAGS_DISABLE_ALPHATEST_IN_SHADER                  0x00000008
#define PS_BLENDOPT_FLAGS_DISABLE_ROUNDING_IN_BLENDOPT                 0x00000010
#define PS_BLENDOPT_FLAGS_DISABLE_EARLY_OUT_ALPHA_TEST                 0x00000020
#define PS_BLENDOPT_FLAGS_DISABLE_HW_ALPHA_TEST_WITH_ALPHATEST_IN_SHADER 0x00000040
#define PS_BLENDOPT_FLAGS_DISABLE_HW_BLENDOPT                          0x00000080
#define PS_BLENDOPT_FLAGS_DISABLE_DEPTH_STENCIL_WRITE_CHECK_FOR_BLENDOPT 0x00000100
#define PS_BLENDOPT_FLAGS_DISABLE_API_MANDATED_EARLYZ_FOR_BLENDOPT     0x00000200
#define PS_BLENDOPT_FLAGS_DISABLE_RENDERTARGET_FORMAT_CHECK_FOR_BLENDOPT 0x00000800
#define PS_BLENDOPT_FLAGS_SWALLOW_ROP                                  0x01000000
#define PS_BLENDOPT_FLAGS_DISABLE_PROP_DEBUG1_PRI_WRITE                0x02000000
#define PS_BLENDOPT_FLAGS_DEFAULT                                      0


#define PS_BLENDOPT_FP16_ROUNDING_STRING                               "45670163"
#define PS_BLENDOPT_FP16_ROUNDING_ID                                   0x00235422
#define PS_BLENDOPT_FP16_ROUNDING_OVERINSTALL                          0 // OVERRIDE


#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_STRING             "56921011"
#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_ID                 0x00fe48ce
#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_OVERINSTALL        0 // OVERRIDE
#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_MIN                0x00
#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_MAX                0x64
#define PS_BLENDOPT_MAX_ALPHA_TEST_DEPENDENCY_CHAIN_DEFAULT            0x19


#define PS_BLENDOPT_MAX_CHAIN_EARLY_OUT_ALPHA_TEST_STRING              "32446321"
#define PS_BLENDOPT_MAX_CHAIN_EARLY_OUT_ALPHA_TEST_ID                  0x00136445
#define PS_BLENDOPT_MAX_CHAIN_EARLY_OUT_ALPHA_TEST_OVERINSTALL         0 // OVERRIDE
#define PS_BLENDOPT_MAX_CHAIN_EARLY_OUT_ALPHA_TEST_DEFAULT             0x4


#define PS_BLENDOPT_MAX_INST_COUNT_STRING                              "36466726"
#define PS_BLENDOPT_MAX_INST_COUNT_ID                                  0x00927247
#define PS_BLENDOPT_MAX_INST_COUNT_OVERINSTALL                         0 // OVERRIDE
#define PS_BLENDOPT_MAX_INST_COUNT_DEFAULT                             0x200


#define PS_BLENDOPT_MAX_RT_COUNT_STRING                                "45890269"
#define PS_BLENDOPT_MAX_RT_COUNT_ID                                    0x00137221
#define PS_BLENDOPT_MAX_RT_COUNT_OVERINSTALL                           0 // OVERRIDE


#define PS_BLENDOPT_MIN_INST_COUNT_STRING                              "34456124"
#define PS_BLENDOPT_MIN_INST_COUNT_ID                                  0x00127546
#define PS_BLENDOPT_MIN_INST_COUNT_OVERINSTALL                         0 // OVERRIDE
#define PS_BLENDOPT_MIN_INST_COUNT_DEFAULT                             0x10


#define PS_BM_DEFER_DESTROY_STRING                                     "38686564"
#define PS_BM_DEFER_DESTROY_ID                                         0x000efbc3
#define PS_BM_DEFER_DESTROY_OVERINSTALL                                0 // OVERRIDE
#define PS_BM_DEFER_DESTROY_OFF                                        0x02656393
#define PS_BM_DEFER_DESTROY_DISABLED                                   0x02656393
#define PS_BM_DEFER_DESTROY_ON                                         0x02166322
#define PS_BM_DEFER_DESTROY_ENABLED                                    0x02166322
#define PS_BM_DEFER_DESTROY_DEFAULT                                    PS_BM_DEFER_DESTROY_ON


#define PS_BM_DEFER_DESTROY_ASYNC_FREE_BATCH_SIZE_STRING               "31616522"
#define PS_BM_DEFER_DESTROY_ASYNC_FREE_BATCH_SIZE_ID                   0x00beb185
#define PS_BM_DEFER_DESTROY_ASYNC_FREE_BATCH_SIZE_OVERINSTALL          0 // OVERRIDE


#define PS_BM_DEFER_DESTROY_FLAGS_STRING                               "34026294"
#define PS_BM_DEFER_DESTROY_FLAGS_ID                                   0x00159046
#define PS_BM_DEFER_DESTROY_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define PS_BM_DEFER_DESTROY_FLAGS_DISABLE_GLOBAL_RENAMING              0x00000001
#define PS_BM_DEFER_DESTROY_FLAGS_ALLOW_GLOBAL_RENAMING_PITCH_ONLY     0x00000002
#define PS_BM_DEFER_DESTROY_FLAGS_DISABLE_ASYNC_FREES                  0x00000004
#define PS_BM_DEFER_DESTROY_FLAGS_DISABLE_ALLOC_RECYCLING              0x00000010
#define PS_BM_DEFER_DESTROY_FLAGS_DISABLE_PENDING_ALLOC_RECYCLING      0x00000020
#define PS_BM_DEFER_DESTROY_FLAGS_DEFAULT                              0x0


#define PS_BM_DEFER_DESTROY_MAX_DEFERRED_STRING                        "31616521"
#define PS_BM_DEFER_DESTROY_MAX_DEFERRED_ID                            0x00beb184
#define PS_BM_DEFER_DESTROY_MAX_DEFERRED_OVERINSTALL                   0 // OVERRIDE


#define PS_BM_DEFER_DESTROY_MAX_RENAMED_STRING                         "38246966"
#define PS_BM_DEFER_DESTROY_MAX_RENAMED_ID                             0x00ac9da0
#define PS_BM_DEFER_DESTROY_MAX_RENAMED_OVERINSTALL                    0 // OVERRIDE


#define PS_BM_DEFER_DESTROY_MAX_RENAMED_NONVID_STRING                  "38246967"
#define PS_BM_DEFER_DESTROY_MAX_RENAMED_NONVID_ID                      0x00934193
#define PS_BM_DEFER_DESTROY_MAX_RENAMED_NONVID_OVERINSTALL             0 // OVERRIDE


#define PS_BM_FLAGS_STRING                                             "32626593"
#define PS_BM_FLAGS_ID                                                 0x00dc68af
#define PS_BM_FLAGS_OVERINSTALL                                        0 // OVERRIDE
#define PS_BM_FLAGS_DISABLE_SUBALLOCATION                              0x00000001
#define PS_BM_FLAGS_ALLOW_SUBALLOCATION_PITCH_ONLY                     0x00000002
#define PS_BM_FLAGS_DISABLE_LOCK_CACHING                               0x00000004
#define PS_BM_FLAGS_DISABLE_RENAMING                                   0x00000008
#define PS_BM_FLAGS_FORCE_FLUSH_ON_LOCK                                0x00000010
#define PS_BM_FLAGS_ALLOW_LARGE_SUBALLOCATION                          0x00000020
#define PS_BM_FLAGS_DISABLE_OFFER_SMALL_BLOCKS                         0x00000040
#define PS_BM_FLAGS_DISABLE_INTERNAL_OFFER_RECLAIM                     0x00000080
#define PS_BM_FLAGS_DISABLE_ALL_OFFER_RECLAIM                          0x00000100
#define PS_BM_FLAGS_DEFAULT                                            0x00000000


#define PS_BUFFER_PLACEMENT_CONTROL_STRING                             "77095605"
#define PS_BUFFER_PLACEMENT_CONTROL_ID                                 0x0094c538
#define PS_BUFFER_PLACEMENT_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define PS_BUFFER_PLACEMENT_CONTROL_PREFER_CPU_VISIBLE                 0x00000001
#define PS_BUFFER_PLACEMENT_CONTROL_PREFER_CPU_INVISIBLE               0x00000002
#define PS_BUFFER_PLACEMENT_CONTROL_FORCE_CPU_VISIBLE                  0x00000004
#define PS_BUFFER_PLACEMENT_CONTROL_FORCE_CPU_INVISIBLE                0x00000008
#define PS_BUFFER_PLACEMENT_CONTROL_PREFER_VID                         0x00001000
#define PS_BUFFER_PLACEMENT_CONTROL_PREFER_HOST                        0x00002000
#define PS_BUFFER_PLACEMENT_CONTROL_PREFER_CACHABLE                    0x00004000
#define PS_BUFFER_PLACEMENT_CONTROL_PREFERS_VIDMEM_SLOW                0x00008000
#define PS_BUFFER_PLACEMENT_CONTROL_FORCE_VID                          0x00100000
#define PS_BUFFER_PLACEMENT_CONTROL_FORCE_HOST                         0x00200000
#define PS_BUFFER_PLACEMENT_CONTROL_FORCE_CACHABLE                     0x00400000
#define PS_BUFFER_PLACEMENT_CONTROL_DEFAULT                            0x00000000


#define PS_BUFFER_PLACEMENT_TARGET_STRING                              "77095604"
#define PS_BUFFER_PLACEMENT_TARGET_ID                                  0x0094c537
#define PS_BUFFER_PLACEMENT_TARGET_OVERINSTALL                         0 // OVERRIDE
#define PS_BUFFER_PLACEMENT_TARGET_USAGE_IMMUTABLE                     0x00000001
#define PS_BUFFER_PLACEMENT_TARGET_USAGE_DEFAULT                       0x00000002
#define PS_BUFFER_PLACEMENT_TARGET_USAGE_DYNAMIC                       0x00000004
#define PS_BUFFER_PLACEMENT_TARGET_CPU_READ                            0x00001000
#define PS_BUFFER_PLACEMENT_TARGET_NO_CPU_READ                         0x00002000
#define PS_BUFFER_PLACEMENT_TARGET_VERTEX_BUFFER                       0x00100000
#define PS_BUFFER_PLACEMENT_TARGET_INDEX_BUFFER                        0x00200000
#define PS_BUFFER_PLACEMENT_TARGET_CONSTANT_BUFFER                     0x00400000
#define PS_BUFFER_PLACEMENT_TARGET_SHADERRESOURCE_BUF_1D               0x00800000
#define PS_BUFFER_PLACEMENT_TARGET_ALL_VERTEX_BUFFER                   0x00103007
#define PS_BUFFER_PLACEMENT_TARGET_ALL_INDEX_BUFFER                    0x00203007
#define PS_BUFFER_PLACEMENT_TARGET_ALL_CONSTANT_BUFFER                 0x00403007
#define PS_BUFFER_PLACEMENT_TARGET_ALL_SHADERRESOURCE_BUF_1D           0x00803007
#define PS_BUFFER_PLACEMENT_TARGET_DEFAULT                             0x00000000


#define PS_CAN_VECTORIZE_TRACKER_STRING                                "64834044"
#define PS_CAN_VECTORIZE_TRACKER_ID                                    0x00d59bae
#define PS_CAN_VECTORIZE_TRACKER_OVERINSTALL                           0 // OVERRIDE
#define PS_CAN_VECTORIZE_TRACKER_OFF                                   0x00000000
#define PS_CAN_VECTORIZE_TRACKER_DISABLED                              0x00000000
#define PS_CAN_VECTORIZE_TRACKER_ON                                    0x00000001
#define PS_CAN_VECTORIZE_TRACKER_ENABLED                               0x00000001
#define PS_CAN_VECTORIZE_TRACKER_DEFAULT                               PS_CAN_VECTORIZE_TRACKER_ON


#define PS_CATALOG_ID_STRING                                           "94672924"
#define PS_CATALOG_ID_ID                                               0x00d54edf
#define PS_CATALOG_ID_OVERINSTALL                                      0 // OVERRIDE


#define PS_CATALOG_MODE_STRING                                         "63703137"
#define PS_CATALOG_MODE_ID                                             0x00f84fdc
#define PS_CATALOG_MODE_OVERINSTALL                                    0 // OVERRIDE
#define PS_CATALOG_MODE_DONOTHING                                      0x00000000
#define PS_CATALOG_MODE_NOTHING                                        0x00000000
#define PS_CATALOG_MODE_0                                              0x00000000
#define PS_CATALOG_MODE_NORENDER                                       0x00000001
#define PS_CATALOG_MODE_NO_RENDER                                      0x00000001
#define PS_CATALOG_MODE_NO                                             0x00000001
#define PS_CATALOG_MODE_BLINK                                          0x00000002
#define PS_CATALOG_MODE_ONLYRENDER                                     0x00000003
#define PS_CATALOG_MODE_ONLY_RENDER                                    0x00000003
#define PS_CATALOG_MODE_ONLY                                           0x00000003
#define PS_CATALOG_MODE_BREAK                                          0x00000004
#define PS_CATALOG_MODE_BREAKPOINT                                     0x00000004
#define PS_CATALOG_MODE_BP                                             0x00000004


#define PS_CATALOG_OBJECT_STRING                                       "92548394"
#define PS_CATALOG_OBJECT_ID                                           0x0088a974
#define PS_CATALOG_OBJECT_OVERINSTALL                                  0 // OVERRIDE
#define PS_CATALOG_OBJECT_VERTEXBUFFER                                 0x00000000
#define PS_CATALOG_OBJECT_VERTEX_BUFFER                                0x00000000
#define PS_CATALOG_OBJECT_VB                                           0x00000000
#define PS_CATALOG_OBJECT_VERTEXSHADER                                 0x00000001
#define PS_CATALOG_OBJECT_VERTEX_SHADER                                0x00000001
#define PS_CATALOG_OBJECT_VS                                           0x00000001
#define PS_CATALOG_OBJECT_PIXELSHADER                                  0x00000002
#define PS_CATALOG_OBJECT_PIXEL_SHADER                                 0x00000002
#define PS_CATALOG_OBJECT_PS                                           0x00000002
#define PS_CATALOG_OBJECT_TEXTURE                                      0x00000003
#define PS_CATALOG_OBJECT_TEX                                          0x00000003
#define PS_CATALOG_OBJECT_TRILINEAR                                    0x00000004
#define PS_CATALOG_OBJECT_TRILIN                                       0x00000004
#define PS_CATALOG_OBJECT_INDEXBUFFER                                  0x00000005
#define PS_CATALOG_OBJECT_INDEX_BUFFER                                 0x00000005
#define PS_CATALOG_OBJECT_IB                                           0x00000005
#define PS_CATALOG_OBJECT_PS_TEXFILTER                                 0x00000006


#define PS_CATALOG_STATS_FLAGS_STRING                                  "70558393"
#define PS_CATALOG_STATS_FLAGS_ID                                      0x0034ce27
#define PS_CATALOG_STATS_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_CATALOG_STATS_FLAGS_VBINFO                                  0x00000001
#define PS_CATALOG_STATS_FLAGS_VBSIZES                                 0x00000002
#define PS_CATALOG_STATS_FLAGS_VBTABLE                                 0x00000004
#define PS_CATALOG_STATS_FLAGS_TEXINFO                                 0x00000010
#define PS_CATALOG_STATS_FLAGS_VSINFO                                  0x00000100
#define PS_CATALOG_STATS_FLAGS_IBINFO                                  0x00001000


#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_STRING                     "6b07da21"
#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_ID                         0x006b76af
#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_OVERINSTALL                0 // OVERRIDE
#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_ALLOW_TARGETED_SMALL_SURF_COMPRESSION 0x00000001
#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_ALLOW_TARGETED_TEX_UAV_1BPP_COMPRESSION 0x00000002
#define PS_CBC_COMPRESSION_HEURISTICS_FLAGS_DEFAULT                    0


#define PS_CBC_MISS_THRESHOLD_STRING                                   "0xafdfb0"
#define PS_CBC_MISS_THRESHOLD_ID                                       0x00afdfb0
#define PS_CBC_MISS_THRESHOLD_OVERINSTALL                              0 // OVERRIDE
#define PS_CBC_MISS_THRESHOLD_DEFAULT                                  0


#define PS_CBC_MISS_THRESHOLD_MODE_STRING                              "0xacdfb0"
#define PS_CBC_MISS_THRESHOLD_MODE_ID                                  0x00acdfb0
#define PS_CBC_MISS_THRESHOLD_MODE_OVERINSTALL                         0 // OVERRIDE
#define PS_CBC_MISS_THRESHOLD_MODE_APPLY_TO_ALL_TEX_UAV                0x00000001
#define PS_CBC_MISS_THRESHOLD_MODE_APPLY_TO_ALL_RENDERTARGET           0x00000002
#define PS_CBC_MISS_THRESHOLD_MODE_APPLY_TO_ALL_DEPTH                  0x00000004
#define PS_CBC_MISS_THRESHOLD_MODE_DEFAULT                             PS_CBC_MISS_THRESHOLD_MODE_APPLY_TO_ALL_TEX_UAV


#define PS_CE_BLIT_STAGED_UPLOAD_STRING                                "56259087"
#define PS_CE_BLIT_STAGED_UPLOAD_ID                                    0x003b9857
#define PS_CE_BLIT_STAGED_UPLOAD_OVERINSTALL                           0 // OVERRIDE
#define PS_CE_BLIT_STAGED_UPLOAD_OFF                                   0x00000000
#define PS_CE_BLIT_STAGED_UPLOAD_DISABLED                              0x00000000
#define PS_CE_BLIT_STAGED_UPLOAD_ON                                    0x00000001
#define PS_CE_BLIT_STAGED_UPLOAD_ENABLED                               0x00000001


#define PS_CLEAR_SKIP_STRING                                           "22845965"
#define PS_CLEAR_SKIP_ID                                               0x00939824
#define PS_CLEAR_SKIP_OVERINSTALL                                      0 // OVERRIDE
#define PS_CLEAR_SKIP_OFF                                              0x0
#define PS_CLEAR_SKIP_DISABLED                                         0x0
#define PS_CLEAR_SKIP_ON                                               0x1
#define PS_CLEAR_SKIP_ENABLED                                          0x1
#define PS_CLEAR_SKIP_DEFAULT                                          PS_CLEAR_SKIP_ON


#define PS_CLEAR_SKIP_FLAGS_STRING                                     "00037234"
#define PS_CLEAR_SKIP_FLAGS_ID                                         0x00b9b97c
#define PS_CLEAR_SKIP_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_CLEAR_SKIP_FLAGS_DISABLE_SKIP_COLOR                         0x00000001
#define PS_CLEAR_SKIP_FLAGS_DISABLE_SKIP_DEPTH                         0x00000002
#define PS_CLEAR_SKIP_FLAGS_DISABLE_SKIP_STENCIL                       0x00000004
#define PS_CLEAR_SKIP_FLAGS_DISABLE_SKIP_UNORDEREDACCESS               0x00000008
#define PS_CLEAR_SKIP_FLAGS_DISABLE_SKIP_MASK                          0x0000000f
#define PS_CLEAR_SKIP_FLAGS_DISABLE_RECT_TRACKING                      0x00000100
#define PS_CLEAR_SKIP_FLAGS_DUMP_LOG_TO_FILE                           0x80000000
#define PS_CLEAR_SKIP_FLAGS_DUMP_LOG_TO_DEBUGGER                       0x40000000
#define PS_CLEAR_SKIP_FLAGS_DEFAULT                                    0


#define PS_COMPRESSION_FILENAME_STRING                                 "COMPRESSION_FILENAME"
#define PS_COMPRESSION_FILENAME_ID                                     0x00ad60b3
#define PS_COMPRESSION_FILENAME_OVERINSTALL                            0 // OVERRIDE


#define PS_COMPRESSION_FLAGS_STRING                                    "03146123"
#define PS_COMPRESSION_FLAGS_ID                                        0x008b6026
#define PS_COMPRESSION_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_COMPRESSION_FLAGS_REALLOCATE                                0x00000001
#define PS_COMPRESSION_FLAGS_FAVOR_COLOR                               0x00000002
#define PS_COMPRESSION_FLAGS_IGNORE_CONTENTS                           0x00000004


#define PS_COMPRESSION_FROMFILE_STRING                                 "c96e68"
#define PS_COMPRESSION_FROMFILE_ID                                     0x00c96e68
#define PS_COMPRESSION_FROMFILE_OVERINSTALL                            0 // OVERRIDE
#define PS_COMPRESSION_FROMFILE_OFF                                    0
#define PS_COMPRESSION_FROMFILE_DISABLED                               0
#define PS_COMPRESSION_FROMFILE_ON                                     1
#define PS_COMPRESSION_FROMFILE_ENABLED                                1
#define PS_COMPRESSION_FROMFILE_DEFAULT                                PS_COMPRESSION_FROMFILE_OFF


#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_STRING        "0xffece0"
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_ID            0x00ffece0
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_OVERINSTALL   0 // OVERRIDE
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_OFF           0x00000000
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_DISABLED      0x00000000
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_ON            0x00000001
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_ENABLED       0x00000001
#define PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_DEFAULT       PS_COMPUTE_CTA_REG_TARGET_USE_SMSCG_CAPPED_SHMEM_ON


#define PS_COMPUTE_CTA_THROTTLING_BARRIER_COUNT_STRING                 "0xaffec0"
#define PS_COMPUTE_CTA_THROTTLING_BARRIER_COUNT_ID                     0x00affec0
#define PS_COMPUTE_CTA_THROTTLING_BARRIER_COUNT_OVERINSTALL            0 // OVERRIDE
#define PS_COMPUTE_CTA_THROTTLING_BARRIER_COUNT_DEFAULT                0


#define PS_COMPUTE_CTA_THROTTLING_MODE_STRING                          "0xaeedc0"
#define PS_COMPUTE_CTA_THROTTLING_MODE_ID                              0x00aeedc0
#define PS_COMPUTE_CTA_THROTTLING_MODE_OVERINSTALL                     0 // OVERRIDE
#define PS_COMPUTE_CTA_THROTTLING_MODE_APP_DEFAULT                     0
#define PS_COMPUTE_CTA_THROTTLING_MODE_APPLY_TO_ALL_SHADERS            1
#define PS_COMPUTE_CTA_THROTTLING_MODE_APPLY_TO_SPECIFIC_SHADERS       2
#define PS_COMPUTE_CTA_THROTTLING_MODE_DEFAULT                         PS_COMPUTE_CTA_THROTTLING_MODE_APP_DEFAULT


#define PS_COMPUTE_CTA_THROTTLING_SHARED_MEMORY_STRING                 "0xaffde0"
#define PS_COMPUTE_CTA_THROTTLING_SHARED_MEMORY_ID                     0x00affde0
#define PS_COMPUTE_CTA_THROTTLING_SHARED_MEMORY_OVERINSTALL            0 // OVERRIDE
#define PS_COMPUTE_CTA_THROTTLING_SHARED_MEMORY_DEFAULT                0


#define PS_COMPUTE_REGISTER_BLOAT_COUNT_STRING                         "B40D9E040"
#define PS_COMPUTE_REGISTER_BLOAT_COUNT_ID                             0x00951b40
#define PS_COMPUTE_REGISTER_BLOAT_COUNT_OVERINSTALL                    0 // OVERRIDE
#define PS_COMPUTE_REGISTER_BLOAT_COUNT_DEFAULT                        0


#define PS_COMPUTE_REGISTER_BLOAT_FACTOR_STRING                        "B40D9E041"
#define PS_COMPUTE_REGISTER_BLOAT_FACTOR_ID                            0x00951b41
#define PS_COMPUTE_REGISTER_BLOAT_FACTOR_OVERINSTALL                   0 // OVERRIDE
#define PS_COMPUTE_REGISTER_BLOAT_FACTOR_DEFAULT                       1.0f


#define PS_COMPUTE_SHADER_DUMP_STRING                                  "15694569"
#define PS_COMPUTE_SHADER_DUMP_ID                                      0x004d109b
#define PS_COMPUTE_SHADER_DUMP_OVERINSTALL                             0 // OVERRIDE
#define PS_COMPUTE_SHADER_DUMP_OFF                                     0x32545116
#define PS_COMPUTE_SHADER_DUMP_DISABLED                                0x32545116
#define PS_COMPUTE_SHADER_DUMP_ON                                      0x43241846
#define PS_COMPUTE_SHADER_DUMP_ENABLED                                 0x43241846


#define PS_COMPUTE_SHADER_DUMP_FLAGS_STRING                            "69801276"
#define PS_COMPUTE_SHADER_DUMP_FLAGS_ID                                0x009dfca7
#define PS_COMPUTE_SHADER_DUMP_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS          0x00000001
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS           0x00000002
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                  0x00000004
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS          0x02000000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS           0x00000008
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_NVINST                       0x00000020
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_NVVM                         0x00000020
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE                0x00000040
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE                0x00000080
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST             0x00000120
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS               0x00000200
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC               0x00000400
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE         0x00000800
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS             0x00001000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE           0x00002000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE            0x00004000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME          0x00010000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED         0x00020000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS        0x00040000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER     0x00080000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS      0x00100000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE 0x00200000
#define PS_COMPUTE_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME          0x00400000


#define PS_COMPUTE_SHADER_HASH_STRING                                  "0xafefe0"
#define PS_COMPUTE_SHADER_HASH_ID                                      0x00afefe0
#define PS_COMPUTE_SHADER_HASH_OVERINSTALL                             0 // OVERRIDE
#define PS_COMPUTE_SHADER_HASH_DEFAULT                                 0


#define PS_CONSTANT_BUFFER_REMAPPER_STRING                             "69948381"
#define PS_CONSTANT_BUFFER_REMAPPER_ID                                 0x0085fd2b
#define PS_CONSTANT_BUFFER_REMAPPER_OVERINSTALL                        0 // OVERRIDE
#define PS_CONSTANT_BUFFER_REMAPPER_OFF                                0x00000000
#define PS_CONSTANT_BUFFER_REMAPPER_DISABLED                           0x00000000
#define PS_CONSTANT_BUFFER_REMAPPER_ON                                 0x00000001
#define PS_CONSTANT_BUFFER_REMAPPER_ENABLED                            0x00000001


#define PS_CONSTANT_BUFFER_REMAPPER_FLAGS_STRING                       "69A48381"
#define PS_CONSTANT_BUFFER_REMAPPER_FLAGS_ID                           0x0085fe2b
#define PS_CONSTANT_BUFFER_REMAPPER_FLAGS_OVERINSTALL                  0 // OVERRIDE
#define PS_CONSTANT_BUFFER_REMAPPER_FLAGS_DISABLE_CONST_BANK_PRIORITY_REMAPPING 0x00000001
#define PS_CONSTANT_BUFFER_REMAPPER_FLAGS_DEFAULT                      0


#define PS_CONST_FOLDING_STRING                                        "1314f311"
#define PS_CONST_FOLDING_ID                                            0x00a4f311
#define PS_CONST_FOLDING_OVERINSTALL                                   0 // OVERRIDE
#define PS_CONST_FOLDING_OFF                                           0xa2b53761
#define PS_CONST_FOLDING_DISABLED                                      0xa2b53761
#define PS_CONST_FOLDING_ON                                            0x79292610
#define PS_CONST_FOLDING_ENABLED                                       0x79292610


#define PS_CONST_FOLDING_CONSTANT_TYPE_STRING                          "1314f31b"
#define PS_CONST_FOLDING_CONSTANT_TYPE_ID                              0x00a4f31b
#define PS_CONST_FOLDING_CONSTANT_TYPE_OVERINSTALL                     0 // OVERRIDE
#define PS_CONST_FOLDING_CONSTANT_TYPE_DISABLE_FLOAT_CONST_DETECTION   0x00000001
#define PS_CONST_FOLDING_CONSTANT_TYPE_DISABLE_BOOL_CONST_DETECTION    0x00000002
#define PS_CONST_FOLDING_CONSTANT_TYPE_DISABLE_INT_CONST_DETECTION     0x00000004


#define PS_CONST_FOLDING_FLAGS_STRING                                  "1314f312"
#define PS_CONST_FOLDING_FLAGS_ID                                      0x00a4f312
#define PS_CONST_FOLDING_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_CONST_FOLDING_FLAGS_DISABLE_INVARIANT_CONST_DETECTION       0x00000001
#define PS_CONST_FOLDING_FLAGS_DISABLE_INVARIANT_CONST_FOLDING         0x00000002
#define PS_CONST_FOLDING_FLAGS_DISABLE_GLOBAL_CB_FOLDING               0x00000004
#define PS_CONST_FOLDING_FLAGS_DISABLE_NVINST_UNROLLING                0x08000000


#define PS_CONST_FOLDING_GPU_STRING                                    "653c9b12"
#define PS_CONST_FOLDING_GPU_ID                                        0x006d6197
#define PS_CONST_FOLDING_GPU_OVERINSTALL                               0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_OFF                                       0xa2b53761
#define PS_CONST_FOLDING_GPU_DISABLED                                  0xa2b53761
#define PS_CONST_FOLDING_GPU_ON                                        0x79292610
#define PS_CONST_FOLDING_GPU_ENABLED                                   0x79292610
#define PS_CONST_FOLDING_GPU_DEFAULT                                   PS_CONST_FOLDING_GPU_ON


#define PS_CONST_FOLDING_GPU_ANALYZE_EVERY_NTH_FRAME_STRING            "719e14"
#define PS_CONST_FOLDING_GPU_ANALYZE_EVERY_NTH_FRAME_ID                0x00719e14
#define PS_CONST_FOLDING_GPU_ANALYZE_EVERY_NTH_FRAME_OVERINSTALL       0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_ANALYZE_EVERY_NTH_FRAME_DEFAULT           8


#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_STRING                    "813914b6"
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ID                        0x0092d8b8
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_OVERINSTALL               0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_DISABLED                  0x00000000
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ENABLED_FOR_SHADER_HASHES 0x00000001
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ENABLED_ALWAYS            0x00000002
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ENABLED_MASK              0x00000007
#define PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_DEFAULT                   PS_CONST_FOLDING_GPU_COMPUTE_SHADERS_ENABLED_ALWAYS


#define PS_CONST_FOLDING_GPU_FILTER_WEIGHT_STRING                      "89c756bf"
#define PS_CONST_FOLDING_GPU_FILTER_WEIGHT_ID                          0x001b026b
#define PS_CONST_FOLDING_GPU_FILTER_WEIGHT_OVERINSTALL                 0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_FILTER_WEIGHT_DEFAULT                     0.9f


#define PS_CONST_FOLDING_GPU_FLAGS_STRING                              "33deebef"
#define PS_CONST_FOLDING_GPU_FLAGS_ID                                  0x00a8c5b6
#define PS_CONST_FOLDING_GPU_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_NULL_OPTIMIZED_SHADER         0x00000001
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_SKIP_ASID                     0x00000002
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_DISABLE_SELECTION             0x00000020
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_DISABLE_HISTOGRAM             0x00000040
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_ALLOW_IN_REPLAY_MODE          0x00000100
#define PS_CONST_FOLDING_GPU_FLAGS_DEBUG_SKIP_TIER3_SAFETY_CHECKS      0x00000200
#define PS_CONST_FOLDING_GPU_FLAGS_ENABLE_HISTOGRAM_SLOT_NEW_PASS      0x00100000
#define PS_CONST_FOLDING_GPU_FLAGS_ENABLE_SELECTION_SLOT_NEW_PASS      0x00200000
#define PS_CONST_FOLDING_GPU_FLAGS_DISABLE_LOADBALANCE_ON_HAZARD       0x00400000
#define PS_CONST_FOLDING_GPU_FLAGS_ENABLE_LOW_LATENCY                  0x80000000
#define PS_CONST_FOLDING_GPU_FLAGS_DEFAULT                             PS_CONST_FOLDING_GPU_FLAGS_DISABLE_LOADBALANCE_ON_HAZARD


#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_STRING          "40a2f0"
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_ID              0x0040a2f0
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_OVERINSTALL     0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_OFF             0
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_DISABLED        0
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_ON              1
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_ENABLED         1
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_DEFAULT         PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_COMPUTE_OFF


#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_STRING         "422eec"
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_ID             0x00422eec
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_OVERINSTALL    0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_OFF            0
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_DISABLED       0
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_ON             1
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_ENABLED        1
#define PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_DEFAULT        PS_CONST_FOLDING_GPU_LOADBALANCE_SCORE_GRAPHICS_ON


#define PS_CONST_FOLDING_GPU_MAX_CONST_COUNT_STRING                    "91f609ef"
#define PS_CONST_FOLDING_GPU_MAX_CONST_COUNT_ID                        0x003edde7
#define PS_CONST_FOLDING_GPU_MAX_CONST_COUNT_OVERINSTALL               0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MAX_CONST_COUNT_DEFAULT                   256


#define PS_CONST_FOLDING_GPU_MAX_SORTED_INVALID_RANGES_STRING          "1c8f85"
#define PS_CONST_FOLDING_GPU_MAX_SORTED_INVALID_RANGES_ID              0x001c8f85
#define PS_CONST_FOLDING_GPU_MAX_SORTED_INVALID_RANGES_OVERINSTALL     0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MAX_SORTED_INVALID_RANGES_DEFAULT         512


#define PS_CONST_FOLDING_GPU_MAX_UNSORTED_INVALID_RANGES_STRING        "33dd04"
#define PS_CONST_FOLDING_GPU_MAX_UNSORTED_INVALID_RANGES_ID            0x0033dd04
#define PS_CONST_FOLDING_GPU_MAX_UNSORTED_INVALID_RANGES_OVERINSTALL   0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MAX_UNSORTED_INVALID_RANGES_DEFAULT       64


#define PS_CONST_FOLDING_GPU_MESH_SHADERS_STRING                       "813914b9"
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_ID                           0x0092d8bb
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_OVERINSTALL                  0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_DISABLED                     0x00000000
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_ENABLED_FOR_SHADER_HASHES    0x00000001
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_ENABLED_ALWAYS               0x00000002
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_ENABLED_MASK                 0x00000007
#define PS_CONST_FOLDING_GPU_MESH_SHADERS_DEFAULT                      PS_CONST_FOLDING_GPU_MESH_SHADERS_DISABLED


#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_STRING                  "813914ba"
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_ID                      0x0092d8bc
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_OVERINSTALL             0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_DISABLED                0x00000000
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_ENABLED_FOR_SHADER_HASHES 0x00000001
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_ENABLED_ALWAYS          0x00000002
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_ENABLED_MASK            0x00000007
#define PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_DEFAULT                 PS_CONST_FOLDING_GPU_MESH_TASK_SHADERS_DISABLED


#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_STRING            "ca0d60"
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_ID                0x00ca0d60
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_OVERINSTALL       0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_DEFAULT           2


#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_RT_STRING         "ca0d61"
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_RT_ID             0x00ca0d61
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_RT_OVERINSTALL    0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_MIN_HISTOGRAM_HIT_COUNT_RT_DEFAULT        8


#define PS_CONST_FOLDING_GPU_NUM_HISTOGRAM_PHASES_STRING               "63dbc7"
#define PS_CONST_FOLDING_GPU_NUM_HISTOGRAM_PHASES_ID                   0x0063dbc7
#define PS_CONST_FOLDING_GPU_NUM_HISTOGRAM_PHASES_OVERINSTALL          0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_NUM_HISTOGRAM_PHASES_DEFAULT              4


#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_STRING                      "813914b7"
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_ID                          0x0092d8b9
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_OVERINSTALL                 0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_DISABLED                    0x00000000
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_ENABLED_FOR_SHADER_HASHES   0x00000001
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_ENABLED_ALWAYS              0x00000002
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_ENABLED_MASK                0x00000007
#define PS_CONST_FOLDING_GPU_PIXEL_SHADERS_DEFAULT                     0x00000005


#define PS_CONST_FOLDING_GPU_RT_SHADERS_STRING                         "813914bb"
#define PS_CONST_FOLDING_GPU_RT_SHADERS_ID                             0x0092d8bd
#define PS_CONST_FOLDING_GPU_RT_SHADERS_OVERINSTALL                    0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_RT_SHADERS_DISABLED                       0x00000000
#define PS_CONST_FOLDING_GPU_RT_SHADERS_ENABLED_FOR_SHADER_HASHES      0x00000001
#define PS_CONST_FOLDING_GPU_RT_SHADERS_ENABLED_ALWAYS                 0x00000002
#define PS_CONST_FOLDING_GPU_RT_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_RT_SHADERS_ENABLED_MASK                   0x00000007
#define PS_CONST_FOLDING_GPU_RT_SHADERS_DEFAULT                        PS_CONST_FOLDING_GPU_RT_SHADERS_ENABLED_ALWAYS


#define PS_CONST_FOLDING_GPU_RT_SHADERS_QUOTA_STRING                   "F8ED2F94"
#define PS_CONST_FOLDING_GPU_RT_SHADERS_QUOTA_ID                       0x00757cf8
#define PS_CONST_FOLDING_GPU_RT_SHADERS_QUOTA_OVERINSTALL              0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_RT_SHADERS_QUOTA_DEFAULT                  8


#define PS_CONST_FOLDING_GPU_SHADER_HASH_STRING                        "c2566148"
#define PS_CONST_FOLDING_GPU_SHADER_HASH_ID                            0x0073b68f
#define PS_CONST_FOLDING_GPU_SHADER_HASH_OVERINSTALL                   0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_SHADER_HASH_DEFAULT                       0x0


#define PS_CONST_FOLDING_GPU_SHADER_HASHES_STRING                      "b4f0347f"
#define PS_CONST_FOLDING_GPU_SHADER_HASHES_ID                          0x00a10b4e
#define PS_CONST_FOLDING_GPU_SHADER_HASHES_OVERINSTALL                 0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_SHADER_HASHES_DEFAULT                     ""


#define PS_CONST_FOLDING_GPU_USE_LIMIT_STRING                          "5eb152e2"
#define PS_CONST_FOLDING_GPU_USE_LIMIT_ID                              0x000d3a43
#define PS_CONST_FOLDING_GPU_USE_LIMIT_OVERINSTALL                     0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_USE_LIMIT_DEFAULT                         1024


#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_STRING                     "813914b8"
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_ID                         0x0092d8ba
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_OVERINSTALL                0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_DISABLED                   0x00000000
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_ENABLED_FOR_SHADER_HASHES  0x00000001
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_ENABLED_ALWAYS             0x00000002
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_ENABLED_ALWAYS_WITH_DRIVER_SCG 0x00000004
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_ENABLED_MASK               0x00000007
#define PS_CONST_FOLDING_GPU_VERTEX_SHADERS_DEFAULT                    PS_CONST_FOLDING_GPU_VERTEX_SHADERS_DISABLED


#define PS_CONST_FOLDING_GPU_VOLATILITY_AGING_FACTOR_STRING            "78e99987"
#define PS_CONST_FOLDING_GPU_VOLATILITY_AGING_FACTOR_ID                0x00e3ea78
#define PS_CONST_FOLDING_GPU_VOLATILITY_AGING_FACTOR_OVERINSTALL       0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_VOLATILITY_AGING_FACTOR_DEFAULT           0.99f


#define PS_CONST_FOLDING_GPU_VOLATILITY_THRESHOLD_STRING               "89c756be"
#define PS_CONST_FOLDING_GPU_VOLATILITY_THRESHOLD_ID                   0x001b026a
#define PS_CONST_FOLDING_GPU_VOLATILITY_THRESHOLD_OVERINSTALL          0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_VOLATILITY_THRESHOLD_DEFAULT              0.75f


#define PS_CONST_FOLDING_GPU_WARMUP_FRAMES_STRING                      "428adc26"
#define PS_CONST_FOLDING_GPU_WARMUP_FRAMES_ID                          0x00ea5144
#define PS_CONST_FOLDING_GPU_WARMUP_FRAMES_OVERINSTALL                 0 // OVERRIDE
#define PS_CONST_FOLDING_GPU_WARMUP_FRAMES_DEFAULT                     0


#define PS_CONST_FOLDING_SHADER_TYPE_STRING                            "1314f313"
#define PS_CONST_FOLDING_SHADER_TYPE_ID                                0x00a4f313
#define PS_CONST_FOLDING_SHADER_TYPE_OVERINSTALL                       0 // OVERRIDE
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_VERTEX_SHADER             0x00000001
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_HULL_SHADER               0x00000002
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_DOMAIN_SHADER             0x00000004
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_GEOMETRY_SHADER           0x00000008
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_PIXEL_SHADER              0x00000010
#define PS_CONST_FOLDING_SHADER_TYPE_DISABLE_COMPUTE_SHADER            0x00000020


#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_STRING                      "1314f31a"
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_ID                          0x00a4f31a
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_OVERINSTALL                 0 // OVERRIDE
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_VERTEX_SPECIALIZE_ALL       0x0000000000000001
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_VERTEX_SPECIALIZE_LOOP_COUNTERS 0x0000000000000002
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_VERTEX_SPECIALIZE_IF_BRANCHES 0x0000000000000004
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_VERTEX_SPECIALIZE_ONLY      0x0000000000000008
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_VERTEX_CONTROL_FLOW_ONLY    0x0000000000000010
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_HULL_SPECIALIZE_ALL         0x0000000000000100
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_HULL_SPECIALIZE_LOOP_COUNTERS 0x0000000000000200
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_HULL_SPECIALIZE_IF_BRANCHES 0x0000000000000400
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_HULL_SPECIALIZE_ONLY        0x0000000000000800
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_HULL_CONTROL_FLOW_ONLY      0x0000000000001000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_DOMAIN_SPECIALIZE_ALL       0x0000000000010000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_DOMAIN_SPECIALIZE_LOOP_COUNTERS 0x0000000000020000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_DOMAIN_SPECIALIZE_IF_BRANCHES 0x0000000000040000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_DOMAIN_SPECIALIZE_ONLY      0x0000000000080000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_DOMAIN_CONTROL_FLOW_ONLY    0x0000000000100000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_GEOMETRY_SPECIALIZE_ALL     0x0000000001000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_GEOMETRY_SPECIALIZE_LOOP_COUNTERS 0x0000000002000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_GEOMETRY_SPECIALIZE_IF_BRANCHES 0x0000000004000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_GEOMETRY_SPECIALIZE_ONLY    0x0000000008000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_GEOMETRY_CONTROL_FLOW_ONLY  0x0000000010000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_PIXEL_SPECIALIZE_ALL        0x0000000100000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_PIXEL_SPECIALIZE_LOOP_COUNTERS 0x0000000200000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_PIXEL_SPECIALIZE_IF_BRANCHES 0x0000000400000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_PIXEL_SPECIALIZE_ONLY       0x0000000800000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_PIXEL_CONTROL_FLOW_ONLY     0x0000001000000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_COMPUTE_SPECIALIZE_ALL      0x0000010000000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_COMPUTE_SPECIALIZE_LOOP_COUNTERS 0x0000020000000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_COMPUTE_SPECIALIZE_IF_BRANCHES 0x0000040000000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_COMPUTE_SPECIALIZE_ONLY     0x0000080000000000
#define PS_CONST_FOLDING_SHADER_TYPE_FLAGS_COMPUTE_CONTROL_FLOW_ONLY   0x0000100000000000


#define PS_COPARGS_DUMP_VER_STRING                                     "be58bb"
#define PS_COPARGS_DUMP_VER_ID                                         0x00be58bb
#define PS_COPARGS_DUMP_VER_OVERINSTALL                                0 // OVERRIDE
#define PS_COPARGS_DUMP_VER_VER_0                                      0
#define PS_COPARGS_DUMP_VER_0                                          0
#define PS_COPARGS_DUMP_VER_VER_1                                      1
#define PS_COPARGS_DUMP_VER_1                                          1
#define PS_COPARGS_DUMP_VER_VER_2                                      2
#define PS_COPARGS_DUMP_VER_2                                          2
#define PS_COPARGS_DUMP_VER_VER_3                                      3
#define PS_COPARGS_DUMP_VER_3                                          3
#define PS_COPARGS_DUMP_VER_VER_COMPAT                                 0xffffffff
#define PS_COPARGS_DUMP_VER_VER_UNKNOWN                                0xffffffff
#define PS_COPARGS_DUMP_VER_DEFAULT                                    PS_COPARGS_DUMP_VER_VER_2


#define PS_COPY_TRACKER_STRING                                         "f3affe33"
#define PS_COPY_TRACKER_ID                                             0x00503f9a
#define PS_COPY_TRACKER_OVERINSTALL                                    0 // OVERRIDE
#define PS_COPY_TRACKER_OFF                                            0x71b537f1
#define PS_COPY_TRACKER_DISABLED                                       0x71b537f1
#define PS_COPY_TRACKER_ON                                             0x12242f10
#define PS_COPY_TRACKER_ENABLED                                        0x12242f10


#define PS_COPY_TRACKER_END_FRAME_STRING                               "1e33af01"
#define PS_COPY_TRACKER_END_FRAME_ID                                   0x009f6568
#define PS_COPY_TRACKER_END_FRAME_OVERINSTALL                          0 // OVERRIDE


#define PS_COPY_TRACKER_FILENAME_STRING                                "a3420edf"
#define PS_COPY_TRACKER_FILENAME_ID                                    0x00d29002
#define PS_COPY_TRACKER_FILENAME_OVERINSTALL                           0 // OVERRIDE


#define PS_COPY_TRACKER_FLAGS_STRING                                   "1e33aeff"
#define PS_COPY_TRACKER_FLAGS_ID                                       0x009f6566
#define PS_COPY_TRACKER_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_COPY_TRACKER_FLAGS_DBGPRINT_DECISIONS                       0x00000001
#define PS_COPY_TRACKER_FLAGS_LOG_DECISIONS                            0x00000002
#define PS_COPY_TRACKER_FLAGS_DIRTY_DST                                0x00000004
#define PS_COPY_TRACKER_FLAGS_TOGGLE_ONOFF                             0x00000008
#define PS_COPY_TRACKER_FLAGS_ANNOTATE                                 0x00000010
#define PS_COPY_TRACKER_FLAGS_DONT_OPTIMIZE_DRAW                       0x00100000
#define PS_COPY_TRACKER_FLAGS_DONT_OPTIMIZE_BLIT                       0x00200000
#define PS_COPY_TRACKER_FLAGS_DONT_OPTIMIZE_COLORFILL                  0x00400000
#define PS_COPY_TRACKER_FLAGS_DISABLE_LOAD_BALANCED_DRAW_ANALYSIS      0x01000000
#define PS_COPY_TRACKER_FLAGS_DISABLE_LOAD_BALANCED_BLIT_ANALYSIS      0x02000000
#define PS_COPY_TRACKER_FLAGS_DONT_PROMOTE_DEPTH_DRAWS_TO_TWOD         0x04000000


#define PS_COPY_TRACKER_START_FRAME_STRING                             "1e33af00"
#define PS_COPY_TRACKER_START_FRAME_ID                                 0x009f6567
#define PS_COPY_TRACKER_START_FRAME_OVERINSTALL                        0 // OVERRIDE


#define PS_CPU_CLEAR_STRING                                            "39456367"
#define PS_CPU_CLEAR_ID                                                0x0040de6d
#define PS_CPU_CLEAR_OVERINSTALL                                       0 // OVERRIDE
#define PS_CPU_CLEAR_OFF                                               0x02656393
#define PS_CPU_CLEAR_DISABLED                                          0x02656393
#define PS_CPU_CLEAR_ON                                                0x02166322
#define PS_CPU_CLEAR_ENABLED                                           0x02166322


#define PS_CPU_CLEAR_2_STRING                                          "48079670"
#define PS_CPU_CLEAR_2_ID                                              0x007b3ace
#define PS_CPU_CLEAR_2_OVERINSTALL                                     0 // OVERRIDE
#define PS_CPU_CLEAR_2_OFF                                             0x02656393
#define PS_CPU_CLEAR_2_DISABLED                                        0x02656393
#define PS_CPU_CLEAR_2_ON                                              0x02166322
#define PS_CPU_CLEAR_2_ENABLED                                         0x02166322


#define PS_CPU_CLEAR_2_ALLOW_STRING                                    "37742411"
#define PS_CPU_CLEAR_2_ALLOW_ID                                        0x001bf167
#define PS_CPU_CLEAR_2_ALLOW_OVERINSTALL                               0 // OVERRIDE
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_R32F_CLEARS                         0x00000001
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_FORCE_SYNCHRONIZED_CLEAR            0x04000000
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_NULL_CPU_CLEAR                      0x08000000
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_CAPS_OVERRIDE                       0x20000000
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_CLASS_OVERRIDE                      0x40000000
#define PS_CPU_CLEAR_2_ALLOW_ALLOW_CHIP_ID_OVERRIDE                    0x80000000


#define PS_CPU_CLEAR_ALLOW_STRING                                      "48903887"
#define PS_CPU_CLEAR_ALLOW_ID                                          0x005cb703
#define PS_CPU_CLEAR_ALLOW_OVERINSTALL                                 0 // OVERRIDE
#define PS_CPU_CLEAR_ALLOW_ALLOW_COLOR_CLEARS                          0x00000001
#define PS_CPU_CLEAR_ALLOW_ALLOW_STENCIL_CLEARS                        0x00000002
#define PS_CPU_CLEAR_ALLOW_ALLOW_Z_CLEARS                              0x00000004
#define PS_CPU_CLEAR_ALLOW_ALLOW_PARTIAL_Z_CLEARS                      0x00000008


#define PS_CTA_THROTTLE_TARGET_STRING                                  "03849179"
#define PS_CTA_THROTTLE_TARGET_ID                                      0x000012f1
#define PS_CTA_THROTTLE_TARGET_OVERINSTALL                             0 // OVERRIDE
#define PS_CTA_THROTTLE_TARGET_DEFAULT                                 0x8


#define PS_CTA_THROTTLING_STRING                                       "03849178"
#define PS_CTA_THROTTLING_ID                                           0x000012f0
#define PS_CTA_THROTTLING_OVERINSTALL                                  0 // OVERRIDE
#define PS_CTA_THROTTLING_OFF                                          0x00000000
#define PS_CTA_THROTTLING_DISABLED                                     0x00000000
#define PS_CTA_THROTTLING_ON                                           0x00000001
#define PS_CTA_THROTTLING_ENABLED                                      0x00000001
#define PS_CTA_THROTTLING_DEFAULT                                      PS_CTA_THROTTLING_ON


#define PS_CYCLESTATS_CPU_FLAGS_STRING                                 "c7f6275667"
#define PS_CYCLESTATS_CPU_FLAGS_ID                                     0x001c9022
#define PS_CYCLESTATS_CPU_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define PS_CYCLESTATS_CPU_FLAGS_HOTSPOTS                               0x00000001
#define PS_CYCLESTATS_CPU_FLAGS_PAGEFAULTS                             0x00000002
#define PS_CYCLESTATS_CPU_FLAGS_RELMSECTHRESHOLD                       0x00000004
#define PS_CYCLESTATS_CPU_FLAGS_STATIC_STATS                           0x00000008
#define PS_CYCLESTATS_CPU_FLAGS_SUM_10_FRAMES                          0x00001000
#define PS_CYCLESTATS_CPU_FLAGS_SUM_100_FRAMES                         0x00002000
#define PS_CYCLESTATS_CPU_FLAGS_SUM_1000_FRAMES                        0x00004000
#define PS_CYCLESTATS_CPU_FLAGS_DONOTDUMP2FILE                         0x00010000
#define PS_CYCLESTATS_CPU_FLAGS_DUMP2DEBUGGER                          0x00020000
#define PS_CYCLESTATS_CPU_FLAGS_SUM_INDIVIDUAL_CPUS                    0x00040000
#define PS_CYCLESTATS_CPU_FLAGS_ADVANCE_ON_CLIENT_PRESENT              0x00100000
#define PS_CYCLESTATS_CPU_FLAGS_USE_LARGE_BUFFER                       0x00200000
#define PS_CYCLESTATS_CPU_FLAGS_SHOW_ALL_HITS                          0x00400000
#define PS_CYCLESTATS_CPU_FLAGS_IGNORESYMBOLS                          0x01000000
#define PS_CYCLESTATS_CPU_FLAGS_DONOTPROFILEUSERMODE                   0x02000000
#define PS_CYCLESTATS_CPU_FLAGS_SHOWHITCOUNT                           0x04000000
#define PS_CYCLESTATS_CPU_FLAGS_DUMPOVERHEAD                           0x08000000
#define PS_CYCLESTATS_CPU_FLAGS_STACKWALK                              0x10000000


#define PS_CYCLESTATS_CPU_INTERVAL_STRING                              "e7f6275667"
#define PS_CYCLESTATS_CPU_INTERVAL_ID                                  0x00872971
#define PS_CYCLESTATS_CPU_INTERVAL_OVERINSTALL                         0 // OVERRIDE


#define PS_CYCLESTATS_CPU_SAMPLEMODE_STRING                            "d7f6275667"
#define PS_CYCLESTATS_CPU_SAMPLEMODE_ID                                0x003dfe58
#define PS_CYCLESTATS_CPU_SAMPLEMODE_OVERINSTALL                       0 // OVERRIDE


#define PS_CYCLESTATS_CPU_STACKWALK_EPILOGSIZE_STRING                  "58f6275667"
#define PS_CYCLESTATS_CPU_STACKWALK_EPILOGSIZE_ID                      0x00534989
#define PS_CYCLESTATS_CPU_STACKWALK_EPILOGSIZE_OVERINSTALL             0 // OVERRIDE


#define PS_CYCLESTATS_CPU_STACKWALK_FUNCTION_STRING                    "e8f6275667"
#define PS_CYCLESTATS_CPU_STACKWALK_FUNCTION_ID                        0x003176ec
#define PS_CYCLESTATS_CPU_STACKWALK_FUNCTION_OVERINSTALL               0 // OVERRIDE


#define PS_CYCLESTATS_CPU_STACKWALK_MODULE_STRING                      "d8f6275667"
#define PS_CYCLESTATS_CPU_STACKWALK_MODULE_ID                          0x00bc27fe
#define PS_CYCLESTATS_CPU_STACKWALK_MODULE_OVERINSTALL                 0 // OVERRIDE


#define PS_CYCLESTATS_CPU_STACKWALK_NUMSTEPS_STRING                    "f8f6275667"
#define PS_CYCLESTATS_CPU_STACKWALK_NUMSTEPS_ID                        0x001dbc9d
#define PS_CYCLESTATS_CPU_STACKWALK_NUMSTEPS_OVERINSTALL               0 // OVERRIDE


#define PS_CYCLESTATS_CPU_STACKWALK_PROLOGSIZE_STRING                  "08f6275667"
#define PS_CYCLESTATS_CPU_STACKWALK_PROLOGSIZE_ID                      0x001cd54f
#define PS_CYCLESTATS_CPU_STACKWALK_PROLOGSIZE_OVERINSTALL             0 // OVERRIDE


#define PS_CYCLESTATS_CPU_THRESHOLD_STRING                             "f7f6275667"
#define PS_CYCLESTATS_CPU_THRESHOLD_ID                                 0x00f4099f
#define PS_CYCLESTATS_CPU_THRESHOLD_OVERINSTALL                        0 // OVERRIDE


#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_STRING                     "211022"
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_ID                         0x00211022
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_OVERINSTALL                0 // OVERRIDE
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_DISABLED                   0x0
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_OFF                        0x0
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_0                          0x0
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_FALSE                      0x0
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_ENABLED                    0x1
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_ON                         0x1
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_1                          0x1
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_TRUE                       0x1
#define PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_DEFAULT                    PS_CYCLESTATS_DX12_MULTIDEVICE_HACK_DISABLED


#define PS_D3D_DEBUG_HOOKS_STRING                                      "6ee18f"
#define PS_D3D_DEBUG_HOOKS_ID                                          0x006ee18f
#define PS_D3D_DEBUG_HOOKS_OVERINSTALL                                 0 // OVERRIDE
#define PS_D3D_DEBUG_HOOKS_OFF                                         0x00000000
#define PS_D3D_DEBUG_HOOKS_OS_EXIT_HOOKS_ON                            0x00000001
#define PS_D3D_DEBUG_HOOKS_PERF_MARKERS_ON_FOR_DX9                     0x00000002
#define PS_D3D_DEBUG_HOOKS_PERF_MARKERS_ON_FOR_DX11                    0x00000004
#define PS_D3D_DEBUG_HOOKS_PERF_MARKERS_ON_FOR_DX12                    0x00000008
#define PS_D3D_DEBUG_HOOKS_PERF_MARKERS_ON                             0x0000000e
#define PS_D3D_DEBUG_HOOKS_CLASS_NAME_TRACKING_ON                      0x00000010
#define PS_D3D_DEBUG_HOOKS_TIMESTAMP_CHECK_ON                          0x00000020
#define PS_D3D_DEBUG_HOOKS_ECL_MERGING                                 0x00000040
#define PS_D3D_DEBUG_HOOKS_MISC_DEBUG_ON                               0x00000030
#define PS_D3D_DEBUG_HOOKS_ON                                          0x0000007f
#define PS_D3D_DEBUG_HOOKS_DEFAULT                                     PS_D3D_DEBUG_HOOKS_OFF


#define PS_DEBUG_FILE_STRING                                           "09753192"
#define PS_DEBUG_FILE_ID                                               0x00aa265d
#define PS_DEBUG_FILE_OVERINSTALL                                      0 // OVERRIDE
#define PS_DEBUG_FILE_OFF                                              0x55695605
#define PS_DEBUG_FILE_DISABLED                                         0x55695605
#define PS_DEBUG_FILE_ON                                               0x49659773
#define PS_DEBUG_FILE_ENABLED                                          0x49659773


#define PS_DEBUG_FILENAME_STRING                                       "81743389"
#define PS_DEBUG_FILENAME_ID                                           0x008f2a02
#define PS_DEBUG_FILENAME_OVERINSTALL                                  0 // OVERRIDE


#define PS_DEBUG_IO_BUFSIZE_STRING                                     "1448d7"
#define PS_DEBUG_IO_BUFSIZE_ID                                         0x001448d7
#define PS_DEBUG_IO_BUFSIZE_OVERINSTALL                                0 // OVERRIDE
#define PS_DEBUG_IO_BUFSIZE_DEFAULT_BUFSIZE_X86                        0x10000
#define PS_DEBUG_IO_BUFSIZE_DEFAULT_BUFSIZE_X64                        0x80000


#define PS_DEBUG_IO_MODE_STRING                                        "03a4df"
#define PS_DEBUG_IO_MODE_ID                                            0x0003a4df
#define PS_DEBUG_IO_MODE_OVERINSTALL                                   0 // OVERRIDE
#define PS_DEBUG_IO_MODE_USE_UM_FILEIO_IF_NO_KMD                       0x00000000
#define PS_DEBUG_IO_MODE_USE_KMD_FILEIO                                0x00000001
#define PS_DEBUG_IO_MODE_USE_UM_FILEIO                                 0x00000002
#define PS_DEBUG_IO_MODE_DEFAULT                                       PS_DEBUG_IO_MODE_USE_UM_FILEIO_IF_NO_KMD


#define PS_DEBUG_PRINT_STRING                                          "23818512"
#define PS_DEBUG_PRINT_ID                                              0x001fe641
#define PS_DEBUG_PRINT_OVERINSTALL                                     0 // OVERRIDE
#define PS_DEBUG_PRINT_OFF                                             0x88884133
#define PS_DEBUG_PRINT_DISABLED                                        0x88884133
#define PS_DEBUG_PRINT_ON                                              0x65357577
#define PS_DEBUG_PRINT_ENABLED                                         0x65357577


#define PS_DEBUG_PRINT_BUFSIZE_STRING                                  "99344152"
#define PS_DEBUG_PRINT_BUFSIZE_ID                                      0x00e550f9
#define PS_DEBUG_PRINT_BUFSIZE_OVERINSTALL                             0 // OVERRIDE


#define PS_DEBUG_PRINT_FLAGS_STRING                                    "08329721"
#define PS_DEBUG_PRINT_FLAGS_ID                                        0x00457323
#define PS_DEBUG_PRINT_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_DEBUG_PRINT_FLAGS_DUMP_STATE_INITIAL                        0x00000001
#define PS_DEBUG_PRINT_FLAGS_DUMP_STATE_FINAL                          0x00000002


#define PS_DEFER_SET_TEX_STRING                                        "614f7dc0"
#define PS_DEFER_SET_TEX_ID                                            0x004f3a81
#define PS_DEFER_SET_TEX_OVERINSTALL                                   0 // OVERRIDE
#define PS_DEFER_SET_TEX_OFF                                           0x77b537f1
#define PS_DEFER_SET_TEX_DISABLED                                      0x77b537f1
#define PS_DEFER_SET_TEX_ON                                            0x12242210
#define PS_DEFER_SET_TEX_ENABLED                                       0x12242210


#define PS_DEFER_SET_TEX_FLAGS_STRING                                  "614f7dc1"
#define PS_DEFER_SET_TEX_FLAGS_ID                                      0x004f3a82
#define PS_DEFER_SET_TEX_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_DEFER_SET_TEX_FLAGS_DONT_DEFER_HS_DS_GS_SET_STATE           0x00000001


#define PS_DEPTH_OPT_IN_SHADER_STRING                                  "83915032"
#define PS_DEPTH_OPT_IN_SHADER_ID                                      0x00465221
#define PS_DEPTH_OPT_IN_SHADER_OVERINSTALL                             0 // OVERRIDE
#define PS_DEPTH_OPT_IN_SHADER_OFF                                     0x00000000
#define PS_DEPTH_OPT_IN_SHADER_DISABLED                                0x00000000
#define PS_DEPTH_OPT_IN_SHADER_ON                                      0x00000001
#define PS_DEPTH_OPT_IN_SHADER_ENABLED                                 0x00000001
#define PS_DEPTH_OPT_IN_SHADER_DEFAULT                                 PS_DEPTH_OPT_IN_SHADER_ON


#define PS_DOMAIN_SHADER_DUMP_STRING                                   "38144972"
#define PS_DOMAIN_SHADER_DUMP_ID                                       0x00bc32ef
#define PS_DOMAIN_SHADER_DUMP_OVERINSTALL                              0 // OVERRIDE
#define PS_DOMAIN_SHADER_DUMP_OFF                                      0x38672673
#define PS_DOMAIN_SHADER_DUMP_DISABLED                                 0x38672673
#define PS_DOMAIN_SHADER_DUMP_ON                                       0x62481129
#define PS_DOMAIN_SHADER_DUMP_ENABLED                                  0x62481129


#define PS_DOMAIN_SHADER_DUMP_FLAGS_STRING                             "19156670"
#define PS_DOMAIN_SHADER_DUMP_FLAGS_ID                                 0x00307222
#define PS_DOMAIN_SHADER_DUMP_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS           0x00000001
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS            0x00000002
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                   0x00000004
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS           0x02000000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS            0x00000008
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_NVINST                        0x00000020
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_NVVM                          0x00000020
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE                 0x00000040
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE                 0x00000080
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST              0x00000120
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS                0x00000200
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC                0x00000400
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE          0x00000800
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS              0x00001000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE            0x00002000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE             0x00004000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME           0x00010000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED          0x00020000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS         0x00040000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER      0x00080000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS       0x00100000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE 0x00200000
#define PS_DOMAIN_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME           0x00400000


#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_STRING                        "34ab6004"
#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_ID                            0x00157040
#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_OVERINSTALL                   0 // OVERRIDE
#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_DEVICE_INFER_HAS_WORK         0x00000001
#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_NO_BARRIER_HAZARD             0x00000002
#define PS_DROP_EMPTY_COMMAND_LIST_FLAGS_DEFAULT                       0x0


#define PS_DX10_NULL_STRING                                            "f1925143"
#define PS_DX10_NULL_ID                                                0x00c8c57c
#define PS_DX10_NULL_OVERINSTALL                                       0 // OVERRIDE
#define PS_DX10_NULL_OFF                                               0x00000000
#define PS_DX10_NULL_DRIVER                                            0x00000001
#define PS_DX10_NULL_HARDWARE                                          0x00000002
#define PS_DX10_NULL_HOTKEY                                            0x00000010


#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_STRING                         "12657269"
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_ID                             0x00c44dfb
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DUMP_HEX_SPH                   0x00000001
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DELETE_EMPTY_DUMP_FILES        0x00000002
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DUMP_HEX_UCODE                 0x00000004
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DUMP_DX_RUNTIME_HASH_IN_SUMMARY 0x00000008
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DUMP_JSON_OUTPUT               0x00000010
#define PS_DX10_SHADER_DUMP_DEBUG_FLAGS_DEFAULT                        0


#define PS_DX10_SHADER_DUMP_ON_CREATION_STRING                         "22359421"
#define PS_DX10_SHADER_DUMP_ON_CREATION_ID                             0x00d74dd8
#define PS_DX10_SHADER_DUMP_ON_CREATION_OVERINSTALL                    0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_ON_CREATION_OFF                            0x07084358
#define PS_DX10_SHADER_DUMP_ON_CREATION_DISABLED                       0x07084358
#define PS_DX10_SHADER_DUMP_ON_CREATION_ON                             0x64308112
#define PS_DX10_SHADER_DUMP_ON_CREATION_ENABLED                        0x64308112
#define PS_DX10_SHADER_DUMP_ON_CREATION_DEFAULT                        PS_DX10_SHADER_DUMP_ON_CREATION_OFF


#define PS_DX10_SHADER_DUMP_ON_CREATION_FILENAME_STRING                "18979468"
#define PS_DX10_SHADER_DUMP_ON_CREATION_FILENAME_ID                    0x003737b9
#define PS_DX10_SHADER_DUMP_ON_CREATION_FILENAME_OVERINSTALL           0 // OVERRIDE


#define PS_DX10_SHADER_DUMP_SHADER_COLLECTION_HASH_STRING              "b79e9b"
#define PS_DX10_SHADER_DUMP_SHADER_COLLECTION_HASH_ID                  0x00b79e9b
#define PS_DX10_SHADER_DUMP_SHADER_COLLECTION_HASH_OVERINSTALL         0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_SHADER_COLLECTION_HASH_DEFAULT             0


#define PS_DX10_SHADER_DUMP_SHADER_HASH_STRING                         "649b71"
#define PS_DX10_SHADER_DUMP_SHADER_HASH_ID                             0x00649b71
#define PS_DX10_SHADER_DUMP_SHADER_HASH_OVERINSTALL                    0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_SHADER_HASH_DEFAULT                        0


#define PS_DX10_SHADER_DUMP_SHADER_HASHES_STRING_STRING                "b5f0247c"
#define PS_DX10_SHADER_DUMP_SHADER_HASHES_STRING_ID                    0x00a11b4b
#define PS_DX10_SHADER_DUMP_SHADER_HASHES_STRING_OVERINSTALL           0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_SHADER_HASHES_STRING_DEFAULT               ""


#define PS_DX10_SHADER_DUMP_UCODE_HASH_STRING                          "e4d39e"
#define PS_DX10_SHADER_DUMP_UCODE_HASH_ID                              0x00e4d39e
#define PS_DX10_SHADER_DUMP_UCODE_HASH_OVERINSTALL                     0 // OVERRIDE
#define PS_DX10_SHADER_DUMP_UCODE_HASH_DEFAULT                         0


#define PS_DX10_SURFACE_PLACEMENT_STRING                               "80923143"
#define PS_DX10_SURFACE_PLACEMENT_ID                                   0x00b1729d
#define PS_DX10_SURFACE_PLACEMENT_OVERINSTALL                          0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_OFF                                  0x00000000
#define PS_DX10_SURFACE_PLACEMENT_DISABLED                             0x00000000
#define PS_DX10_SURFACE_PLACEMENT_ON                                   0x00000001
#define PS_DX10_SURFACE_PLACEMENT_ENABLED                              0x00000001
#define PS_DX10_SURFACE_PLACEMENT_DEFAULT                              PS_DX10_SURFACE_PLACEMENT_ON


#define PS_DX10_SURFACE_PLACEMENT_ALLOW_STRING                         "77095603"
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_ID                             0x0094c536
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_OVERINSTALL                    0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_FORCE_HOSTMEM               0x00000100
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_FORCE_VIDMEM                0x00000200
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_FORCE_MASK                  0x00000300
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_HOSTMEM             0x00000400
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_VIDMEM_ALL          0x00000800
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_MASK                0x00000C00
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_FORCE_HOSTMEM               0x00001000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_FORCE_VIDMEM                0x00002000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_FORCE_MASK                  0x00003000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_HOSTMEM             0x00004000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_VIDMEM_ALL          0x00008000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_MASK                0x0000C000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_FORCE_HOSTMEM                0x00010000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_FORCE_VIDMEM                 0x00020000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_FORCE_MASK                   0x00030000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_HOSTMEM              0x00040000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_VIDMEM_ALL           0x00080000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_MASK                 0x000C0000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_BOTH                 0x000C0000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RESOLVE_TARGET_HIGH_PRIORITY   0x00100000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_DISABLE_CPU_VISIBLE_VIDMEM     0x01000000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_VIDMEM_SLOW         0x40000000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_VIDMEM_SLOW         0x80000000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_VIDMEM_SLOW          0x02000000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_DISABLE_ADJUST_PRIORITY_BY_SIZE 0x00200000
#define PS_DX10_SURFACE_PLACEMENT_ALLOW_DEFAULT                        PS_DX10_SURFACE_PLACEMENT_ALLOW_RESOLVE_TARGET_HIGH_PRIORITY


#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_STRING            "17298761"
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_ID                0x00944462
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_OVERINSTALL       0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_DISALLOW_ALL      0x00000001
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_DISALLOW_RENDER_TARGETS 0x00000002
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_DISALLOW_DEPTH_STENCILS 0x00000004
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_DISALLOW_UAVS     0x00000008
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_FLAGS_DEFAULT           0x0


#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_MIN_SIZE_STRING         "17298762"
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_MIN_SIZE_ID             0x00944463
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_MIN_SIZE_OVERINSTALL    0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_BACKINGSTORE_MIN_SIZE_DEFAULT        0x8000


#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_STRING              "94178359"
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_ID                  0x00ea83c5
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_OVERINSTALL         0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_HIGH       0x187F7082
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_MAXIMUM    0x83B7BC1A
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_MAXIMUM_IF_MIXED_BUS 0xFC17F610
#define PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_DEFAULT             PS_DX10_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_HIGH


#define PS_DX10_SURFACE_PLACEMENT_STATS_STRING                         "53302112"
#define PS_DX10_SURFACE_PLACEMENT_STATS_ID                             0x00f39412
#define PS_DX10_SURFACE_PLACEMENT_STATS_OVERINSTALL                    0 // OVERRIDE
#define PS_DX10_SURFACE_PLACEMENT_STATS_OFF                            0x00000000
#define PS_DX10_SURFACE_PLACEMENT_STATS_DISABLED                       0x00000000
#define PS_DX10_SURFACE_PLACEMENT_STATS_ON                             0x00000001
#define PS_DX10_SURFACE_PLACEMENT_STATS_ENABLED                        0x00000001
#define PS_DX10_SURFACE_PLACEMENT_STATS_DEFAULT                        PS_DX10_SURFACE_PLACEMENT_STATS_OFF


#define PS_DX12_ASM_SHADER_REPLACEMENT_STRING                          "94724172"
#define PS_DX12_ASM_SHADER_REPLACEMENT_ID                              0x0025b821
#define PS_DX12_ASM_SHADER_REPLACEMENT_OVERINSTALL                     0 // OVERRIDE
#define PS_DX12_ASM_SHADER_REPLACEMENT_OFF                             0xbb832af7
#define PS_DX12_ASM_SHADER_REPLACEMENT_DISABLED                        0xbb832af7
#define PS_DX12_ASM_SHADER_REPLACEMENT_ON                              0x81c02e66
#define PS_DX12_ASM_SHADER_REPLACEMENT_ENABLED                         0x81c02e66
#define PS_DX12_ASM_SHADER_REPLACEMENT_DEFAULT                         PS_DX12_ASM_SHADER_REPLACEMENT_ON


#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_STRING               "0153335"
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_ID                   0x00e107da
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_OVERINSTALL          0 // OVERRIDE
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_ALL_SRV_ACCESSIBLE   0x00000001
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_ALL_CBV_ACCESSIBLE   0x00000010
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_ALL_UAV_ACCESSIBLE   0x00000100
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_NO_SRV_ACCESSIBLE    0x00000002
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_NO_CBV_ACCESSIBLE    0x00000020
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_NO_UAV_ACCESSIBLE    0x00000200
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_ALL_RESOURCES_BOUND  0x00000111
#define PS_DX12_FORCE_RESOURCE_TYPE_ACCESSIBILITY_DEFAULT              0x0


#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_STRING                        "0562AD73"
#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_ID                            0x00c96e67
#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_OVERINSTALL                   0 // OVERRIDE
#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_OFF                           0x00000000
#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_ON                            0x00000001
#define PS_DX12_HEAP_PRIORITIES_OVERRIDE_DEFAULT                       PS_DX12_HEAP_PRIORITIES_OVERRIDE_OFF


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_STRING                       "25367753"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_ID                           0x0049c741
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_OVERINSTALL                  0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_OFF                          0x00000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_0                            0x00000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_FALSE                        0x00000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL                    0x00000008
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL_UNTIL_PCAS         0x00000010
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL_CROSS_CL_DEFERRAL  0x00000020
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL_PRE_CROSS_CL_DEFERRAL 0x00000040
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL_NO_GRAPHICS_OPTIMIZATIONS 0x00000080
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFER_ALL_DISCARD_IN_DISPATCH_TABLE 0x00000100
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DO_ONLY_SYNC_NO_DEFERRAL     0x00010000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_NO_WFI_REMOVAL               0x00020000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_KEEP_REDUNDANT_BARRIERS      0x00040000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DEFAULT                      PS_DX12_RESOURCE_BARRIER_DEFERRAL_OFF


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_STRING  "18976427"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_ID      0x00195789
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_OVERINSTALL 0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_VERTEX_BUFFER 0x00000001
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_CONSTANT_BUFFER 0x00000002
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_INDEX_BUFFER 0x00000004
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_RENDER_TARGET 0x00000008
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_UNORDERED_ACCESS 0x00000010
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_DEPTH_STENCIL_WRITE 0x00000020
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_DEPTH_STENCIL_READ 0x00000040
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_SHADER_RESOURCE 0x00000080
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_STREAM_OUTPUT 0x00000100
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_INDIRECT_ARGUMENT_OR_PREDICATION 0x00000200
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_COPY_DEST 0x00000400
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_COPY_SOURCE 0x00000800
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_RESOLVE_DEST 0x00001000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_RESOLVE_SOURCE 0x00002000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_RAYTRACING_ACCELERATION_STRUCTURE_READ 0x00004000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_RAYTRACING_ACCELERATION_STRUCTURE_WRITE 0x00008000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_SHADING_RATE_SOURCE 0x00010000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_NO_ACCESS 0x80000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_ALL     0x8001ffff
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_DEFAULT PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_ACCESS_TYPES_ALL


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_STRING    "12458921"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_ID        0x00461397
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_OVERINSTALL 0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_ALL       0x00000001
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_DRAW      0x00000002
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_INPUT_ASSEMBLER 0x00000004
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_WORLD_SHADING 0x00000008
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_PIXEL_SHADING 0x00000010
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_DEPTH_STENCIL 0x00000020
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_RENDER_TARGET 0x00000040
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_COMPUTE_SHADING 0x00000080
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_RAYTRACING 0x00000100
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_COPY      0x00000200
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_RESOLVE   0x00000400
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_EXECUTE_INDIRECT_OR_PREDICATION 0x00000800
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_ALL_SHADING 0x00001000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_NON_PIXEL_SHADING 0x00002000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO 0x00004000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_BUILD_RAYTRACING_ACCELERATION_STRUCTURE 0x00800000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_COPY_RAYTRACING_ACCELERATION_STRUCTURE 0x01000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_SPLIT     0x80000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_SYNC_TYPES_DEFAULT   0x81807fff


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_STRING         "54123398"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_ID             0x00249239
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_OVERINSTALL    0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_TRANSITION     0x00000001
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_ALIASING       0x00000002
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_UAV            0x00000004
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_RANGED         0x00000008
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_ALL            0x0000000f
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_DEFAULT        PS_DX12_RESOURCE_BARRIER_DEFERRAL_BARRIER_TYPES_ALL


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_STRING "13497822"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_ID 0x00932717
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_OVERINSTALL 0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_NONE 0x00000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_VERTEX_AND_CONSTANT_BUFFER 0x00000001
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_INDEX_BUFFER 0x00000002
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_RENDER_TARGET 0x00000004
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_UNORDERED_ACCESS 0x00000008
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_DEPTH_WRITE 0x00000010
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_DEPTH_READ 0x00000020
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_NON_PIXEL_SHADER_RESOURCE 0x00000040
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_PIXEL_SHADER_RESOURCE 0x00000080
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_STREAM_OUT 0x00000100
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_INDIRECT_ARGUMENT 0x00000200
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_COPY_DEST 0x00000400
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_COPY_SOURCE 0x00000800
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_RESOLVE_DEST 0x00001000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_RESOLVE_SOURCE 0x00002000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_SHADING_RATE_SOURCE 0x01000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_RAYTRACING_ACCELERATION_STRUCTURE 0x00400000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_COMMON 0x80000000
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_DEFAULT PS_DX12_RESOURCE_BARRIER_DEFERRAL_DISABLE_TRANSITION_STATES_NONE


#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_STRING           "58216654"
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_ID               0x0038a323
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_OVERINSTALL      0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_DIRECT           0x00000001
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_COMPUTE_ONLY     0x00000002
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_COPY_ONLY        0x00000004
#define PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_DEFAULT          PS_DX12_RESOURCE_BARRIER_DEFERRAL_QUEUE_TYPES_DIRECT


#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_STRING                      "15437531"
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_ID                          0x0047b891
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_OVERINSTALL                 0 // OVERRIDE
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_OFF                         0x00000000
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_0                           0x00000000
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_FALSE                       0x00000000
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_RT_TO_SRV_OVERRIDE          0x00000001
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_DEFER_COPY_BARRIERS_UNTIL_DRAW 0x00000002
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_DEFER_COPY_BARRIERS_UNTIL_DRAW_ALWAYS_ON 0x00000006
#define PS_DX12_RESOURCE_BARRIER_OVERRIDES_DEFAULT                     PS_DX12_RESOURCE_BARRIER_OVERRIDES_OFF


#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_STRING        "00620BAB"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_ID            0x000f0bab
#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_OVERINSTALL   0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_OFF           0x00000000
#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_ON            0x00000001
#define PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_DEFAULT       PS_DX12_SURFACE_PLACEMENT_BAR1_DUMP_UPLOAD_HEAPS_OFF


#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_STRING               "006200Be"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_ID                   0x000f00be
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_OVERINSTALL          0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_FIRST_COME_FIRST_SERVE 0x00000000
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_GREATER_THAN         0x00000001
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_LESS_THAN            0x00000002
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_INCLUDE_SIZE_LIST    0x00000003
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_EXCLUDE_SIZE_LIST    0x00000004
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_TARGET_HEAP_ORDER    0x00000005
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_DEFAULT              PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTICS_FIRST_COME_FIRST_SERVE


#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTIC_LIST_STRING           "006200BF"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTIC_LIST_ID               0x000f00bf
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTIC_LIST_OVERINSTALL      0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_HEURISTIC_LIST_DEFAULT          L""


#define PS_DX12_SURFACE_PLACEMENT_BAR1_LOCK_CACHING_LIST_STRING        "006200B1"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_LOCK_CACHING_LIST_ID            0x000f00b1
#define PS_DX12_SURFACE_PLACEMENT_BAR1_LOCK_CACHING_LIST_OVERINSTALL   0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_LOCK_CACHING_LIST_DEFAULT       L""


#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_STRING               "006200BB"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_ID                   0x000f00bb
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_OVERINSTALL          0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_ENABLE_LOCK_CACHING  0x00000001
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_IGNORE_SYSTEM_CAPABILITIES 0x00000002
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_DISALLOW_GRID        0x00000004
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_DISALLOW_VGX         0x00000008
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_DISALLOW_SLI         0x00000010
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_IGNORE_SIZE_CLAMPING 0x00000020
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_IGNORE_NVAPI_HINTS   0X00000040
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_AVOID_INTEL_PERF_BUG_3440153 0x00000080
#define PS_DX12_SURFACE_PLACEMENT_BAR1_MISC_FLAGS_DEFAULT              0x0


#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTE_INTERNAL_FLAGS_STRING   "0062EEBB"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTE_INTERNAL_FLAGS_ID       0x000feebb
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTE_INTERNAL_FLAGS_OVERINSTALL 0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTE_INTERNAL_FLAGS_PUSHBUFFERS 0x00000001
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTE_INTERNAL_FLAGS_DEFAULT  0x0


#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_STRING                "006200BA"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_ID                    0x000f00ba
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_OVERINSTALL           0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_OFF                   0x00000000
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_ON                    0x00000001
#define PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_DEFAULT               PS_DX12_SURFACE_PLACEMENT_BAR1_PROMOTION_OFF


#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_STRING                     "006200BD"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_ID                         0x000f00bd
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_OVERINSTALL                0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_DEFAULT                    0x0


#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_LIMIT_STRING               "006200FF"
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_LIMIT_ID                   0x000f00ff
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_LIMIT_OVERINSTALL          0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_BAR1_SIZE_LIMIT_DEFAULT              0x0


#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STRING                         "ff39208f"
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_ID                             0x0039208f
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_INVALID_HEAP_PRIORITY_LOW      0x0000000000000001
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_INVALID_HEAP_PRIORITY_NORMAL   0x0000000000000002
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_INVALID_HEAP_PRIORITY_HIGH     0x0000000000000004
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_INVALID_HEAP_PRIORITY_MAXIMUM  0x0000000000000008
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_BUFFER_HEAP_PRIORITY_LOW       0x0000000000000010
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_BUFFER_HEAP_PRIORITY_NORMAL    0x0000000000000020
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_BUFFER_HEAP_PRIORITY_HIGH      0x0000000000000040
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_BUFFER_HEAP_PRIORITY_MAXIMUM   0x0000000000000080
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STATIC_TEX_HEAP_PRIORITY_LOW   0x0000000000000100
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STATIC_TEX_HEAP_PRIORITY_NORMAL 0x0000000000000200
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STATIC_TEX_HEAP_PRIORITY_HIGH  0x0000000000000400
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STATIC_TEX_HEAP_PRIORITY_MAXIMUM 0x0000000000000800
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_RTV_HEAP_PRIORITY_LOW          0x0000000000001000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_RTV_HEAP_PRIORITY_NORMAL       0x0000000000002000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_RTV_HEAP_PRIORITY_HIGH         0x0000000000004000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_RTV_HEAP_PRIORITY_MAXIMUM      0x0000000000008000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_TIER2_HEAP_PRIORITY_LOW        0x0000000000010000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_TIER2_HEAP_PRIORITY_NORMAL     0x0000000000020000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_TIER2_HEAP_PRIORITY_HIGH       0x0000000000040000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_TIER2_HEAP_PRIORITY_MAXIMUM    0x0000000000080000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_INVALID_HEAP_BONUS_PRIORITY_MASK 0x0000000000f00000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_BUFFER_HEAP_BONUS_PRIORITY_MASK 0x000000000f000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_STATIC_TEX_HEAP_BONUS_PRIORITY_MASK 0x00000000f0000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_RTV_HEAP_BONUS_PRIORITY_MASK   0x0000000f00000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_TIER2_HEAP_BONUS_PRIORITY_MASK 0x000000f000000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_MODIFIED_PRIORITIES_MASK       0x000000ffffffffff
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_ASSUME_UAVS_IN_BUFFER_HEAPS    0x0000010000000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_ASSUME_UAVS_NOT_IN_BUFFER_HEAPS 0x0000020000000000
#define PS_DX12_SURFACE_PLACEMENT_FLAGS_DEFAULT                        0x0


#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_STRING                  "007201AC"
#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_ID                      0x000e0ca0
#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_OVERINSTALL             0 // OVERRIDE
#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_OFF                     0x00000000
#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_ON                      0x00000001
#define PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_DEFAULT                 PS_DX12_SURFACE_PLACEMENT_LOCK_CACHING_ON


#define PS_DX_ASM_SHADER_REPLACEMENT_FILENAME_STRING                   "01234742"
#define PS_DX_ASM_SHADER_REPLACEMENT_FILENAME_ID                       0x007122e1
#define PS_DX_ASM_SHADER_REPLACEMENT_FILENAME_OVERINSTALL              0 // OVERRIDE


#define PS_DX_ASM_SHADER_REPLACEMENT_FLAGS_STRING                      "94724171"
#define PS_DX_ASM_SHADER_REPLACEMENT_FLAGS_ID                          0x0025b820
#define PS_DX_ASM_SHADER_REPLACEMENT_FLAGS_OVERINSTALL                 0 // OVERRIDE
#define PS_DX_ASM_SHADER_REPLACEMENT_FLAGS_DISABLE_DRIVER_SHADERS      0x00000001


#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_STRING             "0xa345c0"
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_ID                 0x00a345c0
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_OVERINSTALL        0 // OVERRIDE
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_SLOT_MASK          0x000000FF
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_SPACE_MASK         0xFFFFFF00
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_SPACE_SHIFT        8
#define PS_DX_ASM_SHADER_REPLACEMENT_NVAPI_HLSL_EXT_DEFAULT            0


#define PS_DYNAMIC_CTA_REFORMING_STRING                                "0376a1fd"
#define PS_DYNAMIC_CTA_REFORMING_ID                                    0x00afd100
#define PS_DYNAMIC_CTA_REFORMING_OVERINSTALL                           0 // OVERRIDE
#define PS_DYNAMIC_CTA_REFORMING_OFF                                   0x00000000
#define PS_DYNAMIC_CTA_REFORMING_ON                                    0x00000001
#define PS_DYNAMIC_CTA_REFORMING_DEFAULT                               PS_DYNAMIC_CTA_REFORMING_ON


#define PS_ECL_MERGE_FLAGS_STRING                                      "01694446"
#define PS_ECL_MERGE_FLAGS_ID                                          0x006ee191
#define PS_ECL_MERGE_FLAGS_OVERINSTALL                                 0 // OVERRIDE
#define PS_ECL_MERGE_FLAGS_DISABLE_MERGING                             0x00000001
#define PS_ECL_MERGE_FLAGS_LOG_MULTIPLE_FRAMES                         0x00000002
#define PS_ECL_MERGE_FLAGS_BASIC_LOGGING                               0x00000004
#define PS_ECL_MERGE_FLAGS_EXTENDED_LOGGING                            0x00000008
#define PS_ECL_MERGE_FLAGS_ETW_LOGGING                                 0x00000010
#define PS_ECL_MERGE_FLAGS_FRAME_SUMMARIES                             0x00000020
#define PS_ECL_MERGE_FLAGS_DEFAULT                                     OFF


#define PS_ECL_MERGE_HOTKEY_STRING                                     "01694445"
#define PS_ECL_MERGE_HOTKEY_ID                                         0x006ee190
#define PS_ECL_MERGE_HOTKEY_OVERINSTALL                                0 // OVERRIDE
#define PS_ECL_MERGE_HOTKEY_DEFAULT                                    0x7a


#define PS_ECL_MERGE_LOG_END_FRAME_STRING                              "01694448"
#define PS_ECL_MERGE_LOG_END_FRAME_ID                                  0x006ee193
#define PS_ECL_MERGE_LOG_END_FRAME_OVERINSTALL                         0 // OVERRIDE
#define PS_ECL_MERGE_LOG_END_FRAME_DEFAULT                             0


#define PS_ECL_MERGE_LOG_START_FRAME_STRING                            "01694447"
#define PS_ECL_MERGE_LOG_START_FRAME_ID                                0x006ee192
#define PS_ECL_MERGE_LOG_START_FRAME_OVERINSTALL                       0 // OVERRIDE
#define PS_ECL_MERGE_LOG_START_FRAME_DEFAULT                           0


#define PS_EVENTTRACEDX9_STRING                                        "af502bd12d"
#define PS_EVENTTRACEDX9_ID                                            0x00d496ba
#define PS_EVENTTRACEDX9_OVERINSTALL                                   0 // OVERRIDE
#define PS_EVENTTRACEDX9_HOTKEY                                        0x00000001
#define PS_EVENTTRACEDX9_MCEVENTS                                      0x00000002
#define PS_EVENTTRACEDX9_ENTRYPOINTS                                   0x00000004
#define PS_EVENTTRACEDX9_REFCOUNT_WAIT                                 0x00000010
#define PS_EVENTTRACEDX9_SUPERTRI                                      0x00000020
#define PS_EVENTTRACEDX9_SHADER_COMPILE                                0x00000040
#define PS_EVENTTRACEDX9_VTEX                                          0x00000080
#define PS_EVENTTRACEDX9_PSLOADBALANCE                                 0x00000100
#define PS_EVENTTRACEDX9_ASYNCDEVICEWAIT                               0x00000200
#define PS_EVENTTRACEDX9_VIDEO                                         0x00001000
#define PS_EVENTTRACEDX9_QUERIES                                       0x00002000


#define PS_EVENTTRACEDX9_ENTRY_POINTS_STRING                           "af502bd12e"
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ID                               0x00f4c603
#define PS_EVENTTRACEDX9_ENTRY_POINTS_OVERINSTALL                      0 // OVERRIDE
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_LOCK                 0x00000001
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_LOCK_ASYNC           0x00000002
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_QUERY                0x00000004
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_FLUSH                0x00000008
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_BLIT                 0x00000010
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_PRESENT              0x00000020
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_DEVICE               0x00000040
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_RESOURCE             0x00000080
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_STATE                0x00000100
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_STATE_LEGACY         0x00000200
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_DRAW                 0x00000400
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_DRAW2                0x00000800
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_VIDEO                0x00001000
#define PS_EVENTTRACEDX9_ENTRY_POINTS_ENTRY_POINT_ADAPTER              0x00002000


#define PS_FILE_PATH_STRING                                            "61807119"
#define PS_FILE_PATH_ID                                                0x00b7b8ac
#define PS_FILE_PATH_OVERINSTALL                                       0 // OVERRIDE
#define PS_FILE_PATH_DEFAULT                                           "c:"


#define PS_FILTERING_SHADER_STRING                                     "42568528"
#define PS_FILTERING_SHADER_ID                                         0x00c08217
#define PS_FILTERING_SHADER_OVERINSTALL                                0 // OVERRIDE
#define PS_FILTERING_SHADER_OFF                                        0x33986383
#define PS_FILTERING_SHADER_DISABLED                                   0x33986383
#define PS_FILTERING_SHADER_ON                                         0x36183041
#define PS_FILTERING_SHADER_ENABLED                                    0x36183041


#define PS_FILTERING_SHADER_ADDRESS_MODE_STRING                        "22948572"
#define PS_FILTERING_SHADER_ADDRESS_MODE_ID                            0x00a14785
#define PS_FILTERING_SHADER_ADDRESS_MODE_OVERINSTALL                   0 // OVERRIDE
#define PS_FILTERING_SHADER_ADDRESS_MODE_DEFAULT                       0x0


#define PS_FILTERING_SHADER_FLAGS_STRING                               "68158841"
#define PS_FILTERING_SHADER_FLAGS_ID                                   0x0030bbf1
#define PS_FILTERING_SHADER_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define PS_FILTERING_SHADER_FLAGS_FILTERINGSHADER                      0x00000001
#define PS_FILTERING_SHADER_FLAGS_FILTERINGSHADER_SIMPLE_SEARCH        0x00000002
#define PS_FILTERING_SHADER_FLAGS_FILTERINGSHADER_MIPOK                0x00000004
#define PS_FILTERING_SHADER_FLAGS_FILTERINGSHADER_ADDRESSMODE          0x00000010


#define PS_FILTERING_SHADER_MAXANISO_STRING                            "11266437"
#define PS_FILTERING_SHADER_MAXANISO_ID                                0x00db1d0f
#define PS_FILTERING_SHADER_MAXANISO_OVERINSTALL                       0 // OVERRIDE
#define PS_FILTERING_SHADER_MAXANISO_DEFAULT                           0x0


#define PS_FILTERING_SHADER_STATS_STRING                               "73492926"
#define PS_FILTERING_SHADER_STATS_ID                                   0x00eda232
#define PS_FILTERING_SHADER_STATS_OVERINSTALL                          0 // OVERRIDE
#define PS_FILTERING_SHADER_STATS_OFF                                  0x33726865
#define PS_FILTERING_SHADER_STATS_DISABLED                             0x33726865
#define PS_FILTERING_SHADER_STATS_ON                                   0x81228679
#define PS_FILTERING_SHADER_STATS_ENABLED                              0x81228679
#define PS_FILTERING_SHADER_STATS_DEFAULT                              PS_FILTERING_SHADER_STATS_OFF


#define PS_FILTERING_SHADER_THRESH_STRING                              "92952281"
#define PS_FILTERING_SHADER_THRESH_ID                                  0x0069d486
#define PS_FILTERING_SHADER_THRESH_OVERINSTALL                         0 // OVERRIDE
#define PS_FILTERING_SHADER_THRESH_DEFAULT                             32


#define PS_FORCEFOG_STRING                                             "06921107"
#define PS_FORCEFOG_ID                                                 0x008251de
#define PS_FORCEFOG_OVERINSTALL                                        0 // OVERRIDE
#define PS_FORCEFOG_OFF                                                0x88724e2a
#define PS_FORCEFOG_DISABLED                                           0x88724e2a
#define PS_FORCEFOG_ON                                                 0xb773cf10
#define PS_FORCEFOG_ENABLED                                            0xb773cf10


#define PS_FORCE_DSR_BLT_STRING                                        "37284362"
#define PS_FORCE_DSR_BLT_ID                                            0x008e6261
#define PS_FORCE_DSR_BLT_OVERINSTALL                                   0 // OVERRIDE
#define PS_FORCE_DSR_BLT_FORCE_ALL                                     0x00000001
#define PS_FORCE_DSR_BLT_FORCE_MSAA                                    0x00000002
#define PS_FORCE_DSR_BLT_FORCE_SCREEN_SIZE                             0x00000004
#define PS_FORCE_DSR_BLT_FORCE_FP_FORMAT                               0x00000008
#define PS_FORCE_DSR_BLT_DEFAULT                                       0x0


#define PS_FORCE_FULLSCREEN_LATEZ_STRING                               "44590982"
#define PS_FORCE_FULLSCREEN_LATEZ_ID                                   0x00f69863
#define PS_FORCE_FULLSCREEN_LATEZ_OVERINSTALL                          0 // OVERRIDE
#define PS_FORCE_FULLSCREEN_LATEZ_OFF                                  0x00000000
#define PS_FORCE_FULLSCREEN_LATEZ_DISABLED                             0x00000000
#define PS_FORCE_FULLSCREEN_LATEZ_ON                                   0x00000001
#define PS_FORCE_FULLSCREEN_LATEZ_ENABLED                              0x00000001
#define PS_FORCE_FULLSCREEN_LATEZ_DEFAULT                              PS_FORCE_FULLSCREEN_LATEZ_OFF


#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_STRING                         "44590324"
#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_ID                             0x00f69862
#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_ACCURATE_FULLSCREEN_CHECK      0x00000001
#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_ANALYSIS_ONLY                  0x00000002
#define PS_FORCE_FULLSCREEN_LATEZ_FLAGS_DEFAULT                        0x0


#define PS_FORCE_LOW_LATENCY_3D_NODE_STRING                            "94D15A1"
#define PS_FORCE_LOW_LATENCY_3D_NODE_ID                                0x0094d15a
#define PS_FORCE_LOW_LATENCY_3D_NODE_OVERINSTALL                       0 // OVERRIDE
#define PS_FORCE_LOW_LATENCY_3D_NODE_OFF                               0x00000000
#define PS_FORCE_LOW_LATENCY_3D_NODE_DISABLED                          0x00000000
#define PS_FORCE_LOW_LATENCY_3D_NODE_ON                                0x00000001
#define PS_FORCE_LOW_LATENCY_3D_NODE_ENABLED                           0x00000001
#define PS_FORCE_LOW_LATENCY_3D_NODE_DEFAULT                           PS_FORCE_LOW_LATENCY_3D_NODE_OFF


#define PS_FORMAT_SUBSTITUTION_STRING                                  "54496412"
#define PS_FORMAT_SUBSTITUTION_ID                                      0x00e61456
#define PS_FORMAT_SUBSTITUTION_OVERINSTALL                             0 // OVERRIDE
#define PS_FORMAT_SUBSTITUTION_OFF                                     0x00000000
#define PS_FORMAT_SUBSTITUTION_DISABLED                                0x00000000
#define PS_FORMAT_SUBSTITUTION_ON                                      0x00000001
#define PS_FORMAT_SUBSTITUTION_ENABLED                                 0x00000001
#define PS_FORMAT_SUBSTITUTION_DEFAULT                                 PS_FORMAT_SUBSTITUTION_ON


#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_STRING                        "54496414"
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_ID                            0x00e21156
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_OVERINSTALL                   0 // OVERRIDE
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_SCREEN_SIZE_CHECK        0x00000001
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_TYPED_FORMAT_CHECK       0x00000002
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_TEXTURE2D_CHECK          0x00000004
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_MIPMAPS_CHECK            0x00000008
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_INITIAL_DATA_CHECK       0x00000010
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_LOCKABLE_CHECK           0x00000020
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_SHARED_RESOURCES_CHECK   0x00000040
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_PRIMARIES_CHECK          0x00000080
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_SKIP_RENDERTARGET_CHECK       0x00000100
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_DEFAULT_KEPLER                0x00000000
#define PS_FORMAT_SUBSTITUTION_SKIPCHECK_DEFAULT                       0x0


#define PS_FORMAT_SUBSTITUTION_TYPE_STRING                             "54496413"
#define PS_FORMAT_SUBSTITUTION_TYPE_ID                                 0x00e21154
#define PS_FORMAT_SUBSTITUTION_TYPE_OVERINSTALL                        0 // OVERRIDE
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_ABGR16F_TO_R11G11B10F       0x00000001
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_R32F_TO_R16F                0x00000002
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_R11G11B10F_TO_RGBA8         0x00000004
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_SRGB_TO_RGB                 0x00000008
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_D32S8X24_TO_D24S8           0x00000010
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_D32S8X24_TO_D32             0x00000020
#define PS_FORMAT_SUBSTITUTION_TYPE_DEMOTE_RGBA32F_TO_RGBA16F          0x00000040
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_R5G6B5_TO_RGBA8            0x00000100
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_RG8_TO_RGBA8               0x00000200
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_R16F_TO_R32F               0x00000400
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_R16F_TO_RG16F              0x00000800
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_RGBX8_TO_RGB10A2           0x00001000
#define PS_FORMAT_SUBSTITUTION_TYPE_PROMOTE_RGBA8_TO_RGB10A2           0x00002000
#define PS_FORMAT_SUBSTITUTION_TYPE_ALLOW_FACTORED_SIZES               0x01000000
#define PS_FORMAT_SUBSTITUTION_TYPE_DEFAULT_KEPLER                     0x00000000
#define PS_FORMAT_SUBSTITUTION_TYPE_DEFAULT                            0x0


#define PS_GAMMATEXTURE_STRING                                         "56121345"
#define PS_GAMMATEXTURE_ID                                             0x002ce6c2
#define PS_GAMMATEXTURE_OVERINSTALL                                    0 // OVERRIDE
#define PS_GAMMATEXTURE_OFF                                            0x53212312
#define PS_GAMMATEXTURE_DISABLED                                       0x53212312
#define PS_GAMMATEXTURE_ON                                             0x56127897
#define PS_GAMMATEXTURE_ENABLED                                        0x56127897


#define PS_GEOMETRY_SHADER_DUMP_STRING                                 "49960973"
#define PS_GEOMETRY_SHADER_DUMP_ID                                     0x00a37eb1
#define PS_GEOMETRY_SHADER_DUMP_OVERINSTALL                            0 // OVERRIDE
#define PS_GEOMETRY_SHADER_DUMP_OFF                                    0x12457256
#define PS_GEOMETRY_SHADER_DUMP_DISABLED                               0x12457256
#define PS_GEOMETRY_SHADER_DUMP_ON                                     0x35830718
#define PS_GEOMETRY_SHADER_DUMP_ENABLED                                0x35830718


#define PS_GEOMETRY_SHADER_DUMP_FLAGS_STRING                           "12950094"
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_ID                               0x008137ea
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS         0x00000001
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS          0x00000002
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                 0x00000004
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_CUBEMAP_SHADERS             0x01000000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS         0x02000000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS          0x00000008
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_NVINST                      0x00000020
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_NVVM                        0x00000020
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE               0x00000040
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE               0x00000080
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST            0x00000120
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS              0x00000200
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC              0x00000400
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE        0x00000800
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS            0x00001000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE          0x00002000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE           0x00004000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME         0x00010000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED        0x00020000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS       0x00040000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER    0x00080000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS     0x00100000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE 0x00200000
#define PS_GEOMETRY_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME         0x00400000


#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_STRING                         "97d6b7"
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_ID                             0x0097d6b7
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_DISABLE_BREAK_ON_ASSERT        0x00000001
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_ENABLE_BREAK_ON_SNAPSHOT       0x00000002
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_ENABLE_BREAK_ON_WARNING        0x00000004
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_LOG_ASSERTS                    0x00000010
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_LOG_DEBUG_SNAPSHOTS            0x00000020
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_LOG_PRINTS                     0x00000040
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_LOG_WARNINGS                   0x00000080
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_LOG_ALL                        0x000000F0
#define PS_GPUKERNEL_DEBUG_HELPER_FLAGS_DEFAULT                        0


#define PS_GSOUTPUTBLOAT_STRING                                        "11175936"
#define PS_GSOUTPUTBLOAT_ID                                            0x00c60db0
#define PS_GSOUTPUTBLOAT_OVERINSTALL                                   0 // OVERRIDE
#define PS_GSOUTPUTBLOAT_OFF                                           0xF033B861
#define PS_GSOUTPUTBLOAT_DISABLED                                      0xF033B861
#define PS_GSOUTPUTBLOAT_ON                                            0xF033B862
#define PS_GSOUTPUTBLOAT_ENABLED                                       0xF033B862


#define PS_HOISTUSERCLIP_STRING                                        "3e524fed"
#define PS_HOISTUSERCLIP_ID                                            0x001e2f6a
#define PS_HOISTUSERCLIP_OVERINSTALL                                   0 // OVERRIDE
#define PS_HOISTUSERCLIP_OFF                                           0x0
#define PS_HOISTUSERCLIP_DISABLED                                      0x0
#define PS_HOISTUSERCLIP_ON                                            0x1
#define PS_HOISTUSERCLIP_ENABLED                                       0x1


#define PS_HOISTUSERCLIP_FLAGS_STRING                                  "3e524fee"
#define PS_HOISTUSERCLIP_FLAGS_ID                                      0x001e2f6b
#define PS_HOISTUSERCLIP_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_HOISTUSERCLIP_FLAGS_DISABLE_USERCLIP_HOISTING               0x00000001


#define PS_HULL_SHADER_DUMP_STRING                                     "81131154"
#define PS_HULL_SHADER_DUMP_ID                                         0x00257577
#define PS_HULL_SHADER_DUMP_OVERINSTALL                                0 // OVERRIDE
#define PS_HULL_SHADER_DUMP_OFF                                        0x37226957
#define PS_HULL_SHADER_DUMP_DISABLED                                   0x37226957
#define PS_HULL_SHADER_DUMP_ON                                         0x54322201
#define PS_HULL_SHADER_DUMP_ENABLED                                    0x54322201


#define PS_HULL_SHADER_DUMP_FLAGS_STRING                               "84995585"
#define PS_HULL_SHADER_DUMP_FLAGS_ID                                   0x00508ad9
#define PS_HULL_SHADER_DUMP_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS             0x00000001
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS              0x00000002
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                     0x00000004
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS             0x02000000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS              0x00000008
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_NVINST                          0x00000020
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_NVVM                            0x00000020
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE                   0x00000040
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE                   0x00000080
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST                0x00000120
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS                  0x00000200
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC                  0x00000400
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE            0x00000800
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS                0x00001000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE              0x00002000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE               0x00004000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME             0x00010000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED            0x00020000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS           0x00040000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER        0x00080000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS         0x00100000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE  0x00200000
#define PS_HULL_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME             0x00400000


#define PS_INDEX_BUFFER_STRING                                         "81222987"
#define PS_INDEX_BUFFER_ID                                             0x00b6c0d9
#define PS_INDEX_BUFFER_OVERINSTALL                                    0 // OVERRIDE
#define PS_INDEX_BUFFER_OFF                                            0x10681799
#define PS_INDEX_BUFFER_DISABLED                                       0x10681799
#define PS_INDEX_BUFFER_ON                                             0x90098363
#define PS_INDEX_BUFFER_ENABLED                                        0x90098363
#define PS_INDEX_BUFFER_DEFAULT                                        PS_INDEX_BUFFER_ON


#define PS_INDEX_BUFFER_ALLOW_STRING                                   "00960476"
#define PS_INDEX_BUFFER_ALLOW_ID                                       0x00e1e6d9
#define PS_INDEX_BUFFER_ALLOW_OVERINSTALL                              0 // OVERRIDE
#define PS_INDEX_BUFFER_ALLOW_ALLOW_HARDWARE                           0x00000001
#define PS_INDEX_BUFFER_ALLOW_ALLOW_CALLRET                            0x00000002
#define PS_INDEX_BUFFER_ALLOW_DEFAULT                                  0


#define PS_INDEX_BUFFER_STATS_FLAGS_STRING                             "41846546"
#define PS_INDEX_BUFFER_STATS_FLAGS_ID                                 0x00385794
#define PS_INDEX_BUFFER_STATS_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_INDEX_BUFFER_STATS_FLAGS_DECIDE_COUNTS                      0x00000001
#define PS_INDEX_BUFFER_STATS_FLAGS_DUMP_INDICES                       0x00000002
#define PS_INDEX_BUFFER_STATS_FLAGS_DEFAULT                            0


#define PS_INDEX_BUFFER_THRESH_STRING                                  "12746852"
#define PS_INDEX_BUFFER_THRESH_ID                                      0x00374a3f
#define PS_INDEX_BUFFER_THRESH_OVERINSTALL                             0 // OVERRIDE
#define PS_INDEX_BUFFER_THRESH_DEFAULT                                 0x40


#define PS_INPUT_BUFFERS_CB_DUMP_FILENAME_STRING                       "ac12d54g"
#define PS_INPUT_BUFFERS_CB_DUMP_FILENAME_ID                           0x00e6fd5b
#define PS_INPUT_BUFFERS_CB_DUMP_FILENAME_OVERINSTALL                  0 // OVERRIDE


#define PS_INPUT_BUFFERS_DUMP_STRING                                   "91213355"
#define PS_INPUT_BUFFERS_DUMP_ID                                       0x00174b97
#define PS_INPUT_BUFFERS_DUMP_OVERINSTALL                              0 // OVERRIDE
#define PS_INPUT_BUFFERS_DUMP_OFF                                      0x12653542
#define PS_INPUT_BUFFERS_DUMP_DISABLED                                 0x12653542
#define PS_INPUT_BUFFERS_DUMP_ON                                       0x73748260
#define PS_INPUT_BUFFERS_DUMP_ENABLED                                  0x73748260


#define PS_INPUT_BUFFERS_DUMP_FLAGS_STRING                             "95334789"
#define PS_INPUT_BUFFERS_DUMP_FLAGS_ID                                 0x00b9920d
#define PS_INPUT_BUFFERS_DUMP_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_NONE                          0x00000000
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_VERTEX_BUFFERS                0x00000001
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_INDEX_BUFFERS                 0x00000002
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_VERTEX_SHADER_CONSTANT_BUFFERS 0x00000004
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_PIXEL_SHADER_CONSTANT_BUFFERS 0x00000008
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_GEOMETRY_SHADER_CONSTANT_BUFFERS 0x00000010
#define PS_INPUT_BUFFERS_DUMP_FLAGS_DUMP_ASSOCIATED_SHADER_INFO        0x00000020


#define PS_INPUT_BUFFERS_IB_DUMP_FILENAME_STRING                       "ac12d43g"
#define PS_INPUT_BUFFERS_IB_DUMP_FILENAME_ID                           0x0071692d
#define PS_INPUT_BUFFERS_IB_DUMP_FILENAME_OVERINSTALL                  0 // OVERRIDE


#define PS_INPUT_BUFFERS_VB_DUMP_FILENAME_STRING                       "ac12d32g"
#define PS_INPUT_BUFFERS_VB_DUMP_FILENAME_ID                           0x003c3064
#define PS_INPUT_BUFFERS_VB_DUMP_FILENAME_OVERINSTALL                  0 // OVERRIDE


#define PS_KEPLER_FORCECULL_STRING                                     "008a41eb"
#define PS_KEPLER_FORCECULL_ID                                         0x0084e413
#define PS_KEPLER_FORCECULL_OVERINSTALL                                0 // OVERRIDE
#define PS_KEPLER_FORCECULL_OFF                                        0x0
#define PS_KEPLER_FORCECULL_DISABLED                                   0x0
#define PS_KEPLER_FORCECULL_ON                                         0x1
#define PS_KEPLER_FORCECULL_ENABLED                                    0x1


#define PS_KEPLER_ISSB_STRING                                          "af5f41af"
#define PS_KEPLER_ISSB_ID                                              0x00ea426a
#define PS_KEPLER_ISSB_OVERINSTALL                                     0 // OVERRIDE
#define PS_KEPLER_ISSB_OFF                                             0x0
#define PS_KEPLER_ISSB_DISABLED                                        0x0
#define PS_KEPLER_ISSB_ON                                              0x1
#define PS_KEPLER_ISSB_ENABLED                                         0x1


#define PS_KEPLER_ISSB_FLAGS_STRING                                    "af5f41b0"
#define PS_KEPLER_ISSB_FLAGS_ID                                        0x00ea426b
#define PS_KEPLER_ISSB_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_KEPLER_ISSB_FLAGS_DISABLE_VS_OPTS                           0x00000001
#define PS_KEPLER_ISSB_FLAGS_DISABLE_DS_OPTS                           0x00000010
#define PS_KEPLER_ISSB_FLAGS_DISABLE_GS_OPTS                           0x00000100
#define PS_KEPLER_ISSB_FLAGS_DISABLE_GS_DONT_FORWARD_ATTRIBUTES_VIA_STLD 0x00000200
#define PS_KEPLER_ISSB_FLAGS_DONT_BAILOUT_IF_SHADER_IS_SPILLING        0x00001000


#define PS_KEPLER_LSU_STRING                                           "53901ae6"
#define PS_KEPLER_LSU_ID                                               0x0063e380
#define PS_KEPLER_LSU_OVERINSTALL                                      0 // OVERRIDE
#define PS_KEPLER_LSU_OFF                                              0x0
#define PS_KEPLER_LSU_DISABLED                                         0x0
#define PS_KEPLER_LSU_ON                                               0x1
#define PS_KEPLER_LSU_ENABLED                                          0x1


#define PS_KEPLER_LSU_FLAGS_STRING                                     "53901ae7"
#define PS_KEPLER_LSU_FLAGS_ID                                         0x0063e381
#define PS_KEPLER_LSU_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_KEPLER_LSU_FLAGS_DONT_PACK_RGBA8_WRITES                     0x00000001
#define PS_KEPLER_LSU_FLAGS_DONT_VECTORIZE_SUST_WRITES                 0x00000010
#define PS_KEPLER_LSU_FLAGS_DONT_RESIZE_CTA                            0x00000100
#define PS_KEPLER_LSU_FLAGS_DONT_SWIZZLE_CTA                           0x00001000
#define PS_KEPLER_LSU_FLAGS_DONT_RESHAPE_SHMEM                         0x00010000
#define PS_KEPLER_LSU_FLAGS_DONT_COMPACT_SHMEM                         0x00020000
#define PS_KEPLER_LSU_FLAGS_DONT_OPTIMIZE_SMALL_BPP_FORMATS            0x00100000


#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_STRING             "0356afd1"
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_ID                 0x0036d002
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_OVERINSTALL        0 // OVERRIDE
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_DEFAULT            0x607F6080


#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_STRING              "0356afd0"
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ID                  0x0036d001
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_OVERINSTALL         0 // OVERRIDE
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_OFF                 0x00000000
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ON                  0x00000001
#define PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_DEFAULT             PS_KEPLER_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ON


#define PS_KEPLER_PUR_STRING                                           "51ab9373"
#define PS_KEPLER_PUR_ID                                               0x00135cce
#define PS_KEPLER_PUR_OVERINSTALL                                      0 // OVERRIDE
#define PS_KEPLER_PUR_OFF                                              0x0
#define PS_KEPLER_PUR_DISABLED                                         0x0
#define PS_KEPLER_PUR_ON                                               0x1
#define PS_KEPLER_PUR_ENABLED                                          0x1


#define PS_KEPLER_PUR_FLAGS_STRING                                     "51ab9374"
#define PS_KEPLER_PUR_FLAGS_ID                                         0x00135ccf
#define PS_KEPLER_PUR_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_KEPLER_PUR_FLAGS_DISABLE_BUFFER_REMAPPING                   0x00000001
#define PS_KEPLER_PUR_FLAGS_DISABLE_LOAD_BALANCED                      0x00000002
#define PS_KEPLER_PUR_FLAGS_DEFAULT                                    PS_KEPLER_PUR_FLAGS_DISABLE_LOAD_BALANCED


#define PS_KEPLER_SOO_STRING                                           "516fa442"
#define PS_KEPLER_SOO_ID                                               0x000a44f3
#define PS_KEPLER_SOO_OVERINSTALL                                      0 // OVERRIDE
#define PS_KEPLER_SOO_OFF                                              0x0
#define PS_KEPLER_SOO_DISABLED                                         0x0
#define PS_KEPLER_SOO_ON                                               0x1
#define PS_KEPLER_SOO_ENABLED                                          0x1


#define PS_KEPLER_SOO_FLAGS_STRING                                     "516fa443"
#define PS_KEPLER_SOO_FLAGS_ID                                         0x000a44f4
#define PS_KEPLER_SOO_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_KEPLER_SOO_FLAGS_DISABLE_VS_GS_MERGING                      0x00000001


#define PS_KEPLER_SW_CWD_STRING                                        "f293901e"
#define PS_KEPLER_SW_CWD_ID                                            0x00fd771f
#define PS_KEPLER_SW_CWD_OVERINSTALL                                   0 // OVERRIDE
#define PS_KEPLER_SW_CWD_OFF                                           0x0
#define PS_KEPLER_SW_CWD_DISABLED                                      0x0
#define PS_KEPLER_SW_CWD_ON                                            0x1
#define PS_KEPLER_SW_CWD_ENABLED                                       0x1


#define PS_KEPLER_SW_CWD_FLAGS_STRING                                  "f293901f"
#define PS_KEPLER_SW_CWD_FLAGS_ID                                      0x00fd7720
#define PS_KEPLER_SW_CWD_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_KEPLER_SW_CWD_FLAGS_DONT_OPT_COPY_SHADERS                   0x00000001
#define PS_KEPLER_SW_CWD_FLAGS_DONT_OPT_SHMEM_SHADERS                  0x00000002


#define PS_KEPLER_TEX_FOLDING_STRING                                   "639c7e93"
#define PS_KEPLER_TEX_FOLDING_ID                                       0x00639c80
#define PS_KEPLER_TEX_FOLDING_OVERINSTALL                              0 // OVERRIDE
#define PS_KEPLER_TEX_FOLDING_OFF                                      0x0
#define PS_KEPLER_TEX_FOLDING_DISABLED                                 0x0
#define PS_KEPLER_TEX_FOLDING_ON                                       0x1
#define PS_KEPLER_TEX_FOLDING_ENABLED                                  0x1


#define PS_KEPLER_TEX_FOLDING_FLAGS_STRING                             "639c7e94"
#define PS_KEPLER_TEX_FOLDING_FLAGS_ID                                 0x00639c81
#define PS_KEPLER_TEX_FOLDING_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_KEPLER_TEX_FOLDING_FLAGS_DISABLE_LD_1D_FOLDING              0x00000001


#define PS_KEPLER_VIEW_REMAPPER_STRING                                 "61907890"
#define PS_KEPLER_VIEW_REMAPPER_ID                                     0x00e108fe
#define PS_KEPLER_VIEW_REMAPPER_OVERINSTALL                            0 // OVERRIDE
#define PS_KEPLER_VIEW_REMAPPER_OFF                                    0x0
#define PS_KEPLER_VIEW_REMAPPER_DISABLED                               0x0
#define PS_KEPLER_VIEW_REMAPPER_ON                                     0x1
#define PS_KEPLER_VIEW_REMAPPER_ENABLED                                0x1


#define PS_KEPLER_VIEW_REMAPPER_FLAGS_STRING                           "61907891"
#define PS_KEPLER_VIEW_REMAPPER_FLAGS_ID                               0x00e108ff
#define PS_KEPLER_VIEW_REMAPPER_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_KEPLER_VIEW_REMAPPER_FLAGS_DISABLE_3D_TO_2DARRAY_DEMOTING   0x00000001


#define PS_KILL_ON_CONST_STRING                                        "0832f58a"
#define PS_KILL_ON_CONST_ID                                            0x00089b53
#define PS_KILL_ON_CONST_OVERINSTALL                                   0 // OVERRIDE
#define PS_KILL_ON_CONST_OFF                                           0x00000000
#define PS_KILL_ON_CONST_DISABLED                                      0x00000000
#define PS_KILL_ON_CONST_ON                                            0x00000001
#define PS_KILL_ON_CONST_ENABLED                                       0x00000001
#define PS_KILL_ON_CONST_DEFAULT                                       PS_KILL_ON_CONST_ON


#define PS_LOADBALANCE_STRING                                          "237914726"
#define PS_LOADBALANCE_ID                                              0x00fbb0f4
#define PS_LOADBALANCE_OVERINSTALL                                     0 // OVERRIDE
#define PS_LOADBALANCE_OFF                                             0x88551123
#define PS_LOADBALANCE_DISABLED                                        0x88551123
#define PS_LOADBALANCE_ON                                              0x37521253
#define PS_LOADBALANCE_ENABLED                                         0x37521253


#define PS_LOADBALANCE_CALLCOUNT_STEPPING_STRING                       "44739321"
#define PS_LOADBALANCE_CALLCOUNT_STEPPING_ID                           0x00fa1020
#define PS_LOADBALANCE_CALLCOUNT_STEPPING_OVERINSTALL                  0 // OVERRIDE
#define PS_LOADBALANCE_CALLCOUNT_STEPPING_DEFAULT                      100


#define PS_LOADBALANCE_DX12_STRING                                     "237914729"
#define PS_LOADBALANCE_DX12_ID                                         0x00fbb0f5
#define PS_LOADBALANCE_DX12_OVERINSTALL                                0 // OVERRIDE
#define PS_LOADBALANCE_DX12_OFF                                        0x88551123
#define PS_LOADBALANCE_DX12_DISABLED                                   0x88551123
#define PS_LOADBALANCE_DX12_ON                                         0x37521253
#define PS_LOADBALANCE_DX12_ENABLED                                    0x37521253
#define PS_LOADBALANCE_DX12_DEFAULT                                    PS_LOADBALANCE_DX12_OFF


#define PS_LOADBALANCE_DX12_FORCE_SCORE_STRING                         "0271757B"
#define PS_LOADBALANCE_DX12_FORCE_SCORE_ID                             0x00ff6a49
#define PS_LOADBALANCE_DX12_FORCE_SCORE_OVERINSTALL                    0 // OVERRIDE
#define PS_LOADBALANCE_DX12_FORCE_SCORE_DEFAULT                        0.0f


#define PS_LOADBALANCE_DX12_GPU_ACTIVE_MERGE_THRESHOLD_STRING          "02717579"
#define PS_LOADBALANCE_DX12_GPU_ACTIVE_MERGE_THRESHOLD_ID              0x00ff6a47
#define PS_LOADBALANCE_DX12_GPU_ACTIVE_MERGE_THRESHOLD_OVERINSTALL     0 // OVERRIDE
#define PS_LOADBALANCE_DX12_GPU_ACTIVE_MERGE_THRESHOLD_DEFAULT         50


#define PS_LOADBALANCE_DX12_GPU_IDLE_THRESHOLD_STRING                  "02717577"
#define PS_LOADBALANCE_DX12_GPU_IDLE_THRESHOLD_ID                      0x00ff6a45
#define PS_LOADBALANCE_DX12_GPU_IDLE_THRESHOLD_OVERINSTALL             0 // OVERRIDE
#define PS_LOADBALANCE_DX12_GPU_IDLE_THRESHOLD_DEFAULT                 0.1f


#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MAX_THRESHOLD_STRING       "0271757A"
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MAX_THRESHOLD_ID           0x00ff6a48
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MAX_THRESHOLD_OVERINSTALL  0 // OVERRIDE
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MAX_THRESHOLD_DEFAULT      0.9f


#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MIN_THRESHOLD_STRING       "02717578"
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MIN_THRESHOLD_ID           0x00ff6a46
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MIN_THRESHOLD_OVERINSTALL  0 // OVERRIDE
#define PS_LOADBALANCE_DX12_ONE_FRAME_AHEAD_MIN_THRESHOLD_DEFAULT      0.5f


#define PS_LOADBALANCE_FILTER_HEURISTIC_STRING                         "237914724"
#define PS_LOADBALANCE_FILTER_HEURISTIC_ID                             0x00fbb0f2
#define PS_LOADBALANCE_FILTER_HEURISTIC_OVERINSTALL                    0 // OVERRIDE
#define PS_LOADBALANCE_FILTER_HEURISTIC_RUNNING_AVERAGE                0x00000001
#define PS_LOADBALANCE_FILTER_HEURISTIC_BOX_FILTER_UNIFORM             0x00000002
#define PS_LOADBALANCE_FILTER_HEURISTIC_BOX_FILTER_LINEAR              0x00000003
#define PS_LOADBALANCE_FILTER_HEURISTIC_DEFAULT                        PS_LOADBALANCE_FILTER_HEURISTIC_BOX_FILTER_UNIFORM


#define PS_LOADBALANCE_FRAMETIME_AVERAGING_STRING                      "237914738"
#define PS_LOADBALANCE_FRAMETIME_AVERAGING_ID                          0x00ca17fa
#define PS_LOADBALANCE_FRAMETIME_AVERAGING_OVERINSTALL                 0 // OVERRIDE
#define PS_LOADBALANCE_FRAMETIME_AVERAGING_DEFAULT                     10


#define PS_LOADBALANCE_GPU_BUSY_THRESHOLD_STRING                       "237914739"
#define PS_LOADBALANCE_GPU_BUSY_THRESHOLD_ID                           0x00433faf
#define PS_LOADBALANCE_GPU_BUSY_THRESHOLD_OVERINSTALL                  0 // OVERRIDE
#define PS_LOADBALANCE_GPU_BUSY_THRESHOLD_DEFAULT                      0.8f


#define PS_LOADBALANCE_HOTKEY_STRING                                   "61021163"
#define PS_LOADBALANCE_HOTKEY_ID                                       0x00686457
#define PS_LOADBALANCE_HOTKEY_OVERINSTALL                              0 // OVERRIDE
#define PS_LOADBALANCE_HOTKEY_OFF                                      0xD86B7741
#define PS_LOADBALANCE_HOTKEY_DISABLED                                 0xD86B7741
#define PS_LOADBALANCE_HOTKEY_ON                                       0xBDD134C8
#define PS_LOADBALANCE_HOTKEY_ENABLED                                  0xBDD134C8
#define PS_LOADBALANCE_HOTKEY_DEFAULT                                  PS_LOADBALANCE_HOTKEY_OFF


#define PS_LOADBALANCE_IDLE_TIME_BIAS_STRING                           "447162911"
#define PS_LOADBALANCE_IDLE_TIME_BIAS_ID                               0x0027aa1a
#define PS_LOADBALANCE_IDLE_TIME_BIAS_OVERINSTALL                      0 // OVERRIDE
#define PS_LOADBALANCE_IDLE_TIME_BIAS_DEFAULT                          0.97f


#define PS_LOADBALANCE_IDLE_TIME_CUTOFF_STRING                         "237914741"
#define PS_LOADBALANCE_IDLE_TIME_CUTOFF_ID                             0x004ae9bf
#define PS_LOADBALANCE_IDLE_TIME_CUTOFF_OVERINSTALL                    0 // OVERRIDE
#define PS_LOADBALANCE_IDLE_TIME_CUTOFF_DEFAULT                        2.0f


#define PS_LOADBALANCE_IDLE_TIME_RATIO_STRING                          "237914740"
#define PS_LOADBALANCE_IDLE_TIME_RATIO_ID                              0x00fe4555
#define PS_LOADBALANCE_IDLE_TIME_RATIO_OVERINSTALL                     0 // OVERRIDE
#define PS_LOADBALANCE_IDLE_TIME_RATIO_DEFAULT                         3.0f


#define PS_LOADBALANCE_INTRA_BUFFER_SPACING_STRING                     "237914736"
#define PS_LOADBALANCE_INTRA_BUFFER_SPACING_ID                         0x008ac9fe
#define PS_LOADBALANCE_INTRA_BUFFER_SPACING_OVERINSTALL                0 // OVERRIDE
#define PS_LOADBALANCE_INTRA_BUFFER_SPACING_DEFAULT                    0x8000


#define PS_LOADBALANCE_LAG_REDUCTION_HYSTERSIS_STRING                  "07612479"
#define PS_LOADBALANCE_LAG_REDUCTION_HYSTERSIS_ID                      0x00cde764
#define PS_LOADBALANCE_LAG_REDUCTION_HYSTERSIS_OVERINSTALL             0 // OVERRIDE
#define PS_LOADBALANCE_LAG_REDUCTION_HYSTERSIS_DEFAULT                 0x4


#define PS_LOADBALANCE_LOW_LATENCY_SLEEP_FACTOR_STRING                 "02437576"
#define PS_LOADBALANCE_LOW_LATENCY_SLEEP_FACTOR_ID                     0x00fe5a44
#define PS_LOADBALANCE_LOW_LATENCY_SLEEP_FACTOR_OVERINSTALL            0 // OVERRIDE
#define PS_LOADBALANCE_LOW_LATENCY_SLEEP_FACTOR_DEFAULT                0.5f


#define PS_LOADBALANCE_MAX_MEASUREMENTS_PER_FRAME_STRING               "237914755"
#define PS_LOADBALANCE_MAX_MEASUREMENTS_PER_FRAME_ID                   0x00d6b3a8
#define PS_LOADBALANCE_MAX_MEASUREMENTS_PER_FRAME_OVERINSTALL          0 // OVERRIDE
#define PS_LOADBALANCE_MAX_MEASUREMENTS_PER_FRAME_DEFAULT              0x100


#define PS_LOADBALANCE_MODE_STRING                                     "237914728"
#define PS_LOADBALANCE_MODE_ID                                         0x008f14f5
#define PS_LOADBALANCE_MODE_OVERINSTALL                                0 // OVERRIDE
#define PS_LOADBALANCE_MODE_FORCE_CPU_LIMITED                          0x00000000
#define PS_LOADBALANCE_MODE_FORCE_ALWAYS_OFF                           0x00000000
#define PS_LOADBALANCE_MODE_FORCE_GPU_LIMITED                          0x00000001
#define PS_LOADBALANCE_MODE_FORCE_ALWAYS_ON                            0x00000001
#define PS_LOADBALANCE_MODE_FORCE_LOADBALANCE                          0x00000002
#define PS_LOADBALANCE_MODE_FORCE_LB                                   0x00000002
#define PS_LOADBALANCE_MODE_FORCE_ALTERNATE                            0x00000003
#define PS_LOADBALANCE_MODE_FORCE_ALTERNATE_EACH_DECISION              0x00000004
#define PS_LOADBALANCE_MODE_FORCE_SCORE_OSCILLATION                    0x00000006


#define PS_LOADBALANCE_ONE_FRAME_AHEAD_THRESHOLD_STRING                "02717576"
#define PS_LOADBALANCE_ONE_FRAME_AHEAD_THRESHOLD_ID                    0x00ff6a44
#define PS_LOADBALANCE_ONE_FRAME_AHEAD_THRESHOLD_OVERINSTALL           0 // OVERRIDE
#define PS_LOADBALANCE_ONE_FRAME_AHEAD_THRESHOLD_DEFAULT               0.5f


#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_STRING        "661234721"
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_ID            0x00a7cb55
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_OVERINSTALL   0 // OVERRIDE
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_RUNNING_AVERAGE 0x00000001
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_BOX_FILTER_UNIFORM 0x00000002
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_BOX_FILTER_LINEAR 0x00000003
#define PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_DEFAULT       PS_LOADBALANCE_PERF_STRAT_TIMER_FILTER_HEURISTIC_BOX_FILTER_LINEAR


#define PS_LOADBALANCE_PERF_STRAT_TIMER_SAMPLES_STRING                 "122767119"
#define PS_LOADBALANCE_PERF_STRAT_TIMER_SAMPLES_ID                     0x00daf9cc
#define PS_LOADBALANCE_PERF_STRAT_TIMER_SAMPLES_OVERINSTALL            0 // OVERRIDE
#define PS_LOADBALANCE_PERF_STRAT_TIMER_SAMPLES_DEFAULT                16


#define PS_LOADBALANCE_QUEUED_FRAME_THRESHOLD_STRING                   "237914742"
#define PS_LOADBALANCE_QUEUED_FRAME_THRESHOLD_ID                       0x00375e2a
#define PS_LOADBALANCE_QUEUED_FRAME_THRESHOLD_OVERINSTALL              0 // OVERRIDE
#define PS_LOADBALANCE_QUEUED_FRAME_THRESHOLD_DEFAULT                  0.2f


#define PS_LOADBALANCE_QUEUED_WORK_CUTOFF_STRING                       "66274905"
#define PS_LOADBALANCE_QUEUED_WORK_CUTOFF_ID                           0x00aff441
#define PS_LOADBALANCE_QUEUED_WORK_CUTOFF_OVERINSTALL                  0 // OVERRIDE
#define PS_LOADBALANCE_QUEUED_WORK_CUTOFF_DEFAULT                      1.0f


#define PS_LOADBALANCE_REVERSE_MODE_RATIO_STRING                       "237914743"
#define PS_LOADBALANCE_REVERSE_MODE_RATIO_ID                           0x00f55a13
#define PS_LOADBALANCE_REVERSE_MODE_RATIO_OVERINSTALL                  0 // OVERRIDE
#define PS_LOADBALANCE_REVERSE_MODE_RATIO_DEFAULT                      4.0f


#define PS_LOADBALANCE_STATS_LOG_SIZE_STRING                           "237914737"
#define PS_LOADBALANCE_STATS_LOG_SIZE_ID                               0x008ac9fc
#define PS_LOADBALANCE_STATS_LOG_SIZE_OVERINSTALL                      0 // OVERRIDE
#define PS_LOADBALANCE_STATS_LOG_SIZE_DEFAULT                          0


#define PS_LOADBALANCE_TIMEOUT_STRING                                  "237914727"
#define PS_LOADBALANCE_TIMEOUT_ID                                      0x00d6b3a9
#define PS_LOADBALANCE_TIMEOUT_OVERINSTALL                             0 // OVERRIDE


#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_STRING                  "237914725"
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_ID                      0x00fbb0f3
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_OVERINSTALL             0 // OVERRIDE
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_OFF                     0
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_DISABLED                0
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_ON                      1
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_ENABLED                 1
#define PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_DEFAULT                 PS_LOADBALANCE_USE_INTRA_BUFFER_TIMING_ON


#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_STRING                     "777635221"
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_ID                         0x00acc103
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_OVERINSTALL                0 // OVERRIDE
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_OFF                        0
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_DISABLED                   0
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_ON                         1
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_ENABLED                    1
#define PS_LOADBALANCE_USE_PERF_STRAT_TIMER_DEFAULT                    PS_LOADBALANCE_USE_PERF_STRAT_TIMER_ON


#define PS_LOAD_TO_CONST_STRING                                        "2622eaf9"
#define PS_LOAD_TO_CONST_ID                                            0x00faff17
#define PS_LOAD_TO_CONST_OVERINSTALL                                   0 // OVERRIDE
#define PS_LOAD_TO_CONST_OFF                                           0x00000000
#define PS_LOAD_TO_CONST_DISABLED                                      0x00000000
#define PS_LOAD_TO_CONST_ON                                            0x00000001
#define PS_LOAD_TO_CONST_ENABLED                                       0x00000001


#define PS_LOAD_TO_CONST_FLAGS_STRING                                  "239efcf2"
#define PS_LOAD_TO_CONST_FLAGS_ID                                      0x00feef19
#define PS_LOAD_TO_CONST_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_LOAD_TO_CONST_FLAGS_DISABLE_PROFILES                        0x00000001


#define PS_LOAD_TO_CONST_SHADER_HASH_STRING                            "488abc22"
#define PS_LOAD_TO_CONST_SHADER_HASH_ID                                0x00def112
#define PS_LOAD_TO_CONST_SHADER_HASH_OVERINSTALL                       0 // OVERRIDE


#define PS_LOAD_TO_CONST_SHADER_SLOT_STRING                            "55ac7d32"
#define PS_LOAD_TO_CONST_SHADER_SLOT_ID                                0x003a331b
#define PS_LOAD_TO_CONST_SHADER_SLOT_OVERINSTALL                       0 // OVERRIDE


#define PS_LWBM_STATS_FLAGS_STRING                                     "1f075814"
#define PS_LWBM_STATS_FLAGS_ID                                         0x00eaa150
#define PS_LWBM_STATS_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_LWBM_STATS_FLAGS_TIMING_DATA                                0x00000001
#define PS_LWBM_STATS_FLAGS_DEFAULT                                    0


#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_STRING            "0356afd2"
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_ID                0x0036d003
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_OVERINSTALL       0 // OVERRIDE
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_DEFAULT_DEFAULT           0x20806080


#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_STRING             "0356afd3"
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ID                 0x0036d004
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_OVERINSTALL        0 // OVERRIDE
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_OFF                0x00000000
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ON                 0x00000001
#define PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_DEFAULT            PS_MAXWELL_MRT_SUBTILING_PERF_KNOB_A_ENABLE_ON


#define PS_MAXWELL_SULD_TO_TLD_STRING                                  "41807"
#define PS_MAXWELL_SULD_TO_TLD_ID                                      0x00f0f67a
#define PS_MAXWELL_SULD_TO_TLD_OVERINSTALL                             0 // OVERRIDE
#define PS_MAXWELL_SULD_TO_TLD_OFF                                     0x00000000
#define PS_MAXWELL_SULD_TO_TLD_DISABLED                                0x00000000
#define PS_MAXWELL_SULD_TO_TLD_ON                                      0x00000001
#define PS_MAXWELL_SULD_TO_TLD_ENABLED                                 0x00000001
#define PS_MAXWELL_SULD_TO_TLD_DEFAULT                                 PS_MAXWELL_SULD_TO_TLD_ON


#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR0_STRING                      "0xce2346"
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR0_ID                          0x00ce2236
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR0_OVERINSTALL                 0 // OVERRIDE
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR0_DEFAULT                     0x0


#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR1_STRING                      "0xce2347"
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR1_ID                          0x00ce2237
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR1_OVERINSTALL                 0 // OVERRIDE
#define PS_MAXWELL_TILEDCACHE_BUNDLE_ADDR1_DEFAULT                     0x0


#define PS_MAXWELL_TILEDCACHE_BUNDLE_CTRL0_STRING                      "0xce2467"
#define PS_MAXWELL_TILEDCACHE_BUNDLE_CTRL0_ID                          0x00ce2467
#define PS_MAXWELL_TILEDCACHE_BUNDLE_CTRL0_OVERINSTALL                 0 // OVERRIDE
#define PS_MAXWELL_TILEDCACHE_BUNDLE_CTRL0_DEFAULT                     0x0


#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_STRING                  "0xce2447"
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_ID                      0x00ce2447
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_OVERINSTALL             0 // OVERRIDE
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_CB_MIN_THRESHOLD_MASK   0x000000FF
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_CB_HIGH_THRESHOLD_MASK  0x0000FF00
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_CB_MAX_THRESHOLD_MASK   0xFFFF0000
#define PS_MAXWELL_TILEDCACHE_CBBIND_THRESHOLD_DEFAULT                 0x10002110


#define PS_MAXWELL_TILEDCACHE_FLAGS_STRING                             "0xce2446"
#define PS_MAXWELL_TILEDCACHE_FLAGS_ID                                 0x00ce2446
#define PS_MAXWELL_TILEDCACHE_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_SKIP_FLUSH_REDUNDANT_BINDS 0x00000001
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_OFF_Z_ONLY_BIND            0x00000002
#define PS_MAXWELL_TILEDCACHE_FLAGS_FLUSH_ON_AA_RESOLVE                0x00000004
#define PS_MAXWELL_TILEDCACHE_FLAGS_FORCE_CAN_BIN_ACROSS_RT_BINDS      0x00000008
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_BINNING_CLEARS             0x00000010
#define PS_MAXWELL_TILEDCACHE_FLAGS_FORCE_WFI_AFTER_CLEARS             0x00000020
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_HEAVYWEIGHT_BUNDLE_BINNABLE_OVERRIDE 0x00000040
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_PER_SEGMENT_GPFIFO         0x00000080
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_WITH_TESSELLATION_SHD      0x00000100
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_WITH_GEOMETRY_SHD          0x00000200
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_WITH_PSI_SHD               0x00000400
#define PS_MAXWELL_TILEDCACHE_FLAGS_DISABLE_STEAM_VR_SMALL_PRIM_HWBUG_WAR 0x00010000
#define PS_MAXWELL_TILEDCACHE_FLAGS_FLIP_TILE_XY_DIMENSIONS            0x00020000
#define PS_MAXWELL_TILEDCACHE_FLAGS_INCLUDE_RT_ARRAY_SLICES_IN_BPP     0x00040000
#define PS_MAXWELL_TILEDCACHE_FLAGS_BIN_BLENDING_ONLY                  0x00080000
#define PS_MAXWELL_TILEDCACHE_FLAGS_USE_MAX_TILESIZE_TO_DISABLE_BINNING 0x00100000
#define PS_MAXWELL_TILEDCACHE_FLAGS_DEFAULT                            0x00000584


#define PS_MEMORYSTATS_STRING                                          "23167345"
#define PS_MEMORYSTATS_ID                                              0x003d2713
#define PS_MEMORYSTATS_OVERINSTALL                                     0 // OVERRIDE
#define PS_MEMORYSTATS_OFF                                             0x00000000
#define PS_MEMORYSTATS_DISABLED                                        0x00000000
#define PS_MEMORYSTATS_ON                                              0x00000001
#define PS_MEMORYSTATS_ENABLED                                         0x00000001


#define PS_MEMORYSTATS_FRAME_INTERVAL_STRING                           "25643546"
#define PS_MEMORYSTATS_FRAME_INTERVAL_ID                               0x00094c48
#define PS_MEMORYSTATS_FRAME_INTERVAL_OVERINSTALL                      0 // OVERRIDE
#define PS_MEMORYSTATS_FRAME_INTERVAL_MIN                              0x00
#define PS_MEMORYSTATS_FRAME_INTERVAL_MAX                              0x7fffffff


#define PS_MEMORY_OPT_FRAME_LAGGING_THRESHOLD_STRING                   "02532311"
#define PS_MEMORY_OPT_FRAME_LAGGING_THRESHOLD_ID                       0x005ad0ff
#define PS_MEMORY_OPT_FRAME_LAGGING_THRESHOLD_OVERINSTALL              0 // OVERRIDE
#define PS_MEMORY_OPT_FRAME_LAGGING_THRESHOLD_DEFAULT                  10


#define PS_MEMORY_OPT_INITIAL_FRAME_COUNT_LOW_FOOTPRINT_STRING         "02532310"
#define PS_MEMORY_OPT_INITIAL_FRAME_COUNT_LOW_FOOTPRINT_ID             0x005ad0fe
#define PS_MEMORY_OPT_INITIAL_FRAME_COUNT_LOW_FOOTPRINT_OVERINSTALL    0 // OVERRIDE
#define PS_MEMORY_OPT_INITIAL_FRAME_COUNT_LOW_FOOTPRINT_DEFAULT        15


#define PS_METHOD_CHECK_STRING                                         "23710720"
#define PS_METHOD_CHECK_ID                                             0x00181e12
#define PS_METHOD_CHECK_OVERINSTALL                                    0 // OVERRIDE
#define PS_METHOD_CHECK_OFF                                            0x91523313
#define PS_METHOD_CHECK_DISABLED                                       0x91523313
#define PS_METHOD_CHECK_ON                                             0x73317235
#define PS_METHOD_CHECK_ENABLED                                        0x73317235


#define PS_METHOD_CHECK_HOTKEY_STRING                                  "32467728"
#define PS_METHOD_CHECK_HOTKEY_ID                                      0x0082b2e6
#define PS_METHOD_CHECK_HOTKEY_OVERINSTALL                             0 // OVERRIDE
#define PS_METHOD_CHECK_HOTKEY_DEFAULT                                 0xA0


#define PS_METHOD_CHECK_THRESHOLD_STRING                               "12953327"
#define PS_METHOD_CHECK_THRESHOLD_ID                                   0x008fa08c
#define PS_METHOD_CHECK_THRESHOLD_OVERINSTALL                          0 // OVERRIDE
#define PS_METHOD_CHECK_THRESHOLD_DEFAULT                              20


#define PS_MINIMIZE_SHADER_ATTRIBUTES_STRING                           "ad4548cd"
#define PS_MINIMIZE_SHADER_ATTRIBUTES_ID                               0x00bdad4d
#define PS_MINIMIZE_SHADER_ATTRIBUTES_OVERINSTALL                      0 // OVERRIDE
#define PS_MINIMIZE_SHADER_ATTRIBUTES_OFF                              0x00000000
#define PS_MINIMIZE_SHADER_ATTRIBUTES_DISABLED                         0x00000000
#define PS_MINIMIZE_SHADER_ATTRIBUTES_ON                               0x00000001
#define PS_MINIMIZE_SHADER_ATTRIBUTES_ENABLED                          0x00000001
#define PS_MINIMIZE_SHADER_ATTRIBUTES_DEFAULT                          PS_MINIMIZE_SHADER_ATTRIBUTES_ON


#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_STRING                     "12afd1a9"
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_ID                         0x0032147a
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_OVERINSTALL                0 // OVERRIDE
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_DISABLE_PIXEL              0x00000001
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_DISABLE_VTG                0x00000002
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_DISABLE_NULL_COLOR_TARGET  0x00000004
#define PS_MINIMIZE_SHADER_ATTRIBUTES_FLAGS_DEFAULT                    0x0


#define PS_MINIMIZE_TEX_STRING                                         "14436288"
#define PS_MINIMIZE_TEX_ID                                             0x0011f001
#define PS_MINIMIZE_TEX_OVERINSTALL                                    0 // OVERRIDE
#define PS_MINIMIZE_TEX_OFF                                            0x00000000
#define PS_MINIMIZE_TEX_DISABLED                                       0x00000000
#define PS_MINIMIZE_TEX_ON                                             0x00000001
#define PS_MINIMIZE_TEX_ENABLED                                        0x00000001
#define PS_MINIMIZE_TEX_DEFAULT                                        PS_MINIMIZE_TEX_ON


#define PS_MINIMIZE_TEX_FLAGS_STRING                                   "14436289"
#define PS_MINIMIZE_TEX_FLAGS_ID                                       0x0011f002
#define PS_MINIMIZE_TEX_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_MINIMIZE_TEX_FLAGS_DISABLE_RGBA8_TO_R8                      0x00000001
#define PS_MINIMIZE_TEX_FLAGS_DEFAULT                                  0


#define PS_MISC_INSOMNIA_STRING                                        "e7ab193d"
#define PS_MISC_INSOMNIA_ID                                            0x00b46836
#define PS_MISC_INSOMNIA_OVERINSTALL                                   0 // OVERRIDE
#define PS_MISC_INSOMNIA_OFF                                           0x00000000
#define PS_MISC_INSOMNIA_0                                             0x00000000
#define PS_MISC_INSOMNIA_FALSE                                         0x00000000
#define PS_MISC_INSOMNIA_DISABLED                                      0x00000000
#define PS_MISC_INSOMNIA_ON                                            0x00000001
#define PS_MISC_INSOMNIA_1                                             0x00000001
#define PS_MISC_INSOMNIA_TRUE                                          0x00000001
#define PS_MISC_INSOMNIA_ENABLED                                       0x00000001


#define PS_MSAA_DEPTH_PASS_STRING                                      "34554AFF"
#define PS_MSAA_DEPTH_PASS_ID                                          0x00554464
#define PS_MSAA_DEPTH_PASS_OVERINSTALL                                 0 // OVERRIDE
#define PS_MSAA_DEPTH_PASS_OFF                                         0x00000000
#define PS_MSAA_DEPTH_PASS_DISABLED                                    0x00000000
#define PS_MSAA_DEPTH_PASS_ON                                          0x00000001
#define PS_MSAA_DEPTH_PASS_ENABLED                                     0x00000001
#define PS_MSAA_DEPTH_PASS_DEFAULT                                     0x1


#define PS_MSAA_DEPTH_PASS_ALTERNATE_STRING                            "890714FA"
#define PS_MSAA_DEPTH_PASS_ALTERNATE_ID                                0x005134f4
#define PS_MSAA_DEPTH_PASS_ALTERNATE_OVERINSTALL                       0 // OVERRIDE
#define PS_MSAA_DEPTH_PASS_ALTERNATE_OFF                               0x00000000
#define PS_MSAA_DEPTH_PASS_ALTERNATE_DISABLED                          0x00000000
#define PS_MSAA_DEPTH_PASS_ALTERNATE_ON                                0x00000001
#define PS_MSAA_DEPTH_PASS_ALTERNATE_ENABLED                           0x00000001
#define PS_MSAA_DEPTH_PASS_ALTERNATE_DEFAULT                           0x0


#define PS_MSAA_DEPTH_PASS_APP_DETECT_STRING                           "3A4864FE"
#define PS_MSAA_DEPTH_PASS_APP_DETECT_ID                               0x00654186
#define PS_MSAA_DEPTH_PASS_APP_DETECT_OVERINSTALL                      0 // OVERRIDE
#define PS_MSAA_DEPTH_PASS_APP_DETECT_OFF                              0x00000000
#define PS_MSAA_DEPTH_PASS_APP_DETECT_DISABLED                         0x00000000
#define PS_MSAA_DEPTH_PASS_APP_DETECT_ON                               0x00000001
#define PS_MSAA_DEPTH_PASS_APP_DETECT_ENABLED                          0x00000001
#define PS_MSAA_DEPTH_PASS_APP_DETECT_DEFAULT                          0x1


#define PS_MSAA_DEPTH_PASS_MAX_INST_COUNT_STRING                       "12082908"
#define PS_MSAA_DEPTH_PASS_MAX_INST_COUNT_ID                           0x00f93fc2
#define PS_MSAA_DEPTH_PASS_MAX_INST_COUNT_OVERINSTALL                  0 // OVERRIDE
#define PS_MSAA_DEPTH_PASS_MAX_INST_COUNT_SM_CLASSIC_MAX_INST_COUNT_DEFAULT 0x10
#define PS_MSAA_DEPTH_PASS_MAX_INST_COUNT_SM_QUICK_MAX_INST_COUNT_DEFAULT 0x10


#define PS_MSAA_DEPTH_PASS_SM_CHECK_STRING                             "FF09783F"
#define PS_MSAA_DEPTH_PASS_SM_CHECK_ID                                 0x001254ff
#define PS_MSAA_DEPTH_PASS_SM_CHECK_OVERINSTALL                        0 // OVERRIDE
#define PS_MSAA_DEPTH_PASS_SM_CHECK_OFF                                0x00000000
#define PS_MSAA_DEPTH_PASS_SM_CHECK_DISABLED                           0x00000000
#define PS_MSAA_DEPTH_PASS_SM_CHECK_ON                                 0x00000001
#define PS_MSAA_DEPTH_PASS_SM_CHECK_ENABLED                            0x00000001
#define PS_MSAA_DEPTH_PASS_SM_CHECK_DEFAULT                            0x1


#define PS_MULTICHIP_STRING                                            "63859943"
#define PS_MULTICHIP_ID                                                0x00e4f4fa
#define PS_MULTICHIP_OVERINSTALL                                       0 // OVERRIDE
#define PS_MULTICHIP_OFF                                               0x52aebf3d
#define PS_MULTICHIP_DISABLED                                          0x52aebf3d
#define PS_MULTICHIP_ON                                                0xde8f1a66
#define PS_MULTICHIP_ENABLED                                           0xde8f1a66


#define PS_MULTICHIP_BREAKPOINT0_STRING                                "28651425"
#define PS_MULTICHIP_BREAKPOINT0_ID                                    0x008129d7
#define PS_MULTICHIP_BREAKPOINT0_OVERINSTALL                           0 // OVERRIDE
#define PS_MULTICHIP_BREAKPOINT0_TEXTURE                               0x00000000
#define PS_MULTICHIP_BREAKPOINT0_TEXTURE_PUSH                          0x00000001
#define PS_MULTICHIP_BREAKPOINT0_FRAMEBUFFER                           0x00000002
#define PS_MULTICHIP_BREAKPOINT0_VERTEXBUFFER                          0x00000003
#define PS_MULTICHIP_BREAKPOINT0_INDEXBUFFER                           0x00000004
#define PS_MULTICHIP_BREAKPOINT0_RENDERTARGET                          0x00000005
#define PS_MULTICHIP_BREAKPOINT0_VIEWPORT                              0x00000006
#define PS_MULTICHIP_BREAKPOINT0_ZBUFFER                               0x00000007
#define PS_MULTICHIP_BREAKPOINT0_TWODSURFACE                           0x00000008
#define PS_MULTICHIP_BREAKPOINT0_PUSHFORAFR                            0x00000009
#define PS_MULTICHIP_BREAKPOINT0_OTHER                                 0x0000000a


#define PS_MULTICHIP_BREAKPOINT1_STRING                                "28651426"
#define PS_MULTICHIP_BREAKPOINT1_ID                                    0x00772796
#define PS_MULTICHIP_BREAKPOINT1_OVERINSTALL                           0 // OVERRIDE
#define PS_MULTICHIP_BREAKPOINT1_TEXTURE                               0x00000000
#define PS_MULTICHIP_BREAKPOINT1_TEXTURE_PUSH                          0x00000001
#define PS_MULTICHIP_BREAKPOINT1_FRAMEBUFFER                           0x00000002
#define PS_MULTICHIP_BREAKPOINT1_VERTEXBUFFER                          0x00000003
#define PS_MULTICHIP_BREAKPOINT1_INDEXBUFFER                           0x00000004
#define PS_MULTICHIP_BREAKPOINT1_RENDERTARGET                          0x00000005
#define PS_MULTICHIP_BREAKPOINT1_VIEWPORT                              0x00000006
#define PS_MULTICHIP_BREAKPOINT1_ZBUFFER                               0x00000007
#define PS_MULTICHIP_BREAKPOINT1_TWODSURFACE                           0x00000008
#define PS_MULTICHIP_BREAKPOINT1_PUSHFORAFR                            0x00000009
#define PS_MULTICHIP_BREAKPOINT1_OTHER                                 0x0000000a


#define PS_MULTICHIP_STATS_STRING                                      "09021549"
#define PS_MULTICHIP_STATS_ID                                          0x006a43d2
#define PS_MULTICHIP_STATS_OVERINSTALL                                 0 // OVERRIDE
#define PS_MULTICHIP_STATS_OFF                                         0x00000000
#define PS_MULTICHIP_STATS_DISABLED                                    0x00000000
#define PS_MULTICHIP_STATS_ON                                          0x00000001
#define PS_MULTICHIP_STATS_ENABLED                                     0x00000001


#define PS_MULTIPASS_FFT_STRING                                        "ff70ff"
#define PS_MULTIPASS_FFT_ID                                            0x00ff70ff
#define PS_MULTIPASS_FFT_OVERINSTALL                                   0 // OVERRIDE
#define PS_MULTIPASS_FFT_OFF                                           0x00000000
#define PS_MULTIPASS_FFT_DISABLED                                      0x00000000
#define PS_MULTIPASS_FFT_ON                                            0x00000001
#define PS_MULTIPASS_FFT_ENABLED                                       0x00000001
#define PS_MULTIPASS_FFT_DEFAULT                                       PS_MULTIPASS_FFT_ON


#define PS_MULTIPASS_FFT_FLAGS_STRING                                  "DECAF0"
#define PS_MULTIPASS_FFT_FLAGS_ID                                      0x001e0fac
#define PS_MULTIPASS_FFT_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define PS_MULTIPASS_FFT_FLAGS_DUMP_STATS                              0x00000001
#define PS_MULTIPASS_FFT_FLAGS_DUMP_INFO                               0x00000002
#define PS_MULTIPASS_FFT_FLAGS_DUMP_LOOKASIDE_CBS                      0x00000004
#define PS_MULTIPASS_FFT_FLAGS_DUMP_TRANSIENT_CBS                      0x00000008
#define PS_MULTIPASS_FFT_FLAGS_DEFAULT                                 0x00000000


#define PS_MULTIPASS_FFT_MAX_COALESCED_GRIDS_STRING                    "FAL0FF"
#define PS_MULTIPASS_FFT_MAX_COALESCED_GRIDS_ID                        0x000000fa
#define PS_MULTIPASS_FFT_MAX_COALESCED_GRIDS_OVERINSTALL               0 // OVERRIDE
#define PS_MULTIPASS_FFT_MAX_COALESCED_GRIDS_DEFAULT                   10


#define PS_OCCLUDE_BEFORE_FETCH_STRING                                 "ab874912"
#define PS_OCCLUDE_BEFORE_FETCH_ID                                     0x00ad6749
#define PS_OCCLUDE_BEFORE_FETCH_OVERINSTALL                            0 // OVERRIDE
#define PS_OCCLUDE_BEFORE_FETCH_OFF                                    0x00000000
#define PS_OCCLUDE_BEFORE_FETCH_DISABLED                               0x00000000
#define PS_OCCLUDE_BEFORE_FETCH_ON                                     0x00000001
#define PS_OCCLUDE_BEFORE_FETCH_ENABLED                                0x00000001
#define PS_OCCLUDE_BEFORE_FETCH_DEFAULT                                PS_OCCLUDE_BEFORE_FETCH_OFF


#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_STRING                           "ab874913"
#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_ID                               0x00ad674a
#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_MRT_ONLY                         0x00000001
#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_REMOVE_GENERICS_IN_PS_IMAP       0x00000002
#define PS_OCCLUDE_BEFORE_FETCH_FLAGS_DEFAULT                          0x0


#define PS_ODEPTH_TO_COLOR_STRING                                      "445a7415"
#define PS_ODEPTH_TO_COLOR_ID                                          0x00f62a79
#define PS_ODEPTH_TO_COLOR_OVERINSTALL                                 0 // OVERRIDE
#define PS_ODEPTH_TO_COLOR_OFF                                         0x00000000
#define PS_ODEPTH_TO_COLOR_DISABLED                                    0x00000000
#define PS_ODEPTH_TO_COLOR_ON                                          0x00000001
#define PS_ODEPTH_TO_COLOR_ENABLED                                     0x00000001
#define PS_ODEPTH_TO_COLOR_DEFAULT                                     PS_ODEPTH_TO_COLOR_ON


#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_STRING                        "C06FE"
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_ID                            0x000c06fe
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_OVERINSTALL                   0 // OVERRIDE
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_DEFAULT                       0x00000000
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_NO_DEFERRAL                   0x00000001
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_SKIP_WAIT_ON_CLEAR            0x00000002
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_DISABLE_OCCLUSION_BINNING     0x00000004
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_DISABLE_PREDICATE_BINNING     0x00000008
#define PS_PASCAL_BINNED_OCC_QUERY_FLAGS_DISABLE_PREDICATE_HINT_BINNING 0x00000010


#define PS_PASCAL_BINNED_OCC_QUERY_SCRATCH_METHODS_COUNT_STRING        "C06FD"
#define PS_PASCAL_BINNED_OCC_QUERY_SCRATCH_METHODS_COUNT_ID            0x000c06fd
#define PS_PASCAL_BINNED_OCC_QUERY_SCRATCH_METHODS_COUNT_OVERINSTALL   0 // OVERRIDE
#define PS_PASCAL_BINNED_OCC_QUERY_SCRATCH_METHODS_COUNT_DEFAULT       0x2000


#define PS_PATCH_SHADOWMAP_UNIQUENESS_STRING                           "73025139"
#define PS_PATCH_SHADOWMAP_UNIQUENESS_ID                               0x0026f375
#define PS_PATCH_SHADOWMAP_UNIQUENESS_OVERINSTALL                      0 // OVERRIDE
#define PS_PATCH_SHADOWMAP_UNIQUENESS_OFF                              0x00000000
#define PS_PATCH_SHADOWMAP_UNIQUENESS_DISABLED                         0x00000000
#define PS_PATCH_SHADOWMAP_UNIQUENESS_ON                               0x00000001
#define PS_PATCH_SHADOWMAP_UNIQUENESS_ENABLED                          0x00000001
#define PS_PATCH_SHADOWMAP_UNIQUENESS_DEFAULT                          PS_PATCH_SHADOWMAP_UNIQUENESS_ON


#define PS_PERFBOOST_STRING                                            "52438210"
#define PS_PERFBOOST_ID                                                0x006de2c6
#define PS_PERFBOOST_OVERINSTALL                                       0 // OVERRIDE
#define PS_PERFBOOST_OFF                                               0x00000000
#define PS_PERFBOOST_DISABLED                                          0x00000000
#define PS_PERFBOOST_ON                                                0x00000001
#define PS_PERFBOOST_ENABLED                                           0x00000001
#define PS_PERFBOOST_DEFAULT                                           PS_PERFBOOST_ON


#define PS_PERFBOOST_CPU_BOUND_FRAMES_STRING                           "52438214"
#define PS_PERFBOOST_CPU_BOUND_FRAMES_ID                               0x00dece25
#define PS_PERFBOOST_CPU_BOUND_FRAMES_OVERINSTALL                      0 // OVERRIDE
#define PS_PERFBOOST_CPU_BOUND_FRAMES_DEFAULT                          4


#define PS_PERFBOOST_GPU_BOUND_FRAMES_STRING                           "52438213"
#define PS_PERFBOOST_GPU_BOUND_FRAMES_ID                               0x00b345f3
#define PS_PERFBOOST_GPU_BOUND_FRAMES_OVERINSTALL                      0 // OVERRIDE
#define PS_PERFBOOST_GPU_BOUND_FRAMES_DEFAULT                          2


#define PS_PERFBOOST_INTERVAL_STRING                                   "52438212"
#define PS_PERFBOOST_INTERVAL_ID                                       0x0087194d
#define PS_PERFBOOST_INTERVAL_OVERINSTALL                              0 // OVERRIDE
#define PS_PERFBOOST_INTERVAL_DEFAULT                                  5


#define PS_PERFBOOST_TIME_STRING                                       "52438211"
#define PS_PERFBOOST_TIME_ID                                           0x0071875f
#define PS_PERFBOOST_TIME_OVERINSTALL                                  0 // OVERRIDE
#define PS_PERFBOOST_TIME_DEFAULT                                      2


#define PS_PGO_PIECEMEAL_PROFILER_FILENAME_STRING                      "00752a75"
#define PS_PGO_PIECEMEAL_PROFILER_FILENAME_ID                          0x000da72a
#define PS_PGO_PIECEMEAL_PROFILER_FILENAME_OVERINSTALL                 0 // OVERRIDE


#define PS_PGO_PIECEMEAL_PROFILER_FILEPATH_STRING                      "02752a85"
#define PS_PGO_PIECEMEAL_PROFILER_FILEPATH_ID                          0x000ca82b
#define PS_PGO_PIECEMEAL_PROFILER_FILEPATH_OVERINSTALL                 0 // OVERRIDE


#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_STRING                     "00752b74"
#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_ID                         0x0049de44
#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_OVERINSTALL                0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_MIN                        16384
#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_MAX                        16777216
#define PS_PGO_PIECEMEAL_PROFILER_FILE_SIZE_DEFAULT                    0x100


#define PS_PIXEL_SHADER_STRING                                         "71327987"
#define PS_PIXEL_SHADER_ID                                             0x00d89617
#define PS_PIXEL_SHADER_OVERINSTALL                                    0 // OVERRIDE
#define PS_PIXEL_SHADER_OFF                                            0x29962001
#define PS_PIXEL_SHADER_DISABLED                                       0x29962001
#define PS_PIXEL_SHADER_ON                                             0x85639845
#define PS_PIXEL_SHADER_ENABLED                                        0x85639845
#define PS_PIXEL_SHADER_DEFAULT                                        PS_PIXEL_SHADER_ON


#define PS_PIXEL_SHADER_ALLOW_STRING                                   "30176303"
#define PS_PIXEL_SHADER_ALLOW_ID                                       0x0079c5e6
#define PS_PIXEL_SHADER_ALLOW_OVERINSTALL                              0 // OVERRIDE
#define PS_PIXEL_SHADER_ALLOW_ALLOW_STATIC_HAND_TUNED_TSS              0x00000001
#define PS_PIXEL_SHADER_ALLOW_ALLOW_STATIC_HAND_TUNED_REAL             0x00000002
#define PS_PIXEL_SHADER_ALLOW_ALLOW_DYNAMIC_HAND_TUNED_TSS             0x00000004
#define PS_PIXEL_SHADER_ALLOW_ALLOW_DYNAMIC_HAND_TUNED_REAL            0x00000008
#define PS_PIXEL_SHADER_ALLOW_WHITE_TUNEDNESS_STATIC_HANDTUNED         0x00000010
#define PS_PIXEL_SHADER_ALLOW_WHITE_TUNEDNESS_DYNAMIC_HANDTUNED        0x00000020
#define PS_PIXEL_SHADER_ALLOW_WHITE_TUNEDNESS_NON_HANDTUNED            0x00000040
#define PS_PIXEL_SHADER_ALLOW_WHITE_TYPE_TSS                           0x00000100
#define PS_PIXEL_SHADER_ALLOW_WHITE_TYPE_PS1X                          0x00000200
#define PS_PIXEL_SHADER_ALLOW_WHITE_TYPE_PS20                          0x00000400
#define PS_PIXEL_SHADER_ALLOW_WHITE_TYPE_PS30                          0x00000800
#define PS_PIXEL_SHADER_ALLOW_ALLOW_QIF_OPT                            0x00001000
#define PS_PIXEL_SHADER_ALLOW_DEFAULT                                  0x00000003


#define PS_PIXEL_SHADER_BREAKHASH_STRING                               "83564689"
#define PS_PIXEL_SHADER_BREAKHASH_ID                                   0x003601c8
#define PS_PIXEL_SHADER_BREAKHASH_OVERINSTALL                          0 // OVERRIDE
#define PS_PIXEL_SHADER_BREAKHASH_DEFAULT                              0


#define PS_PIXEL_SHADER_DUMP_STRING                                    "91214835"
#define PS_PIXEL_SHADER_DUMP_ID                                        0x00552ba6
#define PS_PIXEL_SHADER_DUMP_OVERINSTALL                               0 // OVERRIDE
#define PS_PIXEL_SHADER_DUMP_OFF                                       0x12542653
#define PS_PIXEL_SHADER_DUMP_DISABLED                                  0x12542653
#define PS_PIXEL_SHADER_DUMP_ON                                        0x78260374
#define PS_PIXEL_SHADER_DUMP_ENABLED                                   0x78260374


#define PS_PIXEL_SHADER_DUMP_FLAGS_STRING                              "95394027"
#define PS_PIXEL_SHADER_DUMP_FLAGS_ID                                  0x00c52d2c
#define PS_PIXEL_SHADER_DUMP_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS            0x00000001
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS             0x00000002
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                    0x00000004
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_CUBEMAP_SHADERS                0x01000000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS            0x02000000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS             0x00000008
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_NVINST                         0x00000020
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_NVVM                           0x00000020
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE                  0x00000040
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE                  0x00000080
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST               0x00000120
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS                 0x00000200
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC                 0x00000400
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE           0x00000800
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS               0x00001000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE             0x00002000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE              0x00004000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME            0x00010000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED           0x00020000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS          0x00040000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER       0x00080000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS        0x00100000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE 0x00200000
#define PS_PIXEL_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME            0x00400000


#define PS_PIXEL_SHADER_DUMP_ON_CREATION_STRING                        "4b0a75"
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_ID                            0x004b0a75
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_OVERINSTALL                   0 // OVERRIDE
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_OFF                           0x18989151
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_DISABLED                      0x18989151
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_ON                            0x18384404
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_ENABLED                       0x18384404
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_DEFAULT                       PS_PIXEL_SHADER_DUMP_ON_CREATION_OFF


#define PS_PIXEL_SHADER_DUMP_ON_CREATION_FILENAME_STRING               "d14221"
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_FILENAME_ID                   0x00d14221
#define PS_PIXEL_SHADER_DUMP_ON_CREATION_FILENAME_OVERINSTALL          0 // OVERRIDE


#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_STRING                          "67390230"
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_ID                              0x00e4a54c
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_OVERINSTALL                     0 // OVERRIDE
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_SQDDELAY_NONFAT                 0x00000001
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_SQDDELAY_SEMIFAT                0x00000002
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_SQDDELAY_FAT                    0x00000004
#define PS_PIXEL_SHADER_SQDDELAY_ALLOW_DEFAULT                         0x00000007


#define PS_PIXEL_SHADER_SQDDELAY_NONTEXTURE_STRING                     "20923765"
#define PS_PIXEL_SHADER_SQDDELAY_NONTEXTURE_ID                         0x0044335b
#define PS_PIXEL_SHADER_SQDDELAY_NONTEXTURE_OVERINSTALL                0 // OVERRIDE
#define PS_PIXEL_SHADER_SQDDELAY_NONTEXTURE_DEFAULT                    0x60


#define PS_PIXEL_SHADER_SQDDELAY_SHORT_STRING                          "86396039"
#define PS_PIXEL_SHADER_SQDDELAY_SHORT_ID                              0x009f8149
#define PS_PIXEL_SHADER_SQDDELAY_SHORT_OVERINSTALL                     0 // OVERRIDE
#define PS_PIXEL_SHADER_SQDDELAY_SHORT_DEFAULT                         0


#define PS_PIXEL_SHADER_SQDDELAY_TEXTURE_STRING                        "69230592"
#define PS_PIXEL_SHADER_SQDDELAY_TEXTURE_ID                            0x0073622c
#define PS_PIXEL_SHADER_SQDDELAY_TEXTURE_OVERINSTALL                   0 // OVERRIDE
#define PS_PIXEL_SHADER_SQDDELAY_TEXTURE_DEFAULT                       0


#define PS_PIXEL_SHADER_STATS_MAX_SHADERS_DUMPED_STRING                "00015887"
#define PS_PIXEL_SHADER_STATS_MAX_SHADERS_DUMPED_ID                    0x00ee1093
#define PS_PIXEL_SHADER_STATS_MAX_SHADERS_DUMPED_OVERINSTALL           0 // OVERRIDE
#define PS_PIXEL_SHADER_STATS_MAX_SHADERS_DUMPED_DEFAULT               0x800


#define PS_PIXEL_SHADER_WHITENESS_STRING                               "75900125"
#define PS_PIXEL_SHADER_WHITENESS_ID                                   0x00822a00
#define PS_PIXEL_SHADER_WHITENESS_OVERINSTALL                          0 // OVERRIDE
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TUNEDNESS_STATIC_HANDTUNED     0x00000010
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TUNEDNESS_DYNAMIC_HANDTUNED    0x00000020
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TUNEDNESS_NON_HANDTUNED        0x00000040
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TYPE_TSS                       0x00000100
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TYPE_PS1X                      0x00000200
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TYPE_PS20                      0x00000400
#define PS_PIXEL_SHADER_WHITENESS_WHITE_TYPE_PS30                      0x00000800
#define PS_PIXEL_SHADER_WHITENESS_DEFAULT                              0


#define PS_PREFER_DSR_BLT_STRING                                       "56258452"
#define PS_PREFER_DSR_BLT_ID                                           0x003b15b2
#define PS_PREFER_DSR_BLT_OVERINSTALL                                  0 // OVERRIDE
#define PS_PREFER_DSR_BLT_OFF                                          0x00000000
#define PS_PREFER_DSR_BLT_DISABLED                                     0x00000000
#define PS_PREFER_DSR_BLT_ON                                           0x00000001
#define PS_PREFER_DSR_BLT_ENABLED                                      0x00000001
#define PS_PREFER_DSR_BLT_DEFAULT                                      PS_PREFER_DSR_BLT_ON


#define PS_PREFER_DSR_BLT_SIZE_STRING                                  "28347975"
#define PS_PREFER_DSR_BLT_SIZE_ID                                      0x004c8da1
#define PS_PREFER_DSR_BLT_SIZE_OVERINSTALL                             0 // OVERRIDE
#define PS_PREFER_DSR_BLT_SIZE_DEFAULT                                 0x100000


#define PS_PRERESOLVE_STRING                                           "16F84a00"
#define PS_PRERESOLVE_ID                                               0x004cda1e
#define PS_PRERESOLVE_OVERINSTALL                                      0 // OVERRIDE
#define PS_PRERESOLVE_OFF                                              0x18F3902C
#define PS_PRERESOLVE_DISABLED                                         0x18F3902C
#define PS_PRERESOLVE_ON                                               0x18F3902D
#define PS_PRERESOLVE_ENABLED                                          0x18F3902D
#define PS_PRERESOLVE_DEFAULT                                          PS_PRERESOLVE_ON


#define PS_PRIMARY_SURFACE_STALL_STRING                                "70453190"
#define PS_PRIMARY_SURFACE_STALL_ID                                    0x00222b57
#define PS_PRIMARY_SURFACE_STALL_OVERINSTALL                           0 // OVERRIDE
#define PS_PRIMARY_SURFACE_STALL_OFF                                   0x79384338
#define PS_PRIMARY_SURFACE_STALL_DISABLED                              0x79384338
#define PS_PRIMARY_SURFACE_STALL_ON                                    0x67081874
#define PS_PRIMARY_SURFACE_STALL_ENABLED                               0x67081874


#define PS_PRIMARY_SURFACE_STALL_STATS_STRING                          "38132616"
#define PS_PRIMARY_SURFACE_STALL_STATS_ID                              0x004ce466
#define PS_PRIMARY_SURFACE_STALL_STATS_OVERINSTALL                     0 // OVERRIDE
#define PS_PRIMARY_SURFACE_STALL_STATS_OFF                             0x00000000
#define PS_PRIMARY_SURFACE_STALL_STATS_DISABLED                        0x00000000
#define PS_PRIMARY_SURFACE_STALL_STATS_ON                              0x00000001
#define PS_PRIMARY_SURFACE_STALL_STATS_ENABLED                         0x00000001


#define PS_PROFILE_GUIDED_OPT_STRING                                   "553c9a15"
#define PS_PROFILE_GUIDED_OPT_ID                                       0x005d7297
#define PS_PROFILE_GUIDED_OPT_OVERINSTALL                              0 // OVERRIDE
#define PS_PROFILE_GUIDED_OPT_OFF                                      0xa2b53761
#define PS_PROFILE_GUIDED_OPT_DISABLED                                 0xa2b53761
#define PS_PROFILE_GUIDED_OPT_ON                                       0x79292610
#define PS_PROFILE_GUIDED_OPT_ENABLED                                  0x79292610
#define PS_PROFILE_GUIDED_OPT_DEFAULT                                  PS_PROFILE_GUIDED_OPT_OFF


#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_STRING                   "c0422caf"
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ID                       0x0094fced
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_OVERINSTALL              0 // OVERRIDE
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ALLOW_PS                 0x001
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ALLOW_CS                 0x002
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ZEROP_ALLOW_CODE_MOTION  0x004
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ZEROP_PERFORM_UNIFORM_CHECK 0x008
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ZEROP_ENABLE_ZEROP       0x010
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ZEROP_ENABLE_BB_FREQ_OPTIS 0x020
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_ZEROP_REORDER_COLD_BBS   0x040
#define PS_PROFILE_GUIDED_OPT_EXTRA_ORI_FLAGS_DEFAULT                  0x07F


#define PS_PROFILE_GUIDED_OPT_FILENAME_STRING                          "00742c74"
#define PS_PROFILE_GUIDED_OPT_FILENAME_ID                              0x000ca72b
#define PS_PROFILE_GUIDED_OPT_FILENAME_OVERINSTALL                     0 // OVERRIDE


#define PS_PROFILE_GUIDED_OPT_FLAGS_STRING                             "34dfabc1"
#define PS_PROFILE_GUIDED_OPT_FLAGS_ID                                 0x0017a4c5
#define PS_PROFILE_GUIDED_OPT_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_PROFILE_GUIDED_OPT_FLAGS_DISABLE_FOR_PS                     0x00000001
#define PS_PROFILE_GUIDED_OPT_FLAGS_DISABLE_FOR_CS                     0x00000002
#define PS_PROFILE_GUIDED_OPT_FLAGS_TURING_AND_ABOVE_ONLY              0x00000004
#define PS_PROFILE_GUIDED_OPT_FLAGS_AMPERE_AND_ABOVE_ONLY              0x00000008
#define PS_PROFILE_GUIDED_OPT_FLAGS_ENABLE_DX11                        0x00000010
#define PS_PROFILE_GUIDED_OPT_FLAGS_DISABLE_DX12                       0x00000020
#define PS_PROFILE_GUIDED_OPT_FLAGS_DEFAULT                            0


#define PS_PROFILE_GUIDED_OPT_FOCUS_ON_HASH_STRING                     "00972a82"
#define PS_PROFILE_GUIDED_OPT_FOCUS_ON_HASH_ID                         0x0041cd44
#define PS_PROFILE_GUIDED_OPT_FOCUS_ON_HASH_OVERINSTALL                0 // OVERRIDE
#define PS_PROFILE_GUIDED_OPT_FOCUS_ON_HASH_DEFAULT                    0x0


#define PS_PSHADER_COMPILE_STRING                                      "33863973"
#define PS_PSHADER_COMPILE_ID                                          0x00212b0a
#define PS_PSHADER_COMPILE_OVERINSTALL                                 0 // OVERRIDE
#define PS_PSHADER_COMPILE_OFF                                         0x29543769
#define PS_PSHADER_COMPILE_DISABLED                                    0x29543769
#define PS_PSHADER_COMPILE_ON                                          0x79272925
#define PS_PSHADER_COMPILE_ENABLED                                     0x79272925


#define PS_PSHADER_COMPILE_ALLOW_STRING                                "03075880"
#define PS_PSHADER_COMPILE_ALLOW_ID                                    0x00eeff4b
#define PS_PSHADER_COMPILE_ALLOW_OVERINSTALL                           0 // OVERRIDE
#define PS_PSHADER_COMPILE_ALLOW_ENABLE_OPTIMIZER                      0x00000001
#define PS_PSHADER_COMPILE_ALLOW_ENABLE_BRANCH_OPTIMIZER               0x00000002
#define PS_PSHADER_COMPILE_ALLOW_APP_DETECT                            0x00000010
#define PS_PSHADER_COMPILE_ALLOW_LOAD_BALANCE                          0x00000020


#define PS_PSO_LIBRARY_FLAGS_STRING                                    "ed0448"
#define PS_PSO_LIBRARY_FLAGS_ID                                        0x00ed0448
#define PS_PSO_LIBRARY_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_PSO_LIBRARY_FLAGS_ENABLE_DEFAULT_SHADER_SERIALIZATION       0x00000001
#define PS_PSO_LIBRARY_FLAGS_DISABLE_SERIALIZED_CHECKS                 0x00000002
#define PS_PSO_LIBRARY_FLAGS_MAX_VALUE                                 0xffffffff


#define PS_PUSHBUFFER_DUMP_FILENAME_STRING                             "ac12fedf"
#define PS_PUSHBUFFER_DUMP_FILENAME_ID                                 0x001e89f6
#define PS_PUSHBUFFER_DUMP_FILENAME_OVERINSTALL                        0 // OVERRIDE


#define PS_PUSHBUFFER_DUMP_FLAGS_STRING                                "ac12fede"
#define PS_PUSHBUFFER_DUMP_FLAGS_ID                                    0x0055302e
#define PS_PUSHBUFFER_DUMP_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define PS_PUSHBUFFER_DUMP_FLAGS_ENABLE                                0x00000001
#define PS_PUSHBUFFER_DUMP_FLAGS_PER_FRAME_LOGFILE                     0x00000002
#define PS_PUSHBUFFER_DUMP_FLAGS_DO_NOT_DECODE_METHODS                 0x00000004
#define PS_PUSHBUFFER_DUMP_FLAGS_COUNT_ONLY                            0x00000008
#define PS_PUSHBUFFER_DUMP_FLAGS_FORCE_COHERENT_PB_GP                  0x00000010
#define PS_PUSHBUFFER_DUMP_FLAGS_FORCE_NO_SUBROUTINES                  0x00000020
#define PS_PUSHBUFFER_DUMP_FLAGS_WFI_ONLY                              0x00000040
#define PS_PUSHBUFFER_DUMP_FLAGS_ENTRY_POINT_ANNOTATIONS               0x00000080
#define PS_PUSHBUFFER_DUMP_FLAGS_APP_REGIME_ANNOTATIONS                0x00000100
#define PS_PUSHBUFFER_DUMP_FLAGS_PERFSTRAT_ANNOTATIONS                 0x00000200
#define PS_PUSHBUFFER_DUMP_FLAGS_HOTKEY                                0x00001000
#define PS_PUSHBUFFER_DUMP_FLAGS_FLUSH_FILE                            0x00002000


#define PS_PUSH_VID_STRING                                             "82442271"
#define PS_PUSH_VID_ID                                                 0x001daa1e
#define PS_PUSH_VID_OVERINSTALL                                        0 // OVERRIDE
#define PS_PUSH_VID_OFF                                                0x66081959
#define PS_PUSH_VID_DISABLED                                           0x66081959
#define PS_PUSH_VID_ON                                                 0x10354174
#define PS_PUSH_VID_ENABLED                                            0x10354174


#define PS_R32F_COMPRESSION_STRING                                     "21693864"
#define PS_R32F_COMPRESSION_ID                                         0x002eeeba
#define PS_R32F_COMPRESSION_OVERINSTALL                                0 // OVERRIDE
#define PS_R32F_COMPRESSION_OFF                                        0x99388110
#define PS_R32F_COMPRESSION_DISABLED                                   0x99388110
#define PS_R32F_COMPRESSION_ON                                         0x25558967
#define PS_R32F_COMPRESSION_ENABLED                                    0x25558967
#define PS_R32F_COMPRESSION_DEFAULT                                    PS_R32F_COMPRESSION_ON


#define PS_REDUCE_MEMORY_FOOTPRINT_STRING                              "44F7A4"
#define PS_REDUCE_MEMORY_FOOTPRINT_ID                                  0x0044f7a4
#define PS_REDUCE_MEMORY_FOOTPRINT_OVERINSTALL                         0 // OVERRIDE
#define PS_REDUCE_MEMORY_FOOTPRINT_DEFAULT                             0x00000000
#define PS_REDUCE_MEMORY_FOOTPRINT_FORCE_ON                            0x00000001
#define PS_REDUCE_MEMORY_FOOTPRINT_FORCE_OFF                           0x00000002


#define PS_REDUCTION_STRING                                            "19463578"
#define PS_REDUCTION_ID                                                0x00584944
#define PS_REDUCTION_OVERINSTALL                                       0 // OVERRIDE
#define PS_REDUCTION_OFF                                               0x00000000
#define PS_REDUCTION_DISABLED                                          0x00000000
#define PS_REDUCTION_ON                                                0x00000001
#define PS_REDUCTION_ENABLED                                           0x00000001
#define PS_REDUCTION_DEFAULT                                           0x1


#define PS_REDUCTION_BLITS_STRING                                      "F3491F01"
#define PS_REDUCTION_BLITS_ID                                          0x00adc542
#define PS_REDUCTION_BLITS_OVERINSTALL                                 0 // OVERRIDE
#define PS_REDUCTION_BLITS_OFF                                         0x00000000
#define PS_REDUCTION_BLITS_DISABLED                                    0x00000000
#define PS_REDUCTION_BLITS_ON                                          0x00000001
#define PS_REDUCTION_BLITS_ENABLED                                     0x00000001
#define PS_REDUCTION_BLITS_DEFAULT                                     0x1


#define PS_REDUCTION_DISABLE_KNOB_STRING                               "1254CBFF"
#define PS_REDUCTION_DISABLE_KNOB_ID                                   0x005614f5
#define PS_REDUCTION_DISABLE_KNOB_OVERINSTALL                          0 // OVERRIDE
#define PS_REDUCTION_DISABLE_KNOB_DISABLE_WARPS_PER_SUBTILE            0x00000001
#define PS_REDUCTION_DISABLE_KNOB_DISABLE_REDUCTION_HACK               0x00000002
#define PS_REDUCTION_DISABLE_KNOB_DISABLE_WARP_THROTTLE                0x00000004
#define PS_REDUCTION_DISABLE_KNOB_DISABLE_REG_COUNT                    0x00000008
#define PS_REDUCTION_DISABLE_KNOB_DISABLE_COMPUTE                      0x00000010
#define PS_REDUCTION_DISABLE_KNOB_DEFAULT                              0x0


#define PS_REDUCTION_DYNAMIC_MODE_STRING                               "81736418"
#define PS_REDUCTION_DYNAMIC_MODE_ID                                   0x003dcdad
#define PS_REDUCTION_DYNAMIC_MODE_OVERINSTALL                          0 // OVERRIDE
#define PS_REDUCTION_DYNAMIC_MODE_OFF                                  0x00000000
#define PS_REDUCTION_DYNAMIC_MODE_DISABLED                             0x00000000
#define PS_REDUCTION_DYNAMIC_MODE_ON                                   0x00000001
#define PS_REDUCTION_DYNAMIC_MODE_ENABLED                              0x00000001
#define PS_REDUCTION_DYNAMIC_MODE_DEFAULT                              0x1


#define PS_REDUCTION_FORCED_STRING                                     "16936964"
#define PS_REDUCTION_FORCED_ID                                         0x0022b4eb
#define PS_REDUCTION_FORCED_OVERINSTALL                                0 // OVERRIDE
#define PS_REDUCTION_FORCED_OFF                                        0x00000000
#define PS_REDUCTION_FORCED_DISABLED                                   0x00000000
#define PS_REDUCTION_FORCED_ON                                         0x00000001
#define PS_REDUCTION_FORCED_ENABLED                                    0x00000001
#define PS_REDUCTION_FORCED_DEFAULT                                    0x0


#define PS_REDUCTION_HASH_MODE_STRING                                  "87634598"
#define PS_REDUCTION_HASH_MODE_ID                                      0x005925c4
#define PS_REDUCTION_HASH_MODE_OVERINSTALL                             0 // OVERRIDE
#define PS_REDUCTION_HASH_MODE_SINGLE_SHADER_OBJECT                    0x00000000
#define PS_REDUCTION_HASH_MODE_ALL_SHADER_OBJECT                       0x00000001
#define PS_REDUCTION_HASH_MODE_DEFAULT                                 0x1


#define PS_REDUCTION_LOAD_BALANCED_STRING                              "20943285"
#define PS_REDUCTION_LOAD_BALANCED_ID                                  0x00db834a
#define PS_REDUCTION_LOAD_BALANCED_OVERINSTALL                         0 // OVERRIDE
#define PS_REDUCTION_LOAD_BALANCED_OFF                                 0x00000000
#define PS_REDUCTION_LOAD_BALANCED_DISABLED                            0x00000000
#define PS_REDUCTION_LOAD_BALANCED_ON                                  0x00000001
#define PS_REDUCTION_LOAD_BALANCED_ENABLED                             0x00000001
#define PS_REDUCTION_LOAD_BALANCED_DEFAULT                             PS_REDUCTION_LOAD_BALANCED_ON


#define PS_REDUCTION_MAX_BUCKETS_PER_FRAME_STRING                      "12389074"
#define PS_REDUCTION_MAX_BUCKETS_PER_FRAME_ID                          0x0003a486
#define PS_REDUCTION_MAX_BUCKETS_PER_FRAME_OVERINSTALL                 0 // OVERRIDE
#define PS_REDUCTION_MAX_BUCKETS_PER_FRAME_DEFAULT                     0x8


#define PS_REDUCTION_MIN_DST_SIZE_STRING                               "f8c8e021"
#define PS_REDUCTION_MIN_DST_SIZE_ID                                   0x001f8c9d
#define PS_REDUCTION_MIN_DST_SIZE_OVERINSTALL                          0 // OVERRIDE
#define PS_REDUCTION_MIN_DST_SIZE_DEFAULT                              0x100


#define PS_REDUCTION_MIN_SRC_SIZE_STRING                               "10ce7f49"
#define PS_REDUCTION_MIN_SRC_SIZE_ID                                   0x00fac894
#define PS_REDUCTION_MIN_SRC_SIZE_OVERINSTALL                          0 // OVERRIDE
#define PS_REDUCTION_MIN_SRC_SIZE_DEFAULT                              0x80


#define PS_REDUCTION_MIN_TIMESTAMP_STRING                              "19f839ea"
#define PS_REDUCTION_MIN_TIMESTAMP_ID                                  0x00f81720
#define PS_REDUCTION_MIN_TIMESTAMP_OVERINSTALL                         0 // OVERRIDE
#define PS_REDUCTION_MIN_TIMESTAMP_DEFAULT                             0x2000


#define PS_REDUCTION_PROFILING_INTERVAL_STRING                         "43782461"
#define PS_REDUCTION_PROFILING_INTERVAL_ID                             0x00ad4c1f
#define PS_REDUCTION_PROFILING_INTERVAL_OVERINSTALL                    0 // OVERRIDE
#define PS_REDUCTION_PROFILING_INTERVAL_DEFAULT                        0x100


#define PS_REDUCTION_REGISTER_PER_SUBTILE_STRING                       "1362541A"
#define PS_REDUCTION_REGISTER_PER_SUBTILE_ID                           0x00f34f6f
#define PS_REDUCTION_REGISTER_PER_SUBTILE_OVERINSTALL                  0 // OVERRIDE
#define PS_REDUCTION_REGISTER_PER_SUBTILE_DEFAULT                      0x80


#define PS_REDUCTION_STATS_STRING                                      "16134F4C"
#define PS_REDUCTION_STATS_ID                                          0x00941288
#define PS_REDUCTION_STATS_OVERINSTALL                                 0 // OVERRIDE
#define PS_REDUCTION_STATS_OFF                                         0x00000000
#define PS_REDUCTION_STATS_DISABLED                                    0x00000000
#define PS_REDUCTION_STATS_ON                                          0x00000001
#define PS_REDUCTION_STATS_ENABLED                                     0x00000001
#define PS_REDUCTION_STATS_DEFAULT                                     0x0


#define PS_REDUCTION_STATS_FLAGS_STRING                                "197783BC"
#define PS_REDUCTION_STATS_FLAGS_ID                                    0x005f3874
#define PS_REDUCTION_STATS_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define PS_REDUCTION_STATS_FLAGS_PER_BUCKET_STATE_CHANGES              0x00000001
#define PS_REDUCTION_STATS_FLAGS_PER_BUCKET_PROFILING                  0x00000002
#define PS_REDUCTION_STATS_FLAGS_DEFAULT                               0x0


#define PS_REDUCTION_WARPS_PER_SUBTILE_STRING                          "87364952"
#define PS_REDUCTION_WARPS_PER_SUBTILE_ID                              0x0009333f
#define PS_REDUCTION_WARPS_PER_SUBTILE_OVERINSTALL                     0 // OVERRIDE
#define PS_REDUCTION_WARPS_PER_SUBTILE_DEFAULT                         0x2


#define PS_REDUCTION_WARP_THROTTLE_STRING                              "1348970F"
#define PS_REDUCTION_WARP_THROTTLE_ID                                  0x00f830fe
#define PS_REDUCTION_WARP_THROTTLE_OVERINSTALL                         0 // OVERRIDE
#define PS_REDUCTION_WARP_THROTTLE_OFF                                 0x00000000
#define PS_REDUCTION_WARP_THROTTLE_DISABLED                            0x00000000
#define PS_REDUCTION_WARP_THROTTLE_ON                                  0x00000001
#define PS_REDUCTION_WARP_THROTTLE_ENABLED                             0x00000001
#define PS_REDUCTION_WARP_THROTTLE_DEFAULT                             0x1


#define PS_RESIZEL1DM_STRING                                           "82443271"
#define PS_RESIZEL1DM_ID                                               0x001d1fe1
#define PS_RESIZEL1DM_OVERINSTALL                                      0 // OVERRIDE
#define PS_RESIZEL1DM_OFF                                              0x00000000
#define PS_RESIZEL1DM_DISABLED                                         0x00000000
#define PS_RESIZEL1DM_ON                                               0x00000001
#define PS_RESIZEL1DM_ENABLED                                          0x00000001
#define PS_RESIZEL1DM_DEFAULT                                          PS_RESIZEL1DM_ON


#define PS_RESIZEL1DM_FLAGS_STRING                                     "41292307"
#define PS_RESIZEL1DM_FLAGS_ID                                         0x001d1ee1
#define PS_RESIZEL1DM_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_RESIZEL1DM_FLAGS_DM_COMPUTE_DYNAMIC                         0x00000010
#define PS_RESIZEL1DM_FLAGS_DM_COMPUTE_48KB                            0x00000020
#define PS_RESIZEL1DM_FLAGS_DM_COMPUTE_32KB                            0x00000030
#define PS_RESIZEL1DM_FLAGS_DM_COMPUTE_16KB                            0x00000040
#define PS_RESIZEL1DM_FLAGS_DM_COMPUTE_MASK                            0x00000070
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_DYNAMIC                   0x00000100
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_0KB                       0x00000200
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_8KB                       0x00000300
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_16KB                      0x00000400
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_32KB                      0x00000500
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_64KB                      0x00000600
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_96KB                      0x00000700
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_MASK                      0x00000700
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_ENABLE_MAX                0x00001000
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_ENABLE_MIN                0x00002000
#define PS_RESIZEL1DM_FLAGS_DM_VOLTA_COMPUTE_ENABLE_MIN_MAX_MASK       0x00003000
#define PS_RESIZEL1DM_FLAGS_DM_TURING_COMPUTE_DYNAMIC                  0x00010000
#define PS_RESIZEL1DM_FLAGS_DM_TURING_COMPUTE_32KB                     0x00020000
#define PS_RESIZEL1DM_FLAGS_DM_TURING_COMPUTE_48KB                     0x00030000
#define PS_RESIZEL1DM_FLAGS_DM_TURING_COMPUTE_64KB                     0x00040000
#define PS_RESIZEL1DM_FLAGS_DM_TURING_COMPUTE_MASK                     0x00070000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_DYNAMIC                  0x00100000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_0KB                      0x00200000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_8KB                      0x00300000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_16KB                     0x00400000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_32KB                     0x00500000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_64KB                     0x00600000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_100KB                    0x00700000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_132KB                    0x00800000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_164KB                    0x00900000
#define PS_RESIZEL1DM_FLAGS_DM_AMPERE_COMPUTE_MASK                     0x00F00000
#define PS_RESIZEL1DM_FLAGS_DEFAULT                                    0x00110110


#define PS_RT_SHADER_DUMP_STRING                                       "dad3d6"
#define PS_RT_SHADER_DUMP_ID                                           0x00dad3d6
#define PS_RT_SHADER_DUMP_OVERINSTALL                                  0 // OVERRIDE
#define PS_RT_SHADER_DUMP_OFF                                          0x0
#define PS_RT_SHADER_DUMP_DISABLED                                     0x0
#define PS_RT_SHADER_DUMP_ON                                           0x1
#define PS_RT_SHADER_DUMP_ENABLED                                      0x1
#define PS_RT_SHADER_DUMP_DEFAULT                                      PS_RT_SHADER_DUMP_OFF


#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_STRING                           "a20168"
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_ID                               0x00a20168
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DUMP_SHADERS_ON_CREATION         0x00000001
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DUMP_HEX_UCODE                   0x00000004
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DUMP_ELF_SECTIONS                0x00000010
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DUMP_ELF_SECTION_CONTENTS        0x00000020
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DUMP_ELF_SECTION_UCODE           0x00000040
#define PS_RT_SHADER_DUMP_DEBUG_FLAGS_DEFAULT                          0


#define PS_RT_SHADER_DUMP_FLAGS_STRING                                 "aceb82"
#define PS_RT_SHADER_DUMP_FLAGS_ID                                     0x00aceb82
#define PS_RT_SHADER_DUMP_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define PS_RT_SHADER_DUMP_FLAGS_DUMP_RAYGEN_SHADERS                    0x00000001
#define PS_RT_SHADER_DUMP_FLAGS_DUMP_MISS_SHADERS                      0x00000002
#define PS_RT_SHADER_DUMP_FLAGS_DUMP_HITGROUP_SHADERS                  0x00000004
#define PS_RT_SHADER_DUMP_FLAGS_DUMP_CALLABLE_SHADERS                  0x00000008
#define PS_RT_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER          0x00080000
#define PS_RT_SHADER_DUMP_FLAGS_DEFAULT                                0x0000000f


#define PS_RT_SHADER_DUMP_ON_CREATION_FILENAME_STRING                  "01fca6"
#define PS_RT_SHADER_DUMP_ON_CREATION_FILENAME_ID                      0x0001fca6
#define PS_RT_SHADER_DUMP_ON_CREATION_FILENAME_OVERINSTALL             0 // OVERRIDE


#define PS_SAMPLEPIXEL_TWOPASS_STRING                                  "ab4548cd"
#define PS_SAMPLEPIXEL_TWOPASS_ID                                      0x00bd4d4d
#define PS_SAMPLEPIXEL_TWOPASS_OVERINSTALL                             0 // OVERRIDE
#define PS_SAMPLEPIXEL_TWOPASS_OFF                                     0x00000000
#define PS_SAMPLEPIXEL_TWOPASS_DISABLED                                0x00000000
#define PS_SAMPLEPIXEL_TWOPASS_ON                                      0x00000001
#define PS_SAMPLEPIXEL_TWOPASS_ENABLED                                 0x00000001
#define PS_SAMPLEPIXEL_TWOPASS_DEFAULT                                 PS_SAMPLEPIXEL_TWOPASS_ON


#define PS_SANDBAG_STRING                                              "0562AD70"
#define PS_SANDBAG_ID                                                  0x00eff101
#define PS_SANDBAG_OVERINSTALL                                         0 // OVERRIDE
#define PS_SANDBAG_OFF                                                 0x00000000
#define PS_SANDBAG_ON                                                  0x00000001
#define PS_SANDBAG_DEFAULT                                             PS_SANDBAG_OFF


#define PS_SANDBAG_WFI_COUNT_STRING                                    "0562AD72"
#define PS_SANDBAG_WFI_COUNT_ID                                        0x00eff301
#define PS_SANDBAG_WFI_COUNT_OVERINSTALL                               0 // OVERRIDE
#define PS_SANDBAG_WFI_COUNT_DEFAULT                                   0x64


#define PS_SANDBAG_WFI_FREQUENCY_STRING                                "0562AD71"
#define PS_SANDBAG_WFI_FREQUENCY_ID                                    0x00eff201
#define PS_SANDBAG_WFI_FREQUENCY_OVERINSTALL                           0 // OVERRIDE
#define PS_SANDBAG_WFI_FREQUENCY_DEFAULT                               0x1


#define PS_SECTOR_PROMOTION_STRING                                     "cc13ade2"
#define PS_SECTOR_PROMOTION_ID                                         0x000858ac
#define PS_SECTOR_PROMOTION_OVERINSTALL                                0 // OVERRIDE
#define PS_SECTOR_PROMOTION_FORCE_NO_PROMOTION                         0x00000001
#define PS_SECTOR_PROMOTION_FORCE_2H                                   0x00000002
#define PS_SECTOR_PROMOTION_FORCE_2V                                   0x00000004
#define PS_SECTOR_PROMOTION_FORCE_4                                    0x00000008
#define PS_SECTOR_PROMOTION_FORCE_MASK                                 0x0000000f
#define PS_SECTOR_PROMOTION_PREFER_2H                                  0x00000010
#define PS_SECTOR_PROMOTION_PREFER_2V                                  0x00000020
#define PS_SECTOR_PROMOTION_PREFER_4                                   0x00000040
#define PS_SECTOR_PROMOTION_PREFER_SETTING_MASK                        0x00000070
#define PS_SECTOR_PROMOTION_PREFER_FOR_BC_FORMATS                      0x00000100
#define PS_SECTOR_PROMOTION_PREFER_FOR_BUFFERS                         0x00000200
#define PS_SECTOR_PROMOTION_PREFER_FOR_MIPPED_OR_ARRAYED               0x00000400
#define PS_SECTOR_PROMOTION_PREFER_FOR_NON_RENDERABLE                  0x00000800
#define PS_SECTOR_PROMOTION_PREFER_FOR_NON_COMPRESSED                  0x00001000
#define PS_SECTOR_PROMOTION_PREFER_FOR_COMPRESSED                      0x00002000
#define PS_SECTOR_PROMOTION_PREFER_HEURISTIC_MASK                      0x00003f00


#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_STRING                       "cc13ade3"
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_ID                           0x000858ad
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_OVERINSTALL                  0 // OVERRIDE
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_OFF                          0x00000000
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_DISABLED                     0x00000000
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_ON                           0x00000001
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_ENABLED                      0x00000001
#define PS_SECTOR_PROMOTION_8XAA_OVERRIDE_DEFAULT                      PS_SECTOR_PROMOTION_8XAA_OVERRIDE_ON


#define PS_SHADERDISKCACHE_STRING                                      "F12B908F"
#define PS_SHADERDISKCACHE_ID                                          0x00198fff
#define PS_SHADERDISKCACHE_OVERINSTALL                                 0 // OVERRIDE
#define PS_SHADERDISKCACHE_OFF                                         0x00000000
#define PS_SHADERDISKCACHE_DISABLED                                    0x00000000
#define PS_SHADERDISKCACHE_ON                                          0x00000001
#define PS_SHADERDISKCACHE_ENABLED                                     0x00000001
#define PS_SHADERDISKCACHE_DEFAULT                                     PS_SHADERDISKCACHE_ON


#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_STRING             "F32B90a1"
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_ID                 0x0019a001
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_OVERINSTALL        0 // OVERRIDE
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_OFF                0x00000000
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_DISABLED           0x00000000
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_ON                 0x00000001
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_ENABLED            0x00000001
#define PS_SHADERDISKCACHE_DLL_LOADLIBRARY_SECURITY_DEFAULT            0x1


#define PS_SHADERDISKCACHE_DLL_PATH_STRING                             "F32B90a0"
#define PS_SHADERDISKCACHE_DLL_PATH_ID                                 0x0019a000
#define PS_SHADERDISKCACHE_DLL_PATH_OVERINSTALL                        0 // OVERRIDE
#define PS_SHADERDISKCACHE_DLL_PATH_DEFAULT                            ""


#define PS_SHADERDISKCACHE_FLAGS_STRING                                "83CA8490"
#define PS_SHADERDISKCACHE_FLAGS_ID                                    0x00f4889b
#define PS_SHADERDISKCACHE_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_DEFAULT_COMPILES              0x00000001
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_OPTIONAL_COMPILES             0x00000002
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_DRIVER_VERSIONING             0x00000008
#define PS_SHADERDISKCACHE_FLAGS_DUMP_HISTOGRAM                        0x00000010
#define PS_SHADERDISKCACHE_FLAGS_DUMP_TIMELINE                         0x00000020
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_GARBAGE_COLLECTION            0x00000040
#define PS_SHADERDISKCACHE_FLAGS_ENABLE_ENCRYPTION                     0x00000080
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_CRC                           0x00000100
#define PS_SHADERDISKCACHE_FLAGS_ENABLE_STATS_FILES                    0x00000200
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_STATS_RESET                   0x00000400
#define PS_SHADERDISKCACHE_FLAGS_DISABLE_DEBUG_FORCED_COMPILE          0x00000800
#define PS_SHADERDISKCACHE_FLAGS_NO_COMPRESSION                        0x00001000
#define PS_SHADERDISKCACHE_FLAGS_RLE_COMPRESSION                       0x00002000
#define PS_SHADERDISKCACHE_FLAGS_LZMA_COMPRESSION                      0x00004000
#define PS_SHADERDISKCACHE_FLAGS_BACKEND_MEM_MAP_FILES                 0x00010000
#define PS_SHADERDISKCACHE_FLAGS_BACKEND_GFN_DLL                       0x00020000
#define PS_SHADERDISKCACHE_FLAGS_BACKEND_SQLITE                        0x00040000
#define PS_SHADERDISKCACHE_FLAGS_FLOOD_CACHE_DIRECTORY                 0x00100000
#define PS_SHADERDISKCACHE_FLAGS_DEFAULT                               0x0


#define PS_SHADERDISKCACHE_LZMA_DICTSIZE_STRING                        "9187C742"
#define PS_SHADERDISKCACHE_LZMA_DICTSIZE_ID                            0x00ac8499
#define PS_SHADERDISKCACHE_LZMA_DICTSIZE_OVERINSTALL                   0 // OVERRIDE
#define PS_SHADERDISKCACHE_LZMA_DICTSIZE_DEFAULT                       0xd


#define PS_SHADERDISKCACHE_LZMA_LEVEL_STRING                           "9187C741"
#define PS_SHADERDISKCACHE_LZMA_LEVEL_ID                               0x00ac8498
#define PS_SHADERDISKCACHE_LZMA_LEVEL_OVERINSTALL                      0 // OVERRIDE
#define PS_SHADERDISKCACHE_LZMA_LEVEL_DEFAULT                          0x0


#define PS_SHADERDISKCACHE_MAX_DATA_FILES_STRING                       "9187C738"
#define PS_SHADERDISKCACHE_MAX_DATA_FILES_ID                           0x00ac8494
#define PS_SHADERDISKCACHE_MAX_DATA_FILES_OVERINSTALL                  0 // OVERRIDE
#define PS_SHADERDISKCACHE_MAX_DATA_FILES_DEFAULT                      0x40


#define PS_SHADERDISKCACHE_MAX_DEFAULT_BIN_SIZE_STRING                 "9187C737"
#define PS_SHADERDISKCACHE_MAX_DEFAULT_BIN_SIZE_ID                     0x00ac8493
#define PS_SHADERDISKCACHE_MAX_DEFAULT_BIN_SIZE_OVERINSTALL            0 // OVERRIDE
#define PS_SHADERDISKCACHE_MAX_DEFAULT_BIN_SIZE_DEFAULT                0x200


#define PS_SHADERDISKCACHE_MAX_OPTIONAL_BIN_SIZE_STRING                "9187C739"
#define PS_SHADERDISKCACHE_MAX_OPTIONAL_BIN_SIZE_ID                    0x00ac8495
#define PS_SHADERDISKCACHE_MAX_OPTIONAL_BIN_SIZE_OVERINSTALL           0 // OVERRIDE
#define PS_SHADERDISKCACHE_MAX_OPTIONAL_BIN_SIZE_DEFAULT               0x100


#define PS_SHADERDISKCACHE_MAX_RTCORE_BIN_SIZE_STRING                  "9187C73A"
#define PS_SHADERDISKCACHE_MAX_RTCORE_BIN_SIZE_ID                      0x00ac8496
#define PS_SHADERDISKCACHE_MAX_RTCORE_BIN_SIZE_OVERINSTALL             0 // OVERRIDE
#define PS_SHADERDISKCACHE_MAX_RTCORE_BIN_SIZE_DEFAULT                 0x100


#define PS_SHADERDISKCACHE_MAX_SIZE_STRING                             "9187C740"
#define PS_SHADERDISKCACHE_MAX_SIZE_ID                                 0x00ac8497
#define PS_SHADERDISKCACHE_MAX_SIZE_OVERINSTALL                        1 // MERGE
#define PS_SHADERDISKCACHE_MAX_SIZE_MIN                                0x0
#define PS_SHADERDISKCACHE_MAX_SIZE_MAX                                0xffffffff
#define PS_SHADERDISKCACHE_MAX_SIZE_DEFAULT                            0x1000


#define PS_SHADERDISKCACHE_MAX_TOC_SIZE_STRING                         "9187C736"
#define PS_SHADERDISKCACHE_MAX_TOC_SIZE_ID                             0x00ac8492
#define PS_SHADERDISKCACHE_MAX_TOC_SIZE_OVERINSTALL                    0 // OVERRIDE
#define PS_SHADERDISKCACHE_MAX_TOC_SIZE_DEFAULT                        0x100


#define PS_SHADERDISKCACHE_PATH_STRING                                 "F32B909F"
#define PS_SHADERDISKCACHE_PATH_ID                                     0x00199fff
#define PS_SHADERDISKCACHE_PATH_OVERINSTALL                            0 // OVERRIDE
#define PS_SHADERDISKCACHE_PATH_DEFAULT                                L""


#define PS_SHADER_CLEAR_STRING                                         "ab454eee"
#define PS_SHADER_CLEAR_ID                                             0x00bd4eee
#define PS_SHADER_CLEAR_OVERINSTALL                                    0 // OVERRIDE
#define PS_SHADER_CLEAR_OFF                                            0x00000000
#define PS_SHADER_CLEAR_DISABLED                                       0x00000000
#define PS_SHADER_CLEAR_ON                                             0x00000001
#define PS_SHADER_CLEAR_ENABLED                                        0x00000001
#define PS_SHADER_CLEAR_DEFAULT                                        PS_SHADER_CLEAR_ON


#define PS_SHADER_CLEAR_FLAGS_STRING                                   "12afdeee"
#define PS_SHADER_CLEAR_FLAGS_ID                                       0x00321eee
#define PS_SHADER_CLEAR_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_SHADER_CLEAR_FLAGS_DISABLE_COLOR_CLEAR                      0x00000001
#define PS_SHADER_CLEAR_FLAGS_DISABLE_DEPTH_CLEAR                      0x00000002
#define PS_SHADER_CLEAR_FLAGS_DISABLE_STENCIL_CLEAR                    0x00000004
#define PS_SHADER_CLEAR_FLAGS_DISABLE_PARTIAL_CLEAR                    0x00000004
#define PS_SHADER_CLEAR_FLAGS_DISABLE_ARBITRARY_VALUE                  0x00000008
#define PS_SHADER_CLEAR_FLAGS_DISABLE_PER_COMPONENT_VALUE              0x00000010
#define PS_SHADER_CLEAR_FLAGS_DEFAULT                                  0


#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_STRING      "03134744"
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_ID          0x007428e3
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_OVERINSTALL 0 // OVERRIDE
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_OFF         0x00000000
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_DISABLED    0x00000000
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_ON          0x00000001
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_ENABLED     0x00000001
#define PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_DEFAULT     PS_SHADER_COMPILE_FORCE_SURFCLAMP_FROM_IGN_TO_TRAP_OFF


#define PS_SHADER_COMPILE_OPT_LEVEL_STRING                             "61491656"
#define PS_SHADER_COMPILE_OPT_LEVEL_ID                                 0x00d04375
#define PS_SHADER_COMPILE_OPT_LEVEL_OVERINSTALL                        0 // OVERRIDE
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_UNSPEC                         0x00000000
#define PS_SHADER_COMPILE_OPT_LEVEL_0                                  0x00000000
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_MIN                            0x00000001
#define PS_SHADER_COMPILE_OPT_LEVEL_1                                  0x00000001
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_LOW                            0x00000002
#define PS_SHADER_COMPILE_OPT_LEVEL_2                                  0x00000002
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_DEFAULT                        0x00000003
#define PS_SHADER_COMPILE_OPT_LEVEL_3                                  0x00000003
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_HIGH                           0x00000004
#define PS_SHADER_COMPILE_OPT_LEVEL_4                                  0x00000004
#define PS_SHADER_COMPILE_OPT_LEVEL_COP_MAX                            0x00000005
#define PS_SHADER_COMPILE_OPT_LEVEL_5                                  0x00000005
#define PS_SHADER_COMPILE_OPT_LEVEL_DEFAULT                            PS_SHADER_COMPILE_OPT_LEVEL_COP_HIGH


#define PS_SHADER_CONST_EXPRESSIONS_STRING                             "bcfe4410"
#define PS_SHADER_CONST_EXPRESSIONS_ID                                 0x00fc7620
#define PS_SHADER_CONST_EXPRESSIONS_OVERINSTALL                        0 // OVERRIDE
#define PS_SHADER_CONST_EXPRESSIONS_OFF                                0x0
#define PS_SHADER_CONST_EXPRESSIONS_DISABLED                           0x0
#define PS_SHADER_CONST_EXPRESSIONS_ON                                 0x1
#define PS_SHADER_CONST_EXPRESSIONS_ENABLED                            0x1


#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_STRING                       "bcfe4411"
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_ID                           0x00fc7621
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_OVERINSTALL                  0 // OVERRIDE
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_DONT_OPT_NVINST_CONST_TLD    0x00000001
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_DONT_OPT_NVINST_EMULATED_CONSTANT_LOADS 0x00000002
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_DISABLE_OCG_CONSTEXPR        0x00010000
#define PS_SHADER_CONST_EXPRESSIONS_FLAGS_DISABLE_NVINST_CONSTEXPR     0x10000000


#define PS_SHADER_LOADBALANCE_STRING                                   "58027530"
#define PS_SHADER_LOADBALANCE_ID                                       0x00fd3683
#define PS_SHADER_LOADBALANCE_OVERINSTALL                              0 // OVERRIDE
#define PS_SHADER_LOADBALANCE_PS_FORCE_REG_ALLOC_POLICY                0x00000001
#define PS_SHADER_LOADBALANCE_PS_REG_ALLOC_POLICY_THIN                 0x00000000
#define PS_SHADER_LOADBALANCE_PS_REG_ALLOC_POLICY_THICK                0x00000002
#define PS_SHADER_LOADBALANCE_DEFAULT                                  0


#define PS_SHADER_MERGE_STRING                                         "ab49f012"
#define PS_SHADER_MERGE_ID                                             0x0001f85e
#define PS_SHADER_MERGE_OVERINSTALL                                    0 // OVERRIDE
#define PS_SHADER_MERGE_OFF                                            0x0
#define PS_SHADER_MERGE_DISABLED                                       0x0
#define PS_SHADER_MERGE_ON                                             0x1
#define PS_SHADER_MERGE_ENABLED                                        0x1
#define PS_SHADER_MERGE_DEFAULT                                        PS_SHADER_MERGE_ON


#define PS_SHADER_MERGE_FLAGS_STRING                                   "fe038f12"
#define PS_SHADER_MERGE_FLAGS_ID                                       0x0001f85f
#define PS_SHADER_MERGE_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_SHADER_MERGE_FLAGS_DISABLE_MERGE                            0x00000000
#define PS_SHADER_MERGE_FLAGS_ENABLE_SRGB_CONVERSION                   0x00000001
#define PS_SHADER_MERGE_FLAGS_ENABLE_B10G11R11F_CONVERSION             0x00000002
#define PS_SHADER_MERGE_FLAGS_DEFAULT                                  PS_SHADER_MERGE_FLAGS_ENABLE_SRGB_CONVERSION


#define PS_SHADER_MERGE_SRGB_INST_LIMIT_STRING                         "10f12931"
#define PS_SHADER_MERGE_SRGB_INST_LIMIT_ID                             0x000fb391
#define PS_SHADER_MERGE_SRGB_INST_LIMIT_OVERINSTALL                    0 // OVERRIDE
#define PS_SHADER_MERGE_SRGB_INST_LIMIT_DEFAULT                        0x0


#define PS_SHADER_PROFILING_XML_STRING                                 "03234742"
#define PS_SHADER_PROFILING_XML_ID                                     0x007322e1
#define PS_SHADER_PROFILING_XML_OVERINSTALL                            0 // OVERRIDE


#define PS_SHADER_REPLACEMENT_STRING                                   "03134743"
#define PS_SHADER_REPLACEMENT_ID                                       0x007428e2
#define PS_SHADER_REPLACEMENT_OVERINSTALL                              0 // OVERRIDE
#define PS_SHADER_REPLACEMENT_OFF                                      0x49106433
#define PS_SHADER_REPLACEMENT_DISABLED                                 0x49106433
#define PS_SHADER_REPLACEMENT_ON                                       0x68974006
#define PS_SHADER_REPLACEMENT_ENABLED                                  0x68974006


#define PS_SHADER_REPLACEMENT_FILENAME_STRING                          "25025519"
#define PS_SHADER_REPLACEMENT_FILENAME_ID                              0x00a13b84
#define PS_SHADER_REPLACEMENT_FILENAME_OVERINSTALL                     0 // OVERRIDE


#define PS_SHADER_REPLACEMENT_FLAGS_STRING                             "94754171"
#define PS_SHADER_REPLACEMENT_FLAGS_ID                                 0x0025b830
#define PS_SHADER_REPLACEMENT_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_PIXEL_SHADERS               0x00000001
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_VERTEX_SHADERS              0x00000002
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_GEOMETRY_SHADERS            0x00000004
#define PS_SHADER_REPLACEMENT_FLAGS_DYNAMIC_SHADERS                    0x00000008
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_HULL_SHADERS                0x00000010
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_DOMAIN_SHADERS              0x00000020
#define PS_SHADER_REPLACEMENT_FLAGS_STATIC_COMPUTE_SHADERS             0x00000040
#define PS_SHADER_REPLACEMENT_FLAGS_DYNAMIC_SHADER_COLLECTIONS         0x00010000
#define PS_SHADER_REPLACEMENT_FLAGS_MATCH_UCODE_HASH                   0x00020000


#define PS_SHADER_REPLACEMENT_RESERVED_VA_STRING                       "94754172"
#define PS_SHADER_REPLACEMENT_RESERVED_VA_ID                           0x0025b831
#define PS_SHADER_REPLACEMENT_RESERVED_VA_OVERINSTALL                  0 // OVERRIDE
#define PS_SHADER_REPLACEMENT_RESERVED_VA_DEFAULT                      0x0000000000


#define PS_SHADER_REPLACEMENT_RESERVED_VA_SIZE_STRING                  "94754173"
#define PS_SHADER_REPLACEMENT_RESERVED_VA_SIZE_ID                      0x0025b832
#define PS_SHADER_REPLACEMENT_RESERVED_VA_SIZE_OVERINSTALL             0 // OVERRIDE
#define PS_SHADER_REPLACEMENT_RESERVED_VA_SIZE_DEFAULT                 0x000000000


#define PS_SHADER_SELECTION_GPU_STRING                                 "1b71385b"
#define PS_SHADER_SELECTION_GPU_ID                                     0x00b23833
#define PS_SHADER_SELECTION_GPU_OVERINSTALL                            0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_OFF                                    0xd3a0a7c9
#define PS_SHADER_SELECTION_GPU_DISABLED                               0xd3a0a7c9
#define PS_SHADER_SELECTION_GPU_ON                                     0xb27051ba
#define PS_SHADER_SELECTION_GPU_ENABLED                                0xb27051ba
#define PS_SHADER_SELECTION_GPU_DEFAULT                                PS_SHADER_SELECTION_GPU_ON


#define PS_SHADER_SELECTION_GPU_FLAGS_STRING                           "81ba4de2"
#define PS_SHADER_SELECTION_GPU_FLAGS_ID                               0x00d89676
#define PS_SHADER_SELECTION_GPU_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_FLAGS_DEBUG_ALWAYS_USE_FALLBACK_SHADER 0x00000001
#define PS_SHADER_SELECTION_GPU_FLAGS_DEBUG_ALWAYS_USE_OPTIMIZED_SHADER 0x00000002
#define PS_SHADER_SELECTION_GPU_FLAGS_DEBUG_CORRUPT_INVARIANT_SET      0x00000004
#define PS_SHADER_SELECTION_GPU_FLAGS_DEBUG_SKIP_PATCH_SHADER          0x00000010
#define PS_SHADER_SELECTION_GPU_FLAGS_DEBUG_BREAK_ON_DISABLE           0x00000020
#define PS_SHADER_SELECTION_GPU_FLAGS_ENABLE_LOW_LATENCY               0x00000100
#define PS_SHADER_SELECTION_GPU_FLAGS_ENABLE_SELECTION_CONTEXT_NEW_PASS 0x00000200
#define PS_SHADER_SELECTION_GPU_FLAGS_ENABLE_PATCH_CONTEXT_NEW_PASS    0x00000400
#define PS_SHADER_SELECTION_GPU_FLAGS_DISABLE_FOR_DISPATCH_INDIRECT    0x04000000
#define PS_SHADER_SELECTION_GPU_FLAGS_GATHER_OCCUPANCY_STATS           0x08000000
#define PS_SHADER_SELECTION_GPU_FLAGS_GATHER_FALLBACK_STATS            0x10000000
#define PS_SHADER_SELECTION_GPU_FLAGS_GATHER_ANALYSIS_SHADER_TIMES     0x20000000
#define PS_SHADER_SELECTION_GPU_FLAGS_GATHER_GENERAL_STATS             0x40000000
#define PS_SHADER_SELECTION_GPU_FLAGS_GATHER_PROFILE_DATA              0x80000000
#define PS_SHADER_SELECTION_GPU_FLAGS_DEFAULT                          0


#define PS_SHADER_SELECTION_GPU_INDICATOR_STRING                       "eb05df"
#define PS_SHADER_SELECTION_GPU_INDICATOR_ID                           0x00eb05df
#define PS_SHADER_SELECTION_GPU_INDICATOR_OVERINSTALL                  0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_INDICATOR_OFF                          0
#define PS_SHADER_SELECTION_GPU_INDICATOR_DISABLED                     0
#define PS_SHADER_SELECTION_GPU_INDICATOR_ON                           1
#define PS_SHADER_SELECTION_GPU_INDICATOR_ENABLED                      1
#define PS_SHADER_SELECTION_GPU_INDICATOR_DEFAULT                      PS_SHADER_SELECTION_GPU_INDICATOR_OFF


#define PS_SHADER_SELECTION_GPU_LDA_STRING                             "eb05e0"
#define PS_SHADER_SELECTION_GPU_LDA_ID                                 0x00eb05e0
#define PS_SHADER_SELECTION_GPU_LDA_OVERINSTALL                        0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_LDA_NONE                               0
#define PS_SHADER_SELECTION_GPU_LDA_0                                  0
#define PS_SHADER_SELECTION_GPU_LDA_ALL                                1
#define PS_SHADER_SELECTION_GPU_LDA_1                                  1
#define PS_SHADER_SELECTION_GPU_LDA_PASCAL_AND_NEWER                   2
#define PS_SHADER_SELECTION_GPU_LDA_TURING_AND_NEWER                   3
#define PS_SHADER_SELECTION_GPU_LDA_AMPERE_AND_NEWER                   4
#define PS_SHADER_SELECTION_GPU_LDA_DEFAULT                            PS_SHADER_SELECTION_GPU_LDA_AMPERE_AND_NEWER


#define PS_SHADER_SELECTION_GPU_PATCH_THREAD_GROUP_SIZE_STRING         "5b4e7c86"
#define PS_SHADER_SELECTION_GPU_PATCH_THREAD_GROUP_SIZE_ID             0x00bb573c
#define PS_SHADER_SELECTION_GPU_PATCH_THREAD_GROUP_SIZE_OVERINSTALL    0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_PATCH_THREAD_GROUP_SIZE_DEFAULT        256


#define PS_SHADER_SELECTION_GPU_PROCESSING_THREAD_TIMEOUT_STRING       "096bac1d"
#define PS_SHADER_SELECTION_GPU_PROCESSING_THREAD_TIMEOUT_ID           0x005d3415
#define PS_SHADER_SELECTION_GPU_PROCESSING_THREAD_TIMEOUT_OVERINSTALL  0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_PROCESSING_THREAD_TIMEOUT_DEFAULT      40


#define PS_SHADER_SELECTION_GPU_SELECTION_THREAD_GROUP_SIZE_STRING     "7b97daab"
#define PS_SHADER_SELECTION_GPU_SELECTION_THREAD_GROUP_SIZE_ID         0x00cad27e
#define PS_SHADER_SELECTION_GPU_SELECTION_THREAD_GROUP_SIZE_OVERINSTALL 0 // OVERRIDE
#define PS_SHADER_SELECTION_GPU_SELECTION_THREAD_GROUP_SIZE_DEFAULT    256


#define PS_SHADER_SPECIFIC_REDUCTION12_STRING                          "cbdf32"
#define PS_SHADER_SPECIFIC_REDUCTION12_ID                              0x0003fe33
#define PS_SHADER_SPECIFIC_REDUCTION12_OVERINSTALL                     0 // OVERRIDE
#define PS_SHADER_SPECIFIC_REDUCTION12_OFF                             0x00000000
#define PS_SHADER_SPECIFIC_REDUCTION12_DISABLED                        0x00000000
#define PS_SHADER_SPECIFIC_REDUCTION12_ON                              0x00000001
#define PS_SHADER_SPECIFIC_REDUCTION12_ENABLED                         0x00000001
#define PS_SHADER_SPECIFIC_REDUCTION12_DEFAULT                         PS_SHADER_SPECIFIC_REDUCTION12_ON


#define PS_SHADER_SRV2LDG_FLAGS_STRING                                 "8108a6cc"
#define PS_SHADER_SRV2LDG_FLAGS_ID                                     0x006a8018
#define PS_SHADER_SRV2LDG_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_RAW                         0x00000001
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_STRUCTURED                  0x00000002
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_OUTOFBOUNDS_CHECK              0x00000010
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_SM_OOR_ADDR_CHECK_FASTPATH     0x00000020
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_STRUCTURED_FOR_STRIDE_4     0x00000100
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_STRUCTURED_FOR_STRIDE_8     0x00000200
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_STRUCTURED_FOR_STRIDE_12    0x00000400
#define PS_SHADER_SRV2LDG_FLAGS_DISABLE_LD_STRUCTURED_FOR_STRIDE_16    0x00000800
#define PS_SHADER_SRV2LDG_FLAGS_DEFAULT                                0x3


#define PS_SHADER_TLD4_STRING                                          "bcfe4412"
#define PS_SHADER_TLD4_ID                                              0x00fc7622
#define PS_SHADER_TLD4_OVERINSTALL                                     0 // OVERRIDE
#define PS_SHADER_TLD4_OFF                                             0x0
#define PS_SHADER_TLD4_DISABLED                                        0x0
#define PS_SHADER_TLD4_ON                                              0x1
#define PS_SHADER_TLD4_ENABLED                                         0x1


#define PS_SHADER_TLD4_FLAGS_STRING                                    "bcfe4413"
#define PS_SHADER_TLD4_FLAGS_ID                                        0x00fc7623
#define PS_SHADER_TLD4_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_SHADER_TLD4_FLAGS_DONT_OPT_TLD                              0x00000001


#define PS_SHADOW_STRING                                               "ab6548cd"
#define PS_SHADOW_ID                                                   0x00ad4d4d
#define PS_SHADOW_OVERINSTALL                                          0 // OVERRIDE
#define PS_SHADOW_OFF                                                  0x00000000
#define PS_SHADOW_DISABLED                                             0x00000000
#define PS_SHADOW_ON                                                   0x00000001
#define PS_SHADOW_ENABLED                                              0x00000001
#define PS_SHADOW_DEFAULT                                              PS_SHADOW_ON


#define PS_SHADOW_FLAGS_STRING                                         "ab5548cd"
#define PS_SHADOW_FLAGS_ID                                             0x00ad4a4d
#define PS_SHADOW_FLAGS_OVERINSTALL                                    0 // OVERRIDE
#define PS_SHADOW_FLAGS_DISABLE_MINMAX                                 0x00000001
#define PS_SHADOW_FLAGS_DISABLE_BITPACKING                             0x00000002
#define PS_SHADOW_FLAGS_DISABLE_BITPACKBRANCHING                       0x00000004
#define PS_SHADOW_FLAGS_DISABLE_DEPTHCONVERSION                        0x00000008
#define PS_SHADOW_FLAGS_DISABLE_CONVEXITY                              0x00000010
#define PS_SHADOW_FLAGS_DEFAULT                                        0x0


#define PS_SHARE_AA_RT_STRING                                          "18F3902B"
#define PS_SHARE_AA_RT_ID                                              0x006f6a1b
#define PS_SHARE_AA_RT_OVERINSTALL                                     0 // OVERRIDE
#define PS_SHARE_AA_RT_OFF                                             0x18F3902C
#define PS_SHARE_AA_RT_DISABLED                                        0x18F3902C
#define PS_SHARE_AA_RT_ON                                              0x18F3902D
#define PS_SHARE_AA_RT_ENABLED                                         0x18F3902D


#define PS_SHARE_AA_RT_FLAGS_STRING                                    "813F09B2"
#define PS_SHARE_AA_RT_FLAGS_ID                                        0x00beaa8d
#define PS_SHARE_AA_RT_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_SHARE_AA_RT_FLAGS_DBGPRINT                                  0x00000001
#define PS_SHARE_AA_RT_FLAGS_DO_NOT_RESTORE                            0x00000002
#define PS_SHARE_AA_RT_FLAGS_NO_THRESHOLD                              0x00000004


#define PS_SINGLE_CLIP_PLANE_SHEAR_STRING                              "62145345"
#define PS_SINGLE_CLIP_PLANE_SHEAR_ID                                  0x008b71fc
#define PS_SINGLE_CLIP_PLANE_SHEAR_OVERINSTALL                         0 // OVERRIDE
#define PS_SINGLE_CLIP_PLANE_SHEAR_OFF                                 0
#define PS_SINGLE_CLIP_PLANE_SHEAR_DISABLED                            0
#define PS_SINGLE_CLIP_PLANE_SHEAR_FALSE                               0
#define PS_SINGLE_CLIP_PLANE_SHEAR_0                                   0
#define PS_SINGLE_CLIP_PLANE_SHEAR_NO_CLIP_PLANE_CHANGES               1
#define PS_SINGLE_CLIP_PLANE_SHEAR_ALLOW_0TO1_TRANSITION               2


#define PS_SKIP_SURFACE_STORE_STRING                                   "44597412"
#define PS_SKIP_SURFACE_STORE_ID                                       0x00f62467
#define PS_SKIP_SURFACE_STORE_OVERINSTALL                              0 // OVERRIDE
#define PS_SKIP_SURFACE_STORE_OFF                                      0x00000000
#define PS_SKIP_SURFACE_STORE_DISABLED                                 0x00000000
#define PS_SKIP_SURFACE_STORE_ON                                       0x00000001
#define PS_SKIP_SURFACE_STORE_ENABLED                                  0x00000001
#define PS_SKIP_SURFACE_STORE_DEFAULT                                  PS_SKIP_SURFACE_STORE_ON


#define PS_SKIP_SURFACE_STORE_FLAGS_STRING                             "44597411"
#define PS_SKIP_SURFACE_STORE_FLAGS_ID                                 0x00f62466
#define PS_SKIP_SURFACE_STORE_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_SKIP_SURFACE_STORE_FLAGS_FORCE_SUST_TO_NOP                  0x00000001
#define PS_SKIP_SURFACE_STORE_FLAGS_DEFAULT                            0


#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_STRING                          "af10fa13"
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_ID                              0x00fef772
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_OVERINSTALL                     0 // OVERRIDE
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_OFF                             0
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_DISABLED                        0
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_ON                              1
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_ENABLED                         1
#define PS_SKIP_WRITE_BUFFER_IMMEDIATE_DEFAULT                         PS_SKIP_WRITE_BUFFER_IMMEDIATE_OFF


#define PS_SOFTWAREVSHADER_STRING                                      "9F4E781C"
#define PS_SOFTWAREVSHADER_ID                                          0x004fc81b
#define PS_SOFTWAREVSHADER_OVERINSTALL                                 0 // OVERRIDE
#define PS_SOFTWAREVSHADER_OFF                                         0
#define PS_SOFTWAREVSHADER_DISABLED                                    0
#define PS_SOFTWAREVSHADER_ON                                          1
#define PS_SOFTWAREVSHADER_ENABLED                                     1
#define PS_SOFTWAREVSHADER_DEFAULT                                     PS_SOFTWAREVSHADER_ON


#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_STRING                 "8E33A84D"
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_ID                     0x00402a87
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_OVERINSTALL            0 // OVERRIDE
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_OFF                    0
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_0                      0
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_FALSE                  0
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_DISABLED               0
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_ON                     1
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_1                      1
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_TRUE                   1
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_ENABLED                1
#define PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_DEFAULT                PS_SOFTWAREVSHADER_ALLOW_UNCACHED_READS_ON


#define PS_SOFTWAREVSHADER_SSE_MATH_STRING                             "9F4E781D"
#define PS_SOFTWAREVSHADER_SSE_MATH_ID                                 0x00301b78
#define PS_SOFTWAREVSHADER_SSE_MATH_OVERINSTALL                        0 // OVERRIDE
#define PS_SOFTWAREVSHADER_SSE_MATH_OFF                                0
#define PS_SOFTWAREVSHADER_SSE_MATH_0                                  0
#define PS_SOFTWAREVSHADER_SSE_MATH_FALSE                              0
#define PS_SOFTWAREVSHADER_SSE_MATH_DISABLED                           0
#define PS_SOFTWAREVSHADER_SSE_MATH_ON                                 1
#define PS_SOFTWAREVSHADER_SSE_MATH_1                                  1
#define PS_SOFTWAREVSHADER_SSE_MATH_TRUE                               1
#define PS_SOFTWAREVSHADER_SSE_MATH_ENABLED                            1
#define PS_SOFTWAREVSHADER_SSE_MATH_DEFAULT                            PS_SOFTWAREVSHADER_SSE_MATH_ON


#define PS_SPH_FORCE_GLOBAL_STORE_STRING                               "0153334"
#define PS_SPH_FORCE_GLOBAL_STORE_ID                                   0x00153334
#define PS_SPH_FORCE_GLOBAL_STORE_OVERINSTALL                          0 // OVERRIDE
#define PS_SPH_FORCE_GLOBAL_STORE_OFF                                  0x0
#define PS_SPH_FORCE_GLOBAL_STORE_DISABLED                             0x0
#define PS_SPH_FORCE_GLOBAL_STORE_ON                                   0x1
#define PS_SPH_FORCE_GLOBAL_STORE_ENABLED                              0x1


#define PS_SPH_FORCE_GLOBAL_STORE_HASH_STRING                          "0153333"
#define PS_SPH_FORCE_GLOBAL_STORE_HASH_ID                              0x00153333
#define PS_SPH_FORCE_GLOBAL_STORE_HASH_OVERINSTALL                     0 // OVERRIDE
#define PS_SPH_FORCE_GLOBAL_STORE_HASH_DEFAULT                         0x0


#define PS_SPOOF_CLEAR_STRING                                          "934234e4"
#define PS_SPOOF_CLEAR_ID                                              0x0063e966
#define PS_SPOOF_CLEAR_OVERINSTALL                                     0 // OVERRIDE
#define PS_SPOOF_CLEAR_OFF                                             0x0
#define PS_SPOOF_CLEAR_DISABLED                                        0x0
#define PS_SPOOF_CLEAR_ON                                              0x1
#define PS_SPOOF_CLEAR_ENABLED                                         0x1
#define PS_SPOOF_CLEAR_DEFAULT                                         PS_SPOOF_CLEAR_ON


#define PS_SPOOF_CLEAR_FLAGS_STRING                                    "95231ef"
#define PS_SPOOF_CLEAR_FLAGS_ID                                        0x0067e967
#define PS_SPOOF_CLEAR_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_SPOOF_CLEAR_FLAGS_R8_AS_C32                                 0x00000001
#define PS_SPOOF_CLEAR_FLAGS_A8_AS_C32                                 0x00000002
#define PS_SPOOF_CLEAR_FLAGS_R8G8_AS_C32                               0x00000004
#define PS_SPOOF_CLEAR_FLAGS_R5G6B5_AS_C32                             0x00000008
#define PS_SPOOF_CLEAR_FLAGS_R16_AS_C32                                0x00000010
#define PS_SPOOF_CLEAR_FLAGS_DEFAULT                                   0x0000001f


#define PS_SPOOF_RGBA8_AS_UINT32_STRING                                "387dea44"
#define PS_SPOOF_RGBA8_AS_UINT32_ID                                    0x0026ff10
#define PS_SPOOF_RGBA8_AS_UINT32_OVERINSTALL                           0 // OVERRIDE
#define PS_SPOOF_RGBA8_AS_UINT32_OFF                                   0x00000000
#define PS_SPOOF_RGBA8_AS_UINT32_DISABLED                              0x00000000
#define PS_SPOOF_RGBA8_AS_UINT32_ON                                    0x00000001
#define PS_SPOOF_RGBA8_AS_UINT32_ENABLED                               0x00000001


#define PS_SSV_REVERSAL_STRING                                         "30500027"
#define PS_SSV_REVERSAL_ID                                             0x007be16a
#define PS_SSV_REVERSAL_OVERINSTALL                                    0 // OVERRIDE
#define PS_SSV_REVERSAL_OFF                                            0x82842504
#define PS_SSV_REVERSAL_DISABLED                                       0x82842504
#define PS_SSV_REVERSAL_ON                                             0x48169919
#define PS_SSV_REVERSAL_ENABLED                                        0x48169919


#define PS_STATE_OBJECT_FLAGS_STRING                                   "33b37fed"
#define PS_STATE_OBJECT_FLAGS_ID                                       0x0026bc21
#define PS_STATE_OBJECT_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_STATE_OBJECT_FLAGS_DISABLE                                  0x00000001
#define PS_STATE_OBJECT_FLAGS_NULL_SPECIALIZATION_HANDLE               0x00000002
#define PS_STATE_OBJECT_FLAGS_SKIP_APPLY_DEPENDENCIES                  0x00000004
#define PS_STATE_OBJECT_FLAGS_DEFAULT                                  0


#define PS_STATE_OBJECT_HASH_STRING                                    "636ed139"
#define PS_STATE_OBJECT_HASH_ID                                        0x00a282d8
#define PS_STATE_OBJECT_HASH_OVERINSTALL                               0 // OVERRIDE
#define PS_STATE_OBJECT_HASH_DEFAULT                                   0x0


#define PS_STATS_FILENAME_STRING                                       "87329924"
#define PS_STATS_FILENAME_ID                                           0x0027f984
#define PS_STATS_FILENAME_OVERINSTALL                                  0 // OVERRIDE


#define PS_STATS_FLAGS_STRING                                          "01192886"
#define PS_STATS_FLAGS_ID                                              0x00bd7e18
#define PS_STATS_FLAGS_OVERINSTALL                                     0 // OVERRIDE
#define PS_STATS_FLAGS_ALL_ALLOC                                       0x00000001
#define PS_STATS_FLAGS_HW_ALLOC                                        0x00000002
#define PS_STATS_FLAGS_INSTANCE_WORKING_SET                            0x00000004
#define PS_STATS_FLAGS_COMPRESSION_WORKING_SET                         0x00000004
#define PS_STATS_FLAGS_FRAME_WORKING_SET                               0x00000008
#define PS_STATS_FLAGS_WARNINGS_PER_FRAME                              0x00000010
#define PS_STATS_FLAGS_WARNINGS_GLOBAL                                 0x00000020
#define PS_STATS_FLAGS_WARNINGS_PER_DRAW                               0x00000040
#define PS_STATS_FLAGS_QMD_HEAP                                        0x00000100
#define PS_STATS_FLAGS_QMD_HISTOGRAM                                   0x00000200
#define PS_STATS_FLAGS_BENCHMARK_SYSTEM                                0x00001000
#define PS_STATS_FLAGS_DEFAULT                                         0


#define PS_STATS_WORKING_SET_FLAGS_STRING                              "03112787"
#define PS_STATS_WORKING_SET_FLAGS_ID                                  0x00297319
#define PS_STATS_WORKING_SET_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_DRAW                        0x00000001
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_CLEAR                       0x00000002
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_RESOLVE                     0x00000004
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_COPY                        0x00000008
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_UPDATE                      0x00000010
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_MAP                         0x00000020
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_PRESENT                     0x00000040
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_DISPATCH                    0x00000080
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_DEBUG_STATE                 0x01000000
#define PS_STATS_WORKING_SET_FLAGS_INCLUDE_NON_RENDERABLE              0x02000000
#define PS_STATS_WORKING_SET_FLAGS_DEFAULT                             PS_STATS_WORKING_SET_FLAGS_INCLUDE_DRAW


#define PS_STUTTERSTATS_STRING                                         "18323178"
#define PS_STUTTERSTATS_ID                                             0x0079b063
#define PS_STUTTERSTATS_OVERINSTALL                                    0 // OVERRIDE
#define PS_STUTTERSTATS_OFF                                            0x00000000
#define PS_STUTTERSTATS_DISABLED                                       0x00000000
#define PS_STUTTERSTATS_ON                                             0x00000001
#define PS_STUTTERSTATS_ENABLED                                        0x00000001


#define PS_STUTTERSTATS_FLAGS_STRING                                   "01692884"
#define PS_STUTTERSTATS_FLAGS_ID                                       0x002c0e32
#define PS_STUTTERSTATS_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_STUTTERSTATS_FLAGS_BM_TRACE                                 0x00000001
#define PS_STUTTERSTATS_FLAGS_DEFAULT_SHADER_TRACE                     0x00000002
#define PS_STUTTERSTATS_FLAGS_OPTIONAL_SHADER_TRACE                    0x00000004
#define PS_STUTTERSTATS_FLAGS_STALL_TRACE                              0x00000008
#define PS_STUTTERSTATS_FLAGS_KMD_TRACE                                0x00000010
#define PS_STUTTERSTATS_FLAGS_OUTOFORDER_TRACE                         0x00000020
#define PS_STUTTERSTATS_FLAGS_UPDATESUBRESOURCE_TRACE                  0x00000040
#define PS_STUTTERSTATS_FLAGS_DUMP_TO_DEBUGGER                         0x01000000
#define PS_STUTTERSTATS_FLAGS_SPARSE_STATS                             0x02000000
#define PS_STUTTERSTATS_FLAGS_ENABLE_ON_DWM                            0x04000000


#define PS_STUTTERSTATS_HOTKEY_STRING                                  "01694444"
#define PS_STUTTERSTATS_HOTKEY_ID                                      0x002c2222
#define PS_STUTTERSTATS_HOTKEY_OVERINSTALL                             0 // OVERRIDE
#define PS_STUTTERSTATS_HOTKEY_DEFAULT                                 0x75


#define PS_STUTTERSTATS_THRESHOLD_STRING                               "01694443"
#define PS_STUTTERSTATS_THRESHOLD_ID                                   0x002c2221
#define PS_STUTTERSTATS_THRESHOLD_OVERINSTALL                          0 // OVERRIDE
#define PS_STUTTERSTATS_THRESHOLD_DEFAULT                              0.0


#define PS_SUPERSCHMOO_STRING                                          "2af47821"
#define PS_SUPERSCHMOO_ID                                              0x00128f3a
#define PS_SUPERSCHMOO_OVERINSTALL                                     0 // OVERRIDE
#define PS_SUPERSCHMOO_OFF                                             0x00000000
#define PS_SUPERSCHMOO_DISABLED                                        0x00000000
#define PS_SUPERSCHMOO_ON                                              0x00000001
#define PS_SUPERSCHMOO_ENABLED                                         0x00000001
#define PS_SUPERSCHMOO_DEFAULT                                         PS_SUPERSCHMOO_OFF


#define PS_SUPERSCHMOO_CONFIG_FILE_STRING                              "2ae47822"
#define PS_SUPERSCHMOO_CONFIG_FILE_ID                                  0x00128e3b
#define PS_SUPERSCHMOO_CONFIG_FILE_OVERINSTALL                         0 // OVERRIDE


#define PS_SUPERTRIVS_STRING                                           "34048747"
#define PS_SUPERTRIVS_ID                                               0x0083cb94
#define PS_SUPERTRIVS_OVERINSTALL                                      0 // OVERRIDE
#define PS_SUPERTRIVS_OFF                                              0x19377544
#define PS_SUPERTRIVS_DISABLED                                         0x19377544
#define PS_SUPERTRIVS_ON                                               0x83460489
#define PS_SUPERTRIVS_ENABLED                                          0x83460489


#define PS_SUPERTRIVS_ALLOW_STRING                                     "11773538"
#define PS_SUPERTRIVS_ALLOW_ID                                         0x005c8dfe
#define PS_SUPERTRIVS_ALLOW_OVERINSTALL                                0 // OVERRIDE
#define PS_SUPERTRIVS_ALLOW_ALLOW_REJECT_CULL_NONE                     0x00000001
#define PS_SUPERTRIVS_ALLOW_ALLOW_NO_LOADBALANCE                       0x00000002
#define PS_SUPERTRIVS_ALLOW_ALLOW_BBOX_ONLY_CULL                       0x00000004
#define PS_SUPERTRIVS_ALLOW_ALLOW_ASYNC_ONLY                           0x00000008
#define PS_SUPERTRIVS_ALLOW_ALLOW_USE_ASM                              0x00000010
#define PS_SUPERTRIVS_ALLOW_ALLOW_ONLY_FRUSTUM                         0x00000020
#define PS_SUPERTRIVS_ALLOW_DISABLE_SSE_MATH_FUNCTIONS                 0x00000080


#define PS_SUPERTRIVS_FRAMESAHEADSCALAR0_STRING                        "27141217"
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR0_ID                            0x007b0e10
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR0_OVERINSTALL                   0 // OVERRIDE


#define PS_SUPERTRIVS_FRAMESAHEADSCALAR1_STRING                        "28308937"
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR1_ID                            0x00964aac
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR1_OVERINSTALL                   0 // OVERRIDE


#define PS_SUPERTRIVS_FRAMESAHEADSCALAR2_STRING                        "39499901"
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR2_ID                            0x00bc14a1
#define PS_SUPERTRIVS_FRAMESAHEADSCALAR2_OVERINSTALL                   0 // OVERRIDE


#define PS_SUPERTRIVS_MAXPRIM_STRING                                   "90348218"
#define PS_SUPERTRIVS_MAXPRIM_ID                                       0x004e2891
#define PS_SUPERTRIVS_MAXPRIM_OVERINSTALL                              0 // OVERRIDE


#define PS_SUPERTRIVS_MINPRIM_STRING                                   "65900237"
#define PS_SUPERTRIVS_MINPRIM_ID                                       0x009ba0d3
#define PS_SUPERTRIVS_MINPRIM_OVERINSTALL                              0 // OVERRIDE


#define PS_SUPERTRIVS_STATS_FLAGS_STRING                               "24667454"
#define PS_SUPERTRIVS_STATS_FLAGS_ID                                   0x00ffad71
#define PS_SUPERTRIVS_STATS_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define PS_SUPERTRIVS_STATS_FLAGS_DUMP_STATS                           0x00000001
#define PS_SUPERTRIVS_STATS_FLAGS_DUMP_FLAGS                           0x40000000
#define PS_SUPERTRIVS_STATS_FLAGS_DUMP_DIRECTIONS                      0x80000000


#define PS_SUPERTRIVS_THRESH_STRING                                    "84647684"
#define PS_SUPERTRIVS_THRESH_ID                                        0x0032c456
#define PS_SUPERTRIVS_THRESH_OVERINSTALL                               0 // OVERRIDE


#define PS_SURFACESTATS_STRING                                         "02334891"
#define PS_SURFACESTATS_ID                                             0x0092b670
#define PS_SURFACESTATS_OVERINSTALL                                    0 // OVERRIDE
#define PS_SURFACESTATS_OFF                                            0x78463528
#define PS_SURFACESTATS_0                                              0x78463528
#define PS_SURFACESTATS_FALSE                                          0x78463528
#define PS_SURFACESTATS_DISABLED                                       0x78463528
#define PS_SURFACESTATS_ON                                             0x92347647
#define PS_SURFACESTATS_1                                              0x92347647
#define PS_SURFACESTATS_TRUE                                           0x92347647
#define PS_SURFACESTATS_ENABLED                                        0x92347647


#define PS_SURFACESTATS_FLAGS_STRING                                   "07293859"
#define PS_SURFACESTATS_FLAGS_ID                                       0x007506e8
#define PS_SURFACESTATS_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define PS_SURFACESTATS_FLAGS_DUMP_VBS                                 0x00000001
#define PS_SURFACESTATS_FLAGS_DUMP_IBS                                 0x00000002
#define PS_SURFACESTATS_FLAGS_DUMP_RTS                                 0x00000004
#define PS_SURFACESTATS_FLAGS_DUMP_ZBS                                 0x00000008
#define PS_SURFACESTATS_FLAGS_DUMP_TEX                                 0x00000010


#define PS_SURFACESTATS_MAX_STRING                                     "83820211"
#define PS_SURFACESTATS_MAX_ID                                         0x001fb410
#define PS_SURFACESTATS_MAX_OVERINSTALL                                0 // OVERRIDE


#define PS_SURFACE_PLACEMENT_STRING                                    "58027529"
#define PS_SURFACE_PLACEMENT_ID                                        0x00f21052
#define PS_SURFACE_PLACEMENT_OVERINSTALL                               0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_OFF                                       0x75032831
#define PS_SURFACE_PLACEMENT_DISABLED                                  0x75032831
#define PS_SURFACE_PLACEMENT_ON                                        0x91205621
#define PS_SURFACE_PLACEMENT_ENABLED                                   0x91205621


#define PS_SURFACE_PLACEMENT_ALLOW_STRING                              "19278264"
#define PS_SURFACE_PLACEMENT_ALLOW_ID                                  0x0090f680
#define PS_SURFACE_PLACEMENT_ALLOW_OVERINSTALL                         0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_ALLOW_VB_FORCE_HOSTMEM                    0x00000001
#define PS_SURFACE_PLACEMENT_ALLOW_VB_FORCE_VIDMEM                     0x00000002
#define PS_SURFACE_PLACEMENT_ALLOW_VB_FORCE_CPUVISIBLE                 0x00000004
#define PS_SURFACE_PLACEMENT_ALLOW_VB_FORCE_LOCKABLE_CPUVISIBLE        0x00000008
#define PS_SURFACE_PLACEMENT_ALLOW_VB_FORCE_MASK                       0x0000000F
#define PS_SURFACE_PLACEMENT_ALLOW_VB_STATIC_PREFERS_HOSTMEM           0x00000010
#define PS_SURFACE_PLACEMENT_ALLOW_VB_STATIC_PREFERS_VIDMEM            0x00000020
#define PS_SURFACE_PLACEMENT_ALLOW_VB_STATIC_PREFERS_MASK              0x00000030
#define PS_SURFACE_PLACEMENT_ALLOW_VB_WRITEONLY_PREFERS_HOSTMEM        0x00000040
#define PS_SURFACE_PLACEMENT_ALLOW_VB_WRITEONLY_PREFERS_VIDMEM         0x00000080
#define PS_SURFACE_PLACEMENT_ALLOW_VB_WRITEONLY_PREFERS_MASK           0x000000C0
#define PS_SURFACE_PLACEMENT_ALLOW_VB_ALLOW_MASK                       0x000000FF
#define PS_SURFACE_PLACEMENT_ALLOW_IB_FORCE_HOSTMEM                    0x00000100
#define PS_SURFACE_PLACEMENT_ALLOW_IB_FORCE_VIDMEM                     0x00000200
#define PS_SURFACE_PLACEMENT_ALLOW_IB_FORCE_MASK                       0x00000300
#define PS_SURFACE_PLACEMENT_ALLOW_IB_PREFERS_HOSTMEM                  0x00000400
#define PS_SURFACE_PLACEMENT_ALLOW_IB_PREFERS_VIDMEM                   0x00000800
#define PS_SURFACE_PLACEMENT_ALLOW_IB_PREFERS_MASK                     0x00000C00
#define PS_SURFACE_PLACEMENT_ALLOW_TX_FORCE_HOSTMEM                    0x00001000
#define PS_SURFACE_PLACEMENT_ALLOW_TX_FORCE_VIDMEM                     0x00002000
#define PS_SURFACE_PLACEMENT_ALLOW_TX_FORCE_MASK                       0x00003000
#define PS_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_HOSTMEM                  0x00004000
#define PS_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_VIDMEM                   0x00008000
#define PS_SURFACE_PLACEMENT_ALLOW_TX_PREFERS_MASK                     0x0000C000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_FORCE_HOSTMEM                    0x00010000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_FORCE_VIDMEM                     0x00020000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_FORCE_MASK                       0x00030000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_HOSTMEM                  0x00040000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_VIDMEM                   0x00080000
#define PS_SURFACE_PLACEMENT_ALLOW_RT_PREFERS_MASK                     0x000C0000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_FORCE_HOSTMEM                     0x00100000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_FORCE_VIDMEM                      0x00200000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_FORCE_MASK                        0x00300000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_HOSTMEM                   0x00400000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_VIDMEM                    0x00800000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_MASK                      0x00C00000
#define PS_SURFACE_PLACEMENT_ALLOW_Z_PREFERS_BOTH                      0x00C00000
#define PS_SURFACE_PLACEMENT_ALLOW_PB_FORCE_HOSTMEM                    0x01000000
#define PS_SURFACE_PLACEMENT_ALLOW_PB_FORCE_VIDMEM                     0x02000000
#define PS_SURFACE_PLACEMENT_ALLOW_PB_FORCE_MASK                       0x03000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_FORCE_INCLUDE_Z                  0x04000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_FORCE_ALL_HEAPS                  0x08000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_USE_NONE                         0x10000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_USE_2V                           0x20000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_USE_2H                           0x40000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_USE_4                            0x80000000
#define PS_SURFACE_PLACEMENT_ALLOW_SP_MASK                             0xFC000000
#define PS_SURFACE_PLACEMENT_ALLOW_DEFAULT                             0x00000000


#define PS_SURFACE_PLACEMENT_ATTRIB_STRING                             "09293473"
#define PS_SURFACE_PLACEMENT_ATTRIB_ID                                 0x009f7a61
#define PS_SURFACE_PLACEMENT_ATTRIB_OVERINSTALL                        0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_ATTRIB_DISABLE_FOS_ON_FLIP_CHAIN          0x00000001
#define PS_SURFACE_PLACEMENT_ATTRIB_ENABLE_ZCOMPRESSION_ON_RTT         0x00000002
#define PS_SURFACE_PLACEMENT_ATTRIB_ENABLE_ZCULL_ON_RTT                0x00000004
#define PS_SURFACE_PLACEMENT_ATTRIB_PCIE_X1                            0x00000010
#define PS_SURFACE_PLACEMENT_ATTRIB_SLOW_MRT_REPLAY_WAR                0x00010000


#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_STRING                   "00620BAC"
#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_ID                       0x000f0bac
#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_OVERINSTALL              0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_OFF                      0x00000000
#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_ON                       0x00000001
#define PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_DEFAULT                  PS_SURFACE_PLACEMENT_BAR1_REPORT_MAPS_OFF


#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_STRING                   "75137491"
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_ID                       0x006bdd49
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_OVERINSTALL              0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_HIGH            0x187F7082
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_MAXIMUM         0x83B7BC1A
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_MAXIMUM_IF_MIXED_BUS 0xFC17F610
#define PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_DEFAULT                  PS_SURFACE_PLACEMENT_HIGHEST_PRIORITY_PRIORITY_HIGH


#define PS_SURFACE_PLACEMENT_PROMOTION_STRING                          "17294461"
#define PS_SURFACE_PLACEMENT_PROMOTION_ID                              0x009e7462
#define PS_SURFACE_PLACEMENT_PROMOTION_OVERINSTALL                     0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_PROMOTION_DISABLE_DYNAMIC_VB_PROMOTION    0x00000001
#define PS_SURFACE_PLACEMENT_PROMOTION_DISABLE_STATIC_VB_PROMOTION     0x00000002
#define PS_SURFACE_PLACEMENT_PROMOTION_DISABLE_RW_IB_PROMOTION         0x00000004
#define PS_SURFACE_PLACEMENT_PROMOTION_DISABLE_W_IB_PROMOTION          0x00000008
#define PS_SURFACE_PLACEMENT_PROMOTION_DEFAULT                         PS_SURFACE_PLACEMENT_PROMOTION_DISABLE_RW_IB_PROMOTION


#define PS_SURFACE_PLACEMENT_STATS_STRING                              "46208492"
#define PS_SURFACE_PLACEMENT_STATS_ID                                  0x002b05bc
#define PS_SURFACE_PLACEMENT_STATS_OVERINSTALL                         0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_STATS_OFF                                 0x00000000
#define PS_SURFACE_PLACEMENT_STATS_DISABLED                            0x00000000
#define PS_SURFACE_PLACEMENT_STATS_ON                                  0x00000001
#define PS_SURFACE_PLACEMENT_STATS_ENABLED                             0x00000001


#define PS_SURFACE_PLACEMENT_STATS_FLAGS_STRING                        "19278364"
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_ID                            0x00e3d86c
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_OVERINSTALL                   0 // OVERRIDE
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_SURFPLACE_DUMP_VB_STATS       0x00000001
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_SURFPLACE_DUMP_IB_STATS       0x00000002
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_SURFPLACE_DUMP_TX_STATS       0x00000004
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_SURFPLACE_DUMP_RT_STATS       0x00000008
#define PS_SURFACE_PLACEMENT_STATS_FLAGS_SURFPLACE_DUMP_Z_STATS        0x00000010


#define PS_SYSTEMCHECK_STRING                                          "afdead13"
#define PS_SYSTEMCHECK_ID                                              0x00d02e1d
#define PS_SYSTEMCHECK_OVERINSTALL                                     0 // OVERRIDE
#define PS_SYSTEMCHECK_OFF                                             0x52aebf3d
#define PS_SYSTEMCHECK_DISABLED                                        0x52aebf3d
#define PS_SYSTEMCHECK_ON                                              0xde8f1a66
#define PS_SYSTEMCHECK_ENABLED                                         0xde8f1a66


#define PS_SYSTEMCHECK_FLAGS_STRING                                    "afdead14"
#define PS_SYSTEMCHECK_FLAGS_ID                                        0x009c010e
#define PS_SYSTEMCHECK_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_SYSTEMCHECK_FLAGS_MEASURE_COLOR_BANDWIDTH                   0x00000001
#define PS_SYSTEMCHECK_FLAGS_MEASURE_DEPTH_BANDWIDTH                   0x00000002
#define PS_SYSTEMCHECK_FLAGS_MEASURE_KICKOFF_PERF                      0x00000010
#define PS_SYSTEMCHECK_FLAGS_MEASURE_BATCHED_ALLOC_PERF                0x00000100
#define PS_SYSTEMCHECK_FLAGS_MEASURE_INTERLEAVED_ALLOC_PERF            0x00000200
#define PS_SYSTEMCHECK_FLAGS_MEASURE_TEX_LATENCY                       0x00001000


#define PS_SYSVBOPT_STRING                                             "d13733f16"
#define PS_SYSVBOPT_ID                                                 0x00dd5fa3
#define PS_SYSVBOPT_OVERINSTALL                                        0 // OVERRIDE
#define PS_SYSVBOPT_OFF                                                0x00000000
#define PS_SYSVBOPT_DISABLED                                           0x00000000
#define PS_SYSVBOPT_ON                                                 0x00000001
#define PS_SYSVBOPT_ENABLED                                            0x00000001


#define PS_TEXCOMPRESS_STRING                                          "33857441"
#define PS_TEXCOMPRESS_ID                                              0x008388ee
#define PS_TEXCOMPRESS_OVERINSTALL                                     0 // OVERRIDE
#define PS_TEXCOMPRESS_OFF                                             0x44933872
#define PS_TEXCOMPRESS_DISABLED                                        0x44933872
#define PS_TEXCOMPRESS_ON                                              0x10098834
#define PS_TEXCOMPRESS_ENABLED                                         0x10098834


#define PS_TEXCOMPRESS_ALLOW_STRING                                    "49376530"
#define PS_TEXCOMPRESS_ALLOW_ID                                        0x00b36185
#define PS_TEXCOMPRESS_ALLOW_OVERINSTALL                               0 // OVERRIDE
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT3TO1_ONPSHAD                     0x00000001
#define PS_TEXCOMPRESS_ALLOW_FORCE_DXT3TO1_ONPSHAD                     0x00000002
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT3TO1_ONBLT_DEFAULT_ALPHA         0x00000004
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT3TO1_ONBLT_ANYALPHA              0x00000008
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT5TO1_ONPSHAD                     0x00000010
#define PS_TEXCOMPRESS_ALLOW_FORCE_DXT5TO1_ONPSHAD                     0x00000020
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT5TO1_ONBLT_DEFAULT_ALPHA         0x00000040
#define PS_TEXCOMPRESS_ALLOW_ALLOW_DXT5TO1_ONBLT_ANYALPHA              0x00000080
#define PS_TEXCOMPRESS_ALLOW_ALLOW_ARGBTODXT5                          0x00000100
#define PS_TEXCOMPRESS_ALLOW_ALLOW_CUBEMAP_DXTATO1                     0x00010000


#define PS_TEXCOMPRESS_STATS_STRING                                    "49376531"
#define PS_TEXCOMPRESS_STATS_ID                                        0x00864e77
#define PS_TEXCOMPRESS_STATS_OVERINSTALL                               0 // OVERRIDE
#define PS_TEXCOMPRESS_STATS_OFF                                       0x00000000
#define PS_TEXCOMPRESS_STATS_DISABLED                                  0x00000000
#define PS_TEXCOMPRESS_STATS_ON                                        0x00000001
#define PS_TEXCOMPRESS_STATS_ENABLED                                   0x00000001


#define PS_TEXFILTER_STRING                                            "12621688"
#define PS_TEXFILTER_ID                                                0x00e8e235
#define PS_TEXFILTER_OVERINSTALL                                       0 // OVERRIDE
#define PS_TEXFILTER_OFF                                               0x96569555
#define PS_TEXFILTER_DISABLED                                          0x96569555
#define PS_TEXFILTER_ON                                                0x95104604
#define PS_TEXFILTER_ENABLED                                           0x95104604


#define PS_TEXFILTER_12X_TRISLOPE_STRING                               "10432215"
#define PS_TEXFILTER_12X_TRISLOPE_ID                                   0x004e8861
#define PS_TEXFILTER_12X_TRISLOPE_OVERINSTALL                          0 // OVERRIDE


#define PS_TEXFILTER_16X_TRISLOPE_STRING                               "35725197"
#define PS_TEXFILTER_16X_TRISLOPE_ID                                   0x0018a6d7
#define PS_TEXFILTER_16X_TRISLOPE_OVERINSTALL                          0 // OVERRIDE


#define PS_TEXFILTER_1X_TRISLOPE_STRING                                "97442978"
#define PS_TEXFILTER_1X_TRISLOPE_ID                                    0x0019d6d9
#define PS_TEXFILTER_1X_TRISLOPE_OVERINSTALL                           0 // OVERRIDE


#define PS_TEXFILTER_2X_TRISLOPE_STRING                                "44648998"
#define PS_TEXFILTER_2X_TRISLOPE_ID                                    0x007b19b9
#define PS_TEXFILTER_2X_TRISLOPE_OVERINSTALL                           0 // OVERRIDE


#define PS_TEXFILTER_4X_TRISLOPE_STRING                                "04435985"
#define PS_TEXFILTER_4X_TRISLOPE_ID                                    0x00ef7d01
#define PS_TEXFILTER_4X_TRISLOPE_OVERINSTALL                           0 // OVERRIDE


#define PS_TEXFILTER_6X_TRISLOPE_STRING                                "32535779"
#define PS_TEXFILTER_6X_TRISLOPE_ID                                    0x0064774e
#define PS_TEXFILTER_6X_TRISLOPE_OVERINSTALL                           0 // OVERRIDE


#define PS_TEXFILTER_8X_TRISLOPE_STRING                                "57301419"
#define PS_TEXFILTER_8X_TRISLOPE_ID                                    0x0024c09b
#define PS_TEXFILTER_8X_TRISLOPE_OVERINSTALL                           0 // OVERRIDE


#define PS_TEXFILTER_ALLOW_STRING                                      "04301809"
#define PS_TEXFILTER_ALLOW_ID                                          0x00f1b013
#define PS_TEXFILTER_ALLOW_OVERINSTALL                                 0 // OVERRIDE
#define PS_TEXFILTER_ALLOW_ALLOW_TRILINEAR_SLOPE                       0x00000001
#define PS_TEXFILTER_ALLOW_ALLOW_FORCE_BILINEAR                        0x00000002
#define PS_TEXFILTER_ALLOW_ALLOW_ANISO_BIAS                            0x00000004
#define PS_TEXFILTER_ALLOW_ALLOW_TEXTURE_ANALYSIS                      0x00000008
#define PS_TEXFILTER_ALLOW_ALLOW_ANISO_SAMPLE_STEPPING2                0x00000010
#define PS_TEXFILTER_ALLOW_ALLOW_DISABLE_ANISO_SHADOWMAPS              0x00000020
#define PS_TEXFILTER_ALLOW_ALLOW_BILINEAR_IN_ANISO_STAGE1              0x00000040
#define PS_TEXFILTER_ALLOW_ALLOW_BILINEAR_IN_ANISO_STAGE0              0x00000080
#define PS_TEXFILTER_ALLOW_ALLOW_LIMIT_ANISO_FOR_CUBEMAPS              0x00000100
#define PS_TEXFILTER_ALLOW_ALLOW_LIMIT_BEST_CHOICE_TRILINEAR           0x00008000
#define PS_TEXFILTER_ALLOW_ALLOW_NO_CPL_OVERRIDE_NONMIPMAPPED          0x00200000
#define PS_TEXFILTER_ALLOW_ALLOW_NO_ANISO_1D_TEXTURES                  0x00400000
#define PS_TEXFILTER_ALLOW_ALLOW_LIMIT_ANISO_NONMIPMAPPED              0x00800000
#define PS_TEXFILTER_ALLOW_ALLOW_SET_MAX_KNOB3                         0x40000000


#define PS_TEXFILTER_ANISO_LOD_QUALITY_STRING                          "05681204"
#define PS_TEXFILTER_ANISO_LOD_QUALITY_ID                              0x00b4d451
#define PS_TEXFILTER_ANISO_LOD_QUALITY_OVERINSTALL                     0 // OVERRIDE
#define PS_TEXFILTER_ANISO_LOD_QUALITY_LOW                             0x00000000
#define PS_TEXFILTER_ANISO_LOD_QUALITY_0                               0x00000000
#define PS_TEXFILTER_ANISO_LOD_QUALITY_HIGH                            0x00000001
#define PS_TEXFILTER_ANISO_LOD_QUALITY_1                               0x00000001


#define PS_TEXFILTER_ANISO_OPTS2_STRING                                "30913648"
#define PS_TEXFILTER_ANISO_OPTS2_ID                                    0x00e73211
#define PS_TEXFILTER_ANISO_OPTS2_OVERINSTALL                           1 // MERGE
#define PS_TEXFILTER_ANISO_OPTS2_OFF                                   0x00000000
#define PS_TEXFILTER_ANISO_OPTS2_DISABLED                              0x00000000
#define PS_TEXFILTER_ANISO_OPTS2_ON                                    0x00000001
#define PS_TEXFILTER_ANISO_OPTS2_ENABLED                               0x00000001
#define PS_TEXFILTER_ANISO_OPTS2_DEFAULT                               PS_TEXFILTER_ANISO_OPTS2_OFF


#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_STRING                   "aa847634"
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_ID                       0x009f2a39
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_OVERINSTALL              0 // OVERRIDE
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_HALF                     0x00000000
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_ONE                      0x00000001
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_TWO                      0x00000002
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_FUNC_MAX                      0x00000003


#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_STRING               "aa253015"
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_ID                   0x00845312
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_OVERINSTALL          0 // OVERRIDE
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_NONE                 0x00000000
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_ONE                  0x00000001
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_TWO                  0x00000002
#define PS_TEXFILTER_ANISO_SPREAD_COARSE_MODIFIER_SQRT                 0x00000003


#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_STRING                     "aa726430"
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_ID                         0x0027ef20
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_OVERINSTALL                0 // OVERRIDE
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_HALF                       0x00000000
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_ONE                        0x00000001
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_TWO                        0x00000002
#define PS_TEXFILTER_ANISO_SPREAD_FINE_FUNC_MAX                        0x00000003


#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_STRING                 "aa881871"
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_ID                     0x00afbee7
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_OVERINSTALL            0 // OVERRIDE
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_NONE                   0x00000000
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_ONE                    0x00000001
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_TWO                    0x00000002
#define PS_TEXFILTER_ANISO_SPREAD_FINE_MODIFIER_SQRT                   0x00000003


#define PS_TEXFILTER_ANISO_SPREAD_SCALE_STRING                         "aa901110"
#define PS_TEXFILTER_ANISO_SPREAD_SCALE_ID                             0x00ae3716
#define PS_TEXFILTER_ANISO_SPREAD_SCALE_OVERINSTALL                    0 // OVERRIDE
#define PS_TEXFILTER_ANISO_SPREAD_SCALE_MIN                            0x00
#define PS_TEXFILTER_ANISO_SPREAD_SCALE_MAX                            0x1f


#define PS_TEXFILTER_BILINEAR_IN_ANISO_STRING                          "40792312"
#define PS_TEXFILTER_BILINEAR_IN_ANISO_ID                              0x0084cd70
#define PS_TEXFILTER_BILINEAR_IN_ANISO_OVERINSTALL                     1 // MERGE
#define PS_TEXFILTER_BILINEAR_IN_ANISO_OFF                             0x00000000
#define PS_TEXFILTER_BILINEAR_IN_ANISO_DISABLED                        0x00000000
#define PS_TEXFILTER_BILINEAR_IN_ANISO_ON                              0x00000001
#define PS_TEXFILTER_BILINEAR_IN_ANISO_ENABLED                         0x00000001
#define PS_TEXFILTER_BILINEAR_IN_ANISO_DEFAULT                         PS_TEXFILTER_BILINEAR_IN_ANISO_OFF


#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_STRING                       "94118636"
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ID                           0x002ecaf2
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_OVERINSTALL                  1 // MERGE
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_OFF                          0x00000000
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_DISABLED                     0x00000000
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ON                           0x00000001
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_ENABLED                      0x00000001
#define PS_TEXFILTER_DISABLE_TRILIN_SLOPE_DEFAULT                      PS_TEXFILTER_DISABLE_TRILIN_SLOPE_OFF


#define PS_TEXFILTER_ISO_LOD_QUALITY_STRING                            "66600131"
#define PS_TEXFILTER_ISO_LOD_QUALITY_ID                                0x006b515e
#define PS_TEXFILTER_ISO_LOD_QUALITY_OVERINSTALL                       0 // OVERRIDE
#define PS_TEXFILTER_ISO_LOD_QUALITY_LOW                               0x00000000
#define PS_TEXFILTER_ISO_LOD_QUALITY_0                                 0x00000000
#define PS_TEXFILTER_ISO_LOD_QUALITY_HIGH                              0x00000001
#define PS_TEXFILTER_ISO_LOD_QUALITY_1                                 0x00000001


#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_STRING              "fa302c"
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_ID                  0x00fa302c
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_OVERINSTALL         0 // OVERRIDE
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_OFF                 0x00000000
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_DISABLED            0x00000000
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_ON                  0x00000001
#define PS_TEXFILTER_KEPLER_FIXUP_UNOPT_LOD_SPREAD_ENABLED             0x00000001


#define PS_TEXFILTER_NO_NEG_LODBIAS_STRING                             "16579523"
#define PS_TEXFILTER_NO_NEG_LODBIAS_ID                                 0x0019bb68
#define PS_TEXFILTER_NO_NEG_LODBIAS_OVERINSTALL                        1 // MERGE
#define PS_TEXFILTER_NO_NEG_LODBIAS_OFF                                0x00000000
#define PS_TEXFILTER_NO_NEG_LODBIAS_DISABLED                           0x00000000
#define PS_TEXFILTER_NO_NEG_LODBIAS_ON                                 0x00000001
#define PS_TEXFILTER_NO_NEG_LODBIAS_ENABLED                            0x00000001
#define PS_TEXFILTER_NO_NEG_LODBIAS_DEFAULT                            PS_TEXFILTER_NO_NEG_LODBIAS_OFF


#define PS_TEXFILTER_STATS_STRING                                      "25707224"
#define PS_TEXFILTER_STATS_ID                                          0x000b69c2
#define PS_TEXFILTER_STATS_OVERINSTALL                                 0 // OVERRIDE
#define PS_TEXFILTER_STATS_OFF                                         0x00000000
#define PS_TEXFILTER_STATS_DISABLED                                    0x00000000
#define PS_TEXFILTER_STATS_ON                                          0x00000001
#define PS_TEXFILTER_STATS_ENABLED                                     0x00000001


#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_STRING                       "31232579"
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_ID                           0x00800636
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_OVERINSTALL                  0 // OVERRIDE
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_OFF                          0x00000000
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_DISABLED                     0x00000000
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_ON                           0x00000001
#define PS_TEXFILTER_USE_HIGH_QUALITY_LOD_ENABLED                      0x00000001


#define PS_TEXTURE_FORCE_REP_CPULOCK_STRING                            "74356788"
#define PS_TEXTURE_FORCE_REP_CPULOCK_ID                                0x00255f4a
#define PS_TEXTURE_FORCE_REP_CPULOCK_OVERINSTALL                       0 // OVERRIDE
#define PS_TEXTURE_FORCE_REP_CPULOCK_USE_DRIVER_DEFAULT                0x00000000
#define PS_TEXTURE_FORCE_REP_CPULOCK_FORCE_ENABLE                      0x00000001
#define PS_TEXTURE_FORCE_REP_CPULOCK_FORCE_DISABLE                     0x00000002
#define PS_TEXTURE_FORCE_REP_CPULOCK_MIN                               0x00000000
#define PS_TEXTURE_FORCE_REP_CPULOCK_MAX                               0x00000002
#define PS_TEXTURE_FORCE_REP_CPULOCK_DEFAULT                           PS_TEXTURE_FORCE_REP_CPULOCK_USE_DRIVER_DEFAULT
#define PS_TEXTURE_FORCE_REP_CPULOCK_DEFAULT_GL                        PS_TEXTURE_FORCE_REP_CPULOCK_FORCE_DISABLE


#define PS_TEXTURE_MIRROR_STRING                                       "61015940"
#define PS_TEXTURE_MIRROR_ID                                           0x009edea3
#define PS_TEXTURE_MIRROR_OVERINSTALL                                  0 // OVERRIDE
#define PS_TEXTURE_MIRROR_OFF                                          0x46923917
#define PS_TEXTURE_MIRROR_DISABLED                                     0x46923917
#define PS_TEXTURE_MIRROR_ON                                           0x23257121
#define PS_TEXTURE_MIRROR_ENABLED                                      0x23257121


#define PS_TEXTURE_MIRROR_FLAGS_STRING                                 "21455190"
#define PS_TEXTURE_MIRROR_FLAGS_ID                                     0x002036a7
#define PS_TEXTURE_MIRROR_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COPY_FORCE_NONE                    0x00000000
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COPY_FORCE_VID                     0x00000001
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COPY_FORCE_HOST                    0x00000002
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COLORFILL_FORCE_NONE               0x00000000
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COLORFILL_FORCE_VID                0x00000100
#define PS_TEXTURE_MIRROR_FLAGS_TEX_COLORFILL_FORCE_HOST               0x00000200


#define PS_TEXTURE_PLACEMENT_BANDWIDTH_THRESHOLD_STRING                "74852146"
#define PS_TEXTURE_PLACEMENT_BANDWIDTH_THRESHOLD_ID                    0x003846a7
#define PS_TEXTURE_PLACEMENT_BANDWIDTH_THRESHOLD_OVERINSTALL           0 // OVERRIDE


#define PS_TIMESTAMPS_AGGREGATOR_FLAGS_STRING                          "64183459"
#define PS_TIMESTAMPS_AGGREGATOR_FLAGS_ID                              0x009af3a3
#define PS_TIMESTAMPS_AGGREGATOR_FLAGS_OVERINSTALL                     0 // OVERRIDE
#define PS_TIMESTAMPS_AGGREGATOR_FLAGS_ENABLE_TIMING                   0x00000001
#define PS_TIMESTAMPS_AGGREGATOR_FLAGS_ENABLE_LOG                      0x00000002


#define PS_UCO_STRING                                                  "4F5C9CD0"
#define PS_UCO_ID                                                      0x001ba354
#define PS_UCO_OVERINSTALL                                             0 // OVERRIDE
#define PS_UCO_OFF                                                     0x18F3902C
#define PS_UCO_DISABLED                                                0x18F3902C
#define PS_UCO_ON                                                      0x18F3902D
#define PS_UCO_ENABLED                                                 0x18F3902D
#define PS_UCO_DEFAULT                                                 PS_UCO_ON


#define PS_UCODE_SHADER_DUMP_STRING                                    "09ff012e"
#define PS_UCODE_SHADER_DUMP_ID                                        0x005e03cf
#define PS_UCODE_SHADER_DUMP_OVERINSTALL                               0 // OVERRIDE
#define PS_UCODE_SHADER_DUMP_OFF                                       0x32545116
#define PS_UCODE_SHADER_DUMP_DISABLED                                  0x32545116
#define PS_UCODE_SHADER_DUMP_ON                                        0x43241846
#define PS_UCODE_SHADER_DUMP_ENABLED                                   0x43241846


#define PS_UCODE_SHADER_DUMP_FLAGS_STRING                              "09ff012f"
#define PS_UCODE_SHADER_DUMP_FLAGS_ID                                  0x005e03de
#define PS_UCODE_SHADER_DUMP_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_UCODE_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS             0x00000008
#define PS_UCODE_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER       0x00080000
#define PS_UCODE_SHADER_DUMP_FLAGS_DELAY_UNTIL_HOTKEY_THEN_CAPTURE_SINGLE_FRAME_THEN_EXIT 0x10000000
#define PS_UCODE_SHADER_DUMP_FLAGS_DELAY_UNTIL_HOTKEY_THEN_CAPTURE_UNTIL_HOTKEY_THEN_EXIT 0x20000000


#define PS_UCO_FLAGS_STRING                                            "1AA784D5"
#define PS_UCO_FLAGS_ID                                                0x00630112
#define PS_UCO_FLAGS_OVERINSTALL                                       0 // OVERRIDE
#define PS_UCO_FLAGS_ENABLE_LOW_LATENCY                                0x00000001
#define PS_UCO_FLAGS_DEFAULT                                           0


#define PS_UNIFORM_TEX_STRING                                          "44597413"
#define PS_UNIFORM_TEX_ID                                              0x00f62469
#define PS_UNIFORM_TEX_OVERINSTALL                                     0 // OVERRIDE
#define PS_UNIFORM_TEX_OFF                                             0x00000000
#define PS_UNIFORM_TEX_DISABLED                                        0x00000000
#define PS_UNIFORM_TEX_ON                                              0x00000001
#define PS_UNIFORM_TEX_ENABLED                                         0x00000001
#define PS_UNIFORM_TEX_DEFAULT                                         PS_UNIFORM_TEX_ON


#define PS_UNIFORM_TEX_FLAGS_STRING                                    "44597421"
#define PS_UNIFORM_TEX_FLAGS_ID                                        0x00e31256
#define PS_UNIFORM_TEX_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_UNIFORM_TEX_FLAGS_DISABLE_STAGED_ANALYSIS                   0x00000001
#define PS_UNIFORM_TEX_FLAGS_DISABLE_DYNAMIC_ANALYSIS                  0x00000002
#define PS_UNIFORM_TEX_FLAGS_DISABLE_BORDER_ADDRESSING_CHECK           0x00000004
#define PS_UNIFORM_TEX_FLAGS_RESTRICT_TO_ZERO                          0x00000008
#define PS_UNIFORM_TEX_FLAGS_DISABLE_BC_SUPPORT                        0x00000010
#define PS_UNIFORM_TEX_FLAGS_DISABLE_DRAW_DISPATCH_TABLE               0x00000020
#define PS_UNIFORM_TEX_FLAGS_DISABLE_NULL_TEXTURE_SUPPORT              0x00000040
#define PS_UNIFORM_TEX_FLAGS_DISABLE_LOAD_BALANCING                    0x00000080
#define PS_UNIFORM_TEX_FLAGS_DEFAULT                                   PS_UNIFORM_TEX_FLAGS_DISABLE_DRAW_DISPATCH_TABLE


#define PS_UNIFORM_TEX_MAX_DIM_STRING                                  "32625524"
#define PS_UNIFORM_TEX_MAX_DIM_ID                                      0x00eef152
#define PS_UNIFORM_TEX_MAX_DIM_OVERINSTALL                             0 // OVERRIDE
#define PS_UNIFORM_TEX_MAX_DIM_DEFAULT                                 0x20


#define PS_UNIFORM_TEX_SHADER_TYPE_STRING                              "44590981"
#define PS_UNIFORM_TEX_SHADER_TYPE_ID                                  0x00e39872
#define PS_UNIFORM_TEX_SHADER_TYPE_OVERINSTALL                         0 // OVERRIDE
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_VS_SUPPORT                  0x00000001
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_GS_SUPPORT                  0x00000002
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_PS_SUPPORT                  0x00000004
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_HS_SUPPORT                  0x00000008
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_DS_SUPPORT                  0x00000010
#define PS_UNIFORM_TEX_SHADER_TYPE_DISABLE_CS_SUPPORT                  0x00000020


#define PS_UNIQUENESSSTATS_STRING                                      "67198239"
#define PS_UNIQUENESSSTATS_ID                                          0x00cfc92f
#define PS_UNIQUENESSSTATS_OVERINSTALL                                 0 // OVERRIDE
#define PS_UNIQUENESSSTATS_OFF                                         0x32720261
#define PS_UNIQUENESSSTATS_0                                           0x32720261
#define PS_UNIQUENESSSTATS_FALSE                                       0x32720261
#define PS_UNIQUENESSSTATS_DISABLED                                    0x32720261
#define PS_UNIQUENESSSTATS_ON                                          0x47613549
#define PS_UNIQUENESSSTATS_1                                           0x47613549
#define PS_UNIQUENESSSTATS_TRUE                                        0x47613549
#define PS_UNIQUENESSSTATS_ENABLED                                     0x47613549


#define PS_UNIQUENESSSTATS_FLAGS_STRING                                "11212573"
#define PS_UNIQUENESSSTATS_FLAGS_ID                                    0x0023dc9e
#define PS_UNIQUENESSSTATS_FLAGS_OVERINSTALL                           0 // OVERRIDE
#define PS_UNIQUENESSSTATS_FLAGS_PRINT_INITIAL_COMPILE                 0x00000001
#define PS_UNIQUENESSSTATS_FLAGS_PRINT_ASYNC_COMPILES                  0x00000002
#define PS_UNIQUENESSSTATS_FLAGS_PRINT_DUPLICATE_COMPILES              0x00000004
#define PS_UNIQUENESSSTATS_FLAGS_PRINT_ADDITIONAL_COMPILES             0x00000008
#define PS_UNIQUENESSSTATS_FLAGS_WRITE_LOG_FILE                        0x80000000
#define PS_UNIQUENESSSTATS_FLAGS_WRITE_XLS_FILE                        0x40000000


#define PS_USE_DSR_DEPTH_COPY_STRING                                   "088C4D71"
#define PS_USE_DSR_DEPTH_COPY_ID                                       0x00f98e49
#define PS_USE_DSR_DEPTH_COPY_OVERINSTALL                              0 // OVERRIDE
#define PS_USE_DSR_DEPTH_COPY_OFF                                      0x00000000
#define PS_USE_DSR_DEPTH_COPY_ON                                       0x00000001
#define PS_USE_DSR_DEPTH_COPY_DEFAULT                                  PS_USE_DSR_DEPTH_COPY_OFF


#define PS_VAF_TO_TEXTURE_FETCH_STRING                                 "0376afd1"
#define PS_VAF_TO_TEXTURE_FETCH_ID                                     0x00afd001
#define PS_VAF_TO_TEXTURE_FETCH_OVERINSTALL                            0 // OVERRIDE
#define PS_VAF_TO_TEXTURE_FETCH_OFF                                    0x00000000
#define PS_VAF_TO_TEXTURE_FETCH_ON                                     0x00000001
#define PS_VAF_TO_TEXTURE_FETCH_DEFAULT                                PS_VAF_TO_TEXTURE_FETCH_ON


#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_STRING                           "0376afd2"
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_ID                               0x00afd002
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_OVERINSTALL                      0 // OVERRIDE
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_DISABLE_APP_DETECTION            0x00000001
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_DISABLE_MIXED_ATTRIBUTE_FORMATS  0x00000002
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_DISABLE_ARCH_SPECIFIC_CHECK      0x00000004
#define PS_VAF_TO_TEXTURE_FETCH_FLAGS_DEFAULT                          PS_VAF_TO_TEXTURE_FETCH_FLAGS_DISABLE_MIXED_ATTRIBUTE_FORMATS


#define PS_VBRENAME_STALL_STRING                                       "08429788"
#define PS_VBRENAME_STALL_ID                                           0x009647ba
#define PS_VBRENAME_STALL_OVERINSTALL                                  0 // OVERRIDE
#define PS_VBRENAME_STALL_OFF                                          0x55335336
#define PS_VBRENAME_STALL_DISABLED                                     0x55335336
#define PS_VBRENAME_STALL_ON                                           0x42173516
#define PS_VBRENAME_STALL_ENABLED                                      0x42173516


#define PS_VBRENAME_STALL_STATS_STRING                                 "96092575"
#define PS_VBRENAME_STALL_STATS_ID                                     0x00380df7
#define PS_VBRENAME_STALL_STATS_OVERINSTALL                            0 // OVERRIDE
#define PS_VBRENAME_STALL_STATS_OFF                                    0x00000000
#define PS_VBRENAME_STALL_STATS_DISABLED                               0x00000000
#define PS_VBRENAME_STALL_STATS_ON                                     0x00000001
#define PS_VBRENAME_STALL_STATS_ENABLED                                0x00000001


#define PS_VERTEX_SHADER_STRING                                        "00695671"
#define PS_VERTEX_SHADER_ID                                            0x0094f265
#define PS_VERTEX_SHADER_OVERINSTALL                                   0 // OVERRIDE
#define PS_VERTEX_SHADER_OFF                                           0x48845629
#define PS_VERTEX_SHADER_DISABLED                                      0x48845629
#define PS_VERTEX_SHADER_ON                                            0x15832834
#define PS_VERTEX_SHADER_ENABLED                                       0x15832834


#define PS_VERTEX_SHADER_ALLOW_STRING                                  "257489588"
#define PS_VERTEX_SHADER_ALLOW_ID                                      0x002957cc
#define PS_VERTEX_SHADER_ALLOW_OVERINSTALL                             0 // OVERRIDE
#define PS_VERTEX_SHADER_ALLOW_ALLOW_STATIC_HAND_TUNED                 0x00000001
#define PS_VERTEX_SHADER_ALLOW_ALLOW_DYNAMIC_HAND_TUNED                0x00000002


#define PS_VERTEX_SHADER_DUMP_STRING                                   "49005740"
#define PS_VERTEX_SHADER_DUMP_ID                                       0x00abf661
#define PS_VERTEX_SHADER_DUMP_OVERINSTALL                              0 // OVERRIDE
#define PS_VERTEX_SHADER_DUMP_OFF                                      0x28470024
#define PS_VERTEX_SHADER_DUMP_DISABLED                                 0x28470024
#define PS_VERTEX_SHADER_DUMP_ON                                       0x29267504
#define PS_VERTEX_SHADER_DUMP_ENABLED                                  0x29267504


#define PS_VERTEX_SHADER_DUMP_FLAGS_STRING                             "67739784"
#define PS_VERTEX_SHADER_DUMP_FLAGS_ID                                 0x0039ac22
#define PS_VERTEX_SHADER_DUMP_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_APP_CREATED_SHADERS           0x00000001
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_HAND_TUNED_SHADERS            0x00000002
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_DSR_SHADERS                   0x00000004
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_CUBEMAP_SHADERS               0x01000000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_DRIVER_CALC_SHADERS           0x02000000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_ZERO_USAGE_SHADERS            0x00000008
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_NVINST                        0x00000020
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_NVVM                          0x00000020
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SAMPLER_STATE                 0x00000040
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_TEXTURE_STATE                 0x00000080
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_NVINST              0x00000120
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_SASS                0x00000200
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_ANNOTATED_DXBC                0x00000400
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_GENERATE_SOURCE_CODE          0x00000800
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_CONST_HISTOGRAMS              0x00001000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_RENDERTARGET_STATE            0x00002000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_DEPTHTARGET_STATE             0x00004000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_TIME           0x00010000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_SPEED          0x00020000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_STALLS         0x00040000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER      0x00080000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_SORT_COLLECTIONS       0x00100000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_USE_PCSAMPLER_FOR_USAGE 0x00200000
#define PS_VERTEX_SHADER_DUMP_FLAGS_DUMP_SHADER_COMPILE_TIME           0x00400000


#define PS_VERTEX_SHADER_STATS_FILENAME_STRING                         "864a83"
#define PS_VERTEX_SHADER_STATS_FILENAME_ID                             0x00864a83
#define PS_VERTEX_SHADER_STATS_FILENAME_OVERINSTALL                    0 // OVERRIDE


#define PS_VIDEO_CCX_STRING                                            "925341ed"
#define PS_VIDEO_CCX_ID                                                0x00ff2467
#define PS_VIDEO_CCX_OVERINSTALL                                       0 // OVERRIDE
#define PS_VIDEO_CCX_OFF                                               0x0
#define PS_VIDEO_CCX_DISABLED                                          0x0
#define PS_VIDEO_CCX_ON                                                0x1
#define PS_VIDEO_CCX_ENABLED                                           0x1


#define PS_VPRS_STRING                                                 "504269"
#define PS_VPRS_ID                                                     0x00504269
#define PS_VPRS_OVERINSTALL                                            0 // OVERRIDE
#define PS_VPRS_OFF                                                    0x00000000
#define PS_VPRS_ON                                                     0x00000001
#define PS_VPRS_DEFAULT                                                PS_VPRS_OFF


#define PS_VPRS_FLAGS_STRING                                           "504256"
#define PS_VPRS_FLAGS_ID                                               0x00504256
#define PS_VPRS_FLAGS_OVERINSTALL                                      0 // OVERRIDE
#define PS_VPRS_FLAGS_VPRS_FLAGS_NONE                                  0x00000000
#define PS_VPRS_FLAGS_VPRS_FLAGS_FORCE_SHADING_RATE_SURFACE            0x00000001
#define PS_VPRS_FLAGS_VPRS_FLAGS_ENABLE_VPRS_FOR_SQUARE_RT             0x00000002
#define PS_VPRS_FLAGS_VPRS_FLAGS_ENABLE_VPRS_FOR_SMALL_RT              0x00000004
#define PS_VPRS_FLAGS_DEFAULT                                          0x00000006


#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_RADII_STRING             "554249"
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_RADII_ID                 0x00554249
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_RADII_OVERINSTALL        0 // OVERRIDE
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_RADII_DEFAULT            5.0f


#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_SHADINGRATE_STRING       "544249"
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_SHADINGRATE_ID           0x00544249
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_SHADINGRATE_OVERINSTALL  0 // OVERRIDE
#define PS_VPRS_LOADBALANCE_GPU_THRESHOLD_PCT_SHADINGRATE_DEFAULT      15.0f


#define PS_VPRS_LOADBALANCE_RADII_STEPCOUNT_STRING                     "534249"
#define PS_VPRS_LOADBALANCE_RADII_STEPCOUNT_ID                         0x00534249
#define PS_VPRS_LOADBALANCE_RADII_STEPCOUNT_OVERINSTALL                0 // OVERRIDE
#define PS_VPRS_LOADBALANCE_RADII_STEPCOUNT_DEFAULT                    0.05f


#define PS_VPRS_LOADBALANCE_TARGET_FPS_STRING                          "514249"
#define PS_VPRS_LOADBALANCE_TARGET_FPS_ID                              0x00514249
#define PS_VPRS_LOADBALANCE_TARGET_FPS_OVERINSTALL                     0 // OVERRIDE
#define PS_VPRS_LOADBALANCE_TARGET_FPS_DEFAULT                         90.0f


#define PS_VPRS_LOADBALANCE_TARGET_GPUMS_STRING                        "524249"
#define PS_VPRS_LOADBALANCE_TARGET_GPUMS_ID                            0x00524249
#define PS_VPRS_LOADBALANCE_TARGET_GPUMS_OVERINSTALL                   0 // OVERRIDE
#define PS_VPRS_LOADBALANCE_TARGET_GPUMS_DEFAULT                       8.5f


#define PS_VPRS_MODE_STRING                                            "504296"
#define PS_VPRS_MODE_ID                                                0x00504296
#define PS_VPRS_MODE_OVERINSTALL                                       0 // OVERRIDE
#define PS_VPRS_MODE_SR_NONE                                           0x0000
#define PS_VPRS_MODE_SR_CONSTANT_1x1                                   0x0001
#define PS_VPRS_MODE_SR_CONSTANT_1x2                                   0x0002
#define PS_VPRS_MODE_SR_CONSTANT_2x1                                   0x0003
#define PS_VPRS_MODE_SR_CONSTANT_2x2                                   0x0004
#define PS_VPRS_MODE_SR_CONSTANT_2x4                                   0x0005
#define PS_VPRS_MODE_SR_CONSTANT_4x2                                   0x0006
#define PS_VPRS_MODE_SR_CONSTANT_4x4                                   0x0007
#define PS_VPRS_MODE_SR_CONSTANT_2xSS                                  0x0008
#define PS_VPRS_MODE_SR_CONSTANT_4xSS                                  0x0009
#define PS_VPRS_MODE_SR_CONSTANT_8xSS                                  0x000a
#define PS_VPRS_MODE_SR_CONSTANT_16xSS                                 0x000b
#define PS_VPRS_MODE_SR_FOVEATED                                       0x000c
#define PS_VPRS_MODE_SR_NOISY                                          0x000d
#define PS_VPRS_MODE_DEFAULT                                           0


#define PS_VPRS_SMALL_RT_THRESHOLD_HEIGHT_STRING                       "504249"
#define PS_VPRS_SMALL_RT_THRESHOLD_HEIGHT_ID                           0x00504249
#define PS_VPRS_SMALL_RT_THRESHOLD_HEIGHT_OVERINSTALL                  0 // OVERRIDE
#define PS_VPRS_SMALL_RT_THRESHOLD_HEIGHT_DEFAULT                      256


#define PS_VPRS_SMALL_RT_THRESHOLD_WIDTH_STRING                        "504245"
#define PS_VPRS_SMALL_RT_THRESHOLD_WIDTH_ID                            0x00504245
#define PS_VPRS_SMALL_RT_THRESHOLD_WIDTH_OVERINSTALL                   0 // OVERRIDE
#define PS_VPRS_SMALL_RT_THRESHOLD_WIDTH_DEFAULT                       256


#define PS_VPR_DEBUGGING_STRING                                        "611fd52D"
#define PS_VPR_DEBUGGING_ID                                            0x00af2139
#define PS_VPR_DEBUGGING_OVERINSTALL                                   0 // OVERRIDE
#define PS_VPR_DEBUGGING_OFF                                           0x18F3902C
#define PS_VPR_DEBUGGING_DISABLED                                      0x18F3902C
#define PS_VPR_DEBUGGING_ON                                            0x18F3902D
#define PS_VPR_DEBUGGING_ENABLED                                       0x18F3902D
#define PS_VPR_DEBUGGING_DEFAULT                                       PS_VPR_DEBUGGING_OFF


#define PS_VPR_DWM_PROTECTED_LMEM_ALLOC_DESTROY_HYSTERESIS_STRING      "34affda2"
#define PS_VPR_DWM_PROTECTED_LMEM_ALLOC_DESTROY_HYSTERESIS_ID          0x0034affd
#define PS_VPR_DWM_PROTECTED_LMEM_ALLOC_DESTROY_HYSTERESIS_OVERINSTALL 0 // OVERRIDE
#define PS_VPR_DWM_PROTECTED_LMEM_ALLOC_DESTROY_HYSTERESIS_DEFAULT     0x5


#define PS_WARBUG305617_STRING                                         "42895563"
#define PS_WARBUG305617_ID                                             0x005bc87f
#define PS_WARBUG305617_OVERINSTALL                                    0 // OVERRIDE
#define PS_WARBUG305617_OFF                                            0x08253890
#define PS_WARBUG305617_DISABLED                                       0x08253890
#define PS_WARBUG305617_ON                                             0x56289103
#define PS_WARBUG305617_ENABLED                                        0x56289103


#define PS_WARP_PROFILER_STRING                                        "0562ABA0"
#define PS_WARP_PROFILER_ID                                            0x00effba0
#define PS_WARP_PROFILER_OVERINSTALL                                   0 // OVERRIDE
#define PS_WARP_PROFILER_OFF                                           0x00000000
#define PS_WARP_PROFILER_ON                                            0x00000001
#define PS_WARP_PROFILER_DEFAULT                                       PS_WARP_PROFILER_OFF


#define PS_WARP_PROFILER_DEFER_CREATION_STRING                         "0562ABA3"
#define PS_WARP_PROFILER_DEFER_CREATION_ID                             0x00effba3
#define PS_WARP_PROFILER_DEFER_CREATION_OVERINSTALL                    0 // OVERRIDE
#define PS_WARP_PROFILER_DEFER_CREATION_OFF                            0x00000000
#define PS_WARP_PROFILER_DEFER_CREATION_ON                             0x00000001
#define PS_WARP_PROFILER_DEFER_CREATION_DEFAULT                        PS_WARP_PROFILER_DEFER_CREATION_OFF


#define PS_WARP_PROFILER_DUMP_FRAME_NUM_STRING                         "00EFFBA4"
#define PS_WARP_PROFILER_DUMP_FRAME_NUM_ID                             0x00effba4
#define PS_WARP_PROFILER_DUMP_FRAME_NUM_OVERINSTALL                    0 // OVERRIDE
#define PS_WARP_PROFILER_DUMP_FRAME_NUM_DEFAULT                        0x0


#define PS_WARP_PROFILER_FRAMES_STRING                                 "0562ABA2"
#define PS_WARP_PROFILER_FRAMES_ID                                     0x00effba2
#define PS_WARP_PROFILER_FRAMES_OVERINSTALL                            0 // OVERRIDE
#define PS_WARP_PROFILER_FRAMES_DEFAULT                                0x1


#define PS_WARP_PROFILER_NUM_RESIZE_FRAMES_STRING                      "0562ABA5"
#define PS_WARP_PROFILER_NUM_RESIZE_FRAMES_ID                          0x00effba5
#define PS_WARP_PROFILER_NUM_RESIZE_FRAMES_OVERINSTALL                 0 // OVERRIDE
#define PS_WARP_PROFILER_NUM_RESIZE_FRAMES_DEFAULT                     0x0


#define PS_WARP_PROFILER_RESIZE_MODE_STRING                            "0562ABA6"
#define PS_WARP_PROFILER_RESIZE_MODE_ID                                0x00effba6
#define PS_WARP_PROFILER_RESIZE_MODE_OVERINSTALL                       0 // OVERRIDE
#define PS_WARP_PROFILER_RESIZE_MODE_OFF                               0x00000000
#define PS_WARP_PROFILER_RESIZE_MODE_SINGLE_FRAME                      0x00000001
#define PS_WARP_PROFILER_RESIZE_MODE_MULTI_FRAME                       0x00000002
#define PS_WARP_PROFILER_RESIZE_MODE_DEFAULT                           0x00000000


#define PS_WARP_PROFILER_SEGMENTS_STRING                               "0562ABA1"
#define PS_WARP_PROFILER_SEGMENTS_ID                                   0x00effba1
#define PS_WARP_PROFILER_SEGMENTS_OVERINSTALL                          0 // OVERRIDE
#define PS_WARP_PROFILER_SEGMENTS_DEFAULT                              0x1


#define PS_ZBC_STRING                                                  "915241ed"
#define PS_ZBC_ID                                                      0x00fe2367
#define PS_ZBC_OVERINSTALL                                             0 // OVERRIDE
#define PS_ZBC_OFF                                                     0x0
#define PS_ZBC_DISABLED                                                0x0
#define PS_ZBC_ON                                                      0x1
#define PS_ZBC_ENABLED                                                 0x1
#define PS_ZBC_DEFAULT                                                 PS_ZBC_ON


#define PS_ZBC_FLAGS_STRING                                            "915241ee"
#define PS_ZBC_FLAGS_ID                                                0x00fe2368
#define PS_ZBC_FLAGS_OVERINSTALL                                       0 // OVERRIDE
#define PS_ZBC_FLAGS_DISABLE_COLOR_CLEAR_TRACKING                      0x00000001
#define PS_ZBC_FLAGS_DISABLE_DEPTH_CLEAR_TRACKING                      0x00000002
#define PS_ZBC_FLAGS_DISABLE_STENCIL_CLEAR_TRACKING                    0x00000004
#define PS_ZBC_FLAGS_DISABLE_COLOR_ZBC                                 0x00000010
#define PS_ZBC_FLAGS_DISABLE_DEPTH_ZBC                                 0x00000020
#define PS_ZBC_FLAGS_DISABLE_STENCIL_ZBC                               0x00000040
#define PS_ZBC_FLAGS_DO_NOT_FREE_ZBC_CLEAR_TABLE_ENTRIES               0x00010000
#define PS_ZBC_FLAGS_DBG_PRINT_EVERY_FRAME                             0x01000000
#define PS_ZBC_FLAGS_REPORT_SET_ZBC_FAILURES                           0x02000000
#define PS_ZBC_FLAGS_DEFAULT                                           0


#define PS_ZBC_MAX_ENTRIES_STRING                                      "10f12985"
#define PS_ZBC_MAX_ENTRIES_ID                                          0x000f3875
#define PS_ZBC_MAX_ENTRIES_OVERINSTALL                                 0 // OVERRIDE
#define PS_ZBC_MAX_ENTRIES_DEFAULT                                     0x7fffffff


#define PS_ZCULL_STRING                                                "48484658"
#define PS_ZCULL_ID                                                    0x008d583f
#define PS_ZCULL_OVERINSTALL                                           0 // OVERRIDE
#define PS_ZCULL_OFF                                                   0x91302489
#define PS_ZCULL_DISABLED                                              0x91302489
#define PS_ZCULL_ON                                                    0x91256712
#define PS_ZCULL_ENABLED                                               0x91256712


#define PS_ZCULL_DIRTY_DRAW_VALIDATION_STRING                          "00037828"
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_ID                              0x009fd0fb
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_OVERINSTALL                     0 // OVERRIDE
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_OFF                             0x00000000
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_DISABLED                        0x00000000
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_ON                              0x00000001
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_ENABLED                         0x00000001
#define PS_ZCULL_DIRTY_DRAW_VALIDATION_DEFAULT                         PS_ZCULL_DIRTY_DRAW_VALIDATION_ON


#define PS_ZCULL_FLAGS_STRING                                          "00037827"
#define PS_ZCULL_FLAGS_ID                                              0x009fd0f9
#define PS_ZCULL_FLAGS_OVERINSTALL                                     0 // OVERRIDE
#define PS_ZCULL_FLAGS_ZC_NONE                                         0x00000000
#define PS_ZCULL_FLAGS_ZC_DISABLE_VIEWPORTS                            0x00000001
#define PS_ZCULL_FLAGS_ZC_DX12_DISABLE_SHADER_HEURISTICS               0x00000002
#define PS_ZCULL_FLAGS_ZC_DISABLE_ARRAYS_AS_SLICES                     0x00000004
#define PS_ZCULL_FLAGS_ZC_DX11_DISABLE_UNCONDITIONAL_BACKING_STORE     0x00000008
#define PS_ZCULL_FLAGS_ZC_DISABLE_ZF32_PRI_RESET                       0x00040000
#define PS_ZCULL_FLAGS_DEFAULT                                         PS_ZCULL_FLAGS_ZC_NONE


#define PS_ZCULL_INFO_STRING                                           "efb8225a"
#define PS_ZCULL_INFO_ID                                               0x00fe8b22
#define PS_ZCULL_INFO_OVERINSTALL                                      0 // OVERRIDE
#define PS_ZCULL_INFO_DISABLED                                         0x00000000
#define PS_ZCULL_INFO_TRACE                                            0x00000001
#define PS_ZCULL_INFO_STATS                                            0x00000002
#define PS_ZCULL_INFO_PER_DRAW_STATS                                   0x00000004
#define PS_ZCULL_INFO_DEFAULT                                          PS_ZCULL_INFO_DISABLED


#define PS_ZCULL_SCULL_ENABLE_STRING                                   "89262555"
#define PS_ZCULL_SCULL_ENABLE_ID                                       0x00a21555
#define PS_ZCULL_SCULL_ENABLE_OVERINSTALL                              0 // OVERRIDE
#define PS_ZCULL_SCULL_ENABLE_OFF                                      0x00000000
#define PS_ZCULL_SCULL_ENABLE_DISABLED                                 0x00000000
#define PS_ZCULL_SCULL_ENABLE_ON                                       0x00000001
#define PS_ZCULL_SCULL_ENABLE_ENABLED                                  0x00000001
#define PS_ZCULL_SCULL_ENABLE_DEFAULT                                  PS_ZCULL_SCULL_ENABLE_OFF


#define PS_ZCULL_SHADER_HEURISTICS_LDA_STRING                          "eb05e1"
#define PS_ZCULL_SHADER_HEURISTICS_LDA_ID                              0x00eb05e1
#define PS_ZCULL_SHADER_HEURISTICS_LDA_OVERINSTALL                     0 // OVERRIDE
#define PS_ZCULL_SHADER_HEURISTICS_LDA_NONE                            0
#define PS_ZCULL_SHADER_HEURISTICS_LDA_0                               0
#define PS_ZCULL_SHADER_HEURISTICS_LDA_ALL                             1
#define PS_ZCULL_SHADER_HEURISTICS_LDA_1                               1
#define PS_ZCULL_SHADER_HEURISTICS_LDA_PASCAL_AND_NEWER                2
#define PS_ZCULL_SHADER_HEURISTICS_LDA_TURING_AND_NEWER                3
#define PS_ZCULL_SHADER_HEURISTICS_LDA_AMPERE_AND_NEWER                4
#define PS_ZCULL_SHADER_HEURISTICS_LDA_DEFAULT                         PS_ZCULL_SHADER_HEURISTICS_LDA_NONE


#define PS_ZCULL_STATS_STRING                                          "89262223"
#define PS_ZCULL_STATS_ID                                              0x00a21b67
#define PS_ZCULL_STATS_OVERINSTALL                                     0 // OVERRIDE
#define PS_ZCULL_STATS_OFF                                             0x00000000
#define PS_ZCULL_STATS_DISABLED                                        0x00000000
#define PS_ZCULL_STATS_ON                                              0x00000001
#define PS_ZCULL_STATS_ENABLED                                         0x00000001


#define PS_ZCULL_TOTAL_ALIQUOTS_STRING                                 "efb8225b"
#define PS_ZCULL_TOTAL_ALIQUOTS_ID                                     0x00228bfe
#define PS_ZCULL_TOTAL_ALIQUOTS_OVERINSTALL                            0 // OVERRIDE
#define PS_ZCULL_TOTAL_ALIQUOTS_DEFAULT                                0


#define PS_ZCULL_ZF32_GREATER_PRI_STRING                               "00037826"
#define PS_ZCULL_ZF32_GREATER_PRI_ID                                   0x009fd0fa
#define PS_ZCULL_ZF32_GREATER_PRI_OVERINSTALL                          0 // OVERRIDE
#define PS_ZCULL_ZF32_GREATER_PRI_DISABLE_ZF32                         0x00000001
#define PS_ZCULL_ZF32_GREATER_PRI_DISABLE_ZF32_X24                     0x00000002
#define PS_ZCULL_ZF32_GREATER_PRI_DEFAULT                              0


#define PS_ZERO_TEX_MODULATION_STRING                                  "82035431"
#define PS_ZERO_TEX_MODULATION_ID                                      0x00d5f51f
#define PS_ZERO_TEX_MODULATION_OVERINSTALL                             0 // OVERRIDE
#define PS_ZERO_TEX_MODULATION_OFF                                     0x45134824
#define PS_ZERO_TEX_MODULATION_DISABLED                                0x45134824
#define PS_ZERO_TEX_MODULATION_ON                                      0x96012432
#define PS_ZERO_TEX_MODULATION_ENABLED                                 0x96012432
#define PS_ZERO_TEX_MODULATION_DEFAULT                                 PS_ZERO_TEX_MODULATION_ON


#define PS_ZERO_TEX_MODULATION_FLAGS_STRING                            "64032429"
#define PS_ZERO_TEX_MODULATION_FLAGS_ID                                0x0013f415
#define PS_ZERO_TEX_MODULATION_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define PS_ZERO_TEX_MODULATION_FLAGS_SKIP_TEXTURE_ANALYSIS             0x00000001
#define PS_ZERO_TEX_MODULATION_FLAGS_DEFAULT                           0x00000000


#define PS_ZERO_TEX_MODULATION_MIN_DEPENDENT_INST_STRING               "62267e2f"
#define PS_ZERO_TEX_MODULATION_MIN_DEPENDENT_INST_ID                   0x0072b1e2
#define PS_ZERO_TEX_MODULATION_MIN_DEPENDENT_INST_OVERINSTALL          0 // OVERRIDE
#define PS_ZERO_TEX_MODULATION_MIN_DEPENDENT_INST_DEFAULT              0x3


#define PS_ZERO_TEX_MODULATION_PERCENT_ZERO_STRING                     "12567524"
#define PS_ZERO_TEX_MODULATION_PERCENT_ZERO_ID                         0x0083b1e1
#define PS_ZERO_TEX_MODULATION_PERCENT_ZERO_OVERINSTALL                0 // OVERRIDE
#define PS_ZERO_TEX_MODULATION_PERCENT_ZERO_DEFAULT                    0x32


#define PUSHBUFFER_FLAGS_STRING                                        "1e89f7"
#define PUSHBUFFER_FLAGS_ID                                            0x001e89f7
#define PUSHBUFFER_FLAGS_OVERINSTALL                                   0 // OVERRIDE
#define PUSHBUFFER_FLAGS_IGNORE_SPLIT_POINTS                           0x00000001
#define PUSHBUFFER_FLAGS_DEFAULT                                       0


#define PUSHBUFFER_HEAP_STRING                                         "38fffc81"
#define PUSHBUFFER_HEAP_ID                                             0x0012fa6f
#define PUSHBUFFER_HEAP_OVERINSTALL                                    0 // OVERRIDE
#define PUSHBUFFER_HEAP_PB_HEAP_HOST                                   0x00000000
#define PUSHBUFFER_HEAP_PB_HEAP_CACHED                                 0x00000001
#define PUSHBUFFER_HEAP_DEFAULT                                        PUSHBUFFER_HEAP_PB_HEAP_HOST


#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_STRING                     "5B1406"
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_ID                         0x005b1406
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_OVERINSTALL                0 // OVERRIDE
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_OFF                        0x00000000
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_DISABLED                   0x00000000
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_ON                         0x00000001
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_ENABLED                    0x00000001
#define QMD_INVALIDATE_INTERNAL_CB_BINDINGS_DEFAULT                    QMD_INVALIDATE_INTERNAL_CB_BINDINGS_OFF


#define QMD_PRIORITY_ASYNC_COMPUTE_STRING                              "EDD836"
#define QMD_PRIORITY_ASYNC_COMPUTE_ID                                  0x00a44b66
#define QMD_PRIORITY_ASYNC_COMPUTE_OVERINSTALL                         0 // OVERRIDE
#define QMD_PRIORITY_ASYNC_COMPUTE_DEFAULT                             36


#define QMD_PRIORITY_ASYNC_PERFSTRAT_HIGH_STRING                       "EDD839"
#define QMD_PRIORITY_ASYNC_PERFSTRAT_HIGH_ID                           0x00a44b69
#define QMD_PRIORITY_ASYNC_PERFSTRAT_HIGH_OVERINSTALL                  0 // OVERRIDE
#define QMD_PRIORITY_ASYNC_PERFSTRAT_HIGH_DEFAULT                      24


#define QMD_PRIORITY_ASYNC_PERFSTRAT_LOW_STRING                        "EDD83A"
#define QMD_PRIORITY_ASYNC_PERFSTRAT_LOW_ID                            0x00a44b6a
#define QMD_PRIORITY_ASYNC_PERFSTRAT_LOW_OVERINSTALL                   0 // OVERRIDE
#define QMD_PRIORITY_ASYNC_PERFSTRAT_LOW_DEFAULT                       40


#define QMD_PRIORITY_ASYNC_RTCORE_ACCEL_STRING                         "EDD832"
#define QMD_PRIORITY_ASYNC_RTCORE_ACCEL_ID                             0x00a44b62
#define QMD_PRIORITY_ASYNC_RTCORE_ACCEL_OVERINSTALL                    0 // OVERRIDE
#define QMD_PRIORITY_ASYNC_RTCORE_ACCEL_DEFAULT                        28


#define QMD_PRIORITY_ASYNC_RTCORE_LAUNCH_STRING                        "EDD834"
#define QMD_PRIORITY_ASYNC_RTCORE_LAUNCH_ID                            0x00a44b64
#define QMD_PRIORITY_ASYNC_RTCORE_LAUNCH_OVERINSTALL                   0 // OVERRIDE
#define QMD_PRIORITY_ASYNC_RTCORE_LAUNCH_DEFAULT                       32


#define QMD_PRIORITY_SYNC_COMPUTE_STRING                               "EDD835"
#define QMD_PRIORITY_SYNC_COMPUTE_ID                                   0x00a44b65
#define QMD_PRIORITY_SYNC_COMPUTE_OVERINSTALL                          0 // OVERRIDE
#define QMD_PRIORITY_SYNC_COMPUTE_DEFAULT                              16


#define QMD_PRIORITY_SYNC_PERFSTRAT_HIGH_STRING                        "EDD830"
#define QMD_PRIORITY_SYNC_PERFSTRAT_HIGH_ID                            0x00a44b60
#define QMD_PRIORITY_SYNC_PERFSTRAT_HIGH_OVERINSTALL                   0 // OVERRIDE
#define QMD_PRIORITY_SYNC_PERFSTRAT_HIGH_DEFAULT                       4


#define QMD_PRIORITY_SYNC_PERFSTRAT_LOW_STRING                         "EDD837"
#define QMD_PRIORITY_SYNC_PERFSTRAT_LOW_ID                             0x00a44b67
#define QMD_PRIORITY_SYNC_PERFSTRAT_LOW_OVERINSTALL                    0 // OVERRIDE
#define QMD_PRIORITY_SYNC_PERFSTRAT_LOW_DEFAULT                        20


#define QMD_PRIORITY_SYNC_RTCORE_ACCEL_STRING                          "EDD831"
#define QMD_PRIORITY_SYNC_RTCORE_ACCEL_ID                              0x00a44b61
#define QMD_PRIORITY_SYNC_RTCORE_ACCEL_OVERINSTALL                     0 // OVERRIDE
#define QMD_PRIORITY_SYNC_RTCORE_ACCEL_DEFAULT                         8


#define QMD_PRIORITY_SYNC_RTCORE_LAUNCH_STRING                         "EDD833"
#define QMD_PRIORITY_SYNC_RTCORE_LAUNCH_ID                             0x00a44b63
#define QMD_PRIORITY_SYNC_RTCORE_LAUNCH_OVERINSTALL                    0 // OVERRIDE
#define QMD_PRIORITY_SYNC_RTCORE_LAUNCH_DEFAULT                        12


#define QMD_SM_DISABLE_MASK_STRING                                     "0x15ba22"
#define QMD_SM_DISABLE_MASK_ID                                         0x0015ba22
#define QMD_SM_DISABLE_MASK_OVERINSTALL                                0 // OVERRIDE
#define QMD_SM_DISABLE_MASK_DEFAULT                                    0


#define QMD_SM_DISABLE_MASK_FLAGS_STRING                               "0xc29b07"
#define QMD_SM_DISABLE_MASK_FLAGS_ID                                   0x00c29b07
#define QMD_SM_DISABLE_MASK_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define QMD_SM_DISABLE_MASK_FLAGS_APPLY_MASK_TO_COD                    0x00000001
#define QMD_SM_DISABLE_MASK_FLAGS_APPLY_MASK_TO_D3D                    0x00000002
#define QMD_SM_DISABLE_MASK_FLAGS_DEFAULT                              0


#define QMD_SM_DISABLE_MASK_ROTATE_MODE_STRING                         "0xbe4587"
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_ID                             0x00be4587
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_OVERINSTALL                    0 // OVERRIDE
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_OFF                            0x0
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_HALF                           0x1
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_QUARTER                        0x2
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_MODE_MASK                      0xFF
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_DISALLOW_SYNC                  0x40000000
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_DISALLOW_ASYNC                 0x80000000
#define QMD_SM_DISABLE_MASK_ROTATE_MODE_DEFAULT                        QMD_SM_DISABLE_MASK_ROTATE_MODE_QUARTER


#define QMD_SM_DISABLE_MASK_ROTATE_USER_LIMIT_STRING                   "0xbe6542"
#define QMD_SM_DISABLE_MASK_ROTATE_USER_LIMIT_ID                       0x00be6542
#define QMD_SM_DISABLE_MASK_ROTATE_USER_LIMIT_OVERINSTALL              0 // OVERRIDE
#define QMD_SM_DISABLE_MASK_ROTATE_USER_LIMIT_DEFAULT                  0x0


#define QUALITY_ENHANCEMENTS_STRING                                    "QualityEnhancements"
#define QUALITY_ENHANCEMENTS_ID                                        0x00ce2691
#define QUALITY_ENHANCEMENTS_OVERINSTALL                               1 // MERGE
#define QUALITY_ENHANCEMENTS_HIGHQUALITY                               0xfffffff6
#define QUALITY_ENHANCEMENTS_HQ                                        0xfffffff6
#define QUALITY_ENHANCEMENTS_QUALITY                                   0x00000000
#define QUALITY_ENHANCEMENTS_Q                                         0x00000000
#define QUALITY_ENHANCEMENTS_0                                         0x00000000
#define QUALITY_ENHANCEMENTS_PERFORMANCE                               0x0000000a
#define QUALITY_ENHANCEMENTS_P                                         0x0000000a
#define QUALITY_ENHANCEMENTS_a                                         0x0000000a
#define QUALITY_ENHANCEMENTS_0xa                                       0x0000000a
#define QUALITY_ENHANCEMENTS_HIGHPERFORMANCE                           0x00000014
#define QUALITY_ENHANCEMENTS_HP                                        0x00000014
#define QUALITY_ENHANCEMENTS_14                                        0x00000014
#define QUALITY_ENHANCEMENTS_0x14                                      0x00000014
#define QUALITY_ENHANCEMENTS_DEFAULT                                   QUALITY_ENHANCEMENTS_QUALITY


#define QUALITY_ENHANCEMENT_SUBSTITUTION_STRING                        "QualityEnhancementSubstitution"
#define QUALITY_ENHANCEMENT_SUBSTITUTION_ID                            0x00ce2692
#define QUALITY_ENHANCEMENT_SUBSTITUTION_OVERINSTALL                   1 // MERGE
#define QUALITY_ENHANCEMENT_SUBSTITUTION_NO_SUBSTITUTION               0x00000000
#define QUALITY_ENHANCEMENT_SUBSTITUTION_HIGHQUALITY_BECOMES_QUALITY   0x00000001
#define QUALITY_ENHANCEMENT_SUBSTITUTION_DEFAULT                       QUALITY_ENHANCEMENT_SUBSTITUTION_NO_SUBSTITUTION


#define QUERY_FLAGS_STRING                                             "7ca199"
#define QUERY_FLAGS_ID                                                 0x007ca199
#define QUERY_FLAGS_OVERINSTALL                                        0 // OVERRIDE
#define QUERY_FLAGS_DEFAULT                                            0x00000000
#define QUERY_FLAGS_FORCE_GETDATA_FLUSH                                0x00000001
#define QUERY_FLAGS_FORCE_GETDATA_WAITFORDATA                          0x00000002


#define RAYQUERY_AND_FLAGS_STRING                                      "0x50a158"
#define RAYQUERY_AND_FLAGS_ID                                          0x0050a158
#define RAYQUERY_AND_FLAGS_OVERINSTALL                                 0 // OVERRIDE
#define RAYQUERY_AND_FLAGS_DEFAULT                                     0xFFFFFFFF
#define RAYQUERY_AND_FLAGS_CLEAR_FORCE_OPAQUE                          0xFFFFFFFE
#define RAYQUERY_AND_FLAGS_CLEAR_FORCE_NO_OPAQUE                       0xFFFFFFFD
#define RAYQUERY_AND_FLAGS_CLEAR_TERM_ON_FIRST_HIT                     0xFFFFFFFB
#define RAYQUERY_AND_FLAGS_CLEAR_SKIP_CLOSEST_HIT                      0xFFFFFFF7
#define RAYQUERY_AND_FLAGS_CLEAR_CULL_BACK_FACING                      0xFFFFFFEF
#define RAYQUERY_AND_FLAGS_CLEAR_CULL_FRONT_FACING                     0xFFFFFFDF
#define RAYQUERY_AND_FLAGS_CLEAR_CULL_OPAQUE                           0xFFFFFFBF
#define RAYQUERY_AND_FLAGS_CLEAR_CULL_NON_OPAQUE                       0xFFFFFF7F
#define RAYQUERY_AND_FLAGS_CLEAR_SKIP_TRIANGLES                        0xFFFFFEFF
#define RAYQUERY_AND_FLAGS_CLEAR_SKIP_AABBS                            0xFFFFFDFF


#define RAYQUERY_OR_FLAGS_STRING                                       "0x50a157"
#define RAYQUERY_OR_FLAGS_ID                                           0x0050a157
#define RAYQUERY_OR_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define RAYQUERY_OR_FLAGS_DEFAULT                                      0
#define RAYQUERY_OR_FLAGS_FORCE_OPAQUE                                 1
#define RAYQUERY_OR_FLAGS_FORCE_NO_OPAQUE                              2
#define RAYQUERY_OR_FLAGS_TERM_ON_FIRST_HIT                            4
#define RAYQUERY_OR_FLAGS_SKIP_CLOSEST_HIT                             8
#define RAYQUERY_OR_FLAGS_CULL_BACK_FACING                             16
#define RAYQUERY_OR_FLAGS_CULL_FRONT_FACING                            32
#define RAYQUERY_OR_FLAGS_CULL_OPAQUE                                  64
#define RAYQUERY_OR_FLAGS_CULL_NON_OPAQUE                              128
#define RAYQUERY_OR_FLAGS_SKIP_TRIANGLES                               256
#define RAYQUERY_OR_FLAGS_SKIP_AABBS                                   512


#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_STRING                  "8f7215a4"
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_ID                      0x008f7215
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_OVERINSTALL             0 // OVERRIDE
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_OFF                     0x00000000
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_0                       0x00000000
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_FALSE                   0x00000000
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_DISABLED                0x00000000
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_ON                      0x00000001
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_1                       0x00000001
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_TRUE                    0x00000001
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_ENABLED                 0x00000001
#define READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_DEFAULT                 READ_ONLY_DSV_EARLYZ_HAZARD_WAR_ENABLE_OFF


#define READ_REGISTRY_FOR_DVS_MACHINE_STRING                           "abc123"
#define READ_REGISTRY_FOR_DVS_MACHINE_ID                               0x00abc123
#define READ_REGISTRY_FOR_DVS_MACHINE_OVERINSTALL                      0 // OVERRIDE
#define READ_REGISTRY_FOR_DVS_MACHINE_OFF                              0x00000000
#define READ_REGISTRY_FOR_DVS_MACHINE_DISABLED                         0x00000000
#define READ_REGISTRY_FOR_DVS_MACHINE_ON                               0x00000001
#define READ_REGISTRY_FOR_DVS_MACHINE_ENABLED                          0x00000001
#define READ_REGISTRY_FOR_DVS_MACHINE_DEFAULT                          READ_REGISTRY_FOR_DVS_MACHINE_ON


#define REDUCE_VASPACE_MAPPINGS_STRING                                 "78E16B9B"
#define REDUCE_VASPACE_MAPPINGS_ID                                     0x007c3865
#define REDUCE_VASPACE_MAPPINGS_OVERINSTALL                            0 // OVERRIDE
#define REDUCE_VASPACE_MAPPINGS_OFF                                    0x22754241
#define REDUCE_VASPACE_MAPPINGS_DISABLED                               0x22754241
#define REDUCE_VASPACE_MAPPINGS_ON                                     0x66855023
#define REDUCE_VASPACE_MAPPINGS_ENABLED                                0x66855023
#define REDUCE_VASPACE_MAPPINGS_DEFAULT                                REDUCE_VASPACE_MAPPINGS_ON


#define REFCOUNT_BACKING_STORE_STRING                                  "E114DA43"
#define REFCOUNT_BACKING_STORE_ID                                      0x00f0e2ab
#define REFCOUNT_BACKING_STORE_OVERINSTALL                             0 // OVERRIDE
#define REFCOUNT_BACKING_STORE_DEFAULT                                 0x00000000
#define REFCOUNT_BACKING_STORE_BLOCKLIST                               0x00000001
#define REFCOUNT_BACKING_STORE_MONITORED_FENCE                         0x00000002


#define REFRESHRATEOVERRIDES_STRING                                    "841AH591"
#define REFRESHRATEOVERRIDES_ID                                        0x00e52f42
#define REFRESHRATEOVERRIDES_OVERINSTALL                               0 // OVERRIDE
#define REFRESHRATEOVERRIDES_DEFAULT                                   0


#define REFRESHRATEOVERRIDE_DENYLIST_STRING                            "810FG510"
#define REFRESHRATEOVERRIDE_DENYLIST_ID                                0x003feebc
#define REFRESHRATEOVERRIDE_DENYLIST_OVERINSTALL                       0 // OVERRIDE


#define REFRESH_RATE_OVERRIDE_STRING                                   "5196aef8"
#define REFRESH_RATE_OVERRIDE_ID                                       0x0064b541
#define REFRESH_RATE_OVERRIDE_OVERINSTALL                              1 // MERGE
#define REFRESH_RATE_OVERRIDE_APPLICATION_CONTROLLED                   0x00000000
#define REFRESH_RATE_OVERRIDE_HIGHEST_AVAILABLE                        0x00000001
#define REFRESH_RATE_OVERRIDE_LOW_LATENCY_RR_MASK                      0x00000FF0
#define REFRESH_RATE_OVERRIDE_DEFAULT                                  REFRESH_RATE_OVERRIDE_APPLICATION_CONTROLLED


#define REGCOUNT_GS_MAX_STRING                                         "32156483"
#define REGCOUNT_GS_MAX_ID                                             0x001457e8
#define REGCOUNT_GS_MAX_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_GS_MAX_DEFAULT                                        0xFFFFFFFF


#define REGCOUNT_GS_MIN_STRING                                         "12356843"
#define REGCOUNT_GS_MIN_ID                                             0x00d6f45c
#define REGCOUNT_GS_MIN_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_GS_MIN_DEFAULT                                        0x00000000


#define REGCOUNT_PS_MAX_STRING                                         "00034521"
#define REGCOUNT_PS_MAX_ID                                             0x00c51ec7
#define REGCOUNT_PS_MAX_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_PS_MAX_DEFAULT                                        0xFFFFFFFF


#define REGCOUNT_PS_MIN_STRING                                         "56489120"
#define REGCOUNT_PS_MIN_ID                                             0x00e3c4f8
#define REGCOUNT_PS_MIN_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_PS_MIN_DEFAULT                                        0x00000000


#define REGCOUNT_VS_MAX_STRING                                         "88845674"
#define REGCOUNT_VS_MAX_ID                                             0x00aa85a3
#define REGCOUNT_VS_MAX_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_VS_MAX_DEFAULT                                        0xFFFFFFFF


#define REGCOUNT_VS_MIN_STRING                                         "33325674"
#define REGCOUNT_VS_MIN_ID                                             0x00a83584
#define REGCOUNT_VS_MIN_OVERINSTALL                                    0 // OVERRIDE
#define REGCOUNT_VS_MIN_DEFAULT                                        0x00000000


#define REPORT_D3D12_DDI_SUPPORTED_STRING                              "29567354"
#define REPORT_D3D12_DDI_SUPPORTED_ID                                  0x0003268b
#define REPORT_D3D12_DDI_SUPPORTED_OVERINSTALL                         0 // OVERRIDE
#define REPORT_D3D12_DDI_SUPPORTED_DEFAULT                             0x000000FF


#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_STRING         "fac428"
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_ID             0x00fac428
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_OVERINSTALL    0 // OVERRIDE
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_OFF            0
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_DISABLED       0
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_ON             1
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_ENABLED        1
#define RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_DEFAULT        RESET_FREE_GPFIFO_ENTRIES_IN_UMD_MANAGED_GPFIFO_OFF


#define RESOURCEMINLODOPTIMIZATIONENABLE_STRING                        "6a8fafed"
#define RESOURCEMINLODOPTIMIZATIONENABLE_ID                            0x003c40ca
#define RESOURCEMINLODOPTIMIZATIONENABLE_OVERINSTALL                   0 // OVERRIDE
#define RESOURCEMINLODOPTIMIZATIONENABLE_OFF                           0x9739af35
#define RESOURCEMINLODOPTIMIZATIONENABLE_DISABLED                      0x9739af35
#define RESOURCEMINLODOPTIMIZATIONENABLE_ON                            0xdef2fe3a
#define RESOURCEMINLODOPTIMIZATIONENABLE_ENABLED                       0xdef2fe3a
#define RESOURCEMINLODOPTIMIZATIONENABLE_DEFAULT                       RESOURCEMINLODOPTIMIZATIONENABLE_OFF


#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_STRING                  "fad419"
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_ID                      0x00fad419
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_OVERINSTALL             0 // OVERRIDE
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_OFF                     0
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_DISABLED                0
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_ON                      1
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_ENABLED                 1
#define REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_DEFAULT                 REUSE_FREE_SPACE_IN_UMD_MANAGED_GPFIFO_ON


#define RIDSHIM_STRING                                                 "34578954"
#define RIDSHIM_ID                                                     0x00a8a36b
#define RIDSHIM_OVERINSTALL                                            0 // OVERRIDE
#define RIDSHIM_ENABLE                                                 0x00000001
#define RIDSHIM_DUMP_LOG                                               0x00000002
#define RIDSHIM_DUMP_PRESENT_SURFACES                                  0x00000004
#define RIDSHIM_CREATE_FRAME_DIRECTORIES                               0x00000008
#define RIDSHIM_START_DUMP_DISABLED                                    0x00000010
#define RIDSHIM_DUMP_PRE_DRAW                                          0x00000020
#define RIDSHIM_ENABLE_HOTKEYS                                         0x00000040
#define RIDSHIM_DUMP_RT_AFTER_PRESENT                                  0x00000080
#define RIDSHIM_DUMP_RT_AFTER_DRAW                                     0x00000100
#define RIDSHIM_DUMP_DS_AFTER_DRAW                                     0x00000200
#define RIDSHIM_DUMP_RT_ON_SETRTV                                      0x00000400
#define RIDSHIM_DUMP_DS_ON_SETRTV                                      0x00000800
#define RIDSHIM_DUMP_CS_UAV_AFTER_DISPATCH                             0x00001000
#define RIDSHIM_DUMP_3D_UAV_AFTER_DRAW                                 0x00002000
#define RIDSHIM_DUMP_CS_UAV_ON_SETUAV                                  0x00004000
#define RIDSHIM_DUMP_3D_UAV_ON_SETUAV                                  0x00008000
#define RIDSHIM_DUMP_VS_SRV_AFTER_DRAW                                 0x00100000
#define RIDSHIM_DUMP_HS_SRV_AFTER_DRAW                                 0x00200000
#define RIDSHIM_DUMP_DS_SRV_AFTER_DRAW                                 0x00400000
#define RIDSHIM_DUMP_GS_SRV_AFTER_DRAW                                 0x00800000
#define RIDSHIM_DUMP_PS_SRV_AFTER_DRAW                                 0x01000000
#define RIDSHIM_DUMP_CS_SRV_AFTER_DRAW                                 0x02000000
#define RIDSHIM_DUMP_ALL_AFTER_CROSSADAPTER_COPY                       0x10000000


#define RIDSHIM9_STRING                                                "34578999"
#define RIDSHIM9_ID                                                    0x00a8a36c
#define RIDSHIM9_OVERINSTALL                                           0 // OVERRIDE
#define RIDSHIM9_DISABLE                                               0x00000000
#define RIDSHIM9_DUMP_ERRORLOG                                         0x00000002
#define RIDSHIM9_DUMP_RT                                               0x00000004
#define RIDSHIM9_DUMP_TEXTURE                                          0x00000008
#define RIDSHIM9_DUMP_ZBUFFER                                          0x00000010
#define RIDSHIM9_CREATE_FRAME_DIRECTORIES                              0x00000020
#define RIDSHIM9_ENABLE_HOTKEYS                                        0x00000040
#define RIDSHIM9_DUMP_BEFORE_DRAW                                      0x00000080
#define RIDSHIM9_DUMP_AFTER_DRAW                                       0x00000100
#define RIDSHIM9_DUMP_BEFORE_PRESENT                                   0x00000200
#define RIDSHIM9_DUMP_AFTER_PRESENT                                    0x00000400
#define RIDSHIM9_DUMP_BEFORE_BLT                                       0x00000800
#define RIDSHIM9_DUMP_AFTER_BLT                                        0x00001000
#define RIDSHIM9_DUMP_BEFORE_COLORFILL                                 0x00002000
#define RIDSHIM9_DUMP_AFTER_COLORFILL                                  0x00004000
#define RIDSHIM9_DUMP_BEFORE_DEPTHFILL                                 0x00008000
#define RIDSHIM9_DUMP_AFTER_DEPTHFILL                                  0x00010000
#define RIDSHIM9_DUMP_BEFORE_CLEAR                                     0x00020000
#define RIDSHIM9_DUMP_AFTER_CLEAR                                      0x00040000
#define RIDSHIM9_DUMP_BEFORE_UPDATESUBRES                              0x00080000
#define RIDSHIM9_DUMP_AFTER_UPDATESUBRES                               0x00100000
#define RIDSHIM9_DUMP_VB                                               0x00200000
#define RIDSHIM9_DUMP_IB                                               0x00400000
#define RIDSHIM9_DUMP_BEFORE_PRESENT_MSHYBRID                          0x00800000
#define RIDSHIM9_DUMP_AFTER_PRESENT_MSHYBRID                           0x01000000
#define RIDSHIM9_DUMP_BEFORE_BLT_MSHYBRID                              0x02000000
#define RIDSHIM9_DUMP_AFTER_BLT_MSHYBRID                               0x04000000
#define RIDSHIM9_DUMP_AS_IMAGE                                         0x10000000
#define RIDSHIM9_DUMP_AS_TEXT                                          0x20000000
#define RIDSHIM9_DEFAULT                                               RIDSHIM9_DISABLE


#define RIDSHIM9_BASEDIR_STRING                                        "34578945"
#define RIDSHIM9_BASEDIR_ID                                            0x00f5fddf
#define RIDSHIM9_BASEDIR_OVERINSTALL                                   0 // OVERRIDE


#define RIDSHIM9_DRAWPERFRAME_RANGE_STRING                             "34574957"
#define RIDSHIM9_DRAWPERFRAME_RANGE_ID                                 0x00102371
#define RIDSHIM9_DRAWPERFRAME_RANGE_OVERINSTALL                        0 // OVERRIDE


#define RIDSHIM9_DRAW_RANGE_STRING                                     "34577956"
#define RIDSHIM9_DRAW_RANGE_ID                                         0x00102380
#define RIDSHIM9_DRAW_RANGE_OVERINSTALL                                0 // OVERRIDE


#define RIDSHIM9_IMAGE_FORMAT_STRING                                   "34578979"
#define RIDSHIM9_IMAGE_FORMAT_ID                                       0x00bf6515
#define RIDSHIM9_IMAGE_FORMAT_OVERINSTALL                              0 // OVERRIDE


#define RIDSHIM9_PRESENT_RANGE_STRING                                  "34577957"
#define RIDSHIM9_PRESENT_RANGE_ID                                      0x00102381
#define RIDSHIM9_PRESENT_RANGE_OVERINSTALL                             0 // OVERRIDE


#define RIDSHIM9_SINGLE_FRAME_HOTKEY_STRING                            "34578977"
#define RIDSHIM9_SINGLE_FRAME_HOTKEY_ID                                0x0021df14
#define RIDSHIM9_SINGLE_FRAME_HOTKEY_OVERINSTALL                       0 // OVERRIDE


#define RIDSHIM9_TOGGLE_HOTKEY_STRING                                  "34578978"
#define RIDSHIM9_TOGGLE_HOTKEY_ID                                      0x009f9e95
#define RIDSHIM9_TOGGLE_HOTKEY_OVERINSTALL                             0 // OVERRIDE


#define RIDSHIM_BASEDIR_STRING                                         "34578955"
#define RIDSHIM_BASEDIR_ID                                             0x00f5f9df
#define RIDSHIM_BASEDIR_OVERINSTALL                                    0 // OVERRIDE


#define RIDSHIM_DRAW_RANGE_STRING                                      "44577956"
#define RIDSHIM_DRAW_RANGE_ID                                          0x00202380
#define RIDSHIM_DRAW_RANGE_OVERINSTALL                                 0 // OVERRIDE


#define RIDSHIM_FRAMES_STRING                                          "34578956"
#define RIDSHIM_FRAMES_ID                                              0x00102480
#define RIDSHIM_FRAMES_OVERINSTALL                                     0 // OVERRIDE


#define RIDSHIM_IMAGE_FORMAT_STRING                                    "34578959"
#define RIDSHIM_IMAGE_FORMAT_ID                                        0x00bf6505
#define RIDSHIM_IMAGE_FORMAT_OVERINSTALL                               0 // OVERRIDE


#define RIDSHIM_SINGLE_FRAME_HOTKEY_STRING                             "34578957"
#define RIDSHIM_SINGLE_FRAME_HOTKEY_ID                                 0x0021df13
#define RIDSHIM_SINGLE_FRAME_HOTKEY_OVERINSTALL                        0 // OVERRIDE


#define RIDSHIM_TOGGLE_HOTKEY_STRING                                   "34578958"
#define RIDSHIM_TOGGLE_HOTKEY_ID                                       0x009f9ef5
#define RIDSHIM_TOGGLE_HOTKEY_OVERINSTALL                              0 // OVERRIDE


#define RTCQ_SCHEDULING_STRING                                         "FA67B634"
#define RTCQ_SCHEDULING_ID                                             0x0093e45a
#define RTCQ_SCHEDULING_OVERINSTALL                                    0 // OVERRIDE
#define RTCQ_SCHEDULING_USE_MIDBUFFERPREEMPTION                        0x00000000
#define RTCQ_SCHEDULING_USE_LOWLATENCY                                 0x00000001
#define RTCQ_SCHEDULING_DEFAULT                                        RTCQ_SCHEDULING_USE_LOWLATENCY


#define RTXIO_FLAGS_STRING                                             "0xa3c15d"
#define RTXIO_FLAGS_ID                                                 0x00a3c15d
#define RTXIO_FLAGS_OVERINSTALL                                        0 // OVERRIDE
#define RTXIO_FLAGS_NONE                                               0
#define RTXIO_FLAGS_VIDMEM_STAGING_ENABLE                              0x01
#define RTXIO_FLAGS_HOST_STAGING_ALWAYS_MAPPED                         0x02
#define RTXIO_FLAGS_ENABLE_DRIVER_THREAD                               0x04
#define RTXIO_FLAGS_NVME_BATCH_READS                                   0x08
#define RTXIO_FLAGS_DEFAULT                                            RTXIO_FLAGS_ENABLE_DRIVER_THREAD


#define RTXIO_MAX_SOURCE_READ_SIZE_STRING                              "0xa3315a"
#define RTXIO_MAX_SOURCE_READ_SIZE_ID                                  0x00a3315a
#define RTXIO_MAX_SOURCE_READ_SIZE_OVERINSTALL                         0 // OVERRIDE
#define RTXIO_MAX_SOURCE_READ_SIZE_DEFAULT                             0


#define RTXIO_NVME_MAX_READ_PER_CMD_STRING                             "0xa33158"
#define RTXIO_NVME_MAX_READ_PER_CMD_ID                                 0x00a33158
#define RTXIO_NVME_MAX_READ_PER_CMD_OVERINSTALL                        0 // OVERRIDE
#define RTXIO_NVME_MAX_READ_PER_CMD_DEFAULT                            0x0


#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_STRING                       "0xa66156"
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_ID                           0x00a66156
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_OVERINSTALL                  0 // OVERRIDE
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_OFF                          0
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_DISABLED                     0
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_ON                           1
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_ENABLED                      1
#define RTXIO_NVME_RESERVED_QUEUES_ENABLE_DEFAULT                      RTXIO_NVME_RESERVED_QUEUES_ENABLE_OFF


#define RTXIO_NVME_USE_LBA_UMD_STRING                                  "0xa33157"
#define RTXIO_NVME_USE_LBA_UMD_ID                                      0x00a33157
#define RTXIO_NVME_USE_LBA_UMD_OVERINSTALL                             0 // OVERRIDE
#define RTXIO_NVME_USE_LBA_UMD_OFF                                     0
#define RTXIO_NVME_USE_LBA_UMD_0                                       0
#define RTXIO_NVME_USE_LBA_UMD_FALSE                                   0
#define RTXIO_NVME_USE_LBA_UMD_DISABLED                                0
#define RTXIO_NVME_USE_LBA_UMD_ON                                      1
#define RTXIO_NVME_USE_LBA_UMD_1                                       1
#define RTXIO_NVME_USE_LBA_UMD_TRUE                                    1
#define RTXIO_NVME_USE_LBA_UMD_ENABLED                                 1
#define RTXIO_NVME_USE_LBA_UMD_DEFAULT                                 RTXIO_NVME_USE_LBA_UMD_OFF


#define RTXIO_OVERRIDE_STAGING_BUFFER_SIZE_STRING                      "0xa3315b"
#define RTXIO_OVERRIDE_STAGING_BUFFER_SIZE_ID                          0x00a3315b
#define RTXIO_OVERRIDE_STAGING_BUFFER_SIZE_OVERINSTALL                 0 // OVERRIDE
#define RTXIO_OVERRIDE_STAGING_BUFFER_SIZE_DEFAULT                     0


#define RUN_CTA_IN_ONE_SM_PARTITION_STRING                             "00237583"
#define RUN_CTA_IN_ONE_SM_PARTITION_ID                                 0x00237583
#define RUN_CTA_IN_ONE_SM_PARTITION_OVERINSTALL                        0 // OVERRIDE
#define RUN_CTA_IN_ONE_SM_PARTITION_OFF                                0x00000000
#define RUN_CTA_IN_ONE_SM_PARTITION_ON                                 0x00000001


#define RUN_CTA_IN_ONE_SM_PARTITION_MAX_WARP_COUNT_STRING              "00237444"
#define RUN_CTA_IN_ONE_SM_PARTITION_MAX_WARP_COUNT_ID                  0x00237444
#define RUN_CTA_IN_ONE_SM_PARTITION_MAX_WARP_COUNT_OVERINSTALL         0 // OVERRIDE
#define RUN_CTA_IN_ONE_SM_PARTITION_MAX_WARP_COUNT_DEFAULT             0xffffffff


#define SCGLOG_FIRST_CL_STRING                                         "0xa2fd89"
#define SCGLOG_FIRST_CL_ID                                             0x00a2fd89
#define SCGLOG_FIRST_CL_OVERINSTALL                                    0 // OVERRIDE
#define SCGLOG_FIRST_CL_DEFAULT                                        0


#define SCGLOG_FIRST_FRAME_STRING                                      "0xa25fc8"
#define SCGLOG_FIRST_FRAME_ID                                          0x00a25fc8
#define SCGLOG_FIRST_FRAME_OVERINSTALL                                 0 // OVERRIDE
#define SCGLOG_FIRST_FRAME_DEFAULT                                     0


#define SCGLOG_FLAGS_STRING                                            "0xa25fc7"
#define SCGLOG_FLAGS_ID                                                0x00a25fc7
#define SCGLOG_FLAGS_OVERINSTALL                                       0 // OVERRIDE
#define SCGLOG_FLAGS_LOG_PUSHBUFFER_FLUSHES                            1
#define SCGLOG_FLAGS_LOG_GR_vs_CS_HAZARDS                              2
#define SCGLOG_FLAGS_LOG_CS_vs_CS_HAZARDS                              4
#define SCGLOG_FLAGS_LOG_REFCOUNTS                                     8
#define SCGLOG_FLAGS_LOG_PER_FRAME_SCG_QUERY                           0x100
#define SCGLOG_FLAGS_DEFAULT                                           0


#define SCGLOG_LAST_CL_STRING                                          "0xa2fd8a"
#define SCGLOG_LAST_CL_ID                                              0x00a2fd8a
#define SCGLOG_LAST_CL_OVERINSTALL                                     0 // OVERRIDE
#define SCGLOG_LAST_CL_DEFAULT                                         0xFFFFFFFF


#define SCGLOG_LAST_FRAME_STRING                                       "0xa25fc9"
#define SCGLOG_LAST_FRAME_ID                                           0x00a25fc9
#define SCGLOG_LAST_FRAME_OVERINSTALL                                  0 // OVERRIDE
#define SCGLOG_LAST_FRAME_DEFAULT                                      0xFFFFFFFF


#define SCGLOG_QUERY_MASK_STRING                                       "0xa2efc7"
#define SCGLOG_QUERY_MASK_ID                                           0x00a2efc7
#define SCGLOG_QUERY_MASK_OVERINSTALL                                  0 // OVERRIDE
#define SCGLOG_QUERY_MASK_GRAPHICS_ACTIVE_CYCLES                       0x001
#define SCGLOG_QUERY_MASK_COMPUTE_ACTIVE_CYCLES                        0x002
#define SCGLOG_QUERY_MASK_IDLE_CYCLES                                  0x004
#define SCGLOG_QUERY_MASK_GRAPHICS_OCCUPANCY                           0x008
#define SCGLOG_QUERY_MASK_UNUSED_0                                     0x010
#define SCGLOG_QUERY_MASK_DEBUG_COUNTER                                0x020
#define SCGLOG_QUERY_MASK_COMPUTE_OCCUPANCY                            0x040
#define SCGLOG_QUERY_MASK_UNUSED_1                                     0x080
#define SCGLOG_QUERY_MASK_DEFAULT                                      0x0000006f


#define SCG_D3D12_COMPUTE_QUEUES_STRING                                "0xe1d8a1"
#define SCG_D3D12_COMPUTE_QUEUES_ID                                    0x000c2132
#define SCG_D3D12_COMPUTE_QUEUES_OVERINSTALL                           0 // OVERRIDE
#define SCG_D3D12_COMPUTE_QUEUES_ENABLED                               0x00000001
#define SCG_D3D12_COMPUTE_QUEUES_DISABLED                              0
#define SCG_D3D12_COMPUTE_QUEUES_DEFAULT                               SCG_D3D12_COMPUTE_QUEUES_ENABLED


#define SCG_D3D12_CONTROL_FILE_STRING                                  "0x1c19fe"
#define SCG_D3D12_CONTROL_FILE_ID                                      0x001c19fe
#define SCG_D3D12_CONTROL_FILE_OVERINSTALL                             0 // OVERRIDE


#define SCG_D3D12_CONTROL_FLAGS_STRING                                 "0x1c19fd"
#define SCG_D3D12_CONTROL_FLAGS_ID                                     0x001c19fd
#define SCG_D3D12_CONTROL_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define SCG_D3D12_CONTROL_FLAGS_DISABLE_CL_HAZARD_DETECT               0x0001
#define SCG_D3D12_CONTROL_FLAGS_FORCE_GR_SEMAPHORE_WFI                 0x0010
#define SCG_D3D12_CONTROL_FLAGS_FORCE_CS_SEMAPHORE_WFI                 0x0020
#define SCG_D3D12_CONTROL_FLAGS_FORCE_GR_HOST_WFI                      0x0040
#define SCG_D3D12_CONTROL_FLAGS_FORCE_CS_HOST_WFI                      0x0080
#define SCG_D3D12_CONTROL_FLAGS_DISABLE_STATIC_CONFIG                  0x0100
#define SCG_D3D12_CONTROL_FLAGS_DISABLE_CL_INITIAL_DESCRIPTOR_HEAP_SET_ON_PBDMA1 0x0200
#define SCG_D3D12_CONTROL_FLAGS_DEFAULT                                0


#define SCG_D3D12_DEBUG_FLAGS_STRING                                   "0x1c19ff"
#define SCG_D3D12_DEBUG_FLAGS_ID                                       0x001c19ff
#define SCG_D3D12_DEBUG_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define SCG_D3D12_DEBUG_FLAGS_DUMP_ASYNC_CS_DEVICE_SHADER_HASH         0x01
#define SCG_D3D12_DEBUG_FLAGS_DUMP_SYNC_GR_CS_DEVICE_SHADER_HASH       0x02
#define SCG_D3D12_DEBUG_FLAGS_DUMP_SHADER_GROUP_TIMESTAMPS             0x04
#define SCG_D3D12_DEBUG_FLAGS_REMOVE_REDUNDANT_HASHES                  0x10
#define SCG_D3D12_DEBUG_FLAGS_DUMP_TO_DEBUGGER                         0x20
#define SCG_D3D12_DEBUG_FLAGS_DUMP_SCG_STATE_HAZARDS                   0x40
#define SCG_D3D12_DEBUG_FLAGS_DEFAULT                                  0x0


#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_STRING                "0xde2ed0"
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_ID                    0x00db1d88
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_OVERINSTALL           0 // OVERRIDE
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_OFF                   0
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_DISABLED              0
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_ON                    1
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_ENABLED               1
#define SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_DEFAULT               SCG_D3D12_ENABLE_DYNAMIC_SMSCG_HEURISTIC_OFF


#define SCG_D3D12_FAST_DRAIN_THROTTLE_STRING                           "0xcd0a8a"
#define SCG_D3D12_FAST_DRAIN_THROTTLE_ID                               0x00cd0a8a
#define SCG_D3D12_FAST_DRAIN_THROTTLE_OVERINSTALL                      0 // OVERRIDE
#define SCG_D3D12_FAST_DRAIN_THROTTLE_OFF                              0
#define SCG_D3D12_FAST_DRAIN_THROTTLE_DISABLED                         0
#define SCG_D3D12_FAST_DRAIN_THROTTLE_ON                               1
#define SCG_D3D12_FAST_DRAIN_THROTTLE_ENABLED                          1
#define SCG_D3D12_FAST_DRAIN_THROTTLE_DEFAULT                          SCG_D3D12_FAST_DRAIN_THROTTLE_OFF


#define SCG_D3D12_GPU_HAZARD_RESOLVE_STRING                            "0xcd0a89"
#define SCG_D3D12_GPU_HAZARD_RESOLVE_ID                                0x00cd0a89
#define SCG_D3D12_GPU_HAZARD_RESOLVE_OVERINSTALL                       0 // OVERRIDE
#define SCG_D3D12_GPU_HAZARD_RESOLVE_OFF                               0
#define SCG_D3D12_GPU_HAZARD_RESOLVE_DISABLED                          0
#define SCG_D3D12_GPU_HAZARD_RESOLVE_ON                                1
#define SCG_D3D12_GPU_HAZARD_RESOLVE_ENABLED                           1
#define SCG_D3D12_GPU_HAZARD_RESOLVE_DEFAULT                           SCG_D3D12_GPU_HAZARD_RESOLVE_OFF


#define SCG_D3D12_REMOVE_BACKUP_DEVICE_STRING                          "0xe1d8a2"
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_ID                              0x00c2132a
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_OVERINSTALL                     0 // OVERRIDE
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_REMOVE_BACKUP_DEVICE            0x00000001
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_REMOVE_PROMOTION_CONTEXT        0x00000002
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_REMOVE_BOTH                     0x00000003
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_DISABLED                        0
#define SCG_D3D12_REMOVE_BACKUP_DEVICE_DEFAULT                         SCG_D3D12_REMOVE_BACKUP_DEVICE_DISABLED


#define SCG_D3D12_SINGLE_NODE_STRING                                   "0x10ef2e"
#define SCG_D3D12_SINGLE_NODE_ID                                       0x00a1232f
#define SCG_D3D12_SINGLE_NODE_OVERINSTALL                              0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_OFF                                      0
#define SCG_D3D12_SINGLE_NODE_DISABLED                                 0
#define SCG_D3D12_SINGLE_NODE_ON                                       1
#define SCG_D3D12_SINGLE_NODE_ENABLED                                  1
#define SCG_D3D12_SINGLE_NODE_DEFAULT                                  SCG_D3D12_SINGLE_NODE_ON


#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_STRING                          "0x7ae814"
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_ID                              0x007ae814
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_OVERINSTALL                     0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_DISABLED                        0
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_ENABLE_SCG_AT_HIGH_LEVEL        0x1
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_ENABLE_SCG_AT_LOW_LEVEL         0x2
#define SCG_D3D12_SINGLE_NODE_AUTO_SCG_DEFAULT                         SCG_D3D12_SINGLE_NODE_AUTO_SCG_DISABLED


#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_STRING                       "0x607695"
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_ID                           0x00607695
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_OVERINSTALL                  0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_OFF                          0
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_DISABLED                     0
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_ON                           1
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_ENABLED                      1
#define SCG_D3D12_SINGLE_NODE_DRIVER_COPY_DEFAULT                      SCG_D3D12_SINGLE_NODE_DRIVER_COPY_OFF


#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_STRING                "0x5bc650"
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_ID                    0x005bc650
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_OVERINSTALL           0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_OFF                   0
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_DISABLED              0
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_ON                    1
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_ENABLED               1
#define SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_DEFAULT               SCG_D3D12_SINGLE_NODE_DRIVER_PRE_EXECUTE_OFF


#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_STRING                "0xcd1c8b"
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_ID                    0x00befb7b
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_OVERINSTALL           0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_OFF                   0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_DISABLED              0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_ON                    1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_ENABLED               1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_DEFAULT               SCG_D3D12_SINGLE_NODE_DRIVER_SCG_COMPUTE_ON


#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_STRING               "0xdf3ed0"
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_ID                   0x00dc1999
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_OVERINSTALL          0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_OFF                  0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_DISABLED             0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_ON                   1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_ENABLED              1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_DEFAULT              SCG_D3D12_SINGLE_NODE_DRIVER_SCG_GRAPHICS_ON


#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_STRING      "0xcdf4ea"
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_ID          0x00cdf4ea
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_OVERINSTALL 0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_OFF         0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_DISABLED    0
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_ON          1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_ENABLED     1
#define SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_DEFAULT     SCG_D3D12_SINGLE_NODE_DRIVER_SCG_NO_BROADCAST_WAIT_ON


#define SCG_D3D12_SINGLE_NODE_LDA_STRING                               "0x10ef30"
#define SCG_D3D12_SINGLE_NODE_LDA_ID                                   0x00a12330
#define SCG_D3D12_SINGLE_NODE_LDA_OVERINSTALL                          0 // OVERRIDE
#define SCG_D3D12_SINGLE_NODE_LDA_NONE                                 0
#define SCG_D3D12_SINGLE_NODE_LDA_0                                    0
#define SCG_D3D12_SINGLE_NODE_LDA_ALL                                  1
#define SCG_D3D12_SINGLE_NODE_LDA_1                                    1
#define SCG_D3D12_SINGLE_NODE_LDA_TURING_AND_NEWER                     2
#define SCG_D3D12_SINGLE_NODE_LDA_AMPERE_AND_NEWER                     3
#define SCG_D3D12_SINGLE_NODE_LDA_DEFAULT                              SCG_D3D12_SINGLE_NODE_LDA_AMPERE_AND_NEWER


#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_STRING                   "0x1d3a0f"
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_ID                       0x000cc8ec
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_OVERINSTALL              0 // OVERRIDE
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_BUILD_BVH_COMPUTE 0x00001
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_DISPATCH_RAYS_COMPUTE 0x00002
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_EMIT_BVH_INFO_COMPUTE 0x00004
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_COPY_BVH_COMPUTE 0x00008
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_SET_PIPELINE_STATE_COMPUTE 0x00010
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_INIT_META_COMMAND_COMPUTE 0x00020
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_EXECUTE_META_COMMAND_COMPUTE 0x00040
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_LAUNCH_CUBIN_COMPUTE 0x00080
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_COMPUTE_MASK 0x000FF
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_BUILD_BVH_DIRECT 0x00100
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_DISPATCH_RAYS_DIRECT 0x00200
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_EMIT_BVH_INFO_DIRECT 0x00400
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_COPY_BVH_DIRECT 0x00800
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_SET_PIPELINE_STATE_DIRECT 0x01000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_INIT_META_COMMAND_DIRECT 0x02000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_EXECUTE_META_COMMAND_DIRECT 0x04000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_LAUNCH_CUBIN_DIRECT 0x08000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_DIRECT_MASK 0x0FF00
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_DEFAULT_COMPUTE 0x10000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DISABLE_SMSCG_DEFAULT_DIRECT 0x20000
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_DYNAMIC_DEFAULT                  0


#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_STRING                    "0x2d2a0f"
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_ID                        0x000b08ec
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_OVERINSTALL               0 // OVERRIDE
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_ENABLE_SMSCG_WITH_DXR     0x1
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_ENABLE_SMSCG_WITH_META_COMMANDS 0x2
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_ENABLE_SMSCG_DEFERRED_INIT 0x4
#define SCG_D3D12_SMSCG_CONTROL_FLAGS_STATIC_ENABLE_SMSCG_FOR_DRIVER_SCG 0x8


#define SCG_DEBUG_COUNTER_MODE_STRING                                  "0x128890"
#define SCG_DEBUG_COUNTER_MODE_ID                                      0x00128890
#define SCG_DEBUG_COUNTER_MODE_OVERINSTALL                             0 // OVERRIDE
#define SCG_DEBUG_COUNTER_MODE_GFX_PIX_QUADS_0                         0x0
#define SCG_DEBUG_COUNTER_MODE_GFX_PIX_QUADS_1                         0x1
#define SCG_DEBUG_COUNTER_MODE_WARP_DRAIN                              0x2
#define SCG_DEBUG_COUNTER_MODE_OCCUPANCY_EXCL_ISBE                     0x3
#define SCG_DEBUG_COUNTER_MODE_DEFAULT                                 SCG_DEBUG_COUNTER_MODE_OCCUPANCY_EXCL_ISBE


#define SCG_GRAPHICS_CQ_ID_STRING                                      "0x109439"
#define SCG_GRAPHICS_CQ_ID_ID                                          0x00109493
#define SCG_GRAPHICS_CQ_ID_OVERINSTALL                                 0 // OVERRIDE
#define SCG_GRAPHICS_CQ_ID_DEFAULT                                     0


#define SCG_GRAPHICS_PRIORITY_STRING                                   "EDD838"
#define SCG_GRAPHICS_PRIORITY_ID                                       0x00a44b68
#define SCG_GRAPHICS_PRIORITY_OVERINSTALL                              0 // OVERRIDE
#define SCG_GRAPHICS_PRIORITY_DEFAULT                                  16


#define SCG_GR_HAZARD_CONTROL_STRING                                   "0xa223f6"
#define SCG_GR_HAZARD_CONTROL_ID                                       0x00a223f6
#define SCG_GR_HAZARD_CONTROL_OVERINSTALL                              0 // OVERRIDE
#define SCG_GR_HAZARD_CONTROL_DRIVER_CONTROLLED                        0
#define SCG_GR_HAZARD_CONTROL_FORCE_WFI                                1
#define SCG_GR_HAZARD_CONTROL_FORCE_SEMAPHORE                          2
#define SCG_GR_HAZARD_CONTROL_MODE_CONTROL_MASK                        0xFF
#define SCG_GR_HAZARD_CONTROL_FORCE_HOST_WAIT                          0x100
#define SCG_GR_HAZARD_CONTROL_DEFAULT                                  SCG_GR_HAZARD_CONTROL_DRIVER_CONTROLLED


#define SCG_NVAPI_SAMPLER_HEADER_POOL_SIZE_STRING                      "0xadc451"
#define SCG_NVAPI_SAMPLER_HEADER_POOL_SIZE_ID                          0x009a8c93
#define SCG_NVAPI_SAMPLER_HEADER_POOL_SIZE_OVERINSTALL                 0 // OVERRIDE
#define SCG_NVAPI_SAMPLER_HEADER_POOL_SIZE_DEFAULT                     0x7FF


#define SCG_NVAPI_SHADER_HEAP_SIZE_STRING                              "0x835adf"
#define SCG_NVAPI_SHADER_HEAP_SIZE_ID                                  0x00f1afb4
#define SCG_NVAPI_SHADER_HEAP_SIZE_OVERINSTALL                         0 // OVERRIDE
#define SCG_NVAPI_SHADER_HEAP_SIZE_DEFAULT                             0x100000


#define SCG_NVAPI_TEXTURE_HEADER_POOL_SIZE_STRING                      "0x2f2cce"
#define SCG_NVAPI_TEXTURE_HEADER_POOL_SIZE_ID                          0x0012ce3c
#define SCG_NVAPI_TEXTURE_HEADER_POOL_SIZE_OVERINSTALL                 0 // OVERRIDE
#define SCG_NVAPI_TEXTURE_HEADER_POOL_SIZE_DEFAULT                     0x20000


#define SCG_QMD_USE_DEPENDENT_POINTER_STRING                           "0x37777a"
#define SCG_QMD_USE_DEPENDENT_POINTER_ID                               0x0037777a
#define SCG_QMD_USE_DEPENDENT_POINTER_OVERINSTALL                      0 // OVERRIDE
#define SCG_QMD_USE_DEPENDENT_POINTER_OFF                              0x0
#define SCG_QMD_USE_DEPENDENT_POINTER_DISABLED                         0x0
#define SCG_QMD_USE_DEPENDENT_POINTER_ON                               0x1
#define SCG_QMD_USE_DEPENDENT_POINTER_ENABLED                          0x1
#define SCG_QMD_USE_DEPENDENT_POINTER_DEFAULT                          SCG_QMD_USE_DEPENDENT_POINTER_OFF


#define SCG_SINGLE_NODE_STRING                                         "0xa25fc4"
#define SCG_SINGLE_NODE_ID                                             0x00a25fc4
#define SCG_SINGLE_NODE_OVERINSTALL                                    0 // OVERRIDE
#define SCG_SINGLE_NODE_DISABLED                                       0
#define SCG_SINGLE_NODE_ENABLED                                        0x00000001
#define SCG_SINGLE_NODE_CONDITIONAL_PASCAL                             0x10000001
#define SCG_SINGLE_NODE_CONDITIONAL_PASCAL_PLUS                        0x20000001
#define SCG_SINGLE_NODE_DISABLED_ON_SLI                                0x00000002
#define SCG_SINGLE_NODE_DISABLED_ON_SLI_HWS                            0x00000004
#define SCG_SINGLE_NODE_AMPERE_DISABLE_SMSCG                           0x00000008
#define SCG_SINGLE_NODE_DISABLED_WITH_HWS_OFF                          0x00000010
#define SCG_SINGLE_NODE_DEFAULT                                        SCG_SINGLE_NODE_DISABLED


#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_STRING                     "bab1fe42"
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_ID                         0x00c79f0d
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_OVERINSTALL                0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_OFF                        0x00000000
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_DISABLED                   0x00000000
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_ON                         0x00000001
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_ENABLED                    0x00000001
#define SETREDUCECOLORTHRESHOLDSFORCEENABLE_DEFAULT                    SETREDUCECOLORTHRESHOLDSFORCEENABLE_OFF


#define SETREDUCECOLORTHRESHOLDSFP11_STRING                            "b1fbaf43"
#define SETREDUCECOLORTHRESHOLDSFP11_ID                                0x006b49bf
#define SETREDUCECOLORTHRESHOLDSFP11_OVERINSTALL                       0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSFP11_DEFAULT                           0x3f


#define SETREDUCECOLORTHRESHOLDSFP16_STRING                            "a2fb451e"
#define SETREDUCECOLORTHRESHOLDSFP16_ID                                0x00467b8c
#define SETREDUCECOLORTHRESHOLDSFP16_OVERINSTALL                       0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSFP16_DEFAULT                           0xff


#define SETREDUCECOLORTHRESHOLDSSRGB8_STRING                           "e435563f"
#define SETREDUCECOLORTHRESHOLDSSRGB8_ID                               0x007e811e
#define SETREDUCECOLORTHRESHOLDSSRGB8_OVERINSTALL                      0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSSRGB8_DEFAULT                          0xff


#define SETREDUCECOLORTHRESHOLDSUNORM10_STRING                         "1acf43fe"
#define SETREDUCECOLORTHRESHOLDSUNORM10_ID                             0x00febcb0
#define SETREDUCECOLORTHRESHOLDSUNORM10_OVERINSTALL                    0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSUNORM10_DEFAULT                        0xff


#define SETREDUCECOLORTHRESHOLDSUNORM16_STRING                         "1bda43fe"
#define SETREDUCECOLORTHRESHOLDSUNORM16_ID                             0x002dc7ff
#define SETREDUCECOLORTHRESHOLDSUNORM16_OVERINSTALL                    0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSUNORM16_DEFAULT                        0xff


#define SETREDUCECOLORTHRESHOLDSUNORM8_STRING                          "b1fb0f01"
#define SETREDUCECOLORTHRESHOLDSUNORM8_ID                              0x00a2de5f
#define SETREDUCECOLORTHRESHOLDSUNORM8_OVERINSTALL                     0 // OVERRIDE
#define SETREDUCECOLORTHRESHOLDSUNORM8_DEFAULT                         0xff


#define SETTESSELLATIONCUTHEIGHT_STRING                                "fb347cce"
#define SETTESSELLATIONCUTHEIGHT_ID                                    0x00d8ad1f
#define SETTESSELLATIONCUTHEIGHT_OVERINSTALL                           0 // OVERRIDE
#define SETTESSELLATIONCUTHEIGHT_DEFAULT                               0x8


#define SETVTGREGISTERWATERMARKS_STRING                                "beefcba2"
#define SETVTGREGISTERWATERMARKS_ID                                    0x00f58a2d
#define SETVTGREGISTERWATERMARKS_OVERINSTALL                           0 // OVERRIDE
#define SETVTGREGISTERWATERMARKS_DEFAULT_MAXWELL                       0x08000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_PASCAL_A                      0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_PASCAL_B                      0x08000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_VOLTA_A                       0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_TURING_A                      0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_AMPERE_A                      0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_AMPERE_B                      0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_ADA_A                         0x10000080
#define SETVTGREGISTERWATERMARKS_DEFAULT_HOPPER_A                      0x10000080


#define SETVTGWARPWATERMARKS_STRING                                    "beefcba1"
#define SETVTGWARPWATERMARKS_ID                                        0x00f5874f
#define SETVTGWARPWATERMARKS_OVERINSTALL                               0 // OVERRIDE
#define SETVTGWARPWATERMARKS_DEFAULT_MAXWELL                           0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_PASCAL_A                          0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_PASCAL_B                          0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_VOLTA_A                           0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_TURING_A                          0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_AMPERE_A                          0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_AMPERE_B                          0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_ADA_A                             0x00400008
#define SETVTGWARPWATERMARKS_DEFAULT_HOPPER_A                          0x00400008


#define SET_3D_CHANNEL_INIT_METHODS_STRING                             "DE34575A"
#define SET_3D_CHANNEL_INIT_METHODS_ID                                 0x00e118a5
#define SET_3D_CHANNEL_INIT_METHODS_OVERINSTALL                        0 // OVERRIDE
#define SET_3D_CHANNEL_INIT_METHODS_DEFAULT                            ""


#define SET_3D_NODE_LOW_PRIORITY_STRING                                "34323"
#define SET_3D_NODE_LOW_PRIORITY_ID                                    0x00a34323
#define SET_3D_NODE_LOW_PRIORITY_OVERINSTALL                           0 // OVERRIDE
#define SET_3D_NODE_LOW_PRIORITY_OFF                                   0x0
#define SET_3D_NODE_LOW_PRIORITY_DISABLED                              0x0
#define SET_3D_NODE_LOW_PRIORITY_ON                                    0x1
#define SET_3D_NODE_LOW_PRIORITY_ENABLED                               0x1
#define SET_3D_NODE_LOW_PRIORITY_DEFAULT                               SET_3D_NODE_LOW_PRIORITY_OFF


#define SET_COMPUTE_CHANNEL_INIT_METHODS_STRING                        "DE456649"
#define SET_COMPUTE_CHANNEL_INIT_METHODS_ID                            0x00e22894
#define SET_COMPUTE_CHANNEL_INIT_METHODS_OVERINSTALL                   0 // OVERRIDE
#define SET_COMPUTE_CHANNEL_INIT_METHODS_DEFAULT                       ""


#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_STRING                  "SetPowerThrottleforPCIeCompliance"
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ID                      0x00ae785c
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_OVERINSTALL             1 // MERGE
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_OFF                     0x00000000
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_0                       0x00000000
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_FALSE                   0x00000000
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_DISABLED                0x00000000
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ON                      0x00000001
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_1                       0x00000001
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_TRUE                    0x00000001
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_ENABLED                 0x00000001
#define SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_DEFAULT                 SET_POWER_THROTTLE_FOR_PCIe_COMPLIANCE_OFF


#define SET_VAB_DATA_STRING                                            "0xab8687"
#define SET_VAB_DATA_ID                                                0x00ab8687
#define SET_VAB_DATA_OVERINSTALL                                       0 // OVERRIDE
#define SET_VAB_DATA_ZERO                                              0x00000000
#define SET_VAB_DATA_UINT_ONE                                          0x00000001
#define SET_VAB_DATA_FLOAT_ONE                                         0x3f800000
#define SET_VAB_DATA_FLOAT_POS_INF                                     0x7f800000
#define SET_VAB_DATA_FLOAT_NAN                                         0x7fc00000
#define SET_VAB_DATA_USE_API_DEFAULTS                                  0xffffffff
#define SET_VAB_DATA_DEFAULT                                           SET_VAB_DATA_USE_API_DEFAULTS


#define SHADERMAXCTAPERSM_STRING                                       "50361292"
#define SHADERMAXCTAPERSM_ID                                           0x00bc6200
#define SHADERMAXCTAPERSM_OVERINSTALL                                  0 // OVERRIDE
#define SHADERMAXCTAPERSM_MIN                                          0
#define SHADERMAXCTAPERSM_MAX                                          255
#define SHADERMAXCTAPERSM_DEFAULT                                      SHADERMAXCTAPERSM_MIN


#define SHADERMAXREGALLOWED_STRING                                     "50361291"
#define SHADERMAXREGALLOWED_ID                                         0x00bc6199
#define SHADERMAXREGALLOWED_OVERINSTALL                                0 // OVERRIDE
#define SHADERMAXREGALLOWED_MIN                                        0
#define SHADERMAXREGALLOWED_MAX                                        1024
#define SHADERMAXREGALLOWED_DEFAULT                                    SHADERMAXREGALLOWED_MIN


#define SHADERMAXREGALLOWED_HASH_STRING                                "50361200"
#define SHADERMAXREGALLOWED_HASH_ID                                    0x00bc6100
#define SHADERMAXREGALLOWED_HASH_OVERINSTALL                           0 // OVERRIDE
#define SHADERMAXREGALLOWED_HASH_DEFAULT                               0


#define SHADERMAXREGALLOWED_TYPES_STRING                               "50361290"
#define SHADERMAXREGALLOWED_TYPES_ID                                   0x00bc6198
#define SHADERMAXREGALLOWED_TYPES_OVERINSTALL                          0 // OVERRIDE
#define SHADERMAXREGALLOWED_TYPES_VERTEX_SHADER                        0x00000001
#define SHADERMAXREGALLOWED_TYPES_HULL_SHADER                          0x00000002
#define SHADERMAXREGALLOWED_TYPES_DOMAIN_SHADER                        0x00000004
#define SHADERMAXREGALLOWED_TYPES_GEOMETRY_SHADER                      0x00000008
#define SHADERMAXREGALLOWED_TYPES_PIXEL_SHADER                         0x00000010
#define SHADERMAXREGALLOWED_TYPES_COMPUTE_SHADER                       0x00000020
#define SHADERMAXREGALLOWED_TYPES_DEFAULT                              0x0000003f


#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_STRING                "0x1adc01"
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_ID                    0x001adc01
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_OVERINSTALL           0 // OVERRIDE
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_OFF                   0
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_DISABLED              0
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_ON                    1
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_ENABLED               1
#define SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_DEFAULT               SHADER_HEAP_WDDM2_DX1X_MULTIBLOCK_ENABLE_ON


#define SHADER_HEAP_WDDM2_MULTIBLOCK_RESERVE_VA_SIZE_STRING            "0x1abc0f"
#define SHADER_HEAP_WDDM2_MULTIBLOCK_RESERVE_VA_SIZE_ID                0x001abc0f
#define SHADER_HEAP_WDDM2_MULTIBLOCK_RESERVE_VA_SIZE_OVERINSTALL       0 // OVERRIDE
#define SHADER_HEAP_WDDM2_MULTIBLOCK_RESERVE_VA_SIZE_DEFAULT_DX11      0x10000000
#define SHADER_HEAP_WDDM2_MULTIBLOCK_RESERVE_VA_SIZE_DEFAULT_DX12      0x20000000


#define SHARPEN_ALLOW_STRING                                           "598949"
#define SHARPEN_ALLOW_ID                                               0x00598949
#define SHARPEN_ALLOW_OVERINSTALL                                      1 // MERGE
#define SHARPEN_ALLOW_DISALLOWED                                       0
#define SHARPEN_ALLOW_0                                                0
#define SHARPEN_ALLOW_OFF                                              0
#define SHARPEN_ALLOW_DISABLED                                         0
#define SHARPEN_ALLOW_OPENGL_ALLOWED                                   0x1
#define SHARPEN_ALLOW_DX9_ALLOWED                                      0x2
#define SHARPEN_ALLOW_DX11_ALLOWED                                     0x4
#define SHARPEN_ALLOW_DX12_ALLOWED                                     0x8
#define SHARPEN_ALLOW_ALLOWED                                          0xF
#define SHARPEN_ALLOW_DEFAULT                                          SHARPEN_ALLOW_OPENGL_ALLOWED


#define SHARPEN_ENABLE_STRING                                          "598928"
#define SHARPEN_ENABLE_ID                                              0x00598928
#define SHARPEN_ENABLE_OVERINSTALL                                     1 // MERGE
#define SHARPEN_ENABLE_OFF                                             0
#define SHARPEN_ENABLE_DISABLED                                        0
#define SHARPEN_ENABLE_ON                                              1
#define SHARPEN_ENABLE_ENABLED                                         1
#define SHARPEN_ENABLE_DEFAULT                                         SHARPEN_ENABLE_OFF


#define SHARPEN_IGNORE_FILM_GRAIN_STRING                               "2ed8ce"
#define SHARPEN_IGNORE_FILM_GRAIN_ID                                   0x002ed8ce
#define SHARPEN_IGNORE_FILM_GRAIN_OVERINSTALL                          1 // MERGE
#define SHARPEN_IGNORE_FILM_GRAIN_MIN                                  0x00
#define SHARPEN_IGNORE_FILM_GRAIN_MAX                                  0xff
#define SHARPEN_IGNORE_FILM_GRAIN_DEFAULT                              17


#define SHARPEN_INDICATOR_ENABLE_STRING                                "598929"
#define SHARPEN_INDICATOR_ENABLE_ID                                    0x00598929
#define SHARPEN_INDICATOR_ENABLE_OVERINSTALL                           1 // MERGE
#define SHARPEN_INDICATOR_ENABLE_OFF                                   0
#define SHARPEN_INDICATOR_ENABLE_DISABLED                              0
#define SHARPEN_INDICATOR_ENABLE_ON                                    1
#define SHARPEN_INDICATOR_ENABLE_ENABLED                               1
#define SHARPEN_INDICATOR_ENABLE_DEFAULT                               SHARPEN_INDICATOR_ENABLE_OFF


#define SHARPEN_VALUE_STRING                                           "2ed8cd"
#define SHARPEN_VALUE_ID                                               0x002ed8cd
#define SHARPEN_VALUE_OVERINSTALL                                      1 // MERGE
#define SHARPEN_VALUE_MIN                                              0x0
#define SHARPEN_VALUE_MAX                                              0xff
#define SHARPEN_VALUE_DEFAULT                                          50


#define SHARPEN_VALUE_NIS2_STRING                                      "abab21"
#define SHARPEN_VALUE_NIS2_ID                                          0x00abab21
#define SHARPEN_VALUE_NIS2_OVERINSTALL                                 1 // MERGE
#define SHARPEN_VALUE_NIS2_MIN                                         0x0
#define SHARPEN_VALUE_NIS2_MAX                                         0x64
#define SHARPEN_VALUE_NIS2_DEFAULT                                     50


#define SHIM_FAILURE_INJECTION_CALLBACKS_STRING                        "dd3b22c7"
#define SHIM_FAILURE_INJECTION_CALLBACKS_ID                            0x00dd8f66
#define SHIM_FAILURE_INJECTION_CALLBACKS_OVERINSTALL                   0 // OVERRIDE
#define SHIM_FAILURE_INJECTION_CALLBACKS_DISABLED                      0x0000000000000000
#define SHIM_FAILURE_INJECTION_CALLBACKS_ALLOCATE                      0x0000000000000001
#define SHIM_FAILURE_INJECTION_CALLBACKS_RENDER                        0x0000000000000002
#define SHIM_FAILURE_INJECTION_CALLBACKS_LOCK                          0x0000000000000004
#define SHIM_FAILURE_INJECTION_CALLBACKS_CREATECONTEXT                 0x0000000000000008
#define SHIM_FAILURE_INJECTION_CALLBACKS_MAKERESIDENT                  0x0000000000000010
#define SHIM_FAILURE_INJECTION_CALLBACKS_DEFAULT                       0xffffffffffffffff


#define SHIM_FAILURE_INJECTION_ENABLE_STRING                           "4ab97e6f"
#define SHIM_FAILURE_INJECTION_ENABLE_ID                               0x00427529
#define SHIM_FAILURE_INJECTION_ENABLE_OVERINSTALL                      0 // OVERRIDE
#define SHIM_FAILURE_INJECTION_ENABLE_OFF                              0
#define SHIM_FAILURE_INJECTION_ENABLE_DISABLED                         0
#define SHIM_FAILURE_INJECTION_ENABLE_ON                               1
#define SHIM_FAILURE_INJECTION_ENABLE_ENABLED                          1
#define SHIM_FAILURE_INJECTION_ENABLE_DEFAULT                          SHIM_FAILURE_INJECTION_ENABLE_OFF


#define SHIM_FAILURE_INJECTION_FAILURE_POINT_STRING                    "bae1b26f"
#define SHIM_FAILURE_INJECTION_FAILURE_POINT_ID                        0x00dcafc1
#define SHIM_FAILURE_INJECTION_FAILURE_POINT_OVERINSTALL               0 // OVERRIDE
#define SHIM_FAILURE_INJECTION_FAILURE_POINT_DEFAULT                   0


#define SHIM_PASSTHRU_ENABLE_STRING                                    "ShimPassthruEnable"
#define SHIM_PASSTHRU_ENABLE_ID                                        0x004b4639
#define SHIM_PASSTHRU_ENABLE_OVERINSTALL                               0 // OVERRIDE
#define SHIM_PASSTHRU_ENABLE_OFF                                       0
#define SHIM_PASSTHRU_ENABLE_DISABLED                                  0
#define SHIM_PASSTHRU_ENABLE_ON                                        1
#define SHIM_PASSTHRU_ENABLE_ENABLED                                   1
#define SHIM_PASSTHRU_ENABLE_DEFAULT                                   SHIM_PASSTHRU_ENABLE_OFF


#define SILK_BUFFER_POLICY_STRING                                      "B5270433"
#define SILK_BUFFER_POLICY_ID                                          0x00b75345
#define SILK_BUFFER_POLICY_OVERINSTALL                                 0 // OVERRIDE
#define SILK_BUFFER_POLICY_DIVISOR_MASK                                0x0000000f
#define SILK_BUFFER_POLICY_ADJUST_A_MS2_MASK                           0x000000f0
#define SILK_BUFFER_POLICY_ADJUST_A_MS2_SHIFT                          4
#define SILK_BUFFER_POLICY_AVG_FRAMES_MASK                             0x0000ff00
#define SILK_BUFFER_POLICY_AVG_FRAMES_SHIFT                            8
#define SILK_BUFFER_POLICY_MAX_ADJUST_MS_MASK                          0x000f0000
#define SILK_BUFFER_POLICY_MAX_ADJUST_MS_SHIFT                         16
#define SILK_BUFFER_POLICY_MAX_DELAY_10MS_MASK                         0x00f00000
#define SILK_BUFFER_POLICY_MAX_DELAY_10MS_SHIFT                        20
#define SILK_BUFFER_POLICY_LATENCY_MS_MASK                             0xff000000
#define SILK_BUFFER_POLICY_LATENCY_MS_SHIFT                            24
#define SILK_BUFFER_POLICY_DEFAULT4                                    0x19a40824


#define SILK_LOG_STRING                                                "B5270431"
#define SILK_LOG_ID                                                    0x00b75343
#define SILK_LOG_OVERINSTALL                                           0 // OVERRIDE
#define SILK_LOG_DISABLED                                              0x00000000
#define SILK_LOG_OFF                                                   0x00000000
#define SILK_LOG_0                                                     0x00000000
#define SILK_LOG_ENABLED                                               0x00000001
#define SILK_LOG_ON                                                    0x00000001
#define SILK_LOG_1                                                     0x00000001
#define SILK_LOG_VSYNC_ON_ALT                                          0x00000002
#define SILK_LOG_DEFAULT                                               SILK_LOG_DISABLED


#define SILK_SMOOTHNESS_STRING                                         "864173547"
#define SILK_SMOOTHNESS_ID                                             0x00987251
#define SILK_SMOOTHNESS_OVERINSTALL                                    1 // MERGE
#define SILK_SMOOTHNESS_LOW                                            0x00000000
#define SILK_SMOOTHNESS_MEDIUM                                         0x00000001
#define SILK_SMOOTHNESS_HIGH                                           0x00000002
#define SILK_SMOOTHNESS_ULTRA                                          0x00000003
#define SILK_SMOOTHNESS_OFF                                            0x00000004
#define SILK_SMOOTHNESS_DEFAULT                                        SILK_SMOOTHNESS_LOW


#define SILK_SMOOTHNESS_ALLOW_STRING                                   "666634"
#define SILK_SMOOTHNESS_ALLOW_ID                                       0x00666634
#define SILK_SMOOTHNESS_ALLOW_OVERINSTALL                              0 // OVERRIDE
#define SILK_SMOOTHNESS_ALLOW_DISABLED                                 0
#define SILK_SMOOTHNESS_ALLOW_OFF                                      0
#define SILK_SMOOTHNESS_ALLOW_ENABLED                                  1
#define SILK_SMOOTHNESS_ALLOW_ON                                       1
#define SILK_SMOOTHNESS_ALLOW_DEFAULT                                  SILK_SMOOTHNESS_ALLOW_DISABLED


#define SLI2_MODE10_STRING                                             "64286458"
#define SLI2_MODE10_ID                                                 0x00a06948
#define SLI2_MODE10_OVERINSTALL                                        0 // OVERRIDE
#define SLI2_MODE10_USE_MCCOMPAT                                       0x00000000
#define SLI2_MODE10_FORCE_2AFR                                         0x00000001
#define SLI2_MODE10_DISABLE_SLI                                        0x00000004
#define SLI2_MODE10_FORCE_4AFR                                         0x00000005
#define SLI2_MODE10_FORCE_3AFR                                         0x00000006
#define SLI2_MODE10_SLI_MODE_MASK                                      0x00000007
#define SLI2_MODE10_OVERRIDE_BIT                                       0x80000000
#define SLI2_MODE10_DEFAULT                                            SLI2_MODE10_USE_MCCOMPAT


#define SLI2_MODE12_STRING                                             "64a04747"
#define SLI2_MODE12_ID                                                 0x00a04747
#define SLI2_MODE12_OVERINSTALL                                        0 // OVERRIDE
#define SLI2_MODE12_USE_MCCOMPAT                                       0x00000000
#define SLI2_MODE12_FORCE_2AFR                                         0x00000001
#define SLI2_MODE12_DISABLE_SLI                                        0x00000004
#define SLI2_MODE12_FORCE_4AFR                                         0x00000005
#define SLI2_MODE12_FORCE_3AFR                                         0x00000006
#define SLI2_MODE12_SLI_MODE_MASK                                      0x00000007
#define SLI2_MODE12_OVERRIDE_BIT                                       0x80000000
#define SLI2_MODE12_DEFAULT                                            SLI2_MODE12_USE_MCCOMPAT


#define SLILOG_STRING                                                  "40599523"
#define SLILOG_ID                                                      0x00258eb9
#define SLILOG_OVERINSTALL                                             0 // OVERRIDE
#define SLILOG_MIN                                                     0
#define SLILOG_MAX                                                     1024
#define SLILOG_DEFAULT                                                 0


#define SLILOG_APP_FILTER_STRING                                       "A6441456"
#define SLILOG_APP_FILTER_ID                                           0x00a76564
#define SLILOG_APP_FILTER_OVERINSTALL                                  0 // OVERRIDE
#define SLILOG_APP_FILTER_DEFAULT                                      0x00000000


#define SLILOG_CONSOLE_TO_FILE_STRING                                  "c822ab"
#define SLILOG_CONSOLE_TO_FILE_ID                                      0x00c622ab
#define SLILOG_CONSOLE_TO_FILE_OVERINSTALL                             0 // OVERRIDE
#define SLILOG_CONSOLE_TO_FILE_OFF                                     1
#define SLILOG_CONSOLE_TO_FILE_DISABLED                                1
#define SLILOG_CONSOLE_TO_FILE_ON                                      0
#define SLILOG_CONSOLE_TO_FILE_ENABLED                                 0
#define SLILOG_CONSOLE_TO_FILE_DEFAULT                                 SLILOG_CONSOLE_TO_FILE_OFF


#define SLILOG_FILE_STRING                                             "56443456"
#define SLILOG_FILE_ID                                                 0x00076564
#define SLILOG_FILE_OVERINSTALL                                        0 // OVERRIDE
#define SLILOG_FILE_DEFAULT                                            0x00000000


#define SLILOG_FLAGS_STRING                                            "40599522"
#define SLILOG_FLAGS_ID                                                0x00258ec0
#define SLILOG_FLAGS_OVERINSTALL                                       0 // OVERRIDE
#define SLILOG_FLAGS_DISABLE                                           0x0
#define SLILOG_FLAGS_ENABLE_3D_TS                                      0x1
#define SLILOG_FLAGS_ENABLE_CE_TS                                      0x2
#define SLILOG_FLAGS_ENABLE_BEGIN_END_TS                               0x4
#define SLILOG_FLAGS_ENABLE_WAIT_TS                                    0x8
#define SLILOG_FLAGS_DEFAULT                                           0x0


#define SLILOG_SINGLE_GPU_STRING                                       "40599521"
#define SLILOG_SINGLE_GPU_ID                                           0x00258eb8
#define SLILOG_SINGLE_GPU_OVERINSTALL                                  0 // OVERRIDE
#define SLILOG_SINGLE_GPU_OFF0                                         0
#define SLILOG_SINGLE_GPU_OFF1                                         1
#define SLILOG_SINGLE_GPU_2WAY                                         2
#define SLILOG_SINGLE_GPU_3WAY                                         3
#define SLILOG_SINGLE_GPU_4WAY                                         4
#define SLILOG_SINGLE_GPU_DEFAULT                                      0


#define SLIMOSAIC_CONTROL_STRING                                       "71308559"
#define SLIMOSAIC_CONTROL_ID                                           0x00f713bc
#define SLIMOSAIC_CONTROL_OVERINSTALL                                  0 // OVERRIDE
#define SLIMOSAIC_CONTROL_ALLOW_ALL                                    0x00000000
#define SLIMOSAIC_CONTROL_DISABLE_TWOD                                 0x00000001
#define SLIMOSAIC_CONTROL_FORCE_BAR1_WAR                               0x80000000
#define SLIMOSAIC_CONTROL_DISABLE_CAN_VECTORIZE_TRACKER                0x00000002
#define SLIMOSAIC_CONTROL_DISABLE_CE_TRANSFER_2WAY                     0x00000004
#define SLIMOSAIC_CONTROL_DISABLE_CE_TRANSFER_3WAY                     0x00000010
#define SLIMOSAIC_CONTROL_DISABLE_CE_TRANSFER_4WAY                     0x00000020
#define SLIMOSAIC_CONTROL_UNICAST_CE_TRANSFER_2WAY                     0x00000040
#define SLIMOSAIC_CONTROL_UNICAST_CE_TRANSFER_3WAY                     0x00000100
#define SLIMOSAIC_CONTROL_UNICAST_CE_TRANSFER_4WAY                     0x00000200
#define SLIMOSAIC_CONTROL_SYNC_PRESENT_CHANNELS                        0x00000800
#define SLIMOSAIC_CONTROL_DISABLE_VIDEO_BRIDGE                         0x00001000
#define SLIMOSAIC_CONTROL_DISABLE_FLIPEX_BC_TRANSITION                 0x00002000
#define SLIMOSAIC_CONTROL_DEFAULT                                      SLIMOSAIC_CONTROL_ALLOW_ALL


#define SLI_BRIDGELESS_OPTIMIZATION_STRING                             "49501226"
#define SLI_BRIDGELESS_OPTIMIZATION_ID                                 0x00a67bad
#define SLI_BRIDGELESS_OPTIMIZATION_OVERINSTALL                        0 // OVERRIDE
#define SLI_BRIDGELESS_OPTIMIZATION_AUTO_SELECT                        0x1
#define SLI_BRIDGELESS_OPTIMIZATION_FORCE_ON                           0x2
#define SLI_BRIDGELESS_OPTIMIZATION_FORCE_OFF                          0x4
#define SLI_BRIDGELESS_OPTIMIZATION_SHOW_INDICATOR                     0x8
#define SLI_BRIDGELESS_OPTIMIZATION_DISABLE_CHANNEL_PRESENT_COPY       0x10
#define SLI_BRIDGELESS_OPTIMIZATION_DISABLE_FLEXI_PRESENT_CHANNEL      0x20
#define SLI_BRIDGELESS_OPTIMIZATION_COPY_ON_3D_FOR_EXPLICIT_DX12       0x40
#define SLI_BRIDGELESS_OPTIMIZATION_USE_MOSAIC_SCANOUT_OFFSET          0x80
#define SLI_BRIDGELESS_OPTIMIZATION_DEFAULT                            SLI_BRIDGELESS_OPTIMIZATION_AUTO_SELECT


#define SLI_ENABLE_EARLY_PUSH_STRING                                   "44502329"
#define SLI_ENABLE_EARLY_PUSH_ID                                       0x00a37aad
#define SLI_ENABLE_EARLY_PUSH_OVERINSTALL                              0 // OVERRIDE
#define SLI_ENABLE_EARLY_PUSH_OFF                                      0x00000000
#define SLI_ENABLE_EARLY_PUSH_DISABLED                                 0x00000000
#define SLI_ENABLE_EARLY_PUSH_ON                                       0x00000001
#define SLI_ENABLE_EARLY_PUSH_ENABLED                                  0x00000001
#define SLI_ENABLE_EARLY_PUSH_DEFAULT                                  SLI_ENABLE_EARLY_PUSH_ON


#define SLI_TIMESTAMP_FRAME_STRING                                     "72164393"
#define SLI_TIMESTAMP_FRAME_ID                                         0x00fa3264
#define SLI_TIMESTAMP_FRAME_OVERINSTALL                                0 // OVERRIDE
#define SLI_TIMESTAMP_FRAME_DEFAULT                                    0


#define SPM_SHADER_EXCEPTIONS_STRING                                   "a025fc81"
#define SPM_SHADER_EXCEPTIONS_ID                                       0x0017fd60
#define SPM_SHADER_EXCEPTIONS_OVERINSTALL                              0 // OVERRIDE
#define SPM_SHADER_EXCEPTIONS_ENABLE                                   0x00000001
#define SPM_SHADER_EXCEPTIONS_ENABLE_API_ILLEGAL_EXCEPTIONS            0x00000002
#define SPM_SHADER_EXCEPTIONS_ENABLE_API_LEGAL_EXCEPTIONS              0x00000004
#define SPM_SHADER_EXCEPTIONS_DISABLE_TEX_FORMAT_EXCEPTIONS            0x00000008
#define SPM_SHADER_EXCEPTIONS_DISABLE_TEX_LAYOUT_EXCEPTIONS            0x00000010


#define SPOOFARCH_STRING                                               "64907721"
#define SPOOFARCH_ID                                                   0x00dc00d1
#define SPOOFARCH_OVERINSTALL                                          0 // OVERRIDE
#define SPOOFARCH_GM108                                                0x0110
#define SPOOFARCH_GM204                                                0x0120
#define SPOOFARCH_GP100                                                0x0130
#define SPOOFARCH_GV100                                                0x0140
#define SPOOFARCH_GV11B                                                0x0150
#define SPOOFARCH_TU102                                                0x0160
#define SPOOFARCH_GA100                                                0x0170
#define SPOOFARCH_GA102                                                0x0180
#define SPOOFARCH_GA10B                                                0x0190
#define SPOOFARCH_AD102                                                0x0200
#define SPOOFARCH_GH100                                                0x0210


#define SQUASHWENABLE_STRING                                           "30297832"
#define SQUASHWENABLE_ID                                               0x00387e72
#define SQUASHWENABLE_OVERINSTALL                                      0 // OVERRIDE
#define SQUASHWENABLE_OFF                                              0x61657714
#define SQUASHWENABLE_DISABLED                                         0x61657714
#define SQUASHWENABLE_ON                                               0x40011596
#define SQUASHWENABLE_ENABLED                                          0x40011596
#define SQUASHWENABLE_DEFAULT                                          SQUASHWENABLE_OFF


#define STAGING_CACHE_SIZE_STRING                                      "51524924"
#define STAGING_CACHE_SIZE_ID                                          0x0013fec2
#define STAGING_CACHE_SIZE_OVERINSTALL                                 0 // OVERRIDE
#define STAGING_CACHE_SIZE_MIN                                         0
#define STAGING_CACHE_SIZE_MAX                                         16777217
#define STAGING_CACHE_SIZE_DEFAULT                                     131072


#define STENCIL_CRITERION_STRING                                       "00065643"
#define STENCIL_CRITERION_ID                                           0x005fb393
#define STENCIL_CRITERION_OVERINSTALL                                  0 // OVERRIDE


#define SUBCH3D_INLINE_UPLOADS_STRING                                  "5296759c"
#define SUBCH3D_INLINE_UPLOADS_ID                                      0x00d413b1
#define SUBCH3D_INLINE_UPLOADS_OVERINSTALL                             0 // OVERRIDE
#define SUBCH3D_INLINE_UPLOADS_OFF                                     0x0
#define SUBCH3D_INLINE_UPLOADS_DISABLED                                0x0
#define SUBCH3D_INLINE_UPLOADS_ON                                      0x1
#define SUBCH3D_INLINE_UPLOADS_ENABLED                                 0x1
#define SUBCH3D_INLINE_UPLOADS_DEFAULT                                 SUBCH3D_INLINE_UPLOADS_OFF


#define SUPPRESS_ASSERTS_IN_AUTOMATION_STRING                          "35354321"
#define SUPPRESS_ASSERTS_IN_AUTOMATION_ID                              0x0032dcd5
#define SUPPRESS_ASSERTS_IN_AUTOMATION_OVERINSTALL                     0 // OVERRIDE
#define SUPPRESS_ASSERTS_IN_AUTOMATION_SUPPRESS_ASSERT_RS1             0x00000001
#define SUPPRESS_ASSERTS_IN_AUTOMATION_SUPPRESS_ASSERT_RS2             0x00000002
#define SUPPRESS_ASSERTS_IN_AUTOMATION_SUPPRESS_ASSERT_ALL             0x00000004
#define SUPPRESS_ASSERTS_IN_AUTOMATION_DEFAULT                         0


#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_STRING                   "200383472"
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_ID                       0x0032ecb5
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_OVERINSTALL              0 // OVERRIDE
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_OFF                      0x0
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_DISABLED                 0x0
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_ON                       0x1
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_ENABLED                  0x1
#define SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_DEFAULT                  SUPPRESS_MSEDGE_ASSERTS_IN_AUTOMATION_ON


#define SURFACEDUMPMAXRANGE_STRING                                     "841SDMX1"
#define SURFACEDUMPMAXRANGE_ID                                         0x005bd840
#define SURFACEDUMPMAXRANGE_OVERINSTALL                                0 // OVERRIDE
#define SURFACEDUMPMAXRANGE_DEFAULT                                    0


#define SURFACEDUMPMINRANGE_STRING                                     "841SDMM1"
#define SURFACEDUMPMINRANGE_ID                                         0x00691dcd
#define SURFACEDUMPMINRANGE_OVERINSTALL                                0 // OVERRIDE
#define SURFACEDUMPMINRANGE_DEFAULT                                    0


#define SURFACEDUMPMODULO_STRING                                       "841SD591"
#define SURFACEDUMPMODULO_ID                                           0x0006b91b
#define SURFACEDUMPMODULO_OVERINSTALL                                  0 // OVERRIDE
#define SURFACEDUMPMODULO_DEFAULT                                      0


#define SURFACEFORMATSDX7_STRING                                       "52971801"
#define SURFACEFORMATSDX7_ID                                           0x00540059
#define SURFACEFORMATSDX7_OVERINSTALL                                  0 // OVERRIDE
#define SURFACEFORMATSDX7_BASIC                                        0x10000000
#define SURFACEFORMATSDX7_BUMPMAP                                      0x20000000
#define SURFACEFORMATSDX7_FLOAT                                        0x01000000
#define SURFACEFORMATSDX7_DXT                                          0x04000000
#define SURFACEFORMATSDX7_PALETTIZED                                   0x08000000
#define SURFACEFORMATSDX7_HILO                                         0x00200000
#define SURFACEFORMATSDX7_RGBG                                         0x00400000
#define SURFACEFORMATSDX7_HEMI                                         0x00800000
#define SURFACEFORMATSDX7_YUV                                          0x00010000
#define SURFACEFORMATSDX7_ZETA                                         0x00040000
#define SURFACEFORMATSDX7_CONTROL                                      0x00080000
#define SURFACEFORMATSDX7_MISC                                         0x00001000
#define SURFACEFORMATSDX7_NVYX                                         0x00000800
#define SURFACEFORMATSDX7_ATI                                          0x00000400
#define SURFACEFORMATSDX7_RAWZ                                         0x00000200
#define SURFACEFORMATSDX7_INTZ                                         0x00000100


#define SURFACEFORMATSDX8_STRING                                       "54082152"
#define SURFACEFORMATSDX8_ID                                           0x00f2f699
#define SURFACEFORMATSDX8_OVERINSTALL                                  0 // OVERRIDE
#define SURFACEFORMATSDX8_BASIC                                        0x10000000
#define SURFACEFORMATSDX8_BUMPMAP                                      0x20000000
#define SURFACEFORMATSDX8_FLOAT                                        0x01000000
#define SURFACEFORMATSDX8_DXT                                          0x04000000
#define SURFACEFORMATSDX8_PALETTIZED                                   0x08000000
#define SURFACEFORMATSDX8_HILO                                         0x00200000
#define SURFACEFORMATSDX8_RGBG                                         0x00400000
#define SURFACEFORMATSDX8_HEMI                                         0x00800000
#define SURFACEFORMATSDX8_YUV                                          0x00010000
#define SURFACEFORMATSDX8_ZETA                                         0x00040000
#define SURFACEFORMATSDX8_CONTROL                                      0x00080000
#define SURFACEFORMATSDX8_MISC                                         0x00001000
#define SURFACEFORMATSDX8_NVYX                                         0x00000800
#define SURFACEFORMATSDX8_ATI                                          0x00000400
#define SURFACEFORMATSDX8_RAWZ                                         0x00000200
#define SURFACEFORMATSDX8_INTZ                                         0x00000100


#define SURROUND_METERED_FRAMES_STRING                                 "71F71f67"
#define SURROUND_METERED_FRAMES_ID                                     0x00f71f67
#define SURROUND_METERED_FRAMES_OVERINSTALL                            0 // OVERRIDE
#define SURROUND_METERED_FRAMES_DEFAULT                                0


#define SYSMEMCACHEDCOPYBEHAVIOR_STRING                                "52267594"
#define SYSMEMCACHEDCOPYBEHAVIOR_ID                                    0x00db3853
#define SYSMEMCACHEDCOPYBEHAVIOR_OVERINSTALL                           0 // OVERRIDE
#define SYSMEMCACHEDCOPYBEHAVIOR_DISALLOW                              0x00000000
#define SYSMEMCACHEDCOPYBEHAVIOR_ALLOW_FOR_TEXTURES_WITHOUT_SUBRESOURCES 0x00000001
#define SYSMEMCACHEDCOPYBEHAVIOR_ALLOW_FOR_TEXTURES_WITH_SUBRESOURCES  0x00000002
#define SYSMEMCACHEDCOPYBEHAVIOR_DEFAULT                               SYSMEMCACHEDCOPYBEHAVIOR_ALLOW_FOR_TEXTURES_WITHOUT_SUBRESOURCES


#define SYSMEMPROMOTION_STRING                                         "beefcba5"
#define SYSMEMPROMOTION_ID                                             0x00783e4a
#define SYSMEMPROMOTION_OVERINSTALL                                    0 // OVERRIDE
#define SYSMEMPROMOTION_NO_PROMOTE                                     0x00000000
#define SYSMEMPROMOTION_ALL_PROMOTE_MASK                               0x00000003
#define SYSMEMPROMOTION_ALL_PROMOTE_64B                                0x00000001
#define SYSMEMPROMOTION_ALL_PROMOTE_128B                               0x00000002
#define SYSMEMPROMOTION_HUB_PROMOTE_MASK                               0x0000000C
#define SYSMEMPROMOTION_HUB_PROMOTE_64B                                0x00000004
#define SYSMEMPROMOTION_HUB_PROMOTE_128B                               0x00000008
#define SYSMEMPROMOTION_CE_PROMOTE_MASK                                0x00000030
#define SYSMEMPROMOTION_CE_PROMOTE_64B                                 0x00000010
#define SYSMEMPROMOTION_CE_PROMOTE_128B                                0x00000020
#define SYSMEMPROMOTION_FE_PROMOTE_MASK                                0x000000C0
#define SYSMEMPROMOTION_FE_PROMOTE_64B                                 0x00000040
#define SYSMEMPROMOTION_FE_PROMOTE_128B                                0x00000080
#define SYSMEMPROMOTION_PD_PROMOTE_MASK                                0x00000300
#define SYSMEMPROMOTION_PD_PROMOTE_64B                                 0x00000100
#define SYSMEMPROMOTION_PD_PROMOTE_128B                                0x00000200
#define SYSMEMPROMOTION_CTX_PROMOTE_MASK                               0x00000C00
#define SYSMEMPROMOTION_CTX_PROMOTE_64B                                0x00000400
#define SYSMEMPROMOTION_CTX_PROMOTE_128B                               0x00000800
#define SYSMEMPROMOTION_SCC_PROMOTE_MASK                               0x00003000
#define SYSMEMPROMOTION_SCC_PROMOTE_64B                                0x00001000
#define SYSMEMPROMOTION_SCC_PROMOTE_128B                               0x00002000
#define SYSMEMPROMOTION_L1_PROMOTE_MASK                                0x00030000
#define SYSMEMPROMOTION_L1_PROMOTE_64B                                 0x00010000
#define SYSMEMPROMOTION_L1_PROMOTE_128B                                0x00020000
#define SYSMEMPROMOTION_T1_PROMOTE_MASK                                0x000C0000
#define SYSMEMPROMOTION_T1_PROMOTE_64B                                 0x00040000
#define SYSMEMPROMOTION_T1_PROMOTE_128B                                0x00080000
#define SYSMEMPROMOTION_PE_PROMOTE_MASK                                0x00300000
#define SYSMEMPROMOTION_PE_PROMOTE_64B                                 0x00100000
#define SYSMEMPROMOTION_PE_PROMOTE_128B                                0x00200000
#define SYSMEMPROMOTION_RAST_PROMOTE_MASK                              0x00C00000
#define SYSMEMPROMOTION_RAST_PROMOTE_64B                               0x00400000
#define SYSMEMPROMOTION_RAST_PROMOTE_128B                              0x00800000
#define SYSMEMPROMOTION_ROP_PROMOTE_MASK                               0x03000000
#define SYSMEMPROMOTION_ROP_PROMOTE_64B                                0x01000000
#define SYSMEMPROMOTION_ROP_PROMOTE_128B                               0x02000000
#define SYSMEMPROMOTION_GCC_PROMOTE_MASK                               0x0C000000
#define SYSMEMPROMOTION_GCC_PROMOTE_64B                                0x04000000
#define SYSMEMPROMOTION_GCC_PROMOTE_128B                               0x08000000
#define SYSMEMPROMOTION_GPCCS_PROMOTE_MASK                             0x30000000
#define SYSMEMPROMOTION_GPCCS_PROMOTE_64B                              0x10000000
#define SYSMEMPROMOTION_GPCCS_PROMOTE_128B                             0x20000000
#define SYSMEMPROMOTION_PROMOTE_MASK_ALL                               0x3fff3fff


#define TDR_EARLY_OUT_ENABLE_STRING                                    "31337157"
#define TDR_EARLY_OUT_ENABLE_ID                                        0x00855f9a
#define TDR_EARLY_OUT_ENABLE_OVERINSTALL                               0 // OVERRIDE
#define TDR_EARLY_OUT_ENABLE_OFF                                       0x0
#define TDR_EARLY_OUT_ENABLE_DISABLED                                  0x0
#define TDR_EARLY_OUT_ENABLE_ON                                        0x1
#define TDR_EARLY_OUT_ENABLE_ENABLED                                   0x1
#define TDR_EARLY_OUT_ENABLE_DEFAULT                                   TDR_EARLY_OUT_ENABLE_OFF


#define TDR_EARLY_OUT_PERCENTAGE_STRING                                "54387566"
#define TDR_EARLY_OUT_PERCENTAGE_ID                                    0x00029a7c
#define TDR_EARLY_OUT_PERCENTAGE_OVERINSTALL                           0 // OVERRIDE
#define TDR_EARLY_OUT_PERCENTAGE_MIN                                   0x00000000
#define TDR_EARLY_OUT_PERCENTAGE_MAX                                   0x00000064
#define TDR_EARLY_OUT_PERCENTAGE_DEFAULT                               TDR_EARLY_OUT_PERCENTAGE_MAX


#define TESLASHADERPERFCOUNTERCONTROL0_STRING                          "52348248"
#define TESLASHADERPERFCOUNTERCONTROL0_ID                              0x003c7b85
#define TESLASHADERPERFCOUNTERCONTROL0_OVERINSTALL                     0 // OVERRIDE
#define TESLASHADERPERFCOUNTERCONTROL0_MIN                             0x00000000
#define TESLASHADERPERFCOUNTERCONTROL0_MAX                             0xffffffff


#define TESLASHADERPERFCOUNTERCONTROL1_STRING                          "52358245"
#define TESLASHADERPERFCOUNTERCONTROL1_ID                              0x00f25f64
#define TESLASHADERPERFCOUNTERCONTROL1_OVERINSTALL                     0 // OVERRIDE
#define TESLASHADERPERFCOUNTERCONTROL1_MIN                             0x00000000
#define TESLASHADERPERFCOUNTERCONTROL1_MAX                             0xffffffff


#define TESLASHADERPERFCOUNTERCONTROL2_STRING                          "53346243"
#define TESLASHADERPERFCOUNTERCONTROL2_ID                              0x004a539c
#define TESLASHADERPERFCOUNTERCONTROL2_OVERINSTALL                     0 // OVERRIDE
#define TESLASHADERPERFCOUNTERCONTROL2_MIN                             0x00000000
#define TESLASHADERPERFCOUNTERCONTROL2_MAX                             0xffffffff


#define TESLASHADERPERFCOUNTERCONTROL3_STRING                          "57347247"
#define TESLASHADERPERFCOUNTERCONTROL3_ID                              0x003539bf
#define TESLASHADERPERFCOUNTERCONTROL3_OVERINSTALL                     0 // OVERRIDE
#define TESLASHADERPERFCOUNTERCONTROL3_MIN                             0x00000000
#define TESLASHADERPERFCOUNTERCONTROL3_MAX                             0xffffffff


#define TESLASHADERPERFCOUNTERVALUE0_STRING                            "52368246"
#define TESLASHADERPERFCOUNTERVALUE0_ID                                0x000fac25
#define TESLASHADERPERFCOUNTERVALUE0_OVERINSTALL                       0 // OVERRIDE
#define TESLASHADERPERFCOUNTERVALUE0_MIN                               0x00000000
#define TESLASHADERPERFCOUNTERVALUE0_MAX                               0xffffffff


#define TESLASHADERPERFCOUNTERVALUE1_STRING                            "52648648"
#define TESLASHADERPERFCOUNTERVALUE1_ID                                0x005445d6
#define TESLASHADERPERFCOUNTERVALUE1_OVERINSTALL                       0 // OVERRIDE
#define TESLASHADERPERFCOUNTERVALUE1_MIN                               0x00000000
#define TESLASHADERPERFCOUNTERVALUE1_MAX                               0xffffffff


#define TESLASHADERPERFCOUNTERVALUE2_STRING                            "58342249"
#define TESLASHADERPERFCOUNTERVALUE2_ID                                0x00bda454
#define TESLASHADERPERFCOUNTERVALUE2_OVERINSTALL                       0 // OVERRIDE
#define TESLASHADERPERFCOUNTERVALUE2_MIN                               0x00000000
#define TESLASHADERPERFCOUNTERVALUE2_MAX                               0xffffffff


#define TESLASHADERPERFCOUNTERVALUE3_STRING                            "52948298"
#define TESLASHADERPERFCOUNTERVALUE3_ID                                0x00e274bc
#define TESLASHADERPERFCOUNTERVALUE3_OVERINSTALL                       0 // OVERRIDE
#define TESLASHADERPERFCOUNTERVALUE3_MIN                               0x00000000
#define TESLASHADERPERFCOUNTERVALUE3_MAX                               0xffffffff


#define TEST_NVFBC_LOGO_RENDER_STRING                                  "3112447"
#define TEST_NVFBC_LOGO_RENDER_ID                                      0x008712cd
#define TEST_NVFBC_LOGO_RENDER_OVERINSTALL                             0 // OVERRIDE
#define TEST_NVFBC_LOGO_RENDER_DISABLE                                 0x0
#define TEST_NVFBC_LOGO_RENDER_TEST_NVFBC_LOGO_RENDER                  0x1
#define TEST_NVFBC_LOGO_RENDER_DEFAULT                                 TEST_NVFBC_LOGO_RENDER_DISABLE


#define TEXCOMPRESSENABLE_STRING                                       "57026692"
#define TEXCOMPRESSENABLE_ID                                           0x001f9b6e
#define TEXCOMPRESSENABLE_OVERINSTALL                                  0 // OVERRIDE
#define TEXCOMPRESSENABLE_OFF                                          0x86752318
#define TEXCOMPRESSENABLE_DISABLED                                     0x86752318
#define TEXCOMPRESSENABLE_ON                                           0x88204955
#define TEXCOMPRESSENABLE_ENABLED                                      0x88204955
#define TEXCOMPRESSENABLE_DEFAULT                                      TEXCOMPRESSENABLE_ON


#define TEXELALIGNMENT_STRING                                          "56255736"
#define TEXELALIGNMENT_ID                                              0x0025287b
#define TEXELALIGNMENT_OVERINSTALL                                     0 // OVERRIDE
#define TEXELALIGNMENT_ZOH_CENTER                                      0x02000000
#define TEXELALIGNMENT_ZOH_CORNER                                      0x01000000
#define TEXELALIGNMENT_FOH_CENTER                                      0x00200000
#define TEXELALIGNMENT_FOH_CORNER                                      0x00100000
#define TEXELALIGNMENT_TEXEL_CENTER                                    0x00020000
#define TEXELALIGNMENT_TEXEL_CORNER                                    0x00010000
#define TEXELALIGNMENT_DEFAULT                                         0x01120000


#define TEXHEADERSIMMORTAL_STRING                                      "97513764"
#define TEXHEADERSIMMORTAL_ID                                          0x00ece12c
#define TEXHEADERSIMMORTAL_OVERINSTALL                                 0 // OVERRIDE
#define TEXHEADERSIMMORTAL_OFF                                         0x49845612
#define TEXHEADERSIMMORTAL_DISABLED                                    0x49845612
#define TEXHEADERSIMMORTAL_ON                                          0x72389234
#define TEXHEADERSIMMORTAL_ENABLED                                     0x72389234
#define TEXHEADERSIMMORTAL_DEFAULT                                     TEXHEADERSIMMORTAL_OFF


#define TEXPOOLSIZE_STRING                                             "59954098"
#define TEXPOOLSIZE_ID                                                 0x00ae8e52
#define TEXPOOLSIZE_OVERINSTALL                                        0 // OVERRIDE
#define TEXPOOLSIZE_MIN                                                0x1
#define TEXPOOLSIZE_MAX                                                0x1000
#define TEXPOOLSIZE_DEFAULT                                            INITIAL_NUM_TEXTURE_HEADER_POOL_ENTRIES


#define TEXTURESTAGECAP_STRING                                         "59954022"
#define TEXTURESTAGECAP_ID                                             0x00143ae9
#define TEXTURESTAGECAP_OVERINSTALL                                    0 // OVERRIDE
#define TEXTURESTAGECAP_MIN                                            0x1
#define TEXTURESTAGECAP_MAX                                            0x100
#define TEXTURESTAGECAP_DEFAULT                                        0x100


#define THREEDSMAX_SHIM_FLAGS_STRING                                   "ab2c74f1"
#define THREEDSMAX_SHIM_FLAGS_ID                                       0x002c74f1
#define THREEDSMAX_SHIM_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define THREEDSMAX_SHIM_FLAGS_DISABLE                                  0x00000000
#define THREEDSMAX_SHIM_FLAGS_ENABLE                                   0x00000001
#define THREEDSMAX_SHIM_FLAGS_ENABLEGEFORCE                            0x00000002
#define THREEDSMAX_SHIM_FLAGS_DEFAULT                                  THREEDSMAX_SHIM_FLAGS_DISABLE


#define TILE_POOL_LARGE_PAGE_SUPPORT_STRING                            "0x152af5"
#define TILE_POOL_LARGE_PAGE_SUPPORT_ID                                0x00152af5
#define TILE_POOL_LARGE_PAGE_SUPPORT_OVERINSTALL                       0 // OVERRIDE
#define TILE_POOL_LARGE_PAGE_SUPPORT_OFF                               0x0
#define TILE_POOL_LARGE_PAGE_SUPPORT_0                                 0x0
#define TILE_POOL_LARGE_PAGE_SUPPORT_FALSE                             0x0
#define TILE_POOL_LARGE_PAGE_SUPPORT_DISABLED                          0x0
#define TILE_POOL_LARGE_PAGE_SUPPORT_ON                                0x1
#define TILE_POOL_LARGE_PAGE_SUPPORT_1                                 0x1
#define TILE_POOL_LARGE_PAGE_SUPPORT_TRUE                              0x1
#define TILE_POOL_LARGE_PAGE_SUPPORT_ENABLED                           0x1
#define TILE_POOL_LARGE_PAGE_SUPPORT_DISABLED_FOR_WIN10_OS_BUG_200549489 0x2
#define TILE_POOL_LARGE_PAGE_SUPPORT_DEFAULT                           TILE_POOL_LARGE_PAGE_SUPPORT_DISABLED_FOR_WIN10_OS_BUG_200549489


#define TIRWITHDEPTH_STRING                                            "044540"
#define TIRWITHDEPTH_ID                                                0x00044540
#define TIRWITHDEPTH_OVERINSTALL                                       0 // OVERRIDE
#define TIRWITHDEPTH_USE_REDUCE_COVERAGE_DISABLE                       0x00000001
#define TIRWITHDEPTH_DEFAULT                                           0


#define TRACKED_SEMAPHORE_FLAGS_STRING                                 "0xfaf031"
#define TRACKED_SEMAPHORE_FLAGS_ID                                     0x00faf031
#define TRACKED_SEMAPHORE_FLAGS_OVERINSTALL                            0 // OVERRIDE
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_SCG_GPU_STATE_HAZARD_ANNOTATION 0x00000001
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_ENTRY_POINT_ANNOTATION          0x00000002
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_APP_REGIME_ANNOTATION           0x00000004
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_CUSTOM_ANNOTATION               0x00000008
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_SINGLE_NODE_SCG_ANNOTATION      0x00000010
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_PERFSTRAT_ANNOTATION            0x00000020
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_PUSHER_ANNOTATION               0x00000040
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_COPY_ANNOTATION                 0x00000080
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_SHADER_ANNOTATION               0x00000100
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_DEBUG_ANNOTATION                0x00000200
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_HOTKEY                          0x00001000
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_EXTERNAL_PROCESS_NOTIFICATION   0x00002000
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_PERF_INSPECTOR_FILENAME         0x00004000
#define TRACKED_SEMAPHORE_FLAGS_ENABLE_EXIT_ON_COMPLETION              0x10000000
#define TRACKED_SEMAPHORE_FLAGS_DEFAULT                                0x0


#define TRACKED_SEMAPHORE_FRAMES_STRING                                "0xfaf032"
#define TRACKED_SEMAPHORE_FRAMES_ID                                    0x00faf032
#define TRACKED_SEMAPHORE_FRAMES_OVERINSTALL                           0 // OVERRIDE
#define TRACKED_SEMAPHORE_FRAMES_DEFAULT                               0x8


#define TRIPLE_BUFFERING_ALLOW_STRING                                  "676635"
#define TRIPLE_BUFFERING_ALLOW_ID                                      0x00676635
#define TRIPLE_BUFFERING_ALLOW_OVERINSTALL                             0 // OVERRIDE
#define TRIPLE_BUFFERING_ALLOW_DISABLED                                0
#define TRIPLE_BUFFERING_ALLOW_OFF                                     0
#define TRIPLE_BUFFERING_ALLOW_ENABLED                                 1
#define TRIPLE_BUFFERING_ALLOW_ON                                      1
#define TRIPLE_BUFFERING_ALLOW_DEFAULT                                 TRIPLE_BUFFERING_ALLOW_ENABLED


#define TRMSAAMODE_STRING                                              "45382907"
#define TRMSAAMODE_ID                                                  0x0043ed70
#define TRMSAAMODE_OVERINSTALL                                         0 // OVERRIDE
#define TRMSAAMODE_Q                                                   0x0000
#define TRMSAAMODE_ATOC                                                0x0001
#define TRMSAAMODE_A4X_TC                                              0x0002
#define TRMSAAMODE_C4X_TC                                              0x0003
#define TRMSAAMODE_A3X_TC                                              0x0004
#define TRMSAAMODE_C3X_TC                                              0x0005
#define TRMSAAMODE_A4X_ALL                                             0x0006
#define TRMSAAMODE_C4X_ALL                                             0x0007
#define TRMSAAMODE_A3X_ALL                                             0x0008
#define TRMSAAMODE_C3X_ALL                                             0x0009
#define TRMSAAMODE_SS2X                                                0x000a
#define TRMSAAMODE_SS4X                                                0x000b
#define TRMSAAMODE_SS8X                                                0x000c
#define TRMSAAMODE_TEST                                                0x000F
#define TRMSAAMODE_MAX                                                 0x000F
#define TRMSAAMODE_DEFAULT                                             0


#define TSF_ENABLE_STRING                                              "853748"
#define TSF_ENABLE_ID                                                  0x00853748
#define TSF_ENABLE_OVERINSTALL                                         0 // OVERRIDE
#define TSF_ENABLE_OFF                                                 0
#define TSF_ENABLE_DISABLED                                            0
#define TSF_ENABLE_ON                                                  1
#define TSF_ENABLE_ENABLED                                             1
#define TSF_ENABLE_DEFAULT                                             TSF_ENABLE_ON


#define TSF_SETTING_STRING                                             "322156"
#define TSF_SETTING_ID                                                 0x00322156
#define TSF_SETTING_OVERINSTALL                                        0 // OVERRIDE
#define TSF_SETTING_DEFAULT_FILTER                                     0x00000001
#define TSF_SETTING_SPATIAL_FILTER                                     0x00000002
#define TSF_SETTING_DEINTERLACE_FILTER                                 0x00000003
#define TSF_SETTING_FILTER_FROM_FILE                                   0x00000004
#define TSF_SETTING_DEFAULT                                            TSF_SETTING_SPATIAL_FILTER


#define TSF_THRESHOLD_STATIC_OBJECT_STRING                             "89790"
#define TSF_THRESHOLD_STATIC_OBJECT_ID                                 0x00a89790
#define TSF_THRESHOLD_STATIC_OBJECT_OVERINSTALL                        0 // OVERRIDE
#define TSF_THRESHOLD_STATIC_OBJECT_DEFAULT                            50


#define TURING_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                    "0x523de1"
#define TURING_A_TILEDCACHE_BUFFERINTERLEAVE_ID                        0x00523de1
#define TURING_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL               0 // OVERRIDE
#define TURING_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                   0x00022313


#define TURING_A_TILEDCACHE_CONTROL_STRING                             "0x523de2"
#define TURING_A_TILEDCACHE_CONTROL_ID                                 0x00523de2
#define TURING_A_TILEDCACHE_CONTROL_OVERINSTALL                        0 // OVERRIDE
#define TURING_A_TILEDCACHE_CONTROL_DEFAULT                            0x08080202


#define TURING_A_TILEDCACHE_CONTROL_EXTENDED_STRING                    "0x523de3"
#define TURING_A_TILEDCACHE_CONTROL_EXTENDED_ID                        0x00523de3
#define TURING_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL               0 // OVERRIDE
#define TURING_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                   0x00000008


#define TURING_A_TILEDCACHE_L2_USAGE_STRING                            "0x523de5"
#define TURING_A_TILEDCACHE_L2_USAGE_ID                                0x00523de5
#define TURING_A_TILEDCACHE_L2_USAGE_OVERINSTALL                       0 // OVERRIDE
#define TURING_A_TILEDCACHE_L2_USAGE_DEFAULT                           0.5f


#define TURING_A_TILEDCACHE_STATETHRESHOLD_STRING                      "0x523de4"
#define TURING_A_TILEDCACHE_STATETHRESHOLD_ID                          0x00523de4
#define TURING_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                 0 // OVERRIDE
#define TURING_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                     0x00080001


#define TURING_CBV_BIND_MODE_STRING                                    "CB1234"
#define TURING_CBV_BIND_MODE_ID                                        0x00035aed
#define TURING_CBV_BIND_MODE_OVERINSTALL                               0 // OVERRIDE
#define TURING_CBV_BIND_MODE_CBV_BIND_MODE_DEFAULT                     0x00000000
#define TURING_CBV_BIND_MODE_DX12_CBV_BIND_MODE_SHIFT                  0
#define TURING_CBV_BIND_MODE_DX12_CBV_BIND_MODE_MASK                   0x0000000F
#define TURING_CBV_BIND_MODE_DX12_CBV_BIND_MODE_LEGACY                 0x00000001
#define TURING_CBV_BIND_MODE_DX12_CBV_BIND_MODE_PUREBINDLESS           0x00000000
#define TURING_CBV_BIND_MODE_DX11_CMP_CBV_BIND_MODE_SHIFT              4
#define TURING_CBV_BIND_MODE_DX11_CMP_CBV_BIND_MODE_MASK               0x000000F0
#define TURING_CBV_BIND_MODE_DX11_CMP_CBV_BIND_MODE_LEGACY             0x00000010
#define TURING_CBV_BIND_MODE_DX11_CMP_CBV_BIND_MODE_PUREBINDLESS       0x00000020
#define TURING_CBV_BIND_MODE_DX11_CMP_CBV_BIND_MODE_HYBRIDBINDLESS     0x00000000
#define TURING_CBV_BIND_MODE_DEFAULT                                   TURING_CBV_BIND_MODE_CBV_BIND_MODE_DEFAULT


#define TURING_DX12_SURFACE_BIND_MODE_STRING                           "ab4d1a"
#define TURING_DX12_SURFACE_BIND_MODE_ID                               0x00ab4d1a
#define TURING_DX12_SURFACE_BIND_MODE_OVERINSTALL                      0 // OVERRIDE
#define TURING_DX12_SURFACE_BIND_MODE_PUREBINDLESS                     0x0
#define TURING_DX12_SURFACE_BIND_MODE_LEGACY                           0x1
#define TURING_DX12_SURFACE_BIND_MODE_DEFAULT                          TURING_DX12_SURFACE_BIND_MODE_PUREBINDLESS


#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_STRING                    "fb1fc6"
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_ID                        0x0087b9bd
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_OVERINSTALL               0 // OVERRIDE
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_OFF                       0x0
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_0                         0x0
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_FALSE                     0x0
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_DISABLED                  0x0
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_ON                        0x1
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_1                         0x1
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_TRUE                      0x1
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_ENABLED                   0x1
#define TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_DEFAULT                   TURING_GCC_PREFETCH_DXR_STRAT_ENABLE_ON


#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_STRING                   "fb1fc7"
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_ID                       0x0087b9be
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_OVERINSTALL              0 // OVERRIDE
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_OFF                      0x0
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_0                        0x0
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_FALSE                    0x0
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_DISABLED                 0x0
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_ON                       0x1
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_1                        0x1
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_TRUE                     0x1
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_ENABLED                  0x1
#define TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_DEFAULT                  TURING_GCC_PREFETCH_DXR_TOGGLE_ENABLE_OFF


#define TURING_MME64_USE_DMA_READ_PORT_STRING                          "0x341314"
#define TURING_MME64_USE_DMA_READ_PORT_ID                              0x00341314
#define TURING_MME64_USE_DMA_READ_PORT_OVERINSTALL                     0 // OVERRIDE
#define TURING_MME64_USE_DMA_READ_PORT_OFF                             0x000000000
#define TURING_MME64_USE_DMA_READ_PORT_DISABLED                        0x000000000
#define TURING_MME64_USE_DMA_READ_PORT_ON                              0x000000001
#define TURING_MME64_USE_DMA_READ_PORT_ENABLED                         0x000000001
#define TURING_MME64_USE_DMA_READ_PORT_DEFAULT                         TURING_MME64_USE_DMA_READ_PORT_ON


#define TURING_MONITORED_FENCE_FLAGS_STRING                            "0x1bbbbb"
#define TURING_MONITORED_FENCE_FLAGS_ID                                0x001bbbbb
#define TURING_MONITORED_FENCE_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define TURING_MONITORED_FENCE_FLAGS_DISABLE                           0x00000000
#define TURING_MONITORED_FENCE_FLAGS_ENABLE                            0x00000001
#define TURING_MONITORED_FENCE_FLAGS_FORCE_COMPUTE_ON_3D               0x00000040
#define TURING_MONITORED_FENCE_FLAGS_ENABLE_COMPUTE_DX1x_SCG           0x00000020
#define TURING_MONITORED_FENCE_FLAGS_FORCE_CE_ON_3D                    0x00000080
#define TURING_MONITORED_FENCE_FLAGS_IGNORE_CE_HW_WAR                  0x00000004
#define TURING_MONITORED_FENCE_FLAGS_IGNORE_HASHVA_RELEASE             0x00000002
#define TURING_MONITORED_FENCE_FLAGS_ENABLE_LEGACY                     0x00000010
#define TURING_MONITORED_FENCE_FLAGS_ENABLE_DBG_PRINT                  0x00000100
#define TURING_MONITORED_FENCE_FLAGS_DEFAULT                           TURING_MONITORED_FENCE_FLAGS_DISABLE


#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_STRING                 "fb1fc5"
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_ID                     0x0087b9bc
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_OVERINSTALL            0 // OVERRIDE
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_OFF                    0x0
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_0                      0x0
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_FALSE                  0x0
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_DISABLED               0x0
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_ON                     0x1
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_1                      0x1
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_TRUE                   0x1
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_ENABLED                0x1
#define TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_DEFAULT                TURING_PRI_GPCS_GCC_DBG_PREFETCH_ENABLE_ON


#define TURING_ROOTCBV_MODE_STRING                                     "CB2284"
#define TURING_ROOTCBV_MODE_ID                                         0x00035bef
#define TURING_ROOTCBV_MODE_OVERINSTALL                                0 // OVERRIDE
#define TURING_ROOTCBV_MODE_ROOTCBV_MODE_FORCE_LDG                     0x0
#define TURING_ROOTCBV_MODE_GRAPHICS_ROOTCBV_FORCE_LDCB                0x1
#define TURING_ROOTCBV_MODE_COMPUTE_ROOTCBV_FORCE_LDCB                 0x2
#define TURING_ROOTCBV_MODE_ROOTCBV_MODE_FORCE_LDCB                    0x3
#define TURING_ROOTCBV_MODE_DEFAULT                                    TURING_ROOTCBV_MODE_ROOTCBV_MODE_FORCE_LDCB


#define TURING_TEXTURE_BIND_MODE_STRING                                "ab4d1b"
#define TURING_TEXTURE_BIND_MODE_ID                                    0x00ab4d1b
#define TURING_TEXTURE_BIND_MODE_OVERINSTALL                           0 // OVERRIDE
#define TURING_TEXTURE_BIND_MODE_DX11_LEGACY                           0x1
#define TURING_TEXTURE_BIND_MODE_DX12_LEGACY                           0x2
#define TURING_TEXTURE_BIND_MODE_DEFAULT                               TURING_TEXTURE_BIND_MODE_DX11_LEGACY


#define TURING_TEX_SMP_VIA_ROOT_TABLE_STRING                           "ab4d10"
#define TURING_TEX_SMP_VIA_ROOT_TABLE_ID                               0x00ab4d10
#define TURING_TEX_SMP_VIA_ROOT_TABLE_OVERINSTALL                      0 // OVERRIDE
#define TURING_TEX_SMP_VIA_ROOT_TABLE_OFF                              0x0
#define TURING_TEX_SMP_VIA_ROOT_TABLE_DISABLED                         0x0
#define TURING_TEX_SMP_VIA_ROOT_TABLE_ON                               0x1
#define TURING_TEX_SMP_VIA_ROOT_TABLE_ENABLED                          0x1
#define TURING_TEX_SMP_VIA_ROOT_TABLE_DEFAULT                          TURING_TEX_SMP_VIA_ROOT_TABLE_ON


#define TURING_USE_BUNDLE64_DRAW_STRING                                "0xC08DC"
#define TURING_USE_BUNDLE64_DRAW_ID                                    0x000c08dc
#define TURING_USE_BUNDLE64_DRAW_OVERINSTALL                           0 // OVERRIDE
#define TURING_USE_BUNDLE64_DRAW_OFF                                   0x00000000
#define TURING_USE_BUNDLE64_DRAW_DISABLED                              0x00000000
#define TURING_USE_BUNDLE64_DRAW_ON                                    0x00000001
#define TURING_USE_BUNDLE64_DRAW_ENABLED                               0x00000001
#define TURING_USE_BUNDLE64_DRAW_DEFAULT                               TURING_USE_BUNDLE64_DRAW_ON


#define UMD_LOAD_PATH_STRING                                           "61807118"
#define UMD_LOAD_PATH_ID                                               0x00b7b8aa
#define UMD_LOAD_PATH_OVERINSTALL                                      0 // OVERRIDE
#define UMD_LOAD_PATH_DEFAULT                                          ""


#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_STRING   "fab429"
#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_ID       0x00fab429
#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_STATIC   0x0
#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_REGKEY_BASED 0x1
#define UMD_MANAGED_GPFIFO_ALLOCATION_CAPACITY_SELECTION_MODE_DEFAULT  1


#define UMD_MANAGED_GPFIFO_GROWTH_FACTOR_STRING                        "fac425"
#define UMD_MANAGED_GPFIFO_GROWTH_FACTOR_ID                            0x00fac425
#define UMD_MANAGED_GPFIFO_GROWTH_FACTOR_OVERINSTALL                   0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_GROWTH_FACTOR_DEFAULT                       0x2


#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_STRING                        "fac426"
#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_ID                            0x00fac426
#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_OVERINSTALL                   0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_HOST                          0x0
#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_VID                           0x1
#define UMD_MANAGED_GPFIFO_HEAP_LOCATION_DEFAULT                       0


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_ASYNC_COPY_CHANNEL_STRING  "fac427"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_ASYNC_COPY_CHANNEL_ID      0x00fac427
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_ASYNC_COPY_CHANNEL_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_ASYNC_COPY_CHANNEL_DEFAULT 4096


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_DX9_STRING                 "fac520"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_DX9_ID                     0x00fac520
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_DX9_OVERINSTALL            0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_DX9_DEFAULT                4096


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_GRAPHICS_CHANNEL_STRING    "fac419"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_GRAPHICS_CHANNEL_ID        0x00fac419
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_GRAPHICS_CHANNEL_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_GRAPHICS_CHANNEL_DEFAULT   4096


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_ASYNC_COMPUTE_CHANNEL_STRING "fac420"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_ASYNC_COMPUTE_CHANNEL_ID 0x00fac420
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_ASYNC_COMPUTE_CHANNEL_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_ASYNC_COMPUTE_CHANNEL_DEFAULT 4096


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_DRIVER_CHANNEL_STRING  "fac424"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_DRIVER_CHANNEL_ID      0x00fac424
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_DRIVER_CHANNEL_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_DRIVER_CHANNEL_DEFAULT 4096


#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_HELPER_CHANNEL_STRING  "fac421"
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_HELPER_CHANNEL_ID      0x00fac421
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_HELPER_CHANNEL_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_INITIAL_CAPACITY_SCG_HELPER_CHANNEL_DEFAULT 512


#define UMD_MANAGED_GPFIFO_MAX_CAPACITY_STRING                         "fac423"
#define UMD_MANAGED_GPFIFO_MAX_CAPACITY_ID                             0x00fac423
#define UMD_MANAGED_GPFIFO_MAX_CAPACITY_OVERINSTALL                    0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_MAX_CAPACITY_DEFAULT                        0x200000


#define UMD_MANAGED_GPFIFO_SUB_PB_MASK_FOR_GPFIFO_SWITCH_ALLOWED_STRING "fac422"
#define UMD_MANAGED_GPFIFO_SUB_PB_MASK_FOR_GPFIFO_SWITCH_ALLOWED_ID    0x00fac422
#define UMD_MANAGED_GPFIFO_SUB_PB_MASK_FOR_GPFIFO_SWITCH_ALLOWED_OVERINSTALL 0 // OVERRIDE
#define UMD_MANAGED_GPFIFO_SUB_PB_MASK_FOR_GPFIFO_SWITCH_ALLOWED_DEFAULT 0xffffffff


#define UNORDERED3DCOMPRESSENABLE_STRING                               "0xafbcf0"
#define UNORDERED3DCOMPRESSENABLE_ID                                   0x00afbcf0
#define UNORDERED3DCOMPRESSENABLE_OVERINSTALL                          0 // OVERRIDE
#define UNORDERED3DCOMPRESSENABLE_OFF                                  0x99388100
#define UNORDERED3DCOMPRESSENABLE_DISABLED                             0x99388100
#define UNORDERED3DCOMPRESSENABLE_ON                                   0x25558997
#define UNORDERED3DCOMPRESSENABLE_ENABLED                              0x25558997
#define UNORDERED3DCOMPRESSENABLE_DEFAULT                              UNORDERED3DCOMPRESSENABLE_OFF


#define UNORDEREDCOMPRESSENABLE_STRING                                 "21612298"
#define UNORDEREDCOMPRESSENABLE_ID                                     0x0085f498
#define UNORDEREDCOMPRESSENABLE_OVERINSTALL                            0 // OVERRIDE
#define UNORDEREDCOMPRESSENABLE_OFF                                    0x99388100
#define UNORDEREDCOMPRESSENABLE_DISABLED                               0x99388100
#define UNORDEREDCOMPRESSENABLE_ON                                     0x25558997
#define UNORDEREDCOMPRESSENABLE_ENABLED                                0x25558997
#define UNORDEREDCOMPRESSENABLE_DEFAULT                                UNORDEREDCOMPRESSENABLE_ON


#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_STRING "0x031dff"
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_ID     0x00031dff
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_OVERINSTALL 0 // OVERRIDE
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_OFF    0x0
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_0      0x0
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_FALSE  0x0
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_DISABLED 0x0
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_ON     0x1
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_1      0x1
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_TRUE   0x1
#define UPLOAD_QUEUE_FLUSH_ON_SAME_SUBCH_I2M_FOR_INVALIDATE_WAR_ENABLED 0x1


#define USERMIPMAPENABLE_STRING                                        "36759435"
#define USERMIPMAPENABLE_ID                                            0x00b8d271
#define USERMIPMAPENABLE_OVERINSTALL                                   0 // OVERRIDE
#define USERMIPMAPENABLE_OFF                                           0x48391723
#define USERMIPMAPENABLE_DISABLED                                      0x48391723
#define USERMIPMAPENABLE_ON                                            0x24829101
#define USERMIPMAPENABLE_ENABLED                                       0x24829101
#define USERMIPMAPENABLE_DEFAULT                                       USERMIPMAPENABLE_ON


#define USE_CE_FOR_TRANSFERS_STRING                                    "0xceadd2"
#define USE_CE_FOR_TRANSFERS_ID                                        0x00ceadd2
#define USE_CE_FOR_TRANSFERS_OVERINSTALL                               0 // OVERRIDE
#define USE_CE_FOR_TRANSFERS_DISABLE                                   0x00000000
#define USE_CE_FOR_TRANSFERS_BUFFER_UPLOADS_DOWNLOADS                  0x00000002
#define USE_CE_FOR_TRANSFERS_TEXTURE_UPLOADS_DOWNLOADS                 0x00000004
#define USE_CE_FOR_TRANSFERS_TEXTURE_STAGING_UPLOAD                    0x00000008
#define USE_CE_FOR_TRANSFERS_ALL_ENABLE                                0x0000000E
#define USE_CE_FOR_TRANSFERS_DEFAULT                                   USE_CE_FOR_TRANSFERS_DISABLE


#define USE_CE_FOR_TRANSFERS_THRESHOLD_STRING                          "0xceadd4"
#define USE_CE_FOR_TRANSFERS_THRESHOLD_ID                              0x00ceadd4
#define USE_CE_FOR_TRANSFERS_THRESHOLD_OVERINSTALL                     0 // OVERRIDE
#define USE_CE_FOR_TRANSFERS_THRESHOLD_DEFAULT                         0x00000000


#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_STRING             "4f886868"
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_ID                 0x006da677
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_OVERINSTALL        0 // OVERRIDE
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_OFF                0x00000000
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_DISABLED           0x00000000
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_ON                 0x00000001
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_ENABLED            0x00000001
#define USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_DEFAULT            USE_COMMON_TEXTURE_POOL_ENTRIES_FOR_DSC_DSR_ON


#define USE_DISPATCH_HELPER_FOR_DSC_STRING                             "4f886856"
#define USE_DISPATCH_HELPER_FOR_DSC_ID                                 0x006da688
#define USE_DISPATCH_HELPER_FOR_DSC_OVERINSTALL                        0 // OVERRIDE
#define USE_DISPATCH_HELPER_FOR_DSC_OFF                                0x00000000
#define USE_DISPATCH_HELPER_FOR_DSC_DISABLED                           0x00000000
#define USE_DISPATCH_HELPER_FOR_DSC_ON                                 0x00000001
#define USE_DISPATCH_HELPER_FOR_DSC_ENABLED                            0x00000001
#define USE_DISPATCH_HELPER_FOR_DSC_DEFAULT                            USE_DISPATCH_HELPER_FOR_DSC_OFF


#define USE_DSC_FOR_SUPPORTED_BLITS_STRING                             "4f887778"
#define USE_DSC_FOR_SUPPORTED_BLITS_ID                                 0x006da689
#define USE_DSC_FOR_SUPPORTED_BLITS_OVERINSTALL                        0 // OVERRIDE
#define USE_DSC_FOR_SUPPORTED_BLITS_OFF                                0x00000000
#define USE_DSC_FOR_SUPPORTED_BLITS_DISABLED                           0x00000000
#define USE_DSC_FOR_SUPPORTED_BLITS_ON                                 0x00000001
#define USE_DSC_FOR_SUPPORTED_BLITS_ENABLED                            0x00000001
#define USE_DSC_FOR_SUPPORTED_BLITS_DEFAULT                            USE_DSC_FOR_SUPPORTED_BLITS_OFF


#define USE_INCREMENT_PUT_PRE_GA10x_STRING                             "abdb11"
#define USE_INCREMENT_PUT_PRE_GA10x_ID                                 0x00abdb11
#define USE_INCREMENT_PUT_PRE_GA10x_OVERINSTALL                        0 // OVERRIDE
#define USE_INCREMENT_PUT_PRE_GA10x_OFF                                0x00000000
#define USE_INCREMENT_PUT_PRE_GA10x_DISABLED                           0x00000000
#define USE_INCREMENT_PUT_PRE_GA10x_ON                                 0x00000001
#define USE_INCREMENT_PUT_PRE_GA10x_ENABLED                            0x00000001
#define USE_INCREMENT_PUT_PRE_GA10x_DEFAULT                            USE_INCREMENT_PUT_PRE_GA10x_OFF


#define VALIDATE_PARAMS_STRING                                         "54896354"
#define VALIDATE_PARAMS_ID                                             0x00a9d3c5
#define VALIDATE_PARAMS_OVERINSTALL                                    0 // OVERRIDE
#define VALIDATE_PARAMS_NOTHING                                        0x00000000
#define VALIDATE_PARAMS_COPYREGION                                     0x00000001
#define VALIDATE_PARAMS_INTERPRET_NEGATIVE                             0X00000002
#define VALIDATE_PARAMS_DEFAULT                                        VALIDATE_PARAMS_NOTHING


#define VERTEX_SHADER_BATCH_CULL_STRING                                "50361872"
#define VERTEX_SHADER_BATCH_CULL_ID                                    0x00bc6786
#define VERTEX_SHADER_BATCH_CULL_OVERINSTALL                           0 // OVERRIDE
#define VERTEX_SHADER_BATCH_CULL_OFF                                   0x00000000
#define VERTEX_SHADER_BATCH_CULL_0                                     0x00000000
#define VERTEX_SHADER_BATCH_CULL_FALSE                                 0x00000000
#define VERTEX_SHADER_BATCH_CULL_DISABLED                              0x00000000
#define VERTEX_SHADER_BATCH_CULL_ON                                    0x00000001
#define VERTEX_SHADER_BATCH_CULL_1                                     0x00000001
#define VERTEX_SHADER_BATCH_CULL_TRUE                                  0x00000001
#define VERTEX_SHADER_BATCH_CULL_ENABLED                               0x00000001
#define VERTEX_SHADER_BATCH_CULL_DEFAULT                               VERTEX_SHADER_BATCH_CULL_ON


#define VIDEOTEXTUREENABLE_STRING                                      "38375933"
#define VIDEOTEXTUREENABLE_ID                                          0x00088922
#define VIDEOTEXTUREENABLE_OVERINSTALL                                 0 // OVERRIDE
#define VIDEOTEXTUREENABLE_OFF                                         0x75360106
#define VIDEOTEXTUREENABLE_DISABLED                                    0x75360106
#define VIDEOTEXTUREENABLE_ON                                          0x24917602
#define VIDEOTEXTUREENABLE_ENABLED                                     0x24917602
#define VIDEOTEXTUREENABLE_DEFAULT                                     VIDEOTEXTUREENABLE_ON


#define VOLTA_A_TILEDCACHE_BUFFERINTERLEAVE_STRING                     "0x523db1"
#define VOLTA_A_TILEDCACHE_BUFFERINTERLEAVE_ID                         0x00523db1
#define VOLTA_A_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL                0 // OVERRIDE
#define VOLTA_A_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                    0x00002313


#define VOLTA_A_TILEDCACHE_CONTROL_STRING                              "0x523db2"
#define VOLTA_A_TILEDCACHE_CONTROL_ID                                  0x00523db2
#define VOLTA_A_TILEDCACHE_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define VOLTA_A_TILEDCACHE_CONTROL_DEFAULT                             0x08080202


#define VOLTA_A_TILEDCACHE_CONTROL_EXTENDED_STRING                     "0x523db3"
#define VOLTA_A_TILEDCACHE_CONTROL_EXTENDED_ID                         0x00523db3
#define VOLTA_A_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL                0 // OVERRIDE
#define VOLTA_A_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                    0x00000008


#define VOLTA_A_TILEDCACHE_L2_USAGE_STRING                             "0x523db5"
#define VOLTA_A_TILEDCACHE_L2_USAGE_ID                                 0x00523db5
#define VOLTA_A_TILEDCACHE_L2_USAGE_OVERINSTALL                        0 // OVERRIDE
#define VOLTA_A_TILEDCACHE_L2_USAGE_DEFAULT                            0.5f


#define VOLTA_A_TILEDCACHE_STATETHRESHOLD_STRING                       "0x523db4"
#define VOLTA_A_TILEDCACHE_STATETHRESHOLD_ID                           0x00523db4
#define VOLTA_A_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                  0 // OVERRIDE
#define VOLTA_A_TILEDCACHE_STATETHRESHOLD_DEFAULT                      0x00080001


#define VOLTA_UAV_L1_CACHE_OCGCONTROL_STRING                           "e07348"
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_ID                               0x00e07348
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_OVERINSTALL                      0 // OVERRIDE
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_DISABLE_FOR_SULD                 0x00000001
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_DISABLE_FOR_SUST                 0x00000002
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_ALLOW_FOR_SUATOM                 0x00000004
#define VOLTA_UAV_L1_CACHE_OCGCONTROL_DEFAULT                          0


#define VRINDICATOR_STRING                                             "d52e49d3"
#define VRINDICATOR_ID                                                 0x00d5e9d3
#define VRINDICATOR_OVERINSTALL                                        0 // OVERRIDE
#define VRINDICATOR_OFF                                                0x0
#define VRINDICATOR_0                                                  0x0
#define VRINDICATOR_FALSE                                              0x0
#define VRINDICATOR_DISABLED                                           0x0
#define VRINDICATOR_SHOW_VR_INDICATOR                                  0x80402010
#define VRINDICATOR_SHOW_VRS_INDICATOR                                 0x80402011
#define VRINDICATOR_SHOW_AUTOVRS_INDICATOR                             0x80402012
#define VRINDICATOR_DEFAULT                                            VRINDICATOR_OFF


#define VR_FEATURES_DISABLE_STRING                                     "371420"
#define VR_FEATURES_DISABLE_ID                                         0x004f3289
#define VR_FEATURES_DISABLE_OVERINSTALL                                0 // OVERRIDE
#define VR_FEATURES_DISABLE_NONE                                       0x00000000
#define VR_FEATURES_DISABLE_MULTI_RES_SHADING                          0x00000001
#define VR_FEATURES_DISABLE_SINGLE_PASS_STEREO_X                       0x00000002
#define VR_FEATURES_DISABLE_LENS_MATCH_SHADING                         0x00000004
#define VR_FEATURES_DISABLE_VRCOMPOSITOR_NODE                          0x00000008
#define VR_FEATURES_DISABLE_VARIABLE_RATE_SHADING                      0x00000010
#define VR_FEATURES_DISABLE_SINGLE_PASS_STEREO_XYZW                    0x00000020
#define VR_FEATURES_DISABLE_MULTIVIEW_RENDERING                        0x00000040
#define VR_FEATURES_DISABLE_DEFAULT                                    VR_FEATURES_DISABLE_NONE


#define VR_PERF_OPTIONS_STRING                                         "d52e49e3"
#define VR_PERF_OPTIONS_ID                                             0x00d5e9e3
#define VR_PERF_OPTIONS_OVERINSTALL                                    0 // OVERRIDE
#define VR_PERF_OPTIONS_DEFAULT                                        0x00000000
#define VR_PERF_OPTIONS_NO_MIRROR_EGPU                                 0x00000001
#define VR_PERF_OPTIONS_NO_MIRROR                                      0x00000002


#define VSVERSIONCAP_STRING                                            "59954023"
#define VSVERSIONCAP_ID                                                0x007354e7
#define VSVERSIONCAP_OVERINSTALL                                       0 // OVERRIDE
#define VSVERSIONCAP_MIN                                               0xfffe0000
#define VSVERSIONCAP_MAX                                               0xffffffff
#define VSVERSIONCAP_DEFAULT                                           0xffffffff


#define VSYNCMODE_STRING                                               "60461791"
#define VSYNCMODE_ID                                                   0x00a879cf
#define VSYNCMODE_OVERINSTALL                                          1 // MERGE
#define VSYNCMODE_PASSIVE                                              0x60925292
#define VSYNCMODE_APP_CONTROLLED                                       0x60925292
#define VSYNCMODE_FORCEOFF                                             0x08416747
#define VSYNCMODE_DISABLE                                              0x08416747
#define VSYNCMODE_OFF                                                  0x08416747
#define VSYNCMODE_FALSE                                                0x08416747
#define VSYNCMODE_0                                                    0x08416747
#define VSYNCMODE_FORCEON                                              0x47814940
#define VSYNCMODE_ENABLE                                               0x47814940
#define VSYNCMODE_ON                                                   0x47814940
#define VSYNCMODE_TRUE                                                 0x47814940
#define VSYNCMODE_FLIPINTERVAL1                                        0x47814940
#define VSYNCMODE_1                                                    0x47814940
#define VSYNCMODE_FLIPINTERVAL2                                        0x32610244
#define VSYNCMODE_2                                                    0x32610244
#define VSYNCMODE_FLIPINTERVAL3                                        0x71271021
#define VSYNCMODE_3                                                    0x71271021
#define VSYNCMODE_FLIPINTERVAL4                                        0x13245256
#define VSYNCMODE_4                                                    0x13245256
#define VSYNCMODE_VIRTUAL                                              0x18888888
#define VSYNCMODE_DEFAULT                                              VSYNCMODE_PASSIVE


#define VSYNCTEARCONTROL_STRING                                        "14493863"
#define VSYNCTEARCONTROL_ID                                            0x005a375c
#define VSYNCTEARCONTROL_OVERINSTALL                                   1 // MERGE
#define VSYNCTEARCONTROL_DISABLE                                       0x96861077
#define VSYNCTEARCONTROL_OFF                                           0x96861077
#define VSYNCTEARCONTROL_FALSE                                         0x96861077
#define VSYNCTEARCONTROL_0                                             0x96861077
#define VSYNCTEARCONTROL_ENABLE                                        0x99941284
#define VSYNCTEARCONTROL_ON                                            0x99941284
#define VSYNCTEARCONTROL_TRUE                                          0x99941284
#define VSYNCTEARCONTROL_1                                             0x99941284
#define VSYNCTEARCONTROL_DEFAULT                                       VSYNCTEARCONTROL_DISABLE


#define VSYNC_FLIP_USE_NV_INTERVAL_STRING                              "60262781"
#define VSYNC_FLIP_USE_NV_INTERVAL_ID                                  0x00b139cf
#define VSYNC_FLIP_USE_NV_INTERVAL_OVERINSTALL                         0 // OVERRIDE
#define VSYNC_FLIP_USE_NV_INTERVAL_OFF                                 0x00000000
#define VSYNC_FLIP_USE_NV_INTERVAL_DISABLED                            0x00000000
#define VSYNC_FLIP_USE_NV_INTERVAL_OS                                  0x00000000
#define VSYNC_FLIP_USE_NV_INTERVAL_ON                                  0x00000001
#define VSYNC_FLIP_USE_NV_INTERVAL_ENABLED                             0x00000001
#define VSYNC_FLIP_USE_NV_INTERVAL_NV                                  0x00000001
#define VSYNC_FLIP_USE_NV_INTERVAL_DEFAULT                             VSYNC_FLIP_USE_NV_INTERVAL_ON


#define WATERMARKING_INDICATOR_ENABLE_STRING                           "380880"
#define WATERMARKING_INDICATOR_ENABLE_ID                               0x00380880
#define WATERMARKING_INDICATOR_ENABLE_OVERINSTALL                      0 // OVERRIDE
#define WATERMARKING_INDICATOR_ENABLE_OFF                              0x00000000
#define WATERMARKING_INDICATOR_ENABLE_0                                0x00000000
#define WATERMARKING_INDICATOR_ENABLE_FALSE                            0x00000000
#define WATERMARKING_INDICATOR_ENABLE_DISABLED                         0x00000000
#define WATERMARKING_INDICATOR_ENABLE_ON                               0x00000001
#define WATERMARKING_INDICATOR_ENABLE_1                                0x00000001
#define WATERMARKING_INDICATOR_ENABLE_TRUE                             0x00000001
#define WATERMARKING_INDICATOR_ENABLE_ENABLED                          0x00000001
#define WATERMARKING_INDICATOR_ENABLE_MASK                             0xFFFFFFFF
#define WATERMARKING_INDICATOR_ENABLE_DEFAULT                          WATERMARKING_INDICATOR_ENABLE_OFF


#define WDDM13_MARKER_TYPE_PROFILE_STRING                              "09122013"
#define WDDM13_MARKER_TYPE_PROFILE_ID                                  0x008b30dd
#define WDDM13_MARKER_TYPE_PROFILE_OVERINSTALL                         0 // OVERRIDE
#define WDDM13_MARKER_TYPE_PROFILE_OFF                                 0x00000000
#define WDDM13_MARKER_TYPE_PROFILE_ON                                  0x00000001
#define WDDM13_MARKER_TYPE_PROFILE_DEFAULT                             WDDM13_MARKER_TYPE_PROFILE_ON


#define WDDMV2_DEALLOC2_FLAGS_STRING                                   "200025545"
#define WDDMV2_DEALLOC2_FLAGS_ID                                       0x005f69ac
#define WDDMV2_DEALLOC2_FLAGS_OVERINSTALL                              0 // OVERRIDE
#define WDDMV2_DEALLOC2_FLAGS_FORCE_ALLOCATION_IN_USE_FOR_DEALLOC2     0x00000001
#define WDDMV2_DEALLOC2_FLAGS_DISABLE_RS3_HOTFIX_FOR_2006962           0x00000002


#define WDDMV2_RESIDENCY_FLAGS_STRING                                  "20002553"
#define WDDMV2_RESIDENCY_FLAGS_ID                                      0x005f69ab
#define WDDMV2_RESIDENCY_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define WDDMV2_RESIDENCY_FLAGS_BIND_ON_ALLOCATE                        0x00000001
#define WDDMV2_RESIDENCY_FLAGS_WAITONCPU_FOR_PAGING_AFTER_ALLOCATE     0x00000002
#define WDDMV2_RESIDENCY_FLAGS_WAITONCPU_FOR_PAGING_BEFORE_PRESENT     0x00000004
#define WDDMV2_RESIDENCY_FLAGS_DISABLE_NOTWRITTEN_OPTIMIZATIN          0x00000008
#define WDDMV2_RESIDENCY_FLAGS_DISABLE_EVICT_ONLY_IF_NECESSARY         0x00000010


#define WDDMV2_SKIP_TRIM_FLAGS_STRING                                  "29992553"
#define WDDMV2_SKIP_TRIM_FLAGS_ID                                      0x00596999
#define WDDMV2_SKIP_TRIM_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define WDDMV2_SKIP_TRIM_FLAGS_SKIP_TRIM_DISABLED                      0x00000000
#define WDDMV2_SKIP_TRIM_FLAGS_SKIP_TRIM_NORMAL                        0x00000001
#define WDDMV2_SKIP_TRIM_FLAGS_SKIP_TRIM_PERIODIC                      0x00000002
#define WDDMV2_SKIP_TRIM_FLAGS_SKIP_TRIM_AGGRESSIVE                    0x00000004


#define WFORMAT16_STRING                                               "62225341"
#define WFORMAT16_ID                                                   0x00a1a248
#define WFORMAT16_OVERINSTALL                                          0 // OVERRIDE
#define WFORMAT16_FIXED                                                0x92446898
#define WFORMAT16_0                                                    0x92446898
#define WFORMAT16_FLOAT                                                0x83557128
#define WFORMAT16_1                                                    0x83557128
#define WFORMAT16_DEFAULT                                              WFORMAT16_FIXED


#define WFORMAT32_STRING                                               "64907714"
#define WFORMAT32_ID                                                   0x002a00ad
#define WFORMAT32_OVERINSTALL                                          0 // OVERRIDE
#define WFORMAT32_FIXED                                                0x92446898
#define WFORMAT32_0                                                    0x92446898
#define WFORMAT32_FLOAT                                                0x83557128
#define WFORMAT32_1                                                    0x83557128
#define WFORMAT32_DEFAULT                                              WFORMAT32_FLOAT


#define WHOLE_PSO_MESH_FLAG_STRING                                     "813C0Eb6"
#define WHOLE_PSO_MESH_FLAG_ID                                         0x009c0eb8
#define WHOLE_PSO_MESH_FLAG_OVERINSTALL                                0 // OVERRIDE
#define WHOLE_PSO_MESH_FLAG_DEFAULT_WHOLEPSO                           0x00000000
#define WHOLE_PSO_MESH_FLAG_OPTIMIZED_WHOLEPSO                         0x00000001
#define WHOLE_PSO_MESH_FLAG_SINGLE_STAGE                               0x00000002
#define WHOLE_PSO_MESH_FLAG_DEFAULT                                    WHOLE_PSO_MESH_FLAG_OPTIMIZED_WHOLEPSO


#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_STRING                    "wgsm"
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_ID                        0x0078eee8
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_OVERINSTALL               0 // OVERRIDE
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_FOREGROUND_POLICY_DEFAULT 0x00000000
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_FOREGROUND_POLICY_PRESENT_WND 0x00000000
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_FOREGROUND_POLICY_FORCE   0x00000001
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_FOREGROUND_POLICY_FOREGROUND_WND 0x00000002
#define WINDOWED_GSYNC_FOREGROUND_APP_POLICY_DEFAULT                   WINDOWED_GSYNC_FOREGROUND_APP_POLICY_FOREGROUND_POLICY_DEFAULT


#define WKS_FEATURE_INDICATOR_STRING                                   "211019"
#define WKS_FEATURE_INDICATOR_ID                                       0x00211019
#define WKS_FEATURE_INDICATOR_OVERINSTALL                              0 // OVERRIDE
#define WKS_FEATURE_INDICATOR_OFF                                      0x00000000
#define WKS_FEATURE_INDICATOR_0                                        0x00000000
#define WKS_FEATURE_INDICATOR_FALSE                                    0x00000000
#define WKS_FEATURE_INDICATOR_DISABLED                                 0x00000000
#define WKS_FEATURE_INDICATOR_ON                                       0x00000001
#define WKS_FEATURE_INDICATOR_1                                        0x00000001
#define WKS_FEATURE_INDICATOR_TRUE                                     0x00000001
#define WKS_FEATURE_INDICATOR_ENABLED                                  0x00000001
#define WKS_FEATURE_INDICATOR_FEATURE_MASK                             0x00000FF0
#define WKS_FEATURE_INDICATOR_SWAPGROUP                                0x00000010
#define WKS_FEATURE_INDICATOR_SWAPGROUP_JOINED                         0x00000020
#define WKS_FEATURE_INDICATOR_COMPOSITOR                               0x00000040
#define WKS_FEATURE_INDICATOR_DDISPLAY                                 0x00000080
#define WKS_FEATURE_INDICATOR_APP_MASK                                 0x0000F000
#define WKS_FEATURE_INDICATOR_APP                                      0x00001000
#define WKS_FEATURE_INDICATOR_DWM                                      0x00002000
#define WKS_FEATURE_INDICATOR_DEFAULT                                  WKS_FEATURE_INDICATOR_OFF


#define WORKER_KMI_LAYER_STRING                                        "0562AED0"
#define WORKER_KMI_LAYER_ID                                            0x00effed0
#define WORKER_KMI_LAYER_OVERINSTALL                                   0 // OVERRIDE
#define WORKER_KMI_LAYER_OFF                                           0x00000000
#define WORKER_KMI_LAYER_ON                                            0x00000001
#define WORKER_KMI_LAYER_DEFAULT                                       WORKER_KMI_LAYER_ON


#define WORKER_KMI_LAYER_THREAD_PRIORITY_STRING                        "0562AED1"
#define WORKER_KMI_LAYER_THREAD_PRIORITY_ID                            0x00effed1
#define WORKER_KMI_LAYER_THREAD_PRIORITY_OVERINSTALL                   0 // OVERRIDE
#define WORKER_KMI_LAYER_THREAD_PRIORITY_LOWEST                        0xFFFFFFFE
#define WORKER_KMI_LAYER_THREAD_PRIORITY_BELOW_NORMAL                  0xFFFFFFFF
#define WORKER_KMI_LAYER_THREAD_PRIORITY_NORMAL                        0x00000000
#define WORKER_KMI_LAYER_THREAD_PRIORITY_ABOVE_NORMAL                  0x00000001
#define WORKER_KMI_LAYER_THREAD_PRIORITY_HIGHEST                       0x00000002
#define WORKER_KMI_LAYER_THREAD_PRIORITY_DEFAULT                       0x00000001


#define WRITE_FULL_BE_ENABLE_STRING                                    ""
#define WRITE_FULL_BE_ENABLE_ID                                        0x00abd3f1
#define WRITE_FULL_BE_ENABLE_OVERINSTALL                               0 // OVERRIDE
#define WRITE_FULL_BE_ENABLE_DISABLE                                   0x00000000
#define WRITE_FULL_BE_ENABLE_CROP_VID                                  0x00000001
#define WRITE_FULL_BE_ENABLE_CROP_SYS                                  0x00000002
#define WRITE_FULL_BE_ENABLE_ZROP_VID                                  0x00000004
#define WRITE_FULL_BE_ENABLE_ZROP_SYS                                  0x00000008
#define WRITE_FULL_BE_ENABLE_ENABLE_CROP_ALL                           0x00000010
#define WRITE_FULL_BE_ENABLE_ENABLE_ZROP_ALL                           0x00000020
#define WRITE_FULL_BE_ENABLE_ALL                                       0x0000003f
#define WRITE_FULL_BE_ENABLE_DEFAULT                                   WRITE_FULL_BE_ENABLE_ALL


#define WRITE_TO_HOST_STAGING_BUFFER_SIZE_STRING                       "89527426"
#define WRITE_TO_HOST_STAGING_BUFFER_SIZE_ID                           0x00f63a49
#define WRITE_TO_HOST_STAGING_BUFFER_SIZE_OVERINSTALL                  0 // OVERRIDE
#define WRITE_TO_HOST_STAGING_BUFFER_SIZE_DEFAULT                      0x0


#define WSCALE16_STRING                                                "A2103837"
#define WSCALE16_ID                                                    0x00d3c26f
#define WSCALE16_OVERINSTALL                                           0 // OVERRIDE
#define WSCALE16_MIN                                                   0x00000000
#define WSCALE16_MAX                                                   0x00010000
#define WSCALE16_DEFAULT                                               WSCALE16_MAX


#define WSCALE24_STRING                                                "A4176590"
#define WSCALE24_ID                                                    0x00d76268
#define WSCALE24_OVERINSTALL                                           0 // OVERRIDE
#define WSCALE24_MIN                                                   0x00000000
#define WSCALE24_MAX                                                   0x01000000
#define WSCALE24_DEFAULT                                               WSCALE24_MAX


#define WTD_ALLOW_STRING                                               "WTD_ALLOW"
#define WTD_ALLOW_ID                                                   0x001a6bb7
#define WTD_ALLOW_OVERINSTALL                                          0 // OVERRIDE


#define WTD_EXECMODEL_STRING                                           "WTD_EXECMODEL"
#define WTD_EXECMODEL_ID                                               0x0066a35d
#define WTD_EXECMODEL_OVERINSTALL                                      0 // OVERRIDE


#define WTD_FORCEASYNCCMD0_STRING                                      "WTD_FORCEASYNCCMD0"
#define WTD_FORCEASYNCCMD0_ID                                          0x00b6142e
#define WTD_FORCEASYNCCMD0_OVERINSTALL                                 0 // OVERRIDE


#define WTD_FORCEASYNCCMD1_STRING                                      "WTD_FORCEASYNCCMD1"
#define WTD_FORCEASYNCCMD1_ID                                          0x008b9549
#define WTD_FORCEASYNCCMD1_OVERINSTALL                                 0 // OVERRIDE


#define WTD_FORCEASYNCCMD2_STRING                                      "WTD_FORCEASYNCCMD2"
#define WTD_FORCEASYNCCMD2_ID                                          0x00cbc7bb
#define WTD_FORCEASYNCCMD2_OVERINSTALL                                 0 // OVERRIDE


#define WTD_FORCEASYNCCMD3_STRING                                      "WTD_FORCEASYNCCMD3"
#define WTD_FORCEASYNCCMD3_ID                                          0x007cd240
#define WTD_FORCEASYNCCMD3_OVERINSTALL                                 0 // OVERRIDE


#define WTD_STATS_STRING                                               "WTD_STATS"
#define WTD_STATS_ID                                                   0x000c1d68
#define WTD_STATS_OVERINSTALL                                          0 // OVERRIDE


#define ZBC_STRING                                                     "e4bb8796"
#define ZBC_ID                                                         0x009daed8
#define ZBC_OVERINSTALL                                                0 // OVERRIDE
#define ZBC_DISABLE_ALL                                                0x00000000
#define ZBC_ALLOW_RENDERTARGET                                         0x00000001
#define ZBC_ALLOW_DEPTH                                                0x00000002
#define ZBC_ALLOW_PRIMARY                                              0x00000004
#define ZBC_ALLOW_VIDEO                                                0x00000008
#define ZBC_ALLOW_TEXTURE                                              0x00000010
#define ZBC_ALLOW_CUBEMAP                                              0x00000020
#define ZBC_ALLOW_VOLUME                                               0x00000040
#define ZBC_ALLOW_VERTEXARRAY                                          0x00000080
#define ZBC_ALLOW_INDEXARRAY                                           0x00000100
#define ZBC_ALLOW_OFFSCREEN                                            0x00000200
#define ZBC_ALLOW_STREAMOUT                                            0x00000400
#define ZBC_ALLOW_SEMAPHORE                                            0x00004000
#define ZBC_ALLOW_PUSHBUFFER                                           0x00010000
#define ZBC_ALLOW_GPFIFOBUFFER                                         0x00020000
#define ZBC_ALLOW_CONTEXT_SAVE                                         0x00040000
#define ZBC_ALLOW_TEXHEADERS                                           0x00080000
#define ZBC_ALLOW_SAMPLERS                                             0x00100000
#define ZBC_ALLOW_ZCULL_CONTEXT                                        0x00200000
#define ZBC_ALLOW_FRAGMENTPROGRAM                                      0x00800000
#define ZBC_ALLOW_UNKNOWN                                              0x40000000
#define ZBC_ALLOW_GDI                                                  0x80000000
#define ZBC_ALLOW_ALL                                                  0xc0bf47ff
#define ZBC_MASK                                                       0xc0bf47ff
#define ZBC_DEFAULT                                                    ZBC_ALLOW_ALL


#define ZBIAS_STRING                                                   "A6489764"
#define ZBIAS_ID                                                       0x000d53e5
#define ZBIAS_OVERINSTALL                                              0 // OVERRIDE
#define ZBIAS_MIN                                                      0
#define ZBIAS_MAX                                                      10
#define ZBIAS_DEFAULT                                                  ZBIAS_MIN


#define ZCOMPRESSENABLE_STRING                                         "46205529"
#define ZCOMPRESSENABLE_ID                                             0x005b9a13
#define ZCOMPRESSENABLE_OVERINSTALL                                    0 // OVERRIDE
#define ZCOMPRESSENABLE_OFF                                            0x86752318
#define ZCOMPRESSENABLE_DISABLED                                       0x86752318
#define ZCOMPRESSENABLE_ON                                             0x88204955
#define ZCOMPRESSENABLE_ENABLED                                        0x88204955
#define ZCOMPRESSENABLE_DEFAULT                                        ZCOMPRESSENABLE_ON


#define ZCULL_FLAGS_STRING                                             "ffaeaeff"
#define ZCULL_FLAGS_ID                                                 0x0054cf06
#define ZCULL_FLAGS_OVERINSTALL                                        0 // OVERRIDE
#define ZCULL_FLAGS_NONE                                               0x00000000
#define ZCULL_FLAGS_DYNAMIC_STENCIL                                    0x00000001
#define ZCULL_FLAGS_DEFAULT                                            ZCULL_FLAGS_DYNAMIC_STENCIL


#define ZCULL_TOTAL_ALIQUOTS_STRING                                    "ffabccde"
#define ZCULL_TOTAL_ALIQUOTS_ID                                        0x0051c571
#define ZCULL_TOTAL_ALIQUOTS_OVERINSTALL                               0 // OVERRIDE
#define ZCULL_TOTAL_ALIQUOTS_DEFAULT                                   0


#endif // _G_D3DREG_H_
